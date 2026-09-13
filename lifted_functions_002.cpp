#include "lifted_functions.h"
#include <cmath>
namespace lifted {

__declspec(noinline) void sfera_sub_00414920(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6, value_7, value_8, value_9;
 bool sub_pred[9]; double x87_p0;
    goto label_00014920;

label_00012160:
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x41216Cu);
    if (cpu->eax > 9u) goto label_00012293;
    switch (cpu->eax) {
        case 0u: goto label_000121EA;
        case 1u: goto label_00012226;
        case 2u: goto label_00012250;
        case 3u: goto label_0001217C;
        case 4u: goto label_000121AA;
        case 5u: goto label_000121D8;
        case 6u: case 7u: case 8u: goto label_00012293;
        case 9u: goto label_00012280;
        default: cpu->eip = 0x412175u; throw std::out_of_range("resolved jump-table index out of range"); return;
    }

label_0001217C:
 ;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x412181u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x412188u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_000122A0;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41219Eu)); sfera_sub_00406DE0(cpu, LIFT_CODE_TOKEN_VA(0x41219Eu));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;

label_000121AA:
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x4121AFu);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x4121B6u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_000122A0;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4121CCu)); sfera_sub_00406E30(cpu, LIFT_CODE_TOKEN_VA(0x4121CCu));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;

label_000121D8:
    cpu->ecx = 0u;
    sub_pred[6] = *(uint8_t*)(cpu->esi + 8u) == (uint8_t)(cpu->ecx);
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (sub_pred[6]);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;

label_000121EA:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4121EFu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4121F8u);
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_000122A0;
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41221Au)); sfera_sub_004117C0(cpu, LIFT_CODE_TOKEN_VA(0x41221Au));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;

label_00012226:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x41222Bu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_000122A0;
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412244u)); sfera_sub_00411190(cpu, LIFT_CODE_TOKEN_VA(0x412244u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;

label_00012250:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x412255u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x41225Eu);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_000122A0;
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412274u)); sfera_sub_00409C90(cpu, LIFT_CODE_TOKEN_VA(0x412274u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;

label_00012280:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412287u)); sfera_sub_00410650(cpu, LIFT_CODE_TOKEN_VA(0x412287u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;

label_00012293:
    cpu->edi = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;

label_000122A0:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;

label_000122D0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x14u;
    cpu->esi = cpu->ecx;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4122FCu);
    if (cpu->eax > 9u) goto label_0001245D;
    switch (cpu->eax) {
        case 0u: goto label_0001236B;
        case 1u: goto label_000123C5;
        case 2u: goto label_0001240C;
        case 3u: goto label_0001230C;
        case 4u: goto label_00012335;
        case 5u: goto label_0001235E;
        case 6u: case 7u: case 8u: goto label_0001245D;
        case 9u: goto label_00012443;
        default: cpu->eip = 0x412305u; throw std::out_of_range("resolved jump-table index out of range"); return;
    }

label_0001230C:
 ;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x412311u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x412318u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00012465;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41232Eu)); sfera_sub_00406F30(cpu, LIFT_CODE_TOKEN_VA(0x41232Eu));
    cpu->ecx = cpu->eax;
    goto label_00012460;

label_00012335:
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x41233Au);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x412341u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00012465;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412357u)); sfera_sub_00406F80(cpu, LIFT_CODE_TOKEN_VA(0x412357u));
    cpu->ecx = cpu->eax;
    goto label_00012460;

label_0001235E:
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 8u) == (uint8_t)(cpu->ecx));
    goto label_00012460;

label_0001236B:
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412374u)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x412374u));
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x412381u);
    cpu->edi = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_000123A2;
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412399u)); sfera_sub_00411370(cpu, LIFT_CODE_TOKEN_VA(0x412399u));
    *(uint32_t*)(cpu->eax) = cpu->edi;

label_0001239B:
    cpu->ecx = 0u;

label_0001239D:
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x123A2u);

label_000123A2:
    cpu->ecx = cpu->esp + 0xCu;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4123B3u)); sfera_sub_00402CF0(cpu, LIFT_CODE_TOKEN_VA(0x4123B3u));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;

label_000123C5:
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4123CEu)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x4123CEu));
    *(uint32_t*)(cpu->esp + 0x1Cu) = 1u;
    cpu->ecx = cpu->esp + 0xCu;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) == 0u) goto label_00012402;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4123F0u)); sfera_sub_00402CF0(cpu, LIFT_CODE_TOKEN_VA(0x4123F0u));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;

label_00012402:
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41240Au)); sfera_sub_00411140(cpu, LIFT_CODE_TOKEN_VA(0x41240Au));
    goto label_0001239B;

label_0001240C:
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412415u)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x412415u));
    *(uint32_t*)(cpu->esp + 0x1Cu) = 2u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x412422u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_000123A2;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41243Cu)); sfera_sub_00409D10(cpu, LIFT_CODE_TOKEN_VA(0x41243Cu));
    cpu->ecx = cpu->eax;
    goto label_0001239D;

label_00012443:
    cpu->ecx = cpu->esi + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41244Bu)); sfera_sub_0040A060(cpu, LIFT_CODE_TOKEN_VA(0x41244Bu));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412455u)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x412455u));
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->ecx = 0u;
    goto label_00012460;

label_0001245D:
    cpu->ecx |= 0xFFFFFFFFu;

label_00012460:
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x12465u);

label_00012465:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;

label_000124A0:
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4124ACu);
    if (cpu->eax > 9u) goto label_000125D3;
    switch (cpu->eax) {
        case 0u: goto label_0001252A;
        case 1u: goto label_00012566;
        case 2u: goto label_00012590;
        case 3u: goto label_000124BC;
        case 4u: goto label_000124EA;
        case 5u: goto label_00012518;
        case 6u: case 7u: case 8u: goto label_000125D3;
        case 9u: goto label_000125C0;
        default: cpu->eip = 0x4124B5u; throw std::out_of_range("resolved jump-table index out of range"); return;
    }

label_000124BC:
 ;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x4124C1u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x4124C8u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_000125E0;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4124DEu)); sfera_sub_00406FE0(cpu, LIFT_CODE_TOKEN_VA(0x4124DEu));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;

label_000124EA:
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x4124EFu);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x4124F6u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_000125E0;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41250Cu)); sfera_sub_00407030(cpu, LIFT_CODE_TOKEN_VA(0x41250Cu));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;

label_00012518:
    cpu->ecx = 0u;
    sub_pred[8] = *(uint8_t*)(cpu->esi + 8u) == (uint8_t)(cpu->ecx);
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (sub_pred[8]);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;

label_0001252A:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x41252Fu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    value_0 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_VA(0x412538u);
    *(float*)(cpu->esp + 8u) = value_0; 
     if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_000125E0;
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41255Au)); sfera_sub_00411820(cpu, LIFT_CODE_TOKEN_VA(0x41255Au));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;

label_00012566:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x41256Bu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_000125E0;
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412584u)); sfera_sub_00411190(cpu, LIFT_CODE_TOKEN_VA(0x412584u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;

label_00012590:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x412595u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x41259Eu);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_000125E0;
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4125B4u)); sfera_sub_00409D50(cpu, LIFT_CODE_TOKEN_VA(0x4125B4u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;

label_000125C0:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4125C7u)); sfera_sub_00410650(cpu, LIFT_CODE_TOKEN_VA(0x4125C7u));
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;

label_000125D3:
    cpu->edi = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;

label_000125E0:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;

label_00012610:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    cpu->esi = cpu->ecx;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x41263Cu);
    if (cpu->eax > 9u) goto label_000127A3;
    switch (cpu->eax) {
        case 0u: goto label_000126AB;
        case 1u: goto label_0001270B;
        case 2u: goto label_00012752;
        case 3u: goto label_0001264C;
        case 4u: goto label_00012675;
        case 5u: goto label_0001269E;
        case 6u: case 7u: case 8u: goto label_000127A3;
        case 9u: goto label_00012789;
        default: cpu->eip = 0x412645u; throw std::out_of_range("resolved jump-table index out of range"); return;
    }

label_0001264C:
 ;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x412651u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x412658u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_000127AB;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41266Eu)); sfera_sub_00407130(cpu, LIFT_CODE_TOKEN_VA(0x41266Eu));
    cpu->ecx = cpu->eax;
    goto label_000127A6;

label_00012675:
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x41267Au);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x412681u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_000127AB;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412697u)); sfera_sub_00407180(cpu, LIFT_CODE_TOKEN_VA(0x412697u));
    cpu->ecx = cpu->eax;
    goto label_000127A6;

label_0001269E:
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 8u) == (uint8_t)(cpu->ecx));
    goto label_000127A6;

label_000126AB:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4126B4u)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x4126B4u));
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    value_1 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_VA(0x4126C1u);
    *(float*)(cpu->esp + 0xCu) = value_1; 
     if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_000126E8;
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4126DBu)); sfera_sub_00411450(cpu, LIFT_CODE_TOKEN_VA(0x4126DBu));
    *(float*)(cpu->eax) = (double)*(float*)(cpu->esp + 0xCu);

label_000126E1:
    cpu->ecx = 0u;

label_000126E3:
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x126E8u);

label_000126E8:
    cpu->ecx = cpu->esp + 0x10u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4126F9u)); sfera_sub_00402CF0(cpu, LIFT_CODE_TOKEN_VA(0x4126F9u));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;

label_0001270B:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412714u)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x412714u));
    *(uint32_t*)(cpu->esp + 0x20u) = 1u;
    cpu->ecx = cpu->esp + 0x10u;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) == 0u) goto label_00012748;
    *(uint32_t*)(cpu->esp + 0x20u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412736u)); sfera_sub_00402CF0(cpu, LIFT_CODE_TOKEN_VA(0x412736u));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;

label_00012748:
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412750u)); sfera_sub_00411140(cpu, LIFT_CODE_TOKEN_VA(0x412750u));
    goto label_000126E1;

label_00012752:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41275Bu)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x41275Bu));
    *(uint32_t*)(cpu->esp + 0x20u) = 2u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x412768u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_000126E8;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412782u)); sfera_sub_00409DD0(cpu, LIFT_CODE_TOKEN_VA(0x412782u));
    cpu->ecx = cpu->eax;
    goto label_000126E3;

label_00012789:
    cpu->ecx = cpu->esi + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412791u)); sfera_sub_0040A060(cpu, LIFT_CODE_TOKEN_VA(0x412791u));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41279Bu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x41279Bu));
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->ecx = 0u;
    goto label_000127A6;

label_000127A3:
    cpu->ecx |= 0xFFFFFFFFu;

label_000127A6:
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x127ABu);

label_000127AB:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;

label_000127F0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    cpu->esi = cpu->ecx;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x41281Cu);
    if (cpu->eax > 9u) goto label_0001294D;
    switch (cpu->eax) {
        case 0u: goto label_0001288B;
        case 1u: goto label_000128E9;
        case 2u: goto label_0001290B;
        case 3u: goto label_0001282C;
        case 4u: goto label_00012855;
        case 5u: goto label_0001287E;
        case 6u: case 7u: case 8u: goto label_0001294D;
        case 9u: goto label_00012933;
        default: cpu->eip = 0x412825u; throw std::out_of_range("resolved jump-table index out of range"); return;
    }

label_0001282C:
 ;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x412831u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x412838u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00012955;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41284Eu)); sfera_sub_00407390(cpu, LIFT_CODE_TOKEN_VA(0x41284Eu));
    cpu->ecx = cpu->eax;
    goto label_00012950;

