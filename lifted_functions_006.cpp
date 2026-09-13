#include "lifted_functions.h"
#include <cmath>
#include <cstring>
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
__declspec(noinline) void sfera_sub_004398D0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->ecx);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    cpu->ecx = g_sfera_mbc_runtime->argument_count;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = (int8_t)(*(uint8_t*)(cpu->eax));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    ++cpu->eax;
    cpu->edi = 0u;
    cpu->esi = 0u;
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->eax));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((int32_t)cpu->ebp >= (int32_t)cpu->edi) goto label_00039938;
    cpu->edx = cpu->ecx + cpu->ebp;
    cpu->edx = 0u - (uint64_t)(cpu->edx);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    cpu->edx = cpu->ebp;
    cpu->edx = 0u - (uint64_t)(cpu->edx);
    if ((int32_t)(cpu->edx) >= (int32_t)(cpu->ecx)) goto label_00039930;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Wrong number of parameters (must be %d, present %d)"); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->text_buffer[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x439912u));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->text_buffer[0];
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->reportError(reinterpret_cast<const char*>(cpu->ecx))); cpu->eip = LIFT_CODE_TOKEN_VA(0x439925u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    cpu->ecx = g_sfera_mbc_runtime->argument_count;
    label_00039930:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp = cpu->ecx;
    goto label_00039975;
    label_00039938:
    if (cpu->ebp == cpu->ecx) goto label_00039975;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Wrong number of parameters (must be %d, present %d)"); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->text_buffer[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x439948u));
    cpu->esp += 0x10u;
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->text_buffer[0];
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->reportError(reinterpret_cast<const char*>(cpu->ecx))); cpu->eip = LIFT_CODE_TOKEN_VA(0x43995Bu);
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    if ((cpu->ebp == cpu->eax) || ((int32_t)(cpu->ebp) < (int32_t)(cpu->eax))) goto label_00039970;
    cpu->ebp -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp = cpu->eax;
    label_00039970:
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
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
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->eax));
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->esi += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax += 4u;
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->eax));
    if ((cpu->ecx & 0xFFu) != 0x10u) goto label_000399C5;
    if ((cpu->edx & 0xFFu) != 0x20u) goto label_000399BF;
    x87_v0 = (double)*(float*)(cpu->edi);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    *(uint32_t*)(cpu->esi) = cpu->eax;
    goto label_00039A37;
    label_000399BF:
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    goto label_00039A37;
    label_000399C5:
    if ((cpu->ecx & 0xFFu) != 0x20u) goto label_000399DA;
    if ((cpu->edx & 0xFFu) != (cpu->ecx & 0xFFu)) goto label_000399D4;
    *(float*)(cpu->esi) = (double)*(float*)(cpu->edi);
    goto label_00039A37;
    label_000399D4:
    *(float*)(cpu->esi) = (double)(((int32_t)(*(uint32_t*)(cpu->edi))));
    goto label_00039A37;
    label_000399DA:
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000399FE;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000399E8;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    *(uint8_t*)(cpu->esi) = cpu->ecx & 0xFFu;
    goto label_00039A37;
    label_000399E8:
    if ((cpu->edx & 0xFFu) != 0x20u) goto label_000399F8;
    x87_v0 = (double)*(float*)(cpu->edi);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    goto label_00039A37;
    label_000399F8:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    *(uint8_t*)(cpu->esi) = cpu->edx & 0xFFu;
    goto label_00039A37;
    label_000399FE:
    if ((cpu->edx & 0xFFu) != 0x20u) goto label_00039A13;
    x87_v0 = (double)*(float*)(cpu->edi);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    --cpu->ebp;
    cpu->ebx += 0x20u;
    cpu->edi += 0x20u;
    if ((int32_t)cpu->ebp > 0) goto label_00039990;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = 0u;
    label_00039A51:
    x87_v0 = 0.0;
    if ((int32_t)(cpu->esi) < (int32_t)(4u)) goto label_00039B7E;
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
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->eax));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->ecx += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax += 4u;
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->eax));
    if ((cpu->edx & 0xFFu) != 0x10u) goto label_00039A8F;
    *(uint32_t*)(cpu->ecx) = cpu->edi;
    goto label_00039AA8;
    label_00039A8F:
    if ((cpu->edx & 0xFFu) != 0x20u) goto label_00039A98;
    *(float*)(cpu->ecx) = x87_v0;
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
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    ++cpu->ecx;
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->ecx));
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->eax += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx += 4u;
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->ecx));
    if ((cpu->edx & 0xFFu) != 0x10u) goto label_00039AD1;
    *(uint32_t*)(cpu->eax) = cpu->edi;
    goto label_00039AEA;
    label_00039AD1:
    if ((cpu->edx & 0xFFu) != 0x20u) goto label_00039ADA;
    *(float*)(cpu->eax) = x87_v0;
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
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    ++cpu->ecx;
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->ecx));
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->eax += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx += 4u;
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->ecx));
    if ((cpu->edx & 0xFFu) != 0x10u) goto label_00039B13;
    *(uint32_t*)(cpu->eax) = cpu->edi;
    goto label_00039B2C;
    label_00039B13:
    if ((cpu->edx & 0xFFu) != 0x20u) goto label_00039B1C;
    *(float*)(cpu->eax) = x87_v0;
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
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    ++cpu->ecx;
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->ecx));
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->eax += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx += 4u;
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->ecx));
    if ((cpu->edx & 0xFFu) != 0x10u) goto label_00039B55;
    *(uint32_t*)(cpu->eax) = cpu->edi;
    goto label_00039B6E;
    label_00039B55:
    if ((cpu->edx & 0xFFu) != 0x20u) goto label_00039B5E;
    *(float*)(cpu->eax) = x87_v0;
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
    --cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    if (cpu->ebx != 0u) goto label_00039A6E;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    label_00039B7E:
    if ((int32_t)cpu->esi <= (int32_t)cpu->edi) goto label_00039BC4;
    goto label_00039B89;
    label_00039B84:
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    label_00039B89:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->eax));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->ecx += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax += 4u;
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->eax));
    if ((cpu->edx & 0xFFu) == 0x10u) goto label_00039BBD;
    if ((cpu->edx & 0xFFu) != 0x20u) goto label_00039BAF;
    *(float*)(cpu->ecx) = x87_v0;
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
    x87_v0 = x87_v0; 
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_00439C30(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[2]; bool sub_pred[1]; double x87_v0, x87_v1;
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->edx = 0u;
    if ((int32_t)cpu->ecx < (int32_t)cpu->edx) goto label_0003A280;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x398u);
    cpu->ecx += ((uintptr_t)&g_sfera_world_slot_table_runtime.slots[0].object_handle);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    lift_test[0]=(*(uint8_t*)(cpu->ebp + 0x10u)&4u)==0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    if (!lift_test[0]) goto label_0003A27F;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x14u);
    if (cpu->ecx > 0xFFFFu) goto label_0003A27F;
    cpu->eax = cpu->ecx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if (*(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id)) != cpu->ecx) goto label_0003A27F;
    if ((int32_t)*(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index)) < (int32_t)cpu->edx) goto label_0003A27F;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ebx);
    cpu->eax&=1u; lift_test[1]=cpu->eax==0u;
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    if (lift_test[1]) goto label_00039CB9;
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
    cpu->esi = *(uint32_t*)(cpu->eax + 0x84u);
    cpu->esi += *(uint32_t*)(cpu->eax + 0x50u);
    x87_v0 = (double)*(float*)(cpu->esi);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    *(uint32_t*)(cpu->ebp + 0x358u) = cpu->eax;
    x87_v0 = (double)*(float*)(cpu->esi + 4u);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    *(uint32_t*)(cpu->ebp + 0x35Cu) = cpu->eax;
    x87_v0 = (double)*(float*)(cpu->esi + 8u);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
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
    sub_pred[0] = (int32_t)((uint32_t)(g_sfera_mbc_runtime->shared_buffer_size)) < (int32_t)(0x1000u);
    x87_v0 = 0.0;
    if (!sub_pred[0]) goto label_0003A02D;
    cpu->esi = *(uint32_t*)((cpu->eax * 4u) + ((uintptr_t)&g_sfera_mbc_interpreter_storage.send_field_data[0]));
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_runtime->send_field_width[0])));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((int32_t)cpu->eax > (int32_t)0x20u) goto label_00039DAD;
    lift_push32(cpu, 0x258240u);
    x87_v0 = x87_v0; 
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    goto label_00039FDA;
    label_00039DAD:
    if (cpu->eax != 0x6Cu) goto label_00039E36;
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0x30u) = x87_v1;
    { const double lift_left=x87_v1; const double lift_right=-1000.0; if (lift_left<lift_right) goto label_00039DD8; }
    { const double lift_left=x87_v1; const double lift_right=1000.0; if (!(lift_left>lift_right)) goto label_00039DE0; }
    label_00039DD8:
    x87_v1 = x87_v1; 
    *(float*)(cpu->esp + 0x30u) = x87_v0; 
    goto label_00039E04;
    label_00039DE0:
    { const double lift_left=x87_v1; const double lift_right=x87_v0;  if (!(lift_left<lift_right)) goto label_00039E02; }
    label_00039DE9:
    *(float*)(cpu->esp + 0x30u) = ((((double)*(float*)(cpu->esp + 0x30u))) + (6.2831854820251465));
    { const double lift_left=x87_v0; const double lift_right=((double)*(float*)(cpu->esp + 0x30u)); if (lift_left>lift_right) goto label_00039DE9; }
    label_00039E02:
    x87_v0 = x87_v0; 
    label_00039E04:
    *(float*)(cpu->esp + 0x30u) = ((((double)*(float*)(cpu->esp + 0x30u))) * (40.7436637878418));
    x87_v0 = (double)*(float*)(cpu->esp + 0x30u);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    lift_push32(cpu, 0x258240u);
    cpu->eax &= 0xFFu;
    lift_push32(cpu, 8u);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x3Cu;
    goto label_00039FD9;
    label_00039E36:
    x87_v0 = x87_v0; 
    if (cpu->eax != 0x69u) goto label_00039E6C;
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x358u);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x439E50u)); sfera_sub_00437BF0(cpu, LIFT_CODE_TOKEN_VA(0x439E50u));
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    if (cpu->eax == 0xFFFFFFFFu) goto label_00039ED3;
    lift_push32(cpu, 0x258240u); lift_push32(cpu, 0xCu); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->ecx);
    goto label_00039FDA;
    label_00039E6C:
    if (cpu->eax != 0x6Au) goto label_00039EA0;
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x35Cu);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x439E84u)); sfera_sub_00437BF0(cpu, LIFT_CODE_TOKEN_VA(0x439E84u));
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    if (cpu->eax == 0xFFFFFFFFu) goto label_00039ED3;
    lift_push32(cpu, 0x258240u); lift_push32(cpu, 0xCu); lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->edx);
    goto label_00039FDA;
    label_00039EA0:
    if (cpu->eax != 0x6Bu) goto label_00039EE0;
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x360u);
    *(float*)(cpu->esp) = x87_v0; 
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
    x87_v0 = x87_v0; 
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->reportError(reinterpret_cast<const char*>(cpu->ecx))); cpu->eip = LIFT_CODE_TOKEN_VA(0x43A039u);
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
    cpu->eax += 7u;
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
    cpu->edi = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
    cpu->esi = *(uint32_t*)(cpu->edi + 0x84u);
    cpu->esi += *(uint32_t*)(cpu->edi + 0x50u);
    x87_v0 = (double)*(float*)(cpu->esi);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    *(uint32_t*)(cpu->ebp + 0x358u) = cpu->eax;
    x87_v0 = (double)*(float*)(cpu->esi + 4u);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    *(uint32_t*)(cpu->ebp + 0x35Cu) = cpu->eax;
    x87_v0 = (double)*(float*)(cpu->esi + 8u);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ebp + 0x360u) = cpu->eax;
    goto label_0003A0E5;
    label_0003A0DF:
    cpu->edi = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
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
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
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
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
    lift_push32(cpu, 0x190u); lift_push32(cpu, 0x12u);
    cpu->ecx += 0xB4u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A22Eu)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_VA(0x43A22Eu));
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
    lift_push32(cpu, 0x190u); lift_push32(cpu, 0xCu);
    cpu->edx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->edx);
    cpu->eax += 0x44u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x40u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43A254u)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_VA(0x43A254u));
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
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
    auto* destination = reinterpret_cast<CCommonItem*>(cpu->ecx);
    const auto* source = reinterpret_cast<const CCommonItem*>(*(uint32_t*)(cpu->esp + 4u));
    if (destination != nullptr && source != nullptr) {
        std::memcpy(destination->name, source->name, sizeof(destination->name));
        destination->active = source->active;
        destination->position_x = source->position_x;
        destination->position_y = source->position_y;
        destination->position_z = source->position_z;
        destination->field_a8 = source->field_a8; destination->field_ac = source->field_ac; destination->field_b0 = source->field_b0; destination->field_b4 = source->field_b4; destination->field_b8 = source->field_b8;
        std::memcpy(destination->payload, source->payload, sizeof(destination->payload));
    }
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(destination));
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043A300(LiftCpu* cpu, uint32_t stop_address) {
    auto* list = reinterpret_cast<CItemListCommonItem*>(cpu->ecx);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(list == nullptr ? nullptr : list->firstItem()));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043A3D0(LiftCpu* cpu, uint32_t stop_address) {
    auto* list = reinterpret_cast<CItemListCommonItem*>(cpu->ecx);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(list == nullptr ? nullptr : list->nextItem()));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043A6F0(LiftCpu* cpu, uint32_t stop_address) {
    auto* manager = reinterpret_cast<CBaseManagerCommonItem*>(cpu->ecx);
    std::printf("\n-----BaseManager---ALL LISTS----------------------------\n");
    if (manager != nullptr) {
        auto* lists = reinterpret_cast<CItemListCommonItem*>(manager->item_storage);
        if (lists != nullptr) for (std::uint32_t list_index = 0u; list_index < manager->capacity; ++list_index) {
            CItemListCommonItem& list = lists[list_index];
            if (list.active != 1u) continue;
            std::printf("List Name = ''%s'', min = %u, curmax = %u, cur = %u\n", list.name, list.minimum_items, list.capacity, list.item_count);
            std::printf("~~~~~ItemList~~~ALL ITEMS~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            auto* items = reinterpret_cast<CCommonItem*>(list.item_storage);
            if (items == nullptr || list.item_count == 0u) { std::printf(". . . . . . . \n"); continue; }
            for (std::uint32_t item_index = 0u; item_index < list.capacity; ++item_index) if (items[item_index].active == 1u) { std::printf(" ItemName = ''%s''\n", items[item_index].name); items[item_index].releaseItem(); }
        }
    }
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043A830(LiftCpu* cpu, uint32_t stop_address) {
    auto* list = reinterpret_cast<CItemListCommonItem*>(cpu->ecx);
    const std::int32_t minimum = static_cast<std::int32_t>(*(uint32_t*)(cpu->esp + 4u));
    const std::int32_t reserved = static_cast<std::int32_t>(*(uint32_t*)(cpu->esp + 8u));
    const std::uint32_t mode = *(uint32_t*)(cpu->esp + 12u);
    const char* list_name = reinterpret_cast<const char*>(*(uint32_t*)(cpu->esp + 16u));
    const std::uint32_t parameter = *(uint32_t*)(cpu->esp + 20u);
    cpu->eax = list == nullptr ? static_cast<std::uint32_t>(-14) : static_cast<std::uint32_t>(list->initialize(minimum, reserved, mode, list_name, parameter));
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}












__declspec(noinline) void sfera_sub_0043B140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->popInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43B145u);
    if (cpu->eax == 0u) goto label_0003B151;
    g_sfera_mbc_runtime->instruction_cursor += 4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003B151:
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    cpu->eax += *(uint32_t*)(cpu->eax);
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->eax));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043B160(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->popInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43B165u);
    if (cpu->eax == 0u) goto label_0003B171;
    g_sfera_mbc_runtime->instruction_cursor += 2u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003B171:
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    cpu->ecx = (int16_t)(*(uint16_t*)(cpu->eax));
    cpu->eax += cpu->ecx;
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->eax));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043B190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    cpu->ecx = *(uint8_t*)(cpu->eax);
    lift_push32(cpu, cpu->ebx);
    ++cpu->eax;
    lift_push32(cpu, cpu->ebp);
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->eax));
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint16_t*)(cpu->eax);
    cpu->eax += 2u;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->eax));
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->popInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43B1B9u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax += 4u;
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->eax));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax += 4u;
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->eax));
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax += 4u;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->eax));
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
    WorldDiagnostics::describeScript(cpu->ecx != 0);
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
    cpu->esi += *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = cpu->edx;
    ++cpu->edx;
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
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
    cpu->esi = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
    cpu->ecx += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
