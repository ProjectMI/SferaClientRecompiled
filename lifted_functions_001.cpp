#include "lifted_functions.h"
#include <cmath>
namespace lifted {


__declspec(noinline) void sfera_sub_0040A470(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 8u;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esi += 8u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x20u) == 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if (sub_pred[0]) goto label_0000A4C5;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0000A4C5:
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_0000A4D6;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ecx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0000A4D6:
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    *(uint8_t*)(cpu->esi) = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040A500(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = 0u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x40A512u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->ecx += static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(g_sfera_mbc_runtime->process_memory_base));
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    *(uint8_t*)(cpu->esi) = 0u;
    cpu->edi = cpu->eax + 1u;
    label_0000A530:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0000A530;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40A542u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x40A542u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_0040A680(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_0000A6DD;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    if (*(uint32_t*)(cpu->esi + 0x1Cu) < 0x10u) goto label_0000A6B3;
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0000A6B3:
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x1Cu) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->eax;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 8u) = cpu->eax & 0xFFu;
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->edi + 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0000A6DD:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_0040AB90(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->edi + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->edi + 8u);
    cpu->edx += cpu->eax;
    cpu->esi = 0x811C9DC5u;
    if (cpu->eax == cpu->edx) goto label_0000ABC1;
    lift_push32(cpu, cpu->ebx);
    label_0000ABB0:
    cpu->ebx = (int8_t)(*(uint8_t*)(cpu->eax));
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x1000193u);
    ++cpu->eax;
    cpu->esi ^= cpu->ebx;
    if (cpu->eax != cpu->edx) goto label_0000ABB0;
    cpu->ebx = lift_pop32(cpu);
    label_0000ABC1:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    cpu->eax = cpu->edx;
    cpu->eax &= cpu->esi;
    if (*(uint32_t*)(cpu->ecx + 0x24u) > cpu->eax) goto label_0000ABD6;
    cpu->edx >>= 1u;
    cpu->esi |= 0xFFFFFFFFu;
    cpu->esi -= cpu->edx;
    cpu->eax += cpu->esi;
    label_0000ABD6:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x10u);
    sub_pred[0] = *(uint32_t*)(cpu->edx + (cpu->eax * 8u) + 4u) == cpu->edi;
    cpu->edx = cpu->edx + (cpu->eax * 8u);
    if (!sub_pred[0]) goto label_0000ABFF;
    if (*(uint32_t*)(cpu->edx) != cpu->edi) goto label_0000ABF7;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx) = cpu->esi;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx + (cpu->eax * 8u) + 4u) = cpu->esi;
    goto label_0000AC07;
    label_0000ABF7:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    goto label_0000AC07;
    label_0000ABFF:
    if (*(uint32_t*)(cpu->edx) != cpu->edi) goto label_0000AC0B;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    label_0000AC07:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000AC0B:
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx += 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40AC19u)); sfera_sub_00406BA0(cpu, LIFT_CODE_TOKEN_VA(0x40AC19u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040AC20(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0x811C9DC5u;
    if (cpu->eax == cpu->edx) goto label_0000AC50;
    label_0000AC40:
    cpu->ebx = (int8_t)(*(uint8_t*)(cpu->eax));
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x1000193u);
    ++cpu->eax;
    cpu->edi ^= cpu->ebx;
    if (cpu->eax != cpu->edx) goto label_0000AC40;
    label_0000AC50:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->eax = cpu->edx;
    cpu->eax &= cpu->edi;
    if (*(uint32_t*)(cpu->esi + 0x24u) > cpu->eax) goto label_0000AC65;
    cpu->edx >>= 1u;
    cpu->edi |= 0xFFFFFFFFu;
    cpu->edi -= cpu->edx;
    cpu->eax += cpu->edi;
    label_0000AC65:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    sub_pred[0] = *(uint32_t*)(cpu->edx + (cpu->eax * 8u) + 4u) == cpu->ecx;
    cpu->edx = cpu->edx + (cpu->eax * 8u);
    if (!sub_pred[0]) goto label_0000AC8E;
    if (*(uint32_t*)(cpu->edx) != cpu->ecx) goto label_0000AC86;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx + (cpu->eax * 8u) + 4u) = cpu->ecx;
    goto label_0000AC96;
    label_0000AC86:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    goto label_0000AC96;
    label_0000AC8E:
    if (*(uint32_t*)(cpu->edx) != cpu->ecx) goto label_0000AC9A;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    label_0000AC96:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    label_0000AC9A:
    cpu->ebx = *(uint32_t*)(cpu->ecx);
    cpu->edi = cpu->ecx;
    if (cpu->ecx == *(uint32_t*)(cpu->esi + 4u)) goto label_0000ACC5;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = cpu->ecx + 4u;
    *(uint32_t*)(cpu->edx) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40ACB9u)); sfera_sub_00403C10(cpu, LIFT_CODE_TOKEN_VA(0x40ACB9u));
    lift_push32(cpu, cpu->edi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->esi + 8u);
    label_0000ACC5:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_0040BB40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->edi + 4u) = cpu->ebx;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_0000BB91;
    lift_push32(cpu, cpu->ebp);
    label_0000BB60:
    cpu->ebp = *(uint32_t*)(cpu->esi);
    if (*(uint32_t*)(cpu->esi + 0x20u) < 0x10u) goto label_0000BB74;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0000BB74:
    *(uint32_t*)(cpu->esi + 0x20u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->ebx;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 0xCu) = cpu->ebx & 0xFFu;
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    cpu->esi = cpu->ebp;
    if (cpu->ebp != *(uint32_t*)(cpu->edi)) goto label_0000BB60;
    cpu->ebp = lift_pop32(cpu);
    label_0000BB91:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040BBA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->edi + 4u) = cpu->ebx;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_0000BC10;
    lift_push32(cpu, cpu->ebp);
    label_0000BBC0:
    cpu->ebp = *(uint32_t*)(cpu->esi);
    if (*(uint32_t*)(cpu->esi + 0x38u) < 0x10u) goto label_0000BBD4;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0000BBD4:
    *(uint32_t*)(cpu->esi + 0x38u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x24u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esi + 0x1Cu) < 0x10u) goto label_0000BBF3;
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0000BBF3:
    *(uint32_t*)(cpu->esi + 0x1Cu) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ebx;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 8u) = cpu->ebx & 0xFFu;
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    cpu->esi = cpu->ebp;
    if (cpu->ebp != *(uint32_t*)(cpu->edi)) goto label_0000BBC0;
    cpu->ebp = lift_pop32(cpu);
    label_0000BC10:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040BC20(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->edi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    *(uint32_t*)(cpu->ebx + 4u) = 0u;
    if (cpu->edi == *(uint32_t*)(cpu->ebx)) goto label_0000BCC8;
    label_0000BC5D:
    cpu->ebp = *(uint32_t*)(cpu->edi);
    cpu->esi = cpu->edi + 8u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    sub_pred[1] = *(uint32_t*)(cpu->esi + 0x20u) == 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    if (sub_pred[1]) goto label_0000BC8F;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0000BC8F:
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x14u) < 0x10u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0xFFFFFFFFu;
    if (sub_pred[0]) goto label_0000BCA8;
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0000BCA8:
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    lift_push32(cpu, cpu->edi);
    *(uint8_t*)(cpu->esi) = 0u;
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    cpu->edi = cpu->ebp;
    if (cpu->ebp != *(uint32_t*)(cpu->ebx)) goto label_0000BC5D;
    label_0000BCC8:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_0040C700(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_0000C75D;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    if (*(uint32_t*)(cpu->esi + 0x20u) < 0x10u) goto label_0000C733;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0000C733:
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x20u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->eax;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 0xCu) = cpu->eax & 0xFFu;
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->edi + 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0000C75D:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040C770(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_0000C7E3;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    if (*(uint32_t*)(cpu->esi + 0x38u) < 0x10u) goto label_0000C7A3;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->ecx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0000C7A3:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esi + 0x38u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x24u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esi + 0x1Cu) < 0x10u) goto label_0000C7C5;
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->edx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0000C7C5:
    *(uint32_t*)(cpu->esi + 0x1Cu) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ebx;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 8u) = cpu->ebx & 0xFFu;
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->edi + 4u);
    cpu->ebx = lift_pop32(cpu);
    label_0000C7E3:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040C7F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_0000C82A;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi + 8u;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40C81Au)); sfera_sub_0040A470(cpu, LIFT_CODE_TOKEN_VA(0x40C81Au));
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->edi + 4u);
    label_0000C82A:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_0040D740(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->edi + 4u) = cpu->ebx;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_0000D7B1;
    lift_push32(cpu, cpu->ebp);
    label_0000D760:
    cpu->ebp = *(uint32_t*)(cpu->esi);
    if (*(uint32_t*)(cpu->esi + 0x24u) < 0x10u) goto label_0000D774;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0000D774:
    *(uint32_t*)(cpu->esi + 0x24u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x10u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esi + 0xCu) == cpu->ebx) goto label_0000D7A1;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0000D7A1:
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    cpu->esi = cpu->ebp;
    if (cpu->ebp != *(uint32_t*)(cpu->edi)) goto label_0000D760;
    cpu->ebp = lift_pop32(cpu);
    label_0000D7B1:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040D7C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = cpu->edi + 0x10u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    if (cpu->esi == cpu->edx) goto label_0000D7F2;
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->edx) goto label_0000D7EF;
    lift_push32(cpu, cpu->ebx);
    label_0000D7E0:
    cpu->ebx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esi) = cpu->ebx;
    cpu->eax += 4u;
    cpu->esi += 4u;
    if (cpu->eax != cpu->edx) goto label_0000D7E0;
    cpu->ebx = lift_pop32(cpu);
    label_0000D7EF:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->esi;
    label_0000D7F2:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D807u)); sfera_sub_00408D90(cpu, LIFT_CODE_TOKEN_VA(0x40D807u));
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->edi + 0x24u) = cpu->esi;
    *(uint32_t*)(cpu->edi + 0x20u) = cpu->eax;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040D820(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, 0x1F31Du); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ldiv), LIFT_CODE_TOKEN_VA(0x40D831u));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x41A7u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xB14u);
    cpu->esp += 8u;
    if ((int32_t)(cpu->edx -= cpu->eax) >= 0) goto label_0000D850;
    cpu->edx += 0x7FFFFFFFu;
    label_0000D850:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->eax = cpu->ecx;
    cpu->eax &= cpu->edx;
    if (*(uint32_t*)(cpu->esi + 0x24u) > cpu->eax) goto label_0000D865;
    cpu->ecx >>= 1u;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->ecx;
    cpu->eax += cpu->edx;
    label_0000D865:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    sub_pred[0] = *(uint32_t*)(cpu->ecx + (cpu->eax * 8u) + 4u) == cpu->edx;
    cpu->ecx = cpu->ecx + (cpu->eax * 8u);
    if (!sub_pred[0]) goto label_0000D892;
    if (*(uint32_t*)(cpu->ecx) != cpu->edx) goto label_0000D88A;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->ecx + (cpu->eax * 8u) + 4u) = cpu->edx;
    goto label_0000D89A;
    label_0000D88A:
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    goto label_0000D89A;
    label_0000D892:
    if (*(uint32_t*)(cpu->ecx) != cpu->edx) goto label_0000D89E;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    label_0000D89A:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000D89E:
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D8ACu)); sfera_sub_0040C700(cpu, LIFT_CODE_TOKEN_VA(0x40D8ACu));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040D8C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = cpu->edi + 8u;
    cpu->esi = cpu->ecx;
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x20u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D8D5u)); sfera_sub_00403170(cpu, LIFT_CODE_TOKEN_VA(0x40D8D5u));
    cpu->eax &= cpu->ebx;
    if (*(uint32_t*)(cpu->esi + 0x24u) > cpu->eax) goto label_0000D8E5;
    cpu->ebx >>= 1u;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->ebx;
    cpu->eax += cpu->ecx;
    label_0000D8E5:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ecx = cpu->edx + (cpu->eax * 8u);
    if (*(uint32_t*)(cpu->edx + (cpu->eax * 8u) + 4u) != cpu->edi) goto label_0000D90E;
    if (*(uint32_t*)(cpu->ecx) != cpu->edi) goto label_0000D906;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->ecx + (cpu->eax * 8u) + 4u) = cpu->edx;
    goto label_0000D916;
    label_0000D906:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    goto label_0000D916;
    label_0000D90E:
    if (*(uint32_t*)(cpu->ecx) != cpu->edi) goto label_0000D91A;
    cpu->edx = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    label_0000D916:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    label_0000D91A:
    cpu->ebx = *(uint32_t*)(cpu->edi);
    if (cpu->edi == *(uint32_t*)(cpu->esi + 4u)) goto label_0000D943;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->ebx;
    cpu->edx = *(uint32_t*)(cpu->edi);
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi + 0xCu;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40D937u)); sfera_sub_0040A470(cpu, LIFT_CODE_TOKEN_VA(0x40D937u));
    lift_push32(cpu, cpu->edi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->esi + 8u);
    label_0000D943:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040D950(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->esi == *(uint32_t*)(cpu->edi)) goto label_0000D9C0;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    if (*(uint32_t*)(cpu->esi + 0x24u) < 0x10u) goto label_0000D983;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->ecx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0000D983:
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x24u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->eax;
    *(uint8_t*)(cpu->esi + 0x10u) = cpu->eax & 0xFFu;
    if (*(uint32_t*)(cpu->esi + 0xCu) == cpu->eax) goto label_0000D9B0;
    cpu->edx = cpu->eax + 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->edx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0000D9B0:
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->edi + 4u);
    label_0000D9C0:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_0040E070(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    x87_v0 = (double)*(float*)(cpu->ebx + 0x28u);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->ebx + 8u))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x24u);
    if ((int32_t)cpu->eax >= 0) goto label_0000E08B;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_0000E08B:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u))));
    if ((int32_t)cpu->ecx >= 0) goto label_0000E09F;
    x87_v2 = (x87_v2) + (((double)4294967296.0f));
    label_0000E09F:
    x87_v1 = x87_v1 / x87_v2; 
    *(float*)(cpu->esp + 8u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 8u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (!(lift_left>lift_right)) goto label_0000E118; }
    cpu->eax = 0u;
    label_0000E0B4:
    if (cpu->esi >= 0x1FFFFFFFu) goto label_0000E0C4;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)cpu->eax < (int32_t)3u) goto label_0000E0B4;
    label_0000E0C4:
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = cpu->ebx + 0x10u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi == cpu->edx) goto label_0000E0F2;
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->edx) goto label_0000E0EF;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E0E0:
    cpu->ebp = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi) = cpu->ebp;
    cpu->eax += 4u;
    cpu->edi += 4u;
    if (cpu->eax != cpu->edx) goto label_0000E0E0;
    cpu->ebp = lift_pop32(cpu);
    label_0000E0EF:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    label_0000E0F2:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E103u)); sfera_sub_00408D90(cpu, LIFT_CODE_TOKEN_VA(0x40E103u));
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->ebx + 0x24u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E117u)); sfera_sub_0040FAC0(cpu, LIFT_CODE_TOKEN_VA(0x40E117u));
    cpu->edi = lift_pop32(cpu);
    label_0000E118:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040E120(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    x87_v0 = (double)*(float*)(cpu->ebx + 0x28u);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->ebx + 8u))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x24u);
    if ((int32_t)cpu->eax >= 0) goto label_0000E13B;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_0000E13B:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u))));
    if ((int32_t)cpu->ecx >= 0) goto label_0000E14F;
    x87_v2 = (x87_v2) + (((double)4294967296.0f));
    label_0000E14F:
    x87_v1 = x87_v1 / x87_v2; 
    *(float*)(cpu->esp + 8u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 8u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (!(lift_left>lift_right)) goto label_0000E1C8; }
    cpu->eax = 0u;
    label_0000E164:
    if (cpu->esi >= 0x1FFFFFFFu) goto label_0000E174;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)cpu->eax < (int32_t)3u) goto label_0000E164;
    label_0000E174:
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = cpu->ebx + 0x10u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi == cpu->edx) goto label_0000E1A2;
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->edx) goto label_0000E19F;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E190:
    cpu->ebp = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi) = cpu->ebp;
    cpu->eax += 4u;
    cpu->edi += 4u;
    if (cpu->eax != cpu->edx) goto label_0000E190;
    cpu->ebp = lift_pop32(cpu);
    label_0000E19F:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    label_0000E1A2:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E1B3u)); sfera_sub_00408D90(cpu, LIFT_CODE_TOKEN_VA(0x40E1B3u));
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->ebx + 0x24u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E1C7u)); sfera_sub_0040FB10(cpu, LIFT_CODE_TOKEN_VA(0x40E1C7u));
    cpu->edi = lift_pop32(cpu);
    label_0000E1C8:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040E1D0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    x87_v0 = (double)*(float*)(cpu->ebx + 0x28u);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->ebx + 8u))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x24u);
    if ((int32_t)cpu->eax >= 0) goto label_0000E1EB;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_0000E1EB:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u))));
    if ((int32_t)cpu->ecx >= 0) goto label_0000E1FF;
    x87_v2 = (x87_v2) + (((double)4294967296.0f));
    label_0000E1FF:
    x87_v1 = x87_v1 / x87_v2; 
    *(float*)(cpu->esp + 8u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 8u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (!(lift_left>lift_right)) goto label_0000E278; }
    cpu->eax = 0u;
    label_0000E214:
    if (cpu->esi >= 0x1FFFFFFFu) goto label_0000E224;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)cpu->eax < (int32_t)3u) goto label_0000E214;
    label_0000E224:
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = cpu->ebx + 0x10u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi == cpu->edx) goto label_0000E252;
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->edx) goto label_0000E24F;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E240:
    cpu->ebp = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi) = cpu->ebp;
    cpu->eax += 4u;
    cpu->edi += 4u;
    if (cpu->eax != cpu->edx) goto label_0000E240;
    cpu->ebp = lift_pop32(cpu);
    label_0000E24F:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    label_0000E252:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E263u)); sfera_sub_00408D90(cpu, LIFT_CODE_TOKEN_VA(0x40E263u));
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->ebx + 0x24u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E277u)); sfera_sub_0040FB60(cpu, LIFT_CODE_TOKEN_VA(0x40E277u));
    cpu->edi = lift_pop32(cpu);
    label_0000E278:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040E280(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    x87_v0 = (double)*(float*)(cpu->ebx + 0x28u);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->ebx + 8u))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x24u);
    if ((int32_t)cpu->eax >= 0) goto label_0000E29B;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_0000E29B:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u))));
    if ((int32_t)cpu->ecx >= 0) goto label_0000E2AF;
    x87_v2 = (x87_v2) + (((double)4294967296.0f));
    label_0000E2AF:
    x87_v1 = x87_v1 / x87_v2; 
    *(float*)(cpu->esp + 8u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 8u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (!(lift_left>lift_right)) goto label_0000E328; }
    cpu->eax = 0u;
    label_0000E2C4:
    if (cpu->esi >= 0x1FFFFFFFu) goto label_0000E2D4;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)cpu->eax < (int32_t)3u) goto label_0000E2C4;
    label_0000E2D4:
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = cpu->ebx + 0x10u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi == cpu->edx) goto label_0000E302;
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->edx) goto label_0000E2FF;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E2F0:
    cpu->ebp = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi) = cpu->ebp;
    cpu->eax += 4u;
    cpu->edi += 4u;
    if (cpu->eax != cpu->edx) goto label_0000E2F0;
    cpu->ebp = lift_pop32(cpu);
    label_0000E2FF:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    label_0000E302:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E313u)); sfera_sub_00408D90(cpu, LIFT_CODE_TOKEN_VA(0x40E313u));
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->ebx + 0x24u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E327u)); sfera_sub_0040FBB0(cpu, LIFT_CODE_TOKEN_VA(0x40E327u));
    cpu->edi = lift_pop32(cpu);
    label_0000E328:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040E330(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    x87_v0 = (double)*(float*)(cpu->ebx + 0x28u);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->ebx + 8u))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x24u);
    if ((int32_t)cpu->eax >= 0) goto label_0000E34B;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_0000E34B:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u))));
    if ((int32_t)cpu->ecx >= 0) goto label_0000E35F;
    x87_v2 = (x87_v2) + (((double)4294967296.0f));
    label_0000E35F:
    x87_v1 = x87_v1 / x87_v2; 
    *(float*)(cpu->esp + 8u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 8u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (!(lift_left>lift_right)) goto label_0000E3D8; }
    cpu->eax = 0u;
    label_0000E374:
    if (cpu->esi >= 0x1FFFFFFFu) goto label_0000E384;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)cpu->eax < (int32_t)3u) goto label_0000E374;
    label_0000E384:
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = cpu->ebx + 0x10u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi == cpu->edx) goto label_0000E3B2;
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->edx) goto label_0000E3AF;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E3A0:
    cpu->ebp = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi) = cpu->ebp;
    cpu->eax += 4u;
    cpu->edi += 4u;
    if (cpu->eax != cpu->edx) goto label_0000E3A0;
    cpu->ebp = lift_pop32(cpu);
    label_0000E3AF:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    label_0000E3B2:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E3C3u)); sfera_sub_00408D90(cpu, LIFT_CODE_TOKEN_VA(0x40E3C3u));
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->ebx + 0x24u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E3D7u)); sfera_sub_0040FC00(cpu, LIFT_CODE_TOKEN_VA(0x40E3D7u));
    cpu->edi = lift_pop32(cpu);
    label_0000E3D8:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040E3E0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    x87_v0 = (double)*(float*)(cpu->ebx + 0x28u);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->ebx + 8u))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x24u);
    if ((int32_t)cpu->eax >= 0) goto label_0000E3FB;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_0000E3FB:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u))));
    if ((int32_t)cpu->ecx >= 0) goto label_0000E40F;
    x87_v2 = (x87_v2) + (((double)4294967296.0f));
    label_0000E40F:
    x87_v1 = x87_v1 / x87_v2; 
    *(float*)(cpu->esp + 8u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 8u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (!(lift_left>lift_right)) goto label_0000E488; }
    cpu->eax = 0u;
    label_0000E424:
    if (cpu->esi >= 0x1FFFFFFFu) goto label_0000E434;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)cpu->eax < (int32_t)3u) goto label_0000E424;
    label_0000E434:
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = cpu->ebx + 0x10u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi == cpu->edx) goto label_0000E462;
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->edx) goto label_0000E45F;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E450:
    cpu->ebp = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi) = cpu->ebp;
    cpu->eax += 4u;
    cpu->edi += 4u;
    if (cpu->eax != cpu->edx) goto label_0000E450;
    cpu->ebp = lift_pop32(cpu);
    label_0000E45F:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    label_0000E462:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E473u)); sfera_sub_00408D90(cpu, LIFT_CODE_TOKEN_VA(0x40E473u));
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->ebx + 0x24u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E487u)); sfera_sub_0040FC50(cpu, LIFT_CODE_TOKEN_VA(0x40E487u));
    cpu->edi = lift_pop32(cpu);
    label_0000E488:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040E490(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    x87_v0 = (double)*(float*)(cpu->ebx + 0x28u);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->ebx + 8u))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x24u);
    if ((int32_t)cpu->eax >= 0) goto label_0000E4AB;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_0000E4AB:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u))));
    if ((int32_t)cpu->ecx >= 0) goto label_0000E4BF;
    x87_v2 = (x87_v2) + (((double)4294967296.0f));
    label_0000E4BF:
    x87_v1 = x87_v1 / x87_v2; 
    *(float*)(cpu->esp + 8u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 8u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (!(lift_left>lift_right)) goto label_0000E538; }
    cpu->eax = 0u;
    label_0000E4D4:
    if (cpu->esi >= 0x1FFFFFFFu) goto label_0000E4E4;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)cpu->eax < (int32_t)3u) goto label_0000E4D4;
    label_0000E4E4:
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = cpu->ebx + 0x10u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi == cpu->edx) goto label_0000E512;
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->edx) goto label_0000E50F;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E500:
    cpu->ebp = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi) = cpu->ebp;
    cpu->eax += 4u;
    cpu->edi += 4u;
    if (cpu->eax != cpu->edx) goto label_0000E500;
    cpu->ebp = lift_pop32(cpu);
    label_0000E50F:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    label_0000E512:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E523u)); sfera_sub_00408D90(cpu, LIFT_CODE_TOKEN_VA(0x40E523u));
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->ebx + 0x24u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E537u)); sfera_sub_0040FCA0(cpu, LIFT_CODE_TOKEN_VA(0x40E537u));
    cpu->edi = lift_pop32(cpu);
    label_0000E538:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040E540(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    x87_v0 = (double)*(float*)(cpu->ebx + 0x28u);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->ebx + 8u))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x24u);
    if ((int32_t)cpu->eax >= 0) goto label_0000E55B;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_0000E55B:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u))));
    if ((int32_t)cpu->ecx >= 0) goto label_0000E56F;
    x87_v2 = (x87_v2) + (((double)4294967296.0f));
    label_0000E56F:
    x87_v1 = x87_v1 / x87_v2; 
    *(float*)(cpu->esp + 8u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 8u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (!(lift_left>lift_right)) goto label_0000E5E8; }
    cpu->eax = 0u;
    label_0000E584:
    if (cpu->esi >= 0x1FFFFFFFu) goto label_0000E594;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)cpu->eax < (int32_t)3u) goto label_0000E584;
    label_0000E594:
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = cpu->ebx + 0x10u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi == cpu->edx) goto label_0000E5C2;
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->edx) goto label_0000E5BF;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E5B0:
    cpu->ebp = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi) = cpu->ebp;
    cpu->eax += 4u;
    cpu->edi += 4u;
    if (cpu->eax != cpu->edx) goto label_0000E5B0;
    cpu->ebp = lift_pop32(cpu);
    label_0000E5BF:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    label_0000E5C2:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E5D3u)); sfera_sub_00408D90(cpu, LIFT_CODE_TOKEN_VA(0x40E5D3u));
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->ebx + 0x24u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E5E7u)); sfera_sub_0040FCF0(cpu, LIFT_CODE_TOKEN_VA(0x40E5E7u));
    cpu->edi = lift_pop32(cpu);
    label_0000E5E8:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040E5F0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    x87_v0 = (double)*(float*)(cpu->ebx + 0x28u);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->ebx + 8u))));
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0x24u);
    if ((int32_t)cpu->eax >= 0) goto label_0000E60B;
    x87_v1 = (x87_v1) + (((double)4294967296.0f));
    label_0000E60B:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u))));
    if ((int32_t)cpu->ecx >= 0) goto label_0000E61F;
    x87_v2 = (x87_v2) + (((double)4294967296.0f));
    label_0000E61F:
    x87_v1 = x87_v1 / x87_v2; 
    *(float*)(cpu->esp + 8u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 8u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (!(lift_left>lift_right)) goto label_0000E698; }
    cpu->eax = 0u;
    label_0000E634:
    if (cpu->esi >= 0x1FFFFFFFu) goto label_0000E644;
    ++cpu->eax;
    cpu->esi += cpu->esi;
    if ((int32_t)cpu->eax < (int32_t)3u) goto label_0000E634;
    label_0000E644:
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = cpu->ebx + 0x10u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    if (cpu->edi == cpu->edx) goto label_0000E672;
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->edx) goto label_0000E66F;
    lift_push32(cpu, cpu->ebp);
    (void)cpu;
    label_0000E660:
    cpu->ebp = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi) = cpu->ebp;
    cpu->eax += 4u;
    cpu->edi += 4u;
    if (cpu->eax != cpu->edx) goto label_0000E660;
    cpu->ebp = lift_pop32(cpu);
    label_0000E66F:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    label_0000E672:
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi + cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E683u)); sfera_sub_00408D90(cpu, LIFT_CODE_TOKEN_VA(0x40E683u));
    cpu->eax = cpu->esi + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebx + 0x20u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->ebx + 0x24u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E697u)); sfera_sub_0040FD40(cpu, LIFT_CODE_TOKEN_VA(0x40E697u));
    cpu->edi = lift_pop32(cpu);
    label_0000E698:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_0040E920(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->ecx) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 8u) = 0u;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 4u)) goto label_0000E953;
    lift_push32(cpu, cpu->edi);
    label_0000E940:
    cpu->edi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if (cpu->edi != *(uint32_t*)(cpu->esi + 4u)) goto label_0000E940;
    cpu->edi = lift_pop32(cpu);
    label_0000E953:
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E95Cu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x40E95Cu));
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040E960(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ebx;
    if (cpu->esi != *(uint32_t*)(cpu->eax)) goto label_0000E99E;
    if (*(uint32_t*)(cpu->esp + 0x1Cu) != cpu->eax) goto label_0000E99E;
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E983u)); sfera_sub_004BC130(cpu, LIFT_CODE_TOKEN_VA(0x40E983u));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40E98Cu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x40E98Cu));
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000E99E:
    if (cpu->esi == *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_0000EA92;
    lift_push32(cpu, cpu->ebp);
    label_0000E9B0:
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->edx = (uint32_t)(((uint64_t)0xCCCCCCCDu * (uint32_t)(cpu->ecx)) >> 32u);
    cpu->edx >>= 3u;
    cpu->ebp = 0u;
    ++cpu->edx;
    cpu->ebx = 0x811C9DC5u;
    if (cpu->ecx == 0u) goto label_0000E9F0;
    (void)cpu;
    label_0000E9D0:
    if (*(uint32_t*)(cpu->esi + 0x1Cu) < 0x10u) goto label_0000E9DB;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    goto label_0000E9DE;
    label_0000E9DB:
    cpu->eax = cpu->esi + 8u;
    label_0000E9DE:
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->eax + cpu->ebp));
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x1000193u);
    cpu->ebp += cpu->edx;
    cpu->ebx ^= cpu->eax;
    if (cpu->ebp < cpu->ecx) goto label_0000E9D0;
    label_0000E9F0:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x20u);
    cpu->eax = cpu->ecx;
    cpu->eax &= cpu->ebx;
    if (*(uint32_t*)(cpu->edx + 0x24u) > cpu->eax) goto label_0000EA09;
    cpu->ecx >>= 1u;
    cpu->ebx |= 0xFFFFFFFFu;
    cpu->ebx -= cpu->ecx;
    cpu->eax += cpu->ebx;
    label_0000EA09:
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x10u);
    sub_pred[0] = *(uint32_t*)(cpu->ecx + (cpu->eax * 8u) + 4u) == cpu->esi;
    cpu->ecx = cpu->ecx + (cpu->eax * 8u);
    if (!sub_pred[0]) goto label_0000EA32;
    if (*(uint32_t*)(cpu->ecx) != cpu->esi) goto label_0000EA2A;
    cpu->ebx = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x10u);
    cpu->ebx = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->ecx + (cpu->eax * 8u) + 4u) = cpu->ebx;
    goto label_0000EA3A;
    label_0000EA2A:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    goto label_0000EA3A;
    label_0000EA32:
    if (*(uint32_t*)(cpu->ecx) != cpu->esi) goto label_0000EA3A;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    label_0000EA3A:
    cpu->ebx = cpu->edx + 4u;
    if (cpu->esi == *(uint32_t*)(cpu->edx + 4u)) goto label_0000EA81;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0x1Cu) < 0x10u) goto label_0000EA63;
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->edx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0000EA63:
    *(uint32_t*)(cpu->esi + 0x1Cu) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x18u) = 0u;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->ebx + 4u);
    label_0000EA81:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->esi != cpu->eax) goto label_0000E9B0;
    cpu->ebp = lift_pop32(cpu);
    label_0000EA92:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040EAA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_0000EADA;
    if (cpu->edx != cpu->eax) goto label_0000EADA;
    cpu->ecx = cpu->esi + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EAC0u)); sfera_sub_0040A060(cpu, LIFT_CODE_TOKEN_VA(0x40EAC0u));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EAC9u)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x40EAC9u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000EADA:
    if (cpu->ecx == cpu->edx) goto label_0000EAFD;
    label_0000EAE0:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EAF3u)); sfera_sub_0040AB90(cpu, LIFT_CODE_TOKEN_VA(0x40EAF3u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x18u)) goto label_0000EAE0;
    label_0000EAFD:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040EB10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_0000EB3E;
    if (cpu->edx != cpu->eax) goto label_0000EB3E;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EB2Eu)); sfera_sub_0040E920(cpu, LIFT_CODE_TOKEN_VA(0x40EB2Eu));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000EB3E:
    if (cpu->ecx == cpu->edx) goto label_0000EB5F;
    label_0000EB42:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EB55u)); sfera_sub_00407BD0(cpu, LIFT_CODE_TOKEN_VA(0x40EB55u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x14u)) goto label_0000EB42;
    label_0000EB5F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040EB70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_0000EBAA;
    if (cpu->edx != cpu->eax) goto label_0000EBAA;
    cpu->ecx = cpu->esi + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EB90u)); sfera_sub_0040BB40(cpu, LIFT_CODE_TOKEN_VA(0x40EB90u));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EB99u)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x40EB99u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000EBAA:
    if (cpu->ecx == cpu->edx) goto label_0000EBCD;
    label_0000EBB0:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EBC3u)); sfera_sub_0040D820(cpu, LIFT_CODE_TOKEN_VA(0x40EBC3u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x18u)) goto label_0000EBB0;
    label_0000EBCD:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040EBE0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ebx;
    if (cpu->edi != *(uint32_t*)(cpu->eax)) goto label_0000EC1E;
    if (*(uint32_t*)(cpu->esp + 0x1Cu) != cpu->eax) goto label_0000EC1E;
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EC03u)); sfera_sub_0040BBA0(cpu, LIFT_CODE_TOKEN_VA(0x40EC03u));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EC0Cu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x40EC0Cu));
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000EC1E:
    if (cpu->edi == *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_0000ED30;
    lift_push32(cpu, cpu->ebp);
    label_0000EC30:
    cpu->edx = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x18u);
    cpu->edx = (uint32_t)(((uint64_t)0xCCCCCCCDu * (uint32_t)(cpu->ecx)) >> 32u);
    cpu->edx >>= 3u;
    cpu->ebp = 0u;
    ++cpu->edx;
    cpu->ebx = 0x811C9DC5u;
    if (cpu->ecx == 0u) goto label_0000EC70;
    (void)cpu;
    label_0000EC50:
    if (*(uint32_t*)(cpu->edi + 0x1Cu) < 0x10u) goto label_0000EC5B;
    cpu->eax = *(uint32_t*)(cpu->edi + 8u);
    goto label_0000EC5E;
    label_0000EC5B:
    cpu->eax = cpu->edi + 8u;
    label_0000EC5E:
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->eax + cpu->ebp));
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x1000193u);
    cpu->ebp += cpu->edx;
    cpu->ebx ^= cpu->eax;
    if (cpu->ebp < cpu->ecx) goto label_0000EC50;
    label_0000EC70:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x20u);
    cpu->eax = cpu->ecx;
    cpu->eax &= cpu->ebx;
    if (*(uint32_t*)(cpu->edx + 0x24u) > cpu->eax) goto label_0000EC89;
    cpu->ecx >>= 1u;
    cpu->ebx |= 0xFFFFFFFFu;
    cpu->ebx -= cpu->ecx;
    cpu->eax += cpu->ebx;
    label_0000EC89:
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x10u);
    sub_pred[0] = *(uint32_t*)(cpu->ecx + (cpu->eax * 8u) + 4u) == cpu->edi;
    cpu->ecx = cpu->ecx + (cpu->eax * 8u);
    if (!sub_pred[0]) goto label_0000ECB2;
    if (*(uint32_t*)(cpu->ecx) != cpu->edi) goto label_0000ECAA;
    cpu->ebx = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x10u);
    cpu->ebx = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->ecx + (cpu->eax * 8u) + 4u) = cpu->ebx;
    goto label_0000ECBA;
    label_0000ECAA:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    goto label_0000ECBA;
    label_0000ECB2:
    if (*(uint32_t*)(cpu->ecx) != cpu->edi) goto label_0000ECBA;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    label_0000ECBA:
    cpu->ebx = cpu->edx + 4u;
    if (cpu->edi == *(uint32_t*)(cpu->edx + 4u)) goto label_0000ED1F;
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    if (*(uint32_t*)(cpu->edi + 0x38u) < 0x10u) goto label_0000ECE3;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x24u);
    lift_push32(cpu, cpu->edx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0000ECE3:
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->edi + 0x38u) = 0xFu;
    *(uint32_t*)(cpu->edi + 0x34u) = cpu->ebp;
    *(uint8_t*)(cpu->edi + 0x24u) = 0u;
    if (*(uint32_t*)(cpu->edi + 0x1Cu) < 0x10u) goto label_0000ED05;
    cpu->eax = *(uint32_t*)(cpu->edi + 8u);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_0000ED05:
    *(uint32_t*)(cpu->edi + 0x1Cu) = 0xFu;
    *(uint32_t*)(cpu->edi + 0x18u) = cpu->ebp;
    lift_push32(cpu, cpu->edi);
    *(uint8_t*)(cpu->edi + 8u) = 0u;
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->ebx + 4u);
    label_0000ED1F:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->edi != cpu->ecx) goto label_0000EC30;
    cpu->ebp = lift_pop32(cpu);
    label_0000ED30:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040ED40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_0000ED7A;
    if (cpu->edx != cpu->eax) goto label_0000ED7A;
    cpu->ecx = cpu->esi + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40ED60u)); sfera_sub_00408A50(cpu, LIFT_CODE_TOKEN_VA(0x40ED60u));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40ED69u)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x40ED69u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000ED7A:
    if (cpu->ecx == cpu->edx) goto label_0000ED9D;
    label_0000ED80:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40ED93u)); sfera_sub_0040A180(cpu, LIFT_CODE_TOKEN_VA(0x40ED93u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x18u)) goto label_0000ED80;
    label_0000ED9D:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040EDB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_0000EDEA;
    if (cpu->edx != cpu->eax) goto label_0000EDEA;
    cpu->ecx = cpu->esi + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EDD0u)); sfera_sub_0040BC20(cpu, LIFT_CODE_TOKEN_VA(0x40EDD0u));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EDD9u)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x40EDD9u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000EDEA:
    if (cpu->ecx == cpu->edx) goto label_0000EE0D;
    label_0000EDF0:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EE03u)); sfera_sub_0040D8C0(cpu, LIFT_CODE_TOKEN_VA(0x40EE03u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x18u)) goto label_0000EDF0;
    label_0000EE0D:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040EE20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_0000EE5A;
    if (cpu->edx != cpu->eax) goto label_0000EE5A;
    cpu->ecx = cpu->esi + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EE40u)); sfera_sub_0040A0C0(cpu, LIFT_CODE_TOKEN_VA(0x40EE40u));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EE49u)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x40EE49u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000EE5A:
    if (cpu->ecx == cpu->edx) goto label_0000EE7D;
    label_0000EE60:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EE73u)); sfera_sub_0040AC20(cpu, LIFT_CODE_TOKEN_VA(0x40EE73u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x18u)) goto label_0000EE60;
    label_0000EE7D:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040EE90(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->edi + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->edi + 8u);
    cpu->edx += cpu->eax;
    cpu->esi = 0x811C9DC5u;
    if (cpu->eax == cpu->edx) goto label_0000EEC1;
    lift_push32(cpu, cpu->ebx);
    label_0000EEB0:
    cpu->ebx = (int8_t)(*(uint8_t*)(cpu->eax));
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x1000193u);
    ++cpu->eax;
    cpu->esi ^= cpu->ebx;
    if (cpu->eax != cpu->edx) goto label_0000EEB0;
    cpu->ebx = lift_pop32(cpu);
    label_0000EEC1:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    cpu->eax = cpu->edx;
    cpu->eax &= cpu->esi;
    if (*(uint32_t*)(cpu->ecx + 0x24u) > cpu->eax) goto label_0000EED6;
    cpu->edx >>= 1u;
    cpu->esi |= 0xFFFFFFFFu;
    cpu->esi -= cpu->edx;
    cpu->eax += cpu->esi;
    label_0000EED6:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x10u);
    sub_pred[0] = *(uint32_t*)(cpu->edx + (cpu->eax * 8u) + 4u) == cpu->edi;
    cpu->edx = cpu->edx + (cpu->eax * 8u);
    if (!sub_pred[0]) goto label_0000EEFF;
    if (*(uint32_t*)(cpu->edx) != cpu->edi) goto label_0000EEF7;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx) = cpu->esi;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx + (cpu->eax * 8u) + 4u) = cpu->esi;
    goto label_0000EF07;
    label_0000EEF7:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    goto label_0000EF07;
    label_0000EEFF:
    if (*(uint32_t*)(cpu->edx) != cpu->edi) goto label_0000EF0B;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    label_0000EF07:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000EF0B:
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx += 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EF19u)); sfera_sub_0040D950(cpu, LIFT_CODE_TOKEN_VA(0x40EF19u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040EF20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, 0x1F31Du); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ldiv), LIFT_CODE_TOKEN_VA(0x40EF32u));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x41A7u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xB14u);
    cpu->esp += 8u;
    if ((int32_t)(cpu->edx -= cpu->eax) >= 0) goto label_0000EF51;
    cpu->edx += 0x7FFFFFFFu;
    label_0000EF51:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x20u);
    cpu->ebx = cpu->eax;
    cpu->ebx &= cpu->edx;
    if (*(uint32_t*)(cpu->ebp + 0x24u) > cpu->ebx) goto label_0000EF66;
    cpu->eax >>= 1u;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->eax;
    cpu->ebx += cpu->edx;
    label_0000EF66:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->ebx * 8u));
    cpu->esi = *(uint32_t*)(cpu->ebp + 4u);
    cpu->eax = cpu->eax + (cpu->ebx * 8u);
    cpu->edi = cpu->ebp + 4u;
    if (cpu->esi == cpu->ecx) goto label_0000EF94;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    if (cpu->esi == cpu->ecx) goto label_0000EF94;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000EF88:
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->esi + 8u) == cpu->eax) goto label_0000EFCA;
    if (cpu->esi != cpu->ecx) goto label_0000EF88;
    label_0000EF94:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (cpu->esi == cpu->eax) goto label_0000EFAF;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40EFABu)); sfera_sub_004039D0(cpu, LIFT_CODE_TOKEN_VA(0x40EFABu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_0000EFAF:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->eax = cpu->edx + (cpu->ebx * 8u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    if (cpu->edx != *(uint32_t*)(cpu->edi)) goto label_0000EFFE;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->eax + (cpu->ebx * 8u) + 4u) = cpu->ecx;
    goto label_0000F024;
    label_0000EFCA:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->eax == *(uint32_t*)(cpu->edi)) goto label_0000EFED;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ebx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edx) = cpu->ebx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    --*(uint32_t*)(cpu->edi + 4u);
    label_0000EFED:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000EFFE:
    if (cpu->edx != cpu->esi) goto label_0000F006;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    goto label_0000F024;
    label_0000F006:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    if (cpu->ecx == *(uint32_t*)(cpu->esp + 0x18u)) goto label_0000F024;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->ebx * 8u) + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = cpu->eax + (cpu->ebx * 8u) + 4u;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0000F024:
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F02Bu)); sfera_sub_0040E070(cpu, LIFT_CODE_TOKEN_VA(0x40F02Bu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040F040(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edx = 0x811C9DC5u;
    if (cpu->eax == cpu->ecx) goto label_0000F070;
    label_0000F060:
    cpu->esi = (int8_t)(*(uint8_t*)(cpu->eax));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1000193u);
    ++cpu->eax;
    cpu->edx ^= cpu->esi;
    if (cpu->eax != cpu->ecx) goto label_0000F060;
    label_0000F070:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x20u);
    cpu->edi = cpu->eax;
    cpu->edi &= cpu->edx;
    if (*(uint32_t*)(cpu->ebx + 0x24u) > cpu->edi) goto label_0000F085;
    cpu->eax >>= 1u;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->eax;
    cpu->edi += cpu->ecx;
    label_0000F085:
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->edi * 8u));
    cpu->esi = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = cpu->edx + (cpu->edi * 8u);
    cpu->ebp = cpu->ebx + 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->esi == cpu->ecx) goto label_0000F0BF;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->ecx) goto label_0000F0BF;
    label_0000F0A5:
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = cpu->esi + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F0B5u)); sfera_sub_00401D30(cpu, LIFT_CODE_TOKEN_VA(0x40F0B5u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_0000F0F6;
    if (cpu->esi != *(uint32_t*)(cpu->esp + 0x10u)) goto label_0000F0A5;
    label_0000F0BF:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (cpu->esi == cpu->eax) goto label_0000F0DA;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F0D6u)); sfera_sub_00404EF0(cpu, LIFT_CODE_TOKEN_VA(0x40F0D6u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    label_0000F0DA:
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->eax = cpu->edx + (cpu->edi * 8u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    if (cpu->edx != *(uint32_t*)(cpu->ebp)) goto label_0000F12E;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x10u);
    *(uint32_t*)(cpu->eax + (cpu->edi * 8u) + 4u) = cpu->ecx;
    goto label_0000F154;
    label_0000F0F6:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F103u)); sfera_sub_00401D30(cpu, LIFT_CODE_TOKEN_VA(0x40F103u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_0000F10B;
    cpu->esi = *(uint32_t*)(cpu->esi);
    goto label_0000F0BF;
    label_0000F10B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F11Cu)); sfera_sub_00406BA0(cpu, LIFT_CODE_TOKEN_VA(0x40F11Cu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000F12E:
    if (cpu->edx != cpu->esi) goto label_0000F136;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    goto label_0000F154;
    label_0000F136:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    if (cpu->ecx == *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_0000F154;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->edi * 8u) + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = cpu->eax + (cpu->edi * 8u) + 4u;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0000F154:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F15Bu)); sfera_sub_0040E120(cpu, LIFT_CODE_TOKEN_VA(0x40F15Bu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040F180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x20u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F196u)); sfera_sub_00403170(cpu, LIFT_CODE_TOKEN_VA(0x40F196u));
    cpu->ebx = cpu->eax;
    cpu->ebx &= cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    if (*(uint32_t*)(cpu->ebp + 0x24u) > cpu->ebx) goto label_0000F1B0;
    cpu->esi >>= 1u;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->esi;
    cpu->ebx += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    label_0000F1B0:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ebx * 8u));
    cpu->esi = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edi = cpu->ebp + 4u;
    cpu->eax = cpu->edx + (cpu->ebx * 8u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    if (cpu->esi == cpu->ecx) goto label_0000F232;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->ecx) goto label_0000F232;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x14u);
    cpu->ebx = *(uint32_t*)(cpu->eax + 0x10u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    label_0000F1E2:
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = cpu->esi + 8u;
    if (*(uint32_t*)(cpu->esi + 0x1Cu) < 0x10u) goto label_0000F1F3;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000F1F3:
    cpu->edx = cpu->ebx;
    if (cpu->ebx < cpu->edi) goto label_0000F1FB;
    cpu->edx = cpu->edi;
    label_0000F1FB:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    if (*(uint32_t*)(cpu->esp + 0x18u) < 0x10u) goto label_0000F208;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_0000F208:
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F210u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x40F210u));
    cpu->esp += 0xCu;
    if (cpu->eax != 0u) goto label_0000F224;
    if (cpu->ebx < cpu->edi) goto label_0000F224;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->ebx != cpu->edi);
    if (cpu->eax == 0u) goto label_0000F265;
    label_0000F224:
    if (cpu->esi != *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_0000F1E2;
    label_0000F22A:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000F232:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (cpu->esi == cpu->eax) goto label_0000F24D;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F249u)); sfera_sub_00403A60(cpu, LIFT_CODE_TOKEN_VA(0x40F249u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_0000F24D:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->eax + (cpu->ebx * 8u));
    cpu->eax = cpu->eax + (cpu->ebx * 8u);
    if (cpu->edx != *(uint32_t*)(cpu->edi)) goto label_0000F2B7;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->edx + (cpu->ebx * 8u) + 4u) = cpu->ecx;
    goto label_0000F2DB;
    label_0000F265:
    cpu->ecx = cpu->esi + 8u;
    if (*(uint32_t*)(cpu->esp + 0x18u) < 0x10u) goto label_0000F277;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    goto label_0000F27B;
    label_0000F277:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    label_0000F27B:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F288u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x40F288u));
    if (cpu->eax == 0u) goto label_0000F290;
    cpu->esi = *(uint32_t*)(cpu->esi);
    goto label_0000F22A;
    label_0000F290:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F2A3u)); sfera_sub_0040A680(cpu, LIFT_CODE_TOKEN_VA(0x40F2A3u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000F2B7:
    if (cpu->edx != cpu->esi) goto label_0000F2BF;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    goto label_0000F2DB;
    label_0000F2BF:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    if (cpu->edx == cpu->ecx) goto label_0000F2DB;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->ebx * 8u) + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = cpu->eax + (cpu->ebx * 8u) + 4u;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0000F2DB:
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F2E2u)); sfera_sub_0040E1D0(cpu, LIFT_CODE_TOKEN_VA(0x40F2E2u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040F300(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, 0x1F31Du); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ldiv), LIFT_CODE_TOKEN_VA(0x40F312u));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x41A7u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xB14u);
    cpu->esp += 8u;
    if ((int32_t)(cpu->edx -= cpu->eax) >= 0) goto label_0000F331;
    cpu->edx += 0x7FFFFFFFu;
    label_0000F331:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x20u);
    cpu->ebx = cpu->eax;
    cpu->ebx &= cpu->edx;
    if (*(uint32_t*)(cpu->edi + 0x24u) > cpu->ebx) goto label_0000F346;
    cpu->eax >>= 1u;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->eax;
    cpu->ebx += cpu->edx;
    label_0000F346:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->ebx * 8u));
    cpu->esi = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = cpu->eax + (cpu->ebx * 8u);
    cpu->ebp = cpu->edi + 4u;
    if (cpu->esi == cpu->ecx) goto label_0000F374;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    if (cpu->esi == cpu->ecx) goto label_0000F374;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000F368:
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->esi + 8u) == cpu->eax) goto label_0000F3B0;
    if (cpu->esi != cpu->ecx) goto label_0000F368;
    label_0000F374:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (cpu->esi == cpu->eax) goto label_0000F38F;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F38Bu)); sfera_sub_00403A60(cpu, LIFT_CODE_TOKEN_VA(0x40F38Bu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_0000F38F:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->eax + (cpu->ebx * 8u));
    cpu->eax = cpu->eax + (cpu->ebx * 8u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    if (cpu->edx != *(uint32_t*)(cpu->ebp)) goto label_0000F3D2;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x10u);
    *(uint32_t*)(cpu->ecx + (cpu->ebx * 8u) + 4u) = cpu->edx;
    goto label_0000F3F8;
    label_0000F3B0:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F3C1u)); sfera_sub_0040C700(cpu, LIFT_CODE_TOKEN_VA(0x40F3C1u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000F3D2:
    if (cpu->edx != cpu->esi) goto label_0000F3DA;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    goto label_0000F3F8;
    label_0000F3DA:
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    if (cpu->ecx == *(uint32_t*)(cpu->esp + 0x18u)) goto label_0000F3F8;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ebx * 8u) + 4u);
    cpu->eax = cpu->edx + (cpu->ebx * 8u) + 4u;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0000F3F8:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F3FFu)); sfera_sub_0040E280(cpu, LIFT_CODE_TOKEN_VA(0x40F3FFu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040F420(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x20u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F436u)); sfera_sub_00403170(cpu, LIFT_CODE_TOKEN_VA(0x40F436u));
    cpu->ebx = cpu->eax;
    cpu->ebx &= cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    if (*(uint32_t*)(cpu->ebp + 0x24u) > cpu->ebx) goto label_0000F450;
    cpu->esi >>= 1u;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->esi;
    cpu->ebx += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    label_0000F450:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ebx * 8u));
    cpu->esi = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edi = cpu->ebp + 4u;
    cpu->eax = cpu->edx + (cpu->ebx * 8u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    if (cpu->esi == cpu->ecx) goto label_0000F4D2;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->ecx) goto label_0000F4D2;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x14u);
    cpu->ebx = *(uint32_t*)(cpu->eax + 0x10u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    label_0000F482:
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = cpu->esi + 8u;
    if (*(uint32_t*)(cpu->esi + 0x1Cu) < 0x10u) goto label_0000F493;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000F493:
    cpu->edx = cpu->ebx;
    if (cpu->ebx < cpu->edi) goto label_0000F49B;
    cpu->edx = cpu->edi;
    label_0000F49B:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    if (*(uint32_t*)(cpu->esp + 0x18u) < 0x10u) goto label_0000F4A8;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_0000F4A8:
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F4B0u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x40F4B0u));
    cpu->esp += 0xCu;
    if (cpu->eax != 0u) goto label_0000F4C4;
    if (cpu->ebx < cpu->edi) goto label_0000F4C4;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->ebx != cpu->edi);
    if (cpu->eax == 0u) goto label_0000F505;
    label_0000F4C4:
    if (cpu->esi != *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_0000F482;
    label_0000F4CA:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000F4D2:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (cpu->esi == cpu->eax) goto label_0000F4ED;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F4E9u)); sfera_sub_00403AF0(cpu, LIFT_CODE_TOKEN_VA(0x40F4E9u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_0000F4ED:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->eax + (cpu->ebx * 8u));
    cpu->eax = cpu->eax + (cpu->ebx * 8u);
    if (cpu->edx != *(uint32_t*)(cpu->edi)) goto label_0000F557;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->edx + (cpu->ebx * 8u) + 4u) = cpu->ecx;
    goto label_0000F57B;
    label_0000F505:
    cpu->ecx = cpu->esi + 8u;
    if (*(uint32_t*)(cpu->esp + 0x18u) < 0x10u) goto label_0000F517;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    goto label_0000F51B;
    label_0000F517:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    label_0000F51B:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F528u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x40F528u));
    if (cpu->eax == 0u) goto label_0000F530;
    cpu->esi = *(uint32_t*)(cpu->esi);
    goto label_0000F4CA;
    label_0000F530:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F543u)); sfera_sub_0040C770(cpu, LIFT_CODE_TOKEN_VA(0x40F543u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000F557:
    if (cpu->edx != cpu->esi) goto label_0000F55F;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    goto label_0000F57B;
    label_0000F55F:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    if (cpu->edx == cpu->ecx) goto label_0000F57B;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->ebx * 8u) + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = cpu->eax + (cpu->ebx * 8u) + 4u;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0000F57B:
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F582u)); sfera_sub_0040E330(cpu, LIFT_CODE_TOKEN_VA(0x40F582u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040F5A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edx = 0x811C9DC5u;
    if (cpu->eax == cpu->ecx) goto label_0000F5D0;
    label_0000F5C0:
    cpu->esi = (int8_t)(*(uint8_t*)(cpu->eax));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1000193u);
    ++cpu->eax;
    cpu->edx ^= cpu->esi;
    if (cpu->eax != cpu->ecx) goto label_0000F5C0;
    label_0000F5D0:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x20u);
    cpu->edi = cpu->eax;
    cpu->edi &= cpu->edx;
    if (*(uint32_t*)(cpu->ebx + 0x24u) > cpu->edi) goto label_0000F5E5;
    cpu->eax >>= 1u;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->eax;
    cpu->edi += cpu->ecx;
    label_0000F5E5:
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->edi * 8u));
    cpu->esi = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = cpu->edx + (cpu->edi * 8u);
    cpu->ebp = cpu->ebx + 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->esi == cpu->ecx) goto label_0000F61F;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->ecx) goto label_0000F61F;
    label_0000F605:
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = cpu->esi + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F615u)); sfera_sub_00401D30(cpu, LIFT_CODE_TOKEN_VA(0x40F615u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_0000F656;
    if (cpu->esi != *(uint32_t*)(cpu->esp + 0x10u)) goto label_0000F605;
    label_0000F61F:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (cpu->esi == cpu->eax) goto label_0000F63A;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F636u)); sfera_sub_00403B80(cpu, LIFT_CODE_TOKEN_VA(0x40F636u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    label_0000F63A:
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->eax = cpu->edx + (cpu->edi * 8u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    if (cpu->edx != *(uint32_t*)(cpu->ebp)) goto label_0000F68E;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x10u);
    *(uint32_t*)(cpu->eax + (cpu->edi * 8u) + 4u) = cpu->ecx;
    goto label_0000F6B4;
    label_0000F656:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F663u)); sfera_sub_00401D30(cpu, LIFT_CODE_TOKEN_VA(0x40F663u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_0000F66B;
    cpu->esi = *(uint32_t*)(cpu->esi);
    goto label_0000F61F;
    label_0000F66B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F67Cu)); sfera_sub_0040D950(cpu, LIFT_CODE_TOKEN_VA(0x40F67Cu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000F68E:
    if (cpu->edx != cpu->esi) goto label_0000F696;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    goto label_0000F6B4;
    label_0000F696:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    if (cpu->ecx == *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_0000F6B4;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->edi * 8u) + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = cpu->eax + (cpu->edi * 8u) + 4u;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0000F6B4:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F6BBu)); sfera_sub_0040E3E0(cpu, LIFT_CODE_TOKEN_VA(0x40F6BBu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040F6E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, 0x1F31Du); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ldiv), LIFT_CODE_TOKEN_VA(0x40F6F2u));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x41A7u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xB14u);
    cpu->esp += 8u;
    if ((int32_t)(cpu->edx -= cpu->eax) >= 0) goto label_0000F711;
    cpu->edx += 0x7FFFFFFFu;
    label_0000F711:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x20u);
    cpu->ebx = cpu->eax;
    cpu->ebx &= cpu->edx;
    if (*(uint32_t*)(cpu->edi + 0x24u) > cpu->ebx) goto label_0000F726;
    cpu->eax >>= 1u;
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->eax;
    cpu->ebx += cpu->edx;
    label_0000F726:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->ebx * 8u));
    cpu->esi = *(uint32_t*)(cpu->edi + 4u);
    cpu->eax = cpu->eax + (cpu->ebx * 8u);
    cpu->ebp = cpu->edi + 4u;
    if (cpu->esi == cpu->ecx) goto label_0000F754;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    if (cpu->esi == cpu->ecx) goto label_0000F754;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000F748:
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->esi + 8u) == cpu->eax) goto label_0000F790;
    if (cpu->esi != cpu->ecx) goto label_0000F748;
    label_0000F754:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (cpu->esi == cpu->eax) goto label_0000F76F;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F76Bu)); sfera_sub_00404EF0(cpu, LIFT_CODE_TOKEN_VA(0x40F76Bu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_0000F76F:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->eax + (cpu->ebx * 8u));
    cpu->eax = cpu->eax + (cpu->ebx * 8u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    if (cpu->edx != *(uint32_t*)(cpu->ebp)) goto label_0000F7B2;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x10u);
    *(uint32_t*)(cpu->ecx + (cpu->ebx * 8u) + 4u) = cpu->edx;
    goto label_0000F7D8;
    label_0000F790:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F7A1u)); sfera_sub_00408D20(cpu, LIFT_CODE_TOKEN_VA(0x40F7A1u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000F7B2:
    if (cpu->edx != cpu->esi) goto label_0000F7BA;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    goto label_0000F7D8;
    label_0000F7BA:
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    if (cpu->ecx == *(uint32_t*)(cpu->esp + 0x18u)) goto label_0000F7D8;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ebx * 8u) + 4u);
    cpu->eax = cpu->edx + (cpu->ebx * 8u) + 4u;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0000F7D8:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F7DFu)); sfera_sub_0040E490(cpu, LIFT_CODE_TOKEN_VA(0x40F7DFu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040F800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->ebp + 0x20u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F816u)); sfera_sub_00403170(cpu, LIFT_CODE_TOKEN_VA(0x40F816u));
    cpu->ebx = cpu->eax;
    cpu->ebx &= cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    if (*(uint32_t*)(cpu->ebp + 0x24u) > cpu->ebx) goto label_0000F830;
    cpu->esi >>= 1u;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->esi;
    cpu->ebx += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    label_0000F830:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ebx * 8u));
    cpu->esi = *(uint32_t*)(cpu->ebp + 4u);
    cpu->edi = cpu->ebp + 4u;
    cpu->eax = cpu->edx + (cpu->ebx * 8u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    if (cpu->esi == cpu->ecx) goto label_0000F8B2;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->ecx) goto label_0000F8B2;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x14u);
    cpu->ebx = *(uint32_t*)(cpu->eax + 0x10u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    label_0000F862:
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = cpu->esi + 8u;
    if (*(uint32_t*)(cpu->esi + 0x1Cu) < 0x10u) goto label_0000F873;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0000F873:
    cpu->edx = cpu->ebx;
    if (cpu->ebx < cpu->edi) goto label_0000F87B;
    cpu->edx = cpu->edi;
    label_0000F87B:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    if (*(uint32_t*)(cpu->esp + 0x18u) < 0x10u) goto label_0000F888;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_0000F888:
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F890u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x40F890u));
    cpu->esp += 0xCu;
    if (cpu->eax != 0u) goto label_0000F8A4;
    if (cpu->ebx < cpu->edi) goto label_0000F8A4;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->ebx != cpu->edi);
    if (cpu->eax == 0u) goto label_0000F8E5;
    label_0000F8A4:
    if (cpu->esi != *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_0000F862;
    label_0000F8AA:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0000F8B2:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (cpu->esi == cpu->eax) goto label_0000F8CD;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F8C9u)); sfera_sub_00403B80(cpu, LIFT_CODE_TOKEN_VA(0x40F8C9u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_0000F8CD:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->eax + (cpu->ebx * 8u));
    cpu->eax = cpu->eax + (cpu->ebx * 8u);
    if (cpu->edx != *(uint32_t*)(cpu->edi)) goto label_0000F937;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->edx + (cpu->ebx * 8u) + 4u) = cpu->ecx;
    goto label_0000F95B;
    label_0000F8E5:
    cpu->ecx = cpu->esi + 8u;
    if (*(uint32_t*)(cpu->esp + 0x18u) < 0x10u) goto label_0000F8F7;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    goto label_0000F8FB;
    label_0000F8F7:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    label_0000F8FB:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F908u)); sfera_sub_004027A0(cpu, LIFT_CODE_TOKEN_VA(0x40F908u));
    if (cpu->eax == 0u) goto label_0000F910;
    cpu->esi = *(uint32_t*)(cpu->esi);
    goto label_0000F8AA;
    label_0000F910:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F923u)); sfera_sub_0040C7F0(cpu, LIFT_CODE_TOKEN_VA(0x40F923u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000F937:
    if (cpu->edx != cpu->esi) goto label_0000F93F;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    goto label_0000F95B;
    label_0000F93F:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    if (cpu->edx == cpu->ecx) goto label_0000F95B;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->ebx * 8u) + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = cpu->eax + (cpu->ebx * 8u) + 4u;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0000F95B:
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F962u)); sfera_sub_0040E540(cpu, LIFT_CODE_TOKEN_VA(0x40F962u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040F980(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edx = 0x811C9DC5u;
    if (cpu->eax == cpu->ecx) goto label_0000F9B0;
    label_0000F9A0:
    cpu->esi = (int8_t)(*(uint8_t*)(cpu->eax));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1000193u);
    ++cpu->eax;
    cpu->edx ^= cpu->esi;
    if (cpu->eax != cpu->ecx) goto label_0000F9A0;
    label_0000F9B0:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x20u);
    cpu->edi = cpu->eax;
    cpu->edi &= cpu->edx;
    if (*(uint32_t*)(cpu->ebx + 0x24u) > cpu->edi) goto label_0000F9C5;
    cpu->eax >>= 1u;
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->eax;
    cpu->edi += cpu->ecx;
    label_0000F9C5:
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->edi * 8u));
    cpu->esi = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = cpu->edx + (cpu->edi * 8u);
    cpu->ebp = cpu->ebx + 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    if (cpu->esi == cpu->ecx) goto label_0000F9FF;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (cpu->esi == cpu->ecx) goto label_0000F9FF;
    label_0000F9E5:
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = cpu->esi + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40F9F5u)); sfera_sub_00401D30(cpu, LIFT_CODE_TOKEN_VA(0x40F9F5u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_0000FA36;
    if (cpu->esi != *(uint32_t*)(cpu->esp + 0x10u)) goto label_0000F9E5;
    label_0000F9FF:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (cpu->esi == cpu->eax) goto label_0000FA1A;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FA16u)); sfera_sub_00404F80(cpu, LIFT_CODE_TOKEN_VA(0x40FA16u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    label_0000FA1A:
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->eax = cpu->edx + (cpu->edi * 8u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    if (cpu->edx != *(uint32_t*)(cpu->ebp)) goto label_0000FA6E;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x10u);
    *(uint32_t*)(cpu->eax + (cpu->edi * 8u) + 4u) = cpu->ecx;
    goto label_0000FA94;
    label_0000FA36:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FA43u)); sfera_sub_00401D30(cpu, LIFT_CODE_TOKEN_VA(0x40FA43u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_0000FA4B;
    cpu->esi = *(uint32_t*)(cpu->esi);
    goto label_0000F9FF;
    label_0000FA4B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FA5Cu)); sfera_sub_0040A220(cpu, LIFT_CODE_TOKEN_VA(0x40FA5Cu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000FA6E:
    if (cpu->edx != cpu->esi) goto label_0000FA76;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    goto label_0000FA94;
    label_0000FA76:
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    if (cpu->ecx == *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_0000FA94;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->edi * 8u) + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = cpu->eax + (cpu->edi * 8u) + 4u;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0000FA94:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FA9Bu)); sfera_sub_0040E5F0(cpu, LIFT_CODE_TOKEN_VA(0x40FA9Bu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040FAC0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->ecx) == cpu->eax) goto label_0000FB02;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    lift_push32(cpu, cpu->ebx);
    label_0000FAE0:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (sub_pred[0]);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FAFDu)); sfera_sub_0040EF20(cpu, LIFT_CODE_TOKEN_VA(0x40FAFDu));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_0000FAE0;
    cpu->ebx = lift_pop32(cpu);
    label_0000FB02:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040FB10(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->ecx) == cpu->eax) goto label_0000FB52;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    lift_push32(cpu, cpu->ebx);
    label_0000FB30:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (sub_pred[0]);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FB4Du)); sfera_sub_0040F040(cpu, LIFT_CODE_TOKEN_VA(0x40FB4Du));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_0000FB30;
    cpu->ebx = lift_pop32(cpu);
    label_0000FB52:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040FB60(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->ecx) == cpu->eax) goto label_0000FBA2;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    lift_push32(cpu, cpu->ebx);
    label_0000FB80:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (sub_pred[0]);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FB9Du)); sfera_sub_0040F180(cpu, LIFT_CODE_TOKEN_VA(0x40FB9Du));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_0000FB80;
    cpu->ebx = lift_pop32(cpu);
    label_0000FBA2:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040FBB0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->ecx) == cpu->eax) goto label_0000FBF2;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    lift_push32(cpu, cpu->ebx);
    label_0000FBD0:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (sub_pred[0]);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FBEDu)); sfera_sub_0040F300(cpu, LIFT_CODE_TOKEN_VA(0x40FBEDu));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_0000FBD0;
    cpu->ebx = lift_pop32(cpu);
    label_0000FBF2:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040FC00(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->ecx) == cpu->eax) goto label_0000FC42;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    lift_push32(cpu, cpu->ebx);
    label_0000FC20:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (sub_pred[0]);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FC3Du)); sfera_sub_0040F420(cpu, LIFT_CODE_TOKEN_VA(0x40FC3Du));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_0000FC20;
    cpu->ebx = lift_pop32(cpu);
    label_0000FC42:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040FC50(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->ecx) == cpu->eax) goto label_0000FC92;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    lift_push32(cpu, cpu->ebx);
    label_0000FC70:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (sub_pred[0]);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FC8Du)); sfera_sub_0040F5A0(cpu, LIFT_CODE_TOKEN_VA(0x40FC8Du));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_0000FC70;
    cpu->ebx = lift_pop32(cpu);
    label_0000FC92:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040FCA0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->ecx) == cpu->eax) goto label_0000FCE2;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    lift_push32(cpu, cpu->ebx);
    label_0000FCC0:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (sub_pred[0]);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FCDDu)); sfera_sub_0040F6E0(cpu, LIFT_CODE_TOKEN_VA(0x40FCDDu));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_0000FCC0;
    cpu->ebx = lift_pop32(cpu);
    label_0000FCE2:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040FCF0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->ecx) == cpu->eax) goto label_0000FD32;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    lift_push32(cpu, cpu->ebx);
    label_0000FD10:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (sub_pred[0]);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FD2Du)); sfera_sub_0040F800(cpu, LIFT_CODE_TOKEN_VA(0x40FD2Du));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_0000FD10;
    cpu->ebx = lift_pop32(cpu);
    label_0000FD32:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040FD40(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->ecx) == cpu->eax) goto label_0000FD82;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    lift_push32(cpu, cpu->ebx);
    label_0000FD60:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    sub_pred[0] = cpu->eax == *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (sub_pred[0]);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FD7Du)); sfera_sub_0040F980(cpu, LIFT_CODE_TOKEN_VA(0x40FD7Du));
    if ((cpu->ebx & 0xFFu) == 0u) goto label_0000FD60;
    cpu->ebx = lift_pop32(cpu);
    label_0000FD82:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0040FD90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    lift_push32(cpu, 0x28u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->edi = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edi;
    if (cpu->edi == cpu->eax) goto label_0000FE37;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->esi = cpu->edi + 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    *(uint32_t*)(cpu->edi) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->esi;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->esi == cpu->eax) goto label_0000FE0C;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FE06u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x40FE06u));
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x1Cu);
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->eax;
    label_0000FE0C:
    cpu->eax = cpu->edi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000FE37:
    cpu->edx = cpu->ebp + 8u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FE5Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40FE5Cu));
    cpu->eip = 0x40FE5Cu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_0040FE60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    lift_push32(cpu, 0x28u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->edi = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edi;
    if (cpu->edi == cpu->eax) goto label_0000FF07;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->esi = cpu->edi + 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    *(uint32_t*)(cpu->edi) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->esi;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->esi == cpu->eax) goto label_0000FEDC;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FED6u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x40FED6u));
    *(float*)(cpu->esi + 0x1Cu) = (double)*(float*)(cpu->ebx + 0x1Cu);
    label_0000FEDC:
    cpu->eax = cpu->edi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000FF07:
    cpu->ecx = cpu->ebp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FF2Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40FF2Cu));
    cpu->eip = 0x40FF2Cu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_0040FF30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    lift_push32(cpu, 0x28u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esi = cpu->eax;
    cpu->ebx = 0u;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->esi;
    if (cpu->esi == cpu->ebx) goto label_0000FFD9;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->eax = cpu->esi + 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->eax;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->eax == cpu->ebx) goto label_0000FFAE;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = cpu->eax + 4u;
    cpu->edx += 4u;
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->ebx;
    lift_push32(cpu, cpu->edx);
    *(uint8_t*)(cpu->ecx) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0xFFAEu)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_RVA(0xFFAEu));
    label_0000FFAE:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0000FFD9:
    cpu->eax = cpu->ebp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x40FFFEu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x40FFFEu));
    cpu->eip = 0x40FFFEu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_00410000(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    lift_push32(cpu, 0x40u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->edi = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->edi;
    if (cpu->edi == cpu->eax) goto label_000100C6;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->esi = cpu->edi + 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    *(uint32_t*)(cpu->edi) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->esi;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->esi == cpu->eax) goto label_0001009B;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41007Au)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x41007Au));
    cpu->ecx = cpu->esi + 0x1Cu;
    cpu->ebx += 0x1Cu;
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = 0u;
    lift_push32(cpu, cpu->ebx);
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 2u;
    *(uint8_t*)(cpu->ecx) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x1009Bu)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_RVA(0x1009Bu));
    label_0001009B:
    cpu->eax = cpu->edi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000100C6:
    cpu->ecx = cpu->ebp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4100EBu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4100EBu));
    cpu->eip = 0x4100EBu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_004100F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    lift_push32(cpu, 0x2Cu);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->ebx = cpu->eax;
    cpu->eax = 0u;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->ebx;
    if (cpu->ebx == cpu->eax) goto label_000101A5;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->esi = cpu->ebx + 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->eax;
    *(uint32_t*)(cpu->ebx) = cpu->ecx;
    *(uint32_t*)(cpu->ebx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->esi;
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->esi;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->esi == cpu->eax) goto label_0001017A;
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410166u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x410166u));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x20u);
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x1Cu);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 0x1Cu) = cpu->eax;
    label_0001017A:
    cpu->eax = cpu->ebx;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000101A5:
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    cpu->eax = cpu->ebp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4101CAu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4101CAu));
    cpu->eip = 0x4101CAu; ::DebugBreak(); return;
}