label_00012855:
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x41285Au);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x412861u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00012955;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412877u)); sfera_sub_004073E0(cpu, LIFT_CODE_TOKEN_VA(0x412877u));
    cpu->ecx = cpu->eax;
    goto label_00012950;

label_0001287E:
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 8u) == (uint8_t)(cpu->ecx));
    goto label_00012950;

label_0001288B:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x412890u);
    cpu->ecx = cpu->esp + 0x10u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41289Du)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x41289Du));
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_000128C6;
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4128BFu)); sfera_sub_004118E0(cpu, LIFT_CODE_TOKEN_VA(0x4128BFu));
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x128C6u);

label_000128C6:
    cpu->ecx = cpu->esp + 0x10u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4128D7u)); sfera_sub_00402CF0(cpu, LIFT_CODE_TOKEN_VA(0x4128D7u));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;

label_000128E9:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4128EEu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00012955;
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412907u)); sfera_sub_00411280(cpu, LIFT_CODE_TOKEN_VA(0x412907u));
    cpu->ecx = 0u;
    goto label_00012950;

label_0001290B:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x412910u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x412919u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00012955;
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41292Fu)); sfera_sub_00409ED0(cpu, LIFT_CODE_TOKEN_VA(0x41292Fu));
    cpu->ecx = cpu->eax;
    goto label_00012950;

label_00012933:
    cpu->ecx = cpu->esi + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41293Bu)); sfera_sub_00408A50(cpu, LIFT_CODE_TOKEN_VA(0x41293Bu));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412945u)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x412945u));
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->ecx = 0u;
    goto label_00012950;

label_0001294D:
    cpu->ecx |= 0xFFFFFFFFu;

label_00012950:
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x12955u);

label_00012955:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;

label_00012990:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x20u;
    cpu->esi = cpu->ecx;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4129C2u);
    if (cpu->eax > 9u) goto label_00012B23;
    switch (cpu->eax) {
        case 0u: goto label_00012A31;
        case 1u: goto label_00012AA2;
        case 2u: goto label_00012AD1;
        case 3u: goto label_000129D2;
        case 4u: goto label_000129FB;
        case 5u: goto label_00012A24;
        case 6u: case 7u: case 8u: goto label_00012B23;
        case 9u: goto label_00012B09;
        default: cpu->eip = 0x4129CBu; throw std::out_of_range("resolved jump-table index out of range"); return;
    }

label_000129D2:
 ;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x4129D7u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x4129DEu);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00012B2B;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4129F4u)); sfera_sub_004074C0(cpu, LIFT_CODE_TOKEN_VA(0x4129F4u));
    cpu->ecx = cpu->eax;
    goto label_00012B26;

label_000129FB:
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x412A00u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x412A07u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00012B2B;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412A1Du)); sfera_sub_00407500(cpu, LIFT_CODE_TOKEN_VA(0x412A1Du));
    cpu->ecx = cpu->eax;
    goto label_00012B26;

label_00012A24:
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 8u) == (uint8_t)(cpu->ecx));
    goto label_00012B26;

label_00012A31:
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412A3Au)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x412A3Au));
    cpu->ecx = cpu->esp + 0xCu;
    *(uint32_t*)(cpu->esp + 0x28u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412A4Bu)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x412A4Bu));
    *(uint8_t*)(cpu->esp + 0x28u) = 1u;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00012A71;
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412A6Au)); sfera_sub_00411930(cpu, LIFT_CODE_TOKEN_VA(0x412A6Au));
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x12A71u);

label_00012A71:
    cpu->ecx = cpu->esp + 0xCu;
    *(uint8_t*)(cpu->esp + 0x28u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x12A7Fu)); sfera_sub_00402CF0(cpu, LIFT_CODE_TOKEN_RVA(0x12A7Fu));

label_00012A7F:
    cpu->ecx = cpu->esp + 0x14u;
    *(uint32_t*)(cpu->esp + 0x28u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412A90u)); sfera_sub_00402CF0(cpu, LIFT_CODE_TOKEN_VA(0x412A90u));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;

label_00012AA2:
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412AABu)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x412AABu));
    *(uint32_t*)(cpu->esp + 0x28u) = 2u;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00012A7F;
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412AC8u)); sfera_sub_00411320(cpu, LIFT_CODE_TOKEN_VA(0x412AC8u));
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x412ACFu);
    goto label_00012A7F;

label_00012AD1:
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412ADAu)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x412ADAu));
    *(uint32_t*)(cpu->esp + 0x28u) = 3u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x412AE7u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00012A7F;
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412AFDu)); sfera_sub_00409F50(cpu, LIFT_CODE_TOKEN_VA(0x412AFDu));
    cpu->ecx = cpu->eax;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x412B04u);
    goto label_00012A7F;

label_00012B09:
    cpu->ecx = cpu->esi + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412B11u)); sfera_sub_0040A0C0(cpu, LIFT_CODE_TOKEN_VA(0x412B11u));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x412B1Bu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x412B1Bu));
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->ecx = 0u;
    goto label_00012B26;

label_00012B23:
    cpu->ecx |= 0xFFFFFFFFu;

label_00012B26:
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x12B2Bu);

label_00012B2B:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;

label_00013D00:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x3Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x48u;
    cpu->esi = cpu->ecx;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x413D37u);
    if (cpu->eax > 9u) goto label_00013E7B;
    switch (cpu->eax) {
        case 0u: goto label_00013DA6;
        case 1u: goto label_00013DEB;
        case 2u: goto label_00013E23;
        case 3u: goto label_00013D47;
        case 4u: goto label_00013D70;
        case 5u: goto label_00013D99;
        case 6u: case 7u: case 8u: goto label_00013E7B;
        case 9u: goto label_00013E61;
        default: cpu->eip = 0x413D40u; throw std::out_of_range("resolved jump-table index out of range"); return;
    }

label_00013D47:
 ;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x413D4Cu);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x413D53u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00013E83;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413D69u)); sfera_sub_00406E90(cpu, LIFT_CODE_TOKEN_VA(0x413D69u));
    cpu->ecx = cpu->eax;
    goto label_00013E7E;

label_00013D70:
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x413D75u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x413D7Cu);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00013E83;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413D92u)); sfera_sub_00406EE0(cpu, LIFT_CODE_TOKEN_VA(0x413D92u));
    cpu->ecx = cpu->eax;
    goto label_00013E7E;

label_00013D99:
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 8u) == (uint8_t)(cpu->ecx));
    goto label_00013E7E;

label_00013DA6:
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413DAFu)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x413DAFu));
    *(uint32_t*)(cpu->esp + 0x50u) = 0u;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x413DBCu);
    cpu->edi = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00013DDD;
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413DD4u)); sfera_sub_00412BC0(cpu, LIFT_CODE_TOKEN_VA(0x413DD4u));
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->edi;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x13DDDu);

label_00013DDD:
    cpu->ecx = cpu->esp + 0xCu;

label_00013DE1:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413DE6u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x413DE6u));
    goto label_00013E83;

label_00013DEB:
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413DF4u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x413DF4u));
    *(uint32_t*)(cpu->esp + 0x50u) = 1u;
    cpu->ecx = cpu->esp + 0xCu;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00013DE1;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413E11u)); sfera_sub_004110F0(cpu, LIFT_CODE_TOKEN_VA(0x413E11u));
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x413E18u);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413E21u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x413E21u));
    goto label_00013E83;

label_00013E23:
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413E2Cu)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x413E2Cu));
    *(uint32_t*)(cpu->esp + 0x50u) = 2u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x413E39u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00013E56;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413E4Fu)); sfera_sub_00409CD0(cpu, LIFT_CODE_TOKEN_VA(0x413E4Fu));
    cpu->ecx = cpu->eax;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x13E56u);

label_00013E56:
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413E5Fu)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x413E5Fu));
    goto label_00013E83;

label_00013E61:
    cpu->ecx = cpu->esi + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413E69u)); sfera_sub_004BC130(cpu, LIFT_CODE_TOKEN_VA(0x413E69u));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413E73u)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x413E73u));
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->ecx = 0u;
    goto label_00013E7E;

label_00013E7B:
    cpu->ecx |= 0xFFFFFFFFu;

label_00013E7E:
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x13E83u);

label_00013E83:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x48u;
    cpu->esp += 4u; cpu->eip = stop_address; return;

label_00013ED0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x40u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x4Cu;
    cpu->esi = cpu->ecx;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x413F07u);
    if (cpu->eax > 9u) goto label_00014051;
    switch (cpu->eax) {
        case 0u: goto label_00013F76;
        case 1u: goto label_00013FC1;
        case 2u: goto label_00013FF9;
        case 3u: goto label_00013F17;
        case 4u: goto label_00013F40;
        case 5u: goto label_00013F69;
        case 6u: case 7u: case 8u: goto label_00014051;
        case 9u: goto label_00014037;
        default: cpu->eip = 0x413F10u; throw std::out_of_range("resolved jump-table index out of range"); return;
    }

label_00013F17:
 ;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x413F1Cu);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x413F23u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00014059;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413F39u)); sfera_sub_00407090(cpu, LIFT_CODE_TOKEN_VA(0x413F39u));
    cpu->ecx = cpu->eax;
    goto label_00014054;

label_00013F40:
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x413F45u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x413F4Cu);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00014059;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413F62u)); sfera_sub_004070E0(cpu, LIFT_CODE_TOKEN_VA(0x413F62u));
    cpu->ecx = cpu->eax;
    goto label_00014054;

label_00013F69:
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 8u) == (uint8_t)(cpu->ecx));
    goto label_00014054;

label_00013F76:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413F7Fu)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x413F7Fu));
    *(uint32_t*)(cpu->esp + 0x54u) = 0u;
    value_3 = g_sfera_mbc_runtime->nextReal(); cpu->eip = LIFT_CODE_TOKEN_VA(0x413F8Cu);
    *(float*)(cpu->esp + 0xCu) = value_3; 
     if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00013FB3;
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413FA6u)); sfera_sub_00412C80(cpu, LIFT_CODE_TOKEN_VA(0x413FA6u));
    x87_p0 = (double)*(float*)(cpu->esp + 0xCu);
    cpu->ecx = 0u;
    *(float*)(cpu->eax) = x87_p0; 
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x13FB3u);

label_00013FB3:
    cpu->ecx = cpu->esp + 0x10u;

label_00013FB7:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413FBCu)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x413FBCu));
    goto label_00014059;

label_00013FC1:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413FCAu)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x413FCAu));
    *(uint32_t*)(cpu->esp + 0x54u) = 1u;
    cpu->ecx = cpu->esp + 0x10u;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00013FB7;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413FE7u)); sfera_sub_004110F0(cpu, LIFT_CODE_TOKEN_VA(0x413FE7u));
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x413FEEu);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x413FF7u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x413FF7u));
    goto label_00014059;

label_00013FF9:
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414002u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x414002u));
    *(uint32_t*)(cpu->esp + 0x54u) = 2u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x41400Fu);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_0001402C;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414025u)); sfera_sub_00409D90(cpu, LIFT_CODE_TOKEN_VA(0x414025u));
    cpu->ecx = cpu->eax;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x1402Cu);

label_0001402C:
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414035u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x414035u));
    goto label_00014059;

label_00014037:
    cpu->ecx = cpu->esi + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41403Fu)); sfera_sub_004BC130(cpu, LIFT_CODE_TOKEN_VA(0x41403Fu));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414049u)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x414049u));
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->ecx = 0u;
    goto label_00014054;