__declspec(noinline) void sfera_sub_0043B320(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 8u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    cpu->ecx = *(uint8_t*)(cpu->eax);
    lift_push32(cpu, cpu->ebx);
    ++cpu->eax;
    lift_push32(cpu, cpu->ebp);
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->eax));
    cpu->ebp = *(uint16_t*)(cpu->eax);
    lift_push32(cpu, cpu->esi);
    cpu->eax += 2u;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->eax));
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->popSlice())); cpu->eip = LIFT_CODE_TOKEN_VA(0x43B349u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->popInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43B350u);
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx += 4u;
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->ecx));
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
    WorldDiagnostics::describeScript(cpu->ecx != 0);
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
    *(uint32_t*)(cpu->esi) += cpu->ebp;
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->eax = cpu->edx;
    ++cpu->edx;
    cpu->eax <<= 5u;
    cpu->eax += ((uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    sub_pred[0] = *(uint8_t*)(cpu->esp + 0x13u) == 0u;
    g_sfera_mbc_runtime->value_stack_size = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->edx;
    if (sub_pred[0]) goto label_0003B492;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->edx != 0u) goto label_0003B418;
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
    cpu->esi = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
    cpu->ecx += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
__declspec(noinline) void sfera_sub_0043B4C0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint8_t*)(cpu->eax);
    ++cpu->eax;
    lift_push32(cpu, cpu->esi);
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->eax));
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint16_t*)(cpu->eax);
    cpu->eax += 2u;
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->eax));
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->popSlice())); cpu->eip = LIFT_CODE_TOKEN_VA(0x43B4E1u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->popInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43B4E8u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(cpu->eax);
    *(uint32_t*)(cpu->esi) = (uint64_t)(*(uint32_t*)(cpu->esi)) + (uint64_t)(cpu->edi) + (uint64_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = *(uint32_t*)(cpu->esi);
    if (cpu->eax==0u) goto label_0003B554;
    if (cpu->edi < cpu->eax) goto label_0003B4FF;
    if (cpu->edi <= *(uint32_t*)(cpu->esi + 8u)) goto label_0003B554;
    label_0003B4FF:
    cpu->ecx = 1u;
    WorldDiagnostics::describeScript(cpu->ecx != 0);
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43B529u)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x43B529u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->esp += 0x18u;
    if (cpu->eax==0u) goto label_0003B554;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ecx==0u) goto label_0003B554;
    sub_pred[0] = (int32_t)(cpu->eax) < (int32_t)(cpu->ecx);
    if (cpu->eax < cpu->ecx) goto label_0003B544;
    if (cpu->eax <= *(uint32_t*)(cpu->esi + 8u)) goto label_0003B554;
    sub_pred[0] = (int32_t)(cpu->eax) < (int32_t)(cpu->ecx);
    label_0003B544:
    if (!sub_pred[0]) goto label_0003B54B;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    goto label_0003B554;
    label_0003B54B:
    --cpu->eax;
    if ((cpu->eax == *(uint32_t*)(cpu->esi + 8u)) || ((int32_t)(cpu->eax) < (int32_t)(*(uint32_t*)(cpu->esi + 8u)))) goto label_0003B554;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    label_0003B554:
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = cpu->ecx;
    ++cpu->ecx;
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
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
__declspec(noinline) void sfera_sub_0043B610(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint8_t*)(cpu->eax);
    lift_push32(cpu, cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->edi);
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->eax));
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->popSlice())); cpu->eip = LIFT_CODE_TOKEN_VA(0x43B626u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    cpu->ecx = *(uint16_t*)(cpu->eax);
    cpu->eax += 2u;
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->eax));
    *(uint32_t*)(cpu->esi) = (uint64_t)(*(uint32_t*)(cpu->esi)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = *(uint32_t*)(cpu->esi);
    if (cpu->eax==0u) goto label_0003B6A1;
    if (cpu->edi < cpu->eax) goto label_0003B64C;
    if (cpu->edi <= *(uint32_t*)(cpu->esi + 8u)) goto label_0003B6A1;
    label_0003B64C:
    cpu->ecx = 1u;
    WorldDiagnostics::describeScript(cpu->ecx != 0);
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43B676u)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x43B676u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->esp += 0x18u;
    if (cpu->eax==0u) goto label_0003B6A1;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ecx==0u) goto label_0003B6A1;
    sub_pred[0] = (int32_t)(cpu->eax) < (int32_t)(cpu->ecx);
    if (cpu->eax < cpu->ecx) goto label_0003B691;
    if (cpu->eax <= *(uint32_t*)(cpu->esi + 8u)) goto label_0003B6A1;
    sub_pred[0] = (int32_t)(cpu->eax) < (int32_t)(cpu->ecx);
    label_0003B691:
    if (!sub_pred[0]) goto label_0003B698;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    goto label_0003B6A1;
    label_0003B698:
    --cpu->eax;
    if ((cpu->eax == *(uint32_t*)(cpu->esi + 8u)) || ((int32_t)(cpu->eax) < (int32_t)(*(uint32_t*)(cpu->esi + 8u)))) goto label_0003B6A1;
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
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->ecx += 4u;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edi;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edi;
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->ecx));
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
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
__declspec(noinline) void sfera_sub_0043B790(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint8_t*)(cpu->eax);
    lift_push32(cpu, cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->edi);
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->eax));
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->popSlice())); cpu->eip = LIFT_CODE_TOKEN_VA(0x43B7A6u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    cpu->ecx = *(uint16_t*)(cpu->eax);
    cpu->eax += 2u;
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->eax));
    *(uint32_t*)(cpu->esi) = (uint64_t)(*(uint32_t*)(cpu->esi)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = *(uint32_t*)(cpu->esi);
    if (cpu->eax == 0u) goto label_0003B821;
    if (cpu->edi < cpu->eax) goto label_0003B7CC;
    if (cpu->edi <= *(uint32_t*)(cpu->esi + 8u)) goto label_0003B821;
    label_0003B7CC:
    cpu->ecx = 1u;
    WorldDiagnostics::describeScript(cpu->ecx != 0);
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
    sub_pred[0] = (int32_t)(cpu->eax) < (int32_t)(cpu->ecx);
    if (cpu->eax < cpu->ecx) goto label_0003B811;
    if (cpu->eax <= *(uint32_t*)(cpu->esi + 8u)) goto label_0003B821;
    sub_pred[0] = (int32_t)(cpu->eax) < (int32_t)(cpu->ecx);
    label_0003B811:
    if (!sub_pred[0]) goto label_0003B818;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    goto label_0003B821;
    label_0003B818:
    --cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)*(uint32_t*)(cpu->esi + 8u)) goto label_0003B821;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    label_0003B821:
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax += 4u;
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->eax));
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
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->program_table_base));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    cpu->esi -= static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->bytecode_base));
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->eax + cpu->ecx + 0x84u;
    cpu->esi += 4u;
    if (*(uint8_t*)(cpu->edi) < 0x14u) goto label_0003B8B8;
    cpu->ecx = (uintptr_t)"Return stack overflow";
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->reportError(reinterpret_cast<const char*>(cpu->ecx))); cpu->eip = LIFT_CODE_TOKEN_RVA(0x3B8B8u);
    label_0003B8B8:
    cpu->edx = *(uint8_t*)(cpu->edi);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_program_record));
    *(uint32_t*)(cpu->eax + (cpu->edx * 4u) + 0x34u) = cpu->esi;
    ++*(uint8_t*)(cpu->edi);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    cpu->eax += *(uint32_t*)(cpu->eax);
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->eax));
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    g_sfera_mbc_runtime->argument_end = cpu->eax;
    cpu->eax -= g_sfera_mbc_runtime->argument_count;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->value_stack_size = cpu->eax;
    g_sfera_mbc_runtime->argument_cursor = cpu->eax;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043B8F0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
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
    cpu->eax -= static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->edx = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    cpu->eax = cpu->eax + cpu->esi + 0xFFFFFFFFu;
    cpu->ecx = cpu->esp + 0x18u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    g_sfera_mbc_runtime->pushSlice(*reinterpret_cast<const SferaSliceReference32*>(cpu->ecx), cpu->edx); cpu->eip = LIFT_CODE_TOKEN_VA(0x43B95Fu);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->edi += cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    goto label_0003B9E8;
    label_0003B96D:
    cpu->edx = *(uint32_t*)(cpu->edi);
    if ((int32_t)(cpu->ecx) >= (int32_t)(0x100u)) goto label_0003B99C;
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].value.base = cpu->edx;
    goto label_0003B9C7;
    label_0003B98E:
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->edi);
    if ((int32_t)(cpu->ecx) < (int32_t)(0x100u)) goto label_0003B9AE;
    label_0003B99C:
    cpu->ecx = (uintptr_t)"Stack overflow";
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->reportError(reinterpret_cast<const char*>(cpu->ecx))); cpu->eip = LIFT_CODE_TOKEN_VA(0x43B9A6u);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    goto label_0003B9E5;
    label_0003B9AE:
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x20u;
    *(float*)((uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].value.base) = x87_v0; 
    label_0003B9C7:
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source.base = 0xFFFFFFFFu;
    cpu->ecx += cpu->ebx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source.begin = cpu->ebx;
    g_sfera_mbc_runtime->value_stack_size = cpu->ecx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source.end = cpu->ebx;
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
__declspec(noinline) void sfera_sub_0043BA10(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
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
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_0003BA64;
    if ((cpu->edx & 0xFFu) == 0u) goto label_0003BA60;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_0003BA64;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0003BA44;
    label_0003BA60:
    cpu->eax = 0u;
    goto label_0003BA69;
    label_0003BA64:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
    label_0003BA69:
    if (cpu->eax != 0u) goto label_0003BA72;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x28u) >= (int32_t)cpu->eax) goto label_0003BAA9;
    label_0003BA72:
    ++cpu->ebx;
    cpu->esi += 0x34u;
    if ((int32_t)cpu->ebx < (int32_t)cpu->edi) goto label_0003BA40;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
    label_0003BA7F:
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xBCu);
    if (cpu->ecx == 0u) goto label_0003BAA4;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x230u);
    *(uint32_t*)(cpu->eax + 0xBCu) = cpu->edx;
    lift_push32(cpu, 0x1853u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    label_0003BAA4:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0003BAA7:
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003BAA9:
    cpu->eax = g_sfera_mbc_runtime->program_index;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->program_table_base));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    cpu->edi = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->bytecode_base));
    cpu->edi -= static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    cpu->esi = cpu->eax + cpu->ecx + 0x84u;
    if (*(uint8_t*)(cpu->eax + cpu->ecx + 0x84u) < 0x14u) goto label_0003BAE1;
    cpu->ecx = (uintptr_t)"Return stack overflow";
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->reportError(reinterpret_cast<const char*>(cpu->ecx))); cpu->eip = LIFT_CODE_TOKEN_RVA(0x3BAE1u);
    label_0003BAE1:
    cpu->edx = *(uint8_t*)(cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_program_record));
    *(uint32_t*)(cpu->eax + (cpu->edx * 4u) + 0x34u) = cpu->edi;
    ++*(uint8_t*)(cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43BAF6u)); sfera_sub_0043B8F0(cpu, LIFT_CODE_TOKEN_VA(0x43BAF6u));
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x34u);
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x68u);
    cpu->eax = *(uint32_t*)(cpu->edx + cpu->ebx + 0x24u);
    cpu->eax += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->bytecode_base));
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->eax));
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->argument_end = cpu->eax;
    cpu->eax -= g_sfera_mbc_runtime->argument_count;
    cpu->ebx = lift_pop32(cpu);
    g_sfera_mbc_runtime->value_stack_size = cpu->eax;
    g_sfera_mbc_runtime->argument_cursor = cpu->eax;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043BB30(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x1976u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = 0x100u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
    cpu->esi = cpu->eax;
    value_1 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_VA(0x43BB4Du);
    *(float*)(cpu->esp + 4u) = value_1; 
    value_0 = (double)*(float*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    *(double*)(cpu->esp) = value_0;
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x43BBAAu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->ecx += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    sfera_sub_00459B10(cpu, stop_address); return;
}








__declspec(noinline) void sfera_sub_0043BDB0(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6, value_7, value_8, value_9, value_10, value_11, value_12, value_13;
 bool sub_pred[1]; double x87_p0, x87_p1, x87_p2, x87_p3;
    cpu->esp -= 0x18u;
    if (g_sfera_mbc_runtime->argument_count != 2u) goto label_0003BE83;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x43BDC7u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x43BDCEu);
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
    reinterpret_cast<SferaSliceReference32*>(cpu->ecx)->diagnoseRange(cpu->edx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x3BDFBu);
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
    reinterpret_cast<SferaSliceReference32*>(cpu->ecx)->diagnoseRange(cpu->edx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x3BE26u);
label_0003BE26:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003BE7D;
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->edi);
    x87_p0 = (double)*(float*)(cpu->eax + cpu->edx + 4u);
    x87_p0 = (x87_p0) - (((double)*(float*)(cpu->ecx + cpu->edx + 4u)));
    cpu->ecx += cpu->edx;
    x87_p1 = (double)*(float*)(cpu->eax + cpu->edx);
    x87_p1 = (x87_p1) - (((double)*(float*)(cpu->ecx)));
    x87_p2 = (double)*(float*)(cpu->eax + cpu->edx + 8u);
    x87_p2 = (x87_p2) - (((double)*(float*)(cpu->ecx + 8u)));
    x87_p3 = x87_p1;
    x87_p1 = x87_p1 * x87_p3; 
    x87_p3 = x87_p0;
    x87_p0 = x87_p0 * x87_p3; 
    std::swap(x87_p2, x87_p1);
    x87_p0 = x87_p0 + x87_p2; 
    x87_p1 = (x87_p1) * (x87_p1);
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 0x1Cu) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x1Cu);
    x87_p0 = std::sqrt(x87_p0);
    *(float*)(cpu->esp + 0x1Cu) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_p0; 
    g_sfera_mbc_runtime->pushReal(*reinterpret_cast<const float*>(cpu->esp)); cpu->esp += 4u; cpu->eip = LIFT_CODE_TOKEN_RVA(0x3BE7Du);
label_0003BE7D:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
label_0003BE83:
    value_10 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_VA(0x43BE88u);
    *(float*)(cpu->esp + 4u) = value_10; 
     value_11 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_VA(0x43BE91u);
    *(float*)(cpu->esp) = value_11; 
     value_12 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_VA(0x43BE99u);
    *(float*)(cpu->esp + 0xCu) = value_12; 
     value_13 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_VA(0x43BEA2u);
    *(float*)(cpu->esp + 8u) = value_13; 
    cpu->eax = g_sfera_mbc_runtime->argument_count;
     if (cpu->eax != 4u) goto label_0003BEE9;
    x87_p0 = (double)*(float*)(cpu->esp);
    x87_p0 = (x87_p0) - (((double)*(float*)(cpu->esp + 8u)));
    x87_p1 = (double)*(float*)(cpu->esp + 4u);
    x87_p1 = (x87_p1) - (((double)*(float*)(cpu->esp + 0xCu)));
    x87_p1 = (x87_p1) * (x87_p1);
    x87_p2 = x87_p0;
    x87_p0 = x87_p0 * x87_p2; 
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_p0 = std::sqrt(x87_p0);
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_p0; 
    g_sfera_mbc_runtime->pushReal(*reinterpret_cast<const float*>(cpu->esp)); cpu->esp += 4u; cpu->eip = LIFT_CODE_TOKEN_VA(0x43BEE5u);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
label_0003BEE9:
    if (cpu->eax != 5u) goto label_0003BF1A;
    x87_p0 = (double)*(float*)(cpu->esp);
    lift_push32(cpu, cpu->ecx);
    x87_p0 = (x87_p0) - (((double)*(float*)(cpu->esp + 0xCu)));
    x87_p1 = (double)*(float*)(cpu->esp + 8u);
    x87_p1 = (x87_p1) - (((double)*(float*)(cpu->esp + 0x10u)));
    x87_p1 = (x87_p1) * (x87_p1);
    x87_p2 = x87_p0;
    x87_p0 = x87_p0 * x87_p2; 
    x87_p0 = x87_p0 + x87_p1; 
    *(float*)(cpu->esp + 0x18u) = x87_p0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x18u);
    g_sfera_mbc_runtime->pushReal(*reinterpret_cast<const float*>(cpu->esp)); cpu->esp += 4u; cpu->eip = LIFT_CODE_TOKEN_VA(0x43BF16u);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
label_0003BF1A:
    value_8 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_VA(0x43BF1Fu);
    *(float*)(cpu->esp + 0x10u) = value_8; 
     value_9 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_VA(0x43BF28u);
    *(float*)(cpu->esp + 0x14u) = value_9; 
    sub_pred[0] = (uint32_t)(g_sfera_mbc_runtime->argument_count) == 6u;
    value_0 = (double)*(float*)(cpu->esp);
    value_1 = (value_0) - (((double)*(float*)(cpu->esp + 0x10u)));
    x87_p0 = (double)*(float*)(cpu->esp + 4u);
    x87_p0 = (x87_p0) - (((double)*(float*)(cpu->esp + 8u)));
    x87_p1 = (double)*(float*)(cpu->esp + 0xCu);
    x87_p1 = (x87_p1) - (((double)*(float*)(cpu->esp + 0x14u)));
    x87_p2 = x87_p0;
    x87_p0 = x87_p0 * x87_p2; 
    x87_p2 = value_1;
    value_2 = value_1 * x87_p2; 
    std::swap(x87_p1, x87_p0);
    value_3 = value_2 + x87_p1; 
    x87_p0 = (x87_p0) * (x87_p0);
    value_4 = value_3 + x87_p0; 
    if (!sub_pred[0]) goto label_0003BF7E;
    *(float*)(cpu->esp + 0x14u) = value_4; 
    value_5 = (double)*(float*)(cpu->esp + 0x14u);
    value_6 = std::sqrt(value_5);
    *(float*)(cpu->esp + 0x14u) = value_6; 
    value_7 = (double)*(float*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = value_7; 
     g_sfera_mbc_runtime->pushReal(*reinterpret_cast<const float*>(cpu->esp)); cpu->esp += 4u; cpu->eip = LIFT_CODE_TOKEN_VA(0x43BF7Au);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
label_0003BF7E:
    *(float*)(cpu->esp + 0x14u) = value_4; 
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x18u);
     g_sfera_mbc_runtime->pushReal(*reinterpret_cast<const float*>(cpu->esp)); cpu->esp += 4u; cpu->eip = LIFT_CODE_TOKEN_VA(0x43BF8Fu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}





