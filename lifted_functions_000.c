#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>
#include <cstddef>

static void sfera_prepare_msvc_string_storage(uint32_t address) { if (lift_load32(address + 0x10u) == 0u && lift_load32(address + 0x14u) == 0u) { lift_store8(address, 0u); lift_store32(address + 0x14u, 15u); } }

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401000u);
    cpu->eax = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_00001006: cpu->eip = LIFT_CODE_TOKEN_VA(0x401006u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00001006;
    cpu->eax -= cpu->esi;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + cpu->eax + 0xFFFFFFFFu)), r=(uint64_t)(0x5Cu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = (uint32_t)(cpu->ecx + cpu->eax + 0xFFFFFFFFu);
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00001026;
    label_00001020: cpu->eip = LIFT_CODE_TOKEN_VA(0x401020u);
    --cpu->eax;
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x5Cu)) goto label_00001020;
    label_00001026: cpu->eip = LIFT_CODE_TOKEN_VA(0x401026u);
    ++cpu->eax;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401030(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401030u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::sprintf);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    cpu->edi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00001064;
    cpu->eax = lift_load32(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"AutoBoundsArray error: non-uniform growth of an index\nFile: %s  Line: %d\n"); lift_push32(cpu, (uintptr_t)g_sfera_array_error_buffer);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x1057u), LIFT_CODE_TOKEN_RVA(0x1055u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401057u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_array_error_buffer;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1064u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00001064: cpu->eip = LIFT_CODE_TOKEN_VA(0x401064u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0000108A;
    cpu->edx = lift_load32(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"AutoBoundsArray error: the index has exceeded a maximum\nFile: %s  Line: %d\n"); lift_push32(cpu, (uintptr_t)g_sfera_array_error_buffer);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x107Du), LIFT_CODE_TOKEN_RVA(0x107Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40107Du);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_array_error_buffer;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x108Au); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0000108A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40108Au);
    cpu->ebx = lift_load32(cpu->esi + 0xCu);
    cpu->ebx += lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(cpu->eax)) goto label_00001099;
    cpu->ebx = cpu->eax;
    label_00001099: cpu->eip = LIFT_CODE_TOKEN_VA(0x401099u);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->ebx);
    lift_push32(cpu, 0x2Bu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Arrays.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4010ABu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x10u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(lift_load32(cpu->esi + 4u));
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->eax;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4010B9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4010BEu);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->ebx);
    cpu->edx -= cpu->edi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->edi += cpu->ebp;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4010CCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4010D1u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->esp += 0x18u;
    lift_push32(cpu, 0x2Fu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Arrays.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4010E2u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi, cpu->ebp);
    lift_store32(cpu->esi + 4u, cpu->ebx);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004010F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4010F0u);
    cpu->eax = lift_load32(cpu->ecx + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"BoundCheckArray error: index less than zero\nFile: %s  Line: %d\n"); lift_push32(cpu, (uintptr_t)g_sfera_array_error_buffer);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4010FFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x401105u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_array_error_buffer;
    sfera_sub_00459B10(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401120u);
    cpu->eax = lift_load32(cpu->ecx + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"BoundCheckArray error: index out of range %d\nFile: %s  Line: %d\n"); lift_push32(cpu, (uintptr_t)g_sfera_array_error_buffer);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x401130u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x401136u);
    cpu->esp += 0x14u;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_array_error_buffer;
    sfera_sub_00459B10(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401150(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401150u);
    cpu->esp -= 0x60u;
    lift_x87_push(cpu, 1.0);
    cpu->eax = cpu->ecx;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + 0x68u, 0x10000u);
    cpu->ecx = lift_load32(cpu->esp);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + 0x50u, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + 0x54u, cpu->edx);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp);
    lift_store32(cpu->eax + 0x58u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    lift_store32(cpu->eax + 0x5Cu, cpu->edx);
    lift_store32(cpu->eax + 0x60u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->eax + 0x64u, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->ecx &= 0xFFFFFFF0u;
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->ecx + 4u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->esi);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store_f32(cpu->edx + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store_f32(cpu->ecx + 0xCu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store_f32(cpu->edx + 0x10u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->ecx + 0x14u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->edi);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->edx + 0x18u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store_f32(cpu->ecx + 0x1Cu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store_f32(cpu->edx + 0x20u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store_f32(cpu->ecx + 0x24u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->edx + 0x28u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->ecx + 0x2Cu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store_f32(cpu->edx + 0x30u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store_f32(cpu->ecx + 0x34u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store_f32(cpu->edx + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store_f32(cpu->ecx + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_load32(cpu->eax);
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x60u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401250(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401250u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_push32(cpu, cpu->esi);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_load32(cpu->esp + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_store32(cpu->eax + 0xCu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax + 0x10u, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax + 0x14u, cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_load32(cpu->esp + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_store32(cpu->eax + 0x18u, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax + 0x1Cu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax + 0x20u, cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_load32(cpu->esp + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_store32(cpu->eax + 0x54u, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax + 0x58u, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax + 0x5Cu, cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_load32(cpu->esp + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_store32(cpu->eax + 0x30u, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax + 0x34u, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax + 0x38u, cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_load32(cpu->esp + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_store32(cpu->eax + 0x3Cu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax + 0x40u, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax + 0x44u, cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    cpu->esi = lift_load32(cpu->esp + 4u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax + 0x24u, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->eax + 0x28u, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax + 0x2Cu, cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    cpu->ecx = lift_load32(cpu->esp);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_store32(cpu->eax + 0x48u, cpu->ecx);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->eax + 0x4Cu, cpu->edx);
    lift_store32(cpu->eax + 0x50u, cpu->ecx);
    cpu->esp += 0xCu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004013B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4013B0u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 4u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004013D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4013D0u);
    cpu->esp -= 0x10u;
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00001465;
    if ((uint32_t)(cpu->edi) == 0u) goto label_0000142E;
    cpu->ecx = lift_load32(cpu->edi);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->ebp);
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_00001465;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, (uintptr_t)" ERROR(1): putbitstream: bufer will overload: bitT = %d, count = %d, bufsize = %d"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x28u, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\inter.h");
    lift_store32(cpu->esp + 0x2Cu, 0x25Fu);
    lift_store32(cpu->esp + 0x30u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401429u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    goto label_00001465;
    label_0000142E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40142Eu);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    if ((int32_t)(uint32_t)(cpu->ebp) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_00001465;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, (uintptr_t)" ERROR(2): putbitstream: bufer will overload: count = %d, bufsize = %d"); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x24u, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\inter.h");
    lift_store32(cpu->esp + 0x28u, 0x265u);
    lift_store32(cpu->esp + 0x2Cu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401462u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_00001465: cpu->eip = LIFT_CODE_TOKEN_VA(0x401465u);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->edi) == 0u) goto label_0000146F;
    cpu->edx = lift_load32(cpu->edi);
    label_0000146F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40146Fu);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00001479;
    cpu->ecx = lift_load32(cpu->eax);
    label_00001479: cpu->eip = LIFT_CODE_TOKEN_VA(0x401479u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edi = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->ebx & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->edi = (uint32_t)(cpu->eax + cpu->ecx);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    lift_store32(cpu->esp + 0x30u, cpu->ecx);
    cpu->ecx = cpu->edx;
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->edx & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    cpu->esi += cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_000014D5;
    cpu->eax = cpu->ebp;
    label_000014B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4014B6u);
    if ((uint8_t)((lift_load8(cpu->edi)) & ((cpu->ebx & 0xFFu))) == 0u) goto label_000014BE;
    lift_store8(cpu->esi, (uint64_t)(lift_load8(cpu->esi)) | (uint64_t)((cpu->edx & 0xFFu)));
    goto label_000014C4;
    label_000014BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4014BEu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((cpu->edx & 0xFFu)) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->esi, (uint64_t)(lift_load8(cpu->esi)) & (uint64_t)((cpu->ecx & 0xFFu)));
    label_000014C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4014C4u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000014CB;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_000014CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4014CBu);
    { uint64_t l=(uint64_t)((cpu->ebx & 0xFFu)), r=(uint64_t)((cpu->ebx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000014D2;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->edi;
    label_000014D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4014D2u);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000014B6;
    label_000014D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4014D5u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000014DF;
    lift_store32(cpu->eax, (uint64_t)(lift_load32(cpu->eax)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u));
    label_000014DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4014DFu);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000014E9;
    lift_store32(cpu->eax, (uint64_t)(lift_load32(cpu->eax)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u));
    label_000014E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4014E9u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401500(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401500u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ecx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    lift_push32(cpu, cpu->ebx);
    label_00001507: cpu->eip = LIFT_CODE_TOKEN_VA(0x401507u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != 0u) goto label_00001507;
    cpu->eax -= cpu->esi;
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    cpu->esi -= cpu->edx;
    cpu->ebx = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_00001563;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->eax) < (uint32_t)(4u)) goto label_00001536;
    label_00001522: cpu->eip = LIFT_CODE_TOKEN_VA(0x401522u);
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edx))) goto label_00001563;
    cpu->eax -= 4u;
    cpu->edx += 4u;
    cpu->esi += 4u;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(4u)) goto label_00001522;
    label_00001536: cpu->eip = LIFT_CODE_TOKEN_VA(0x401536u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0000155A;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(lift_load8(cpu->esi))) goto label_00001563;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(1u)) goto label_0000155A;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx + 1u)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(lift_load8(cpu->esi + 1u))) goto label_00001563;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(2u)) goto label_0000155A;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx + 2u)) & 0xFFu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(lift_load8(cpu->esi + 2u))) goto label_00001563;
    label_0000155A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40155Au);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00001563: cpu->eip = LIFT_CODE_TOKEN_VA(0x401563u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401570(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401570u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->edx = cpu->ecx;
    cpu->edx -= cpu->eax;
    label_00001578: cpu->eip = LIFT_CODE_TOKEN_VA(0x401578u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00001578;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401590(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401590u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->esi) < (uint32_t)(0x25823Fu)) goto label_000015A5;
    cpu->esi = 0x25823Fu;
    label_000015A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4015A5u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_config_text_runtime.owned_text[0]);
    g_sfera_config_text_runtime.current_text = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_config_text_runtime.owned_text[0]));
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4015BAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4015BFu);
    cpu->ecx = g_sfera_config_text_runtime.current_text;
    cpu->eax = (uint32_t)(uintptr_t)"";
    cpu->edx = cpu->edi;
    cpu->esp += 0xCu;
    lift_store8(cpu->ecx + cpu->esi, 0u);
    cpu->edx -= cpu->eax;
    label_000015D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4015D5u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000015D5;
    cpu->edi = lift_pop32(cpu);
    g_sfera_config_text_runtime.text_length = (uint32_t)(cpu->esi);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004015F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4015F0u);
    cpu->eax = g_sfera_config_text_runtime.text_length;
    lift_return(cpu, 0u, stop_address); return;
}

static uint32_t sfera_config_lookup(uint32_t key_address) {
    const uint32_t text_address = g_sfera_config_text_runtime.current_text;
    const uint32_t text_length = g_sfera_config_text_runtime.text_length;
    if (text_address == 0u || key_address == 0u) {
        return 0u;
    }
    std::size_t key_length = 0u;
    while (key_length != 4096u && lift_load8(key_address + static_cast<uint32_t>(key_length)) != 0u) {
        ++key_length;
    }
    if (key_length == 4096u) {
        return 0u;
    }
    const std::size_t bounded_length = text_length < 0x25823Fu ? text_length : 0x25823Fu;
    const std::size_t scan_limit = bounded_length + 1u;
    if (static_cast<uint64_t>(text_address) + scan_limit > 0x100000000ull) {
        return 0u;
    }
    std::size_t line = 0u;
    while (line < scan_limit) {
        std::size_t token_end = line;
        while (token_end < scan_limit) {
            const uint8_t value = lift_load8(text_address + static_cast<uint32_t>(token_end));
            if (value == ' ' || value == '\t' || value == '\r' || value == 0u) {
                break;
            }
            ++token_end;
        }
        bool matches = token_end - line == key_length;
        for (std::size_t index = 0u; matches && index != key_length; ++index) {
            matches = lift_load8(text_address + static_cast<uint32_t>(line + index)) == lift_load8(key_address + static_cast<uint32_t>(index));
        }
        if (matches) {
            std::size_t value = token_end;
            while (value < scan_limit) {
                const uint8_t current = lift_load8(text_address + static_cast<uint32_t>(value));
                if (current != ' ' && current != '\t') {
                    break;
                }
                ++value;
            }
            return value < scan_limit ? text_address + static_cast<uint32_t>(value) : 0u;
        }
        std::size_t next_line = token_end;
        while (next_line < scan_limit) {
            const uint8_t current = lift_load8(text_address + static_cast<uint32_t>(next_line));
            if (current == '\n' || current == 0u) {
                break;
            }
            ++next_line;
        }
        if (next_line == scan_limit || lift_load8(text_address + static_cast<uint32_t>(next_line)) == 0u) {
            return 0u;
        }
        line = next_line + 1u;
    }
    return 0u;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401600(LiftCpu* cpu, uint32_t stop_address) {
    static_cast<void>(stop_address);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401600u);
    const uint32_t key_address = lift_load32(cpu->esp + 4u);
    cpu->eax = sfera_config_lookup(key_address);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401680(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401680u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x180u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_chmod), LIFT_CODE_TOKEN_VA(0x401689u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x40168Fu);
    lift_push32(cpu, 0x180u); lift_push32(cpu, 0x8302u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x40169Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4016A0u);
    cpu->esi = cpu->eax;
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_000016B0;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000016B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4016B0u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_write), LIFT_CODE_TOKEN_VA(0x4016BBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4016C1u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x4016C2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4016C8u);
    cpu->esp += 0x10u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401700(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401700u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->edx = cpu->ecx;
    g_sfera_config_text_runtime.text_length = (uint32_t)(0u);
    g_sfera_config_text_runtime.current_text = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_config_text_runtime.owned_text[0]));
    g_sfera_config_text_runtime.owned_text[0] = (uint8_t)(0u);
    cpu->edx -= cpu->eax;
    label_00001723: cpu->eip = LIFT_CODE_TOKEN_VA(0x401723u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00001723;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401730u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    g_sfera_config_text_runtime.current_text = (uint32_t)(cpu->eax);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00001740: cpu->eip = LIFT_CODE_TOKEN_VA(0x401740u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != 0u) goto label_00001740;
    cpu->eax -= cpu->edx;
    g_sfera_config_text_runtime.text_length = (uint32_t)(cpu->eax);
    cpu->eax = (uint32_t)(uintptr_t)"";
    cpu->edx = cpu->ecx;
    cpu->edx -= cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    label_00001758: cpu->eip = LIFT_CODE_TOKEN_VA(0x401758u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00001758;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401770u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40177Au); lift_push32(cpu, r); sfera_sub_00401600(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00001783;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    lift_return(cpu, 8u, stop_address); return;
    label_00001783: cpu->eip = LIFT_CODE_TOKEN_VA(0x401783u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x40178Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x401794u);
    cpu->esp += 0xCu;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004017A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4017A0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4017AAu); lift_push32(cpu, r); sfera_sub_00401600(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000017B3;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    lift_return(cpu, 8u, stop_address); return;
    label_000017B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4017B3u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%f"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4017BEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4017C4u);
    cpu->esp += 0xCu;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004017D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4017D0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4017DAu); lift_push32(cpu, r); sfera_sub_00401600(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000017E3;
    label_000017DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4017DEu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    lift_return(cpu, 12u, stop_address); return;
    label_000017E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4017E3u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x22u)) goto label_000017DE;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_00001823;
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    label_000017F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4017F8u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0x22u)) goto label_0000181F;
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_0000181F;
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0xAu)) goto label_00001815;
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0xDu)) goto label_00001812;
    lift_store8(cpu->edx, cpu->ecx & 0xFFu);
    goto label_00001815;
    label_00001812: cpu->eip = LIFT_CODE_TOKEN_VA(0x401812u);
    lift_store8(cpu->edx, 0x20u);
    label_00001815: cpu->eip = LIFT_CODE_TOKEN_VA(0x401815u);
    ++cpu->edx;
    { uint64_t l=(uint64_t)(cpu->esi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->esi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000017F8;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000181F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40181Fu);
    if ((uint32_t)(cpu->esi) != 0u) goto label_00001829;
    label_00001823: cpu->eip = LIFT_CODE_TOKEN_VA(0x401823u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_00001829: cpu->eip = LIFT_CODE_TOKEN_VA(0x401829u);
    lift_store8(cpu->edx, 0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401840u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40184Bu); lift_push32(cpu, r); sfera_sub_00401600(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != 0u) goto label_00001857;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_00001857: cpu->eip = LIFT_CODE_TOKEN_VA(0x401857u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi)) & 0xFFu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = 0u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    if ((uint8_t)((cpu->edx & 0xFFu)) == (uint8_t)(0x23u)) goto label_0000192F;
    label_00001870: cpu->eip = LIFT_CODE_TOKEN_VA(0x401870u);
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_0000192B;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->ebp = (uint32_t)(cpu->ecx + 6u);
    cpu->eax += cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00001979;
    cpu->esi = cpu->ecx;
    cpu->eax = (uint32_t)(cpu->edx + 0xFFFFFFD0u);
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(3u), 32u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi) * 8u));
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->edx & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    ++cpu->edi;
    cpu->ecx += cpu->esi;
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_000018B1;
    lift_store8(cpu->ecx, (uint64_t)(lift_load8(cpu->ecx)) | (uint64_t)((cpu->edx & 0xFFu)));
    goto label_000018B7;
    label_000018B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4018B1u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->edx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->ecx, (uint64_t)(lift_load8(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_000018B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4018B7u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000018BE;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->ecx;
    label_000018BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4018BEu);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (2u)) == 0u) goto label_000018C6;
    lift_store8(cpu->ecx, (uint64_t)(lift_load8(cpu->ecx)) | (uint64_t)((cpu->edx & 0xFFu)));
    goto label_000018CC;
    label_000018C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4018C6u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->edx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->ecx, (uint64_t)(lift_load8(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_000018CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4018CCu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000018D3;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->ecx;
    label_000018D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4018D3u);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (4u)) == 0u) goto label_000018DB;
    lift_store8(cpu->ecx, (uint64_t)(lift_load8(cpu->ecx)) | (uint64_t)((cpu->edx & 0xFFu)));
    goto label_000018E1;
    label_000018DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4018DBu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->edx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->ecx, (uint64_t)(lift_load8(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_000018E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4018E1u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000018E8;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->ecx;
    label_000018E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4018E8u);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (8u)) == 0u) goto label_000018F0;
    lift_store8(cpu->ecx, (uint64_t)(lift_load8(cpu->ecx)) | (uint64_t)((cpu->edx & 0xFFu)));
    goto label_000018F6;
    label_000018F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4018F0u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->edx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->ecx, (uint64_t)(lift_load8(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_000018F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4018F6u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000018FD;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->ecx;
    label_000018FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4018FDu);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (0x10u)) == 0u) goto label_00001905;
    lift_store8(cpu->ecx, (uint64_t)(lift_load8(cpu->ecx)) | (uint64_t)((cpu->edx & 0xFFu)));
    goto label_0000190B;
    label_00001905: cpu->eip = LIFT_CODE_TOKEN_VA(0x401905u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->edx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->ecx, (uint64_t)(lift_load8(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_0000190B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40190Bu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00001912;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->ecx;
    label_00001912: cpu->eip = LIFT_CODE_TOKEN_VA(0x401912u);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (0x20u)) == 0u) goto label_0000191A;
    lift_store8(cpu->ecx, (uint64_t)(lift_load8(cpu->ecx)) | (uint64_t)((cpu->edx & 0xFFu)));
    goto label_0000191E;
    label_0000191A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40191Au);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->ecx, (uint64_t)(lift_load8(cpu->ecx)) & (uint64_t)((cpu->edx & 0xFFu)));
    label_0000191E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40191Eu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi)) & 0xFFu);
    cpu->ecx = cpu->ebp;
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(0x23u)) goto label_00001870;
    label_0000192B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40192Bu);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    label_0000192F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40192Fu);
    if ((uint8_t)(lift_load8(cpu->edi)) != (uint8_t)(0x23u)) goto label_00001970;
    cpu->edx = (int8_t)(lift_load8(cpu->edi + 1u));
    cpu->edx -= 0x30u;
    if ((int32_t)(uint32_t)(cpu->edx) <= 0) goto label_00001970;
    cpu->eax = (uint32_t)(cpu->edx + cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    if ((uint32_t)(cpu->eax) > (uint32_t)(cpu->ecx)) goto label_0000197D;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 2u)) & 0xFFu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) - (uint64_t)(0x30u) - (uint64_t)(0u))) & 0xFFu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_store8(cpu->esp + 0x2Cu, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1970u); lift_push32(cpu, r); sfera_sub_004013D0(cpu,r); if (cpu->eip != r) return; }
    label_00001970: cpu->eip = LIFT_CODE_TOKEN_VA(0x401970u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_00001979: cpu->eip = LIFT_CODE_TOKEN_VA(0x401979u);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    label_0000197D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40197Du);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401990u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebp;
    lift_push32(cpu, cpu->edi);
    g_sfera_config_text_runtime.text_length = (uint32_t)(0u);
    g_sfera_config_text_runtime.current_text = (uint32_t)(((uint32_t)(uintptr_t)&g_sfera_config_text_runtime.owned_text[0]));
    g_sfera_config_text_runtime.owned_text[0] = (uint8_t)(0u);
    cpu->edx -= cpu->eax;
    label_000019B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4019B8u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000019B8;
    cpu->edi = g_sfera_config_text_runtime.current_text;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x8000u); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4019D0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4019D6u);
    cpu->esi = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_00001AA0;
    lift_push32(cpu, 0x25823Fu); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x4019EBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4019F1u);
    lift_push32(cpu, cpu->esi);
    g_sfera_config_text_runtime.text_length = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x4019F7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4019FDu);
    cpu->edx = g_sfera_config_text_runtime.text_length;
    cpu->ecx = g_sfera_config_text_runtime.current_text;
    cpu->esp += 0x10u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401A11u); lift_push32(cpu, r); sfera_sub_0047E850(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00001AA8;
    cpu->edx = 0xC6u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\config.cpp";
    lift_store32(cpu->esp + 0x10u, 0x25823Fu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401A30u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401A3Bu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_config_text_runtime.text_length;
    cpu->edx = g_sfera_config_text_runtime.current_text;
    cpu->esp += 4u;
    lift_push32(cpu, cpu->ecx);
    cpu->esi = cpu->eax;
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401A59u); lift_push32(cpu, r); sfera_sub_0047E870(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != 0u) goto label_00001A78;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    g_sfera_config_text_runtime.text_length = (uint32_t)(cpu->eax);
    cpu->eax = g_sfera_config_text_runtime.current_text;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x401A70u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x401A75u);
    cpu->esp += 0xCu;
    label_00001A78: cpu->eip = LIFT_CODE_TOKEN_VA(0x401A78u);
    cpu->edx = 0xCFu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\config.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401A87u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401A8Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->edi) == 0u) goto label_00001AA8;
    lift_push32(cpu, (uint32_t)(uintptr_t)"");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1AA0u); lift_push32(cpu, r); sfera_sub_00401700(cpu,r); if (cpu->eip != r) return; }
    label_00001AA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x401AA0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00001AA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x401AA8u);
    cpu->ecx = g_sfera_config_text_runtime.text_length;
    cpu->edx = g_sfera_config_text_runtime.current_text;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store8(cpu->edx + cpu->ecx, 0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401AC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401AC0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->edi)) != (uint8_t)(0u)) goto label_00001AD0;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00001AD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x401AD0u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0xCu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0xCu, 0x25823Fu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00001B02;
    cpu->edx = 0xE3u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\config.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401AF0u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401AFBu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = cpu->eax;
    goto label_00001B04;
    label_00001B02: cpu->eip = LIFT_CODE_TOKEN_VA(0x401B02u);
    cpu->esi = 0u;
    label_00001B04: cpu->eip = LIFT_CODE_TOKEN_VA(0x401B04u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    if ((uint8_t)(lift_load8(cpu->esp + 0x14u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00001B1C;
    cpu->ecx = g_sfera_config_text_runtime.text_length;
    cpu->edx = g_sfera_config_text_runtime.current_text;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    goto label_00001B3E;
    label_00001B1C: cpu->eip = LIFT_CODE_TOKEN_VA(0x401B1Cu);
    cpu->eax = g_sfera_config_text_runtime.text_length;
    cpu->ecx = g_sfera_config_text_runtime.current_text;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401B34u); lift_push32(cpu, r); sfera_sub_0047E900(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00001B47;
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    label_00001B3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x401B3Eu);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401B45u); lift_push32(cpu, r); sfera_sub_00401680(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax & 0xFFu)) & 0xFFu);
    label_00001B47: cpu->eip = LIFT_CODE_TOKEN_VA(0x401B47u);
    cpu->edx = 0xEBu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\config.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401B56u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401B5Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((cpu->ebx & 0xFFu)) & 0xFFu);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401B70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401B70u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_config_text_runtime.text_length;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->esi)) goto label_00001B81;
    cpu->esi = cpu->eax;
    label_00001B81: cpu->eip = LIFT_CODE_TOKEN_VA(0x401B81u);
    cpu->eax = g_sfera_config_text_runtime.current_text;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x401B8Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x401B92u);
    cpu->esp += 0xCu;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401BE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401BE0u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->esi) < (uint32_t)(4u)) goto label_00001C07;
    label_00001BF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x401BF3u);
    cpu->eax = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->ecx))) goto label_00001C0B;
    cpu->esi -= 4u;
    cpu->ecx += 4u;
    cpu->edx += 4u;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(4u)) goto label_00001BF3;
    label_00001C07: cpu->eip = LIFT_CODE_TOKEN_VA(0x401C07u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_00001C4F;
    label_00001C0B: cpu->eip = LIFT_CODE_TOKEN_VA(0x401C0Bu);
    cpu->eax = lift_load8(cpu->edx);
    cpu->edi = lift_load8(cpu->ecx);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00001C46;
    if ((uint32_t)(cpu->esi) <= (uint32_t)(1u)) goto label_00001C4F;
    cpu->eax = lift_load8(cpu->edx + 1u);
    cpu->edi = lift_load8(cpu->ecx + 1u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00001C46;
    if ((uint32_t)(cpu->esi) <= (uint32_t)(2u)) goto label_00001C4F;
    cpu->eax = lift_load8(cpu->edx + 2u);
    cpu->edi = lift_load8(cpu->ecx + 2u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00001C46;
    if ((uint32_t)(cpu->esi) <= (uint32_t)(3u)) goto label_00001C4F;
    cpu->eax = lift_load8(cpu->edx + 3u);
    cpu->ecx = lift_load8(cpu->ecx + 3u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    label_00001C46: cpu->eip = LIFT_CODE_TOKEN_VA(0x401C46u);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax |= 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00001C4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x401C4Fu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401C60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401C60u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edx) == 0u) goto label_00001C7F;
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->edx)) goto label_00001C7A;
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = (uint32_t)(cpu->eax + cpu->edx + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->ecx + 8u))) goto label_00001C7F;
    label_00001C7A: cpu->eip = LIFT_CODE_TOKEN_VA(0x401C7Au);
    cpu->eax = 0u;
    lift_return(cpu, 4u, stop_address); return;
    label_00001C7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x401C7Fu);
    cpu->eax = 1u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401C90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401C90u);
    cpu->eax = lift_load32(cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00001C9C;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_00001CBC;
    label_00001C9C: cpu->eip = LIFT_CODE_TOKEN_VA(0x401C9Cu);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edx) == 0u) goto label_00001CB4;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->edx)) goto label_00001CBC;
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = (uint32_t)(cpu->eax + cpu->edx + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->eax) > (uint32_t)(lift_load32(cpu->ecx + 8u))) goto label_00001CBC;
    label_00001CB4: cpu->eip = LIFT_CODE_TOKEN_VA(0x401CB4u);
    cpu->eax = 1u;
    lift_return(cpu, 4u, stop_address); return;
    label_00001CBC: cpu->eip = LIFT_CODE_TOKEN_VA(0x401CBCu);
    cpu->eax = 0u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401CD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401CD0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00001CE2;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_00001CF5;
    label_00001CE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x401CE2u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00001D01;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_00001CF5;
    cpu->eax += 0xBu;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_00001D01;
    label_00001CF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x401CF5u);
    cpu->edx = 0xCu;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1D01u); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    label_00001D01: cpu->eip = LIFT_CODE_TOKEN_VA(0x401D01u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = lift_load32(cpu->esi);
    cpu->esi = lift_load32(cpu->edi);
    cpu->ecx -= cpu->edx;
    lift_store32(cpu->eax + cpu->edx + 4u, cpu->ecx);
    lift_store32(cpu->eax + cpu->edx, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->esi + 0xFFFFFFFFu);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax + cpu->edx + 8u, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401D30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401D30u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->ecx;
    cpu->esi = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_00001D4E;
    if ((uint32_t)(lift_load32(cpu->edi + 4u)) != (uint32_t)(0u)) goto label_00001D4E;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00001D4E: cpu->eip = LIFT_CODE_TOKEN_VA(0x401D4Eu);
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->eax = 0u;
    { uint64_t v=(uint64_t)(cpu->edx); lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u;
    { uint64_t v=(uint64_t)(cpu->esi); lift_flags_logic(cpu,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_00001D6B;
    label_00001D63: cpu->eip = LIFT_CODE_TOKEN_VA(0x401D63u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00001D6B: cpu->eip = LIFT_CODE_TOKEN_VA(0x401D6Bu);
    cpu->ecx = lift_load32(cpu->ebp);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edi))) goto label_00001D63;
    if ((uint32_t)(cpu->ecx) < (uint32_t)(4u)) goto label_00001D8B;
    label_00001D77: cpu->eip = LIFT_CODE_TOKEN_VA(0x401D77u);
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx))) goto label_00001D8F;
    cpu->ecx -= 4u;
    cpu->edx += 4u;
    cpu->esi += 4u;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(4u)) goto label_00001D77;
    label_00001D8B: cpu->eip = LIFT_CODE_TOKEN_VA(0x401D8Bu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00001DDD;
    label_00001D8F: cpu->eip = LIFT_CODE_TOKEN_VA(0x401D8Fu);
    cpu->edi = lift_load8(cpu->edx);
    cpu->eax = lift_load8(cpu->esi);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00001DCA;
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(1u)) goto label_00001DDD;
    cpu->eax = lift_load8(cpu->esi + 1u);
    cpu->edi = lift_load8(cpu->edx + 1u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00001DCA;
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(2u)) goto label_00001DDD;
    cpu->eax = lift_load8(cpu->esi + 2u);
    cpu->edi = lift_load8(cpu->edx + 2u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00001DCA;
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(3u)) goto label_00001DDD;
    cpu->eax = lift_load8(cpu->esi + 3u);
    cpu->ecx = lift_load8(cpu->edx + 3u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    label_00001DCA: cpu->eip = LIFT_CODE_TOKEN_VA(0x401DCAu);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax |= 1u;
    cpu->edi = lift_pop32(cpu);
    cpu->edx = 0u;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00001DDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x401DDDu);
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu);
    cpu->edx = 0u;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401DF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401DF0u);
    cpu->eax = 1u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401E00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401E00u);
    cpu->eax = 2u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401E10u);
    cpu->eax = 3u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401E20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401E20u);
    cpu->eax = 4u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401E30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401E30u);
    cpu->eax = 5u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401E40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401E40u);
    cpu->eax = cpu->ecx;
    lift_store32(cpu->eax, 0x19285u);
    lift_store8(cpu->eax + 8u, 0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401E50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401E50u);
    lift_store32(cpu->ecx, 0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00401F10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x401F10u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00001F4A;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx)), r=(uint64_t)(0x19285u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00001F4A;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    --cpu->eax;
    if ((uint32_t)(cpu->eax) > (uint32_t)(4u)) goto label_00001F4A;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00001F31;
        case 1u: goto label_00001F36;
        case 2u: goto label_00001F3B;
        case 3u: goto label_00001F40;
        case 4u: goto label_00001F45;
        default: lift_trap(cpu, 0x401F2Au, "resolved jump-table index out of range"); return;
    }
label_00001F31: ;
    goto label_00014F70;
    label_00001F36: cpu->eip = LIFT_CODE_TOKEN_VA(0x401F36u);
    goto label_00018680;
    label_00001F3B: cpu->eip = LIFT_CODE_TOKEN_VA(0x401F3Bu);
    goto label_000165C0;
    label_00001F40: cpu->eip = LIFT_CODE_TOKEN_VA(0x401F40u);
    goto label_00016170;
    label_00001F45: cpu->eip = LIFT_CODE_TOKEN_VA(0x401F45u);
    goto label_00018080;
    label_00001F4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x401F4Au);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 0u, stop_address); return;
    label_00014F70: cpu->eip = LIFT_CODE_TOKEN_VA(0x414F70u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    --cpu->eax;
    if ((uint32_t)(cpu->eax) > (uint32_t)(4u)) goto label_00015022;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00014F87;
        case 1u: goto label_00014FAA;
        case 2u: goto label_00015022;
        case 3u: goto label_00014FCD;
        case 4u: goto label_00015006;
        default: lift_trap(cpu, 0x414F80u, "resolved jump-table index out of range"); return;
    }
label_00014F87: ;
    cpu->edx = 0x18u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sListContainer.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414F96u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414F9Du); lift_push32(cpu, r); sfera_sub_004149E0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414FA3u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00014FAA: cpu->eip = LIFT_CODE_TOKEN_VA(0x414FAAu);
    cpu->edx = 0x18u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sListContainer.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414FB9u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414FC0u); lift_push32(cpu, r); sfera_sub_004149E0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414FC6u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00014FCD: cpu->eip = LIFT_CODE_TOKEN_VA(0x414FCDu);
    lift_push32(cpu, cpu->edi);
    cpu->edx = 0x18u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sListContainer.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414FDDu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esi + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414FE5u); lift_push32(cpu, r); sfera_sub_004BC130(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414FEEu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414FF8u); lift_push32(cpu, r); sfera_sub_00401E50(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x414FFEu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00015006: cpu->eip = LIFT_CODE_TOKEN_VA(0x415006u);
    cpu->edx = 0x18u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sListContainer.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x415015u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41501Eu); lift_push32(cpu, r); sfera_sub_00414CA0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00015022: cpu->eip = LIFT_CODE_TOKEN_VA(0x415022u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00016170: cpu->eip = LIFT_CODE_TOKEN_VA(0x416170u);
    cpu->eax = lift_load32(cpu->ecx + 0x10u);
    --cpu->eax;
    if ((uint32_t)(cpu->eax) > (uint32_t)(4u)) goto label_000161A0;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00016180;
        case 1u: goto label_00016188;
        case 2u: goto label_000161A0;
        case 3u: goto label_00016190;
        case 4u: goto label_00016198;
        default: lift_trap(cpu, 0x416179u, "resolved jump-table index out of range"); return;
    }
label_00016180: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416185u); lift_push32(cpu, r); sfera_sub_00416080(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
    label_00016188: cpu->eip = LIFT_CODE_TOKEN_VA(0x416188u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41618Du); lift_push32(cpu, r); sfera_sub_00416080(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
    label_00016190: cpu->eip = LIFT_CODE_TOKEN_VA(0x416190u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416195u); lift_push32(cpu, r); sfera_sub_004160D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
    label_00016198: cpu->eip = LIFT_CODE_TOKEN_VA(0x416198u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41619Du); lift_push32(cpu, r); sfera_sub_00416120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
    label_000161A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4161A0u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 0u, stop_address); return;
    label_000165C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4165C0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000165EF;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000165D3;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000165D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4165D3u);
    cpu->edx = 0x19u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sSetContainer.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4165E2u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4165EBu); lift_push32(cpu, r); sfera_sub_00416520(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000165EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4165EFu);
    cpu->edx = 0x19u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sSetContainer.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4165FEu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x416607u); lift_push32(cpu, r); sfera_sub_00416290(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00018080: cpu->eip = LIFT_CODE_TOKEN_VA(0x418080u);
    cpu->eax = lift_load32(cpu->ecx + 0x10u);
    --cpu->eax;
    if ((uint32_t)(cpu->eax) > (uint32_t)(4u)) goto label_000180B0;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00018090;
        case 1u: goto label_00018098;
        case 2u: goto label_000180B0;
        case 3u: goto label_000180A0;
        case 4u: goto label_000180A8;
        default: lift_trap(cpu, 0x418089u, "resolved jump-table index out of range"); return;
    }
