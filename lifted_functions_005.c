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
    label_0002F870: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F870u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002F88E;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edi = lift_load32(cpu->eax + 8u);
    cpu->eax = lift_load32(cpu->eax + 0xCu);
    goto label_0002F8A5;
    label_0002F88E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F88Eu);
    cpu->eax = lift_load32(cpu->esi + 0x7Cu);
    cpu->ecx = lift_load32(cpu->esi + 0x74u);
    cpu->edx = lift_load32(cpu->esi + 0x78u);
    cpu->edi = (uint32_t)(cpu->eax + cpu->ecx + 0xFFFFFFFFu);
    cpu->eax = lift_load32(cpu->esi + 0x80u);
    cpu->eax = (uint32_t)(cpu->eax + cpu->edx + 0xFFFFFFFFu);
    label_0002F8A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F8A5u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esi + 0x84u))) goto label_0002F8C5;
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esi + 0x88u))) goto label_0002F8C5;
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esi + 0x8Cu))) goto label_0002F8C5;
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 0x90u))) goto label_0002F8E6;
    label_0002F8C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F8C5u);
    lift_store32(cpu->esi + 0x84u, cpu->ecx);
    lift_store32(cpu->esi + 0x88u, cpu->edx);
    lift_store32(cpu->esi + 0x8Cu, cpu->edi);
    lift_store32(cpu->esi + 0x90u, cpu->eax);
    lift_store16(cpu->esi + 0x564u, 0u);
    label_0002F8E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F8E6u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x565u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002FA26;
    cpu->eax = lift_load32(cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x98u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store8(cpu->esi + 0x565u, cpu->ebx & 0xFFu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    cpu->ecx = (uint32_t)(cpu->esi + 0xF0u);
    lift_store_f32(cpu->esi + 0xE4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 5u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1Cu));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esi + 0xE8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = cpu->esi;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x2Cu));
    lift_store_f32(cpu->esi + 0xECu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x54u));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store_f32(cpu->esi + 0x114u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x108u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0xFCu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x64u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - ((double)(((int32_t)(lift_load32(cpu->esi + 0x84u))))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x5Cu));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x54u))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store_f32(cpu->esi + 0xF4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x118u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x64u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - ((double)(((int32_t)(lift_load32(cpu->esi + 0x8Cu))))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x5Cu))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x54u))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store_f32(cpu->esi + 0x100u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x10Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x68u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - ((double)(((int32_t)(lift_load32(cpu->esi + 0x88u))))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x60u))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x54u))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store_f32(cpu->esi + 0xF8u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x104u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x68u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - ((double)(((int32_t)(lift_load32(cpu->esi + 0x90u))))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x60u))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x54u))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store_f32(cpu->esi + 0x110u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x11Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x50u));
    lift_store_f32(cpu->esi + 0x120u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esi + 0x128u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x124u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2FA26u); lift_push32(cpu, r); sfera_sub_0042F450(cpu,r); if (cpu->eip != r) return; }
    label_0002FA26: cpu->eip = LIFT_CODE_TOKEN_VA(0x42FA26u);
    cpu->ebp = lift_load32(cpu->esp + 0x30u);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_0002FDFB;
    if ((uint8_t)(lift_load8(cpu->esi + 0x564u)) != (uint8_t)(0u)) goto label_0002FDFB;
    cpu->eax = (uint32_t)(cpu->esi + 0x518u);
    lift_store8(cpu->esi + 0x564u, cpu->ebx & 0xFFu);
    cpu->edi = 0xA0u;
    cpu->ebx = 0x10u;
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    goto label_0002FA64;
    label_0002FA60: cpu->eip = LIFT_CODE_TOKEN_VA(0x42FA60u);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    label_0002FA64: cpu->eip = LIFT_CODE_TOKEN_VA(0x42FA64u);
    cpu->ebp = lift_load32(cpu->eax + 0xFFFFFFFCu);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u));
    cpu->ebp = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->ebp) * 2u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ebp) * 4u) + 0xECu));
    cpu->ebp = (uint32_t)(cpu->esi + ((uint32_t)(cpu->ebp) * 4u));
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0xECu))));
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->ecx) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xE8u));
    cpu->eax = (uint32_t)(cpu->esi + ((uint32_t)(cpu->eax) * 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 0xE8u))));
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u) + 0x39u);
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->edx) * 4u));
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xE8u));
    cpu->edx = lift_load32(cpu->edx + 0xFFFFFFFCu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 0xE8u))));
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u) + 0x39u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xECu));
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->edx) * 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0xECu))));
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    cpu->edx = lift_load32(cpu->edx);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u) + 0x39u);
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->edx) * 4u));
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xE8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xE8u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xECu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0xECu))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xECu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 0xECu))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx))));
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xECu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 0xECu))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xECu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xECu))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xE8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp + 0xE8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xE8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx + 0xE8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xE8u));
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx + 0xE8u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42FBAAu); lift_push32(cpu, r); sfera_sub_0042F3E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->ebx + cpu->ecx, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edi + cpu->edx + 0xCu, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edi + cpu->eax + 8u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edi + cpu->ecx + 4u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edi + cpu->edx, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store32(cpu->esp + 0x2Cu, (uint64_t)(lift_load32(cpu->esp + 0x2Cu)) + (uint64_t)(0xCu) + (uint64_t)(0u));
    lift_store_f32(cpu->ebx + cpu->eax + 4u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edi + cpu->ecx + 0x1Cu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edi + cpu->edx + 0x18u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edi + cpu->eax + 0x14u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edi + cpu->ecx + 0x10u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    cpu->ebx += 0x10u;
    lift_store_f32(cpu->ebx + cpu->edx + 0xFFFFFFF8u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edi + cpu->eax + 0x2Cu, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edi + cpu->ecx + 0x28u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store_f32(cpu->edi + cpu->edx + 0x24u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edi + cpu->eax + 0x20u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    cpu->edi += 0x40u;
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xE8u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xECu));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ebx + cpu->edx + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->edi + cpu->eax + 0xFFFFFFFCu, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edi + cpu->ecx + 0xFFFFFFF8u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edi + cpu->edx + 0xFFFFFFF4u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edi + cpu->eax + 0xFFFFFFF0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(0x60u)) goto label_0002FA60;
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x50u));
    cpu->ebp = lift_load32(cpu->esp + 0x30u);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->ecx + 0x6Cu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + 0x68u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + 0x64u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->ecx + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x54u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->edx + 0x7Cu, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + 0x78u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->ecx + 0x74u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x58u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->eax + 0x8Cu, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->ecx + 0x88u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + 0x84u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x54u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x124u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x50u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x120u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x58u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x128u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->eax + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->ecx + 0x9Cu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + 0x98u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + 0x94u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->ecx + 0x90u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0002FDFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x42FDFBu);
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    cpu->edi = (uint32_t)(cpu->esi + 0xE4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0xE8u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0xECu))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0xCu))));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 0.0);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00030091;
    cpu->eax = 0xA0u;
    cpu->ecx = 0x10u;
    (void)cpu;
    label_0002FE40: cpu->eip = LIFT_CODE_TOKEN_VA(0x42FE40u);
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx));
    cpu->eax += 0x40u;
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edx + cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFCCu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFC8u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFC4u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFC0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + cpu->edx + 4u));
    cpu->edx = (uint32_t)(cpu->ecx + cpu->edx + 4u);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFDCu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFD8u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFD4u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFD0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + cpu->edx + 8u));
    cpu->edx = (uint32_t)(cpu->ecx + cpu->edx + 8u);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFECu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFE8u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFE4u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFE0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + cpu->edx + 0xCu));
    cpu->edx = (uint32_t)(cpu->ecx + cpu->edx + 0xCu);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    cpu->ecx += 0x10u;
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFFCu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFF8u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFF4u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFF0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(0x60u)) goto label_0002FE40;
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->eax + 0x6Cu, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->ecx + 0x68u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + 0x64u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->ecx + 0x7Cu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + 0x78u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + 0x74u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->ecx + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->edx + 0x8Cu, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + 0x88u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->ecx + 0x84u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->eax + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->eax + 0x9Cu, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->ecx + 0x98u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + 0x94u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + 0x90u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00030091: cpu->eip = LIFT_CODE_TOKEN_VA(0x430091u);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0003009B;
    lift_store32(cpu->eax, cpu->edi);
    label_0003009B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43009Bu);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_000300A8;
    cpu->esi += 0x12Cu;
    lift_store32(cpu->ebp, cpu->esi);
    label_000300A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4300A8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 12u, stop_address); return;
    label_000300C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4300C0u);
    cpu->esp -= 0x18u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x1Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000300E8;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->ecx, 0u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 12u, stop_address); return;
    label_000300E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4300E8u);
    cpu->eax = lift_load32(cpu->esi + 0x74u);
    cpu->ecx = lift_load32(cpu->esi + 0x78u);
    cpu->edx = lift_load32(cpu->esi + 0x7Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x80u);
    cpu->edx = (uint32_t)(cpu->edx + cpu->eax + 0xFFFFFFFFu);
    cpu->edi = (uint32_t)(cpu->edi + cpu->ecx + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 0x84u))) goto label_00030122;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esi + 0x88u))) goto label_00030122;
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esi + 0x8Cu))) goto label_00030122;
    if ((uint32_t)(cpu->edi) == (uint32_t)(lift_load32(cpu->esi + 0x90u))) goto label_00030143;
    label_00030122: cpu->eip = LIFT_CODE_TOKEN_VA(0x430122u);
    lift_store32(cpu->esi + 0x84u, cpu->eax);
    lift_store32(cpu->esi + 0x88u, cpu->ecx);
    lift_store32(cpu->esi + 0x8Cu, cpu->edx);
    lift_store32(cpu->esi + 0x90u, cpu->edi);
    lift_store16(cpu->esi + 0x564u, 0u);
    label_00030143: cpu->eip = LIFT_CODE_TOKEN_VA(0x430143u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x565u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00030264;
    cpu->eax = lift_load32(cpu->esi);
    lift_store8(cpu->esi + 0x565u, cpu->ebx & 0xFFu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 5u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1Cu));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x2Cu));
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0xE4u, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x54u));
    lift_store32(cpu->esi + 0xE8u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->esi + 0xF0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_store_f32(cpu->esi + 0x114u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0xECu, cpu->edx);
    lift_store_f32(cpu->esi + 0x108u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esi + 0xFCu, lift_x87_get(cpu, 0u));
    cpu->edx = cpu->esi;
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x54u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (((double)lift_load_f32(cpu->esi + 0x560u))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x550u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store_f32(cpu->esi + 0xF4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x118u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x558u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x550u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store_f32(cpu->esi + 0x100u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x10Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x554u))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store_f32(cpu->esi + 0xF8u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x104u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x55Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x554u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store_f32(cpu->esi + 0x110u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x11Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x50u));
    lift_store_f32(cpu->esi + 0x120u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esi + 0x128u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x124u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x30264u); lift_push32(cpu, r); sfera_sub_0042F450(cpu,r); if (cpu->eip != r) return; }
    label_00030264: cpu->eip = LIFT_CODE_TOKEN_VA(0x430264u);
    cpu->ebp = lift_load32(cpu->esp + 0x30u);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_0003063B;
    if ((uint8_t)(lift_load8(cpu->esi + 0x564u)) != (uint8_t)(0u)) goto label_0003063B;
    cpu->eax = (uint32_t)(cpu->esi + 0x518u);
    lift_store8(cpu->esi + 0x564u, cpu->ebx & 0xFFu);
    cpu->edi = 0xA0u;
    cpu->ebx = 0x10u;
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    goto label_000302A4;
    label_000302A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4302A0u);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    label_000302A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4302A4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->ebp = lift_load32(cpu->eax + 0xFFFFFFFCu);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u));
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 0xECu));
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ebp = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->ebp) * 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->ebp) * 4u) + 0xECu))));
    cpu->ebp = (uint32_t)(cpu->esi + ((uint32_t)(cpu->ebp) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xE8u));
    cpu->eax = (uint32_t)(cpu->esi + ((uint32_t)(cpu->eax) * 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 0xE8u))));
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u) + 0x39u);
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->edx) * 4u));
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xE8u));
    cpu->edx = lift_load32(cpu->edx + 0xFFFFFFFCu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 0xE8u))));
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u) + 0x39u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xECu));
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->edx) * 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp + 0xECu))));
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    cpu->edx = lift_load32(cpu->edx);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u) + 0x39u);
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->edx) * 4u));
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xECu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0xECu))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xE8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xE8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx))));
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xECu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ecx + 0xECu))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xECu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + 0xECu))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx))));
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xECu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xECu))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xE8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp + 0xE8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xE8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx + 0xE8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xE8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx + 0xE8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4303EAu); lift_push32(cpu, r); sfera_sub_0042F3E0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->ebx + cpu->eax, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->ecx + cpu->edi + 0xCu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + cpu->edi + 8u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + cpu->edi + 4u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edi + cpu->ecx, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store32(cpu->esp + 0x2Cu, (uint64_t)(lift_load32(cpu->esp + 0x2Cu)) + (uint64_t)(0xCu) + (uint64_t)(0u));
    lift_store_f32(cpu->edx + cpu->ebx + 4u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + cpu->edi + 0x1Cu, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->ecx + cpu->edi + 0x18u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + cpu->edi + 0x14u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edi + cpu->eax + 0x10u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    cpu->ebx += 0x10u;
    lift_store_f32(cpu->ecx + cpu->ebx + 0xFFFFFFF8u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + cpu->edi + 0x2Cu, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + cpu->edi + 0x28u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store_f32(cpu->ecx + cpu->edi + 0x24u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edi + cpu->edx + 0x20u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    cpu->edi += 0x40u;
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xE8u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xECu));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ecx + cpu->ebx + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->edx + cpu->edi + 0xFFFFFFFCu, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + cpu->edi + 0xFFFFFFF8u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->ecx + cpu->edi + 0xFFFFFFF4u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edi + cpu->edx + 0xFFFFFFF0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(0x60u)) goto label_000302A0;
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x50u));
    cpu->ebp = lift_load32(cpu->esp + 0x30u);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->eax + 0x6Cu, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->ecx + 0x68u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + 0x64u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x54u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->ecx + 0x7Cu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + 0x78u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + 0x74u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->ecx + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x58u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->edx + 0x8Cu, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + 0x88u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->ecx + 0x84u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x54u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x124u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x50u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x120u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x58u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x128u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->eax + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->eax + 0x9Cu, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->ecx + 0x98u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + 0x94u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + 0x90u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0003063B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43063Bu);
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    cpu->edi = (uint32_t)(cpu->esi + 0xE4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0xE8u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0xECu))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0xCu))));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 0.0);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000308D1;
    cpu->eax = 0xA0u;
    cpu->ecx = 0x10u;
    (void)cpu;
    label_00030680: cpu->eip = LIFT_CODE_TOKEN_VA(0x430680u);
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx));
    cpu->eax += 0x40u;
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edx + cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->edx + cpu->eax + 0xFFFFFFCCu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + cpu->eax + 0xFFFFFFC8u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + cpu->eax + 0xFFFFFFC4u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFC0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 4u));
    cpu->edx = (uint32_t)(cpu->edx + cpu->ecx + 4u);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->edx + cpu->eax + 0xFFFFFFDCu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + cpu->eax + 0xFFFFFFD8u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + cpu->eax + 0xFFFFFFD4u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFD0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 8u));
    cpu->edx = (uint32_t)(cpu->edx + cpu->ecx + 8u);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->edx + cpu->eax + 0xFFFFFFECu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + cpu->eax + 0xFFFFFFE8u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + cpu->eax + 0xFFFFFFE4u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFE0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0xCu));
    cpu->edx = (uint32_t)(cpu->edx + cpu->ecx + 0xCu);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    cpu->ecx += 0x10u;
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->edx + cpu->eax + 0xFFFFFFFCu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + cpu->eax + 0xFFFFFFF8u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + cpu->eax + 0xFFFFFFF4u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + cpu->edx + 0xFFFFFFF0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(0x60u)) goto label_00030680;
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->eax + 0x6Cu, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->ecx + 0x68u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + 0x64u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->ecx + 0x7Cu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + 0x78u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + 0x74u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->ecx + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->edx + 0x8Cu, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + 0x88u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->ecx + 0x84u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->eax + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->eax + 0x9Cu, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->ecx + 0x98u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->edx + 0x94u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esi + 0x31Cu);
    lift_store_f32(cpu->eax + 0x90u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000308D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4308D1u);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000308DB;
    lift_store32(cpu->eax, cpu->edi);
    label_000308DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4308DBu);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_000308E8;
    cpu->esi += 0x12Cu;
    lift_store32(cpu->ebp, cpu->esi);
    label_000308E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4308E8u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 12u, stop_address); return;
    label_00030900: cpu->eip = LIFT_CODE_TOKEN_VA(0x430900u);
    if ((uint8_t)(lift_load8(cpu->ecx + 0x566u)) == (uint8_t)(0u)) goto label_0003090E;
    goto label_000300C0;
    label_0003090E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43090Eu);
    goto label_0002F870;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00430920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x430920u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x18u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00030941;
    lift_push32(cpu, 2u); lift_push32(cpu, 0x10000u); lift_push32(cpu, 0xAu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43093Au); lift_push32(cpu, r); sfera_sub_00419920(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x18u, 1u);
    label_00030941: cpu->eip = LIFT_CODE_TOKEN_VA(0x430941u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, 4000.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, 0.5120000243186951);
    lift_x87_set(cpu, 2u, (lift_x87_get(cpu, 2u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43095Cu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x18u))));
    cpu->esi = cpu->eax;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x430969u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
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
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->ecx += cpu->eax;
    cpu->edx = cpu->ecx & 0xFFFFu;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4309AEu); lift_push32(cpu, r); sfera_sub_00419990(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0x800000FFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000309BE;
    --cpu->edi;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->edi = v; }
    { uint64_t l=(uint64_t)(cpu->edi), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    label_000309BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4309BEu);
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0x800000FFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000309D1;
    --cpu->esi;
    cpu->esi |= 0xFFFFFF00u;
    ++cpu->esi;
    label_000309D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4309D1u);
    cpu->edi += cpu->eax;
    cpu->eax = (int8_t)(lift_load8(cpu->esi + cpu->edi));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax &= 0xFu;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000309E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4309E1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004309F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4309F0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0x18u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00030A11;
    lift_push32(cpu, 2u); lift_push32(cpu, 0x10000u); lift_push32(cpu, 0xAu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x430A0Au); lift_push32(cpu, r); sfera_sub_00419920(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x18u, 1u);
    label_00030A11: cpu->eip = LIFT_CODE_TOKEN_VA(0x430A11u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, 4000.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, 0.5120000243186951);
    lift_x87_set(cpu, 2u, (lift_x87_get(cpu, 2u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x430A2Cu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x18u))));
    cpu->esi = cpu->eax;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x430A39u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
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
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->ecx += cpu->eax;
    cpu->edx = cpu->ecx & 0xFFFFu;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x430A7Eu); lift_push32(cpu, r); sfera_sub_00419990(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0x800000FFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00030A8E;
    --cpu->edi;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->edi = v; }
    { uint64_t l=(uint64_t)(cpu->edi), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    label_00030A8E: cpu->eip = LIFT_CODE_TOKEN_VA(0x430A8Eu);
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0x800000FFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00030AA1;
    --cpu->esi;
    cpu->esi |= 0xFFFFFF00u;
    ++cpu->esi;
    label_00030AA1: cpu->eip = LIFT_CODE_TOKEN_VA(0x430AA1u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->eax = (int8_t)(lift_load8(cpu->esi + cpu->edi));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(4u), 32u);
    cpu->esi = lift_pop32(cpu);
    cpu->eax &= 3u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00030AB4: cpu->eip = LIFT_CODE_TOKEN_VA(0x430AB4u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00430AC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x430AC0u);
    cpu->esp -= 0x30u;
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    cpu->eax = lift_load16(cpu->eax);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x40u);
    cpu->ebx = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(0x800000FFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebx = v; }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00030AEF;
    --cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ebx = v; }
    { uint64_t l=(uint64_t)(cpu->ebx), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    label_00030AEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x430AEFu);
    cpu->ecx = 9u;
    cpu->esi = (uint32_t)(uintptr_t)"Landscape\\GrassMap\\GrassMap_00_00.bin";
    cpu->edi = (uint32_t)(cpu->esp + 0x14u);
    lift_movs32(cpu, 1u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(8u), 32u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_movs16(cpu, 0u);
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_00030B10: cpu->eip = LIFT_CODE_TOKEN_VA(0x430B10u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00030B10;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->esi = (uint32_t)(cpu->esp + cpu->eax + 0x14u);
    cpu->eax = 0x66666667u;
    lift_multiply_accumulator(cpu, cpu->ebx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax & 0xFFu)) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->eax + 0x30u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->ebx & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,8u); cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    lift_store8(cpu->esi + 0xFFFFFFF7u, cpu->ecx & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = 0x66666667u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->edx = (uint32_t)(cpu->eax + 0x30u);
    lift_store8(cpu->esi + 0xFFFFFFFAu, cpu->edx & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax & 0xFFu)) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) - (uint64_t)((cpu->eax & 0xFFu)) - (uint64_t)(0u))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    lift_store8(cpu->esi + 0xFFFFFFFBu, cpu->ecx & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store8(cpu->esi + 0xFFFFFFF8u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x430B7Eu); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    lift_push32(cpu, 0x10000u);
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x430B8Eu); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x430B95u); lift_push32(cpu, r); sfera_sub_0042F180(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00430BB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x430BB0u);
    cpu->eax = cpu->ecx;
    std::construct_at(reinterpret_cast<GrassMapMngr*>(cpu->eax));
    lift_store32(cpu->eax + 0x18u, 0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00430BC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x430BC0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00030BDD;
    lift_push32(cpu, 0x3Au);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\hash.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x430BD6u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 8u, 0u);
    label_00030BDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x430BDDu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00430BE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x430BE0u);
    cpu->ecx = 0u;
    lift_flags_logic(cpu,0u,32u); cpu->edx = 0u;
    label_00030BE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x430BE4u);
    cpu->eax = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00030BFA;
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    label_00030BFA: cpu->eip = LIFT_CODE_TOKEN_VA(0x430BFAu);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00030C0F;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_00030C11;
    label_00030C0F: cpu->eip = LIFT_CODE_TOKEN_VA(0x430C0Fu);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_00030C11: cpu->eip = LIFT_CODE_TOKEN_VA(0x430C11u);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00030C26;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_00030C28;
    label_00030C26: cpu->eip = LIFT_CODE_TOKEN_VA(0x430C26u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_00030C28: cpu->eip = LIFT_CODE_TOKEN_VA(0x430C28u);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00030C3D;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_00030C3F;
    label_00030C3D: cpu->eip = LIFT_CODE_TOKEN_VA(0x430C3Du);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_00030C3F: cpu->eip = LIFT_CODE_TOKEN_VA(0x430C3Fu);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00030C54;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_00030C56;
    label_00030C54: cpu->eip = LIFT_CODE_TOKEN_VA(0x430C54u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_00030C56: cpu->eip = LIFT_CODE_TOKEN_VA(0x430C56u);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00030C6B;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_00030C6D;
    label_00030C6B: cpu->eip = LIFT_CODE_TOKEN_VA(0x430C6Bu);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_00030C6D: cpu->eip = LIFT_CODE_TOKEN_VA(0x430C6Du);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00030C82;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_00030C84;
    label_00030C82: cpu->eip = LIFT_CODE_TOKEN_VA(0x430C82u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_00030C84: cpu->eip = LIFT_CODE_TOKEN_VA(0x430C84u);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_00030C90;
    cpu->ecx ^= 0xEDB88320u;
    label_00030C90: cpu->eip = LIFT_CODE_TOKEN_VA(0x430C90u);
    lift_store16(((uint32_t)(cpu->edx) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_packet_codec_runtime.checksum[0]), cpu->ecx & 0xFFFFu);
    ++cpu->edx;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00030BE4;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00430CB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x430CB0u);
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
    label_00030CE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x430CE4u);
    lift_store8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_packet_codec_runtime.substitution[0]), cpu->eax & 0xFFu);
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x100u)) goto label_00030CE4;
    cpu->eax = 0u;
    label_00030CF4: cpu->eip = LIFT_CODE_TOKEN_VA(0x430CF4u);
    cpu->ecx = lift_load8(cpu->esp + cpu->eax);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + cpu->eax + 0x3Cu)) & 0xFFu);
    ++cpu->eax;
    lift_store8(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_packet_codec_runtime.substitution[0]), cpu->edx & 0xFFu);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x3Cu)) goto label_00030CF4;
    cpu->esp += 0x7Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00430D20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x430D20u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    cpu->eax = 1u;
    if ((uint32_t)(cpu->ebp) != 0u) goto label_00030D43;
    if ((uint32_t)(lift_load32(cpu->esp + 0x30u)) != (uint32_t)(cpu->eax)) goto label_00030D43;
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    goto label_00030D4F;
    label_00030D43: cpu->eip = LIFT_CODE_TOKEN_VA(0x430D43u);
    lift_store32(cpu->esp + 0x2Cu, 0u);
    if ((uint32_t)(cpu->ebp) != 0u) goto label_00030D65;
    label_00030D4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x430D4Fu);
    cpu->edi = lift_load32(cpu->esp + 0x28u);
    cpu->eax = cpu->edi;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_00030D58: cpu->eip = LIFT_CODE_TOKEN_VA(0x430D58u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00030D58;
    cpu->eax -= cpu->esi;
    cpu->ebp = cpu->eax;
    goto label_00030D69;
    label_00030D65: cpu->eip = LIFT_CODE_TOKEN_VA(0x430D65u);
    cpu->edi = lift_load32(cpu->esp + 0x28u);
    label_00030D69: cpu->eip = LIFT_CODE_TOKEN_VA(0x430D69u);
    if ((int32_t)(uint32_t)(cpu->ebp) <= (int32_t)(uint32_t)(lift_load32(cpu->ecx))) goto label_00030D79;
    label_00030D6D: cpu->eip = LIFT_CODE_TOKEN_VA(0x430D6Du);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 12u, stop_address); return;
    label_00030D79: cpu->eip = LIFT_CODE_TOKEN_VA(0x430D79u);
    cpu->esi = 0u;
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00030DAA;
    label_00030D81: cpu->eip = LIFT_CODE_TOKEN_VA(0x430D81u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x2Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + cpu->edi)) & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00030D94;
    cpu->edx = cpu->edx & 0xFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_packet_codec_runtime.substitution[0]))) & 0xFFu);
    label_00030D94: cpu->eip = LIFT_CODE_TOKEN_VA(0x430D94u);
    cpu->edx = cpu->edx & 0xFFu;
    cpu->esi = (cpu->esi & 0xFFFF0000u) | ((uint32_t)(lift_shift_right(cpu, (cpu->esi & 0xFFFFu), (uint32_t)(1u), 16u)) & 0xFFFFu);
    cpu->esi = (cpu->esi & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->esi & 0xFFFFu)) + (uint64_t)(lift_load16(((uint32_t)(cpu->edx) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_packet_codec_runtime.checksum[0]))) + (uint64_t)(0u))) & 0xFFFFu);
    ++cpu->eax;
    cpu->esi = cpu->esi & 0xFFFFu;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ebp)) goto label_00030D81;
    label_00030DAA: cpu->eip = LIFT_CODE_TOKEN_VA(0x430DAAu);
    cpu->eax = cpu->esi & 0xFFFFu;
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 2u) + 0x16u);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->eax = lift_load16(cpu->eax);
    cpu->edx = 0xFFFFu;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint16_t)((cpu->eax & 0xFFFFu)) == (uint16_t)((cpu->edx & 0xFFFFu))) goto label_00030D6D;
    cpu->esi = lift_load32(cpu->ecx + 0xCu);
    cpu->edx = cpu->eax & 0xFFFFu;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->esi);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    cpu->edx += cpu->ebx;
    lift_store32(cpu->esp + 0x14u, 0u);
    label_00030DE5: cpu->eip = LIFT_CODE_TOKEN_VA(0x430DE5u);
    cpu->eax = lift_load16(cpu->edx + 8u);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(lift_load32(cpu->edx))) goto label_00030EDE;
    if ((uint32_t)(lift_load32(cpu->esp + 0x30u)) != (uint32_t)(0u)) goto label_00030EB2;
    cpu->esi = cpu->edi;
    cpu->ebx = cpu->ebp;
    cpu->edi = (uint32_t)(cpu->edx + 0xAu);
    if ((uint32_t)(cpu->ebp) < (uint32_t)(4u)) goto label_00030E24;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00030E10: cpu->eip = LIFT_CODE_TOKEN_VA(0x430E10u);
    cpu->eax = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi))) goto label_00030E28;
    cpu->ebx -= 4u;
    cpu->esi += 4u;
    cpu->edi += 4u;
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(4u)) goto label_00030E10;
    label_00030E24: cpu->eip = LIFT_CODE_TOKEN_VA(0x430E24u);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_00030E73;
    label_00030E28: cpu->eip = LIFT_CODE_TOKEN_VA(0x430E28u);
    cpu->eax = lift_load8(cpu->edi);
    cpu->ecx = lift_load8(cpu->esi);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00030E63;
    if ((uint32_t)(cpu->ebx) <= (uint32_t)(1u)) goto label_00030E6F;
    cpu->eax = lift_load8(cpu->edi + 1u);
    cpu->ecx = lift_load8(cpu->esi + 1u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00030E63;
    if ((uint32_t)(cpu->ebx) <= (uint32_t)(2u)) goto label_00030E6F;
    cpu->eax = lift_load8(cpu->edi + 2u);
    cpu->ecx = lift_load8(cpu->esi + 2u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00030E63;
    if ((uint32_t)(cpu->ebx) <= (uint32_t)(3u)) goto label_00030E6F;
    cpu->eax = lift_load8(cpu->edi + 3u);
    cpu->ecx = lift_load8(cpu->esi + 3u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    label_00030E63: cpu->eip = LIFT_CODE_TOKEN_VA(0x430E63u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax |= 1u;
    goto label_00030E75;
    label_00030E6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x430E6Fu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_00030E73: cpu->eip = LIFT_CODE_TOKEN_VA(0x430E73u);
    cpu->eax = 0u;
    label_00030E75: cpu->eip = LIFT_CODE_TOKEN_VA(0x430E75u);
    cpu->ebx = 0u;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = cpu->ebx;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00030EDA;
    label_00030E82: cpu->eip = LIFT_CODE_TOKEN_VA(0x430E82u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00030EA5;
    cpu->ecx = lift_load16(cpu->edx + 8u);
    lift_store16(cpu->eax + 8u, cpu->ecx & 0xFFFFu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load16(cpu->eax);
    lift_store16(cpu->edx + 8u, cpu->ecx & 0xFFFFu);
    cpu->ecx = lift_load16(cpu->esp + 0x18u);
    lift_store16(cpu->eax, cpu->ecx & 0xFFFFu);
    label_00030EA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x430EA5u);
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 12u, stop_address); return;
    label_00030EB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x430EB2u);
    cpu->esi = 0u;
    cpu->eax = (uint32_t)(cpu->edx + 0xAu);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00030E82;
    cpu->edi -= cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00030EC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x430EC0u);
    cpu->ecx = (int8_t)(lift_load8(cpu->edi + cpu->eax));
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    if ((uint8_t)((cpu->ebx & 0xFFu)) != (uint8_t)(lift_load8(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_packet_codec_runtime.substitution[0])))) goto label_00030ED6;
    ++cpu->esi;
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->ebp)) goto label_00030EC0;
    goto label_00030E82;
    label_00030ED6: cpu->eip = LIFT_CODE_TOKEN_VA(0x430ED6u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    label_00030EDA: cpu->eip = LIFT_CODE_TOKEN_VA(0x430EDAu);
    cpu->edi = lift_load32(cpu->esp + 0x2Cu);
    label_00030EDE: cpu->eip = LIFT_CODE_TOKEN_VA(0x430EDEu);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    cpu->esi = 0xFFFFu;
    if ((uint16_t)((cpu->eax & 0xFFFFu)) == (uint16_t)((cpu->esi & 0xFFFFu))) goto label_00030F08;
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    cpu->edx = cpu->eax & 0xFFFFu;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(lift_load32(cpu->esp + 0x1Cu));
    cpu->edx += lift_load32(cpu->esp + 0x20u);
    cpu->eax = cpu->eax & 0xFFFFu;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    goto label_00030DE5;
    label_00030F08: cpu->eip = LIFT_CODE_TOKEN_VA(0x430F08u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00430F20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x430F20u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x430F31u); lift_push32(cpu, r); sfera_sub_00430D20(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00430F40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x430F40u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x430F51u); lift_push32(cpu, r); sfera_sub_00430D20(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00430F60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x430F60u);
    { uint64_t l=(uint64_t)(g_sfera_packet_codec_runtime.initialized), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00030F83;
    g_sfera_packet_codec_runtime.initialized = (uint32_t)(1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x430F7Cu); lift_push32(cpu, r); sfera_sub_00430BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x30F83u); lift_push32(cpu, r); sfera_sub_00430CB0(cpu,r); if (cpu->eip != r) return; }
    label_00030F83: cpu->eip = LIFT_CODE_TOKEN_VA(0x430F83u);
    lift_push32(cpu, 0x20018u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x430F8Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x430F90u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->esi + 4u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->eax + 0xAu);
    lift_store32(cpu->esi + 0xCu, cpu->ecx);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->edi);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0x25u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\hash.cpp";
    lift_store32(cpu->esi, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x430FB9u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x20000u);
    lift_store32(cpu->esi + 8u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esi + 0x16u);
    cpu->edx = 0u;
    lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->eax);
    lift_store16(cpu->esi + 0x14u, cpu->edx & 0xFFFFu);
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x430FD3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x430FD8u);
    cpu->ecx = (uint32_t)(cpu->edi + 0xFFFFFFFFu);
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_00030FFC;
    lift_push32(cpu, cpu->ebx);
    label_00030FE5: cpu->eip = LIFT_CODE_TOKEN_VA(0x430FE5u);
    cpu->edi = lift_load32(cpu->esi + 0xCu);
    cpu->ebx = lift_load32(cpu->esi + 8u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(cpu->eax);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    ++cpu->eax;
    lift_store16(cpu->edi + cpu->ebx + 8u, cpu->edx & 0xFFFFu);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ecx)) goto label_00030FE5;
    cpu->ebx = lift_pop32(cpu);
    label_00030FFC: cpu->eip = LIFT_CODE_TOKEN_VA(0x430FFCu);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    cpu->eax = 0xFFFFu;
    lift_store16(cpu->ecx + cpu->edx + 8u, cpu->eax & 0xFFFFu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431020(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x431020u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x431039u); lift_push32(cpu, r); sfera_sub_00430D20(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00031046;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_00031046: cpu->eip = LIFT_CODE_TOKEN_VA(0x431046u);
    cpu->ecx = 0xFFFFu;
    lift_push32(cpu, cpu->edi);
    if ((uint16_t)(lift_load16(cpu->esi + 0x14u)) != (uint16_t)((cpu->ecx & 0xFFFFu))) goto label_00031106;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x10u)), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031065;
    cpu->ecx = (uint32_t)(uintptr_t)"CHash16::register_str: more than 65535 elements";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x31065u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00031065: cpu->eip = LIFT_CODE_TOKEN_VA(0x431065u);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edi = cpu->edx;
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(0x1Fu), 32u);
    cpu->edi += cpu->edx;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(0x32u)) goto label_00031080;
    cpu->edi = 0x32u;
    label_00031080: cpu->eip = LIFT_CODE_TOKEN_VA(0x431080u);
    lift_store32(cpu->esi + 0x10u, (uint64_t)(lift_load32(cpu->esi + 0x10u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u));
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)((cpu->ecx & 0xFFFFu)) & 0xFFFFu);
    lift_store16(cpu->esi + 0x14u, cpu->edx & 0xFFFFu);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0xFFFFu)) goto label_000310A4;
    cpu->ecx = 0xFFFFu;
    cpu->ecx -= cpu->eax;
    cpu->edi += cpu->ecx;
    lift_store32(cpu->esi + 0x10u, 0xFFFFu);
    label_000310A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4310A4u);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(lift_load32(cpu->esi + 0xCu));
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, 0x83u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\hash.cpp");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4310BDu); lift_push32(cpu, r); sfera_sub_004EBE80(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 8u, cpu->eax);
    cpu->edx = (uint32_t)(cpu->edi + 0xFFFFFFFFu);
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(cpu->edx) <= 0) goto label_000310EF;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000310D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4310D0u);
    cpu->ecx = lift_load16(cpu->esi + 0x14u);
    cpu->ebx = lift_load32(cpu->esi + 8u);
    cpu->edi = (uint32_t)(cpu->ecx + cpu->eax + 1u);
    cpu->ecx += cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(lift_load32(cpu->esi + 0xCu));
    ++cpu->eax;
    lift_store16(cpu->ecx + cpu->ebx + 8u, cpu->edi & 0xFFFFu);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edx)) goto label_000310D0;
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    label_000310EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4310EFu);
    cpu->edx = lift_load16(cpu->esi + 0x14u);
    cpu->edx += cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(lift_load32(cpu->esi + 0xCu));
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = 0xFFFFu;
    lift_store16(cpu->edx + cpu->eax + 8u, cpu->ecx & 0xFFFFu);
    label_00031106: cpu->eip = LIFT_CODE_TOKEN_VA(0x431106u);
    cpu->edi = lift_load16(cpu->esi + 0x14u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(lift_load32(cpu->esi + 0xCu));
    cpu->edi += lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->ebp) != 0u) goto label_00031126;
    cpu->eax = 1u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x20u)) != (uint32_t)(cpu->eax)) goto label_00031126;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    goto label_00031132;
    label_00031126: cpu->eip = LIFT_CODE_TOKEN_VA(0x431126u);
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((uint32_t)(cpu->ebp) != 0u) goto label_00031146;
    label_00031132: cpu->eip = LIFT_CODE_TOKEN_VA(0x431132u);
    cpu->eax = cpu->ebx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00031137: cpu->eip = LIFT_CODE_TOKEN_VA(0x431137u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00031137;
    cpu->eax -= cpu->edx;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->ebp = cpu->eax;
    label_00031146: cpu->eip = LIFT_CODE_TOKEN_VA(0x431146u);
    if ((int32_t)(uint32_t)(cpu->ebp) <= (int32_t)(uint32_t)(lift_load32(cpu->esi))) goto label_00031154;
    cpu->ecx = (uint32_t)(uintptr_t)"CHash16::register_str: maxStrLen exceed";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x31154u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00031154: cpu->eip = LIFT_CODE_TOKEN_VA(0x431154u);
    cpu->edx = 0u;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00031190;
    cpu->ecx = (uint32_t)(cpu->edi + 0xAu);
    cpu->eax = (uint32_t)(cpu->edi + 0xAu);
    cpu->ebx -= cpu->ecx;
    label_00031162: cpu->eip = LIFT_CODE_TOKEN_VA(0x431162u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x14u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebx + cpu->eax)) & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00031175;
    cpu->ecx = cpu->ecx & 0xFFu;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_packet_codec_runtime.substitution[0]))) & 0xFFu);
    label_00031175: cpu->eip = LIFT_CODE_TOKEN_VA(0x431175u);
    lift_store8(cpu->eax, cpu->ecx & 0xFFu);
    cpu->ecx = cpu->ecx & 0xFFu;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_shift_right(cpu, (cpu->edx & 0xFFFFu), (uint32_t)(1u), 16u)) & 0xFFFFu);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFFFu)) + (uint64_t)(lift_load16(((uint32_t)(cpu->ecx) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_packet_codec_runtime.checksum[0]))) + (uint64_t)(0u))) & 0xFFFFu);
    ++cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    cpu->edx = cpu->edx & 0xFFFFu;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031162;
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    label_00031190: cpu->eip = LIFT_CODE_TOKEN_VA(0x431190u);
    cpu->ecx = lift_load16(cpu->esi + 0x14u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->edi + 8u)) & 0xFFFFu);
    lift_store16(cpu->esi + 0x14u, cpu->eax & 0xFFFFu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->edx = cpu->edx & 0xFFFFu;
    cpu->eax = (uint32_t)(cpu->esi + ((uint32_t)(cpu->edx) * 2u) + 0x16u);
    lift_store32(cpu->edi, cpu->ebp);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->eax)) & 0xFFFFu);
    lift_store16(cpu->edi + 8u, cpu->edx & 0xFFFFu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store16(cpu->eax, cpu->ecx & 0xFFFFu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004311D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4311D0u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4311E6u); lift_push32(cpu, r); sfera_sub_00431020(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004311F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4311F0u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x431206u); lift_push32(cpu, r); sfera_sub_00431020(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431210(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x431210u);
    cpu->eax = lift_load32(cpu->ecx + 0x6Cu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x431220u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->ecx + 0x2Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x30u, cpu->edx);
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431240(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x431240u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->ecx + 0x24u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx + 0x28u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431260(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x431260u);
    cpu->edx = lift_load32(cpu->ecx + 0x2Cu);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->ecx + 0x30u);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x431280u);
    cpu->edx = lift_load32(cpu->ecx + 0x24u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->ecx + 0x28u);
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004312A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4312A0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_store32(cpu->ecx + 0x24u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004312B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4312B0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_store32(cpu->ecx + 0x28u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004312C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4312C0u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(5u)) goto label_000312CD;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(4u)) goto label_000312CD;
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
    label_000312CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4312CDu);
    cpu->eax = 1u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004312E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4312E0u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->esp, cpu->ecx);
    if ((uint32_t)(cpu->edx) != 0u) goto label_000312F5;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->ecx + 0x10u))) goto label_0003136D;
    label_000312F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4312F5u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 0x10u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edi)) goto label_00031366;
    cpu->edi -= cpu->eax;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->edi)) goto label_00031366;
    cpu->esi = 1u;
    cpu->esi -= cpu->edx;
    cpu->edi += cpu->esi;
    if ((uint32_t)(lift_load32(cpu->ecx + 0x14u)) < (uint32_t)(0x10u)) goto label_00031317;
    cpu->ecx = lift_load32(cpu->ecx);
    label_00031317: cpu->eip = LIFT_CODE_TOKEN_VA(0x431317u);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    cpu->ebx = (uint32_t)(cpu->ecx + cpu->eax);
    cpu->eax = (int8_t)(lift_load8(cpu->ebp));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_memchr_address32(), LIFT_CODE_TOKEN_VA(0x431325u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43132Bu);
    cpu->esi = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00031366;
    label_00031334: cpu->eip = LIFT_CODE_TOKEN_VA(0x431334u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x431340u); lift_push32(cpu, r); sfera_sub_00401BE0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00031371;
    cpu->edx = (int8_t)(lift_load8(cpu->ebp));
    cpu->ebx -= cpu->esi;
    cpu->edi = (uint32_t)(cpu->edi + cpu->ebx + 0xFFFFFFFFu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->ebx = (uint32_t)(cpu->esi + 1u);
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_memchr_address32(), LIFT_CODE_TOKEN_VA(0x431357u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43135Du);
    cpu->esi = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00031334;
    label_00031366: cpu->eip = LIFT_CODE_TOKEN_VA(0x431366u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    label_0003136D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43136Du);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_00031371: cpu->eip = LIFT_CODE_TOKEN_VA(0x431371u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x14u)) < (uint32_t)(0x10u)) goto label_0003137D;
    cpu->ecx = lift_load32(cpu->ecx);
    label_0003137D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43137Du);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax -= cpu->ecx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x431390u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    cpu->eax = cpu->esi;
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000313A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4313A0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000313A0;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4313B5u); lift_push32(cpu, r); sfera_sub_004312E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004313F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4313F0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    cpu->edx = (uint32_t)(cpu->ecx + 8u);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 4u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x431408u); lift_push32(cpu, r); sfera_sub_004905D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431460(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x431460u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0xFFFFFFFFu);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x431482u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431490(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x431490u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = 0u;
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    std::construct_at(reinterpret_cast<HyperTextElement_WordWrap*>(cpu->esi));
    lift_push32(cpu, 0xFFFFFFFFu);
    lift_store32(cpu->ecx + 0x10u, cpu->eax);
    lift_store32(cpu->ecx + 0x14u, 0xFu);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->ecx, cpu->eax & 0xFFu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4314BAu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 4u, 3u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004314D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4314D0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    cpu->eax = 0u;
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx += 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store8(cpu->esi, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4314F6u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431500(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x431500u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->ebx = 0u;
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    lift_store32(cpu->esi + 4u, cpu->ebx);
    std::construct_at(reinterpret_cast<HyperTextElement*>(cpu->esi));
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->ecx + 0x14u, 0xFu);
    lift_store32(cpu->ecx + 0x10u, cpu->ebx);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->ecx, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x431550u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 4u, 1u);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = (uint32_t)(cpu->esi + 0x34u);
    std::construct_at(reinterpret_cast<HyperTextElementWithParameters*>(cpu->esi));
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->ecx + 0x14u, 0xFu);
    lift_store32(cpu->ecx + 0x10u, cpu->ebx);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    lift_store8(cpu->ecx, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43157Du); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 4u, 2u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004315A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4315A0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    cpu->eax = 0u;
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx += 0x34u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store8(cpu->esi, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4315C6u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004315D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4315D0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    lift_store32(cpu->esi + 4u, 0u);
    std::construct_at(reinterpret_cast<HyperTextElement*>(cpu->esi));
    lift_push32(cpu, 0u);
    lift_store32(cpu->ecx + 0x14u, 0xFu);
    lift_store32(cpu->ecx + 0x10u, 0u);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->ecx, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x431602u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esi + 0x30u, cpu->eax);
    std::construct_at(reinterpret_cast<HyperTextElement_PlainText*>(cpu->esi));
    lift_store32(cpu->esi + 0x24u, cpu->ecx);
    lift_store32(cpu->esi + 0x28u, 0u);
    lift_store32(cpu->esi + 0x2Cu, cpu->edx);
    lift_store32(cpu->esi + 4u, 4u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431640(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x431640u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store8(cpu->esi, cpu->eax & 0xFFu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43166Au); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431680(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x431680u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, 3u); lift_push32(cpu, 0u);
    cpu->esi = (uint32_t)(cpu->edi + 0x50u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"://");
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x14u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4316A0u); lift_push32(cpu, r); sfera_sub_004312E0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000316F7;
    cpu->edi = lift_load32(cpu->edi + 0x60u);
    cpu->ecx = (uint32_t)(cpu->eax + 3u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->edi)) goto label_000316F7;
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_000316B9;
    cpu->edx = lift_load32(cpu->esi);
    goto label_000316BB;
    label_000316B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4316B9u);
    cpu->edx = cpu->esi;
    label_000316BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4316BBu);
    if ((uint8_t)(lift_load8(cpu->edx + cpu->eax + 3u)) != (uint8_t)(0x2Fu)) goto label_000316E0;
    cpu->eax += 4u;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edi)) goto label_000316F7;
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4316D8u); lift_push32(cpu, r); sfera_sub_00431640(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000316E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4316E0u);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4316EFu); lift_push32(cpu, r); sfera_sub_00431640(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000316F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4316F7u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, 0u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"");
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43171Au); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x431730u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x431769u); lift_push32(cpu, r); sfera_sub_00431500(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = (uint32_t)(cpu->esi + 0x50u);
    std::construct_at(reinterpret_cast<HyperTextElement_Link*>(cpu->esi));
    lift_push32(cpu, 0u);
    lift_store32(cpu->ecx + 0x14u, 0xFu);
    lift_store32(cpu->ecx + 0x10u, 0u);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x20u, 0u);
    lift_store8(cpu->ecx, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x431799u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esi + 0x6Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esi + 0x30u, cpu->eax);
    lift_store32(cpu->esi + 0x24u, cpu->ecx);
    lift_store32(cpu->esi + 0x28u, 0u);
    lift_store32(cpu->esi + 0x2Cu, cpu->edx);
    lift_store32(cpu->esi + 4u, 5u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 28u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004317E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4317E0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->ecx += 8u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4317F1u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x431800u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_vswprintf), LIFT_CODE_TOKEN_VA(0x43180Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x431815u);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431820(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x431820u);
    cpu->eax = cpu->ecx;
    if ((uint32_t)(cpu->eax) > (uint32_t)(0xFFFFu)) goto label_00031842;
    cpu->edx = cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    if ((uint32_t)(lift_load32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id))) != (uint32_t)(cpu->eax)) goto label_00031842;
    if ((int32_t)(uint32_t)(lift_load32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))) >= (int32_t)(uint32_t)(0u)) goto label_00031845;
    label_00031842: cpu->eip = LIFT_CODE_TOKEN_VA(0x431842u);
    cpu->eax |= 0xFFFFFFFFu;
    label_00031845: cpu->eip = LIFT_CODE_TOKEN_VA(0x431845u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x431850u);
    cpu->ecx -= cpu->edx;
    cpu->eax = cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x3840u)) goto label_00031872;
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_0003186B;
    cpu->eax = (uint32_t)(cpu->ecx + 0x8000u);
    lift_return(cpu, 0u, stop_address); return;
    label_0003186B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43186Bu);
    cpu->eax = (uint32_t)(cpu->ecx + 0xFFFF8000u);
    lift_return(cpu, 0u, stop_address); return;
    label_00031872: cpu->eip = LIFT_CODE_TOKEN_VA(0x431872u);
    cpu->eax = cpu->ecx;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431880(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x431880u);
    cpu->esp -= 0x1B4u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::sprintf);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = 0u;
    label_000318A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4318A0u);
    cpu->eax = g_sfera_network_runtime.local_port_candidate;
    ++cpu->eax;
    g_sfera_network_runtime.local_port_candidate = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(0x68ECu)) goto label_000318BC;
    cpu->eax = 0x68EAu;
    g_sfera_network_runtime.local_port_candidate = (uint32_t)(cpu->eax);
    label_000318BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4318BCu);
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->eax;
    cpu->eax = (uint32_t)(cpu->esp + 0x1B4u);
    lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x318CEu), LIFT_CODE_TOKEN_RVA(0x318CCu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4318CEu);
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x202u);
    lift_native_call(cpu, native_function_address32(&::WSAStartup), LIFT_CODE_TOKEN_VA(0x4318DBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4318E0u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0003194A;
    lift_push32(cpu, (uint32_t)(uintptr_t)"");
    lift_native_call(cpu, native_function_address32(&::gethostbyname), LIFT_CODE_TOKEN_VA(0x4318E9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4318EEu);
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::inet_ntoa), LIFT_CODE_TOKEN_VA(0x4318F6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4318FBu);
    cpu->edx = 2u;
    lift_push32(cpu, cpu->eax);
    lift_store16(cpu->esp + 0x14u, cpu->edx & 0xFFFFu);
    lift_native_call(cpu, native_function_address32(&::inet_addr), LIFT_CODE_TOKEN_VA(0x431906u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43190Bu);
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::htons), LIFT_CODE_TOKEN_VA(0x431910u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x431915u);
    lift_push32(cpu, 0u); lift_push32(cpu, 2u); lift_push32(cpu, 2u);
    lift_store16(cpu->esp + 0x1Eu, cpu->eax & 0xFFFFu);
    lift_native_call(cpu, native_function_address32(&::socket), LIFT_CODE_TOKEN_VA(0x431920u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x431925u);
    cpu->esi = cpu->eax;
    lift_push32(cpu, 0x10u);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::bind), LIFT_CODE_TOKEN_VA(0x43192Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x431934u);
    lift_push32(cpu, cpu->esi);
    cpu->edi = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::closesocket), LIFT_CODE_TOKEN_VA(0x431937u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43193Cu);
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x43193Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x431941u);
    { uint64_t v=(uint64_t)(cpu->edi); lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00031972;
    label_0003194A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43194Au);
    ++cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(3u)) goto label_000318A0;
    cpu->eax = 0x68EAu;
    label_00031959: cpu->eip = LIFT_CODE_TOKEN_VA(0x431959u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1B4u;
    lift_return(cpu, 0u, stop_address); return;
    label_00031972: cpu->eip = LIFT_CODE_TOKEN_VA(0x431972u);
    cpu->eax = g_sfera_network_runtime.local_port_candidate;
    goto label_00031959;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x431980u);
    cpu->eax = g_sfera_directplay_runtime.peer;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000319F6;
    lift_push32(cpu, 0u);
    g_sfera_directplay_runtime.connection_info.size = (uint32_t)(0x5Cu);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x50u);
    lift_push32(cpu, (uintptr_t)&g_sfera_directplay_runtime.connection_info); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x319A2u), LIFT_CODE_TOKEN_RVA(0x319A0u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4319A2u);
    cpu->eax = lift_load32((uintptr_t)&g_sfera_directplay_runtime.connection_info.bytes_sent_guaranteed);
    cpu->eax += lift_load32((uint32_t)(uintptr_t)&g_sfera_directplay_runtime.connection_info.bytes_sent_non_guaranteed);
    cpu->edx = cpu->eax;
    cpu->edx -= g_sfera_recovered_static_runtime.network_bytes_received_snapshot;
    g_sfera_recovered_static_runtime.network_bytes_received_snapshot = (uint32_t)(cpu->eax);
    cpu->eax = lift_load32((uintptr_t)&g_sfera_directplay_runtime.connection_info.bytes_retried);
    cpu->ecx = cpu->eax;
    cpu->ecx -= g_sfera_recovered_static_runtime.network_bytes_retried_snapshot;
    g_sfera_recovered_static_runtime.network_bytes_retried_snapshot = (uint32_t)(cpu->eax);
    cpu->eax = lift_load32((uintptr_t)&g_sfera_directplay_runtime.connection_info.bytes_received_non_guaranteed);
    cpu->eax += lift_load32((uint32_t)(uintptr_t)&g_sfera_directplay_runtime.connection_info.bytes_received_guaranteed);
    g_sfera_network_runtime.bytes_retried_delta = (uint32_t)(cpu->ecx);
    cpu->ecx = cpu->eax;
    cpu->ecx -= g_sfera_recovered_static_runtime.network_bytes_sent_snapshot;
    g_sfera_network_runtime.bytes_sent_delta = (uint32_t)(cpu->edx);
    g_sfera_network_runtime.bytes_received_delta = (uint32_t)(cpu->ecx);
    g_sfera_recovered_static_runtime.network_bytes_sent_snapshot = (uint32_t)(cpu->eax);
    label_000319F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4319F6u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431A00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x431A00u);
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_24)) == (uint32_t)(0u)) goto label_00031A60;
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_window_runtime.timing_critical_section[0]);
    g_sfera_directplay_runtime.connection_info.size = (uint32_t)(0x5Cu);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x431A18u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x431A1Eu);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_24;
    cpu->ecx = lift_load32(cpu->eax + 0xEAA8u);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_window_runtime.timing_critical_section[0]);
    g_sfera_directplay_runtime.connection_info.round_trip_latency_ms = (uint32_t)(cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x431A34u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x431A3Au);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_24;
    cpu->edx = lift_load32(cpu->eax + 0xEA94u);
    g_sfera_network_runtime.bytes_sent_delta = (uint32_t)(cpu->edx);
    g_sfera_network_runtime.bytes_retried_delta = (uint32_t)(0u);
    cpu->eax = lift_load32(cpu->eax + 0xEA98u);
    g_sfera_network_runtime.bytes_received_delta = (uint32_t)(cpu->eax);
    label_00031A60: cpu->eip = LIFT_CODE_TOKEN_VA(0x431A60u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431A70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x431A70u);
    cpu->esp -= 0x24u;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFF0005u)) goto label_00031AAE;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFF0016u)) goto label_00031AAE;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFF0009u)) goto label_00031AAE;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFF000Eu)) goto label_00031AAE;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFF000Fu)) goto label_00031AAE;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(0xFFFF0007u)) goto label_00031ACF;
    label_00031AAE: cpu->eip = LIFT_CODE_TOKEN_VA(0x431AAEu);
    cpu->eax = cpu->ecx & 0xFFFFu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, (uintptr_t)"MessID: %u\n"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x431ABCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x431AC2u);
    cpu->esp += 0xCu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x31ACFu); lift_push32(cpu, r); sfera_sub_0047FED0(cpu,r); if (cpu->eip != r) return; }
    label_00031ACF: cpu->eip = LIFT_CODE_TOKEN_VA(0x431ACFu);
    cpu->esp += 0x24u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431AE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x431AE0u);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_directplay_runtime.critical_section[0]);
    lift_native_call(cpu, native_function_address32(&::EnterCriticalSection), LIFT_CODE_TOKEN_VA(0x431AE5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x431AEBu);
    cpu->eax = g_sfera_directplay_runtime.transport.receive_write_index;
    cpu->edx = 0u;
    cpu->ecx = 1u;
    if ((uint8_t)(g_sfera_directplay_runtime.transport.receive_busy) == (uint8_t)((cpu->edx & 0xFFu))) goto label_00031B0D;
    g_sfera_directplay_runtime.transport.receive_corrupted = (uint8_t)((cpu->ecx & 0xFFu));
    if ((uint32_t)(cpu->eax) == (uint32_t)(g_sfera_directplay_runtime.transport.receive_read_index)) goto label_00031B13;
    label_00031B0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x431B0Du);
    g_sfera_directplay_runtime.transport.receive_corrupted = (uint8_t)((cpu->edx & 0xFFu));
    label_00031B13: cpu->eip = LIFT_CODE_TOKEN_VA(0x431B13u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->eax;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x1A8u);
    cpu->eax += cpu->ecx;
    cpu->esi += ((uint32_t)(uintptr_t)&g_sfera_network_runtime.message_slots[0]);
    g_sfera_directplay_runtime.transport.receive_write_index = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xBE8u)) goto label_00031B36;
    g_sfera_directplay_runtime.transport.receive_write_index = (uint32_t)(cpu->edx);
    label_00031B36: cpu->eip = LIFT_CODE_TOKEN_VA(0x431B36u);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_directplay_runtime.critical_section[0]);
    g_sfera_directplay_runtime.transport.receive_busy = (uint8_t)((cpu->ecx & 0xFFu));
    lift_native_call(cpu, native_function_address32(&::LeaveCriticalSection), LIFT_CODE_TOKEN_VA(0x431B41u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x431B47u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431B50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x431B50u);
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled)) == (uint8_t)(1u)) goto label_00031C12;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x431B69u); lift_push32(cpu, r); sfera_sub_00431A70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFF0005u)) goto label_00031BFC;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFF0011u)) goto label_00031BA0;
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFF0016u)) goto label_00031C11;
    g_sfera_network_runtime.initialization_result = (uint32_t)(0xFFFFFFFFu);
    g_sfera_network_runtime.timeout_marker_pending = (uint8_t)(1u);
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    lift_return(cpu, 12u, stop_address); return;
    label_00031BA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x431BA0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x431BA5u); lift_push32(cpu, r); sfera_sub_00431AE0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_directplay_runtime.transport.sent_packet_count, (uint64_t)(g_sfera_directplay_runtime.transport.sent_packet_count) + 1u);
    lift_store32(cpu->eax, 0xFFFF0011u);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store32(cpu->eax + 8u, 0xFFFFFFFFu);
    cpu->ecx = lift_load32(cpu->edx + 0x10u);
    { uint64_t l=(uint64_t)(g_sfera_directplay_runtime.transport.sent_bytes.low), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); lift_store32((uint32_t)(uintptr_t)&g_sfera_directplay_runtime.transport.sent_bytes.low, v); }
    lift_store32((uint32_t)(uintptr_t)&g_sfera_directplay_runtime.transport.sent_bytes.high, (uint64_t)(g_sfera_directplay_runtime.transport.sent_bytes.high) + (uint64_t)(0u) + (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)));
    if ((uint32_t)(cpu->ecx) < (uint32_t)(0x190u)) goto label_00031BDF;
    cpu->ecx = 0x18Fu;
    label_00031BDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x431BDFu);
    lift_store32(cpu->eax + 0x19Cu, cpu->ecx);
    cpu->edx = lift_load32(cpu->edx + 0xCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->eax += 0xCu;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x431BEEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x431BF3u);
    cpu->esp += 0xCu;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    lift_return(cpu, 12u, stop_address); return;
    label_00031BFC: cpu->eip = LIFT_CODE_TOKEN_VA(0x431BFCu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + 0xCu)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->eax + cpu->eax + 0xFFFFFFFFu);
    g_sfera_network_runtime.initialization_result = (uint32_t)(cpu->eax);
    label_00031C11: cpu->eip = LIFT_CODE_TOKEN_VA(0x431C11u);
    cpu->esi = lift_pop32(cpu);
    label_00031C12: cpu->eip = LIFT_CODE_TOKEN_VA(0x431C12u);
    cpu->eax = 0u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00431C20(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00031C20;
    label_0002EA80: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EA80u);
    cpu->eax = 0x1010u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42EA8Au); lift_push32(cpu, r); sfera_sub_004EEAF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(uintptr_t)"NetError.log";
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"r"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x42EAA4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42EAAAu);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0002EB58;
    lift_push32(cpu, 0x1000u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x42EAC3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42EAC8u);
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0002EAD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EAD0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_error_log_runtime.index_table[0]))) & 0xFFu);
    lift_store8(cpu->esp + cpu->eax + 0x11u, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0002EAD0;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0xF7Bu);
    cpu->edx = (uint32_t)(cpu->esp + 0x9Du);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    lift_store8(cpu->esp + 0x20u, 4u);
    lift_native_call(cpu, native_function_address32(&::fread), LIFT_CODE_TOKEN_VA(0x42EAF4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42EAFAu);
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0xA5u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x42EB02u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42EB08u);
    cpu->esp += 0x14u;
    lift_push32(cpu, 0xB8u);
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0x2BF20u);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    cpu->eax = g_sfera_directplay_runtime.peer;
    lift_push32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x1Cu, 0x1000u);
    lift_store32(cpu->esp + 0x18u, 0u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x20u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x2EB48u), LIFT_CODE_TOKEN_RVA(0x2EB46u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42EB48u);
    cpu->ecx = (uint32_t)(uintptr_t)"NetError.log";
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x42EB4Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42EB55u);
    cpu->esp += 4u;
    label_0002EB58: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EB58u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1010u;
    lift_return(cpu, 0u, stop_address); return;
    label_00031C20: cpu->eip = LIFT_CODE_TOKEN_VA(0x431C20u);
    cpu->esp -= 0x38u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(3u)) goto label_000326BD;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFF0011u)) goto label_00032784;
    cpu->eax = lift_load32(cpu->edi + 0x19Cu);
    cpu->edx = 1u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_00031C63;
    if ((uint8_t)(lift_load8(cpu->edi + 0xCu)) != (uint8_t)(2u)) goto label_00031C63;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x431C58u); lift_push32(cpu, r); sfera_sub_0042E990(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    goto label_0002EA80;
    label_00031C63: cpu->eip = LIFT_CODE_TOKEN_VA(0x431C63u);
    cpu->ecx = 0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = (uint32_t)(cpu->edi + 0xDu);
    lift_store8(cpu->eax + cpu->ebp + 0xFFFFFFFFu, cpu->ecx & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp)) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) & (uint64_t)(1u))) & 0xFFu);
    lift_store32(cpu->esp + 0x40u, cpu->ecx);
    lift_store8(cpu->esp + 0x40u, cpu->eax & 0xFFu);
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x38u, cpu->ecx);
    lift_store32(cpu->esp + 0x34u, cpu->ecx);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x40u)), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031DF2;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(2u) & 0xFFu);
    cpu->esi = cpu->ebp;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    cpu->edi = 4u;
    label_00031CA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x431CA7u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031CAF;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00031CB5;
    label_00031CAF: cpu->eip = LIFT_CODE_TOKEN_VA(0x431CAFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00031CB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x431CB5u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031CBC;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031CBC: cpu->eip = LIFT_CODE_TOKEN_VA(0x431CBCu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031CC3;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031CC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x431CC3u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031CCB;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00031CD1;
    label_00031CCB: cpu->eip = LIFT_CODE_TOKEN_VA(0x431CCBu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00031CD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x431CD1u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031CD8;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031CD8: cpu->eip = LIFT_CODE_TOKEN_VA(0x431CD8u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031CDF;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031CDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x431CDFu);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031CE7;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00031CED;
    label_00031CE7: cpu->eip = LIFT_CODE_TOKEN_VA(0x431CE7u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00031CED: cpu->eip = LIFT_CODE_TOKEN_VA(0x431CEDu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031CF4;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031CF4: cpu->eip = LIFT_CODE_TOKEN_VA(0x431CF4u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031CFB;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031CFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x431CFBu);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031D03;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00031D09;
    label_00031D03: cpu->eip = LIFT_CODE_TOKEN_VA(0x431D03u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00031D09: cpu->eip = LIFT_CODE_TOKEN_VA(0x431D09u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031D10;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031D10: cpu->eip = LIFT_CODE_TOKEN_VA(0x431D10u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031D17;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031D17: cpu->eip = LIFT_CODE_TOKEN_VA(0x431D17u);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031CA7;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(2u) & 0xFFu);
    cpu->esi = (uint32_t)(cpu->ebp + 2u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    cpu->edi = 0xDu;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00031D30: cpu->eip = LIFT_CODE_TOKEN_VA(0x431D30u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031D38;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00031D3E;
    label_00031D38: cpu->eip = LIFT_CODE_TOKEN_VA(0x431D38u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00031D3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x431D3Eu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031D45;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031D45: cpu->eip = LIFT_CODE_TOKEN_VA(0x431D45u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031D4C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031D4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x431D4Cu);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031D30;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(0x40u) & 0xFFu);
    cpu->esi = (uint32_t)(cpu->ebp + 3u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    cpu->edi = 4u;
    (void)cpu;
    label_00031D60: cpu->eip = LIFT_CODE_TOKEN_VA(0x431D60u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031D68;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00031D6E;
    label_00031D68: cpu->eip = LIFT_CODE_TOKEN_VA(0x431D68u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00031D6E: cpu->eip = LIFT_CODE_TOKEN_VA(0x431D6Eu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031D75;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031D75: cpu->eip = LIFT_CODE_TOKEN_VA(0x431D75u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031D7C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031D7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x431D7Cu);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031D84;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00031D8A;
    label_00031D84: cpu->eip = LIFT_CODE_TOKEN_VA(0x431D84u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00031D8A: cpu->eip = LIFT_CODE_TOKEN_VA(0x431D8Au);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031D91;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031D91: cpu->eip = LIFT_CODE_TOKEN_VA(0x431D91u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031D98;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031D98: cpu->eip = LIFT_CODE_TOKEN_VA(0x431D98u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031DA0;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00031DA6;
    label_00031DA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x431DA0u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00031DA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x431DA6u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031DAD;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031DAD: cpu->eip = LIFT_CODE_TOKEN_VA(0x431DADu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031DB4;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031DB4: cpu->eip = LIFT_CODE_TOKEN_VA(0x431DB4u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031DBC;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00031DC2;
    label_00031DBC: cpu->eip = LIFT_CODE_TOKEN_VA(0x431DBCu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00031DC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x431DC2u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031DC9;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031DC9: cpu->eip = LIFT_CODE_TOKEN_VA(0x431DC9u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031DD0;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031DD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x431DD0u);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031D60;
    lift_store32(cpu->esp + 0x38u, (uint64_t)(lift_load32(cpu->esp + 0x38u)) - (uint64_t)(0x4B0u) - (uint64_t)(0u));
    cpu->eax = 0x8000u;
    lift_store32(cpu->esp + 0x34u, (uint64_t)(lift_load32(cpu->esp + 0x34u)) - (uint64_t)(cpu->eax) - (uint64_t)(0u));
    lift_store32(cpu->esp + 0x3Cu, (uint64_t)(lift_load32(cpu->esp + 0x3Cu)) - (uint64_t)(cpu->eax) - (uint64_t)(0u));
    lift_store32(cpu->esp + 0x10u, 0x2Eu);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    label_00031DF2: cpu->eip = LIFT_CODE_TOKEN_VA(0x431DF2u);
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->edx & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ebp);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    cpu->edi = 3u;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00031E20: cpu->eip = LIFT_CODE_TOKEN_VA(0x431E20u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031E28;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00031E2E;
    label_00031E28: cpu->eip = LIFT_CODE_TOKEN_VA(0x431E28u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00031E2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x431E2Eu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031E35;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031E35: cpu->eip = LIFT_CODE_TOKEN_VA(0x431E35u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031E3C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031E3C: cpu->eip = LIFT_CODE_TOKEN_VA(0x431E3Cu);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031E44;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00031E4A;
    label_00031E44: cpu->eip = LIFT_CODE_TOKEN_VA(0x431E44u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00031E4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x431E4Au);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031E51;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031E51: cpu->eip = LIFT_CODE_TOKEN_VA(0x431E51u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031E58;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031E58: cpu->eip = LIFT_CODE_TOKEN_VA(0x431E58u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031E60;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00031E66;
    label_00031E60: cpu->eip = LIFT_CODE_TOKEN_VA(0x431E60u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00031E66: cpu->eip = LIFT_CODE_TOKEN_VA(0x431E66u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031E6D;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031E6D: cpu->eip = LIFT_CODE_TOKEN_VA(0x431E6Du);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031E74;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031E74: cpu->eip = LIFT_CODE_TOKEN_VA(0x431E74u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031E7C;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00031E82;
    label_00031E7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x431E7Cu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00031E82: cpu->eip = LIFT_CODE_TOKEN_VA(0x431E82u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031E89;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031E89: cpu->eip = LIFT_CODE_TOKEN_VA(0x431E89u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031E90;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031E90: cpu->eip = LIFT_CODE_TOKEN_VA(0x431E90u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031E98;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00031E9E;
    label_00031E98: cpu->eip = LIFT_CODE_TOKEN_VA(0x431E98u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00031E9E: cpu->eip = LIFT_CODE_TOKEN_VA(0x431E9Eu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031EA5;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031EA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x431EA5u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031EAC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031EAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x431EACu);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031E20;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(0xFu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    label_00031EC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x431EC0u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->edx & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ebp);
    lift_store32(cpu->esp + 0x20u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    cpu->edi = 3u;
    label_00031EF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x431EF0u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031EF8;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00031EFE;
    label_00031EF8: cpu->eip = LIFT_CODE_TOKEN_VA(0x431EF8u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00031EFE: cpu->eip = LIFT_CODE_TOKEN_VA(0x431EFEu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031F05;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031F05: cpu->eip = LIFT_CODE_TOKEN_VA(0x431F05u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031F0C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031F0C: cpu->eip = LIFT_CODE_TOKEN_VA(0x431F0Cu);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031F14;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00031F1A;
    label_00031F14: cpu->eip = LIFT_CODE_TOKEN_VA(0x431F14u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00031F1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x431F1Au);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031F21;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031F21: cpu->eip = LIFT_CODE_TOKEN_VA(0x431F21u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031F28;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031F28: cpu->eip = LIFT_CODE_TOKEN_VA(0x431F28u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031F30;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00031F36;
    label_00031F30: cpu->eip = LIFT_CODE_TOKEN_VA(0x431F30u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00031F36: cpu->eip = LIFT_CODE_TOKEN_VA(0x431F36u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031F3D;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031F3D: cpu->eip = LIFT_CODE_TOKEN_VA(0x431F3Du);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031F44;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031F44: cpu->eip = LIFT_CODE_TOKEN_VA(0x431F44u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031F4C;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00031F52;
    label_00031F4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x431F4Cu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00031F52: cpu->eip = LIFT_CODE_TOKEN_VA(0x431F52u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031F59;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031F59: cpu->eip = LIFT_CODE_TOKEN_VA(0x431F59u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031F60;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031F60: cpu->eip = LIFT_CODE_TOKEN_VA(0x431F60u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031F68;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00031F6E;
    label_00031F68: cpu->eip = LIFT_CODE_TOKEN_VA(0x431F68u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00031F6E: cpu->eip = LIFT_CODE_TOKEN_VA(0x431F6Eu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031F75;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031F75: cpu->eip = LIFT_CODE_TOKEN_VA(0x431F75u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031F7C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031F7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x431F7Cu);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00031F84;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00031F8A;
    label_00031F84: cpu->eip = LIFT_CODE_TOKEN_VA(0x431F84u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00031F8A: cpu->eip = LIFT_CODE_TOKEN_VA(0x431F8Au);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031F91;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00031F91: cpu->eip = LIFT_CODE_TOKEN_VA(0x431F91u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031F98;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00031F98: cpu->eip = LIFT_CODE_TOKEN_VA(0x431F98u);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00031EF0;
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(0x12u) + (uint64_t)(0u));
    lift_push32(cpu, 4u); lift_push32(cpu, 0xCu);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->esp + 0x54u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 0x2Cu, cpu->esi);
    lift_store32(cpu->esp + 0x54u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x431FC5u); lift_push32(cpu, r); sfera_sub_004013D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) != (uint32_t)(cpu->esi)) goto label_000320EF;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0xFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00032080;
    cpu->eax = cpu->edi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id))), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032080;
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))), r=(uint64_t)(cpu->esi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00032080;
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0]));
    cpu->edx = (uint32_t)(uintptr_t)"EKill";
    g_sfera_mbc_runtime->active_process = (uint32_t)(cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x432015u); lift_push32(cpu, r); sfera_sub_00435020(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00032043;
    cpu->eax = g_sfera_mbc_runtime->active_process;
    lift_store32(cpu->eax + 0x94u, (uint64_t)(lift_load32(cpu->eax + 0x94u)) | (uint64_t)(4u));
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    lift_store8(cpu->ecx + 0xB8u, 1u);
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->ecx = lift_load32(cpu->edx + 0xB4u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x32043u); lift_push32(cpu, r); sfera_sub_00433CF0(cpu,r); if (cpu->eip != r) return; }
    label_00032043: cpu->eip = LIFT_CODE_TOKEN_VA(0x432043u);
    cpu->eax = g_sfera_mbc_runtime->active_process;
    lift_store32(cpu->eax + 0x94u, (uint64_t)(lift_load32(cpu->eax + 0x94u)) | (uint64_t)(0x20u));
    cpu->edx = g_sfera_mbc_runtime->active_process;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edx + 0xB4u)), r=(uint64_t)(cpu->esi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032080;
    cpu->eax = lift_load32(cpu->esp + 0x40u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x690u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\INet.cpp"); lift_push32(cpu, (uintptr_t)"Unloading _main: %s:%d, %d, %d, %d, %d\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43207Du); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=cpu->esp, r=(uint64_t)(0x1Cu), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    label_00032080: cpu->eip = LIFT_CODE_TOKEN_VA(0x432080u);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->eax = cpu->ebp;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->edx & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ecx);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    cpu->edi = 7u;
    cpu->edi = cpu->edi;
    label_000320B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4320B0u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_000320B8;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_000320BE;
    label_000320B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4320B8u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_000320BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4320BEu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000320C5;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_000320C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4320C5u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000320CC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_000320CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4320CCu);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000320B0;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ebp += 7u;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x3Fu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00031EC0;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00032783;
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    label_000320EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4320EFu);
    if ((uint32_t)(cpu->edi) > (uint32_t)(0xFFFFu)) goto label_0003212F;
    cpu->eax = cpu->edi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id))) != (uint32_t)(cpu->edi)) goto label_0003211F;
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))) < (int32_t)(uint32_t)(0u)) goto label_0003211F;
    cpu->esi = cpu->edi;
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    if ((uint32_t)(cpu->edi) != (uint32_t)(0xFFFFFFFFu)) goto label_000321B1;
    label_0003211F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43211Fu);
    if ((uint32_t)(cpu->edi) > (uint32_t)(0xFFFFu)) goto label_0003212F;
    cpu->esi = cpu->edi;
    lift_store32(cpu->esp + 0x28u, cpu->edi);
    goto label_00032136;
    label_0003212F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43212Fu);
    cpu->esi |= 0xFFFFFFFFu;
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    label_00032136: cpu->eip = LIFT_CODE_TOKEN_VA(0x432136u);
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id))) == (uint32_t)(cpu->edi)) goto label_0003218E;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x8D8u);
    cpu->ecx += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0]);
    cpu->edx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43215Du); lift_push32(cpu, r); sfera_sub_00435230(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    if ((uint32_t)(cpu->esi) > (uint32_t)(0xFFFFu)) goto label_00032783;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id))) != (uint32_t)(cpu->esi)) goto label_00032783;
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))) < (int32_t)(uint32_t)(0u)) goto label_00032783;
    label_0003218E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43218Eu);
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_00032783;
    lift_store32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].flags), (uint64_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].flags))) | (uint64_t)(4u));
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0]));
    cpu->ecx = cpu->esi;
    lift_store8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].state_byte_b8), 1u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x321B1u); lift_push32(cpu, r); sfera_sub_00433CF0(cpu,r); if (cpu->eip != r) return; }
    label_000321B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4321B1u);
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_00032783;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0])), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->esi = v; }
    g_sfera_mbc_runtime->active_process = (uint32_t)(cpu->esi);
    label_000321D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4321D0u);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->eax = cpu->ebp;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->edx & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ecx);
    lift_store32(cpu->esp + 0x14u, 0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    cpu->edi = 7u;
    label_00032202: cpu->eip = LIFT_CODE_TOKEN_VA(0x432202u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003220A;
    lift_store8(cpu->ecx, (uint64_t)(lift_load8(cpu->ecx)) | (uint64_t)((cpu->eax & 0xFFu)));
    goto label_00032210;
    label_0003220A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43220Au);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->ecx, (uint64_t)(lift_load8(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00032210: cpu->eip = LIFT_CODE_TOKEN_VA(0x432210u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032217;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->ecx;
    label_00032217: cpu->eip = LIFT_CODE_TOKEN_VA(0x432217u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003221E;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_0003221E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43221Eu);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032202;
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    cpu->eax = lift_load32(cpu->ecx + 0xD0u);
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 8u));
    cpu->ebp += 7u;
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    lift_store32(cpu->esp + 0x2Cu, cpu->edx);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0x3Fu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00031EC0;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00032783;
    --cpu->esi;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0x3Du), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0003267D;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003226B;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000322F1;
    label_0003226B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43226Bu);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x6Cu)) == (uint32_t)(0xFFFFFFFFu)) goto label_000322A0;
    if ((uint8_t)((lift_load8(cpu->ecx + 0x94u)) & (0x20u)) == 0u) goto label_000322C7;
    cpu->edi = lift_load32(cpu->esp + 0x28u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_00032299;
    lift_push32(cpu, 0x6FFu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\INet.cpp"); lift_push32(cpu, (uintptr_t)"Unloading _main: %s:%d\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x432296u); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_00032299: cpu->eip = LIFT_CODE_TOKEN_VA(0x432299u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x322A0u); lift_push32(cpu, r); sfera_sub_00435D40(cpu,r); if (cpu->eip != r) return; }
    label_000322A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4322A0u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x8D8u);
    cpu->ecx += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4322B9u); lift_push32(cpu, r); sfera_sub_00435230(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0003267D;
    label_000322C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4322C7u);
    lift_store32(cpu->ecx + 0x94u, (uint64_t)(lift_load32(cpu->ecx + 0x94u)) & (uint64_t)(0xFFFFFFFBu));
    cpu->eax = g_sfera_mbc_runtime->active_process;
    lift_store8(cpu->eax + 0xB8u, 1u);
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->ecx = lift_load32(cpu->edx + 0xB4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4322EBu); lift_push32(cpu, r); sfera_sub_00433CF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    label_000322F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4322F1u);
    cpu->eax = lift_load32(cpu->ecx + 0xD0u);
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 8u));
    cpu->edi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    cpu->edx = lift_load16(cpu->edi + 0x22u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    if ((uint32_t)(cpu->edx) == (uint32_t)(0xFFFFu)) goto label_00032318;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x432312u); lift_push32(cpu, r); sfera_sub_004350C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    label_00032318: cpu->eip = LIFT_CODE_TOKEN_VA(0x432318u);
    cpu->eax = lift_load32(cpu->edi + 0x1Cu);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0003267D;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = 0u;
    cpu->edi = 0u;
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x44u, cpu->edx);
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0003254D;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00032340: cpu->eip = LIFT_CODE_TOKEN_VA(0x432340u);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->eax = (int8_t)(lift_load8(cpu->edi + cpu->eax));
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(0x20u)) goto label_00032359;
    cpu->ebp += cpu->eax;
    goto label_0003252E;
    label_00032359: cpu->eip = LIFT_CODE_TOKEN_VA(0x432359u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x65u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000323E6;
    cpu->edx = cpu->ebp;
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx) * 8u));
    cpu->ecx = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->eax & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->ecx += cpu->edx;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx)), r=(uint64_t)((cpu->eax & 0xFFu)), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003238C;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->ecx;
    label_0003238C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43238Cu);
    if ((uint8_t)((lift_load8(cpu->ecx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_00032395;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) | (uint64_t)(2u))) & 0xFFu);
    goto label_00032398;
    label_00032395: cpu->eip = LIFT_CODE_TOKEN_VA(0x432395u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) & (uint64_t)(0xFDu))) & 0xFFu);
    label_00032398: cpu->eip = LIFT_CODE_TOKEN_VA(0x432398u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003239F;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->ecx;
    label_0003239F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43239Fu);
    if ((uint8_t)((lift_load8(cpu->ecx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_000323A8;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) | (uint64_t)(4u))) & 0xFFu);
    goto label_000323AB;
    label_000323A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4323A8u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) & (uint64_t)(0xFBu))) & 0xFFu);
    label_000323AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4323ABu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000323B2;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->ecx;
    label_000323B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4323B2u);
    if ((uint8_t)((lift_load8(cpu->ecx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_000323CE;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) | (uint64_t)(8u))) & 0xFFu);
    cpu->ebp += 4u;
    ++cpu->edi;
    lift_store8(cpu->esp + 0x10u, cpu->edx & 0xFFu);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    goto label_0003252E;
    label_000323CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4323CEu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) & (uint64_t)(0xF7u))) & 0xFFu);
    cpu->ebp += 4u;
    ++cpu->edi;
    lift_store8(cpu->esp + 0x10u, cpu->edx & 0xFFu);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    goto label_0003252E;
    label_000323E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4323E6u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x66u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000324AA;
    cpu->eax = cpu->ebp;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->edx & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ecx);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    cpu->edi = 2u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00032420: cpu->eip = LIFT_CODE_TOKEN_VA(0x432420u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032428;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_0003242E;
    label_00032428: cpu->eip = LIFT_CODE_TOKEN_VA(0x432428u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_0003242E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43242Eu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032435;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032435: cpu->eip = LIFT_CODE_TOKEN_VA(0x432435u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003243C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_0003243C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43243Cu);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032444;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_0003244A;
    label_00032444: cpu->eip = LIFT_CODE_TOKEN_VA(0x432444u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_0003244A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43244Au);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032451;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032451: cpu->eip = LIFT_CODE_TOKEN_VA(0x432451u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032458;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032458: cpu->eip = LIFT_CODE_TOKEN_VA(0x432458u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032460;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00032466;
    label_00032460: cpu->eip = LIFT_CODE_TOKEN_VA(0x432460u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00032466: cpu->eip = LIFT_CODE_TOKEN_VA(0x432466u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003246D;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_0003246D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43246Du);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032474;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032474: cpu->eip = LIFT_CODE_TOKEN_VA(0x432474u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003247C;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00032482;
    label_0003247C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43247Cu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00032482: cpu->eip = LIFT_CODE_TOKEN_VA(0x432482u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032489;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032489: cpu->eip = LIFT_CODE_TOKEN_VA(0x432489u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032490;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032490: cpu->eip = LIFT_CODE_TOKEN_VA(0x432490u);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032420;
    cpu->edi = lift_load32(cpu->esp + 0x30u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    ++cpu->edi;
    cpu->ebp += 8u;
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    cpu->ebx = 0u;
    goto label_0003252E;
    label_000324AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4324AAu);
    cpu->edx = (uint32_t)(cpu->eax + 0xFFFFFF97u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(2u)) goto label_000324B7;
    cpu->ebp += 0xCu;
    goto label_0003252E;
    label_000324B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4324B7u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x67u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032526;
    cpu->edx = (uint32_t)(cpu->ebp + 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx) * 8u));
    cpu->ecx = (uint32_t)(cpu->ebp + 1u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->eax & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx += cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edx)), r=(uint64_t)((cpu->eax & 0xFFu)), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000324E8;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->edx;
    label_000324E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4324E8u);
    if ((uint8_t)((lift_load8(cpu->edx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_000324F1;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) | (uint64_t)(2u))) & 0xFFu);
    goto label_000324F4;
    label_000324F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4324F1u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFDu))) & 0xFFu);
    label_000324F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4324F4u);
    lift_store8(cpu->esp + 0x10u, cpu->ecx & 0xFFu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ebp += 3u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_00032508;
    cpu->ebp += 3u;
    goto label_0003252E;
    label_00032508: cpu->eip = LIFT_CODE_TOKEN_VA(0x432508u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00032512;
    cpu->ebp += 7u;
    goto label_0003252E;
    label_00032512: cpu->eip = LIFT_CODE_TOKEN_VA(0x432512u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(2u)) goto label_0003251C;
    cpu->ebp += 0xEu;
    goto label_0003252E;
    label_0003251C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43251Cu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(3u)) goto label_0003252E;
    cpu->ebp += 0x1Fu;
    goto label_0003252E;
    label_00032526: cpu->eip = LIFT_CODE_TOKEN_VA(0x432526u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x6Cu)) goto label_0003252E;
    cpu->ebp += 8u;
    label_0003252E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43252Eu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_00032539;
    ++cpu->edi;
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    goto label_0003253A;
    label_00032539: cpu->eip = LIFT_CODE_TOKEN_VA(0x432539u);
    --cpu->esi;
    label_0003253A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43253Au);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->edx + 0x1Cu))) goto label_00032340;
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    label_0003254D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43254Du);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + 0x94u)), r=(uint64_t)(4u), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000321D0;
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    if ((uint8_t)((lift_load8(cpu->eax + 0x20u)) & (1u)) != 0u) goto label_0003258A;
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u) + 0xDCu);
    if ((int32_t)(uint32_t)(cpu->ecx) < 0) goto label_0003258E;
    cpu->edx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x432582u); lift_push32(cpu, r); sfera_sub_00431850(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_000321D0;
    label_0003258A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43258Au);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    label_0003258E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43258Eu);
    lift_push32(cpu, 0x752u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\INet.cpp";
    cpu->ecx = 0x18u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4325A2u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->esi + 8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->esi + 0xCu, cpu->edx);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 0x14u, cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u) + 0x1D8u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000325DF;
    lift_store32(cpu->eax + ((uint32_t)(cpu->edi) * 4u) + 0x1D8u, cpu->esi);
    goto label_00032616;
    label_000325DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4325DFu);
    cpu->ebx = 0u;
    label_000325E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4325E1u);
    cpu->edi = lift_load32(cpu->esp + 0x24u);
    cpu->edi -= lift_load32(cpu->ecx + 8u);
    cpu->eax = cpu->edi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x3840u)) goto label_00032608;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00032602;
    cpu->edi += 0x8000u;
    goto label_00032608;
    label_00032602: cpu->eip = LIFT_CODE_TOKEN_VA(0x432602u);
    cpu->edi -= 0x8000u;
    label_00032608: cpu->eip = LIFT_CODE_TOKEN_VA(0x432608u);
    if ((int32_t)(uint32_t)(cpu->edi) < 0) goto label_00032664;
    cpu->ebx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000325E1;
    label_00032614: cpu->eip = LIFT_CODE_TOKEN_VA(0x432614u);
    lift_store32(cpu->ebx, cpu->esi);
    label_00032616: cpu->eip = LIFT_CODE_TOKEN_VA(0x432616u);
    cpu->ebx = cpu->ebp;
    cpu->ebx -= lift_load32(cpu->esp + 0x44u);
    lift_push32(cpu, 0x77Au);
    cpu->eax = (uint32_t)(cpu->ebx + 8u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(7u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->edi = (uint32_t)(cpu->edx + cpu->eax);
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(3u), 32u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\INet.cpp";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43263Au); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x432641u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x432646u);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43265Fu); lift_push32(cpu, r); sfera_sub_004013D0(cpu,r); if (cpu->eip != r) return; }
    goto label_000321D0;
    label_00032664: cpu->eip = LIFT_CODE_TOKEN_VA(0x432664u);
    lift_store32(cpu->esi, cpu->ecx);
    if ((uint32_t)(cpu->ebx) != 0u) goto label_00032614;
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->eax) * 4u) + 0x1D8u, cpu->esi);
    goto label_00032616;
    label_0003267D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43267Du);
    if ((uint8_t)((lift_load8(cpu->ecx + 0x94u)) & (4u)) == 0u) goto label_00032783;
    cpu->edi = lift_load32(cpu->esp + 0x28u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_000326AF;
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x6E7u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\INet.cpp"); lift_push32(cpu, (uintptr_t)"Unloading _main: %s:%d, %d, %d\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4326ACu); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000326AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4326AFu);
    cpu->ebp = lift_pop32(cpu);
    cpu->ecx = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    sfera_sub_00435D40(cpu, stop_address); return;
    label_000326BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4326BDu);
    cpu->ecx = lift_load32(cpu->edi + 8u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x398u);
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_world_slot_table_runtime.slots[0].linked_handle));
    if ((uint32_t)(cpu->ecx) > (uint32_t)(0xFFFFu)) goto label_00032784;
    cpu->eax = cpu->ecx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id))) != (uint32_t)(cpu->ecx)) goto label_00032784;
    cpu->ebx = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))) < (int32_t)(uint32_t)(cpu->ebx)) goto label_00032784;
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0]));
    g_sfera_mbc_runtime->active_process = (uint32_t)(cpu->edx);
    lift_push32(cpu, 0x623u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\INet.cpp";
    cpu->ecx = (uint32_t)(cpu->ebx + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x432718u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->esi, cpu->ebx);
    cpu->eax = lift_load32(cpu->edi + 0x19Cu);
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, cpu->ebx);
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    cpu->eax = lift_load32(cpu->ecx + 0x2D0u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_00032746;
    lift_store32(cpu->ecx + 0x2D0u, cpu->esi);
    goto label_00032750;
    label_00032746: cpu->eip = LIFT_CODE_TOKEN_VA(0x432746u);
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_00032746;
    lift_store32(cpu->ecx, cpu->esi);
    label_00032750: cpu->eip = LIFT_CODE_TOKEN_VA(0x432750u);
    cpu->ecx = lift_load32(cpu->edi + 0x19Cu);
    lift_push32(cpu, 0x63Du);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\INet.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x432765u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x19Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edi += 0xCu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x432774u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x432779u);
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    lift_return(cpu, 0u, stop_address); return;
    label_00032783: cpu->eip = LIFT_CODE_TOKEN_VA(0x432783u);
    cpu->ebp = lift_pop32(cpu);
    label_00032784: cpu->eip = LIFT_CODE_TOKEN_VA(0x432784u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00432790(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x432790u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = 1u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    if ((uint32_t)(g_sfera_network_runtime.initialization_result) != (uint32_t)(cpu->eax)) goto label_00032865;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_directplay_runtime.transport.received_packet_count, (uint64_t)(g_sfera_directplay_runtime.transport.received_packet_count) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    cpu->edi = lift_load32(cpu->ebp + 0xCu);
    { uint64_t l=(uint64_t)(g_sfera_directplay_runtime.transport.received_bytes.low), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); lift_store32((uint32_t)(uintptr_t)&g_sfera_directplay_runtime.transport.received_bytes.low, v); }
    lift_store32((uint32_t)(uintptr_t)&g_sfera_directplay_runtime.transport.received_bytes.high, (uint64_t)(g_sfera_directplay_runtime.transport.received_bytes.high) + (uint64_t)(0u) + (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)));
    if ((uint32_t)(cpu->ebx) != (uint32_t)(8u)) goto label_000327DF;
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 0x2BF20u);
    cpu->ebx = 0x88u;
    goto label_000327EC;
    label_000327DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4327DFu);
    cpu->ebx |= 0x90u;
    lift_store32(cpu->ebp + 0xFFFFFFF8u, 0xEA60u);
    label_000327EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4327ECu);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4327F6u); lift_push32(cpu, r); sfera_sub_0048A1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->edi + 1u);
    lift_store32(cpu->ebp + 0xFFFFFFF4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x432801u); lift_push32(cpu, r); sfera_sub_004EEA10(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->esi = cpu->esp;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 1u);
    lift_push32(cpu, cpu->ecx);
    lift_store8(cpu->esi, 0u);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43280Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x432814u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    cpu->esp += 0xCu;
    { uint64_t l=(uint64_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    g_sfera_directplay_runtime.send_buffer.buffer_size = (uint32_t)(cpu->eax);
    lift_store32((uintptr_t)&g_sfera_directplay_runtime.send_buffer.buffer_data, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032842;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_24;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x12Cu); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x432840u); lift_push32(cpu, r); sfera_sub_00418BB0(cpu,r); if (cpu->eip != r) return; }
    goto label_00032865;
    label_00032842: cpu->eip = LIFT_CODE_TOKEN_VA(0x432842u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    cpu->eax = g_sfera_directplay_runtime.peer;
    cpu->edx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edx + 0x20u);
    cpu->ebx |= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&g_sfera_directplay_runtime.send_async_handle); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u); lift_push32(cpu, (uintptr_t)&g_sfera_directplay_runtime.send_buffer); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x32865u), LIFT_CODE_TOKEN_RVA(0x32863u))) { return; }
    label_00032865: cpu->eip = LIFT_CODE_TOKEN_VA(0x432865u);
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00432880(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x432880u);
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
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x328DDu); lift_push32(cpu, r); sfera_sub_0047FED0(cpu,r); if (cpu->eip != r) return; }
    label_000328DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4328DDu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4328E2u); lift_push32(cpu, r); sfera_sub_0047FF70(cpu,r); if (cpu->eip != r) return; }
    lift_store32((uint32_t)(uintptr_t)&g_sfera_network_runtime.error_budget, (uint64_t)(g_sfera_network_runtime.error_budget) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    goto label_000328F1;
    label_000328EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4328EAu);
    g_sfera_network_runtime.network_error_active = (uint8_t)(0u);
    label_000328F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4328F1u);
    if ((uint8_t)(g_sfera_network_runtime.timeout_marker_pending) != (uint8_t)(1u)) goto label_0003290D;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    cpu->ecx = (uint32_t)(uintptr_t)"-- T\n";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x432906u); lift_push32(cpu, r); sfera_sub_0047FED0(cpu,r); if (cpu->eip != r) return; }
    g_sfera_network_runtime.timeout_marker_pending = (uint8_t)(0u);
    label_0003290D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43290Du);
    cpu->eax = g_sfera_directplay_runtime.peer;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00032943;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 4u, 0x5Cu);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x50u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x3292Du), LIFT_CODE_TOKEN_RVA(0x3292Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43292Du);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00032943;
    cpu->ecx = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x32943u); lift_push32(cpu, r); sfera_sub_0047FEB0(cpu,r); if (cpu->eip != r) return; }
    label_00032943: cpu->eip = LIFT_CODE_TOKEN_VA(0x432943u);
    cpu->esp += 0x60u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00432970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x432970u);
    cpu->esp -= 0x38u;
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(0xFFFF0011u)) goto label_000333FC;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = (uint32_t)(cpu->ecx + 0xDu);
    cpu->ecx = lift_load32(cpu->ecx + 0x19Cu);
    lift_store8(cpu->ecx + cpu->ebp + 0xFFFFFFFFu, cpu->eax & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp)) & 0xFFu);
    cpu->ecx = 1u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) & (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    lift_push32(cpu, cpu->esi);
    lift_store8(cpu->esp + 0x3Cu, cpu->edx & 0xFFu);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x40u)), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032B14;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(2u) & 0xFFu);
    cpu->esi = cpu->ebp;
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    cpu->edi = (uint32_t)(cpu->ecx + 3u);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000329D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4329D0u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_000329D8;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_000329DE;
    label_000329D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4329D8u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_000329DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4329DEu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000329E5;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_000329E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4329E5u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000329EC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_000329EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4329ECu);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_000329F4;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_000329FA;
    label_000329F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4329F4u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_000329FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4329FAu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032A01;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032A01: cpu->eip = LIFT_CODE_TOKEN_VA(0x432A01u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032A08;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032A08: cpu->eip = LIFT_CODE_TOKEN_VA(0x432A08u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032A10;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00032A16;
    label_00032A10: cpu->eip = LIFT_CODE_TOKEN_VA(0x432A10u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00032A16: cpu->eip = LIFT_CODE_TOKEN_VA(0x432A16u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032A1D;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032A1D: cpu->eip = LIFT_CODE_TOKEN_VA(0x432A1Du);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032A24;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032A24: cpu->eip = LIFT_CODE_TOKEN_VA(0x432A24u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032A2C;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00032A32;
    label_00032A2C: cpu->eip = LIFT_CODE_TOKEN_VA(0x432A2Cu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00032A32: cpu->eip = LIFT_CODE_TOKEN_VA(0x432A32u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032A39;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032A39: cpu->eip = LIFT_CODE_TOKEN_VA(0x432A39u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032A40;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032A40: cpu->eip = LIFT_CODE_TOKEN_VA(0x432A40u);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000329D0;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(2u) & 0xFFu);
    cpu->esi = (uint32_t)(cpu->ebp + 2u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    cpu->edi = 0xDu;
    label_00032A53: cpu->eip = LIFT_CODE_TOKEN_VA(0x432A53u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032A5B;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00032A61;
    label_00032A5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x432A5Bu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00032A61: cpu->eip = LIFT_CODE_TOKEN_VA(0x432A61u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032A68;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032A68: cpu->eip = LIFT_CODE_TOKEN_VA(0x432A68u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032A6F;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032A6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x432A6Fu);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032A53;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(0x40u) & 0xFFu);
    cpu->esi = (uint32_t)(cpu->ebp + 3u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    cpu->edi = 4u;
    label_00032A82: cpu->eip = LIFT_CODE_TOKEN_VA(0x432A82u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032A8A;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00032A90;
    label_00032A8A: cpu->eip = LIFT_CODE_TOKEN_VA(0x432A8Au);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00032A90: cpu->eip = LIFT_CODE_TOKEN_VA(0x432A90u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032A97;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032A97: cpu->eip = LIFT_CODE_TOKEN_VA(0x432A97u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032A9E;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032A9E: cpu->eip = LIFT_CODE_TOKEN_VA(0x432A9Eu);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032AA6;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00032AAC;
    label_00032AA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x432AA6u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00032AAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x432AACu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032AB3;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032AB3: cpu->eip = LIFT_CODE_TOKEN_VA(0x432AB3u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032ABA;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032ABA: cpu->eip = LIFT_CODE_TOKEN_VA(0x432ABAu);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032AC2;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00032AC8;
    label_00032AC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x432AC2u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00032AC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x432AC8u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032ACF;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032ACF: cpu->eip = LIFT_CODE_TOKEN_VA(0x432ACFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032AD6;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032AD6: cpu->eip = LIFT_CODE_TOKEN_VA(0x432AD6u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032ADE;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00032AE4;
    label_00032ADE: cpu->eip = LIFT_CODE_TOKEN_VA(0x432ADEu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00032AE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x432AE4u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032AEB;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032AEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x432AEBu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032AF2;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032AF2: cpu->eip = LIFT_CODE_TOKEN_VA(0x432AF2u);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032A82;
    lift_store32(cpu->esp + 0x38u, (uint64_t)(lift_load32(cpu->esp + 0x38u)) - (uint64_t)(0x4B0u) - (uint64_t)(0u));
    cpu->eax = 0x8000u;
    lift_store32(cpu->esp + 0x34u, (uint64_t)(lift_load32(cpu->esp + 0x34u)) - (uint64_t)(cpu->eax) - (uint64_t)(0u));
    lift_store32(cpu->esp + 0x3Cu, (uint64_t)(lift_load32(cpu->esp + 0x3Cu)) - (uint64_t)(cpu->eax) - (uint64_t)(0u));
    lift_store32(cpu->esp + 0x10u, 0x2Eu);
    lift_flags_logic(cpu,0u,32u); cpu->eax = 0u;
    label_00032B14: cpu->eip = LIFT_CODE_TOKEN_VA(0x432B14u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->edx & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ebp);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    cpu->edi = 3u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00032B40: cpu->eip = LIFT_CODE_TOKEN_VA(0x432B40u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032B48;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00032B4E;
    label_00032B48: cpu->eip = LIFT_CODE_TOKEN_VA(0x432B48u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00032B4E: cpu->eip = LIFT_CODE_TOKEN_VA(0x432B4Eu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032B55;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032B55: cpu->eip = LIFT_CODE_TOKEN_VA(0x432B55u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032B5C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032B5C: cpu->eip = LIFT_CODE_TOKEN_VA(0x432B5Cu);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032B64;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00032B6A;
    label_00032B64: cpu->eip = LIFT_CODE_TOKEN_VA(0x432B64u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00032B6A: cpu->eip = LIFT_CODE_TOKEN_VA(0x432B6Au);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032B71;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032B71: cpu->eip = LIFT_CODE_TOKEN_VA(0x432B71u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032B78;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032B78: cpu->eip = LIFT_CODE_TOKEN_VA(0x432B78u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032B80;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00032B86;
    label_00032B80: cpu->eip = LIFT_CODE_TOKEN_VA(0x432B80u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00032B86: cpu->eip = LIFT_CODE_TOKEN_VA(0x432B86u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032B8D;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032B8D: cpu->eip = LIFT_CODE_TOKEN_VA(0x432B8Du);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032B94;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032B94: cpu->eip = LIFT_CODE_TOKEN_VA(0x432B94u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032B9C;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00032BA2;
    label_00032B9C: cpu->eip = LIFT_CODE_TOKEN_VA(0x432B9Cu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00032BA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x432BA2u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032BA9;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032BA9: cpu->eip = LIFT_CODE_TOKEN_VA(0x432BA9u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032BB0;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032BB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x432BB0u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032BB8;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00032BBE;
    label_00032BB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x432BB8u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00032BBE: cpu->eip = LIFT_CODE_TOKEN_VA(0x432BBEu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032BC5;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032BC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x432BC5u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032BCC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032BCC: cpu->eip = LIFT_CODE_TOKEN_VA(0x432BCCu);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032B40;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(0xFu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    label_00032BE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x432BE0u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->edx & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ebp);
    lift_store32(cpu->esp + 0x20u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    cpu->edi = 3u;
    label_00032C10: cpu->eip = LIFT_CODE_TOKEN_VA(0x432C10u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032C18;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00032C1E;
    label_00032C18: cpu->eip = LIFT_CODE_TOKEN_VA(0x432C18u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00032C1E: cpu->eip = LIFT_CODE_TOKEN_VA(0x432C1Eu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032C25;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032C25: cpu->eip = LIFT_CODE_TOKEN_VA(0x432C25u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032C2C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032C2C: cpu->eip = LIFT_CODE_TOKEN_VA(0x432C2Cu);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032C34;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00032C3A;
    label_00032C34: cpu->eip = LIFT_CODE_TOKEN_VA(0x432C34u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00032C3A: cpu->eip = LIFT_CODE_TOKEN_VA(0x432C3Au);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032C41;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032C41: cpu->eip = LIFT_CODE_TOKEN_VA(0x432C41u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032C48;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032C48: cpu->eip = LIFT_CODE_TOKEN_VA(0x432C48u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032C50;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00032C56;
    label_00032C50: cpu->eip = LIFT_CODE_TOKEN_VA(0x432C50u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00032C56: cpu->eip = LIFT_CODE_TOKEN_VA(0x432C56u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032C5D;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032C5D: cpu->eip = LIFT_CODE_TOKEN_VA(0x432C5Du);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032C64;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032C64: cpu->eip = LIFT_CODE_TOKEN_VA(0x432C64u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032C6C;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00032C72;
    label_00032C6C: cpu->eip = LIFT_CODE_TOKEN_VA(0x432C6Cu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00032C72: cpu->eip = LIFT_CODE_TOKEN_VA(0x432C72u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032C79;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032C79: cpu->eip = LIFT_CODE_TOKEN_VA(0x432C79u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032C80;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032C80: cpu->eip = LIFT_CODE_TOKEN_VA(0x432C80u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032C88;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00032C8E;
    label_00032C88: cpu->eip = LIFT_CODE_TOKEN_VA(0x432C88u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00032C8E: cpu->eip = LIFT_CODE_TOKEN_VA(0x432C8Eu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032C95;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032C95: cpu->eip = LIFT_CODE_TOKEN_VA(0x432C95u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032C9C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032C9C: cpu->eip = LIFT_CODE_TOKEN_VA(0x432C9Cu);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032CA4;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00032CAA;
    label_00032CA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x432CA4u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00032CAA: cpu->eip = LIFT_CODE_TOKEN_VA(0x432CAAu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032CB1;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032CB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x432CB1u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032CB8;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032CB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x432CB8u);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032C10;
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(0x12u) + (uint64_t)(0u));
    lift_push32(cpu, 4u); lift_push32(cpu, 0xCu);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->esp + 0x54u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 0x2Cu, cpu->esi);
    lift_store32(cpu->esp + 0x54u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x432CE5u); lift_push32(cpu, r); sfera_sub_004013D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) != (uint32_t)(cpu->esi)) goto label_00032E0F;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0xFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00032DA0;
    cpu->eax = cpu->edi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id))), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032DA0;
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))), r=(uint64_t)(cpu->esi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00032DA0;
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0]));
    cpu->edx = (uint32_t)(uintptr_t)"EKill";
    g_sfera_mbc_runtime->active_process = (uint32_t)(cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x432D35u); lift_push32(cpu, r); sfera_sub_00435020(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00032D63;
    cpu->eax = g_sfera_mbc_runtime->active_process;
    lift_store32(cpu->eax + 0x94u, (uint64_t)(lift_load32(cpu->eax + 0x94u)) | (uint64_t)(4u));
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    lift_store8(cpu->ecx + 0xB8u, 1u);
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->ecx = lift_load32(cpu->edx + 0xB4u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x32D63u); lift_push32(cpu, r); sfera_sub_00433CF0(cpu,r); if (cpu->eip != r) return; }
    label_00032D63: cpu->eip = LIFT_CODE_TOKEN_VA(0x432D63u);
    cpu->eax = g_sfera_mbc_runtime->active_process;
    lift_store32(cpu->eax + 0x94u, (uint64_t)(lift_load32(cpu->eax + 0x94u)) | (uint64_t)(0x20u));
    cpu->edx = g_sfera_mbc_runtime->active_process;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edx + 0xB4u)), r=(uint64_t)(cpu->esi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032DA0;
    cpu->eax = lift_load32(cpu->esp + 0x40u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x126u); lift_push32(cpu, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\inet_tcp.h"); lift_push32(cpu, (uintptr_t)"Unloading _main: %s:%d, %d, %d, %d, %d\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x432D9Du); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=cpu->esp, r=(uint64_t)(0x1Cu), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    label_00032DA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x432DA0u);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->eax = cpu->ebp;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->edx & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ecx);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    cpu->edi = 7u;
    cpu->edi = cpu->edi;
    label_00032DD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x432DD0u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032DD8;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00032DDE;
    label_00032DD8: cpu->eip = LIFT_CODE_TOKEN_VA(0x432DD8u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00032DDE: cpu->eip = LIFT_CODE_TOKEN_VA(0x432DDEu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032DE5;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00032DE5: cpu->eip = LIFT_CODE_TOKEN_VA(0x432DE5u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032DEC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032DEC: cpu->eip = LIFT_CODE_TOKEN_VA(0x432DECu);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032DD0;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ebp += 7u;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x3Fu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00032BE0;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000333F8;
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    label_00032E0F: cpu->eip = LIFT_CODE_TOKEN_VA(0x432E0Fu);
    if ((uint32_t)(cpu->edi) > (uint32_t)(0xFFFFu)) goto label_00032E4F;
    cpu->eax = cpu->edi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id))) != (uint32_t)(cpu->edi)) goto label_00032E3F;
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))) < (int32_t)(uint32_t)(0u)) goto label_00032E3F;
    cpu->esi = cpu->edi;
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    if ((uint32_t)(cpu->edi) != (uint32_t)(0xFFFFFFFFu)) goto label_00032ED1;
    label_00032E3F: cpu->eip = LIFT_CODE_TOKEN_VA(0x432E3Fu);
    if ((uint32_t)(cpu->edi) > (uint32_t)(0xFFFFu)) goto label_00032E4F;
    cpu->esi = cpu->edi;
    lift_store32(cpu->esp + 0x28u, cpu->edi);
    goto label_00032E56;
    label_00032E4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x432E4Fu);
    cpu->esi |= 0xFFFFFFFFu;
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    label_00032E56: cpu->eip = LIFT_CODE_TOKEN_VA(0x432E56u);
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id))) == (uint32_t)(cpu->edi)) goto label_00032EAE;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x8D8u);
    cpu->ecx += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0]);
    cpu->edx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x432E7Du); lift_push32(cpu, r); sfera_sub_00435230(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    if ((uint32_t)(cpu->esi) > (uint32_t)(0xFFFFu)) goto label_000333F8;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id))) != (uint32_t)(cpu->esi)) goto label_000333F8;
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))) < (int32_t)(uint32_t)(0u)) goto label_000333F8;
    label_00032EAE: cpu->eip = LIFT_CODE_TOKEN_VA(0x432EAEu);
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_000333F8;
    lift_store32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].flags), (uint64_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].flags))) | (uint64_t)(4u));
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0]));
    cpu->ecx = cpu->esi;
    lift_store8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].state_byte_b8), 1u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x32ED1u); lift_push32(cpu, r); sfera_sub_00433CF0(cpu,r); if (cpu->eip != r) return; }
    label_00032ED1: cpu->eip = LIFT_CODE_TOKEN_VA(0x432ED1u);
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_000333F8;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0])), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->esi = v; }
    g_sfera_mbc_runtime->active_process = (uint32_t)(cpu->esi);
    label_00032EF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x432EF0u);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->eax = cpu->ebp;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->edx & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ecx);
    lift_store32(cpu->esp + 0x14u, 0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    cpu->edi = 7u;
    label_00032F22: cpu->eip = LIFT_CODE_TOKEN_VA(0x432F22u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00032F2A;
    lift_store8(cpu->ecx, (uint64_t)(lift_load8(cpu->ecx)) | (uint64_t)((cpu->eax & 0xFFu)));
    goto label_00032F30;
    label_00032F2A: cpu->eip = LIFT_CODE_TOKEN_VA(0x432F2Au);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->ecx, (uint64_t)(lift_load8(cpu->ecx)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00032F30: cpu->eip = LIFT_CODE_TOKEN_VA(0x432F30u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032F37;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->ecx;
    label_00032F37: cpu->eip = LIFT_CODE_TOKEN_VA(0x432F37u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032F3E;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00032F3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x432F3Eu);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032F22;
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    cpu->eax = lift_load32(cpu->ecx + 0xD0u);
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 8u));
    cpu->ebp += 7u;
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    lift_store32(cpu->esp + 0x2Cu, cpu->edx);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0x3Fu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00032BE0;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000333F8;
    --cpu->esi;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0x3Du), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000333BC;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00032F8B;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00033011;
    label_00032F8B: cpu->eip = LIFT_CODE_TOKEN_VA(0x432F8Bu);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x6Cu)) == (uint32_t)(0xFFFFFFFFu)) goto label_00032FC0;
    if ((uint8_t)((lift_load8(cpu->ecx + 0x94u)) & (0x20u)) == 0u) goto label_00032FE7;
    cpu->edi = lift_load32(cpu->esp + 0x28u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_00032FB9;
    lift_push32(cpu, 0x195u); lift_push32(cpu, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\inet_tcp.h"); lift_push32(cpu, (uintptr_t)"Unloading _main: %s:%d\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x432FB6u); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_00032FB9: cpu->eip = LIFT_CODE_TOKEN_VA(0x432FB9u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x32FC0u); lift_push32(cpu, r); sfera_sub_00435D40(cpu,r); if (cpu->eip != r) return; }
    label_00032FC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x432FC0u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x8D8u);
    cpu->ecx += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x432FD9u); lift_push32(cpu, r); sfera_sub_00435230(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000333BC;
    label_00032FE7: cpu->eip = LIFT_CODE_TOKEN_VA(0x432FE7u);
    lift_store32(cpu->ecx + 0x94u, (uint64_t)(lift_load32(cpu->ecx + 0x94u)) & (uint64_t)(0xFFFFFFFBu));
    cpu->eax = g_sfera_mbc_runtime->active_process;
    lift_store8(cpu->eax + 0xB8u, 1u);
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->ecx = lift_load32(cpu->edx + 0xB4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43300Bu); lift_push32(cpu, r); sfera_sub_00433CF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    label_00033011: cpu->eip = LIFT_CODE_TOKEN_VA(0x433011u);
    cpu->eax = lift_load32(cpu->ecx + 0xD0u);
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 8u));
    cpu->edi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    cpu->edx = lift_load16(cpu->edi + 0x22u);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    if ((uint32_t)(cpu->edx) == (uint32_t)(0xFFFFu)) goto label_00033038;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433032u); lift_push32(cpu, r); sfera_sub_004350C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    label_00033038: cpu->eip = LIFT_CODE_TOKEN_VA(0x433038u);
    cpu->eax = lift_load32(cpu->edi + 0x1Cu);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000333BC;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = 0u;
    cpu->edi = 0u;
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x44u, cpu->edx);
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0003326D;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00033060: cpu->eip = LIFT_CODE_TOKEN_VA(0x433060u);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->eax = (int8_t)(lift_load8(cpu->edi + cpu->eax));
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(0x20u)) goto label_00033079;
    cpu->ebp += cpu->eax;
    goto label_0003324E;
    label_00033079: cpu->eip = LIFT_CODE_TOKEN_VA(0x433079u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x65u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00033106;
    cpu->edx = cpu->ebp;
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx) * 8u));
    cpu->ecx = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->eax & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->ecx += cpu->edx;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx)), r=(uint64_t)((cpu->eax & 0xFFu)), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000330AC;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->ecx;
    label_000330AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4330ACu);
    if ((uint8_t)((lift_load8(cpu->ecx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_000330B5;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) | (uint64_t)(2u))) & 0xFFu);
    goto label_000330B8;
    label_000330B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4330B5u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) & (uint64_t)(0xFDu))) & 0xFFu);
    label_000330B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4330B8u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000330BF;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->ecx;
    label_000330BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4330BFu);
    if ((uint8_t)((lift_load8(cpu->ecx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_000330C8;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) | (uint64_t)(4u))) & 0xFFu);
    goto label_000330CB;
    label_000330C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4330C8u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) & (uint64_t)(0xFBu))) & 0xFFu);
    label_000330CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4330CBu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000330D2;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->ecx;
    label_000330D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4330D2u);
    if ((uint8_t)((lift_load8(cpu->ecx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_000330EE;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) | (uint64_t)(8u))) & 0xFFu);
    cpu->ebp += 4u;
    ++cpu->edi;
    lift_store8(cpu->esp + 0x10u, cpu->edx & 0xFFu);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    goto label_0003324E;
    label_000330EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4330EEu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) & (uint64_t)(0xF7u))) & 0xFFu);
    cpu->ebp += 4u;
    ++cpu->edi;
    lift_store8(cpu->esp + 0x10u, cpu->edx & 0xFFu);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    goto label_0003324E;
    label_00033106: cpu->eip = LIFT_CODE_TOKEN_VA(0x433106u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x66u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000331CA;
    cpu->eax = cpu->ebp;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ecx = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->edx & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ecx);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    cpu->edi = 2u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00033140: cpu->eip = LIFT_CODE_TOKEN_VA(0x433140u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00033148;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_0003314E;
    label_00033148: cpu->eip = LIFT_CODE_TOKEN_VA(0x433148u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_0003314E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43314Eu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00033155;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00033155: cpu->eip = LIFT_CODE_TOKEN_VA(0x433155u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003315C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_0003315C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43315Cu);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00033164;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_0003316A;
    label_00033164: cpu->eip = LIFT_CODE_TOKEN_VA(0x433164u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_0003316A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43316Au);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00033171;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00033171: cpu->eip = LIFT_CODE_TOKEN_VA(0x433171u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00033178;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00033178: cpu->eip = LIFT_CODE_TOKEN_VA(0x433178u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00033180;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00033186;
    label_00033180: cpu->eip = LIFT_CODE_TOKEN_VA(0x433180u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00033186: cpu->eip = LIFT_CODE_TOKEN_VA(0x433186u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003318D;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_0003318D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43318Du);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00033194;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00033194: cpu->eip = LIFT_CODE_TOKEN_VA(0x433194u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_0003319C;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_000331A2;
    label_0003319C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43319Cu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_000331A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4331A2u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000331A9;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_000331A9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4331A9u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000331B0;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_000331B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4331B0u);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00033140;
    cpu->edi = lift_load32(cpu->esp + 0x30u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    ++cpu->edi;
    cpu->ebp += 8u;
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    cpu->ebx = 0u;
    goto label_0003324E;
    label_000331CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4331CAu);
    cpu->edx = (uint32_t)(cpu->eax + 0xFFFFFF97u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(2u)) goto label_000331D7;
    cpu->ebp += 0xCu;
    goto label_0003324E;
    label_000331D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4331D7u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x67u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00033246;
    cpu->edx = (uint32_t)(cpu->ebp + 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx) * 8u));
    cpu->ecx = (uint32_t)(cpu->ebp + 1u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->eax & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx += cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    { uint64_t l=(uint64_t)(lift_load8(cpu->edx)), r=(uint64_t)((cpu->eax & 0xFFu)), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00033208;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->edx;
    label_00033208: cpu->eip = LIFT_CODE_TOKEN_VA(0x433208u);
    if ((uint8_t)((lift_load8(cpu->edx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_00033211;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) | (uint64_t)(2u))) & 0xFFu);
    goto label_00033214;
    label_00033211: cpu->eip = LIFT_CODE_TOKEN_VA(0x433211u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFDu))) & 0xFFu);
    label_00033214: cpu->eip = LIFT_CODE_TOKEN_VA(0x433214u);
    lift_store8(cpu->esp + 0x10u, cpu->ecx & 0xFFu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ebp += 3u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_00033228;
    cpu->ebp += 3u;
    goto label_0003324E;
    label_00033228: cpu->eip = LIFT_CODE_TOKEN_VA(0x433228u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00033232;
    cpu->ebp += 7u;
    goto label_0003324E;
    label_00033232: cpu->eip = LIFT_CODE_TOKEN_VA(0x433232u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(2u)) goto label_0003323C;
    cpu->ebp += 0xEu;
    goto label_0003324E;
    label_0003323C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43323Cu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(3u)) goto label_0003324E;
    cpu->ebp += 0x1Fu;
    goto label_0003324E;
    label_00033246: cpu->eip = LIFT_CODE_TOKEN_VA(0x433246u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x6Cu)) goto label_0003324E;
    cpu->ebp += 8u;
    label_0003324E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43324Eu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_00033259;
    ++cpu->edi;
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    goto label_0003325A;
    label_00033259: cpu->eip = LIFT_CODE_TOKEN_VA(0x433259u);
    --cpu->esi;
    label_0003325A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43325Au);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->edx + 0x1Cu))) goto label_00033060;
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    label_0003326D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43326Du);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + 0x94u)), r=(uint64_t)(4u), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00032EF0;
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    if ((uint8_t)((lift_load8(cpu->eax + 0x20u)) & (1u)) != 0u) goto label_000332C5;
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u) + 0xDCu);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000332C9;
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->ecx -= cpu->eax;
    cpu->eax = cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x3840u)) goto label_000332BD;
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000332B7;
    cpu->ecx += 0x8000u;
    goto label_000332BD;
    label_000332B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4332B7u);
    cpu->ecx -= 0x8000u;
    label_000332BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4332BDu);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_00032EF0;
    label_000332C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4332C5u);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    label_000332C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4332C9u);
    lift_push32(cpu, 0x1E8u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\inet_tcp.h";
    cpu->ecx = 0x18u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4332DDu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->esi + 8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->esi + 0xCu, cpu->edx);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 0x14u, cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u) + 0x1D8u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_0003331A;
    lift_store32(cpu->eax + ((uint32_t)(cpu->edi) * 4u) + 0x1D8u, cpu->esi);
    goto label_00033355;
    label_0003331A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43331Au);
    cpu->ebx = 0u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00033320: cpu->eip = LIFT_CODE_TOKEN_VA(0x433320u);
    cpu->edi = lift_load32(cpu->esp + 0x24u);
    cpu->edi -= lift_load32(cpu->ecx + 8u);
    cpu->eax = cpu->edi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax ^= cpu->edx;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x3840u)) goto label_00033347;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00033341;
    cpu->edi += 0x8000u;
    goto label_00033347;
    label_00033341: cpu->eip = LIFT_CODE_TOKEN_VA(0x433341u);
    cpu->edi -= 0x8000u;
    label_00033347: cpu->eip = LIFT_CODE_TOKEN_VA(0x433347u);
    if ((int32_t)(uint32_t)(cpu->edi) < 0) goto label_000333A3;
    cpu->ebx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_00033320;
    label_00033353: cpu->eip = LIFT_CODE_TOKEN_VA(0x433353u);
    lift_store32(cpu->ebx, cpu->esi);
    label_00033355: cpu->eip = LIFT_CODE_TOKEN_VA(0x433355u);
    cpu->ebx = cpu->ebp;
    cpu->ebx -= lift_load32(cpu->esp + 0x44u);
    lift_push32(cpu, 0x210u);
    cpu->eax = (uint32_t)(cpu->ebx + 8u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(7u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->edi = (uint32_t)(cpu->edx + cpu->eax);
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(3u), 32u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\inet_tcp.h";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433379u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x433380u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x433385u);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43339Eu); lift_push32(cpu, r); sfera_sub_004013D0(cpu,r); if (cpu->eip != r) return; }
    goto label_00032EF0;
    label_000333A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4333A3u);
    lift_store32(cpu->esi, cpu->ecx);
    if ((uint32_t)(cpu->ebx) != 0u) goto label_00033353;
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->eax) * 4u) + 0x1D8u, cpu->esi);
    goto label_00033355;
    label_000333BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4333BCu);
    if ((uint8_t)((lift_load8(cpu->ecx + 0x94u)) & (4u)) == 0u) goto label_000333F8;
    cpu->edi = lift_load32(cpu->esp + 0x28u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_000333EA;
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x17Du); lift_push32(cpu, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\inet_tcp.h"); lift_push32(cpu, (uintptr_t)"Unloading _main: %s:%d, %d, %d\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4333E7u); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x14u;
    label_000333EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4333EAu);
    cpu->ecx = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x38u;
    sfera_sub_00435D40(cpu, stop_address); return;
    label_000333F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4333F8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000333FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4333FCu);
    cpu->esp += 0x38u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433400u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(0xFFFF0011u)) goto label_0003345E;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43340Du); lift_push32(cpu, r); sfera_sub_00431AE0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_directplay_runtime.transport.sent_packet_count, (uint64_t)(g_sfera_directplay_runtime.transport.sent_packet_count) + 1u);
    lift_store32(cpu->eax, 0xFFFF0011u);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store32(cpu->eax + 8u, 0xFFFFFFFFu);
    cpu->ecx = lift_load32(cpu->edx + 0x10u);
    { uint64_t l=(uint64_t)(g_sfera_directplay_runtime.transport.sent_bytes.low), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); lift_store32((uint32_t)(uintptr_t)&g_sfera_directplay_runtime.transport.sent_bytes.low, v); }
    lift_store32((uint32_t)(uintptr_t)&g_sfera_directplay_runtime.transport.sent_bytes.high, (uint64_t)(g_sfera_directplay_runtime.transport.sent_bytes.high) + (uint64_t)(0u) + (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)));
    if ((uint32_t)(cpu->ecx) < (uint32_t)(0x190u)) goto label_00033447;
    cpu->ecx = 0x18Fu;
    label_00033447: cpu->eip = LIFT_CODE_TOKEN_VA(0x433447u);
    lift_store32(cpu->eax + 0x19Cu, cpu->ecx);
    cpu->edx = lift_load32(cpu->edx + 0xCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->eax += 0xCu;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x433456u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43345Bu);
    cpu->esp += 0xCu;
    label_0003345E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43345Eu);
    cpu->eax = 0u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433470u);
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
    label_000334CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4334CAu);
    cpu->eax = 3u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    g_sfera_directplay_runtime.transport.mode = (uint32_t)(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x20Cu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000334E8;
    g_sfera_network_runtime.server_port = (uint32_t)(cpu->eax);
    label_000334E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4334E8u);
    cpu->eax = g_sfera_network_runtime.initialization_result;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0003392B;
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x6Cu);
    lift_push32(cpu, (uintptr_t)L"%S"); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433505u); lift_push32(cpu, r); sfera_sub_00431800(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_directplay_runtime.critical_section[0]);
    g_sfera_directplay_runtime.transport.receive_read_index = (uint32_t)(cpu->ebx);
    g_sfera_directplay_runtime.transport.receive_write_index = (uint32_t)(cpu->ebx);
    lift_store32((uintptr_t)&g_sfera_directplay_runtime.transport.reserved_30, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::InitializeCriticalSection), LIFT_CODE_TOKEN_VA(0x43351Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x433525u);
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000337D3;
    lift_push32(cpu, 0x48u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x433539u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43353Eu);
    cpu->edx = 0x231B9780u;
    cpu->eax = 0x11D51577u;
    cpu->ecx = 0x8F885D8Eu;
    cpu->esi = native_function_address32(&::CoCreateInstance);
    cpu->esp += 0xCu;
    lift_push32(cpu, (uintptr_t)&g_sfera_directplay_runtime.peer); lift_push32(cpu, (uintptr_t)&kDirectPlay8ClientIid); lift_push32(cpu, 1u);
    lift_store32(cpu->esp + 0x44u, cpu->edx);
    cpu->edx = 0x76AA058Fu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&kDirectPlay8ClientClsid);
    lift_store32(cpu->esp + 0x34u, 0x48u);
    lift_store32(cpu->esp + 0x50u, cpu->eax);
    lift_store32(cpu->esp + 0x54u, cpu->ecx);
    lift_store32(cpu->esp + 0x58u, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x3358Au), LIFT_CODE_TOKEN_RVA(0x33588u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43358Au);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000338EC;
    cpu->eax = g_sfera_directplay_runtime.transport.primary_address;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000335A9;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x335A3u), LIFT_CODE_TOKEN_RVA(0x335A1u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4335A3u);
    g_sfera_directplay_runtime.transport.primary_address = (uint32_t)(cpu->ebx);
    label_000335A9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4335A9u);
    lift_push32(cpu, (uintptr_t)&g_sfera_directplay_runtime.transport.primary_address); lift_push32(cpu, (uintptr_t)&kDirectPlay8AddressIid); lift_push32(cpu, 0x17u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&kDirectPlay8AddressClsid);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x335BDu), LIFT_CODE_TOKEN_RVA(0x335BBu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4335BDu);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000338EC;
    cpu->eax = g_sfera_directplay_runtime.transport.secondary_address;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000335DC;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x335D6u), LIFT_CODE_TOKEN_RVA(0x335D4u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4335D6u);
    g_sfera_directplay_runtime.transport.secondary_address = (uint32_t)(cpu->ebx);
    label_000335DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4335DCu);
    lift_push32(cpu, (uintptr_t)&g_sfera_directplay_runtime.transport.secondary_address); lift_push32(cpu, (uintptr_t)&kDirectPlay8AddressIid); lift_push32(cpu, 0x17u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&kDirectPlay8AddressClsid);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x335F0u), LIFT_CODE_TOKEN_RVA(0x335EEu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4335F0u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000338EC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ecx = (uint32_t)(uintptr_t)"Initialize\n";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433604u); lift_push32(cpu, r); sfera_sub_0047FED0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_directplay_runtime.peer;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xCu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00431B50)); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x33618u), LIFT_CODE_TOKEN_RVA(0x33616u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433618u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000338EC;
    cpu->eax = g_sfera_directplay_runtime.transport.primary_address;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x34u);
    lift_push32(cpu, (uintptr_t)&kDirectPlay8TcpIpProvider); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x33632u), LIFT_CODE_TOKEN_RVA(0x33630u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433632u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000338EC;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43363Fu); lift_push32(cpu, r); sfera_sub_00431880(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 2u); lift_push32(cpu, 4u);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->eax = g_sfera_directplay_runtime.transport.primary_address;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)L"port"); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x48u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x3365Eu), LIFT_CODE_TOKEN_RVA(0x3365Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43365Eu);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000338EC;
    cpu->eax = g_sfera_directplay_runtime.transport.primary_address;
    lift_push32(cpu, 2u); lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x20u, 2u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, (uintptr_t)L"traversalmode"); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x48u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x33689u), LIFT_CODE_TOKEN_RVA(0x33687u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433689u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000338EC;
    cpu->eax = g_sfera_directplay_runtime.transport.secondary_address;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x34u);
    lift_push32(cpu, (uintptr_t)&kDirectPlay8TcpIpProvider); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x336A3u), LIFT_CODE_TOKEN_RVA(0x336A1u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4336A3u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000338EC;
    cpu->eax = (uint32_t)(cpu->esp + 0x68u);
    cpu->edx = (uint32_t)(cpu->eax + 2u);
    label_000336B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4336B2u);
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->eax)) & 0xFFFFu);
    cpu->eax += 2u;
    if ((uint16_t)((cpu->ecx & 0xFFFFu)) != (uint16_t)((cpu->ebx & 0xFFFFu))) goto label_000336B2;
    cpu->ecx = g_sfera_directplay_runtime.transport.secondary_address;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    lift_push32(cpu, 1u);
    cpu->eax = (uint32_t)(cpu->eax + cpu->eax + 2u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x70u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)L"hostname"); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx + 0x48u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ecx), LIFT_CODE_TOKEN_RVA(0x336E0u), LIFT_CODE_TOKEN_RVA(0x336DEu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4336E0u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000338EC;
    cpu->eax = g_sfera_directplay_runtime.transport.secondary_address;
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, 2u); lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)&g_sfera_network_runtime.server_port); lift_push32(cpu, (uintptr_t)L"port"); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 0x48u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x33703u), LIFT_CODE_TOKEN_RVA(0x33701u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433703u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000338EC;
    cpu->eax = g_sfera_directplay_runtime.peer;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x40u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&g_sfera_network_runtime.directplay_caps); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x3371Eu), LIFT_CODE_TOKEN_RVA(0x3371Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43371Eu);
    cpu->eax = g_sfera_directplay_runtime.peer;
    lift_push32(cpu, cpu->ebx);
    g_sfera_network_runtime.directplay_caps.words[8] = 0x64u;
    g_sfera_network_runtime.directplay_caps.words[9] = cpu->ebx;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x44u);
    lift_push32(cpu, (uintptr_t)&g_sfera_network_runtime.directplay_caps); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x33741u), LIFT_CODE_TOKEN_RVA(0x3373Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433741u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    cpu->ecx = (uint32_t)(uintptr_t)"Connect\n";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43374Du); lift_push32(cpu, r); sfera_sub_0047FED0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_directplay_runtime.peer;
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&g_sfera_network_runtime.message_call_scratch); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_directplay_runtime.transport.primary_address;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_directplay_runtime.transport.secondary_address;
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x1Cu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x3377Du), LIFT_CODE_TOKEN_RVA(0x3377Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43377Du);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ebx)) goto label_000338EC;
    cpu->eax = g_sfera_directplay_runtime.peer;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&g_sfera_network_runtime.directplay_caps);
    g_sfera_network_runtime.directplay_caps.words[0] = (uint32_t)(0x24u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x4Cu);
    lift_push32(cpu, (uintptr_t)&kDirectPlay8TcpIpProvider); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x337A7u), LIFT_CODE_TOKEN_RVA(0x337A5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4337A7u);
    cpu->eax = g_sfera_directplay_runtime.peer;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&g_sfera_network_runtime.directplay_caps);
    lift_store32((uintptr_t)&g_sfera_network_runtime.directplay_caps.words[7], 4u);
    lift_store32((uintptr_t)&g_sfera_network_runtime.directplay_caps.words[8], 0x10000u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x48u);
    lift_push32(cpu, (uintptr_t)&kDirectPlay8TcpIpProvider); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x337D3u), LIFT_CODE_TOKEN_RVA(0x337D1u))) { return; }
    label_000337D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4337D3u);
    cpu->ecx = cpu->edi;
    g_sfera_network_runtime.initialization_result = (uint32_t)(cpu->ebx);
    g_sfera_network_runtime.timeout_marker_pending = (uint8_t)((cpu->ebx & 0xFFu));
    g_sfera_network_runtime.error_budget = (uint32_t)(cpu->ebx);
    g_sfera_network_runtime.network_error_active = (uint8_t)((cpu->ebx & 0xFFu));
    g_sfera_network_runtime.net_log_has_error = (uint8_t)((cpu->ebx & 0xFFu));
    g_sfera_network_runtime.initialized = (uint8_t)(1u);
    g_sfera_directplay_runtime.transport.transport_flag = (uint8_t)((cpu->ebx & 0xFFu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433805u); lift_push32(cpu, r); sfera_sub_00480090(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00033819;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433812u); lift_push32(cpu, r); sfera_sub_004801E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x33819u); lift_push32(cpu, r); sfera_sub_00480280(cpu,r); if (cpu->eip != r) return; }
    label_00033819: cpu->eip = LIFT_CODE_TOKEN_VA(0x433819u);
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled)) != (uint8_t)(1u)) goto label_00033926;
    cpu->eax = g_sfera_network_runtime.server_port;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Try init TCP-IP manager (%d '%s')\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43383Cu); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_24)) == (uint32_t)(cpu->ebx)) goto label_00033870;
    cpu->edx = 0x32Du;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\INet.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433856u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_24;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00033870;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433867u); lift_push32(cpu, r); sfera_sub_00418D50(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43386Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00033870: cpu->eip = LIFT_CODE_TOKEN_VA(0x433870u);
    cpu->edx = 0x32Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\INet.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43387Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xEABCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433889u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x204u, cpu->ebx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000338A4;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4338A2u); lift_push32(cpu, r); sfera_sub_004188A0(cpu,r); if (cpu->eip != r) return; }
    goto label_000338A6;
    label_000338A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4338A4u);
    cpu->eax = 0u;
    label_000338A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4338A6u);
    cpu->esi |= 0xFFFFFFFFu;
    lift_store32(cpu->esp + 0x204u, cpu->esi);
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_24) = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00033926;
    cpu->ecx = g_sfera_network_runtime.server_port;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4338C8u); lift_push32(cpu, r); sfera_sub_004193E0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0003390E;
    cpu->edx = g_sfera_network_runtime.server_port;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager (%d '%s') = ERROR\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4338E3u); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    g_sfera_network_runtime.initialization_result = (uint32_t)(cpu->esi);
    label_000338EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4338ECu);
    cpu->ecx = (uint32_t)(uintptr_t)"Network initialize error! ";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4338F6u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"\n";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433900u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"\n";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43390Au); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    goto label_0003392B;
    label_0003390E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43390Eu);
    cpu->eax = g_sfera_network_runtime.server_port;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Init TCP-IP manager (%d '%s') = OK\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433923u); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_00033926: cpu->eip = LIFT_CODE_TOKEN_VA(0x433926u);
    cpu->eax = 1u;
    label_0003392B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43392Bu);
    cpu->ecx = lift_load32(cpu->esp + 0x1FCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1F8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433960(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433960u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::DeleteCriticalSection);
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00033A32;
    if ((uint32_t)(g_sfera_directplay_runtime.peer) == (uint32_t)(cpu->ebx)) goto label_00033A73;
    if ((uint8_t)(g_sfera_network_runtime.timeout_marker_pending) != (uint8_t)(1u)) goto label_0003399D;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    cpu->ecx = (uint32_t)(uintptr_t)"-- T\n";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433997u); lift_push32(cpu, r); sfera_sub_0047FED0(cpu,r); if (cpu->eip != r) return; }
    g_sfera_network_runtime.timeout_marker_pending = (uint8_t)((cpu->ebx & 0xFFu));
    label_0003399D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43399Du);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) ^ (uint64_t)((cpu->edx & 0xFFu)))) & 0xFFu);
    cpu->ecx = (uint32_t)(uintptr_t)"Release\n";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4339A9u); lift_push32(cpu, r); sfera_sub_0047FED0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_network_runtime.net_log_has_error), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4339B8u); lift_push32(cpu, r); sfera_sub_00480110(cpu,r); if (cpu->eip != r) return; }
    g_sfera_network_runtime.initialized = (uint8_t)((cpu->ebx & 0xFFu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4339C3u); lift_push32(cpu, r); sfera_sub_00480300(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_directplay_runtime.peer;
    lift_push32(cpu, cpu->ebx);
    lift_store32((uintptr_t)&g_sfera_directplay_runtime.caps.connect_timeout_ms, 0x32u);
    lift_store32((uintptr_t)&g_sfera_directplay_runtime.caps.connect_retries, 1u);
    lift_store32((uintptr_t)&g_sfera_directplay_runtime.caps.timeout_until_keepalive_ms, 0x3E8u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x44u);
    lift_push32(cpu, (uintptr_t)&g_sfera_directplay_runtime.caps); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x339F4u), LIFT_CODE_TOKEN_RVA(0x339F2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4339F4u);
    cpu->eax = g_sfera_directplay_runtime.peer;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x38u);
    if ((uint8_t)(g_sfera_directplay_runtime.transport.transport_flag) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00033A0A;
    lift_push32(cpu, 1u);
    goto label_00033A0B;
    label_00033A0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x433A0Au);
    lift_push32(cpu, cpu->ebx);
    label_00033A0B: cpu->eip = LIFT_CODE_TOKEN_VA(0x433A0Bu);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x33A0Eu), LIFT_CODE_TOKEN_RVA(0x33A0Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433A0Eu);
    cpu->eax = g_sfera_directplay_runtime.peer;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x33A1Bu), LIFT_CODE_TOKEN_RVA(0x33A19u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433A1Bu);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_directplay_runtime.critical_section[0]);
    g_sfera_directplay_runtime.peer = (uint32_t)(cpu->ebx);
    g_sfera_network_runtime.initialization_result = (uint32_t)(0xFFFFFFFFu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x33A32u), LIFT_CODE_TOKEN_RVA(0x33A30u))) { return; }
    label_00033A32: cpu->eip = LIFT_CODE_TOKEN_VA(0x433A32u);
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled)) != (uint8_t)(1u)) goto label_00033A73;
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_client_config_runtime.state_24;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00033A73;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433A4Au); lift_push32(cpu, r); sfera_sub_00418A20(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_directplay_runtime.critical_section[0]);
    g_sfera_network_runtime.initialized = (uint8_t)((cpu->ebx & 0xFFu));
    g_sfera_network_runtime.initialization_result = (uint32_t)(0xFFFFFFFFu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x33A61u), LIFT_CODE_TOKEN_RVA(0x33A5Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433A61u);
    lift_push32(cpu, (uintptr_t)"Deinit TCP-IP manager = OK\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433A70u); lift_push32(cpu, r); sfera_sub_00418750(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_00033A73: cpu->eip = LIFT_CODE_TOKEN_VA(0x433A73u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433A80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433A80u);
    cpu->esp -= 0x84u;
    if ((uint8_t)(g_sfera_directplay_runtime.transport.receive_corrupted) == (uint8_t)(0u)) goto label_00033AC9;
    lift_push32(cpu, (uint32_t)(uintptr_t)"receive_netdata");
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, (uintptr_t)"%s(): DATA CORRUPTION\n"); lift_push32(cpu, cpu->eax);
    g_sfera_directplay_runtime.transport.receive_corrupted = (uint8_t)(0u);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x433AB3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x433AB9u);
    cpu->esp += 0xCu;
    cpu->edx = (uint32_t)(cpu->esp);
    cpu->ecx = (uint32_t)(uintptr_t)"logs\\directplay";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x33AC9u); lift_push32(cpu, r); sfera_sub_00434660(cpu,r); if (cpu->eip != r) return; }
    label_00033AC9: cpu->eip = LIFT_CODE_TOKEN_VA(0x433AC9u);
    if ((uint32_t)(g_sfera_network_runtime.initialization_result) != (uint32_t)(1u)) goto label_00033B72;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::EnterCriticalSection);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_directplay_runtime.critical_section[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x33AE5u), LIFT_CODE_TOKEN_RVA(0x33AE3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433AE5u);
    cpu->eax = g_sfera_directplay_runtime.transport.receive_read_index;
    cpu->ebp = native_function_address32(&::LeaveCriticalSection);
    if ((uint32_t)(cpu->eax) == (uint32_t)(g_sfera_directplay_runtime.transport.receive_write_index)) goto label_00033B62;
    lift_push32(cpu, cpu->esi);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00033B00: cpu->eip = LIFT_CODE_TOKEN_VA(0x433B00u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1A8u);
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_network_runtime.message_slots[0]);
    { uint64_t l=(uint64_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = cpu->eax;
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00033B1F;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433B1Du); lift_push32(cpu, r); sfera_sub_00432970(cpu,r); if (cpu->eip != r) return; }
    goto label_00033B24;
    label_00033B1F: cpu->eip = LIFT_CODE_TOKEN_VA(0x433B1Fu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x33B24u); lift_push32(cpu, r); sfera_sub_00431C20(cpu,r); if (cpu->eip != r) return; }
    label_00033B24: cpu->eip = LIFT_CODE_TOKEN_VA(0x433B24u);
    cpu->eax = g_sfera_directplay_runtime.transport.receive_read_index;
    ++cpu->eax;
    lift_store32(cpu->esi, 0u);
    g_sfera_directplay_runtime.transport.receive_read_index = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xBE8u)) goto label_00033B46;
    g_sfera_directplay_runtime.transport.receive_read_index = (uint32_t)(0u);
    label_00033B46: cpu->eip = LIFT_CODE_TOKEN_VA(0x433B46u);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_directplay_runtime.critical_section[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x33B4Du), LIFT_CODE_TOKEN_RVA(0x33B4Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433B4Du);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_directplay_runtime.critical_section[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x33B54u), LIFT_CODE_TOKEN_RVA(0x33B52u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433B54u);
    cpu->eax = g_sfera_directplay_runtime.transport.receive_read_index;
    if ((uint32_t)(cpu->eax) != (uint32_t)(g_sfera_directplay_runtime.transport.receive_write_index)) goto label_00033B00;
    cpu->esi = lift_pop32(cpu);
    label_00033B62: cpu->eip = LIFT_CODE_TOKEN_VA(0x433B62u);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_directplay_runtime.critical_section[0]);
    g_sfera_directplay_runtime.transport.receive_busy = (uint8_t)(0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x33B70u), LIFT_CODE_TOKEN_RVA(0x33B6Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433B70u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_00033B72: cpu->eip = LIFT_CODE_TOKEN_VA(0x433B72u);
    cpu->esp += 0x84u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433B90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433B90u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0x10u)) goto label_00033B9C;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00033B9C;
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
    label_00033B9C: cpu->eip = LIFT_CODE_TOKEN_VA(0x433B9Cu);
    cpu->eax = 1u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433BB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433BB0u);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_00033BBA;
    cpu->eax = 1u;
    lift_return(cpu, 0u, stop_address); return;
    label_00033BBA: cpu->eip = LIFT_CODE_TOKEN_VA(0x433BBAu);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)(0xFu), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->eax) * 8u) + 4u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433BD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433BD0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x96u); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x433BE1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x433BE7u);
    cpu->esp += 0xCu;
    lift_store8(cpu->esi + 0x99u, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433C00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433C00u);
    cpu->esp -= 0x18u;
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->registered_object_count;
    lift_store32(cpu->esp + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_02;
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    lift_push32(cpu, 0x14u);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433C4Fu); lift_push32(cpu, r); sfera_sub_004311F0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00033C65;
    cpu->eax = g_sfera_mbc_runtime->registered_object_count;
    g_sfera_mbc_runtime->registered_objects[cpu->eax] = (uint32_t)(cpu->esi);
    ++cpu->eax;
    g_sfera_mbc_runtime->registered_object_count = (uint32_t)(cpu->eax);
    label_00033C65: cpu->eip = LIFT_CODE_TOKEN_VA(0x433C65u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433C80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433C80u);
    cpu->esp -= 0x18u;
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->esp, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->eax = lift_load32(cpu->eax + 0xCu);
    lift_store32(cpu->esp + 8u, cpu->ecx);
    lift_push32(cpu, 0x14u);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_02;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433CC0u); lift_push32(cpu, r); sfera_sub_00430F40(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_00033CD6;
    cpu->eax = 0u;
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_00033CD6: cpu->eip = LIFT_CODE_TOKEN_VA(0x433CD6u);
    cpu->eax = g_sfera_mbc_runtime->registered_objects[cpu->eax];
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433CF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433CF0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(2u) & 0xFFu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0xB9u)) == (uint8_t)((cpu->eax & 0xFFu))) goto label_00033D8E;
    if ((int32_t)(uint32_t)(cpu->edi) < 0) goto label_00033D8E;
    ++g_sfera_mbc_runtime->execution_chain_count;
    lift_store8(cpu->esi + 0xB9u, cpu->eax & 0xFFu);
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->execution_chain_tail) >= (int32_t)(uint32_t)(0u)) goto label_00033D52;
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->execution_chain_head) < (int32_t)(uint32_t)(0u)) goto label_00033D34;
    cpu->ecx = (uint32_t)(uintptr_t)"internal error 34096874309";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x33D34u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    label_00033D34: cpu->eip = LIFT_CODE_TOKEN_VA(0x433D34u);
    g_sfera_mbc_runtime->execution_chain_tail = (uint32_t)(cpu->edi);
    g_sfera_mbc_runtime->execution_chain_head = (uint32_t)(cpu->edi);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0xCCu, cpu->eax);
    lift_store32(cpu->esi + 0xC8u, cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00033D52: cpu->eip = LIFT_CODE_TOKEN_VA(0x433D52u);
    cpu->eax = g_sfera_mbc_runtime->execution_chain_head;
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00033D6A;
    cpu->ecx = (uint32_t)(uintptr_t)"internal error 04975350934760";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433D65u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_mbc_runtime->execution_chain_head;
    label_00033D6A: cpu->eip = LIFT_CODE_TOKEN_VA(0x433D6Au);
    cpu->ecx = cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x348u);
    lift_store32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].execution_prev_index), cpu->edi);
    lift_store32(cpu->esi + 0xCCu, cpu->eax);
    lift_store32(cpu->esi + 0xC8u, 0xFFFFFFFFu);
    g_sfera_mbc_runtime->execution_chain_head = (uint32_t)(cpu->edi);
    label_00033D8E: cpu->eip = LIFT_CODE_TOKEN_VA(0x433D8Eu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433DA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433DA0u);
    if ((uint8_t)(lift_load8(cpu->edx + 0xB9u)) == (uint8_t)(0u)) goto label_00033E0A;
    --g_sfera_mbc_runtime->execution_chain_count;
    cpu->eax = lift_load32(cpu->edx + 0xCCu);
    lift_store8(cpu->edx + 0xB9u, 0u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00033DD5;
    cpu->ecx = lift_load32(cpu->edx + 0xC8u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    lift_store32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].execution_prev_index), cpu->ecx);
    goto label_00033DE0;
    label_00033DD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x433DD5u);
    cpu->eax = lift_load32(cpu->edx + 0xC8u);
    g_sfera_mbc_runtime->execution_chain_tail = (uint32_t)(cpu->eax);
    label_00033DE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x433DE0u);
    cpu->eax = lift_load32(cpu->edx + 0xC8u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00033DFE;
    cpu->ecx = lift_load32(cpu->edx + 0xCCu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    lift_store32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].execution_next_index), cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
    label_00033DFE: cpu->eip = LIFT_CODE_TOKEN_VA(0x433DFEu);
    cpu->edx = lift_load32(cpu->edx + 0xCCu);
    g_sfera_mbc_runtime->execution_chain_head = (uint32_t)(cpu->edx);
    label_00033E0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x433E0Au);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433E10u);
    cpu->eax = g_sfera_inter_scalar_runtime.mode_01;
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(0x16u), 32u);
    { int64_t v=(int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x16Du); cpu->edx= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x12u), 32u);
    cpu->ecx &= 0xFu;
    cpu->ecx = sfera_calendar_days_before_month(cpu->ecx);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(0xDu), 32u);
    cpu->edx &= 0x1Fu;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x1Fu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ecx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 8u));
    cpu->edx = cpu->ecx;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(4u), 32u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->ecx &= 0x3Fu;
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 4u));
    cpu->eax &= 3u;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433E70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433E70u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x433E7Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x433E82u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
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
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(4u), 32u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433EB5u); lift_push32(cpu, r); sfera_sub_004EEA40(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u); lift_push32(cpu, 0x201480u);
    cpu->ebx = cpu->edx;
    cpu->edi = cpu->eax;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433EC7u); lift_push32(cpu, r); sfera_sub_004EEA40(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0xFFDFEB80u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->eax;
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433EDBu); lift_push32(cpu, r); sfera_sub_004EED20(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->eax = g_sfera_inter_scalar_runtime.mode_01;
    cpu->ebx = (uint64_t)(cpu->ebx) + (uint64_t)(cpu->edx) + (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1680u);
    cpu->esi += 0x188u;
    lift_push32(cpu, cpu->ebx);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x3FFFFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(0x16u), 32u);
    lift_push32(cpu, cpu->edi);
    cpu->esi ^= cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433F02u); lift_push32(cpu, r); sfera_sub_004EEA40(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0xFFFFE980u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ebp = cpu->eax;
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433F16u); lift_push32(cpu, r); sfera_sub_004EED20(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->ebx = (uint64_t)(cpu->ebx) + (uint64_t)(cpu->edx) + (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->esi &= 0xFFC43FFFu;
    cpu->esi |= 0x42000u;
    cpu->eax = 1u;
    label_00033F30: cpu->eip = LIFT_CODE_TOKEN_VA(0x433F30u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00033F56;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00033F45;
    { uint64_t l=(uint64_t)(sfera_calendar_days_before_month(cpu->eax + 1u)), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_00033F56;
    label_00033F45: cpu->eip = LIFT_CODE_TOKEN_VA(0x433F45u);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00033F5E;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00033F56;
    { uint64_t l=(uint64_t)(sfera_calendar_days_before_month(cpu->eax)), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_00033F5E;
    label_00033F56: cpu->eip = LIFT_CODE_TOKEN_VA(0x433F56u);
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xDu)) goto label_00033F30;
    goto label_00033F7F;
    label_00033F5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x433F5Eu);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(sfera_calendar_days_before_month(cpu->eax)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebp = v; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    { uint64_t l=(uint64_t)(cpu->ebp), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)(0xDu), 32u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(0x3E000u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x12u), 32u);
    cpu->ebp |= cpu->eax;
    cpu->esi &= 0xFFC01FFFu;
    cpu->esi |= cpu->ebp;
    label_00033F7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x433F7Fu);
    lift_push32(cpu, 0u); lift_push32(cpu, 0xF0u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433F8Du); lift_push32(cpu, r); sfera_sub_004EEA40(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0xFFFFFF10u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ebp = cpu->eax;
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433FA1u); lift_push32(cpu, r); sfera_sub_004EED20(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    lift_push32(cpu, 4u);
    cpu->ebx = (uint64_t)(cpu->ebx) + (uint64_t)(cpu->edx) + (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433FB0u); lift_push32(cpu, r); sfera_sub_004EEA40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax &= 0x3Fu;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(0x1Fu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    lift_push32(cpu, 0u);
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)(6u), 32u);
    cpu->eax |= cpu->ebp;
    lift_push32(cpu, 4u);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->ebx);
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x433FCEu); lift_push32(cpu, r); sfera_sub_004EEC60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax &= 3u;
    cpu->esi &= 0xFFFFE000u;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx |= cpu->eax;
    cpu->ecx |= cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    g_sfera_inter_scalar_runtime.mode_01 = (uint32_t)(cpu->ecx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00433FF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x433FF0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->eax = cpu->edi;
    cpu->esi = cpu->ecx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00034000: cpu->eip = LIFT_CODE_TOKEN_VA(0x434000u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00034000;
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00034067;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_00034067;
    cpu->eax = (uint32_t)(cpu->ebx + 0xFFFFFFFFu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43401Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434021u);
    cpu->esp += 0xCu;
    lift_store8(cpu->esi + cpu->ebx + 0xFFFFFFFFu, 0u);
    if ((int32_t)(uint32_t)(g_sfera_network_runtime.active_slot) < (int32_t)(uint32_t)(0u)) goto label_0003405F;
    cpu->eax = cpu->edi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00034037: cpu->eip = LIFT_CODE_TOKEN_VA(0x434037u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00034037;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"MBINTER MESSAGE: Wrong string to copy: '%s', strlen: %d\n"); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x43404Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434052u);
    cpu->esp += 0x10u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3405Fu); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    label_0003405F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43405Fu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00034067: cpu->eip = LIFT_CODE_TOKEN_VA(0x434067u);
    cpu->ecx = cpu->edi;
    cpu->esi -= cpu->edi;
    label_00034070: cpu->eip = LIFT_CODE_TOKEN_VA(0x434070u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->esi + cpu->ecx, cpu->edx & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00034070;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x434080u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi)) & 0xFFu);
    cpu->esi = cpu->ecx;
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000340AB;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00034090: cpu->eip = LIFT_CODE_TOKEN_VA(0x434090u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Au)) goto label_000340B5;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)((cpu->eax & 0xFFu))) goto label_000340A2;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x3Fu)) goto label_000340CD;
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_000340CD;
    label_000340A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4340A2u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    ++cpu->esi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00034090;
    label_000340AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4340ABu);
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi)), r=(uint64_t)((cpu->eax & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    label_000340B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4340B2u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000340B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4340B5u);
    cpu->edx = (uint32_t)(cpu->edi + 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4340BFu); lift_push32(cpu, r); sfera_sub_00434080(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000340B2;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    ++cpu->esi;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000340B5;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000340CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4340CDu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004340E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4340E0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    lift_push32(cpu, 0x2Eu); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->ecx);
    lift_native_call(cpu, native_strrchr_address32(), LIFT_CODE_TOKEN_VA(0x4340FBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434101u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) != 0u) goto label_0003411C;
    cpu->eax = cpu->edi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_00034110: cpu->eip = LIFT_CODE_TOKEN_VA(0x434110u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00034110;
    cpu->eax -= cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + cpu->edi);
    label_0003411C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43411Cu);
    cpu->eax = cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00034121: cpu->eip = LIFT_CODE_TOKEN_VA(0x434121u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00034121;
    cpu->eax -= cpu->edx;
    cpu->ebx = (uint32_t)(cpu->eax + 1u);
    cpu->eax = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x434134u); lift_push32(cpu, r); sfera_sub_004EEA10(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esp;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43413Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434141u);
    cpu->esp += 0xCu;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::GetLocalTime), LIFT_CODE_TOKEN_VA(0x434148u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43414Eu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    cpu->edx = lift_load16(cpu->ebp + 0xFFFFFFF2u);
    cpu->eax = lift_load16(cpu->ebp + 0xFFFFFFEEu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load16(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx -= 0x7D0u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    cpu->esi -= cpu->edi;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"%.*s_%02d.%02d.%02d%s"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x434174u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43417Au);
    cpu->esp += 0x20u;
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004341A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4341A0u);
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000341B7;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_000341B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4341B7u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\script.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4341BDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4341C3u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000341E8;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    g_sfera_log_first_write = (uint32_t)(0u);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x4341D8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4341DEu);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4341DFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4341E5u);
    cpu->esp += 0xCu;
    label_000341E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4341E8u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434240(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x434240u);
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034253;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_00034253: cpu->eip = LIFT_CODE_TOKEN_VA(0x434253u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\script.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x43425Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434260u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00034293;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    cpu->esp -= 8u;
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)"%f"); lift_push32(cpu, cpu->esi);
    g_sfera_log_first_write = (uint32_t)(0u);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x434283u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434289u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x43428Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434290u);
    cpu->esp += 0x14u;
    label_00034293: cpu->eip = LIFT_CODE_TOKEN_VA(0x434293u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004342A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4342A0u);
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000342B7;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_000342B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4342B7u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\deletings.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4342BDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4342C3u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000342DE;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x4342CEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4342D4u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4342D5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4342DBu);
    cpu->esp += 0xCu;
    label_000342DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4342DEu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434340(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x434340u);
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034353;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_00034353: cpu->eip = LIFT_CODE_TOKEN_VA(0x434353u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\deletings.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x43435Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434360u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00034389;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    cpu->esp -= 8u;
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)"%f"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x434379u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43437Fu);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x434380u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434386u);
    cpu->esp += 0x14u;
    label_00034389: cpu->eip = LIFT_CODE_TOKEN_VA(0x434389u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x434390u);
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000343A7;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_000343A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4343A7u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\gm.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4343ADu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4343B3u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000343CE;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x4343BEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4343C4u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4343C5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4343CBu);
    cpu->esp += 0xCu;
    label_000343CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4343CEu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434430(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x434430u);
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034443;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_00034443: cpu->eip = LIFT_CODE_TOKEN_VA(0x434443u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\gm.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x43444Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434450u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00034479;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    cpu->esp -= 8u;
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)"%f"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x434469u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43446Fu);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x434470u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434476u);
    cpu->esp += 0x14u;
    label_00034479: cpu->eip = LIFT_CODE_TOKEN_VA(0x434479u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x434480u);
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034497;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_00034497: cpu->eip = LIFT_CODE_TOKEN_VA(0x434497u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\trade.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x43449Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4344A3u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000344BE;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x4344AEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4344B4u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x4344B5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4344BBu);
    cpu->esp += 0xCu;
    label_000344BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4344BEu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434520(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x434520u);
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034533;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_00034533: cpu->eip = LIFT_CODE_TOKEN_VA(0x434533u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\trade.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x43453Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434540u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00034569;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    cpu->esp -= 8u;
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)"%f"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x434559u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43455Fu);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x434560u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434566u);
    cpu->esp += 0x14u;
    label_00034569: cpu->eip = LIFT_CODE_TOKEN_VA(0x434569u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434610(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x434610u);
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034623;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_00034623: cpu->eip = LIFT_CODE_TOKEN_VA(0x434623u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"logs\\violations.log");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x43462Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434630u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00034659;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    cpu->esp -= 8u;
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)"%f"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x434649u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43464Fu);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x434650u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434656u);
    cpu->esp += 0x14u;
    label_00034659: cpu->eip = LIFT_CODE_TOKEN_VA(0x434659u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434660(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x434660u);
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034677;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_00034677: cpu->eip = LIFT_CODE_TOKEN_VA(0x434677u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x434679u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43467Fu);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0003469A;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x43468Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434690u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x434691u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434697u);
    cpu->esp += 0xCu;
    label_0003469A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43469Au);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004346F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4346F0u);
    { uint64_t l=(uint64_t)(g_sfera_log_first_write), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034703;
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_00034703: cpu->eip = LIFT_CODE_TOKEN_VA(0x434703u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x434706u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43470Cu);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00034735;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    cpu->esp -= 8u;
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)"%f"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x434725u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43472Bu);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x43472Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434732u);
    cpu->esp += 0x14u;
    label_00034735: cpu->eip = LIFT_CODE_TOKEN_VA(0x434735u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434740(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x434740u);
    cpu->esp -= 0xA0u;
    cpu->eax = lift_load32((uintptr_t)"logs\\tmp_cl");
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"logs\\tmp_cl") + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"logs\\tmp_cl") + 4u);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x30u, cpu->edx);
    lift_store32(cpu->esp + 0x34u, 0u);
    lift_native_call(cpu, native_function_address32(&::GetLocalTime), LIFT_CODE_TOKEN_VA(0x434783u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434789u);
    cpu->ecx = lift_load16(cpu->esp + 0x1Au);
    cpu->edx = lift_load16(cpu->esp + 0x16u);
    cpu->eax = lift_load16(cpu->esp + 0x14u);
    cpu->edi = native_function_address32(&::sprintf);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->eax -= 0x7D0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, (uintptr_t)"%s_%02d%02d%02d.log"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x347B7u), LIFT_CODE_TOKEN_RVA(0x347B5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4347B7u);
    cpu->eax = (uint32_t)(cpu->esp + 0x5Cu);
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x4347C1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4347C7u);
    cpu->esi = cpu->eax;
    cpu->esp += 0x20u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00034819;
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4347D5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4347DBu);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4347E0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4347E6u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, (uintptr_t)"%02i:%02i:%02i "); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x347FDu), LIFT_CODE_TOKEN_RVA(0x347FBu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4347FDu);
    cpu->edi = native_function_address32(&::fputs);
    cpu->edx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x3480Bu), LIFT_CODE_TOKEN_RVA(0x34809u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43480Bu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x3480Fu), LIFT_CODE_TOKEN_RVA(0x3480Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43480Fu);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x434810u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434816u);
    cpu->esp += 0x30u;
    label_00034819: cpu->eip = LIFT_CODE_TOKEN_VA(0x434819u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xA0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x434840u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    label_00034842: cpu->eip = LIFT_CODE_TOKEN_VA(0x434842u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    if ((uint8_t)(((cpu->ecx & 0xFFu)) & (1u)) == 0u) goto label_00034850;
    cpu->eax ^= 0xEDB88320u;
    label_00034850: cpu->eip = LIFT_CODE_TOKEN_VA(0x434850u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003485D;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0003485F;
    label_0003485D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43485Du);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0003485F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43485Fu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003486C;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0003486E;
    label_0003486C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43486Cu);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0003486E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43486Eu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003487B;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0003487D;
    label_0003487B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43487Bu);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0003487D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43487Du);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003488A;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0003488C;
    label_0003488A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43488Au);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0003488C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43488Cu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00034899;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0003489B;
    label_00034899: cpu->eip = LIFT_CODE_TOKEN_VA(0x434899u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0003489B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43489Bu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000348A8;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_000348AA;
    label_000348A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4348A8u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_000348AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4348AAu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000348B7;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_000348B9;
    label_000348B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4348B7u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_000348B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4348B9u);
    lift_store32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_crc32_table[0]), cpu->eax);
    ++cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00034842;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004348D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4348D0u);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000348FF;
    cpu->eax = g_sfera_mbc_runtime->file_crc32;
    lift_push32(cpu, cpu->esi);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000348E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4348E0u);
    cpu->esi = (int8_t)(lift_load8(cpu->ecx));
    cpu->esi ^= cpu->eax;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax ^= lift_load32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_crc32_table[0]));
    ++cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    g_sfera_mbc_runtime->file_crc32 = (uint32_t)(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000348E0;
    cpu->esi = lift_pop32(cpu);
    label_000348FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4348FFu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x434900u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = g_sfera_mbc_runtime->execution_context_depth;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00034995;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::sprintf);
    lift_push32(cpu, cpu->esi);
    label_00034925: cpu->eip = LIFT_CODE_TOKEN_VA(0x434925u);
    cpu->eax = cpu->edi;
    --cpu->ebx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->edi = cpu->edi;
    label_00034930: cpu->eip = LIFT_CODE_TOKEN_VA(0x434930u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00034930;
    cpu->eax -= cpu->edx;
    cpu->ecx = (uint32_t)(cpu->eax + cpu->edi);
    cpu->eax = g_sfera_mbc_runtime->execution_context_stack[cpu->ebx].process_index;
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00034950;
    lift_push32(cpu, (uintptr_t)"\nCall from C++\n"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x3494Bu), LIFT_CODE_TOKEN_RVA(0x34949u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43494Bu);
    cpu->esp += 8u;
    goto label_0003497F;
    label_00034950: cpu->eip = LIFT_CODE_TOKEN_VA(0x434950u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    cpu->edx = lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id));
    if ((uint32_t)(cpu->edx) != (uint32_t)(g_sfera_mbc_runtime->execution_context_stack[cpu->ebx].process_id)) goto label_00034988;
    cpu->edx = g_sfera_mbc_runtime->execution_context_stack[cpu->ebx].program_index;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xA4u);
    cpu->edx += g_sfera_mbc_runtime->execution_context_stack[cpu->ebx].program_table_base;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].name[0]));
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"\nPrevious prc: %s\nProgram: %s\n"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x3497Cu), LIFT_CODE_TOKEN_RVA(0x3497Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43497Cu);
    cpu->esp += 0x10u;
    label_0003497F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43497Fu);
    if ((int32_t)(uint32_t)(cpu->ebx) > 0) goto label_00034925;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00034988: cpu->eip = LIFT_CODE_TOKEN_VA(0x434988u);
    lift_push32(cpu, (uintptr_t)"\nError in prc call stack\n"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x34990u), LIFT_CODE_TOKEN_RVA(0x3498Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x434990u);
    cpu->esp += 8u;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_00034995: cpu->eip = LIFT_CODE_TOKEN_VA(0x434995u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004349A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4349A0u);
    cpu->esp -= 0xCu;
    cpu->eax = 0x7FFFu;
    lift_store16(cpu->ecx, cpu->eax & 0xFFFFu);
    lift_store32(cpu->esp + 8u, cpu->edx);
    lift_store32(cpu->edx, 0u);
    cpu->edx = g_sfera_mbc_runtime->process_index;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 8u, cpu->ecx);
    lift_store32(cpu->esp + 4u, cpu->ebp);
    if ((uint32_t)(cpu->edx) > (uint32_t)(0xFFFFu)) goto label_00034ADF;
    cpu->eax = cpu->edx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].bytecode_base));
    if ((uint32_t)(g_sfera_mbc_runtime->bytecode_base) == (uint32_t)(cpu->ecx)) goto label_000349F1;
    cpu->ebp = 0x80u;
    lift_store32(cpu->esp + 4u, cpu->ebp);
    label_000349F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4349F1u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->current_instruction_address;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    cpu->esi -= cpu->ecx;
    if ((uint32_t)(cpu->edi) == 0u) goto label_00034A39;
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].bytecode_size));
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->eax -= cpu->esi;
    if ((int32_t)(uint32_t)(cpu->eax) > 0) goto label_00034A1B;
    lift_store32(cpu->ecx, 0u);
    goto label_00034A33;
    label_00034A1B: cpu->eip = LIFT_CODE_TOKEN_VA(0x434A1Bu);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ecx)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_00034A21;
    lift_store32(cpu->ecx, cpu->eax);
    label_00034A21: cpu->eip = LIFT_CODE_TOKEN_VA(0x434A21u);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->current_instruction_address;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x434A2Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434A30u);
    cpu->esp += 0xCu;
    label_00034A33: cpu->eip = LIFT_CODE_TOKEN_VA(0x434A33u);
    cpu->edx = g_sfera_mbc_runtime->process_index;
    label_00034A39: cpu->eip = LIFT_CODE_TOKEN_VA(0x434A39u);
    cpu->ecx = cpu->edx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x348u);
    cpu->edi = lift_load16(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].code_range_count));
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (int16_t)((cpu->edi & 0xFFFFu));
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x24u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00034A7F;
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].code_range_begin[0]));
    cpu->esp = (uint32_t)(cpu->esp);
    label_00034A60: cpu->eip = LIFT_CODE_TOKEN_VA(0x434A60u);
    cpu->edi = lift_load32(cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->edi)) goto label_00034A6F;
    cpu->ebp = lift_load32(cpu->ecx + 0x20u);
    cpu->ebp += cpu->edi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->ebp)) goto label_00034A92;
    label_00034A6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x434A6Fu);
    ++cpu->eax;
    cpu->ecx += 4u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ebx)) goto label_00034A60;
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_load32(cpu->esp + 0x24u);
    label_00034A7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x434A7Fu);
    if ((uint16_t)((cpu->edi & 0xFFFFu)) != (uint16_t)(8u)) goto label_00034AD2;
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (uint32_t)(cpu->ebp + 2u);
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 8u, stop_address); return;
    label_00034A92: cpu->eip = LIFT_CODE_TOKEN_VA(0x434A92u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1A4u);
    cpu->edx += cpu->eax;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(((uint32_t)(cpu->edx) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].code_range_ids[0]))) & 0xFFFFu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store16(cpu->edx, cpu->ecx & 0xFFFFu);
    cpu->ecx = g_sfera_mbc_runtime->process_index;
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xD2u);
    cpu->ecx += cpu->eax;
    cpu->esi -= lift_load32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].code_range_begin[0]));
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->edx, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 8u, stop_address); return;
    label_00034AD2: cpu->eip = LIFT_CODE_TOKEN_VA(0x434AD2u);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (uint32_t)(cpu->ebp + 3u);
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 8u, stop_address); return;
    label_00034ADF: cpu->eip = LIFT_CODE_TOKEN_VA(0x434ADFu);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434AF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x434AF0u);
    cpu->esp -= 0xB4u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00034B33;
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x434B0Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434B15u);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    cpu->esp += 4u;
    --cpu->edi;
    cpu->edi = cpu->edi;
    label_00034B20: cpu->eip = LIFT_CODE_TOKEN_VA(0x434B20u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00034B20;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x0020)) & 0xFFFFu);
    lift_store16(cpu->edi, cpu->eax & 0xFFFFu);
    goto label_00034B3A;
    label_00034B33: cpu->eip = LIFT_CODE_TOKEN_VA(0x434B33u);
    g_sfera_mbc_runtime->diagnostic_context[0] = (uint8_t)(0u);
    label_00034B3A: cpu->eip = LIFT_CODE_TOKEN_VA(0x434B3Au);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x14u, 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x434B59u); lift_push32(cpu, r); sfera_sub_004349A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(7u), 32u);
    cpu->ecx &= 1u;
    cpu->eax &= 0xFFFFFF7Fu;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00034BA3;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    --cpu->edi;
    label_00034B75: cpu->eip = LIFT_CODE_TOKEN_VA(0x434B75u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00034B75;
    cpu->ecx = 9u;
    cpu->esi = (uint32_t)(uintptr_t)"PrcName,CodeOffs: unknown. (wrong pos)";
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    lift_movs8(cpu, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xB4u;
    lift_return(cpu, 0u, stop_address); return;
    label_00034BA3: cpu->eip = LIFT_CODE_TOKEN_VA(0x434BA3u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(2u)) goto label_00034BDD;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    --cpu->edi;
    cpu->edi = cpu->edi;
    label_00034BB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x434BB0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00034BB0;
    cpu->ecx = 0xFu;
    cpu->esi = (uint32_t)(uintptr_t)"PrcName,CodeOffs: unknown. (modulesNum == MAX_MODULES_IN_PRC)";
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xB4u;
    lift_return(cpu, 0u, stop_address); return;
    label_00034BDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x434BDDu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(3u)) goto label_00034C15;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    --cpu->edi;
    label_00034BE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x434BE8u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00034BE8;
    cpu->ecx = 0xBu;
    cpu->esi = (uint32_t)(uintptr_t)"PrcName,CodeOffs: unknown. (Offset not found)";
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xB4u;
    lift_return(cpu, 0u, stop_address); return;
    label_00034C15: cpu->eip = LIFT_CODE_TOKEN_VA(0x434C15u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = 0u;
    lift_store8(cpu->esp + 0x40u, 0u);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00034C74;
    label_00034C26: cpu->eip = LIFT_CODE_TOKEN_VA(0x434C26u);
    cpu->eax = lift_load8(cpu->esp + cpu->ebp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, (uintptr_t)"%x "); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x434C36u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434C3Cu);
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    cpu->esp += 0xCu;
    cpu->ecx = cpu->eax;
    label_00034C45: cpu->eip = LIFT_CODE_TOKEN_VA(0x434C45u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00034C45;
    cpu->edi = (uint32_t)(cpu->esp + 0x40u);
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00034C55: cpu->eip = LIFT_CODE_TOKEN_VA(0x434C55u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034C55;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    ++cpu->ebp;
    lift_movs8(cpu, 1u);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(cpu->ebx)) goto label_00034C26;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    label_00034C74: cpu->eip = LIFT_CODE_TOKEN_VA(0x434C74u);
    cpu->edi = (uint32_t)(cpu->esp + 0x40u);
    cpu->ebp = lift_pop32(cpu);
    --cpu->edi;
    cpu->ebx = lift_pop32(cpu);
    label_00034C80: cpu->eip = LIFT_CODE_TOKEN_VA(0x434C80u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00034C80;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x000A)) & 0xFFFFu);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    lift_store16(cpu->edi, cpu->edx & 0xFFFFu);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00034CE0;
    cpu->edi = cpu->edi;
    label_00034CA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x434CA0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00034CA0;
    cpu->ecx = g_sfera_mbc_runtime->process_index;
    cpu->eax -= cpu->edx;
    cpu->edx = cpu->ecx;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    cpu->edx = lift_load32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].bytecode_base));
    lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->bytecode_base;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]));
    lift_push32(cpu, (uintptr_t)"Warn!!! pos = %d, sBaseCodePtr = %d, Prc[pos].baseCodePtr = %d. "); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x434CD2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434CD8u);
    cpu->esp += 0x14u;
    goto label_00034D09;
    label_00034CE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x434CE0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00034CE0;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax -= cpu->edx;
    cpu->edx = lift_load16(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]));
    lift_push32(cpu, (uintptr_t)"module:%d, code:%d. "); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x434D00u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434D06u);
    cpu->esp += 0x10u;
    label_00034D09: cpu->eip = LIFT_CODE_TOKEN_VA(0x434D09u);
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    cpu->ecx = cpu->eax;
    (void)cpu;
    label_00034D10: cpu->eip = LIFT_CODE_TOKEN_VA(0x434D10u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00034D10;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00034D21: cpu->eip = LIFT_CODE_TOKEN_VA(0x434D21u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034D21;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xB4u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434D50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x434D50u);
    { uint64_t l=(uint64_t)(g_sfera_network_runtime.active_slot), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00034D81;
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x434D66u); lift_push32(cpu, r); sfera_sub_00434AF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_diagnostic_log_byte;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x434D7Au); lift_push32(cpu, r); sfera_sub_004ED410(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x34D81u); lift_push32(cpu, r); sfera_sub_004ED380(cpu,r); if (cpu->eip != r) return; }
    label_00034D81: cpu->eip = LIFT_CODE_TOKEN_VA(0x434D81u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434D90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x434D90u);
    cpu->esp -= 0x404u;
    if ((int32_t)(uint32_t)(g_sfera_network_runtime.active_slot) >= (int32_t)(uint32_t)(0u)) goto label_00034DC4;
    cpu->eax = 0u;
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
    label_00034DC4: cpu->eip = LIFT_CODE_TOKEN_VA(0x434DC4u);
    cpu->ecx = 1u;
    g_sfera_mbc_runtime->diagnostic_context[0] = (uint8_t)(0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x434DD5u); lift_push32(cpu, r); sfera_sub_00434AF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_mbc_runtime->program_index;
    cpu->edx = g_sfera_mbc_runtime->current_instruction_address;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    cpu->edx -= g_sfera_mbc_runtime->bytecode_base;
    cpu->eax += g_sfera_mbc_runtime->program_table_base;
    cpu->edx += 0x20u;
    cpu->ecx = lift_load8(cpu->eax + 0x84u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->process_index;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->edx += ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].name[0]);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"MBC-file: %s\nProgram: %s\nCall's depth: %d\nAddress: 0x%08X\n"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x434E1Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x434E22u);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    cpu->esp += 0x18u;
    cpu->ecx = cpu->eax;
    label_00034E30: cpu->eip = LIFT_CODE_TOKEN_VA(0x434E30u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00034E30;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00034E43: cpu->eip = LIFT_CODE_TOKEN_VA(0x434E43u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00034E43;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x434E63u); lift_push32(cpu, r); sfera_sub_00434900(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434E80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x434E80u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = 1u;
    cpu->edi = cpu->edx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x434E90u); lift_push32(cpu, r); sfera_sub_00434AF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) != 0u) goto label_00034EB9;
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->esi);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x434EB4u); lift_push32(cpu, r); sfera_sub_0049B7F0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x18u;
    goto label_00034EE0;
    label_00034EB9: cpu->eip = LIFT_CODE_TOKEN_VA(0x434EB9u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->esi + 4u);
    ++cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->edi);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, ptr+offset = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x434EDDu); lift_push32(cpu, r); sfera_sub_0049B7F0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x1Cu;
    label_00034EE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x434EE0u);
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00034F0C;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00034F0C;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00034EF8;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_00034F0C;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_00034EF8: cpu->eip = LIFT_CODE_TOKEN_VA(0x434EF8u);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_00034F00;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00034F00: cpu->eip = LIFT_CODE_TOKEN_VA(0x434F00u);
    cpu->eax = (uint32_t)(cpu->eax + cpu->edi + 0xFFFFFFFFu);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(lift_load32(cpu->esi + 8u))) goto label_00034F0C;
    lift_store32(cpu->esi + 8u, cpu->eax);
    label_00034F0C: cpu->eip = LIFT_CODE_TOKEN_VA(0x434F0Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434F10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x434F10u);
    cpu->eax = cpu->ecx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = g_sfera_mbc_runtime->active_process;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = g_sfera_mbc_runtime->program_table_base;
    cpu->edx = lift_load8(cpu->eax + cpu->edi + 0x2Du);
    cpu->esi = (int16_t)(lift_load16(cpu->ebx + ((uint32_t)(cpu->edx) * 2u) + 0x7Cu));
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00034F55;
    lift_store16(cpu->ebx + ((uint32_t)(cpu->edx) * 2u) + 0x7Cu, cpu->ecx & 0xFFFFu);
    cpu->esi = g_sfera_mbc_runtime->active_process;
    lift_store16(cpu->esi + ((uint32_t)(cpu->edx) * 2u) + 0x74u, cpu->ecx & 0xFFFFu);
    cpu->edx = g_sfera_mbc_runtime->program_table_base;
    lift_store16(cpu->eax + cpu->edx + 0x9Cu, cpu->ecx & 0xFFFFu);
    goto label_00034F7E;
    label_00034F55: cpu->eip = LIFT_CODE_TOKEN_VA(0x434F55u);
    cpu->ebx = cpu->esi;
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0xA4u);
    lift_store16(cpu->ebx + cpu->edi + 0x9Eu, cpu->ecx & 0xFFFFu);
    cpu->edi = g_sfera_mbc_runtime->program_table_base;
    lift_store16(cpu->eax + cpu->edi + 0x9Cu, cpu->esi & 0xFFFFu);
    cpu->esi = g_sfera_mbc_runtime->active_process;
    lift_store16(cpu->esi + ((uint32_t)(cpu->edx) * 2u) + 0x7Cu, cpu->ecx & 0xFFFFu);
    label_00034F7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x434F7Eu);
    cpu->edx = g_sfera_mbc_runtime->program_table_base;
    lift_store16(cpu->eax + cpu->edx + 0x9Eu, cpu->ecx & 0xFFFFu);
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->eax + 0xB8u, 1u);
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->ecx = lift_load32(cpu->edx + 0xB4u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    sfera_sub_00433CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00434FB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x434FB0u);
    cpu->eax = cpu->edx;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xA4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ecx + 0x5Cu);
    cpu->edx += cpu->ebx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load8(cpu->edx + 0x2Du);
    lift_push32(cpu, cpu->edi);
    cpu->edi = (int16_t)(lift_load16(cpu->ecx + ((uint32_t)(cpu->esi) * 2u) + 0x7Cu));
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00034FE0;
    lift_store16(cpu->ecx + ((uint32_t)(cpu->esi) * 2u) + 0x7Cu, cpu->eax & 0xFFFFu);
    lift_store16(cpu->ecx + ((uint32_t)(cpu->esi) * 2u) + 0x74u, cpu->eax & 0xFFFFu);
    lift_store16(cpu->edx + 0x9Cu, cpu->eax & 0xFFFFu);
    goto label_00034FFE;
    label_00034FE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x434FE0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->edi;
    cpu->ebp = (int64_t)(int32_t)(cpu->ebp) * (int64_t)(int32_t)(0xA4u);
    lift_store16(cpu->ebx + cpu->ebp + 0x9Eu, cpu->eax & 0xFFFFu);
    lift_store16(cpu->edx + 0x9Cu, cpu->edi & 0xFFFFu);
    lift_store16(cpu->ecx + ((uint32_t)(cpu->esi) * 2u) + 0x7Cu, cpu->eax & 0xFFFFu);
    cpu->ebp = lift_pop32(cpu);
    label_00034FFE: cpu->eip = LIFT_CODE_TOKEN_VA(0x434FFEu);
    cpu->edi = lift_pop32(cpu);
    lift_store16(cpu->edx + 0x9Eu, cpu->eax & 0xFFFFu);
    cpu->esi = lift_pop32(cpu);
    lift_store8(cpu->ecx + 0xB8u, 1u);
    cpu->edx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->ecx + 0xB4u);
    cpu->ebx = lift_pop32(cpu);
    sfera_sub_00433CF0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00435020(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x435020u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = lift_load32(cpu->edi + 0x5Cu);
    cpu->ebx = cpu->edx;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00035034;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00035034: cpu->eip = LIFT_CODE_TOKEN_VA(0x435034u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->edi + 0x58u)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_00035079;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00035040: cpu->eip = LIFT_CODE_TOKEN_VA(0x435040u);
    cpu->ecx = cpu->ebx;
    cpu->eax = cpu->esi;
    label_00035044: cpu->eip = LIFT_CODE_TOKEN_VA(0x435044u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00035064;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_00035060;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00035064;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00035044;
    label_00035060: cpu->eip = LIFT_CODE_TOKEN_VA(0x435060u);
    cpu->eax = 0u;
    goto label_00035069;
    label_00035064: cpu->eip = LIFT_CODE_TOKEN_VA(0x435064u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_00035069: cpu->eip = LIFT_CODE_TOKEN_VA(0x435069u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00035080;
    ++cpu->ebp;
    cpu->esi += 0xA4u;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(lift_load32(cpu->edi + 0x58u))) goto label_00035040;
    label_00035079: cpu->eip = LIFT_CODE_TOKEN_VA(0x435079u);
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00035080: cpu->eip = LIFT_CODE_TOKEN_VA(0x435080u);
    if ((uint8_t)(lift_load8(cpu->esi + 0x2Cu)) == (uint8_t)(1u)) goto label_00035098;
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43508Fu); lift_push32(cpu, r); sfera_sub_00434FB0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    lift_store32(cpu->esi + 0x88u, cpu->eax);
    label_00035098: cpu->eip = LIFT_CODE_TOKEN_VA(0x435098u);
    lift_store8(cpu->esi + 0x2Cu, 1u);
    cpu->ecx = lift_load32(cpu->edi + 0xB4u);
    cpu->edx = cpu->edi;
    lift_store8(cpu->edi + 0xB8u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4350B0u); lift_push32(cpu, r); sfera_sub_00433CF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004350C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4350C0u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edx) < 0) goto label_0003510A;
    if ((int32_t)(uint32_t)(cpu->edx) >= (int32_t)(uint32_t)(lift_load32(cpu->edi + 0x58u))) goto label_0003510A;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->edi + 0x5Cu);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000350D9;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000350D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4350D9u);
    cpu->eax = cpu->edx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    cpu->esi += cpu->eax;
    if ((uint8_t)(lift_load8(cpu->esi + 0x2Cu)) == (uint8_t)(1u)) goto label_000350F7;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4350EEu); lift_push32(cpu, r); sfera_sub_00434FB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x24u);
    lift_store32(cpu->esi + 0x88u, cpu->ecx);
    label_000350F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4350F7u);
    lift_store8(cpu->esi + 0x2Cu, 1u);
    cpu->esi = lift_pop32(cpu);
    lift_store8(cpu->edi + 0xB8u, 1u);
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003510A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43510Au);
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00435110(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x435110u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ebx = g_sfera_mbc_runtime->module_link_stream_size;
    cpu->eax = 0u;
    lift_store32(cpu->esp + 4u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00035228;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(0x7Fu) & 0xFFu);
    lift_push32(cpu, cpu->edi);
    label_00035130: cpu->eip = LIFT_CODE_TOKEN_VA(0x435130u);
    if ((uint8_t)(lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->module_link_stream[0]))) != (uint8_t)((cpu->edx & 0xFFu))) goto label_0003521C;
    cpu->esi = (int8_t)(lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->module_link_stream[1])));
    cpu->edi = lift_load32(cpu->ecx + (uint32_t)offsetof(SferaMbcProcessRecord, module_record_base));
    cpu->esi = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 8u));
    cpu->esi += cpu->esi;
    cpu->esi += cpu->esi;
    cpu->edi += cpu->esi;
    if ((uint8_t)(lift_load8(cpu->edi + 0x20u)) != (uint8_t)(0xFFu)) goto label_000351D1;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->module_link_stream[2]))) & 0xFFu);
    lift_store8(cpu->edi + 0x20u, cpu->ebx & 0xFFu);
    cpu->edi = lift_load16(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->module_link_stream[3]));
    cpu->eax += 5u;
    if ((uint32_t)(cpu->edi) == (uint32_t)(0xFFFFu)) goto label_00035190;
    cpu->ebx = lift_load32(cpu->ecx + (uint32_t)offsetof(SferaMbcProcessRecord, module_record_base));
    cpu->ebx = (uint32_t)(cpu->ebx + cpu->esi + 0x22u);
    cpu->ebp = 0xFFFFu;
    if ((uint16_t)(lift_load16(cpu->ebx)) != (uint16_t)((cpu->ebp & 0xFFFFu))) goto label_00035190;
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->ebp += cpu->edi;
    lift_store16(cpu->ebx, cpu->ebp & 0xFFFFu);
    label_00035190: cpu->eip = LIFT_CODE_TOKEN_VA(0x435190u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->module_link_stream[0]))) & 0xFFu);
    cpu->edi = 0u;
    if ((uint8_t)((cpu->ebx & 0xFFu)) == (uint8_t)((cpu->edx & 0xFFu))) goto label_000351BF;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000351A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4351A0u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(g_sfera_mbc_runtime->module_link_stream_size)) goto label_000351BF;
    cpu->ebp = lift_load32(cpu->ecx + (uint32_t)offsetof(SferaMbcProcessRecord, module_record_base));
    cpu->ebp += cpu->esi;
    ++cpu->eax;
    lift_store8(cpu->edi + cpu->ebp, cpu->ebx & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->module_link_stream[0]))) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != (uint8_t)((cpu->edx & 0xFFu))) goto label_000351A0;
    label_000351BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4351BFu);
    cpu->ebx = lift_load32(cpu->ecx + (uint32_t)offsetof(SferaMbcProcessRecord, module_record_base));
    lift_store32(cpu->ebx + cpu->esi + 0x1Cu, cpu->edi);
    cpu->ebx = g_sfera_mbc_runtime->module_link_stream_size;
    goto label_00035213;
    label_000351D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4351D1u);
    cpu->esi = lift_load16(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->module_link_stream[3]));
    cpu->eax += 5u;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFu)) goto label_000351FE;
    cpu->ebp = 0xFFFFu;
    if ((uint16_t)(lift_load16(cpu->edi + 0x22u)) != (uint16_t)((cpu->ebp & 0xFFFFu))) goto label_000351FE;
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    cpu->ebx += cpu->esi;
    lift_store16(cpu->edi + 0x22u, cpu->ebx & 0xFFFFu);
    cpu->ebx = g_sfera_mbc_runtime->module_link_stream_size;
    label_000351FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4351FEu);
    if ((uint8_t)(lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->module_link_stream[0]))) == (uint8_t)((cpu->edx & 0xFFu))) goto label_0003521B;
    label_00035206: cpu->eip = LIFT_CODE_TOKEN_VA(0x435206u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_00035213;
    ++cpu->eax;
    if ((uint8_t)(lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->module_link_stream[0]))) != (uint8_t)((cpu->edx & 0xFFu))) goto label_00035206;
    label_00035213: cpu->eip = LIFT_CODE_TOKEN_VA(0x435213u);
    if ((uint8_t)(lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->module_link_stream[0]))) != (uint8_t)((cpu->edx & 0xFFu))) goto label_0003521C;
    label_0003521B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43521Bu);
    --cpu->eax;
    label_0003521C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43521Cu);
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ebx)) goto label_00035130;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_00035228: cpu->eip = LIFT_CODE_TOKEN_VA(0x435228u);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00435230(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x435230u);
    cpu->esp -= 0x50u;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    g_sfera_mbc_runtime->text_buffer[0] = (uint8_t)(0u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax)), r=(uint64_t)(0x40u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x24u, cpu->esi);
    cpu->ebx = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00035294;
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 1u)), r=(uint64_t)(0x40u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebx = (uint32_t)(cpu->eax + 1u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->text_buffer[0];
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00035290;
    label_00035264: cpu->eip = LIFT_CODE_TOKEN_VA(0x435264u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebx)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_00035397;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x3Bu)) goto label_0003527D;
    lift_store16(cpu->eax, 0xA0Du);
    cpu->eax += 2u;
    goto label_0003528A;
    label_0003527D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43527Du);
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x27u)) goto label_00035285;
    lift_store8(cpu->ebx, 0x22u);
    label_00035285: cpu->eip = LIFT_CODE_TOKEN_VA(0x435285u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebx)) & 0xFFu);
    lift_store8(cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    label_0003528A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43528Au);
    ++cpu->ebx;
    if ((uint8_t)(lift_load8(cpu->ebx)) != (uint8_t)(0x40u)) goto label_00035264;
    label_00035290: cpu->eip = LIFT_CODE_TOKEN_VA(0x435290u);
    lift_store8(cpu->eax, 0u);
    ++cpu->ebx;
    label_00035294: cpu->eip = LIFT_CODE_TOKEN_VA(0x435294u);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    cpu->eax = cpu->ebx;
    cpu->edx -= cpu->ebx;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000352A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4352A0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000352A0;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    --cpu->eax;
    (void)cpu;
    label_000352B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4352B0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000352B0;
    cpu->edx = 0x63626D2Eu;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_store32(cpu->eax, cpu->edx);
    lift_store8(cpu->eax + 4u, cpu->ecx & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000352D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4352D0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4352FEu); lift_push32(cpu, r); sfera_sub_00489EF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) == 0u) goto label_00035D16;
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(0x10u)) goto label_00035D16;
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_000353AB;
    cpu->eax = g_sfera_network_runtime.shutdown_state;
    ++cpu->eax;
    g_sfera_network_runtime.shutdown_state = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(2u)) goto label_00035338;
    g_sfera_network_runtime.shutdown_state = (uint32_t)(0u);
    label_00035338: cpu->eip = LIFT_CODE_TOKEN_VA(0x435338u);
    cpu->eax = g_sfera_mbc_runtime->process_search_cursor;
    cpu->esi = cpu->eax;
    cpu->edx = cpu->esi;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003537C;
    label_00035354: cpu->eip = LIFT_CODE_TOKEN_VA(0x435354u);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0x10000u)) goto label_0003535F;
    cpu->esi = 0u;
    label_0003535F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43535Fu);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_00035D16;
    cpu->ecx = cpu->esi;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x348u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))) >= (int32_t)(uint32_t)(0u)) goto label_00035354;
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    label_0003537C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43537Cu);
    cpu->eax = (uint32_t)(cpu->esi + 1u);
    g_sfera_mbc_runtime->process_search_cursor = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x10000u)) goto label_000353D0;
    g_sfera_mbc_runtime->process_search_cursor = (uint32_t)(0u);
    goto label_000353D0;
    label_00035397: cpu->eip = LIFT_CODE_TOKEN_VA(0x435397u);
    cpu->esi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x50u;
    lift_return(cpu, 0u, stop_address); return;
    label_000353AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4353ABu);
    if ((uint32_t)(cpu->esi) > (uint32_t)(0xFFFFu)) goto label_00035D16;
    cpu->edx = cpu->esi;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00035D16;
    label_000353D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4353D0u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    cpu->esi += ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0]);
    cpu->eax = 0u;
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_key), cpu->eax);
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_key) + 4u, cpu->eax);
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_key) + 8u, cpu->eax);
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_key) + 0xCu, cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x24u)) & 0xFFFFu);
    cpu->edx = cpu->esi;
    lift_store16(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_key), cpu->eax & 0xFFFFu);
    cpu->eax = cpu->ebx;
    cpu->edx -= cpu->ebx;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00035400: cpu->eip = LIFT_CODE_TOKEN_VA(0x435400u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax + 0x10u, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00035400;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(0x10u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebp = v; }
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, flags), 0u);
    lift_store16(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, state_byte_b8), 0u);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000355B6;
    cpu->ebx = (uint32_t)(cpu->ebp + 0x10u);
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00035443;
    label_00035438: cpu->eip = LIFT_CODE_TOKEN_VA(0x435438u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43543Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x435440u);
    cpu->esp += 0xCu;
    label_00035443: cpu->eip = LIFT_CODE_TOKEN_VA(0x435443u);
    cpu->eax = lift_load8(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, header_code_0c));
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load8(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, header_code_0e));
    cpu->edi += cpu->ebx;
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 2u) + 0xFFFFFDF0u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebp = v; }
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000355C0;
    cpu->ebx = (uint32_t)(cpu->ebp + 4u);
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00035483;
    label_00035475: cpu->eip = LIFT_CODE_TOKEN_VA(0x435475u);
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, field_040));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43547Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x435480u);
    cpu->esp += 0xCu;
    label_00035483: cpu->eip = LIFT_CODE_TOKEN_VA(0x435483u);
    cpu->edi += cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebp = v; }
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000355CA;
    cpu->ebx = (uint32_t)(cpu->ebp + 4u);
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_000354AD;
    label_0003549F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43549Fu);
    lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4354A5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4354AAu);
    cpu->esp += 0xCu;
    label_000354AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4354ADu);
    cpu->eax = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag));
    cpu->edi += cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000354C0;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    ++g_sfera_mbc_module_memory_stats[cpu->eax / 3u].process_count;
    label_000354C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4354C0u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebp = v; }
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000355D4;
    cpu->ebx = (uint32_t)(cpu->ebp + 4u);
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_000354E8;
    label_000354DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4354DAu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4354E0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4354E5u);
    cpu->esp += 0xCu;
    label_000354E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4354E8u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size))), r=(uint64_t)(2u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size), v); }
    cpu->edi += cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebp = v; }
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000355DE;
    cpu->ebx = (uint32_t)(cpu->ebp + 4u);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00035518;
    label_0003550A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43550Au);
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_size));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435510u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x435515u);
    cpu->esp += 0xCu;
    label_00035518: cpu->eip = LIFT_CODE_TOKEN_VA(0x435518u);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    cpu->edi += cpu->ebx;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00035530;
    lift_push32(cpu, 0xBADu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x35530u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    label_00035530: cpu->eip = LIFT_CODE_TOKEN_VA(0x435530u);
    cpu->eax = 0u;
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_ids), cpu->eax);
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_ids) + 4u, cpu->eax);
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_ids) + 8u, cpu->eax);
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_ids) + 0xCu, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size));
    cpu->ecx = 1u;
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_begin), cpu->eax);
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_memory_offset), cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag))) & 0xFFFFu);
    lift_store16(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count), cpu->ecx & 0xFFFFu);
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_size), cpu->edx);
    lift_store16(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_ids), cpu->eax & 0xFFFFu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag))), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00035585;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.mbc_service_object[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x35585u); lift_push32(cpu, r); sfera_sub_004225F0(cpu,r); if (cpu->eip != r) return; }
    label_00035585: cpu->eip = LIFT_CODE_TOKEN_VA(0x435585u);
    cpu->edx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_size));
    cpu->ecx = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_key));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x435590u); lift_push32(cpu, r); sfera_sub_00433C80(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000355E8;
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base), cpu->eax);
    cpu->eax = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size));
    cpu->eax -= 2u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000355AF;
    cpu->eax += lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x10u, 0u);
    label_000355AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4355AFu);
    cpu->edi += cpu->eax;
    goto label_0003564B;
    label_000355B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4355B6u);
    cpu->ebx = 0x10u;
    goto label_00035438;
    label_000355C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4355C0u);
    cpu->ebx = 4u;
    goto label_00035475;
    label_000355CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4355CAu);
    cpu->ebx = 4u;
    goto label_0003549F;
    label_000355D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4355D4u);
    cpu->ebx = 4u;
    goto label_000354DA;
    label_000355DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4355DEu);
    cpu->ebx = 4u;
    goto label_0003550A;
    label_000355E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4355E8u);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size));
    lift_push32(cpu, 0xBC3u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4355FAu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size));
    cpu->ecx -= 2u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base), cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0003561A;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = (uint32_t)(cpu->ecx + cpu->edx);
    lift_store32(cpu->esp + 0x10u, 0u);
    goto label_0003561C;
    label_0003561A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43561Au);
    cpu->ebx = cpu->ecx;
    label_0003561C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43561Cu);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_0003562B;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435623u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x435628u);
    cpu->esp += 0xCu;
    label_0003562B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43562Bu);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base));
    cpu->eax = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size));
    cpu->eax = (uint32_t)(cpu->eax + cpu->ecx + 0xFFFFFFFEu);
    lift_store16(cpu->eax, 0x23C9u);
    cpu->edx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_size));
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base));
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_key));
    cpu->edi += cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3564Bu); lift_push32(cpu, r); sfera_sub_00433C00(cpu,r); if (cpu->eip != r) return; }
    label_0003564B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43564Bu);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_size));
    lift_push32(cpu, 0xBD5u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43565Du); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag));
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base), cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_00035674;
    cpu->edx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_size));
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    g_sfera_mbc_module_memory_stats[cpu->ecx / 3u].process_memory_bytes += cpu->edx;
    label_00035674: cpu->eip = LIFT_CODE_TOKEN_VA(0x435674u);
    cpu->ebx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_size));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035689;
    cpu->ebx += lift_load32(cpu->esp + 0x10u);
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    goto label_0003568B;
    label_00035689: cpu->eip = LIFT_CODE_TOKEN_VA(0x435689u);
    cpu->ebp = 0u;
    label_0003568B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43568Bu);
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0003569A;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435692u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x435697u);
    cpu->esp += 0xCu;
    label_0003569A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43569Au);
    cpu->edi += cpu->ebx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035B23;
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    cpu->ebx += 4u;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_000356C4;
    label_000356B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4356B6u);
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_count));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4356BCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4356C1u);
    cpu->esp += 0xCu;
    label_000356C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4356C4u);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->edi += cpu->ebx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_000356DC;
    lift_push32(cpu, 0xBDDu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x356DCu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    label_000356DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4356DCu);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_count));
    ++cpu->ecx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xA4u);
    lift_push32(cpu, 0xBE2u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4356F5u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base), cpu->eax);
    cpu->eax = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_map_a));
    cpu->ecx = 4u;
    label_00035700: cpu->eip = LIFT_CODE_TOKEN_VA(0x435700u);
    cpu->edx |= 0xFFFFFFFFu;
    lift_store16(cpu->eax + 8u, cpu->edx & 0xFFFFu);
    cpu->edx |= cpu->edx;
    lift_store16(cpu->eax, cpu->edx & 0xFFFFu);
    cpu->eax += 2u;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00035700;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_count))), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_000358D0;
    cpu->ebp = 0u;
    label_00035721: cpu->eip = LIFT_CODE_TOKEN_VA(0x435721u);
    lift_store32(cpu->esp + 0x18u, 0u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00035730: cpu->eip = LIFT_CODE_TOKEN_VA(0x435730u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x10u, v); }
    lift_store8(cpu->esp + 0x17u, cpu->eax & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035B2D;
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    ++cpu->ebx;
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00035764;
    label_00035751: cpu->eip = LIFT_CODE_TOKEN_VA(0x435751u);
    lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Bu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435758u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43575Du);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x23u)) & 0xFFu);
    cpu->esp += 0xCu;
    label_00035764: cpu->eip = LIFT_CODE_TOKEN_VA(0x435764u);
    cpu->edx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx += cpu->ebp;
    lift_store8(cpu->edx + cpu->ecx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    cpu->edi += cpu->ebx;
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00035730;
    cpu->eax = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->ebx = 4u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    cpu->eax = (uint32_t)(cpu->eax + cpu->ebp + 0x24u);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000357A0;
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    cpu->ebx += 4u;
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_000357AB;
    label_000357A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4357A0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4357A3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4357A8u);
    cpu->esp += 0xCu;
    label_000357AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4357ABu);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->edi += cpu->ebx;
    cpu->ebx = 4u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    cpu->eax = (uint32_t)(cpu->ecx + cpu->ebp + 0x28u);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000357D2;
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    cpu->ebx += 4u;
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_000357DD;
    label_000357D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4357D2u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4357D5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4357DAu);
    cpu->esp += 0xCu;
    label_000357DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4357DDu);
    cpu->edx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->edi += cpu->ebx;
    cpu->ebx = 1u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    cpu->eax = (uint32_t)(cpu->edx + cpu->ebp + 0x2Cu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035802;
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    ++cpu->ebx;
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_0003580D;
    label_00035802: cpu->eip = LIFT_CODE_TOKEN_VA(0x435802u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435805u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43580Au);
    cpu->esp += 0xCu;
    label_0003580D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43580Du);
    cpu->eax = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->edi += cpu->ebx;
    cpu->ebx = 1u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    cpu->eax = (uint32_t)(cpu->eax + cpu->ebp + 0x2Du);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035832;
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    ++cpu->ebx;
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_0003583D;
    label_00035832: cpu->eip = LIFT_CODE_TOKEN_VA(0x435832u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435835u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43583Au);
    cpu->esp += 0xCu;
    label_0003583D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43583Du);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->edi += cpu->ebx;
    cpu->ebx = 4u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    cpu->eax = (uint32_t)(cpu->ecx + cpu->ebp + 0x30u);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035864;
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    cpu->ebx += 4u;
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_0003586F;
    label_00035864: cpu->eip = LIFT_CODE_TOKEN_VA(0x435864u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435867u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43586Cu);
    cpu->esp += 0xCu;
    label_0003586F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43586Fu);
    cpu->edx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    lift_store8(cpu->edx + cpu->ebp + 0x84u, 0u);
    cpu->eax = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    lift_store8(cpu->eax + cpu->ebp + 0x94u, 0u);
    cpu->eax = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->edx = lift_load32(cpu->eax + cpu->ebp + 0x24u);
    lift_store32(cpu->eax + cpu->ebp + 0x88u, cpu->edx);
    cpu->eax = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    lift_store32(cpu->eax + cpu->ebp + 0x98u, 0xFFFFFFFFu);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->edi += cpu->ebx;
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->ebp + 0x2Cu)) != (uint8_t)(1u)) goto label_000358B8;
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x358B8u); lift_push32(cpu, r); sfera_sub_00434FB0(cpu,r); if (cpu->eip != r) return; }
    label_000358B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4358B8u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    ++cpu->eax;
    cpu->ebp += 0xA4u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_count))), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00035721;
    label_000358D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4358D0u);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->eax = cpu->edx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    lift_store32(cpu->eax + cpu->ecx, 0x465023u);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size));
    cpu->ebx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->ecx -= 2u;
    lift_store32(cpu->ebx + cpu->eax + 0x24u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->ebx = lift_load32(cpu->ecx + cpu->eax + 0x24u);
    ++cpu->ebx;
    lift_store32(cpu->ecx + cpu->eax + 0x28u, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    lift_store8(cpu->ecx + cpu->eax + 0x2Cu, 0u);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    lift_store8(cpu->ecx + cpu->eax + 0x2Du, 0u);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->ebp = 0u;
    lift_store32(cpu->ecx + cpu->eax + 0x30u, cpu->ebp);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    lift_store8(cpu->ecx + cpu->eax + 0x84u, 0u);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->ebx = lift_load32(cpu->ecx + cpu->eax + 0x24u);
    lift_store32(cpu->ecx + cpu->eax + 0x88u, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    lift_store32(cpu->ecx + cpu->eax + 0x98u, 0xFFFFFFFFu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_count))), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_count), v); }
    cpu->ebx = 4u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, field_0bc), cpu->ebp);
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, field_0c0), cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035968;
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    cpu->ebx += 4u;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_00035978;
    label_00035968: cpu->eip = LIFT_CODE_TOKEN_VA(0x435968u);
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_count));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43596Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x435973u);
    cpu->esp += 0xCu;
    cpu->ebp = 0u;
    label_00035978: cpu->eip = LIFT_CODE_TOKEN_VA(0x435978u);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    cpu->edi += cpu->ebx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_00035992;
    lift_push32(cpu, 0xC17u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x435990u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = 0u;
    label_00035992: cpu->eip = LIFT_CODE_TOKEN_VA(0x435992u);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_count));
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table), cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->ecx) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_000359B3;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x34u);
    lift_push32(cpu, 0xC1Eu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4359AEu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table), cpu->eax);
    cpu->ebp = 0u;
    label_000359B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4359B3u);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_count))), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00035AD1;
    lift_store32(cpu->esp + 0x18u, 0u);
    label_000359D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4359D0u);
    cpu->ebx = 0u;
    label_000359D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4359D2u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebp = 1u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    lift_store8(cpu->esp + 0x17u, cpu->eax & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000359F4;
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    ++cpu->ebp;
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00035A07;
    label_000359F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4359F4u);
    lift_push32(cpu, cpu->ebp);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Bu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4359FBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x435A00u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x23u)) & 0xFFu);
    cpu->esp += 0xCu;
    label_00035A07: cpu->eip = LIFT_CODE_TOKEN_VA(0x435A07u);
    cpu->edx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx += cpu->ecx;
    lift_store8(cpu->edx + cpu->ebx, cpu->eax & 0xFFu);
    cpu->edi += cpu->ebp;
    ++cpu->ebx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000359D2;
    cpu->eax = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    cpu->ebx = 4u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    cpu->eax = (uint32_t)(cpu->ecx + cpu->eax + 0x24u);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035B37;
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->ebp += 4u;
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00035A4E;
    label_00035A43: cpu->eip = LIFT_CODE_TOKEN_VA(0x435A43u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435A46u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x435A4Bu);
    cpu->esp += 0xCu;
    label_00035A4E: cpu->eip = LIFT_CODE_TOKEN_VA(0x435A4Eu);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->edi += cpu->ebp;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    cpu->eax = (uint32_t)(cpu->edx + cpu->ecx + 0x28u);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035B3E;
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->ebp += 4u;
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00035A83;
    label_00035A78: cpu->eip = LIFT_CODE_TOKEN_VA(0x435A78u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435A7Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x435A80u);
    cpu->esp += 0xCu;
    label_00035A83: cpu->eip = LIFT_CODE_TOKEN_VA(0x435A83u);
    cpu->eax = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edi += cpu->ebp;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    cpu->eax = (uint32_t)(cpu->ecx + cpu->eax + 0x2Cu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035B45;
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->ebp += 4u;
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00035AB8;
    label_00035AAD: cpu->eip = LIFT_CODE_TOKEN_VA(0x435AADu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435AB0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x435AB5u);
    cpu->esp += 0xCu;
    label_00035AB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x435AB8u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x18u, (uint64_t)(lift_load32(cpu->esp + 0x18u)) + (uint64_t)(0x34u) + (uint64_t)(0u));
    ++cpu->eax;
    cpu->edi += cpu->ebp;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_count))), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000359D0;
    label_00035AD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x435AD1u);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, workspace_base));
    cpu->ebp = 0u;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_00035AEC;
    lift_push32(cpu, 0xC36u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x35AECu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    label_00035AEC: cpu->eip = LIFT_CODE_TOKEN_VA(0x435AECu);
    cpu->ebx = 0xA0u;
    lift_push32(cpu, 0xC37u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x435B02u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x28u)), r=(uint64_t)(0x16u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, workspace_base), cpu->eax);
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00035B4C;
    cpu->ebx = 0x3Cu;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035B64;
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    cpu->ebx += 0x3Cu;
    goto label_00035B5C;
    label_00035B23: cpu->eip = LIFT_CODE_TOKEN_VA(0x435B23u);
    cpu->ebx = 4u;
    goto label_000356B6;
    label_00035B2D: cpu->eip = LIFT_CODE_TOKEN_VA(0x435B2Du);
    cpu->ebx = 1u;
    goto label_00035751;
    label_00035B37: cpu->eip = LIFT_CODE_TOKEN_VA(0x435B37u);
    cpu->ebp = cpu->ebx;
    goto label_00035A43;
    label_00035B3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x435B3Eu);
    cpu->ebp = cpu->ebx;
    goto label_00035A78;
    label_00035B45: cpu->eip = LIFT_CODE_TOKEN_VA(0x435B45u);
    cpu->ebp = cpu->ebx;
    goto label_00035AAD;
    label_00035B4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x435B4Cu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035B64;
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    cpu->ebx += 0xA0u;
    label_00035B5C: cpu->eip = LIFT_CODE_TOKEN_VA(0x435B5Cu);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_00035B6F;
    label_00035B64: cpu->eip = LIFT_CODE_TOKEN_VA(0x435B64u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435B67u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x435B6Cu);
    cpu->esp += 0xCu;
    label_00035B6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x435B6Fu);
    cpu->edi += cpu->ebx;
    cpu->ebx = 4u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035B8B;
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    cpu->ebx += 4u;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_00035B9A;
    label_00035B8B: cpu->eip = LIFT_CODE_TOKEN_VA(0x435B8Bu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->module_link_stream_size);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435B92u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x435B97u);
    cpu->esp += 0xCu;
    label_00035B9A: cpu->eip = LIFT_CODE_TOKEN_VA(0x435B9Au);
    cpu->eax = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x8D8u);
    lift_push32(cpu, 0x8B8u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0].runtime[0]));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    cpu->edi += cpu->ebx;
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_record_base), cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x435BB9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x435BBEu);
    cpu->ebx = g_sfera_mbc_runtime->module_link_stream_size;
    cpu->esp += 0xCu;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035BD5;
    cpu->ebx += lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    label_00035BD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x435BD5u);
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_00035BE8;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->module_link_stream[0]);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435BE0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x435BE5u);
    cpu->esp += 0xCu;
    label_00035BE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x435BE8u);
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    cpu->edi += cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x435BF3u); lift_push32(cpu, r); sfera_sub_00435110(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebx = v; }
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035CC6;
    cpu->ebp = (uint32_t)(cpu->ebx + 4u);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00035C22;
    label_00035C11: cpu->eip = LIFT_CODE_TOKEN_VA(0x435C11u);
    lift_push32(cpu, cpu->ebp);
    cpu->eax = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, field_084));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435C1Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x435C1Fu);
    cpu->esp += 0xCu;
    label_00035C22: cpu->eip = LIFT_CODE_TOKEN_VA(0x435C22u);
    cpu->edi += cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebx = v; }
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, field_090), 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035CD0;
    cpu->ebp = (uint32_t)(cpu->ebx + 4u);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00035C59;
    label_00035C48: cpu->eip = LIFT_CODE_TOKEN_VA(0x435C48u);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, field_088));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435C51u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x435C56u);
    cpu->esp += 0xCu;
    label_00035C59: cpu->eip = LIFT_CODE_TOKEN_VA(0x435C59u);
    cpu->edi += cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebx = v; }
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00035CDA;
    cpu->ebx += 4u;
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00035C84;
    label_00035C73: cpu->eip = LIFT_CODE_TOKEN_VA(0x435C73u);
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, field_08c));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x435C7Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x435C81u);
    cpu->esp += 0xCu;
    label_00035C84: cpu->eip = LIFT_CODE_TOKEN_VA(0x435C84u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->eax = 0u;
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, field_09a), cpu->eax);
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entry_count), cpu->eax);
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_capacity), cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->process_chain_last;
    cpu->edx = cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    lift_store32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_next_index), cpu->ecx);
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, chain_prev_index), cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, chain_next_index), cpu->ecx);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_00035CE1;
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_id), cpu->ecx);
    goto label_00035CE7;
    label_00035CC6: cpu->eip = LIFT_CODE_TOKEN_VA(0x435CC6u);
    cpu->ebp = 4u;
    goto label_00035C11;
    label_00035CD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x435CD0u);
    cpu->ebp = 4u;
    goto label_00035C48;
    label_00035CDA: cpu->eip = LIFT_CODE_TOKEN_VA(0x435CDAu);
    cpu->ebx = 4u;
    goto label_00035C73;
    label_00035CE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x435CE1u);
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_id), cpu->eax);
    label_00035CE7: cpu->eip = LIFT_CODE_TOKEN_VA(0x435CE7u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, state_byte_b8))), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    g_sfera_mbc_runtime->process_chain_last = (uint32_t)(cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00035CFD;
    cpu->edx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x35CFDu); lift_push32(cpu, r); sfera_sub_00433CF0(cpu,r); if (cpu->eip != r) return; }
    label_00035CFD: cpu->eip = LIFT_CODE_TOKEN_VA(0x435CFDu);
    cpu->eax = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_id));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x50u;
    lift_return(cpu, 0u, stop_address); return;
    label_00035D16: cpu->eip = LIFT_CODE_TOKEN_VA(0x435D16u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0x50u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00435D40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x435D40u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00035D57;
    cpu->ecx = (uint32_t)(uintptr_t)"prc_unload _main.mbl\n";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x435D55u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    goto label_00035D69;
    label_00035D57: cpu->eip = LIFT_CODE_TOKEN_VA(0x435D57u);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00036092;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(0x10000u)) goto label_00036092;
    label_00035D69: cpu->eip = LIFT_CODE_TOKEN_VA(0x435D69u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edi;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    cpu->esi += ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0]);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.mbc_service_object[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x435D83u); lift_push32(cpu, r); sfera_sub_00422270(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag))), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.mbc_service_object[0];
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00035D95;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x435D93u); lift_push32(cpu, r); sfera_sub_00422620(cpu,r); if (cpu->eip != r) return; }
    goto label_00035D9B;
    label_00035D95: cpu->eip = LIFT_CODE_TOKEN_VA(0x435D95u);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x35D9Bu); lift_push32(cpu, r); sfera_sub_00422630(cpu,r); if (cpu->eip != r) return; }
    label_00035D9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x435D9Bu);
    cpu->eax = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag));
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_00035DAC;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    --g_sfera_mbc_module_memory_stats[cpu->eax / 3u].process_count;
    label_00035DAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x435DACu);
    cpu->eax = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, chain_prev_index));
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ebx)) goto label_0003608A;
    if ((uint32_t)(cpu->edi) != (uint32_t)(g_sfera_mbc_runtime->process_chain_last)) goto label_00035DD4;
    cpu->ecx = cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x348u);
    g_sfera_mbc_runtime->process_chain_last = (uint32_t)(cpu->eax);
    lift_store32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_next_index), cpu->eax);
    goto label_00035E15;
    label_00035DD4: cpu->eip = LIFT_CODE_TOKEN_VA(0x435DD4u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(g_sfera_mbc_runtime->process_chain_first)) goto label_00035DF4;
    cpu->eax = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, chain_next_index));
    cpu->edx = cpu->eax;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    g_sfera_mbc_runtime->process_chain_first = (uint32_t)(cpu->eax);
    lift_store32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index), cpu->eax);
    goto label_00035E15;
    label_00035DF4: cpu->eip = LIFT_CODE_TOKEN_VA(0x435DF4u);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, chain_next_index));
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x348u);
    lift_store32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index), cpu->eax);
    cpu->edx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, chain_prev_index));
    cpu->eax = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, chain_next_index));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    lift_store32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_next_index), cpu->eax);
    label_00035E15: cpu->eip = LIFT_CODE_TOKEN_VA(0x435E15u);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x435E1Eu); lift_push32(cpu, r); sfera_sub_00433DA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, flags))), r=(uint64_t)(4u), v=l | r; lift_flags_logic(cpu,v,32u); lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, flags), v); }
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, chain_prev_index), 0xFFFFFFFFu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00035E45;
    lift_push32(cpu, 0xE0Fu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x435E42u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base), cpu->ebx);
    label_00035E45: cpu->eip = LIFT_CODE_TOKEN_VA(0x435E45u);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00035E5E;
    lift_push32(cpu, 0xE11u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x435E5Bu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table), cpu->ebx);
    label_00035E5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x435E5Eu);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, workspace_base));
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00035E7D;
    lift_push32(cpu, 0xE15u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x435E77u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, workspace_base), cpu->ebx);
    label_00035E7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x435E7Du);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, owned_block_b));
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00035E9C;
    lift_push32(cpu, 0xE1Au);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x435E96u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, owned_block_b), cpu->ebx);
    label_00035E9C: cpu->eip = LIFT_CODE_TOKEN_VA(0x435E9Cu);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, owned_block_a));
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00035EBB;
    lift_push32(cpu, 0xE26u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x435EB5u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, owned_block_a), cpu->ebx);
    label_00035EBB: cpu->eip = LIFT_CODE_TOKEN_VA(0x435EBBu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, execution_scratch));
    lift_store32(cpu->esp + 0x10u, 0x3Fu);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00035ED0: cpu->eip = LIFT_CODE_TOKEN_VA(0x435ED0u);
    cpu->edi = lift_load32(cpu->ebp);
    lift_store32(cpu->ebp + 0xFFFFFF04u, 0xFFFFFFFFu);
    lift_store32(cpu->ebp, cpu->ebx);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebx)) goto label_00035F0F;
    label_00035EE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x435EE4u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->ebx = lift_load32(cpu->edi);
    lift_push32(cpu, 0xE38u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x435EF8u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xE39u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x435F09u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->ebx;
    if ((uint32_t)(cpu->ebx) != 0u) goto label_00035EE4;
    label_00035F0F: cpu->eip = LIFT_CODE_TOKEN_VA(0x435F0Fu);
    cpu->ebp += 4u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00035ED0;
    cpu->edi = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entries));
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, field_0d8), 0xFFFFFFFFu);
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, field_0d4), cpu->ebx);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebx)) goto label_0003605C;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entry_count))), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00035F69;
    cpu->edi = cpu->edi;
    label_00035F40: cpu->eip = LIFT_CODE_TOKEN_VA(0x435F40u);
    cpu->eax = lift_load32(cpu->edi + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(4u)) goto label_00035F51;
    cpu->ecx = lift_load32(cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x435F4Fu); lift_push32(cpu, r); sfera_sub_00457370(cpu,r); if (cpu->eip != r) return; }
    goto label_00035F5D;
    label_00035F51: cpu->eip = LIFT_CODE_TOKEN_VA(0x435F51u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(5u)) goto label_00035F5D;
    cpu->ecx = lift_load32(cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x35F5Du); lift_push32(cpu, r); sfera_sub_00455C20(cpu,r); if (cpu->eip != r) return; }
    label_00035F5D: cpu->eip = LIFT_CODE_TOKEN_VA(0x435F5Du);
    ++cpu->ebx;
    cpu->edi += 8u;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entry_count))), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00035F40;
    label_00035F69: cpu->eip = LIFT_CODE_TOKEN_VA(0x435F69u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entry_count))), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entries));
    lift_store32(cpu->esp + 0x10u, 0u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003603B;
    label_00035F84: cpu->eip = LIFT_CODE_TOKEN_VA(0x435F84u);
    cpu->eax = lift_load32(cpu->ebx + 4u);
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
    cpu->ecx = lift_load32(cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x435F9Eu); lift_push32(cpu, r); sfera_sub_00459150(cpu,r); if (cpu->eip != r) return; }
    goto label_00036023;
    label_00035FA3: cpu->eip = LIFT_CODE_TOKEN_VA(0x435FA3u);
    cpu->ecx = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x435FA6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x435FACu);
    cpu->esp += 4u;
    goto label_00036023;
    label_00035FB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x435FB1u);
    cpu->ecx = lift_load32(cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x435FB8u); lift_push32(cpu, r); sfera_sub_00458E80(cpu,r); if (cpu->eip != r) return; }
    goto label_00036023;
    label_00035FBA: cpu->eip = LIFT_CODE_TOKEN_VA(0x435FBAu);
    cpu->ecx = lift_load32(cpu->ebx);
    cpu->edx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x435FC6u); lift_push32(cpu, r); sfera_sub_004B8700(cpu,r); if (cpu->eip != r) return; }
    goto label_00036023;
    label_00035FC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x435FC8u);
    cpu->ecx = lift_load32(cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x435FCFu); lift_push32(cpu, r); sfera_sub_004D12C0(cpu,r); if (cpu->eip != r) return; }
    goto label_00036023;
    label_00035FD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x435FD1u);
    cpu->edx = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x435FD4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x435FDAu);
    cpu->esp += 4u;
    goto label_00036023;
    label_00035FDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x435FDFu);
    cpu->eax = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    cpu->ecx = lift_load32(cpu->ebx);
    cpu->edi = lift_load32(cpu->ecx + cpu->eax);
    cpu->edi += cpu->eax;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag))), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00036009;
    cpu->eax = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag));
    cpu->edx = (uint32_t)(cpu->edi + 0xFFFFFFFCu);
    lift_push32(cpu, cpu->edx);
    cpu->ebp = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    lift_native_call(cpu, native_function_address32(&::_msize), LIFT_CODE_TOKEN_VA(0x435FF9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x435FFFu);
    cpu->esp += 4u;
    g_sfera_mbc_module_memory_stats[cpu->ebp / 3u].dynamic_memory_bytes -= cpu->eax;
    label_00036009: cpu->eip = LIFT_CODE_TOKEN_VA(0x436009u);
    lift_push32(cpu, 0xE65u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43601Au); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    goto label_00036023;
    label_0003601C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43601Cu);
    cpu->ecx = lift_load32(cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x36023u); lift_push32(cpu, r); sfera_sub_00401F10(cpu,r); if (cpu->eip != r) return; }
    label_00036023: cpu->eip = LIFT_CODE_TOKEN_VA(0x436023u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    ++cpu->eax;
    cpu->ebx += 8u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entry_count))), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00035F84;
    label_0003603B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43603Bu);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entries));
    lift_push32(cpu, 0xE71u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x436050u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entries), 0u);
    cpu->ebx = 0u;
    label_0003605C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43605Cu);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base), cpu->ebx);
    cpu->ebp = lift_pop32(cpu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00036079;
    lift_push32(cpu, 0xE8Cu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x436076u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base), cpu->ebx);
    label_00036079: cpu->eip = LIFT_CODE_TOKEN_VA(0x436079u);
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_id), 0xFFFFFFFFu);
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003608A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43608Au);
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00036092: cpu->eip = LIFT_CODE_TOKEN_VA(0x436092u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004360D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4360D0u);
    cpu->esp -= 8u;
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esp + 4u, cpu->eax);
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x3D0900u)) goto label_000361CD;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->active_process;
    cpu->ebx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_size));
    cpu->ecx = cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x80000003u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00036100;
    --cpu->ecx;
    cpu->ecx |= 0xFFFFFFFCu;
    ++cpu->ecx;
    label_00036100: cpu->eip = LIFT_CODE_TOKEN_VA(0x436100u);
    cpu->edx = 4u;
    cpu->edx -= cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x80000003u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00036114;
    --cpu->edx;
    cpu->edx |= 0xFFFFFFFCu;
    ++cpu->edx;
    label_00036114: cpu->eip = LIFT_CODE_TOKEN_VA(0x436114u);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    cpu->ebx += cpu->edx;
    lift_push32(cpu, 0xEB4u);
    cpu->edx = (uint32_t)(cpu->ebx + cpu->eax);
    lift_push32(cpu, (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp");
    cpu->ebp = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43612Du); lift_push32(cpu, r); sfera_sub_004EBE80(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entries));
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base), cpu->eax);
    if ((uint32_t)(cpu->edi) == 0u) goto label_0003618E;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entry_count))), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x10u, 0u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0003618E;
    label_00036150: cpu->eip = LIFT_CODE_TOKEN_VA(0x436150u);
    if ((uint32_t)(lift_load32(cpu->edi + 4u)) != (uint32_t)(3u)) goto label_0003617A;
    cpu->edx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    cpu->eax = lift_load32(cpu->edi);
    cpu->ecx = cpu->ebp;
    cpu->eax += cpu->edx;
    cpu->ecx -= cpu->edx;
    cpu->edx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0003617A;
    cpu->edx += cpu->ecx;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0003617A;
    cpu->edx += cpu->ecx;
    lift_store32(cpu->eax + 8u, (uint64_t)(lift_load32(cpu->eax + 8u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    lift_store32(cpu->eax + 4u, cpu->edx);
    label_0003617A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43617Au);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    ++cpu->eax;
    cpu->edi += 8u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entry_count))), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00036150;
    label_0003618E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43618Eu);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    lift_push32(cpu, cpu->edi);
    cpu->eax += cpu->ebx;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x43619Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4361A0u);
    cpu->eax = (uint32_t)(cpu->ebx + cpu->edi);
    lift_store32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_size), cpu->eax);
    cpu->eax = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag));
    cpu->esp += 0xCu;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000361BA;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    g_sfera_mbc_module_memory_stats[cpu->eax / 3u].process_memory_bytes += cpu->edi;
    label_000361BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4361BAu);
    cpu->ecx = lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    g_sfera_mbc_runtime->process_memory_base = (uint32_t)(cpu->ecx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
    label_000361CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4361CDu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004361E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4361E0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u); lift_push32(cpu, 0x8000u); lift_push32(cpu, cpu->ecx);
    g_sfera_mbc_runtime->file_crc32 = (uint32_t)(0u);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x4361F4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4361FAu);
    cpu->edi = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->edi) != (uint32_t)(0xFFFFFFFFu)) goto label_00036209;
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00036209: cpu->eip = LIFT_CODE_TOKEN_VA(0x436209u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_filelength), LIFT_CODE_TOKEN_VA(0x43620Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x436213u);
    cpu->ecx = cpu->eax;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 0xFFFFu;
    cpu->esi = (uint32_t)(cpu->edx + cpu->eax);
    cpu->ebx = cpu->ecx;
    { uint64_t l=cpu->esp, r=(uint64_t)(4u), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(0x10u), 32u);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(0x8000FFFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00036237;
    --cpu->ebx;
    cpu->ebx |= 0xFFFF0000u;
    ++cpu->ebx;
    label_00036237: cpu->eip = LIFT_CODE_TOKEN_VA(0x436237u);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_0003629B;
    label_00036243: cpu->eip = LIFT_CODE_TOKEN_VA(0x436243u);
    lift_push32(cpu, 0x10000u); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->file_io_buffer[0]); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x43624Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x436254u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000362B4;
    cpu->eax = g_sfera_mbc_runtime->file_crc32;
    cpu->ecx = 0x10000u;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_io_buffer[0];
    label_00036270: cpu->eip = LIFT_CODE_TOKEN_VA(0x436270u);
    cpu->ebp = (int8_t)(lift_load8(cpu->edx));
    cpu->ebp ^= cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax ^= lift_load32(((uint32_t)(cpu->ebp) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_crc32_table[0]));
    ++cpu->edx;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00036270;
    g_sfera_mbc_runtime->file_crc32 = (uint32_t)(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->esi)) goto label_00036243;
    label_0003629B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43629Bu);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000362C8;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->file_io_buffer[0]); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x4362A6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4362ACu);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000362BC;
    label_000362B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4362B4u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000362BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4362BCu);
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_io_buffer[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x362C8u); lift_push32(cpu, r); sfera_sub_004348D0(cpu,r); if (cpu->eip != r) return; }
    label_000362C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4362C8u);
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x4362C9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4362CFu);
    cpu->eax = g_sfera_mbc_runtime->file_crc32;
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004362E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4362E0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->file_find_data); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->file_search_pattern[0]);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_findfirst64i32), LIFT_CODE_TOKEN_VA(0x4362F5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4362FBu);
    cpu->edi = cpu->eax;
    cpu->esp += 8u;
    lift_store32(cpu->esp + 0xCu, cpu->edi);
    if ((uint32_t)(cpu->edi) == (uint32_t)(0xFFFFFFFFu)) goto label_000364F8;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::strncpy);
    cpu->ebx = 0u;
    goto label_00036324;
    label_00036320: cpu->eip = LIFT_CODE_TOKEN_VA(0x436320u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    label_00036324: cpu->eip = LIFT_CODE_TOKEN_VA(0x436324u);
    if ((uint8_t)((g_sfera_mbc_runtime->file_find_data.attrib) & (0x10u)) != 0u) goto label_000364DB;
    lift_push32(cpu, (uintptr_t)"filelist.dat"); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->file_find_data.name[0]);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x43633Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x436341u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000364DB;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_path_buffer[0];
    cpu->eax = cpu->esi;
    cpu->edx -= cpu->esi;
    label_00036355: cpu->eip = LIFT_CODE_TOKEN_VA(0x436355u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00036355;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_find_data.name[0];
    cpu->esi = cpu->eax;
    label_00036366: cpu->eip = LIFT_CODE_TOKEN_VA(0x436366u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00036366;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_path_buffer[0];
    cpu->eax -= cpu->esi;
    --cpu->edi;
    label_00036375: cpu->eip = LIFT_CODE_TOKEN_VA(0x436375u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ebx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00036375;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    lift_push32(cpu, 0xEFBu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = 0x118u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43639Fu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_path_buffer[0];
    g_sfera_mbc_runtime->file_index_current = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4363AEu); lift_push32(cpu, r); sfera_sub_004361E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_mbc_runtime->file_index_current;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_store32(cpu->ecx + (uint32_t)offsetof(SferaMbcFileIndexNode, checksum), cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->file_index_current;
    lift_store32(cpu->eax + ((uint32_t)offsetof(SferaMbcFileIndexNode, checksum) + 4u), cpu->edx);
    cpu->ecx = g_sfera_mbc_runtime->file_index_current;
    cpu->edx = lift_load32((uintptr_t)&g_sfera_mbc_runtime->file_find_data.size);
    lift_store32(cpu->ecx + (uint32_t)offsetof(SferaMbcFileIndexNode, file_size), cpu->edx);
    cpu->eax = g_sfera_mbc_runtime->file_index_current;
    lift_push32(cpu, 0x40u);
    cpu->eax += 8u;
    lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->file_find_data.name[0]); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x363EAu), LIFT_CODE_TOKEN_RVA(0x363E8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4363EAu);
    cpu->ecx = g_sfera_mbc_runtime->file_index_current;
    lift_store32(cpu->ecx + 4u, cpu->ebx);
    cpu->edx = g_sfera_mbc_runtime->file_index_current;
    lift_store32(cpu->edx, cpu->ebx);
    cpu->eax = g_sfera_mbc_runtime->file_index_head;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_00036416;
    cpu->eax = g_sfera_mbc_runtime->file_index_current;
    g_sfera_mbc_runtime->file_index_head = (uint32_t)(cpu->eax);
    goto label_000364DB;
    label_00036416: cpu->eip = LIFT_CODE_TOKEN_VA(0x436416u);
    g_sfera_mbc_runtime->file_index_scan_prev = (uint32_t)(cpu->ebx);
    g_sfera_mbc_runtime->file_index_scan = (uint32_t)(cpu->eax);
    label_00036421: cpu->eip = LIFT_CODE_TOKEN_VA(0x436421u);
    cpu->ecx = g_sfera_mbc_runtime->file_index_current;
    cpu->ecx += 8u;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += 8u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x43642Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x436435u);
    cpu->esp += 8u;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->eax = g_sfera_mbc_runtime->file_index_scan;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00036453;
    g_sfera_mbc_runtime->file_index_scan_prev = (uint32_t)(cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    g_sfera_mbc_runtime->file_index_scan = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_00036421;
    goto label_000364C0;
    label_00036453: cpu->eip = LIFT_CODE_TOKEN_VA(0x436453u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(g_sfera_mbc_runtime->file_index_head)) goto label_0003647F;
    cpu->edx = g_sfera_mbc_runtime->file_index_current;
    lift_store32(cpu->edx, cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->file_index_current;
    cpu->ecx = g_sfera_mbc_runtime->file_index_scan;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    cpu->edx = g_sfera_mbc_runtime->file_index_current;
    g_sfera_mbc_runtime->file_index_head = (uint32_t)(cpu->edx);
    goto label_000364B8;
    label_0003647F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43647Fu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = g_sfera_mbc_runtime->file_index_current;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = g_sfera_mbc_runtime->file_index_scan;
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->ecx = g_sfera_mbc_runtime->file_index_current;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    cpu->edx = g_sfera_mbc_runtime->file_index_current;
    cpu->eax = g_sfera_mbc_runtime->file_index_scan;
    lift_store32(cpu->edx, cpu->eax);
    cpu->ecx = g_sfera_mbc_runtime->file_index_current;
    cpu->edx = g_sfera_mbc_runtime->file_index_scan;
    lift_store32(cpu->edx + 4u, cpu->ecx);
    label_000364B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4364B8u);
    if ((uint32_t)(g_sfera_mbc_runtime->file_index_scan) != (uint32_t)(cpu->ebx)) goto label_000364DB;
    label_000364C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4364C0u);
    cpu->eax = g_sfera_mbc_runtime->file_index_current;
    cpu->ecx = g_sfera_mbc_runtime->file_index_scan_prev;
    lift_store32(cpu->ecx, cpu->eax);
    cpu->edx = g_sfera_mbc_runtime->file_index_current;
    cpu->eax = g_sfera_mbc_runtime->file_index_scan_prev;
    lift_store32(cpu->edx + 4u, cpu->eax);
    label_000364DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4364DBu);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->file_find_data); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_findnext64i32), LIFT_CODE_TOKEN_VA(0x4364E5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4364EBu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00036320;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000364F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4364F8u);
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x4364F9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4364FFu);
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x436510u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->ecx;
    cpu->ebx = 0u;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_search_pattern[0];
    lift_push32(cpu, cpu->edi);
    g_sfera_mbc_runtime->file_index_head = (uint32_t)(cpu->ebx);
    cpu->eax = cpu->ebp;
    cpu->esi -= cpu->ebp;
    label_00036528: cpu->eip = LIFT_CODE_TOKEN_VA(0x436528u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->esi + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00036528;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_search_pattern[0];
    --cpu->eax;
    label_00036538: cpu->eip = LIFT_CODE_TOKEN_VA(0x436538u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00036538;
    cpu->ecx = 0x656C6966u;
    cpu->edx = 0x7473696Cu;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = 0x7461642Eu;
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x8000u);
    lift_store32(cpu->eax + (uint32_t)offsetof(SferaMbcFileIndexNode, name), cpu->ecx);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_search_pattern[0]);
    lift_store8(cpu->eax + 0xCu, cpu->edx & 0xFFu);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x43656Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x436574u);
    cpu->edi = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->edi) == (uint32_t)(0xFFFFFFFFu)) goto label_00036590;
    if ((uint32_t)(g_sfera_inter_scalar_runtime.state_06) == (uint32_t)(cpu->ebx)) goto label_000365CD;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x436587u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43658Du);
    cpu->esp += 4u;
    label_00036590: cpu->eip = LIFT_CODE_TOKEN_VA(0x436590u);
    lift_push32(cpu, 7u); lift_push32(cpu, (uintptr_t)"xupdate"); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::strncmp), LIFT_CODE_TOKEN_VA(0x436598u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43659Eu);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000365EB;
    cpu->eax = cpu->ebp;
    label_000365A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4365A7u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->esi + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000365A7;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_search_pattern[0];
    --cpu->edi;
    label_000365B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4365B7u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000365B7;
    cpu->eax = lift_load32((uintptr_t)"*.*");
    lift_store32(cpu->edi, cpu->eax);
    cpu->ecx = cpu->ebp;
    goto label_00036691;
    label_000365CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4365CDu);
    lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->file_crc32); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x4365D5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4365DBu);
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x4365DCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4365E2u);
    cpu->esp += 0x10u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000365EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4365EBu);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_search_pattern[0];
    g_sfera_mbc_runtime->file_search_pattern[0] = (uint8_t)((cpu->ebx & 0xFFu));
    --cpu->eax;
    label_000365F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4365F7u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000365F7;
    cpu->ecx = lift_load32((uintptr_t)"sphere*.exe");
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"sphere*.exe") + 4u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"sphere*.exe") + 8u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + (uint32_t)offsetof(SferaMbcFileIndexNode, name), cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)"";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x436623u); lift_push32(cpu, r); sfera_sub_004362E0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_search_pattern[0];
    g_sfera_mbc_runtime->file_search_pattern[0] = (uint8_t)((cpu->ebx & 0xFFu));
    --cpu->eax;
    (void)cpu;
    label_00036630: cpu->eip = LIFT_CODE_TOKEN_VA(0x436630u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00036630;
    cpu->edx = lift_load32((uintptr_t)"xlaunch*.exe");
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"xlaunch*.exe") + 4u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"xlaunch*.exe") + 8u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"xlaunch*.exe") + 0xCu)) & 0xFFu);
    lift_store32(cpu->eax + (uint32_t)offsetof(SferaMbcFileIndexNode, name), cpu->edx);
    lift_store8(cpu->eax + 0xCu, cpu->ecx & 0xFFu);
    cpu->ecx = (uint32_t)(uintptr_t)"";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x436665u); lift_push32(cpu, r); sfera_sub_004362E0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_search_pattern[0];
    g_sfera_mbc_runtime->file_search_pattern[0] = (uint8_t)((cpu->ebx & 0xFFu));
    --cpu->eax;
    label_00036671: cpu->eip = LIFT_CODE_TOKEN_VA(0x436671u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00036671;
    cpu->edx = lift_load32((uintptr_t)"*.dll");
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(((uint32_t)(uintptr_t)"*.dll") + 4u)) & 0xFFFFu);
    lift_store32(cpu->eax, cpu->edx);
    lift_store16(cpu->eax + 4u, cpu->ecx & 0xFFFFu);
    cpu->ecx = (uint32_t)(uintptr_t)"";
    label_00036691: cpu->eip = LIFT_CODE_TOKEN_VA(0x436691u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x436696u); lift_push32(cpu, r); sfera_sub_004362E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_path_buffer[0];
    cpu->eax = cpu->ebp;
    cpu->edx -= cpu->ebp;
    (void)cpu;
    label_000366A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4366A0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000366A0;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_path_buffer[0];
    --cpu->eax;
    label_000366B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4366B0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000366B0;
    cpu->edx = 0x656C6966u;
    cpu->ecx = 0x7473696Cu;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = 0x7461642Eu;
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_store32(cpu->eax + (uint32_t)offsetof(SferaMbcFileIndexNode, name), cpu->edx);
    lift_store8(cpu->eax + 0xCu, cpu->ecx & 0xFFu);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_path_buffer[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4366E5u); lift_push32(cpu, r); sfera_sub_0042EE20(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_path_buffer[0];
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4366F5u); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_mbc_runtime->file_index_head;
    g_sfera_mbc_runtime->file_crc32 = (uint32_t)(cpu->ebx);
    g_sfera_mbc_runtime->file_index_scan_prev = (uint32_t)(cpu->ebx);
    g_sfera_mbc_runtime->file_index_current = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000368B9;
    label_00036720: cpu->eip = LIFT_CODE_TOKEN_VA(0x436720u);
    cpu->ebp = native_function_address32(&::tolower);
    cpu->eax += 8u;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_normalized_name[0];
    cpu->edx -= cpu->eax;
    label_00036730: cpu->eip = LIFT_CODE_TOKEN_VA(0x436730u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00036730;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_normalized_name[0];
    cpu->esi = 0u;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00036744: cpu->eip = LIFT_CODE_TOKEN_VA(0x436744u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00036744;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003677D;
    (void)cpu;
    label_00036750: cpu->eip = LIFT_CODE_TOKEN_VA(0x436750u);
    cpu->edx = (int8_t)(lift_load8(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_normalized_name[0])));
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x3675Au), LIFT_CODE_TOKEN_RVA(0x36758u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x43675Au);
    lift_store8(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_normalized_name[0]), cpu->eax & 0xFFu);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_normalized_name[0];
    cpu->esp += 4u;
    ++cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00036770: cpu->eip = LIFT_CODE_TOKEN_VA(0x436770u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00036770;
    cpu->eax -= cpu->edx;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->eax)) goto label_00036750;
    label_0003677D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43677Du);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_normalized_name[0];
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00036785: cpu->eip = LIFT_CODE_TOKEN_VA(0x436785u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00036785;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_normalized_name[0];
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43679Cu); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_mbc_runtime->file_index_current;
    lift_push32(cpu, 4u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)((uint32_t)offsetof(SferaMbcFileIndexNode, checksum)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4367B1u); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_mbc_runtime->file_index_current;
    lift_push32(cpu, 4u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)((uint32_t)offsetof(SferaMbcFileIndexNode, file_size)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4367C6u); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_normalized_name[0];
    cpu->ecx = (uint32_t)(cpu->eax + 1u);
    cpu->edi = cpu->edi;
    label_000367D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4367D0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000367D0;
    cpu->eax -= cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->eax + 1u);
    cpu->eax = g_sfera_mbc_runtime->file_crc32;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_normalized_name[0];
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00036810;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000367F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4367F0u);
    cpu->esi = (int8_t)(lift_load8(cpu->edx));
    cpu->esi ^= cpu->eax;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax ^= lift_load32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_crc32_table[0]));
    --cpu->ecx;
    ++cpu->edx;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->ebx)) goto label_000367F0;
    g_sfera_mbc_runtime->file_crc32 = (uint32_t)(cpu->eax);
    label_00036810: cpu->eip = LIFT_CODE_TOKEN_VA(0x436810u);
    cpu->esi = g_sfera_mbc_runtime->file_index_current;
    cpu->ecx = 4u;
    cpu->edx = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcFileIndexNode, checksum));
    label_00036821: cpu->eip = LIFT_CODE_TOKEN_VA(0x436821u);
    cpu->ebp = (int8_t)(lift_load8(cpu->edx));
    cpu->ebp ^= cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax ^= lift_load32(((uint32_t)(cpu->ebp) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_crc32_table[0]));
    --cpu->ecx;
    ++cpu->edx;
    g_sfera_mbc_runtime->file_crc32 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->ebx)) goto label_00036821;
    cpu->ecx = 4u;
    cpu->edx = (uint32_t)(cpu->esi + (uint32_t)offsetof(SferaMbcFileIndexNode, file_size));
    cpu->esp = (uint32_t)(cpu->esp);
    label_00036850: cpu->eip = LIFT_CODE_TOKEN_VA(0x436850u);
    cpu->ebp = (int8_t)(lift_load8(cpu->edx));
    cpu->ebp ^= cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax ^= lift_load32(((uint32_t)(cpu->ebp) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_crc32_table[0]));
    --cpu->ecx;
    ++cpu->edx;
    g_sfera_mbc_runtime->file_crc32 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->ebx)) goto label_00036850;
    cpu->ecx = g_sfera_mbc_runtime->file_index_scan_prev;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0003688F;
    lift_push32(cpu, 0xF62u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x436889u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = g_sfera_mbc_runtime->file_index_current;
    label_0003688F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43688Fu);
    cpu->ecx = cpu->esi;
    g_sfera_mbc_runtime->file_index_scan_prev = (uint32_t)(cpu->ecx);
    cpu->eax = lift_load32(cpu->esi);
    g_sfera_mbc_runtime->file_index_current = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_00036720;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000368B9;
    lift_push32(cpu, 0xF65u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x368B9u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    label_000368B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4368B9u);
    lift_push32(cpu, cpu->ebx);
    cpu->edx = 0u;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4368C3u); lift_push32(cpu, r); sfera_sub_0042F0E0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->file_crc32;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4368D1u); lift_push32(cpu, r); sfera_sub_0042F000(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0042F180(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004368E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4368E0u);
    cpu->edx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load8(cpu->edx);
    lift_push32(cpu, cpu->edi);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->edi = 1u;
    cpu->edx += cpu->edi;
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->edx);
    lift_store32(cpu->eax, cpu->esi);
    cpu->ecx = lift_load32(cpu->edx);
    cpu->edx += 4u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->edx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(0x10u)) goto label_0003691C;
    if ((uint32_t)(cpu->esi) != (uint32_t)(0x20u)) goto label_00036944;
    label_0003691C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43691Cu);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->edx + cpu->ecx);
    lift_store32(cpu->eax + 0x14u, cpu->edx);
    lift_store32(cpu->eax + 4u, 4u);
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx += 3u;
    g_sfera_mbc_runtime->value_stack_size += cpu->edi;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax + 0x10u, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00036944: cpu->eip = LIFT_CODE_TOKEN_VA(0x436944u);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00036970;
    cpu->edx = (int8_t)(lift_load8(cpu->edx + cpu->ecx));
    g_sfera_mbc_runtime->value_stack_size += cpu->edi;
    lift_store32(cpu->eax + 4u, cpu->edi);
    lift_store32(cpu->eax + 0x14u, cpu->edx);
    lift_store32(cpu->eax, 0x10u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    lift_store32(cpu->eax + 0x10u, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00036970: cpu->eip = LIFT_CODE_TOKEN_VA(0x436970u);
    cpu->esi = lift_load32(cpu->edx + cpu->ecx);
    lift_store32(cpu->eax + 0x14u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + cpu->ecx + 4u);
    lift_store32(cpu->eax + 0x18u, cpu->esi);
    cpu->edx = lift_load32(cpu->edx + cpu->ecx + 8u);
    g_sfera_mbc_runtime->value_stack_size += cpu->edi;
    lift_store32(cpu->eax + 0x1Cu, cpu->edx);
    lift_store32(cpu->eax + 4u, 0xCu);
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx += 0xBu;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax + 0x10u, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004369A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4369A0u);
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->eax += lift_load32(cpu->eax);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004369B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4369B0u);
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = (int16_t)(lift_load16(cpu->eax));
    cpu->eax += cpu->ecx;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004369C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4369C0u);
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = lift_load8(cpu->eax);
    ++cpu->eax;
    g_sfera_mbc_runtime->argument_count = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004369E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4369E0u);
    cpu->eax = g_sfera_mbc_runtime->call_frame_depth;
    cpu->ecx = g_sfera_mbc_runtime->frame_stack_base[cpu->eax];
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436A00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x436A00u);
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load8(cpu->ecx);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = 1u;
    cpu->ecx += cpu->esi;
    lift_store32(cpu->eax + 0x10u, cpu->esi);
    lift_store32(cpu->eax + 0xCu, cpu->esi);
    lift_push32(cpu, cpu->edi);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    lift_store32(cpu->eax + 8u, 0xFFFFFFFFu);
    cpu->edi = lift_load32(cpu->ecx);
    lift_store32(cpu->eax + 0x14u, cpu->edi);
    cpu->edx += cpu->esi;
    cpu->ecx += 4u;
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    lift_store32(cpu->eax + 4u, 4u);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436A60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x436A60u);
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load8(cpu->ecx);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = 1u;
    cpu->ecx += cpu->esi;
    lift_store32(cpu->eax + 0x10u, cpu->esi);
    lift_store32(cpu->eax + 0xCu, cpu->esi);
    lift_push32(cpu, cpu->edi);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    lift_store32(cpu->eax + 8u, 0xFFFFFFFFu);
    cpu->edi = lift_load16(cpu->ecx);
    lift_store32(cpu->eax + 0x14u, cpu->edi);
    cpu->edx += cpu->esi;
    cpu->ecx += 2u;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax + 4u, 4u);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436AC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x436AC0u);
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load8(cpu->ecx);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    lift_store32(cpu->eax, cpu->esi);
    cpu->esi = 1u;
    cpu->ecx += cpu->esi;
    lift_store32(cpu->eax + 0x10u, cpu->esi);
    lift_store32(cpu->eax + 0xCu, cpu->esi);
    lift_push32(cpu, cpu->edi);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    lift_store32(cpu->eax + 8u, 0xFFFFFFFFu);
    cpu->edi = (int8_t)(lift_load8(cpu->ecx));
    lift_store32(cpu->eax + 0x14u, cpu->edi);
    cpu->ecx += cpu->esi;
    cpu->edx += cpu->esi;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax + 4u, 4u);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436B20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x436B20u);
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = cpu->esi;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    lift_store32(cpu->eax, 1u);
    lift_store32(cpu->eax + 8u, 0xFFFFFFFFu);
    lift_store32(cpu->eax + 0x10u, 1u);
    lift_store32(cpu->eax + 0xCu, 1u);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx += 4u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load16(cpu->ecx);
    cpu->ecx += 2u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edi + cpu->edx + 0xFFFFFFFFu);
    ++cpu->esi;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax + 0x18u, cpu->edx);
    lift_store32(cpu->eax + 0x14u, cpu->edx);
    lift_store32(cpu->eax + 0x1Cu, cpu->ecx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->esi);
    lift_store32(cpu->eax + 4u, 0xCu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436B90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x436B90u);
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->edx = lift_load8(cpu->ecx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx += 4u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx);
    cpu->ecx += 4u;
    lift_store32(cpu->eax + 0x18u, cpu->edx);
    lift_store32(cpu->eax + 0x14u, cpu->edx);
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edi + cpu->edx + 0xFFFFFFFFu);
    lift_store32(cpu->eax + 0x1Cu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 0x18u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0x1Cu);
    ++cpu->esi;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->esi);
    lift_store32(cpu->eax + 0x10u, cpu->edx);
    lift_store32(cpu->eax + 4u, 0xCu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436C00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x436C00u);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = cpu->ecx;
    ++cpu->ecx;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->edx = lift_load8(cpu->ecx);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->ecx += 4u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx);
    cpu->ecx += 4u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    lift_store32(cpu->eax + 0x18u, cpu->edx);
    lift_store32(cpu->eax + 0x14u, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esi + cpu->edx + 0xFFFFFFFFu);
    lift_store32(cpu->eax + 0x1Cu, cpu->ecx);
    lift_store32(cpu->eax + 8u, 0xFFFFFFFFu);
    lift_store32(cpu->eax + 0x10u, 1u);
    lift_store32(cpu->eax + 0xCu, 1u);
    lift_store32(cpu->eax + 4u, 0xCu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436C70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x436C70u);
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = (int16_t)(lift_load16(cpu->eax));
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0xA4u);
    cpu->eax += 2u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->program_table_base;
    cpu->edx = lift_load32(cpu->esi + cpu->eax + 0x24u);
    lift_store32(cpu->esi + cpu->eax + 0x88u, cpu->edx);
    cpu->eax = g_sfera_mbc_runtime->program_table_base;
    lift_store32(cpu->esi + cpu->eax + 0x98u, 0xFFFFFFFFu);
    cpu->eax = g_sfera_mbc_runtime->program_table_base;
    if ((int8_t)(uint8_t)(lift_load8(cpu->esi + cpu->eax + 0x2Cu)) >= (int8_t)(uint8_t)(0u)) goto label_00036CC7;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x436CBAu); lift_push32(cpu, r); sfera_sub_00434F10(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_mbc_runtime->program_table_base;
    lift_store8(cpu->esi + cpu->ecx + 0x2Cu, 1u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00036CC7: cpu->eip = LIFT_CODE_TOKEN_VA(0x436CC7u);
    lift_store8(cpu->esi + cpu->eax + 0x2Cu, 1u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436CD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x436CD0u);
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = (int16_t)(lift_load16(cpu->eax));
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0xA4u);
    cpu->eax += 2u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->program_table_base;
    cpu->edx = lift_load32(cpu->esi + cpu->eax + 0x24u);
    lift_store32(cpu->esi + cpu->eax + 0x88u, cpu->edx);
    cpu->eax = g_sfera_mbc_runtime->program_table_base;
    cpu->edx = g_sfera_mbc_runtime->program_index;
    lift_store32(cpu->esi + cpu->eax + 0x98u, cpu->edx);
    cpu->eax = g_sfera_mbc_runtime->program_table_base;
    if ((int8_t)(uint8_t)(lift_load8(cpu->esi + cpu->eax + 0x2Cu)) >= (int8_t)(uint8_t)(0u)) goto label_00036D21;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x436D1Cu); lift_push32(cpu, r); sfera_sub_00434F10(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_mbc_runtime->program_table_base;
    label_00036D21: cpu->eip = LIFT_CODE_TOKEN_VA(0x436D21u);
    lift_store8(cpu->esi + cpu->eax + 0x2Cu, 1u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436D30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x436D30u);
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->eax = (int16_t)(lift_load16(cpu->ecx));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    cpu->ecx += 2u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->program_table_base;
    cpu->edx = lift_load32(cpu->eax + cpu->ecx + 0x28u);
    lift_store32(cpu->eax + cpu->ecx + 0x88u, cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436D60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x436D60u);
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->eax = (int16_t)(lift_load16(cpu->ecx));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    cpu->ecx += 2u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->program_table_base;
    lift_store8(cpu->eax + cpu->ecx + 0x2Cu, 0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436D90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x436D90u);
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = (int16_t)(lift_load16(cpu->eax));
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0xA4u);
    cpu->eax += 2u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->program_table_base;
    if ((int8_t)(uint8_t)(lift_load8(cpu->esi + cpu->eax + 0x2Cu)) >= (int8_t)(uint8_t)(0u)) goto label_00036DBF;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x436DBAu); lift_push32(cpu, r); sfera_sub_00434F10(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_mbc_runtime->program_table_base;
    label_00036DBF: cpu->eip = LIFT_CODE_TOKEN_VA(0x436DBFu);
    lift_store8(cpu->esi + cpu->eax + 0x2Cu, 1u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x436DD0u);
    cpu->ecx = g_sfera_mbc_runtime->active_program_record;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + 0x84u)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00036DF2;
    cpu->ecx = g_sfera_mbc_runtime->bytecode_base;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ecx += cpu->eax;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
    label_00036DF2: cpu->eip = LIFT_CODE_TOKEN_VA(0x436DF2u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) - 1u)) & 0xFFu);
    lift_store8(cpu->ecx + 0x84u, cpu->eax & 0xFFu);
    cpu->ecx = g_sfera_mbc_runtime->bytecode_base;
    cpu->edx = cpu->eax & 0xFFu;
    cpu->eax = g_sfera_mbc_runtime->active_program_record;
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->edx) * 4u) + 0x34u);
    cpu->ecx += cpu->eax;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436E20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x436E20u);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    lift_push32(cpu, cpu->ebx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->eax);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->ebx = lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.width));
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type));
    cpu->eax = lift_load32(cpu->esi + 0xFFFFFFE8u);
    lift_push32(cpu, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00036E4A;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_00036E5E;
    label_00036E4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x436E4Au);
    cpu->ecx = lift_load32(cpu->esi + 0xFFFFFFECu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00036E68;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_00036E5E;
    cpu->eax = (uint32_t)(cpu->eax + cpu->ebx + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esi + 0xFFFFFFF0u))) goto label_00036E68;
    label_00036E5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x436E5Eu);
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFE8u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x36E68u); lift_push32(cpu, r); sfera_sub_00434E80(cpu,r); if (cpu->eip != r) return; }
    label_00036E68: cpu->eip = LIFT_CODE_TOKEN_VA(0x436E68u);
    if ((uint32_t)(cpu->ebx) != (uint32_t)(1u)) goto label_00036E8A;
    cpu->ecx = lift_load32(cpu->esi + 0xFFFFFFE8u);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->esi + 0xFFFFFFF4u, 0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0x14u)) & 0xFFu);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + 0xFFFFFFF4u, cpu->eax & 0xFFu);
    cpu->esi = lift_pop32(cpu);
    lift_store8(cpu->edx + cpu->ecx, cpu->eax & 0xFFu);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00036E8A: cpu->eip = LIFT_CODE_TOKEN_VA(0x436E8Au);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0xFFFFFFE0u)), r=(uint64_t)(0xFu), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    lift_store32(cpu->esi + 0xFFFFFFF4u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00036EA6;
    cpu->ecx = lift_load32(cpu->esi + 0xFFFFFFE8u);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->edx + cpu->ecx, cpu->eax);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00036EA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x436EA6u);
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->edi = lift_load32(cpu->esi + 0xFFFFFFE8u);
    cpu->edi += g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->esi + 0xFFFFFFF8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0x1Cu);
    lift_store32(cpu->esi + 0xFFFFFFFCu, cpu->edx);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    lift_store32(cpu->edi, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->edi + 4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0x1Cu);
    lift_store32(cpu->edi + 8u, cpu->edx);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436ED0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x436ED0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(5u), 32u);
    cpu->eax = lift_load32(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0]));
    cpu->ecx = lift_load32(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[1]));
    cpu->edx = lift_load32(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[2]));
    cpu->esi = (uint32_t)(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    lift_store32(cpu->esi + 8u, cpu->eax);
    cpu->eax = cpu->ecx;
    lift_store32(cpu->esi + 0xCu, cpu->ecx);
    lift_store32(cpu->esi + 0x10u, cpu->edx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00036F63;
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->eax)) goto label_00036F0C;
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(cpu->edx)) goto label_00036F63;
    label_00036F0C: cpu->eip = LIFT_CODE_TOKEN_VA(0x436F0Cu);
    cpu->ecx = 1u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x436F16u); lift_push32(cpu, r); sfera_sub_00434AF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->edx = lift_load32(cpu->esi + 0x14u);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0]); lift_push32(cpu, (uintptr_t)"%s\n Slice out of range! ptr = %d, begin = %d, end = %d"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x436F37u); lift_push32(cpu, r); sfera_sub_0049B7F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    cpu->esp += 0x18u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00036F63;
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00036F63;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00036F53;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esi + 0x1Cu))) goto label_00036F63;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_00036F53: cpu->eip = LIFT_CODE_TOKEN_VA(0x436F53u);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_00036F5A;
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    goto label_00036F63;
    label_00036F5A: cpu->eip = LIFT_CODE_TOKEN_VA(0x436F5Au);
    --cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x1Cu))) goto label_00036F63;
    lift_store32(cpu->esi + 0x1Cu, cpu->eax);
    label_00036F63: cpu->eip = LIFT_CODE_TOKEN_VA(0x436F63u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esi, v); }
    cpu->eax = lift_load32(cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00036F88;
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = (int8_t)(lift_load8(cpu->eax + cpu->ecx));
    lift_store32(cpu->esi + 0x14u, cpu->edx);
    lift_store32(cpu->esi + 4u, 1u);
    lift_store32(cpu->esi, 0x10u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00036F88: cpu->eip = LIFT_CODE_TOKEN_VA(0x436F88u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(0xFu), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00036FA4;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->ecx + cpu->eax);
    lift_store32(cpu->esi + 0x14u, cpu->edx);
    lift_store32(cpu->esi + 4u, 4u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00036FA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x436FA4u);
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->esi + 0x14u, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esi + 0x18u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esi + 0x1Cu, cpu->eax);
    lift_store32(cpu->esi + 4u, 0xCu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00436FD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x436FD0u);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.source_id));
    cpu->edx = lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.range_begin));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    lift_store32(cpu->eax + 0x14u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 0x10u);
    lift_store32(cpu->eax + 0x18u, cpu->edx);
    lift_store32(cpu->eax + 0x1Cu, cpu->ecx);
    cpu->ecx = 1u;
    lift_store32(cpu->eax + 8u, 0xFFFFFFFFu);
    lift_store32(cpu->eax + 0x10u, cpu->ecx);
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    lift_store32(cpu->eax, (uint64_t)(lift_load32(cpu->eax)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    lift_store32(cpu->eax + 4u, 0xCu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437020(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437020u);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = (uint32_t)(cpu->ecx + 0xFFFFFFFEu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->edx = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037049;
    cpu->edx = lift_load32(cpu->edx + 0x14u);
    lift_store32(cpu->eax + 0x14u, (uint64_t)(lift_load32(cpu->eax + 0x14u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    goto label_00037052;
    label_00037049: cpu->eip = LIFT_CODE_TOKEN_VA(0x437049u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x14u))));
    lift_store_f32(cpu->eax + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00037052: cpu->eip = LIFT_CODE_TOKEN_VA(0x437052u);
    cpu->edx = 1u;
    cpu->ecx -= cpu->edx;
    lift_store32(cpu->eax + 8u, 0xFFFFFFFFu);
    lift_store32(cpu->eax + 0x10u, cpu->edx);
    lift_store32(cpu->eax + 0xCu, cpu->edx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437070(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437070u);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = (uint32_t)(cpu->ecx + 0xFFFFFFFEu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->edx = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037099;
    cpu->edx = lift_load32(cpu->edx + 0x14u);
    lift_store32(cpu->eax + 0x14u, (uint64_t)(lift_load32(cpu->eax + 0x14u)) - (uint64_t)(cpu->edx) - (uint64_t)(0u));
    goto label_000370A2;
    label_00037099: cpu->eip = LIFT_CODE_TOKEN_VA(0x437099u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + 0x14u))));
    lift_store_f32(cpu->eax + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000370A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4370A2u);
    cpu->edx = 1u;
    cpu->ecx -= cpu->edx;
    lift_store32(cpu->eax + 8u, 0xFFFFFFFFu);
    lift_store32(cpu->eax + 0x10u, cpu->edx);
    lift_store32(cpu->eax + 0xCu, cpu->edx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004370C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4370C0u);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = (uint32_t)(cpu->ecx + 0xFFFFFFFEu);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->edx = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000370ED;
    cpu->edx = lift_load32(cpu->edx + 0x14u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(lift_load32(cpu->eax + 0x14u));
    lift_store32(cpu->eax + 0x14u, cpu->edx);
    goto label_000370F6;
    label_000370ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4370EDu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x14u))));
    lift_store_f32(cpu->eax + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000370F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4370F6u);
    cpu->edx = 1u;
    cpu->ecx -= cpu->edx;
    lift_store32(cpu->eax + 8u, 0xFFFFFFFFu);
    lift_store32(cpu->eax + 0x10u, cpu->edx);
    lift_store32(cpu->eax + 0xCu, cpu->edx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437120(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437120u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFFEu);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = lift_load32(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(5u), 32u);
    lift_divide_accumulator(cpu, lift_load32(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0])), 32u, 1u);
    cpu->eax = 1u;
    cpu->esi -= cpu->eax;
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->esi);
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ecx + 0x14u, cpu->edx);
    lift_store32(cpu->ecx + 8u, 0xFFFFFFFFu);
    lift_store32(cpu->ecx + 0x10u, cpu->eax);
    lift_store32(cpu->ecx + 0xCu, cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437170(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437170u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFFEu);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    cpu->eax = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx)), r=(uint64_t)(0x20u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000371A5;
    cpu->edx = lift_load32(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->eax + 0x14u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    lift_store32(cpu->ecx + 0x14u, cpu->ebx);
    cpu->ebx = lift_pop32(cpu);
    goto label_000371C0;
    label_000371A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4371A5u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000371BB;
    cpu->eax = 1u;
    goto label_000371BD;
    label_000371BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4371BBu);
    cpu->eax = 0u;
    label_000371BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4371BDu);
    lift_store32(cpu->ecx + 0x14u, cpu->eax);
    label_000371C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4371C0u);
    --cpu->esi;
    lift_store32(cpu->ecx + 8u, 0xFFFFFFFFu);
    lift_store32(cpu->ecx + 0x10u, 1u);
    lift_store32(cpu->ecx + 0xCu, 1u);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->esi);
    lift_store32(cpu->ecx, 0x10u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004371F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4371F0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFFEu);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    cpu->eax = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx)), r=(uint64_t)(0x20u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00037225;
    cpu->edx = lift_load32(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->eax + 0x14u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store32(cpu->ecx + 0x14u, cpu->ebx);
    cpu->ebx = lift_pop32(cpu);
    goto label_00037240;
    label_00037225: cpu->eip = LIFT_CODE_TOKEN_VA(0x437225u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0003723B;
    cpu->eax = 1u;
    goto label_0003723D;
    label_0003723B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43723Bu);
    cpu->eax = 0u;
    label_0003723D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43723Du);
    lift_store32(cpu->ecx + 0x14u, cpu->eax);
    label_00037240: cpu->eip = LIFT_CODE_TOKEN_VA(0x437240u);
    --cpu->esi;
    lift_store32(cpu->ecx + 8u, 0xFFFFFFFFu);
    lift_store32(cpu->ecx + 0x10u, 1u);
    lift_store32(cpu->ecx + 0xCu, 1u);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->esi);
    lift_store32(cpu->ecx, 0x10u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437270u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFFEu);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    cpu->eax = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx)), r=(uint64_t)(0x20u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000372A5;
    cpu->edx = lift_load32(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->eax + 0x14u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u))) ? 1u : 0u) & 0xFFu);
    lift_store32(cpu->ecx + 0x14u, cpu->ebx);
    cpu->ebx = lift_pop32(cpu);
    goto label_000372C0;
    label_000372A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4372A5u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000372BB;
    cpu->eax = 1u;
    goto label_000372BD;
    label_000372BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4372BBu);
    cpu->eax = 0u;
    label_000372BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4372BDu);
    lift_store32(cpu->ecx + 0x14u, cpu->eax);
    label_000372C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4372C0u);
    --cpu->esi;
    lift_store32(cpu->ecx + 8u, 0xFFFFFFFFu);
    lift_store32(cpu->ecx + 0x10u, 1u);
    lift_store32(cpu->ecx + 0xCu, 1u);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->esi);
    lift_store32(cpu->ecx, 0x10u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004372F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4372F0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFFEu);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    cpu->eax = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx)), r=(uint64_t)(0x20u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00037325;
    cpu->edx = lift_load32(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->eax + 0x14u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u)) ? 1u : 0u) & 0xFFu);
    lift_store32(cpu->ecx + 0x14u, cpu->ebx);
    cpu->ebx = lift_pop32(cpu);
    goto label_00037340;
    label_00037325: cpu->eip = LIFT_CODE_TOKEN_VA(0x437325u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0003733B;
    cpu->eax = 1u;
    goto label_0003733D;
    label_0003733B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43733Bu);
    cpu->eax = 0u;
    label_0003733D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43733Du);
    lift_store32(cpu->ecx + 0x14u, cpu->eax);
    label_00037340: cpu->eip = LIFT_CODE_TOKEN_VA(0x437340u);
    --cpu->esi;
    lift_store32(cpu->ecx + 8u, 0xFFFFFFFFu);
    lift_store32(cpu->ecx + 0x10u, 1u);
    lift_store32(cpu->ecx + 0xCu, 1u);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->esi);
    lift_store32(cpu->ecx, 0x10u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437370(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437370u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFFEu);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    cpu->eax = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx)), r=(uint64_t)(0x20u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000373A5;
    cpu->edx = lift_load32(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->eax + 0x14u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store32(cpu->ecx + 0x14u, cpu->ebx);
    cpu->ebx = lift_pop32(cpu);
    goto label_000373C0;
    label_000373A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4373A5u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000373BB;
    cpu->eax = 1u;
    goto label_000373BD;
    label_000373BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4373BBu);
    cpu->eax = 0u;
    label_000373BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4373BDu);
    lift_store32(cpu->ecx + 0x14u, cpu->eax);
    label_000373C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4373C0u);
    --cpu->esi;
    lift_store32(cpu->ecx + 8u, 0xFFFFFFFFu);
    lift_store32(cpu->ecx + 0x10u, 1u);
    lift_store32(cpu->ecx + 0xCu, 1u);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->esi);
    lift_store32(cpu->ecx, 0x10u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004373F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4373F0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFFEu);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    cpu->eax = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx)), r=(uint64_t)(0x20u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00037425;
    cpu->edx = lift_load32(cpu->ecx + 0x14u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->eax + 0x14u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u))) ? 1u : 0u) & 0xFFu);
    lift_store32(cpu->ecx + 0x14u, cpu->ebx);
    cpu->ebx = lift_pop32(cpu);
    goto label_00037440;
    label_00037425: cpu->eip = LIFT_CODE_TOKEN_VA(0x437425u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_0003743B;
    cpu->eax = 1u;
    goto label_0003743D;
    label_0003743B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43743Bu);
    cpu->eax = 0u;
    label_0003743D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43743Du);
    lift_store32(cpu->ecx + 0x14u, cpu->eax);
    label_00037440: cpu->eip = LIFT_CODE_TOKEN_VA(0x437440u);
    --cpu->esi;
    lift_store32(cpu->ecx + 8u, 0xFFFFFFFFu);
    lift_store32(cpu->ecx + 0x10u, 1u);
    lift_store32(cpu->ecx + 0xCu, 1u);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->esi);
    lift_store32(cpu->ecx, 0x10u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437470u);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0]))), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037495;
    --g_sfera_mbc_runtime->value_stack_size;
    g_sfera_mbc_runtime->instruction_cursor += 2u;
    lift_return(cpu, 0u, stop_address); return;
    label_00037495: cpu->eip = LIFT_CODE_TOKEN_VA(0x437495u);
    lift_store32(cpu->eax, 0x10u);
    cpu->ecx = 1u;
    lift_store32(cpu->eax + 8u, 0xFFFFFFFFu);
    lift_store32(cpu->eax + 0x10u, cpu->ecx);
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = (int16_t)(lift_load16(cpu->eax));
    cpu->eax += cpu->ecx;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004374C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4374C0u);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0]))), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000374E5;
    --g_sfera_mbc_runtime->value_stack_size;
    g_sfera_mbc_runtime->instruction_cursor += 2u;
    lift_return(cpu, 0u, stop_address); return;
    label_000374E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4374E5u);
    lift_store32(cpu->eax, 0x10u);
    cpu->ecx = 1u;
    lift_store32(cpu->eax + 8u, 0xFFFFFFFFu);
    lift_store32(cpu->eax + 0x10u, cpu->ecx);
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = (int16_t)(lift_load16(cpu->eax));
    cpu->eax += cpu->ecx;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437510u);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    cpu->ecx = 1u;
    lift_store32(cpu->eax + 8u, 0xFFFFFFFFu);
    lift_store32(cpu->eax + 0x10u, cpu->ecx);
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    lift_store32(cpu->eax, 0x10u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437540(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437540u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0x10u)) goto label_0003755E;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_0003758B;
    label_0003755E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43755Eu);
    cpu->edx = 1u;
    lift_store32(cpu->eax + 0x14u, (uint64_t)(lift_load32(cpu->eax + 0x14u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    cpu->ecx = lift_load32(cpu->eax + 0x14u);
    if ((uint32_t)(lift_load32(cpu->eax + 4u)) != (uint32_t)(cpu->edx)) goto label_0003757E;
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 0x14u)) & 0xFFu);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store8(cpu->eax + cpu->ecx, cpu->edx & 0xFFu);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003757E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43757Eu);
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->eax + cpu->edx, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0003758B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43758Bu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (1.0));
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_store_f32(cpu->eax + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edx + cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004375B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4375B0u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0x10u)) goto label_000375CE;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000375F7;
    label_000375CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4375CEu);
    lift_store32(cpu->eax + 0x14u, (uint64_t)(lift_load32(cpu->eax + 0x14u)) - 1u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 4u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = lift_load32(cpu->eax + 0x14u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000375EA;
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 0x14u)) & 0xFFu);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store8(cpu->eax + cpu->ecx, cpu->edx & 0xFFu);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000375EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4375EAu);
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->eax + cpu->edx, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000375F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4375F7u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (1.0));
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_store_f32(cpu->eax + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edx + cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437620(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437620u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0x10u)) goto label_0003763E;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_00037664;
    label_0003763E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43763Eu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 4u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037656;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 0x14u)) & 0xFFu);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) + 1u)) & 0xFFu);
    lift_store8(cpu->eax + cpu->edx, cpu->ecx & 0xFFu);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00037656: cpu->eip = LIFT_CODE_TOKEN_VA(0x437656u);
    cpu->ecx = lift_load32(cpu->eax + 0x14u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    ++cpu->ecx;
    lift_store32(cpu->eax + cpu->edx, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00037664: cpu->eip = LIFT_CODE_TOKEN_VA(0x437664u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (1.0));
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_store_f32(cpu->edx + cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437690(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437690u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0x10u)) goto label_000376AE;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_000376D4;
    label_000376AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4376AEu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 4u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = lift_load32(cpu->eax + 8u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000376C6;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 0x14u)) & 0xFFu);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) - 1u)) & 0xFFu);
    lift_store8(cpu->eax + cpu->edx, cpu->ecx & 0xFFu);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000376C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4376C6u);
    cpu->ecx = lift_load32(cpu->eax + 0x14u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    --cpu->ecx;
    lift_store32(cpu->eax + cpu->edx, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000376D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4376D4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    cpu->ecx = lift_load32(cpu->eax + 8u);
    lift_x87_push(cpu, 1.0);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_store_f32(cpu->eax + 0x14u, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_store_f32(cpu->edx + cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437700(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437700u);
    cpu->eax = g_sfera_mbc_runtime->current_instruction_address;
    cpu->eax -= g_sfera_mbc_runtime->bytecode_base;
    cpu->ecx = g_sfera_mbc_runtime->process_index;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x437718u); lift_push32(cpu, r); sfera_sub_00421710(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43771Fu); lift_push32(cpu, r); sfera_sub_00421720(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx = lift_load8(cpu->eax);
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
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437750u);
    g_sfera_mbc_runtime->execution_failed = (uint32_t)(1u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437760(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437760u);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0]))))));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    lift_store32(cpu->eax, 0x20u);
    lift_store_f32(cpu->eax + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437780(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437780u);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFFFFFFEu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->eax + 0x14u)))));
    lift_store32(cpu->eax, 0x20u);
    lift_store_f32(cpu->eax + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004377A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4377A0u);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = (uint32_t)(cpu->ecx + 0xFFFFFFFEu);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
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
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004377F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4377F0u);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->eax);
    cpu->edx = lift_load16(cpu->ecx);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->ecx += 2u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0];
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->edx);
    lift_store32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0]), (uint64_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0]))) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    lift_store32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.source_id), 0xFFFFFFFFu);
    lift_store32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.range_end), 1u);
    lift_store32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.range_begin), 1u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437840(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437840u);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->eax);
    cpu->edx = lift_load16(cpu->ecx);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->ecx += 2u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0];
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->edx);
    lift_store32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0]), (uint64_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0]))) - (uint64_t)(cpu->ecx) - (uint64_t)(0u));
    lift_store32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.source_id), 0xFFFFFFFFu);
    lift_store32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.range_end), 1u);
    lift_store32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.range_begin), 1u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437890(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437890u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(5u), 32u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0])));
    cpu->esi = (uint32_t)(cpu->esi + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4378ABu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_store32(cpu->esi, 0x10u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004378C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4378C0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xFFFFFFFEu), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(5u), 32u);
    cpu->esi += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4378DBu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_store32(cpu->esi, 0x10u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004378F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4378F0u);
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->edx = lift_load16(cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    lift_store32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0]), (uint64_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0]))) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    cpu->ecx += 2u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 0x14u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->edx + cpu->eax, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437930(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437930u);
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->edx = lift_load16(cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    lift_store32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0]), (uint64_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.payload[0]))) - (uint64_t)(cpu->edx) - (uint64_t)(0u));
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    cpu->ecx += 2u;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 0x14u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->edx + cpu->eax, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437970u);
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->edx = lift_load16(cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->ecx += 2u;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 0x14u);
    cpu->ecx += cpu->edx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->eax + cpu->edx, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004379B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4379B0u);
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->edx = lift_load16(cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->ecx += 2u;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 0x14u);
    cpu->ecx -= cpu->edx;
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->eax + cpu->edx, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004379F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4379F0u);
    cpu->eax = g_sfera_mbc_runtime->value_stack_size;
    cpu->edx = (uint32_t)(cpu->eax + 0xFFFFFFFEu);
    cpu->ecx = 0x10u;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(5u), 32u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].type = (uint32_t)(cpu->ecx);
    lift_store32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type), cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437A10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437A10u);
    cpu->eax = g_sfera_mbc_runtime->active_process;
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0xA4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    cpu->edi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037A63;
    cpu->ecx = lift_load32(cpu->eax + 0xB4u);
    { uint64_t x=(uint64_t)(cpu->ecx), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->ecx = v; }
    cpu->ecx = (uint64_t)(cpu->ecx) - (uint64_t)(cpu->ecx) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->ecx &= 0xFFFF3CBAu;
    cpu->ecx += 0xC350u;
    lift_store32(cpu->eax + 0xACu, cpu->ecx);
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->ecx = lift_load32(cpu->edx + 0xACu);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x1936u);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x437A61u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    goto label_00037AB3;
    label_00037A63: cpu->eip = LIFT_CODE_TOKEN_VA(0x437A63u);
    cpu->edx = lift_load32(cpu->eax + 0xA8u);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(lift_load32(cpu->eax + 0xACu))) goto label_00037AC4;
    if ((uint32_t)(lift_load32(cpu->eax + 0xB4u)) != (uint32_t)(0u)) goto label_00037A86;
    lift_store32(cpu->eax + 0xACu, (uint64_t)(lift_load32(cpu->eax + 0xACu)) + (uint64_t)(0x2710u) + (uint64_t)(0u));
    goto label_00037A8D;
    label_00037A86: cpu->eip = LIFT_CODE_TOKEN_VA(0x437A86u);
    lift_store32(cpu->eax + 0xACu, (uint64_t)(lift_load32(cpu->eax + 0xACu)) + (uint64_t)(0xAu) + (uint64_t)(0u));
    label_00037A8D: cpu->eip = LIFT_CODE_TOKEN_VA(0x437A8Du);
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->edx = lift_load32(cpu->eax + 0xACu);
    cpu->ecx = lift_load32(cpu->eax + 0xA4u);
    cpu->edx += cpu->edx;
    lift_push32(cpu, 0x193Bu);
    cpu->edx += cpu->edx;
    lift_push32(cpu, (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp");
    cpu->edx += cpu->edx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x37AB3u); lift_push32(cpu, r); sfera_sub_004EBE80(cpu,r); if (cpu->eip != r) return; }
    label_00037AB3: cpu->eip = LIFT_CODE_TOKEN_VA(0x437AB3u);
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    lift_store32(cpu->ecx + 0xA4u, cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->active_process;
    label_00037AC4: cpu->eip = LIFT_CODE_TOKEN_VA(0x437AC4u);
    cpu->edx = lift_load32(cpu->eax + 0xA8u);
    cpu->eax = lift_load32(cpu->eax + 0xA4u);
    lift_store32(cpu->eax + ((uint32_t)(cpu->edx) * 8u), cpu->edi);
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->ecx = lift_load32(cpu->eax + 0xA8u);
    cpu->edx = lift_load32(cpu->eax + 0xA4u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->ecx) * 8u) + 4u, cpu->esi);
    cpu->eax = g_sfera_mbc_runtime->active_process;
    lift_store32(cpu->eax + 0xA8u, (uint64_t)(lift_load32(cpu->eax + 0xA8u)) + 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437B00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437B00u);
    sfera_sub_00437A10(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437B10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437B10u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->ebx) != 0u) goto label_00037B22;
    cpu->ebx = g_sfera_mbc_runtime->active_process;
    label_00037B22: cpu->eip = LIFT_CODE_TOKEN_VA(0x437B22u);
    cpu->esi = lift_load32(cpu->ebx + 0xA8u);
    cpu->ebp = lift_load32(cpu->ebx + 0xA4u);
    cpu->eax = 0u;
    cpu->edi = cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00037B70;
    label_00037B36: cpu->eip = LIFT_CODE_TOKEN_VA(0x437B36u);
    if ((uint32_t)(lift_load32(cpu->edi)) != (uint32_t)(cpu->ecx)) goto label_00037B3F;
    if ((uint32_t)(lift_load32(cpu->edi + 4u)) == (uint32_t)(cpu->edx)) goto label_00037B54;
    label_00037B3F: cpu->eip = LIFT_CODE_TOKEN_VA(0x437B3Fu);
    ++cpu->eax;
    cpu->edi += 8u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->esi)) goto label_00037B36;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ebx + 0xA8u, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00037B54: cpu->eip = LIFT_CODE_TOKEN_VA(0x437B54u);
    cpu->ecx = cpu->esi;
    cpu->ecx -= cpu->eax;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ecx) * 8u) + 0xFFFFFFF8u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->eax) * 8u) + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x437B66u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x437B6Cu);
    cpu->esp += 0xCu;
    --cpu->esi;
    label_00037B70: cpu->eip = LIFT_CODE_TOKEN_VA(0x437B70u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ebx + 0xA8u, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437B80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437B80u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = g_sfera_mbc_runtime->active_process;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->ebx + 0xA4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebx + 0xA8u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00037BD8;
    cpu->edi = cpu->edi;
    label_00037BA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x437BA0u);
    if ((uint32_t)(lift_load32(cpu->edi)) != (uint32_t)(cpu->ecx)) goto label_00037BA9;
    if ((uint32_t)(lift_load32(cpu->edi + 4u)) == (uint32_t)(cpu->edx)) goto label_00037BBC;
    label_00037BA9: cpu->eip = LIFT_CODE_TOKEN_VA(0x437BA9u);
    ++cpu->eax;
    cpu->edi += 8u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->esi)) goto label_00037BA0;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ebx + 0xA8u, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00037BBC: cpu->eip = LIFT_CODE_TOKEN_VA(0x437BBCu);
    cpu->ecx = cpu->esi;
    cpu->ecx -= cpu->eax;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ecx) * 8u) + 0xFFFFFFF8u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->eax) * 8u) + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x437BCEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x437BD4u);
    cpu->esp += 0xCu;
    --cpu->esi;
    label_00037BD8: cpu->eip = LIFT_CODE_TOKEN_VA(0x437BD8u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ebx + 0xA8u, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437BF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437BF0u);
    cpu->esp -= 8u;
    lift_store32(cpu->esp, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp)))));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 120.0);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_00037C41;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
    label_00037C41: cpu->eip = LIFT_CODE_TOKEN_VA(0x437C41u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037C50;
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    goto label_00037C55;
    label_00037C50: cpu->eip = LIFT_CODE_TOKEN_VA(0x437C50u);
    cpu->ecx = 1u;
    label_00037C55: cpu->eip = LIFT_CODE_TOKEN_VA(0x437C55u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (40.0));
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(0xBu), 32u);
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_push(cpu, (double)0.0062500000931322575f); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store16(cpu->esp + 0xCu, cpu->fpu_control);
    lift_x87_set(cpu, 0u, (((double)g_sfera_recovered_static_runtime.inverse_40)) - (lift_x87_get(cpu, 0u)));
    cpu->eax = lift_load16(cpu->esp + 0xCu);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp, cpu->eax);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (2047.0));
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp));
    lift_store64(cpu->esp, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp);
    cpu->eax |= cpu->ecx;
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0xCu));
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437CB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437CB0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->edx;
    cpu->esi = cpu->ecx;
    cpu->ecx = 0u;
    { uint64_t v=(uint64_t)(cpu->ebp); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00037CC0;
    cpu->ecx = lift_load32(cpu->ebp);
    label_00037CC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x437CC0u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->edx & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    lift_push32(cpu, cpu->edi);
    cpu->esi += cpu->eax;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    cpu->edi = 2u;
    label_00037CE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x437CE1u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00037CE9;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00037CEF;
    label_00037CE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x437CE9u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00037CEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x437CEFu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037CF6;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00037CF6: cpu->eip = LIFT_CODE_TOKEN_VA(0x437CF6u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037CFD;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00037CFD: cpu->eip = LIFT_CODE_TOKEN_VA(0x437CFDu);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00037D05;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00037D0B;
    label_00037D05: cpu->eip = LIFT_CODE_TOKEN_VA(0x437D05u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00037D0B: cpu->eip = LIFT_CODE_TOKEN_VA(0x437D0Bu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037D12;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00037D12: cpu->eip = LIFT_CODE_TOKEN_VA(0x437D12u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037D19;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00037D19: cpu->eip = LIFT_CODE_TOKEN_VA(0x437D19u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00037D21;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00037D27;
    label_00037D21: cpu->eip = LIFT_CODE_TOKEN_VA(0x437D21u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00037D27: cpu->eip = LIFT_CODE_TOKEN_VA(0x437D27u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037D2E;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00037D2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x437D2Eu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037D35;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00037D35: cpu->eip = LIFT_CODE_TOKEN_VA(0x437D35u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00037D3D;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00037D43;
    label_00037D3D: cpu->eip = LIFT_CODE_TOKEN_VA(0x437D3Du);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00037D43: cpu->eip = LIFT_CODE_TOKEN_VA(0x437D43u);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037D4A;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00037D4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x437D4Au);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037D51;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00037D51: cpu->eip = LIFT_CODE_TOKEN_VA(0x437D51u);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00037D59;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00037D5F;
    label_00037D59: cpu->eip = LIFT_CODE_TOKEN_VA(0x437D59u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00037D5F: cpu->eip = LIFT_CODE_TOKEN_VA(0x437D5Fu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037D66;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00037D66: cpu->eip = LIFT_CODE_TOKEN_VA(0x437D66u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037D6D;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00037D6D: cpu->eip = LIFT_CODE_TOKEN_VA(0x437D6Du);
    if ((uint8_t)((lift_load8(cpu->esi)) & ((cpu->edx & 0xFFu))) == 0u) goto label_00037D75;
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) | (uint64_t)((cpu->ecx & 0xFFu)));
    goto label_00037D7B;
    label_00037D75: cpu->eip = LIFT_CODE_TOKEN_VA(0x437D75u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->ecx & 0xFFu)) & 0xFFu);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(~((uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax, (uint64_t)(lift_load8(cpu->eax)) & (uint64_t)((cpu->ebx & 0xFFu)));
    label_00037D7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x437D7Bu);
    { uint64_t l=(uint64_t)((cpu->ecx & 0xFFu)), r=(uint64_t)((cpu->ecx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037D82;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->eax;
    label_00037D82: cpu->eip = LIFT_CODE_TOKEN_VA(0x437D82u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)((cpu->edx & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037D89;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->esi;
    label_00037D89: cpu->eip = LIFT_CODE_TOKEN_VA(0x437D89u);
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037CE1;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_00037D9A;
    lift_store32(cpu->ebp, (uint64_t)(lift_load32(cpu->ebp)) + (uint64_t)(0xCu) + (uint64_t)(0u));
    label_00037D9A: cpu->eip = LIFT_CODE_TOKEN_VA(0x437D9Au);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.inverse_40));
    lift_x87_push(cpu, (double)0.0062500000931322575f);
    cpu->ecx = cpu->eax;
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x7FFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 8u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 8u)))));
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00037DC6;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_00037DC6: cpu->eip = LIFT_CODE_TOKEN_VA(0x437DC6u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (2047.0));
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (40.0));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    if ((uint32_t)((cpu->eax) & (0x800u)) == 0u) goto label_00037DF1;
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    label_00037DF1: cpu->eip = LIFT_CODE_TOKEN_VA(0x437DF1u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 8u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp))));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437E10u);
    sfera_sub_00433960(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437E20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437E20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->named_vector_count;
    lift_push32(cpu, cpu->edi);
    cpu->ebx = 0u;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->named_vectors[0];
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    cpu->ebp = cpu->ecx;
    g_sfera_mbc_runtime->named_vector_cursor = (uint32_t)(cpu->edi);
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00037E7E;
    label_00037E42: cpu->eip = LIFT_CODE_TOKEN_VA(0x437E42u);
    cpu->ecx = lift_load32(cpu->edi + 0xCu);
    cpu->eax = cpu->ebp;
    label_00037E47: cpu->eip = LIFT_CODE_TOKEN_VA(0x437E47u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037E67;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_00037E63;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037E67;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00037E47;
    label_00037E63: cpu->eip = LIFT_CODE_TOKEN_VA(0x437E63u);
    cpu->eax = 0u;
    goto label_00037E6C;
    label_00037E67: cpu->eip = LIFT_CODE_TOKEN_VA(0x437E67u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_00037E6C: cpu->eip = LIFT_CODE_TOKEN_VA(0x437E6Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00037EE4;
    cpu->edi += 0x10u;
    ++cpu->ebx;
    g_sfera_mbc_runtime->named_vector_cursor = (uint32_t)(cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->esi)) goto label_00037E42;
    label_00037E7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x437E7Eu);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0x3E8u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_00037F4F;
    cpu->eax = cpu->esi;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->named_vectors[0]);
    g_sfera_mbc_runtime->named_vector_cursor = (uint32_t)(cpu->eax);
    ++cpu->esi;
    cpu->eax = cpu->ebp;
    g_sfera_mbc_runtime->named_vector_count = (uint32_t)(cpu->esi);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00037EA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x437EA5u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00037EA5;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, 0x35FEu);
    cpu->ecx = (uint32_t)(cpu->eax + 1u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x437EC0u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_mbc_runtime->named_vector_cursor;
    lift_store32(cpu->ecx + 0xCu, cpu->eax);
    cpu->edx = g_sfera_mbc_runtime->named_vector_cursor;
    cpu->edx = lift_load32(cpu->edx + 0xCu);
    cpu->ecx = cpu->ebp;
    label_00037ED4: cpu->eip = LIFT_CODE_TOKEN_VA(0x437ED4u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00037ED4;
    cpu->edi = g_sfera_mbc_runtime->named_vector_cursor;
    label_00037EE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x437EE4u);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->edi + 4u)) > (int32_t)(uint32_t)(cpu->esi)) goto label_00037F46;
    cpu->ecx = lift_load32(cpu->edi);
    lift_push32(cpu, 0x3603u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp");
    cpu->edx = (uint32_t)(((uint32_t)(cpu->esi) * 4u) + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x437F05u); lift_push32(cpu, r); sfera_sub_004EBE80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_mbc_runtime->named_vector_cursor;
    lift_store32(cpu->ecx, cpu->eax);
    cpu->edx = g_sfera_mbc_runtime->named_vector_cursor;
    cpu->eax = lift_load32(cpu->edx + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->esi)) goto label_00037F34;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00037F20: cpu->eip = LIFT_CODE_TOKEN_VA(0x437F20u);
    cpu->ecx = g_sfera_mbc_runtime->named_vector_cursor;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->edx + ((uint32_t)(cpu->eax) * 4u), 0u);
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->esi)) goto label_00037F20;
    label_00037F34: cpu->eip = LIFT_CODE_TOKEN_VA(0x437F34u);
    cpu->ecx = g_sfera_mbc_runtime->named_vector_cursor;
    cpu->eax = (uint32_t)(cpu->esi + 1u);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    cpu->edi = g_sfera_mbc_runtime->named_vector_cursor;
    label_00037F46: cpu->eip = LIFT_CODE_TOKEN_VA(0x437F46u);
    cpu->edx = lift_load32(cpu->edi);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->esi) * 4u), cpu->eax);
    label_00037F4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x437F4Fu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437F60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437F60u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    cpu->edx = cpu->ecx;
    cpu->ecx = g_sfera_mbc_runtime->named_vector_count;
    lift_push32(cpu, cpu->edi);
    cpu->ebp = 0u;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->named_vectors[0];
    g_sfera_mbc_runtime->named_vector_cursor = (uint32_t)(cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_00037FBE;
    label_00037F82: cpu->eip = LIFT_CODE_TOKEN_VA(0x437F82u);
    cpu->esi = lift_load32(cpu->edi + 0xCu);
    cpu->eax = cpu->edx;
    label_00037F87: cpu->eip = LIFT_CODE_TOKEN_VA(0x437F87u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->ebx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->esi)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037FA7;
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_00037FA3;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->ebx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->esi + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00037FA7;
    cpu->eax += 2u;
    cpu->esi += 2u;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != 0u) goto label_00037F87;
    label_00037FA3: cpu->eip = LIFT_CODE_TOKEN_VA(0x437FA3u);
    cpu->eax = 0u;
    goto label_00037FAC;
    label_00037FA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x437FA7u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_00037FAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x437FACu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00037FC6;
    ++cpu->ebp;
    cpu->edi += 0x10u;
    g_sfera_mbc_runtime->named_vector_cursor = (uint32_t)(cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(cpu->ecx)) goto label_00037F82;
    label_00037FBE: cpu->eip = LIFT_CODE_TOKEN_VA(0x437FBEu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00037FC6: cpu->eip = LIFT_CODE_TOKEN_VA(0x437FC6u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00037FD7;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00037FD7: cpu->eip = LIFT_CODE_TOKEN_VA(0x437FD7u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->edi + 4u))) goto label_00037FBE;
    cpu->ecx = lift_load32(cpu->edi);
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00437FF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x437FF0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0xB0u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00038020;
    lift_push32(cpu, 0x3822u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = 0x80u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x438015u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xB0u, cpu->eax);
    lift_store8(cpu->eax, 0u);
    goto label_00038024;
    label_00038020: cpu->eip = LIFT_CODE_TOKEN_VA(0x438020u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    label_00038024: cpu->eip = LIFT_CODE_TOKEN_VA(0x438024u);
    cpu->ecx = cpu->ebp;
    cpu->esi = (uint32_t)(cpu->ecx + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00038030: cpu->eip = LIFT_CODE_TOKEN_VA(0x438030u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00038030;
    cpu->ecx -= cpu->esi;
    cpu->esi = cpu->ecx;
    cpu->ecx = cpu->eax;
    cpu->edi = (uint32_t)(cpu->ecx + 1u);
    label_00038040: cpu->eip = LIFT_CODE_TOKEN_VA(0x438040u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00038040;
    cpu->ecx -= cpu->edi;
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->esi + 4u);
    if ((int32_t)(uint32_t)(cpu->ecx) > (int32_t)(uint32_t)(0x7Fu)) goto label_00038098;
    cpu->ecx = (uint32_t)(cpu->eax + 0xFFFFFFFFu);
    label_00038055: cpu->eip = LIFT_CODE_TOKEN_VA(0x438055u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + 1u)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00038055;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x0A0D)) & 0xFFFFu);
    lift_store16(cpu->ecx, cpu->edx & 0xFFFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"\r\n") + 2u)) & 0xFFu);
    lift_store8(cpu->ecx + 2u, cpu->edx & 0xFFu);
    cpu->ecx = cpu->ebp;
    cpu->esi = cpu->ebp;
    label_00038074: cpu->eip = LIFT_CODE_TOKEN_VA(0x438074u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00038074;
    cpu->ecx -= cpu->esi;
    cpu->edx = cpu->ecx;
    cpu->edi = (uint32_t)(cpu->eax + 0xFFFFFFFFu);
    label_00038082: cpu->eip = LIFT_CODE_TOKEN_VA(0x438082u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->eax & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00038082;
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->edx;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    label_00038098: cpu->eip = LIFT_CODE_TOKEN_VA(0x438098u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004380A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4380A0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ecx;
    cpu->esi = cpu->ebp;
    lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->eax + 4u);
    cpu->esi -= cpu->eax;
    cpu->edi = 0x96u;
    label_000380B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4380B5u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + cpu->edx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->ecx & 0xFFu);
    ++cpu->edx;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000380B5;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp + 0x9Au)) & 0xFFu);
    lift_store8(cpu->eax + 0x9Au, cpu->edx & 0xFFu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x9Cu));
    lift_store_f32(cpu->eax + 0x9Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xA0u));
    cpu->esi = lift_pop32(cpu);
    lift_store_f32(cpu->eax + 0xA0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xA4u));
    cpu->ebp = lift_pop32(cpu);
    lift_store_f32(cpu->eax + 0xA4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00438100(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x438100u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFF9u)) goto label_0003811B;
    lift_push32(cpu, (uint32_t)(uintptr_t)"~~~~~ItemList~~~FIND ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x438114u); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0003811B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43811Bu);
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0003813F;
    cpu->ecx = lift_load32(cpu->ecx + 0xD0u);
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xD4u);
    cpu->edx = (uint32_t)(cpu->eax + cpu->ecx + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)" FindItem 'OK' = ''%s''\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43813Cu); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_0003813F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43813Fu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_00038151;
    lift_push32(cpu, (uint32_t)(uintptr_t)" FindItem = 'ERROR'\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43814Eu); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00038151: cpu->eip = LIFT_CODE_TOKEN_VA(0x438151u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00438160(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x438160u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFF9u)) goto label_0003817B;
    lift_push32(cpu, (uint32_t)(uintptr_t)"~~~~~ItemList~~~FIND NEXT ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x438174u); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0003817B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43817Bu);
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_0003819F;
    cpu->ecx = lift_load32(cpu->ecx + 0xD0u);
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1BCu);
    cpu->edx = (uint32_t)(cpu->eax + cpu->ecx + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)" FindNextItem 'OK' = ''%s''\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43819Cu); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_0003819F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43819Fu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_000381B1;
    lift_push32(cpu, (uint32_t)(uintptr_t)" FindNextItem = 'ERROR'\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4381AEu); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000381B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4381B1u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004381C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4381C0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFF9u)) goto label_000381DB;
    lift_push32(cpu, (uint32_t)(uintptr_t)"~~~~~ItemList~~~FIND ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4381D4u); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000381DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4381DBu);
    if ((int32_t)(uint32_t)(cpu->esi) < 0) goto label_000381FF;
    cpu->ecx = lift_load32(cpu->ecx + 0xD0u);
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1BCu);
    cpu->edx = (uint32_t)(cpu->eax + cpu->ecx + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)" FindItem 'OK' = ''%s''\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4381FCu); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_000381FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4381FFu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_00038211;
    lift_push32(cpu, (uint32_t)(uintptr_t)" FindItem = 'ERROR'\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43820Eu); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00038211: cpu->eip = LIFT_CODE_TOKEN_VA(0x438211u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00438220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x438220u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->edi);
    lift_store16(cpu->ecx + 0x42u, cpu->eax & 0xFFFFu);
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00038271;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x1Cu)) & 0xFFu);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00038240: cpu->eip = LIFT_CODE_TOKEN_VA(0x438240u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + cpu->edi)) & 0xFFu);
    { uint64_t v=(uint64_t)((cpu->ebx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00038250;
    cpu->edx = cpu->edx & 0xFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(g_sfera_string_lookup_runtime.case_fold[(uint8_t)cpu->edx]) & 0xFFu);
    label_00038250: cpu->eip = LIFT_CODE_TOKEN_VA(0x438250u);
    cpu->ebp = lift_load32(cpu->ecx + 0x10u);
    lift_store8(cpu->eax + cpu->ebp, cpu->edx & 0xFFu);
    cpu->ebp = (cpu->ebp & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->ecx + 0x42u)) & 0xFFFFu);
    cpu->edx = cpu->edx & 0xFFu;
    cpu->ebp = (cpu->ebp & 0xFFFF0000u) | ((uint32_t)(lift_shift_right(cpu, (cpu->ebp & 0xFFFFu), (uint32_t)(1u), 16u)) & 0xFFFFu);
    cpu->ebp = (cpu->ebp & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->ebp & 0xFFFFu)) + (uint64_t)(g_sfera_string_lookup_runtime.hash_mix[(uint8_t)cpu->edx]) + (uint64_t)(0u))) & 0xFFFFu);
    ++cpu->eax;
    lift_store16(cpu->ecx + 0x42u, cpu->ebp & 0xFFFFu);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->esi)) goto label_00038240;
    label_00038271: cpu->eip = LIFT_CODE_TOKEN_VA(0x438271u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->ecx + 0x20u)) & 0xFFFFu);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFFFu)) - 1u)) & 0xFFFFu);
    lift_store16(cpu->ecx + 0x42u, (uint64_t)(lift_load16(cpu->ecx + 0x42u)) & (uint64_t)((cpu->eax & 0xFFFFu)));
    cpu->edx = lift_load16(cpu->ecx + 0x42u);
    cpu->eax = lift_load32(cpu->ecx + 0x18u);
    cpu->eax = lift_load16(cpu->eax + ((uint32_t)(cpu->edx) * 2u));
    cpu->edx = lift_load16(cpu->ecx + 0x1Cu);
    lift_store16(cpu->ecx + 0x34u, cpu->eax & 0xFFFFu);
    if ((uint16_t)((cpu->eax & 0xFFFFu)) == (uint16_t)((cpu->edx & 0xFFFFu))) goto label_00038375;
    cpu->ebx = lift_load32(cpu->ecx + 8u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ebx);
    cpu->eax += lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->ecx + 0x3Cu, 0u);
    lift_store32(cpu->ecx + 0x38u, cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->eax + 8u)) & 0xFFFFu);
    lift_store16(cpu->ecx + 0x40u, cpu->eax & 0xFFFFu);
    label_000382B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4382B2u);
    cpu->ebp = lift_load32(cpu->ecx + 0x38u);
    if ((uint32_t)(lift_load32(cpu->ebp + 4u)) != (uint32_t)(cpu->esi)) goto label_0003830C;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x18u)), r=(uint64_t)(4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = cpu->esi;
    cpu->esi = lift_load32(cpu->ecx + 0x10u);
    cpu->edi = (uint32_t)(cpu->ebp + 0xAu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000382E4;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000382D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4382D0u);
    cpu->edx = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esi))) goto label_00038308;
    cpu->eax -= 4u;
    cpu->esi += 4u;
    cpu->edi += 4u;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(4u)) goto label_000382D0;
    label_000382E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4382E4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0003833A;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(lift_load8(cpu->edi))) goto label_00038308;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(1u)) goto label_0003833A;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(lift_load8(cpu->edi + 1u))) goto label_00038308;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(2u)) goto label_0003833A;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 2u)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(lift_load8(cpu->edi + 2u))) goto label_0003833A;
    label_00038308: cpu->eip = LIFT_CODE_TOKEN_VA(0x438308u);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    label_0003830C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43830Cu);
    cpu->edx = lift_load16(cpu->ecx + 0x40u);
    cpu->eax = lift_load16(cpu->ecx + 0x1Cu);
    if ((uint16_t)((cpu->edx & 0xFFFFu)) == (uint16_t)((cpu->eax & 0xFFFFu))) goto label_00038375;
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edi = cpu->edx;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(cpu->ebx);
    cpu->eax += cpu->edi;
    lift_store32(cpu->ecx + 0x3Cu, cpu->ebp);
    lift_store32(cpu->ecx + 0x38u, cpu->eax);
    lift_store16(cpu->ecx + 0x34u, cpu->edx & 0xFFFFu);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->eax + 8u)) & 0xFFFFu);
    lift_store16(cpu->ecx + 0x40u, cpu->edx & 0xFFFFu);
    goto label_000382B2;
    label_0003833A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43833Au);
    cpu->eax = lift_load32(cpu->ecx + 0x3Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0003836A;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->ebp + 8u)) & 0xFFFFu);
    lift_store16(cpu->eax + 8u, cpu->edx & 0xFFFFu);
    cpu->eax = lift_load16(cpu->ecx + 0x42u);
    cpu->edx = lift_load32(cpu->ecx + 0x18u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->edx + ((uint32_t)(cpu->eax) * 2u))) & 0xFFFFu);
    cpu->esi = lift_load32(cpu->ecx + 0x38u);
    lift_store16(cpu->esi + 8u, cpu->eax & 0xFFFFu);
    cpu->edx = lift_load16(cpu->ecx + 0x42u);
    cpu->eax = lift_load32(cpu->ecx + 0x18u);
    cpu->esi = (cpu->esi & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->ecx + 0x34u)) & 0xFFFFu);
    lift_store16(cpu->eax + ((uint32_t)(cpu->edx) * 2u), cpu->esi & 0xFFFFu);
    label_0003836A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43836Au);
    cpu->eax = lift_load16(cpu->ecx + 0x34u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_00038375: cpu->eip = LIFT_CODE_TOKEN_VA(0x438375u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00438380(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x438380u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFF9u)) goto label_00038399;
    lift_push32(cpu, (uint32_t)(uintptr_t)"~~~~~ItemList~~~DEL ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x438393u); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_return(cpu, 4u, stop_address); return;
    label_00038399: cpu->eip = LIFT_CODE_TOKEN_VA(0x438399u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000383BE;
    cpu->ecx = lift_load32(cpu->ecx + 0xD0u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xD4u);
    cpu->edx = (uint32_t)(cpu->eax + cpu->ecx + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)" DelItem 'OK' = ''%s''\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4383B8u); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
    label_000383BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4383BEu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000383D3;
    lift_push32(cpu, (uint32_t)(uintptr_t)" DelItem = CurItems Less Than CurMax\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4383CDu); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_return(cpu, 4u, stop_address); return;
    label_000383D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4383D3u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFEu)) goto label_000383E3;
    lift_push32(cpu, (uint32_t)(uintptr_t)" DelItem = 'ERROR' NOT DELETE\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4383E2u); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu);
    label_000383E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4383E3u);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004383F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4383F0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFF9u)) goto label_00038409;
    lift_push32(cpu, (uint32_t)(uintptr_t)"~~~~~ItemList~~~DEL ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x438403u); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_return(cpu, 4u, stop_address); return;
    label_00038409: cpu->eip = LIFT_CODE_TOKEN_VA(0x438409u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0003842E;
    cpu->ecx = lift_load32(cpu->ecx + 0xD0u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1BCu);
    cpu->edx = (uint32_t)(cpu->eax + cpu->ecx + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)" DelItem 'OK' = ''%s''\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x438428u); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
    label_0003842E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43842Eu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_00038443;
    lift_push32(cpu, (uint32_t)(uintptr_t)" DelItem = CurItems Less Than CurMax\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43843Du); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_return(cpu, 4u, stop_address); return;
    label_00038443: cpu->eip = LIFT_CODE_TOKEN_VA(0x438443u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFEu)) goto label_00038453;
    lift_push32(cpu, (uint32_t)(uintptr_t)" DelItem = 'ERROR' NOT DELETE\n");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x438452u); lift_push32(cpu, r); sfera_sub_0044BF90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu);
    label_00038453: cpu->eip = LIFT_CODE_TOKEN_VA(0x438453u);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00438460(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x438460u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = 1u;
    if ((uint8_t)(((*(uint8_t*)(void*)&g_sfera_cursor_manager_runtime.initialized_flags)) & ((cpu->eax & 0xFFu))) != 0u) goto label_000384BA;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_cursor_manager_runtime.initialized_flags, (uint64_t)(g_sfera_cursor_manager_runtime.initialized_flags) | (uint64_t)(cpu->eax));
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_cursor_manager_runtime.object[0];
    lift_store32(cpu->esp + 0xCu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4384A5u); lift_push32(cpu, r); sfera_sub_004D79F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004FA360));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4384AFu); lift_push32(cpu, r); sfera_sub_004EE8C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, 0xFFFFFFFFu);
    label_000384BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4384BAu);
    cpu->eax = g_sfera_cursor_manager_runtime.active_cursor;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000384D2;
    cpu->ecx = (uint32_t)(uintptr_t)"CCursorManager::GetActiveCursor(): attempt to retrieve current cursor while one is not set";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4384CDu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_cursor_manager_runtime.active_cursor;
    label_000384D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4384D2u);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004384F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4384F0u);
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
            { uint32_t r=LIFT_CODE_TOKEN_VA(0x43852Cu); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
            g_sfera_mbc_runtime->registered_objects[object_index] = 0u;
        }
    }
    { uint64_t l=(uint64_t)(g_sfera_inter_scalar_runtime.mode_02), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    g_sfera_mbc_runtime->registered_object_count = (uint32_t)(0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00038579;
    cpu->edx = 0x1CBu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43855Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_02;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00038579;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x438570u); lift_push32(cpu, r); sfera_sub_00430BC0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x438576u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00038579: cpu->eip = LIFT_CODE_TOKEN_VA(0x438579u);
    cpu->edx = 0x1CDu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x438588u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x20018u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x438592u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000385B7;
    lift_push32(cpu, 0x834u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0x14u);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4385B5u); lift_push32(cpu, r); sfera_sub_00430F60(cpu,r); if (cpu->eip != r) return; }
    goto label_000385B9;
    label_000385B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4385B7u);
    cpu->eax = 0u;
    label_000385B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4385B9u);
    g_sfera_inter_scalar_runtime.mode_02 = (uint32_t)(cpu->eax);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004385D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4385D0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4385D8u); lift_push32(cpu, r); sfera_sub_00434D90(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"\n---exit_inter start---\nMBINTER MESSAGE:";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4385E2u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4385E9u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"\n";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4385F3u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4385FDu); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"---exit_inter end-----\n";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x438607u); lift_push32(cpu, r); sfera_sub_0044BF50(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->process_index), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    g_sfera_mbc_runtime->execution_failed = (uint32_t)(1u);
    cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00038625;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x38625u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00038625: cpu->eip = LIFT_CODE_TOKEN_VA(0x438625u);
    cpu->edx = (uint32_t)(uintptr_t)"EError";
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0];
    sfera_sub_00435020(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00438640(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x438640u);
    cpu->esp -= 0x104u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    cpu->eax = cpu->ecx;
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edx -= cpu->eax;
    label_00038660: cpu->eip = LIFT_CODE_TOKEN_VA(0x438660u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00038660;
    cpu->eax = cpu->esi;
    cpu->edx = cpu->esi;
    cpu->edi = cpu->edi;
    label_00038670: cpu->eip = LIFT_CODE_TOKEN_VA(0x438670u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00038670;
    cpu->edi = (uint32_t)(cpu->esp + 8u);
    cpu->eax -= cpu->edx;
    --cpu->edi;
    cpu->edi = cpu->edi;
    label_00038680: cpu->eip = LIFT_CODE_TOKEN_VA(0x438680u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00038680;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43869Fu); lift_push32(cpu, r); sfera_sub_004385D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x104u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004386C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4386C0u);
    cpu->esp -= 0x3D8u;
    cpu->edx = (uint32_t)(cpu->esp + 0x394u);
    cpu->edx -= cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000386E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4386E0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx + cpu->ecx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000386E0;
    cpu->eax = (uint32_t)(cpu->esp + 0x394u);
    --cpu->eax;
    label_000386F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4386F2u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000386F2;
    cpu->ecx = 0x63626D2Eu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, cpu->edx & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x394u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00038715: cpu->eip = LIFT_CODE_TOKEN_VA(0x438715u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00038715;
    cpu->eax -= cpu->edx;
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x24u)) goto label_0003873B;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0x3D8u;
    lift_return(cpu, 0u, stop_address); return;
    label_0003873B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43873Bu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_inter_scalar_runtime.state_03;
    cpu->edx = (uint32_t)(cpu->esp + 0x3A8u);
    cpu->ebp = 0u;
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x48u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x438761u); lift_push32(cpu, r); sfera_sub_00489EF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->ebp)) goto label_0003960B;
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0x10u)) goto label_0003960B;
    cpu->eax = 0u;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00038780: cpu->eip = LIFT_CODE_TOKEN_VA(0x438780u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + cpu->eax + 0x3A0u)) & 0xFFu);
    lift_store8(cpu->esp + cpu->eax + 0x54u, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00038780;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0x10u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000388B1;
    cpu->edi = (uint32_t)(cpu->esi + 0x10u);
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_000387BA;
    label_000387AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4387ABu);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4387B2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4387B7u);
    cpu->esp += 0xCu;
    label_000387BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4387BAu);
    cpu->eax = lift_load8(cpu->esp + 0x54u);
    cpu->edx = lift_load8(cpu->esp + 0x56u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->ebx += cpu->edi;
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 2u) + 0xFFFFFDF0u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000388BB;
    cpu->edi = (uint32_t)(cpu->esi + 4u);
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_00038800;
    label_000387EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4387EEu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x8Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4387F8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4387FDu);
    cpu->esp += 0xCu;
    label_00038800: cpu->eip = LIFT_CODE_TOKEN_VA(0x438800u);
    cpu->ebx += cpu->edi;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000388C5;
    cpu->edi = (uint32_t)(cpu->esi + 4u);
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0003882E;
    label_0003881C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43881Cu);
    lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->esp + 0x90u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438826u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43882Bu);
    cpu->esp += 0xCu;
    label_0003882E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43882Eu);
    cpu->ebx += cpu->edi;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000388CF;
    cpu->edi = (uint32_t)(cpu->esi + 4u);
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0003885C;
    label_0003884A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43884Au);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x98u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438854u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x438859u);
    cpu->esp += 0xCu;
    label_0003885C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43885Cu);
    cpu->ebx += cpu->edi;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000388D9;
    cpu->esi += 4u;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_00038884;
    label_00038872: cpu->eip = LIFT_CODE_TOKEN_VA(0x438872u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0xA0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43887Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x438881u);
    cpu->esp += 0xCu;
    label_00038884: cpu->eip = LIFT_CODE_TOKEN_VA(0x438884u);
    cpu->edi = g_sfera_mbc_runtime->process_index;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x348u);
    cpu->ebx += cpu->esi;
    cpu->edi += ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0]);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    cpu->eax = 0u;
    cpu->ecx = (uint32_t)(cpu->edi + 0x30u);
    label_000388A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4388A1u);
    if ((uint16_t)(lift_load16(cpu->ecx)) == (uint16_t)((cpu->ebp & 0xFFFFu))) goto label_000388E0;
    ++cpu->eax;
    cpu->ecx += 2u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(8u)) goto label_000388A1;
    goto label_000388EA;
    label_000388B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4388B1u);
    cpu->edi = 0x10u;
    goto label_000387AB;
    label_000388BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4388BBu);
    cpu->edi = 4u;
    goto label_000387EE;
    label_000388C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4388C5u);
    cpu->edi = 4u;
    goto label_0003881C;
    label_000388CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4388CFu);
    cpu->edi = 4u;
    goto label_0003884A;
    label_000388D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4388D9u);
    cpu->esi = 4u;
    goto label_00038872;
    label_000388E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4388E0u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x40u)) & 0xFFFFu);
    lift_store16(cpu->edi + ((uint32_t)(cpu->eax) * 2u) + (uint32_t)offsetof(SferaMbcProcessRecord, module_key), cpu->edx & 0xFFFFu);
    label_000388EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4388EAu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(8u)) goto label_00038919;
    cpu->edx = (uint32_t)(cpu->esp + 0x58u);
    cpu->ecx = (uint32_t)(uintptr_t)"Cannot link a process - increase MAX_LINKED_PRCS! Linked prc: ";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4388FDu); lift_push32(cpu, r); sfera_sub_00438640(cpu,r); if (cpu->eip != r) return; }
    cpu->eax |= 0xFFFFFFFFu;
    label_00038900: cpu->eip = LIFT_CODE_TOKEN_VA(0x438900u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x3D8u;
    lift_return(cpu, 0u, stop_address); return;
    label_00038919: cpu->eip = LIFT_CODE_TOKEN_VA(0x438919u);
    cpu->esi = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_size));
    cpu->eax = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size));
    cpu->ecx = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x80000003u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038932;
    --cpu->ecx;
    cpu->ecx |= 0xFFFFFFFCu;
    ++cpu->ecx;
    label_00038932: cpu->eip = LIFT_CODE_TOKEN_VA(0x438932u);
    cpu->edx = 4u;
    cpu->edx -= cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x80000003u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038946;
    --cpu->edx;
    cpu->edx |= 0xFFFFFFFCu;
    ++cpu->edx;
    label_00038946: cpu->eip = LIFT_CODE_TOKEN_VA(0x438946u);
    cpu->eax = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base));
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx -= cpu->eax;
    lift_store32(cpu->esp + 0x30u, cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->current_instruction_address;
    cpu->ecx -= cpu->eax;
    cpu->eax = lift_load16(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count));
    cpu->esi += cpu->edx;
    lift_store32(cpu->esp + 0x3Cu, cpu->esi);
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    if ((int16_t)(uint16_t)((cpu->eax & 0xFFFFu)) >= (int16_t)(uint16_t)(8u)) goto label_000389C0;
    cpu->ecx = lift_load32(cpu->esp + 0x94u);
    cpu->eax = (int32_t)(int16_t)cpu->eax;
    lift_store32(cpu->edi + ((uint32_t)(cpu->eax) * 4u) + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_size), cpu->ecx);
    cpu->edx = (int16_t)(lift_load16(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count)));
    cpu->eax = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size));
    lift_store32(cpu->edi + ((uint32_t)(cpu->edx) * 4u) + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_begin), cpu->eax);
    cpu->ecx = (int16_t)(lift_load16(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count)));
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x8Cu)) & 0xFFFFu);
    lift_store16(cpu->edi + ((uint32_t)(cpu->ecx) * 2u) + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_ids), cpu->edx & 0xFFFFu);
    cpu->eax = (int16_t)(lift_load16(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count)));
    lift_store32(cpu->edi + ((uint32_t)(cpu->eax) * 4u) + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_memory_offset), cpu->esi);
    { uint64_t l=(uint64_t)(lift_load16(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count))), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,16u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store16(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, code_range_count), v); }
    label_000389C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4389C0u);
    cpu->ecx = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    cpu->eax = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, module_key) + 4u);
    cpu->edx = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, module_key));
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, module_key) + 8u);
    lift_store32(cpu->esp + 0x394u, cpu->eax);
    lift_store32(cpu->esp + 0x390u, cpu->edx);
    cpu->edx = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, module_key) + 0xCu);
    lift_push32(cpu, 0x14u);
    cpu->eax = (uint32_t)(cpu->esp + 0x394u);
    lift_store32(cpu->esp + 0x39Cu, cpu->ecx);
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_02;
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x3A4u, cpu->edx);
    lift_store32(cpu->esp + 0x3A8u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x438A0Bu); lift_push32(cpu, r); sfera_sub_00430F40(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00038A24;
    cpu->ebp = g_sfera_mbc_runtime->registered_objects[cpu->eax];
    lift_store32(cpu->esp + 0x38u, cpu->ebp);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_00038A24;
    lift_store32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base), cpu->ebp);
    goto label_00038A66;
    label_00038A24: cpu->eip = LIFT_CODE_TOKEN_VA(0x438A24u);
    cpu->ecx = lift_load32(cpu->esp + 0x94u);
    cpu->ecx += lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, 0xCD7u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x438A3Eu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base));
    cpu->ebp = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438A4Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x438A4Fu);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, module_key));
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x438A5Du); lift_push32(cpu, r); sfera_sub_00433C00(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base), cpu->ebp);
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x38u, cpu->ebp);
    label_00038A66: cpu->eip = LIFT_CODE_TOKEN_VA(0x438A66u);
    cpu->ebx = lift_load32(cpu->esp + 0x9Cu);
    cpu->ecx = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    lift_push32(cpu, 0xCE3u);
    cpu->ebx += cpu->esi;
    lift_push32(cpu, (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp");
    cpu->edx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x438A83u); lift_push32(cpu, r); sfera_sub_004EBE80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base));
    cpu->ecx += lift_load32(cpu->esp + 0x28u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base), cpu->eax);
    cpu->eax += cpu->esi;
    cpu->esi = lift_load32(cpu->esp + 0x94u);
    lift_store32(cpu->esp + 0x90u, cpu->ecx);
    lift_store32(cpu->esp + 0x98u, cpu->eax);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_00038AC3;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038ABB;
    cpu->eax = (uint32_t)(cpu->esi + cpu->edx);
    cpu->edx = 0u;
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    goto label_00038AF3;
    label_00038ABB: cpu->eip = LIFT_CODE_TOKEN_VA(0x438ABBu);
    cpu->eax = cpu->esi;
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    goto label_00038AF3;
    label_00038AC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x438AC3u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038AD6;
    cpu->ebp = (uint32_t)(cpu->esi + cpu->edx);
    cpu->edx = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    goto label_00038AD8;
    label_00038AD6: cpu->eip = LIFT_CODE_TOKEN_VA(0x438AD6u);
    cpu->ebp = cpu->esi;
    label_00038AD8: cpu->eip = LIFT_CODE_TOKEN_VA(0x438AD8u);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00038AEF;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438AE3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x438AE8u);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->esp += 0xCu;
    label_00038AEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x438AEFu);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u));
    label_00038AF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x438AF3u);
    cpu->ecx = lift_load32(cpu->esp + 0x9Cu);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038B0D;
    cpu->ebp = (uint32_t)(cpu->ecx + cpu->edx);
    cpu->edx = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    goto label_00038B0F;
    label_00038B0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x438B0Du);
    cpu->ebp = cpu->ecx;
    label_00038B0F: cpu->eip = LIFT_CODE_TOKEN_VA(0x438B0Fu);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00038B34;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->esp + 0x98u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438B21u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x438B26u);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = lift_load32(cpu->esp + 0xA8u);
    cpu->esp += 0xCu;
    label_00038B34: cpu->eip = LIFT_CODE_TOKEN_VA(0x438B34u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size))), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); lift_store32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_size), v); }
    cpu->eax = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base));
    cpu->esi = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u));
    cpu->esi += cpu->eax;
    g_sfera_mbc_runtime->bytecode_base = (uint32_t)(cpu->eax);
    cpu->eax += lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_size), cpu->ebx);
    g_sfera_mbc_runtime->current_instruction_address = (uint32_t)(cpu->eax);
    cpu->eax = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    g_sfera_mbc_runtime->process_memory_base = (uint32_t)(cpu->eax);
    cpu->eax = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, module_tag));
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->esi);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00038B74;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    g_sfera_mbc_module_memory_stats[cpu->eax / 3u].process_memory_bytes += cpu->ecx;
    label_00038B74: cpu->eip = LIFT_CODE_TOKEN_VA(0x438B74u);
    cpu->esi = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entries));
    if ((uint32_t)(cpu->esi) == 0u) goto label_00038BDC;
    cpu->ebx = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entry_count))), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00038BDC;
    cpu->ebp = lift_load32(cpu->esp + 0x20u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00038B90: cpu->eip = LIFT_CODE_TOKEN_VA(0x438B90u);
    if ((uint32_t)(lift_load32(cpu->esi + 4u)) != (uint32_t)(3u)) goto label_00038BCC;
    lift_push32(cpu, (uintptr_t)"prc_link - memory allocation found in base process, pointer corruption quite possible."); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x438BA5u); lift_push32(cpu, r); sfera_sub_0049B790(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = cpu->ebp;
    cpu->eax += cpu->edx;
    cpu->ecx -= cpu->edx;
    cpu->edx = lift_load32(cpu->eax);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->edx) == 0u) goto label_00038BCC;
    cpu->edx += cpu->ecx;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->edx) == 0u) goto label_00038BCC;
    cpu->edx += cpu->ecx;
    lift_store32(cpu->eax + 8u, (uint64_t)(lift_load32(cpu->eax + 8u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    lift_store32(cpu->eax + 4u, cpu->edx);
    label_00038BCC: cpu->eip = LIFT_CODE_TOKEN_VA(0x438BCCu);
    ++cpu->ebx;
    cpu->esi += 8u;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, cleanup_entry_count))), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00038B90;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    label_00038BDC: cpu->eip = LIFT_CODE_TOKEN_VA(0x438BDCu);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038CE1;
    cpu->esi = (uint32_t)(cpu->edx + 4u);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00038C0E;
    label_00038BF8: cpu->eip = LIFT_CODE_TOKEN_VA(0x438BF8u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xA8u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438C06u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x438C0Bu);
    cpu->esp += 0xCu;
    label_00038C0E: cpu->eip = LIFT_CODE_TOKEN_VA(0x438C0Eu);
    cpu->ebx = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, program_count));
    cpu->ebp = lift_load32(cpu->esp + 0xA0u);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(cpu->esi) + (uint64_t)(0u));
    cpu->ecx = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->esi = (uint32_t)(cpu->ebx + cpu->ebp);
    cpu->edx = cpu->esi;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xA4u);
    lift_push32(cpu, 0xD11u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp");
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x3Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x24u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x438C45u); lift_push32(cpu, r); sfera_sub_004EBE80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->ebx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xA4u);
    lift_store32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base), cpu->eax);
    lift_store32(cpu->esp + 0x30u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00038DDA;
    cpu->esi = (uint32_t)(cpu->eax + cpu->ecx + 0x2Cu);
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    label_00038C64: cpu->eip = LIFT_CODE_TOKEN_VA(0x438C64u);
    cpu->ebx = (uint32_t)(cpu->esi + 0xFFFFFFD4u);
    label_00038C70: cpu->eip = LIFT_CODE_TOKEN_VA(0x438C70u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x10u, v); }
    lift_store8(cpu->esp + 0x1Bu, cpu->eax & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038CEB;
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    ++cpu->ebp;
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00038CA4;
    label_00038C8D: cpu->eip = LIFT_CODE_TOKEN_VA(0x438C8Du);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x23u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438C98u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x438C9Du);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x27u)) & 0xFFu);
    cpu->esp += 0xCu;
    label_00038CA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x438CA4u);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u));
    lift_store8(cpu->ebx, cpu->eax & 0xFFu);
    ++cpu->ebx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00038C70;
    cpu->ebp = 4u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038CCD;
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->ebp += 4u;
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00038CF2;
    label_00038CCD: cpu->eip = LIFT_CODE_TOKEN_VA(0x438CCDu);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFF8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438CD7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x438CDCu);
    cpu->esp += 0xCu;
    goto label_00038CF6;
    label_00038CE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x438CE1u);
    cpu->esi = 4u;
    goto label_00038BF8;
    label_00038CEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x438CEBu);
    cpu->ebp = 1u;
    goto label_00038C8D;
    label_00038CF2: cpu->eip = LIFT_CODE_TOKEN_VA(0x438CF2u);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    label_00038CF6: cpu->eip = LIFT_CODE_TOKEN_VA(0x438CF6u);
    cpu->ebx += cpu->ebp;
    cpu->ebp = 4u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038D16;
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->ebp += 4u;
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00038D24;
    label_00038D16: cpu->eip = LIFT_CODE_TOKEN_VA(0x438D16u);
    lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->esi + 0xFFFFFFFCu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438D1Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x438D21u);
    cpu->esp += 0xCu;
    label_00038D24: cpu->eip = LIFT_CODE_TOKEN_VA(0x438D24u);
    cpu->ebx += cpu->ebp;
    cpu->ebp = 1u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038D42;
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    ++cpu->ebp;
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00038D4D;
    label_00038D42: cpu->eip = LIFT_CODE_TOKEN_VA(0x438D42u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438D45u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x438D4Au);
    cpu->esp += 0xCu;
    label_00038D4D: cpu->eip = LIFT_CODE_TOKEN_VA(0x438D4Du);
    cpu->ebx += cpu->ebp;
    cpu->ebp = 1u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038D6B;
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    ++cpu->ebp;
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00038D79;
    label_00038D6B: cpu->eip = LIFT_CODE_TOKEN_VA(0x438D6Bu);
    lift_push32(cpu, cpu->ebp);
    cpu->eax = (uint32_t)(cpu->esi + 1u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438D71u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x438D76u);
    cpu->esp += 0xCu;
    label_00038D79: cpu->eip = LIFT_CODE_TOKEN_VA(0x438D79u);
    cpu->ebx += cpu->ebp;
    cpu->ebp = 4u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038D99;
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->ebp += 4u;
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00038DA7;
    label_00038D99: cpu->eip = LIFT_CODE_TOKEN_VA(0x438D99u);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438D9Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x438DA4u);
    cpu->esp += 0xCu;
    label_00038DA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x438DA7u);
    lift_store8(cpu->esi + 0x58u, 0u);
    lift_store8(cpu->esi + 0x68u, 0u);
    cpu->edx = lift_load32(cpu->esi + 0xFFFFFFF8u);
    lift_store32(cpu->esi + 0x5Cu, cpu->edx);
    cpu->ebx += cpu->ebp;
    lift_store32(cpu->esi + 0x6Cu, 0xFFFFFFFFu);
    cpu->esi += 0xA4u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x20u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x20u, v); }
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00038C64;
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    label_00038DDA: cpu->eip = LIFT_CODE_TOKEN_VA(0x438DDAu);
    cpu->ebx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(cpu->esi)) goto label_00038E9C;
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    label_00038DF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x438DF0u);
    cpu->eax = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    lift_store32(cpu->eax + cpu->esi + 0x88u, (uint64_t)(lift_load32(cpu->eax + cpu->esi + 0x88u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    cpu->edx = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    lift_store32(cpu->edx + cpu->esi + 0x24u, (uint64_t)(lift_load32(cpu->edx + cpu->esi + 0x24u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    cpu->eax = (uint32_t)(cpu->eax + cpu->esi + 0x88u);
    cpu->eax = (uint32_t)(cpu->edx + cpu->esi + 0x24u);
    cpu->eax = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    lift_store32(cpu->eax + cpu->esi + 0x28u, (uint64_t)(lift_load32(cpu->eax + cpu->esi + 0x28u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    cpu->eax = (uint32_t)(cpu->eax + cpu->esi + 0x28u);
    cpu->eax = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    if ((uint8_t)(lift_load8(cpu->eax + cpu->esi + 0x2Cu)) != (uint8_t)(1u)) goto label_00038E87;
    cpu->ecx = lift_load8(cpu->eax + cpu->esi + 0x2Du);
    cpu->ebp = (int16_t)(lift_load16(cpu->edi + ((uint32_t)(cpu->ecx) * 2u) + (uint32_t)offsetof(SferaMbcProcessRecord, program_map_b)));
    cpu->edx = cpu->ebx & 0xFFFFu;
    if ((int32_t)(uint32_t)(cpu->ebp) >= 0) goto label_00038E46;
    lift_store16(cpu->edi + ((uint32_t)(cpu->ecx) * 2u) + (uint32_t)offsetof(SferaMbcProcessRecord, program_map_b), cpu->edx & 0xFFFFu);
    lift_store16(cpu->edi + ((uint32_t)(cpu->ecx) * 2u) + (uint32_t)offsetof(SferaMbcProcessRecord, program_map_a), cpu->edx & 0xFFFFu);
    lift_store16(cpu->eax + cpu->esi + 0x9Cu, cpu->edx & 0xFFFFu);
    goto label_00038E67;
    label_00038E46: cpu->eip = LIFT_CODE_TOKEN_VA(0x438E46u);
    cpu->ebx = cpu->ebp;
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0xA4u);
    lift_store16(cpu->ebx + cpu->eax + 0x9Eu, cpu->edx & 0xFFFFu);
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    lift_store16(cpu->eax + cpu->esi + 0x9Cu, cpu->ebp & 0xFFFFu);
    lift_store16(cpu->edi + ((uint32_t)(cpu->ecx) * 2u) + (uint32_t)offsetof(SferaMbcProcessRecord, program_map_b), cpu->edx & 0xFFFFu);
    label_00038E67: cpu->eip = LIFT_CODE_TOKEN_VA(0x438E67u);
    lift_store16(cpu->eax + cpu->esi + 0x9Eu, cpu->edx & 0xFFFFu);
    cpu->ecx = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, process_id));
    cpu->edx = cpu->edi;
    lift_store8(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, state_byte_b8), 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x438E83u); lift_push32(cpu, r); sfera_sub_00433CF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    label_00038E87: cpu->eip = LIFT_CODE_TOKEN_VA(0x438E87u);
    ++cpu->ebx;
    cpu->esi += 0xA4u;
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_00038DF0;
    label_00038E9C: cpu->eip = LIFT_CODE_TOKEN_VA(0x438E9Cu);
    cpu->edx = g_sfera_mbc_runtime->program_index;
    cpu->eax = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xA4u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx += cpu->eax;
    cpu->esi = 4u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    lift_store32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, program_count), cpu->ecx);
    g_sfera_mbc_runtime->program_table_base = (uint32_t)(cpu->eax);
    g_sfera_mbc_runtime->active_program_record = (uint32_t)(cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038EDD;
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->esi += 4u;
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00038EF3;
    label_00038EDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x438EDDu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xB4u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438EEBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x438EF0u);
    cpu->esp += 0xCu;
    label_00038EF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x438EF3u);
    cpu->ebx = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_count));
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(cpu->esi) + (uint64_t)(0u));
    cpu->esi = lift_load32(cpu->esp + 0xACu);
    cpu->ecx = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    cpu->ebp = (uint32_t)(cpu->esi + cpu->ebx);
    cpu->edx = cpu->ebp;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x34u);
    lift_push32(cpu, 0xD42u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp");
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x34u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x438F23u); lift_push32(cpu, r); sfera_sub_004EBE80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->ebx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x34u);
    lift_store32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table), cpu->eax);
    lift_store32(cpu->esp + 0x30u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00039040;
    cpu->edx = (uint32_t)(cpu->eax + cpu->ecx + 0x28u);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    label_00038F43: cpu->eip = LIFT_CODE_TOKEN_VA(0x438F43u);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    cpu->ebp += 0xFFFFFFD8u;
    cpu->edi = cpu->edi;
    label_00038F50: cpu->eip = LIFT_CODE_TOKEN_VA(0x438F50u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esi = 1u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    lift_store8(cpu->esp + 0x1Bu, cpu->eax & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00038F72;
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    ++cpu->esi;
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00038F85;
    label_00038F72: cpu->eip = LIFT_CODE_TOKEN_VA(0x438F72u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Fu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438F79u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x438F7Eu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x27u)) & 0xFFu);
    cpu->esp += 0xCu;
    label_00038F85: cpu->eip = LIFT_CODE_TOKEN_VA(0x438F85u);
    lift_store8(cpu->ebp, cpu->eax & 0xFFu);
    cpu->ebx += cpu->esi;
    ++cpu->ebp;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00038F50;
    cpu->ebp = 4u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000390C0;
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->esi += cpu->ebp;
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00038FC2;
    label_00038FB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x438FB0u);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx += 0xFFFFFFFCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438FBAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x438FBFu);
    cpu->esp += 0xCu;
    label_00038FC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x438FC2u);
    cpu->ebx += cpu->esi;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000390C7;
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->esi += cpu->ebp;
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00038FEF;
    label_00038FE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x438FE0u);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x438FE7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x438FECu);
    cpu->esp += 0xCu;
    label_00038FEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x438FEFu);
    cpu->ebx += cpu->esi;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000390CE;
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->esi += cpu->ebp;
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_0003901F;
    label_0003900D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43900Du);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi);
    cpu->eax += 4u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x439017u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43901Cu);
    cpu->esp += 0xCu;
    label_0003901F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43901Fu);
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + (uint64_t)(0x34u) + (uint64_t)(0u));
    cpu->ebx += cpu->esi;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x20u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x20u, v); }
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00038F43;
    cpu->ebp = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    cpu->ebx = lift_load32(cpu->esp + 0x24u);
    label_00039040: cpu->eip = LIFT_CODE_TOKEN_VA(0x439040u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x38u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_count), cpu->ebp);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000391DB;
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(cpu->ebp)) goto label_00039129;
    cpu->eax = cpu->ebp;
    cpu->eax -= cpu->ebx;
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    label_00039062: cpu->eip = LIFT_CODE_TOKEN_VA(0x439062u);
    cpu->edx = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax = (uint32_t)(cpu->edx + cpu->ecx + 0x24u);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->eax, (uint64_t)(lift_load32(cpu->eax)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    cpu->eax = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + cpu->ecx + 0x28u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (uint32_t)(cpu->eax + cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0003910B;
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x24u)) <= (int32_t)(uint32_t)(cpu->esi)) goto label_00039112;
    cpu->ebp = cpu->eax;
    label_00039092: cpu->eip = LIFT_CODE_TOKEN_VA(0x439092u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0x28u)) == (uint32_t)(0xFFFFFFFFu)) goto label_000390DE;
    cpu->ecx = cpu->ebp;
    cpu->eax = cpu->ebx;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000390A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4390A0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000390D5;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_000390BC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000390D5;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000390A0;
    label_000390BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4390BCu);
    cpu->eax = 0u;
    goto label_000390DA;
    label_000390C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4390C0u);
    cpu->esi = cpu->ebp;
    goto label_00038FB0;
    label_000390C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4390C7u);
    cpu->esi = cpu->ebp;
    goto label_00038FE0;
    label_000390CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4390CEu);
    cpu->esi = cpu->ebp;
    goto label_0003900D;
    label_000390D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4390D5u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_000390DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4390DAu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000390EA;
    label_000390DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4390DEu);
    ++cpu->esi;
    cpu->ebp += 0x34u;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x24u))) goto label_00039092;
    goto label_00039112;
    label_000390EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4390EAu);
    cpu->eax = lift_load32(cpu->ebx + 0x24u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x34u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base))), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_store8(cpu->eax, 0x47u);
    cpu->ecx = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    cpu->edx = lift_load32(cpu->esi + cpu->ecx + 0x24u);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx -= lift_load32(cpu->ecx + cpu->esi + 0x24u);
    --cpu->edx;
    lift_store32(cpu->eax + 1u, cpu->edx);
    goto label_00039112;
    label_0003910B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43910Bu);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->ebx + 0x28u, (uint64_t)(lift_load32(cpu->ebx + 0x28u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    label_00039112: cpu->eip = LIFT_CODE_TOKEN_VA(0x439112u);
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + (uint64_t)(0x34u) + (uint64_t)(0u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x20u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x20u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00039062;
    cpu->ebp = lift_load32(cpu->esp + 0x2Cu);
    cpu->ebx = lift_load32(cpu->esp + 0x24u);
    label_00039129: cpu->eip = LIFT_CODE_TOKEN_VA(0x439129u);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00039211;
    lift_store32(cpu->esp + 0x1Cu, 0u);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00039140: cpu->eip = LIFT_CODE_TOKEN_VA(0x439140u);
    cpu->eax = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx += cpu->eax;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + 0x28u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000391C6;
    cpu->esi = lift_load32(cpu->esp + 0x24u);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->ebp)) goto label_000391C6;
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    cpu->ebx = (uint32_t)(cpu->edx + cpu->eax);
    label_00039162: cpu->eip = LIFT_CODE_TOKEN_VA(0x439162u);
    if ((uint32_t)(lift_load32(cpu->ebx + 0x28u)) == (uint32_t)(0xFFFFFFFFu)) goto label_00039199;
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx = cpu->ebx;
    cpu->edi = cpu->edi;
    label_00039170: cpu->eip = LIFT_CODE_TOKEN_VA(0x439170u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00039190;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_0003918C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00039190;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00039170;
    label_0003918C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43918Cu);
    cpu->eax = 0u;
    goto label_00039195;
    label_00039190: cpu->eip = LIFT_CODE_TOKEN_VA(0x439190u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_00039195: cpu->eip = LIFT_CODE_TOKEN_VA(0x439195u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000391A3;
    label_00039199: cpu->eip = LIFT_CODE_TOKEN_VA(0x439199u);
    ++cpu->esi;
    cpu->ebx += 0x34u;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->ebp)) goto label_00039162;
    goto label_000391C6;
    label_000391A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4391A3u);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x34u);
    cpu->eax = lift_load32(cpu->eax + 0x24u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base))), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_store8(cpu->eax, 0x47u);
    cpu->ecx = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    cpu->edx = lift_load32(cpu->esi + cpu->ecx + 0x24u);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx -= lift_load32(cpu->ecx + cpu->esi + 0x24u);
    --cpu->edx;
    lift_store32(cpu->eax + 1u, cpu->edx);
    label_000391C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4391C6u);
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + (uint64_t)(0x34u) + (uint64_t)(0u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x20u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x20u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00039140;
    cpu->ebx = lift_load32(cpu->esp + 0x24u);
    goto label_00039211;
    label_000391DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4391DBu);
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(cpu->ebp)) goto label_00039211;
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->ebp -= cpu->ebx;
    cpu->esi = cpu->ebp;
    cpu->ebp = lift_load32(cpu->esp + 0x34u);
    label_000391F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4391F0u);
    cpu->eax = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    lift_store32(cpu->eax + cpu->ecx + 0x24u, (uint64_t)(lift_load32(cpu->eax + cpu->ecx + 0x24u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    cpu->eax = (uint32_t)(cpu->eax + cpu->ecx + 0x24u);
    cpu->eax = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, auxiliary_record_table));
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + cpu->ecx + 0x28u)), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->eax + cpu->ecx + 0x28u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003920B;
    lift_store32(cpu->eax, (uint64_t)(lift_load32(cpu->eax)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u));
    label_0003920B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43920Bu);
    cpu->ecx += 0x34u;
    { uint64_t l=(uint64_t)(cpu->esi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->esi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000391F0;
    label_00039211: cpu->eip = LIFT_CODE_TOKEN_VA(0x439211u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x44u)) > (int32_t)(uint32_t)(0x16u)) goto label_0003923E;
    cpu->esi = 0x3Cu;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00039236;
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->esi += 0x3Cu;
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00039275;
    label_00039236: cpu->eip = LIFT_CODE_TOKEN_VA(0x439236u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    goto label_00039268;
    label_0003923E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43923Eu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(0xA0u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); lift_store32(cpu->esp + 0x10u, v); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000392E1;
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->esi += 0xA0u;
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00039275;
    label_00039262: cpu->eip = LIFT_CODE_TOKEN_VA(0x439262u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    label_00039268: cpu->eip = LIFT_CODE_TOKEN_VA(0x439268u);
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->link_workspace_words[0]);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43926Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x439272u);
    cpu->esp += 0xCu;
    label_00039275: cpu->eip = LIFT_CODE_TOKEN_VA(0x439275u);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(cpu->esi) + (uint64_t)(0u));
    cpu->eax = 0u;
    label_00039280: cpu->eip = LIFT_CODE_TOKEN_VA(0x439280u);
    cpu->ecx = lift_load32(cpu->edi + (uint32_t)offsetof(SferaMbcProcessRecord, workspace_base));
    cpu->edx = 0xFFFFu;
    if ((uint16_t)(lift_load16(cpu->ecx + cpu->eax)) != (uint16_t)((cpu->edx & 0xFFFFu))) goto label_000392A8;
    cpu->edx = g_sfera_mbc_runtime->link_workspace_words[cpu->eax >> 1u];
    cpu->esi = 0xFFFFu;
    if ((uint16_t)((cpu->edx & 0xFFFFu)) == (uint16_t)((cpu->esi & 0xFFFFu))) goto label_000392A8;
    cpu->edx += cpu->ebx;
    lift_store16(cpu->ecx + cpu->eax, cpu->edx & 0xFFFFu);
    label_000392A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4392A8u);
    cpu->eax += 2u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xA0u)) goto label_00039280;
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebx = v; }
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000392EB;
    cpu->esi = (uint32_t)(cpu->ebx + 4u);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_000392F2;
    label_000392CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4392CCu);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->module_link_stream_size);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4392D7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4392DCu);
    cpu->esp += 0xCu;
    goto label_000392F6;
    label_000392E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4392E1u);
    cpu->esi = 0xA0u;
    goto label_00039262;
    label_000392EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4392EBu);
    cpu->esi = 4u;
    goto label_000392CC;
    label_000392F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4392F2u);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    label_000392F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4392F6u);
    cpu->ebp += cpu->esi;
    cpu->esi = g_sfera_mbc_runtime->module_link_stream_size;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebx = v; }
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00039310;
    cpu->esi += cpu->ebx;
    lift_store32(cpu->esp + 0x10u, 0u);
    label_00039310: cpu->eip = LIFT_CODE_TOKEN_VA(0x439310u);
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00039323;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->module_link_stream[0]);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43931Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x439320u);
    cpu->esp += 0xCu;
    label_00039323: cpu->eip = LIFT_CODE_TOKEN_VA(0x439323u);
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    cpu->ecx = cpu->edi;
    cpu->ebp += cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x439330u); lift_push32(cpu, r); sfera_sub_00435110(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00039514;
    cpu->edi = (uint32_t)(cpu->esi + 4u);
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_00039360;
    label_0003934E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43934Eu);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0xD0u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x439358u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43935Du);
    cpu->esp += 0xCu;
    label_00039360: cpu->eip = LIFT_CODE_TOKEN_VA(0x439360u);
    cpu->ebp += cpu->edi;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0003951E;
    cpu->edi = (uint32_t)(cpu->esi + 4u);
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_0003938E;
    label_0003937C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43937Cu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0xD4u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x439386u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43938Bu);
    cpu->esp += 0xCu;
    label_0003938E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43938Eu);
    cpu->ebp += cpu->edi;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00039528;
    cpu->edi = (uint32_t)(cpu->esi + 4u);
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_000393BC;
    label_000393AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4393AAu);
    lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->esp + 0xD8u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4393B4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4393B9u);
    cpu->esp += 0xCu;
    label_000393BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4393BCu);
    cpu->ebp += cpu->edi;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00039532;
    cpu->edi = (uint32_t)(cpu->esi + 4u);
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_000393E7;
    label_000393D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4393D8u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->link_relocation_count);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4393DFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4393E4u);
    cpu->esp += 0xCu;
    label_000393E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4393E7u);
    cpu->ebp += cpu->edi;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x38u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = g_sfera_mbc_runtime->link_relocation_count;
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0003953C;
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edi) * 4u));
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0003940D;
    cpu->eax += cpu->esi;
    cpu->esi = 0u;
    label_0003940D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43940Du);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    label_00039411: cpu->eip = LIFT_CODE_TOKEN_VA(0x439411u);
    cpu->ebp = lift_load32(cpu->esp + 0x3Cu);
    label_00039415: cpu->eip = LIFT_CODE_TOKEN_VA(0x439415u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000395AE;
    cpu->ebx = (uint32_t)(cpu->esi + 4u);
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00039448;
    label_0003942F: cpu->eip = LIFT_CODE_TOKEN_VA(0x43942Fu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->link_relocation_count);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43943Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x43943Fu);
    cpu->edi = g_sfera_mbc_runtime->link_relocation_count;
    cpu->esp += 0xCu;
    label_00039448: cpu->eip = LIFT_CODE_TOKEN_VA(0x439448u);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u));
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->edi) * 4u));
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00039463;
    cpu->ebx += cpu->esi;
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    label_00039463: cpu->eip = LIFT_CODE_TOKEN_VA(0x439463u);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_0003947A;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->link_relocation_offsets[0]);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x439472u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x439477u);
    cpu->esp += 0xCu;
    label_0003947A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43947Au);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u));
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_000394B0;
    label_00039490: cpu->eip = LIFT_CODE_TOKEN_VA(0x439490u);
    cpu->ecx = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->link_relocation_offsets[0]));
    cpu->edx = lift_load32(cpu->esp + 0x98u);
    lift_store32(cpu->ecx + cpu->edx, (uint64_t)(lift_load32(cpu->ecx + cpu->edx)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u));
    cpu->edi = g_sfera_mbc_runtime->link_relocation_count;
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edi)) goto label_00039490;
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    label_000394B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4394B0u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000395B8;
    cpu->ebx = (uint32_t)(cpu->esi + 4u);
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_000394E3;
    label_000394CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4394CAu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->link_relocation_count);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4394D5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4394DAu);
    cpu->edi = g_sfera_mbc_runtime->link_relocation_count;
    cpu->esp += 0xCu;
    label_000394E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4394E3u);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u));
    if ((uint32_t)(lift_load32(cpu->esp + 0x38u)) != (uint32_t)(0u)) goto label_00039604;
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edi) * 4u));
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000395C2;
    cpu->esi += cpu->eax;
    lift_store32(cpu->esp + 0x10u, 0u);
    goto label_000395C4;
    label_00039514: cpu->eip = LIFT_CODE_TOKEN_VA(0x439514u);
    cpu->edi = 4u;
    goto label_0003934E;
    label_0003951E: cpu->eip = LIFT_CODE_TOKEN_VA(0x43951Eu);
    cpu->edi = 4u;
    goto label_0003937C;
    label_00039528: cpu->eip = LIFT_CODE_TOKEN_VA(0x439528u);
    cpu->edi = 4u;
    goto label_000393AA;
    label_00039532: cpu->eip = LIFT_CODE_TOKEN_VA(0x439532u);
    cpu->edi = 4u;
    goto label_000393D8;
    label_0003953C: cpu->eip = LIFT_CODE_TOKEN_VA(0x43953Cu);
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->edi) * 4u));
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00039553;
    cpu->ebx += cpu->esi;
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    label_00039553: cpu->eip = LIFT_CODE_TOKEN_VA(0x439553u);
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_00039566;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->link_relocation_offsets[0]);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x43955Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x439563u);
    cpu->esp += 0xCu;
    label_00039566: cpu->eip = LIFT_CODE_TOKEN_VA(0x439566u);
    cpu->ebp += cpu->ebx;
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_00039411;
    cpu->ebp = lift_load32(cpu->esp + 0x3Cu);
    cpu->edx = lift_load32(cpu->esp + 0x90u);
    label_00039590: cpu->eip = LIFT_CODE_TOKEN_VA(0x439590u);
    cpu->ecx = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->link_relocation_offsets[0]));
    lift_store32(cpu->ecx + cpu->edx, (uint64_t)(lift_load32(cpu->ecx + cpu->edx)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u));
    cpu->edi = g_sfera_mbc_runtime->link_relocation_count;
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edi)) goto label_00039590;
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    goto label_00039415;
    label_000395AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4395AEu);
    cpu->ebx = 4u;
    goto label_0003942F;
    label_000395B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4395B8u);
    cpu->ebx = 4u;
    goto label_000394CA;
    label_000395C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4395C2u);
    cpu->esi = cpu->eax;
    label_000395C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4395C4u);
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_000395DB;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->link_relocation_offsets[0]);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4395D3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4395D8u);
    cpu->esp += 0xCu;
    label_000395DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4395DBu);
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_00039604;
    cpu->edx = lift_load32(cpu->esp + 0x90u);
    cpu->esi = lift_load32(cpu->esp + 0x34u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000395F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4395F0u);
    cpu->ecx = lift_load32(((uint32_t)(cpu->eax) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->link_relocation_offsets[0]));
    lift_store16(cpu->ecx + cpu->edx, (uint64_t)(lift_load16(cpu->ecx + cpu->edx)) + (uint64_t)((cpu->esi & 0xFFFFu)) + (uint64_t)(0u));
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(g_sfera_mbc_runtime->link_relocation_count)) goto label_000395F0;
    label_00039604: cpu->eip = LIFT_CODE_TOKEN_VA(0x439604u);
    cpu->eax = 0u;
    goto label_00038900;
    label_0003960B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43960Bu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0x3D8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00439630(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x439630u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    --cpu->eax;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    cpu->edx = (uint32_t)(cpu->esp);
    cpu->ecx = (uint32_t)(uintptr_t)"Unknown script code: ";
    lift_store8(cpu->esp, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 1u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x439653u); lift_push32(cpu, r); sfera_sub_00438640(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00439660(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x439660u);
    cpu->ecx = (uint32_t)(uintptr_t)"Unlinked function was called";
    sfera_sub_004385D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00439670(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x439670u);
    cpu->eax = g_sfera_mbc_runtime->call_frame_depth;
    ++cpu->eax;
    g_sfera_mbc_runtime->call_frame_depth = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x14u)) goto label_0003969D;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack of stacks overflow";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x43968Au); lift_push32(cpu, r); sfera_sub_004385D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_mbc_runtime->call_frame_depth;
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    g_sfera_mbc_runtime->frame_stack_base[cpu->eax] = (uint32_t)(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
    label_0003969D: cpu->eip = LIFT_CODE_TOKEN_VA(0x43969Du);
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    g_sfera_mbc_runtime->frame_stack_base[cpu->eax] = (uint32_t)(cpu->edx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004396B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4396B0u);
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->call_frame_depth), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; g_sfera_mbc_runtime->call_frame_depth = (uint32_t)((v)); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000396C2;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack of stacks devastation";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_000396C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4396C2u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004396D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4396D0u);
    cpu->eax = g_sfera_mbc_runtime->active_program_record;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 0x84u)) & 0xFFu);
    cpu->edx = 0u;
    lift_push32(cpu, cpu->esi);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)((cpu->edx & 0xFFu))) goto label_00039739;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) - 1u)) & 0xFFu);
    lift_store8(cpu->eax + 0x84u, cpu->ecx & 0xFFu);
    cpu->eax = g_sfera_mbc_runtime->active_program_record;
    cpu->ecx = cpu->ecx & 0xFFu;
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u) + 0x34u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_00039733;
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->ecx = lift_load32(cpu->eax + 0xBCu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_00039725;
    cpu->edx = lift_load32(cpu->ecx + 0x230u);
    lift_store32(cpu->eax + 0xBCu, cpu->edx);
    lift_push32(cpu, 0x1853u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x39725u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    label_00039725: cpu->eip = LIFT_CODE_TOKEN_VA(0x439725u);
    cpu->eax = g_sfera_mbc_runtime->bytecode_base;
    cpu->eax -= cpu->esi;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00039733: cpu->eip = LIFT_CODE_TOKEN_VA(0x439733u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000397DD;
    label_00039739: cpu->eip = LIFT_CODE_TOKEN_VA(0x439739u);
    cpu->ecx = g_sfera_mbc_runtime->execution_context_depth;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_00039755;
    cpu->ecx = (uint32_t)(uintptr_t)"fo12(): return stack underflow";
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004385D0(cpu, stop_address); return;
    label_00039750: cpu->eip = LIFT_CODE_TOKEN_VA(0x439750u);
    cpu->eax = g_sfera_mbc_runtime->active_program_record;
    label_00039755: cpu->eip = LIFT_CODE_TOKEN_VA(0x439755u);
    --cpu->ecx;
    g_sfera_mbc_runtime->execution_context_depth = (uint32_t)(cpu->ecx);
    lift_store8(cpu->eax + 0x94u, cpu->edx & 0xFFu);
    cpu->ecx = g_sfera_mbc_runtime->execution_context_depth;
    cpu->eax = g_sfera_mbc_runtime->execution_context_stack[cpu->ecx].process_index;
    g_sfera_mbc_runtime->process_index = (uint32_t)(cpu->eax);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id));
    if ((uint32_t)(cpu->eax) == (uint32_t)(g_sfera_mbc_runtime->execution_context_stack[cpu->ecx].process_id)) goto label_0003979A;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_00039750;
    cpu->ecx = (uint32_t)(uintptr_t)"Return to defunct process";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x3979Au); lift_push32(cpu, r); sfera_sub_004385D0(cpu,r); if (cpu->eip != r) return; }
    label_0003979A: cpu->eip = LIFT_CODE_TOKEN_VA(0x43979Au);
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
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000397DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4397DDu);
    cpu->eax = g_sfera_mbc_runtime->bytecode_base;
    cpu->eax += cpu->esi;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004397F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4397F0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_mbc_runtime->value_stack_size;
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFFEu);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    cpu->eax = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.base_slot.type));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00039832;
    cpu->edi = lift_load32(cpu->eax + 0x14u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_00039827;
    cpu->edi = lift_pop32(cpu);
    cpu->ecx = (uint32_t)(uintptr_t)"Division by zero";
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004385D0(cpu, stop_address); return;
    label_00039827: cpu->eip = LIFT_CODE_TOKEN_VA(0x439827u);
    cpu->eax = lift_load32(cpu->ecx + 0x14u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_divide_accumulator(cpu, cpu->edi, 32u, 1u);
    lift_store32(cpu->ecx + 0x14u, cpu->eax);
    goto label_0003983B;
    label_00039832: cpu->eip = LIFT_CODE_TOKEN_VA(0x439832u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (((double)lift_load_f32(cpu->eax + 0x14u))));
    lift_store_f32(cpu->ecx + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0003983B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43983Bu);
    cpu->eax = 1u;
    cpu->esi -= cpu->eax;
    cpu->edi = lift_pop32(cpu);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->esi);
    lift_store32(cpu->ecx + 8u, 0xFFFFFFFFu);
    lift_store32(cpu->ecx + 0x10u, cpu->eax);
    lift_store32(cpu->ecx + 0xCu, cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00439860(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x439860u);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = g_sfera_mbc_runtime->call_frame_depth;
    cpu->edx = 1u;
    cpu->ecx -= cpu->edx;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(g_sfera_mbc_runtime->frame_stack_base[cpu->eax]), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0003988B;
    cpu->ecx = (uint32_t)(uintptr_t)"fo27(): stack underflow";
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003988B: cpu->eip = LIFT_CODE_TOKEN_VA(0x43988Bu);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.value_stack.entries[0].type);
    if ((uint32_t)(lift_load32(cpu->eax)) != (uint32_t)(0x20u)) goto label_000398A4;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->eax + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000398AE;
    label_000398A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4398A4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax + 0x14u);
    cpu->esi = 0u - (uint64_t)(cpu->esi);
    lift_store32(cpu->eax + 0x14u, cpu->esi);
    cpu->esi = lift_pop32(cpu);
    label_000398AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4398AEu);
    cpu->ecx += cpu->edx;
    lift_store32(cpu->eax + 8u, 0xFFFFFFFFu);
    lift_store32(cpu->eax + 0x10u, cpu->edx);
    lift_store32(cpu->eax + 0xCu, cpu->edx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}