__declspec(noinline) void sfera_sub_0043C1D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x43C1D7u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (((uint32_t)(g_sfera_mbc_runtime->argument_count) == 1u) || ((int32_t)((uint32_t)(g_sfera_mbc_runtime->argument_count)) < (int32_t)(1u))) goto label_0003C1EB;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43C1E7u);
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
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx = cpu->ecx + cpu->esi;
    cpu->edx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C21Du)); sfera_sub_00435230(cpu, LIFT_CODE_TOKEN_VA(0x43C21Du));
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_runtime->active_tag = cpu->eax;
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003C22B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043C230(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43C236u);
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
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
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
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003C2B0:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043C2C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x43C2C6u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi != 0u) goto label_0003C2DE;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffprc_link\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C2DBu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x43C2DBu));
    cpu->esp += 8u;
    label_0003C2DE:
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx = cpu->ecx + cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C2ECu)); sfera_sub_004386C0(cpu, LIFT_CODE_TOKEN_VA(0x43C2ECu));
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    g_sfera_mbc_runtime->active_tag = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    if ((int32_t)(cpu->edx) < (int32_t)(0x100u)) goto label_0003C30A;
    cpu->ecx = (uintptr_t)"Stack overflow";
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->reportError(reinterpret_cast<const char*>(cpu->ecx))); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003C30A:
    cpu->ecx = cpu->edx;
    cpu->ecx <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].value.base = cpu->eax;
    cpu->eax = 1u;
    cpu->edx += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source.base = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source.end = cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source.begin = cpu->eax;
    g_sfera_mbc_runtime->value_stack_size = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_0043C3A0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x43C3CFu);
    cpu->ebp = *(uint32_t*)(cpu->eax);
    if (cpu->ebp != 0u) goto label_0003C3E7;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffprc_id\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43C3E4u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x43C3E4u));
    cpu->esp += 8u;
    label_0003C3E7:
    cpu->ebx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ebx += cpu->ebp;
    goto label_0003C3F8;
    label_0003C3F1:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43C3F6u);
    cpu->ebp = cpu->eax;
    label_0003C3F8:
    if ((int32_t)g_sfera_mbc_runtime->argument_count <= (int32_t)cpu->esi) goto label_0003C428;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43C405u);
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
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_0003C481;
    if ((cpu->edx & 0xFFu) == 0u) goto label_0003C47D;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_0003C481;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0003C461;
    label_0003C47D:
    cpu->eax = 0u;
    goto label_0003C486;
    label_0003C481:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
    label_0003C486:
    if (cpu->eax != 0u) goto label_0003C4B4;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x348u);
    cpu->eax = *(uint32_t*)(cpu->edi + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    cpu->ecx = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
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
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003C4D0:
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x348u);
    cpu->ecx = *(uint32_t*)(cpu->edi + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    label_0003C4E0:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003C4F0:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043C770(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[3];
    goto label_0003C770;
    label_0003C500:
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    cpu->esi += ((uintptr_t)&g_sfera_mbc_runtime->processes[0]);
    sub_pred[1] = *(uint32_t*)(cpu->esi + 0x68u) == 0u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    if (!sub_pred[1]) goto label_0003C53F;
    cpu->ecx |= 0xFFFFFFFFu;
    g_sfera_mbc_runtime->active_tag = cpu->ecx; g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x43C52Fu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003C53F:
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    lift_push32(cpu, cpu->ebx);
    cpu->eax <<= 5u;
    sub_pred[2] = (uint32_t)((uint64_t)(g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type)) == 1u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    if (!sub_pred[2]) goto label_0003C5EF;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x43C55Cu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->ecx += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_0003C5B6;
    if ((cpu->edx & 0xFFu) == 0u) goto label_0003C5B2;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_0003C5B6;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0003C596;
    label_0003C5B2:
    cpu->eax = 0u;
    goto label_0003C5BB;
    label_0003C5B6:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
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
    g_sfera_mbc_runtime->active_tag = cpu->ecx; g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x43C5DCu);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003C5EF:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43C5F4u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xC4u);
    cpu->eax = *(uint16_t*)(cpu->ecx + (cpu->eax * 2u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (cpu->eax == 0xFFFFu) goto label_0003C5D4;
    label_0003C609:
    cpu->ebp = g_sfera_mbc_runtime->execution_context_depth;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->edi = g_sfera_mbc_runtime->process_index;
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->bytecode_base));
    cpu->ebx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->program_table_base));
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].process_index = cpu->edi;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x348u);
    cpu->edi = *(uint32_t*)(cpu->edi + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id));
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].process_memory_base = cpu->ecx;
    cpu->ecx = g_sfera_mbc_runtime->program_index;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].program_index = cpu->ecx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xA4u);
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].bytecode_base = reinterpret_cast<decltype(g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].bytecode_base)>(cpu->edx);
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].process_id = cpu->edi;
    cpu->edi = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].instruction_cursor = cpu->edx;
    cpu->edx -= static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->bytecode_base));
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].active_process = cpu->edi;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].program_table_base = reinterpret_cast<decltype(g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].program_table_base)>(cpu->ebx);
    cpu->ecx += cpu->ebx;
    g_sfera_mbc_runtime->active_program_record = reinterpret_cast<ScriptProgramDiagnostic*>(static_cast<std::uintptr_t>(cpu->ecx));
    ++cpu->ebp;
    g_sfera_mbc_runtime->execution_context_depth = cpu->ebp;
    *(uint32_t*)(cpu->ecx + 0x88u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x5Cu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x34u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x48u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x68u);
    g_sfera_mbc_runtime->bytecode_base = reinterpret_cast<decltype(g_sfera_mbc_runtime->bytecode_base)>(cpu->edi);
    g_sfera_mbc_runtime->program_table_base = reinterpret_cast<decltype(g_sfera_mbc_runtime->program_table_base)>(cpu->edx);
    cpu->ebx = *(uint32_t*)(cpu->eax + cpu->ecx + 0x24u);
    cpu->ebx += cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x50u);
    g_sfera_mbc_runtime->process_memory_base = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->edi));
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->ebx));
    cpu->eax = *(uint32_t*)(cpu->eax + cpu->ecx + 0x28u);
    g_sfera_mbc_runtime->program_index = cpu->eax;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    cpu->edi = cpu->eax + cpu->edx;
    g_sfera_mbc_runtime->active_program_record = reinterpret_cast<ScriptProgramDiagnostic*>(static_cast<std::uintptr_t>(cpu->edi));
    *(uint8_t*)(cpu->edx + cpu->eax + 0x84u) = 0u;
    cpu->eax = g_sfera_mbc_runtime->program_index;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x5Cu);
    cpu->edx = cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xA4u);
    if (*(uint8_t*)(cpu->edx + cpu->edi + 0x94u) == 0u) goto label_0003C731;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x68u);
    if (*(uint32_t*)(cpu->edx + cpu->ecx + 0x2Cu) != 0u) goto label_0003C731;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
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
    g_sfera_mbc_runtime->active_process = reinterpret_cast<SferaMbcProcessRecord*>(static_cast<std::uintptr_t>(cpu->esi));
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->process_index = cpu->edx;
    g_sfera_mbc_runtime->active_tag = 0u;
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003C770:
    if ((int32_t)(g_sfera_mbc_runtime->argument_count -= 2u) >= 0) goto label_0003C781;
    cpu->ecx |= 0xFFFFFFFFu;
    g_sfera_mbc_runtime->active_tag = cpu->ecx; g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003C781:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43C786u);
    if (cpu->eax > 0xFFFFu) goto label_0003C7AA;
    cpu->edx = cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    if (*(uint32_t*)(cpu->edx + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id)) != cpu->eax) goto label_0003C7AA;
    if ((int32_t)*(uint32_t*)(cpu->edx + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index)) < (int32_t)0u) goto label_0003C7AA;
    if ((int32_t)cpu->eax > 0) goto label_0003C7B2;
    label_0003C7AA:
    cpu->ecx |= 0xFFFFFFFFu;
    g_sfera_mbc_runtime->active_tag = cpu->ecx; g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003C7B2:
    cpu->ecx = cpu->eax;
    goto label_0003C500;
}
__declspec(noinline) void sfera_sub_0043C7C0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[3];
    goto label_0003C7C0;
    label_0003C500:
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    cpu->esi += ((uintptr_t)&g_sfera_mbc_runtime->processes[0]);
    sub_pred[1] = *(uint32_t*)(cpu->esi + 0x68u) == 0u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    if (!sub_pred[1]) goto label_0003C53F;
    cpu->ecx |= 0xFFFFFFFFu;
    g_sfera_mbc_runtime->active_tag = cpu->ecx; g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x43C52Fu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003C53F:
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    lift_push32(cpu, cpu->ebx);
    cpu->eax <<= 5u;
    sub_pred[2] = (uint32_t)((uint64_t)(g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type)) == 1u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    if (!sub_pred[2]) goto label_0003C5EF;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x43C55Cu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->ecx += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_0003C5B6;
    if ((cpu->edx & 0xFFu) == 0u) goto label_0003C5B2;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_0003C5B6;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0003C596;
    label_0003C5B2:
    cpu->eax = 0u;
    goto label_0003C5BB;
    label_0003C5B6:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
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
    g_sfera_mbc_runtime->active_tag = cpu->ecx; g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x43C5DCu);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003C5EF:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43C5F4u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xC4u);
    cpu->eax = *(uint16_t*)(cpu->ecx + (cpu->eax * 2u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (cpu->eax == 0xFFFFu) goto label_0003C5D4;
    label_0003C609:
    cpu->ebp = g_sfera_mbc_runtime->execution_context_depth;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->edi = g_sfera_mbc_runtime->process_index;
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->bytecode_base));
    cpu->ebx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->program_table_base));
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].process_index = cpu->edi;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x348u);
    cpu->edi = *(uint32_t*)(cpu->edi + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id));
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].process_memory_base = cpu->ecx;
    cpu->ecx = g_sfera_mbc_runtime->program_index;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].program_index = cpu->ecx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xA4u);
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].bytecode_base = reinterpret_cast<decltype(g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].bytecode_base)>(cpu->edx);
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->instruction_cursor));
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].process_id = cpu->edi;
    cpu->edi = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].instruction_cursor = cpu->edx;
    cpu->edx -= static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->bytecode_base));
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].active_process = cpu->edi;
    g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].program_table_base = reinterpret_cast<decltype(g_sfera_mbc_runtime->execution_context_stack[cpu->ebp].program_table_base)>(cpu->ebx);
    cpu->ecx += cpu->ebx;
    g_sfera_mbc_runtime->active_program_record = reinterpret_cast<ScriptProgramDiagnostic*>(static_cast<std::uintptr_t>(cpu->ecx));
    ++cpu->ebp;
    g_sfera_mbc_runtime->execution_context_depth = cpu->ebp;
    *(uint32_t*)(cpu->ecx + 0x88u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x5Cu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x34u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x48u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x68u);
    g_sfera_mbc_runtime->bytecode_base = reinterpret_cast<decltype(g_sfera_mbc_runtime->bytecode_base)>(cpu->edi);
    g_sfera_mbc_runtime->program_table_base = reinterpret_cast<decltype(g_sfera_mbc_runtime->program_table_base)>(cpu->edx);
    cpu->ebx = *(uint32_t*)(cpu->eax + cpu->ecx + 0x24u);
    cpu->ebx += cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x50u);
    g_sfera_mbc_runtime->process_memory_base = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->edi));
    g_sfera_mbc_runtime->instruction_cursor = reinterpret_cast<std::uint8_t*>(static_cast<std::uintptr_t>(cpu->ebx));
    cpu->eax = *(uint32_t*)(cpu->eax + cpu->ecx + 0x28u);
    g_sfera_mbc_runtime->program_index = cpu->eax;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    cpu->edi = cpu->eax + cpu->edx;
    g_sfera_mbc_runtime->active_program_record = reinterpret_cast<ScriptProgramDiagnostic*>(static_cast<std::uintptr_t>(cpu->edi));
    *(uint8_t*)(cpu->edx + cpu->eax + 0x84u) = 0u;
    cpu->eax = g_sfera_mbc_runtime->program_index;
    cpu->edi = *(uint32_t*)(cpu->esi + 0x5Cu);
    cpu->edx = cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xA4u);
    if (*(uint8_t*)(cpu->edx + cpu->edi + 0x94u) == 0u) goto label_0003C731;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x68u);
    if (*(uint32_t*)(cpu->edx + cpu->ecx + 0x2Cu) != 0u) goto label_0003C731;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
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
    g_sfera_mbc_runtime->active_process = reinterpret_cast<SferaMbcProcessRecord*>(static_cast<std::uintptr_t>(cpu->esi));
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->process_index = cpu->edx;
    g_sfera_mbc_runtime->active_tag = 0u;
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003C7C0:
    if ((int32_t)(--g_sfera_mbc_runtime->argument_count) >= 0) goto label_0003C7D0;
    cpu->ecx |= 0xFFFFFFFFu;
    g_sfera_mbc_runtime->active_tag = cpu->ecx; g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003C7D0:
    cpu->ecx = 0u;
    goto label_0003C500;
}




__declspec(noinline) void sfera_sub_0043C980(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = 1u;
    lift_push32(cpu, cpu->edi);
    if ((int32_t)g_sfera_mbc_runtime->argument_count < (int32_t)cpu->esi) goto label_0003CC86;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43C9A9u);
    g_sfera_mbc_runtime->argument_count -= cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    if (cpu->eax != 0xFFFFFFFEu) goto label_0003C9CA;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43C9BCu);
    g_sfera_mbc_runtime->argument_count -= cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    goto label_0003CAC3;
    label_0003C9CA:
    if (cpu->eax != 0xFFFFFFFCu) goto label_0003C9E2;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43C9D4u);
    g_sfera_mbc_runtime->argument_count -= cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    goto label_0003CAC3;
    label_0003C9E2:
    if (cpu->eax != 0xFFFFFFFBu) goto label_0003C9FA;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43C9ECu);
    g_sfera_mbc_runtime->argument_count -= cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    goto label_0003CAC3;
    label_0003C9FA:
    if (cpu->eax != 0xFFFFFFF9u) goto label_0003CAB1;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43CA08u);
    g_sfera_mbc_runtime->argument_count -= cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    cpu->eax = 0x100u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43CA1Bu)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x43CA1Bu));
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = g_sfera_mbc_runtime->argument_cursor;
    cpu->ebx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->ecx;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43CA33u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x43CA38u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->esi += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43CA45u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x43CA4Au);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edi += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43CA57u);
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
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
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
    if ((*(uint32_t*)(cpu->esi + 0x1Cu) == cpu->ecx) || ((int32_t)(*(uint32_t*)(cpu->esi + 0x1Cu)) < (int32_t)(cpu->ecx))) goto label_0003CC65;
    label_0003CB0A:
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax <<= 5u;
    cpu->ebx = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].value.base;
    cpu->eax = 1u;
    g_sfera_mbc_runtime->argument_cursor += cpu->eax;
    if ((int32_t)(g_sfera_mbc_runtime->argument_count -= cpu->eax) < 0) goto label_0003CC86;
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
    --g_sfera_mbc_runtime->argument_count; sub_pred[0] = (int32_t)(g_sfera_mbc_runtime->argument_count) < 0;
    *(uint32_t*)((cpu->edi * 4u) + ((uintptr_t)&g_sfera_mbc_interpreter_storage.send_field_data[0])) = cpu->ebx;
    if (sub_pred[0]) goto label_0003CC8D;
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->ecx;
    if ((int32_t)cpu->ecx >= (int32_t)*(uint32_t*)(cpu->esi + 0x1Cu)) goto label_0003CC8D;
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->ecx + cpu->esi));
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->eax;
    if ((cpu->eax != 0x20u) && ((int32_t)(cpu->eax) >= (int32_t)(0x20u))) goto label_0003CC8D;
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax <<= 5u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type;
    if ((((cpu->eax & 0xFFu)) & (0xFu)) == 0u) goto label_0003CC8D;
    cpu->ecx = cpu->eax + 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43CBF7u)); sfera_sub_00433BB0(cpu, LIFT_CODE_TOKEN_VA(0x43CBF7u));
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->edx = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].value.base;
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
    if ((int32_t)(cpu->ecx) < (int32_t)(*(uint32_t*)(cpu->esi + 0x1Cu))) goto label_0003CB0A;
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
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->reportError(reinterpret_cast<const char*>(cpu->ecx))); cpu->eip = LIFT_CODE_TOKEN_RVA(0x3CC9Eu);
    label_0003CC9E:
    cpu->esp = cpu->ebp + 0xFFFFFFD8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043CCC0(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[2]; bool sub_pred[1]; double x87_v0;
    cpu->esp -= 0x38u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = 1u;
    lift_push32(cpu, cpu->edi);
    if ((int32_t)g_sfera_mbc_runtime->argument_count < (int32_t)cpu->esi) goto label_0003D37C;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43CCDDu);
    g_sfera_mbc_runtime->argument_count -= cpu->esi;
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ecx;
    if (cpu->ecx > 0x3Du) goto label_0003D38D;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->ecx * 4u) + 0x1D8u);
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->esi;
    if (cpu->esi != cpu->ebp) goto label_0003CD17;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003CD17:
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax + (cpu->ecx * 4u) + 0x1D8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edi = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
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
    cpu->ecx -= cpu->esi;
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
    if (cpu->eax != 0x67u) goto label_0003CFB5;
    cpu->eax = cpu->ebp;
    cpu->eax = (int32_t)(cpu->eax) >> 3u;
    cpu->edx = cpu->eax * 8u;
    cpu->ecx = cpu->ebp;
    cpu->ecx -= cpu->edx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (((uint8_t)((cpu->edx & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u)));
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    cpu->ecx = cpu->ebp + 1u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    lift_test[0]=(*(uint8_t*)(cpu->eax + cpu->edi)&(cpu->edx & 0xFFu))==0u;
    cpu->edx = cpu->ebp + 1u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((!lift_test[0]) ? 1u : 0u) & 0xFFu);
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    *(uint8_t*)(cpu->esp + 0x2Cu) = cpu->eax & 0xFFu;
    cpu->eax = cpu->edx * 8u;
    cpu->ecx -= cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (((uint8_t)((cpu->eax & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u)));
    cpu->edx += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((*(uint8_t*)(cpu->edx)&(cpu->eax & 0xFFu))!=0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((cpu->eax + cpu->eax) & 0xFFu);
    if ((cpu->eax & 0xFFu) != 0u) goto label_0003CE27;
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
    if (cpu->eax != cpu->ebx) goto label_0003CE99;
    cpu->edx = cpu->ebp;
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->eax = cpu->edx * 8u;
    cpu->ecx -= cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (((uint8_t)((cpu->eax & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u)));
    cpu->edx += cpu->edi;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((*(uint8_t*)(cpu->edx)&(cpu->eax & 0xFFu))!=0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((cpu->eax + cpu->eax) & 0xFFu);
    if ((cpu->eax & 0xFFu) != 0u) goto label_0003CE64;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->edx;
    label_0003CE64:
    if ((uint8_t)((*(uint8_t*)(cpu->edx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_0003CE6D;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) | (uint64_t)(2u))) & 0xFFu);
    goto label_0003CE70;
    label_0003CE6D:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFDu))) & 0xFFu);
    label_0003CE70:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((cpu->eax + cpu->eax) & 0xFFu);
    if ((cpu->eax & 0xFFu) != 0u) goto label_0003CE77;
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
    if (cpu->eax != 1u) goto label_0003CEE7;
    cpu->eax = cpu->ebp;
    cpu->eax = (int32_t)(cpu->eax) >> 3u;
    cpu->edx = cpu->eax * 8u;
    cpu->ecx -= cpu->edx;
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
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((cpu->eax + cpu->eax) & 0xFFu);
    if ((cpu->eax & 0xFFu) != 0u) goto label_0003CED5;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->ecx;
    label_0003CED5:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx + cpu->edx) & 0xFFu);
    if ((cpu->edx & 0xFFu) != 0u) goto label_0003CEDC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->esi;
    label_0003CEDC:
    if ((--cpu->edi) != 0u) goto label_0003CEC0;
    cpu->ebp += 7u;
    goto label_0003CF92;
    label_0003CEE7:
    sub_pred[0] = cpu->eax == 2u;
    cpu->eax = cpu->ebp;
    if (!sub_pred[0]) goto label_0003CF50;
    cpu->eax = (int32_t)(cpu->eax) >> 3u;
    cpu->edx = cpu->eax * 8u;
    cpu->ecx -= cpu->edx;
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
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((cpu->eax + cpu->eax) & 0xFFu);
    if ((cpu->eax & 0xFFu) != 0u) goto label_0003CF25;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->ecx;
    label_0003CF25:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx + cpu->edx) & 0xFFu);
    if ((cpu->edx & 0xFFu) != 0u) goto label_0003CF2C;
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
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((cpu->eax + cpu->eax) & 0xFFu);
    if ((cpu->eax & 0xFFu) != 0u) goto label_0003CF41;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->ecx;
    label_0003CF41:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx + cpu->edx) & 0xFFu);
    if ((cpu->edx & 0xFFu) != 0u) goto label_0003CF48;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->esi;
    label_0003CF48:
    if ((--cpu->edi) != 0u) goto label_0003CF10;
    cpu->ebp += 0xEu;
    goto label_0003CF92;
    label_0003CF50:
    cpu->eax = (int32_t)(cpu->eax) >> 3u;
    cpu->edx = cpu->eax * 8u;
    cpu->ecx -= cpu->edx;
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
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((cpu->eax + cpu->eax) & 0xFFu);
    if ((cpu->eax & 0xFFu) != 0u) goto label_0003CF85;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->ecx;
    label_0003CF85:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx + cpu->edx) & 0xFFu);
    if ((cpu->edx & 0xFFu) != 0u) goto label_0003CF8C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->esi;
    label_0003CF8C:
    if ((--cpu->edi) != 0u) goto label_0003CF70;
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
    if (cpu->eax != 0x65u) goto label_0003D028;
    cpu->edx = cpu->ebp;
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    cpu->eax = cpu->edx * 8u;
    cpu->ecx = cpu->ebp;
    cpu->ecx -= cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (((uint8_t)((cpu->eax & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u)));
    cpu->edx += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((*(uint8_t*)(cpu->edx)&(cpu->eax & 0xFFu))!=0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((cpu->eax + cpu->eax) & 0xFFu);
    if ((cpu->eax & 0xFFu) != 0u) goto label_0003CFE0;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->edx;
    label_0003CFE0:
    if ((uint8_t)((*(uint8_t*)(cpu->edx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_0003CFE9;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) | (uint64_t)(2u))) & 0xFFu);
    goto label_0003CFEC;
    label_0003CFE9:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFDu))) & 0xFFu);
    label_0003CFEC:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((cpu->eax + cpu->eax) & 0xFFu);
    if ((cpu->eax & 0xFFu) != 0u) goto label_0003CFF3;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->edx;
    label_0003CFF3:
    if ((uint8_t)((*(uint8_t*)(cpu->edx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_0003CFFC;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) | (uint64_t)(4u))) & 0xFFu);
    goto label_0003CFFF;
    label_0003CFFC:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFBu))) & 0xFFu);
    label_0003CFFF:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((cpu->eax + cpu->eax) & 0xFFu);
    if ((cpu->eax & 0xFFu) != 0u) goto label_0003D006;
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
    if (cpu->eax != 0x66u) goto label_0003D179;
    cpu->eax = cpu->ebp;
    cpu->eax = (int32_t)(cpu->eax) >> 3u;
    cpu->edx = cpu->eax * 8u;
    cpu->ecx = cpu->ebp;
    cpu->ecx -= cpu->edx;
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
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((cpu->ecx + cpu->ecx) & 0xFFu);
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0003D06C;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->eax;
    label_0003D06C:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx + cpu->edx) & 0xFFu);
    if ((cpu->edx & 0xFFu) != 0u) goto label_0003D073;
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
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((cpu->ecx + cpu->ecx) & 0xFFu);
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0003D088;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->eax;
    label_0003D088:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx + cpu->edx) & 0xFFu);
    if ((cpu->edx & 0xFFu) != 0u) goto label_0003D08F;
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
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((cpu->ecx + cpu->ecx) & 0xFFu);
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0003D0A4;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->eax;
    label_0003D0A4:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx + cpu->edx) & 0xFFu);
    if ((cpu->edx & 0xFFu) != 0u) goto label_0003D0AB;
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
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((cpu->ecx + cpu->ecx) & 0xFFu);
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0003D0C0;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->eax;
    label_0003D0C0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx + cpu->edx) & 0xFFu);
    if ((cpu->edx & 0xFFu) != 0u) goto label_0003D0C7;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->esi;
    label_0003D0C7:
    if ((--cpu->edi) != 0u) goto label_0003D057;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebp += 8u;
    cpu->ebx = 0u;
    label_0003D0D3:
    g_sfera_mbc_runtime->argument_count -= 2u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    if ((int32_t)(g_sfera_mbc_runtime->argument_count) < 0) goto label_0003D37C;
    cpu->ecx = g_sfera_mbc_runtime->argument_cursor;
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    cpu->esi = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source.base;
    cpu->esi += *(uint32_t*)(cpu->edx + 0x50u);
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type;
    ++cpu->ecx;
    g_sfera_mbc_runtime->argument_cursor = cpu->ecx;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D112u)); sfera_sub_00433BB0(cpu, LIFT_CODE_TOKEN_VA(0x43D112u));
    if ((cpu->eax == cpu->ebx) || ((int32_t)(cpu->eax) < (int32_t)(cpu->ebx))) goto label_0003D125;
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43D11Du));
    cpu->esp += 0xCu;
    label_0003D125:
    cpu->esi = g_sfera_mbc_runtime->argument_cursor;
    cpu->esi <<= 5u;
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->esi >> 5u].type;
    if ((((cpu->eax & 0xFFu)) & (0xFu)) == 0u) goto label_0003D36B;
    cpu->ecx = cpu->eax + 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D144u)); sfera_sub_00433BB0(cpu, LIFT_CODE_TOKEN_VA(0x43D144u));
    cpu->esi = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->esi >> 5u].value.base;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
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
    if (cpu->eax != 0x6Cu) goto label_0003D26E;
    cpu->eax = cpu->ebp;
    cpu->eax = (int32_t)(cpu->eax) >> 3u;
    cpu->edx = cpu->eax * 8u;
    cpu->ecx = cpu->ebp;
    cpu->ecx -= cpu->edx;
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
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((cpu->ecx + cpu->ecx) & 0xFFu);
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0003D1F7;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->eax;
    label_0003D1F7:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx + cpu->edx) & 0xFFu);
    if ((cpu->edx & 0xFFu) != 0u) goto label_0003D1FE;
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
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((cpu->ecx + cpu->ecx) & 0xFFu);
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0003D213;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->eax;
    label_0003D213:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx + cpu->edx) & 0xFFu);
    if ((cpu->edx & 0xFFu) != 0u) goto label_0003D21A;
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
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((cpu->ecx + cpu->ecx) & 0xFFu);
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0003D22F;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->eax;
    label_0003D22F:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx + cpu->edx) & 0xFFu);
    if ((cpu->edx & 0xFFu) != 0u) goto label_0003D236;
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
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((cpu->ecx + cpu->ecx) & 0xFFu);
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0003D24B;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->eax;
    label_0003D24B:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->edx + cpu->edx) & 0xFFu);
    if ((cpu->edx & 0xFFu) != 0u) goto label_0003D252;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (1u & 0xFFu);
    ++cpu->esi;
    label_0003D252:
    if ((--cpu->edi) != 0u) goto label_0003D1E2;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebp += 8u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    x87_v0 = (x87_v0) * (0.02454369328916073);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    label_0003D26E:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    if (cpu->ebx!=0u) goto label_0003D2D8;
    if ((int32_t)(--g_sfera_mbc_runtime->argument_count) < 0) goto label_0003D37C;
    cpu->edx = g_sfera_mbc_runtime->argument_cursor;
    cpu->esi = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
    cpu->eax = cpu->edx;
    cpu->eax <<= 5u;
    cpu->ecx = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source.base;
    cpu->ecx += *(uint32_t*)(cpu->esi + 0x50u);
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type;
    ++cpu->edx;
    g_sfera_mbc_runtime->argument_cursor = cpu->edx;
    if (cpu->eax != 0u) goto label_0003D2B2;
    cpu->eax = cpu->ebx + 1u;
    goto label_0003D2C3;
    label_0003D2B2:
    lift_test[1]=((cpu->eax & 0xFFu)&0xFu)==0u;
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((!lift_test[1]) ? 1u : 0u) & 0xFFu);
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
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
    *(uint32_t*)(cpu->edx + (cpu->ecx * 4u) + 0xDCu) = cpu->eax;
    label_0003D338:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x43D340u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, 0x1DE0u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    lift_push32(cpu, 0x1DE1u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->esi;
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003D36B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = (uintptr_t)"Wrong data for 'receive' function";
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->reportError(reinterpret_cast<const char*>(cpu->ecx))); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003D37C:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = (uintptr_t)"Wrong number of parameters for 'receive' function";
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->reportError(reinterpret_cast<const char*>(cpu->ecx))); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003D38D:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = (uintptr_t)"Wrong region for 'receive' function";
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->reportError(reinterpret_cast<const char*>(cpu->ecx))); cpu->esp += 4u; cpu->eip = stop_address; return;
}