label_00018090: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418095u); lift_push32(cpu, r); sfera_sub_00417F20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
    label_00018098: cpu->eip = LIFT_CODE_TOKEN_VA(0x418098u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41809Du); lift_push32(cpu, r); sfera_sub_00417F20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
    label_000180A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4180A0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4180A5u); lift_push32(cpu, r); sfera_sub_00417FA0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
    label_000180A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4180A8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4180ADu); lift_push32(cpu, r); sfera_sub_00418010(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
    label_000180B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4180B0u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 0u, stop_address); return;
    label_00018680: cpu->eip = LIFT_CODE_TOKEN_VA(0x418680u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    --cpu->eax;
    if ((uint32_t)(cpu->eax) > (uint32_t)(4u)) goto label_0001872A;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00018697;
        case 1u: goto label_000186B3;
        case 2u: goto label_000186CF;
        case 3u: goto label_000186EB;
        case 4u: goto label_00018707;
        default: lift_trap(cpu, 0x418690u, "resolved jump-table index out of range"); return;
    }
label_00018697: ;
    cpu->edx = 0x17u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sVectorContainer.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4186A6u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4186AFu); lift_push32(cpu, r); sfera_sub_00418220(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000186B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4186B3u);
    cpu->edx = 0x17u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sVectorContainer.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4186C2u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4186CBu); lift_push32(cpu, r); sfera_sub_00418220(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000186CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4186CFu);
    cpu->edx = 0x17u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sVectorContainer.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4186DEu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4186E7u); lift_push32(cpu, r); sfera_sub_00418220(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000186EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4186EBu);
    cpu->edx = 0x17u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sVectorContainer.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4186FAu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418703u); lift_push32(cpu, r); sfera_sub_00418620(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00018707: cpu->eip = LIFT_CODE_TOKEN_VA(0x418707u);
    cpu->edx = 0x17u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sVectorContainer.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418716u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x41871Du); lift_push32(cpu, r); sfera_sub_004182C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x418723u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0001872A: cpu->eip = LIFT_CODE_TOKEN_VA(0x41872Au);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402040(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00002040;
    label_00001E60: cpu->eip = LIFT_CODE_TOKEN_VA(0x401E60u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401E66u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    --cpu->eax;
    if ((uint32_t)(cpu->eax) > (uint32_t)(4u)) goto label_00001EE3;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00001E73;
        case 1u: goto label_00001E99;
        case 2u: goto label_00001EA7;
        case 3u: goto label_00001EB5;
        case 4u: goto label_00001ECC;
        default: lift_trap(cpu, 0x401E6Cu, "resolved jump-table index out of range"); return;
    }
label_00001E73: ;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401E78u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1E7Fu); lift_push32(cpu, r); sfera_sub_00414E00(cpu,r); if (cpu->eip != r) return; }
    label_00001E7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x401E7Fu);
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00001E91;
    cpu->edx = 9u;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x1E91u); lift_push32(cpu, r); sfera_sub_00437B00(cpu,r); if (cpu->eip != r) return; }
    label_00001E91: cpu->eip = LIFT_CODE_TOKEN_VA(0x401E91u);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00001E99: cpu->eip = LIFT_CODE_TOKEN_VA(0x401E99u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401E9Eu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401EA5u); lift_push32(cpu, r); sfera_sub_00418470(cpu,r); if (cpu->eip != r) return; }
    goto label_00001E7F;
    label_00001EA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x401EA7u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401EACu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401EB3u); lift_push32(cpu, r); sfera_sub_00416460(cpu,r); if (cpu->eip != r) return; }
    goto label_00001E7F;
    label_00001EB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x401EB5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401EBAu); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401EC1u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401ECAu); lift_push32(cpu, r); sfera_sub_00415DB0(cpu,r); if (cpu->eip != r) return; }
    goto label_00001E7F;
    label_00001ECC: cpu->eip = LIFT_CODE_TOKEN_VA(0x401ECCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401ED1u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401ED8u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401EE1u); lift_push32(cpu, r); sfera_sub_00417C70(cpu,r); if (cpu->eip != r) return; }
    goto label_00001E7F;
    label_00001EE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x401EE3u);
    cpu->esi = 0u;
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00001F70: cpu->eip = LIFT_CODE_TOKEN_VA(0x401F70u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401F75u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00001F8E;
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax)), r=(uint64_t)(0x19285u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_00001F8E;
    cpu->ecx = lift_load32(cpu->eax + 4u);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00001F8E: cpu->eip = LIFT_CODE_TOKEN_VA(0x401F8Eu);
    cpu->ecx |= 0xFFFFFFFFu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00001FA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x401FA0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x401FA5u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00001FB6;
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax)), r=(uint64_t)(0x19285u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00001FBE;
    label_00001FB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x401FB6u);
    cpu->ecx |= 0xFFFFFFFFu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00001FBE: cpu->eip = LIFT_CODE_TOKEN_VA(0x401FBEu);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    --cpu->ecx;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(4u)) goto label_00001FB6;
    switch ((uint32_t)(cpu->ecx)) {
        case 0u: case 1u: goto label_00001FCE;
        case 2u: goto label_00001FB6;
        case 3u: case 4u: goto label_00001FD6;
        default: lift_trap(cpu, 0x401FC7u, "resolved jump-table index out of range"); return;
    }
label_00001FCE: ;
    cpu->ecx = lift_load32(cpu->eax + 0xCu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00001FD6: cpu->eip = LIFT_CODE_TOKEN_VA(0x401FD6u);
    cpu->ecx = lift_load32(cpu->eax + 0x10u);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00002000: cpu->eip = LIFT_CODE_TOKEN_VA(0x402000u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x402005u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00002016;
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax)), r=(uint64_t)(0x19285u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0000201E;
    label_00002016: cpu->eip = LIFT_CODE_TOKEN_VA(0x402016u);
    cpu->ecx |= 0xFFFFFFFFu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000201E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40201Eu);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(3u)) goto label_0000202E;
    cpu->ecx += 0xFFFFFFFCu;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(1u)) goto label_00002016;
    label_0000202E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40202Eu);
    cpu->ecx = lift_load32(cpu->eax + 0xCu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00002040: cpu->eip = LIFT_CODE_TOKEN_VA(0x402040u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x402045u); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    --cpu->eax;
    if ((uint32_t)(cpu->eax) > (uint32_t)(4u)) goto label_00002089;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00002052;
        case 1u: goto label_00002057;
        case 2u: goto label_0000207A;
        case 3u: goto label_0000207F;
        case 4u: goto label_00002084;
        default: lift_trap(cpu, 0x40204Bu, "resolved jump-table index out of range"); return;
    }
