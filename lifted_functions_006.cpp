#include "lifted_functions.h"
#include <cmath>
namespace lifted {

struct SferaMbInterObjectProfile {
    uint32_t factory_kind;
    uint8_t property_274;
    uint8_t property_275;
    uint8_t property_276;
    uint8_t property_277;
};
static SferaMbInterObjectProfile sfera_mbinter_object_profile(uint32_t kind) {
    switch (kind) {
        case 0u: return SferaMbInterObjectProfile{0u, 0u, 0u, 0u, 0u};
        case 1u: return SferaMbInterObjectProfile{1u, 0u, 1u, 0u, 0u};
        case 2u: return SferaMbInterObjectProfile{2u, 0u, 1u, 1u, 0u};
        case 3u: return SferaMbInterObjectProfile{3u, 0u, 1u, 1u, 0u};
        case 4u: return SferaMbInterObjectProfile{1u, 0u, 1u, 0u, 0u};
        case 5u: return SferaMbInterObjectProfile{4u, 0u, 0u, 1u, 1u};
        case 6u: return SferaMbInterObjectProfile{5u, 0u, 0u, 1u, 0u};
        case 7u: return SferaMbInterObjectProfile{6u, 0u, 0u, 0u, 0u};
        case 8u: return SferaMbInterObjectProfile{4u, 0u, 0u, 0u, 0u};
        case 9u: return SferaMbInterObjectProfile{5u, 0u, 0u, 0u, 0u};
        case 0xAu: return SferaMbInterObjectProfile{3u, 1u, 1u, 1u, 0u};
        default: return SferaMbInterObjectProfile{0u, 0u, 0u, 0u, 0u};
    }
}
__declspec(noinline) void sfera_sub_004398D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = g_sfera_mbc_runtime->argument_count;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = (int8_t)(*(uint8_t*)(cpu->eax));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    ++cpu->eax;
    cpu->edi = 0u;
    cpu->esi = 0u;
    g_sfera_mbc_runtime->instruction_cursor = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((int32_t)cpu->ebp >= (int32_t)cpu->edi) goto label_00039938;
    cpu->edx = cpu->ecx + cpu->ebp;
    cpu->edx = 0u - (uint64_t)(cpu->edx);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    cpu->edx = cpu->ebp;
    cpu->edx = 0u - (uint64_t)(cpu->edx);
    { uint64_t l=cpu->edx, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_00039930;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Wrong number of parameters (must be %d, present %d)"); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->text_buffer[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x439912u));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->text_buffer[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x439925u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x439925u));
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = g_sfera_mbc_runtime->argument_count;
    label_00039930:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp = cpu->ecx;
    goto label_00039975;
    label_00039938:
    { uint64_t l=cpu->ebp, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00039975;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Wrong number of parameters (must be %d, present %d)"); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->text_buffer[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x439948u));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->text_buffer[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43995Bu)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x43995Bu));
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    { uint64_t l=cpu->ebp, r=cpu->eax, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00039970;
    { uint64_t l=cpu->ebp, r=cpu->eax, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebp = v; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp = cpu->eax;
    label_00039970:
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    label_00039975:
    cpu->ebx = g_sfera_mbc_runtime->argument_cursor;
    cpu->ebx <<= 5u;
    cpu->ebx += ((uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    if ((int32_t)cpu->ebp <= (int32_t)cpu->edi) goto label_00039A51;
    cpu->edi = cpu->ebx + 0x14u;
    (void)cpu;
    label_00039990:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebx));
    ++cpu->eax;
    g_sfera_mbc_runtime->instruction_cursor = cpu->eax;
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    cpu->eax += 4u;
    g_sfera_mbc_runtime->instruction_cursor = cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0x10u) goto label_000399C5;
    if ((cpu->edx & 0xFFu) != 0x20u) goto label_000399BF;
    lift_x87_push(cpu, (double)*(float*)(cpu->edi));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4399BBu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4399BBu));
    *(uint32_t*)(cpu->esi) = cpu->eax;
    goto label_00039A37;
    label_000399BF:
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    goto label_00039A37;
    label_000399C5:
    if ((cpu->ecx & 0xFFu) != 0x20u) goto label_000399DA;
    if ((cpu->edx & 0xFFu) != (cpu->ecx & 0xFFu)) goto label_000399D4;
    lift_x87_push(cpu, (double)*(float*)(cpu->edi));
    *(float*)(cpu->esi) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_00039A37;
    label_000399D4:
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->edi)))));
    *(float*)(cpu->esi) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_00039A37;
    label_000399DA:
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000399FE;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000399E8;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    *(uint8_t*)(cpu->esi) = cpu->ecx & 0xFFu;
    goto label_00039A37;
    label_000399E8:
    if ((cpu->edx & 0xFFu) != 0x20u) goto label_000399F8;
    lift_x87_push(cpu, (double)*(float*)(cpu->edi));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4399F4u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4399F4u));
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    goto label_00039A37;
    label_000399F8:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    *(uint8_t*)(cpu->esi) = cpu->edx & 0xFFu;
    goto label_00039A37;
    label_000399FE:
    if ((cpu->edx & 0xFFu) != 0x20u) goto label_00039A13;
    lift_x87_push(cpu, (double)*(float*)(cpu->edi));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x439A0Au)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x439A0Au));
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    goto label_00039A34;
    label_00039A13:
    if ((cpu->edx & 0xFFu) == 0x10u) goto label_00039A1C;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00039A27;
    label_00039A1C:
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    goto label_00039A34;
    label_00039A27:
    cpu->ecx = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 8u);
    label_00039A34:
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    label_00039A37:
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    --cpu->ebp;
    cpu->ebx += 0x20u;
    cpu->edi += 0x20u;
    if ((int32_t)cpu->ebp > 0) goto label_00039990;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = 0u;
    label_00039A51:
    lift_x87_push(cpu, 0.0);
    { uint64_t l=cpu->esi, r=4u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00039B7E;
    cpu->ebx = cpu->esi + 0xFFFFFFFCu;
    cpu->ebx >>= 2u;
    ++cpu->ebx;
    cpu->ecx = cpu->ebx;
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->edx = cpu->esi + (cpu->ecx * 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    label_00039A6E:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    g_sfera_mbc_runtime->instruction_cursor = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->ecx += g_sfera_mbc_runtime->process_memory_base;
    cpu->eax += 4u;
    g_sfera_mbc_runtime->instruction_cursor = cpu->eax;
    if ((cpu->edx & 0xFFu) != 0x10u) goto label_00039A8F;
    *(uint32_t*)(cpu->ecx) = cpu->edi;
    goto label_00039AA8;
    label_00039A8F:
    if ((cpu->edx & 0xFFu) != 0x20u) goto label_00039A98;
    *(float*)(cpu->ecx) = cpu->fpu[0u];
    goto label_00039AA8;
    label_00039A98:
    if ((cpu->edx & 0xFFu) != 0u) goto label_00039AA0;
    *(uint8_t*)(cpu->ecx) = cpu->edx & 0xFFu;
    goto label_00039AA8;
    label_00039AA0:
    *(uint32_t*)(cpu->ecx) = cpu->edi;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->edi;
    label_00039AA8:
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    ++cpu->ecx;
    g_sfera_mbc_runtime->instruction_cursor = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += 4u;
    g_sfera_mbc_runtime->instruction_cursor = cpu->ecx;
    if ((cpu->edx & 0xFFu) != 0x10u) goto label_00039AD1;
    *(uint32_t*)(cpu->eax) = cpu->edi;
    goto label_00039AEA;
    label_00039AD1:
    if ((cpu->edx & 0xFFu) != 0x20u) goto label_00039ADA;
    *(float*)(cpu->eax) = cpu->fpu[0u];
    goto label_00039AEA;
    label_00039ADA:
    if ((cpu->edx & 0xFFu) != 0u) goto label_00039AE2;
    *(uint8_t*)(cpu->eax) = cpu->edx & 0xFFu;
    goto label_00039AEA;
    label_00039AE2:
    *(uint32_t*)(cpu->eax) = cpu->edi;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edi;
    label_00039AEA:
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    ++cpu->ecx;
    g_sfera_mbc_runtime->instruction_cursor = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += 4u;
    g_sfera_mbc_runtime->instruction_cursor = cpu->ecx;
    if ((cpu->edx & 0xFFu) != 0x10u) goto label_00039B13;
    *(uint32_t*)(cpu->eax) = cpu->edi;
    goto label_00039B2C;
    label_00039B13:
    if ((cpu->edx & 0xFFu) != 0x20u) goto label_00039B1C;
    *(float*)(cpu->eax) = cpu->fpu[0u];
    goto label_00039B2C;
    label_00039B1C:
    if ((cpu->edx & 0xFFu) != 0u) goto label_00039B24;
    *(uint8_t*)(cpu->eax) = cpu->edx & 0xFFu;
    goto label_00039B2C;
    label_00039B24:
    *(uint32_t*)(cpu->eax) = cpu->edi;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edi;
    label_00039B2C:
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    ++cpu->ecx;
    g_sfera_mbc_runtime->instruction_cursor = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += 4u;
    g_sfera_mbc_runtime->instruction_cursor = cpu->ecx;
    if ((cpu->edx & 0xFFu) != 0x10u) goto label_00039B55;
    *(uint32_t*)(cpu->eax) = cpu->edi;
    goto label_00039B6E;
    label_00039B55:
    if ((cpu->edx & 0xFFu) != 0x20u) goto label_00039B5E;
    *(float*)(cpu->eax) = cpu->fpu[0u];
    goto label_00039B6E;
    label_00039B5E:
    if ((cpu->edx & 0xFFu) != 0u) goto label_00039B66;
    *(uint8_t*)(cpu->eax) = cpu->edx & 0xFFu;
    goto label_00039B6E;
    label_00039B66:
    *(uint32_t*)(cpu->eax) = cpu->edi;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edi;
    label_00039B6E:
    { uint64_t l=cpu->ebx, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00039A6E;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    label_00039B7E:
    if ((int32_t)cpu->esi <= (int32_t)cpu->edi) goto label_00039BC4;
    goto label_00039B89;
    label_00039B84:
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    label_00039B89:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    g_sfera_mbc_runtime->instruction_cursor = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->ecx += g_sfera_mbc_runtime->process_memory_base;
    cpu->eax += 4u;
    g_sfera_mbc_runtime->instruction_cursor = cpu->eax;
    if ((cpu->edx & 0xFFu) == 0x10u) goto label_00039BBD;
    if ((cpu->edx & 0xFFu) != 0x20u) goto label_00039BAF;
    *(float*)(cpu->ecx) = cpu->fpu[0u];
    goto label_00039BBF;
    label_00039BAF:
    if ((cpu->edx & 0xFFu) != 0u) goto label_00039BB7;
    *(uint8_t*)(cpu->ecx) = cpu->edx & 0xFFu;
    goto label_00039BBF;
    label_00039BB7:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->edi;
    label_00039BBD:
    *(uint32_t*)(cpu->ecx) = cpu->edi;
    label_00039BBF:
    --cpu->esi;
    if ((int32_t)cpu->esi > (int32_t)cpu->edi) goto label_00039B84;
    label_00039BC4:
    cpu->edi = lift_pop32(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00439BD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = g_sfera_mbc_runtime->call_frame_depth;
    --cpu->ecx;
    g_sfera_mbc_runtime->value_stack_size = cpu->ecx;
    { uint64_t l=cpu->ecx, r=g_sfera_mbc_runtime->frame_stack_base[cpu->eax], v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_00039BF5;
    cpu->ecx = (uintptr_t)"fo31(): stack underflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_00039BF5:
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    cpu->eax += ((uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    cpu->edx = 0u;
    { uint64_t l=*(uint32_t*)(cpu->eax + 0x14u), r=cpu->edx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    ++cpu->ecx;
    g_sfera_mbc_runtime->value_stack_size = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->eax + 0x10u) = 1u;
    *(uint32_t*)(cpu->eax + 0xCu) = 1u;
    *(uint32_t*)(cpu->eax) = 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00439C30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->edx = 0u;
    if ((int32_t)cpu->ecx < (int32_t)cpu->edx) goto label_0003A280;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x398u);
    cpu->ecx += ((uintptr_t)&g_sfera_world_slot_table_runtime.slots[0].object_handle);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    { uint64_t l=*(uint8_t*)(cpu->ebp + 0x10u), r=4u, v=l & r; lift_flags_logic(cpu,v,8u); }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003A27F;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x14u);
    if (cpu->ecx > 0xFFFFu) goto label_0003A27F;
    cpu->eax = cpu->ecx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if (*(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id)) != cpu->ecx) goto label_0003A27F;
    if ((int32_t)*(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index)) < (int32_t)cpu->edx) goto label_0003A27F;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ebx);
    { uint64_t l=cpu->eax, r=1u, v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00039CB9;
    cpu->esi = cpu->ebp + 0x2Cu;
    cpu->eax = cpu->ebp + 0x1BCu;
    *(uint32_t*)(cpu->esp + 0x24u) = 8u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    cpu->ebx = cpu->ebp + 0x28u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    goto label_00039D1C;
    label_00039CB9:
    cpu->ebx = cpu->ebp + 0x1C0u;
    cpu->ecx = cpu->ebp + 0x1C4u;
    cpu->eax = cpu->ebp + 0x354u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if (*(uint32_t*)(cpu->ebx) != cpu->edx) goto label_00039D1A;
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->esi = *(uint32_t*)(cpu->eax + 0x84u);
    cpu->esi += *(uint32_t*)(cpu->eax + 0x50u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x439CF0u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x439CF0u));
    *(uint32_t*)(cpu->ebp + 0x358u) = cpu->eax;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 4u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x439CFEu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x439CFEu));
    *(uint32_t*)(cpu->ebp + 0x35Cu) = cpu->eax;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 8u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x439D0Cu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x439D0Cu));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ebp + 0x360u) = cpu->eax;
    cpu->edx = 0u;
    goto label_00039D1C;
    label_00039D1A:
    cpu->esi = cpu->ecx;
    label_00039D1C:
    lift_push32(cpu, 0x200u); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->shared_buffer[0]);
    g_sfera_mbc_runtime->shared_buffer_size = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x439D2Du));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0x258240u); lift_push32(cpu, 7u); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->ecx);
    ++cpu->edi;
    cpu->edx = (uintptr_t)&g_sfera_mbc_runtime->shared_buffer_size;
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->shared_buffer[0];
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x439D57u)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_VA(0x439D57u));
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    if ((int32_t)g_sfera_mbc_runtime->send_field_count <= (int32_t)cpu->eax) goto label_0003A047;
    label_00039D70:
    { uint64_t l=g_sfera_mbc_runtime->shared_buffer_size, r=0x1000u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_x87_push(cpu, 0.0);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0003A02D;
    cpu->esi = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_mbc_interpreter_storage.send_field_data[0]));
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_runtime->send_field_width[0])));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((int32_t)cpu->eax > (int32_t)0x20u) goto label_00039DAD;
    lift_push32(cpu, 0x258240u);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    goto label_00039FDA;
    label_00039DAD:
    if (cpu->eax != 0x6Cu) goto label_00039E36;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u];
    lift_x87_compare(cpu, cpu->fpu[0u], -1000.0);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00039DD8;
    lift_x87_compare(cpu, cpu->fpu[0u], 1000.0);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00039DE0;
    label_00039DD8:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_00039E04;
    label_00039DE0:
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00039E02;
    label_00039DE9:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (6.2831854820251465);
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_compare(cpu, cpu->fpu[0u], ((double)*(float*)(cpu->esp + 0x30u)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00039DE9;
    label_00039E02:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00039E04:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (40.7436637878418);
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x439E1Bu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x439E1Bu));
    lift_push32(cpu, 0x258240u);
    cpu->eax &= 0xFFu;
    lift_push32(cpu, 8u);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x3Cu;
    goto label_00039FD9;
    label_00039E36:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (cpu->eax != 0x69u) goto label_00039E6C;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x358u);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x439E50u)); sfera_sub_00437BF0(cpu, LIFT_CODE_TOKEN_VA(0x439E50u));
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    if (cpu->eax == 0xFFFFFFFFu) goto label_00039ED3;
    lift_push32(cpu, 0x258240u); lift_push32(cpu, 0xCu); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->ecx);
    goto label_00039FDA;
    label_00039E6C:
    if (cpu->eax != 0x6Au) goto label_00039EA0;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x35Cu);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x439E84u)); sfera_sub_00437BF0(cpu, LIFT_CODE_TOKEN_VA(0x439E84u));
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    if (cpu->eax == 0xFFFFFFFFu) goto label_00039ED3;
    lift_push32(cpu, 0x258240u); lift_push32(cpu, 0xCu); lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->edx);
    goto label_00039FDA;
    label_00039EA0:
    if (cpu->eax != 0x6Bu) goto label_00039EE0;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x360u);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x439EB8u)); sfera_sub_00437BF0(cpu, LIFT_CODE_TOKEN_VA(0x439EB8u));
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    if (cpu->eax == 0xFFFFFFFFu) goto label_00039ED3;
    lift_push32(cpu, 0x258240u); lift_push32(cpu, 0xCu); lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x3Cu;
    goto label_00039FD9;
    label_00039ED3:
    *(uint32_t*)(cpu->esp + 0x18u) = 1u;
    goto label_00039FE9;
    label_00039EE0:
    if (cpu->eax != 0x67u) goto label_00039FE9;
    cpu->edi = 0u;
    if ((int32_t)cpu->esi >= (int32_t)cpu->edi) goto label_00039EFF;
    cpu->esi = 0u - (uint64_t)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x30u) = 1u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    goto label_00039F03;
    label_00039EFF:
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    label_00039F03:
    lift_push32(cpu, 0x258240u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uintptr_t)&g_sfera_mbc_runtime->shared_buffer_size;
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->shared_buffer[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x439F1Fu)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_VA(0x439F1Fu));
    lift_push32(cpu, 0x258240u); lift_push32(cpu, 2u); lift_push32(cpu, cpu->edi);
    if ((int32_t)cpu->esi >= (int32_t)8u) goto label_00039F50;
    cpu->edx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uintptr_t)&g_sfera_mbc_runtime->shared_buffer_size;
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->shared_buffer[0];
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x439F44u)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_VA(0x439F44u));
    lift_push32(cpu, 0x258240u); lift_push32(cpu, 3u);
    goto label_00039FD4;
    label_00039F50:
    if ((int32_t)cpu->esi >= (int32_t)0x80u) goto label_00039F83;
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uintptr_t)&g_sfera_mbc_runtime->shared_buffer_size;
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->shared_buffer[0];
    *(uint32_t*)(cpu->esp + 0x40u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x439F74u)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_VA(0x439F74u));
    lift_push32(cpu, 0x258240u); lift_push32(cpu, 7u); lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    goto label_00039FDA;
    label_00039F83:
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->shared_buffer[0];
    if ((int32_t)cpu->esi >= (int32_t)0x4000u) goto label_00039FB6;
    cpu->eax = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uintptr_t)&g_sfera_mbc_runtime->shared_buffer_size;
    *(uint32_t*)(cpu->esp + 0x40u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x439FA7u)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_VA(0x439FA7u));
    lift_push32(cpu, 0x258240u); lift_push32(cpu, 0xEu); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    goto label_00039FDA;
    label_00039FB6:
    cpu->edx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uintptr_t)&g_sfera_mbc_runtime->shared_buffer_size;
    *(uint32_t*)(cpu->esp + 0x40u) = 3u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x439FCDu)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_VA(0x439FCDu));
    lift_push32(cpu, 0x258240u); lift_push32(cpu, 0x1Fu);
    label_00039FD4:
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edi);
    label_00039FD9:
    lift_push32(cpu, cpu->eax);
    label_00039FDA:
    cpu->edx = (uintptr_t)&g_sfera_mbc_runtime->shared_buffer_size;
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->shared_buffer[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x39FE9u)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_RVA(0x39FE9u));
    label_00039FE9:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)g_sfera_mbc_runtime->send_field_count) goto label_00039D70;
    if (*(uint32_t*)(cpu->esp + 0x18u) == 0u) goto label_0003A043;
    lift_push32(cpu, 0x200u); lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->shared_buffer[0]);
    g_sfera_mbc_runtime->shared_buffer_size = 0u;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x43A01Bu));
    cpu->esp += 0xCu;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0003A02D:
    cpu->ecx = (uintptr_t)"Too long data for region";
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A039u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x43A039u));
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0003A043:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    label_0003A047:
    cpu->eax = *(uint32_t*)(cpu->ebx);
    if (cpu->eax == 0u) goto label_0003A0DF;
    cpu->ecx = g_sfera_mbc_runtime->shared_buffer_size;
    cpu->edx = cpu->eax + cpu->ecx + 0x25u;
    if ((int32_t)cpu->edx <= (int32_t)0x640u) goto label_0003A1D7;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    { uint64_t l=cpu->eax, r=7u, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (int32_t)(cpu->eax) >> 3u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A07Au)); sfera_sub_00432790(cpu, LIFT_CODE_TOKEN_VA(0x43A07Au));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, 0x190u); lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->eax) = 0xFFFFFFFFu;
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->ebx) = 0u;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x43A092u));
    cpu->esp += 0xCu;
    if (*(uint32_t*)(cpu->esp + 0x28u) != 0u) goto label_0003A0DF;
    cpu->edi = g_sfera_mbc_runtime->active_process;
    cpu->esi = *(uint32_t*)(cpu->edi + 0x84u);
    cpu->esi += *(uint32_t*)(cpu->edi + 0x50u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A0B7u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x43A0B7u));
    *(uint32_t*)(cpu->ebp + 0x358u) = cpu->eax;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 4u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A0C5u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x43A0C5u));
    *(uint32_t*)(cpu->ebp + 0x35Cu) = cpu->eax;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 8u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A0D3u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x43A0D3u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ebp + 0x360u) = cpu->eax;
    goto label_0003A0E5;
    label_0003A0DF:
    cpu->edi = g_sfera_mbc_runtime->active_process;
    label_0003A0E5:
    if (*(uint32_t*)(cpu->esp + 0x28u) != 0u) goto label_0003A189;
    if (((*(uint8_t*)(cpu->edi + 0x94u)) & (2u)) != 0u) goto label_0003A189;
    lift_push32(cpu, 0x190u); lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x40u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A11Cu)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_VA(0x43A11Cu));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x358u);
    lift_push32(cpu, 0x190u); lift_push32(cpu, 0x10u);
    cpu->edx += 0x8000u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x3Cu;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A143u)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_VA(0x43A143u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x35Cu);
    lift_push32(cpu, 0x190u); lift_push32(cpu, 0xDu);
    cpu->ecx += 0x4B0u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x3Cu;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A16Au)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_VA(0x43A16Au));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x360u);
    lift_push32(cpu, 0x190u); lift_push32(cpu, 0x10u);
    cpu->eax += 0x8000u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x3Cu;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    lift_push32(cpu, cpu->ecx);
    goto label_0003A19F;
    label_0003A189:
    lift_push32(cpu, 0x190u); lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x3Cu;
    *(uint32_t*)(cpu->esp + 0x3Cu) = 0u;
    lift_push32(cpu, cpu->edx);
    label_0003A19F:
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A1A8u)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_VA(0x43A1A8u));
    cpu->eax = g_sfera_recovered_static_runtime.simulation_tick;
    lift_push32(cpu, 0x190u); lift_push32(cpu, 0xFu); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x3Cu;
    cpu->eax = (int32_t)(cpu->eax) >> 3u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A1CBu)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_VA(0x43A1CBu));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->edi) = 0xFFFFFFFFu;
    goto label_0003A1DB;
    label_0003A1D7:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_0003A1DB:
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->edx = g_sfera_mbc_runtime->active_process;
    if (*(uint32_t*)(cpu->edx + 0xB4u) == cpu->eax) goto label_0003A262;
    if (cpu->eax == 0xFFFFFFFFu) goto label_0003A20F;
    lift_push32(cpu, 0x190u); lift_push32(cpu, 7u); lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x40u) = 0x3Fu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3A20Fu)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_RVA(0x3A20Fu));
    label_0003A20F:
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    lift_push32(cpu, 0x190u); lift_push32(cpu, 0x12u);
    cpu->ecx += 0xB4u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A22Eu)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_VA(0x43A22Eu));
    cpu->eax = g_sfera_mbc_runtime->active_process;
    lift_push32(cpu, 0x190u); lift_push32(cpu, 0xCu);
    cpu->edx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->edx);
    cpu->eax += 0x44u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x40u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A254u)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_VA(0x43A254u));
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xB4u);
    *(uint32_t*)(cpu->edi) = cpu->edx;
    label_0003A262:
    cpu->eax = g_sfera_mbc_runtime->shared_buffer_size;
    lift_push32(cpu, 0x190u); lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->shared_buffer[0]);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A27Du)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_VA(0x43A27Du));
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0003A27F:
    cpu->ebp = lift_pop32(cpu);
    label_0003A280:
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043A290(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A29Eu)); sfera_sub_004380A0(cpu, LIFT_CODE_TOKEN_VA(0x43A29Eu));
    cpu->eax = *(uint32_t*)(cpu->edi + 0xA8u);
    *(uint32_t*)(cpu->esi + 0xA8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xACu);
    *(uint32_t*)(cpu->esi + 0xACu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0xB0u);
    *(uint32_t*)(cpu->esi + 0xB0u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0xB4u);
    *(uint32_t*)(cpu->esi + 0xB4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xB8u);
    *(uint32_t*)(cpu->esi + 0xB8u) = cpu->ecx;
    cpu->eax = cpu->esi + 0xBCu;
    cpu->edi -= cpu->esi;
    cpu->ecx = 0x100u;
    label_0003A2E7:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + cpu->eax));
    *(uint8_t*)(cpu->eax) = cpu->edx & 0xFFu;
    ++cpu->eax;
    { uint64_t l=cpu->ecx, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003A2E7;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043A300(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (*(uint8_t*)(cpu->edi + 0xC8u) == 0u) goto label_0003A31A;
    lift_push32(cpu, (uintptr_t)"~~~~~ItemList~~~FIND FIRST ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A317u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x43A317u));
    cpu->esp += 4u;
    label_0003A31A:
    cpu->esi = 0u;
    if ((int32_t)*(uint32_t*)(cpu->edi + 0xACu) <= (int32_t)cpu->esi) goto label_0003A343;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xD0u);
    cpu->eax = cpu->ecx + 0x9Au;
    label_0003A330:
    if (*(uint8_t*)(cpu->eax) == 1u) goto label_0003A368;
    ++cpu->esi;
    cpu->eax += 0x1BCu;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->edi + 0xACu)) goto label_0003A330;
    label_0003A343:
    { uint64_t l=*(uint8_t*)(cpu->edi + 0xC8u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    *(uint32_t*)(cpu->edi + 0xC4u) = 0xFFFFFFFFu;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003A363;
    lift_push32(cpu, (uintptr_t)" FindFirstItem = 'ERROR'\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A360u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x43A360u));
    cpu->esp += 4u;
    label_0003A363:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003A368:
    { uint64_t l=*(uint8_t*)(cpu->edi + 0xC8u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    *(uint32_t*)(cpu->edi + 0xC4u) = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003A3B3;
    if (cpu->esi != 0xFFFFFFF9u) goto label_0003A383;
    lift_push32(cpu, (uintptr_t)"~~~~~ItemList~~~FIND FIRST ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    goto label_0003A3AB;
    label_0003A383:
    if ((int32_t)cpu->esi < 0) goto label_0003A3A1;
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1BCu);
    cpu->ecx = cpu->eax + cpu->ecx + 4u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)" FindFirstItem 'OK' = ''%s''\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A39Eu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x43A39Eu));
    cpu->esp += 8u;
    label_0003A3A1:
    if (cpu->esi != 0xFFFFFFFFu) goto label_0003A3B3;
    lift_push32(cpu, (uintptr_t)" FindFirstItem = 'ERROR'\n");
    label_0003A3AB:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A3B0u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x43A3B0u));
    cpu->esp += 4u;
    label_0003A3B3:
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1BCu);
    cpu->eax += *(uint32_t*)(cpu->edi + 0xD0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043A3D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0xC8u) == 0u) goto label_0003A3E9;
    lift_push32(cpu, (uintptr_t)"~~~~~ItemList~~~FIND NEXT ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A3E6u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x43A3E6u));
    cpu->esp += 4u;
    label_0003A3E9:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xC4u);
    if ((int32_t)cpu->eax < 0) goto label_0003A425;
    ++cpu->eax;
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->esi + 0xACu)) goto label_0003A425;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xD0u);
    cpu->ecx = cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x1BCu);
    cpu->ecx = cpu->ecx + cpu->edx + 0x9Au;
    label_0003A411:
    if (*(uint8_t*)(cpu->ecx) == 1u) goto label_0003A43F;
    ++cpu->eax;
    cpu->ecx += 0x1BCu;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 0xACu)) goto label_0003A411;
    label_0003A425:
    if (*(uint8_t*)(cpu->esi + 0xC8u) == 0u) goto label_0003A43B;
    lift_push32(cpu, (uintptr_t)" FindNextItem = 'ERROR'\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A438u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x43A438u));
    cpu->esp += 4u;
    label_0003A43B:
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003A43F:
    { uint64_t l=*(uint8_t*)(cpu->esi + 0xC8u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    *(uint32_t*)(cpu->esi + 0xC4u) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003A456;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3A456u)); sfera_sub_00438160(cpu, LIFT_CODE_TOKEN_RVA(0x3A456u));
    label_0003A456:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xC4u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1BCu);
    cpu->eax += *(uint32_t*)(cpu->esi + 0xD0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043A470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = cpu->ecx;
    std::construct_at(reinterpret_cast<CItem*>(cpu->eax));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx + 4u;
    cpu->edi = cpu->eax + 4u;
    cpu->ecx = 0x25u;
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx + 0x9Au));
    *(uint8_t*)(cpu->eax + 0x9Au) = cpu->ecx & 0xFFu;
    cpu->esi = cpu->edx + 0xBCu;
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0x9Cu));
    cpu->edi = cpu->eax + 0xBCu;
    *(float*)(cpu->eax + 0x9Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0xA0u));
    *(float*)(cpu->eax + 0xA0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0xA4u));
    std::construct_at(reinterpret_cast<CCommonItem*>(cpu->eax));
    *(float*)(cpu->eax + 0xA4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0xA8u);
    *(uint32_t*)(cpu->eax + 0xA8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 0xACu);
    *(uint32_t*)(cpu->eax + 0xACu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 0xB0u);
    *(uint32_t*)(cpu->eax + 0xB0u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 0xB4u);
    *(uint32_t*)(cpu->eax + 0xB4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 0xB8u);
    *(uint32_t*)(cpu->eax + 0xB8u) = cpu->ecx;
    cpu->ecx = 0x40u;
    lift_movs32(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043A520(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->ebp >= 0) goto label_0003A55B;
    lift_push32(cpu, cpu->ebp);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, (uintptr_t)"HashMap::init: wrong _startSize=%d"); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x18u) = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\HashMap.h";
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0x9Au;
    *(uint32_t*)(cpu->esp + 0x20u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A558u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x43A558u));
    cpu->esp += 0xCu;
    label_0003A55B:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    if ((int32_t)cpu->ebx >= (int32_t)1u) goto label_0003A590;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, (uintptr_t)"HashMap::init: wrong _maxKeyLen=%d"); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x1Cu) = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\HashMap.h";
    *(uint32_t*)(cpu->esp + 0x20u) = 0x9Bu;
    *(uint32_t*)(cpu->esp + 0x24u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A58Du)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x43A58Du));
    cpu->esp += 0xCu;
    label_0003A590:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ecx = 1u;
    cpu->eax = 0u;
    label_0003A5A0:
    if (cpu->ecx == cpu->edi) goto label_0003A5AC;
    ++cpu->eax;
    cpu->ecx += cpu->ecx;
    if ((int32_t)cpu->eax < (int32_t)0x20u) goto label_0003A5A0;
    label_0003A5AC:
    if (cpu->eax != 0x20u) goto label_0003A5DB;
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, (uintptr_t)"HashMap::init:  hashTabSize must be power of 2"); lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x18u) = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\HashMap.h";
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xA2u;
    *(uint32_t*)(cpu->esp + 0x20u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A5D8u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x43A5D8u));
    cpu->esp += 8u;
    label_0003A5DB:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A5E0u)); sfera_sub_004ED5C0(cpu, LIFT_CODE_TOKEN_VA(0x43A5E0u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx = 0u;
    if (cpu->eax == cpu->ecx) goto label_0003A5EF;
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->eax;
    goto label_0003A5F6;
    label_0003A5EF:
    *(uint32_t*)(cpu->esi + 0x30u) = (uintptr_t)&g_sfera_std_allocator;
    label_0003A5F6:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x24u));
    cpu->eax = 0xFFFFu;
    *(uint16_t*)(cpu->esi + 0x1Cu) = cpu->eax & 0xFFFFu;
    *(uint8_t*)(cpu->esi + 0x1Eu) = cpu->edx & 0xFFu;
    cpu->edx = 0u;
    cpu->eax = cpu->ebx + 0xBu;
    *(uint32_t*)(cpu->esi) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    *(uint16_t*)(cpu->esi + 0x14u) = cpu->edx & 0xFFFFu;
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->ecx;
    { uint64_t l=cpu->ebp, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003A629;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebp;
    goto label_0003A643;
    label_0003A629:
    cpu->eax = cpu->edi + cpu->edi;
    cpu->eax >>= 3u;
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, *(uint32_t*)(cpu->esi + 8u), 32u, 0u);
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->eax;
    if ((int32_t)cpu->eax >= (int32_t)0x14u) goto label_0003A643;
    *(uint32_t*)(cpu->esi + 0xCu) = 0x14u;
    label_0003A643:
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esi + 0xCu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->ebp = 0u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx);
    reinterpret_cast<StdAllocator*>(cpu->ecx)->allocate(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x30u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    reinterpret_cast<StdAllocator*>(cpu->ecx)->allocate(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x30u);
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    lift_push32(cpu, cpu->ebp);
    cpu->edi += cpu->edi;
    lift_push32(cpu, cpu->edi);
    reinterpret_cast<StdAllocator*>(cpu->ecx)->allocate(cpu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x43A67Fu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->esp += 0xCu;
    --cpu->ecx;
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    if ((int32_t)cpu->ecx <= 0) goto label_0003A6B9;
    label_0003A692:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->edi = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    cpu->edx = cpu->eax + 1u;
    *(uint16_t*)(cpu->ecx + cpu->edi + 8u) = cpu->edx & 0xFFFFu;
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->eax);
    *(uint32_t*)(cpu->edx + cpu->ecx + 4u) = cpu->ebp;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    ++cpu->eax;
    --cpu->edx;
    if ((int32_t)cpu->eax < (int32_t)cpu->edx) goto label_0003A692;
    label_0003A6B9:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    cpu->edi = (cpu->edi & 0xFFFF0000u) | (*(uint16_t*)(cpu->esi + 0x1Cu));
    *(uint16_t*)(cpu->ecx + cpu->edx + 8u) = cpu->edi & 0xFFFFu;
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx + cpu->edx + 4u) = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043A6F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, (uintptr_t)"\n-----BaseManager---ALL LISTS----------------------------\n");
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A705u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x43A705u));
    cpu->ebp = 0u;
    cpu->esp += 4u;
    if ((int32_t)*(uint32_t*)(cpu->edi + 0xB0u) <= (int32_t)cpu->ebp) goto label_0003A818;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ebp;
    if ((int32_t)*(uint32_t*)(cpu->edi + 0xACu) <= (int32_t)cpu->ebp) goto label_0003A825;
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    lift_push32(cpu, cpu->esi);
    label_0003A730:
    cpu->eax = *(uint32_t*)(cpu->edi + 0xD0u);
    if (*(uint8_t*)(cpu->eax + cpu->ebp + 0x9Au) != 1u) goto label_0003A7F1;
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->ebp + 0xB0u);
    cpu->ecx = *(uint32_t*)(cpu->eax + cpu->ebp + 0xACu);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->eax + 0xA8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->eax += 4u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"List Name = ''%s'', min = %d, curmax = %d, cur = %d\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A76Bu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x43A76Bu));
    cpu->esi = *(uint32_t*)(cpu->edi + 0xD0u);
    lift_push32(cpu, (uintptr_t)"~~~~~ItemList~~~ALL ITEMS~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    cpu->esi += cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A77Du)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x43A77Du));
    cpu->esp += 0x18u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0xB0u) <= (int32_t)0u) goto label_0003A7E4;
    cpu->ebx = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0xACu) <= (int32_t)cpu->ebx) goto label_0003A7F1;
    cpu->ebp = 0u;
    label_0003A7A0:
    cpu->edi = *(uint32_t*)(cpu->esi + 0xD0u);
    cpu->edi += cpu->ebp;
    if (*(uint8_t*)(cpu->edi + 0x9Au) != 1u) goto label_0003A7CB;
    cpu->ecx = cpu->edi + 4u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)" ItemName = ''%s''\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A7BFu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x43A7BFu));
    cpu->esp += 8u;
    cpu->ecx = cpu->edi;
    reinterpret_cast<CItem*>(cpu->ecx)->releaseItem(cpu);
    label_0003A7CB:
    ++cpu->ebx;
    cpu->ebp += 0x1BCu;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->esi + 0xACu)) goto label_0003A7A0;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    goto label_0003A7F1;
    label_0003A7E4:
    lift_push32(cpu, (uintptr_t)". . . . . . . \n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A7EEu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x43A7EEu));
    cpu->esp += 4u;
    label_0003A7F1:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->eax;
    cpu->ebp += 0xD4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->edi + 0xACu)) goto label_0003A730;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003A818:
    lift_push32(cpu, (uintptr_t)". . . . . . . . . \n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A822u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x43A822u));
    cpu->esp += 4u;
    label_0003A825:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043A830(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esi + 0xA8u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, 0x96u);
    *(uint32_t*)(cpu->esi + 0xB4u) = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 4u;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ecx);
    *(uint8_t*)(cpu->esi + 0xC8u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0xACu) = 0x1Eu;
    *(uint32_t*)(cpu->esi + 0xB0u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xB8u) = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x43A898u));
    cpu->esp += 0xCu;
    cpu->edx = 0x1A4u;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\lists\\ItemList.h";
    *(uint8_t*)(cpu->esi + 0x99u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A8B6u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x43A8B6u));
    lift_push32(cpu, 0x44u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A8BDu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x43A8BDu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if (cpu->eax == cpu->ebx) goto label_0003A8E3;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x100u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, 0x96u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A8E1u)); sfera_sub_0043A520(cpu, LIFT_CODE_TOKEN_VA(0x43A8E1u));
    goto label_0003A8E5;
    label_0003A8E3:
    cpu->eax = 0u;
    label_0003A8E5:
    cpu->ecx |= 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0xCCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x28u) = cpu->ecx;
    lift_push32(cpu, 0x1ABu);
    cpu->edx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\lists\\ItemList.h";
    cpu->ecx = 0x3408u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A909u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x43A909u));
    *(uint32_t*)(cpu->esi + 0xD0u) = cpu->eax;
    if (cpu->eax != cpu->ebx) goto label_0003A94B;
    if (*(uint8_t*)(cpu->esi + 0xC8u) == (cpu->ebx & 0xFFu)) goto label_0003A932;
    lift_push32(cpu, (uintptr_t)"~~~~~ItemList~~~INITIALIZE~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A925u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x43A925u));
    lift_push32(cpu, (uintptr_t)" Initialize = 'ERROR'\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A92Fu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x43A92Fu));
    cpu->esp += 8u;
    label_0003A932:
    cpu->eax = 0xFFFFFFF2u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
    label_0003A94B:
    lift_push32(cpu, 0x3408u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x43A952u));
    cpu->esp += 0xCu;
    if (*(uint8_t*)(cpu->esi + 0xC8u) == (cpu->ebx & 0xFFu)) goto label_0003A979;
    lift_push32(cpu, (uintptr_t)"~~~~~ItemList~~~INITIALIZE~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A96Cu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x43A96Cu));
    lift_push32(cpu, (uintptr_t)"Initialize complete\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A976u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x43A976u));
    cpu->esp += 8u;
    label_0003A979:
    cpu->eax = 0u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043A990(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->edi);
    if (cpu->eax == 0u) goto label_0003A9A1;
    *(uint32_t*)(cpu->eax) = 0u;
    label_0003A9A1:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->eax != 0u) goto label_0003A9BA;
    if (*(uint8_t*)(cpu->esi + 0x1Eu) != 0u) goto label_0003A9BA;
    *(uint8_t*)(cpu->esp + 0x10u) = 1u;
    goto label_0003A9C3;
    label_0003A9BA:
    *(uint8_t*)(cpu->esp + 0x10u) = 0u;
    if (cpu->eax != 0u) goto label_0003A9D1;
    label_0003A9C3:
    cpu->eax = cpu->edi;
    cpu->edx = cpu->eax + 1u;
    label_0003A9C8:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0003A9C8;
    cpu->eax -= cpu->edx;
    label_0003A9D1:
    if ((int32_t)cpu->eax <= (int32_t)*(uint32_t*)(cpu->esi)) goto label_0003A9DC;
    label_0003A9D5:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0003A9DC:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A9EAu)); sfera_sub_00438220(cpu, LIFT_CODE_TOKEN_VA(0x43A9EAu));
    if (cpu->eax == 0xFFFFFFFFu) goto label_0003A9D5;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x38u);
    *(uint32_t*)(cpu->edx + 4u) = 0u;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x3Cu);
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)(cpu->esi + 0x40u));
    if (cpu->eax == 0u) goto label_0003AA0A;
    *(uint16_t*)(cpu->eax + 8u) = cpu->ecx & 0xFFFFu;
    goto label_0003AA15;
    label_0003AA0A:
    cpu->edx = *(uint16_t*)(cpu->esi + 0x42u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18u);
    *(uint16_t*)(cpu->eax + (cpu->edx * 2u)) = cpu->ecx & 0xFFFFu;
    label_0003AA15:
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(cpu->esi + 0x14u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x38u);
    *(uint16_t*)(cpu->edx + 8u) = cpu->eax & 0xFFFFu;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)(cpu->esi + 0x34u));
    cpu->edi = lift_pop32(cpu);
    *(uint16_t*)(cpu->esi + 0x14u) = cpu->ecx & 0xFFFFu;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043AA30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    if (cpu->eax == cpu->ebx) goto label_0003AA44;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    label_0003AA44:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    if (cpu->ebp != cpu->ebx) goto label_0003AA5C;
    if (*(uint8_t*)(cpu->esi + 0x1Eu) != (cpu->ebx & 0xFFu)) goto label_0003AA5C;
    *(uint8_t*)(cpu->esp + 0x24u) = 1u;
    goto label_0003AA64;
    label_0003AA5C:
    *(uint8_t*)(cpu->esp + 0x24u) = cpu->ebx & 0xFFu;
    if (cpu->ebp != cpu->ebx) goto label_0003AA7B;
    label_0003AA64:
    cpu->eax = cpu->edi;
    cpu->edx = cpu->eax + 1u;
    label_0003AA70:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0003AA70;
    cpu->eax -= cpu->edx;
    cpu->ebp = cpu->eax;
    label_0003AA7B:
    if ((int32_t)cpu->ebp <= (int32_t)*(uint32_t*)(cpu->esi)) goto label_0003AAB6;
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, (uintptr_t)"HashMap::insert: maxKeyLen exceed"); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x18u) = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\HashMap.h";
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0x129u;
    *(uint32_t*)(cpu->esp + 0x20u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43AAA6u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x43AAA6u));
    cpu->esp += 8u;
    label_0003AAA9:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0003AAB6:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43AAC4u)); sfera_sub_00438220(cpu, LIFT_CODE_TOKEN_VA(0x43AAC4u));
    if (cpu->eax != 0xFFFFFFFFu) goto label_0003AAA9;
    cpu->eax = *(uint16_t*)(cpu->esi + 0x1Cu);
    if (*(uint16_t*)(cpu->esi + 0x14u) != (cpu->eax & 0xFFFFu)) goto label_0003ABC5;
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    if (cpu->eax != cpu->ecx) goto label_0003AB17;
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, (uintptr_t)"HashMap::insert: more than maxIndexVal elements"); lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x18u) = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\HashMap.h";
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0x134u;
    *(uint32_t*)(cpu->esp + 0x20u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43AB07u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x43AB07u));
    cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0003AB17:
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=cpu->eax, r=cpu->edx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edi = cpu->eax;
    cpu->edi = (int32_t)(cpu->edi) >> 1u;
    if ((int32_t)cpu->edi >= (int32_t)0xAu) goto label_0003AB28;
    cpu->edi = 0xAu;
    label_0003AB28:
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(cpu->esi + 0xCu));
    *(uint32_t*)(cpu->esi + 0xCu) = (uint64_t)(*(uint32_t*)(cpu->esi + 0xCu)) + (uint64_t)(cpu->edi) + (uint64_t)(0u);
    *(uint16_t*)(cpu->esi + 0x14u) = cpu->eax & 0xFFFFu;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    if (cpu->eax <= cpu->ecx) goto label_0003AB43;
    cpu->edx = cpu->ecx;
    cpu->edx -= cpu->eax;
    cpu->edi += cpu->edx;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ecx;
    label_0003AB43:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esi + 8u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx);
    reinterpret_cast<StdAllocator*>(cpu->ecx)->reallocate(cpu);
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->edx = cpu->edi + 0xFFFFFFFFu;
    cpu->eax = 0u;
    if ((int32_t)cpu->edx <= (int32_t)cpu->ebx) goto label_0003AB9E;
    label_0003AB70:
    cpu->ecx = *(uint16_t*)(cpu->esi + 0x14u);
    cpu->ebx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = cpu->ecx + cpu->eax + 1u;
    cpu->ecx += cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esi + 8u));
    *(uint16_t*)(cpu->ecx + cpu->ebx + 8u) = cpu->edi & 0xFFFFu;
    cpu->ecx = *(uint16_t*)(cpu->esi + 0x14u);
    cpu->edi = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx += cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esi + 8u));
    cpu->ebx = 0u;
    ++cpu->eax;
    *(uint32_t*)(cpu->ecx + cpu->edi + 4u) = cpu->ebx;
    if ((int32_t)cpu->eax < (int32_t)cpu->edx) goto label_0003AB70;
    label_0003AB9E:
    cpu->edx = *(uint16_t*)(cpu->esi + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = (cpu->edi & 0xFFFF0000u) | (*(uint16_t*)(cpu->esi + 0x1Cu));
    cpu->edx += cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esi + 8u));
    *(uint16_t*)(cpu->edx + cpu->ecx + 8u) = cpu->edi & 0xFFFFu;
    cpu->edx = *(uint16_t*)(cpu->esi + 0x14u);
    cpu->edx += cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esi + 8u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx + cpu->eax + 4u) = cpu->ebx;
    label_0003ABC5:
    cpu->edi = *(uint16_t*)(cpu->esi + 0x14u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esi + 8u));
    cpu->edi += *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 0xAu;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43ABD9u));
    *(uint8_t*)(cpu->edi + cpu->ebp + 0xAu) = cpu->ebx & 0xFFu;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)(cpu->edi + 8u));
    cpu->eax = *(uint16_t*)(cpu->esi + 0x14u);
    *(uint16_t*)(cpu->esi + 0x14u) = cpu->ecx & 0xFFFFu;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->esp += 0xCu;
    if (cpu->ecx == cpu->ebx) goto label_0003ABFD;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->edi) = cpu->edx;
    label_0003ABFD:
    cpu->ecx = *(uint16_t*)(cpu->esi + 0x42u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)(cpu->edx + (cpu->ecx * 2u)));
    *(uint32_t*)(cpu->edi + 4u) = cpu->ebp;
    *(uint16_t*)(cpu->edi + 8u) = cpu->ecx & 0xFFFFu;
    cpu->edx = *(uint16_t*)(cpu->esi + 0x42u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint16_t*)(cpu->ecx + (cpu->edx * 2u)) = cpu->eax & 0xFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043AC30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = g_sfera_mbc_runtime->call_frame_depth;
    { uint64_t l=cpu->eax, r=g_sfera_mbc_runtime->frame_stack_base[cpu->ecx], v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0003AC51;
    cpu->ecx = (uintptr_t)"popint(): stack underflow";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43AC4Eu)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x43AC4Eu));
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003AC51:
    { uint64_t l=cpu->eax, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    g_sfera_mbc_runtime->value_stack_size = cpu->eax;
    cpu->eax <<= 5u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (((uint8_t)g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type));
    if ((cpu->ecx & 0xFFu) == 0x10u) goto label_0003AC81;
    if ((cpu->ecx & 0xFFu) != 0x20u) goto label_0003AC75;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0]));
    sfera_sub_004EE940(cpu, stop_address); return;
    label_0003AC75:
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0003AC81;
    cpu->eax = (int8_t)(((uint8_t)g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0]));
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003AC81:
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0];
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043AC90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = g_sfera_mbc_runtime->call_frame_depth;
    { uint64_t l=cpu->eax, r=g_sfera_mbc_runtime->frame_stack_base[cpu->ecx], v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0003ACC8;
    cpu->ecx = (uintptr_t)"popsliceref(): stack underflow";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43ACAEu)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x43ACAEu));
    cpu->ecx = 0u;
    g_sfera_pop_slice_fallback.base = cpu->ecx;
    g_sfera_pop_slice_fallback.begin = cpu->ecx;
    g_sfera_pop_slice_fallback.end = cpu->ecx;
    cpu->eax = (uintptr_t)&g_sfera_pop_slice_fallback;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003ACC8:
    { uint64_t l=cpu->eax, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    g_sfera_mbc_runtime->value_stack_size = cpu->eax;
    cpu->eax <<= 5u;
    cpu->eax += ((uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    if (((*(uint8_t*)(cpu->eax)) & (0xFu)) != 0u) goto label_0003ACE3;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    label_0003ACE3:
    cpu->eax += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043ACF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->argument_cursor;
    { uint64_t l=cpu->esi, r=g_sfera_mbc_runtime->argument_end, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003AD0D;
    cpu->ecx = (uintptr_t)"Too few parameters";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43AD09u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x43AD09u));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003AD0D:
    cpu->eax = cpu->esi;
    cpu->eax <<= 5u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (((uint8_t)g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type));
    if ((cpu->ecx & 0xFFu) == 0x10u) goto label_0003AD4A;
    if ((cpu->ecx & 0xFFu) != 0x20u) goto label_0003AD36;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0]));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43AD2Du)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x43AD2Du));
    ++cpu->esi;
    g_sfera_mbc_runtime->argument_cursor = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003AD36:
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0003AD4A;
    cpu->eax = (int8_t)(((uint8_t)g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0]));
    ++cpu->esi;
    g_sfera_mbc_runtime->argument_cursor = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003AD4A:
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0];
    ++cpu->esi;
    g_sfera_mbc_runtime->argument_cursor = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043AD60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->argument_cursor;
    { uint64_t l=cpu->ecx, r=g_sfera_mbc_runtime->argument_end, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003AD7D;
    cpu->ecx = (uintptr_t)"Too few parameters";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43AD79u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x43AD79u));
    lift_x87_push(cpu, 0.0);
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003AD7D:
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (((uint8_t)g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type));
    if ((cpu->edx & 0xFFu) != 0x20u) goto label_0003ADA2;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0]));
    ++cpu->ecx;
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    g_sfera_mbc_runtime->argument_cursor = cpu->ecx;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003ADA2:
    if ((cpu->edx & 0xFFu) != 0x10u) goto label_0003ADBC;
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0]))));
    ++cpu->ecx;
    g_sfera_mbc_runtime->argument_cursor = cpu->ecx;
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003ADBC:
    if ((cpu->edx & 0xFFu) != 0u) goto label_0003ADDC;
    cpu->eax = (int8_t)(((uint8_t)g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0]));
    *(uint32_t*)(cpu->esp) = cpu->eax;
    ++cpu->ecx;
    g_sfera_mbc_runtime->argument_cursor = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp)))));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003ADDC:
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0]))));
    ++cpu->ecx;
    g_sfera_mbc_runtime->argument_cursor = cpu->ecx;
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043AE00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    lift_push32(cpu, cpu->esi);
    { uint64_t l=cpu->eax, r=g_sfera_mbc_runtime->argument_end, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003AE2E;
    cpu->ecx = (uintptr_t)"popsliceup(): stack underflow";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43AE18u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x43AE18u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->esi = 0u;
    cpu->ecx = 0u;
    cpu->edx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0003AE2E:
    cpu->ecx = cpu->eax;
    cpu->ecx <<= 5u;
    cpu->ecx += ((uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    ++cpu->eax;
    { uint64_t l=*(uint8_t*)(cpu->ecx), r=0xFu, v=l & r; lift_flags_logic(cpu,v,8u); }
    g_sfera_mbc_runtime->argument_cursor = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003AE4C;
    cpu->esi = 0u;
    *(uint32_t*)(cpu->ecx + 0x18u) = cpu->esi;
    *(uint32_t*)(cpu->ecx + 0x1Cu) = cpu->esi;
    label_0003AE4C:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043AE70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mbc_runtime->argument_cursor;
    { uint64_t l=cpu->ecx, r=g_sfera_mbc_runtime->argument_end, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003AEA2;
    cpu->ecx = (uintptr_t)"popsliceupref(): stack underflow";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43AE88u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x43AE88u));
    cpu->ecx = 0u;
    g_sfera_pop_sliceup_fallback.base = cpu->ecx;
    g_sfera_pop_sliceup_fallback.begin = cpu->ecx;
    g_sfera_pop_sliceup_fallback.end = cpu->ecx;
    cpu->eax = (uintptr_t)&g_sfera_pop_sliceup_fallback;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003AEA2:
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    cpu->eax += ((uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    ++cpu->ecx;
    { uint64_t l=*(uint8_t*)(cpu->eax), r=0xFu, v=l & r; lift_flags_logic(cpu,v,8u); }
    g_sfera_mbc_runtime->argument_cursor = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003AEC0;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    label_0003AEC0:
    cpu->eax += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043AED0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->ecx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003AEEB;
    cpu->ecx = (uintptr_t)"Stack overflow";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43AEE8u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x43AEE8u));
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0003AEEB:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    cpu->edx = 1u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x20u;
    *(float*)((uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0]) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = cpu->edx;
    g_sfera_mbc_runtime->value_stack_size = cpu->ecx;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043AF30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->esi, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003AF4A;
    cpu->ecx = (uintptr_t)"Stack overflow";
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003AF4A:
    cpu->eax = cpu->esi;
    cpu->eax <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[1] = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[2] = cpu->ecx;
    cpu->ecx = 1u;
    cpu->esi += cpu->ecx;
    g_sfera_mbc_runtime->value_stack_size = cpu->esi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = cpu->ecx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043AFA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    g_sfera_mbc_runtime->active_tag = cpu->ecx;
    { uint64_t l=cpu->edx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003AFBE;
    cpu->ecx = (uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003AFBE:
    cpu->eax = cpu->edx;
    cpu->eax <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = cpu->ecx;
    cpu->ecx = 1u;
    cpu->edx += cpu->ecx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = cpu->ecx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = cpu->ecx;
    g_sfera_mbc_runtime->value_stack_size = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043B0B0(LiftCpu* cpu, uint32_t stop_address) {
    sfera_sub_0043ACF0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_0043B0C0(LiftCpu* cpu, uint32_t stop_address) {
    sfera_sub_0043AD60(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_0043B0D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->edx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003B0E8;
    cpu->ecx = (uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003B0E8:
    cpu->eax = cpu->edx;
    cpu->eax <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = cpu->ecx;
    cpu->ecx = 1u;
    cpu->edx += cpu->ecx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = cpu->ecx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = cpu->ecx;
    g_sfera_mbc_runtime->value_stack_size = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043B130(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043B140(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43B145u)); sfera_sub_0043AC30(cpu, LIFT_CODE_TOKEN_VA(0x43B145u));
    if (cpu->eax == 0u) goto label_0003B151;
    g_sfera_mbc_runtime->instruction_cursor += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003B151:
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->eax += *(uint32_t*)(cpu->eax);
    g_sfera_mbc_runtime->instruction_cursor = cpu->eax;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043B160(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43B165u)); sfera_sub_0043AC30(cpu, LIFT_CODE_TOKEN_VA(0x43B165u));
    if (cpu->eax == 0u) goto label_0003B171;
    g_sfera_mbc_runtime->instruction_cursor += 2u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003B171:
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = (int16_t)(*(uint16_t*)(cpu->eax));
    cpu->eax += cpu->ecx;
    g_sfera_mbc_runtime->instruction_cursor = cpu->eax;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043B190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = *(uint8_t*)(cpu->eax);
    lift_push32(cpu, cpu->ebx);
    ++cpu->eax;
    lift_push32(cpu, cpu->ebp);
    g_sfera_mbc_runtime->instruction_cursor = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint16_t*)(cpu->eax);
    cpu->eax += 2u;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    g_sfera_mbc_runtime->instruction_cursor = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43B1B9u)); sfera_sub_0043AC30(cpu, LIFT_CODE_TOKEN_VA(0x43B1B9u));
    cpu->edi = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax += 4u;
    g_sfera_mbc_runtime->instruction_cursor = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax += 4u;
    g_sfera_mbc_runtime->instruction_cursor = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax += 4u;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    g_sfera_mbc_runtime->instruction_cursor = cpu->eax;
    cpu->ebp = cpu->ecx;
    if ((int32_t)cpu->ecx >= 0) goto label_0003B1F4;
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ebp = cpu->ecx;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (1u & 0xFFu);
    label_0003B1F4:
    if ((int32_t)cpu->edi >= (int32_t)cpu->ebp) goto label_0003B1FC;
    if ((int32_t)cpu->edi >= 0) goto label_0003B22A;
    label_0003B1FC:
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43B206u)); sfera_sub_00434AF0(cpu, LIFT_CODE_TOKEN_VA(0x43B206u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\nArray boundary error: array size = %d, index = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43B21Cu)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x43B21Cu));
    cpu->esp += 0x14u;
    if ((int32_t)cpu->edi >= 0) goto label_0003B227;
    cpu->edi = 0u;
    goto label_0003B22A;
    label_0003B227:
    cpu->edi = cpu->ebp + 0xFFFFFFFFu;
    label_0003B22A:
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->edi);
    { uint64_t l=cpu->esi, r=*(uint32_t*)(cpu->esp + 0x14u), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->eax = cpu->edx;
    { uint64_t l=cpu->edx, v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    cpu->ecx = cpu->esi;
    g_sfera_mbc_runtime->value_stack_size = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax <<= 5u;
    cpu->eax += ((uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    cpu->edx = cpu->edx + cpu->ecx + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->edx;
    if ((cpu->ebx & 0xFFu) == 0u) goto label_0003B2F4;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->edx != 0u) goto label_0003B28D;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (int8_t)(*(uint8_t*)(cpu->edx + cpu->ecx));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->eax) = 0x10u;
    *(uint32_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003B28D:
    if (cpu->edx == 0x10u) goto label_0003B297;
    if (cpu->edx != 0x20u) goto label_0003B2B4;
    label_0003B297:
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = *(uint32_t*)(cpu->esi + cpu->ecx);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = 4u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003B2B4:
    if (cpu->edx != 0x30u) goto label_0003B2CC;
    cpu->edx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xCu);
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->eax) = 0x30u;
    goto label_0003B305;
    label_0003B2CC:
    cpu->ecx += g_sfera_mbc_runtime->process_memory_base;
    cpu->edi = lift_pop32(cpu);
    cpu->esi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = 0xCu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003B2F4:
    cpu->edx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xCu);
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0003B305:
    cpu->edx = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = 0xCu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043B320(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = *(uint8_t*)(cpu->eax);
    lift_push32(cpu, cpu->ebx);
    ++cpu->eax;
    lift_push32(cpu, cpu->ebp);
    g_sfera_mbc_runtime->instruction_cursor = cpu->eax;
    cpu->ebp = *(uint16_t*)(cpu->eax);
    lift_push32(cpu, cpu->esi);
    cpu->eax += 2u;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    g_sfera_mbc_runtime->instruction_cursor = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43B349u)); sfera_sub_0043AC90(cpu, LIFT_CODE_TOKEN_VA(0x43B349u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43B350u)); sfera_sub_0043AC30(cpu, LIFT_CODE_TOKEN_VA(0x43B350u));
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx += 4u;
    g_sfera_mbc_runtime->instruction_cursor = cpu->ecx;
    cpu->ebx = cpu->eax;
    *(uint8_t*)(cpu->esp + 0x13u) = 0u;
    if ((int32_t)cpu->eax >= 0) goto label_0003B377;
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->ebx = cpu->eax;
    *(uint8_t*)(cpu->esp + 0x13u) = 1u;
    label_0003B377:
    if ((int32_t)cpu->edi >= (int32_t)cpu->ebx) goto label_0003B37F;
    if ((int32_t)cpu->edi >= 0) goto label_0003B3B4;
    label_0003B37F:
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43B389u)); sfera_sub_00434AF0(cpu, LIFT_CODE_TOKEN_VA(0x43B389u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\nArray2 boundary error: array size = %d, index = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43B39Fu)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x43B39Fu));
    cpu->esp += 0x14u;
    if ((int32_t)cpu->edi < 0) goto label_0003B3B1;
    cpu->eax = cpu->ebx + 0xFFFFFFFFu;
    if ((int32_t)cpu->eax >= 0) goto label_0003B3B1;
    cpu->edi = 0u;
    goto label_0003B3B4;
    label_0003B3B1:
    cpu->edi = cpu->ebx + 0xFFFFFFFFu;
    label_0003B3B4:
    cpu->ebp = (int64_t)(int32_t)(cpu->ebp) * (int64_t)(int32_t)(cpu->edi);
    { uint64_t l=*(uint32_t*)(cpu->esi), r=cpu->ebp, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esi) = v; }
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->eax = cpu->edx;
    { uint64_t l=cpu->edx, v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    cpu->eax <<= 5u;
    cpu->eax += ((uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    { uint64_t l=*(uint8_t*)(cpu->esp + 0x13u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    g_sfera_mbc_runtime->value_stack_size = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003B492;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->edx != 0u) goto label_0003B418;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (int8_t)(*(uint8_t*)(cpu->edx + cpu->ecx));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->eax) = 0x10u;
    *(uint32_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003B418:
    if (cpu->edx == 0x10u) goto label_0003B422;
    if (cpu->edx != 0x20u) goto label_0003B43F;
    label_0003B422:
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = *(uint32_t*)(cpu->esi + cpu->ecx);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = 4u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003B43F:
    if (cpu->edx != 0x30u) goto label_0003B46A;
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = 0x30u;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = 0xCu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003B46A:
    cpu->ecx += g_sfera_mbc_runtime->process_memory_base;
    cpu->edi = lift_pop32(cpu);
    cpu->esi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = 0xCu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003B492:
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = 0xCu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043B4C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint8_t*)(cpu->eax);
    ++cpu->eax;
    lift_push32(cpu, cpu->esi);
    g_sfera_mbc_runtime->instruction_cursor = cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint16_t*)(cpu->eax);
    cpu->eax += 2u;
    g_sfera_mbc_runtime->instruction_cursor = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43B4E1u)); sfera_sub_0043AC90(cpu, LIFT_CODE_TOKEN_VA(0x43B4E1u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43B4E8u)); sfera_sub_0043AC30(cpu, LIFT_CODE_TOKEN_VA(0x43B4E8u));
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(cpu->eax);
    *(uint32_t*)(cpu->esi) = (uint64_t)(*(uint32_t*)(cpu->esi)) + (uint64_t)(cpu->edi) + (uint64_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = *(uint32_t*)(cpu->esi);
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003B554;
    if (cpu->edi < cpu->eax) goto label_0003B4FF;
    { uint64_t l=cpu->edi, r=*(uint32_t*)(cpu->esi + 8u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0003B554;
    label_0003B4FF:
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43B509u)); sfera_sub_00434AF0(cpu, LIFT_CODE_TOKEN_VA(0x43B509u));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43B529u)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x43B529u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->esp += 0x18u;
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003B554;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    { uint64_t v=cpu->ecx; lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003B554;
    { uint64_t l=cpu->eax, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0003B544;
    { uint64_t l=cpu->eax, r=*(uint32_t*)(cpu->esi + 8u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0003B554;
    { uint64_t l=cpu->eax, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_0003B544:
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0003B54B;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    goto label_0003B554;
    label_0003B54B:
    --cpu->eax;
    { uint64_t l=cpu->eax, r=*(uint32_t*)(cpu->esi + 8u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003B554;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    label_0003B554:
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = cpu->ecx;
    { uint64_t l=cpu->ecx, v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->eax <<= 5u;
    cpu->eax += ((uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    g_sfera_mbc_runtime->value_stack_size = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ecx;
    if (cpu->ebx != 0u) goto label_0003B59E;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (int8_t)(*(uint8_t*)(cpu->edx + cpu->edi));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->eax) = 0x10u;
    *(uint32_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003B59E:
    if (cpu->ebx == 0x10u) goto label_0003B5A8;
    if (cpu->ebx != 0x20u) goto label_0003B5C1;
    label_0003B5A8:
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = *(uint32_t*)(cpu->edx + cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 4u) = 4u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003B5C1:
    if (cpu->ebx != 0x30u) goto label_0003B5E4;
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = 0xCu;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003B5E4:
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->ecx + cpu->edi);
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + cpu->edi + 4u);
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ecx + cpu->edi + 8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 4u) = 0xCu;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043B610(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint8_t*)(cpu->eax);
    lift_push32(cpu, cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->edi);
    g_sfera_mbc_runtime->instruction_cursor = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43B626u)); sfera_sub_0043AC90(cpu, LIFT_CODE_TOKEN_VA(0x43B626u));
    cpu->esi = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = *(uint16_t*)(cpu->eax);
    cpu->eax += 2u;
    g_sfera_mbc_runtime->instruction_cursor = cpu->eax;
    *(uint32_t*)(cpu->esi) = (uint64_t)(*(uint32_t*)(cpu->esi)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = *(uint32_t*)(cpu->esi);
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003B6A1;
    if (cpu->edi < cpu->eax) goto label_0003B64C;
    { uint64_t l=cpu->edi, r=*(uint32_t*)(cpu->esi + 8u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0003B6A1;
    label_0003B64C:
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43B656u)); sfera_sub_00434AF0(cpu, LIFT_CODE_TOKEN_VA(0x43B656u));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43B676u)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x43B676u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->esp += 0x18u;
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003B6A1;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    { uint64_t v=cpu->ecx; lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003B6A1;
    { uint64_t l=cpu->eax, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0003B691;
    { uint64_t l=cpu->eax, r=*(uint32_t*)(cpu->esi + 8u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0003B6A1;
    { uint64_t l=cpu->eax, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_0003B691:
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0003B698;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    goto label_0003B6A1;
    label_0003B698:
    --cpu->eax;
    { uint64_t l=cpu->eax, r=*(uint32_t*)(cpu->esi + 8u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003B6A1;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    label_0003B6A1:
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    cpu->eax += ((uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    ++cpu->ecx;
    g_sfera_mbc_runtime->value_stack_size = cpu->ecx;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    if (cpu->ebx == 0x10u) goto label_0003B6C4;
    if (cpu->ebx != 0x20u) goto label_0003B6E7;
    label_0003B6C4:
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->ecx + cpu->edi);
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = 4u;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edi;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edi;
    cpu->edi += 3u;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003B6E7:
    if (cpu->ebx != 0u) goto label_0003B712;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = (int8_t)(*(uint8_t*)(cpu->ecx + cpu->edi));
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->eax) = 0x10u;
    *(uint32_t*)(cpu->eax + 4u) = 1u;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edi;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edi;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003B712:
    if (cpu->ebx != 0x30u) goto label_0003B751;
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->ecx += 4u;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edi;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edi;
    g_sfera_mbc_runtime->instruction_cursor = cpu->ecx;
    cpu->ecx = cpu->edx + cpu->edi + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->edx = cpu->edi;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = 0xCu;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003B751:
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->ecx + cpu->edi);
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + cpu->edi + 4u);
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ecx + cpu->edi + 8u);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 4u) = 0xCu;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edi;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edi;
    cpu->edi += 0xBu;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043B790(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint8_t*)(cpu->eax);
    lift_push32(cpu, cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->edi);
    g_sfera_mbc_runtime->instruction_cursor = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43B7A6u)); sfera_sub_0043AC90(cpu, LIFT_CODE_TOKEN_VA(0x43B7A6u));
    cpu->esi = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = *(uint16_t*)(cpu->eax);
    cpu->eax += 2u;
    g_sfera_mbc_runtime->instruction_cursor = cpu->eax;
    *(uint32_t*)(cpu->esi) = (uint64_t)(*(uint32_t*)(cpu->esi)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = *(uint32_t*)(cpu->esi);
    if (cpu->eax == 0u) goto label_0003B821;
    if (cpu->edi < cpu->eax) goto label_0003B7CC;
    if (cpu->edi <= *(uint32_t*)(cpu->esi + 8u)) goto label_0003B821;
    label_0003B7CC:
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43B7D6u)); sfera_sub_00434AF0(cpu, LIFT_CODE_TOKEN_VA(0x43B7D6u));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43B7F6u)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x43B7F6u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->esp += 0x18u;
    if (cpu->eax == 0u) goto label_0003B821;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ecx == 0u) goto label_0003B821;
    { uint64_t l=cpu->eax, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0003B811;
    if (cpu->eax <= *(uint32_t*)(cpu->esi + 8u)) goto label_0003B821;
    { uint64_t l=cpu->eax, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_0003B811:
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0003B818;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    goto label_0003B821;
    label_0003B818:
    --cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)*(uint32_t*)(cpu->esi + 8u)) goto label_0003B821;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    label_0003B821:
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->eax, r=4u, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    g_sfera_mbc_runtime->instruction_cursor = cpu->eax;
    cpu->eax = cpu->edx;
    cpu->eax <<= 5u;
    cpu->eax += ((uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->edi;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->edi;
    cpu->ecx = cpu->ecx + cpu->edi + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->edi = lift_pop32(cpu);
    ++cpu->edx;
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 8u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->eax + 0x10u) = 1u;
    *(uint32_t*)(cpu->eax + 0xCu) = 1u;
    g_sfera_mbc_runtime->value_stack_size = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = 0xCu;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043B880(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->program_index;
    cpu->ecx = g_sfera_mbc_runtime->program_table_base;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->instruction_cursor;
    cpu->esi -= g_sfera_mbc_runtime->bytecode_base;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->eax + cpu->ecx + 0x84u;
    cpu->esi += 4u;
    if (*(uint8_t*)(cpu->edi) < 0x14u) goto label_0003B8B8;
    cpu->ecx = (uintptr_t)"Return stack overflow";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3B8B8u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x3B8B8u));
    label_0003B8B8:
    cpu->edx = *(uint8_t*)(cpu->edi);
    cpu->eax = g_sfera_mbc_runtime->active_program_record;
    *(uint32_t*)(cpu->eax + (cpu->edx * 4u) + 0x34u) = cpu->esi;
    ++*(uint8_t*)(cpu->edi);
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->eax += *(uint32_t*)(cpu->eax);
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_runtime->instruction_cursor = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    g_sfera_mbc_runtime->argument_end = cpu->eax;
    cpu->eax -= g_sfera_mbc_runtime->argument_count;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->value_stack_size = cpu->eax;
    g_sfera_mbc_runtime->argument_cursor = cpu->eax;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043B8F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->ebp = 0u;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    cpu->edi = cpu->esi + 0x30u;
    g_sfera_mbc_runtime->argument_count = cpu->ebp;
    cpu->ebx = cpu->ebp + 1u;
    label_0003B911:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + cpu->ebp + 0x20u));
    if ((cpu->eax & 0xFFu) == 0x46u) goto label_0003B98E;
    if ((cpu->eax & 0xFFu) == 0x49u) goto label_0003B96D;
    if ((cpu->eax & 0xFFu) == 0x53u) goto label_0003B92B;
    cpu->ebp = 0x10u;
    goto label_0003B9EE;
    label_0003B92B:
    cpu->eax = cpu->edi;
    cpu->edx = cpu->eax + 1u;
    label_0003B930:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0003B930;
    cpu->eax -= cpu->edx;
    cpu->esi = cpu->eax + 1u;
    cpu->eax = cpu->edi;
    cpu->eax -= g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    cpu->eax = cpu->eax + cpu->esi + 0xFFFFFFFFu;
    cpu->ecx = cpu->esp + 0x18u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43B95Fu)); sfera_sub_0043AF30(cpu, LIFT_CODE_TOKEN_VA(0x43B95Fu));
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->edi += cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    goto label_0003B9E8;
    label_0003B96D:
    cpu->edx = *(uint32_t*)(cpu->edi);
    { uint64_t l=cpu->ecx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0003B99C;
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = cpu->edx;
    goto label_0003B9C7;
    label_0003B98E:
    lift_x87_push(cpu, (double)*(float*)(cpu->edi));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    { uint64_t l=cpu->ecx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003B9AE;
    label_0003B99C:
    cpu->ecx = (uintptr_t)"Stack overflow";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43B9A6u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x43B9A6u));
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    goto label_0003B9E5;
    label_0003B9AE:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x20u;
    *(float*)((uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0]) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0003B9C7:
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = 0xFFFFFFFFu;
    cpu->ecx += cpu->ebx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = cpu->ebx;
    g_sfera_mbc_runtime->value_stack_size = cpu->ecx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = cpu->ebx;
    label_0003B9E5:
    cpu->edi += 4u;
    label_0003B9E8:
    g_sfera_mbc_runtime->argument_count += cpu->ebx;
    label_0003B9EE:
    cpu->ebp += cpu->ebx;
    if ((int32_t)cpu->ebp < (int32_t)0x10u) goto label_0003B911;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043BA10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->active_process;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->eax + 0xBCu);
    if (cpu->ebp == 0u) goto label_0003BAA7;
    --g_sfera_mbc_runtime->instruction_cursor;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax + 0x64u);
    cpu->ebx = 0u;
    if ((int32_t)cpu->edi <= 0) goto label_0003BA7F;
    cpu->esi = *(uint32_t*)(cpu->eax + 0x68u);
    label_0003BA40:
    cpu->ecx = cpu->esi;
    cpu->eax = cpu->ebp;
    label_0003BA44:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    { uint64_t l=(cpu->edx & 0xFFu), r=*(uint8_t*)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003BA64;
    if ((cpu->edx & 0xFFu) == 0u) goto label_0003BA60;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    { uint64_t l=(cpu->edx & 0xFFu), r=*(uint8_t*)(cpu->ecx + 1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003BA64;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0003BA44;
    label_0003BA60:
    cpu->eax = 0u;
    goto label_0003BA69;
    label_0003BA64:
    { uint64_t l=cpu->eax, r=cpu->eax, c=((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_0003BA69:
    if (cpu->eax != 0u) goto label_0003BA72;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x28u) >= (int32_t)cpu->eax) goto label_0003BAA9;
    label_0003BA72:
    ++cpu->ebx;
    cpu->esi += 0x34u;
    if ((int32_t)cpu->ebx < (int32_t)cpu->edi) goto label_0003BA40;
    cpu->eax = g_sfera_mbc_runtime->active_process;
    label_0003BA7F:
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xBCu);
    if (cpu->ecx == 0u) goto label_0003BAA4;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x230u);
    *(uint32_t*)(cpu->eax + 0xBCu) = cpu->edx;
    lift_push32(cpu, 0x1853u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3BAA4u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_RVA(0x3BAA4u));
    label_0003BAA4:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0003BAA7:
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003BAA9:
    cpu->eax = g_sfera_mbc_runtime->program_index;
    cpu->ecx = g_sfera_mbc_runtime->program_table_base;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    cpu->edi = g_sfera_mbc_runtime->bytecode_base;
    cpu->edi -= g_sfera_mbc_runtime->instruction_cursor;
    { uint64_t l=*(uint8_t*)(cpu->eax + cpu->ecx + 0x84u), r=0x14u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = cpu->eax + cpu->ecx + 0x84u;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0003BAE1;
    cpu->ecx = (uintptr_t)"Return stack overflow";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3BAE1u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x3BAE1u));
    label_0003BAE1:
    cpu->edx = *(uint8_t*)(cpu->esi);
    cpu->eax = g_sfera_mbc_runtime->active_program_record;
    *(uint32_t*)(cpu->eax + (cpu->edx * 4u) + 0x34u) = cpu->edi;
    ++*(uint8_t*)(cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BAF6u)); sfera_sub_0043B8F0(cpu, LIFT_CODE_TOKEN_VA(0x43BAF6u));
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x34u);
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x68u);
    cpu->eax = *(uint32_t*)(cpu->edx + cpu->ebx + 0x24u);
    cpu->eax += g_sfera_mbc_runtime->bytecode_base;
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_runtime->instruction_cursor = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->argument_end = cpu->eax;
    cpu->eax -= g_sfera_mbc_runtime->argument_count;
    cpu->ebx = lift_pop32(cpu);
    g_sfera_mbc_runtime->value_stack_size = cpu->eax;
    g_sfera_mbc_runtime->argument_cursor = cpu->eax;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043BB30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x1976u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = 0x100u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BB46u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x43BB46u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BB4Du)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43BB4Du));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    cpu->esp -= 8u;
    *(double*)(cpu->esp) = cpu->fpu[0u];
    lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)"MBInter:\n %f"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x43BB61u));
    cpu->esp += 0x10u;
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00459B10(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_0043BB80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    if (cpu->eax != 0u) goto label_0003BB96;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BB8Eu)); sfera_sub_004595F0(cpu, LIFT_CODE_TOKEN_VA(0x43BB8Eu));
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::exit), LIFT_CODE_TOKEN_RVA(0x3BB90u));
    label_0003BB96:
    if ((int32_t)cpu->eax <= (int32_t)1u) goto label_0003BBA5;
    g_sfera_network_runtime.active_slot = 0xFFFFFFFFu;
    label_0003BBA5:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BBAAu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43BBAAu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->ecx += g_sfera_mbc_runtime->process_memory_base;
    sfera_sub_00459B10(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_0043BBC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BBC6u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43BBC6u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BBD1u)); sfera_sub_004EE9F8(cpu, LIFT_CODE_TOKEN_VA(0x43BBD1u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BBE0u)); sfera_sub_0043AED0(cpu, LIFT_CODE_TOKEN_VA(0x43BBE0u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043BBF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BBF6u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43BBF6u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BC01u)); sfera_sub_004EE9F2(cpu, LIFT_CODE_TOKEN_VA(0x43BC01u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BC10u)); sfera_sub_0043AED0(cpu, LIFT_CODE_TOKEN_VA(0x43BC10u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043BC20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BC26u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43BC26u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BC31u)); sfera_sub_004EEC54(cpu, LIFT_CODE_TOKEN_VA(0x43BC31u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BC40u)); sfera_sub_0043AED0(cpu, LIFT_CODE_TOKEN_VA(0x43BC40u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043BC50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BC58u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43BC58u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BC60u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43BC60u));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BC70u)); sfera_sub_004EEC4E(cpu, LIFT_CODE_TOKEN_VA(0x43BC70u));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BC81u)); sfera_sub_0043AED0(cpu, LIFT_CODE_TOKEN_VA(0x43BC81u));
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043BC90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BC95u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43BC95u));
    if ((int32_t)cpu->eax >= 0) goto label_0003BC9B;
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    label_0003BC9B:
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->edx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003BCB3;
    cpu->ecx = (uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003BCB3:
    cpu->ecx = cpu->edx;
    cpu->ecx <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].payload[0] = cpu->eax;
    cpu->eax = 1u;
    cpu->edx += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_end = cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_begin = cpu->eax;
    g_sfera_mbc_runtime->value_stack_size = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043BCF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BCF6u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43BCF6u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0003BD11;
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    label_0003BD11:
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BD1Au)); sfera_sub_0043AED0(cpu, LIFT_CODE_TOKEN_VA(0x43BD1Au));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043BD20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->ecx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003BD38;
    cpu->ecx = (uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003BD38:
    cpu->edx = g_sfera_recovered_static_runtime.simulation_tick;
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = cpu->edx;
    cpu->edx = 1u;
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = cpu->edx;
    g_sfera_mbc_runtime->value_stack_size = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043BD80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x43BD81u));
    *(uint32_t*)(cpu->esp) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp)))));
    lift_push32(cpu, cpu->ecx);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0517578125e-05);
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BDA4u)); sfera_sub_0043AED0(cpu, LIFT_CODE_TOKEN_VA(0x43BDA4u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043BDB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    if (g_sfera_mbc_runtime->argument_count != 2u) goto label_0003BE83;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BDC7u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43BDC7u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BDCEu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43BDCEu));
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if ((int32_t)cpu->eax < (int32_t)0xFFFFFFFCu) goto label_0003BDDC;
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_0003BDEF;
    label_0003BDDC:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ecx == 0u) goto label_0003BDFB;
    if (cpu->eax < cpu->ecx) goto label_0003BDEF;
    cpu->eax += 0xBu;
    if (cpu->eax <= *(uint32_t*)(cpu->esi + 8u)) goto label_0003BDFB;
    label_0003BDEF:
    cpu->edx = 0xCu;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3BDFBu)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_RVA(0x3BDFBu));
    label_0003BDFB:
    cpu->eax = *(uint32_t*)(cpu->edi);
    if ((int32_t)cpu->eax < (int32_t)0xFFFFFFFCu) goto label_0003BE07;
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_0003BE1A;
    label_0003BE07:
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    if (cpu->ecx == 0u) goto label_0003BE26;
    if (cpu->eax < cpu->ecx) goto label_0003BE1A;
    cpu->eax += 0xBu;
    if (cpu->eax <= *(uint32_t*)(cpu->edi + 8u)) goto label_0003BE26;
    label_0003BE1A:
    cpu->edx = 0xCu;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3BE26u)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_RVA(0x3BE26u));
    label_0003BE26:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003BE7D;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->edi);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + cpu->edx + 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + cpu->edx + 4u)));
    cpu->ecx += cpu->edx;
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + cpu->edx));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx)));
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + cpu->edx + 8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 8u)));
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BE6Cu)); sfera_sub_004EE9EC(cpu, LIFT_CODE_TOKEN_VA(0x43BE6Cu));
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3BE7Du)); sfera_sub_0043AED0(cpu, LIFT_CODE_TOKEN_RVA(0x3BE7Du));
    label_0003BE7D:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003BE83:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BE88u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43BE88u));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BE91u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43BE91u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BE99u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43BE99u));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BEA2u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43BEA2u));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    if (cpu->eax != 4u) goto label_0003BEE9;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 8u)));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0xCu)));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BED4u)); sfera_sub_004EE9EC(cpu, LIFT_CODE_TOKEN_VA(0x43BED4u));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BEE5u)); sfera_sub_0043AED0(cpu, LIFT_CODE_TOKEN_VA(0x43BEE5u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003BEE9:
    if (cpu->eax != 5u) goto label_0003BF1A;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    lift_push32(cpu, cpu->ecx);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0xCu)));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x10u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BF16u)); sfera_sub_0043AED0(cpu, LIFT_CODE_TOKEN_VA(0x43BF16u));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003BF1A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BF1Fu)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43BF1Fu));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BF28u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43BF28u));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=6u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x10u)));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 8u)));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x14u)));
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003BF7E;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BF69u)); sfera_sub_004EE9EC(cpu, LIFT_CODE_TOKEN_VA(0x43BF69u));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BF7Au)); sfera_sub_0043AED0(cpu, LIFT_CODE_TOKEN_VA(0x43BF7Au));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003BF7E:
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BF8Fu)); sfera_sub_0043AED0(cpu, LIFT_CODE_TOKEN_VA(0x43BF8Fu));
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043BFA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BFA7u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43BFA7u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BFAEu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43BFAEu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BFB5u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43BFB5u));
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    if ((int32_t)cpu->edx < (int32_t)0x100u) goto label_0003BFCF;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (uintptr_t)"Stack overflow";
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003BFCF:
    { uint64_t l=cpu->esi, r=0xFFFFFF00u, v=l | r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    cpu->esi <<= 8u;
    cpu->edi &= 0xFFu;
    { uint64_t l=cpu->esi, r=cpu->edi, v=l | r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    cpu->esi <<= 8u;
    { uint64_t l=cpu->eax, r=0xFFu, v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->ecx = cpu->edx;
    cpu->ecx <<= 5u;
    cpu->esi |= cpu->eax;
    cpu->eax = 1u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].payload[0] = cpu->esi;
    cpu->edx += cpu->eax;
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_end = cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_begin = cpu->eax;
    g_sfera_mbc_runtime->value_stack_size = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043C030(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C03Au)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43C03Au));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C041u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43C041u));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ebx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->ebx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003C062;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (uintptr_t)"Stack overflow";
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003C062:
    cpu->eax = cpu->edi;
    cpu->eax = (int32_t)(cpu->eax) >> 16u;
    { uint64_t l=cpu->eax, r=0xFFu, v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u)))));
    lift_push32(cpu, cpu->ebp);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_push32(cpu, cpu->esi);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->esi = cpu->ebx;
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esi <<= 5u;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->esi >> 5u].type = 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C094u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x43C094u));
    cpu->ecx = cpu->edi;
    cpu->ecx = (int32_t)(cpu->ecx) >> 8u;
    cpu->ecx &= 0xFFu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    cpu->ebp = cpu->eax;
    { uint64_t l=cpu->ebp, r=0xFFFFFF00u, v=l | r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    cpu->ebp = cpu->ebp << 8u;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C0B9u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x43C0B9u));
    cpu->edi &= 0xFFu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    cpu->fpu[0u] = (cpu->fpu[0u]) * ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    cpu->eax &= 0xFFu;
    { uint64_t l=cpu->ebp, r=cpu->eax, v=l | r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    cpu->ebp = cpu->ebp << 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C0D6u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x43C0D6u));
    cpu->eax &= 0xFFu;
    cpu->ebp |= cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->esi >> 5u].payload[0] = cpu->ebp;
    cpu->eax = 1u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->esi >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->esi >> 5u].range_end = cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->esi >> 5u].range_begin = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ebx += cpu->eax;
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_runtime->value_stack_size = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043C110(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C116u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43C116u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0003C131;
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    label_0003C131:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C136u)); sfera_sub_004EE9EC(cpu, LIFT_CODE_TOKEN_VA(0x43C136u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C145u)); sfera_sub_0043AED0(cpu, LIFT_CODE_TOKEN_VA(0x43C145u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043C150(LiftCpu* cpu, uint32_t stop_address) {
    if (g_sfera_mbc_runtime->argument_count != 0u) goto label_0003C164;
    cpu->ecx = g_sfera_scene_control_runtime.active_context;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3C164u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x3C164u));
    label_0003C164:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C169u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43C169u));
    if (cpu->eax != 0u) goto label_0003C178;
    cpu->ecx = g_sfera_scene_control_runtime.active_context;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003C178:
    if (cpu->eax != 1u) goto label_0003C188;
    cpu->ecx = g_sfera_world_load_runtime.active_tool_context;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003C188:
    cpu->ecx = g_sfera_recovered_static_runtime.graphics_state;
    sfera_sub_0043B0D0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_0043C1A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C1A5u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43C1A5u));
    if (g_sfera_texture_cache_runtime.cache_enabled == 0u) goto label_0003C1BA;
    cpu->ecx = (int8_t)(*(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_direct_input_runtime.keyboard_state[0])));
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003C1BA:
    cpu->ecx = 0u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_0043C1D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C1D7u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43C1D7u));
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=1u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003C1EB;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C1E7u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43C1E7u));
    cpu->edi = cpu->eax;
    goto label_0003C1EE;
    label_0003C1EB:
    cpu->edi |= 0xFFFFFFFFu;
    label_0003C1EE:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003C22B;
    if (cpu->esi != 0u) goto label_0003C20D;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffprc_load\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C20Au)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x43C20Au));
    cpu->esp += 8u;
    label_0003C20D:
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = cpu->ecx + cpu->esi;
    cpu->edx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C21Du)); sfera_sub_00435230(cpu, LIFT_CODE_TOKEN_VA(0x43C21Du));
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_runtime->active_tag = cpu->eax;
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003C22B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043C230(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C236u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43C236u));
    if (cpu->eax > 0xFFFFu) goto label_0003C25A;
    cpu->ecx = cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x348u);
    if (*(uint32_t*)(cpu->ecx + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id)) != cpu->eax) goto label_0003C25A;
    if ((int32_t)*(uint32_t*)(cpu->ecx + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index)) < (int32_t)0u) goto label_0003C25A;
    cpu->esi = cpu->eax;
    goto label_0003C25D;
    label_0003C25A:
    cpu->esi |= 0xFFFFFFFFu;
    label_0003C25D:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003C2B0;
    if (cpu->esi != g_sfera_mbc_runtime->process_index) goto label_0003C281;
    g_sfera_mbc_runtime->active_tag = 0xFFFFFFFFu;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003C281:
    if (cpu->esi != 0u) goto label_0003C29C;
    lift_push32(cpu, 0x1A42u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp"); lift_push32(cpu, (uintptr_t)"Unloading _main: %s:%d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C299u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x43C299u));
    cpu->esp += 0xCu;
    label_0003C29C:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C2A3u)); sfera_sub_00435D40(cpu, LIFT_CODE_TOKEN_VA(0x43C2A3u));
    g_sfera_mbc_runtime->active_tag = cpu->eax;
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003C2B0:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043C2C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C2C6u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43C2C6u));
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi != 0u) goto label_0003C2DE;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffprc_link\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C2DBu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x43C2DBu));
    cpu->esp += 8u;
    label_0003C2DE:
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = cpu->ecx + cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C2ECu)); sfera_sub_004386C0(cpu, LIFT_CODE_TOKEN_VA(0x43C2ECu));
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    g_sfera_mbc_runtime->active_tag = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    { uint64_t l=cpu->edx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003C30A;
    cpu->ecx = (uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003C30A:
    cpu->ecx = cpu->edx;
    cpu->ecx <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].payload[0] = cpu->eax;
    cpu->eax = 1u;
    cpu->edx += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_end = cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_begin = cpu->eax;
    g_sfera_mbc_runtime->value_stack_size = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043C350(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C355u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43C355u));
    if (cpu->eax > 0xFFFFu) goto label_0003C375;
    cpu->ecx = cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x348u);
    if (*(uint32_t*)(cpu->ecx + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id)) != cpu->eax) goto label_0003C375;
    if ((int32_t)*(uint32_t*)(cpu->ecx + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index)) >= (int32_t)0u) goto label_0003C378;
    label_0003C375:
    cpu->eax |= 0xFFFFFFFFu;
    label_0003C378:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003C39E;
    if ((int32_t)cpu->eax >= 0) goto label_0003C38D;
    cpu->ecx |= 0xFFFFFFFFu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003C38D:
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    cpu->ecx = *(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].module_tag));
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003C39E:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043C3A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->eax <<= 5u;
    cpu->esi = 1u;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = g_sfera_mbc_runtime->process_chain_first;
    *(uint32_t*)(cpu->esp + 0x10u) = 0xFFFFFFFFu;
    if ((uint32_t)(g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type) != cpu->esi) goto label_0003C3F1;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C3CFu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43C3CFu));
    cpu->ebp = *(uint32_t*)(cpu->eax);
    if (cpu->ebp != 0u) goto label_0003C3E7;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffprc_id\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C3E4u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x43C3E4u));
    cpu->esp += 8u;
    label_0003C3E7:
    cpu->ebx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ebx += cpu->ebp;
    goto label_0003C3F8;
    label_0003C3F1:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C3F6u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43C3F6u));
    cpu->ebp = cpu->eax;
    label_0003C3F8:
    if ((int32_t)g_sfera_mbc_runtime->argument_count <= (int32_t)cpu->esi) goto label_0003C428;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C405u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43C405u));
    if (cpu->eax > 0xFFFFu) goto label_0003C4E0;
    cpu->edx = cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    cpu->ecx = *(uint32_t*)(cpu->edx + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_next_index));
    if (cpu->ecx == cpu->eax) goto label_0003C4E0;
    cpu->edi = cpu->ecx;
    label_0003C428:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003C4F0;
    label_0003C440:
    cpu->esi = cpu->edi;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    if (*(uint32_t*)(cpu->esi + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index)) == 0xFFFFFFFFu) goto label_0003C4E0;
    if (cpu->ebx == 0u) goto label_0003C4A8;
    cpu->ecx = cpu->esi + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].name[0]);
    cpu->eax = cpu->ebx;
    label_0003C461:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    { uint64_t l=(cpu->edx & 0xFFu), r=*(uint8_t*)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003C481;
    if ((cpu->edx & 0xFFu) == 0u) goto label_0003C47D;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    { uint64_t l=(cpu->edx & 0xFFu), r=*(uint8_t*)(cpu->ecx + 1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003C481;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0003C461;
    label_0003C47D:
    cpu->eax = 0u;
    goto label_0003C486;
    label_0003C481:
    { uint64_t l=cpu->eax, r=cpu->eax, c=((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_0003C486:
    if (cpu->eax != 0u) goto label_0003C4B4;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x348u);
    cpu->eax = *(uint32_t*)(cpu->edi + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    cpu->ecx = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003C4A8:
    if (cpu->ebp == *(uint32_t*)(cpu->esi + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].module_tag))) goto label_0003C4D0;
    if (cpu->ebp == 0u) goto label_0003C4D0;
    label_0003C4B4:
    cpu->eax = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_next_index));
    if (cpu->edi != cpu->eax) goto label_0003C440;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003C4D0:
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x348u);
    cpu->ecx = *(uint32_t*)(cpu->edi + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    label_0003C4E0:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003C4F0:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043C770(LiftCpu* cpu, uint32_t stop_address) {
    goto label_0003C770;
    label_0003C500:
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    cpu->esi += ((uintptr_t)&g_sfera_mbc_runtime->processes[0]);
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x68u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003C53F;
    cpu->ecx |= 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C52Fu)); sfera_sub_0043AFA0(cpu, LIFT_CODE_TOKEN_VA(0x43C52Fu));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003C53F:
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    lift_push32(cpu, cpu->ebx);
    cpu->eax <<= 5u;
    { uint64_t l=(uint64_t)(g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type), r=1u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003C5EF;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C55Cu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43C55Cu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->ecx += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, 0x1Fu); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x43C56Cu));
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x64u);
    cpu->edi = 0u;
    cpu->esp += 0xCu;
    *(uint8_t*)(cpu->esp + 0x37u) = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    if ((int32_t)cpu->ebp <= 0) goto label_0003C5D0;
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x68u);
    label_0003C590:
    cpu->ecx = cpu->ebx;
    cpu->eax = cpu->esp + 0x18u;
    label_0003C596:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    { uint64_t l=(cpu->edx & 0xFFu), r=*(uint8_t*)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003C5B6;
    if ((cpu->edx & 0xFFu) == 0u) goto label_0003C5B2;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    { uint64_t l=(cpu->edx & 0xFFu), r=*(uint8_t*)(cpu->ecx + 1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003C5B6;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0003C596;
    label_0003C5B2:
    cpu->eax = 0u;
    goto label_0003C5BB;
    label_0003C5B6:
    { uint64_t l=cpu->eax, r=cpu->eax, c=((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_0003C5BB:
    if (cpu->eax != 0u) goto label_0003C5C4;
    if ((int32_t)*(uint32_t*)(cpu->ebx + 0x28u) >= (int32_t)cpu->eax) goto label_0003C5CC;
    label_0003C5C4:
    ++cpu->edi;
    cpu->ebx += 0x34u;
    if ((int32_t)cpu->edi < (int32_t)cpu->ebp) goto label_0003C590;
    label_0003C5CC:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    label_0003C5D0:
    if ((int32_t)cpu->edi < (int32_t)cpu->ebp) goto label_0003C609;
    label_0003C5D4:
    cpu->ecx |= 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C5DCu)); sfera_sub_0043AFA0(cpu, LIFT_CODE_TOKEN_VA(0x43C5DCu));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003C5EF:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C5F4u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43C5F4u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xC4u);
    cpu->eax = *(uint16_t*)(cpu->ecx + (cpu->eax * 2u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (cpu->eax == 0xFFFFu) goto label_0003C5D4;
    label_0003C609:
    cpu->ebp = g_sfera_mbc_runtime->execution_context_depth;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi = g_sfera_mbc_runtime->process_index;
    cpu->edx = g_sfera_mbc_runtime->bytecode_base;
    cpu->ebx = g_sfera_mbc_runtime->program_table_base;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].process_index = cpu->edi;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x348u);
    cpu->edi = *(uint32_t*)(cpu->edi + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id));
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].process_memory_base = cpu->ecx;
    cpu->ecx = g_sfera_mbc_runtime->program_index;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].program_index = cpu->ecx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xA4u);
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].bytecode_base = cpu->edx;
    cpu->edx = g_sfera_mbc_runtime->instruction_cursor;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].process_id = cpu->edi;
    cpu->edi = g_sfera_mbc_runtime->active_process;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].instruction_cursor = cpu->edx;
    cpu->edx -= g_sfera_mbc_runtime->bytecode_base;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].active_process = cpu->edi;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].program_table_base = cpu->ebx;
    cpu->ecx += cpu->ebx;
    g_sfera_mbc_runtime->active_program_record = cpu->ecx;
    ++cpu->ebp;
    g_sfera_mbc_runtime->execution_context_depth = cpu->ebp;
    *(uint32_t*)(cpu->ecx + 0x88u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x5Cu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x34u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x48u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x68u);
    g_sfera_mbc_runtime->bytecode_base = cpu->edi;
    g_sfera_mbc_runtime->program_table_base = cpu->edx;
    cpu->ebx = *(uint32_t*)(cpu->eax + cpu->ecx + 0x24u);
    cpu->ebx += cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x50u);
    g_sfera_mbc_runtime->process_memory_base = cpu->edi;
    g_sfera_mbc_runtime->instruction_cursor = cpu->ebx;
    cpu->eax = *(uint32_t*)(cpu->eax + cpu->ecx + 0x28u);
    g_sfera_mbc_runtime->program_index = cpu->eax;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    cpu->edi = cpu->eax + cpu->edx;
    g_sfera_mbc_runtime->active_program_record = cpu->edi;
    *(uint8_t*)(cpu->edx + cpu->eax + 0x84u) = 0u;
    cpu->eax = g_sfera_mbc_runtime->program_index;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x5Cu);
    cpu->edx = cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xA4u);
    if (*(uint8_t*)(cpu->edx + cpu->edi + 0x94u) == 0u) goto label_0003C731;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x68u);
    if (*(uint32_t*)(cpu->edx + cpu->ecx + 0x2Cu) != 0u) goto label_0003C731;
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x44u);
    cpu->edx = g_sfera_mbc_runtime->process_index;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x44u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"Double \"func\" call, prob. stack corruption: %s (prc %d, tag %d), called from (prc %d, tag %d).\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C729u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x43C729u));
    cpu->eax = g_sfera_mbc_runtime->program_index;
    cpu->esp += 0x1Cu;
    label_0003C731:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x5Cu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + cpu->ecx + 0x94u) = 1u;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    g_sfera_mbc_runtime->active_process = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->process_index = cpu->edx;
    g_sfera_mbc_runtime->active_tag = 0u;
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003C770:
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=2u, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); g_sfera_mbc_runtime->argument_count = (uint32_t)((v)); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0003C781;
    cpu->ecx |= 0xFFFFFFFFu;
    sfera_sub_0043AFA0(cpu, stop_address); return;
    label_0003C781:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C786u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43C786u));
    if (cpu->eax > 0xFFFFu) goto label_0003C7AA;
    cpu->edx = cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    if (*(uint32_t*)(cpu->edx + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id)) != cpu->eax) goto label_0003C7AA;
    if ((int32_t)*(uint32_t*)(cpu->edx + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index)) < (int32_t)0u) goto label_0003C7AA;
    if ((int32_t)cpu->eax > 0) goto label_0003C7B2;
    label_0003C7AA:
    cpu->ecx |= 0xFFFFFFFFu;
    sfera_sub_0043AFA0(cpu, stop_address); return;
    label_0003C7B2:
    cpu->ecx = cpu->eax;
    goto label_0003C500;
}
__declspec(noinline) void sfera_sub_0043C7C0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_0003C7C0;
    label_0003C500:
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    cpu->esi += ((uintptr_t)&g_sfera_mbc_runtime->processes[0]);
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x68u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003C53F;
    cpu->ecx |= 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C52Fu)); sfera_sub_0043AFA0(cpu, LIFT_CODE_TOKEN_VA(0x43C52Fu));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003C53F:
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    lift_push32(cpu, cpu->ebx);
    cpu->eax <<= 5u;
    { uint64_t l=(uint64_t)(g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type), r=1u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003C5EF;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C55Cu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43C55Cu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->ecx += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, 0x1Fu); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x43C56Cu));
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x64u);
    cpu->edi = 0u;
    cpu->esp += 0xCu;
    *(uint8_t*)(cpu->esp + 0x37u) = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    if ((int32_t)cpu->ebp <= 0) goto label_0003C5D0;
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x68u);
    label_0003C590:
    cpu->ecx = cpu->ebx;
    cpu->eax = cpu->esp + 0x18u;
    label_0003C596:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    { uint64_t l=(cpu->edx & 0xFFu), r=*(uint8_t*)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003C5B6;
    if ((cpu->edx & 0xFFu) == 0u) goto label_0003C5B2;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    { uint64_t l=(cpu->edx & 0xFFu), r=*(uint8_t*)(cpu->ecx + 1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003C5B6;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0003C596;
    label_0003C5B2:
    cpu->eax = 0u;
    goto label_0003C5BB;
    label_0003C5B6:
    { uint64_t l=cpu->eax, r=cpu->eax, c=((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_0003C5BB:
    if (cpu->eax != 0u) goto label_0003C5C4;
    if ((int32_t)*(uint32_t*)(cpu->ebx + 0x28u) >= (int32_t)cpu->eax) goto label_0003C5CC;
    label_0003C5C4:
    ++cpu->edi;
    cpu->ebx += 0x34u;
    if ((int32_t)cpu->edi < (int32_t)cpu->ebp) goto label_0003C590;
    label_0003C5CC:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    label_0003C5D0:
    if ((int32_t)cpu->edi < (int32_t)cpu->ebp) goto label_0003C609;
    label_0003C5D4:
    cpu->ecx |= 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C5DCu)); sfera_sub_0043AFA0(cpu, LIFT_CODE_TOKEN_VA(0x43C5DCu));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003C5EF:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C5F4u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43C5F4u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xC4u);
    cpu->eax = *(uint16_t*)(cpu->ecx + (cpu->eax * 2u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (cpu->eax == 0xFFFFu) goto label_0003C5D4;
    label_0003C609:
    cpu->ebp = g_sfera_mbc_runtime->execution_context_depth;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi = g_sfera_mbc_runtime->process_index;
    cpu->edx = g_sfera_mbc_runtime->bytecode_base;
    cpu->ebx = g_sfera_mbc_runtime->program_table_base;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].process_index = cpu->edi;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x348u);
    cpu->edi = *(uint32_t*)(cpu->edi + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id));
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].process_memory_base = cpu->ecx;
    cpu->ecx = g_sfera_mbc_runtime->program_index;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].program_index = cpu->ecx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xA4u);
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].bytecode_base = cpu->edx;
    cpu->edx = g_sfera_mbc_runtime->instruction_cursor;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].process_id = cpu->edi;
    cpu->edi = g_sfera_mbc_runtime->active_process;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].instruction_cursor = cpu->edx;
    cpu->edx -= g_sfera_mbc_runtime->bytecode_base;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].active_process = cpu->edi;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].program_table_base = cpu->ebx;
    cpu->ecx += cpu->ebx;
    g_sfera_mbc_runtime->active_program_record = cpu->ecx;
    ++cpu->ebp;
    g_sfera_mbc_runtime->execution_context_depth = cpu->ebp;
    *(uint32_t*)(cpu->ecx + 0x88u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x5Cu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x34u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x48u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x68u);
    g_sfera_mbc_runtime->bytecode_base = cpu->edi;
    g_sfera_mbc_runtime->program_table_base = cpu->edx;
    cpu->ebx = *(uint32_t*)(cpu->eax + cpu->ecx + 0x24u);
    cpu->ebx += cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x50u);
    g_sfera_mbc_runtime->process_memory_base = cpu->edi;
    g_sfera_mbc_runtime->instruction_cursor = cpu->ebx;
    cpu->eax = *(uint32_t*)(cpu->eax + cpu->ecx + 0x28u);
    g_sfera_mbc_runtime->program_index = cpu->eax;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    cpu->edi = cpu->eax + cpu->edx;
    g_sfera_mbc_runtime->active_program_record = cpu->edi;
    *(uint8_t*)(cpu->edx + cpu->eax + 0x84u) = 0u;
    cpu->eax = g_sfera_mbc_runtime->program_index;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x5Cu);
    cpu->edx = cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xA4u);
    if (*(uint8_t*)(cpu->edx + cpu->edi + 0x94u) == 0u) goto label_0003C731;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x68u);
    if (*(uint32_t*)(cpu->edx + cpu->ecx + 0x2Cu) != 0u) goto label_0003C731;
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x44u);
    cpu->edx = g_sfera_mbc_runtime->process_index;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x44u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"Double \"func\" call, prob. stack corruption: %s (prc %d, tag %d), called from (prc %d, tag %d).\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C729u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x43C729u));
    cpu->eax = g_sfera_mbc_runtime->program_index;
    cpu->esp += 0x1Cu;
    label_0003C731:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x5Cu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + cpu->ecx + 0x94u) = 1u;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    g_sfera_mbc_runtime->active_process = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->process_index = cpu->edx;
    g_sfera_mbc_runtime->active_tag = 0u;
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003C7C0:
    { uint64_t l=g_sfera_mbc_runtime->argument_count, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; g_sfera_mbc_runtime->argument_count = (uint32_t)((v)); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0003C7D0;
    cpu->ecx |= 0xFFFFFFFFu;
    sfera_sub_0043AFA0(cpu, stop_address); return;
    label_0003C7D0:
    cpu->ecx = 0u;
    goto label_0003C500;
}
__declspec(noinline) void sfera_sub_0043C7E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->ecx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003C7F8;
    cpu->ecx = (uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003C7F8:
    cpu->edx = g_sfera_mbc_runtime->active_tag;
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = cpu->edx;
    cpu->edx = 1u;
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = cpu->edx;
    g_sfera_mbc_runtime->value_stack_size = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043C840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->ecx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003C858;
    cpu->ecx = (uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003C858:
    cpu->edx = g_sfera_mbc_runtime->argument_count;
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = cpu->edx;
    cpu->edx = 1u;
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = cpu->edx;
    g_sfera_mbc_runtime->value_stack_size = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043C8A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->process_index;
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    cpu->edx = *(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].module_tag));
    { uint64_t l=cpu->ecx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003C8C9;
    cpu->ecx = (uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003C8C9:
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = cpu->edx;
    cpu->edx = 1u;
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = cpu->edx;
    g_sfera_mbc_runtime->value_stack_size = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043C910(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->process_index;
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    cpu->edx = *(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id));
    { uint64_t l=cpu->ecx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003C939;
    cpu->ecx = (uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003C939:
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = cpu->edx;
    cpu->edx = 1u;
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = cpu->edx;
    g_sfera_mbc_runtime->value_stack_size = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043C980(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = 1u;
    lift_push32(cpu, cpu->edi);
    if ((int32_t)g_sfera_mbc_runtime->argument_count < (int32_t)cpu->esi) goto label_0003CC86;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C9A9u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43C9A9u));
    g_sfera_mbc_runtime->argument_count -= cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    if (cpu->eax != 0xFFFFFFFEu) goto label_0003C9CA;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C9BCu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43C9BCu));
    g_sfera_mbc_runtime->argument_count -= cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    goto label_0003CAC3;
    label_0003C9CA:
    if (cpu->eax != 0xFFFFFFFCu) goto label_0003C9E2;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C9D4u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43C9D4u));
    g_sfera_mbc_runtime->argument_count -= cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    goto label_0003CAC3;
    label_0003C9E2:
    if (cpu->eax != 0xFFFFFFFBu) goto label_0003C9FA;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C9ECu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43C9ECu));
    g_sfera_mbc_runtime->argument_count -= cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    goto label_0003CAC3;
    label_0003C9FA:
    if (cpu->eax != 0xFFFFFFF9u) goto label_0003CAB1;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43CA08u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43CA08u));
    g_sfera_mbc_runtime->argument_count -= cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    cpu->eax = 0x100u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43CA1Bu)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x43CA1Bu));
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = g_sfera_mbc_runtime->argument_cursor;
    cpu->ebx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43CA33u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43CA33u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43CA38u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43CA38u));
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43CA45u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43CA45u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43CA4Au)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43CA4Au));
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43CA57u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43CA57u));
    *(uint8_t*)(cpu->ebx + 1u) = cpu->eax & 0xFFu;
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003CC9E;
    cpu->edx = cpu->ebx + 2u;
    *(uint8_t*)(cpu->ebx) = 5u;
    cpu->eax = cpu->esi;
    cpu->edx -= cpu->esi;
    label_0003CA71:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0003CA71;
    cpu->ecx = cpu->esi + 1u;
    label_0003CA80:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    ++cpu->esi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0003CA80;
    cpu->esi -= cpu->ecx;
    cpu->edx = cpu->esi + cpu->ebx + 3u;
    cpu->eax = cpu->edi;
    cpu->edx -= cpu->edi;
    label_0003CA91:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0003CA91;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    g_sfera_mbc_runtime->argument_cursor = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    g_sfera_mbc_runtime->value_stack_size = cpu->edx;
    goto label_0003CAC3;
    label_0003CAB1:
    if (cpu->eax == 0xFFFFFFFFu) goto label_0003CC9E;
    if (cpu->eax == 0xFFFFFFFDu) goto label_0003CC9E;
    label_0003CAC3:
    if (cpu->eax > 0x3Du) goto label_0003CC94;
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->edx = *(uint32_t*)(cpu->edx + 0xD0u);
    cpu->ecx = cpu->eax + (cpu->eax * 8u);
    cpu->esi = cpu->edx + (cpu->ecx * 4u);
    cpu->edx = (int8_t)(*(uint8_t*)(cpu->esi + 0x20u));
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->edx;
    if (cpu->edx != 0xFFFFFFFFu) goto label_0003CAF7;
    cpu->ecx = (uintptr_t)"Wrong flags for 'send' function";
    goto label_0003CC99;
    label_0003CAF7:
    cpu->edi = 0u;
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->send_field_count = cpu->edi;
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x1Cu), r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003CC65;
    label_0003CB0A:
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax <<= 5u;
    cpu->ebx = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0];
    cpu->eax = 1u;
    g_sfera_mbc_runtime->argument_cursor += cpu->eax;
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=cpu->eax, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); g_sfera_mbc_runtime->argument_count = (uint32_t)((v)); }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_0003CC86;
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->ecx + cpu->esi));
    if ((int32_t)cpu->eax > (int32_t)0x20u) goto label_0003CB3D;
    if ((int32_t)cpu->eax >= (int32_t)0xFFFFFFE0u) goto label_0003CB45;
    label_0003CB3D:
    cpu->edx = cpu->eax + 0xFFFFFF99u;
    if (cpu->edx > 5u) goto label_0003CB5C;
    label_0003CB45:
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    *(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_mbc_interpreter_storage.send_field_data[0])) = cpu->ebx;
    *(uint8_t*)(cpu->edi + ((uintptr_t)&g_sfera_mbc_runtime->send_field_width[0])) = cpu->eax & 0xFFu;
    goto label_0003CC4E;
    label_0003CB5C:
    if (cpu->eax != 0x65u) goto label_0003CB7C;
    *(uint8_t*)(cpu->edi + ((uintptr_t)&g_sfera_mbc_runtime->send_field_width[0])) = 4u;
    if ((int32_t)cpu->ebx >= 0) goto label_0003CB70;
    cpu->ebx = 0u;
    goto label_0003CBA1;
    label_0003CB70:
    if ((int32_t)cpu->ebx <= (int32_t)0xFu) goto label_0003CBA1;
    cpu->ebx = 0xFu;
    goto label_0003CBA1;
    label_0003CB7C:
    if (cpu->eax != 0x66u) goto label_0003CC4E;
    *(uint8_t*)(cpu->edi + ((uintptr_t)&g_sfera_mbc_runtime->send_field_width[0])) = 8u;
    if ((int32_t)cpu->ebx >= 0) goto label_0003CB94;
    cpu->ebx = 0u;
    goto label_0003CBA1;
    label_0003CB94:
    if ((int32_t)cpu->ebx <= (int32_t)0xFFu) goto label_0003CBA1;
    cpu->ebx = 0xFFu;
    label_0003CBA1:
    { uint64_t l=g_sfera_mbc_runtime->argument_count, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; g_sfera_mbc_runtime->argument_count = (uint32_t)((v)); }
    *(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_mbc_interpreter_storage.send_field_data[0])) = cpu->ebx;
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_0003CC8D;
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->ecx;
    if ((int32_t)cpu->ecx >= (int32_t)*(uint32_t*)(cpu->esi + 0x1Cu)) goto label_0003CC8D;
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->ecx + cpu->esi));
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->eax;
    { uint64_t l=cpu->eax, r=0x20u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0003CC8D;
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax <<= 5u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type;
    if ((((cpu->eax & 0xFFu)) & (0xFu)) == 0u) goto label_0003CC8D;
    cpu->ecx = cpu->eax + 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43CBF7u)); sfera_sub_00433BB0(cpu, LIFT_CODE_TOKEN_VA(0x43CBF7u));
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->edx = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0];
    cpu->edx += *(uint32_t*)(cpu->ecx + 0x50u);
    ++g_sfera_mbc_runtime->argument_cursor;
    if ((int32_t)cpu->ebx <= 0) goto label_0003CC48;
    label_0003CC15:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp + 0xFFFFFFE8u));
    ++cpu->edi;
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->send_field_count = cpu->edi;
    *(uint8_t*)(cpu->edi + ((uintptr_t)&g_sfera_mbc_runtime->send_field_width[0])) = cpu->eax & 0xFFu;
    *(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_mbc_interpreter_storage.send_field_data[0])) = cpu->ecx;
    if ((int32_t)cpu->esi <= (int32_t)cpu->ecx) goto label_0003CC41;
    label_0003CC32:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + cpu->edx));
    *(uint8_t*)(cpu->ecx + (cpu->edi * 4u) + ((uintptr_t)&g_sfera_mbc_interpreter_storage.send_field_data[0])) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)cpu->esi) goto label_0003CC32;
    label_0003CC41:
    --cpu->ebx;
    cpu->edx += cpu->esi;
    if ((int32_t)cpu->ebx > 0) goto label_0003CC15;
    label_0003CC48:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u);
    label_0003CC4E:
    ++cpu->edi;
    ++cpu->ecx;
    g_sfera_mbc_runtime->send_field_count = cpu->edi;
    { uint64_t l=cpu->ecx, r=*(uint32_t*)(cpu->esi + 0x1Cu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003CB0A;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    label_0003CC65:
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax;
    cpu->ecx = 0x190u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43CC72u)); sfera_sub_00439C30(cpu, LIFT_CODE_TOKEN_VA(0x43CC72u));
    cpu->esp = cpu->ebp + 0xFFFFFFD8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003CC86:
    cpu->ecx = (uintptr_t)"Wrong number of parameters for 'send' function";
    goto label_0003CC99;
    label_0003CC8D:
    cpu->ecx = (uintptr_t)"Wrong data for 'send' function";
    goto label_0003CC99;
    label_0003CC94:
    cpu->ecx = (uintptr_t)"Wrong region for 'send' function";
    label_0003CC99:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3CC9Eu)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x3CC9Eu));
    label_0003CC9E:
    cpu->esp = cpu->ebp + 0xFFFFFFD8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043CCC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x38u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = 1u;
    lift_push32(cpu, cpu->edi);
    if ((int32_t)g_sfera_mbc_runtime->argument_count < (int32_t)cpu->esi) goto label_0003D37C;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43CCDDu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43CCDDu));
    g_sfera_mbc_runtime->argument_count -= cpu->esi;
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ecx;
    if (cpu->ecx > 0x3Du) goto label_0003D38D;
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->ecx * 4u) + 0x1D8u);
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->esi;
    if (cpu->esi != cpu->ebp) goto label_0003CD17;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003CD17:
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax + (cpu->ecx * 4u) + 0x1D8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edi = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->eax = *(uint32_t*)(cpu->eax + 0xD0u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edx;
    cpu->edx = cpu->ecx + (cpu->ecx * 8u);
    cpu->eax = cpu->eax + (cpu->edx * 4u);
    cpu->edx = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    if ((int32_t)*(uint32_t*)(cpu->eax + 0x1Cu) <= (int32_t)cpu->ebp) goto label_0003D322;
    label_0003CD68:
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->edx + cpu->eax));
    cpu->ebx = 0u;
    if ((int32_t)cpu->eax >= (int32_t)cpu->ebx) goto label_0003CDAA;
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    lift_push32(cpu, 4u);
    cpu->esi = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43CD8Eu)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_VA(0x43CD8Eu));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = 0x20u;
    { uint64_t l=cpu->ecx, r=cpu->esi, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx <<= (((cpu->ecx & 0xFFu)) & 31u);
    cpu->edx = (int32_t)(cpu->edx) >> (((cpu->ecx & 0xFFu)) & 31u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    goto label_0003D26E;
    label_0003CDAA:
    if ((int32_t)cpu->eax > (int32_t)0x20u) goto label_0003CDD0;
    lift_push32(cpu, 4u); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->edx = 0u;
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43CDC7u)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_VA(0x43CDC7u));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    goto label_0003D26E;
    label_0003CDD0:
    { uint64_t l=cpu->eax, r=0x67u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CFB5;
    cpu->eax = cpu->ebp;
    cpu->eax = (int32_t)(cpu->eax) >> 3u;
    cpu->edx = cpu->eax * 8u;
    cpu->ecx = cpu->ebp;
    { uint64_t l=cpu->ecx, r=cpu->edx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (((uint8_t)((cpu->edx & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u)));
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    cpu->ecx = cpu->ebp + 1u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    { uint64_t l=*(uint8_t*)(cpu->eax + cpu->edi), r=(cpu->edx & 0xFFu), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->edx = cpu->ebp + 1u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    *(uint8_t*)(cpu->esp + 0x2Cu) = cpu->eax & 0xFFu;
    cpu->eax = cpu->edx * 8u;
    { uint64_t l=cpu->ecx, r=cpu->eax, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (((uint8_t)((cpu->eax & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u)));
    cpu->edx += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    { uint64_t l=*(uint8_t*)(cpu->edx), r=(cpu->eax & 0xFFu), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t l=(cpu->eax & 0xFFu), r=(cpu->eax & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CE27;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->edx;
    label_0003CE27:
    if ((uint8_t)((*(uint8_t*)(cpu->edx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_0003CE30;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) | (uint64_t)(2u))) & 0xFFu);
    goto label_0003CE33;
    label_0003CE30:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFDu))) & 0xFFu);
    label_0003CE33:
    *(uint8_t*)(cpu->esp + 0x14u) = cpu->ecx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebp += 3u;
    cpu->ecx = cpu->ebp;
    { uint64_t l=cpu->eax, r=cpu->ebx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CE99;
    cpu->edx = cpu->ebp;
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->eax = cpu->edx * 8u;
    { uint64_t l=cpu->ecx, r=cpu->eax, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (((uint8_t)((cpu->eax & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u)));
    cpu->edx += cpu->edi;
    { uint64_t l=*(uint8_t*)(cpu->edx), r=(cpu->eax & 0xFFu), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t l=(cpu->eax & 0xFFu), r=(cpu->eax & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CE64;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->edx;
    label_0003CE64:
    if ((uint8_t)((*(uint8_t*)(cpu->edx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_0003CE6D;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) | (uint64_t)(2u))) & 0xFFu);
    goto label_0003CE70;
    label_0003CE6D:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFDu))) & 0xFFu);
    label_0003CE70:
    { uint64_t l=(cpu->eax & 0xFFu), r=(cpu->eax & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CE77;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->edx;
    label_0003CE77:
    if ((uint8_t)((*(uint8_t*)(cpu->edx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_0003CE8A;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) | (uint64_t)(4u))) & 0xFFu);
    *(uint8_t*)(cpu->esp + 0x10u) = cpu->ecx & 0xFFu;
    cpu->ebp += 3u;
    goto label_0003CF98;
    label_0003CE8A:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFBu))) & 0xFFu);
    *(uint8_t*)(cpu->esp + 0x10u) = cpu->ecx & 0xFFu;
    cpu->ebp += 3u;
    goto label_0003CF98;
    label_0003CE99:
    { uint64_t l=cpu->eax, r=1u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CEE7;
    cpu->eax = cpu->ebp;
    cpu->eax = (int32_t)(cpu->eax) >> 3u;
    cpu->edx = cpu->eax * 8u;
    { uint64_t l=cpu->ecx, r=cpu->edx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esi = cpu->eax + cpu->edi;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (((uint8_t)((cpu->edx & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u)));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ecx = cpu->esp + 0x10u;
    cpu->edi = 7u;
    label_0003CEC0:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003CEC8;
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) | (uint64_t)((cpu->eax & 0xFFu));
    goto label_0003CECE;
    label_0003CEC8:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->eax & 0xFFu) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_0003CECE:
    { uint64_t l=(cpu->eax & 0xFFu), r=(cpu->eax & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CED5;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->ecx;
    label_0003CED5:
    { uint64_t l=(cpu->edx & 0xFFu), r=(cpu->edx & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CEDC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->esi;
    label_0003CEDC:
    { uint64_t l=cpu->edi, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CEC0;
    cpu->ebp += 7u;
    goto label_0003CF92;
    label_0003CEE7:
    { uint64_t l=cpu->eax, r=2u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = cpu->ebp;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CF50;
    cpu->eax = (int32_t)(cpu->eax) >> 3u;
    cpu->edx = cpu->eax * 8u;
    { uint64_t l=cpu->ecx, r=cpu->edx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esi = cpu->eax + cpu->edi;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (((uint8_t)((cpu->edx & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u)));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ecx = cpu->esp + 0x10u;
    cpu->edi = 7u;
    label_0003CF10:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003CF18;
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) | (uint64_t)((cpu->eax & 0xFFu));
    goto label_0003CF1E;
    label_0003CF18:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->eax & 0xFFu) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_0003CF1E:
    { uint64_t l=(cpu->eax & 0xFFu), r=(cpu->eax & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CF25;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->ecx;
    label_0003CF25:
    { uint64_t l=(cpu->edx & 0xFFu), r=(cpu->edx & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CF2C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->esi;
    label_0003CF2C:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003CF34;
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) | (uint64_t)((cpu->eax & 0xFFu));
    goto label_0003CF3A;
    label_0003CF34:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->eax & 0xFFu) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_0003CF3A:
    { uint64_t l=(cpu->eax & 0xFFu), r=(cpu->eax & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CF41;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->ecx;
    label_0003CF41:
    { uint64_t l=(cpu->edx & 0xFFu), r=(cpu->edx & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CF48;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->esi;
    label_0003CF48:
    { uint64_t l=cpu->edi, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CF10;
    cpu->ebp += 0xEu;
    goto label_0003CF92;
    label_0003CF50:
    cpu->eax = (int32_t)(cpu->eax) >> 3u;
    cpu->edx = cpu->eax * 8u;
    { uint64_t l=cpu->ecx, r=cpu->edx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esi = cpu->eax + cpu->edi;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (((uint8_t)((cpu->edx & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u)));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ecx = cpu->esp + 0x10u;
    cpu->edi = 0x1Fu;
    label_0003CF70:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003CF78;
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) | (uint64_t)((cpu->eax & 0xFFu));
    goto label_0003CF7E;
    label_0003CF78:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->eax & 0xFFu) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_0003CF7E:
    { uint64_t l=(cpu->eax & 0xFFu), r=(cpu->eax & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CF85;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->ecx;
    label_0003CF85:
    { uint64_t l=(cpu->edx & 0xFFu), r=(cpu->edx & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CF8C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->esi;
    label_0003CF8C:
    { uint64_t l=cpu->edi, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CF70;
    cpu->ebp += 0x1Fu;
    label_0003CF92:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebx = 0u;
    label_0003CF98:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    if (*(uint32_t*)(cpu->esp + 0x2Cu) == cpu->ebx) goto label_0003D26E;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    goto label_0003D26E;
    label_0003CFB5:
    { uint64_t l=cpu->eax, r=0x65u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D028;
    cpu->edx = cpu->ebp;
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->eax = cpu->edx * 8u;
    cpu->ecx = cpu->ebp;
    { uint64_t l=cpu->ecx, r=cpu->eax, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (((uint8_t)((cpu->eax & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u)));
    cpu->edx += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    { uint64_t l=*(uint8_t*)(cpu->edx), r=(cpu->eax & 0xFFu), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t l=(cpu->eax & 0xFFu), r=(cpu->eax & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CFE0;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->edx;
    label_0003CFE0:
    if ((uint8_t)((*(uint8_t*)(cpu->edx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_0003CFE9;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) | (uint64_t)(2u))) & 0xFFu);
    goto label_0003CFEC;
    label_0003CFE9:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFDu))) & 0xFFu);
    label_0003CFEC:
    { uint64_t l=(cpu->eax & 0xFFu), r=(cpu->eax & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CFF3;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->edx;
    label_0003CFF3:
    if ((uint8_t)((*(uint8_t*)(cpu->edx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_0003CFFC;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) | (uint64_t)(4u))) & 0xFFu);
    goto label_0003CFFF;
    label_0003CFFC:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFBu))) & 0xFFu);
    label_0003CFFF:
    { uint64_t l=(cpu->eax & 0xFFu), r=(cpu->eax & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D006;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->edx;
    label_0003D006:
    if ((uint8_t)((*(uint8_t*)(cpu->edx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_0003D019;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) | (uint64_t)(8u))) & 0xFFu);
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->ecx & 0xFFu;
    cpu->ebp += 4u;
    goto label_0003D0D3;
    label_0003D019:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xF7u))) & 0xFFu);
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->ecx & 0xFFu;
    cpu->ebp += 4u;
    goto label_0003D0D3;
    label_0003D028:
    { uint64_t l=cpu->eax, r=0x66u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D179;
    cpu->eax = cpu->ebp;
    cpu->eax = (int32_t)(cpu->eax) >> 3u;
    cpu->edx = cpu->eax * 8u;
    cpu->ecx = cpu->ebp;
    { uint64_t l=cpu->ecx, r=cpu->edx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esi = cpu->eax + cpu->edi;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (((uint8_t)((cpu->edx & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u)));
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->eax = cpu->esp + 0x18u;
    cpu->edi = 2u;
    label_0003D057:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003D05F;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_0003D065;
    label_0003D05F:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_0003D065:
    { uint64_t l=(cpu->ecx & 0xFFu), r=(cpu->ecx & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D06C;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->eax;
    label_0003D06C:
    { uint64_t l=(cpu->edx & 0xFFu), r=(cpu->edx & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D073;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->esi;
    label_0003D073:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003D07B;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_0003D081;
    label_0003D07B:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_0003D081:
    { uint64_t l=(cpu->ecx & 0xFFu), r=(cpu->ecx & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D088;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->eax;
    label_0003D088:
    { uint64_t l=(cpu->edx & 0xFFu), r=(cpu->edx & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D08F;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->esi;
    label_0003D08F:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003D097;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_0003D09D;
    label_0003D097:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_0003D09D:
    { uint64_t l=(cpu->ecx & 0xFFu), r=(cpu->ecx & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D0A4;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->eax;
    label_0003D0A4:
    { uint64_t l=(cpu->edx & 0xFFu), r=(cpu->edx & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D0AB;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->esi;
    label_0003D0AB:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003D0B3;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_0003D0B9;
    label_0003D0B3:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_0003D0B9:
    { uint64_t l=(cpu->ecx & 0xFFu), r=(cpu->ecx & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D0C0;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->eax;
    label_0003D0C0:
    { uint64_t l=(cpu->edx & 0xFFu), r=(cpu->edx & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D0C7;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->esi;
    label_0003D0C7:
    { uint64_t l=cpu->edi, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D057;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebp += 8u;
    cpu->ebx = 0u;
    label_0003D0D3:
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=2u, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); g_sfera_mbc_runtime->argument_count = (uint32_t)((v)); }
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_0003D37C;
    cpu->ecx = g_sfera_mbc_runtime->argument_cursor;
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    cpu->esi = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id;
    cpu->esi += *(uint32_t*)(cpu->edx + 0x50u);
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type;
    ++cpu->ecx;
    g_sfera_mbc_runtime->argument_cursor = cpu->ecx;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D112u)); sfera_sub_00433BB0(cpu, LIFT_CODE_TOKEN_VA(0x43D112u));
    { uint64_t l=cpu->eax, r=cpu->ebx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003D125;
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43D11Du));
    { uint64_t l=cpu->esp, r=0xCu, v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    label_0003D125:
    cpu->esi = g_sfera_mbc_runtime->argument_cursor;
    cpu->esi <<= 5u;
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->esi >> 5u].type;
    if ((((cpu->eax & 0xFFu)) & (0xFu)) == 0u) goto label_0003D36B;
    cpu->ecx = cpu->eax + 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D144u)); sfera_sub_00433BB0(cpu, LIFT_CODE_TOKEN_VA(0x43D144u));
    cpu->esi = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->esi >> 5u].payload[0];
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    cpu->esi += *(uint32_t*)(cpu->ecx + 0x50u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    cpu->eax = 1u;
    g_sfera_mbc_runtime->argument_cursor += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    if (*(uint32_t*)(cpu->esp + 0x18u) != cpu->ebx) goto label_0003D304;
    *(uint32_t*)(cpu->esp + 0x1Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x1Cu)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    goto label_0003D304;
    label_0003D179:
    if (cpu->eax != 0x69u) goto label_0003D185;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    goto label_0003D19B;
    label_0003D185:
    if (cpu->eax != 0x6Au) goto label_0003D191;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    goto label_0003D19B;
    label_0003D191:
    if (cpu->eax != 0x6Bu) goto label_0003D1B3;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    label_0003D19B:
    cpu->edx = cpu->esp + 0x18u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D1A6u)); sfera_sub_00437CB0(cpu, LIFT_CODE_TOKEN_VA(0x43D1A6u));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    goto label_0003D26E;
    label_0003D1B3:
    { uint64_t l=cpu->eax, r=0x6Cu, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D26E;
    cpu->eax = cpu->ebp;
    cpu->eax = (int32_t)(cpu->eax) >> 3u;
    cpu->edx = cpu->eax * 8u;
    cpu->ecx = cpu->ebp;
    { uint64_t l=cpu->ecx, r=cpu->edx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->esi = cpu->eax + cpu->edi;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (((uint8_t)((cpu->edx & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u)));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->eax = cpu->esp + 0x10u;
    cpu->edi = 2u;
    label_0003D1E2:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003D1EA;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_0003D1F0;
    label_0003D1EA:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_0003D1F0:
    { uint64_t l=(cpu->ecx & 0xFFu), r=(cpu->ecx & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D1F7;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->eax;
    label_0003D1F7:
    { uint64_t l=(cpu->edx & 0xFFu), r=(cpu->edx & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D1FE;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->esi;
    label_0003D1FE:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003D206;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_0003D20C;
    label_0003D206:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_0003D20C:
    { uint64_t l=(cpu->ecx & 0xFFu), r=(cpu->ecx & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D213;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->eax;
    label_0003D213:
    { uint64_t l=(cpu->edx & 0xFFu), r=(cpu->edx & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D21A;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->esi;
    label_0003D21A:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003D222;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_0003D228;
    label_0003D222:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_0003D228:
    { uint64_t l=(cpu->ecx & 0xFFu), r=(cpu->ecx & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D22F;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->eax;
    label_0003D22F:
    { uint64_t l=(cpu->edx & 0xFFu), r=(cpu->edx & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D236;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->esi;
    label_0003D236:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003D23E;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_0003D244;
    label_0003D23E:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((cpu->ecx & 0xFFu) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_0003D244:
    { uint64_t l=(cpu->ecx & 0xFFu), r=(cpu->ecx & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D24B;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->eax;
    label_0003D24B:
    { uint64_t l=(cpu->edx & 0xFFu), r=(cpu->edx & 0xFFu), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D252;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->esi;
    label_0003D252:
    { uint64_t l=cpu->edi, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D1E2;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebp += 8u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.02454369328916073);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0003D26E:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    { uint64_t v=cpu->ebx; lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D2D8;
    { uint64_t l=g_sfera_mbc_runtime->argument_count, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; g_sfera_mbc_runtime->argument_count = (uint32_t)((v)); }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_0003D37C;
    cpu->edx = g_sfera_mbc_runtime->argument_cursor;
    cpu->esi = g_sfera_mbc_runtime->active_process;
    cpu->eax = cpu->edx;
    cpu->eax <<= 5u;
    cpu->ecx = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id;
    cpu->ecx += *(uint32_t*)(cpu->esi + 0x50u);
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type;
    ++cpu->edx;
    g_sfera_mbc_runtime->argument_cursor = cpu->edx;
    if (cpu->eax != 0u) goto label_0003D2B2;
    cpu->eax = cpu->ebx + 1u;
    goto label_0003D2C3;
    label_0003D2B2:
    { uint64_t l=(cpu->eax & 0xFFu), r=0xFu, v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = (cpu->eax * 8u) + 4u;
    label_0003D2C3:
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43D2CEu));
    cpu->esp += 0xCu;
    goto label_0003D304;
    label_0003D2D8:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x24u);
    --cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    if ((int32_t)cpu->esi <= 0) goto label_0003D2F8;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43D2F0u));
    cpu->esp += 0xCu;
    label_0003D2F8:
    *(uint32_t*)(cpu->esp + 0x28u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x28u)) + (uint64_t)(cpu->esi) + (uint64_t)(0u);
    if ((int32_t)cpu->ebx <= 0) goto label_0003D304;
    --*(uint32_t*)(cpu->esp + 0x1Cu);
    label_0003D304:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x3Cu);
    ++cpu->edx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    if ((int32_t)cpu->edx < (int32_t)*(uint32_t*)(cpu->eax + 0x1Cu)) goto label_0003CD68;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x44u);
    label_0003D322:
    if (((*(uint8_t*)(cpu->eax + 0x20u)) & (1u)) != 0u) goto label_0003D338;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->edx = g_sfera_mbc_runtime->active_process;
    *(uint32_t*)(cpu->edx + (cpu->ecx * 4u) + 0xDCu) = cpu->eax;
    label_0003D338:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D340u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x43D340u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, 0x1DE0u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D352u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x43D352u));
    lift_push32(cpu, 0x1DE1u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D363u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x43D363u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003D36B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = (uintptr_t)"Wrong data for 'receive' function";
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003D37C:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = (uintptr_t)"Wrong number of parameters for 'receive' function";
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003D38D:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = (uintptr_t)"Wrong region for 'receive' function";
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    sfera_sub_004385D0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_0043D3A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->ecx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003D3B8;
    cpu->ecx = (uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003D3B8:
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    cpu->edx = 1u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = 0u;
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = cpu->edx;
    g_sfera_mbc_runtime->value_stack_size = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043D400(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D406u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43D406u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D40Du)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43D40Du));
    cpu->esi -= cpu->eax;
    cpu->ecx = cpu->esi;
    cpu->eax = cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    cpu->esi = lift_pop32(cpu);
    if ((int32_t)cpu->eax <= (int32_t)0x3840u) goto label_0003D432;
    if ((int32_t)cpu->ecx >= 0) goto label_0003D42C;
    cpu->ecx += 0x8000u;
    goto label_0003D432;
    label_0003D42C:
    cpu->ecx -= 0x8000u;
    label_0003D432:
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->edx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003D44A;
    cpu->ecx = (uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003D44A:
    cpu->eax = cpu->edx;
    cpu->eax <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = cpu->ecx;
    cpu->ecx = 1u;
    cpu->edx += cpu->ecx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = cpu->ecx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = cpu->ecx;
    g_sfera_mbc_runtime->value_stack_size = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043D490(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D495u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43D495u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003D4B4;
    if ((int32_t)cpu->eax >= 0) goto label_0003D4AD;
    cpu->ecx = g_sfera_mbc_static_runtime.profile_fallback;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003D4AD:
    cpu->ecx = 0u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003D4B4:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043D4C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D4C7u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43D4C7u));
    cpu->esi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D4CEu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43D4CEu));
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=2u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = *(uint32_t*)(cpu->eax);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003D4E0;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D4DEu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43D4DEu));
    goto label_0003D4E2;
    label_0003D4E0:
    cpu->eax = 0u;
    label_0003D4E2:
    lift_push32(cpu, cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = cpu->eax + cpu->edi;
    cpu->ecx = cpu->eax + cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D4F3u)); sfera_sub_00433470(cpu, LIFT_CODE_TOKEN_VA(0x43D4F3u));
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    { uint64_t l=cpu->edx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003D50D;
    cpu->ecx = (uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003D50D:
    cpu->ecx = cpu->edx;
    cpu->ecx <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].payload[0] = cpu->eax;
    cpu->eax = 1u;
    cpu->edx += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_end = cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_begin = cpu->eax;
    g_sfera_mbc_runtime->value_stack_size = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043D550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x94u);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->edx &= 4u;
    { uint64_t l=cpu->ecx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003D576;
    cpu->ecx = (uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003D576:
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = cpu->edx;
    cpu->edx = 1u;
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = cpu->edx;
    g_sfera_mbc_runtime->value_stack_size = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043D5B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D5B7u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43D5B7u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D5BEu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43D5BEu));
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if ((int32_t)cpu->eax < (int32_t)0xFFFFFFFCu) goto label_0003D5CC;
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_0003D5DC;
    label_0003D5CC:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ecx == 0u) goto label_0003D649;
    if (cpu->eax < cpu->ecx) goto label_0003D5DC;
    if (cpu->eax <= *(uint32_t*)(cpu->esi + 8u)) goto label_0003D649;
    label_0003D5DC:
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D5E6u)); sfera_sub_00434AF0(cpu, LIFT_CODE_TOKEN_VA(0x43D5E6u));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D606u)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x43D606u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->esp += 0x18u;
    if (cpu->eax == 0u) goto label_0003D69E;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ecx == 0u) goto label_0003D69E;
    { uint64_t l=cpu->eax, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0003D629;
    if (cpu->eax <= *(uint32_t*)(cpu->esi + 8u)) goto label_0003D69E;
    { uint64_t l=cpu->eax, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_0003D629:
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0003D637;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    ++g_sfera_mbc_runtime->value_stack_size;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003D637:
    --cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)*(uint32_t*)(cpu->esi + 8u)) goto label_0003D69E;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    ++g_sfera_mbc_runtime->value_stack_size;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003D649:
    cpu->eax = 0u;
    if (g_sfera_mbc_runtime->argument_count != 3u) goto label_0003D659;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3D659u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_RVA(0x3D659u));
    label_0003D659:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003D6A4;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx += cpu->eax;
    cpu->ecx += cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D675u)); sfera_sub_00433FF0(cpu, LIFT_CODE_TOKEN_VA(0x43D675u));
    cpu->ecx = *(uint32_t*)(cpu->edi);
    if ((int32_t)cpu->ecx < (int32_t)0xFFFFFFFCu) goto label_0003D681;
    if ((int32_t)cpu->ecx < (int32_t)4u) goto label_0003D695;
    label_0003D681:
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    if (cpu->edx == 0u) goto label_0003D69E;
    if (cpu->ecx < cpu->edx) goto label_0003D695;
    cpu->ecx = cpu->ecx + cpu->eax + 0xFFFFFFFFu;
    if (cpu->ecx <= *(uint32_t*)(cpu->edi + 8u)) goto label_0003D69E;
    label_0003D695:
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3D69Eu)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_RVA(0x3D69Eu));
    label_0003D69E:
    ++g_sfera_mbc_runtime->value_stack_size;
    label_0003D6A4:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043D6B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D6B8u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43D6B8u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D6BFu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43D6BFu));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D6C6u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43D6C6u));
    cpu->ebx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if ((int32_t)cpu->eax < (int32_t)0xFFFFFFFCu) goto label_0003D6D4;
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_0003D6E4;
    label_0003D6D4:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ecx == 0u) goto label_0003D757;
    if (cpu->eax < cpu->ecx) goto label_0003D6E4;
    if (cpu->eax <= *(uint32_t*)(cpu->esi + 8u)) goto label_0003D757;
    label_0003D6E4:
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D6EEu)); sfera_sub_00434AF0(cpu, LIFT_CODE_TOKEN_VA(0x43D6EEu));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D70Eu)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x43D70Eu));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->esp += 0x18u;
    if (cpu->eax == 0u) goto label_0003D7B4;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ecx == 0u) goto label_0003D7B4;
    { uint64_t l=cpu->eax, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0003D735;
    if (cpu->eax <= *(uint32_t*)(cpu->esi + 8u)) goto label_0003D7B4;
    { uint64_t l=cpu->eax, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_0003D735:
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0003D744;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    ++g_sfera_mbc_runtime->value_stack_size;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003D744:
    --cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)*(uint32_t*)(cpu->esi + 8u)) goto label_0003D7B4;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    ++g_sfera_mbc_runtime->value_stack_size;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003D757:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003D7BA;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->esi = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->ebx);
    cpu->eax += cpu->ecx;
    cpu->esi += cpu->ecx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x43D76Fu));
    cpu->eax = cpu->esi;
    cpu->esp += 0xCu;
    *(uint8_t*)(cpu->esi + cpu->ebx) = 0u;
    cpu->edx = cpu->eax + 1u;
    label_0003D781:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0003D781;
    cpu->eax -= cpu->edx;
    cpu->edx = cpu->eax + 1u;
    cpu->eax = *(uint32_t*)(cpu->edi);
    if ((int32_t)cpu->eax < (int32_t)0xFFFFFFFCu) goto label_0003D799;
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_0003D7AD;
    label_0003D799:
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    if (cpu->ecx == 0u) goto label_0003D7B4;
    if (cpu->eax < cpu->ecx) goto label_0003D7AD;
    cpu->eax = cpu->eax + cpu->edx + 0xFFFFFFFFu;
    if (cpu->eax <= *(uint32_t*)(cpu->edi + 8u)) goto label_0003D7B4;
    label_0003D7AD:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3D7B4u)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_RVA(0x3D7B4u));
    label_0003D7B4:
    ++g_sfera_mbc_runtime->value_stack_size;
    label_0003D7BA:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043D7C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D7C8u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43D7C8u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D7CFu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43D7CFu));
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi);
    if ((int32_t)cpu->eax < (int32_t)0xFFFFFFFCu) goto label_0003D7DD;
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_0003D7ED;
    label_0003D7DD:
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    if (cpu->ecx == 0u) goto label_0003D854;
    if (cpu->eax < cpu->ecx) goto label_0003D7ED;
    if (cpu->eax <= *(uint32_t*)(cpu->edi + 8u)) goto label_0003D854;
    label_0003D7ED:
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D7F7u)); sfera_sub_00434AF0(cpu, LIFT_CODE_TOKEN_VA(0x43D7F7u));
    cpu->eax = *(uint32_t*)(cpu->edi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = *(uint32_t*)(cpu->edi);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D817u)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x43D817u));
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->esp += 0x18u;
    if (cpu->eax == 0u) goto label_0003D84A;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    if (cpu->ecx == 0u) goto label_0003D84A;
    { uint64_t l=cpu->eax, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0003D832;
    if (cpu->eax <= *(uint32_t*)(cpu->edi + 8u)) goto label_0003D84A;
    { uint64_t l=cpu->eax, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_0003D832:
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0003D841;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    ++g_sfera_mbc_runtime->value_stack_size;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003D841:
    --cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)*(uint32_t*)(cpu->edi + 8u)) goto label_0003D84A;
    *(uint32_t*)(cpu->edi + 8u) = cpu->eax;
    label_0003D84A:
    ++g_sfera_mbc_runtime->value_stack_size;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003D854:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if ((int32_t)cpu->ecx < (int32_t)0xFFFFFFFCu) goto label_0003D860;
    if ((int32_t)cpu->ecx < (int32_t)4u) goto label_0003D870;
    label_0003D860:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax == 0u) goto label_0003D8C7;
    if (cpu->ecx < cpu->eax) goto label_0003D870;
    if (cpu->ecx <= *(uint32_t*)(cpu->esi + 8u)) goto label_0003D8C7;
    label_0003D870:
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D87Au)); sfera_sub_00434AF0(cpu, LIFT_CODE_TOKEN_VA(0x43D87Au));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D89Au)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x43D89Au));
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->esp += 0x18u;
    if (cpu->ecx == 0u) goto label_0003D8C7;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax == 0u) goto label_0003D8C7;
    { uint64_t l=cpu->ecx, r=cpu->eax, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0003D8B5;
    if (cpu->ecx <= *(uint32_t*)(cpu->esi + 8u)) goto label_0003D8C7;
    { uint64_t l=cpu->ecx, r=cpu->eax, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_0003D8B5:
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0003D8BC;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    goto label_0003D8C7;
    label_0003D8BC:
    cpu->eax = cpu->ecx + 0xFFFFFFFFu;
    if ((int32_t)cpu->eax <= (int32_t)*(uint32_t*)(cpu->esi + 8u)) goto label_0003D8C7;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    label_0003D8C7:
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx + cpu->eax;
    cpu->edi += cpu->eax;
    cpu->eax = cpu->ebp;
    cpu->ebx = cpu->eax + 1u;
    label_0003D8E0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0003D8E0;
    cpu->eax -= cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = cpu->edi;
    cpu->ebx = cpu->eax + 1u;
    label_0003D8F2:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0003D8F2;
    cpu->eax -= cpu->ebx;
    cpu->ebx = cpu->eax;
    if ((int32_t)cpu->ecx < (int32_t)0xFFFFFFFCu) goto label_0003D907;
    if ((int32_t)cpu->ecx < (int32_t)4u) goto label_0003D923;
    label_0003D907:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax == 0u) goto label_0003D932;
    if (cpu->ecx < cpu->eax) goto label_0003D923;
    cpu->eax = cpu->ecx + cpu->ebx + 1u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->eax + cpu->ecx + 0xFFFFFFFFu;
    if (cpu->edx <= *(uint32_t*)(cpu->esi + 8u)) goto label_0003D932;
    label_0003D923:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->ebx + cpu->eax + 1u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3D932u)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_RVA(0x3D932u));
    label_0003D932:
    if ((int32_t)g_sfera_mbc_runtime->argument_count <= (int32_t)2u) goto label_0003D96A;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D940u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43D940u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->ebx + cpu->ecx + 1u;
    if ((int32_t)cpu->edx <= (int32_t)cpu->eax) goto label_0003D96A;
    lift_push32(cpu, (uintptr_t)"Size mismatch: ffstrcat\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D95Bu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x43D95Bu));
    cpu->esp += 8u;
    ++g_sfera_mbc_runtime->value_stack_size;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003D96A:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003D9A6;
    ++g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = cpu->edi;
    cpu->ecx = cpu->edi;
    label_0003D980:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0003D980;
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    cpu->edi = cpu->ebp + 0xFFFFFFFFu;
    label_0003D990:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    { uint64_t v= cpu->ecx & 0xFFu; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D990;
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 2u;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    label_0003D9A6:
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043D9B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D9B9u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43D9B9u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D9C0u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43D9C0u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003DA00;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->eax += cpu->edx;
    cpu->ecx += cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_strstr_address32(), LIFT_CODE_TOKEN_VA(0x43D9D9u));
    cpu->esp += 8u;
    cpu->edx = 1u;
    if (cpu->eax != 0u) goto label_0003DA05;
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3DA00u)); sfera_sub_0043AF30(cpu, LIFT_CODE_TOKEN_RVA(0x3DA00u));
    label_0003DA00:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003DA05:
    cpu->eax -= g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    sfera_sub_0043AF30(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_0043DA20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DA29u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43DA29u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DA30u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43DA30u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003DA69;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx += cpu->eax;
    cpu->ecx += cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DA4Bu)); sfera_sub_004ED620(cpu, LIFT_CODE_TOKEN_VA(0x43DA4Bu));
    cpu->edx = 1u;
    if (cpu->eax != 0u) goto label_0003DA6E;
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3DA69u)); sfera_sub_0043AF30(cpu, LIFT_CODE_TOKEN_RVA(0x3DA69u));
    label_0003DA69:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003DA6E:
    cpu->eax -= g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    sfera_sub_0043AF30(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_0043DA90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DA98u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43DA98u));
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi += cpu->eax;
    if (cpu->edi != cpu->eax) goto label_0003DAB7;
    lift_push32(cpu, (uintptr_t)"ffstrlen(): NULL-pointer dereferencing\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DAB4u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x43DAB4u));
    cpu->esp += 8u;
    label_0003DAB7:
    cpu->ebx = 1u;
    if ((int32_t)g_sfera_mbc_runtime->argument_count <= (int32_t)cpu->ebx) goto label_0003DAF5;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DAC9u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43DAC9u));
    cpu->esi = 0u;
    if ((int32_t)cpu->eax <= 0) goto label_0003DADC;
    (void)cpu;
    label_0003DAD0:
    if (*(uint8_t*)(cpu->esi + cpu->edi) == 0u) goto label_0003DADC;
    cpu->esi += cpu->ebx;
    if ((int32_t)cpu->esi < (int32_t)cpu->eax) goto label_0003DAD0;
    label_0003DADC:
    if (cpu->esi != cpu->eax) goto label_0003DB0B;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"ffstrlen(): end of string was not found in buffer of size %d\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DAF0u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x43DAF0u));
    cpu->esp += 0xCu;
    goto label_0003DB0B;
    label_0003DAF5:
    cpu->eax = cpu->edi;
    cpu->edx = cpu->eax + 1u;
    label_0003DB00:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0003DB00;
    cpu->eax -= cpu->edx;
    cpu->esi = cpu->eax;
    label_0003DB0B:
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->ecx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003DB7B;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DB1Eu)); sfera_sub_00434D90(cpu, LIFT_CODE_TOKEN_VA(0x43DB1Eu));
    cpu->ecx = (uintptr_t)"\n---exit_inter start---\nMBINTER MESSAGE:";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DB28u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x43DB28u));
    cpu->ecx = (uintptr_t)"Stack overflow";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DB32u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x43DB32u));
    cpu->ecx = (uintptr_t)"\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DB3Cu)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x43DB3Cu));
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DB46u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x43DB46u));
    cpu->ecx = (uintptr_t)"---exit_inter end-----\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DB50u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x43DB50u));
    { uint64_t l=g_sfera_mbc_runtime->process_index, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    g_sfera_mbc_runtime->execution_failed = cpu->ebx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003DB69;
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3DB69u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x3DB69u));
    label_0003DB69:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->edx = (uintptr_t)"EError";
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->processes[0];
    cpu->ebx = lift_pop32(cpu);
    sfera_sub_00435020(cpu, stop_address); return;
    label_0003DB7B:
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = cpu->esi;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx += cpu->ebx;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = cpu->ebx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = cpu->ebx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_runtime->value_stack_size = cpu->ecx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043DBC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DBC6u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43DBC6u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DBCDu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43DBCDu));
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = cpu->edx + cpu->eax;
    cpu->eax = cpu->edx + cpu->esi;
    cpu->esi = lift_pop32(cpu);
    label_0003DBE0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    { uint64_t l=(cpu->edx & 0xFFu), r=*(uint8_t*)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003DC00;
    if ((cpu->edx & 0xFFu) == 0u) goto label_0003DBFC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    { uint64_t l=(cpu->edx & 0xFFu), r=*(uint8_t*)(cpu->ecx + 1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003DC00;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0003DBE0;
    label_0003DBFC:
    cpu->ecx = 0u;
    goto label_0003DC05;
    label_0003DC00:
    { uint64_t l=cpu->ecx, r=cpu->ecx, c=((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = (uint64_t)(cpu->ecx) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_0003DC05:
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->edx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003DC1D;
    cpu->ecx = (uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003DC1D:
    cpu->eax = cpu->edx;
    cpu->eax <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = cpu->ecx;
    cpu->ecx = 1u;
    cpu->edx += cpu->ecx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = cpu->ecx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = cpu->ecx;
    g_sfera_mbc_runtime->value_stack_size = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043DC60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DC66u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43DC66u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DC6Du)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43DC6Du));
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax += cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx += cpu->esi;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x43DC79u));
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    cpu->esp += 8u;
    cpu->esi = lift_pop32(cpu);
    { uint64_t l=cpu->edx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003DC9B;
    cpu->ecx = (uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003DC9B:
    cpu->ecx = cpu->edx;
    cpu->ecx <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].payload[0] = cpu->eax;
    cpu->eax = 1u;
    cpu->edx += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_end = cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_begin = cpu->eax;
    g_sfera_mbc_runtime->value_stack_size = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043DCE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DCE7u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43DCE7u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DCEEu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43DCEEu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DCF5u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43DCF5u));
    lift_push32(cpu, cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = cpu->eax + cpu->edi;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->esi;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strncmp), LIFT_CODE_TOKEN_VA(0x43DD02u));
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    { uint64_t l=cpu->edx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003DD25;
    cpu->ecx = (uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003DD25:
    cpu->ecx = cpu->edx;
    cpu->ecx <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].payload[0] = cpu->eax;
    cpu->eax = 1u;
    cpu->edx += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_end = cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_begin = cpu->eax;
    g_sfera_mbc_runtime->value_stack_size = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043DD60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DD67u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43DD67u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DD6Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43DD6Eu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DD75u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43DD75u));
    lift_push32(cpu, cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = cpu->eax + cpu->edi;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->esi;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_strnicmp), LIFT_CODE_TOKEN_VA(0x43DD82u));
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    { uint64_t l=cpu->edx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003DDA5;
    cpu->ecx = (uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003DDA5:
    cpu->ecx = cpu->edx;
    cpu->ecx <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].payload[0] = cpu->eax;
    cpu->eax = 1u;
    cpu->edx += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_end = cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_begin = cpu->eax;
    g_sfera_mbc_runtime->value_stack_size = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043DDE0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_0003DDE0;
    label_000341F0:
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034207;
    cpu->eax = (uintptr_t)"at";
    label_00034207:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\script.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x43420Du));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_0003423D;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->esi);
    g_sfera_log_first_write = 0u;
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x43422Du));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x434234u));
    cpu->esp += 0x10u;
    label_0003423D:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000342F0:
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034307;
    cpu->eax = (uintptr_t)"at";
    label_00034307:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\deletings.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x43430Du));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_00034333;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x434323u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x43432Au));
    cpu->esp += 0x10u;
    label_00034333:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000343E0:
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000343F7;
    cpu->eax = (uintptr_t)"at";
    label_000343F7:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\gm.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4343FDu));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_00034423;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x434413u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x43441Au));
    cpu->esp += 0x10u;
    label_00034423:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000344D0:
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000344E7;
    cpu->eax = (uintptr_t)"at";
    label_000344E7:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\trade.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4344EDu));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_00034513;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x434503u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x43450Au));
    cpu->esp += 0x10u;
    label_00034513:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00034570:
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034587;
    cpu->eax = (uintptr_t)"at";
    label_00034587:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\violations.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x43458Du));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_000345AE;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x43459Eu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4345A5u));
    cpu->esp += 0xCu;
    label_000345AE:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000345C0:
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000345D7;
    cpu->eax = (uintptr_t)"at";
    label_000345D7:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\violations.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4345DDu));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_00034603;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x4345F3u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4345FAu));
    cpu->esp += 0x10u;
    label_00034603:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000346A0:
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->eax = (uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000346B7;
    cpu->eax = (uintptr_t)"at";
    label_000346B7:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4346B9u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_000346DF;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x4346CFu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4346D6u));
    cpu->esp += 0x10u;
    label_000346DF:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003DDE0:
    lift_push32(cpu, cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax <<= 5u;
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type;
    lift_push32(cpu, cpu->esi);
    if ((((cpu->eax & 0xFFu)) & (0xFu)) == 0u) goto label_0003DF48;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DDFDu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43DDFDu));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003E0EC;
    if (g_sfera_mbc_runtime->argument_count != 2u) goto label_0003DF36;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DE1Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43DE1Eu));
    if (cpu->eax != 1u) goto label_0003DE34;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_004342A0(cpu, stop_address); return;
    label_0003DE34:
    if (cpu->eax != 2u) goto label_0003DE4B;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = cpu->ecx + cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434390(cpu, stop_address); return;
    label_0003DE4B:
    if (cpu->eax != 3u) goto label_0003DE62;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = cpu->ecx + cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434480(cpu, stop_address); return;
    label_0003DE62:
    if (cpu->eax != 9u) goto label_0003DE7E;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = cpu->edx + cpu->esi;
    cpu->ecx = (uintptr_t)"logs\\goldtaler";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434660(cpu, stop_address); return;
    label_0003DE7E:
    if (cpu->eax != 0xAu) goto label_0003DE99;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx += cpu->esi;
    cpu->ecx = (uintptr_t)"logs\\mstatin";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434660(cpu, stop_address); return;
    label_0003DE99:
    if (cpu->eax != 0xBu) goto label_0003DEB5;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = cpu->edx + cpu->esi;
    cpu->ecx = (uintptr_t)"logs\\mstatout";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434660(cpu, stop_address); return;
    label_0003DEB5:
    if (cpu->eax != 0xCu) goto label_0003DED1;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = cpu->edx + cpu->esi;
    cpu->ecx = (uintptr_t)"logs\\gtstatin";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434660(cpu, stop_address); return;
    label_0003DED1:
    if (cpu->eax != 0xDu) goto label_0003DEEC;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx += cpu->esi;
    cpu->ecx = (uintptr_t)"logs\\gtstatout";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434660(cpu, stop_address); return;
    label_0003DEEC:
    if (cpu->eax != 0xEu) goto label_0003DF08;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = cpu->edx + cpu->esi;
    cpu->ecx = (uintptr_t)"logs\\bigmoney";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434660(cpu, stop_address); return;
    label_0003DF08:
    if (cpu->eax != 0xFu) goto label_0003DF24;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = cpu->edx + cpu->esi;
    cpu->ecx = (uintptr_t)"logs\\chat";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434660(cpu, stop_address); return;
    label_0003DF24:
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = cpu->ecx + cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_00034570;
    label_0003DF36:
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = cpu->ecx + cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_004341A0(cpu, stop_address); return;
    label_0003DF48:
    if (cpu->eax == 0x20u) goto label_0003E026;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DF56u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43DF56u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003E0EC;
    if (g_sfera_mbc_runtime->argument_count != 2u) goto label_0003E01B;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43DF77u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43DF77u));
    if (cpu->eax != 1u) goto label_0003DF87;
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000342F0;
    label_0003DF87:
    if (cpu->eax != 2u) goto label_0003DF97;
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000343E0;
    label_0003DF97:
    if (cpu->eax != 3u) goto label_0003DFA7;
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000344D0;
    label_0003DFA7:
    if (cpu->eax != 9u) goto label_0003DFBC;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)"logs\\goldtaler";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000346A0;
    label_0003DFBC:
    if (cpu->eax != 0xAu) goto label_0003DFD1;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)"logs\\mstatin";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000346A0;
    label_0003DFD1:
    if (cpu->eax != 0xBu) goto label_0003DFE6;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)"logs\\mstatout";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000346A0;
    label_0003DFE6:
    if (cpu->eax != 0xEu) goto label_0003DFFB;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)"logs\\bigmoney";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000346A0;
    label_0003DFFB:
    if (cpu->eax != 0xFu) goto label_0003E010;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)"logs\\chat";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000346A0;
    label_0003E010:
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000345C0;
    label_0003E01B:
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000341F0;
    label_0003E026:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E02Bu)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43E02Bu));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003E0EC;
    if (g_sfera_mbc_runtime->argument_count != 2u) goto label_0003E0DF;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E04Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43E04Eu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (cpu->eax != 1u) goto label_0003E063;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E060u)); sfera_sub_00434340(cpu, LIFT_CODE_TOKEN_VA(0x43E060u));
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E063:
    if (cpu->eax != 2u) goto label_0003E070;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E06Du)); sfera_sub_00434430(cpu, LIFT_CODE_TOKEN_VA(0x43E06Du));
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E070:
    if (cpu->eax != 3u) goto label_0003E07D;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E07Au)); sfera_sub_00434520(cpu, LIFT_CODE_TOKEN_VA(0x43E07Au));
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E07D:
    if (cpu->eax != 9u) goto label_0003E08F;
    cpu->ecx = (uintptr_t)"logs\\goldtaler";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E08Cu)); sfera_sub_004346F0(cpu, LIFT_CODE_TOKEN_VA(0x43E08Cu));
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E08F:
    if (cpu->eax != 0xAu) goto label_0003E0A1;
    cpu->ecx = (uintptr_t)"logs\\mstatin";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E09Eu)); sfera_sub_004346F0(cpu, LIFT_CODE_TOKEN_VA(0x43E09Eu));
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E0A1:
    if (cpu->eax != 0xBu) goto label_0003E0B3;
    cpu->ecx = (uintptr_t)"logs\\mstatout";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E0B0u)); sfera_sub_004346F0(cpu, LIFT_CODE_TOKEN_VA(0x43E0B0u));
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E0B3:
    if (cpu->eax != 0xEu) goto label_0003E0C5;
    cpu->ecx = (uintptr_t)"logs\\bigmoney";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E0C2u)); sfera_sub_004346F0(cpu, LIFT_CODE_TOKEN_VA(0x43E0C2u));
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E0C5:
    if (cpu->eax != 0xFu) goto label_0003E0D7;
    cpu->ecx = (uintptr_t)"logs\\chat";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E0D4u)); sfera_sub_004346F0(cpu, LIFT_CODE_TOKEN_VA(0x43E0D4u));
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E0D7:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E0DCu)); sfera_sub_00434610(cpu, LIFT_CODE_TOKEN_VA(0x43E0DCu));
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E0DF:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3E0ECu)); sfera_sub_00434240(cpu, LIFT_CODE_TOKEN_RVA(0x3E0ECu));
    label_0003E0EC:
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043E0F0(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003E20A;
    lift_push32(cpu, cpu->esi);
    label_0003E101:
    cpu->esi = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax = cpu->esi;
    cpu->eax <<= 5u;
    cpu->ecx = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type;
    if ((((cpu->ecx & 0xFFu)) & (0xFu)) == 0u) goto label_0003E1D7;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_mbc_runtime->argument_end) goto label_0003E197;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E128u)); sfera_sub_00434D90(cpu, LIFT_CODE_TOKEN_VA(0x43E128u));
    cpu->ecx = (uintptr_t)"\n---exit_inter start---\nMBINTER MESSAGE:";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E132u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x43E132u));
    cpu->ecx = (uintptr_t)"Too few parameters";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E13Cu)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x43E13Cu));
    cpu->ecx = (uintptr_t)"\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E146u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x43E146u));
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E150u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x43E150u));
    cpu->ecx = (uintptr_t)"---exit_inter end-----\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E15Au)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x43E15Au));
    { uint64_t l=g_sfera_mbc_runtime->process_index, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    g_sfera_mbc_runtime->execution_failed = 1u;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003E177;
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3E177u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x3E177u));
    label_0003E177:
    cpu->edx = (uintptr_t)"EError";
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->processes[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E186u)); sfera_sub_00435020(cpu, LIFT_CODE_TOKEN_VA(0x43E186u));
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = 0u;
    cpu->ecx += cpu->eax;
    *(uint32_t*)(cpu->edi) = cpu->ecx;
    cpu->edi += 4u;
    goto label_0003E1F6;
    label_0003E197:
    if ((cpu->ecx & 0xFFu) == 0x10u) goto label_0003E1BB;
    if ((cpu->ecx & 0xFFu) != 0x20u) goto label_0003E1AE;
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0]));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E1ACu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x43E1ACu));
    goto label_0003E1C1;
    label_0003E1AE:
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0003E1BB;
    cpu->eax = (int8_t)(((uint8_t)g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0]));
    goto label_0003E1C1;
    label_0003E1BB:
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0];
    label_0003E1C1:
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    ++cpu->esi;
    cpu->ecx += cpu->eax;
    g_sfera_mbc_runtime->argument_cursor = cpu->esi;
    *(uint32_t*)(cpu->edi) = cpu->ecx;
    cpu->edi += 4u;
    goto label_0003E1F6;
    label_0003E1D7:
    if (cpu->ecx == 0x10u) goto label_0003E1E0;
    if (cpu->ecx != 0u) goto label_0003E1EC;
    label_0003E1E0:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E1E5u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43E1E5u));
    *(uint32_t*)(cpu->edi) = cpu->eax;
    cpu->edi += 4u;
    goto label_0003E1F6;
    label_0003E1EC:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E1F1u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43E1F1u));
    *(double*)(cpu->edi) = cpu->fpu[0u];
    lift_x87_pop(cpu);
    cpu->edi += 8u;
    label_0003E1F6:
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    --cpu->eax;
    g_sfera_mbc_runtime->argument_count = cpu->eax;
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0003E101;
    cpu->esi = lift_pop32(cpu);
    label_0003E20A:
    ++g_sfera_mbc_runtime->value_stack_size;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043E220(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 1u;
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=cpu->edi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003E267;
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax <<= 5u;
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type;
    if (cpu->eax == 0x10u) goto label_0003E257;
    if (cpu->eax != 0u) goto label_0003E267;
    label_0003E257:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E25Cu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43E25Cu));
    g_sfera_mbc_runtime->argument_count -= cpu->edi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    goto label_0003E26E;
    label_0003E267:
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = 0u;
    label_0003E26E:
    if ((int32_t)g_sfera_mbc_runtime->argument_count >= (int32_t)cpu->edi) goto label_0003E280;
    cpu->ecx = (uintptr_t)"Invalid parameter list: fflogf()";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3E280u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x3E280u));
    label_0003E280:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E285u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43E285u));
    cpu->esi = cpu->eax;
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003E4AA;
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    cpu->eax -= cpu->edi;
    g_sfera_mbc_runtime->argument_count = cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E2B4u)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x43E2B4u));
    cpu->ebx = cpu->esp;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E2BDu)); sfera_sub_0043E0F0(cpu, LIFT_CODE_TOKEN_VA(0x43E2BDu));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_vscprintf), LIFT_CODE_TOKEN_VA(0x43E2BFu));
    cpu->esi = cpu->edi + cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi <= 0x1000u) goto label_0003E2D8;
    cpu->esi = 0x1000u;
    label_0003E2D8:
    cpu->eax = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E2DFu)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x43E2DFu));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->edi = cpu->esp;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_vsnprintf), LIFT_CODE_TOKEN_VA(0x43E2E8u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->esp += 0x10u;
    *(uint8_t*)(cpu->edi + cpu->esi + 0xFFFFFFFFu) = 0u;
    if (cpu->eax > 0x10u) goto label_0003E470;
    switch (cpu->eax) {
        case 0u: goto label_0003E309;
        case 1u: goto label_0003E324;
        case 2u: goto label_0003E33F;
        case 3u: goto label_0003E35A;
        case 4u: case 5u: case 6u: case 7u: case 8u: goto label_0003E470;
        case 9u: goto label_0003E375;
        case 10u: goto label_0003E395;
        case 11u: goto label_0003E3B5;
        case 12u: goto label_0003E3D5;
        case 13u: goto label_0003E3F5;
        case 14u: goto label_0003E415;
        case 15u: goto label_0003E430;
        case 16u: goto label_0003E450;
        default: lift_trap(cpu, 0x43E302u, "resolved jump-table index out of range"); return;
    }
label_0003E309: ;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E310u)); sfera_sub_004341A0(cpu, LIFT_CODE_TOKEN_VA(0x43E310u));
    cpu->esp = cpu->ebp + 0xFFFFFFE8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E324:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E32Bu)); sfera_sub_004342A0(cpu, LIFT_CODE_TOKEN_VA(0x43E32Bu));
    cpu->esp = cpu->ebp + 0xFFFFFFE8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E33F:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E346u)); sfera_sub_00434390(cpu, LIFT_CODE_TOKEN_VA(0x43E346u));
    cpu->esp = cpu->ebp + 0xFFFFFFE8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E35A:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E361u)); sfera_sub_00434480(cpu, LIFT_CODE_TOKEN_VA(0x43E361u));
    cpu->esp = cpu->ebp + 0xFFFFFFE8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E375:
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)"logs\\goldtaler";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E381u)); sfera_sub_00434660(cpu, LIFT_CODE_TOKEN_VA(0x43E381u));
    cpu->esp = cpu->ebp + 0xFFFFFFE8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E395:
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)"logs\\mstatin";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E3A1u)); sfera_sub_00434660(cpu, LIFT_CODE_TOKEN_VA(0x43E3A1u));
    cpu->esp = cpu->ebp + 0xFFFFFFE8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E3B5:
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)"logs\\mstatout";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E3C1u)); sfera_sub_00434660(cpu, LIFT_CODE_TOKEN_VA(0x43E3C1u));
    cpu->esp = cpu->ebp + 0xFFFFFFE8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E3D5:
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)"logs\\gtstatin";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E3E1u)); sfera_sub_00434660(cpu, LIFT_CODE_TOKEN_VA(0x43E3E1u));
    cpu->esp = cpu->ebp + 0xFFFFFFE8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E3F5:
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)"logs\\gtstatout";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E401u)); sfera_sub_00434660(cpu, LIFT_CODE_TOKEN_VA(0x43E401u));
    cpu->esp = cpu->ebp + 0xFFFFFFE8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E415:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E41Cu)); sfera_sub_00434740(cpu, LIFT_CODE_TOKEN_VA(0x43E41Cu));
    cpu->esp = cpu->ebp + 0xFFFFFFE8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E430:
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)"logs\\old_things";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E43Cu)); sfera_sub_00434660(cpu, LIFT_CODE_TOKEN_VA(0x43E43Cu));
    cpu->esp = cpu->ebp + 0xFFFFFFE8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E450:
    cpu->edx = cpu->edi;
    cpu->ecx = (uintptr_t)"logs\\add_exp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E45Cu)); sfera_sub_00434660(cpu, LIFT_CODE_TOKEN_VA(0x43E45Cu));
    cpu->esp = cpu->ebp + 0xFFFFFFE8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E470:
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003E483;
    cpu->eax = (uintptr_t)"at";
    label_0003E483:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\violations.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x43E489u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_0003E4AA;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x43E49Au));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x43E4A1u));
    cpu->esp += 0xCu;
    label_0003E4AA:
    cpu->esp = cpu->ebp + 0xFFFFFFE8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043E510(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp + 0xFFFFFE68u;
    cpu->esp -= 0x218u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 1u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint8_t*)(cpu->ebp + 0xFFFFFF83u) = 0u;
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=cpu->ebx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003E564;
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax <<= 5u;
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type;
    if (cpu->eax == 0x10u) goto label_0003E556;
    if (cpu->eax != 0u) goto label_0003E564;
    label_0003E556:
    *(uint8_t*)(cpu->ebp + 0xFFFFFF83u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E55Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43E55Eu));
    g_sfera_mbc_runtime->argument_count -= cpu->ebx;
    label_0003E564:
    if ((int32_t)g_sfera_mbc_runtime->argument_count >= (int32_t)2u) goto label_0003E577;
    cpu->ecx = (uintptr_t)"Invalid parameter list: ffflogf()";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3E577u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x3E577u));
    label_0003E577:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E57Cu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43E57Cu));
    cpu->esi = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->esi += cpu->eax;
    if (cpu->esi != cpu->eax) goto label_0003E59B;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffflogf, pchFileName\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E598u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x43E598u));
    cpu->esp += 8u;
    label_0003E59B:
    g_sfera_mbc_runtime->argument_count -= cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E5A6u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43E5A6u));
    cpu->edi = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi += cpu->eax;
    if (cpu->edi != cpu->eax) goto label_0003E5C5;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffflogf, pchFormatString\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E5C2u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x43E5C2u));
    cpu->esp += 8u;
    label_0003E5C5:
    g_sfera_mbc_runtime->argument_count -= cpu->ebx;
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003E69E;
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E5E8u)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x43E5E8u));
    cpu->ebx = cpu->esp;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E5F1u)); sfera_sub_0043E0F0(cpu, LIFT_CODE_TOKEN_VA(0x43E5F1u));
    if (*(uint8_t*)(cpu->ebp + 0xFFFFFF83u) == 0u) goto label_0003E603;
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebp + 0xFFFFFF94u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E601u)); sfera_sub_004340E0(cpu, LIFT_CODE_TOKEN_VA(0x43E601u));
    goto label_0003E61A;
    label_0003E603:
    cpu->edx = cpu->ebp + 0xFFFFFF94u;
    cpu->eax = cpu->esi;
    cpu->edx -= cpu->esi;
    label_0003E610:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0003E610;
    label_0003E61A:
    cpu->ecx = cpu->ebp + 0xFFFFFF94u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"logs\\%s");
    cpu->edx = cpu->ebp + 0x94u;
    lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x43E62Fu));
    cpu->eax = cpu->ebp + 0x94u;
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->ebp + 0x193u) = 0u;
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x43E648u));
    cpu->esi = cpu->eax;
    cpu->esp += 0x18u;
    if (cpu->esi == 0u) goto label_0003E69E;
    cpu->ecx = cpu->ebp + 0xFFFFFF84u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::GetLocalTime), LIFT_CODE_TOKEN_VA(0x43E65Bu));
    cpu->edx = *(uint16_t*)(cpu->ebp + 0xFFFFFF90u);
    cpu->eax = *(uint16_t*)(cpu->ebp + 0xFFFFFF8Eu);
    cpu->ecx = *(uint16_t*)(cpu->ebp + 0xFFFFFF8Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint16_t*)(cpu->ebp + 0xFFFFFF84u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint16_t*)(cpu->ebp + 0xFFFFFF86u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint16_t*)(cpu->ebp + 0xFFFFFF8Au);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%02u.%02u.%04u %02u:%02u:%02u "); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x43E685u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::vfprintf), LIFT_CODE_TOKEN_VA(0x43E68Eu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x43E695u));
    cpu->esp += 0x30u;
    label_0003E69E:
    cpu->esp = cpu->ebp + 0xFFFFFF74u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp + 0x198u;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043E6C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax <<= 5u;
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type;
    if ((((cpu->eax & 0xFFu)) & (0xFu)) == 0u) goto label_0003E6D7;
    sfera_sub_0043ACF0(cpu, stop_address); return;
    label_0003E6D7:
    if (cpu->eax == 0x20u) goto label_0003E6E1;
    sfera_sub_0043ACF0(cpu, stop_address); return;
    label_0003E6E1:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E6E6u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43E6E6u));
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043E6F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E6F6u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43E6F6u));
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_0003E70E;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffcreate\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E70Bu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x43E70Bu));
    cpu->esp += 8u;
    label_0003E70E:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003E77C;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax += cpu->esi;
    lift_push32(cpu, 0x180u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_chmod), LIFT_CODE_TOKEN_VA(0x43E724u));
    cpu->esp += 8u;
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=2u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, 0x180u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003E74B;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, 0x8102u);
    cpu->ecx += cpu->esi;
    lift_push32(cpu, cpu->ecx);
    goto label_0003E759;
    label_0003E74B:
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, 0x8302u);
    cpu->edx += cpu->esi;
    lift_push32(cpu, cpu->edx);
    label_0003E759:
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x43E759u));
    cpu->esi = cpu->eax;
    cpu->esp += 0xCu;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E76Bu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x43E76Bu));
    if ((int32_t)cpu->esi < 0) goto label_0003E77C;
    cpu->ecx = cpu->esi;
    cpu->edx = 1u;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_00437A10(cpu, stop_address); return;
    label_0003E77C:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043E780(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0x8002u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E78Cu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43E78Cu));
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_0003E7A4;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffopen\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E7A1u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x43E7A1u));
    cpu->esp += 8u;
    label_0003E7A4:
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax += cpu->esi;
    lift_push32(cpu, 0x180u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_chmod), LIFT_CODE_TOKEN_VA(0x43E7B1u));
    cpu->esp += 8u;
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003E830;
    if ((int32_t)g_sfera_mbc_runtime->argument_count <= (int32_t)1u) goto label_0003E7DB;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E7D1u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43E7D1u));
    if (cpu->eax != 1u) goto label_0003E80B;
    cpu->edi = 0x8000u;
    label_0003E7DB:
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, 0u);
    cpu->edx += cpu->esi;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x43E7E7u));
    cpu->esp += 0xCu;
    label_0003E7F0:
    cpu->esi = cpu->eax;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E7F9u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x43E7F9u));
    if ((int32_t)cpu->esi < 0) goto label_0003E830;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->edx = 1u;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_00437A10(cpu, stop_address); return;
    label_0003E80B:
    if (cpu->eax != 3u) goto label_0003E7DB;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, 0x180u); lift_push32(cpu, 0x40u);
    cpu->ecx += cpu->esi;
    lift_push32(cpu, 0x8002u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_sopen), LIFT_CODE_TOKEN_VA(0x43E825u));
    cpu->esp += 0x10u;
    goto label_0003E7F0;
    label_0003E830:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043E840(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E847u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43E847u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E84Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43E84Eu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E855u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43E855u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003E88D;
    lift_push32(cpu, cpu->eax);
    if (cpu->edi != 0u) goto label_0003E878;
    lift_push32(cpu, 2u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_locking), LIFT_CODE_TOKEN_VA(0x43E866u));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003E878:
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_locking), LIFT_CODE_TOKEN_VA(0x43E87Bu));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003E88D:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043E890(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E896u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43E896u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003E8BD;
    if ((int32_t)cpu->esi < 0) goto label_0003E8BD;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x43E8A6u));
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = 1u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3E8BDu)); sfera_sub_00437B10(cpu, LIFT_CODE_TOKEN_RVA(0x3E8BDu));
    label_0003E8BD:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043E8C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E8C9u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43E8C9u));
    cpu->ebp = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E8D0u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43E8D0u));
    cpu->esi = cpu->eax;
    cpu->edi = *(uint32_t*)(cpu->esi);
    cpu->edi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E8DFu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43E8DFu));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003E939;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if ((int32_t)cpu->eax < (int32_t)0xFFFFFFFCu) goto label_0003E8F6;
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_0003E90A;
    label_0003E8F6:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ecx == 0u) goto label_0003E913;
    if (cpu->eax < cpu->ecx) goto label_0003E90A;
    cpu->eax = cpu->eax + cpu->ebx + 0xFFFFFFFFu;
    if (cpu->eax <= *(uint32_t*)(cpu->esi + 8u)) goto label_0003E913;
    label_0003E90A:
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3E913u)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_RVA(0x3E913u));
    label_0003E913:
    if ((int32_t)cpu->ebp < 0) goto label_0003E92E;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_write), LIFT_CODE_TOKEN_VA(0x43E91Au));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003E92E:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->ebx = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003E939:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043E940(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E946u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43E946u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003E9AA;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E959u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43E959u));
    cpu->esi = cpu->eax;
    cpu->edi = *(uint32_t*)(cpu->esi);
    cpu->edi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E968u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43E968u));
    cpu->ebx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if ((int32_t)cpu->eax < (int32_t)0xFFFFFFFCu) goto label_0003E976;
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_0003E98A;
    label_0003E976:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ecx == 0u) goto label_0003E993;
    if (cpu->eax < cpu->ecx) goto label_0003E98A;
    cpu->eax = cpu->eax + cpu->ebx + 0xFFFFFFFFu;
    if (cpu->eax <= *(uint32_t*)(cpu->esi + 8u)) goto label_0003E993;
    label_0003E98A:
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3E993u)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_RVA(0x3E993u));
    label_0003E993:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x43E996u));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->ebp = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003E9AA:
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043E9B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E9B8u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43E9B8u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003EA58;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E9D1u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43E9D1u));
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_0003E9E9;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffread\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E9E6u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x43E9E6u));
    cpu->esp += 8u;
    label_0003E9E9:
    cpu->ebx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ebx += cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E9F6u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43E9F6u));
    cpu->edi = cpu->eax;
    cpu->esi = 0u;
    *(uint8_t*)(cpu->esp + 0xDu) = 0u;
    if ((int32_t)cpu->edi <= 0) goto label_0003EA4E;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::_read);
    label_0003EA10:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x3EA1Eu), LIFT_CODE_TOKEN_RVA(0x3EA1Cu))) { return; }
    cpu->esp += 0xCu;
    if (cpu->eax != 1u) goto label_0003EA4D;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x10u));
    if ((cpu->eax & 0xFFu) == 0xAu) goto label_0003EA49;
    if ((cpu->eax & 0xFFu) == 0u) goto label_0003EA49;
    *(uint8_t*)(cpu->esi + cpu->ebx) = cpu->eax & 0xFFu;
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)cpu->edi) goto label_0003EA10;
    cpu->ebp = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EA42u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x43EA42u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003EA49:
    *(uint8_t*)(cpu->esi + cpu->ebx) = 0u;
    label_0003EA4D:
    cpu->ebp = lift_pop32(cpu);
    label_0003EA4E:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EA55u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x43EA55u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0003EA58:
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043EA60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EA67u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43EA67u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EA6Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43EA6Eu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EA75u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43EA75u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003EAA7;
    if (cpu->eax != 1u) goto label_0003EA87;
    cpu->eax = 0u;
    goto label_0003EA92;
    label_0003EA87:
    cpu->ecx = 0u;
    { uint64_t l=cpu->eax, r=2u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = cpu->ecx + 1u;
    label_0003EA92:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_lseek), LIFT_CODE_TOKEN_VA(0x43EA95u));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003EAA7:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043EAB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EAB5u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43EAB5u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003EACF;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_filelength), LIFT_CODE_TOKEN_VA(0x43EABFu));
    cpu->esp += 4u;
    cpu->ecx = cpu->eax;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003EACF:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043EAD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x34u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EAE3u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43EAE3u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003EB03;
    cpu->ecx = cpu->esp;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_fstat64i32), LIFT_CODE_TOKEN_VA(0x43EAF1u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esp += 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3EB03u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x3EB03u));
    label_0003EB03:
    cpu->esp += 0x34u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043EB20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EB26u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43EB26u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EB2Du)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43EB2Du));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003EB41;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_chsize), LIFT_CODE_TOKEN_VA(0x43EB38u));
    cpu->esp += 8u;
    label_0003EB41:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043EB50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EB64u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43EB64u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EB6Bu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43EB6Bu));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003EB94;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    cpu->eax = cpu->esp + 4u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::_futime64), LIFT_CODE_TOKEN_VA(0x43EB8Bu));
    cpu->esp += 8u;
    label_0003EB94:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043EBB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EBB5u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43EBB5u));
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003EBD5;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x43EBC5u));
    cpu->esp += 4u;
    cpu->ecx = cpu->eax;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003EBD5:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043EBE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EBE6u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43EBE6u));
    cpu->esi = cpu->eax;
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EBF3u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43EBF3u));
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003EC15;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x43EC04u));
    cpu->esp += 8u;
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003EC15:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043EC20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EC25u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43EC25u));
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003EC46;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EC3Bu)); sfera_sub_00436510(cpu, LIFT_CODE_TOKEN_VA(0x43EC3Bu));
    cpu->ecx = g_sfera_mbc_runtime->file_crc32;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003EC46:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043EC50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EC55u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43EC55u));
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->edx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003EC6D;
    cpu->ecx = (uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003EC6D:
    cpu->ecx = cpu->edx;
    cpu->ecx <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].payload[0] = cpu->eax;
    cpu->eax = 1u;
    cpu->edx += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_end = cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_begin = cpu->eax;
    g_sfera_mbc_runtime->value_stack_size = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043ECB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43ECB5u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43ECB5u));
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43ECBEu)); sfera_sub_0043AED0(cpu, LIFT_CODE_TOKEN_VA(0x43ECBEu));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043ECC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_recovered_static_runtime.mbc_stack_table_cursor;
    cpu->edx = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_mbc_static_runtime.stack_default_values[0]));
    if (cpu->edx == 0u) goto label_0003ECD6;
    ++g_sfera_recovered_static_runtime.mbc_stack_table_cursor;
    label_0003ECD6:
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->ecx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003ECEE;
    cpu->ecx = (uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003ECEE:
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = cpu->edx;
    ++cpu->ecx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = 1u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = 1u;
    g_sfera_mbc_runtime->value_stack_size = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043ED30(LiftCpu* cpu, uint32_t stop_address) {
    SferaMbInterObjectProfile sfera_profile;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43ED3Au)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43ED3Au));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43ED41u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43ED41u));
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=2u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003ED53;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43ED51u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43ED51u));
    cpu->esi = cpu->eax;
    label_0003ED53:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003EDC5;
    sfera_profile = sfera_mbinter_object_profile(cpu->edi);
    cpu->ecx = sfera_profile.factory_kind;
    cpu->eax = 0u;
    { uint64_t l=cpu->esi, r=1u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->edx = cpu->esi + 0xFFFFFFFFu;
    { uint64_t x=cpu->edx, v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->edx = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(cpu->edx) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->edx &= g_sfera_mbc_runtime->active_process;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = cpu->ecx + cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43ED88u)); sfera_sub_00479A30(cpu, LIFT_CODE_TOKEN_VA(0x43ED88u));
    cpu->esi = cpu->eax;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43ED91u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x43ED91u));
    if ((int32_t)cpu->esi >= 0) goto label_0003EDC9;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += cpu->ebx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Error creating object: %s"); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->text_buffer[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x43EDA8u));
    cpu->esp += 0xCu;
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->text_buffer[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EDBBu)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x43EDBBu));
    g_sfera_mbc_runtime->execution_failed = 0u;
    label_0003EDC5:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003EDC9:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EDD0u)); sfera_sub_00454F70(cpu, LIFT_CODE_TOKEN_VA(0x43EDD0u));
    g_sfera_inter_scalar_runtime.mode_03 = cpu->eax;
    if (*(uint8_t*)(cpu->eax + 0x138u) != 1u) goto label_0003EE33;
    cpu->edx = g_sfera_inter_scalar_runtime.mode_03;
    *(uint8_t*)(cpu->edx + 0x274u) = sfera_profile.property_274;
    *(uint8_t*)(cpu->edx + 0x275u) = sfera_profile.property_275;
    *(uint8_t*)(cpu->edx + 0x276u) = sfera_profile.property_276;
    *(uint8_t*)(cpu->edx + 0x277u) = sfera_profile.property_277;
    label_0003EE33:
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->edx = 0u;
    cpu->ebx = lift_pop32(cpu);
    sfera_sub_00437A10(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_0043EE40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EE49u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43EE49u));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi < 0) goto label_0003EF47;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EE58u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43EE58u));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EE61u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43EE61u));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EE6Au)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43EE6Au));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EE75u)); sfera_sub_00454F70(cpu, LIFT_CODE_TOKEN_VA(0x43EE75u));
    g_sfera_inter_scalar_runtime.mode_03 = cpu->eax;
    if (cpu->eax != 0u) goto label_0003EE8D;
    g_sfera_mbc_runtime->active_tag = 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003EE8D:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003EF47;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    *(float*)(cpu->eax + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    *(float*)(cpu->eax + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    *(float*)(cpu->ecx + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (cpu->esi != g_sfera_world_objects.controlled_object_handle) goto label_0003EF1B;
    if (g_sfera_graphics_runtime.render_mode_enabled != 1u) goto label_0003EF1B;
    cpu->eax = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 8u));
    *(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xCu));
    *(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x10u));
    g_sfera_main_input_state_runtime.motion_accumulator = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32));
    lift_x87_push(cpu, 333.0);
    cpu->fpu[1u] = (cpu->fpu[1u]) + (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[1u]);
    *(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)(*(float*)(void*)&g_sfera_main_input_state_runtime.motion_accumulator)));
    g_sfera_main_input_state_runtime.motion_accumulator = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0003EF1B:
    if ((int32_t)g_sfera_mbc_runtime->argument_count < (int32_t)5u) goto label_0003EF47;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EF2Bu)); sfera_sub_0045ED20(cpu, LIFT_CODE_TOKEN_VA(0x43EF2Bu));
    if (g_sfera_mbc_runtime->argument_count != 6u) goto label_0003EF47;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EF39u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43EF39u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EF3Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43EF3Eu));
    cpu->edx = g_sfera_inter_scalar_runtime.mode_03;
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->eax;
    label_0003EF47:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043EF50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EF55u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43EF55u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EF5Cu)); sfera_sub_00454E30(cpu, LIFT_CODE_TOKEN_VA(0x43EF5Cu));
    g_sfera_mbc_runtime->resolved_position_pointer = cpu->eax;
    if (cpu->eax != 0u) goto label_0003EF75;
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EF70u)); sfera_sub_0043AED0(cpu, LIFT_CODE_TOKEN_VA(0x43EF70u));
    cpu->eax = g_sfera_mbc_runtime->resolved_position_pointer;
    label_0003EF75:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003EF89;
    lift_x87_push(cpu, (double)*(float*)(cpu->eax));
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3EF89u)); sfera_sub_0043AED0(cpu, LIFT_CODE_TOKEN_RVA(0x3EF89u));
    label_0003EF89:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043EF90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EF95u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43EF95u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EF9Cu)); sfera_sub_00454E30(cpu, LIFT_CODE_TOKEN_VA(0x43EF9Cu));
    g_sfera_mbc_runtime->resolved_position_pointer = cpu->eax;
    if (cpu->eax != 0u) goto label_0003EFB5;
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EFB0u)); sfera_sub_0043AED0(cpu, LIFT_CODE_TOKEN_VA(0x43EFB0u));
    cpu->eax = g_sfera_mbc_runtime->resolved_position_pointer;
    label_0003EFB5:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003EFCA;
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 4u));
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3EFCAu)); sfera_sub_0043AED0(cpu, LIFT_CODE_TOKEN_RVA(0x3EFCAu));
    label_0003EFCA:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043EFD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EFD5u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43EFD5u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EFDCu)); sfera_sub_00454E30(cpu, LIFT_CODE_TOKEN_VA(0x43EFDCu));
    g_sfera_mbc_runtime->resolved_position_pointer = cpu->eax;
    if (cpu->eax != 0u) goto label_0003EFF5;
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EFF0u)); sfera_sub_0043AED0(cpu, LIFT_CODE_TOKEN_VA(0x43EFF0u));
    cpu->eax = g_sfera_mbc_runtime->resolved_position_pointer;
    label_0003EFF5:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003F00A;
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 8u));
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3F00Au)); sfera_sub_0043AED0(cpu, LIFT_CODE_TOKEN_RVA(0x3F00Au));
    label_0003F00A:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F010(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F015u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F015u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F01Cu)); sfera_sub_00454ED0(cpu, LIFT_CODE_TOKEN_VA(0x43F01Cu));
    g_sfera_inter_scalar_runtime.state_04 = cpu->eax;
    if (cpu->eax != 0u) goto label_0003F035;
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F030u)); sfera_sub_0043AED0(cpu, LIFT_CODE_TOKEN_VA(0x43F030u));
    cpu->eax = g_sfera_inter_scalar_runtime.state_04;
    label_0003F035:
    lift_x87_push(cpu, (double)*(float*)(cpu->eax));
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F040u)); sfera_sub_0043AED0(cpu, LIFT_CODE_TOKEN_VA(0x43F040u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F050(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F055u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F055u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F05Cu)); sfera_sub_00454ED0(cpu, LIFT_CODE_TOKEN_VA(0x43F05Cu));
    g_sfera_inter_scalar_runtime.state_04 = cpu->eax;
    if (cpu->eax != 0u) goto label_0003F075;
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F070u)); sfera_sub_0043AED0(cpu, LIFT_CODE_TOKEN_VA(0x43F070u));
    cpu->eax = g_sfera_inter_scalar_runtime.state_04;
    label_0003F075:
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 4u));
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F081u)); sfera_sub_0043AED0(cpu, LIFT_CODE_TOKEN_VA(0x43F081u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F090(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F095u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F095u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F09Cu)); sfera_sub_00454ED0(cpu, LIFT_CODE_TOKEN_VA(0x43F09Cu));
    g_sfera_inter_scalar_runtime.state_04 = cpu->eax;
    if (cpu->eax != 0u) goto label_0003F0B5;
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F0B0u)); sfera_sub_0043AED0(cpu, LIFT_CODE_TOKEN_VA(0x43F0B0u));
    cpu->eax = g_sfera_inter_scalar_runtime.state_04;
    label_0003F0B5:
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 8u));
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F0C1u)); sfera_sub_0043AED0(cpu, LIFT_CODE_TOKEN_VA(0x43F0C1u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F0D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F0D6u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F0D6u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003F0F8;
    if (cpu->esi == 0xFFFFFFFFu) goto label_0003F0ED;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3F0EDu)); sfera_sub_00459150(cpu, LIFT_CODE_TOKEN_RVA(0x3F0EDu));
    label_0003F0ED:
    lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3F0F8u)); sfera_sub_00437B10(cpu, LIFT_CODE_TOKEN_RVA(0x3F0F8u));
    label_0003F0F8:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F100(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F109u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F109u));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi < 0) goto label_0003F172;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F114u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43F114u));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F11Du)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43F11Du));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F126u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43F126u));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F131u)); sfera_sub_00454F70(cpu, LIFT_CODE_TOKEN_VA(0x43F131u));
    g_sfera_inter_scalar_runtime.mode_03 = cpu->eax;
    if (cpu->eax != 0u) goto label_0003F149;
    g_sfera_mbc_runtime->active_tag = 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003F149:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003F172;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    *(float*)(cpu->eax + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    *(float*)(cpu->eax + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    *(float*)(cpu->ecx + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0003F172:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F180(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = 0u;
    cpu->ebp = 0u;
    cpu->edi = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F18Fu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F18Fu));
    cpu->ebx = cpu->eax;
    if ((int32_t)cpu->ebx >= 0) goto label_0003F1A0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->ebx = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003F1A0:
    if (g_sfera_mbc_runtime->argument_count != 5u) goto label_0003F1D5;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F1AEu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F1AEu));
    cpu->edi = cpu->eax;
    cpu->edi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F1BBu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F1BBu));
    cpu->esi = cpu->eax;
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F1C8u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F1C8u));
    cpu->ebp = cpu->eax;
    cpu->ebp += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3F1D5u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_RVA(0x3F1D5u));
    label_0003F1D5:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003F205;
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=1u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = cpu->ebx;
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003F297;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F1F2u)); sfera_sub_00454F70(cpu, LIFT_CODE_TOKEN_VA(0x43F1F2u));
    g_sfera_inter_scalar_runtime.mode_03 = cpu->eax;
    if (cpu->eax != 0u) goto label_0003F20A;
    g_sfera_mbc_runtime->active_tag = 0xFFFFFFFFu;
    label_0003F205:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003F20A:
    lift_push32(cpu, 0x2178u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F21Bu)); sfera_sub_0045CB30(cpu, LIFT_CODE_TOKEN_VA(0x43F21Bu));
    cpu->ebx = cpu->eax;
    if (*(uint8_t*)(cpu->ebx + 0x2A0u) == 0u) goto label_0003F22A;
    cpu->ecx = 0u;
    goto label_0003F22D;
    label_0003F22A:
    cpu->ecx |= 0xFFFFFFFFu;
    label_0003F22D:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F232u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x43F232u));
    *(uint8_t*)(cpu->ebx + 0x2A0u) = 0u;
    if (cpu->edi == 0u) goto label_0003F205;
    if (*(uint8_t*)(cpu->ebx + 0x2A1u) == 0u) goto label_0003F28C;
    *(uint32_t*)(cpu->edi) = 1u;
    if (cpu->esi == 0u) goto label_0003F272;
    if (cpu->esi == g_sfera_mbc_runtime->process_memory_base) goto label_0003F272;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x2A4u));
    *(float*)(cpu->esi) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x2A8u));
    *(float*)(cpu->esi + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x2ACu));
    *(float*)(cpu->esi + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0003F272:
    if (cpu->ebp == 0u) goto label_0003F205;
    if (cpu->ebp == g_sfera_mbc_runtime->process_memory_base) goto label_0003F205;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 0x2B0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(float*)(cpu->ebp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003F28C:
    *(uint32_t*)(cpu->edi) = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003F297:
    cpu->edx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F29Eu)); sfera_sub_004731A0(cpu, LIFT_CODE_TOKEN_VA(0x43F29Eu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_0043F2B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F2B5u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F2B5u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003F2E0;
    if ((int32_t)cpu->eax < 0) goto label_0003F2D8;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F2C9u)); sfera_sub_0045CC30(cpu, LIFT_CODE_TOKEN_VA(0x43F2C9u));
    if (cpu->eax == 0u) goto label_0003F2D8;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xB4u);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003F2D8:
    cpu->ecx |= 0xFFFFFFFFu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003F2E0:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F2F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F2F9u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F2F9u));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi < 0) goto label_0003F3D3;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F308u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43F308u));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F311u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43F311u));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F31Au)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43F31Au));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F325u)); sfera_sub_00454F70(cpu, LIFT_CODE_TOKEN_VA(0x43F325u));
    g_sfera_inter_scalar_runtime.mode_03 = cpu->eax;
    if (cpu->eax != 0u) goto label_0003F33D;
    g_sfera_mbc_runtime->active_tag = 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003F33D:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003F3D3;
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 4u)));
    *(float*)(cpu->eax + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xCu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 8u)));
    *(float*)(cpu->eax + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0xCu)));
    *(float*)(cpu->eax + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (cpu->esi != g_sfera_world_objects.controlled_object_handle) goto label_0003F3D3;
    if (g_sfera_graphics_runtime.render_mode_enabled != 1u) goto label_0003F3D3;
    cpu->eax = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 8u));
    *(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xCu));
    *(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x10u));
    g_sfera_main_input_state_runtime.motion_accumulator = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32));
    lift_x87_push(cpu, 333.0);
    cpu->fpu[1u] = (cpu->fpu[1u]) + (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[1u]);
    *(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)(*(float*)(void*)&g_sfera_main_input_state_runtime.motion_accumulator)));
    g_sfera_main_input_state_runtime.motion_accumulator = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0003F3D3:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F3E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F3E9u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F3E9u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F3F0u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43F3F0u));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F3F9u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43F3F9u));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F402u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43F402u));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003F430;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    cpu->esp -= 0xCu;
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3F430u)); sfera_sub_0046B7D0(cpu, LIFT_CODE_TOKEN_RVA(0x3F430u));
    label_0003F430:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F440(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F447u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F447u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F44Eu)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43F44Eu));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003F476;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    cpu->esp -= 0xCu;
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u];
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3F476u)); sfera_sub_0046B7D0(cpu, LIFT_CODE_TOKEN_RVA(0x3F476u));
    label_0003F476:
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F489u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F489u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F490u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43F490u));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F499u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43F499u));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F4A2u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43F4A2u));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003F4D0;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    cpu->esp -= 0xCu;
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3F4D0u)); sfera_sub_004634E0(cpu, LIFT_CODE_TOKEN_RVA(0x3F4D0u));
    label_0003F4D0:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F4E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F4E6u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F4E6u));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi < 0) goto label_0003F51F;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F4F1u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F4F1u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003F51F;
    lift_push32(cpu, cpu->ebx);
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    lift_push32(cpu, 0x21FAu);
    cpu->ecx = cpu->esi;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F50Cu)); sfera_sub_00454F70(cpu, LIFT_CODE_TOKEN_VA(0x43F50Cu));
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F518u)); sfera_sub_0045CB30(cpu, LIFT_CODE_TOKEN_VA(0x43F518u));
    *(uint8_t*)(cpu->eax + 0x141u) = cpu->ebx & 0xFFu;
    cpu->ebx = lift_pop32(cpu);
    label_0003F51F:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F530(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->eax <<= 5u;
    { uint64_t l=(uint64_t)(g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type), r=1u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003F5A4;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F54Bu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F54Bu));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F554u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F554u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F55Bu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F55Bu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F562u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F562u));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F569u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43F569u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F56Eu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x43F56Eu));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003F59E;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F582u)); sfera_sub_00455820(cpu, LIFT_CODE_TOKEN_VA(0x43F582u));
    if (cpu->eax == 0u) goto label_0003F5D8;
    *(uint32_t*)(cpu->eax + 0x6DA8u) = cpu->esi;
    *(uint32_t*)(cpu->eax + 0x6DACu) = cpu->edi;
    *(uint32_t*)(cpu->eax + 0x6DB0u) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 0x6DB4u) = cpu->ebp;
    label_0003F59E:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003F5A4:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F5A9u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F5A9u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F5B0u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F5B0u));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F5B7u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F5B7u));
    cpu->ebp = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F5BEu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F5BEu));
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=8u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003F61A;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F5D2u)); sfera_sub_00455820(cpu, LIFT_CODE_TOKEN_VA(0x43F5D2u));
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_0003F5E9;
    label_0003F5D8:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = (uintptr_t)"Wrong parameters for 'text' function";
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003F5E9:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F5EEu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F5EEu));
    *(uint32_t*)(cpu->esi + 0x6DA8u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F5F9u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F5F9u));
    *(uint32_t*)(cpu->esi + 0x6DACu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F604u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F604u));
    *(uint32_t*)(cpu->esi + 0x6DB0u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F60Fu)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x43F60Fu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F614u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x43F614u));
    *(uint32_t*)(cpu->esi + 0x6DB4u) = cpu->eax;
    label_0003F61A:
    if (g_sfera_mbc_runtime->argument_count != 9u) goto label_0003F628;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3F628u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_RVA(0x3F628u));
    label_0003F628:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003F59E;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax += cpu->edi;
    cpu->edx = (uintptr_t)&g_sfera_mbc_runtime->text_buffer[0];
    cpu->edx -= cpu->eax;
    label_0003F643:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0003F643;
    if (g_sfera_mbc_runtime->text_buffer[0] != (cpu->ecx & 0xFFu)) goto label_0003F661;
    cpu->edx = 0x3Fu;
    *(uint16_t*)((uintptr_t)&g_sfera_mbc_runtime->text_buffer[0]) = cpu->edx & 0xFFFFu;
    label_0003F661:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->text_buffer[0]);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F672u)); sfera_sub_00463020(cpu, LIFT_CODE_TOKEN_VA(0x43F672u));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_0003F687;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003F687:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F68Eu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x43F68Eu));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->edx = 4u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00437A10(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_0043F6B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F6B6u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F6B6u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003F6DA;
    if ((int32_t)cpu->esi < 0) goto label_0003F6CC;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3F6CCu)); sfera_sub_00457370(cpu, LIFT_CODE_TOKEN_RVA(0x3F6CCu));
    label_0003F6CC:
    lift_push32(cpu, 0u);
    cpu->edx = 4u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3F6DAu)); sfera_sub_00437B10(cpu, LIFT_CODE_TOKEN_RVA(0x3F6DAu));
    label_0003F6DA:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F6E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F6E7u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F6E7u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F6EEu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F6EEu));
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=3u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003F714;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F6FEu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F6FEu));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003F711;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3F711u)); sfera_sub_0045AC40(cpu, LIFT_CODE_TOKEN_RVA(0x3F711u));
    label_0003F711:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003F714:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003F711;
    cpu->edx = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)cpu->esi >= 0) goto label_0005ABE4;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5ABE4u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5ABE4u));
    label_0005ABE4:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_0005ABF8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5ABF8u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5ABF8u));
    label_0005ABF8:
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 4u)) != 0u) goto label_0005AC0D;
    cpu->ecx = (uintptr_t)"text_color: wrong handle";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AC0Du)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x5AC0Du));
    label_0005AC0D:
    if ((int32_t)cpu->esi >= 0) goto label_0005AC1B;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AC1Bu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x5AC1Bu));
    label_0005AC1B:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_interface_runtime.window_handle_table.capacity) goto label_0005AC2F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x5AC2Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x5AC2Fu));
    label_0005AC2F:
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    *(uint32_t*)(cpu->edx + 0x28u) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0xFFu;
    cpu->esi = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F742u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F742u));
    cpu->ebx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F74Du)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F74Du));
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=2u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003F770;
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F763u)); sfera_sub_0045EB60(cpu, LIFT_CODE_TOKEN_VA(0x43F763u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003F770:
    lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F776u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F776u));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F77Du)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F77Du));
    cpu->ebp = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F784u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F784u));
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F78Du)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F78Du));
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=6u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003F7A1;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F79Fu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F79Fu));
    cpu->edi = cpu->eax;
    label_0003F7A1:
    if ((int32_t)g_sfera_mbc_runtime->argument_count <= (int32_t)7u) goto label_0003F7B1;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F7AFu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F7AFu));
    cpu->esi = cpu->eax;
    label_0003F7B1:
    if ((int32_t)g_sfera_mbc_runtime->argument_count <= (int32_t)8u) goto label_0003F7BF;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3F7BFu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_RVA(0x3F7BFu));
    label_0003F7BF:
    if ((int32_t)g_sfera_mbc_runtime->argument_count <= (int32_t)9u) goto label_0003F7D2;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F7CDu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F7CDu));
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3F7D2u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_RVA(0x3F7D2u));
    label_0003F7D2:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003F831;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F800u)); sfera_sub_00467E70(cpu, LIFT_CODE_TOKEN_VA(0x43F800u));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_0003F817;
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->ecx = (uintptr_t)"Error creating sprite";
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003F817:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F81Eu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x43F81Eu));
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->edx = 5u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    sfera_sub_00437A10(cpu, stop_address); return;
    label_0003F831:
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F840(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F846u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F846u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003F86A;
    if ((int32_t)cpu->esi < 0) goto label_0003F85C;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3F85Cu)); sfera_sub_00455C20(cpu, LIFT_CODE_TOKEN_RVA(0x3F85Cu));
    label_0003F85C:
    lift_push32(cpu, 0u);
    cpu->edx = 5u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3F86Au)); sfera_sub_00437B10(cpu, LIFT_CODE_TOKEN_RVA(0x3F86Au));
    label_0003F86A:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F870(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F87Au)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F87Au));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F881u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F881u));
    cpu->edi = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax <<= 5u;
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type;
    cpu->ebp = 0u;
    if (cpu->eax != 0x11u) goto label_0003F89D;
    cpu->ebp = cpu->eax + 0xFFFFFFF0u;
    goto label_0003F8AF;
    label_0003F89D:
    if (cpu->eax != 0x21u) goto label_0003F8A7;
    cpu->ebp = cpu->eax + 0xFFFFFFE1u;
    goto label_0003F8AF;
    label_0003F8A7:
    if (cpu->eax != 1u) goto label_0003F8AF;
    cpu->ebp = cpu->eax + 2u;
    label_0003F8AF:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F8B4u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F8B4u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003F9CF;
    if (g_sfera_mbc_runtime->argument_count != 3u) goto label_0003F908;
    if (cpu->ebp == 1u) goto label_0003F8DF;
    if (cpu->ebp == 2u) goto label_0003F8DF;
    if (cpu->ebp != 3u) goto label_0003F9C1;
    label_0003F8DF:
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = cpu->eax + cpu->ebx;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax + cpu->edi;
    lift_push32(cpu, cpu->edx);
    cpu->eax += cpu->esi;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x43F8EFu));
    cpu->esp += 0xCu;
    cpu->esi = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003F908:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F90Du)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F90Du));
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=4u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003F945;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = cpu->eax + cpu->ebp;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax + cpu->ebx;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax + cpu->edi;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->esi;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x43F92Cu));
    cpu->esp += 0x10u;
    cpu->esi = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003F945:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F94Au)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F94Au));
    cpu->ecx = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->eax != 5u) goto label_0003F98B;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = cpu->eax + cpu->ecx;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax + cpu->ebp;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax + cpu->ebx;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax + cpu->edi;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->esi;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x43F972u));
    cpu->esp += 0x14u;
    cpu->esi = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003F98B:
    if (cpu->eax != 6u) goto label_0003F9C1;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43F995u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43F995u));
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = cpu->ecx + cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->ecx + cpu->eax;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ecx + cpu->ebp;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ecx + cpu->ebx;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ecx + cpu->edi;
    lift_push32(cpu, cpu->eax);
    cpu->ecx += cpu->esi;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x43F9B6u));
    cpu->esp += 0x18u;
    cpu->esi = cpu->eax;
    label_0003F9C1:
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003F9CF:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F9E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=2u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0003FA04;
    cpu->ecx = (uintptr_t)"Wrong number of parameters: ffsprintf";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3FA04u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x3FA04u));
    label_0003FA04:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FA09u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43FA09u));
    cpu->edi = cpu->eax;
    cpu->edi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FA16u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43FA16u));
    cpu->ebx = cpu->eax;
    cpu->ebx += g_sfera_mbc_runtime->process_memory_base;
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003FA54;
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    cpu->eax -= 2u;
    g_sfera_mbc_runtime->argument_count = cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FA3Fu)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x43FA3Fu));
    cpu->esi = cpu->esp;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FA48u)); sfera_sub_0043E0F0(cpu, LIFT_CODE_TOKEN_VA(0x43FA48u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::vsprintf), LIFT_CODE_TOKEN_VA(0x43FA4Bu));
    cpu->esp += 0xCu;
    label_0003FA54:
    cpu->esp = cpu->ebp + 0xFFFFFFF0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043FA70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->execution_context_depth;
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003FA84;
    cpu->eax <<= 5u;
    cpu->edx = g_sfera_mbc_runtime->execution_context_stack[g_sfera_mbc_runtime->execution_context_depth - 1u].process_id;
    goto label_0003FA87;
    label_0003FA84:
    cpu->edx |= 0xFFFFFFFFu;
    label_0003FA87:
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->ecx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003FA9F;
    cpu->ecx = (uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003FA9F:
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = cpu->edx;
    cpu->edx = 1u;
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = cpu->edx;
    g_sfera_mbc_runtime->value_stack_size = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043FAE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=1u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003FBB8;
    cpu->eax = g_sfera_mbc_runtime->execution_context_depth;
    if ((int32_t)cpu->eax <= 0) goto label_0003FB21;
    cpu->ecx = g_sfera_mbc_runtime->program_index;
    cpu->edx = g_sfera_mbc_runtime->program_table_base;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xA4u);
    { uint64_t l=*(uint8_t*)(cpu->ecx + cpu->edx + 0x84u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0003FB21;
    cpu->eax <<= 5u;
    cpu->esi = g_sfera_mbc_runtime->execution_context_stack[g_sfera_mbc_runtime->execution_context_depth - 1u].process_id;
    goto label_0003FB24;
    label_0003FB21:
    cpu->esi |= 0xFFFFFFFFu;
    label_0003FB24:
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FB2Fu)); sfera_sub_0043AE00(cpu, LIFT_CODE_TOKEN_VA(0x43FB2Fu));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003FC7C;
    if (cpu->esi > 0xFFFFu) goto label_0003FBAB;
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if (*(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id)) != cpu->esi) goto label_0003FBAB;
    if ((int32_t)*(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index)) < (int32_t)0u) goto label_0003FBAB;
    if (cpu->esi == 0xFFFFFFFFu) goto label_0003FBAB;
    cpu->eax = *(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_memory_base));
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax -= cpu->esi;
    { uint64_t v=cpu->ecx; lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003FB86;
    cpu->ecx += cpu->eax;
    { uint64_t v=cpu->edx; lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003FB86;
    cpu->edx += cpu->eax;
    { uint64_t l=cpu->edi, r=cpu->eax, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    label_0003FB86:
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax <<= 5u;
    cpu->eax = *(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.source_id));
    *(uint32_t*)(cpu->eax + cpu->esi) = cpu->ecx;
    *(uint32_t*)(cpu->eax + cpu->esi + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + cpu->esi + 8u) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003FBAB:
    cpu->edi = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003FBB8:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FBBDu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43FBBDu));
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FBC9u)); sfera_sub_0043AE00(cpu, LIFT_CODE_TOKEN_VA(0x43FBC9u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003FC7D;
    if (cpu->esi > 0xFFFFu) goto label_0003FC47;
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if (*(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id)) != cpu->esi) goto label_0003FC47;
    if ((int32_t)*(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index)) < (int32_t)0u) goto label_0003FC47;
    if (cpu->esi == 0xFFFFFFFFu) goto label_0003FC47;
    cpu->eax = *(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_memory_base));
    cpu->eax -= g_sfera_mbc_runtime->process_memory_base;
    if (cpu->ecx == 0u) goto label_0003FC34;
    cpu->ecx += cpu->eax;
    *(uint32_t*)(cpu->esp + 4u) = cpu->ecx;
    if (cpu->edx == 0u) goto label_0003FC34;
    cpu->edx += cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0xCu)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    *(uint32_t*)(cpu->esp + 8u) = cpu->edx;
    label_0003FC34:
    cpu->edx = 1u;
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FC42u)); sfera_sub_0043AF30(cpu, LIFT_CODE_TOKEN_VA(0x43FC42u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003FC47:
    cpu->edx = 1u;
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 4u) = 0u;
    *(uint32_t*)(cpu->esp + 8u) = 0u;
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    g_sfera_mbc_runtime->active_tag = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FC77u)); sfera_sub_0043AF30(cpu, LIFT_CODE_TOKEN_VA(0x43FC77u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003FC7C:
    cpu->edi = lift_pop32(cpu);
    label_0003FC7D:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043FC90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FC98u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43FC98u));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FC9Fu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43FC9Fu));
    cpu->esi = cpu->eax;
    if (*(uint32_t*)(cpu->esi) != 0u) goto label_0003FCBC;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffmempcpy\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FCB5u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x43FCB5u));
    cpu->esp += 8u;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003FCBC:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FCC3u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43FCC3u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FCCAu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43FCCAu));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FCD3u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43FCD3u));
    cpu->ebp = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if ((int32_t)cpu->eax < (int32_t)0xFFFFFFFCu) goto label_0003FCE1;
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_0003FCF5;
    label_0003FCE1:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ecx == 0u) goto label_0003FCFE;
    if (cpu->eax < cpu->ecx) goto label_0003FCF5;
    cpu->eax = cpu->eax + cpu->ebp + 0xFFFFFFFFu;
    if (cpu->eax <= *(uint32_t*)(cpu->esi + 8u)) goto label_0003FCFE;
    label_0003FCF5:
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3FCFEu)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_RVA(0x3FCFEu));
    label_0003FCFE:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003FD9B;
    cpu->ecx |= 0xFFFFFFFFu;
    if (cpu->ebx > 0xFFFFu) goto label_0003FD33;
    cpu->eax = cpu->ebx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if (*(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id)) != cpu->ebx) goto label_0003FD33;
    if ((int32_t)*(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index)) < (int32_t)0u) goto label_0003FD33;
    if (cpu->ebx != cpu->ecx) goto label_0003FD45;
    label_0003FD33:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->active_tag = cpu->ecx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003FD45:
    cpu->eax = *(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_memory_base));
    cpu->eax += *(uint32_t*)(cpu->esi);
    if (cpu->edi > 0xFFFFu) goto label_0003FD72;
    cpu->edx = cpu->edi;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    if (*(uint32_t*)(cpu->edx + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id)) != cpu->edi) goto label_0003FD72;
    if ((int32_t)*(uint32_t*)(cpu->edx + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index)) < (int32_t)0u) goto label_0003FD72;
    if (cpu->edi != cpu->ecx) goto label_0003FD84;
    label_0003FD72:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->active_tag = cpu->ecx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003FD84:
    cpu->ecx = *(uint32_t*)(cpu->edx + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_memory_base));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx += *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43FD93u));
    cpu->esp += 0xCu;
    label_0003FD9B:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043FDB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FDB7u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43FDB7u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FDBEu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43FDBEu));
    cpu->edi = cpu->eax;
    if (*(uint32_t*)(cpu->edi) != 0u) goto label_0003FDDA;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffmempcpy\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FDD4u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x43FDD4u));
    cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003FDDA:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FDE1u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43FDE1u));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FDE8u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43FDE8u));
    cpu->ebp = cpu->eax;
    cpu->eax = 0u;
    if (g_sfera_mbc_runtime->argument_count != 5u) goto label_0003FDFA;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3FDFAu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_RVA(0x3FDFAu));
    label_0003FDFA:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003FEA6;
    cpu->ecx |= 0xFFFFFFFFu;
    if (cpu->esi > 0xFFFFu) goto label_0003FE2F;
    cpu->edx = cpu->esi;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    if (*(uint32_t*)(cpu->edx + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id)) != cpu->esi) goto label_0003FE2F;
    if ((int32_t)*(uint32_t*)(cpu->edx + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index)) < (int32_t)0u) goto label_0003FE2F;
    if (cpu->esi != cpu->ecx) goto label_0003FE3E;
    label_0003FE2F:
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_runtime->active_tag = cpu->ecx;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003FE3E:
    cpu->esi = *(uint32_t*)(cpu->edx + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_memory_base));
    cpu->esi += *(uint32_t*)(cpu->edi);
    if (cpu->ebx > 0xFFFFu) goto label_0003FE6B;
    cpu->edx = cpu->ebx;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    if (*(uint32_t*)(cpu->edx + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id)) != cpu->ebx) goto label_0003FE6B;
    if ((int32_t)*(uint32_t*)(cpu->edx + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index)) < (int32_t)0u) goto label_0003FE6B;
    if (cpu->ebx != cpu->ecx) goto label_0003FE7A;
    label_0003FE6B:
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_runtime->active_tag = cpu->ecx;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003FE7A:
    cpu->edx = *(uint32_t*)(cpu->edx + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_memory_base));
    cpu->edx += *(uint32_t*)(cpu->ebp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FE8Bu)); sfera_sub_00433FF0(cpu, LIFT_CODE_TOKEN_VA(0x43FE8Bu));
    cpu->esi = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FE95u)); sfera_sub_00401C60(cpu, LIFT_CODE_TOKEN_VA(0x43FE95u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_0003FEA6;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->ecx = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    cpu->edx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_00434E80(cpu, stop_address); return;
    label_0003FEA6:
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043FEB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FEB8u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43FEB8u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FEBFu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43FEBFu));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FEC6u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43FEC6u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003FF16;
    if (cpu->edi == 0u) goto label_0003FEFE;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if ((int32_t)cpu->eax < (int32_t)0xFFFFFFFCu) goto label_0003FEE1;
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_0003FEF5;
    label_0003FEE1:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ecx == 0u) goto label_0003FEFE;
    if (cpu->eax < cpu->ecx) goto label_0003FEF5;
    cpu->eax = cpu->eax + cpu->edi + 0xFFFFFFFFu;
    if (cpu->eax <= *(uint32_t*)(cpu->esi + 8u)) goto label_0003FEFE;
    label_0003FEF5:
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3FEFEu)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_RVA(0x3FEFEu));
    label_0003FEFE:
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    cpu->edx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->edi);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43FF0Eu));
    cpu->esp += 0xCu;
    label_0003FF16:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043FF20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FF28u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43FF28u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FF2Fu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43FF2Fu));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FF36u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43FF36u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003FF87;
    if (cpu->edi == 0u) goto label_0003FF6E;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if ((int32_t)cpu->eax < (int32_t)0xFFFFFFFCu) goto label_0003FF51;
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_0003FF65;
    label_0003FF51:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ecx == 0u) goto label_0003FF6E;
    if (cpu->eax < cpu->ecx) goto label_0003FF65;
    cpu->eax = cpu->eax + cpu->edi + 0xFFFFFFFFu;
    if (cpu->eax <= *(uint32_t*)(cpu->esi + 8u)) goto label_0003FF6E;
    label_0003FF65:
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3FF6Eu)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_RVA(0x3FF6Eu));
    label_0003FF6E:
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    cpu->edx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->edi);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x43FF7Eu));
    cpu->esp += 0xCu;
    label_0003FF87:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043FF90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FF98u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x43FF98u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FF9Fu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43FF9Fu));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FFA6u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x43FFA6u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003FFF1;
    if (cpu->edi == 0u) goto label_0003FFDE;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if ((int32_t)cpu->eax < (int32_t)0xFFFFFFFCu) goto label_0003FFC1;
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_0003FFD5;
    label_0003FFC1:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ecx == 0u) goto label_0003FFDE;
    if (cpu->eax < cpu->ecx) goto label_0003FFD5;
    cpu->eax = cpu->eax + cpu->edi + 0xFFFFFFFFu;
    if (cpu->eax <= *(uint32_t*)(cpu->esi + 8u)) goto label_0003FFDE;
    label_0003FFD5:
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3FFDEu)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_RVA(0x3FFDEu));
    label_0003FFDE:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->ecx += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x43FFE9u));
    cpu->esp += 0xCu;
    label_0003FFF1:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00440000(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = 1u;
    if (g_sfera_mbc_runtime->argument_count != cpu->esi) goto label_00040028;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440013u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440013u));
    if (cpu->eax == 0u) goto label_00040028;
    if (cpu->eax == cpu->esi) goto label_00040020;
    if (cpu->eax != 0xFFFFFFFFu) goto label_0004002E;
    label_00040020:
    g_sfera_render_lookup_runtime.initialized = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040028:
    g_sfera_mbc_runtime->halt_all_requested = cpu->esi;
    label_0004002E:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00440030(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->ecx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00040048;
    cpu->ecx = (uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_00040048:
    cpu->edx = g_sfera_network_runtime.initialization_result;
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = cpu->edx;
    cpu->edx = 1u;
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = cpu->edx;
    g_sfera_mbc_runtime->value_stack_size = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00440090(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=2u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_000400BB;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4400A0u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4400A0u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4400A7u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4400A7u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4400AEu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4400AEu));
    if (cpu->eax != 0u) goto label_000400DB;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4400B9u)); sfera_sub_0045CF00(cpu, LIFT_CODE_TOKEN_VA(0x4400B9u));
    goto label_000400E2;
    label_000400BB:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4400C0u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4400C0u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4400C7u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4400C7u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000400E8;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4400D9u)); sfera_sub_0045CF00(cpu, LIFT_CODE_TOKEN_VA(0x4400D9u));
    goto label_000400E2;
    label_000400DB:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x400E2u)); sfera_sub_0045D3C0(cpu, LIFT_CODE_TOKEN_RVA(0x400E2u));
    label_000400E2:
    if (cpu->eax == 0u) goto label_000400E8;
    *(uint32_t*)(cpu->eax) = cpu->edi;
    label_000400E8:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004400F0(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=2u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0004011B;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440100u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440100u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440107u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440107u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44010Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44010Eu));
    if (cpu->eax != 0u) goto label_0004013B;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440119u)); sfera_sub_0045D020(cpu, LIFT_CODE_TOKEN_VA(0x440119u));
    goto label_00040142;
    label_0004011B:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440120u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440120u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440127u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440127u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00040148;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440139u)); sfera_sub_0045D020(cpu, LIFT_CODE_TOKEN_VA(0x440139u));
    goto label_00040142;
    label_0004013B:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x40142u)); sfera_sub_0045D280(cpu, LIFT_CODE_TOKEN_RVA(0x40142u));
    label_00040142:
    if (cpu->eax == 0u) goto label_00040148;
    *(uint32_t*)(cpu->eax) = cpu->edi;
    label_00040148:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00440150(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440156u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440156u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44015Du)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44015Du));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00040177;
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44016Fu)); sfera_sub_0045CD70(cpu, LIFT_CODE_TOKEN_VA(0x44016Fu));
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00040177:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00440180(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440187u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440187u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44018Eu)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x44018Eu));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_000401AC;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4401A2u)); sfera_sub_0045D140(cpu, LIFT_CODE_TOKEN_VA(0x4401A2u));
    if (cpu->eax == 0u) goto label_000401AC;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    *(float*)(cpu->eax) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000401AC:
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004401B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4401B9u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4401B9u));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi < 0) goto label_0004024F;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4401C8u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x4401C8u));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4401D1u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x4401D1u));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4401DCu)); sfera_sub_00454F70(cpu, LIFT_CODE_TOKEN_VA(0x4401DCu));
    g_sfera_inter_scalar_runtime.mode_03 = cpu->eax;
    if (cpu->eax != 0u) goto label_000401F4;
    g_sfera_mbc_runtime->active_tag = 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000401F4:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0004024F;
    lift_push32(cpu, 0x23F5u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44020Eu)); sfera_sub_0045CB30(cpu, LIFT_CODE_TOKEN_VA(0x44020Eu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    cpu->esi = cpu->eax;
    *(float*)(cpu->esi + 0x27Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (g_sfera_mbc_runtime->argument_count != 4u) goto label_00040245;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440228u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x440228u));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    *(float*)(cpu->esi + 0x280u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    *(float*)(cpu->esi + 0x284u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040245:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    *(float*)(cpu->esi + 0x284u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0004024F:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00440260(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440266u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440266u));
    if ((int32_t)cpu->eax < 0) goto label_000402CC;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440271u)); sfera_sub_00454F70(cpu, LIFT_CODE_TOKEN_VA(0x440271u));
    g_sfera_inter_scalar_runtime.mode_03 = cpu->eax;
    if (cpu->eax != 0u) goto label_00040286;
    g_sfera_mbc_runtime->active_tag = 0xFFFFFFFFu;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040286:
    if (g_sfera_mbc_runtime->argument_count != 3u) goto label_0004029D;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440294u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440294u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44029Bu)); sfera_sub_00451990(cpu, LIFT_CODE_TOKEN_VA(0x44029Bu));
    goto label_000402A2;
    label_0004029D:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x402A2u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_RVA(0x402A2u));
    label_000402A2:
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000402CC;
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    lift_push32(cpu, 0x2411u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4402C3u)); sfera_sub_0045CB30(cpu, LIFT_CODE_TOKEN_VA(0x4402C3u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    *(float*)(cpu->eax + 0x28Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000402CC:
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004402D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4402D7u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4402D7u));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi < 0) goto label_00040327;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4402E2u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x4402E2u));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4402EDu)); sfera_sub_00454F70(cpu, LIFT_CODE_TOKEN_VA(0x4402EDu));
    g_sfera_inter_scalar_runtime.mode_03 = cpu->eax;
    if (cpu->eax != 0u) goto label_00040303;
    g_sfera_mbc_runtime->active_tag = 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040303:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00040327;
    lift_push32(cpu, 0x241Cu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44031Du)); sfera_sub_0045CB30(cpu, LIFT_CODE_TOKEN_VA(0x44031Du));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    *(float*)(cpu->eax + 0x294u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00040327:
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00440330(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440335u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440335u));
    if ((int32_t)cpu->eax >= 0) goto label_00040340;
    label_00040339:
    cpu->ecx = 0u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00040340:
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440347u)); sfera_sub_00454F70(cpu, LIFT_CODE_TOKEN_VA(0x440347u));
    g_sfera_inter_scalar_runtime.mode_03 = cpu->eax;
    if (cpu->eax != 0u) goto label_0004035B;
    g_sfera_mbc_runtime->active_tag = 0xFFFFFFFFu;
    label_0004035A:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004035B:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0004035A;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440369u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440369u));
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    if (cpu->eax != 0xFFFFFFFFu) goto label_00040395;
    lift_push32(cpu, 0x2428u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440383u)); sfera_sub_0045CB30(cpu, LIFT_CODE_TOKEN_VA(0x440383u));
    cpu->ecx = 1u;
    if (*(uint32_t*)(cpu->eax + 0x278u) != cpu->ecx) goto label_00040339;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00040395:
    lift_push32(cpu, 0x242Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44039Fu)); sfera_sub_0045CB30(cpu, LIFT_CODE_TOKEN_VA(0x44039Fu));
    *(uint32_t*)(cpu->eax + 0x278u) = 1u;
    cpu->ecx = 0u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_004403B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4403B6u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4403B6u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4403BDu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4403BDu));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00040404;
    if (cpu->esi != 0xFFFFFFFEu) goto label_000403DB;
    if (cpu->eax != cpu->esi) goto label_000403EC;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_flags;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000403DB:
    if (cpu->esi != 0xFFFFFFFFu) goto label_000403EC;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_x;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000403EC:
    cpu->esi = lift_pop32(cpu);
    if (cpu->eax != 0xFFFFFFFFu) goto label_000403FD;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_y;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000403FD:
    cpu->ecx = 0u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00040404:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00440410(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440416u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440416u));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi < 0) goto label_000404D3;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440427u)); sfera_sub_00454F70(cpu, LIFT_CODE_TOKEN_VA(0x440427u));
    g_sfera_inter_scalar_runtime.mode_03 = cpu->eax;
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004043C;
    g_sfera_mbc_runtime->active_tag = 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004043C:
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax <<= 5u;
    if ((uint32_t)(g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type) == 0x21u) goto label_00040469;
    lift_push32(cpu, (uintptr_t)"g_norm: wrong type of parameter (must be float pointer)\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44045Cu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44045Cu));
    cpu->esp += 8u;
    g_sfera_mbc_runtime->execution_failed = 1u;
    label_00040469:
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44046Fu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44046Fu));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000404D2;
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x2459u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440490u)); sfera_sub_0045CB30(cpu, LIFT_CODE_TOKEN_VA(0x440490u));
    cpu->ecx = cpu->esi;
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440499u)); sfera_sub_00463B30(cpu, LIFT_CODE_TOKEN_VA(0x440499u));
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->esi = cpu->eax + cpu->ebx;
    if (cpu->esi != cpu->eax) goto label_000404B7;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffg_norm\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4404B4u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4404B4u));
    cpu->esp += 8u;
    label_000404B7:
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x14Cu));
    *(float*)(cpu->esi) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x150u));
    *(float*)(cpu->esi + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x154u));
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->esi + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000404D2:
    cpu->ebx = lift_pop32(cpu);
    label_000404D3:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004404E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4404E5u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4404E5u));
    if ((int32_t)cpu->eax < 0) goto label_00040570;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4404F4u)); sfera_sub_00454F70(cpu, LIFT_CODE_TOKEN_VA(0x4404F4u));
    g_sfera_inter_scalar_runtime.mode_03 = cpu->eax;
    if (cpu->eax != 0u) goto label_00040508;
    g_sfera_mbc_runtime->active_tag = 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040508:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44050Eu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x44050Eu));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004056F;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if ((int32_t)cpu->eax < (int32_t)0xFFFFFFFCu) goto label_00040525;
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_00040538;
    label_00040525:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ecx == 0u) goto label_00040544;
    if (cpu->eax < cpu->ecx) goto label_00040538;
    cpu->eax += 0xBu;
    if (cpu->eax <= *(uint32_t*)(cpu->esi + 8u)) goto label_00040544;
    label_00040538:
    cpu->edx = 0xCu;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x40544u)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_RVA(0x40544u));
    label_00040544:
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 8u));
    *(float*)(cpu->eax) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0xCu));
    *(float*)(cpu->eax + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x10u));
    *(float*)(cpu->eax + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0004056F:
    cpu->esi = lift_pop32(cpu);
    label_00040570:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00440580(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440585u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440585u));
    if ((int32_t)cpu->eax < 0) goto label_000405F5;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440590u)); sfera_sub_00454F70(cpu, LIFT_CODE_TOKEN_VA(0x440590u));
    g_sfera_inter_scalar_runtime.mode_03 = cpu->eax;
    if (cpu->eax != 0u) goto label_000405A4;
    g_sfera_mbc_runtime->active_tag = 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000405A4:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4405A9u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4405A9u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_000405F5;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx + cpu->eax;
    if (cpu->esi != cpu->ecx) goto label_000405D2;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffg_abg\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4405CFu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4405CFu));
    cpu->esp += 8u;
    label_000405D2:
    cpu->eax = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x14u));
    *(float*)(cpu->esi) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x18u));
    *(float*)(cpu->esi + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0x1Cu));
    *(float*)(cpu->esi + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    label_000405F5:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00440600(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 8u;
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=3u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_00040626;
    cpu->ecx = (uintptr_t)"Wrong number of parameters: ffsnprintf";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x40626u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x40626u));
    label_00040626:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44062Bu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44062Bu));
    cpu->esi = cpu->eax;
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440638u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440638u));
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440640u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440640u));
    cpu->ebx = cpu->eax;
    cpu->ebx += g_sfera_mbc_runtime->process_memory_base;
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00040687;
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    cpu->eax -= 3u;
    g_sfera_mbc_runtime->argument_count = cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440669u)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x440669u));
    cpu->edi = cpu->esp;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440672u)); sfera_sub_0043E0F0(cpu, LIFT_CODE_TOKEN_VA(0x440672u));
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_vsnprintf), LIFT_CODE_TOKEN_VA(0x440679u));
    cpu->esp += 0x10u;
    *(uint8_t*)(cpu->edi + cpu->esi + 0xFFFFFFFFu) = 0u;
    label_00040687:
    cpu->esp = cpu->ebp + 0xFFFFFFECu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004406A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4406B3u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4406B3u));
    if (cpu->eax != 0u) goto label_00040740;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4406C2u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4406C2u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4406C9u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4406C9u));
    cpu->esi = cpu->eax;
    if (cpu->edi == 0u) goto label_000406D3;
    if (cpu->esi != 0u) goto label_000406E5;
    label_000406D3:
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffeditor, EDSC_GETCLICKPOINT\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4406E2u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4406E2u));
    cpu->esp += 8u;
    label_000406E5:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0004073E;
    lift_x87_push(cpu, 0.0);
    cpu->edx = cpu->esp + 0xCu;
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u];
    cpu->ecx = cpu->esp + 8u;
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440709u)); sfera_sub_004731C0(cpu, LIFT_CODE_TOKEN_VA(0x440709u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->edx + cpu->esi) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->edx + cpu->esi + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->edx + cpu->esi + 8u) = cpu->ecx;
    if ((int32_t)cpu->eax < 0) goto label_00040737;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    *(float*)(cpu->edx + cpu->edi) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00040737:
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4073Eu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x4073Eu));
    label_0004073E:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_00040740:
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00440750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x30u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440763u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440763u));
    *(uint32_t*)(cpu->esp) = cpu->eax;
    if (cpu->eax > 0x4Fu) goto label_00041B5F;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    switch (cpu->eax) {
        case 0u: goto label_00040781;
        case 1u: goto label_0004081A;
        case 2u: goto label_0004085A;
        case 3u: goto label_00040878;
        case 4u: goto label_00040896;
        case 5u: goto label_000408DE;
        case 6u: goto label_0004091A;
        case 7u: goto label_00040962;
        case 8u: goto label_00040A8B;
        case 9u: goto label_00040B0A;
        case 10u: goto label_00040B4D;
        case 11u: goto label_00040BE5;
        case 12u: goto label_00040C5B;
        case 13u: goto label_00040CA1;
        case 14u: goto label_00040CE5;
        case 15u: goto label_00040D5D;
        case 16u: goto label_00040DDB;
        case 17u: goto label_00040E17;
        case 18u: goto label_00040E6B;
        case 19u: goto label_00040F45;
        case 20u: goto label_00040FC8;
        case 21u: goto label_00041049;
        case 22u: goto label_0004108E;
        case 23u: goto label_0004124A;
        case 24u: goto label_00041290;
        case 25u: goto label_000412D0;
        case 26u: goto label_0004133D;
        case 27u: goto label_000413AD;
        case 28u: goto label_0004140C;
        case 29u: goto label_0004142B;
        case 30u: goto label_0004146B;
        case 31u: goto label_0004148E;
        case 32u: goto label_000414CD;
        case 33u: goto label_00041503;
        case 34u: goto label_00041590;
        case 35u: goto label_000415F3;
        case 36u: goto label_00041641;
        case 37u: goto label_00041696;
        case 38u: goto label_0004172C;
        case 39u: goto label_00041761;
        case 40u: goto label_000417D8;
        case 41u: goto label_00041818;
        case 42u: goto label_00041952;
        case 43u: goto label_000419C3;
        case 44u: goto label_00041A03;
        case 45u: goto label_00041A4A;
        case 46u: goto label_00041AB9;
        case 47u: goto label_00041B0E;
        case 55u: goto label_00040BC7;
        case 78u: goto label_00041B26;
        case 79u: goto label_00041B4C;
        default: goto label_00041B5B;
    }
