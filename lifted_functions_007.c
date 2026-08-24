#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>
#include <string.h>

static uint32_t sfera_clip_plane_order(uint32_t index) {
    switch (index) {
        case 0u: return 0u;
        case 1u: return 1u;
        case 2u: return 3u;
        case 3u: return 5u;
        case 4u: return 4u;
        default: return 2u;
    }
}

static LiftFunction sfera_mbinter_handler_function(uint32_t opcode) {
    switch (opcode) {
        case 0x69u: return &sfera_sub_004368E0;
        case 0x47u: return &sfera_sub_004369A0;
        case 0x2Cu: return &sfera_sub_004369C0;
        case 0x30u: return &sfera_sub_004369E0;
        case 0x49u: return &sfera_sub_0043B140;
        case 0x39u: return &sfera_sub_00436A00;
        case 0x61u: return &sfera_sub_0043B190;
        case 0x52u: return &sfera_sub_00436C70;
        case 0x53u: return &sfera_sub_00436D30;
        case 0x43u: return &sfera_sub_00436D90;
        case 0x63u: return &sfera_sub_0043B880;
        case 0x72u: return &sfera_sub_004396D0;
        case 0x3Du: return &sfera_sub_00436E20;
        case 0x2Bu: return &sfera_sub_00437020;
        case 0x2Du: return &sfera_sub_00437070;
        case 0x2Au: return &sfera_sub_004370C0;
        case 0x2Fu: return &sfera_sub_004397F0;
        case 0x25u: return &sfera_sub_00437120;
        case 0x31u: return &sfera_sub_00439670;
        case 0x32u: return &sfera_sub_004396B0;
        case 0xF0u: return &sfera_sub_00437170;
        case 0xEDu: return &sfera_sub_004371F0;
        case 0x3Eu: return &sfera_sub_00437270;
        case 0x3Cu: return &sfera_sub_004372F0;
        case 0xE1u: return &sfera_sub_00437370;
        case 0xECu: return &sfera_sub_004373F0;
        case 0xF1u: return &sfera_sub_00439860;
        case 0x4Fu: return &sfera_sub_004398D0;
        case 0xEBu: return &sfera_sub_00437510;
        case 0xE8u: return &sfera_sub_00437510;
        case 0x21u: return &sfera_sub_00439BD0;
        case 0xEFu: return &sfera_sub_00437540;
        case 0xF3u: return &sfera_sub_004375B0;
        case 0x55u: return &sfera_sub_00436CD0;
        case 0x66u: return &sfera_sub_00437700;
        case 0xF6u: return &sfera_sub_00437620;
        case 0xF7u: return &sfera_sub_00437690;
        case 0xD6u: return &sfera_sub_00437970;
        case 0xD7u: return &sfera_sub_004379B0;
        case 0x62u: return &sfera_sub_0043B320;
        case 0x6Du: return &sfera_sub_0043B4C0;
        case 0x67u: return &sfera_sub_00439660;
        case 0x41u: return &sfera_sub_00436B20;
        case 0x5Eu: return &sfera_sub_00436ED0;
        case 0x50u: return &sfera_sub_00436D60;
        case 0x26u: return &sfera_sub_00436FD0;
        case 0x48u: return &sfera_sub_00437750;
        case 0x2Eu: return &sfera_sub_00437760;
        case 0x3Au: return &sfera_sub_00437780;
        case 0x7Eu: return &sfera_sub_004377A0;
        case 0x5Bu: return &sfera_sub_004377F0;
        case 0x5Du: return &sfera_sub_00437840;
        case 0x60u: return &sfera_sub_00437890;
        case 0x22u: return &sfera_sub_004378C0;
        case 0x74u: return &sfera_sub_00436DD0;
        case 0xCFu: return &sfera_sub_004378F0;
        case 0xD3u: return &sfera_sub_00437930;
        case 0x3Bu: return &sfera_sub_004379F0;
        case 0x4Au: return &sfera_sub_004369B0;
        case 0x4Bu: return &sfera_sub_0043B160;
        case 0x28u: return &sfera_sub_00436A60;
        case 0x29u: return &sfera_sub_00436AC0;
        case 0xC9u: return &sfera_sub_0043BA10;
        case 0x65u: return &sfera_sub_00436B90;
        case 0x64u: return &sfera_sub_0043B610;
        case 0x68u: return &sfera_sub_0043B790;
        case 0x6Cu: return &sfera_sub_00436C00;
        case 0x4Cu: return &sfera_sub_00437470;
        case 0x4Du: return &sfera_sub_004374C0;
        default: return &sfera_sub_00439630;
    }
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00442F70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442F81u)); sfera_sub_0043AE00(cpu, LIFT_CODE_TOKEN_VA(0x442F81u));
    cpu->esi = lift_load32(cpu->eax);
    cpu->ebx = lift_load32(cpu->eax + 4u);
    cpu->ebp = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442F9Au)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x442F9Au));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442FA1u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x442FA1u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00043039;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_00042FBC;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(4u)) goto label_00042FCC;
    label_00042FBC:
    if ((uint32_t)(cpu->ebx) == 0u) goto label_00042FE0;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebx)) goto label_00042FCC;
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->edi) * 4u) + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(cpu->ebp)) goto label_00042FE0;
    label_00042FCC:
    cpu->edx = (uint32_t)(((uint32_t)(cpu->edi) * 4u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x442FDCu)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_VA(0x442FDCu));
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    label_00042FE0:
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00042FF3;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00042FF3:
    cpu->ebx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ebx += cpu->esi;
    cpu->esi = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->edi) * 4u) + 0xFFFFFFFCu);
    cpu->ecx = cpu->ebx;
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(cpu->esi)) goto label_00043028;
    label_00043005:
    cpu->eax = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u))), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_00043022;
    cpu->ecx = (uint32_t)(cpu->eax + 4u);
    goto label_00043024;
    label_00043022:
    cpu->esi = cpu->eax;
    label_00043024:
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->esi)) goto label_00043005;
    label_00043028:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ebp = lift_pop32(cpu);
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_00043039:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00443050(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443058u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x443058u));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44305Fu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x44305Fu));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443066u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x443066u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000430BD;
    cpu->eax = lift_load32(cpu->esi);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xFFFFFFFCu)) goto label_0004307D;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(4u)) goto label_00043091;
    label_0004307D:
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0004309A;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_00043091;
    cpu->eax = (uint32_t)(cpu->eax + cpu->edi + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(lift_load32(cpu->esi + 8u))) goto label_0004309A;
    label_00043091:
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4309Au)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_RVA(0x4309Au));
    label_0004309A:
    cpu->ecx = lift_load32(cpu->esi);
    cpu->ecx += g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = cpu->edi;
    g_sfera_mbc_runtime->file_crc32 = (uint32_t)(cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4430AFu)); sfera_sub_004348D0(cpu, LIFT_CODE_TOKEN_VA(0x4430AFu));
    cpu->ecx = g_sfera_mbc_runtime->file_crc32;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    sfera_sub_0043B0D0(cpu, stop_address); return;
    label_000430BD:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004430D0(LiftCpu* cpu, uint32_t stop_address) {
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
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x443138u));
    cpu->esp += 0xCu;
    cpu->edx = 0x1A4u;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\lists\\ItemList.h";
    lift_store8(cpu->esi + 0x99u, cpu->ebx & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443156u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x443156u));
    lift_push32(cpu, 0x44u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44315Du)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x44315Du));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00043183;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x100u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u); lift_push32(cpu, 0x96u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443181u)); sfera_sub_0043A520(cpu, LIFT_CODE_TOKEN_VA(0x443181u));
    goto label_00043185;
    label_00043183:
    cpu->eax = 0u;
    label_00043185:
    cpu->ecx |= 0xFFFFFFFFu;
    lift_store32(cpu->esi + 0xCCu, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_store32(cpu->eax + 0x28u, cpu->ecx);
    lift_push32(cpu, 0x1ABu);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\lists\\ItemList.h";
    cpu->ecx = 0x18D8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4431A9u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4431A9u));
    lift_store32(cpu->esi + 0xD0u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_000431EB;
    if ((uint8_t)(lift_load8(cpu->esi + 0xC8u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000431D2;
    lift_push32(cpu, (uint32_t)(uintptr_t)"~~~~~ItemList~~~INITIALIZE~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4431C5u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x4431C5u));
    lift_push32(cpu, (uint32_t)(uintptr_t)" Initialize = 'ERROR'\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4431CFu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x4431CFu));
    cpu->esp += 8u;
    label_000431D2:
    cpu->eax = 0xFFFFFFF2u;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
    label_000431EB:
    lift_push32(cpu, 0x18D8u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4431F2u));
    cpu->esp += 0xCu;
    if ((uint8_t)(lift_load8(cpu->esi + 0xC8u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00043219;
    lift_push32(cpu, (uint32_t)(uintptr_t)"~~~~~ItemList~~~INITIALIZE~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44320Cu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x44320Cu));
    lift_push32(cpu, (uint32_t)(uintptr_t)"Initialize complete\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443216u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x443216u));
    cpu->esp += 8u;
    label_00043219:
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00443230(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + 0xC8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0004324A;
    lift_push32(cpu, (uint32_t)(uintptr_t)"~~~~~ItemList~~~FIND ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443247u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x443247u));
    cpu->esp += 4u;
    label_0004324A:
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->esi = lift_load32(cpu->ebx + 0xCCu);
    cpu->ecx += 4u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x1Eu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->esp + 0x10u, cpu->eax & 0xFFu);
    cpu->eax = cpu->ecx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_00043268:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00043268;
    cpu->eax -= cpu->edi;
    cpu->edi = lift_pop32(cpu);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(lift_load32(cpu->esi))) goto label_00043294;
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443284u)); sfera_sub_00438220(cpu, LIFT_CODE_TOKEN_VA(0x443284u));
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00043294;
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    cpu->ecx += lift_load32(cpu->esi + 4u);
    goto label_00043297;
    label_00043294:
    cpu->ecx = (uint32_t)(cpu->esi + 0x28u);
    label_00043297:
    cpu->esi = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_000432C2;
    if ((uint8_t)(lift_load8(cpu->ebx + 0xC8u)) == (uint8_t)(0u)) goto label_000432AF;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x432AFu)); sfera_sub_00438100(cpu, LIFT_CODE_TOKEN_RVA(0x432AFu));
    label_000432AF:
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xD4u);
    cpu->eax += lift_load32(cpu->ebx + 0xD0u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000432C2:
    if ((uint8_t)(lift_load8(cpu->ebx + 0xC8u)) == (uint8_t)(0u)) goto label_000432D8;
    lift_push32(cpu, (uint32_t)(uintptr_t)" FindItem = 'ERROR'\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4432D5u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x4432D5u));
    cpu->esp += 4u;
    label_000432D8:
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004432E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x428u;
    cpu->eax = lift_load32(cpu->esp + 0x42Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x434u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::strncpy);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0x96u);
    cpu->ebp = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xC4u);
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, cpu->ecx);
    std::construct_at(reinterpret_cast<CItem*>(cpu->esp + 0x20u));
    std::construct_at(reinterpret_cast<CCommonItem*>(cpu->esp + 0x284u));
    std::construct_at(reinterpret_cast<CCommonItem*>(cpu->esp + 0xC8u));
    cpu->edi = 0u;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x43343u), LIFT_CODE_TOKEN_RVA(0x43341u))) { return; }
    lift_push32(cpu, 0x96u);
    cpu->edx = (uint32_t)(cpu->esp + 0x28Cu);
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, cpu->edx);
    lift_store8(cpu->esp + 0x16Du, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x4335Fu), LIFT_CODE_TOKEN_RVA(0x4335Du))) { return; }
    lift_push32(cpu, 0x96u);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_store8(cpu->esp + 0x335u, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x43374u), LIFT_CODE_TOKEN_RVA(0x43372u))) { return; }
    cpu->esp += 0x24u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->esp + 0xB1u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44338Bu)); sfera_sub_00443230(cpu, LIFT_CODE_TOKEN_VA(0x44338Bu));
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0004340C;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443398u)); sfera_sub_0043A300(cpu, LIFT_CODE_TOKEN_VA(0x443398u));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000433A8;
    cpu->edx = (uint32_t)(cpu->esp + 0xBCu);
    lift_push32(cpu, cpu->edx);
    goto label_00043414;
    label_000433A8:
    cpu->ecx = lift_load32(cpu->ebx + 0xB0u);
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x413u);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\lists\\basemanager.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4433C1u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4433C1u));
    cpu->ebp = cpu->eax;
    cpu->eax = lift_load32(cpu->ebx + 0xB0u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4433D1u));
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp += 0xCu;
    if ((uint32_t)(lift_load32(cpu->esp + 0x444u)) != (uint32_t)(cpu->eax)) goto label_00043522;
    if ((uint32_t)(lift_load32(cpu->esp + 0x448u)) != (uint32_t)(cpu->eax)) goto label_00043466;
    if ((uint32_t)(lift_load32(cpu->esp + 0x44Cu)) != (uint32_t)(cpu->eax)) goto label_00043440;
    lift_push32(cpu, 0x41Du);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\lists\\basemanager.h";
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4340Cu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_RVA(0x4340Cu));
    label_0004340C:
    cpu->ecx = (uint32_t)(cpu->esp + 0xBCu);
    lift_push32(cpu, cpu->ecx);
    label_00043414:
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44341Fu)); sfera_sub_0043A470(cpu, LIFT_CODE_TOKEN_VA(0x44341Fu));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x428u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
    label_00043440:
    cpu->edx = lift_load32(cpu->esp + 0x44Cu);
    if ((uint32_t)(lift_load32(cpu->esi + 0xB0u)) != (uint32_t)(cpu->edx)) goto label_00043454;
    lift_store32(cpu->ebp + ((uint32_t)(cpu->edi) * 4u), cpu->esi);
    ++cpu->edi;
    label_00043454:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44345Bu)); sfera_sub_0043A3D0(cpu, LIFT_CODE_TOKEN_VA(0x44345Bu));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00043440;
    goto label_000434E1;
    label_00043466:
    if ((uint32_t)(lift_load32(cpu->esp + 0x44Cu)) == (uint32_t)(cpu->eax)) goto label_000434A3;
    (void)cpu;
    label_00043470:
    cpu->eax = lift_load32(cpu->esp + 0x448u);
    if ((uint32_t)(lift_load32(cpu->esi + 0xA8u)) != (uint32_t)(cpu->eax)) goto label_00043493;
    cpu->ecx = lift_load32(cpu->esp + 0x44Cu);
    if ((uint32_t)(lift_load32(cpu->esi + 0xB0u)) != (uint32_t)(cpu->ecx)) goto label_00043493;
    lift_store32(cpu->ebp + ((uint32_t)(cpu->edi) * 4u), cpu->esi);
    ++cpu->edi;
    label_00043493:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44349Au)); sfera_sub_0043A3D0(cpu, LIFT_CODE_TOKEN_VA(0x44349Au));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00043470;
    cpu->eax |= 0xFFFFFFFFu;
    label_000434A3:
    if ((uint32_t)(lift_load32(cpu->esp + 0x448u)) == (uint32_t)(cpu->eax)) goto label_000434E1;
    if ((uint32_t)(lift_load32(cpu->esp + 0x44Cu)) != (uint32_t)(cpu->eax)) goto label_000434E1;
    label_000434C0:
    cpu->ecx = lift_load32(cpu->esp + 0x448u);
    if ((uint32_t)(lift_load32(cpu->esi + 0xA8u)) != (uint32_t)(cpu->ecx)) goto label_000434D4;
    lift_store32(cpu->ebp + ((uint32_t)(cpu->edi) * 4u), cpu->esi);
    ++cpu->edi;
    label_000434D4:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4434DBu)); sfera_sub_0043A3D0(cpu, LIFT_CODE_TOKEN_VA(0x4434DBu));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000434C0;
    label_000434E1:
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_00043655;
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x4434E9u));
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_divide_accumulator(cpu, cpu->edi, 32u, 1u);
    cpu->ecx = 0x6Fu;
    cpu->edi = (uint32_t)(cpu->esp + 0x278u);
    lift_push32(cpu, 0x49Au);
    cpu->esi = lift_load32(cpu->ebp + ((uint32_t)(cpu->edx) * 4u));
    lift_movs32(cpu, 1u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\lists\\basemanager.h";
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443515u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x443515u));
    cpu->edx = (uint32_t)(cpu->esp + 0x278u);
    lift_push32(cpu, cpu->edx);
    goto label_00043414;
    label_00043522:
    if ((uint32_t)(lift_load32(cpu->esp + 0x448u)) == (uint32_t)(cpu->eax)) goto label_00043582;
    if ((uint32_t)(lift_load32(cpu->esp + 0x44Cu)) == (uint32_t)(cpu->eax)) goto label_00043582;
    label_00043540:
    cpu->edx = lift_load32(cpu->esp + 0x444u);
    if ((uint32_t)(lift_load32(cpu->esi + 0xACu)) != (uint32_t)(cpu->edx)) goto label_00043572;
    cpu->eax = lift_load32(cpu->esp + 0x448u);
    if ((uint32_t)(lift_load32(cpu->esi + 0xA8u)) != (uint32_t)(cpu->eax)) goto label_00043572;
    cpu->ecx = lift_load32(cpu->esp + 0x44Cu);
    if ((uint32_t)(lift_load32(cpu->esi + 0xB0u)) != (uint32_t)(cpu->ecx)) goto label_00043572;
    lift_store32(cpu->ebp + ((uint32_t)(cpu->edi) * 4u), cpu->esi);
    ++cpu->edi;
    label_00043572:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443579u)); sfera_sub_0043A3D0(cpu, LIFT_CODE_TOKEN_VA(0x443579u));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00043540;
    cpu->eax |= 0xFFFFFFFFu;
    label_00043582:
    if ((uint32_t)(lift_load32(cpu->esp + 0x444u)) == (uint32_t)(cpu->eax)) goto label_000434A3;
    if ((uint32_t)(lift_load32(cpu->esp + 0x448u)) != (uint32_t)(cpu->eax)) goto label_00043606;
    if ((uint32_t)(lift_load32(cpu->esp + 0x44Cu)) == (uint32_t)(cpu->eax)) goto label_000435E0;
    label_000435A1:
    cpu->edx = lift_load32(cpu->esp + 0x444u);
    if ((uint32_t)(lift_load32(cpu->esi + 0xACu)) != (uint32_t)(cpu->edx)) goto label_000435C4;
    cpu->eax = lift_load32(cpu->esp + 0x44Cu);
    if ((uint32_t)(lift_load32(cpu->esi + 0xB0u)) != (uint32_t)(cpu->eax)) goto label_000435C4;
    lift_store32(cpu->ebp + ((uint32_t)(cpu->edi) * 4u), cpu->esi);
    ++cpu->edi;
    label_000435C4:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4435CBu)); sfera_sub_0043A3D0(cpu, LIFT_CODE_TOKEN_VA(0x4435CBu));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000435A1;
    goto label_000434E1;
    label_000435E0:
    cpu->ecx = lift_load32(cpu->esp + 0x444u);
    if ((uint32_t)(lift_load32(cpu->esi + 0xACu)) != (uint32_t)(cpu->ecx)) goto label_000435F4;
    lift_store32(cpu->ebp + ((uint32_t)(cpu->edi) * 4u), cpu->esi);
    ++cpu->edi;
    label_000435F4:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4435FBu)); sfera_sub_0043A3D0(cpu, LIFT_CODE_TOKEN_VA(0x4435FBu));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000435E0;
    goto label_000434E1;
    label_00043606:
    if ((uint32_t)(lift_load32(cpu->esp + 0x44Cu)) != (uint32_t)(cpu->eax)) goto label_000434E1;
    label_00043620:
    cpu->edx = lift_load32(cpu->esp + 0x444u);
    if ((uint32_t)(lift_load32(cpu->esi + 0xACu)) != (uint32_t)(cpu->edx)) goto label_00043643;
    cpu->eax = lift_load32(cpu->esp + 0x448u);
    if ((uint32_t)(lift_load32(cpu->esi + 0xA8u)) != (uint32_t)(cpu->eax)) goto label_00043643;
    lift_store32(cpu->ebp + ((uint32_t)(cpu->edi) * 4u), cpu->esi);
    ++cpu->edi;
    label_00043643:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44364Au)); sfera_sub_0043A3D0(cpu, LIFT_CODE_TOKEN_VA(0x44364Au));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00043620;
    goto label_000434E1;
    label_00043655:
    lift_push32(cpu, 0x4A0u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\lists\\basemanager.h";
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443666u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x443666u));
    cpu->eax = (uint32_t)(cpu->esp + 0xBCu);
    lift_push32(cpu, cpu->eax);
    goto label_00043414;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00443680(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + 0xC8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0004369A;
    lift_push32(cpu, (uint32_t)(uintptr_t)"~~~~~ItemList~~~FIND ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443697u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x443697u));
    cpu->esp += 4u;
    label_0004369A:
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->esi = lift_load32(cpu->ebx + 0xCCu);
    cpu->ecx += 4u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x1Eu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->esp + 0x10u, cpu->eax & 0xFFu);
    cpu->eax = cpu->ecx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000436B8:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000436B8;
    cpu->eax -= cpu->edi;
    cpu->edi = lift_pop32(cpu);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(lift_load32(cpu->esi))) goto label_000436E4;
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4436D4u)); sfera_sub_00438220(cpu, LIFT_CODE_TOKEN_VA(0x4436D4u));
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000436E4;
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    cpu->ecx += lift_load32(cpu->esi + 4u);
    goto label_000436E7;
    label_000436E4:
    cpu->ecx = (uint32_t)(cpu->esi + 0x28u);
    label_000436E7:
    cpu->esi = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_00043712;
    if ((uint8_t)(lift_load8(cpu->ebx + 0xC8u)) == (uint8_t)(0u)) goto label_000436FF;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x436FFu)); sfera_sub_004381C0(cpu, LIFT_CODE_TOKEN_RVA(0x436FFu));
    label_000436FF:
    cpu->eax = cpu->esi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1BCu);
    cpu->eax += lift_load32(cpu->ebx + 0xD0u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00043712:
    if ((uint8_t)(lift_load8(cpu->ebx + 0xC8u)) == (uint8_t)(0u)) goto label_00043728;
    lift_push32(cpu, (uint32_t)(uintptr_t)" FindItem = 'ERROR'\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443725u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x443725u));
    cpu->esp += 4u;
    label_00043728:
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00443730(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0xC8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0004374B;
    lift_push32(cpu, (uint32_t)(uintptr_t)"~~~~~ItemList~~~DEL ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443748u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x443748u));
    cpu->esp += 4u;
    label_0004374B:
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_load32(cpu->esi + 0xCCu);
    cpu->ebx += 4u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x1Eu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->esp + 0x10u, cpu->eax & 0xFFu);
    cpu->eax = cpu->ebx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00043768:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00043768;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(lift_load32(cpu->edi))) goto label_00043793;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443783u)); sfera_sub_00438220(cpu, LIFT_CODE_TOKEN_VA(0x443783u));
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00043793;
    cpu->ecx = lift_load32(cpu->edi + 8u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    cpu->ecx += lift_load32(cpu->edi + 4u);
    goto label_00043796;
    label_00043793:
    cpu->ecx = (uint32_t)(cpu->edi + 0x28u);
    label_00043796:
    cpu->edi = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->edi) == (uint32_t)(0xFFFFFFFFu)) goto label_00043831;
    cpu->ecx = lift_load32(cpu->esi + 0xCCu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4437AFu)); sfera_sub_0043A990(cpu, LIFT_CODE_TOKEN_VA(0x4437AFu));
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(1u)) goto label_00043826;
    if ((uint8_t)(lift_load8(cpu->esi + 0xC8u)) == (uint8_t)(0u)) goto label_000437C4;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x437C4u)); sfera_sub_00438380(cpu, LIFT_CODE_TOKEN_RVA(0x437C4u));
    label_000437C4:
    cpu->edx = lift_load32(cpu->esi + 0xD0u);
    cpu->eax = cpu->edi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xD4u);
    lift_store8(cpu->edx + cpu->eax + 0x9Au, 0u);
    cpu->ecx = lift_load32(cpu->esi + 0xD0u);
    cpu->ecx += cpu->eax;
    reinterpret_cast<CItem*>(cpu->ecx)->resetItem(cpu);
    lift_store32(cpu->esi + 0xB0u, (uint64_t)(lift_load32(cpu->esi + 0xB0u)) - 1u);
    cpu->eax = lift_load32(cpu->esi + 0xB0u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0xA8u))) goto label_0004381E;
    if ((uint8_t)(lift_load8(cpu->esi + 0xC8u)) == (uint8_t)(0u)) goto label_00043813;
    lift_push32(cpu, (uint32_t)(uintptr_t)" DelItem = CurItems Less Than CurMax\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443810u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x443810u));
    cpu->esp += 4u;
    label_00043813:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0xFFFFFFFAu;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0004381E:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00043826:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0xFFFFFFF7u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00043831:
    if ((uint8_t)(lift_load8(cpu->esi + 0xC8u)) == (uint8_t)(0u)) goto label_00043847;
    lift_push32(cpu, (uint32_t)(uintptr_t)" DelItem = 'ERROR' NOT DELETE\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443844u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x443844u));
    cpu->esp += 4u;
    label_00043847:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0xFFFFFFF8u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00443860(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0xC8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0004387B;
    lift_push32(cpu, (uint32_t)(uintptr_t)"~~~~~ItemList~~~DEL ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443878u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x443878u));
    cpu->esp += 4u;
    label_0004387B:
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_load32(cpu->esi + 0xCCu);
    cpu->ebx += 4u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x1Eu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->esp + 0x10u, cpu->eax & 0xFFu);
    cpu->eax = cpu->ebx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00043898:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00043898;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(lift_load32(cpu->edi))) goto label_000438C3;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4438B3u)); sfera_sub_00438220(cpu, LIFT_CODE_TOKEN_VA(0x4438B3u));
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000438C3;
    cpu->ecx = lift_load32(cpu->edi + 8u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    cpu->ecx += lift_load32(cpu->edi + 4u);
    goto label_000438C6;
    label_000438C3:
    cpu->ecx = (uint32_t)(cpu->edi + 0x28u);
    label_000438C6:
    cpu->edi = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->edi) == (uint32_t)(0xFFFFFFFFu)) goto label_00043961;
    cpu->ecx = lift_load32(cpu->esi + 0xCCu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4438DFu)); sfera_sub_0043A990(cpu, LIFT_CODE_TOKEN_VA(0x4438DFu));
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(1u)) goto label_00043956;
    if ((uint8_t)(lift_load8(cpu->esi + 0xC8u)) == (uint8_t)(0u)) goto label_000438F4;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x438F4u)); sfera_sub_004383F0(cpu, LIFT_CODE_TOKEN_RVA(0x438F4u));
    label_000438F4:
    cpu->edx = lift_load32(cpu->esi + 0xD0u);
    cpu->eax = cpu->edi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1BCu);
    lift_store8(cpu->edx + cpu->eax + 0x9Au, 0u);
    cpu->ecx = lift_load32(cpu->esi + 0xD0u);
    cpu->ecx += cpu->eax;
    reinterpret_cast<CItem*>(cpu->ecx)->resetItem(cpu);
    lift_store32(cpu->esi + 0xB0u, (uint64_t)(lift_load32(cpu->esi + 0xB0u)) - 1u);
    cpu->eax = lift_load32(cpu->esi + 0xB0u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->esi + 0xA8u))) goto label_0004394E;
    if ((uint8_t)(lift_load8(cpu->esi + 0xC8u)) == (uint8_t)(0u)) goto label_00043943;
    lift_push32(cpu, (uint32_t)(uintptr_t)" DelItem = CurItems Less Than CurMax\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443940u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x443940u));
    cpu->esp += 4u;
    label_00043943:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0xFFFFFFFAu;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0004394E:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00043956:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0xFFFFFFF7u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00043961:
    if ((uint8_t)(lift_load8(cpu->esi + 0xC8u)) == (uint8_t)(0u)) goto label_00043977;
    lift_push32(cpu, (uint32_t)(uintptr_t)" DelItem = 'ERROR' NOT DELETE\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443974u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x443974u));
    cpu->esp += 4u;
    label_00043977:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0xFFFFFFF8u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00443990(LiftCpu* cpu, uint32_t stop_address) {
    if ((uint32_t)(g_sfera_inter_scalar_runtime.state_07) == (uint32_t)(0u)) goto label_000439B6;
    cpu->edx = 0xF90u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4439A8u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4439A8u));
    cpu->eax = g_sfera_inter_scalar_runtime.state_07;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4439B3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4439B3u));
    cpu->esp += 4u;
    label_000439B6:
    cpu->edx = 0xF91u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4439C5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4439C5u));
    lift_push32(cpu, 0x208u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4439CFu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4439CFu));
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000439DE;
    std::construct_at(reinterpret_cast<CBaseManagerCommonItem*>(cpu->eax));
    goto label_000439E0;
    label_000439DE:
    cpu->eax = 0u;
    label_000439E0:
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"PlayersLists"); lift_push32(cpu, 1u);
    g_sfera_inter_scalar_runtime.state_07 = (uint32_t)(cpu->eax);
    lift_push32(cpu, 0x64u);
    lift_store32(cpu->eax + 0xD8u, 0u);
    cpu->ecx = g_sfera_inter_scalar_runtime.state_07;
    lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443A07u)); sfera_sub_004430D0(cpu, LIFT_CODE_TOKEN_VA(0x443A07u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00443EB0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00043EB0;
    label_0003B000:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = g_sfera_mbc_runtime->value_stack_size;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0003B01E;
    cpu->esi = lift_pop32(cpu);
    cpu->ecx = (uint32_t)(uintptr_t)"pushpointer(): stack overflow";
    cpu->ebp = lift_pop32(cpu);
    sfera_sub_004385D0(cpu, stop_address); return;
    label_0003B01E:
    cpu->eax = cpu->ebp;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->ecx = 1u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(cpu->ecx);
    if ((uint32_t)(cpu->esi) == 0u) goto label_0003B063;
    cpu->edx = cpu->esi;
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->edx + 1u);
    label_0003B038:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    ++cpu->edx;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0003B038;
    cpu->esi -= g_sfera_mbc_runtime->process_memory_base;
    cpu->edx -= cpu->edi;
    cpu->edx += cpu->esi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[1] = (uint32_t)(cpu->esi);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(cpu->esi);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[2] = (uint32_t)(cpu->edx);
    cpu->ecx = 1u;
    cpu->edi = lift_pop32(cpu);
    goto label_0003B085;
    label_0003B063:
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = 0u - (uint64_t)(cpu->edx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(cpu->edx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[1] = (uint32_t)(0u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[2] = (uint32_t)(0u);
    label_0003B085:
    cpu->ebp += cpu->ecx;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ebp);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->ecx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->ecx);
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00043A10:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443A18u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x443A18u));
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != 0u) goto label_00043A28;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x43A28u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x43A28u));
    label_00043A28:
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax += cpu->esi;
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443A38u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x443A38u));
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != 0u) goto label_00043A48;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x43A48u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x43A48u));
    label_00043A48:
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443A53u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x443A53u));
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = lift_load32(cpu->eax);
    cpu->edi = (uint32_t)(cpu->ecx + cpu->eax);
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->ecx)) goto label_00043A64;
    cpu->edi = 0u;
    label_00043A64:
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->edi)) goto label_00043A72;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_0003B000;
    label_00043A72:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    cpu->edx = 0u;
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(0x2Du), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->edx + cpu->edx + 0xFFFFFFFFu);
    cpu->ebp = cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x2Du)) goto label_00043A87;
    ++cpu->esi;
    label_00043A87:
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_00043ABB;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) - (uint64_t)(0x30u) - (uint64_t)(0u))) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) > (uint8_t)(9u)) goto label_00043ABB;
    cpu->eax = 0u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, cpu->ebx);
    label_00043A98:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    cpu->ebx = (uint32_t)(cpu->edx + 0xFFFFFFD0u);
    if ((uint8_t)((cpu->ebx & 0xFFu)) > (uint8_t)(9u)) goto label_00043AB1;
    cpu->edx = (int8_t)((cpu->edx & 0xFFu));
    ++cpu->ecx;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 2u) + 0xFFFFFFD0u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edi)) goto label_00043A98;
    label_00043AB1:
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->ebp);
    lift_store32(cpu->edx, cpu->eax);
    cpu->ebx = lift_pop32(cpu);
    label_00043ABB:
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 4u;
    goto label_0003B000;
    label_00043AD0:
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443ADBu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x443ADBu));
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != 0u) goto label_00043AEB;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x43AEBu)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x43AEBu));
    label_00043AEB:
    cpu->ebp = g_sfera_mbc_runtime->process_memory_base;
    cpu->ebp += cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443AF8u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x443AF8u));
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != 0u) goto label_00043B08;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x43B08u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x43B08u));
    label_00043B08:
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443B13u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x443B13u));
    cpu->edi = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax += cpu->edi;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edi)) goto label_00043B23;
    cpu->eax = 0u;
    label_00043B23:
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->eax)) goto label_00043B34;
    label_00043B27:
    cpu->ecx = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    goto label_0003B000;
    label_00043B34:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(0x2Du), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->ecx + 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(0x2Du)) goto label_00043B4C;
    ++cpu->esi;
    label_00043B4C:
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_00043B27;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) - (uint64_t)(0x30u) - (uint64_t)(0u))) & 0xFFu);
    if ((uint8_t)((cpu->edx & 0xFFu)) > (uint8_t)(9u)) goto label_00043B27;
    lift_x87_push(cpu, 0.0);
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ebx);
    lift_x87_push(cpu, 10.0);
    label_00043B69:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    cpu->ebx = (uint32_t)(cpu->edx + 0xFFFFFFD0u);
    if ((uint8_t)((cpu->ebx & 0xFFu)) > (uint8_t)(9u)) goto label_00043B94;
    cpu->edx = (int8_t)((cpu->edx & 0xFFu));
    cpu->edx -= 0x30u;
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    ++cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_00043BE3;
    goto label_00043B69;
    label_00043B94:
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_00043BE3;
    if ((uint8_t)(lift_load8(cpu->ecx)) != (uint8_t)(0x2Eu)) goto label_00043BE3;
    lift_x87_push(cpu, (double)0.10000000149011612f);
    ++cpu->ecx;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_00043BE3;
    label_00043BAC:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    cpu->ebx = (uint32_t)(cpu->edx + 0xFFFFFFD0u);
    if ((uint8_t)((cpu->ebx & 0xFFu)) > (uint8_t)(9u)) goto label_00043BE3;
    cpu->edx = (int8_t)((cpu->edx & 0xFFu));
    cpu->edx -= 0x30u;
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    ++cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->eax)) goto label_00043BAC;
    label_00043BE3:
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx = lift_pop32(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 4u))));
    lift_store_f32(cpu->ebp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    goto label_0003B000;
    label_00043C00:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443C06u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x443C06u));
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != 0u) goto label_00043C16;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x43C16u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x43C16u));
    label_00043C16:
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443C21u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x443C21u));
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax += cpu->ecx;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_00043C31;
    cpu->eax = 0u;
    label_00043C31:
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_00043C4A;
    if ((uint8_t)(lift_load8(cpu->esi)) <= (uint8_t)(0x20u)) goto label_00043C4A;
    cpu->ecx = cpu->esi;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00043C40:
    if ((uint8_t)(lift_load8(cpu->ecx)) <= (uint8_t)(0x20u)) goto label_00043C4A;
    ++cpu->ecx;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->eax)) goto label_00043C40;
    label_00043C4A:
    cpu->esi = lift_pop32(cpu);
    goto label_0003B000;
    label_00043C50:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443C57u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x443C57u));
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != 0u) goto label_00043C67;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x43C67u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x43C67u));
    label_00043C67:
    cpu->edi = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi += cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443C74u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x443C74u));
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = lift_load32(cpu->eax);
    cpu->esi = (uint32_t)(cpu->ecx + cpu->eax);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ecx)) goto label_00043C85;
    cpu->esi = 0u;
    label_00043C85:
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->esi)) goto label_00043CBF;
    if ((uint8_t)(lift_load8(cpu->edi)) != (uint8_t)(0x22u)) goto label_00043CBF;
    cpu->edx = (uint32_t)(cpu->edi + 1u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_00043CBF;
    label_00043C95:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00043CB3;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0xDu)) goto label_00043CB3;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0xAu)) goto label_00043CB3;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x22u)) goto label_00043CB3;
    ++cpu->edx;
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->esi)) goto label_00043C95;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    goto label_0003B000;
    label_00043CB3:
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_00043CBF;
    if ((uint8_t)(lift_load8(cpu->edx)) != (uint8_t)(0x22u)) goto label_00043CBF;
    cpu->ecx = (uint32_t)(cpu->edx + 1u);
    label_00043CBF:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    goto label_0003B000;
    label_00043CD0:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443CD6u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x443CD6u));
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != 0u) goto label_00043CE6;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x43CE6u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x43CE6u));
    label_00043CE6:
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443CF1u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x443CF1u));
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->eax);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->ecx)) goto label_00043D02;
    cpu->edx = 0u;
    label_00043D02:
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edx)) goto label_00043D41;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x41u)) goto label_00043D10;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x5Au)) goto label_00043D1C;
    label_00043D10:
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x61u)) goto label_00043D18;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x7Au)) goto label_00043D1C;
    label_00043D18:
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x5Fu)) goto label_00043D41;
    label_00043D1C:
    cpu->ecx = cpu->esi;
    cpu->edi = cpu->edi;
    label_00043D20:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x41u)) goto label_00043D2A;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x5Au)) goto label_00043D3C;
    label_00043D2A:
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) < (int8_t)(uint8_t)(0x61u)) goto label_00043D32;
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) <= (int8_t)(uint8_t)(0x7Au)) goto label_00043D3C;
    label_00043D32:
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x5Fu)) goto label_00043D3C;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) - (uint64_t)(0x30u) - (uint64_t)(0u))) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) > (uint8_t)(9u)) goto label_00043D41;
    label_00043D3C:
    ++cpu->ecx;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_00043D20;
    label_00043D41:
    cpu->esi = lift_pop32(cpu);
    goto label_0003B000;
    label_00043D50:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443D56u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x443D56u));
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != 0u) goto label_00043D66;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x43D66u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x43D66u));
    label_00043D66:
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443D71u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x443D71u));
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->eax);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->ecx)) goto label_00043D82;
    cpu->edx = 0u;
    label_00043D82:
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edx)) goto label_00043DA1;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x20u)) goto label_00043D90;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(9u)) goto label_00043DA1;
    label_00043D90:
    cpu->ecx = cpu->esi;
    label_00043D92:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x20u)) goto label_00043D9C;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(9u)) goto label_00043DA1;
    label_00043D9C:
    ++cpu->ecx;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_00043D92;
    label_00043DA1:
    cpu->esi = lift_pop32(cpu);
    goto label_0003B000;
    label_00043DB0:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443DB7u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x443DB7u));
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != 0u) goto label_00043DC7;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x43DC7u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x43DC7u));
    label_00043DC7:
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443DD2u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x443DD2u));
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->eax);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->ecx)) goto label_00043DE3;
    cpu->edx = 0u;
    label_00043DE3:
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edx)) goto label_00043E1E;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00043DF0:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    if ((uint8_t)((cpu->ebx & 0xFFu)) == (uint8_t)(0x20u)) goto label_00043DFC;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != (uint8_t)(9u)) goto label_00043E08;
    label_00043DFC:
    ++cpu->eax;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_00043DF0;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    goto label_0003B000;
    label_00043E08:
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_00043E1E;
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0xDu)) goto label_00043E1E;
    ++cpu->eax;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_00043E1E;
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0xAu)) goto label_00043E1E;
    cpu->ecx = (uint32_t)(cpu->eax + 1u);
    label_00043E1E:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    goto label_0003B000;
    label_00043E30:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443E37u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x443E37u));
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != 0u) goto label_00043E47;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x43E47u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x43E47u));
    label_00043E47:
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443E52u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x443E52u));
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->eax);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->ecx)) goto label_00043E63;
    cpu->edx = 0u;
    label_00043E63:
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edx)) goto label_00043EA2;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00043E70:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    if ((uint8_t)((cpu->ebx & 0xFFu)) == 0u) goto label_00043E8C;
    if ((uint8_t)((cpu->ebx & 0xFFu)) == (uint8_t)(0xDu)) goto label_00043E8C;
    if ((uint8_t)((cpu->ebx & 0xFFu)) == (uint8_t)(0xAu)) goto label_00043E8C;
    ++cpu->eax;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_00043E70;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    goto label_0003B000;
    label_00043E8C:
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_00043EA2;
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0xDu)) goto label_00043EA2;
    ++cpu->eax;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_00043EA2;
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0xAu)) goto label_00043EA2;
    cpu->ecx = (uint32_t)(cpu->eax + 1u);
    label_00043EA2:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    goto label_0003B000;
    label_00043EB0:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443EB5u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x443EB5u));
    if ((uint32_t)(cpu->eax) > (uint32_t)(7u)) goto label_00043EE9;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00043EC1;
        case 1u: goto label_00043EC6;
        case 2u: goto label_00043ECB;
        case 3u: goto label_00043ED0;
        case 4u: goto label_00043ED5;
        case 5u: goto label_00043EDA;
        case 6u: goto label_00043EDF;
        case 7u: goto label_00043EE4;
        default: lift_trap(cpu, 0x443EBAu, "resolved jump-table index out of range"); return;
    }
label_00043EC1: ;
    goto label_00043A10;
    label_00043EC6:
    goto label_00043AD0;
    label_00043ECB:
    goto label_00043C00;
    label_00043ED0:
    goto label_00043C50;
    label_00043ED5:
    goto label_00043CD0;
    label_00043EDA:
    goto label_00043D50;
    label_00043EDF:
    goto label_00043DB0;
    label_00043EE4:
    goto label_00043E30;
    label_00043EE9:
    cpu->ecx = (uint32_t)(uintptr_t)"ffparse(). Invalid parsing type";
    sfera_sub_004385D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00443F20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1BCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x1D0u);
    (void)0; /* source SEH registration eliminated */
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443F60u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x443F60u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x1FEu)) goto label_000468DE;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_000441CB;
        case 1u: goto label_00044237;
        case 2u: goto label_0004429E;
        case 3u: goto label_000442AE;
        case 4u: goto label_00044306;
        case 5u: goto label_0004432C;
        case 6u: goto label_0004433B;
        case 7u: goto label_0004434B;
        case 8u: goto label_000443F6;
        case 9u: goto label_0004451D;
        case 10u: goto label_000445A5;
        case 11u: goto label_000445DE;
        case 12u: goto label_00044601;
        case 14u: goto label_0004464F;
        case 18u: goto label_00044675;
        case 19u: goto label_000446CB;
        case 20u: goto label_00044763;
        case 21u: goto label_000447D0;
        case 22u: goto label_00044805;
        case 23u: goto label_000445D4;
        case 24u: goto label_00044814;
        case 25u: goto label_00044824;
        case 26u: goto label_00044834;
        case 27u: goto label_00044844;
        case 28u: goto label_00044854;
        case 29u: goto label_00044864;
        case 32u: goto label_000448EE;
        case 33u: goto label_00044934;
        case 34u: goto label_000449B5;
        case 35u: goto label_000449C8;
        case 36u: goto label_00044A0C;
        case 37u: goto label_00044A6B;
        case 38u: goto label_00044A7E;
        case 39u: goto label_00044ACB;
        case 41u: goto label_00044B13;
        case 43u: goto label_00044B2F;
        case 44u: goto label_00044BC6;
        case 45u: goto label_00044C13;
        case 46u: goto label_00044C62;
        case 47u: goto label_00044C8D;
        case 53u: goto label_00044CA9;
        case 57u: goto label_000440B7;
        case 58u: goto label_00044CBA;
        case 59u: goto label_00044DA3;
        case 60u: goto label_00044DBF;
        case 61u: goto label_00044DCF;
        case 63u: goto label_00044E05;
        case 64u: goto label_00044E3A;
        case 65u: goto label_00044E87;
        case 66u: goto label_00044E97;
        case 67u: goto label_0004503A;
        case 68u: goto label_00045223;
        case 69u: goto label_00045265;
        case 70u: goto label_000452A8;
        case 71u: goto label_00045344;
        case 72u: goto label_00045376;
        case 73u: goto label_000453FB;
        case 74u: goto label_00045433;
        case 75u: goto label_0004545F;
        case 77u: goto label_000454BA;
        case 78u: goto label_000454D4;
        case 79u: goto label_00045533;
        case 80u: goto label_000455AD;
        case 81u: goto label_00045564;
        case 82u: goto label_00045631;
        case 83u: goto label_0004564F;
        case 84u: goto label_00045721;
        case 85u: goto label_00045760;
        case 86u: goto label_00045835;
        case 87u: goto label_000458D6;
        case 88u: goto label_0004592C;
        case 89u: goto label_00045974;
        case 92u: goto label_000459A4;
        case 93u: goto label_00045A34;
        case 94u: goto label_00045A5D;
        case 95u: goto label_00045B8D;
        case 96u: goto label_00045BDA;
        case 98u: goto label_00045C0F;
        case 99u: goto label_00045CCF;
        case 100u: goto label_00045DE9;
        case 103u: goto label_00045E69;
        case 106u: goto label_00045EAB;
        case 107u: goto label_00045EE7;
        case 109u: goto label_00045F0B;
        case 110u: goto label_00045F41;
        case 111u: goto label_00045FD8;
        case 112u: goto label_00045FE8;
        case 113u: goto label_00046003;
        case 114u: goto label_00046047;
        case 115u: goto label_00046081;
        case 116u: goto label_000460B4;
        case 119u: goto label_000460E9;
        case 120u: goto label_0004610E;
        case 121u: goto label_00046131;
        case 122u: goto label_0004617B;
        case 123u: goto label_000461C0;
        case 124u: goto label_00046210;
        case 125u: goto label_0004623E;
        case 126u: goto label_00046296;
        case 127u: goto label_000462DE;
        case 128u: goto label_0004631D;
        case 131u: goto label_0004637B;
        case 132u: goto label_00046442;
        case 133u: case 134u: case 138u: goto label_00043FA1;
        case 136u: goto label_0004646F;
        case 140u: goto label_000464EF;
        case 150u: goto label_00046539;
        case 152u: goto label_00046573;
        case 206u: goto label_0004657D;
        case 207u: goto label_00046598;
        case 212u: goto label_000465AE;
        case 213u: goto label_000465BE;
        case 214u: goto label_000465CF;
        case 215u: goto label_000465E0;
        case 216u: goto label_00046612;
        case 218u: goto label_0004664F;
        case 219u: goto label_000466F6;
        case 220u: goto label_0004672C;
        case 221u: goto label_00046665;
        case 224u: goto label_00046676;
        case 225u: goto label_00044066;
        case 226u: goto label_00044054;
        case 227u: goto label_00043FAD;
        case 228u: goto label_00046846;
        case 229u: goto label_00043F7D;
        case 230u: goto label_000468AC;
        case 231u: goto label_000468BE;
        case 508u: goto label_0004675B;
        case 509u: goto label_00046827;
        case 510u: goto label_00046836;
        default: goto label_000468DE;
    }
label_00043F7D: ;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443F82u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x443F82u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443F89u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x443F89u));
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx -= cpu->ecx;
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi);
    cpu->edx += cpu->eax;
    cpu->ecx += cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x43FA1u)); sfera_sub_00419840(cpu, LIFT_CODE_TOKEN_RVA(0x43FA1u));
    label_00043FA1:
    cpu->ecx = 0u;
    label_00043FA3:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443FA8u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x443FA8u));
    goto label_000468DE;
    label_00043FAD:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443FB2u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x443FB2u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443FB9u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x443FB9u));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443FC0u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x443FC0u));
    cpu->ebp = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x443FC7u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x443FC7u));
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax += cpu->esi;
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000468DE;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + cpu->esi));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + cpu->edi));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + cpu->esi));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 1e-05);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00044042;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444014u)); sfera_sub_004EE9EC(cpu, LIFT_CODE_TOKEN_VA(0x444014u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + cpu->edi));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->ebx + cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->ebp + cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00044042:
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44404Fu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44404Fu));
    goto label_000468DE;
    label_00044054:
    lift_native_call(cpu, native_function_address32(&::GetTickCount), LIFT_CODE_TOKEN_RVA(0x44054u));
    label_0004405A:
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444061u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x444061u));
    goto label_000468DE;
    label_00044066:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44406Bu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44406Bu));
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_store32(cpu->esp + 0x1A4u, cpu->eax);
    lift_store32(cpu->esp + 0x1A8u, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44407Fu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x44407Fu));
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != 0u) goto label_0004408F;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4408Fu)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x4408Fu));
    label_0004408F:
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = (uint32_t)(cpu->esp + 0x1A4u);
    lift_push32(cpu, cpu->eax);
    cpu->edi = (uint32_t)(cpu->esi + cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4440A0u));
    cpu->ecx = 9u;
    cpu->esi = cpu->eax;
    cpu->esp += 4u;
    lift_movs32(cpu, 1u);
    goto label_000468DE;
    label_000440B7:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4440BCu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4440BCu));
    cpu->ecx = (uint32_t)(cpu->esp + 0x1A4u);
    lift_push32(cpu, cpu->ecx);
    cpu->esi = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x4440C6u));
    cpu->edx = (uint32_t)(cpu->esp + 0x1A8u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x4440D4u));
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) > (uint32_t)(9u)) goto label_000441B8;
    switch ((uint32_t)(cpu->esi)) {
        case 0u: goto label_000440ED;
        case 1u: goto label_000440FC;
        case 2u: goto label_0004410B;
        case 3u: goto label_0004411A;
        case 4u: goto label_00044129;
        case 5u: goto label_00044138;
        case 6u: goto label_000441B8;
        case 7u: goto label_00044147;
        case 8u: goto label_00044158;
        case 9u: goto label_0004418A;
        default: lift_trap(cpu, 0x4440E6u, "resolved jump-table index out of range"); return;
    }
label_000440ED: ;
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4440F7u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4440F7u));
    goto label_000468DE;
    label_000440FC:
    cpu->eax = lift_load32(cpu->eax + 0xCu);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444106u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x444106u));
    goto label_000468DE;
    label_0004410B:
    cpu->eax = lift_load32(cpu->eax + 0x10u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444115u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x444115u));
    goto label_000468DE;
    label_0004411A:
    cpu->eax = lift_load32(cpu->eax + 0x14u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444124u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x444124u));
    goto label_000468DE;
    label_00044129:
    cpu->eax = lift_load32(cpu->eax + 0x18u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444133u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x444133u));
    goto label_000468DE;
    label_00044138:
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444142u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x444142u));
    goto label_000468DE;
    label_00044147:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44414Cu)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x44414Cu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444153u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x444153u));
    goto label_000468DE;
    label_00044158:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44415Du)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x44415Du));
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != 0u) goto label_0004416D;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4416Du)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x4416Du));
    label_0004416D:
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax += cpu->esi;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_mktime64), LIFT_CODE_TOKEN_VA(0x444175u));
    cpu->esp += 4u;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444185u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x444185u));
    goto label_000468DE;
    label_0004418A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44418Fu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44418Fu));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444196u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444196u));
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_x87_push(cpu, ::_difftime64(static_cast<__time64_t>(lift_load64(cpu->esp)), static_cast<__time64_t>(lift_load64(cpu->esp + 8u))));
    cpu->esp += 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4441ACu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x4441ACu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4441B3u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4441B3u));
    goto label_000468DE;
    label_000441B8:
    cpu->eax = lift_load32(cpu->esp + 0x1A4u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4441C6u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4441C6u));
    goto label_000468DE;
    label_000441CB:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4441D0u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4441D0u));
    cpu->esi = 0u;
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(3u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000441FC;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4441E4u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4441E4u));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000441FC;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffsys, G_GROUND\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4441F9u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4441F9u));
    cpu->esp += 8u;
    label_000441FC:
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444216u)); sfera_sub_004766E0(cpu, LIFT_CODE_TOKEN_VA(0x444216u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44421Du)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44421Du));
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_000468DE;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->edx + cpu->esi, cpu->ecx);
    goto label_000468DE;
    label_00044237:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44423Cu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44423Cu));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000468DE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44424Fu)); sfera_sub_00454F70(cpu, LIFT_CODE_TOKEN_VA(0x44424Fu));
    g_sfera_inter_scalar_runtime.mode_03 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00044267;
    label_00044258:
    g_sfera_mbc_runtime->active_tag = (uint32_t)(0xFFFFFFFFu);
    goto label_000468DE;
    label_00044267:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44426Cu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44426Cu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    lift_push32(cpu, 0x27CBu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444293u)); sfera_sub_0045CB30(cpu, LIFT_CODE_TOKEN_VA(0x444293u));
    lift_store8(cpu->eax + 0x274u, cpu->ebx & 0xFFu);
    goto label_000468DE;
    label_0004429E:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4442A3u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x4442A3u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.environment_factor, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000468DE;
    label_000442AE:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4442B3u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4442B3u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000468DE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4442C6u)); sfera_sub_00454F70(cpu, LIFT_CODE_TOKEN_VA(0x4442C6u));
    g_sfera_inter_scalar_runtime.mode_03 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00044258;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4442D4u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4442D4u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    lift_push32(cpu, 0x27DAu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4442FBu)); sfera_sub_0045CB30(cpu, LIFT_CODE_TOKEN_VA(0x4442FBu));
    lift_store8(cpu->eax + 0x276u, cpu->ebx & 0xFFu);
    goto label_000468DE;
    label_00044306:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44430Bu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44430Bu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    g_sfera_world_objects.controlled_object_handle = (uint32_t)(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000468DE;
    g_sfera_world_objects.controlled_object_handle = (uint32_t)(0xFFFFFFFFu);
    goto label_000468DE;
    label_0004432C:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444331u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444331u));
    g_sfera_inter_scalar_runtime.mode_01 = (uint32_t)(cpu->eax);
    goto label_000468DE;
    label_0004433B:
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_01;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444346u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x444346u));
    goto label_000468DE;
    label_0004434B:
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_x87_push(cpu, 0.0);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00044382;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44435Du)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44435Du));
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44436Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44436Eu));
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->esp + 0x18u))) / (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    goto label_00044386;
    label_00044382:
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u));
    label_00044386:
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_01;
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x1Fu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(4u), 32u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->eax &= 0x3Fu;
    cpu->ecx &= 3u;
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edx) * 4u));
    lift_store32(cpu->esp + 0x1A4u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1A4u)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000443C4;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000443C4:
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (5760.0));
    lift_x87_set(cpu, 0u, (0.9994999766349792) - (lift_x87_get(cpu, 0u)));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.environment_factor, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)g_sfera_graphics_runtime.environment_factor));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000468DC;
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.environment_factor, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000468DE;
    label_000443F6:
    cpu->eax = g_sfera_inter_scalar_runtime.mode_01;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->edx ^= cpu->eax;
    cpu->ecx = cpu->eax;
    cpu->edx &= 3u;
    cpu->ecx &= 3u;
    cpu->eax ^= cpu->edx;
    g_sfera_inter_scalar_runtime.mode_01 = (uint32_t)(cpu->eax);
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(3u)) goto label_000468DE;
    cpu->eax &= 0xFFFFFFFCu;
    cpu->ecx = cpu->eax;
    cpu->ecx &= 0xFFFFFFFCu;
    cpu->ecx += 4u;
    cpu->ecx ^= cpu->eax;
    cpu->ecx &= 0xFCu;
    cpu->eax ^= cpu->ecx;
    cpu->edx = cpu->eax;
    cpu->edx &= 0xFCu;
    g_sfera_inter_scalar_runtime.mode_01 = (uint32_t)(cpu->eax);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(0xF0u)) goto label_000468DE;
    cpu->eax &= 0xFFFFFF03u;
    cpu->ecx = cpu->eax;
    cpu->ecx &= 0xFFFFFF00u;
    cpu->ecx += 0x100u;
    cpu->ecx ^= cpu->eax;
    cpu->ecx &= 0x1F00u;
    cpu->eax ^= cpu->ecx;
    cpu->edx = cpu->eax;
    cpu->edx &= 0x1F00u;
    g_sfera_inter_scalar_runtime.mode_01 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->edx) != (uint32_t)(0x1800u)) goto label_000468DE;
    cpu->eax &= 0xFFFFE0FFu;
    cpu->esi = cpu->eax;
    cpu->esi &= 0xFFFFE000u;
    cpu->esi += 0x2000u;
    cpu->ecx = cpu->eax;
    cpu->edx = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x12u), 32u);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(0xDu), 32u);
    cpu->esi &= 0x3E000u;
    cpu->ecx &= 0xFu;
    cpu->edx &= 0x1Fu;
    cpu->eax ^= cpu->esi;
    g_sfera_inter_scalar_runtime.mode_01 = (uint32_t)(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(sfera_calendar_days_in_month(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000468DE;
    cpu->eax &= 0xFFFC3FFFu;
    cpu->eax |= 0x2000u;
    cpu->ecx = cpu->eax;
    cpu->ecx &= 0xFFFC0000u;
    cpu->ecx += 0x40000u;
    cpu->ecx ^= cpu->eax;
    cpu->ecx &= 0x3C0000u;
    cpu->eax ^= cpu->ecx;
    cpu->edx = cpu->eax;
    cpu->edx &= 0x3C0000u;
    g_sfera_inter_scalar_runtime.mode_01 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->edx) <= (uint32_t)(0x300000u)) goto label_000468DE;
    cpu->eax &= 0xFFC7FFFFu;
    cpu->eax |= 0x40000u;
    cpu->ecx = cpu->eax;
    cpu->ecx &= 0xFFC00000u;
    cpu->ecx += 0x400000u;
    cpu->eax &= 0x3FFFFFu;
    cpu->ecx ^= cpu->eax;
    g_sfera_inter_scalar_runtime.mode_01 = (uint32_t)(cpu->ecx);
    goto label_000468DE;
    label_0004451D:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444522u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444522u));
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_01;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_0004453E;
    cpu->ecx &= 3u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444539u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x444539u));
    goto label_000468DE;
    label_0004453E:
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00044553;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->ecx &= 0x3Fu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44454Eu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44454Eu));
    goto label_000468DE;
    label_00044553:
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00044568;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->ecx &= 0x1Fu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444563u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x444563u));
    goto label_000468DE;
    label_00044568:
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004457D;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0xDu), 32u);
    cpu->ecx &= 0x1Fu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444578u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x444578u));
    goto label_000468DE;
    label_0004457D:
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(5u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00044592;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x12u), 32u);
    cpu->ecx &= 0xFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44458Du)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44458Du));
    goto label_000468DE;
    label_00044592:
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x16u), 32u);
    cpu->ecx += 0x1E78u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4445A0u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4445A0u));
    goto label_000468DE;
    label_000445A5:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4445AAu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4445AAu));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000468DE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4445BDu)); sfera_sub_00454F70(cpu, LIFT_CODE_TOKEN_VA(0x4445BDu));
    g_sfera_inter_scalar_runtime.mode_03 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00044258;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4445CFu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4445CFu));
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x445D4u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_RVA(0x445D4u));
    label_000445D4:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4445D9u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4445D9u));
    goto label_000468DE;
    label_000445DE:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4445E3u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4445E3u));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_000445F7;
    cpu->ecx = g_sfera_texture_cache_runtime.render_gate;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4445F2u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4445F2u));
    goto label_000468DE;
    label_000445F7:
    g_sfera_texture_cache_runtime.render_gate = (uint32_t)(cpu->eax);
    goto label_000468DE;
    label_00044601:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444606u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444606u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00044624;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffsys, G_ERRMSG\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44461Du)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44461Du));
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->esp += 8u;
    label_00044624:
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    cpu->edx += cpu->eax;
    cpu->edi = cpu->edi;
    label_00044640:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00044640;
    goto label_000468DE;
    label_0004464F:
    if ((uint32_t)(g_sfera_texture_cache_runtime.render_gate) != (uint32_t)(0u)) goto label_00043FA1;
    if ((uint32_t)(g_sfera_client_process_runtime.ui_bridge) != (uint32_t)(0u)) goto label_00043FA1;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44466Eu)); sfera_sub_004C9D30(cpu, LIFT_CODE_TOKEN_VA(0x44466Eu));
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    goto label_00044BFE;
    label_00044675:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44467Au)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44467Au));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444681u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444681u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444695u)); sfera_sub_00455E00(cpu, LIFT_CODE_TOKEN_VA(0x444695u));
    cpu->esi = cpu->eax;
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->argument_count) < (int32_t)(uint32_t)(4u)) goto label_000446AB;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4446A8u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x4446A8u));
    lift_store_f32(cpu->esi + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000446AB:
    if ((uint32_t)(g_sfera_mbc_runtime->argument_count) != (uint32_t)(5u)) goto label_000468DE;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4446BDu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4446BDu));
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->esi + 0x20u, cpu->eax & 0xFFu);
    goto label_000468DE;
    label_000446CB:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4446D0u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4446D0u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4446D7u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4446D7u));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000446EF;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffsys, FINDFIRST\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4446ECu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4446ECu));
    cpu->esp += 8u;
    label_000446EF:
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += cpu->edi;
    lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->script_find_data); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_findfirst64i32), LIFT_CODE_TOKEN_VA(0x44470Au));
    cpu->esp += 8u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0004474C;
    cpu->edx = 2u;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444727u)); sfera_sub_00437A10(cpu, LIFT_CODE_TOKEN_VA(0x444727u));
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->script_find_data.name[0];
    cpu->edx += cpu->esi;
    label_00044734:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00044734;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444747u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x444747u));
    goto label_000468DE;
    label_0004474C:
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store8(cpu->eax + cpu->esi, 0u);
    label_00044755:
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44475Eu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44475Eu));
    goto label_000468DE;
    label_00044763:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444768u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444768u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44476Fu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44476Fu));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00044787;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffsys, FINDNEXT\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444784u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x444784u));
    cpu->esp += 8u;
    label_00044787:
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->script_find_data); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_findnext64i32), LIFT_CODE_TOKEN_VA(0x44479Au));
    cpu->esp += 8u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0004474C;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->script_find_data.name[0];
    cpu->edx += cpu->esi;
    label_000447B8:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000447B8;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4447CBu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4447CBu));
    goto label_000468DE;
    label_000447D0:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4447D5u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4447D5u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000468DE;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x4447E7u));
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444800u)); sfera_sub_00437B10(cpu, LIFT_CODE_TOKEN_VA(0x444800u));
    goto label_000468DE;
    label_00044805:
    g_sfera_mbc_runtime->instruction_step_count = (uint32_t)(0u);
    goto label_000468DE;
    label_00044814:
    cpu->ecx = g_sfera_directplay_runtime.connection_info.round_trip_latency_ms;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44481Fu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44481Fu));
    goto label_000468DE;
    label_00044824:
    cpu->ecx = lift_load32((uintptr_t)&g_sfera_directplay_runtime.connection_info.throughput_bps);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44482Fu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44482Fu));
    goto label_000468DE;
    label_00044834:
    cpu->ecx = g_sfera_network_runtime.bytes_sent_delta;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44483Fu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44483Fu));
    goto label_000468DE;
    label_00044844:
    cpu->ecx = g_sfera_network_runtime.bytes_received_delta;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44484Fu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44484Fu));
    goto label_000468DE;
    label_00044854:
    cpu->ecx = g_sfera_network_runtime.bytes_retried_delta;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44485Fu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44485Fu));
    goto label_000468DE;
    label_00044864:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444869u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444869u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444870u)); sfera_sub_00431820(cpu, LIFT_CODE_TOKEN_VA(0x444870u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444879u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444879u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000448B6;
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    lift_store32(cpu->ecx + 0x90u, 0xFFFFFFFFu);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000448A9;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x448A9u)); sfera_sub_004615E0(cpu, LIFT_CODE_TOKEN_RVA(0x448A9u));
    label_000448A9:
    cpu->ecx |= 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4448B1u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4448B1u));
    goto label_000468DE;
    label_000448B6:
    cpu->edx = cpu->ecx;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    if ((uint32_t)(lift_load32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].field_084))) == (uint32_t)(0u)) goto label_000458C9;
    cpu->edx = g_sfera_mbc_runtime->active_process;
    lift_store32(cpu->edx + 0x90u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_000448E2;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x448E2u)); sfera_sub_004614E0(cpu, LIFT_CODE_TOKEN_RVA(0x448E2u));
    label_000448E2:
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4448E9u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4448E9u));
    goto label_000468DE;
    label_000448EE:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4448F3u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4448F3u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4448FAu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4448FAu));
    lift_x87_push(cpu, 0.0);
    cpu->edx = 0u;
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44490Du)); sfera_sub_004731C0(cpu, LIFT_CODE_TOKEN_VA(0x44490Du));
    if ((uint32_t)(cpu->esi) == 0u) goto label_0004491A;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->ecx + cpu->esi, cpu->eax);
    label_0004491A:
    if ((uint32_t)(cpu->edi) == 0u) goto label_000468DE;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_store_f32(cpu->edx + cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000468DE;
    label_00044934:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444939u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444939u));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00044951;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffsys, G_MOUSEXY, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44494Eu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44494Eu));
    cpu->esp += 8u;
    label_00044951:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444956u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444956u));
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != 0u) goto label_0004496E;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffsys, G_MOUSEXY, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44496Bu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44496Bu));
    cpu->esp += 8u;
    label_0004496E:
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444980u)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x444980u));

    cpu->ecx = (uint32_t)(cpu->esp + 0x1A4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    reinterpret_cast<CCursor*>(cpu->ecx)->getPosition(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1A4u)))));
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store_f32(cpu->eax + cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1A8u)))));
    lift_store_f32(cpu->ecx + cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000468DE;
    label_000449B5:
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_state;
    cpu->ecx &= 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4449C3u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4449C3u));
    goto label_000468DE;
    label_000449C8:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4449CDu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4449CDu));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4449D6u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4449D6u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00044A02;
    cpu->ecx += g_sfera_mbc_runtime->process_memory_base;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_main_command_state_runtime.default_cursor_token[0];
    cpu->esi -= cpu->ecx;
    label_000449F8:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->esi + cpu->ecx, cpu->edx & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000449F8;
    label_00044A02:
    (*(uint32_t*)(void*)&g_sfera_main_command_state_runtime.render_channel_mask) = (uint32_t)(cpu->eax);
    goto label_000468DE;
    label_00044A0C:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444A11u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444A11u));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00044A29;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffsys, G_CURSDIR\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444A26u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x444A26u));
    cpu->esp += 8u;
    label_00044A29:
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.mbc_vector_scratch;
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444A44u)); sfera_sub_004731C0(cpu, LIFT_CODE_TOKEN_VA(0x444A44u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.mbc_vector_scratch));
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store_f32(cpu->eax + cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.mbc_vector_scratch.y));
    lift_store_f32(cpu->eax + cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.mbc_vector_scratch.z));
    lift_store_f32(cpu->eax + cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000468DE;
    label_00044A6B:
    cpu->ecx = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.cursor_state;
    cpu->ecx &= 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444A79u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x444A79u));
    goto label_000468DE;
    label_00044A7E:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444A83u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444A83u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000468DE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444A96u)); sfera_sub_00454F70(cpu, LIFT_CODE_TOKEN_VA(0x444A96u));
    g_sfera_inter_scalar_runtime.mode_03 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00044258;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444AA8u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444AA8u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->edx = g_sfera_inter_scalar_runtime.mode_03;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->edx + 0x139u, cpu->ecx & 0xFFu);
    goto label_000468DE;
    label_00044ACB:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444AD0u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x444AD0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444AD9u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x444AD9u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444AEFu)); sfera_sub_00438460(cpu, LIFT_CODE_TOKEN_VA(0x444AEFu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    cpu->esi = cpu->eax;

    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444AFCu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x444AFCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444B06u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x444B06u));
    lift_push32(cpu, cpu->eax);

    cpu->ecx = cpu->esi;
    reinterpret_cast<CCursor*>(cpu->ecx)->setPosition(cpu);
    goto label_000468DE;
    label_00044B13:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444B18u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444B18u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    g_sfera_recovered_static_runtime.render_gate = (uint32_t)(cpu->eax);
    goto label_000468DE;
    label_00044B2F:
    if ((uint32_t)(g_sfera_mbc_runtime->argument_count) != (uint32_t)(3u)) goto label_00044B54;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444B3Du)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444B3Du));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444B44u)); sfera_sub_00431820(cpu, LIFT_CODE_TOKEN_VA(0x444B44u));
    cpu->esi = cpu->eax;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    cpu->esi += ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0]);
    goto label_00044B5A;
    label_00044B54:
    cpu->esi = g_sfera_mbc_runtime->active_process;
    label_00044B5A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444B5Fu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444B5Fu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000468DE;
    cpu->ecx = (int16_t)(lift_load16(cpu->esi + 0x9Au));
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00043FA3;
    cpu->esi = lift_load32(cpu->esi + 0xA0u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000458C9;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_000458C9;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000458C9;
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = (int16_t)(lift_load16(cpu->esi + ((uint32_t)(cpu->ecx) * 4u)));
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x190u)) goto label_000458C9;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x398u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_world_slot_table_runtime.slots[0].linked_handle));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444BC1u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x444BC1u));
    goto label_000468DE;
    label_00044BC6:
    cpu->ecx = g_sfera_world_objects.controlled_object_handle;
    if ((int32_t)(uint32_t)(cpu->ecx) < 0) goto label_00043FA1;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444BD9u)); sfera_sub_00454F70(cpu, LIFT_CODE_TOKEN_VA(0x444BD9u));
    g_sfera_inter_scalar_runtime.mode_03 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00043FA1;
    lift_push32(cpu, 0x2980u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444BF7u)); sfera_sub_0045CB30(cpu, LIFT_CODE_TOKEN_VA(0x444BF7u));
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x142u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    label_00044BFE:
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00043FA1;
    label_00044C04:
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444C0Eu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x444C0Eu));
    goto label_000468DE;
    label_00044C13:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444C18u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444C18u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444C21u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444C21u));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00044C39;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffsys, LINK_ON\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444C36u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x444C36u));
    cpu->esp += 8u;
    label_00044C39:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444C3Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444C3Eu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->edx += cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444C5Du)); sfera_sub_00479FD0(cpu, LIFT_CODE_TOKEN_VA(0x444C5Du));
    goto label_000468DE;
    label_00044C62:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444C67u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444C67u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444C70u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444C70u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444C88u)); sfera_sub_004593C0(cpu, LIFT_CODE_TOKEN_VA(0x444C88u));
    goto label_000468DE;
    label_00044C8D:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444C92u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444C92u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_08) = (uint32_t)(cpu->eax);
    goto label_000468DE;
    label_00044CA9:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444CAEu)); sfera_sub_00433E10(cpu, LIFT_CODE_TOKEN_VA(0x444CAEu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444CB5u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x444CB5u));
    goto label_000468DE;
    label_00044CBA:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444CBFu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444CBFu));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444CC8u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444CC8u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(1u)) goto label_00044CF8;
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_01;
    cpu->edx = cpu->ecx;
    cpu->edx ^= cpu->eax;
    cpu->edx &= 3u;
    cpu->ecx ^= cpu->edx;
    g_sfera_inter_scalar_runtime.mode_01 = (uint32_t)(cpu->ecx);
    goto label_000468DE;
    label_00044CF8:
    if ((uint32_t)(cpu->ecx) != (uint32_t)(2u)) goto label_00044D1D;
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->eax) * 4u));
    cpu->eax = g_sfera_inter_scalar_runtime.mode_01;
    cpu->ecx ^= cpu->eax;
    cpu->ecx &= 0xFCu;
    cpu->eax ^= cpu->ecx;
    g_sfera_inter_scalar_runtime.mode_01 = (uint32_t)(cpu->eax);
    goto label_000468DE;
    label_00044D1D:
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(3u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00044D3F;
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_01;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax ^= cpu->ecx;
    cpu->eax &= 0x1F00u;
    cpu->ecx ^= cpu->eax;
    g_sfera_inter_scalar_runtime.mode_01 = (uint32_t)(cpu->ecx);
    goto label_000468DE;
    label_00044D3F:
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00044D61;
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_01;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0xDu), 32u);
    cpu->eax ^= cpu->ecx;
    cpu->eax &= 0x3E000u;
    cpu->ecx ^= cpu->eax;
    g_sfera_inter_scalar_runtime.mode_01 = (uint32_t)(cpu->ecx);
    goto label_000468DE;
    label_00044D61:
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(5u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00044D83;
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_01;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x12u), 32u);
    cpu->eax ^= cpu->ecx;
    cpu->eax &= 0x3C0000u;
    cpu->ecx ^= cpu->eax;
    g_sfera_inter_scalar_runtime.mode_01 = (uint32_t)(cpu->ecx);
    goto label_000468DE;
    label_00044D83:
    cpu->edx = g_sfera_inter_scalar_runtime.mode_01;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x188u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x16u), 32u);
    cpu->edx &= 0x3FFFFFu;
    cpu->eax ^= cpu->edx;
    g_sfera_inter_scalar_runtime.mode_01 = (uint32_t)(cpu->eax);
    goto label_000468DE;
    label_00044DA3:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444DA8u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444DA8u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    (*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_27) = (uint32_t)(cpu->eax);
    goto label_000468DE;
    label_00044DBF:
    cpu->ecx = g_sfera_recovered_static_runtime.server_number;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444DCAu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x444DCAu));
    goto label_000468DE;
    label_00044DCF:
    cpu->eax = g_sfera_mbc_runtime->active_process;
    if ((uint32_t)(lift_load32(cpu->eax + 0xB4u)) != (uint32_t)(0u)) goto label_00044DF9;
    lift_push32(cpu, 0x2A2Au); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp"); lift_push32(cpu, (uintptr_t)"Unloading _main: %s:%d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444DF1u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x444DF1u));
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->esp += 0xCu;
    label_00044DF9:
    lift_store32(cpu->eax + 0x94u, (uint64_t)(lift_load32(cpu->eax + 0x94u)) | (uint64_t)(0x20u));
    goto label_000468DE;
    label_00044E05:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444E0Au)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444E0Au));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444E13u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x444E13u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444E35u)); sfera_sub_0046EC60(cpu, LIFT_CODE_TOKEN_VA(0x444E35u));
    goto label_000468DE;
    label_00044E3A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444E3Fu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444E3Fu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000468DE;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00044E6E;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffsys, PLAY_MUSIC\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444E63u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x444E63u));
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00044E7B;
    label_00044E6E:
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += cpu->eax;
    if ((uint8_t)(lift_load8(cpu->ecx)) != (uint8_t)(0u)) goto label_00044E7D;
    label_00044E7B:
    cpu->ecx = 0u;
    label_00044E7D:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444E82u)); sfera_sub_004998A0(cpu, LIFT_CODE_TOKEN_VA(0x444E82u));
    goto label_000468DE;
    label_00044E87:
    cpu->ecx = g_sfera_client_process_runtime.client_object;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444E92u)); sfera_sub_004210D0(cpu, LIFT_CODE_TOKEN_VA(0x444E92u));
    goto label_000468DE;
    label_00044E97:
    cpu->ebx = 0u;
    cpu->ebp = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444EA0u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444EA0u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00044EBA;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffsys, GZ_PACK, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444EB7u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x444EB7u));
    cpu->esp += 8u;
    label_00044EBA:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444EBFu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x444EBFu));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00044ED7;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffsys, GZ_PACK, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444ED4u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x444ED4u));
    cpu->esp += 8u;
    label_00044ED7:
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(cpu->ebx)) goto label_000468DE;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi = (uint32_t)(cpu->eax + cpu->esi);
    cpu->eax += lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444EF8u)); sfera_sub_0042EBE0(cpu, LIFT_CODE_TOKEN_VA(0x444EF8u));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444EFFu)); sfera_sub_0042F2A0(cpu, LIFT_CODE_TOKEN_VA(0x444EFFu));
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00044F0D;
    cpu->ecx |= 0xFFFFFFFFu;
    goto label_00044FFD;
    label_00044F0D:
    cpu->edx = 0u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444F16u)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x444F16u));
    cpu->edi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00044F24;
    cpu->ecx |= 0xFFFFFFFFu;
    goto label_00044FFD;
    label_00044F24:
    lift_push32(cpu, 0x2A62u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444F35u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x444F35u));
    cpu->ebx = cpu->eax;
    cpu->eax = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_fstat64i32), LIFT_CODE_TOKEN_VA(0x444F3Du));
    cpu->ecx = lift_load32(cpu->esp + 0x78u);
    cpu->eax = lift_load32(cpu->esp + 0x74u);
    cpu->esp += 8u;
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x44u, cpu->ecx);
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444F68u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x444F68u));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444F6Fu)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x444F6Fu));
    cpu->ecx = cpu->esi;
    { int64_t v=(int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x65u); cpu->ecx= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->eax = 0x51EB851Fu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(5u), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    cpu->ecx = (uint32_t)(cpu->edx + cpu->ecx + 0x14u);
    lift_push32(cpu, 0x2A69u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444F9Au)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x444F9Au));
    cpu->ebp = cpu->eax;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444FA9u)); sfera_sub_0047E900(cpu, LIFT_CODE_TOKEN_VA(0x444FA9u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_00044FB2;
    cpu->ecx |= 0xFFFFFFFFu;
    goto label_00044FFD;
    label_00044FB2:
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, 0x180u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_chmod), LIFT_CODE_TOKEN_VA(0x444FBCu));
    cpu->esp += 8u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444FCCu)); sfera_sub_0042EE20(cpu, LIFT_CODE_TOKEN_VA(0x444FCCu));
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00044FD7;
    cpu->ecx |= 0xFFFFFFFFu;
    goto label_00044FFD;
    label_00044FD7:
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444FE5u)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x444FE5u));
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_futime64), LIFT_CODE_TOKEN_VA(0x444FEBu));
    cpu->esp += 8u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x444FFBu)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x444FFBu));
    cpu->ecx = 0u;
    label_00044FFD:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445002u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x445002u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445007u)); sfera_sub_0042EBD0(cpu, LIFT_CODE_TOKEN_VA(0x445007u));
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0004501C;
    lift_push32(cpu, 0x2A73u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4501Cu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_RVA(0x4501Cu));
    label_0004501C:
    if ((uint32_t)(cpu->ebp) == 0u) goto label_000468DE;
    lift_push32(cpu, 0x2A74u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445035u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x445035u));
    goto label_000468DE;
    label_0004503A:
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445045u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445045u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_0004505F;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffsys, GZ_UNPACK, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44505Cu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44505Cu));
    cpu->esp += 8u;
    label_0004505F:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445064u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445064u));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_0004507C;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffsys, GZ_UNPACK, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445079u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x445079u));
    cpu->esp += 8u;
    label_0004507C:
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(cpu->ebx)) goto label_000468DE;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edi = (uint32_t)(cpu->eax + cpu->esi);
    cpu->ebp = (uint32_t)(cpu->eax + cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44509Cu)); sfera_sub_0042EBE0(cpu, LIFT_CODE_TOKEN_VA(0x44509Cu));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4450A3u)); sfera_sub_0042F2A0(cpu, LIFT_CODE_TOKEN_VA(0x4450A3u));
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000450B1;
    cpu->ecx |= 0xFFFFFFFFu;
    goto label_000451E4;
    label_000450B1:
    cpu->edx = 0u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4450BAu)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x4450BAu));
    cpu->edi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_000450C8;
    cpu->ecx |= 0xFFFFFFFFu;
    goto label_000451E4;
    label_000450C8:
    lift_push32(cpu, 0x2A8Bu);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4450DAu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x4450DAu));
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::_fstat64i32), LIFT_CODE_TOKEN_VA(0x4450E2u));
    cpu->ecx = lift_load32(cpu->esp + 0x78u);
    cpu->eax = lift_load32(cpu->esp + 0x74u);
    cpu->esp += 8u;
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x44u, cpu->ecx);
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44510Du)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x44510Du));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445114u)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x445114u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x20u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445129u)); sfera_sub_0047E870(cpu, LIFT_CODE_TOKEN_VA(0x445129u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_0004516B;
    lift_push32(cpu, 0x180u); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_chmod), LIFT_CODE_TOKEN_VA(0x445133u));
    cpu->esp += 8u;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445143u)); sfera_sub_0042EE20(cpu, LIFT_CODE_TOKEN_VA(0x445143u));
    cpu->edi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_00045151;
    cpu->ecx |= 0xFFFFFFFFu;
    goto label_000451E4;
    label_00045151:
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44515Bu)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x44515Bu));
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_futime64), LIFT_CODE_TOKEN_VA(0x445161u));
    cpu->ecx = cpu->edi;
    goto label_000451DA;
    label_0004516B:
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, 0x2AA1u);
    cpu->ecx += 0x64u;
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445181u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x445181u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x24u, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445194u)); sfera_sub_0047E870(cpu, LIFT_CODE_TOKEN_VA(0x445194u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_0004519D;
    cpu->ecx |= 0xFFFFFFFFu;
    goto label_000451E4;
    label_0004519D:
    lift_push32(cpu, 0x180u); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_chmod), LIFT_CODE_TOKEN_VA(0x4451A3u));
    cpu->esp += 8u;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4451B3u)); sfera_sub_0042EE20(cpu, LIFT_CODE_TOKEN_VA(0x4451B3u));
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_000451BE;
    cpu->ecx |= 0xFFFFFFFFu;
    goto label_000451E4;
    label_000451BE:
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4451CCu)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x4451CCu));
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_futime64), LIFT_CODE_TOKEN_VA(0x4451D2u));
    cpu->ecx = cpu->esi;
    label_000451DA:
    cpu->esp += 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4451E2u)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x4451E2u));
    cpu->ecx = 0u;
    label_000451E4:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4451E9u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4451E9u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4451EEu)); sfera_sub_0042EBD0(cpu, LIFT_CODE_TOKEN_VA(0x4451EEu));
    if ((uint32_t)(cpu->ebx) == 0u) goto label_00045203;
    lift_push32(cpu, 0x2AABu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x45203u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_RVA(0x45203u));
    label_00045203:
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000468DE;
    lift_push32(cpu, 0x2AACu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44521Eu)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x44521Eu));
    goto label_000468DE;
    label_00045223:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445228u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445228u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00045246;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffsys, MAP_LOAD\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44523Fu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44523Fu));
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->esp += 8u;
    label_00045246:
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445260u)); sfera_sub_00450DD0(cpu, LIFT_CODE_TOKEN_VA(0x445260u));
    goto label_000468DE;
    label_00045265:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44526Au)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44526Au));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00045288;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffsys, MAP_SAVE\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445281u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x445281u));
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->esp += 8u;
    label_00045288:
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4452A3u)); sfera_sub_004601F0(cpu, LIFT_CODE_TOKEN_VA(0x4452A3u));
    goto label_000468DE;
    label_000452A8:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4452ADu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4452ADu));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000452C7;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffsys, MAP_PICSIZE, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4452C4u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4452C4u));
    cpu->esp += 8u;
    label_000452C7:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4452CCu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4452CCu));
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != 0u) goto label_000452E4;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffsys, MAP_PICSIZE, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4452E1u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4452E1u));
    cpu->esp += 8u;
    label_000452E4:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4452E9u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4452E9u));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00045301;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffsys, MAP_PICSIZE, 3\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4452FEu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4452FEu));
    cpu->esp += 8u;
    label_00045301:
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx += g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445326u)); sfera_sub_00450B30(cpu, LIFT_CODE_TOKEN_VA(0x445326u));
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x18u)) & 0xFFu);
    lift_store8(cpu->eax + cpu->edi, cpu->ecx & 0xFFu);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x1Cu)) & 0xFFu);
    lift_store8(cpu->edx + cpu->esi, cpu->eax & 0xFFu);
    goto label_000468DE;
    label_00045344:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445349u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445349u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445352u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445352u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = 0u;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store32(((uint32_t)(cpu->edx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_client_config_runtime.state_12), cpu->ecx);
    goto label_000468DE;
    label_00045376:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44537Bu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44537Bu));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445384u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445384u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_000453DC;
    cpu->edi = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += cpu->edi;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_process_runtime.executable_path[0];
    cpu->esi -= cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000453B0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->ecx + cpu->esi, cpu->edx & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000453B0;
    cpu->eax += cpu->edi;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_relaunch_runtime.argument[0];
    cpu->edx -= cpu->eax;
    label_000453C3:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->eax + cpu->edx, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000453C3;
    g_sfera_render_lookup_runtime.initialized = (uint32_t)(1u);
    goto label_000468DE;
    label_000453DC:
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += cpu->edx;
    lift_push32(cpu, 0u);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    lift_native_call(cpu, native_function_address32(&::_spawnl), LIFT_CODE_TOKEN_VA(0x4453EDu));
    cpu->esp += 0x14u;
    goto label_000468DE;
    label_000453FB:
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->argument_count) <= (int32_t)(uint32_t)(1u)) goto label_00045429;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445409u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445409u));
    { uint64_t l=(uint64_t)((*(uint32_t*)(void*)&g_sfera_client_config_runtime.state_19)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00043FA1;
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445424u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x445424u));
    goto label_000468DE;
    label_00045429:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44542Eu)); sfera_sub_0047AB30(cpu, LIFT_CODE_TOKEN_VA(0x44542Eu));
    goto label_000468DE;
    label_00045433:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445438u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445438u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445441u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445441u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445448u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445448u));
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = g_sfera_client_process_runtime.client_object;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44545Au)); sfera_sub_00420860(cpu, LIFT_CODE_TOKEN_VA(0x44545Au));
    goto label_000468DE;
    label_0004545F:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445464u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445464u));
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44546Fu)); sfera_sub_0042AFB0(cpu, LIFT_CODE_TOKEN_VA(0x44546Fu));
    cpu->edx = g_sfera_world_objects.controlled_object_handle;
    if ((int32_t)(uint32_t)(cpu->edx) <= 0) goto label_000468DE;
    if ((uint32_t)(lift_load32(cpu->esp + 0x14u)) == (uint32_t)(0u)) goto label_00045498;
    cpu->ecx = 0x12Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44548Eu)); sfera_sub_0042AB10(cpu, LIFT_CODE_TOKEN_VA(0x44548Eu));
    g_sfera_network_runtime.pending_slot = (uint32_t)(cpu->eax);
    goto label_000468DE;
    label_00045498:
    cpu->ecx = g_sfera_network_runtime.pending_slot;
    if ((int32_t)(uint32_t)(cpu->ecx) < 0) goto label_000468DE;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4454ABu)); sfera_sub_00429B20(cpu, LIFT_CODE_TOKEN_VA(0x4454ABu));
    g_sfera_network_runtime.pending_slot = (uint32_t)(0xFFFFFFFFu);
    goto label_000468DE;
    label_000454BA:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4454BFu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4454BFu));
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::Sleep), LIFT_CODE_TOKEN_VA(0x4454C4u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4454CFu)); sfera_sub_0044C160(cpu, LIFT_CODE_TOKEN_VA(0x4454CFu));
    goto label_000468DE;
    label_000454D4:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4454D9u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4454D9u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000468DE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4454ECu)); sfera_sub_00454F70(cpu, LIFT_CODE_TOKEN_VA(0x4454ECu));
    g_sfera_inter_scalar_runtime.mode_03 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00044258;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4454FEu)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x4454FEu));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_03;
    lift_push32(cpu, 0x2B35u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445524u)); sfera_sub_0045CB30(cpu, LIFT_CODE_TOKEN_VA(0x445524u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->eax + 0x148u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000468DE;
    label_00045533:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445538u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445538u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44553Fu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44553Fu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->argument_count), r=(uint64_t)(3u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = g_sfera_client_process_runtime.client_object;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0004555A;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445555u)); sfera_sub_0041F3C0(cpu, LIFT_CODE_TOKEN_VA(0x445555u));
    goto label_000468DE;
    label_0004555A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44555Fu)); sfera_sub_0041F400(cpu, LIFT_CODE_TOKEN_VA(0x44555Fu));
    goto label_000468DE;
    label_00045564:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445569u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x445569u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445572u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x445572u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44557Bu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44557Bu));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445582u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445582u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    cpu->ecx = g_sfera_client_process_runtime.client_object;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4455A1u)); sfera_sub_00420720(cpu, LIFT_CODE_TOKEN_VA(0x4455A1u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4455A8u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4455A8u));
    goto label_000468DE;
    label_000455AD:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4455B2u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4455B2u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000458C9;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    if ((uint32_t)(g_sfera_mbc_runtime->argument_count) != (uint32_t)(3u)) goto label_000455DB;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4455D9u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4455D9u));
    goto label_00045605;
    label_000455DB:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4455E0u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4455E0u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4455E7u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4455E7u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4455EEu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4455EEu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x45605u)); sfera_sub_00451570(cpu, LIFT_CODE_TOKEN_RVA(0x45605u));
    label_00045605:
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->esi = cpu->eax;
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445612u)); sfera_sub_00456D60(cpu, LIFT_CODE_TOKEN_VA(0x445612u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000458C9;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445625u)); sfera_sub_00460C90(cpu, LIFT_CODE_TOKEN_VA(0x445625u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44562Cu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44562Cu));
    goto label_000468DE;
    label_00045631:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445636u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445636u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44564Au)); sfera_sub_0047B3D0(cpu, LIFT_CODE_TOKEN_VA(0x44564Au));
    goto label_000468DE;
    label_0004564F:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445654u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445654u));
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ebx) != 0u) goto label_0004566C;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffsys, G_PLANT, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445669u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x445669u));
    cpu->esp += 8u;
    label_0004566C:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445671u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445671u));
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != 0u) goto label_00045689;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffsys, G_PLANT, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445686u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x445686u));
    cpu->esp += 8u;
    label_00045689:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44568Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44568Eu));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000456A6;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffsys, G_PLANT, 3\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4456A3u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x4456A3u));
    cpu->esp += 8u;
    label_000456A6:
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx += cpu->ebx;
    cpu->edx = (uint32_t)(cpu->esp + 0x1A8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4456CCu)); sfera_sub_00459530(cpu, LIFT_CODE_TOKEN_VA(0x4456CCu));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000458C9;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1A4u));
    lift_store_f32(cpu->eax + cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = 0u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1A8u));
    lift_store_f32(cpu->eax + cpu->edi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1ACu));
    lift_store_f32(cpu->eax + cpu->edi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_store_f32(cpu->eax + cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store_f32(cpu->eax + cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store_f32(cpu->eax + cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44571Cu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44571Cu));
    goto label_000468DE;
    label_00045721:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445726u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445726u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000468DE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445739u)); sfera_sub_00454F70(cpu, LIFT_CODE_TOKEN_VA(0x445739u));
    g_sfera_inter_scalar_runtime.mode_03 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00044258;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = lift_load32(cpu->eax + 0x20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44575Bu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44575Bu));
    goto label_000468DE;
    label_00045760:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445765u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445765u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44576Cu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44576Cu));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445775u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445775u));
    cpu->ebx = 0u;
    cpu->ebp = cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(cpu->ebx)) goto label_000468DE;
    if ((uint32_t)(g_sfera_inter_scalar_runtime.mode_04) == (uint32_t)(cpu->ebx)) goto label_000457BC;
    cpu->edx = 0x2B9Bu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44579Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x44579Cu));
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_04;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000457B6;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4457ADu)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4457ADu));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4457B3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4457B3u));
    cpu->esp += 4u;
    label_000457B6:
    g_sfera_inter_scalar_runtime.mode_04 = (uint32_t)(cpu->ebx);
    label_000457BC:
    cpu->edx = 0x2B9Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4457CBu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4457CBu));
    lift_push32(cpu, 0x648u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4457D5u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4457D5u));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x1A4u, cpu->eax);
    lift_store32(cpu->esp + 0x1D8u, cpu->ebx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000457FF;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx += lift_load32(cpu->esp + 0x14u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4457FDu)); sfera_sub_0049A950(cpu, LIFT_CODE_TOKEN_VA(0x4457FDu));
    goto label_00045801;
    label_000457FF:
    cpu->eax = 0u;
    label_00045801:
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += cpu->ebp;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x1DCu, 0xFFFFFFFFu);
    g_sfera_inter_scalar_runtime.mode_04 = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445821u)); sfera_sub_0049B0B0(cpu, LIFT_CODE_TOKEN_VA(0x445821u));
    if ((uint32_t)(cpu->eax) != 0u) goto label_000458C9;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445830u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x445830u));
    goto label_000468DE;
    label_00045835:
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_04;
    cpu->edi = 0u;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000458C9;
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44584Fu)); sfera_sub_0049A9B0(cpu, LIFT_CODE_TOKEN_VA(0x44584Fu));
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edi)) goto label_00045891;
    cpu->edx = 0x2BAAu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445862u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x445862u));
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_04;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0004587C;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445873u)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x445873u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445879u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x445879u));
    cpu->esp += 4u;
    label_0004587C:
    cpu->ecx = 0x65u;
    g_sfera_inter_scalar_runtime.mode_04 = (uint32_t)(cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44588Cu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44588Cu));
    goto label_000468DE;
    label_00045891:
    if ((uint32_t)(cpu->eax) != (uint32_t)(5u)) goto label_00044755;
    cpu->edx = 0x2BB1u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4458A9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4458A9u));
    cpu->ecx = g_sfera_inter_scalar_runtime.mode_04;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000458C3;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4458BAu)); sfera_sub_0042B7D0(cpu, LIFT_CODE_TOKEN_VA(0x4458BAu));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4458C0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4458C0u));
    cpu->esp += 4u;
    label_000458C3:
    g_sfera_inter_scalar_runtime.mode_04 = (uint32_t)(cpu->edi);
    label_000458C9:
    cpu->ecx |= 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4458D1u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4458D1u));
    goto label_000468DE;
    label_000458D6:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4458DBu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4458DBu));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4458E4u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x4458E4u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4458EDu)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x4458EDu));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    cpu->ecx = g_sfera_client_process_runtime.client_object;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445920u)); sfera_sub_00421600(cpu, LIFT_CODE_TOKEN_VA(0x445920u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445927u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x445927u));
    goto label_000468DE;
    label_0004592C:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445931u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x445931u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44593Au)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x44593Au));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    cpu->ecx = g_sfera_client_process_runtime.client_object;
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445968u)); sfera_sub_004216D0(cpu, LIFT_CODE_TOKEN_VA(0x445968u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44596Fu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44596Fu));
    goto label_000468DE;
    label_00045974:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445979u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445979u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445980u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445980u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445987u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445987u));
    lift_push32(cpu, cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(cpu->eax + cpu->edi);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_client_process_runtime.client_object;
    cpu->eax += cpu->esi;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44599Fu)); sfera_sub_0041F930(cpu, LIFT_CODE_TOKEN_VA(0x44599Fu));
    goto label_000468DE;
    label_000459A4:
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.mbc_service_object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4459AEu)); sfera_sub_004226C0(cpu, LIFT_CODE_TOKEN_VA(0x4459AEu));
    if ((uint32_t)(g_sfera_inter_scalar_runtime.state_03) == (uint32_t)(0u)) goto label_000459E0;
    cpu->edx = 0x2C07u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4459C6u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4459C6u));
    cpu->ecx = g_sfera_inter_scalar_runtime.state_03;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000459E0;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4459D7u)); sfera_sub_00489D50(cpu, LIFT_CODE_TOKEN_VA(0x4459D7u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4459DDu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4459DDu));
    cpu->esp += 4u;
    label_000459E0:
    cpu->edx = 0x2C0Bu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4459EFu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4459EFu));
    lift_push32(cpu, 0x20C9Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4459F9u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4459F9u));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x1A4u, cpu->eax);
    lift_store32(cpu->esp + 0x1D8u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00045A28;
    lift_push32(cpu, (uint32_t)(uintptr_t)"mbc\\");
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445A1Eu)); sfera_sub_00489F30(cpu, LIFT_CODE_TOKEN_VA(0x445A1Eu));
    g_sfera_inter_scalar_runtime.state_03 = (uint32_t)(cpu->eax);
    goto label_000468DE;
    label_00045A28:
    cpu->eax = 0u;
    g_sfera_inter_scalar_runtime.state_03 = (uint32_t)(cpu->eax);
    goto label_000468DE;
    label_00045A34:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445A39u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445A39u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_mkdir), LIFT_CODE_TOKEN_VA(0x445A4Fu));
    cpu->esp += 4u;
    goto label_000468DE;
    label_00045A5D:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445A62u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x445A62u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445A6Bu)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x445A6Bu));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, fabs(lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)70.0f));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00045ABB;
    label_00045AAB:
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00045AAF:
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445AB6u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x445AB6u));
    goto label_000468DE;
    label_00045ABB:
    lift_x87_push(cpu, (double)-742.0f);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00045AE6;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_00045AE8;
    label_00045AD3:
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = 1u;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445AE1u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x445AE1u));
    goto label_000468DE;
    label_00045AE6:
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00045AE8:
    lift_x87_push(cpu, -492.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00045B02;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00045AD3;
    goto label_00045B04;
    label_00045B02:
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00045B04:
    lift_x87_push(cpu, -242.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00045B1E;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00045AD3;
    goto label_00045B20;
    label_00045B1E:
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00045B20:
    lift_x87_push(cpu, 7.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00045B3A;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00045AD3;
    goto label_00045B3C;
    label_00045B3A:
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00045B3C:
    lift_x87_push(cpu, (double)257.0f);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00045B5A;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_00045AD3;
    goto label_00045B5C;
    label_00045B5A:
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00045B5C:
    lift_x87_push(cpu, 507.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00045AAB;
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00045AAF;
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445B88u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x445B88u));
    goto label_000468DE;
    label_00045B8D:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445B92u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x445B92u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445B9Bu)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x445B9Bu));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445BC3u)); sfera_sub_004519B0(cpu, LIFT_CODE_TOKEN_VA(0x445BC3u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_00043FA1;
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445BD5u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x445BD5u));
    goto label_000468DE;
    label_00045BDA:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445BDFu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445BDFu));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445BE8u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x445BE8u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445C0Au)); sfera_sub_004570A0(cpu, LIFT_CODE_TOKEN_VA(0x445C0Au));
    goto label_000468DE;
    label_00045C0F:
    if ((uint32_t)(g_sfera_recovered_static_runtime.render_state_08) == (uint32_t)(0u)) goto label_000468DE;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445C21u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445C21u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445C28u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445C28u));
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445C31u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445C31u));
    cpu->ebx = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445C39u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445C39u));
    cpu->eax = cpu->eax & 0xFFu;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445C45u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445C45u));
    cpu->ecx = cpu->eax & 0xFFu;
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445C51u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445C51u));
    cpu->eax = cpu->eax & 0xFFu;
    cpu->ecx = 0x30u;
    lift_store8(cpu->esp + 0x43u, cpu->ebx & 0xFFu);
    if ((int32_t)(uint32_t)(cpu->ebx) > 0) goto label_00045C65;
    lift_store8(cpu->esp + 0x43u, cpu->ecx & 0xFFu);
    label_00045C65:
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_store8(cpu->esp + 0x45u, cpu->edx & 0xFFu);
    if ((int32_t)(uint32_t)(cpu->edx) > 0) goto label_00045C76;
    lift_store8(cpu->esp + 0x45u, 0x31u);
    label_00045C76:
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_store8(cpu->esp + 0x46u, cpu->edx & 0xFFu);
    if ((int32_t)(uint32_t)(cpu->edx) > 0) goto label_00045C86;
    lift_store8(cpu->esp + 0x46u, cpu->ecx & 0xFFu);
    label_00045C86:
    lift_store8(cpu->esp + 0x44u, cpu->eax & 0xFFu);
    if ((int32_t)(uint32_t)(cpu->eax) > 0) goto label_00045C92;
    lift_store8(cpu->esp + 0x44u, cpu->ecx & 0xFFu);
    label_00045C92:
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    lift_store8(cpu->esp + 0x46u, cpu->ecx & 0xFFu);
    cpu->ecx = g_sfera_recovered_static_runtime.render_state_08;
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x44u, 0x303030u);
    lift_store16(cpu->esp + 0x4Fu, 0u);
    lift_store16(cpu->esp + 0x48u, 0x3030u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445CCAu)); sfera_sub_0041C3E0(cpu, LIFT_CODE_TOKEN_VA(0x445CCAu));
    goto label_000468DE;
    label_00045CCF:
    if ((uint32_t)(g_sfera_recovered_static_runtime.render_state_08) == (uint32_t)(0u)) goto label_000468DE;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445CE1u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445CE1u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445CE8u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445CE8u));
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445CF1u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445CF1u));
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445CFAu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445CFAu));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445D01u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445D01u));
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445D0Au)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445D0Au));
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445D13u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445D13u));
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445D1Cu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445D1Cu));
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445D25u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445D25u));
    lift_store32(cpu->esp + 0x1A4u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445D31u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445D31u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000468DE;
    cpu->ecx = g_sfera_recovered_static_runtime.render_state_08;
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445D53u)); sfera_sub_0041C520(cpu, LIFT_CODE_TOKEN_VA(0x445D53u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000468DE;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00045D67;
    lift_store8(cpu->esp + 0x3Cu, cpu->eax & 0xFFu);
    label_00045D67:
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00045D73;
    lift_store8(cpu->esp + 0x3Du, cpu->eax & 0xFFu);
    label_00045D73:
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = 0x30u;
    if ((uint32_t)(cpu->ebx) != 0u) goto label_00045D88;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00045D8C;
    cpu->ebx = cpu->ecx;
    goto label_00045D8C;
    label_00045D88:
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->ecx)) goto label_00045D90;
    label_00045D8C:
    lift_store8(cpu->esp + 0x3Eu, cpu->ebx & 0xFFu);
    label_00045D90:
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_00045D98;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00045D9C;
    label_00045D98:
    lift_store8(cpu->esp + 0x3Fu, cpu->eax & 0xFFu);
    label_00045D9C:
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00045DA8;
    lift_store8(cpu->esp + 0x42u, cpu->eax & 0xFFu);
    label_00045DA8:
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x2Cu)) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x28u)) & 0xFFu);
    lift_store8(cpu->esp + 0x48u, cpu->ecx & 0xFFu);
    lift_store8(cpu->esp + 0x47u, cpu->edx & 0xFFu);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00045DC4;
    lift_store8(cpu->esp + 0x40u, cpu->eax & 0xFFu);
    label_00045DC4:
    cpu->eax = lift_load32(cpu->esp + 0x1A4u);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00045DD3;
    lift_store8(cpu->esp + 0x41u, cpu->eax & 0xFFu);
    label_00045DD3:
    cpu->ecx = g_sfera_recovered_static_runtime.render_state_08;
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445DE4u)); sfera_sub_0041C3E0(cpu, LIFT_CODE_TOKEN_VA(0x445DE4u));
    goto label_000468DE;
    label_00045DE9:
    if ((uint32_t)(g_sfera_recovered_static_runtime.render_state_08) == (uint32_t)(0u)) goto label_00043FA1;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445DFBu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445DFBu));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445E02u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445E02u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000468DE;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00045E2F;
    cpu->ecx = g_sfera_recovered_static_runtime.render_state_08;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445E23u)); sfera_sub_0041BF70(cpu, LIFT_CODE_TOKEN_VA(0x445E23u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445E2Au)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x445E2Au));
    goto label_000468DE;
    label_00045E2F:
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00045E4C;
    cpu->ecx = g_sfera_recovered_static_runtime.render_state_08;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445E40u)); sfera_sub_0041BFF0(cpu, LIFT_CODE_TOKEN_VA(0x445E40u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445E47u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x445E47u));
    goto label_000468DE;
    label_00045E4C:
    if ((uint32_t)(cpu->eax) == (uint32_t)(2u)) goto label_00045E5A;
    if ((uint32_t)(cpu->eax) != (uint32_t)(3u)) goto label_00043FA1;
    label_00045E5A:
    cpu->ecx = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445E64u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x445E64u));
    goto label_000468DE;
    label_00045E69:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445E6Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445E6Eu));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00045E8C;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: ffsys, G_VERSION\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445E85u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x445E85u));
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->esp += 8u;
    label_00045E8C:
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->ecx + cpu->eax, 3u);
    goto label_000468DE;
    label_00045EAB:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445EB0u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445EB0u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445EB9u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445EB9u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445EC0u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445EC0u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->edx);
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445EE2u)); sfera_sub_0042E080(cpu, LIFT_CODE_TOKEN_VA(0x445EE2u));
    goto label_000468DE;
    label_00045EE7:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445EECu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445EECu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = 0u;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    g_sfera_world_render_runtime.feature_toggle = (uint32_t)(cpu->ecx);
    goto label_000468DE;
    label_00045F0B:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445F10u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445F10u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445F17u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445F17u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = (uint32_t)(cpu->ecx + cpu->eax);
    cpu->ecx += cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_inter_scalar_runtime.state_05;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445F3Cu)); sfera_sub_0041E220(cpu, LIFT_CODE_TOKEN_VA(0x445F3Cu));
    goto label_000468DE;
    label_00045F41:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445F46u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445F46u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445F4Du)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445F4Du));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445F54u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445F54u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445F5Bu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x445F5Bu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000468DE;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(cpu->eax + cpu->esi);
    cpu->eax = lift_load32(cpu->eax + cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_inter_scalar_runtime.state_05;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_00045FB2;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445F90u)); sfera_sub_0041ED40(cpu, LIFT_CODE_TOKEN_VA(0x445F90u));
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->ecx + cpu->eax, 1u);
    label_00045FA1:
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->eax + cpu->ebx, cpu->ecx);
    goto label_000468DE;
    label_00045FB2:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445FB7u)); sfera_sub_0041ECA0(cpu, LIFT_CODE_TOKEN_VA(0x445FB7u));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->edx + cpu->ecx, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00045FA1;
    cpu->ecx = g_sfera_inter_scalar_runtime.state_05;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445FD3u)); sfera_sub_0041F0D0(cpu, LIFT_CODE_TOKEN_VA(0x445FD3u));
    goto label_000468DE;
    label_00045FD8:
    cpu->ecx = g_sfera_inter_scalar_runtime.state_05;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445FE3u)); sfera_sub_0041E1B0(cpu, LIFT_CODE_TOKEN_VA(0x445FE3u));
    goto label_000468DE;
    label_00045FE8:
    cpu->ecx = g_sfera_inter_scalar_runtime.state_05;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445FF3u)); sfera_sub_0041EC70(cpu, LIFT_CODE_TOKEN_VA(0x445FF3u));
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x445FFEu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x445FFEu));
    goto label_000468DE;
    label_00046003:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446008u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x446008u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44600Fu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44600Fu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000468DE;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx += cpu->esi;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::getenv), LIFT_CODE_TOKEN_VA(0x446027u));
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->esp += 4u;
    cpu->edx += cpu->edi;
    label_00046038:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx, cpu->ecx & 0xFFu);
    ++cpu->eax;
    ++cpu->edx;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00046038;
    goto label_000468DE;
    label_00046047:
    lift_push32(cpu, 0x64u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1B4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x64u); lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"C:\\");
    lift_native_call(cpu, native_function_address32(&::GetVolumeInformationA), LIFT_CODE_TOKEN_VA(0x446060u));
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax &= lift_load32(cpu->esp + 0x1A4u);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44607Cu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44607Cu));
    goto label_000468DE;
    label_00046081:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446086u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x446086u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4460A0u)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x4460A0u));
    if ((uint32_t)(cpu->eax) != 0u) goto label_00044C04;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4460AFu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4460AFu));
    goto label_000468DE;
    label_000460B4:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4460B9u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4460B9u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4460D4u)); sfera_sub_00425D30(cpu, LIFT_CODE_TOKEN_VA(0x4460D4u));
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_0004405A;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4460E4u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4460E4u));
    goto label_000468DE;
    label_000460E9:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4460EEu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4460EEu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4460F5u)); sfera_sub_00454F70(cpu, LIFT_CODE_TOKEN_VA(0x4460F5u));
    g_sfera_inter_scalar_runtime.mode_03 = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000458C9;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446109u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x446109u));
    goto label_000468DE;
    label_0004610E:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446113u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x446113u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446118u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x446118u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44612Cu)); sfera_sub_00429B20(cpu, LIFT_CODE_TOKEN_VA(0x44612Cu));
    goto label_000468DE;
    label_00046131:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446136u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x446136u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44613Du)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44613Du));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000468DE;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax += cpu->edi;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_atoi64), LIFT_CODE_TOKEN_VA(0x446154u));
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->ecx + cpu->esi, cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->esp += 4u;
    cpu->ecx = 0u;
    lift_store32(cpu->eax + cpu->esi + 4u, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446176u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x446176u));
    goto label_000468DE;
    label_0004617B:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446180u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x446180u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446187u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x446187u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->ecx + cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + cpu->esi + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, (uintptr_t)"%I64u"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x4461ABu));
    cpu->esp += 0x10u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4461BBu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4461BBu));
    goto label_000468DE;
    label_000461C0:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4461C5u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4461C5u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4461CCu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4461CCu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi = lift_load32(cpu->ecx + cpu->esi + 4u);
    cpu->ecx += cpu->esi;
    cpu->esi = lift_load32(cpu->ecx);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->esi = v; }
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->edx), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    label_000461EC:
    lift_store32(cpu->ecx, cpu->esi);
    lift_store32(cpu->ecx + 4u, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_00046201;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00043FA1;
    if (true) goto label_00043FA1;
    label_00046201:
    cpu->ecx = 0xFFFFFFFEu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44620Bu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44620Bu));
    goto label_000468DE;
    label_00046210:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446215u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x446215u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44621Cu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44621Cu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi = lift_load32(cpu->ecx + cpu->esi + 4u);
    cpu->ecx += cpu->esi;
    cpu->esi = lift_load32(cpu->ecx);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->edx), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    goto label_000461EC;
    label_0004623E:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446243u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x446243u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44624Au)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44624Au));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi = lift_load32(cpu->ecx + cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + cpu->esi + 4u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00046289;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00044C04;
    if ((uint32_t)(cpu->edi) > (uint32_t)(cpu->eax)) goto label_00044C04;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00043FA1;
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00046289;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_00043FA1;
    label_00046289:
    cpu->ecx |= 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446291u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x446291u));
    goto label_000468DE;
    label_00046296:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44629Bu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44629Bu));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4462A2u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x4462A2u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    cpu->edi = lift_load32(cpu->eax + cpu->esi);
    cpu->eax = lift_load32(cpu->eax + cpu->esi + 4u);
    lift_store32(cpu->esp + 0x1A8u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4462CFu)); sfera_sub_004EE976(cpu, LIFT_CODE_TOKEN_VA(0x4462CFu));
    cpu->ecx = cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4462D9u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4462D9u));
    goto label_000468DE;
    label_000462DE:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4462E3u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4462E3u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4462EAu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4462EAu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edi = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44630Cu)); sfera_sub_004EED20(cpu, LIFT_CODE_TOKEN_VA(0x44630Cu));
    lift_store32(cpu->esi, cpu->eax);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi + 4u, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446318u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x446318u));
    goto label_000468DE;
    label_0004631D:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446322u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x446322u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446329u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x446329u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->ecx + cpu->esi);
    cpu->edi = lift_load32(cpu->ecx + cpu->eax);
    cpu->esi = lift_load32(cpu->ecx + cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->ecx + cpu->eax + 4u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0004636E;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00044C04;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->edi)) goto label_00044C04;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00043FA1;
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0004636E;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->edi)) goto label_00043FA1;
    label_0004636E:
    cpu->ecx |= 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446376u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x446376u));
    goto label_000468DE;
    label_0004637B:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446380u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x446380u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000468DE;
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::GetLocalTime), LIFT_CODE_TOKEN_VA(0x446394u));
    cpu->eax = lift_load16(cpu->esp + 0x3Eu);
    cpu->ecx = lift_load16(cpu->esp + 0x3Au);
    cpu->edx = lift_load16(cpu->esp + 0x38u);
    cpu->esi = native_function_address32(&::sprintf);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x1B0u);
    lift_push32(cpu, (uintptr_t)"%d-%02d-%02d "); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x463C1u), LIFT_CODE_TOKEN_RVA(0x463BFu))) { return; }
    cpu->ecx = lift_load16(cpu->esp + 0x58u);
    cpu->edx = lift_load16(cpu->esp + 0x56u);
    cpu->eax = lift_load16(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1D8u);
    lift_push32(cpu, (uintptr_t)"%02d:%02d:%02d"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x463E2u), LIFT_CODE_TOKEN_RVA(0x463E0u))) { return; }
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->esp += 0x28u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x1A4u);
    cpu->edx += cpu->edi;
    label_000463F4:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000463F4;
    cpu->eax = (uint32_t)(cpu->esp + 0x1B8u);
    cpu->ecx = cpu->eax;
    label_00046407:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00046407;
    cpu->edi += g_sfera_mbc_runtime->process_memory_base;
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00046420:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00046420;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44643Du)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44643Du));
    goto label_000468DE;
    label_00046442:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446447u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x446447u));
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"open"); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::ShellExecuteA), LIFT_CODE_TOKEN_VA(0x44645Du));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44646Au)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44646Au));
    goto label_000468DE;
    label_0004646F:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446474u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x446474u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000468DE;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(cpu->esp + 0x7Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_findfirst64i32), LIFT_CODE_TOKEN_VA(0x446493u));
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_000464BA;
    lift_native_call(cpu, native_function_address32(&::_errno), LIFT_CODE_TOKEN_VA(0x4464A1u));
    cpu->ecx = lift_load32(cpu->eax);
    cpu->ecx -= 2u;
    { uint64_t x=(uint64_t)(cpu->ecx), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->ecx = v; }
    cpu->ecx = (uint64_t)(cpu->ecx) - (uint64_t)(cpu->ecx) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4464B5u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4464B5u));
    goto label_000468DE;
    label_000464BA:
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x7Cu)), r=(uint64_t)(0x10u), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_push32(cpu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000464DA;
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x4464C2u));
    cpu->esp += 4u;
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4464D5u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4464D5u));
    goto label_000468DE;
    label_000464DA:
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x4464DAu));
    cpu->esp += 4u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4464EAu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4464EAu));
    goto label_000468DE;
    label_000464EF:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4464F4u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4464F4u));
    cpu->esi = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->esi += cpu->eax;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->eax)) goto label_00046513;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: chat, SYS_SET_USER_NAME, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446510u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x446510u));
    cpu->esp += 8u;
    label_00046513:
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_error_log_runtime.index_table[0];
    cpu->eax = cpu->esi;
    cpu->edx -= cpu->esi;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00046520:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->eax + cpu->edx, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00046520;
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446534u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x446534u));
    goto label_000468DE;
    label_00046539:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44653Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44653Eu));
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    g_sfera_directplay_runtime.transport.transport_flag = (uint8_t)((cpu->eax & 0xFFu));
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00046567;
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled)) != (uint8_t)(1u)) goto label_00046567;
    lift_push32(cpu, (uintptr_t)"-------------------------CONNECTION_LOST_NOTIFICATION\n"); lift_push32(cpu, (uintptr_t)"tcp_ip_connect.log");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446564u)); sfera_sub_00418750(cpu, LIFT_CODE_TOKEN_VA(0x446564u));
    cpu->esp += 8u;
    label_00046567:
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44656Eu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44656Eu));
    goto label_000468DE;
    label_00046573:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446578u)); sfera_sub_004BCD80(cpu, LIFT_CODE_TOKEN_VA(0x446578u));
    goto label_000468DE;
    label_0004657D:
    lift_push32(cpu, (uint32_t)(uintptr_t)"WorldMap.bmp");
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_map_generator_runtime.storage[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44658Cu)); sfera_sub_0047DB30(cpu, LIFT_CODE_TOKEN_VA(0x44658Cu));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446593u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x446593u));
    goto label_000468DE;
    label_00046598:
    cpu->ecx = 0u;
    g_sfera_mbc_runtime->trace_steps_remaining = (uint32_t)(0x19u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4465A9u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4465A9u));
    goto label_000468DE;
    label_000465AE:
    cpu->ecx = g_sfera_interface_runtime.invite_messages;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4465B9u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4465B9u));
    goto label_000468DE;
    label_000465BE:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4465C3u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4465C3u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4465CAu)); sfera_sub_004BA750(cpu, LIFT_CODE_TOKEN_VA(0x4465CAu));
    goto label_000468DE;
    label_000465CF:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4465D4u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4465D4u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4465DBu)); sfera_sub_004BA7E0(cpu, LIFT_CODE_TOKEN_VA(0x4465DBu));
    goto label_000468DE;
    label_000465E0:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4465E5u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4465E5u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_inter_scalar_runtime.state_05;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446606u)); sfera_sub_0041E480(cpu, LIFT_CODE_TOKEN_VA(0x446606u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44660Du)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44660Du));
    goto label_000468DE;
    label_00046612:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446617u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x446617u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44661Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44661Eu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = (uint32_t)(cpu->ecx + cpu->eax);
    cpu->ecx += cpu->esi;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_inter_scalar_runtime.state_05;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446643u)); sfera_sub_0041E550(cpu, LIFT_CODE_TOKEN_VA(0x446643u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44664Au)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44664Au));
    goto label_000468DE;
    label_0004664F:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(g_sfera_interface_runtime.primary_gate) & 0xFFu);
    g_sfera_interface_runtime.secondary_gate = (uint8_t)((cpu->eax & 0xFFu));
    g_sfera_interface_runtime.primary_gate = (uint8_t)(0u);
    goto label_000468DE;
    label_00046665:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(g_sfera_interface_runtime.secondary_gate) & 0xFFu);
    g_sfera_interface_runtime.primary_gate = (uint8_t)((cpu->ecx & 0xFFu));
    goto label_000468DE;
    label_00046676:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44667Bu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44667Bu));
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000468DE;
    lift_push32(cpu, 0x308Du);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44668Fu)); sfera_sub_00454F70(cpu, LIFT_CODE_TOKEN_VA(0x44668Fu));
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44669Bu)); sfera_sub_0045CB30(cpu, LIFT_CODE_TOKEN_VA(0x44669Bu));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_000468DE;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4466AAu)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x4466AAu));
    lift_store_f32(cpu->esp + 0x1A4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4466B6u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x4466B6u));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4466BFu)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x4466BFu));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1A4u));
    lift_store_f32(cpu->esi + 0x288u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esi + 0x28Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store_f32(cpu->esi + 0x290u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000468DE;
    label_000466F6:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4466FBu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4466FBu));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000468DE;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = g_sfera_input_device_runtime.shared_object;
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446720u)); sfera_sub_0047E700(cpu, LIFT_CODE_TOKEN_VA(0x446720u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446727u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x446727u));
    goto label_000468DE;
    label_0004672C:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446731u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x446731u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000468DE;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44674Fu)); sfera_sub_0047E760(cpu, LIFT_CODE_TOKEN_VA(0x44674Fu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446756u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x446756u));
    goto label_000468DE;
    label_0004675B:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446760u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x446760u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446767u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x446767u));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44676Eu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x44676Eu));
    cpu->edi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->edi) != 0u) goto label_0004677E;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4677Eu)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x4677Eu));
    label_0004677E:
    cpu->edi += g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->esp + 0x1A4u, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446790u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x446790u));
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x348u);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    cpu->esi += ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0]);
    cpu->ebp = lift_load32(cpu->esi + 0x68u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_000458C9;
    cpu->esi = lift_load32(cpu->esi + 0x64u);
    cpu->edi = cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(cpu->esi)) goto label_000467DB;
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x34u);
    cpu->ebx += cpu->ebp;
    label_000467C1:
    cpu->edx = lift_load32(cpu->esp + 0x1A4u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4467CFu)); sfera_sub_00434080(cpu, LIFT_CODE_TOKEN_VA(0x4467CFu));
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000467F7;
    ++cpu->edi;
    cpu->ebx += 0x34u;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->esi)) goto label_000467C1;
    label_000467DB:
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(g_sfera_mbc_runtime->process_memory_base)) goto label_000467EA;
    lift_store8(cpu->eax, 0u);
    label_000467EA:
    cpu->ecx |= 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4467F2u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4467F2u));
    goto label_000468DE;
    label_000467F7:
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(g_sfera_mbc_runtime->process_memory_base)) goto label_0004681A;
    cpu->eax = cpu->edi;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x34u);
    cpu->eax += cpu->ebp;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00046810:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx, cpu->ecx & 0xFFu);
    ++cpu->eax;
    ++cpu->edx;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00046810;
    label_0004681A:
    cpu->ecx = (uint32_t)(cpu->edi + 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446822u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x446822u));
    goto label_000468DE;
    label_00046827:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44682Cu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44682Cu));
    g_sfera_network_runtime.connection_slot = (uint32_t)(cpu->eax);
    goto label_000468DE;
    label_00046836:
    cpu->ecx = g_sfera_network_runtime.connection_slot;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446841u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x446841u));
    goto label_000468DE;
    label_00046846:
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.gamexp_sid_present)) != (uint8_t)(0u)) goto label_0004689A;
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.gamexp_sid[0];
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00046857:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00046857;
    cpu->eax -= cpu->edx;
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446867u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x446867u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446871u)); sfera_sub_00401C90(cpu, LIFT_CODE_TOKEN_VA(0x446871u));
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0004687E;
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4687Eu)); sfera_sub_00434E80(cpu, LIFT_CODE_TOKEN_RVA(0x4687Eu));
    label_0004687E:
    cpu->eax = lift_load32(cpu->esi);
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.gamexp_sid[0];
    label_00046890:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    lift_store8(cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->edx;
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00046890;
    label_0004689A:
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.gamexp_sid_present)), r=(uint64_t)((cpu->ecx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4468AAu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4468AAu));
    goto label_000468DE;
    label_000468AC:
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    g_sfera_graphics_runtime.render_mode_enabled = (uint8_t)(1u);
    goto label_000468DE;
    label_000468BE:
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000468DE;
    cpu->ecx = *(uint8_t*)(void*)&g_sfera_client_config_runtime.flag_03;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4468D3u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4468D3u));
    (*(uint8_t*)(void*)&g_sfera_client_config_runtime.flag_03) = (uint8_t)(0u);
    goto label_000468DE;
    label_000468DC:
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000468DE:
    cpu->ecx = lift_load32(cpu->esp + 0x1D0u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1C8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00446D40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446D54u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x446D54u));
    cpu->esi = cpu->eax;
    cpu->eax = (uint32_t)(cpu->esi + 0xFFFFFFF3u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x31u)) goto label_000476F7;

    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00046D73;
        case 1u: goto label_0004731C;
        case 2u: goto label_0004747A;
        case 3u: goto label_000474D2;
        case 4u: goto label_00047500;
        case 17u: goto label_00047546;
        case 41u: goto label_00047593;
        case 42u: goto label_00047620;
        case 43u: goto label_0004764E;
        case 44u: goto label_000476A1;
        case 49u: goto label_000476C5;
        default: goto label_000476F4;
    }
label_00046D73: ;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446D78u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x446D78u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000476F4;
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->edx -= cpu->eax;
    label_00046D91:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00046D91;
    cpu->edx = g_sfera_mbc_runtime->argument_cursor;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(5u), 32u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x1Cu)), r=(uint64_t)(0x2Au), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint8_t)g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].type)) & 0xFFu);
    lift_store8(cpu->esp + 0x12u, cpu->ebx & 0xFFu);
    cpu->ebp = (uint32_t)(cpu->esp + 0x1Cu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00046DF2;
    cpu->ecx = (int8_t)((cpu->ebx & 0xFFu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446DC1u)); sfera_sub_00433B90(cpu, LIFT_CODE_TOKEN_VA(0x446DC1u));
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00046DCE;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446DCAu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x446DCAu));
    cpu->esi = cpu->eax;
    goto label_00046E11;
    label_00046DCE:
    if ((uint8_t)((cpu->ebx & 0xFFu)) != (uint8_t)(0x20u)) goto label_00046DDE;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446DD8u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x446DD8u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00046E11;
    label_00046DDE:
    if ((uint8_t)((cpu->ebx & 0xFFu)) != (uint8_t)(1u)) goto label_00046E1E;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446DE8u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x446DE8u));
    cpu->ebp = cpu->eax;
    cpu->ebp += g_sfera_mbc_runtime->process_memory_base;
    goto label_00046E11;
    label_00046DF2:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446DF7u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x446DF7u));
    cpu->ebp = cpu->eax;
    cpu->ebp += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446E04u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x446E04u));
    lift_store8(cpu->esp + 0x12u, 0x2Au);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x12u)) & 0xFFu);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    label_00046E11:
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000476F4;
    label_00046E1E:
    cpu->ecx = (int8_t)((cpu->ebx & 0xFFu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446E26u)); sfera_sub_00433B90(cpu, LIFT_CODE_TOKEN_VA(0x446E26u));
    { uint64_t v=(uint64_t)((cpu->eax & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    cpu->eax = native_function_address32(&::sprintf);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00046E44;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, (uintptr_t)&g_sfera_config_text_runtime.format_scratch[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x46E3Cu), LIFT_CODE_TOKEN_RVA(0x46E3Au))) { return; }
    cpu->esp += 0xCu;
    goto label_00046F85;
    label_00046E44:
    if ((uint8_t)((cpu->ebx & 0xFFu)) != (uint8_t)(0x20u)) goto label_00046E67;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->esp -= 8u;
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)"%f"); lift_push32(cpu, (uintptr_t)&g_sfera_config_text_runtime.format_scratch[0]);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x46E5Fu), LIFT_CODE_TOKEN_RVA(0x46E5Du))) { return; }
    cpu->esp += 0x10u;
    goto label_00046F85;
    label_00046E67:
    if ((uint8_t)((cpu->ebx & 0xFFu)) != (uint8_t)(1u)) goto label_00046E84;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_config_text_runtime.format_scratch[0];
    cpu->eax = cpu->ebp;
    cpu->edx -= cpu->ebp;
    label_00046E75:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00046E75;
    goto label_00046F85;
    label_00046E84:
    if ((uint8_t)((cpu->ebx & 0xFFu)) != (uint8_t)(0x2Au)) goto label_00046F85;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->edi = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->ebx = 0u;
    cpu->ecx = (uint32_t)(cpu->edi + 0xFFFFFFFAu);
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_config_text_runtime.format_scratch[0];
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_00046F46;
    cpu->edi = cpu->edi;
    label_00046EB0:
    cpu->edx = cpu->ebx;
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = (uint32_t)(((uint32_t)(cpu->edx) * 8u));
    cpu->ecx = cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_shift_left(cpu, (cpu->eax & 0xFFu), (uint32_t)((cpu->ecx & 0xFFu)), 8u)) & 0xFFu);
    cpu->edx += cpu->ebp;
    { uint64_t l=(uint64_t)(lift_load8(cpu->edx)), r=(uint64_t)((cpu->eax & 0xFFu)), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00046ED2;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->edx;
    label_00046ED2:
    if ((uint8_t)((lift_load8(cpu->edx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_00046EDB;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) | (uint64_t)(2u))) & 0xFFu);
    goto label_00046EDE;
    label_00046EDB:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFDu))) & 0xFFu);
    label_00046EDE:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00046EE5;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->edx;
    label_00046EE5:
    if ((uint8_t)((lift_load8(cpu->edx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_00046EEE;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) | (uint64_t)(4u))) & 0xFFu);
    goto label_00046EF1;
    label_00046EEE:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xFBu))) & 0xFFu);
    label_00046EF1:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00046EF8;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->edx;
    label_00046EF8:
    if ((uint8_t)((lift_load8(cpu->edx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_00046F01;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) | (uint64_t)(8u))) & 0xFFu);
    goto label_00046F04;
    label_00046F01:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xF7u))) & 0xFFu);
    label_00046F04:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00046F0B;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->edx;
    label_00046F0B:
    if ((uint8_t)((lift_load8(cpu->edx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_00046F14;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) | (uint64_t)(0x10u))) & 0xFFu);
    goto label_00046F17;
    label_00046F14:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xEFu))) & 0xFFu);
    label_00046F17:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->eax & 0xFFu)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00046F1E;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    ++cpu->edx;
    label_00046F1E:
    if ((uint8_t)((lift_load8(cpu->edx)) & ((cpu->eax & 0xFFu))) == 0u) goto label_00046F27;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) | (uint64_t)(0x20u))) & 0xFFu);
    goto label_00046F2A;
    label_00046F27:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) & (uint64_t)(0xDFu))) & 0xFFu);
    label_00046F2A:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    cpu->ebx += 6u;
    lift_store8(cpu->esi, cpu->ecx & 0xFFu);
    cpu->eax = (uint32_t)(cpu->edi + 0xFFFFFFFAu);
    ++cpu->esi;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00046EB0;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    label_00046F46:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(6u) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) - (uint64_t)((cpu->ebx & 0xFFu)) - (uint64_t)(0u))) & 0xFFu);
    lift_store8(cpu->esi, 0x23u);
    lift_store8(cpu->esi + 1u, cpu->eax & 0xFFu);
    cpu->esi += 2u;
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(cpu->edi)) goto label_00046F82;
    lift_push32(cpu, 1u);
    cpu->edi -= cpu->ebx;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x23u);
    lift_store8(cpu->esp + 0x23u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x446F78u)); sfera_sub_004013D0(cpu, LIFT_CODE_TOKEN_VA(0x446F78u));
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x13u)) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    lift_store8(cpu->esi, cpu->edx & 0xFFu);
    ++cpu->esi;
    label_00046F82:
    lift_store8(cpu->esi, 0u);
    label_00046F85:
    cpu->ecx = g_sfera_config_text_runtime.current_text;
    cpu->ebx = g_sfera_config_text_runtime.text_length;
    cpu->ebp = cpu->ecx;
    label_00046F93:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp)) & 0xFFu);
    cpu->esi = cpu->ebp;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x20u)) goto label_00046FBB;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00046FA0:
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(9u)) goto label_00046FBB;
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00046FBB;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0xDu)) goto label_00046FBB;
    cpu->eax = (uint32_t)(cpu->ebx + cpu->ecx);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->eax)) goto label_00046FBB;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x20u)) goto label_00046FA0;
    label_00046FBB:
    cpu->edi = cpu->esi;
    cpu->edi -= cpu->ebp;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->shared_buffer[0]);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x446FC6u));
    cpu->esp += 0xCu;
    lift_store8(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->shared_buffer[0]), 0u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->shared_buffer[0];
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->edi = cpu->edi;
    label_00046FE0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00047000;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_00046FFC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00047000;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00046FE0;
    label_00046FFC:
    cpu->eax = 0u;
    goto label_00047005;
    label_00047000:
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_00047005:
    cpu->edi = g_sfera_config_text_runtime.current_text;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00047161;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0xAu)) goto label_0004703A;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00047020:
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00047035;
    cpu->ecx = (uint32_t)(cpu->ebx + cpu->edi);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->ecx)) goto label_00047035;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    ++cpu->esi;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0xAu)) goto label_00047020;
    goto label_0004703A;
    label_00047035:
    if ((uint8_t)(lift_load8(cpu->esi)) != (uint8_t)(0xAu)) goto label_00047058;
    label_0004703A:
    cpu->ebp = (uint32_t)(cpu->esi + 1u);
    cpu->edx = cpu->ebp;
    cpu->edx -= cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edx) >= (int32_t)(uint32_t)(0x258240u)) goto label_00047161;
    cpu->ecx = g_sfera_config_text_runtime.current_text;
    goto label_00046F93;
    label_00047058:
    cpu->esi = (uint32_t)(cpu->ebx + cpu->edi);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_0004706E;
    lift_store16(cpu->esi, 0xA0Du);
    cpu->esi += 2u;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_config_text_runtime.text_length, (uint64_t)(g_sfera_config_text_runtime.text_length) + (uint64_t)(2u) + (uint64_t)(0u));
    label_0004706E:
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x12u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_config_text_runtime.format_scratch[0]);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00047086;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%s\t\"%s\"");
    goto label_00047090;
    label_00047086:
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%s\t%s");
    label_00047090:
    lift_push32(cpu, (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->shared_buffer[0]);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x447095u));
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->shared_buffer[0];
    cpu->esp += 0x10u;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000470A6:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000470A6;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->shared_buffer[0]); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4470B6u));
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->shared_buffer[0];
    cpu->esp += 0xCu;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000470C6:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000470C6;
    cpu->ecx = g_sfera_config_text_runtime.text_length;
    cpu->eax -= cpu->edx;
    cpu->edx = g_sfera_config_text_runtime.current_text;
    cpu->ecx += cpu->eax;
    g_sfera_config_text_runtime.text_length = (uint32_t)(cpu->ecx);
    lift_store8(cpu->ecx + cpu->edx, 0u);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00047112;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4470FFu)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x4470FFu));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00047112:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->edx = 1u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    cpu->ebp = lift_pop32(cpu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(0u);
    cpu->ecx += cpu->edx;
    cpu->ebx = lift_pop32(cpu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->edx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->edx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00047161:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x20u)) goto label_00047180;
    label_00047168:
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(9u)) goto label_00047180;
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00047180;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp + 1u)) & 0xFFu);
    ++cpu->ebp;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x20u)) goto label_00047168;
    goto label_0004718B;
    label_00047180:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x20u)) goto label_0004718B;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(9u)) goto label_00047194;
    label_0004718B:
    if ((uint8_t)(lift_load8(cpu->ebp)) == (uint8_t)(0u)) goto label_00047194;
    ++cpu->ebp;
    goto label_00047180;
    label_00047194:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp)) & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x22u)) goto label_000471BB;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp + 1u)) & 0xFFu);
    ++cpu->ebp;
    cpu->eax = cpu->ebp;
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0x22u)) goto label_000471CF;
    label_000471A7:
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0xDu)) goto label_000471CF;
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_000471CF;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x22u)) goto label_000471A7;
    goto label_000471CF;
    label_000471BB:
    cpu->eax = cpu->ebp;
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0xDu)) goto label_000471CF;
    label_000471C2:
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_000471CF;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0xDu)) goto label_000471C2;
    label_000471CF:
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_text_runtime.format_scratch[0];
    cpu->esi = (uint32_t)(cpu->ecx + 1u);
    label_000471D7:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000471D7;
    cpu->ebx -= cpu->eax;
    cpu->ecx -= cpu->esi;
    cpu->ecx -= cpu->eax;
    cpu->ebx += cpu->edi;
    lift_push32(cpu, cpu->ebx);
    cpu->esi = (uint32_t)(cpu->ebp + cpu->ecx);
    lift_push32(cpu, cpu->eax);
    cpu->eax += cpu->esi;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4471EFu));
    cpu->eax = g_sfera_config_text_runtime.text_length;
    cpu->ecx = g_sfera_config_text_runtime.current_text;
    cpu->eax += cpu->esi;
    g_sfera_config_text_runtime.text_length = (uint32_t)(cpu->eax);
    lift_store8(cpu->eax + cpu->ecx, 0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_config_text_runtime.format_scratch[0];
    cpu->esp += 0xCu;
    cpu->ecx = 0u;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_00047218:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00047218;
    cpu->eax -= cpu->esi;
    cpu->edi = 1u;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00047252;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00047230:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_config_text_runtime.format_scratch[0]))) & 0xFFu);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_config_text_runtime.format_scratch[0];
    lift_store8(cpu->ebp, cpu->edx & 0xFFu);
    cpu->ecx += cpu->edi;
    cpu->ebp += cpu->edi;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_00047245:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00047245;
    cpu->eax -= cpu->esi;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->eax)) goto label_00047230;
    label_00047252:
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000472D2;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447265u)); sfera_sub_00434D90(cpu, LIFT_CODE_TOKEN_VA(0x447265u));
    cpu->ecx = (uint32_t)(uintptr_t)"\n---exit_inter start---\nMBINTER MESSAGE:";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44726Fu)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x44726Fu));
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447279u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x447279u));
    cpu->ecx = (uint32_t)(uintptr_t)"\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447283u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x447283u));
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44728Du)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x44728Du));
    cpu->ecx = (uint32_t)(uintptr_t)"---exit_inter end-----\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447297u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x447297u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->process_index), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    g_sfera_mbc_runtime->execution_failed = (uint32_t)(cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000472B0;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x472B0u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x472B0u));
    label_000472B0:
    cpu->edx = (uint32_t)(uintptr_t)"EError";
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4472BFu)); sfera_sub_00435020(cpu, LIFT_CODE_TOKEN_VA(0x4472BFu));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000472D2:
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(0u);
    cpu->ecx += cpu->edi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->edi);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004731C:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447321u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x447321u));
    cpu->eax = lift_load32(cpu->eax);
    cpu->esi = g_sfera_mbc_runtime->process_memory_base;
    cpu->esi += cpu->eax;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi)), r=(uint64_t)(0x2Au), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00047337;
    cpu->ebp = 0x2Au;
    goto label_00047346;
    label_00047337:
    cpu->edx = g_sfera_mbc_runtime->argument_cursor;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(5u), 32u);
    cpu->ebp = g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->edx >> 5u].type;
    label_00047346:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44734Bu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x44734Bu));
    cpu->eax = lift_load32(cpu->eax);
    cpu->edi = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi += cpu->eax;
    if ((uint32_t)(g_sfera_mbc_runtime->argument_count) != (uint32_t)(4u)) goto label_00047365;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447363u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x447363u));
    goto label_0004736A;
    label_00047365:
    cpu->eax = 0x989680u;
    label_0004736A:
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000476F4;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(0x11u)) goto label_000473AC;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_text_runtime.parser_path[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44738Au)); sfera_sub_00401770(cpu, LIFT_CODE_TOKEN_VA(0x44738Au));
    cpu->ecx = 0u;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax & 0xFFu)) & 0xFFu);
    { uint64_t v=(uint64_t)((cpu->ebx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    --cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447399u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x447399u));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000473AC:
    if ((uint32_t)(cpu->ebp) != (uint32_t)(0x21u)) goto label_000473DF;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_text_runtime.parser_path[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4473BDu)); sfera_sub_004017A0(cpu, LIFT_CODE_TOKEN_VA(0x4473BDu));
    cpu->ecx = 0u;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax & 0xFFu)) & 0xFFu);
    { uint64_t v=(uint64_t)((cpu->ebx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    --cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4473CCu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4473CCu));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000473DF:
    if ((uint32_t)(cpu->ebp) != (uint32_t)(1u)) goto label_00047413;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_text_runtime.parser_path[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4473F1u)); sfera_sub_004017D0(cpu, LIFT_CODE_TOKEN_VA(0x4473F1u));
    cpu->ecx = 0u;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax & 0xFFu)) & 0xFFu);
    { uint64_t v=(uint64_t)((cpu->ebx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    --cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447400u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x447400u));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00047413:
    if ((uint32_t)(cpu->ebp) != (uint32_t)(0x2Au)) goto label_00047447;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_text_runtime.parser_path[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447425u)); sfera_sub_00401840(cpu, LIFT_CODE_TOKEN_VA(0x447425u));
    cpu->ecx = 0u;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax & 0xFFu)) & 0xFFu);
    { uint64_t v=(uint64_t)((cpu->ebx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    --cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447434u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x447434u));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00047447:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"wrong parameter in cfg_get, '%s'\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447457u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x447457u));
    cpu->ecx = 0u;
    cpu->esp += 0xCu;
    { uint64_t v=(uint64_t)((cpu->ebx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    --cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447467u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x447467u));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004747A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44747Fu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x44747Fu));
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != 0u) goto label_0004748F;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4748Fu)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x4748Fu));
    label_0004748F:
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = (uint32_t)(cpu->esi + cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000476F4;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_text_runtime.parser_path[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4474B0u)); sfera_sub_00401990(cpu, LIFT_CODE_TOKEN_VA(0x4474B0u));
    cpu->ecx = cpu->eax & 0xFFu;
    { uint64_t x=(uint64_t)(cpu->ecx), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->ecx = v; }
    cpu->ecx = (uint64_t)(cpu->ecx) - (uint64_t)(cpu->ecx) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    --cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4474BFu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4474BFu));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000474D2:
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_text_runtime.parser_path[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4474DEu)); sfera_sub_00401AC0(cpu, LIFT_CODE_TOKEN_VA(0x4474DEu));
    cpu->ecx = cpu->eax & 0xFFu;
    { uint64_t x=(uint64_t)(cpu->ecx), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->ecx = v; }
    cpu->ecx = (uint64_t)(cpu->ecx) - (uint64_t)(cpu->ecx) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    --cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4474EDu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4474EDu));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00047500:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447505u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x447505u));
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != 0u) goto label_00047515;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x47515u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x47515u));
    label_00047515:
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000476F4;
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_text_runtime.parser_path[0];
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447533u)); sfera_sub_00401700(cpu, LIFT_CODE_TOKEN_VA(0x447533u));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00047546:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44754Bu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x44754Bu));
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != 0u) goto label_0004755B;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4755Bu)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x4755Bu));
    label_0004755B:
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000476F4;
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_text_runtime.parser_path[0];
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447579u)); sfera_sub_00401730(cpu, LIFT_CODE_TOKEN_VA(0x447579u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447580u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x447580u));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00047593:
    cpu->eax = g_sfera_mbc_runtime->active_process;
    if ((uint32_t)(lift_load32(cpu->eax + 0xB0u)) != (uint32_t)(0u)) goto label_000475BC;
    cpu->ecx |= 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4475A9u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4475A9u));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000475BC:
    cpu->edx = lift_load32(cpu->eax + 0xB0u);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_000475C7:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000475C7;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_text_runtime.parser_path[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4475DCu)); sfera_sub_00401590(cpu, LIFT_CODE_TOKEN_VA(0x4475DCu));
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->ecx = lift_load32(cpu->eax + 0xB0u);
    lift_push32(cpu, 0x31C6u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4475F6u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x4475F6u));
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    lift_store32(cpu->ecx + 0xB0u, 0u);
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44760Du)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44760Du));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00047620:
    lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_text_runtime.parser_path[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44762Cu)); sfera_sub_00401AC0(cpu, LIFT_CODE_TOKEN_VA(0x44762Cu));
    cpu->ecx = cpu->eax & 0xFFu;
    { uint64_t x=(uint64_t)(cpu->ecx), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->ecx = v; }
    cpu->ecx = (uint64_t)(cpu->ecx) - (uint64_t)(cpu->ecx) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    --cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44763Bu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44763Bu));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004764E:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447653u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x447653u));
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != 0u) goto label_00047663;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x47663u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x47663u));
    label_00047663:
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44766Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44766Eu));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000476F4;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_text_runtime.parser_path[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447687u)); sfera_sub_00401B70(cpu, LIFT_CODE_TOKEN_VA(0x447687u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44768Eu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44768Eu));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000476A1:
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_text_runtime.parser_path[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4476ABu)); sfera_sub_004015F0(cpu, LIFT_CODE_TOKEN_VA(0x4476ABu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4476B2u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x4476B2u));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000476C5:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4476CAu)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x4476CAu));
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000476DA;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x476DAu)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x476DAu));
    label_000476DA:
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000476F4;
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_text_runtime.parser_path[0];
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x476F4u)); sfera_sub_00401570(cpu, LIFT_CODE_TOKEN_RVA(0x476F4u));
    label_000476F4:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000476F7:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00447770(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447778u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x447778u));
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != 0u) goto label_00047788;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x47788u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x47788u));
    label_00047788:
    cpu->ebx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ebx += cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447795u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x447795u));
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != 0u) goto label_000477A5;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x477A5u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x477A5u));
    label_000477A5:
    cpu->edi = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi += cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4477B2u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x4477B2u));
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_000478CE;
    cpu->ecx = cpu->edi;
    cpu->esi = cpu->eax;
    cpu->edx = cpu->ebx;
    cpu->edi = 1u;
    if ((uint32_t)(cpu->eax) < (uint32_t)(4u)) goto label_000477E4;
    (void)cpu;
    label_000477D0:
    cpu->eax = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->ecx))) goto label_000477E8;
    cpu->esi -= 4u;
    cpu->ecx += 4u;
    cpu->edx += 4u;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(4u)) goto label_000477D0;
    label_000477E4:
    if ((uint32_t)(cpu->esi) == 0u) goto label_00047829;
    label_000477E8:
    cpu->eax = lift_load8(cpu->edx);
    cpu->ebx = lift_load8(cpu->ecx);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00047822;
    if ((uint32_t)(cpu->esi) <= (uint32_t)(cpu->edi)) goto label_00047829;
    cpu->eax = lift_load8(cpu->edx + 1u);
    cpu->ebx = lift_load8(cpu->ecx + 1u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00047822;
    if ((uint32_t)(cpu->esi) <= (uint32_t)(2u)) goto label_00047829;
    cpu->eax = lift_load8(cpu->edx + 2u);
    cpu->ebx = lift_load8(cpu->ecx + 2u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00047822;
    if ((uint32_t)(cpu->esi) <= (uint32_t)(3u)) goto label_00047829;
    cpu->eax = lift_load8(cpu->edx + 3u);
    cpu->ecx = lift_load8(cpu->ecx + 3u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    label_00047822:
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax |= cpu->edi;
    goto label_0004782B;
    label_00047829:
    cpu->eax = 0u;
    label_0004782B:
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0004789B;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44783Eu)); sfera_sub_00434D90(cpu, LIFT_CODE_TOKEN_VA(0x44783Eu));
    cpu->ecx = (uint32_t)(uintptr_t)"\n---exit_inter start---\nMBINTER MESSAGE:";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447848u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x447848u));
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447852u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x447852u));
    cpu->ecx = (uint32_t)(uintptr_t)"\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44785Cu)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x44785Cu));
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447866u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x447866u));
    cpu->ecx = (uint32_t)(uintptr_t)"---exit_inter end-----\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447870u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x447870u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->process_index), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    g_sfera_mbc_runtime->execution_failed = (uint32_t)(cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00047889;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x47889u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x47889u));
    label_00047889:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->edx = (uint32_t)(uintptr_t)"EError";
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0];
    cpu->ebx = lift_pop32(cpu);
    sfera_sub_00435020(cpu, stop_address); return;
    label_0004789B:
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].payload[0] = (uint32_t)(cpu->eax);
    cpu->edx += cpu->edi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_end = (uint32_t)(cpu->edi);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->ecx >> 5u].range_begin = (uint32_t)(cpu->edi);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    label_000478CE:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004478E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x250u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x25Cu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0xD4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00047917;
    lift_push32(cpu, (uint32_t)(uintptr_t)"\n-----BaseManager---DEL LIST----------------------------------------\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447914u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x447914u));
    cpu->esp += 4u;
    label_00047917:
    cpu->edi = native_function_address32(&::strncpy);
    lift_push32(cpu, 0x96u);
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    std::construct_at(reinterpret_cast<CItemListCommonItem*>(cpu->esp + 0x54u));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x47932u), LIFT_CODE_TOKEN_RVA(0x47930u))) { return; }
    lift_push32(cpu, 0x96u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x130u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    lift_store8(cpu->esp + 0xF9u, 0u);
    std::construct_at(reinterpret_cast<CItem*>(cpu->esp + 0x134u));
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x47955u), LIFT_CODE_TOKEN_RVA(0x47953u))) { return; }
    cpu->esp += 0x18u;
    cpu->edx = (uint32_t)(cpu->esp + 0x11Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x1B9u, 0u);
    cpu->ebx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447974u)); sfera_sub_00443230(cpu, LIFT_CODE_TOKEN_VA(0x447974u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_0004797E;
    cpu->ebx = lift_load32(cpu->eax + 0xB4u);
    label_0004797E:
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44798Au)); sfera_sub_00443730(cpu, LIFT_CODE_TOKEN_VA(0x44798Au));
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000479F7;
    if ((uint8_t)(lift_load8(cpu->esi + 0xD4u)) == (uint8_t)((cpu->eax & 0xFFu))) goto label_000479AC;
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)" Deleted List  'OK' = ''%s''\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4479A9u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x4479A9u));
    cpu->esp += 8u;
    label_000479AC:
    if ((uint8_t)(lift_load8(cpu->esi + 0xD4u)) != (uint8_t)(2u)) goto label_000479BC;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x479BCu)); sfera_sub_0043A6F0(cpu, LIFT_CODE_TOKEN_RVA(0x479BCu));
    label_000479BC:
    if ((uint32_t)(cpu->ebx) != (uint32_t)(1u)) goto label_000479F3;
    if ((uint32_t)(lift_load32(cpu->esp + 0x268u)) == (uint32_t)(0u)) goto label_000479F3;
    lift_push32(cpu, 0x96u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1C8u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x479DBu), LIFT_CODE_TOKEN_RVA(0x479D9u))) { return; }
    lift_push32(cpu, 0x20u);
    cpu->esi += 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_store8(cpu->esp + 0x271u, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x479F0u), LIFT_CODE_TOKEN_RVA(0x479EEu))) { return; }
    cpu->esp += 0x18u;
    label_000479F3:
    cpu->eax = 0u;
    goto label_00047A16;
    label_000479F7:
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFAu)) goto label_00047A16;
    if ((uint8_t)(lift_load8(cpu->esi + 0xD4u)) == (uint8_t)(0u)) goto label_00047A16;
    lift_push32(cpu, (uint32_t)(uintptr_t)" Delete List =  'ERROR' ER_CURITEMS_LESS_MINITEMS\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447A0Fu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x447A0Fu));
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->esp += 4u;
    label_00047A16:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x250u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00447A40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x2DCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0xD4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 0xCu);
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00047A87;
    lift_push32(cpu, (uint32_t)(uintptr_t)"\n-----BaseManager---DEL ITEM ITEM----------------------------------------\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447A84u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x447A84u));
    cpu->esp += 4u;
    label_00047A87:
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    std::construct_at(reinterpret_cast<CItemListCommonItem*>(cpu->esp + 0x54u));
    std::construct_at(reinterpret_cast<CCommonItem*>(cpu->esp + 0x128u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447AA2u)); sfera_sub_00443230(cpu, LIFT_CODE_TOKEN_VA(0x447AA2u));
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_00047C85;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447AB4u)); sfera_sub_00443680(cpu, LIFT_CODE_TOKEN_VA(0x447AB4u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 0xB8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00047B27;
    if ((uint32_t)(cpu->edi) != 0u) goto label_00047B00;
    if ((uint8_t)(lift_load8(cpu->esi + 0xD4u)) == (uint8_t)((cpu->eax & 0xFFu))) goto label_00047AE4;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->eax += 4u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)" Delete pItemFrom 'NOT' Found = ''%s''\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447AE1u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x447AE1u));
    cpu->esp += 8u;
    label_00047AE4:
    cpu->eax = 0xFFFFFFF6u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00047B00:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447B07u)); sfera_sub_0043A300(cpu, LIFT_CODE_TOKEN_VA(0x447B07u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_00047C0D;
    (void)cpu;
    label_00047B10:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<CBaseManagerCommonItem*>(cpu->ecx)->handleRemove(cpu);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447B23u)); sfera_sub_0043A3D0(cpu, LIFT_CODE_TOKEN_VA(0x447B23u));
    if ((uint32_t)(cpu->eax) != 0u) goto label_00047B10;
    label_00047B27:
    if ((uint32_t)(lift_load32(cpu->ebx + 0xB4u)) != (uint32_t)(1u)) goto label_00047BA4;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x10u)) == (uint32_t)(0u)) goto label_00047BA4;
    cpu->ecx = 0x35u;
    cpu->esi = cpu->ebx;
    cpu->edi = (uint32_t)(cpu->esp + 0x50u);
    lift_movs32(cpu, 1u);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_00047B59;
    cpu->ecx = 0x6Fu;
    cpu->edi = (uint32_t)(cpu->esp + 0x124u);
    lift_movs32(cpu, 1u);
    label_00047B59:
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, 0x20u);
    cpu->ecx += 4u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x447B68u));
    cpu->ecx = g_sfera_recovered_static_runtime.server_number;
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    cpu->eax = (uint32_t)(cpu->esp + 0x5Cu);
    cpu->esp += 0xCu;
    lift_store8(cpu->esp + 0x4Fu, 0u);
    lift_store32(cpu->esp + 0x20u, 0x290u);
    lift_store32(cpu->esp + 0x1Cu, 5u);
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    lift_store32(cpu->esp + 0x24u, 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    label_00047BA4:
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447BB0u)); sfera_sub_00443860(cpu, LIFT_CODE_TOKEN_VA(0x447BB0u));
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(0xFFFFFFFAu)) goto label_00047C3F;
    if ((uint8_t)(lift_load8(cpu->esi + 0xD4u)) == (uint8_t)(0u)) goto label_00047BD5;
    cpu->edi += 4u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)" Delete ItemItem ER_CURITEMS_LESS_MINITEMS = ''%s''\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447BD2u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x447BD2u));
    cpu->esp += 8u;
    label_00047BD5:
    if ((uint8_t)(lift_load8(cpu->esi + 0xD4u)) != (uint8_t)(2u)) goto label_00047BE5;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x47BE5u)); sfera_sub_0043A6F0(cpu, LIFT_CODE_TOKEN_RVA(0x47BE5u));
    label_00047BE5:
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447BF1u)); sfera_sub_00443730(cpu, LIFT_CODE_TOKEN_VA(0x447BF1u));
    cpu->eax = 0xFFFFFFFAu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00047C0D:
    if ((uint8_t)(lift_load8(cpu->esi + 0xD4u)) == (uint8_t)(0u)) goto label_00047C23;
    lift_push32(cpu, (uint32_t)(uintptr_t)" Delete pItemTo 'NOT' Found\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447C20u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x447C20u));
    cpu->esp += 4u;
    label_00047C23:
    cpu->eax = 0xFFFFFFF5u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00047C3F:
    if ((uint32_t)(cpu->ebx) != 0u) goto label_00047C6C;
    if ((uint8_t)(lift_load8(cpu->esi + 0xD4u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00047C5C;
    cpu->edi += 4u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)" Delete ItemItem  'OK' = ''%s''\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447C59u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x447C59u));
    cpu->esp += 8u;
    label_00047C5C:
    if ((uint8_t)(lift_load8(cpu->esi + 0xD4u)) != (uint8_t)(2u)) goto label_00047C6C;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x47C6Cu)); sfera_sub_0043A6F0(cpu, LIFT_CODE_TOKEN_RVA(0x47C6Cu));
    label_00047C6C:
    cpu->eax = cpu->ebx;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00047C85:
    if ((uint8_t)(lift_load8(cpu->esi + 0xD4u)) == (uint8_t)(0u)) goto label_00047C9B;
    lift_push32(cpu, (uint32_t)(uintptr_t)" Delete ItemItem  'ERROR' ITEM NOT FOUND\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447C98u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x447C98u));
    cpu->esp += 4u;
    label_00047C9B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0xFFFFFFFCu;
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00447CC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x2DCu;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ebx = cpu->ecx;
    std::construct_at(reinterpret_cast<CItemListCommonItem*>(cpu->esp + 0x44u));
    std::construct_at(reinterpret_cast<CCommonItem*>(cpu->esp + 0x118u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447CFEu)); sfera_sub_00443230(cpu, LIFT_CODE_TOKEN_VA(0x447CFEu));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00047DA7;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447D10u)); sfera_sub_00443680(cpu, LIFT_CODE_TOKEN_VA(0x447D10u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_00047DA7;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x10u));
    lift_store_f32(cpu->eax + 0x9Cu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x14u));
    lift_store_f32(cpu->eax + 0xA0u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x18u));
    lift_store_f32(cpu->eax + 0xA4u, lift_x87_get(cpu, 0u));
    if ((uint32_t)(lift_load32(cpu->esi + 0xB4u)) != (uint32_t)(1u)) goto label_00047DA1;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x1Cu)) == (uint32_t)(0u)) goto label_00047DA1;
    cpu->ecx = 0x35u;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    cpu->edi = (uint32_t)(cpu->esp + 0x40u);
    lift_movs32(cpu, 1u);
    cpu->esi = cpu->eax;
    cpu->ecx = 0x6Fu;
    cpu->edi = (uint32_t)(cpu->esp + 0x114u);
    lift_movs32(cpu, 1u);
    lift_store_f32(cpu->esp + 0x2D0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x2D4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x2D8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0x20u);
    cpu->ebx += 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x447D7Fu));
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
    label_00047DA1:
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00047DA7:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00447DD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, 0x96u);
    cpu->eax = (uint32_t)(cpu->edi + 4u);
    lift_push32(cpu, (uintptr_t)""); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x447DE3u));
    cpu->ecx = lift_load32(cpu->edi + 0xD0u);
    cpu->esp += 0xCu;
    cpu->ebx = 0u;
    lift_push32(cpu, 0x1C5u);
    cpu->edx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\lists\\ItemList.h";
    lift_store8(cpu->edi + 0x99u, cpu->ebx & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447E09u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x447E09u));
    cpu->edx = 0x1C7u;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\lists\\ItemList.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447E18u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x447E18u));
    cpu->esi = lift_load32(cpu->edi + 0xCCu);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_00047E6A;
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00047E37;
    cpu->ecx = lift_load32(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<StdAllocator*>(cpu->ecx)->deallocate(cpu);
    lift_store32(cpu->esi + 4u, cpu->ebx);
    label_00047E37:
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00047E4C;
    cpu->ecx = lift_load32(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<StdAllocator*>(cpu->ecx)->deallocate(cpu);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    label_00047E4C:
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00047E61;
    cpu->ecx = lift_load32(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->eax);
    reinterpret_cast<StdAllocator*>(cpu->ecx)->deallocate(cpu);
    lift_store32(cpu->esi + 0x18u, cpu->ebx);
    label_00047E61:
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447E67u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x447E67u));
    cpu->esp += 4u;
    label_00047E6A:
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0xC8u)), r=(uint64_t)((cpu->ebx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00047E8C;
    lift_push32(cpu, (uint32_t)(uintptr_t)"~~~~~ItemList~~~DEINITIALIZE~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447E7Fu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x447E7Fu));
    lift_push32(cpu, (uint32_t)(uintptr_t)" Deinitialize complete\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447E89u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x447E89u));
    cpu->esp += 8u;
    label_00047E8C:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00447E90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebp + 0xC8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00047EAB;
    lift_push32(cpu, (uint32_t)(uintptr_t)"~~~~~ItemList~~~ADD ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447EA8u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x447EA8u));
    cpu->esp += 4u;
    label_00047EAB:
    cpu->ecx = lift_load32(cpu->ebp + 0xACu);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xB0u)) != (uint32_t)(cpu->ecx)) goto label_00047F43;
    cpu->eax = cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(3u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->esi = (uint32_t)(cpu->edx + cpu->eax);
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(2u), 32u);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(0x32u)) goto label_00047ED3;
    cpu->esi = 0x32u;
    label_00047ED3:
    cpu->edx = (uint32_t)(cpu->ecx + cpu->esi);
    cpu->ecx = lift_load32(cpu->ebp + 0xD0u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xD4u);
    lift_push32(cpu, 0x1E7u); lift_push32(cpu, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\lists\\ItemList.h");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447EF1u)); sfera_sub_004EBE80(cpu, LIFT_CODE_TOKEN_VA(0x447EF1u));
    lift_store32(cpu->ebp + 0xD0u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00047F1B;
    if ((uint8_t)(lift_load8(cpu->ebp + 0xC8u)) == (uint8_t)((cpu->eax & 0xFFu))) goto label_00047F10;
    lift_push32(cpu, (uint32_t)(uintptr_t)" AddItem = 'ERROR' MEMORY NOT ALLOC\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447F0Du)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x447F0Du));
    cpu->esp += 4u;
    label_00047F10:
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0xFFFFFFECu;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00047F1B:
    cpu->edx = lift_load32(cpu->ebp + 0xACu);
    cpu->ecx = cpu->esi;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xD4u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xD4u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->eax;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x447F35u));
    cpu->esp += 0xCu;
    lift_store32(cpu->ebp + 0xACu, (uint64_t)(lift_load32(cpu->ebp + 0xACu)) + (uint64_t)(cpu->esi) + (uint64_t)(0u));
    label_00047F43:
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 0xCCu);
    cpu->esi += 4u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x1Eu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->esp + 0xCu, cpu->eax & 0xFFu);
    cpu->eax = cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00047F61:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00047F61;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(lift_load32(cpu->edi))) goto label_00047F8C;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x447F7Cu)); sfera_sub_00438220(cpu, LIFT_CODE_TOKEN_VA(0x447F7Cu));
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00047F8C;
    cpu->ecx = lift_load32(cpu->edi + 8u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    cpu->ecx += lift_load32(cpu->edi + 4u);
    goto label_00047F8F;
    label_00047F8C:
    cpu->ecx = (uint32_t)(cpu->edi + 0x28u);
    label_00047F8F:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(0xFFFFFFFFu)) goto label_0004802B;
    if ((int32_t)(uint32_t)(cpu->ebx) < 0) goto label_00047FA7;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->ebp + 0xACu))) goto label_00047FB6;
    label_00047FA7:
    cpu->edx = 0x1F8u;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\lists\\ItemList.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x47FB6u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x47FB6u));
    label_00047FB6:
    cpu->edi = lift_load32(cpu->ebp + 0xD0u);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    cpu->eax = cpu->ebx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xD4u);
    cpu->edi += cpu->eax;
    cpu->ecx = 0x35u;
    lift_movs32(cpu, 1u);
    cpu->edx = lift_load32(cpu->ebp + 0xD0u);
    lift_store8(cpu->edx + cpu->eax + 0x9Au, 1u);
    if ((uint8_t)(lift_load8(cpu->ebp + 0xC8u)) == (uint8_t)(0u)) goto label_0004801E;
    if ((int32_t)(uint32_t)(cpu->ebx) < 0) goto label_00048011;
    cpu->ecx = lift_load32(cpu->ebp + 0xD0u);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->eax + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)" AddItem Rewrite = ''%s''\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448001u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x448001u));
    cpu->esp += 8u;
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0xFFFFFF97u;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00048011:
    lift_push32(cpu, (uint32_t)(uintptr_t)" AddItem = 'ERROR' MEMORY NOT ALLOC\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44801Bu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x44801Bu));
    cpu->esp += 4u;
    label_0004801E:
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0xFFFFFF97u;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0004802B:
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0xACu)) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0004805B;
    cpu->eax = lift_load32(cpu->ebp + 0xD0u);
    cpu->eax += 0x9Au;
    label_00048044:
    if ((uint8_t)(lift_load8(cpu->eax)) == (uint8_t)(0u)) goto label_00048065;
    ++cpu->ebx;
    cpu->eax += 0xD4u;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->ebp + 0xACu))) goto label_00048044;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    label_0004805B:
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00048065:
    cpu->ecx = lift_load32(cpu->ebp + 0xCCu);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44807Cu)); sfera_sub_0043AA30(cpu, LIFT_CODE_TOKEN_VA(0x44807Cu));
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_000480FB;
    cpu->edi = lift_load32(cpu->ebp + 0xD0u);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    cpu->eax = cpu->ebx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xD4u);
    cpu->edi += cpu->eax;
    cpu->ecx = 0x35u;
    lift_movs32(cpu, 1u);
    cpu->ecx = lift_load32(cpu->ebp + 0xD0u);
    lift_store8(cpu->ecx + cpu->eax + 0x9Au, 1u);
    if ((uint8_t)(lift_load8(cpu->ebp + 0xC8u)) == (uint8_t)(0u)) goto label_000480EB;
    if ((int32_t)(uint32_t)(cpu->ebx) < 0) goto label_000480DE;
    cpu->edx = lift_load32(cpu->ebp + 0xD0u);
    cpu->eax = (uint32_t)(cpu->edx + cpu->eax + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)" AddItem = ''%s''\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4480CBu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x4480CBu));
    lift_store32(cpu->ebp + 0xB0u, (uint64_t)(lift_load32(cpu->ebp + 0xB0u)) + 1u);
    cpu->esp += 8u;
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000480DE:
    lift_push32(cpu, (uint32_t)(uintptr_t)" AddItem = 'ERROR' NOT ADD\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4480E8u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x4480E8u));
    cpu->esp += 4u;
    label_000480EB:
    lift_store32(cpu->ebp + 0xB0u, (uint64_t)(lift_load32(cpu->ebp + 0xB0u)) + 1u);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000480FB:
    if ((uint8_t)(lift_load8(cpu->ebp + 0xC8u)) == (uint8_t)(0u)) goto label_00048111;
    lift_push32(cpu, (uint32_t)(uintptr_t)" AddItem = 'ERROR' NOT ADD\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44810Eu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x44810Eu));
    cpu->esp += 4u;
    label_00048111:
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0xFFFFFFFDu;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00448120(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebp + 0xC8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0004813B;
    lift_push32(cpu, (uint32_t)(uintptr_t)"~~~~~ItemList~~~ADD ITEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448138u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x448138u));
    cpu->esp += 4u;
    label_0004813B:
    cpu->ecx = lift_load32(cpu->ebp + 0xACu);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xB0u)) != (uint32_t)(cpu->ecx)) goto label_000481D3;
    cpu->eax = cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(3u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->esi = (uint32_t)(cpu->edx + cpu->eax);
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(2u), 32u);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(0x32u)) goto label_00048163;
    cpu->esi = 0x32u;
    label_00048163:
    cpu->edx = (uint32_t)(cpu->ecx + cpu->esi);
    cpu->ecx = lift_load32(cpu->ebp + 0xD0u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1BCu);
    lift_push32(cpu, 0x1E7u); lift_push32(cpu, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\lists\\ItemList.h");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448181u)); sfera_sub_004EBE80(cpu, LIFT_CODE_TOKEN_VA(0x448181u));
    lift_store32(cpu->ebp + 0xD0u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000481AB;
    if ((uint8_t)(lift_load8(cpu->ebp + 0xC8u)) == (uint8_t)((cpu->eax & 0xFFu))) goto label_000481A0;
    lift_push32(cpu, (uint32_t)(uintptr_t)" AddItem = 'ERROR' MEMORY NOT ALLOC\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44819Du)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x44819Du));
    cpu->esp += 4u;
    label_000481A0:
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0xFFFFFFECu;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000481AB:
    cpu->edx = lift_load32(cpu->ebp + 0xACu);
    cpu->ecx = cpu->esi;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x1BCu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x1BCu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->eax;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4481C5u));
    cpu->esp += 0xCu;
    lift_store32(cpu->ebp + 0xACu, (uint64_t)(lift_load32(cpu->ebp + 0xACu)) + (uint64_t)(cpu->esi) + (uint64_t)(0u));
    label_000481D3:
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 0xCCu);
    cpu->esi += 4u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 0x1Eu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->esp + 0xCu, cpu->eax & 0xFFu);
    cpu->eax = cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_000481F1:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000481F1;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(lift_load32(cpu->edi))) goto label_0004821C;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44820Cu)); sfera_sub_00438220(cpu, LIFT_CODE_TOKEN_VA(0x44820Cu));
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_0004821C;
    cpu->ecx = lift_load32(cpu->edi + 8u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(cpu->eax);
    cpu->ecx += lift_load32(cpu->edi + 4u);
    goto label_0004821F;
    label_0004821C:
    cpu->ecx = (uint32_t)(cpu->edi + 0x28u);
    label_0004821F:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(0xFFFFFFFFu)) goto label_000482BB;
    if ((int32_t)(uint32_t)(cpu->ebx) < 0) goto label_00048237;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->ebp + 0xACu))) goto label_00048246;
    label_00048237:
    cpu->edx = 0x1F8u;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\lists\\ItemList.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x48246u)); sfera_sub_0047EBA0(cpu, LIFT_CODE_TOKEN_RVA(0x48246u));
    label_00048246:
    cpu->edi = lift_load32(cpu->ebp + 0xD0u);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    cpu->eax = cpu->ebx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1BCu);
    cpu->edi += cpu->eax;
    cpu->ecx = 0x6Fu;
    lift_movs32(cpu, 1u);
    cpu->edx = lift_load32(cpu->ebp + 0xD0u);
    lift_store8(cpu->edx + cpu->eax + 0x9Au, 1u);
    if ((uint8_t)(lift_load8(cpu->ebp + 0xC8u)) == (uint8_t)(0u)) goto label_000482AE;
    if ((int32_t)(uint32_t)(cpu->ebx) < 0) goto label_000482A1;
    cpu->ecx = lift_load32(cpu->ebp + 0xD0u);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->eax + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)" AddItem Rewrite = ''%s''\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448291u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x448291u));
    cpu->esp += 8u;
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0xFFFFFF97u;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000482A1:
    lift_push32(cpu, (uint32_t)(uintptr_t)" AddItem = 'ERROR' MEMORY NOT ALLOC\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4482ABu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x4482ABu));
    cpu->esp += 4u;
    label_000482AE:
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0xFFFFFF97u;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000482BB:
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp + 0xACu)) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_000482EB;
    cpu->eax = lift_load32(cpu->ebp + 0xD0u);
    cpu->eax += 0x9Au;
    label_000482D4:
    if ((uint8_t)(lift_load8(cpu->eax)) == (uint8_t)(0u)) goto label_000482F5;
    ++cpu->ebx;
    cpu->eax += 0x1BCu;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->ebp + 0xACu))) goto label_000482D4;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    label_000482EB:
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000482F5:
    cpu->ecx = lift_load32(cpu->ebp + 0xCCu);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44830Cu)); sfera_sub_0043AA30(cpu, LIFT_CODE_TOKEN_VA(0x44830Cu));
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0004838B;
    cpu->edi = lift_load32(cpu->ebp + 0xD0u);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    cpu->eax = cpu->ebx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x1BCu);
    cpu->edi += cpu->eax;
    cpu->ecx = 0x6Fu;
    lift_movs32(cpu, 1u);
    cpu->ecx = lift_load32(cpu->ebp + 0xD0u);
    lift_store8(cpu->ecx + cpu->eax + 0x9Au, 1u);
    if ((uint8_t)(lift_load8(cpu->ebp + 0xC8u)) == (uint8_t)(0u)) goto label_0004837B;
    if ((int32_t)(uint32_t)(cpu->ebx) < 0) goto label_0004836E;
    cpu->edx = lift_load32(cpu->ebp + 0xD0u);
    cpu->eax = (uint32_t)(cpu->edx + cpu->eax + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)" AddItem = ''%s''\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44835Bu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x44835Bu));
    lift_store32(cpu->ebp + 0xB0u, (uint64_t)(lift_load32(cpu->ebp + 0xB0u)) + 1u);
    cpu->esp += 8u;
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0004836E:
    lift_push32(cpu, (uint32_t)(uintptr_t)" AddItem = 'ERROR' NOT ADD\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448378u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x448378u));
    cpu->esp += 4u;
    label_0004837B:
    lift_store32(cpu->ebp + 0xB0u, (uint64_t)(lift_load32(cpu->ebp + 0xB0u)) + 1u);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0004838B:
    if ((uint8_t)(lift_load8(cpu->ebp + 0xC8u)) == (uint8_t)(0u)) goto label_000483A1;
    lift_push32(cpu, (uint32_t)(uintptr_t)" AddItem = 'ERROR' NOT ADD\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44839Eu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x44839Eu));
    cpu->esp += 4u;
    label_000483A1:
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0xFFFFFFFDu;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004483B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    g_sfera_mbc_runtime->saved_invocation.process_memory_base = (uint32_t)(cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->argument_cursor;
    g_sfera_mbc_runtime->saved_invocation.value_stack_size = (uint32_t)(cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->argument_end;
    g_sfera_mbc_runtime->saved_invocation.argument_cursor = (uint32_t)(cpu->eax);
    cpu->eax = 1u;
    g_sfera_mbc_runtime->saved_invocation.argument_end = (uint32_t)(cpu->edx);
    cpu->edx |= 0xFFFFFFFFu;
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(0xFAu);
    g_sfera_mbc_runtime->argument_end = (uint32_t)(0xFFu);
    g_sfera_mbc_runtime->process_memory_base = (uint32_t)(0u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[250].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[250].payload[0] = (uint32_t)(0xFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[250].source_id = (uint32_t)(cpu->edx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[250].range_end = (uint32_t)(cpu->eax);
    g_sfera_mbc_interpreter_storage.value_stack.entries[250].range_begin = (uint32_t)(cpu->eax);
    g_sfera_mbc_interpreter_storage.value_stack.entries[251].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[251].payload[0] = (uint32_t)(cpu->ecx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[251].source_id = (uint32_t)(cpu->edx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[251].range_end = (uint32_t)(cpu->eax);
    g_sfera_mbc_interpreter_storage.value_stack.entries[251].range_begin = (uint32_t)(cpu->eax);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(0xFCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448455u)); sfera_sub_00446D40(cpu, LIFT_CODE_TOKEN_VA(0x448455u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44845Au)); sfera_sub_0043AC30(cpu, LIFT_CODE_TOKEN_VA(0x44845Au));
    cpu->ecx = g_sfera_mbc_runtime->saved_invocation.process_memory_base;
    cpu->edx = g_sfera_mbc_runtime->saved_invocation.value_stack_size;
    g_sfera_mbc_runtime->process_memory_base = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->saved_invocation.argument_cursor;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->saved_invocation.argument_end;
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->argument_end = (uint32_t)(cpu->edx);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00448490(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    cpu->edx = g_sfera_mbc_runtime->argument_cursor;
    g_sfera_mbc_runtime->saved_invocation.process_memory_base = (uint32_t)(cpu->eax);
    cpu->eax = g_sfera_mbc_runtime->argument_end;
    g_sfera_mbc_runtime->saved_invocation.argument_end = (uint32_t)(cpu->eax);
    cpu->eax = 0x10u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[250].type = (uint32_t)(cpu->eax);
    g_sfera_mbc_interpreter_storage.value_stack.entries[250].payload[0] = (uint32_t)(cpu->eax);
    cpu->eax = 1u;
    g_sfera_mbc_runtime->saved_invocation.value_stack_size = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->saved_invocation.argument_cursor = (uint32_t)(cpu->edx);
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(0xFAu);
    g_sfera_mbc_runtime->argument_end = (uint32_t)(0xFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[250].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[250].range_end = (uint32_t)(cpu->eax);
    g_sfera_mbc_interpreter_storage.value_stack.entries[250].range_begin = (uint32_t)(cpu->eax);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(0xFBu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448507u)); sfera_sub_00446D40(cpu, LIFT_CODE_TOKEN_VA(0x448507u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44850Cu)); sfera_sub_0043AC30(cpu, LIFT_CODE_TOKEN_VA(0x44850Cu));
    cpu->ecx = g_sfera_mbc_runtime->saved_invocation.process_memory_base;
    cpu->edx = g_sfera_mbc_runtime->saved_invocation.value_stack_size;
    g_sfera_mbc_runtime->process_memory_base = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->saved_invocation.argument_cursor;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->saved_invocation.argument_end;
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->argument_end = (uint32_t)(cpu->edx);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00448540(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_store32(cpu->esp, cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = cpu->ecx;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    g_sfera_mbc_runtime->saved_invocation.value_stack_size = (uint32_t)(cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->argument_end;
    g_sfera_mbc_runtime->saved_invocation.process_memory_base = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->argument_cursor;
    g_sfera_mbc_runtime->saved_invocation.argument_end = (uint32_t)(cpu->edx);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    lift_push32(cpu, cpu->ebx);
    g_sfera_mbc_runtime->saved_invocation.argument_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = 0xFAu;
    g_sfera_mbc_runtime->process_memory_base = (uint32_t)(cpu->edx);
    lift_push32(cpu, cpu->esi);
    cpu->edx -= cpu->eax;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->argument_end = (uint32_t)(0xFFu);
    cpu->esi = 1u;
    cpu->ebx = 0u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_000485B0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    cpu->eax += cpu->esi;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000485B0;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->eax + 0x28u, cpu->ebx);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000485E3;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4485DBu)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x4485DBu));
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    goto label_0004861A;
    label_000485E3:
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(0xEu);
    cpu->ecx += cpu->esi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->esi);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->esi);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    label_0004861A:
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0004862E;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44862Cu)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x44862Cu));
    goto label_00048661;
    label_0004862E:
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(cpu->ebx);
    cpu->ecx += cpu->esi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->esi);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->esi);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    label_00048661:
    cpu->edx = 0x11u;
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0xCu, 0x28u);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44867Fu)); sfera_sub_0043AF30(cpu, LIFT_CODE_TOKEN_VA(0x44867Fu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448684u)); sfera_sub_00446D40(cpu, LIFT_CODE_TOKEN_VA(0x448684u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448689u)); sfera_sub_0043AC30(cpu, LIFT_CODE_TOKEN_VA(0x448689u));
    cpu->esi = lift_pop32(cpu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004869D;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx = lift_load32(cpu->ecx + 0x28u);
    cpu->ecx = lift_load32(cpu->esp);
    lift_store32(cpu->ecx, cpu->edx);
    label_0004869D:
    cpu->edx = g_sfera_mbc_runtime->saved_invocation.process_memory_base;
    cpu->ecx = g_sfera_mbc_runtime->saved_invocation.value_stack_size;
    g_sfera_mbc_runtime->process_memory_base = (uint32_t)(cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->saved_invocation.argument_cursor;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->saved_invocation.argument_end;
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->edx);
    g_sfera_mbc_runtime->argument_end = (uint32_t)(cpu->ecx);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004486E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_store32(cpu->esp, cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = cpu->ecx;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    g_sfera_mbc_runtime->saved_invocation.value_stack_size = (uint32_t)(cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->argument_end;
    g_sfera_mbc_runtime->saved_invocation.process_memory_base = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->argument_cursor;
    g_sfera_mbc_runtime->saved_invocation.argument_end = (uint32_t)(cpu->edx);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    g_sfera_mbc_runtime->saved_invocation.argument_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = 0xFAu;
    lift_push32(cpu, cpu->esi);
    g_sfera_mbc_runtime->process_memory_base = (uint32_t)(cpu->edx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->argument_end = (uint32_t)(0xFFu);
    cpu->edx -= cpu->eax;
    cpu->esi = 1u;
    label_00048746:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    cpu->eax += cpu->esi;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00048746;
    lift_x87_push(cpu, 0.0);
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store_f32(cpu->eax + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0004877B;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448773u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x448773u));
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    goto label_000487B2;
    label_0004877B:
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(0xEu);
    cpu->ecx += cpu->esi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->esi);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->esi);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    label_000487B2:
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000487C6;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4487C4u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x4487C4u));
    goto label_000487FD;
    label_000487C6:
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(0u);
    cpu->ecx += cpu->esi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->esi);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->esi);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    label_000487FD:
    cpu->edx = 0x21u;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_store32(cpu->esp + 8u, 0x28u);
    lift_store32(cpu->esp + 0xCu, 0u);
    lift_store32(cpu->esp + 0x10u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448823u)); sfera_sub_0043AF30(cpu, LIFT_CODE_TOKEN_VA(0x448823u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448828u)); sfera_sub_00446D40(cpu, LIFT_CODE_TOKEN_VA(0x448828u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44882Du)); sfera_sub_0043AC30(cpu, LIFT_CODE_TOKEN_VA(0x44882Du));
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00048840;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x28u));
    cpu->edx = lift_load32(cpu->esp);
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00048840:
    cpu->ecx = g_sfera_mbc_runtime->saved_invocation.process_memory_base;
    cpu->edx = g_sfera_mbc_runtime->saved_invocation.value_stack_size;
    g_sfera_mbc_runtime->process_memory_base = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->saved_invocation.argument_cursor;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->saved_invocation.argument_end;
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->argument_end = (uint32_t)(cpu->edx);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00448880(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->ecx;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    g_sfera_mbc_runtime->saved_invocation.value_stack_size = (uint32_t)(cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->argument_end;
    g_sfera_mbc_runtime->saved_invocation.process_memory_base = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->argument_cursor;
    g_sfera_mbc_runtime->saved_invocation.argument_end = (uint32_t)(cpu->edx);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    g_sfera_mbc_runtime->saved_invocation.argument_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = 0xFAu;
    g_sfera_mbc_runtime->process_memory_base = (uint32_t)(cpu->edx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->argument_end = (uint32_t)(0xFFu);
    cpu->edx -= cpu->eax;
    cpu->ebx = 1u;
    label_000488E6:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    cpu->eax += cpu->ebx;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000488E6;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    lift_store8(cpu->eax + 0x28u, cpu->ecx & 0xFFu);
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00048919;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448911u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x448911u));
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    goto label_00048950;
    label_00048919:
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(0xEu);
    cpu->ecx += cpu->ebx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->ebx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->ebx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    label_00048950:
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00048964;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448962u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x448962u));
    goto label_0004899B;
    label_00048964:
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(0u);
    cpu->ecx += cpu->ebx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->ebx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->ebx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    label_0004899B:
    cpu->edx = cpu->ebx;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_store32(cpu->esp + 8u, 0x28u);
    lift_store32(cpu->esp + 0xCu, 0u);
    lift_store32(cpu->esp + 0x10u, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4489BEu)); sfera_sub_0043AF30(cpu, LIFT_CODE_TOKEN_VA(0x4489BEu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4489C3u)); sfera_sub_00446D40(cpu, LIFT_CODE_TOKEN_VA(0x4489C3u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4489C8u)); sfera_sub_0043AC30(cpu, LIFT_CODE_TOKEN_VA(0x4489C8u));
    if ((uint32_t)(cpu->eax) != 0u) goto label_000489E1;
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx += 0x28u;
    label_000489D5:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    lift_store8(cpu->esi, cpu->ecx & 0xFFu);
    cpu->edx += cpu->ebx;
    cpu->esi += cpu->ebx;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000489D5;
    label_000489E1:
    cpu->ecx = g_sfera_mbc_runtime->saved_invocation.process_memory_base;
    cpu->edx = g_sfera_mbc_runtime->saved_invocation.value_stack_size;
    g_sfera_mbc_runtime->process_memory_base = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->saved_invocation.argument_cursor;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->saved_invocation.argument_end;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->argument_end = (uint32_t)(cpu->edx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00448A20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->edx;
    cpu->edx = g_sfera_mbc_runtime->value_stack_size;
    cpu->eax = cpu->ecx;
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    g_sfera_mbc_runtime->saved_invocation.value_stack_size = (uint32_t)(cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->argument_end;
    g_sfera_mbc_runtime->saved_invocation.process_memory_base = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->argument_cursor;
    g_sfera_mbc_runtime->saved_invocation.argument_end = (uint32_t)(cpu->edx);
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    g_sfera_mbc_runtime->saved_invocation.argument_cursor = (uint32_t)(cpu->ecx);
    cpu->ecx = 0xFAu;
    lift_push32(cpu, cpu->esi);
    g_sfera_mbc_runtime->process_memory_base = (uint32_t)(cpu->edx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->argument_end = (uint32_t)(0xFFu);
    cpu->edx -= cpu->eax;
    cpu->esi = 1u;
    label_00048A83:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    cpu->eax += cpu->esi;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00048A83;
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00048AAE;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448AA6u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x448AA6u));
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    goto label_00048AE5;
    label_00048AAE:
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(0xDu);
    cpu->ecx += cpu->esi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->esi);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->esi);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    label_00048AE5:
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00048AFF;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448AF7u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x448AF7u));
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    goto label_00048B36;
    label_00048AFF:
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(0u);
    cpu->ecx += cpu->esi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->esi);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->esi);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    label_00048B36:
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00048B4A;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448B48u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x448B48u));
    goto label_00048B7D;
    label_00048B4A:
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(0x10u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(cpu->ebp);
    cpu->ecx += cpu->esi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(0xFFFFFFFFu);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->esi);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->esi);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    label_00048B7D:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448B82u)); sfera_sub_00446D40(cpu, LIFT_CODE_TOKEN_VA(0x448B82u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448B87u)); sfera_sub_0043AC30(cpu, LIFT_CODE_TOKEN_VA(0x448B87u));
    cpu->ecx = g_sfera_mbc_runtime->saved_invocation.process_memory_base;
    cpu->edx = g_sfera_mbc_runtime->saved_invocation.value_stack_size;
    g_sfera_mbc_runtime->process_memory_base = (uint32_t)(cpu->ecx);
    cpu->ecx = g_sfera_mbc_runtime->saved_invocation.argument_cursor;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->edx);
    cpu->edx = g_sfera_mbc_runtime->saved_invocation.argument_end;
    cpu->esi = lift_pop32(cpu);
    g_sfera_mbc_runtime->argument_cursor = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->argument_end = (uint32_t)(cpu->edx);
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00448BC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1B4u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0xD4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x1D0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00048BF6;
    lift_push32(cpu, (uint32_t)(uintptr_t)"\n-----BaseManager---ADD LIST-----------------------------------------\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448BF3u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x448BF3u));
    cpu->esp += 4u;
    label_00048BF6:
    cpu->ebp = lift_load32(cpu->esp + 0x1D4u);
    cpu->eax = lift_load32(cpu->esp + 0x1CCu);
    cpu->ecx = lift_load32(cpu->esp + 0x1C8u);
    cpu->edx = lift_load32(cpu->esp + 0x1C4u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0xFCu);
    std::construct_at(reinterpret_cast<CItemListCommonItem*>(cpu->esp + 0xFCu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448C2Eu)); sfera_sub_0043A830(cpu, LIFT_CODE_TOKEN_VA(0x448C2Eu));
    if ((uint32_t)(cpu->eax) != 0u) goto label_00048D6B;
    cpu->eax = (uint32_t)(cpu->esp + 0xE8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448C45u)); sfera_sub_00443230(cpu, LIFT_CODE_TOKEN_VA(0x448C45u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_00048C69;
    if ((uint8_t)(lift_load8(cpu->esi + 0xD4u)) == (uint8_t)(0u)) goto label_00048C5F;
    lift_push32(cpu, (uint32_t)(uintptr_t)" Added List = 'ERROR' ALREADY EXIST\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448C5Cu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x448C5Cu));
    cpu->esp += 4u;
    label_00048C5F:
    cpu->eax = 0xFFFFFF9Bu;
    goto label_00048D6B;
    label_00048C69:
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0xECu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448C79u)); sfera_sub_00447E90(cpu, LIFT_CODE_TOKEN_VA(0x448C79u));
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ebx) != 0u) goto label_00048D38;
    cpu->edx = (uint32_t)(cpu->esp + 0xECu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448C92u)); sfera_sub_00443230(cpu, LIFT_CODE_TOKEN_VA(0x448C92u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_00048CA2;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 0xD4u)) & 0xFFu);
    lift_store8(cpu->eax + 0xC8u, cpu->ecx & 0xFFu);
    label_00048CA2:
    if ((uint8_t)(lift_load8(cpu->esi + 0xD4u)) == (uint8_t)(0u)) goto label_00048CC0;
    cpu->edx = (uint32_t)(cpu->esp + 0xF0u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)" Added List  'OK' = ''%s''\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448CBDu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x448CBDu));
    cpu->esp += 8u;
    label_00048CC0:
    if ((uint8_t)(lift_load8(cpu->esi + 0xD4u)) != (uint8_t)(2u)) goto label_00048CD0;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x48CD0u)); sfera_sub_0043A6F0(cpu, LIFT_CODE_TOKEN_RVA(0x48CD0u));
    label_00048CD0:
    cpu->eax = 1u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x1D0u)) != (uint32_t)(cpu->eax)) goto label_00048D34;
    if ((uint32_t)(lift_load32(cpu->esp + 0x1DCu)) == (uint32_t)(0u)) goto label_00048D34;
    cpu->ecx = lift_load32(cpu->esp + 0x1C8u);
    cpu->edx = lift_load32(cpu->esp + 0x1CCu);
    lift_push32(cpu, 0x96u);
    lift_store32(cpu->esp + 0x50u, cpu->eax);
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::strncpy);
    cpu->eax = (uint32_t)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x50u, cpu->ecx);
    lift_store32(cpu->esp + 0x54u, cpu->edx);
    lift_store32(cpu->esp + 0xF4u, cpu->ebp);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x48D1Cu), LIFT_CODE_TOKEN_RVA(0x48D1Au))) { return; }
    lift_push32(cpu, 0x20u);
    cpu->esi += 4u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    lift_store8(cpu->esp + 0xFDu, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x48D31u), LIFT_CODE_TOKEN_RVA(0x48D2Fu))) { return; }
    cpu->esp += 0x18u;
    label_00048D34:
    cpu->eax = 0u;
    goto label_00048D6A;
    label_00048D38:
    if ((uint32_t)(cpu->ebx) != (uint32_t)(0xFFFFFFECu)) goto label_00048D4D;
    if ((uint8_t)(lift_load8(cpu->esi + 0xD4u)) == (uint8_t)(0u)) goto label_00048D68;
    lift_push32(cpu, (uint32_t)(uintptr_t)" Added List = 'ERROR' ER_ITEM_MEMORY_NOT_ALLOC\n");
    goto label_00048D60;
    label_00048D4D:
    if ((uint32_t)(cpu->ebx) != (uint32_t)(0xFFFFFFFDu)) goto label_00048D68;
    if ((uint8_t)(lift_load8(cpu->esi + 0xD4u)) == (uint8_t)(0u)) goto label_00048D68;
    lift_push32(cpu, (uint32_t)(uintptr_t)" Added List = 'ERROR' ER_ITEM_NOT_ADDED\n");
    label_00048D60:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448D65u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x448D65u));
    cpu->esp += 4u;
    label_00048D68:
    cpu->eax = cpu->ebx;
    label_00048D6A:
    cpu->ebx = lift_pop32(cpu);
    label_00048D6B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x1B4u;
    cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00448D90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x2D4u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 0xCu);
    cpu->ebx = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + 0xD4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00048DCF;
    lift_push32(cpu, (uint32_t)(uintptr_t)"\n-----BaseManager---ADD ITEM ITEM----------------------------------------\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448DCCu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x448DCCu));
    cpu->esp += 4u;
    label_00048DCF:
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    std::construct_at(reinterpret_cast<CItemListCommonItem*>(cpu->esp + 0x4Cu));
    std::construct_at(reinterpret_cast<CCommonItem*>(cpu->esp + 0x120u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448DEAu)); sfera_sub_00443230(cpu, LIFT_CODE_TOKEN_VA(0x448DEAu));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00049161;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448DFCu)); sfera_sub_00448120(cpu, LIFT_CODE_TOKEN_VA(0x448DFCu));
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00048F83;
    if ((uint8_t)(lift_load8(cpu->ebx + 0xD4u)) == (uint8_t)((cpu->eax & 0xFFu))) goto label_00048E21;
    cpu->eax = (uint32_t)(cpu->edi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)" Added ItemItem  'OK' = ''%s''\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448E1Eu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x448E1Eu));
    cpu->esp += 8u;
    label_00048E21:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448E29u)); sfera_sub_00443680(cpu, LIFT_CODE_TOKEN_VA(0x448E29u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0xB8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00048F26;
    if ((uint8_t)(lift_load8(cpu->ebx + 0xD4u)) == (uint8_t)(0u)) goto label_00048E50;
    lift_push32(cpu, (uint32_t)(uintptr_t)" Add ItemItem    \315\340\367\340\353\356 \321\350\355\365\360\356\355\350\347\340\366\350\350 '\302\361\345\354 \356\362 \362\345\352\363\371\345\343\356, \362\345\352\363\371\345\354\363 \356\362 \342\361\345\365'\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448E4Du)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x448E4Du));
    cpu->esp += 4u;
    label_00048E50:
    if ((uint32_t)(lift_load32(cpu->esp + 0xCu)) != (uint32_t)(0u)) goto label_00048E8D;
    if ((uint8_t)(lift_load8(cpu->ebx + 0xD4u)) == (uint8_t)(0u)) goto label_00048E71;
    cpu->edi += 4u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)" Add pItemFrom  'NOT' Found = ''%s''\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448E6Eu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x448E6Eu));
    cpu->esp += 8u;
    label_00048E71:
    cpu->eax = 0xFFFFFFEFu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00048E8D:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448E94u)); sfera_sub_0043A300(cpu, LIFT_CODE_TOKEN_VA(0x448E94u));
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != 0u) goto label_00048ED0;
    if ((uint8_t)(lift_load8(cpu->ebx + 0xD4u)) == (uint8_t)((cpu->eax & 0xFFu))) goto label_00048EAF;
    lift_push32(cpu, (uint32_t)(uintptr_t)" Add pItemTo  'NOT' Found\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448EACu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x448EACu));
    cpu->esp += 4u;
    label_00048EAF:
    cpu->eax = 0xFFFFFFF0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00048ED0:
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->eax)) goto label_00048EE8;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    reinterpret_cast<CBaseManagerCommonItem*>(cpu->ecx)->handleInsert(cpu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    label_00048EE8:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    reinterpret_cast<CBaseManagerCommonItem*>(cpu->ecx)->handleInsert(cpu);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448EFBu)); sfera_sub_0043A3D0(cpu, LIFT_CODE_TOKEN_VA(0x448EFBu));
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) != 0u) goto label_00048ED0;
    if ((uint8_t)(lift_load8(cpu->ebx + 0xD4u)) == (uint8_t)((cpu->eax & 0xFFu))) goto label_00048F16;
    lift_push32(cpu, (uint32_t)(uintptr_t)" Add ItemItem    \312\356\355\345\366 \321\350\355\365\360\356\355\350\347\340\366\350\350 '\302\361\345\354 \356\362 \362\345\352\363\371\345\343\356, \362\345\352\363\371\345\354\363 \356\362 \342\361\345\365'\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448F13u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x448F13u));
    cpu->esp += 4u;
    label_00048F16:
    if ((uint8_t)(lift_load8(cpu->ebx + 0xD4u)) != (uint8_t)(2u)) goto label_00048F26;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x48F26u)); sfera_sub_0043A6F0(cpu, LIFT_CODE_TOKEN_RVA(0x48F26u));
    label_00048F26:
    if ((uint32_t)(lift_load32(cpu->esi + 0xB4u)) != (uint32_t)(1u)) goto label_00048F6A;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x10u)) == (uint32_t)(0u)) goto label_00048F6A;
    cpu->ecx = 0x35u;
    cpu->edi = (uint32_t)(cpu->esp + 0x48u);
    lift_movs32(cpu, 1u);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->esi) == 0u) goto label_00048F56;
    cpu->ecx = 0x6Fu;
    cpu->edi = (uint32_t)(cpu->esp + 0x11Cu);
    lift_movs32(cpu, 1u);
    label_00048F56:
    lift_push32(cpu, 0x20u);
    cpu->ebx += 4u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x448F61u));
    cpu->esp += 0xCu;
    label_00048F6A:
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00048F83:
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFF97u)) goto label_000490ED;
    if ((uint8_t)(lift_load8(cpu->ebx + 0xD4u)) == (uint8_t)(0u)) goto label_00048FA6;
    cpu->edx = (uint32_t)(cpu->edi + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)" Added ItemItem REWRITE = ''%s''\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448FA3u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x448FA3u));
    cpu->esp += 8u;
    label_00048FA6:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448FAEu)); sfera_sub_00443680(cpu, LIFT_CODE_TOKEN_VA(0x448FAEu));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0xB8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->eax;
    lift_store32(cpu->esp + 0xCu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0004908D;
    if ((uint8_t)(lift_load8(cpu->ebx + 0xD4u)) == (uint8_t)(0u)) goto label_00048FD7;
    lift_push32(cpu, (uint32_t)(uintptr_t)" Add ItemItem    \315\340\367\340\353\356 \321\350\355\365\360\356\355\350\347\340\366\350\350 '\302\361\345\354 \356\362 \362\345\352\363\371\345\343\356, \362\345\352\363\371\345\354\363 \356\362 \342\361\345\365'\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448FD4u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x448FD4u));
    cpu->esp += 4u;
    label_00048FD7:
    if ((uint32_t)(cpu->edi) != 0u) goto label_00049015;
    if ((uint8_t)(lift_load8(cpu->ebx + 0xD4u)) == (uint8_t)(0u)) goto label_00048FF9;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->eax += 4u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)" Add pItemFrom  'NOT' Found = ''%s''\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x448FF6u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x448FF6u));
    cpu->esp += 8u;
    label_00048FF9:
    cpu->eax = 0xFFFFFFEEu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00049015:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44901Cu)); sfera_sub_0043A300(cpu, LIFT_CODE_TOKEN_VA(0x44901Cu));
    if ((uint32_t)(cpu->eax) != 0u) goto label_00049051;
    if ((uint8_t)(lift_load8(cpu->ebx + 0xD4u)) == (uint8_t)((cpu->eax & 0xFFu))) goto label_00049035;
    lift_push32(cpu, (uint32_t)(uintptr_t)" Add pItemTo  'NOT' Found\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449032u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x449032u));
    cpu->esp += 4u;
    label_00049035:
    cpu->eax = 0xFFFFFFEDu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00049051:
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    reinterpret_cast<CBaseManagerCommonItem*>(cpu->ecx)->handleInsert(cpu);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449064u)); sfera_sub_0043A3D0(cpu, LIFT_CODE_TOKEN_VA(0x449064u));
    if ((uint32_t)(cpu->eax) != 0u) goto label_00049051;
    if ((uint8_t)(lift_load8(cpu->ebx + 0xD4u)) == (uint8_t)((cpu->eax & 0xFFu))) goto label_0004907D;
    lift_push32(cpu, (uint32_t)(uintptr_t)" Add ItemItem    \312\356\355\345\366 \321\350\355\365\360\356\355\350\347\340\366\350\350 '\302\361\345\354 \356\362 \362\345\352\363\371\345\343\356, \362\345\352\363\371\345\354\363 \356\362 \342\361\345\365'\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44907Au)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x44907Au));
    cpu->esp += 4u;
    label_0004907D:
    if ((uint8_t)(lift_load8(cpu->ebx + 0xD4u)) != (uint8_t)(2u)) goto label_0004908D;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4908Du)); sfera_sub_0043A6F0(cpu, LIFT_CODE_TOKEN_RVA(0x4908Du));
    label_0004908D:
    if ((uint32_t)(lift_load32(cpu->esi + 0xB4u)) != (uint32_t)(1u)) goto label_000490D1;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x10u)) == (uint32_t)(0u)) goto label_000490D1;
    cpu->ecx = 0x35u;
    cpu->edi = (uint32_t)(cpu->esp + 0x48u);
    lift_movs32(cpu, 1u);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->esi) == 0u) goto label_000490BD;
    cpu->ecx = 0x6Fu;
    cpu->edi = (uint32_t)(cpu->esp + 0x11Cu);
    lift_movs32(cpu, 1u);
    label_000490BD:
    lift_push32(cpu, 0x20u);
    cpu->ebx += 4u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x4490C8u));
    cpu->esp += 0xCu;
    label_000490D1:
    cpu->eax = 0xFFFFFF97u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000490ED:
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFECu)) goto label_00049127;
    if ((uint8_t)(lift_load8(cpu->ebx + 0xD4u)) == (uint8_t)(0u)) goto label_00049166;
    cpu->edi += 4u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)" Add ItemItem  'ERROR' ER_ITEM_MEMORY_NOT_ALLOC = ''%s''\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449109u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x449109u));
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00049127:
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFDu)) goto label_00049166;
    if ((uint8_t)(lift_load8(cpu->ebx + 0xD4u)) == (uint8_t)(0u)) goto label_00049166;
    cpu->edi += 4u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)" Add ItemItem  'ERROR' ER_ITEM_NOT_ADDED = ''%s''\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449143u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x449143u));
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00049161:
    cpu->eax = 0xFFFFFFF1u;
    label_00049166:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00449180(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1B0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x1C4u);
    (void)0; /* source SEH registration eliminated */
    lift_native_call(cpu, native_function_address32(&::timeGetTime), LIFT_CODE_TOKEN_VA(0x4491BBu));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::srand), LIFT_CODE_TOKEN_VA(0x4491C2u));
    cpu->esp += 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4491D0u)); sfera_sub_00434840(cpu, LIFT_CODE_TOKEN_VA(0x4491D0u));
    lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->startup_option[0]); lift_push32(cpu, (uintptr_t)" %s"); lift_push32(cpu, (uintptr_t)&g_sfera_startup_command_line_runtime.text[0]);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4491DFu));
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"-r"); lift_push32(cpu, (uintptr_t)&g_sfera_mbc_runtime->startup_option[0]);
    lift_native_call(cpu, native_function_address32(&::_strnicmp), LIFT_CODE_TOKEN_VA(0x4491F1u));
    cpu->esp += 0x18u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00049208;
    g_sfera_inter_scalar_runtime.state_06 = (uint32_t)(1u);
    label_00049208:
    cpu->edx = 0xFECu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449217u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x449217u));
    cpu->ecx = g_sfera_inter_scalar_runtime.state_05;
    cpu->ebx = 0u;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00049233;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44922Au)); sfera_sub_0041F080(cpu, LIFT_CODE_TOKEN_VA(0x44922Au));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449230u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x449230u));
    cpu->esp += 4u;
    label_00049233:
    cpu->edx = 0xFEDu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449242u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x449242u));
    lift_push32(cpu, 0x37BCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44924Cu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x44924Cu));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x1CCu, cpu->ebx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00049267;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449265u)); sfera_sub_0041F050(cpu, LIFT_CODE_TOKEN_VA(0x449265u));
    goto label_00049269;
    label_00049267:
    cpu->eax = 0u;
    label_00049269:
    cpu->ebp |= 0xFFFFFFFFu;
    lift_store32(cpu->esp + 0x1CCu, cpu->ebp);
    g_sfera_inter_scalar_runtime.state_05 = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44927Du)); sfera_sub_00443990(cpu, LIFT_CODE_TOKEN_VA(0x44927Du));
    cpu->edx = 0xFFBu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44928Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x44928Cu));
    cpu->ecx = g_sfera_inter_scalar_runtime.state_03;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000492A6;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44929Du)); sfera_sub_00489D50(cpu, LIFT_CODE_TOKEN_VA(0x44929Du));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4492A3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4492A3u));
    cpu->esp += 4u;
    label_000492A6:
    cpu->edx = 0xFFFu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4492B5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4492B5u));
    lift_push32(cpu, 0x20C9Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4492BFu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4492BFu));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x1CCu, 1u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000492E3;
    lift_push32(cpu, (uint32_t)(uintptr_t)"mbc\\");
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4492E1u)); sfera_sub_00489F30(cpu, LIFT_CODE_TOKEN_VA(0x4492E1u));
    goto label_000492E5;
    label_000492E3:
    cpu->eax = 0u;
    label_000492E5:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"__debug.mbc");
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x1D4u, cpu->ebp);
    g_sfera_inter_scalar_runtime.state_03 = (uint32_t)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4492FEu)); sfera_sub_00489DE0(cpu, LIFT_CODE_TOKEN_VA(0x4492FEu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449303u)); sfera_sub_00433960(cpu, LIFT_CODE_TOKEN_VA(0x449303u));
    g_sfera_mbc_runtime->process_chain_first = (uint32_t)(cpu->ebp);
    g_sfera_mbc_runtime->process_chain_last = (uint32_t)(cpu->ebp);
    g_sfera_mbc_runtime->execution_chain_tail = (uint32_t)(cpu->ebp);
    g_sfera_mbc_runtime->execution_chain_head = (uint32_t)(cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449320u)); sfera_sub_004384F0(cpu, LIFT_CODE_TOKEN_VA(0x449320u));
    cpu->esi = 0u;
    label_00049322:
    cpu->edi = cpu->esi;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x348u);
    lift_push32(cpu, 0xFCu);
    cpu->eax = (uint32_t)(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].execution_scratch[0]));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index), cpu->esi);
    lift_store32(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_next_index), cpu->esi);
    lift_store32(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].execution_next_index), cpu->esi);
    lift_store32(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].execution_prev_index), cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x44934Fu));
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_00049372;
    lift_push32(cpu, 0x1015u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp"); lift_push32(cpu, (uintptr_t)"Unloading _main: %s:%d\n");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44936Fu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x44936Fu));
    cpu->esp += 0xCu;
    label_00049372:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449379u)); sfera_sub_00435D40(cpu, LIFT_CODE_TOKEN_VA(0x449379u));
    ++cpu->esi;
    lift_store32(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id), cpu->ebp);
    if ((uint32_t)(cpu->esi) < (uint32_t)(0x10000u)) goto label_00049322;
    cpu->esi = 1u;
    lift_push32(cpu, (uint32_t)(uintptr_t)"");
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_config_text_runtime.parser_path[0];
    g_sfera_mbc_runtime->process_search_cursor = (uint32_t)(cpu->ebx);
    g_sfera_mbc_runtime->process_chain_first = (uint32_t)(cpu->ebx);
    g_sfera_mbc_runtime->process_chain_last = (uint32_t)(cpu->ebx);
    g_sfera_inter_scalar_runtime.state_01 = (uint32_t)(cpu->ebx);
    g_sfera_inter_scalar_runtime.state_02 = (uint32_t)(cpu->ebx);
    g_sfera_network_runtime.active_slot = (uint32_t)(cpu->ebp);
    g_sfera_recovered_static_runtime.simulation_tick = (uint32_t)(cpu->ebx);
    g_sfera_inter_scalar_runtime.mode_01 = (uint32_t)(0x442800u);
    lift_store8((uintptr_t)&g_sfera_mbc_static_runtime.init_flag, cpu->ebx & 0xFFu);
    lift_store32((uintptr_t)&g_sfera_mbc_static_runtime.init_marker, cpu->esi);
    g_sfera_mbc_runtime->halt_all_requested = (uint32_t)(cpu->ebx);
    g_sfera_world_objects.controlled_object_handle = (uint32_t)(cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4493E8u)); sfera_sub_00401570(cpu, LIFT_CODE_TOKEN_VA(0x4493E8u));
    g_sfera_texture_cache_runtime.render_gate = (uint32_t)(cpu->ebx);
    cpu->eax = 0u;
    label_000493F0:
    lift_store32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_world_slot_table_runtime.slots[0].state), 4u);
    cpu->eax += 0x398u;
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x59D80u)) goto label_000493F0;
    lift_push32(cpu, 0x190u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&g_sfera_world_slot_table_runtime.slots[400].primary_payload[0]);
    g_sfera_world_slot_table_runtime.active_limit = (uint32_t)(0x190u);
    lift_store32((uintptr_t)&g_sfera_world_slot_table_runtime.slots[400].primary_state, cpu->ebp);
    lift_store32((uintptr_t)&g_sfera_world_slot_table_runtime.slots[400].state, 2u);
    lift_store32((uintptr_t)&g_sfera_world_slot_table_runtime.slots[400].object_handle, cpu->esi);
    lift_store32((uintptr_t)&g_sfera_world_slot_table_runtime.slots[400].primary_flags, cpu->ebx);
    lift_store32((uintptr_t)&g_sfera_world_slot_table_runtime.slots[400].secondary_flags, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x44943Du));
    lift_push32(cpu, 0x190u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)&g_sfera_world_slot_table_runtime.slots[400].secondary_payload[0]);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x44944Du));
    cpu->esp += 0x18u;
    lift_store32((uintptr_t)&g_sfera_world_slot_table_runtime.slots[400].secondary_state, cpu->ebp);
    lift_store32((uintptr_t)&g_sfera_world_slot_table_runtime.slots[400].record_state, cpu->ebp);
    cpu->eax = 0u;
    label_00049470:
    lift_store8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0]), cpu->ebx & 0xFFu);
    cpu->eax += 0x8D8u;
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x8D8000u)) goto label_00049470;
    cpu->ecx = lift_load32((uintptr_t)"mbc\\*.mbc");
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"mbc\\*.mbc") + 4u);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(lift_load16(((uint32_t)(uintptr_t)"mbc\\*.mbc") + 8u)) & 0xFFFFu);
    lift_store32(cpu->esp + 0x140u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x144u, cpu->edx);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x144u);
    lift_push32(cpu, cpu->edx);
    lift_store16(cpu->esp + 0x150u, cpu->eax & 0xFFFFu);
    lift_native_call(cpu, native_function_address32(&::_findfirst64i32), LIFT_CODE_TOKEN_VA(0x4494B7u));
    cpu->ebp = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(0xFFFFFFFFu)) goto label_000495BE;
    label_000494D0:
    if ((uint8_t)((lift_load8(cpu->esp + 0x18u)) & (0x10u)) != 0u) goto label_000495A7;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4494E6u)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x4494E6u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = 0x14u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4494F5u)); sfera_sub_0042F0E0(cpu, LIFT_CODE_TOKEN_VA(0x4494F5u));
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449502u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x449502u));
    if ((uint32_t)(lift_load32(cpu->esp + 0x14u)) != (uint32_t)(cpu->ebx)) goto label_0004951F;
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Null tag %s"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44951Cu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44951Cu));
    cpu->esp += 0xCu;
    label_0004951F:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449526u)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x449526u));
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(0xFFFu)) goto label_00049552;
    cpu->ecx = cpu->edx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x8D8u);
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    cpu->esi = cpu->eax;
    cpu->ecx -= cpu->esi;
    cpu->esi = (uint32_t)(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0]));
    label_00049548:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->esi + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00049548;
    label_00049552:
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x8D8u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0]));
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_00049561:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00049561;
    cpu->eax -= cpu->edi;
    --cpu->eax;
    if ((uint8_t)(lift_load8(cpu->edx + cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0]))) == (uint8_t)(0x5Cu)) goto label_00049596;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx + cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0]))) & 0xFFu);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00049580:
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0x2Eu)) goto label_00049596;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_00049596;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx + cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0] - 1u))) & 0xFFu);
    --cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x5Cu)) goto label_00049580;
    label_00049596:
    if ((uint8_t)(lift_load8(cpu->edx + cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0]))) != (uint8_t)(0x2Eu)) goto label_000495A7;
    lift_store8(cpu->edx + cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_interpreter_storage.module_records[0]), cpu->ebx & 0xFFu);
    label_000495A7:
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_findnext64i32), LIFT_CODE_TOKEN_VA(0x4495ADu));
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000494D0;
    label_000495BE:
    lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x4495BFu));
    cpu->esp += 4u;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.mbc_service_object[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4495D2u)); sfera_sub_00422000(cpu, LIFT_CODE_TOKEN_VA(0x4495D2u));
    cpu->ecx = (uint32_t)(uintptr_t)"connectn.cfg";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4495DCu)); sfera_sub_004483B0(cpu, LIFT_CODE_TOKEN_VA(0x4495DCu));
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_network_runtime.server_port;
    cpu->ecx = (uint32_t)(uintptr_t)"PORT";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4495EBu)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x4495EBu));
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"_main";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4495F7u)); sfera_sub_00435230(cpu, LIFT_CODE_TOKEN_VA(0x4495F7u));
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_00049606;
    cpu->ecx = (uint32_t)(uintptr_t)"MBInter: Process '_main' not found";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x49606u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x49606u));
    label_00049606:
    for (uint32_t opcode = 0u; opcode < 0x100u; ++opcode) {
        g_sfera_mbc_runtime->opcode_handlers[opcode] = LIFT_FUNCTION(sfera_mbinter_handler_function(opcode));
    }
    cpu->edi = 0u;
    if ((uint32_t)(g_sfera_mbc_runtime->named_vector_count) <= (uint32_t)(cpu->ebx)) goto label_00049693;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->named_vectors[0];
    label_00049656:
    if ((uint32_t)(lift_load32(cpu->esi + 0xCu)) == (uint32_t)(cpu->ebx)) goto label_00049687;
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00049670;
    lift_push32(cpu, 0x1084u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x49670u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_RVA(0x49670u));
    label_00049670:
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, 0x1086u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp";
    lift_store32(cpu->esi, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449684u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x449684u));
    lift_store32(cpu->esi + 4u, cpu->ebx);
    label_00049687:
    ++cpu->edi;
    cpu->esi += 0x10u;
    if ((uint32_t)(cpu->edi) < (uint32_t)(g_sfera_mbc_runtime->named_vector_count)) goto label_00049656;
    label_00049693:
    lift_push32(cpu, cpu->ebx);
    g_sfera_mbc_runtime->named_vector_count = (uint32_t)(cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x44969Au));
    cpu->esp += 4u;
    lift_store32((uintptr_t)&g_sfera_mbc_static_runtime.startup_time.low, cpu->eax);
    lift_store32((uintptr_t)&g_sfera_mbc_static_runtime.startup_time.high, cpu->edx);
    g_sfera_network_runtime.pending_slot = (uint32_t)(0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4496BDu)); sfera_sub_00433E70(cpu, LIFT_CODE_TOKEN_VA(0x4496BDu));
    cpu->ecx = lift_load32(cpu->esp + 0x1C4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1BCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004496F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = 1u;
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->trace_steps_remaining) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_00049720;
    g_sfera_mbc_runtime->trace_steps_remaining -= cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)"-------------------------------------- ";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449715u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x449715u));
    cpu->ecx = g_sfera_mbc_runtime->trace_steps_remaining;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x49720u)); sfera_sub_0044BEC0(cpu, LIFT_CODE_TOKEN_RVA(0x49720u));
    label_00049720:
    cpu->ebp = 2u;
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.mbc_service_object[0];
    lift_store8((uintptr_t)&g_sfera_mbc_static_runtime.service_flag, cpu->ebx & 0xFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449736u)); sfera_sub_004223E0(cpu, LIFT_CODE_TOKEN_VA(0x449736u));
    if ((int32_t)(uint32_t)(g_sfera_network_runtime.active_slot) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_00049EE3;
    cpu->eax = g_sfera_interpreter_scratch_runtime.network_poll_counter;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_recovered_static_runtime.simulation_tick, (uint64_t)(g_sfera_recovered_static_runtime.simulation_tick) + (uint64_t)(cpu->esi) + (uint64_t)(0u));
    cpu->eax += cpu->esi;
    g_sfera_interpreter_scratch_runtime.network_poll_counter = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0xC0u)) goto label_00049776;
    if ((uint8_t)((*(uint8_t*)(void*)&g_sfera_client_config_runtime.connect_type_enabled)) != (uint8_t)(1u)) goto label_0004976B;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449769u)); sfera_sub_00431A00(cpu, LIFT_CODE_TOKEN_VA(0x449769u));
    goto label_00049770;
    label_0004976B:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x49770u)); sfera_sub_00431980(cpu, LIFT_CODE_TOKEN_RVA(0x49770u));
    label_00049770:
    g_sfera_interpreter_scratch_runtime.network_poll_counter = (uint32_t)(cpu->ebx);
    label_00049776:
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->halt_all_requested), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000497E7;
    cpu->esi = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0];
    label_00049783:
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + (uint32_t)offsetof(SferaMbcProcessRecord, chain_prev_index))), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000497D3;
    g_sfera_mbc_runtime->active_process = (uint32_t)(cpu->esi);
    cpu->eax = 0x7Cu;
    label_000497A0:
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->ecx |= 0xFFFFFFFFu;
    lift_store16(cpu->eax + cpu->edx + 0xFFFFFFF8u, cpu->ecx & 0xFFFFu);
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->ecx |= cpu->ecx;
    lift_store16(cpu->eax + cpu->edx, cpu->ecx & 0xFFFFu);
    cpu->eax += cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x84u)) goto label_000497A0;
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    cpu->edx = (uint32_t)(uintptr_t)"EPHalt";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x497D3u)); sfera_sub_00435020(cpu, LIFT_CODE_TOKEN_RVA(0x497D3u));
    label_000497D3:
    cpu->esi += 0x348u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[65536])), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00049783;
    g_sfera_mbc_runtime->halt_all_requested = (uint32_t)(cpu->ebp);
    label_000497E7:
    lift_push32(cpu, cpu->edi);
    cpu->edi = g_sfera_recovered_static_runtime.simulation_tick;
    cpu->eax = 0x2AAAAAABu;
    lift_multiply_accumulator(cpu, cpu->edi, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->ecx = cpu->edi;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00049816;
    cpu->edi = cpu->ebp;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    goto label_0004982C;
    label_00049816:
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0x80000007u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00049823;
    --cpu->edi;
    cpu->edi |= 0xFFFFFFF8u;
    ++cpu->edi;
    label_00049823:
    { uint64_t x=(uint64_t)(cpu->edi), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->edi = v; }
    cpu->edi = (uint64_t)(cpu->edi) - (uint64_t)(cpu->edi) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    ++cpu->edi;
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    label_0004982C:
    cpu->eax = g_sfera_recovered_static_runtime.graphics_state;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00049844;
    g_sfera_inter_scalar_runtime.state_02 = (uint32_t)(cpu->eax);
    g_sfera_inter_scalar_runtime.state_01 = (uint32_t)(1u);
    label_00049844:
    cpu->eax = g_sfera_mbc_runtime->execution_chain_tail;
    cpu->ecx = cpu->eax;
    g_sfera_mbc_runtime->process_index = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->dispatch_process_count = (uint32_t)(cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ebx)) goto label_00049D94;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].chain_prev_index))) < (int32_t)(uint32_t)(cpu->ebx)) goto label_00049D94;
    goto label_0004988A;
    label_00049880:
    cpu->ecx = g_sfera_mbc_runtime->process_index;
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    label_0004988A:
    ++g_sfera_mbc_runtime->dispatch_process_count;
    cpu->eax = cpu->ecx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0]));
    g_sfera_mbc_runtime->trace_process_header_pending = (uint8_t)(1u);
    g_sfera_network_runtime.active_slot = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->active_process = (uint32_t)(cpu->edx);
    cpu->esi = lift_load32(cpu->edx + (uint32_t)offsetof(SferaMbcProcessRecord, program_table_base));
    g_sfera_mbc_runtime->program_table_base = (uint32_t)(cpu->esi);
    cpu->ecx = lift_load32(cpu->edx + (uint32_t)offsetof(SferaMbcProcessRecord, bytecode_base));
    g_sfera_mbc_runtime->bytecode_base = (uint32_t)(cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx + (uint32_t)offsetof(SferaMbcProcessRecord, process_memory_base));
    g_sfera_mbc_runtime->process_memory_base = (uint32_t)(cpu->ecx);
    g_sfera_mbc_runtime->execution_context_depth = (uint32_t)(cpu->ebx);
    g_sfera_mbc_runtime->execution_failed = (uint32_t)(cpu->ebx);
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->trace_steps_remaining) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0004991E;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].module_tag))) != (uint32_t)(cpu->ebp)) goto label_0004991E;
    cpu->ecx = (uint32_t)(uintptr_t)"--- Player ---\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4498F2u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x4498F2u));
    cpu->edx = g_sfera_mbc_runtime->process_index;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"ID=%d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44990Fu)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x44990Fu));
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->esi = g_sfera_mbc_runtime->program_table_base;
    cpu->esp += 8u;
    label_0004991E:
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->ebx)) goto label_00049CF9;
    cpu->edi = 0x7Cu;
    (void)cpu;
    label_00049930:
    cpu->ecx = (int16_t)(lift_load16(cpu->edx + cpu->edi + 0xFFFFFFF8u));
    g_sfera_mbc_runtime->program_index = (uint32_t)(cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->ebx)) goto label_00049CE4;
    label_00049943:
    cpu->eax = cpu->ecx;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    cpu->eax += cpu->esi;
    g_sfera_mbc_runtime->trace_program_header_pending = (uint8_t)(1u);
    g_sfera_mbc_runtime->active_program_record = (uint32_t)(cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    if ((int8_t)(uint8_t)(lift_load8(cpu->eax + 0x2Cu)) <= (int8_t)(uint8_t)((cpu->ebx & 0xFFu))) goto label_00049C34;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ebx);
    g_sfera_mbc_runtime->call_frame_depth = (uint32_t)(cpu->ebx);
    g_sfera_mbc_runtime->instruction_step_count = (uint32_t)(cpu->ebx);
    label_00049980:
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xA4u);
    cpu->ecx = lift_load32(cpu->ecx + cpu->esi + 0x98u);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->ebx)) goto label_00049AFA;
    cpu->edx = cpu->ecx;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xA4u);
    if ((int8_t)(uint8_t)(lift_load8(cpu->edx + cpu->esi + 0x2Cu)) > (int8_t)(uint8_t)((cpu->ebx & 0xFFu))) goto label_00049980;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xA4u);
    if ((int8_t)(uint8_t)(lift_load8(cpu->ecx + cpu->esi + 0x2Cu)) >= (int8_t)(uint8_t)((cpu->ebx & 0xFFu))) goto label_00049C11;
    cpu->eax = lift_load32(cpu->eax + 0x28u);
    label_000499B6:
    cpu->eax += g_sfera_mbc_runtime->bytecode_base;
    g_sfera_mbc_runtime->instruction_cursor = (uint32_t)(cpu->eax);
    label_000499C1:
    cpu->ecx = g_sfera_mbc_runtime->instruction_step_count;
    cpu->edx = cpu->ecx;
    ++cpu->ecx;
    g_sfera_mbc_runtime->instruction_step_count = (uint32_t)(cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->edx) > (int32_t)(uint32_t)(0x3567E0u)) goto label_00049DB2;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    g_sfera_mbc_runtime->current_opcode = (uint8_t)((cpu->ecx & 0xFFu));
    g_sfera_mbc_runtime->current_instruction_address = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(g_sfera_mbc_runtime->trace_steps_remaining) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_00049A9E;
    cpu->edx = g_sfera_mbc_runtime->process_index;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x348u);
    if ((uint32_t)(lift_load32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].module_tag))) != (uint32_t)(cpu->ebp)) goto label_00049A9E;
    if ((uint8_t)(g_sfera_mbc_runtime->trace_program_header_pending) != (uint8_t)(1u)) goto label_00049A9E;
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->trace_process_header_pending), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    g_sfera_mbc_runtime->trace_program_header_pending = (uint8_t)((cpu->ebx & 0xFFu));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00049A63;
    cpu->ecx = (uint32_t)(uintptr_t)"=== Player ===\n";
    g_sfera_mbc_runtime->trace_process_header_pending = (uint8_t)((cpu->ebx & 0xFFu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449A39u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x449A39u));
    cpu->eax = g_sfera_mbc_runtime->process_index;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x348u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0].process_id));
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"ID=%d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449A55u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x449A55u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(g_sfera_mbc_runtime->current_opcode) & 0xFFu);
    cpu->eax = g_sfera_mbc_runtime->current_instruction_address;
    cpu->esp += 8u;
    label_00049A63:
    if ((int32_t)(uint32_t)(g_sfera_network_runtime.active_slot) < (int32_t)(uint32_t)(cpu->ebx)) goto label_00049A9E;
    cpu->ecx = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449A75u)); sfera_sub_00434AF0(cpu, LIFT_CODE_TOKEN_VA(0x449A75u));
    cpu->ecx = (uint32_t)(uintptr_t)"\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449A7Fu)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x449A7Fu));
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449A89u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x449A89u));
    cpu->ecx = (uint32_t)(uintptr_t)"\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449A93u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x449A93u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(g_sfera_mbc_runtime->current_opcode) & 0xFFu);
    cpu->eax = g_sfera_mbc_runtime->current_instruction_address;
    label_00049A9E:
    cpu->edx = g_sfera_interpreter_scratch_runtime.diagnostic_step_counter;
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(0x3E8u)) goto label_00049ACE;
    cpu->eax -= g_sfera_mbc_runtime->bytecode_base;
    cpu->edx = g_sfera_mbc_runtime->process_index;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449ABFu)); sfera_sub_00421710(cpu, LIFT_CODE_TOKEN_VA(0x449ABFu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449AC6u)); sfera_sub_00421720(cpu, LIFT_CODE_TOKEN_VA(0x449AC6u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(g_sfera_mbc_runtime->current_opcode) & 0xFFu);
    cpu->edx = 0u;
    label_00049ACE:
    cpu->esi = 1u;
    cpu->edx += cpu->esi;
    g_sfera_interpreter_scratch_runtime.diagnostic_step_counter = (uint32_t)(cpu->edx);
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x30u)) goto label_00049B05;
    cpu->eax = g_sfera_mbc_runtime->call_frame_depth;
    cpu->ecx = g_sfera_mbc_runtime->frame_stack_base[cpu->eax];
    g_sfera_mbc_runtime->instruction_cursor += cpu->esi;
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    goto label_00049B21;
    label_00049AFA:
    cpu->eax = lift_load32(cpu->eax + 0x88u);
    goto label_000499B6;
    label_00049B05:
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0x7Cu)) goto label_00049B37;
    if ((uint8_t)((cpu->ecx & 0xFFu)) == (uint8_t)(0x23u)) goto label_00049B42;
    g_sfera_mbc_runtime->instruction_cursor += cpu->esi;
    cpu->edx = cpu->ecx & 0xFFu;
    cpu->eax = g_sfera_mbc_runtime->opcode_handlers[cpu->edx];
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x49B21u), LIFT_CODE_TOKEN_RVA(0x49B1Fu))) { return; }
    label_00049B21:
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(cpu->ebx)) goto label_00049D07;
    cpu->eax = g_sfera_mbc_runtime->instruction_cursor;
    goto label_000499C1;
    label_00049B37:
    g_sfera_mbc_runtime->instruction_cursor += cpu->esi;
    goto label_00049C0C;
    label_00049B42:
    cpu->ecx = g_sfera_mbc_runtime->active_program_record;
    lift_store8(cpu->ecx + 0x84u, cpu->ebx & 0xFFu);
    cpu->edx = g_sfera_mbc_runtime->active_program_record;
    lift_store8(cpu->edx + 0x2Cu, 0xFFu);
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->ecx = (int16_t)(lift_load16(cpu->edi + cpu->eax));
    cpu->edx = g_sfera_mbc_runtime->program_index;
    g_sfera_mbc_runtime->pending_program_index = (uint32_t)(cpu->ecx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->ecx)) goto label_00049C59;
    cpu->ecx = (int16_t)(lift_load16(cpu->eax + cpu->edi + 0xFFFFFFF8u));
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->ecx)) goto label_00049BBE;
    cpu->edx = g_sfera_mbc_runtime->active_program_record;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->edx + 0x9Eu)) & 0xFFFFu);
    lift_store16(cpu->eax + cpu->edi + 0xFFFFFFF8u, cpu->ecx & 0xFFFFu);
    cpu->edx = g_sfera_mbc_runtime->active_program_record;
    cpu->eax = (int16_t)(lift_load16(cpu->edx + 0x9Eu));
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xA4u);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->ecx + cpu->edi + 0xFFFFFFF8u)) & 0xFFFFu);
    cpu->ecx = g_sfera_mbc_runtime->program_table_base;
    lift_store16(cpu->eax + cpu->ecx + 0x9Cu, cpu->edx & 0xFFFFu);
    goto label_00049C0C;
    label_00049BBE:
    cpu->eax = g_sfera_mbc_runtime->active_program_record;
    cpu->edx = (int16_t)(lift_load16(cpu->eax + 0x9Eu));
    cpu->eax = lift_load16(cpu->eax + 0x9Cu);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xA4u);
    cpu->ecx = g_sfera_mbc_runtime->program_table_base;
    lift_store16(cpu->edx + cpu->ecx + 0x9Cu, cpu->eax & 0xFFFFu);
    cpu->eax = g_sfera_mbc_runtime->active_program_record;
    cpu->edx = (int16_t)(lift_load16(cpu->eax + 0x9Cu));
    cpu->eax = lift_load16(cpu->eax + 0x9Eu);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xA4u);
    cpu->ecx = g_sfera_mbc_runtime->program_table_base;
    lift_store16(cpu->edx + cpu->ecx + 0x9Eu, cpu->eax & 0xFFFFu);
    label_00049C0C:
    cpu->eax = g_sfera_mbc_runtime->active_program_record;
    label_00049C11:
    cpu->ecx = g_sfera_mbc_runtime->instruction_cursor;
    cpu->ecx -= g_sfera_mbc_runtime->bytecode_base;
    lift_store32(cpu->eax + 0x88u, cpu->ecx);
    cpu->edx = g_sfera_mbc_runtime->active_process;
    cpu->esi = g_sfera_mbc_runtime->program_table_base;
    cpu->eax = g_sfera_mbc_runtime->active_program_record;
    label_00049C34:
    cpu->ecx = (int16_t)(lift_load16(cpu->eax + 0x9Eu));
    g_sfera_mbc_runtime->program_index = (uint32_t)(cpu->ecx);
    cpu->eax = (int16_t)(lift_load16(cpu->edi + cpu->edx));
    cpu->ebp = 2u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) == (uint32_t)(cpu->eax)) goto label_00049CE4;
    goto label_00049943;
    label_00049C59:
    cpu->edx = (int16_t)(lift_load16(cpu->eax + cpu->edi + 0xFFFFFFF8u));
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_00049CA6;
    cpu->ecx |= 0xFFFFFFFFu;
    lift_store16(cpu->eax + cpu->edi + 0xFFFFFFF8u, cpu->ecx & 0xFFFFu);
    cpu->eax = g_sfera_mbc_runtime->active_process;
    cpu->edx |= cpu->ecx;
    lift_store16(cpu->edi + cpu->eax, cpu->edx & 0xFFFFu);
    cpu->edx = g_sfera_mbc_runtime->active_process;
    { uint64_t l=(uint64_t)(lift_load16(cpu->edx + (uint32_t)offsetof(SferaMbcProcessRecord, program_map_a))), r=(uint64_t)((cpu->ebx & 0xFFFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,16u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_00049CDE;
    { uint64_t l=(uint64_t)(lift_load16(cpu->edx + (uint32_t)offsetof(SferaMbcProcessRecord, program_map_a) + 2u)), r=(uint64_t)((cpu->ebx & 0xFFFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,16u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_00049CDE;
    { uint64_t l=(uint64_t)(lift_load16(cpu->edx + (uint32_t)offsetof(SferaMbcProcessRecord, program_map_a) + 4u)), r=(uint64_t)((cpu->ebx & 0xFFFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,16u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_00049CDE;
    cpu->ecx = g_sfera_mbc_runtime->process_index;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449C98u)); sfera_sub_00433DA0(cpu, LIFT_CODE_TOKEN_VA(0x449C98u));
    cpu->ecx = g_sfera_mbc_runtime->active_process;
    lift_store8(cpu->ecx + (uint32_t)offsetof(SferaMbcProcessRecord, state_byte_b8), cpu->ebx & 0xFFu);
    goto label_00049CD8;
    label_00049CA6:
    cpu->edx = g_sfera_mbc_runtime->active_program_record;
    cpu->ecx = (int16_t)(lift_load16(cpu->edx + 0x9Cu));
    g_sfera_mbc_runtime->pending_program_index = (uint32_t)(cpu->ecx);
    lift_store16(cpu->edi + cpu->eax, cpu->ecx & 0xFFFFu);
    cpu->eax = g_sfera_mbc_runtime->pending_program_index;
    cpu->edx = g_sfera_mbc_runtime->program_table_base;
    cpu->ecx = cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xA4u);
    lift_store16(cpu->ecx + cpu->edx + 0x9Eu, cpu->eax & 0xFFFFu);
    label_00049CD8:
    cpu->edx = g_sfera_mbc_runtime->active_process;
    label_00049CDE:
    cpu->esi = g_sfera_mbc_runtime->program_table_base;
    label_00049CE4:
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    ++cpu->eax;
    cpu->edi += cpu->ebp;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x10u))) goto label_00049930;
    label_00049CF9:
    { uint64_t l=(uint64_t)(lift_load8(cpu->edx + (uint32_t)offsetof(SferaMbcProcessRecord, flags))), r=(uint64_t)(4u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00049D71;
    label_00049D02:
    cpu->esi = 1u;
    label_00049D07:
    if ((uint32_t)(g_sfera_mbc_runtime->process_index) != (uint32_t)(cpu->ebx)) goto label_00049D53;
    lift_push32(cpu, 0x12CCu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Inter.cpp"); lift_push32(cpu, (uintptr_t)"Unloading _main: %s:%d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449D23u)); sfera_sub_0044BF90(cpu, LIFT_CODE_TOKEN_VA(0x449D23u));
    cpu->esp += 0xCu;
    if ((int32_t)(uint32_t)(g_sfera_network_runtime.active_slot) < (int32_t)(uint32_t)(cpu->ebx)) goto label_00049D53;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449D35u)); sfera_sub_00434AF0(cpu, LIFT_CODE_TOKEN_VA(0x449D35u));
    cpu->ecx = (uint32_t)(uintptr_t)"\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449D3Fu)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x449D3Fu));
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449D49u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x449D49u));
    cpu->ecx = (uint32_t)(uintptr_t)"\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x49D53u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_RVA(0x49D53u));
    label_00049D53:
    cpu->ecx = g_sfera_mbc_runtime->process_index;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449D5Eu)); sfera_sub_00435D40(cpu, LIFT_CODE_TOKEN_VA(0x449D5Eu));
    cpu->eax = g_sfera_mbc_runtime->process_index;
    if ((uint32_t)(cpu->eax) == (uint32_t)(g_sfera_mbc_runtime->process_chain_last)) goto label_00049D94;
    cpu->edx = g_sfera_mbc_runtime->active_process;
    label_00049D71:
    cpu->ecx = g_sfera_network_runtime.active_slot;
    cpu->edx = lift_load32(cpu->edx + (uint32_t)offsetof(SferaMbcProcessRecord, execution_prev_index));
    g_sfera_mbc_runtime->process_index = (uint32_t)(cpu->edx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(g_sfera_mbc_runtime->execution_chain_head)) goto label_00049D94;
    if ((uint32_t)(cpu->edx) != (uint32_t)(0xFFFFFFFFu)) goto label_00049880;
    label_00049D94:
    g_sfera_network_runtime.active_slot = (uint32_t)(0xFFFFFFFFu);
    if ((uint32_t)(g_sfera_mbc_runtime->halt_all_requested) != (uint32_t)(cpu->ebp)) goto label_00049E19;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    sfera_sub_00449180(cpu, stop_address); return;
    label_00049DB2:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449DB7u)); sfera_sub_00434D90(cpu, LIFT_CODE_TOKEN_VA(0x449DB7u));
    cpu->ecx = (uint32_t)(uintptr_t)"\n---exit_inter start---\nMBINTER MESSAGE:";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449DC1u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x449DC1u));
    cpu->ecx = (uint32_t)(uintptr_t)"Endless cycle found";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449DCBu)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x449DCBu));
    cpu->ecx = (uint32_t)(uintptr_t)"\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449DD5u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x449DD5u));
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449DDFu)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x449DDFu));
    cpu->ecx = (uint32_t)(uintptr_t)"---exit_inter end-----\n";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449DE9u)); sfera_sub_0044BF50(cpu, LIFT_CODE_TOKEN_VA(0x449DE9u));
    g_sfera_mbc_runtime->execution_failed = (uint32_t)(1u);
    if ((uint32_t)(g_sfera_mbc_runtime->process_index) != (uint32_t)(cpu->ebx)) goto label_00049E05;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->diagnostic_context[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x49E05u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x49E05u));
    label_00049E05:
    cpu->edx = (uint32_t)(uintptr_t)"EError";
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_mbc_runtime->processes[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449E14u)); sfera_sub_00435020(cpu, LIFT_CODE_TOKEN_VA(0x449E14u));
    goto label_00049D02;
    label_00049E19:
    cpu->eax = g_sfera_recovered_static_runtime.simulation_tick;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_divide_accumulator(cpu, 3u, 32u, 1u);
    if ((uint32_t)(cpu->edx) != 0u) goto label_00049ED3;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449E32u)); sfera_sub_00433A80(cpu, LIFT_CODE_TOKEN_VA(0x449E32u));
    cpu->ebp = g_sfera_world_slot_table_runtime.active_limit;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(cpu->ebx)) goto label_00049ED3;
    label_00049E40:
    cpu->esi = cpu->ebp;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x398u);
    cpu->esi += ((uint32_t)(uintptr_t)&g_sfera_world_slot_table_runtime.slots[0].object_handle);
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    cpu->ebp = lift_load32(cpu->esi + 0x24u);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_00049E8B;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(7u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    lift_push32(cpu, cpu->eax);
    cpu->edi = (uint32_t)(cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->esi;
    cpu->ecx = 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449E6Fu)); sfera_sub_00432790(cpu, LIFT_CODE_TOKEN_VA(0x449E6Fu));
    lift_push32(cpu, 0x190u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esi + 0x28u, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x449E79u));
    cpu->esp += 0xCu;
    lift_store32(cpu->esi + 0x1BCu, 0xFFFFFFFFu);
    label_00049E8B:
    cpu->eax = lift_load32(cpu->esi + 0x1C0u);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_00049ECB;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(7u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    lift_push32(cpu, cpu->eax);
    cpu->edi = (uint32_t)(cpu->esi + 0x1C4u);
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->esi;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449EACu)); sfera_sub_00432790(cpu, LIFT_CODE_TOKEN_VA(0x449EACu));
    lift_push32(cpu, 0x190u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esi + 0x1C0u, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x449EB9u));
    cpu->esp += 0xCu;
    lift_store32(cpu->esi + 0x354u, 0xFFFFFFFFu);
    label_00049ECB:
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_00049E40;
    label_00049ED3:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449EDBu)); sfera_sub_00421710(cpu, LIFT_CODE_TOKEN_VA(0x449EDBu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449EE2u)); sfera_sub_00421720(cpu, LIFT_CODE_TOKEN_VA(0x449EE2u));
    cpu->edi = lift_pop32(cpu);
    label_00049EE3:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00449EF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x6D8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449F09u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x449F09u));
    --cpu->eax;
    if ((uint32_t)(cpu->eax) > (uint32_t)(0xAu)) goto label_0004A87C;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_00049F1E;
        case 1u: goto label_00049F8A;
        case 2u: goto label_00049FD0;
        case 3u: goto label_0004A0E6;
        case 4u: goto label_0004A186;
        case 5u: goto label_0004A30D;
        case 6u: goto label_0004A44A;
        case 7u: goto label_0004A5C6;
        case 8u: goto label_0004A6A1;
        case 9u: goto label_0004A767;
        case 10u: goto label_0004A871;
        default: lift_trap(cpu, 0x449F17u, "resolved jump-table index out of range"); return;
    }
label_00049F1E: ;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449F23u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x449F23u));
    cpu->esi = cpu->eax;
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449F30u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x449F30u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449F37u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x449F37u));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449F3Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x449F3Eu));
    cpu->ebp = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449F45u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x449F45u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004A878;
    lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x4E8u);
    lift_push32(cpu, (uintptr_t)"LA: '%s' "); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x449F64u));
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->esp += 0xCu;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_inter_scalar_runtime.state_07;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449F83u)); sfera_sub_00448BC0(cpu, LIFT_CODE_TOKEN_VA(0x449F83u));
    cpu->ecx = cpu->eax;
    goto label_0004A873;
    label_00049F8A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449F8Fu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x449F8Fu));
    cpu->esi = cpu->eax;
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0004A878;
    lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->esp + 0x4E8u);
    lift_push32(cpu, (uintptr_t)"LD: '%s' "); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x449FB2u));
    cpu->ecx = g_sfera_inter_scalar_runtime.state_07;
    cpu->esp += 0xCu;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449FC9u)); sfera_sub_004478E0(cpu, LIFT_CODE_TOKEN_VA(0x449FC9u));
    cpu->ecx = cpu->eax;
    goto label_0004A873;
    label_00049FD0:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449FD5u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x449FD5u));
    cpu->ebx = cpu->eax;
    cpu->ebx += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449FE2u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x449FE2u));
    cpu->esi = cpu->eax;
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449FEFu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x449FEFu));
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x449FF8u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x449FF8u));
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A001u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A001u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A00Au)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A00Au));
    cpu->edi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(0x100u)) goto label_0004A019;
    cpu->edi = 0x100u;
    label_0004A019:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A01Eu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A01Eu));
    cpu->ebp = cpu->eax;
    cpu->ebp += g_sfera_mbc_runtime->process_memory_base;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0004A878;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0x4ECu);
    lift_push32(cpu, (uintptr_t)"IA+: '%s' '%s' "); lift_push32(cpu, cpu->eax);
    std::construct_at(reinterpret_cast<CItem*>(cpu->esp + 0x2Cu));
    std::construct_at(reinterpret_cast<CCommonItem*>(cpu->esp + 0x17Cu));
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x44A055u));
    cpu->esp += 0x10u;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A068u)); sfera_sub_00433BD0(cpu, LIFT_CODE_TOKEN_VA(0x44A068u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_inter_scalar_runtime.state_07;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A078u)); sfera_sub_00443230(cpu, LIFT_CODE_TOKEN_VA(0x44A078u));
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0004A284;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x170u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A08Fu)); sfera_sub_00433BD0(cpu, LIFT_CODE_TOKEN_VA(0x44A08Fu));
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x218u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x22Cu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x224u, cpu->eax);
    lift_store32(cpu->esp + 0x228u, cpu->ecx);
    lift_store32(cpu->esp + 0x230u, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x44A0C1u));
    cpu->ecx = g_sfera_inter_scalar_runtime.state_07;
    cpu->esp += 0xCu;
    lift_push32(cpu, 1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x170u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A0DFu)); sfera_sub_00448D90(cpu, LIFT_CODE_TOKEN_VA(0x44A0DFu));
    cpu->ecx = cpu->eax;
    goto label_0004A873;
    label_0004A0E6:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A0EBu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A0EBu));
    cpu->esi = cpu->eax;
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A0F8u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A0F8u));
    cpu->edi = cpu->eax;
    cpu->edi += g_sfera_mbc_runtime->process_memory_base;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0004A878;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4ECu);
    lift_push32(cpu, (uintptr_t)"ID-: '%s' '%s' "); lift_push32(cpu, cpu->ecx);
    std::construct_at(reinterpret_cast<CItem*>(cpu->esp + 0x2Cu));
    std::construct_at(reinterpret_cast<CCommonItem*>(cpu->esp + 0x17Cu));
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x44A12Fu));
    cpu->esp += 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A142u)); sfera_sub_00433BD0(cpu, LIFT_CODE_TOKEN_VA(0x44A142u));
    cpu->ecx = g_sfera_inter_scalar_runtime.state_07;
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A152u)); sfera_sub_00443230(cpu, LIFT_CODE_TOKEN_VA(0x44A152u));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0004A284;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x170u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A169u)); sfera_sub_00433BD0(cpu, LIFT_CODE_TOKEN_VA(0x44A169u));
    cpu->ecx = g_sfera_inter_scalar_runtime.state_07;
    lift_push32(cpu, 1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x170u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A17Fu)); sfera_sub_00447A40(cpu, LIFT_CODE_TOKEN_VA(0x44A17Fu));
    cpu->ecx = cpu->eax;
    goto label_0004A873;
    label_0004A186:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A18Bu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A18Bu));
    cpu->edi = cpu->eax;
    cpu->edi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A198u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A198u));
    cpu->esi = cpu->eax;
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A1A5u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A1A5u));
    cpu->ebx = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ebx += cpu->eax;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(cpu->eax)) goto label_0004A1C4;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: list, L_FFITEM, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A1C1u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44A1C1u));
    cpu->esp += 8u;
    label_0004A1C4:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A1C9u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A1C9u));
    cpu->ecx = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->eax)) goto label_0004A1EC;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: list, L_FFITEM, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A1E9u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44A1E9u));
    cpu->esp += 8u;
    label_0004A1EC:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A1F1u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A1F1u));
    cpu->ecx = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += cpu->eax;
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->eax)) goto label_0004A214;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: list, L_FFITEM, 3\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A211u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44A211u));
    cpu->esp += 8u;
    label_0004A214:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A219u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A219u));
    cpu->ecx = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->eax)) goto label_0004A23C;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: list, L_FFITEM, 4\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A239u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44A239u));
    cpu->esp += 8u;
    label_0004A23C:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A241u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A241u));
    cpu->ebp = cpu->eax;
    cpu->ebp += g_sfera_mbc_runtime->process_memory_base;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0004A878;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    std::construct_at(reinterpret_cast<CItem*>(cpu->esp + 0x20u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A268u)); sfera_sub_00433BD0(cpu, LIFT_CODE_TOKEN_VA(0x44A268u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_inter_scalar_runtime.state_07;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A278u)); sfera_sub_00443230(cpu, LIFT_CODE_TOKEN_VA(0x44A278u));
    g_sfera_interpreter_scratch_runtime.item_lookup_result = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0004A28C;
    label_0004A281:
    lift_store8(cpu->esi, 0u);
    label_0004A284:
    cpu->ecx |= 0xFFFFFFFFu;
    goto label_0004A873;
    label_0004A28C:
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A293u)); sfera_sub_0043A300(cpu, LIFT_CODE_TOKEN_VA(0x44A293u));
    if ((uint32_t)(cpu->eax) != 0u) goto label_0004A2A4;
    label_0004A297:
    lift_store8(cpu->esi, 0u);
    label_0004A29A:
    cpu->ecx = 0xFFFFFFFEu;
    goto label_0004A873;
    label_0004A2A4:
    cpu->ecx = (uint32_t)(cpu->eax + 4u);
    cpu->esi -= cpu->ecx;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0004A2B0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->ecx + cpu->esi, cpu->edx & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0004A2B0;
    cpu->edx = lift_load32(cpu->eax + 0xA8u);
    lift_store32(cpu->ebx, cpu->edx);
    cpu->ecx = lift_load32(cpu->eax + 0xACu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->edx, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 0xB0u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->edx, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 0xB8u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->edx, cpu->ecx);
    if ((uint32_t)(cpu->ebp) == (uint32_t)(g_sfera_mbc_runtime->process_memory_base)) goto label_0004A871;
    cpu->ecx = lift_load32(cpu->eax + 0xB8u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax += 0xBCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x44A300u));
    cpu->esp += 0xCu;
    goto label_0004A871;
    label_0004A30D:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A312u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A312u));
    cpu->esi = cpu->eax;
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A31Fu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A31Fu));
    cpu->edi = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi += cpu->eax;
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->eax)) goto label_0004A33E;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: list, L_FNITEM, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A33Bu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44A33Bu));
    cpu->esp += 8u;
    label_0004A33E:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A343u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A343u));
    cpu->ecx = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->eax)) goto label_0004A366;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: list, L_FNITEM, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A363u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44A363u));
    cpu->esp += 8u;
    label_0004A366:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A36Bu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A36Bu));
    cpu->ecx = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += cpu->eax;
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->eax)) goto label_0004A38E;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: list, L_FNITEM, 3\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A38Bu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44A38Bu));
    cpu->esp += 8u;
    label_0004A38E:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A393u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A393u));
    cpu->ebp = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ebp += cpu->eax;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(cpu->eax)) goto label_0004A3B2;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: list, L_FNITEM, 4\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A3AFu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44A3AFu));
    cpu->esp += 8u;
    label_0004A3B2:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A3B7u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A3B7u));
    cpu->ebx = cpu->eax;
    cpu->ebx += g_sfera_mbc_runtime->process_memory_base;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0004A878;
    cpu->ecx = g_sfera_interpreter_scratch_runtime.item_lookup_result;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0004A281;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A3DFu)); sfera_sub_0043A3D0(cpu, LIFT_CODE_TOKEN_VA(0x44A3DFu));
    if ((uint32_t)(cpu->eax) == 0u) goto label_0004A297;
    cpu->ecx = (uint32_t)(cpu->eax + 4u);
    cpu->esi -= cpu->ecx;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0004A3F0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->ecx + cpu->esi, cpu->edx & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0004A3F0;
    cpu->edx = lift_load32(cpu->eax + 0xA8u);
    lift_store32(cpu->edi, cpu->edx);
    cpu->ecx = lift_load32(cpu->eax + 0xACu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->edx, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 0xB0u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->edx, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 0xB8u);
    lift_store32(cpu->ebp, cpu->ecx);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(g_sfera_mbc_runtime->process_memory_base)) goto label_0004A871;
    cpu->edx = lift_load32(cpu->eax + 0xB8u);
    lift_push32(cpu, cpu->edx);
    cpu->eax += 0xBCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x44A43Du));
    cpu->esp += 0xCu;
    goto label_0004A871;
    label_0004A44A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A44Fu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A44Fu));
    cpu->esi = cpu->eax;
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A45Cu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A45Cu));
    cpu->ebx = cpu->eax;
    cpu->ebx += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A469u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A469u));
    cpu->edi = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi += cpu->eax;
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->eax)) goto label_0004A488;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: list, L_FINDITEM, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A485u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44A485u));
    cpu->esp += 8u;
    label_0004A488:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A48Du)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A48Du));
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax += cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_0004A4AF;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: list, L_FINDITEM, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A4ACu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44A4ACu));
    cpu->esp += 8u;
    label_0004A4AF:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A4B4u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A4B4u));
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax += cpu->ecx;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_0004A4D6;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: list, L_FINDITEM, 3\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A4D3u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44A4D3u));
    cpu->esp += 8u;
    label_0004A4D6:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A4DBu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A4DBu));
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A4EAu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A4EAu));
    cpu->ebp = cpu->eax;
    cpu->ebp += g_sfera_mbc_runtime->process_memory_base;
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0004A878;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    std::construct_at(reinterpret_cast<CItem*>(cpu->esp + 0x20u));
    std::construct_at(reinterpret_cast<CItem*>(cpu->esp + 0xC8u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A519u)); sfera_sub_00433BD0(cpu, LIFT_CODE_TOKEN_VA(0x44A519u));
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0xC8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A526u)); sfera_sub_00433BD0(cpu, LIFT_CODE_TOKEN_VA(0x44A526u));
    cpu->ecx = g_sfera_inter_scalar_runtime.state_07;
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A536u)); sfera_sub_00443230(cpu, LIFT_CODE_TOKEN_VA(0x44A536u));
    g_sfera_interpreter_scratch_runtime.item_lookup_result = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0004A284;
    cpu->ecx = (uint32_t)(cpu->esp + 0xC4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A552u)); sfera_sub_00443680(cpu, LIFT_CODE_TOKEN_VA(0x44A552u));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0004A29A;
    cpu->edx = lift_load32(cpu->esi + 0xA8u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->edi, cpu->edx);
    cpu->eax = lift_load32(cpu->esi + 0xACu);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 0xB0u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->eax, cpu->edx);
    if ((uint32_t)(cpu->ebp) == (uint32_t)(g_sfera_mbc_runtime->process_memory_base)) goto label_0004A59B;
    cpu->ecx = lift_load32(cpu->esi + 0xB8u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0xBCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x44A593u));
    cpu->esp += 0xCu;
    label_0004A59B:
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(g_sfera_mbc_runtime->process_memory_base)) goto label_0004A5B9;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: list, L_FINDITEM, 4\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A5B6u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44A5B6u));
    cpu->esp += 8u;
    label_0004A5B9:
    cpu->eax = lift_load32(cpu->esi + 0xB8u);
    lift_store32(cpu->edi, cpu->eax);
    goto label_0004A871;
    label_0004A5C6:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A5CBu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A5CBu));
    cpu->esi = cpu->eax;
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A5D8u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A5D8u));
    cpu->eax += g_sfera_mbc_runtime->process_memory_base;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A5E7u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A5E7u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A5EEu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A5EEu));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A5F5u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A5F5u));
    { uint64_t l=(uint64_t)(g_sfera_mbc_runtime->execution_failed), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004A878;
    lift_push32(cpu, (uint32_t)(uintptr_t)"");
    cpu->ecx = (uint32_t)(cpu->esp + 0x170u);
    std::construct_at(reinterpret_cast<CCommonItem*>(cpu->esp + 0x170u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A620u)); sfera_sub_00433BD0(cpu, LIFT_CODE_TOKEN_VA(0x44A620u));
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x338u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_inter_scalar_runtime.state_07;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A637u)); sfera_sub_004432E0(cpu, LIFT_CODE_TOKEN_VA(0x44A637u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x170u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A644u)); sfera_sub_0043A290(cpu, LIFT_CODE_TOKEN_VA(0x44A644u));
    cpu->ecx = (uint32_t)(uintptr_t)"";
    cpu->eax = (uint32_t)(cpu->esp + 0x170u);
    label_0004A650:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004A670;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_0004A66C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004A670;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0004A650;
    label_0004A66C:
    cpu->eax = 0u;
    goto label_0004A675;
    label_0004A670:
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_0004A675:
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0004A687;
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    cpu->ecx |= 0xFFFFFFFFu;
    goto label_0004A873;
    label_0004A687:
    cpu->eax = (uint32_t)(cpu->esp + 0x170u);
    cpu->ecx = cpu->eax;
    cpu->edx -= cpu->ecx;
    label_0004A692:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->eax + cpu->edx, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0004A692;
    goto label_0004A871;
    label_0004A6A1:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A6A6u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A6A6u));
    cpu->esi = cpu->eax;
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A6B3u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A6B3u));
    cpu->edi = cpu->eax;
    cpu->edi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A6C0u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x44A6C0u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A6C9u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x44A6C9u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A6D2u)); sfera_sub_0043AD60(cpu, LIFT_CODE_TOKEN_VA(0x44A6D2u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0004A878;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0xC8u);
    std::construct_at(reinterpret_cast<CItem*>(cpu->esp + 0xC8u));
    std::construct_at(reinterpret_cast<CCommonItem*>(cpu->esp + 0x170u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A706u)); sfera_sub_00433BD0(cpu, LIFT_CODE_TOKEN_VA(0x44A706u));
    cpu->ecx = g_sfera_inter_scalar_runtime.state_07;
    cpu->edx = (uint32_t)(cpu->esp + 0xC4u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A719u)); sfera_sub_00443230(cpu, LIFT_CODE_TOKEN_VA(0x44A719u));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0004A284;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x170u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A730u)); sfera_sub_00433BD0(cpu, LIFT_CODE_TOKEN_VA(0x44A730u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->ecx = g_sfera_inter_scalar_runtime.state_07;
    lift_push32(cpu, 1u);
    cpu->esp -= 0xCu;
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(cpu->esp + 0x17Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A760u)); sfera_sub_00447CC0(cpu, LIFT_CODE_TOKEN_VA(0x44A760u));
    cpu->ecx = cpu->eax;
    goto label_0004A873;
    label_0004A767:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A76Cu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A76Cu));
    cpu->esi = cpu->eax;
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A779u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A779u));
    cpu->edi = cpu->eax;
    cpu->edi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A786u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A786u));
    cpu->ebx = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ebx += cpu->eax;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(cpu->eax)) goto label_0004A7A5;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: list, L_FINDITEM, 1\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A7A2u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44A7A2u));
    cpu->esp += 8u;
    label_0004A7A5:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A7AAu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A7AAu));
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax += cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_0004A7CC;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: list, L_FINDITEM, 2\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A7C9u)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44A7C9u));
    cpu->esp += 8u;
    label_0004A7CC:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A7D1u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44A7D1u));
    cpu->ebp = cpu->eax;
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->ebp += cpu->eax;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(cpu->eax)) goto label_0004A7F0;
    lift_push32(cpu, (uintptr_t)"NULL-pointer dereferencing: list, L_FINDITEM, 3\n"); lift_push32(cpu, (uintptr_t)&g_sfera_warning_log_runtime.object[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A7EDu)); sfera_sub_0049B790(cpu, LIFT_CODE_TOKEN_VA(0x44A7EDu));
    cpu->esp += 8u;
    label_0004A7F0:
    if ((uint32_t)(g_sfera_mbc_runtime->execution_failed) != (uint32_t)(0u)) goto label_0004A878;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0xC8u);
    std::construct_at(reinterpret_cast<CItem*>(cpu->esp + 0xC8u));
    std::construct_at(reinterpret_cast<CItem*>(cpu->esp + 0x20u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A816u)); sfera_sub_00433BD0(cpu, LIFT_CODE_TOKEN_VA(0x44A816u));
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A820u)); sfera_sub_00433BD0(cpu, LIFT_CODE_TOKEN_VA(0x44A820u));
    cpu->ecx = (uint32_t)(cpu->esp + 0xC4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_inter_scalar_runtime.state_07;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A833u)); sfera_sub_00443230(cpu, LIFT_CODE_TOKEN_VA(0x44A833u));
    g_sfera_interpreter_scratch_runtime.item_lookup_result = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0004A29A;
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A84Cu)); sfera_sub_00443680(cpu, LIFT_CODE_TOKEN_VA(0x44A84Cu));
    if ((uint32_t)(cpu->eax) == 0u) goto label_0004A284;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x9Cu));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store_f32(cpu->ebx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xA0u));
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xA4u));
    lift_store_f32(cpu->ebp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004A871:
    cpu->ecx = 0u;
    label_0004A873:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4A878u)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_RVA(0x4A878u));
    label_0004A878:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0004A87C:
    cpu->esp += 0x6D8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044B130(LiftCpu* cpu, uint32_t stop_address) {
    goto label_0004B130;
    label_0004A8C0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x34u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    (void)0; /* source SEH registration eliminated */
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A8F7u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x44A8F7u));
    cpu->esi = lift_load32(cpu->eax);
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_0004A909;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4A909u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x4A909u));
    label_0004A909:
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax += cpu->esi;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A919u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x44A919u));
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_0004A929;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4A929u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x4A929u));
    label_0004A929:
    cpu->ebp = g_sfera_mbc_runtime->process_memory_base;
    cpu->ebp += cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A936u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x44A936u));
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_0004A946;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4A946u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x4A946u));
    label_0004A946:
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A951u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x44A951u));
    cpu->edi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->ebx)) goto label_0004A961;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4A961u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x4A961u));
    label_0004A961:
    cpu->eax = g_sfera_mbc_runtime->process_memory_base;
    cpu->eax += cpu->edi;
    cpu->esp -= 0x1Cu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    cpu->eax = cpu->esi;
    lift_store32(cpu->ecx + 0x14u, 0xFu);
    lift_store32(cpu->ecx + 0x10u, cpu->ebx);
    lift_store32(cpu->esp + 0x38u, cpu->esp);
    lift_store8(cpu->ecx, cpu->ebx & 0xFFu);
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_0004A986:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0004A986;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A996u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x44A996u));
    cpu->esp -= 0x1Cu;
    cpu->ecx = cpu->esp;
    cpu->edi = 0xFu;
    cpu->eax = cpu->ebp;
    lift_store32(cpu->ecx + 0x14u, cpu->edi);
    lift_store32(cpu->ecx + 0x10u, cpu->ebx);
    lift_store32(cpu->esp + 0x88u, cpu->ebx);
    lift_store32(cpu->esp + 0x5Cu, cpu->esp);
    lift_store8(cpu->ecx, cpu->ebx & 0xFFu);
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_0004A9B8:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0004A9B8;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44A9C8u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x44A9C8u));
    cpu->ebp = lift_load32(cpu->esp + 0x4Cu);
    cpu->esp -= 0x1Cu;
    cpu->ecx = cpu->esp;
    cpu->eax = cpu->ebp;
    lift_store32(cpu->ecx + 0x14u, cpu->edi);
    lift_store32(cpu->ecx + 0x10u, cpu->ebx);
    lift_store8(cpu->esp + 0xA4u, 1u);
    lift_store32(cpu->esp + 0x74u, cpu->esp);
    lift_store8(cpu->ecx, cpu->ebx & 0xFFu);
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0004A9F0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0004A9F0;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AA00u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x44AA00u));
    cpu->ebp |= 0xFFFFFFFFu;
    cpu->ecx = (uint32_t)(cpu->esp + 0x7Cu);
    lift_store32(cpu->esp + 0xA4u, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AA13u)); sfera_sub_00492B40(cpu, LIFT_CODE_TOKEN_VA(0x44AA13u));
    cpu->esi = 0x10u;
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->esi)) goto label_0004AA1F;
    cpu->eax = lift_load32(cpu->eax);
    label_0004AA1F:
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->edx -= cpu->eax;
    label_0004AA25:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0004AA25;
    if ((uint32_t)(lift_load32(cpu->esp + 0x3Cu)) < (uint32_t)(cpu->esi)) goto label_0004AA42;
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AA3Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x44AA3Fu));
    cpu->esp += 4u;
    label_0004AA42:
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    lift_store32(cpu->esp + 0x3Cu, cpu->edi);
    lift_store32(cpu->esp + 0x38u, cpu->ebx);
    lift_store8(cpu->esp + 0x28u, cpu->ebx & 0xFFu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0004AA68;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AA66u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x44AA66u));
    goto label_0004AA98;
    label_0004AA68:
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    cpu->edx = 1u;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(cpu->esi);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(cpu->ebx);
    cpu->ecx += cpu->edx;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(cpu->ebp);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->edx);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->edx);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    label_0004AA98:
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x40u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004AAC0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x3Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    (void)0; /* source SEH registration eliminated */
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AAF7u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x44AAF7u));
    cpu->esi = lift_load32(cpu->eax);
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_0004AB09;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4AB09u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x4AB09u));
    label_0004AB09:
    cpu->edi = g_sfera_mbc_runtime->process_memory_base;
    cpu->edi += cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AB16u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x44AB16u));
    cpu->esi = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_0004AB26;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4AB26u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x4AB26u));
    label_0004AB26:
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    cpu->eax = cpu->edi;
    lift_store32(cpu->esp + 0x28u, 0xFu);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    lift_store8(cpu->esp + 0x14u, cpu->ebx & 0xFFu);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0004AB41:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0004AB41;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AB55u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x44AB55u));
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x58u, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AB66u)); sfera_sub_00491C80(cpu, LIFT_CODE_TOKEN_VA(0x44AB66u));
    cpu->ebp = 0x10u;
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(cpu->ebp)) goto label_0004AB72;
    cpu->eax = lift_load32(cpu->eax);
    label_0004AB72:
    cpu->edx = cpu->esi;
    cpu->edx -= cpu->eax;
    cpu->edi = 1u;
    label_0004AB80:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    cpu->eax += cpu->edi;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0004AB80;
    if ((uint32_t)(lift_load32(cpu->esp + 0x44u)) < (uint32_t)(cpu->ebp)) goto label_0004AB9E;
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AB9Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x44AB9Bu));
    cpu->esp += 4u;
    label_0004AB9E:
    cpu->esi |= 0xFFFFFFFFu;
    lift_store32(cpu->esp + 0x44u, 0xFu);
    lift_store32(cpu->esp + 0x40u, cpu->ebx);
    lift_store8(cpu->esp + 0x30u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esp + 0x58u, cpu->esi);
    if ((uint32_t)(lift_load32(cpu->esp + 0x28u)) < (uint32_t)(cpu->ebp)) goto label_0004ABC8;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44ABC5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x44ABC5u));
    cpu->esp += 4u;
    label_0004ABC8:
    cpu->ecx = g_sfera_mbc_runtime->value_stack_size;
    lift_store32(cpu->esp + 0x28u, 0xFu);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    lift_store8(cpu->esp + 0x14u, cpu->ebx & 0xFFu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0004ABF2;
    cpu->ecx = (uint32_t)(uintptr_t)"Stack overflow";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44ABF0u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_VA(0x44ABF0u));
    goto label_0004AC1D;
    label_0004ABF2:
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].type = (uint32_t)(cpu->ebp);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].payload[0] = (uint32_t)(cpu->ebx);
    cpu->ecx += cpu->edi;
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].source_id = (uint32_t)(cpu->esi);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_end = (uint32_t)(cpu->edi);
    g_sfera_mbc_interpreter_storage.value_stack.entries[cpu->eax >> 5u].range_begin = (uint32_t)(cpu->edi);
    g_sfera_mbc_runtime->value_stack_size = (uint32_t)(cpu->ecx);
    label_0004AC1D:
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x48u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004AC40:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x48u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x5Cu);
    (void)0; /* source SEH registration eliminated */
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AC77u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x44AC77u));
    cpu->esi = lift_load32(cpu->eax);
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_0004AC89;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4AC89u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x4AC89u));
    label_0004AC89:
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AC94u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x44AC94u));
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += cpu->eax;
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44ACA7u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x44ACA7u));
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx += cpu->eax;
    cpu->eax = 0xFu;
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_store32(cpu->esp + 0x50u, cpu->eax);
    lift_store32(cpu->esp + 0x4Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x3Cu, cpu->ebx & 0xFFu);
    lift_store32(cpu->esp + 0x64u, cpu->ebx);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    lift_store8(cpu->esp + 0x20u, cpu->ebx & 0xFFu);
    cpu->esp -= 0x1Cu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx + 0x14u, cpu->eax);
    cpu->eax = cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    lift_store32(cpu->esp + 0x30u, cpu->esp);
    lift_store32(cpu->ecx + 0x10u, cpu->ebx);
    lift_store8(cpu->esp + 0x80u, 1u);
    cpu->edi = (uint32_t)(cpu->esp + 0x58u);
    cpu->ebp = (uint32_t)(cpu->esp + 0x3Cu);
    lift_store8(cpu->ecx, cpu->ebx & 0xFFu);
    lift_store32(cpu->esp + 0x30u, cpu->edx);
    label_0004AD00:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0004AD00;
    cpu->eax -= lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AD12u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x44AD12u));
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AD1Bu)); sfera_sub_004930A0(cpu, LIFT_CODE_TOKEN_VA(0x44AD1Bu));
    cpu->esi = 0x10u;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(1u)) goto label_0004AD74;
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->edx) == (uint32_t)(g_sfera_mbc_runtime->process_memory_base)) goto label_0004AD4A;
    cpu->eax = lift_load32(cpu->esp + 0x3Cu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x50u)) >= (uint32_t)(cpu->esi)) goto label_0004AD3E;
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    label_0004AD3E:
    cpu->edx -= cpu->eax;
    label_0004AD40:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0004AD40;
    label_0004AD4A:
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(g_sfera_mbc_runtime->process_memory_base)) goto label_0004AD70;
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x34u)) >= (uint32_t)(cpu->esi)) goto label_0004AD64;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    label_0004AD64:
    cpu->edx -= cpu->eax;
    label_0004AD66:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0004AD66;
    label_0004AD70:
    cpu->ecx = 0u;
    goto label_0004AD77;
    label_0004AD74:
    cpu->ecx |= 0xFFFFFFFFu;
    label_0004AD77:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AD7Cu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44AD7Cu));
    if ((uint32_t)(lift_load32(cpu->esp + 0x34u)) < (uint32_t)(cpu->esi)) goto label_0004AD8F;
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AD8Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x44AD8Cu));
    cpu->esp += 4u;
    label_0004AD8F:
    lift_store32(cpu->esp + 0x34u, 0xFu);
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    lift_store8(cpu->esp + 0x20u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x50u)) < (uint32_t)(cpu->esi)) goto label_0004ADB2;
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44ADAFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x44ADAFu));
    cpu->esp += 4u;
    label_0004ADB2:
    cpu->ecx = lift_load32(cpu->esp + 0x5Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x54u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004ADE0:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x48u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x5Cu);
    (void)0; /* source SEH registration eliminated */
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AE17u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x44AE17u));
    cpu->esi = lift_load32(cpu->eax);
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_0004AE29;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4AE29u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x4AE29u));
    label_0004AE29:
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AE34u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x44AE34u));
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += cpu->eax;
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AE47u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x44AE47u));
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx += cpu->eax;
    cpu->eax = 0xFu;
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_store32(cpu->esp + 0x50u, cpu->eax);
    lift_store32(cpu->esp + 0x4Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x3Cu, cpu->ebx & 0xFFu);
    lift_store32(cpu->esp + 0x64u, cpu->ebx);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    lift_store8(cpu->esp + 0x20u, cpu->ebx & 0xFFu);
    cpu->esp -= 0x1Cu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx + 0x14u, cpu->eax);
    cpu->eax = cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    lift_store32(cpu->esp + 0x30u, cpu->esp);
    lift_store32(cpu->ecx + 0x10u, cpu->ebx);
    lift_store8(cpu->esp + 0x80u, 1u);
    cpu->edi = (uint32_t)(cpu->esp + 0x3Cu);
    cpu->ebp = (uint32_t)(cpu->esp + 0x58u);
    lift_store8(cpu->ecx, cpu->ebx & 0xFFu);
    lift_store32(cpu->esp + 0x30u, cpu->edx);
    label_0004AEA0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0004AEA0;
    cpu->eax -= lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AEB2u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x44AEB2u));
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AEBBu)); sfera_sub_00493430(cpu, LIFT_CODE_TOKEN_VA(0x44AEBBu));
    cpu->esi = 0x10u;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(1u)) goto label_0004AF14;
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->edx) == (uint32_t)(g_sfera_mbc_runtime->process_memory_base)) goto label_0004AEEA;
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x34u)) >= (uint32_t)(cpu->esi)) goto label_0004AEDE;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    label_0004AEDE:
    cpu->edx -= cpu->eax;
    label_0004AEE0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0004AEE0;
    label_0004AEEA:
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(g_sfera_mbc_runtime->process_memory_base)) goto label_0004AF10;
    cpu->eax = lift_load32(cpu->esp + 0x3Cu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x50u)) >= (uint32_t)(cpu->esi)) goto label_0004AF04;
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    label_0004AF04:
    cpu->edx -= cpu->eax;
    label_0004AF06:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0004AF06;
    label_0004AF10:
    cpu->ecx = 0u;
    goto label_0004AF17;
    label_0004AF14:
    cpu->ecx |= 0xFFFFFFFFu;
    label_0004AF17:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AF1Cu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44AF1Cu));
    if ((uint32_t)(lift_load32(cpu->esp + 0x34u)) < (uint32_t)(cpu->esi)) goto label_0004AF2F;
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AF2Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x44AF2Cu));
    cpu->esp += 4u;
    label_0004AF2F:
    lift_store32(cpu->esp + 0x34u, 0xFu);
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    lift_store8(cpu->esp + 0x20u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x50u)) < (uint32_t)(cpu->esi)) goto label_0004AF52;
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AF4Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x44AF4Fu));
    cpu->esp += 4u;
    label_0004AF52:
    cpu->ecx = lift_load32(cpu->esp + 0x5Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x54u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004AF80:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x48u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x5Cu);
    (void)0; /* source SEH registration eliminated */
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AFB7u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x44AFB7u));
    cpu->esi = lift_load32(cpu->eax);
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ebx)) goto label_0004AFC9;
    cpu->ecx = (uint32_t)(uintptr_t)"poppointerup(): unexpected NULL-pointer fetched";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4AFC9u)); sfera_sub_004385D0(cpu, LIFT_CODE_TOKEN_RVA(0x4AFC9u));
    label_0004AFC9:
    cpu->esi += g_sfera_mbc_runtime->process_memory_base;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AFD4u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44AFD4u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AFDBu)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44AFDBu));
    cpu->ebp = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AFE2u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x44AFE2u));
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = g_sfera_mbc_runtime->process_memory_base;
    cpu->ecx += cpu->eax;
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44AFF5u)); sfera_sub_0043AE70(cpu, LIFT_CODE_TOKEN_VA(0x44AFF5u));
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = g_sfera_mbc_runtime->process_memory_base;
    cpu->edx += cpu->eax;
    cpu->eax = 0xFu;
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_store32(cpu->esp + 0x50u, cpu->eax);
    lift_store32(cpu->esp + 0x4Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x3Cu, cpu->ebx & 0xFFu);
    lift_store32(cpu->esp + 0x64u, cpu->ebx);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    lift_store8(cpu->esp + 0x20u, cpu->ebx & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx);
    cpu->esp -= 0x1Cu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx + 0x14u, cpu->eax);
    cpu->eax = cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    lift_store32(cpu->esp + 0x38u, cpu->esp);
    lift_store32(cpu->ecx + 0x10u, cpu->ebx);
    lift_store8(cpu->esp + 0x88u, 1u);
    lift_store8(cpu->ecx, cpu->ebx & 0xFFu);
    lift_store32(cpu->esp + 0x38u, cpu->edx);
    label_0004B050:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0004B050;
    cpu->eax -= lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44B062u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x44B062u));
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44B06Bu)); sfera_sub_00493920(cpu, LIFT_CODE_TOKEN_VA(0x44B06Bu));
    cpu->esi = 0x10u;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(1u)) goto label_0004B0C4;
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->edx) == (uint32_t)(g_sfera_mbc_runtime->process_memory_base)) goto label_0004B09A;
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x34u)) >= (uint32_t)(cpu->esi)) goto label_0004B08E;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    label_0004B08E:
    cpu->edx -= cpu->eax;
    label_0004B090:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0004B090;
    label_0004B09A:
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(g_sfera_mbc_runtime->process_memory_base)) goto label_0004B0C0;
    cpu->eax = lift_load32(cpu->esp + 0x3Cu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x50u)) >= (uint32_t)(cpu->esi)) goto label_0004B0B4;
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    label_0004B0B4:
    cpu->edx -= cpu->eax;
    label_0004B0B6:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0004B0B6;
    label_0004B0C0:
    cpu->ecx = 0u;
    goto label_0004B0C7;
    label_0004B0C4:
    cpu->ecx |= 0xFFFFFFFFu;
    label_0004B0C7:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44B0CCu)); sfera_sub_0043B0D0(cpu, LIFT_CODE_TOKEN_VA(0x44B0CCu));
    if ((uint32_t)(lift_load32(cpu->esp + 0x34u)) < (uint32_t)(cpu->esi)) goto label_0004B0DF;
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44B0DCu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x44B0DCu));
    cpu->esp += 4u;
    label_0004B0DF:
    lift_store32(cpu->esp + 0x34u, 0xFu);
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    lift_store8(cpu->esp + 0x20u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x50u)) < (uint32_t)(cpu->esi)) goto label_0004B102;
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44B0FFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x44B0FFu));
    cpu->esp += 4u;
    label_0004B102:
    cpu->ecx = lift_load32(cpu->esp + 0x5Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x54u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004B130:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44B135u)); sfera_sub_0043ACF0(cpu, LIFT_CODE_TOKEN_VA(0x44B135u));
    if ((uint32_t)(cpu->eax) > (uint32_t)(4u)) goto label_0004B15A;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_0004B141;
        case 1u: goto label_0004B146;
        case 2u: goto label_0004B14B;
        case 3u: goto label_0004B150;
        case 4u: goto label_0004B155;
        default: lift_trap(cpu, 0x44B13Au, "resolved jump-table index out of range"); return;
    }
label_0004B141: ;
    goto label_0004A8C0;
    label_0004B146:
    goto label_0004AAC0;
    label_0004B14B:
    goto label_0004AC40;
    label_0004B150:
    goto label_0004ADE0;
    label_0004B155:
    goto label_0004AF80;
    label_0004B15A:
    cpu->ecx = (uint32_t)(uintptr_t)"ffchat_utility(). Invalid Chat utility function type";
    sfera_sub_004385D0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044B180(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44B1ADu)); sfera_sub_00425E30(cpu, LIFT_CODE_TOKEN_VA(0x44B1ADu));
    lift_push32(cpu, (uint32_t)(uintptr_t)"light_source.eff");
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x18u, 0u);
    std::construct_at(reinterpret_cast<CLightEffect*>(cpu->esi));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44B1C7u)); sfera_sub_00425EB0(cpu, LIFT_CODE_TOKEN_VA(0x44B1C7u));
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esi + 0x70u, lift_x87_get(cpu, 0u));
    cpu->eax = 1u;
    lift_x87_push(cpu, (double)255.0f);
    cpu->ecx |= 0xFFFFFFFFu;
    lift_store_f32(cpu->esi + 0x6Cu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store_f32(cpu->esi + 0x68u, lift_x87_get(cpu, 0u));
    lift_store8(cpu->esi + 0x80u, cpu->eax & 0xFFu);
    lift_store_f32(cpu->esi + 0x64u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 8u, 0xC8u);
    lift_store_f32(cpu->esi + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0x14u, cpu->ecx);
    lift_store32(cpu->esi + 0x78u, cpu->ecx);
    lift_store32(cpu->esi + 0x74u, 0u);
    lift_store_f32(cpu->esi + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0x84u, 0u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044B230(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->edi + 0x74u)) != (uint32_t)(0u)) goto label_0004B27E;
    lift_x87_push(cpu, 0.0);
    cpu->ecx = lift_load32(cpu->edi + 0x60u);
    cpu->edx = lift_load32(cpu->edi + 0x64u);
    cpu->esp -= 0x14u;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edi + 0x68u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->edi + 0x6Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebx);
    lift_store32(cpu->eax + 0xCu, cpu->edx);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44B27Bu)); sfera_sub_004562D0(cpu, LIFT_CODE_TOKEN_VA(0x44B27Bu));
    lift_store32(cpu->edi + 0x78u, cpu->eax);
    label_0004B27E:
    cpu->ecx = lift_load32(cpu->edi + 0x78u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFFFFFFu)) goto label_0004B333;
    lift_store32(cpu->edi + 0x74u, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44B296u)); sfera_sub_004600C0(cpu, LIFT_CODE_TOKEN_VA(0x44B296u));
    cpu->edx = lift_load32(cpu->ebx);
    cpu->esi = cpu->eax;
    lift_store32(cpu->esi, cpu->edx);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebx + 8u);
    lift_store32(cpu->esi + 8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x60u);
    lift_store32(cpu->esi + 0xCu, cpu->edx);
    cpu->eax = lift_load32(cpu->edi + 0x64u);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edi + 0x68u);
    lift_store32(cpu->esi + 0x14u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x6Cu);
    lift_store32(cpu->esi + 0x18u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x70u));
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load8(cpu->edi + 0x80u);
    cpu->eax = lift_load32(cpu->edi + 0x84u);
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    if ((uint32_t)(cpu->edx) != 0u) goto label_0004B32D;
    cpu->ebx = native_function_address32(&::rand);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x4B2E3u), LIFT_CODE_TOKEN_RVA(0x4B2E1u))) { return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x4B2E9u), LIFT_CODE_TOKEN_RVA(0x4B2E7u))) { return; }
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->ecx -= cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 0x7Cu))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x10u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x10u))));
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x14u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x14u))));
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004B32D:
    lift_store32(cpu->edi + 0x84u, (uint64_t)(lift_load32(cpu->edi + 0x84u)) + 1u);
    label_0004B333:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x18u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044B340(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004B36B;
    cpu->ecx = lift_load32(cpu->esi + 0x78u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFFFFFFu)) goto label_0004B357;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4B357u)); sfera_sub_004563A0(cpu, LIFT_CODE_TOKEN_RVA(0x4B357u));
    label_0004B357:
    lift_store32(cpu->esi + 0x78u, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x74u, 0u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0004B36B:
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044B380(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->esi + 0xDu)) != (uint8_t)(0u)) goto label_0004B3A8;
    cpu->ecx = lift_load32(cpu->esi + 0x78u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFFFFFFu)) goto label_0004B396;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4B396u)); sfera_sub_004563A0(cpu, LIFT_CODE_TOKEN_RVA(0x4B396u));
    label_0004B396:
    lift_store32(cpu->esi + 0x78u, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x74u, 0u);
    lift_store8(cpu->esi + 0xDu, 1u);
    label_0004B3A8:
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044B3B0(LiftCpu* cpu, uint32_t stop_address) {
    if ((uint8_t)(lift_load8(cpu->ecx + 0xDu)) == (uint8_t)(0u)) goto label_0004B3BA;
    lift_store8(cpu->ecx + 0xDu, 0u);
    label_0004B3BA:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044B3C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->edx = 0xB7u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\LightEffect.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44B3F0u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x44B3F0u));
    lift_push32(cpu, 0x88u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44B3FAu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x44B3FAu));
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0004B424;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44B414u)); sfera_sub_0044B180(cpu, LIFT_CODE_TOKEN_VA(0x44B414u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004B424:
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044B440(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0004B4EF;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->esi += 8u;
    cpu->ebx = cpu->eax;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0004B460:
    cpu->eax = lift_load32(cpu->esi + 0xFFFFFFF8u);
    cpu->ecx = (uint32_t)(cpu->eax + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(3u)) goto label_0004B4CF;
    switch ((uint32_t)(cpu->ecx)) {
        case 0u: goto label_0004B472;
        case 1u: goto label_0004B4A2;
        case 2u: goto label_0004B4AB;
        case 3u: goto label_0004B4C3;
        default: lift_trap(cpu, 0x44B46Bu, "resolved jump-table index out of range"); return;
    }
label_0004B472: ;
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load16(cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_store_f32(cpu->edi + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load16(cpu->eax + 2u);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_store_f32(cpu->edi + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load16(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_store_f32(cpu->edi + 0x68u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004B4E3;
    label_0004B4A2:
    cpu->ecx = lift_load32(cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_store_f32(cpu->edi + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004B4E3;
    label_0004B4AB:
    cpu->edx = lift_load32(cpu->esi);
    cpu->eax = lift_load8(cpu->edx);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (100.0));
    lift_store_f32(cpu->edi + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004B4E3;
    label_0004B4C3:
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edi + 0x80u, cpu->edx & 0xFFu);
    goto label_0004B4E3;
    label_0004B4CF:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"CLightEffect::SetParameter() -> Unrecognized parameter %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44B4DAu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x44B4DAu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44B4E0u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x44B4E0u));
    cpu->esp += 0xCu;
    label_0004B4E3:
    cpu->esi += 0xCu;
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004B460;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0004B4EF:
    cpu->edi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044B510(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    std::construct_at(reinterpret_cast<CLightEffect*>(cpu->esi));
    cpu->ecx = lift_load32(cpu->esi + 0x78u);
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFFFFFFu)) goto label_0004B553;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4B553u)); sfera_sub_004563A0(cpu, LIFT_CODE_TOKEN_RVA(0x4B553u));
    label_0004B553:
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x78u, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x74u, 0u);
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44B570u)); sfera_sub_00425E70(cpu, LIFT_CODE_TOKEN_VA(0x44B570u));
    if ((uint8_t)((lift_load8(cpu->esp + 0x1Cu)) & (1u)) == 0u) goto label_0004B580;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44B57Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x44B57Du));
    cpu->esp += 4u;
    label_0004B580:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044B5A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    cpu->eax = lift_load32(cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xCu))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0x1Cu))));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0x2Cu))));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->edx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x18u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x28u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->edx + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044B7D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store_f32(cpu->ecx + 0x94u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    lift_store32(cpu->ecx + 0x74u, cpu->eax);
    lift_store32(cpu->ecx + 0x78u, cpu->edx);
    lift_store32(cpu->ecx + 0x7Cu, cpu->esi);
    lift_store32(cpu->ecx + 0x80u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0004B80D;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0004B80D:
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.5);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0004B831;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0004B831:
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->ecx + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 2.0);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 3u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->ecx + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    if ((int32_t)(uint32_t)(cpu->edi) >= 0) goto label_0004B859;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0004B859:
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_0004B877;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0004B877:
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->esi = lift_pop32(cpu);
    lift_store_f32(cpu->ecx + 0x68u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044B890(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x58u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004B8C7;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x54u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004B8C7;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x50u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0004B90E;
    label_0004B8C7:
    lift_store_f32(cpu->esi + 0x58u, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44B8DDu)); sfera_sub_004EED54(cpu, LIFT_CODE_TOKEN_VA(0x44B8DDu));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    lift_store_f32(cpu->esi + 0x98u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store16(cpu->esi + 0x564u, 0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store8(cpu->esi + 0x566u, cpu->eax & 0xFFu);
    lift_store_f32(cpu->esi + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esi + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0004B90E:
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044B920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x40u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    cpu->eax = cpu->ecx;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx = 0x10u;
    cpu->esi = cpu->eax;
    cpu->edi = (uint32_t)(cpu->esp + 8u);
    lift_movs32(cpu, 1u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0xCu))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0x18u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0x20u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0x2Cu))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x30u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x34u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0x38u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x3Cu));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0xCu))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0x18u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0x20u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0x2Cu))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x30u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x34u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0x38u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x3Cu));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0xCu))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0x18u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0x20u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x28u));
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    cpu->esi = lift_pop32(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0x2Cu))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x30u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x34u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0x38u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x3Cu));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0xCu))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0x18u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0x20u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0x2Cu))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x30u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x34u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0x38u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x3Cu));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0x40u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044BB80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x24u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_x87_push(cpu, 2.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xCu));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx + 0xCu))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx + 0xCu))));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx + 0xCu))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->edx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp))));
    lift_store_f32(cpu->edx + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->edx + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 3u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->edx + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->edx + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 4u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->edx + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->edx + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->edx + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0x24u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044BC70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 0xCu))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 1e-05);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0004BD90;
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 9.999999747378752e-06);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0004BD2B;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44BCCEu)); sfera_sub_004EED5A(cpu, LIFT_CODE_TOKEN_VA(0x44BCCEu));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44BCE3u)); sfera_sub_004EE9F8(cpu, LIFT_CODE_TOKEN_VA(0x44BCE3u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0xCu))));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44BD00u)); sfera_sub_004EE9F8(cpu, LIFT_CODE_TOKEN_VA(0x44BD00u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44BD1Du)); sfera_sub_004EE9F8(cpu, LIFT_CODE_TOKEN_VA(0x44BD1Du));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (((double)lift_load_f32(cpu->esp + 0x10u))));
    goto label_0004BD3B;
    label_0004BD2B:
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004BD3B:
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 8u))));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xCu));
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0xCu))));
    cpu->esi = lift_pop32(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0004BD90:
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_store_f32(cpu->edi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (1.5707965));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44BDC7u)); sfera_sub_004EE9F8(cpu, LIFT_CODE_TOKEN_VA(0x44BDC7u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (1.5707965));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44BDDAu)); sfera_sub_004EE9F8(cpu, LIFT_CODE_TOKEN_VA(0x44BDDAu));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->edi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->edi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xCu));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 0xCu))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->edi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044BE30(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=cpu->esp, r=(uint64_t)(0x88u), v=l - r; lift_flags_sub(cpu,l,r,0u,v,32u); cpu->esp= v; }
    lift_push32(cpu, cpu->esi);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(6u), 32u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uint32_t)(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_log_runtime.files[0].path.text[0]));
    cpu->ecx = cpu->eax;
    cpu->esi = (uint32_t)(cpu->ecx + 1u);
    label_0004BE56:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0004BE56;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0004BE95;
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    cpu->edx -= cpu->eax;
    label_0004BE67:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0004BE67;
    if ((uint32_t)(lift_load32(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_log_runtime.files[0].truncate_on_first_write))) != (uint32_t)(1u)) goto label_0004BE88;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + ((uint32_t)(uintptr_t)&g_sfera_log_runtime.files[0].has_written))), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(uintptr_t)"wt";
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0004BE8D;
    label_0004BE88:
    cpu->eax = (uint32_t)(uintptr_t)"at";
    label_0004BE8D:
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    goto label_0004BE9F;
    label_0004BE95:
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, (uintptr_t)"ErrorTest.log");
    label_0004BE9F:
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x44BE9Fu));
    cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x88u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044BEC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44BECBu)); sfera_sub_0044BE30(cpu, LIFT_CODE_TOKEN_VA(0x44BECBu));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0004BEF9;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)"%d\n"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x44BED8u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x44BEDFu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x44BEE6u));
    cpu->esp += 0x14u;
    g_sfera_log_runtime.files[0].has_written = (uint32_t)(1u);
    label_0004BEF9:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044BF00(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44BF08u)); sfera_sub_0044BE30(cpu, LIFT_CODE_TOKEN_VA(0x44BF08u));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0004BF3F;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    cpu->esp -= 8u;
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)"%f\n"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x44BF1Eu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x44BF25u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x44BF2Cu));
    cpu->esp += 0x18u;
    g_sfera_log_runtime.files[0].has_written = (uint32_t)(1u);
    label_0004BF3F:
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044BF50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44BF5Bu)); sfera_sub_0044BE30(cpu, LIFT_CODE_TOKEN_VA(0x44BF5Bu));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0004BF84;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x44BF63u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x44BF6Au));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x44BF71u));
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[0].has_written = (uint32_t)(1u);
    label_0004BF84:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044BF90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)&g_sfera_client_process_runtime.log_message[0]);
    lift_native_call(cpu, native_function_address32(&::vsprintf), LIFT_CODE_TOKEN_VA(0x44BFA0u));
    cpu->esp += 0xCu;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44BFB0u)); sfera_sub_0044BE30(cpu, LIFT_CODE_TOKEN_VA(0x44BFB0u));
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0004BFDD;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)&g_sfera_client_process_runtime.log_message[0]);
    lift_native_call(cpu, native_function_address32(&::fputs), LIFT_CODE_TOKEN_VA(0x44BFBCu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x44BFC3u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x44BFCAu));
    cpu->esp += 0x10u;
    g_sfera_log_runtime.files[0].has_written = (uint32_t)(1u);
    label_0004BFDD:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044BFE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->edx;
    cpu->edi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x44BFEEu));
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x44BFF9u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"%A, %d %B %Y"); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::strftime), LIFT_CODE_TOKEN_VA(0x44C007u));
    cpu->esp += 0x18u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044C020(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x41Cu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44C038u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x44C038u));
    cpu->edx = 2u;
    cpu->ecx = cpu->esi;
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44C046u)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x44C046u));
    cpu->esi = cpu->eax;
    cpu->edx = cpu->edi;
    lift_push32(cpu, 2u);
    cpu->edx = 0u - (uint64_t)(cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44C055u)); sfera_sub_0042F0E0(cpu, LIFT_CODE_TOKEN_VA(0x44C055u));
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44C05Fu)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x44C05Fu));
    lift_push32(cpu, 0u);
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44C06Au)); sfera_sub_0042F0E0(cpu, LIFT_CODE_TOKEN_VA(0x44C06Au));
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44C074u)); sfera_sub_0042F000(cpu, LIFT_CODE_TOKEN_VA(0x44C074u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_chsize), LIFT_CODE_TOKEN_VA(0x44C076u));
    cpu->esp += 8u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44C086u)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x44C086u));
    lift_push32(cpu, 0x424u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44C097u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x44C097u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044C0A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0004C0BA;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4C0BAu)); sfera_sub_004D8880(cpu, LIFT_CODE_TOKEN_RVA(0x4C0BAu));
    label_0004C0BA:
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"Debug"); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::MessageBoxA), LIFT_CODE_TOKEN_VA(0x44C0C8u));
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044C0D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::ShowCursor);
    lift_push32(cpu, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x4C0DBu), LIFT_CODE_TOKEN_RVA(0x4C0D9u))) { return; }
    lift_push32(cpu, 1u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x4C0DFu), LIFT_CODE_TOKEN_RVA(0x4C0DDu))) { return; }
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0004C0EB;
    label_0004C0E3:
    lift_push32(cpu, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x4C0E7u), LIFT_CODE_TOKEN_RVA(0x4C0E5u))) { return; }
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0004C0E3;
    label_0004C0EB:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044C0F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::ShowCursor);
    lift_push32(cpu, 0u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x4C0FBu), LIFT_CODE_TOKEN_RVA(0x4C0F9u))) { return; }
    lift_push32(cpu, 1u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x4C0FFu), LIFT_CODE_TOKEN_RVA(0x4C0FDu))) { return; }
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0004C10B;
    label_0004C103:
    lift_push32(cpu, 1u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x4C107u), LIFT_CODE_TOKEN_RVA(0x4C105u))) { return; }
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0004C103;
    label_0004C10B:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044C110(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = 0u;
    label_0004C115:
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.resource_count[0]))) <= (int32_t)(uint32_t)(cpu->edi)) goto label_0004C145;
    cpu->esi = (uint32_t)(cpu->ebx + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.atlas_resources[0][0]));
    label_0004C125:
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0004C139;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x4C133u), LIFT_CODE_TOKEN_RVA(0x4C131u))) { return; }
    lift_store32(cpu->esi, 0u);
    label_0004C139:
    ++cpu->edi;
    cpu->esi += 0x14u;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->ebx + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.resource_count[0])))) goto label_0004C125;
    label_0004C145:
    cpu->ebx += 4u;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(0x14u)) goto label_0004C115;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044C160(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::PeekMessageA);
    lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x4C179u), LIFT_CODE_TOKEN_RVA(0x4C177u))) { return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0004C1BA;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::DispatchMessageA);
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::TranslateMessage);
    label_0004C190:
    if ((uint32_t)(lift_load32(cpu->esp + 0x10u)) == (uint32_t)(0x12u)) goto label_0004C1BF;
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x4C19Eu), LIFT_CODE_TOKEN_RVA(0x4C19Cu))) { return; }
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x4C1A5u), LIFT_CODE_TOKEN_RVA(0x4C1A3u))) { return; }
    lift_push32(cpu, 1u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x4C1B4u), LIFT_CODE_TOKEN_RVA(0x4C1B2u))) { return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0004C190;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0004C1BA:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004C1BF:
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::ExitProcess), LIFT_CODE_TOKEN_VA(0x44C1C1u));
    lift_trap(cpu, 0x44C1C7u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044C1D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 4u));
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 8u))));
    cpu->eax = cpu->ecx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 4u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    cpu->esi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 4u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044C210(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=cpu->esp, r=(uint64_t)(0x10u), v=l - r; lift_flags_sub(cpu,l,r,0u,v,32u); cpu->esp= v; }
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    lift_store32(cpu->esp + 0xCu, 0u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_push32(cpu, cpu->edi);
    label_0004C236:
    cpu->esi = sfera_clip_plane_order(cpu->eax);
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(4u), 32u);
    cpu->esi += lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = 0u;
    cpu->ebp = 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0004C2F2;
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = (uint32_t)(cpu->edx + 0xFFFFFFFCu);
    cpu->ebx = lift_shift_right(cpu, cpu->ebx, (uint32_t)(2u), 32u);
    cpu->edi += 0x14u;
    ++cpu->ebx;
    cpu->ebp = (uint32_t)(((uint32_t)(cpu->ebx) * 4u));
    label_0004C261:
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xFFFFFFF0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xFFFFFFECu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xFFFFFFF4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004C283;
    ++cpu->ecx;
    label_0004C283:
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xFFFFFFFCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xFFFFFFF8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004C2A4;
    ++cpu->ecx;
    label_0004C2A4:
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004C2C6;
    ++cpu->ecx;
    label_0004C2C6:
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 8u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004C2E8;
    ++cpu->ecx;
    label_0004C2E8:
    cpu->edi += 0x30u;
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004C261;
    label_0004C2F2:
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(cpu->edx)) goto label_0004C32D;
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->eax = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->ebp) * 2u));
    cpu->ebx = cpu->edx;
    cpu->edi = (uint32_t)(cpu->edi + ((uint32_t)(cpu->eax) * 4u) + 8u);
    cpu->ebx -= cpu->ebp;
    label_0004C306:
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xFFFFFFFCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xFFFFFFF8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004C327;
    ++cpu->ecx;
    label_0004C327:
    cpu->edi += 0xCu;
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004C306;
    label_0004C32D:
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0004C362;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(6u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0004C236;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->ebp = lift_pop32(cpu);
    cpu->eax += 2u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0004C362:
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044C370(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->ecx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.clip_planes[0][0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44C37Du)); sfera_sub_0044C210(cpu, LIFT_CODE_TOKEN_VA(0x44C37Du));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044C380(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.interpolation_axes[0].count;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->edx) * 4u) + 0xFFFFFFFCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[0].samples[0])));
    lift_push32(cpu, cpu->ebx);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_world_bounds_runtime.minimum.x.f32));
    lift_push32(cpu, cpu->ebp);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    cpu->esi = 0u;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    cpu->ebp = 0u;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004C3B2;
    cpu->ebp = (uint32_t)(cpu->edi + 1u);
    label_0004C3B2:
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, 1.0);
    label_0004C3B6:
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->edi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[0].samples[0])));
    cpu->ebx = 0u;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 3u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_0004C3D3;
    cpu->ebx = 1u;
    label_0004C3D3:
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->ebx)) goto label_0004C46D;
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[0].samples[0])))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[0].samples[0])));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[0].samples[0])))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004C410;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    goto label_0004C429;
    label_0004C410:
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0004C423;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    label_0004C423:
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0004C429:
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[2].samples[0])));
    ++cpu->esi;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[2].samples[0])))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[2].samples[0])))));
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[2].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[1].samples[0])));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[1].samples[0])))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[1].samples[0])))));
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[1].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[0].count), lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0004C46D:
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0004C499;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[0].samples[0])));
    ++cpu->esi;
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[0].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[1].samples[0])));
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[1].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[2].samples[0])));
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[2].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004C499:
    ++cpu->edi;
    cpu->ebp = cpu->ebx;
    cpu->edx = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.interpolation_axes[0].count))) goto label_0004C3B6;
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    g_sfera_landscape_interpolation_runtime.axes[0].count = (uint32_t)(cpu->esi);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044C4C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = g_sfera_landscape_interpolation_runtime.axes[0].count;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->edx) * 4u) + 0xFFFFFFFCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[0].samples[0])));
    lift_push32(cpu, cpu->ebx);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_world_bounds_runtime.maximum.x.f32));
    lift_push32(cpu, cpu->ebp);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    cpu->esi = 0u;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    cpu->ebp = 0u;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_0004C4F2;
    cpu->ebp = (uint32_t)(cpu->edi + 1u);
    label_0004C4F2:
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, 1.0);
    label_0004C4F6:
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->edi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[0].samples[0])));
    cpu->ebx = 0u;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 3u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004C513;
    cpu->ebx = 1u;
    label_0004C513:
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->ebx)) goto label_0004C5AD;
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[0].samples[0])))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[0].samples[0])));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[0].samples[0])))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004C550;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    goto label_0004C569;
    label_0004C550:
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0004C563;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    label_0004C563:
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0004C569:
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[2].samples[0])));
    ++cpu->esi;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[2].samples[0])))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[2].samples[0])))));
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[2].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[1].samples[0])));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[1].samples[0])))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[1].samples[0])))));
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[1].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[0].count), lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0004C5AD:
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0004C5D9;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[0].samples[0])));
    ++cpu->esi;
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[0].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[1].samples[0])));
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[1].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[2].samples[0])));
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[2].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004C5D9:
    ++cpu->edi;
    cpu->ebp = cpu->ebx;
    cpu->edx = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_landscape_interpolation_runtime.axes[0].count)) goto label_0004C4F6;
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.interpolation_axes[0].count) = (uint32_t)(cpu->esi);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044C600(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.interpolation_axes[0].count;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->edx) * 4u) + 0xFFFFFFFCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[1].samples[0])));
    lift_push32(cpu, cpu->ebx);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_world_bounds_runtime.minimum.y.f32));
    lift_push32(cpu, cpu->ebp);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    cpu->esi = 0u;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    cpu->ebp = 0u;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004C632;
    cpu->ebp = (uint32_t)(cpu->edi + 1u);
    label_0004C632:
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, 1.0);
    label_0004C636:
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->edi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[1].samples[0])));
    cpu->ebx = 0u;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 3u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_0004C653;
    cpu->ebx = 1u;
    label_0004C653:
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->ebx)) goto label_0004C6ED;
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[1].samples[0])))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[1].samples[0])));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[1].samples[0])))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004C690;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    goto label_0004C6A9;
    label_0004C690:
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0004C6A3;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    label_0004C6A3:
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0004C6A9:
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[0].samples[0])));
    ++cpu->esi;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[0].samples[0])))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[0].samples[0])))));
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[0].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[2].samples[0])));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[2].samples[0])))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[2].samples[0])))));
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[2].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[1].count), lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0004C6ED:
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0004C719;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[0].samples[0])));
    ++cpu->esi;
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[0].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[1].samples[0])));
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[1].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[2].samples[0])));
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[2].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004C719:
    ++cpu->edi;
    cpu->ebp = cpu->ebx;
    cpu->edx = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.interpolation_axes[0].count))) goto label_0004C636;
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    g_sfera_landscape_interpolation_runtime.axes[0].count = (uint32_t)(cpu->esi);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044C740(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = g_sfera_landscape_interpolation_runtime.axes[0].count;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->edx) * 4u) + 0xFFFFFFFCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[1].samples[0])));
    lift_push32(cpu, cpu->ebx);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_world_bounds_runtime.maximum.y.f32));
    lift_push32(cpu, cpu->ebp);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    cpu->esi = 0u;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    cpu->ebp = 0u;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_0004C772;
    cpu->ebp = (uint32_t)(cpu->edi + 1u);
    label_0004C772:
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, 1.0);
    label_0004C776:
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->edi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[1].samples[0])));
    cpu->ebx = 0u;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 3u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004C793;
    cpu->ebx = 1u;
    label_0004C793:
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->ebx)) goto label_0004C82D;
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[1].samples[0])))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[1].samples[0])));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[1].samples[0])))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004C7D0;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    goto label_0004C7E9;
    label_0004C7D0:
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0004C7E3;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    label_0004C7E3:
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0004C7E9:
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[0].samples[0])));
    ++cpu->esi;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[0].samples[0])))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[0].samples[0])))));
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[0].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[2].samples[0])));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[2].samples[0])))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[2].samples[0])))));
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[2].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[1].count), lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0004C82D:
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0004C859;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[0].samples[0])));
    ++cpu->esi;
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[0].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[1].samples[0])));
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[1].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[2].samples[0])));
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[2].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004C859:
    ++cpu->edi;
    cpu->ebp = cpu->ebx;
    cpu->edx = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_landscape_interpolation_runtime.axes[0].count)) goto label_0004C776;
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.interpolation_axes[0].count) = (uint32_t)(cpu->esi);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044C880(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.interpolation_axes[0].count;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->edx) * 4u) + 0xFFFFFFFCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[2].samples[0])));
    lift_push32(cpu, cpu->ebx);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_world_bounds_runtime.minimum.z.f32));
    lift_push32(cpu, cpu->ebp);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    cpu->esi = 0u;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    cpu->ebp = 0u;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004C8B2;
    cpu->ebp = (uint32_t)(cpu->edi + 1u);
    label_0004C8B2:
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, 1.0);
    label_0004C8B6:
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->edi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[2].samples[0])));
    cpu->ebx = 0u;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 3u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_0004C8D3;
    cpu->ebx = 1u;
    label_0004C8D3:
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->ebx)) goto label_0004C96D;
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[2].samples[0])))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[2].samples[0])));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[2].samples[0])))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004C910;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    goto label_0004C929;
    label_0004C910:
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0004C923;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    label_0004C923:
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0004C929:
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[0].samples[0])));
    ++cpu->esi;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[0].samples[0])))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[0].samples[0])))));
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[0].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[1].samples[0])));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[1].samples[0])))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[1].samples[0])))));
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[1].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[2].count), lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0004C96D:
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0004C999;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[0].samples[0])));
    ++cpu->esi;
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[0].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[1].samples[0])));
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[1].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[2].samples[0])));
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[2].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004C999:
    ++cpu->edi;
    cpu->ebp = cpu->ebx;
    cpu->edx = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)((*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.interpolation_axes[0].count))) goto label_0004C8B6;
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    g_sfera_landscape_interpolation_runtime.axes[0].count = (uint32_t)(cpu->esi);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044C9C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = g_sfera_landscape_interpolation_runtime.axes[0].count;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->edx) * 4u) + 0xFFFFFFFCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[2].samples[0])));
    lift_push32(cpu, cpu->ebx);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_world_bounds_runtime.maximum.z.f32));
    lift_push32(cpu, cpu->ebp);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    cpu->esi = 0u;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    cpu->ebp = 0u;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_0004C9F2;
    cpu->ebp = (uint32_t)(cpu->edi + 1u);
    label_0004C9F2:
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, 1.0);
    label_0004C9F6:
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->edi) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[2].samples[0])));
    cpu->ebx = 0u;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 3u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004CA13;
    cpu->ebx = 1u;
    label_0004CA13:
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->ebx)) goto label_0004CAAD;
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[2].samples[0])))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[2].samples[0])));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[2].samples[0])))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0004CA50;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    goto label_0004CA69;
    label_0004CA50:
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0004CA63;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    label_0004CA63:
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0004CA69:
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[0].samples[0])));
    ++cpu->esi;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[0].samples[0])))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[0].samples[0])))));
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[0].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[1].samples[0])));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[1].samples[0])))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[1].samples[0])))));
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[1].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[2].count), lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0004CAAD:
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0004CAD9;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[0].samples[0])));
    ++cpu->esi;
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[0].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[1].samples[0])));
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[1].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_landscape_interpolation_runtime.axes[2].samples[0])));
    lift_store_f32(((uint32_t)(cpu->esi) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_main_ui_state_runtime.interpolation_axes[2].count), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004CAD9:
    ++cpu->edi;
    cpu->ebp = cpu->ebx;
    cpu->edx = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_landscape_interpolation_runtime.axes[0].count)) goto label_0004C9F6;
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    (*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.interpolation_axes[0].count) = (uint32_t)(cpu->esi);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044CB00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_0004CB14:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0004CB14;
    cpu->eax -= cpu->esi;
    cpu->ecx = cpu->eax;
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_0004CB24:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0004CB24;
    cpu->eax -= cpu->esi;
    cpu->edi = cpu->eax;
    cpu->ecx -= cpu->edi;
    cpu->ebx = (uint32_t)(cpu->ecx + 1u);
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(cpu->ebx) <= 0) goto label_0004CB5C;
    cpu->ebp = native_function_address32(&::_strnicmp);
    label_0004CB40:
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esi + cpu->ecx);
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x4CB50u), LIFT_CODE_TOKEN_RVA(0x4CB4Eu))) { return; }
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0004CB66;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->ebx)) goto label_0004CB40;
    label_0004CB5C:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004CB66:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044CB70(LiftCpu* cpu, uint32_t stop_address) {
    if ((uint32_t)(g_sfera_direct_input_runtime.direct_input) == (uint32_t)(0u)) goto label_0004CBE0;
    cpu->eax = g_sfera_input_device_runtime.keyboard_device;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0004CBA1;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x4CB8Au), LIFT_CODE_TOKEN_RVA(0x4CB88u))) { return; }
    cpu->eax = g_sfera_input_device_runtime.keyboard_device;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x4CB97u), LIFT_CODE_TOKEN_RVA(0x4CB95u))) { return; }
    g_sfera_input_device_runtime.keyboard_device = (uint32_t)(0u);
    label_0004CBA1:
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0004CBC9;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x4CBB2u), LIFT_CODE_TOKEN_RVA(0x4CBB0u))) { return; }
    cpu->eax = g_sfera_direct_input_runtime.mouse_device;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x4CBBFu), LIFT_CODE_TOKEN_RVA(0x4CBBDu))) { return; }
    g_sfera_direct_input_runtime.mouse_device = (uint32_t)(0u);
    label_0004CBC9:
    cpu->eax = g_sfera_direct_input_runtime.direct_input;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x4CBD6u), LIFT_CODE_TOKEN_RVA(0x4CBD4u))) { return; }
    g_sfera_direct_input_runtime.direct_input = (uint32_t)(0u);
    label_0004CBE0:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044CBF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_input_device_runtime.keyboard_device;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0004CC6E;
    if ((uint32_t)(g_sfera_texture_cache_runtime.cache_enabled) == (uint32_t)(0u)) goto label_0004CC6E;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x24u);
    lift_push32(cpu, (uintptr_t)&g_sfera_direct_input_runtime.keyboard_state[0]); lift_push32(cpu, 0x100u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x4CC14u), LIFT_CODE_TOKEN_RVA(0x4CC12u))) { return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x8007001Eu)) goto label_0004CC22;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x8007000Cu)) goto label_0004CC54;
    label_0004CC22:
    cpu->eax = g_sfera_input_device_runtime.keyboard_device;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x4CC2Fu), LIFT_CODE_TOKEN_RVA(0x4CC2Du))) { return; }
    cpu->eax = g_sfera_input_device_runtime.keyboard_device;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x24u);
    lift_push32(cpu, (uintptr_t)&g_sfera_direct_input_runtime.keyboard_state[0]); lift_push32(cpu, 0x100u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x4CC46u), LIFT_CODE_TOKEN_RVA(0x4CC44u))) { return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x8007001Eu)) goto label_0004CC6E;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x8007000Cu)) goto label_0004CC6E;
    label_0004CC54:
    cpu->eax = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(0x80u) & 0xFFu);
    label_0004CC60:
    lift_store8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_direct_input_runtime.keyboard_state[0]), (uint64_t)(lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_direct_input_runtime.keyboard_state[0]))) & (uint64_t)((cpu->ecx & 0xFFu)));
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x100u)) goto label_0004CC60;
    label_0004CC6E:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044CC70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = g_sfera_input_device_runtime.keyboard_device;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0004CD06;
    if ((uint32_t)(g_sfera_texture_cache_runtime.cache_enabled) == (uint32_t)(0u)) goto label_0004CD06;
    label_0004CC87:
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_main_command_state_runtime.async_status);
    lift_store32(cpu->esp + 0xCu, 1u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, 0x14u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x28u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x4CCA5u), LIFT_CODE_TOKEN_RVA(0x4CCA3u))) { return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x8007001Eu)) goto label_0004CCB3;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x8007000Cu)) goto label_0004CCE9;
    label_0004CCB3:
    cpu->eax = g_sfera_input_device_runtime.keyboard_device;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x4CCC0u), LIFT_CODE_TOKEN_RVA(0x4CCBEu))) { return; }
    cpu->eax = g_sfera_input_device_runtime.keyboard_device;
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)&g_sfera_main_command_state_runtime.async_status); lift_push32(cpu, 0x14u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x28u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x4CCDBu), LIFT_CODE_TOKEN_RVA(0x4CCD9u))) { return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x8007001Eu)) goto label_0004CD06;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x8007000Cu)) goto label_0004CD06;
    label_0004CCE9:
    if ((uint32_t)(lift_load32(cpu->esp)) == (uint32_t)(0u)) goto label_0004CD06;
    if ((uint8_t)((lift_load8((uint32_t)(uintptr_t)&g_sfera_main_command_state_runtime.async_status_bytes[0])) & (0x80u)) != 0u) goto label_0004CCFF;
    cpu->eax = g_sfera_input_device_runtime.keyboard_device;
    goto label_0004CC87;
    label_0004CCFF:
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_command_state_runtime.async_status;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004CD06:
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044CD30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_store32(cpu->esp + 4u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ebp) <= (int32_t)(uint32_t)(1u)) goto label_0004CD74;
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFFEu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44CD6Du)); sfera_sub_004A4E10(cpu, LIFT_CODE_TOKEN_VA(0x44CD6Du));
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
    label_0004CD74:
    cpu->eax = 0xFFFFFFFEu;
    cpu->eax -= lift_load32(((uint32_t)(cpu->ebp) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.origin[0]));
    lift_push32(cpu, cpu->ebx);
    cpu->edx += cpu->eax;
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(g_sfera_screen_clip_runtime.bottom), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0004D180;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x30u);
    cpu->eax = cpu->esi;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    cpu->eax -= cpu->esi;
    cpu->eax += cpu->eax;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->eax += cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(g_sfera_screen_clip_runtime.top)) goto label_0004D17F;
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    cpu->edx &= 0xFF000000u;
    if ((uint32_t)(cpu->edx) == (uint32_t)(0xFF000000u)) goto label_0004CDE4;
    if ((uint8_t)(lift_load8(cpu->esp + 0x3Cu)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0004CDE4;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44CDE0u)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_VA(0x44CDE0u));
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    label_0004CDE4:
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.0010000000474974513f);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0004CE49;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.scale.x));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0004D17B;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.scale.y));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0004D179;
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004CE4B;
    label_0004CE49:
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004CE4B:
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_push32(cpu, cpu->edi);
    cpu->esi = 0u;
    cpu->edi = 0u;
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0004D164;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    label_0004CE66:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(0xAu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0004D10E;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax & 0xFFu)) & 0xFFu);
    cpu->eax = cpu->edx & 0xFFu;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_font_runtime.glyphs[0].defined))), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x40u, cpu->edx & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004CE8C;
    lift_store8(cpu->esp + 0x40u, 0x7Cu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x40u)) & 0xFFu);
    label_0004CE8C:
    if ((int32_t)(uint32_t)(cpu->ecx) > (int32_t)(uint32_t)(g_sfera_screen_clip_runtime.right)) goto label_0004D0DA;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->eax += cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(g_sfera_screen_clip_runtime.left), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0004D0DA;
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    cpu->ebp = cpu->edx & 0xFFu;
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)(4u), 32u);
    cpu->eax = lift_load32(cpu->ebp + ((uint32_t)(uintptr_t)&g_sfera_font_runtime.glyphs[0].texture_index));
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx += cpu->eax;
    cpu->eax = lift_load32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.atlas_resources[0][0]));
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0004CF3A;
    { uint64_t v=(uint64_t)(cpu->ebx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004CED6;
    cpu->ebx = cpu->eax;
    goto label_0004CF3A;
    label_0004CED6:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ebx);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44CEE8u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x44CEE8u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x16u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44CEF7u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x44CEF7u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x1C4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44CF07u)); sfera_sub_004D8B70(cpu, LIFT_CODE_TOKEN_VA(0x44CF07u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)&g_sfera_screen_quad_indices[0]); lift_push32(cpu, cpu->esi); lift_push32(cpu, sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 0u, &SferaScreenVertex::x)); lift_push32(cpu, 0xFu); lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44CF24u)); sfera_sub_004D9580(cpu, LIFT_CODE_TOKEN_VA(0x44CF24u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x40u)) & 0xFFu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->esi = 0u;
    lift_flags_logic(cpu,0u,32u); cpu->edi = 0u;
    label_0004CF3A:
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->eax = cpu->esi;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 0u, &SferaScreenVertex::z), lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 0u, &SferaScreenVertex::diffuse), cpu->ecx);
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 0u, &SferaScreenVertex::rhw), lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 1u, &SferaScreenVertex::diffuse), cpu->ecx);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 2u, &SferaScreenVertex::diffuse), cpu->ecx);
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 1u, &SferaScreenVertex::z), lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 3u, &SferaScreenVertex::diffuse), cpu->ecx);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store16(((uint32_t)(cpu->edi) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_screen_quad_indices[0]), cpu->esi & 0xFFFFu);
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 1u, &SferaScreenVertex::rhw), lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 2u, &SferaScreenVertex::z), lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 2u, &SferaScreenVertex::rhw), lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 3u, &SferaScreenVertex::z), lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 3u, &SferaScreenVertex::rhw), lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_push(cpu, 0.5);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 0u, &SferaScreenVertex::x), lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 3u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 0u, &SferaScreenVertex::y), lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + ((uint32_t)(uintptr_t)&g_sfera_font_runtime.glyphs[0].u)));
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 0u, &SferaScreenVertex::u), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + ((uint32_t)(uintptr_t)&g_sfera_font_runtime.glyphs[0].v)));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 0u, &SferaScreenVertex::v), lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x24u)))));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 1u, &SferaScreenVertex::x), lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 1u, &SferaScreenVertex::y), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + ((uint32_t)(uintptr_t)&g_sfera_font_runtime.glyphs[0].u)));
    lift_x87_push(cpu, 0.1171875);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 1u, &SferaScreenVertex::u), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 1u, &SferaScreenVertex::v), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 2u, &SferaScreenVertex::x), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x40u))));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 2u, &SferaScreenVertex::y), lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 2u, &SferaScreenVertex::u), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + ((uint32_t)(uintptr_t)&g_sfera_font_runtime.glyphs[0].v)));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 2u, &SferaScreenVertex::v), lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 3u, &SferaScreenVertex::x), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 3u, &SferaScreenVertex::y), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 0u, &SferaScreenVertex::u)));
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 3u, &SferaScreenVertex::u), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 3u, &SferaScreenVertex::v), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_load32(cpu->esp + 0x38u);
    cpu->eax = (uint32_t)(cpu->esi + 1u);
    lift_store16(((uint32_t)(cpu->edi) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_screen_quad_indices[1]), cpu->eax & 0xFFFFu);
    cpu->eax = (uint32_t)(cpu->esi + 2u);
    cpu->ecx = (uint32_t)(cpu->esi + 3u);
    lift_store16(((uint32_t)(cpu->edi) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_screen_quad_indices[3]), cpu->esi & 0xFFFFu);
    lift_store16(((uint32_t)(cpu->edi) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_screen_quad_indices[5]), cpu->ecx & 0xFFFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store16(((uint32_t)(cpu->edi) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_screen_quad_indices[2]), cpu->eax & 0xFFFFu);
    lift_store16(((uint32_t)(cpu->edi) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_screen_quad_indices[4]), cpu->eax & 0xFFFFu);
    cpu->esi += 4u;
    cpu->edi += 6u;
    label_0004D0DA:
    lift_store32(cpu->esp + 0x2Cu, (uint64_t)(lift_load32(cpu->esp + 0x2Cu)) + 1u);
    cpu->eax = cpu->edx & 0xFFu;
    cpu->edx = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx += cpu->eax;
    cpu->eax = lift_load32(((uint32_t)(cpu->edx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_metrics[0][0]));
    cpu->eax += lift_load32(((uint32_t)(cpu->ebp) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.code_base[0]));
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(lift_load32(cpu->esp + 0x34u));
    cpu->ecx += cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0004CE66;
    label_0004D10E:
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->esi) == 0u) goto label_0004D164;
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44D128u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x44D128u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x16u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44D137u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x44D137u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x1C4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44D147u)); sfera_sub_004D8B70(cpu, LIFT_CODE_TOKEN_VA(0x44D147u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)&g_sfera_screen_quad_indices[0]); lift_push32(cpu, cpu->esi); lift_push32(cpu, sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 0u, &SferaScreenVertex::x)); lift_push32(cpu, 0xFu); lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4D164u)); sfera_sub_004D9580(cpu, LIFT_CODE_TOKEN_RVA(0x4D164u));
    label_0004D164:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44D16Fu)); sfera_sub_004D91E0(cpu, LIFT_CODE_TOKEN_VA(0x44D16Fu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
    label_0004D179:
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004D17B:
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004D17F:
    cpu->esi = lift_pop32(cpu);
    label_0004D180:
    cpu->ebx = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044D190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    cpu->ebp = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(g_sfera_screen_clip_runtime.bottom), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_0004D58A;
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    cpu->eax -= cpu->ecx;
    cpu->eax += cpu->eax;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    cpu->eax += cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(g_sfera_screen_clip_runtime.top)) goto label_0004D58A;
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->eax &= 0xFF000000u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFF000000u)) goto label_0004D1F2;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 6u); lift_push32(cpu, 5u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4D1F2u)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_RVA(0x4D1F2u));
    label_0004D1F2:
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.0010000000474974513f);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0004D257;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.scale.x));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0004D586;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.scale.y));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0004D584;
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0004D259;
    label_0004D257:
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004D259:
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0004D56F;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    label_0004D272:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(0xAu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0004D519;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax & 0xFFu)) & 0xFFu);
    cpu->eax = cpu->edx & 0xFFu;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(4u), 32u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_font_runtime.glyphs[0].defined))), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x40u, cpu->edx & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004D298;
    lift_store8(cpu->esp + 0x40u, 0x7Cu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x40u)) & 0xFFu);
    label_0004D298:
    if ((int32_t)(uint32_t)(cpu->ebp) > (int32_t)(uint32_t)(g_sfera_screen_clip_runtime.right)) goto label_0004D4E2;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->ecx += cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(g_sfera_screen_clip_runtime.left), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0004D4E2;
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    cpu->ebp = cpu->edx & 0xFFu;
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)(4u), 32u);
    cpu->eax = lift_load32(cpu->ebp + ((uint32_t)(uintptr_t)&g_sfera_font_runtime.glyphs[0].texture_index));
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx += cpu->eax;
    cpu->eax = lift_load32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.atlas_resources[0][0]));
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0004D346;
    { uint64_t v=(uint64_t)(cpu->ebx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004D2E2;
    cpu->ebx = cpu->eax;
    goto label_0004D346;
    label_0004D2E2:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ebx);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44D2F4u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x44D2F4u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x16u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44D303u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x44D303u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x1C4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44D313u)); sfera_sub_004D8B70(cpu, LIFT_CODE_TOKEN_VA(0x44D313u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)&g_sfera_screen_quad_indices[0]); lift_push32(cpu, cpu->esi); lift_push32(cpu, sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 0u, &SferaScreenVertex::x)); lift_push32(cpu, 0xFu); lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44D330u)); sfera_sub_004D9580(cpu, LIFT_CODE_TOKEN_VA(0x44D330u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x40u)) & 0xFFu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->esi = 0u;
    lift_flags_logic(cpu,0u,32u); cpu->edi = 0u;
    label_0004D346:
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->eax = cpu->esi;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(5u), 32u);
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 0u, &SferaScreenVertex::z), lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 0u, &SferaScreenVertex::diffuse), cpu->ecx);
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 0u, &SferaScreenVertex::rhw), lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 1u, &SferaScreenVertex::diffuse), cpu->ecx);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 2u, &SferaScreenVertex::diffuse), cpu->ecx);
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 1u, &SferaScreenVertex::z), lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 3u, &SferaScreenVertex::diffuse), cpu->ecx);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store16(((uint32_t)(cpu->edi) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_screen_quad_indices[0]), cpu->esi & 0xFFFFu);
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 1u, &SferaScreenVertex::rhw), lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 2u, &SferaScreenVertex::z), lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 2u, &SferaScreenVertex::rhw), lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 3u, &SferaScreenVertex::z), lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 3u, &SferaScreenVertex::rhw), lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    lift_x87_push(cpu, 0.5);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) - (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 0u, &SferaScreenVertex::x), lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x28u)))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 3u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 0u, &SferaScreenVertex::y), lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + ((uint32_t)(uintptr_t)&g_sfera_font_runtime.glyphs[0].u)));
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 0u, &SferaScreenVertex::u), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + ((uint32_t)(uintptr_t)&g_sfera_font_runtime.glyphs[0].v)));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 0u, &SferaScreenVertex::v), lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x20u)))));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 1u, &SferaScreenVertex::x), lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 1u, &SferaScreenVertex::y), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + ((uint32_t)(uintptr_t)&g_sfera_font_runtime.glyphs[0].u)));
    lift_x87_push(cpu, 0.1171875);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 1u, &SferaScreenVertex::u), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 1u, &SferaScreenVertex::v), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 2u, &SferaScreenVertex::x), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x40u))));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 2u, &SferaScreenVertex::y), lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 2u, &SferaScreenVertex::u), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + ((uint32_t)(uintptr_t)&g_sfera_font_runtime.glyphs[0].v)));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 2u, &SferaScreenVertex::v), lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 3u, &SferaScreenVertex::x), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 3u, &SferaScreenVertex::y), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 0u, &SferaScreenVertex::u)));
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 3u, &SferaScreenVertex::u), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 3u, &SferaScreenVertex::v), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    cpu->eax = (uint32_t)(cpu->esi + 1u);
    lift_store16(((uint32_t)(cpu->edi) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_screen_quad_indices[1]), cpu->eax & 0xFFFFu);
    cpu->eax = (uint32_t)(cpu->esi + 2u);
    cpu->ecx = (uint32_t)(cpu->esi + 3u);
    lift_store16(((uint32_t)(cpu->edi) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_screen_quad_indices[3]), cpu->esi & 0xFFFFu);
    lift_store16(((uint32_t)(cpu->edi) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_screen_quad_indices[2]), cpu->eax & 0xFFFFu);
    lift_store16(((uint32_t)(cpu->edi) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_screen_quad_indices[4]), cpu->eax & 0xFFFFu);
    lift_store16(((uint32_t)(cpu->edi) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_screen_quad_indices[5]), cpu->ecx & 0xFFFFu);
    cpu->esi += 4u;
    cpu->edi += 6u;
    label_0004D4E2:
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->esp + 0x30u, (uint64_t)(lift_load32(cpu->esp + 0x30u)) + 1u);
    cpu->eax = cpu->edx & 0xFFu;
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx += cpu->eax;
    cpu->eax = lift_load32(((uint32_t)(cpu->edx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.glyph_metrics[0][0]));
    cpu->eax += lift_load32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_font_atlas_layout_runtime.code_base[0]));
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(lift_load32(cpu->esp + 0x38u));
    cpu->ebp += cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0004D272;
    label_0004D519:
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->esi) == 0u) goto label_0004D56F;
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44D533u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x44D533u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x16u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44D542u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x44D542u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x1C4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44D552u)); sfera_sub_004D8B70(cpu, LIFT_CODE_TOKEN_VA(0x44D552u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->edi); lift_push32(cpu, (uintptr_t)&g_sfera_screen_quad_indices[0]); lift_push32(cpu, cpu->esi); lift_push32(cpu, sfera_screen_vertex_address(g_sfera_landscape_screen_vertices, 0u, &SferaScreenVertex::x)); lift_push32(cpu, 0xFu); lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4D56Fu)); sfera_sub_004D9580(cpu, LIFT_CODE_TOKEN_RVA(0x4D56Fu));
    label_0004D56F:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44D57Au)); sfera_sub_004D91E0(cpu, LIFT_CODE_TOKEN_VA(0x44D57Au));
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
    label_0004D584:
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004D586:
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004D58A:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044D5A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if ((uint32_t)((*(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_02)) == (uint32_t)(cpu->esi)) goto label_0004D6F7;
    lift_x87_push(cpu, 0.0);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].x, lift_x87_get(cpu, 0u));
    lift_push32(cpu, 6u);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].y, lift_x87_get(cpu, 0u));
    lift_push32(cpu, 5u);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].u, lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].v, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_width))));
    lift_x87_push(cpu, 0.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].x, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].y, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].v, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].x));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].x, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_graphics_runtime.display_height))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].y, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].u, lift_x87_get(cpu, 0u));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].v, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].x, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].y));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].y, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].v, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44D64Au)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_VA(0x44D64Au));
    lift_x87_push(cpu, 0.0);
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_ui_state_runtime.ui_state_02;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].z, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(0x18u), 32u);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].rhw, lift_x87_get(cpu, 0u));
    cpu->eax |= 0xFFFFFFu;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_push32(cpu, 0x1C4u);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].z, lift_x87_get(cpu, 0u));
    g_sfera_scene_render_runtime.textured_quad[0].diffuse = (uint32_t)(cpu->eax);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    g_sfera_scene_render_runtime.textured_quad[0].specular = (uint32_t)(cpu->esi);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[1].rhw, lift_x87_get(cpu, 0u));
    g_sfera_scene_render_runtime.textured_quad[1].diffuse = (uint32_t)(cpu->eax);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    g_sfera_scene_render_runtime.textured_quad[1].specular = (uint32_t)(cpu->esi);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].z, lift_x87_get(cpu, 0u));
    g_sfera_scene_render_runtime.textured_quad[2].diffuse = (uint32_t)(cpu->eax);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    g_sfera_scene_render_runtime.textured_quad[2].specular = (uint32_t)(cpu->esi);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[2].rhw, lift_x87_get(cpu, 0u));
    g_sfera_scene_render_runtime.textured_quad[3].diffuse = (uint32_t)(cpu->eax);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    g_sfera_scene_render_runtime.textured_quad[3].specular = (uint32_t)(cpu->esi);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].z, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_scene_render_runtime.textured_quad[3].rhw, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44D6D1u)); sfera_sub_004D8B70(cpu, LIFT_CODE_TOKEN_VA(0x44D6D1u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x20u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->esi); lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)&g_sfera_scene_render_runtime.textured_quad[0].x); lift_push32(cpu, 0xEu); lift_push32(cpu, 6u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44D6EBu)); sfera_sub_004D9580(cpu, LIFT_CODE_TOKEN_VA(0x44D6EBu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->esi = lift_pop32(cpu);
    sfera_sub_004D91E0(cpu, stop_address); return;
    label_0004D6F7:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044D700(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x6Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44D713u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x44D713u));
    cpu->eax -= g_sfera_client_main_scalar_runtime.counter_04;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_frame_runtime.fps_sample_count, (uint64_t)(g_sfera_frame_runtime.fps_sample_count) + 1u);
    lift_store32(cpu->esp, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x2710u)) goto label_0004D758;
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_frame_runtime.fps_sample_count))));
    g_sfera_frame_runtime.fps_sample_count = (uint32_t)(0u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (10000.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / ((double)(((int32_t)(lift_load32(cpu->esp))))));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_frame_runtime.fps, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44D74Du)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x44D74Du));
    g_sfera_client_main_scalar_runtime.counter_04 = (uint32_t)(cpu->eax);
    lift_store32((uintptr_t)&g_sfera_frame_runtime.fps_anchor.high, cpu->edx);
    label_0004D758:
    if ((uint32_t)(g_sfera_landscape_map_runtime.show_fps) == (uint32_t)(0u)) goto label_0004D7C5;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_frame_runtime.fps));
    cpu->eax = g_sfera_graphics_runtime.display_width;
    cpu->ecx = g_sfera_graphics_runtime.display_height;
    cpu->esp -= 8u;
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    --cpu->eax;
    --cpu->ecx;
    lift_push32(cpu, (uintptr_t)"FPS: %4.1f"); lift_push32(cpu, cpu->edx);
    g_sfera_screen_clip_runtime.left = (uint32_t)(0u);
    g_sfera_screen_clip_runtime.top = (uint32_t)(0u);
    g_sfera_screen_clip_runtime.right = (uint32_t)(cpu->eax);
    g_sfera_screen_clip_runtime.bottom = (uint32_t)(cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x44D7A3u));
    lift_x87_push(cpu, 0.0);
    cpu->esp += 0xCu;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0u); lift_push32(cpu, 1u); lift_push32(cpu, 0xFFFFFFFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4D7C5u)); sfera_sub_0044D190(cpu, LIFT_CODE_TOKEN_RVA(0x4D7C5u));
    label_0004D7C5:
    cpu->esp += 0x6Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044D7E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_0004D808;
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, 0x10u); lift_push32(cpu, (uintptr_t)"Critical"); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::MessageBoxA), LIFT_CODE_TOKEN_VA(0x44D7F8u));
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0004D808:
    lift_push32(cpu, 0x11u); lift_push32(cpu, (uintptr_t)"Error"); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_window_runtime.main_window;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::MessageBoxA), LIFT_CODE_TOKEN_VA(0x44D817u));
    cpu->esi = cpu->eax;
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044D830(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, 1024.0);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    cpu->edi = (uint32_t)(cpu->ecx + 0x1D78u);
    cpu->esi = (uint32_t)(cpu->ecx + 0x2514u);
    lift_store32(cpu->esp + 0x10u, 4u);
    lift_push32(cpu, cpu->ebp);
    label_0004D855:
    cpu->ebp = 4u;
    label_0004D85A:
    cpu->ebx = 9u;
    label_0004D85F:
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x1Cu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0004D891;
    lift_store_f32(cpu->edi + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edi + 0x28u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edi + 0x4Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edi + 0x58u, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44D888u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x44D888u));
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->edi + 0x68u, cpu->eax);
    goto label_0004D893;
    label_0004D891:
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004D893:
    cpu->esi += 0x78u;
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004D85F;
    cpu->edi += 0x78u;
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004D85A;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x14u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x14u, v); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004D855;
    cpu->esi = (uint32_t)(cpu->ecx + 0x1D94u);
    cpu->edi = (uint32_t)(cpu->ecx + 0x1B98u);
    cpu->ebp = (uint32_t)(cpu->ebx + 4u);
    label_0004D8B4:
    cpu->ebx = 4u;
    label_0004D8B9:
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x1Cu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0004D8EB;
    lift_store_f32(cpu->edi + 0x1Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edi + 0x28u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edi + 0x4Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edi + 0x58u, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44D8E2u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x44D8E2u));
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->edi + 0x68u, cpu->eax);
    goto label_0004D8ED;
    label_0004D8EB:
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004D8ED:
    cpu->esi += 0x78u;
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004D8B9;
    cpu->edi += 0x78u;
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004D8B4;
    cpu->ebp = lift_pop32(cpu);
    cpu->edi = (uint32_t)(cpu->ebx + 4u);
    cpu->esi = (uint32_t)(cpu->ecx + 0x1BB4u);
    cpu->ebx = lift_pop32(cpu);
    label_0004D904:
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x1B3Cu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0004D948;
    lift_store_f32(cpu->ecx + 0x1B3Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ecx + 0x1B48u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ecx + 0x1B6Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ecx + 0x1B78u, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44D93Cu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x44D93Cu));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->ecx + 0x1B88u, cpu->eax);
    goto label_0004D94A;
    label_0004D948:
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0004D94A:
    cpu->esi += 0x78u;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004D904;
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044D960(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x12Cu;
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_findfirst64i32), LIFT_CODE_TOKEN_VA(0x44D97Bu));
    cpu->edi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->edi) == (uint32_t)(0xFFFFFFFFu)) goto label_0004DA9E;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::_findnext64i32);
    lift_push32(cpu, cpu->esi);
    label_0004D9A0:
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0xCu)), r=(uint64_t)(0x10u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0004DA7F;
    cpu->ecx = (int8_t)(lift_load8(cpu->esp + 0x31u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(((int8_t)(lift_load8(cpu->ecx + ((uint32_t)(uintptr_t)g_sfera_ascii_lower_runtime.table))))) & 0xFFFFu);
    cpu->ecx = (int8_t)(lift_load8(cpu->esp + 0x30u));
    cpu->edx = 0x100u;
    {
        int64_t result = (int64_t)(((int16_t)((cpu->eax & 0xFFFFu)))) * (int64_t)(((int16_t)((cpu->edx & 0xFFFFu))));
        cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint64_t)result) & 0xFFFFu);
        int64_t truncated = (int64_t)(int16_t)result;
        uint32_t overflow = truncated != result;
        cpu->eflags = (cpu->eflags & ~LIFT_FLAG_CF) | ((overflow != 0u) ? LIFT_FLAG_CF : 0u);
        cpu->eflags = (cpu->eflags & ~LIFT_FLAG_OF) | ((overflow != 0u) ? LIFT_FLAG_OF : 0u);
    }
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(((int8_t)(lift_load8(cpu->ecx + ((uint32_t)(uintptr_t)g_sfera_ascii_lower_runtime.table))))) & 0xFFFFu);
    cpu->ecx = g_sfera_scene_control_runtime.microtexture_count;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFFFu)) + (uint64_t)((cpu->edx & 0xFFFFu)) + (uint64_t)(0u))) & 0xFFFFu);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    lift_store16(((uint32_t)(cpu->edx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.microtextures[0].lookup_key), cpu->eax & 0xFFFFu);
    cpu->edx = g_sfera_client_main_scalar_runtime.state_02;
    cpu->eax = cpu->eax & 0xFFFFu;
    lift_store16(cpu->edx + ((uint32_t)(cpu->eax) * 2u), cpu->ecx & 0xFFFFu);
    lift_push32(cpu, 0x12E7u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\main.cpp";
    cpu->ecx = 0x20020u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DA03u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x44DA03u));
    cpu->ecx = g_sfera_scene_control_runtime.microtexture_count;
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    lift_store32(((uint32_t)(cpu->ecx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.microtextures[0].resource), cpu->eax);
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DA1Eu)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x44DA1Eu));
    cpu->esi = cpu->eax;
    cpu->eax = g_sfera_scene_control_runtime.microtexture_count;
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->edx = lift_load32(((uint32_t)(cpu->edx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.microtextures[0].resource));
    lift_push32(cpu, 0x20020u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DA3Bu)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x44DA3Bu));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DA42u)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x44DA42u));
    if ((uint8_t)(lift_load8(cpu->esp + 0x32u)) != (uint8_t)(0x5Fu)) goto label_0004DA5A;
    cpu->eax = g_sfera_scene_control_runtime.microtexture_count;
    g_sfera_graphics_runtime.base_microtexture_id = (uint32_t)(cpu->eax);
    lift_store8(cpu->esp + 0x33u, 0u);
    goto label_0004DA5F;
    label_0004DA5A:
    lift_store8(cpu->esp + 0x32u, 0u);
    label_0004DA5F:
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x44DA68u)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x44DA68u));
    cpu->ecx = g_sfera_scene_control_runtime.microtexture_count;
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    ++cpu->ecx;
    lift_store32(((uint32_t)(cpu->edx) * 4u) + ((uint32_t)(uintptr_t)&g_sfera_scene_control_runtime.microtextures[0].name), cpu->eax);
    g_sfera_scene_control_runtime.microtexture_count = (uint32_t)(cpu->ecx);
    label_0004DA7F:
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x4DA87u), LIFT_CODE_TOKEN_RVA(0x4DA85u))) { return; }
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0004D9A0;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x44DA93u));
    cpu->esp += 4u;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_0004DA9E:
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x12Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044DAC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    label_0004DAC2:
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    if ((uint8_t)(((cpu->ecx & 0xFFu)) & (1u)) == 0u) goto label_0004DAD0;
    cpu->eax ^= 0xEDB88320u;
    label_0004DAD0:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0004DADD;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0004DADF;
    label_0004DADD:
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0004DADF:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0004DAEC;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0004DAEE;
    label_0004DAEC:
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0004DAEE:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0004DAFB;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0004DAFD;
    label_0004DAFB:
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0004DAFD:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0004DB0A;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0004DB0C;
    label_0004DB0A:
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0004DB0C:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0004DB19;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0004DB1B;
    label_0004DB19:
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0004DB1B:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0004DB28;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0004DB2A;
    label_0004DB28:
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0004DB2A:
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0004DB37;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0004DB39;
    label_0004DB37:
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0004DB39:
    lift_store8(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_static_render_lookup_runtime.legacy_crc_low_table[0]), cpu->eax & 0xFFu);
    ++cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0004DAC2;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044DB50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    label_0004DB60:
    cpu->eax = (uint32_t)(cpu->ecx + cpu->edi);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    lift_x87_push(cpu, (double)lift_load_f32(((uint32_t)(cpu->eax) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_partition_sort_runtime.entries[0].sort_key)));
    cpu->esi = cpu->ecx;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = cpu->edi;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    label_0004DB78:
    lift_x87_push(cpu, (double)lift_load_f32(((uint32_t)(cpu->esi) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_partition_sort_runtime.entries[0].sort_key)));
    ++cpu->esi;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0004DB78;
    --cpu->esi;
    label_0004DB8A:
    lift_x87_push(cpu, (double)lift_load_f32(((uint32_t)(cpu->edx) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_partition_sort_runtime.entries[0].sort_key)));
    --cpu->edx;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0004DB8A;
    ++cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) > (int32_t)(uint32_t)(cpu->edx)) goto label_0004DBE6;
    lift_x87_push(cpu, (double)lift_load_f32(((uint32_t)(cpu->esi) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_partition_sort_runtime.entries[0].sort_key)));
    cpu->ebx = lift_load32(((uint32_t)(cpu->edx) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_partition_sort_runtime.entries[0].partition_index));
    cpu->eax = lift_load32(((uint32_t)(cpu->esi) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_partition_sort_runtime.entries[0].partition_index));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(((uint32_t)(cpu->esi) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_partition_sort_runtime.entries[0].partition_index), cpu->ebx);
    lift_x87_push(cpu, (double)lift_load_f32(((uint32_t)(cpu->edx) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_partition_sort_runtime.entries[0].sort_key)));
    lift_store_f32(((uint32_t)(cpu->esi) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_partition_sort_runtime.entries[0].sort_key), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(((uint32_t)(cpu->edx) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_partition_sort_runtime.entries[0].partition_index), cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    ++cpu->esi;
    lift_store_f32(((uint32_t)(cpu->edx) * 8u) + ((uint32_t)(uintptr_t)&g_sfera_partition_sort_runtime.entries[0].sort_key), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    --cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(cpu->edx)) goto label_0004DB78;
    label_0004DBE6:
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->edx)) goto label_0004DBF1;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x4DBF1u)); sfera_sub_0044DB50(cpu, LIFT_CODE_TOKEN_RVA(0x4DBF1u));
    label_0004DBF1:
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0004DBFC;
    cpu->ecx = cpu->esi;
    goto label_0004DB60;
    label_0004DBFC:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0044DC10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1Cu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_push32(cpu, cpu->ebx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_push32(cpu, cpu->esi);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->edi);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_store32(cpu->edx, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->edx + 4u, cpu->eax);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->edx + 8u, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x14u));
    lift_store32(cpu->edx + 0xCu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store32(cpu->edx + 0x10u, cpu->eax);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->edx + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x20u));
    lift_store32(cpu->edx + 0x18u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store32(cpu->edx + 0x1Cu, cpu->eax);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->edx + 0x20u, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x2Cu));
    lift_store32(cpu->edx + 0x24u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store32(cpu->edx + 0x28u, cpu->eax);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->edx + 0x2Cu, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x30u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x34u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x38u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->edx + 0x30u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->edx + 0x34u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->edx + 0x38u, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x3Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x40u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x44u));
    lift_store32(cpu->edx + 0x3Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store32(cpu->edx + 0x40u, cpu->eax);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->edx + 0x44u, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x48u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x4Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x50u));
    lift_store32(cpu->edx + 0x48u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store32(cpu->edx + 0x4Cu, cpu->eax);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->edx + 0x50u, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x54u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x58u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx + 0x5Cu))));
    lift_store32(cpu->edx + 0x54u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->edx + 0x58u, cpu->eax);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->edx + 0x5Cu, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (1024.0));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store32(cpu->esp + 0xCu, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu); lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (1024.0));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store32(cpu->esp + 0x10u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu); lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (1024.0));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store32(cpu->esp + 0x14u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->esi = lift_load32(cpu->ecx + 0x60u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->esi += cpu->eax;
    lift_store32(cpu->edx + 0x60u, cpu->esi);
    cpu->edi = lift_load32(cpu->ecx + 0x68u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->edi += cpu->esi;
    lift_store32(cpu->edx + 0x68u, cpu->edi);
    cpu->ebx = lift_load32(cpu->ecx + 0x70u);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->ebx += cpu->edi;
    lift_store32(cpu->edx + 0x70u, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ecx + 0x64u);
    cpu->ebx += cpu->eax;
    lift_store32(cpu->edx + 0x64u, cpu->ebx);
    cpu->eax = lift_load32(cpu->ecx + 0x6Cu);
    cpu->eax += cpu->esi;
    lift_store32(cpu->edx + 0x6Cu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ecx + 0x74u);
    cpu->ecx += cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->edx + 0x74u, cpu->ecx);
    if (cpu->edx == (uint32_t)(uintptr_t)&g_sfera_view_projection_scratch_runtime) { g_sfera_view_geometry_runtime.clipping_bounds = g_sfera_view_projection_scratch_runtime.clipping_bounds; }
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
