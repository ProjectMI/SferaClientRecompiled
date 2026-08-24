#include "lifted_functions.h"
#include "lifted_normalized_ops.h"
#include <math.h>

static void sfera_mbinter_execute_opcode(LiftCpu* cpu, uint32_t stop_address, uint32_t opcode) {
    switch (opcode & 0xFFu) {
        case 0u:
        case 1u:
            sfera_sub_0043BB30(cpu, stop_address);
            return;
        case 2u:
            sfera_sub_0043BB80(cpu, stop_address);
            return;
        case 3u:
            sfera_sub_0043BBC0(cpu, stop_address);
            return;
        case 4u:
            sfera_sub_0043BBF0(cpu, stop_address);
            return;
        case 5u:
            sfera_sub_0043BCF0(cpu, stop_address);
            return;
        case 6u:
            sfera_sub_0043BC90(cpu, stop_address);
            return;
        case 7u:
            sfera_sub_0043BC50(cpu, stop_address);
            return;
        case 8u:
            sfera_sub_0043BD20(cpu, stop_address);
            return;
        case 9u:
            sfera_sub_0043F870(cpu, stop_address);
            return;
        case 0xAu:
            sfera_sub_00440750(cpu, stop_address);
            return;
        case 0xBu:
            sfera_sub_0043BFA0(cpu, stop_address);
            return;
        case 0xCu:
            sfera_sub_0043C110(cpu, stop_address);
            return;
        case 0xDu:
            sfera_sub_0043C150(cpu, stop_address);
            return;
        case 0xEu:
            sfera_sub_0043C1A0(cpu, stop_address);
            return;
        case 0xFu:
            sfera_sub_00441FE0(cpu, stop_address);
            return;
        case 0x10u:
            sfera_sub_0043C1D0(cpu, stop_address);
            return;
        case 0x11u:
            sfera_sub_0043C230(cpu, stop_address);
            return;
        case 0x12u:
            sfera_sub_0043C2C0(cpu, stop_address);
            return;
        case 0x13u:
            sfera_sub_0043C350(cpu, stop_address);
            return;
        case 0x14u:
            sfera_sub_0043C770(cpu, stop_address);
            return;
        case 0x15u:
            sfera_sub_0043C7C0(cpu, stop_address);
            return;
        case 0x16u:
            sfera_sub_0043C7E0(cpu, stop_address);
            return;
        case 0x17u:
            sfera_sub_0043C840(cpu, stop_address);
            return;
        case 0x18u:
            sfera_sub_0043C8A0(cpu, stop_address);
            return;
        case 0x19u:
        case 0x1Bu:
            sfera_sub_0043D3A0(cpu, stop_address);
            return;
        case 0x1Au:
            sfera_sub_0043C980(cpu, stop_address);
            return;
        case 0x1Cu:
            sfera_sub_0043C3A0(cpu, stop_address);
            return;
        case 0x1Du:
            sfera_sub_0043D490(cpu, stop_address);
            return;
        case 0x1Eu:
            sfera_sub_0043D4C0(cpu, stop_address);
            return;
        case 0x1Fu:
            sfera_sub_00437E10(cpu, stop_address);
            return;
        case 0x20u:
            sfera_sub_0043D550(cpu, stop_address);
            return;
        case 0x21u:
            sfera_sub_0043CCC0(cpu, stop_address);
            return;
        case 0x22u:
            sfera_sub_0043D5B0(cpu, stop_address);
            return;
        case 0x23u:
            sfera_sub_0043D7C0(cpu, stop_address);
            return;
        case 0x24u:
            sfera_sub_0043DA90(cpu, stop_address);
            return;
        case 0x25u:
            sfera_sub_0043DBC0(cpu, stop_address);
            return;
        case 0x26u:
            sfera_sub_0043DDE0(cpu, stop_address);
            return;
        case 0x27u:
            sfera_sub_0043C910(cpu, stop_address);
            return;
        case 0x28u:
            sfera_sub_0043E6F0(cpu, stop_address);
            return;
        case 0x29u:
            sfera_sub_0043E780(cpu, stop_address);
            return;
        case 0x2Au:
            sfera_sub_0043E890(cpu, stop_address);
            return;
        case 0x2Bu:
            sfera_sub_0043E8C0(cpu, stop_address);
            return;
        case 0x2Cu:
            sfera_sub_0043E940(cpu, stop_address);
            return;
        case 0x2Du:
            sfera_sub_0043EC50(cpu, stop_address);
            return;
        case 0x2Eu:
            sfera_sub_0043ECB0(cpu, stop_address);
            return;
        case 0x2Fu:
            sfera_sub_0043ED30(cpu, stop_address);
            return;
        case 0x30u:
            sfera_sub_0043EE40(cpu, stop_address);
            return;
        case 0x31u:
            sfera_sub_0043F2F0(cpu, stop_address);
            return;
        case 0x32u:
            sfera_sub_0043F3E0(cpu, stop_address);
            return;
        case 0x33u:
            sfera_sub_0043F440(cpu, stop_address);
            return;
        case 0x34u:
            sfera_sub_0043F100(cpu, stop_address);
            return;
        case 0x35u:
            sfera_sub_0043F480(cpu, stop_address);
            return;
        case 0x36u:
            sfera_sub_0043EF50(cpu, stop_address);
            return;
        case 0x37u:
            sfera_sub_0043EF90(cpu, stop_address);
            return;
        case 0x38u:
            sfera_sub_0043EFD0(cpu, stop_address);
            return;
        case 0x39u:
            sfera_sub_0043F010(cpu, stop_address);
            return;
        case 0x3Au:
            sfera_sub_0043F050(cpu, stop_address);
            return;
        case 0x3Bu:
            sfera_sub_0043F090(cpu, stop_address);
            return;
        case 0x3Cu:
            sfera_sub_0043F0D0(cpu, stop_address);
            return;
        case 0x3Du:
            sfera_sub_0043F530(cpu, stop_address);
            return;
        case 0x3Eu:
            sfera_sub_0043F6B0(cpu, stop_address);
            return;
        case 0x3Fu:
            sfera_sub_0043F6E0(cpu, stop_address);
            return;
        case 0x40u:
            sfera_sub_0043ECC0(cpu, stop_address);
            return;
        case 0x41u:
            sfera_sub_0043EA60(cpu, stop_address);
            return;
        case 0x42u:
            sfera_sub_0043EAB0(cpu, stop_address);
            return;
        case 0x43u:
            sfera_sub_0043F9E0(cpu, stop_address);
            return;
        case 0x44u:
            sfera_sub_0043EBE0(cpu, stop_address);
            return;
        case 0x45u:
            sfera_sub_0043EBB0(cpu, stop_address);
            return;
        case 0x46u:
            sfera_sub_0043EAD0(cpu, stop_address);
            return;
        case 0x47u:
            sfera_sub_0043EB20(cpu, stop_address);
            return;
        case 0x48u:
            sfera_sub_0043EB50(cpu, stop_address);
            return;
        case 0x49u:
            sfera_sub_0043F730(cpu, stop_address);
            return;
        case 0x4Au:
            sfera_sub_0043EC20(cpu, stop_address);
            return;
        case 0x4Bu:
            sfera_sub_0043DC60(cpu, stop_address);
            return;
        case 0x4Cu:
            sfera_sub_0043DCE0(cpu, stop_address);
            return;
        case 0x4Du:
            sfera_sub_0043FC90(cpu, stop_address);
            return;
        case 0x4Eu:
            sfera_sub_0043FEB0(cpu, stop_address);
            return;
        case 0x4Fu:
            sfera_sub_0043FF90(cpu, stop_address);
            return;
        case 0x50u:
            sfera_sub_0043D400(cpu, stop_address);
            return;
        case 0x51u:
            sfera_sub_0043BDB0(cpu, stop_address);
            return;
        case 0x52u:
            sfera_sub_00440000(cpu, stop_address);
            return;
        case 0x53u:
            sfera_sub_0043F180(cpu, stop_address);
            return;
        case 0x54u:
            sfera_sub_0043F2B0(cpu, stop_address);
            return;
        case 0x55u:
            sfera_sub_00440030(cpu, stop_address);
            return;
        case 0x56u:
            sfera_sub_0043E6C0(cpu, stop_address);
            return;
        case 0x57u:
            sfera_sub_00440090(cpu, stop_address);
            return;
        case 0x58u:
            sfera_sub_004400F0(cpu, stop_address);
            return;
        case 0x59u:
            sfera_sub_00440150(cpu, stop_address);
            return;
        case 0x5Au:
            sfera_sub_00440180(cpu, stop_address);
            return;
        case 0x5Bu:
            sfera_sub_0043E510(cpu, stop_address);
            return;
        case 0x5Cu:
            sfera_sub_004401B0(cpu, stop_address);
            return;
        case 0x5Du:
            sfera_sub_00440260(cpu, stop_address);
            return;
        case 0x5Eu:
            sfera_sub_004402D0(cpu, stop_address);
            return;
        case 0x5Fu:
            sfera_sub_0043D9B0(cpu, stop_address);
            return;
        case 0x60u:
            sfera_sub_0043FF20(cpu, stop_address);
            return;
        case 0x61u:
            sfera_sub_00440330(cpu, stop_address);
            return;
        case 0x62u:
            sfera_sub_004403B0(cpu, stop_address);
            return;
        case 0x63u:
            sfera_sub_0043F4E0(cpu, stop_address);
            return;
        case 0x64u:
            sfera_sub_00440410(cpu, stop_address);
            return;
        case 0x65u:
            sfera_sub_004404E0(cpu, stop_address);
            return;
        case 0x66u:
            sfera_sub_00440580(cpu, stop_address);
            return;
        case 0x67u:
            sfera_sub_00443F20(cpu, stop_address);
            return;
        case 0x68u:
            sfera_sub_00441C90(cpu, stop_address);
            return;
        case 0x69u:
            sfera_sub_0043F840(cpu, stop_address);
            return;
        case 0x6Au:
            sfera_sub_0043BD80(cpu, stop_address);
            return;
        case 0x6Bu:
            sfera_sub_00441CE0(cpu, stop_address);
            return;
        case 0x6Cu:
            sfera_sub_0043FDB0(cpu, stop_address);
            return;
        case 0x6Du:
            sfera_sub_00441D60(cpu, stop_address);
            return;
        case 0x6Eu:
            sfera_sub_00441DD0(cpu, stop_address);
            return;
        case 0x6Fu:
            sfera_sub_00441E80(cpu, stop_address);
            return;
        case 0x70u:
            sfera_sub_00442140(cpu, stop_address);
            return;
        case 0x71u:
            sfera_sub_00442030(cpu, stop_address);
            return;
        case 0x72u:
            sfera_sub_00442220(cpu, stop_address);
            return;
        case 0x73u:
            sfera_sub_004423A0(cpu, stop_address);
            return;
        case 0x74u:
            sfera_sub_0043E840(cpu, stop_address);
            return;
        case 0x75u:
            sfera_sub_00446D40(cpu, stop_address);
            return;
        case 0x76u:
            sfera_sub_00442570(cpu, stop_address);
            return;
        case 0x77u:
            sfera_sub_004425A0(cpu, stop_address);
            return;
        case 0x78u:
            sfera_sub_0043B0B0(cpu, stop_address);
            return;
        case 0x79u:
            sfera_sub_0043FAE0(cpu, stop_address);
            return;
        case 0x7Au:
        case 0x82u:
        case 0x85u:
            sfera_sub_0042B7D0(cpu, stop_address);
            return;
        case 0x7Bu:
            sfera_sub_00440600(cpu, stop_address);
            return;
        case 0x7Cu:
            sfera_sub_0043E9B0(cpu, stop_address);
            return;
        case 0x7Du:
            sfera_sub_0043BC20(cpu, stop_address);
            return;
        case 0x7Eu:
            sfera_sub_0043E220(cpu, stop_address);
            return;
        case 0x7Fu:
            sfera_sub_0043FA70(cpu, stop_address);
            return;
        case 0x80u:
            sfera_sub_00443EB0(cpu, stop_address);
            return;
        case 0x81u:
            sfera_sub_0044B130(cpu, stop_address);
            return;
        case 0x83u:
            sfera_sub_004406A0(cpu, stop_address);
            return;
        case 0x84u:
            sfera_sub_00449EF0(cpu, stop_address);
            return;
        case 0x86u:
            sfera_sub_0043C030(cpu, stop_address);
            return;
        case 0x87u:
            sfera_sub_0043DA20(cpu, stop_address);
            return;
        case 0x88u:
            sfera_sub_0043D6B0(cpu, stop_address);
            return;
        case 0x89u:
            sfera_sub_0043DD60(cpu, stop_address);
            return;
        case 0x8Au:
            sfera_sub_004425F0(cpu, stop_address);
            return;
        case 0x8Bu:
            sfera_sub_00442660(cpu, stop_address);
            return;
        case 0x8Cu:
            sfera_sub_004426D0(cpu, stop_address);
            return;
        case 0x8Du:
            sfera_sub_00442740(cpu, stop_address);
            return;
        case 0x8Eu:
            sfera_sub_004427A0(cpu, stop_address);
            return;
        case 0x8Fu:
            sfera_sub_00442810(cpu, stop_address);
            return;
        case 0x90u:
            sfera_sub_00442880(cpu, stop_address);
            return;
        case 0x91u:
            sfera_sub_00442900(cpu, stop_address);
            return;
        case 0x92u:
            sfera_sub_00442980(cpu, stop_address);
            return;
        case 0x93u:
            sfera_sub_00447770(cpu, stop_address);
            return;
        case 0x94u:
            sfera_sub_00442B60(cpu, stop_address);
            return;
        case 0x95u:
            sfera_sub_00442B70(cpu, stop_address);
            return;
        case 0x96u:
            sfera_sub_00442B80(cpu, stop_address);
            return;
        case 0x97u:
            sfera_sub_00442B90(cpu, stop_address);
            return;
        case 0x98u:
            sfera_sub_00442BA0(cpu, stop_address);
            return;
        case 0x99u:
            sfera_sub_00442C40(cpu, stop_address);
            return;
        case 0x9Au:
            sfera_sub_00442D80(cpu, stop_address);
            return;
        case 0x9Bu:
            sfera_sub_00442D90(cpu, stop_address);
            return;
        case 0x9Cu:
            sfera_sub_00442DA0(cpu, stop_address);
            return;
        case 0x9Du:
            sfera_sub_00442DB0(cpu, stop_address);
            return;
        case 0x9Eu:
            sfera_sub_00442DC0(cpu, stop_address);
            return;
        case 0x9Fu:
            sfera_sub_00442E80(cpu, stop_address);
            return;
        case 0xA0u:
            sfera_sub_00442F70(cpu, stop_address);
            return;
        case 0xA1u:
            sfera_sub_00414920(cpu, stop_address);
            return;
        case 0xA2u:
            sfera_sub_00402040(cpu, stop_address);
            return;
        case 0xA3u:
            sfera_sub_00443050(cpu, stop_address);
            return;
        default:
            lift_trap(cpu, 0x43774Eu, "unsupported MBInter bytecode opcode");
            return;
    }
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00430900(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00030900;
    label_0002F870:
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002F88E;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edi = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0xCu);
    goto label_0002F8A5;
    label_0002F88E:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x7Cu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x74u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x78u);
    cpu->edi = (uint32_t)(cpu->eax + cpu->ecx + 0xFFFFFFFFu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x80u);
    cpu->eax = (uint32_t)(cpu->eax + cpu->edx + 0xFFFFFFFFu);
    label_0002F8A5:
    if ((uint32_t)(cpu->ecx) != *(uint32_t*)(cpu->esi + 0x84u)) goto label_0002F8C5;
    if ((uint32_t)(cpu->edx) != *(uint32_t*)(cpu->esi + 0x88u)) goto label_0002F8C5;
    if ((uint32_t)(cpu->edi) != *(uint32_t*)(cpu->esi + 0x8Cu)) goto label_0002F8C5;
    if ((uint32_t)(cpu->eax) == *(uint32_t*)(cpu->esi + 0x90u)) goto label_0002F8E6;
    label_0002F8C5:
    *(uint32_t*)(cpu->esi + 0x84u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x88u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x8Cu) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x90u) = cpu->eax;
    *(uint16_t*)(cpu->esi + 0x564u) = 0u;
    label_0002F8E6:
    { uint64_t l=(uint64_t)(*(uint8_t*)(cpu->esi + 0x565u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002FA26;
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x98u));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint8_t*)(cpu->esi + 0x565u) = cpu->ebx & 0xFFu;
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xCu));
    cpu->ecx = (uint32_t)(cpu->esi + 0xF0u);
    *(float*)(cpu->esi + 0xE4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, 5u);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x1Cu));
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esi + 0xE8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = cpu->esi;
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x2Cu));
    *(float*)(cpu->esi + 0xECu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x54u));
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    *(float*)(cpu->esi + 0x114u) = cpu->fpu[0u];
    *(float*)(cpu->esi + 0x108u) = cpu->fpu[0u];
    *(float*)(cpu->esi + 0xFCu) = cpu->fpu[0u];
    *(float*)(cpu->ecx) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x64u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x84u)))));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x5Cu));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x54u)));
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    *(float*)(cpu->esi + 0xF4u) = cpu->fpu[0u];
    *(float*)(cpu->esi + 0x118u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x64u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x8Cu)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x5Cu)));
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x54u)));
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    *(float*)(cpu->esi + 0x100u) = cpu->fpu[0u];
    *(float*)(cpu->esi + 0x10Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x68u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x88u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x60u)));
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x54u)));
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    *(float*)(cpu->esi + 0xF8u) = cpu->fpu[0u];
    *(float*)(cpu->esi + 0x104u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x68u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x90u)))));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x60u)));
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x54u)));
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    *(float*)(cpu->esi + 0x110u) = cpu->fpu[0u];
    *(float*)(cpu->esi + 0x11Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x50u));
    *(float*)(cpu->esi + 0x120u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esi + 0x128u) = cpu->fpu[0u];
    *(float*)(cpu->esi + 0x124u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2FA26u)); sfera_sub_0042F450(cpu, LIFT_CODE_TOKEN_RVA(0x2FA26u));
    label_0002FA26:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x30u);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_0002FDFB;
    if (*(uint8_t*)(cpu->esi + 0x564u) != (uint8_t)(0u)) goto label_0002FDFB;
    cpu->eax = (uint32_t)(cpu->esi + 0x518u);
    *(uint8_t*)(cpu->esi + 0x564u) = cpu->ebx & 0xFFu;
    cpu->edi = 0xA0u;
    cpu->ebx = 0x10u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    goto label_0002FA64;
    label_0002FA60:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_0002FA64:
    cpu->ebp = *(uint32_t*)(cpu->eax + 0xFFFFFFFCu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u));
    cpu->ebp = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->ebp) * 2u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + ((uint32_t)(cpu->ebp) * 4u) + 0xECu));
    cpu->ebp = (uint32_t)(cpu->esi + ((uint32_t)(cpu->ebp) * 4u));
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0xECu)));
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->ecx) * 4u));
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0xE8u));
    cpu->eax = (uint32_t)(cpu->esi + ((uint32_t)(cpu->eax) * 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0xE8u)));
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u) + 0x39u);
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->edx) * 4u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xE8u));
    cpu->edx = *(uint32_t*)(cpu->edx + 0xFFFFFFFCu);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ebp + 0xE8u)));
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u) + 0x39u);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0xECu));
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->edx) * 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax + 0xECu)));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edx = *(uint32_t*)(cpu->edx);
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u) + 0x39u);
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->edx) * 4u));
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0xE8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 0xE8u)));
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0xECu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax + 0xECu)));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xECu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ebp + 0xECu)));
    lift_x87_push(cpu, (double)*(float*)(cpu->edx));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edx)));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0xECu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0xECu)));
    lift_x87_push(cpu, (double)*(float*)(cpu->edx));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edx)));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0xECu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 0xECu)));
    lift_x87_push(cpu, (double)*(float*)(cpu->edx));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edx)));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->edx)));
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xE8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ebp + 0xE8u)));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->edx)));
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0xE8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ecx + 0xE8u)));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xE8u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ecx + 0xE8u)));
    lift_x87_push(cpu, (double)*(float*)(cpu->edx));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax)));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42FBAAu)); sfera_sub_0042F3E0(cpu, LIFT_CODE_TOKEN_VA(0x42FBAAu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    *(float*)(cpu->ebx + cpu->ecx) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edi + cpu->edx + 0xCu) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edi + cpu->eax + 8u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edi + cpu->ecx + 4u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edi + cpu->edx) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    *(uint32_t*)(cpu->esp + 0x2Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x2Cu)) + (uint64_t)(0xCu) + (uint64_t)(0u);
    *(float*)(cpu->ebx + cpu->eax + 4u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edi + cpu->ecx + 0x1Cu) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edi + cpu->edx + 0x18u) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edi + cpu->eax + 0x14u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edi + cpu->ecx + 0x10u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    cpu->ebx += 0x10u;
    *(float*)(cpu->ebx + cpu->edx + 0xFFFFFFF8u) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edi + cpu->eax + 0x2Cu) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edi + cpu->ecx + 0x28u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->edi + cpu->edx + 0x24u) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edi + cpu->eax + 0x20u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    cpu->edi += 0x40u;
    cpu->fpu[0u] = -cpu->fpu[0u];
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ecx)));
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0xE8u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0xECu));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->ebx + cpu->edx + 0xFFFFFFFCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    *(float*)(cpu->edi + cpu->eax + 0xFFFFFFFCu) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edi + cpu->ecx + 0xFFFFFFF8u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edi + cpu->edx + 0xFFFFFFF4u) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edi + cpu->eax + 0xFFFFFFF0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(0x60u)) goto label_0002FA60;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x50u));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u];
    *(float*)(cpu->eax) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    *(float*)(cpu->ecx + 0x6Cu) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + 0x68u) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + 0x64u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->ecx + 0x60u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x54u));
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u];
    *(float*)(cpu->eax + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    *(float*)(cpu->edx + 0x7Cu) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + 0x78u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->ecx + 0x74u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + 0x70u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x58u));
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u];
    *(float*)(cpu->eax + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    *(float*)(cpu->eax + 0x8Cu) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->ecx + 0x88u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + 0x84u) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + 0x80u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x54u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x124u)));
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x50u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x120u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x58u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x128u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u];
    *(float*)(cpu->eax + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    *(float*)(cpu->ecx + 0x9Cu) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + 0x98u) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + 0x94u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->ecx + 0x90u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0002FDFB:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 4u));
    cpu->edi = (uint32_t)(cpu->esi + 0xE4u);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0xE8u)));
    lift_x87_push(cpu, (double)*(float*)(cpu->edi));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->eax)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0xECu)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax + 0xCu)));
    lift_x87_compare(cpu, cpu->fpu[0u], 0.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00030091;
    cpu->eax = 0xA0u;
    cpu->ecx = 0x10u;
    (void)cpu;
    label_0002FE40:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + cpu->ecx));
    cpu->eax += 0x40u;
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u];
    *(float*)(cpu->edx + cpu->ecx) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFCCu) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFC8u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFC4u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFC0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + cpu->edx + 4u));
    cpu->edx = (uint32_t)(cpu->ecx + cpu->edx + 4u);
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u];
    *(float*)(cpu->edx) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFDCu) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFD8u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFD4u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFD0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + cpu->edx + 8u));
    cpu->edx = (uint32_t)(cpu->ecx + cpu->edx + 8u);
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u];
    *(float*)(cpu->edx) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFECu) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFE8u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFE4u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFE0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + cpu->edx + 0xCu));
    cpu->edx = (uint32_t)(cpu->ecx + cpu->edx + 0xCu);
    cpu->fpu[0u] = -cpu->fpu[0u];
    cpu->ecx += 0x10u;
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u];
    *(float*)(cpu->edx) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFFCu) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFF8u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFF4u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFF0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(0x60u)) goto label_0002FE40;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax));
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u];
    *(float*)(cpu->eax) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->eax + 0x6Cu) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->ecx + 0x68u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + 0x64u) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + 0x60u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 4u));
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u];
    *(float*)(cpu->eax + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->ecx + 0x7Cu) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + 0x78u) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + 0x74u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->ecx + 0x70u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 8u));
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u];
    *(float*)(cpu->eax + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->edx + 0x8Cu) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + 0x88u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->ecx + 0x84u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + 0x80u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xCu));
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u];
    *(float*)(cpu->eax + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->eax + 0x9Cu) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->ecx + 0x98u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + 0x94u) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + 0x90u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00030091:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0003009B;
    *(uint32_t*)(cpu->eax) = cpu->edi;
    label_0003009B:
    if ((uint32_t)(cpu->ebp) == 0u) goto label_000300A8;
    cpu->esi += 0x12Cu;
    *(uint32_t*)(cpu->ebp) = cpu->esi;
    label_000300A8:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000300C0:
    cpu->esp -= 0x18u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x1Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000300E8;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->ecx) = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000300E8:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x74u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x78u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x7Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x80u);
    cpu->edx = (uint32_t)(cpu->edx + cpu->eax + 0xFFFFFFFFu);
    cpu->edi = (uint32_t)(cpu->edi + cpu->ecx + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->eax) != *(uint32_t*)(cpu->esi + 0x84u)) goto label_00030122;
    if ((uint32_t)(cpu->ecx) != *(uint32_t*)(cpu->esi + 0x88u)) goto label_00030122;
    if ((uint32_t)(cpu->edx) != *(uint32_t*)(cpu->esi + 0x8Cu)) goto label_00030122;
    if ((uint32_t)(cpu->edi) == *(uint32_t*)(cpu->esi + 0x90u)) goto label_00030143;
    label_00030122:
    *(uint32_t*)(cpu->esi + 0x84u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x88u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x8Cu) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x90u) = cpu->edi;
    *(uint16_t*)(cpu->esi + 0x564u) = 0u;
    label_00030143:
    { uint64_t l=(uint64_t)(*(uint8_t*)(cpu->esi + 0x565u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00030264;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint8_t*)(cpu->esi + 0x565u) = cpu->ebx & 0xFFu;
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xCu));
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, 5u);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x1Cu));
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x2Cu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esi + 0xE4u) = cpu->eax;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x54u));
    *(uint32_t*)(cpu->esi + 0xE8u) = cpu->ecx;
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->esi + 0xF0u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    *(float*)(cpu->esi + 0x114u) = cpu->fpu[0u];
    *(uint32_t*)(cpu->esi + 0xECu) = cpu->edx;
    *(float*)(cpu->esi + 0x108u) = cpu->fpu[0u];
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esi + 0xFCu) = cpu->fpu[0u];
    cpu->edx = cpu->esi;
    *(float*)(cpu->ecx) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x54u));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (((double)*(float*)(cpu->esi + 0x560u)));
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x550u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    *(float*)(cpu->esi + 0xF4u) = cpu->fpu[0u];
    *(float*)(cpu->esi + 0x118u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x558u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x550u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    *(float*)(cpu->esi + 0x100u) = cpu->fpu[0u];
    *(float*)(cpu->esi + 0x10Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x554u)));
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    *(float*)(cpu->esi + 0xF8u) = cpu->fpu[0u];
    *(float*)(cpu->esi + 0x104u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x55Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x554u)));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    *(float*)(cpu->esi + 0x110u) = cpu->fpu[0u];
    *(float*)(cpu->esi + 0x11Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x50u));
    *(float*)(cpu->esi + 0x120u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esi + 0x128u) = cpu->fpu[0u];
    *(float*)(cpu->esi + 0x124u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x30264u)); sfera_sub_0042F450(cpu, LIFT_CODE_TOKEN_RVA(0x30264u));
    label_00030264:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x30u);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_0003063B;
    if (*(uint8_t*)(cpu->esi + 0x564u) != (uint8_t)(0u)) goto label_0003063B;
    cpu->eax = (uint32_t)(cpu->esi + 0x518u);
    *(uint8_t*)(cpu->esi + 0x564u) = cpu->ebx & 0xFFu;
    cpu->edi = 0xA0u;
    cpu->ebx = 0x10u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    goto label_000302A4;
    label_000302A0:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_000302A4:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->ebp = *(uint32_t*)(cpu->eax + 0xFFFFFFFCu);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u));
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0xECu));
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ebp = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->ebp) * 2u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + ((uint32_t)(cpu->ebp) * 4u) + 0xECu)));
    cpu->ebp = (uint32_t)(cpu->esi + ((uint32_t)(cpu->ebp) * 4u));
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0xE8u));
    cpu->eax = (uint32_t)(cpu->esi + ((uint32_t)(cpu->eax) * 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0xE8u)));
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u) + 0x39u);
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->edx) * 4u));
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xE8u));
    cpu->edx = *(uint32_t*)(cpu->edx + 0xFFFFFFFCu);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ebp + 0xE8u)));
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u) + 0x39u);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xECu));
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->edx) * 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ebp + 0xECu)));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edx = *(uint32_t*)(cpu->edx);
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u) + 0x39u);
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->edx) * 4u));
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0xECu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax + 0xECu)));
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0xE8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 0xE8u)));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edx)));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0xECu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ecx + 0xECu)));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xECu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->ebp + 0xECu)));
    lift_x87_push(cpu, (double)*(float*)(cpu->edx));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edx)));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0xECu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 0xECu)));
    lift_x87_push(cpu, (double)*(float*)(cpu->edx));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edx)));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->edx)));
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xE8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ebp + 0xE8u)));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->edx)));
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0xE8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ecx + 0xE8u)));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->edx)));
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xE8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ecx + 0xE8u)));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4303EAu)); sfera_sub_0042F3E0(cpu, LIFT_CODE_TOKEN_VA(0x4303EAu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    *(float*)(cpu->ebx + cpu->eax) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->ecx + cpu->edi + 0xCu) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + cpu->edi + 8u) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + cpu->edi + 4u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edi + cpu->ecx) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    *(uint32_t*)(cpu->esp + 0x2Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x2Cu)) + (uint64_t)(0xCu) + (uint64_t)(0u);
    *(float*)(cpu->edx + cpu->ebx + 4u) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + cpu->edi + 0x1Cu) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->ecx + cpu->edi + 0x18u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + cpu->edi + 0x14u) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edi + cpu->eax + 0x10u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    cpu->ebx += 0x10u;
    *(float*)(cpu->ecx + cpu->ebx + 0xFFFFFFF8u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + cpu->edi + 0x2Cu) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + cpu->edi + 0x28u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->ecx + cpu->edi + 0x24u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edi + cpu->edx + 0x20u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    cpu->edi += 0x40u;
    cpu->fpu[0u] = -cpu->fpu[0u];
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->eax)));
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0xE8u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0xECu));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->ecx + cpu->ebx + 0xFFFFFFFCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    *(float*)(cpu->edx + cpu->edi + 0xFFFFFFFCu) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + cpu->edi + 0xFFFFFFF8u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->ecx + cpu->edi + 0xFFFFFFF4u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edi + cpu->edx + 0xFFFFFFF0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(0x60u)) goto label_000302A0;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x50u));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u];
    *(float*)(cpu->eax) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    *(float*)(cpu->eax + 0x6Cu) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->ecx + 0x68u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + 0x64u) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + 0x60u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x54u));
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u];
    *(float*)(cpu->eax + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    *(float*)(cpu->ecx + 0x7Cu) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + 0x78u) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + 0x74u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->ecx + 0x70u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x58u));
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u];
    *(float*)(cpu->eax + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    *(float*)(cpu->edx + 0x8Cu) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + 0x88u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->ecx + 0x84u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + 0x80u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x54u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x124u)));
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x50u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x120u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x58u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x128u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u];
    *(float*)(cpu->eax + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    *(float*)(cpu->eax + 0x9Cu) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->ecx + 0x98u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + 0x94u) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + 0x90u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0003063B:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 4u));
    cpu->edi = (uint32_t)(cpu->esi + 0xE4u);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0xE8u)));
    lift_x87_push(cpu, (double)*(float*)(cpu->edi));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->eax)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0xECu)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax + 0xCu)));
    lift_x87_compare(cpu, cpu->fpu[0u], 0.0);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000308D1;
    cpu->eax = 0xA0u;
    cpu->ecx = 0x10u;
    (void)cpu;
    label_00030680:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + cpu->ecx));
    cpu->eax += 0x40u;
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u];
    *(float*)(cpu->edx + cpu->ecx) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->edx + cpu->eax + 0xFFFFFFCCu) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + cpu->eax + 0xFFFFFFC8u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + cpu->eax + 0xFFFFFFC4u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFC0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + cpu->ecx + 4u));
    cpu->edx = (uint32_t)(cpu->edx + cpu->ecx + 4u);
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u];
    *(float*)(cpu->edx) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->edx + cpu->eax + 0xFFFFFFDCu) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + cpu->eax + 0xFFFFFFD8u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + cpu->eax + 0xFFFFFFD4u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFD0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + cpu->ecx + 8u));
    cpu->edx = (uint32_t)(cpu->edx + cpu->ecx + 8u);
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u];
    *(float*)(cpu->edx) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->edx + cpu->eax + 0xFFFFFFECu) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + cpu->eax + 0xFFFFFFE8u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + cpu->eax + 0xFFFFFFE4u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFE0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + cpu->ecx + 0xCu));
    cpu->edx = (uint32_t)(cpu->edx + cpu->ecx + 0xCu);
    cpu->fpu[0u] = -cpu->fpu[0u];
    cpu->ecx += 0x10u;
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u];
    *(float*)(cpu->edx) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->edx + cpu->eax + 0xFFFFFFFCu) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + cpu->eax + 0xFFFFFFF8u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + cpu->eax + 0xFFFFFFF4u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + cpu->edx + 0xFFFFFFF0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(0x60u)) goto label_00030680;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax));
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u];
    *(float*)(cpu->eax) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->eax + 0x6Cu) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->ecx + 0x68u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + 0x64u) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + 0x60u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 4u));
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u];
    *(float*)(cpu->eax + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->ecx + 0x7Cu) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + 0x78u) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + 0x74u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->ecx + 0x70u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 8u));
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u];
    *(float*)(cpu->eax + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->edx + 0x8Cu) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + 0x88u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->ecx + 0x84u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + 0x80u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xCu));
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u];
    *(float*)(cpu->eax + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    *(float*)(cpu->eax + 0x9Cu) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->ecx + 0x98u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->edx + 0x94u) = cpu->fpu[0u];
    cpu->eax = *(uint32_t*)(cpu->esi + 0x31Cu);
    *(float*)(cpu->eax + 0x90u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000308D1:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000308DB;
    *(uint32_t*)(cpu->eax) = cpu->edi;
    label_000308DB:
    if ((uint32_t)(cpu->ebp) == 0u) goto label_000308E8;
    cpu->esi += 0x12Cu;
    *(uint32_t*)(cpu->ebp) = cpu->esi;
    label_000308E8:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00030900:
    if (*(uint8_t*)(cpu->ecx + 0x566u) == (uint8_t)(0u)) goto label_0003090E;
    goto label_000300C0;
    label_0003090E:
    goto label_0002F870;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00430920(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->ebx + 0x18u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00030941;
    lift_push32(cpu, 2u); lift_push32(cpu, 0x10000u); lift_push32(cpu, 0xAu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43093Au)); sfera_sub_00419920(cpu, LIFT_CODE_TOKEN_VA(0x43093Au));
    *(uint32_t*)(cpu->ebx + 0x18u) = 1u;
    label_00030941:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_x87_push(cpu, 4000.0);
    cpu->fpu[1u] = (cpu->fpu[1u]) + (cpu->fpu[0u]);
    lift_x87_push(cpu, 0.5120000243186951);
    cpu->fpu[2u] = (cpu->fpu[2u]) * (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43095Cu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x43095Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x18u)));
    cpu->esi = cpu->eax;
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x430969u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x430969u));
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->esi) > (uint32_t)(0xFFFu)) goto label_000309E1;
    if ((uint32_t)(cpu->edi) > (uint32_t)(0xFFFu)) goto label_000309E1;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 0xFFu;
    cpu->ecx = (uint32_t)(cpu->edx + cpu->eax);
    cpu->eax = cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 0xFFu;
    cpu->eax += cpu->edx;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFFFFF00u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->eax = (uint32_t)((int32_t)(cpu->eax) >> 8u);
    cpu->ecx += cpu->eax;
    cpu->edx = cpu->ecx & 0xFFFFu;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4309AEu)); sfera_sub_00419990(cpu, LIFT_CODE_TOKEN_VA(0x4309AEu));
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0x800000FFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000309BE;
    --cpu->edi;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->edi = v; }
    { uint64_t l=(uint64_t)(cpu->edi), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    label_000309BE:
    cpu->edi <<= 8u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0x800000FFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000309D1;
    --cpu->esi;
    cpu->esi |= 0xFFFFFF00u;
    ++cpu->esi;
    label_000309D1:
    cpu->edi += cpu->eax;
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->esi + cpu->edi));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax &= 0xFu;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000309E1:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004309F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->ebx + 0x18u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00030A11;
    lift_push32(cpu, 2u); lift_push32(cpu, 0x10000u); lift_push32(cpu, 0xAu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x430A0Au)); sfera_sub_00419920(cpu, LIFT_CODE_TOKEN_VA(0x430A0Au));
    *(uint32_t*)(cpu->ebx + 0x18u) = 1u;
    label_00030A11:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_x87_push(cpu, 4000.0);
    cpu->fpu[1u] = (cpu->fpu[1u]) + (cpu->fpu[0u]);
    lift_x87_push(cpu, 0.5120000243186951);
    cpu->fpu[2u] = (cpu->fpu[2u]) * (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x430A2Cu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x430A2Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x18u)));
    cpu->esi = cpu->eax;
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x430A39u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x430A39u));
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->esi) > (uint32_t)(0xFFFu)) goto label_00030AB4;
    if ((uint32_t)(cpu->edi) > (uint32_t)(0xFFFu)) goto label_00030AB4;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 0xFFu;
    cpu->ecx = (uint32_t)(cpu->edx + cpu->eax);
    cpu->eax = cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 0xFFu;
    cpu->eax += cpu->edx;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xFFFFFF00u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->eax = (uint32_t)((int32_t)(cpu->eax) >> 8u);
    cpu->ecx += cpu->eax;
    cpu->edx = cpu->ecx & 0xFFFFu;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x430A7Eu)); sfera_sub_00419990(cpu, LIFT_CODE_TOKEN_VA(0x430A7Eu));
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0x800000FFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00030A8E;
    --cpu->edi;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->edi = v; }
    { uint64_t l=(uint64_t)(cpu->edi), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    label_00030A8E:
    cpu->edi <<= 8u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0x800000FFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00030AA1;
    --cpu->esi;
    cpu->esi |= 0xFFFFFF00u;
    ++cpu->esi;
    label_00030AA1:
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->esi + cpu->edi));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (uint32_t)((int32_t)(cpu->eax) >> 4u);
    cpu->esi = lift_pop32(cpu);
    cpu->eax &= 3u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00030AB4:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00430AC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x30u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->eax = *(uint16_t*)(cpu->eax);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->ebx = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(0x800000FFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebx = v; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00030AEF;
    --cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ebx = v; }
    { uint64_t l=(uint64_t)(cpu->ebx), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    label_00030AEF:
    cpu->ecx = 9u;
    cpu->esi = (uint32_t)(uintptr_t)"Landscape\\GrassMap\\GrassMap_00_00.bin";
    cpu->edi = (uint32_t)(cpu->esp + 0x14u);
    lift_movs32(cpu, 1u);
    cpu->eax >>= 8u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_movs16(cpu, 0u);
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_00030B10:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00030B10;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->esi = (uint32_t)(cpu->esp + cpu->eax + 0x14u);
    cpu->eax = 0x66666667u;
    lift_multiply_accumulator(cpu, cpu->ebx, 32u, 1u);
    cpu->edx = (uint32_t)((int32_t)(cpu->edx) >> 2u);
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax & 0xFFu)) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->eax + 0x30u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->ebx & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,8u); cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    *(uint8_t*)(cpu->esi + 0xFFFFFFF7u) = cpu->ecx & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = 0x66666667u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = (uint32_t)((int32_t)(cpu->edx) >> 2u);
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->edx = (uint32_t)(cpu->eax + 0x30u);
    *(uint8_t*)(cpu->esi + 0xFFFFFFFAu) = cpu->edx & 0xFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax & 0xFFu)) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) - (uint64_t)((cpu->eax & 0xFFu)) - (uint64_t)(0u))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    *(uint8_t*)(cpu->esi + 0xFFFFFFFBu) = cpu->ecx & 0xFFu;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    *(uint8_t*)(cpu->esi + 0xFFFFFFF8u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x430B7Eu)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x430B7Eu));
    cpu->esi = cpu->eax;
    lift_push32(cpu, 0x10000u);
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x430B8Eu)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x430B8Eu));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x430B95u)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x430B95u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00430BB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    std::construct_at(reinterpret_cast<GrassMapMngr*>(cpu->eax));
    *(uint32_t*)(cpu->eax + 0x18u) = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00430BC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00030BDD;
    lift_push32(cpu, 0x3Au);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\hash.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x430BD6u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x430BD6u));
    *(uint32_t*)(cpu->esi + 8u) = 0u;
    label_00030BDD:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00430BE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = 0u;
    lift_flags_logic(cpu,0u,32u); cpu->edx = 0u;
    label_00030BE4:
    cpu->eax = cpu->edx;
    cpu->ecx >>= 1u;
    cpu->eax >>= 1u;
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00030BFA;
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    label_00030BFA:
    cpu->ecx >>= 1u;
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00030C0F;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_00030C11;
    label_00030C0F:
    cpu->eax >>= 1u;
    label_00030C11:
    cpu->ecx >>= 1u;
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00030C26;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_00030C28;
    label_00030C26:
    cpu->eax >>= 1u;
    label_00030C28:
    cpu->ecx >>= 1u;
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00030C3D;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_00030C3F;
    label_00030C3D:
    cpu->eax >>= 1u;
    label_00030C3F:
    cpu->ecx >>= 1u;
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00030C54;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_00030C56;
    label_00030C54:
    cpu->eax >>= 1u;
    label_00030C56:
    cpu->ecx >>= 1u;
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00030C6B;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_00030C6D;
    label_00030C6B:
    cpu->eax >>= 1u;
    label_00030C6D:
    cpu->ecx >>= 1u;
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00030C82;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_00030C84;
    label_00030C82:
    cpu->eax >>= 1u;
    label_00030C84:
    cpu->ecx >>= 1u;
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_00030C90;
    cpu->ecx ^= 0xEDB88320u;
    label_00030C90:
    *(uint16_t*)(((uint32_t)(cpu->edx) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_packet_codec_runtime.checksum[0])) = cpu->ecx & 0xFFFFu;
    ++cpu->edx;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00030BE4;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00430CB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x7Cu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx = 0xFu;
    cpu->esi = (uint32_t)(uintptr_t)"QWERTYUIOPASDFGHJKLZXCVBNM\311\326\323\312\305\315\303\330\331\307\325\332\324\333\302\300\317\320\316\313\304\306\335\337\327\321\314\310\322\334\301\336\250";
    cpu->edi = (uint32_t)(cpu->esp + 8u);
    lift_movs32(cpu, 1u);
    cpu->ecx = 0xFu;
    cpu->esi = (uint32_t)(uintptr_t)"qwertyuiopasdfghjklzxcvbnm\351\366\363\352\345\355\343\370\371\347\365\372\364\373\342\340\357\360\356\353\344\346\375\377\367\361\354\350\362\374\341\376\270";
    cpu->edi = (uint32_t)(cpu->esp + 0x44u);
    lift_movs32(cpu, 1u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu);
    label_00030CE4:
    *(uint8_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_packet_codec_runtime.substitution[0])) = cpu->eax & 0xFFu;
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x100u)) goto label_00030CE4;
    cpu->eax = 0u;
    label_00030CF4:
    cpu->ecx = *(uint8_t*)(cpu->esp + cpu->eax);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->esp + cpu->eax + 0x3Cu)) & 0xFFu);
    ++cpu->eax;
    *(uint8_t*)(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_packet_codec_runtime.substitution[0])) = cpu->edx & 0xFFu;
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x3Cu)) goto label_00030CF4;
    cpu->esp += 0x7Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00430D20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    cpu->eax = 1u;
    if ((uint32_t)(cpu->ebp) != 0u) goto label_00030D43;
    if (*(uint32_t*)(cpu->esp + 0x30u) != (uint32_t)(cpu->eax)) goto label_00030D43;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    goto label_00030D4F;
    label_00030D43:
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0u;
    if ((uint32_t)(cpu->ebp) != 0u) goto label_00030D65;
    label_00030D4F:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = cpu->edi;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_00030D58:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00030D58;
    cpu->eax -= cpu->esi;
    cpu->ebp = cpu->eax;
    goto label_00030D69;
    label_00030D65:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x28u);
    label_00030D69:
    if ((int32_t)(uint32_t)(cpu->ebp) <= (int32_t)*(uint32_t*)(cpu->ecx)) goto label_00030D79;
    label_00030D6D:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00030D79:
    cpu->esi = 0u;
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00030DAA;
    label_00030D81:
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x2Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax + cpu->edi)) & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00030D94;
    cpu->edx = cpu->edx & 0xFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_packet_codec_runtime.substitution[0]))) & 0xFFu);
    label_00030D94:
    cpu->edx = cpu->edx & 0xFFu;
    cpu->esi = (cpu->esi & 0xFFFF0000u) | ((uint32_t)((uint16_t)((uint16_t)((cpu->esi & 0xFFFFu)) >> 1u)) & 0xFFFFu);
    cpu->esi = (cpu->esi & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->esi & 0xFFFFu)) + (uint64_t)(*(uint16_t*)(((uint32_t)(cpu->edx) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_packet_codec_runtime.checksum[0]))) + (uint64_t)(0u))) & 0xFFFFu);
    ++cpu->eax;
    cpu->esi = cpu->esi & 0xFFFFu;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ebp)) goto label_00030D81;
    label_00030DAA:
    cpu->eax = cpu->esi & 0xFFFFu;
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 2u) + 0x16u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    cpu->eax = *(uint16_t*)(cpu->eax);
    cpu->edx = 0xFFFFu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((uint16_t)((cpu->eax & 0xFFFFu)) == (uint16_t)((cpu->edx & 0xFFFFu))) goto label_00030D6D;
    cpu->esi = *(uint32_t*)(cpu->ecx + 0xCu);
    cpu->edx = cpu->eax & 0xFFFFu;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->esi);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    cpu->edx += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    label_00030DE5:
    cpu->eax = *(uint16_t*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    if ((uint32_t)(cpu->ebp) != *(uint32_t*)(cpu->edx)) goto label_00030EDE;
    if (*(uint32_t*)(cpu->esp + 0x30u) != (uint32_t)(0u)) goto label_00030EB2;
    cpu->esi = cpu->edi;
    cpu->ebx = cpu->ebp;
    cpu->edi = (uint32_t)(cpu->edx + 0xAu);
    if ((uint32_t)(cpu->ebp) < (uint32_t)(4u)) goto label_00030E24;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00030E10:
    cpu->eax = *(uint32_t*)(cpu->edi);
    if ((uint32_t)(cpu->eax) != *(uint32_t*)(cpu->esi)) goto label_00030E28;
    cpu->ebx -= 4u;
    cpu->esi += 4u;
    cpu->edi += 4u;
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(4u)) goto label_00030E10;
    label_00030E24:
    if ((uint32_t)(cpu->ebx) == 0u) goto label_00030E73;
    label_00030E28:
    cpu->eax = *(uint8_t*)(cpu->edi);
    cpu->ecx = *(uint8_t*)(cpu->esi);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00030E63;
    if ((uint32_t)(cpu->ebx) <= (uint32_t)(1u)) goto label_00030E6F;
    cpu->eax = *(uint8_t*)(cpu->edi + 1u);
    cpu->ecx = *(uint8_t*)(cpu->esi + 1u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00030E63;
    if ((uint32_t)(cpu->ebx) <= (uint32_t)(2u)) goto label_00030E6F;
    cpu->eax = *(uint8_t*)(cpu->edi + 2u);
    cpu->ecx = *(uint8_t*)(cpu->esi + 2u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00030E63;
    if ((uint32_t)(cpu->ebx) <= (uint32_t)(3u)) goto label_00030E6F;
    cpu->eax = *(uint8_t*)(cpu->edi + 3u);
    cpu->ecx = *(uint8_t*)(cpu->esi + 3u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    label_00030E63:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = (uint32_t)((int32_t)(cpu->eax) >> 31u);
    cpu->eax |= 1u;
    goto label_00030E75;
    label_00030E6F:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    label_00030E73:
    cpu->eax = 0u;
    label_00030E75:
    cpu->ebx = 0u;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = cpu->ebx;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00030EDA;
    label_00030E82:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00030EA5;
    cpu->ecx = *(uint16_t*)(cpu->edx + 8u);
    *(uint16_t*)(cpu->eax + 8u) = cpu->ecx & 0xFFFFu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint16_t*)(cpu->eax);
    *(uint16_t*)(cpu->edx + 8u) = cpu->ecx & 0xFFFFu;
    cpu->ecx = *(uint16_t*)(cpu->esp + 0x18u);
    *(uint16_t*)(cpu->eax) = cpu->ecx & 0xFFFFu;
    label_00030EA5:
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00030EB2:
    cpu->esi = 0u;
    cpu->eax = (uint32_t)(cpu->edx + 0xAu);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00030E82;
    cpu->edi -= cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00030EC0:
    cpu->ecx = (int8_t)(*(uint8_t*)(cpu->edi + cpu->eax));
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    if ((uint8_t)((cpu->ebx & 0xFFu)) != *(uint8_t*)(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_packet_codec_runtime.substitution[0]))) goto label_00030ED6;
    ++cpu->esi;
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->ebp)) goto label_00030EC0;
    goto label_00030E82;
    label_00030ED6:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    label_00030EDA:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_00030EDE:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->esi = 0xFFFFu;
    if ((uint16_t)((cpu->eax & 0xFFFFu)) == (uint16_t)((cpu->esi & 0xFFFFu))) goto label_00030F08;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    cpu->edx = cpu->eax & 0xFFFFu;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu));
    cpu->edx += *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = cpu->eax & 0xFFFFu;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    goto label_00030DE5;
    label_00030F08:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00430F20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x430F31u)); sfera_sub_00430D20(cpu, LIFT_CODE_TOKEN_VA(0x430F31u));
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00430F40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x430F51u)); sfera_sub_00430D20(cpu, LIFT_CODE_TOKEN_VA(0x430F51u));
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00430F60(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=(uint64_t)(g_sfera_packet_codec_runtime.initialized), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00030F83;
    g_sfera_packet_codec_runtime.initialized = (uint32_t)(1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x430F7Cu)); sfera_sub_00430BE0(cpu, LIFT_CODE_TOKEN_VA(0x430F7Cu));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x30F83u)); sfera_sub_00430CB0(cpu, LIFT_CODE_TOKEN_RVA(0x30F83u));
    label_00030F83:
    lift_push32(cpu, 0x20018u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x430F8Bu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->eax + 0xAu);
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ecx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->edi);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0x25u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\hash.cpp";
    *(uint32_t*)(cpu->esi) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x430FB9u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x430FB9u));
    lift_push32(cpu, 0x20000u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    cpu->eax = (uint32_t)(cpu->esi + 0x16u);
    cpu->edx = 0u;
    lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->eax);
    *(uint16_t*)(cpu->esi + 0x14u) = cpu->edx & 0xFFFFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x430FD3u));
    cpu->ecx = (uint32_t)(cpu->edi + 0xFFFFFFFFu);
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_00030FFC;
    lift_push32(cpu, cpu->ebx);
    label_00030FE5:
    cpu->edi = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->ebx = *(uint32_t*)(cpu->esi + 8u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(cpu->eax);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    ++cpu->eax;
    *(uint16_t*)(cpu->edi + cpu->ebx + 8u) = cpu->edx & 0xFFFFu;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ecx)) goto label_00030FE5;
    cpu->ebx = lift_pop32(cpu);
    label_00030FFC:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    cpu->eax = 0xFFFFu;
    *(uint16_t*)(cpu->ecx + cpu->edx + 8u) = cpu->eax & 0xFFFFu;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431020(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x431039u)); sfera_sub_00430D20(cpu, LIFT_CODE_TOKEN_VA(0x431039u));
    if ((uint32_t)(cpu->eax) == *(uint32_t*)(cpu->esi + 4u)) goto label_00031046;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_00031046:
    cpu->ecx = 0xFFFFu;
    lift_push32(cpu, cpu->edi);
    if (*(uint16_t*)(cpu->esi + 0x14u) != (uint16_t)((cpu->ecx & 0xFFFFu))) goto label_00031106;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esi + 0x10u)), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031065;
    cpu->ecx = (uint32_t)(uintptr_t)"CHash16::register_str: more than 65535 elements";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x31065u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x31065u));
    label_00031065:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edi = cpu->edx;
    cpu->edi >>= 31u;
    cpu->edi += cpu->edx;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(0x32u)) goto label_00031080;
    cpu->edi = 0x32u;
    label_00031080:
    *(uint32_t*)(cpu->esi + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x10u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)((cpu->ecx & 0xFFFFu)) & 0xFFFFu);
    *(uint16_t*)(cpu->esi + 0x14u) = cpu->edx & 0xFFFFu;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0xFFFFu)) goto label_000310A4;
    cpu->ecx = 0xFFFFu;
    cpu->ecx -= cpu->eax;
    cpu->edi += cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x10u) = 0xFFFFu;
    label_000310A4:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esi + 0xCu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, 0x83u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\hash.cpp");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4310BDu)); sfera_sub_004EBE80(cpu, LIFT_CODE_TOKEN_VA(0x4310BDu));
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    cpu->edx = (uint32_t)(cpu->edi + 0xFFFFFFFFu);
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(cpu->edx) <= 0) goto label_000310EF;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000310D0:
    cpu->ecx = *(uint16_t*)(cpu->esi + 0x14u);
    cpu->ebx = *(uint32_t*)(cpu->esi + 8u);
    cpu->edi = (uint32_t)(cpu->ecx + cpu->eax + 1u);
    cpu->ecx += cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esi + 0xCu));
    ++cpu->eax;
    *(uint16_t*)(cpu->ecx + cpu->ebx + 8u) = cpu->edi & 0xFFFFu;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edx)) goto label_000310D0;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    label_000310EF:
    cpu->edx = *(uint16_t*)(cpu->esi + 0x14u);
    cpu->edx += cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esi + 0xCu));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = 0xFFFFu;
    *(uint16_t*)(cpu->edx + cpu->eax + 8u) = cpu->ecx & 0xFFFFu;
    label_00031106:
    cpu->edi = *(uint16_t*)(cpu->esi + 0x14u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esi + 0xCu));
    cpu->edi += *(uint32_t*)(cpu->esi + 8u);
    if ((uint32_t)(cpu->ebp) != 0u) goto label_00031126;
    cpu->eax = 1u;
    if (*(uint32_t*)(cpu->esp + 0x20u) != (uint32_t)(cpu->eax)) goto label_00031126;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    goto label_00031132;
    label_00031126:
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if ((uint32_t)(cpu->ebp) != 0u) goto label_00031146;
    label_00031132:
    cpu->eax = cpu->ebx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00031137:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00031137;
    cpu->eax -= cpu->edx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    cpu->ebp = cpu->eax;
    label_00031146:
    if ((int32_t)(uint32_t)(cpu->ebp) <= (int32_t)*(uint32_t*)(cpu->esi)) goto label_00031154;
    cpu->ecx = (uint32_t)(uintptr_t)"CHash16::register_str: maxStrLen exceed";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x31154u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x31154u));
    label_00031154:
    cpu->edx = 0u;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00031190;
    cpu->ecx = (uint32_t)(cpu->edi + 0xAu);
    cpu->eax = (uint32_t)(cpu->edi + 0xAu);
    cpu->ebx -= cpu->ecx;
    label_00031162:
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->ebx + cpu->eax)) & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00031175;
    cpu->ecx = cpu->ecx & 0xFFu;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_packet_codec_runtime.substitution[0]))) & 0xFFu);
    label_00031175:
    *(uint8_t*)(cpu->eax) = cpu->ecx & 0xFFu;
    cpu->ecx = cpu->ecx & 0xFFu;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)((uint16_t)((uint16_t)((cpu->edx & 0xFFFFu)) >> 1u)) & 0xFFFFu);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFFFu)) + (uint64_t)(*(uint16_t*)(((uint32_t)(cpu->ecx) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_packet_codec_runtime.checksum[0]))) + (uint64_t)(0u))) & 0xFFFFu);
    ++cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    cpu->edx = cpu->edx & 0xFFFFu;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031162;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    label_00031190:
    cpu->ecx = *(uint16_t*)(cpu->esi + 0x14u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(*(uint16_t*)(cpu->edi + 8u)) & 0xFFFFu);
    *(uint16_t*)(cpu->esi + 0x14u) = cpu->eax & 0xFFFFu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->edx = cpu->edx & 0xFFFFu;
    cpu->eax = (uint32_t)(cpu->esi + ((uint32_t)(cpu->edx) * 2u) + 0x16u);
    *(uint32_t*)(cpu->edi) = cpu->ebp;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(*(uint16_t*)(cpu->eax)) & 0xFFFFu);
    *(uint16_t*)(cpu->edi + 8u) = cpu->edx & 0xFFFFu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint16_t*)(cpu->eax) = cpu->ecx & 0xFFFFu;
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004311D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4311E6u)); sfera_sub_00431020(cpu, LIFT_CODE_TOKEN_VA(0x4311E6u));
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004311F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x431206u)); sfera_sub_00431020(cpu, LIFT_CODE_TOKEN_VA(0x431206u));
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431210(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x6Cu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->ecx + 0x2Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x30u) = cpu->edx;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431240(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ecx + 0x24u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx + 0x28u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431260(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x2Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x30u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x28u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004312A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->ecx + 0x24u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004312B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->ecx + 0x28u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004312C0(LiftCpu* cpu, uint32_t stop_address) {
    if ((uint32_t)(cpu->ecx) == (uint32_t)(5u)) goto label_000312CD;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(4u)) goto label_000312CD;
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000312CD:
    cpu->eax = 1u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004312E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->esp) = cpu->ecx;
    if ((uint32_t)(cpu->edx) != 0u) goto label_000312F5;
    if ((uint32_t)(cpu->eax) <= *(uint32_t*)(cpu->ecx + 0x10u)) goto label_0003136D;
    label_000312F5:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 0x10u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edi)) goto label_00031366;
    cpu->edi -= cpu->eax;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->edi)) goto label_00031366;
    cpu->esi = 1u;
    cpu->esi -= cpu->edx;
    cpu->edi += cpu->esi;
    if (*(uint32_t*)(cpu->ecx + 0x14u) < (uint32_t)(0x10u)) goto label_00031317;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_00031317:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ebx = (uint32_t)(cpu->ecx + cpu->eax);
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->ebp));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_memchr_address32(), LIFT_CODE_TOKEN_VA(0x431325u));
    cpu->esi = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00031366;
    label_00031334:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x431340u)); sfera_sub_00401BE0(cpu, LIFT_CODE_TOKEN_VA(0x431340u));
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00031371;
    cpu->edx = (int8_t)(*(uint8_t*)(cpu->ebp));
    cpu->ebx -= cpu->esi;
    cpu->edi = (uint32_t)(cpu->edi + cpu->ebx + 0xFFFFFFFFu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->ebx = (uint32_t)(cpu->esi + 1u);
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_memchr_address32(), LIFT_CODE_TOKEN_VA(0x431357u));
    cpu->esi = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00031334;
    label_00031366:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    label_0003136D:
    cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00031371:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint32_t*)(cpu->ecx + 0x14u) < (uint32_t)(0x10u)) goto label_0003137D;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_0003137D:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax -= cpu->ecx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431390(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = cpu->esi;
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000313A0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000313A0;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4313B5u)); sfera_sub_004312E0(cpu, LIFT_CODE_TOKEN_VA(0x4313B5u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004313F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = (uint32_t)(cpu->ecx + 8u);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 4u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x431408u)); sfera_sub_004905D0(cpu, LIFT_CODE_TOKEN_VA(0x431408u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431460(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0xFFFFFFFFu);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x431482u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x431482u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431490(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->eax = 0u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    std::construct_at(reinterpret_cast<HyperTextElement_WordWrap*>(cpu->esi));
    lift_push32(cpu, 0xFFFFFFFFu);
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->ecx) = cpu->eax & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4314BAu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4314BAu));
    *(uint32_t*)(cpu->esi + 4u) = 3u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004314D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = 0u;
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4314F6u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4314F6u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431500(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebx = 0u;
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebx;
    std::construct_at(reinterpret_cast<HyperTextElement*>(cpu->esi));
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->ebx;
    lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->ecx) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x431550u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x431550u));
    *(uint32_t*)(cpu->esi + 4u) = 1u;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = (uint32_t)(cpu->esi + 0x34u);
    std::construct_at(reinterpret_cast<HyperTextElementWithParameters*>(cpu->esi));
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->ebx;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    *(uint8_t*)(cpu->ecx) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43157Du)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x43157Du));
    *(uint32_t*)(cpu->esi + 4u) = 2u;
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004315A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = 0u;
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx += 0x34u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4315C6u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4315C6u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004315D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    *(uint32_t*)(cpu->esi + 4u) = 0u;
    std::construct_at(reinterpret_cast<HyperTextElement*>(cpu->esi));
    lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = 0u;
    lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->ecx) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x431602u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x431602u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->eax;
    std::construct_at(reinterpret_cast<HyperTextElement_PlainText*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x28u) = 0u;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = 4u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431640(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43166Au)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x43166Au));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431680(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, 3u); lift_push32(cpu, 0u);
    cpu->esi = (uint32_t)(cpu->edi + 0x50u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"://");
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4316A0u)); sfera_sub_004312E0(cpu, LIFT_CODE_TOKEN_VA(0x4316A0u));
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000316F7;
    cpu->edi = *(uint32_t*)(cpu->edi + 0x60u);
    cpu->ecx = (uint32_t)(cpu->eax + 3u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->edi)) goto label_000316F7;
    if (*(uint32_t*)(cpu->esi + 0x14u) < (uint32_t)(0x10u)) goto label_000316B9;
    cpu->edx = *(uint32_t*)(cpu->esi);
    goto label_000316BB;
    label_000316B9:
    cpu->edx = cpu->esi;
    label_000316BB:
    if (*(uint8_t*)(cpu->edx + cpu->eax + 3u) != (uint8_t)(0x2Fu)) goto label_000316E0;
    cpu->eax += 4u;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edi)) goto label_000316F7;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4316D8u)); sfera_sub_00431640(cpu, LIFT_CODE_TOKEN_VA(0x4316D8u));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000316E0:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4316EFu)); sfera_sub_00431640(cpu, LIFT_CODE_TOKEN_VA(0x4316EFu));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000316F7:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    lift_push32(cpu, (uint32_t)(uintptr_t)"");
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43171Au)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x43171Au));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431730(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x431769u)); sfera_sub_00431500(cpu, LIFT_CODE_TOKEN_VA(0x431769u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = (uint32_t)(cpu->esi + 0x50u);
    std::construct_at(reinterpret_cast<HyperTextElement_Link*>(cpu->esi));
    lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->ecx + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = 0u;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    *(uint8_t*)(cpu->ecx) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x431799u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x431799u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esi + 0x6Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x28u) = 0u;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = 5u;
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x20u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004317E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->ecx += 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4317F1u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x4317F1u));
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_vswprintf), LIFT_CODE_TOKEN_VA(0x43180Fu));
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431820(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    if ((uint32_t)(cpu->eax) > (uint32_t)(0xFFFFu)) goto label_00031842;
    cpu->edx = cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    if (*(uint32_t*)(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id)) != (uint32_t)(cpu->eax)) goto label_00031842;
    if ((int32_t)*(uint32_t*)(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index)) >= (int32_t)(uint32_t)(0u)) goto label_00031845;
    label_00031842:
    cpu->eax |= 0xFFFFFFFFu;
    label_00031845:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx -= cpu->edx;
    cpu->eax = cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x3840u)) goto label_00031872;
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_0003186B;
    cpu->eax = (uint32_t)(cpu->ecx + 0x8000u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003186B:
    cpu->eax = (uint32_t)(cpu->ecx + 0xFFFF8000u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00031872:
    cpu->eax = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431880(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1B4u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::sprintf);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = 0u;
    label_000318A0:
    cpu->eax = g_sfera_network_runtime.local_port_candidate;
    ++cpu->eax;
    g_sfera_network_runtime.local_port_candidate = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(0x68ECu)) goto label_000318BC;
    cpu->eax = 0x68EAu;
    g_sfera_network_runtime.local_port_candidate = (uint32_t)(cpu->eax);
    label_000318BC:
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->eax;
    cpu->eax = (uint32_t)(cpu->esp + 0x1B4u);
    lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x318CEu), LIFT_CODE_TOKEN_RVA(0x318CCu))) { return; }
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x202u);
    lift_native_call(cpu, native_function_address32(&::WSAStartup), LIFT_CODE_TOKEN_VA(0x4318DBu));
    if ((uint32_t)(cpu->eax) != 0u) goto label_0003194A;
    lift_push32(cpu, (uint32_t)(uintptr_t)"");
    lift_native_call(cpu, native_function_address32(&::gethostbyname), LIFT_CODE_TOKEN_VA(0x4318E9u));
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::inet_ntoa), LIFT_CODE_TOKEN_VA(0x4318F6u));
    cpu->edx = 2u;
    lift_push32(cpu, cpu->eax);
    *(uint16_t*)(cpu->esp + 0x14u) = cpu->edx & 0xFFFFu;
    lift_native_call(cpu, native_function_address32(&::inet_addr), LIFT_CODE_TOKEN_VA(0x431906u));
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::htons), LIFT_CODE_TOKEN_VA(0x431910u));
    lift_push32(cpu, 0u); lift_push32(cpu, 2u); lift_push32(cpu, 2u);
    *(uint16_t*)(cpu->esp + 0x1Eu) = cpu->eax & 0xFFFFu;
    lift_native_call(cpu, native_function_address32(&::socket), LIFT_CODE_TOKEN_VA(0x431920u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, 0x10u);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::bind), LIFT_CODE_TOKEN_VA(0x43192Fu));
    lift_push32(cpu, cpu->esi);
    cpu->edi = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::closesocket), LIFT_CODE_TOKEN_VA(0x431937u));
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x43193Cu));
    { uint64_t v=(uint64_t)(cpu->edi); lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00031972;
    label_0003194A:
    ++cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(3u)) goto label_000318A0;
    cpu->eax = 0x68EAu;
    label_00031959:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1B4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00031972:
    cpu->eax = g_sfera_network_runtime.local_port_candidate;
    goto label_00031959;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_directplay_runtime.peer;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000319F6;
    lift_push32(cpu, 0u);
    g_sfera_directplay_runtime.connection_info.size = (uint32_t)(0x5Cu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x50u);
    lift_push32(cpu, (uintptr_t)&g_sfera_directplay_runtime.connection_info); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x319A2u), LIFT_CODE_TOKEN_RVA(0x319A0u))) { return; }
    cpu->eax = *(uint32_t*)((uintptr_t)&g_sfera_directplay_runtime.connection_info.bytes_sent_guaranteed);
    cpu->eax += *(uint32_t*)((uint32_t)(uintptr_t)&g_sfera_directplay_runtime.connection_info.bytes_sent_non_guaranteed);
    cpu->edx = cpu->eax;
    cpu->edx -= g_sfera_recovered_static_runtime.network_bytes_received_snapshot;
    g_sfera_recovered_static_runtime.network_bytes_received_snapshot = (uint32_t)(cpu->eax);
    cpu->eax = *(uint32_t*)((uintptr_t)&g_sfera_directplay_runtime.connection_info.bytes_retried);
    cpu->ecx = cpu->eax;
    cpu->ecx -= g_sfera_recovered_static_runtime.network_bytes_retried_snapshot;
    g_sfera_recovered_static_runtime.network_bytes_retried_snapshot = (uint32_t)(cpu->eax);
    cpu->eax = *(uint32_t*)((uintptr_t)&g_sfera_directplay_runtime.connection_info.bytes_received_non_guaranteed);
    cpu->eax += *(uint32_t*)((uint32_t)(uintptr_t)&g_sfera_directplay_runtime.connection_info.bytes_received_guaranteed);
    g_sfera_network_runtime.bytes_retried_delta = (uint32_t)(cpu->ecx);
    cpu->ecx = cpu->eax;
    cpu->ecx -= g_sfera_recovered_static_runtime.network_bytes_sent_snapshot;
    g_sfera_network_runtime.bytes_sent_delta = (uint32_t)(cpu->edx);
    g_sfera_network_runtime.bytes_received_delta = (uint32_t)(cpu->ecx);
    g_sfera_recovered_static_runtime.network_bytes_sent_snapshot = (uint32_t)(cpu->eax);
    label_000319F6:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431A00(LiftCpu* cpu, uint32_t stop_address) {
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_24)) == (uint32_t)(0u)) goto label_00031A60;
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_window_runtime.timing_critical_section[0]);
    g_sfera_directplay_runtime.connection_info.size = (uint32_t)(0x5Cu);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x431A18u));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_24;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xEAA8u);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_window_runtime.timing_critical_section[0]);
    g_sfera_directplay_runtime.connection_info.round_trip_latency_ms = (uint32_t)(cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x431A34u));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_24;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xEA94u);
    g_sfera_network_runtime.bytes_sent_delta = (uint32_t)(cpu->edx);
    g_sfera_network_runtime.bytes_retried_delta = (uint32_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0xEA98u);
    g_sfera_network_runtime.bytes_received_delta = (uint32_t)(cpu->eax);
    label_00031A60:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431A70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x24u;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFF0005u)) goto label_00031AAE;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFF0016u)) goto label_00031AAE;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFF0009u)) goto label_00031AAE;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFF000Eu)) goto label_00031AAE;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFF000Fu)) goto label_00031AAE;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(0xFFFF0007u)) goto label_00031ACF;
    label_00031AAE:
    cpu->eax = cpu->ecx & 0xFFFFu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, (uintptr_t)"MessID: %u\n"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x431ABCu));
    cpu->esp += 0xCu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x31ACFu)); sfera_sub_0047FED0(cpu, LIFT_CODE_TOKEN_RVA(0x31ACFu));
    label_00031ACF:
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431AE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_directplay_runtime.critical_section[0]);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x431AE5u));
    cpu->eax = g_sfera_directplay_runtime.transport.receive_write_index;
    cpu->edx = 0u;
    cpu->ecx = 1u;
    if ((uint8_t)(g_sfera_directplay_runtime.transport.receive_busy) == (uint8_t)((cpu->edx & 0xFFu))) goto label_00031B0D;
    g_sfera_directplay_runtime.transport.receive_corrupted = (uint8_t)((cpu->ecx & 0xFFu));
    if ((uint32_t)(cpu->eax) == (uint32_t)(g_sfera_directplay_runtime.transport.receive_read_index)) goto label_00031B13;
    label_00031B0D:
    g_sfera_directplay_runtime.transport.receive_corrupted = (uint8_t)((cpu->edx & 0xFFu));
    label_00031B13:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->eax;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x1A8u);
    cpu->eax += cpu->ecx;
    cpu->esi += ((uint32_t)(uintptr_t)&g_sfera_network_runtime.message_slots[0]);
    g_sfera_directplay_runtime.transport.receive_write_index = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xBE8u)) goto label_00031B36;
    g_sfera_directplay_runtime.transport.receive_write_index = (uint32_t)(cpu->edx);
    label_00031B36:
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_directplay_runtime.critical_section[0]);
    g_sfera_directplay_runtime.transport.receive_busy = (uint8_t)((cpu->ecx & 0xFFu));
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x431B41u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431B50(LiftCpu* cpu, uint32_t stop_address) {
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled)) == (uint8_t)(1u)) goto label_00031C12;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x431B69u)); sfera_sub_00431A70(cpu, LIFT_CODE_TOKEN_VA(0x431B69u));
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFF0005u)) goto label_00031BFC;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFF0011u)) goto label_00031BA0;
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFF0016u)) goto label_00031C11;
    g_sfera_network_runtime.initialization_result = (uint32_t)(0xFFFFFFFFu);
    g_sfera_network_runtime.timeout_marker_pending = (uint8_t)(1u);
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00031BA0:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x431BA5u)); sfera_sub_00431AE0(cpu, LIFT_CODE_TOKEN_VA(0x431BA5u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)((uint32_t)(uintptr_t)&g_sfera_directplay_runtime.transport.sent_packet_count) = (uint64_t)(g_sfera_directplay_runtime.transport.sent_packet_count) + 1u;
    *(uint32_t*)(cpu->eax) = 0xFFFF0011u;
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = 0xFFFFFFFFu;
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x10u);
    { uint64_t l=(uint64_t)(g_sfera_directplay_runtime.transport.sent_bytes.low), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); *(uint32_t*)((uint32_t)(uintptr_t)&g_sfera_directplay_runtime.transport.sent_bytes.low) = v; }
    *(uint32_t*)((uint32_t)(uintptr_t)&g_sfera_directplay_runtime.transport.sent_bytes.high) = (uint64_t)(g_sfera_directplay_runtime.transport.sent_bytes.high) + (uint64_t)(0u) + (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    if ((uint32_t)(cpu->ecx) < (uint32_t)(0x190u)) goto label_00031BDF;
    cpu->ecx = 0x18Fu;
    label_00031BDF:
    *(uint32_t*)(cpu->eax + 0x19Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edx + 0xCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->eax += 0xCu;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x431BEEu));
    cpu->esp += 0xCu;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00031BFC:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->ecx + 0xCu)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->eax + cpu->eax + 0xFFFFFFFFu);
    g_sfera_network_runtime.initialization_result = (uint32_t)(cpu->eax);
    label_00031C11:
    cpu->esi = lift_pop32(cpu);
    label_00031C12:
    cpu->eax = 0u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431C20(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00031C20;
    label_0002EA80:
    cpu->eax = 0x1010u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42EA8Au)); sfera_sub_004EEAF0(cpu, LIFT_CODE_TOKEN_VA(0x42EA8Au));
    cpu->eax = (uint32_t)(uintptr_t)"NetError.log";
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"r"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x42EAA4u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0002EB58;
    lift_push32(cpu, 0x1000u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x42EAC3u));
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0002EAD0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_error_log_runtime.index_table[0]))) & 0xFFu);
    *(uint8_t*)(cpu->esp + cpu->eax + 0x11u) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0002EAD0;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0xF7Bu);
    cpu->edx = (uint32_t)(cpu->esp + 0x9Du);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    *(uint8_t*)(cpu->esp + 0x20u) = 4u;
    lift_native_call(cpu, native_function_address32(&::fread), LIFT_CODE_TOKEN_VA(0x42EAF4u));
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0xA5u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x42EB02u));
    cpu->esp += 0x14u;
    lift_push32(cpu, 0xB8u);
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0x2BF20u);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    cpu->eax = g_sfera_directplay_runtime.peer;
    lift_push32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0x1000u;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x20u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x2EB48u), LIFT_CODE_TOKEN_RVA(0x2EB46u))) { return; }
    cpu->ecx = (uint32_t)(uintptr_t)"NetError.log";
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x42EB4Fu));
    cpu->esp += 4u;
    label_0002EB58:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1010u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00031C20:
    cpu->esp -= 0x38u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(3u)) goto label_000326BD;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFF0011u)) goto label_00032784;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x19Cu);
    cpu->edx = 1u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_00031C63;
    if (*(uint8_t*)(cpu->edi + 0xCu) != (uint8_t)(2u)) goto label_00031C63;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x431C58u)); sfera_sub_0042E990(cpu, LIFT_CODE_TOKEN_VA(0x431C58u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    goto label_0002EA80;
    label_00031C63:
    cpu->ecx = 0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = (uint32_t)(cpu->edi + 0xDu);
    *(uint8_t*)(cpu->eax + cpu->ebp + 0xFFFFFFFFu) = cpu->ecx & 0xFFu;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->ebp)) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) & (uint64_t)(1u))) & 0xFFu);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ecx;
    *(uint8_t*)(cpu->esp + 0x40u) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ecx;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x40u)), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031DF2;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(2u) & 0xFFu);
    cpu->esi = cpu->ebp;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    cpu->edi = 4u;
    label_00031CA7:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031CAF;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00031CB5;
    label_00031CAF:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00031CB5:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031CBC;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031CBC:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031CC3;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031CC3:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031CCB;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00031CD1;
    label_00031CCB:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00031CD1:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031CD8;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031CD8:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031CDF;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031CDF:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031CE7;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00031CED;
    label_00031CE7:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00031CED:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031CF4;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031CF4:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031CFB;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031CFB:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031D03;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00031D09;
    label_00031D03:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00031D09:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031D10;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031D10:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031D17;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031D17:
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031CA7;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(2u) & 0xFFu);
    cpu->esi = (uint32_t)(cpu->ebp + 2u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    cpu->edi = 0xDu;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00031D30:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031D38;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00031D3E;
    label_00031D38:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00031D3E:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031D45;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031D45:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031D4C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031D4C:
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031D30;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(0x40u) & 0xFFu);
    cpu->esi = (uint32_t)(cpu->ebp + 3u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    cpu->edi = 4u;
    (void)cpu;
    label_00031D60:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031D68;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00031D6E;
    label_00031D68:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00031D6E:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031D75;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031D75:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031D7C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031D7C:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031D84;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00031D8A;
    label_00031D84:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00031D8A:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031D91;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031D91:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031D98;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031D98:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031DA0;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00031DA6;
    label_00031DA0:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00031DA6:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031DAD;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031DAD:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031DB4;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031DB4:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031DBC;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00031DC2;
    label_00031DBC:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00031DC2:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031DC9;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031DC9:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031DD0;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031DD0:
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031D60;
    *(uint32_t*)(cpu->esp + 0x38u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x38u)) - (uint64_t)(0x4B0u) - (uint64_t)(0u);
    cpu->eax = 0x8000u;
    *(uint32_t*)(cpu->esp + 0x34u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x34u)) - (uint64_t)(cpu->eax) - (uint64_t)(0u);
    *(uint32_t*)(cpu->esp + 0x3Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x3Cu)) - (uint64_t)(cpu->eax) - (uint64_t)(0u);
    *(uint32_t*)(cpu->esp + 0x10u) = 0x2Eu;
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    label_00031DF2:
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->ecx;
    cpu->eax = (uint32_t)((int32_t)(cpu->eax) >> 3u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((uint8_t)((uint8_t)((cpu->edx & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u))) & 0xFFu);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ebp);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    cpu->edi = 3u;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00031E20:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031E28;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00031E2E;
    label_00031E28:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00031E2E:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031E35;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031E35:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031E3C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031E3C:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031E44;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00031E4A;
    label_00031E44:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00031E4A:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031E51;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031E51:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031E58;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031E58:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031E60;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00031E66;
    label_00031E60:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00031E66:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031E6D;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031E6D:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031E74;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031E74:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031E7C;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00031E82;
    label_00031E7C:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00031E82:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031E89;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031E89:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031E90;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031E90:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031E98;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00031E9E;
    label_00031E98:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00031E9E:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031EA5;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031EA5:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031EAC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031EAC:
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031E20;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(0xFu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    label_00031EC0:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = cpu->ecx;
    cpu->eax = (uint32_t)((int32_t)(cpu->eax) >> 3u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((uint8_t)((uint8_t)((cpu->edx & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u))) & 0xFFu);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ebp);
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    cpu->edi = 3u;
    label_00031EF0:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031EF8;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00031EFE;
    label_00031EF8:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00031EFE:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031F05;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031F05:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031F0C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031F0C:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031F14;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00031F1A;
    label_00031F14:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00031F1A:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031F21;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031F21:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031F28;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031F28:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031F30;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00031F36;
    label_00031F30:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00031F36:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031F3D;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031F3D:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031F44;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031F44:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031F4C;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00031F52;
    label_00031F4C:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00031F52:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031F59;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031F59:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031F60;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031F60:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031F68;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00031F6E;
    label_00031F68:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00031F6E:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031F75;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031F75:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031F7C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031F7C:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031F84;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00031F8A;
    label_00031F84:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00031F8A:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031F91;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031F91:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031F98;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031F98:
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031EF0;
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(0x12u) + (uint64_t)(0u);
    lift_push32(cpu, 4u); lift_push32(cpu, 0xCu);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->esp + 0x54u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x431FC5u)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_VA(0x431FC5u));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    if (*(uint32_t*)(cpu->esp + 0x1Cu) != (uint32_t)(cpu->esi)) goto label_000320EF;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0xFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00032080;
    cpu->eax = cpu->edi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id))), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032080;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))), r=(uint64_t)(cpu->esi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00032080;
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0]));
    cpu->edx = (uint32_t)(uintptr_t)"EKill";
    g_sfera_mbc_runtime->active_process = (uint32_t)(cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x432015u)); sfera_sub_00435020(cpu, LIFT_CODE_TOKEN_VA(0x432015u));
    if ((uint32_t)(cpu->eax) != 0u) goto label_00032043;
    cpu->eax = g_sfera_mbc_runtime->active_process;
    *(uint32_t*)(cpu->eax + 0x94u) = (uint64_t)(*(uint32_t*)(cpu->eax + 0x94u)) | (uint64_t)(4u);
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    *(uint8_t*)(cpu->ecx + 0xB8u) = 1u;
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->ecx = *(uint32_t*)(cpu->edx + 0xB4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x32043u)); sfera_sub_00433CF0(cpu, LIFT_CODE_TOKEN_RVA(0x32043u));
    label_00032043:
    cpu->eax = g_sfera_mbc_runtime->active_process;
    *(uint32_t*)(cpu->eax + 0x94u) = (uint64_t)(*(uint32_t*)(cpu->eax + 0x94u)) | (uint64_t)(0x20u);
    cpu->edx = g_sfera_mbc_runtime->active_process;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->edx + 0xB4u)), r=(uint64_t)(cpu->esi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032080;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x690u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\INet.cpp"); lift_push32(cpu, (uintptr_t)"Unloading _main: %s:%d, %d, %d, %d, %d\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43207Du)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x43207Du));
    { uint64_t l=cpu->esp, r=(uint64_t)(0x1Cu), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    label_00032080:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->ebp;
    cpu->eax = (uint32_t)((int32_t)(cpu->eax) >> 3u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((uint8_t)((uint8_t)((cpu->edx & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u))) & 0xFFu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    cpu->esi = (uint32_t)(cpu->eax + cpu->ecx);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    cpu->edi = 7u;
    cpu->edi = cpu->edi;
    label_000320B0:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_000320B8;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_000320BE;
    label_000320B8:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_000320BE:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000320C5;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_000320C5:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000320CC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_000320CC:
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000320B0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebp += 7u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x3Fu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00031EC0;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00032783;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    label_000320EF:
    if ((uint32_t)(cpu->edi) > (uint32_t)(0xFFFFu)) goto label_0003212F;
    cpu->eax = cpu->edi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if (*(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id)) != (uint32_t)(cpu->edi)) goto label_0003211F;
    if ((int32_t)*(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index)) < (int32_t)(uint32_t)(0u)) goto label_0003211F;
    cpu->esi = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    if ((uint32_t)(cpu->edi) != (uint32_t)(0xFFFFFFFFu)) goto label_000321B1;
    label_0003211F:
    if ((uint32_t)(cpu->edi) > (uint32_t)(0xFFFFu)) goto label_0003212F;
    cpu->esi = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edi;
    goto label_00032136;
    label_0003212F:
    cpu->esi |= 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    label_00032136:
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if (*(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id)) == (uint32_t)(cpu->edi)) goto label_0003218E;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x8D8u);
    cpu->ecx += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0]);
    cpu->edx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43215Du)); sfera_sub_00435230(cpu, LIFT_CODE_TOKEN_VA(0x43215Du));
    cpu->esi = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    if ((uint32_t)(cpu->esi) > (uint32_t)(0xFFFFu)) goto label_00032783;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if (*(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id)) != (uint32_t)(cpu->esi)) goto label_00032783;
    if ((int32_t)*(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index)) < (int32_t)(uint32_t)(0u)) goto label_00032783;
    label_0003218E:
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_00032783;
    *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].flags)) = (uint64_t)(*(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].flags))) | (uint64_t)(4u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0]));
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].state_byte_b8)) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x321B1u)); sfera_sub_00433CF0(cpu, LIFT_CODE_TOKEN_RVA(0x321B1u));
    label_000321B1:
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_00032783;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0])), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->esi = v; }
    g_sfera_mbc_runtime->active_process = (uint32_t)(cpu->esi);
    label_000321D0:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->ebp;
    cpu->eax = (uint32_t)((int32_t)(cpu->eax) >> 3u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((uint8_t)((uint8_t)((cpu->edx & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u))) & 0xFFu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    cpu->edi = 7u;
    label_00032202:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003220A;
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) | (uint64_t)((cpu->eax & 0xFFu));
    goto label_00032210;
    label_0003220A:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00032210:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032217;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->ecx;
    label_00032217:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003221E;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_0003221E:
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032202;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xD0u);
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 8u));
    cpu->ebp += 7u;
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0x3Fu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00031EC0;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00032783;
    --cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0x3Du), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0003267D;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003226B;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000322F1;
    label_0003226B:
    if (*(uint32_t*)(cpu->ecx + 0x6Cu) == (uint32_t)(0xFFFFFFFFu)) goto label_000322A0;
    if ((uint8_t)((*(uint8_t*)(cpu->ecx + 0x94u)) & (0x20u)) == 0u) goto label_000322C7;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x28u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_00032299;
    lift_push32(cpu, 0x6FFu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\INet.cpp"); lift_push32(cpu, (uintptr_t)"Unloading _main: %s:%d\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x432296u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x432296u));
    cpu->esp += 0xCu;
    label_00032299:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x322A0u)); sfera_sub_00435D40(cpu, LIFT_CODE_TOKEN_RVA(0x322A0u));
    label_000322A0:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x8D8u);
    cpu->ecx += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4322B9u)); sfera_sub_00435230(cpu, LIFT_CODE_TOKEN_VA(0x4322B9u));
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0003267D;
    label_000322C7:
    *(uint32_t*)(cpu->ecx + 0x94u) = (uint64_t)(*(uint32_t*)(cpu->ecx + 0x94u)) & (uint64_t)(0xFFFFFFFBu);
    cpu->eax = g_sfera_mbc_runtime->active_process;
    *(uint8_t*)(cpu->eax + 0xB8u) = 1u;
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->ecx = *(uint32_t*)(cpu->edx + 0xB4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4322EBu)); sfera_sub_00433CF0(cpu, LIFT_CODE_TOKEN_VA(0x4322EBu));
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    label_000322F1:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xD0u);
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 8u));
    cpu->edi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    cpu->edx = *(uint16_t*)(cpu->edi + 0x22u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edi;
    if ((uint32_t)(cpu->edx) == (uint32_t)(0xFFFFu)) goto label_00032318;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x432312u)); sfera_sub_004350C0(cpu, LIFT_CODE_TOKEN_VA(0x432312u));
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    label_00032318:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1Cu);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0003267D;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = 0u;
    cpu->edi = 0u;
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0003254D;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00032340:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->edi + cpu->eax));
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(0x20u)) goto label_00032359;
    cpu->ebp += cpu->eax;
    goto label_0003252E;
    label_00032359:
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x65u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000323E6;
    cpu->edx = cpu->ebp;
    cpu->edx = (uint32_t)((int32_t)(cpu->edx) >> 3u);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx) * 8u));
    cpu->ecx = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((uint8_t)((uint8_t)((cpu->eax & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u))) & 0xFFu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    { uint64_t l=(uint64_t)(*(uint8_t*)(cpu->ecx)), r=(uint64_t)((cpu->eax & 0xFFu)), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003238C;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->ecx;
    label_0003238C:
    if ((uint8_t)((*(uint8_t*)(cpu->ecx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_00032395;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) | (uint64_t)(2u))) & 0xFFu);
    goto label_00032398;
    label_00032395:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) & (uint64_t)(0xFDu))) & 0xFFu);
    label_00032398:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003239F;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->ecx;
    label_0003239F:
    if ((uint8_t)((*(uint8_t*)(cpu->ecx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_000323A8;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) | (uint64_t)(4u))) & 0xFFu);
    goto label_000323AB;
    label_000323A8:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) & (uint64_t)(0xFBu))) & 0xFFu);
    label_000323AB:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000323B2;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->ecx;
    label_000323B2:
    if ((uint8_t)((*(uint8_t*)(cpu->ecx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_000323CE;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) | (uint64_t)(8u))) & 0xFFu);
    cpu->ebp += 4u;
    ++cpu->edi;
    *(uint8_t*)(cpu->esp + 0x10u) = cpu->edx & 0xFFu;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    goto label_0003252E;
    label_000323CE:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) & (uint64_t)(0xF7u))) & 0xFFu);
    cpu->ebp += 4u;
    ++cpu->edi;
    *(uint8_t*)(cpu->esp + 0x10u) = cpu->edx & 0xFFu;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    goto label_0003252E;
    label_000323E6:
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x66u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000324AA;
    cpu->eax = cpu->ebp;
    cpu->eax = (uint32_t)((int32_t)(cpu->eax) >> 3u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((uint8_t)((uint8_t)((cpu->edx & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u))) & 0xFFu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    cpu->edi = 2u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00032420:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032428;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_0003242E;
    label_00032428:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_0003242E:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032435;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032435:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003243C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_0003243C:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032444;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_0003244A;
    label_00032444:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_0003244A:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032451;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032451:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032458;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032458:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032460;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00032466;
    label_00032460:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00032466:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003246D;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_0003246D:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032474;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032474:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003247C;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00032482;
    label_0003247C:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00032482:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032489;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032489:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032490;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032490:
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032420;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->edi;
    cpu->ebp += 8u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    cpu->ebx = 0u;
    goto label_0003252E;
    label_000324AA:
    cpu->edx = (uint32_t)(cpu->eax + 0xFFFFFF97u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(2u)) goto label_000324B7;
    cpu->ebp += 0xCu;
    goto label_0003252E;
    label_000324B7:
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x67u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032526;
    cpu->edx = (uint32_t)(cpu->ebp + 1u);
    cpu->edx = (uint32_t)((int32_t)(cpu->edx) >> 3u);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx) * 8u));
    cpu->ecx = (uint32_t)(cpu->ebp + 1u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((uint8_t)((uint8_t)((cpu->eax & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u))) & 0xFFu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    { uint64_t l=(uint64_t)(*(uint8_t*)(cpu->edx)), r=(uint64_t)((cpu->eax & 0xFFu)), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000324E8;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->edx;
    label_000324E8:
    if ((uint8_t)((*(uint8_t*)(cpu->edx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_000324F1;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) | (uint64_t)(2u))) & 0xFFu);
    goto label_000324F4;
    label_000324F1:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFDu))) & 0xFFu);
    label_000324F4:
    *(uint8_t*)(cpu->esp + 0x10u) = cpu->ecx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp += 3u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_00032508;
    cpu->ebp += 3u;
    goto label_0003252E;
    label_00032508:
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00032512;
    cpu->ebp += 7u;
    goto label_0003252E;
    label_00032512:
    if ((uint32_t)(cpu->eax) != (uint32_t)(2u)) goto label_0003251C;
    cpu->ebp += 0xEu;
    goto label_0003252E;
    label_0003251C:
    if ((uint32_t)(cpu->eax) != (uint32_t)(3u)) goto label_0003252E;
    cpu->ebp += 0x1Fu;
    goto label_0003252E;
    label_00032526:
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x6Cu)) goto label_0003252E;
    cpu->ebp += 8u;
    label_0003252E:
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_00032539;
    ++cpu->edi;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    goto label_0003253A;
    label_00032539:
    --cpu->esi;
    label_0003253A:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)*(uint32_t*)(cpu->edx + 0x1Cu)) goto label_00032340;
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    label_0003254D:
    { uint64_t l=(uint64_t)(*(uint8_t*)(cpu->ecx + 0x94u)), r=(uint64_t)(4u), v=l & r; lift_flags_logic(cpu,v,8u); }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000321D0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    if ((uint8_t)((*(uint8_t*)(cpu->eax + 0x20u)) & (1u)) != 0u) goto label_0003258A;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + ((uint32_t)(cpu->edi) * 4u) + 0xDCu);
    if ((int32_t)(uint32_t)(cpu->ecx) < 0) goto label_0003258E;
    cpu->edx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x432582u)); sfera_sub_00431850(cpu, LIFT_CODE_TOKEN_VA(0x432582u));
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_000321D0;
    label_0003258A:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    label_0003258E:
    lift_push32(cpu, 0x752u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\INet.cpp";
    cpu->ecx = 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4325A2u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4325A2u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esi) = 0u;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ecx;
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->ecx = *(uint32_t*)(cpu->eax + ((uint32_t)(cpu->edi) * 4u) + 0x1D8u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000325DF;
    *(uint32_t*)(cpu->eax + ((uint32_t)(cpu->edi) * 4u) + 0x1D8u) = cpu->esi;
    goto label_00032616;
    label_000325DF:
    cpu->ebx = 0u;
    label_000325E1:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edi -= *(uint32_t*)(cpu->ecx + 8u);
    cpu->eax = cpu->edi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x3840u)) goto label_00032608;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00032602;
    cpu->edi += 0x8000u;
    goto label_00032608;
    label_00032602:
    cpu->edi -= 0x8000u;
    label_00032608:
    if ((int32_t)(uint32_t)(cpu->edi) < 0) goto label_00032664;
    cpu->ebx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000325E1;
    label_00032614:
    *(uint32_t*)(cpu->ebx) = cpu->esi;
    label_00032616:
    cpu->ebx = cpu->ebp;
    cpu->ebx -= *(uint32_t*)(cpu->esp + 0x44u);
    lift_push32(cpu, 0x77Au);
    cpu->eax = (uint32_t)(cpu->ebx + 8u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(7u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->edi = (uint32_t)(cpu->edx + cpu->eax);
    cpu->edi = (uint32_t)((int32_t)(cpu->edi) >> 3u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\INet.cpp";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43263Au)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x43263Au));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x432641u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43265Fu)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_VA(0x43265Fu));
    goto label_000321D0;
    label_00032664:
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    if ((uint32_t)(cpu->ebx) != 0u) goto label_00032614;
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->edx + ((uint32_t)(cpu->eax) * 4u) + 0x1D8u) = cpu->esi;
    goto label_00032616;
    label_0003267D:
    if ((uint8_t)((*(uint8_t*)(cpu->ecx + 0x94u)) & (4u)) == 0u) goto label_00032783;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x28u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_000326AF;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x6E7u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\INet.cpp"); lift_push32(cpu, (uintptr_t)"Unloading _main: %s:%d, %d, %d\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4326ACu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x4326ACu));
    cpu->esp += 0x14u;
    label_000326AF:
    cpu->ebp = lift_pop32(cpu);
    cpu->ecx = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    sfera_sub_00435D40(cpu, stop_address); return;
    label_000326BD:
    cpu->ecx = *(uint32_t*)(cpu->edi + 8u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x398u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_world_slot_table_runtime.slots[0].linked_handle));
    if ((uint32_t)(cpu->ecx) > (uint32_t)(0xFFFFu)) goto label_00032784;
    cpu->eax = cpu->ecx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if (*(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id)) != (uint32_t)(cpu->ecx)) goto label_00032784;
    cpu->ebx = 0u;
    if ((int32_t)*(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index)) < (int32_t)(uint32_t)(cpu->ebx)) goto label_00032784;
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0]));
    g_sfera_mbc_runtime->active_process = (uint32_t)(cpu->edx);
    lift_push32(cpu, 0x623u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\INet.cpp";
    cpu->ecx = (uint32_t)(cpu->ebx + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x432718u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x432718u));
    cpu->esi = cpu->eax;
    *(uint32_t*)(cpu->esi) = cpu->ebx;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x19Cu);
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ebx;
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x2D0u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_00032746;
    *(uint32_t*)(cpu->ecx + 0x2D0u) = cpu->esi;
    goto label_00032750;
    label_00032746:
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_00032746;
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    label_00032750:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x19Cu);
    lift_push32(cpu, 0x63Du);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\INet.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x432765u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x432765u));
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x19Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edi += 0xCu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x432774u));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00032783:
    cpu->ebp = lift_pop32(cpu);
    label_00032784:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00432790(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = 1u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    if ((uint32_t)(g_sfera_network_runtime.initialization_result) != (uint32_t)(cpu->eax)) goto label_00032865;
    *(uint32_t*)((uint32_t)(uintptr_t)&g_sfera_directplay_runtime.transport.received_packet_count) = (uint64_t)(g_sfera_directplay_runtime.transport.received_packet_count) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xCu);
    { uint64_t l=(uint64_t)(g_sfera_directplay_runtime.transport.received_bytes.low), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); *(uint32_t*)((uint32_t)(uintptr_t)&g_sfera_directplay_runtime.transport.received_bytes.low) = v; }
    *(uint32_t*)((uint32_t)(uintptr_t)&g_sfera_directplay_runtime.transport.received_bytes.high) = (uint64_t)(g_sfera_directplay_runtime.transport.received_bytes.high) + (uint64_t)(0u) + (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    if ((uint32_t)(cpu->ebx) != (uint32_t)(8u)) goto label_000327DF;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = 0x2BF20u;
    cpu->ebx = 0x88u;
    goto label_000327EC;
    label_000327DF:
    cpu->ebx |= 0x90u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = 0xEA60u;
    label_000327EC:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4327F6u)); sfera_sub_0048A1C0(cpu, LIFT_CODE_TOKEN_VA(0x4327F6u));
    cpu->eax = (uint32_t)(cpu->edi + 1u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x432801u)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x432801u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->esi = cpu->esp;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 1u);
    lift_push32(cpu, cpu->ecx);
    *(uint8_t*)(cpu->esi) = 0u;
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43280Fu));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFF4u);
    cpu->esp += 0xCu;
    { uint64_t l=(uint64_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    g_sfera_directplay_runtime.send_buffer.buffer_size = (uint32_t)(cpu->eax);
    *(uint32_t*)((uintptr_t)&g_sfera_directplay_runtime.send_buffer.buffer_data) = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032842;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_24;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x12Cu); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x432840u)); sfera_sub_00418BB0(cpu, LIFT_CODE_TOKEN_VA(0x432840u));
    goto label_00032865;
    label_00032842:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax = g_sfera_directplay_runtime.peer;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edx + 0x20u);
    cpu->ebx |= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&g_sfera_directplay_runtime.send_async_handle); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u); lift_push32(cpu, (uintptr_t)&g_sfera_directplay_runtime.send_buffer); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x32865u), LIFT_CODE_TOKEN_RVA(0x32863u))) { return; }
    label_00032865:
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00432880(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x60u;
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled)) == (uint8_t)(1u)) goto label_00032943;
    if ((uint8_t)(g_sfera_network_runtime.initialized) == (uint8_t)(0u)) goto label_00032943;
    if ((int32_t)(uint32_t)(g_sfera_network_runtime.error_budget) >= (int32_t)(uint32_t)(0x32u)) goto label_000328F1;
    if ((uint8_t)(g_sfera_directplay_runtime.transport.transport_flag) == (uint8_t)(0u)) goto label_000328EA;
    if ((uint8_t)(g_sfera_network_runtime.network_error_active) != (uint8_t)(0u)) goto label_000328DD;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    cpu->ecx = (uint32_t)(uintptr_t)"-- N\n";
    g_sfera_network_runtime.network_error_active = (uint8_t)(1u);
    g_sfera_network_runtime.net_log_has_error = (uint8_t)(1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x328DDu)); sfera_sub_0047FED0(cpu, LIFT_CODE_TOKEN_RVA(0x328DDu));
    label_000328DD:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4328E2u)); sfera_sub_0047FF70(cpu, LIFT_CODE_TOKEN_VA(0x4328E2u));
    *(uint32_t*)((uint32_t)(uintptr_t)&g_sfera_network_runtime.error_budget) = (uint64_t)(g_sfera_network_runtime.error_budget) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    goto label_000328F1;
    label_000328EA:
    g_sfera_network_runtime.network_error_active = (uint8_t)(0u);
    label_000328F1:
    if ((uint8_t)(g_sfera_network_runtime.timeout_marker_pending) != (uint8_t)(1u)) goto label_0003290D;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    cpu->ecx = (uint32_t)(uintptr_t)"-- T\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x432906u)); sfera_sub_0047FED0(cpu, LIFT_CODE_TOKEN_VA(0x432906u));
    g_sfera_network_runtime.timeout_marker_pending = (uint8_t)(0u);
    label_0003290D:
    cpu->eax = g_sfera_directplay_runtime.peer;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00032943;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    *(uint32_t*)(cpu->esp + 4u) = 0x5Cu;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x50u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x3292Du), LIFT_CODE_TOKEN_RVA(0x3292Bu))) { return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00032943;
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x50u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x32943u)); sfera_sub_0047FEB0(cpu, LIFT_CODE_TOKEN_RVA(0x32943u));
    label_00032943:
    cpu->esp += 0x60u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00432970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x38u;
    if (*(uint32_t*)(cpu->ecx) != (uint32_t)(0xFFFF0011u)) goto label_000333FC;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = (uint32_t)(cpu->ecx + 0xDu);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x19Cu);
    *(uint8_t*)(cpu->ecx + cpu->ebp + 0xFFFFFFFFu) = cpu->eax & 0xFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->ebp)) & 0xFFu);
    cpu->ecx = 1u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) & (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    lift_push32(cpu, cpu->esi);
    *(uint8_t*)(cpu->esp + 0x3Cu) = cpu->edx & 0xFFu;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x40u)), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032B14;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(2u) & 0xFFu);
    cpu->esi = cpu->ebp;
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    cpu->edi = (uint32_t)(cpu->ecx + 3u);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000329D0:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_000329D8;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_000329DE;
    label_000329D8:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_000329DE:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000329E5;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_000329E5:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000329EC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_000329EC:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_000329F4;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_000329FA;
    label_000329F4:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_000329FA:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032A01;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032A01:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032A08;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032A08:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032A10;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00032A16;
    label_00032A10:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00032A16:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032A1D;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032A1D:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032A24;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032A24:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032A2C;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00032A32;
    label_00032A2C:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00032A32:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032A39;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032A39:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032A40;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032A40:
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000329D0;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(2u) & 0xFFu);
    cpu->esi = (uint32_t)(cpu->ebp + 2u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    cpu->edi = 0xDu;
    label_00032A53:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032A5B;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00032A61;
    label_00032A5B:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00032A61:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032A68;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032A68:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032A6F;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032A6F:
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032A53;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(0x40u) & 0xFFu);
    cpu->esi = (uint32_t)(cpu->ebp + 3u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    cpu->edi = 4u;
    label_00032A82:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032A8A;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00032A90;
    label_00032A8A:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00032A90:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032A97;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032A97:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032A9E;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032A9E:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032AA6;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00032AAC;
    label_00032AA6:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00032AAC:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032AB3;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032AB3:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032ABA;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032ABA:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032AC2;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00032AC8;
    label_00032AC2:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00032AC8:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032ACF;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032ACF:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032AD6;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032AD6:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032ADE;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00032AE4;
    label_00032ADE:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00032AE4:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032AEB;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032AEB:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032AF2;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032AF2:
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032A82;
    *(uint32_t*)(cpu->esp + 0x38u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x38u)) - (uint64_t)(0x4B0u) - (uint64_t)(0u);
    cpu->eax = 0x8000u;
    *(uint32_t*)(cpu->esp + 0x34u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x34u)) - (uint64_t)(cpu->eax) - (uint64_t)(0u);
    *(uint32_t*)(cpu->esp + 0x3Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x3Cu)) - (uint64_t)(cpu->eax) - (uint64_t)(0u);
    *(uint32_t*)(cpu->esp + 0x10u) = 0x2Eu;
    lift_flags_logic(cpu,0u,32u); cpu->eax = 0u;
    label_00032B14:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    cpu->eax = cpu->ecx;
    cpu->eax = (uint32_t)((int32_t)(cpu->eax) >> 3u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((uint8_t)((uint8_t)((cpu->edx & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u))) & 0xFFu);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ebp);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    cpu->edi = 3u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00032B40:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032B48;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00032B4E;
    label_00032B48:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00032B4E:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032B55;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032B55:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032B5C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032B5C:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032B64;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00032B6A;
    label_00032B64:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00032B6A:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032B71;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032B71:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032B78;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032B78:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032B80;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00032B86;
    label_00032B80:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00032B86:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032B8D;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032B8D:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032B94;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032B94:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032B9C;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00032BA2;
    label_00032B9C:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00032BA2:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032BA9;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032BA9:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032BB0;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032BB0:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032BB8;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00032BBE;
    label_00032BB8:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00032BBE:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032BC5;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032BC5:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032BCC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032BCC:
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032B40;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(0xFu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    label_00032BE0:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = cpu->ecx;
    cpu->eax = (uint32_t)((int32_t)(cpu->eax) >> 3u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((uint8_t)((uint8_t)((cpu->edx & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u))) & 0xFFu);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ebp);
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    cpu->edi = 3u;
    label_00032C10:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032C18;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00032C1E;
    label_00032C18:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00032C1E:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032C25;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032C25:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032C2C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032C2C:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032C34;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00032C3A;
    label_00032C34:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00032C3A:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032C41;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032C41:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032C48;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032C48:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032C50;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00032C56;
    label_00032C50:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00032C56:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032C5D;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032C5D:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032C64;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032C64:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032C6C;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00032C72;
    label_00032C6C:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00032C72:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032C79;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032C79:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032C80;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032C80:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032C88;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00032C8E;
    label_00032C88:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00032C8E:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032C95;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032C95:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032C9C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032C9C:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032CA4;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00032CAA;
    label_00032CA4:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00032CAA:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032CB1;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032CB1:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032CB8;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032CB8:
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032C10;
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(0x12u) + (uint64_t)(0u);
    lift_push32(cpu, 4u); lift_push32(cpu, 0xCu);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->esp + 0x54u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x432CE5u)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_VA(0x432CE5u));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    if (*(uint32_t*)(cpu->esp + 0x1Cu) != (uint32_t)(cpu->esi)) goto label_00032E0F;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0xFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00032DA0;
    cpu->eax = cpu->edi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id))), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032DA0;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))), r=(uint64_t)(cpu->esi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00032DA0;
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0]));
    cpu->edx = (uint32_t)(uintptr_t)"EKill";
    g_sfera_mbc_runtime->active_process = (uint32_t)(cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x432D35u)); sfera_sub_00435020(cpu, LIFT_CODE_TOKEN_VA(0x432D35u));
    if ((uint32_t)(cpu->eax) != 0u) goto label_00032D63;
    cpu->eax = g_sfera_mbc_runtime->active_process;
    *(uint32_t*)(cpu->eax + 0x94u) = (uint64_t)(*(uint32_t*)(cpu->eax + 0x94u)) | (uint64_t)(4u);
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    *(uint8_t*)(cpu->ecx + 0xB8u) = 1u;
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->ecx = *(uint32_t*)(cpu->edx + 0xB4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x32D63u)); sfera_sub_00433CF0(cpu, LIFT_CODE_TOKEN_RVA(0x32D63u));
    label_00032D63:
    cpu->eax = g_sfera_mbc_runtime->active_process;
    *(uint32_t*)(cpu->eax + 0x94u) = (uint64_t)(*(uint32_t*)(cpu->eax + 0x94u)) | (uint64_t)(0x20u);
    cpu->edx = g_sfera_mbc_runtime->active_process;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->edx + 0xB4u)), r=(uint64_t)(cpu->esi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032DA0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x126u); lift_push32(cpu, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\inet_tcp.h"); lift_push32(cpu, (uintptr_t)"Unloading _main: %s:%d, %d, %d, %d, %d\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x432D9Du)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x432D9Du));
    { uint64_t l=cpu->esp, r=(uint64_t)(0x1Cu), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    label_00032DA0:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->ebp;
    cpu->eax = (uint32_t)((int32_t)(cpu->eax) >> 3u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((uint8_t)((uint8_t)((cpu->edx & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u))) & 0xFFu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    cpu->esi = (uint32_t)(cpu->eax + cpu->ecx);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    cpu->edi = 7u;
    cpu->edi = cpu->edi;
    label_00032DD0:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032DD8;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00032DDE;
    label_00032DD8:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00032DDE:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032DE5;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032DE5:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032DEC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032DEC:
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032DD0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebp += 7u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x3Fu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00032BE0;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000333F8;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    label_00032E0F:
    if ((uint32_t)(cpu->edi) > (uint32_t)(0xFFFFu)) goto label_00032E4F;
    cpu->eax = cpu->edi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if (*(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id)) != (uint32_t)(cpu->edi)) goto label_00032E3F;
    if ((int32_t)*(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index)) < (int32_t)(uint32_t)(0u)) goto label_00032E3F;
    cpu->esi = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    if ((uint32_t)(cpu->edi) != (uint32_t)(0xFFFFFFFFu)) goto label_00032ED1;
    label_00032E3F:
    if ((uint32_t)(cpu->edi) > (uint32_t)(0xFFFFu)) goto label_00032E4F;
    cpu->esi = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edi;
    goto label_00032E56;
    label_00032E4F:
    cpu->esi |= 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    label_00032E56:
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if (*(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id)) == (uint32_t)(cpu->edi)) goto label_00032EAE;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x8D8u);
    cpu->ecx += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0]);
    cpu->edx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x432E7Du)); sfera_sub_00435230(cpu, LIFT_CODE_TOKEN_VA(0x432E7Du));
    cpu->esi = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    if ((uint32_t)(cpu->esi) > (uint32_t)(0xFFFFu)) goto label_000333F8;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if (*(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id)) != (uint32_t)(cpu->esi)) goto label_000333F8;
    if ((int32_t)*(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index)) < (int32_t)(uint32_t)(0u)) goto label_000333F8;
    label_00032EAE:
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_000333F8;
    *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].flags)) = (uint64_t)(*(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].flags))) | (uint64_t)(4u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0]));
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].state_byte_b8)) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x32ED1u)); sfera_sub_00433CF0(cpu, LIFT_CODE_TOKEN_RVA(0x32ED1u));
    label_00032ED1:
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_000333F8;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0])), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->esi = v; }
    g_sfera_mbc_runtime->active_process = (uint32_t)(cpu->esi);
    label_00032EF0:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->ebp;
    cpu->eax = (uint32_t)((int32_t)(cpu->eax) >> 3u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((uint8_t)((uint8_t)((cpu->edx & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u))) & 0xFFu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    cpu->edi = 7u;
    label_00032F22:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032F2A;
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) | (uint64_t)((cpu->eax & 0xFFu));
    goto label_00032F30;
    label_00032F2A:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->ecx) = (uint64_t)(*(uint8_t*)(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00032F30:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032F37;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->ecx;
    label_00032F37:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032F3E;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032F3E:
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032F22;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xD0u);
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 8u));
    cpu->ebp += 7u;
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0x3Fu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00032BE0;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000333F8;
    --cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0x3Du), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000333BC;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00032F8B;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00033011;
    label_00032F8B:
    if (*(uint32_t*)(cpu->ecx + 0x6Cu) == (uint32_t)(0xFFFFFFFFu)) goto label_00032FC0;
    if ((uint8_t)((*(uint8_t*)(cpu->ecx + 0x94u)) & (0x20u)) == 0u) goto label_00032FE7;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x28u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_00032FB9;
    lift_push32(cpu, 0x195u); lift_push32(cpu, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\inet_tcp.h"); lift_push32(cpu, (uintptr_t)"Unloading _main: %s:%d\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x432FB6u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x432FB6u));
    cpu->esp += 0xCu;
    label_00032FB9:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x32FC0u)); sfera_sub_00435D40(cpu, LIFT_CODE_TOKEN_RVA(0x32FC0u));
    label_00032FC0:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x8D8u);
    cpu->ecx += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x432FD9u)); sfera_sub_00435230(cpu, LIFT_CODE_TOKEN_VA(0x432FD9u));
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000333BC;
    label_00032FE7:
    *(uint32_t*)(cpu->ecx + 0x94u) = (uint64_t)(*(uint32_t*)(cpu->ecx + 0x94u)) & (uint64_t)(0xFFFFFFFBu);
    cpu->eax = g_sfera_mbc_runtime->active_process;
    *(uint8_t*)(cpu->eax + 0xB8u) = 1u;
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->ecx = *(uint32_t*)(cpu->edx + 0xB4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43300Bu)); sfera_sub_00433CF0(cpu, LIFT_CODE_TOKEN_VA(0x43300Bu));
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    label_00033011:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xD0u);
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 8u));
    cpu->edi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    cpu->edx = *(uint16_t*)(cpu->edi + 0x22u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edi;
    if ((uint32_t)(cpu->edx) == (uint32_t)(0xFFFFu)) goto label_00033038;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433032u)); sfera_sub_004350C0(cpu, LIFT_CODE_TOKEN_VA(0x433032u));
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    label_00033038:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x1Cu);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000333BC;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = 0u;
    cpu->edi = 0u;
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0003326D;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00033060:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->edi + cpu->eax));
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(0x20u)) goto label_00033079;
    cpu->ebp += cpu->eax;
    goto label_0003324E;
    label_00033079:
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x65u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00033106;
    cpu->edx = cpu->ebp;
    cpu->edx = (uint32_t)((int32_t)(cpu->edx) >> 3u);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx) * 8u));
    cpu->ecx = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((uint8_t)((uint8_t)((cpu->eax & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u))) & 0xFFu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    { uint64_t l=(uint64_t)(*(uint8_t*)(cpu->ecx)), r=(uint64_t)((cpu->eax & 0xFFu)), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000330AC;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->ecx;
    label_000330AC:
    if ((uint8_t)((*(uint8_t*)(cpu->ecx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_000330B5;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) | (uint64_t)(2u))) & 0xFFu);
    goto label_000330B8;
    label_000330B5:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) & (uint64_t)(0xFDu))) & 0xFFu);
    label_000330B8:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000330BF;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->ecx;
    label_000330BF:
    if ((uint8_t)((*(uint8_t*)(cpu->ecx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_000330C8;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) | (uint64_t)(4u))) & 0xFFu);
    goto label_000330CB;
    label_000330C8:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) & (uint64_t)(0xFBu))) & 0xFFu);
    label_000330CB:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000330D2;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->ecx;
    label_000330D2:
    if ((uint8_t)((*(uint8_t*)(cpu->ecx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_000330EE;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) | (uint64_t)(8u))) & 0xFFu);
    cpu->ebp += 4u;
    ++cpu->edi;
    *(uint8_t*)(cpu->esp + 0x10u) = cpu->edx & 0xFFu;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    goto label_0003324E;
    label_000330EE:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) & (uint64_t)(0xF7u))) & 0xFFu);
    cpu->ebp += 4u;
    ++cpu->edi;
    *(uint8_t*)(cpu->esp + 0x10u) = cpu->edx & 0xFFu;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    goto label_0003324E;
    label_00033106:
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x66u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000331CA;
    cpu->eax = cpu->ebp;
    cpu->eax = (uint32_t)((int32_t)(cpu->eax) >> 3u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((uint8_t)((uint8_t)((cpu->edx & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u))) & 0xFFu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    cpu->edi = 2u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00033140:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00033148;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_0003314E;
    label_00033148:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_0003314E:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00033155;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00033155:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003315C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_0003315C:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00033164;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_0003316A;
    label_00033164:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_0003316A:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00033171;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00033171:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00033178;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00033178:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00033180;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00033186;
    label_00033180:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00033186:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003318D;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_0003318D:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00033194;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00033194:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003319C;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_000331A2;
    label_0003319C:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_000331A2:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000331A9;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_000331A9:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000331B0;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_000331B0:
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00033140;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->edi;
    cpu->ebp += 8u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    cpu->ebx = 0u;
    goto label_0003324E;
    label_000331CA:
    cpu->edx = (uint32_t)(cpu->eax + 0xFFFFFF97u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(2u)) goto label_000331D7;
    cpu->ebp += 0xCu;
    goto label_0003324E;
    label_000331D7:
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x67u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00033246;
    cpu->edx = (uint32_t)(cpu->ebp + 1u);
    cpu->edx = (uint32_t)((int32_t)(cpu->edx) >> 3u);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx) * 8u));
    cpu->ecx = (uint32_t)(cpu->ebp + 1u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((uint8_t)((uint8_t)((cpu->eax & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u))) & 0xFFu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    { uint64_t l=(uint64_t)(*(uint8_t*)(cpu->edx)), r=(uint64_t)((cpu->eax & 0xFFu)), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00033208;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->edx;
    label_00033208:
    if ((uint8_t)((*(uint8_t*)(cpu->edx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_00033211;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) | (uint64_t)(2u))) & 0xFFu);
    goto label_00033214;
    label_00033211:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFDu))) & 0xFFu);
    label_00033214:
    *(uint8_t*)(cpu->esp + 0x10u) = cpu->ecx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp += 3u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_00033228;
    cpu->ebp += 3u;
    goto label_0003324E;
    label_00033228:
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00033232;
    cpu->ebp += 7u;
    goto label_0003324E;
    label_00033232:
    if ((uint32_t)(cpu->eax) != (uint32_t)(2u)) goto label_0003323C;
    cpu->ebp += 0xEu;
    goto label_0003324E;
    label_0003323C:
    if ((uint32_t)(cpu->eax) != (uint32_t)(3u)) goto label_0003324E;
    cpu->ebp += 0x1Fu;
    goto label_0003324E;
    label_00033246:
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x6Cu)) goto label_0003324E;
    cpu->ebp += 8u;
    label_0003324E:
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_00033259;
    ++cpu->edi;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    goto label_0003325A;
    label_00033259:
    --cpu->esi;
    label_0003325A:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)*(uint32_t*)(cpu->edx + 0x1Cu)) goto label_00033060;
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    label_0003326D:
    { uint64_t l=(uint64_t)(*(uint8_t*)(cpu->ecx + 0x94u)), r=(uint64_t)(4u), v=l & r; lift_flags_logic(cpu,v,8u); }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032EF0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    if ((uint8_t)((*(uint8_t*)(cpu->eax + 0x20u)) & (1u)) != 0u) goto label_000332C5;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->ecx + ((uint32_t)(cpu->edi) * 4u) + 0xDCu);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000332C9;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx -= cpu->eax;
    cpu->eax = cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x3840u)) goto label_000332BD;
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000332B7;
    cpu->ecx += 0x8000u;
    goto label_000332BD;
    label_000332B7:
    cpu->ecx -= 0x8000u;
    label_000332BD:
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_00032EF0;
    label_000332C5:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    label_000332C9:
    lift_push32(cpu, 0x1E8u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\inet_tcp.h";
    cpu->ecx = 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4332DDu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4332DDu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esi) = 0u;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ecx;
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->ecx = *(uint32_t*)(cpu->eax + ((uint32_t)(cpu->edi) * 4u) + 0x1D8u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_0003331A;
    *(uint32_t*)(cpu->eax + ((uint32_t)(cpu->edi) * 4u) + 0x1D8u) = cpu->esi;
    goto label_00033355;
    label_0003331A:
    cpu->ebx = 0u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00033320:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edi -= *(uint32_t*)(cpu->ecx + 8u);
    cpu->eax = cpu->edi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x3840u)) goto label_00033347;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00033341;
    cpu->edi += 0x8000u;
    goto label_00033347;
    label_00033341:
    cpu->edi -= 0x8000u;
    label_00033347:
    if ((int32_t)(uint32_t)(cpu->edi) < 0) goto label_000333A3;
    cpu->ebx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_00033320;
    label_00033353:
    *(uint32_t*)(cpu->ebx) = cpu->esi;
    label_00033355:
    cpu->ebx = cpu->ebp;
    cpu->ebx -= *(uint32_t*)(cpu->esp + 0x44u);
    lift_push32(cpu, 0x210u);
    cpu->eax = (uint32_t)(cpu->ebx + 8u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(7u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->edi = (uint32_t)(cpu->edx + cpu->eax);
    cpu->edi = (uint32_t)((int32_t)(cpu->edi) >> 3u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\inet_tcp.h";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433379u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x433379u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x433380u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43339Eu)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_VA(0x43339Eu));
    goto label_00032EF0;
    label_000333A3:
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    if ((uint32_t)(cpu->ebx) != 0u) goto label_00033353;
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->edx + ((uint32_t)(cpu->eax) * 4u) + 0x1D8u) = cpu->esi;
    goto label_00033355;
    label_000333BC:
    if ((uint8_t)((*(uint8_t*)(cpu->ecx + 0x94u)) & (4u)) == 0u) goto label_000333F8;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x28u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_000333EA;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x17Du); lift_push32(cpu, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\inet_tcp.h"); lift_push32(cpu, (uintptr_t)"Unloading _main: %s:%d, %d, %d\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4333E7u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x4333E7u));
    cpu->esp += 0x14u;
    label_000333EA:
    cpu->ecx = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    sfera_sub_00435D40(cpu, stop_address); return;
    label_000333F8:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000333FC:
    cpu->esp += 0x38u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433400(LiftCpu* cpu, uint32_t stop_address) {
    if ((uint32_t)(cpu->edx) != (uint32_t)(0xFFFF0011u)) goto label_0003345E;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43340Du)); sfera_sub_00431AE0(cpu, LIFT_CODE_TOKEN_VA(0x43340Du));
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)((uint32_t)(uintptr_t)&g_sfera_directplay_runtime.transport.sent_packet_count) = (uint64_t)(g_sfera_directplay_runtime.transport.sent_packet_count) + 1u;
    *(uint32_t*)(cpu->eax) = 0xFFFF0011u;
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = 0xFFFFFFFFu;
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x10u);
    { uint64_t l=(uint64_t)(g_sfera_directplay_runtime.transport.sent_bytes.low), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); *(uint32_t*)((uint32_t)(uintptr_t)&g_sfera_directplay_runtime.transport.sent_bytes.low) = v; }
    *(uint32_t*)((uint32_t)(uintptr_t)&g_sfera_directplay_runtime.transport.sent_bytes.high) = (uint64_t)(g_sfera_directplay_runtime.transport.sent_bytes.high) + (uint64_t)(0u) + (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    if ((uint32_t)(cpu->ecx) < (uint32_t)(0x190u)) goto label_00033447;
    cpu->ecx = 0x18Fu;
    label_00033447:
    *(uint32_t*)(cpu->eax + 0x19Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edx + 0xCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->eax += 0xCu;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x433456u));
    cpu->esp += 0xCu;
    label_0003345E:
    cpu->eax = 0u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433470(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1ECu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x1FCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = 0u;
    cpu->edi = cpu->ecx;
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000334CA;
    g_sfera_directplay_runtime.caps.size = (uint32_t)(0x14u);
    g_sfera_network_runtime.directplay_caps.words[0] = (uint32_t)(0x30u);
    label_000334CA:
    cpu->eax = 3u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    g_sfera_directplay_runtime.transport.mode = (uint32_t)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20Cu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000334E8;
    g_sfera_network_runtime.server_port = (uint32_t)(cpu->eax);
    label_000334E8:
    cpu->eax = g_sfera_network_runtime.initialization_result;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0003392B;
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x6Cu);
    lift_push32(cpu, (uintptr_t)L"%S"); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433505u)); sfera_sub_00431800(cpu, LIFT_CODE_TOKEN_VA(0x433505u));
    cpu->esp += 0xCu;
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_directplay_runtime.critical_section[0]);
    g_sfera_directplay_runtime.transport.receive_read_index = (uint32_t)(cpu->ebx);
    g_sfera_directplay_runtime.transport.receive_write_index = (uint32_t)(cpu->ebx);
    *(uint32_t*)((uintptr_t)&g_sfera_directplay_runtime.transport.reserved_30) = cpu->ebx;
    lift_native_call(cpu, native_function_address32(&::InitializeCriticalSection), LIFT_CODE_TOKEN_VA(0x43351Fu));
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000337D3;
    lift_push32(cpu, 0x48u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x433539u));
    cpu->edx = 0x231B9780u;
    cpu->eax = 0x11D51577u;
    cpu->ecx = 0x8F885D8Eu;
    cpu->esi = native_function_address32(&::CoCreateInstance);
    cpu->esp += 0xCu;
    lift_push32(cpu, (uintptr_t)&g_sfera_directplay_runtime.peer); lift_push32(cpu, (uintptr_t)&kDirectPlay8ClientIid); lift_push32(cpu, 1u);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edx;
    cpu->edx = 0x76AA058Fu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&kDirectPlay8ClientClsid);
    *(uint32_t*)(cpu->esp + 0x34u) = 0x48u;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->edx;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x3358Au), LIFT_CODE_TOKEN_RVA(0x33588u))) { return; }
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000338EC;
    cpu->eax = g_sfera_directplay_runtime.transport.primary_address;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000335A9;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x335A3u), LIFT_CODE_TOKEN_RVA(0x335A1u))) { return; }
    g_sfera_directplay_runtime.transport.primary_address = (uint32_t)(cpu->ebx);
    label_000335A9:
    lift_push32(cpu, (uintptr_t)&g_sfera_directplay_runtime.transport.primary_address); lift_push32(cpu, (uintptr_t)&kDirectPlay8AddressIid); lift_push32(cpu, 0x17u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&kDirectPlay8AddressClsid);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x335BDu), LIFT_CODE_TOKEN_RVA(0x335BBu))) { return; }
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000338EC;
    cpu->eax = g_sfera_directplay_runtime.transport.secondary_address;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000335DC;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x335D6u), LIFT_CODE_TOKEN_RVA(0x335D4u))) { return; }
    g_sfera_directplay_runtime.transport.secondary_address = (uint32_t)(cpu->ebx);
    label_000335DC:
    lift_push32(cpu, (uintptr_t)&g_sfera_directplay_runtime.transport.secondary_address); lift_push32(cpu, (uintptr_t)&kDirectPlay8AddressIid); lift_push32(cpu, 0x17u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&kDirectPlay8AddressClsid);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x335F0u), LIFT_CODE_TOKEN_RVA(0x335EEu))) { return; }
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000338EC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ecx = (uint32_t)(uintptr_t)"Initialize\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433604u)); sfera_sub_0047FED0(cpu, LIFT_CODE_TOKEN_VA(0x433604u));
    cpu->eax = g_sfera_directplay_runtime.peer;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xCu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00431B50)); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x33618u), LIFT_CODE_TOKEN_RVA(0x33616u))) { return; }
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000338EC;
    cpu->eax = g_sfera_directplay_runtime.transport.primary_address;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x34u);
    lift_push32(cpu, (uintptr_t)&kDirectPlay8TcpIpProvider); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x33632u), LIFT_CODE_TOKEN_RVA(0x33630u))) { return; }
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000338EC;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43363Fu)); sfera_sub_00431880(cpu, LIFT_CODE_TOKEN_VA(0x43363Fu));
    lift_push32(cpu, 2u); lift_push32(cpu, 4u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    cpu->eax = g_sfera_directplay_runtime.transport.primary_address;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)L"port"); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x48u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x3365Eu), LIFT_CODE_TOKEN_RVA(0x3365Cu))) { return; }
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000338EC;
    cpu->eax = g_sfera_directplay_runtime.transport.primary_address;
    lift_push32(cpu, 2u); lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x20u) = 2u;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, (uintptr_t)L"traversalmode"); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x48u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x33689u), LIFT_CODE_TOKEN_RVA(0x33687u))) { return; }
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000338EC;
    cpu->eax = g_sfera_directplay_runtime.transport.secondary_address;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x34u);
    lift_push32(cpu, (uintptr_t)&kDirectPlay8TcpIpProvider); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x336A3u), LIFT_CODE_TOKEN_RVA(0x336A1u))) { return; }
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000338EC;
    cpu->eax = (uint32_t)(cpu->esp + 0x68u);
    cpu->edx = (uint32_t)(cpu->eax + 2u);
    label_000336B2:
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(*(uint16_t*)(cpu->eax)) & 0xFFFFu);
    cpu->eax += 2u;
    if ((uint16_t)((cpu->ecx & 0xFFFFu)) != (uint16_t)((cpu->ebx & 0xFFFFu))) goto label_000336B2;
    cpu->ecx = g_sfera_directplay_runtime.transport.secondary_address;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = (uint32_t)((int32_t)(cpu->eax) >> 1u);
    lift_push32(cpu, 1u);
    cpu->eax = (uint32_t)(cpu->eax + cpu->eax + 2u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x70u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)L"hostname"); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x48u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ecx), LIFT_CODE_TOKEN_RVA(0x336E0u), LIFT_CODE_TOKEN_RVA(0x336DEu))) { return; }
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000338EC;
    cpu->eax = g_sfera_directplay_runtime.transport.secondary_address;
    cpu->edx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, 2u); lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)&g_sfera_network_runtime.server_port); lift_push32(cpu, (uintptr_t)L"port"); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x48u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x33703u), LIFT_CODE_TOKEN_RVA(0x33701u))) { return; }
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000338EC;
    cpu->eax = g_sfera_directplay_runtime.peer;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x40u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&g_sfera_network_runtime.directplay_caps); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x3371Eu), LIFT_CODE_TOKEN_RVA(0x3371Cu))) { return; }
    cpu->eax = g_sfera_directplay_runtime.peer;
    lift_push32(cpu, cpu->ebx);
    g_sfera_network_runtime.directplay_caps.words[8] = 0x64u;
    g_sfera_network_runtime.directplay_caps.words[9] = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x44u);
    lift_push32(cpu, (uintptr_t)&g_sfera_network_runtime.directplay_caps); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x33741u), LIFT_CODE_TOKEN_RVA(0x3373Fu))) { return; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    cpu->ecx = (uint32_t)(uintptr_t)"Connect\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43374Du)); sfera_sub_0047FED0(cpu, LIFT_CODE_TOKEN_VA(0x43374Du));
    cpu->eax = g_sfera_directplay_runtime.peer;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&g_sfera_network_runtime.message_call_scratch); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_directplay_runtime.transport.primary_address;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_directplay_runtime.transport.secondary_address;
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x1Cu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x3377Du), LIFT_CODE_TOKEN_RVA(0x3377Bu))) { return; }
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ebx)) goto label_000338EC;
    cpu->eax = g_sfera_directplay_runtime.peer;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&g_sfera_network_runtime.directplay_caps);
    g_sfera_network_runtime.directplay_caps.words[0] = (uint32_t)(0x24u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x4Cu);
    lift_push32(cpu, (uintptr_t)&kDirectPlay8TcpIpProvider); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x337A7u), LIFT_CODE_TOKEN_RVA(0x337A5u))) { return; }
    cpu->eax = g_sfera_directplay_runtime.peer;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&g_sfera_network_runtime.directplay_caps);
    *(uint32_t*)((uintptr_t)&g_sfera_network_runtime.directplay_caps.words[7]) = 4u;
    *(uint32_t*)((uintptr_t)&g_sfera_network_runtime.directplay_caps.words[8]) = 0x10000u;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x48u);
    lift_push32(cpu, (uintptr_t)&kDirectPlay8TcpIpProvider); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x337D3u), LIFT_CODE_TOKEN_RVA(0x337D1u))) { return; }
    label_000337D3:
    cpu->ecx = cpu->edi;
    g_sfera_network_runtime.initialization_result = (uint32_t)(cpu->ebx);
    g_sfera_network_runtime.timeout_marker_pending = (uint8_t)((cpu->ebx & 0xFFu));
    g_sfera_network_runtime.error_budget = (uint32_t)(cpu->ebx);
    g_sfera_network_runtime.network_error_active = (uint8_t)((cpu->ebx & 0xFFu));
    g_sfera_network_runtime.net_log_has_error = (uint8_t)((cpu->ebx & 0xFFu));
    g_sfera_network_runtime.initialized = (uint8_t)(1u);
    g_sfera_directplay_runtime.transport.transport_flag = (uint8_t)((cpu->ebx & 0xFFu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433805u)); sfera_sub_00480090(cpu, LIFT_CODE_TOKEN_VA(0x433805u));
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00033819;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433812u)); sfera_sub_004801E0(cpu, LIFT_CODE_TOKEN_VA(0x433812u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x33819u)); sfera_sub_00480280(cpu, LIFT_CODE_TOKEN_RVA(0x33819u));
    label_00033819:
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled)) != (uint8_t)(1u)) goto label_00033926;
    cpu->eax = g_sfera_network_runtime.server_port;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Try init TCP-IP manager (%d '%s')\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43383Cu)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x43383Cu));
    cpu->esp += 0x10u;
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_24)) == (uint32_t)(cpu->ebx)) goto label_00033870;
    cpu->edx = 0x32Du;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\INet.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433856u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x433856u));
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_24;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00033870;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433867u)); sfera_sub_00418D50(cpu, LIFT_CODE_TOKEN_VA(0x433867u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43386Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x43386Du));
    cpu->esp += 4u;
    label_00033870:
    cpu->edx = 0x32Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\INet.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43387Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x43387Fu));
    lift_push32(cpu, 0xEABCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433889u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x433889u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x204u) = cpu->ebx;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000338A4;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4338A2u)); sfera_sub_004188A0(cpu, LIFT_CODE_TOKEN_VA(0x4338A2u));
    goto label_000338A6;
    label_000338A4:
    cpu->eax = 0u;
    label_000338A6:
    cpu->esi |= 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x204u) = cpu->esi;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_24) = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00033926;
    cpu->ecx = g_sfera_network_runtime.server_port;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4338C8u)); sfera_sub_004193E0(cpu, LIFT_CODE_TOKEN_VA(0x4338C8u));
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0003390E;
    cpu->edx = g_sfera_network_runtime.server_port;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager (%d '%s') = ERROR\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4338E3u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x4338E3u));
    cpu->esp += 0x10u;
    g_sfera_network_runtime.initialization_result = (uint32_t)(cpu->esi);
    label_000338EC:
    cpu->ecx = (uint32_t)(uintptr_t)"Network initialize error! ";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4338F6u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4338F6u));
    cpu->ecx = (uint32_t)(uintptr_t)"\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433900u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x433900u));
    cpu->ecx = (uint32_t)(uintptr_t)"\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43390Au)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x43390Au));
    cpu->eax = 0u;
    goto label_0003392B;
    label_0003390E:
    cpu->eax = g_sfera_network_runtime.server_port;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager (%d '%s') = OK\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433923u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x433923u));
    cpu->esp += 0x10u;
    label_00033926:
    cpu->eax = 1u;
    label_0003392B:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1FCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1F8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433960(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::DeleteCriticalSection);
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00033A32;
    if ((uint32_t)(g_sfera_directplay_runtime.peer) == (uint32_t)(cpu->ebx)) goto label_00033A73;
    if ((uint8_t)(g_sfera_network_runtime.timeout_marker_pending) != (uint8_t)(1u)) goto label_0003399D;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    cpu->ecx = (uint32_t)(uintptr_t)"-- T\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433997u)); sfera_sub_0047FED0(cpu, LIFT_CODE_TOKEN_VA(0x433997u));
    g_sfera_network_runtime.timeout_marker_pending = (uint8_t)((cpu->ebx & 0xFFu));
    label_0003399D:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    cpu->ecx = (uint32_t)(uintptr_t)"Release\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4339A9u)); sfera_sub_0047FED0(cpu, LIFT_CODE_TOKEN_VA(0x4339A9u));
    { uint64_t l=(uint64_t)(g_sfera_network_runtime.net_log_has_error), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4339B8u)); sfera_sub_00480110(cpu, LIFT_CODE_TOKEN_VA(0x4339B8u));
    g_sfera_network_runtime.initialized = (uint8_t)((cpu->ebx & 0xFFu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4339C3u)); sfera_sub_00480300(cpu, LIFT_CODE_TOKEN_VA(0x4339C3u));
    cpu->eax = g_sfera_directplay_runtime.peer;
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)((uintptr_t)&g_sfera_directplay_runtime.caps.connect_timeout_ms) = 0x32u;
    *(uint32_t*)((uintptr_t)&g_sfera_directplay_runtime.caps.connect_retries) = 1u;
    *(uint32_t*)((uintptr_t)&g_sfera_directplay_runtime.caps.timeout_until_keepalive_ms) = 0x3E8u;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x44u);
    lift_push32(cpu, (uintptr_t)&g_sfera_directplay_runtime.caps); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x339F4u), LIFT_CODE_TOKEN_RVA(0x339F2u))) { return; }
    cpu->eax = g_sfera_directplay_runtime.peer;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x38u);
    if ((uint8_t)(g_sfera_directplay_runtime.transport.transport_flag) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00033A0A;
    lift_push32(cpu, 1u);
    goto label_00033A0B;
    label_00033A0A:
    lift_push32(cpu, cpu->ebx);
    label_00033A0B:
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x33A0Eu), LIFT_CODE_TOKEN_RVA(0x33A0Cu))) { return; }
    cpu->eax = g_sfera_directplay_runtime.peer;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x33A1Bu), LIFT_CODE_TOKEN_RVA(0x33A19u))) { return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_directplay_runtime.critical_section[0]);
    g_sfera_directplay_runtime.peer = (uint32_t)(cpu->ebx);
    g_sfera_network_runtime.initialization_result = (uint32_t)(0xFFFFFFFFu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x33A32u), LIFT_CODE_TOKEN_RVA(0x33A30u))) { return; }
    label_00033A32:
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled)) != (uint8_t)(1u)) goto label_00033A73;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_24;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00033A73;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433A4Au)); sfera_sub_00418A20(cpu, LIFT_CODE_TOKEN_VA(0x433A4Au));
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_directplay_runtime.critical_section[0]);
    g_sfera_network_runtime.initialized = (uint8_t)((cpu->ebx & 0xFFu));
    g_sfera_network_runtime.initialization_result = (uint32_t)(0xFFFFFFFFu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x33A61u), LIFT_CODE_TOKEN_RVA(0x33A5Fu))) { return; }
    lift_push32(cpu, (uintptr_t)"Deinit TCP-IP manager = OK\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433A70u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x433A70u));
    cpu->esp += 8u;
    label_00033A73:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433A80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x84u;
    if ((uint8_t)(g_sfera_directplay_runtime.transport.receive_corrupted) == (uint8_t)(0u)) goto label_00033AC9;
    lift_push32(cpu, (uint32_t)(uintptr_t)"receive_netdata");
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, (uintptr_t)"%s(): DATA CORRUPTION\n"); lift_push32(cpu, cpu->eax);
    g_sfera_directplay_runtime.transport.receive_corrupted = (uint8_t)(0u);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x433AB3u));
    cpu->esp += 0xCu;
    cpu->edx = (uint32_t)(cpu->esp);
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\directplay";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x33AC9u)); sfera_sub_00434660(cpu, LIFT_CODE_TOKEN_RVA(0x33AC9u));
    label_00033AC9:
    if ((uint32_t)(g_sfera_network_runtime.initialization_result) != (uint32_t)(1u)) goto label_00033B72;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::EnterCriticalSection);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_directplay_runtime.critical_section[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x33AE5u), LIFT_CODE_TOKEN_RVA(0x33AE3u))) { return; }
    cpu->eax = g_sfera_directplay_runtime.transport.receive_read_index;
    cpu->ebp = native_function_address32(&::LeaveCriticalSection);
    if ((uint32_t)(cpu->eax) == (uint32_t)(g_sfera_directplay_runtime.transport.receive_write_index)) goto label_00033B62;
    lift_push32(cpu, cpu->esi);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00033B00:
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1A8u);
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_network_runtime.message_slots[0]);
    { uint64_t l=(uint64_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = cpu->eax;
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00033B1F;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433B1Du)); sfera_sub_00432970(cpu, LIFT_CODE_TOKEN_VA(0x433B1Du));
    goto label_00033B24;
    label_00033B1F:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x33B24u)); sfera_sub_00431C20(cpu, LIFT_CODE_TOKEN_RVA(0x33B24u));
    label_00033B24:
    cpu->eax = g_sfera_directplay_runtime.transport.receive_read_index;
    ++cpu->eax;
    *(uint32_t*)(cpu->esi) = 0u;
    g_sfera_directplay_runtime.transport.receive_read_index = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xBE8u)) goto label_00033B46;
    g_sfera_directplay_runtime.transport.receive_read_index = (uint32_t)(0u);
    label_00033B46:
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_directplay_runtime.critical_section[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x33B4Du), LIFT_CODE_TOKEN_RVA(0x33B4Bu))) { return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_directplay_runtime.critical_section[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x33B54u), LIFT_CODE_TOKEN_RVA(0x33B52u))) { return; }
    cpu->eax = g_sfera_directplay_runtime.transport.receive_read_index;
    if ((uint32_t)(cpu->eax) != (uint32_t)(g_sfera_directplay_runtime.transport.receive_write_index)) goto label_00033B00;
    cpu->esi = lift_pop32(cpu);
    label_00033B62:
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_directplay_runtime.critical_section[0]);
    g_sfera_directplay_runtime.transport.receive_busy = (uint8_t)(0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x33B70u), LIFT_CODE_TOKEN_RVA(0x33B6Eu))) { return; }
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_00033B72:
    cpu->esp += 0x84u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433B90(LiftCpu* cpu, uint32_t stop_address) {
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0x10u)) goto label_00033B9C;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00033B9C;
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00033B9C:
    cpu->eax = 1u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433BB0(LiftCpu* cpu, uint32_t stop_address) {
    if ((uint32_t)(cpu->ecx) != 0u) goto label_00033BBA;
    cpu->eax = 1u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00033BBA:
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)(0xFu), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->eax) * 8u) + 4u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433BD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x96u); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x433BE1u));
    cpu->esp += 0xCu;
    *(uint8_t*)(cpu->esi + 0x99u) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433C00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    cpu->ecx = g_sfera_mbc_runtime->registered_object_count;
    *(uint32_t*)(cpu->esp + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_02;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    lift_push32(cpu, 0x14u);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433C4Fu)); sfera_sub_004311F0(cpu, LIFT_CODE_TOKEN_VA(0x433C4Fu));
    if ((uint32_t)(cpu->eax) == 0u) goto label_00033C65;
    cpu->eax = g_sfera_mbc_runtime->registered_object_count;
    g_sfera_mbc_runtime->registered_objects[cpu->eax] = (uint32_t)(cpu->esi);
    ++cpu->eax;
    g_sfera_mbc_runtime->registered_object_count = (uint32_t)(cpu->eax);
    label_00033C65:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433C80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0xCu);
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    lift_push32(cpu, 0x14u);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_02;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433CC0u)); sfera_sub_00430F40(cpu, LIFT_CODE_TOKEN_VA(0x433CC0u));
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_00033CD6;
    cpu->eax = 0u;
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00033CD6:
    cpu->eax = g_sfera_mbc_runtime->registered_objects[cpu->eax];
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433CF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(2u) & 0xFFu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (*(uint8_t*)(cpu->esi + 0xB9u) == (uint8_t)((cpu->eax & 0xFFu))) goto label_00033D8E;
    if ((int32_t)(uint32_t)(cpu->edi) < 0) goto label_00033D8E;
    ++g_sfera_mbc_runtime->execution_chain_count;
    *(uint8_t*)(cpu->esi + 0xB9u) = cpu->eax & 0xFFu;
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->execution_chain_tail) >= (int32_t)(uint32_t)(0u)) goto label_00033D52;
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->execution_chain_head) < (int32_t)(uint32_t)(0u)) goto label_00033D34;
    cpu->ecx = (uint32_t)(uintptr_t)"internal error 34096874309";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x33D34u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_RVA(0x33D34u));
    label_00033D34:
    g_sfera_mbc_runtime->execution_chain_tail = (uint32_t)(cpu->edi);
    g_sfera_mbc_runtime->execution_chain_head = (uint32_t)(cpu->edi);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0xCCu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xC8u) = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00033D52:
    cpu->eax = g_sfera_mbc_runtime->execution_chain_head;
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00033D6A;
    cpu->ecx = (uint32_t)(uintptr_t)"internal error 04975350934760";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433D65u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x433D65u));
    cpu->eax = g_sfera_mbc_runtime->execution_chain_head;
    label_00033D6A:
    cpu->ecx = cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x348u);
    *(uint32_t*)(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].execution_prev_index)) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0xCCu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xC8u) = 0xFFFFFFFFu;
    g_sfera_mbc_runtime->execution_chain_head = (uint32_t)(cpu->edi);
    label_00033D8E:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433DA0(LiftCpu* cpu, uint32_t stop_address) {
    if (*(uint8_t*)(cpu->edx + 0xB9u) == (uint8_t)(0u)) goto label_00033E0A;
    --g_sfera_mbc_runtime->execution_chain_count;
    cpu->eax = *(uint32_t*)(cpu->edx + 0xCCu);
    *(uint8_t*)(cpu->edx + 0xB9u) = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00033DD5;
    cpu->ecx = *(uint32_t*)(cpu->edx + 0xC8u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].execution_prev_index)) = cpu->ecx;
    goto label_00033DE0;
    label_00033DD5:
    cpu->eax = *(uint32_t*)(cpu->edx + 0xC8u);
    g_sfera_mbc_runtime->execution_chain_tail = (uint32_t)(cpu->eax);
    label_00033DE0:
    cpu->eax = *(uint32_t*)(cpu->edx + 0xC8u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00033DFE;
    cpu->ecx = *(uint32_t*)(cpu->edx + 0xCCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].execution_next_index)) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00033DFE:
    cpu->edx = *(uint32_t*)(cpu->edx + 0xCCu);
    g_sfera_mbc_runtime->execution_chain_head = (uint32_t)(cpu->edx);
    label_00033E0A:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_inter_scalar_runtime.mode_01;
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(0x16u), 32u);
    { int64_t v=(int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x16Du); cpu->edx= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 18u;
    cpu->ecx &= 0xFu;
    cpu->ecx = sfera_calendar_days_before_month(cpu->ecx);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = cpu->eax;
    cpu->edx >>= 13u;
    cpu->edx &= 0x1Fu;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = cpu->eax;
    cpu->edx >>= 8u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x1Fu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ecx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 8u));
    cpu->edx = cpu->ecx;
    cpu->edx <<= 4u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 2u;
    cpu->ecx &= 0x3Fu;
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 4u));
    cpu->eax &= 3u;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433E70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x433E7Cu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esp += 4u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x900FAE80u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = (uint64_t)(cpu->ecx) + (uint64_t)(4u) + (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_double_shift_left(cpu, cpu->ecx, cpu->eax, (uint32_t)(1u), 32u);
    cpu->edx = cpu->eax;
    cpu->eax += cpu->eax;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ecx), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->esi = lift_double_shift_left(cpu, cpu->esi, cpu->edx, (uint32_t)(4u), 32u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x3Cu);
    cpu->edx <<= 4u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433EB5u)); sfera_sub_004EEA40(cpu, LIFT_CODE_TOKEN_VA(0x433EB5u));
    lift_push32(cpu, 0u); lift_push32(cpu, 0x201480u);
    cpu->ebx = cpu->edx;
    cpu->edi = cpu->eax;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433EC7u)); sfera_sub_004EEA40(cpu, LIFT_CODE_TOKEN_VA(0x433EC7u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0xFFDFEB80u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433EDBu)); sfera_sub_004EED20(cpu, LIFT_CODE_TOKEN_VA(0x433EDBu));
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->eax = g_sfera_inter_scalar_runtime.mode_01;
    cpu->ebx = (uint64_t)(cpu->ebx) + (uint64_t)(cpu->edx) + (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1680u);
    cpu->esi += 0x188u;
    lift_push32(cpu, cpu->ebx);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x3FFFFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->esi <<= 22u;
    lift_push32(cpu, cpu->edi);
    cpu->esi ^= cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433F02u)); sfera_sub_004EEA40(cpu, LIFT_CODE_TOKEN_VA(0x433F02u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0xFFFFE980u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ebp = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433F16u)); sfera_sub_004EED20(cpu, LIFT_CODE_TOKEN_VA(0x433F16u));
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->ebx = (uint64_t)(cpu->ebx) + (uint64_t)(cpu->edx) + (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->esi &= 0xFFC43FFFu;
    cpu->esi |= 0x42000u;
    cpu->eax = 1u;
    label_00033F30:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00033F56;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00033F45;
    { uint64_t l=(uint64_t)(sfera_calendar_days_before_month(cpu->eax + 1u)), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_00033F56;
    label_00033F45:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00033F5E;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00033F56;
    { uint64_t l=(uint64_t)(sfera_calendar_days_before_month(cpu->eax)), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_00033F5E;
    label_00033F56:
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xDu)) goto label_00033F30;
    goto label_00033F7F;
    label_00033F5E:
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(sfera_calendar_days_before_month(cpu->eax)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebp = v; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    { uint64_t l=(uint64_t)(cpu->ebp), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    cpu->ebp = (uint32_t)((uint32_t)(cpu->ebp) << 13u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(0x3E000u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    cpu->eax <<= 18u;
    cpu->ebp |= cpu->eax;
    cpu->esi &= 0xFFC01FFFu;
    cpu->esi |= cpu->ebp;
    label_00033F7F:
    lift_push32(cpu, 0u); lift_push32(cpu, 0xF0u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433F8Du)); sfera_sub_004EEA40(cpu, LIFT_CODE_TOKEN_VA(0x433F8Du));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0xFFFFFF10u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ebp = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433FA1u)); sfera_sub_004EED20(cpu, LIFT_CODE_TOKEN_VA(0x433FA1u));
    lift_push32(cpu, 0u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    lift_push32(cpu, 4u);
    cpu->ebx = (uint64_t)(cpu->ebx) + (uint64_t)(cpu->edx) + (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433FB0u)); sfera_sub_004EEA40(cpu, LIFT_CODE_TOKEN_VA(0x433FB0u));
    cpu->eax &= 0x3Fu;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(0x1Fu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    lift_push32(cpu, 0u);
    cpu->ebp = (uint32_t)((uint32_t)(cpu->ebp) << 6u);
    cpu->eax |= cpu->ebp;
    lift_push32(cpu, 4u);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->ebx);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x433FCEu)); sfera_sub_004EEC60(cpu, LIFT_CODE_TOKEN_VA(0x433FCEu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax &= 3u;
    cpu->esi &= 0xFFFFE000u;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx |= cpu->eax;
    cpu->ecx |= cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    g_sfera_inter_scalar_runtime.mode_01 = (uint32_t)(cpu->ecx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433FF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->eax = cpu->edi;
    cpu->esi = cpu->ecx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00034000:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00034000;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00034067;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_00034067;
    cpu->eax = (uint32_t)(cpu->ebx + 0xFFFFFFFFu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43401Cu));
    cpu->esp += 0xCu;
    *(uint8_t*)(cpu->esi + cpu->ebx + 0xFFFFFFFFu) = 0u;
    if ((int32_t)(uint32_t)(g_sfera_network_runtime.active_slot) < (int32_t)(uint32_t)(0u)) goto label_0003405F;
    cpu->eax = cpu->edi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00034037:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00034037;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"MBINTER MESSAGE: Wrong string to copy: '%s', strlen: %d\n"); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x43404Cu));
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3405Fu)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_RVA(0x3405Fu));
    label_0003405F:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00034067:
    cpu->ecx = cpu->edi;
    cpu->esi -= cpu->edi;
    label_00034070:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->ecx)) & 0xFFu);
    *(uint8_t*)(cpu->esi + cpu->ecx) = cpu->edx & 0xFFu;
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00034070;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434080(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->edi)) & 0xFFu);
    cpu->esi = cpu->ecx;
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000340AB;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00034090:
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Au)) goto label_000340B5;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)((cpu->eax & 0xFFu))) goto label_000340A2;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x3Fu)) goto label_000340CD;
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_000340CD;
    label_000340A2:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    ++cpu->esi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00034090;
    label_000340AB:
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(*(uint8_t*)(cpu->esi)), r=(uint64_t)((cpu->eax & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    label_000340B2:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000340B5:
    cpu->edx = (uint32_t)(cpu->edi + 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4340BFu)); sfera_sub_00434080(cpu, LIFT_CODE_TOKEN_VA(0x4340BFu));
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000340B2;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->esi)) & 0xFFu);
    ++cpu->esi;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000340B5;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000340CD:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004340E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    lift_push32(cpu, 0x2Eu); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->ecx;
    lift_native_call(cpu, native_strrchr_address32(), LIFT_CODE_TOKEN_VA(0x4340FBu));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) != 0u) goto label_0003411C;
    cpu->eax = cpu->edi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_00034110:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00034110;
    cpu->eax -= cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + cpu->edi);
    label_0003411C:
    cpu->eax = cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00034121:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00034121;
    cpu->eax -= cpu->edx;
    cpu->ebx = (uint32_t)(cpu->eax + 1u);
    cpu->eax = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x434134u)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x434134u));
    cpu->eax = cpu->esp;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43413Cu));
    cpu->esp += 0xCu;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetLocalTime), LIFT_CODE_TOKEN_VA(0x434148u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    cpu->edx = *(uint16_t*)(cpu->ebp + 0xFFFFFFF2u);
    cpu->eax = *(uint16_t*)(cpu->ebp + 0xFFFFFFEEu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint16_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx -= 0x7D0u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->esi -= cpu->edi;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"%.*s_%02d.%02d.%02d%s"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x434174u));
    cpu->esp += 0x20u;
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004341A0(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000341B7;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_000341B7:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\script.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4341BDu));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000341E8;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    g_sfera_log_first_write = (uint32_t)(0u);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x4341D8u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4341DFu));
    cpu->esp += 0xCu;
    label_000341E8:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434240(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034253;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_00034253:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\script.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x43425Au));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00034293;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    cpu->esp -= 8u;
    *(double*)(cpu->esp) = cpu->fpu[0u];
    lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)"%f"); lift_push32(cpu, cpu->esi);
    g_sfera_log_first_write = (uint32_t)(0u);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x434283u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x43428Au));
    cpu->esp += 0x14u;
    label_00034293:
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004342A0(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000342B7;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_000342B7:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\deletings.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4342BDu));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000342DE;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x4342CEu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4342D5u));
    cpu->esp += 0xCu;
    label_000342DE:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434340(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034353;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_00034353:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\deletings.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x43435Au));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00034389;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    cpu->esp -= 8u;
    *(double*)(cpu->esp) = cpu->fpu[0u];
    lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)"%f"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x434379u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x434380u));
    cpu->esp += 0x14u;
    label_00034389:
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434390(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000343A7;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_000343A7:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\gm.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4343ADu));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000343CE;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x4343BEu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4343C5u));
    cpu->esp += 0xCu;
    label_000343CE:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434430(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034443;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_00034443:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\gm.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x43444Au));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00034479;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    cpu->esp -= 8u;
    *(double*)(cpu->esp) = cpu->fpu[0u];
    lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)"%f"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x434469u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x434470u));
    cpu->esp += 0x14u;
    label_00034479:
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434480(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034497;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_00034497:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\trade.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x43449Du));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000344BE;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x4344AEu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4344B5u));
    cpu->esp += 0xCu;
    label_000344BE:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434520(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034533;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_00034533:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\trade.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x43453Au));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00034569;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    cpu->esp -= 8u;
    *(double*)(cpu->esp) = cpu->fpu[0u];
    lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)"%f"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x434559u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x434560u));
    cpu->esp += 0x14u;
    label_00034569:
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434610(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034623;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_00034623:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\violations.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x43462Au));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00034659;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    cpu->esp -= 8u;
    *(double*)(cpu->esp) = cpu->fpu[0u];
    lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)"%f"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x434649u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x434650u));
    cpu->esp += 0x14u;
    label_00034659:
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434660(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034677;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_00034677:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x434679u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0003469A;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x43468Au));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x434691u));
    cpu->esp += 0xCu;
    label_0003469A:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004346F0(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034703;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_00034703:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x434706u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00034735;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    cpu->esp -= 8u;
    *(double*)(cpu->esp) = cpu->fpu[0u];
    lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)"%f"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x434725u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x43472Cu));
    cpu->esp += 0x14u;
    label_00034735:
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434740(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xA0u;
    cpu->eax = *(uint32_t*)((uintptr_t)"logs\\tmp_cl");
    cpu->edx = *(uint32_t*)(((uint32_t)(uintptr_t)"logs\\tmp_cl") + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(((uint32_t)(uintptr_t)"logs\\tmp_cl") + 4u);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x34u) = 0u;
    lift_native_call(cpu, native_function_address32(&::GetLocalTime), LIFT_CODE_TOKEN_VA(0x434783u));
    cpu->ecx = *(uint16_t*)(cpu->esp + 0x1Au);
    cpu->edx = *(uint16_t*)(cpu->esp + 0x16u);
    cpu->eax = *(uint16_t*)(cpu->esp + 0x14u);
    cpu->edi = native_function_address32(&::sprintf);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->eax -= 0x7D0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, (uintptr_t)"%s_%02d%02d%02d.log"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x347B7u), LIFT_CODE_TOKEN_RVA(0x347B5u))) { return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x5Cu);
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4347C1u));
    cpu->esi = cpu->eax;
    cpu->esp += 0x20u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00034819;
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4347D5u));
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4347E0u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, (uintptr_t)"%02i:%02i:%02i "); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x347FDu), LIFT_CODE_TOKEN_RVA(0x347FBu))) { return; }
    cpu->edi = native_function_address32(&::fputs);
    cpu->edx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x3480Bu), LIFT_CODE_TOKEN_RVA(0x34809u))) { return; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x3480Fu), LIFT_CODE_TOKEN_RVA(0x3480Du))) { return; }
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x434810u));
    cpu->esp += 0x30u;
    label_00034819:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xA0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434840(LiftCpu* cpu, uint32_t stop_address) {
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    label_00034842:
    cpu->eax = cpu->ecx;
    cpu->eax >>= 1u;
    if ((uint8_t)(((cpu->ecx & 0xFFu)) & (1u)) == 0u) goto label_00034850;
    cpu->eax ^= 0xEDB88320u;
    label_00034850:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003485D;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0003485F;
    label_0003485D:
    cpu->eax >>= 1u;
    label_0003485F:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003486C;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0003486E;
    label_0003486C:
    cpu->eax >>= 1u;
    label_0003486E:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003487B;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0003487D;
    label_0003487B:
    cpu->eax >>= 1u;
    label_0003487D:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003488A;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0003488C;
    label_0003488A:
    cpu->eax >>= 1u;
    label_0003488C:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00034899;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0003489B;
    label_00034899:
    cpu->eax >>= 1u;
    label_0003489B:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000348A8;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_000348AA;
    label_000348A8:
    cpu->eax >>= 1u;
    label_000348AA:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000348B7;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_000348B9;
    label_000348B7:
    cpu->eax >>= 1u;
    label_000348B9:
    *(uint32_t*)(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_crc32_table[0])) = cpu->eax;
    ++cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00034842;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004348D0(LiftCpu* cpu, uint32_t stop_address) {
    if ((uint32_t)(cpu->edx) == 0u) goto label_000348FF;
    cpu->eax = g_sfera_mbc_runtime->file_crc32;
    lift_push32(cpu, cpu->esi);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000348E0:
    cpu->esi = (int8_t)(*(uint8_t*)(cpu->ecx));
    cpu->esi ^= cpu->eax;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    cpu->eax >>= 8u;
    cpu->eax ^= *(uint32_t*)(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_crc32_table[0]));
    ++cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    g_sfera_mbc_runtime->file_crc32 = (uint32_t)(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000348E0;
    cpu->esi = lift_pop32(cpu);
    label_000348FF:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434900(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = g_sfera_mbc_runtime->execution_context_depth;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00034995;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::sprintf);
    lift_push32(cpu, cpu->esi);
    label_00034925:
    cpu->eax = cpu->edi;
    --cpu->ebx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->edi = cpu->edi;
    label_00034930:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00034930;
    cpu->eax -= cpu->edx;
    cpu->ecx = (uint32_t)(cpu->eax + cpu->edi);
    cpu->eax = g_sfera_mbc_runtime->execution_context_stack[cpu->ebx].process_index;
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00034950;
    lift_push32(cpu, (uintptr_t)"\nCall from C++\n"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x3494Bu), LIFT_CODE_TOKEN_RVA(0x34949u))) { return; }
    cpu->esp += 8u;
    goto label_0003497F;
    label_00034950:
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    cpu->edx = *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id));
    if ((uint32_t)(cpu->edx) != (uint32_t)(g_sfera_mbc_runtime->execution_context_stack[cpu->ebx].process_id)) goto label_00034988;
    cpu->edx = g_sfera_mbc_runtime->execution_context_stack[cpu->ebx].program_index;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xA4u);
    cpu->edx += g_sfera_mbc_runtime->execution_context_stack[cpu->ebx].program_table_base;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].name[0]));
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"\nPrevious prc: %s\nProgram: %s\n"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x3497Cu), LIFT_CODE_TOKEN_RVA(0x3497Au))) { return; }
    cpu->esp += 0x10u;
    label_0003497F:
    if ((int32_t)(uint32_t)(cpu->ebx) > 0) goto label_00034925;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00034988:
    lift_push32(cpu, (uintptr_t)"\nError in prc call stack\n"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x34990u), LIFT_CODE_TOKEN_RVA(0x3498Eu))) { return; }
    cpu->esp += 8u;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_00034995:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004349A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    cpu->eax = 0x7FFFu;
    *(uint16_t*)(cpu->ecx) = cpu->eax & 0xFFFFu;
    *(uint32_t*)(cpu->esp + 8u) = cpu->edx;
    *(uint32_t*)(cpu->edx) = 0u;
    cpu->edx = g_sfera_mbc_runtime->process_index;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 4u) = cpu->ebp;
    if ((uint32_t)(cpu->edx) > (uint32_t)(0xFFFFu)) goto label_00034ADF;
    cpu->eax = cpu->edx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    cpu->ecx = *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].bytecode_base));
    if ((uint32_t)(g_sfera_mbc_runtime->bytecode_base) == (uint32_t)(cpu->ecx)) goto label_000349F1;
    cpu->ebp = 0x80u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->ebp;
    label_000349F1:
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->current_instruction_address;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi -= cpu->ecx;
    if ((uint32_t)(cpu->edi) == 0u) goto label_00034A39;
    cpu->eax = *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].bytecode_size));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax -= cpu->esi;
    if ((int32_t)(uint32_t)(cpu->eax) > 0) goto label_00034A1B;
    *(uint32_t*)(cpu->ecx) = 0u;
    goto label_00034A33;
    label_00034A1B:
    if ((int32_t)*(uint32_t*)(cpu->ecx) <= (int32_t)(uint32_t)(cpu->eax)) goto label_00034A21;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    label_00034A21:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->current_instruction_address;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x434A2Bu));
    cpu->esp += 0xCu;
    label_00034A33:
    cpu->edx = g_sfera_mbc_runtime->process_index;
    label_00034A39:
    cpu->ecx = cpu->edx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x348u);
    cpu->edi = *(uint16_t*)(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].code_range_count));
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (int16_t)((cpu->edi & 0xFFFFu));
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edi;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00034A7F;
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].code_range_begin[0]));
    cpu->esp = (uint32_t)(cpu->esp);
    label_00034A60:
    cpu->edi = *(uint32_t*)(cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->edi)) goto label_00034A6F;
    cpu->ebp = *(uint32_t*)(cpu->ecx + 0x20u);
    cpu->ebp += cpu->edi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->ebp)) goto label_00034A92;
    label_00034A6F:
    ++cpu->eax;
    cpu->ecx += 4u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ebx)) goto label_00034A60;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x24u);
    label_00034A7F:
    if ((uint16_t)((cpu->edi & 0xFFFFu)) != (uint16_t)(8u)) goto label_00034AD2;
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (uint32_t)(cpu->ebp + 2u);
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00034A92:
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1A4u);
    cpu->edx += cpu->eax;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(*(uint16_t*)(((uint32_t)(cpu->edx) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].code_range_ids[0]))) & 0xFFFFu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint16_t*)(cpu->edx) = cpu->ecx & 0xFFFFu;
    cpu->ecx = g_sfera_mbc_runtime->process_index;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xD2u);
    cpu->ecx += cpu->eax;
    cpu->esi -= *(uint32_t*)(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].code_range_begin[0]));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->edx) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00034AD2:
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (uint32_t)(cpu->ebp + 3u);
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00034ADF:
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434AF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xB4u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00034B33;
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x434B0Fu));
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    cpu->esp += 4u;
    --cpu->edi;
    cpu->edi = cpu->edi;
    label_00034B20:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00034B20;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x0020)) & 0xFFFFu);
    *(uint16_t*)(cpu->edi) = cpu->eax & 0xFFFFu;
    goto label_00034B3A;
    label_00034B33:
    g_sfera_mbc_runtime->diagnostic_context[0] = (uint8_t)(0u);
    label_00034B3A:
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x14u) = 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x434B59u)); sfera_sub_004349A0(cpu, LIFT_CODE_TOKEN_VA(0x434B59u));
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 7u;
    cpu->ecx &= 1u;
    cpu->eax &= 0xFFFFFF7Fu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00034BA3;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    --cpu->edi;
    label_00034B75:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00034B75;
    cpu->ecx = 9u;
    cpu->esi = (uint32_t)(uintptr_t)"PrcName,CodeOffs: unknown. (wrong pos)";
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    lift_movs8(cpu, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xB4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00034BA3:
    if ((uint32_t)(cpu->eax) != (uint32_t)(2u)) goto label_00034BDD;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    --cpu->edi;
    cpu->edi = cpu->edi;
    label_00034BB0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00034BB0;
    cpu->ecx = 0xFu;
    cpu->esi = (uint32_t)(uintptr_t)"PrcName,CodeOffs: unknown. (modulesNum == MAX_MODULES_IN_PRC)";
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xB4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00034BDD:
    if ((uint32_t)(cpu->eax) != (uint32_t)(3u)) goto label_00034C15;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    --cpu->edi;
    label_00034BE8:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00034BE8;
    cpu->ecx = 0xBu;
    cpu->esi = (uint32_t)(uintptr_t)"PrcName,CodeOffs: unknown. (Offset not found)";
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xB4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00034C15:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = 0u;
    *(uint8_t*)(cpu->esp + 0x40u) = 0u;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00034C74;
    label_00034C26:
    cpu->eax = *(uint8_t*)(cpu->esp + cpu->ebp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, (uintptr_t)"%x "); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x434C36u));
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    cpu->esp += 0xCu;
    cpu->ecx = cpu->eax;
    label_00034C45:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00034C45;
    cpu->edi = (uint32_t)(cpu->esp + 0x40u);
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00034C55:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034C55;
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 2u;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    ++cpu->ebp;
    lift_movs8(cpu, 1u);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(cpu->ebx)) goto label_00034C26;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_00034C74:
    cpu->edi = (uint32_t)(cpu->esp + 0x40u);
    cpu->ebp = lift_pop32(cpu);
    --cpu->edi;
    cpu->ebx = lift_pop32(cpu);
    label_00034C80:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00034C80;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x000A)) & 0xFFFFu);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    *(uint16_t*)(cpu->edi) = cpu->edx & 0xFFFFu;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00034CE0;
    cpu->edi = cpu->edi;
    label_00034CA0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00034CA0;
    cpu->ecx = g_sfera_mbc_runtime->process_index;
    cpu->eax -= cpu->edx;
    cpu->edx = cpu->ecx;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    cpu->edx = *(uint32_t*)(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].bytecode_base));
    lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->bytecode_base;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]));
    lift_push32(cpu, (uintptr_t)"Warn!!! pos = %d, sBaseCodePtr = %d, Prc[pos].baseCodePtr = %d. "); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x434CD2u));
    cpu->esp += 0x14u;
    goto label_00034D09;
    label_00034CE0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00034CE0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax -= cpu->edx;
    cpu->edx = *(uint16_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]));
    lift_push32(cpu, (uintptr_t)"module:%d, code:%d. "); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x434D00u));
    cpu->esp += 0x10u;
    label_00034D09:
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    cpu->ecx = cpu->eax;
    (void)cpu;
    label_00034D10:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00034D10;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00034D21:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034D21;
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 2u;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xB4u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434D50(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=(uint64_t)(g_sfera_network_runtime.active_slot), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00034D81;
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x434D66u)); sfera_sub_00434AF0(cpu, LIFT_CODE_TOKEN_VA(0x434D66u));
    cpu->eax = g_sfera_diagnostic_log_byte;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x434D7Au)); sfera_sub_004ED410(cpu, LIFT_CODE_TOKEN_VA(0x434D7Au));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x34D81u)); sfera_sub_004ED380(cpu, LIFT_CODE_TOKEN_RVA(0x34D81u));
    label_00034D81:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434D90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x404u;
    if ((int32_t)(uint32_t)(g_sfera_network_runtime.active_slot) >= (int32_t)(uint32_t)(0u)) goto label_00034DC4;
    cpu->eax = 0u;
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00034DC4:
    cpu->ecx = 1u;
    g_sfera_mbc_runtime->diagnostic_context[0] = (uint8_t)(0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x434DD5u)); sfera_sub_00434AF0(cpu, LIFT_CODE_TOKEN_VA(0x434DD5u));
    cpu->eax = g_sfera_mbc_runtime->program_index;
    cpu->edx = g_sfera_mbc_runtime->current_instruction_address;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    cpu->edx -= g_sfera_mbc_runtime->bytecode_base;
    cpu->eax += g_sfera_mbc_runtime->program_table_base;
    cpu->edx += 0x20u;
    cpu->ecx = *(uint8_t*)(cpu->eax + 0x84u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->process_index;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->edx += ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].name[0]);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"MBC-file: %s\nProgram: %s\nCall's depth: %d\nAddress: 0x%08X\n"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x434E1Cu));
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    cpu->esp += 0x18u;
    cpu->ecx = cpu->eax;
    label_00034E30:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00034E30;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00034E43:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034E43;
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 2u;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x434E63u)); sfera_sub_00434900(cpu, LIFT_CODE_TOKEN_VA(0x434E63u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434E80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = 1u;
    cpu->edi = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x434E90u)); sfera_sub_00434AF0(cpu, LIFT_CODE_TOKEN_VA(0x434E90u));
    if ((uint32_t)(cpu->edi) != 0u) goto label_00034EB9;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x434EB4u)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x434EB4u));
    cpu->esp += 0x18u;
    goto label_00034EE0;
    label_00034EB9:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    ++cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->edi);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, ptr+offset = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x434EDDu)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x434EDDu));
    cpu->esp += 0x1Cu;
    label_00034EE0:
    cpu->eax = *(uint32_t*)(cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00034F0C;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00034F0C;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00034EF8;
    if ((uint32_t)(cpu->eax) <= *(uint32_t*)(cpu->esi + 8u)) goto label_00034F0C;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_00034EF8:
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_00034F00;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00034F00:
    cpu->eax = (uint32_t)(cpu->eax + cpu->edi + 0xFFFFFFFFu);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)*(uint32_t*)(cpu->esi + 8u)) goto label_00034F0C;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    label_00034F0C:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434F10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = g_sfera_mbc_runtime->active_process;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = g_sfera_mbc_runtime->program_table_base;
    cpu->edx = *(uint8_t*)(cpu->eax + cpu->edi + 0x2Du);
    cpu->esi = (int16_t)(*(uint16_t*)(cpu->ebx + ((uint32_t)(cpu->edx) * 2u) + 0x7Cu));
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00034F55;
    *(uint16_t*)(cpu->ebx + ((uint32_t)(cpu->edx) * 2u) + 0x7Cu) = cpu->ecx & 0xFFFFu;
    cpu->esi = g_sfera_mbc_runtime->active_process;
    *(uint16_t*)(cpu->esi + ((uint32_t)(cpu->edx) * 2u) + 0x74u) = cpu->ecx & 0xFFFFu;
    cpu->edx = g_sfera_mbc_runtime->program_table_base;
    *(uint16_t*)(cpu->eax + cpu->edx + 0x9Cu) = cpu->ecx & 0xFFFFu;
    goto label_00034F7E;
    label_00034F55:
    cpu->ebx = cpu->esi;
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0xA4u);
    *(uint16_t*)(cpu->ebx + cpu->edi + 0x9Eu) = cpu->ecx & 0xFFFFu;
    cpu->edi = g_sfera_mbc_runtime->program_table_base;
    *(uint16_t*)(cpu->eax + cpu->edi + 0x9Cu) = cpu->esi & 0xFFFFu;
    cpu->esi = g_sfera_mbc_runtime->active_process;
    *(uint16_t*)(cpu->esi + ((uint32_t)(cpu->edx) * 2u) + 0x7Cu) = cpu->ecx & 0xFFFFu;
    label_00034F7E:
    cpu->edx = g_sfera_mbc_runtime->program_table_base;
    *(uint16_t*)(cpu->eax + cpu->edx + 0x9Eu) = cpu->ecx & 0xFFFFu;
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 0xB8u) = 1u;
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->ecx = *(uint32_t*)(cpu->edx + 0xB4u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    sfera_sub_00433CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434FB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->edx;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xA4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->ecx + 0x5Cu);
    cpu->edx += cpu->ebx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint8_t*)(cpu->edx + 0x2Du);
    lift_push32(cpu, cpu->edi);
    cpu->edi = (int16_t)(*(uint16_t*)(cpu->ecx + ((uint32_t)(cpu->esi) * 2u) + 0x7Cu));
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00034FE0;
    *(uint16_t*)(cpu->ecx + ((uint32_t)(cpu->esi) * 2u) + 0x7Cu) = cpu->eax & 0xFFFFu;
    *(uint16_t*)(cpu->ecx + ((uint32_t)(cpu->esi) * 2u) + 0x74u) = cpu->eax & 0xFFFFu;
    *(uint16_t*)(cpu->edx + 0x9Cu) = cpu->eax & 0xFFFFu;
    goto label_00034FFE;
    label_00034FE0:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->edi;
    cpu->ebp = (int64_t)(int32_t)(cpu->ebp) * (int64_t)(int32_t)(0xA4u);
    *(uint16_t*)(cpu->ebx + cpu->ebp + 0x9Eu) = cpu->eax & 0xFFFFu;
    *(uint16_t*)(cpu->edx + 0x9Cu) = cpu->edi & 0xFFFFu;
    *(uint16_t*)(cpu->ecx + ((uint32_t)(cpu->esi) * 2u) + 0x7Cu) = cpu->eax & 0xFFFFu;
    cpu->ebp = lift_pop32(cpu);
    label_00034FFE:
    cpu->edi = lift_pop32(cpu);
    *(uint16_t*)(cpu->edx + 0x9Eu) = cpu->eax & 0xFFFFu;
    cpu->esi = lift_pop32(cpu);
    *(uint8_t*)(cpu->ecx + 0xB8u) = 1u;
    cpu->edx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0xB4u);
    cpu->ebx = lift_pop32(cpu);
    sfera_sub_00433CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00435020(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->edi + 0x5Cu);
    cpu->ebx = cpu->edx;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00035034;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00035034:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = 0u;
    if ((int32_t)*(uint32_t*)(cpu->edi + 0x58u) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_00035079;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00035040:
    cpu->ecx = cpu->ebx;
    cpu->eax = cpu->esi;
    label_00035044:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(*(uint8_t*)(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00035064;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_00035060;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(*(uint8_t*)(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00035064;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00035044;
    label_00035060:
    cpu->eax = 0u;
    goto label_00035069;
    label_00035064:
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_00035069:
    if ((uint32_t)(cpu->eax) == 0u) goto label_00035080;
    ++cpu->ebp;
    cpu->esi += 0xA4u;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)*(uint32_t*)(cpu->edi + 0x58u)) goto label_00035040;
    label_00035079:
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00035080:
    if (*(uint8_t*)(cpu->esi + 0x2Cu) == (uint8_t)(1u)) goto label_00035098;
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43508Fu)); sfera_sub_00434FB0(cpu, LIFT_CODE_TOKEN_VA(0x43508Fu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    *(uint32_t*)(cpu->esi + 0x88u) = cpu->eax;
    label_00035098:
    *(uint8_t*)(cpu->esi + 0x2Cu) = 1u;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xB4u);
    cpu->edx = cpu->edi;
    *(uint8_t*)(cpu->edi + 0xB8u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4350B0u)); sfera_sub_00433CF0(cpu, LIFT_CODE_TOKEN_VA(0x4350B0u));
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004350C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edx) < 0) goto label_0003510A;
    if ((int32_t)(uint32_t)(cpu->edx) >= (int32_t)*(uint32_t*)(cpu->edi + 0x58u)) goto label_0003510A;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->edi + 0x5Cu);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000350D9;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000350D9:
    cpu->eax = cpu->edx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    cpu->esi += cpu->eax;
    if (*(uint8_t*)(cpu->esi + 0x2Cu) == (uint8_t)(1u)) goto label_000350F7;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4350EEu)); sfera_sub_00434FB0(cpu, LIFT_CODE_TOKEN_VA(0x4350EEu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x24u);
    *(uint32_t*)(cpu->esi + 0x88u) = cpu->ecx;
    label_000350F7:
    *(uint8_t*)(cpu->esi + 0x2Cu) = 1u;
    cpu->esi = lift_pop32(cpu);
    *(uint8_t*)(cpu->edi + 0xB8u) = 1u;
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003510A:
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00435110(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = g_sfera_mbc_runtime->module_link_stream_size;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00035228;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(0x7Fu) & 0xFFu);
    lift_push32(cpu, cpu->edi);
    label_00035130:
    if (*(uint8_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->module_link_stream[0])) != (uint8_t)((cpu->edx & 0xFFu))) goto label_0003521C;
    cpu->esi = (int8_t)(*(uint8_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->module_link_stream[1])));
    cpu->edi = *(uint32_t*)(cpu->ecx + (uint32_t)offsetof(SferaMbcProcessRecord, module_record_base));
    cpu->esi = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 8u));
    cpu->esi += cpu->esi;
    cpu->esi += cpu->esi;
    cpu->edi += cpu->esi;
    if (*(uint8_t*)(cpu->edi + 0x20u) != (uint8_t)(0xFFu)) goto label_000351D1;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->module_link_stream[2]))) & 0xFFu);
    *(uint8_t*)(cpu->edi + 0x20u) = cpu->ebx & 0xFFu;
    cpu->edi = *(uint16_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->module_link_stream[3]));
    cpu->eax += 5u;
    if ((uint32_t)(cpu->edi) == (uint32_t)(0xFFFFu)) goto label_00035190;
    cpu->ebx = *(uint32_t*)(cpu->ecx + (uint32_t)offsetof(SferaMbcProcessRecord, module_record_base));
    cpu->ebx = (uint32_t)(cpu->ebx + cpu->esi + 0x22u);
    cpu->ebp = 0xFFFFu;
    if (*(uint16_t*)(cpu->ebx) != (uint16_t)((cpu->ebp & 0xFFFFu))) goto label_00035190;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp += cpu->edi;
    *(uint16_t*)(cpu->ebx) = cpu->ebp & 0xFFFFu;
    label_00035190:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->module_link_stream[0]))) & 0xFFu);
    cpu->edi = 0u;
    if ((uint8_t)((cpu->ebx & 0xFFu)) == (uint8_t)((cpu->edx & 0xFFu))) goto label_000351BF;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000351A0:
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(g_sfera_mbc_runtime->module_link_stream_size)) goto label_000351BF;
    cpu->ebp = *(uint32_t*)(cpu->ecx + (uint32_t)offsetof(SferaMbcProcessRecord, module_record_base));
    cpu->ebp += cpu->esi;
    ++cpu->eax;
    *(uint8_t*)(cpu->edi + cpu->ebp) = cpu->ebx & 0xFFu;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->module_link_stream[0]))) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != (uint8_t)((cpu->edx & 0xFFu))) goto label_000351A0;
    label_000351BF:
    cpu->ebx = *(uint32_t*)(cpu->ecx + (uint32_t)offsetof(SferaMbcProcessRecord, module_record_base));
    *(uint32_t*)(cpu->ebx + cpu->esi + 0x1Cu) = cpu->edi;
    cpu->ebx = g_sfera_mbc_runtime->module_link_stream_size;
    goto label_00035213;
    label_000351D1:
    cpu->esi = *(uint16_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->module_link_stream[3]));
    cpu->eax += 5u;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFu)) goto label_000351FE;
    cpu->ebp = 0xFFFFu;
    if (*(uint16_t*)(cpu->edi + 0x22u) != (uint16_t)((cpu->ebp & 0xFFFFu))) goto label_000351FE;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx += cpu->esi;
    *(uint16_t*)(cpu->edi + 0x22u) = cpu->ebx & 0xFFFFu;
    cpu->ebx = g_sfera_mbc_runtime->module_link_stream_size;
    label_000351FE:
    if (*(uint8_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->module_link_stream[0])) == (uint8_t)((cpu->edx & 0xFFu))) goto label_0003521B;
    label_00035206:
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_00035213;
    ++cpu->eax;
    if (*(uint8_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->module_link_stream[0])) != (uint8_t)((cpu->edx & 0xFFu))) goto label_00035206;
    label_00035213:
    if (*(uint8_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->module_link_stream[0])) != (uint8_t)((cpu->edx & 0xFFu))) goto label_0003521C;
    label_0003521B:
    --cpu->eax;
    label_0003521C:
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ebx)) goto label_00035130;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_00035228:
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00435230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x50u;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    g_sfera_mbc_runtime->text_buffer[0] = (uint8_t)(0u);
    { uint64_t l=(uint64_t)(*(uint8_t*)(cpu->eax)), r=(uint64_t)(0x40u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esi;
    cpu->ebx = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00035294;
    { uint64_t l=(uint64_t)(*(uint8_t*)(cpu->eax + 1u)), r=(uint64_t)(0x40u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebx = (uint32_t)(cpu->eax + 1u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->text_buffer[0];
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00035290;
    label_00035264:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->ebx)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_00035397;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x3Bu)) goto label_0003527D;
    *(uint16_t*)(cpu->eax) = 0xA0Du;
    cpu->eax += 2u;
    goto label_0003528A;
    label_0003527D:
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x27u)) goto label_00035285;
    *(uint8_t*)(cpu->ebx) = 0x22u;
    label_00035285:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->ebx)) & 0xFFu);
    *(uint8_t*)(cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    label_0003528A:
    ++cpu->ebx;
    if (*(uint8_t*)(cpu->ebx) != (uint8_t)(0x40u)) goto label_00035264;
    label_00035290:
    *(uint8_t*)(cpu->eax) = 0u;
    ++cpu->ebx;
    label_00035294:
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    cpu->eax = cpu->ebx;
    cpu->edx -= cpu->ebx;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000352A0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000352A0;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    --cpu->eax;
    (void)cpu;
    label_000352B0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000352B0;
    cpu->edx = 0x63626D2Eu;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint8_t*)(cpu->eax + 4u) = cpu->ecx & 0xFFu;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000352D0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000352D0;
    cpu->eax -= cpu->edx;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(0x24u)) goto label_00035397;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_inter_scalar_runtime.state_03;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4352FEu)); sfera_sub_00489EF0(cpu, LIFT_CODE_TOKEN_VA(0x4352FEu));
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) == 0u) goto label_00035D16;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(0x10u)) goto label_00035D16;
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_000353AB;
    cpu->eax = g_sfera_network_runtime.shutdown_state;
    ++cpu->eax;
    g_sfera_network_runtime.shutdown_state = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(2u)) goto label_00035338;
    g_sfera_network_runtime.shutdown_state = (uint32_t)(0u);
    label_00035338:
    cpu->eax = g_sfera_mbc_runtime->process_search_cursor;
    cpu->esi = cpu->eax;
    cpu->edx = cpu->esi;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003537C;
    label_00035354:
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0x10000u)) goto label_0003535F;
    cpu->esi = 0u;
    label_0003535F:
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_00035D16;
    cpu->ecx = cpu->esi;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x348u);
    if ((int32_t)*(uint32_t*)(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index)) >= (int32_t)(uint32_t)(0u)) goto label_00035354;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    label_0003537C:
    cpu->eax = (uint32_t)(cpu->esi + 1u);
    g_sfera_mbc_runtime->process_search_cursor = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x10000u)) goto label_000353D0;
    g_sfera_mbc_runtime->process_search_cursor = (uint32_t)(0u);
    goto label_000353D0;
    label_00035397:
    cpu->esi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x50u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000353AB:
    if ((uint32_t)(cpu->esi) > (uint32_t)(0xFFFFu)) goto label_00035D16;
    cpu->edx = cpu->esi;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00035D16;
    label_000353D0:
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    cpu->esi += ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0]);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_key)) = cpu->eax;
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_key) + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_key) + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_key) + 0xCu) = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(*(uint16_t*)(cpu->esp + 0x24u)) & 0xFFFFu);
    cpu->edx = cpu->esi;
    *(uint16_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_key)) = cpu->eax & 0xFFFFu;
    cpu->eax = cpu->ebx;
    cpu->edx -= cpu->ebx;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00035400:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    *(uint8_t*)(cpu->edx + cpu->eax + 0x10u) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00035400;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(0x10u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebp = v; }
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, flags)) = 0u;
    *(uint16_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, state_byte_b8)) = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000355B6;
    cpu->ebx = (uint32_t)(cpu->ebp + 0x10u);
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00035443;
    label_00035438:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43543Bu));
    cpu->esp += 0xCu;
    label_00035443:
    cpu->eax = *(uint8_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, header_code_0c));
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = *(uint8_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, header_code_0e));
    cpu->edi += cpu->ebx;
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 2u) + 0xFFFFFDF0u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebp = v; }
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000355C0;
    cpu->ebx = (uint32_t)(cpu->ebp + 4u);
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00035483;
    label_00035475:
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, field_040));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43547Bu));
    cpu->esp += 0xCu;
    label_00035483:
    cpu->edi += cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebp = v; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000355CA;
    cpu->ebx = (uint32_t)(cpu->ebp + 4u);
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_000354AD;
    label_0003549F:
    lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4354A5u));
    cpu->esp += 0xCu;
    label_000354AD:
    cpu->eax = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag));
    cpu->edi += cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000354C0;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    ++g_sfera_mbc_module_memory_stats[cpu->eax / 3u].process_count;
    label_000354C0:
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebp = v; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000355D4;
    cpu->ebx = (uint32_t)(cpu->ebp + 4u);
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_000354E8;
    label_000354DA:
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4354E0u));
    cpu->esp += 0xCu;
    label_000354E8:
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size))), r=(uint64_t)(2u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size)) = v; }
    cpu->edi += cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebp = v; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000355DE;
    cpu->ebx = (uint32_t)(cpu->ebp + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00035518;
    label_0003550A:
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_size));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435510u));
    cpu->esp += 0xCu;
    label_00035518:
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    cpu->edi += cpu->ebx;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00035530;
    lift_push32(cpu, 0xBADu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x35530u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_RVA(0x35530u));
    label_00035530:
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_ids)) = cpu->eax;
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_ids) + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_ids) + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_ids) + 0xCu) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size));
    cpu->ecx = 1u;
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_begin)) = cpu->eax;
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_memory_offset)) = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(*(uint16_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag))) & 0xFFFFu);
    *(uint16_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count)) = cpu->ecx & 0xFFFFu;
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_size)) = cpu->edx;
    *(uint16_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_ids)) = cpu->eax & 0xFFFFu;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag))), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00035585;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.mbc_service_object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x35585u)); sfera_sub_004225F0(cpu, LIFT_CODE_TOKEN_RVA(0x35585u));
    label_00035585:
    cpu->edx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_size));
    cpu->ecx = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_key));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x435590u)); sfera_sub_00433C80(cpu, LIFT_CODE_TOKEN_VA(0x435590u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000355E8;
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base)) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size));
    cpu->eax -= 2u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000355AF;
    cpu->eax += *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    label_000355AF:
    cpu->edi += cpu->eax;
    goto label_0003564B;
    label_000355B6:
    cpu->ebx = 0x10u;
    goto label_00035438;
    label_000355C0:
    cpu->ebx = 4u;
    goto label_00035475;
    label_000355CA:
    cpu->ebx = 4u;
    goto label_0003549F;
    label_000355D4:
    cpu->ebx = 4u;
    goto label_000354DA;
    label_000355DE:
    cpu->ebx = 4u;
    goto label_0003550A;
    label_000355E8:
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size));
    lift_push32(cpu, 0xBC3u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4355FAu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4355FAu));
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size));
    cpu->ecx -= 2u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base)) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0003561A;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = (uint32_t)(cpu->ecx + cpu->edx);
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    goto label_0003561C;
    label_0003561A:
    cpu->ebx = cpu->ecx;
    label_0003561C:
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_0003562B;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435623u));
    cpu->esp += 0xCu;
    label_0003562B:
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base));
    cpu->eax = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size));
    cpu->eax = (uint32_t)(cpu->eax + cpu->ecx + 0xFFFFFFFEu);
    *(uint16_t*)(cpu->eax) = 0x23C9u;
    cpu->edx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_size));
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base));
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_key));
    cpu->edi += cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3564Bu)); sfera_sub_00433C00(cpu, LIFT_CODE_TOKEN_RVA(0x3564Bu));
    label_0003564B:
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_size));
    lift_push32(cpu, 0xBD5u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43565Du)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x43565Du));
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag));
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base)) = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_00035674;
    cpu->edx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_size));
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    g_sfera_mbc_module_memory_stats[cpu->ecx / 3u].process_memory_bytes += cpu->edx;
    label_00035674:
    cpu->ebx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_size));
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035689;
    cpu->ebx += *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    goto label_0003568B;
    label_00035689:
    cpu->ebp = 0u;
    label_0003568B:
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0003569A;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435692u));
    cpu->esp += 0xCu;
    label_0003569A:
    cpu->edi += cpu->ebx;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035B23;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_000356C4;
    label_000356B6:
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_count));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4356BCu));
    cpu->esp += 0xCu;
    label_000356C4:
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->edi += cpu->ebx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_000356DC;
    lift_push32(cpu, 0xBDDu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x356DCu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_RVA(0x356DCu));
    label_000356DC:
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_count));
    ++cpu->ecx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xA4u);
    lift_push32(cpu, 0xBE2u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4356F5u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4356F5u));
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base)) = cpu->eax;
    cpu->eax = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_map_a));
    cpu->ecx = 4u;
    label_00035700:
    cpu->edx |= 0xFFFFFFFFu;
    *(uint16_t*)(cpu->eax + 8u) = cpu->edx & 0xFFFFu;
    cpu->edx |= cpu->edx;
    *(uint16_t*)(cpu->eax) = cpu->edx & 0xFFFFu;
    cpu->eax += 2u;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00035700;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_count))), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_000358D0;
    cpu->ebp = 0u;
    label_00035721:
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00035730:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; *(uint32_t*)(cpu->esp + 0x10u) = v; }
    *(uint8_t*)(cpu->esp + 0x17u) = cpu->eax & 0xFFu;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035B2D;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00035764;
    label_00035751:
    lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Bu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435758u));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->esp + 0x23u)) & 0xFFu);
    cpu->esp += 0xCu;
    label_00035764:
    cpu->edx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx += cpu->ebp;
    *(uint8_t*)(cpu->edx + cpu->ecx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    cpu->edi += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00035730;
    cpu->eax = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->ebx = 4u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    cpu->eax = (uint32_t)(cpu->eax + cpu->ebp + 0x24u);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000357A0;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_000357AB;
    label_000357A0:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4357A3u));
    cpu->esp += 0xCu;
    label_000357AB:
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->edi += cpu->ebx;
    cpu->ebx = 4u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    cpu->eax = (uint32_t)(cpu->ecx + cpu->ebp + 0x28u);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000357D2;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_000357DD;
    label_000357D2:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4357D5u));
    cpu->esp += 0xCu;
    label_000357DD:
    cpu->edx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->edi += cpu->ebx;
    cpu->ebx = 1u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    cpu->eax = (uint32_t)(cpu->edx + cpu->ebp + 0x2Cu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035802;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_0003580D;
    label_00035802:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435805u));
    cpu->esp += 0xCu;
    label_0003580D:
    cpu->eax = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->edi += cpu->ebx;
    cpu->ebx = 1u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    cpu->eax = (uint32_t)(cpu->eax + cpu->ebp + 0x2Du);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035832;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_0003583D;
    label_00035832:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435835u));
    cpu->esp += 0xCu;
    label_0003583D:
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->edi += cpu->ebx;
    cpu->ebx = 4u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    cpu->eax = (uint32_t)(cpu->ecx + cpu->ebp + 0x30u);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035864;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_0003586F;
    label_00035864:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435867u));
    cpu->esp += 0xCu;
    label_0003586F:
    cpu->edx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    *(uint8_t*)(cpu->edx + cpu->ebp + 0x84u) = 0u;
    cpu->eax = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    *(uint8_t*)(cpu->eax + cpu->ebp + 0x94u) = 0u;
    cpu->eax = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->ebp + 0x24u);
    *(uint32_t*)(cpu->eax + cpu->ebp + 0x88u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    *(uint32_t*)(cpu->eax + cpu->ebp + 0x98u) = 0xFFFFFFFFu;
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->edi += cpu->ebx;
    if (*(uint8_t*)(cpu->ecx + cpu->ebp + 0x2Cu) != (uint8_t)(1u)) goto label_000358B8;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x358B8u)); sfera_sub_00434FB0(cpu, LIFT_CODE_TOKEN_RVA(0x358B8u));
    label_000358B8:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    ++cpu->eax;
    cpu->ebp += 0xA4u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(*(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_count))), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00035721;
    label_000358D0:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->eax = cpu->edx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    *(uint32_t*)(cpu->eax + cpu->ecx) = 0x465023u;
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size));
    cpu->ebx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->ecx -= 2u;
    *(uint32_t*)(cpu->ebx + cpu->eax + 0x24u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->ebx = *(uint32_t*)(cpu->ecx + cpu->eax + 0x24u);
    ++cpu->ebx;
    *(uint32_t*)(cpu->ecx + cpu->eax + 0x28u) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    *(uint8_t*)(cpu->ecx + cpu->eax + 0x2Cu) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    *(uint8_t*)(cpu->ecx + cpu->eax + 0x2Du) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->ecx + cpu->eax + 0x30u) = cpu->ebp;
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    *(uint8_t*)(cpu->ecx + cpu->eax + 0x84u) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->ebx = *(uint32_t*)(cpu->ecx + cpu->eax + 0x24u);
    *(uint32_t*)(cpu->ecx + cpu->eax + 0x88u) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    *(uint32_t*)(cpu->ecx + cpu->eax + 0x98u) = 0xFFFFFFFFu;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_count))), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_count)) = v; }
    cpu->ebx = 4u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, field_0bc)) = cpu->ebp;
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, field_0c0)) = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035968;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_00035978;
    label_00035968:
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_count));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43596Eu));
    cpu->esp += 0xCu;
    cpu->ebp = 0u;
    label_00035978:
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    cpu->edi += cpu->ebx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_00035992;
    lift_push32(cpu, 0xC17u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x435990u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x435990u));
    cpu->ebp = 0u;
    label_00035992:
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_count));
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table)) = cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ecx) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_000359B3;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x34u);
    lift_push32(cpu, 0xC1Eu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4359AEu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4359AEu));
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table)) = cpu->eax;
    cpu->ebp = 0u;
    label_000359B3:
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_count))), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00035AD1;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    label_000359D0:
    cpu->ebx = 0u;
    label_000359D2:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebp = 1u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    *(uint8_t*)(cpu->esp + 0x17u) = cpu->eax & 0xFFu;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000359F4;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00035A07;
    label_000359F4:
    lift_push32(cpu, cpu->ebp);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Bu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4359FBu));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->esp + 0x23u)) & 0xFFu);
    cpu->esp += 0xCu;
    label_00035A07:
    cpu->edx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx += cpu->ecx;
    *(uint8_t*)(cpu->edx + cpu->ebx) = cpu->eax & 0xFFu;
    cpu->edi += cpu->ebp;
    ++cpu->ebx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000359D2;
    cpu->eax = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    cpu->ebx = 4u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    cpu->eax = (uint32_t)(cpu->ecx + cpu->eax + 0x24u);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035B37;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00035A4E;
    label_00035A43:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435A46u));
    cpu->esp += 0xCu;
    label_00035A4E:
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edi += cpu->ebp;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    cpu->eax = (uint32_t)(cpu->edx + cpu->ecx + 0x28u);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035B3E;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00035A83;
    label_00035A78:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435A7Bu));
    cpu->esp += 0xCu;
    label_00035A83:
    cpu->eax = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edi += cpu->ebp;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    cpu->eax = (uint32_t)(cpu->ecx + cpu->eax + 0x2Cu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035B45;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00035AB8;
    label_00035AAD:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435AB0u));
    cpu->esp += 0xCu;
    label_00035AB8:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x18u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x18u)) + (uint64_t)(0x34u) + (uint64_t)(0u);
    ++cpu->eax;
    cpu->edi += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(*(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_count))), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000359D0;
    label_00035AD1:
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, workspace_base));
    cpu->ebp = 0u;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_00035AEC;
    lift_push32(cpu, 0xC36u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x35AECu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_RVA(0x35AECu));
    label_00035AEC:
    cpu->ebx = 0xA0u;
    lift_push32(cpu, 0xC37u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x435B02u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x435B02u));
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x28u)), r=(uint64_t)(0x16u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, workspace_base)) = cpu->eax;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00035B4C;
    cpu->ebx = 0x3Cu;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035B64;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx += 0x3Cu;
    goto label_00035B5C;
    label_00035B23:
    cpu->ebx = 4u;
    goto label_000356B6;
    label_00035B2D:
    cpu->ebx = 1u;
    goto label_00035751;
    label_00035B37:
    cpu->ebp = cpu->ebx;
    goto label_00035A43;
    label_00035B3E:
    cpu->ebp = cpu->ebx;
    goto label_00035A78;
    label_00035B45:
    cpu->ebp = cpu->ebx;
    goto label_00035AAD;
    label_00035B4C:
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035B64;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx += 0xA0u;
    label_00035B5C:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_00035B6F;
    label_00035B64:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435B67u));
    cpu->esp += 0xCu;
    label_00035B6F:
    cpu->edi += cpu->ebx;
    cpu->ebx = 4u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035B8B;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_00035B9A;
    label_00035B8B:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->module_link_stream_size);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435B92u));
    cpu->esp += 0xCu;
    label_00035B9A:
    cpu->eax = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x8D8u);
    lift_push32(cpu, 0x8B8u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0].runtime[0]));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    cpu->edi += cpu->ebx;
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_record_base)) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x435BB9u));
    cpu->ebx = g_sfera_mbc_runtime->module_link_stream_size;
    cpu->esp += 0xCu;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035BD5;
    cpu->ebx += *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    label_00035BD5:
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_00035BE8;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->module_link_stream[0]);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435BE0u));
    cpu->esp += 0xCu;
    label_00035BE8:
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    cpu->edi += cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x435BF3u)); sfera_sub_00435110(cpu, LIFT_CODE_TOKEN_VA(0x435BF3u));
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebx = v; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035CC6;
    cpu->ebp = (uint32_t)(cpu->ebx + 4u);
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00035C22;
    label_00035C11:
    lift_push32(cpu, cpu->ebp);
    cpu->eax = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, field_084));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435C1Au));
    cpu->esp += 0xCu;
    label_00035C22:
    cpu->edi += cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebx = v; }
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, field_090)) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035CD0;
    cpu->ebp = (uint32_t)(cpu->ebx + 4u);
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00035C59;
    label_00035C48:
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, field_088));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435C51u));
    cpu->esp += 0xCu;
    label_00035C59:
    cpu->edi += cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebx = v; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035CDA;
    cpu->ebx += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00035C84;
    label_00035C73:
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, field_08c));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435C7Cu));
    cpu->esp += 0xCu;
    label_00035C84:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, field_09a)) = cpu->eax;
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entry_count)) = cpu->eax;
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_capacity)) = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->process_chain_last;
    cpu->edx = cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    *(uint32_t*)(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_next_index)) = cpu->ecx;
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, chain_prev_index)) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, chain_next_index)) = cpu->ecx;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_00035CE1;
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_id)) = cpu->ecx;
    goto label_00035CE7;
    label_00035CC6:
    cpu->ebp = 4u;
    goto label_00035C11;
    label_00035CD0:
    cpu->ebp = 4u;
    goto label_00035C48;
    label_00035CDA:
    cpu->ebx = 4u;
    goto label_00035C73;
    label_00035CE1:
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_id)) = cpu->eax;
    label_00035CE7:
    { uint64_t l=(uint64_t)(*(uint8_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, state_byte_b8))), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    g_sfera_mbc_runtime->process_chain_last = (uint32_t)(cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00035CFD;
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x35CFDu)); sfera_sub_00433CF0(cpu, LIFT_CODE_TOKEN_RVA(0x35CFDu));
    label_00035CFD:
    cpu->eax = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_id));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x50u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00035D16:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0x50u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00435D40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00035D57;
    cpu->ecx = (uint32_t)(uintptr_t)"prc_unload _main.mbl\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x435D55u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x435D55u));
    goto label_00035D69;
    label_00035D57:
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00036092;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(0x10000u)) goto label_00036092;
    label_00035D69:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edi;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    cpu->esi += ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0]);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.mbc_service_object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x435D83u)); sfera_sub_00422270(cpu, LIFT_CODE_TOKEN_VA(0x435D83u));
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag))), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.mbc_service_object[0];
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00035D95;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x435D93u)); sfera_sub_00422620(cpu, LIFT_CODE_TOKEN_VA(0x435D93u));
    goto label_00035D9B;
    label_00035D95:
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x35D9Bu)); sfera_sub_00422630(cpu, LIFT_CODE_TOKEN_RVA(0x35D9Bu));
    label_00035D9B:
    cpu->eax = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag));
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_00035DAC;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    --g_sfera_mbc_module_memory_stats[cpu->eax / 3u].process_count;
    label_00035DAC:
    cpu->eax = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, chain_prev_index));
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ebx)) goto label_0003608A;
    if ((uint32_t)(cpu->edi) != (uint32_t)(g_sfera_mbc_runtime->process_chain_last)) goto label_00035DD4;
    cpu->ecx = cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x348u);
    g_sfera_mbc_runtime->process_chain_last = (uint32_t)(cpu->eax);
    *(uint32_t*)(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_next_index)) = cpu->eax;
    goto label_00035E15;
    label_00035DD4:
    if ((uint32_t)(cpu->edi) != (uint32_t)(g_sfera_mbc_runtime->process_chain_first)) goto label_00035DF4;
    cpu->eax = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, chain_next_index));
    cpu->edx = cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    g_sfera_mbc_runtime->process_chain_first = (uint32_t)(cpu->eax);
    *(uint32_t*)(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index)) = cpu->eax;
    goto label_00035E15;
    label_00035DF4:
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, chain_next_index));
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x348u);
    *(uint32_t*)(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index)) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, chain_prev_index));
    cpu->eax = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, chain_next_index));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    *(uint32_t*)(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_next_index)) = cpu->eax;
    label_00035E15:
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x435E1Eu)); sfera_sub_00433DA0(cpu, LIFT_CODE_TOKEN_VA(0x435E1Eu));
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, flags))), r=(uint64_t)(4u), v=l | r; lift_flags_logic(cpu,v,32u); *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, flags)) = v; }
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, chain_prev_index)) = 0xFFFFFFFFu;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00035E45;
    lift_push32(cpu, 0xE0Fu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x435E42u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x435E42u));
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base)) = cpu->ebx;
    label_00035E45:
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00035E5E;
    lift_push32(cpu, 0xE11u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x435E5Bu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x435E5Bu));
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table)) = cpu->ebx;
    label_00035E5E:
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, workspace_base));
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00035E7D;
    lift_push32(cpu, 0xE15u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x435E77u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x435E77u));
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, workspace_base)) = cpu->ebx;
    label_00035E7D:
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, owned_block_b));
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00035E9C;
    lift_push32(cpu, 0xE1Au);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x435E96u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x435E96u));
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, owned_block_b)) = cpu->ebx;
    label_00035E9C:
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, owned_block_a));
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00035EBB;
    lift_push32(cpu, 0xE26u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x435EB5u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x435EB5u));
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, owned_block_a)) = cpu->ebx;
    label_00035EBB:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, execution_scratch));
    *(uint32_t*)(cpu->esp + 0x10u) = 0x3Fu;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00035ED0:
    cpu->edi = *(uint32_t*)(cpu->ebp);
    *(uint32_t*)(cpu->ebp + 0xFFFFFF04u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebp) = cpu->ebx;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebx)) goto label_00035F0F;
    label_00035EE4:
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ebx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, 0xE38u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x435EF8u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x435EF8u));
    lift_push32(cpu, 0xE39u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x435F09u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x435F09u));
    cpu->edi = cpu->ebx;
    if ((uint32_t)(cpu->ebx) != 0u) goto label_00035EE4;
    label_00035F0F:
    cpu->ebp += 4u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; *(uint32_t*)(cpu->esp + 0x10u) = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00035ED0;
    cpu->edi = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entries));
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, field_0d8)) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, field_0d4)) = cpu->ebx;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebx)) goto label_0003605C;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entry_count))), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00035F69;
    cpu->edi = cpu->edi;
    label_00035F40:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(4u)) goto label_00035F51;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x435F4Fu)); sfera_sub_00457370(cpu, LIFT_CODE_TOKEN_VA(0x435F4Fu));
    goto label_00035F5D;
    label_00035F51:
    if ((uint32_t)(cpu->eax) != (uint32_t)(5u)) goto label_00035F5D;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x35F5Du)); sfera_sub_00455C20(cpu, LIFT_CODE_TOKEN_RVA(0x35F5Du));
    label_00035F5D:
    ++cpu->ebx;
    cpu->edi += 8u;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(*(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entry_count))), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00035F40;
    label_00035F69:
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entry_count))), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entries));
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003603B;
    label_00035F84:
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(9u)) goto label_00036023;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00035F97;
        case 1u: goto label_00035FA3;
        case 2u: goto label_00035FD1;
        case 3u: goto label_00035FDF;
        case 4u: case 5u: goto label_00036023;
        case 6u: goto label_00035FB1;
        case 7u: goto label_00035FBA;
        case 8u: goto label_00035FC8;
        case 9u: goto label_0003601C;
        default: lift_trap(cpu, 0x435F90u, "resolved jump-table index out of range"); return;
    }
label_00035F97: ;
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x435F9Eu)); sfera_sub_00459150(cpu, LIFT_CODE_TOKEN_VA(0x435F9Eu));
    goto label_00036023;
    label_00035FA3:
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x435FA6u));
    cpu->esp += 4u;
    goto label_00036023;
    label_00035FB1:
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x435FB8u)); sfera_sub_00458E80(cpu, LIFT_CODE_TOKEN_VA(0x435FB8u));
    goto label_00036023;
    label_00035FBA:
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    cpu->edx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x435FC6u)); sfera_sub_004B8700(cpu, LIFT_CODE_TOKEN_VA(0x435FC6u));
    goto label_00036023;
    label_00035FC8:
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x435FCFu)); sfera_sub_004D12C0(cpu, LIFT_CODE_TOKEN_VA(0x435FCFu));
    goto label_00036023;
    label_00035FD1:
    cpu->edx = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x435FD4u));
    cpu->esp += 4u;
    goto label_00036023;
    label_00035FDF:
    cpu->eax = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    cpu->edi = *(uint32_t*)(cpu->ecx + cpu->eax);
    cpu->edi += cpu->eax;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag))), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00036009;
    cpu->eax = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag));
    cpu->edx = (uint32_t)(cpu->edi + 0xFFFFFFFCu);
    lift_push32(cpu, cpu->edx);
    cpu->ebp = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    lift_native_call(cpu, native_function_address32(&::_msize), LIFT_CODE_TOKEN_VA(0x435FF9u));
    cpu->esp += 4u;
    g_sfera_mbc_module_memory_stats[cpu->ebp / 3u].dynamic_memory_bytes -= cpu->eax;
    label_00036009:
    lift_push32(cpu, 0xE65u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43601Au)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x43601Au));
    goto label_00036023;
    label_0003601C:
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x36023u)); sfera_sub_00401F10(cpu, LIFT_CODE_TOKEN_RVA(0x36023u));
    label_00036023:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->eax;
    cpu->ebx += 8u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(*(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entry_count))), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00035F84;
    label_0003603B:
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entries));
    lift_push32(cpu, 0xE71u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x436050u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x436050u));
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entries)) = 0u;
    cpu->ebx = 0u;
    label_0003605C:
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base)) = cpu->ebx;
    cpu->ebp = lift_pop32(cpu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00036079;
    lift_push32(cpu, 0xE8Cu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x436076u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x436076u));
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base)) = cpu->ebx;
    label_00036079:
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_id)) = 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003608A:
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00036092:
    cpu->edi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004360D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x3D0900u)) goto label_000361CD;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->active_process;
    cpu->ebx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_size));
    cpu->ecx = cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x80000003u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00036100;
    --cpu->ecx;
    cpu->ecx |= 0xFFFFFFFCu;
    ++cpu->ecx;
    label_00036100:
    cpu->edx = 4u;
    cpu->edx -= cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x80000003u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00036114;
    --cpu->edx;
    cpu->edx |= 0xFFFFFFFCu;
    ++cpu->edx;
    label_00036114:
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    cpu->ebx += cpu->edx;
    lift_push32(cpu, 0xEB4u);
    cpu->edx = (uint32_t)(cpu->ebx + cpu->eax);
    lift_push32(cpu, (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp");
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43612Du)); sfera_sub_004EBE80(cpu, LIFT_CODE_TOKEN_VA(0x43612Du));
    cpu->edi = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entries));
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base)) = cpu->eax;
    if ((uint32_t)(cpu->edi) == 0u) goto label_0003618E;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entry_count))), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003618E;
    label_00036150:
    if (*(uint32_t*)(cpu->edi + 4u) != (uint32_t)(3u)) goto label_0003617A;
    cpu->edx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->ecx = cpu->ebp;
    cpu->eax += cpu->edx;
    cpu->ecx -= cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0003617A;
    cpu->edx += cpu->ecx;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0003617A;
    cpu->edx += cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = (uint64_t)(*(uint32_t*)(cpu->eax + 8u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    label_0003617A:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->eax;
    cpu->edi += 8u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(*(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entry_count))), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00036150;
    label_0003618E:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    lift_push32(cpu, cpu->edi);
    cpu->eax += cpu->ebx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x43619Bu));
    cpu->eax = (uint32_t)(cpu->ebx + cpu->edi);
    *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_size)) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag));
    cpu->esp += 0xCu;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000361BA;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    g_sfera_mbc_module_memory_stats[cpu->eax / 3u].process_memory_bytes += cpu->edi;
    label_000361BA:
    cpu->ecx = *(uint32_t*)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    g_sfera_mbc_runtime->process_memory_base = (uint32_t)(cpu->ecx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000361CD:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004361E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u); lift_push32(cpu, 0x8000u); lift_push32(cpu, cpu->ecx);
    g_sfera_mbc_runtime->file_crc32 = (uint32_t)(0u);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4361F4u));
    cpu->edi = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->edi) != (uint32_t)(0xFFFFFFFFu)) goto label_00036209;
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00036209:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_filelength), LIFT_CODE_TOKEN_VA(0x43620Du));
    cpu->ecx = cpu->eax;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 0xFFFFu;
    cpu->esi = (uint32_t)(cpu->edx + cpu->eax);
    cpu->ebx = cpu->ecx;
    { uint64_t l=cpu->esp, r=(uint64_t)(4u), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    cpu->esi = (uint32_t)((int32_t)(cpu->esi) >> 16u);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(0x8000FFFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00036237;
    --cpu->ebx;
    cpu->ebx |= 0xFFFF0000u;
    ++cpu->ebx;
    label_00036237:
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_0003629B;
    label_00036243:
    lift_push32(cpu, 0x10000u); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->file_io_buffer[0]); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x43624Eu));
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000362B4;
    cpu->eax = g_sfera_mbc_runtime->file_crc32;
    cpu->ecx = 0x10000u;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_io_buffer[0];
    label_00036270:
    cpu->ebp = (int8_t)(*(uint8_t*)(cpu->edx));
    cpu->ebp ^= cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    cpu->eax >>= 8u;
    cpu->eax ^= *(uint32_t*)(((uint32_t)(cpu->ebp) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_crc32_table[0]));
    ++cpu->edx;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00036270;
    g_sfera_mbc_runtime->file_crc32 = (uint32_t)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->esi)) goto label_00036243;
    label_0003629B:
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000362C8;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->file_io_buffer[0]); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x4362A6u));
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000362BC;
    label_000362B4:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000362BC:
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_io_buffer[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x362C8u)); sfera_sub_004348D0(cpu, LIFT_CODE_TOKEN_RVA(0x362C8u));
    label_000362C8:
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x4362C9u));
    cpu->eax = g_sfera_mbc_runtime->file_crc32;
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004362E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->file_find_data); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->file_search_pattern[0]);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    lift_native_call(cpu, native_function_address32(&::_findfirst64i32), LIFT_CODE_TOKEN_VA(0x4362F5u));
    cpu->edi = cpu->eax;
    cpu->esp += 8u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edi;
    if ((uint32_t)(cpu->edi) == (uint32_t)(0xFFFFFFFFu)) goto label_000364F8;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::strncpy);
    cpu->ebx = 0u;
    goto label_00036324;
    label_00036320:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    label_00036324:
    if ((uint8_t)((g_sfera_mbc_runtime->file_find_data.attrib) & (0x10u)) != 0u) goto label_000364DB;
    lift_push32(cpu, (uintptr_t)"filelist.dat"); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->file_find_data.name[0]);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x43633Bu));
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000364DB;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_path_buffer[0];
    cpu->eax = cpu->esi;
    cpu->edx -= cpu->esi;
    label_00036355:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00036355;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_find_data.name[0];
    cpu->esi = cpu->eax;
    label_00036366:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00036366;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_path_buffer[0];
    cpu->eax -= cpu->esi;
    --cpu->edi;
    label_00036375:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ebx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00036375;
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 2u;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    lift_push32(cpu, 0xEFBu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = 0x118u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43639Fu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x43639Fu));
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_path_buffer[0];
    g_sfera_mbc_runtime->file_index_current = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4363AEu)); sfera_sub_004361E0(cpu, LIFT_CODE_TOKEN_VA(0x4363AEu));
    cpu->ecx = g_sfera_mbc_runtime->file_index_current;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    *(uint32_t*)(cpu->ecx + (uint32_t)offsetof(SferaMbcFileIndexNode, checksum)) = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->file_index_current;
    *(uint32_t*)(cpu->eax + ((uint32_t)offsetof(SferaMbcFileIndexNode, checksum) + 4u)) = cpu->edx;
    cpu->ecx = g_sfera_mbc_runtime->file_index_current;
    cpu->edx = *(uint32_t*)((uintptr_t)&g_sfera_mbc_runtime->file_find_data.size);
    *(uint32_t*)(cpu->ecx + (uint32_t)offsetof(SferaMbcFileIndexNode, file_size)) = cpu->edx;
    cpu->eax = g_sfera_mbc_runtime->file_index_current;
    lift_push32(cpu, 0x40u);
    cpu->eax += 8u;
    lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->file_find_data.name[0]); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x363EAu), LIFT_CODE_TOKEN_RVA(0x363E8u))) { return; }
    cpu->ecx = g_sfera_mbc_runtime->file_index_current;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->ebx;
    cpu->edx = g_sfera_mbc_runtime->file_index_current;
    *(uint32_t*)(cpu->edx) = cpu->ebx;
    cpu->eax = g_sfera_mbc_runtime->file_index_head;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_00036416;
    cpu->eax = g_sfera_mbc_runtime->file_index_current;
    g_sfera_mbc_runtime->file_index_head = (uint32_t)(cpu->eax);
    goto label_000364DB;
    label_00036416:
    g_sfera_mbc_runtime->file_index_scan_prev = (uint32_t)(cpu->ebx);
    g_sfera_mbc_runtime->file_index_scan = (uint32_t)(cpu->eax);
    label_00036421:
    cpu->ecx = g_sfera_mbc_runtime->file_index_current;
    cpu->ecx += 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x43642Fu));
    cpu->esp += 8u;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->eax = g_sfera_mbc_runtime->file_index_scan;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00036453;
    g_sfera_mbc_runtime->file_index_scan_prev = (uint32_t)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax);
    g_sfera_mbc_runtime->file_index_scan = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_00036421;
    goto label_000364C0;
    label_00036453:
    if ((uint32_t)(cpu->eax) != (uint32_t)(g_sfera_mbc_runtime->file_index_head)) goto label_0003647F;
    cpu->edx = g_sfera_mbc_runtime->file_index_current;
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->file_index_current;
    cpu->ecx = g_sfera_mbc_runtime->file_index_scan;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    cpu->edx = g_sfera_mbc_runtime->file_index_current;
    g_sfera_mbc_runtime->file_index_head = (uint32_t)(cpu->edx);
    goto label_000364B8;
    label_0003647F:
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = g_sfera_mbc_runtime->file_index_current;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = g_sfera_mbc_runtime->file_index_scan;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = g_sfera_mbc_runtime->file_index_current;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    cpu->edx = g_sfera_mbc_runtime->file_index_current;
    cpu->eax = g_sfera_mbc_runtime->file_index_scan;
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->ecx = g_sfera_mbc_runtime->file_index_current;
    cpu->edx = g_sfera_mbc_runtime->file_index_scan;
    *(uint32_t*)(cpu->edx + 4u) = cpu->ecx;
    label_000364B8:
    if ((uint32_t)(g_sfera_mbc_runtime->file_index_scan) != (uint32_t)(cpu->ebx)) goto label_000364DB;
    label_000364C0:
    cpu->eax = g_sfera_mbc_runtime->file_index_current;
    cpu->ecx = g_sfera_mbc_runtime->file_index_scan_prev;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = g_sfera_mbc_runtime->file_index_current;
    cpu->eax = g_sfera_mbc_runtime->file_index_scan_prev;
    *(uint32_t*)(cpu->edx + 4u) = cpu->eax;
    label_000364DB:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->file_find_data); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_findnext64i32), LIFT_CODE_TOKEN_VA(0x4364E5u));
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00036320;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000364F8:
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x4364F9u));
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436510(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->ecx;
    cpu->ebx = 0u;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_search_pattern[0];
    lift_push32(cpu, cpu->edi);
    g_sfera_mbc_runtime->file_index_head = (uint32_t)(cpu->ebx);
    cpu->eax = cpu->ebp;
    cpu->esi -= cpu->ebp;
    label_00036528:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    *(uint8_t*)(cpu->esi + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00036528;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_search_pattern[0];
    --cpu->eax;
    label_00036538:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00036538;
    cpu->ecx = 0x656C6966u;
    cpu->edx = 0x7473696Cu;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = 0x7461642Eu;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x8000u);
    *(uint32_t*)(cpu->eax + (uint32_t)offsetof(SferaMbcFileIndexNode, name)) = cpu->ecx;
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_search_pattern[0]);
    *(uint8_t*)(cpu->eax + 0xCu) = cpu->edx & 0xFFu;
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x43656Eu));
    cpu->edi = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->edi) == (uint32_t)(0xFFFFFFFFu)) goto label_00036590;
    if ((uint32_t)(g_sfera_inter_scalar_runtime.state_06) == (uint32_t)(cpu->ebx)) goto label_000365CD;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x436587u));
    cpu->esp += 4u;
    label_00036590:
    lift_push32(cpu, 7u); lift_push32(cpu, (uintptr_t)"xupdate"); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::strncmp), LIFT_CODE_TOKEN_VA(0x436598u));
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000365EB;
    cpu->eax = cpu->ebp;
    label_000365A7:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    *(uint8_t*)(cpu->esi + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000365A7;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_search_pattern[0];
    --cpu->edi;
    label_000365B7:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000365B7;
    cpu->eax = *(uint32_t*)((uintptr_t)"*.*");
    *(uint32_t*)(cpu->edi) = cpu->eax;
    cpu->ecx = cpu->ebp;
    goto label_00036691;
    label_000365CD:
    lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->file_crc32); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x4365D5u));
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x4365DCu));
    cpu->esp += 0x10u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000365EB:
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_search_pattern[0];
    g_sfera_mbc_runtime->file_search_pattern[0] = (uint8_t)((cpu->ebx & 0xFFu));
    --cpu->eax;
    label_000365F7:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000365F7;
    cpu->ecx = *(uint32_t*)((uintptr_t)"sphere*.exe");
    cpu->edx = *(uint32_t*)(((uint32_t)(uintptr_t)"sphere*.exe") + 4u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(((uint32_t)(uintptr_t)"sphere*.exe") + 8u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + (uint32_t)offsetof(SferaMbcFileIndexNode, name)) = cpu->ecx;
    cpu->ecx = (uint32_t)(uintptr_t)"";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x436623u)); sfera_sub_004362E0(cpu, LIFT_CODE_TOKEN_VA(0x436623u));
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_search_pattern[0];
    g_sfera_mbc_runtime->file_search_pattern[0] = (uint8_t)((cpu->ebx & 0xFFu));
    --cpu->eax;
    (void)cpu;
    label_00036630:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00036630;
    cpu->edx = *(uint32_t*)((uintptr_t)"xlaunch*.exe");
    cpu->ecx = *(uint32_t*)(((uint32_t)(uintptr_t)"xlaunch*.exe") + 4u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(((uint32_t)(uintptr_t)"xlaunch*.exe") + 8u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(((uint32_t)(uintptr_t)"xlaunch*.exe") + 0xCu)) & 0xFFu);
    *(uint32_t*)(cpu->eax + (uint32_t)offsetof(SferaMbcFileIndexNode, name)) = cpu->edx;
    *(uint8_t*)(cpu->eax + 0xCu) = cpu->ecx & 0xFFu;
    cpu->ecx = (uint32_t)(uintptr_t)"";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x436665u)); sfera_sub_004362E0(cpu, LIFT_CODE_TOKEN_VA(0x436665u));
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_search_pattern[0];
    g_sfera_mbc_runtime->file_search_pattern[0] = (uint8_t)((cpu->ebx & 0xFFu));
    --cpu->eax;
    label_00036671:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00036671;
    cpu->edx = *(uint32_t*)((uintptr_t)"*.dll");
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(*(uint16_t*)(((uint32_t)(uintptr_t)"*.dll") + 4u)) & 0xFFFFu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint16_t*)(cpu->eax + 4u) = cpu->ecx & 0xFFFFu;
    cpu->ecx = (uint32_t)(uintptr_t)"";
    label_00036691:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x436696u)); sfera_sub_004362E0(cpu, LIFT_CODE_TOKEN_VA(0x436696u));
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_path_buffer[0];
    cpu->eax = cpu->ebp;
    cpu->edx -= cpu->ebp;
    (void)cpu;
    label_000366A0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000366A0;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_path_buffer[0];
    --cpu->eax;
    label_000366B0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000366B0;
    cpu->edx = 0x656C6966u;
    cpu->ecx = 0x7473696Cu;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = 0x7461642Eu;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->eax + (uint32_t)offsetof(SferaMbcFileIndexNode, name)) = cpu->edx;
    *(uint8_t*)(cpu->eax + 0xCu) = cpu->ecx & 0xFFu;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_path_buffer[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4366E5u)); sfera_sub_0042EE20(cpu, LIFT_CODE_TOKEN_VA(0x4366E5u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_path_buffer[0];
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4366F5u)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x4366F5u));
    cpu->eax = g_sfera_mbc_runtime->file_index_head;
    g_sfera_mbc_runtime->file_crc32 = (uint32_t)(cpu->ebx);
    g_sfera_mbc_runtime->file_index_scan_prev = (uint32_t)(cpu->ebx);
    g_sfera_mbc_runtime->file_index_current = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000368B9;
    label_00036720:
    cpu->ebp = native_function_address32(&::tolower);
    cpu->eax += 8u;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_normalized_name[0];
    cpu->edx -= cpu->eax;
    label_00036730:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00036730;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_normalized_name[0];
    cpu->esi = 0u;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00036744:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00036744;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003677D;
    (void)cpu;
    label_00036750:
    cpu->edx = (int8_t)(*(uint8_t*)(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_normalized_name[0])));
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x3675Au), LIFT_CODE_TOKEN_RVA(0x36758u))) { return; }
    *(uint8_t*)(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_normalized_name[0])) = cpu->eax & 0xFFu;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_normalized_name[0];
    cpu->esp += 4u;
    ++cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00036770:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00036770;
    cpu->eax -= cpu->edx;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->eax)) goto label_00036750;
    label_0003677D:
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_normalized_name[0];
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00036785:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00036785;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_normalized_name[0];
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43679Cu)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x43679Cu));
    cpu->edx = g_sfera_mbc_runtime->file_index_current;
    lift_push32(cpu, 4u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)((uint32_t)offsetof(SferaMbcFileIndexNode, checksum)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4367B1u)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x4367B1u));
    cpu->edx = g_sfera_mbc_runtime->file_index_current;
    lift_push32(cpu, 4u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)((uint32_t)offsetof(SferaMbcFileIndexNode, file_size)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4367C6u)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x4367C6u));
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_normalized_name[0];
    cpu->ecx = (uint32_t)(cpu->eax + 1u);
    cpu->edi = cpu->edi;
    label_000367D0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000367D0;
    cpu->eax -= cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->eax + 1u);
    cpu->eax = g_sfera_mbc_runtime->file_crc32;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_normalized_name[0];
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00036810;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000367F0:
    cpu->esi = (int8_t)(*(uint8_t*)(cpu->edx));
    cpu->esi ^= cpu->eax;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    cpu->eax >>= 8u;
    cpu->eax ^= *(uint32_t*)(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_crc32_table[0]));
    --cpu->ecx;
    ++cpu->edx;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->ebx)) goto label_000367F0;
    g_sfera_mbc_runtime->file_crc32 = (uint32_t)(cpu->eax);
    label_00036810:
    cpu->esi = g_sfera_mbc_runtime->file_index_current;
    cpu->ecx = 4u;
    cpu->edx = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcFileIndexNode, checksum));
    label_00036821:
    cpu->ebp = (int8_t)(*(uint8_t*)(cpu->edx));
    cpu->ebp ^= cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    cpu->eax >>= 8u;
    cpu->eax ^= *(uint32_t*)(((uint32_t)(cpu->ebp) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_crc32_table[0]));
    --cpu->ecx;
    ++cpu->edx;
    g_sfera_mbc_runtime->file_crc32 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->ebx)) goto label_00036821;
    cpu->ecx = 4u;
    cpu->edx = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcFileIndexNode, file_size));
    cpu->esp = (uint32_t)(cpu->esp);
    label_00036850:
    cpu->ebp = (int8_t)(*(uint8_t*)(cpu->edx));
    cpu->ebp ^= cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    cpu->eax >>= 8u;
    cpu->eax ^= *(uint32_t*)(((uint32_t)(cpu->ebp) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_crc32_table[0]));
    --cpu->ecx;
    ++cpu->edx;
    g_sfera_mbc_runtime->file_crc32 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->ebx)) goto label_00036850;
    cpu->ecx = g_sfera_mbc_runtime->file_index_scan_prev;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0003688F;
    lift_push32(cpu, 0xF62u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x436889u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x436889u));
    cpu->esi = g_sfera_mbc_runtime->file_index_current;
    label_0003688F:
    cpu->ecx = cpu->esi;
    g_sfera_mbc_runtime->file_index_scan_prev = (uint32_t)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esi);
    g_sfera_mbc_runtime->file_index_current = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_00036720;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000368B9;
    lift_push32(cpu, 0xF65u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x368B9u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_RVA(0x368B9u));
    label_000368B9:
    lift_push32(cpu, cpu->ebx);
    cpu->edx = 0u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4368C3u)); sfera_sub_0042F0E0(cpu, LIFT_CODE_TOKEN_VA(0x4368C3u));
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_crc32;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4368D1u)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x4368D1u));
    cpu->ecx = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0042F180(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004368E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint8_t*)(cpu->edx);
    lift_push32(cpu, cpu->edi);
    cpu->eax <<= 5u;
    cpu->edi = 1u;
    cpu->edx += cpu->edi;
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx += 4u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->edx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(0x10u)) goto label_0003691C;
    if ((uint32_t)(cpu->esi) != (uint32_t)(0x20u)) goto label_00036944;
    label_0003691C:
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->edx + cpu->ecx);
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = 4u;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx += 3u;
    g_sfera_mbc_runtime->value_stack_size += cpu->edi;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00036944:
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00036970;
    cpu->edx = (int8_t)(*(uint8_t*)(cpu->edx + cpu->ecx));
    g_sfera_mbc_runtime->value_stack_size += cpu->edi;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->eax) = 0x10u;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00036970:
    cpu->esi = *(uint32_t*)(cpu->edx + cpu->ecx);
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->esi;
    cpu->edx = *(uint32_t*)(cpu->edx + cpu->ecx + 8u);
    g_sfera_mbc_runtime->value_stack_size += cpu->edi;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = 0xCu;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx += 0xBu;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004369A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->eax += *(uint32_t*)(cpu->eax);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004369B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = (int16_t)(*(uint16_t*)(cpu->eax));
    cpu->eax += cpu->ecx;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004369C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = *(uint8_t*)(cpu->eax);
    ++cpu->eax;
    g_sfera_mbc_runtime->argument_count = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004369E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->call_frame_depth;
    cpu->ecx = g_sfera_mbc_runtime->frame_stack_base[cpu->eax];
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436A00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint8_t*)(cpu->ecx);
    cpu->eax = cpu->edx;
    cpu->eax <<= 5u;
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = 1u;
    cpu->ecx += cpu->esi;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->esi;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->esi;
    lift_push32(cpu, cpu->edi);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 8u) = 0xFFFFFFFFu;
    cpu->edi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->edi;
    cpu->edx += cpu->esi;
    cpu->ecx += 4u;
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 4u) = 4u;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436A60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint8_t*)(cpu->ecx);
    cpu->eax = cpu->edx;
    cpu->eax <<= 5u;
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = 1u;
    cpu->ecx += cpu->esi;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->esi;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->esi;
    lift_push32(cpu, cpu->edi);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 8u) = 0xFFFFFFFFu;
    cpu->edi = *(uint16_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->edi;
    cpu->edx += cpu->esi;
    cpu->ecx += 2u;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 4u) = 4u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436AC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint8_t*)(cpu->ecx);
    cpu->eax = cpu->edx;
    cpu->eax <<= 5u;
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    cpu->esi = 1u;
    cpu->ecx += cpu->esi;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->esi;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->esi;
    lift_push32(cpu, cpu->edi);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 8u) = 0xFFFFFFFFu;
    cpu->edi = (int8_t)(*(uint8_t*)(cpu->ecx));
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->edi;
    cpu->ecx += cpu->esi;
    cpu->edx += cpu->esi;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 4u) = 4u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436B20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = cpu->esi;
    cpu->eax <<= 5u;
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    *(uint32_t*)(cpu->eax) = 1u;
    *(uint32_t*)(cpu->eax + 8u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->eax + 0x10u) = 1u;
    *(uint32_t*)(cpu->eax + 0xCu) = 1u;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->ecx += 4u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint16_t*)(cpu->ecx);
    cpu->ecx += 2u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edi + cpu->edx + 0xFFFFFFFFu);
    ++cpu->esi;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->esi);
    *(uint32_t*)(cpu->eax + 4u) = 0xCu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436B90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->edx = *(uint8_t*)(cpu->ecx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->eax <<= 5u;
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->ecx += 4u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx);
    cpu->ecx += 4u;
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->edx;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edi + cpu->edx + 0xFFFFFFFFu);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x18u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x1Cu);
    ++cpu->esi;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->esi);
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = 0xCu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436C00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = cpu->ecx;
    ++cpu->ecx;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->edx = *(uint8_t*)(cpu->ecx);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->eax <<= 5u;
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->ecx += 4u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx);
    cpu->ecx += 4u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->edx;
    cpu->ecx = (uint32_t)(cpu->esi + cpu->edx + 0xFFFFFFFFu);
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->eax + 0x10u) = 1u;
    *(uint32_t*)(cpu->eax + 0xCu) = 1u;
    *(uint32_t*)(cpu->eax + 4u) = 0xCu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436C70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = (int16_t)(*(uint16_t*)(cpu->eax));
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0xA4u);
    cpu->eax += 2u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->program_table_base;
    cpu->edx = *(uint32_t*)(cpu->esi + cpu->eax + 0x24u);
    *(uint32_t*)(cpu->esi + cpu->eax + 0x88u) = cpu->edx;
    cpu->eax = g_sfera_mbc_runtime->program_table_base;
    *(uint32_t*)(cpu->esi + cpu->eax + 0x98u) = 0xFFFFFFFFu;
    cpu->eax = g_sfera_mbc_runtime->program_table_base;
    if ((int8_t)*(uint8_t*)(cpu->esi + cpu->eax + 0x2Cu) >= (int8_t)(uint8_t)(0u)) goto label_00036CC7;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x436CBAu)); sfera_sub_00434F10(cpu, LIFT_CODE_TOKEN_VA(0x436CBAu));
    cpu->ecx = g_sfera_mbc_runtime->program_table_base;
    *(uint8_t*)(cpu->esi + cpu->ecx + 0x2Cu) = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00036CC7:
    *(uint8_t*)(cpu->esi + cpu->eax + 0x2Cu) = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436CD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = (int16_t)(*(uint16_t*)(cpu->eax));
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0xA4u);
    cpu->eax += 2u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->program_table_base;
    cpu->edx = *(uint32_t*)(cpu->esi + cpu->eax + 0x24u);
    *(uint32_t*)(cpu->esi + cpu->eax + 0x88u) = cpu->edx;
    cpu->eax = g_sfera_mbc_runtime->program_table_base;
    cpu->edx = g_sfera_mbc_runtime->program_index;
    *(uint32_t*)(cpu->esi + cpu->eax + 0x98u) = cpu->edx;
    cpu->eax = g_sfera_mbc_runtime->program_table_base;
    if ((int8_t)*(uint8_t*)(cpu->esi + cpu->eax + 0x2Cu) >= (int8_t)(uint8_t)(0u)) goto label_00036D21;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x436D1Cu)); sfera_sub_00434F10(cpu, LIFT_CODE_TOKEN_VA(0x436D1Cu));
    cpu->eax = g_sfera_mbc_runtime->program_table_base;
    label_00036D21:
    *(uint8_t*)(cpu->esi + cpu->eax + 0x2Cu) = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436D30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->eax = (int16_t)(*(uint16_t*)(cpu->ecx));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    cpu->ecx += 2u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->program_table_base;
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->ecx + 0x28u);
    *(uint32_t*)(cpu->eax + cpu->ecx + 0x88u) = cpu->edx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436D60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->eax = (int16_t)(*(uint16_t*)(cpu->ecx));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    cpu->ecx += 2u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->program_table_base;
    *(uint8_t*)(cpu->eax + cpu->ecx + 0x2Cu) = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436D90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = (int16_t)(*(uint16_t*)(cpu->eax));
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0xA4u);
    cpu->eax += 2u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->program_table_base;
    if ((int8_t)*(uint8_t*)(cpu->esi + cpu->eax + 0x2Cu) >= (int8_t)(uint8_t)(0u)) goto label_00036DBF;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x436DBAu)); sfera_sub_00434F10(cpu, LIFT_CODE_TOKEN_VA(0x436DBAu));
    cpu->eax = g_sfera_mbc_runtime->program_table_base;
    label_00036DBF:
    *(uint8_t*)(cpu->esi + cpu->eax + 0x2Cu) = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mbc_runtime->active_program_record;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->ecx + 0x84u)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00036DF2;
    cpu->ecx = g_sfera_mbc_runtime->bytecode_base;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ecx += cpu->eax;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00036DF2:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) - 1u)) & 0xFFu);
    *(uint8_t*)(cpu->ecx + 0x84u) = cpu->eax & 0xFFu;
    cpu->ecx = g_sfera_mbc_runtime->bytecode_base;
    cpu->edx = cpu->eax & 0xFFu;
    cpu->eax = g_sfera_mbc_runtime->active_program_record;
    cpu->eax = *(uint32_t*)(cpu->eax + ((uint32_t)(cpu->edx) * 4u) + 0x34u);
    cpu->ecx += cpu->eax;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436E20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    lift_push32(cpu, cpu->ebx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->eax);
    cpu->eax <<= 5u;
    cpu->ebx = *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.width));
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00036E4A;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_00036E5E;
    label_00036E4A:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xFFFFFFECu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00036E68;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_00036E5E;
    cpu->eax = (uint32_t)(cpu->eax + cpu->ebx + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->eax) <= *(uint32_t*)(cpu->esi + 0xFFFFFFF0u)) goto label_00036E68;
    label_00036E5E:
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFE8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x36E68u)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_RVA(0x36E68u));
    label_00036E68:
    if ((uint32_t)(cpu->ebx) != (uint32_t)(1u)) goto label_00036E8A;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xFFFFFFE8u);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->esi + 0xFFFFFFF4u) = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->esi + 0x14u)) & 0xFFu);
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + 0xFFFFFFF4u) = cpu->eax & 0xFFu;
    cpu->esi = lift_pop32(cpu);
    *(uint8_t*)(cpu->edx + cpu->ecx) = cpu->eax & 0xFFu;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00036E8A:
    { uint64_t l=(uint64_t)(*(uint8_t*)(cpu->esi + 0xFFFFFFE0u)), r=(uint64_t)(0xFu), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    *(uint32_t*)(cpu->esi + 0xFFFFFFF4u) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00036EA6;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xFFFFFFE8u);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->edx + cpu->ecx) = cpu->eax;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00036EA6:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0xFFFFFFE8u);
    cpu->edi += g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->esi + 0xFFFFFFF8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1Cu);
    *(uint32_t*)(cpu->esi + 0xFFFFFFFCu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    *(uint32_t*)(cpu->edi) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    *(uint32_t*)(cpu->edi + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1Cu);
    *(uint32_t*)(cpu->edi + 8u) = cpu->edx;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436ED0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->esi <<= 5u;
    cpu->eax = *(uint32_t*)(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0]));
    cpu->ecx = *(uint32_t*)(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[1]));
    cpu->edx = *(uint32_t*)(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[2]));
    cpu->esi = (uint32_t)(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edx;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00036F63;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->eax)) goto label_00036F0C;
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(cpu->edx)) goto label_00036F63;
    label_00036F0C:
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x436F16u)); sfera_sub_00434AF0(cpu, LIFT_CODE_TOKEN_VA(0x436F16u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x14u);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x436F37u)); sfera_sub_0049B7F0(cpu, LIFT_CODE_TOKEN_VA(0x436F37u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    cpu->esp += 0x18u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00036F63;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00036F63;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00036F53;
    if ((uint32_t)(cpu->eax) <= *(uint32_t*)(cpu->esi + 0x1Cu)) goto label_00036F63;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_00036F53:
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_00036F5A;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->eax;
    goto label_00036F63;
    label_00036F5A:
    --cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)*(uint32_t*)(cpu->esi + 0x1Cu)) goto label_00036F63;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->eax;
    label_00036F63:
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esi)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; *(uint32_t*)(cpu->esi) = v; }
    cpu->eax = *(uint32_t*)(cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00036F88;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = (int8_t)(*(uint8_t*)(cpu->eax + cpu->ecx));
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = 1u;
    *(uint32_t*)(cpu->esi) = 0x10u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00036F88:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(0xFu), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00036FA4;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = *(uint32_t*)(cpu->ecx + cpu->eax);
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = 4u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00036FA4:
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = 0xCu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436FD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax <<= 5u;
    cpu->ecx = *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.source_id));
    cpu->edx = *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.range_begin));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x10u);
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0x1Cu) = cpu->ecx;
    cpu->ecx = 1u;
    *(uint32_t*)(cpu->eax + 8u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    *(uint32_t*)(cpu->eax) = (uint64_t)(*(uint32_t*)(cpu->eax)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    *(uint32_t*)(cpu->eax + 4u) = 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437020(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = (uint32_t)(cpu->ecx + 0xFFFFFFFEu);
    cpu->eax <<= 5u;
    cpu->edx = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx <<= 5u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->eax)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037049;
    cpu->edx = *(uint32_t*)(cpu->edx + 0x14u);
    *(uint32_t*)(cpu->eax + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->eax + 0x14u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    goto label_00037052;
    label_00037049:
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax + 0x14u)));
    *(float*)(cpu->eax + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00037052:
    cpu->edx = 1u;
    cpu->ecx -= cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edx;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437070(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = (uint32_t)(cpu->ecx + 0xFFFFFFFEu);
    cpu->eax <<= 5u;
    cpu->edx = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx <<= 5u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->eax)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037099;
    cpu->edx = *(uint32_t*)(cpu->edx + 0x14u);
    *(uint32_t*)(cpu->eax + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->eax + 0x14u)) - (uint64_t)(cpu->edx) - (uint64_t)(0u);
    goto label_000370A2;
    label_00037099:
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->edx + 0x14u)));
    *(float*)(cpu->eax + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000370A2:
    cpu->edx = 1u;
    cpu->ecx -= cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edx;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004370C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = (uint32_t)(cpu->ecx + 0xFFFFFFFEu);
    cpu->eax <<= 5u;
    cpu->edx = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx <<= 5u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->eax)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000370ED;
    cpu->edx = *(uint32_t*)(cpu->edx + 0x14u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->eax + 0x14u));
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->edx;
    goto label_000370F6;
    label_000370ED:
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->eax + 0x14u)));
    *(float*)(cpu->eax + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000370F6:
    cpu->edx = 1u;
    cpu->ecx -= cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edx;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437120(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFFEu);
    cpu->ecx <<= 5u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edi <<= 5u;
    lift_divide_accumulator(cpu, *(uint32_t*)(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0])), 32u, 1u);
    cpu->eax = 1u;
    cpu->esi -= cpu->eax;
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->esi);
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx + 0x14u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 8u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0xCu) = cpu->eax;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437170(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFFEu);
    cpu->ecx <<= 5u;
    cpu->eax = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax <<= 5u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->ecx)), r=(uint64_t)(0x20u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000371A5;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(*(uint32_t*)(cpu->eax + 0x14u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    *(uint32_t*)(cpu->ecx + 0x14u) = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    goto label_000371C0;
    label_000371A5:
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x14u));
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x14u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000371BB;
    cpu->eax = 1u;
    goto label_000371BD;
    label_000371BB:
    cpu->eax = 0u;
    label_000371BD:
    *(uint32_t*)(cpu->ecx + 0x14u) = cpu->eax;
    label_000371C0:
    --cpu->esi;
    *(uint32_t*)(cpu->ecx + 8u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = 1u;
    *(uint32_t*)(cpu->ecx + 0xCu) = 1u;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->esi);
    *(uint32_t*)(cpu->ecx) = 0x10u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004371F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFFEu);
    cpu->ecx <<= 5u;
    cpu->eax = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax <<= 5u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->ecx)), r=(uint64_t)(0x20u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00037225;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(*(uint32_t*)(cpu->eax + 0x14u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    *(uint32_t*)(cpu->ecx + 0x14u) = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    goto label_00037240;
    label_00037225:
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x14u));
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x14u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0003723B;
    cpu->eax = 1u;
    goto label_0003723D;
    label_0003723B:
    cpu->eax = 0u;
    label_0003723D:
    *(uint32_t*)(cpu->ecx + 0x14u) = cpu->eax;
    label_00037240:
    --cpu->esi;
    *(uint32_t*)(cpu->ecx + 8u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = 1u;
    *(uint32_t*)(cpu->ecx + 0xCu) = 1u;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->esi);
    *(uint32_t*)(cpu->ecx) = 0x10u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437270(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFFEu);
    cpu->ecx <<= 5u;
    cpu->eax = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax <<= 5u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->ecx)), r=(uint64_t)(0x20u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000372A5;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(*(uint32_t*)(cpu->eax + 0x14u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u))) ? 1u : 0u) & 0xFFu);
    *(uint32_t*)(cpu->ecx + 0x14u) = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    goto label_000372C0;
    label_000372A5:
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x14u));
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x14u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000372BB;
    cpu->eax = 1u;
    goto label_000372BD;
    label_000372BB:
    cpu->eax = 0u;
    label_000372BD:
    *(uint32_t*)(cpu->ecx + 0x14u) = cpu->eax;
    label_000372C0:
    --cpu->esi;
    *(uint32_t*)(cpu->ecx + 8u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = 1u;
    *(uint32_t*)(cpu->ecx + 0xCu) = 1u;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->esi);
    *(uint32_t*)(cpu->ecx) = 0x10u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004372F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFFEu);
    cpu->ecx <<= 5u;
    cpu->eax = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax <<= 5u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->ecx)), r=(uint64_t)(0x20u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00037325;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(*(uint32_t*)(cpu->eax + 0x14u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u)) ? 1u : 0u) & 0xFFu);
    *(uint32_t*)(cpu->ecx + 0x14u) = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    goto label_00037340;
    label_00037325:
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x14u));
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x14u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0003733B;
    cpu->eax = 1u;
    goto label_0003733D;
    label_0003733B:
    cpu->eax = 0u;
    label_0003733D:
    *(uint32_t*)(cpu->ecx + 0x14u) = cpu->eax;
    label_00037340:
    --cpu->esi;
    *(uint32_t*)(cpu->ecx + 8u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = 1u;
    *(uint32_t*)(cpu->ecx + 0xCu) = 1u;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->esi);
    *(uint32_t*)(cpu->ecx) = 0x10u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437370(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFFEu);
    cpu->ecx <<= 5u;
    cpu->eax = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax <<= 5u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->ecx)), r=(uint64_t)(0x20u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000373A5;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(*(uint32_t*)(cpu->eax + 0x14u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) ? 1u : 0u) & 0xFFu);
    *(uint32_t*)(cpu->ecx + 0x14u) = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    goto label_000373C0;
    label_000373A5:
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x14u));
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x14u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000373BB;
    cpu->eax = 1u;
    goto label_000373BD;
    label_000373BB:
    cpu->eax = 0u;
    label_000373BD:
    *(uint32_t*)(cpu->ecx + 0x14u) = cpu->eax;
    label_000373C0:
    --cpu->esi;
    *(uint32_t*)(cpu->ecx + 8u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = 1u;
    *(uint32_t*)(cpu->ecx + 0xCu) = 1u;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->esi);
    *(uint32_t*)(cpu->ecx) = 0x10u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004373F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFFEu);
    cpu->ecx <<= 5u;
    cpu->eax = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax <<= 5u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->ecx)), r=(uint64_t)(0x20u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00037425;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(*(uint32_t*)(cpu->eax + 0x14u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u))) ? 1u : 0u) & 0xFFu);
    *(uint32_t*)(cpu->ecx + 0x14u) = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    goto label_00037440;
    label_00037425:
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x14u));
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x14u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_0003743B;
    cpu->eax = 1u;
    goto label_0003743D;
    label_0003743B:
    cpu->eax = 0u;
    label_0003743D:
    *(uint32_t*)(cpu->ecx + 0x14u) = cpu->eax;
    label_00037440:
    --cpu->esi;
    *(uint32_t*)(cpu->ecx + 8u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = 1u;
    *(uint32_t*)(cpu->ecx + 0xCu) = 1u;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->esi);
    *(uint32_t*)(cpu->ecx) = 0x10u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax <<= 5u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0]))), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037495;
    --g_sfera_mbc_runtime->value_stack_size;
    g_sfera_mbc_runtime->instruction_cursor += 2u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00037495:
    *(uint32_t*)(cpu->eax) = 0x10u;
    cpu->ecx = 1u;
    *(uint32_t*)(cpu->eax + 8u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = (int16_t)(*(uint16_t*)(cpu->eax));
    cpu->eax += cpu->ecx;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004374C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax <<= 5u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0]))), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000374E5;
    --g_sfera_mbc_runtime->value_stack_size;
    g_sfera_mbc_runtime->instruction_cursor += 2u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000374E5:
    *(uint32_t*)(cpu->eax) = 0x10u;
    cpu->ecx = 1u;
    *(uint32_t*)(cpu->eax + 8u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = (int16_t)(*(uint16_t*)(cpu->eax));
    cpu->eax += cpu->ecx;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax <<= 5u;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    cpu->ecx = 1u;
    *(uint32_t*)(cpu->eax + 8u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    *(uint32_t*)(cpu->eax) = 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437540(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax <<= 5u;
    cpu->ecx = *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0x10u)) goto label_0003755E;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_0003758B;
    label_0003755E:
    cpu->edx = 1u;
    *(uint32_t*)(cpu->eax + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->eax + 0x14u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x14u);
    if (*(uint32_t*)(cpu->eax + 4u) != (uint32_t)(cpu->edx)) goto label_0003757E;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax + 0x14u)) & 0xFFu);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    *(uint8_t*)(cpu->eax + cpu->ecx) = cpu->edx & 0xFFu;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003757E:
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->eax + cpu->edx) = cpu->ecx;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003758B:
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x14u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (1.0);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    *(float*)(cpu->eax + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->edx + cpu->ecx) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004375B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax <<= 5u;
    cpu->ecx = *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0x10u)) goto label_000375CE;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000375F7;
    label_000375CE:
    *(uint32_t*)(cpu->eax + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->eax + 0x14u)) - 1u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->eax + 4u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x14u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000375EA;
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax + 0x14u)) & 0xFFu);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    *(uint8_t*)(cpu->eax + cpu->ecx) = cpu->edx & 0xFFu;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000375EA:
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->eax + cpu->edx) = cpu->ecx;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000375F7:
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x14u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (1.0);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    *(float*)(cpu->eax + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->edx + cpu->ecx) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437620(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax <<= 5u;
    cpu->ecx = *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0x10u)) goto label_0003763E;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_00037664;
    label_0003763E:
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->eax + 4u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037656;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax + 0x14u)) & 0xFFu);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) + 1u)) & 0xFFu);
    *(uint8_t*)(cpu->eax + cpu->edx) = cpu->ecx & 0xFFu;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00037656:
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x14u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    ++cpu->ecx;
    *(uint32_t*)(cpu->eax + cpu->edx) = cpu->ecx;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00037664:
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x14u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (1.0);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    *(float*)(cpu->edx + cpu->ecx) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437690(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax <<= 5u;
    cpu->ecx = *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0x10u)) goto label_000376AE;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000376D4;
    label_000376AE:
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->eax + 4u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000376C6;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax + 0x14u)) & 0xFFu);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) - 1u)) & 0xFFu);
    *(uint8_t*)(cpu->eax + cpu->edx) = cpu->ecx & 0xFFu;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000376C6:
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x14u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    --cpu->ecx;
    *(uint32_t*)(cpu->eax + cpu->edx) = cpu->ecx;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000376D4:
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x14u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_x87_push(cpu, 1.0);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->fpu[1u] = (cpu->fpu[1u]) - (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    *(float*)(cpu->eax + 0x14u) = cpu->fpu[0u];
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    *(float*)(cpu->edx + cpu->ecx) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437700(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->current_instruction_address;
    cpu->eax -= g_sfera_mbc_runtime->bytecode_base;
    cpu->ecx = g_sfera_mbc_runtime->process_index;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x437718u)); sfera_sub_00421710(cpu, LIFT_CODE_TOKEN_VA(0x437718u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43771Fu)); sfera_sub_00421720(cpu, LIFT_CODE_TOKEN_VA(0x43771Fu));
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = *(uint8_t*)(cpu->eax);
    ++cpu->eax;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    g_sfera_mbc_runtime->argument_end = (uint32_t)(cpu->eax);
    cpu->eax -= g_sfera_mbc_runtime->argument_count;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->eax);
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->eax);
    sfera_mbinter_execute_opcode(cpu, stop_address, cpu->ecx);
    return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437750(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_mbc_runtime->execution_failed = (uint32_t)(1u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437760(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax <<= 5u;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0]))))));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    *(uint32_t*)(cpu->eax) = 0x20u;
    *(float*)(cpu->eax + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437780(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFFFFFFEu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax <<= 5u;
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->eax + 0x14u)))));
    *(uint32_t*)(cpu->eax) = 0x20u;
    *(float*)(cpu->eax + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004377A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = (uint32_t)(cpu->ecx + 0xFFFFFFFEu);
    cpu->ecx <<= 5u;
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax <<= 5u;
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    cpu->ecx = 8u;
    cpu->esi = cpu->eax;
    cpu->edi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = 8u;
    cpu->esi = (uint32_t)(cpu->edx + 0xFFFFFFE0u);
    cpu->edi = cpu->eax;
    lift_movs32(cpu, 1u);
    cpu->ecx = 8u;
    cpu->esi = cpu->edx;
    cpu->edi = (uint32_t)(cpu->edx + 0xFFFFFFE0u);
    lift_movs32(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004377F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->eax);
    cpu->edx = *(uint16_t*)(cpu->ecx);
    cpu->eax <<= 5u;
    cpu->ecx += 2u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0];
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->edx);
    *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0])) = (uint64_t)(*(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0]))) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.source_id)) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.range_end)) = 1u;
    *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.range_begin)) = 1u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->eax);
    cpu->edx = *(uint16_t*)(cpu->ecx);
    cpu->eax <<= 5u;
    cpu->ecx += 2u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0];
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->edx);
    *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0])) = (uint64_t)(*(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0]))) - (uint64_t)(cpu->ecx) - (uint64_t)(0u);
    *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.source_id)) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.range_end)) = 1u;
    *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.range_begin)) = 1u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437890(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->esi <<= 5u;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0])));
    cpu->esi = (uint32_t)(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4378ABu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4378ABu));
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esi) = 0x10u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004378C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xFFFFFFFEu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->esi <<= 5u;
    cpu->esi += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x14u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4378DBu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4378DBu));
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esi) = 0x10u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004378F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->edx = *(uint16_t*)(cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax <<= 5u;
    *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0])) = (uint64_t)(*(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0]))) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    cpu->ecx += 2u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->edx + cpu->eax) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437930(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->edx = *(uint16_t*)(cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax <<= 5u;
    *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0])) = (uint64_t)(*(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0]))) - (uint64_t)(cpu->edx) - (uint64_t)(0u);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    cpu->ecx += 2u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->edx + cpu->eax) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->edx = *(uint16_t*)(cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax <<= 5u;
    cpu->ecx += 2u;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x14u);
    cpu->ecx += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->eax + cpu->edx) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004379B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->edx = *(uint16_t*)(cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax <<= 5u;
    cpu->ecx += 2u;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x14u);
    cpu->ecx -= cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    *(uint32_t*)(cpu->eax + cpu->edx) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004379F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->edx = (uint32_t)(cpu->eax + 0xFFFFFFFEu);
    cpu->ecx = 0x10u;
    cpu->edx <<= 5u;
    cpu->eax <<= 5u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].type = (uint32_t)(cpu->ecx);
    *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type)) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437A10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->active_process;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->eax + 0xA4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    cpu->edi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037A63;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xB4u);
    { uint64_t x=(uint64_t)(cpu->ecx), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->ecx = v; }
    cpu->ecx = (uint64_t)(cpu->ecx) - (uint64_t)(cpu->ecx) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->ecx &= 0xFFFF3CBAu;
    cpu->ecx += 0xC350u;
    *(uint32_t*)(cpu->eax + 0xACu) = cpu->ecx;
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->ecx = *(uint32_t*)(cpu->edx + 0xACu);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x1936u);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x437A61u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x437A61u));
    goto label_00037AB3;
    label_00037A63:
    cpu->edx = *(uint32_t*)(cpu->eax + 0xA8u);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)*(uint32_t*)(cpu->eax + 0xACu)) goto label_00037AC4;
    if (*(uint32_t*)(cpu->eax + 0xB4u) != (uint32_t)(0u)) goto label_00037A86;
    *(uint32_t*)(cpu->eax + 0xACu) = (uint64_t)(*(uint32_t*)(cpu->eax + 0xACu)) + (uint64_t)(0x2710u) + (uint64_t)(0u);
    goto label_00037A8D;
    label_00037A86:
    *(uint32_t*)(cpu->eax + 0xACu) = (uint64_t)(*(uint32_t*)(cpu->eax + 0xACu)) + (uint64_t)(0xAu) + (uint64_t)(0u);
    label_00037A8D:
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xACu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xA4u);
    cpu->edx += cpu->edx;
    lift_push32(cpu, 0x193Bu);
    cpu->edx += cpu->edx;
    lift_push32(cpu, (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp");
    cpu->edx += cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x37AB3u)); sfera_sub_004EBE80(cpu, LIFT_CODE_TOKEN_RVA(0x37AB3u));
    label_00037AB3:
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    *(uint32_t*)(cpu->ecx + 0xA4u) = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->active_process;
    label_00037AC4:
    cpu->edx = *(uint32_t*)(cpu->eax + 0xA8u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0xA4u);
    *(uint32_t*)(cpu->eax + ((uint32_t)(cpu->edx) * 8u)) = cpu->edi;
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xA8u);
    cpu->edx = *(uint32_t*)(cpu->eax + 0xA4u);
    *(uint32_t*)(cpu->edx + ((uint32_t)(cpu->ecx) * 8u) + 4u) = cpu->esi;
    cpu->eax = g_sfera_mbc_runtime->active_process;
    *(uint32_t*)(cpu->eax + 0xA8u) = (uint64_t)(*(uint32_t*)(cpu->eax + 0xA8u)) + 1u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437B00(LiftCpu* cpu, uint32_t stop_address) {
    sfera_sub_00437A10(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437B10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->ebx) != 0u) goto label_00037B22;
    cpu->ebx = g_sfera_mbc_runtime->active_process;
    label_00037B22:
    cpu->esi = *(uint32_t*)(cpu->ebx + 0xA8u);
    cpu->ebp = *(uint32_t*)(cpu->ebx + 0xA4u);
    cpu->eax = 0u;
    cpu->edi = cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00037B70;
    label_00037B36:
    if (*(uint32_t*)(cpu->edi) != (uint32_t)(cpu->ecx)) goto label_00037B3F;
    if (*(uint32_t*)(cpu->edi + 4u) == (uint32_t)(cpu->edx)) goto label_00037B54;
    label_00037B3F:
    ++cpu->eax;
    cpu->edi += 8u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->esi)) goto label_00037B36;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 0xA8u) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00037B54:
    cpu->ecx = cpu->esi;
    cpu->ecx -= cpu->eax;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ecx) * 8u) + 0xFFFFFFF8u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->eax) * 8u) + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x437B66u));
    cpu->esp += 0xCu;
    --cpu->esi;
    label_00037B70:
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 0xA8u) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437B80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = g_sfera_mbc_runtime->active_process;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->ebx + 0xA4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebx + 0xA8u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00037BD8;
    cpu->edi = cpu->edi;
    label_00037BA0:
    if (*(uint32_t*)(cpu->edi) != (uint32_t)(cpu->ecx)) goto label_00037BA9;
    if (*(uint32_t*)(cpu->edi + 4u) == (uint32_t)(cpu->edx)) goto label_00037BBC;
    label_00037BA9:
    ++cpu->eax;
    cpu->edi += 8u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->esi)) goto label_00037BA0;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 0xA8u) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00037BBC:
    cpu->ecx = cpu->esi;
    cpu->ecx -= cpu->eax;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ecx) * 8u) + 0xFFFFFFF8u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->eax) * 8u) + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x437BCEu));
    cpu->esp += 0xCu;
    --cpu->esi;
    label_00037BD8:
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 0xA8u) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437BF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    *(uint32_t*)(cpu->esp) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp)))));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    cpu->fpu[0u] = fabs(cpu->fpu[0u]);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    lift_x87_compare(cpu, cpu->fpu[0u], 120.0);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_00037C41;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00037C41:
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037C50;
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    goto label_00037C55;
    label_00037C50:
    cpu->ecx = 1u;
    label_00037C55:
    cpu->fpu[0u] = (cpu->fpu[0u]) + (40.0);
    cpu->ecx <<= 11u;
    lift_x87_push(cpu, 1.0);
    cpu->fpu[1u] = cpu->fpu[0u] / cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    lift_x87_push(cpu, (double)0.0062500000931322575f); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint16_t*)(cpu->esp + 0xCu) = cpu->fpu_control;
    cpu->fpu[0u] = (((double)g_sfera_recovered_static_runtime.inverse_40)) - (cpu->fpu[0u]);
    cpu->eax = *(uint16_t*)(cpu->esp + 0xCu);
    cpu->eax |= 0xC00u;
    *(uint32_t*)(cpu->esp) = cpu->eax;
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (2047.0);
    cpu->fpu_control = *(uint16_t*)(cpu->esp);
    *(uint64_t*)(cpu->esp) = lift_x87_round(cpu, cpu->fpu[0u], 0u);
    lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp);
    cpu->eax |= cpu->ecx;
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0xCu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437CB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->edx;
    cpu->esi = cpu->ecx;
    cpu->ecx = 0u;
    { uint64_t v=(uint64_t)(cpu->ebp); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00037CC0;
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    label_00037CC0:
    cpu->eax = cpu->ecx;
    cpu->eax = (uint32_t)((int32_t)(cpu->eax) >> 3u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((uint8_t)((uint8_t)((cpu->edx & 0xFFu)) << (((cpu->ecx & 0xFFu)) & 31u))) & 0xFFu);
    lift_push32(cpu, cpu->edi);
    cpu->esi += cpu->eax;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    cpu->edi = 2u;
    label_00037CE1:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00037CE9;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00037CEF;
    label_00037CE9:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00037CEF:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037CF6;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00037CF6:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037CFD;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00037CFD:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00037D05;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00037D0B;
    label_00037D05:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00037D0B:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037D12;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00037D12:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037D19;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00037D19:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00037D21;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00037D27;
    label_00037D21:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00037D27:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037D2E;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00037D2E:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037D35;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00037D35:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00037D3D;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00037D43;
    label_00037D3D:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00037D43:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037D4A;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00037D4A:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037D51;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00037D51:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00037D59;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00037D5F;
    label_00037D59:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00037D5F:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037D66;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00037D66:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037D6D;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00037D6D:
    if ((uint8_t)((*(uint8_t*)(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00037D75;
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu));
    goto label_00037D7B;
    label_00037D75:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax) = (uint64_t)(*(uint8_t*)(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu));
    label_00037D7B:
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037D82;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00037D82:
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037D89;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00037D89:
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037CE1;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_00037D9A;
    *(uint32_t*)(cpu->ebp) = (uint64_t)(*(uint32_t*)(cpu->ebp)) + (uint64_t)(0xCu) + (uint64_t)(0u);
    label_00037D9A:
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_x87_push(cpu, (double)*(float*)((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.inverse_40));
    lift_x87_push(cpu, (double)0.0062500000931322575f);
    cpu->ecx = cpu->eax;
    lift_x87_push(cpu, cpu->fpu[0u]);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x7FFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u)))));
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00037DC6;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_00037DC6:
    cpu->fpu[0u] = (cpu->fpu[0u]) / (2047.0);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    lift_x87_push(cpu, 1.0);
    cpu->fpu[1u] = cpu->fpu[0u] / cpu->fpu[1u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (40.0);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp));
    if ((uint32_t)((cpu->eax) & (0x800u)) == 0u) goto label_00037DF1;
    cpu->fpu[0u] = -cpu->fpu[0u];
    label_00037DF1:
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp)));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437E10(LiftCpu* cpu, uint32_t stop_address) {
    sfera_sub_00433960(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437E20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->named_vector_count;
    lift_push32(cpu, cpu->edi);
    cpu->ebx = 0u;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->named_vectors[0];
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    cpu->ebp = cpu->ecx;
    g_sfera_mbc_runtime->named_vector_cursor = (uint32_t)(cpu->edi);
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00037E7E;
    label_00037E42:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xCu);
    cpu->eax = cpu->ebp;
    label_00037E47:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(*(uint8_t*)(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037E67;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_00037E63;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(*(uint8_t*)(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037E67;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00037E47;
    label_00037E63:
    cpu->eax = 0u;
    goto label_00037E6C;
    label_00037E67:
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_00037E6C:
    if ((uint32_t)(cpu->eax) == 0u) goto label_00037EE4;
    cpu->edi += 0x10u;
    ++cpu->ebx;
    g_sfera_mbc_runtime->named_vector_cursor = (uint32_t)(cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->esi)) goto label_00037E42;
    label_00037E7E:
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0x3E8u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_00037F4F;
    cpu->eax = cpu->esi;
    cpu->eax <<= 4u;
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->named_vectors[0]);
    g_sfera_mbc_runtime->named_vector_cursor = (uint32_t)(cpu->eax);
    ++cpu->esi;
    cpu->eax = cpu->ebp;
    g_sfera_mbc_runtime->named_vector_count = (uint32_t)(cpu->esi);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00037EA5:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00037EA5;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, 0x35FEu);
    cpu->ecx = (uint32_t)(cpu->eax + 1u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x437EC0u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x437EC0u));
    cpu->ecx = g_sfera_mbc_runtime->named_vector_cursor;
    *(uint32_t*)(cpu->ecx + 0xCu) = cpu->eax;
    cpu->edx = g_sfera_mbc_runtime->named_vector_cursor;
    cpu->edx = *(uint32_t*)(cpu->edx + 0xCu);
    cpu->ecx = cpu->ebp;
    label_00037ED4:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->ecx)) & 0xFFu);
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00037ED4;
    cpu->edi = g_sfera_mbc_runtime->named_vector_cursor;
    label_00037EE4:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    if ((int32_t)*(uint32_t*)(cpu->edi + 4u) > (int32_t)(uint32_t)(cpu->esi)) goto label_00037F46;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    lift_push32(cpu, 0x3603u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp");
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi) * 4u) + 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x437F05u)); sfera_sub_004EBE80(cpu, LIFT_CODE_TOKEN_VA(0x437F05u));
    cpu->ecx = g_sfera_mbc_runtime->named_vector_cursor;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->edx = g_sfera_mbc_runtime->named_vector_cursor;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->esi)) goto label_00037F34;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00037F20:
    cpu->ecx = g_sfera_mbc_runtime->named_vector_cursor;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->edx + ((uint32_t)(cpu->eax) * 4u)) = 0u;
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->esi)) goto label_00037F20;
    label_00037F34:
    cpu->ecx = g_sfera_mbc_runtime->named_vector_cursor;
    cpu->eax = (uint32_t)(cpu->esi + 1u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    cpu->edi = g_sfera_mbc_runtime->named_vector_cursor;
    label_00037F46:
    cpu->edx = *(uint32_t*)(cpu->edi);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->edx + ((uint32_t)(cpu->esi) * 4u)) = cpu->eax;
    label_00037F4F:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437F60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    cpu->edx = cpu->ecx;
    cpu->ecx = g_sfera_mbc_runtime->named_vector_count;
    lift_push32(cpu, cpu->edi);
    cpu->ebp = 0u;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->named_vectors[0];
    g_sfera_mbc_runtime->named_vector_cursor = (uint32_t)(cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_00037FBE;
    label_00037F82:
    cpu->esi = *(uint32_t*)(cpu->edi + 0xCu);
    cpu->eax = cpu->edx;
    label_00037F87:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->ebx & 0xFFu)), r=(uint64_t)(*(uint8_t*)(cpu->esi)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037FA7;
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_00037FA3;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->ebx & 0xFFu)), r=(uint64_t)(*(uint8_t*)(cpu->esi + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037FA7;
    cpu->eax += 2u;
    cpu->esi += 2u;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != 0u) goto label_00037F87;
    label_00037FA3:
    cpu->eax = 0u;
    goto label_00037FAC;
    label_00037FA7:
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_00037FAC:
    if ((uint32_t)(cpu->eax) == 0u) goto label_00037FC6;
    ++cpu->ebp;
    cpu->edi += 0x10u;
    g_sfera_mbc_runtime->named_vector_cursor = (uint32_t)(cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(cpu->ecx)) goto label_00037F82;
    label_00037FBE:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00037FC6:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00037FD7;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00037FD7:
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)*(uint32_t*)(cpu->edi + 4u)) goto label_00037FBE;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->eax = *(uint32_t*)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437FF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esi + 0xB0u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00038020;
    lift_push32(cpu, 0x3822u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = 0x80u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x438015u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x438015u));
    *(uint32_t*)(cpu->esi + 0xB0u) = cpu->eax;
    *(uint8_t*)(cpu->eax) = 0u;
    goto label_00038024;
    label_00038020:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    label_00038024:
    cpu->ecx = cpu->ebp;
    cpu->esi = (uint32_t)(cpu->ecx + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00038030:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00038030;
    cpu->ecx -= cpu->esi;
    cpu->esi = cpu->ecx;
    cpu->ecx = cpu->eax;
    cpu->edi = (uint32_t)(cpu->ecx + 1u);
    label_00038040:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00038040;
    cpu->ecx -= cpu->edi;
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->esi + 4u);
    if ((int32_t)(uint32_t)(cpu->ecx) > (int32_t)(uint32_t)(0x7Fu)) goto label_00038098;
    cpu->ecx = (uint32_t)(cpu->eax + 0xFFFFFFFFu);
    label_00038055:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->ecx + 1u)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00038055;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x0A0D)) & 0xFFFFu);
    *(uint16_t*)(cpu->ecx) = cpu->edx & 0xFFFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(((uint32_t)(uintptr_t)"\r\n") + 2u)) & 0xFFu);
    *(uint8_t*)(cpu->ecx + 2u) = cpu->edx & 0xFFu;
    cpu->ecx = cpu->ebp;
    cpu->esi = cpu->ebp;
    label_00038074:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00038074;
    cpu->ecx -= cpu->esi;
    cpu->edx = cpu->ecx;
    cpu->edi = (uint32_t)(cpu->eax + 0xFFFFFFFFu);
    label_00038082:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->eax & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00038082;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 2u;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->edx;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    label_00038098:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004380A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ecx;
    cpu->esi = cpu->ebp;
    lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->eax + 4u);
    cpu->esi -= cpu->eax;
    cpu->edi = 0x96u;
    label_000380B5:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->esi + cpu->edx)) & 0xFFu);
    *(uint8_t*)(cpu->edx) = cpu->ecx & 0xFFu;
    ++cpu->edx;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000380B5;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->ebp + 0x9Au)) & 0xFFu);
    *(uint8_t*)(cpu->eax + 0x9Au) = cpu->edx & 0xFFu;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x9Cu));
    *(float*)(cpu->eax + 0x9Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0xA0u));
    cpu->esi = lift_pop32(cpu);
    *(float*)(cpu->eax + 0xA0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0xA4u));
    cpu->ebp = lift_pop32(cpu);
    *(float*)(cpu->eax + 0xA4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00438100(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFF9u)) goto label_0003811B;
    lift_push32(cpu, (uint32_t)(uintptr_t)"~~~~~ItemList~~~FIND ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x438114u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x438114u));
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0003811B:
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0003813F;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0xD0u);
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xD4u);
    cpu->edx = (uint32_t)(cpu->eax + cpu->ecx + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)" FindItem 'OK' = ''%s''\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43813Cu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x43813Cu));
    cpu->esp += 8u;
    label_0003813F:
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_00038151;
    lift_push32(cpu, (uint32_t)(uintptr_t)" FindItem = 'ERROR'\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43814Eu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x43814Eu));
    cpu->esp += 4u;
    label_00038151:
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00438160(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFF9u)) goto label_0003817B;
    lift_push32(cpu, (uint32_t)(uintptr_t)"~~~~~ItemList~~~FIND NEXT ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x438174u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x438174u));
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0003817B:
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0003819F;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0xD0u);
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1BCu);
    cpu->edx = (uint32_t)(cpu->eax + cpu->ecx + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)" FindNextItem 'OK' = ''%s''\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43819Cu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x43819Cu));
    cpu->esp += 8u;
    label_0003819F:
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_000381B1;
    lift_push32(cpu, (uint32_t)(uintptr_t)" FindNextItem = 'ERROR'\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4381AEu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x4381AEu));
    cpu->esp += 4u;
    label_000381B1:
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004381C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFF9u)) goto label_000381DB;
    lift_push32(cpu, (uint32_t)(uintptr_t)"~~~~~ItemList~~~FIND ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4381D4u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x4381D4u));
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000381DB:
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_000381FF;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0xD0u);
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1BCu);
    cpu->edx = (uint32_t)(cpu->eax + cpu->ecx + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)" FindItem 'OK' = ''%s''\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4381FCu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x4381FCu));
    cpu->esp += 8u;
    label_000381FF:
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_00038211;
    lift_push32(cpu, (uint32_t)(uintptr_t)" FindItem = 'ERROR'\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43820Eu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x43820Eu));
    cpu->esp += 4u;
    label_00038211:
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00438220(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->edi);
    *(uint16_t*)(cpu->ecx + 0x42u) = cpu->eax & 0xFFFFu;
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00038271;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->esp + 0x1Cu)) & 0xFFu);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00038240:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax + cpu->edi)) & 0xFFu);
    { uint64_t v=(uint64_t)((cpu->ebx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00038250;
    cpu->edx = cpu->edx & 0xFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->edx]) & 0xFFu);
    label_00038250:
    cpu->ebp = *(uint32_t*)(cpu->ecx + 0x10u);
    *(uint8_t*)(cpu->eax + cpu->ebp) = cpu->edx & 0xFFu;
    cpu->ebp = (cpu->ebp & 0xFFFF0000u) | ((uint32_t)(*(uint16_t*)(cpu->ecx + 0x42u)) & 0xFFFFu);
    cpu->edx = cpu->edx & 0xFFu;
    cpu->ebp = (cpu->ebp & 0xFFFF0000u) | ((uint32_t)((uint16_t)((uint16_t)((cpu->ebp & 0xFFFFu)) >> 1u)) & 0xFFFFu);
    cpu->ebp = (cpu->ebp & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->ebp & 0xFFFFu)) + (uint64_t)(g_sfera_string_lookup_runtime.hash_mix[(uint8_t)cpu->edx]) + (uint64_t)(0u))) & 0xFFFFu);
    ++cpu->eax;
    *(uint16_t*)(cpu->ecx + 0x42u) = cpu->ebp & 0xFFFFu;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->esi)) goto label_00038240;
    label_00038271:
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(*(uint16_t*)(cpu->ecx + 0x20u)) & 0xFFFFu);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFFFu)) - 1u)) & 0xFFFFu);
    *(uint16_t*)(cpu->ecx + 0x42u) = (uint64_t)(*(uint16_t*)(cpu->ecx + 0x42u)) & (uint64_t)((cpu->eax & 0xFFFFu));
    cpu->edx = *(uint16_t*)(cpu->ecx + 0x42u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x18u);
    cpu->eax = *(uint16_t*)(cpu->eax + ((uint32_t)(cpu->edx) * 2u));
    cpu->edx = *(uint16_t*)(cpu->ecx + 0x1Cu);
    *(uint16_t*)(cpu->ecx + 0x34u) = cpu->eax & 0xFFFFu;
    if ((uint16_t)((cpu->eax & 0xFFFFu)) == (uint16_t)((cpu->edx & 0xFFFFu))) goto label_00038375;
    cpu->ebx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ebx);
    cpu->eax += *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->ecx + 0x3Cu) = 0u;
    *(uint32_t*)(cpu->ecx + 0x38u) = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(*(uint16_t*)(cpu->eax + 8u)) & 0xFFFFu);
    *(uint16_t*)(cpu->ecx + 0x40u) = cpu->eax & 0xFFFFu;
    label_000382B2:
    cpu->ebp = *(uint32_t*)(cpu->ecx + 0x38u);
    if (*(uint32_t*)(cpu->ebp + 4u) != (uint32_t)(cpu->esi)) goto label_0003830C;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x18u)), r=(uint64_t)(4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->edi = (uint32_t)(cpu->ebp + 0xAu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000382E4;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000382D0:
    cpu->edx = *(uint32_t*)(cpu->edi);
    if ((uint32_t)(cpu->edx) != *(uint32_t*)(cpu->esi)) goto label_00038308;
    cpu->eax -= 4u;
    cpu->esi += 4u;
    cpu->edi += 4u;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(4u)) goto label_000382D0;
    label_000382E4:
    if ((uint32_t)(cpu->eax) == 0u) goto label_0003833A;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != *(uint8_t*)(cpu->edi)) goto label_00038308;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(1u)) goto label_0003833A;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->esi + 1u)) & 0xFFu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != *(uint8_t*)(cpu->edi + 1u)) goto label_00038308;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(2u)) goto label_0003833A;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->esi + 2u)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == *(uint8_t*)(cpu->edi + 2u)) goto label_0003833A;
    label_00038308:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    label_0003830C:
    cpu->edx = *(uint16_t*)(cpu->ecx + 0x40u);
    cpu->eax = *(uint16_t*)(cpu->ecx + 0x1Cu);
    if ((uint16_t)((cpu->edx & 0xFFFFu)) == (uint16_t)((cpu->eax & 0xFFFFu))) goto label_00038375;
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edi = cpu->edx;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(cpu->ebx);
    cpu->eax += cpu->edi;
    *(uint32_t*)(cpu->ecx + 0x3Cu) = cpu->ebp;
    *(uint32_t*)(cpu->ecx + 0x38u) = cpu->eax;
    *(uint16_t*)(cpu->ecx + 0x34u) = cpu->edx & 0xFFFFu;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(*(uint16_t*)(cpu->eax + 8u)) & 0xFFFFu);
    *(uint16_t*)(cpu->ecx + 0x40u) = cpu->edx & 0xFFFFu;
    goto label_000382B2;
    label_0003833A:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x3Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0003836A;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(*(uint16_t*)(cpu->ebp + 8u)) & 0xFFFFu);
    *(uint16_t*)(cpu->eax + 8u) = cpu->edx & 0xFFFFu;
    cpu->eax = *(uint16_t*)(cpu->ecx + 0x42u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x18u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(*(uint16_t*)(cpu->edx + ((uint32_t)(cpu->eax) * 2u))) & 0xFFFFu);
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x38u);
    *(uint16_t*)(cpu->esi + 8u) = cpu->eax & 0xFFFFu;
    cpu->edx = *(uint16_t*)(cpu->ecx + 0x42u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x18u);
    cpu->esi = (cpu->esi & 0xFFFF0000u) | ((uint32_t)(*(uint16_t*)(cpu->ecx + 0x34u)) & 0xFFFFu);
    *(uint16_t*)(cpu->eax + ((uint32_t)(cpu->edx) * 2u)) = cpu->esi & 0xFFFFu;
    label_0003836A:
    cpu->eax = *(uint16_t*)(cpu->ecx + 0x34u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00038375:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00438380(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFF9u)) goto label_00038399;
    lift_push32(cpu, (uint32_t)(uintptr_t)"~~~~~ItemList~~~DEL ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x438393u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x438393u));
    cpu->esp += 4u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00038399:
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000383BE;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0xD0u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xD4u);
    cpu->edx = (uint32_t)(cpu->eax + cpu->ecx + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)" DelItem 'OK' = ''%s''\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4383B8u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x4383B8u));
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000383BE:
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000383D3;
    lift_push32(cpu, (uint32_t)(uintptr_t)" DelItem = CurItems Less Than CurMax\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4383CDu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x4383CDu));
    cpu->esp += 4u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000383D3:
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFEu)) goto label_000383E3;
    lift_push32(cpu, (uint32_t)(uintptr_t)" DelItem = 'ERROR' NOT DELETE\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4383E2u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x4383E2u));
    cpu->ecx = lift_pop32(cpu);
    label_000383E3:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004383F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFF9u)) goto label_00038409;
    lift_push32(cpu, (uint32_t)(uintptr_t)"~~~~~ItemList~~~DEL ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x438403u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x438403u));
    cpu->esp += 4u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00038409:
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0003842E;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0xD0u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1BCu);
    cpu->edx = (uint32_t)(cpu->eax + cpu->ecx + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)" DelItem 'OK' = ''%s''\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x438428u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x438428u));
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0003842E:
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_00038443;
    lift_push32(cpu, (uint32_t)(uintptr_t)" DelItem = CurItems Less Than CurMax\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43843Du)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x43843Du));
    cpu->esp += 4u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00038443:
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFEu)) goto label_00038453;
    lift_push32(cpu, (uint32_t)(uintptr_t)" DelItem = 'ERROR' NOT DELETE\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x438452u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x438452u));
    cpu->ecx = lift_pop32(cpu);
    label_00038453:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00438460(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = 1u;
    if ((uint8_t)(((*(uint8_t*)(void*)&g_sfera_cursor_manager_runtime.initialized_flags)) & ((cpu->eax & 0xFFu))) != 0u) goto label_000384BA;
    *(uint32_t*)((uint32_t)(uintptr_t)&g_sfera_cursor_manager_runtime.initialized_flags) = (uint64_t)(g_sfera_cursor_manager_runtime.initialized_flags) | (uint64_t)(cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_cursor_manager_runtime.object[0];
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4384A5u)); sfera_sub_004D79F0(cpu, LIFT_CODE_TOKEN_VA(0x4384A5u));
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA360));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4384AFu)); sfera_sub_004EE8C0(cpu, LIFT_CODE_TOKEN_VA(0x4384AFu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = 0xFFFFFFFFu;
    label_000384BA:
    cpu->eax = g_sfera_cursor_manager_runtime.active_cursor;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000384D2;
    cpu->ecx = (uint32_t)(uintptr_t)"CCursorManager::GetActiveCursor(): attempt to retrieve current cursor while one is not set";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4384CDu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x4384CDu));
    cpu->eax = g_sfera_cursor_manager_runtime.active_cursor;
    label_000384D2:
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004384F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    for (uint32_t object_index = 0u; object_index < UINT32_C(2100); ++object_index) {
        cpu->ecx = g_sfera_mbc_runtime->registered_objects[object_index];
        if (cpu->ecx != 0u) {
            lift_push32(cpu, 0x1C4u);
            cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
            lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43852Cu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x43852Cu));
            g_sfera_mbc_runtime->registered_objects[object_index] = 0u;
        }
    }
    { uint64_t l=(uint64_t)(g_sfera_inter_scalar_runtime.mode_02), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    g_sfera_mbc_runtime->registered_object_count = (uint32_t)(0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00038579;
    cpu->edx = 0x1CBu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43855Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x43855Fu));
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_02;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00038579;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x438570u)); sfera_sub_00430BC0(cpu, LIFT_CODE_TOKEN_VA(0x438570u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x438576u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x438576u));
    cpu->esp += 4u;
    label_00038579:
    cpu->edx = 0x1CDu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x438588u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x438588u));
    lift_push32(cpu, 0x20018u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x438592u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x438592u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000385B7;
    lift_push32(cpu, 0x834u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0x14u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4385B5u)); sfera_sub_00430F60(cpu, LIFT_CODE_TOKEN_VA(0x4385B5u));
    goto label_000385B9;
    label_000385B7:
    cpu->eax = 0u;
    label_000385B9:
    g_sfera_inter_scalar_runtime.mode_02 = (uint32_t)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004385D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4385D8u)); sfera_sub_00434D90(cpu, LIFT_CODE_TOKEN_VA(0x4385D8u));
    cpu->ecx = (uint32_t)(uintptr_t)"\n---exit_inter start---\nMBINTER MESSAGE:";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4385E2u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4385E2u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4385E9u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4385E9u));
    cpu->ecx = (uint32_t)(uintptr_t)"\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4385F3u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4385F3u));
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4385FDu)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4385FDu));
    cpu->ecx = (uint32_t)(uintptr_t)"---exit_inter end-----\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x438607u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x438607u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->process_index), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    g_sfera_mbc_runtime->execution_failed = (uint32_t)(1u);
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00038625;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x38625u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x38625u));
    label_00038625:
    cpu->edx = (uint32_t)(uintptr_t)"EError";
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0];
    sfera_sub_00435020(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00438640(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x104u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    cpu->eax = cpu->ecx;
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edx -= cpu->eax;
    label_00038660:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00038660;
    cpu->eax = cpu->esi;
    cpu->edx = cpu->esi;
    cpu->edi = cpu->edi;
    label_00038670:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00038670;
    cpu->edi = (uint32_t)(cpu->esp + 8u);
    cpu->eax -= cpu->edx;
    --cpu->edi;
    cpu->edi = cpu->edi;
    label_00038680:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00038680;
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 2u;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43869Fu)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x43869Fu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x104u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004386C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x3D8u;
    cpu->edx = (uint32_t)(cpu->esp + 0x394u);
    cpu->edx -= cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000386E0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->ecx)) & 0xFFu);
    *(uint8_t*)(cpu->edx + cpu->ecx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000386E0;
    cpu->eax = (uint32_t)(cpu->esp + 0x394u);
    --cpu->eax;
    label_000386F2:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000386F2;
    cpu->ecx = 0x63626D2Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = cpu->edx & 0xFFu;
    cpu->eax = (uint32_t)(cpu->esp + 0x394u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00038715:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00038715;
    cpu->eax -= cpu->edx;
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x24u)) goto label_0003873B;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0x3D8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003873B:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_inter_scalar_runtime.state_03;
    cpu->edx = (uint32_t)(cpu->esp + 0x3A8u);
    cpu->ebp = 0u;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x438761u)); sfera_sub_00489EF0(cpu, LIFT_CODE_TOKEN_VA(0x438761u));
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->ebp)) goto label_0003960B;
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0x10u)) goto label_0003960B;
    cpu->eax = 0u;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00038780:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->esp + cpu->eax + 0x3A0u)) & 0xFFu);
    *(uint8_t*)(cpu->esp + cpu->eax + 0x54u) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00038780;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0x10u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000388B1;
    cpu->edi = (uint32_t)(cpu->esi + 0x10u);
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_000387BA;
    label_000387AB:
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4387B2u));
    cpu->esp += 0xCu;
    label_000387BA:
    cpu->eax = *(uint8_t*)(cpu->esp + 0x54u);
    cpu->edx = *(uint8_t*)(cpu->esp + 0x56u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->ebx += cpu->edi;
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 2u) + 0xFFFFFDF0u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000388BB;
    cpu->edi = (uint32_t)(cpu->esi + 4u);
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_00038800;
    label_000387EE:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x8Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4387F8u));
    cpu->esp += 0xCu;
    label_00038800:
    cpu->ebx += cpu->edi;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000388C5;
    cpu->edi = (uint32_t)(cpu->esi + 4u);
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0003882E;
    label_0003881C:
    lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->esp + 0x90u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438826u));
    cpu->esp += 0xCu;
    label_0003882E:
    cpu->ebx += cpu->edi;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000388CF;
    cpu->edi = (uint32_t)(cpu->esi + 4u);
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0003885C;
    label_0003884A:
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x98u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438854u));
    cpu->esp += 0xCu;
    label_0003885C:
    cpu->ebx += cpu->edi;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000388D9;
    cpu->esi += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_00038884;
    label_00038872:
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0xA0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43887Cu));
    cpu->esp += 0xCu;
    label_00038884:
    cpu->edi = g_sfera_mbc_runtime->process_index;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x348u);
    cpu->ebx += cpu->esi;
    cpu->edi += ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0]);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    cpu->eax = 0u;
    cpu->ecx = (uint32_t)(cpu->edi + 0x30u);
    label_000388A1:
    if (*(uint16_t*)(cpu->ecx) == (uint16_t)((cpu->ebp & 0xFFFFu))) goto label_000388E0;
    ++cpu->eax;
    cpu->ecx += 2u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(8u)) goto label_000388A1;
    goto label_000388EA;
    label_000388B1:
    cpu->edi = 0x10u;
    goto label_000387AB;
    label_000388BB:
    cpu->edi = 4u;
    goto label_000387EE;
    label_000388C5:
    cpu->edi = 4u;
    goto label_0003881C;
    label_000388CF:
    cpu->edi = 4u;
    goto label_0003884A;
    label_000388D9:
    cpu->esi = 4u;
    goto label_00038872;
    label_000388E0:
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(*(uint16_t*)(cpu->esp + 0x40u)) & 0xFFFFu);
    *(uint16_t*)(cpu->edi + ((uint32_t)(cpu->eax) * 2u) + (uint32_t)offsetof(SferaMbcProcessRecord, module_key)) = cpu->edx & 0xFFFFu;
    label_000388EA:
    if ((uint32_t)(cpu->eax) != (uint32_t)(8u)) goto label_00038919;
    cpu->edx = (uint32_t)(cpu->esp + 0x58u);
    cpu->ecx = (uint32_t)(uintptr_t)"Cannot link a process - increase MAX_LINKED_PRCS! Linked prc: ";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4388FDu)); sfera_sub_00438640(cpu, LIFT_CODE_TOKEN_VA(0x4388FDu));
    cpu->eax |= 0xFFFFFFFFu;
    label_00038900:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x3D8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00038919:
    cpu->esi = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_size));
    cpu->eax = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size));
    cpu->ecx = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x80000003u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038932;
    --cpu->ecx;
    cpu->ecx |= 0xFFFFFFFCu;
    ++cpu->ecx;
    label_00038932:
    cpu->edx = 4u;
    cpu->edx -= cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x80000003u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038946;
    --cpu->edx;
    cpu->edx |= 0xFFFFFFFCu;
    ++cpu->edx;
    label_00038946:
    cpu->eax = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base));
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ecx;
    cpu->ecx = g_sfera_mbc_runtime->current_instruction_address;
    cpu->ecx -= cpu->eax;
    cpu->eax = *(uint16_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count));
    cpu->esi += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    if ((int16_t)(uint16_t)((cpu->eax & 0xFFFFu)) >= (int16_t)(uint16_t)(8u)) goto label_000389C0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x94u);
    cpu->eax = (int32_t)(int16_t)cpu->eax;
    *(uint32_t*)(cpu->edi + ((uint32_t)(cpu->eax) * 4u) + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_size)) = cpu->ecx;
    cpu->edx = (int16_t)(*(uint16_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count)));
    cpu->eax = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size));
    *(uint32_t*)(cpu->edi + ((uint32_t)(cpu->edx) * 4u) + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_begin)) = cpu->eax;
    cpu->ecx = (int16_t)(*(uint16_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count)));
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(*(uint16_t*)(cpu->esp + 0x8Cu)) & 0xFFFFu);
    *(uint16_t*)(cpu->edi + ((uint32_t)(cpu->ecx) * 2u) + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_ids)) = cpu->edx & 0xFFFFu;
    cpu->eax = (int16_t)(*(uint16_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count)));
    *(uint32_t*)(cpu->edi + ((uint32_t)(cpu->eax) * 4u) + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_memory_offset)) = cpu->esi;
    { uint64_t l=(uint64_t)(*(uint16_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count))), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,16u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; *(uint16_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count)) = v; }
    label_000389C0:
    cpu->ecx = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    cpu->eax = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, module_key) + 4u);
    cpu->edx = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, module_key));
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, module_key) + 8u);
    *(uint32_t*)(cpu->esp + 0x394u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x390u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, module_key) + 0xCu);
    lift_push32(cpu, 0x14u);
    cpu->eax = (uint32_t)(cpu->esp + 0x394u);
    *(uint32_t*)(cpu->esp + 0x39Cu) = cpu->ecx;
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_02;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x3A4u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x3A8u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x438A0Bu)); sfera_sub_00430F40(cpu, LIFT_CODE_TOKEN_VA(0x438A0Bu));
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00038A24;
    cpu->ebp = g_sfera_mbc_runtime->registered_objects[cpu->eax];
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ebp;
    if ((uint32_t)(cpu->ebp) == 0u) goto label_00038A24;
    *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base)) = cpu->ebp;
    goto label_00038A66;
    label_00038A24:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x94u);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, 0xCD7u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x438A3Eu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x438A3Eu));
    cpu->ecx = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base));
    cpu->ebp = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438A4Au));
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, module_key));
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x438A5Du)); sfera_sub_00433C00(cpu, LIFT_CODE_TOKEN_VA(0x438A5Du));
    *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base)) = cpu->ebp;
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ebp;
    label_00038A66:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x9Cu);
    cpu->ecx = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    lift_push32(cpu, 0xCE3u);
    cpu->ebx += cpu->esi;
    lift_push32(cpu, (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp");
    cpu->edx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x438A83u)); sfera_sub_004EBE80(cpu, LIFT_CODE_TOKEN_VA(0x438A83u));
    cpu->ecx = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base));
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base)) = cpu->eax;
    cpu->eax += cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x94u);
    *(uint32_t*)(cpu->esp + 0x90u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x98u) = cpu->eax;
    if ((uint32_t)(cpu->ebp) == 0u) goto label_00038AC3;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038ABB;
    cpu->eax = (uint32_t)(cpu->esi + cpu->edx);
    cpu->edx = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    goto label_00038AF3;
    label_00038ABB:
    cpu->eax = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    goto label_00038AF3;
    label_00038AC3:
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038AD6;
    cpu->ebp = (uint32_t)(cpu->esi + cpu->edx);
    cpu->edx = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    goto label_00038AD8;
    label_00038AD6:
    cpu->ebp = cpu->esi;
    label_00038AD8:
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00038AEF;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438AE3u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esp += 0xCu;
    label_00038AEF:
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    label_00038AF3:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x9Cu);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038B0D;
    cpu->ebp = (uint32_t)(cpu->ecx + cpu->edx);
    cpu->edx = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    goto label_00038B0F;
    label_00038B0D:
    cpu->ebp = cpu->ecx;
    label_00038B0F:
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00038B34;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x98u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438B21u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xA8u);
    cpu->esp += 0xCu;
    label_00038B34:
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size))), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size)) = v; }
    cpu->eax = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    cpu->esi += cpu->eax;
    g_sfera_mbc_runtime->bytecode_base = (uint32_t)(cpu->eax);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_size)) = cpu->ebx;
    g_sfera_mbc_runtime->current_instruction_address = (uint32_t)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    g_sfera_mbc_runtime->process_memory_base = (uint32_t)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag));
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->esi);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00038B74;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    g_sfera_mbc_module_memory_stats[cpu->eax / 3u].process_memory_bytes += cpu->ecx;
    label_00038B74:
    cpu->esi = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entries));
    if ((uint32_t)(cpu->esi) == 0u) goto label_00038BDC;
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entry_count))), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00038BDC;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00038B90:
    if (*(uint32_t*)(cpu->esi + 4u) != (uint32_t)(3u)) goto label_00038BCC;
    lift_push32(cpu, (uintptr_t)"prc_link - memory allocation found in base process, pointer corruption quite possible."); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x438BA5u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x438BA5u));
    cpu->edx = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = cpu->ebp;
    cpu->eax += cpu->edx;
    cpu->ecx -= cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->edx) == 0u) goto label_00038BCC;
    cpu->edx += cpu->ecx;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    if ((uint32_t)(cpu->edx) == 0u) goto label_00038BCC;
    cpu->edx += cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = (uint64_t)(*(uint32_t*)(cpu->eax + 8u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    label_00038BCC:
    ++cpu->ebx;
    cpu->esi += 8u;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(*(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entry_count))), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00038B90;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    label_00038BDC:
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038CE1;
    cpu->esi = (uint32_t)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00038C0E;
    label_00038BF8:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xA8u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438C06u));
    cpu->esp += 0xCu;
    label_00038C0E:
    cpu->ebx = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, program_count));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0xA0u);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->esi) + (uint64_t)(0u);
    cpu->ecx = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->esi = (uint32_t)(cpu->ebx + cpu->ebp);
    cpu->edx = cpu->esi;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xA4u);
    lift_push32(cpu, 0xD11u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp");
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x438C45u)); sfera_sub_004EBE80(cpu, LIFT_CODE_TOKEN_VA(0x438C45u));
    cpu->ecx = cpu->ebx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xA4u);
    *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base)) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00038DDA;
    cpu->esi = (uint32_t)(cpu->eax + cpu->ecx + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebp;
    label_00038C64:
    cpu->ebx = (uint32_t)(cpu->esi + 0xFFFFFFD4u);
    label_00038C70:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; *(uint32_t*)(cpu->esp + 0x10u) = v; }
    *(uint8_t*)(cpu->esp + 0x1Bu) = cpu->eax & 0xFFu;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038CEB;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00038CA4;
    label_00038C8D:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x23u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438C98u));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->esp + 0x27u)) & 0xFFu);
    cpu->esp += 0xCu;
    label_00038CA4:
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    *(uint8_t*)(cpu->ebx) = cpu->eax & 0xFFu;
    ++cpu->ebx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00038C70;
    cpu->ebp = 4u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038CCD;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00038CF2;
    label_00038CCD:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFF8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438CD7u));
    cpu->esp += 0xCu;
    goto label_00038CF6;
    label_00038CE1:
    cpu->esi = 4u;
    goto label_00038BF8;
    label_00038CEB:
    cpu->ebp = 1u;
    goto label_00038C8D;
    label_00038CF2:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    label_00038CF6:
    cpu->ebx += cpu->ebp;
    cpu->ebp = 4u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038D16;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00038D24;
    label_00038D16:
    lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->esi + 0xFFFFFFFCu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438D1Cu));
    cpu->esp += 0xCu;
    label_00038D24:
    cpu->ebx += cpu->ebp;
    cpu->ebp = 1u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038D42;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00038D4D;
    label_00038D42:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438D45u));
    cpu->esp += 0xCu;
    label_00038D4D:
    cpu->ebx += cpu->ebp;
    cpu->ebp = 1u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038D6B;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00038D79;
    label_00038D6B:
    lift_push32(cpu, cpu->ebp);
    cpu->eax = (uint32_t)(cpu->esi + 1u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438D71u));
    cpu->esp += 0xCu;
    label_00038D79:
    cpu->ebx += cpu->ebp;
    cpu->ebp = 4u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038D99;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00038DA7;
    label_00038D99:
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438D9Fu));
    cpu->esp += 0xCu;
    label_00038DA7:
    *(uint8_t*)(cpu->esi + 0x58u) = 0u;
    *(uint8_t*)(cpu->esi + 0x68u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xFFFFFFF8u);
    *(uint32_t*)(cpu->esi + 0x5Cu) = cpu->edx;
    cpu->ebx += cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x6Cu) = 0xFFFFFFFFu;
    cpu->esi += 0xA4u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x20u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; *(uint32_t*)(cpu->esp + 0x20u) = v; }
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00038C64;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    label_00038DDA:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(cpu->esi)) goto label_00038E9C;
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    label_00038DF0:
    cpu->eax = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    *(uint32_t*)(cpu->eax + cpu->esi + 0x88u) = (uint64_t)(*(uint32_t*)(cpu->eax + cpu->esi + 0x88u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    cpu->edx = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    *(uint32_t*)(cpu->edx + cpu->esi + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->edx + cpu->esi + 0x24u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    cpu->eax = (uint32_t)(cpu->eax + cpu->esi + 0x88u);
    cpu->eax = (uint32_t)(cpu->edx + cpu->esi + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    *(uint32_t*)(cpu->eax + cpu->esi + 0x28u) = (uint64_t)(*(uint32_t*)(cpu->eax + cpu->esi + 0x28u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    cpu->eax = (uint32_t)(cpu->eax + cpu->esi + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    if (*(uint8_t*)(cpu->eax + cpu->esi + 0x2Cu) != (uint8_t)(1u)) goto label_00038E87;
    cpu->ecx = *(uint8_t*)(cpu->eax + cpu->esi + 0x2Du);
    cpu->ebp = (int16_t)(*(uint16_t*)(cpu->edi + ((uint32_t)(cpu->ecx) * 2u) + (uint32_t)offsetof(SferaMbcProcessRecord, program_map_b)));
    cpu->edx = cpu->ebx & 0xFFFFu;
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_00038E46;
    *(uint16_t*)(cpu->edi + ((uint32_t)(cpu->ecx) * 2u) + (uint32_t)offsetof(SferaMbcProcessRecord, program_map_b)) = cpu->edx & 0xFFFFu;
    *(uint16_t*)(cpu->edi + ((uint32_t)(cpu->ecx) * 2u) + (uint32_t)offsetof(SferaMbcProcessRecord, program_map_a)) = cpu->edx & 0xFFFFu;
    *(uint16_t*)(cpu->eax + cpu->esi + 0x9Cu) = cpu->edx & 0xFFFFu;
    goto label_00038E67;
    label_00038E46:
    cpu->ebx = cpu->ebp;
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0xA4u);
    *(uint16_t*)(cpu->ebx + cpu->eax + 0x9Eu) = cpu->edx & 0xFFFFu;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint16_t*)(cpu->eax + cpu->esi + 0x9Cu) = cpu->ebp & 0xFFFFu;
    *(uint16_t*)(cpu->edi + ((uint32_t)(cpu->ecx) * 2u) + (uint32_t)offsetof(SferaMbcProcessRecord, program_map_b)) = cpu->edx & 0xFFFFu;
    label_00038E67:
    *(uint16_t*)(cpu->eax + cpu->esi + 0x9Eu) = cpu->edx & 0xFFFFu;
    cpu->ecx = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, process_id));
    cpu->edx = cpu->edi;
    *(uint8_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, state_byte_b8)) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x438E83u)); sfera_sub_00433CF0(cpu, LIFT_CODE_TOKEN_VA(0x438E83u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    label_00038E87:
    ++cpu->ebx;
    cpu->esi += 0xA4u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)*(uint32_t*)(cpu->esp + 0x1Cu)) goto label_00038DF0;
    label_00038E9C:
    cpu->edx = g_sfera_mbc_runtime->program_index;
    cpu->eax = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xA4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx += cpu->eax;
    cpu->esi = 4u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, program_count)) = cpu->ecx;
    g_sfera_mbc_runtime->program_table_base = (uint32_t)(cpu->eax);
    g_sfera_mbc_runtime->active_program_record = (uint32_t)(cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038EDD;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi += 4u;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00038EF3;
    label_00038EDD:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xB4u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438EEBu));
    cpu->esp += 0xCu;
    label_00038EF3:
    cpu->ebx = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_count));
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->esi) + (uint64_t)(0u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xACu);
    cpu->ecx = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    cpu->ebp = (uint32_t)(cpu->esi + cpu->ebx);
    cpu->edx = cpu->ebp;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x34u);
    lift_push32(cpu, 0xD42u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp");
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x438F23u)); sfera_sub_004EBE80(cpu, LIFT_CODE_TOKEN_VA(0x438F23u));
    cpu->ecx = cpu->ebx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x34u);
    *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table)) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00039040;
    cpu->edx = (uint32_t)(cpu->eax + cpu->ecx + 0x28u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    label_00038F43:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebp += 0xFFFFFFD8u;
    cpu->edi = cpu->edi;
    label_00038F50:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = 1u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    *(uint8_t*)(cpu->esp + 0x1Bu) = cpu->eax & 0xFFu;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038F72;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00038F85;
    label_00038F72:
    lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Fu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438F79u));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->esp + 0x27u)) & 0xFFu);
    cpu->esp += 0xCu;
    label_00038F85:
    *(uint8_t*)(cpu->ebp) = cpu->eax & 0xFFu;
    cpu->ebx += cpu->esi;
    ++cpu->ebp;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00038F50;
    cpu->ebp = 4u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000390C0;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00038FC2;
    label_00038FB0:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx += 0xFFFFFFFCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438FBAu));
    cpu->esp += 0xCu;
    label_00038FC2:
    cpu->ebx += cpu->esi;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000390C7;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00038FEF;
    label_00038FE0:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438FE7u));
    cpu->esp += 0xCu;
    label_00038FEF:
    cpu->ebx += cpu->esi;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000390CE;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_0003901F;
    label_0003900D:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi);
    cpu->eax += 4u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x439017u));
    cpu->esp += 0xCu;
    label_0003901F:
    *(uint32_t*)(cpu->esp + 0x1Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x1Cu)) + (uint64_t)(0x34u) + (uint64_t)(0u);
    cpu->ebx += cpu->esi;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x20u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; *(uint32_t*)(cpu->esp + 0x20u) = v; }
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00038F43;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x24u);
    label_00039040:
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x38u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_count)) = cpu->ebp;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000391DB;
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(cpu->ebp)) goto label_00039129;
    cpu->eax = cpu->ebp;
    cpu->eax -= cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    label_00039062:
    cpu->edx = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = (uint32_t)(cpu->edx + cpu->ecx + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->eax) = (uint64_t)(*(uint32_t*)(cpu->eax)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->eax + cpu->ecx + 0x28u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (uint32_t)(cpu->eax + cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003910B;
    cpu->esi = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x24u) <= (int32_t)(uint32_t)(cpu->esi)) goto label_00039112;
    cpu->ebp = cpu->eax;
    label_00039092:
    if (*(uint32_t*)(cpu->ebp + 0x28u) == (uint32_t)(0xFFFFFFFFu)) goto label_000390DE;
    cpu->ecx = cpu->ebp;
    cpu->eax = cpu->ebx;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000390A0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(*(uint8_t*)(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000390D5;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_000390BC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(*(uint8_t*)(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000390D5;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000390A0;
    label_000390BC:
    cpu->eax = 0u;
    goto label_000390DA;
    label_000390C0:
    cpu->esi = cpu->ebp;
    goto label_00038FB0;
    label_000390C7:
    cpu->esi = cpu->ebp;
    goto label_00038FE0;
    label_000390CE:
    cpu->esi = cpu->ebp;
    goto label_0003900D;
    label_000390D5:
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000390DA:
    if ((uint32_t)(cpu->eax) == 0u) goto label_000390EA;
    label_000390DE:
    ++cpu->esi;
    cpu->ebp += 0x34u;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)*(uint32_t*)(cpu->esp + 0x24u)) goto label_00039092;
    goto label_00039112;
    label_000390EA:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x24u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x34u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(*(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base))), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    *(uint8_t*)(cpu->eax) = 0x47u;
    cpu->ecx = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    cpu->edx = *(uint32_t*)(cpu->esi + cpu->ecx + 0x24u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx -= *(uint32_t*)(cpu->ecx + cpu->esi + 0x24u);
    --cpu->edx;
    *(uint32_t*)(cpu->eax + 1u) = cpu->edx;
    goto label_00039112;
    label_0003910B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->ebx + 0x28u) = (uint64_t)(*(uint32_t*)(cpu->ebx + 0x28u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    label_00039112:
    *(uint32_t*)(cpu->esp + 0x1Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x1Cu)) + (uint64_t)(0x34u) + (uint64_t)(0u);
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x20u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; *(uint32_t*)(cpu->esp + 0x20u) = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00039062;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x24u);
    label_00039129:
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00039211;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00039140:
    cpu->eax = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx += cpu->eax;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->ecx + 0x28u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000391C6;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x24u);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->ebp)) goto label_000391C6;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ebx = (uint32_t)(cpu->edx + cpu->eax);
    label_00039162:
    if (*(uint32_t*)(cpu->ebx + 0x28u) == (uint32_t)(0xFFFFFFFFu)) goto label_00039199;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ecx = cpu->ebx;
    cpu->edi = cpu->edi;
    label_00039170:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(*(uint8_t*)(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00039190;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_0003918C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(*(uint8_t*)(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00039190;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00039170;
    label_0003918C:
    cpu->eax = 0u;
    goto label_00039195;
    label_00039190:
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_00039195:
    if ((uint32_t)(cpu->eax) == 0u) goto label_000391A3;
    label_00039199:
    ++cpu->esi;
    cpu->ebx += 0x34u;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->ebp)) goto label_00039162;
    goto label_000391C6;
    label_000391A3:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x34u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x24u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(*(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base))), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    *(uint8_t*)(cpu->eax) = 0x47u;
    cpu->ecx = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    cpu->edx = *(uint32_t*)(cpu->esi + cpu->ecx + 0x24u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx -= *(uint32_t*)(cpu->ecx + cpu->esi + 0x24u);
    --cpu->edx;
    *(uint32_t*)(cpu->eax + 1u) = cpu->edx;
    label_000391C6:
    *(uint32_t*)(cpu->esp + 0x1Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x1Cu)) + (uint64_t)(0x34u) + (uint64_t)(0u);
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x20u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; *(uint32_t*)(cpu->esp + 0x20u) = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00039140;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x24u);
    goto label_00039211;
    label_000391DB:
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(cpu->ebp)) goto label_00039211;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ebp -= cpu->ebx;
    cpu->esi = cpu->ebp;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x34u);
    label_000391F0:
    cpu->eax = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    *(uint32_t*)(cpu->eax + cpu->ecx + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->eax + cpu->ecx + 0x24u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    cpu->eax = (uint32_t)(cpu->eax + cpu->ecx + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->eax + cpu->ecx + 0x28u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->eax + cpu->ecx + 0x28u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003920B;
    *(uint32_t*)(cpu->eax) = (uint64_t)(*(uint32_t*)(cpu->eax)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    label_0003920B:
    cpu->ecx += 0x34u;
    { uint64_t l=(uint64_t)(cpu->esi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->esi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000391F0;
    label_00039211:
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x44u) > (int32_t)(uint32_t)(0x16u)) goto label_0003923E;
    cpu->esi = 0x3Cu;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00039236;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi += 0x3Cu;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00039275;
    label_00039236:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    goto label_00039268;
    label_0003923E:
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)), r=(uint64_t)(0xA0u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); *(uint32_t*)(cpu->esp + 0x10u) = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000392E1;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi += 0xA0u;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00039275;
    label_00039262:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    label_00039268:
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->link_workspace_words[0]);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43926Du));
    cpu->esp += 0xCu;
    label_00039275:
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->esi) + (uint64_t)(0u);
    cpu->eax = 0u;
    label_00039280:
    cpu->ecx = *(uint32_t*)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, workspace_base));
    cpu->edx = 0xFFFFu;
    if (*(uint16_t*)(cpu->ecx + cpu->eax) != (uint16_t)((cpu->edx & 0xFFFFu))) goto label_000392A8;
    cpu->edx = g_sfera_mbc_runtime->link_workspace_words[cpu->eax >> 1u];
    cpu->esi = 0xFFFFu;
    if ((uint16_t)((cpu->edx & 0xFFFFu)) == (uint16_t)((cpu->esi & 0xFFFFu))) goto label_000392A8;
    cpu->edx += cpu->ebx;
    *(uint16_t*)(cpu->ecx + cpu->eax) = cpu->edx & 0xFFFFu;
    label_000392A8:
    cpu->eax += 2u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xA0u)) goto label_00039280;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebx = v; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000392EB;
    cpu->esi = (uint32_t)(cpu->ebx + 4u);
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_000392F2;
    label_000392CC:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->module_link_stream_size);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4392D7u));
    cpu->esp += 0xCu;
    goto label_000392F6;
    label_000392E1:
    cpu->esi = 0xA0u;
    goto label_00039262;
    label_000392EB:
    cpu->esi = 4u;
    goto label_000392CC;
    label_000392F2:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    label_000392F6:
    cpu->ebp += cpu->esi;
    cpu->esi = g_sfera_mbc_runtime->module_link_stream_size;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebx = v; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00039310;
    cpu->esi += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    label_00039310:
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00039323;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->module_link_stream[0]);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43931Bu));
    cpu->esp += 0xCu;
    label_00039323:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->ecx = cpu->edi;
    cpu->ebp += cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x439330u)); sfera_sub_00435110(cpu, LIFT_CODE_TOKEN_VA(0x439330u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00039514;
    cpu->edi = (uint32_t)(cpu->esi + 4u);
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_00039360;
    label_0003934E:
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0xD0u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x439358u));
    cpu->esp += 0xCu;
    label_00039360:
    cpu->ebp += cpu->edi;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0003951E;
    cpu->edi = (uint32_t)(cpu->esi + 4u);
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_0003938E;
    label_0003937C:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0xD4u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x439386u));
    cpu->esp += 0xCu;
    label_0003938E:
    cpu->ebp += cpu->edi;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00039528;
    cpu->edi = (uint32_t)(cpu->esi + 4u);
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_000393BC;
    label_000393AA:
    lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->esp + 0xD8u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4393B4u));
    cpu->esp += 0xCu;
    label_000393BC:
    cpu->ebp += cpu->edi;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00039532;
    cpu->edi = (uint32_t)(cpu->esi + 4u);
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_000393E7;
    label_000393D8:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->link_relocation_count);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4393DFu));
    cpu->esp += 0xCu;
    label_000393E7:
    cpu->ebp += cpu->edi;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->esp + 0x38u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = g_sfera_mbc_runtime->link_relocation_count;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003953C;
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edi) * 4u));
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0003940D;
    cpu->eax += cpu->esi;
    cpu->esi = 0u;
    label_0003940D:
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    label_00039411:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x3Cu);
    label_00039415:
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000395AE;
    cpu->ebx = (uint32_t)(cpu->esi + 4u);
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00039448;
    label_0003942F:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->link_relocation_count);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43943Au));
    cpu->edi = g_sfera_mbc_runtime->link_relocation_count;
    cpu->esp += 0xCu;
    label_00039448:
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u);
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->edi) * 4u));
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00039463;
    cpu->ebx += cpu->esi;
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    label_00039463:
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_0003947A;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->link_relocation_offsets[0]);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x439472u));
    cpu->esp += 0xCu;
    label_0003947A:
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u);
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_000394B0;
    label_00039490:
    cpu->ecx = *(uint32_t*)(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->link_relocation_offsets[0]));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x98u);
    *(uint32_t*)(cpu->ecx + cpu->edx) = (uint64_t)(*(uint32_t*)(cpu->ecx + cpu->edx)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    cpu->edi = g_sfera_mbc_runtime->link_relocation_count;
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edi)) goto label_00039490;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    label_000394B0:
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000395B8;
    cpu->ebx = (uint32_t)(cpu->esi + 4u);
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_000394E3;
    label_000394CA:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->link_relocation_count);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4394D5u));
    cpu->edi = g_sfera_mbc_runtime->link_relocation_count;
    cpu->esp += 0xCu;
    label_000394E3:
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u);
    if (*(uint32_t*)(cpu->esp + 0x38u) != (uint32_t)(0u)) goto label_00039604;
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edi) * 4u));
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000395C2;
    cpu->esi += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    goto label_000395C4;
    label_00039514:
    cpu->edi = 4u;
    goto label_0003934E;
    label_0003951E:
    cpu->edi = 4u;
    goto label_0003937C;
    label_00039528:
    cpu->edi = 4u;
    goto label_000393AA;
    label_00039532:
    cpu->edi = 4u;
    goto label_000393D8;
    label_0003953C:
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->edi) * 4u));
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00039553;
    cpu->ebx += cpu->esi;
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    label_00039553:
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00039566;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->link_relocation_offsets[0]);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43955Eu));
    cpu->esp += 0xCu;
    label_00039566:
    cpu->ebp += cpu->ebx;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_00039411;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x90u);
    label_00039590:
    cpu->ecx = *(uint32_t*)(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->link_relocation_offsets[0]));
    *(uint32_t*)(cpu->ecx + cpu->edx) = (uint64_t)(*(uint32_t*)(cpu->ecx + cpu->edx)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    cpu->edi = g_sfera_mbc_runtime->link_relocation_count;
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edi)) goto label_00039590;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    goto label_00039415;
    label_000395AE:
    cpu->ebx = 4u;
    goto label_0003942F;
    label_000395B8:
    cpu->ebx = 4u;
    goto label_000394CA;
    label_000395C2:
    cpu->esi = cpu->eax;
    label_000395C4:
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_000395DB;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->link_relocation_offsets[0]);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4395D3u));
    cpu->esp += 0xCu;
    label_000395DB:
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_00039604;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x90u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000395F0:
    cpu->ecx = *(uint32_t*)(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->link_relocation_offsets[0]));
    *(uint16_t*)(cpu->ecx + cpu->edx) = (uint64_t)(*(uint16_t*)(cpu->ecx + cpu->edx)) + (uint64_t)((cpu->esi & 0xFFFFu)) + (uint64_t)(0u);
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_mbc_runtime->link_relocation_count)) goto label_000395F0;
    label_00039604:
    cpu->eax = 0u;
    goto label_00038900;
    label_0003960B:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0x3D8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00439630(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    --cpu->eax;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax)) & 0xFFu);
    cpu->edx = (uint32_t)(cpu->esp);
    cpu->ecx = (uint32_t)(uintptr_t)"Unknown script code: ";
    *(uint8_t*)(cpu->esp) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esp + 1u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x439653u)); sfera_sub_00438640(cpu, LIFT_CODE_TOKEN_VA(0x439653u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00439660(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = (uint32_t)(uintptr_t)"Unlinked function was called";
    sfera_sub_004385D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00439670(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->call_frame_depth;
    ++cpu->eax;
    g_sfera_mbc_runtime->call_frame_depth = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x14u)) goto label_0003969D;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack of stacks overflow";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x43968Au)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x43968Au));
    cpu->eax = g_sfera_mbc_runtime->call_frame_depth;
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    g_sfera_mbc_runtime->frame_stack_base[cpu->eax] = (uint32_t)(cpu->ecx);
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0003969D:
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    g_sfera_mbc_runtime->frame_stack_base[cpu->eax] = (uint32_t)(cpu->edx);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004396B0(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->call_frame_depth), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; g_sfera_mbc_runtime->call_frame_depth = (uint32_t)((v)); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000396C2;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack of stacks devastation";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_000396C2:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004396D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->active_program_record;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(*(uint8_t*)(cpu->eax + 0x84u)) & 0xFFu);
    cpu->edx = 0u;
    lift_push32(cpu, cpu->esi);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)((cpu->edx & 0xFFu))) goto label_00039739;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) - 1u)) & 0xFFu);
    *(uint8_t*)(cpu->eax + 0x84u) = cpu->ecx & 0xFFu;
    cpu->eax = g_sfera_mbc_runtime->active_program_record;
    cpu->ecx = cpu->ecx & 0xFFu;
    cpu->esi = *(uint32_t*)(cpu->eax + ((uint32_t)(cpu->ecx) * 4u) + 0x34u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_00039733;
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xBCu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_00039725;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x230u);
    *(uint32_t*)(cpu->eax + 0xBCu) = cpu->edx;
    lift_push32(cpu, 0x1853u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x39725u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_RVA(0x39725u));
    label_00039725:
    cpu->eax = g_sfera_mbc_runtime->bytecode_base;
    cpu->eax -= cpu->esi;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00039733:
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000397DD;
    label_00039739:
    cpu->ecx = g_sfera_mbc_runtime->execution_context_depth;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_00039755;
    cpu->ecx = (uint32_t)(uintptr_t)"fo12(): return stack underflow";
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004385D0(cpu, stop_address); return;
    label_00039750:
    cpu->eax = g_sfera_mbc_runtime->active_program_record;
    label_00039755:
    --cpu->ecx;
    g_sfera_mbc_runtime->execution_context_depth = (uint32_t)(cpu->ecx);
    *(uint8_t*)(cpu->eax + 0x94u) = cpu->edx & 0xFFu;
    cpu->ecx = g_sfera_mbc_runtime->execution_context_depth;
    cpu->eax = g_sfera_mbc_runtime->execution_context_stack[cpu->ecx].process_index;
    g_sfera_mbc_runtime->process_index = (uint32_t)(cpu->eax);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    cpu->eax = *(uint32_t*)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id));
    if ((uint32_t)(cpu->eax) == (uint32_t)(g_sfera_mbc_runtime->execution_context_stack[cpu->ecx].process_id)) goto label_0003979A;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_00039750;
    cpu->ecx = (uint32_t)(uintptr_t)"Return to defunct process";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x3979Au)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x3979Au));
    label_0003979A:
    cpu->eax = g_sfera_mbc_runtime->execution_context_stack[g_sfera_mbc_runtime->execution_context_depth].program_index;
    cpu->ecx = g_sfera_mbc_runtime->execution_context_stack[g_sfera_mbc_runtime->execution_context_depth].instruction_cursor;
    cpu->edx = g_sfera_mbc_runtime->execution_context_stack[g_sfera_mbc_runtime->execution_context_depth].bytecode_base;
    g_sfera_mbc_runtime->program_index = (uint32_t)(cpu->eax);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->execution_context_stack[g_sfera_mbc_runtime->execution_context_depth].process_memory_base;
    g_sfera_mbc_runtime->process_memory_base = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->execution_context_stack[g_sfera_mbc_runtime->execution_context_depth].program_table_base;
    g_sfera_mbc_runtime->bytecode_base = (uint32_t)(cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->execution_context_stack[g_sfera_mbc_runtime->execution_context_depth].active_process;
    cpu->eax += cpu->ecx;
    g_sfera_mbc_runtime->program_table_base = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->active_process = (uint32_t)(cpu->edx);
    g_sfera_mbc_runtime->active_program_record = (uint32_t)(cpu->eax);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000397DD:
    cpu->eax = g_sfera_mbc_runtime->bytecode_base;
    cpu->eax += cpu->esi;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004397F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFFEu);
    cpu->ecx <<= 5u;
    cpu->eax = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax <<= 5u;
    { uint64_t l=(uint64_t)(*(uint32_t*)(cpu->ecx)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00039832;
    cpu->edi = *(uint32_t*)(cpu->eax + 0x14u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_00039827;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (uint32_t)(uintptr_t)"Division by zero";
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004385D0(cpu, stop_address); return;
    label_00039827:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x14u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_divide_accumulator(cpu, cpu->edi, 32u, 1u);
    *(uint32_t*)(cpu->ecx + 0x14u) = cpu->eax;
    goto label_0003983B;
    label_00039832:
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (((double)*(float*)(cpu->eax + 0x14u)));
    *(float*)(cpu->ecx + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0003983B:
    cpu->eax = 1u;
    cpu->esi -= cpu->eax;
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->esi);
    *(uint32_t*)(cpu->ecx + 8u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0xCu) = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00439860(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = g_sfera_mbc_runtime->call_frame_depth;
    cpu->edx = 1u;
    cpu->ecx -= cpu->edx;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(g_sfera_mbc_runtime->frame_stack_base[cpu->eax]), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0003988B;
    cpu->ecx = (uint32_t)(uintptr_t)"fo27(): stack underflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003988B:
    cpu->eax = cpu->ecx;
    cpu->eax <<= 5u;
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    if (*(uint32_t*)(cpu->eax) != (uint32_t)(0x20u)) goto label_000398A4;
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x14u));
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->eax + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_000398AE;
    label_000398A4:
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax + 0x14u);
    cpu->esi = 0u - (uint64_t)(cpu->esi);
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    label_000398AE:
    cpu->ecx += cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edx;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