label_00002052: ;
    goto label_00001E60;
    label_00002057: cpu->eip = LIFT_CODE_TOKEN_VA(0x402057u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40205Du); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->edx = 9u;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40206Bu); lift_push32(cpu, r); sfera_sub_00437B80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x402072u); lift_push32(cpu, r); sfera_sub_00401F10(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0000207A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40207Au);
    goto label_00001F70;
    label_0000207F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40207Fu);
    goto label_00001FA0;
    label_00002084: cpu->eip = LIFT_CODE_TOKEN_VA(0x402084u);
    goto label_00002000;
    label_00002089: cpu->eip = LIFT_CODE_TOKEN_VA(0x402089u);
    cpu->ecx |= 0xFFFFFFFFu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004020B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4020B0u);
    cpu->eax = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000020BA;
    cpu->eax = lift_load32(cpu->eax);
    label_000020BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4020BAu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004020E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4020E0u);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x29u)) != (uint8_t)(0u)) goto label_000020FA;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000020F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4020F0u);
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x29u)) == (uint8_t)(0u)) goto label_000020F0;
    label_000020FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4020FAu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402100(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402100u);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x11u)) != (uint8_t)(0u)) goto label_0000211B;
    label_00002110: cpu->eip = LIFT_CODE_TOKEN_VA(0x402110u);
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x11u)) == (uint8_t)(0u)) goto label_00002110;
    label_0000211B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40211Bu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402120u);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x29u)) != (uint8_t)(0u)) goto label_0000213B;
    label_00002130: cpu->eip = LIFT_CODE_TOKEN_VA(0x402130u);
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x29u)) == (uint8_t)(0u)) goto label_00002130;
    label_0000213B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40213Bu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402140u);
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x11u)) == (uint8_t)(0u)) goto label_00002150;
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
    label_00002150: cpu->eip = LIFT_CODE_TOKEN_VA(0x402150u);
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x11u)) != (uint8_t)(0u)) goto label_0000216F;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x11u)) != (uint8_t)(0u)) goto label_00002191;
    label_00002161: cpu->eip = LIFT_CODE_TOKEN_VA(0x402161u);
    cpu->edx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x11u)) == (uint8_t)(0u)) goto label_00002161;
    lift_store32(cpu->eax, cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
    label_0000216F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40216Fu);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x11u)) != (uint8_t)(0u)) goto label_00002189;
    label_00002178: cpu->eip = LIFT_CODE_TOKEN_VA(0x402178u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edx))) goto label_00002189;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x11u)) == (uint8_t)(0u)) goto label_00002178;
    label_00002189: cpu->eip = LIFT_CODE_TOKEN_VA(0x402189u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x11u)) != (uint8_t)(0u)) goto label_00002193;
    label_00002191: cpu->eip = LIFT_CODE_TOKEN_VA(0x402191u);
    lift_store32(cpu->eax, cpu->edx);
    label_00002193: cpu->eip = LIFT_CODE_TOKEN_VA(0x402193u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004021A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4021A0u);
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x29u)) == (uint8_t)(0u)) goto label_000021B0;
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
    label_000021B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4021B0u);
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x29u)) != (uint8_t)(0u)) goto label_000021CF;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x29u)) != (uint8_t)(0u)) goto label_000021F1;
    label_000021C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4021C1u);
    cpu->edx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x29u)) == (uint8_t)(0u)) goto label_000021C1;
    lift_store32(cpu->eax, cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
    label_000021CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4021CFu);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x29u)) != (uint8_t)(0u)) goto label_000021E9;
    label_000021D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4021D8u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edx))) goto label_000021E9;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x29u)) == (uint8_t)(0u)) goto label_000021D8;
    label_000021E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4021E9u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x29u)) != (uint8_t)(0u)) goto label_000021F3;
    label_000021F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4021F1u);
    lift_store32(cpu->eax, cpu->edx);
    label_000021F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4021F3u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402200(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402200u);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x15u)) != (uint8_t)(0u)) goto label_0000221B;
    label_00002210: cpu->eip = LIFT_CODE_TOKEN_VA(0x402210u);
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x15u)) == (uint8_t)(0u)) goto label_00002210;
    label_0000221B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40221Bu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402220u);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x15u)) != (uint8_t)(0u)) goto label_0000226A;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x15u)) != (uint8_t)(0u)) goto label_0000224D;
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x15u)) != (uint8_t)(0u)) goto label_0000224A;
    label_00002240: cpu->eip = LIFT_CODE_TOKEN_VA(0x402240u);
    cpu->ecx = cpu->edx;
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x15u)) == (uint8_t)(0u)) goto label_00002240;
    label_0000224A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40224Au);
    lift_store32(cpu->eax, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
    label_0000224D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40224Du);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x15u)) != (uint8_t)(0u)) goto label_00002268;
    label_00002256: cpu->eip = LIFT_CODE_TOKEN_VA(0x402256u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_00002268;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x15u)) == (uint8_t)(0u)) goto label_00002256;
    label_00002268: cpu->eip = LIFT_CODE_TOKEN_VA(0x402268u);
    lift_store32(cpu->eax, cpu->edx);
    label_0000226A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40226Au);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402270u);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Du)) != (uint8_t)(0u)) goto label_0000228B;
    label_00002280: cpu->eip = LIFT_CODE_TOKEN_VA(0x402280u);
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Du)) == (uint8_t)(0u)) goto label_00002280;
    label_0000228B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40228Bu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402290(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402290u);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Du)) != (uint8_t)(0u)) goto label_000022AA;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000022A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4022A0u);
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Du)) == (uint8_t)(0u)) goto label_000022A0;
    label_000022AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4022AAu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004022B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4022B0u);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x15u)) != (uint8_t)(0u)) goto label_000022CA;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000022C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4022C0u);
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x15u)) == (uint8_t)(0u)) goto label_000022C0;
    label_000022CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4022CAu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004022D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4022D0u);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Du)) != (uint8_t)(0u)) goto label_0000231A;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x2Du)) != (uint8_t)(0u)) goto label_000022FD;
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Du)) != (uint8_t)(0u)) goto label_000022FA;
    label_000022F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4022F0u);
    cpu->ecx = cpu->edx;
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Du)) == (uint8_t)(0u)) goto label_000022F0;
    label_000022FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4022FAu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
    label_000022FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4022FDu);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Du)) != (uint8_t)(0u)) goto label_00002318;
    label_00002306: cpu->eip = LIFT_CODE_TOKEN_VA(0x402306u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_00002318;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Du)) == (uint8_t)(0u)) goto label_00002306;
    label_00002318: cpu->eip = LIFT_CODE_TOKEN_VA(0x402318u);
    lift_store32(cpu->eax, cpu->edx);
    label_0000231A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40231Au);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402320(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402320u);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x45u)) != (uint8_t)(0u)) goto label_0000233B;
    label_00002330: cpu->eip = LIFT_CODE_TOKEN_VA(0x402330u);
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x45u)) == (uint8_t)(0u)) goto label_00002330;
    label_0000233B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40233Bu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402340(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402340u);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x45u)) != (uint8_t)(0u)) goto label_0000235A;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00002350: cpu->eip = LIFT_CODE_TOKEN_VA(0x402350u);
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x45u)) == (uint8_t)(0u)) goto label_00002350;
    label_0000235A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40235Au);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402360(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402360u);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x45u)) != (uint8_t)(0u)) goto label_000023AA;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x45u)) != (uint8_t)(0u)) goto label_0000238D;
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x45u)) != (uint8_t)(0u)) goto label_0000238A;
    label_00002380: cpu->eip = LIFT_CODE_TOKEN_VA(0x402380u);
    cpu->ecx = cpu->edx;
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x45u)) == (uint8_t)(0u)) goto label_00002380;
    label_0000238A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40238Au);
    lift_store32(cpu->eax, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
    label_0000238D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40238Du);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x45u)) != (uint8_t)(0u)) goto label_000023A8;
    label_00002396: cpu->eip = LIFT_CODE_TOKEN_VA(0x402396u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_000023A8;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x45u)) == (uint8_t)(0u)) goto label_00002396;
    label_000023A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4023A8u);
    lift_store32(cpu->eax, cpu->edx);
    label_000023AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4023AAu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004023B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4023B0u);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x19u)) != (uint8_t)(0u)) goto label_000023CB;
    label_000023C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4023C0u);
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x19u)) == (uint8_t)(0u)) goto label_000023C0;
    label_000023CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4023CBu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004023D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4023D0u);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x19u)) != (uint8_t)(0u)) goto label_000023EA;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000023E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4023E0u);
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x19u)) == (uint8_t)(0u)) goto label_000023E0;
    label_000023EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4023EAu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004023F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4023F0u);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x19u)) != (uint8_t)(0u)) goto label_0000243A;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x19u)) != (uint8_t)(0u)) goto label_0000241D;
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x19u)) != (uint8_t)(0u)) goto label_0000241A;
    label_00002410: cpu->eip = LIFT_CODE_TOKEN_VA(0x402410u);
    cpu->ecx = cpu->edx;
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x19u)) == (uint8_t)(0u)) goto label_00002410;
    label_0000241A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40241Au);
    lift_store32(cpu->eax, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
    label_0000241D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40241Du);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x19u)) != (uint8_t)(0u)) goto label_00002438;
    label_00002426: cpu->eip = LIFT_CODE_TOKEN_VA(0x402426u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_00002438;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x19u)) == (uint8_t)(0u)) goto label_00002426;
    label_00002438: cpu->eip = LIFT_CODE_TOKEN_VA(0x402438u);
    lift_store32(cpu->eax, cpu->edx);
    label_0000243A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40243Au);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402440(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402440u);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x31u)) != (uint8_t)(0u)) goto label_0000245B;
    label_00002450: cpu->eip = LIFT_CODE_TOKEN_VA(0x402450u);
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x31u)) == (uint8_t)(0u)) goto label_00002450;
    label_0000245B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40245Bu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402460(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402460u);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x31u)) != (uint8_t)(0u)) goto label_0000247A;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00002470: cpu->eip = LIFT_CODE_TOKEN_VA(0x402470u);
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x31u)) == (uint8_t)(0u)) goto label_00002470;
    label_0000247A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40247Au);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402480u);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x31u)) != (uint8_t)(0u)) goto label_000024CA;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x31u)) != (uint8_t)(0u)) goto label_000024AD;
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x31u)) != (uint8_t)(0u)) goto label_000024AA;
    label_000024A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4024A0u);
    cpu->ecx = cpu->edx;
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x31u)) == (uint8_t)(0u)) goto label_000024A0;
    label_000024AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4024AAu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
    label_000024AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4024ADu);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x31u)) != (uint8_t)(0u)) goto label_000024C8;
    label_000024B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4024B6u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_000024C8;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x31u)) == (uint8_t)(0u)) goto label_000024B6;
    label_000024C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4024C8u);
    lift_store32(cpu->eax, cpu->edx);
    label_000024CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4024CAu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004024D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4024D0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->edx;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_00002528;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    (void)cpu;
    label_000024E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4024E0u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->esi)) goto label_00002516;
    cpu->edx = 0x46u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4024F3u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4024FCu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edi + 4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi);
    lift_store32(cpu->edi, cpu->edx);
    cpu->esp += 4u;
    lift_store32(cpu->esi + 4u, 0u);
    lift_store32(cpu->esi, 0u);
    label_00002516: cpu->eip = LIFT_CODE_TOKEN_VA(0x402516u);
    cpu->esi += 8u;
    cpu->edi += 8u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_000024E0;
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00002528: cpu->eip = LIFT_CODE_TOKEN_VA(0x402528u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402540(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402540u);
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x2Du)) == (uint8_t)(0u)) goto label_00002550;
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
    label_00002550: cpu->eip = LIFT_CODE_TOKEN_VA(0x402550u);
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Du)) != (uint8_t)(0u)) goto label_0000256F;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x2Du)) != (uint8_t)(0u)) goto label_00002591;
    label_00002561: cpu->eip = LIFT_CODE_TOKEN_VA(0x402561u);
    cpu->edx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x2Du)) == (uint8_t)(0u)) goto label_00002561;
    lift_store32(cpu->eax, cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
    label_0000256F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40256Fu);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Du)) != (uint8_t)(0u)) goto label_00002589;
    label_00002578: cpu->eip = LIFT_CODE_TOKEN_VA(0x402578u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edx))) goto label_00002589;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Du)) == (uint8_t)(0u)) goto label_00002578;
    label_00002589: cpu->eip = LIFT_CODE_TOKEN_VA(0x402589u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x2Du)) != (uint8_t)(0u)) goto label_00002593;
    label_00002591: cpu->eip = LIFT_CODE_TOKEN_VA(0x402591u);
    lift_store32(cpu->eax, cpu->edx);
    label_00002593: cpu->eip = LIFT_CODE_TOKEN_VA(0x402593u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004025A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4025A0u);
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x15u)) == (uint8_t)(0u)) goto label_000025B0;
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
    label_000025B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4025B0u);
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x15u)) != (uint8_t)(0u)) goto label_000025CF;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x15u)) != (uint8_t)(0u)) goto label_000025F1;
    label_000025C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4025C1u);
    cpu->edx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x15u)) == (uint8_t)(0u)) goto label_000025C1;
    lift_store32(cpu->eax, cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
    label_000025CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4025CFu);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x15u)) != (uint8_t)(0u)) goto label_000025E9;
    label_000025D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4025D8u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edx))) goto label_000025E9;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x15u)) == (uint8_t)(0u)) goto label_000025D8;
    label_000025E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4025E9u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x15u)) != (uint8_t)(0u)) goto label_000025F3;
    label_000025F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4025F1u);
    lift_store32(cpu->eax, cpu->edx);
    label_000025F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4025F3u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402600(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402600u);
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x45u)) == (uint8_t)(0u)) goto label_00002610;
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
    label_00002610: cpu->eip = LIFT_CODE_TOKEN_VA(0x402610u);
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x45u)) != (uint8_t)(0u)) goto label_0000262F;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x45u)) != (uint8_t)(0u)) goto label_00002651;
    label_00002621: cpu->eip = LIFT_CODE_TOKEN_VA(0x402621u);
    cpu->edx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x45u)) == (uint8_t)(0u)) goto label_00002621;
    lift_store32(cpu->eax, cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
    label_0000262F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40262Fu);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x45u)) != (uint8_t)(0u)) goto label_00002649;
    label_00002638: cpu->eip = LIFT_CODE_TOKEN_VA(0x402638u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edx))) goto label_00002649;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x45u)) == (uint8_t)(0u)) goto label_00002638;
    label_00002649: cpu->eip = LIFT_CODE_TOKEN_VA(0x402649u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x45u)) != (uint8_t)(0u)) goto label_00002653;
    label_00002651: cpu->eip = LIFT_CODE_TOKEN_VA(0x402651u);
    lift_store32(cpu->eax, cpu->edx);
    label_00002653: cpu->eip = LIFT_CODE_TOKEN_VA(0x402653u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402660(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402660u);
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x19u)) == (uint8_t)(0u)) goto label_00002670;
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
    label_00002670: cpu->eip = LIFT_CODE_TOKEN_VA(0x402670u);
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x19u)) != (uint8_t)(0u)) goto label_0000268F;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x19u)) != (uint8_t)(0u)) goto label_000026B1;
    label_00002681: cpu->eip = LIFT_CODE_TOKEN_VA(0x402681u);
    cpu->edx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x19u)) == (uint8_t)(0u)) goto label_00002681;
    lift_store32(cpu->eax, cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
    label_0000268F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40268Fu);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x19u)) != (uint8_t)(0u)) goto label_000026A9;
    label_00002698: cpu->eip = LIFT_CODE_TOKEN_VA(0x402698u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edx))) goto label_000026A9;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x19u)) == (uint8_t)(0u)) goto label_00002698;
    label_000026A9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4026A9u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x19u)) != (uint8_t)(0u)) goto label_000026B3;
    label_000026B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4026B1u);
    lift_store32(cpu->eax, cpu->edx);
    label_000026B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4026B3u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004026C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4026C0u);
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x31u)) == (uint8_t)(0u)) goto label_000026D0;
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
    label_000026D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4026D0u);
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x31u)) != (uint8_t)(0u)) goto label_000026EF;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x31u)) != (uint8_t)(0u)) goto label_00002711;
    label_000026E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4026E1u);
    cpu->edx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x31u)) == (uint8_t)(0u)) goto label_000026E1;
    lift_store32(cpu->eax, cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
    label_000026EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4026EFu);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x31u)) != (uint8_t)(0u)) goto label_00002709;
    label_000026F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4026F8u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edx))) goto label_00002709;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x31u)) == (uint8_t)(0u)) goto label_000026F8;
    label_00002709: cpu->eip = LIFT_CODE_TOKEN_VA(0x402709u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x31u)) != (uint8_t)(0u)) goto label_00002713;
    label_00002711: cpu->eip = LIFT_CODE_TOKEN_VA(0x402711u);
    lift_store32(cpu->eax, cpu->edx);
    label_00002713: cpu->eip = LIFT_CODE_TOKEN_VA(0x402713u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402720(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402720u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x402733u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40273Au); lift_push32(cpu, r); sfera_sub_0043B0B0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->edi);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00002748;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_0000275C;
    label_00002748: cpu->eip = LIFT_CODE_TOKEN_VA(0x402748u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00002765;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_0000275C;
    cpu->eax = (uint32_t)(cpu->eax + cpu->esi + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_00002765;
    label_0000275C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40275Cu);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2765u); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    label_00002765: cpu->eip = LIFT_CODE_TOKEN_VA(0x402765u);
    cpu->edi = lift_load32(cpu->edi);
    cpu->edi += g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = 0x20u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    lift_store32(cpu->ebx, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40277Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x402784u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebx + 4u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x40278Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x40278Fu);
    cpu->esp += 0x10u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004027A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4027A0u);
    cpu->eax = lift_load32(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 8u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edi)) goto label_000027B7;
    lift_push32(cpu, (uint32_t)(uintptr_t)"invalid string position");
    lift_trap(cpu, cpu->eip, "std::out_of_range");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x27B7u);
    label_000027B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4027B7u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    cpu->eax -= cpu->edi;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->esi)) goto label_000027C5;
    cpu->esi = cpu->eax;
    label_000027C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4027C5u);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebx)) goto label_000027D1;
    cpu->edx = cpu->ebx;
    label_000027D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4027D1u);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x14u)) < (uint32_t)(0x10u)) goto label_000027DB;
    cpu->eax = lift_load32(cpu->ecx);
    goto label_000027DD;
    label_000027DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4027DBu);
    cpu->eax = cpu->ecx;
    label_000027DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4027DDu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->edi;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4027EBu); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00002806;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->ebx)) goto label_000027FF;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_000027FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4027FFu);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    label_00002806: cpu->eip = LIFT_CODE_TOKEN_VA(0x402806u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402810(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402810u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_00002829;
    lift_push32(cpu, (uint32_t)(uintptr_t)"invalid string position");
    lift_trap(cpu, cpu->eip, "std::out_of_range");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x2829u);
    label_00002829: cpu->eip = LIFT_CODE_TOKEN_VA(0x402829u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->eax -= cpu->ecx;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edi)) goto label_00002836;
    cpu->edi = cpu->eax;
    label_00002836: cpu->eip = LIFT_CODE_TOKEN_VA(0x402836u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_0000288A;
    cpu->edx = lift_load32(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->ebx);
    if ((uint32_t)(cpu->edx) < (uint32_t)(0x10u)) goto label_00002847;
    cpu->ebx = lift_load32(cpu->esi);
    goto label_00002849;
    label_00002847: cpu->eip = LIFT_CODE_TOKEN_VA(0x402847u);
    cpu->ebx = cpu->esi;
    label_00002849: cpu->eip = LIFT_CODE_TOKEN_VA(0x402849u);
    if ((uint32_t)(cpu->edx) < (uint32_t)(0x10u)) goto label_00002852;
    cpu->edx = lift_load32(cpu->esi);
    goto label_00002854;
    label_00002852: cpu->eip = LIFT_CODE_TOKEN_VA(0x402852u);
    cpu->edx = cpu->esi;
    label_00002854: cpu->eip = LIFT_CODE_TOKEN_VA(0x402854u);
    cpu->eax -= cpu->edi;
    cpu->ebx += cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ebx += cpu->edi;
    cpu->edx += cpu->ecx;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x40285Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x402865u);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->esp += 0xCu;
    cpu->eax -= cpu->edi;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00002884;
    cpu->ecx = lift_load32(cpu->esi);
    lift_store8(cpu->ecx + cpu->eax, 0u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00002884: cpu->eip = LIFT_CODE_TOKEN_VA(0x402884u);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->ecx + cpu->eax, 0u);
    label_0000288A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40288Au);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004028A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4028A0u);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = 0u;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000028ED;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(0xFFFFFFFFu)) goto label_000028BF;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4028B8u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000028ED;
    label_000028BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4028BFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 0x14u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x28EDu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_000028ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4028EDu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402900u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_00002926;
    cpu->edx = lift_load32(cpu->ecx + 0x14u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->ecx + 0x10u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edx)) goto label_00002926;
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->ecx + 0x10u);
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u), cpu->edx);
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_00002926: cpu->eip = LIFT_CODE_TOKEN_VA(0x402926u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402930(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402930u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0000295F;
    cpu->edx = lift_load32(cpu->ecx + 0x14u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->ecx + 0x10u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edx)) goto label_0000295F;
    cpu->ecx = lift_load32(cpu->ecx + 0x10u);
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->edx);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->ecx + cpu->edx, cpu->eax);
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_0000295F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40295Fu);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402970u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_00002996;
    cpu->edx = lift_load32(cpu->ecx + 0x14u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->ecx + 0x10u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edx)) goto label_00002996;
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->ecx + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_store_f32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_00002996: cpu->eip = LIFT_CODE_TOKEN_VA(0x402996u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004029A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4029A0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000029CE;
    cpu->edx = lift_load32(cpu->ecx + 0x14u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->ecx + 0x10u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edx)) goto label_000029CE;
    cpu->ecx = lift_load32(cpu->ecx + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u)));
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->edx);
    lift_store_f32(cpu->eax + cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_000029CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4029CEu);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004029E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4029E0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_00002A03;
    cpu->edx = lift_load32(cpu->ecx + 0x14u);
    cpu->edx -= lift_load32(cpu->ecx + 0x10u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edx)) goto label_00002A03;
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->ecx + 0x10u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    lift_store8(cpu->eax + cpu->ecx, cpu->edx & 0xFFu);
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_00002A03: cpu->eip = LIFT_CODE_TOKEN_VA(0x402A03u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402A10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402A10u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_00002A3C;
    cpu->edx = lift_load32(cpu->ecx + 0x14u);
    cpu->edx -= lift_load32(cpu->ecx + 0x10u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edx)) goto label_00002A3C;
    cpu->ecx = lift_load32(cpu->ecx + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + cpu->ecx)) & 0xFFu);
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->edx);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_store8(cpu->ecx + cpu->edx, cpu->eax & 0xFFu);
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_00002A3C: cpu->eip = LIFT_CODE_TOKEN_VA(0x402A3Cu);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402A50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402A50u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_00002AAE;
    cpu->edx = lift_load32(cpu->ecx + 0x14u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->ecx + 0x10u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edx)) goto label_00002AAE;
    cpu->ecx = lift_load32(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->esi = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 8u));
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_00002AA7;
    cpu->edx = 0x46u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x402A84u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x402A8Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi);
    lift_store32(cpu->esi, cpu->ecx);
    cpu->esp += 4u;
    lift_store32(cpu->edi + 4u, 0u);
    lift_store32(cpu->edi, 0u);
    label_00002AA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x402AA7u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00002AAE: cpu->eip = LIFT_CODE_TOKEN_VA(0x402AAEu);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402AC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402AC0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_00002AE9;
    cpu->edx = lift_load32(cpu->ecx + 0x14u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->ecx + 0x10u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edx)) goto label_00002AE9;
    cpu->ecx = lift_load32(cpu->ecx + 0x10u);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 8u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x402AE4u); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_00002AE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x402AE9u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402AF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402AF0u);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x29u)) != (uint8_t)(0u)) goto label_00002B3A;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x29u)) != (uint8_t)(0u)) goto label_00002B1D;
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x29u)) != (uint8_t)(0u)) goto label_00002B1A;
    label_00002B10: cpu->eip = LIFT_CODE_TOKEN_VA(0x402B10u);
    cpu->ecx = cpu->edx;
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->edx + 0x29u)) == (uint8_t)(0u)) goto label_00002B10;
    label_00002B1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x402B1Au);
    lift_store32(cpu->eax, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
    label_00002B1D: cpu->eip = LIFT_CODE_TOKEN_VA(0x402B1Du);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x29u)) != (uint8_t)(0u)) goto label_00002B38;
    label_00002B26: cpu->eip = LIFT_CODE_TOKEN_VA(0x402B26u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_00002B38;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x29u)) == (uint8_t)(0u)) goto label_00002B26;
    label_00002B38: cpu->eip = LIFT_CODE_TOKEN_VA(0x402B38u);
    lift_store32(cpu->eax, cpu->edx);
    label_00002B3A: cpu->eip = LIFT_CODE_TOKEN_VA(0x402B3Au);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402B40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402B40u);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = 0u;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00002B9D;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(0x9249249u)) goto label_00002B6F;
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ecx) * 8u));
    cpu->eax -= cpu->ecx;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x402B68u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00002B9D;
    label_00002B6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x402B6Fu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 0x14u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2B9Du); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_00002B9D: cpu->eip = LIFT_CODE_TOKEN_VA(0x402B9Du);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402BB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402BB0u);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = 0u;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00002C07;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(0x1FFFFFFFu)) goto label_00002BD9;
    cpu->eax = (uint32_t)(((uint32_t)(cpu->ecx) * 8u));
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x402BD2u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00002C07;
    label_00002BD9: cpu->eip = LIFT_CODE_TOKEN_VA(0x402BD9u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 0x14u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2C07u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_00002C07: cpu->eip = LIFT_CODE_TOKEN_VA(0x402C07u);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402C10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402C10u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    lift_store32(cpu->edx + 8u, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->esi + 0x29u)) != (uint8_t)(0u)) goto label_00002C28;
    lift_store32(cpu->esi + 4u, cpu->edx);
    label_00002C28: cpu->eip = LIFT_CODE_TOKEN_VA(0x402C28u);
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 4u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_00002C42;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_00002C42: cpu->eip = LIFT_CODE_TOKEN_VA(0x402C42u);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx))) goto label_00002C53;
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_00002C53: cpu->eip = LIFT_CODE_TOKEN_VA(0x402C53u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402C60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402C60u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->edx, cpu->esi);
    cpu->esi = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x29u)) != (uint8_t)(0u)) goto label_00002C78;
    lift_store32(cpu->esi + 4u, cpu->edx);
    label_00002C78: cpu->eip = LIFT_CODE_TOKEN_VA(0x402C78u);
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 4u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_00002C93;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_00002C93: cpu->eip = LIFT_CODE_TOKEN_VA(0x402C93u);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 8u))) goto label_00002CA7;
    lift_store32(cpu->ecx + 8u, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_00002CA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x402CA7u);
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402CF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402CF0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 4u)) == (uint32_t)(0u)) goto label_00002D14;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x402D08u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x402D11u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00002D14: cpu->eip = LIFT_CODE_TOKEN_VA(0x402D14u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402D20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402D20u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0xCu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00002D71;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x402D65u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x402D6Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00002D71: cpu->eip = LIFT_CODE_TOKEN_VA(0x402D71u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00002D9A;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x402D8Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x402D97u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00002D9A: cpu->eip = LIFT_CODE_TOKEN_VA(0x402D9Au);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402DB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402DB0u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    lift_store32(cpu->edx + 8u, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->esi + 0x15u)) != (uint8_t)(0u)) goto label_00002DC8;
    lift_store32(cpu->esi + 4u, cpu->edx);
    label_00002DC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x402DC8u);
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 4u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_00002DE2;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_00002DE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x402DE2u);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx))) goto label_00002DF3;
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_00002DF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x402DF3u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402E00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402E00u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->edx, cpu->esi);
    cpu->esi = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x15u)) != (uint8_t)(0u)) goto label_00002E18;
    lift_store32(cpu->esi + 4u, cpu->edx);
    label_00002E18: cpu->eip = LIFT_CODE_TOKEN_VA(0x402E18u);
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 4u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_00002E33;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_00002E33: cpu->eip = LIFT_CODE_TOKEN_VA(0x402E33u);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 8u))) goto label_00002E47;
    lift_store32(cpu->ecx + 8u, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_00002E47: cpu->eip = LIFT_CODE_TOKEN_VA(0x402E47u);
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402E60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402E60u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->edx, cpu->esi);
    cpu->esi = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x2Du)) != (uint8_t)(0u)) goto label_00002E78;
    lift_store32(cpu->esi + 4u, cpu->edx);
    label_00002E78: cpu->eip = LIFT_CODE_TOKEN_VA(0x402E78u);
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 4u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_00002E93;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_00002E93: cpu->eip = LIFT_CODE_TOKEN_VA(0x402E93u);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 8u))) goto label_00002EA7;
    lift_store32(cpu->ecx + 8u, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_00002EA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x402EA7u);
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402EC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402EC0u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    lift_store32(cpu->edx + 8u, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->esi + 0x2Du)) != (uint8_t)(0u)) goto label_00002ED8;
    lift_store32(cpu->esi + 4u, cpu->edx);
    label_00002ED8: cpu->eip = LIFT_CODE_TOKEN_VA(0x402ED8u);
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 4u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_00002EF2;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_00002EF2: cpu->eip = LIFT_CODE_TOKEN_VA(0x402EF2u);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx))) goto label_00002F03;
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_00002F03: cpu->eip = LIFT_CODE_TOKEN_VA(0x402F03u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402F10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402F10u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    lift_store32(cpu->edx + 8u, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->esi + 0x45u)) != (uint8_t)(0u)) goto label_00002F28;
    lift_store32(cpu->esi + 4u, cpu->edx);
    label_00002F28: cpu->eip = LIFT_CODE_TOKEN_VA(0x402F28u);
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 4u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_00002F42;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_00002F42: cpu->eip = LIFT_CODE_TOKEN_VA(0x402F42u);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx))) goto label_00002F53;
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_00002F53: cpu->eip = LIFT_CODE_TOKEN_VA(0x402F53u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402F60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402F60u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->edx, cpu->esi);
    cpu->esi = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x45u)) != (uint8_t)(0u)) goto label_00002F78;
    lift_store32(cpu->esi + 4u, cpu->edx);
    label_00002F78: cpu->eip = LIFT_CODE_TOKEN_VA(0x402F78u);
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 4u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_00002F93;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_00002F93: cpu->eip = LIFT_CODE_TOKEN_VA(0x402F93u);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 8u))) goto label_00002FA7;
    lift_store32(cpu->ecx + 8u, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_00002FA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x402FA7u);
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00402FC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x402FC0u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    lift_store32(cpu->edx + 8u, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->esi + 0x19u)) != (uint8_t)(0u)) goto label_00002FD8;
    lift_store32(cpu->esi + 4u, cpu->edx);
    label_00002FD8: cpu->eip = LIFT_CODE_TOKEN_VA(0x402FD8u);
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 4u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_00002FF2;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_00002FF2: cpu->eip = LIFT_CODE_TOKEN_VA(0x402FF2u);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx))) goto label_00003003;
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_00003003: cpu->eip = LIFT_CODE_TOKEN_VA(0x403003u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00403010(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403010u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->edx, cpu->esi);
    cpu->esi = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x19u)) != (uint8_t)(0u)) goto label_00003028;
    lift_store32(cpu->esi + 4u, cpu->edx);
    label_00003028: cpu->eip = LIFT_CODE_TOKEN_VA(0x403028u);
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 4u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_00003043;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_00003043: cpu->eip = LIFT_CODE_TOKEN_VA(0x403043u);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 8u))) goto label_00003057;
    lift_store32(cpu->ecx + 8u, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_00003057: cpu->eip = LIFT_CODE_TOKEN_VA(0x403057u);
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00403070(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403070u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    lift_store32(cpu->edx + 8u, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->esi + 0x31u)) != (uint8_t)(0u)) goto label_00003088;
    lift_store32(cpu->esi + 4u, cpu->edx);
    label_00003088: cpu->eip = LIFT_CODE_TOKEN_VA(0x403088u);
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 4u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_000030A2;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_000030A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4030A2u);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx))) goto label_000030B3;
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_000030B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4030B3u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004030C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4030C0u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->edx, cpu->esi);
    cpu->esi = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x31u)) != (uint8_t)(0u)) goto label_000030D8;
    lift_store32(cpu->esi + 4u, cpu->edx);
    label_000030D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4030D8u);
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 4u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_000030F3;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_000030F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4030F3u);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->ecx + 8u))) goto label_00003107;
    lift_store32(cpu->ecx + 8u, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
    label_00003107: cpu->eip = LIFT_CODE_TOKEN_VA(0x403107u);
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00403120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403120u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_00003140;
    lift_push32(cpu, cpu->esi);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00003130: cpu->eip = LIFT_CODE_TOKEN_VA(0x403130u);
    cpu->esi = lift_load32(cpu->edx + 0xFFFFFFFCu);
    cpu->edx -= 4u;
    cpu->eax -= 4u;
    lift_store32(cpu->eax, cpu->esi);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->ecx)) goto label_00003130;
    cpu->esi = lift_pop32(cpu);
    label_00003140: cpu->eip = LIFT_CODE_TOKEN_VA(0x403140u);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00403150(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403150u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0000316C;
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00003160: cpu->eip = LIFT_CODE_TOKEN_VA(0x403160u);
    cpu->esi = lift_load32(cpu->eax);
    lift_store32(cpu->ecx, cpu->esi);
    cpu->ecx += 4u;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_00003160;
    cpu->esi = lift_pop32(cpu);
    label_0000316C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40316Cu);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00403170(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403170u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebx + 0x10u);
    cpu->eax = 0xCCCCCCCDu;
    lift_multiply_accumulator(cpu, cpu->edi, 32u, 0u);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->ecx = 0u;
    ++cpu->edx;
    cpu->esi = 0x811C9DC5u;
    if ((uint32_t)(cpu->edi) == 0u) goto label_000031B2;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->ebx + 0x14u);
    label_00003194: cpu->eip = LIFT_CODE_TOKEN_VA(0x403194u);
    if ((uint32_t)(cpu->ebp) < (uint32_t)(0x10u)) goto label_0000319D;
    cpu->eax = lift_load32(cpu->ebx);
    goto label_0000319F;
    label_0000319D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40319Du);
    cpu->eax = cpu->ebx;
    label_0000319F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40319Fu);
    cpu->eax = (int8_t)(lift_load8(cpu->eax + cpu->ecx));
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x1000193u);
    cpu->ecx += cpu->edx;
    cpu->esi ^= cpu->eax;
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->edi)) goto label_00003194;
    cpu->ebp = lift_pop32(cpu);
    label_000031B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4031B2u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004031C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4031C0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_000031D2;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_000031E5;
    label_000031D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4031D2u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000031F1;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_000031E5;
    cpu->eax += 0xBu;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_000031F1;
    label_000031E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4031E5u);
    cpu->edx = 0xCu;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x31F1u); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    label_000031F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4031F1u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->esi = lift_load32(cpu->edi + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00003216;
    cpu->ecx = lift_load32(cpu->edi);
    cpu->ecx -= cpu->edx;
    lift_store32(cpu->eax + cpu->edx + 4u, cpu->ecx);
    lift_store32(cpu->eax + cpu->edx, cpu->ecx);
    cpu->ecx += cpu->esi;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax + cpu->edx + 8u, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00003216: cpu->eip = LIFT_CODE_TOKEN_VA(0x403216u);
    cpu->ecx = cpu->edi;
    cpu->ecx -= cpu->edx;
    lift_store32(cpu->eax + cpu->edx + 4u, cpu->ecx);
    lift_store32(cpu->eax + cpu->edx, cpu->ecx);
    cpu->ecx += cpu->esi;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax + cpu->edx + 8u, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00403230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403230u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    cpu->edi = cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->edi);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->esi = cpu->eax;
    cpu->esi |= 0xFu;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xFFFFFFFEu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_00003271;
    cpu->esi = cpu->eax;
    goto label_00003298;
    label_00003271: cpu->eip = LIFT_CODE_TOKEN_VA(0x403271u);
    cpu->ebx = lift_load32(cpu->edi + 0x14u);
    cpu->eax = 0xAAAAAAABu;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 0u);
    cpu->ecx = cpu->ebx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(cpu->edx)) goto label_00003298;
    cpu->eax = 0xFFFFFFFEu;
    cpu->eax -= cpu->ecx;
    cpu->esi = (uint32_t)(cpu->ecx + cpu->ebx);
    if ((uint32_t)(cpu->ebx) <= (uint32_t)(cpu->eax)) goto label_00003298;
    cpu->esi = 0xFFFFFFFEu;
    label_00003298: cpu->eip = LIFT_CODE_TOKEN_VA(0x403298u);
    cpu->eax = 0u;
    cpu->ecx = (uint32_t)(cpu->esi + 1u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, cpu->eax);
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(cpu->eax)) goto label_000032B6;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(0xFFFFFFFFu)) goto label_000032BB;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4032AFu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000032BB;
    label_000032B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4032B6u);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    goto label_0000330D;
    label_000032BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4032BBu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x32E4u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    sfera_sub_004032E4(cpu, stop_address); return;
    label_0000330D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40330Du);
    cpu->ebx = lift_load32(cpu->ebp + 0xCu);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0000332E;
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) < (uint32_t)(0x10u)) goto label_0000331E;
    cpu->eax = lift_load32(cpu->edi);
    goto label_00003320;
    label_0000331E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40331Eu);
    cpu->eax = cpu->edi;
    label_00003320: cpu->eip = LIFT_CODE_TOKEN_VA(0x403320u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x403326u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x40332Bu);
    cpu->esp += 0xCu;
    label_0000332E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40332Eu);
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) < (uint32_t)(0x10u)) goto label_0000333F;
    cpu->ecx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40333Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000333F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40333Fu);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store8(cpu->edi, 0u);
    lift_store32(cpu->edi, cpu->eax);
    lift_store32(cpu->edi + 0x14u, cpu->esi);
    lift_store32(cpu->edi + 0x10u, cpu->ebx);
    if ((uint32_t)(cpu->esi) < (uint32_t)(0x10u)) goto label_00003354;
    cpu->edi = cpu->eax;
    label_00003354: cpu->eip = LIFT_CODE_TOKEN_VA(0x403354u);
    lift_store8(cpu->edi + cpu->ebx, 0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004032E4(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4032E4u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->eax);
    ++cpu->eax;
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx += 0x18u;
    lift_store8(cpu->ebp + 0xFFFFFFFCu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4032FEu); lift_push32(cpu, r); sfera_sub_004028A0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 8u, cpu->eax);
    cpu->eax = LIFT_CALLBACK(sfera_sub_00403307);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00403307(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403307u);
    cpu->edi = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->ebx = lift_load32(cpu->ebp + 0xCu);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0000332E;
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) < (uint32_t)(0x10u)) goto label_0000331E;
    cpu->eax = lift_load32(cpu->edi);
    goto label_00003320;
    label_0000331E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40331Eu);
    cpu->eax = cpu->edi;
    label_00003320: cpu->eip = LIFT_CODE_TOKEN_VA(0x403320u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x403326u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x40332Bu);
    cpu->esp += 0xCu;
    label_0000332E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40332Eu);
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) < (uint32_t)(0x10u)) goto label_0000333F;
    cpu->ecx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40333Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000333F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40333Fu);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store8(cpu->edi, 0u);
    lift_store32(cpu->edi, cpu->eax);
    lift_store32(cpu->edi + 0x14u, cpu->esi);
    lift_store32(cpu->edi + 0x10u, cpu->ebx);
    if ((uint32_t)(cpu->esi) < (uint32_t)(0x10u)) goto label_00003354;
    cpu->edi = cpu->eax;
    label_00003354: cpu->eip = LIFT_CODE_TOKEN_VA(0x403354u);
    lift_store8(cpu->edi + cpu->ebx, 0u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040336C(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40336Cu);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFECu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_00003380;
    cpu->edx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40337Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00003380: cpu->eip = LIFT_CODE_TOKEN_VA(0x403380u);
    lift_push32(cpu, 0u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_push32(cpu, 0u);
    lift_store8(cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40339Au); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x40339Au, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004033A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4033A0u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 8u);
    if ((int32_t)(uint32_t)(cpu->edi) < 0) goto label_000033E6;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 0x14u);
    cpu->esi -= lift_load32(cpu->ecx + 0x10u);
    cpu->eax = 0x92492493u;
    lift_multiply_accumulator(cpu, cpu->esi, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(4u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_000033E6;
    cpu->eax = lift_load32(cpu->ecx + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->edi) * 8u));
    cpu->edx -= cpu->edi;
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4033E0u); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000033E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4033E6u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004033F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4033F0u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x11u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00003434;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00003410: cpu->eip = LIFT_CODE_TOKEN_VA(0x403410u);
    cpu->esi = lift_load32(cpu->eax + 0xCu);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->edi)) goto label_0000341C;
    cpu->eax = lift_load32(cpu->eax + 8u);
    goto label_0000342C;
    label_0000341C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40341Cu);
    if ((uint8_t)(lift_load8(cpu->edx + 0x11u)) == (uint8_t)(0u)) goto label_00003428;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->esi)) goto label_00003428;
    cpu->edx = cpu->eax;
    label_00003428: cpu->eip = LIFT_CODE_TOKEN_VA(0x403428u);
    cpu->ebx = cpu->eax;
    cpu->eax = lift_load32(cpu->eax);
    label_0000342C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40342Cu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x11u)) == (uint8_t)(0u)) goto label_00003410;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_00003434: cpu->eip = LIFT_CODE_TOKEN_VA(0x403434u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x11u)) == (uint8_t)(0u)) goto label_00003442;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    goto label_00003444;
    label_00003442: cpu->eip = LIFT_CODE_TOKEN_VA(0x403442u);
    cpu->eax = lift_load32(cpu->edx);
    label_00003444: cpu->eip = LIFT_CODE_TOKEN_VA(0x403444u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x11u)) != (uint8_t)(0u)) goto label_00003464;
    cpu->ecx = lift_load32(cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00003450: cpu->eip = LIFT_CODE_TOKEN_VA(0x403450u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(lift_load32(cpu->eax + 0xCu))) goto label_0000345B;
    cpu->edx = cpu->eax;
    cpu->eax = lift_load32(cpu->eax);
    goto label_0000345E;
    label_0000345B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40345Bu);
    cpu->eax = lift_load32(cpu->eax + 8u);
    label_0000345E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40345Eu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x11u)) == (uint8_t)(0u)) goto label_00003450;
    label_00003464: cpu->eip = LIFT_CODE_TOKEN_VA(0x403464u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00403480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403480u);
    cpu->eax = lift_load32(cpu->ecx + 0x10u);
    lift_store32(cpu->ecx + 0x20u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ecx + 0x14u))) goto label_000034A7;
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->esi + cpu->edx, cpu->eax);
    lift_store8(cpu->ecx + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000034A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4034A7u);
    lift_store8(cpu->ecx + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004034C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4034C0u);
    cpu->eax = lift_load32(cpu->ecx + 0x10u);
    lift_store32(cpu->ecx + 0x20u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ecx + 0x14u))) goto label_000034E7;
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    cpu->edx = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    lift_store8(cpu->esi + cpu->edx, cpu->eax & 0xFFu);
    lift_store8(cpu->ecx + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000034E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4034E7u);
    lift_store8(cpu->ecx + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00403500(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403500u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x15u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00003544;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00003520: cpu->eip = LIFT_CODE_TOKEN_VA(0x403520u);
    cpu->esi = lift_load32(cpu->eax + 0xCu);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->edi)) goto label_0000352C;
    cpu->eax = lift_load32(cpu->eax + 8u);
    goto label_0000353C;
    label_0000352C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40352Cu);
    if ((uint8_t)(lift_load8(cpu->edx + 0x15u)) == (uint8_t)(0u)) goto label_00003538;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->esi)) goto label_00003538;
    cpu->edx = cpu->eax;
    label_00003538: cpu->eip = LIFT_CODE_TOKEN_VA(0x403538u);
    cpu->ebx = cpu->eax;
    cpu->eax = lift_load32(cpu->eax);
    label_0000353C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40353Cu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x15u)) == (uint8_t)(0u)) goto label_00003520;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_00003544: cpu->eip = LIFT_CODE_TOKEN_VA(0x403544u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x15u)) == (uint8_t)(0u)) goto label_00003552;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    goto label_00003554;
    label_00003552: cpu->eip = LIFT_CODE_TOKEN_VA(0x403552u);
    cpu->eax = lift_load32(cpu->edx);
    label_00003554: cpu->eip = LIFT_CODE_TOKEN_VA(0x403554u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x15u)) != (uint8_t)(0u)) goto label_00003574;
    cpu->ecx = lift_load32(cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00003560: cpu->eip = LIFT_CODE_TOKEN_VA(0x403560u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(lift_load32(cpu->eax + 0xCu))) goto label_0000356B;
    cpu->edx = cpu->eax;
    cpu->eax = lift_load32(cpu->eax);
    goto label_0000356E;
    label_0000356B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40356Bu);
    cpu->eax = lift_load32(cpu->eax + 8u);
    label_0000356E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40356Eu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x15u)) == (uint8_t)(0u)) goto label_00003560;
    label_00003574: cpu->eip = LIFT_CODE_TOKEN_VA(0x403574u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00403590(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403590u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x2Du)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000035D4;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000035B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4035B0u);
    cpu->esi = lift_load32(cpu->eax + 0xCu);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->edi)) goto label_000035BC;
    cpu->eax = lift_load32(cpu->eax + 8u);
    goto label_000035CC;
    label_000035BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4035BCu);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Du)) == (uint8_t)(0u)) goto label_000035C8;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->esi)) goto label_000035C8;
    cpu->edx = cpu->eax;
    label_000035C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4035C8u);
    cpu->ebx = cpu->eax;
    cpu->eax = lift_load32(cpu->eax);
    label_000035CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4035CCu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) == (uint8_t)(0u)) goto label_000035B0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000035D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4035D4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Du)) == (uint8_t)(0u)) goto label_000035E2;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    goto label_000035E4;
    label_000035E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4035E2u);
    cpu->eax = lift_load32(cpu->edx);
    label_000035E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4035E4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) != (uint8_t)(0u)) goto label_00003604;
    cpu->ecx = lift_load32(cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000035F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4035F0u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(lift_load32(cpu->eax + 0xCu))) goto label_000035FB;
    cpu->edx = cpu->eax;
    cpu->eax = lift_load32(cpu->eax);
    goto label_000035FE;
    label_000035FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4035FBu);
    cpu->eax = lift_load32(cpu->eax + 8u);
    label_000035FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4035FEu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) == (uint8_t)(0u)) goto label_000035F0;
    label_00003604: cpu->eip = LIFT_CODE_TOKEN_VA(0x403604u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00403620(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403620u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x19u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00003664;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00003640: cpu->eip = LIFT_CODE_TOKEN_VA(0x403640u);
    cpu->esi = lift_load32(cpu->eax + 0xCu);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->edi)) goto label_0000364C;
    cpu->eax = lift_load32(cpu->eax + 8u);
    goto label_0000365C;
    label_0000364C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40364Cu);
    if ((uint8_t)(lift_load8(cpu->edx + 0x19u)) == (uint8_t)(0u)) goto label_00003658;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->esi)) goto label_00003658;
    cpu->edx = cpu->eax;
    label_00003658: cpu->eip = LIFT_CODE_TOKEN_VA(0x403658u);
    cpu->ebx = cpu->eax;
    cpu->eax = lift_load32(cpu->eax);
    label_0000365C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40365Cu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x19u)) == (uint8_t)(0u)) goto label_00003640;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_00003664: cpu->eip = LIFT_CODE_TOKEN_VA(0x403664u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x19u)) == (uint8_t)(0u)) goto label_00003672;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    goto label_00003674;
    label_00003672: cpu->eip = LIFT_CODE_TOKEN_VA(0x403672u);
    cpu->eax = lift_load32(cpu->edx);
    label_00003674: cpu->eip = LIFT_CODE_TOKEN_VA(0x403674u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x19u)) != (uint8_t)(0u)) goto label_00003694;
    cpu->ecx = lift_load32(cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00003680: cpu->eip = LIFT_CODE_TOKEN_VA(0x403680u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(lift_load32(cpu->eax + 0xCu))) goto label_0000368B;
    cpu->edx = cpu->eax;
    cpu->eax = lift_load32(cpu->eax);
    goto label_0000368E;
    label_0000368B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40368Bu);
    cpu->eax = lift_load32(cpu->eax + 8u);
    label_0000368E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40368Eu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x19u)) == (uint8_t)(0u)) goto label_00003680;
    label_00003694: cpu->eip = LIFT_CODE_TOKEN_VA(0x403694u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004036B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4036B0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4036BAu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000036E3;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->eax + 8u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000036DD;
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000036DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4036DDu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
    label_000036E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4036E3u);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 0x14u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x403711u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x403711u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00403720(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403720u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40372Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00003768;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->eax + 8u);
    lift_store32(cpu->eax, cpu->ecx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_00003762;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->edx + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx);
    lift_store32(cpu->edx, cpu->edi);
    lift_store32(cpu->ecx + 4u, 0u);
    lift_store32(cpu->ecx, 0u);
    cpu->edi = lift_pop32(cpu);
    label_00003762: cpu->eip = LIFT_CODE_TOKEN_VA(0x403762u);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
    label_00003768: cpu->eip = LIFT_CODE_TOKEN_VA(0x403768u);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 0x14u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x403796u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x403796u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004037A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4037A0u);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x1FFFFFFEu)) goto label_000037C2;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4037B4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, (uint32_t)(uintptr_t)"map/set<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x37C2u);
    label_000037C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4037C2u);
    ++cpu->eax;
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->ebp + 4u, cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_000037EC;
    lift_store32(cpu->edx + 4u, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->edx, cpu->ebp);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 8u, cpu->ebp);
    goto label_0000380D;
    label_000037EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4037ECu);
    if ((uint8_t)(lift_load8(cpu->esp + 0x10u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000037FF;
    lift_store32(cpu->eax, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx))) goto label_0000380D;
    lift_store32(cpu->edx, cpu->ebp);
    goto label_0000380D;
    label_000037FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4037FFu);
    lift_store32(cpu->eax + 8u, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_0000380D;
    lift_store32(cpu->edx + 8u, cpu->ebp);
    label_0000380D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40380Du);
    cpu->edx = lift_load32(cpu->ebp + 4u);
    cpu->eax = cpu->ebp;
    if ((uint8_t)(lift_load8(cpu->edx + 0x14u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000039AE;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00003820: cpu->eip = LIFT_CODE_TOKEN_VA(0x403820u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->esi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esi))) goto label_000038EF;
    cpu->esi = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x14u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00003852;
    lift_store8(cpu->edx + 0x14u, 1u);
    lift_store8(cpu->esi + 0x14u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x14u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    goto label_000039A0;
    label_00003852: cpu->eip = LIFT_CODE_TOKEN_VA(0x403852u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_00003891;
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->esi = lift_load32(cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx);
    if ((uint8_t)(lift_load8(cpu->esi + 0x15u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000386B;
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_0000386B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40386Bu);
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx + 4u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0000387E;
    lift_store32(cpu->esi + 4u, cpu->edx);
    goto label_0000388C;
    label_0000387E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40387Eu);
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi))) goto label_00003889;
    lift_store32(cpu->esi, cpu->edx);
    goto label_0000388C;
    label_00003889: cpu->eip = LIFT_CODE_TOKEN_VA(0x403889u);
    lift_store32(cpu->esi + 8u, cpu->edx);
    label_0000388C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40388Cu);
    lift_store32(cpu->edx, cpu->eax);
    lift_store32(cpu->eax + 4u, cpu->edx);
    label_00003891: cpu->eip = LIFT_CODE_TOKEN_VA(0x403891u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store8(cpu->edx + 0x14u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x14u, cpu->ebx & 0xFFu);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->esi = lift_load32(cpu->edx);
    cpu->edi = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->edx, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->edi + 0x15u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000038B9;
    lift_store32(cpu->edi + 4u, cpu->edx);
    label_000038B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4038B9u);
    cpu->edi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_000038D2;
    lift_store32(cpu->edi + 4u, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_0000399D;
    label_000038D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4038D2u);
    cpu->edi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_000038E5;
    lift_store32(cpu->edi + 8u, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_0000399D;
    label_000038E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4038E5u);
    lift_store32(cpu->edi, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_0000399D;
    label_000038EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4038EFu);
    cpu->esi = lift_load32(cpu->esi);
    if ((uint8_t)(lift_load8(cpu->esi + 0x14u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00003912;
    lift_store8(cpu->edx + 0x14u, 1u);
    lift_store8(cpu->esi + 0x14u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x14u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    goto label_000039A0;
    label_00003912: cpu->eip = LIFT_CODE_TOKEN_VA(0x403912u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx))) goto label_00003952;
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->edx + 8u);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x15u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000392A;
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_0000392A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40392Au);
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx + 4u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0000393D;
    lift_store32(cpu->esi + 4u, cpu->edx);
    goto label_0000394C;
    label_0000393D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40393Du);
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0000394A;
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_0000394C;
    label_0000394A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40394Au);
    lift_store32(cpu->esi, cpu->edx);
    label_0000394C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40394Cu);
    lift_store32(cpu->edx + 8u, cpu->eax);
    lift_store32(cpu->eax + 4u, cpu->edx);
    label_00003952: cpu->eip = LIFT_CODE_TOKEN_VA(0x403952u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store8(cpu->edx + 0x14u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x14u, cpu->ebx & 0xFFu);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->esi = lift_load32(cpu->edx + 8u);
    cpu->edi = lift_load32(cpu->esi);
    lift_store32(cpu->edx + 8u, cpu->edi);
    cpu->edi = lift_load32(cpu->esi);
    if ((uint8_t)(lift_load8(cpu->edi + 0x15u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000397A;
    lift_store32(cpu->edi + 4u, cpu->edx);
    label_0000397A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40397Au);
    cpu->edi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_0000398D;
    lift_store32(cpu->edi + 4u, cpu->esi);
    goto label_0000399B;
    label_0000398D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40398Du);
    cpu->edi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi))) goto label_00003998;
    lift_store32(cpu->edi, cpu->esi);
    goto label_0000399B;
    label_00003998: cpu->eip = LIFT_CODE_TOKEN_VA(0x403998u);
    lift_store32(cpu->edi + 8u, cpu->esi);
    label_0000399B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40399Bu);
    lift_store32(cpu->esi, cpu->edx);
    label_0000399D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40399Du);
    lift_store32(cpu->edx + 4u, cpu->esi);
    label_000039A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4039A0u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x14u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00003820;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_000039AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4039AEu);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->ebp);
    cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->ecx + 0x14u, 1u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004039D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4039D0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->esi)) goto label_00003A00;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0x1FFFFFFEu;
    cpu->edi -= cpu->edx;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000039F8;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x39F8u);
    label_000039F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4039F8u);
    cpu->edx += cpu->eax;
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) - (uint64_t)(cpu->eax) - (uint64_t)(0u));
    label_00003A00: cpu->eip = LIFT_CODE_TOKEN_VA(0x403A00u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->edx + 4u, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00403A60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403A60u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->esi)) goto label_00003A90;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0x7FFFFFEu;
    cpu->edi -= cpu->edx;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_00003A88;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x3A88u);
    label_00003A88: cpu->eip = LIFT_CODE_TOKEN_VA(0x403A88u);
    cpu->edx += cpu->eax;
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) - (uint64_t)(cpu->eax) - (uint64_t)(0u));
    label_00003A90: cpu->eip = LIFT_CODE_TOKEN_VA(0x403A90u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->edx + 4u, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00403AF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403AF0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->esi)) goto label_00003B20;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0x4924923u;
    cpu->edi -= cpu->edx;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_00003B18;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x3B18u);
    label_00003B18: cpu->eip = LIFT_CODE_TOKEN_VA(0x403B18u);
    cpu->edx += cpu->eax;
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) - (uint64_t)(cpu->eax) - (uint64_t)(0u));
    label_00003B20: cpu->eip = LIFT_CODE_TOKEN_VA(0x403B20u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->edx + 4u, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00403B80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403B80u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->esi)) goto label_00003BB0;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0x71C71C6u;
    cpu->edi -= cpu->edx;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_00003BA8;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x3BA8u);
    label_00003BA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x403BA8u);
    cpu->edx += cpu->eax;
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) - (uint64_t)(cpu->eax) - (uint64_t)(0u));
    label_00003BB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x403BB0u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->edx + 4u, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00403C10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403C10u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = (uint32_t)(cpu->ecx + 8u);
    lift_store32(cpu->esp + 8u, cpu->esi);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0xCu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00003C62;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x403C56u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x403C5Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00003C62: cpu->eip = LIFT_CODE_TOKEN_VA(0x403C62u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00003C8B;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x403C7Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x403C88u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00003C8B: cpu->eip = LIFT_CODE_TOKEN_VA(0x403C8Bu);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00403CA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403CA0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ebp) <= (uint32_t)(0xFFFFFFFEu)) goto label_00003CB8;
    lift_push32(cpu, (uint32_t)(uintptr_t)"string too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x3CB8u);
    label_00003CB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x403CB8u);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ebp)) goto label_00003CD6;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x403CC9u); lift_push32(cpu, r); sfera_sub_00403230(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00003CD6: cpu->eip = LIFT_CODE_TOKEN_VA(0x403CD6u);
    if ((uint8_t)(lift_load8(cpu->esp + 0x10u)) == (uint8_t)(0u)) goto label_00003D29;
    if ((uint32_t)(cpu->ebp) >= (uint32_t)(0x10u)) goto label_00003D29;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->ebp) >= (uint32_t)(cpu->edi)) goto label_00003CEC;
    cpu->edi = cpu->ebp;
    label_00003CEC: cpu->eip = LIFT_CODE_TOKEN_VA(0x403CECu);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x10u)) goto label_00003D0D;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00003D03;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x403CFBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x403D00u);
    cpu->esp += 0xCu;
    label_00003D03: cpu->eip = LIFT_CODE_TOKEN_VA(0x403D03u);
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x403D09u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ebx = lift_pop32(cpu);
    label_00003D0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x403D0Du);
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    cpu->ecx = 0u;
    lift_store8(cpu->edi + cpu->esi, 0u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00003D29: cpu->eip = LIFT_CODE_TOKEN_VA(0x403D29u);
    if ((uint32_t)(cpu->ebp) != 0u) goto label_00003D3A;
    lift_store32(cpu->esi + 0x10u, cpu->ebp);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x10u)) goto label_00003D37;
    cpu->esi = lift_load32(cpu->esi);
    label_00003D37: cpu->eip = LIFT_CODE_TOKEN_VA(0x403D37u);
    lift_store8(cpu->esi, 0u);
    label_00003D3A: cpu->eip = LIFT_CODE_TOKEN_VA(0x403D3Au);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00403D50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403D50u);
    cpu->edx = lift_load32(cpu->ecx + 0x14u);
    cpu->eax = lift_load32(cpu->edx);
    lift_store32(cpu->ecx + 0x20u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_00003D79;
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->eax + 0xCu);
    cpu->edx = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->esi + cpu->edx, cpu->eax);
    lift_store8(cpu->ecx + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00003D79: cpu->eip = LIFT_CODE_TOKEN_VA(0x403D79u);
    lift_store8(cpu->ecx + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00403D90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403D90u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) != (uint8_t)(0u)) goto label_00003DA0;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00003DA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x403DA0u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x403DA9u); lift_push32(cpu, r); sfera_sub_004B1370(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x20u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->esi + 0x14u))) goto label_00003DCD;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edi + 0xCu);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->eax + cpu->ecx, cpu->edx);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00003DCD: cpu->eip = LIFT_CODE_TOKEN_VA(0x403DCDu);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00403DE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403DE0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_00003E05;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x403DFBu); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00003E05: cpu->eip = LIFT_CODE_TOKEN_VA(0x403E05u);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00403E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403E10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) != (uint8_t)(0u)) goto label_00003E20;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00003E20: cpu->eip = LIFT_CODE_TOKEN_VA(0x403E20u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x403E29u); lift_push32(cpu, r); sfera_sub_00402AF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x20u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->esi + 0x14u))) goto label_00003E48;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = (uint32_t)(cpu->edi + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x403E3Du); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00003E48: cpu->eip = LIFT_CODE_TOKEN_VA(0x403E48u);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00403E60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403E60u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = lift_load32(cpu->eax + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00003E6F;
    cpu->eax = lift_load32(cpu->eax);
    label_00003E6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x403E6Fu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x403E80u); lift_push32(cpu, r); sfera_sub_004027A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) != 0u)) ? 1u : 0u) & 0xFFu);
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00403F00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x403F00u);
    cpu->esp -= 0x18u;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x29u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edx = cpu->eax;
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000401B;
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    cpu->ecx = lift_load32(cpu->edx + 0x10u);
    cpu->eax = lift_load32(cpu->edx + 0x14u);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    goto label_00003F4C;
    label_00003F40: cpu->eip = LIFT_CODE_TOKEN_VA(0x403F40u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    label_00003F4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x403F4Cu);
    cpu->edi += 0xCu;
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) < (uint32_t)(0x10u)) goto label_00003F58;
    cpu->edx = lift_load32(cpu->edx);
    label_00003F58: cpu->eip = LIFT_CODE_TOKEN_VA(0x403F58u);
    cpu->esi = lift_load32(cpu->edi + 0x10u);
    cpu->ebp = cpu->esi;
    if ((uint32_t)(cpu->ebp) >= (uint32_t)(cpu->esi)) goto label_00003F61;
    label_00003F61: cpu->eip = LIFT_CODE_TOKEN_VA(0x403F61u);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->ecx)) goto label_00003F67;
    cpu->ecx = cpu->esi;
    label_00003F67: cpu->eip = LIFT_CODE_TOKEN_VA(0x403F67u);
    cpu->ebx = lift_load32(cpu->edi + 0x14u);
    if ((uint32_t)(cpu->ebx) < (uint32_t)(0x10u)) goto label_00003F73;
    cpu->eax = lift_load32(cpu->edi);
    goto label_00003F75;
    label_00003F73: cpu->eip = LIFT_CODE_TOKEN_VA(0x403F73u);
    cpu->eax = cpu->edi;
    label_00003F75: cpu->eip = LIFT_CODE_TOKEN_VA(0x403F75u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x403F7Du); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00003F93;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ecx)) goto label_00003F95;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_00003F93: cpu->eip = LIFT_CODE_TOKEN_VA(0x403F93u);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00003FA2;
    label_00003F95: cpu->eip = LIFT_CODE_TOKEN_VA(0x403F95u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    goto label_00004005;
    label_00003FA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x403FA2u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x29u)) == (uint8_t)(0u)) goto label_00003FF7;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(0x10u)) goto label_00003FB3;
    cpu->edi = lift_load32(cpu->edi);
    label_00003FB3: cpu->eip = LIFT_CODE_TOKEN_VA(0x403FB3u);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->esi = lift_load32(cpu->eax + 0x10u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->esi)) goto label_00003FC0;
    cpu->esi = cpu->ecx;
    label_00003FC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x403FC0u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebp)) goto label_00003FC8;
    cpu->ecx = cpu->ebp;
    label_00003FC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x403FC8u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) < (uint32_t)(0x10u)) goto label_00003FD1;
    cpu->eax = lift_load32(cpu->eax);
    label_00003FD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x403FD1u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x403FD9u); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00003FEB;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebp)) goto label_00003FED;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_00003FEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x403FEBu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00003FF7;
    label_00003FED: cpu->eip = LIFT_CODE_TOKEN_VA(0x403FEDu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    goto label_00003FFB;
    label_00003FF7: cpu->eip = LIFT_CODE_TOKEN_VA(0x403FF7u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    label_00003FFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x403FFBu);
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    label_00004005: cpu->eip = LIFT_CODE_TOKEN_VA(0x404005u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x29u)) == (uint8_t)(0u)) goto label_00003F40;
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    label_0000401B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40401Bu);
    if ((uint8_t)(lift_load8(cpu->edx + 0x29u)) == (uint8_t)(0u)) goto label_00004029;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ebx = lift_load32(cpu->eax + 4u);
    goto label_0000402B;
    label_00004029: cpu->eip = LIFT_CODE_TOKEN_VA(0x404029u);
    cpu->ebx = lift_load32(cpu->edx);
    label_0000402B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40402Bu);
    if ((uint8_t)(lift_load8(cpu->ebx + 0x29u)) != (uint8_t)(0u)) goto label_0000408E;
    cpu->ebp = lift_load32(cpu->esp + 0x30u);
    label_00004035: cpu->eip = LIFT_CODE_TOKEN_VA(0x404035u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x20u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_load32(cpu->ebx + 0x1Cu);
    cpu->eax = (uint32_t)(cpu->ebx + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00004043;
    cpu->eax = lift_load32(cpu->eax);
    label_00004043: cpu->eip = LIFT_CODE_TOKEN_VA(0x404043u);
    cpu->esi = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->edi)) goto label_00004050;
    cpu->edx = cpu->edi;
    label_00004050: cpu->eip = LIFT_CODE_TOKEN_VA(0x404050u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) < (uint32_t)(0x10u)) goto label_0000405B;
    cpu->ecx = lift_load32(cpu->ebp);
    goto label_0000405D;
    label_0000405B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40405Bu);
    cpu->ecx = cpu->ebp;
    label_0000405D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40405Du);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x404065u); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00004077;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->edi)) goto label_00004079;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_00004077: cpu->eip = LIFT_CODE_TOKEN_VA(0x404077u);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00004081;
    label_00004079: cpu->eip = LIFT_CODE_TOKEN_VA(0x404079u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ebx);
    goto label_00004084;
    label_00004081: cpu->eip = LIFT_CODE_TOKEN_VA(0x404081u);
    cpu->ebx = lift_load32(cpu->ebx + 8u);
    label_00004084: cpu->eip = LIFT_CODE_TOKEN_VA(0x404084u);
    if ((uint8_t)(lift_load8(cpu->ebx + 0x29u)) == (uint8_t)(0u)) goto label_00004035;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    label_0000408E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40408Eu);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004040B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4040B0u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x29u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 4u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000412D;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = lift_load32(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000040D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4040D0u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->edi + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000040DE;
    cpu->edx = lift_load32(cpu->ebp);
    goto label_000040E0;
    label_000040DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4040DEu);
    cpu->edx = cpu->ebp;
    label_000040E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4040E0u);
    cpu->esi = lift_load32(cpu->eax + 0x10u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->esi)) goto label_000040E9;
    label_000040E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4040E9u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebx)) goto label_000040F1;
    cpu->ecx = cpu->ebx;
    label_000040F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4040F1u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000040F9;
    cpu->eax = lift_load32(cpu->eax);
    label_000040F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4040F9u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x404101u); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00004113;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebx)) goto label_00004115;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_00004113: cpu->eip = LIFT_CODE_TOKEN_VA(0x404113u);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0000411A;
    label_00004115: cpu->eip = LIFT_CODE_TOKEN_VA(0x404115u);
    cpu->edi = lift_load32(cpu->edi + 8u);
    goto label_00004120;
    label_0000411A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40411Au);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->edi = lift_load32(cpu->edi);
    label_00004120: cpu->eip = LIFT_CODE_TOKEN_VA(0x404120u);
    if ((uint8_t)(lift_load8(cpu->edi + 0x29u)) == (uint8_t)(0u)) goto label_000040D0;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0000412D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40412Du);
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00404140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x404140u);
    cpu->edx = lift_load32(cpu->ecx + 0x10u);
    cpu->eax = lift_load32(cpu->edx);
    lift_store32(cpu->ecx + 0x1Cu, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_00004169;
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->esi + cpu->edx, cpu->eax);
    lift_store8(cpu->ecx + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00004169: cpu->eip = LIFT_CODE_TOKEN_VA(0x404169u);
    lift_store8(cpu->ecx + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00404180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x404180u);
    if ((uint8_t)(lift_load8(cpu->ecx + 8u)) == (uint8_t)(0u)) goto label_000041B6;
    cpu->eax = lift_load32(cpu->ecx + 0x1Cu);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = cpu->edx;
    lift_store32(cpu->ecx + 0x1Cu, cpu->edx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ecx + 0x10u))) goto label_000041B2;
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->esi + cpu->edx, cpu->eax);
    lift_store8(cpu->ecx + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000041B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4041B2u);
    lift_store8(cpu->ecx + 8u, 0u);
    label_000041B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4041B6u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004041C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4041C0u);
    cpu->edx = lift_load32(cpu->ecx + 0x10u);
    cpu->eax = lift_load32(cpu->edx);
    lift_store32(cpu->ecx + 0x1Cu, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_000041E6;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->edx);
    lift_store_f32(cpu->eax + cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store8(cpu->ecx + 8u, 1u);
    cpu->eax = 0u;
    lift_return(cpu, 4u, stop_address); return;
    label_000041E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4041E6u);
    lift_store8(cpu->ecx + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004041F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4041F0u);
    if ((uint8_t)(lift_load8(cpu->ecx + 8u)) == (uint8_t)(0u)) goto label_00004223;
    cpu->eax = lift_load32(cpu->ecx + 0x1Cu);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = cpu->edx;
    lift_store32(cpu->ecx + 0x1Cu, cpu->edx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ecx + 0x10u))) goto label_0000421F;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->edx);
    lift_store_f32(cpu->eax + cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store8(cpu->ecx + 8u, 1u);
    cpu->eax = 0u;
    lift_return(cpu, 4u, stop_address); return;
    label_0000421F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40421Fu);
    lift_store8(cpu->ecx + 8u, 0u);
    label_00004223: cpu->eip = LIFT_CODE_TOKEN_VA(0x404223u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00404230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x404230u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) == (uint8_t)(0u)) goto label_00004262;
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esi + 0x1Cu, cpu->ecx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_0000425E;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x404254u); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0000425E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40425Eu);
    lift_store8(cpu->esi + 8u, 0u);
    label_00004262: cpu->eip = LIFT_CODE_TOKEN_VA(0x404262u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00404270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x404270u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) == (uint8_t)(0u)) goto label_000042A2;
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esi + 0x1Cu, cpu->ecx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_0000429E;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x404294u); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0000429E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40429Eu);
    lift_store8(cpu->esi + 8u, 0u);
    label_000042A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4042A2u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004042B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4042B0u);
    if ((uint8_t)(lift_load8(cpu->ecx + 8u)) == (uint8_t)(0u)) goto label_000042E2;
    lift_store32(cpu->ecx + 0x20u, (uint64_t)(lift_load32(cpu->ecx + 0x20u)) + (uint64_t)(4u) + (uint64_t)(0u));
    cpu->eax = lift_load32(cpu->ecx + 0x20u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ecx + 0x14u))) goto label_000042DE;
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->esi + cpu->edx, cpu->eax);
    lift_store8(cpu->ecx + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000042DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4042DEu);
    lift_store8(cpu->ecx + 8u, 0u);
    label_000042E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4042E2u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004042F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4042F0u);
    if ((uint8_t)(lift_load8(cpu->ecx + 8u)) == (uint8_t)(0u)) goto label_0000431F;
    lift_store32(cpu->ecx + 0x20u, (uint64_t)(lift_load32(cpu->ecx + 0x20u)) + (uint64_t)(4u) + (uint64_t)(0u));
    cpu->eax = lift_load32(cpu->ecx + 0x20u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ecx + 0x14u))) goto label_0000431B;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->edx);
    lift_store_f32(cpu->eax + cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store8(cpu->ecx + 8u, 1u);
    cpu->eax = 0u;
    lift_return(cpu, 4u, stop_address); return;
    label_0000431B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40431Bu);
    lift_store8(cpu->ecx + 8u, 0u);
    label_0000431F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40431Fu);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00404330(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x404330u);
    if ((uint8_t)(lift_load8(cpu->ecx + 8u)) == (uint8_t)(0u)) goto label_00004367;
    cpu->edx = 1u;
    lift_store32(cpu->ecx + 0x20u, (uint64_t)(lift_load32(cpu->ecx + 0x20u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    cpu->eax = lift_load32(cpu->ecx + 0x20u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ecx + 0x14u))) goto label_00004363;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    cpu->esi = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->edi);
    cpu->edi = g_sfera_mbc_runtime->process_memory_base;
    lift_store8(cpu->edi + cpu->esi, cpu->eax & 0xFFu);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->ecx + 8u, cpu->edx & 0xFFu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00004363: cpu->eip = LIFT_CODE_TOKEN_VA(0x404363u);
    lift_store8(cpu->ecx + 8u, 0u);
    label_00004367: cpu->eip = LIFT_CODE_TOKEN_VA(0x404367u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00404370(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x404370u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) == (uint8_t)(0u)) goto label_0000439C;
    lift_store32(cpu->esi + 0x20u, (uint64_t)(lift_load32(cpu->esi + 0x20u)) + (uint64_t)(0x1Cu) + (uint64_t)(0u));
    cpu->edx = lift_load32(cpu->esi + 0x20u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(lift_load32(cpu->esi + 0x14u))) goto label_00004398;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40438Eu); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00004398: cpu->eip = LIFT_CODE_TOKEN_VA(0x404398u);
    lift_store8(cpu->esi + 8u, 0u);
    label_0000439C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40439Cu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004043B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4043B0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) == (uint8_t)(0u)) goto label_000043DC;
    lift_store32(cpu->esi + 0x20u, (uint64_t)(lift_load32(cpu->esi + 0x20u)) + (uint64_t)(8u) + (uint64_t)(0u));
    cpu->edx = lift_load32(cpu->esi + 0x20u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(lift_load32(cpu->esi + 0x14u))) goto label_000043D8;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4043CEu); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000043D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4043D8u);
    lift_store8(cpu->esi + 8u, 0u);
    label_000043DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4043DCu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004043F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4043F0u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x11u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_push32(cpu, cpu->edi);
    lift_store8(cpu->esp + 0x18u, cpu->ecx & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000443D;
    cpu->edx = lift_load32(cpu->ebx + 0xCu);
    label_00004411: cpu->eip = LIFT_CODE_TOKEN_VA(0x404411u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x1Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00004422;
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0xCu)), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_00004428;
    label_00004422: cpu->eip = LIFT_CODE_TOKEN_VA(0x404422u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->eax + 0xCu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u)) ? 1u : 0u) & 0xFFu);
    label_00004428: cpu->eip = LIFT_CODE_TOKEN_VA(0x404428u);
    lift_store8(cpu->esp + 0x18u, cpu->ecx & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_00004434;
    cpu->eax = lift_load32(cpu->eax);
    goto label_00004437;
    label_00004434: cpu->eip = LIFT_CODE_TOKEN_VA(0x404434u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    label_00004437: cpu->eip = LIFT_CODE_TOKEN_VA(0x404437u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x11u)) == (uint8_t)(0u)) goto label_00004411;
    label_0000443D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40443Du);
    cpu->edi = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_0000447A;
    cpu->eax = lift_load32(cpu->ebp + 4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->eax))) goto label_00004471;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40445Eu); lift_push32(cpu, r); sfera_sub_004D2180(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->edx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_00004471: cpu->eip = LIFT_CODE_TOKEN_VA(0x404471u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x404476u); lift_push32(cpu, r); sfera_sub_00402140(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    label_0000447A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40447Au);
    cpu->eax = lift_load32(cpu->edi + 0xCu);
    lift_push32(cpu, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0xCu))) goto label_000044A8;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x404495u); lift_push32(cpu, r); sfera_sub_004D2180(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000044A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4044A8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4044ADu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->esp += 4u;
    lift_store32(cpu->eax, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->eax + 4u, 0u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004044D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4044D0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x15u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebx = cpu->ecx;
    cpu->esi = cpu->edi;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000044FF;
    label_000044E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4044E1u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4044ECu); lift_push32(cpu, r); sfera_sub_004044D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4044F4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x15u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000044E1;
    label_000044FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4044FFu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00404510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x404510u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x15u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00004529;
    lift_push32(cpu, (uint32_t)(uintptr_t)"invalid map/set<T> iterator");
    lift_trap(cpu, cpu->eip, "std::out_of_range");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x4529u);
    label_00004529: cpu->eip = LIFT_CODE_TOKEN_VA(0x404529u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40453Bu); lift_push32(cpu, r); sfera_sub_00402220(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x15u)) == (uint8_t)(0u)) goto label_00004548;
    cpu->edi = lift_load32(cpu->ebx + 8u);
    goto label_00004560;
    label_00004548: cpu->eip = LIFT_CODE_TOKEN_VA(0x404548u);
    cpu->eax = lift_load32(cpu->ebx + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x15u)) == (uint8_t)(0u)) goto label_00004555;
    cpu->edi = cpu->ecx;
    goto label_00004560;
    label_00004555: cpu->eip = LIFT_CODE_TOKEN_VA(0x404555u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_000045C7;
    label_00004560: cpu->eip = LIFT_CODE_TOKEN_VA(0x404560u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x15u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_load32(cpu->ebx + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000456C;
    lift_store32(cpu->edi + 4u, cpu->esi);
    label_0000456C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40456Cu);
    cpu->eax = lift_load32(cpu->ebp + 4u);
    if ((uint32_t)(lift_load32(cpu->eax + 4u)) != (uint32_t)(cpu->ebx)) goto label_00004579;
    lift_store32(cpu->eax + 4u, cpu->edi);
    goto label_00004584;
    label_00004579: cpu->eip = LIFT_CODE_TOKEN_VA(0x404579u);
    if ((uint32_t)(lift_load32(cpu->esi)) != (uint32_t)(cpu->ebx)) goto label_00004581;
    lift_store32(cpu->esi, cpu->edi);
    goto label_00004584;
    label_00004581: cpu->eip = LIFT_CODE_TOKEN_VA(0x404581u);
    lift_store32(cpu->esi + 8u, cpu->edi);
    label_00004584: cpu->eip = LIFT_CODE_TOKEN_VA(0x404584u);
    cpu->ebx = lift_load32(cpu->ebp + 4u);
    cpu->ecx = lift_load32(cpu->ebx);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esp + 0x10u))) goto label_000045A2;
    if ((uint8_t)(lift_load8(cpu->edi + 0x15u)) == (uint8_t)(0u)) goto label_00004599;
    cpu->eax = cpu->esi;
    goto label_000045A0;
    label_00004599: cpu->eip = LIFT_CODE_TOKEN_VA(0x404599u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x45A0u); lift_push32(cpu, r); sfera_sub_004022B0(cpu,r); if (cpu->eip != r) return; }
    label_000045A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4045A0u);
    lift_store32(cpu->ebx, cpu->eax);
    label_000045A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4045A2u);
    cpu->ebx = lift_load32(cpu->ebp + 4u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(lift_load32(cpu->ebx + 8u)) != (uint32_t)(cpu->edx)) goto label_0000461E;
    if ((uint8_t)(lift_load8(cpu->edi + 0x15u)) == (uint8_t)(0u)) goto label_000045BB;
    cpu->eax = cpu->esi;
    lift_store32(cpu->ebx + 8u, cpu->eax);
    goto label_0000461E;
    label_000045BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4045BBu);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4045C2u); lift_push32(cpu, r); sfera_sub_00402200(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 8u, cpu->eax);
    goto label_0000461E;
    label_000045C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4045C7u);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebx);
    lift_store32(cpu->eax, cpu->ecx);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->ebx + 8u))) goto label_000045D7;
    cpu->esi = cpu->eax;
    goto label_000045F1;
    label_000045D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4045D7u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x15u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000045E3;
    lift_store32(cpu->edi + 4u, cpu->esi);
    label_000045E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4045E3u);
    lift_store32(cpu->esi, cpu->edi);
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebx + 8u);
    lift_store32(cpu->edx + 4u, cpu->eax);
    label_000045F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4045F1u);
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx + 4u)) != (uint32_t)(cpu->ebx)) goto label_000045FE;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    goto label_0000460C;
    label_000045FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4045FEu);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(cpu->ebx)) goto label_00004609;
    lift_store32(cpu->ecx, cpu->eax);
    goto label_0000460C;
    label_00004609: cpu->eip = LIFT_CODE_TOKEN_VA(0x404609u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    label_0000460C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40460Cu);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebx + 0x14u)) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 0x14u)) & 0xFFu);
    lift_store8(cpu->eax + 0x14u, cpu->edx & 0xFFu);
    lift_store8(cpu->ebx + 0x14u, cpu->ecx & 0xFFu);
    label_0000461E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40461Eu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x14u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00004726;
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_00004723;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00004640: cpu->eip = LIFT_CODE_TOKEN_VA(0x404640u);
    if ((uint8_t)(lift_load8(cpu->edi + 0x14u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00004723;
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->eax)) goto label_000046B2;
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x14u)) != (uint8_t)(0u)) goto label_0000466A;
    lift_store8(cpu->eax + 0x14u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->esi + 0x14u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x404667u); lift_push32(cpu, r); sfera_sub_00402DB0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    label_0000466A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40466Au);
    if ((uint8_t)(lift_load8(cpu->eax + 0x15u)) != (uint8_t)(0u)) goto label_000046E2;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x14u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000467F;
    cpu->ecx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x14u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000046DE;
    label_0000467F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40467Fu);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x14u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00004699;
    lift_store8(cpu->edx + 0x14u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->eax + 0x14u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x404696u); lift_push32(cpu, r); sfera_sub_00402E00(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    label_00004699: cpu->eip = LIFT_CODE_TOKEN_VA(0x404699u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x14u)) & 0xFFu);
    lift_store8(cpu->eax + 0x14u, cpu->ecx & 0xFFu);
    lift_store8(cpu->esi + 0x14u, cpu->ebx & 0xFFu);
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->edx + 0x14u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4046B0u); lift_push32(cpu, r); sfera_sub_00402DB0(cpu,r); if (cpu->eip != r) return; }
    goto label_00004723;
    label_000046B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4046B2u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x14u)) != (uint8_t)(0u)) goto label_000046C9;
    lift_store8(cpu->eax + 0x14u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->esi + 0x14u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4046C7u); lift_push32(cpu, r); sfera_sub_00402E00(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    label_000046C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4046C9u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x15u)) != (uint8_t)(0u)) goto label_000046E2;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x14u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000046F5;
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x14u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000046F5;
    label_000046DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4046DEu);
    lift_store8(cpu->eax + 0x14u, 0u);
    label_000046E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4046E2u);
    cpu->edx = lift_load32(cpu->ebp + 4u);
    cpu->edi = cpu->esi;
    cpu->esi = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->edx + 4u))) goto label_00004640;
    goto label_00004723;
    label_000046F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4046F5u);
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x14u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000470D;
    lift_store8(cpu->edx + 0x14u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->eax + 0x14u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40470Bu); lift_push32(cpu, r); sfera_sub_00402DB0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    label_0000470D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40470Du);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x14u)) & 0xFFu);
    lift_store8(cpu->eax + 0x14u, cpu->ecx & 0xFFu);
    lift_store8(cpu->esi + 0x14u, cpu->ebx & 0xFFu);
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->edx + 0x14u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x4723u); lift_push32(cpu, r); sfera_sub_00402E00(cpu,r); if (cpu->eip != r) return; }
    label_00004723: cpu->eip = LIFT_CODE_TOKEN_VA(0x404723u);
    lift_store8(cpu->edi + 0x14u, cpu->ebx & 0xFFu);
    label_00004726: cpu->eip = LIFT_CODE_TOKEN_VA(0x404726u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x404730u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00004741;
    --cpu->eax;
    lift_store32(cpu->ebp + 8u, cpu->eax);
    label_00004741: cpu->eip = LIFT_CODE_TOKEN_VA(0x404741u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00404750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x404750u);
    cpu->esp -= 0x18u;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x2Du)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edx = cpu->eax;
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000486B;
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    cpu->ecx = lift_load32(cpu->edx + 0x10u);
    cpu->eax = lift_load32(cpu->edx + 0x14u);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    goto label_0000479C;
    label_00004790: cpu->eip = LIFT_CODE_TOKEN_VA(0x404790u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    label_0000479C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40479Cu);
    cpu->edi += 0xCu;
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) < (uint32_t)(0x10u)) goto label_000047A8;
    cpu->edx = lift_load32(cpu->edx);
    label_000047A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4047A8u);
    cpu->esi = lift_load32(cpu->edi + 0x10u);
    cpu->ebp = cpu->esi;
    if ((uint32_t)(cpu->ebp) >= (uint32_t)(cpu->esi)) goto label_000047B1;
    label_000047B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4047B1u);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->ecx)) goto label_000047B7;
    cpu->ecx = cpu->esi;
    label_000047B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4047B7u);
    cpu->ebx = lift_load32(cpu->edi + 0x14u);
    if ((uint32_t)(cpu->ebx) < (uint32_t)(0x10u)) goto label_000047C3;
    cpu->eax = lift_load32(cpu->edi);
    goto label_000047C5;
    label_000047C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4047C3u);
    cpu->eax = cpu->edi;
    label_000047C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4047C5u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4047CDu); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000047E3;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ecx)) goto label_000047E5;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_000047E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4047E3u);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000047F2;
    label_000047E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4047E5u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    goto label_00004855;
    label_000047F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4047F2u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) == (uint8_t)(0u)) goto label_00004847;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(0x10u)) goto label_00004803;
    cpu->edi = lift_load32(cpu->edi);
    label_00004803: cpu->eip = LIFT_CODE_TOKEN_VA(0x404803u);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->esi = lift_load32(cpu->eax + 0x10u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->esi)) goto label_00004810;
    cpu->esi = cpu->ecx;
    label_00004810: cpu->eip = LIFT_CODE_TOKEN_VA(0x404810u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebp)) goto label_00004818;
    cpu->ecx = cpu->ebp;
    label_00004818: cpu->eip = LIFT_CODE_TOKEN_VA(0x404818u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) < (uint32_t)(0x10u)) goto label_00004821;
    cpu->eax = lift_load32(cpu->eax);
    label_00004821: cpu->eip = LIFT_CODE_TOKEN_VA(0x404821u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x404829u); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000483B;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebp)) goto label_0000483D;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_0000483B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40483Bu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00004847;
    label_0000483D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40483Du);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    goto label_0000484B;
    label_00004847: cpu->eip = LIFT_CODE_TOKEN_VA(0x404847u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    label_0000484B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40484Bu);
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    label_00004855: cpu->eip = LIFT_CODE_TOKEN_VA(0x404855u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Du)) == (uint8_t)(0u)) goto label_00004790;
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    label_0000486B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40486Bu);
    if ((uint8_t)(lift_load8(cpu->edx + 0x2Du)) == (uint8_t)(0u)) goto label_00004879;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ebx = lift_load32(cpu->eax + 4u);
    goto label_0000487B;
    label_00004879: cpu->eip = LIFT_CODE_TOKEN_VA(0x404879u);
    cpu->ebx = lift_load32(cpu->edx);
    label_0000487B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40487Bu);
    if ((uint8_t)(lift_load8(cpu->ebx + 0x2Du)) != (uint8_t)(0u)) goto label_000048DE;
    cpu->ebp = lift_load32(cpu->esp + 0x30u);
    label_00004885: cpu->eip = LIFT_CODE_TOKEN_VA(0x404885u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x20u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_load32(cpu->ebx + 0x1Cu);
    cpu->eax = (uint32_t)(cpu->ebx + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00004893;
    cpu->eax = lift_load32(cpu->eax);
    label_00004893: cpu->eip = LIFT_CODE_TOKEN_VA(0x404893u);
    cpu->esi = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->edi)) goto label_000048A0;
    cpu->edx = cpu->edi;
    label_000048A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4048A0u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) < (uint32_t)(0x10u)) goto label_000048AB;
    cpu->ecx = lift_load32(cpu->ebp);
    goto label_000048AD;
    label_000048AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4048ABu);
    cpu->ecx = cpu->ebp;
    label_000048AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4048ADu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4048B5u); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000048C7;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->edi)) goto label_000048C9;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_000048C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4048C7u);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000048D1;
    label_000048C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4048C9u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ebx);
    goto label_000048D4;
    label_000048D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4048D1u);
    cpu->ebx = lift_load32(cpu->ebx + 8u);
    label_000048D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4048D4u);
    if ((uint8_t)(lift_load8(cpu->ebx + 0x2Du)) == (uint8_t)(0u)) goto label_00004885;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    label_000048DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4048DEu);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00404900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x404900u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x2Du)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 4u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000497D;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = lift_load32(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00004920: cpu->eip = LIFT_CODE_TOKEN_VA(0x404920u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->edi + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0000492E;
    cpu->edx = lift_load32(cpu->ebp);
    goto label_00004930;
    label_0000492E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40492Eu);
    cpu->edx = cpu->ebp;
    label_00004930: cpu->eip = LIFT_CODE_TOKEN_VA(0x404930u);
    cpu->esi = lift_load32(cpu->eax + 0x10u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->esi)) goto label_00004939;
    label_00004939: cpu->eip = LIFT_CODE_TOKEN_VA(0x404939u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebx)) goto label_00004941;
    cpu->ecx = cpu->ebx;
    label_00004941: cpu->eip = LIFT_CODE_TOKEN_VA(0x404941u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_00004949;
    cpu->eax = lift_load32(cpu->eax);
    label_00004949: cpu->eip = LIFT_CODE_TOKEN_VA(0x404949u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x404951u); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00004963;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebx)) goto label_00004965;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_00004963: cpu->eip = LIFT_CODE_TOKEN_VA(0x404963u);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0000496A;
    label_00004965: cpu->eip = LIFT_CODE_TOKEN_VA(0x404965u);
    cpu->edi = lift_load32(cpu->edi + 8u);
    goto label_00004970;
    label_0000496A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40496Au);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->edi = lift_load32(cpu->edi);
    label_00004970: cpu->eip = LIFT_CODE_TOKEN_VA(0x404970u);
    if ((uint8_t)(lift_load8(cpu->edi + 0x2Du)) == (uint8_t)(0u)) goto label_00004920;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0000497D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40497Du);
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00404990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x404990u);
    cpu->esp -= 0x18u;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x45u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edx = cpu->eax;
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00004AAB;
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    cpu->ecx = lift_load32(cpu->edx + 0x10u);
    cpu->eax = lift_load32(cpu->edx + 0x14u);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    goto label_000049DC;
    label_000049D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4049D0u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    label_000049DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4049DCu);
    cpu->edi += 0xCu;
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) < (uint32_t)(0x10u)) goto label_000049E8;
    cpu->edx = lift_load32(cpu->edx);
    label_000049E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4049E8u);
    cpu->esi = lift_load32(cpu->edi + 0x10u);
    cpu->ebp = cpu->esi;
    if ((uint32_t)(cpu->ebp) >= (uint32_t)(cpu->esi)) goto label_000049F1;
    label_000049F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4049F1u);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->ecx)) goto label_000049F7;
    cpu->ecx = cpu->esi;
    label_000049F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4049F7u);
    cpu->ebx = lift_load32(cpu->edi + 0x14u);
    if ((uint32_t)(cpu->ebx) < (uint32_t)(0x10u)) goto label_00004A03;
    cpu->eax = lift_load32(cpu->edi);
    goto label_00004A05;
    label_00004A03: cpu->eip = LIFT_CODE_TOKEN_VA(0x404A03u);
    cpu->eax = cpu->edi;
    label_00004A05: cpu->eip = LIFT_CODE_TOKEN_VA(0x404A05u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x404A0Du); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00004A23;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ecx)) goto label_00004A25;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_00004A23: cpu->eip = LIFT_CODE_TOKEN_VA(0x404A23u);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00004A32;
    label_00004A25: cpu->eip = LIFT_CODE_TOKEN_VA(0x404A25u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    goto label_00004A95;
    label_00004A32: cpu->eip = LIFT_CODE_TOKEN_VA(0x404A32u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x45u)) == (uint8_t)(0u)) goto label_00004A87;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(0x10u)) goto label_00004A43;
    cpu->edi = lift_load32(cpu->edi);
    label_00004A43: cpu->eip = LIFT_CODE_TOKEN_VA(0x404A43u);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->esi = lift_load32(cpu->eax + 0x10u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->esi)) goto label_00004A50;
    cpu->esi = cpu->ecx;
    label_00004A50: cpu->eip = LIFT_CODE_TOKEN_VA(0x404A50u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebp)) goto label_00004A58;
    cpu->ecx = cpu->ebp;
    label_00004A58: cpu->eip = LIFT_CODE_TOKEN_VA(0x404A58u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) < (uint32_t)(0x10u)) goto label_00004A61;
    cpu->eax = lift_load32(cpu->eax);
    label_00004A61: cpu->eip = LIFT_CODE_TOKEN_VA(0x404A61u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x404A69u); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00004A7B;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebp)) goto label_00004A7D;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_00004A7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x404A7Bu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00004A87;
    label_00004A7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x404A7Du);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    goto label_00004A8B;
    label_00004A87: cpu->eip = LIFT_CODE_TOKEN_VA(0x404A87u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    label_00004A8B: cpu->eip = LIFT_CODE_TOKEN_VA(0x404A8Bu);
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    label_00004A95: cpu->eip = LIFT_CODE_TOKEN_VA(0x404A95u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x45u)) == (uint8_t)(0u)) goto label_000049D0;
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    label_00004AAB: cpu->eip = LIFT_CODE_TOKEN_VA(0x404AABu);
    if ((uint8_t)(lift_load8(cpu->edx + 0x45u)) == (uint8_t)(0u)) goto label_00004AB9;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ebx = lift_load32(cpu->eax + 4u);
    goto label_00004ABB;
    label_00004AB9: cpu->eip = LIFT_CODE_TOKEN_VA(0x404AB9u);
    cpu->ebx = lift_load32(cpu->edx);
    label_00004ABB: cpu->eip = LIFT_CODE_TOKEN_VA(0x404ABBu);
    if ((uint8_t)(lift_load8(cpu->ebx + 0x45u)) != (uint8_t)(0u)) goto label_00004B1E;
    cpu->ebp = lift_load32(cpu->esp + 0x30u);
    label_00004AC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x404AC5u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x20u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_load32(cpu->ebx + 0x1Cu);
    cpu->eax = (uint32_t)(cpu->ebx + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00004AD3;
    cpu->eax = lift_load32(cpu->eax);
    label_00004AD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x404AD3u);
    cpu->esi = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->edi)) goto label_00004AE0;
    cpu->edx = cpu->edi;
    label_00004AE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x404AE0u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) < (uint32_t)(0x10u)) goto label_00004AEB;
    cpu->ecx = lift_load32(cpu->ebp);
    goto label_00004AED;
    label_00004AEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x404AEBu);
    cpu->ecx = cpu->ebp;
    label_00004AED: cpu->eip = LIFT_CODE_TOKEN_VA(0x404AEDu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x404AF5u); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00004B07;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->edi)) goto label_00004B09;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_00004B07: cpu->eip = LIFT_CODE_TOKEN_VA(0x404B07u);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00004B11;
    label_00004B09: cpu->eip = LIFT_CODE_TOKEN_VA(0x404B09u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ebx);
    goto label_00004B14;
    label_00004B11: cpu->eip = LIFT_CODE_TOKEN_VA(0x404B11u);
    cpu->ebx = lift_load32(cpu->ebx + 8u);
    label_00004B14: cpu->eip = LIFT_CODE_TOKEN_VA(0x404B14u);
    if ((uint8_t)(lift_load8(cpu->ebx + 0x45u)) == (uint8_t)(0u)) goto label_00004AC5;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    label_00004B1E: cpu->eip = LIFT_CODE_TOKEN_VA(0x404B1Eu);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00404B40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x404B40u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x45u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 4u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00004BBD;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = lift_load32(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00004B60: cpu->eip = LIFT_CODE_TOKEN_VA(0x404B60u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->edi + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00004B6E;
    cpu->edx = lift_load32(cpu->ebp);
    goto label_00004B70;
    label_00004B6E: cpu->eip = LIFT_CODE_TOKEN_VA(0x404B6Eu);
    cpu->edx = cpu->ebp;
    label_00004B70: cpu->eip = LIFT_CODE_TOKEN_VA(0x404B70u);
    cpu->esi = lift_load32(cpu->eax + 0x10u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->esi)) goto label_00004B79;
    label_00004B79: cpu->eip = LIFT_CODE_TOKEN_VA(0x404B79u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebx)) goto label_00004B81;
    cpu->ecx = cpu->ebx;
    label_00004B81: cpu->eip = LIFT_CODE_TOKEN_VA(0x404B81u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_00004B89;
    cpu->eax = lift_load32(cpu->eax);
    label_00004B89: cpu->eip = LIFT_CODE_TOKEN_VA(0x404B89u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x404B91u); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00004BA3;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebx)) goto label_00004BA5;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_00004BA3: cpu->eip = LIFT_CODE_TOKEN_VA(0x404BA3u);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00004BAA;
    label_00004BA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x404BA5u);
    cpu->edi = lift_load32(cpu->edi + 8u);
    goto label_00004BB0;
    label_00004BAA: cpu->eip = LIFT_CODE_TOKEN_VA(0x404BAAu);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->edi = lift_load32(cpu->edi);
    label_00004BB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x404BB0u);
    if ((uint8_t)(lift_load8(cpu->edi + 0x45u)) == (uint8_t)(0u)) goto label_00004B60;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00004BBD: cpu->eip = LIFT_CODE_TOKEN_VA(0x404BBDu);
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00404BD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x404BD0u);
    cpu->esp -= 0x18u;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x31u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edx = cpu->eax;
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00004CEB;
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    cpu->ecx = lift_load32(cpu->edx + 0x10u);
    cpu->eax = lift_load32(cpu->edx + 0x14u);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    goto label_00004C1C;
    label_00004C10: cpu->eip = LIFT_CODE_TOKEN_VA(0x404C10u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    label_00004C1C: cpu->eip = LIFT_CODE_TOKEN_VA(0x404C1Cu);
    cpu->edi += 0xCu;
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) < (uint32_t)(0x10u)) goto label_00004C28;
    cpu->edx = lift_load32(cpu->edx);
    label_00004C28: cpu->eip = LIFT_CODE_TOKEN_VA(0x404C28u);
    cpu->esi = lift_load32(cpu->edi + 0x10u);
    cpu->ebp = cpu->esi;
    if ((uint32_t)(cpu->ebp) >= (uint32_t)(cpu->esi)) goto label_00004C31;
    label_00004C31: cpu->eip = LIFT_CODE_TOKEN_VA(0x404C31u);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->ecx)) goto label_00004C37;
    cpu->ecx = cpu->esi;
    label_00004C37: cpu->eip = LIFT_CODE_TOKEN_VA(0x404C37u);
    cpu->ebx = lift_load32(cpu->edi + 0x14u);
    if ((uint32_t)(cpu->ebx) < (uint32_t)(0x10u)) goto label_00004C43;
    cpu->eax = lift_load32(cpu->edi);
    goto label_00004C45;
    label_00004C43: cpu->eip = LIFT_CODE_TOKEN_VA(0x404C43u);
    cpu->eax = cpu->edi;
    label_00004C45: cpu->eip = LIFT_CODE_TOKEN_VA(0x404C45u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x404C4Du); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00004C63;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ecx)) goto label_00004C65;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_00004C63: cpu->eip = LIFT_CODE_TOKEN_VA(0x404C63u);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00004C72;
    label_00004C65: cpu->eip = LIFT_CODE_TOKEN_VA(0x404C65u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    goto label_00004CD5;
    label_00004C72: cpu->eip = LIFT_CODE_TOKEN_VA(0x404C72u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x31u)) == (uint8_t)(0u)) goto label_00004CC7;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(0x10u)) goto label_00004C83;
    cpu->edi = lift_load32(cpu->edi);
    label_00004C83: cpu->eip = LIFT_CODE_TOKEN_VA(0x404C83u);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->esi = lift_load32(cpu->eax + 0x10u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->esi)) goto label_00004C90;
    cpu->esi = cpu->ecx;
    label_00004C90: cpu->eip = LIFT_CODE_TOKEN_VA(0x404C90u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebp)) goto label_00004C98;
    cpu->ecx = cpu->ebp;
    label_00004C98: cpu->eip = LIFT_CODE_TOKEN_VA(0x404C98u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) < (uint32_t)(0x10u)) goto label_00004CA1;
    cpu->eax = lift_load32(cpu->eax);
    label_00004CA1: cpu->eip = LIFT_CODE_TOKEN_VA(0x404CA1u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x404CA9u); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00004CBB;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebp)) goto label_00004CBD;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_00004CBB: cpu->eip = LIFT_CODE_TOKEN_VA(0x404CBBu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00004CC7;
    label_00004CBD: cpu->eip = LIFT_CODE_TOKEN_VA(0x404CBDu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    goto label_00004CCB;
    label_00004CC7: cpu->eip = LIFT_CODE_TOKEN_VA(0x404CC7u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    label_00004CCB: cpu->eip = LIFT_CODE_TOKEN_VA(0x404CCBu);
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    label_00004CD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x404CD5u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x31u)) == (uint8_t)(0u)) goto label_00004C10;
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    label_00004CEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x404CEBu);
    if ((uint8_t)(lift_load8(cpu->edx + 0x31u)) == (uint8_t)(0u)) goto label_00004CF9;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ebx = lift_load32(cpu->eax + 4u);
    goto label_00004CFB;
    label_00004CF9: cpu->eip = LIFT_CODE_TOKEN_VA(0x404CF9u);
    cpu->ebx = lift_load32(cpu->edx);
    label_00004CFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x404CFBu);
    if ((uint8_t)(lift_load8(cpu->ebx + 0x31u)) != (uint8_t)(0u)) goto label_00004D5E;
    cpu->ebp = lift_load32(cpu->esp + 0x30u);
    label_00004D05: cpu->eip = LIFT_CODE_TOKEN_VA(0x404D05u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x20u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_load32(cpu->ebx + 0x1Cu);
    cpu->eax = (uint32_t)(cpu->ebx + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00004D13;
    cpu->eax = lift_load32(cpu->eax);
    label_00004D13: cpu->eip = LIFT_CODE_TOKEN_VA(0x404D13u);
    cpu->esi = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->edi)) goto label_00004D20;
    cpu->edx = cpu->edi;
    label_00004D20: cpu->eip = LIFT_CODE_TOKEN_VA(0x404D20u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) < (uint32_t)(0x10u)) goto label_00004D2B;
    cpu->ecx = lift_load32(cpu->ebp);
    goto label_00004D2D;
    label_00004D2B: cpu->eip = LIFT_CODE_TOKEN_VA(0x404D2Bu);
    cpu->ecx = cpu->ebp;
    label_00004D2D: cpu->eip = LIFT_CODE_TOKEN_VA(0x404D2Du);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x404D35u); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00004D47;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->edi)) goto label_00004D49;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_00004D47: cpu->eip = LIFT_CODE_TOKEN_VA(0x404D47u);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00004D51;
    label_00004D49: cpu->eip = LIFT_CODE_TOKEN_VA(0x404D49u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ebx);
    goto label_00004D54;
    label_00004D51: cpu->eip = LIFT_CODE_TOKEN_VA(0x404D51u);
    cpu->ebx = lift_load32(cpu->ebx + 8u);
    label_00004D54: cpu->eip = LIFT_CODE_TOKEN_VA(0x404D54u);
    if ((uint8_t)(lift_load8(cpu->ebx + 0x31u)) == (uint8_t)(0u)) goto label_00004D05;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    label_00004D5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x404D5Eu);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00404D80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x404D80u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x31u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 4u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00004DFD;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = lift_load32(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00004DA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x404DA0u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->edi + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00004DAE;
    cpu->edx = lift_load32(cpu->ebp);
    goto label_00004DB0;
    label_00004DAE: cpu->eip = LIFT_CODE_TOKEN_VA(0x404DAEu);
    cpu->edx = cpu->ebp;
    label_00004DB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x404DB0u);
    cpu->esi = lift_load32(cpu->eax + 0x10u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->esi)) goto label_00004DB9;
    label_00004DB9: cpu->eip = LIFT_CODE_TOKEN_VA(0x404DB9u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebx)) goto label_00004DC1;
    cpu->ecx = cpu->ebx;
    label_00004DC1: cpu->eip = LIFT_CODE_TOKEN_VA(0x404DC1u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_00004DC9;
    cpu->eax = lift_load32(cpu->eax);
    label_00004DC9: cpu->eip = LIFT_CODE_TOKEN_VA(0x404DC9u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x404DD1u); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00004DE3;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebx)) goto label_00004DE5;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_00004DE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x404DE3u);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00004DEA;
    label_00004DE5: cpu->eip = LIFT_CODE_TOKEN_VA(0x404DE5u);
    cpu->edi = lift_load32(cpu->edi + 8u);
    goto label_00004DF0;
    label_00004DEA: cpu->eip = LIFT_CODE_TOKEN_VA(0x404DEAu);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->edi = lift_load32(cpu->edi);
    label_00004DF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x404DF0u);
    if ((uint8_t)(lift_load8(cpu->edi + 0x31u)) == (uint8_t)(0u)) goto label_00004DA0;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00004DFD: cpu->eip = LIFT_CODE_TOKEN_VA(0x404DFDu);
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00404E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x404E10u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x15u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_push32(cpu, cpu->edi);
    lift_store8(cpu->esp + 0x18u, cpu->ecx & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00004E5D;
    cpu->edx = lift_load32(cpu->ebx + 0xCu);
    label_00004E31: cpu->eip = LIFT_CODE_TOKEN_VA(0x404E31u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x1Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00004E42;
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0xCu)), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_00004E48;
    label_00004E42: cpu->eip = LIFT_CODE_TOKEN_VA(0x404E42u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->eax + 0xCu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u)) ? 1u : 0u) & 0xFFu);
    label_00004E48: cpu->eip = LIFT_CODE_TOKEN_VA(0x404E48u);
    lift_store8(cpu->esp + 0x18u, cpu->ecx & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_00004E54;
    cpu->eax = lift_load32(cpu->eax);
    goto label_00004E57;
    label_00004E54: cpu->eip = LIFT_CODE_TOKEN_VA(0x404E54u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    label_00004E57: cpu->eip = LIFT_CODE_TOKEN_VA(0x404E57u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x15u)) == (uint8_t)(0u)) goto label_00004E31;
    label_00004E5D: cpu->eip = LIFT_CODE_TOKEN_VA(0x404E5Du);
    cpu->edi = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_00004E9A;
    cpu->eax = lift_load32(cpu->ebp + 4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->eax))) goto label_00004E91;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x404E7Eu); lift_push32(cpu, r); sfera_sub_004037A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->edx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_00004E91: cpu->eip = LIFT_CODE_TOKEN_VA(0x404E91u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x404E96u); lift_push32(cpu, r); sfera_sub_004025A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    label_00004E9A: cpu->eip = LIFT_CODE_TOKEN_VA(0x404E9Au);
    cpu->eax = lift_load32(cpu->edi + 0xCu);
    lift_push32(cpu, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0xCu))) goto label_00004EC8;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x404EB5u); lift_push32(cpu, r); sfera_sub_004037A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_00004EC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x404EC8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x404ECDu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->esp += 4u;
    lift_store32(cpu->eax, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->eax + 4u, 0u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00404EF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x404EF0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->esi)) goto label_00004F20;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0x15555554u;
    cpu->edi -= cpu->edx;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_00004F18;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x4F18u);
    label_00004F18: cpu->eip = LIFT_CODE_TOKEN_VA(0x404F18u);
    cpu->edx += cpu->eax;
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) - (uint64_t)(cpu->eax) - (uint64_t)(0u));
    label_00004F20: cpu->eip = LIFT_CODE_TOKEN_VA(0x404F20u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->edx + 4u, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00404F80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x404F80u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->esi)) goto label_00004FB0;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0xFFFFFFEu;
    cpu->edi -= cpu->edx;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_00004FA8;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x4FA8u);
    label_00004FA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x404FA8u);
    cpu->edx += cpu->eax;
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) - (uint64_t)(cpu->eax) - (uint64_t)(0u));
    label_00004FB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x404FB0u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->edx + 4u, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405010(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405010u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_00005046;
    lift_push32(cpu, cpu->edi);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00005020: cpu->eip = LIFT_CODE_TOKEN_VA(0x405020u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0000503B;
    cpu->edi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edi);
    lift_store32(cpu->ecx + 4u, 0u);
    lift_store32(cpu->ecx, 0u);
    label_0000503B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40503Bu);
    cpu->ecx += 8u;
    cpu->eax += 8u;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_00005020;
    cpu->edi = lift_pop32(cpu);
    label_00005046: cpu->eip = LIFT_CODE_TOKEN_VA(0x405046u);
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405050(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405050u);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0000506F;
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00005060: cpu->eip = LIFT_CODE_TOKEN_VA(0x405060u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00005068;
    cpu->esi = lift_load32(cpu->eax);
    lift_store32(cpu->ecx, cpu->esi);
    label_00005068: cpu->eip = LIFT_CODE_TOKEN_VA(0x405068u);
    cpu->ecx += 4u;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00005060;
    cpu->esi = lift_pop32(cpu);
    label_0000506F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40506Fu);
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405080u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000050A3;
    lift_push32(cpu, cpu->esi);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00005090: cpu->eip = LIFT_CODE_TOKEN_VA(0x405090u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00005098;
    cpu->esi = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->esi);
    label_00005098: cpu->eip = LIFT_CODE_TOKEN_VA(0x405098u);
    cpu->ecx += 4u;
    cpu->eax += 4u;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_00005090;
    cpu->esi = lift_pop32(cpu);
    label_000050A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4050A3u);
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004050B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4050B0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4050BAu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000050EB;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->eax + 8u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000050E5;
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->edx);
    lift_store32(cpu->ecx, cpu->esi);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    cpu->esi = lift_pop32(cpu);
    label_000050E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4050E5u);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
    label_000050EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4050EBu);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 0x14u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405119u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x405119u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405120u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40512Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0000515B;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->eax + 8u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00005155;
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->edx);
    lift_store32(cpu->ecx, cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_store_f32(cpu->ecx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    label_00005155: cpu->eip = LIFT_CODE_TOKEN_VA(0x405155u);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
    label_0000515B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40515Bu);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 0x14u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405189u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x405189u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405190u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40519Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000051DF;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->eax + 8u);
    lift_store32(cpu->eax, cpu->ecx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000051D9;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx);
    lift_store32(cpu->edx, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->edx + 8u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->edx + 4u, cpu->edi);
    lift_store32(cpu->ecx + 8u, 0u);
    lift_store32(cpu->ecx + 4u, 0u);
    cpu->edi = lift_pop32(cpu);
    label_000051D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4051D9u);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
    label_000051DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4051DFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 0x14u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40520Du); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x40520Du, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405210(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405210u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 0x10u);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->ebx)) goto label_00005230;
    lift_push32(cpu, (uint32_t)(uintptr_t)"invalid string position");
    lift_trap(cpu, cpu->eip, "std::out_of_range");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x5230u);
    label_00005230: cpu->eip = LIFT_CODE_TOKEN_VA(0x405230u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi -= cpu->ebx;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edi)) goto label_0000523C;
    cpu->edi = cpu->eax;
    label_0000523C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40523Cu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebp)) goto label_0000525D;
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->edi += cpu->ebx;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40524Au); lift_push32(cpu, r); sfera_sub_00402810(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405254u); lift_push32(cpu, r); sfera_sub_00402810(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000525D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40525Du);
    if ((uint32_t)(cpu->edi) <= (uint32_t)(0xFFFFFFFEu)) goto label_0000526D;
    lift_push32(cpu, (uint32_t)(uintptr_t)"string too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x526Du);
    label_0000526D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40526Du);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edi)) goto label_00005291;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40527Eu); lift_push32(cpu, r); sfera_sub_00403230(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) == 0u) goto label_000052EF;
    label_00005282: cpu->eip = LIFT_CODE_TOKEN_VA(0x405282u);
    cpu->eax = 0x10u;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) < (uint32_t)(cpu->eax)) goto label_000052B7;
    cpu->ecx = lift_load32(cpu->ebp);
    goto label_000052B9;
    label_00005291: cpu->eip = LIFT_CODE_TOKEN_VA(0x405291u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_00005282;
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x10u)) goto label_000052AB;
    cpu->eax = lift_load32(cpu->esi);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->eax, 0u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000052AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4052ABu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->eax, 0u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000052B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4052B7u);
    cpu->ecx = cpu->ebp;
    label_000052B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4052B9u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(cpu->eax)) goto label_000052C2;
    cpu->eax = lift_load32(cpu->esi);
    goto label_000052C4;
    label_000052C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4052C2u);
    cpu->eax = cpu->esi;
    label_000052C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4052C4u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx += cpu->ebx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4052C9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4052CEu);
    cpu->esp += 0xCu;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000052E9;
    cpu->eax = lift_load32(cpu->esi);
    lift_store8(cpu->eax + cpu->edi, 0u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000052E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4052E9u);
    cpu->eax = cpu->esi;
    lift_store8(cpu->eax + cpu->edi, 0u);
    label_000052EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4052EFu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405300(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405300u);
    cpu->ecx = lift_load32(cpu->ecx + 0x10u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_0000532E;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    label_00005310: cpu->eip = LIFT_CODE_TOKEN_VA(0x405310u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_0000531B;
    cpu->eax = lift_load32(cpu->eax);
    ++cpu->edx;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_00005310;
    label_0000531B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40531Bu);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_0000532E;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_0000532E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40532Eu);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405340(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405340u);
    cpu->ecx = lift_load32(cpu->ecx + 0x10u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_00005379;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    cpu->esi = lift_load32(cpu->esi);
    label_00005352: cpu->eip = LIFT_CODE_TOKEN_VA(0x405352u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_0000535D;
    cpu->eax = lift_load32(cpu->eax);
    ++cpu->edx;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_00005352;
    label_0000535D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40535Du);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_00005379;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->ecx + cpu->edx, cpu->eax);
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_00005379: cpu->eip = LIFT_CODE_TOKEN_VA(0x405379u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405380(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405380u);
    cpu->ecx = lift_load32(cpu->ecx + 0x10u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000053AE;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    label_00005390: cpu->eip = LIFT_CODE_TOKEN_VA(0x405390u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_0000539B;
    cpu->eax = lift_load32(cpu->eax);
    ++cpu->edx;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_00005390;
    label_0000539B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40539Bu);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000053AE;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_000053AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4053AEu);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004053C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4053C0u);
    cpu->ecx = lift_load32(cpu->ecx + 0x10u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000053F8;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    cpu->esi = lift_load32(cpu->esi);
    label_000053D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4053D2u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_000053DD;
    cpu->eax = lift_load32(cpu->eax);
    ++cpu->edx;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000053D2;
    label_000053DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4053DDu);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000053F8;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store_f32(cpu->eax + cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_000053F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4053F8u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405400u);
    cpu->ecx = lift_load32(cpu->ecx + 0x10u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_00005433;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    cpu->esi = lift_load32(cpu->esi);
    label_00005412: cpu->eip = LIFT_CODE_TOKEN_VA(0x405412u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_0000541D;
    cpu->eax = lift_load32(cpu->eax);
    ++cpu->edx;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_00005412;
    label_0000541D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40541Du);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_00005433;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40542Eu); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_00005433: cpu->eip = LIFT_CODE_TOKEN_VA(0x405433u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405440(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405440u);
    cpu->ecx = lift_load32(cpu->ecx + 0x10u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = 0u;
    lift_push32(cpu, cpu->esi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000054A4;
    cpu->esi = lift_load32(cpu->esp + 8u);
    label_00005450: cpu->eip = LIFT_CODE_TOKEN_VA(0x405450u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_0000545B;
    cpu->eax = lift_load32(cpu->eax);
    ++cpu->edx;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_00005450;
    label_0000545B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40545Bu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000054A4;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->esi = (uint32_t)(cpu->eax + 8u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_0000549D;
    cpu->edx = 0x46u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40547Au); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405483u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->esi + 4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi);
    lift_store32(cpu->esi, cpu->edx);
    cpu->esp += 4u;
    lift_store32(cpu->edi + 4u, 0u);
    lift_store32(cpu->edi, 0u);
    label_0000549D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40549Du);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000054A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4054A4u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004054B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4054B0u);
    cpu->ecx = lift_load32(cpu->ecx + 0x10u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000054E3;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    cpu->esi = lift_load32(cpu->esi);
    label_000054C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4054C2u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_000054CD;
    cpu->eax = lift_load32(cpu->eax);
    ++cpu->edx;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000054C2;
    label_000054CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4054CDu);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000054E3;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4054DEu); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_000054E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4054E3u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004054F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4054F0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_00005571;
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi + 0x10u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_00005571;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000551A;
    cpu->edi = lift_load32(cpu->esi + 0x20u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(lift_load32(cpu->esi + 0x10u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(2u), 32u);
    goto label_0000551E;
    label_0000551A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40551Au);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    label_0000551E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40551Eu);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx = lift_load32(cpu->esi + 0x14u);
    cpu->ecx = (uint32_t)(cpu->eax + 4u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x405536u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x40553Cu);
    lift_store32(cpu->esi + 0x14u, (uint64_t)(lift_load32(cpu->esi + 0x14u)) + (uint64_t)(0xFFFFFFFCu) + (uint64_t)(0u));
    cpu->esp += 0xCu;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) == (uint8_t)(0u)) goto label_0000556A;
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x10u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_00005566;
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edi) * 4u));
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00005566: cpu->eip = LIFT_CODE_TOKEN_VA(0x405566u);
    lift_store8(cpu->esi + 8u, 0u);
    label_0000556A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40556Au);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00005571: cpu->eip = LIFT_CODE_TOKEN_VA(0x405571u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405580(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405580u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    if ((int32_t)(uint32_t)(cpu->ecx) < 0) goto label_000055EE;
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    cpu->eax -= lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000055EE;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000055A4;
    cpu->edi = lift_load32(cpu->esi + 0x20u);
    cpu->edi -= lift_load32(cpu->esi + 0x10u);
    goto label_000055A8;
    label_000055A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4055A4u);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    label_000055A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4055A8u);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->edx = lift_load32(cpu->esi + 0x14u);
    cpu->eax += cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->eax + 1u);
    cpu->edx -= cpu->ecx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4055B8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4055BEu);
    lift_store32(cpu->esi + 0x14u, (uint64_t)(lift_load32(cpu->esi + 0x14u)) - 1u);
    cpu->esp += 0xCu;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) == (uint8_t)(0u)) goto label_000055E7;
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    cpu->eax -= lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_000055E3;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->eax += cpu->edi;
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000055E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4055E3u);
    lift_store8(cpu->esi + 8u, 0u);
    label_000055E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4055E7u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000055EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4055EEu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405600(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405600u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405615u); lift_push32(cpu, r); sfera_sub_004B2440(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->esi + 0x14u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405630(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00005630;
    label_00003E90: cpu->eip = LIFT_CODE_TOKEN_VA(0x403E90u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ebp) <= (uint32_t)(0xFFFFFFFFu)) goto label_00003EA8;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x3EA8u);
    label_00003EA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x403EA8u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->eax -= lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ebp)) goto label_00003EF4;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x403EBCu); lift_push32(cpu, r); sfera_sub_004028A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx -= cpu->eax;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x403EC8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x403ECEu);
    cpu->eax = lift_load32(cpu->esi);
    cpu->ebx = lift_load32(cpu->esi + 4u);
    cpu->esp += 0xCu;
    cpu->ebx -= cpu->eax;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00003EE5;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x403EE2u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00003EE5: cpu->eip = LIFT_CODE_TOKEN_VA(0x403EE5u);
    cpu->ebx += cpu->edi;
    cpu->edx = (uint32_t)(cpu->edi + cpu->ebp);
    lift_store32(cpu->esi, cpu->edi);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 4u, cpu->ebx);
    lift_store32(cpu->esi + 8u, cpu->edx);
    cpu->ebx = lift_pop32(cpu);
    label_00003EF4: cpu->eip = LIFT_CODE_TOKEN_VA(0x403EF4u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00005630: cpu->eip = LIFT_CODE_TOKEN_VA(0x405630u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->edi);
    cpu->edi |= 0xFFFFFFFFu;
    cpu->eax -= cpu->esi;
    cpu->edi -= cpu->edx;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_00005651;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x5651u);
    label_00005651: cpu->eip = LIFT_CODE_TOKEN_VA(0x405651u);
    cpu->eax += cpu->edx;
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->edx -= cpu->esi;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_00005680;
    cpu->esi = cpu->edx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(1u), 32u);
    cpu->edi |= 0xFFFFFFFFu;
    cpu->edi -= cpu->esi;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->edx)) goto label_0000566D;
    cpu->edx = 0u;
    goto label_0000566F;
    label_0000566D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40566Du);
    cpu->edx += cpu->esi;
    label_0000566F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40566Fu);
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->eax)) goto label_00005675;
    cpu->edx = cpu->eax;
    label_00005675: cpu->eip = LIFT_CODE_TOKEN_VA(0x405675u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->esp + 4u, cpu->edx);
    goto label_00003E90;
    label_00005680: cpu->eip = LIFT_CODE_TOKEN_VA(0x405680u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405770u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000057B3;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00005795;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00005787;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005787: cpu->eip = LIFT_CODE_TOKEN_VA(0x405787u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005795: cpu->eip = LIFT_CODE_TOKEN_VA(0x405795u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40579Au); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000057F2;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4057ABu); lift_push32(cpu, r); sfera_sub_00404230(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000057B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4057B3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4057B8u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000057F2;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x10u);
    cpu->edx = lift_load32(cpu->edi);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esi + 0x1Cu, cpu->edx);
    cpu->edi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000057E5;
    cpu->edx += 8u;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4057D9u); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 1u);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000057E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4057E5u);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000057F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4057F2u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405800u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00005843;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00005825;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00005817;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005817: cpu->eip = LIFT_CODE_TOKEN_VA(0x405817u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005825: cpu->eip = LIFT_CODE_TOKEN_VA(0x405825u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40582Au); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00005882;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40583Bu); lift_push32(cpu, r); sfera_sub_00404270(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005843: cpu->eip = LIFT_CODE_TOKEN_VA(0x405843u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405848u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00005882;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x10u);
    cpu->edx = lift_load32(cpu->edi);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esi + 0x1Cu, cpu->edx);
    cpu->edi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00005875;
    cpu->edx += 8u;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405869u); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 1u);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005875: cpu->eip = LIFT_CODE_TOKEN_VA(0x405875u);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005882: cpu->eip = LIFT_CODE_TOKEN_VA(0x405882u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405A00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405A00u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00005A43;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00005A25;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00005A17;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005A17: cpu->eip = LIFT_CODE_TOKEN_VA(0x405A17u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005A25: cpu->eip = LIFT_CODE_TOKEN_VA(0x405A25u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405A2Au); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00005A7C;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405A3Bu); lift_push32(cpu, r); sfera_sub_00404370(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005A43: cpu->eip = LIFT_CODE_TOKEN_VA(0x405A43u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405A48u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00005A7C;
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->esi + 0x20u, cpu->edx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(lift_load32(cpu->esi + 0x14u))) goto label_00005A6F;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405A63u); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 1u);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005A6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x405A6Fu);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005A7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x405A7Cu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405A80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405A80u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00005AC3;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00005AA5;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00005A97;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005A97: cpu->eip = LIFT_CODE_TOKEN_VA(0x405A97u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 8u)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005AA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x405AA5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405AAAu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00005AFC;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405ABBu); lift_push32(cpu, r); sfera_sub_004043B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005AC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x405AC3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405AC8u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00005AFC;
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->esi + 0x20u, cpu->edx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(lift_load32(cpu->esi + 0x14u))) goto label_00005AEF;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405AE3u); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 1u);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005AEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x405AEFu);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00005AFC: cpu->eip = LIFT_CODE_TOKEN_VA(0x405AFCu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405B00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405B00u);
    cpu->edx = lift_load32(cpu->ecx + 0x18u);
    cpu->eax = lift_load32(cpu->edx);
    lift_store32(cpu->ecx + 0x24u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_00005B3E;
    cpu->eax = lift_load32(cpu->eax + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->esi + cpu->edx, cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x24u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->eax = lift_load32(cpu->eax);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->edx + 0x10u);
    lift_store32(cpu->esi + cpu->eax, cpu->edx);
    lift_store8(cpu->ecx + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00005B3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x405B3Eu);
    lift_store8(cpu->ecx + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405B50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405B50u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) != (uint8_t)(0u)) goto label_00005B60;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00005B60: cpu->eip = LIFT_CODE_TOKEN_VA(0x405B60u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405B69u); lift_push32(cpu, r); sfera_sub_00402220(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x18u))) goto label_00005BA2;
    cpu->eax = lift_load32(cpu->eax + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->ecx + cpu->edx, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 0x24u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->edx + 0x10u);
    lift_store32(cpu->eax + cpu->ecx, cpu->edx);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00005BA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x405BA2u);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405BB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405BB0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->esi + 0x24u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_00005BEA;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405BCBu); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->eax + 0x28u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->ecx + cpu->edx, cpu->eax);
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00005BEA: cpu->eip = LIFT_CODE_TOKEN_VA(0x405BEAu);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405C00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405C00u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) != (uint8_t)(0u)) goto label_00005C10;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00005C10: cpu->eip = LIFT_CODE_TOKEN_VA(0x405C10u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405C19u); lift_push32(cpu, r); sfera_sub_004022D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x18u))) goto label_00005C4D;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = (uint32_t)(cpu->eax + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405C2Du); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->eax + 0x28u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->ecx + cpu->edx, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00005C4D: cpu->eip = LIFT_CODE_TOKEN_VA(0x405C4Du);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405C60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405C60u);
    cpu->edx = lift_load32(cpu->ecx + 0x18u);
    cpu->eax = lift_load32(cpu->edx);
    lift_store32(cpu->ecx + 0x24u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_00005C9E;
    cpu->eax = lift_load32(cpu->eax + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->esi + cpu->edx, cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x10u));
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_store_f32(cpu->edx + cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store8(cpu->ecx + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00005C9E: cpu->eip = LIFT_CODE_TOKEN_VA(0x405C9Eu);
    lift_store8(cpu->ecx + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405CB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405CB0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) != (uint8_t)(0u)) goto label_00005CC0;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00005CC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x405CC0u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405CC9u); lift_push32(cpu, r); sfera_sub_00402220(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x18u))) goto label_00005D03;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->eax + 0xCu);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->ecx + cpu->edx, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 0x24u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x10u));
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_store_f32(cpu->edx + cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00005D03: cpu->eip = LIFT_CODE_TOKEN_VA(0x405D03u);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405D10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405D10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->esi + 0x24u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_00005D49;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405D2Bu); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x28u));
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store_f32(cpu->eax + cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00005D49: cpu->eip = LIFT_CODE_TOKEN_VA(0x405D49u);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405D60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405D60u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) != (uint8_t)(0u)) goto label_00005D70;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00005D70: cpu->eip = LIFT_CODE_TOKEN_VA(0x405D70u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405D79u); lift_push32(cpu, r); sfera_sub_004022D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x18u))) goto label_00005DAC;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = (uint32_t)(cpu->eax + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405D8Du); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x28u));
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store_f32(cpu->eax + cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00005DAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x405DACu);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405DC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405DC0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->esi + 0x24u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_00005DFA;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = lift_load32(cpu->eax + 0xCu);
    lift_store32(cpu->ecx + cpu->edx, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx += 0x10u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405DF0u); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00005DFA: cpu->eip = LIFT_CODE_TOKEN_VA(0x405DFAu);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405E10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) != (uint8_t)(0u)) goto label_00005E20;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00005E20: cpu->eip = LIFT_CODE_TOKEN_VA(0x405E20u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405E29u); lift_push32(cpu, r); sfera_sub_004022D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x18u))) goto label_00005E5D;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = lift_load32(cpu->eax + 0xCu);
    lift_store32(cpu->ecx + cpu->edx, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx += 0x10u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405E52u); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00005E5D: cpu->eip = LIFT_CODE_TOKEN_VA(0x405E5Du);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405E70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405E70u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->esi + 0x24u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_00005EA4;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405E8Bu); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx += 0x28u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405E9Au); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00005EA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x405EA4u);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405EB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405EB0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) != (uint8_t)(0u)) goto label_00005EC0;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00005EC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x405EC0u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405EC9u); lift_push32(cpu, r); sfera_sub_00402360(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x18u))) goto label_00005EF7;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = (uint32_t)(cpu->eax + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405EDDu); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx += 0x28u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405EECu); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00005EF7: cpu->eip = LIFT_CODE_TOKEN_VA(0x405EF7u);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405F10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405F10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->esi + 0x24u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_00005F4A;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = lift_load32(cpu->eax + 0xCu);
    lift_store32(cpu->ecx + cpu->edx, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx += 0x10u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405F40u); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00005F4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x405F4Au);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405F60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405F60u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) != (uint8_t)(0u)) goto label_00005F70;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00005F70: cpu->eip = LIFT_CODE_TOKEN_VA(0x405F70u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405F79u); lift_push32(cpu, r); sfera_sub_004023F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x18u))) goto label_00005FAD;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = lift_load32(cpu->eax + 0xCu);
    lift_store32(cpu->ecx + cpu->edx, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx += 0x10u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405FA2u); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00005FAD: cpu->eip = LIFT_CODE_TOKEN_VA(0x405FADu);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00405FC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x405FC0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->esi + 0x24u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_00005FF4;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405FDBu); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx += 0x28u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x405FEAu); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00005FF4: cpu->eip = LIFT_CODE_TOKEN_VA(0x405FF4u);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406000u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) != (uint8_t)(0u)) goto label_00006010;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00006010: cpu->eip = LIFT_CODE_TOKEN_VA(0x406010u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406019u); lift_push32(cpu, r); sfera_sub_00402480(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x18u))) goto label_00006047;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = (uint32_t)(cpu->eax + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40602Du); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx += 0x28u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40603Cu); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00006047: cpu->eip = LIFT_CODE_TOKEN_VA(0x406047u);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406060(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406060u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x15u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000608A;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->edi);
    label_00006075: cpu->eip = LIFT_CODE_TOKEN_VA(0x406075u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + 0xCu)) >= (int32_t)(uint32_t)(cpu->esi)) goto label_0000607F;
    cpu->eax = lift_load32(cpu->eax + 8u);
    goto label_00006083;
    label_0000607F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40607Fu);
    cpu->edx = cpu->eax;
    cpu->eax = lift_load32(cpu->eax);
    label_00006083: cpu->eip = LIFT_CODE_TOKEN_VA(0x406083u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x15u)) == (uint8_t)(0u)) goto label_00006075;
    cpu->esi = lift_pop32(cpu);
    label_0000608A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40608Au);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->eax)) goto label_000060AD;
    cpu->ecx = lift_load32(cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->edx + 0xCu))) goto label_000060AD;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000060AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4060ADu);
    lift_store32(cpu->esp + 4u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004060D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4060D0u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x2Du)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000060FA;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->edi);
    label_000060E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4060E5u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + 0xCu)) >= (int32_t)(uint32_t)(cpu->esi)) goto label_000060EF;
    cpu->eax = lift_load32(cpu->eax + 8u);
    goto label_000060F3;
    label_000060EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4060EFu);
    cpu->edx = cpu->eax;
    cpu->eax = lift_load32(cpu->eax);
    label_000060F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4060F3u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x2Du)) == (uint8_t)(0u)) goto label_000060E5;
    cpu->esi = lift_pop32(cpu);
    label_000060FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4060FAu);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->eax)) goto label_0000611D;
    cpu->ecx = lift_load32(cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->edx + 0xCu))) goto label_0000611D;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0000611D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40611Du);
    lift_store32(cpu->esp + 4u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406140u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x19u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000616A;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->edi);
    label_00006155: cpu->eip = LIFT_CODE_TOKEN_VA(0x406155u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + 0xCu)) >= (int32_t)(uint32_t)(cpu->esi)) goto label_0000615F;
    cpu->eax = lift_load32(cpu->eax + 8u);
    goto label_00006163;
    label_0000615F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40615Fu);
    cpu->edx = cpu->eax;
    cpu->eax = lift_load32(cpu->eax);
    label_00006163: cpu->eip = LIFT_CODE_TOKEN_VA(0x406163u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x19u)) == (uint8_t)(0u)) goto label_00006155;
    cpu->esi = lift_pop32(cpu);
    label_0000616A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40616Au);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->eax)) goto label_0000618D;
    cpu->ecx = lift_load32(cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->edx + 0xCu))) goto label_0000618D;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0000618D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40618Du);
    lift_store32(cpu->esp + 4u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004061B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4061B0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_000061C4;
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4061C1u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000061C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4061C4u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store8(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406210(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406210u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x30u)) < (uint32_t)(0x10u)) goto label_00006225;
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406222u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00006225: cpu->eip = LIFT_CODE_TOKEN_VA(0x406225u);
    lift_store32(cpu->esi + 0x30u, 0xFu);
    lift_store32(cpu->esi + 0x2Cu, 0u);
    lift_store8(cpu->esi + 0x1Cu, 0u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_00006248;
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406245u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00006248: cpu->eip = LIFT_CODE_TOKEN_VA(0x406248u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store8(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406340(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406340u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax))) goto label_0000636E;
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->eax)) goto label_0000636E;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40635Eu); lift_push32(cpu, r); sfera_sub_00429A30(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0000636E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40636Eu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000063DF;
    label_00006372: cpu->eip = LIFT_CODE_TOKEN_VA(0x406372u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + 0x15u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edx = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000063C8;
    cpu->eax = lift_load32(cpu->ecx + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x15u)) != (uint8_t)(0u)) goto label_000063A0;
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->eax + 0x15u)) != (uint8_t)(0u)) goto label_0000639A;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00006390: cpu->eip = LIFT_CODE_TOKEN_VA(0x406390u);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->eax + 0x15u)) == (uint8_t)(0u)) goto label_00006390;
    label_0000639A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40639Au);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    goto label_000063C8;
    label_000063A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4063A0u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x15u)) != (uint8_t)(0u)) goto label_000063C4;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000063B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4063B0u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_000063C4;
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->eax = lift_load32(cpu->eax + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x15u)) == (uint8_t)(0u)) goto label_000063B0;
    label_000063C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4063C4u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_000063C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4063C8u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4063D5u); lift_push32(cpu, r); sfera_sub_00404510(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_00006372;
    label_000063DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4063DFu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004063F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4063F0u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0000642A;
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx + 4u);
    label_00006400: cpu->eip = LIFT_CODE_TOKEN_VA(0x406400u);
    if ((uint32_t)(lift_load32(cpu->esi)) == (uint32_t)(0u)) goto label_0000641F;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406414u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40641Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000641F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40641Fu);
    cpu->esi += 8u;
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFFCu);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edi)) goto label_00006400;
    cpu->esi = lift_pop32(cpu);
    label_0000642A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40642Au);
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406430(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406430u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000645C;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406452u); lift_push32(cpu, r); sfera_sub_004037A0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000645C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40645Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebp);
    if ((uint32_t)(cpu->ebx) != (uint32_t)(lift_load32(cpu->eax))) goto label_0000648E;
    cpu->ecx = lift_load32(cpu->edi + 0xCu);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0xCu))) goto label_0000656D;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406482u); lift_push32(cpu, r); sfera_sub_004037A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000648E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40648Eu);
    if ((uint32_t)(cpu->ebx) != (uint32_t)(cpu->eax)) goto label_000064BB;
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    if ((int32_t)(uint32_t)(cpu->edx) >= (int32_t)(uint32_t)(lift_load32(cpu->edi + 0xCu))) goto label_0000656D;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4064AFu); lift_push32(cpu, r); sfera_sub_004037A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_000064BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4064BBu);
    cpu->ebp = lift_load32(cpu->edi + 0xCu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0xCu)), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00006516;
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4064D0u); lift_push32(cpu, r); sfera_sub_004025A0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + 0xCu)) >= (int32_t)(uint32_t)(cpu->ebp)) goto label_00006513;
    cpu->ecx = lift_load32(cpu->eax + 8u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + 0x15u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000064FE;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4064F2u); lift_push32(cpu, r); sfera_sub_004037A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_000064FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4064FEu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406507u); lift_push32(cpu, r); sfera_sub_004037A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_00006513: cpu->eip = LIFT_CODE_TOKEN_VA(0x406513u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0xCu)), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_00006516: cpu->eip = LIFT_CODE_TOKEN_VA(0x406516u);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0000656D;
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406525u); lift_push32(cpu, r); sfera_sub_00402220(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00006533;
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(lift_load32(cpu->eax + 0xCu))) goto label_0000656D;
    label_00006533: cpu->eip = LIFT_CODE_TOKEN_VA(0x406533u);
    cpu->edx = lift_load32(cpu->ebx + 8u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edx + 0x15u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00006558;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40654Cu); lift_push32(cpu, r); sfera_sub_004037A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_00006558: cpu->eip = LIFT_CODE_TOKEN_VA(0x406558u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406561u); lift_push32(cpu, r); sfera_sub_004037A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_0000656D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40656Du);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40657Cu); lift_push32(cpu, r); sfera_sub_00404E10(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406590(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406590u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x18u);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40659Du); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0u;
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_000065D7;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->eax + 0xCu);
    lift_store16(cpu->eax + 0x14u, cpu->edx & 0xFFFFu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_000065D0;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->esi = lift_load32(cpu->edx);
    lift_store32(cpu->ecx, cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_store_f32(cpu->ecx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000065D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4065D0u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_000065D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4065D7u);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406601u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x406601u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406610(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406610u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x1Cu);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40661Eu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 0u;
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00006665;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->eax + 0xCu);
    lift_store16(cpu->eax + 0x18u, cpu->ebx & 0xFFFFu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0000665D;
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->esi = lift_load32(cpu->edx);
    lift_store32(cpu->ecx, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 8u);
    lift_store32(cpu->ecx + 8u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->ecx + 4u, cpu->esi);
    lift_store32(cpu->edx + 8u, cpu->ebx);
    lift_store32(cpu->edx + 4u, cpu->ebx);
    label_0000665D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40665Du);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_00006665: cpu->eip = LIFT_CODE_TOKEN_VA(0x406665u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40668Fu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x40668Fu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406690(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406690u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40669Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000066DE;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->eax + 8u);
    lift_store32(cpu->eax, cpu->ecx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000066D8;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->edx + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx);
    lift_store32(cpu->edx, cpu->edi);
    lift_store32(cpu->ecx + 4u, 0u);
    lift_store32(cpu->ecx, 0u);
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->edx + 8u, cpu->ecx);
    cpu->edi = lift_pop32(cpu);
    label_000066D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4066D8u);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
    label_000066DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4066DEu);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 0x14u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40670Cu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x40670Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406710(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406710u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40671Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0000675E;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->eax + 8u);
    lift_store32(cpu->eax, cpu->ecx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_00006758;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->edx + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx);
    lift_store32(cpu->edx, cpu->edi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_store32(cpu->ecx + 4u, 0u);
    lift_store32(cpu->ecx, 0u);
    lift_store_f32(cpu->edx + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    label_00006758: cpu->eip = LIFT_CODE_TOKEN_VA(0x406758u);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
    label_0000675E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40675Eu);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 0x14u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40678Cu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x40678Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406790(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406790u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40679Bu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0u;
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000067E6;
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->eax + 8u);
    lift_store32(cpu->eax, cpu->ecx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_000067DF;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->edx + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx);
    lift_store32(cpu->edx, cpu->edi);
    lift_store32(cpu->ecx + 4u, cpu->esi);
    lift_store32(cpu->ecx, cpu->esi);
    cpu->edi = lift_load32(cpu->ecx + 0xCu);
    lift_store32(cpu->edx + 0xCu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->edx + 8u, cpu->edi);
    lift_store32(cpu->ecx + 0xCu, cpu->esi);
    lift_store32(cpu->ecx + 8u, cpu->esi);
    cpu->edi = lift_pop32(cpu);
    label_000067DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4067DFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
    label_000067E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4067E6u);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406810u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x406810u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406820(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406820u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    sfera_prepare_msvc_string_storage(cpu->esi);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_00006885;
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(0x10u)) goto label_00006838;
    cpu->eax = lift_load32(cpu->esi);
    goto label_0000683A;
    label_00006838: cpu->eip = LIFT_CODE_TOKEN_VA(0x406838u);
    cpu->eax = cpu->esi;
    label_0000683A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40683Au);
    if ((uint32_t)(cpu->ebx) < (uint32_t)(cpu->eax)) goto label_00006885;
    if ((uint32_t)(cpu->ecx) < (uint32_t)(0x10u)) goto label_00006847;
    cpu->eax = lift_load32(cpu->esi);
    goto label_00006849;
    label_00006847: cpu->eip = LIFT_CODE_TOKEN_VA(0x406847u);
    cpu->eax = cpu->esi;
    label_00006849: cpu->eip = LIFT_CODE_TOKEN_VA(0x406849u);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    cpu->edx += cpu->eax;
    if ((uint32_t)(cpu->edx) <= (uint32_t)(cpu->ebx)) goto label_00006885;
    if ((uint32_t)(cpu->ecx) < (uint32_t)(0x10u)) goto label_0000686E;
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ebx -= cpu->eax;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406869u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0000686E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40686Eu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = cpu->esi;
    lift_push32(cpu, cpu->ecx);
    cpu->ebx -= cpu->eax;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406880u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00006885: cpu->eip = LIFT_CODE_TOKEN_VA(0x406885u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->edi) <= (uint32_t)(0xFFFFFFFEu)) goto label_0000689A;
    lift_push32(cpu, (uint32_t)(uintptr_t)"string too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x689Au);
    label_0000689A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40689Au);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edi)) goto label_000068BB;
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4068ADu); lift_push32(cpu, r); sfera_sub_00403230(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) == 0u) goto label_00006909;
    label_000068B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4068B1u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_000068DF;
    cpu->eax = lift_load32(cpu->esi);
    goto label_000068E1;
    label_000068BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4068BBu);
    if ((uint32_t)(cpu->edi) != 0u) goto label_000068B1;
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x10u)) goto label_000068D4;
    cpu->eax = lift_load32(cpu->esi);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->eax, 0u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000068D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4068D4u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    lift_store8(cpu->eax, 0u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000068DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4068DFu);
    cpu->eax = cpu->esi;
    label_000068E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4068E1u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4068E4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4068E9u);
    cpu->esp += 0xCu;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00006903;
    cpu->eax = lift_load32(cpu->esi);
    lift_store8(cpu->eax + cpu->edi, 0u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00006903: cpu->eip = LIFT_CODE_TOKEN_VA(0x406903u);
    cpu->eax = cpu->esi;
    lift_store8(cpu->eax + cpu->edi, 0u);
    label_00006909: cpu->eip = LIFT_CODE_TOKEN_VA(0x406909u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406920u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 0x10u);
    cpu->esi = (uint32_t)(cpu->ecx + 0x10u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406939u); lift_push32(cpu, r); sfera_sub_004B9190(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_00006953;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x6953u);
    label_00006953: cpu->eip = LIFT_CODE_TOKEN_VA(0x406953u);
    ++cpu->ecx;
    lift_store32(cpu->esi + 4u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406970u);
    cpu->eax = lift_load32(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40698Bu); lift_push32(cpu, r); sfera_sub_004B9190(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_000069A5;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x69A5u);
    label_000069A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4069A5u);
    ++cpu->ecx;
    lift_store32(cpu->esi + 4u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004069C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4069C0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_00006A24;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    label_000069D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4069D3u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000069DE;
    cpu->eax = lift_load32(cpu->eax);
    ++cpu->ecx;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_000069D3;
    label_000069DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4069DEu);
    cpu->edi = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_00006A24;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) == (uint8_t)(0u)) goto label_000069FE;
    if ((uint32_t)(lift_load32(cpu->esi + 0x1Cu)) != (uint32_t)(cpu->eax)) goto label_000069FE;
    cpu->ecx = lift_load32(cpu->esi + 0x1Cu);
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->esi + 0x1Cu, cpu->ecx);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_000069FE;
    lift_store8(cpu->esi + 8u, 0u);
    label_000069FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4069FEu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_00006A1E;
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->edx, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->edx + 4u, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406A18u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x14u, (uint64_t)(lift_load32(cpu->esi + 0x14u)) - 1u);
    label_00006A1E: cpu->eip = LIFT_CODE_TOKEN_VA(0x406A1Eu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00006A24: cpu->eip = LIFT_CODE_TOKEN_VA(0x406A24u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406A30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406A30u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 0x10u);
    cpu->esi = (uint32_t)(cpu->ecx + 0x10u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406A49u); lift_push32(cpu, r); sfera_sub_004036B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_00006A63;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x6A63u);
    label_00006A63: cpu->eip = LIFT_CODE_TOKEN_VA(0x406A63u);
    ++cpu->ecx;
    lift_store32(cpu->esi + 4u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406A80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406A80u);
    cpu->eax = lift_load32(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406A9Bu); lift_push32(cpu, r); sfera_sub_004036B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = 0x3FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_00006AB5;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x6AB5u);
    label_00006AB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x406AB5u);
    ++cpu->ecx;
    lift_store32(cpu->esi + 4u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406AD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406AD0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 0x10u);
    cpu->esi = (uint32_t)(cpu->ecx + 0x10u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406AE9u); lift_push32(cpu, r); sfera_sub_00403720(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = 0x1FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_00006B03;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x6B03u);
    label_00006B03: cpu->eip = LIFT_CODE_TOKEN_VA(0x406B03u);
    ++cpu->ecx;
    lift_store32(cpu->esi + 4u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406B20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406B20u);
    cpu->eax = lift_load32(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406B3Bu); lift_push32(cpu, r); sfera_sub_00403720(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = 0x1FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(1u)) goto label_00006B55;
    lift_push32(cpu, (uint32_t)(uintptr_t)"list<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x6B55u);
    label_00006B55: cpu->eip = LIFT_CODE_TOKEN_VA(0x406B55u);
    ++cpu->ecx;
    lift_store32(cpu->esi + 4u, cpu->ecx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406B70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406B70u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx + 0x10u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406B85u); lift_push32(cpu, r); sfera_sub_004D23B0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406B92u); lift_push32(cpu, r); sfera_sub_004043F0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406BA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406BA0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(lift_load32(cpu->edi))) goto label_00006BFD;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edx + 4u, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->esi + 0xCu)) == (uint32_t)(0u)) goto label_00006BE2;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406BD6u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406BDFu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00006BE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x406BE2u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406BE8u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->esp += 4u;
    lift_store32(cpu->edi + 4u, (uint64_t)(lift_load32(cpu->edi + 4u)) - 1u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00006BFD: cpu->eip = LIFT_CODE_TOKEN_VA(0x406BFDu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406C10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406C10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_00006C4F;
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->edi)) goto label_00006C4F;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_00006C38;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C38u); lift_push32(cpu, r); sfera_sub_004BDE90(cpu,r); if (cpu->eip != r) return; }
    label_00006C38: cpu->eip = LIFT_CODE_TOKEN_VA(0x406C38u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00006C68;
    cpu->ecx = lift_load32(cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u)));
    cpu->edi = lift_pop32(cpu);
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(4u) + (uint64_t)(0u));
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00006C4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x406C4Fu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_00006C5D;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6C5Du); lift_push32(cpu, r); sfera_sub_004BDE90(cpu,r); if (cpu->eip != r) return; }
    label_00006C5D: cpu->eip = LIFT_CODE_TOKEN_VA(0x406C5Du);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00006C68;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00006C68: cpu->eip = LIFT_CODE_TOKEN_VA(0x406C68u);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(4u) + (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406C80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406C80u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_00006CBB;
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->edi)) goto label_00006CBB;
    cpu->edi -= cpu->ecx;
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_00006CA5;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6CA5u); lift_push32(cpu, r); sfera_sub_00405630(cpu,r); if (cpu->eip != r) return; }
    label_00006CA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x406CA5u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00006CD4;
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + cpu->ecx)) & 0xFFu);
    lift_store8(cpu->eax, cpu->edx & 0xFFu);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00006CBB: cpu->eip = LIFT_CODE_TOKEN_VA(0x406CBBu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_00006CC9;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x6CC9u); lift_push32(cpu, r); sfera_sub_00405630(cpu,r); if (cpu->eip != r) return; }
    label_00006CC9: cpu->eip = LIFT_CODE_TOKEN_VA(0x406CC9u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00006CD4;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi)) & 0xFFu);
    lift_store8(cpu->eax, cpu->ecx & 0xFFu);
    label_00006CD4: cpu->eip = LIFT_CODE_TOKEN_VA(0x406CD4u);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406CE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406CE0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406CF5u); lift_push32(cpu, r); sfera_sub_00406060(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x18u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00006D15;
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0x10u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->eax + cpu->ecx, cpu->edx);
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_00006D15: cpu->eip = LIFT_CODE_TOKEN_VA(0x406D15u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406D20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406D20u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406D35u); lift_push32(cpu, r); sfera_sub_00406060(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x18u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00006D56;
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    cpu->ecx = lift_load32(cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_store_f32(cpu->edx + cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_00006D56: cpu->eip = LIFT_CODE_TOKEN_VA(0x406D56u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406D60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406D60u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406D75u); lift_push32(cpu, r); sfera_sub_004060D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x18u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00006D90;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406D8Bu); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_00006D90: cpu->eip = LIFT_CODE_TOKEN_VA(0x406D90u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406DA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406DA0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406DB5u); lift_push32(cpu, r); sfera_sub_00406140(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x18u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00006DD0;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406DCBu); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_00006DD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x406DD0u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406DE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406DE0u);
    cpu->edx = lift_load32(cpu->ecx + 0x18u);
    cpu->eax = lift_load32(cpu->edx);
    lift_store32(cpu->ecx + 0x40u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_00006E1E;
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->esi + cpu->edx, cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x40u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->eax = lift_load32(cpu->eax);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->edx + 0xCu);
    lift_store32(cpu->esi + cpu->eax, cpu->edx);
    lift_store8(cpu->ecx + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00006E1E: cpu->eip = LIFT_CODE_TOKEN_VA(0x406E1Eu);
    lift_store8(cpu->ecx + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406E30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406E30u);
    if ((uint8_t)(lift_load8(cpu->ecx + 8u)) == (uint8_t)(0u)) goto label_00006E7B;
    cpu->eax = lift_load32(cpu->ecx + 0x40u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = cpu->edx;
    lift_store32(cpu->ecx + 0x40u, cpu->edx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ecx + 0x18u))) goto label_00006E77;
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->esi + cpu->edx, cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x40u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->eax = lift_load32(cpu->eax);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->edx + 0xCu);
    lift_store32(cpu->esi + cpu->eax, cpu->edx);
    lift_store8(cpu->ecx + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00006E77: cpu->eip = LIFT_CODE_TOKEN_VA(0x406E77u);
    lift_store8(cpu->ecx + 8u, 0u);
    label_00006E7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x406E7Bu);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406E90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406E90u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_00006ECA;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406EABu); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x40u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->eax + 0x24u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->ecx + cpu->edx, cpu->eax);
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00006ECA: cpu->eip = LIFT_CODE_TOKEN_VA(0x406ECAu);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406EE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406EE0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) == (uint8_t)(0u)) goto label_00006F26;
    cpu->eax = lift_load32(cpu->esi + 0x40u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esi + 0x40u, cpu->ecx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x18u))) goto label_00006F22;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406F04u); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x40u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->edx + 0x24u);
    lift_store32(cpu->eax + cpu->ecx, cpu->edx);
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00006F22: cpu->eip = LIFT_CODE_TOKEN_VA(0x406F22u);
    lift_store8(cpu->esi + 8u, 0u);
    label_00006F26: cpu->eip = LIFT_CODE_TOKEN_VA(0x406F26u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406F30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406F30u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_00006F6A;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406F4Bu); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x40u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->eax + 0x10u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->ecx + cpu->edx, cpu->eax);
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00006F6A: cpu->eip = LIFT_CODE_TOKEN_VA(0x406F6Au);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406F80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406F80u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) == (uint8_t)(0u)) goto label_00006FC6;
    cpu->eax = lift_load32(cpu->esi + 0x40u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esi + 0x40u, cpu->ecx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x18u))) goto label_00006FC2;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x406FA4u); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x40u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->edx + 0x10u);
    lift_store32(cpu->eax + cpu->ecx, cpu->edx);
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00006FC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x406FC2u);
    lift_store8(cpu->esi + 8u, 0u);
    label_00006FC6: cpu->eip = LIFT_CODE_TOKEN_VA(0x406FC6u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00406FE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x406FE0u);
    cpu->edx = lift_load32(cpu->ecx + 0x18u);
    cpu->eax = lift_load32(cpu->edx);
    lift_store32(cpu->ecx + 0x40u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_0000701E;
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->esi + cpu->edx, cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x40u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0xCu));
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_store_f32(cpu->edx + cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store8(cpu->ecx + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0000701E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40701Eu);
    lift_store8(cpu->ecx + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00407030(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x407030u);
    if ((uint8_t)(lift_load8(cpu->ecx + 8u)) == (uint8_t)(0u)) goto label_0000707B;
    cpu->eax = lift_load32(cpu->ecx + 0x40u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = cpu->edx;
    lift_store32(cpu->ecx + 0x40u, cpu->edx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ecx + 0x18u))) goto label_00007077;
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->esi + cpu->edx, cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x40u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0xCu));
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_store_f32(cpu->edx + cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store8(cpu->ecx + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00007077: cpu->eip = LIFT_CODE_TOKEN_VA(0x407077u);
    lift_store8(cpu->ecx + 8u, 0u);
    label_0000707B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40707Bu);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00407090(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x407090u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000070C9;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4070ABu); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x40u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x24u));
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store_f32(cpu->eax + cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000070C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4070C9u);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004070E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4070E0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) == (uint8_t)(0u)) goto label_00007127;
    cpu->eax = lift_load32(cpu->esi + 0x40u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esi + 0x40u, cpu->ecx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x18u))) goto label_00007123;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407104u); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x40u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x24u));
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_store_f32(cpu->edx + cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00007123: cpu->eip = LIFT_CODE_TOKEN_VA(0x407123u);
    lift_store8(cpu->esi + 8u, 0u);
    label_00007127: cpu->eip = LIFT_CODE_TOKEN_VA(0x407127u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00407130(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x407130u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_00007169;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40714Bu); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x40u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store_f32(cpu->eax + cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00007169: cpu->eip = LIFT_CODE_TOKEN_VA(0x407169u);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00407180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x407180u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) == (uint8_t)(0u)) goto label_000071C7;
    cpu->eax = lift_load32(cpu->esi + 0x40u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esi + 0x40u, cpu->ecx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x18u))) goto label_000071C3;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4071A4u); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x40u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x10u));
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_store_f32(cpu->edx + cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000071C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4071C3u);
    lift_store8(cpu->esi + 8u, 0u);
    label_000071C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4071C7u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004071D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4071D0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_0000720A;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + cpu->edx, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 0x40u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx += 0xCu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407200u); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0000720A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40720Au);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00407220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x407220u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) == (uint8_t)(0u)) goto label_00007266;
    cpu->eax = lift_load32(cpu->esi + 0x40u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esi + 0x40u, cpu->ecx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x18u))) goto label_00007262;
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->eax + cpu->ecx, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x40u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx += 0xCu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407258u); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00007262: cpu->eip = LIFT_CODE_TOKEN_VA(0x407262u);
    lift_store8(cpu->esi + 8u, 0u);
    label_00007266: cpu->eip = LIFT_CODE_TOKEN_VA(0x407266u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00407270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x407270u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000072A4;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40728Bu); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x40u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx += 0x24u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40729Au); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000072A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4072A4u);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004072B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4072B0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) == (uint8_t)(0u)) goto label_000072F1;
    cpu->eax = lift_load32(cpu->esi + 0x40u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esi + 0x40u, cpu->ecx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x18u))) goto label_000072ED;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4072D4u); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x40u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx += 0x24u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4072E3u); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000072ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4072EDu);
    lift_store8(cpu->esi + 8u, 0u);
    label_000072F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4072F1u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00407300(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x407300u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_00007334;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40731Bu); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x40u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx += 0x10u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40732Au); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00007334: cpu->eip = LIFT_CODE_TOKEN_VA(0x407334u);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00407340(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x407340u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) == (uint8_t)(0u)) goto label_00007381;
    cpu->eax = lift_load32(cpu->esi + 0x40u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esi + 0x40u, cpu->ecx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x18u))) goto label_0000737D;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407364u); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x40u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx += 0x10u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407373u); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0000737D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40737Du);
    lift_store8(cpu->esi + 8u, 0u);
    label_00007381: cpu->eip = LIFT_CODE_TOKEN_VA(0x407381u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00407390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x407390u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000073CA;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + cpu->edx, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 0x40u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx += 0xCu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4073C0u); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000073CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4073CAu);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004073E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4073E0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) == (uint8_t)(0u)) goto label_00007426;
    cpu->eax = lift_load32(cpu->esi + 0x40u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esi + 0x40u, cpu->ecx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x18u))) goto label_00007422;
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->eax + cpu->ecx, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x40u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx += 0xCu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407418u); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00007422: cpu->eip = LIFT_CODE_TOKEN_VA(0x407422u);
    lift_store8(cpu->esi + 8u, 0u);
    label_00007426: cpu->eip = LIFT_CODE_TOKEN_VA(0x407426u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00407430(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x407430u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_00007464;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40744Bu); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x40u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx += 0x24u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40745Au); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00007464: cpu->eip = LIFT_CODE_TOKEN_VA(0x407464u);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00407470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x407470u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) == (uint8_t)(0u)) goto label_000074B1;
    cpu->eax = lift_load32(cpu->esi + 0x40u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esi + 0x40u, cpu->ecx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x18u))) goto label_000074AD;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407494u); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x40u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx += 0x24u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4074A3u); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000074AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4074ADu);
    lift_store8(cpu->esi + 8u, 0u);
    label_000074B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4074B1u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004074C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4074C0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000074F4;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4074DBu); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x40u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx += 0x10u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4074EAu); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000074F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4074F4u);
    lift_store8(cpu->esi + 8u, 0u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00407500(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x407500u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) == (uint8_t)(0u)) goto label_00007541;
    cpu->eax = lift_load32(cpu->esi + 0x40u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esi + 0x40u, cpu->ecx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x18u))) goto label_0000753D;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407524u); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x40u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx += 0x10u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407533u); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 8u, 1u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0000753D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40753Du);
    lift_store8(cpu->esi + 8u, 0u);
    label_00007541: cpu->eip = LIFT_CODE_TOKEN_VA(0x407541u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00407550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x407550u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x1F31Du); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::ldiv), LIFT_CODE_TOKEN_VA(0x407562u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x407568u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x41A7u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xB14u);
    cpu->esp += 8u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00007581;
    cpu->edx += 0x7FFFFFFFu;
    label_00007581: cpu->eip = LIFT_CODE_TOKEN_VA(0x407581u);
    cpu->ecx = lift_load32(cpu->esi + 0x20u);
    cpu->eax = cpu->ecx;
    cpu->eax &= cpu->edx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x24u)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00007596;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->ecx;
    cpu->eax += cpu->edx;
    label_00007596: cpu->eip = LIFT_CODE_TOKEN_VA(0x407596u);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->edi = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 8u));
    cpu->esi = lift_load32(cpu->esi + 4u);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax = cpu->edi;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    label_000075A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4075A8u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->esi)) goto label_000075B0;
    cpu->ecx = cpu->esi;
    goto label_000075B5;
    label_000075B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4075B0u);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    cpu->ecx = lift_load32(cpu->ecx);
    label_000075B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4075B5u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_000075F6;
    cpu->ecx = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(lift_load32(cpu->ebx))) goto label_000075C4;
    cpu->eax = lift_load32(cpu->eax);
    goto label_000075A8;
    label_000075C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4075C4u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->ebx)) == (uint32_t)(cpu->ecx)) goto label_000075E3;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000075E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4075E3u);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000075F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4075F6u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00407610(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x407610u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->edx = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->esi = 0x811C9DC5u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_00007640;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00007630: cpu->eip = LIFT_CODE_TOKEN_VA(0x407630u);
    cpu->edi = (int8_t)(lift_load8(cpu->eax));
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x1000193u);
    ++cpu->eax;
    cpu->esi ^= cpu->edi;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_00007630;
    label_00007640: cpu->eip = LIFT_CODE_TOKEN_VA(0x407640u);
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    cpu->eax = cpu->edx;
    cpu->eax &= cpu->esi;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + 0x24u)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00007655;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->esi |= 0xFFFFFFFFu;
    cpu->esi -= cpu->edx;
    cpu->eax += cpu->esi;
    label_00007655: cpu->eip = LIFT_CODE_TOKEN_VA(0x407655u);
    cpu->edx = lift_load32(cpu->ecx + 0x10u);
    cpu->ebp = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 8u));
    cpu->edi = lift_load32(cpu->ecx + 4u);
    cpu->ebx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 8u));
    cpu->esi = cpu->ebp;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    label_00007667: cpu->eip = LIFT_CODE_TOKEN_VA(0x407667u);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(cpu->edi)) goto label_0000766F;
    cpu->eax = cpu->edi;
    goto label_00007674;
    label_0000766F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40766Fu);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->eax = lift_load32(cpu->eax);
    label_00007674: cpu->eip = LIFT_CODE_TOKEN_VA(0x407674u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_000076CE;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407685u); lift_push32(cpu, r); sfera_sub_00401D30(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0000768D;
    cpu->esi = lift_load32(cpu->esi);
    goto label_00007667;
    label_0000768D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40768Du);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    cpu->esi += 8u;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40769Eu); lift_push32(cpu, r); sfera_sub_00401D30(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000076BA;
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000076BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4076BAu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000076CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4076CEu);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->eax, cpu->edi);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004076E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4076E0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->ecx);
    cpu->ecx += cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    cpu->edx = 0x811C9DC5u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_00007711;
    label_00007701: cpu->eip = LIFT_CODE_TOKEN_VA(0x407701u);
    cpu->esi = (int8_t)(lift_load8(cpu->eax));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1000193u);
    ++cpu->eax;
    cpu->edx ^= cpu->esi;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_00007701;
    label_00007711: cpu->eip = LIFT_CODE_TOKEN_VA(0x407711u);
    cpu->ecx = lift_load32(cpu->edi + 0x20u);
    cpu->eax = cpu->ecx;
    cpu->eax &= cpu->edx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + 0x24u)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00007726;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->ecx;
    cpu->eax += cpu->edx;
    label_00007726: cpu->eip = LIFT_CODE_TOKEN_VA(0x407726u);
    cpu->ecx = lift_load32(cpu->edi + 0x10u);
    cpu->ebp = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 8u));
    cpu->edi = lift_load32(cpu->edi + 4u);
    cpu->ebx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 8u));
    cpu->esi = cpu->ebp;
    label_00007734: cpu->eip = LIFT_CODE_TOKEN_VA(0x407734u);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(cpu->edi)) goto label_0000773C;
    cpu->eax = cpu->edi;
    goto label_00007741;
    label_0000773C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40773Cu);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->eax = lift_load32(cpu->edx);
    label_00007741: cpu->eip = LIFT_CODE_TOKEN_VA(0x407741u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_000077A1;
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407752u); lift_push32(cpu, r); sfera_sub_00401D30(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0000775A;
    cpu->esi = lift_load32(cpu->esi);
    goto label_00007734;
    label_0000775A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40775Au);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    cpu->edi = cpu->edi;
    label_00007760: cpu->eip = LIFT_CODE_TOKEN_VA(0x407760u);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(cpu->edi)) goto label_00007768;
    cpu->eax = cpu->edi;
    goto label_0000776D;
    label_00007768: cpu->eip = LIFT_CODE_TOKEN_VA(0x407768u);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->eax = lift_load32(cpu->ecx);
    label_0000776D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40776Du);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_00007786;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40777Eu); lift_push32(cpu, r); sfera_sub_00401D30(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00007786;
    cpu->esi = lift_load32(cpu->esi);
    goto label_00007760;
    label_00007786: cpu->eip = LIFT_CODE_TOKEN_VA(0x407786u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->esi)) goto label_000077A1;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax + 4u, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 8u, stop_address); return;
    label_000077A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4077A1u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004077C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4077C0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->ebp);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x1F31Du); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::ldiv), LIFT_CODE_TOKEN_VA(0x4077D3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4077D9u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x41A7u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xB14u);
    cpu->esp += 8u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000077F2;
    cpu->edx += 0x7FFFFFFFu;
    label_000077F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4077F2u);
    cpu->ecx = lift_load32(cpu->esi + 0x20u);
    cpu->eax = cpu->ecx;
    cpu->eax &= cpu->edx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x24u)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00007807;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->ecx;
    cpu->eax += cpu->edx;
    label_00007807: cpu->eip = LIFT_CODE_TOKEN_VA(0x407807u);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->ebx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 8u));
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->edi = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 8u));
    cpu->ecx = cpu->ebx;
    label_00007815: cpu->eip = LIFT_CODE_TOKEN_VA(0x407815u);
    if ((uint32_t)(cpu->ebx) != (uint32_t)(cpu->edx)) goto label_0000781D;
    cpu->eax = cpu->edx;
    goto label_00007822;
    label_0000781D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40781Du);
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->eax = lift_load32(cpu->eax);
    label_00007822: cpu->eip = LIFT_CODE_TOKEN_VA(0x407822u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_00007872;
    cpu->eax = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebp))) goto label_00007832;
    cpu->ecx = lift_load32(cpu->ecx);
    goto label_00007815;
    label_00007832: cpu->eip = LIFT_CODE_TOKEN_VA(0x407832u);
    cpu->ebp = lift_load32(cpu->ebp);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00007840: cpu->eip = LIFT_CODE_TOKEN_VA(0x407840u);
    if ((uint32_t)(cpu->ebx) != (uint32_t)(cpu->edx)) goto label_00007848;
    cpu->eax = cpu->edx;
    goto label_0000784D;
    label_00007848: cpu->eip = LIFT_CODE_TOKEN_VA(0x407848u);
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->eax = lift_load32(cpu->eax);
    label_0000784D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40784Du);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_0000785A;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(lift_load32(cpu->ecx + 8u))) goto label_0000785A;
    cpu->ecx = lift_load32(cpu->ecx);
    goto label_00007840;
    label_0000785A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40785Au);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->ecx)) goto label_00007872;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00007872: cpu->eip = LIFT_CODE_TOKEN_VA(0x407872u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00407890(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x407890u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = lift_load32(cpu->esi + 0x20u);
    lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4078A6u); lift_push32(cpu, r); sfera_sub_00403170(cpu,r); if (cpu->eip != r) return; }
    cpu->eax &= cpu->edi;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x24u)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000078B6;
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(1u), 32u);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->edi;
    cpu->eax += cpu->ecx;
    label_000078B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4078B6u);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 8u));
    cpu->edi = lift_load32(cpu->esi + 4u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 8u));
    cpu->edx = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    cpu->esi = 0x10u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000078E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4078E0u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edi)) goto label_000078E8;
    cpu->eax = cpu->edi;
    goto label_000078ED;
    label_000078E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4078E8u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax);
    label_000078ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4078EDu);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->eax)) goto label_000079CD;
    cpu->ebx = lift_load32(cpu->ebp + 0x10u);
    cpu->eax = (uint32_t)(cpu->edx + 8u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) < (uint32_t)(cpu->esi)) goto label_00007905;
    cpu->edx = lift_load32(cpu->ebp);
    goto label_00007907;
    label_00007905: cpu->eip = LIFT_CODE_TOKEN_VA(0x407905u);
    cpu->edx = cpu->ebp;
    label_00007907: cpu->eip = LIFT_CODE_TOKEN_VA(0x407907u);
    cpu->edi = lift_load32(cpu->eax + 0x10u);
    cpu->ecx = cpu->edi;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->edi)) goto label_00007910;
    label_00007910: cpu->eip = LIFT_CODE_TOKEN_VA(0x407910u);
    cpu->ecx = cpu->edi;
    if ((uint32_t)(cpu->edi) < (uint32_t)(cpu->ebx)) goto label_00007918;
    cpu->ecx = cpu->ebx;
    label_00007918: cpu->eip = LIFT_CODE_TOKEN_VA(0x407918u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->esi)) goto label_0000791F;
    cpu->eax = lift_load32(cpu->eax);
    label_0000791F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40791Fu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407927u); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0000793B;
    if ((uint32_t)(cpu->edi) < (uint32_t)(cpu->ebx)) goto label_0000793B;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00007953;
    label_0000793B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40793Bu);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    goto label_000078E0;
    label_00007953: cpu->eip = LIFT_CODE_TOKEN_VA(0x407953u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ebx = lift_load32(cpu->eax + 0x18u);
    cpu->eax += 8u;
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->esi)) goto label_00007964;
    cpu->eax = lift_load32(cpu->eax);
    label_00007964: cpu->eip = LIFT_CODE_TOKEN_VA(0x407964u);
    cpu->edi = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = cpu->edi;
    cpu->edx = cpu->edi;
    if ((uint32_t)(cpu->edi) < (uint32_t)(cpu->ebx)) goto label_00007971;
    cpu->edx = cpu->ebx;
    label_00007971: cpu->eip = LIFT_CODE_TOKEN_VA(0x407971u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) < (uint32_t)(cpu->esi)) goto label_0000797B;
    cpu->ecx = lift_load32(cpu->ebp);
    goto label_0000797D;
    label_0000797B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40797Bu);
    cpu->ecx = cpu->ebp;
    label_0000797D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40797Du);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407985u); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00007999;
    if ((uint32_t)(cpu->edi) < (uint32_t)(cpu->ebx)) goto label_00007999;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000079B7;
    label_00007999: cpu->eip = LIFT_CODE_TOKEN_VA(0x407999u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 8u, stop_address); return;
    label_000079B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4079B7u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 8u, stop_address); return;
    label_000079CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4079CDu);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->eax, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004079E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4079E0u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = lift_load32(cpu->edi + 0x20u);
    lift_push32(cpu, cpu->ebp);
    lift_store32(cpu->esp + 0x24u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4079FAu); lift_push32(cpu, r); sfera_sub_00403170(cpu,r); if (cpu->eip != r) return; }
    cpu->eax &= cpu->esi;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + 0x24u)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00007A0A;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(1u), 32u);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->esi;
    cpu->eax += cpu->ecx;
    label_00007A0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x407A0Au);
    cpu->edx = lift_load32(cpu->edi + 0x10u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 8u));
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->ebx = cpu->ecx;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    label_00007A28: cpu->eip = LIFT_CODE_TOKEN_VA(0x407A28u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_00007A30;
    cpu->eax = cpu->edx;
    goto label_00007A35;
    label_00007A30: cpu->eip = LIFT_CODE_TOKEN_VA(0x407A30u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax);
    label_00007A35: cpu->eip = LIFT_CODE_TOKEN_VA(0x407A35u);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->eax)) goto label_00007BB0;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_load32(cpu->ebp + 0x10u);
    cpu->eax = (uint32_t)(cpu->ebx + 8u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00007A4E;
    cpu->edx = lift_load32(cpu->ebp);
    goto label_00007A50;
    label_00007A4E: cpu->eip = LIFT_CODE_TOKEN_VA(0x407A4Eu);
    cpu->edx = cpu->ebp;
    label_00007A50: cpu->eip = LIFT_CODE_TOKEN_VA(0x407A50u);
    cpu->esi = lift_load32(cpu->eax + 0x10u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->esi)) goto label_00007A59;
    label_00007A59: cpu->eip = LIFT_CODE_TOKEN_VA(0x407A59u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->edi)) goto label_00007A61;
    cpu->ecx = cpu->edi;
    label_00007A61: cpu->eip = LIFT_CODE_TOKEN_VA(0x407A61u);
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_00007A69;
    cpu->eax = lift_load32(cpu->eax);
    label_00007A69: cpu->eip = LIFT_CODE_TOKEN_VA(0x407A69u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407A71u); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00007A85;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->edi)) goto label_00007A85;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00007A9F;
    label_00007A85: cpu->eip = LIFT_CODE_TOKEN_VA(0x407A85u);
    cpu->ecx = lift_load32(cpu->ebx);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->ebx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    goto label_00007A28;
    label_00007A9F: cpu->eip = LIFT_CODE_TOKEN_VA(0x407A9Fu);
    cpu->edx = lift_load32(cpu->ebp + 0x14u);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    label_00007AB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x407AB0u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) == (uint32_t)(cpu->eax)) goto label_00007AC3;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->edx);
    label_00007AC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x407AC3u);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->eax)) goto label_00007B91;
    cpu->eax = (uint32_t)(cpu->ebx + 8u);
    cpu->ebx = lift_load32(cpu->eax + 0x10u);
    cpu->esi = 0x10u;
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->esi)) goto label_00007ADD;
    cpu->eax = lift_load32(cpu->eax);
    label_00007ADD: cpu->eip = LIFT_CODE_TOKEN_VA(0x407ADDu);
    cpu->edi = lift_load32(cpu->ebp + 0x10u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->edi)) goto label_00007AE6;
    cpu->edi = cpu->ecx;
    label_00007AE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x407AE6u);
    cpu->edx = cpu->edi;
    if ((uint32_t)(cpu->edi) < (uint32_t)(cpu->ebx)) goto label_00007AEE;
    cpu->edx = cpu->ebx;
    label_00007AEE: cpu->eip = LIFT_CODE_TOKEN_VA(0x407AEEu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x24u)) < (uint32_t)(cpu->esi)) goto label_00007AF9;
    cpu->esi = lift_load32(cpu->ebp);
    goto label_00007AFB;
    label_00007AF9: cpu->eip = LIFT_CODE_TOKEN_VA(0x407AF9u);
    cpu->esi = cpu->ebp;
    label_00007AFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x407AFBu);
    cpu->ecx = cpu->eax;
    if ((uint32_t)(cpu->edx) < (uint32_t)(4u)) goto label_00007B16;
    label_00007B02: cpu->eip = LIFT_CODE_TOKEN_VA(0x407B02u);
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->ecx))) goto label_00007B1A;
    cpu->edx -= 4u;
    cpu->ecx += 4u;
    cpu->esi += 4u;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(4u)) goto label_00007B02;
    label_00007B16: cpu->eip = LIFT_CODE_TOKEN_VA(0x407B16u);
    if ((uint32_t)(cpu->edx) == 0u) goto label_00007B65;
    label_00007B1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x407B1Au);
    cpu->ebp = lift_load8(cpu->ecx);
    cpu->eax = lift_load8(cpu->esi);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00007B55;
    if ((uint32_t)(cpu->edx) <= (uint32_t)(1u)) goto label_00007B61;
    cpu->eax = lift_load8(cpu->esi + 1u);
    cpu->ebp = lift_load8(cpu->ecx + 1u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00007B55;
    if ((uint32_t)(cpu->edx) <= (uint32_t)(2u)) goto label_00007B61;
    cpu->eax = lift_load8(cpu->esi + 2u);
    cpu->ebp = lift_load8(cpu->ecx + 2u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00007B55;
    if ((uint32_t)(cpu->edx) <= (uint32_t)(3u)) goto label_00007B61;
    cpu->eax = lift_load8(cpu->esi + 3u);
    cpu->ecx = lift_load8(cpu->ecx + 3u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    label_00007B55: cpu->eip = LIFT_CODE_TOKEN_VA(0x407B55u);
    cpu->ebp = lift_load32(cpu->esp + 0x38u);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax |= 1u;
    goto label_00007B67;
    label_00007B61: cpu->eip = LIFT_CODE_TOKEN_VA(0x407B61u);
    cpu->ebp = lift_load32(cpu->esp + 0x38u);
    label_00007B65: cpu->eip = LIFT_CODE_TOKEN_VA(0x407B65u);
    cpu->eax = 0u;
    label_00007B67: cpu->eip = LIFT_CODE_TOKEN_VA(0x407B67u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00007B8D;
    if ((uint32_t)(cpu->edi) < (uint32_t)(cpu->ebx)) goto label_00007B8D;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00007B8D;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->ebx = cpu->eax;
    goto label_00007AB0;
    label_00007B8D: cpu->eip = LIFT_CODE_TOKEN_VA(0x407B8Du);
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    label_00007B91: cpu->eip = LIFT_CODE_TOKEN_VA(0x407B91u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00007BAC;
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 8u, stop_address); return;
    label_00007BAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x407BACu);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    label_00007BB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x407BB0u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00407BD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x407BD0u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 0x1F31Du); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ldiv), LIFT_CODE_TOKEN_VA(0x407BE1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x407BE7u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x41A7u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xB14u);
    cpu->esp += 8u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00007C00;
    cpu->edx += 0x7FFFFFFFu;
    label_00007C00: cpu->eip = LIFT_CODE_TOKEN_VA(0x407C00u);
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= cpu->edx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x24u)), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00007C15;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->eax;
    cpu->ecx += cpu->edx;
    label_00007C15: cpu->eip = LIFT_CODE_TOKEN_VA(0x407C15u);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 8u));
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(lift_load32(cpu->edx + 4u)) != (uint32_t)(cpu->eax)) goto label_00007C41;
    if ((uint32_t)(lift_load32(cpu->edx)) != (uint32_t)(cpu->eax)) goto label_00007C39;
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edx, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->ecx) * 8u) + 4u, cpu->eax);
    goto label_00007C49;
    label_00007C39: cpu->eip = LIFT_CODE_TOKEN_VA(0x407C39u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx + 4u, cpu->ecx);
    goto label_00007C49;
    label_00007C41: cpu->eip = LIFT_CODE_TOKEN_VA(0x407C41u);
    if ((uint32_t)(lift_load32(cpu->edx)) != (uint32_t)(cpu->eax)) goto label_00007C4D;
    cpu->eax = lift_load32(cpu->eax);
    lift_store32(cpu->edx, cpu->eax);
    label_00007C49: cpu->eip = LIFT_CODE_TOKEN_VA(0x407C49u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    label_00007C4D: cpu->eip = LIFT_CODE_TOKEN_VA(0x407C4Du);
    cpu->edi = lift_load32(cpu->eax);
    cpu->ecx = cpu->eax;
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00007C6F;
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx, cpu->edi);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->edx + 4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407C69u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 8u, (uint64_t)(lift_load32(cpu->esi + 8u)) - 1u);
    label_00007C6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x407C6Fu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00407C80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x407C80u);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->esi);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x15555554u)) goto label_00007CC4;
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) == (uint32_t)(0u)) goto label_00007CB0;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407CA4u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407CADu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00007CB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x407CB0u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x407CB6u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, (uint32_t)(uintptr_t)"map/set<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x7CC4u);
    label_00007CC4: cpu->eip = LIFT_CODE_TOKEN_VA(0x407CC4u);
    ++cpu->eax;
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->ebp + 4u, cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_00007CEE;
    lift_store32(cpu->edx + 4u, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->edx, cpu->ebp);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 8u, cpu->ebp);
    goto label_00007D0F;
    label_00007CEE: cpu->eip = LIFT_CODE_TOKEN_VA(0x407CEEu);
    if ((uint8_t)(lift_load8(cpu->esp + 0x14u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00007D01;
    lift_store32(cpu->eax, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx))) goto label_00007D0F;
    lift_store32(cpu->edx, cpu->ebp);
    goto label_00007D0F;
    label_00007D01: cpu->eip = LIFT_CODE_TOKEN_VA(0x407D01u);
    lift_store32(cpu->eax + 8u, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_00007D0F;
    lift_store32(cpu->edx + 8u, cpu->ebp);
    label_00007D0F: cpu->eip = LIFT_CODE_TOKEN_VA(0x407D0Fu);
    cpu->edx = lift_load32(cpu->ebp + 4u);
    cpu->eax = cpu->ebp;
    if ((uint8_t)(lift_load8(cpu->edx + 0x18u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00007EAD;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edi;
    label_00007D20: cpu->eip = LIFT_CODE_TOKEN_VA(0x407D20u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->esi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esi))) goto label_00007DEF;
    cpu->esi = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x18u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00007D52;
    lift_store8(cpu->edx + 0x18u, 1u);
    lift_store8(cpu->esi + 0x18u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x18u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    goto label_00007EA0;
    label_00007D52: cpu->eip = LIFT_CODE_TOKEN_VA(0x407D52u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_00007D91;
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->esi = lift_load32(cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx);
    if ((uint8_t)(lift_load8(cpu->esi + 0x19u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00007D6B;
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_00007D6B: cpu->eip = LIFT_CODE_TOKEN_VA(0x407D6Bu);
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx + 4u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00007D7E;
    lift_store32(cpu->esi + 4u, cpu->edx);
    goto label_00007D8C;
    label_00007D7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x407D7Eu);
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi))) goto label_00007D89;
    lift_store32(cpu->esi, cpu->edx);
    goto label_00007D8C;
    label_00007D89: cpu->eip = LIFT_CODE_TOKEN_VA(0x407D89u);
    lift_store32(cpu->esi + 8u, cpu->edx);
    label_00007D8C: cpu->eip = LIFT_CODE_TOKEN_VA(0x407D8Cu);
    lift_store32(cpu->edx, cpu->eax);
    lift_store32(cpu->eax + 4u, cpu->edx);
    label_00007D91: cpu->eip = LIFT_CODE_TOKEN_VA(0x407D91u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store8(cpu->edx + 0x18u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x18u, cpu->ebx & 0xFFu);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->esi = lift_load32(cpu->edx);
    cpu->edi = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->edx, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->edi + 0x19u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00007DB9;
    lift_store32(cpu->edi + 4u, cpu->edx);
    label_00007DB9: cpu->eip = LIFT_CODE_TOKEN_VA(0x407DB9u);
    cpu->edi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_00007DD2;
    lift_store32(cpu->edi + 4u, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_00007E9D;
    label_00007DD2: cpu->eip = LIFT_CODE_TOKEN_VA(0x407DD2u);
    cpu->edi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_00007DE5;
    lift_store32(cpu->edi + 8u, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_00007E9D;
    label_00007DE5: cpu->eip = LIFT_CODE_TOKEN_VA(0x407DE5u);
    lift_store32(cpu->edi, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_00007E9D;
    label_00007DEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x407DEFu);
    cpu->esi = lift_load32(cpu->esi);
    if ((uint8_t)(lift_load8(cpu->esi + 0x18u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00007E12;
    lift_store8(cpu->edx + 0x18u, 1u);
    lift_store8(cpu->esi + 0x18u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x18u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    goto label_00007EA0;
    label_00007E12: cpu->eip = LIFT_CODE_TOKEN_VA(0x407E12u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx))) goto label_00007E52;
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->edx + 8u);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x19u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00007E2A;
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_00007E2A: cpu->eip = LIFT_CODE_TOKEN_VA(0x407E2Au);
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx + 4u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00007E3D;
    lift_store32(cpu->esi + 4u, cpu->edx);
    goto label_00007E4C;
    label_00007E3D: cpu->eip = LIFT_CODE_TOKEN_VA(0x407E3Du);
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_00007E4A;
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_00007E4C;
    label_00007E4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x407E4Au);
    lift_store32(cpu->esi, cpu->edx);
    label_00007E4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x407E4Cu);
    lift_store32(cpu->edx + 8u, cpu->eax);
    lift_store32(cpu->eax + 4u, cpu->edx);
    label_00007E52: cpu->eip = LIFT_CODE_TOKEN_VA(0x407E52u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store8(cpu->edx + 0x18u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x18u, cpu->ebx & 0xFFu);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->esi = lift_load32(cpu->edx + 8u);
    cpu->edi = lift_load32(cpu->esi);
    lift_store32(cpu->edx + 8u, cpu->edi);
    cpu->edi = lift_load32(cpu->esi);
    if ((uint8_t)(lift_load8(cpu->edi + 0x19u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00007E7A;
    lift_store32(cpu->edi + 4u, cpu->edx);
    label_00007E7A: cpu->eip = LIFT_CODE_TOKEN_VA(0x407E7Au);
    cpu->edi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_00007E8D;
    lift_store32(cpu->edi + 4u, cpu->esi);
    goto label_00007E9B;
    label_00007E8D: cpu->eip = LIFT_CODE_TOKEN_VA(0x407E8Du);
    cpu->edi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi))) goto label_00007E98;
    lift_store32(cpu->edi, cpu->esi);
    goto label_00007E9B;
    label_00007E98: cpu->eip = LIFT_CODE_TOKEN_VA(0x407E98u);
    lift_store32(cpu->edi + 8u, cpu->esi);
    label_00007E9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x407E9Bu);
    lift_store32(cpu->esi, cpu->edx);
    label_00007E9D: cpu->eip = LIFT_CODE_TOKEN_VA(0x407E9Du);
    lift_store32(cpu->edx + 4u, cpu->esi);
    label_00007EA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x407EA0u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x18u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00007D20;
    cpu->edi = lift_pop32(cpu);
    label_00007EAD: cpu->eip = LIFT_CODE_TOKEN_VA(0x407EADu);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax, cpu->ebp);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    lift_store8(cpu->ecx + 0x18u, 1u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00408150(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x408150u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 0x10u);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx = 0u;
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000081A2;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    label_00008162: cpu->eip = LIFT_CODE_TOKEN_VA(0x408162u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->ebx)) goto label_0000816D;
    cpu->eax = lift_load32(cpu->eax);
    ++cpu->edx;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_00008162;
    label_0000816D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40816Du);
    cpu->ebx = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_000081A2;
    if ((uint8_t)(lift_load8(cpu->ecx + 8u)) == (uint8_t)(0u)) goto label_0000818D;
    if ((uint32_t)(lift_load32(cpu->ecx + 0x1Cu)) != (uint32_t)(cpu->eax)) goto label_0000818D;
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->ecx + 0x1Cu, cpu->edx);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->esi)) goto label_0000818D;
    lift_store8(cpu->ecx + 8u, 0u);
    label_0000818D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40818Du);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ecx + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40819Bu); lift_push32(cpu, r); sfera_sub_00406BA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000081A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4081A2u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004081B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4081B0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + 8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (uint32_t)(cpu->ebx + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000081E0;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebx + 0x20u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(lift_load32(cpu->ebx + 0x10u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(2u), 32u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4081D1u); lift_push32(cpu, r); sfera_sub_004BDF90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 0x10u);
    cpu->edi = lift_pop32(cpu);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebx + 0x20u, cpu->edx);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000081E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4081E0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4081E6u); lift_push32(cpu, r); sfera_sub_004BDF90(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004081F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4081F0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + 8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (uint32_t)(cpu->ebx + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00008220;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebx + 0x20u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(lift_load32(cpu->ebx + 0x10u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(2u), 32u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408211u); lift_push32(cpu, r); sfera_sub_00406C10(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 0x10u);
    cpu->edi = lift_pop32(cpu);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebx + 0x20u, cpu->edx);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00008220: cpu->eip = LIFT_CODE_TOKEN_VA(0x408220u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408226u); lift_push32(cpu, r); sfera_sub_00406C10(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00408230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x408230u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + 8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (uint32_t)(cpu->ebx + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000825C;
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebx + 0x20u);
    cpu->edi -= lift_load32(cpu->ebx + 0x10u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40824Eu); lift_push32(cpu, r); sfera_sub_00406C80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 0x10u);
    cpu->ecx += cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebx + 0x20u, cpu->ecx);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0000825C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40825Cu);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408266u); lift_push32(cpu, r); sfera_sub_00406C80(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00408270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x408270u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 8u)) == (uint8_t)(0u)) goto label_000082A4;
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    cpu->ecx = lift_load32(cpu->ebp);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax + 0xCu))) goto label_000082A3;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esi + 0x14u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408299u); lift_push32(cpu, r); sfera_sub_004B1370(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x20u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000082A3;
    lift_store8(cpu->esi + 8u, 0u);
    label_000082A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4082A3u);
    cpu->edi = lift_pop32(cpu);
    label_000082A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4082A4u);
    lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4082B2u); lift_push32(cpu, r); sfera_sub_004033F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4082C9u); lift_push32(cpu, r); sfera_sub_004B2C40(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004082E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4082E0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4082F3u); lift_push32(cpu, r); sfera_sub_004040B0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebx + 0x14u))) goto label_00008334;
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    cpu->eax += 0xCu;
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_0000830A;
    cpu->eax = lift_load32(cpu->eax);
    label_0000830A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40830Au);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408319u); lift_push32(cpu, r); sfera_sub_004027A0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_00008334;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->ebx + 0x14u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edx;
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00008334: cpu->eip = LIFT_CODE_TOKEN_VA(0x408334u);
    cpu->ecx = lift_load32(cpu->ebx + 0x14u);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->edx;
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040842B(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40842Bu);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408434u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408440u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x408440u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00408450(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x408450u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408463u); lift_push32(cpu, r); sfera_sub_00404900(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebx + 0x18u))) goto label_00008493;
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    cpu->eax += 0xCu;
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_0000847A;
    cpu->eax = lift_load32(cpu->eax);
    label_0000847A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40847Au);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408489u); lift_push32(cpu, r); sfera_sub_004027A0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_00008493;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    goto label_0000849E;
    label_00008493: cpu->eip = LIFT_CODE_TOKEN_VA(0x408493u);
    cpu->ecx = lift_load32(cpu->ebx + 0x18u);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    label_0000849E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40849Eu);
    cpu->eax = lift_load32(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->ebx + 0x18u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000084BF;
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0x28u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->eax + cpu->ecx, cpu->edx);
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000084BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4084BFu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004084D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4084D0u);
    cpu->esp -= 8u;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->ecx + 8u, 0u);
    cpu->esi = (uint32_t)(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4084ECu); lift_push32(cpu, r); sfera_sub_00403500(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408502u); lift_push32(cpu, r); sfera_sub_00406340(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00408510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x408510u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408523u); lift_push32(cpu, r); sfera_sub_00404900(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebx + 0x18u))) goto label_00008553;
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    cpu->eax += 0xCu;
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_0000853A;
    cpu->eax = lift_load32(cpu->eax);
    label_0000853A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40853Au);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408549u); lift_push32(cpu, r); sfera_sub_004027A0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_00008553;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    goto label_0000855E;
    label_00008553: cpu->eip = LIFT_CODE_TOKEN_VA(0x408553u);
    cpu->ecx = lift_load32(cpu->ebx + 0x18u);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    label_0000855E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40855Eu);
    cpu->eax = lift_load32(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->ebx + 0x18u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00008580;
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x28u));
    cpu->ecx = lift_load32(cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_store_f32(cpu->edx + cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00008580: cpu->eip = LIFT_CODE_TOKEN_VA(0x408580u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00408590(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x408590u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4085A3u); lift_push32(cpu, r); sfera_sub_00404B40(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebx + 0x18u))) goto label_000085D3;
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    cpu->eax += 0xCu;
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_000085BA;
    cpu->eax = lift_load32(cpu->eax);
    label_000085BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4085BAu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4085C9u); lift_push32(cpu, r); sfera_sub_004027A0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000085D3;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    goto label_000085DE;
    label_000085D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4085D3u);
    cpu->ecx = lift_load32(cpu->ebx + 0x18u);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    label_000085DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4085DEu);
    cpu->eax = lift_load32(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->ebx + 0x18u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000085FA;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = (uint32_t)(cpu->eax + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4085F4u); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000085FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4085FAu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00408610(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x408610u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408623u); lift_push32(cpu, r); sfera_sub_00404D80(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebx + 0x18u))) goto label_00008653;
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    cpu->eax += 0xCu;
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_0000863A;
    cpu->eax = lift_load32(cpu->eax);
    label_0000863A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40863Au);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408649u); lift_push32(cpu, r); sfera_sub_004027A0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_00008653;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    goto label_0000865E;
    label_00008653: cpu->eip = LIFT_CODE_TOKEN_VA(0x408653u);
    cpu->ecx = lift_load32(cpu->ebx + 0x18u);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    label_0000865E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40865Eu);
    cpu->eax = lift_load32(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->ebx + 0x18u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000867A;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = (uint32_t)(cpu->eax + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408674u); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0000867A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40867Au);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00408690(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x408690u);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x9249248u)) goto label_000086D5;
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x20u)) < (uint32_t)(0x10u)) goto label_000086B2;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4086AFu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000086B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4086B2u);
    cpu->ebx = 0u;
    lift_store32(cpu->esi + 0x20u, 0xFu);
    lift_store32(cpu->esi + 0x1Cu, cpu->ebx);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0xCu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4086C7u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, (uint32_t)(uintptr_t)"map/set<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x86D5u);
    label_000086D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4086D5u);
    ++cpu->eax;
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->ebp + 4u, cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_000086FE;
    lift_store32(cpu->edx + 4u, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->edx, cpu->ebp);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 8u, cpu->ebp);
    goto label_0000871F;
    label_000086FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4086FEu);
    if ((uint8_t)(lift_load8(cpu->esp + 0x14u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00008711;
    lift_store32(cpu->eax, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx))) goto label_0000871F;
    lift_store32(cpu->edx, cpu->ebp);
    goto label_0000871F;
    label_00008711: cpu->eip = LIFT_CODE_TOKEN_VA(0x408711u);
    lift_store32(cpu->eax + 8u, cpu->ebp);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_0000871F;
    lift_store32(cpu->edx + 8u, cpu->ebp);
    label_0000871F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40871Fu);
    cpu->edx = lift_load32(cpu->ebp + 4u);
    cpu->eax = cpu->ebp;
    if ((uint8_t)(lift_load8(cpu->edx + 0x28u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000088BD;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edi;
    label_00008730: cpu->eip = LIFT_CODE_TOKEN_VA(0x408730u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->esi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esi))) goto label_000087FF;
    cpu->esi = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x28u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00008762;
    lift_store8(cpu->edx + 0x28u, 1u);
    lift_store8(cpu->esi + 0x28u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x28u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    goto label_000088B0;
    label_00008762: cpu->eip = LIFT_CODE_TOKEN_VA(0x408762u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx + 8u))) goto label_000087A1;
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->esi = lift_load32(cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx);
    if ((uint8_t)(lift_load8(cpu->esi + 0x29u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000877B;
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_0000877B: cpu->eip = LIFT_CODE_TOKEN_VA(0x40877Bu);
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx + 4u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0000878E;
    lift_store32(cpu->esi + 4u, cpu->edx);
    goto label_0000879C;
    label_0000878E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40878Eu);
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi))) goto label_00008799;
    lift_store32(cpu->esi, cpu->edx);
    goto label_0000879C;
    label_00008799: cpu->eip = LIFT_CODE_TOKEN_VA(0x408799u);
    lift_store32(cpu->esi + 8u, cpu->edx);
    label_0000879C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40879Cu);
    lift_store32(cpu->edx, cpu->eax);
    lift_store32(cpu->eax + 4u, cpu->edx);
    label_000087A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4087A1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store8(cpu->edx + 0x28u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x28u, cpu->ebx & 0xFFu);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->esi = lift_load32(cpu->edx);
    cpu->edi = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->edx, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->edi + 0x29u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000087C9;
    lift_store32(cpu->edi + 4u, cpu->edx);
    label_000087C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4087C9u);
    cpu->edi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_000087E2;
    lift_store32(cpu->edi + 4u, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_000088AD;
    label_000087E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4087E2u);
    cpu->edi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_000087F5;
    lift_store32(cpu->edi + 8u, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_000088AD;
    label_000087F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4087F5u);
    lift_store32(cpu->edi, cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_000088AD;
    label_000087FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4087FFu);
    cpu->esi = lift_load32(cpu->esi);
    if ((uint8_t)(lift_load8(cpu->esi + 0x28u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00008822;
    lift_store8(cpu->edx + 0x28u, 1u);
    lift_store8(cpu->esi + 0x28u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x28u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    goto label_000088B0;
    label_00008822: cpu->eip = LIFT_CODE_TOKEN_VA(0x408822u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->edx))) goto label_00008862;
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->edx + 8u);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x29u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000883A;
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_0000883A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40883Au);
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx + 4u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_0000884D;
    lift_store32(cpu->esi + 4u, cpu->edx);
    goto label_0000885C;
    label_0000884D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40884Du);
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0000885A;
    lift_store32(cpu->esi + 8u, cpu->edx);
    goto label_0000885C;
    label_0000885A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40885Au);
    lift_store32(cpu->esi, cpu->edx);
    label_0000885C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40885Cu);
    lift_store32(cpu->edx + 8u, cpu->eax);
    lift_store32(cpu->eax + 4u, cpu->edx);
    label_00008862: cpu->eip = LIFT_CODE_TOKEN_VA(0x408862u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store8(cpu->edx + 0x28u, 1u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store8(cpu->edx + 0x28u, cpu->ebx & 0xFFu);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->esi = lift_load32(cpu->edx + 8u);
    cpu->edi = lift_load32(cpu->esi);
    lift_store32(cpu->edx + 8u, cpu->edi);
    cpu->edi = lift_load32(cpu->esi);
    if ((uint8_t)(lift_load8(cpu->edi + 0x29u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000888A;
    lift_store32(cpu->edi + 4u, cpu->edx);
    label_0000888A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40888Au);
    cpu->edi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->esi + 4u, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_0000889D;
    lift_store32(cpu->edi + 4u, cpu->esi);
    goto label_000088AB;
    label_0000889D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40889Du);
    cpu->edi = lift_load32(cpu->edx + 4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->edi))) goto label_000088A8;
    lift_store32(cpu->edi, cpu->esi);
    goto label_000088AB;
    label_000088A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4088A8u);
    lift_store32(cpu->edi + 8u, cpu->esi);
    label_000088AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4088ABu);
    lift_store32(cpu->esi, cpu->edx);
    label_000088AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4088ADu);
    lift_store32(cpu->edx + 4u, cpu->esi);
    label_000088B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4088B0u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x28u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00008730;
    cpu->edi = lift_pop32(cpu);
    label_000088BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4088BDu);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax, cpu->ebp);
    cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store8(cpu->ecx + 0x28u, 1u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004088E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4088E0u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x15u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00008914;
    cpu->ecx = lift_load32(cpu->edx);
    label_00008900: cpu->eip = LIFT_CODE_TOKEN_VA(0x408900u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + 0xCu)) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_0000890A;
    cpu->eax = lift_load32(cpu->eax + 8u);
    goto label_0000890E;
    label_0000890A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40890Au);
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->eax);
    label_0000890E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40890Eu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x15u)) == (uint8_t)(0u)) goto label_00008900;
    label_00008914: cpu->eip = LIFT_CODE_TOKEN_VA(0x408914u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00008920;
    cpu->eax = lift_load32(cpu->edx);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->edi + 0xCu))) goto label_00008957;
    label_00008920: cpu->eip = LIFT_CODE_TOKEN_VA(0x408920u);
    cpu->ecx = lift_load32(cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_store32(cpu->esp + 8u, cpu->ecx);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x10u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40893Au); lift_push32(cpu, r); sfera_sub_0042A320(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408948u); lift_push32(cpu, r); sfera_sub_00406430(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax += 0x10u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
    label_00008957: cpu->eip = LIFT_CODE_TOKEN_VA(0x408957u);
    cpu->eax = (uint32_t)(cpu->edi + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00408970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x408970u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x15u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000089A4;
    cpu->ecx = lift_load32(cpu->edx);
    label_00008990: cpu->eip = LIFT_CODE_TOKEN_VA(0x408990u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + 0xCu)) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_0000899A;
    cpu->eax = lift_load32(cpu->eax + 8u);
    goto label_0000899E;
    label_0000899A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40899Au);
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->eax);
    label_0000899E: cpu->eip = LIFT_CODE_TOKEN_VA(0x40899Eu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x15u)) == (uint8_t)(0u)) goto label_00008990;
    label_000089A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4089A4u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(lift_load32(cpu->edi + 4u))) goto label_000089B0;
    cpu->eax = lift_load32(cpu->edx);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0xCu))) goto label_000089E5;
    label_000089B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4089B0u);
    cpu->ecx = lift_load32(cpu->edx);
    lift_x87_push(cpu, 0.0);
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 8u, cpu->ecx);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4089C8u); lift_push32(cpu, r); sfera_sub_00406590(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4089D6u); lift_push32(cpu, r); sfera_sub_00406430(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax += 0x10u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
    label_000089E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4089E5u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (uint32_t)(cpu->esi + 0x10u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004089F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4089F0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x19u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebx = cpu->ecx;
    cpu->esi = cpu->edi;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00008A40;
    label_00008A01: cpu->eip = LIFT_CODE_TOKEN_VA(0x408A01u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408A0Cu); lift_push32(cpu, r); sfera_sub_004089F0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + 0x14u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_load32(cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00008A2F;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408A23u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + 0x14u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408A2Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00008A2F: cpu->eip = LIFT_CODE_TOKEN_VA(0x408A2Fu);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408A35u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x19u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00008A01;
    label_00008A40: cpu->eip = LIFT_CODE_TOKEN_VA(0x408A40u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00408A50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x408A50u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi);
    cpu->esi = lift_load32(cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store32(cpu->edi + 4u, 0u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(lift_load32(cpu->edi))) goto label_00008AA3;
    lift_push32(cpu, cpu->ebx);
    label_00008A70: cpu->eip = LIFT_CODE_TOKEN_VA(0x408A70u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x10u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = lift_load32(cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00008A93;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408A87u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408A90u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00008A93: cpu->eip = LIFT_CODE_TOKEN_VA(0x408A93u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408A99u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = cpu->ebx;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(lift_load32(cpu->edi))) goto label_00008A70;
    cpu->ebx = lift_pop32(cpu);
    label_00008AA3: cpu->eip = LIFT_CODE_TOKEN_VA(0x408AA3u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00408AB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x408AB0u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x19u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    lift_store32(cpu->esp + 4u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00008ACD;
    lift_push32(cpu, (uint32_t)(uintptr_t)"invalid map/set<T> iterator");
    lift_trap(cpu, cpu->eip, "std::out_of_range");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x8ACDu);
    label_00008ACD: cpu->eip = LIFT_CODE_TOKEN_VA(0x408ACDu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->ebp = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408ADBu); lift_push32(cpu, r); sfera_sub_004023F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x19u)) == (uint8_t)(0u)) goto label_00008AE9;
    cpu->edi = lift_load32(cpu->ebp + 8u);
    goto label_00008B01;
    label_00008AE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x408AE9u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x19u)) == (uint8_t)(0u)) goto label_00008AF6;
    cpu->edi = cpu->ecx;
    goto label_00008B01;
    label_00008AF6: cpu->eip = LIFT_CODE_TOKEN_VA(0x408AF6u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebp)) goto label_00008B64;
    label_00008B01: cpu->eip = LIFT_CODE_TOKEN_VA(0x408B01u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x19u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_load32(cpu->ebp + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00008B0D;
    lift_store32(cpu->edi + 4u, cpu->esi);
    label_00008B0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x408B0Du);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->eax + 4u)) != (uint32_t)(cpu->ebp)) goto label_00008B1A;
    lift_store32(cpu->eax + 4u, cpu->edi);
    goto label_00008B25;
    label_00008B1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x408B1Au);
    if ((uint32_t)(lift_load32(cpu->esi)) != (uint32_t)(cpu->ebp)) goto label_00008B22;
    lift_store32(cpu->esi, cpu->edi);
    goto label_00008B25;
    label_00008B22: cpu->eip = LIFT_CODE_TOKEN_VA(0x408B22u);
    lift_store32(cpu->esi + 8u, cpu->edi);
    label_00008B25: cpu->eip = LIFT_CODE_TOKEN_VA(0x408B25u);
    cpu->ebx = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->ebx)) != (uint32_t)(cpu->ebp)) goto label_00008B3F;
    if ((uint8_t)(lift_load8(cpu->edi + 0x19u)) == (uint8_t)(0u)) goto label_00008B36;
    cpu->eax = cpu->esi;
    goto label_00008B3D;
    label_00008B36: cpu->eip = LIFT_CODE_TOKEN_VA(0x408B36u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8B3Du); lift_push32(cpu, r); sfera_sub_004023D0(cpu,r); if (cpu->eip != r) return; }
    label_00008B3D: cpu->eip = LIFT_CODE_TOKEN_VA(0x408B3Du);
    lift_store32(cpu->ebx, cpu->eax);
    label_00008B3F: cpu->eip = LIFT_CODE_TOKEN_VA(0x408B3Fu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(lift_load32(cpu->ebx + 8u)) != (uint32_t)(cpu->ebp)) goto label_00008BBC;
    if ((uint8_t)(lift_load8(cpu->edi + 0x19u)) == (uint8_t)(0u)) goto label_00008B58;
    cpu->eax = cpu->esi;
    lift_store32(cpu->ebx + 8u, cpu->eax);
    goto label_00008BBC;
    label_00008B58: cpu->eip = LIFT_CODE_TOKEN_VA(0x408B58u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408B5Fu); lift_push32(cpu, r); sfera_sub_004023B0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 8u, cpu->eax);
    goto label_00008BBC;
    label_00008B64: cpu->eip = LIFT_CODE_TOKEN_VA(0x408B64u);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp);
    lift_store32(cpu->eax, cpu->ecx);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->ebp + 8u))) goto label_00008B75;
    cpu->esi = cpu->eax;
    goto label_00008B8F;
    label_00008B75: cpu->eip = LIFT_CODE_TOKEN_VA(0x408B75u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x19u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00008B81;
    lift_store32(cpu->edi + 4u, cpu->esi);
    label_00008B81: cpu->eip = LIFT_CODE_TOKEN_VA(0x408B81u);
    lift_store32(cpu->esi, cpu->edi);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx + 4u, cpu->eax);
    label_00008B8F: cpu->eip = LIFT_CODE_TOKEN_VA(0x408B8Fu);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx + 4u)) != (uint32_t)(cpu->ebp)) goto label_00008B9C;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    goto label_00008BAA;
    label_00008B9C: cpu->eip = LIFT_CODE_TOKEN_VA(0x408B9Cu);
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(cpu->ebp)) goto label_00008BA7;
    lift_store32(cpu->ecx, cpu->eax);
    goto label_00008BAA;
    label_00008BA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x408BA7u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    label_00008BAA: cpu->eip = LIFT_CODE_TOKEN_VA(0x408BAAu);
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp + 0x18u)) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 0x18u)) & 0xFFu);
    lift_store8(cpu->eax + 0x18u, cpu->edx & 0xFFu);
    lift_store8(cpu->ebp + 0x18u, cpu->ecx & 0xFFu);
    label_00008BBC: cpu->eip = LIFT_CODE_TOKEN_VA(0x408BBCu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    if ((uint8_t)(lift_load8(cpu->ebp + 0x18u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00008CC6;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->eax + 4u))) goto label_00008CC3;
    label_00008BD7: cpu->eip = LIFT_CODE_TOKEN_VA(0x408BD7u);
    if ((uint8_t)(lift_load8(cpu->edi + 0x18u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00008CC3;
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->eax)) goto label_00008C4D;
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x18u)) != (uint8_t)(0u)) goto label_00008C03;
    lift_store8(cpu->eax + 0x18u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0x18u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408BFCu); lift_push32(cpu, r); sfera_sub_00402FC0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_00008C03: cpu->eip = LIFT_CODE_TOKEN_VA(0x408C03u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x19u)) != (uint8_t)(0u)) goto label_00008C7F;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x18u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00008C18;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x18u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00008C7B;
    label_00008C18: cpu->eip = LIFT_CODE_TOKEN_VA(0x408C18u);
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x18u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00008C36;
    cpu->edx = lift_load32(cpu->eax);
    lift_store8(cpu->edx + 0x18u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->eax + 0x18u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408C2Fu); lift_push32(cpu, r); sfera_sub_00403010(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_00008C36: cpu->eip = LIFT_CODE_TOKEN_VA(0x408C36u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x18u)) & 0xFFu);
    lift_store8(cpu->eax + 0x18u, cpu->edx & 0xFFu);
    lift_store8(cpu->esi + 0x18u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->eax + 0x18u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408C4Bu); lift_push32(cpu, r); sfera_sub_00402FC0(cpu,r); if (cpu->eip != r) return; }
    goto label_00008CC3;
    label_00008C4D: cpu->eip = LIFT_CODE_TOKEN_VA(0x408C4Du);
    if ((uint8_t)(lift_load8(cpu->eax + 0x18u)) != (uint8_t)(0u)) goto label_00008C66;
    lift_store8(cpu->eax + 0x18u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0x18u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408C60u); lift_push32(cpu, r); sfera_sub_00403010(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_00008C66: cpu->eip = LIFT_CODE_TOKEN_VA(0x408C66u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x19u)) != (uint8_t)(0u)) goto label_00008C7F;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x18u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00008C92;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x18u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00008C92;
    label_00008C7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x408C7Bu);
    lift_store8(cpu->eax + 0x18u, 0u);
    label_00008C7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x408C7Fu);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edi = cpu->esi;
    cpu->esi = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->eax + 4u))) goto label_00008BD7;
    goto label_00008CC3;
    label_00008C92: cpu->eip = LIFT_CODE_TOKEN_VA(0x408C92u);
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x18u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00008CAF;
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_store8(cpu->edx + 0x18u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->eax + 0x18u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408CA9u); lift_push32(cpu, r); sfera_sub_00402FC0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_00008CAF: cpu->eip = LIFT_CODE_TOKEN_VA(0x408CAFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x18u)) & 0xFFu);
    lift_store8(cpu->eax + 0x18u, cpu->edx & 0xFFu);
    lift_store8(cpu->esi + 0x18u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->eax + 0x18u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8CC3u); lift_push32(cpu, r); sfera_sub_00403010(cpu,r); if (cpu->eip != r) return; }
    label_00008CC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x408CC3u);
    lift_store8(cpu->edi + 0x18u, cpu->ebx & 0xFFu);
    label_00008CC6: cpu->eip = LIFT_CODE_TOKEN_VA(0x408CC6u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) == (uint32_t)(0u)) goto label_00008CE7;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408CDBu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408CE4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00008CE7: cpu->eip = LIFT_CODE_TOKEN_VA(0x408CE7u);
    lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408CEDu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00008D02;
    --cpu->eax;
    lift_store32(cpu->ecx + 8u, cpu->eax);
    label_00008D02: cpu->eip = LIFT_CODE_TOKEN_VA(0x408D02u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00408D20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x408D20u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(lift_load32(cpu->edi))) goto label_00008D7D;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edx + 4u, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->esi + 0x10u)) == (uint32_t)(0u)) goto label_00008D62;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408D56u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408D5Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00008D62: cpu->eip = LIFT_CODE_TOKEN_VA(0x408D62u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408D68u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->esp += 4u;
    lift_store32(cpu->edi + 4u, (uint64_t)(lift_load32(cpu->edi + 4u)) - 1u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00008D7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x408D7Du);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00408D90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x408D90u);
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
    cpu->edi = lift_load32(cpu->ebp + 0xCu);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00008F98;
    cpu->ebx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax = cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->edx = 0x3FFFFFFFu;
    cpu->edx -= cpu->eax;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->edi)) goto label_00008DEA;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x8DEAu);
    label_00008DEA: cpu->eip = LIFT_CODE_TOKEN_VA(0x408DEAu);
    cpu->edx = (uint32_t)(cpu->eax + cpu->edi);
    cpu->eax = lift_load32(cpu->esi + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_00008EE3;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    cpu->ebx = 0x3FFFFFFFu;
    cpu->ebx -= cpu->ecx;
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(cpu->eax)) goto label_00008E18;
    lift_store32(cpu->ebp + 0xCu, 0u);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    goto label_00008E1D;
    label_00008E18: cpu->eip = LIFT_CODE_TOKEN_VA(0x408E18u);
    cpu->eax += cpu->ecx;
    lift_store32(cpu->ebp + 0xCu, cpu->eax);
    label_00008E1D: cpu->eip = LIFT_CODE_TOKEN_VA(0x408E1Du);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edx)) goto label_00008E26;
    lift_store32(cpu->ebp + 0xCu, cpu->edx);
    cpu->eax = cpu->edx;
    label_00008E26: cpu->eip = LIFT_CODE_TOKEN_VA(0x408E26u);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408E2Fu); lift_push32(cpu, r); sfera_sub_0049F1D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(lift_load32(cpu->esi)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebx = v; }
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->eax);
    cpu->ebx = lift_shift_arithmetic(cpu, cpu->ebx, (uint32_t)(2u), 32u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ebx) * 4u));
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->edi;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408E59u); lift_push32(cpu, r); sfera_sub_00405050(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408E71u); lift_push32(cpu, r); sfera_sub_00405080(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->ebx + cpu->edi);
    cpu->ebx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->eax = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408E90u); lift_push32(cpu, r); sfera_sub_00405080(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->edi += cpu->ecx;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00008EA9;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408EA6u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00008EA9: cpu->eip = LIFT_CODE_TOKEN_VA(0x408EA9u);
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    cpu->eax = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->edx) * 4u));
    cpu->ecx = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->edi) * 4u));
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->ecx);
    lift_store32(cpu->esi, cpu->ebx);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_00008EE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x408EE3u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    cpu->eax = cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->edx);
    lift_store32(cpu->ebp + 0xCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_00008F57;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->edi) * 4u));
    lift_store32(cpu->ebp + 0x10u, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->eax += cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408F1Au); lift_push32(cpu, r); sfera_sub_00405080(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->edx = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->ebp + 8u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    lift_push32(cpu, cpu->eax);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    lift_push32(cpu, 0u);
    cpu->edi -= cpu->edx;
    cpu->eax = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->edi;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408F43u); lift_push32(cpu, r); sfera_sub_00405050(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx -= cpu->eax;
    goto label_00008F93;
    label_00008F57: cpu->eip = LIFT_CODE_TOKEN_VA(0x408F57u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edi) * 4u));
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esi + 0xCu);
    cpu->edi = cpu->ebx;
    lift_push32(cpu, cpu->edx);
    cpu->edi -= cpu->eax;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    lift_store32(cpu->ebp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408F79u); lift_push32(cpu, r); sfera_sub_00405080(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->edi;
    lift_store32(cpu->esi + 4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408F87u); lift_push32(cpu, r); sfera_sub_00403120(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->edx += cpu->ecx;
    label_00008F93: cpu->eip = LIFT_CODE_TOKEN_VA(0x408F93u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8F98u); lift_push32(cpu, r); sfera_sub_00403150(cpu,r); if (cpu->eip != r) return; }
    label_00008F98: cpu->eip = LIFT_CODE_TOKEN_VA(0x408F98u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00408ECE(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x408ECEu);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408ED7u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    sfera_sub_00408EDA(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00408EDA(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x408EDAu);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408EE3u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    cpu->eax = cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->edx);
    lift_store32(cpu->ebp + 0xCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_00008F57;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->edi) * 4u));
    lift_store32(cpu->ebp + 0x10u, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->eax += cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408F1Au); lift_push32(cpu, r); sfera_sub_00405080(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->edx = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->ebp + 8u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    lift_push32(cpu, cpu->eax);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    lift_push32(cpu, 0u);
    cpu->edi -= cpu->edx;
    cpu->eax = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->edi;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408F43u); lift_push32(cpu, r); sfera_sub_00405050(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx -= cpu->eax;
    goto label_00008F93;
    label_00008F57: cpu->eip = LIFT_CODE_TOKEN_VA(0x408F57u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edi) * 4u));
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esi + 0xCu);
    cpu->edi = cpu->ebx;
    lift_push32(cpu, cpu->edx);
    cpu->edi -= cpu->eax;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    lift_store32(cpu->ebp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408F79u); lift_push32(cpu, r); sfera_sub_00405080(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->edi;
    lift_store32(cpu->esi + 4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408F87u); lift_push32(cpu, r); sfera_sub_00403120(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->edx += cpu->ecx;
    label_00008F93: cpu->eip = LIFT_CODE_TOKEN_VA(0x408F93u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408F98u); lift_push32(cpu, r); sfera_sub_00403150(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00408FB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x408FB0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_00008FE9;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00008FC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x408FC0u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_00008FD1;
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408FCEu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00008FD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x408FD1u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store8(cpu->esi, 0u);
    cpu->esi += 0x1Cu;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->edi)) goto label_00008FC0;
    label_00008FE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x408FE9u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00408FF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x408FF0u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x19u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_store8(cpu->esp + 0x18u, cpu->ecx & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000903D;
    cpu->edx = lift_load32(cpu->ebx + 0xCu);
    label_00009011: cpu->eip = LIFT_CODE_TOKEN_VA(0x409011u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x1Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00009022;
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0xCu)), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_00009028;
    label_00009022: cpu->eip = LIFT_CODE_TOKEN_VA(0x409022u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->eax + 0xCu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u)) ? 1u : 0u) & 0xFFu);
    label_00009028: cpu->eip = LIFT_CODE_TOKEN_VA(0x409028u);
    lift_store8(cpu->esp + 0x18u, cpu->ecx & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_00009034;
    cpu->eax = lift_load32(cpu->eax);
    goto label_00009037;
    label_00009034: cpu->eip = LIFT_CODE_TOKEN_VA(0x409034u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    label_00009037: cpu->eip = LIFT_CODE_TOKEN_VA(0x409037u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x19u)) == (uint8_t)(0u)) goto label_00009011;
    label_0000903D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40903Du);
    cpu->ebp = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_0000907A;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->eax))) goto label_00009071;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40905Eu); lift_push32(cpu, r); sfera_sub_00407C80(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->edx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_00009071: cpu->eip = LIFT_CODE_TOKEN_VA(0x409071u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409076u); lift_push32(cpu, r); sfera_sub_00402660(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    label_0000907A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40907Au);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0xCu))) goto label_000090A8;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409095u); lift_push32(cpu, r); sfera_sub_00407C80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_000090A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4090A8u);
    if ((uint32_t)(lift_load32(cpu->ebx + 0x14u)) == (uint32_t)(0u)) goto label_000090C9;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4090BDu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ebx + 0x14u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4090C6u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000090C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4090C9u);
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4090CFu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ebp);
    cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->eax + 4u, 0u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004090F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4090F0u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->edx;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store8(cpu->esi, 0u);
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    cpu->edi = cpu->edi;
    label_00009110: cpu->eip = LIFT_CODE_TOKEN_VA(0x409110u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00009110;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409122u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00409130(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x409130u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_0000919A;
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_0000914D;
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40914Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000914D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40914Du);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store8(cpu->esi, 0u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) >= (uint32_t)(0x10u)) goto label_00009176;
    cpu->ecx = lift_load32(cpu->edi + 0x10u);
    ++cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x40916Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x409171u);
    cpu->esp += 0xCu;
    goto label_00009180;
    label_00009176: cpu->eip = LIFT_CODE_TOKEN_VA(0x409176u);
    cpu->edx = lift_load32(cpu->edi);
    lift_store32(cpu->esi, cpu->edx);
    lift_store32(cpu->edi, 0u);
    label_00009180: cpu->eip = LIFT_CODE_TOKEN_VA(0x409180u);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x14u);
    lift_store32(cpu->esi + 0x14u, cpu->ecx);
    lift_store32(cpu->edi + 0x10u, 0u);
    lift_store32(cpu->edi + 0x14u, 0u);
    label_0000919A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40919Au);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00409790(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00009790;
    label_00008360: cpu->eip = LIFT_CODE_TOKEN_VA(0x408360u);
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
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(0x1FFFFFFFu)) goto label_000083A2;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x83A2u);
    label_000083A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4083A2u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(3u), 32u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_00008417;
    cpu->edi = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4083B9u); lift_push32(cpu, r); sfera_sub_00402BB0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->ebx = cpu->eax;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->ebx);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4083D7u); lift_push32(cpu, r); sfera_sub_00405010(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edi = cpu->edx;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(3u), 32u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0xFFFFFFFFu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00008406;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4083FBu); lift_push32(cpu, r); sfera_sub_004063F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x408403u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00008406: cpu->eip = LIFT_CODE_TOKEN_VA(0x408406u);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->eax = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->edx) * 8u));
    cpu->ecx = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->edi) * 8u));
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->ecx);
    lift_store32(cpu->esi, cpu->ebx);
    label_00008417: cpu->eip = LIFT_CODE_TOKEN_VA(0x408417u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00009790: cpu->eip = LIFT_CODE_TOKEN_VA(0x409790u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->edi);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edi = 0x1FFFFFFFu;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edi -= cpu->edx;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_000097B6;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x97B6u);
    label_000097B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4097B6u);
    cpu->eax += cpu->edx;
    cpu->edx = lift_load32(cpu->ecx + 8u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000097EA;
    cpu->esi = cpu->edx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(1u), 32u);
    cpu->edi = 0x1FFFFFFFu;
    cpu->edi -= cpu->esi;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->edx)) goto label_000097D7;
    cpu->edx = 0u;
    goto label_000097D9;
    label_000097D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4097D7u);
    cpu->edx += cpu->esi;
    label_000097D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4097D9u);
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->eax)) goto label_000097DF;
    cpu->edx = cpu->eax;
    label_000097DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4097DFu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->esp + 4u, cpu->edx);
    goto label_00008360;
    label_000097EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4097EAu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004097F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4097F0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->edi = cpu->esi;
    if ((uint8_t)(lift_load8(cpu->esi + 0x29u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0000983F;
    label_00009803: cpu->eip = LIFT_CODE_TOKEN_VA(0x409803u);
    cpu->eax = lift_load32(cpu->edi + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40980Eu); lift_push32(cpu, r); sfera_sub_004097F0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x20u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_load32(cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00009822;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40981Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00009822: cpu->eip = LIFT_CODE_TOKEN_VA(0x409822u);
    lift_store32(cpu->esi + 0x20u, 0xFu);
    lift_store32(cpu->esi + 0x1Cu, cpu->ebx);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0xCu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409835u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = cpu->edi;
    if ((uint8_t)(lift_load8(cpu->edi + 0x29u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00009803;
    label_0000983F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40983Fu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00409850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x409850u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x29u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    lift_store32(cpu->esp + 4u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000986D;
    lift_push32(cpu, (uint32_t)(uintptr_t)"invalid map/set<T> iterator");
    lift_trap(cpu, cpu->eip, "std::out_of_range");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x986Du);
    label_0000986D: cpu->eip = LIFT_CODE_TOKEN_VA(0x40986Du);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->ebp = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40987Bu); lift_push32(cpu, r); sfera_sub_00402AF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x29u)) == (uint8_t)(0u)) goto label_00009889;
    cpu->edi = lift_load32(cpu->ebp + 8u);
    goto label_000098A1;
    label_00009889: cpu->eip = LIFT_CODE_TOKEN_VA(0x409889u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x29u)) == (uint8_t)(0u)) goto label_00009896;
    cpu->edi = cpu->ecx;
    goto label_000098A1;
    label_00009896: cpu->eip = LIFT_CODE_TOKEN_VA(0x409896u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebp)) goto label_00009904;
    label_000098A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4098A1u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x29u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_load32(cpu->ebp + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000098AD;
    lift_store32(cpu->edi + 4u, cpu->esi);
    label_000098AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4098ADu);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->eax + 4u)) != (uint32_t)(cpu->ebp)) goto label_000098BA;
    lift_store32(cpu->eax + 4u, cpu->edi);
    goto label_000098C5;
    label_000098BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4098BAu);
    if ((uint32_t)(lift_load32(cpu->esi)) != (uint32_t)(cpu->ebp)) goto label_000098C2;
    lift_store32(cpu->esi, cpu->edi);
    goto label_000098C5;
    label_000098C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4098C2u);
    lift_store32(cpu->esi + 8u, cpu->edi);
    label_000098C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4098C5u);
    cpu->ebx = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->ebx)) != (uint32_t)(cpu->ebp)) goto label_000098DF;
    if ((uint8_t)(lift_load8(cpu->edi + 0x29u)) == (uint8_t)(0u)) goto label_000098D6;
    cpu->eax = cpu->esi;
    goto label_000098DD;
    label_000098D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4098D6u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x98DDu); lift_push32(cpu, r); sfera_sub_004020E0(cpu,r); if (cpu->eip != r) return; }
    label_000098DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4098DDu);
    lift_store32(cpu->ebx, cpu->eax);
    label_000098DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4098DFu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(lift_load32(cpu->ebx + 8u)) != (uint32_t)(cpu->ebp)) goto label_0000995C;
    if ((uint8_t)(lift_load8(cpu->edi + 0x29u)) == (uint8_t)(0u)) goto label_000098F8;
    cpu->eax = cpu->esi;
    lift_store32(cpu->ebx + 8u, cpu->eax);
    goto label_0000995C;
    label_000098F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4098F8u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4098FFu); lift_push32(cpu, r); sfera_sub_00402120(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 8u, cpu->eax);
    goto label_0000995C;
    label_00009904: cpu->eip = LIFT_CODE_TOKEN_VA(0x409904u);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp);
    lift_store32(cpu->eax, cpu->ecx);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->ebp + 8u))) goto label_00009915;
    cpu->esi = cpu->eax;
    goto label_0000992F;
    label_00009915: cpu->eip = LIFT_CODE_TOKEN_VA(0x409915u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x29u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00009921;
    lift_store32(cpu->edi + 4u, cpu->esi);
    label_00009921: cpu->eip = LIFT_CODE_TOKEN_VA(0x409921u);
    lift_store32(cpu->esi, cpu->edi);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->edx + 4u, cpu->eax);
    label_0000992F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40992Fu);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx + 4u)) != (uint32_t)(cpu->ebp)) goto label_0000993C;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    goto label_0000994A;
    label_0000993C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40993Cu);
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(cpu->ebp)) goto label_00009947;
    lift_store32(cpu->ecx, cpu->eax);
    goto label_0000994A;
    label_00009947: cpu->eip = LIFT_CODE_TOKEN_VA(0x409947u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    label_0000994A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40994Au);
    cpu->ecx = lift_load32(cpu->ebp + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp + 0x28u)) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 0x28u)) & 0xFFu);
    lift_store8(cpu->eax + 0x28u, cpu->edx & 0xFFu);
    lift_store8(cpu->ebp + 0x28u, cpu->ecx & 0xFFu);
    label_0000995C: cpu->eip = LIFT_CODE_TOKEN_VA(0x40995Cu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    if ((uint8_t)(lift_load8(cpu->ebp + 0x28u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00009A66;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->eax + 4u))) goto label_00009A63;
    label_00009977: cpu->eip = LIFT_CODE_TOKEN_VA(0x409977u);
    if ((uint8_t)(lift_load8(cpu->edi + 0x28u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00009A63;
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->eax)) goto label_000099ED;
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x28u)) != (uint8_t)(0u)) goto label_000099A3;
    lift_store8(cpu->eax + 0x28u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0x28u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40999Cu); lift_push32(cpu, r); sfera_sub_00402C10(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_000099A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4099A3u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x29u)) != (uint8_t)(0u)) goto label_00009A1F;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x28u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000099B8;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x28u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00009A1B;
    label_000099B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4099B8u);
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x28u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000099D6;
    cpu->edx = lift_load32(cpu->eax);
    lift_store8(cpu->edx + 0x28u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->eax + 0x28u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4099CFu); lift_push32(cpu, r); sfera_sub_00402C60(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_000099D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4099D6u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x28u)) & 0xFFu);
    lift_store8(cpu->eax + 0x28u, cpu->edx & 0xFFu);
    lift_store8(cpu->esi + 0x28u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->eax + 0x28u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4099EBu); lift_push32(cpu, r); sfera_sub_00402C10(cpu,r); if (cpu->eip != r) return; }
    goto label_00009A63;
    label_000099ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4099EDu);
    if ((uint8_t)(lift_load8(cpu->eax + 0x28u)) != (uint8_t)(0u)) goto label_00009A06;
    lift_store8(cpu->eax + 0x28u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esi + 0x28u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409A00u); lift_push32(cpu, r); sfera_sub_00402C60(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_00009A06: cpu->eip = LIFT_CODE_TOKEN_VA(0x409A06u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x29u)) != (uint8_t)(0u)) goto label_00009A1F;
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((uint8_t)(lift_load8(cpu->edx + 0x28u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00009A32;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x28u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00009A32;
    label_00009A1B: cpu->eip = LIFT_CODE_TOKEN_VA(0x409A1Bu);
    lift_store8(cpu->eax + 0x28u, 0u);
    label_00009A1F: cpu->eip = LIFT_CODE_TOKEN_VA(0x409A1Fu);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edi = cpu->esi;
    cpu->esi = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->eax + 4u))) goto label_00009977;
    goto label_00009A63;
    label_00009A32: cpu->eip = LIFT_CODE_TOKEN_VA(0x409A32u);
    cpu->edx = lift_load32(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->edx + 0x28u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00009A4F;
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_store8(cpu->edx + 0x28u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->eax + 0x28u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409A49u); lift_push32(cpu, r); sfera_sub_00402C10(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_00009A4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x409A4Fu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x28u)) & 0xFFu);
    lift_store8(cpu->eax + 0x28u, cpu->edx & 0xFFu);
    lift_store8(cpu->esi + 0x28u, cpu->ebx & 0xFFu);
    cpu->eax = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->eax + 0x28u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9A63u); lift_push32(cpu, r); sfera_sub_00402C60(cpu,r); if (cpu->eip != r) return; }
    label_00009A63: cpu->eip = LIFT_CODE_TOKEN_VA(0x409A63u);
    lift_store8(cpu->edi + 0x28u, cpu->ebx & 0xFFu);
    label_00009A66: cpu->eip = LIFT_CODE_TOKEN_VA(0x409A66u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x20u)) < (uint32_t)(0x10u)) goto label_00009A78;
    cpu->ecx = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409A75u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00009A78: cpu->eip = LIFT_CODE_TOKEN_VA(0x409A78u);
    lift_store32(cpu->ebp + 0x20u, 0xFu);
    lift_store32(cpu->ebp + 0x1Cu, 0u);
    lift_push32(cpu, cpu->ebp);
    lift_store8(cpu->ebp + 0xCu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409A90u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00009AA5;
    --cpu->eax;
    lift_store32(cpu->ecx + 8u, cpu->eax);
    label_00009AA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x409AA5u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00409AC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x409AC0u);
    cpu->esp -= 0xCu;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->eax;
    cpu->ebp += 0xCu;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + 0x29u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_store8(cpu->esp + 0x10u, cpu->eax & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00009BBC;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00009AF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x409AF0u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x28u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->ebx + 0xCu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00009B52;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) < (uint32_t)(0x10u)) goto label_00009B09;
    cpu->edx = lift_load32(cpu->ebp);
    goto label_00009B0B;
    label_00009B09: cpu->eip = LIFT_CODE_TOKEN_VA(0x409B09u);
    cpu->edx = cpu->ebp;
    label_00009B0B: cpu->eip = LIFT_CODE_TOKEN_VA(0x409B0Bu);
    cpu->esi = lift_load32(cpu->eax + 0x10u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->esi)) goto label_00009B14;
    label_00009B14: cpu->eip = LIFT_CODE_TOKEN_VA(0x409B14u);
    cpu->edi = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->edi)) goto label_00009B1F;
    cpu->ecx = cpu->edi;
    label_00009B1F: cpu->eip = LIFT_CODE_TOKEN_VA(0x409B1Fu);
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_00009B27;
    cpu->eax = lift_load32(cpu->eax);
    label_00009B27: cpu->eip = LIFT_CODE_TOKEN_VA(0x409B27u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409B2Fu); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00009B4D;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->edi)) goto label_00009B44;
    cpu->eax |= 0xFFFFFFFFu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_00009B9B;
    label_00009B44: cpu->eip = LIFT_CODE_TOKEN_VA(0x409B44u);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_00009B4D: cpu->eip = LIFT_CODE_TOKEN_VA(0x409B4Du);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_00009B9B;
    label_00009B52: cpu->eip = LIFT_CODE_TOKEN_VA(0x409B52u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_load32(cpu->eax + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00009B5D;
    cpu->eax = lift_load32(cpu->eax);
    label_00009B5D: cpu->eip = LIFT_CODE_TOKEN_VA(0x409B5Du);
    cpu->esi = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->edi)) goto label_00009B6A;
    cpu->edx = cpu->edi;
    label_00009B6A: cpu->eip = LIFT_CODE_TOKEN_VA(0x409B6Au);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) < (uint32_t)(0x10u)) goto label_00009B75;
    cpu->ecx = lift_load32(cpu->ebp);
    goto label_00009B77;
    label_00009B75: cpu->eip = LIFT_CODE_TOKEN_VA(0x409B75u);
    cpu->ecx = cpu->ebp;
    label_00009B77: cpu->eip = LIFT_CODE_TOKEN_VA(0x409B77u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409B7Fu); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00009B98;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->edi)) goto label_00009B8F;
    cpu->eax |= 0xFFFFFFFFu;
    goto label_00009B96;
    label_00009B8F: cpu->eip = LIFT_CODE_TOKEN_VA(0x409B8Fu);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    label_00009B96: cpu->eip = LIFT_CODE_TOKEN_VA(0x409B96u);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    label_00009B98: cpu->eip = LIFT_CODE_TOKEN_VA(0x409B98u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_SF) != 0u)) ? 1u : 0u) & 0xFFu);
    label_00009B9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x409B9Bu);
    lift_store8(cpu->esp + 0x10u, cpu->eax & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00009BA7;
    cpu->ebx = lift_load32(cpu->ebx);
    goto label_00009BAA;
    label_00009BA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x409BA7u);
    cpu->ebx = lift_load32(cpu->ebx + 8u);
    label_00009BAA: cpu->eip = LIFT_CODE_TOKEN_VA(0x409BAAu);
    if ((uint8_t)(lift_load8(cpu->ebx + 0x29u)) == (uint8_t)(0u)) goto label_00009AF0;
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    label_00009BBC: cpu->eip = LIFT_CODE_TOKEN_VA(0x409BBCu);
    cpu->esi = cpu->edi;
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00009C02;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->eax))) goto label_00009BF5;
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    label_00009BDA: cpu->eip = LIFT_CODE_TOKEN_VA(0x409BDAu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409BDFu); lift_push32(cpu, r); sfera_sub_00408690(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
    label_00009BF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x409BF5u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409BFEu); lift_push32(cpu, r); sfera_sub_004021A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x28u);
    label_00009C02: cpu->eip = LIFT_CODE_TOKEN_VA(0x409C02u);
    cpu->edx = lift_load32(cpu->ebp + 0x10u);
    cpu->ebx = 0x10u;
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) < (uint32_t)(cpu->ebx)) goto label_00009C17;
    cpu->eax = lift_load32(cpu->ebp);
    goto label_00009C19;
    label_00009C17: cpu->eip = LIFT_CODE_TOKEN_VA(0x409C17u);
    cpu->eax = cpu->ebp;
    label_00009C19: cpu->eip = LIFT_CODE_TOKEN_VA(0x409C19u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409C26u); lift_push32(cpu, r); sfera_sub_004027A0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00009C40;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx);
    goto label_00009BDA;
    label_00009C40: cpu->eip = LIFT_CODE_TOKEN_VA(0x409C40u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x14u)) < (uint32_t)(cpu->ebx)) goto label_00009C51;
    cpu->edx = lift_load32(cpu->ebp);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409C4Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00009C51: cpu->eip = LIFT_CODE_TOKEN_VA(0x409C51u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->ebp + 0x14u, 0xFu);
    lift_store32(cpu->ebp + 0x10u, 0u);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->ebp, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409C6Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->eax + 4u, 0u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00409C90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x409C90u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409CA5u); lift_push32(cpu, r); sfera_sub_00407550(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x18u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00009CC5;
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->eax + cpu->ecx, cpu->edx);
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_00009CC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x409CC5u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00409CD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x409CD0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409CE5u); lift_push32(cpu, r); sfera_sub_00407890(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x18u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00009D05;
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0x24u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->eax + cpu->ecx, cpu->edx);
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_00009D05: cpu->eip = LIFT_CODE_TOKEN_VA(0x409D05u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00409D10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x409D10u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409D25u); lift_push32(cpu, r); sfera_sub_00407610(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x18u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00009D45;
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0x10u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->eax + cpu->ecx, cpu->edx);
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_00009D45: cpu->eip = LIFT_CODE_TOKEN_VA(0x409D45u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00409D50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x409D50u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409D65u); lift_push32(cpu, r); sfera_sub_00407550(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x18u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00009D86;
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    cpu->ecx = lift_load32(cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_store_f32(cpu->edx + cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_00009D86: cpu->eip = LIFT_CODE_TOKEN_VA(0x409D86u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00409D90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x409D90u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409DA5u); lift_push32(cpu, r); sfera_sub_00407890(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x18u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00009DC6;
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x24u));
    cpu->ecx = lift_load32(cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_store_f32(cpu->edx + cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_00009DC6: cpu->eip = LIFT_CODE_TOKEN_VA(0x409DC6u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00409DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x409DD0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409DE5u); lift_push32(cpu, r); sfera_sub_00407610(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x18u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00009E06;
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    cpu->ecx = lift_load32(cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_store_f32(cpu->edx + cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_00009E06: cpu->eip = LIFT_CODE_TOKEN_VA(0x409E06u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00409E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x409E10u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409E25u); lift_push32(cpu, r); sfera_sub_00407550(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x18u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00009E40;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409E3Bu); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_00009E40: cpu->eip = LIFT_CODE_TOKEN_VA(0x409E40u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00409E50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x409E50u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409E65u); lift_push32(cpu, r); sfera_sub_00407890(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x18u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00009E80;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409E7Bu); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_00009E80: cpu->eip = LIFT_CODE_TOKEN_VA(0x409E80u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00409E90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x409E90u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409EA5u); lift_push32(cpu, r); sfera_sub_00407610(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x18u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00009EC0;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409EBBu); lift_push32(cpu, r); sfera_sub_004031C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_00009EC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x409EC0u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00409ED0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x409ED0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409EE5u); lift_push32(cpu, r); sfera_sub_00407550(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x18u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00009F00;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409EFBu); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_00009F00: cpu->eip = LIFT_CODE_TOKEN_VA(0x409F00u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00409F10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x409F10u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409F25u); lift_push32(cpu, r); sfera_sub_00407890(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x18u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00009F40;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409F3Bu); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_00009F40: cpu->eip = LIFT_CODE_TOKEN_VA(0x409F40u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00409F50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x409F50u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409F65u); lift_push32(cpu, r); sfera_sub_00407610(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x18u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00009F80;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409F7Bu); lift_push32(cpu, r); sfera_sub_00401CD0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_return(cpu, 8u, stop_address); return;
    label_00009F80: cpu->eip = LIFT_CODE_TOKEN_VA(0x409F80u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00409F90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x409F90u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax))) goto label_00009FDA;
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->eax)) goto label_00009FDA;
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x409FB2u); lift_push32(cpu, r); sfera_sub_004089F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->esi + 8u, 0u);
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_00009FDA: cpu->eip = LIFT_CODE_TOKEN_VA(0x409FDAu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0000A04F;
    cpu->edi = cpu->edi;
    label_00009FE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x409FE0u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + 0x19u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edx = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000A038;
    cpu->eax = lift_load32(cpu->ecx + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x19u)) != (uint8_t)(0u)) goto label_0000A010;
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->eax + 0x19u)) != (uint8_t)(0u)) goto label_0000A00A;
    label_0000A000: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A000u);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint8_t)(lift_load8(cpu->eax + 0x19u)) == (uint8_t)(0u)) goto label_0000A000;
    label_0000A00A: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A00Au);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    goto label_0000A038;
    label_0000A010: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A010u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x19u)) != (uint8_t)(0u)) goto label_0000A034;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0000A020: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A020u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_0000A034;
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->eax = lift_load32(cpu->eax + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x19u)) == (uint8_t)(0u)) goto label_0000A020;
    label_0000A034: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A034u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    label_0000A038: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A038u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A045u); lift_push32(cpu, r); sfera_sub_00408AB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_00009FE0;
    label_0000A04F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A04Fu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040A060(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40A060u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi);
    cpu->esi = lift_load32(cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store32(cpu->edi + 4u, 0u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(lift_load32(cpu->edi))) goto label_0000A0B3;
    lift_push32(cpu, cpu->ebx);
    label_0000A080: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A080u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0xCu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = lift_load32(cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000A0A3;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A097u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A0A0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000A0A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A0A3u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A0A9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = cpu->ebx;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(lift_load32(cpu->edi))) goto label_0000A080;
    cpu->ebx = lift_pop32(cpu);
    label_0000A0B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A0B3u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040A0C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40A0C0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx);
    cpu->edi = lift_load32(cpu->eax);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->eax);
    lift_store32(cpu->ebx + 4u, 0u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->ebx))) goto label_0000A167;
    label_0000A0FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A0FDu);
    cpu->ebp = lift_load32(cpu->edi);
    cpu->esi = (uint32_t)(cpu->edi + 8u);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0xCu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x20u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000A12F;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A123u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A12Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000A12F: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A12Fu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0000A158;
    cpu->edx = 0x27u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A14Cu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A155u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0000A158: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A158u);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A15Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->edi = cpu->ebp;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(lift_load32(cpu->ebx))) goto label_0000A0FD;
    label_0000A167: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A167u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040A180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40A180u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, 0x1F31Du); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ldiv), LIFT_CODE_TOKEN_VA(0x40A191u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x40A197u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x41A7u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xB14u);
    cpu->esp += 8u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0000A1B0;
    cpu->edx += 0x7FFFFFFFu;
    label_0000A1B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A1B0u);
    cpu->ecx = lift_load32(cpu->esi + 0x20u);
    cpu->eax = cpu->ecx;
    cpu->eax &= cpu->edx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x24u)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0000A1C5;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->ecx;
    cpu->eax += cpu->edx;
    label_0000A1C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A1C5u);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 8u) + 4u)), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 8u));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0000A1F2;
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(cpu->edx)) goto label_0000A1EA;
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->eax) * 8u) + 4u, cpu->edx);
    goto label_0000A1FA;
    label_0000A1EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A1EAu);
    cpu->eax = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    goto label_0000A1FA;
    label_0000A1F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A1F2u);
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(cpu->edx)) goto label_0000A1FE;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->ecx, cpu->edx);
    label_0000A1FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A1FAu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    label_0000A1FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A1FEu);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esi + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A20Cu); lift_push32(cpu, r); sfera_sub_00408D20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0040A220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x40A220u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(lift_load32(cpu->edi))) goto label_0000A258;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->edx + 4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A248u); lift_push32(cpu, r); sfera_sub_00403C10(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x40A24Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->esp += 4u;
    lift_store32(cpu->edi + 4u, (uint64_t)(lift_load32(cpu->edi + 4u)) - 1u);
    label_0000A258: cpu->eip = LIFT_CODE_TOKEN_VA(0x40A258u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}