label_00040781: ;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440786u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440786u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44078Du)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44078Du));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440794u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440794u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44079Du)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44079Du));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4407A4u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4407A4u));
    cpu->ebp = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4407ABu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4407ABu));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4407CDu)); sfera_sub_004556B0(cpu, LIFT_CODE_TOKEN_VA(0x4407CDu));
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4407D8u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4407D8u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if ((int32_t)cpu->ecx >= 0) goto label_000407FD;
    cpu->ecx = (uintptr_t)"Error creating window";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4407EAu)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x4407EAu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000407FD:
    cpu->edx = 6u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440807u)); sfera_sub_00437A10(cpu, LIFT_CODE_TOKEN_VA(0x440807u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004081A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44081Fu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44081Fu));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440837u)); sfera_sub_00458E80(cpu, LIFT_CODE_TOKEN_VA(0x440837u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, 0u);
    cpu->edx = 6u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440847u)); sfera_sub_00437B10(cpu, LIFT_CODE_TOKEN_VA(0x440847u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004085A:
    cpu->ecx = g_sfera_graphics_runtime.display_width;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440865u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x440865u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040878:
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440883u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x440883u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040896:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44089Bu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44089Bu));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4408A2u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4408A2u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4408A9u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4408A9u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4408C4u)); sfera_sub_0044FA20(cpu, LIFT_CODE_TOKEN_VA(0x4408C4u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4408CBu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4408CBu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000408DE:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4408E3u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4408E3u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4408EAu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4408EAu));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440900u)); sfera_sub_0044F9E0(cpu, LIFT_CODE_TOKEN_VA(0x440900u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440907u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x440907u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004091A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44091Fu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44091Fu));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440926u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440926u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44092Du)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44092Du));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440948u)); sfera_sub_0044FA50(cpu, LIFT_CODE_TOKEN_VA(0x440948u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44094Fu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44094Fu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040962:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440967u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440967u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440970u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440970u));
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_00040988;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, W_EVENT, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440985u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x440985u));
    cpu->esp += 8u;
    label_00040988:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44098Du)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44098Du));
    cpu->edi = cpu->eax;
    if (cpu->edi != 0u) goto label_000409A5;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, W_EVENT, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4409A2u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4409A2u));
    cpu->esp += 8u;
    label_000409A5:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4409BBu)); sfera_sub_00455820(cpu, LIFT_CODE_TOKEN_VA(0x4409BBu));
    if (cpu->eax == 0u) goto label_00040A5E;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x6E08u);
    if ((int32_t)cpu->ecx <= 0) goto label_00040A5E;
    --cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x6E08u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + (cpu->ecx * 4u) + 0x6DB8u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->ecx + cpu->esi) = cpu->edx;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x6E08u);
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->edx * 4u) + 0x6DE0u);
    if (cpu->eax != 0u) goto label_00040A1A;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->eax + cpu->edi) = cpu->ecx;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040A1A:
    if (cpu->eax != 1u) goto label_00040A3C;
    cpu->ecx = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->eax + cpu->edi) = cpu->ecx;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040A3C:
    if (cpu->eax != 2u) goto label_00040A43;
    cpu->ecx = cpu->eax;
    label_00040A43:
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->eax + cpu->edi) = cpu->ecx;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040A5E:
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->ecx + cpu->esi) = 0xFFFFFFFFu;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->edx + cpu->edi) = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040A8B:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440A90u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440A90u));
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_00040AA8;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, W_WINCON, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440AA5u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x440AA5u));
    cpu->esp += 8u;
    label_00040AA8:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440AADu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440AADu));
    cpu->edi = cpu->eax;
    if (cpu->edi != 0u) goto label_00040AC5;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, W_WINCON, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440AC2u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x440AC2u));
    cpu->esp += 8u;
    label_00040AC5:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->edx = cpu->esp + 0x14u;
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440ADFu)); sfera_sub_00467910(cpu, LIFT_CODE_TOKEN_VA(0x440ADFu));
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax + cpu->esi) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->eax + cpu->edi) = cpu->edx;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040B0A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440B0Fu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440B0Fu));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440B18u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440B18u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440B30u)); sfera_sub_00455820(cpu, LIFT_CODE_TOKEN_VA(0x440B30u));
    if (cpu->eax == 0u) goto label_00041B5B;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040B4D:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440B52u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440B52u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440B5Bu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440B5Bu));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440B62u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440B62u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440B69u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440B69u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440B72u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440B72u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440B8Au)); sfera_sub_00455820(cpu, LIFT_CODE_TOKEN_VA(0x440B8Au));
    if (cpu->eax == 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x20u);
    cpu->ecx += cpu->esi;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->edx += *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x24u);
    cpu->ecx += cpu->edi;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x28u);
    cpu->esi = lift_pop32(cpu);
    cpu->edx += cpu->ebx;
    cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->edx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040BC7:
    cpu->ecx = g_sfera_window_runtime.active_window_index;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440BD2u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x440BD2u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040BE5:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440BEAu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440BEAu));
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_00040C02;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, W_TEXTSIZE, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440BFFu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x440BFFu));
    cpu->esp += 8u;
    label_00040C02:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440C07u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440C07u));
    cpu->edi = cpu->eax;
    if (cpu->edi != 0u) goto label_00040C1F;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, W_TEXTSIZE, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440C1Cu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x440C1Cu));
    cpu->esp += 8u;
    label_00040C1F:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = g_sfera_recovered_static_runtime.text_size_height;
    *(uint32_t*)(cpu->eax + cpu->esi) = cpu->ecx;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = g_sfera_input_device_runtime.process_value;
    *(uint32_t*)(cpu->edx + cpu->edi) = cpu->eax;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040C5B:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440C60u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440C60u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440C67u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440C67u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    if ((int32_t)cpu->esi >= 0) goto label_00040C7E;
    cpu->esi += 0x100u;
    label_00040C7E:
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440C87u)); sfera_sub_0044FA00(cpu, LIFT_CODE_TOKEN_VA(0x440C87u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440C8Eu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x440C8Eu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040CA1:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440CA6u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440CA6u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440CAFu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440CAFu));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440CC7u)); sfera_sub_00455820(cpu, LIFT_CODE_TOKEN_VA(0x440CC7u));
    if (cpu->eax == 0u) goto label_00041B5B;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040CE5:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440CEAu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440CEAu));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440CF3u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440CF3u));
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_00040D0B;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, W_GETCURXY, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440D08u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x440D08u));
    cpu->esp += 8u;
    label_00040D0B:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440D10u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440D10u));
    cpu->edi = cpu->eax;
    if (cpu->edi != 0u) goto label_00040D28;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, W_GETCURXY, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440D25u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x440D25u));
    cpu->esp += 8u;
    label_00040D28:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = cpu->eax + cpu->edi;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = cpu->eax + cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440D4Au)); sfera_sub_00468D30(cpu, LIFT_CODE_TOKEN_VA(0x440D4Au));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040D5D:
    if ((int32_t)g_sfera_mbc_runtime->argument_count <= (int32_t)1u) goto label_00040DB2;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440D6Bu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440D6Bu));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440D81u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x440D81u));
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x10u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = cpu->ecx & 0xFFu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->setSystemCursorVisible(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    g_sfera_recovered_static_runtime.interaction_enabled = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040DB2:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440DB7u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x440DB7u));
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->isSystemCursorVisible(cpu);
    cpu->ecx = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440DC8u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x440DC8u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040DDB:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440DE0u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440DE0u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440DF6u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x440DF6u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->setCursorKind(cpu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040E17:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440E1Cu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440E1Cu));
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=2u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00040E37;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440E2Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440E2Eu));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440E35u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440E35u));
    goto label_00040E3F;
    label_00040E37:
    cpu->esi = 8u;
    cpu->eax = cpu->esi + 0xFFFFFFF0u;
    label_00040E3F:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440E58u)); sfera_sub_004B84B0(cpu, LIFT_CODE_TOKEN_VA(0x440E58u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040E6B:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440E70u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440E70u));
    cpu->ecx = g_sfera_mbc_runtime->argument_count;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)cpu->ecx <= (int32_t)3u) goto label_00040E99;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440E84u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440E84u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440E8Bu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440E8Bu));
    cpu->ecx = g_sfera_mbc_runtime->argument_count;
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    goto label_00040EA1;
    label_00040E99:
    cpu->esi = 8u;
    cpu->edi = cpu->esi + 8u;
    label_00040EA1:
    if (cpu->ecx == 3u) goto label_00040EB0;
    if (cpu->ecx == 5u) goto label_00040EB0;
    cpu->ecx |= 0xFFFFFFFFu;
    goto label_00040EBB;
    label_00040EB0:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440EB5u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440EB5u));
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    label_00040EBB:
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    if (cpu->eax == 0u) goto label_00040F19;
    if ((int32_t)cpu->ecx >= 0) goto label_00040EE1;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->edi);
    cpu->ecx += cpu->eax;
    cpu->edx = cpu->esi;
    goto label_00040F1F;
    label_00040EE1:
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, 0x20u); lift_push32(cpu, 8u);
    cpu->edx += cpu->eax;
    cpu->ecx = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440EF7u)); sfera_sub_004B8680(cpu, LIFT_CODE_TOKEN_VA(0x440EF7u));
    cpu->edx = 0x10u;
    lift_push32(cpu, 0x10u);
    cpu->ecx = cpu->edx + 0xFFFFFFF2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440F06u)); sfera_sub_004B86B0(cpu, LIFT_CODE_TOKEN_VA(0x440F06u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040F19:
    cpu->edx = 0u;
    lift_push32(cpu, 0u);
    cpu->ecx = 0u;
    label_00040F1F:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440F24u)); sfera_sub_004B8630(cpu, LIFT_CODE_TOKEN_VA(0x440F24u));
    lift_push32(cpu, 0u);
    cpu->edx = 0u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edx + 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440F32u)); sfera_sub_004B8680(cpu, LIFT_CODE_TOKEN_VA(0x440F32u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040F45:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440F4Au)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440F4Au));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440F53u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440F53u));
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=3u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00040F72;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440F65u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440F65u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440F6Cu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440F6Cu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    goto label_00040F97;
    label_00040F72:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->ecx != 0u) goto label_00040F82;
    cpu->esi = cpu->ecx + 6u;
    cpu->eax = cpu->ecx + 0x28u;
    goto label_00040F97;
    label_00040F82:
    if (cpu->ecx != 1u) goto label_00040F8F;
    cpu->esi = cpu->ecx + 0xFu;
    cpu->eax = cpu->ecx + 5u;
    goto label_00040F97;
    label_00040F8F:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    label_00040F97:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440FB5u)); sfera_sub_004B86D0(cpu, LIFT_CODE_TOKEN_VA(0x440FB5u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040FC8:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440FCDu)); sfera_sub_004B83C0(cpu, LIFT_CODE_TOKEN_VA(0x440FCDu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00041A9F;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440FDAu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440FDAu));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440FE3u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440FE3u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440FEAu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440FEAu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440FF1u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x440FF1u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441015u)); sfera_sub_004BAAA0(cpu, LIFT_CODE_TOKEN_VA(0x441015u));
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441020u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x441020u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx == 0u) goto label_00041B5B;
    cpu->edx = 7u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441036u)); sfera_sub_00437A10(cpu, LIFT_CODE_TOKEN_VA(0x441036u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041049:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44104Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44104Eu));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    cpu->edx = 1u;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44106Bu)); sfera_sub_004B8700(cpu, LIFT_CODE_TOKEN_VA(0x44106Bu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, 0u);
    cpu->edx = 7u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44107Bu)); sfera_sub_00437B10(cpu, LIFT_CODE_TOKEN_VA(0x44107Bu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004108E:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441093u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441093u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (cpu->eax != 0u) goto label_000410AD;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, PEEK_MESSAGE, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4410AAu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4410AAu));
    cpu->esp += 8u;
    label_000410AD:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4410B2u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4410B2u));
    cpu->ebx = cpu->eax;
    if (cpu->ebx != 0u) goto label_000410CA;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, PEEK_MESSAGE, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4410C7u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4410C7u));
    cpu->esp += 8u;
    label_000410CA:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4410CFu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4410CFu));
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_000410E7;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, PEEK_MESSAGE, 3\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4410E4u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4410E4u));
    cpu->esp += 8u;
    label_000410E7:
    if ((int32_t)g_sfera_mbc_runtime->argument_count < (int32_t)5u) goto label_0004110F;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4410F5u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4410F5u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->eax != 0u) goto label_0004110F;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, PEEK_MESSAGE, 4\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44110Cu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44110Cu));
    cpu->esp += 8u;
    label_0004110F:
    cpu->ebp = 6u;
    if (g_sfera_mbc_runtime->argument_count != cpu->ebp) goto label_0004113B;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441121u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441121u));
    cpu->edi = cpu->eax;
    if (cpu->edi != 0u) goto label_0004113F;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, PEEK_MESSAGE, 5\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441136u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x441136u));
    cpu->esp += 8u;
    goto label_0004113F;
    label_0004113B:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    label_0004113F:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441159u)); sfera_sub_004B8740(cpu, LIFT_CODE_TOKEN_VA(0x441159u));
    if (cpu->eax == 0u) goto label_00041A9F;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->edx + cpu->ebx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->edx + cpu->esi) = cpu->ecx;
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    if (cpu->eax != 5u) goto label_0004120C;
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x28u), r=0xFA1u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000411DE;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax >>= 16u;
    *(uint32_t*)(cpu->ecx + cpu->ebx) = cpu->eax;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->edx + cpu->esi) = cpu->eax;
    cpu->ecx = *(uint16_t*)(cpu->esp + 0x30u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->eax + cpu->edx) = cpu->ecx;
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4411CBu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4411CBu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000411DE:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->edx + cpu->ecx) = 0xFFFFFFFFu;
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4411F9u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4411F9u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004120C:
    if (cpu->eax != cpu->ebp) goto label_0004122D;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->eax + cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->ecx + cpu->edi) = cpu->eax;
    label_0004122D:
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441237u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x441237u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004124A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44124Fu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44124Fu));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441258u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441258u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx += cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441276u)); sfera_sub_004BACE0(cpu, LIFT_CODE_TOKEN_VA(0x441276u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44127Du)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44127Du));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041290:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441295u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441295u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44129Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44129Eu));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4412B6u)); sfera_sub_004B9820(cpu, LIFT_CODE_TOKEN_VA(0x4412B6u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4412BDu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4412BDu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000412D0:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4412D5u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4412D5u));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4412DCu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4412DCu));
    cpu->ebp = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4412E3u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4412E3u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4412EAu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4412EAu));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4412F1u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4412F1u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    if ((((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_0004130E;
    if (cpu->edi == 0u) goto label_0004130E;
    cpu->edi += cpu->ecx;
    label_0004130E:
    if ((((cpu->eax & 0xFFu)) & (2u)) == 0u) goto label_00041318;
    if (cpu->esi == 0u) goto label_00041318;
    cpu->esi += cpu->ecx;
    label_00041318:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441323u)); sfera_sub_004BB750(cpu, LIFT_CODE_TOKEN_VA(0x441323u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44132Au)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44132Au));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004133D:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441342u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441342u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44134Bu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44134Bu));
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_00041363;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, GET_WINDOW_TEXT\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441360u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x441360u));
    cpu->esp += 8u;
    label_00041363:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441368u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441368u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    if ((int32_t)cpu->eax >= (int32_t)1u) goto label_0004137F;
    cpu->eax = 1u;
    label_0004137F:
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    --cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->edx + cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441393u)); sfera_sub_004B9150(cpu, LIFT_CODE_TOKEN_VA(0x441393u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44139Au)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44139Au));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000413AD:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4413B2u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4413B2u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (cpu->eax != 0u) goto label_000413CC;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, GET_SYSTEM_MESSAGE\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4413C9u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4413C9u));
    cpu->esp += 8u;
    label_000413CC:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4413E2u)); sfera_sub_004BA6B0(cpu, LIFT_CODE_TOKEN_VA(0x4413E2u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4413E9u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4413E9u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + cpu->ecx) = cpu->edx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004140C:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441411u)); sfera_sub_004B98B0(cpu, LIFT_CODE_TOKEN_VA(0x441411u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441418u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x441418u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004142B:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441430u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441430u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441439u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441439u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441451u)); sfera_sub_004B8750(cpu, LIFT_CODE_TOKEN_VA(0x441451u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441458u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x441458u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004146B:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441470u)); sfera_sub_004B99E0(cpu, LIFT_CODE_TOKEN_VA(0x441470u));
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44147Bu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44147Bu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004148E:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441493u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441493u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44149Cu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44149Cu));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx += g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4414BAu)); sfera_sub_004BC650(cpu, LIFT_CODE_TOKEN_VA(0x4414BAu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000414CD:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4414D2u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4414D2u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4414F0u)); sfera_sub_004B9A10(cpu, LIFT_CODE_TOKEN_VA(0x4414F0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041503:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441508u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441508u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441511u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441511u));
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_00041529;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, GET_WINDOW_POS, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441526u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x441526u));
    cpu->esp += 8u;
    label_00041529:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44152Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44152Eu));
    cpu->edi = cpu->eax;
    if (cpu->edi != 0u) goto label_00041546;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, GET_WINDOW_POS, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441543u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x441543u));
    cpu->esp += 8u;
    label_00041546:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441565u)); sfera_sub_004B87A0(cpu, LIFT_CODE_TOKEN_VA(0x441565u));
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->eax + cpu->esi) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->eax + cpu->edi) = cpu->edx;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041590:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441595u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441595u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44159Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44159Eu));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4415A5u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4415A5u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4415C6u)); sfera_sub_004B8780(cpu, LIFT_CODE_TOKEN_VA(0x4415C6u));
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->edx + cpu->esi) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->edx + cpu->edi) = cpu->ecx;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000415F3:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4415F8u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4415F8u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441601u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441601u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0xFAu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441627u)); sfera_sub_004A21F0(cpu, LIFT_CODE_TOKEN_VA(0x441627u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44162Eu)); sfera_sub_004A2670(cpu, LIFT_CODE_TOKEN_VA(0x44162Eu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041641:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441646u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441646u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    if (cpu->eax != 0u) goto label_00041675;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441662u)); sfera_sub_004B8A40(cpu, LIFT_CODE_TOKEN_VA(0x441662u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041675:
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = cpu->ecx + cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441683u)); sfera_sub_004B8A40(cpu, LIFT_CODE_TOKEN_VA(0x441683u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041696:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19 == 0u) goto label_00041A9F;
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=1u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uintptr_t)"options";
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_000416DB;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4416B6u)); sfera_sub_004B9A70(cpu, LIFT_CODE_TOKEN_VA(0x4416B6u));
    if (cpu->eax == 0u) goto label_00041746;
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4416C8u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4416C8u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000416DB:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4416E0u)); sfera_sub_004B9A70(cpu, LIFT_CODE_TOKEN_VA(0x4416E0u));
    if (cpu->eax != 0u) goto label_00041708;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4416EBu)); sfera_sub_004CD1A0(cpu, LIFT_CODE_TOKEN_VA(0x4416EBu));
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4416F5u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4416F5u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041708:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44170Fu)); sfera_sub_004CD1A0(cpu, LIFT_CODE_TOKEN_VA(0x44170Fu));
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441719u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x441719u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004172C:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19 == 0u) goto label_00041A9F;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44173Eu)); sfera_sub_004B9AD0(cpu, LIFT_CODE_TOKEN_VA(0x44173Eu));
    if (cpu->eax != 0u) goto label_00041AD4;
    label_00041746:
    cpu->ecx |= 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44174Eu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44174Eu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041761:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441766u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441766u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44176Fu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44176Fu));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44178Bu)); sfera_sub_004D14A0(cpu, LIFT_CODE_TOKEN_VA(0x44178Bu));
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441796u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x441796u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != 0u) goto label_000417BB;
    cpu->ecx = (uintptr_t)"Error creating GUI window";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4417A8u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x4417A8u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000417BB:
    cpu->edx = 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4417C5u)); sfera_sub_00437A10(cpu, LIFT_CODE_TOKEN_VA(0x4417C5u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000417D8:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4417DDu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4417DDu));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4417F5u)); sfera_sub_004D12C0(cpu, LIFT_CODE_TOKEN_VA(0x4417F5u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, 0u);
    cpu->edx = 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441805u)); sfera_sub_00437B10(cpu, LIFT_CODE_TOKEN_VA(0x441805u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041818:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44181Du)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44181Du));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441826u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441826u));
    cpu->edi = cpu->eax;
    if (cpu->edi != 0u) goto label_0004183E;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, PEEK_MESSAGEGUI, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44183Bu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44183Bu));
    cpu->esp += 8u;
    label_0004183E:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441843u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441843u));
    cpu->ebx = cpu->eax;
    if (cpu->ebx != 0u) goto label_0004185B;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, PEEK_MESSAGEGUI, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441858u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x441858u));
    cpu->esp += 8u;
    label_0004185B:
    if ((int32_t)g_sfera_mbc_runtime->argument_count < (int32_t)5u) goto label_00041883;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441869u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441869u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->eax != 0u) goto label_00041883;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, PEEK_MESSAGEGUI, 3\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441880u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x441880u));
    cpu->esp += 8u;
    label_00041883:
    cpu->ebp = 6u;
    if (g_sfera_mbc_runtime->argument_count != cpu->ebp) goto label_000418AF;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441895u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441895u));
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_000418B3;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, PEEK_MESSAGEGUI, 4\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4418AAu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4418AAu));
    cpu->esp += 8u;
    goto label_000418B3;
    label_000418AF:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    label_000418B3:
    if ((int32_t)g_sfera_mbc_runtime->argument_count < (int32_t)5u) goto label_000418C5;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4418C1u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4418C1u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    label_000418C5:
    if (g_sfera_mbc_runtime->argument_count != cpu->ebp) goto label_000418D4;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4418D2u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4418D2u));
    cpu->esi = cpu->eax;
    label_000418D4:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4418EEu)); sfera_sub_004D1360(cpu, LIFT_CODE_TOKEN_VA(0x4418EEu));
    if (cpu->eax == 0u) goto label_00041A9F;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->eax + cpu->edi) = cpu->ecx;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->edx + cpu->ebx) = cpu->eax;
    if (g_sfera_mbc_runtime->argument_count != cpu->ebp) goto label_00041935;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->ecx + cpu->edx) = cpu->eax;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->ecx + cpu->esi) = cpu->edx;
    label_00041935:
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44193Fu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44193Fu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041952:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441957u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441957u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441960u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441960u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441967u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441967u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44196Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44196Eu));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441977u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441977u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    if ((((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_00041990;
    cpu->esi += cpu->ecx;
    label_00041990:
    if ((((cpu->eax & 0xFFu)) & (2u)) == 0u) goto label_00041998;
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    label_00041998:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4419A9u)); sfera_sub_004D1060(cpu, LIFT_CODE_TOKEN_VA(0x4419A9u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4419B0u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4419B0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000419C3:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4419C8u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4419C8u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4419D1u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4419D1u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4419E9u)); sfera_sub_004D0F50(cpu, LIFT_CODE_TOKEN_VA(0x4419E9u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4419F0u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4419F0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041A03:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441A08u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441A08u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441A11u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441A11u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->edx + cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441A30u)); sfera_sub_004D10D0(cpu, LIFT_CODE_TOKEN_VA(0x441A30u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441A37u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x441A37u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041A4A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441A4Fu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441A4Fu));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441A58u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441A58u));
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_00041A70;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, GET_WINDOW_TEXTGUI\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441A6Du)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x441A6Du));
    cpu->esp += 8u;
    label_00041A70:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441A75u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441A75u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    if ((int32_t)cpu->eax >= (int32_t)1u) goto label_00041A8C;
    cpu->eax = 1u;
    label_00041A8C:
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    --cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->edx += cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x41A9Fu)); sfera_sub_004D1110(cpu, LIFT_CODE_TOKEN_RVA(0x41A9Fu));
    label_00041A9F:
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441AA6u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x441AA6u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041AB9:
    if ((int32_t)g_sfera_mbc_runtime->argument_count <= (int32_t)1u) goto label_00041AF1;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441AC7u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441AC7u));
    { uint64_t l=(*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state_04), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00041A9F;
    label_00041AD4:
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441ADEu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x441ADEu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041AF1:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    g_sfera_client_process_runtime.shutdown_requested = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041B0E:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441B13u)); sfera_sub_0044C160(cpu, LIFT_CODE_TOKEN_VA(0x441B13u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041B26:
    if (g_sfera_recovered_static_runtime.loadcount_guard != 0u) goto label_00041B5B;
    cpu->ecx = 0x50u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441B39u)); sfera_sub_00461700(cpu, LIFT_CODE_TOKEN_VA(0x441B39u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041B4C:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441B51u)); sfera_sub_00451890(cpu, LIFT_CODE_TOKEN_VA(0x441B51u));
    g_sfera_recovered_static_runtime.loadcount_guard = 1u;
    label_00041B5B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00041B5F:
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00441C90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441C96u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441C96u));
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_00041CAE;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: thisname\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441CABu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x441CABu));
    cpu->esp += 8u;
    label_00041CAE:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041CD2;
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += 0x10u;
    cpu->edx += cpu->esi;
    label_00041CC8:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00041CC8;
    label_00041CD2:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00441CE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441CE7u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441CE7u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441CEEu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441CEEu));
    cpu->edi = cpu->eax;
    if (cpu->edi != 0u) goto label_00041D06;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: prc_name\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441D03u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x441D03u));
    cpu->esp += 8u;
    label_00041D06:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041D5B;
    if (cpu->esi <= 0xFFFFu) goto label_00041D21;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00041D21:
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    cpu->esi += ((uintptr_t)&g_sfera_mbc_runtime->processes[0]);
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x6Cu) >= (int32_t)0u) goto label_00041D3D;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00041D3D:
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = cpu->esi + 0x10u;
    cpu->edx += cpu->edi;
    label_00041D48:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00041D48;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00041D5B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00441D60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441D66u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441D66u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441D6Du)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441D6Du));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041DBF;
    if (cpu->esi > 0xFFFu) goto label_00041DB6;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x8D8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi += cpu->eax;
    cpu->eax = cpu->esi + ((uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0]);
    cpu->edx = cpu->edi;
    cpu->edx -= cpu->eax;
    label_00041D97:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00041D97;
    { uint64_t l=*(uint8_t*)(cpu->edi), r=(cpu->ecx & 0xFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041DAF;
    cpu->ecx |= 0xFFFFFFFFu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00041DAF:
    cpu->ecx = 0u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00041DB6:
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00041DBF:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00441DD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441DD5u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441DD5u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041E7D;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::_stricmp);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx += cpu->eax;
    cpu->edi = 0u;
    cpu->esi = (uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0];
    label_00041E00:
    if (*(uint8_t*)(cpu->esi) == 0u) goto label_00041E10;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x41E09u), LIFT_CODE_TOKEN_RVA(0x41E07u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_00041E3B;
    label_00041E10:
    ++cpu->edi;
    cpu->esi += 0x8D8u;
    if ((int32_t)cpu->edi < (int32_t)0x1000u) goto label_00041E00;
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    { uint64_t l=cpu->ecx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00041E46;
    cpu->ecx = (uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_00041E3B:
    cpu->ecx = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00041E46:
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    cpu->edx |= 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = cpu->edx;
    cpu->edx = 1u;
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = cpu->edx;
    g_sfera_mbc_runtime->value_stack_size = cpu->ecx;
    label_00041E7D:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00441E80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if (cpu->eax != 4u) goto label_00041EE3;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441E94u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441E94u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441E9Bu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441E9Bu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441EA2u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441EA2u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441EA7u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441EA7u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041FD3;
    if (cpu->esi != 0u) goto label_00041EC7;
    cpu->edx = (uintptr_t)"";
    cpu->ecx = (uintptr_t)"Effect attached to zero handle!";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x41EC7u)); sfera_sub_00438640(cpu, LIFT_CODE_TOKEN_RVA(0x41EC7u));
    label_00041EC7:
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = cpu->ecx + cpu->edi;
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441ED7u)); sfera_sub_0042AD40(cpu, LIFT_CODE_TOKEN_VA(0x441ED7u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00041EE3:
    if ((int32_t)cpu->eax >= (int32_t)3u) goto label_00041F43;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441EEDu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441EEDu));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441EF4u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441EF4u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041FD3;
    if ((int32_t)cpu->esi > 0) goto label_00041F2E;
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    cpu->ecx += 0x10u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Wrong Handler for Effect %s\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441F1Eu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x441F1Eu));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00041F2E:
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441F37u)); sfera_sub_0042AB10(cpu, LIFT_CODE_TOKEN_VA(0x441F37u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00041F43:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441F48u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441F48u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441F4Fu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441F4Fu));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441F56u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441F56u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041FD3;
    if ((int32_t)cpu->esi > 0) goto label_00041F8D;
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->edx += 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"Wrong Handler for Effect %s\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441F7Cu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x441F7Cu));
    cpu->esp += 0xCu;
    label_00041F7F:
    cpu->ecx |= 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441F87u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x441F87u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041F8D:
    if (cpu->eax != 0u) goto label_00041FAF;
    if (cpu->esi == g_sfera_world_objects.controlled_object_handle) goto label_00041F7F;
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441FA2u)); sfera_sub_0042AB10(cpu, LIFT_CODE_TOKEN_VA(0x441FA2u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441FA9u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x441FA9u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041FAF:
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    lift_push32(cpu, 1u);
    cpu->edx = cpu->esp + 0xCu;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441FCCu)); sfera_sub_00425CF0(cpu, LIFT_CODE_TOKEN_VA(0x441FCCu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x41FD3u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x41FD3u));
    label_00041FD3:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00441FE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441FE9u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x441FE9u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00042028;
    if ((int32_t)cpu->esi > 0) goto label_00042003;
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00042003:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44200Au)); sfera_sub_004360D0(cpu, LIFT_CODE_TOKEN_VA(0x44200Au));
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    cpu->eax = cpu->eax + cpu->esi + 0xFFFFFFFFu;
    cpu->edx = 1u;
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x42028u)); sfera_sub_0043AF30(cpu, LIFT_CODE_TOKEN_RVA(0x42028u));
    label_00042028:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00442030(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442038u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x442038u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44203Fu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44203Fu));
    cpu->ebp = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax == 0u) goto label_000420A8;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if (cpu->ecx < cpu->eax) goto label_00042053;
    if (cpu->ecx <= *(uint32_t*)(cpu->esi + 8u)) goto label_000420A8;
    label_00042053:
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44205Du)); sfera_sub_00434AF0(cpu, LIFT_CODE_TOKEN_VA(0x44205Du));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44207Du)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x44207Du));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->esp += 0x18u;
    if (cpu->eax == 0u) goto label_000420A8;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ecx == 0u) goto label_000420A8;
    { uint64_t l=cpu->eax, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00042098;
    if (cpu->eax <= *(uint32_t*)(cpu->esi + 8u)) goto label_000420A8;
    { uint64_t l=cpu->eax, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_00042098:
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0004209F;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    goto label_000420A8;
    label_0004209F:
    --cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)*(uint32_t*)(cpu->esi + 8u)) goto label_000420A8;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    label_000420A8:
    cpu->ebx = *(uint32_t*)(cpu->esi);
    cpu->ebx += g_sfera_mbc_runtime->process_memory_base;
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0004212E;
    lift_push32(cpu, cpu->edi);
    if ((int32_t)cpu->ebp > 0) goto label_000420C2;
    cpu->edi = 0u;
    goto label_0004210A;
    label_000420C2:
    lift_push32(cpu, 0x35B4u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4420D3u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4420D3u));
    if (cpu->eax != 0u) goto label_000420DB;
    cpu->edi = 0u;
    goto label_0004210A;
    label_000420DB:
    cpu->eax -= g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = 3u;
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4420EFu)); sfera_sub_00437A10(cpu, LIFT_CODE_TOKEN_VA(0x4420EFu));
    cpu->eax = g_sfera_mbc_runtime->active_process;
    if ((int32_t)*(uint32_t*)(cpu->eax + 0x44u) <= (int32_t)0u) goto label_0004210A;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x44u);
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->ecx = cpu->ebp + 8u;
    g_sfera_mbc_module_memory_stats[cpu->eax / 3u].dynamic_memory_bytes += cpu->ecx;
    label_0004210A:
    if (*(uint32_t*)(cpu->ebx) == 0u) goto label_00042121;
    lift_push32(cpu, (uintptr_t)"ffdmalloc: ptr != NULL"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44211Eu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44211Eu));
    cpu->esp += 8u;
    label_00042121:
    cpu->edx = cpu->edi + cpu->ebp + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebx + 4u) = cpu->edi;
    *(uint32_t*)(cpu->ebx) = cpu->edi;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->edx;
    cpu->edi = lift_pop32(cpu);
    label_0004212E:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00442140(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442147u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x442147u));
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax == 0u) goto label_000421B0;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if (cpu->ecx < cpu->eax) goto label_0004215B;
    if (cpu->ecx <= *(uint32_t*)(cpu->esi + 8u)) goto label_000421B0;
    label_0004215B:
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442165u)); sfera_sub_00434AF0(cpu, LIFT_CODE_TOKEN_VA(0x442165u));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442185u)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x442185u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->esp += 0x18u;
    if (cpu->eax == 0u) goto label_000421B0;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ecx == 0u) goto label_000421B0;
    { uint64_t l=cpu->eax, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000421A0;
    if (cpu->eax <= *(uint32_t*)(cpu->esi + 8u)) goto label_000421B0;
    { uint64_t l=cpu->eax, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_000421A0:
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_000421A7;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    goto label_000421B0;
    label_000421A7:
    --cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)*(uint32_t*)(cpu->esi + 8u)) goto label_000421B0;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    label_000421B0:
    cpu->edi = *(uint32_t*)(cpu->esi);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi += cpu->eax;
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00042219;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->edi);
    if (cpu->ebx == 0u) goto label_00042218;
    cpu->ebx += cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->active_process;
    if ((int32_t)*(uint32_t*)(cpu->eax + 0x44u) <= (int32_t)0u) goto label_000421F2;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x44u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->eax + (cpu->eax * 2u);
    cpu->eax = cpu->ebx + 0xFFFFFFFCu;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_msize), LIFT_CODE_TOKEN_VA(0x4421E1u));
    cpu->esp += 4u;
    g_sfera_mbc_module_memory_stats[cpu->ebp / 3u].dynamic_memory_bytes -= cpu->eax;
    cpu->ebp = lift_pop32(cpu);
    label_000421F2:
    lift_push32(cpu, 0x35EFu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442203u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x442203u));
    cpu->eax = 0u;
    *(uint32_t*)(cpu->edi) = cpu->eax;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->eax + 3u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x42218u)); sfera_sub_00437B10(cpu, LIFT_CODE_TOKEN_RVA(0x42218u));
    label_00042218:
    cpu->ebx = lift_pop32(cpu);
    label_00042219:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00442220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442229u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x442229u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442230u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x442230u));
    { uint64_t l=g_sfera_mbc_runtime->argument_count, r=2u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00042250;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442242u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x442242u));
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    if ((int32_t)cpu->eax < 0) goto label_00042392;
    goto label_00042258;
    label_00042250:
    *(uint32_t*)(cpu->esp + 4u) = 0u;
    label_00042258:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->edi);
    cpu->edi = g_sfera_mbc_runtime->named_vector_count;
    cpu->ebp += cpu->esi;
    cpu->ebx = 0u;
    cpu->esi = (uintptr_t)&g_sfera_mbc_runtime->named_vectors[0];
    g_sfera_mbc_runtime->named_vector_cursor = cpu->esi;
    if ((int32_t)cpu->edi <= 0) goto label_000422BC;
    label_00042280:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->eax = cpu->ebp;
    label_00042285:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    { uint64_t l=(cpu->edx & 0xFFu), r=*(uint8_t*)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000422A5;
    if ((cpu->edx & 0xFFu) == 0u) goto label_000422A1;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    { uint64_t l=(cpu->edx & 0xFFu), r=*(uint8_t*)(cpu->ecx + 1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000422A5;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00042285;
    label_000422A1:
    cpu->eax = 0u;
    goto label_000422AA;
    label_000422A5:
    { uint64_t l=cpu->eax, r=cpu->eax, c=((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000422AA:
    if (cpu->eax == 0u) goto label_00042323;
    cpu->esi += 0x10u;
    ++cpu->ebx;
    g_sfera_mbc_runtime->named_vector_cursor = cpu->esi;
    if ((int32_t)cpu->ebx < (int32_t)cpu->edi) goto label_00042280;
    label_000422BC:
    { uint64_t l=cpu->edi, r=0x3E8u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0004238F;
    cpu->ecx = cpu->edi;
    cpu->ecx <<= 4u;
    cpu->ecx += ((uintptr_t)&g_sfera_mbc_runtime->named_vectors[0]);
    ++cpu->edi;
    cpu->eax = cpu->ebp;
    g_sfera_mbc_runtime->named_vector_cursor = cpu->ecx;
    g_sfera_mbc_runtime->named_vector_count = cpu->edi;
    cpu->edx = cpu->eax + 1u;
    label_000422E5:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000422E5;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, 0x362Fu);
    cpu->ecx = cpu->eax + 1u;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442300u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x442300u));
    cpu->edx = g_sfera_mbc_runtime->named_vector_cursor;
    *(uint32_t*)(cpu->edx + 0xCu) = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->named_vector_cursor;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->ecx = cpu->ebp;
    label_00042313:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00042313;
    cpu->esi = g_sfera_mbc_runtime->named_vector_cursor;
    label_00042323:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) > (int32_t)cpu->edi) goto label_00042386;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, 0x3634u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp");
    cpu->edx = (cpu->edi * 4u) + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442344u)); sfera_sub_004EBE80(cpu, LIFT_CODE_TOKEN_VA(0x442344u));
    cpu->ecx = g_sfera_mbc_runtime->named_vector_cursor;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = g_sfera_mbc_runtime->named_vector_cursor;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    if ((int32_t)cpu->eax >= (int32_t)cpu->edi) goto label_00042374;
    label_00042360:
    cpu->ecx = g_sfera_mbc_runtime->named_vector_cursor;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->edx + (cpu->eax * 4u)) = 0u;
    ++cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)cpu->edi) goto label_00042360;
    label_00042374:
    cpu->ecx = g_sfera_mbc_runtime->named_vector_cursor;
    cpu->eax = cpu->edi + 1u;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    cpu->esi = g_sfera_mbc_runtime->named_vector_cursor;
    label_00042386:
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->edx + (cpu->edi * 4u)) = cpu->eax;
    label_0004238F:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00042392:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004423A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4423AAu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4423AAu));
    cpu->ebx = 1u;
    cpu->esi = cpu->eax;
    if ((int32_t)g_sfera_mbc_runtime->argument_count <= (int32_t)cpu->ebx) goto label_000423C4;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4423BEu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4423BEu));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    goto label_000423CC;
    label_000423C4:
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    label_000423CC:
    cpu->ebp = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = g_sfera_mbc_runtime->named_vector_count;
    cpu->ebp += cpu->esi;
    cpu->edi = 0u;
    cpu->esi = (uintptr_t)&g_sfera_mbc_runtime->named_vectors[0];
    g_sfera_mbc_runtime->named_vector_cursor = cpu->esi;
    if ((int32_t)cpu->eax <= 0) goto label_00042435;
    label_000423F0:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->ecx = cpu->ebp;
    label_000423F5:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    { uint64_t l=(cpu->ebx & 0xFFu), r=*(uint8_t*)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00042415;
    if ((cpu->ebx & 0xFFu) == 0u) goto label_00042411;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + 1u));
    { uint64_t l=(cpu->ebx & 0xFFu), r=*(uint8_t*)(cpu->edx + 1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00042415;
    cpu->ecx += 2u;
    cpu->edx += 2u;
    if ((cpu->ebx & 0xFFu) != 0u) goto label_000423F5;
    label_00042411:
    cpu->ecx = 0u;
    goto label_0004241A;
    label_00042415:
    { uint64_t l=cpu->ecx, r=cpu->ecx, c=((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = (uint64_t)(cpu->ecx) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_0004241A:
    if (cpu->ecx == 0u) goto label_000424AD;
    ++cpu->edi;
    cpu->esi += 0x10u;
    g_sfera_mbc_runtime->named_vector_cursor = cpu->esi;
    if ((int32_t)cpu->edi < (int32_t)cpu->eax) goto label_000423F0;
    cpu->ebx = 1u;
    label_00042435:
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->ecx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00042524;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44244Cu)); sfera_sub_00434D90(cpu, LIFT_CODE_TOKEN_VA(0x44244Cu));
    cpu->ecx = (uintptr_t)"\n---exit_inter start---\nMBINTER MESSAGE:";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442456u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x442456u));
    cpu->ecx = (uintptr_t)"Stack overflow";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442460u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x442460u));
    cpu->ecx = (uintptr_t)"\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44246Au)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x44246Au));
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442474u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x442474u));
    cpu->ecx = (uintptr_t)"---exit_inter end-----\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44247Eu)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x44247Eu));
    { uint64_t l=g_sfera_mbc_runtime->process_index, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    g_sfera_mbc_runtime->execution_failed = cpu->ebx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00042497;
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x42497u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x42497u));
    label_00042497:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->edx = (uintptr_t)"EError";
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->processes[0];
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00435020(cpu, stop_address); return;
    label_000424AD:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    if ((int32_t)cpu->eax >= 0) goto label_00042501;
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    { uint64_t l=cpu->ecx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000424D7;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = (uintptr_t)"Stack overflow";
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_004385D0(cpu, stop_address); return;
    label_000424D7:
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = cpu->edx;
    cpu->edx = 1u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = cpu->edx;
    cpu->ecx += cpu->edx;
    goto label_0004254B;
    label_00042501:
    cpu->edi = lift_pop32(cpu);
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00042514;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00042514:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00042524:
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = 0u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = cpu->ebx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = cpu->ebx;
    cpu->ecx += cpu->ebx;
    label_0004254B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    g_sfera_mbc_runtime->value_stack_size = cpu->ecx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00442570(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    cpu->eax = (uintptr_t)&g_sfera_font_runtime;
    cpu->eax -= g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = 1u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp) = cpu->eax;
    cpu->eax += 7u;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442599u)); sfera_sub_0043AF30(cpu, LIFT_CODE_TOKEN_VA(0x442599u));
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004425A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->ecx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000425B8;
    cpu->ecx = (uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_000425B8:
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x10u;
    cpu->edx |= 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = cpu->edx;
    cpu->edx = 1u;
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = cpu->edx;
    g_sfera_mbc_runtime->value_stack_size = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004425F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4425F6u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4425F6u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4425FDu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4425FDu));
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->edx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00042616;
    cpu->ecx = (uintptr_t)"Stack overflow";
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004385D0(cpu, stop_address); return;
    label_00042616:
    cpu->ecx = cpu->edx;
    cpu->ecx <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = 0x10u;
    cpu->eax &= cpu->esi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].payload[0] = cpu->eax;
    cpu->eax = 1u;
    cpu->edx += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_end = cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_begin = cpu->eax;
    g_sfera_mbc_runtime->value_stack_size = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00442660(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442666u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x442666u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44266Du)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44266Du));
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->edx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00042686;
    cpu->ecx = (uintptr_t)"Stack overflow";
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004385D0(cpu, stop_address); return;
    label_00042686:
    cpu->ecx = cpu->edx;
    cpu->ecx <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = 0x10u;
    cpu->eax |= cpu->esi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].payload[0] = cpu->eax;
    cpu->eax = 1u;
    cpu->edx += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_end = cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_begin = cpu->eax;
    g_sfera_mbc_runtime->value_stack_size = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004426D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4426D6u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4426D6u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4426DDu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4426DDu));
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->edx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000426F6;
    cpu->ecx = (uintptr_t)"Stack overflow";
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004385D0(cpu, stop_address); return;
    label_000426F6:
    cpu->ecx = cpu->edx;
    cpu->ecx <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = 0x10u;
    cpu->eax ^= cpu->esi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].payload[0] = cpu->eax;
    cpu->eax = 1u;
    cpu->edx += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_end = cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_begin = cpu->eax;
    g_sfera_mbc_runtime->value_stack_size = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00442740(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442745u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x442745u));
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->edx, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0004275D;
    cpu->ecx = (uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0004275D:
    cpu->ecx = cpu->edx;
    cpu->ecx <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = 0x10u;
    cpu->eax = ~((uint64_t)(cpu->eax));
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].payload[0] = cpu->eax;
    cpu->eax = 1u;
    cpu->edx += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_end = cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_begin = cpu->eax;
    g_sfera_mbc_runtime->value_stack_size = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004427A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4427A7u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4427A7u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4427AEu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4427AEu));
    cpu->edi = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->edi, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000427C8;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (uintptr_t)"Stack overflow";
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004385D0(cpu, stop_address); return;
    label_000427C8:
    cpu->ecx = cpu->eax;
    cpu->eax = 1u;
    cpu->edx = cpu->edi;
    cpu->edx <<= 5u;
    cpu->esi <<= (((cpu->ecx & 0xFFu)) & 31u);
    cpu->edi += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].type = 0x10u;
    g_sfera_mbc_runtime->value_stack_size = cpu->edi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].payload[0] = cpu->esi;
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].range_end = cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].range_begin = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00442810(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442817u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x442817u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44281Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44281Eu));
    cpu->edi = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->edi, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00042838;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (uintptr_t)"Stack overflow";
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004385D0(cpu, stop_address); return;
    label_00042838:
    cpu->ecx = cpu->eax;
    cpu->eax = 1u;
    cpu->edx = cpu->edi;
    cpu->edx <<= 5u;
    cpu->esi = (int32_t)(cpu->esi) >> (((cpu->ecx & 0xFFu)) & 31u);
    cpu->edi += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].type = 0x10u;
    g_sfera_mbc_runtime->value_stack_size = cpu->edi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].payload[0] = cpu->esi;
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].range_end = cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].range_begin = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00442880(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442887u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x442887u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44288Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44288Eu));
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->esi, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000428A8;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (uintptr_t)"Stack overflow";
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004385D0(cpu, stop_address); return;
    label_000428A8:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = 1u;
    cpu->ecx = cpu->eax;
    cpu->ebp = cpu->ebp << (((cpu->ecx & 0xFFu)) & 31u);
    cpu->edx = cpu->esi;
    cpu->edx <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].type = 0x10u;
    cpu->ebp = ~((uint64_t)(cpu->ebp));
    cpu->ebp &= cpu->edi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].payload[0] = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    ++cpu->esi;
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_runtime->value_stack_size = cpu->esi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].range_end = 1u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].range_begin = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00442900(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442907u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x442907u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44290Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44290Eu));
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=cpu->esi, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00042928;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (uintptr_t)"Stack overflow";
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004385D0(cpu, stop_address); return;
    label_00042928:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = 1u;
    cpu->ecx = cpu->eax;
    cpu->ebp = cpu->ebp << (((cpu->ecx & 0xFFu)) & 31u);
    cpu->edx = cpu->esi;
    cpu->edx <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].type = 0x10u;
    cpu->ebp |= cpu->edi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].payload[0] = cpu->ebp;
    cpu->ebp = lift_pop32(cpu);
    ++cpu->esi;
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_runtime->value_stack_size = cpu->esi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].range_end = 1u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].range_begin = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00442980(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442987u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x442987u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44298Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44298Eu));
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = cpu->eax;
    { uint64_t l=cpu->esi, r=0x100u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000429AA;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (uintptr_t)"Stack overflow";
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004385D0(cpu, stop_address); return;
    label_000429AA:
    lift_push32(cpu, cpu->ebx);
    cpu->eax = 1u;
    cpu->ebx = cpu->eax;
    cpu->ebx <<= (((cpu->ecx & 0xFFu)) & 31u);
    cpu->edx = cpu->esi;
    cpu->edx <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].type = 0x10u;
    { uint64_t l=cpu->ebx, r=cpu->edi, v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebx = v; }
    cpu->ebx = (int32_t)(cpu->ebx) >> (((cpu->ecx & 0xFFu)) & 31u);
    cpu->esi += cpu->eax;
    g_sfera_mbc_runtime->value_stack_size = cpu->esi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].payload[0] = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].source_id = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].range_end = cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].range_begin = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00442B60(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00042B60;
    label_000429F0:
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4429FEu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4429FEu));
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->ebx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ebp = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442A17u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x442A17u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00042A76;
    if ((int32_t)cpu->esi < (int32_t)0xFFFFFFFCu) goto label_00042A2E;
    if ((int32_t)cpu->esi < (int32_t)4u) goto label_00042A3E;
    label_00042A2E:
    if (cpu->ebx == 0u) goto label_00042A4B;
    if (cpu->esi < cpu->ebx) goto label_00042A3E;
    cpu->eax = cpu->esi + cpu->edi + 0xFFFFFFFFu;
    if (cpu->eax <= cpu->ebp) goto label_00042A4B;
    label_00042A3E:
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442A49u)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_VA(0x442A49u));
    goto label_00042A68;
    label_00042A4B:
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->esi;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x442A5Au));
    cpu->esp += 0xCu;
    cpu->esi += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    label_00042A68:
    cpu->edx = 1u;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x42A76u)); sfera_sub_0043AF30(cpu, LIFT_CODE_TOKEN_RVA(0x42A76u));
    label_00042A76:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00042B60:
    cpu->ecx = 1u;
    goto label_000429F0;
}
__declspec(noinline) void sfera_sub_00442B70(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00042B70;
    label_000429F0:
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4429FEu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4429FEu));
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->ebx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ebp = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442A17u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x442A17u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00042A76;
    if ((int32_t)cpu->esi < (int32_t)0xFFFFFFFCu) goto label_00042A2E;
    if ((int32_t)cpu->esi < (int32_t)4u) goto label_00042A3E;
    label_00042A2E:
    if (cpu->ebx == 0u) goto label_00042A4B;
    if (cpu->esi < cpu->ebx) goto label_00042A3E;
    cpu->eax = cpu->esi + cpu->edi + 0xFFFFFFFFu;
    if (cpu->eax <= cpu->ebp) goto label_00042A4B;
    label_00042A3E:
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442A49u)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_VA(0x442A49u));
    goto label_00042A68;
    label_00042A4B:
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->esi;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x442A5Au));
    cpu->esp += 0xCu;
    cpu->esi += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    label_00042A68:
    cpu->edx = 1u;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x42A76u)); sfera_sub_0043AF30(cpu, LIFT_CODE_TOKEN_RVA(0x42A76u));
    label_00042A76:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00042B70:
    cpu->ecx = 2u;
    goto label_000429F0;
}
__declspec(noinline) void sfera_sub_00442B80(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00042B80;
    label_000429F0:
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4429FEu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4429FEu));
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->ebx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ebp = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442A17u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x442A17u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00042A76;
    if ((int32_t)cpu->esi < (int32_t)0xFFFFFFFCu) goto label_00042A2E;
    if ((int32_t)cpu->esi < (int32_t)4u) goto label_00042A3E;
    label_00042A2E:
    if (cpu->ebx == 0u) goto label_00042A4B;
    if (cpu->esi < cpu->ebx) goto label_00042A3E;
    cpu->eax = cpu->esi + cpu->edi + 0xFFFFFFFFu;
    if (cpu->eax <= cpu->ebp) goto label_00042A4B;
    label_00042A3E:
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442A49u)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_VA(0x442A49u));
    goto label_00042A68;
    label_00042A4B:
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->esi;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x442A5Au));
    cpu->esp += 0xCu;
    cpu->esi += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    label_00042A68:
    cpu->edx = 1u;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x42A76u)); sfera_sub_0043AF30(cpu, LIFT_CODE_TOKEN_RVA(0x42A76u));
    label_00042A76:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00042B80:
    cpu->ecx = 3u;
    goto label_000429F0;
}
__declspec(noinline) void sfera_sub_00442B90(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00042B90;
    label_000429F0:
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4429FEu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4429FEu));
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->ebx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ebp = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442A17u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x442A17u));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00042A76;
    if ((int32_t)cpu->esi < (int32_t)0xFFFFFFFCu) goto label_00042A2E;
    if ((int32_t)cpu->esi < (int32_t)4u) goto label_00042A3E;
    label_00042A2E:
    if (cpu->ebx == 0u) goto label_00042A4B;
    if (cpu->esi < cpu->ebx) goto label_00042A3E;
    cpu->eax = cpu->esi + cpu->edi + 0xFFFFFFFFu;
    if (cpu->eax <= cpu->ebp) goto label_00042A4B;
    label_00042A3E:
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442A49u)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_VA(0x442A49u));
    goto label_00042A68;
    label_00042A4B:
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->esi;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x442A5Au));
    cpu->esp += 0xCu;
    cpu->esi += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    label_00042A68:
    cpu->edx = 1u;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x42A76u)); sfera_sub_0043AF30(cpu, LIFT_CODE_TOKEN_RVA(0x42A76u));
    label_00042A76:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00042B90:
    cpu->ecx = 4u;
    goto label_000429F0;
}
__declspec(noinline) void sfera_sub_00442BA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442BABu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x442BABu));
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->edi = *(uint32_t*)(cpu->eax + 4u);
    cpu->ebx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442BC4u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x442BC4u));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00042C2F;
    if ((int32_t)cpu->esi < (int32_t)0xFFFFFFFCu) goto label_00042BDB;
    if ((int32_t)cpu->esi < (int32_t)4u) goto label_00042BEA;
    label_00042BDB:
    if (cpu->edi == 0u) goto label_00042C0D;
    if (cpu->esi < cpu->edi) goto label_00042BEA;
    cpu->eax = cpu->esi + 3u;
    if (cpu->eax <= cpu->ebx) goto label_00042C0D;
    label_00042BEA:
    cpu->edx = 4u;
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442BF8u)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_VA(0x442BF8u));
    cpu->edx = 1u;
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442C06u)); sfera_sub_0043AF30(cpu, LIFT_CODE_TOKEN_VA(0x442C06u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00042C0D:
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->edx + cpu->esi) = cpu->ecx;
    cpu->esi += 4u;
    cpu->edx = 1u;
    cpu->ecx = cpu->esp + 0x10u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x42C2Fu)); sfera_sub_0043AF30(cpu, LIFT_CODE_TOKEN_RVA(0x42C2Fu));
    label_00042C2F:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00442C40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442C4Bu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x442C4Bu));
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->ebp = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442C64u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x442C64u));
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if ((int32_t)cpu->eax < (int32_t)0xFFFFFFFCu) goto label_00042C72;
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_00042C82;
    label_00042C72:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ecx == 0u) goto label_00042CF3;
    if (cpu->eax < cpu->ecx) goto label_00042C82;
    if (cpu->eax <= *(uint32_t*)(cpu->esi + 8u)) goto label_00042CF3;
    label_00042C82:
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442C8Cu)); sfera_sub_00434AF0(cpu, LIFT_CODE_TOKEN_VA(0x442C8Cu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->esi);
    ++cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442CACu)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x442CACu));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->esp += 0x18u;
    if (cpu->eax == 0u) goto label_00042D78;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ecx == 0u) goto label_00042D78;
    { uint64_t l=cpu->eax, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00042CD3;
    if (cpu->eax <= *(uint32_t*)(cpu->esi + 8u)) goto label_00042D78;
    { uint64_t l=cpu->eax, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_00042CD3:
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_00042CDF;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00042CDF:
    --cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)*(uint32_t*)(cpu->esi + 8u)) goto label_00042D78;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00042CF3:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00042D78;
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = cpu->eax + cpu->esi;
    cpu->eax = cpu->ecx;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->eax + 1u;
    label_00042D10:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00042D10;
    cpu->eax -= cpu->ebx;
    cpu->edx = cpu->eax + 1u;
    cpu->esi += cpu->edi;
    cpu->ebx = lift_pop32(cpu);
    (void)cpu;
    label_00042D20:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->esi;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00042D20;
    if ((int32_t)cpu->edi < (int32_t)0xFFFFFFFCu) goto label_00042D34;
    if ((int32_t)cpu->edi < (int32_t)4u) goto label_00042D46;
    label_00042D34:
    if (cpu->ebp == 0u) goto label_00042D64;
    if (cpu->edi < cpu->ebp) goto label_00042D46;
    cpu->ecx = cpu->edx + cpu->edi + 0xFFFFFFFFu;
    if (cpu->ecx <= *(uint32_t*)(cpu->esp + 0x14u)) goto label_00042D64;
    label_00042D46:
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442D4Fu)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_VA(0x442D4Fu));
    cpu->edx = 1u;
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442D5Du)); sfera_sub_0043AF30(cpu, LIFT_CODE_TOKEN_VA(0x442D5Du));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00042D64:
    cpu->edi += cpu->edx;
    cpu->edx = 1u;
    cpu->ecx = cpu->esp + 0xCu;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x42D78u)); sfera_sub_0043AF30(cpu, LIFT_CODE_TOKEN_RVA(0x42D78u));
    label_00042D78:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00442D80(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00042D80;
    label_00042A80:
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    cpu->edi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442A92u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x442A92u));
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->ebp = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442AABu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x442AABu));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00042B4C;
    if ((int32_t)cpu->esi < (int32_t)0xFFFFFFFCu) goto label_00042AC4;
    if ((int32_t)cpu->esi < (int32_t)4u) goto label_00042AD6;
    label_00042AC4:
    if (cpu->ebp == 0u) goto label_00042AE3;
    if (cpu->esi < cpu->ebp) goto label_00042AD6;
    cpu->ecx = cpu->esi + cpu->edi + 0xFFFFFFFFu;
    if (cpu->ecx <= *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_00042AE3;
    label_00042AD6:
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442AE1u)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_VA(0x442AE1u));
    goto label_00042B3E;
    label_00042AE3:
    cpu->eax = *(uint32_t*)(cpu->ebx);
    if ((int32_t)cpu->eax < (int32_t)0xFFFFFFFCu) goto label_00042AEF;
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_00042B03;
    label_00042AEF:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    if (cpu->ecx == 0u) goto label_00042B0E;
    if (cpu->eax < cpu->ecx) goto label_00042B03;
    cpu->edx = cpu->eax + cpu->edi + 0xFFFFFFFFu;
    if (cpu->edx <= *(uint32_t*)(cpu->ebx + 8u)) goto label_00042B0E;
    label_00042B03:
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442B0Cu)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_VA(0x442B0Cu));
    goto label_00042B3E;
    label_00042B0E:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x442B1Cu));
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->eax + cpu->esi;
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x442B30u));
    cpu->esp += 0x18u;
    cpu->esi += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    label_00042B3E:
    cpu->edx = 1u;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x42B4Cu)); sfera_sub_0043AF30(cpu, LIFT_CODE_TOKEN_RVA(0x42B4Cu));
    label_00042B4C:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00042D80:
    cpu->edx = 0u;
    cpu->ecx = cpu->edx + 1u;
    goto label_00042A80;
}
__declspec(noinline) void sfera_sub_00442D90(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00042D90;
    label_00042A80:
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    cpu->edi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442A92u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x442A92u));
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->ebp = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442AABu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x442AABu));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00042B4C;
    if ((int32_t)cpu->esi < (int32_t)0xFFFFFFFCu) goto label_00042AC4;
    if ((int32_t)cpu->esi < (int32_t)4u) goto label_00042AD6;
    label_00042AC4:
    if (cpu->ebp == 0u) goto label_00042AE3;
    if (cpu->esi < cpu->ebp) goto label_00042AD6;
    cpu->ecx = cpu->esi + cpu->edi + 0xFFFFFFFFu;
    if (cpu->ecx <= *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_00042AE3;
    label_00042AD6:
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442AE1u)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_VA(0x442AE1u));
    goto label_00042B3E;
    label_00042AE3:
    cpu->eax = *(uint32_t*)(cpu->ebx);
    if ((int32_t)cpu->eax < (int32_t)0xFFFFFFFCu) goto label_00042AEF;
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_00042B03;
    label_00042AEF:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    if (cpu->ecx == 0u) goto label_00042B0E;
    if (cpu->eax < cpu->ecx) goto label_00042B03;
    cpu->edx = cpu->eax + cpu->edi + 0xFFFFFFFFu;
    if (cpu->edx <= *(uint32_t*)(cpu->ebx + 8u)) goto label_00042B0E;
    label_00042B03:
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442B0Cu)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_VA(0x442B0Cu));
    goto label_00042B3E;
    label_00042B0E:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x442B1Cu));
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->eax + cpu->esi;
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x442B30u));
    cpu->esp += 0x18u;
    cpu->esi += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    label_00042B3E:
    cpu->edx = 1u;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x42B4Cu)); sfera_sub_0043AF30(cpu, LIFT_CODE_TOKEN_RVA(0x42B4Cu));
    label_00042B4C:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00042D90:
    cpu->edx = 4u;
    cpu->ecx = cpu->edx + 0xFFFFFFFEu;
    goto label_00042A80;
}
__declspec(noinline) void sfera_sub_00442DA0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00042DA0;
    label_00042A80:
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    cpu->edi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442A92u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x442A92u));
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->ebp = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442AABu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x442AABu));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00042B4C;
    if ((int32_t)cpu->esi < (int32_t)0xFFFFFFFCu) goto label_00042AC4;
    if ((int32_t)cpu->esi < (int32_t)4u) goto label_00042AD6;
    label_00042AC4:
    if (cpu->ebp == 0u) goto label_00042AE3;
    if (cpu->esi < cpu->ebp) goto label_00042AD6;
    cpu->ecx = cpu->esi + cpu->edi + 0xFFFFFFFFu;
    if (cpu->ecx <= *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_00042AE3;
    label_00042AD6:
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442AE1u)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_VA(0x442AE1u));
    goto label_00042B3E;
    label_00042AE3:
    cpu->eax = *(uint32_t*)(cpu->ebx);
    if ((int32_t)cpu->eax < (int32_t)0xFFFFFFFCu) goto label_00042AEF;
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_00042B03;
    label_00042AEF:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    if (cpu->ecx == 0u) goto label_00042B0E;
    if (cpu->eax < cpu->ecx) goto label_00042B03;
    cpu->edx = cpu->eax + cpu->edi + 0xFFFFFFFFu;
    if (cpu->edx <= *(uint32_t*)(cpu->ebx + 8u)) goto label_00042B0E;
    label_00042B03:
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442B0Cu)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_VA(0x442B0Cu));
    goto label_00042B3E;
    label_00042B0E:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x442B1Cu));
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->eax + cpu->esi;
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x442B30u));
    cpu->esp += 0x18u;
    cpu->esi += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    label_00042B3E:
    cpu->edx = 1u;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x42B4Cu)); sfera_sub_0043AF30(cpu, LIFT_CODE_TOKEN_RVA(0x42B4Cu));
    label_00042B4C:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00042DA0:
    cpu->edx = 4u;
    cpu->ecx = cpu->edx + 0xFFFFFFFFu;
    goto label_00042A80;
}
__declspec(noinline) void sfera_sub_00442DB0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00042DB0;
    label_00042A80:
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    cpu->edi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442A92u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x442A92u));
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->ebp = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442AABu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x442AABu));
    { uint64_t l=g_sfera_mbc_runtime->execution_failed, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00042B4C;
    if ((int32_t)cpu->esi < (int32_t)0xFFFFFFFCu) goto label_00042AC4;
    if ((int32_t)cpu->esi < (int32_t)4u) goto label_00042AD6;
    label_00042AC4:
    if (cpu->ebp == 0u) goto label_00042AE3;
    if (cpu->esi < cpu->ebp) goto label_00042AD6;
    cpu->ecx = cpu->esi + cpu->edi + 0xFFFFFFFFu;
    if (cpu->ecx <= *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_00042AE3;
    label_00042AD6:
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442AE1u)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_VA(0x442AE1u));
    goto label_00042B3E;
    label_00042AE3:
    cpu->eax = *(uint32_t*)(cpu->ebx);
    if ((int32_t)cpu->eax < (int32_t)0xFFFFFFFCu) goto label_00042AEF;
    if ((int32_t)cpu->eax < (int32_t)4u) goto label_00042B03;
    label_00042AEF:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    if (cpu->ecx == 0u) goto label_00042B0E;
    if (cpu->eax < cpu->ecx) goto label_00042B03;
    cpu->edx = cpu->eax + cpu->edi + 0xFFFFFFFFu;
    if (cpu->edx <= *(uint32_t*)(cpu->ebx + 8u)) goto label_00042B0E;
    label_00042B03:
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442B0Cu)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_VA(0x442B0Cu));
    goto label_00042B3E;
    label_00042B0E:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x442B1Cu));
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->eax + cpu->esi;
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x442B30u));
    cpu->esp += 0x18u;
    cpu->esi += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    label_00042B3E:
    cpu->edx = 1u;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x42B4Cu)); sfera_sub_0043AF30(cpu, LIFT_CODE_TOKEN_RVA(0x42B4Cu));
    label_00042B4C:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00042DB0:
    cpu->edx = 0u;
    cpu->ecx = cpu->edx + 4u;
    goto label_00042A80;
}
__declspec(noinline) void sfera_sub_00442DC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442DCBu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x442DCBu));
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->edi = *(uint32_t*)(cpu->eax + 4u);
    cpu->ebx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442DE4u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x442DE4u));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00042E6C;
    if ((int32_t)cpu->esi < (int32_t)0xFFFFFFFCu) goto label_00042DF7;
    if ((int32_t)cpu->esi < (int32_t)4u) goto label_00042E06;
    label_00042DF7:
    if (cpu->edi == 0u) goto label_00042E1B;
    if (cpu->esi < cpu->edi) goto label_00042E06;
    cpu->ecx = cpu->esi + 3u;
    if (cpu->ecx <= cpu->ebx) goto label_00042E1B;
    label_00042E06:
    cpu->edx = 4u;
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442E14u)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_VA(0x442E14u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00042E1B:
    cpu->edx = *(uint32_t*)(cpu->eax);
    if ((int32_t)cpu->edx < (int32_t)0xFFFFFFFCu) goto label_00042E27;
    if ((int32_t)cpu->edx < (int32_t)4u) goto label_00042E3A;
    label_00042E27:
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    if (cpu->ecx == 0u) goto label_00042E4C;
    if (cpu->edx < cpu->ecx) goto label_00042E3A;
    cpu->ecx = cpu->edx + 3u;
    if (cpu->ecx <= *(uint32_t*)(cpu->eax + 8u)) goto label_00042E4C;
    label_00042E3A:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->edx = 4u;
    cpu->ecx = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    sfera_sub_00434E80(cpu, stop_address); return;
    label_00042E4C:
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = *(uint32_t*)(cpu->eax + cpu->esi);
    *(uint32_t*)(cpu->edx + cpu->eax) = cpu->ecx;
    cpu->esi += 4u;
    cpu->edx = 1u;
    cpu->ecx = cpu->esp + 0xCu;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x42E6Cu)); sfera_sub_0043AF30(cpu, LIFT_CODE_TOKEN_RVA(0x42E6Cu));
    label_00042E6C:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00442E80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442E8Cu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x442E8Cu));
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    cpu->ebx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442EA5u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x442EA5u));
    cpu->ebp = cpu->eax;
    if ((int32_t)cpu->edi < (int32_t)0xFFFFFFFCu) goto label_00042EB1;
    if ((int32_t)cpu->edi < (int32_t)4u) goto label_00042EBD;
    label_00042EB1:
    if (cpu->esi == 0u) goto label_00042EEA;
    if (cpu->edi < cpu->esi) goto label_00042EBD;
    if (cpu->edi <= cpu->ebx) goto label_00042EEA;
    label_00042EBD:
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442EC7u)); sfera_sub_00434AF0(cpu, LIFT_CODE_TOKEN_VA(0x442EC7u));
    ++cpu->ebx;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442EDFu)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x442EDFu));
    cpu->esp += 0x18u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00042EEA:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00042F5B;
    cpu->ebx = g_sfera_mbc_runtime->process_memory_base;
    cpu->esi = cpu->ebx + cpu->edi;
    cpu->ecx = cpu->esi;
    cpu->eax = cpu->ecx + 1u;
    label_00042F01:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    ++cpu->ecx;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00042F01;
    cpu->ecx -= cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp);
    cpu->edx = cpu->ecx + 1u;
    cpu->eax += cpu->ebx;
    label_00042F12:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    *(uint8_t*)(cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->esi;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00042F12;
    if ((int32_t)cpu->edi < (int32_t)0xFFFFFFFCu) goto label_00042F26;
    if ((int32_t)cpu->edi < (int32_t)4u) goto label_00042F3C;
    label_00042F26:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->eax == 0u) goto label_00042F47;
    if (cpu->edi < cpu->eax) goto label_00042F3C;
    cpu->eax = cpu->edx + cpu->edi + 0xFFFFFFFFu;
    if (cpu->eax <= *(uint32_t*)(cpu->esp + 0x18u)) goto label_00042F47;
    label_00042F3C:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442F45u)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_VA(0x442F45u));
    goto label_00042F4D;
    label_00042F47:
    cpu->edi += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    label_00042F4D:
    cpu->edx = 1u;
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x42F5Bu)); sfera_sub_0043AF30(cpu, LIFT_CODE_TOKEN_RVA(0x42F5Bu));
    label_00042F5B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

} // namespace lifted