__declspec(noinline) void sfera_sub_00410650(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->ecx) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x18u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->ebp + 0x1Cu) = 0u;
    if (cpu->eax == *(uint32_t*)(cpu->ebp + 0x18u)) goto label_00010683;
    lift_push32(cpu, cpu->edi);
    label_00010670:
    cpu->edi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if (cpu->edi != *(uint32_t*)(cpu->ebp + 0x18u)) goto label_00010670;
    cpu->edi = lift_pop32(cpu);
    label_00010683:
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->ebp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41068Du)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x41068Du));
    cpu->esi = lift_pop32(cpu);
    *(uint8_t*)(cpu->ebp + 8u) = 0u;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004106A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    if (cpu->ecx != *(uint32_t*)(cpu->eax)) goto label_000106DA;
    if (cpu->edx != cpu->eax) goto label_000106DA;
    cpu->ecx = cpu->esi + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4106C0u)); sfera_sub_0040D740(cpu, LIFT_CODE_TOKEN_VA(0x4106C0u));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4106C9u)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x4106C9u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000106DA:
    if (cpu->ecx == cpu->edx) goto label_000106FD;
    label_000106E0:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4106F3u)); sfera_sub_0040EE90(cpu, LIFT_CODE_TOKEN_VA(0x4106F3u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x18u)) goto label_000106E0;
    label_000106FD:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00410710(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41072Cu)); sfera_sub_004050B0(cpu, LIFT_CODE_TOKEN_VA(0x41072Cu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = 0x1FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_00010746;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410710u); throw std::length_error("std::length_error");
    label_00010746:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410768u)); sfera_sub_0040EF20(cpu, LIFT_CODE_TOKEN_VA(0x410768u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00410770(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41078Cu)); sfera_sub_00406690(cpu, LIFT_CODE_TOKEN_VA(0x41078Cu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = 0x15555554u;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_000107A6;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410770u); throw std::length_error("std::length_error");
    label_000107A6:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4107C8u)); sfera_sub_0040F040(cpu, LIFT_CODE_TOKEN_VA(0x4107C8u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004107D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4107ECu)); sfera_sub_00405120(cpu, LIFT_CODE_TOKEN_VA(0x4107ECu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = 0x1FFFFFFEu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_00010806;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4107D0u); throw std::length_error("std::length_error");
    label_00010806:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410828u)); sfera_sub_0040EF20(cpu, LIFT_CODE_TOKEN_VA(0x410828u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00410830(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41084Cu)); sfera_sub_00406710(cpu, LIFT_CODE_TOKEN_VA(0x41084Cu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = 0x15555554u;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_00010866;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410830u); throw std::length_error("std::length_error");
    label_00010866:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410888u)); sfera_sub_0040F040(cpu, LIFT_CODE_TOKEN_VA(0x410888u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00410890(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4108ACu)); sfera_sub_00405190(cpu, LIFT_CODE_TOKEN_VA(0x4108ACu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = 0x15555554u;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_000108C6;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x410890u); throw std::length_error("std::length_error");
    label_000108C6:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4108E8u)); sfera_sub_0040F6E0(cpu, LIFT_CODE_TOKEN_VA(0x4108E8u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004108F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41090Cu)); sfera_sub_00406790(cpu, LIFT_CODE_TOKEN_VA(0x41090Cu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = 0xFFFFFFEu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_00010926;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4108F0u); throw std::length_error("std::length_error");
    label_00010926:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410948u)); sfera_sub_0040F980(cpu, LIFT_CODE_TOKEN_VA(0x410948u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_00410DE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    lift_push32(cpu, 0x2Cu);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esi = cpu->eax;
    cpu->ebx = 0u;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->esi;
    if (cpu->esi == cpu->ebx) goto label_00010E98;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCu);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->eax = cpu->esi + 8u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xCu) = cpu->eax;
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 1u;
    if (cpu->eax == cpu->ebx) goto label_00010E6D;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->edx + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->edx) = cpu->ebx;
    cpu->ecx = cpu->eax + 8u;
    cpu->edx += 8u;
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->ebx;
    lift_push32(cpu, cpu->edx);
    *(uint8_t*)(cpu->ebp + 0xFFFFFFFCu) = 2u;
    *(uint8_t*)(cpu->ecx) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x10E6Du)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_RVA(0x10E6Du));
    label_00010E6D:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00010E98:
    cpu->eax = cpu->ebp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    *(uint32_t*)(cpu->ebp + 8u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp + 0xFFFFFFE0u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x410EBDu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x410EBDu));
    cpu->eip = 0x410EBDu; ::DebugBreak(); return;
}