label_00014051:
    cpu->ecx |= 0xFFFFFFFFu;

label_00014054:
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x14059u);

label_00014059:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x4Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;

label_000140A0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x24u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x30u;
    cpu->esi = cpu->ecx;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4140D7u);
    if (cpu->eax > 9u) goto label_000141F8;
    switch (cpu->eax) {
        case 0u: goto label_00014146;
        case 1u: goto label_00014194;
        case 2u: goto label_000141B6;
        case 3u: goto label_000140E7;
        case 4u: goto label_00014110;
        case 5u: goto label_00014139;
        case 6u: case 7u: case 8u: goto label_000141F8;
        case 9u: goto label_000141DE;
        default: cpu->eip = 0x4140E0u; throw std::out_of_range("resolved jump-table index out of range"); return;
    }

label_000140E7:
 ;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x4140ECu);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x4140F3u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00014200;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414109u)); sfera_sub_004071D0(cpu, LIFT_CODE_TOKEN_VA(0x414109u));
    cpu->ecx = cpu->eax;
    goto label_000141FB;

label_00014110:
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x414115u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x41411Cu);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00014200;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414132u)); sfera_sub_00407220(cpu, LIFT_CODE_TOKEN_VA(0x414132u));
    cpu->ecx = cpu->eax;
    goto label_000141FB;

label_00014139:
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 8u) == (uint8_t)(cpu->ecx));
    goto label_000141FB;

label_00014146:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x41414Bu);
    cpu->ecx = cpu->esp + 0x10u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414158u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x414158u));
    *(uint32_t*)(cpu->esp + 0x38u) = 0u;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00014189;
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414176u)); sfera_sub_00412D50(cpu, LIFT_CODE_TOKEN_VA(0x414176u));
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414182u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x414182u));
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x14189u);

label_00014189:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414192u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x414192u));
    goto label_00014200;

label_00014194:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x414199u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00014200;
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4141B2u)); sfera_sub_004111E0(cpu, LIFT_CODE_TOKEN_VA(0x4141B2u));
    cpu->ecx = 0u;
    goto label_000141FB;

label_000141B6:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4141BBu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x4141C4u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00014200;
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4141DAu)); sfera_sub_00409E10(cpu, LIFT_CODE_TOKEN_VA(0x4141DAu));
    cpu->ecx = cpu->eax;
    goto label_000141FB;

label_000141DE:
    cpu->ecx = cpu->esi + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4141E6u)); sfera_sub_0040BB40(cpu, LIFT_CODE_TOKEN_VA(0x4141E6u));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4141F0u)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x4141F0u));
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->ecx = 0u;
    goto label_000141FB;

label_000141F8:
    cpu->ecx |= 0xFFFFFFFFu;

label_000141FB:
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x14200u);

label_00014200:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;

label_00014250:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x58u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x64u;
    cpu->esi = cpu->ecx;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x414287u);
    if (cpu->eax > 9u) goto label_000143E5;
    switch (cpu->eax) {
        case 0u: goto label_000142F6;
        case 1u: goto label_00014355;
        case 2u: goto label_0001438D;
        case 3u: goto label_00014297;
        case 4u: goto label_000142C0;
        case 5u: goto label_000142E9;
        case 6u: case 7u: case 8u: goto label_000143E5;
        case 9u: goto label_000143CB;
        default: cpu->eip = 0x414290u; throw std::out_of_range("resolved jump-table index out of range"); return;
    }

label_00014297:
 ;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x41429Cu);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x4142A3u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_000143ED;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4142B9u)); sfera_sub_00407270(cpu, LIFT_CODE_TOKEN_VA(0x4142B9u));
    cpu->ecx = cpu->eax;
    goto label_000143E8;

label_000142C0:
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x4142C5u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x4142CCu);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_000143ED;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4142E2u)); sfera_sub_004072B0(cpu, LIFT_CODE_TOKEN_VA(0x4142E2u));
    cpu->ecx = cpu->eax;
    goto label_000143E8;

label_000142E9:
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 8u) == (uint8_t)(cpu->ecx));
    goto label_000143E8;

label_000142F6:
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4142FFu)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x4142FFu));
    cpu->ecx = cpu->esp + 0x28u;
    *(uint32_t*)(cpu->esp + 0x6Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414310u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x414310u));
    *(uint8_t*)(cpu->esp + 0x6Cu) = 1u;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_0001433E;
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41432Bu)); sfera_sub_00412E60(cpu, LIFT_CODE_TOKEN_VA(0x41432Bu));
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414337u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x414337u));
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x1433Eu);

label_0001433E:
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x14347u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_RVA(0x14347u));

label_00014347:
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414350u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x414350u));
    goto label_000143ED;

label_00014355:
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41435Eu)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x41435Eu));
    *(uint32_t*)(cpu->esp + 0x6Cu) = 2u;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00014347;
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41437Bu)); sfera_sub_00411230(cpu, LIFT_CODE_TOKEN_VA(0x41437Bu));
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x414382u);
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41438Bu)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x41438Bu));
    goto label_000143ED;

label_0001438D:
    cpu->ecx = cpu->esp + 0x44u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414396u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x414396u));
    *(uint32_t*)(cpu->esp + 0x6Cu) = 3u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x4143A3u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_000143C0;
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4143B9u)); sfera_sub_00409E50(cpu, LIFT_CODE_TOKEN_VA(0x4143B9u));
    cpu->ecx = cpu->eax;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x143C0u);

label_000143C0:
    cpu->ecx = cpu->esp + 0x44u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4143C9u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4143C9u));
    goto label_000143ED;

label_000143CB:
    cpu->ecx = cpu->esi + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4143D3u)); sfera_sub_0040BBA0(cpu, LIFT_CODE_TOKEN_VA(0x4143D3u));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4143DDu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x4143DDu));
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->ecx = 0u;
    goto label_000143E8;

label_000143E5:
    cpu->ecx |= 0xFFFFFFFFu;

label_000143E8:
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x143EDu);

label_000143ED:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x64u;
    cpu->esp += 4u; cpu->eip = stop_address; return;

label_00014440:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x44u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x50u;
    cpu->esi = cpu->ecx;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x414477u);
    if (cpu->eax > 9u) goto label_000145D2;
    switch (cpu->eax) {
        case 0u: goto label_000144E6;
        case 1u: goto label_00014542;
        case 2u: goto label_0001457A;
        case 3u: goto label_00014487;
        case 4u: goto label_000144B0;
        case 5u: goto label_000144D9;
        case 6u: case 7u: case 8u: goto label_000145D2;
        case 9u: goto label_000145B8;
        default: cpu->eip = 0x414480u; throw std::out_of_range("resolved jump-table index out of range"); return;
    }

label_00014487:
 ;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x41448Cu);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x414493u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_000145DA;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4144A9u)); sfera_sub_00407430(cpu, LIFT_CODE_TOKEN_VA(0x4144A9u));
    cpu->ecx = cpu->eax;
    goto label_000145D5;

label_000144B0:
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x4144B5u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x4144BCu);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_000145DA;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4144D2u)); sfera_sub_00407470(cpu, LIFT_CODE_TOKEN_VA(0x4144D2u));
    cpu->ecx = cpu->eax;
    goto label_000145D5;

label_000144D9:
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 8u) == (uint8_t)(cpu->ecx));
    goto label_000145D5;

label_000144E6:
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4144EFu)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x4144EFu));
    cpu->ecx = cpu->esp + 0xCu;
    *(uint32_t*)(cpu->esp + 0x58u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414500u)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x414500u));
    *(uint8_t*)(cpu->esp + 0x58u) = 1u;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00014526;
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41451Fu)); sfera_sub_00413B30(cpu, LIFT_CODE_TOKEN_VA(0x41451Fu));
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x14526u);

label_00014526:
    cpu->ecx = cpu->esp + 0xCu;
    *(uint8_t*)(cpu->esp + 0x58u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x14534u)); sfera_sub_00402CF0(cpu, LIFT_CODE_TOKEN_RVA(0x14534u));

label_00014534:
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41453Du)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x41453Du));
    goto label_000145DA;

label_00014542:
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41454Bu)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x41454Bu));
    *(uint32_t*)(cpu->esp + 0x58u) = 2u;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00014534;
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414568u)); sfera_sub_004112D0(cpu, LIFT_CODE_TOKEN_VA(0x414568u));
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x41456Fu);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414578u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x414578u));
    goto label_000145DA;

label_0001457A:
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414583u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x414583u));
    *(uint32_t*)(cpu->esp + 0x58u) = 3u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x414590u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_000145AD;
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4145A6u)); sfera_sub_00409F10(cpu, LIFT_CODE_TOKEN_VA(0x4145A6u));
    cpu->ecx = cpu->eax;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x145ADu);

label_000145AD:
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4145B6u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4145B6u));
    goto label_000145DA;

label_000145B8:
    cpu->ecx = cpu->esi + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4145C0u)); sfera_sub_0040BC20(cpu, LIFT_CODE_TOKEN_VA(0x4145C0u));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4145CAu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x4145CAu));
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->ecx = 0u;
    goto label_000145D5;

label_000145D2:
    cpu->ecx |= 0xFFFFFFFFu;

label_000145D5:
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x145DAu);

label_000145DA:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x50u;
    cpu->esp += 4u; cpu->eip = stop_address; return;

label_00014620:
    reinterpret_cast<SferaScriptContainer*>(cpu->ecx)->execute(*g_sfera_mbc_runtime); cpu->esp += 4u; cpu->eip = stop_address; return;

label_000146A0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x34u;
    cpu->esi = cpu->ecx;
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x4146D7u);
    if (cpu->eax > 9u) goto label_0001482B;
    switch (cpu->eax) {
        case 0u: goto label_00014746;
        case 1u: goto label_000147AD;
        case 2u: goto label_000147DC;
        case 3u: goto label_000146E7;
        case 4u: goto label_00014710;
        case 5u: goto label_00014739;
        case 6u: case 7u: case 8u: goto label_0001482B;
        case 9u: goto label_00014811;
        default: cpu->eip = 0x4146E0u; throw std::out_of_range("resolved jump-table index out of range"); return;
    }

label_000146E7:
 ;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x4146ECu);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x4146F3u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00014833;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414709u)); sfera_sub_00407300(cpu, LIFT_CODE_TOKEN_VA(0x414709u));
    cpu->ecx = cpu->eax;
    goto label_0001482E;

label_00014710:
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x414715u);
    cpu->edi = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x41471Cu);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00014833;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414732u)); sfera_sub_00407340(cpu, LIFT_CODE_TOKEN_VA(0x414732u));
    cpu->ecx = cpu->eax;
    goto label_0001482E;

label_00014739:
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 8u) == (uint8_t)(cpu->ecx));
    goto label_0001482E;

label_00014746:
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41474Fu)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x41474Fu));
    cpu->ecx = cpu->esp + 0x14u;
    *(uint32_t*)(cpu->esp + 0x3Cu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414760u)); sfera_sub_0040A500(cpu, LIFT_CODE_TOKEN_VA(0x414760u));
    *(uint8_t*)(cpu->esp + 0x3Cu) = 1u;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_0001478E;
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41477Bu)); sfera_sub_00413B80(cpu, LIFT_CODE_TOKEN_VA(0x41477Bu));
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414787u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x414787u));
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x1478Eu);

label_0001478E:
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x14797u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_RVA(0x14797u));