__declspec(noinline) void sfera_sub_0043D4C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x43D4C7u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x43D4CEu);
    cpu->edi = *(uint32_t*)(cpu->eax);
    if (((uint32_t)(g_sfera_mbc_runtime->argument_count) == 2u) || ((int32_t)((uint32_t)(g_sfera_mbc_runtime->argument_count)) < (int32_t)(2u))) goto label_0003D4E0;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43D4DEu);
    goto label_0003D4E2;
    label_0003D4E0:
    cpu->eax = 0u;
    label_0003D4E2:
    lift_push32(cpu, cpu->eax);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->edx = cpu->eax + cpu->edi;
    cpu->ecx = cpu->eax + cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43D4F3u)); sfera_sub_00433470(cpu, LIFT_CODE_TOKEN_VA(0x43D4F3u));
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    if ((int32_t)(cpu->edx) < (int32_t)(0x100u)) goto label_0003D50D;
    cpu->ecx = (uintptr_t)"Stack overflow";
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->reportError(reinterpret_cast<const char*>(cpu->ecx))); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003D50D:
    cpu->ecx = cpu->edx;
    cpu->ecx <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].value.base = cpu->eax;
    cpu->eax = 1u;
    cpu->edx += cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source.base = 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source.end = cpu->eax;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source.begin = cpu->eax;
    g_sfera_mbc_runtime->value_stack_size = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}











__declspec(noinline) void sfera_sub_0043DDE0(LiftCpu* cpu, uint32_t stop_address) { double value_0;
 bool sub_pred[7]; double x87_p0;
    goto label_0003DDE0;
label_000341F0:
    sub_pred[0] = (uint32_t)((uint64_t)(g_sfera_log_first_write)) == 0u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uintptr_t)"wt";
    if (!sub_pred[0]) goto label_00034207;
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
    sub_pred[1] = (uint32_t)((uint64_t)(g_sfera_log_first_write)) == 0u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uintptr_t)"wt";
    if (!sub_pred[1]) goto label_00034307;
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
    sub_pred[2] = (uint32_t)((uint64_t)(g_sfera_log_first_write)) == 0u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uintptr_t)"wt";
    if (!sub_pred[2]) goto label_000343F7;
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
    sub_pred[3] = (uint32_t)((uint64_t)(g_sfera_log_first_write)) == 0u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uintptr_t)"wt";
    if (!sub_pred[3]) goto label_000344E7;
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
    sub_pred[4] = (uint32_t)((uint64_t)(g_sfera_log_first_write)) == 0u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uintptr_t)"wt";
    if (!sub_pred[4]) goto label_00034587;
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
    sub_pred[5] = (uint32_t)((uint64_t)(g_sfera_log_first_write)) == 0u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uintptr_t)"wt";
    if (!sub_pred[5]) goto label_000345D7;
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
    sub_pred[6] = (uint32_t)((uint64_t)(g_sfera_log_first_write)) == 0u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->eax = (uintptr_t)"wt";
    if (!sub_pred[6]) goto label_000346B7;
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
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43DDFDu);
    cpu->esi = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_0003E0EC;
    if (g_sfera_mbc_runtime->argument_count != 2u) goto label_0003DF36;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43DE1Eu);
    if (cpu->eax != 1u) goto label_0003DE34;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx += cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_004342A0(cpu, stop_address); return;
label_0003DE34:
    if (cpu->eax != 2u) goto label_0003DE4B;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx = cpu->ecx + cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434390(cpu, stop_address); return;
label_0003DE4B:
    if (cpu->eax != 3u) goto label_0003DE62;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx = cpu->ecx + cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434480(cpu, stop_address); return;
label_0003DE62:
    if (cpu->eax != 9u) goto label_0003DE7E;
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->edx = cpu->edx + cpu->esi;
    cpu->ecx = (uintptr_t)"logs\\goldtaler";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434660(cpu, stop_address); return;
label_0003DE7E:
    if (cpu->eax != 0xAu) goto label_0003DE99;
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->edx += cpu->esi;
    cpu->ecx = (uintptr_t)"logs\\mstatin";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434660(cpu, stop_address); return;
label_0003DE99:
    if (cpu->eax != 0xBu) goto label_0003DEB5;
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->edx = cpu->edx + cpu->esi;
    cpu->ecx = (uintptr_t)"logs\\mstatout";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434660(cpu, stop_address); return;
label_0003DEB5:
    if (cpu->eax != 0xCu) goto label_0003DED1;
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->edx = cpu->edx + cpu->esi;
    cpu->ecx = (uintptr_t)"logs\\gtstatin";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434660(cpu, stop_address); return;
label_0003DED1:
    if (cpu->eax != 0xDu) goto label_0003DEEC;
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->edx += cpu->esi;
    cpu->ecx = (uintptr_t)"logs\\gtstatout";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434660(cpu, stop_address); return;
label_0003DEEC:
    if (cpu->eax != 0xEu) goto label_0003DF08;
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->edx = cpu->edx + cpu->esi;
    cpu->ecx = (uintptr_t)"logs\\bigmoney";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434660(cpu, stop_address); return;
label_0003DF08:
    if (cpu->eax != 0xFu) goto label_0003DF24;
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->edx = cpu->edx + cpu->esi;
    cpu->ecx = (uintptr_t)"logs\\chat";
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_00434660(cpu, stop_address); return;
label_0003DF24:
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx = cpu->ecx + cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_00034570;
label_0003DF36:
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx = cpu->ecx + cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_004341A0(cpu, stop_address); return;
label_0003DF48:
    if (cpu->eax == 0x20u) goto label_0003E026;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43DF56u);
    cpu->esi = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_0003E0EC;
    if (g_sfera_mbc_runtime->argument_count != 2u) goto label_0003E01B;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43DF77u);
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
    value_0 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E02Bu);
    *(float*)(cpu->esp + 4u) = value_0; 
     if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003E0EC;
    if (g_sfera_mbc_runtime->argument_count != 2u) goto label_0003E0DF;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E04Eu);
    x87_p0 = (double)*(float*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_p0; 
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
    x87_p0 = (double)*(float*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_p0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3E0ECu)); sfera_sub_00434240(cpu, LIFT_CODE_TOKEN_RVA(0x3E0ECu));
label_0003E0EC:
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043E0F0(LiftCpu* cpu, uint32_t stop_address) { double value_0;
 bool sub_pred[3]; double x87_p0;
    sub_pred[0] = (uint32_t)(g_sfera_mbc_runtime->argument_count) == 0u; sub_pred[2] = (int32_t)((uint32_t)(g_sfera_mbc_runtime->argument_count)) < (int32_t)(0u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((sub_pred[0]) || (sub_pred[2])) goto label_0003E20A;
    lift_push32(cpu, cpu->esi);
label_0003E101:
    cpu->esi = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax = cpu->esi;
    cpu->eax <<= 5u;
    cpu->ecx = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type;
    if ((((cpu->ecx & 0xFFu)) & (0xFu)) == 0u) goto label_0003E1D7;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_mbc_runtime->argument_end) goto label_0003E197;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldDiagnostics::scriptContext()));
    cpu->ecx = (uintptr_t)"\n---exit_inter start---\nMBINTER MESSAGE:";
    g_sfera_log_runtime.files[0].write(reinterpret_cast<const char*>(cpu->ecx));
    cpu->ecx = (uintptr_t)"Too few parameters";
    g_sfera_log_runtime.files[0].write(reinterpret_cast<const char*>(cpu->ecx));
    cpu->ecx = (uintptr_t)"\n";
    g_sfera_log_runtime.files[0].write(reinterpret_cast<const char*>(cpu->ecx));
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    g_sfera_log_runtime.files[0].write(reinterpret_cast<const char*>(cpu->ecx));
    cpu->ecx = (uintptr_t)"---exit_inter end-----\n";
    g_sfera_log_runtime.files[0].write(reinterpret_cast<const char*>(cpu->ecx));
    sub_pred[1] = (uint32_t)(g_sfera_mbc_runtime->process_index) == 0u;
    g_sfera_mbc_runtime->execution_failed = 1u;
    if (!sub_pred[1]) goto label_0003E177;
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3E177u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x3E177u));
label_0003E177:
    cpu->edx = (uintptr_t)"EError";
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->processes[0];
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<SferaMbcProcessRecord*>(cpu->ecx)->activateProgram(reinterpret_cast<const char*>(cpu->edx))); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E186u);
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax = 0u;
    cpu->ecx += cpu->eax;
    *(uint32_t*)(cpu->edi) = cpu->ecx;
    cpu->edi += 4u;
    goto label_0003E1F6;
label_0003E197:
    if ((cpu->ecx & 0xFFu) == 0x10u) goto label_0003E1BB;
    if ((cpu->ecx & 0xFFu) != 0x20u) goto label_0003E1AE;
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].value.base);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_p0); 
    goto label_0003E1C1;
label_0003E1AE:
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0003E1BB;
    cpu->eax = (int8_t)(((uint8_t)g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].value.base));
    goto label_0003E1C1;
label_0003E1BB:
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].value.base;
label_0003E1C1:
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E1E5u);
    *(uint32_t*)(cpu->edi) = cpu->eax;
    cpu->edi += 4u;
    goto label_0003E1F6;
label_0003E1EC:
    value_0 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E1F1u);
    *(double*)(cpu->edi) = value_0;
    cpu->edi += 8u;
label_0003E1F6:
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    --cpu->eax;
    g_sfera_mbc_runtime->argument_count = cpu->eax;
    if ((cpu->eax!=0u) && (((cpu->eax)&0x80000000u)==0u)) goto label_0003E101;
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
    if ((int32_t)((uint32_t)(g_sfera_mbc_runtime->argument_count)) < (int32_t)(cpu->edi)) goto label_0003E267;
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax <<= 5u;
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type;
    if (cpu->eax == 0x10u) goto label_0003E257;
    if (cpu->eax != 0u) goto label_0003E267;
    label_0003E257:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E25Cu);
    g_sfera_mbc_runtime->argument_count -= cpu->edi;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    goto label_0003E26E;
    label_0003E267:
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = 0u;
    label_0003E26E:
    if ((int32_t)g_sfera_mbc_runtime->argument_count >= (int32_t)cpu->edi) goto label_0003E280;
    cpu->ecx = (uintptr_t)"Invalid parameter list: fflogf()";
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->reportError(reinterpret_cast<const char*>(cpu->ecx))); cpu->eip = LIFT_CODE_TOKEN_RVA(0x3E280u);
    label_0003E280:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E285u);
    cpu->esi = cpu->eax;
    cpu->esi += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->esi;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_0003E4AA;
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
        default: cpu->eip = 0x43E302u; throw std::out_of_range("resolved jump-table index out of range"); return;
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
    cpu->eax = (uintptr_t)"wt";
    if ((uint32_t)((uint64_t)(g_sfera_log_first_write)) != 0u) goto label_0003E483;
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
    if ((int32_t)((uint32_t)(g_sfera_mbc_runtime->argument_count)) < (int32_t)(cpu->ebx)) goto label_0003E564;
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax <<= 5u;
    cpu->eax = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type;
    if (cpu->eax == 0x10u) goto label_0003E556;
    if (cpu->eax != 0u) goto label_0003E564;
    label_0003E556:
    *(uint8_t*)(cpu->ebp + 0xFFFFFF83u) = cpu->ebx & 0xFFu;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E55Eu);
    g_sfera_mbc_runtime->argument_count -= cpu->ebx;
    label_0003E564:
    if ((int32_t)g_sfera_mbc_runtime->argument_count >= (int32_t)2u) goto label_0003E577;
    cpu->ecx = (uintptr_t)"Invalid parameter list: ffflogf()";
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->reportError(reinterpret_cast<const char*>(cpu->ecx))); cpu->eip = LIFT_CODE_TOKEN_RVA(0x3E577u);
    label_0003E577:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E57Cu);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->esi += cpu->eax;
    if (cpu->esi != cpu->eax) goto label_0003E59B;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffflogf, pchFileName\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E598u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x43E598u));
    cpu->esp += 8u;
    label_0003E59B:
    g_sfera_mbc_runtime->argument_count -= cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E5A6u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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

__declspec(noinline) void sfera_sub_0043E6F0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E6F6u);
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_0003E70E;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffcreate\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E70Bu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x43E70Bu));
    cpu->esp += 8u;
    label_0003E70E:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003E77C;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax += cpu->esi;
    lift_push32(cpu, 0x180u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_chmod), LIFT_CODE_TOKEN_VA(0x43E724u));
    cpu->esp += 8u;
    sub_pred[0] = (uint32_t)(g_sfera_mbc_runtime->argument_count) == 2u;
    lift_push32(cpu, 0x180u);
    if (!sub_pred[0]) goto label_0003E74B;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    lift_push32(cpu, 0x8102u);
    cpu->ecx += cpu->esi;
    lift_push32(cpu, cpu->ecx);
    goto label_0003E759;
    label_0003E74B:
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    lift_push32(cpu, 0x8302u);
    cpu->edx += cpu->esi;
    lift_push32(cpu, cpu->edx);
    label_0003E759:
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x43E759u));
    cpu->esi = cpu->eax;
    cpu->esp += 0xCu;
    cpu->ecx = cpu->esi;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E76Bu);
    if ((int32_t)cpu->esi < 0) goto label_0003E77C;
    cpu->ecx = cpu->esi;
    cpu->edx = 1u;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->active_process->registerResource(cpu->ecx, cpu->edx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E77C:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043E780(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0x8002u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E78Cu);
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_0003E7A4;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffopen\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E7A1u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x43E7A1u));
    cpu->esp += 8u;
    label_0003E7A4:
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax += cpu->esi;
    lift_push32(cpu, 0x180u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_chmod), LIFT_CODE_TOKEN_VA(0x43E7B1u));
    cpu->esp += 8u;
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003E830;
    if ((int32_t)g_sfera_mbc_runtime->argument_count <= (int32_t)1u) goto label_0003E7DB;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E7D1u);
    if (cpu->eax != 1u) goto label_0003E80B;
    cpu->edi = 0x8000u;
    label_0003E7DB:
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    lift_push32(cpu, 0u);
    cpu->edx += cpu->esi;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x43E7E7u));
    cpu->esp += 0xCu;
    label_0003E7F0:
    cpu->esi = cpu->eax;
    cpu->ecx = cpu->esi;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E7F9u);
    if ((int32_t)cpu->esi < 0) goto label_0003E830;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->edx = 1u;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->active_process->registerResource(cpu->ecx, cpu->edx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E80B:
    if (cpu->eax != 3u) goto label_0003E7DB;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E847u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E84Eu);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E855u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003E88D;
    lift_push32(cpu, cpu->eax);
    if (cpu->edi != 0u) goto label_0003E878;
    lift_push32(cpu, 2u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_locking), LIFT_CODE_TOKEN_VA(0x43E866u));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E878:
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_locking), LIFT_CODE_TOKEN_VA(0x43E87Bu));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E88D:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043E890(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E896u);
    cpu->esi = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_0003E8BD;
    if ((int32_t)cpu->esi < 0) goto label_0003E8BD;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x43E8A6u));
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = 1u;
    cpu->ecx = cpu->esi;
    { auto* process = reinterpret_cast<SferaMbcProcessRecord*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)); (process != nullptr ? process : g_sfera_mbc_runtime->active_process)->unregisterResource(cpu->ecx, cpu->edx); } cpu->esp += 4u; cpu->eip = LIFT_CODE_TOKEN_RVA(0x3E8BDu);
    label_0003E8BD:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043E8C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E8C9u);
    cpu->ebp = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E8D0u);
    cpu->esi = cpu->eax;
    cpu->edi = *(uint32_t*)(cpu->esi);
    cpu->edi += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E8DFu);
    cpu->ebx = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_0003E939;
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
    reinterpret_cast<SferaSliceReference32*>(cpu->ecx)->diagnoseRange(cpu->edx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x3E913u);
    label_0003E913:
    if ((int32_t)cpu->ebp < 0) goto label_0003E92E;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_write), LIFT_CODE_TOKEN_VA(0x43E91Au));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E92E:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->ebx = lift_pop32(cpu);
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E939:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043E940(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E946u);
    cpu->ebp = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_0003E9AA;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E959u);
    cpu->esi = cpu->eax;
    cpu->edi = *(uint32_t*)(cpu->esi);
    cpu->edi += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E968u);
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
    reinterpret_cast<SferaSliceReference32*>(cpu->ecx)->diagnoseRange(cpu->edx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x3E993u);
    label_0003E993:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x43E996u));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->ebp = lift_pop32(cpu);
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003E9AA:
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043E9B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E9B8u);
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_0003EA58;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E9D1u);
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_0003E9E9;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffread\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43E9E6u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x43E9E6u));
    cpu->esp += 8u;
    label_0003E9E9:
    cpu->ebx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ebx += cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43E9F6u);
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
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_read)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u), *(uint32_t*)(cpu->esp + 0x8u));
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
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EA42u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003EA49:
    *(uint8_t*)(cpu->esi + cpu->ebx) = 0u;
    label_0003EA4D:
    cpu->ebp = lift_pop32(cpu);
    label_0003EA4E:
    cpu->ecx = cpu->esi;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EA55u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0003EA58:
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043EA60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EA67u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EA6Eu);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EA75u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003EAA7;
    if (cpu->eax != 1u) goto label_0003EA87;
    cpu->eax = 0u;
    goto label_0003EA92;
    label_0003EA87:
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (cpu->eax != 2u);
    cpu->eax = cpu->ecx + 1u;
    label_0003EA92:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_lseek), LIFT_CODE_TOKEN_VA(0x43EA95u));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003EAA7:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043EAB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EAB5u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003EACF;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_filelength), LIFT_CODE_TOKEN_VA(0x43EABFu));
    cpu->esp += 4u;
    cpu->ecx = cpu->eax;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003EACF:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043EAD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x34u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EAE3u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003EB03;
    cpu->ecx = cpu->esp;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_fstat64i32), LIFT_CODE_TOKEN_VA(0x43EAF1u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esp += 8u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x3EB03u);
    label_0003EB03:
    cpu->esp += 0x34u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043EB20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EB26u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EB2Du);
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
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EB64u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EB6Bu);
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
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EBB5u);
    cpu->eax += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003EBD5;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x43EBC5u));
    cpu->esp += 4u;
    cpu->ecx = cpu->eax;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003EBD5:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043EBE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EBE6u);
    cpu->esi = cpu->eax;
    cpu->esi += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EBF3u);
    cpu->eax += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003EC15;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::rename), LIFT_CODE_TOKEN_VA(0x43EC04u));
    cpu->esp += 8u;
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003EC15:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043EC20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EC25u);
    cpu->eax += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003EC46;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43EC3Bu)); sfera_sub_00436510(cpu, LIFT_CODE_TOKEN_VA(0x43EC3Bu));
    cpu->ecx = g_sfera_mbc_runtime->file_crc32;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003EC46:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}