__declspec(noinline) void sfera_sub_004110F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41110Cu)); sfera_sub_004079E0(cpu, LIFT_CODE_TOKEN_VA(0x41110Cu));
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->ecx) goto label_00011126;
    label_00011120:
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->ecx) goto label_00011120;
    label_00011126:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411134u)); sfera_sub_0040E960(cpu, LIFT_CODE_TOKEN_VA(0x411134u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41115Cu)); sfera_sub_004076E0(cpu, LIFT_CODE_TOKEN_VA(0x41115Cu));
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->ecx) goto label_00011176;
    label_00011170:
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->ecx) goto label_00011170;
    label_00011176:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411184u)); sfera_sub_0040EAA0(cpu, LIFT_CODE_TOKEN_VA(0x411184u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4111ACu)); sfera_sub_004077C0(cpu, LIFT_CODE_TOKEN_VA(0x4111ACu));
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->ecx) goto label_000111C6;
    label_000111C0:
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->ecx) goto label_000111C0;
    label_000111C6:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4111D4u)); sfera_sub_0040EB10(cpu, LIFT_CODE_TOKEN_VA(0x4111D4u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004111E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4111FCu)); sfera_sub_004077C0(cpu, LIFT_CODE_TOKEN_VA(0x4111FCu));
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->ecx) goto label_00011216;
    label_00011210:
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->ecx) goto label_00011210;
    label_00011216:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411224u)); sfera_sub_0040EB70(cpu, LIFT_CODE_TOKEN_VA(0x411224u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41124Cu)); sfera_sub_004079E0(cpu, LIFT_CODE_TOKEN_VA(0x41124Cu));
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->ecx) goto label_00011266;
    label_00011260:
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->ecx) goto label_00011260;
    label_00011266:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411274u)); sfera_sub_0040EBE0(cpu, LIFT_CODE_TOKEN_VA(0x411274u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41129Cu)); sfera_sub_004077C0(cpu, LIFT_CODE_TOKEN_VA(0x41129Cu));
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->ecx) goto label_000112B6;
    label_000112B0:
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->ecx) goto label_000112B0;
    label_000112B6:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4112C4u)); sfera_sub_0040ED40(cpu, LIFT_CODE_TOKEN_VA(0x4112C4u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004112D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4112ECu)); sfera_sub_004079E0(cpu, LIFT_CODE_TOKEN_VA(0x4112ECu));
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->ecx) goto label_00011306;
    label_00011300:
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->ecx) goto label_00011300;
    label_00011306:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411314u)); sfera_sub_0040EDB0(cpu, LIFT_CODE_TOKEN_VA(0x411314u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411320(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41133Cu)); sfera_sub_004076E0(cpu, LIFT_CODE_TOKEN_VA(0x41133Cu));
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->ecx) goto label_00011356;
    label_00011350:
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->ecx) goto label_00011350;
    label_00011356:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411364u)); sfera_sub_0040EE20(cpu, LIFT_CODE_TOKEN_VA(0x411364u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411370(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x20u;
    cpu->edi = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4113A6u)); sfera_sub_00407610(cpu, LIFT_CODE_TOKEN_VA(0x4113A6u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    if (cpu->ecx != *(uint32_t*)(cpu->edi + 4u)) goto label_0001142B;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = 0u;
    *(uint32_t*)(cpu->esi) = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x30u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4113EAu)); sfera_sub_00410770(cpu, LIFT_CODE_TOKEN_VA(0x4113EAu));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x28u) = 0xFFFFFFFFu;
    if (cpu->edi == 0u) goto label_00011414;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, cpu->edi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00011414:
    cpu->eax = cpu->esi + 0x10u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0001142B:
    cpu->eax = cpu->ecx + 0x10u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411450(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x20u;
    cpu->edi = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411486u)); sfera_sub_00407610(cpu, LIFT_CODE_TOKEN_VA(0x411486u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    if (cpu->ecx != *(uint32_t*)(cpu->edi + 4u)) goto label_00011509;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    x87_v0 = 0.0;
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = 0u;
    *(uint32_t*)(cpu->esi) = 0u;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x30u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4114C8u)); sfera_sub_00410830(cpu, LIFT_CODE_TOKEN_VA(0x4114C8u));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x28u) = 0xFFFFFFFFu;
    if (cpu->edi == 0u) goto label_000114F2;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, cpu->edi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_000114F2:
    cpu->eax = cpu->esi + 0x10u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00011509:
    cpu->eax = cpu->ecx + 0x10u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411520(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x2Cu;
    cpu->esi = cpu->ecx;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411557u)); sfera_sub_00407550(cpu, LIFT_CODE_TOKEN_VA(0x411557u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    if (cpu->ecx != *(uint32_t*)(cpu->esi + 4u)) goto label_000115CE;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x3Cu) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411592u)); sfera_sub_00410890(cpu, LIFT_CODE_TOKEN_VA(0x411592u));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint8_t*)(cpu->esp + 0x34u) = cpu->ebx & 0xFFu;
    if (cpu->edi == cpu->ebx) goto label_000115B6;
    cpu->edx = cpu->ebx + 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, cpu->edi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_000115B6:
    cpu->eax = cpu->esi + 0xCu;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x28u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000115CE:
    cpu->eax = cpu->ecx + 0xCu;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x28u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004115F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x30u;
    cpu->edi = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411627u)); sfera_sub_00407610(cpu, LIFT_CODE_TOKEN_VA(0x411627u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40u);
    if (cpu->ecx != *(uint32_t*)(cpu->edi + 4u)) goto label_00011695;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    *(uint8_t*)(cpu->esp + 0x40u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41166Eu)); sfera_sub_004108F0(cpu, LIFT_CODE_TOKEN_VA(0x41166Eu));
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint8_t*)(cpu->esp + 0x38u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41167Du)); sfera_sub_00402D20(cpu, LIFT_CODE_TOKEN_VA(0x41167Du));
    cpu->eax = cpu->esi + 0x10u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00011695:
    cpu->eax = cpu->ecx + 0x10u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_004117C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4117D9u)); sfera_sub_00407550(cpu, LIFT_CODE_TOKEN_VA(0x4117D9u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 4u)) goto label_00011803;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x14u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411801u)); sfera_sub_00410710(cpu, LIFT_CODE_TOKEN_VA(0x411801u));
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00011803:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edx;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411820(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411839u)); sfera_sub_00407550(cpu, LIFT_CODE_TOKEN_VA(0x411839u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 4u)) goto label_00011872;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    x87_v0 = 0.0;
    cpu->edx = cpu->esp + 8u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x14u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41185Fu)); sfera_sub_004107D0(cpu, LIFT_CODE_TOKEN_VA(0x41185Fu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->eax);
    x87_v0 = (double)*(float*)(cpu->ecx);
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->eax + 0xCu) = x87_v0; 
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00011872:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    x87_v0 = (double)*(float*)(cpu->edx);
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->eax + 0xCu) = x87_v0; 
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411890(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->ecx + 8u) = 0u;
    cpu->esi = cpu->ecx + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4118ACu)); sfera_sub_004076E0(cpu, LIFT_CODE_TOKEN_VA(0x4118ACu));
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = cpu->edx;
    if (cpu->edx == cpu->ecx) goto label_000118C6;
    label_000118C0:
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != cpu->ecx) goto label_000118C0;
    label_000118C6:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4118D4u)); sfera_sub_004106A0(cpu, LIFT_CODE_TOKEN_VA(0x4118D4u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004118E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx += 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4118EFu)); sfera_sub_00411520(cpu, LIFT_CODE_TOKEN_VA(0x4118EFu));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = cpu->eax;
    if (cpu->esi == cpu->edi) goto label_0001192B;
    cpu->edx = 0x46u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->edi + 4u) = 0u;
    *(uint32_t*)(cpu->edi) = 0u;
    label_0001192B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411930(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx += 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41193Fu)); sfera_sub_004115F0(cpu, LIFT_CODE_TOKEN_VA(0x41193Fu));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = cpu->eax;
    if (cpu->esi == cpu->edi) goto label_0001197B;
    cpu->edx = 0x46u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->edi + 4u) = 0u;
    *(uint32_t*)(cpu->edi) = 0u;
    label_0001197B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_00411F20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411F3Cu)); sfera_sub_0040FD90(cpu, LIFT_CODE_TOKEN_VA(0x411F3Cu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = 0x7FFFFFEu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_00011F56;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x411F20u); throw std::length_error("std::length_error");
    label_00011F56:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411F78u)); sfera_sub_0040F180(cpu, LIFT_CODE_TOKEN_VA(0x411F78u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411F80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411F9Cu)); sfera_sub_0040FE60(cpu, LIFT_CODE_TOKEN_VA(0x411F9Cu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = 0x7FFFFFEu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_00011FB6;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x411F80u); throw std::length_error("std::length_error");
    label_00011FB6:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411FD8u)); sfera_sub_0040F180(cpu, LIFT_CODE_TOKEN_VA(0x411FD8u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00411FE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x411FFCu)); sfera_sub_0040FF30(cpu, LIFT_CODE_TOKEN_VA(0x411FFCu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = 0x7FFFFFEu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_00012016;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x411FE0u); throw std::length_error("std::length_error");
    label_00012016:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412038u)); sfera_sub_0040F300(cpu, LIFT_CODE_TOKEN_VA(0x412038u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00412040(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41205Cu)); sfera_sub_00410000(cpu, LIFT_CODE_TOKEN_VA(0x41205Cu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = 0x4924923u;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_00012076;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x412040u); throw std::length_error("std::length_error");
    label_00012076:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412098u)); sfera_sub_0040F420(cpu, LIFT_CODE_TOKEN_VA(0x412098u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004120A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4120BCu)); sfera_sub_004100F0(cpu, LIFT_CODE_TOKEN_VA(0x4120BCu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = 0x71C71C6u;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_000120D6;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4120A0u); throw std::length_error("std::length_error");
    label_000120D6:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4120F8u)); sfera_sub_0040F800(cpu, LIFT_CODE_TOKEN_VA(0x4120F8u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_00412BC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x40u;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412C02u)); sfera_sub_00407890(cpu, LIFT_CODE_TOKEN_VA(0x412C02u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->esi + 4u)) goto label_00012C5B;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x34u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x20u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412C27u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x412C27u));
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ebx;
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412C40u)); sfera_sub_00411F20(cpu, LIFT_CODE_TOKEN_VA(0x412C40u));
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (*(uint32_t*)(cpu->esp + 0x30u) < 0x10u) goto label_00012C56;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00012C56:
    cpu->eax = cpu->esi + 0x24u;
    goto label_00012C5E;
    label_00012C5B:
    cpu->eax = cpu->ecx + 0x24u;
    label_00012C5E:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x3Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00412C80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x3Cu;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412CC1u)); sfera_sub_00407890(cpu, LIFT_CODE_TOKEN_VA(0x412CC1u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->ecx != *(uint32_t*)(cpu->esi + 4u)) goto label_00012D23;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x30u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0u;
    *(uint8_t*)(cpu->esp + 0x1Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412CE9u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x412CE9u));
    *(float*)(cpu->esp + 0x34u) = (double)(0.0);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x4Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412D08u)); sfera_sub_00411F80(cpu, LIFT_CODE_TOKEN_VA(0x412D08u));
    cpu->esi = *(uint32_t*)(cpu->eax);
    if (*(uint32_t*)(cpu->esp + 0x2Cu) < 0x10u) goto label_00012D1E;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00012D1E:
    cpu->eax = cpu->esi + 0x24u;
    goto label_00012D26;
    label_00012D23:
    cpu->eax = cpu->ecx + 0x24u;
    label_00012D26:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x3Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00412D50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x48u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x58u;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412D92u)); sfera_sub_00407550(cpu, LIFT_CODE_TOKEN_VA(0x412D92u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->esi + 4u)) goto label_00012E31;
    cpu->edi = *(uint32_t*)(cpu->edi);
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x4Cu) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x38u) = cpu->ebx & 0xFFu;
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x34u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x20u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412DD9u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x412DD9u));
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x68u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412DEFu)); sfera_sub_00411FE0(cpu, LIFT_CODE_TOKEN_VA(0x412DEFu));
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->edi = 0x10u;
    if (*(uint32_t*)(cpu->esp + 0x30u) < cpu->edi) goto label_00012E09;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00012E09:
    *(uint32_t*)(cpu->esp + 0x30u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x1Cu) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x4Cu) < cpu->edi) goto label_00012E2C;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00012E2C:
    cpu->eax = cpu->esi + 0xCu;
    goto label_00012E34;
    label_00012E31:
    cpu->eax = cpu->ecx + 0xCu;
    label_00012E34:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x54u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00412E60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x64u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x78u;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x88u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412EA6u)); sfera_sub_00407890(cpu, LIFT_CODE_TOKEN_VA(0x412EA6u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->ecx != *(uint32_t*)(cpu->esi + 4u)) goto label_00012F7B;
    cpu->ebx = 0u;
    cpu->ebp = 0xFu;
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x58u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x24u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412EE3u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x412EE3u));
    cpu->ecx = cpu->esp + 0x58u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x40u;
    *(uint8_t*)(cpu->esp + 0x84u) = 1u;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x40u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412F05u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x412F05u));
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x88u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412F1Eu)); sfera_sub_00412040(cpu, LIFT_CODE_TOKEN_VA(0x412F1Eu));
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->esi = 0x10u;
    if (*(uint32_t*)(cpu->esp + 0x50u) < cpu->esi) goto label_00012F38;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00012F38:
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x3Cu) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x34u) < cpu->esi) goto label_00012F57;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00012F57:
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x20u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x6Cu) < cpu->esi) goto label_00012F76;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00012F76:
    cpu->eax = cpu->edi + 0x24u;
    goto label_00012F7E;
    label_00012F7B:
    cpu->eax = cpu->ecx + 0x24u;
    label_00012F7E:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x70u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00412FA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x38u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x48u;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412FE2u)); sfera_sub_00407890(cpu, LIFT_CODE_TOKEN_VA(0x412FE2u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->esi + 4u)) goto label_0001307D;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x38u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x24u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413017u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x413017u));
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x58u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41303Du)); sfera_sub_004120A0(cpu, LIFT_CODE_TOKEN_VA(0x41303Du));
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint8_t*)(cpu->esp + 0x50u) = 2u;
    if (*(uint32_t*)(cpu->esp + 0x40u) == cpu->ebx) goto label_00013064;
    cpu->edx = cpu->ebx + 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00013064:
    if (*(uint32_t*)(cpu->esp + 0x34u) < 0x10u) goto label_00013078;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00013078:
    cpu->eax = cpu->esi + 0x24u;
    goto label_00013080;
    label_0001307D:
    cpu->eax = cpu->ecx + 0x24u;
    label_00013080:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x44u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004130A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4130BCu)); sfera_sub_00410DE0(cpu, LIFT_CODE_TOKEN_VA(0x4130BCu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = 0x71C71C6u;
    cpu->edx -= cpu->ecx;
    if (cpu->edx >= 1u) goto label_000130D6;
    lift_push32(cpu, (uintptr_t)"list<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4130A0u); throw std::length_error("std::length_error");
    label_000130D6:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4130F8u)); sfera_sub_0040F5A0(cpu, LIFT_CODE_TOKEN_VA(0x4130F8u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00413B30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx += 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413B3Fu)); sfera_sub_00412FA0(cpu, LIFT_CODE_TOKEN_VA(0x413B3Fu));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = cpu->eax;
    if (cpu->esi == cpu->edi) goto label_00013B7B;
    cpu->edx = 0x46u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->edi + 4u) = 0u;
    *(uint32_t*)(cpu->edi) = 0u;
    label_00013B7B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00413B80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x4Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x5Cu;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x6Cu);
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413BC2u)); sfera_sub_00407610(cpu, LIFT_CODE_TOKEN_VA(0x413BC2u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx != *(uint32_t*)(cpu->edi + 4u)) goto label_00013C98;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x50u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x3Cu) = cpu->ebx & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi) = cpu->ebx;
    cpu->eax = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x24u;
    *(uint8_t*)(cpu->esp + 0x68u) = 1u;
    *(uint32_t*)(cpu->esp + 0x38u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x24u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413C1Au)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x413C1Au));
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    *(uint8_t*)(cpu->esp + 0x6Cu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413C30u)); sfera_sub_004130A0(cpu, LIFT_CODE_TOKEN_VA(0x413C30u));
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->edi = 0x10u;
    *(uint8_t*)(cpu->esp + 0x64u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x34u) < cpu->edi) goto label_00013C4E;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00013C4E:
    *(uint32_t*)(cpu->esp + 0x34u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x20u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x1Cu) == cpu->ebx) goto label_00013C80;
    cpu->edx = 0x27u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\DataCont\\sDataContainers.cpp";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00013C80:
    if (*(uint32_t*)(cpu->esp + 0x50u) < cpu->edi) goto label_00013C93;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00013C93:
    cpu->eax = cpu->esi + 0x10u;
    goto label_00013C9B;
    label_00013C98:
    cpu->eax = cpu->ecx + 0x10u;
    label_00013C9B:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x58u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

} // namespace lifted