label_00014797:
    cpu->ecx = cpu->esp + 0xCu;
    *(uint32_t*)(cpu->esp + 0x3Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4147A8u)); sfera_sub_00402CF0(cpu, LIFT_CODE_TOKEN_VA(0x4147A8u));
    goto label_00014833;

label_000147AD:
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4147B6u)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x4147B6u));
    *(uint32_t*)(cpu->esp + 0x3Cu) = 2u;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != 0u) goto label_00014797;
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4147D3u)); sfera_sub_00411890(cpu, LIFT_CODE_TOKEN_VA(0x4147D3u));
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x4147DAu);
    goto label_00014797;

label_000147DC:
    cpu->ecx = cpu->esp + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4147E5u)); sfera_sub_00402720(cpu, LIFT_CODE_TOKEN_VA(0x4147E5u));
    *(uint32_t*)(cpu->esp + 0x3Cu) = 3u;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(&g_sfera_mbc_runtime->nextSliceReference())); cpu->eip = LIFT_CODE_TOKEN_VA(0x4147F2u);
    if (g_sfera_mbc_runtime->execution_failed != 0u) goto label_00014797;
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414808u)); sfera_sub_00409E90(cpu, LIFT_CODE_TOKEN_VA(0x414808u));
    cpu->ecx = cpu->eax;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_VA(0x41480Fu);
    goto label_00014797;

label_00014811:
    cpu->ecx = cpu->esi + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414819u)); sfera_sub_0040D740(cpu, LIFT_CODE_TOKEN_VA(0x414819u));
    lift_push32(cpu, 8u);
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x414823u)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x414823u));
    *(uint8_t*)(cpu->esi + 8u) = 0u;
    cpu->ecx = 0u;
    goto label_0001482E;

label_0001482B:
    cpu->ecx |= 0xFFFFFFFFu;

label_0001482E:
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->eip = LIFT_CODE_TOKEN_RVA(0x14833u);

label_00014833:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 4u; cpu->eip = stop_address; return;

label_00014880:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    --cpu->eax;
    if (cpu->eax > 4u) goto label_00014904;
    switch (cpu->eax) {
        case 0u: goto label_00014890;
        case 1u: goto label_000148AD;
        case 2u: goto label_00014904;
        case 3u: goto label_000148CA;
        case 4u: goto label_000148E7;
        default: cpu->eip = 0x414889u; throw std::out_of_range("resolved jump-table index out of range"); return;
    }

label_00014890:
 ;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xCu);
    if ((--cpu->eax) == 0u) goto label_000148A8;
    if ((cpu->eax -= 3u) == 0u) goto label_000148A3;
    if ((--cpu->eax) != 0u) goto label_00014904;
    goto label_000122D0;

label_000148A3:
    goto label_00013D00;

label_000148A8:
    goto label_00012160;

label_000148AD:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xCu);
    if ((--cpu->eax) == 0u) goto label_000148C5;
    if ((cpu->eax -= 3u) == 0u) goto label_000148C0;
    if ((--cpu->eax) != 0u) goto label_00014904;
    goto label_00012610;

label_000148C0:
    goto label_00013ED0;

label_000148C5:
    goto label_000124A0;

label_000148CA:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xCu);
    if ((--cpu->eax) == 0u) goto label_000148E2;
    if ((cpu->eax -= 3u) == 0u) goto label_000148DD;
    if ((--cpu->eax) != 0u) goto label_00014904;
    goto label_000146A0;

label_000148DD:
    goto label_00014250;

label_000148E2:
    goto label_000140A0;

label_000148E7:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xCu);
    if ((--cpu->eax) == 0u) goto label_000148FF;
    if ((cpu->eax -= 3u) == 0u) goto label_000148FA;
    if ((--cpu->eax) != 0u) goto label_00014904;
    goto label_00012990;

label_000148FA:
    goto label_00014440;

label_000148FF:
    goto label_000127F0;

label_00014904:
    cpu->esp += 4u; cpu->eip = stop_address; return;

label_00014920:
    cpu->eax = static_cast<std::uint32_t>(g_sfera_mbc_runtime->nextInteger()); cpu->eip = LIFT_CODE_TOKEN_VA(0x414925u);
    cpu->ecx = cpu->eax;
    if (cpu->ecx == 0u) goto label_00014938;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint32_t*)(cpu->ecx) == 0x19285u);
    if ((cpu->eax & 0xFFu) != 0u) goto label_00014940;

label_00014938:
    cpu->ecx |= 0xFFFFFFFFu;
    g_sfera_mbc_runtime->pushInteger(cpu->ecx); cpu->esp += 4u; cpu->eip = stop_address; return;

label_00014940:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    --cpu->eax;
    if (cpu->eax > 4u) goto label_00014979;
    switch (cpu->eax) {
        case 0u: goto label_00014950;
        case 1u: goto label_00014955;
        case 2u: goto label_0001495A;
        case 3u: goto label_0001496F;
        case 4u: goto label_00014974;
        default: cpu->eip = 0x414949u; throw std::out_of_range("resolved jump-table index out of range"); return;
    }

label_00014950:
    reinterpret_cast<SferaScriptContainer*>(cpu->ecx)->execute(*g_sfera_mbc_runtime); cpu->esp += 4u; cpu->eip = stop_address; return;

label_00014955:
    reinterpret_cast<SferaScriptContainer*>(cpu->ecx)->execute(*g_sfera_mbc_runtime); cpu->esp += 4u; cpu->eip = stop_address; return;

label_0001495A:
    reinterpret_cast<SferaScriptContainer*>(cpu->ecx)->execute(*g_sfera_mbc_runtime); cpu->esp += 4u; cpu->eip = stop_address; return;

label_0001496F:
    goto label_00014620;

label_00014974:
    goto label_00014880;