__declspec(noinline) void sfera_sub_0043ED30(LiftCpu* cpu, uint32_t stop_address) {
    SferaMbInterObjectProfile sfera_profile;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = 0u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43ED3Au);
    cpu->ebx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43ED41u);
    cpu->edi = cpu->eax;
    if (((uint32_t)(g_sfera_mbc_runtime->argument_count) == 2u) || ((int32_t)((uint32_t)(g_sfera_mbc_runtime->argument_count)) < (int32_t)(2u))) goto label_0003ED53;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43ED51u);
    cpu->esi = cpu->eax;
    label_0003ED53:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003EDC5;
    sfera_profile = sfera_mbinter_object_profile(cpu->edi);
    cpu->ecx = sfera_profile.factory_kind;
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != 1u);
    cpu->edx = cpu->esi + 0xFFFFFFFFu;
    cpu->edx = -cpu->edx;
    cpu->edx = (cpu->edx != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx = cpu->ecx + cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_world_objects.create(reinterpret_cast<const char*>(cpu->ecx), reinterpret_cast<SferaMbcProcessRecord*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), *reinterpret_cast<const std::uint32_t*>(cpu->esp + 4u) != 0u));  cpu->esp += 8u;
    cpu->esi = cpu->eax;
    cpu->ecx = cpu->esi;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x43ED91u);
    if ((int32_t)cpu->esi >= 0) goto label_0003EDC9;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx += cpu->ebx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Error creating object: %s"); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->text_buffer[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x43EDA8u));
    cpu->esp += 0xCu;
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->text_buffer[0];
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->reportError(reinterpret_cast<const char*>(cpu->ecx))); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EDBBu);
    g_sfera_mbc_runtime->execution_failed = 0u;
    label_0003EDC5:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003EDC9:
    cpu->ecx = cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_world_objects.object(cpu->ecx, "GetObjectPointer")));
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
    g_sfera_mbc_runtime->active_process->registerResource(cpu->ecx, cpu->edx); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043EE40(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2;
 double x87_p0, x87_p1;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EE49u);
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi < 0) goto label_0003EF47;
    value_1 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EE58u);
    *(float*)(cpu->esp + 4u) = value_1; 
     value_2 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EE61u);
    *(float*)(cpu->esp + 8u) = value_2; 
     value_0 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EE6Au);
    *(float*)(cpu->esp + 0xCu) = value_0; 
    cpu->ecx = cpu->esi;
     cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_world_objects.object(cpu->ecx, "GetObjectPointer")));
    g_sfera_inter_scalar_runtime.mode_03 = cpu->eax;
    if (cpu->eax != 0u) goto label_0003EE8D;
    g_sfera_mbc_runtime->active_tag = 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
label_0003EE8D:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003EF47;
    *(float*)(cpu->eax + 8u) = (double)*(float*)(cpu->esp + 4u);
    cpu->eax = g_sfera_inter_scalar_runtime.mode_03;
    *(float*)(cpu->eax + 0xCu) = (double)*(float*)(cpu->esp + 8u);
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    *(float*)(cpu->ecx + 0x10u) = (double)*(float*)(cpu->esp + 0xCu);
    if (cpu->esi != g_sfera_world_objects.controlled_object_handle) goto label_0003EF1B;
    if (g_sfera_graphics_runtime.render_mode_enabled != 1u) goto label_0003EF1B;
    cpu->eax = g_sfera_inter_scalar_runtime.mode_03;
    *(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32) = (double)*(float*)(cpu->eax + 8u);
    *(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32) = (double)*(float*)(cpu->eax + 0xCu);
    g_sfera_main_input_state_runtime.motion_accumulator = (double)*(float*)(cpu->eax + 0x10u);
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32);
    x87_p1 = 333.0;
    x87_p0 = (x87_p0) + (x87_p1);
    std::swap(x87_p1, x87_p0);
    *(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32) = x87_p1; 
    x87_p1 = (double)*(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32);
    x87_p1 = (x87_p1) + (x87_p0);
    *(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32) = x87_p1; 
    x87_p0 = (x87_p0) + (((double)(*(float*)(void*)&g_sfera_main_input_state_runtime.motion_accumulator)));
    g_sfera_main_input_state_runtime.motion_accumulator = x87_p0; 
label_0003EF1B:
    if ((int32_t)g_sfera_mbc_runtime->argument_count < (int32_t)5u) goto label_0003EF47;
    cpu->ecx = cpu->esi;
    g_sfera_world_objects.updateSpatialIndex(cpu->ecx);
    if (g_sfera_mbc_runtime->argument_count != 6u) goto label_0003EF47;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EF39u);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43EF3Eu);
    cpu->edx = g_sfera_inter_scalar_runtime.mode_03;
    *(uint32_t*)(cpu->edx + 0x20u) = cpu->eax;
label_0003EF47:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}






__declspec(noinline) void sfera_sub_0043F0D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F0D6u);
    cpu->esi = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_0003F0F8;
    if (cpu->esi == 0xFFFFFFFFu) goto label_0003F0ED;
    cpu->ecx = cpu->esi;
    g_sfera_world_objects.destroy(cpu->ecx);
    label_0003F0ED:
    lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    { auto* process = reinterpret_cast<SferaMbcProcessRecord*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)); (process != nullptr ? process : g_sfera_mbc_runtime->active_process)->unregisterResource(cpu->ecx, cpu->edx); } cpu->esp += 4u; cpu->eip = LIFT_CODE_TOKEN_RVA(0x3F0F8u);
    label_0003F0F8:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_0043F180(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = 0u;
    cpu->ebp = 0u;
    cpu->edi = 0u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F18Fu);
    cpu->ebx = cpu->eax;
    if ((int32_t)cpu->ebx >= 0) goto label_0003F1A0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->ebx = lift_pop32(cpu);
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003F1A0:
    if (g_sfera_mbc_runtime->argument_count != 5u) goto label_0003F1D5;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F1AEu);
    cpu->edi = cpu->eax;
    cpu->edi += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F1BBu);
    cpu->esi = cpu->eax;
    cpu->esi += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F1C8u);
    cpu->ebp = cpu->eax;
    cpu->ebp += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_RVA(0x3F1D5u);
    label_0003F1D5:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003F205;
    cpu->ecx = cpu->ebx;
    if (((uint32_t)(g_sfera_mbc_runtime->argument_count) == 1u) || ((int32_t)((uint32_t)(g_sfera_mbc_runtime->argument_count)) < (int32_t)(1u))) goto label_0003F297;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_world_objects.object(cpu->ecx, "GetObjectPointer")));
    g_sfera_inter_scalar_runtime.mode_03 = cpu->eax;
    if (cpu->eax != 0u) goto label_0003F20A;
    g_sfera_mbc_runtime->active_tag = 0xFFFFFFFFu;
    label_0003F205:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003F20A:
    lift_push32(cpu, 0x2178u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SphereRender::CharacterModels::checkedExtended(reinterpret_cast<WorldObject*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp))));  cpu->esp += 4u;
    cpu->ebx = cpu->eax;
    if (*(uint8_t*)(cpu->ebx + 0x2A0u) == 0u) goto label_0003F22A;
    cpu->ecx = 0u;
    goto label_0003F22D;
    label_0003F22A:
    cpu->ecx |= 0xFFFFFFFFu;
    label_0003F22D:
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F232u);
    *(uint8_t*)(cpu->ebx + 0x2A0u) = 0u;
    if (cpu->edi == 0u) goto label_0003F205;
    if (*(uint8_t*)(cpu->ebx + 0x2A1u) == 0u) goto label_0003F28C;
    *(uint32_t*)(cpu->edi) = 1u;
    if (cpu->esi == 0u) goto label_0003F272;
    if (cpu->esi == static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base))) goto label_0003F272;
    *(float*)(cpu->esi) = (double)*(float*)(cpu->ebx + 0x2A4u);
    *(float*)(cpu->esi + 4u) = (double)*(float*)(cpu->ebx + 0x2A8u);
    *(float*)(cpu->esi + 8u) = (double)*(float*)(cpu->ebx + 0x2ACu);
    label_0003F272:
    if (cpu->ebp == 0u) goto label_0003F205;
    if (cpu->ebp == static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base))) goto label_0003F205;
    x87_v0 = (double)*(float*)(cpu->ebx + 0x2B0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(float*)(cpu->ebp) = x87_v0; 
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003F28C:
    *(uint32_t*)(cpu->edi) = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003F297:
    cpu->edx = 0u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_contacts.testMovement(cpu->ecx, cpu->edx != 0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F2B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F2B5u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003F2E0;
    if ((int32_t)cpu->eax < 0) goto label_0003F2D8;
    cpu->ecx = cpu->eax;
    { const auto* object = g_sfera_world_objects.object(cpu->ecx, "GetProcess"); cpu->eax = object != nullptr && object->extended_pose_available != 0u ? static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(static_cast<const ExtendedWorldObject*>(object)->process_handle)) : 0u; }
    if (cpu->eax == 0u) goto label_0003F2D8;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xB4u);
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003F2D8:
    cpu->ecx |= 0xFFFFFFFFu;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003F2E0:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F2F0(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2;
 double x87_p0, x87_p1;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F2F9u);
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi < 0) goto label_0003F3D3;
    value_1 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F308u);
    *(float*)(cpu->esp + 4u) = value_1; 
     value_2 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F311u);
    *(float*)(cpu->esp + 8u) = value_2; 
     value_0 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F31Au);
    *(float*)(cpu->esp + 0xCu) = value_0; 
    cpu->ecx = cpu->esi;
     cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_world_objects.object(cpu->ecx, "GetObjectPointer")));
    g_sfera_inter_scalar_runtime.mode_03 = cpu->eax;
    if (cpu->eax != 0u) goto label_0003F33D;
    g_sfera_mbc_runtime->active_tag = 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
label_0003F33D:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003F3D3;
    *(float*)(cpu->eax + 8u) = ((((double)*(float*)(cpu->eax + 8u))) + (((double)*(float*)(cpu->esp + 4u))));
    cpu->eax = g_sfera_inter_scalar_runtime.mode_03;
    *(float*)(cpu->eax + 0xCu) = ((((double)*(float*)(cpu->eax + 0xCu))) + (((double)*(float*)(cpu->esp + 8u))));
    cpu->eax = g_sfera_inter_scalar_runtime.mode_03;
    *(float*)(cpu->eax + 0x10u) = ((((double)*(float*)(cpu->eax + 0x10u))) + (((double)*(float*)(cpu->esp + 0xCu))));
    if (cpu->esi != g_sfera_world_objects.controlled_object_handle) goto label_0003F3D3;
    if (g_sfera_graphics_runtime.render_mode_enabled != 1u) goto label_0003F3D3;
    cpu->eax = g_sfera_inter_scalar_runtime.mode_03;
    *(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32) = (double)*(float*)(cpu->eax + 8u);
    *(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32) = (double)*(float*)(cpu->eax + 0xCu);
    g_sfera_main_input_state_runtime.motion_accumulator = (double)*(float*)(cpu->eax + 0x10u);
    x87_p0 = (double)*(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32);
    x87_p1 = 333.0;
    x87_p0 = (x87_p0) + (x87_p1);
    std::swap(x87_p1, x87_p0);
    *(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_x.f32) = x87_p1; 
    x87_p1 = (double)*(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32);
    x87_p1 = (x87_p1) + (x87_p0);
    *(float*)((uintptr_t)&g_sfera_scene_control_runtime.camera_y.f32) = x87_p1; 
    x87_p0 = (x87_p0) + (((double)(*(float*)(void*)&g_sfera_main_input_state_runtime.motion_accumulator)));
    g_sfera_main_input_state_runtime.motion_accumulator = x87_p0; 
label_0003F3D3:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}



__declspec(noinline) void sfera_sub_0043F4E0(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1];
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F4E6u);
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi < 0) goto label_0003F51F;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F4F1u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003F51F;
    lift_push32(cpu, cpu->ebx);
    lift_test[0]=cpu->eax==0u;
    lift_push32(cpu, 0x21FAu);
    cpu->ecx = cpu->esi;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((!lift_test[0]) ? 1u : 0u) & 0xFFu);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_world_objects.object(cpu->ecx, "GetObjectPointer")));
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SphereRender::CharacterModels::checkedExtended(reinterpret_cast<WorldObject*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp))));  cpu->esp += 4u;
    *(uint8_t*)(cpu->eax + 0x141u) = cpu->ebx & 0xFFu;
    cpu->ebx = lift_pop32(cpu);
    label_0003F51F:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F530(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1;
 bool sub_pred[1];
    lift_push32(cpu, cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->eax <<= 5u;
    sub_pred[0] = (uint32_t)((uint64_t)(g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type)) == 1u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if (sub_pred[0]) goto label_0003F5A4;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F54Bu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F554u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F55Bu);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F562u);
    cpu->ebx = cpu->eax;
    value_0 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F569u);
    cpu->eax = (uint32_t)(int32_t)std::trunc(value_0); 
    cpu->ebp = cpu->eax;
     if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_0003F59E;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(GameInterface::window(cpu->ecx, "GetWindowPointer")));
    if (cpu->eax == 0u) goto label_0003F5D8;
    reinterpret_cast<GameUiWindow*>(cpu->eax)->textColor = cpu->esi;
    reinterpret_cast<GameUiWindow*>(cpu->eax)->textStyle = cpu->edi;
    reinterpret_cast<GameUiWindow*>(cpu->eax)->font = cpu->ebx;
    reinterpret_cast<GameUiWindow*>(cpu->eax)->fontScale = cpu->ebp;
label_0003F59E:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
label_0003F5A4:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F5A9u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F5B0u);
    cpu->ebx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F5B7u);
    cpu->ebp = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F5BEu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)((uint32_t)(g_sfera_mbc_runtime->argument_count)) < (int32_t)(8u)) goto label_0003F61A;
    cpu->ecx = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(GameInterface::window(cpu->ecx, "GetWindowPointer")));
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_0003F5E9;
label_0003F5D8:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = (uintptr_t)"Wrong parameters for 'text' function";
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->reportError(reinterpret_cast<const char*>(cpu->ecx))); cpu->esp += 4u; cpu->eip = stop_address; return;
label_0003F5E9:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F5EEu);
    reinterpret_cast<GameUiWindow*>(cpu->esi)->textColor = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F5F9u);
    reinterpret_cast<GameUiWindow*>(cpu->esi)->textStyle = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F604u);
    reinterpret_cast<GameUiWindow*>(cpu->esi)->font = cpu->eax;
    value_1 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F60Fu);
    cpu->eax = (uint32_t)(int32_t)std::trunc(value_1); 
    reinterpret_cast<GameUiWindow*>(cpu->esi)->fontScale = cpu->eax;
label_0003F61A:
    if (g_sfera_mbc_runtime->argument_count != 9u) goto label_0003F628;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_RVA(0x3F628u);
label_0003F628:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003F59E;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
    cpu->eax = WorldGuiControls::createText(static_cast<std::int32_t>(cpu->ecx), static_cast<std::int32_t>(cpu->edx), reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)), *reinterpret_cast<const std::uint32_t*>(cpu->esp + 4u)); cpu->esp += 8u;
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_0003F687;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
label_0003F687:
    cpu->ecx = cpu->esi;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F68Eu);
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->edx = 4u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    g_sfera_mbc_runtime->active_process->registerResource(cpu->ecx, cpu->edx); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F6B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F6B6u);
    cpu->esi = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_0003F6DA;
    if ((int32_t)cpu->esi < 0) goto label_0003F6CC;
    cpu->ecx = cpu->esi;
    WorldGuiControls::destroyText(cpu->ecx);
    label_0003F6CC:
    lift_push32(cpu, 0u);
    cpu->edx = 4u;
    cpu->ecx = cpu->esi;
    { auto* process = reinterpret_cast<SferaMbcProcessRecord*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)); (process != nullptr ? process : g_sfera_mbc_runtime->active_process)->unregisterResource(cpu->ecx, cpu->edx); } cpu->esp += 4u; cpu->eip = LIFT_CODE_TOKEN_RVA(0x3F6DAu);
    label_0003F6DA:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F6E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F6E7u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F6EEu);
    cpu->edi = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->argument_count) != 3u) goto label_0003F714;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F6FEu);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003F711;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    WorldGuiControls::setAppearance(cpu->ecx, *reinterpret_cast<const std::uint32_t*>(cpu->esp), cpu->edx); cpu->esp += 4u;
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_interface_runtime.window_handle_table.data));
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
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_interface_runtime.window_handle_table.data));
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    *(uint32_t*)(cpu->edx + 0x28u) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0xFFu;
    cpu->esi = 0u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F742u);
    cpu->ebx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F74Du);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->argument_count) != 2u) goto label_0003F770;
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->ebx;
    WorldGuiControls::setAppearance(cpu->ecx, cpu->edx);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003F770:
    lift_push32(cpu, cpu->ebp);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F776u);
    cpu->ebx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F77Du);
    cpu->ebp = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F784u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F78Du);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if (((uint32_t)(g_sfera_mbc_runtime->argument_count) == 6u) || ((int32_t)((uint32_t)(g_sfera_mbc_runtime->argument_count)) < (int32_t)(6u))) goto label_0003F7A1;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F79Fu);
    cpu->edi = cpu->eax;
    label_0003F7A1:
    if ((int32_t)g_sfera_mbc_runtime->argument_count <= (int32_t)7u) goto label_0003F7B1;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F7AFu);
    cpu->esi = cpu->eax;
    label_0003F7B1:
    if ((int32_t)g_sfera_mbc_runtime->argument_count <= (int32_t)8u) goto label_0003F7BF;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_RVA(0x3F7BFu);
    label_0003F7BF:
    if ((int32_t)g_sfera_mbc_runtime->argument_count <= (int32_t)9u) goto label_0003F7D2;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F7CDu);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_RVA(0x3F7D2u);
    label_0003F7D2:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0003F831;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->ebx;
    cpu->eax = WorldGuiControls::createSprite(static_cast<std::int32_t>(cpu->ecx), static_cast<std::int32_t>(cpu->edx), *reinterpret_cast<const std::int32_t*>(cpu->esp), *reinterpret_cast<const std::int32_t*>(cpu->esp + 4u), reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp + 8u)), *reinterpret_cast<const std::uint32_t*>(cpu->esp + 12u), *reinterpret_cast<const std::uint32_t*>(cpu->esp + 16u)); cpu->esp += 24u;
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_0003F817;
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->ecx = (uintptr_t)"Error creating sprite";
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->reportError(reinterpret_cast<const char*>(cpu->ecx))); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003F817:
    cpu->ecx = cpu->esi;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F81Eu);
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    cpu->edx = 5u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    g_sfera_mbc_runtime->active_process->registerResource(cpu->ecx, cpu->edx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003F831:
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F840(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F846u);
    cpu->esi = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_0003F86A;
    if ((int32_t)cpu->esi < 0) goto label_0003F85C;
    cpu->ecx = cpu->esi;
    WorldGuiControls::destroySprite(cpu->ecx);
    label_0003F85C:
    lift_push32(cpu, 0u);
    cpu->edx = 5u;
    cpu->ecx = cpu->esi;
    { auto* process = reinterpret_cast<SferaMbcProcessRecord*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)); (process != nullptr ? process : g_sfera_mbc_runtime->active_process)->unregisterResource(cpu->ecx, cpu->edx); } cpu->esp += 4u; cpu->eip = LIFT_CODE_TOKEN_RVA(0x3F86Au);
    label_0003F86A:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F870(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F87Au);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F881u);
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
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F8B4u);
    cpu->ebx = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_0003F9CF;
    if (g_sfera_mbc_runtime->argument_count != 3u) goto label_0003F908;
    if (cpu->ebp == 1u) goto label_0003F8DF;
    if (cpu->ebp == 2u) goto label_0003F8DF;
    if (cpu->ebp != 3u) goto label_0003F9C1;
    label_0003F8DF:
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003F908:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F90Du);
    cpu->ebp = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->argument_count) != 4u) goto label_0003F945;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003F945:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F94Au);
    cpu->ecx = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->eax != 5u) goto label_0003F98B;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003F98B:
    if (cpu->eax != 6u) goto label_0003F9C1;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43F995u);
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003F9CF:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0043F9E0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    sub_pred[0] = (int32_t)((uint32_t)(g_sfera_mbc_runtime->argument_count)) < (int32_t)(2u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if (!sub_pred[0]) goto label_0003FA04;
    cpu->ecx = (uintptr_t)"Wrong number of parameters: ffsprintf";
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->reportError(reinterpret_cast<const char*>(cpu->ecx))); cpu->eip = LIFT_CODE_TOKEN_RVA(0x3FA04u);
    label_0003FA04:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43FA09u);
    cpu->edi = cpu->eax;
    cpu->edi += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43FA16u);
    cpu->ebx = cpu->eax;
    cpu->ebx += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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

