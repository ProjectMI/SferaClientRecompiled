#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>

typedef struct SferaMbInterObjectProfile {
    uint32_t factory_kind;
    uint8_t property_274;
    uint8_t property_275;
    uint8_t property_276;
    uint8_t property_277;
} SferaMbInterObjectProfile;

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

LIFT_ENTRY void LIFT_CDECL sfera_sub_004398D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4398D0u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = g_sfera_mbc_runtime->argument_count;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = (int8_t)(lift_load8(cpu->eax));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    ++cpu->eax;
    cpu->edi = 0u;
    cpu->esi = 0u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(cpu->edi)) goto label_00039938;
    cpu->edx = (uint32_t)(cpu->ecx + cpu->ebp);
    cpu->edx = 0u - (uint64_t)(cpu->edx);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    cpu->edx = cpu->ebp;
    cpu->edx = 0u - (uint64_t)(cpu->edx);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_00039930;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Wrong number of parameters (must be %d, present %d)"); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->text_buffer[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x439912u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x439918u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->text_buffer[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x439925u); lift_push32(cpu, r); sfera_sub_004385D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = g_sfera_mbc_runtime->argument_count;
    label_00039930: cpu->eip = LIFT_CODE_TOKEN_VA(0x439930u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->ebp = cpu->ecx;
    goto label_00039975;
    label_00039938: cpu->eip = LIFT_CODE_TOKEN_VA(0x439938u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00039975;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Wrong number of parameters (must be %d, present %d)"); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->text_buffer[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x439948u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43994Eu);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->text_buffer[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43995Bu); lift_push32(cpu, r); sfera_sub_004385D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00039970;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebp = v; }
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->ebp = cpu->eax;
    label_00039970: cpu->eip = LIFT_CODE_TOKEN_VA(0x439970u);
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    label_00039975: cpu->eip = LIFT_CODE_TOKEN_VA(0x439975u);
    cpu->ebx = g_sfera_mbc_runtime->argument_cursor;
    cpu->ebx = lift_shift_left(cpu, cpu->ebx, (uint32_t)(5u), 32u);
    cpu->ebx += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    if ((int32_t)(uint32_t)(cpu->ebp) <= (int32_t)(uint32_t)(cpu->edi)) goto label_00039A51;
    cpu->edi = (uint32_t)(cpu->ebx + 0x14u);
    (void)cpu;
    label_00039990: cpu->eip = LIFT_CODE_TOKEN_VA(0x439990u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebx)) & 0xFFu);
    ++cpu->eax;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->esi = lift_load32(cpu->eax);
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    cpu->eax += 4u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x10u)) goto label_000399C5;
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(0x20u)) goto label_000399BF;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4399BBu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi, cpu->eax);
    goto label_00039A37;
    label_000399BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4399BFu);
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->esi, cpu->eax);
    goto label_00039A37;
    label_000399C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4399C5u);
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x20u)) goto label_000399DA;
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)((cpu->ecx & 0xFFu))) goto label_000399D4;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00039A37;
    label_000399D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4399D4u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edi)))));
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00039A37;
    label_000399DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4399DAu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000399FE;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000399E8;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi)) & 0xFFu);
    lift_store8(cpu->esi, cpu->ecx & 0xFFu);
    goto label_00039A37;
    label_000399E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4399E8u);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(0x20u)) goto label_000399F8;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4399F4u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi, cpu->eax & 0xFFu);
    goto label_00039A37;
    label_000399F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4399F8u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi)) & 0xFFu);
    lift_store8(cpu->esi, cpu->edx & 0xFFu);
    goto label_00039A37;
    label_000399FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4399FEu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(0x20u)) goto label_00039A13;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x439A0Au); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi, cpu->eax);
    cpu->eax = 0u;
    lift_store32(cpu->esi + 4u, cpu->eax);
    goto label_00039A34;
    label_00039A13: cpu->eip = LIFT_CODE_TOKEN_VA(0x439A13u);
    if ((uint8_t)((cpu->edx & 0xFFu)) == (uint8_t)(0x10u)) goto label_00039A1C;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00039A27;
    label_00039A1C: cpu->eip = LIFT_CODE_TOKEN_VA(0x439A1Cu);
    cpu->eax = lift_load32(cpu->edi);
    lift_store32(cpu->esi, cpu->eax);
    cpu->eax = 0u;
    lift_store32(cpu->esi + 4u, cpu->eax);
    goto label_00039A34;
    label_00039A27: cpu->eip = LIFT_CODE_TOKEN_VA(0x439A27u);
    cpu->ecx = lift_load32(cpu->edi);
    lift_store32(cpu->esi, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->esi + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 8u);
    label_00039A34: cpu->eip = LIFT_CODE_TOKEN_VA(0x439A34u);
    lift_store32(cpu->esi + 8u, cpu->eax);
    label_00039A37: cpu->eip = LIFT_CODE_TOKEN_VA(0x439A37u);
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    --cpu->ebp;
    cpu->ebx += 0x20u;
    cpu->edi += 0x20u;
    if ((int32_t)(uint32_t)(cpu->ebp) > 0) goto label_00039990;
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->edi = 0u;
    label_00039A51: cpu->eip = LIFT_CODE_TOKEN_VA(0x439A51u);
    lift_x87_push(cpu, 0.0);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00039B7E;
    cpu->ebx = (uint32_t)(cpu->esi + 0xFFFFFFFCu);
    cpu->ebx = lift_shift_right(cpu, cpu->ebx, (uint32_t)(2u), 32u);
    ++cpu->ebx;
    cpu->ecx = cpu->ebx;
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->ecx) * 4u));
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    label_00039A6E: cpu->eip = LIFT_CODE_TOKEN_VA(0x439A6Eu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->ecx += g_sfera_mbc_runtime->process_memory_base;
    cpu->eax += 4u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(0x10u)) goto label_00039A8F;
    lift_store32(cpu->ecx, cpu->edi);
    goto label_00039AA8;
    label_00039A8F: cpu->eip = LIFT_CODE_TOKEN_VA(0x439A8Fu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(0x20u)) goto label_00039A98;
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u));
    goto label_00039AA8;
    label_00039A98: cpu->eip = LIFT_CODE_TOKEN_VA(0x439A98u);
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00039AA0;
    lift_store8(cpu->ecx, cpu->edx & 0xFFu);
    goto label_00039AA8;
    label_00039AA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x439AA0u);
    lift_store32(cpu->ecx, cpu->edi);
    lift_store32(cpu->ecx + 4u, cpu->edi);
    lift_store32(cpu->ecx + 8u, cpu->edi);
    label_00039AA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x439AA8u);
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += 4u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(0x10u)) goto label_00039AD1;
    lift_store32(cpu->eax, cpu->edi);
    goto label_00039AEA;
    label_00039AD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x439AD1u);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(0x20u)) goto label_00039ADA;
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u));
    goto label_00039AEA;
    label_00039ADA: cpu->eip = LIFT_CODE_TOKEN_VA(0x439ADAu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00039AE2;
    lift_store8(cpu->eax, cpu->edx & 0xFFu);
    goto label_00039AEA;
    label_00039AE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x439AE2u);
    lift_store32(cpu->eax, cpu->edi);
    lift_store32(cpu->eax + 4u, cpu->edi);
    lift_store32(cpu->eax + 8u, cpu->edi);
    label_00039AEA: cpu->eip = LIFT_CODE_TOKEN_VA(0x439AEAu);
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += 4u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(0x10u)) goto label_00039B13;
    lift_store32(cpu->eax, cpu->edi);
    goto label_00039B2C;
    label_00039B13: cpu->eip = LIFT_CODE_TOKEN_VA(0x439B13u);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(0x20u)) goto label_00039B1C;
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u));
    goto label_00039B2C;
    label_00039B1C: cpu->eip = LIFT_CODE_TOKEN_VA(0x439B1Cu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00039B24;
    lift_store8(cpu->eax, cpu->edx & 0xFFu);
    goto label_00039B2C;
    label_00039B24: cpu->eip = LIFT_CODE_TOKEN_VA(0x439B24u);
    lift_store32(cpu->eax, cpu->edi);
    lift_store32(cpu->eax + 4u, cpu->edi);
    lift_store32(cpu->eax + 8u, cpu->edi);
    label_00039B2C: cpu->eip = LIFT_CODE_TOKEN_VA(0x439B2Cu);
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += 4u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(0x10u)) goto label_00039B55;
    lift_store32(cpu->eax, cpu->edi);
    goto label_00039B6E;
    label_00039B55: cpu->eip = LIFT_CODE_TOKEN_VA(0x439B55u);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(0x20u)) goto label_00039B5E;
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u));
    goto label_00039B6E;
    label_00039B5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x439B5Eu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00039B66;
    lift_store8(cpu->eax, cpu->edx & 0xFFu);
    goto label_00039B6E;
    label_00039B66: cpu->eip = LIFT_CODE_TOKEN_VA(0x439B66u);
    lift_store32(cpu->eax, cpu->edi);
    lift_store32(cpu->eax + 4u, cpu->edi);
    lift_store32(cpu->eax + 8u, cpu->edi);
    label_00039B6E: cpu->eip = LIFT_CODE_TOKEN_VA(0x439B6Eu);
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00039A6E;
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    label_00039B7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x439B7Eu);
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(cpu->edi)) goto label_00039BC4;
    goto label_00039B89;
    label_00039B84: cpu->eip = LIFT_CODE_TOKEN_VA(0x439B84u);
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    label_00039B89: cpu->eip = LIFT_CODE_TOKEN_VA(0x439B89u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->ecx += g_sfera_mbc_runtime->process_memory_base;
    cpu->eax += 4u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    if ((uint8_t)((cpu->edx & 0xFFu)) == (uint8_t)(0x10u)) goto label_00039BBD;
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(0x20u)) goto label_00039BAF;
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u));
    goto label_00039BBF;
    label_00039BAF: cpu->eip = LIFT_CODE_TOKEN_VA(0x439BAFu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00039BB7;
    lift_store8(cpu->ecx, cpu->edx & 0xFFu);
    goto label_00039BBF;
    label_00039BB7: cpu->eip = LIFT_CODE_TOKEN_VA(0x439BB7u);
    lift_store32(cpu->ecx + 4u, cpu->edi);
    lift_store32(cpu->ecx + 8u, cpu->edi);
    label_00039BBD: cpu->eip = LIFT_CODE_TOKEN_VA(0x439BBDu);
    lift_store32(cpu->ecx, cpu->edi);
    label_00039BBF: cpu->eip = LIFT_CODE_TOKEN_VA(0x439BBFu);
    --cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) > (int32_t)(uint32_t)(cpu->edi)) goto label_00039B84;
    label_00039BC4: cpu->eip = LIFT_CODE_TOKEN_VA(0x439BC4u);
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00439BD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x439BD0u);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = g_sfera_mbc_runtime->call_frame_depth;
    --cpu->ecx;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(g_sfera_mbc_runtime->frame_stack_base[cpu->eax]), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_00039BF5;
    cpu->ecx = (uint32_t)(uintptr_t)"fo31(): stack underflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_00039BF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x439BF5u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    cpu->edx = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x14u)), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    ++cpu->ecx;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    lift_store32(cpu->eax + 0x14u, cpu->edx);
    lift_store32(cpu->eax + 8u, 0xFFFFFFFFu);
    lift_store32(cpu->eax + 0x10u, 1u);
    lift_store32(cpu->eax + 0xCu, 1u);
    lift_store32(cpu->eax, 0x10u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00439C30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x439C30u);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->edx = 0u;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->edx)) goto label_0003A280;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x398u);
    cpu->ecx += ((uint32_t)(uintptr_t)&g_sfera_world_slot_table_runtime.slots[0].object_handle);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebp + 0x10u)), r=(uint64_t)(4u), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003A27F;
    cpu->ecx = lift_load32(cpu->ebp + 0x14u);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(0xFFFFu)) goto label_0003A27F;
    cpu->eax = cpu->ecx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id))) != (uint32_t)(cpu->ecx)) goto label_0003A27F;
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))) < (int32_t)(uint32_t)(cpu->edx)) goto label_0003A27F;
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ebx);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00039CB9;
    cpu->esi = (uint32_t)(cpu->ebp + 0x2Cu);
    cpu->eax = (uint32_t)(cpu->ebp + 0x1BCu);
    lift_store32(cpu->esp + 0x24u, 8u);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    cpu->ebx = (uint32_t)(cpu->ebp + 0x28u);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    goto label_00039D1C;
    label_00039CB9: cpu->eip = LIFT_CODE_TOKEN_VA(0x439CB9u);
    cpu->ebx = (uint32_t)(cpu->ebp + 0x1C0u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x1C4u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x354u);
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->ebx)) != (uint32_t)(cpu->edx)) goto label_00039D1A;
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->esi = lift_load32(cpu->eax + 0x84u);
    cpu->esi += lift_load32(cpu->eax + 0x50u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x439CF0u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 0x358u, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x439CFEu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 0x35Cu, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x439D0Cu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->ebp + 0x360u, cpu->eax);
    cpu->edx = 0u;
    goto label_00039D1C;
    label_00039D1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x439D1Au);
    cpu->esi = cpu->ecx;
    label_00039D1C: cpu->eip = LIFT_CODE_TOKEN_VA(0x439D1Cu);
    lift_push32(cpu, 0x200u); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->shared_buffer[0]);
    g_sfera_mbc_runtime->shared_buffer_size = (uint32_t)(cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x439D2Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x439D32u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0x258240u); lift_push32(cpu, 7u); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    ++cpu->edi;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->shared_buffer_size;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->shared_buffer[0];
    lift_store32(cpu->esp + 0x40u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x439D57u); lift_push32(cpu, r); sfera_sub_004013D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->send_field_count) <= (int32_t)(uint32_t)(cpu->eax)) goto label_0003A047;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00039D70: cpu->eip = LIFT_CODE_TOKEN_VA(0x439D70u);
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->shared_buffer_size), r=(uint64_t)(0x1000u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_x87_push(cpu, 0.0);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0003A02D;
    cpu->esi = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.send_field_data[0]));
    cpu->eax = (int8_t)(lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->send_field_width[0])));
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(0x20u)) goto label_00039DAD;
    lift_push32(cpu, 0x258240u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    goto label_00039FDA;
    label_00039DAD: cpu->eip = LIFT_CODE_TOKEN_VA(0x439DADu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x6Cu)) goto label_00039E36;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), -1000.0);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00039DD8;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 1000.0);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00039DE0;
    label_00039DD8: cpu->eip = LIFT_CODE_TOKEN_VA(0x439DD8u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00039E04;
    label_00039DE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x439DE0u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00039E02;
    label_00039DE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x439DE9u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (6.2831854820251465));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esp + 0x30u)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00039DE9;
    label_00039E02: cpu->eip = LIFT_CODE_TOKEN_VA(0x439E02u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00039E04: cpu->eip = LIFT_CODE_TOKEN_VA(0x439E04u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (40.7436637878418));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x439E1Bu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x258240u);
    cpu->eax &= 0xFFu;
    lift_push32(cpu, 8u);
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    goto label_00039FD9;
    label_00039E36: cpu->eip = LIFT_CODE_TOKEN_VA(0x439E36u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x69u)) goto label_00039E6C;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 0x358u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x439E50u); lift_push32(cpu, r); sfera_sub_00437BF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00039ED3;
    lift_push32(cpu, 0x258240u); lift_push32(cpu, 0xCu); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    goto label_00039FDA;
    label_00039E6C: cpu->eip = LIFT_CODE_TOKEN_VA(0x439E6Cu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x6Au)) goto label_00039EA0;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 0x35Cu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x439E84u); lift_push32(cpu, r); sfera_sub_00437BF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00039ED3;
    lift_push32(cpu, 0x258240u); lift_push32(cpu, 0xCu); lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    goto label_00039FDA;
    label_00039EA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x439EA0u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x6Bu)) goto label_00039EE0;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebp + 0x360u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x439EB8u); lift_push32(cpu, r); sfera_sub_00437BF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00039ED3;
    lift_push32(cpu, 0x258240u); lift_push32(cpu, 0xCu); lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    goto label_00039FD9;
    label_00039ED3: cpu->eip = LIFT_CODE_TOKEN_VA(0x439ED3u);
    lift_store32(cpu->esp + 0x18u, 1u);
    goto label_00039FE9;
    label_00039EE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x439EE0u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x67u)) goto label_00039FE9;
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->edi)) goto label_00039EFF;
    cpu->esi = 0u - (uint64_t)(cpu->esi);
    lift_store32(cpu->esp + 0x30u, 1u);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    goto label_00039F03;
    label_00039EFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x439EFFu);
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    label_00039F03: cpu->eip = LIFT_CODE_TOKEN_VA(0x439F03u);
    lift_push32(cpu, 0x258240u); lift_push32(cpu, 1u); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->shared_buffer_size;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->shared_buffer[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x439F1Fu); lift_push32(cpu, r); sfera_sub_004013D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x258240u); lift_push32(cpu, 2u); lift_push32(cpu, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(8u)) goto label_00039F50;
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->shared_buffer_size;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->shared_buffer[0];
    lift_store32(cpu->esp + 0x40u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x439F44u); lift_push32(cpu, r); sfera_sub_004013D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x258240u); lift_push32(cpu, 3u);
    goto label_00039FD4;
    label_00039F50: cpu->eip = LIFT_CODE_TOKEN_VA(0x439F50u);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(0x80u)) goto label_00039F83;
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->shared_buffer_size;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->shared_buffer[0];
    lift_store32(cpu->esp + 0x40u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x439F74u); lift_push32(cpu, r); sfera_sub_004013D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x258240u); lift_push32(cpu, 7u); lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    goto label_00039FDA;
    label_00039F83: cpu->eip = LIFT_CODE_TOKEN_VA(0x439F83u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->shared_buffer[0];
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(0x4000u)) goto label_00039FB6;
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->shared_buffer_size;
    lift_store32(cpu->esp + 0x40u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x439FA7u); lift_push32(cpu, r); sfera_sub_004013D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x258240u); lift_push32(cpu, 0xEu); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    goto label_00039FDA;
    label_00039FB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x439FB6u);
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->shared_buffer_size;
    lift_store32(cpu->esp + 0x40u, 3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x439FCDu); lift_push32(cpu, r); sfera_sub_004013D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x258240u); lift_push32(cpu, 0x1Fu);
    label_00039FD4: cpu->eip = LIFT_CODE_TOKEN_VA(0x439FD4u);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    label_00039FD9: cpu->eip = LIFT_CODE_TOKEN_VA(0x439FD9u);
    lift_push32(cpu, cpu->eax);
    label_00039FDA: cpu->eip = LIFT_CODE_TOKEN_VA(0x439FDAu);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->shared_buffer_size;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->shared_buffer[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x39FE9u); lift_push32(cpu, r); sfera_sub_004013D0(cpu,r); if (cpu->eip != r) return; }
    label_00039FE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x439FE9u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_mbc_runtime->send_field_count)) goto label_00039D70;
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) == (uint32_t)(0u)) goto label_0003A043;
    lift_push32(cpu, 0x200u); lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->shared_buffer[0]);
    g_sfera_mbc_runtime->shared_buffer_size = (uint32_t)(0u);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x43A01Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43A020u);
    cpu->esp += 0xCu;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 4u, stop_address); return;
    label_0003A02D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A02Du);
    cpu->ecx = (uint32_t)(uintptr_t)"Too long data for region";
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A039u); lift_push32(cpu, r); sfera_sub_004385D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 4u, stop_address); return;
    label_0003A043: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A043u);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    label_0003A047: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A047u);
    cpu->eax = lift_load32(cpu->ebx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0003A0DF;
    cpu->ecx = g_sfera_mbc_runtime->shared_buffer_size;
    cpu->edx = (uint32_t)(cpu->eax + cpu->ecx + 0x25u);
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(0x640u)) goto label_0003A1D7;
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(7u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A07Au); lift_push32(cpu, r); sfera_sub_00432790(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, 0x190u); lift_push32(cpu, 0u);
    lift_store32(cpu->eax, 0xFFFFFFFFu);
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->ebx, 0u);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x43A092u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43A097u);
    cpu->esp += 0xCu;
    if ((uint32_t)(lift_load32(cpu->esp + 0x28u)) != (uint32_t)(0u)) goto label_0003A0DF;
    cpu->edi = g_sfera_mbc_runtime->active_process;
    cpu->esi = lift_load32(cpu->edi + 0x84u);
    cpu->esi += lift_load32(cpu->edi + 0x50u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A0B7u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 0x358u, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A0C5u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 0x35Cu, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A0D3u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->ebp + 0x360u, cpu->eax);
    goto label_0003A0E5;
    label_0003A0DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A0DFu);
    cpu->edi = g_sfera_mbc_runtime->active_process;
    label_0003A0E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A0E5u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x28u)) != (uint32_t)(0u)) goto label_0003A189;
    if ((uint8_t)((lift_load8(cpu->edi + 0x94u)) & (2u)) != 0u) goto label_0003A189;
    lift_push32(cpu, 0x190u); lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x40u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A11Cu); lift_push32(cpu, r); sfera_sub_004013D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ebp + 0x358u);
    lift_push32(cpu, 0x190u); lift_push32(cpu, 0x10u);
    cpu->edx += 0x8000u;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    lift_store32(cpu->esp + 0x3Cu, cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A143u); lift_push32(cpu, r); sfera_sub_004013D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0x35Cu);
    lift_push32(cpu, 0x190u); lift_push32(cpu, 0xDu);
    cpu->ecx += 0x4B0u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A16Au); lift_push32(cpu, r); sfera_sub_004013D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0x360u);
    lift_push32(cpu, 0x190u); lift_push32(cpu, 0x10u);
    cpu->eax += 0x8000u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_push32(cpu, cpu->ecx);
    goto label_0003A19F;
    label_0003A189: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A189u);
    lift_push32(cpu, 0x190u); lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_store32(cpu->esp + 0x3Cu, 0u);
    lift_push32(cpu, cpu->edx);
    label_0003A19F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A19Fu);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A1A8u); lift_push32(cpu, r); sfera_sub_004013D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_recovered_static_runtime.simulation_tick;
    lift_push32(cpu, 0x190u); lift_push32(cpu, 0xFu); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x40u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A1CBu); lift_push32(cpu, r); sfera_sub_004013D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->edi, 0xFFFFFFFFu);
    goto label_0003A1DB;
    label_0003A1D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A1D7u);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    label_0003A1DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A1DBu);
    cpu->eax = lift_load32(cpu->edi);
    cpu->edx = g_sfera_mbc_runtime->active_process;
    if ((uint32_t)(lift_load32(cpu->edx + 0xB4u)) == (uint32_t)(cpu->eax)) goto label_0003A262;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_0003A20F;
    lift_push32(cpu, 0x190u); lift_push32(cpu, 7u); lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x40u, 0x3Fu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3A20Fu); lift_push32(cpu, r); sfera_sub_004013D0(cpu,r); if (cpu->eip != r) return; }
    label_0003A20F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A20Fu);
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    lift_push32(cpu, 0x190u); lift_push32(cpu, 0x12u);
    cpu->ecx += 0xB4u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A22Eu); lift_push32(cpu, r); sfera_sub_004013D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_mbc_runtime->active_process;
    lift_push32(cpu, 0x190u); lift_push32(cpu, 0xCu);
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    cpu->eax += 0x44u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x40u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A254u); lift_push32(cpu, r); sfera_sub_004013D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    cpu->edx = lift_load32(cpu->ecx + 0xB4u);
    lift_store32(cpu->edi, cpu->edx);
    label_0003A262: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A262u);
    cpu->eax = g_sfera_mbc_runtime->shared_buffer_size;
    lift_push32(cpu, 0x190u); lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->shared_buffer[0]);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A27Du); lift_push32(cpu, r); sfera_sub_004013D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0003A27F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A27Fu);
    cpu->ebp = lift_pop32(cpu);
    label_0003A280: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A280u);
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043A290(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43A290u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A29Eu); lift_push32(cpu, r); sfera_sub_004380A0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0xA8u);
    lift_store32(cpu->esi + 0xA8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0xACu);
    lift_store32(cpu->esi + 0xACu, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0xB0u);
    lift_store32(cpu->esi + 0xB0u, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0xB4u);
    lift_store32(cpu->esi + 0xB4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0xB8u);
    lift_store32(cpu->esi + 0xB8u, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esi + 0xBCu);
    cpu->edi -= cpu->esi;
    cpu->ecx = 0x100u;
    label_0003A2E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A2E7u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + cpu->eax)) & 0xFFu);
    lift_store8(cpu->eax, cpu->edx & 0xFFu);
    ++cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003A2E7;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043A300(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43A300u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->edi + 0xC8u)) == (uint8_t)(0u)) goto label_0003A31A;
    lift_push32(cpu, (uint32_t)(uintptr_t)"~~~~~ItemList~~~FIND FIRST ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A317u); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0003A31A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A31Au);
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->edi + 0xACu)) <= (int32_t)(uint32_t)(cpu->esi)) goto label_0003A343;
    cpu->ecx = lift_load32(cpu->edi + 0xD0u);
    cpu->eax = (uint32_t)(cpu->ecx + 0x9Au);
    label_0003A330: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A330u);
    if ((uint8_t)(lift_load8(cpu->eax)) == (uint8_t)(1u)) goto label_0003A368;
    ++cpu->esi;
    cpu->eax += 0x1BCu;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->edi + 0xACu))) goto label_0003A330;
    label_0003A343: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A343u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0xC8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->edi + 0xC4u, 0xFFFFFFFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003A363;
    lift_push32(cpu, (uint32_t)(uintptr_t)" FindFirstItem = 'ERROR'\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A360u); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0003A363: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A363u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003A368: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A368u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0xC8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->edi + 0xC4u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003A3B3;
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFF9u)) goto label_0003A383;
    lift_push32(cpu, (uint32_t)(uintptr_t)"~~~~~ItemList~~~FIND FIRST ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    goto label_0003A3AB;
    label_0003A383: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A383u);
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0003A3A1;
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1BCu);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->ecx + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)" FindFirstItem 'OK' = ''%s''\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A39Eu); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_0003A3A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A3A1u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_0003A3B3;
    lift_push32(cpu, (uint32_t)(uintptr_t)" FindFirstItem = 'ERROR'\n");
    label_0003A3AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A3ABu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A3B0u); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0003A3B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A3B3u);
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1BCu);
    cpu->eax += lift_load32(cpu->edi + 0xD0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043A3D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43A3D0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0xC8u)) == (uint8_t)(0u)) goto label_0003A3E9;
    lift_push32(cpu, (uint32_t)(uintptr_t)"~~~~~ItemList~~~FIND NEXT ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A3E6u); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0003A3E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A3E9u);
    cpu->eax = lift_load32(cpu->esi + 0xC4u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0003A425;
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0xACu))) goto label_0003A425;
    cpu->edx = lift_load32(cpu->esi + 0xD0u);
    cpu->ecx = cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x1BCu);
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->edx + 0x9Au);
    label_0003A411: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A411u);
    if ((uint8_t)(lift_load8(cpu->ecx)) == (uint8_t)(1u)) goto label_0003A43F;
    ++cpu->eax;
    cpu->ecx += 0x1BCu;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0xACu))) goto label_0003A411;
    label_0003A425: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A425u);
    if ((uint8_t)(lift_load8(cpu->esi + 0xC8u)) == (uint8_t)(0u)) goto label_0003A43B;
    lift_push32(cpu, (uint32_t)(uintptr_t)" FindNextItem = 'ERROR'\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A438u); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0003A43B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A43Bu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003A43F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A43Fu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0xC8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esi + 0xC4u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003A456;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3A456u); lift_push32(cpu, r); sfera_sub_00438160(cpu,r); if (cpu->eip != r) return; }
    label_0003A456: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A456u);
    cpu->eax = lift_load32(cpu->esi + 0xC4u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1BCu);
    cpu->eax += lift_load32(cpu->esi + 0xD0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043A470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43A470u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = cpu->ecx;
    std::construct_at(reinterpret_cast<CItem*>(cpu->eax));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = (uint32_t)(cpu->edx + 4u);
    cpu->edi = (uint32_t)(cpu->eax + 4u);
    cpu->ecx = 0x25u;
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx + 0x9Au)) & 0xFFu);
    lift_store8(cpu->eax + 0x9Au, cpu->ecx & 0xFFu);
    cpu->esi = (uint32_t)(cpu->edx + 0xBCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x9Cu));
    cpu->edi = (uint32_t)(cpu->eax + 0xBCu);
    lift_store_f32(cpu->eax + 0x9Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0xA0u));
    lift_store_f32(cpu->eax + 0xA0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0xA4u));
    std::construct_at(reinterpret_cast<CCommonItem*>(cpu->eax));
    lift_store_f32(cpu->eax + 0xA4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->edx + 0xA8u);
    lift_store32(cpu->eax + 0xA8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx + 0xACu);
    lift_store32(cpu->eax + 0xACu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx + 0xB0u);
    lift_store32(cpu->eax + 0xB0u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx + 0xB4u);
    lift_store32(cpu->eax + 0xB4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx + 0xB8u);
    lift_store32(cpu->eax + 0xB8u, cpu->ecx);
    cpu->ecx = 0x40u;
    lift_movs32(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043A520(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43A520u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_0003A55B;
    lift_push32(cpu, cpu->ebp);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"HashMap::init: wrong _startSize=%d"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\HashMap.h");
    lift_store32(cpu->esp + 0x1Cu, 0x9Au);
    lift_store32(cpu->esp + 0x20u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A558u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_0003A55B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A55Bu);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(1u)) goto label_0003A590;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, (uintptr_t)"HashMap::init: wrong _maxKeyLen=%d"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x1Cu, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\HashMap.h");
    lift_store32(cpu->esp + 0x20u, 0x9Bu);
    lift_store32(cpu->esp + 0x24u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A58Du); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_0003A590: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A590u);
    cpu->edi = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx = 1u;
    cpu->eax = 0u;
    label_0003A5A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A5A0u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0003A5AC;
    ++cpu->eax;
    cpu->ecx += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x20u)) goto label_0003A5A0;
    label_0003A5AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A5ACu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x20u)) goto label_0003A5DB;
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"HashMap::init:  hashTabSize must be power of 2"); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x18u, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\HashMap.h");
    lift_store32(cpu->esp + 0x1Cu, 0xA2u);
    lift_store32(cpu->esp + 0x20u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A5D8u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_0003A5DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A5DBu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A5E0u); lift_push32(cpu, r); sfera_sub_004ED5C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->ecx = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_0003A5EF;
    lift_store32(cpu->esi + 0x30u, cpu->eax);
    goto label_0003A5F6;
    label_0003A5EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A5EFu);
    lift_store32(cpu->esi + 0x30u, (uintptr_t)&g_sfera_std_allocator);
    label_0003A5F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A5F6u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x24u)) & 0xFFu);
    cpu->eax = 0xFFFFu;
    lift_store16(cpu->esi + 0x1Cu, cpu->eax & 0xFFFFu);
    lift_store8(cpu->esi + 0x1Eu, cpu->edx & 0xFFu);
    cpu->edx = 0u;
    cpu->eax = (uint32_t)(cpu->ebx + 0xBu);
    lift_store32(cpu->esi, cpu->ebx);
    lift_store32(cpu->esi + 0x20u, cpu->edi);
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_store16(cpu->esi + 0x14u, cpu->edx & 0xFFFFu);
    lift_store32(cpu->esi + 0x24u, cpu->ecx);
    lift_store32(cpu->esi + 0x2Cu, cpu->ecx);
    lift_store32(cpu->esi + 0x28u, cpu->ecx);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003A629;
    lift_store32(cpu->esi + 0xCu, cpu->ebp);
    goto label_0003A643;
    label_0003A629: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A629u);
    cpu->eax = (uint32_t)(cpu->edi + cpu->edi);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, lift_load32(cpu->esi + 8u), 32u, 0u);
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(0x14u)) goto label_0003A643;
    lift_store32(cpu->esi + 0xCu, 0x14u);
    label_0003A643: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A643u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(lift_load32(cpu->esi + 0xCu));
    cpu->ecx = lift_load32(cpu->esi + 0x30u);
    cpu->ebp = 0u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx);
    reinterpret_cast<StdAllocator*>(cpu->ecx)->allocate(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43A657u);
    cpu->ecx = lift_load32(cpu->esi + 0x30u);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    reinterpret_cast<StdAllocator*>(cpu->ecx)->allocate(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43A665u);
    cpu->ecx = lift_load32(cpu->esi + 0x30u);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_push32(cpu, cpu->ebp);
    cpu->edi += cpu->edi;
    lift_push32(cpu, cpu->edi);
    reinterpret_cast<StdAllocator*>(cpu->ecx)->allocate(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43A675u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x43A67Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43A684u);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->esp += 0xCu;
    --cpu->ecx;
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_0003A6B9;
    label_0003A692: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A692u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->edi = lift_load32(cpu->esi + 4u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    lift_store16(cpu->ecx + cpu->edi + 8u, cpu->edx & 0xFFFFu);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->eax);
    lift_store32(cpu->edx + cpu->ecx + 4u, cpu->ebp);
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    ++cpu->eax;
    --cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edx)) goto label_0003A692;
    label_0003A6B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A6B9u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    cpu->edi = (cpu->edi & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esi + 0x1Cu)) & 0xFFFFu);
    lift_store16(cpu->ecx + cpu->edx + 8u, cpu->edi & 0xFFFFu);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ecx + cpu->edx + 4u, cpu->ebp);
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043A6F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43A6F0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, (uint32_t)(uintptr_t)"\n-----BaseManager---ALL LISTS----------------------------\n");
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A705u); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = 0u;
    cpu->esp += 4u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->edi + 0xB0u)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0003A818;
    lift_store32(cpu->esp + 8u, cpu->ebp);
    if ((int32_t)(uint32_t)(lift_load32(cpu->edi + 0xACu)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0003A825;
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    lift_push32(cpu, cpu->esi);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0003A730: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A730u);
    cpu->eax = lift_load32(cpu->edi + 0xD0u);
    if ((uint8_t)(lift_load8(cpu->eax + cpu->ebp + 0x9Au)) != (uint8_t)(1u)) goto label_0003A7F1;
    cpu->edx = lift_load32(cpu->eax + cpu->ebp + 0xB0u);
    cpu->ecx = lift_load32(cpu->eax + cpu->ebp + 0xACu);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0xA8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->eax += 4u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"List Name = ''%s'', min = %d, curmax = %d, cur = %d\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A76Bu); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->edi + 0xD0u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"~~~~~ItemList~~~ALL ITEMS~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    cpu->esi += cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A77Du); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0xB0u)) <= (int32_t)(uint32_t)(0u)) goto label_0003A7E4;
    cpu->ebx = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0xACu)) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0003A7F1;
    cpu->ebp = 0u;
    label_0003A7A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A7A0u);
    cpu->edi = lift_load32(cpu->esi + 0xD0u);
    cpu->edi += cpu->ebp;
    if ((uint8_t)(lift_load8(cpu->edi + 0x9Au)) != (uint8_t)(1u)) goto label_0003A7CB;
    cpu->ecx = (uint32_t)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)" ItemName = ''%s''\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A7BFu); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    cpu->ecx = cpu->edi;
    reinterpret_cast<CItem*>(cpu->ecx)->releaseItem(cpu);
    label_0003A7CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A7CBu);
    ++cpu->ebx;
    cpu->ebp += 0x1BCu;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0xACu))) goto label_0003A7A0;
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    goto label_0003A7F1;
    label_0003A7E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A7E4u);
    lift_push32(cpu, (uint32_t)(uintptr_t)". . . . . . . \n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A7EEu); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0003A7F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A7F1u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    ++cpu->eax;
    cpu->ebp += 0xD4u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->edi + 0xACu))) goto label_0003A730;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
    label_0003A818: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A818u);
    lift_push32(cpu, (uint32_t)(uintptr_t)". . . . . . . . . \n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A822u); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0003A825: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A825u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043A830(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43A830u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->esi + 0xA8u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, 0x96u);
    lift_store32(cpu->esi + 0xB4u, cpu->ecx);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 4u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ecx);
    lift_store8(cpu->esi + 0xC8u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0xACu, 0x1Eu);
    lift_store32(cpu->esi + 0xB0u, cpu->ebx);
    lift_store32(cpu->esi + 0xB8u, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x43A898u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43A89Eu);
    cpu->esp += 0xCu;
    cpu->edx = 0x1A4u;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\lists\\ItemList.h";
    lift_store8(cpu->esi + 0x99u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A8B6u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A8BDu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_0003A8E3;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x100u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, 0x96u);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A8E1u); lift_push32(cpu, r); sfera_sub_0043A520(cpu,r); if (cpu->eip != r) return; }
    goto label_0003A8E5;
    label_0003A8E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A8E3u);
    cpu->eax = 0u;
    label_0003A8E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A8E5u);
    cpu->ecx |= 0xFFFFFFFFu;
    lift_store32(cpu->esi + 0xCCu, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_store32(cpu->eax + 0x28u, cpu->ecx);
    lift_push32(cpu, 0x1ABu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\lists\\ItemList.h";
    cpu->ecx = 0x3408u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A909u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xD0u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_0003A94B;
    if ((uint8_t)(lift_load8(cpu->esi + 0xC8u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0003A932;
    lift_push32(cpu, (uint32_t)(uintptr_t)"~~~~~ItemList~~~INITIALIZE~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A925u); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)" Initialize = 'ERROR'\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A92Fu); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_0003A932: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A932u);
    cpu->eax = 0xFFFFFFF2u;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 20u, stop_address); return;
    label_0003A94B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A94Bu);
    lift_push32(cpu, 0x3408u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x43A952u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43A957u);
    cpu->esp += 0xCu;
    if ((uint8_t)(lift_load8(cpu->esi + 0xC8u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0003A979;
    lift_push32(cpu, (uint32_t)(uintptr_t)"~~~~~ItemList~~~INITIALIZE~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A96Cu); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"Initialize complete\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A976u); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_0003A979: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A979u);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043A990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43A990u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0003A9A1;
    lift_store32(cpu->eax, 0u);
    label_0003A9A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A9A1u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0003A9BA;
    if ((uint8_t)(lift_load8(cpu->esi + 0x1Eu)) != (uint8_t)(0u)) goto label_0003A9BA;
    lift_store8(cpu->esp + 0x10u, 1u);
    goto label_0003A9C3;
    label_0003A9BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A9BAu);
    lift_store8(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0003A9D1;
    label_0003A9C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A9C3u);
    cpu->eax = cpu->edi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0003A9C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A9C8u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0003A9C8;
    cpu->eax -= cpu->edx;
    label_0003A9D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A9D1u);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(lift_load32(cpu->esi))) goto label_0003A9DC;
    label_0003A9D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A9D5u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0003A9DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x43A9DCu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43A9EAu); lift_push32(cpu, r); sfera_sub_00438220(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_0003A9D5;
    cpu->edx = lift_load32(cpu->esi + 0x38u);
    lift_store32(cpu->edx + 4u, 0u);
    cpu->eax = lift_load32(cpu->esi + 0x3Cu);
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esi + 0x40u)) & 0xFFFFu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0003AA0A;
    lift_store16(cpu->eax + 8u, cpu->ecx & 0xFFFFu);
    goto label_0003AA15;
    label_0003AA0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AA0Au);
    cpu->edx = lift_load16(cpu->esi + 0x42u);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_store16(cpu->eax + ((uint32_t)(cpu->edx) * 2u), cpu->ecx & 0xFFFFu);
    label_0003AA15: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AA15u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esi + 0x14u)) & 0xFFFFu);
    cpu->edx = lift_load32(cpu->esi + 0x38u);
    lift_store16(cpu->edx + 8u, cpu->eax & 0xFFFFu);
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esi + 0x34u)) & 0xFFFFu);
    cpu->edi = lift_pop32(cpu);
    lift_store16(cpu->esi + 0x14u, cpu->ecx & 0xFFFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043AA30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43AA30u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_0003AA44;
    lift_store32(cpu->eax, cpu->ebx);
    label_0003AA44: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AA44u);
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(cpu->ebx)) goto label_0003AA5C;
    if ((uint8_t)(lift_load8(cpu->esi + 0x1Eu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0003AA5C;
    lift_store8(cpu->esp + 0x24u, 1u);
    goto label_0003AA64;
    label_0003AA5C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AA5Cu);
    lift_store8(cpu->esp + 0x24u, cpu->ebx & 0xFFu);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(cpu->ebx)) goto label_0003AA7B;
    label_0003AA64: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AA64u);
    cpu->eax = cpu->edi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0003AA70: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AA70u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0003AA70;
    cpu->eax -= cpu->edx;
    cpu->ebp = cpu->eax;
    label_0003AA7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AA7Bu);
    if ((int32_t)(uint32_t)(cpu->ebp) <= (int32_t)(uint32_t)(lift_load32(cpu->esi))) goto label_0003AAB6;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"HashMap::insert: maxKeyLen exceed"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\HashMap.h");
    lift_store32(cpu->esp + 0x1Cu, 0x129u);
    lift_store32(cpu->esp + 0x20u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43AAA6u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_0003AAA9: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AAA9u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
    label_0003AAB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AAB6u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43AAC4u); lift_push32(cpu, r); sfera_sub_00438220(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_0003AAA9;
    cpu->eax = lift_load16(cpu->esi + 0x1Cu);
    if ((uint16_t)(lift_load16(cpu->esi + 0x14u)) != (uint16_t)((cpu->eax & 0xFFFFu))) goto label_0003ABC5;
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_0003AB17;
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"HashMap::insert: more than maxIndexVal elements"); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x18u, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\HashMap.h");
    lift_store32(cpu->esp + 0x1Cu, 0x134u);
    lift_store32(cpu->esp + 0x20u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43AB07u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
    label_0003AB17: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AB17u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edi = cpu->eax;
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(1u), 32u);
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(0xAu)) goto label_0003AB28;
    cpu->edi = 0xAu;
    label_0003AB28: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AB28u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esi + 0xCu)) & 0xFFFFu);
    lift_store32(cpu->esi + 0xCu, (uint64_t)(lift_load32(cpu->esi + 0xCu)) + (uint64_t)(cpu->edi) + (uint64_t)(0u));
    lift_store16(cpu->esi + 0x14u, cpu->eax & 0xFFFFu);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->ecx)) goto label_0003AB43;
    cpu->edx = cpu->ecx;
    cpu->edx -= cpu->eax;
    cpu->edi += cpu->edx;
    lift_store32(cpu->esi + 0xCu, cpu->ecx);
    label_0003AB43: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AB43u);
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(lift_load32(cpu->esi + 8u));
    cpu->ecx = lift_load32(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx);
    reinterpret_cast<StdAllocator*>(cpu->ecx)->reallocate(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43AB5Au);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->edx = (uint32_t)(cpu->edi + 0xFFFFFFFFu);
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0003AB9E;
    label_0003AB70: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AB70u);
    cpu->ecx = lift_load16(cpu->esi + 0x14u);
    cpu->ebx = lift_load32(cpu->esi + 4u);
    cpu->edi = (uint32_t)(cpu->ecx + cpu->eax + 1u);
    cpu->ecx += cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(lift_load32(cpu->esi + 8u));
    lift_store16(cpu->ecx + cpu->ebx + 8u, cpu->edi & 0xFFFFu);
    cpu->ecx = lift_load16(cpu->esi + 0x14u);
    cpu->edi = lift_load32(cpu->esi + 4u);
    cpu->ecx += cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(lift_load32(cpu->esi + 8u));
    cpu->ebx = 0u;
    ++cpu->eax;
    lift_store32(cpu->ecx + cpu->edi + 4u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edx)) goto label_0003AB70;
    label_0003AB9E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AB9Eu);
    cpu->edx = lift_load16(cpu->esi + 0x14u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edi = (cpu->edi & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esi + 0x1Cu)) & 0xFFFFu);
    cpu->edx += cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(lift_load32(cpu->esi + 8u));
    lift_store16(cpu->edx + cpu->ecx + 8u, cpu->edi & 0xFFFFu);
    cpu->edx = lift_load16(cpu->esi + 0x14u);
    cpu->edx += cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(lift_load32(cpu->esi + 8u));
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edx + cpu->eax + 4u, cpu->ebx);
    label_0003ABC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43ABC5u);
    cpu->edi = lift_load16(cpu->esi + 0x14u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(lift_load32(cpu->esi + 8u));
    cpu->edi += lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0xAu);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43ABD9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43ABDEu);
    lift_store8(cpu->edi + cpu->ebp + 0xAu, cpu->ebx & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->edi + 8u)) & 0xFFFFu);
    cpu->eax = lift_load16(cpu->esi + 0x14u);
    lift_store16(cpu->esi + 0x14u, cpu->ecx & 0xFFFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0003ABFD;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->edi, cpu->edx);
    label_0003ABFD: cpu->eip = LIFT_CODE_TOKEN_VA(0x43ABFDu);
    cpu->ecx = lift_load16(cpu->esi + 0x42u);
    cpu->edx = lift_load32(cpu->esi + 0x18u);
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->edx + ((uint32_t)(cpu->ecx) * 2u))) & 0xFFFFu);
    lift_store32(cpu->edi + 4u, cpu->ebp);
    lift_store16(cpu->edi + 8u, cpu->ecx & 0xFFFFu);
    cpu->edx = lift_load16(cpu->esi + 0x42u);
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store16(cpu->ecx + ((uint32_t)(cpu->edx) * 2u), cpu->eax & 0xFFFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043AC30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43AC30u);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = g_sfera_mbc_runtime->call_frame_depth;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(g_sfera_mbc_runtime->frame_stack_base[cpu->ecx]), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0003AC51;
    cpu->ecx = (uint32_t)(uintptr_t)"popint(): stack underflow";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43AC4Eu); lift_push32(cpu, r); sfera_sub_004385D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
    label_0003AC51: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AC51u);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->eax);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint8_t)g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0x10u)) goto label_0003AC81;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x20u)) goto label_0003AC75;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0]));
    sfera_sub_004EE940(cpu, stop_address); return;
    label_0003AC75: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AC75u);
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0003AC81;
    cpu->eax = (int8_t)(((uint8_t)g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0]));
    lift_return(cpu, 0u, stop_address); return;
    label_0003AC81: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AC81u);
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0];
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043AC90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43AC90u);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = g_sfera_mbc_runtime->call_frame_depth;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(g_sfera_mbc_runtime->frame_stack_base[cpu->ecx]), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0003ACC8;
    cpu->ecx = (uint32_t)(uintptr_t)"popsliceref(): stack underflow";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43ACAEu); lift_push32(cpu, r); sfera_sub_004385D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    g_sfera_pop_slice_fallback.base = (uint32_t)(cpu->ecx);
    lift_store32((uintptr_t)&g_sfera_pop_slice_fallback.begin, cpu->ecx);
    lift_store32((uintptr_t)&g_sfera_pop_slice_fallback.end, cpu->ecx);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_pop_slice_fallback;
    lift_return(cpu, 0u, stop_address); return;
    label_0003ACC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x43ACC8u);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->eax);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    if ((uint8_t)((lift_load8(cpu->eax)) & (0xFu)) != 0u) goto label_0003ACE3;
    cpu->ecx = 0u;
    lift_store32(cpu->eax + 0x18u, cpu->ecx);
    lift_store32(cpu->eax + 0x1Cu, cpu->ecx);
    label_0003ACE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x43ACE3u);
    cpu->eax += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043ACF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43ACF0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->argument_cursor;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(g_sfera_mbc_runtime->argument_end), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003AD0D;
    cpu->ecx = (uint32_t)(uintptr_t)"Too few parameters";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43AD09u); lift_push32(cpu, r); sfera_sub_004385D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003AD0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AD0Du);
    cpu->eax = cpu->esi;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint8_t)g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0x10u)) goto label_0003AD4A;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x20u)) goto label_0003AD36;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0]));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43AD2Du); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    ++cpu->esi;
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->esi);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003AD36: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AD36u);
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0003AD4A;
    cpu->eax = (int8_t)(((uint8_t)g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0]));
    ++cpu->esi;
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->esi);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003AD4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AD4Au);
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0];
    ++cpu->esi;
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->esi);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043AD60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43AD60u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->argument_cursor;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(g_sfera_mbc_runtime->argument_end), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003AD7D;
    cpu->ecx = (uint32_t)(uintptr_t)"Too few parameters";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43AD79u); lift_push32(cpu, r); sfera_sub_004385D0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003AD7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AD7Du);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint8_t)g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type)) & 0xFFu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(0x20u)) goto label_0003ADA2;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0]));
    ++cpu->ecx;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003ADA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x43ADA2u);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(0x10u)) goto label_0003ADBC;
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0]))));
    ++cpu->ecx;
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003ADBC: cpu->eip = LIFT_CODE_TOKEN_VA(0x43ADBCu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0003ADDC;
    cpu->eax = (int8_t)(((uint8_t)g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0]));
    lift_store32(cpu->esp, cpu->eax);
    ++cpu->ecx;
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp)))));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003ADDC: cpu->eip = LIFT_CODE_TOKEN_VA(0x43ADDCu);
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0]))));
    ++cpu->ecx;
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043AE00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43AE00u);
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    lift_push32(cpu, cpu->esi);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(g_sfera_mbc_runtime->argument_end), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003AE2E;
    cpu->ecx = (uint32_t)(uintptr_t)"popsliceup(): stack underflow";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43AE18u); lift_push32(cpu, r); sfera_sub_004385D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->esi = 0u;
    cpu->ecx = 0u;
    cpu->edx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->esi);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0003AE2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AE2Eu);
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    cpu->ecx += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    ++cpu->eax;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx)), r=(uint64_t)(0xFu), v=l & r; lift_flags_logic(cpu,v,8u); }
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003AE4C;
    cpu->esi = 0u;
    lift_store32(cpu->ecx + 0x18u, cpu->esi);
    lift_store32(cpu->ecx + 0x1Cu, cpu->esi);
    label_0003AE4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AE4Cu);
    cpu->edx = lift_load32(cpu->ecx + 0x14u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x18u);
    cpu->ecx = lift_load32(cpu->ecx + 0x1Cu);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043AE70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43AE70u);
    cpu->ecx = g_sfera_mbc_runtime->argument_cursor;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(g_sfera_mbc_runtime->argument_end), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003AEA2;
    cpu->ecx = (uint32_t)(uintptr_t)"popsliceupref(): stack underflow";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43AE88u); lift_push32(cpu, r); sfera_sub_004385D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    g_sfera_pop_sliceup_fallback.base = (uint32_t)(cpu->ecx);
    lift_store32((uintptr_t)&g_sfera_pop_sliceup_fallback.begin, cpu->ecx);
    lift_store32((uintptr_t)&g_sfera_pop_sliceup_fallback.end, cpu->ecx);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_pop_sliceup_fallback;
    lift_return(cpu, 0u, stop_address); return;
    label_0003AEA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AEA2u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    ++cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax)), r=(uint64_t)(0xFu), v=l & r; lift_flags_logic(cpu,v,8u); }
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003AEC0;
    cpu->ecx = 0u;
    lift_store32(cpu->eax + 0x18u, cpu->ecx);
    lift_store32(cpu->eax + 0x1Cu, cpu->ecx);
    label_0003AEC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AEC0u);
    cpu->eax += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043AED0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43AED0u);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003AEEB;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43AEE8u); lift_push32(cpu, r); sfera_sub_004385D0(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 4u, stop_address); return;
    label_0003AEEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AEEBu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->edx = 1u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x20u);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->edx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->edx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043AF30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43AF30u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003AF4A;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003AF4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AF4Au);
    cpu->eax = cpu->esi;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(cpu->edx);
    cpu->edx = lift_load32(cpu->ecx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[1] = (uint32_t)(cpu->edx);
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[2] = (uint32_t)(cpu->ecx);
    cpu->ecx = 1u;
    cpu->esi += cpu->ecx;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->esi);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->ecx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043AFA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43AFA0u);
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    g_sfera_mbc_runtime->active_tag = (uint32_t)(cpu->ecx);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003AFBE;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003AFBE: cpu->eip = LIFT_CODE_TOKEN_VA(0x43AFBEu);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(cpu->ecx);
    cpu->ecx = 1u;
    cpu->edx += cpu->ecx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->ecx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043B0B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43B0B0u);
    sfera_sub_0043ACF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043B0C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43B0C0u);
    sfera_sub_0043AD60(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043B0D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43B0D0u);
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003B0E8;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003B0E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B0E8u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(cpu->ecx);
    cpu->ecx = 1u;
    cpu->edx += cpu->ecx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->ecx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043B130(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43B130u);
    cpu->eax = 0u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043B140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43B140u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43B145u); lift_push32(cpu, r); sfera_sub_0043AC30(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0003B151;
    g_sfera_mbc_runtime->instruction_cursor += 4u;
    lift_return(cpu, 0u, stop_address); return;
    label_0003B151: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B151u);
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->eax += lift_load32(cpu->eax);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043B160(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43B160u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43B165u); lift_push32(cpu, r); sfera_sub_0043AC30(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0003B171;
    g_sfera_mbc_runtime->instruction_cursor += 2u;
    lift_return(cpu, 0u, stop_address); return;
    label_0003B171: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B171u);
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = (int16_t)(lift_load16(cpu->eax));
    cpu->eax += cpu->ecx;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043B190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43B190u);
    cpu->esp -= 0xCu;
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = lift_load8(cpu->eax);
    lift_push32(cpu, cpu->ebx);
    ++cpu->eax;
    lift_push32(cpu, cpu->ebp);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load16(cpu->eax);
    cpu->eax += 2u;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43B1B9u); lift_push32(cpu, r); sfera_sub_0043AC30(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax += 4u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax += 4u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax += 4u;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->ebp = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_0003B1F4;
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ebp = cpu->ecx;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    label_0003B1F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B1F4u);
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->ebp)) goto label_0003B1FC;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0003B22A;
    label_0003B1FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B1FCu);
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43B206u); lift_push32(cpu, r); sfera_sub_00434AF0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\nArray boundary error: array size = %d, index = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43B21Cu); lift_push32(cpu, r); sfera_sub_0049B7F0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0003B227;
    cpu->edi = 0u;
    goto label_0003B22A;
    label_0003B227: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B227u);
    cpu->edi = (uint32_t)(cpu->ebp + 0xFFFFFFFFu);
    label_0003B22A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B22Au);
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->edi);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(lift_load32(cpu->esp + 0x14u)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->eax = cpu->edx;
    { uint64_t l=(uint64_t)(cpu->edx), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    cpu->ecx = cpu->esi;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    cpu->edx = (uint32_t)(cpu->edx + cpu->ecx + 0xFFFFFFFFu);
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    lift_store32(cpu->eax + 0x10u, cpu->edx);
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_0003B2F4;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->edx) != 0u) goto label_0003B28D;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (int8_t)(lift_load8(cpu->edx + cpu->ecx));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax + 0x14u, cpu->ecx);
    lift_store32(cpu->eax, 0x10u);
    lift_store32(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
    label_0003B28D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B28Du);
    if ((uint32_t)(cpu->edx) == (uint32_t)(0x10u)) goto label_0003B297;
    if ((uint32_t)(cpu->edx) != (uint32_t)(0x20u)) goto label_0003B2B4;
    label_0003B297: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B297u);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = lift_load32(cpu->esi + cpu->ecx);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax + 0x14u, cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, 4u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
    label_0003B2B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B2B4u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(0x30u)) goto label_0003B2CC;
    cpu->edx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax + 0xCu);
    lift_store32(cpu->eax + 0x14u, cpu->edx);
    lift_store32(cpu->eax + 0x18u, cpu->ecx);
    lift_store32(cpu->eax, 0x30u);
    goto label_0003B305;
    label_0003B2CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B2CCu);
    cpu->ecx += g_sfera_mbc_runtime->process_memory_base;
    cpu->edi = lift_pop32(cpu);
    cpu->esi = lift_load32(cpu->ecx);
    lift_store32(cpu->eax + 0x14u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 0x18u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax + 0x1Cu, cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, 0xCu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
    label_0003B2F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B2F4u);
    cpu->edx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax + 0xCu);
    lift_store32(cpu->eax + 0x14u, cpu->edx);
    lift_store32(cpu->eax + 0x18u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax, cpu->ecx);
    label_0003B305: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B305u);
    cpu->edx = lift_load32(cpu->eax + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax + 0x1Cu, cpu->edx);
    lift_store32(cpu->eax + 4u, 0xCu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043B320(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43B320u);
    cpu->esp -= 8u;
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = lift_load8(cpu->eax);
    lift_push32(cpu, cpu->ebx);
    ++cpu->eax;
    lift_push32(cpu, cpu->ebp);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->ebp = lift_load16(cpu->eax);
    lift_push32(cpu, cpu->esi);
    cpu->eax += 2u;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43B349u); lift_push32(cpu, r); sfera_sub_0043AC90(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43B350u); lift_push32(cpu, r); sfera_sub_0043AC30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx += 4u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->ebx = cpu->eax;
    lift_store8(cpu->esp + 0x13u, 0u);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0003B377;
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->ebx = cpu->eax;
    lift_store8(cpu->esp + 0x13u, 1u);
    label_0003B377: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B377u);
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0003B37F;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0003B3B4;
    label_0003B37F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B37Fu);
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43B389u); lift_push32(cpu, r); sfera_sub_00434AF0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\nArray2 boundary error: array size = %d, index = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43B39Fu); lift_push32(cpu, r); sfera_sub_0049B7F0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    if ((int32_t)(uint32_t)(cpu->edi) < 0) goto label_0003B3B1;
    cpu->eax = (uint32_t)(cpu->ebx + 0xFFFFFFFFu);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0003B3B1;
    cpu->edi = 0u;
    goto label_0003B3B4;
    label_0003B3B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B3B1u);
    cpu->edi = (uint32_t)(cpu->ebx + 0xFFFFFFFFu);
    label_0003B3B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B3B4u);
    cpu->ebp = (int64_t)(int32_t)(cpu->ebp) * (int64_t)(int32_t)(cpu->edi);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi)), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); lift_store32(cpu->esi, v); }
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax = cpu->edx;
    { uint64_t l=(uint64_t)(cpu->edx), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x13u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    cpu->edx = lift_load32(cpu->esi);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 0xCu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->eax + 0x10u, cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003B492;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->edx) != 0u) goto label_0003B418;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (int8_t)(lift_load8(cpu->edx + cpu->ecx));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax + 0x14u, cpu->ecx);
    lift_store32(cpu->eax, 0x10u);
    lift_store32(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
    label_0003B418: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B418u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(0x10u)) goto label_0003B422;
    if ((uint32_t)(cpu->edx) != (uint32_t)(0x20u)) goto label_0003B43F;
    label_0003B422: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B422u);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = lift_load32(cpu->esi + cpu->ecx);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax + 0x14u, cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, 4u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
    label_0003B43F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B43Fu);
    if ((uint32_t)(cpu->edx) != (uint32_t)(0x30u)) goto label_0003B46A;
    cpu->edx = lift_load32(cpu->esi);
    lift_store32(cpu->eax + 0x14u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax + 0x18u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, 0x30u);
    lift_store32(cpu->eax + 0x1Cu, cpu->edx);
    lift_store32(cpu->eax + 4u, 0xCu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
    label_0003B46A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B46Au);
    cpu->ecx += g_sfera_mbc_runtime->process_memory_base;
    cpu->edi = lift_pop32(cpu);
    cpu->esi = lift_load32(cpu->ecx);
    lift_store32(cpu->eax + 0x14u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 0x18u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax + 0x1Cu, cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, 0xCu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
    label_0003B492: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B492u);
    cpu->edx = lift_load32(cpu->esi);
    lift_store32(cpu->eax + 0x14u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 0x18u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store32(cpu->eax + 0x1Cu, cpu->edx);
    lift_store32(cpu->eax + 4u, 0xCu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043B4C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43B4C0u);
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load8(cpu->eax);
    ++cpu->eax;
    lift_push32(cpu, cpu->esi);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load16(cpu->eax);
    cpu->eax += 2u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43B4E1u); lift_push32(cpu, r); sfera_sub_0043AC90(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43B4E8u); lift_push32(cpu, r); sfera_sub_0043AC30(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(cpu->eax);
    lift_store32(cpu->esi, (uint64_t)(lift_load32(cpu->esi)) + (uint64_t)(cpu->edi) + (uint64_t)(0u));
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->edi = lift_load32(cpu->esi);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003B554;
    if ((uint32_t)(cpu->edi) < (uint32_t)(cpu->eax)) goto label_0003B4FF;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(lift_load32(cpu->esi + 8u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0003B554;
    label_0003B4FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B4FFu);
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43B509u); lift_push32(cpu, r); sfera_sub_00434AF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43B529u); lift_push32(cpu, r); sfera_sub_0049B7F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->esp += 0x18u;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003B554;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003B554;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0003B544;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 8u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0003B554;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_0003B544: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B544u);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0003B54B;
    lift_store32(cpu->esi + 4u, cpu->eax);
    goto label_0003B554;
    label_0003B54B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B54Bu);
    --cpu->eax;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 8u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003B554;
    lift_store32(cpu->esi + 8u, cpu->eax);
    label_0003B554: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B554u);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 0xCu, cpu->edx);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->eax + 0x10u, cpu->ecx);
    if ((uint32_t)(cpu->ebx) != 0u) goto label_0003B59E;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (int8_t)(lift_load8(cpu->edx + cpu->edi));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->eax + 0x14u, cpu->ecx);
    lift_store32(cpu->eax, 0x10u);
    lift_store32(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003B59E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B59Eu);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(0x10u)) goto label_0003B5A8;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(0x20u)) goto label_0003B5C1;
    label_0003B5A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B5A8u);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = lift_load32(cpu->edx + cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 0x14u, cpu->ecx);
    lift_store32(cpu->eax + 4u, 4u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003B5C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B5C1u);
    if ((uint32_t)(cpu->ebx) != (uint32_t)(0x30u)) goto label_0003B5E4;
    cpu->edx = lift_load32(cpu->esi);
    lift_store32(cpu->eax + 0x14u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 0x18u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 0x1Cu, cpu->edx);
    lift_store32(cpu->eax + 4u, 0xCu);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003B5E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B5E4u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->ecx + cpu->edi);
    lift_store32(cpu->eax + 0x14u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + cpu->edi + 4u);
    lift_store32(cpu->eax + 0x18u, cpu->edx);
    cpu->ecx = lift_load32(cpu->ecx + cpu->edi + 8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 0x1Cu, cpu->ecx);
    lift_store32(cpu->eax + 4u, 0xCu);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043B610(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43B610u);
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load8(cpu->eax);
    lift_push32(cpu, cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->edi);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43B626u); lift_push32(cpu, r); sfera_sub_0043AC90(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = lift_load16(cpu->eax);
    cpu->eax += 2u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    lift_store32(cpu->esi, (uint64_t)(lift_load32(cpu->esi)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->edi = lift_load32(cpu->esi);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003B6A1;
    if ((uint32_t)(cpu->edi) < (uint32_t)(cpu->eax)) goto label_0003B64C;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(lift_load32(cpu->esi + 8u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0003B6A1;
    label_0003B64C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B64Cu);
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43B656u); lift_push32(cpu, r); sfera_sub_00434AF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43B676u); lift_push32(cpu, r); sfera_sub_0049B7F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->esp += 0x18u;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003B6A1;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003B6A1;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0003B691;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 8u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0003B6A1;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_0003B691: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B691u);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0003B698;
    lift_store32(cpu->esi + 4u, cpu->eax);
    goto label_0003B6A1;
    label_0003B698: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B698u);
    --cpu->eax;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 8u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003B6A1;
    lift_store32(cpu->esi + 8u, cpu->eax);
    label_0003B6A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B6A1u);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    ++cpu->ecx;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    lift_store32(cpu->eax, cpu->ebx);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(0x10u)) goto label_0003B6C4;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(0x20u)) goto label_0003B6E7;
    label_0003B6C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B6C4u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->ecx + cpu->edi);
    lift_store32(cpu->eax + 0x14u, cpu->edx);
    lift_store32(cpu->eax + 4u, 4u);
    lift_store32(cpu->eax + 0xCu, cpu->edi);
    lift_store32(cpu->eax + 8u, cpu->edi);
    cpu->edi += 3u;
    lift_store32(cpu->eax + 0x10u, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003B6E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B6E7u);
    if ((uint32_t)(cpu->ebx) != 0u) goto label_0003B712;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = (int8_t)(lift_load8(cpu->ecx + cpu->edi));
    lift_store32(cpu->eax + 0x14u, cpu->edx);
    lift_store32(cpu->eax, 0x10u);
    lift_store32(cpu->eax + 4u, 1u);
    lift_store32(cpu->eax + 0xCu, cpu->edi);
    lift_store32(cpu->eax + 8u, cpu->edi);
    lift_store32(cpu->eax + 0x10u, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003B712: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B712u);
    if ((uint32_t)(cpu->ebx) != (uint32_t)(0x30u)) goto label_0003B751;
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx += 4u;
    lift_store32(cpu->eax + 0xCu, cpu->edi);
    lift_store32(cpu->eax + 8u, cpu->edi);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edx + cpu->edi + 0xFFFFFFFFu);
    lift_store32(cpu->eax + 0x10u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 0xCu);
    cpu->edx = cpu->edi;
    lift_store32(cpu->eax + 0x14u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->eax + 0x18u, cpu->ecx);
    lift_store32(cpu->eax + 0x1Cu, cpu->edx);
    lift_store32(cpu->eax + 4u, 0xCu);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003B751: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B751u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->ecx + cpu->edi);
    lift_store32(cpu->eax + 0x14u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + cpu->edi + 4u);
    lift_store32(cpu->eax + 0x18u, cpu->edx);
    cpu->ecx = lift_load32(cpu->ecx + cpu->edi + 8u);
    lift_store32(cpu->eax + 0x1Cu, cpu->ecx);
    lift_store32(cpu->eax + 4u, 0xCu);
    lift_store32(cpu->eax + 0xCu, cpu->edi);
    lift_store32(cpu->eax + 8u, cpu->edi);
    cpu->edi += 0xBu;
    lift_store32(cpu->eax + 0x10u, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043B790(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43B790u);
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load8(cpu->eax);
    lift_push32(cpu, cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->edi);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43B7A6u); lift_push32(cpu, r); sfera_sub_0043AC90(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = lift_load16(cpu->eax);
    cpu->eax += 2u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    lift_store32(cpu->esi, (uint64_t)(lift_load32(cpu->esi)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->edi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0003B821;
    if ((uint32_t)(cpu->edi) < (uint32_t)(cpu->eax)) goto label_0003B7CC;
    if ((uint32_t)(cpu->edi) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0003B821;
    label_0003B7CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B7CCu);
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43B7D6u); lift_push32(cpu, r); sfera_sub_00434AF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43B7F6u); lift_push32(cpu, r); sfera_sub_0049B7F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->esp += 0x18u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0003B821;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0003B821;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0003B811;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0003B821;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_0003B811: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B811u);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0003B818;
    lift_store32(cpu->esi + 4u, cpu->eax);
    goto label_0003B821;
    label_0003B818: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B818u);
    --cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0003B821;
    lift_store32(cpu->esi + 8u, cpu->eax);
    label_0003B821: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B821u);
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 0x18u, cpu->edi);
    lift_store32(cpu->eax + 0x14u, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->edi + 0xFFFFFFFFu);
    lift_store32(cpu->eax + 0x1Cu, cpu->ecx);
    cpu->edi = lift_pop32(cpu);
    ++cpu->edx;
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->eax + 8u, 0xFFFFFFFFu);
    lift_store32(cpu->eax + 0x10u, 1u);
    lift_store32(cpu->eax + 0xCu, 1u);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    lift_store32(cpu->eax + 4u, 0xCu);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043B880(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43B880u);
    cpu->eax = g_sfera_mbc_runtime->program_index;
    cpu->ecx = g_sfera_mbc_runtime->program_table_base;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->instruction_cursor;
    cpu->esi -= g_sfera_mbc_runtime->bytecode_base;
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->eax + cpu->ecx + 0x84u);
    cpu->esi += 4u;
    if ((uint8_t)(lift_load8(cpu->edi)) < (uint8_t)(0x14u)) goto label_0003B8B8;
    cpu->ecx = (uint32_t)(uintptr_t)"Return stack overflow";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3B8B8u); lift_push32(cpu, r); sfera_sub_004385D0(cpu,r); if (cpu->eip != r) return; }
    label_0003B8B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B8B8u);
    cpu->edx = lift_load8(cpu->edi);
    cpu->eax = g_sfera_mbc_runtime->active_program_record;
    lift_store32(cpu->eax + ((uint32_t)(cpu->edx) * 4u) + 0x34u, cpu->esi);
    lift_store8(cpu->edi, (uint64_t)(lift_load8(cpu->edi)) + 1u);
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->eax += lift_load32(cpu->eax);
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    g_sfera_mbc_runtime->argument_end = (uint32_t)(cpu->eax);
    cpu->eax -= g_sfera_mbc_runtime->argument_count;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->eax);
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043B8F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43B8F0u);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->ebp = 0u;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    cpu->edi = (uint32_t)(cpu->esi + 0x30u);
    g_sfera_mbc_runtime->argument_count = (uint32_t)(cpu->ebp);
    cpu->ebx = (uint32_t)(cpu->ebp + 1u);
    label_0003B911: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B911u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + cpu->ebp + 0x20u)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x46u)) goto label_0003B98E;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x49u)) goto label_0003B96D;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x53u)) goto label_0003B92B;
    cpu->ebp = 0x10u;
    goto label_0003B9EE;
    label_0003B92B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B92Bu);
    cpu->eax = cpu->edi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0003B930: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B930u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0003B930;
    cpu->eax -= cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    cpu->eax = cpu->edi;
    cpu->eax -= g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = cpu->ebx;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->eax + cpu->esi + 0xFFFFFFFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43B95Fu); lift_push32(cpu, r); sfera_sub_0043AF30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->edi += cpu->esi;
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    goto label_0003B9E8;
    label_0003B96D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B96Du);
    cpu->edx = lift_load32(cpu->edi);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0003B99C;
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(cpu->edx);
    goto label_0003B9C7;
    label_0003B98E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B98Eu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003B9AE;
    label_0003B99C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B99Cu);
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43B9A6u); lift_push32(cpu, r); sfera_sub_004385D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    goto label_0003B9E5;
    label_0003B9AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B9AEu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x20u);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0], lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0003B9C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B9C7u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    cpu->ecx += cpu->ebx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->ebx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->ebx);
    label_0003B9E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B9E5u);
    cpu->edi += 4u;
    label_0003B9E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B9E8u);
    g_sfera_mbc_runtime->argument_count += cpu->ebx;
    label_0003B9EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x43B9EEu);
    cpu->ebp += cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(0x10u)) goto label_0003B911;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043BA10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43BA10u);
    cpu->eax = g_sfera_mbc_runtime->active_process;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->eax + 0xBCu);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_0003BAA7;
    --g_sfera_mbc_runtime->instruction_cursor;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->eax + 0x64u);
    cpu->ebx = 0u;
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_0003BA7F;
    cpu->esi = lift_load32(cpu->eax + 0x68u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0003BA40: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BA40u);
    cpu->ecx = cpu->esi;
    cpu->eax = cpu->ebp;
    label_0003BA44: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BA44u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003BA64;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_0003BA60;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003BA64;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0003BA44;
    label_0003BA60: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BA60u);
    cpu->eax = 0u;
    goto label_0003BA69;
    label_0003BA64: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BA64u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_0003BA69: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BA69u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0003BA72;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x28u)) >= (int32_t)(uint32_t)(cpu->eax)) goto label_0003BAA9;
    label_0003BA72: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BA72u);
    ++cpu->ebx;
    cpu->esi += 0x34u;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->edi)) goto label_0003BA40;
    cpu->eax = g_sfera_mbc_runtime->active_process;
    label_0003BA7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BA7Fu);
    cpu->ecx = lift_load32(cpu->eax + 0xBCu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0003BAA4;
    cpu->edx = lift_load32(cpu->ecx + 0x230u);
    lift_store32(cpu->eax + 0xBCu, cpu->edx);
    lift_push32(cpu, 0x1853u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3BAA4u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    label_0003BAA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BAA4u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0003BAA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BAA7u);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003BAA9: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BAA9u);
    cpu->eax = g_sfera_mbc_runtime->program_index;
    cpu->ecx = g_sfera_mbc_runtime->program_table_base;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    cpu->edi = g_sfera_mbc_runtime->bytecode_base;
    cpu->edi -= g_sfera_mbc_runtime->instruction_cursor;
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + cpu->ecx + 0x84u)), r=(uint64_t)(0x14u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = (uint32_t)(cpu->eax + cpu->ecx + 0x84u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0003BAE1;
    cpu->ecx = (uint32_t)(uintptr_t)"Return stack overflow";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3BAE1u); lift_push32(cpu, r); sfera_sub_004385D0(cpu,r); if (cpu->eip != r) return; }
    label_0003BAE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BAE1u);
    cpu->edx = lift_load8(cpu->esi);
    cpu->eax = g_sfera_mbc_runtime->active_program_record;
    lift_store32(cpu->eax + ((uint32_t)(cpu->edx) * 4u) + 0x34u, cpu->edi);
    lift_store8(cpu->esi, (uint64_t)(lift_load8(cpu->esi)) + 1u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BAF6u); lift_push32(cpu, r); sfera_sub_0043B8F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x34u);
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    cpu->edx = lift_load32(cpu->ecx + 0x68u);
    cpu->eax = lift_load32(cpu->edx + cpu->ebx + 0x24u);
    cpu->eax += g_sfera_mbc_runtime->bytecode_base;
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->argument_end = (uint32_t)(cpu->eax);
    cpu->eax -= g_sfera_mbc_runtime->argument_count;
    cpu->ebx = lift_pop32(cpu);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->eax);
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->eax);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043BB30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43BB30u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x1976u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = 0x100u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BB46u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BB4Du); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    cpu->esp -= 8u;
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)"MBInter:\n %f"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x43BB61u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43BB67u);
    cpu->esp += 0x10u;
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00459B10(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043BB80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43BB80u);
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0003BB96;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BB8Eu); lift_push32(cpu, r); sfera_sub_004595F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::exit), LIFT_CODE_TOKEN_RVA(0x3BB90u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x3BB96u);
    label_0003BB96: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BB96u);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(1u)) goto label_0003BBA5;
    g_sfera_network_runtime.active_slot = (uint32_t)(0xFFFFFFFFu);
    label_0003BBA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BBA5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BBAAu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->ecx += g_sfera_mbc_runtime->process_memory_base;
    sfera_sub_00459B10(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043BBC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43BBC0u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BBC6u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BBD1u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BBE0u); lift_push32(cpu, r); sfera_sub_0043AED0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043BBF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43BBF0u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BBF6u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BC01u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BC10u); lift_push32(cpu, r); sfera_sub_0043AED0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043BC20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43BC20u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BC26u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BC31u); lift_push32(cpu, r); sfera_sub_004EEC54(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BC40u); lift_push32(cpu, r); sfera_sub_0043AED0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043BC50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43BC50u);
    cpu->esp -= 8u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BC58u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BC60u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BC70u); lift_push32(cpu, r); sfera_sub_004EEC4E(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BC81u); lift_push32(cpu, r); sfera_sub_0043AED0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043BC90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43BC90u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BC95u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0003BC9B;
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    label_0003BC9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BC9Bu);
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003BCB3;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003BCB3: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BCB3u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].payload[0] = (uint32_t)(cpu->eax);
    cpu->eax = 1u;
    cpu->edx += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_end = (uint32_t)(cpu->eax);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_begin = (uint32_t)(cpu->eax);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043BCF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43BCF0u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BCF6u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0003BD11;
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    label_0003BD11: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BD11u);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BD1Au); lift_push32(cpu, r); sfera_sub_0043AED0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043BD20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43BD20u);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003BD38;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003BD38: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BD38u);
    cpu->edx = g_sfera_recovered_static_runtime.simulation_tick;
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(cpu->edx);
    cpu->edx = 1u;
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->edx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->edx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043BD80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43BD80u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x43BD81u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43BD87u);
    lift_store32(cpu->esp, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp)))));
    lift_push32(cpu, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0517578125e-05));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BDA4u); lift_push32(cpu, r); sfera_sub_0043AED0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043BDB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43BDB0u);
    cpu->esp -= 0x18u;
    if ((uint32_t)(g_sfera_mbc_runtime->argument_count) != (uint32_t)(2u)) goto label_0003BE83;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BDC7u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BDCEu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->esi);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_0003BDDC;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_0003BDEF;
    label_0003BDDC: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BDDCu);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0003BDFB;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_0003BDEF;
    cpu->eax += 0xBu;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0003BDFB;
    label_0003BDEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BDEFu);
    cpu->edx = 0xCu;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3BDFBu); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    label_0003BDFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BDFBu);
    cpu->eax = lift_load32(cpu->edi);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_0003BE07;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_0003BE1A;
    label_0003BE07: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BE07u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0003BE26;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_0003BE1A;
    cpu->eax += 0xBu;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_0003BE26;
    label_0003BE1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BE1Au);
    cpu->edx = 0xCu;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3BE26u); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    label_0003BE26: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BE26u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003BE7D;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->edi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->edx + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + cpu->edx + 4u))));
    cpu->ecx += cpu->edx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->edx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->edx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 8u))));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BE6Cu); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3BE7Du); lift_push32(cpu, r); sfera_sub_0043AED0(cpu,r); if (cpu->eip != r) return; }
    label_0003BE7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BE7Du);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_0003BE83: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BE83u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BE88u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BE91u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BE99u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BEA2u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    if ((uint32_t)(cpu->eax) != (uint32_t)(4u)) goto label_0003BEE9;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 8u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0xCu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BED4u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BEE5u); lift_push32(cpu, r); sfera_sub_0043AED0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_0003BEE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BEE9u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(5u)) goto label_0003BF1A;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_push32(cpu, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0xCu))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BF16u); lift_push32(cpu, r); sfera_sub_0043AED0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_0003BF1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BF1Au);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BF1Fu); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BF28u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(6u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 8u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003BF7E;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BF69u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BF7Au); lift_push32(cpu, r); sfera_sub_0043AED0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_0003BF7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BF7Eu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BF8Fu); lift_push32(cpu, r); sfera_sub_0043AED0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043BFA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43BFA0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BFA7u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BFAEu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43BFB5u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(0x100u)) goto label_0003BFCF;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003BFCF: cpu->eip = LIFT_CODE_TOKEN_VA(0x43BFCFu);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(8u), 32u);
    cpu->edi &= 0xFFu;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edi), v=l | r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    cpu->esi |= cpu->eax;
    cpu->eax = 1u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].payload[0] = (uint32_t)(cpu->esi);
    cpu->edx += cpu->eax;
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_end = (uint32_t)(cpu->eax);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_begin = (uint32_t)(cpu->eax);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043C030(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43C030u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C03Au); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C041u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003C062;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003C062: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C062u);
    cpu->eax = cpu->edi;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(0x10u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 8u)))));
    lift_push32(cpu, cpu->ebp);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_push32(cpu, cpu->esi);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->esi = cpu->ebx;
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(5u), 32u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->esi >> 5u].type = (uint32_t)(0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C094u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edi;
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->ecx &= 0xFFu;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    cpu->ebp = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)(8u), 32u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C0B9u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edi &= 0xFFu;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * ((double)(((int32_t)(lift_load32(cpu->esp + 0x14u))))));
    cpu->eax &= 0xFFu;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)(8u), 32u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C0D6u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->eax &= 0xFFu;
    cpu->ebp |= cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->esi >> 5u].payload[0] = (uint32_t)(cpu->ebp);
    cpu->eax = 1u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->esi >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->esi >> 5u].range_end = (uint32_t)(cpu->eax);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->esi >> 5u].range_begin = (uint32_t)(cpu->eax);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ebx += cpu->eax;
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ebx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043C110(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43C110u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C116u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0003C131;
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    label_0003C131: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C131u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C136u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C145u); lift_push32(cpu, r); sfera_sub_0043AED0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043C150(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43C150u);
    if ((uint32_t)(g_sfera_mbc_runtime->argument_count) != (uint32_t)(0u)) goto label_0003C164;
    cpu->ecx = g_sfera_scene_control_runtime.active_context;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3C164u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_0003C164: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C164u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C169u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0003C178;
    cpu->ecx = g_sfera_scene_control_runtime.active_context;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003C178: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C178u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_0003C188;
    cpu->ecx = g_sfera_world_load_runtime.active_tool_context;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003C188: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C188u);
    cpu->ecx = g_sfera_recovered_static_runtime.graphics_state;
    sfera_sub_0043B0D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043C1A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43C1A0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C1A5u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_texture_cache_runtime.cache_enabled) == (uint32_t)(0u)) goto label_0003C1BA;
    cpu->ecx = (int8_t)(lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_direct_input_runtime.keyboard_state[0])));
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003C1BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C1BAu);
    cpu->ecx = 0u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043C1D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43C1D0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C1D7u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_load32(cpu->eax);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003C1EB;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C1E7u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    goto label_0003C1EE;
    label_0003C1EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C1EBu);
    cpu->edi |= 0xFFFFFFFFu;
    label_0003C1EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C1EEu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003C22B;
    if ((uint32_t)(cpu->esi) != 0u) goto label_0003C20D;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffprc_load\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C20Au); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_0003C20D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C20Du);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->esi);
    cpu->edx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C21Du); lift_push32(cpu, r); sfera_sub_00435230(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_runtime->active_tag = (uint32_t)(cpu->eax);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003C22B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C22Bu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043C230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43C230u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C236u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(0xFFFFu)) goto label_0003C25A;
    cpu->ecx = cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x348u);
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id))) != (uint32_t)(cpu->eax)) goto label_0003C25A;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))) < (int32_t)(uint32_t)(0u)) goto label_0003C25A;
    cpu->esi = cpu->eax;
    goto label_0003C25D;
    label_0003C25A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C25Au);
    cpu->esi |= 0xFFFFFFFFu;
    label_0003C25D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C25Du);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003C2B0;
    if ((uint32_t)(cpu->esi) != (uint32_t)(g_sfera_mbc_runtime->process_index)) goto label_0003C281;
    g_sfera_mbc_runtime->active_tag = (uint32_t)(0xFFFFFFFFu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003C281: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C281u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_0003C29C;
    lift_push32(cpu, 0x1A42u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp"); lift_push32(cpu, (uintptr_t)"Unloading _main: %s:%d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C299u); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_0003C29C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C29Cu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C2A3u); lift_push32(cpu, r); sfera_sub_00435D40(cpu,r); if (cpu->eip != r) return; }
    g_sfera_mbc_runtime->active_tag = (uint32_t)(cpu->eax);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003C2B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C2B0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043C2C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43C2C0u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C2C6u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != 0u) goto label_0003C2DE;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffprc_link\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C2DBu); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_0003C2DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C2DEu);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C2ECu); lift_push32(cpu, r); sfera_sub_004386C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    g_sfera_mbc_runtime->active_tag = (uint32_t)(cpu->eax);
    cpu->esi = lift_pop32(cpu);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003C30A;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003C30A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C30Au);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].payload[0] = (uint32_t)(cpu->eax);
    cpu->eax = 1u;
    cpu->edx += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_end = (uint32_t)(cpu->eax);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_begin = (uint32_t)(cpu->eax);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043C350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43C350u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C355u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(0xFFFFu)) goto label_0003C375;
    cpu->ecx = cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x348u);
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id))) != (uint32_t)(cpu->eax)) goto label_0003C375;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))) >= (int32_t)(uint32_t)(0u)) goto label_0003C378;
    label_0003C375: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C375u);
    cpu->eax |= 0xFFFFFFFFu;
    label_0003C378: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C378u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003C39E;
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0003C38D;
    cpu->ecx |= 0xFFFFFFFFu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003C38D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C38Du);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].module_tag));
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003C39E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C39Eu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043C3A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43C3A0u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->esi = 1u;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = g_sfera_mbc_runtime->process_chain_first;
    lift_store32(cpu->esp + 0x10u, 0xFFFFFFFFu);
    if ((uint32_t)(g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type) != (uint32_t)(cpu->esi)) goto label_0003C3F1;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C3CFu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ebp) != 0u) goto label_0003C3E7;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffprc_id\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C3E4u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_0003C3E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C3E7u);
    cpu->ebx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ebx += cpu->ebp;
    goto label_0003C3F8;
    label_0003C3F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C3F1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C3F6u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    label_0003C3F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C3F8u);
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->argument_count) <= (int32_t)(uint32_t)(cpu->esi)) goto label_0003C428;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C405u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(0xFFFFu)) goto label_0003C4E0;
    cpu->edx = cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_next_index));
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_0003C4E0;
    cpu->edi = cpu->ecx;
    label_0003C428: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C428u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003C4F0;
    label_0003C440: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C440u);
    cpu->esi = cpu->edi;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    if ((uint32_t)(lift_load32(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))) == (uint32_t)(0xFFFFFFFFu)) goto label_0003C4E0;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0003C4A8;
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].name[0]));
    cpu->eax = cpu->ebx;
    label_0003C461: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C461u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003C481;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_0003C47D;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003C481;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0003C461;
    label_0003C47D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C47Du);
    cpu->eax = 0u;
    goto label_0003C486;
    label_0003C481: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C481u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_0003C486: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C486u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0003C4B4;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x348u);
    cpu->eax = lift_load32(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->esp + 4u, cpu->eax);
    cpu->ecx = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003C4A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C4A8u);
    if ((uint32_t)(cpu->ebp) == (uint32_t)(lift_load32(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].module_tag)))) goto label_0003C4D0;
    if ((uint32_t)(cpu->ebp) == 0u) goto label_0003C4D0;
    label_0003C4B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C4B4u);
    cpu->eax = cpu->edi;
    cpu->edi = lift_load32(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_next_index));
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->eax)) goto label_0003C440;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003C4D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C4D0u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x348u);
    cpu->ecx = lift_load32(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id));
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    label_0003C4E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C4E0u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003C4F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C4F0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043C770(LiftCpu* cpu, uint32_t stop_address) {
    goto label_0003C770;
    label_0003C500: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C500u);
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    cpu->esi += ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0]);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x68u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 8u, cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003C53F;
    cpu->ecx |= 0xFFFFFFFFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C52Fu); lift_push32(cpu, r); sfera_sub_0043AFA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    lift_return(cpu, 0u, stop_address); return;
    label_0003C53F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C53Fu);
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003C5EF;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C55Cu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->ecx += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, 0x1Fu); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x43C56Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43C572u);
    cpu->ebp = lift_load32(cpu->esi + 0x64u);
    cpu->edi = 0u;
    cpu->esp += 0xCu;
    lift_store8(cpu->esp + 0x37u, 0u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_0003C5D0;
    cpu->ebx = lift_load32(cpu->esi + 0x68u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0003C590: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C590u);
    cpu->ecx = cpu->ebx;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    label_0003C596: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C596u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003C5B6;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_0003C5B2;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003C5B6;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0003C596;
    label_0003C5B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C5B2u);
    cpu->eax = 0u;
    goto label_0003C5BB;
    label_0003C5B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C5B6u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_0003C5BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C5BBu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0003C5C4;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x28u)) >= (int32_t)(uint32_t)(cpu->eax)) goto label_0003C5CC;
    label_0003C5C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C5C4u);
    ++cpu->edi;
    cpu->ebx += 0x34u;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->ebp)) goto label_0003C590;
    label_0003C5CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C5CCu);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    label_0003C5D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C5D0u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->ebp)) goto label_0003C609;
    label_0003C5D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C5D4u);
    cpu->ecx |= 0xFFFFFFFFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C5DCu); lift_push32(cpu, r); sfera_sub_0043AFA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    lift_return(cpu, 0u, stop_address); return;
    label_0003C5EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C5EFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C5F4u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xC4u);
    cpu->eax = lift_load16(cpu->ecx + ((uint32_t)(cpu->eax) * 2u));
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFu)) goto label_0003C5D4;
    label_0003C609: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C609u);
    cpu->ebp = g_sfera_mbc_runtime->execution_context_depth;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi = g_sfera_mbc_runtime->process_index;
    cpu->edx = g_sfera_mbc_runtime->bytecode_base;
    cpu->ebx = g_sfera_mbc_runtime->program_table_base;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].process_index = (uint32_t)(cpu->edi);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x348u);
    cpu->edi = lift_load32(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id));
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].process_memory_base = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->program_index;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].program_index = (uint32_t)(cpu->ecx);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xA4u);
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].bytecode_base = (uint32_t)(cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->instruction_cursor;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].process_id = (uint32_t)(cpu->edi);
    cpu->edi = g_sfera_mbc_runtime->active_process;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].instruction_cursor = (uint32_t)(cpu->edx);
    cpu->edx -= g_sfera_mbc_runtime->bytecode_base;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].active_process = (uint32_t)(cpu->edi);
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].program_table_base = (uint32_t)(cpu->ebx);
    cpu->ecx += cpu->ebx;
    g_sfera_mbc_runtime->active_program_record = (uint32_t)(cpu->ecx);
    ++cpu->ebp;
    g_sfera_mbc_runtime->execution_context_depth = (uint32_t)(cpu->ebp);
    lift_store32(cpu->ecx + 0x88u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esi + 0x5Cu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x34u);
    cpu->edi = lift_load32(cpu->esi + 0x48u);
    cpu->eax = lift_load32(cpu->esi + 0x68u);
    g_sfera_mbc_runtime->bytecode_base = (uint32_t)(cpu->edi);
    g_sfera_mbc_runtime->program_table_base = (uint32_t)(cpu->edx);
    cpu->ebx = lift_load32(cpu->eax + cpu->ecx + 0x24u);
    cpu->ebx += cpu->edi;
    cpu->edi = lift_load32(cpu->esi + 0x50u);
    g_sfera_mbc_runtime->process_memory_base = (uint32_t)(cpu->edi);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ebx);
    cpu->eax = lift_load32(cpu->eax + cpu->ecx + 0x28u);
    g_sfera_mbc_runtime->program_index = (uint32_t)(cpu->eax);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    cpu->edi = (uint32_t)(cpu->eax + cpu->edx);
    g_sfera_mbc_runtime->active_program_record = (uint32_t)(cpu->edi);
    lift_store8(cpu->edx + cpu->eax + 0x84u, 0u);
    cpu->eax = g_sfera_mbc_runtime->program_index;
    cpu->edi = lift_load32(cpu->esi + 0x5Cu);
    cpu->edx = cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xA4u);
    if ((uint8_t)(lift_load8(cpu->edx + cpu->edi + 0x94u)) == (uint8_t)(0u)) goto label_0003C731;
    cpu->edx = lift_load32(cpu->esi + 0x68u);
    if ((uint32_t)(lift_load32(cpu->edx + cpu->ecx + 0x2Cu)) != (uint32_t)(0u)) goto label_0003C731;
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->ecx = lift_load32(cpu->eax + 0x44u);
    cpu->edx = g_sfera_mbc_runtime->process_index;
    cpu->eax = lift_load32(cpu->esi + 0x44u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"Double \"func\" call, prob. stack corruption: %s (prc %d, tag %d), called from (prc %d, tag %d).\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C729u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_mbc_runtime->program_index;
    cpu->esp += 0x1Cu;
    label_0003C731: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C731u);
    cpu->ecx = lift_load32(cpu->esi + 0x5Cu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->eax + cpu->ecx + 0x94u, 1u);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    g_sfera_mbc_runtime->active_process = (uint32_t)(cpu->esi);
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->process_index = (uint32_t)(cpu->edx);
    g_sfera_mbc_runtime->active_tag = (uint32_t)(0u);
    cpu->esp += 0x2Cu;
    lift_return(cpu, 0u, stop_address); return;
    label_0003C770: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C770u);
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(2u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); g_sfera_mbc_runtime->argument_count = (uint32_t)((v)); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0003C781;
    cpu->ecx |= 0xFFFFFFFFu;
    sfera_sub_0043AFA0(cpu, stop_address); return;
    label_0003C781: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C781u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C786u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) > (uint32_t)(0xFFFFu)) goto label_0003C7AA;
    cpu->edx = cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    if ((uint32_t)(lift_load32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id))) != (uint32_t)(cpu->eax)) goto label_0003C7AA;
    if ((int32_t)(uint32_t)(lift_load32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))) < (int32_t)(uint32_t)(0u)) goto label_0003C7AA;
    if ((int32_t)(uint32_t)(cpu->eax) > 0) goto label_0003C7B2;
    label_0003C7AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C7AAu);
    cpu->ecx |= 0xFFFFFFFFu;
    sfera_sub_0043AFA0(cpu, stop_address); return;
    label_0003C7B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C7B2u);
    cpu->ecx = cpu->eax;
    goto label_0003C500;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043C7C0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_0003C7C0;
    label_0003C500: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C500u);
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    cpu->esi += ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0]);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x68u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 8u, cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003C53F;
    cpu->ecx |= 0xFFFFFFFFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C52Fu); lift_push32(cpu, r); sfera_sub_0043AFA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    lift_return(cpu, 0u, stop_address); return;
    label_0003C53F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C53Fu);
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003C5EF;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C55Cu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->ecx += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, 0x1Fu); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x43C56Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43C572u);
    cpu->ebp = lift_load32(cpu->esi + 0x64u);
    cpu->edi = 0u;
    cpu->esp += 0xCu;
    lift_store8(cpu->esp + 0x37u, 0u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_0003C5D0;
    cpu->ebx = lift_load32(cpu->esi + 0x68u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0003C590: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C590u);
    cpu->ecx = cpu->ebx;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    label_0003C596: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C596u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003C5B6;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_0003C5B2;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003C5B6;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0003C596;
    label_0003C5B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C5B2u);
    cpu->eax = 0u;
    goto label_0003C5BB;
    label_0003C5B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C5B6u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_0003C5BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C5BBu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0003C5C4;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x28u)) >= (int32_t)(uint32_t)(cpu->eax)) goto label_0003C5CC;
    label_0003C5C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C5C4u);
    ++cpu->edi;
    cpu->ebx += 0x34u;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->ebp)) goto label_0003C590;
    label_0003C5CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C5CCu);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    label_0003C5D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C5D0u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->ebp)) goto label_0003C609;
    label_0003C5D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C5D4u);
    cpu->ecx |= 0xFFFFFFFFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C5DCu); lift_push32(cpu, r); sfera_sub_0043AFA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    lift_return(cpu, 0u, stop_address); return;
    label_0003C5EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C5EFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C5F4u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xC4u);
    cpu->eax = lift_load16(cpu->ecx + ((uint32_t)(cpu->eax) * 2u));
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFu)) goto label_0003C5D4;
    label_0003C609: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C609u);
    cpu->ebp = g_sfera_mbc_runtime->execution_context_depth;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi = g_sfera_mbc_runtime->process_index;
    cpu->edx = g_sfera_mbc_runtime->bytecode_base;
    cpu->ebx = g_sfera_mbc_runtime->program_table_base;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].process_index = (uint32_t)(cpu->edi);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x348u);
    cpu->edi = lift_load32(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id));
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].process_memory_base = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->program_index;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].program_index = (uint32_t)(cpu->ecx);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xA4u);
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].bytecode_base = (uint32_t)(cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->instruction_cursor;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].process_id = (uint32_t)(cpu->edi);
    cpu->edi = g_sfera_mbc_runtime->active_process;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].instruction_cursor = (uint32_t)(cpu->edx);
    cpu->edx -= g_sfera_mbc_runtime->bytecode_base;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].active_process = (uint32_t)(cpu->edi);
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].program_table_base = (uint32_t)(cpu->ebx);
    cpu->ecx += cpu->ebx;
    g_sfera_mbc_runtime->active_program_record = (uint32_t)(cpu->ecx);
    ++cpu->ebp;
    g_sfera_mbc_runtime->execution_context_depth = (uint32_t)(cpu->ebp);
    lift_store32(cpu->ecx + 0x88u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esi + 0x5Cu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x34u);
    cpu->edi = lift_load32(cpu->esi + 0x48u);
    cpu->eax = lift_load32(cpu->esi + 0x68u);
    g_sfera_mbc_runtime->bytecode_base = (uint32_t)(cpu->edi);
    g_sfera_mbc_runtime->program_table_base = (uint32_t)(cpu->edx);
    cpu->ebx = lift_load32(cpu->eax + cpu->ecx + 0x24u);
    cpu->ebx += cpu->edi;
    cpu->edi = lift_load32(cpu->esi + 0x50u);
    g_sfera_mbc_runtime->process_memory_base = (uint32_t)(cpu->edi);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ebx);
    cpu->eax = lift_load32(cpu->eax + cpu->ecx + 0x28u);
    g_sfera_mbc_runtime->program_index = (uint32_t)(cpu->eax);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    cpu->edi = (uint32_t)(cpu->eax + cpu->edx);
    g_sfera_mbc_runtime->active_program_record = (uint32_t)(cpu->edi);
    lift_store8(cpu->edx + cpu->eax + 0x84u, 0u);
    cpu->eax = g_sfera_mbc_runtime->program_index;
    cpu->edi = lift_load32(cpu->esi + 0x5Cu);
    cpu->edx = cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xA4u);
    if ((uint8_t)(lift_load8(cpu->edx + cpu->edi + 0x94u)) == (uint8_t)(0u)) goto label_0003C731;
    cpu->edx = lift_load32(cpu->esi + 0x68u);
    if ((uint32_t)(lift_load32(cpu->edx + cpu->ecx + 0x2Cu)) != (uint32_t)(0u)) goto label_0003C731;
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->ecx = lift_load32(cpu->eax + 0x44u);
    cpu->edx = g_sfera_mbc_runtime->process_index;
    cpu->eax = lift_load32(cpu->esi + 0x44u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"Double \"func\" call, prob. stack corruption: %s (prc %d, tag %d), called from (prc %d, tag %d).\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C729u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_mbc_runtime->program_index;
    cpu->esp += 0x1Cu;
    label_0003C731: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C731u);
    cpu->ecx = lift_load32(cpu->esi + 0x5Cu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->eax + cpu->ecx + 0x94u, 1u);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    g_sfera_mbc_runtime->active_process = (uint32_t)(cpu->esi);
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->process_index = (uint32_t)(cpu->edx);
    g_sfera_mbc_runtime->active_tag = (uint32_t)(0u);
    cpu->esp += 0x2Cu;
    lift_return(cpu, 0u, stop_address); return;
    label_0003C7C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C7C0u);
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; g_sfera_mbc_runtime->argument_count = (uint32_t)((v)); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0003C7D0;
    cpu->ecx |= 0xFFFFFFFFu;
    sfera_sub_0043AFA0(cpu, stop_address); return;
    label_0003C7D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C7D0u);
    cpu->ecx = 0u;
    goto label_0003C500;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043C7E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43C7E0u);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003C7F8;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003C7F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C7F8u);
    cpu->edx = g_sfera_mbc_runtime->active_tag;
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(cpu->edx);
    cpu->edx = 1u;
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->edx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->edx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043C840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43C840u);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003C858;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003C858: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C858u);
    cpu->edx = g_sfera_mbc_runtime->argument_count;
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(cpu->edx);
    cpu->edx = 1u;
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->edx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->edx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043C8A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43C8A0u);
    cpu->eax = g_sfera_mbc_runtime->process_index;
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    cpu->edx = lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].module_tag));
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003C8C9;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003C8C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C8C9u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(cpu->edx);
    cpu->edx = 1u;
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->edx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->edx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043C910(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43C910u);
    cpu->eax = g_sfera_mbc_runtime->process_index;
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    cpu->edx = lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id));
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003C939;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003C939: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C939u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(cpu->edx);
    cpu->edx = 1u;
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->edx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->edx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043C980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43C980u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = 1u;
    lift_push32(cpu, cpu->edi);
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->argument_count) < (int32_t)(uint32_t)(cpu->esi)) goto label_0003CC86;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C9A9u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    g_sfera_mbc_runtime->argument_count -= cpu->esi;
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFEu)) goto label_0003C9CA;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C9BCu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    g_sfera_mbc_runtime->argument_count -= cpu->esi;
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    goto label_0003CAC3;
    label_0003C9CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C9CAu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFCu)) goto label_0003C9E2;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C9D4u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    g_sfera_mbc_runtime->argument_count -= cpu->esi;
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    goto label_0003CAC3;
    label_0003C9E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C9E2u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFBu)) goto label_0003C9FA;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43C9ECu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    g_sfera_mbc_runtime->argument_count -= cpu->esi;
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    goto label_0003CAC3;
    label_0003C9FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x43C9FAu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFF9u)) goto label_0003CAB1;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43CA08u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    g_sfera_mbc_runtime->argument_count -= cpu->esi;
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    cpu->eax = 0x100u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43CA1Bu); lift_push32(cpu, r); sfera_sub_004EEA10(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = g_sfera_mbc_runtime->argument_cursor;
    cpu->ebx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFF4u, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43CA33u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43CA38u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->eax);
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43CA45u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43CA4Au); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->eax);
    cpu->edi += g_sfera_mbc_runtime->process_memory_base;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43CA57u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->ebx + 1u, cpu->eax & 0xFFu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003CC9E;
    cpu->edx = (uint32_t)(cpu->ebx + 2u);
    lift_store8(cpu->ebx, 5u);
    cpu->eax = cpu->esi;
    cpu->edx -= cpu->esi;
    label_0003CA71: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CA71u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0003CA71;
    cpu->ecx = (uint32_t)(cpu->esi + 1u);
    cpu->edi = cpu->edi;
    label_0003CA80: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CA80u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    ++cpu->esi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0003CA80;
    cpu->esi -= cpu->ecx;
    cpu->edx = (uint32_t)(cpu->esi + cpu->ebx + 3u);
    cpu->eax = cpu->edi;
    cpu->edx -= cpu->edi;
    label_0003CA91: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CA91u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0003CA91;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    goto label_0003CAC3;
    label_0003CAB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CAB1u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_0003CC9E;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFDu)) goto label_0003CC9E;
    label_0003CAC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CAC3u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x3Du)) goto label_0003CC94;
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->edx = lift_load32(cpu->edx + 0xD0u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->esi = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->edx = (int8_t)(lift_load8(cpu->esi + 0x20u));
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esi);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->edx);
    if ((uint32_t)(cpu->edx) != (uint32_t)(0xFFFFFFFFu)) goto label_0003CAF7;
    cpu->ecx = (uint32_t)(uintptr_t)"Wrong flags for 'send' function";
    goto label_0003CC99;
    label_0003CAF7: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CAF7u);
    cpu->edi = 0u;
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->send_field_count = (uint32_t)(cpu->edi);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x1Cu)), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003CC65;
    label_0003CB0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CB0Au);
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->ebx = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0];
    cpu->eax = 1u;
    g_sfera_mbc_runtime->argument_cursor += cpu->eax;
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); g_sfera_mbc_runtime->argument_count = (uint32_t)((v)); }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_0003CC86;
    cpu->eax = (int8_t)(lift_load8(cpu->ecx + cpu->esi));
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(0x20u)) goto label_0003CB3D;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(0xFFFFFFE0u)) goto label_0003CB45;
    label_0003CB3D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CB3Du);
    cpu->edx = (uint32_t)(cpu->eax + 0xFFFFFF99u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(5u)) goto label_0003CB5C;
    label_0003CB45: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CB45u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    lift_store32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.send_field_data[0]), cpu->ebx);
    lift_store8(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->send_field_width[0]), cpu->eax & 0xFFu);
    goto label_0003CC4E;
    label_0003CB5C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CB5Cu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x65u)) goto label_0003CB7C;
    lift_store8(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->send_field_width[0]), 4u);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_0003CB70;
    cpu->ebx = 0u;
    goto label_0003CBA1;
    label_0003CB70: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CB70u);
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(0xFu)) goto label_0003CBA1;
    cpu->ebx = 0xFu;
    goto label_0003CBA1;
    label_0003CB7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CB7Cu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x66u)) goto label_0003CC4E;
    lift_store8(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->send_field_width[0]), 8u);
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_0003CB94;
    cpu->ebx = 0u;
    goto label_0003CBA1;
    label_0003CB94: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CB94u);
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(0xFFu)) goto label_0003CBA1;
    cpu->ebx = 0xFFu;
    label_0003CBA1: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CBA1u);
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; g_sfera_mbc_runtime->argument_count = (uint32_t)((v)); }
    lift_store32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.send_field_data[0]), cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_0003CC8D;
    ++cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFF4u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1Cu))) goto label_0003CC8D;
    cpu->eax = (int8_t)(lift_load8(cpu->ecx + cpu->esi));
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x20u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0003CC8D;
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->eax);
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type;
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (0xFu)) == 0u) goto label_0003CC8D;
    cpu->ecx = (uint32_t)(cpu->eax + 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43CBF7u); lift_push32(cpu, r); sfera_sub_00433BB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->edx = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0];
    cpu->edx += lift_load32(cpu->ecx + 0x50u);
    ++g_sfera_mbc_runtime->argument_cursor;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_0003CC48;
    label_0003CC15: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CC15u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp + 0xFFFFFFE8u)) & 0xFFu);
    ++cpu->edi;
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->send_field_count = (uint32_t)(cpu->edi);
    lift_store8(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->send_field_width[0]), cpu->eax & 0xFFu);
    lift_store32(((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.send_field_data[0]), cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_0003CC41;
    label_0003CC32: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CC32u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + cpu->edx)) & 0xFFu);
    lift_store8(cpu->ecx + ((uint32_t)(cpu->edi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.send_field_data[0]), cpu->eax & 0xFFu);
    ++cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->esi)) goto label_0003CC32;
    label_0003CC41: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CC41u);
    --cpu->ebx;
    cpu->edx += cpu->esi;
    if ((int32_t)(uint32_t)(cpu->ebx) > 0) goto label_0003CC15;
    label_0003CC48: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CC48u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFF0u);
    label_0003CC4E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CC4Eu);
    ++cpu->edi;
    ++cpu->ecx;
    g_sfera_mbc_runtime->send_field_count = (uint32_t)(cpu->edi);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi + 0x1Cu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003CB0A;
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    label_0003CC65: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CC65u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax;
    cpu->ecx = 0x190u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43CC72u); lift_push32(cpu, r); sfera_sub_00439C30(cpu,r); if (cpu->eip != r) return; }
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003CC86: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CC86u);
    cpu->ecx = (uint32_t)(uintptr_t)"Wrong number of parameters for 'send' function";
    goto label_0003CC99;
    label_0003CC8D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CC8Du);
    cpu->ecx = (uint32_t)(uintptr_t)"Wrong data for 'send' function";
    goto label_0003CC99;
    label_0003CC94: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CC94u);
    cpu->ecx = (uint32_t)(uintptr_t)"Wrong region for 'send' function";
    label_0003CC99: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CC99u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3CC9Eu); lift_push32(cpu, r); sfera_sub_004385D0(cpu,r); if (cpu->eip != r) return; }
    label_0003CC9E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CC9Eu);
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043CCC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43CCC0u);
    cpu->esp -= 0x38u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = 1u;
    lift_push32(cpu, cpu->edi);
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->argument_count) < (int32_t)(uint32_t)(cpu->esi)) goto label_0003D37C;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43CCDDu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    g_sfera_mbc_runtime->argument_count -= cpu->esi;
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x40u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(0x3Du)) goto label_0003D38D;
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u) + 0x1D8u);
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x44u, cpu->esi);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebp)) goto label_0003CD17;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003CD17: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CD17u);
    cpu->edx = lift_load32(cpu->esi);
    lift_store32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u) + 0x1D8u, cpu->edx);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    cpu->edi = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->eax = lift_load32(cpu->eax + 0xD0u);
    lift_store32(cpu->esp + 0x34u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 8u));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    cpu->edx = 0u;
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + 0x1Cu)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0003D322;
    label_0003CD68: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CD68u);
    cpu->eax = (int8_t)(lift_load8(cpu->edx + cpu->eax));
    cpu->ebx = 0u;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0003CDAA;
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    lift_push32(cpu, 4u);
    cpu->esi = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43CD8Eu); lift_push32(cpu, r); sfera_sub_004013D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = 0x20u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    goto label_0003D26E;
    label_0003CDAA: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CDAAu);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(0x20u)) goto label_0003CDD0;
    lift_push32(cpu, 4u); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43CDC7u); lift_push32(cpu, r); sfera_sub_004013D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    goto label_0003D26E;
    label_0003CDD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CDD0u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x67u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CFB5;
    cpu->eax = cpu->ebp;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->edx & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->ebp + 1u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + cpu->edi)), r=(uint64_t)((cpu->edx & 0xFFu)), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->edx = (uint32_t)(cpu->ebp + 1u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    lift_store8(cpu->esp + 0x2Cu, cpu->eax & 0xFFu);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx) * 8u));
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->eax & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    cpu->edx += cpu->edi;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edx)), r=(uint64_t)((cpu->eax & 0xFFu)), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CE27;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->edx;
    label_0003CE27: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CE27u);
    if ((uint8_t)((lift_load8(cpu->edx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_0003CE30;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) | (uint64_t)(2u))) & 0xFFu);
    goto label_0003CE33;
    label_0003CE30: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CE30u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFDu))) & 0xFFu);
    label_0003CE33: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CE33u);
    lift_store8(cpu->esp + 0x14u, cpu->ecx & 0xFFu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ebp += 3u;
    cpu->ecx = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CE99;
    cpu->edx = cpu->ebp;
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx) * 8u));
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->eax & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    cpu->edx += cpu->edi;
    { uint64_t l=(uint64_t)(lift_load8(cpu->edx)), r=(uint64_t)((cpu->eax & 0xFFu)), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CE64;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->edx;
    label_0003CE64: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CE64u);
    if ((uint8_t)((lift_load8(cpu->edx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_0003CE6D;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) | (uint64_t)(2u))) & 0xFFu);
    goto label_0003CE70;
    label_0003CE6D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CE6Du);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFDu))) & 0xFFu);
    label_0003CE70: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CE70u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CE77;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->edx;
    label_0003CE77: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CE77u);
    if ((uint8_t)((lift_load8(cpu->edx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_0003CE8A;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) | (uint64_t)(4u))) & 0xFFu);
    lift_store8(cpu->esp + 0x10u, cpu->ecx & 0xFFu);
    cpu->ebp += 3u;
    goto label_0003CF98;
    label_0003CE8A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CE8Au);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFBu))) & 0xFFu);
    lift_store8(cpu->esp + 0x10u, cpu->ecx & 0xFFu);
    cpu->ebp += 3u;
    goto label_0003CF98;
    label_0003CE99: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CE99u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CEE7;
    cpu->eax = cpu->ebp;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esi = (uint32_t)(cpu->eax + cpu->edi);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->edx & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    cpu->edi = 7u;
    cpu->edi = cpu->edi;
    label_0003CEC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CEC0u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003CEC8;
    lift_store8(cpu->ecx, (uint64_t)(lift_load8(cpu->ecx)) | (uint64_t)((cpu->eax & 0xFFu)));
    goto label_0003CECE;
    label_0003CEC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CEC8u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->ecx, (uint64_t)(lift_load8(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_0003CECE: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CECEu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CED5;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->ecx;
    label_0003CED5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CED5u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CEDC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_0003CEDC: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CEDCu);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CEC0;
    cpu->ebp += 7u;
    goto label_0003CF92;
    label_0003CEE7: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CEE7u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = cpu->ebp;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CF50;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esi = (uint32_t)(cpu->eax + cpu->edi);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->edx & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    cpu->edi = 7u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0003CF10: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CF10u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003CF18;
    lift_store8(cpu->ecx, (uint64_t)(lift_load8(cpu->ecx)) | (uint64_t)((cpu->eax & 0xFFu)));
    goto label_0003CF1E;
    label_0003CF18: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CF18u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->ecx, (uint64_t)(lift_load8(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_0003CF1E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CF1Eu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CF25;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->ecx;
    label_0003CF25: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CF25u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CF2C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_0003CF2C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CF2Cu);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003CF34;
    lift_store8(cpu->ecx, (uint64_t)(lift_load8(cpu->ecx)) | (uint64_t)((cpu->eax & 0xFFu)));
    goto label_0003CF3A;
    label_0003CF34: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CF34u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->ecx, (uint64_t)(lift_load8(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_0003CF3A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CF3Au);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CF41;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->ecx;
    label_0003CF41: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CF41u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CF48;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_0003CF48: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CF48u);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CF10;
    cpu->ebp += 0xEu;
    goto label_0003CF92;
    label_0003CF50: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CF50u);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esi = (uint32_t)(cpu->eax + cpu->edi);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->edx & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    cpu->edi = 0x1Fu;
    cpu->edi = cpu->edi;
    label_0003CF70: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CF70u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003CF78;
    lift_store8(cpu->ecx, (uint64_t)(lift_load8(cpu->ecx)) | (uint64_t)((cpu->eax & 0xFFu)));
    goto label_0003CF7E;
    label_0003CF78: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CF78u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->ecx, (uint64_t)(lift_load8(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_0003CF7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CF7Eu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CF85;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->ecx;
    label_0003CF85: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CF85u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CF8C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_0003CF8C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CF8Cu);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CF70;
    cpu->ebp += 0x1Fu;
    label_0003CF92: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CF92u);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->ebx = 0u;
    label_0003CF98: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CF98u);
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    if ((uint32_t)(lift_load32(cpu->esp + 0x2Cu)) == (uint32_t)(cpu->ebx)) goto label_0003D26E;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    goto label_0003D26E;
    label_0003CFB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CFB5u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x65u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D028;
    cpu->edx = cpu->ebp;
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx) * 8u));
    cpu->ecx = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->eax & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    cpu->edx += cpu->edi;
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edx)), r=(uint64_t)((cpu->eax & 0xFFu)), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CFE0;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->edx;
    label_0003CFE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CFE0u);
    if ((uint8_t)((lift_load8(cpu->edx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_0003CFE9;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) | (uint64_t)(2u))) & 0xFFu);
    goto label_0003CFEC;
    label_0003CFE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CFE9u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFDu))) & 0xFFu);
    label_0003CFEC: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CFECu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003CFF3;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->edx;
    label_0003CFF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CFF3u);
    if ((uint8_t)((lift_load8(cpu->edx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_0003CFFC;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) | (uint64_t)(4u))) & 0xFFu);
    goto label_0003CFFF;
    label_0003CFFC: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CFFCu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFBu))) & 0xFFu);
    label_0003CFFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x43CFFFu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D006;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->edx;
    label_0003D006: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D006u);
    if ((uint8_t)((lift_load8(cpu->edx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_0003D019;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) | (uint64_t)(8u))) & 0xFFu);
    lift_store8(cpu->esp + 0x18u, cpu->ecx & 0xFFu);
    cpu->ebp += 4u;
    goto label_0003D0D3;
    label_0003D019: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D019u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xF7u))) & 0xFFu);
    lift_store8(cpu->esp + 0x18u, cpu->ecx & 0xFFu);
    cpu->ebp += 4u;
    goto label_0003D0D3;
    label_0003D028: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D028u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x66u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D179;
    cpu->eax = cpu->ebp;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esi = (uint32_t)(cpu->eax + cpu->edi);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->edx & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    cpu->edi = 2u;
    label_0003D057: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D057u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003D05F;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_0003D065;
    label_0003D05F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D05Fu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_0003D065: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D065u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D06C;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_0003D06C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D06Cu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D073;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_0003D073: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D073u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003D07B;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_0003D081;
    label_0003D07B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D07Bu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_0003D081: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D081u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D088;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_0003D088: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D088u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D08F;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_0003D08F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D08Fu);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003D097;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_0003D09D;
    label_0003D097: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D097u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_0003D09D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D09Du);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D0A4;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_0003D0A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D0A4u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D0AB;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_0003D0AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D0ABu);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003D0B3;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_0003D0B9;
    label_0003D0B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D0B3u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_0003D0B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D0B9u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D0C0;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_0003D0C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D0C0u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D0C7;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_0003D0C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D0C7u);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D057;
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->ebp += 8u;
    cpu->ebx = 0u;
    label_0003D0D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D0D3u);
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(2u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); g_sfera_mbc_runtime->argument_count = (uint32_t)((v)); }
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_0003D37C;
    cpu->ecx = g_sfera_mbc_runtime->argument_cursor;
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->esi = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id;
    cpu->esi += lift_load32(cpu->edx + 0x50u);
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type;
    ++cpu->ecx;
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D112u); lift_push32(cpu, r); sfera_sub_00433BB0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003D125;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43D11Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43D122u);
    { uint64_t l=cpu->esp, r=(uint64_t)(0xCu), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    label_0003D125: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D125u);
    cpu->esi = g_sfera_mbc_runtime->argument_cursor;
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(5u), 32u);
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->esi >> 5u].type;
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (0xFu)) == 0u) goto label_0003D36B;
    cpu->ecx = (uint32_t)(cpu->eax + 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D144u); lift_push32(cpu, r); sfera_sub_00433BB0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->esi >> 5u].payload[0];
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    cpu->esi += lift_load32(cpu->ecx + 0x50u);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    cpu->eax = 1u;
    g_sfera_mbc_runtime->argument_cursor += cpu->eax;
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) != (uint32_t)(cpu->ebx)) goto label_0003D304;
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    goto label_0003D304;
    label_0003D179: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D179u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x69u)) goto label_0003D185;
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    goto label_0003D19B;
    label_0003D185: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D185u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x6Au)) goto label_0003D191;
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    goto label_0003D19B;
    label_0003D191: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D191u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x6Bu)) goto label_0003D1B3;
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    label_0003D19B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D19Bu);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D1A6u); lift_push32(cpu, r); sfera_sub_00437CB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    goto label_0003D26E;
    label_0003D1B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D1B3u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x6Cu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D26E;
    cpu->eax = cpu->ebp;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->esi = (uint32_t)(cpu->eax + cpu->edi);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->edx & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    cpu->edi = 2u;
    label_0003D1E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D1E2u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003D1EA;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_0003D1F0;
    label_0003D1EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D1EAu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_0003D1F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D1F0u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D1F7;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_0003D1F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D1F7u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D1FE;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_0003D1FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D1FEu);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003D206;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_0003D20C;
    label_0003D206: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D206u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_0003D20C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D20Cu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D213;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_0003D213: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D213u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D21A;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_0003D21A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D21Au);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003D222;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_0003D228;
    label_0003D222: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D222u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_0003D228: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D228u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D22F;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_0003D22F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D22Fu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D236;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_0003D236: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D236u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003D23E;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_0003D244;
    label_0003D23E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D23Eu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_0003D244: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D244u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D24B;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_0003D24B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D24Bu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D252;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_0003D252: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D252u);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D1E2;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->ebp += 8u;
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.02454369328916073));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0003D26E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D26Eu);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    { uint64_t v=(uint64_t)(cpu->ebx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D2D8;
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; g_sfera_mbc_runtime->argument_count = (uint32_t)((v)); }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_0003D37C;
    cpu->edx = g_sfera_mbc_runtime->argument_cursor;
    cpu->esi = g_sfera_mbc_runtime->active_process;
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->ecx = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id;
    cpu->ecx += lift_load32(cpu->esi + 0x50u);
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type;
    ++cpu->edx;
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->edx);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0003D2B2;
    cpu->eax = (uint32_t)(cpu->ebx + 1u);
    goto label_0003D2C3;
    label_0003D2B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D2B2u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(0xFu), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->eax) * 8u) + 4u);
    label_0003D2C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D2C3u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43D2CEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43D2D3u);
    cpu->esp += 0xCu;
    goto label_0003D304;
    label_0003D2D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D2D8u);
    cpu->esi = lift_load32(cpu->esp + 0x24u);
    --cpu->ebx;
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_0003D2F8;
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43D2F0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43D2F5u);
    cpu->esp += 0xCu;
    label_0003D2F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D2F8u);
    lift_store32(cpu->esp + 0x28u, (uint64_t)(lift_load32(cpu->esp + 0x28u)) + (uint64_t)(cpu->esi) + (uint64_t)(0u));
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_0003D304;
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) - 1u);
    label_0003D304: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D304u);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax = lift_load32(cpu->esp + 0x3Cu);
    ++cpu->edx;
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(lift_load32(cpu->eax + 0x1Cu))) goto label_0003CD68;
    cpu->ecx = lift_load32(cpu->esp + 0x40u);
    cpu->esi = lift_load32(cpu->esp + 0x44u);
    label_0003D322: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D322u);
    if ((uint8_t)((lift_load8(cpu->eax + 0x20u)) & (1u)) != 0u) goto label_0003D338;
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->edx = g_sfera_mbc_runtime->active_process;
    lift_store32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u) + 0xDCu, cpu->eax);
    label_0003D338: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D338u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D340u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, 0x1DE0u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D352u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1DE1u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D363u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    lift_return(cpu, 0u, stop_address); return;
    label_0003D36B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D36Bu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = (uint32_t)(uintptr_t)"Wrong data for 'receive' function";
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003D37C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D37Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = (uint32_t)(uintptr_t)"Wrong number of parameters for 'receive' function";
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003D38D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D38Du);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = (uint32_t)(uintptr_t)"Wrong region for 'receive' function";
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    sfera_sub_004385D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043D3A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43D3A0u);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003D3B8;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003D3B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D3B8u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->edx = 1u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(0u);
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->edx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->edx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043D400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43D400u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D406u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D40Du); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi -= cpu->eax;
    cpu->ecx = cpu->esi;
    cpu->eax = cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    cpu->esi = lift_pop32(cpu);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x3840u)) goto label_0003D432;
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_0003D42C;
    cpu->ecx += 0x8000u;
    goto label_0003D432;
    label_0003D42C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D42Cu);
    cpu->ecx -= 0x8000u;
    label_0003D432: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D432u);
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003D44A;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003D44A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D44Au);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(cpu->ecx);
    cpu->ecx = 1u;
    cpu->edx += cpu->ecx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->ecx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043D490(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43D490u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D495u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003D4B4;
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0003D4AD;
    cpu->ecx = lift_load32((uintptr_t)&g_sfera_mbc_static_runtime.profile_fallback);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003D4AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D4ADu);
    cpu->ecx = 0u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003D4B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D4B4u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043D4C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43D4C0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D4C7u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D4CEu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_load32(cpu->eax);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003D4E0;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D4DEu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    goto label_0003D4E2;
    label_0003D4E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D4E0u);
    cpu->eax = 0u;
    label_0003D4E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D4E2u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = (uint32_t)(cpu->eax + cpu->edi);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D4F3u); lift_push32(cpu, r); sfera_sub_00433470(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003D50D;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003D50D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D50Du);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].payload[0] = (uint32_t)(cpu->eax);
    cpu->eax = 1u;
    cpu->edx += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_end = (uint32_t)(cpu->eax);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_begin = (uint32_t)(cpu->eax);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043D550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43D550u);
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->edx = lift_load32(cpu->eax + 0x94u);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->edx &= 4u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003D576;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003D576: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D576u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(cpu->edx);
    cpu->edx = 1u;
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->edx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->edx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043D5B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43D5B0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D5B7u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D5BEu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esi);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_0003D5CC;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_0003D5DC;
    label_0003D5CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D5CCu);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0003D649;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_0003D5DC;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0003D649;
    label_0003D5DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D5DCu);
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D5E6u); lift_push32(cpu, r); sfera_sub_00434AF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D606u); lift_push32(cpu, r); sfera_sub_0049B7F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->esp += 0x18u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0003D69E;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0003D69E;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0003D629;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0003D69E;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_0003D629: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D629u);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0003D637;
    lift_store32(cpu->esi + 4u, cpu->eax);
    ++g_sfera_mbc_runtime->value_stack_size;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003D637: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D637u);
    --cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0003D69E;
    lift_store32(cpu->esi + 8u, cpu->eax);
    ++g_sfera_mbc_runtime->value_stack_size;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003D649: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D649u);
    cpu->eax = 0u;
    if ((uint32_t)(g_sfera_mbc_runtime->argument_count) != (uint32_t)(3u)) goto label_0003D659;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3D659u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    label_0003D659: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D659u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003D6A4;
    cpu->edx = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx += cpu->eax;
    cpu->ecx += cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D675u); lift_push32(cpu, r); sfera_sub_00433FF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_0003D681;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(4u)) goto label_0003D695;
    label_0003D681: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D681u);
    cpu->edx = lift_load32(cpu->edi + 4u);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0003D69E;
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->edx)) goto label_0003D695;
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->eax + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_0003D69E;
    label_0003D695: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D695u);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3D69Eu); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    label_0003D69E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D69Eu);
    ++g_sfera_mbc_runtime->value_stack_size;
    label_0003D6A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D6A4u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043D6B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43D6B0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D6B8u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D6BFu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D6C6u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    cpu->eax = lift_load32(cpu->esi);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_0003D6D4;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_0003D6E4;
    label_0003D6D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D6D4u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0003D757;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_0003D6E4;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0003D757;
    label_0003D6E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D6E4u);
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D6EEu); lift_push32(cpu, r); sfera_sub_00434AF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D70Eu); lift_push32(cpu, r); sfera_sub_0049B7F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->esp += 0x18u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0003D7B4;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0003D7B4;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0003D735;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0003D7B4;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_0003D735: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D735u);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0003D744;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 4u, cpu->eax);
    ++g_sfera_mbc_runtime->value_stack_size;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003D744: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D744u);
    --cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0003D7B4;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 8u, cpu->eax);
    ++g_sfera_mbc_runtime->value_stack_size;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003D757: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D757u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003D7BA;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->esi = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->ebx);
    cpu->eax += cpu->ecx;
    cpu->esi += cpu->ecx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x43D76Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43D775u);
    cpu->eax = cpu->esi;
    cpu->esp += 0xCu;
    lift_store8(cpu->esi + cpu->ebx, 0u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0003D781: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D781u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0003D781;
    cpu->eax -= cpu->edx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->eax = lift_load32(cpu->edi);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_0003D799;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_0003D7AD;
    label_0003D799: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D799u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0003D7B4;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_0003D7AD;
    cpu->eax = (uint32_t)(cpu->eax + cpu->edx + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_0003D7B4;
    label_0003D7AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D7ADu);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3D7B4u); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    label_0003D7B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D7B4u);
    ++g_sfera_mbc_runtime->value_stack_size;
    label_0003D7BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D7BAu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043D7C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43D7C0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D7C8u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D7CFu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->edi);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_0003D7DD;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_0003D7ED;
    label_0003D7DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D7DDu);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0003D854;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_0003D7ED;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_0003D854;
    label_0003D7ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D7EDu);
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D7F7u); lift_push32(cpu, r); sfera_sub_00434AF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 8u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->edx = lift_load32(cpu->edi);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D817u); lift_push32(cpu, r); sfera_sub_0049B7F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi);
    cpu->esp += 0x18u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0003D84A;
    cpu->ecx = lift_load32(cpu->edi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0003D84A;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0003D832;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->edi + 8u))) goto label_0003D84A;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_0003D832: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D832u);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0003D841;
    lift_store32(cpu->edi + 4u, cpu->eax);
    ++g_sfera_mbc_runtime->value_stack_size;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003D841: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D841u);
    --cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(lift_load32(cpu->edi + 8u))) goto label_0003D84A;
    lift_store32(cpu->edi + 8u, cpu->eax);
    label_0003D84A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D84Au);
    ++g_sfera_mbc_runtime->value_stack_size;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003D854: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D854u);
    cpu->ecx = lift_load32(cpu->esi);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_0003D860;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(4u)) goto label_0003D870;
    label_0003D860: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D860u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0003D8C7;
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->eax)) goto label_0003D870;
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0003D8C7;
    label_0003D870: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D870u);
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D87Au); lift_push32(cpu, r); sfera_sub_00434AF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D89Au); lift_push32(cpu, r); sfera_sub_0049B7F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi);
    cpu->esp += 0x18u;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0003D8C7;
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0003D8C7;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0003D8B5;
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0003D8C7;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_0003D8B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D8B5u);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0003D8BC;
    lift_store32(cpu->esi + 4u, cpu->ecx);
    goto label_0003D8C7;
    label_0003D8BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D8BCu);
    cpu->eax = (uint32_t)(cpu->ecx + 0xFFFFFFFFu);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0003D8C7;
    lift_store32(cpu->esi + 8u, cpu->eax);
    label_0003D8C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D8C7u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi = lift_load32(cpu->edi);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = (uint32_t)(cpu->ecx + cpu->eax);
    cpu->edi += cpu->eax;
    cpu->eax = cpu->ebp;
    cpu->ebx = (uint32_t)(cpu->eax + 1u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0003D8E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D8E0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0003D8E0;
    cpu->eax -= cpu->ebx;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->eax = cpu->edi;
    cpu->ebx = (uint32_t)(cpu->eax + 1u);
    label_0003D8F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D8F2u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0003D8F2;
    cpu->eax -= cpu->ebx;
    cpu->ebx = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_0003D907;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(4u)) goto label_0003D923;
    label_0003D907: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D907u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0003D932;
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->eax)) goto label_0003D923;
    cpu->eax = (uint32_t)(cpu->ecx + cpu->ebx + 1u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = (uint32_t)(cpu->eax + cpu->ecx + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->edx) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0003D932;
    label_0003D923: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D923u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = (uint32_t)(cpu->ebx + cpu->eax + 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3D932u); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    label_0003D932: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D932u);
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->argument_count) <= (int32_t)(uint32_t)(2u)) goto label_0003D96A;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D940u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = (uint32_t)(cpu->ebx + cpu->ecx + 1u);
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(cpu->eax)) goto label_0003D96A;
    lift_push32(cpu, (uintptr_t)"Size mismatch: ffstrcat\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D95Bu); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    ++g_sfera_mbc_runtime->value_stack_size;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003D96A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D96Au);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003D9A6;
    ++g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = cpu->edi;
    cpu->ecx = cpu->edi;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0003D980: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D980u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0003D980;
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    cpu->edi = (uint32_t)(cpu->ebp + 0xFFFFFFFFu);
    cpu->edi = cpu->edi;
    label_0003D990: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D990u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003D990;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    label_0003D9A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x43D9A6u);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043D9B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43D9B0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D9B9u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43D9C0u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003DA00;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax += cpu->edx;
    cpu->ecx += cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_strstr_address32(), LIFT_CODE_TOKEN_VA(0x43D9D9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43D9DFu);
    cpu->esp += 8u;
    cpu->edx = 1u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0003DA05;
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3DA00u); lift_push32(cpu, r); sfera_sub_0043AF30(cpu,r); if (cpu->eip != r) return; }
    label_0003DA00: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DA00u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
    label_0003DA05: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DA05u);
    cpu->eax -= g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi, cpu->eax);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    sfera_sub_0043AF30(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043DA20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43DA20u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DA29u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DA30u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003DA69;
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx += cpu->eax;
    cpu->ecx += cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DA4Bu); lift_push32(cpu, r); sfera_sub_004ED620(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 1u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0003DA6E;
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3DA69u); lift_push32(cpu, r); sfera_sub_0043AF30(cpu,r); if (cpu->eip != r) return; }
    label_0003DA69: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DA69u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
    label_0003DA6E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DA6Eu);
    cpu->eax -= g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi, cpu->eax);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    sfera_sub_0043AF30(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043DA90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43DA90u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DA98u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi += cpu->eax;
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->eax)) goto label_0003DAB7;
    lift_push32(cpu, (uintptr_t)"ffstrlen(): NULL-pointer dereferencing\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DAB4u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_0003DAB7: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DAB7u);
    cpu->ebx = 1u;
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->argument_count) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0003DAF5;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DAC9u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_0003DADC;
    (void)cpu;
    label_0003DAD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DAD0u);
    if ((uint8_t)(lift_load8(cpu->esi + cpu->edi)) == (uint8_t)(0u)) goto label_0003DADC;
    cpu->esi += cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->eax)) goto label_0003DAD0;
    label_0003DADC: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DADCu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->eax)) goto label_0003DB0B;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"ffstrlen(): end of string was not found in buffer of size %d\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DAF0u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    goto label_0003DB0B;
    label_0003DAF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DAF5u);
    cpu->eax = cpu->edi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0003DB00: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DB00u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0003DB00;
    cpu->eax -= cpu->edx;
    cpu->esi = cpu->eax;
    label_0003DB0B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DB0Bu);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003DB7B;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DB1Eu); lift_push32(cpu, r); sfera_sub_00434D90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"\n---exit_inter start---\nMBINTER MESSAGE:";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DB28u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DB32u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"\n";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DB3Cu); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DB46u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"---exit_inter end-----\n";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DB50u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->process_index), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    g_sfera_mbc_runtime->execution_failed = (uint32_t)(cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003DB69;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3DB69u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0003DB69: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DB69u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->edx = (uint32_t)(uintptr_t)"EError";
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0];
    cpu->ebx = lift_pop32(cpu);
    sfera_sub_00435020(cpu, stop_address); return;
    label_0003DB7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DB7Bu);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(cpu->esi);
    cpu->edi = lift_pop32(cpu);
    cpu->ecx += cpu->ebx;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->ebx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->ebx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043DBC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43DBC0u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DBC6u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DBCDu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(cpu->edx + cpu->eax);
    cpu->eax = (uint32_t)(cpu->edx + cpu->esi);
    cpu->esi = lift_pop32(cpu);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0003DBE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DBE0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003DC00;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_0003DBFC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003DC00;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0003DBE0;
    label_0003DBFC: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DBFCu);
    cpu->ecx = 0u;
    goto label_0003DC05;
    label_0003DC00: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DC00u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = (uint64_t)(cpu->ecx) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_0003DC05: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DC05u);
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003DC1D;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003DC1D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DC1Du);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(cpu->ecx);
    cpu->ecx = 1u;
    cpu->edx += cpu->ecx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->ecx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043DC60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43DC60u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DC66u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DC6Du); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax += cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx += cpu->esi;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x43DC79u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43DC7Fu);
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    cpu->esp += 8u;
    cpu->esi = lift_pop32(cpu);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003DC9B;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003DC9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DC9Bu);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].payload[0] = (uint32_t)(cpu->eax);
    cpu->eax = 1u;
    cpu->edx += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_end = (uint32_t)(cpu->eax);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_begin = (uint32_t)(cpu->eax);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043DCE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43DCE0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DCE7u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DCEEu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DCF5u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(cpu->eax + cpu->edi);
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->esi;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strncmp), LIFT_CODE_TOKEN_VA(0x43DD02u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43DD08u);
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003DD25;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003DD25: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DD25u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].payload[0] = (uint32_t)(cpu->eax);
    cpu->eax = 1u;
    cpu->edx += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_end = (uint32_t)(cpu->eax);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_begin = (uint32_t)(cpu->eax);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043DD60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43DD60u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DD67u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DD6Eu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DD75u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(cpu->eax + cpu->edi);
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->esi;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_strnicmp), LIFT_CODE_TOKEN_VA(0x43DD82u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43DD88u);
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003DDA5;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003DDA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DDA5u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].payload[0] = (uint32_t)(cpu->eax);
    cpu->eax = 1u;
    cpu->edx += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_end = (uint32_t)(cpu->eax);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_begin = (uint32_t)(cpu->eax);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043DDE0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_0003DDE0;
    label_000341F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4341F0u);
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034207;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_00034207: cpu->eip = LIFT_CODE_TOKEN_VA(0x434207u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\script.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x43420Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434213u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0003423D;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->esi);
    g_sfera_log_first_write = (uint32_t)(0u);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x43422Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434233u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x434234u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43423Au);
    cpu->esp += 0x10u;
    label_0003423D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43423Du);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000342F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4342F0u);
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034307;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_00034307: cpu->eip = LIFT_CODE_TOKEN_VA(0x434307u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\deletings.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x43430Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434313u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00034333;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x434323u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434329u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x43432Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434330u);
    cpu->esp += 0x10u;
    label_00034333: cpu->eip = LIFT_CODE_TOKEN_VA(0x434333u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000343E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4343E0u);
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000343F7;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_000343F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4343F7u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\gm.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4343FDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434403u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00034423;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x434413u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434419u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x43441Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434420u);
    cpu->esp += 0x10u;
    label_00034423: cpu->eip = LIFT_CODE_TOKEN_VA(0x434423u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000344D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4344D0u);
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000344E7;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_000344E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4344E7u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\trade.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4344EDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4344F3u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00034513;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x434503u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434509u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x43450Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434510u);
    cpu->esp += 0x10u;
    label_00034513: cpu->eip = LIFT_CODE_TOKEN_VA(0x434513u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00034570: cpu->eip = LIFT_CODE_TOKEN_VA(0x434570u);
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034587;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_00034587: cpu->eip = LIFT_CODE_TOKEN_VA(0x434587u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\violations.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x43458Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434593u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000345AE;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x43459Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4345A4u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4345A5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4345ABu);
    cpu->esp += 0xCu;
    label_000345AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4345AEu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000345C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4345C0u);
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000345D7;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_000345D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4345D7u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\violations.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4345DDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4345E3u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00034603;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x4345F3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4345F9u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4345FAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434600u);
    cpu->esp += 0x10u;
    label_00034603: cpu->eip = LIFT_CODE_TOKEN_VA(0x434603u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000346A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4346A0u);
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000346B7;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_000346B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4346B7u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4346B9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4346BFu);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000346DF;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x4346CFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4346D5u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4346D6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4346DCu);
    cpu->esp += 0x10u;
    label_000346DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4346DFu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003DDE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DDE0u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type;
    lift_push32(cpu, cpu->esi);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (0xFu)) == 0u) goto label_0003DF48;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DDFDu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003E0EC;
    if ((uint32_t)(g_sfera_mbc_runtime->argument_count) != (uint32_t)(2u)) goto label_0003DF36;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DE1Eu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_0003DE34;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_004342A0(cpu, stop_address); return;
    label_0003DE34: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DE34u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(2u)) goto label_0003DE4B;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->esi);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434390(cpu, stop_address); return;
    label_0003DE4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DE4Bu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(3u)) goto label_0003DE62;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->esi);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434480(cpu, stop_address); return;
    label_0003DE62: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DE62u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(9u)) goto label_0003DE7E;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = (uint32_t)(cpu->edx + cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\goldtaler";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434660(cpu, stop_address); return;
    label_0003DE7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DE7Eu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xAu)) goto label_0003DE99;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx += cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\mstatin";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434660(cpu, stop_address); return;
    label_0003DE99: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DE99u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xBu)) goto label_0003DEB5;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = (uint32_t)(cpu->edx + cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\mstatout";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434660(cpu, stop_address); return;
    label_0003DEB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DEB5u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xCu)) goto label_0003DED1;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = (uint32_t)(cpu->edx + cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\gtstatin";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434660(cpu, stop_address); return;
    label_0003DED1: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DED1u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xDu)) goto label_0003DEEC;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx += cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\gtstatout";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434660(cpu, stop_address); return;
    label_0003DEEC: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DEECu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xEu)) goto label_0003DF08;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = (uint32_t)(cpu->edx + cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\bigmoney";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434660(cpu, stop_address); return;
    label_0003DF08: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DF08u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFu)) goto label_0003DF24;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = (uint32_t)(cpu->edx + cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\chat";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434660(cpu, stop_address); return;
    label_0003DF24: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DF24u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->esi);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_00034570;
    label_0003DF36: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DF36u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->esi);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_004341A0(cpu, stop_address); return;
    label_0003DF48: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DF48u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x20u)) goto label_0003E026;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DF56u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003E0EC;
    if ((uint32_t)(g_sfera_mbc_runtime->argument_count) != (uint32_t)(2u)) goto label_0003E01B;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43DF77u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_0003DF87;
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000342F0;
    label_0003DF87: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DF87u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(2u)) goto label_0003DF97;
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000343E0;
    label_0003DF97: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DF97u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(3u)) goto label_0003DFA7;
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000344D0;
    label_0003DFA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DFA7u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(9u)) goto label_0003DFBC;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\goldtaler";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000346A0;
    label_0003DFBC: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DFBCu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xAu)) goto label_0003DFD1;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\mstatin";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000346A0;
    label_0003DFD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DFD1u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xBu)) goto label_0003DFE6;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\mstatout";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000346A0;
    label_0003DFE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DFE6u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xEu)) goto label_0003DFFB;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\bigmoney";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000346A0;
    label_0003DFFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x43DFFBu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFu)) goto label_0003E010;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\chat";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000346A0;
    label_0003E010: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E010u);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000345C0;
    label_0003E01B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E01Bu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_000341F0;
    label_0003E026: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E026u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E02Bu); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003E0EC;
    if ((uint32_t)(g_sfera_mbc_runtime->argument_count) != (uint32_t)(2u)) goto label_0003E0DF;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E04Eu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_0003E063;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E060u); lift_push32(cpu, r); sfera_sub_00434340(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003E063: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E063u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(2u)) goto label_0003E070;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E06Du); lift_push32(cpu, r); sfera_sub_00434430(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003E070: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E070u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(3u)) goto label_0003E07D;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E07Au); lift_push32(cpu, r); sfera_sub_00434520(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003E07D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E07Du);
    if ((uint32_t)(cpu->eax) != (uint32_t)(9u)) goto label_0003E08F;
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\goldtaler";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E08Cu); lift_push32(cpu, r); sfera_sub_004346F0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003E08F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E08Fu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xAu)) goto label_0003E0A1;
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\mstatin";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E09Eu); lift_push32(cpu, r); sfera_sub_004346F0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003E0A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E0A1u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xBu)) goto label_0003E0B3;
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\mstatout";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E0B0u); lift_push32(cpu, r); sfera_sub_004346F0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003E0B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E0B3u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xEu)) goto label_0003E0C5;
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\bigmoney";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E0C2u); lift_push32(cpu, r); sfera_sub_004346F0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003E0C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E0C5u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFu)) goto label_0003E0D7;
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\chat";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E0D4u); lift_push32(cpu, r); sfera_sub_004346F0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003E0D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E0D7u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E0DCu); lift_push32(cpu, r); sfera_sub_00434610(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003E0DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E0DFu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3E0ECu); lift_push32(cpu, r); sfera_sub_00434240(cpu,r); if (cpu->eip != r) return; }
    label_0003E0EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E0ECu);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043E0F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43E0F0u);
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003E20A;
    lift_push32(cpu, cpu->esi);
    label_0003E101: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E101u);
    cpu->esi = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax = cpu->esi;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->ecx = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type;
    if ((uint8_t)(((cpu->ecx & 0xFFu)) & (0xFu)) == 0u) goto label_0003E1D7;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_mbc_runtime->argument_end)) goto label_0003E197;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E128u); lift_push32(cpu, r); sfera_sub_00434D90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"\n---exit_inter start---\nMBINTER MESSAGE:";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E132u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"Too few parameters";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E13Cu); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"\n";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E146u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E150u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"---exit_inter end-----\n";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E15Au); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->process_index), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    g_sfera_mbc_runtime->execution_failed = (uint32_t)(1u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003E177;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3E177u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0003E177: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E177u);
    cpu->edx = (uint32_t)(uintptr_t)"EError";
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E186u); lift_push32(cpu, r); sfera_sub_00435020(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = 0u;
    cpu->ecx += cpu->eax;
    lift_store32(cpu->edi, cpu->ecx);
    cpu->edi += 4u;
    goto label_0003E1F6;
    label_0003E197: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E197u);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0x10u)) goto label_0003E1BB;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x20u)) goto label_0003E1AE;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0]));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E1ACu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    goto label_0003E1C1;
    label_0003E1AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E1AEu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0003E1BB;
    cpu->eax = (int8_t)(((uint8_t)g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0]));
    goto label_0003E1C1;
    label_0003E1BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E1BBu);
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0];
    label_0003E1C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E1C1u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    ++cpu->esi;
    cpu->ecx += cpu->eax;
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->esi);
    lift_store32(cpu->edi, cpu->ecx);
    cpu->edi += 4u;
    goto label_0003E1F6;
    label_0003E1D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E1D7u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0x10u)) goto label_0003E1E0;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_0003E1EC;
    label_0003E1E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E1E0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E1E5u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi, cpu->eax);
    cpu->edi += 4u;
    goto label_0003E1F6;
    label_0003E1EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E1ECu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E1F1u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f64(cpu->edi, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    cpu->edi += 8u;
    label_0003E1F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E1F6u);
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    --cpu->eax;
    g_sfera_mbc_runtime->argument_count = (uint32_t)(cpu->eax);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0003E101;
    cpu->esi = lift_pop32(cpu);
    label_0003E20A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E20Au);
    ++g_sfera_mbc_runtime->value_stack_size;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043E220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43E220u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 1u;
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003E267;
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x10u)) goto label_0003E257;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0003E267;
    label_0003E257: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E257u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E25Cu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    g_sfera_mbc_runtime->argument_count -= cpu->edi;
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    goto label_0003E26E;
    label_0003E267: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E267u);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 0u);
    label_0003E26E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E26Eu);
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->argument_count) >= (int32_t)(uint32_t)(cpu->edi)) goto label_0003E280;
    cpu->ecx = (uint32_t)(uintptr_t)"Invalid parameter list: fflogf()";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3E280u); lift_push32(cpu, r); sfera_sub_004385D0(cpu,r); if (cpu->eip != r) return; }
    label_0003E280: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E280u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E285u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->ebp + 0xFFFFFFF4u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003E4AA;
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    cpu->eax -= cpu->edi;
    g_sfera_mbc_runtime->argument_count = (uint32_t)(cpu->eax);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E2B4u); lift_push32(cpu, r); sfera_sub_004EEA10(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->esp;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E2BDu); lift_push32(cpu, r); sfera_sub_0043E0F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_vscprintf), LIFT_CODE_TOKEN_VA(0x43E2BFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E2C5u);
    cpu->esi = (uint32_t)(cpu->edi + cpu->eax);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) <= (uint32_t)(0x1000u)) goto label_0003E2D8;
    cpu->esi = 0x1000u;
    label_0003E2D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E2D8u);
    cpu->eax = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E2DFu); lift_push32(cpu, r); sfera_sub_004EEA10(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    cpu->edi = cpu->esp;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_vsnprintf), LIFT_CODE_TOKEN_VA(0x43E2E8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E2EEu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->esp += 0x10u;
    lift_store8(cpu->edi + cpu->esi + 0xFFFFFFFFu, 0u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x10u)) goto label_0003E470;
    switch ((uint32_t)(cpu->eax)) {
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E310u); lift_push32(cpu, r); sfera_sub_004341A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003E324: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E324u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E32Bu); lift_push32(cpu, r); sfera_sub_004342A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003E33F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E33Fu);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E346u); lift_push32(cpu, r); sfera_sub_00434390(cpu,r); if (cpu->eip != r) return; }
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003E35A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E35Au);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E361u); lift_push32(cpu, r); sfera_sub_00434480(cpu,r); if (cpu->eip != r) return; }
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003E375: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E375u);
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\goldtaler";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E381u); lift_push32(cpu, r); sfera_sub_00434660(cpu,r); if (cpu->eip != r) return; }
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003E395: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E395u);
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\mstatin";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E3A1u); lift_push32(cpu, r); sfera_sub_00434660(cpu,r); if (cpu->eip != r) return; }
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003E3B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E3B5u);
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\mstatout";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E3C1u); lift_push32(cpu, r); sfera_sub_00434660(cpu,r); if (cpu->eip != r) return; }
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003E3D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E3D5u);
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\gtstatin";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E3E1u); lift_push32(cpu, r); sfera_sub_00434660(cpu,r); if (cpu->eip != r) return; }
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003E3F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E3F5u);
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\gtstatout";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E401u); lift_push32(cpu, r); sfera_sub_00434660(cpu,r); if (cpu->eip != r) return; }
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003E415: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E415u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E41Cu); lift_push32(cpu, r); sfera_sub_00434740(cpu,r); if (cpu->eip != r) return; }
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003E430: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E430u);
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\old_things";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E43Cu); lift_push32(cpu, r); sfera_sub_00434660(cpu,r); if (cpu->eip != r) return; }
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003E450: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E450u);
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\add_exp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E45Cu); lift_push32(cpu, r); sfera_sub_00434660(cpu,r); if (cpu->eip != r) return; }
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003E470: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E470u);
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003E483;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_0003E483: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E483u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\violations.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x43E489u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E48Fu);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0003E4AA;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x43E49Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E4A0u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x43E4A1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E4A7u);
    cpu->esp += 0xCu;
    label_0003E4AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E4AAu);
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043E510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43E510u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = (uint32_t)(cpu->esp + 0xFFFFFE68u);
    cpu->esp -= 0x218u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 1u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store8(cpu->ebp + 0xFFFFFF83u, 0u);
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003E564;
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x10u)) goto label_0003E556;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0003E564;
    label_0003E556: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E556u);
    lift_store8(cpu->ebp + 0xFFFFFF83u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E55Eu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    g_sfera_mbc_runtime->argument_count -= cpu->ebx;
    label_0003E564: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E564u);
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->argument_count) >= (int32_t)(uint32_t)(2u)) goto label_0003E577;
    cpu->ecx = (uint32_t)(uintptr_t)"Invalid parameter list: ffflogf()";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3E577u); lift_push32(cpu, r); sfera_sub_004385D0(cpu,r); if (cpu->eip != r) return; }
    label_0003E577: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E577u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E57Cu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->esi += cpu->eax;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->eax)) goto label_0003E59B;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffflogf, pchFileName\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E598u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_0003E59B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E59Bu);
    g_sfera_mbc_runtime->argument_count -= cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E5A6u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi += cpu->eax;
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->eax)) goto label_0003E5C5;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffflogf, pchFormatString\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E5C2u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_0003E5C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E5C5u);
    g_sfera_mbc_runtime->argument_count -= cpu->ebx;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003E69E;
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E5E8u); lift_push32(cpu, r); sfera_sub_004EEA10(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->esp;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E5F1u); lift_push32(cpu, r); sfera_sub_0043E0F0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(lift_load8(cpu->ebp + 0xFFFFFF83u)) == (uint8_t)(0u)) goto label_0003E603;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF94u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E601u); lift_push32(cpu, r); sfera_sub_004340E0(cpu,r); if (cpu->eip != r) return; }
    goto label_0003E61A;
    label_0003E603: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E603u);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFF94u);
    cpu->eax = cpu->esi;
    cpu->edx -= cpu->esi;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0003E610: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E610u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0003E610;
    label_0003E61A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E61Au);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF94u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"logs\\%s");
    cpu->edx = (uint32_t)(cpu->ebp + 0x94u);
    lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x43E62Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E635u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x94u);
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->eax);
    lift_store8(cpu->ebp + 0x193u, 0u);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x43E648u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E64Eu);
    cpu->esi = cpu->eax;
    cpu->esp += 0x18u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0003E69E;
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFF84u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::GetLocalTime), LIFT_CODE_TOKEN_VA(0x43E65Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E661u);
    cpu->edx = lift_load16(cpu->ebp + 0xFFFFFF90u);
    cpu->eax = lift_load16(cpu->ebp + 0xFFFFFF8Eu);
    cpu->ecx = lift_load16(cpu->ebp + 0xFFFFFF8Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load16(cpu->ebp + 0xFFFFFF84u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load16(cpu->ebp + 0xFFFFFF86u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load16(cpu->ebp + 0xFFFFFF8Au);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%02u.%02u.%04u %02u:%02u:%02u "); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x43E685u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E68Bu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::vfprintf), LIFT_CODE_TOKEN_VA(0x43E68Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E694u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x43E695u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E69Bu);
    cpu->esp += 0x30u;
    label_0003E69E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E69Eu);
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFF74u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = (uint32_t)(cpu->ebp + 0x198u);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043E6C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43E6C0u);
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type;
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (0xFu)) == 0u) goto label_0003E6D7;
    sfera_sub_0043ACF0(cpu, stop_address); return;
    label_0003E6D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E6D7u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x20u)) goto label_0003E6E1;
    sfera_sub_0043ACF0(cpu, stop_address); return;
    label_0003E6E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E6E1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E6E6u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043E6F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43E6F0u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E6F6u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_0003E70E;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffcreate\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E70Bu); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_0003E70E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E70Eu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003E77C;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax += cpu->esi;
    lift_push32(cpu, 0x180u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_chmod), LIFT_CODE_TOKEN_VA(0x43E724u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E72Au);
    cpu->esp += 8u;
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, 0x180u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003E74B;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, 0x8102u);
    cpu->ecx += cpu->esi;
    lift_push32(cpu, cpu->ecx);
    goto label_0003E759;
    label_0003E74B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E74Bu);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, 0x8302u);
    cpu->edx += cpu->esi;
    lift_push32(cpu, cpu->edx);
    label_0003E759: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E759u);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x43E759u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E75Fu);
    cpu->esi = cpu->eax;
    cpu->esp += 0xCu;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E76Bu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0003E77C;
    cpu->ecx = cpu->esi;
    cpu->edx = 1u;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_00437A10(cpu, stop_address); return;
    label_0003E77C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E77Cu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043E780(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43E780u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0x8002u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E78Cu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_0003E7A4;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffopen\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E7A1u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_0003E7A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E7A4u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax += cpu->esi;
    lift_push32(cpu, 0x180u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_chmod), LIFT_CODE_TOKEN_VA(0x43E7B1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E7B7u);
    cpu->esp += 8u;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003E830;
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->argument_count) <= (int32_t)(uint32_t)(1u)) goto label_0003E7DB;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E7D1u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_0003E80B;
    cpu->edi = 0x8000u;
    label_0003E7DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E7DBu);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, 0u);
    cpu->edx += cpu->esi;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x43E7E7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E7EDu);
    cpu->esp += 0xCu;
    label_0003E7F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E7F0u);
    cpu->esi = cpu->eax;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E7F9u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0003E830;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->edx = 1u;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_00437A10(cpu, stop_address); return;
    label_0003E80B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E80Bu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(3u)) goto label_0003E7DB;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, 0x180u); lift_push32(cpu, 0x40u);
    cpu->ecx += cpu->esi;
    lift_push32(cpu, 0x8002u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_sopen), LIFT_CODE_TOKEN_VA(0x43E825u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E82Bu);
    cpu->esp += 0x10u;
    goto label_0003E7F0;
    label_0003E830: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E830u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043E840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43E840u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E847u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E84Eu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E855u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003E88D;
    lift_push32(cpu, cpu->eax);
    if ((uint32_t)(cpu->edi) != 0u) goto label_0003E878;
    lift_push32(cpu, 2u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_locking), LIFT_CODE_TOKEN_VA(0x43E866u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E86Cu);
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003E878: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E878u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_locking), LIFT_CODE_TOKEN_VA(0x43E87Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E881u);
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003E88D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E88Du);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043E890(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43E890u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E896u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003E8BD;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0003E8BD;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x43E8A6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E8ACu);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = 1u;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3E8BDu); lift_push32(cpu, r); sfera_sub_00437B10(cpu,r); if (cpu->eip != r) return; }
    label_0003E8BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E8BDu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043E8C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43E8C0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E8C9u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E8D0u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->edi = lift_load32(cpu->esi);
    cpu->edi += g_sfera_mbc_runtime->process_memory_base;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E8DFu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003E939;
    cpu->eax = lift_load32(cpu->esi);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_0003E8F6;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_0003E90A;
    label_0003E8F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E8F6u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0003E913;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_0003E90A;
    cpu->eax = (uint32_t)(cpu->eax + cpu->ebx + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0003E913;
    label_0003E90A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E90Au);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3E913u); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    label_0003E913: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E913u);
    if ((int32_t)(uint32_t)(cpu->ebp) < 0) goto label_0003E92E;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_write), LIFT_CODE_TOKEN_VA(0x43E91Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E920u);
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003E92E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E92Eu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->ebx = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003E939: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E939u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043E940(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43E940u);
    lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E946u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003E9AA;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E959u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->edi = lift_load32(cpu->esi);
    cpu->edi += g_sfera_mbc_runtime->process_memory_base;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E968u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    cpu->eax = lift_load32(cpu->esi);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_0003E976;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_0003E98A;
    label_0003E976: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E976u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0003E993;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_0003E98A;
    cpu->eax = (uint32_t)(cpu->eax + cpu->ebx + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0003E993;
    label_0003E98A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E98Au);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3E993u); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    label_0003E993: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E993u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x43E996u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E99Cu);
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->ebp = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003E9AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E9AAu);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043E9B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43E9B0u);
    cpu->esp -= 8u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E9B8u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 4u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003EA58;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E9D1u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_0003E9E9;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffread\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E9E6u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_0003E9E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x43E9E9u);
    cpu->ebx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ebx += cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43E9F6u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->esi = 0u;
    lift_store8(cpu->esp + 0xDu, 0u);
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_0003EA4E;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::_read);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0003EA10: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EA10u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x3EA1Eu), LIFT_CODE_TOKEN_RVA(0x3EA1Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43EA1Eu);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_0003EA4D;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x10u)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0xAu)) goto label_0003EA49;
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0003EA49;
    lift_store8(cpu->esi + cpu->ebx, cpu->eax & 0xFFu);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->edi)) goto label_0003EA10;
    cpu->ebp = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EA42u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
    label_0003EA49: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EA49u);
    lift_store8(cpu->esi + cpu->ebx, 0u);
    label_0003EA4D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EA4Du);
    cpu->ebp = lift_pop32(cpu);
    label_0003EA4E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EA4Eu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EA55u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0003EA58: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EA58u);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043EA60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43EA60u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EA67u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EA6Eu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EA75u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003EAA7;
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_0003EA87;
    cpu->eax = 0u;
    goto label_0003EA92;
    label_0003EA87: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EA87u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->ecx + 1u);
    label_0003EA92: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EA92u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_lseek), LIFT_CODE_TOKEN_VA(0x43EA95u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EA9Bu);
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003EAA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EAA7u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043EAB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43EAB0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EAB5u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003EACF;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_filelength), LIFT_CODE_TOKEN_VA(0x43EABFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EAC5u);
    cpu->esp += 4u;
    cpu->ecx = cpu->eax;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003EACF: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EACFu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043EAD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43EAD0u);
    cpu->esp -= 0x34u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EAE3u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003EB03;
    cpu->ecx = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_fstat64i32), LIFT_CODE_TOKEN_VA(0x43EAF1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EAF7u);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->esp += 8u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3EB03u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_0003EB03: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EB03u);
    cpu->esp += 0x34u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043EB20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43EB20u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EB26u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EB2Du); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003EB41;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_chsize), LIFT_CODE_TOKEN_VA(0x43EB38u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EB3Eu);
    cpu->esp += 8u;
    label_0003EB41: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EB41u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043EB50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43EB50u);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EB64u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EB6Bu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003EB94;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_futime64), LIFT_CODE_TOKEN_VA(0x43EB8Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EB91u);
    cpu->esp += 8u;
    label_0003EB94: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EB94u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043EBB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43EBB0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EBB5u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003EBD5;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x43EBC5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EBCBu);
    cpu->esp += 4u;
    cpu->ecx = cpu->eax;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003EBD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EBD5u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043EBE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43EBE0u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EBE6u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EBF3u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003EC15;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x43EC04u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EC0Au);
    cpu->esp += 8u;
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003EC15: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EC15u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043EC20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43EC20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EC25u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003EC46;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EC3Bu); lift_push32(cpu, r); sfera_sub_00436510(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_mbc_runtime->file_crc32;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003EC46: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EC46u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043EC50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43EC50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EC55u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003EC6D;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003EC6D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EC6Du);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].payload[0] = (uint32_t)(cpu->eax);
    cpu->eax = 1u;
    cpu->edx += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_end = (uint32_t)(cpu->eax);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_begin = (uint32_t)(cpu->eax);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043ECB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43ECB0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43ECB5u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43ECBEu); lift_push32(cpu, r); sfera_sub_0043AED0(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043ECC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43ECC0u);
    cpu->eax = g_sfera_recovered_static_runtime.mbc_stack_table_cursor;
    cpu->edx = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_static_runtime.stack_default_values[0]));
    if ((uint32_t)(cpu->edx) == 0u) goto label_0003ECD6;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.mbc_stack_table_cursor, (uint64_t)(g_sfera_recovered_static_runtime.mbc_stack_table_cursor) + 1u);
    label_0003ECD6: cpu->eip = LIFT_CODE_TOKEN_VA(0x43ECD6u);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003ECEE;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003ECEE: cpu->eip = LIFT_CODE_TOKEN_VA(0x43ECEEu);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(cpu->edx);
    ++cpu->ecx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(1u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(1u);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043ED30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43ED30u);
    SferaMbInterObjectProfile sfera_profile;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43ED3Au); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43ED41u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003ED53;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43ED51u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    label_0003ED53: cpu->eip = LIFT_CODE_TOKEN_VA(0x43ED53u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003EDC5;
    sfera_profile = sfera_mbinter_object_profile(cpu->edi);
    cpu->ecx = sfera_profile.factory_kind;
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->edx = (uint32_t)(cpu->esi + 0xFFFFFFFFu);
    { uint64_t x=(uint64_t)(cpu->edx), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->edx = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(cpu->edx) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->edx &= g_sfera_mbc_runtime->active_process;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43ED88u); lift_push32(cpu, r); sfera_sub_00479A30(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43ED91u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0003EDC9;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += cpu->ebx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Error creating object: %s"); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->text_buffer[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x43EDA8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EDAEu);
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->text_buffer[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EDBBu); lift_push32(cpu, r); sfera_sub_004385D0(cpu,r); if (cpu->eip != r) return; }
    g_sfera_mbc_runtime->execution_failed = (uint32_t)(0u);
    label_0003EDC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EDC5u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003EDC9: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EDC9u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EDD0u); lift_push32(cpu, r); sfera_sub_00454F70(cpu,r); if (cpu->eip != r) return; }
    g_sfera_inter_scalar_runtime.mode_03 = (uint32_t)(cpu->eax);
    if ((uint8_t)(lift_load8(cpu->eax + 0x138u)) != (uint8_t)(1u)) goto label_0003EE33;
    cpu->edx = g_sfera_inter_scalar_runtime.mode_03;
    lift_store8(cpu->edx + 0x274u, sfera_profile.property_274);
    lift_store8(cpu->edx + 0x275u, sfera_profile.property_275);
    lift_store8(cpu->edx + 0x276u, sfera_profile.property_276);
    lift_store8(cpu->edx + 0x277u, sfera_profile.property_277);
    label_0003EE33: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EE33u);
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->edx = 0u;
    cpu->ebx = lift_pop32(cpu);
    sfera_sub_00437A10(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043EE40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43EE40u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EE49u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0003EF47;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EE58u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EE61u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EE6Au); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EE75u); lift_push32(cpu, r); sfera_sub_00454F70(cpu,r); if (cpu->eip != r) return; }
    g_sfera_inter_scalar_runtime.mode_03 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0003EE8D;
    g_sfera_mbc_runtime->active_tag = (uint32_t)(0xFFFFFFFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
    label_0003EE8D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EE8Du);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003EF47;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->eax + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->ecx + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(g_sfera_world_objects.controlled_object_handle)) goto label_0003EF1B;
    if ((uint8_t)(g_sfera_graphics_runtime.render_mode_enabled) != (uint8_t)(1u)) goto label_0003EF1B;
    cpu->eax = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.motion_accumulator, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32));
    lift_x87_push(cpu, 333.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)(*(float*)(void*)&g_sfera_main_input_state_runtime.motion_accumulator))));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.motion_accumulator, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0003EF1B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EF1Bu);
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->argument_count) < (int32_t)(uint32_t)(5u)) goto label_0003EF47;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EF2Bu); lift_push32(cpu, r); sfera_sub_0045ED20(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->argument_count) != (uint32_t)(6u)) goto label_0003EF47;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EF39u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EF3Eu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_inter_scalar_runtime.mode_03;
    lift_store32(cpu->edx + 0x20u, cpu->eax);
    label_0003EF47: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EF47u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043EF50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43EF50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EF55u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EF5Cu); lift_push32(cpu, r); sfera_sub_00454E30(cpu,r); if (cpu->eip != r) return; }
    g_sfera_mbc_runtime->resolved_position_pointer = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0003EF75;
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EF70u); lift_push32(cpu, r); sfera_sub_0043AED0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_mbc_runtime->resolved_position_pointer;
    label_0003EF75: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EF75u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003EF89;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3EF89u); lift_push32(cpu, r); sfera_sub_0043AED0(cpu,r); if (cpu->eip != r) return; }
    label_0003EF89: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EF89u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043EF90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43EF90u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EF95u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EF9Cu); lift_push32(cpu, r); sfera_sub_00454E30(cpu,r); if (cpu->eip != r) return; }
    g_sfera_mbc_runtime->resolved_position_pointer = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0003EFB5;
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EFB0u); lift_push32(cpu, r); sfera_sub_0043AED0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_mbc_runtime->resolved_position_pointer;
    label_0003EFB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EFB5u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003EFCA;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3EFCAu); lift_push32(cpu, r); sfera_sub_0043AED0(cpu,r); if (cpu->eip != r) return; }
    label_0003EFCA: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EFCAu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043EFD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43EFD0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EFD5u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EFDCu); lift_push32(cpu, r); sfera_sub_00454E30(cpu,r); if (cpu->eip != r) return; }
    g_sfera_mbc_runtime->resolved_position_pointer = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0003EFF5;
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43EFF0u); lift_push32(cpu, r); sfera_sub_0043AED0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_mbc_runtime->resolved_position_pointer;
    label_0003EFF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43EFF5u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003F00A;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3F00Au); lift_push32(cpu, r); sfera_sub_0043AED0(cpu,r); if (cpu->eip != r) return; }
    label_0003F00A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F00Au);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043F010(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43F010u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F015u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F01Cu); lift_push32(cpu, r); sfera_sub_00454ED0(cpu,r); if (cpu->eip != r) return; }
    g_sfera_inter_scalar_runtime.state_04 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0003F035;
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F030u); lift_push32(cpu, r); sfera_sub_0043AED0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_inter_scalar_runtime.state_04;
    label_0003F035: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F035u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F040u); lift_push32(cpu, r); sfera_sub_0043AED0(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043F050(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43F050u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F055u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F05Cu); lift_push32(cpu, r); sfera_sub_00454ED0(cpu,r); if (cpu->eip != r) return; }
    g_sfera_inter_scalar_runtime.state_04 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0003F075;
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F070u); lift_push32(cpu, r); sfera_sub_0043AED0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_inter_scalar_runtime.state_04;
    label_0003F075: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F075u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F081u); lift_push32(cpu, r); sfera_sub_0043AED0(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043F090(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43F090u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F095u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F09Cu); lift_push32(cpu, r); sfera_sub_00454ED0(cpu,r); if (cpu->eip != r) return; }
    g_sfera_inter_scalar_runtime.state_04 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0003F0B5;
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F0B0u); lift_push32(cpu, r); sfera_sub_0043AED0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_inter_scalar_runtime.state_04;
    label_0003F0B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F0B5u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F0C1u); lift_push32(cpu, r); sfera_sub_0043AED0(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043F0D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43F0D0u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F0D6u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003F0F8;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_0003F0ED;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3F0EDu); lift_push32(cpu, r); sfera_sub_00459150(cpu,r); if (cpu->eip != r) return; }
    label_0003F0ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F0EDu);
    lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3F0F8u); lift_push32(cpu, r); sfera_sub_00437B10(cpu,r); if (cpu->eip != r) return; }
    label_0003F0F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F0F8u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043F100(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43F100u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F109u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0003F172;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F114u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F11Du); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F126u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F131u); lift_push32(cpu, r); sfera_sub_00454F70(cpu,r); if (cpu->eip != r) return; }
    g_sfera_inter_scalar_runtime.mode_03 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0003F149;
    g_sfera_mbc_runtime->active_tag = (uint32_t)(0xFFFFFFFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
    label_0003F149: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F149u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003F172;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->eax + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->eax + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->ecx + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0003F172: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F172u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043F180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43F180u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = 0u;
    cpu->ebp = 0u;
    cpu->edi = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F18Fu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ebx) >= 0) goto label_0003F1A0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->ebx = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003F1A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F1A0u);
    if ((uint32_t)(g_sfera_mbc_runtime->argument_count) != (uint32_t)(5u)) goto label_0003F1D5;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F1AEu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->edi += g_sfera_mbc_runtime->process_memory_base;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F1BBu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F1C8u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    cpu->ebp += g_sfera_mbc_runtime->process_memory_base;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3F1D5u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    label_0003F1D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F1D5u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003F205;
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = cpu->ebx;
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003F297;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F1F2u); lift_push32(cpu, r); sfera_sub_00454F70(cpu,r); if (cpu->eip != r) return; }
    g_sfera_inter_scalar_runtime.mode_03 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0003F20A;
    g_sfera_mbc_runtime->active_tag = (uint32_t)(0xFFFFFFFFu);
    label_0003F205: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F205u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003F20A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F20Au);
    lift_push32(cpu, 0x2178u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F21Bu); lift_push32(cpu, r); sfera_sub_0045CB30(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    if ((uint8_t)(lift_load8(cpu->ebx + 0x2A0u)) == (uint8_t)(0u)) goto label_0003F22A;
    cpu->ecx = 0u;
    goto label_0003F22D;
    label_0003F22A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F22Au);
    cpu->ecx |= 0xFFFFFFFFu;
    label_0003F22D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F22Du);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F232u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->ebx + 0x2A0u, 0u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_0003F205;
    if ((uint8_t)(lift_load8(cpu->ebx + 0x2A1u)) == (uint8_t)(0u)) goto label_0003F28C;
    lift_store32(cpu->edi, 1u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_0003F272;
    if ((uint32_t)(cpu->esi) == (uint32_t)(g_sfera_mbc_runtime->process_memory_base)) goto label_0003F272;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x2A4u));
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x2A8u));
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x2ACu));
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0003F272: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F272u);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_0003F205;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(g_sfera_mbc_runtime->process_memory_base)) goto label_0003F205;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x2B0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store_f32(cpu->ebp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003F28C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F28Cu);
    lift_store32(cpu->edi, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003F297: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F297u);
    cpu->edx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F29Eu); lift_push32(cpu, r); sfera_sub_004731A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043F2B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43F2B0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F2B5u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003F2E0;
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0003F2D8;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F2C9u); lift_push32(cpu, r); sfera_sub_0045CC30(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0003F2D8;
    cpu->ecx = lift_load32(cpu->eax + 0xB4u);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003F2D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F2D8u);
    cpu->ecx |= 0xFFFFFFFFu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003F2E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F2E0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043F2F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43F2F0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F2F9u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0003F3D3;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F308u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F311u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F31Au); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F325u); lift_push32(cpu, r); sfera_sub_00454F70(cpu,r); if (cpu->eip != r) return; }
    g_sfera_inter_scalar_runtime.mode_03 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0003F33D;
    g_sfera_mbc_runtime->active_tag = (uint32_t)(0xFFFFFFFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
    label_0003F33D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F33Du);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003F3D3;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 4u))));
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 8u))));
    lift_store_f32(cpu->eax + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xCu))));
    lift_store_f32(cpu->eax + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(g_sfera_world_objects.controlled_object_handle)) goto label_0003F3D3;
    if ((uint8_t)(g_sfera_graphics_runtime.render_mode_enabled) != (uint8_t)(1u)) goto label_0003F3D3;
    cpu->eax = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.motion_accumulator, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32));
    lift_x87_push(cpu, 333.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)(*(float*)(void*)&g_sfera_main_input_state_runtime.motion_accumulator))));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.motion_accumulator, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0003F3D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F3D3u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043F3E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43F3E0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F3E9u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F3F0u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F3F9u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F402u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003F430;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    cpu->esp -= 0xCu;
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3F430u); lift_push32(cpu, r); sfera_sub_0046B7D0(cpu,r); if (cpu->eip != r) return; }
    label_0003F430: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F430u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043F440(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43F440u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F447u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F44Eu); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003F476;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    cpu->esp -= 0xCu;
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3F476u); lift_push32(cpu, r); sfera_sub_0046B7D0(cpu,r); if (cpu->eip != r) return; }
    label_0003F476: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F476u);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043F480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43F480u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F489u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F490u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F499u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F4A2u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003F4D0;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    cpu->esp -= 0xCu;
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3F4D0u); lift_push32(cpu, r); sfera_sub_004634E0(cpu,r); if (cpu->eip != r) return; }
    label_0003F4D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F4D0u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043F4E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43F4E0u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F4E6u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0003F51F;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F4F1u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003F51F;
    lift_push32(cpu, cpu->ebx);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    lift_push32(cpu, 0x21FAu);
    cpu->ecx = cpu->esi;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F50Cu); lift_push32(cpu, r); sfera_sub_00454F70(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F518u); lift_push32(cpu, r); sfera_sub_0045CB30(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->eax + 0x141u, cpu->ebx & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    label_0003F51F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F51Fu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043F530(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43F530u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003F5A4;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F54Bu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F554u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F55Bu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F562u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F569u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F56Eu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003F59E;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F582u); lift_push32(cpu, r); sfera_sub_00455820(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0003F5D8;
    lift_store32(cpu->eax + 0x6DA8u, cpu->esi);
    lift_store32(cpu->eax + 0x6DACu, cpu->edi);
    lift_store32(cpu->eax + 0x6DB0u, cpu->ebx);
    lift_store32(cpu->eax + 0x6DB4u, cpu->ebp);
    label_0003F59E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F59Eu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003F5A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F5A4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F5A9u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F5B0u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F5B7u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F5BEu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(8u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003F61A;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F5D2u); lift_push32(cpu, r); sfera_sub_00455820(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_0003F5E9;
    label_0003F5D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F5D8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = (uint32_t)(uintptr_t)"Wrong parameters for 'text' function";
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003F5E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F5E9u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F5EEu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x6DA8u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F5F9u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x6DACu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F604u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x6DB0u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F60Fu); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F614u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x6DB4u, cpu->eax);
    label_0003F61A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F61Au);
    if ((uint32_t)(g_sfera_mbc_runtime->argument_count) != (uint32_t)(9u)) goto label_0003F628;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3F628u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    label_0003F628: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F628u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003F59E;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax += cpu->edi;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->text_buffer[0];
    cpu->edx -= cpu->eax;
    label_0003F643: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F643u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0003F643;
    if ((uint8_t)(g_sfera_mbc_runtime->text_buffer[0]) != (uint8_t)((cpu->ecx & 0xFFu))) goto label_0003F661;
    cpu->edx = 0x3Fu;
    lift_store16((uintptr_t)&g_sfera_mbc_runtime->text_buffer[0], cpu->edx & 0xFFFFu);
    label_0003F661: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F661u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->text_buffer[0]);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F672u); lift_push32(cpu, r); sfera_sub_00463020(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0003F687;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003F687: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F687u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F68Eu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->edx = 4u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00437A10(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043F6B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43F6B0u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F6B6u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003F6DA;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0003F6CC;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3F6CCu); lift_push32(cpu, r); sfera_sub_00457370(cpu,r); if (cpu->eip != r) return; }
    label_0003F6CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F6CCu);
    lift_push32(cpu, 0u);
    cpu->edx = 4u;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3F6DAu); lift_push32(cpu, r); sfera_sub_00437B10(cpu,r); if (cpu->eip != r) return; }
    label_0003F6DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F6DAu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043F6E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43F6E0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F6E7u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F6EEu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(3u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003F714;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F6FEu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003F711;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3F711u); lift_push32(cpu, r); sfera_sub_0045AC40(cpu,r); if (cpu->eip != r) return; }
    label_0003F711: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F711u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003F714: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F714u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003F711;
    cpu->edx = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x45ABD0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005ABE4;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5ABE4u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005ABE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x45ABE4u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_0005ABF8;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5ABF8u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005ABF8: cpu->eip = LIFT_CODE_TOKEN_VA(0x45ABF8u);
    cpu->eax = g_sfera_interface_runtime.window_handle_table.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u))) != (uint32_t)(0u)) goto label_0005AC0D;
    cpu->ecx = (uint32_t)(uintptr_t)"text_color: wrong handle";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5AC0Du); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0005AC0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AC0Du);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0005AC1B;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5AC1Bu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0005AC1B: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AC1Bu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_interface_runtime.window_handle_table.capacity)) goto label_0005AC2F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_interface_runtime.window_handle_table.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x5AC2Fu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0005AC2F: cpu->eip = LIFT_CODE_TOKEN_VA(0x45AC2Fu);
    cpu->ecx = g_sfera_interface_runtime.window_handle_table.data;
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    lift_store32(cpu->edx + 0x28u, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043F730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43F730u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0xFFu;
    cpu->esi = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F742u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F74Du); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003F770;
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F763u); lift_push32(cpu, r); sfera_sub_0045EB60(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003F770: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F770u);
    lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F776u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F77Du); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F784u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F78Du); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(6u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003F7A1;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F79Fu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    label_0003F7A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F7A1u);
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->argument_count) <= (int32_t)(uint32_t)(7u)) goto label_0003F7B1;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F7AFu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    label_0003F7B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F7B1u);
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->argument_count) <= (int32_t)(uint32_t)(8u)) goto label_0003F7BF;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3F7BFu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    label_0003F7BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F7BFu);
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->argument_count) <= (int32_t)(uint32_t)(9u)) goto label_0003F7D2;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F7CDu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3F7D2u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    label_0003F7D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F7D2u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003F831;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F800u); lift_push32(cpu, r); sfera_sub_00467E70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0003F817;
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->ecx = (uint32_t)(uintptr_t)"Error creating sprite";
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003F817: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F817u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F81Eu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->edx = 5u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    sfera_sub_00437A10(cpu, stop_address); return;
    label_0003F831: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F831u);
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043F840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43F840u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F846u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003F86A;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0003F85C;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3F85Cu); lift_push32(cpu, r); sfera_sub_00455C20(cpu,r); if (cpu->eip != r) return; }
    label_0003F85C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F85Cu);
    lift_push32(cpu, 0u);
    cpu->edx = 5u;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3F86Au); lift_push32(cpu, r); sfera_sub_00437B10(cpu,r); if (cpu->eip != r) return; }
    label_0003F86A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F86Au);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043F870(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43F870u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F87Au); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F881u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type;
    cpu->ebp = 0u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x11u)) goto label_0003F89D;
    cpu->ebp = (uint32_t)(cpu->eax + 0xFFFFFFF0u);
    goto label_0003F8AF;
    label_0003F89D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F89Du);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x21u)) goto label_0003F8A7;
    cpu->ebp = (uint32_t)(cpu->eax + 0xFFFFFFE1u);
    goto label_0003F8AF;
    label_0003F8A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F8A7u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_0003F8AF;
    cpu->ebp = (uint32_t)(cpu->eax + 2u);
    label_0003F8AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F8AFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F8B4u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003F9CF;
    if ((uint32_t)(g_sfera_mbc_runtime->argument_count) != (uint32_t)(3u)) goto label_0003F908;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(1u)) goto label_0003F8DF;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(2u)) goto label_0003F8DF;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(3u)) goto label_0003F9C1;
    label_0003F8DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F8DFu);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(cpu->eax + cpu->ebx);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->eax + cpu->edi);
    lift_push32(cpu, cpu->edx);
    cpu->eax += cpu->esi;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x43F8EFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F8F5u);
    cpu->esp += 0xCu;
    cpu->esi = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003F908: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F908u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F90Du); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003F945;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(cpu->eax + cpu->ebp);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->eax + cpu->ebx);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->edi);
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->esi;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x43F92Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F932u);
    cpu->esp += 0x10u;
    cpu->esi = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003F945: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F945u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F94Au); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    if ((uint32_t)(cpu->eax) != (uint32_t)(5u)) goto label_0003F98B;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = (uint32_t)(cpu->eax + cpu->ecx);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->ebp);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->eax + cpu->ebx);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->edi);
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->esi;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x43F972u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F978u);
    cpu->esp += 0x14u;
    cpu->esi = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003F98B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F98Bu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(6u)) goto label_0003F9C1;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43F995u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = (uint32_t)(cpu->ecx + cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->eax);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ecx + cpu->ebp);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->ebx);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ecx + cpu->edi);
    lift_push32(cpu, cpu->eax);
    cpu->ecx += cpu->esi;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x43F9B6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F9BCu);
    cpu->esp += 0x18u;
    cpu->esi = cpu->eax;
    label_0003F9C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F9C1u);
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003F9CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x43F9CFu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043F9E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43F9E0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0003FA04;
    cpu->ecx = (uint32_t)(uintptr_t)"Wrong number of parameters: ffsprintf";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3FA04u); lift_push32(cpu, r); sfera_sub_004385D0(cpu,r); if (cpu->eip != r) return; }
    label_0003FA04: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FA04u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FA09u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->edi += g_sfera_mbc_runtime->process_memory_base;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FA16u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    cpu->ebx += g_sfera_mbc_runtime->process_memory_base;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003FA54;
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    cpu->eax -= 2u;
    g_sfera_mbc_runtime->argument_count = (uint32_t)(cpu->eax);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FA3Fu); lift_push32(cpu, r); sfera_sub_004EEA10(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->esp;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FA48u); lift_push32(cpu, r); sfera_sub_0043E0F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::vsprintf), LIFT_CODE_TOKEN_VA(0x43FA4Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43FA51u);
    cpu->esp += 0xCu;
    label_0003FA54: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FA54u);
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFF0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043FA70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43FA70u);
    cpu->eax = g_sfera_mbc_runtime->execution_context_depth;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003FA84;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->edx = g_sfera_mbc_runtime->execution_context_stack[g_sfera_mbc_runtime->execution_context_depth - 1u].process_id;
    goto label_0003FA87;
    label_0003FA84: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FA84u);
    cpu->edx |= 0xFFFFFFFFu;
    label_0003FA87: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FA87u);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003FA9F;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003FA9F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FA9Fu);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(cpu->edx);
    cpu->edx = 1u;
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->edx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->edx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043FAE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43FAE0u);
    cpu->esp -= 0x18u;
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003FBB8;
    cpu->eax = g_sfera_mbc_runtime->execution_context_depth;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_0003FB21;
    cpu->ecx = g_sfera_mbc_runtime->program_index;
    cpu->edx = g_sfera_mbc_runtime->program_table_base;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xA4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + cpu->edx + 0x84u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0003FB21;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->esi = g_sfera_mbc_runtime->execution_context_stack[g_sfera_mbc_runtime->execution_context_depth - 1u].process_id;
    goto label_0003FB24;
    label_0003FB21: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FB21u);
    cpu->esi |= 0xFFFFFFFFu;
    label_0003FB24: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FB24u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FB2Fu); lift_push32(cpu, r); sfera_sub_0043AE00(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edi = lift_load32(cpu->eax + 8u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003FC7C;
    if ((uint32_t)(cpu->esi) > (uint32_t)(0xFFFFu)) goto label_0003FBAB;
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id))) != (uint32_t)(cpu->esi)) goto label_0003FBAB;
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))) < (int32_t)(uint32_t)(0u)) goto label_0003FBAB;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_0003FBAB;
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_memory_base));
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax -= cpu->esi;
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003FB86;
    cpu->ecx += cpu->eax;
    { uint64_t v=(uint64_t)(cpu->edx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003FB86;
    cpu->edx += cpu->eax;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    label_0003FB86: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FB86u);
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.source_id));
    lift_store32(cpu->eax + cpu->esi, cpu->ecx);
    lift_store32(cpu->eax + cpu->esi + 4u, cpu->edx);
    lift_store32(cpu->eax + cpu->esi + 8u, cpu->edi);
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003FBAB: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FBABu);
    cpu->edi = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003FBB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FBB8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FBBDu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FBC9u); lift_push32(cpu, r); sfera_sub_0043AE00(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 4u, cpu->ecx);
    lift_store32(cpu->esp + 8u, cpu->edx);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003FC7D;
    if ((uint32_t)(cpu->esi) > (uint32_t)(0xFFFFu)) goto label_0003FC47;
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id))) != (uint32_t)(cpu->esi)) goto label_0003FC47;
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))) < (int32_t)(uint32_t)(0u)) goto label_0003FC47;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_0003FC47;
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_memory_base));
    cpu->eax -= g_sfera_mbc_runtime->process_memory_base;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0003FC34;
    cpu->ecx += cpu->eax;
    lift_store32(cpu->esp + 4u, cpu->ecx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0003FC34;
    cpu->edx += cpu->eax;
    lift_store32(cpu->esp + 0xCu, (uint64_t)(lift_load32(cpu->esp + 0xCu)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    lift_store32(cpu->esp + 8u, cpu->edx);
    label_0003FC34: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FC34u);
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FC42u); lift_push32(cpu, r); sfera_sub_0043AF30(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_0003FC47: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FC47u);
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 4u, 0u);
    lift_store32(cpu->esp + 8u, 0u);
    lift_store32(cpu->esp + 0xCu, 0u);
    g_sfera_mbc_runtime->active_tag = (uint32_t)(0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FC77u); lift_push32(cpu, r); sfera_sub_0043AF30(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_0003FC7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FC7Cu);
    cpu->edi = lift_pop32(cpu);
    label_0003FC7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FC7Du);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043FC90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43FC90u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FC98u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FC9Fu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(lift_load32(cpu->esi)) != (uint32_t)(0u)) goto label_0003FCBC;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffmempcpy\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FCB5u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003FCBC: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FCBCu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FCC3u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FCCAu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FCD3u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    cpu->eax = lift_load32(cpu->esi);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_0003FCE1;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_0003FCF5;
    label_0003FCE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FCE1u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0003FCFE;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_0003FCF5;
    cpu->eax = (uint32_t)(cpu->eax + cpu->ebp + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0003FCFE;
    label_0003FCF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FCF5u);
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3FCFEu); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    label_0003FCFE: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FCFEu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003FD9B;
    cpu->ecx |= 0xFFFFFFFFu;
    if ((uint32_t)(cpu->ebx) > (uint32_t)(0xFFFFu)) goto label_0003FD33;
    cpu->eax = cpu->ebx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id))) != (uint32_t)(cpu->ebx)) goto label_0003FD33;
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))) < (int32_t)(uint32_t)(0u)) goto label_0003FD33;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(cpu->ecx)) goto label_0003FD45;
    label_0003FD33: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FD33u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->active_tag = (uint32_t)(cpu->ecx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003FD45: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FD45u);
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_memory_base));
    cpu->eax += lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edi) > (uint32_t)(0xFFFFu)) goto label_0003FD72;
    cpu->edx = cpu->edi;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    if ((uint32_t)(lift_load32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id))) != (uint32_t)(cpu->edi)) goto label_0003FD72;
    if ((int32_t)(uint32_t)(lift_load32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))) < (int32_t)(uint32_t)(0u)) goto label_0003FD72;
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->ecx)) goto label_0003FD84;
    label_0003FD72: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FD72u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->active_tag = (uint32_t)(cpu->ecx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003FD84: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FD84u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_memory_base));
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->ecx += lift_load32(cpu->edx);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43FD93u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43FD98u);
    cpu->esp += 0xCu;
    label_0003FD9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FD9Bu);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043FDB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43FDB0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FDB7u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FDBEu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(lift_load32(cpu->edi)) != (uint32_t)(0u)) goto label_0003FDDA;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffmempcpy\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FDD4u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003FDDA: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FDDAu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FDE1u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FDE8u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    cpu->eax = 0u;
    if ((uint32_t)(g_sfera_mbc_runtime->argument_count) != (uint32_t)(5u)) goto label_0003FDFA;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3FDFAu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    label_0003FDFA: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FDFAu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0003FEA6;
    cpu->ecx |= 0xFFFFFFFFu;
    if ((uint32_t)(cpu->esi) > (uint32_t)(0xFFFFu)) goto label_0003FE2F;
    cpu->edx = cpu->esi;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    if ((uint32_t)(lift_load32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id))) != (uint32_t)(cpu->esi)) goto label_0003FE2F;
    if ((int32_t)(uint32_t)(lift_load32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))) < (int32_t)(uint32_t)(0u)) goto label_0003FE2F;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ecx)) goto label_0003FE3E;
    label_0003FE2F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FE2Fu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_runtime->active_tag = (uint32_t)(cpu->ecx);
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003FE3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FE3Eu);
    cpu->esi = lift_load32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_memory_base));
    cpu->esi += lift_load32(cpu->edi);
    if ((uint32_t)(cpu->ebx) > (uint32_t)(0xFFFFu)) goto label_0003FE6B;
    cpu->edx = cpu->ebx;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    if ((uint32_t)(lift_load32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id))) != (uint32_t)(cpu->ebx)) goto label_0003FE6B;
    if ((int32_t)(uint32_t)(lift_load32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))) < (int32_t)(uint32_t)(0u)) goto label_0003FE6B;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(cpu->ecx)) goto label_0003FE7A;
    label_0003FE6B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FE6Bu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_runtime->active_tag = (uint32_t)(cpu->ecx);
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_0003FE7A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FE7Au);
    cpu->edx = lift_load32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_memory_base));
    cpu->edx += lift_load32(cpu->ebp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FE8Bu); lift_push32(cpu, r); sfera_sub_00433FF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FE95u); lift_push32(cpu, r); sfera_sub_00401C60(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0003FEA6;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->ecx = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    cpu->edx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_00434E80(cpu, stop_address); return;
    label_0003FEA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FEA6u);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043FEB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43FEB0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FEB8u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FEBFu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FEC6u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003FF16;
    if ((uint32_t)(cpu->edi) == 0u) goto label_0003FEFE;
    cpu->eax = lift_load32(cpu->esi);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_0003FEE1;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_0003FEF5;
    label_0003FEE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FEE1u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0003FEFE;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_0003FEF5;
    cpu->eax = (uint32_t)(cpu->eax + cpu->edi + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0003FEFE;
    label_0003FEF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FEF5u);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3FEFEu); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    label_0003FEFE: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FEFEu);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = lift_load32(cpu->ebx);
    cpu->edx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->edi);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43FF0Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43FF13u);
    cpu->esp += 0xCu;
    label_0003FF16: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FF16u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043FF20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43FF20u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FF28u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FF2Fu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FF36u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003FF87;
    if ((uint32_t)(cpu->edi) == 0u) goto label_0003FF6E;
    cpu->eax = lift_load32(cpu->esi);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_0003FF51;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_0003FF65;
    label_0003FF51: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FF51u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0003FF6E;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_0003FF65;
    cpu->eax = (uint32_t)(cpu->eax + cpu->edi + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0003FF6E;
    label_0003FF65: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FF65u);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3FF6Eu); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    label_0003FF6E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FF6Eu);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = lift_load32(cpu->ebx);
    cpu->edx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->edi);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x43FF7Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43FF84u);
    cpu->esp += 0xCu;
    label_0003FF87: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FF87u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0043FF90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43FF90u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FF98u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FF9Fu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43FFA6u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003FFF1;
    if ((uint32_t)(cpu->edi) == 0u) goto label_0003FFDE;
    cpu->eax = lift_load32(cpu->esi);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_0003FFC1;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_0003FFD5;
    label_0003FFC1: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FFC1u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0003FFDE;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_0003FFD5;
    cpu->eax = (uint32_t)(cpu->eax + cpu->edi + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0003FFDE;
    label_0003FFD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FFD5u);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3FFDEu); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    label_0003FFDE: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FFDEu);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->ecx += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x43FFE9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43FFEEu);
    cpu->esp += 0xCu;
    label_0003FFF1: cpu->eip = LIFT_CODE_TOKEN_VA(0x43FFF1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00440000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x440000u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = 1u;
    if ((uint32_t)(g_sfera_mbc_runtime->argument_count) != (uint32_t)(cpu->esi)) goto label_00040028;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440013u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00040028;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_00040020;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_0004002E;
    label_00040020: cpu->eip = LIFT_CODE_TOKEN_VA(0x440020u);
    g_sfera_render_lookup_runtime.initialized = (uint32_t)(cpu->esi);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00040028: cpu->eip = LIFT_CODE_TOKEN_VA(0x440028u);
    g_sfera_mbc_runtime->halt_all_requested = (uint32_t)(cpu->esi);
    label_0004002E: cpu->eip = LIFT_CODE_TOKEN_VA(0x44002Eu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00440030(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x440030u);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00040048;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_00040048: cpu->eip = LIFT_CODE_TOKEN_VA(0x440048u);
    cpu->edx = g_sfera_network_runtime.initialization_result;
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(cpu->edx);
    cpu->edx = 1u;
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->edx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->edx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00440090(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x440090u);
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_000400BB;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4400A0u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4400A7u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4400AEu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000400DB;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4400B9u); lift_push32(cpu, r); sfera_sub_0045CF00(cpu,r); if (cpu->eip != r) return; }
    goto label_000400E2;
    label_000400BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4400BBu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4400C0u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4400C7u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000400E8;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4400D9u); lift_push32(cpu, r); sfera_sub_0045CF00(cpu,r); if (cpu->eip != r) return; }
    goto label_000400E2;
    label_000400DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4400DBu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x400E2u); lift_push32(cpu, r); sfera_sub_0045D3C0(cpu,r); if (cpu->eip != r) return; }
    label_000400E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4400E2u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000400E8;
    lift_store32(cpu->eax, cpu->edi);
    label_000400E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4400E8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004400F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4400F0u);
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0004011B;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440100u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440107u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44010Eu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0004013B;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440119u); lift_push32(cpu, r); sfera_sub_0045D020(cpu,r); if (cpu->eip != r) return; }
    goto label_00040142;
    label_0004011B: cpu->eip = LIFT_CODE_TOKEN_VA(0x44011Bu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440120u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440127u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00040148;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440139u); lift_push32(cpu, r); sfera_sub_0045D020(cpu,r); if (cpu->eip != r) return; }
    goto label_00040142;
    label_0004013B: cpu->eip = LIFT_CODE_TOKEN_VA(0x44013Bu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x40142u); lift_push32(cpu, r); sfera_sub_0045D280(cpu,r); if (cpu->eip != r) return; }
    label_00040142: cpu->eip = LIFT_CODE_TOKEN_VA(0x440142u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00040148;
    lift_store32(cpu->eax, cpu->edi);
    label_00040148: cpu->eip = LIFT_CODE_TOKEN_VA(0x440148u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00440150(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x440150u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440156u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44015Du); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00040177;
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44016Fu); lift_push32(cpu, r); sfera_sub_0045CD70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00040177: cpu->eip = LIFT_CODE_TOKEN_VA(0x440177u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00440180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x440180u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440187u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44018Eu); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000401AC;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4401A2u); lift_push32(cpu, r); sfera_sub_0045D140(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000401AC;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000401AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4401ACu);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004401B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4401B0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4401B9u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0004024F;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4401C8u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4401D1u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4401DCu); lift_push32(cpu, r); sfera_sub_00454F70(cpu,r); if (cpu->eip != r) return; }
    g_sfera_inter_scalar_runtime.mode_03 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000401F4;
    g_sfera_mbc_runtime->active_tag = (uint32_t)(0xFFFFFFFFu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
    label_000401F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4401F4u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0004024F;
    lift_push32(cpu, 0x23F5u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44020Eu); lift_push32(cpu, r); sfera_sub_0045CB30(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    cpu->esi = cpu->eax;
    lift_store_f32(cpu->esi + 0x27Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->argument_count) != (uint32_t)(4u)) goto label_00040245;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440228u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esi + 0x280u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esi + 0x284u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
    label_00040245: cpu->eip = LIFT_CODE_TOKEN_VA(0x440245u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esi + 0x284u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004024F: cpu->eip = LIFT_CODE_TOKEN_VA(0x44024Fu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00440260(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x440260u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440266u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000402CC;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440271u); lift_push32(cpu, r); sfera_sub_00454F70(cpu,r); if (cpu->eip != r) return; }
    g_sfera_inter_scalar_runtime.mode_03 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00040286;
    g_sfera_mbc_runtime->active_tag = (uint32_t)(0xFFFFFFFFu);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00040286: cpu->eip = LIFT_CODE_TOKEN_VA(0x440286u);
    if ((uint32_t)(g_sfera_mbc_runtime->argument_count) != (uint32_t)(3u)) goto label_0004029D;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440294u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44029Bu); lift_push32(cpu, r); sfera_sub_00451990(cpu,r); if (cpu->eip != r) return; }
    goto label_000402A2;
    label_0004029D: cpu->eip = LIFT_CODE_TOKEN_VA(0x44029Du);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x402A2u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    label_000402A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4402A2u);
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000402CC;
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    lift_push32(cpu, 0x2411u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4402C3u); lift_push32(cpu, r); sfera_sub_0045CB30(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_store_f32(cpu->eax + 0x28Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000402CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4402CCu);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004402D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4402D0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4402D7u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_00040327;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4402E2u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4402EDu); lift_push32(cpu, r); sfera_sub_00454F70(cpu,r); if (cpu->eip != r) return; }
    g_sfera_inter_scalar_runtime.mode_03 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00040303;
    g_sfera_mbc_runtime->active_tag = (uint32_t)(0xFFFFFFFFu);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00040303: cpu->eip = LIFT_CODE_TOKEN_VA(0x440303u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00040327;
    lift_push32(cpu, 0x241Cu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44031Du); lift_push32(cpu, r); sfera_sub_0045CB30(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->eax + 0x294u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00040327: cpu->eip = LIFT_CODE_TOKEN_VA(0x440327u);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00440330(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x440330u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440335u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00040340;
    label_00040339: cpu->eip = LIFT_CODE_TOKEN_VA(0x440339u);
    cpu->ecx = 0u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00040340: cpu->eip = LIFT_CODE_TOKEN_VA(0x440340u);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440347u); lift_push32(cpu, r); sfera_sub_00454F70(cpu,r); if (cpu->eip != r) return; }
    g_sfera_inter_scalar_runtime.mode_03 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0004035B;
    g_sfera_mbc_runtime->active_tag = (uint32_t)(0xFFFFFFFFu);
    label_0004035A: cpu->eip = LIFT_CODE_TOKEN_VA(0x44035Au);
    lift_return(cpu, 0u, stop_address); return;
    label_0004035B: cpu->eip = LIFT_CODE_TOKEN_VA(0x44035Bu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0004035A;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440369u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_00040395;
    lift_push32(cpu, 0x2428u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440383u); lift_push32(cpu, r); sfera_sub_0045CB30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 1u;
    if ((uint32_t)(lift_load32(cpu->eax + 0x278u)) != (uint32_t)(cpu->ecx)) goto label_00040339;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00040395: cpu->eip = LIFT_CODE_TOKEN_VA(0x440395u);
    lift_push32(cpu, 0x242Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44039Fu); lift_push32(cpu, r); sfera_sub_0045CB30(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->eax + 0x278u, 1u);
    cpu->ecx = 0u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004403B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4403B0u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4403B6u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4403BDu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00040404;
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFEu)) goto label_000403DB;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->esi)) goto label_000403EC;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_flags;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000403DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4403DBu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_000403EC;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_x;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000403EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4403ECu);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000403FD;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_y;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000403FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4403FDu);
    cpu->ecx = 0u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00040404: cpu->eip = LIFT_CODE_TOKEN_VA(0x440404u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00440410(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x440410u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440416u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_000404D3;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440427u); lift_push32(cpu, r); sfera_sub_00454F70(cpu,r); if (cpu->eip != r) return; }
    g_sfera_inter_scalar_runtime.mode_03 = (uint32_t)(cpu->eax);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004043C;
    g_sfera_mbc_runtime->active_tag = (uint32_t)(0xFFFFFFFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0004043C: cpu->eip = LIFT_CODE_TOKEN_VA(0x44043Cu);
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    if ((uint32_t)(g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type) == (uint32_t)(0x21u)) goto label_00040469;
    lift_push32(cpu, (uintptr_t)"g_norm: wrong type of parameter (must be float pointer)\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44045Cu); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    g_sfera_mbc_runtime->execution_failed = (uint32_t)(1u);
    label_00040469: cpu->eip = LIFT_CODE_TOKEN_VA(0x440469u);
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44046Fu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000404D2;
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x2459u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440490u); lift_push32(cpu, r); sfera_sub_0045CB30(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440499u); lift_push32(cpu, r); sfera_sub_00463B30(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->esi = (uint32_t)(cpu->eax + cpu->ebx);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->eax)) goto label_000404B7;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffg_norm\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4404B4u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000404B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4404B7u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x14Cu));
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x150u));
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x154u));
    cpu->edi = lift_pop32(cpu);
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000404D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4404D2u);
    cpu->ebx = lift_pop32(cpu);
    label_000404D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4404D3u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004404E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4404E0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4404E5u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_00040570;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4404F4u); lift_push32(cpu, r); sfera_sub_00454F70(cpu,r); if (cpu->eip != r) return; }
    g_sfera_inter_scalar_runtime.mode_03 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00040508;
    g_sfera_mbc_runtime->active_tag = (uint32_t)(0xFFFFFFFFu);
    lift_return(cpu, 0u, stop_address); return;
    label_00040508: cpu->eip = LIFT_CODE_TOKEN_VA(0x440508u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44050Eu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004056F;
    cpu->eax = lift_load32(cpu->esi);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00040525;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_00040538;
    label_00040525: cpu->eip = LIFT_CODE_TOKEN_VA(0x440525u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00040544;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_00040538;
    cpu->eax += 0xBu;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_00040544;
    label_00040538: cpu->eip = LIFT_CODE_TOKEN_VA(0x440538u);
    cpu->edx = 0xCu;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x40544u); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    label_00040544: cpu->eip = LIFT_CODE_TOKEN_VA(0x440544u);
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0xCu));
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x10u));
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004056F: cpu->eip = LIFT_CODE_TOKEN_VA(0x44056Fu);
    cpu->esi = lift_pop32(cpu);
    label_00040570: cpu->eip = LIFT_CODE_TOKEN_VA(0x440570u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00440580(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x440580u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440585u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000405F5;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440590u); lift_push32(cpu, r); sfera_sub_00454F70(cpu,r); if (cpu->eip != r) return; }
    g_sfera_inter_scalar_runtime.mode_03 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000405A4;
    g_sfera_mbc_runtime->active_tag = (uint32_t)(0xFFFFFFFFu);
    lift_return(cpu, 0u, stop_address); return;
    label_000405A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4405A4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4405A9u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000405F5;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx + cpu->eax);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ecx)) goto label_000405D2;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffg_abg\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4405CFu); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000405D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4405D2u);
    cpu->eax = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x18u));
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = g_sfera_inter_scalar_runtime.mode_03;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x1Cu));
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    label_000405F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4405F5u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00440600(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x440600u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 8u;
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(3u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_00040626;
    cpu->ecx = (uint32_t)(uintptr_t)"Wrong number of parameters: ffsnprintf";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x40626u); lift_push32(cpu, r); sfera_sub_004385D0(cpu,r); if (cpu->eip != r) return; }
    label_00040626: cpu->eip = LIFT_CODE_TOKEN_VA(0x440626u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44062Bu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440638u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440640u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    cpu->ebx += g_sfera_mbc_runtime->process_memory_base;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00040687;
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    cpu->eax -= 3u;
    g_sfera_mbc_runtime->argument_count = (uint32_t)(cpu->eax);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440669u); lift_push32(cpu, r); sfera_sub_004EEA10(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->esp;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440672u); lift_push32(cpu, r); sfera_sub_0043E0F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_vsnprintf), LIFT_CODE_TOKEN_VA(0x440679u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x44067Fu);
    cpu->esp += 0x10u;
    lift_store8(cpu->edi + cpu->esi + 0xFFFFFFFFu, 0u);
    label_00040687: cpu->eip = LIFT_CODE_TOKEN_VA(0x440687u);
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004406A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4406A0u);
    cpu->esp -= 0x14u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4406B3u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00040740;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4406C2u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4406C9u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->edi) == 0u) goto label_000406D3;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000406E5;
    label_000406D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4406D3u);
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffeditor, EDSC_GETCLICKPOINT\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4406E2u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000406E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4406E5u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0004073E;
    lift_x87_push(cpu, 0.0);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440709u); lift_push32(cpu, r); sfera_sub_004731C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->edx + cpu->esi, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->edx + cpu->esi + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->edx + cpu->esi + 8u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_00040737;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_store_f32(cpu->edx + cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00040737: cpu->eip = LIFT_CODE_TOKEN_VA(0x440737u);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x4073Eu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_0004073E: cpu->eip = LIFT_CODE_TOKEN_VA(0x44073Eu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_00040740: cpu->eip = LIFT_CODE_TOKEN_VA(0x440740u);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00440750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x440750u);
    cpu->esp -= 0x30u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440763u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp, cpu->eax);
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x4Fu)) goto label_00041B5F;

    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    switch ((uint32_t)(cpu->eax)) {
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440786u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44078Du); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440794u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44079Du); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4407A4u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4407ABu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4407CDu); lift_push32(cpu, r); sfera_sub_004556B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4407D8u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000407FD;
    cpu->ecx = (uint32_t)(uintptr_t)"Error creating window";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4407EAu); lift_push32(cpu, r); sfera_sub_004385D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_000407FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4407FDu);
    cpu->edx = 6u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440807u); lift_push32(cpu, r); sfera_sub_00437A10(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_0004081A: cpu->eip = LIFT_CODE_TOKEN_VA(0x44081Au);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44081Fu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440837u); lift_push32(cpu, r); sfera_sub_00458E80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, 0u);
    cpu->edx = 6u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440847u); lift_push32(cpu, r); sfera_sub_00437B10(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_0004085A: cpu->eip = LIFT_CODE_TOKEN_VA(0x44085Au);
    cpu->ecx = g_sfera_graphics_runtime.display_width;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440865u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00040878: cpu->eip = LIFT_CODE_TOKEN_VA(0x440878u);
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440883u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00040896: cpu->eip = LIFT_CODE_TOKEN_VA(0x440896u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44089Bu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4408A2u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4408A9u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4408C4u); lift_push32(cpu, r); sfera_sub_0044FA20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4408CBu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_000408DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4408DEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4408E3u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4408EAu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041B5B;
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440900u); lift_push32(cpu, r); sfera_sub_0044F9E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440907u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_0004091A: cpu->eip = LIFT_CODE_TOKEN_VA(0x44091Au);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44091Fu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440926u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44092Du); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440948u); lift_push32(cpu, r); sfera_sub_0044FA50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44094Fu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00040962: cpu->eip = LIFT_CODE_TOKEN_VA(0x440962u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440967u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440970u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00040988;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, W_EVENT, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440985u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_00040988: cpu->eip = LIFT_CODE_TOKEN_VA(0x440988u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44098Du); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != 0u) goto label_000409A5;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, W_EVENT, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4409A2u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000409A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4409A5u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041B5B;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4409BBu); lift_push32(cpu, r); sfera_sub_00455820(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00040A5E;
    cpu->ecx = lift_load32(cpu->eax + 0x6E08u);
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_00040A5E;
    --cpu->ecx;
    lift_store32(cpu->eax + 0x6E08u, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u) + 0x6DB8u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->ecx + cpu->esi, cpu->edx);
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 0x6E08u);
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->edx) * 4u) + 0x6DE0u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00040A1A;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->eax + cpu->edi, cpu->ecx);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00040A1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x440A1Au);
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00040A3C;
    cpu->ecx = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->eax + cpu->edi, cpu->ecx);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00040A3C: cpu->eip = LIFT_CODE_TOKEN_VA(0x440A3Cu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(2u)) goto label_00040A43;
    cpu->ecx = cpu->eax;
    label_00040A43: cpu->eip = LIFT_CODE_TOKEN_VA(0x440A43u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->eax + cpu->edi, cpu->ecx);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00040A5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x440A5Eu);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->ecx + cpu->esi, 0xFFFFFFFFu);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->edx + cpu->edi, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00040A8B: cpu->eip = LIFT_CODE_TOKEN_VA(0x440A8Bu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440A90u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00040AA8;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, W_WINCON, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440AA5u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_00040AA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x440AA8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440AADu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != 0u) goto label_00040AC5;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, W_WINCON, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440AC2u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_00040AC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x440AC5u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041B5B;
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440ADFu); lift_push32(cpu, r); sfera_sub_00467910(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax + cpu->esi, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->eax + cpu->edi, cpu->edx);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00040B0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x440B0Au);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440B0Fu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440B18u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440B30u); lift_push32(cpu, r); sfera_sub_00455820(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00041B5B;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00040B4D: cpu->eip = LIFT_CODE_TOKEN_VA(0x440B4Du);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440B52u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440B5Bu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440B62u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440B69u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440B72u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440B8Au); lift_push32(cpu, r); sfera_sub_00455820(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00041B5B;
    cpu->ecx = lift_load32(cpu->eax + 0x1Cu);
    cpu->edx = lift_load32(cpu->eax + 0x20u);
    cpu->ecx += cpu->esi;
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    cpu->edx += lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->eax + 0x24u);
    cpu->ecx += cpu->edi;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax + 0x10u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0x28u);
    cpu->esi = lift_pop32(cpu);
    cpu->edx += cpu->ebx;
    cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax + 0x14u, cpu->ecx);
    lift_store32(cpu->eax + 0x18u, cpu->edx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00040BC7: cpu->eip = LIFT_CODE_TOKEN_VA(0x440BC7u);
    cpu->ecx = g_sfera_window_runtime.active_window_index;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440BD2u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00040BE5: cpu->eip = LIFT_CODE_TOKEN_VA(0x440BE5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440BEAu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00040C02;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, W_TEXTSIZE, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440BFFu); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_00040C02: cpu->eip = LIFT_CODE_TOKEN_VA(0x440C02u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440C07u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != 0u) goto label_00040C1F;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, W_TEXTSIZE, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440C1Cu); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_00040C1F: cpu->eip = LIFT_CODE_TOKEN_VA(0x440C1Fu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041B5B;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = g_sfera_recovered_static_runtime.text_size_height;
    lift_store32(cpu->eax + cpu->esi, cpu->ecx);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = g_sfera_input_device_runtime.process_value;
    lift_store32(cpu->edx + cpu->edi, cpu->eax);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00040C5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x440C5Bu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440C60u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440C67u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041B5B;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00040C7E;
    cpu->esi += 0x100u;
    label_00040C7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x440C7Eu);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440C87u); lift_push32(cpu, r); sfera_sub_0044FA00(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440C8Eu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00040CA1: cpu->eip = LIFT_CODE_TOKEN_VA(0x440CA1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440CA6u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440CAFu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440CC7u); lift_push32(cpu, r); sfera_sub_00455820(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00041B5B;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax + 4u, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00040CE5: cpu->eip = LIFT_CODE_TOKEN_VA(0x440CE5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440CEAu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440CF3u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00040D0B;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, W_GETCURXY, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440D08u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_00040D0B: cpu->eip = LIFT_CODE_TOKEN_VA(0x440D0Bu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440D10u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != 0u) goto label_00040D28;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, W_GETCURXY, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440D25u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_00040D28: cpu->eip = LIFT_CODE_TOKEN_VA(0x440D28u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041B5B;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(cpu->eax + cpu->edi);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = (uint32_t)(cpu->eax + cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440D4Au); lift_push32(cpu, r); sfera_sub_00468D30(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00040D5D: cpu->eip = LIFT_CODE_TOKEN_VA(0x440D5Du);
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->argument_count) <= (int32_t)(uint32_t)(1u)) goto label_00040DB2;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440D6Bu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440D81u); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }

    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = cpu->ecx & 0xFFu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->setSystemCursorVisible(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x440D96u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    g_sfera_recovered_static_runtime.interaction_enabled = (uint32_t)(cpu->eax);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00040DB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x440DB2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440DB7u); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }

    cpu->ecx = cpu->eax;

    reinterpret_cast<CCursor*>(cpu->ecx)->isSystemCursorVisible(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x440DC0u);
    cpu->ecx = cpu->eax & 0xFFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440DC8u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00040DDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x440DDBu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440DE0u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440DF6u); lift_push32(cpu, r); sfera_sub_00438460(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);

    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->setCursorKind(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x440E04u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00040E17: cpu->eip = LIFT_CODE_TOKEN_VA(0x440E17u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440E1Cu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00040E37;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440E2Eu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440E35u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    goto label_00040E3F;
    label_00040E37: cpu->eip = LIFT_CODE_TOKEN_VA(0x440E37u);
    cpu->esi = 8u;
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFF0u);
    label_00040E3F: cpu->eip = LIFT_CODE_TOKEN_VA(0x440E3Fu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041B5B;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440E58u); lift_push32(cpu, r); sfera_sub_004B84B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00040E6B: cpu->eip = LIFT_CODE_TOKEN_VA(0x440E6Bu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440E70u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_mbc_runtime->argument_count;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ecx) <= (int32_t)(uint32_t)(3u)) goto label_00040E99;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440E84u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440E8Bu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_mbc_runtime->argument_count;
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    goto label_00040EA1;
    label_00040E99: cpu->eip = LIFT_CODE_TOKEN_VA(0x440E99u);
    cpu->esi = 8u;
    cpu->edi = (uint32_t)(cpu->esi + 8u);
    label_00040EA1: cpu->eip = LIFT_CODE_TOKEN_VA(0x440EA1u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(3u)) goto label_00040EB0;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(5u)) goto label_00040EB0;
    cpu->ecx |= 0xFFFFFFFFu;
    goto label_00040EBB;
    label_00040EB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x440EB0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440EB5u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    label_00040EBB: cpu->eip = LIFT_CODE_TOKEN_VA(0x440EBBu);
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00040F19;
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_00040EE1;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->edi);
    cpu->ecx += cpu->eax;
    cpu->edx = cpu->esi;
    goto label_00040F1F;
    label_00040EE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x440EE1u);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, 0x20u); lift_push32(cpu, 8u);
    cpu->edx += cpu->eax;
    cpu->ecx = 2u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440EF7u); lift_push32(cpu, r); sfera_sub_004B8680(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0x10u;
    lift_push32(cpu, 0x10u);
    cpu->ecx = (uint32_t)(cpu->edx + 0xFFFFFFF2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440F06u); lift_push32(cpu, r); sfera_sub_004B86B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00040F19: cpu->eip = LIFT_CODE_TOKEN_VA(0x440F19u);
    cpu->edx = 0u;
    lift_push32(cpu, 0u);
    cpu->ecx = 0u;
    label_00040F1F: cpu->eip = LIFT_CODE_TOKEN_VA(0x440F1Fu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440F24u); lift_push32(cpu, r); sfera_sub_004B8630(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u);
    cpu->edx = 0u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->edx + 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440F32u); lift_push32(cpu, r); sfera_sub_004B8680(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00040F45: cpu->eip = LIFT_CODE_TOKEN_VA(0x440F45u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440F4Au); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440F53u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(3u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00040F72;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440F65u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440F6Cu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    goto label_00040F97;
    label_00040F72: cpu->eip = LIFT_CODE_TOKEN_VA(0x440F72u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_00040F82;
    cpu->esi = (uint32_t)(cpu->ecx + 6u);
    cpu->eax = (uint32_t)(cpu->ecx + 0x28u);
    goto label_00040F97;
    label_00040F82: cpu->eip = LIFT_CODE_TOKEN_VA(0x440F82u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(1u)) goto label_00040F8F;
    cpu->esi = (uint32_t)(cpu->ecx + 0xFu);
    cpu->eax = (uint32_t)(cpu->ecx + 5u);
    goto label_00040F97;
    label_00040F8F: cpu->eip = LIFT_CODE_TOKEN_VA(0x440F8Fu);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    label_00040F97: cpu->eip = LIFT_CODE_TOKEN_VA(0x440F97u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041B5B;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->edx += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440FB5u); lift_push32(cpu, r); sfera_sub_004B86D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00040FC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x440FC8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440FCDu); lift_push32(cpu, r); sfera_sub_004B83C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00041A9F;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440FDAu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440FE3u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440FEAu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x440FF1u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441015u); lift_push32(cpu, r); sfera_sub_004BAAA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441020u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00041B5B;
    cpu->edx = 7u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441036u); lift_push32(cpu, r); sfera_sub_00437A10(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00041049: cpu->eip = LIFT_CODE_TOKEN_VA(0x441049u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44104Eu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    cpu->edx = 1u;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44106Bu); lift_push32(cpu, r); sfera_sub_004B8700(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, 0u);
    cpu->edx = 7u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44107Bu); lift_push32(cpu, r); sfera_sub_00437B10(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_0004108E: cpu->eip = LIFT_CODE_TOKEN_VA(0x44108Eu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441093u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000410AD;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, PEEK_MESSAGE, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4410AAu); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000410AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4410ADu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4410B2u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ebx) != 0u) goto label_000410CA;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, PEEK_MESSAGE, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4410C7u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000410CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4410CAu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4410CFu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000410E7;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, PEEK_MESSAGE, 3\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4410E4u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000410E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4410E7u);
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->argument_count) < (int32_t)(uint32_t)(5u)) goto label_0004110F;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4410F5u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0004110F;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, PEEK_MESSAGE, 4\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44110Cu); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_0004110F: cpu->eip = LIFT_CODE_TOKEN_VA(0x44110Fu);
    cpu->ebp = 6u;
    if ((uint32_t)(g_sfera_mbc_runtime->argument_count) != (uint32_t)(cpu->ebp)) goto label_0004113B;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441121u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != 0u) goto label_0004113F;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, PEEK_MESSAGE, 5\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441136u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    goto label_0004113F;
    label_0004113B: cpu->eip = LIFT_CODE_TOKEN_VA(0x44113Bu);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    label_0004113F: cpu->eip = LIFT_CODE_TOKEN_VA(0x44113Fu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041B5B;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441159u); lift_push32(cpu, r); sfera_sub_004B8740(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00041A9F;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->edx + cpu->ebx, cpu->eax);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->edx + cpu->esi, cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    if ((uint32_t)(cpu->eax) != (uint32_t)(5u)) goto label_0004120C;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x28u)), r=(uint64_t)(0xFA1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000411DE;
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x10u), 32u);
    lift_store32(cpu->ecx + cpu->ebx, cpu->eax);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->edx + cpu->esi, cpu->eax);
    cpu->ecx = lift_load16(cpu->esp + 0x30u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->eax + cpu->edx, cpu->ecx);
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4411CBu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_000411DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4411DEu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->edx + cpu->ecx, 0xFFFFFFFFu);
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4411F9u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_0004120C: cpu->eip = LIFT_CODE_TOKEN_VA(0x44120Cu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebp)) goto label_0004122D;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->eax + cpu->ecx, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->ecx + cpu->edi, cpu->eax);
    label_0004122D: cpu->eip = LIFT_CODE_TOKEN_VA(0x44122Du);
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441237u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_0004124A: cpu->eip = LIFT_CODE_TOKEN_VA(0x44124Au);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44124Fu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441258u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041B5B;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx += cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441276u); lift_push32(cpu, r); sfera_sub_004BACE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44127Du); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00041290: cpu->eip = LIFT_CODE_TOKEN_VA(0x441290u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441295u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44129Eu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041B5B;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4412B6u); lift_push32(cpu, r); sfera_sub_004B9820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4412BDu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_000412D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4412D0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4412D5u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4412DCu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4412E3u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4412EAu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4412F1u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041B5B;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_0004130E;
    if ((uint32_t)(cpu->edi) == 0u) goto label_0004130E;
    cpu->edi += cpu->ecx;
    label_0004130E: cpu->eip = LIFT_CODE_TOKEN_VA(0x44130Eu);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (2u)) == 0u) goto label_00041318;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00041318;
    cpu->esi += cpu->ecx;
    label_00041318: cpu->eip = LIFT_CODE_TOKEN_VA(0x441318u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441323u); lift_push32(cpu, r); sfera_sub_004BB750(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44132Au); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_0004133D: cpu->eip = LIFT_CODE_TOKEN_VA(0x44133Du);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441342u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44134Bu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00041363;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, GET_WINDOW_TEXT\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441360u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_00041363: cpu->eip = LIFT_CODE_TOKEN_VA(0x441363u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441368u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041B5B;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(1u)) goto label_0004137F;
    cpu->eax = 1u;
    label_0004137F: cpu->eip = LIFT_CODE_TOKEN_VA(0x44137Fu);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    --cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->edx + cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441393u); lift_push32(cpu, r); sfera_sub_004B9150(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44139Au); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_000413AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4413ADu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4413B2u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000413CC;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, GET_SYSTEM_MESSAGE\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4413C9u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000413CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4413CCu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041B5B;
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4413E2u); lift_push32(cpu, r); sfera_sub_004BA6B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4413E9u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax + cpu->ecx, cpu->edx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_0004140C: cpu->eip = LIFT_CODE_TOKEN_VA(0x44140Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441411u); lift_push32(cpu, r); sfera_sub_004B98B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441418u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_0004142B: cpu->eip = LIFT_CODE_TOKEN_VA(0x44142Bu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441430u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441439u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041B5B;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441451u); lift_push32(cpu, r); sfera_sub_004B8750(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441458u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_0004146B: cpu->eip = LIFT_CODE_TOKEN_VA(0x44146Bu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441470u); lift_push32(cpu, r); sfera_sub_004B99E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44147Bu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_0004148E: cpu->eip = LIFT_CODE_TOKEN_VA(0x44148Eu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441493u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44149Cu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041B5B;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->ecx += g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4414BAu); lift_push32(cpu, r); sfera_sub_004BC650(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_000414CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4414CDu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4414D2u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4414F0u); lift_push32(cpu, r); sfera_sub_004B9A10(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00041503: cpu->eip = LIFT_CODE_TOKEN_VA(0x441503u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441508u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441511u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00041529;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, GET_WINDOW_POS, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441526u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_00041529: cpu->eip = LIFT_CODE_TOKEN_VA(0x441529u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44152Eu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != 0u) goto label_00041546;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, GET_WINDOW_POS, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441543u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_00041546: cpu->eip = LIFT_CODE_TOKEN_VA(0x441546u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041B5B;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441565u); lift_push32(cpu, r); sfera_sub_004B87A0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->eax + cpu->esi, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->eax + cpu->edi, cpu->edx);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00041590: cpu->eip = LIFT_CODE_TOKEN_VA(0x441590u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441595u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44159Eu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4415A5u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4415C6u); lift_push32(cpu, r); sfera_sub_004B8780(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->edx + cpu->esi, cpu->eax);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->edx + cpu->edi, cpu->ecx);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_000415F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4415F3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4415F8u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441601u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041B5B;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0xFAu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441627u); lift_push32(cpu, r); sfera_sub_004A21F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44162Eu); lift_push32(cpu, r); sfera_sub_004A2670(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00041641: cpu->eip = LIFT_CODE_TOKEN_VA(0x441641u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441646u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00041675;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441662u); lift_push32(cpu, r); sfera_sub_004B8A40(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00041675: cpu->eip = LIFT_CODE_TOKEN_VA(0x441675u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441683u); lift_push32(cpu, r); sfera_sub_004B8A40(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00041696: cpu->eip = LIFT_CODE_TOKEN_VA(0x441696u);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19)) == (uint32_t)(0u)) goto label_00041A9F;
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(uintptr_t)"options";
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_000416DB;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4416B6u); lift_push32(cpu, r); sfera_sub_004B9A70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00041746;
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4416C8u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_000416DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4416DBu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4416E0u); lift_push32(cpu, r); sfera_sub_004B9A70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00041708;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4416EBu); lift_push32(cpu, r); sfera_sub_004CD1A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4416F5u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00041708: cpu->eip = LIFT_CODE_TOKEN_VA(0x441708u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44170Fu); lift_push32(cpu, r); sfera_sub_004CD1A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441719u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_0004172C: cpu->eip = LIFT_CODE_TOKEN_VA(0x44172Cu);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19)) == (uint32_t)(0u)) goto label_00041A9F;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44173Eu); lift_push32(cpu, r); sfera_sub_004B9AD0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00041AD4;
    label_00041746: cpu->eip = LIFT_CODE_TOKEN_VA(0x441746u);
    cpu->ecx |= 0xFFFFFFFFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44174Eu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00041761: cpu->eip = LIFT_CODE_TOKEN_VA(0x441761u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441766u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44176Fu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44178Bu); lift_push32(cpu, r); sfera_sub_004D14A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441796u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000417BB;
    cpu->ecx = (uint32_t)(uintptr_t)"Error creating GUI window";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4417A8u); lift_push32(cpu, r); sfera_sub_004385D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_000417BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4417BBu);
    cpu->edx = 8u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4417C5u); lift_push32(cpu, r); sfera_sub_00437A10(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_000417D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4417D8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4417DDu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041B5B;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4417F5u); lift_push32(cpu, r); sfera_sub_004D12C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, 0u);
    cpu->edx = 8u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441805u); lift_push32(cpu, r); sfera_sub_00437B10(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00041818: cpu->eip = LIFT_CODE_TOKEN_VA(0x441818u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44181Du); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441826u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != 0u) goto label_0004183E;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, PEEK_MESSAGEGUI, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44183Bu); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_0004183E: cpu->eip = LIFT_CODE_TOKEN_VA(0x44183Eu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441843u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ebx) != 0u) goto label_0004185B;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, PEEK_MESSAGEGUI, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441858u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_0004185B: cpu->eip = LIFT_CODE_TOKEN_VA(0x44185Bu);
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->argument_count) < (int32_t)(uint32_t)(5u)) goto label_00041883;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441869u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00041883;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, PEEK_MESSAGEGUI, 3\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441880u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_00041883: cpu->eip = LIFT_CODE_TOKEN_VA(0x441883u);
    cpu->ebp = 6u;
    if ((uint32_t)(g_sfera_mbc_runtime->argument_count) != (uint32_t)(cpu->ebp)) goto label_000418AF;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441895u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000418B3;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, PEEK_MESSAGEGUI, 4\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4418AAu); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    goto label_000418B3;
    label_000418AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4418AFu);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    label_000418B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4418B3u);
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->argument_count) < (int32_t)(uint32_t)(5u)) goto label_000418C5;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4418C1u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    label_000418C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4418C5u);
    if ((uint32_t)(g_sfera_mbc_runtime->argument_count) != (uint32_t)(cpu->ebp)) goto label_000418D4;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4418D2u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    label_000418D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4418D4u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041B5B;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4418EEu); lift_push32(cpu, r); sfera_sub_004D1360(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00041A9F;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->eax + cpu->edi, cpu->ecx);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->edx + cpu->ebx, cpu->eax);
    if ((uint32_t)(g_sfera_mbc_runtime->argument_count) != (uint32_t)(cpu->ebp)) goto label_00041935;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->ecx + cpu->edx, cpu->eax);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->ecx + cpu->esi, cpu->edx);
    label_00041935: cpu->eip = LIFT_CODE_TOKEN_VA(0x441935u);
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44193Fu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00041952: cpu->eip = LIFT_CODE_TOKEN_VA(0x441952u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441957u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441960u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441967u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44196Eu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441977u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041B5B;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_00041990;
    cpu->esi += cpu->ecx;
    label_00041990: cpu->eip = LIFT_CODE_TOKEN_VA(0x441990u);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (2u)) == 0u) goto label_00041998;
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    label_00041998: cpu->eip = LIFT_CODE_TOKEN_VA(0x441998u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4419A9u); lift_push32(cpu, r); sfera_sub_004D1060(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4419B0u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_000419C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4419C3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4419C8u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4419D1u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041B5B;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4419E9u); lift_push32(cpu, r); sfera_sub_004D0F50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4419F0u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00041A03: cpu->eip = LIFT_CODE_TOKEN_VA(0x441A03u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441A08u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441A11u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041B5B;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = (uint32_t)(cpu->edx + cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441A30u); lift_push32(cpu, r); sfera_sub_004D10D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441A37u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00041A4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x441A4Au);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441A4Fu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441A58u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00041A70;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, GET_WINDOW_TEXTGUI\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441A6Du); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_00041A70: cpu->eip = LIFT_CODE_TOKEN_VA(0x441A70u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441A75u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041B5B;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(1u)) goto label_00041A8C;
    cpu->eax = 1u;
    label_00041A8C: cpu->eip = LIFT_CODE_TOKEN_VA(0x441A8Cu);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    --cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->edx += cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x41A9Fu); lift_push32(cpu, r); sfera_sub_004D1110(cpu,r); if (cpu->eip != r) return; }
    label_00041A9F: cpu->eip = LIFT_CODE_TOKEN_VA(0x441A9Fu);
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441AA6u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00041AB9: cpu->eip = LIFT_CODE_TOKEN_VA(0x441AB9u);
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->argument_count) <= (int32_t)(uint32_t)(1u)) goto label_00041AF1;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441AC7u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state_04)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00041A9F;
    label_00041AD4: cpu->eip = LIFT_CODE_TOKEN_VA(0x441AD4u);
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441ADEu); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00041AF1: cpu->eip = LIFT_CODE_TOKEN_VA(0x441AF1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    g_sfera_client_process_runtime.shutdown_requested = (uint32_t)(1u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00041B0E: cpu->eip = LIFT_CODE_TOKEN_VA(0x441B0Eu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441B13u); lift_push32(cpu, r); sfera_sub_0044C160(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00041B26: cpu->eip = LIFT_CODE_TOKEN_VA(0x441B26u);
    if ((uint32_t)(g_sfera_recovered_static_runtime.loadcount_guard) != (uint32_t)(0u)) goto label_00041B5B;
    cpu->ecx = 0x50u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441B39u); lift_push32(cpu, r); sfera_sub_00461700(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
    label_00041B4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x441B4Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441B51u); lift_push32(cpu, r); sfera_sub_00451890(cpu,r); if (cpu->eip != r) return; }
    g_sfera_recovered_static_runtime.loadcount_guard = (uint32_t)(1u);
    label_00041B5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x441B5Bu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00041B5F: cpu->eip = LIFT_CODE_TOKEN_VA(0x441B5Fu);
    cpu->esp += 0x30u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00441C90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x441C90u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441C96u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00041CAE;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: thisname\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441CABu); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_00041CAE: cpu->eip = LIFT_CODE_TOKEN_VA(0x441CAEu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041CD2;
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += 0x10u;
    cpu->edx += cpu->esi;
    label_00041CC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x441CC8u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00041CC8;
    label_00041CD2: cpu->eip = LIFT_CODE_TOKEN_VA(0x441CD2u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00441CE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x441CE0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441CE7u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441CEEu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != 0u) goto label_00041D06;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: prc_name\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441D03u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_00041D06: cpu->eip = LIFT_CODE_TOKEN_VA(0x441D06u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041D5B;
    if ((uint32_t)(cpu->esi) <= (uint32_t)(0xFFFFu)) goto label_00041D21;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00041D21: cpu->eip = LIFT_CODE_TOKEN_VA(0x441D21u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    cpu->esi += ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0]);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x6Cu)) >= (int32_t)(uint32_t)(0u)) goto label_00041D3D;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00041D3D: cpu->eip = LIFT_CODE_TOKEN_VA(0x441D3Du);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(cpu->esi + 0x10u);
    cpu->edx += cpu->edi;
    label_00041D48: cpu->eip = LIFT_CODE_TOKEN_VA(0x441D48u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00041D48;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00041D5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x441D5Bu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00441D60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x441D60u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441D66u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441D6Du); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041DBF;
    if ((uint32_t)(cpu->esi) > (uint32_t)(0xFFFu)) goto label_00041DB6;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x8D8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi += cpu->eax;
    cpu->eax = (uint32_t)(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0]));
    cpu->edx = cpu->edi;
    cpu->edx -= cpu->eax;
    label_00041D97: cpu->eip = LIFT_CODE_TOKEN_VA(0x441D97u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00041D97;
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00041DAF;
    cpu->ecx |= 0xFFFFFFFFu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00041DAF: cpu->eip = LIFT_CODE_TOKEN_VA(0x441DAFu);
    cpu->ecx = 0u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00041DB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x441DB6u);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00041DBF: cpu->eip = LIFT_CODE_TOKEN_VA(0x441DBFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00441DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x441DD0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441DD5u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041E7D;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::_stricmp);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx += cpu->eax;
    cpu->edi = 0u;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0];
    label_00041E00: cpu->eip = LIFT_CODE_TOKEN_VA(0x441E00u);
    if ((uint8_t)(lift_load8(cpu->esi)) == (uint8_t)(0u)) goto label_00041E10;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x41E09u), LIFT_CODE_TOKEN_RVA(0x41E07u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x441E09u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00041E3B;
    label_00041E10: cpu->eip = LIFT_CODE_TOKEN_VA(0x441E10u);
    ++cpu->edi;
    cpu->esi += 0x8D8u;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(0x1000u)) goto label_00041E00;
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00041E46;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_00041E3B: cpu->eip = LIFT_CODE_TOKEN_VA(0x441E3Bu);
    cpu->ecx = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00041E46: cpu->eip = LIFT_CODE_TOKEN_VA(0x441E46u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->edx |= 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(cpu->edx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(cpu->edx);
    cpu->edx = 1u;
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->edx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->edx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    label_00041E7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x441E7Du);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00441E80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x441E80u);
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) != (uint32_t)(4u)) goto label_00041EE3;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441E94u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441E9Bu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441EA2u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441EA7u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041FD3;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00041EC7;
    cpu->edx = (uint32_t)(uintptr_t)"";
    cpu->ecx = (uint32_t)(uintptr_t)"Effect attached to zero handle!";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x41EC7u); lift_push32(cpu, r); sfera_sub_00438640(cpu,r); if (cpu->eip != r) return; }
    label_00041EC7: cpu->eip = LIFT_CODE_TOKEN_VA(0x441EC7u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->edi);
    cpu->edx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441ED7u); lift_push32(cpu, r); sfera_sub_0042AD40(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00041EE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x441EE3u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(3u)) goto label_00041F43;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441EEDu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441EF4u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041FD3;
    if ((int32_t)(uint32_t)(cpu->esi) > 0) goto label_00041F2E;
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    cpu->ecx += 0x10u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Wrong Handler for Effect %s\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441F1Eu); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00041F2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x441F2Eu);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441F37u); lift_push32(cpu, r); sfera_sub_0042AB10(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00041F43: cpu->eip = LIFT_CODE_TOKEN_VA(0x441F43u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441F48u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441F4Fu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441F56u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00041FD3;
    if ((int32_t)(uint32_t)(cpu->esi) > 0) goto label_00041F8D;
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->edx += 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"Wrong Handler for Effect %s\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441F7Cu); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_00041F7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x441F7Fu);
    cpu->ecx |= 0xFFFFFFFFu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441F87u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
    label_00041F8D: cpu->eip = LIFT_CODE_TOKEN_VA(0x441F8Du);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00041FAF;
    if ((uint32_t)(cpu->esi) == (uint32_t)(g_sfera_world_objects.controlled_object_handle)) goto label_00041F7F;
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441FA2u); lift_push32(cpu, r); sfera_sub_0042AB10(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441FA9u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
    label_00041FAF: cpu->eip = LIFT_CODE_TOKEN_VA(0x441FAFu);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    lift_push32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0xCu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441FCCu); lift_push32(cpu, r); sfera_sub_00425CF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x41FD3u); lift_push32(cpu, r); sfera_sub_0043B0D0(cpu,r); if (cpu->eip != r) return; }
    label_00041FD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x441FD3u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00441FE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x441FE0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x441FE9u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00042028;
    if ((int32_t)(uint32_t)(cpu->esi) > 0) goto label_00042003;
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00042003: cpu->eip = LIFT_CODE_TOKEN_VA(0x442003u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44200Au); lift_push32(cpu, r); sfera_sub_004360D0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 4u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->eax + cpu->esi + 0xFFFFFFFFu);
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x42028u); lift_push32(cpu, r); sfera_sub_0043AF30(cpu,r); if (cpu->eip != r) return; }
    label_00042028: cpu->eip = LIFT_CODE_TOKEN_VA(0x442028u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00442030(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x442030u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442038u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44203Fu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000420A8;
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->eax)) goto label_00042053;
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_000420A8;
    label_00042053: cpu->eip = LIFT_CODE_TOKEN_VA(0x442053u);
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44205Du); lift_push32(cpu, r); sfera_sub_00434AF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44207Du); lift_push32(cpu, r); sfera_sub_0049B7F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->esp += 0x18u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000420A8;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000420A8;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00042098;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_000420A8;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_00042098: cpu->eip = LIFT_CODE_TOKEN_VA(0x442098u);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0004209F;
    lift_store32(cpu->esi + 4u, cpu->eax);
    goto label_000420A8;
    label_0004209F: cpu->eip = LIFT_CODE_TOKEN_VA(0x44209Fu);
    --cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(lift_load32(cpu->esi + 8u))) goto label_000420A8;
    lift_store32(cpu->esi + 8u, cpu->eax);
    label_000420A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4420A8u);
    cpu->ebx = lift_load32(cpu->esi);
    cpu->ebx += g_sfera_mbc_runtime->process_memory_base;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0004212E;
    lift_push32(cpu, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ebp) > 0) goto label_000420C2;
    cpu->edi = 0u;
    goto label_0004210A;
    label_000420C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4420C2u);
    lift_push32(cpu, 0x35B4u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4420D3u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000420DB;
    cpu->edi = 0u;
    goto label_0004210A;
    label_000420DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4420DBu);
    cpu->eax -= g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = 3u;
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4420EFu); lift_push32(cpu, r); sfera_sub_00437A10(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_mbc_runtime->active_process;
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + 0x44u)) <= (int32_t)(uint32_t)(0u)) goto label_0004210A;
    cpu->eax = lift_load32(cpu->eax + 0x44u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->ecx = (uint32_t)(cpu->ebp + 8u);
    g_sfera_mbc_module_memory_stats[cpu->eax / 3u].dynamic_memory_bytes += cpu->ecx;
    label_0004210A: cpu->eip = LIFT_CODE_TOKEN_VA(0x44210Au);
    if ((uint32_t)(lift_load32(cpu->ebx)) == (uint32_t)(0u)) goto label_00042121;
    lift_push32(cpu, (uintptr_t)"ffdmalloc: ptr != NULL"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44211Eu); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_00042121: cpu->eip = LIFT_CODE_TOKEN_VA(0x442121u);
    cpu->edx = (uint32_t)(cpu->edi + cpu->ebp + 0xFFFFFFFFu);
    lift_store32(cpu->ebx + 4u, cpu->edi);
    lift_store32(cpu->ebx, cpu->edi);
    lift_store32(cpu->ebx + 8u, cpu->edx);
    cpu->edi = lift_pop32(cpu);
    label_0004212E: cpu->eip = LIFT_CODE_TOKEN_VA(0x44212Eu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00442140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x442140u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442147u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000421B0;
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->eax)) goto label_0004215B;
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_000421B0;
    label_0004215B: cpu->eip = LIFT_CODE_TOKEN_VA(0x44215Bu);
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442165u); lift_push32(cpu, r); sfera_sub_00434AF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442185u); lift_push32(cpu, r); sfera_sub_0049B7F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->esp += 0x18u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000421B0;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000421B0;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000421A0;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_000421B0;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_000421A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4421A0u);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_000421A7;
    lift_store32(cpu->esi + 4u, cpu->eax);
    goto label_000421B0;
    label_000421A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4421A7u);
    --cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(lift_load32(cpu->esi + 8u))) goto label_000421B0;
    lift_store32(cpu->esi + 8u, cpu->eax);
    label_000421B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4421B0u);
    cpu->edi = lift_load32(cpu->esi);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi += cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00042219;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_00042218;
    cpu->ebx += cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->active_process;
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + 0x44u)) <= (int32_t)(uint32_t)(0u)) goto label_000421F2;
    cpu->eax = lift_load32(cpu->eax + 0x44u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = (uint32_t)(cpu->ebx + 0xFFFFFFFCu);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_msize), LIFT_CODE_TOKEN_VA(0x4421E1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4421E7u);
    cpu->esp += 4u;
    g_sfera_mbc_module_memory_stats[cpu->ebp / 3u].dynamic_memory_bytes -= cpu->eax;
    cpu->ebp = lift_pop32(cpu);
    label_000421F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4421F2u);
    lift_push32(cpu, 0x35EFu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442203u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_store32(cpu->edi, cpu->eax);
    lift_store32(cpu->edi + 4u, cpu->eax);
    lift_store32(cpu->edi + 8u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->eax + 3u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x42218u); lift_push32(cpu, r); sfera_sub_00437B10(cpu,r); if (cpu->eip != r) return; }
    label_00042218: cpu->eip = LIFT_CODE_TOKEN_VA(0x442218u);
    cpu->ebx = lift_pop32(cpu);
    label_00042219: cpu->eip = LIFT_CODE_TOKEN_VA(0x442219u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00442220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x442220u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442229u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442230u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 8u, cpu->eax);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00042250;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442242u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 4u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_00042392;
    goto label_00042258;
    label_00042250: cpu->eip = LIFT_CODE_TOKEN_VA(0x442250u);
    lift_store32(cpu->esp + 4u, 0u);
    label_00042258: cpu->eip = LIFT_CODE_TOKEN_VA(0x442258u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->edi);
    cpu->edi = g_sfera_mbc_runtime->named_vector_count;
    cpu->ebp += cpu->esi;
    cpu->ebx = 0u;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->named_vectors[0];
    g_sfera_mbc_runtime->named_vector_cursor = (uint32_t)(cpu->esi);
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_000422BC;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00042280: cpu->eip = LIFT_CODE_TOKEN_VA(0x442280u);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->eax = cpu->ebp;
    label_00042285: cpu->eip = LIFT_CODE_TOKEN_VA(0x442285u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000422A5;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_000422A1;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000422A5;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00042285;
    label_000422A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4422A1u);
    cpu->eax = 0u;
    goto label_000422AA;
    label_000422A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4422A5u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000422AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4422AAu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00042323;
    cpu->esi += 0x10u;
    ++cpu->ebx;
    g_sfera_mbc_runtime->named_vector_cursor = (uint32_t)(cpu->esi);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->edi)) goto label_00042280;
    label_000422BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4422BCu);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0x3E8u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0004238F;
    cpu->ecx = cpu->edi;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    cpu->ecx += ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->named_vectors[0]);
    ++cpu->edi;
    cpu->eax = cpu->ebp;
    g_sfera_mbc_runtime->named_vector_cursor = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->named_vector_count = (uint32_t)(cpu->edi);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000422E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4422E5u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000422E5;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, 0x362Fu);
    cpu->ecx = (uint32_t)(cpu->eax + 1u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442300u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_mbc_runtime->named_vector_cursor;
    lift_store32(cpu->edx + 0xCu, cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->named_vector_cursor;
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    cpu->ecx = cpu->ebp;
    label_00042313: cpu->eip = LIFT_CODE_TOKEN_VA(0x442313u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00042313;
    cpu->esi = g_sfera_mbc_runtime->named_vector_cursor;
    label_00042323: cpu->eip = LIFT_CODE_TOKEN_VA(0x442323u);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) > (int32_t)(uint32_t)(cpu->edi)) goto label_00042386;
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, 0x3634u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp");
    cpu->edx = (uint32_t)(((uint32_t)(cpu->edi) * 4u) + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442344u); lift_push32(cpu, r); sfera_sub_004EBE80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_mbc_runtime->named_vector_cursor;
    lift_store32(cpu->ecx, cpu->eax);
    cpu->edx = g_sfera_mbc_runtime->named_vector_cursor;
    cpu->eax = lift_load32(cpu->edx + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->edi)) goto label_00042374;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00042360: cpu->eip = LIFT_CODE_TOKEN_VA(0x442360u);
    cpu->ecx = g_sfera_mbc_runtime->named_vector_cursor;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->edx + ((uint32_t)(cpu->eax) * 4u), 0u);
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edi)) goto label_00042360;
    label_00042374: cpu->eip = LIFT_CODE_TOKEN_VA(0x442374u);
    cpu->ecx = g_sfera_mbc_runtime->named_vector_cursor;
    cpu->eax = (uint32_t)(cpu->edi + 1u);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    cpu->esi = g_sfera_mbc_runtime->named_vector_cursor;
    label_00042386: cpu->eip = LIFT_CODE_TOKEN_VA(0x442386u);
    cpu->edx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->edi) * 4u), cpu->eax);
    label_0004238F: cpu->eip = LIFT_CODE_TOKEN_VA(0x44238Fu);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00042392: cpu->eip = LIFT_CODE_TOKEN_VA(0x442392u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004423A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4423A0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4423AAu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 1u;
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->argument_count) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_000423C4;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4423BEu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    goto label_000423CC;
    label_000423C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4423C4u);
    lift_store32(cpu->esp + 0x10u, 0u);
    label_000423CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4423CCu);
    cpu->ebp = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = g_sfera_mbc_runtime->named_vector_count;
    cpu->ebp += cpu->esi;
    cpu->edi = 0u;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->named_vectors[0];
    g_sfera_mbc_runtime->named_vector_cursor = (uint32_t)(cpu->esi);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00042435;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000423F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4423F0u);
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    cpu->ecx = cpu->ebp;
    label_000423F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4423F5u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->ebx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->edx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00042415;
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_00042411;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->ebx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->edx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00042415;
    cpu->ecx += 2u;
    cpu->edx += 2u;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != 0u) goto label_000423F5;
    label_00042411: cpu->eip = LIFT_CODE_TOKEN_VA(0x442411u);
    cpu->ecx = 0u;
    goto label_0004241A;
    label_00042415: cpu->eip = LIFT_CODE_TOKEN_VA(0x442415u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = (uint64_t)(cpu->ecx) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_0004241A: cpu->eip = LIFT_CODE_TOKEN_VA(0x44241Au);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000424AD;
    ++cpu->edi;
    cpu->esi += 0x10u;
    g_sfera_mbc_runtime->named_vector_cursor = (uint32_t)(cpu->esi);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->eax)) goto label_000423F0;
    cpu->ebx = 1u;
    label_00042435: cpu->eip = LIFT_CODE_TOKEN_VA(0x442435u);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00042524;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44244Cu); lift_push32(cpu, r); sfera_sub_00434D90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"\n---exit_inter start---\nMBINTER MESSAGE:";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442456u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442460u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"\n";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44246Au); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442474u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"---exit_inter end-----\n";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44247Eu); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->process_index), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    g_sfera_mbc_runtime->execution_failed = (uint32_t)(cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00042497;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x42497u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00042497: cpu->eip = LIFT_CODE_TOKEN_VA(0x442497u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->edx = (uint32_t)(uintptr_t)"EError";
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0];
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00435020(cpu, stop_address); return;
    label_000424AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4424ADu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00042501;
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->edx = lift_load32(cpu->esi + 4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000424D7;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_004385D0(cpu, stop_address); return;
    label_000424D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4424D7u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(cpu->edx);
    cpu->edx = 1u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->edx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->edx);
    cpu->ecx += cpu->edx;
    goto label_0004254B;
    label_00042501: cpu->eip = LIFT_CODE_TOKEN_VA(0x442501u);
    cpu->edi = lift_pop32(cpu);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00042514;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00042514: cpu->eip = LIFT_CODE_TOKEN_VA(0x442514u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00042524: cpu->eip = LIFT_CODE_TOKEN_VA(0x442524u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(0u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->ebx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->ebx);
    cpu->ecx += cpu->ebx;
    label_0004254B: cpu->eip = LIFT_CODE_TOKEN_VA(0x44254Bu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00442570(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x442570u);
    cpu->esp -= 0xCu;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_font_runtime;
    cpu->eax -= g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = 1u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp, cpu->eax);
    cpu->eax += 7u;
    cpu->ecx = (uint32_t)(cpu->esp);
    lift_store32(cpu->esp + 8u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442599u); lift_push32(cpu, r); sfera_sub_0043AF30(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004425A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4425A0u);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000425B8;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_000425B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4425B8u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    cpu->edx |= 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(cpu->edx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(cpu->edx);
    cpu->edx = 1u;
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->edx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->edx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004425F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4425F0u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4425F6u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4425FDu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00042616;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004385D0(cpu, stop_address); return;
    label_00042616: cpu->eip = LIFT_CODE_TOKEN_VA(0x442616u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = (uint32_t)(0x10u);
    cpu->eax &= cpu->esi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].payload[0] = (uint32_t)(cpu->eax);
    cpu->eax = 1u;
    cpu->edx += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_end = (uint32_t)(cpu->eax);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_begin = (uint32_t)(cpu->eax);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00442660(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x442660u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442666u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44266Du); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00042686;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004385D0(cpu, stop_address); return;
    label_00042686: cpu->eip = LIFT_CODE_TOKEN_VA(0x442686u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = (uint32_t)(0x10u);
    cpu->eax |= cpu->esi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].payload[0] = (uint32_t)(cpu->eax);
    cpu->eax = 1u;
    cpu->edx += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_end = (uint32_t)(cpu->eax);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_begin = (uint32_t)(cpu->eax);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004426D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4426D0u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4426D6u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4426DDu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000426F6;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004385D0(cpu, stop_address); return;
    label_000426F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4426F6u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = (uint32_t)(0x10u);
    cpu->eax ^= cpu->esi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].payload[0] = (uint32_t)(cpu->eax);
    cpu->eax = 1u;
    cpu->edx += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_end = (uint32_t)(cpu->eax);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_begin = (uint32_t)(cpu->eax);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00442740(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x442740u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442745u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0004275D;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0004275D: cpu->eip = LIFT_CODE_TOKEN_VA(0x44275Du);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = (uint32_t)(0x10u);
    cpu->eax = ~((uint64_t)(cpu->eax));
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].payload[0] = (uint32_t)(cpu->eax);
    cpu->eax = 1u;
    cpu->edx += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_end = (uint32_t)(cpu->eax);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_begin = (uint32_t)(cpu->eax);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004427A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4427A0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4427A7u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4427AEu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000427C8;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004385D0(cpu, stop_address); return;
    label_000427C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4427C8u);
    cpu->ecx = cpu->eax;
    cpu->eax = 1u;
    cpu->edx = cpu->edi;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(5u), 32u);
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    cpu->edi += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edi);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].payload[0] = (uint32_t)(cpu->esi);
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].range_end = (uint32_t)(cpu->eax);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].range_begin = (uint32_t)(cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00442810(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x442810u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442817u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44281Eu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00042838;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004385D0(cpu, stop_address); return;
    label_00042838: cpu->eip = LIFT_CODE_TOKEN_VA(0x442838u);
    cpu->ecx = cpu->eax;
    cpu->eax = 1u;
    cpu->edx = cpu->edi;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(5u), 32u);
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    cpu->edi += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edi);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].payload[0] = (uint32_t)(cpu->esi);
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].range_end = (uint32_t)(cpu->eax);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].range_begin = (uint32_t)(cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00442880(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x442880u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442887u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44288Eu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000428A8;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004385D0(cpu, stop_address); return;
    label_000428A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4428A8u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = 1u;
    cpu->ecx = cpu->eax;
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    cpu->edx = cpu->esi;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].type = (uint32_t)(0x10u);
    cpu->ebp = ~((uint64_t)(cpu->ebp));
    cpu->ebp &= cpu->edi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].payload[0] = (uint32_t)(cpu->ebp);
    cpu->ebp = lift_pop32(cpu);
    ++cpu->esi;
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->esi);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].range_end = (uint32_t)(1u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].range_begin = (uint32_t)(1u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00442900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x442900u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442907u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44290Eu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00042928;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004385D0(cpu, stop_address); return;
    label_00042928: cpu->eip = LIFT_CODE_TOKEN_VA(0x442928u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = 1u;
    cpu->ecx = cpu->eax;
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    cpu->edx = cpu->esi;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].type = (uint32_t)(0x10u);
    cpu->ebp |= cpu->edi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].payload[0] = (uint32_t)(cpu->ebp);
    cpu->ebp = lift_pop32(cpu);
    ++cpu->esi;
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->esi);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].range_end = (uint32_t)(1u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].range_begin = (uint32_t)(1u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00442980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x442980u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442987u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x44298Eu); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000429AA;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004385D0(cpu, stop_address); return;
    label_000429AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4429AAu);
    lift_push32(cpu, cpu->ebx);
    cpu->eax = 1u;
    cpu->ebx = cpu->eax;
    cpu->ebx = lift_shift_left(cpu, cpu->ebx, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    cpu->edx = cpu->esi;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].type = (uint32_t)(0x10u);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->edi), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebx = v; }
    cpu->ebx = lift_shift_arithmetic(cpu, cpu->ebx, (uint32_t)((cpu->ecx & 0xFFu)), 32u);
    cpu->esi += cpu->eax;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->esi);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].payload[0] = (uint32_t)(cpu->ebx);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].range_end = (uint32_t)(cpu->eax);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].range_begin = (uint32_t)(cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00442B60(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00042B60;
    label_000429F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4429F0u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4429FEu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->eax);
    cpu->ebx = lift_load32(cpu->eax + 4u);
    cpu->ebp = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442A17u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00042A76;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00042A2E;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(4u)) goto label_00042A3E;
    label_00042A2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x442A2Eu);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_00042A4B;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebx)) goto label_00042A3E;
    cpu->eax = (uint32_t)(cpu->esi + cpu->edi + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->ebp)) goto label_00042A4B;
    label_00042A3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x442A3Eu);
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442A49u); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    goto label_00042A68;
    label_00042A4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x442A4Bu);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->esi;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x442A5Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x442A5Fu);
    cpu->esp += 0xCu;
    cpu->esi += cpu->edi;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    label_00042A68: cpu->eip = LIFT_CODE_TOKEN_VA(0x442A68u);
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x42A76u); lift_push32(cpu, r); sfera_sub_0043AF30(cpu,r); if (cpu->eip != r) return; }
    label_00042A76: cpu->eip = LIFT_CODE_TOKEN_VA(0x442A76u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00042B60: cpu->eip = LIFT_CODE_TOKEN_VA(0x442B60u);
    cpu->ecx = 1u;
    goto label_000429F0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00442B70(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00042B70;
    label_000429F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4429F0u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4429FEu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->eax);
    cpu->ebx = lift_load32(cpu->eax + 4u);
    cpu->ebp = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442A17u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00042A76;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00042A2E;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(4u)) goto label_00042A3E;
    label_00042A2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x442A2Eu);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_00042A4B;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebx)) goto label_00042A3E;
    cpu->eax = (uint32_t)(cpu->esi + cpu->edi + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->ebp)) goto label_00042A4B;
    label_00042A3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x442A3Eu);
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442A49u); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    goto label_00042A68;
    label_00042A4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x442A4Bu);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->esi;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x442A5Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x442A5Fu);
    cpu->esp += 0xCu;
    cpu->esi += cpu->edi;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    label_00042A68: cpu->eip = LIFT_CODE_TOKEN_VA(0x442A68u);
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x42A76u); lift_push32(cpu, r); sfera_sub_0043AF30(cpu,r); if (cpu->eip != r) return; }
    label_00042A76: cpu->eip = LIFT_CODE_TOKEN_VA(0x442A76u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00042B70: cpu->eip = LIFT_CODE_TOKEN_VA(0x442B70u);
    cpu->ecx = 2u;
    goto label_000429F0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00442B80(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00042B80;
    label_000429F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4429F0u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4429FEu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->eax);
    cpu->ebx = lift_load32(cpu->eax + 4u);
    cpu->ebp = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442A17u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00042A76;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00042A2E;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(4u)) goto label_00042A3E;
    label_00042A2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x442A2Eu);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_00042A4B;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebx)) goto label_00042A3E;
    cpu->eax = (uint32_t)(cpu->esi + cpu->edi + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->ebp)) goto label_00042A4B;
    label_00042A3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x442A3Eu);
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442A49u); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    goto label_00042A68;
    label_00042A4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x442A4Bu);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->esi;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x442A5Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x442A5Fu);
    cpu->esp += 0xCu;
    cpu->esi += cpu->edi;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    label_00042A68: cpu->eip = LIFT_CODE_TOKEN_VA(0x442A68u);
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x42A76u); lift_push32(cpu, r); sfera_sub_0043AF30(cpu,r); if (cpu->eip != r) return; }
    label_00042A76: cpu->eip = LIFT_CODE_TOKEN_VA(0x442A76u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00042B80: cpu->eip = LIFT_CODE_TOKEN_VA(0x442B80u);
    cpu->ecx = 3u;
    goto label_000429F0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00442B90(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00042B90;
    label_000429F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4429F0u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4429FEu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->eax);
    cpu->ebx = lift_load32(cpu->eax + 4u);
    cpu->ebp = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442A17u); lift_push32(cpu, r); sfera_sub_0043ACF0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00042A76;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00042A2E;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(4u)) goto label_00042A3E;
    label_00042A2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x442A2Eu);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_00042A4B;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebx)) goto label_00042A3E;
    cpu->eax = (uint32_t)(cpu->esi + cpu->edi + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->ebp)) goto label_00042A4B;
    label_00042A3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x442A3Eu);
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442A49u); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    goto label_00042A68;
    label_00042A4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x442A4Bu);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->esi;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x442A5Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x442A5Fu);
    cpu->esp += 0xCu;
    cpu->esi += cpu->edi;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    label_00042A68: cpu->eip = LIFT_CODE_TOKEN_VA(0x442A68u);
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x42A76u); lift_push32(cpu, r); sfera_sub_0043AF30(cpu,r); if (cpu->eip != r) return; }
    label_00042A76: cpu->eip = LIFT_CODE_TOKEN_VA(0x442A76u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00042B90: cpu->eip = LIFT_CODE_TOKEN_VA(0x442B90u);
    cpu->ecx = 4u;
    goto label_000429F0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00442BA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x442BA0u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442BABu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->eax);
    cpu->edi = lift_load32(cpu->eax + 4u);
    cpu->ebx = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442BC4u); lift_push32(cpu, r); sfera_sub_0043AD60(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00042C2F;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00042BDB;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(4u)) goto label_00042BEA;
    label_00042BDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x442BDBu);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00042C0D;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->edi)) goto label_00042BEA;
    cpu->eax = (uint32_t)(cpu->esi + 3u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->ebx)) goto label_00042C0D;
    label_00042BEA: cpu->eip = LIFT_CODE_TOKEN_VA(0x442BEAu);
    cpu->edx = 4u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442BF8u); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442C06u); lift_push32(cpu, r); sfera_sub_0043AF30(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00042C0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x442C0Du);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->edx + cpu->esi, cpu->ecx);
    cpu->esi += 4u;
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x42C2Fu); lift_push32(cpu, r); sfera_sub_0043AF30(cpu,r); if (cpu->eip != r) return; }
    label_00042C2F: cpu->eip = LIFT_CODE_TOKEN_VA(0x442C2Fu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00442C40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x442C40u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442C4Bu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->eax);
    cpu->ebp = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0xCu, cpu->edi);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442C64u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esi);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00042C72;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_00042C82;
    label_00042C72: cpu->eip = LIFT_CODE_TOKEN_VA(0x442C72u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00042CF3;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_00042C82;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_00042CF3;
    label_00042C82: cpu->eip = LIFT_CODE_TOKEN_VA(0x442C82u);
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442C8Cu); lift_push32(cpu, r); sfera_sub_00434AF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->esi);
    ++cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442CACu); lift_push32(cpu, r); sfera_sub_0049B7F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->esp += 0x18u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00042D78;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00042D78;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00042CD3;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_00042D78;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_00042CD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x442CD3u);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_00042CDF;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
    label_00042CDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x442CDFu);
    --cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(lift_load32(cpu->esi + 8u))) goto label_00042D78;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 8u, cpu->eax);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
    label_00042CF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x442CF3u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00042D78;
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(cpu->eax + cpu->esi);
    cpu->eax = cpu->ecx;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (uint32_t)(cpu->eax + 1u);
    label_00042D10: cpu->eip = LIFT_CODE_TOKEN_VA(0x442D10u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00042D10;
    cpu->eax -= cpu->ebx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esi += cpu->edi;
    cpu->ebx = lift_pop32(cpu);
    (void)cpu;
    label_00042D20: cpu->eip = LIFT_CODE_TOKEN_VA(0x442D20u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->esi, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->esi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00042D20;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00042D34;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(4u)) goto label_00042D46;
    label_00042D34: cpu->eip = LIFT_CODE_TOKEN_VA(0x442D34u);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_00042D64;
    if ((uint32_t)(cpu->edi) < (uint32_t)(cpu->ebp)) goto label_00042D46;
    cpu->ecx = (uint32_t)(cpu->edx + cpu->edi + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_00042D64;
    label_00042D46: cpu->eip = LIFT_CODE_TOKEN_VA(0x442D46u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442D4Fu); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442D5Du); lift_push32(cpu, r); sfera_sub_0043AF30(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
    label_00042D64: cpu->eip = LIFT_CODE_TOKEN_VA(0x442D64u);
    cpu->edi += cpu->edx;
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0xCu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x42D78u); lift_push32(cpu, r); sfera_sub_0043AF30(cpu,r); if (cpu->eip != r) return; }
    label_00042D78: cpu->eip = LIFT_CODE_TOKEN_VA(0x442D78u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00442D80(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00042D80;
    label_00042A80: cpu->eip = LIFT_CODE_TOKEN_VA(0x442A80u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    cpu->edi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442A92u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->eax);
    cpu->ebp = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442AABu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00042B4C;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00042AC4;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(4u)) goto label_00042AD6;
    label_00042AC4: cpu->eip = LIFT_CODE_TOKEN_VA(0x442AC4u);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_00042AE3;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebp)) goto label_00042AD6;
    cpu->ecx = (uint32_t)(cpu->esi + cpu->edi + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_00042AE3;
    label_00042AD6: cpu->eip = LIFT_CODE_TOKEN_VA(0x442AD6u);
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442AE1u); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    goto label_00042B3E;
    label_00042AE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x442AE3u);
    cpu->eax = lift_load32(cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00042AEF;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_00042B03;
    label_00042AEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x442AEFu);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00042B0E;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_00042B03;
    cpu->edx = (uint32_t)(cpu->eax + cpu->edi + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->edx) <= (uint32_t)(lift_load32(cpu->ebx + 8u))) goto label_00042B0E;
    label_00042B03: cpu->eip = LIFT_CODE_TOKEN_VA(0x442B03u);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442B0Cu); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    goto label_00042B3E;
    label_00042B0E: cpu->eip = LIFT_CODE_TOKEN_VA(0x442B0Eu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x442B1Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x442B21u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->esi);
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x442B30u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x442B35u);
    cpu->esp += 0x18u;
    cpu->esi += cpu->edi;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    label_00042B3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x442B3Eu);
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x42B4Cu); lift_push32(cpu, r); sfera_sub_0043AF30(cpu,r); if (cpu->eip != r) return; }
    label_00042B4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x442B4Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00042D80: cpu->eip = LIFT_CODE_TOKEN_VA(0x442D80u);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(cpu->edx + 1u);
    goto label_00042A80;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00442D90(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00042D90;
    label_00042A80: cpu->eip = LIFT_CODE_TOKEN_VA(0x442A80u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    cpu->edi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442A92u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->eax);
    cpu->ebp = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442AABu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00042B4C;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00042AC4;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(4u)) goto label_00042AD6;
    label_00042AC4: cpu->eip = LIFT_CODE_TOKEN_VA(0x442AC4u);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_00042AE3;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebp)) goto label_00042AD6;
    cpu->ecx = (uint32_t)(cpu->esi + cpu->edi + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_00042AE3;
    label_00042AD6: cpu->eip = LIFT_CODE_TOKEN_VA(0x442AD6u);
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442AE1u); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    goto label_00042B3E;
    label_00042AE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x442AE3u);
    cpu->eax = lift_load32(cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00042AEF;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_00042B03;
    label_00042AEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x442AEFu);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00042B0E;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_00042B03;
    cpu->edx = (uint32_t)(cpu->eax + cpu->edi + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->edx) <= (uint32_t)(lift_load32(cpu->ebx + 8u))) goto label_00042B0E;
    label_00042B03: cpu->eip = LIFT_CODE_TOKEN_VA(0x442B03u);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442B0Cu); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    goto label_00042B3E;
    label_00042B0E: cpu->eip = LIFT_CODE_TOKEN_VA(0x442B0Eu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x442B1Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x442B21u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->esi);
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x442B30u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x442B35u);
    cpu->esp += 0x18u;
    cpu->esi += cpu->edi;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    label_00042B3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x442B3Eu);
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x42B4Cu); lift_push32(cpu, r); sfera_sub_0043AF30(cpu,r); if (cpu->eip != r) return; }
    label_00042B4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x442B4Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00042D90: cpu->eip = LIFT_CODE_TOKEN_VA(0x442D90u);
    cpu->edx = 4u;
    cpu->ecx = (uint32_t)(cpu->edx + 0xFFFFFFFEu);
    goto label_00042A80;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00442DA0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00042DA0;
    label_00042A80: cpu->eip = LIFT_CODE_TOKEN_VA(0x442A80u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    cpu->edi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442A92u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->eax);
    cpu->ebp = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442AABu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00042B4C;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00042AC4;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(4u)) goto label_00042AD6;
    label_00042AC4: cpu->eip = LIFT_CODE_TOKEN_VA(0x442AC4u);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_00042AE3;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebp)) goto label_00042AD6;
    cpu->ecx = (uint32_t)(cpu->esi + cpu->edi + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_00042AE3;
    label_00042AD6: cpu->eip = LIFT_CODE_TOKEN_VA(0x442AD6u);
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442AE1u); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    goto label_00042B3E;
    label_00042AE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x442AE3u);
    cpu->eax = lift_load32(cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00042AEF;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_00042B03;
    label_00042AEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x442AEFu);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00042B0E;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_00042B03;
    cpu->edx = (uint32_t)(cpu->eax + cpu->edi + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->edx) <= (uint32_t)(lift_load32(cpu->ebx + 8u))) goto label_00042B0E;
    label_00042B03: cpu->eip = LIFT_CODE_TOKEN_VA(0x442B03u);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442B0Cu); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    goto label_00042B3E;
    label_00042B0E: cpu->eip = LIFT_CODE_TOKEN_VA(0x442B0Eu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x442B1Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x442B21u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->esi);
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x442B30u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x442B35u);
    cpu->esp += 0x18u;
    cpu->esi += cpu->edi;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    label_00042B3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x442B3Eu);
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x42B4Cu); lift_push32(cpu, r); sfera_sub_0043AF30(cpu,r); if (cpu->eip != r) return; }
    label_00042B4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x442B4Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00042DA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x442DA0u);
    cpu->edx = 4u;
    cpu->ecx = (uint32_t)(cpu->edx + 0xFFFFFFFFu);
    goto label_00042A80;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00442DB0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00042DB0;
    label_00042A80: cpu->eip = LIFT_CODE_TOKEN_VA(0x442A80u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    cpu->edi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442A92u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->eax);
    cpu->ebp = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442AABu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00042B4C;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00042AC4;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(4u)) goto label_00042AD6;
    label_00042AC4: cpu->eip = LIFT_CODE_TOKEN_VA(0x442AC4u);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_00042AE3;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebp)) goto label_00042AD6;
    cpu->ecx = (uint32_t)(cpu->esi + cpu->edi + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_00042AE3;
    label_00042AD6: cpu->eip = LIFT_CODE_TOKEN_VA(0x442AD6u);
    cpu->edx = cpu->edi;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442AE1u); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    goto label_00042B3E;
    label_00042AE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x442AE3u);
    cpu->eax = lift_load32(cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00042AEF;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_00042B03;
    label_00042AEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x442AEFu);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00042B0E;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_00042B03;
    cpu->edx = (uint32_t)(cpu->eax + cpu->edi + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->edx) <= (uint32_t)(lift_load32(cpu->ebx + 8u))) goto label_00042B0E;
    label_00042B03: cpu->eip = LIFT_CODE_TOKEN_VA(0x442B03u);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442B0Cu); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    goto label_00042B3E;
    label_00042B0E: cpu->eip = LIFT_CODE_TOKEN_VA(0x442B0Eu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x442B1Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x442B21u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->esi);
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x442B30u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x442B35u);
    cpu->esp += 0x18u;
    cpu->esi += cpu->edi;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    label_00042B3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x442B3Eu);
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x42B4Cu); lift_push32(cpu, r); sfera_sub_0043AF30(cpu,r); if (cpu->eip != r) return; }
    label_00042B4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x442B4Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00042DB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x442DB0u);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(cpu->edx + 4u);
    goto label_00042A80;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00442DC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x442DC0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442DCBu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->eax);
    cpu->edi = lift_load32(cpu->eax + 4u);
    cpu->ebx = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442DE4u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00042E6C;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00042DF7;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(4u)) goto label_00042E06;
    label_00042DF7: cpu->eip = LIFT_CODE_TOKEN_VA(0x442DF7u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00042E1B;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->edi)) goto label_00042E06;
    cpu->ecx = (uint32_t)(cpu->esi + 3u);
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(cpu->ebx)) goto label_00042E1B;
    label_00042E06: cpu->eip = LIFT_CODE_TOKEN_VA(0x442E06u);
    cpu->edx = 4u;
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442E14u); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
    label_00042E1B: cpu->eip = LIFT_CODE_TOKEN_VA(0x442E1Bu);
    cpu->edx = lift_load32(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00042E27;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(4u)) goto label_00042E3A;
    label_00042E27: cpu->eip = LIFT_CODE_TOKEN_VA(0x442E27u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00042E4C;
    if ((uint32_t)(cpu->edx) < (uint32_t)(cpu->ecx)) goto label_00042E3A;
    cpu->ecx = (uint32_t)(cpu->edx + 3u);
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_00042E4C;
    label_00042E3A: cpu->eip = LIFT_CODE_TOKEN_VA(0x442E3Au);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->edx = 4u;
    cpu->ecx = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    sfera_sub_00434E80(cpu, stop_address); return;
    label_00042E4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x442E4Cu);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = lift_load32(cpu->eax + cpu->esi);
    lift_store32(cpu->edx + cpu->eax, cpu->ecx);
    cpu->esi += 4u;
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x42E6Cu); lift_push32(cpu, r); sfera_sub_0043AF30(cpu,r); if (cpu->eip != r) return; }
    label_00042E6C: cpu->eip = LIFT_CODE_TOKEN_VA(0x442E6Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00442E80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x442E80u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442E8Cu); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->eax);
    cpu->esi = lift_load32(cpu->eax + 4u);
    cpu->ebx = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442EA5u); lift_push32(cpu, r); sfera_sub_0043AE70(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00042EB1;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(4u)) goto label_00042EBD;
    label_00042EB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x442EB1u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_00042EEA;
    if ((uint32_t)(cpu->edi) < (uint32_t)(cpu->esi)) goto label_00042EBD;
    if ((uint32_t)(cpu->edi) <= (uint32_t)(cpu->ebx)) goto label_00042EEA;
    label_00042EBD: cpu->eip = LIFT_CODE_TOKEN_VA(0x442EBDu);
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442EC7u); lift_push32(cpu, r); sfera_sub_00434AF0(cpu,r); if (cpu->eip != r) return; }
    ++cpu->ebx;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442EDFu); lift_push32(cpu, r); sfera_sub_0049B7F0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
    label_00042EEA: cpu->eip = LIFT_CODE_TOKEN_VA(0x442EEAu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_00042F5B;
    cpu->ebx = g_sfera_mbc_runtime->process_memory_base;
    cpu->esi = (uint32_t)(cpu->ebx + cpu->edi);
    cpu->ecx = cpu->esi;
    cpu->eax = (uint32_t)(cpu->ecx + 1u);
    label_00042F01: cpu->eip = LIFT_CODE_TOKEN_VA(0x442F01u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00042F01;
    cpu->ecx -= cpu->eax;
    cpu->eax = lift_load32(cpu->ebp);
    cpu->edx = (uint32_t)(cpu->ecx + 1u);
    cpu->eax += cpu->ebx;
    label_00042F12: cpu->eip = LIFT_CODE_TOKEN_VA(0x442F12u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    lift_store8(cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->esi;
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00042F12;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00042F26;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(4u)) goto label_00042F3C;
    label_00042F26: cpu->eip = LIFT_CODE_TOKEN_VA(0x442F26u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00042F47;
    if ((uint32_t)(cpu->edi) < (uint32_t)(cpu->eax)) goto label_00042F3C;
    cpu->eax = (uint32_t)(cpu->edx + cpu->edi + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esp + 0x18u))) goto label_00042F47;
    label_00042F3C: cpu->eip = LIFT_CODE_TOKEN_VA(0x442F3Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x442F45u); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    goto label_00042F4D;
    label_00042F47: cpu->eip = LIFT_CODE_TOKEN_VA(0x442F47u);
    cpu->edi += cpu->edx;
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    label_00042F4D: cpu->eip = LIFT_CODE_TOKEN_VA(0x442F4Du);
    cpu->edx = 1u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x42F5Bu); lift_push32(cpu, r); sfera_sub_0043AF30(cpu,r); if (cpu->eip != r) return; }
    label_00042F5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x442F5Bu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}