label_00014979:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_00416650(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if (cpu->eax == cpu->edi) goto label_00016666;
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00016666:
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->ecx) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edi;
    if (cpu->eax == *(uint32_t*)(cpu->esi + 4u)) goto label_00016696;
    label_00016684:
    cpu->edi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    cpu->eax = cpu->edi;
    if (cpu->edi != *(uint32_t*)(cpu->esi + 4u)) goto label_00016684;
    label_00016696:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00416A30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x14u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    if (cpu->eax == cpu->edi) goto label_00016A71;
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00016A71:
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->edi;
    cpu->edi = cpu->esi + 0x18u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    cpu->ecx = cpu->edi;
    *(uint8_t*)(cpu->esp + 0x1Cu) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416A8Du)); sfera_sub_0040A060(cpu, LIFT_CODE_TOKEN_VA(0x416A8Du));
    cpu->edi = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->edi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    reinterpret_cast<SferaDataContainerHeader*>(cpu->ecx)->invalidate(); cpu->eip = LIFT_CODE_TOKEN_VA(0x416AA7u);
    if (((*(uint8_t*)(cpu->esp + 0x24u)) & (1u)) == 0u) goto label_00016AB7;
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00016AB7:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00416AD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x14u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    if (cpu->eax == cpu->edi) goto label_00016B11;
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00016B11:
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->edi;
    cpu->edi = cpu->esi + 0x18u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    cpu->ecx = cpu->edi;
    *(uint8_t*)(cpu->esp + 0x1Cu) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416B2Du)); sfera_sub_00408A50(cpu, LIFT_CODE_TOKEN_VA(0x416B2Du));
    cpu->edi = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->edi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    reinterpret_cast<SferaDataContainerHeader*>(cpu->ecx)->invalidate(); cpu->eip = LIFT_CODE_TOKEN_VA(0x416B47u);
    if (((*(uint8_t*)(cpu->esp + 0x24u)) & (1u)) == 0u) goto label_00016B57;
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00016B57:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00416B70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x14u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    if (cpu->eax == cpu->edi) goto label_00016BB1;
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00016BB1:
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->edi;
    cpu->edi = cpu->esi + 0x18u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    cpu->ecx = cpu->edi;
    *(uint8_t*)(cpu->esp + 0x1Cu) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416BCDu)); sfera_sub_0040A0C0(cpu, LIFT_CODE_TOKEN_VA(0x416BCDu));
    cpu->edi = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->edi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    reinterpret_cast<SferaDataContainerHeader*>(cpu->ecx)->invalidate(); cpu->eip = LIFT_CODE_TOKEN_VA(0x416BE7u);
    if (((*(uint8_t*)(cpu->esp + 0x24u)) & (1u)) == 0u) goto label_00016BF7;
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00016BF7:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00416C10(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x28u;
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    reinterpret_cast<SferaDataContainerHeader*>(cpu->ecx)->initialize(); cpu->eax = cpu->ecx; cpu->eip = LIFT_CODE_TOKEN_VA(0x416C41u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(cpu->esp + 0x10u));
    cpu->esi = cpu->edi + 0x14u;
    cpu->ebx = 0u;
    *(uint16_t*)(cpu->esi) = cpu->eax & 0xFFFFu;
    lift_push32(cpu, 0x10u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_00016CC2;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ebx;
    x87_v0 = 1.0;
    lift_push32(cpu, 8u);
    *(float*)(cpu->esi + 0x28u) = x87_v0; 
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x34u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416C8Eu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x416C8Eu));
    *(uint8_t*)(cpu->esp + 0x30u) = 3u;
    *(uint32_t*)(cpu->edi + 0x40u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(SferaDataContainerHeader::ValueType::Integer); cpu->eip = LIFT_CODE_TOKEN_VA(0x416C9Bu);
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(SferaDataContainerHeader::ValueType::Integer); cpu->eip = LIFT_CODE_TOKEN_VA(0x416CA3u);
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 4u) = 5u;
    cpu->eax = cpu->edi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00016CC2:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416CECu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x416CECu));
    cpu->eip = 0x416CECu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_00416CF0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x28u;
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    reinterpret_cast<SferaDataContainerHeader*>(cpu->ecx)->initialize(); cpu->eax = cpu->ecx; cpu->eip = LIFT_CODE_TOKEN_VA(0x416D21u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(cpu->esp + 0x10u));
    cpu->esi = cpu->edi + 0x14u;
    cpu->ebx = 0u;
    *(uint16_t*)(cpu->esi) = cpu->eax & 0xFFFFu;
    lift_push32(cpu, 0x14u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_00016DA2;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ebx;
    x87_v0 = 1.0;
    lift_push32(cpu, 8u);
    *(float*)(cpu->esi + 0x28u) = x87_v0; 
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x34u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416D6Eu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x416D6Eu));
    *(uint8_t*)(cpu->esp + 0x30u) = 3u;
    *(uint32_t*)(cpu->edi + 0x40u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(SferaDataContainerHeader::ValueType::Binary); cpu->eip = LIFT_CODE_TOKEN_VA(0x416D7Bu);
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(SferaDataContainerHeader::ValueType::Integer); cpu->eip = LIFT_CODE_TOKEN_VA(0x416D83u);
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 4u) = 5u;
    cpu->eax = cpu->edi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00016DA2:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416DCCu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x416DCCu));
    cpu->eip = 0x416DCCu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_00416DD0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x28u;
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    reinterpret_cast<SferaDataContainerHeader*>(cpu->ecx)->initialize(); cpu->eax = cpu->ecx; cpu->eip = LIFT_CODE_TOKEN_VA(0x416E01u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(cpu->esp + 0x10u));
    cpu->esi = cpu->edi + 0x14u;
    cpu->ebx = 0u;
    *(uint16_t*)(cpu->esi) = cpu->eax & 0xFFFFu;
    lift_push32(cpu, 0x10u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_00016E82;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ebx;
    x87_v0 = 1.0;
    lift_push32(cpu, 8u);
    *(float*)(cpu->esi + 0x28u) = x87_v0; 
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x34u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416E4Eu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x416E4Eu));
    *(uint8_t*)(cpu->esp + 0x30u) = 3u;
    *(uint32_t*)(cpu->edi + 0x40u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(SferaDataContainerHeader::ValueType::Integer); cpu->eip = LIFT_CODE_TOKEN_VA(0x416E5Bu);
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(SferaDataContainerHeader::ValueType::Real); cpu->eip = LIFT_CODE_TOKEN_VA(0x416E63u);
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 4u) = 5u;
    cpu->eax = cpu->edi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00016E82:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416EACu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x416EACu));
    cpu->eip = 0x416EACu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_00416EB0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x28u;
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    reinterpret_cast<SferaDataContainerHeader*>(cpu->ecx)->initialize(); cpu->eax = cpu->ecx; cpu->eip = LIFT_CODE_TOKEN_VA(0x416EE1u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(cpu->esp + 0x10u));
    cpu->esi = cpu->edi + 0x14u;
    cpu->ebx = 0u;
    *(uint16_t*)(cpu->esi) = cpu->eax & 0xFFFFu;
    lift_push32(cpu, 0x14u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_00016F62;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ebx;
    x87_v0 = 1.0;
    lift_push32(cpu, 8u);
    *(float*)(cpu->esi + 0x28u) = x87_v0; 
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x34u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416F2Eu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x416F2Eu));
    *(uint8_t*)(cpu->esp + 0x30u) = 3u;
    *(uint32_t*)(cpu->edi + 0x40u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(SferaDataContainerHeader::ValueType::Binary); cpu->eip = LIFT_CODE_TOKEN_VA(0x416F3Bu);
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(SferaDataContainerHeader::ValueType::Real); cpu->eip = LIFT_CODE_TOKEN_VA(0x416F43u);
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 4u) = 5u;
    cpu->eax = cpu->edi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00016F62:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x416F8Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x416F8Cu));
    cpu->eip = 0x416F8Cu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_00416F90(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x28u;
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    reinterpret_cast<SferaDataContainerHeader*>(cpu->ecx)->initialize(); cpu->eax = cpu->ecx; cpu->eip = LIFT_CODE_TOKEN_VA(0x416FC1u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(cpu->esp + 0x10u));
    cpu->esi = cpu->edi + 0x14u;
    cpu->ebx = 0u;
    *(uint16_t*)(cpu->esi) = cpu->eax & 0xFFFFu;
    lift_push32(cpu, 0x14u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_00017042;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ebx;
    x87_v0 = 1.0;
    lift_push32(cpu, 8u);
    *(float*)(cpu->esi + 0x28u) = x87_v0; 
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x34u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41700Eu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x41700Eu));
    *(uint8_t*)(cpu->esp + 0x30u) = 3u;
    *(uint32_t*)(cpu->edi + 0x40u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(SferaDataContainerHeader::ValueType::Integer); cpu->eip = LIFT_CODE_TOKEN_VA(0x41701Bu);
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(SferaDataContainerHeader::ValueType::Binary); cpu->eip = LIFT_CODE_TOKEN_VA(0x417023u);
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 4u) = 5u;
    cpu->eax = cpu->edi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017042:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41706Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x41706Cu));
    cpu->eip = 0x41706Cu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_00417070(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x28u;
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    reinterpret_cast<SferaDataContainerHeader*>(cpu->ecx)->initialize(); cpu->eax = cpu->ecx; cpu->eip = LIFT_CODE_TOKEN_VA(0x4170A1u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(cpu->esp + 0x10u));
    cpu->esi = cpu->edi + 0x14u;
    cpu->ebx = 0u;
    *(uint16_t*)(cpu->esi) = cpu->eax & 0xFFFFu;
    lift_push32(cpu, 0x18u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_00017122;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ebx;
    x87_v0 = 1.0;
    lift_push32(cpu, 8u);
    *(float*)(cpu->esi + 0x28u) = x87_v0; 
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x34u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4170EEu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x4170EEu));
    *(uint8_t*)(cpu->esp + 0x30u) = 3u;
    *(uint32_t*)(cpu->edi + 0x40u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(SferaDataContainerHeader::ValueType::Binary); cpu->eip = LIFT_CODE_TOKEN_VA(0x4170FBu);
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(SferaDataContainerHeader::ValueType::Binary); cpu->eip = LIFT_CODE_TOKEN_VA(0x417103u);
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 4u) = 5u;
    cpu->eax = cpu->edi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017122:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41714Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x41714Cu));
    cpu->eip = 0x41714Cu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_004172F0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x28u;
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    reinterpret_cast<SferaDataContainerHeader*>(cpu->ecx)->initialize(); cpu->eax = cpu->ecx; cpu->eip = LIFT_CODE_TOKEN_VA(0x417321u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(cpu->esp + 0x10u));
    cpu->esi = cpu->edi + 0x14u;
    cpu->ebx = 0u;
    *(uint16_t*)(cpu->esi) = cpu->eax & 0xFFFFu;
    lift_push32(cpu, 0x28u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_000173A2;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ebx;
    x87_v0 = 1.0;
    lift_push32(cpu, 8u);
    *(float*)(cpu->esi + 0x28u) = x87_v0; 
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x34u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41736Eu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x41736Eu));
    *(uint8_t*)(cpu->esp + 0x30u) = 3u;
    *(uint32_t*)(cpu->edi + 0x40u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(SferaDataContainerHeader::ValueType::String); cpu->eip = LIFT_CODE_TOKEN_VA(0x41737Bu);
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(SferaDataContainerHeader::ValueType::Integer); cpu->eip = LIFT_CODE_TOKEN_VA(0x417383u);
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 4u) = 5u;
    cpu->eax = cpu->edi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000173A2:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4173CCu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4173CCu));
    cpu->eip = 0x4173CCu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_004173D0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x28u;
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    reinterpret_cast<SferaDataContainerHeader*>(cpu->ecx)->initialize(); cpu->eax = cpu->ecx; cpu->eip = LIFT_CODE_TOKEN_VA(0x417401u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(cpu->esp + 0x10u));
    cpu->esi = cpu->edi + 0x14u;
    cpu->ebx = 0u;
    *(uint16_t*)(cpu->esi) = cpu->eax & 0xFFFFu;
    lift_push32(cpu, 0x28u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_00017482;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ebx;
    x87_v0 = 1.0;
    lift_push32(cpu, 8u);
    *(float*)(cpu->esi + 0x28u) = x87_v0; 
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x34u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41744Eu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x41744Eu));
    *(uint8_t*)(cpu->esp + 0x30u) = 3u;
    *(uint32_t*)(cpu->edi + 0x40u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(SferaDataContainerHeader::ValueType::String); cpu->eip = LIFT_CODE_TOKEN_VA(0x41745Bu);
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(SferaDataContainerHeader::ValueType::Real); cpu->eip = LIFT_CODE_TOKEN_VA(0x417463u);
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 4u) = 5u;
    cpu->eax = cpu->edi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017482:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4174ACu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4174ACu));
    cpu->eip = 0x4174ACu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_004174B0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x28u;
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    reinterpret_cast<SferaDataContainerHeader*>(cpu->ecx)->initialize(); cpu->eax = cpu->ecx; cpu->eip = LIFT_CODE_TOKEN_VA(0x4174E1u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(cpu->esp + 0x10u));
    cpu->esi = cpu->edi + 0x14u;
    cpu->ebx = 0u;
    *(uint16_t*)(cpu->esi) = cpu->eax & 0xFFFFu;
    lift_push32(cpu, 0x28u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_00017562;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ebx;
    x87_v0 = 1.0;
    lift_push32(cpu, 8u);
    *(float*)(cpu->esi + 0x28u) = x87_v0; 
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x34u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41752Eu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x41752Eu));
    *(uint8_t*)(cpu->esp + 0x30u) = 3u;
    *(uint32_t*)(cpu->edi + 0x40u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(SferaDataContainerHeader::ValueType::Integer); cpu->eip = LIFT_CODE_TOKEN_VA(0x41753Bu);
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(SferaDataContainerHeader::ValueType::String); cpu->eip = LIFT_CODE_TOKEN_VA(0x417543u);
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 4u) = 5u;
    cpu->eax = cpu->edi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017562:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41758Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x41758Cu));
    cpu->eip = 0x41758Cu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_00417590(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x28u;
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    reinterpret_cast<SferaDataContainerHeader*>(cpu->ecx)->initialize(); cpu->eax = cpu->ecx; cpu->eip = LIFT_CODE_TOKEN_VA(0x4175C1u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(cpu->esp + 0x10u));
    cpu->esi = cpu->edi + 0x14u;
    cpu->ebx = 0u;
    *(uint16_t*)(cpu->esi) = cpu->eax & 0xFFFFu;
    lift_push32(cpu, 0x40u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_00017642;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ebx;
    x87_v0 = 1.0;
    lift_push32(cpu, 8u);
    *(float*)(cpu->esi + 0x28u) = x87_v0; 
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x34u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41760Eu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x41760Eu));
    *(uint8_t*)(cpu->esp + 0x30u) = 3u;
    *(uint32_t*)(cpu->edi + 0x40u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(SferaDataContainerHeader::ValueType::String); cpu->eip = LIFT_CODE_TOKEN_VA(0x41761Bu);
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(SferaDataContainerHeader::ValueType::String); cpu->eip = LIFT_CODE_TOKEN_VA(0x417623u);
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 4u) = 5u;
    cpu->eax = cpu->edi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017642:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41766Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x41766Cu));
    cpu->eip = 0x41766Cu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_00417670(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x28u;
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    reinterpret_cast<SferaDataContainerHeader*>(cpu->ecx)->initialize(); cpu->eax = cpu->ecx; cpu->eip = LIFT_CODE_TOKEN_VA(0x4176A1u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(cpu->esp + 0x10u));
    cpu->esi = cpu->edi + 0x14u;
    cpu->ebx = 0u;
    *(uint16_t*)(cpu->esi) = cpu->eax & 0xFFFFu;
    lift_push32(cpu, 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_00017722;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ebx;
    x87_v0 = 1.0;
    lift_push32(cpu, 8u);
    *(float*)(cpu->esi + 0x28u) = x87_v0; 
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x34u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4176EEu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x4176EEu));
    *(uint8_t*)(cpu->esp + 0x30u) = 3u;
    *(uint32_t*)(cpu->edi + 0x40u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(SferaDataContainerHeader::ValueType::Binary); cpu->eip = LIFT_CODE_TOKEN_VA(0x4176FBu);
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(SferaDataContainerHeader::ValueType::String); cpu->eip = LIFT_CODE_TOKEN_VA(0x417703u);
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 4u) = 5u;
    cpu->eax = cpu->edi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017722:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41774Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x41774Cu));
    cpu->eip = 0x41774Cu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_00417750(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x28u;
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    reinterpret_cast<SferaDataContainerHeader*>(cpu->ecx)->initialize(); cpu->eax = cpu->ecx; cpu->eip = LIFT_CODE_TOKEN_VA(0x417781u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(cpu->esp + 0x10u));
    cpu->esi = cpu->edi + 0x14u;
    cpu->ebx = 0u;
    *(uint16_t*)(cpu->esi) = cpu->eax & 0xFFFFu;
    lift_push32(cpu, 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_00017802;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ebx;
    x87_v0 = 1.0;
    lift_push32(cpu, 8u);
    *(float*)(cpu->esi + 0x28u) = x87_v0; 
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x34u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4177CEu)); sfera_sub_0040D7C0(cpu, LIFT_CODE_TOKEN_VA(0x4177CEu));
    *(uint8_t*)(cpu->esp + 0x30u) = 3u;
    *(uint32_t*)(cpu->edi + 0x40u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(SferaDataContainerHeader::ValueType::String); cpu->eip = LIFT_CODE_TOKEN_VA(0x4177DBu);
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->eax;
    cpu->eax = static_cast<std::uint32_t>(SferaDataContainerHeader::ValueType::Binary); cpu->eip = LIFT_CODE_TOKEN_VA(0x4177E3u);
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 4u) = 5u;
    cpu->eax = cpu->edi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017802:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41782Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x41782Cu));
    cpu->eip = 0x41782Cu; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_00417C70(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00017C70;
    label_00017830:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 8u;
    if ((--cpu->ecx) == 0u) goto label_000178E8;
    if ((cpu->ecx -= 3u) == 0u) goto label_000178A8;
    if ((--cpu->ecx) != 0u) goto label_00017928;
    cpu->edx = 0x8Fu;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 0x44u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 2u;
    if (cpu->eax == 0u) goto label_00017928;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417898u)); sfera_sub_00416CF0(cpu, LIFT_CODE_TOKEN_VA(0x417898u));
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000178A8:
    cpu->edx = 0x8Fu;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 0x44u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 1u;
    if (cpu->eax == 0u) goto label_00017928;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4178D8u)); sfera_sub_004172F0(cpu, LIFT_CODE_TOKEN_VA(0x4178D8u));
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000178E8:
    cpu->edx = 0x8Fu;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 0x44u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if (cpu->eax == 0u) goto label_00017928;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417918u)); sfera_sub_00416C10(cpu, LIFT_CODE_TOKEN_VA(0x417918u));
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017928:
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017940:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 8u;
    if ((--cpu->ecx) == 0u) goto label_000179F8;
    if ((cpu->ecx -= 3u) == 0u) goto label_000179B8;
    if ((--cpu->ecx) != 0u) goto label_00017A38;
    cpu->edx = 0x8Fu;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 0x44u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 2u;
    if (cpu->eax == 0u) goto label_00017A38;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4179A8u)); sfera_sub_00416EB0(cpu, LIFT_CODE_TOKEN_VA(0x4179A8u));
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000179B8:
    cpu->edx = 0x8Fu;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 0x44u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 1u;
    if (cpu->eax == 0u) goto label_00017A38;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4179E8u)); sfera_sub_004173D0(cpu, LIFT_CODE_TOKEN_VA(0x4179E8u));
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000179F8:
    cpu->edx = 0x8Fu;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 0x44u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if (cpu->eax == 0u) goto label_00017A38;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417A28u)); sfera_sub_00416DD0(cpu, LIFT_CODE_TOKEN_VA(0x417A28u));
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017A38:
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017A50:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 8u;
    if ((--cpu->ecx) == 0u) goto label_00017B08;
    if ((cpu->ecx -= 3u) == 0u) goto label_00017AC8;
    if ((--cpu->ecx) != 0u) goto label_00017B48;
    cpu->edx = 0x8Fu;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 0x44u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 2u;
    if (cpu->eax == 0u) goto label_00017B48;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417AB8u)); sfera_sub_00417670(cpu, LIFT_CODE_TOKEN_VA(0x417AB8u));
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017AC8:
    cpu->edx = 0x8Fu;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 0x44u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 1u;
    if (cpu->eax == 0u) goto label_00017B48;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417AF8u)); sfera_sub_00417590(cpu, LIFT_CODE_TOKEN_VA(0x417AF8u));
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017B08:
    cpu->edx = 0x8Fu;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 0x44u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if (cpu->eax == 0u) goto label_00017B48;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417B38u)); sfera_sub_004174B0(cpu, LIFT_CODE_TOKEN_VA(0x417B38u));
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017B48:
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017B60:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 8u;
    if ((--cpu->ecx) == 0u) goto label_00017C18;
    if ((cpu->ecx -= 3u) == 0u) goto label_00017BD8;
    if ((--cpu->ecx) != 0u) goto label_00017C58;
    cpu->edx = 0x8Fu;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 0x44u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 2u;
    if (cpu->eax == 0u) goto label_00017C58;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417BC8u)); sfera_sub_00417070(cpu, LIFT_CODE_TOKEN_VA(0x417BC8u));
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017BD8:
    cpu->edx = 0x8Fu;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 0x44u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 1u;
    if (cpu->eax == 0u) goto label_00017C58;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417C08u)); sfera_sub_00417750(cpu, LIFT_CODE_TOKEN_VA(0x417C08u));
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017C18:
    cpu->edx = 0x8Fu;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 0x44u);
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(*reinterpret_cast<const std::uint32_t*>(cpu->esp))));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if (cpu->eax == 0u) goto label_00017C58;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417C48u)); sfera_sub_00416F90(cpu, LIFT_CODE_TOKEN_VA(0x417C48u));
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017C58:
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017C70:
    cpu->eax = cpu->ecx + 0xFFFFFFFFu;
    if (cpu->eax > 4u) goto label_00017C9B;
    switch (cpu->eax) {
        case 0u: goto label_00017C7F;
        case 1u: goto label_00017C86;
        case 2u: goto label_00017C9B;
        case 3u: goto label_00017C8D;
        case 4u: goto label_00017C94;
        default: cpu->eip = 0x417C78u; throw std::out_of_range("resolved jump-table index out of range"); return;
    }