__declspec(noinline) void sfera_sub_0043FAE0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x18u;
    sub_pred[0] = (uint32_t)(g_sfera_mbc_runtime->argument_count) == 1u;
    lift_push32(cpu, cpu->esi);
    if (!sub_pred[0]) goto label_0003FBB8;
    cpu->eax = g_sfera_mbc_runtime->execution_context_depth;
    if ((int32_t)cpu->eax <= 0) goto label_0003FB21;
    cpu->ecx = g_sfera_mbc_runtime->program_index;
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->program_table_base));
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xA4u);
    if (*(uint8_t*)(cpu->ecx + cpu->edx + 0x84u) > 0u) goto label_0003FB21;
    cpu->eax <<= 5u;
    cpu->esi = g_sfera_mbc_runtime->execution_context_stack[g_sfera_mbc_runtime->execution_context_depth - 1u].process_id;
    goto label_0003FB24;
    label_0003FB21:
    cpu->esi |= 0xFFFFFFFFu;
    label_0003FB24:
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *reinterpret_cast<const std::uint32_t*>(cpu->esp); *reinterpret_cast<SferaSliceReference32*>(cpu->eax) = g_sfera_mbc_runtime->nextSlice(); cpu->esp += 4u; cpu->eip = LIFT_CODE_TOKEN_VA(0x43FB2Fu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_0003FC7C;
    if (cpu->esi > 0xFFFFu) goto label_0003FBAB;
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if (*(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id)) != cpu->esi) goto label_0003FBAB;
    if ((int32_t)*(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index)) < (int32_t)0u) goto label_0003FBAB;
    if (cpu->esi == 0xFFFFFFFFu) goto label_0003FBAB;
    cpu->eax = *(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_memory_base));
    cpu->esi = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax -= cpu->esi;
    if (cpu->ecx==0u) goto label_0003FB86;
    cpu->ecx += cpu->eax;
    if (cpu->edx==0u) goto label_0003FB86;
    cpu->edx += cpu->eax;
    cpu->edi += cpu->eax;
    label_0003FB86:
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    cpu->eax <<= 5u;
    cpu->eax = *(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.source.base));
    *(uint32_t*)(cpu->eax + cpu->esi) = cpu->ecx;
    *(uint32_t*)(cpu->eax + cpu->esi + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + cpu->esi + 8u) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003FBAB:
    cpu->edi = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003FBB8:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43FBBDu);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->esi = cpu->eax;
    cpu->eax = *reinterpret_cast<const std::uint32_t*>(cpu->esp); *reinterpret_cast<SferaSliceReference32*>(cpu->eax) = g_sfera_mbc_runtime->nextSlice(); cpu->esp += 4u; cpu->eip = LIFT_CODE_TOKEN_VA(0x43FBC9u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_0003FC7D;
    if (cpu->esi > 0xFFFFu) goto label_0003FC47;
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if (*(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id)) != cpu->esi) goto label_0003FC47;
    if ((int32_t)*(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index)) < (int32_t)0u) goto label_0003FC47;
    if (cpu->esi == 0xFFFFFFFFu) goto label_0003FC47;
    cpu->eax = *(uint32_t*)(cpu->eax + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_memory_base));
    cpu->eax -= static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
    g_sfera_mbc_runtime->pushSlice(*reinterpret_cast<const SferaSliceReference32*>(cpu->ecx), cpu->edx); cpu->eip = LIFT_CODE_TOKEN_VA(0x43FC42u);
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
    g_sfera_mbc_runtime->pushSlice(*reinterpret_cast<const SferaSliceReference32*>(cpu->ecx), cpu->edx); cpu->eip = LIFT_CODE_TOKEN_VA(0x43FC77u);
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
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43FC98u);
    cpu->ebx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x43FC9Fu);
    cpu->esi = cpu->eax;
    if (*(uint32_t*)(cpu->esi) != 0u) goto label_0003FCBC;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffmempcpy\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FCB5u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x43FCB5u));
    cpu->esp += 8u;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003FCBC:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43FCC3u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x43FCCAu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43FCD3u);
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
    reinterpret_cast<SferaSliceReference32*>(cpu->ecx)->diagnoseRange(cpu->edx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x3FCFEu);
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
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
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
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
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
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43FDB7u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x43FDBEu);
    cpu->edi = cpu->eax;
    if (*(uint32_t*)(cpu->edi) != 0u) goto label_0003FDDA;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffmempcpy\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43FDD4u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x43FDD4u));
    cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003FDDA:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x43FDE1u);
    cpu->ebx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x43FDE8u);
    cpu->ebp = cpu->eax;
    cpu->eax = 0u;
    if (g_sfera_mbc_runtime->argument_count != 5u) goto label_0003FDFA;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_RVA(0x3FDFAu);
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
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
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
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003FE7A:
    cpu->edx = *(uint32_t*)(cpu->edx + ((uintptr_t)&g_sfera_mbc_runtime->processes[0].process_memory_base));
    cpu->edx += *(uint32_t*)(cpu->ebp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    cpu->eax = SferaStringLookupRuntime::copyString(reinterpret_cast<char*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::int32_t*>(cpu->esp)); cpu->esp += 4u; cpu->eip = LIFT_CODE_TOKEN_VA(0x43FE8Bu);
    cpu->esi = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    cpu->eax = reinterpret_cast<const SferaSliceReference32*>(cpu->ecx)->contains(*reinterpret_cast<const std::uint32_t*>(cpu->esp), true); cpu->esp += 4u; cpu->eip = LIFT_CODE_TOKEN_VA(0x43FE95u);
    if ((cpu->eax & 0xFFu) != 0u) goto label_0003FEA6;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->ecx = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    cpu->edx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    reinterpret_cast<SferaSliceReference32*>(cpu->ecx)->diagnoseRange(cpu->edx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003FEA6:
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}





__declspec(noinline) void sfera_sub_00440090(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    sub_pred[0] = (uint32_t)(g_sfera_mbc_runtime->argument_count) == 2u; sub_pred[1] = (int32_t)((uint32_t)(g_sfera_mbc_runtime->argument_count)) < (int32_t)(2u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((sub_pred[0]) || (sub_pred[1])) goto label_000400BB;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4400A0u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4400A7u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4400AEu);
    if (cpu->eax != 0u) goto label_000400DB;
    cpu->ecx = cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SphereRender::ModelPose::animation(cpu->ecx)));
    goto label_000400E2;
    label_000400BB:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4400C0u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4400C7u);
    cpu->edi = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_000400E8;
    cpu->ecx = cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SphereRender::ModelPose::animation(cpu->ecx)));
    goto label_000400E2;
    label_000400DB:
    cpu->ecx = cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SphereRender::ModelPose::secondaryAnimation(cpu->ecx)));
    label_000400E2:
    if (cpu->eax == 0u) goto label_000400E8;
    *(uint32_t*)(cpu->eax) = cpu->edi;
    label_000400E8:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004400F0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    sub_pred[0] = (uint32_t)(g_sfera_mbc_runtime->argument_count) == 2u; sub_pred[1] = (int32_t)((uint32_t)(g_sfera_mbc_runtime->argument_count)) < (int32_t)(2u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((sub_pred[0]) || (sub_pred[1])) goto label_0004011B;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440100u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440107u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x44010Eu);
    if (cpu->eax != 0u) goto label_0004013B;
    cpu->ecx = cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SphereRender::ModelPose::frame(cpu->ecx)));
    goto label_00040142;
    label_0004011B:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440120u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440127u);
    cpu->edi = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00040148;
    cpu->ecx = cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SphereRender::ModelPose::frame(cpu->ecx)));
    goto label_00040142;
    label_0004013B:
    cpu->ecx = cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SphereRender::ModelPose::secondaryFrame(cpu->ecx)));
    label_00040142:
    if (cpu->eax == 0u) goto label_00040148;
    *(uint32_t*)(cpu->eax) = cpu->edi;
    label_00040148:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00440150(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440156u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x44015Du);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00040177;
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(SphereRender::ModelPose::animationLength(cpu->ecx, static_cast<std::int32_t>(cpu->edx)));
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040177:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00440180(LiftCpu* cpu, uint32_t stop_address) { double value_0;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440187u);
    cpu->esi = cpu->eax;
    value_0 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_VA(0x44018Eu);
    *(float*)(cpu->esp + 4u) = value_0; 
     if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_000401AC;
    cpu->ecx = cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SphereRender::ModelPose::interpolation(cpu->ecx)));
    if (cpu->eax == 0u) goto label_000401AC;
    *(float*)(cpu->eax) = (double)*(float*)(cpu->esp + 4u);
label_000401AC:
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004401B0(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2;
 double x87_p0;
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4401B9u);
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi < 0) goto label_0004024F;
    value_1 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_VA(0x4401C8u);
    *(float*)(cpu->esp + 8u) = value_1; 
     value_2 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_VA(0x4401D1u);
    *(float*)(cpu->esp + 4u) = value_2; 
    cpu->ecx = cpu->esi;
     cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_world_objects.object(cpu->ecx, "GetObjectPointer")));
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SphereRender::CharacterModels::checkedExtended(reinterpret_cast<WorldObject*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp))));  cpu->esp += 4u;
    x87_p0 = (double)*(float*)(cpu->esp + 8u);
    cpu->esi = cpu->eax;
    *(float*)(cpu->esi + 0x27Cu) = x87_p0; 
    if (g_sfera_mbc_runtime->argument_count != 4u) goto label_00040245;
    value_0 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_VA(0x440228u);
    *(float*)(cpu->esp + 8u) = value_0; 
    *(float*)(cpu->esi + 0x280u) = (double)*(float*)(cpu->esp + 4u);
    *(float*)(cpu->esi + 0x284u) = (double)*(float*)(cpu->esp + 8u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
     cpu->esp += 4u; cpu->eip = stop_address; return;
label_00040245:
    *(float*)(cpu->esi + 0x284u) = (double)*(float*)(cpu->esp + 4u);
label_0004024F:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00440260(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2;
 bool sub_pred[1];
    lift_push32(cpu, cpu->ecx);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440266u);
    if ((int32_t)cpu->eax < 0) goto label_000402CC;
    cpu->ecx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_world_objects.object(cpu->ecx, "GetObjectPointer")));
    g_sfera_inter_scalar_runtime.mode_03 = cpu->eax;
    if (cpu->eax != 0u) goto label_00040286;
    g_sfera_mbc_runtime->active_tag = 0xFFFFFFFFu;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
label_00040286:
    if (g_sfera_mbc_runtime->argument_count != 3u) goto label_0004029D;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440294u);
    cpu->ecx = cpu->eax;
    value_1 = g_sfera_motion.responseValue(static_cast<std::int32_t>(cpu->ecx));
    value_0 = value_1; goto label_000402A2;
label_0004029D:
    value_2 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_RVA(0x402A2u); value_0 = value_2;
label_000402A2:
    sub_pred[0] = (uint32_t)(g_sfera_mbc_runtime->execution_failed) == 0u;
    *(float*)(cpu->esp) = value_0; 
     if (!sub_pred[0]) goto label_000402CC;
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    lift_push32(cpu, 0x2411u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SphereRender::CharacterModels::checkedExtended(reinterpret_cast<WorldObject*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp))));  cpu->esp += 4u;
    *(float*)(cpu->eax + 0x28Cu) = (double)*(float*)(cpu->esp);
label_000402CC:
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004402D0(LiftCpu* cpu, uint32_t stop_address) { double value_0;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4402D7u);
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi < 0) goto label_00040327;
    value_0 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_VA(0x4402E2u);
    *(float*)(cpu->esp + 4u) = value_0; 
    cpu->ecx = cpu->esi;
     cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_world_objects.object(cpu->ecx, "GetObjectPointer")));
    g_sfera_inter_scalar_runtime.mode_03 = cpu->eax;
    if (cpu->eax != 0u) goto label_00040303;
    g_sfera_mbc_runtime->active_tag = 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
label_00040303:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00040327;
    lift_push32(cpu, 0x241Cu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SphereRender::CharacterModels::checkedExtended(reinterpret_cast<WorldObject*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp))));  cpu->esp += 4u;
    *(float*)(cpu->eax + 0x294u) = (double)*(float*)(cpu->esp + 4u);
label_00040327:
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00440330(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440335u);
    if ((int32_t)cpu->eax >= 0) goto label_00040340;
    label_00040339:
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040340:
    cpu->ecx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_world_objects.object(cpu->ecx, "GetObjectPointer")));
    g_sfera_inter_scalar_runtime.mode_03 = cpu->eax;
    if (cpu->eax != 0u) goto label_0004035B;
    g_sfera_mbc_runtime->active_tag = 0xFFFFFFFFu;
    label_0004035A:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004035B:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0004035A;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440369u);
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    if (cpu->eax != 0xFFFFFFFFu) goto label_00040395;
    lift_push32(cpu, 0x2428u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SphereRender::CharacterModels::checkedExtended(reinterpret_cast<WorldObject*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp))));  cpu->esp += 4u;
    cpu->ecx = 1u;
    if (*(uint32_t*)(cpu->eax + 0x278u) != cpu->ecx) goto label_00040339;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040395:
    lift_push32(cpu, 0x242Cu);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SphereRender::CharacterModels::checkedExtended(reinterpret_cast<WorldObject*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp))));  cpu->esp += 4u;
    *(uint32_t*)(cpu->eax + 0x278u) = 1u;
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004403B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4403B6u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4403BDu);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00040404;
    if (cpu->esi != 0xFFFFFFFEu) goto label_000403DB;
    if (cpu->eax != cpu->esi) goto label_000403EC;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.mouse.wheel;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000403DB:
    if (cpu->esi != 0xFFFFFFFFu) goto label_000403EC;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.mouse.dx;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000403EC:
    cpu->esi = lift_pop32(cpu);
    if (cpu->eax != 0xFFFFFFFFu) goto label_000403FD;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.mouse.dy;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000403FD:
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040404:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00440410(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440416u);
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->esi < 0) goto label_000404D3;
    cpu->ecx = cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_world_objects.object(cpu->ecx, "GetObjectPointer")));
    g_sfera_inter_scalar_runtime.mode_03 = cpu->eax;
    if (cpu->eax!=0u) goto label_0004043C;
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
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x44046Fu);
    cpu->ebx = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_000404D2;
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x2459u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SphereRender::CharacterModels::checkedExtended(reinterpret_cast<WorldObject*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp))));  cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    cpu->edi = cpu->eax;
    g_sfera_world_objects.recalculateBasis(cpu->ecx);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->esi = cpu->eax + cpu->ebx;
    if (cpu->esi != cpu->eax) goto label_000404B7;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffg_norm\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4404B4u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4404B4u));
    cpu->esp += 8u;
    label_000404B7:
    *(float*)(cpu->esi) = (double)*(float*)(cpu->edi + 0x14Cu);
    *(float*)(cpu->esi + 4u) = (double)*(float*)(cpu->edi + 0x150u);
    x87_v0 = (double)*(float*)(cpu->edi + 0x154u);
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->esi + 8u) = x87_v0; 
    label_000404D2:
    cpu->ebx = lift_pop32(cpu);
    label_000404D3:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004404E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4404E5u);
    if ((int32_t)cpu->eax < 0) goto label_00040570;
    cpu->ecx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_world_objects.object(cpu->ecx, "GetObjectPointer")));
    g_sfera_inter_scalar_runtime.mode_03 = cpu->eax;
    if (cpu->eax != 0u) goto label_00040508;
    g_sfera_mbc_runtime->active_tag = 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040508:
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x44050Eu);
    cpu->esi = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_0004056F;
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
    reinterpret_cast<SferaSliceReference32*>(cpu->ecx)->diagnoseRange(cpu->edx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x40544u);
    label_00040544:
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    cpu->eax += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(float*)(cpu->eax) = (double)*(float*)(cpu->ecx + 8u);
    cpu->edx = g_sfera_inter_scalar_runtime.mode_03;
    *(float*)(cpu->eax + 4u) = (double)*(float*)(cpu->edx + 0xCu);
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    *(float*)(cpu->eax + 8u) = (double)*(float*)(cpu->ecx + 0x10u);
    label_0004056F:
    cpu->esi = lift_pop32(cpu);
    label_00040570:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00440580(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440585u);
    if ((int32_t)cpu->eax < 0) goto label_000405F5;
    cpu->ecx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_world_objects.object(cpu->ecx, "GetObjectPointer")));
    g_sfera_inter_scalar_runtime.mode_03 = cpu->eax;
    if (cpu->eax != 0u) goto label_000405A4;
    g_sfera_mbc_runtime->active_tag = 0xFFFFFFFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000405A4:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4405A9u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_000405F5;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx + cpu->eax;
    if (cpu->esi != cpu->ecx) goto label_000405D2;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffg_abg\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4405CFu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4405CFu));
    cpu->esp += 8u;
    label_000405D2:
    cpu->eax = g_sfera_inter_scalar_runtime.mode_03;
    *(float*)(cpu->esi) = (double)*(float*)(cpu->eax + 0x14u);
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    *(float*)(cpu->esi + 4u) = (double)*(float*)(cpu->ecx + 0x18u);
    cpu->edx = g_sfera_inter_scalar_runtime.mode_03;
    *(float*)(cpu->esi + 8u) = (double)*(float*)(cpu->edx + 0x1Cu);
    cpu->esi = lift_pop32(cpu);
    label_000405F5:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00440600(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 8u;
    sub_pred[0] = (int32_t)((uint32_t)(g_sfera_mbc_runtime->argument_count)) < (int32_t)(3u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if (!sub_pred[0]) goto label_00040626;
    cpu->ecx = (uintptr_t)"Wrong number of parameters: ffsnprintf";
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->reportError(reinterpret_cast<const char*>(cpu->ecx))); cpu->eip = LIFT_CODE_TOKEN_RVA(0x40626u);
    label_00040626:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x44062Bu);
    cpu->esi = cpu->eax;
    cpu->esi += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440638u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440640u);
    cpu->ebx = cpu->eax;
    cpu->ebx += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