label_00017C7F: ;
    cpu->ecx = cpu->edx;
    goto label_00017830;
    label_00017C86:
    cpu->ecx = cpu->edx;
    goto label_00017940;
    label_00017C8D:
    cpu->ecx = cpu->edx;
    goto label_00017A50;
    label_00017C94:
    cpu->ecx = cpu->edx;
    goto label_00017B60;
    label_00017C9B:
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00417CC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if (cpu->eax == cpu->edi) goto label_00017CD6;
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00017CD6:
    cpu->ecx = cpu->esi + 0x18u;
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417CE7u)); sfera_sub_004BC130(cpu, LIFT_CODE_TOKEN_VA(0x417CE7u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18u);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    reinterpret_cast<SferaDataContainerHeader*>(cpu->ecx)->invalidate(); cpu->eip = LIFT_CODE_TOKEN_VA(0x417CFAu);
    if (((*(uint8_t*)(cpu->esp + 0xCu)) & (1u)) == 0u) goto label_00017D0A;
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00017D0A:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00417D20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if (cpu->eax == cpu->edi) goto label_00017D36;
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00017D36:
    cpu->ecx = cpu->esi + 0x18u;
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417D47u)); sfera_sub_0040BB40(cpu, LIFT_CODE_TOKEN_VA(0x417D47u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18u);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    reinterpret_cast<SferaDataContainerHeader*>(cpu->ecx)->invalidate(); cpu->eip = LIFT_CODE_TOKEN_VA(0x417D5Au);
    if (((*(uint8_t*)(cpu->esp + 0xCu)) & (1u)) == 0u) goto label_00017D6A;
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00017D6A:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00417D80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if (cpu->eax == cpu->edi) goto label_00017D96;
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00017D96:
    cpu->ecx = cpu->esi + 0x18u;
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417DA7u)); sfera_sub_0040BBA0(cpu, LIFT_CODE_TOKEN_VA(0x417DA7u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18u);
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    reinterpret_cast<SferaDataContainerHeader*>(cpu->ecx)->invalidate(); cpu->eip = LIFT_CODE_TOKEN_VA(0x417DBAu);
    if (((*(uint8_t*)(cpu->esp + 0xCu)) & (1u)) == 0u) goto label_00017DCA;
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00017DCA:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00417DE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x14u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    if (cpu->eax == cpu->edi) goto label_00017E21;
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00017E21:
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->edi;
    cpu->edi = cpu->esi + 0x18u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    cpu->ecx = cpu->edi;
    *(uint8_t*)(cpu->esp + 0x1Cu) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417E3Du)); sfera_sub_0040D740(cpu, LIFT_CODE_TOKEN_VA(0x417E3Du));
    cpu->edi = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->edi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    reinterpret_cast<SferaDataContainerHeader*>(cpu->ecx)->invalidate(); cpu->eip = LIFT_CODE_TOKEN_VA(0x417E57u);
    if (((*(uint8_t*)(cpu->esp + 0x24u)) & (1u)) == 0u) goto label_00017E67;
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00017E67:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00417E80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x14u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    if (cpu->eax == cpu->edi) goto label_00017EC1;
    lift_push32(cpu, cpu->eax);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00017EC1:
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->edi;
    cpu->edi = cpu->esi + 0x18u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    cpu->ecx = cpu->edi;
    *(uint8_t*)(cpu->esp + 0x1Cu) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417EDDu)); sfera_sub_0040BC20(cpu, LIFT_CODE_TOKEN_VA(0x417EDDu));
    cpu->edi = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, cpu->edi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    reinterpret_cast<SferaDataContainerHeader*>(cpu->ecx)->invalidate(); cpu->eip = LIFT_CODE_TOKEN_VA(0x417EF7u);
    if (((*(uint8_t*)(cpu->esp + 0x24u)) & (1u)) == 0u) goto label_00017F07;
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    label_00017F07:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00417F20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    if ((--cpu->eax) == 0u) goto label_00017F6E;
    if ((cpu->eax -= 3u) == 0u) goto label_00017F52;
    if ((--cpu->eax) == 0u) goto label_00017F36;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017F36:
    cpu->edx = 0x9Du;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417F4Eu)); sfera_sub_00416A30(cpu, LIFT_CODE_TOKEN_VA(0x417F4Eu));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017F52:
    cpu->edx = 0x9Du;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417F6Au)); sfera_sub_00417CC0(cpu, LIFT_CODE_TOKEN_VA(0x417F6Au));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017F6E:
    cpu->edx = 0x9Du;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417F85u)); sfera_sub_00416650(cpu, LIFT_CODE_TOKEN_VA(0x417F85u));
    cpu->ecx = cpu->esi;
    reinterpret_cast<SferaDataContainerHeader*>(cpu->ecx)->invalidate(); cpu->eip = LIFT_CODE_TOKEN_VA(0x417F8Cu);
    lift_push32(cpu, cpu->esi);
    WorldMemory::release(reinterpret_cast<void*>(*reinterpret_cast<const std::uint32_t*>(cpu->esp)));
    cpu->esp += 4u;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00417FA0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    if ((--cpu->eax) == 0u) goto label_00017FEE;
    if ((cpu->eax -= 3u) == 0u) goto label_00017FD2;
    if ((--cpu->eax) == 0u) goto label_00017FB6;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017FB6:
    cpu->edx = 0x9Du;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417FCEu)); sfera_sub_00417DE0(cpu, LIFT_CODE_TOKEN_VA(0x417FCEu));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017FD2:
    cpu->edx = 0x9Du;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x417FEAu)); sfera_sub_00417D80(cpu, LIFT_CODE_TOKEN_VA(0x417FEAu));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00017FEE:
    cpu->edx = 0x9Du;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418006u)); sfera_sub_00417D20(cpu, LIFT_CODE_TOKEN_VA(0x418006u));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00418010(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    if ((--cpu->eax) == 0u) goto label_0001805E;
    if ((cpu->eax -= 3u) == 0u) goto label_00018042;
    if ((--cpu->eax) == 0u) goto label_00018026;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00018026:
    cpu->edx = 0x9Du;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41803Eu)); sfera_sub_00416B70(cpu, LIFT_CODE_TOKEN_VA(0x41803Eu));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00018042:
    cpu->edx = 0x9Du;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41805Au)); sfera_sub_00417E80(cpu, LIFT_CODE_TOKEN_VA(0x41805Au));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0001805E:
    cpu->edx = 0x9Du;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\datacont\\sUMapContainer.h";
    g_sfera_memory_runtime.allocation_source_name = reinterpret_cast<const char*>(cpu->ecx); g_sfera_memory_runtime.allocation_source_line = cpu->edx;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418076u)); sfera_sub_00416AD0(cpu, LIFT_CODE_TOKEN_VA(0x418076u));
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}


__declspec(noinline) void sfera_sub_00418750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x414u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x418u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = g_sfera_recovered_static_runtime.server_number;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\%d%s");
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, 0x400u); lift_push32(cpu, cpu->ecx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (1u & 0xFFu);
    lift_native_call(cpu, native_function_address32(&::_snprintf), LIFT_CODE_TOKEN_VA(0x418787u));
    cpu->ebp = native_function_address32(&::fopen);
    cpu->edx = cpu->esp + 0x34u;
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->edx);
    cpu->edi = 0u;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fopen)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->esi = cpu->eax;
    cpu->esp += 0x1Cu;
    if (cpu->esi == 0u) goto label_00018875;
    cpu->edi = native_function_address32(&::fclose);
    label_000187B4:
    if ((cpu->ebx & 0xFFu) != 1u) goto label_00018815;
    lift_push32(cpu, 2u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fseek), LIFT_CODE_TOKEN_VA(0x4187BEu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::ftell), LIFT_CODE_TOKEN_VA(0x4187C5u));
    cpu->esp += 0x10u;
    if ((int32_t)cpu->eax <= (int32_t)0x989680u) goto label_00018815;
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fclose)))(*(uint32_t*)(cpu->esp));
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, (uintptr_t)"w"); lift_push32(cpu, cpu->eax);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fopen)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->esi = cpu->eax;
    cpu->esp += 0xCu;
    if (cpu->esi == 0u) goto label_00018815;
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x4187F3u));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fclose)))(*(uint32_t*)(cpu->esp));
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->ecx);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fopen)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->esi = cpu->eax;
    cpu->esp += 0x14u;
    if (cpu->esi != 0u) goto label_000187B4;
    goto label_00018877;
    label_00018815:
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::GetLocalTime), LIFT_CODE_TOKEN_VA(0x41881Au));
    cpu->eax = *(uint16_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint16_t*)(cpu->esp + 0x1Au);
    cpu->edx = *(uint16_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint16_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint16_t*)(cpu->esp + 0x1Au);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint16_t*)(cpu->esp + 0x22u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"%02u.%02u.%04u %02u:%02u:%02u "); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x41884Au));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44Cu);
    cpu->ebx = cpu->eax;
    cpu->eax = cpu->esp + 0x450u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::vfprintf), LIFT_CODE_TOKEN_VA(0x418863u));
    lift_push32(cpu, cpu->esi);
    cpu->ebx += cpu->eax;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fclose)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 0x30u;
    cpu->eax = cpu->ebx;
    goto label_00018877;
    label_00018875:
    cpu->eax = cpu->edi;
    label_00018877:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x414u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004188A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4188CEu)); sfera_sub_00419810(cpu, LIFT_CODE_TOKEN_VA(0x4188CEu));
    cpu->ebx = 0u;
    lift_push32(cpu, 0x23u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\TCP-IP\\ClientConnectMngr.cpp";
    cpu->ecx = 0x13880u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xEA68u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xEA6Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xEA70u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xEA74u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xEA78u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xEA7Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xEA80u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xEA84u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0xEA88u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0xEA8Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xEA90u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xEA94u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xEA98u) = cpu->ebx;
    cpu->eax = static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(WorldMemory::allocate(cpu->ecx, reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp), false))); cpu->esp += 4u;
    lift_push32(cpu, 0x13880u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 0xEA9Cu) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x418940u));
    cpu->eax = 0u;
    lift_push32(cpu, (uintptr_t)"============================================================================\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    *(uint32_t*)(cpu->esi + 0xEAA0u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0xEAA4u) = cpu->ebx & 0xFFu;
    *(uint8_t*)(cpu->esi + 0xEAA6u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0xEAA8u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xEAACu) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0xEAB0u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0xEAB2u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xEAB8u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418986u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x418986u));
    lift_push32(cpu, (uintptr_t)"Create connect manager\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418995u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x418995u));
    cpu->esp += 0x1Cu;
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00418A20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (1u & 0xFFu);
    if (*(uint8_t*)(cpu->esi + 0xEAA4u) != (cpu->ebx & 0xFFu)) goto label_00018B10;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"Deinit TCP-IP manager(1)\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418A43u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x418A43u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xEA70u);
    cpu->edi = native_function_address32(&::WaitForSingleObject);
    cpu->esp += 8u;
    lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->esi + 0xEA88u) = cpu->ebx & 0xFFu;
    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::WaitForSingleObject)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u)); cpu->esp += 0x8u;
    cpu->ebx = native_function_address32(&::TerminateThread);
    if (cpu->eax == 0u) goto label_00018A72;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xEA70u);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::TerminateThread)))(cpu->ecx, 0u);
    label_00018A72:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xEA70u);
    cpu->ebp = native_function_address32(&::CloseHandle);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::CloseHandle)))(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xEA78u);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::WaitForSingleObject)))(cpu->eax, 0x64u);
    if (cpu->eax == 0u) goto label_00018A9B;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xEA78u);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::TerminateThread)))(cpu->ecx, 0u);
    label_00018A9B:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xEA78u);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::CloseHandle)))(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xEA80u);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::WaitForSingleObject)))(cpu->eax, 0x64u);
    if (cpu->eax == 0u) goto label_00018ABE;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xEA80u);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::TerminateThread)))(cpu->ecx, 0u);
    label_00018ABE:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xEA80u);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::CloseHandle)))(cpu->edx);
    lift_push32(cpu, (uintptr_t)"Deinit TCP-IP manager(2)\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418AD6u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x418AD6u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xEA68u);
    cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if (cpu->eax == 0u) goto label_00018AF0;
    if (cpu->eax == 0xFFFFFFFFu) goto label_00018AF0;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::closesocket), LIFT_CODE_TOKEN_VA(0x418AEBu));
    label_00018AF0:
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x418AF0u));
    lift_push32(cpu, (uintptr_t)"Deinit TCP-IP manager(3)\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    *(uint16_t*)(cpu->esi + 0xEAA4u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418B0Du)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x418B0Du));
    cpu->esp += 8u;
    label_00018B10:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00418BB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, (uintptr_t)&g_sfera_network_send_runtime.critical_section);
    *(uint32_t*)(cpu->esp + 0x18u) = (uintptr_t)&g_sfera_network_send_runtime.critical_section;
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x418BE4u));
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = cpu->ebx + 8u;
    cpu->ebp = cpu->eax & 0xFFFFu;
    cpu->ecx = 0x13880u;
    cpu->ecx -= *(uint32_t*)(cpu->esi + 0xEAA0u);
    cpu->edi = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    if ((int32_t)cpu->ecx >= (int32_t)cpu->edi) goto label_00018C4F;
    lift_push32(cpu, (uintptr_t)"-------------------------ERROR: send buffer overload\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418C1Cu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x418C1Cu));
    g_sfera_network_runtime.initialization_result = 0xFFFFFFFFu;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xEA68u);
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_00018C3E;
    if (cpu->eax == 0xFFFFFFFFu) goto label_00018C3E;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::closesocket), LIFT_CODE_TOKEN_VA(0x418C39u));
    label_00018C3E:
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x418C3Eu));
    *(uint8_t*)(cpu->esi + 0xEAA5u) = 0u;
    goto label_00018D2B;
    label_00018C4F:
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x418C4Fu));
    cpu->eax&=0x80000003u;
    if (((cpu->eax)&0x80000000u)==0u) goto label_00018C61;
    --cpu->eax;
    cpu->eax |= 0xFFFFFFFCu;
    ++cpu->eax;
    label_00018C61:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xEAA0u);
    ++cpu->eax;
    *(uint16_t*)(cpu->esi + 0xEAB2u) = (uint64_t)(*(uint16_t*)(cpu->esi + 0xEAB2u)) + (uint64_t)((cpu->eax & 0xFFFFu)) + (uint64_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xEA9Cu);
    *(uint16_t*)(cpu->edx + cpu->eax) = cpu->ebp & 0xFFFFu;
    cpu->eax = *(uint16_t*)(cpu->esi + 0xEAB2u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xEAA0u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xEA9Cu);
    *(uint16_t*)(cpu->ecx + cpu->edx + 4u) = cpu->eax & 0xFFFFu;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xEAA0u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xEA9Cu);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (*(uint16_t*)(cpu->esp + 0x2Cu));
    *(uint16_t*)(cpu->ecx + cpu->edx + 6u) = cpu->eax & 0xFFFFu;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xEAA0u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xEA9Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edx + cpu->eax + 8u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x418CBEu));
    cpu->eax = 4u;
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esp + 0x28u) = 0u;
    if ((int32_t)cpu->edi <= (int32_t)cpu->eax) goto label_00018CFF;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xEA9Cu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xEAA0u);
    cpu->edx += cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)(cpu->esp + 0x28u));
    label_00018CF0:
    cpu->ebx = (cpu->ebx & 0xFFFF0000u) | ((uint32_t)(((int8_t)(*(uint8_t*)(cpu->edx + cpu->eax)))) & 0xFFFFu);
    ++cpu->eax;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFFFu)) + (uint64_t)((cpu->ebx & 0xFFFFu)) + (uint64_t)(0u))) & 0xFFFFu);
    if ((int32_t)cpu->eax < (int32_t)cpu->edi) goto label_00018CF0;
    goto label_00018D04;
    label_00018CFF:
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)(cpu->esp + 0x28u));
    label_00018D04:
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(cpu->esi + 0xEAB4u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xEAA0u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFFFu)) ^ (uint64_t)((cpu->ecx & 0xFFFFu)))) & 0xFFFFu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xEA9Cu);
    *(uint16_t*)(cpu->eax + cpu->ecx + 2u) = cpu->edx & 0xFFFFu;
    *(uint32_t*)(cpu->esi + 0xEAA0u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0xEAA0u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u);
    ++*(uint32_t*)(cpu->esi + 0xEAB8u);
    label_00018D2B:
    lift_push32(cpu, (uintptr_t)&g_sfera_network_send_runtime.critical_section);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x418D30u));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00418D50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418D85u)); sfera_sub_00418A20(cpu, LIFT_CODE_TOKEN_VA(0x418D85u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xEA9Cu);
    lift_push32(cpu, 0x3Au);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\TCP-IP\\ClientConnectMngr.cpp";
    WorldMemory::release(reinterpret_cast<void*>(cpu->ecx), reinterpret_cast<const char*>(cpu->edx), *reinterpret_cast<const std::uint32_t*>(cpu->esp)); cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x418DA6u)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x418DA6u));
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004193E0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x1A8u;
    sub_pred[0] = (uint8_t)(*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled) == 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1B4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (!sub_pred[0]) goto label_00019410;
    cpu->eax |= 0xFFFFFFFFu;
    goto label_00019716;
    label_00019410:
    if (*(uint8_t*)(cpu->edi + 0xEAA4u) != 1u) goto label_0001943B;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1B4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"-------------------------ERROR: ALREADY Init TCP-IP manager (%d '%s')\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419431u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x419431u));
    cpu->esp += 0x10u;
    cpu->eax = 0u;
    goto label_00019716;
    label_0001943B:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1B8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager (%d '%s')\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419454u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x419454u));
    cpu->esp += 0x10u;
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x102u);
    lift_native_call(cpu, native_function_address32(&::WSAStartup), LIFT_CODE_TOKEN_VA(0x419461u));
    if (cpu->eax == 0u) goto label_00019479;
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x41946Au));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(1)--init connect manager (%d '%s'), error=%d\n");
    goto label_000194A3;
    label_00019479:
    lift_push32(cpu, 6u); lift_push32(cpu, 1u); lift_push32(cpu, 2u);
    lift_native_call(cpu, native_function_address32(&::socket), LIFT_CODE_TOKEN_VA(0x41947Fu));
    *(uint32_t*)(cpu->edi + 0xEA68u) = cpu->eax;
    if (cpu->eax != 0xFFFFFFFFu) goto label_000194B8;
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x41948Fu));
    cpu->edi = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x419496u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(2)--init connect manager (%d '%s'), error=%d\n");
    label_000194A3:
    lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4194ADu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x4194ADu));
    cpu->esp += 0x14u;
    cpu->eax |= 0xFFFFFFFFu;
    goto label_00019715;
    label_000194B8:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager (%d '%s'), skt=%d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4194CCu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x4194CCu));
    cpu->eax = *(uint32_t*)(cpu->edi + 0xEA68u);
    cpu->esp += 0x14u;
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u); lift_push32(cpu, 6u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x24u) = 1u;
    lift_native_call(cpu, native_function_address32(&::setsockopt), LIFT_CODE_TOKEN_VA(0x4194E9u));
    cpu->ebx = cpu->eax;
    if ((int32_t)cpu->ebx >= 0) goto label_0001950D;
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x4194F4u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(2_1)--init connect manager (%d), error=%d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41950Au)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x41950Au));
    cpu->esp += 0x10u;
    label_0001950D:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager (%d '%s') - no delay res = %d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41951Fu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x41951Fu));
    cpu->esp += 0x14u;
    cpu->ecx = 2u;
    lift_push32(cpu, cpu->ebp);
    *(uint16_t*)(cpu->esp + 0x18u) = cpu->ecx & 0xFFFFu;
    lift_native_call(cpu, native_function_address32(&::htons), LIFT_CODE_TOKEN_VA(0x41952Du));
    lift_push32(cpu, cpu->esi);
    *(uint16_t*)(cpu->esp + 0x1Au) = cpu->eax & 0xFFFFu;
    lift_native_call(cpu, native_function_address32(&::inet_addr), LIFT_CODE_TOKEN_VA(0x419538u));
    lift_push32(cpu, cpu->esi);
    if (cpu->eax == 0xFFFFFFFFu) goto label_0001955E;
    lift_native_call(cpu, native_function_address32(&::inet_addr), LIFT_CODE_TOKEN_VA(0x419543u));
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::inet_ntoa), LIFT_CODE_TOKEN_VA(0x41954Du));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager(1) (%d '%s'), skt=%d, adr='%s'\n");
    goto label_00019586;
    label_0001955E:
    lift_native_call(cpu, native_function_address32(&::gethostbyname), LIFT_CODE_TOKEN_VA(0x41955Eu));
    if (cpu->eax == 0u) goto label_000196E4;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::inet_ntoa), LIFT_CODE_TOKEN_VA(0x419577u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager(2) (%d '%s'), skt=%d, adr='%s'\n");
    label_00019586:
    lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x419590u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x419590u));
    cpu->edx = *(uint32_t*)(cpu->edi + 0xEA68u);
    cpu->esp += 0x18u;
    lift_push32(cpu, 0x10u);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::connect), LIFT_CODE_TOKEN_VA(0x4195A1u));
    if (cpu->eax == 0u) goto label_000195FB;
    lift_native_call(cpu, native_function_address32(&::_errno), LIFT_CODE_TOKEN_VA(0x4195AAu));
    cpu->edi = *(uint32_t*)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x4195B2u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(4_1)--init connect manager (%d '%s') \n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4195CAu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x4195CAu));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(4_2)--init connect manager (%d '%s'), errno=%d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4195DCu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x4195DCu));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(4_3)--init connect manager (%d '%s'), lastError=%d\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4195EEu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x4195EEu));
    cpu->esp += 0x38u;
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x4195F1u));
    goto label_00019711;
    label_000195FB:
    cpu->eax = cpu->edi + 0xEA74u;
    *(uint8_t*)(cpu->edi + 0xEA88u) = 0u;
    cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(::CreateThread(nullptr, 0u, &sfera_tcp_socket_receive_thread, reinterpret_cast<void*>(static_cast<uintptr_t>(cpu->edi)), 0u, reinterpret_cast<DWORD*>(static_cast<uintptr_t>(cpu->eax)))));
    *(uint32_t*)(cpu->edi + 0xEA70u) = cpu->eax;
    if (cpu->eax != 0u) goto label_00019638;
    lift_native_call(cpu, native_function_address32(&::GetLastError), LIFT_CODE_TOKEN_VA(0x419625u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(5)--init connect manager (%d '%s'), error=%d\n");
    goto label_00019704;
    label_00019638:
    cpu->ebx = native_function_address32(&::SetThreadPriority);

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::SetThreadPriority)))(cpu->eax, 0u);
    cpu->ecx = cpu->edi + 0xEA7Cu;
    cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(::CreateThread(nullptr, 0u, &sfera_tcp_send_maintenance_thread, reinterpret_cast<void*>(static_cast<uintptr_t>(cpu->edi)), 0u, reinterpret_cast<DWORD*>(static_cast<uintptr_t>(cpu->ecx)))));
    *(uint32_t*)(cpu->edi + 0xEA78u) = cpu->eax;
    if (cpu->eax != 0u) goto label_00019679;
    lift_native_call(cpu, native_function_address32(&::GetLastError), LIFT_CODE_TOKEN_VA(0x419666u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(6)--init connect manager (%d '%s'), error=%d\n");
    goto label_00019704;
    label_00019679:

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::SetThreadPriority)))(cpu->eax, 0u);
    cpu->edx = cpu->edi + 0xEA84u;
    cpu->eax = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(::CreateThread(nullptr, 0u, &sfera_tcp_receive_dispatch_thread, reinterpret_cast<void*>(static_cast<uintptr_t>(cpu->edi)), 0u, reinterpret_cast<DWORD*>(static_cast<uintptr_t>(cpu->edx)))));
    *(uint32_t*)(cpu->edi + 0xEA80u) = cpu->eax;
    if (cpu->eax != 0u) goto label_000196B1;
    lift_native_call(cpu, native_function_address32(&::GetLastError), LIFT_CODE_TOKEN_VA(0x4196A1u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(7)--init connect manager (%d '%s'), error=%d\n");
    goto label_00019704;
    label_000196B1:

    cpu->eax = reinterpret_cast<uint32_t (__stdcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::SetThreadPriority)))(cpu->eax, 0u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::inet_ntoa), LIFT_CODE_TOKEN_VA(0x4196BBu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager(3) (%d '%s'), skt=%d, adr='%s'\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4196D4u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x4196D4u));
    cpu->esp += 0x18u;
    *(uint16_t*)(cpu->edi + 0xEAA4u) = 0x101u;
    cpu->eax = 0u;
    goto label_00019714;
    label_000196E4:
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x4196E4u));
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xEA68u);
    lift_push32(cpu, cpu->ecx);
    cpu->ebx = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::closesocket), LIFT_CODE_TOKEN_VA(0x4196F2u));
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x4196F7u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"---error(3)--init connect manager (%d '%s'), error=%d\n");
    label_00019704:
    lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x41970Eu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x41970Eu));
    cpu->esp += 0x14u;
    label_00019711:
    cpu->eax |= 0xFFFFFFFFu;
    label_00019714:
    cpu->ebx = lift_pop32(cpu);
    label_00019715:
    cpu->ebp = lift_pop32(cpu);
    label_00019716:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1A8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00419810(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0xEA60u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x41981Bu));
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esi + 0xEA60u) = 0u;
    *(uint32_t*)(cpu->esi + 0xEA64u) = 0u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00419840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    cpu->eax = *(uint32_t*)((uintptr_t)"0123456789ABCDEF");
    *(uint32_t*)(cpu->esp) = cpu->eax;
    cpu->eax = *(uint32_t*)(((uintptr_t)"0123456789ABCDEF") + 4u);
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(((uintptr_t)"0123456789ABCDEF") + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    cpu->eax = *(uint32_t*)(((uintptr_t)"0123456789ABCDEF") + 0xCu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"0123456789ABCDEF") + 0x10u));
    cpu->esi += cpu->ecx;
    *(uint8_t*)(cpu->esp + 0x14u) = cpu->eax & 0xFFu;
    if (cpu->ecx >= cpu->esi) goto label_000198E6;
    label_00019885:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x61u) goto label_0001988F;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x7Au) goto label_000198DE;
    label_0001988F:
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x41u) goto label_00019897;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x5Au) goto label_000198DE;
    label_00019897:
    if ((int8_t)(cpu->eax & 0xFFu) < (int8_t)0x30u) goto label_0001989F;
    if ((int8_t)(cpu->eax & 0xFFu) <= (int8_t)0x39u) goto label_000198DE;
    label_0001989F:
    if ((cpu->eax & 0xFFu) == 0x2Du) goto label_000198DE;
    if ((cpu->eax & 0xFFu) == 0x5Fu) goto label_000198DE;
    if ((cpu->eax & 0xFFu) == 0x2Eu) goto label_000198DE;
    if ((cpu->eax & 0xFFu) == 0x7Eu) goto label_000198DE;
    if ((cpu->eax & 0xFFu) == 0u) goto label_000198FC;
    cpu->eax = cpu->esi + 0xFFFFFFFEu;
    if (cpu->ecx >= cpu->eax) goto label_00019901;
    *(uint8_t*)(cpu->ecx) = 0x25u;
    cpu->eax = *(uint8_t*)(cpu->edx);
    cpu->eax >>= 4u;
    cpu->eax = *(uint8_t*)(cpu->esp + cpu->eax + 4u);
    *(uint8_t*)(cpu->ecx + 1u) = cpu->eax & 0xFFu;
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->edx));
    cpu->eax &= 0xFu;
    cpu->eax = *(uint8_t*)(cpu->esp + cpu->eax + 4u);
    *(uint8_t*)(cpu->ecx + 2u) = cpu->eax & 0xFFu;
    cpu->ecx += 3u;
    goto label_000198E1;
    label_000198DE:
    *(uint8_t*)(cpu->ecx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    label_000198E1:
    ++cpu->edx;
    if (cpu->ecx < cpu->esi) goto label_00019885;
    label_000198E6:
    *(uint8_t*)(cpu->esi + 0xFFFFFFFFu) = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000198FC:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    *(uint8_t*)(cpu->ecx) = cpu->edx & 0xFFu;
    ++cpu->ecx;
    label_00019901:
    if (cpu->ecx >= cpu->esi) goto label_000198E6;
    *(uint8_t*)(cpu->ecx) = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}


} // namespace lifted