__declspec(noinline) void sfera_sub_004406A0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x14u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4406B3u);
    if (cpu->eax != 0u) goto label_00040740;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4406C2u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4406C9u);
    cpu->esi = cpu->eax;
    if (cpu->edi == 0u) goto label_000406D3;
    if (cpu->esi != 0u) goto label_000406E5;
    label_000406D3:
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffeditor, EDSC_GETCLICKPOINT\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4406E2u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4406E2u));
    cpu->esp += 8u;
    label_000406E5:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0004073E;
    x87_v0 = 0.0;
    cpu->edx = cpu->esp + 0xCu;
    *(float*)(cpu->esp + 0xCu) = x87_v0;
    cpu->ecx = cpu->esp + 8u;
    *(float*)(cpu->esp + 0x10u) = x87_v0;
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    cpu->eax = static_cast<std::uint32_t>(g_sfera_motion.pick(reinterpret_cast<float*>(cpu->ecx), reinterpret_cast<SferaVec3F*>(cpu->edx)));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(uint32_t*)(cpu->edx + cpu->esi) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->edx + cpu->esi + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->edx + cpu->esi + 8u) = cpu->ecx;
    if ((int32_t)cpu->eax < 0) goto label_00040737;
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(float*)(cpu->edx + cpu->edi) = x87_v0; 
    label_00040737:
    cpu->ecx = cpu->eax;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x4073Eu);
    label_0004073E:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_00040740:
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00440750(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x30u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440763u);
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
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440786u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x44078Du);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440794u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x44079Du);
    cpu->ebx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4407A4u);
    cpu->ebp = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4407ABu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    cpu->eax = GameInterface::createWindow(static_cast<std::int32_t>(cpu->ecx), static_cast<std::int32_t>(cpu->edx), *reinterpret_cast<const std::int32_t*>(cpu->esp), *reinterpret_cast<const std::int32_t*>(cpu->esp + 4u), *reinterpret_cast<const std::uint32_t*>(cpu->esp + 8u), *reinterpret_cast<const std::uint32_t*>(cpu->esp + 12u)); cpu->esp += 16u;
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x4407D8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if ((int32_t)cpu->ecx >= 0) goto label_000407FD;
    cpu->ecx = (uintptr_t)"Error creating window";
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->reportError(reinterpret_cast<const char*>(cpu->ecx))); cpu->eip = LIFT_CODE_TOKEN_VA(0x4407EAu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000407FD:
    cpu->edx = 6u;
    g_sfera_mbc_runtime->active_process->registerResource(cpu->ecx, cpu->edx); cpu->eip = LIFT_CODE_TOKEN_VA(0x440807u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004081A:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x44081Fu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00041B5B;
    cpu->ecx = cpu->eax;
    GameInterface::destroyWindow(cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, 0u);
    cpu->edx = 6u;
    { auto* process = reinterpret_cast<SferaMbcProcessRecord*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)); (process != nullptr ? process : g_sfera_mbc_runtime->active_process)->unregisterResource(cpu->ecx, cpu->edx); } cpu->esp += 4u; cpu->eip = LIFT_CODE_TOKEN_VA(0x440847u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004085A:
    cpu->ecx = g_sfera_graphics_runtime.display_width;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x440865u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040878:
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x440883u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040896:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x44089Bu);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4408A2u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4408A9u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00041B5B;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(GameInterface::textHeight(cpu->ecx, cpu->edx, *reinterpret_cast<const std::uint32_t*>(cpu->esp)));  cpu->esp += 4u;
    cpu->ecx = cpu->eax;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x4408CBu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000408DE:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4408E3u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4408EAu);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(GameInterface::fontHeight(cpu->ecx, cpu->edx));
    cpu->ecx = cpu->eax;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x440907u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004091A:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x44091Fu);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440926u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x44092Du);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00041B5B;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(GameInterface::lineOffset(cpu->ecx, cpu->edx, *reinterpret_cast<const std::uint32_t*>(cpu->esp)));  cpu->esp += 4u;
    cpu->ecx = cpu->eax;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x44094Fu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040962:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440967u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440970u);
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_00040988;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, W_EVENT, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440985u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x440985u));
    cpu->esp += 8u;
    label_00040988:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x44098Du);
    cpu->edi = cpu->eax;
    if (cpu->edi != 0u) goto label_000409A5;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, W_EVENT, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4409A2u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4409A2u));
    cpu->esp += 8u;
    label_000409A5:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    {
        auto* window = GameInterface::window(*reinterpret_cast<const std::uint32_t*>(cpu->esp + 0x10u), "GetWindowPointer");
        std::uint32_t control = UINT32_MAX, message = 0;
        if (window != nullptr) window->takeInput(control, message);
        *reinterpret_cast<std::uint32_t*>(static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base)) + cpu->esi) = control;
        *reinterpret_cast<std::uint32_t*>(static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base)) + cpu->edi) = message <= 2u ? message : 0u;
    }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040A8B:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440A90u);
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_00040AA8;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, W_WINCON, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440AA5u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x440AA5u));
    cpu->esp += 8u;
    label_00040AA8:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440AADu);
    cpu->edi = cpu->eax;
    if (cpu->edi != 0u) goto label_00040AC5;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, W_WINCON, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440AC2u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x440AC2u));
    cpu->esp += 8u;
    label_00040AC5:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->edx = cpu->esp + 0x14u;
    cpu->ecx = cpu->esp + 0x10u;
    { const auto hit = GameInterface::hitTest(CCursorManager::instance().position()); *reinterpret_cast<std::uint32_t*>(cpu->ecx) = hit.window; *reinterpret_cast<std::uint32_t*>(cpu->edx) = hit.control; }
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax + cpu->esi) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(uint32_t*)(cpu->eax + cpu->edi) = cpu->edx;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040B0A:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440B0Fu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440B18u);
    cpu->esi = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(GameInterface::window(cpu->ecx, "GetWindowPointer")));
    if (cpu->eax == 0u) goto label_00041B5B;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040B4D:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440B52u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440B5Bu);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440B62u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440B69u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440B72u);
    cpu->ebx = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(GameInterface::window(cpu->ecx, "GetWindowPointer")));
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
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x440BD2u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040BE5:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440BEAu);
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_00040C02;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, W_TEXTSIZE, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440BFFu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x440BFFu));
    cpu->esp += 8u;
    label_00040C02:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440C07u);
    cpu->edi = cpu->eax;
    if (cpu->edi != 0u) goto label_00040C1F;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, W_TEXTSIZE, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440C1Cu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x440C1Cu));
    cpu->esp += 8u;
    label_00040C1F:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx = g_sfera_recovered_static_runtime.text_size_height;
    *(uint32_t*)(cpu->eax + cpu->esi) = cpu->ecx;
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax = g_sfera_input_device_runtime.process_value;
    *(uint32_t*)(cpu->edx + cpu->edi) = cpu->eax;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040C5B:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440C60u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440C67u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    if ((int32_t)cpu->esi >= 0) goto label_00040C7E;
    cpu->esi += 0x100u;
    label_00040C7E:
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(GameInterface::glyphWidth(cpu->ecx, cpu->edx));
    cpu->ecx = cpu->eax;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x440C8Eu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040CA1:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440CA6u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440CAFu);
    cpu->esi = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(GameInterface::window(cpu->ecx, "GetWindowPointer")));
    if (cpu->eax == 0u) goto label_00041B5B;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040CE5:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440CEAu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440CF3u);
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_00040D0B;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, W_GETCURXY, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440D08u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x440D08u));
    cpu->esp += 8u;
    label_00040D0B:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440D10u);
    cpu->edi = cpu->eax;
    if (cpu->edi != 0u) goto label_00040D28;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, W_GETCURXY, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x440D25u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x440D25u));
    cpu->esp += 8u;
    label_00040D28:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx = cpu->eax + cpu->edi;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = cpu->eax + cpu->esi;
    { const auto* owner = GameInterface::window(cpu->ecx); const auto point = owner ? owner->contentPosition(CCursorManager::instance().position()) : SferaCursorPosition{-1, -1}; *reinterpret_cast<std::int32_t*>(cpu->edx) = point.x; *reinterpret_cast<std::int32_t*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)) = point.y; } cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040D5D:
    if ((int32_t)g_sfera_mbc_runtime->argument_count <= (int32_t)1u) goto label_00040DB2;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440D6Bu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00041B5B;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(CCursorManager::instance().activeCursor()));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint32_t*)(cpu->esp + 0x10u) != 0u);
    cpu->ecx = cpu->ecx & 0xFFu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->setSystemCursorVisible(*(uint8_t*)(cpu->esp) != 0u); cpu->esp += 4u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    g_sfera_recovered_static_runtime.interaction_enabled = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040DB2:
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(CCursorManager::instance().activeCursor()));
    cpu->ecx = cpu->eax;
    cpu->eax = reinterpret_cast<CCursor*>(cpu->ecx)->isSystemCursorVisible() ? 1u : 0u;
    cpu->ecx = cpu->eax & 0xFFu;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x440DC8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040DDB:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440DE0u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00041B5B;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(CCursorManager::instance().activeCursor()));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->setCursorKind(*(uint32_t*)(cpu->esp)); cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040E17:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440E1Cu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (((uint32_t)(g_sfera_mbc_runtime->argument_count) == 2u) || ((int32_t)((uint32_t)(g_sfera_mbc_runtime->argument_count)) < (int32_t)(2u))) goto label_00040E37;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440E2Eu);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440E35u);
    goto label_00040E3F;
    label_00040E37:
    cpu->esi = 8u;
    cpu->eax = cpu->esi + 0xFFFFFFF0u;
    label_00040E3F:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esi;
    g_sfera_interface.setCursorKind(cpu->ecx, static_cast<std::int32_t>(cpu->edx), static_cast<std::int32_t>(*reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040E6B:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440E70u);
    cpu->ecx = g_sfera_mbc_runtime->argument_count;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)cpu->ecx <= (int32_t)3u) goto label_00040E99;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440E84u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440E8Bu);
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
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440EB5u);
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    label_00040EBB:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00041B5B;
    if (cpu->eax == 0u) goto label_00040F19;
    if ((int32_t)cpu->ecx >= 0) goto label_00040EE1;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    lift_push32(cpu, cpu->edi);
    cpu->ecx += cpu->eax;
    cpu->edx = cpu->esi;
    goto label_00040F1F;
    label_00040EE1:
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    lift_push32(cpu, 0x20u); lift_push32(cpu, 8u);
    cpu->edx += cpu->eax;
    cpu->ecx = 2u;
    if (auto* cursor = g_sfera_interface.cursor.get()) cursor->setImage(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), static_cast<std::int32_t>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)), static_cast<std::int32_t>(*reinterpret_cast<const std::uint32_t*>(cpu->esp + 4u))); cpu->esp += 8u;
    cpu->edx = 0x10u;
    lift_push32(cpu, 0x10u);
    cpu->ecx = cpu->edx + 0xFFFFFFF2u;
    if (auto* cursor = g_sfera_interface.cursor.get()) cursor->setImageSize(cpu->ecx, cpu->edx, *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040F19:
    cpu->edx = 0u;
    lift_push32(cpu, 0u);
    cpu->ecx = 0u;
    label_00040F1F:
    g_sfera_interface.setCursorImage(reinterpret_cast<const char*>(cpu->ecx), static_cast<std::int32_t>(cpu->edx), static_cast<std::int32_t>(*reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = 0u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edx + 2u;
    if (auto* cursor = g_sfera_interface.cursor.get()) cursor->setImage(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), static_cast<std::int32_t>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)), static_cast<std::int32_t>(*reinterpret_cast<const std::uint32_t*>(cpu->esp + 4u))); cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040F45:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440F4Au);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440F53u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (((uint32_t)(g_sfera_mbc_runtime->argument_count) == 3u) || ((int32_t)((uint32_t)(g_sfera_mbc_runtime->argument_count)) < (int32_t)(3u))) goto label_00040F72;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440F65u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440F6Cu);
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
    cpu->edx += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    if (auto* cursor = g_sfera_interface.cursor.get()) cursor->setText(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), static_cast<std::int32_t>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)), static_cast<std::int32_t>(*reinterpret_cast<const std::uint32_t*>(cpu->esp + 4u)), 1u, UINT32_MAX); cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00040FC8:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_interface.initialized);
    if ((cpu->eax & 0xFFu) == 0u) goto label_00041A9F;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440FDAu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440FE3u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440FEAu);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x440FF1u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00041B5B;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->esi;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_interface.openWindow(reinterpret_cast<const char*>(cpu->ecx), static_cast<std::int32_t>(cpu->edx), static_cast<std::int32_t>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)), *reinterpret_cast<const std::uint32_t*>(cpu->esp + 4u)))); cpu->esp += 8u;
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x441020u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx == 0u) goto label_00041B5B;
    cpu->edx = 7u;
    g_sfera_mbc_runtime->active_process->registerResource(cpu->ecx, cpu->edx); cpu->eip = LIFT_CODE_TOKEN_VA(0x441036u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041049:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x44104Eu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00041B5B;
    cpu->edx = 1u;
    cpu->ecx = cpu->eax;
    g_sfera_interface.closeWindow(reinterpret_cast<SphereUI::Window*>(cpu->ecx), cpu->edx != 0u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, 0u);
    cpu->edx = 7u;
    { auto* process = reinterpret_cast<SferaMbcProcessRecord*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)); (process != nullptr ? process : g_sfera_mbc_runtime->active_process)->unregisterResource(cpu->ecx, cpu->edx); } cpu->esp += 4u; cpu->eip = LIFT_CODE_TOKEN_VA(0x44107Bu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004108E:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441093u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (cpu->eax != 0u) goto label_000410AD;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, PEEK_MESSAGE, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4410AAu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4410AAu));
    cpu->esp += 8u;
    label_000410AD:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4410B2u);
    cpu->ebx = cpu->eax;
    if (cpu->ebx != 0u) goto label_000410CA;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, PEEK_MESSAGE, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4410C7u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4410C7u));
    cpu->esp += 8u;
    label_000410CA:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4410CFu);
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_000410E7;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, PEEK_MESSAGE, 3\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4410E4u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4410E4u));
    cpu->esp += 8u;
    label_000410E7:
    if ((int32_t)g_sfera_mbc_runtime->argument_count < (int32_t)5u) goto label_0004110F;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4410F5u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->eax != 0u) goto label_0004110F;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, PEEK_MESSAGE, 4\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44110Cu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44110Cu));
    cpu->esp += 8u;
    label_0004110F:
    cpu->ebp = 6u;
    if (g_sfera_mbc_runtime->argument_count != cpu->ebp) goto label_0004113B;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441121u);
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<SphereUI::Window*>(cpu->ecx) != nullptr && reinterpret_cast<SphereUI::Window*>(cpu->ecx)->pollEvent(*reinterpret_cast<SphereUI::WindowEvent*>(cpu->edx)));
    if (cpu->eax == 0u) goto label_00041A9F;
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->edx + cpu->ebx) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(uint32_t*)(cpu->edx + cpu->esi) = cpu->ecx;
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    if (cpu->eax != 5u) goto label_0004120C;
    if (*(uint32_t*)(cpu->esp + 0x28u) != 0xFA1u) goto label_000411DE;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax >>= 16u;
    *(uint32_t*)(cpu->ecx + cpu->ebx) = cpu->eax;
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->edx + cpu->esi) = cpu->eax;
    cpu->ecx = *(uint16_t*)(cpu->esp + 0x30u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(uint32_t*)(cpu->eax + cpu->edx) = cpu->ecx;
    cpu->ecx = 1u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x4411CBu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000411DE:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(uint32_t*)(cpu->edx + cpu->ecx) = 0xFFFFFFFFu;
    cpu->ecx = 1u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x4411F9u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004120C:
    if (cpu->eax != cpu->ebp) goto label_0004122D;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->eax + cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(uint32_t*)(cpu->ecx + cpu->edi) = cpu->eax;
    label_0004122D:
    cpu->ecx = 1u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x441237u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004124A:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x44124Fu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441258u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx += cpu->eax;
    if (auto* window = reinterpret_cast<SphereUI::Window*>(cpu->ecx)) window->setText(reinterpret_cast<const char*>(cpu->edx));
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x44127Du);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041290:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441295u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x44129Eu);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(reinterpret_cast<SphereUI::Window*>(cpu->ecx) != nullptr ? reinterpret_cast<SphereUI::Window*>(cpu->ecx)->controlAt(cpu->edx) : nullptr));
    cpu->ecx = cpu->eax;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x4412BDu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000412D0:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4412D5u);
    cpu->ebx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4412DCu);
    cpu->ebp = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4412E3u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4412EAu);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4412F1u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
    if (cpu->edx == 14u) { g_sfera_interface.showHelpPage(reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->eax = 1u; } else cpu->eax = static_cast<std::uint32_t>(g_sfera_interface.sendMessage(reinterpret_cast<SphereUI::Window*>(cpu->ecx), cpu->edx, *reinterpret_cast<const std::uint32_t*>(cpu->esp), *reinterpret_cast<const std::uint32_t*>(cpu->esp + 4u))); cpu->esp += 8u;
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x44132Au);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004133D:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441342u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x44134Bu);
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_00041363;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, GET_WINDOW_TEXT\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441360u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x441360u));
    cpu->esp += 8u;
    label_00041363:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441368u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    if ((int32_t)cpu->eax >= (int32_t)1u) goto label_0004137F;
    cpu->eax = 1u;
    label_0004137F:
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    --cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->edx + cpu->esi;
    { auto* window = reinterpret_cast<SphereUI::Window*>(cpu->ecx); const auto limit = *reinterpret_cast<const std::uint32_t*>(cpu->esp); if (window != nullptr && limit != 0u) { auto* destination = reinterpret_cast<char*>(cpu->edx); const auto count = std::min(window->text_length, limit); std::string_view(window->getText(), window->text_length).copy(destination, count); destination[count] = 0; } }; cpu->esp += 4u;
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x44139Au);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000413AD:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4413B2u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (cpu->eax != 0u) goto label_000413CC;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, GET_SYSTEM_MESSAGE\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4413C9u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4413C9u));
    cpu->esp += 8u;
    label_000413CC:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->ecx = cpu->esp + 0x20u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_interface.pollEvent(*reinterpret_cast<SphereUI::WindowEvent*>(cpu->ecx)));
    cpu->ecx = cpu->eax;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x4413E9u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + cpu->ecx) = cpu->edx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004140C:
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_interface.windowUnderCursor()));
    cpu->ecx = cpu->eax;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x441418u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004142B:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441430u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441439u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(reinterpret_cast<SphereUI::Window*>(cpu->ecx) != nullptr && reinterpret_cast<SphereUI::Window*>(cpu->ecx)->control_kind == 12u ? static_cast<SphereUI::ListItemCtrl*>(reinterpret_cast<SphereUI::Window*>(cpu->ecx))->itemAt(cpu->edx) : nullptr));
    cpu->ecx = cpu->eax;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x441458u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004146B:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_interface.savedPositionsSize());
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x44147Bu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004148E:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441493u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x44149Cu);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->edx = cpu->eax;
    g_sfera_interface.readSavedPositions(std::span<const std::byte>(reinterpret_cast<const std::byte*>(cpu->ecx), cpu->edx));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000414CD:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4414D2u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00041B5B;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx += cpu->eax;
    g_sfera_interface.writeSavedPositions(std::span<std::byte>(reinterpret_cast<std::byte*>(cpu->ecx), g_sfera_interface.savedPositionsSize()));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041503:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441508u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441511u);
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_00041529;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, GET_WINDOW_POS, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441526u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x441526u));
    cpu->esp += 8u;
    label_00041529:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x44152Eu);
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
    if (auto* window = reinterpret_cast<SphereUI::Window*>(cpu->ecx)) { *reinterpret_cast<std::int32_t*>(cpu->edx) = window->x; *reinterpret_cast<std::int32_t*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)) = window->y; }; cpu->esp += 4u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->eax + cpu->esi) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(uint32_t*)(cpu->eax + cpu->edi) = cpu->edx;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041590:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441595u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x44159Eu);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4415A5u);
    cpu->edi = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00041B5B;
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = cpu->esp + 0x1Cu;
    if (auto* window = reinterpret_cast<SphereUI::Window*>(cpu->ecx)) { *reinterpret_cast<std::int32_t*>(cpu->edx) = window->width; *reinterpret_cast<std::int32_t*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)) = window->height; }; cpu->esp += 4u;
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->edx + cpu->esi) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(uint32_t*)(cpu->edx + cpu->edi) = cpu->ecx;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000415F3:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4415F8u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441601u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0xFAu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(SphereUI::CDescriptionWindow::instance()));
    cpu->ecx = cpu->eax;
    reinterpret_cast<SphereUI::CDescriptionWindow*>(static_cast<std::uintptr_t>(cpu->ecx))->showDescription(reinterpret_cast<const char*>(static_cast<std::uintptr_t>(*reinterpret_cast<const std::uint32_t*>(cpu->esp))), *reinterpret_cast<const std::uint32_t*>(cpu->esp + 4u), *reinterpret_cast<const std::uint32_t*>(cpu->esp + 8u), *reinterpret_cast<const std::uint32_t*>(cpu->esp + 12u) != 0u);  cpu->esp += 16u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041641:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441646u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00041B5B;
    if (cpu->eax != 0u) goto label_00041675;
    cpu->ecx = 0u;
    g_sfera_interface.setTooltipText(reinterpret_cast<const char*>(cpu->ecx));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041675:
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx = cpu->ecx + cpu->eax;
    g_sfera_interface.setTooltipText(reinterpret_cast<const char*>(cpu->ecx));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041696:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19 == 0u) goto label_00041A9F;
    cpu->ecx = (uintptr_t)"options";
    if (((uint32_t)(g_sfera_mbc_runtime->argument_count) == 1u) || ((int32_t)((uint32_t)(g_sfera_mbc_runtime->argument_count)) < (int32_t)(1u))) goto label_000416DB;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_interface.findWindow(reinterpret_cast<const char*>(cpu->ecx))));
    if (cpu->eax == 0u) goto label_00041746;
    cpu->ecx = 1u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x4416C8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000416DB:
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_interface.findWindow(reinterpret_cast<const char*>(cpu->ecx))));
    if (cpu->eax != 0u) goto label_00041708;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    g_sfera_interface.showOptions((cpu->ecx & 255u) != 0u);
    cpu->ecx = 1u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x4416F5u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041708:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    g_sfera_interface.showOptions((cpu->ecx & 255u) != 0u);
    cpu->ecx = 1u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x441719u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004172C:
    if (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19 == 0u) goto label_00041A9F;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_interface.hasEscapeWindow());
    if (cpu->eax != 0u) goto label_00041AD4;
    label_00041746:
    cpu->ecx |= 0xFFFFFFFFu;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x44174Eu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041761:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441766u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x44176Fu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_win32_dialogs.create(reinterpret_cast<HINSTANCE>(static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_main_ui_state_runtime.active_ui_object))), cpu->ecx)));
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x441796u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != 0u) goto label_000417BB;
    cpu->ecx = (uintptr_t)"Error creating GUI window";
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->reportError(reinterpret_cast<const char*>(cpu->ecx))); cpu->eip = LIFT_CODE_TOKEN_VA(0x4417A8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000417BB:
    cpu->edx = 8u;
    g_sfera_mbc_runtime->active_process->registerResource(cpu->ecx, cpu->edx); cpu->eip = LIFT_CODE_TOKEN_VA(0x4417C5u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000417D8:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4417DDu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00041B5B;
    cpu->ecx = cpu->eax;
    g_sfera_win32_dialogs.destroy(reinterpret_cast<SferaDialogState*>(cpu->ecx));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, 0u);
    cpu->edx = 8u;
    { auto* process = reinterpret_cast<SferaMbcProcessRecord*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)); (process != nullptr ? process : g_sfera_mbc_runtime->active_process)->unregisterResource(cpu->ecx, cpu->edx); } cpu->esp += 4u; cpu->eip = LIFT_CODE_TOKEN_VA(0x441805u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041818:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x44181Du);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441826u);
    cpu->edi = cpu->eax;
    if (cpu->edi != 0u) goto label_0004183E;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, PEEK_MESSAGEGUI, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44183Bu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44183Bu));
    cpu->esp += 8u;
    label_0004183E:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441843u);
    cpu->ebx = cpu->eax;
    if (cpu->ebx != 0u) goto label_0004185B;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, PEEK_MESSAGEGUI, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441858u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x441858u));
    cpu->esp += 8u;
    label_0004185B:
    if ((int32_t)g_sfera_mbc_runtime->argument_count < (int32_t)5u) goto label_00041883;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441869u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->eax != 0u) goto label_00041883;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, PEEK_MESSAGEGUI, 3\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441880u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x441880u));
    cpu->esp += 8u;
    label_00041883:
    cpu->ebp = 6u;
    if (g_sfera_mbc_runtime->argument_count != cpu->ebp) goto label_000418AF;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441895u);
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
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4418C1u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    label_000418C5:
    if (g_sfera_mbc_runtime->argument_count != cpu->ebp) goto label_000418D4;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4418D2u);
    cpu->esi = cpu->eax;
    label_000418D4:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->esp + 0x20u;
    cpu->eax = cpu->ecx != 0u && reinterpret_cast<SferaDialogState*>(cpu->ecx)->takeEvent(*reinterpret_cast<SferaDialogEvent*>(cpu->edx));
    if (cpu->eax == 0u) goto label_00041A9F;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->eax + cpu->edi) = cpu->ecx;
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->edx + cpu->ebx) = cpu->eax;
    if (g_sfera_mbc_runtime->argument_count != cpu->ebp) goto label_00041935;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->ecx + cpu->edx) = cpu->eax;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->ecx + cpu->esi) = cpu->edx;
    label_00041935:
    cpu->ecx = 1u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x44193Fu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041952:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441957u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441960u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441967u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x44196Eu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441977u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
    cpu->eax = static_cast<std::uint32_t>(g_sfera_win32_dialogs.sendMessage(cpu->ecx, cpu->edx, *reinterpret_cast<const std::uint32_t*>(cpu->esp), static_cast<LPARAM>(*reinterpret_cast<const std::uint32_t*>(cpu->esp + 4u)))); cpu->esp += 8u;
    cpu->ecx = cpu->eax;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x4419B0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000419C3:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4419C8u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4419D1u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->eax;
    cpu->eax = cpu->ecx == 0u ? 0u : static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(::GetDlgItem(reinterpret_cast<SferaDialogState*>(cpu->ecx)->owner, static_cast<int>(cpu->edx))));
    cpu->ecx = cpu->eax;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x4419F0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041A03:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441A08u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441A11u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = cpu->edx + cpu->eax;
    cpu->eax = ::SetWindowTextA(g_sfera_win32_dialogs.resolve(cpu->ecx), reinterpret_cast<const char*>(cpu->edx));
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x441A37u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041A4A:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441A4Fu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441A58u);
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_00041A70;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: window, GET_WINDOW_TEXTGUI\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441A6Du)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x441A6Du));
    cpu->esp += 8u;
    label_00041A70:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441A75u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041B5B;
    if ((int32_t)cpu->eax >= (int32_t)1u) goto label_00041A8C;
    cpu->eax = 1u;
    label_00041A8C:
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    --cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->edx += cpu->esi;
    cpu->eax = ::GetWindowTextA(g_sfera_win32_dialogs.resolve(cpu->ecx), reinterpret_cast<char*>(cpu->edx), static_cast<int>(*reinterpret_cast<const std::uint32_t*>(cpu->esp))); cpu->esp += 4u;
    label_00041A9F:
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x441AA6u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041AB9:
    if ((int32_t)g_sfera_mbc_runtime->argument_count <= (int32_t)1u) goto label_00041AF1;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441AC7u);
    sub_pred[0] = (uint32_t)(*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.input_state_04) == 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (sub_pred[0]) goto label_00041A9F;
    label_00041AD4:
    cpu->ecx = 1u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x441ADEu);
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
    GameInterface::updateLoadingProgress(cpu->ecx);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041B4C:
    GameInterface::finishLoading();
    g_sfera_recovered_static_runtime.loadcount_guard = 1u;
    label_00041B5B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00041B5F:
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00441C90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441C96u);
    cpu->esi = cpu->eax;
    if (cpu->esi != 0u) goto label_00041CAE;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: thisname\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441CABu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x441CABu));
    cpu->esp += 8u;
    label_00041CAE:
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041CD2;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441CE7u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441CEEu);
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
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041D21:
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    cpu->esi += ((uintptr_t)&g_sfera_mbc_runtime->processes[0]);
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x6Cu) >= (int32_t)0u) goto label_00041D3D;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041D3D:
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041D5B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00441D60(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441D66u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441D6Du);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041DBF;
    if (cpu->esi > 0xFFFu) goto label_00041DB6;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x8D8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->edi += cpu->eax;
    cpu->eax = cpu->esi + ((uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0]);
    cpu->edx = cpu->edi;
    cpu->edx -= cpu->eax;
    label_00041D97:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00041D97;
    sub_pred[0] = *(uint8_t*)(cpu->edi) == (uint8_t)(cpu->ecx);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_00041DAF;
    cpu->ecx |= 0xFFFFFFFFu;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041DAF:
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041DB6:
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041DBF:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00441DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441DD5u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041E7D;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::_stricmp);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx += cpu->eax;
    cpu->edi = 0u;
    cpu->esi = (uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0];
    label_00041E00:
    if (*(uint8_t*)(cpu->esi) == 0u) goto label_00041E10;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, cpu->ebx);

    if (cpu->eax == 0u) goto label_00041E3B;
    label_00041E10:
    ++cpu->edi;
    cpu->esi += 0x8D8u;
    if ((int32_t)cpu->edi < (int32_t)0x1000u) goto label_00041E00;
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((int32_t)(cpu->ecx) < (int32_t)(0x100u)) goto label_00041E46;
    cpu->ecx = (uintptr_t)"Stack overflow";
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->reportError(reinterpret_cast<const char*>(cpu->ecx))); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041E3B:
    cpu->ecx = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041E46:
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    cpu->edx |= 0xFFFFFFFFu;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].value.base = cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source.base = cpu->edx;
    cpu->edx = 1u;
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source.end = cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source.begin = cpu->edx;
    g_sfera_mbc_runtime->value_stack_size = cpu->ecx;
    label_00041E7D:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00441E80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->argument_count;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if (cpu->eax != 4u) goto label_00041EE3;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441E94u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441E9Bu);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441EA2u);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441EA7u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041FD3;
    if (cpu->esi != 0u) goto label_00041EC7;
    cpu->edx = (uintptr_t)"";
    cpu->ecx = (uintptr_t)"Effect attached to zero handle!";
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->reportError(reinterpret_cast<const char*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx))); cpu->eip = LIFT_CODE_TOKEN_RVA(0x41EC7u);
    label_00041EC7:
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx = cpu->ecx + cpu->edi;
    cpu->edx = cpu->esi;
    { auto* created_effect = g_sfera_effect_manager.createActiveEffect(reinterpret_cast<const char*>(cpu->ecx), cpu->edx); cpu->eax = created_effect ? static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(created_effect)) : UINT32_MAX; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041EE3:
    if ((int32_t)cpu->eax >= (int32_t)3u) goto label_00041F43;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441EEDu);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441EF4u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041FD3;
    if ((int32_t)cpu->esi > 0) goto label_00041F2E;
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
    cpu->ecx += 0x10u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Wrong Handler for Effect %s\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441F1Eu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x441F1Eu));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041F2E:
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    { auto* created_effect = g_sfera_effect_manager.createActiveEffect(cpu->ecx, cpu->edx); cpu->eax = created_effect ? static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(created_effect)) : UINT32_MAX; }
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041F43:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441F48u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441F4Fu);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441F56u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00041FD3;
    if ((int32_t)cpu->esi > 0) goto label_00041F8D;
    cpu->edx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
    cpu->edx += 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"Wrong Handler for Effect %s\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x441F7Cu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x441F7Cu));
    cpu->esp += 0xCu;
    label_00041F7F:
    cpu->ecx |= 0xFFFFFFFFu;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x441F87u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041F8D:
    if (cpu->eax != 0u) goto label_00041FAF;
    if (cpu->esi == g_sfera_world_objects.controlled_object_handle) goto label_00041F7F;
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    { auto* created_effect = g_sfera_effect_manager.createActiveEffect(cpu->ecx, cpu->edx); cpu->eax = created_effect ? static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(created_effect)) : UINT32_MAX; }
    cpu->ecx = cpu->eax;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x441FA9u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00041FAF:
    cpu->ecx = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    lift_push32(cpu, 1u);
    cpu->edx = cpu->esp + 0xCu;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edi;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_effect_manager.setEffectParameters(cpu->ecx, reinterpret_cast<const SferaEffectParameter*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)));  cpu->esp += 4u;
    cpu->ecx = cpu->eax;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x41FD3u);
    label_00041FD3:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00441FE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x441FE9u);
    cpu->esi = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00042028;
    if ((int32_t)cpu->esi > 0) goto label_00042003;
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00042003:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44200Au)); sfera_sub_004360D0(cpu, LIFT_CODE_TOKEN_VA(0x44200Au));
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    cpu->eax = cpu->eax + cpu->esi + 0xFFFFFFFFu;
    cpu->edx = 1u;
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    g_sfera_mbc_runtime->pushSlice(*reinterpret_cast<const SferaSliceReference32*>(cpu->ecx), cpu->edx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x42028u);
    label_00042028:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00442030(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x442038u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x44203Fu);
    cpu->ebp = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax == 0u) goto label_000420A8;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if (cpu->ecx < cpu->eax) goto label_00042053;
    if (cpu->ecx <= *(uint32_t*)(cpu->esi + 8u)) goto label_000420A8;
    label_00042053:
    cpu->ecx = 1u;
    WorldDiagnostics::describeScript(cpu->ecx != 0);
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
    sub_pred[0] = (int32_t)(cpu->eax) < (int32_t)(cpu->ecx);
    if (cpu->eax < cpu->ecx) goto label_00042098;
    if (cpu->eax <= *(uint32_t*)(cpu->esi + 8u)) goto label_000420A8;
    sub_pred[0] = (int32_t)(cpu->eax) < (int32_t)(cpu->ecx);
    label_00042098:
    if (!sub_pred[0]) goto label_0004209F;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    goto label_000420A8;
    label_0004209F:
    --cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)*(uint32_t*)(cpu->esi + 8u)) goto label_000420A8;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    label_000420A8:
    cpu->ebx = *(uint32_t*)(cpu->esi);
    cpu->ebx += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0004212E;
    lift_push32(cpu, cpu->edi);
    if ((int32_t)cpu->ebp > 0) goto label_000420C2;
    cpu->edi = 0u;
    goto label_0004210A;
    label_000420C2:
    lift_push32(cpu, 0x35B4u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->ebp;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_000420DB;
    cpu->edi = 0u;
    goto label_0004210A;
    label_000420DB:
    cpu->eax -= static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = 3u;
    cpu->edi = cpu->eax;
    g_sfera_mbc_runtime->active_process->registerResource(cpu->ecx, cpu->edx); cpu->eip = LIFT_CODE_TOKEN_VA(0x4420EFu);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
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
__declspec(noinline) void sfera_sub_00442140(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x442147u);
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax == 0u) goto label_000421B0;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if (cpu->ecx < cpu->eax) goto label_0004215B;
    if (cpu->ecx <= *(uint32_t*)(cpu->esi + 8u)) goto label_000421B0;
    label_0004215B:
    cpu->ecx = 1u;
    WorldDiagnostics::describeScript(cpu->ecx != 0);
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
    sub_pred[0] = (int32_t)(cpu->eax) < (int32_t)(cpu->ecx);
    if (cpu->eax < cpu->ecx) goto label_000421A0;
    if (cpu->eax <= *(uint32_t*)(cpu->esi + 8u)) goto label_000421B0;
    sub_pred[0] = (int32_t)(cpu->eax) < (int32_t)(cpu->ecx);
    label_000421A0:
    if (!sub_pred[0]) goto label_000421A7;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    goto label_000421B0;
    label_000421A7:
    --cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)*(uint32_t*)(cpu->esi + 8u)) goto label_000421B0;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    label_000421B0:
    cpu->edi = *(uint32_t*)(cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->edi += cpu->eax;
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00042219;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->edi);
    if (cpu->ebx == 0u) goto label_00042218;
    cpu->ebx += cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->active_process));
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
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->edi) = cpu->eax;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 8u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->eax + 3u;
    { auto* process = reinterpret_cast<SferaMbcProcessRecord*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)); (process != nullptr ? process : g_sfera_mbc_runtime->active_process)->unregisterResource(cpu->ecx, cpu->edx); } cpu->esp += 4u; cpu->eip = LIFT_CODE_TOKEN_RVA(0x42218u);
    label_00042218:
    cpu->ebx = lift_pop32(cpu);
    label_00042219:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00442220(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x442229u);
    cpu->esi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x442230u);
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    if (((uint32_t)(g_sfera_mbc_runtime->argument_count) == 2u) || ((int32_t)((uint32_t)(g_sfera_mbc_runtime->argument_count)) < (int32_t)(2u))) goto label_00042250;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x442242u);
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    if ((int32_t)cpu->eax < 0) goto label_00042392;
    goto label_00042258;
    label_00042250:
    *(uint32_t*)(cpu->esp + 4u) = 0u;
    label_00042258:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_000422A5;
    if ((cpu->edx & 0xFFu) == 0u) goto label_000422A1;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_000422A5;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00042285;
    label_000422A1:
    cpu->eax = 0u;
    goto label_000422AA;
    label_000422A5:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
    label_000422AA:
    if (cpu->eax == 0u) goto label_00042323;
    cpu->esi += 0x10u;
    ++cpu->ebx;
    g_sfera_mbc_runtime->named_vector_cursor = cpu->esi;
    if ((int32_t)cpu->ebx < (int32_t)cpu->edi) goto label_00042280;
    label_000422BC:
    if ((int32_t)(cpu->edi) >= (int32_t)(0x3E8u)) goto label_0004238F;
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
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
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::reallocate(reinterpret_cast<void*>(cpu->ecx), cpu->edx, reinterpret_cast<const char*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)), *reinterpret_cast<const std::uint32_t*>(cpu->esp + 4u)))); cpu->esp += 8u;
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
__declspec(noinline) void sfera_sub_004423A0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4423AAu);
    cpu->ebx = 1u;
    cpu->esi = cpu->eax;
    if ((int32_t)g_sfera_mbc_runtime->argument_count <= (int32_t)cpu->ebx) goto label_000423C4;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4423BEu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    goto label_000423CC;
    label_000423C4:
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    label_000423CC:
    cpu->ebp = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
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
    sub_pred[0] = (uint8_t)(cpu->ebx) < *(uint8_t*)(cpu->edx);
    if ((uint8_t)(cpu->ebx) != *(uint8_t*)(cpu->edx)) goto label_00042415;
    if ((cpu->ebx & 0xFFu) == 0u) goto label_00042411;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + 1u));
    sub_pred[0] = (uint8_t)(cpu->ebx) < *(uint8_t*)(cpu->edx + 1u);
    if ((uint8_t)(cpu->ebx) != *(uint8_t*)(cpu->edx + 1u)) goto label_00042415;
    cpu->ecx += 2u;
    cpu->edx += 2u;
    if ((cpu->ebx & 0xFFu) != 0u) goto label_000423F5;
    label_00042411:
    cpu->ecx = 0u;
    goto label_0004241A;
    label_00042415:
    cpu->ecx = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
    label_0004241A:
    if (cpu->ecx == 0u) goto label_000424AD;
    ++cpu->edi;
    cpu->esi += 0x10u;
    g_sfera_mbc_runtime->named_vector_cursor = cpu->esi;
    if ((int32_t)cpu->edi < (int32_t)cpu->eax) goto label_000423F0;
    cpu->ebx = 1u;
    label_00042435:
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    if ((int32_t)(cpu->ecx) < (int32_t)(0x100u)) goto label_00042524;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldDiagnostics::scriptContext()));
    cpu->ecx = (uintptr_t)"\n---exit_inter start---\nMBINTER MESSAGE:";
    g_sfera_log_runtime.files[0].write(reinterpret_cast<const char*>(cpu->ecx));
    cpu->ecx = (uintptr_t)"Stack overflow";
    g_sfera_log_runtime.files[0].write(reinterpret_cast<const char*>(cpu->ecx));
    cpu->ecx = (uintptr_t)"\n";
    g_sfera_log_runtime.files[0].write(reinterpret_cast<const char*>(cpu->ecx));
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    g_sfera_log_runtime.files[0].write(reinterpret_cast<const char*>(cpu->ecx));
    cpu->ecx = (uintptr_t)"---exit_inter end-----\n";
    g_sfera_log_runtime.files[0].write(reinterpret_cast<const char*>(cpu->ecx));
    sub_pred[1] = (uint32_t)(g_sfera_mbc_runtime->process_index) == 0u;
    g_sfera_mbc_runtime->execution_failed = cpu->ebx;
    if (!sub_pred[1]) goto label_00042497;
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x42497u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x42497u));
    label_00042497:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->edx = (uintptr_t)"EError";
    cpu->ecx = (uintptr_t)&g_sfera_mbc_runtime->processes[0];
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<SferaMbcProcessRecord*>(cpu->ecx)->activateProgram(reinterpret_cast<const char*>(cpu->edx))); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000424AD:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    if ((int32_t)cpu->eax >= 0) goto label_00042501;
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    if ((int32_t)(cpu->ecx) < (int32_t)(0x100u)) goto label_000424D7;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = (uintptr_t)"Stack overflow";
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->reportError(reinterpret_cast<const char*>(cpu->ecx))); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000424D7:
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].value.base = cpu->edx;
    cpu->edx = 1u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source.end = cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source.begin = cpu->edx;
    cpu->ecx += cpu->edx;
    goto label_0004254B;
    label_00042501:
    cpu->edi = lift_pop32(cpu);
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00042514;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00042514:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00042524:
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].value.base = 0u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source.end = cpu->ebx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source.begin = cpu->ebx;
    cpu->ecx += cpu->ebx;
    label_0004254B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    g_sfera_mbc_runtime->value_stack_size = cpu->ecx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source.base = 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00442570(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    cpu->eax = (uintptr_t)&g_sfera_font_runtime;
    cpu->eax -= static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    cpu->edx = 1u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp) = cpu->eax;
    cpu->eax += 7u;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    g_sfera_mbc_runtime->pushSlice(*reinterpret_cast<const SferaSliceReference32*>(cpu->ecx), cpu->edx); cpu->eip = LIFT_CODE_TOKEN_VA(0x442599u);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}























} // namespace lifted
