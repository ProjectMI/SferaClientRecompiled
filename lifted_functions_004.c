#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>

static uint8_t sfera_ascii_lower(uint8_t value) { return value >= 'A' && value <= 'Z' ? (uint8_t)(value + ('a' - 'A')) : value; }
static uint32_t sfera_ascii_hash_ci(uint32_t address) { uint32_t hash = UINT32_C(2166136261); for (;;) { const uint8_t value = lift_load8(address++); if (value == 0u) { return hash; } hash = (hash ^ sfera_ascii_lower(value)) * UINT32_C(16777619); } }
static int sfera_ascii_iequals(uint32_t address, const char* literal) { for (;;) { const uint8_t left = sfera_ascii_lower(lift_load8(address++)); const uint8_t right = sfera_ascii_lower((uint8_t)*literal++); if (left != right) { return 0; } if (left == 0u) { return 1; } } }
static int sfera_process_name_is_ignored(uint32_t address) { switch (sfera_ascii_hash_ci(address)) { case 0xCB320621u: return sfera_ascii_iequals(address, "[System Process]"); case 0xC301CF93u: return sfera_ascii_iequals(address, "idle"); case 0xF84B2A97u: return sfera_ascii_iequals(address, "csrss.exe"); case 0xDE6F2DFEu: return sfera_ascii_iequals(address, "winlogon.exe"); case 0x86049695u: return sfera_ascii_iequals(address, "smss.exe"); case 0x28FDCADBu: return sfera_ascii_iequals(address, "services.exe"); case 0x523B71BAu: return sfera_ascii_iequals(address, "service.exe"); case 0x6105AD4Fu: return sfera_ascii_iequals(address, "lsass.exe"); case 0x82611D84u: return sfera_ascii_iequals(address, "taskmgr.exe"); case 0x491E0A9Cu: return sfera_ascii_iequals(address, "system"); case 0x2453F3B9u: return sfera_ascii_iequals(address, "svchost.exe"); case 0xC979C6AEu: return sfera_ascii_iequals(address, "cdantsrv.exe"); case 0x6369D323u: return sfera_ascii_iequals(address, "spoolsv.exe"); case 0xA162EC55u: return sfera_ascii_iequals(address, "mdm.exe"); case 0x48545BE6u: return sfera_ascii_iequals(address, "nvsvc32.exe"); case 0x708EA5E0u: return sfera_ascii_iequals(address, "far.exe"); case 0x130CD4F6u: return sfera_ascii_iequals(address, "regsvc32.exe"); case 0xA11E0AEu: return sfera_ascii_iequals(address, "mstask.exe"); case 0xABDAFF7Eu: return sfera_ascii_iequals(address, "winmgmt.exe"); case 0x8AE4CC97u: return sfera_ascii_iequals(address, "stisvc.exe"); case 0xDB3A61B5u: return sfera_ascii_iequals(address, "rundll32.exe"); case 0xE566D06Eu: return sfera_ascii_iequals(address, "wcescoomm.exe"); case 0xA062BD36u: return sfera_ascii_iequals(address, "internat.exe"); case 0x5037C1B7u: return sfera_ascii_iequals(address, "winword.exe"); case 0x399460A4u: return sfera_ascii_iequals(address, "explorer.exe"); case 0xB884A32Cu: return sfera_ascii_iequals(address, "notepad.exe"); case 0x82407190u: return sfera_ascii_iequals(address, "ctfmon.exe"); case 0xFFB78D72u: return sfera_ascii_iequals(address, "icq.exe"); case 0x3BC05E55u: return sfera_ascii_iequals(address, "iexplore.exe"); case 0x8C6DE00Au: return sfera_ascii_iequals(address, "srvany.exe"); case 0x47785D4Cu: return sfera_ascii_iequals(address, "spidernt.exe"); case 0xF7D48DE3u: return sfera_ascii_iequals(address, "winamp.exe"); case 0xD391162Bu: return sfera_ascii_iequals(address, "kav.exe"); case 0x83888858u: return sfera_ascii_iequals(address, "winrar.exe"); case 0x4FB24653u: return sfera_ascii_iequals(address, "kavsvc.exe"); case 0x73D09132u: return sfera_ascii_iequals(address, "ati2evxx.exe"); case 0x796F943u: return sfera_ascii_iequals(address, "regsvc.exe"); case 0x51E34A6Eu: return sfera_ascii_iequals(address, "mspmspsv.exe"); case 0x94FF76ADu: return sfera_ascii_iequals(address, "resetservice.exe"); case 0x17B4BBA5u: return sfera_ascii_iequals(address, "directcd.exe"); case 0x5AB899A3u: return sfera_ascii_iequals(address, "qttask.exe"); case 0x91BFD53Cu: return sfera_ascii_iequals(address, "atiptaxx.exe"); case 0x681423EEu: return sfera_ascii_iequals(address, "SOUNDMAN.EXE"); case 0x4DF48812u: return sfera_ascii_iequals(address, "wuauclt.exe"); case 0x5ECB2F2Cu: return sfera_ascii_iequals(address, "miranda32.exe"); case 0xB7110726u: return sfera_ascii_iequals(address, "sphere.exe"); case 0xBB309AE5u: return sfera_ascii_iequals(address, "cmd.exe"); case 0xEDFBE74Au: return sfera_ascii_iequals(address, "calc.exe"); case 0x5D2A3611u: return sfera_ascii_iequals(address, "thebat.exe"); default: return 0; } }

LIFT_ENTRY void LIFT_CDECL sfera_sub_004266D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4266D0u);
    cpu->edx = 0u;
    if ((uint8_t)(lift_load8(cpu->ecx + 0xDu)) == (uint8_t)((cpu->edx & 0xFFu))) goto label_00026700;
    cpu->eax = lift_load32(cpu->ecx + 0xB4u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_000266FD;
    if ((uint32_t)(lift_load32(cpu->eax + 0x38u)) != (uint32_t)(cpu->edx)) goto label_000266FD;
    if ((uint32_t)(lift_load32(cpu->eax + 8u)) != (uint32_t)(cpu->edx)) goto label_000266FD;
    cpu->eax = lift_load32(cpu->eax + 0x68u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_000266F7;
    if ((uint32_t)(lift_load32(cpu->eax + 0x6Cu)) == (uint32_t)(cpu->edx)) goto label_000266FD;
    label_000266F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4266F7u);
    lift_store32(cpu->ecx + 0xA8u, cpu->edx);
    label_000266FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4266FDu);
    lift_store8(cpu->ecx + 0xDu, cpu->edx & 0xFFu);
    label_00026700: cpu->eip = LIFT_CODE_TOKEN_VA(0x426700u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00426710(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x426710u);
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, 0.0);
    cpu->eax = cpu->ecx;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + 0xCu, 0xFFFFFFFFu);
    cpu->ecx = lift_load32(cpu->esp);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)255.0f);
    lift_store32(cpu->eax + 0x10u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_store_f32(cpu->eax + 0x28u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->eax + 0x24u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + 0x14u, cpu->edx);
    lift_store_f32(cpu->eax + 0x20u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + 0x18u, cpu->ecx);
    lift_store_f32(cpu->eax + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = 0u;
    lift_x87_push(cpu, 1.0);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store_f32(cpu->eax + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    lift_store32(cpu->eax + 0x2Cu, cpu->ecx);
    lift_store32(cpu->eax + 0x30u, cpu->ecx);
    lift_store_f32(cpu->eax + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax + 0x34u, cpu->ecx);
    lift_store8(cpu->eax + 0x60u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x58u, 1u);
    lift_store32(cpu->eax + 0x5Cu, cpu->ecx);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00426780(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x426780u);
    cpu->esp -= 0x44u;
    cpu->eax = lift_load32(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x5Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4267B0u); lift_push32(cpu, r); sfera_sub_00494900(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0xAA3u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4267BFu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x200u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4267C9u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"light_pos");
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4267DDu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = native_function_address32(&::sscanf);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00026801;
    cpu->edx = (uint32_t)(cpu->esi + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%f %f %f"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x267FEu), LIFT_CODE_TOKEN_RVA(0x267FCu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4267FEu);
    cpu->esp += 0x14u;
    label_00026801: cpu->eip = LIFT_CODE_TOKEN_VA(0x426801u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"light_color");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42680Eu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00026850;
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%f %f %f %f"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x26831u), LIFT_CODE_TOKEN_RVA(0x2682Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x426831u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0x18u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esi + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esi + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00026850: cpu->eip = LIFT_CODE_TOKEN_VA(0x426850u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"random_color");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42685Du); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000268BB;
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%d %d %d %d %d %d"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x2688Au), LIFT_CODE_TOKEN_RVA(0x26888u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42688Au);
    cpu->eax = lift_load32(cpu->esp + 0x58u);
    cpu->ecx = lift_load32(cpu->esp + 0x5Cu);
    cpu->edx = lift_load32(cpu->esp + 0x60u);
    lift_store32(cpu->esi + 0x38u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x64u);
    lift_store32(cpu->esi + 0x3Cu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x68u);
    lift_store32(cpu->esi + 0x40u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x6Cu);
    cpu->esp += 0x20u;
    lift_store32(cpu->esi + 0x44u, cpu->eax);
    lift_store32(cpu->esi + 0x48u, cpu->ecx);
    lift_store32(cpu->esi + 0x4Cu, cpu->edx);
    lift_store32(cpu->esi + 0x34u, (uint64_t)(lift_load32(cpu->esi + 0x34u)) | (uint64_t)(1u));
    label_000268BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4268BBu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"brightness");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4268C8u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000268E6;
    cpu->eax = (uint32_t)(cpu->esi + 0x54u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x50u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%f %f"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x268DFu), LIFT_CODE_TOKEN_RVA(0x268DDu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4268DFu);
    cpu->esp += 0x10u;
    lift_store32(cpu->esi + 0x34u, (uint64_t)(lift_load32(cpu->esi + 0x34u)) | (uint64_t)(2u));
    label_000268E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4268E6u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"brightFreq");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4268F3u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00026903;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x426900u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esi + 0x58u, cpu->eax & 0xFFu);
    label_00026903: cpu->eip = LIFT_CODE_TOKEN_VA(0x426903u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"attach");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x426910u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00026971;
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x426922u); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00026971;
    lift_push32(cpu, (uintptr_t)"ATTACH_LEFTHAND"); lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::_stricmp);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x26934u), LIFT_CODE_TOKEN_RVA(0x26932u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x426934u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00026941;
    lift_store8(cpu->esi + 0x60u, 1u);
    goto label_00026971;
    label_00026941: cpu->eip = LIFT_CODE_TOKEN_VA(0x426941u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"ATTACH_RIGHTHAND"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x2694Du), LIFT_CODE_TOKEN_RVA(0x2694Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42694Du);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0002695A;
    lift_store8(cpu->esi + 0x60u, 2u);
    goto label_00026971;
    label_0002695A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42695Au);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"ATTACH_BETWEENHANDS"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x26966u), LIFT_CODE_TOKEN_RVA(0x26964u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x426966u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00026971;
    lift_store8(cpu->esi + 0x60u, 3u);
    label_00026971: cpu->eip = LIFT_CODE_TOKEN_VA(0x426971u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"color_track");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x426985u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000269A1;
    lift_push32(cpu, (uintptr_t)"light->color_track"); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42699Eu); lift_push32(cpu, r); sfera_sub_00482CE0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 4u, cpu->eax);
    label_000269A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4269A1u);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"alpha_track");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4269B5u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000269CD;
    lift_push32(cpu, (uintptr_t)"light->alpha_track"); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4269CAu); lift_push32(cpu, r); sfera_sub_00482B00(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 8u, cpu->eax);
    label_000269CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4269CDu);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"position_track");
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4269E1u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000269F8;
    lift_push32(cpu, (uintptr_t)"light->position_track"); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4269F6u); lift_push32(cpu, r); sfera_sub_00482CE0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi, cpu->eax);
    label_000269F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4269F8u);
    cpu->edx = 0xAE6u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_store32(cpu->esi + 0x30u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x426A0Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x426A18u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x426A27u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esp += 0x44u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00426A50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x426A50u);
    cpu->esp -= 0x20u;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    lift_store32(cpu->esp + 0x28u, 0u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(7u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000272B3;
    label_00026A74: cpu->eip = LIFT_CODE_TOKEN_VA(0x426A74u);
    cpu->edi = cpu->eax;
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(1u), 32u);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(7u)) goto label_00027031;
    cpu->ecx = (uint32_t)(cpu->eax + 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x18u, 0u);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x28u)) goto label_00026F26;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 7u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = lift_load16(cpu->esi);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x9Cu);
    cpu->ecx = lift_load16(cpu->esi + ((uint32_t)(cpu->eax) * 2u));
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx = lift_load32(cpu->ecx + cpu->ebp + 0x98u);
    cpu->edx += cpu->ebp;
    cpu->ecx += cpu->ebp;
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    cpu->edx = lift_load32(cpu->edx + 0x98u);
    cpu->edx &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026C0C;
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->edx = lift_load32(cpu->edx + 0x90u);
    cpu->ebx = lift_load32(cpu->ecx + 0x90u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026AFA;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026C14;
    label_00026AFA: cpu->eip = LIFT_CODE_TOKEN_VA(0x426AFAu);
    cpu->edx = (uint32_t)(cpu->eax + cpu->eax);
    cpu->edi = lift_load16(cpu->esi + ((uint32_t)(cpu->edx) * 2u));
    cpu->edx = lift_load32(cpu->ecx + 0x98u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx = lift_load32(cpu->edi + cpu->ebp + 0x98u);
    cpu->edi += cpu->ebp;
    cpu->edx &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026CBC;
    cpu->ecx = lift_load32(cpu->ecx + 0x90u);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(lift_load32(cpu->edi + 0x90u))) goto label_00026CC4;
    label_00026B36: cpu->eip = LIFT_CODE_TOKEN_VA(0x426B36u);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load32(cpu->edx + 0x98u);
    cpu->ebx = lift_load32(cpu->edi + 0x98u);
    cpu->ecx &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026CD1;
    cpu->ecx = lift_load32(cpu->edx + 0x90u);
    cpu->edi = lift_load32(cpu->edi + 0x90u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026B6A;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026CD9;
    label_00026B6A: cpu->eip = LIFT_CODE_TOKEN_VA(0x426B6Au);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    label_00026B6E: cpu->eip = LIFT_CODE_TOKEN_VA(0x426B6Eu);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    label_00026B75: cpu->eip = LIFT_CODE_TOKEN_VA(0x426B75u);
    cpu->ecx = lift_load16(cpu->esi + ((uint32_t)(cpu->edi) * 2u));
    cpu->edx = cpu->edi;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x9Cu);
    cpu->edx -= cpu->eax;
    cpu->ebx = (uint32_t)(cpu->eax + cpu->edi);
    cpu->eax = lift_load16(cpu->esi + ((uint32_t)(cpu->edx) * 2u));
    cpu->edi = lift_load32(cpu->ecx + cpu->ebp + 0x98u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x9Cu);
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + cpu->ebp + 0x98u);
    cpu->ecx += cpu->ebp;
    cpu->eax += cpu->ebp;
    cpu->edx &= 1u;
    cpu->edi &= 1u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026CEA;
    cpu->edx = lift_load32(cpu->eax + 0x90u);
    cpu->edi = lift_load32(cpu->ecx + 0x90u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026BCE;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026CF2;
    label_00026BCE: cpu->eip = LIFT_CODE_TOKEN_VA(0x426BCEu);
    cpu->edi = lift_load16(cpu->esi + ((uint32_t)(cpu->ebx) * 2u));
    cpu->edx = lift_load32(cpu->ecx + 0x98u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx = lift_load32(cpu->edi + cpu->ebp + 0x98u);
    cpu->edi += cpu->ebp;
    cpu->edx &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026D69;
    cpu->ecx = lift_load32(cpu->ecx + 0x90u);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(lift_load32(cpu->edi + 0x90u))) goto label_00026DA5;
    goto label_00026D6D;
    label_00026C0C: cpu->eip = LIFT_CODE_TOKEN_VA(0x426C0Cu);
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_00026AFA;
    label_00026C14: cpu->eip = LIFT_CODE_TOKEN_VA(0x426C14u);
    cpu->edx = (uint32_t)(cpu->eax + cpu->eax);
    cpu->ebx = lift_load16(cpu->esi + ((uint32_t)(cpu->edx) * 2u));
    cpu->edx = lift_load32(cpu->ecx + 0x98u);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx += cpu->ebp;
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ebx + 0x98u);
    cpu->edx &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026C55;
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = lift_load32(cpu->ecx + 0x90u);
    cpu->edx = lift_load32(cpu->ebx + 0x90u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026C66;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026C59;
    goto label_00026C66;
    label_00026C55: cpu->eip = LIFT_CODE_TOKEN_VA(0x426C55u);
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_00026C62;
    label_00026C59: cpu->eip = LIFT_CODE_TOKEN_VA(0x426C59u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    goto label_00026B75;
    label_00026C62: cpu->eip = LIFT_CODE_TOKEN_VA(0x426C62u);
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    label_00026C66: cpu->eip = LIFT_CODE_TOKEN_VA(0x426C66u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load32(cpu->ecx + 0x98u);
    cpu->edx = lift_load32(cpu->ebx + 0x98u);
    cpu->ecx &= 1u;
    cpu->edx &= 1u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026CA7;
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load32(cpu->ecx + 0x90u);
    cpu->edx = lift_load32(cpu->ebx + 0x90u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026CAF;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026B6E;
    lift_store32(cpu->esp + 0x18u, 0u);
    goto label_00026B75;
    label_00026CA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x426CA7u);
    if ((int32_t)(uint32_t)(cpu->ecx) < 0) goto label_00026B6E;
    label_00026CAF: cpu->eip = LIFT_CODE_TOKEN_VA(0x426CAFu);
    lift_store32(cpu->esp + 0x18u, 0u);
    goto label_00026B75;
    label_00026CBC: cpu->eip = LIFT_CODE_TOKEN_VA(0x426CBCu);
    if ((int32_t)(uint32_t)(cpu->edx) <= 0) goto label_00026B36;
    label_00026CC4: cpu->eip = LIFT_CODE_TOKEN_VA(0x426CC4u);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    goto label_00026B75;
    label_00026CD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x426CD1u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_00026B6A;
    label_00026CD9: cpu->eip = LIFT_CODE_TOKEN_VA(0x426CD9u);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x18u, 0u);
    goto label_00026B75;
    label_00026CEA: cpu->eip = LIFT_CODE_TOKEN_VA(0x426CEAu);
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_00026BCE;
    label_00026CF2: cpu->eip = LIFT_CODE_TOKEN_VA(0x426CF2u);
    cpu->edi = lift_load16(cpu->esi + ((uint32_t)(cpu->ebx) * 2u));
    cpu->edx = lift_load32(cpu->ecx + 0x98u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx = lift_load32(cpu->edi + cpu->ebp + 0x98u);
    cpu->edi += cpu->ebp;
    cpu->edx &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026D29;
    cpu->ecx = lift_load32(cpu->ecx + 0x90u);
    cpu->edx = lift_load32(cpu->edi + 0x90u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026D2D;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026DA5;
    goto label_00026D2D;
    label_00026D29: cpu->eip = LIFT_CODE_TOKEN_VA(0x426D29u);
    if ((int32_t)(uint32_t)(cpu->edx) < 0) goto label_00026DA5;
    label_00026D2D: cpu->eip = LIFT_CODE_TOKEN_VA(0x426D2Du);
    cpu->ecx = lift_load32(cpu->eax + 0x98u);
    cpu->edx = lift_load32(cpu->edi + 0x98u);
    cpu->ecx &= 1u;
    cpu->edx &= 1u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026D5B;
    cpu->eax = lift_load32(cpu->eax + 0x90u);
    cpu->edi = lift_load32(cpu->edi + 0x90u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026D55;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026D5F;
    label_00026D55: cpu->eip = LIFT_CODE_TOKEN_VA(0x426D55u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    goto label_00026DA1;
    label_00026D5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x426D5Bu);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_00026D55;
    label_00026D5F: cpu->eip = LIFT_CODE_TOKEN_VA(0x426D5Fu);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    goto label_00026DA5;
    label_00026D69: cpu->eip = LIFT_CODE_TOKEN_VA(0x426D69u);
    if ((int32_t)(uint32_t)(cpu->edx) > 0) goto label_00026DA5;
    label_00026D6D: cpu->eip = LIFT_CODE_TOKEN_VA(0x426D6Du);
    cpu->ecx = lift_load32(cpu->eax + 0x98u);
    cpu->edx = lift_load32(cpu->edi + 0x98u);
    cpu->ecx &= 1u;
    cpu->edx &= 1u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026E45;
    cpu->eax = lift_load32(cpu->eax + 0x90u);
    cpu->edi = lift_load32(cpu->edi + 0x90u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026D9D;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026E4D;
    label_00026D9D: cpu->eip = LIFT_CODE_TOKEN_VA(0x426D9Du);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    label_00026DA1: cpu->eip = LIFT_CODE_TOKEN_VA(0x426DA1u);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    label_00026DA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x426DA5u);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edi = (uint32_t)(cpu->eax + cpu->eax);
    cpu->ecx = cpu->edx;
    cpu->ecx -= cpu->edi;
    cpu->edi = lift_load16(cpu->esi + ((uint32_t)(cpu->ecx) * 2u));
    cpu->edx -= cpu->eax;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x9Cu);
    cpu->eax = lift_load16(cpu->esi + ((uint32_t)(cpu->edx) * 2u));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx = lift_load32(cpu->eax + cpu->ebp + 0x98u);
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edi + cpu->ebp + 0x98u);
    cpu->eax += cpu->ebp;
    cpu->edi += cpu->ebp;
    cpu->ecx &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026E5A;
    cpu->ecx = lift_load32(cpu->edi + 0x90u);
    cpu->ebx = lift_load32(cpu->eax + 0x90u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026DFC;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026E5E;
    label_00026DFC: cpu->eip = LIFT_CODE_TOKEN_VA(0x426DFCu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = lift_load16(cpu->esi + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ecx = lift_load32(cpu->eax + 0x98u);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx += cpu->ebp;
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ebx + 0x98u);
    cpu->ecx &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026EDE;
    cpu->eax = lift_load32(cpu->eax + 0x90u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->ecx + 0x90u))) goto label_00026EE2;
    goto label_00026EEC;
    label_00026E45: cpu->eip = LIFT_CODE_TOKEN_VA(0x426E45u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_00026D9D;
    label_00026E4D: cpu->eip = LIFT_CODE_TOKEN_VA(0x426E4Du);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    goto label_00026DA5;
    label_00026E5A: cpu->eip = LIFT_CODE_TOKEN_VA(0x426E5Au);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_00026DFC;
    label_00026E5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x426E5Eu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = lift_load16(cpu->esi + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ecx = lift_load32(cpu->eax + 0x98u);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx += cpu->ebp;
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    cpu->ebx = lift_load32(cpu->ebx + 0x98u);
    cpu->ecx &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026EA0;
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    cpu->eax = lift_load32(cpu->eax + 0x90u);
    cpu->ecx = lift_load32(cpu->ebx + 0x90u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026EAE;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026EA4;
    goto label_00026EAE;
    label_00026EA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x426EA0u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_00026EAA;
    label_00026EA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x426EA4u);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    goto label_00026F22;
    label_00026EAA: cpu->eip = LIFT_CODE_TOKEN_VA(0x426EAAu);
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    label_00026EAE: cpu->eip = LIFT_CODE_TOKEN_VA(0x426EAEu);
    cpu->eax = lift_load32(cpu->edi + 0x98u);
    cpu->edx = lift_load32(cpu->ebx + 0x98u);
    cpu->eax &= 1u;
    cpu->edx &= 1u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026ED8;
    cpu->edi = lift_load32(cpu->edi + 0x90u);
    cpu->eax = lift_load32(cpu->ebx + 0x90u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026F1A;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026F22;
    goto label_00026F1A;
    label_00026ED8: cpu->eip = LIFT_CODE_TOKEN_VA(0x426ED8u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_00026F22;
    goto label_00026F1A;
    label_00026EDE: cpu->eip = LIFT_CODE_TOKEN_VA(0x426EDEu);
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_00026EE8;
    label_00026EE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x426EE2u);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    goto label_00026F22;
    label_00026EE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x426EE8u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    label_00026EEC: cpu->eip = LIFT_CODE_TOKEN_VA(0x426EECu);
    cpu->eax = lift_load32(cpu->edi + 0x98u);
    cpu->edx = lift_load32(cpu->ecx + 0x98u);
    cpu->eax &= 1u;
    cpu->edx &= 1u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026F16;
    cpu->edi = lift_load32(cpu->edi + 0x90u);
    cpu->ecx = lift_load32(cpu->ecx + 0x90u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026F22;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026F1A;
    goto label_00026F22;
    label_00026F16: cpu->eip = LIFT_CODE_TOKEN_VA(0x426F16u);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00026F22;
    label_00026F1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x426F1Au);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    label_00026F22: cpu->eip = LIFT_CODE_TOKEN_VA(0x426F22u);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    label_00026F26: cpu->eip = LIFT_CODE_TOKEN_VA(0x426F26u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_load16(cpu->esi + ((uint32_t)(cpu->edx) * 2u));
    cpu->eax = lift_load16(cpu->esi + ((uint32_t)(cpu->edi) * 2u));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x9Cu);
    cpu->ecx = lift_load32(cpu->edx + cpu->ebp + 0x98u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx = lift_load32(cpu->eax + cpu->ebp + 0x98u);
    cpu->edx += cpu->ebp;
    cpu->eax += cpu->ebp;
    cpu->ecx &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026FB2;
    cpu->edx = lift_load32(cpu->edx + 0x90u);
    cpu->ecx = lift_load32(cpu->eax + 0x90u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026F70;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026FB6;
    label_00026F70: cpu->eip = LIFT_CODE_TOKEN_VA(0x426F70u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load16(cpu->esi + ((uint32_t)(cpu->edx) * 2u));
    cpu->ecx = lift_load32(cpu->eax + 0x98u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx = lift_load32(cpu->edx + cpu->ebp + 0x98u);
    cpu->edx += cpu->ebp;
    cpu->ecx &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000270DA;
    cpu->eax = lift_load32(cpu->eax + 0x90u);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->edx + 0x90u))) goto label_00027031;
    goto label_000270E2;
    label_00026FB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x426FB2u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_00026F70;
    label_00026FB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x426FB6u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load16(cpu->esi + ((uint32_t)(cpu->edx) * 2u));
    cpu->ecx = lift_load32(cpu->eax + 0x98u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx = lift_load32(cpu->edx + cpu->ebp + 0x98u);
    cpu->edx += cpu->ebp;
    cpu->ecx &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026FF1;
    cpu->eax = lift_load32(cpu->eax + 0x90u);
    cpu->ecx = lift_load32(cpu->edx + 0x90u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026FF5;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00027031;
    goto label_00026FF5;
    label_00026FF1: cpu->eip = LIFT_CODE_TOKEN_VA(0x426FF1u);
    if ((int32_t)(uint32_t)(cpu->ecx) < 0) goto label_00027031;
    label_00026FF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x426FF5u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->eax = lift_load32(cpu->ecx + 0x98u);
    cpu->edi = lift_load32(cpu->edx + 0x98u);
    cpu->eax &= 1u;
    cpu->edi &= 1u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000270C9;
    cpu->eax = lift_load32(cpu->ecx + 0x90u);
    cpu->edx = lift_load32(cpu->edx + 0x90u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000270D1;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000270D1;
    label_0002702D: cpu->eip = LIFT_CODE_TOKEN_VA(0x42702Du);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    label_00027031: cpu->eip = LIFT_CODE_TOKEN_VA(0x427031u);
    cpu->eax = lift_load16(cpu->esi);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esi + ((uint32_t)(cpu->edi) * 2u))) & 0xFFFFu);
    cpu->ebx = lift_load32(cpu->esp + 0x34u);
    lift_store16(cpu->esi, cpu->edx & 0xFFFFu);
    lift_store16(cpu->esi + ((uint32_t)(cpu->edi) * 2u), cpu->eax & 0xFFFFu);
    cpu->edi = 1u;
    --cpu->ebx;
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    label_00027051: cpu->eip = LIFT_CODE_TOKEN_VA(0x427051u);
    if ((int32_t)(uint32_t)(cpu->edi) > (int32_t)(uint32_t)(cpu->ebx)) goto label_0002719E;
    cpu->eax = lift_load16(cpu->esi);
    cpu->ecx = lift_load16(cpu->esi + ((uint32_t)(cpu->edi) * 2u));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x9Cu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x9Cu);
    cpu->edx = lift_load32(cpu->ecx + cpu->ebp + 0x98u);
    cpu->ecx += cpu->ebp;
    cpu->eax += cpu->ebp;
    cpu->ebp = lift_load32(cpu->eax + 0x98u);
    cpu->edx &= 1u;
    cpu->ebp &= 1u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00027128;
    cpu->ecx = lift_load32(cpu->ecx + 0x90u);
    cpu->eax = lift_load32(cpu->eax + 0x90u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0002712C;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000270C2;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->eax = lift_load16(cpu->esi + ((uint32_t)(cpu->edi) * 2u));
    cpu->ecx = lift_load16(cpu->esi + ((uint32_t)(cpu->edx) * 2u));
    lift_store16(cpu->esi + ((uint32_t)(cpu->edx) * 2u), cpu->eax & 0xFFFFu);
    ++cpu->edx;
    lift_store32(cpu->esp + 0x28u, 1u);
    lift_store16(cpu->esi + ((uint32_t)(cpu->edi) * 2u), cpu->ecx & 0xFFFFu);
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    label_000270C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4270C2u);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    ++cpu->edi;
    goto label_00027051;
    label_000270C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4270C9u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0002702D;
    label_000270D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4270D1u);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    goto label_00027031;
    label_000270DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4270DAu);
    if ((int32_t)(uint32_t)(cpu->ecx) > 0) goto label_00027031;
    label_000270E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4270E2u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->eax = lift_load32(cpu->ecx + 0x98u);
    cpu->edi = lift_load32(cpu->edx + 0x98u);
    cpu->eax &= 1u;
    cpu->edi &= 1u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00027117;
    cpu->eax = lift_load32(cpu->ecx + 0x90u);
    cpu->edx = lift_load32(cpu->edx + 0x90u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0002702D;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0002711F;
    goto label_0002702D;
    label_00027117: cpu->eip = LIFT_CODE_TOKEN_VA(0x427117u);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0002702D;
    label_0002711F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42711Fu);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    goto label_00027031;
    label_00027128: cpu->eip = LIFT_CODE_TOKEN_VA(0x427128u);
    if ((int32_t)(uint32_t)(cpu->edx) <= 0) goto label_000270C2;
    label_0002712C: cpu->eip = LIFT_CODE_TOKEN_VA(0x42712Cu);
    if ((int32_t)(uint32_t)(cpu->edi) > (int32_t)(uint32_t)(cpu->ebx)) goto label_0002719A;
    label_00027130: cpu->eip = LIFT_CODE_TOKEN_VA(0x427130u);
    cpu->eax = lift_load16(cpu->esi);
    cpu->ecx = lift_load16(cpu->esi + ((uint32_t)(cpu->ebx) * 2u));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x9Cu);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebp = lift_load32(cpu->eax + cpu->edx + 0x98u);
    cpu->eax += cpu->edx;
    cpu->ecx += cpu->edx;
    cpu->edx = lift_load32(cpu->ecx + 0x98u);
    cpu->edx &= 1u;
    cpu->ebp &= 1u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000271BF;
    cpu->ecx = lift_load32(cpu->ecx + 0x90u);
    cpu->eax = lift_load32(cpu->eax + 0x90u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00027195;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000271C3;
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->eax = lift_load16(cpu->esi + ((uint32_t)(cpu->ebx) * 2u));
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esi + ((uint32_t)(cpu->ecx) * 2u))) & 0xFFFFu);
    lift_store16(cpu->esi + ((uint32_t)(cpu->ebx) * 2u), cpu->edx & 0xFFFFu);
    lift_store16(cpu->esi + ((uint32_t)(cpu->ecx) * 2u), cpu->eax & 0xFFFFu);
    --cpu->ecx;
    lift_store32(cpu->esp + 0x28u, 1u);
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    label_00027195: cpu->eip = LIFT_CODE_TOKEN_VA(0x427195u);
    --cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->edi) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_00027130;
    label_0002719A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42719Au);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    label_0002719E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42719Eu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x28u)) == (uint32_t)(0u)) goto label_00027345;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = cpu->edi;
    cpu->edx -= cpu->ecx;
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->edx)) goto label_000271EA;
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    goto label_000271F0;
    label_000271BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4271BFu);
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_00027195;
    label_000271C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4271C3u);
    if ((int32_t)(uint32_t)(cpu->edi) > (int32_t)(uint32_t)(cpu->ebx)) goto label_0002719A;
    cpu->eax = lift_load16(cpu->esi + ((uint32_t)(cpu->edi) * 2u));
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esi + ((uint32_t)(cpu->ebx) * 2u))) & 0xFFFFu);
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    lift_store16(cpu->esi + ((uint32_t)(cpu->edi) * 2u), cpu->ecx & 0xFFFFu);
    lift_store16(cpu->esi + ((uint32_t)(cpu->ebx) * 2u), cpu->eax & 0xFFFFu);
    ++cpu->edi;
    lift_store32(cpu->esp + 0x28u, 1u);
    --cpu->ebx;
    goto label_00027051;
    label_000271EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4271EAu);
    cpu->ecx = cpu->edx;
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    label_000271F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4271F0u);
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_0002722C;
    cpu->edx = cpu->edi;
    cpu->edx -= cpu->ecx;
    cpu->eax = cpu->esi;
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->edx) * 2u));
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00027200: cpu->eip = LIFT_CODE_TOKEN_VA(0x427200u);
    cpu->edx = lift_load16(cpu->eax);
    lift_store32(cpu->esp + 0x2Cu, cpu->edx);
    cpu->edx = lift_load16(cpu->ecx);
    lift_store16(cpu->eax, cpu->edx & 0xFFFFu);
    cpu->edx = lift_load16(cpu->esp + 0x2Cu);
    lift_store16(cpu->ecx, cpu->edx & 0xFFFFu);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    --cpu->edx;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->edx) > 0) goto label_00027200;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    label_0002722C: cpu->eip = LIFT_CODE_TOKEN_VA(0x42722Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    cpu->ecx -= lift_load32(cpu->esp + 0x24u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->eax -= cpu->ebx;
    --cpu->ecx;
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_00027245;
    cpu->ecx = cpu->eax;
    label_00027245: cpu->eip = LIFT_CODE_TOKEN_VA(0x427245u);
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_00027274;
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    cpu->eax -= cpu->ecx;
    cpu->edi = (uint32_t)(cpu->esi + ((uint32_t)(cpu->edi) * 2u));
    cpu->eax = (uint32_t)(cpu->esi + ((uint32_t)(cpu->eax) * 2u));
    label_00027255: cpu->eip = LIFT_CODE_TOKEN_VA(0x427255u);
    cpu->ebx = lift_load16(cpu->edi);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->eax)) & 0xFFFFu);
    lift_store16(cpu->edi, cpu->edx & 0xFFFFu);
    lift_store16(cpu->eax, cpu->ebx & 0xFFFFu);
    --cpu->ecx;
    cpu->edi += 2u;
    cpu->eax += 2u;
    if ((int32_t)(uint32_t)(cpu->ecx) > 0) goto label_00027255;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    label_00027274: cpu->eip = LIFT_CODE_TOKEN_VA(0x427274u);
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(1u)) goto label_0002728C;
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427288u); lift_push32(cpu, r); sfera_sub_00426A50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    label_0002728C: cpu->eip = LIFT_CODE_TOKEN_VA(0x42728Cu);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(1u)) goto label_000273C9;
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    cpu->ecx -= cpu->eax;
    cpu->esi = (uint32_t)(cpu->esi + ((uint32_t)(cpu->ecx) * 2u));
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_store32(cpu->esp + 0x28u, 0u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(7u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_00026A74;
    label_000272B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4272B3u);
    cpu->edx = 1u;
    lift_store32(cpu->esp + 0x38u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->edx)) goto label_000273C9;
    label_000272C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4272C4u);
    if ((int32_t)(uint32_t)(cpu->edx) <= 0) goto label_0002732E;
    label_000272D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4272D0u);
    cpu->eax = lift_load16(cpu->esi + ((uint32_t)(cpu->edx) * 2u));
    cpu->ecx = lift_load16(cpu->esi + ((uint32_t)(cpu->edx) * 2u) + 0xFFFFFFFEu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx = lift_load32(cpu->eax + cpu->ebp + 0x98u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x9Cu);
    cpu->edi = lift_load32(cpu->ecx + cpu->ebp + 0x98u);
    cpu->edi &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002730F;
    cpu->ecx = lift_load32(cpu->ecx + cpu->ebp + 0x90u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(lift_load32(cpu->eax + cpu->ebp + 0x90u))) goto label_0002732A;
    goto label_00027313;
    label_0002730F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42730Fu);
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_0002732A;
    label_00027313: cpu->eip = LIFT_CODE_TOKEN_VA(0x427313u);
    cpu->eax = lift_load16(cpu->esi + ((uint32_t)(cpu->edx) * 2u));
    cpu->ecx = lift_load16(cpu->esi + ((uint32_t)(cpu->edx) * 2u) + 0xFFFFFFFEu);
    lift_store16(cpu->esi + ((uint32_t)(cpu->edx) * 2u), cpu->ecx & 0xFFFFu);
    lift_store16(cpu->esi + ((uint32_t)(cpu->edx) * 2u) + 0xFFFFFFFEu, cpu->eax & 0xFFFFu);
    --cpu->edx;
    if ((int32_t)(uint32_t)(cpu->edx) > 0) goto label_000272D0;
    label_0002732A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42732Au);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    label_0002732E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42732Eu);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    ++cpu->edx;
    lift_store32(cpu->esp + 0x38u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->eax)) goto label_000272C4;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 8u, stop_address); return;
    label_00027345: cpu->eip = LIFT_CODE_TOKEN_VA(0x427345u);
    cpu->edx = 1u;
    lift_store32(cpu->esp + 0x38u, cpu->edx);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x34u)) <= (int32_t)(uint32_t)(cpu->edx)) goto label_000273C9;
    label_00027358: cpu->eip = LIFT_CODE_TOKEN_VA(0x427358u);
    if ((int32_t)(uint32_t)(cpu->edx) <= 0) goto label_000273BE;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00027360: cpu->eip = LIFT_CODE_TOKEN_VA(0x427360u);
    cpu->eax = lift_load16(cpu->esi + ((uint32_t)(cpu->edx) * 2u));
    cpu->ecx = lift_load16(cpu->esi + ((uint32_t)(cpu->edx) * 2u) + 0xFFFFFFFEu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx = lift_load32(cpu->eax + cpu->ebp + 0x98u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x9Cu);
    cpu->edi = lift_load32(cpu->ecx + cpu->ebp + 0x98u);
    cpu->edi &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002739F;
    cpu->ecx = lift_load32(cpu->ecx + cpu->ebp + 0x90u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(lift_load32(cpu->eax + cpu->ebp + 0x90u))) goto label_000273BA;
    goto label_000273A3;
    label_0002739F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42739Fu);
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_000273BA;
    label_000273A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4273A3u);
    cpu->eax = lift_load16(cpu->esi + ((uint32_t)(cpu->edx) * 2u));
    cpu->ecx = lift_load16(cpu->esi + ((uint32_t)(cpu->edx) * 2u) + 0xFFFFFFFEu);
    lift_store16(cpu->esi + ((uint32_t)(cpu->edx) * 2u), cpu->ecx & 0xFFFFu);
    lift_store16(cpu->esi + ((uint32_t)(cpu->edx) * 2u) + 0xFFFFFFFEu, cpu->eax & 0xFFFFu);
    --cpu->edx;
    if ((int32_t)(uint32_t)(cpu->edx) > 0) goto label_00027360;
    label_000273BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4273BAu);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    label_000273BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4273BEu);
    ++cpu->edx;
    lift_store32(cpu->esp + 0x38u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x34u))) goto label_00027358;
    label_000273C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4273C9u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004273E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4273E0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->edx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42740Eu); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42741Du); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42742Au); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) != (uint32_t)(0x314D5353u)) goto label_00027526;
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) != (uint32_t)(1u)) goto label_00027526;
    cpu->edi = 0u;
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427456u); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427463u); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->edi)) goto label_00027526;
    cpu->ebp = 0u;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->edi)) goto label_00027526;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00027480: cpu->eip = LIFT_CODE_TOKEN_VA(0x427480u);
    cpu->edx = 0x14Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42748Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x58u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427496u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000274B0;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4274ACu); lift_push32(cpu, r); sfera_sub_00483490(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    goto label_000274B2;
    label_000274B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4274B0u);
    cpu->esi = 0u;
    label_000274B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4274B2u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x34u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4274C2u); lift_push32(cpu, r); sfera_sub_004836A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000274F8;
    cpu->eax = g_sfera_effect_manager.particle_resource_head;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edi)) goto label_000274DD;
    g_sfera_effect_manager.particle_resource_head = (uint32_t)(cpu->esi);
    lift_store32(cpu->esi + 0x54u, cpu->edi);
    lift_store32(cpu->esi + 0x50u, cpu->edi);
    goto label_0002751B;
    label_000274DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4274DDu);
    cpu->ecx = lift_load32(cpu->eax + 0x54u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000274ED;
    label_000274E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4274E4u);
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax + 0x54u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edi)) goto label_000274E4;
    label_000274ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4274EDu);
    lift_store32(cpu->eax + 0x54u, cpu->esi);
    lift_store32(cpu->esi + 0x50u, cpu->eax);
    lift_store32(cpu->esi + 0x54u, cpu->edi);
    goto label_0002751B;
    label_000274F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4274F8u);
    cpu->edx = 0x164u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427507u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_0002751B;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427512u); lift_push32(cpu, r); sfera_sub_004834C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427518u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0002751B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42751Bu);
    ++cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_00027480;
    label_00027526: cpu->eip = LIFT_CODE_TOKEN_VA(0x427526u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42752Du); lift_push32(cpu, r); sfera_sub_0042F180(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00427550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x427550u);
    { uint64_t l=(uint64_t)(g_sfera_effect_manager.render_slots.capacity), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00027576;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427568u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_effect_manager.render_slots.data;
    lift_store32(cpu->esi, cpu->eax);
    cpu->eax = g_sfera_effect_manager.render_slot_count;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00027576: cpu->eip = LIFT_CODE_TOKEN_VA(0x427576u);
    cpu->ecx = g_sfera_effect_manager.render_slots.data;
    lift_store32(cpu->esi, cpu->ecx);
    cpu->eax = g_sfera_effect_manager.render_slot_count;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00427590(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x427590u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    std::construct_at(reinterpret_cast<IEffectManager*>(cpu->esi));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000275C0;
    if ((uint8_t)(lift_load8(cpu->esi + 0xCu)) != (uint8_t)(0u)) goto label_000275C0;
    cpu->edx = 0x67Du;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4275B4u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4275BDu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000275C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4275C0u);
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_000275D0;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4275CDu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000275D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4275D0u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004275E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4275E0u);
    cpu->esp -= 0x88u;
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x8Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x48u))));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x4Cu));
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx + 4u))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x50u));
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx + 8u))));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x3Cu))));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x40u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx + 4u))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x44u));
    cpu->eax = lift_load32(cpu->esp);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx + 8u))));
    cpu->ecx = lift_load32(cpu->esp + 4u);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427670u); lift_push32(cpu, r); sfera_sub_004259C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 8u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42767Eu); lift_push32(cpu, r); sfera_sub_0044C370(cpu,r); if (cpu->eip != r) return; }
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->esp += 0x88u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004276A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4276A0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = lift_load32(cpu->edi + 0xA0u);
    lift_store32(cpu->esp + 8u, cpu->esi);
    if ((uint32_t)(cpu->esi) == 0u) goto label_00027724;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x9Cu)) >= (int32_t)(uint32_t)(0x10u)) goto label_00027724;
    cpu->ecx = lift_load32(cpu->edi + 0xB4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000276CB;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x276CBu); lift_push32(cpu, r); sfera_sub_00496870(cpu,r); if (cpu->eip != r) return; }
    label_000276CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4276CBu);
    if ((uint32_t)(lift_load32(cpu->edi + 0xECu)) == (uint32_t)(0u)) goto label_00027710;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = 0u;
    if ((uint32_t)(lift_load32(cpu->edi + 0xBCu)) <= (uint32_t)(cpu->ebp)) goto label_0002770F;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    label_000276E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4276E2u);
    cpu->esi = lift_load32(cpu->edi + 0xECu);
    cpu->ecx = lift_load32(cpu->esi + cpu->ebx + 0xCu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFFFFFFu)) goto label_000276F6;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x276F6u); lift_push32(cpu, r); sfera_sub_004563A0(cpu,r); if (cpu->eip != r) return; }
    label_000276F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4276F6u);
    lift_store32(cpu->esi + cpu->ebx + 0xCu, 0xFFFFFFFFu);
    ++cpu->ebp;
    cpu->ebx += 0x64u;
    if ((uint32_t)(cpu->ebp) < (uint32_t)(lift_load32(cpu->edi + 0xBCu))) goto label_000276E2;
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = lift_pop32(cpu);
    label_0002770F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42770Fu);
    cpu->ebp = lift_pop32(cpu);
    label_00027710: cpu->eip = LIFT_CODE_TOKEN_VA(0x427710u);
    cpu->eax = lift_load32(cpu->esi + 0x9Cu);
    lift_store32(cpu->esi + ((uint32_t)(cpu->eax) * 4u) + 0x5Cu, cpu->edi);
    lift_store32(cpu->esi + 0x9Cu, (uint64_t)(lift_load32(cpu->esi + 0x9Cu)) + 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00027724: cpu->eip = LIFT_CODE_TOKEN_VA(0x427724u);
    cpu->edx = 0x725u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427733u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }

    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<CScriptedEffect*>(cpu->edi)->destroyEffect(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42773Eu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00427750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x427750u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->edi + 0xDu)) != (uint8_t)(0u)) goto label_000277B9;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000277AF;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    if ((uint32_t)(lift_load32(cpu->edi + 0xBCu)) <= (uint32_t)(cpu->ebx)) goto label_0002779A;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = 0u;
    (void)cpu;
    label_00027770: cpu->eip = LIFT_CODE_TOKEN_VA(0x427770u);
    cpu->esi = lift_load32(cpu->edi + 0xECu);
    cpu->ecx = lift_load32(cpu->esi + cpu->ebp + 0xCu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFFFFFFu)) goto label_00027784;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x27784u); lift_push32(cpu, r); sfera_sub_004563A0(cpu,r); if (cpu->eip != r) return; }
    label_00027784: cpu->eip = LIFT_CODE_TOKEN_VA(0x427784u);
    lift_store32(cpu->esi + cpu->ebp + 0xCu, 0xFFFFFFFFu);
    ++cpu->ebx;
    cpu->ebp += 0x64u;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(lift_load32(cpu->edi + 0xBCu))) goto label_00027770;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_0002779A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42779Au);
    cpu->ecx = lift_load32(cpu->edi + 0xB4u);
    cpu->ebx = lift_pop32(cpu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000277AA;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x277AAu); lift_push32(cpu, r); sfera_sub_00496870(cpu,r); if (cpu->eip != r) return; }
    label_000277AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4277AAu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    label_000277AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4277AFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    lift_store8(cpu->edi + 0xEu, cpu->eax & 0xFFu);
    lift_store8(cpu->edi + 0xDu, 1u);
    label_000277B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4277B9u);
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004277C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4277C0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x2Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00027850;
    if ((uint32_t)(lift_load32(cpu->esi)) == (uint32_t)(0u)) goto label_000277F8;
    cpu->edx = 0xA3Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4277E2u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000277F8;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4277EFu); lift_push32(cpu, r); sfera_sub_0042D100(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4277F5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000277F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4277F8u);
    if ((uint32_t)(lift_load32(cpu->esi + 4u)) == (uint32_t)(0u)) goto label_00027824;
    cpu->edx = 0xA3Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42780Du); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00027824;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42781Bu); lift_push32(cpu, r); sfera_sub_0042D100(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427821u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00027824: cpu->eip = LIFT_CODE_TOKEN_VA(0x427824u);
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) == (uint32_t)(0u)) goto label_00027850;
    cpu->edx = 0xA40u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427839u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00027850;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427847u); lift_push32(cpu, r); sfera_sub_0042D100(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42784Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00027850: cpu->eip = LIFT_CODE_TOKEN_VA(0x427850u);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->edi |= 0xFFFFFFFFu;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0002785F;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2785Fu); lift_push32(cpu, r); sfera_sub_004563A0(cpu,r); if (cpu->eip != r) return; }
    label_0002785F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42785Fu);
    lift_store32(cpu->esi + 0xCu, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00427870(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x427870u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFFFFFFu)) goto label_00027887;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427880u); lift_push32(cpu, r); sfera_sub_004563A0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xCu, 0xFFFFFFFFu);
    label_00027887: cpu->eip = LIFT_CODE_TOKEN_VA(0x427887u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_x87_push(cpu, 0.0);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->esp -= 0x14u;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->ecx = lift_load32(cpu->ecx + 0xCu);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4278CAu); lift_push32(cpu, r); sfera_sub_004562D0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004278E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4278E0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebp + 0x9Cu);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_0002793B;
    --cpu->eax;
    lift_store32(cpu->ebp + 0x9Cu, cpu->eax);
    cpu->ebp = lift_load32(cpu->ebp + ((uint32_t)(cpu->eax) * 4u) + 0x5Cu);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427925u); lift_push32(cpu, r); sfera_sub_004261C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->ebp;
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 0u, stop_address); return;
    label_0002793B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42793Bu);
    cpu->edx = 0x803u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42794Au); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427954u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00027966;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427962u); lift_push32(cpu, r); sfera_sub_00425FA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    goto label_00027968;
    label_00027966: cpu->eip = LIFT_CODE_TOKEN_VA(0x427966u);
    cpu->ebx = 0u;
    label_00027968: cpu->eip = LIFT_CODE_TOKEN_VA(0x427968u);
    lift_store8(cpu->ebx + 0xCu, 1u);
    cpu->eax = lift_load32(cpu->ebp + 0xA4u);
    lift_store32(cpu->ebx + 0xA4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xC0u);
    lift_store32(cpu->ebx + 0xC0u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0xB8u);
    lift_store32(cpu->ebx + 0xB8u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 0xC4u);
    lift_store32(cpu->ebx + 0xC4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xCCu);
    lift_store32(cpu->ebx + 0xCCu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0xC8u);
    lift_store32(cpu->ebx + 0xC8u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_store32(cpu->ebx + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->ebx + 8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0xBCu);
    lift_store32(cpu->ebx + 0xBCu, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    lift_store32(cpu->ebx + 0x10u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0x14u);
    lift_store32(cpu->ebx + 0x14u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0xACu);
    lift_store32(cpu->ebx + 0xACu, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x1Cu));
    lift_store_f32(cpu->ebx + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi |= 0xFFFFFFFFu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x18u));
    lift_store_f32(cpu->ebx + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->ebp + 0xD4u);
    lift_store32(cpu->ebx + 0xD4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xD8u);
    lift_store32(cpu->ebx + 0xD8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0xDCu);
    lift_store32(cpu->ebx + 0xDCu, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 0xE0u);
    lift_store32(cpu->ebx + 0xE0u, cpu->eax);
    lift_store32(cpu->ebx + 0xA0u, cpu->ebp);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp + 0x54u)) & 0xFFu);
    lift_store8(cpu->ebx + 0x54u, cpu->ecx & 0xFFu);
    cpu->edx = lift_load32(cpu->ebp + 0x3Cu);
    lift_store32(cpu->ebx + 0x3Cu, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 0x40u);
    lift_store32(cpu->ebx + 0x40u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0x44u);
    lift_store32(cpu->ebx + 0x44u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0x48u);
    lift_store32(cpu->ebx + 0x48u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 0x4Cu);
    lift_store32(cpu->ebx + 0x4Cu, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0x50u);
    lift_store32(cpu->ebx + 0x50u, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebp + 0xB0u);
    lift_store32(cpu->ebx + 0xB0u, cpu->edx);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xD4u)) == (uint32_t)(cpu->edi)) goto label_00027AC2;
    cpu->esi = native_function_address32(&::rand);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x27A6Fu), LIFT_CODE_TOKEN_RVA(0x27A6Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x427A6Fu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x80000001u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00027A7B;
    --cpu->eax;
    cpu->eax |= 0xFFFFFFFEu;
    { uint64_t l=(uint64_t)(cpu->eax), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    label_00027A7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x427A7Bu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00027A87;
    lift_store32(cpu->ebx + 0xE4u, 1u);
    label_00027A87: cpu->eip = LIFT_CODE_TOKEN_VA(0x427A87u);
    if ((uint32_t)(lift_load32(cpu->ebx + 0xE4u)) != (uint32_t)(0u)) goto label_00027AA5;
    if ((uint32_t)(lift_load32(cpu->ebp + 0xD8u)) <= (uint32_t)(0u)) goto label_00027ABA;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x27A9Bu), LIFT_CODE_TOKEN_RVA(0x27A99u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x427A9Bu);
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, lift_load32(cpu->ebp + 0xD8u), 32u, 0u);
    goto label_00027ABC;
    label_00027AA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x427AA5u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xE0u)) <= (uint32_t)(0u)) goto label_00027ABA;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x27AB0u), LIFT_CODE_TOKEN_RVA(0x27AAEu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x427AB0u);
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, lift_load32(cpu->ebp + 0xE0u), 32u, 0u);
    goto label_00027ABC;
    label_00027ABA: cpu->eip = LIFT_CODE_TOKEN_VA(0x427ABAu);
    cpu->edx = 0u;
    label_00027ABC: cpu->eip = LIFT_CODE_TOKEN_VA(0x427ABCu);
    lift_store32(cpu->ebx + 0xD0u, cpu->edx);
    label_00027AC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x427AC2u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xB4u)) == (uint32_t)(0u)) goto label_00027B1A;
    cpu->edx = 0x829u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427ADAu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xC0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427AE4u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x2Cu, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00027B00;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427AFEu); lift_push32(cpu, r); sfera_sub_00495B30(cpu,r); if (cpu->eip != r) return; }
    goto label_00027B02;
    label_00027B00: cpu->eip = LIFT_CODE_TOKEN_VA(0x427B00u);
    cpu->eax = 0u;
    label_00027B02: cpu->eip = LIFT_CODE_TOKEN_VA(0x427B02u);
    lift_store32(cpu->ebx + 0xB4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->ebp + 0xB4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x27B1Au); lift_push32(cpu, r); sfera_sub_004968C0(cpu,r); if (cpu->eip != r) return; }
    label_00027B1A: cpu->eip = LIFT_CODE_TOKEN_VA(0x427B1Au);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xBCu)) <= (uint32_t)(0u)) goto label_00027BE4;
    cpu->edx = 0x82Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427B36u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->ebp + 0xBCu);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->esi;
    cpu->edx = 0x64u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->eax |= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427B60u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x2Cu, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00027B8D;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004277C0)); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00426710)); lift_push32(cpu, cpu->esi);
    cpu->edi = (uint32_t)(cpu->eax + 4u);
    lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->eax, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427B8Bu); lift_push32(cpu, r); sfera_sub_004EEBE9(cpu,r); if (cpu->eip != r) return; }
    goto label_00027B8F;
    label_00027B8D: cpu->eip = LIFT_CODE_TOKEN_VA(0x427B8Du);
    cpu->edi = 0u;
    label_00027B8F: cpu->eip = LIFT_CODE_TOKEN_VA(0x427B8Fu);
    lift_store32(cpu->ebx + 0xECu, cpu->edi);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xBCu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x2Cu, 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_00027BE4;
    cpu->edx = 0u;
    label_00027BB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x427BB0u);
    cpu->eax = lift_load32(cpu->ebx + 0xECu);
    cpu->esi = lift_load32(cpu->ebp + 0xECu);
    cpu->eax += cpu->edx;
    cpu->esi += cpu->edx;
    cpu->edi = cpu->eax;
    cpu->ecx = 0x19u;
    lift_movs32(cpu, 1u);
    lift_store32(cpu->eax + 0x2Cu, 1u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    ++cpu->eax;
    cpu->edx += 0x64u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->ebp + 0xBCu))) goto label_00027BB0;
    label_00027BE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x427BE4u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xB8u)) <= (uint32_t)(0u)) goto label_00027CD4;
    cpu->edx = 0x83Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427C00u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->ebp + 0xB8u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->esi;
    cpu->edx = 0x9Cu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->eax |= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427C2Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x2Cu, 2u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00027C5A;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00483920)); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00483880)); lift_push32(cpu, cpu->esi);
    cpu->edi = (uint32_t)(cpu->eax + 4u);
    lift_push32(cpu, 0x9Cu); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->eax, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427C58u); lift_push32(cpu, r); sfera_sub_004EEBE9(cpu,r); if (cpu->eip != r) return; }
    goto label_00027C5C;
    label_00027C5A: cpu->eip = LIFT_CODE_TOKEN_VA(0x427C5Au);
    cpu->edi = 0u;
    label_00027C5C: cpu->eip = LIFT_CODE_TOKEN_VA(0x427C5Cu);
    lift_store32(cpu->ebx + 0xE8u, cpu->edi);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xB8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x2Cu, 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x18u, 0u);
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_00027CD4;
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    goto label_00027C94;
    label_00027C90: cpu->eip = LIFT_CODE_TOKEN_VA(0x427C90u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    label_00027C94: cpu->eip = LIFT_CODE_TOKEN_VA(0x427C94u);
    cpu->eax = lift_load32(cpu->ebx + 0xE8u);
    cpu->esi = lift_load32(cpu->ebp + 0xE8u);
    cpu->eax += cpu->ecx;
    cpu->esi += cpu->ecx;
    cpu->edi = cpu->eax;
    cpu->ecx = 0x27u;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->eax + 0x34u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427CBBu); lift_push32(cpu, r); sfera_sub_00483B00(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(0x9Cu) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->ebp + 0xB8u))) goto label_00027C90;
    label_00027CD4: cpu->eip = LIFT_CODE_TOKEN_VA(0x427CD4u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xC4u)) <= (uint32_t)(0u)) goto label_00027E1F;
    cpu->edx = 0x84Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427CF0u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->ebp + 0xC4u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->esi;
    cpu->edx = 0x19Cu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->eax |= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427D1Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x2Cu, 3u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00027D4A;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00483F50)); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00486390)); lift_push32(cpu, cpu->esi);
    cpu->edi = (uint32_t)(cpu->eax + 4u);
    lift_push32(cpu, 0x19Cu); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->eax, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427D48u); lift_push32(cpu, r); sfera_sub_004EEBE9(cpu,r); if (cpu->eip != r) return; }
    goto label_00027D4C;
    label_00027D4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x427D4Au);
    cpu->edi = 0u;
    label_00027D4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x427D4Cu);
    lift_store32(cpu->ebx + 0xF0u, cpu->edi);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0xC4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x2Cu, 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x1Cu, 0u);
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_00027E1F;
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    goto label_00027D84;
    label_00027D80: cpu->eip = LIFT_CODE_TOKEN_VA(0x427D80u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    label_00027D84: cpu->eip = LIFT_CODE_TOKEN_VA(0x427D84u);
    cpu->edi = lift_load32(cpu->ebx + 0xF0u);
    cpu->esi = lift_load32(cpu->ebp + 0xF0u);
    cpu->edi += cpu->eax;
    cpu->esi += cpu->eax;
    cpu->ecx = 0x67u;
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    lift_movs32(cpu, 1u);
    cpu->edx = 0x858u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427DB2u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->ecx + 0x5Cu);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 0x50u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427DCFu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x24u);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->ecx = lift_load32(cpu->edx + 0x5Cu);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x427DE9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x427DEEu);
    cpu->esp += 0x10u;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 0x198u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427E02u); lift_push32(cpu, r); sfera_sub_00484440(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(0x19Cu) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->ebp + 0xC4u))) goto label_00027D80;
    label_00027E1F: cpu->eip = LIFT_CODE_TOKEN_VA(0x427E1Fu);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xC8u)) <= (uint32_t)(0u)) goto label_00027EED;
    if ((uint32_t)(lift_load32(cpu->ebp + 0xCCu)) <= (uint32_t)(0u)) goto label_00027EED;
    cpu->edx = 0x864u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427E48u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->ebp + 0xC8u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->esi;
    cpu->edx = 0x19Cu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->eax |= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427E72u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x2Cu, 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00027EA2;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00483F50)); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00486390)); lift_push32(cpu, cpu->esi);
    cpu->edi = (uint32_t)(cpu->eax + 4u);
    lift_push32(cpu, 0x19Cu); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->eax, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427EA0u); lift_push32(cpu, r); sfera_sub_004EEBE9(cpu,r); if (cpu->eip != r) return; }
    goto label_00027EA4;
    label_00027EA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x427EA2u);
    cpu->edi = 0u;
    label_00027EA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x427EA4u);
    cpu->edx = 0x865u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_store32(cpu->esp + 0x2Cu, 0xFFFFFFFFu);
    lift_store32(cpu->ebx + 0xF8u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427EC1u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0xCCu);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 0x50u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427EDDu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->ebx + 0xF4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x27EEDu); lift_push32(cpu, r); sfera_sub_00426440(cpu,r); if (cpu->eip != r) return; }
    label_00027EED: cpu->eip = LIFT_CODE_TOKEN_VA(0x427EEDu);
    cpu->eax = cpu->ebx;
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00427F10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x427F10u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x124u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x138u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = lift_load32(cpu->esp + 0x148u);
    cpu->esi = cpu->ecx;
    cpu->edx = 0x920u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427F67u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x420u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427F71u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x140u, cpu->ebp);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_00027F8E;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427F8Cu); lift_push32(cpu, r); sfera_sub_00493BF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    label_00027F8E: cpu->eip = LIFT_CODE_TOKEN_VA(0x427F8Eu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esp + 0x144u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427FA1u); lift_push32(cpu, r); sfera_sub_00494940(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"effectmesh_def");
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esi + 0x58u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427FB6u); lift_push32(cpu, r); sfera_sub_00494030(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_000280C5;
    cpu->edx = 0x92Cu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_store32(cpu->esi + 0xB8u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427FD5u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->edi;
    cpu->edx = 0x9Cu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->eax |= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x427FF9u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x140u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00028032;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00483920)); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00483880)); lift_push32(cpu, cpu->edi);
    cpu->ebx = (uint32_t)(cpu->eax + 4u);
    lift_push32(cpu, 0x9Cu); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->eax, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42802Au); lift_push32(cpu, r); sfera_sub_004EEBE9(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_load32(cpu->esp + 0x28u);
    goto label_00028034;
    label_00028032: cpu->eip = LIFT_CODE_TOKEN_VA(0x428032u);
    cpu->eax = 0u;
    label_00028034: cpu->eip = LIFT_CODE_TOKEN_VA(0x428034u);
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esp + 0x144u, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0xE8u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42804Eu); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"effectmesh_def");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42805Fu); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000280BE;
    cpu->edi = 0u;
    label_00028065: cpu->eip = LIFT_CODE_TOKEN_VA(0x428065u);
    cpu->ecx = lift_load32(cpu->esi + 0xE8u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    cpu->ecx += cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428079u); lift_push32(cpu, r); sfera_sub_00485AF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00028093;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"CScriptedEffect::LoadScript(%s) -> Can't load effectmesh_def block");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428088u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42808Eu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    goto label_000280A3;
    label_00028093: cpu->eip = LIFT_CODE_TOKEN_VA(0x428093u);
    cpu->ecx = lift_load32(cpu->esi + 0xE8u);
    cpu->ecx += cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4280A0u); lift_push32(cpu, r); sfera_sub_00483F40(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x58u, (uint64_t)(lift_load32(cpu->esi + 0x58u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    label_000280A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4280A3u);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"effectmesh_def");
    cpu->ecx = cpu->ebp;
    cpu->edi += 0x9Cu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4280BAu); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00028065;
    label_000280BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4280BEu);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x280C5u); lift_push32(cpu, r); sfera_sub_004948B0(cpu,r); if (cpu->eip != r) return; }
    label_000280C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4280C5u);
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"psystem_def");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4280D3u); lift_push32(cpu, r); sfera_sub_00494030(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_00028207;
    cpu->edx = 0x943u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_store32(cpu->esi + 0xC4u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4280F2u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->edi;
    cpu->edx = 0x19Cu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->eax |= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428116u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x140u, 2u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002814F;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00483F50)); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00486390)); lift_push32(cpu, cpu->edi);
    cpu->ebx = (uint32_t)(cpu->eax + 4u);
    lift_push32(cpu, 0x19Cu); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->eax, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428147u); lift_push32(cpu, r); sfera_sub_004EEBE9(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_load32(cpu->esp + 0x28u);
    goto label_00028151;
    label_0002814F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42814Fu);
    cpu->eax = 0u;
    label_00028151: cpu->eip = LIFT_CODE_TOKEN_VA(0x428151u);
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esp + 0x144u, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0xF0u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42816Bu); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"psystem_def");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42817Cu); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00028200;
    cpu->edi = 0u;
    label_00028186: cpu->eip = LIFT_CODE_TOKEN_VA(0x428186u);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428192u); lift_push32(cpu, r); sfera_sub_00494900(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xF0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    cpu->ecx += cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4281A6u); lift_push32(cpu, r); sfera_sub_00487D50(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000281C0;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"CScriptedEffect::LoadScript(%s) -> Can't load psystem_def block");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4281B5u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4281BBu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    goto label_000281D9;
    label_000281C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4281C0u);
    cpu->ecx = lift_load32(cpu->esi + 0xF0u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + cpu->ecx + 0x18Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->edi + cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000281D9;
    cpu->edx = lift_load32(cpu->eax + 0x5Cu);
    lift_store32(cpu->esi + 0x58u, (uint64_t)(lift_load32(cpu->esi + 0x58u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    label_000281D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4281D9u);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    cpu->edi += 0x19Cu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4281EBu); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"psystem_def");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4281FCu); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00028186;
    label_00028200: cpu->eip = LIFT_CODE_TOKEN_VA(0x428200u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x28207u); lift_push32(cpu, r); sfera_sub_004948B0(cpu,r); if (cpu->eip != r) return; }
    label_00028207: cpu->eip = LIFT_CODE_TOKEN_VA(0x428207u);
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0xC8u, cpu->eax);
    lift_store32(cpu->esi + 0xCCu, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->esi + 0xC4u)) <= (uint32_t)(cpu->eax)) goto label_000282D2;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00028230: cpu->eip = LIFT_CODE_TOKEN_VA(0x428230u);
    cpu->edi = lift_load32(cpu->esi + 0xF0u);
    cpu->edi += lift_load32(cpu->esp + 0x24u);
    cpu->eax = lift_load32(cpu->edi + 0x18Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000282B5;
    lift_store32(cpu->esp + 0x20u, 0u);
    cpu->ebx = 0u;
    cpu->edi = cpu->edi;
    label_00028250: cpu->eip = LIFT_CODE_TOKEN_VA(0x428250u);
    cpu->edx = lift_load32(cpu->edi + 0x188u);
    cpu->eax = lift_load32(cpu->edx + cpu->ebx);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428261u); lift_push32(cpu, r); sfera_sub_004260F0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000282A1;
    cpu->ecx = lift_load32(cpu->edi + 0x188u);
    lift_store32(cpu->ecx + cpu->ebx + 0x10u, cpu->eax);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x19Cu);
    cpu->edx = lift_load32(cpu->edi + 0x188u);
    cpu->ecx = lift_load32(cpu->edx + cpu->ebx + 4u);
    lift_store32(cpu->esi + 0xC8u, (uint64_t)(lift_load32(cpu->esi + 0xC8u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    cpu->edx = lift_load32(cpu->esi + 0xF0u);
    cpu->ecx = lift_load32(cpu->edi + 0x188u);
    cpu->edx = lift_load32(cpu->eax + cpu->edx + 0x5Cu);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(lift_load32(cpu->ecx + cpu->ebx + 4u));
    lift_store32(cpu->esi + 0xCCu, (uint64_t)(lift_load32(cpu->esi + 0xCCu)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    label_000282A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4282A1u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    ++cpu->eax;
    cpu->ebx += 0x14u;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->edi + 0x18Cu))) goto label_00028250;
    label_000282B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4282B5u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x24u, (uint64_t)(lift_load32(cpu->esp + 0x24u)) + (uint64_t)(0x19Cu) + (uint64_t)(0u));
    ++cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->esi + 0xC4u))) goto label_00028230;
    label_000282D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4282D2u);
    if ((uint32_t)(lift_load32(cpu->esi + 0xC8u)) <= (uint32_t)(0u)) goto label_000283AF;
    if ((uint32_t)(lift_load32(cpu->esi + 0xCCu)) <= (uint32_t)(0u)) goto label_000283AF;
    cpu->edx = 0x973u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4282FBu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0xC8u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->edi;
    cpu->edx = 0x19Cu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->eax |= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428325u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x140u, 3u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00028358;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00483F50)); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00486390)); lift_push32(cpu, cpu->edi);
    cpu->ebx = (uint32_t)(cpu->eax + 4u);
    lift_push32(cpu, 0x19Cu); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->eax, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428356u); lift_push32(cpu, r); sfera_sub_004EEBE9(cpu,r); if (cpu->eip != r) return; }
    goto label_0002835A;
    label_00028358: cpu->eip = LIFT_CODE_TOKEN_VA(0x428358u);
    cpu->ebx = 0u;
    label_0002835A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42835Au);
    cpu->edx = 0x974u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_store32(cpu->esp + 0x140u, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0xF8u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42837Au); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xCCu);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 0x50u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428396u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xF4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0xCCu);
    lift_store32(cpu->esi + 0x58u, (uint64_t)(lift_load32(cpu->esi + 0x58u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x283AFu); lift_push32(cpu, r); sfera_sub_00426440(cpu,r); if (cpu->eip != r) return; }
    label_000283AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4283AFu);
    lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"effect_def");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4283C4u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000289BE;
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"effect_name");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4283DDu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000283FF;
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4283EFu); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000283FF;
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x283FFu); lift_push32(cpu, r); sfera_sub_00425EB0(cpu,r); if (cpu->eip != r) return; }
    label_000283FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4283FFu);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"effect_number");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428410u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00028420;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42841Du); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 8u, cpu->eax);
    label_00028420: cpu->eip = LIFT_CODE_TOKEN_VA(0x428420u);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"effect_time");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428431u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00028444;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42843Eu); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    label_00028444: cpu->eip = LIFT_CODE_TOKEN_VA(0x428444u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"effect_timelimit");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428455u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00028465;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428462u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    label_00028465: cpu->eip = LIFT_CODE_TOKEN_VA(0x428465u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"updvisible_only");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428476u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000284AA;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428483u); lift_push32(cpu, r); sfera_sub_00494710(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xACu, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000284AA;
    lift_push32(cpu, 0x98Du); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4284A1u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4284A7u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_000284AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4284AAu);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"boundbox");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4284BBu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000284F2;
    cpu->ecx = (uint32_t)(cpu->esi + 0x44u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0x40u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x50u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0x4Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x48u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x10u);
    lift_push32(cpu, (uintptr_t)"%f %f %f %f %f %f"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4284E0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4284E6u);
    cpu->esp += 0x20u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(6u)) goto label_000284F2;
    lift_store8(cpu->esi + 0x54u, 1u);
    label_000284F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4284F2u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"daytime_work");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428503u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002857E;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428510u); lift_push32(cpu, r); sfera_sub_004942C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42851Du); lift_push32(cpu, r); sfera_sub_004942C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 24.0);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0002853E;
    lift_x87_set(cpu, 2u, (lift_x87_get(cpu, 2u)) / (lift_x87_get(cpu, 0u)));
    label_0002853E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42853Eu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esi + 0x18u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 3u));
    LIFT_X87_POP_STATUS_AX();
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00028562;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    goto label_00028566;
    label_00028562: cpu->eip = LIFT_CODE_TOKEN_VA(0x428562u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_00028566: cpu->eip = LIFT_CODE_TOKEN_VA(0x428566u);
    lift_x87_push(cpu, 1.0);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0002857E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42857Eu);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"worktime");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42858Fu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000285B1;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42859Cu); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esi + 0xD4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4285ABu); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xD8u, cpu->eax);
    label_000285B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4285B1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"sleeptime");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4285C2u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000285E4;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4285CFu); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esi + 0xDCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4285DEu); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xE0u, cpu->eax);
    label_000285E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4285E4u);
    lift_push32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"sound_def");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4285FCu); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00028693;
    cpu->edx = 0x9B6u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428613u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xC0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42861Du); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x140u, 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002863C;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42863Au); lift_push32(cpu, r); sfera_sub_00495B30(cpu,r); if (cpu->eip != r) return; }
    goto label_0002863E;
    label_0002863C: cpu->eip = LIFT_CODE_TOKEN_VA(0x42863Cu);
    cpu->eax = 0u;
    label_0002863E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42863Eu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x148u, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0xB4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42865Cu); lift_push32(cpu, r); sfera_sub_00495F40(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00028693;
    cpu->edx = 0x9BCu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42866Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0xB4u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00028689;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428680u); lift_push32(cpu, r); sfera_sub_00496F00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428686u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00028689: cpu->eip = LIFT_CODE_TOKEN_VA(0x428689u);
    lift_store32(cpu->esi + 0xB4u, 0u);
    label_00028693: cpu->eip = LIFT_CODE_TOKEN_VA(0x428693u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"light_def");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4286A4u); lift_push32(cpu, r); sfera_sub_00494030(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_0002879C;
    cpu->edx = 0x9C6u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_store32(cpu->esi + 0xBCu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4286C3u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->edi;
    cpu->edx = 0x64u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->eax |= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4286E7u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x140u, 5u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00028717;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004277C0)); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00426710)); lift_push32(cpu, cpu->edi);
    cpu->ebx = (uint32_t)(cpu->eax + 4u);
    lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->eax, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428715u); lift_push32(cpu, r); sfera_sub_004EEBE9(cpu,r); if (cpu->eip != r) return; }
    goto label_00028719;
    label_00028717: cpu->eip = LIFT_CODE_TOKEN_VA(0x428717u);
    cpu->ebx = 0u;
    label_00028719: cpu->eip = LIFT_CODE_TOKEN_VA(0x428719u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esp + 0x144u, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0xECu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428736u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"light_def");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428747u); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00028795;
    cpu->ebx = lift_load32(cpu->esp + 0x28u);
    cpu->edi = 0u;
    label_00028751: cpu->eip = LIFT_CODE_TOKEN_VA(0x428751u);
    cpu->ecx = lift_load32(cpu->esi + 0xECu);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->ecx += cpu->edi;
    lift_push32(cpu, cpu->ebx);
    cpu->edi += 0x64u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428768u); lift_push32(cpu, r); sfera_sub_00426780(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00028780;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"CScriptedEffect::LoadScript(%s) -> Can't load light_def block");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428777u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42877Du); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_00028780: cpu->eip = LIFT_CODE_TOKEN_VA(0x428780u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"light_def");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428791u); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00028751;
    label_00028795: cpu->eip = LIFT_CODE_TOKEN_VA(0x428795u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2879Cu); lift_push32(cpu, r); sfera_sub_004948B0(cpu,r); if (cpu->eip != r) return; }
    label_0002879C: cpu->eip = LIFT_CODE_TOKEN_VA(0x42879Cu);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"effftype");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4287ADu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000287C0;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4287BAu); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xB0u, cpu->eax);
    label_000287C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4287C0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"subeffects_num");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4287D1u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000287E4;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4287DEu); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xC0u, cpu->eax);
    label_000287E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4287E4u);
    if ((uint32_t)(lift_load32(cpu->esi + 0xC0u)) <= (uint32_t)(0u)) goto label_000289BE;
    cpu->edx = 0x9DEu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428800u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xC0u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 4u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42881Cu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xC0u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 0xA4u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x428830u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x428835u);
    cpu->esp += 0x10u;
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428844u); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"subeffect");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428850u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000289B7;
    cpu->ebx = native_function_address32(&::_stricmp);
    cpu->edi = cpu->edi;
    label_00028860: cpu->eip = LIFT_CODE_TOKEN_VA(0x428860u);
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428869u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428879u); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002890F;
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, (uintptr_t)"EFF_MESH"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x2888Du), LIFT_CODE_TOKEN_RVA(0x2888Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42888Du);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000288C9;
    cpu->edx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 2u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4288A2u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002890F;
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4288B2u); lift_push32(cpu, r); sfera_sub_00426080(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xA4u);
    lift_store16(cpu->ecx + ((uint32_t)(cpu->edi) * 4u), cpu->eax & 0xFFFFu);
    cpu->edx = lift_load32(cpu->esi + 0xA4u);
    lift_store8(cpu->edx + ((uint32_t)(cpu->edi) * 4u) + 2u, 1u);
    goto label_0002890F;
    label_000288C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4288C9u);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, (uintptr_t)"EFF_PSYSTEM"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x288D5u), LIFT_CODE_TOKEN_RVA(0x288D3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4288D5u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0002890F;
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 2u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4288EAu); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002890F;
    cpu->edx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4288FAu); lift_push32(cpu, r); sfera_sub_004260F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xA4u);
    lift_store16(cpu->ecx + ((uint32_t)(cpu->edi) * 4u), cpu->eax & 0xFFFFu);
    cpu->edx = lift_load32(cpu->esi + 0xA4u);
    lift_store8(cpu->edx + ((uint32_t)(cpu->edi) * 4u) + 2u, 0u);
    label_0002890F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42890Fu);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 3u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42891Du); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000289A3;
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, (uintptr_t)"ATTACH_LEFTHAND"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x28931u), LIFT_CODE_TOKEN_RVA(0x2892Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x428931u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00028945;
    cpu->edx = lift_load32(cpu->esi + 0xA4u);
    lift_store8(cpu->edx + ((uint32_t)(cpu->edi) * 4u) + 3u, 1u);
    goto label_000289A3;
    label_00028945: cpu->eip = LIFT_CODE_TOKEN_VA(0x428945u);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, (uintptr_t)"ATTACH_RIGHTHAND"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x28951u), LIFT_CODE_TOKEN_RVA(0x2894Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x428951u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00028965;
    cpu->ecx = lift_load32(cpu->esi + 0xA4u);
    lift_store8(cpu->ecx + ((uint32_t)(cpu->edi) * 4u) + 3u, 2u);
    goto label_000289A3;
    label_00028965: cpu->eip = LIFT_CODE_TOKEN_VA(0x428965u);
    cpu->edx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, (uintptr_t)"ATTACH_BETWEENHANDS"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x28971u), LIFT_CODE_TOKEN_RVA(0x2896Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x428971u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00028985;
    cpu->eax = lift_load32(cpu->esi + 0xA4u);
    lift_store8(cpu->eax + ((uint32_t)(cpu->edi) * 4u) + 3u, 3u);
    goto label_000289A3;
    label_00028985: cpu->eip = LIFT_CODE_TOKEN_VA(0x428985u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, (uintptr_t)"ATTACH_SWORD"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x28991u), LIFT_CODE_TOKEN_RVA(0x2898Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x428991u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000289A3;
    cpu->edx = lift_load32(cpu->esi + 0xA4u);
    lift_store8(cpu->edx + ((uint32_t)(cpu->edi) * 4u) + 3u, 4u);
    label_000289A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4289A3u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"subeffect");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4289AFu); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00028860;
    label_000289B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4289B7u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x289BEu); lift_push32(cpu, r); sfera_sub_004945B0(cpu,r); if (cpu->eip != r) return; }
    label_000289BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4289BEu);
    cpu->edx = 0xA10u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4289CDu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->ebp) == 0u) goto label_000289E1;
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4289D8u); lift_push32(cpu, r); sfera_sub_00493C00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4289DEu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000289E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4289E1u);
    cpu->eax = 1u;
    cpu->ecx = lift_load32(cpu->esp + 0x138u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x130u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00428A10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x428A10u);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi |= 0xFFFFFFFFu;
    if ((uint32_t)(lift_load32(cpu->esi + 0x30u)) == (uint32_t)(0u)) goto label_00028A30;
    if ((uint32_t)(lift_load32(cpu->esi + 0xCu)) != (uint32_t)(cpu->edi)) goto label_00028A48;
    label_00028A30: cpu->eip = LIFT_CODE_TOKEN_VA(0x428A30u);
    cpu->eax = (uint32_t)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428A3Fu); lift_push32(cpu, r); sfera_sub_00427870(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0xCu)) == (uint32_t)(cpu->edi)) goto label_00028BD7;
    label_00028A48: cpu->eip = LIFT_CODE_TOKEN_VA(0x428A48u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->esi + 0x30u, 1u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00028A66;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    cpu->edx = (uint32_t)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x28A66u); lift_push32(cpu, r); sfera_sub_0042D180(cpu,r); if (cpu->eip != r) return; }
    label_00028A66: cpu->eip = LIFT_CODE_TOKEN_VA(0x428A66u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00028A94;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428A7Fu); lift_push32(cpu, r); sfera_sub_0042D180(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->esi + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esi + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00028A94: cpu->eip = LIFT_CODE_TOKEN_VA(0x428A94u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00028AB7;
    cpu->edx = g_sfera_effect_manager.particle_random_table;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x28AB7u); lift_push32(cpu, r); sfera_sub_0042D290(cpu,r); if (cpu->eip != r) return; }
    label_00028AB7: cpu->eip = LIFT_CODE_TOKEN_VA(0x428AB7u);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428AC0u); lift_push32(cpu, r); sfera_sub_004600C0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    cpu->ebp = native_function_address32(&::rand);
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax))));
    lift_store_f32(cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 4u))));
    lift_store_f32(cpu->edi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 8u))));
    lift_store_f32(cpu->edi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((lift_load8(cpu->esi + 0x34u)) & (1u)) == 0u) goto label_00028B4E;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x28AEDu), LIFT_CODE_TOKEN_RVA(0x28AEBu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x428AEDu);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * ((double)(((int32_t)(lift_load32(cpu->esi + 0x44u))))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + ((double)(((int32_t)(lift_load32(cpu->esi + 0x38u))))));
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x28B0Eu), LIFT_CODE_TOKEN_RVA(0x28B0Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x428B0Eu);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * ((double)(((int32_t)(lift_load32(cpu->esi + 0x48u))))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + ((double)(((int32_t)(lift_load32(cpu->esi + 0x3Cu))))));
    lift_store_f32(cpu->esi + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x28B2Fu), LIFT_CODE_TOKEN_RVA(0x28B2Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x428B2Fu);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * ((double)(((int32_t)(lift_load32(cpu->esi + 0x4Cu))))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + ((double)(((int32_t)(lift_load32(cpu->esi + 0x40u))))));
    lift_store_f32(cpu->esi + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00028B4E: cpu->eip = LIFT_CODE_TOKEN_VA(0x428B4Eu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x2Cu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.00390625));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->edi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->edi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->edi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x28u))));
    lift_store_f32(cpu->edi + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((lift_load8(cpu->esi + 0x34u)) & (2u)) == 0u) goto label_00028BD3;
    cpu->ecx = lift_load8(cpu->esi + 0x58u);
    cpu->eax = lift_load32(cpu->esi + 0x5Cu);
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    if ((uint32_t)(cpu->edx) != 0u) goto label_00028BD3;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x28B99u), LIFT_CODE_TOKEN_RVA(0x28B97u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x428B99u);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x54u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x50u))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 0xCu))));
    lift_store_f32(cpu->edi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->edi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 0x14u))));
    lift_store_f32(cpu->edi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00028BD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x428BD3u);
    lift_store32(cpu->esi + 0x5Cu, (uint64_t)(lift_load32(cpu->esi + 0x5Cu)) + 1u);
    cpu->ebp = lift_pop32(cpu);
    label_00028BD7: cpu->eip = LIFT_CODE_TOKEN_VA(0x428BD7u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00428BF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x428BF0u);
    cpu->esp -= 0x390u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::FindFirstFileA);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Effects\\*.ssm");
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x28C1Au), LIFT_CODE_TOKEN_RVA(0x28C18u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x428C1Au);
    cpu->ebp = cpu->eax;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(0xFFFFFFFFu)) goto label_00028C9F;
    label_00028C21: cpu->eip = LIFT_CODE_TOKEN_VA(0x428C21u);
    if ((uint8_t)((lift_load8(cpu->esp + 0x1Cu)) & (0x10u)) != 0u) goto label_00028C89;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    cpu->edx = 0x5C737463u;
    cpu->ecx = 0x65666645u;
    lift_store8(cpu->esp + 0x2A4u, cpu->eax & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    lift_store32(cpu->esp + 0x2A0u, cpu->edx);
    lift_store32(cpu->esp + 0x29Cu, cpu->ecx);
    cpu->edx = cpu->eax;
    label_00028C54: cpu->eip = LIFT_CODE_TOKEN_VA(0x428C54u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00028C54;
    cpu->edi = (uint32_t)(cpu->esp + 0x29Cu);
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_00028C65: cpu->eip = LIFT_CODE_TOKEN_VA(0x428C65u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00028C65;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x29Cu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x28C89u); lift_push32(cpu, r); sfera_sub_004273E0(cpu,r); if (cpu->eip != r) return; }
    label_00028C89: cpu->eip = LIFT_CODE_TOKEN_VA(0x428C89u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::FindNextFileA), LIFT_CODE_TOKEN_VA(0x428C8Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x428C95u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00028C21;
    cpu->edi = native_function_address32(&::FindFirstFileA);
    label_00028C9F: cpu->eip = LIFT_CODE_TOKEN_VA(0x428C9Fu);
    cpu->ebx = native_function_address32(&::FindClose);
    lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x28CA8u), LIFT_CODE_TOKEN_RVA(0x28CA6u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x428CA8u);
    cpu->edx = (uint32_t)(cpu->esp + 0x15Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"Effects\\*.sef");
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x28CB7u), LIFT_CODE_TOKEN_RVA(0x28CB5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x428CB7u);
    cpu->esi = cpu->eax;
    cpu->ebp = 0u;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_00028CDE;
    label_00028CC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x428CC0u);
    if ((uint8_t)((lift_load8(cpu->esp + 0x15Cu)) & (0x10u)) != 0u) goto label_00028CCB;
    ++cpu->ebp;
    label_00028CCB: cpu->eip = LIFT_CODE_TOKEN_VA(0x428CCBu);
    cpu->eax = (uint32_t)(cpu->esp + 0x15Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindNextFileA), LIFT_CODE_TOKEN_VA(0x428CD4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x428CDAu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00028CC0;
    label_00028CDE: cpu->eip = LIFT_CODE_TOKEN_VA(0x428CDEu);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x28CE1u), LIFT_CODE_TOKEN_RVA(0x28CDFu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x428CE1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x15Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Players\\*.sef");
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x28CF0u), LIFT_CODE_TOKEN_RVA(0x28CEEu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x428CF0u);
    cpu->esi = cpu->eax;
    cpu->edi = 0u;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_00028D1E;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00028D00: cpu->eip = LIFT_CODE_TOKEN_VA(0x428D00u);
    if ((uint8_t)((lift_load8(cpu->esp + 0x15Cu)) & (0x10u)) != 0u) goto label_00028D0B;
    ++cpu->edi;
    label_00028D0B: cpu->eip = LIFT_CODE_TOKEN_VA(0x428D0Bu);
    cpu->edx = (uint32_t)(cpu->esp + 0x15Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindNextFileA), LIFT_CODE_TOKEN_VA(0x428D14u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x428D1Au);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00028D00;
    label_00028D1E: cpu->eip = LIFT_CODE_TOKEN_VA(0x428D1Eu);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x28D21u), LIFT_CODE_TOKEN_RVA(0x28D1Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x428D21u);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Effects\\*.sef");
    lift_native_call(cpu, native_function_address32(&::FindFirstFileA), LIFT_CODE_TOKEN_VA(0x428D2Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x428D31u);
    cpu->edi += cpu->ebp;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    cpu->ebx = cpu->eax;
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(0xFFFFFFFFu)) goto label_00028E88;
    label_00028D54: cpu->eip = LIFT_CODE_TOKEN_VA(0x428D54u);
    if ((uint8_t)((lift_load8(cpu->esp + 0x1Cu)) & (0x10u)) != 0u) goto label_00028E74;
    cpu->edx = 0x54Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428D6Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428D78u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00028D8A;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428D86u); lift_push32(cpu, r); sfera_sub_00425FA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    goto label_00028D8C;
    label_00028D8A: cpu->eip = LIFT_CODE_TOKEN_VA(0x428D8Au);
    cpu->ebp = 0u;
    label_00028D8C: cpu->eip = LIFT_CODE_TOKEN_VA(0x428D8Cu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    cpu->edx = 0x5C737463u;
    cpu->ecx = 0x65666645u;
    lift_store8(cpu->esp + 0x2A4u, cpu->eax & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    lift_store32(cpu->esp + 0x2A0u, cpu->edx);
    lift_store32(cpu->esp + 0x29Cu, cpu->ecx);
    cpu->edx = cpu->eax;
    label_00028DB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x428DB8u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00028DB8;
    cpu->edi = (uint32_t)(cpu->esp + 0x29Cu);
    cpu->eax -= cpu->edx;
    --cpu->edi;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00028DD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x428DD0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00028DD0;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x29Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428DF7u); lift_push32(cpu, r); sfera_sub_00427F10(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00028E1C;
    cpu->edx = 0x558u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428E0Au); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->ebp) == 0u) goto label_00028E52;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->destroyEffect(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x428E1Au);
    goto label_00028E52;
    label_00028E1C: cpu->eip = LIFT_CODE_TOKEN_VA(0x428E1Cu);
    cpu->eax = g_sfera_effect_manager.effect_definition_head;
    cpu->edx = 0u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->edx)) goto label_00028E32;
    g_sfera_effect_manager.effect_definition_head = (uint32_t)(cpu->ebp);
    lift_store32(cpu->ebp + 0x24u, cpu->edx);
    goto label_00028E4F;
    label_00028E32: cpu->eip = LIFT_CODE_TOKEN_VA(0x428E32u);
    cpu->ecx = lift_load32(cpu->eax + 0x20u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_00028E49;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00028E40: cpu->eip = LIFT_CODE_TOKEN_VA(0x428E40u);
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax + 0x20u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_00028E40;
    label_00028E49: cpu->eip = LIFT_CODE_TOKEN_VA(0x428E49u);
    lift_store32(cpu->eax + 0x20u, cpu->ebp);
    lift_store32(cpu->ebp + 0x24u, cpu->eax);
    label_00028E4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x428E4Fu);
    lift_store32(cpu->ebp + 0x20u, cpu->edx);
    label_00028E52: cpu->eip = LIFT_CODE_TOKEN_VA(0x428E52u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (30.0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428E6Du); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x28E74u); lift_push32(cpu, r); sfera_sub_00461700(cpu,r); if (cpu->eip != r) return; }
    label_00028E74: cpu->eip = LIFT_CODE_TOKEN_VA(0x428E74u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::FindNextFileA), LIFT_CODE_TOKEN_VA(0x428E7Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x428E80u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00028D54;
    label_00028E88: cpu->eip = LIFT_CODE_TOKEN_VA(0x428E88u);
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::FindClose), LIFT_CODE_TOKEN_VA(0x428E89u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x428E8Fu);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"Players\\*.sef");
    lift_native_call(cpu, native_function_address32(&::FindFirstFileA), LIFT_CODE_TOKEN_VA(0x428E99u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x428E9Fu);
    cpu->esi = cpu->eax;
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_00028FDC;
    cpu->edi = cpu->edi;
    label_00028EB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x428EB0u);
    if ((uint8_t)((lift_load8(cpu->esp + 0x1Cu)) & (0x10u)) != 0u) goto label_00028FC8;
    cpu->edx = 0x56Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428ECAu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428ED4u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 0u;
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00028EE8;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428EE4u); lift_push32(cpu, r); sfera_sub_00425FA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    goto label_00028EEA;
    label_00028EE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x428EE8u);
    cpu->ebp = 0u;
    label_00028EEA: cpu->eip = LIFT_CODE_TOKEN_VA(0x428EEAu);
    cpu->eax = lift_load32((uintptr_t)"Players\\");
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"Players\\") + 8u)) & 0xFFu);
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"Players\\") + 4u);
    lift_store32(cpu->esp + 0x29Cu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    lift_store8(cpu->esp + 0x2A4u, cpu->edx & 0xFFu);
    lift_store32(cpu->esp + 0x2A0u, cpu->ecx);
    cpu->edx = cpu->eax;
    label_00028F16: cpu->eip = LIFT_CODE_TOKEN_VA(0x428F16u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00028F16;
    cpu->edi = (uint32_t)(cpu->esp + 0x29Cu);
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_00028F27: cpu->eip = LIFT_CODE_TOKEN_VA(0x428F27u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00028F27;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = (uint32_t)(cpu->esp + 0x29Cu);
    lift_movs8(cpu, 1u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428F4Eu); lift_push32(cpu, r); sfera_sub_00427F10(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00028F73;
    cpu->edx = 0x578u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428F61u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->ebx)) goto label_00028FA2;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->destroyEffect(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x428F71u);
    goto label_00028FA2;
    label_00028F73: cpu->eip = LIFT_CODE_TOKEN_VA(0x428F73u);
    cpu->eax = g_sfera_effect_manager.effect_definition_head;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_00028F87;
    g_sfera_effect_manager.effect_definition_head = (uint32_t)(cpu->ebp);
    lift_store32(cpu->ebp + 0x24u, cpu->ebx);
    goto label_00028F9F;
    label_00028F87: cpu->eip = LIFT_CODE_TOKEN_VA(0x428F87u);
    cpu->ecx = lift_load32(cpu->eax + 0x20u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00028F99;
    cpu->edi = cpu->edi;
    label_00028F90: cpu->eip = LIFT_CODE_TOKEN_VA(0x428F90u);
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->eax + 0x20u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->ebx)) goto label_00028F90;
    label_00028F99: cpu->eip = LIFT_CODE_TOKEN_VA(0x428F99u);
    lift_store32(cpu->eax + 0x20u, cpu->ebp);
    lift_store32(cpu->ebp + 0x24u, cpu->eax);
    label_00028F9F: cpu->eip = LIFT_CODE_TOKEN_VA(0x428F9Fu);
    lift_store32(cpu->ebp + 0x20u, cpu->ebx);
    label_00028FA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x428FA2u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (30.0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428FBDu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x428FC4u); lift_push32(cpu, r); sfera_sub_00461700(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    label_00028FC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x428FC8u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindNextFileA), LIFT_CODE_TOKEN_VA(0x428FCEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x428FD4u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00028EB0;
    label_00028FDC: cpu->eip = LIFT_CODE_TOKEN_VA(0x428FDCu);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindClose), LIFT_CODE_TOKEN_VA(0x428FDDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x428FE3u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x390u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00429000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x429000u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    std::construct_at(reinterpret_cast<CScriptedEffect*>(cpu->esi));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0xF4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x1Cu, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002905F;
    cpu->edx = 0x6F6u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429050u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xF4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42905Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0002905F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42905Fu);
    if ((uint32_t)(lift_load32(cpu->esi + 0xF8u)) == (uint32_t)(0u)) goto label_000290D6;
    cpu->eax = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0xC8u)) <= (uint32_t)(cpu->eax)) goto label_0002909D;
    cpu->ecx = 0u;
    label_00029080: cpu->eip = LIFT_CODE_TOKEN_VA(0x429080u);
    cpu->edx = lift_load32(cpu->esi + 0xF8u);
    lift_store32(cpu->ecx + cpu->edx + 4u, 0u);
    ++cpu->eax;
    cpu->ecx += 0x19Cu;
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->esi + 0xC8u))) goto label_00029080;
    label_0002909D: cpu->eip = LIFT_CODE_TOKEN_VA(0x42909Du);
    cpu->edx = 0x6FBu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4290ACu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xF8u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000290D6;
    cpu->ecx = lift_load32(cpu->eax + 0xFFFFFFFCu);
    cpu->edi = (uint32_t)(cpu->eax + 0xFFFFFFFCu);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00483F50)); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x19Cu); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4290CDu); lift_push32(cpu, r); sfera_sub_004EEB86(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4290D3u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000290D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4290D6u);
    if ((uint32_t)(lift_load32(cpu->esi + 0xE8u)) == (uint32_t)(0u)) goto label_00029118;
    cpu->edx = 0x6FEu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4290EEu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xE8u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00029118;
    cpu->edx = lift_load32(cpu->eax + 0xFFFFFFFCu);
    cpu->edi = (uint32_t)(cpu->eax + 0xFFFFFFFCu);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00483920)); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x9Cu); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42910Fu); lift_push32(cpu, r); sfera_sub_004EEB86(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429115u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00029118: cpu->eip = LIFT_CODE_TOKEN_VA(0x429118u);
    if ((uint32_t)(lift_load32(cpu->esi + 0xF0u)) == (uint32_t)(0u)) goto label_0002915A;
    cpu->edx = 0x6FFu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429130u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xF0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002915A;
    cpu->ecx = lift_load32(cpu->eax + 0xFFFFFFFCu);
    cpu->edi = (uint32_t)(cpu->eax + 0xFFFFFFFCu);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00483F50)); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x19Cu); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429151u); lift_push32(cpu, r); sfera_sub_004EEB86(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429157u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0002915A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42915Au);
    if ((uint32_t)(lift_load32(cpu->esi + 0xECu)) == (uint32_t)(0u)) goto label_00029199;
    cpu->edx = 0x700u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429172u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xECu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00029199;
    cpu->edx = lift_load32(cpu->eax + 0xFFFFFFFCu);
    cpu->edi = (uint32_t)(cpu->eax + 0xFFFFFFFCu);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004277C0)); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429190u); lift_push32(cpu, r); sfera_sub_004EEB86(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429196u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00029199: cpu->eip = LIFT_CODE_TOKEN_VA(0x429199u);
    if ((uint32_t)(lift_load32(cpu->esi + 0xB4u)) == (uint32_t)(0u)) goto label_000291CB;
    cpu->edx = 0x701u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4291B1u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0xB4u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_000291CB;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4291C2u); lift_push32(cpu, r); sfera_sub_00496F00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4291C8u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000291CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4291CBu);
    cpu->ebp = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x9Cu)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0002920A;
    cpu->edi = (uint32_t)(cpu->esi + 0x5Cu);
    label_000291E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4291E0u);
    cpu->edx = 0x704u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4291EFu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000291FE;
    lift_push32(cpu, 1u);
    reinterpret_cast<IEffectManager*>(cpu->ecx)->destroyEffect(cpu);
    label_000291FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4291FEu);
    ++cpu->ebp;
    cpu->edi += 4u;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x9Cu))) goto label_000291E0;
    label_0002920A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42920Au);
    if ((uint8_t)(lift_load8(cpu->esi + 0xCu)) != (uint8_t)(0u)) goto label_00029237;
    if ((uint32_t)(lift_load32(cpu->esi + 0xA4u)) == (uint32_t)(0u)) goto label_00029237;
    cpu->edx = 0x708u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429228u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xA4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429234u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00029237: cpu->eip = LIFT_CODE_TOKEN_VA(0x429237u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    std::construct_at(reinterpret_cast<IEffectManager*>(cpu->esi));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002926C;
    if ((uint8_t)(lift_load8(cpu->esi + 0xCu)) != (uint8_t)(0u)) goto label_0002926C;
    cpu->edx = 0x67Du;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429260u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429269u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0002926C: cpu->eip = LIFT_CODE_TOKEN_VA(0x42926Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00429280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x429280u);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    if ((uint32_t)(lift_load32(cpu->ebx + 0xBCu)) <= (uint32_t)(cpu->esi)) goto label_000294C9;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000292B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4292B0u);
    cpu->esi += lift_load32(cpu->ebx + 0xECu);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    cpu->eax = lift_load8(cpu->esi + 0x60u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->edi |= 0xFFFFFFFFu;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x30u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000292D2;
    if ((uint32_t)(lift_load32(cpu->esi + 0xCu)) != (uint32_t)(cpu->edi)) goto label_00029329;
    label_000292D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4292D2u);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_000292E1;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4292DEu); lift_push32(cpu, r); sfera_sub_004563A0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xCu, cpu->edi);
    label_000292E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4292E1u);
    lift_x87_push(cpu, 0.0);
    cpu->ecx = lift_load32(cpu->esi + 0x1Cu);
    cpu->edx = lift_load32(cpu->esi + 0x20u);
    cpu->esp -= 0x14u;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x24u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->eax + 0xCu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + 0x14u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42931Eu); lift_push32(cpu, r); sfera_sub_004562D0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000294A9;
    label_00029329: cpu->eip = LIFT_CODE_TOKEN_VA(0x429329u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->esi + 0x30u, 1u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00029347;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    cpu->edx = (uint32_t)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x29347u); lift_push32(cpu, r); sfera_sub_0042D180(cpu,r); if (cpu->eip != r) return; }
    label_00029347: cpu->eip = LIFT_CODE_TOKEN_VA(0x429347u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00029375;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429360u); lift_push32(cpu, r); sfera_sub_0042D180(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esi + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esi + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00029375: cpu->eip = LIFT_CODE_TOKEN_VA(0x429375u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00029398;
    cpu->edx = g_sfera_effect_manager.particle_random_table;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x29398u); lift_push32(cpu, r); sfera_sub_0042D290(cpu,r); if (cpu->eip != r) return; }
    label_00029398: cpu->eip = LIFT_CODE_TOKEN_VA(0x429398u);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4293A0u); lift_push32(cpu, r); sfera_sub_004600C0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp))));
    cpu->edi = cpu->eax;
    lift_store_f32(cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x14u))));
    lift_store_f32(cpu->edi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 8u));
    cpu->ebp = native_function_address32(&::rand);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x18u))));
    lift_store_f32(cpu->edi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((lift_load8(cpu->esi + 0x34u)) & (1u)) == 0u) goto label_0002942B;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x293CAu), LIFT_CODE_TOKEN_RVA(0x293C8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4293CAu);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * ((double)(((int32_t)(lift_load32(cpu->esi + 0x44u))))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + ((double)(((int32_t)(lift_load32(cpu->esi + 0x38u))))));
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x293EBu), LIFT_CODE_TOKEN_RVA(0x293E9u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4293EBu);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * ((double)(((int32_t)(lift_load32(cpu->esi + 0x48u))))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + ((double)(((int32_t)(lift_load32(cpu->esi + 0x3Cu))))));
    lift_store_f32(cpu->esi + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x2940Cu), LIFT_CODE_TOKEN_RVA(0x2940Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42940Cu);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * ((double)(((int32_t)(lift_load32(cpu->esi + 0x4Cu))))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + ((double)(((int32_t)(lift_load32(cpu->esi + 0x40u))))));
    lift_store_f32(cpu->esi + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0002942B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42942Bu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1Cu));
    lift_x87_push(cpu, 0.99609375);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->edi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->edi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->edi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x28u))));
    lift_store_f32(cpu->edi + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((lift_load8(cpu->esi + 0x34u)) & (2u)) == 0u) goto label_000294A6;
    cpu->ecx = lift_load8(cpu->esi + 0x58u);
    cpu->eax = lift_load32(cpu->esi + 0x5Cu);
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    if ((uint32_t)(cpu->edx) != 0u) goto label_000294A6;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x29468u), LIFT_CODE_TOKEN_RVA(0x29466u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x429468u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x54u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x50u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->edi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->edi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 0x14u))));
    lift_store_f32(cpu->edi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000294A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4294A6u);
    lift_store32(cpu->esi + 0x5Cu, (uint64_t)(lift_load32(cpu->esi + 0x5Cu)) + 1u);
    label_000294A9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4294A9u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    ++cpu->eax;
    cpu->esi += 0x64u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->ebx + 0xBCu))) goto label_000292B0;
    label_000294C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4294C9u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004294E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4294E0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0xA4u)) == (uint32_t)(0u)) goto label_00029825;
    cpu->eax = lift_load32(cpu->esi + 0x58u);
    cpu->eax += g_sfera_effect_manager.render_slot_count;
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x2710u)) goto label_0002950E;
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) != (uint32_t)(0u)) goto label_00029825;
    label_0002950E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42950Eu);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0xBCu)) <= (uint32_t)(cpu->edi)) goto label_00029553;
    cpu->ebp = 0u;
    label_00029521: cpu->eip = LIFT_CODE_TOKEN_VA(0x429521u);
    cpu->ecx = lift_load32(cpu->esi + 0xECu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    cpu->eax = lift_load8(cpu->ecx + cpu->ebp + 0x60u);
    cpu->ecx += cpu->ebp;
    lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->edx) * 4u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429547u); lift_push32(cpu, r); sfera_sub_00428A10(cpu,r); if (cpu->eip != r) return; }
    ++cpu->edi;
    cpu->ebp += 0x64u;
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi + 0xBCu))) goto label_00029521;
    label_00029553: cpu->eip = LIFT_CODE_TOKEN_VA(0x429553u);
    if ((uint32_t)(lift_load32(cpu->esi + 0xD4u)) == (uint32_t)(0xFFFFFFFFu)) goto label_000296F3;
    cpu->eax = lift_load32(cpu->esi + 0xD0u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000296EC;
    if ((uint32_t)(lift_load32(cpu->esi + 0xE4u)) != (uint32_t)(cpu->eax)) goto label_00029641;
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x42957Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x429580u);
    cpu->ecx = lift_load32(cpu->esi + 0xD8u);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0xD8u)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_000295AC;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000295AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4295ACu);
    lift_store16(cpu->esp + 0x1Cu, cpu->fpu_control);
    cpu->ebp = 0u;
    cpu->eax = lift_load16(cpu->esp + 0x1Cu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 0xE4u, 1u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x10u));
    lift_store64(cpu->esp + 0x10u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->edx += lift_load32(cpu->esi + 0xD4u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x1Cu));
    lift_store32(cpu->esi + 0xD0u, cpu->edx);
    if ((uint32_t)(lift_load32(cpu->esi + 0xC4u)) <= (uint32_t)(cpu->ebp)) goto label_000296F3;
    cpu->edi = 0u;
    label_000295F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4295F6u);
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xF0u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 1u);
    cpu->ecx += cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42960Bu); lift_push32(cpu, r); sfera_sub_00484420(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xF0u);
    lift_store32(cpu->edi + cpu->eax + 0x190u, 1u);
    cpu->ecx = lift_load32(cpu->esi + 0xF0u);
    lift_store32(cpu->edi + cpu->ecx + 0x194u, 0u);
    ++cpu->ebp;
    cpu->edi += 0x19Cu;
    if ((uint32_t)(cpu->ebp) < (uint32_t)(lift_load32(cpu->esi + 0xC4u))) goto label_000295F6;
    goto label_000296F3;
    label_00029641: cpu->eip = LIFT_CODE_TOKEN_VA(0x429641u);
    cpu->edi = lift_load32(cpu->esi + 0xDCu);
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x429647u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42964Du);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    cpu->edx = cpu->edi;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_00029677;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_00029677: cpu->eip = LIFT_CODE_TOKEN_VA(0x429677u);
    lift_store16(cpu->esp + 0x1Cu, cpu->fpu_control);
    cpu->ebp = 0u;
    cpu->eax = lift_load16(cpu->esp + 0x1Cu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 0xE4u, cpu->ebp);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x10u));
    lift_store64(cpu->esp + 0x10u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->eax += cpu->edi;
    lift_store32(cpu->esi + 0xD0u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x1Cu));
    if ((uint32_t)(lift_load32(cpu->esi + 0xC4u)) <= (uint32_t)(cpu->ebp)) goto label_000296F3;
    cpu->edi = 0u;
    label_000296B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4296B5u);
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xF0u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0u);
    cpu->ecx += cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4296CAu); lift_push32(cpu, r); sfera_sub_00484420(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xF0u);
    lift_store32(cpu->edi + cpu->ecx + 0x194u, 1u);
    ++cpu->ebp;
    cpu->edi += 0x19Cu;
    if ((uint32_t)(cpu->ebp) < (uint32_t)(lift_load32(cpu->esi + 0xC4u))) goto label_000296B5;
    goto label_000296F3;
    label_000296EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4296ECu);
    --cpu->eax;
    lift_store32(cpu->esi + 0xD0u, cpu->eax);
    label_000296F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4296F3u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x28u)) == (uint32_t)(0u)) goto label_000297BB;
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    if ((uint32_t)(lift_load32(cpu->esi + 0xC0u)) <= (uint32_t)(cpu->eax)) goto label_00029822;
    cpu->ebp = lift_load32(cpu->esp + 0x2Cu);
    label_00029720: cpu->eip = LIFT_CODE_TOKEN_VA(0x429720u);
    cpu->edx = lift_load32(cpu->esi + 0xA4u);
    cpu->edi = (int16_t)(lift_load16(cpu->edx + ((uint32_t)(cpu->eax) * 4u)));
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    if ((uint32_t)(cpu->edi) == (uint32_t)(0xFFFFFFFFu)) goto label_0002979C;
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 2u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    cpu->eax = lift_load8(cpu->eax + 3u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->ecx = cpu->eax;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->edx) * 4u));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00029775;
    { int64_t v=(int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x9Cu); cpu->edi= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(6u), 32u);
    cpu->ecx += cpu->ebp;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xE8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx += cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429766u); lift_push32(cpu, r); sfera_sub_00483C80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xE8u);
    cpu->ecx += cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429773u); lift_push32(cpu, r); sfera_sub_004856D0(cpu,r); if (cpu->eip != r) return; }
    goto label_0002979C;
    label_00029775: cpu->eip = LIFT_CODE_TOKEN_VA(0x429775u);
    { int64_t v=(int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x19Cu); cpu->edi= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(6u), 32u);
    cpu->ecx += cpu->ebp;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0xF0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx += cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42978Fu); lift_push32(cpu, r); sfera_sub_004866A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0xF0u);
    cpu->ecx += cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2979Cu); lift_push32(cpu, r); sfera_sub_00487410(cpu,r); if (cpu->eip != r) return; }
    label_0002979C: cpu->eip = LIFT_CODE_TOKEN_VA(0x42979Cu);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->esi + 0xC0u))) goto label_00029720;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 20u, stop_address); return;
    label_000297BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4297BBu);
    cpu->edi = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0xC0u)) <= (uint32_t)(cpu->edi)) goto label_00029822;
    cpu->ebp = lift_load32(cpu->esp + 0x2Cu);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000297D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4297D0u);
    cpu->ecx = lift_load32(cpu->esi + 0xA4u);
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edi) * 4u));
    cpu->ecx = (int16_t)(lift_load16(cpu->eax));
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFFFFFFu)) goto label_00029819;
    if ((uint8_t)(lift_load8(cpu->eax + 2u)) != (uint8_t)(0u)) goto label_00029819;
    cpu->eax = lift_load8(cpu->eax + 3u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx &= 0xFFFFu;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x19Cu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi + 0xF0u)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(6u), 32u);
    cpu->edx += cpu->ebp;
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->edx = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x29819u); lift_push32(cpu, r); sfera_sub_004866A0(cpu,r); if (cpu->eip != r) return; }
    label_00029819: cpu->eip = LIFT_CODE_TOKEN_VA(0x429819u);
    ++cpu->edi;
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi + 0xC0u))) goto label_000297D0;
    label_00029822: cpu->eip = LIFT_CODE_TOKEN_VA(0x429822u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00029825: cpu->eip = LIFT_CODE_TOKEN_VA(0x429825u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00429830(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x429830u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ebp) <= (uint32_t)(0x3FFFFFFFu)) goto label_0002984B;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x2984Bu);
    label_0002984B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42984Bu);
    cpu->eax = lift_load32(cpu->esi + 8u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ebp)) goto label_000298A5;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esi + 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429862u); lift_push32(cpu, r); sfera_sub_0049F1D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->ebx = cpu->eax;
    cpu->eax = lift_load32(cpu->esi);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x429875u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42987Bu);
    cpu->eax = lift_load32(cpu->esi);
    cpu->edi = lift_load32(cpu->esi + 4u);
    cpu->edi -= cpu->eax;
    { uint64_t l=cpu->esp, r=(uint64_t)(0xCu), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00029895;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429892u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00029895: cpu->eip = LIFT_CODE_TOKEN_VA(0x429895u);
    cpu->eax = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->edi) * 4u));
    cpu->edx = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->ebp) * 4u));
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi, cpu->ebx);
    lift_store32(cpu->esi + 8u, cpu->edx);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->ebx = lift_pop32(cpu);
    label_000298A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4298A5u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004298B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4298B0u);
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
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000298FD;
    cpu->edx = lift_load32(cpu->ebx + 0xCu);
    label_000298D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4298D1u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x1Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000298E2;
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0xCu)), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_000298E8;
    label_000298E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4298E2u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(lift_load32(cpu->eax + 0xCu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) != 0u)) ? 1u : 0u) & 0xFFu);
    label_000298E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4298E8u);
    lift_store8(cpu->esp + 0x18u, cpu->ecx & 0xFFu);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_000298F4;
    cpu->eax = lift_load32(cpu->eax);
    goto label_000298F7;
    label_000298F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4298F4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    label_000298F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4298F7u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x15u)) == (uint8_t)(0u)) goto label_000298D1;
    label_000298FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4298FDu);
    cpu->edi = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    if ((uint8_t)((cpu->ecx & 0xFFu)) == 0u) goto label_0002993A;
    cpu->eax = lift_load32(cpu->ebp + 4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->eax))) goto label_00029931;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42991Eu); lift_push32(cpu, r); sfera_sub_004037A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->edx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_00029931: cpu->eip = LIFT_CODE_TOKEN_VA(0x429931u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429936u); lift_push32(cpu, r); sfera_sub_004025A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    label_0002993A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42993Au);
    cpu->eax = lift_load32(cpu->edi + 0xCu);
    lift_push32(cpu, cpu->ebx);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(lift_load32(cpu->ebx + 0xCu))) goto label_00029968;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429955u); lift_push32(cpu, r); sfera_sub_004037A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, 1u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_00029968: cpu->eip = LIFT_CODE_TOKEN_VA(0x429968u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42996Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->esp += 4u;
    lift_store32(cpu->eax, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->eax + 4u, 0u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00429990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x429990u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_effect_manager.effect_listeners.sentinel;
    cpu->edx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_00029A02;
    cpu->edi = cpu->edi;
    label_000299A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4299A0u);
    if ((uint32_t)(lift_load32(cpu->edx + 0x10u)) == (uint32_t)(cpu->ecx)) goto label_000299EE;
    if ((uint8_t)(lift_load8(cpu->edx + 0x15u)) != (uint8_t)(0u)) goto label_000299E7;
    cpu->eax = lift_load32(cpu->edx + 8u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x15u)) != (uint8_t)(0u)) goto label_000299CC;
    cpu->edx = cpu->eax;
    cpu->eax = lift_load32(cpu->edx);
    if ((uint8_t)(lift_load8(cpu->eax + 0x15u)) != (uint8_t)(0u)) goto label_000299E7;
    cpu->edi = cpu->edi;
    label_000299C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4299C0u);
    cpu->edx = cpu->eax;
    cpu->eax = lift_load32(cpu->edx);
    if ((uint8_t)(lift_load8(cpu->eax + 0x15u)) == (uint8_t)(0u)) goto label_000299C0;
    goto label_000299E7;
    label_000299CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4299CCu);
    cpu->eax = lift_load32(cpu->edx + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x15u)) != (uint8_t)(0u)) goto label_000299E5;
    label_000299D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4299D5u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_000299E5;
    cpu->edx = cpu->eax;
    cpu->eax = lift_load32(cpu->eax + 4u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x15u)) == (uint8_t)(0u)) goto label_000299D5;
    label_000299E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4299E5u);
    cpu->edx = cpu->eax;
    label_000299E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4299E7u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->esi)) goto label_000299A0;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_000299EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4299EEu);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_00029A02;
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_effect_manager.effect_listeners;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x29A02u); lift_push32(cpu, r); sfera_sub_00404510(cpu,r); if (cpu->eip != r) return; }
    label_00029A02: cpu->eip = LIFT_CODE_TOKEN_VA(0x429A02u);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00429A10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x429A10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429A18u); lift_push32(cpu, r); sfera_sub_00429000(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_00029A28;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429A25u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00029A28: cpu->eip = LIFT_CODE_TOKEN_VA(0x429A28u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00429A30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x429A30u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = lift_load32(cpu->edi + 4u);
    cpu->ebx = lift_load32(cpu->eax + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + 0x15u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = cpu->ebx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00029A61;
    label_00029A43: cpu->eip = LIFT_CODE_TOKEN_VA(0x429A43u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429A4Eu); lift_push32(cpu, r); sfera_sub_004044D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429A56u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x15u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00029A43;
    label_00029A61: cpu->eip = LIFT_CODE_TOKEN_VA(0x429A61u);
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->eax + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->eax, cpu->eax);
    cpu->eax = lift_load32(cpu->edi + 4u);
    lift_store32(cpu->eax + 8u, cpu->eax);
    lift_store32(cpu->edi + 8u, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00429A80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x429A80u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0x15u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00029AAA;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->edi);
    label_00029A95: cpu->eip = LIFT_CODE_TOKEN_VA(0x429A95u);
    if ((uint32_t)(lift_load32(cpu->eax + 0xCu)) >= (uint32_t)(cpu->esi)) goto label_00029A9F;
    cpu->eax = lift_load32(cpu->eax + 8u);
    goto label_00029AA3;
    label_00029A9F: cpu->eip = LIFT_CODE_TOKEN_VA(0x429A9Fu);
    cpu->edx = cpu->eax;
    cpu->eax = lift_load32(cpu->eax);
    label_00029AA3: cpu->eip = LIFT_CODE_TOKEN_VA(0x429AA3u);
    if ((uint8_t)(lift_load8(cpu->eax + 0x15u)) == (uint8_t)(0u)) goto label_00029A95;
    cpu->esi = lift_pop32(cpu);
    label_00029AAA: cpu->eip = LIFT_CODE_TOKEN_VA(0x429AAAu);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->eax)) goto label_00029ACD;
    cpu->ecx = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(lift_load32(cpu->edx + 0xCu))) goto label_00029ACD;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00029ACD: cpu->eip = LIFT_CODE_TOKEN_VA(0x429ACDu);
    lift_store32(cpu->esp + 4u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00429AF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x429AF0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00029B02;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429AFFu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00029B02: cpu->eip = LIFT_CODE_TOKEN_VA(0x429B02u);
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->esi + 4u, 0u);
    lift_store32(cpu->esi + 8u, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00429B20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x429B20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00029C05;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_00029C05;
    if ((uint32_t)(g_sfera_effect_manager.active_effect_count) == (uint32_t)(0u)) goto label_00029C05;
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_effect_manager.effect_listeners;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429B56u); lift_push32(cpu, r); sfera_sub_00429A80(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 8u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(g_sfera_effect_manager.effect_listeners.sentinel)) goto label_00029B79;
    cpu->ecx = lift_load32(cpu->eax + 0x10u);
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    reinterpret_cast<BloodEffListener*>(cpu->ecx)->onEffectDetached(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x429B71u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00029C04;
    label_00029B79: cpu->eip = LIFT_CODE_TOKEN_VA(0x429B79u);
    if ((uint16_t)(lift_load16(cpu->esi)) != (uint16_t)(0u)) goto label_00029B89;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x29B89u); lift_push32(cpu, r); sfera_sub_004560A0(cpu,r); if (cpu->eip != r) return; }
    label_00029B89: cpu->eip = LIFT_CODE_TOKEN_VA(0x429B89u);
    cpu->ecx = lift_load32(cpu->esi + 0x1Cu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00029B9E;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->releaseEffect(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x429B97u);
    lift_store32(cpu->esi + 0x1Cu, 0u);
    label_00029B9E: cpu->eip = LIFT_CODE_TOKEN_VA(0x429B9Eu);
    cpu->ecx = lift_load32(cpu->esi + 0x20u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00029BC0;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429BAAu); lift_push32(cpu, r); sfera_sub_00496FE0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x20u, 0u);
    if ((uint32_t)(g_sfera_effect_manager.active_resource_count) == (uint32_t)(0u)) goto label_00029BC0;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_effect_manager.active_resource_count, (uint64_t)(g_sfera_effect_manager.active_resource_count) - 1u);
    label_00029BC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x429BC0u);
    lift_store32(cpu->esi + 8u, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x18u, 0u);
    lift_store32(cpu->edi, 0xFFFFFFFFu);
    if ((uint32_t)(g_sfera_effect_manager.active_effect_count) == (uint32_t)(0u)) goto label_00029BE3;
    --g_sfera_effect_manager.active_effect_count;
    label_00029BE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x429BE3u);
    cpu->ecx = lift_load32(cpu->esi + 0x38u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00029BF0;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x29BF0u); lift_push32(cpu, r); sfera_sub_00425C30(cpu,r); if (cpu->eip != r) return; }
    label_00029BF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x429BF0u);
    cpu->eax = g_sfera_effect_items.free_count;
    cpu->ecx = g_sfera_effect_items.free_items;
    lift_store32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u), cpu->esi);
    ++g_sfera_effect_items.free_count;
    label_00029C04: cpu->eip = LIFT_CODE_TOKEN_VA(0x429C04u);
    cpu->edi = lift_pop32(cpu);
    label_00029C05: cpu->eip = LIFT_CODE_TOKEN_VA(0x429C05u);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00429C10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x429C10u);
    cpu->esp -= 0x70u;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_effect_manager.viewer_position.x;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429C29u); lift_push32(cpu, r); sfera_sub_00455FD0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_effect_manager.flare_transition;
    cpu->ebx = 0u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00029C71;
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00029C42;
    g_sfera_effect_manager.flare_alpha -= 0x23u;
    goto label_00029C49;
    label_00029C42: cpu->eip = LIFT_CODE_TOKEN_VA(0x429C42u);
    g_sfera_effect_manager.flare_alpha += 0x23u;
    label_00029C49: cpu->eip = LIFT_CODE_TOKEN_VA(0x429C49u);
    if ((int32_t)(uint32_t)(g_sfera_effect_manager.flare_alpha) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_00029C59;
    g_sfera_effect_manager.flare_alpha = (uint32_t)(cpu->ebx);
    goto label_00029C6B;
    label_00029C59: cpu->eip = LIFT_CODE_TOKEN_VA(0x429C59u);
    cpu->eax = 0xFFu;
    if ((int32_t)(uint32_t)(g_sfera_effect_manager.flare_alpha) <= (int32_t)(uint32_t)(cpu->eax)) goto label_00029C71;
    g_sfera_effect_manager.flare_alpha = (uint32_t)(cpu->eax);
    label_00029C6B: cpu->eip = LIFT_CODE_TOKEN_VA(0x429C6Bu);
    g_sfera_effect_manager.flare_transition = (uint32_t)(cpu->ebx);
    label_00029C71: cpu->eip = LIFT_CODE_TOKEN_VA(0x429C71u);
    cpu->eax = g_sfera_effect_manager.render_cycle;
    ++cpu->eax;
    g_sfera_effect_manager.render_slot_count = (uint32_t)(cpu->ebx);
    lift_store8(cpu->esp + 7u, cpu->ebx & 0xFFu);
    g_sfera_effect_manager.render_cycle = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x20u)) goto label_00029C9C;
    lift_store8(cpu->esp + 7u, 1u);
    g_sfera_effect_manager.render_cycle = (uint32_t)(cpu->ebx);
    label_00029C9C: cpu->eip = LIFT_CODE_TOKEN_VA(0x429C9Cu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_view_spatial_runtime.basis[0].z));
    lift_push32(cpu, cpu->esi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (10.0));
    cpu->esi = g_sfera_effect_manager.active_effects.first;
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_00029E7C;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->ebp = 2u;
    label_00029CC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x429CC2u);
    cpu->edi = lift_load32(cpu->esi + 0x30u);
    if ((uint8_t)(lift_load8(cpu->esp + 0x13u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00029CDA;
    cpu->eax = 0xFFFFu;
    if ((uint16_t)(lift_load16(cpu->esi + 2u)) != (uint16_t)((cpu->eax & 0xFFFFu))) goto label_00029DA8;
    label_00029CDA: cpu->eip = LIFT_CODE_TOKEN_VA(0x429CDAu);
    cpu->ecx = 0u;
    lift_store16(cpu->esi + 2u, cpu->ecx & 0xFFFFu);
    if ((uint16_t)(lift_load16(cpu->esi)) != (uint16_t)((cpu->ebx & 0xFFFFu))) goto label_00029D29;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429CF1u); lift_push32(cpu, r); sfera_sub_00455E40(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_effect_manager.viewer_position.x));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x40u))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_effect_manager.viewer_position.y));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x44u))));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_effect_manager.viewer_position.z));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x48u))));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    goto label_00029D5C;
    label_00029D29: cpu->eip = LIFT_CODE_TOKEN_VA(0x429D29u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_effect_manager.viewer_position.x));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_effect_manager.viewer_position.y));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x10u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_effect_manager.viewer_position.z));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x14u))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    label_00029D5C: cpu->eip = LIFT_CODE_TOKEN_VA(0x429D5Cu);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429D8Bu); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esi + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00029DA8;
    lift_store16(cpu->esi + 2u, (uint64_t)(lift_load16(cpu->esi + 2u)) | (uint64_t)(1u));
    label_00029DA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x429DA8u);
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00029E5A;
    cpu->edx = g_sfera_effect_manager.last_processed_generation;
    if ((uint32_t)(cpu->edx) == (uint32_t)(g_sfera_effect_manager.generation)) goto label_00029E15;
    if ((uint8_t)((lift_load8(cpu->esi + 2u)) & (1u)) != 0u) goto label_00029E15;
    if ((uint8_t)(lift_load8(cpu->eax + 0x54u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00029E15;
    if ((uint16_t)(lift_load16(cpu->esi)) != (uint16_t)(1u)) goto label_00029DE9;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    lift_store32(cpu->esp + 0x4Cu, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->esp + 0x50u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi + 0x14u);
    lift_store32(cpu->esp + 0x54u, cpu->edx);
    goto label_00029DF5;
    label_00029DE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x429DE9u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x29DF5u); lift_push32(cpu, r); sfera_sub_00455E40(cpu,r); if (cpu->eip != r) return; }
    label_00029DF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x429DF5u);
    cpu->ecx = lift_load32(cpu->esi + 0x1Cu);
    cpu->eax = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429E02u); lift_push32(cpu, r); sfera_sub_004275E0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00029E0C;
    lift_store16(cpu->esi + 2u, (uint64_t)(lift_load16(cpu->esi + 2u)) | (uint64_t)((cpu->ebp & 0xFFFFu)));
    goto label_00029E15;
    label_00029E0C: cpu->eip = LIFT_CODE_TOKEN_VA(0x429E0Cu);
    cpu->ecx = 0xFFFDu;
    lift_store16(cpu->esi + 2u, (uint64_t)(lift_load16(cpu->esi + 2u)) & (uint64_t)((cpu->ecx & 0xFFFFu)));
    label_00029E15: cpu->eip = LIFT_CODE_TOKEN_VA(0x429E15u);
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    if ((uint8_t)(lift_load8(cpu->eax + 0xFu)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00029E54;
    cpu->ecx = lift_load16(cpu->esi + 2u);
    if ((uint16_t)((cpu->ecx & 0xFFFFu)) == (uint16_t)((cpu->ebx & 0xFFFFu))) goto label_00029E51;
    if ((uint8_t)(((cpu->ecx & 0xFFu)) & (1u)) == 0u) goto label_00029E46;
    lift_store32(cpu->esi + 8u, (uint64_t)(lift_load32(cpu->esi + 8u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u));
    cpu->eax = lift_load32(cpu->eax + 0x14u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00029E70;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->eax)) goto label_00029E70;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429E44u); lift_push32(cpu, r); sfera_sub_00429B20(cpu,r); if (cpu->eip != r) return; }
    goto label_00029E70;
    label_00029E46: cpu->eip = LIFT_CODE_TOKEN_VA(0x429E46u);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00029E70;
    cpu->edx = cpu->ecx;
    goto label_00029E65;
    label_00029E51: cpu->eip = LIFT_CODE_TOKEN_VA(0x429E51u);
    lift_store8(cpu->eax + 0xFu, cpu->ebx & 0xFFu);
    label_00029E54: cpu->eip = LIFT_CODE_TOKEN_VA(0x429E54u);
    label_00029E5A: cpu->eip = LIFT_CODE_TOKEN_VA(0x429E5Au);
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00029E70;
    cpu->edx = lift_load16(cpu->esi + 2u);
    label_00029E65: cpu->eip = LIFT_CODE_TOKEN_VA(0x429E65u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2Cu));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x29E70u), LIFT_CODE_TOKEN_RVA(0x29E6Eu))) { return; }
    label_00029E70: cpu->eip = LIFT_CODE_TOKEN_VA(0x429E70u);
    cpu->esi = cpu->edi;
    if ((uint32_t)(cpu->edi) != (uint32_t)(cpu->ebx)) goto label_00029CC2;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_00029E7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x429E7Cu);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_server_wall;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429E86u); lift_push32(cpu, r); sfera_sub_0048B5E0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429E8Bu); lift_push32(cpu, r); sfera_sub_0041A0B0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1284Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.004999999888241291));
    cpu->esi = lift_pop32(cpu);
    lift_store_f32(cpu->eax + 0x1284Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_effect_manager.render_slot_count;
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(cpu->ebx)) goto label_00029F14;
    cpu->edx = g_sfera_effect_manager.render_sort_indices;
    cpu->eax = 0u;
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(cpu->ebx)) goto label_00029EC3;
    label_00029EB4: cpu->eip = LIFT_CODE_TOKEN_VA(0x429EB4u);
    lift_store16(cpu->edx + ((uint32_t)(cpu->eax) * 2u), cpu->eax & 0xFFFFu);
    cpu->ecx = g_sfera_effect_manager.render_slot_count;
    ++cpu->eax;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_00029EB4;
    label_00029EC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x429EC3u);
    lift_store8(cpu->esp + 7u, cpu->ebx & 0xFFu);
    if ((int32_t)(uint32_t)(g_sfera_effect_manager.render_slots.capacity) > (int32_t)(uint32_t)(cpu->ebx)) goto label_00029EE7;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429EDBu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_effect_manager.render_slot_count;
    cpu->edx = g_sfera_effect_manager.render_sort_indices;
    label_00029EE7: cpu->eip = LIFT_CODE_TOKEN_VA(0x429EE7u);
    cpu->eax = (uint32_t)(cpu->esp + 7u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_effect_manager.render_slots.data;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429EF8u); lift_push32(cpu, r); sfera_sub_00426A50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_effect_manager.generation;
    g_sfera_effect_manager.last_processed_generation = (uint32_t)(cpu->ecx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x70u;
    lift_return(cpu, 0u, stop_address); return;
    label_00029F14: cpu->eip = LIFT_CODE_TOKEN_VA(0x429F14u);
    cpu->edx = g_sfera_effect_manager.generation;
    cpu->ebx = lift_pop32(cpu);
    g_sfera_effect_manager.last_processed_generation = (uint32_t)(cpu->edx);
    cpu->esp += 0x70u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00429F30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x429F30u);
    cpu->esp -= 0x1A0u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(0xFFFFFFFFu)) goto label_0002A26B;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->ebx + 0x1Cu);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_00029F8A;
    cpu->eax = lift_load32(cpu->ebx + 0x28u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x136u)) goto label_00029F7A;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x137u)) goto label_00029F7A;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x138u)) goto label_00029F7A;
    lift_store32(cpu->ebx + 8u, (uint64_t)(lift_load32(cpu->ebx + 8u)) + (uint64_t)(2u) + (uint64_t)(0u));
    goto label_00029F7D;
    label_00029F7A: cpu->eip = LIFT_CODE_TOKEN_VA(0x429F7Au);
    lift_store32(cpu->ebx + 8u, (uint64_t)(lift_load32(cpu->ebx + 8u)) + 1u);
    label_00029F7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x429F7Du);
    cpu->eax = lift_load32(cpu->ebp + 0x14u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00029F94;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx + 8u)) < (int32_t)(uint32_t)(cpu->eax)) goto label_00029F94;
    label_00029F8A: cpu->eip = LIFT_CODE_TOKEN_VA(0x429F8Au);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x429F8Fu); lift_push32(cpu, r); sfera_sub_00429B20(cpu,r); if (cpu->eip != r) return; }
    goto label_0002A26A;
    label_00029F94: cpu->eip = LIFT_CODE_TOKEN_VA(0x429F94u);
    cpu->ecx = lift_load32(cpu->ebp + 0x38u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00029FAD;
    cpu->eax = lift_load32(cpu->ebx + 8u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_00029FAD;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    reinterpret_cast<BloodEffListener*>(cpu->ecx)->onEffectChanged(cpu);
    label_00029FAD: cpu->eip = LIFT_CODE_TOKEN_VA(0x429FADu);
    if ((uint32_t)(lift_load32(cpu->ebx + 0x28u)) != (uint32_t)(0x136u)) goto label_00029FCA;
    cpu->ecx = lift_load32(cpu->ebp + 0x38u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00029FCA;
    cpu->eax = lift_load32(cpu->ebx + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    reinterpret_cast<BloodEffListener*>(cpu->ecx)->onEffectChanged(cpu);
    label_00029FCA: cpu->eip = LIFT_CODE_TOKEN_VA(0x429FCAu);
    { uint64_t l=(uint64_t)(lift_load16(cpu->ebx)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,16u); }
    lift_push32(cpu, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002A014;
    cpu->eax = lift_load32(cpu->ebx + 0xCu);
    cpu->ecx = lift_load32(cpu->ebx + 0x10u);
    cpu->edx = lift_load32(cpu->ebx + 0x14u);
    lift_push32(cpu, 0x40u);
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x6Cu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x40u, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x429FEFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x429FF4u);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esp + 0xB0u, lift_x87_get(cpu, 0u));
    cpu->esp += 0xCu;
    lift_store_f32(cpu->esp + 0x90u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x7Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x68u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0002A11F;
    label_0002A014: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A014u);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A021u); lift_push32(cpu, r); sfera_sub_00455E40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A02Du); lift_push32(cpu, r); sfera_sub_0045F760(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A039u); lift_push32(cpu, r); sfera_sub_0045F920(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x60u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A045u); lift_push32(cpu, r); sfera_sub_0045FAE0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x6Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A051u); lift_push32(cpu, r); sfera_sub_00455F00(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0xACu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A060u); lift_push32(cpu, r); sfera_sub_0045FCA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0xECu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A06Fu); lift_push32(cpu, r); sfera_sub_0045FE00(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x16Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A07Eu); lift_push32(cpu, r); sfera_sub_0045FF60(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    cpu->esi = (uint32_t)(cpu->esp + 0x6Cu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->edi = (uint32_t)(cpu->esp + 0x12Cu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x50u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, 0.5);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x54u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x28u))));
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x2Cu))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x58u, cpu->edx);
    lift_store32(cpu->esp + 0x5Cu, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    label_0002A11F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A11Fu);
    lift_native_call(cpu, native_function_address32(&SI_GetInterface), LIFT_CODE_TOKEN_VA(0x42A11Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42A125u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002A143;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1B0u));
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->updateEffect(cpu);
    label_0002A143: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A143u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x1Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebp + 0xFu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store8(cpu->esp + 0xFu, cpu->eax & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002A18B;
    cpu->eax = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->activateEffect(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42A163u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0002A18B;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebp + 0xDu)), r=(uint64_t)((cpu->eax & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002A182;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) & (uint64_t)(1u))) & 0xFFu);
    cpu->eax = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->deactivateEffect(cpu);
    label_0002A182: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A182u);
    lift_store8(cpu->ebp + 0xFu, 1u);
    goto label_0002A269;
    label_0002A18B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A18Bu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x18u));
    lift_x87_push(cpu, (double)-1.0f);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0002A1D3;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x1Cu));
    LIFT_X87_COMPARE_POP2_AX();
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.environment_factor));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x18u));
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0002A1CC;
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0002A212;
    label_0002A1BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A1BEu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x1Cu));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0002A1D3;
    goto label_0002A214;
    label_0002A1CC: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A1CCu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0002A1BE;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0002A1D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A1D3u);
    cpu->ecx = lift_load32(cpu->ebp + 0x10u);
    cpu->eax = lift_load32(cpu->ebx + 8u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ecx)) goto label_0002A1E3;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    lift_store32(cpu->ebx + 8u, cpu->edx);
    label_0002A1E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A1E3u);
    if ((uint8_t)((lift_load8(cpu->esp + 0x1Cu)) & (2u)) == 0u) goto label_0002A228;
    if ((uint8_t)(lift_load8(cpu->ebp + 0xEu)) == (uint8_t)(0u)) goto label_0002A1FA;
    cpu->ecx = cpu->ebp;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->renderEffect(cpu);
    label_0002A1FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A1FAu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ebx + 8u)))));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->queryEffectState(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42A210u);
    goto label_0002A269;
    label_0002A212: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A212u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0002A214: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A214u);
    if ((uint8_t)(lift_load8(cpu->ebp + 0xDu)) != (uint8_t)(0u)) goto label_0002A269;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->deactivateEffect(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42A226u);
    goto label_0002A269;
    label_0002A228: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A228u);
    if ((uint8_t)(lift_load8(cpu->ebp + 0xDu)) == (uint8_t)(0u)) goto label_0002A238;
    cpu->ecx = cpu->ebp;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->renderEffect(cpu);
    label_0002A238: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A238u);
    cpu->edx = lift_load8(cpu->esp + 0xFu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->ebx + 8u)))));
    cpu->ecx = (uint32_t)(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(lift_load16(cpu->ebx)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,16u); }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ecx) * 4u) + 1u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->initializeEffect(cpu);
    label_0002A269: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A269u);
    cpu->esi = lift_pop32(cpu);
    label_0002A26A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A26Au);
    cpu->ebp = lift_pop32(cpu);
    label_0002A26B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A26Bu);
    cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x1A0u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042A290(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42A290u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x10u)) == (uint32_t)(cpu->edi)) goto label_0002A2B8;
    cpu->edx = (uint32_t)(cpu->edi + 0x48u);
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ItemArray.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A2A9u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A2B2u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    label_0002A2B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A2B8u);
    cpu->ebx = lift_load32(cpu->esi + 4u);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(lift_load32(cpu->esi)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebx = v; }
    lift_store32(cpu->esi + 0x14u, cpu->edi);
    cpu->ebx = lift_shift_arithmetic(cpu, cpu->ebx, (uint32_t)(2u), 32u);
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(cpu->edi)) goto label_0002A2F2;
    label_0002A2D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A2D0u);
    cpu->edx = 0x4Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ItemArray.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A2DFu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u));
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A2EAu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    ++cpu->edi;
    cpu->esp += 4u;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->ebx)) goto label_0002A2D0;
    label_0002A2F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A2F2u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ecx)) goto label_0002A31A;
    cpu->eax = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x42A30Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42A312u);
    cpu->esp += 0xCu;
    cpu->ebx += cpu->edi;
    lift_store32(cpu->esi + 4u, cpu->ebx);
    label_0002A31A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A31Au);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042A320(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42A320u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x18u);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A32Du); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0u;
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_0002A367;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->eax + 0xCu);
    lift_store16(cpu->eax + 0x14u, cpu->edx & 0xFFFFu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0002A360;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->esi = lift_load32(cpu->edx);
    lift_store32(cpu->ecx, cpu->esi);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    label_0002A360: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A360u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_0002A367: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A367u);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A391u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x42A391u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042A3A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42A3A0u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if ((uint32_t)(g_sfera_effect_manager.initialized) == (uint32_t)(cpu->edi)) goto label_0002A47E;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A3B5u); lift_push32(cpu, r); sfera_sub_0041AE00(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A3BAu); lift_push32(cpu, r); sfera_sub_0047FBA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = g_sfera_effect_manager.active_effects.first;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_0002A3EB;
    label_0002A3C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A3C4u);
    cpu->ecx = lift_load32(cpu->esi + 0x1Cu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0002A3D5;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->releaseEffect(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42A3D2u);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    label_0002A3D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A3D5u);
    cpu->ecx = lift_load32(cpu->esi + 0x20u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0002A3E4;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A3E1u); lift_push32(cpu, r); sfera_sub_00496FE0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x20u, cpu->edi);
    label_0002A3E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A3E4u);
    cpu->esi = lift_load32(cpu->esi + 0x30u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->edi)) goto label_0002A3C4;
    label_0002A3EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A3EBu);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_effect_items;
    g_sfera_effect_manager.active_effects.first = (uint32_t)(cpu->edi);
    g_sfera_effect_manager.active_effects.last = (uint32_t)(cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A401u); lift_push32(cpu, r); sfera_sub_0042A290(cpu,r); if (cpu->eip != r) return; }
    g_sfera_effect_manager.active_effect_count = (uint32_t)(cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A40Cu); lift_push32(cpu, r); sfera_sub_00425D80(cpu,r); if (cpu->eip != r) return; }
    g_sfera_effect_manager.initialized = (uint32_t)(cpu->edi);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(g_sfera_effect_manager.effect_listeners.size) <= (uint32_t)(cpu->edi)) goto label_0002A425;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_effect_manager.effect_listeners;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2A425u); lift_push32(cpu, r); sfera_sub_00429A30(cpu,r); if (cpu->eip != r) return; }
    label_0002A425: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A425u);
    cpu->edx = 0x2DFu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A434u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_effect_manager.render_sort_indices;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A43Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->edx = 0x2E0u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A451u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_effect_manager.render_index_buffer;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A45Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->edx = 0x2E1u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A46Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_effect_manager.render_batch_buffer;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A47Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0002A47E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A47Eu);
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042A480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42A480u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edx = 0x60u;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ItemArray.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A496u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 0x3Cu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A4AFu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    cpu->esp += 4u;
    cpu->edx = 0x62u;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ItemArray.h";
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A4C7u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->eax -= lift_load32(cpu->esi);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    ++cpu->eax;
    { int64_t v=(int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(lift_load32(cpu->esi + 0x18u)); cpu->eax= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->edx = 4u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A4EAu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002A523;
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x42A500u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42A505u);
    cpu->esp += 0xCu;
    cpu->edx = 0x67u;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ItemArray.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A517u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A520u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0002A523: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A523u);
    cpu->ecx = 0u;
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    cpu->eax = cpu->ebp;
    cpu->ebx = (uint32_t)(cpu->ecx + 1u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x18u)) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_0002A548;
    label_0002A532: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A532u);
    cpu->edx = lift_load32(cpu->esi + 0x14u);
    cpu->edi = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->edi + ((uint32_t)(cpu->edx) * 4u), cpu->eax);
    lift_store32(cpu->esi + 0x14u, (uint64_t)(lift_load32(cpu->esi + 0x14u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u));
    cpu->ecx += cpu->ebx;
    cpu->eax += 0x3Cu;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x18u))) goto label_0002A532;
    label_0002A548: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A548u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_0002A5C4;
    cpu->edx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->ecx)) goto label_0002A5C4;
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 8u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_0002A5AC;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(0x3FFFFFFEu)) goto label_0002A57E;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x2A57Eu);
    label_0002A57E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A57Eu);
    cpu->ecx -= cpu->edx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0002A5AC;
    cpu->edx = cpu->ecx;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->ebx = 0x3FFFFFFFu;
    cpu->ebx -= cpu->edx;
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(cpu->ecx)) goto label_0002A59C;
    cpu->ecx = 0u;
    goto label_0002A59E;
    label_0002A59C: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A59Cu);
    cpu->ecx += cpu->edx;
    label_0002A59E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A59Eu);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_0002A5A4;
    cpu->ecx = cpu->eax;
    label_0002A5A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A5A4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2A5ACu); lift_push32(cpu, r); sfera_sub_00429830(cpu,r); if (cpu->eip != r) return; }
    label_0002A5AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A5ACu);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002A61B;
    cpu->edx = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(4u) + (uint64_t)(0u));
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0002A5C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A5C4u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_0002A612;
    cpu->edx = lift_load32(cpu->esi);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(0x3FFFFFFEu)) goto label_0002A5E4;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x2A5E4u);
    label_0002A5E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A5E4u);
    cpu->ecx -= cpu->edx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0002A612;
    cpu->edx = cpu->ecx;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->edi = 0x3FFFFFFFu;
    cpu->edi -= cpu->edx;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->ecx)) goto label_0002A602;
    cpu->ecx = 0u;
    goto label_0002A604;
    label_0002A602: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A602u);
    cpu->ecx += cpu->edx;
    label_0002A604: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A604u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_0002A60A;
    cpu->ecx = cpu->eax;
    label_0002A60A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A60Au);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2A612u); lift_push32(cpu, r); sfera_sub_00429830(cpu,r); if (cpu->eip != r) return; }
    label_0002A612: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A612u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002A61B;
    lift_store32(cpu->eax, cpu->ebp);
    label_0002A61B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A61Bu);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(4u) + (uint64_t)(0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042A630(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42A630u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = 0u;
    if ((uint32_t)(g_sfera_effect_manager.initialized) != (uint32_t)(cpu->esi)) goto label_0002AA77;
    if ((uint32_t)(g_sfera_effect_manager.deferred_lifecycle) == (uint32_t)(cpu->esi)) goto label_0002A671;
    g_sfera_effect_manager.deferred_lifecycle = (uint32_t)(cpu->esi);
    goto label_0002A676;
    label_0002A671: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A671u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2A676u); lift_push32(cpu, r); sfera_sub_0042A3A0(cpu,r); if (cpu->eip != r) return; }
    label_0002A676: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A676u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A67Bu); lift_push32(cpu, r); sfera_sub_00425AA0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A680u); lift_push32(cpu, r); sfera_sub_00428BF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0x278u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A68Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x4E20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A699u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->edx = 0x279u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    g_sfera_effect_manager.render_sort_indices = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A6B0u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xEA60u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A6BAu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->edx = 0x27Au;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    g_sfera_effect_manager.render_index_buffer = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A6D1u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7D00u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A6DBu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    g_sfera_effect_manager.render_batch_buffer = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A6E8u); lift_push32(cpu, r); sfera_sub_0041AD50(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A6EDu); lift_push32(cpu, r); sfera_sub_0047FB10(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0x282u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A6FCu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x88u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A706u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_0002A71E;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A71Cu); lift_push32(cpu, r); sfera_sub_0044B180(cpu,r); if (cpu->eip != r) return; }
    goto label_0002A720;
    label_0002A71E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A71Eu);
    cpu->eax = 0u;
    label_0002A720: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A720u);
    cpu->ecx = g_sfera_effect_manager.effect_definition_head;
    cpu->edi |= 0xFFFFFFFFu;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->esi)) goto label_0002A73B;
    g_sfera_effect_manager.effect_definition_head = (uint32_t)(cpu->eax);
    lift_store32(cpu->eax + 0x24u, cpu->esi);
    goto label_0002A751;
    label_0002A73B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A73Bu);
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_0002A74B;
    label_0002A742: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A742u);
    cpu->ecx = cpu->edx;
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->esi)) goto label_0002A742;
    label_0002A74B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A74Bu);
    lift_store32(cpu->ecx + 0x20u, cpu->eax);
    lift_store32(cpu->eax + 0x24u, cpu->ecx);
    label_0002A751: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A751u);
    cpu->edx = 0x283u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_store32(cpu->eax + 0x20u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A763u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x60u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A76Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 1u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_0002A786;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A784u); lift_push32(cpu, r); sfera_sub_0042AFC0(cpu,r); if (cpu->eip != r) return; }
    goto label_0002A788;
    label_0002A786: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A786u);
    cpu->eax = 0u;
    label_0002A788: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A788u);
    cpu->ecx = g_sfera_effect_manager.effect_definition_head;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->esi)) goto label_0002A7A0;
    g_sfera_effect_manager.effect_definition_head = (uint32_t)(cpu->eax);
    lift_store32(cpu->eax + 0x24u, cpu->esi);
    goto label_0002A7B6;
    label_0002A7A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A7A0u);
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_0002A7B0;
    label_0002A7A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A7A7u);
    cpu->ecx = cpu->edx;
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->esi)) goto label_0002A7A7;
    label_0002A7B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A7B0u);
    lift_store32(cpu->ecx + 0x20u, cpu->eax);
    lift_store32(cpu->eax + 0x24u, cpu->ecx);
    label_0002A7B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A7B6u);
    cpu->edx = 0x284u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_store32(cpu->eax + 0x20u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A7C8u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A7CFu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 2u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_0002A7EB;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A7E9u); lift_push32(cpu, r); sfera_sub_0042B150(cpu,r); if (cpu->eip != r) return; }
    goto label_0002A7ED;
    label_0002A7EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A7EBu);
    cpu->eax = 0u;
    label_0002A7ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A7EDu);
    cpu->ecx = g_sfera_effect_manager.effect_definition_head;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->esi)) goto label_0002A805;
    g_sfera_effect_manager.effect_definition_head = (uint32_t)(cpu->eax);
    lift_store32(cpu->eax + 0x24u, cpu->esi);
    goto label_0002A81F;
    label_0002A805: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A805u);
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_0002A819;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0002A810: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A810u);
    cpu->ecx = cpu->edx;
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->esi)) goto label_0002A810;
    label_0002A819: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A819u);
    lift_store32(cpu->ecx + 0x20u, cpu->eax);
    lift_store32(cpu->eax + 0x24u, cpu->ecx);
    label_0002A81F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A81Fu);
    cpu->edx = 0x285u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_store32(cpu->eax + 0x20u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A831u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x74u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A838u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 3u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_0002A854;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A852u); lift_push32(cpu, r); sfera_sub_0042B320(cpu,r); if (cpu->eip != r) return; }
    goto label_0002A856;
    label_0002A854: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A854u);
    cpu->eax = 0u;
    label_0002A856: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A856u);
    cpu->ecx = g_sfera_effect_manager.effect_definition_head;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->esi)) goto label_0002A86E;
    g_sfera_effect_manager.effect_definition_head = (uint32_t)(cpu->eax);
    lift_store32(cpu->eax + 0x24u, cpu->esi);
    goto label_0002A884;
    label_0002A86E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A86Eu);
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_0002A87E;
    label_0002A875: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A875u);
    cpu->ecx = cpu->edx;
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->esi)) goto label_0002A875;
    label_0002A87E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A87Eu);
    lift_store32(cpu->ecx + 0x20u, cpu->eax);
    lift_store32(cpu->eax + 0x24u, cpu->ecx);
    label_0002A884: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A884u);
    cpu->edx = 0x286u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_store32(cpu->eax + 0x20u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A896u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x74u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A89Du); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 4u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_0002A8B9;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A8B7u); lift_push32(cpu, r); sfera_sub_0042B720(cpu,r); if (cpu->eip != r) return; }
    goto label_0002A8BB;
    label_0002A8B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A8B9u);
    cpu->eax = 0u;
    label_0002A8BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A8BBu);
    cpu->ecx = g_sfera_effect_manager.effect_definition_head;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->esi)) goto label_0002A8D3;
    g_sfera_effect_manager.effect_definition_head = (uint32_t)(cpu->eax);
    lift_store32(cpu->eax + 0x24u, cpu->esi);
    goto label_0002A8EF;
    label_0002A8D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A8D3u);
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_0002A8E9;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0002A8E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A8E0u);
    cpu->ecx = cpu->edx;
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->esi)) goto label_0002A8E0;
    label_0002A8E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A8E9u);
    lift_store32(cpu->ecx + 0x20u, cpu->eax);
    lift_store32(cpu->eax + 0x24u, cpu->ecx);
    label_0002A8EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A8EFu);
    cpu->edx = 0x288u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_store32(cpu->eax + 0x20u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A901u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1A8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A90Bu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 5u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_0002A938;
    lift_x87_push(cpu, (double)5.0f);
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0x2D0u);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A936u); lift_push32(cpu, r); sfera_sub_0042C570(cpu,r); if (cpu->eip != r) return; }
    goto label_0002A93A;
    label_0002A938: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A938u);
    cpu->eax = 0u;
    label_0002A93A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A93Au);
    cpu->ecx = g_sfera_effect_manager.effect_definition_head;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->esi)) goto label_0002A952;
    g_sfera_effect_manager.effect_definition_head = (uint32_t)(cpu->eax);
    lift_store32(cpu->eax + 0x24u, cpu->esi);
    goto label_0002A96F;
    label_0002A952: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A952u);
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_0002A969;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0002A960: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A960u);
    cpu->ecx = cpu->edx;
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->esi)) goto label_0002A960;
    label_0002A969: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A969u);
    lift_store32(cpu->ecx + 0x20u, cpu->eax);
    lift_store32(cpu->eax + 0x24u, cpu->ecx);
    label_0002A96F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A96Fu);
    cpu->edx = 0x289u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_store32(cpu->eax + 0x20u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A981u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1A8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A98Bu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 6u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_0002A9B8;
    lift_x87_push(cpu, (double)10.0f);
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0x2D1u);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42A9B6u); lift_push32(cpu, r); sfera_sub_0042C570(cpu,r); if (cpu->eip != r) return; }
    goto label_0002A9BA;
    label_0002A9B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A9B8u);
    cpu->eax = 0u;
    label_0002A9BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A9BAu);
    cpu->ecx = g_sfera_effect_manager.effect_definition_head;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->esi)) goto label_0002A9D2;
    g_sfera_effect_manager.effect_definition_head = (uint32_t)(cpu->eax);
    lift_store32(cpu->eax + 0x24u, cpu->esi);
    goto label_0002A9EF;
    label_0002A9D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A9D2u);
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_0002A9E9;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0002A9E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A9E0u);
    cpu->ecx = cpu->edx;
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->esi)) goto label_0002A9E0;
    label_0002A9E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A9E9u);
    lift_store32(cpu->ecx + 0x20u, cpu->eax);
    lift_store32(cpu->eax + 0x24u, cpu->ecx);
    label_0002A9EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x42A9EFu);
    cpu->edx = 0x28Au;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_store32(cpu->eax + 0x20u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42AA01u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1A8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42AA0Bu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 7u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_0002AA38;
    lift_x87_push(cpu, (double)15.0f);
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0x2D2u);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42AA36u); lift_push32(cpu, r); sfera_sub_0042C570(cpu,r); if (cpu->eip != r) return; }
    goto label_0002AA3A;
    label_0002AA38: cpu->eip = LIFT_CODE_TOKEN_VA(0x42AA38u);
    cpu->eax = 0u;
    label_0002AA3A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42AA3Au);
    cpu->ecx = g_sfera_effect_manager.effect_definition_head;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->esi)) goto label_0002AA4E;
    g_sfera_effect_manager.effect_definition_head = (uint32_t)(cpu->eax);
    lift_store32(cpu->eax + 0x24u, cpu->esi);
    goto label_0002AA64;
    label_0002AA4E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42AA4Eu);
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_0002AA5E;
    label_0002AA55: cpu->eip = LIFT_CODE_TOKEN_VA(0x42AA55u);
    cpu->ecx = cpu->edx;
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(cpu->esi)) goto label_0002AA55;
    label_0002AA5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42AA5Eu);
    lift_store32(cpu->ecx + 0x20u, cpu->eax);
    lift_store32(cpu->eax + 0x24u, cpu->ecx);
    label_0002AA64: cpu->eip = LIFT_CODE_TOKEN_VA(0x42AA64u);
    lift_store32(cpu->eax + 0x20u, cpu->esi);
    g_sfera_effect_manager.render_slot_count = (uint32_t)(cpu->esi);
    g_sfera_effect_manager.initialized = (uint32_t)(1u);
    label_0002AA77: cpu->eip = LIFT_CODE_TOKEN_VA(0x42AA77u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042AA90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42AA90u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_effect_manager.effect_listeners;
    cpu->esi = cpu->edx;
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42AAB1u); lift_push32(cpu, r); sfera_sub_00429A80(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->edx) == (uint32_t)(g_sfera_effect_manager.effect_listeners.sentinel)) goto label_0002AAD6;
    lift_push32(cpu, (uint32_t)(uintptr_t)"EM_RegisterEffectListener::Multiple listeners not implemented.");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42AAC7u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42AACDu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
    label_0002AAD6: cpu->eip = LIFT_CODE_TOKEN_VA(0x42AAD6u);
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_effect_manager.effect_listeners;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42AAEFu); lift_push32(cpu, r); sfera_sub_0042A320(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_effect_manager.effect_listeners;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42AAFFu); lift_push32(cpu, r); sfera_sub_004298B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042AB10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42AB10u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->edx;
    cpu->ebp = 0u;
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    if ((uint32_t)(cpu->ebx) != (uint32_t)(cpu->ebp)) goto label_0002AB4C;
    lift_push32(cpu, 0x342u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42AB43u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42AB49u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    label_0002AB4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x42AB4Cu);
    if ((uint32_t)(g_sfera_effect_manager.active_effect_count) < (uint32_t)(0x1770u)) goto label_0002AB6D;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_0002AB6D: cpu->eip = LIFT_CODE_TOKEN_VA(0x42AB6Du);
    if ((uint32_t)(cpu->esi) < (uint32_t)(0x1388u)) goto label_0002AB92;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42AB80u); lift_push32(cpu, r); sfera_sub_004977E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_0002AB92: cpu->eip = LIFT_CODE_TOKEN_VA(0x42AB92u);
    cpu->ecx = g_sfera_effect_manager.effect_definition_head;
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_0002AD0A;
    label_0002ABA1: cpu->eip = LIFT_CODE_TOKEN_VA(0x42ABA1u);
    if ((uint32_t)(lift_load32(cpu->ecx + 8u)) == (uint32_t)(cpu->esi)) goto label_0002ABC3;
    cpu->ecx = lift_load32(cpu->ecx + 0x20u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->ebp)) goto label_0002ABA1;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_0002ABC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x42ABC3u);
    reinterpret_cast<IEffectManager*>(cpu->ecx)->createEffectResources(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42ABCAu);
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebp)) goto label_0002AD0A;
    if ((uint32_t)(g_sfera_effect_manager.effects_enabled) == (uint32_t)(cpu->ebp)) goto label_0002ABED;
    cpu->ecx = cpu->edi;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->isEffectComplete(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42ABE5u);
    if ((int32_t)(uint32_t)(cpu->eax) > 0) goto label_0002AD0A;
    label_0002ABED: cpu->eip = LIFT_CODE_TOKEN_VA(0x42ABEDu);
    if ((uint32_t)(g_sfera_effect_items.free_count) != (uint32_t)(cpu->ebp)) goto label_0002ABFF;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_effect_items;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2ABFFu); lift_push32(cpu, r); sfera_sub_0042A480(cpu,r); if (cpu->eip != r) return; }
    label_0002ABFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x42ABFFu);
    cpu->eax = g_sfera_effect_items.free_count;
    cpu->ecx = g_sfera_effect_items.free_items;
    --cpu->eax;
    g_sfera_effect_items.free_count = (uint32_t)(cpu->eax);
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42AC1Cu); lift_push32(cpu, r); sfera_sub_00456040(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0002AC54;
    cpu->ecx = cpu->edi;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->releaseEffect(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42AC29u);
    cpu->ecx = g_sfera_effect_items.free_count;
    cpu->edx = g_sfera_effect_items.free_items;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u), cpu->esi);
    ++g_sfera_effect_items.free_count;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_0002AC54: cpu->eip = LIFT_CODE_TOKEN_VA(0x42AC54u);
    cpu->eax = 0u;
    cpu->edx = cpu->ebx;
    cpu->ecx = 0u;
    lift_store32(cpu->esi + 8u, cpu->ebp);
    lift_store16(cpu->esi, cpu->eax & 0xFFFFu);
    lift_store32(cpu->esi + 4u, cpu->ebx);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    lift_store32(cpu->esi + 0x20u, cpu->ebp);
    lift_store32(cpu->esi + 0x18u, LIFT_CALLBACK(sfera_sub_00429F30));
    lift_store32(cpu->esi + 0x24u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42AC78u); lift_push32(cpu, r); sfera_sub_00425B20(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esi + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = 0xFFFFu;
    lift_store32(cpu->esi + 0x28u, cpu->ecx);
    lift_store16(cpu->esi + 2u, cpu->edx & 0xFFFFu);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->esi + 0x30u, cpu->ebp);
    lift_store32(cpu->esi + 0x34u, cpu->ebp);
    lift_store32(cpu->esi + 0x38u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42AC9Fu); lift_push32(cpu, r); sfera_sub_00455E40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->edi + 0x2Cu, cpu->eax);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->edi + 0x30u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->edi + 0x34u, cpu->edx);
    ++g_sfera_effect_manager.active_effect_count;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_effect_manager.active_effects;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42ACC5u); lift_push32(cpu, r); sfera_sub_00425C00(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_effect_manager.effect_listeners;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42ACD9u); lift_push32(cpu, r); sfera_sub_00429A80(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(g_sfera_effect_manager.effect_listeners.sentinel)) goto label_0002AD20;
    cpu->edx = lift_load32(cpu->eax + 0x10u);
    lift_store32(cpu->edi + 0x38u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2Cu));
    cpu->eax = lift_load32(cpu->eax + 0x10u);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, cpu->edi);
    reinterpret_cast<BloodEffListener*>(cpu->ecx)->onEffectAttached(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42ACFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0002AD20;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2AD0Au); lift_push32(cpu, r); sfera_sub_00429B20(cpu,r); if (cpu->eip != r) return; }
    label_0002AD0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42AD0Au);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_0002AD20: cpu->eip = LIFT_CODE_TOKEN_VA(0x42AD20u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042AD40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42AD40u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_effect_manager.effect_definition_head;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x20u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x20u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    cpu->ebx = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002AD79;
    cpu->ebp = native_function_address32(&::_stricmp);
    label_0002AD60: cpu->eip = LIFT_CODE_TOKEN_VA(0x42AD60u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x2AD67u), LIFT_CODE_TOKEN_RVA(0x2AD65u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42AD67u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002AD82;
    cpu->esi = lift_load32(cpu->edi);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x20u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = (uint32_t)(cpu->esi + 0x20u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002AD60;
    label_0002AD79: cpu->eip = LIFT_CODE_TOKEN_VA(0x42AD79u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0002AD82: cpu->eip = LIFT_CODE_TOKEN_VA(0x42AD82u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_0002AD79;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0042AB10(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042ADA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42ADA0u);
    cpu->esp -= 0x3Cu;
    cpu->eax = lift_load32(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ebp);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    cpu->ebp = cpu->ecx;
    if ((uint32_t)(g_sfera_effect_manager.flare_enabled) == (uint32_t)(cpu->eax)) goto label_0002ADD4;
    cpu->ecx = 0u;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    g_sfera_effect_manager.flare_enabled = (uint32_t)(cpu->eax);
    ++cpu->ecx;
    g_sfera_effect_manager.flare_transition = (uint32_t)(cpu->ecx);
    label_0002ADD4: cpu->eip = LIFT_CODE_TOKEN_VA(0x42ADD4u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0002ADE4;
    if ((uint32_t)(g_sfera_effect_manager.flare_alpha) == (uint32_t)(cpu->eax)) goto label_0002AF9A;
    label_0002ADE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x42ADE4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(uintptr_t)"fx_flare";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42ADF1u); lift_push32(cpu, r); sfera_sub_00499D70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x50u);
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 4u));
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(7u), 32u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / ((double)(((int32_t)(g_sfera_graphics_runtime.display_width)))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42AE12u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x1E0u);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    cpu->edi = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / ((double)(((int32_t)(g_sfera_graphics_runtime.display_height)))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42AE2Du); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    cpu->ebx = cpu->eax;
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    cpu->eax = cpu->edi;
    lift_x87_push(cpu, 1.0);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebp = v; }
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u));
    cpu->ecx = cpu->ebx;
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) - (uint64_t)(cpu->ecx) - (uint64_t)(0u));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.3499999940395355f);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.environment_factor));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 2550.0);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0002AEBD;
    lift_store16(cpu->esp + 0x10u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x10u);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (0.3499999940395355) - (lift_x87_get(cpu, 0u)));
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x14u));
    lift_store64(cpu->esp + 0x14u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x10u));
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(0xFFu)) goto label_0002AEBD;
    cpu->ecx = 0xFFu;
    label_0002AEBD: cpu->eip = LIFT_CODE_TOKEN_VA(0x42AEBDu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)"333\077..\\ShareClientSeverCode\\CheckFiles.cpp"));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0002AF07;
    lift_store16(cpu->esp + 0x10u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x10u);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (0.699999988079071));
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x14u));
    lift_store64(cpu->esp + 0x14u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x10u));
    if ((uint32_t)(cpu->ecx) <= (uint32_t)(0xFFu)) goto label_0002AF09;
    cpu->ecx = 0xFFu;
    goto label_0002AF09;
    label_0002AF07: cpu->eip = LIFT_CODE_TOKEN_VA(0x42AF07u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0002AF09: cpu->eip = LIFT_CODE_TOKEN_VA(0x42AF09u);
    lift_x87_push(cpu, (double)0.1899999976158142f);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0002AF27;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 0.8299999833106995);
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002AF2B;
    goto label_0002AF29;
    label_0002AF27: cpu->eip = LIFT_CODE_TOKEN_VA(0x42AF27u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0002AF29: cpu->eip = LIFT_CODE_TOKEN_VA(0x42AF29u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    label_0002AF2B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42AF2Bu);
    cpu->esi = g_sfera_effect_manager.flare_alpha;
    { int64_t v=(int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->ecx); cpu->esi= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(8u), 32u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_0002AF97;
    cpu->ecx = 2u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42AF45u); lift_push32(cpu, r); sfera_sub_004CE0E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx += lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    cpu->esp -= 0x10u;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x2Cu)))));
    cpu->ecx = cpu->esi;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(0x18u), 32u);
    cpu->ecx |= 0xFF640Fu;
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x34u)))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x38u)))));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42AF90u); lift_push32(cpu, r); sfera_sub_004CEDA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2AF97u); lift_push32(cpu, r); sfera_sub_004CE0E0(cpu,r); if (cpu->eip != r) return; }
    label_0002AF97: cpu->eip = LIFT_CODE_TOKEN_VA(0x42AF97u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0002AF9A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42AF9Au);
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x3Cu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042AFB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42AFB0u);
    g_sfera_effect_manager.detail_setting = cpu->ecx;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042AFC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42AFC0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42AFEFu); lift_push32(cpu, r); sfera_sub_00425E30(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"spiral.effect0");
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x24u, 0u);
    std::construct_at(reinterpret_cast<CSpiralEffect*>(cpu->esi));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B009u); lift_push32(cpu, r); sfera_sub_00425EB0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)-0.4000000059604645f);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    cpu->eax = 0x190u;
    lift_x87_push(cpu, (double)-1.0f);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.4000000059604645f);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x3Cu, cpu->eax);
    lift_x87_push(cpu, (double)0.10000000149011612f);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0x40u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esi + 0x48u, cpu->eax);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0x44u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esi + 0x4Cu, cpu->ecx);
    lift_store32(cpu->esi + 8u, 0u);
    lift_store32(cpu->esi + 0x5Cu, 0xFFFFFFFFu);
    lift_store8(cpu->esi + 0x54u, 1u);
    lift_store32(cpu->esi + 0x50u, cpu->edx);
    lift_store32(cpu->esi + 0x58u, 0x50u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042B0A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42B0A0u);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042B0B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42B0B0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->edx = 0x120u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Effects.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B0E1u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x60u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B0E8u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 8u, cpu->eax);
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_0002B102;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B100u); lift_push32(cpu, r); sfera_sub_0042AFC0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    label_0002B102: cpu->eip = LIFT_CODE_TOKEN_VA(0x42B102u);
    cpu->ecx = (uint32_t)(uintptr_t)"fx_flare";
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B114u); lift_push32(cpu, r); sfera_sub_00499D70(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x5Cu, cpu->eax);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042B130(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42B130u);
    lift_push32(cpu, 0x12Eu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Effects.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B144u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B14Au); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042B150(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42B150u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B180u); lift_push32(cpu, r); sfera_sub_00425E30(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0u;
    lift_push32(cpu, (uint32_t)(uintptr_t)"molniya.effect110");
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x28u, cpu->edi);
    std::construct_at(reinterpret_cast<CMolEffect*>(cpu->esi));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B198u); lift_push32(cpu, r); sfera_sub_00425EB0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esi + 0x68u, lift_x87_get(cpu, 0u));
    cpu->eax |= 0xFFFFFFFFu;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0x5Cu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esi + 0x60u, cpu->edx);
    lift_store32(cpu->esi + 0x70u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, 1u);
    lift_store32(cpu->esi + 8u, 0x6Eu);
    lift_store32(cpu->esi + 0x64u, cpu->ecx);
    lift_store32(cpu->esi + 0x6Cu, cpu->edi);
    lift_store32(cpu->esi + 0x74u, cpu->edi);
    lift_store32(cpu->esi + 0x78u, cpu->edi);
    lift_store32(cpu->esi + 0x58u, 4u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042B200(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42B200u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x78u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = lift_load32(cpu->esi + 0x74u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002B242;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0002B237;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xACu));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0002B22A;
    cpu->eax = 1u;
    goto label_0002B22C;
    label_0002B22A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42B22Au);
    cpu->eax = 0u;
    label_0002B22C: cpu->eip = LIFT_CODE_TOKEN_VA(0x42B22Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2B237u); lift_push32(cpu, r); sfera_sub_00496650(cpu,r); if (cpu->eip != r) return; }
    label_0002B237: cpu->eip = LIFT_CODE_TOKEN_VA(0x42B237u);
    lift_store32(cpu->esi + 0x78u, 1u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0002B242: cpu->eip = LIFT_CODE_TOKEN_VA(0x42B242u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0002B257;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_push32(cpu, cpu->ecx);
    cpu->esi += 0x5Cu;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2B257u); lift_push32(cpu, r); sfera_sub_00496BD0(cpu,r); if (cpu->eip != r) return; }
    label_0002B257: cpu->eip = LIFT_CODE_TOKEN_VA(0x42B257u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042B260(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42B260u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->edx = 0x1D9u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Effects.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B291u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B298u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 8u, cpu->eax);
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_0002B2B2;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B2B0u); lift_push32(cpu, r); sfera_sub_0042B150(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    label_0002B2B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x42B2B2u);
    cpu->ecx = (uint32_t)(uintptr_t)"fx_light";
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B2C4u); lift_push32(cpu, r); sfera_sub_00499D70(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x70u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_0002B2DF;
    lift_push32(cpu, (uint32_t)(uintptr_t)"CMolEffect::Texture not found 'fx_light'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B2D6u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B2DCu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_0002B2DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x42B2DFu);
    cpu->ecx = 0x6Eu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B2E9u); lift_push32(cpu, r); sfera_sub_00497910(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x74u, cpu->eax);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042B300(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42B300u);
    lift_push32(cpu, 0x1EBu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Effects.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B314u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B31Au); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042B320(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42B320u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B34Fu); lift_push32(cpu, r); sfera_sub_00425E30(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"blade");
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x24u, 0u);
    std::construct_at(reinterpret_cast<CBladeEffect*>(cpu->esi));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B369u); lift_push32(cpu, r); sfera_sub_00425EB0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esi + 0x68u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x10u, 0x40u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x14u, 0x20u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esi + 0x5Cu, cpu->eax);
    lift_store32(cpu->esi + 0x60u, cpu->ecx);
    lift_store32(cpu->esi + 8u, 0x154u);
    lift_store32(cpu->esi + 0x64u, cpu->edx);
    lift_store32(cpu->esi + 0x6Cu, 0u);
    lift_store32(cpu->esi + 0x70u, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x58u, 4u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042B3D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42B3D0u);
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042B3E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42B3E0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->edx = 0x29Cu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Effects.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B411u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x74u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B418u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 8u, cpu->eax);
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->esi)) goto label_0002B432;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B430u); lift_push32(cpu, r); sfera_sub_0042B320(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    label_0002B432: cpu->eip = LIFT_CODE_TOKEN_VA(0x42B432u);
    cpu->ecx = (uint32_t)(uintptr_t)"fx_blade";
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B444u); lift_push32(cpu, r); sfera_sub_00499D70(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x70u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_0002B45F;
    lift_push32(cpu, (uint32_t)(uintptr_t)"CBladeEffect::Texture not found 'fx_blade'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B456u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B45Cu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_0002B45F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42B45Fu);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042B480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42B480u);
    lift_push32(cpu, 0x2ACu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Effects.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B494u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B49Au); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x10u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042B4A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42B4A0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    std::construct_at(reinterpret_cast<CGazerLakeEffect*>(cpu->ebx));
    lift_store32(cpu->esp + 0x1Cu, 0u);
    cpu->esi = (uint32_t)(cpu->ebx + 0x68u);
    cpu->edi = 0x10u;
    label_0002B4E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x42B4E0u);
    if ((uint32_t)(lift_load32(cpu->esi)) == (uint32_t)(0u)) goto label_0002B503;
    cpu->edx = 0x2DCu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Effects.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B4F4u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0002B503;
    lift_push32(cpu, 1u);
    reinterpret_cast<IEffectManager*>(cpu->ecx)->destroyEffect(cpu);
    label_0002B503: cpu->eip = LIFT_CODE_TOKEN_VA(0x42B503u);
    cpu->esi += 0x14u;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002B4E0;
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->esp + 0x1Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B518u); lift_push32(cpu, r); sfera_sub_00425E70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042B530(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42B530u);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx);
    lift_x87_push(cpu, (double)-1.0f);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x5Cu);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_divide_accumulator(cpu, lift_load32(cpu->esi + 0x60u), 32u, 1u);
    cpu->ebx = lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->edx) != 0u) goto label_0002B63A;
    cpu->edi = 0u;
    cpu->ecx = (uint32_t)(cpu->esi + 0x6Cu);
    label_0002B562: cpu->eip = LIFT_CODE_TOKEN_VA(0x42B562u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0002B57D;
    ++cpu->edi;
    cpu->ecx += 0x14u;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(0x10u)) goto label_0002B562;
    goto label_0002B63A;
    label_0002B57D: cpu->eip = LIFT_CODE_TOKEN_VA(0x42B57Du);
    cpu->ebp = native_function_address32(&::rand);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x2B587u), LIFT_CODE_TOKEN_RVA(0x2B585u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42B587u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (6.283185958862305));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x2B5A9u), LIFT_CODE_TOKEN_RVA(0x2B5A7u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42B5A9u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (0.5));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.1415929794311523));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B5D8u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->eax = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 4u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = (uint32_t)(cpu->esi + ((uint32_t)(cpu->eax) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B5F3u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x64u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->ebp + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B60Eu); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->ecx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 4u) + 0x1Eu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x64u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->ebp + 0x74u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ebp + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)-1.0f);
    label_0002B63A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42B63Au);
    lift_store32(cpu->esi + 0x5Cu, (uint64_t)(lift_load32(cpu->esi + 0x5Cu)) + (uint64_t)(2u) + (uint64_t)(0u));
    cpu->edi = lift_load32(cpu->esp + 0x48u);
    cpu->esi += 0x6Cu;
    cpu->ebp = 0x10u;
    label_0002B64A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42B64Au);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0002B6E8;
    cpu->ecx = lift_load32(cpu->esi + 0xFFFFFFFCu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0002B6E8;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (2.0));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)192.0f);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0002B697;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u));
    goto label_0002B6E8;
    label_0002B697: cpu->eip = LIFT_CODE_TOKEN_VA(0x42B697u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_push32(cpu, cpu->edi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebx))));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_store32(cpu->esp + 0x34u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebx + 4u))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 8u));
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x3Cu, cpu->edx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    reinterpret_cast<IEffectManager*>(static_cast<uintptr_t>(cpu->ecx))->initializeEffect(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42B6E2u);
    lift_x87_push(cpu, (double)-1.0f);
    label_0002B6E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x42B6E8u);
    cpu->esi += 0x14u;
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002B64A;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x28u;
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042B710(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42B710u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042B720(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42B720u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B74Du); lift_push32(cpu, r); sfera_sub_00425E30(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)4.0f);
    lift_store_f32(cpu->esi + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = 0u;
    lift_x87_push(cpu, (double)0.4000000059604645f);
    lift_push32(cpu, (uint32_t)(uintptr_t)"rain");
    lift_store_f32(cpu->esi + 0x68u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_x87_push(cpu, (double)120.0f);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store_f32(cpu->esi + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    std::construct_at(reinterpret_cast<CRainEffect*>(cpu->esi));
    lift_x87_push(cpu, 0.0);
    lift_store32(cpu->esi + 0x5Cu, 0xFFFFFFFFu);
    lift_store_f32(cpu->esi + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0x60u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B78Fu); lift_push32(cpu, r); sfera_sub_00425EB0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x10u, 0x40u);
    lift_store32(cpu->esi + 0x14u, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 8u, 0x190u);
    lift_store32(cpu->esi + 0x28u, 3u);
    lift_store32(cpu->esi + 0x58u, 0xBB8u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042B7D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42B7D0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042B7E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42B7E0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B7E8u); lift_push32(cpu, r); sfera_sub_00425E70(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_0002B7F8;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B7F5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0002B7F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x42B7F8u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042B800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42B800u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x54u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x14u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002BA3C;
    cpu->ecx = lift_load32(cpu->ecx + 0x58u);
    cpu->ecx += g_sfera_effect_manager.render_slot_count;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(0x2710u)) goto label_0002BA3C;
    lift_x87_push(cpu, 1.0);
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)320.0f);
    lift_store32(cpu->esp + 0x34u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x10u));
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    lift_store32(cpu->esp + 0x38u, cpu->ecx);
    lift_store32(cpu->esp + 0x3Cu, cpu->edx);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0002B885;
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (400.0) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (80.0));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0002B885: cpu->eip = LIFT_CODE_TOKEN_VA(0x42B885u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.05000000074505806));
    lift_store32(cpu->esp + 0x1Cu, 0u);
    lift_store_f64(cpu->esp + 0x48u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    label_0002B897: cpu->eip = LIFT_CODE_TOKEN_VA(0x42B897u);
    lift_x87_push(cpu, 0.0);
    lift_store32(cpu->esp + 0x10u, 0x28u);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.1415929794311523));
    lift_store_f64(cpu->esp + 0x40u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    label_0002B8B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x42B8B3u);
    cpu->eax = g_sfera_effect_manager.render_slot_count;
    cpu->esi = cpu->eax;
    ++cpu->eax;
    g_sfera_effect_manager.render_slot_count = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0002B8CE;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2B8CEu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0002B8CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x42B8CEu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_effect_manager.render_slots.capacity)) goto label_0002B8E2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2B8E2u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0002B8E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x42B8E2u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x9Cu);
    lift_x87_push(cpu, -204.0);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    cpu->esi += g_sfera_effect_manager.render_slots.data;
    cpu->ecx = lift_load32(cpu->eax + 0x5Cu);
    lift_store32(cpu->esi + 0x90u, cpu->ecx);
    lift_store32(cpu->esi + 0x98u, 1u);
    lift_store32(cpu->esi + 0x94u, 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B920u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0x33u;
    lift_x87_push(cpu, -51.0);
    cpu->edi -= cpu->eax;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B934u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 77.0);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    cpu->ebx = 0x99u;
    cpu->ebx -= cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B948u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    cpu->ecx = 0x99u;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    cpu->ecx -= cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (255.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x20u))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B968u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x40u);
    cpu->edx = 4u;
    label_0002B974: cpu->eip = LIFT_CODE_TOKEN_VA(0x42B974u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->ecx + 0x10u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->ecx + 0xFFFFFFF0u, cpu->edi);
    lift_store32(cpu->ecx, cpu->ebx);
    lift_store32(cpu->ecx + 0x20u, cpu->eax);
    cpu->ecx += 4u;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002B974;
    lift_x87_push(cpu, 3.1415929794311523);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (1.2000000476837158));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_load_f64(cpu->esp + 0x40u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_load_f64(cpu->esp + 0x48u)));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->esp + 0x38u))) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_store_f64(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu); lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B9C0u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.30000001192092896));
    lift_x87_set(cpu, 0u, (lift_load_f64(cpu->esp + 0x28u)) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store_f64(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu); lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42B9E7u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_push32(cpu, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.30000001192092896));
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    lift_x87_set(cpu, 0u, (lift_load_f64(cpu->esp + 0x2Cu)) - (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.15000000596046448f);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42BA12u); lift_push32(cpu, r); sfera_sub_00483060(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x10u, v); }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.02500000037252903));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002B8B3;
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(2u)) goto label_0002B897;
    label_0002BA3C: cpu->eip = LIFT_CODE_TOKEN_VA(0x42BA3Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042BA50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42BA50u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    std::construct_at(reinterpret_cast<CMolEffect*>(cpu->esi));
    cpu->ecx = lift_load32(cpu->esi + 0x74u);
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0002BA92;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2BA92u); lift_push32(cpu, r); sfera_sub_00496FE0(cpu,r); if (cpu->eip != r) return; }
    label_0002BA92: cpu->eip = LIFT_CODE_TOKEN_VA(0x42BA92u);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42BAA1u); lift_push32(cpu, r); sfera_sub_00425E70(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 0x1Cu)) & (1u)) == 0u) goto label_0002BAB1;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42BAAEu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0002BAB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x42BAB1u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042BAD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42BAD0u);
    cpu->esp -= 0x5Cu;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x6Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002C006;
    cpu->ecx = lift_load32(cpu->edi + 0x58u);
    cpu->ecx += g_sfera_effect_manager.render_slot_count;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(0x2710u)) goto label_0002C006;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + 0x6Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x30u, cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002BB37;
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->edi + 0x5Cu, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edi + 0x60u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->edi + 0x64u, cpu->eax);
    lift_store32(cpu->edi + 0x6Cu, 1u);
    label_0002BB37: cpu->eip = LIFT_CODE_TOKEN_VA(0x42BB37u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x5Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42BB43u); lift_push32(cpu, r); sfera_sub_00455FD0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_effect_manager.render_slot_count;
    cpu->esi = cpu->eax;
    ++cpu->eax;
    g_sfera_effect_manager.render_slot_count = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0002BB5E;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2BB5Eu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0002BB5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42BB5Eu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_effect_manager.render_slots.capacity)) goto label_0002BB72;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2BB72u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0002BB72: cpu->eip = LIFT_CODE_TOKEN_VA(0x42BB72u);
    cpu->ecx = lift_load32(cpu->edi + 0x70u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x9Cu);
    cpu->esi += g_sfera_effect_manager.render_slots.data;
    cpu->ebx = native_function_address32(&::rand);
    cpu->eax = 0xFFu;
    lift_store32(cpu->esi + 0x90u, cpu->ecx);
    lift_store32(cpu->esi + 0x98u, 3u);
    lift_store32(cpu->esi + 0x94u, cpu->eax);
    lift_store32(cpu->esi + 0x30u, cpu->eax);
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    lift_store32(cpu->esi + 0x50u, cpu->eax);
    lift_store32(cpu->esi + 0x60u, cpu->eax);
    lift_store32(cpu->esi + 0x34u, cpu->eax);
    lift_store32(cpu->esi + 0x44u, cpu->eax);
    lift_store32(cpu->esi + 0x54u, cpu->eax);
    lift_store32(cpu->esi + 0x64u, cpu->eax);
    lift_store32(cpu->esi + 0x38u, cpu->eax);
    lift_store32(cpu->esi + 0x48u, cpu->eax);
    lift_store32(cpu->esi + 0x58u, cpu->eax);
    lift_store32(cpu->esi + 0x68u, cpu->eax);
    lift_store32(cpu->esi + 0x3Cu, cpu->eax);
    lift_store32(cpu->esi + 0x4Cu, cpu->eax);
    lift_store32(cpu->esi + 0x5Cu, cpu->eax);
    lift_store32(cpu->esi + 0x6Cu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x2BBD4u), LIFT_CODE_TOKEN_RVA(0x2BBD2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42BBD4u);
    cpu->ebp = cpu->eax;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x2BBD8u), LIFT_CODE_TOKEN_RVA(0x2BBD6u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42BBD8u);
    cpu->ebp -= cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.20000000298023224));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x2BBF4u), LIFT_CODE_TOKEN_RVA(0x2BBF2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42BBF4u);
    cpu->ebp = cpu->eax;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x2BBF8u), LIFT_CODE_TOKEN_RVA(0x2BBF6u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42BBF8u);
    cpu->ebp -= cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.20000000298023224));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x2BC14u), LIFT_CODE_TOKEN_RVA(0x2BC12u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42BC14u);
    cpu->ebp = cpu->eax;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x2BC18u), LIFT_CODE_TOKEN_RVA(0x2BC16u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42BC18u);
    cpu->ebp -= cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.20000000298023224));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x2BC34u), LIFT_CODE_TOKEN_RVA(0x2BC32u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42BC34u);
    cpu->ebp = cpu->eax;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x2BC38u), LIFT_CODE_TOKEN_RVA(0x2BC36u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42BC38u);
    cpu->ebp -= cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.20000000298023224));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x2BC54u), LIFT_CODE_TOKEN_RVA(0x2BC52u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42BC54u);
    cpu->ebp = cpu->eax;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x2BC58u), LIFT_CODE_TOKEN_RVA(0x2BC56u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42BC58u);
    cpu->ebp -= cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.20000000298023224));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x2BC74u), LIFT_CODE_TOKEN_RVA(0x2BC72u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42BC74u);
    cpu->ebp = cpu->eax;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x2BC78u), LIFT_CODE_TOKEN_RVA(0x2BC76u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42BC78u);
    cpu->ebp -= cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.20000000298023224));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x5Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x60u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x2Cu))));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x64u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x30u))));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x34u))));
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x38u))));
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x3Cu))));
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x50u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x40u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x44u))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x58u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x48u))));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x68u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.05000000074505806));
    lift_store_f32(cpu->edi + 0x68u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42BD30u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.30000001192092896));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x50u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x5Cu))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x60u))));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x58u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x64u))));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 6u, lift_x87_get(cpu, 6u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 5u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42BDD7u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, 0.800000011920929);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x50u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x58u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esi + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x68u));
    lift_x87_push(cpu, 0.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x74u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 5u)); lift_x87_set(cpu, 5u, temporary); }
    lift_x87_set(cpu, 6u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 6u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 5u)); lift_x87_set(cpu, 5u, temporary); }
    lift_store_f32(cpu->esi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esi + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x68u))));
    lift_store_f32(cpu->esi + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x5Cu))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x60u))));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x64u))));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 6u, lift_x87_get(cpu, 6u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 5u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42BF33u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, 0.800000011920929);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esi + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x68u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->esi + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 5u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32(cpu->esi + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esi + 0x88u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x68u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->esi + 0x8Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0002C006: cpu->eip = LIFT_CODE_TOKEN_VA(0x42C006u);
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x5Cu;
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042C020(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42C020u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    std::construct_at(reinterpret_cast<CBladeEffect*>(cpu->esi));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42C02Eu); lift_push32(cpu, r); sfera_sub_00425E70(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_0002C03E;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42C03Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0002C03E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42C03Eu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042C050(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42C050u);
    cpu->esp -= 0x58u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x68u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = lift_load32(cpu->esp + 0x5Cu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002C555;
    cpu->ecx = lift_load32(cpu->edi + 0x58u);
    cpu->ecx += g_sfera_effect_manager.render_slot_count;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(0x2710u)) goto label_0002C555;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + 0x6Cu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002C0B7;
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->edi + 0x5Cu, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edi + 0x60u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->edi + 0x64u, cpu->eax);
    lift_store32(cpu->edi + 0x6Cu, 1u);
    label_0002C0B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x42C0B7u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42C0C1u); lift_push32(cpu, r); sfera_sub_00455FD0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_effect_manager.render_slot_count;
    cpu->esi = cpu->eax;
    ++cpu->eax;
    g_sfera_effect_manager.render_slot_count = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0002C0DC;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2C0DCu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0002C0DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x42C0DCu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_effect_manager.render_slots.capacity)) goto label_0002C0F0;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2C0F0u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0002C0F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x42C0F0u);
    cpu->ecx = lift_load32(cpu->edi + 0x70u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x9Cu);
    cpu->esi += g_sfera_effect_manager.render_slots.data;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0xFFu;
    lift_store32(cpu->esi + 0x90u, cpu->ecx);
    lift_store32(cpu->esi + 0x98u, 3u);
    lift_store32(cpu->esi + 0x94u, cpu->ebx);
    cpu->ecx = cpu->ebx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x68u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 0.800000011920929);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0002C147;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x68u));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (0.20000000298023224));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (255.0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42C145u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    label_0002C147: cpu->eip = LIFT_CODE_TOKEN_VA(0x42C147u);
    lift_store32(cpu->esi + 0x30u, cpu->ebx);
    lift_store32(cpu->esi + 0x40u, cpu->ebx);
    lift_store32(cpu->esi + 0x50u, cpu->ebx);
    lift_store32(cpu->esi + 0x34u, cpu->ebx);
    lift_store32(cpu->esi + 0x44u, cpu->ebx);
    lift_store32(cpu->esi + 0x54u, cpu->ebx);
    lift_store32(cpu->esi + 0x38u, cpu->ebx);
    lift_store32(cpu->esi + 0x48u, cpu->ebx);
    lift_store32(cpu->esi + 0x58u, cpu->ebx);
    lift_store32(cpu->esi + 0x3Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x4Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x5Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x60u, cpu->ecx);
    lift_store32(cpu->esi + 0x64u, cpu->ecx);
    lift_store32(cpu->esi + 0x68u, cpu->ecx);
    lift_store32(cpu->esi + 0x6Cu, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x68u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.05000000074505806));
    cpu->ebx = lift_pop32(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->edi + 0x68u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0002C19E;
    lift_store_f32(cpu->edi + 0x68u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0002C1A0;
    label_0002C19E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42C19Eu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0002C1A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x42C1A0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + 0x5Cu))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + 0x60u))));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edi + 0x64u))));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x68u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x3Cu))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x5Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x60u))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x64u))));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x5Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x60u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x2Cu))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x64u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x30u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42C237u); lift_push32(cpu, r); sfera_sub_0042F3E0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, 0.5);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0xCu))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 4u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 3u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x50u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x54u))));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x58u))));
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 6u, lift_x87_get(cpu, 6u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 5u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42C33Cu); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0xCu))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_push(cpu, 0.800000011920929);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esi + 0x70u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x74u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 5u)); lift_x87_set(cpu, 5u, temporary); }
    lift_x87_set(cpu, 6u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 6u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 5u)); lift_x87_set(cpu, 5u, temporary); }
    lift_store_f32(cpu->esi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esi + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x50u))));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x54u))));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x58u))));
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 6u, lift_x87_get(cpu, 6u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 5u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42C48Cu); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0xCu))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_push(cpu, 0.800000011920929);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esi + 0x80u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x84u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 5u)); lift_x87_set(cpu, 5u, temporary); }
    lift_x87_set(cpu, 6u, lift_x87_get(cpu, 6u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 5u)); lift_x87_set(cpu, 5u, temporary); }
    lift_store_f32(cpu->esi + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esi + 0x88u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x8Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    label_0002C555: cpu->eip = LIFT_CODE_TOKEN_VA(0x42C555u);
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x58u;
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042C570(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42C570u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42C59Fu); lift_push32(cpu, r); sfera_sub_00425E30(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    lift_store_f32(cpu->esi + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, (uint32_t)(uintptr_t)"gazer.lake");
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x24u, 0u);
    std::construct_at(reinterpret_cast<CGazerLakeEffect*>(cpu->esi));
    lift_store32(cpu->esi + 0x5Cu, 0u);
    lift_store32(cpu->esi + 0x60u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42C5CEu); lift_push32(cpu, r); sfera_sub_00425EB0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (0.10000000149011612));
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->esi + 8u, cpu->ecx);
    lift_store32(cpu->esi + 0x10u, 0xC0u);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0x14u, 0xFFFFFFFFu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store8(cpu->esi + 0x54u, 1u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)-0.4000000059604645f);
    lift_store32(cpu->esi + 0x3Cu, cpu->edx);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esi + 0x44u, cpu->ecx);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)0.10000000149011612f);
    lift_store32(cpu->esi + 0x48u, cpu->edx);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esi + 0x4Cu, cpu->eax);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esi + 0x50u, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esi + 0x68u);
    cpu->ecx = 0x10u;
    label_0002C660: cpu->eip = LIFT_CODE_TOKEN_VA(0x42C660u);
    lift_store32(cpu->eax, 0u);
    cpu->eax += 0x14u;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002C660;
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042C690(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42C690u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42C698u); lift_push32(cpu, r); sfera_sub_0042B4A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 8u)) & (1u)) == 0u) goto label_0002C6A8;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42C6A5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0002C6A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x42C6A8u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042C6B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42C6B0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->edx = 0x329u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Effects.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42C6E6u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1A8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42C6F0u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x20u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002C71D;
    cpu->ecx = lift_load32(cpu->esi + 0x60u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x64u));
    cpu->edx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42C719u); lift_push32(cpu, r); sfera_sub_0042C570(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    goto label_0002C71F;
    label_0002C71D: cpu->eip = LIFT_CODE_TOKEN_VA(0x42C71Du);
    cpu->ebp = 0u;
    label_0002C71F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42C71Fu);
    cpu->ecx = 0x2D9u;
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42C731u); lift_push32(cpu, r); sfera_sub_00425BD0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) == 0u) goto label_0002C75A;
    cpu->esi = (uint32_t)(cpu->ebp + 0x6Cu);
    cpu->ebx = 0x10u;
    (void)cpu;
    label_0002C740: cpu->eip = LIFT_CODE_TOKEN_VA(0x42C740u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<IEffectManager*>(static_cast<uintptr_t>(cpu->edi))->createEffectResources(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42C749u);
    lift_x87_push(cpu, (double)-1.0f);
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0xFFFFFFFCu, cpu->eax);
    cpu->esi += 0x14u;
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002C740;
    label_0002C75A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42C75Au);
    cpu->eax = cpu->ebp;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042C770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42C770u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    std::construct_at(reinterpret_cast<CRainEffect*>(cpu->esi));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x60u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002C7C7;
    cpu->edx = 0x359u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Effects.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42C7BBu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x60u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42C7C4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0002C7C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x42C7C7u);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42C7D6u); lift_push32(cpu, r); sfera_sub_00425E70(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((lift_load8(cpu->esp + 0x1Cu)) & (1u)) == 0u) goto label_0002C7E6;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42C7E3u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0002C7E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x42C7E6u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042C800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42C800u);
    cpu->esp -= 0xC0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0xD0u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002CFA7;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x5Cu)) == (uint32_t)(0xFFFFFFFFu)) goto label_0002CFA7;
    cpu->eax = lift_load32(cpu->ebp + 0x58u);
    cpu->eax += g_sfera_effect_manager.render_slot_count;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(0x2710u)) goto label_0002CFA7;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x6Cu));
    lift_push32(cpu, cpu->ebx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp + 0x70u))));
    lift_push32(cpu, cpu->esi);
    lift_store16(cpu->esp + 0x1Cu, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x1Cu);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax |= 0xC00u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->edi);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x24u));
    lift_store64(cpu->esp + 0x18u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x20u));
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x18u)))));
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_0002C882;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0002C882: cpu->eip = LIFT_CODE_TOKEN_VA(0x42C882u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ebp + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002CA11;
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    label_0002C895: cpu->eip = LIFT_CODE_TOKEN_VA(0x42C895u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002CA11;
    cpu->ebx = lift_load32(cpu->ebp + 0x60u);
    cpu->ebx += cpu->ecx;
    if ((uint32_t)((lift_load32(cpu->ebx + 0x14u)) & (0x80000000u)) == 0u) goto label_0002C9FE;
    cpu->esi = native_function_address32(&::rand);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x2C8B7u), LIFT_CODE_TOKEN_RVA(0x2C8B5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42C8B7u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (20.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (30.0));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_store_f32(cpu->ebx + 0x18u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ebx + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x2C8E9u), LIFT_CODE_TOKEN_RVA(0x2C8E7u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42C8E9u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, 0.02500000037252903);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ebx + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x2C90Eu), LIFT_CODE_TOKEN_RVA(0x2C90Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42C90Eu);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, 0.05999999865889549);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ebx + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x2C933u), LIFT_CODE_TOKEN_RVA(0x2C931u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42C933u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (6.283185958862305));
    lift_store_f32(cpu->esp + 0xC0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x2C958u), LIFT_CODE_TOKEN_RVA(0x2C956u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42C958u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (0.5));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.1415929794311523));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42C987u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x44u, cpu->ecx);
    cpu->edi = lift_load32(cpu->esp + 0x44u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xC0u));
    lift_x87_sincos(cpu);
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x64u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x68u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ebx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x64u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ebp + 0x68u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ebx + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) - 1u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_store_f32(cpu->ebx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    label_0002C9FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x42C9FEu);
    cpu->ecx += 0x20u;
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(0x17700u)) goto label_0002C895;
    label_0002CA11: cpu->eip = LIFT_CODE_TOKEN_VA(0x42CA11u);
    lift_x87_push(cpu, 0.10000000149011612);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    cpu->ebx = 0x9Bu;
    label_0002CA22: cpu->eip = LIFT_CODE_TOKEN_VA(0x42CA22u);
    cpu->edx = lift_load32(cpu->ebp + 0x60u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + cpu->edx + 0x14u)), r=(uint64_t)(0x80000000u), v=l & r; lift_flags_logic(cpu,v,32u); }
    cpu->edi = (uint32_t)(cpu->eax + cpu->edx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002CF90;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (2.0));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->edi + 0x14u, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (((double)lift_load_f32(cpu->edi + 0x18u))));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 4u))));
    lift_store_f32(cpu->edi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0002CA78;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->edi + 0x10u, 0xC8u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0002CAA5;
    label_0002CA78: cpu->eip = LIFT_CODE_TOKEN_VA(0x42CA78u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (200.0));
    lift_store16(cpu->esp + 0x20u, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0x20u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x18u));
    lift_store64(cpu->esp + 0x18u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->edi + 0x10u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x20u));
    label_0002CAA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x42CAA5u);
    cpu->eax = g_sfera_effect_manager.render_slot_count;
    cpu->esi = cpu->eax;
    ++cpu->eax;
    g_sfera_effect_manager.render_slot_count = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0002CAC0;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2CAC0u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0002CAC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x42CAC0u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_effect_manager.render_slots.capacity)) goto label_0002CAD4;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2CAD4u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0002CAD4: cpu->eip = LIFT_CODE_TOKEN_VA(0x42CAD4u);
    cpu->ecx = lift_load32(cpu->ebp + 0x5Cu);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x9Cu);
    cpu->esi += g_sfera_effect_manager.render_slots.data;
    lift_store32(cpu->esi + 0x90u, cpu->ecx);
    lift_store32(cpu->esi + 0x98u, 1u);
    lift_store32(cpu->esi + 0x94u, 0u);
    cpu->eax = (uint32_t)(cpu->esi + 0x40u);
    cpu->ecx = 4u;
    label_0002CB05: cpu->eip = LIFT_CODE_TOKEN_VA(0x42CB05u);
    lift_store32(cpu->eax + 0xFFFFFFF0u, cpu->ebx);
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 0x10u, cpu->ebx);
    cpu->edx = lift_load32(cpu->edi + 0x10u);
    lift_store32(cpu->eax + 0x20u, cpu->edx);
    cpu->eax += 4u;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002CB05;
    cpu->eax = lift_load32(cpu->esp + 0xD4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi))));
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 4u))));
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x58u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 8u));
    lift_store32(cpu->esp + 0x4Cu, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 8u))));
    cpu->eax = lift_load32(cpu->esp + 0x54u);
    lift_store32(cpu->esp + 0x48u, cpu->eax);
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x5Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x58u));
    lift_store32(cpu->esp + 0x50u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (4.0));
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x1Cu));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)g_sfera_effect_manager.viewer_position.x)));
    lift_store_f32(cpu->esp + 0x78u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)g_sfera_effect_manager.viewer_position.y)));
    lift_store_f32(cpu->esp + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x50u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)g_sfera_effect_manager.viewer_position.z)));
    lift_store_f32(cpu->esp + 0x80u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x7Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x80u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, -1.0);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 4u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x78u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 5u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 4u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 3u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 5u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 5u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 5u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 4u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)9.999999747378752e-06f);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0002CC92;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esp + 0xA8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    cpu->eax = lift_load32(cpu->esp + 0xA8u);
    lift_store_f32(cpu->esp + 0xACu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_store_f32(cpu->esp + 0xB0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0xACu);
    cpu->edx = lift_load32(cpu->esp + 0xB0u);
    lift_store32(cpu->esp + 0x2Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x30u, cpu->edx);
    goto label_0002CCF3;
    label_0002CC92: cpu->eip = LIFT_CODE_TOKEN_VA(0x42CC92u);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    cpu->ecx = 0x5F3759DFu;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->ecx -= cpu->eax;
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.5);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x2Cu))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0002CCF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x42CCF3u);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_push(cpu, lift_x87_get(cpu, 5u));
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
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0002CD60;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x90u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0x90u);
    lift_store_f32(cpu->esp + 0x94u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    cpu->eax = lift_load32(cpu->esp + 0x94u);
    lift_store_f32(cpu->esp + 0x98u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x34u, cpu->edx);
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esp + 0x98u);
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    goto label_0002CDB7;
    label_0002CD60: cpu->eip = LIFT_CODE_TOKEN_VA(0x42CD60u);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    cpu->eax = 0x5F3759DFu;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->eax -= cpu->edx;
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.5);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0002CDB7: cpu->eip = LIFT_CODE_TOKEN_VA(0x42CDB7u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x2Cu))));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x30u))));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x34u))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x38u))));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x3Cu))));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x4Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x50u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x68u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 5u)); lift_x87_set(cpu, 5u, temporary); }
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 4u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0x9Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xA0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xA4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x60u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x6Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x64u));
    lift_store32(cpu->esi, cpu->ecx);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x70u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x68u));
    lift_store32(cpu->esi + 4u, cpu->edx);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x74u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x74u);
    lift_x87_push(cpu, lift_x87_get(cpu, 4u));
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_x87_set(cpu, 6u, lift_x87_get(cpu, 6u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 5u)); lift_x87_set(cpu, 5u, temporary); }
    lift_store_f32(cpu->esp + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    cpu->ecx = lift_load32(cpu->esp + 0x84u);
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0xCu, cpu->ecx);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x88u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x88u);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_store32(cpu->esi + 0x10u, cpu->edx);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x8Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x8Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x9Cu));
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0xB4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0xB4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xA0u));
    lift_store32(cpu->esi + 0x18u, cpu->ecx);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    lift_store_f32(cpu->esp + 0xB8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0xB8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xA4u));
    lift_store32(cpu->esi + 0x1Cu, cpu->edx);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 6u)));
    lift_store_f32(cpu->esp + 0xBCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0xBCu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    lift_x87_set(cpu, 4u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 4u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_store_f32(cpu->esp + 0xC4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0xC4u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store32(cpu->esi + 0x24u, cpu->ecx);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xC8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0xC8u);
    lift_store32(cpu->esi + 0x28u, cpu->edx);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xCCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0xCCu);
    lift_x87_push(cpu, 0.10000000149011612);
    lift_store32(cpu->esi + 0x2Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    label_0002CF90: cpu->eip = LIFT_CODE_TOKEN_VA(0x42CF90u);
    cpu->eax += 0x20u;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x17700u)) goto label_0002CA22;
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0002CFA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x42CFA7u);
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xC0u;
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042CFC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42CFC0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->edx = 0x3C7u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Effects.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42CFF1u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x74u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42CFF8u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002D016;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D012u); lift_push32(cpu, r); sfera_sub_0042B720(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    goto label_0002D018;
    label_0002D016: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D016u);
    cpu->esi = 0u;
    label_0002D018: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D018u);
    cpu->ecx = (uint32_t)(uintptr_t)"fx_rain";
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D02Au); lift_push32(cpu, r); sfera_sub_00499D70(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x5Cu, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_0002D045;
    lift_push32(cpu, (uint32_t)(uintptr_t)"CRainEffect::Texture not found 'fx_rain'");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D03Cu); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D042u); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 8u;
    label_0002D045: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D045u);
    cpu->edx = 0x3CEu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Effects.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D054u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x17700u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D05Eu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)-1.0f);
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x60u, cpu->eax);
    cpu->eax = 0u;
    label_0002D06C: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D06Cu);
    cpu->ecx = lift_load32(cpu->esi + 0x60u);
    lift_store_f32(cpu->ecx + cpu->eax + 0x14u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x60u);
    lift_store_f32(cpu->edx + cpu->eax + 0x34u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x60u);
    lift_store_f32(cpu->ecx + cpu->eax + 0x54u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x60u);
    lift_store_f32(cpu->edx + cpu->eax + 0x74u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x60u);
    lift_store_f32(cpu->ecx + cpu->eax + 0x94u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x60u);
    lift_store_f32(cpu->edx + cpu->eax + 0xB4u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x60u);
    lift_store_f32(cpu->ecx + cpu->eax + 0xD4u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x60u);
    lift_store_f32(cpu->edx + cpu->eax + 0xF4u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esi + 0x60u);
    lift_store_f32(cpu->ecx + cpu->eax + 0x114u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esi + 0x60u);
    lift_store_f32(cpu->edx + cpu->eax + 0x134u, lift_x87_get(cpu, 0u));
    cpu->eax += 0x140u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x17700u)) goto label_0002D06C;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042D0F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42D0F0u);
    cpu->eax = cpu->ecx;
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042D100(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42D100u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi)) == (uint32_t)(0u)) goto label_0002D122;
    cpu->edx = 0x46u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectTrack.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D117u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D11Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0002D122: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D122u);
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->esi + 4u, 0u);
    lift_store32(cpu->esi + 8u, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042D140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42D140u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(4u), 32u);
    cpu->esi += lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = 0xCu;
    lift_movs32(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042D160(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42D160u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(4u), 32u);
    cpu->edi += lift_load32(cpu->ecx);
    cpu->ecx = 0xCu;
    lift_movs32(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042D180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42D180u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0002D262;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u));
    cpu->eax += cpu->eax;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFD0u));
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFD0u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0002D1C6;
    cpu->ecx = lift_load32(cpu->edi + 0x18u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = lift_load32(cpu->edi + 0x1Cu);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->edi + 0x20u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0002D1C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D1C6u);
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_0002D1E6;
    cpu->edi = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u));
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(4u), 32u);
    cpu->edi += cpu->esi;
    label_0002D1D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D1D1u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0002D1E4;
    cpu->edi -= 0x30u;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0002D1D1;
    goto label_0002D1E6;
    label_0002D1E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D1E4u);
    cpu->esi = cpu->edi;
    label_0002D1E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D1E6u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + 8u)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x30u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002D226;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.1415929794311523));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D210u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0002D226: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D226u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x48u));
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x18u))));
    cpu->edi = lift_pop32(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x18u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x4Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x1Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x1Cu))));
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x50u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x20u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x20u))));
    cpu->esi = lift_pop32(cpu);
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_return(cpu, 8u, stop_address); return;
    label_0002D262: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D262u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002D27E;
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 0x18u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0x1Cu);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 0x20u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    lift_return(cpu, 8u, stop_address); return;
    label_0002D27E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D27Eu);
    lift_x87_push(cpu, 0.0);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042D290(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42D290u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    cpu->ebx = 1u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0002D3D5;
    cpu->edx = lift_load32(cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->eax = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 2u));
    cpu->eax += cpu->eax;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFD0u));
    cpu->ecx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFD0u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0002D310;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((lift_load8(cpu->ecx + 4u)) & ((cpu->ebx & 0xFFu))) == 0u) goto label_0002D2FF;
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->eax = lift_load16(cpu->edx + ((uint32_t)(cpu->esi) * 2u) + 0xFFFFFFFEu);
    cpu->eax += lift_load32(cpu->esp + 0x1Cu);
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->ebx = lift_pop32(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (1.5259021893143654e-05));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx + 0xCu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx + 8u))));
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 20u, stop_address); return;
    label_0002D2FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D2FFu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->esi = lift_pop32(cpu);
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 20u, stop_address); return;
    label_0002D310: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D310u);
    cpu->ecx = (uint32_t)(cpu->esi + 0xFFFFFFFFu);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_0002D335;
    cpu->esi = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(4u), 32u);
    cpu->esi += cpu->edx;
    label_0002D31F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D31Fu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0002D333;
    cpu->esi -= 0x30u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0002D31F;
    goto label_0002D335;
    label_0002D333: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D333u);
    cpu->edx = cpu->esi;
    label_0002D335: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D335u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx))));
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x30u));
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x38u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.5259021893143654e-05);
    if ((uint8_t)((lift_load8(cpu->edx + 4u)) & ((cpu->ebx & 0xFFu))) == 0u) goto label_0002D388;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load16(cpu->eax + ((uint32_t)(cpu->ecx) * 2u));
    cpu->edi += cpu->esi;
    lift_store32(cpu->esp + 0x28u, cpu->edi);
    cpu->edi = lift_pop32(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x24u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0xCu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 8u))));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0002D388: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D388u);
    if ((uint8_t)((lift_load8(cpu->edx + 0x34u)) & ((cpu->ebx & 0xFFu))) == 0u) goto label_0002D3B1;
    cpu->eax = lift_load16(cpu->eax + ((uint32_t)(cpu->ecx) * 2u) + 2u);
    cpu->eax += cpu->esi;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * ((double)(((int32_t)(lift_load32(cpu->esp + 0x24u))))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0x3Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0002D3B3;
    label_0002D3B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D3B1u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0002D3B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D3B3u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    cpu->esi = lift_pop32(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->ebx = lift_pop32(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 20u, stop_address); return;
    label_0002D3D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D3D5u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002D417;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint8_t)((lift_load8(cpu->ecx + 4u)) & ((cpu->ebx & 0xFFu))) == 0u) goto label_0002D2FF;
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->eax = lift_load16(cpu->edx);
    cpu->eax += lift_load32(cpu->esp + 0x1Cu);
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->ebx = lift_pop32(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x1Cu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (1.5259021893143654e-05));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx + 0xCu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx + 8u))));
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 20u, stop_address); return;
    label_0002D417: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D417u);
    lift_x87_push(cpu, 0.0);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->esi = lift_pop32(cpu);
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042D430(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42D430u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0002D8A0;
    cpu->esi = lift_load32(cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u));
    cpu->eax += cpu->eax;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFD0u));
    cpu->edi = (uint32_t)(cpu->esi + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFD0u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0002D5BC;
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi + 4u)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002D593;
    cpu->ebp = lift_load32(cpu->esp + 0x44u);
    cpu->esi = cpu->edx;
    cpu->ecx = lift_load16(cpu->ebp + ((uint32_t)(cpu->esi) * 2u) + 0xFFFFFFFEu);
    cpu->ecx += lift_load32(cpu->esp + 0x3Cu);
    cpu->edx = lift_load8(cpu->edi + 0x14u);
    lift_store32(cpu->esp + 0x44u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x44u)))));
    lift_x87_push(cpu, 1.5259021893143654e-05);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    lift_store32(cpu->esp + 0x44u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x44u)))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D4ABu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load16(cpu->ebp + ((uint32_t)(cpu->esi) * 2u));
    cpu->ecx += lift_load32(cpu->esp + 0x3Cu);
    cpu->edx = lift_load8(cpu->edi + 0x15u);
    lift_store32(cpu->esp + 0x44u, cpu->ecx);
    cpu->ebx = cpu->eax;
    cpu->eax = lift_load8(cpu->edi + 0x10u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x44u)))));
    cpu->ebx += cpu->eax;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    lift_store32(cpu->esp + 0x44u, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x44u)))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D4E1u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load16(cpu->ebp + ((uint32_t)(cpu->esi) * 2u) + 2u);
    cpu->edx += lift_load32(cpu->esp + 0x3Cu);
    cpu->ecx = lift_load8(cpu->edi + 0x11u);
    lift_store32(cpu->esp + 0x44u, cpu->edx);
    cpu->eax += cpu->ecx;
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x44u)))));
    cpu->eax = lift_load8(cpu->edi + 0x16u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u));
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x44u)))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D519u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load16(cpu->ebp + ((uint32_t)(cpu->esi) * 2u) + 4u);
    cpu->edx += lift_load32(cpu->esp + 0x3Cu);
    cpu->ecx = lift_load8(cpu->edi + 0x12u);
    lift_store32(cpu->esp + 0x3Cu, cpu->edx);
    cpu->eax += cpu->ecx;
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * ((double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu))))));
    cpu->eax = lift_load8(cpu->edi + 0x17u);
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D54Fu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load8(cpu->edi + 0x13u);
    cpu->ebp = 0xFFu;
    cpu->eax += cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->ebp)) goto label_0002D560;
    cpu->ebx = cpu->ebp;
    label_0002D560: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D560u);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_store8(cpu->edx, cpu->ebx & 0xFFu);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->ebp)) goto label_0002D570;
    cpu->ecx = cpu->ebp;
    label_0002D570: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D570u);
    lift_store8(cpu->edx + 1u, cpu->ecx & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    label_0002D577: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D577u);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->ebp)) goto label_0002D57D;
    cpu->ecx = cpu->ebp;
    label_0002D57D: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D57Du);
    lift_store8(cpu->edx + 2u, cpu->ecx & 0xFFu);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ebp)) goto label_0002D586;
    cpu->eax = cpu->ebp;
    label_0002D586: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D586u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->edx + 3u, cpu->eax & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 20u, stop_address); return;
    label_0002D593: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D593u);
    cpu->edx = lift_load8(cpu->edi + 0x10u);
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    lift_store8(cpu->eax, cpu->edx & 0xFFu);
    cpu->ecx = lift_load8(cpu->edi + 0x11u);
    lift_store8(cpu->eax + 1u, cpu->ecx & 0xFFu);
    cpu->edx = lift_load8(cpu->edi + 0x12u);
    lift_store8(cpu->eax + 2u, cpu->edx & 0xFFu);
    cpu->ecx = lift_load8(cpu->edi + 0x13u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->eax + 3u, cpu->ecx & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 20u, stop_address); return;
    label_0002D5BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D5BCu);
    cpu->edi = (uint32_t)(cpu->edx + 0xFFFFFFFFu);
    cpu->edx = 0u;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0002D5E4;
    cpu->ecx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    cpu->ecx += cpu->esi;
    label_0002D5CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D5CDu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0002D5E2;
    --cpu->edi;
    cpu->ecx -= 0x30u;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->edx)) goto label_0002D5CD;
    goto label_0002D5E4;
    label_0002D5E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D5E2u);
    cpu->esi = cpu->ecx;
    label_0002D5E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D5E4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 4u)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x30u));
    cpu->edx = lift_load8(cpu->esi + 0x10u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi))));
    cpu->eax = lift_load8(cpu->esi + 0x11u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load8(cpu->esi + 0x12u);
    cpu->ebp = lift_load32(cpu->esp + 0x44u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    cpu->edx = lift_load8(cpu->esi + 0x13u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->eax = lift_load8(cpu->esi + 0x40u);
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    cpu->ecx = lift_load8(cpu->esi + 0x41u);
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    cpu->edx = lift_load8(cpu->esi + 0x42u);
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    cpu->eax = lift_load8(cpu->esi + 0x43u);
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.5259021893143654e-05);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002D709;
    cpu->ebx = lift_load32(cpu->esp + 0x3Cu);
    cpu->ecx = lift_load16(cpu->ebp + ((uint32_t)(cpu->edi) * 2u));
    cpu->edx = lift_load8(cpu->esi + 0x14u);
    cpu->ecx += cpu->ebx;
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store32(cpu->esp + 0x3Cu, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D675u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    cpu->eax = lift_load16(cpu->ebp + ((uint32_t)(cpu->edi) * 2u) + 2u);
    cpu->ecx = lift_load8(cpu->esi + 0x15u);
    cpu->eax += cpu->ebx;
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D6A5u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load16(cpu->ebp + ((uint32_t)(cpu->edi) * 2u) + 4u);
    lift_store32(cpu->esp + 0x18u, (uint64_t)(lift_load32(cpu->esp + 0x18u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    cpu->eax = lift_load8(cpu->esi + 0x16u);
    cpu->edx += cpu->ebx;
    lift_store32(cpu->esp + 0x3Cu, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D6D5u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load16(cpu->ebp + ((uint32_t)(cpu->edi) * 2u) + 6u);
    cpu->edx = lift_load8(cpu->esi + 0x17u);
    lift_store32(cpu->esp + 0x20u, (uint64_t)(lift_load32(cpu->esp + 0x20u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    cpu->ecx += cpu->ebx;
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store32(cpu->esp + 0x3Cu, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D705u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x28u, (uint64_t)(lift_load32(cpu->esp + 0x28u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    label_0002D709: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D709u);
    if ((uint8_t)((lift_load8(cpu->esi + 0x34u)) & (1u)) == 0u) goto label_0002D7D7;
    cpu->eax = lift_load16(cpu->ebp + ((uint32_t)(cpu->edi) * 2u) + 2u);
    cpu->ebx = lift_load32(cpu->esp + 0x40u);
    cpu->ecx = lift_load8(cpu->esi + 0x44u);
    cpu->eax += cpu->ebx;
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D743u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load16(cpu->ebp + ((uint32_t)(cpu->edi) * 2u) + 4u);
    lift_store32(cpu->esp + 0x34u, (uint64_t)(lift_load32(cpu->esp + 0x34u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    cpu->eax = lift_load8(cpu->esi + 0x45u);
    cpu->edx += cpu->ebx;
    lift_store32(cpu->esp + 0x3Cu, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D773u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load16(cpu->ebp + ((uint32_t)(cpu->edi) * 2u) + 6u);
    cpu->edx = lift_load8(cpu->esi + 0x46u);
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    cpu->ecx += cpu->ebx;
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store32(cpu->esp + 0x3Cu, cpu->edx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D7A3u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    cpu->eax = lift_load16(cpu->ebp + ((uint32_t)(cpu->edi) * 2u) + 8u);
    cpu->ecx = lift_load8(cpu->esi + 0x47u);
    cpu->eax += cpu->ebx;
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * ((double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu))))));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D7D1u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x24u, (uint64_t)(lift_load32(cpu->esp + 0x24u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    goto label_0002D7D9;
    label_0002D7D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D7D7u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0002D7D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D7D9u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (255.0));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D7E8u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = 0xFFu;
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x10u)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0002D7F9;
    lift_store32(cpu->esp + 0x10u, cpu->ebp);
    label_0002D7F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D7F9u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x18u)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0002D803;
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    label_0002D803: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D803u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x20u)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0002D80D;
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    label_0002D80D: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D80Du);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x28u)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0002D817;
    lift_store32(cpu->esp + 0x28u, cpu->ebp);
    label_0002D817: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D817u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x34u)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0002D821;
    lift_store32(cpu->esp + 0x34u, cpu->ebp);
    label_0002D821: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D821u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x14u)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0002D82B;
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    label_0002D82B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D82Bu);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x1Cu)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0002D835;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    label_0002D835: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D835u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x24u)) <= (int32_t)(uint32_t)(cpu->ebp)) goto label_0002D83F;
    lift_store32(cpu->esp + 0x24u, cpu->ebp);
    label_0002D83F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D83Fu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    { int64_t v=(int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->esi); cpu->edx= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store8(cpu->ecx, cpu->edx & 0xFFu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    { int64_t v=(int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->esi); cpu->edx= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_store8(cpu->ecx + 1u, cpu->edx & 0xFFu);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    { int64_t v=(int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->esi); cpu->edx= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_store8(cpu->ecx + 2u, cpu->edx & 0xFFu);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    { int64_t v=(int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->esi); cpu->edx= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->ecx + 3u, cpu->edx & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 20u, stop_address); return;
    label_0002D8A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D8A0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002D9DD;
    cpu->esi = lift_load32(cpu->ecx);
    if ((uint8_t)((lift_load8(cpu->esi + 4u)) & (1u)) == 0u) goto label_0002D9B4;
    cpu->ebx = lift_load32(cpu->esp + 0x44u);
    cpu->ebp = lift_load32(cpu->esp + 0x3Cu);
    cpu->eax = lift_load16(cpu->ebx);
    cpu->ecx = lift_load8(cpu->esi + 0x14u);
    cpu->eax += cpu->ebp;
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_push(cpu, 1.5259021893143654e-05);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D8ECu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load8(cpu->esi + 0x10u);
    cpu->ecx = lift_load8(cpu->esi + 0x15u);
    cpu->edi += cpu->eax;
    cpu->eax = lift_load16(cpu->ebx + 2u);
    cpu->eax += cpu->ebp;
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D91Du); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load8(cpu->esi + 0x11u);
    cpu->ecx = lift_load8(cpu->esi + 0x16u);
    cpu->eax += cpu->edx;
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    cpu->eax = lift_load16(cpu->ebx + 4u);
    cpu->eax += cpu->ebp;
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D952u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load8(cpu->esi + 0x12u);
    cpu->ecx = lift_load8(cpu->esi + 0x17u);
    cpu->eax += cpu->edx;
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    cpu->eax = lift_load16(cpu->ebx + 6u);
    cpu->eax += cpu->ebp;
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * ((double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu))))));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x3Cu));
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42D985u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load8(cpu->esi + 0x13u);
    cpu->ebp = 0xFFu;
    cpu->eax += cpu->edx;
    cpu->ecx = cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->ebp)) goto label_0002D998;
    cpu->ecx = cpu->ebp;
    label_0002D998: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D998u);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_store8(cpu->edx, cpu->ecx & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->ebp)) goto label_0002D9A8;
    cpu->ecx = cpu->ebp;
    label_0002D9A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D9A8u);
    lift_store8(cpu->edx + 1u, cpu->ecx & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    goto label_0002D577;
    label_0002D9B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D9B4u);
    cpu->ecx = lift_load8(cpu->esi + 0x10u);
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    lift_store8(cpu->eax, cpu->ecx & 0xFFu);
    cpu->edx = lift_load8(cpu->esi + 0x11u);
    lift_store8(cpu->eax + 1u, cpu->edx & 0xFFu);
    cpu->ecx = lift_load8(cpu->esi + 0x12u);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->eax + 2u, cpu->ecx & 0xFFu);
    cpu->edx = lift_load8(cpu->esi + 0x13u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->eax + 3u, cpu->edx & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 20u, stop_address); return;
    label_0002D9DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x42D9DDu);
    cpu->eax = lift_load32(cpu->esp + 0x38u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->edx = 0u;
    cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042D9F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42D9F0u);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0002DE96;
    cpu->esi = lift_load32(cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    cpu->eax = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    cpu->eax += cpu->eax;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFD0u));
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFD0u);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ebp);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0002DB7F;
    cpu->eax = lift_load32(cpu->edx + 4u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_0002DAB7;
    cpu->eax = lift_load32(cpu->esp + 0x40u);
    cpu->ecx = cpu->edi;
    cpu->esi = lift_load16(cpu->eax + ((uint32_t)(cpu->ecx) * 2u));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    cpu->esi += cpu->ecx;
    lift_store32(cpu->esp + 0x40u, cpu->esi);
    cpu->esi = lift_load16(cpu->eax + 2u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x40u)))));
    lift_x87_push(cpu, 1.5259021893143654e-05);
    cpu->eax = lift_load16(cpu->eax + 0xFFFFFFFEu);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    cpu->esi += cpu->ecx;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->esp + 0x40u, cpu->esi);
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax += cpu->ecx;
    cpu->ebp = lift_pop32(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_store32(cpu->esp + 0x3Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * ((double)(((int32_t)(lift_load32(cpu->esp + 0x30u))))));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0x24u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + 0x18u))));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + 0x1Cu))));
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x2Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x2Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + 0x20u))));
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 20u, stop_address); return;
    label_0002DAB7: cpu->eip = LIFT_CODE_TOKEN_VA(0x42DAB7u);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (2u)) == 0u) goto label_0002DB60;
    cpu->ecx = lift_load32(cpu->esp + 0x40u);
    cpu->eax = cpu->edi;
    cpu->esi = lift_load16(cpu->ecx + ((uint32_t)(cpu->eax) * 2u) + 4u);
    cpu->ebx = lift_load16(cpu->ecx + ((uint32_t)(cpu->eax) * 2u) + 2u);
    cpu->edi = lift_load32(cpu->esp + 0x38u);
    cpu->ebp = lift_load16(cpu->ecx + ((uint32_t)(cpu->eax) * 2u) + 6u);
    cpu->ebx -= cpu->esi;
    cpu->esi = lift_load32(cpu->esp + 0x3Cu);
    cpu->ebx -= cpu->esi;
    cpu->ebx += cpu->edi;
    lift_store32(cpu->esp + 0x40u, cpu->ebx);
    cpu->ebx = lift_load16(cpu->ecx + ((uint32_t)(cpu->eax) * 2u) + 8u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x40u)))));
    lift_x87_push(cpu, 1.5259021893143654e-05);
    cpu->ebp -= cpu->ebx;
    cpu->ebx = lift_load16(cpu->ecx + ((uint32_t)(cpu->eax) * 2u) + 0xFFFFFFFEu);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->ecx = lift_load16(cpu->ecx + ((uint32_t)(cpu->eax) * 2u));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp -= cpu->esi;
    cpu->ebp += cpu->edi;
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x40u, cpu->ebp);
    cpu->ebx -= cpu->ecx;
    cpu->ebx -= cpu->esi;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x40u)))));
    cpu->ebx += cpu->edi;
    lift_store32(cpu->esp + 0x40u, cpu->ebx);
    cpu->ebp = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * ((double)(((int32_t)(lift_load32(cpu->esp + 0x30u))))));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0x24u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + 0x18u))));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + 0x1Cu))));
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x2Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x2Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + 0x20u))));
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 20u, stop_address); return;
    label_0002DB60: cpu->eip = LIFT_CODE_TOKEN_VA(0x42DB60u);
    cpu->ecx = lift_load32(cpu->edx + 0x18u);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx + 0x1Cu);
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edx + 0x20u);
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 20u, stop_address); return;
    label_0002DB7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42DB7Fu);
    cpu->edx = (uint32_t)(cpu->edi + 0xFFFFFFFFu);
    { uint64_t v=(uint64_t)(cpu->edx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_0002DBA3;
    cpu->edi = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u));
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(4u), 32u);
    cpu->edi += cpu->esi;
    label_0002DB8E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42DB8Eu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0002DBA1;
    cpu->edi -= 0x30u;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0002DB8E;
    goto label_0002DBA3;
    label_0002DBA1: cpu->eip = LIFT_CODE_TOKEN_VA(0x42DBA1u);
    cpu->esi = cpu->edi;
    label_0002DBA3: cpu->eip = LIFT_CODE_TOKEN_VA(0x42DBA3u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi))));
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x30u));
    cpu->ebx = lift_load32(cpu->esi + 4u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi))));
    cpu->ebp = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x48u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x4Cu);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x50u);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x40u);
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.5259021893143654e-05);
    if ((uint8_t)(((cpu->ebx & 0xFFu)) & (1u)) == 0u) goto label_0002DC5B;
    cpu->edi = lift_load16(cpu->eax + ((uint32_t)(cpu->edx) * 2u));
    cpu->edi += cpu->ebp;
    lift_store32(cpu->esp + 0x40u, cpu->edi);
    cpu->edi = lift_load16(cpu->eax + ((uint32_t)(cpu->edx) * 2u) + 2u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x40u)))));
    cpu->edi += cpu->ebp;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store32(cpu->esp + 0x40u, cpu->edi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x24u))));
    cpu->edi = lift_load16(cpu->eax + ((uint32_t)(cpu->edx) * 2u) + 4u);
    cpu->edi += cpu->ebp;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x40u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store32(cpu->esp + 0x40u, cpu->edi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x28u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x24u))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x40u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x2Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0002DC5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42DC5Bu);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0x34u)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->edi = lift_load32(cpu->esp + 0x3Cu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002DCD5;
    cpu->ecx = lift_load16(cpu->eax + ((uint32_t)(cpu->edx) * 2u) + 2u);
    cpu->ecx += cpu->edi;
    lift_store32(cpu->esp + 0x40u, cpu->ecx);
    cpu->ecx = lift_load16(cpu->eax + ((uint32_t)(cpu->edx) * 2u) + 4u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x40u)))));
    cpu->ecx += cpu->edi;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store32(cpu->esp + 0x40u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x54u))));
    cpu->ecx = lift_load16(cpu->eax + ((uint32_t)(cpu->edx) * 2u) + 6u);
    cpu->ecx += cpu->edi;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x40u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store32(cpu->esp + 0x40u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x58u))));
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x40u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x5Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0002DCD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x42DCD5u);
    if ((uint8_t)(((cpu->ebx & 0xFFu)) & (2u)) == 0u) goto label_0002DD68;
    cpu->ecx = lift_load16(cpu->eax + ((uint32_t)(cpu->edx) * 2u) + 2u);
    cpu->ebx = lift_load16(cpu->eax + ((uint32_t)(cpu->edx) * 2u));
    cpu->ebx -= cpu->ecx;
    cpu->ecx = lift_load16(cpu->eax + ((uint32_t)(cpu->edx) * 2u) + 6u);
    cpu->ebx -= cpu->edi;
    cpu->ebx += cpu->ebp;
    lift_store32(cpu->esp + 0x40u, cpu->ebx);
    cpu->ebx = lift_load16(cpu->eax + ((uint32_t)(cpu->edx) * 2u) + 4u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x40u)))));
    cpu->ebx -= cpu->ecx;
    cpu->ecx = lift_load16(cpu->eax + ((uint32_t)(cpu->edx) * 2u) + 0xAu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    cpu->ebx -= cpu->edi;
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx += cpu->ebp;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store32(cpu->esp + 0x40u, cpu->ebx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x24u))));
    cpu->ebx = lift_load16(cpu->eax + ((uint32_t)(cpu->edx) * 2u) + 8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x20u))));
    cpu->ebx -= cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->ebx -= cpu->edi;
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx += cpu->ebp;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x40u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store32(cpu->esp + 0x40u, cpu->ebx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x28u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x24u))));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x40u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x2Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0002DD68: cpu->eip = LIFT_CODE_TOKEN_VA(0x42DD68u);
    if ((uint8_t)((lift_load8(cpu->esi + 0x34u)) & (2u)) == 0u) goto label_0002DDFD;
    cpu->ebx = lift_load16(cpu->eax + ((uint32_t)(cpu->edx) * 2u) + 4u);
    cpu->ecx = lift_load16(cpu->eax + ((uint32_t)(cpu->edx) * 2u) + 0xAu);
    cpu->ecx -= cpu->ebx;
    cpu->ebx = lift_load16(cpu->eax + ((uint32_t)(cpu->edx) * 2u) + 2u);
    cpu->ecx -= cpu->edi;
    cpu->ecx += cpu->ebp;
    lift_store32(cpu->esp + 0x40u, cpu->ecx);
    cpu->ecx = lift_load16(cpu->eax + ((uint32_t)(cpu->edx) * 2u) + 6u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x40u)))));
    cpu->ecx -= cpu->ebx;
    cpu->ecx -= cpu->edi;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    cpu->ecx += cpu->ebp;
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store32(cpu->esp + 0x40u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x54u))));
    cpu->ecx = lift_load16(cpu->eax + ((uint32_t)(cpu->edx) * 2u) + 0xCu);
    cpu->edx = lift_load16(cpu->eax + ((uint32_t)(cpu->edx) * 2u) + 8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x14u))));
    cpu->edx -= cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx -= cpu->edi;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x40u)))));
    cpu->edx += cpu->ebp;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_store32(cpu->esp + 0x40u, cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x58u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * ((double)(((int32_t)(lift_load32(cpu->esp + 0x40u))))));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x5Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0002DDFF;
    label_0002DDFD: cpu->eip = LIFT_CODE_TOKEN_VA(0x42DDFDu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0002DDFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x42DDFFu);
    if ((uint8_t)((lift_load8(cpu->ecx + 8u)) & (1u)) == 0u) goto label_0002DE44;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.1415929794311523));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42DE1Cu); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.5));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u));
    goto label_0002DE54;
    label_0002DE44: cpu->eip = LIFT_CODE_TOKEN_VA(0x42DE44u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    label_0002DE54: cpu->eip = LIFT_CODE_TOKEN_VA(0x42DE54u);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_pop32(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx = lift_pop32(cpu);
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 20u, stop_address); return;
    label_0002DE96: cpu->eip = LIFT_CODE_TOKEN_VA(0x42DE96u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002DFE1;
    cpu->eax = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    if ((uint8_t)(((cpu->ecx & 0xFFu)) & (1u)) == 0u) goto label_0002DF22;
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    cpu->esi = lift_load16(cpu->ecx + 2u);
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    cpu->esi += cpu->edx;
    lift_store32(cpu->esp + 0x3Cu, cpu->esi);
    cpu->esi = lift_load16(cpu->ecx + 4u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_push(cpu, 1.5259021893143654e-05);
    cpu->ecx = lift_load16(cpu->ecx);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    cpu->esi += cpu->edx;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->esp + 0x3Cu, cpu->esi);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx += cpu->edx;
    cpu->edi = lift_pop32(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x38u)))));
    lift_store32(cpu->esp + 0x38u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->esi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    cpu->ebx = lift_pop32(cpu);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * ((double)(((int32_t)(lift_load32(cpu->esp + 0x30u))))));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x24u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x18u))));
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x1Cu))));
    lift_store_f32(cpu->ecx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x2Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x2Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x20u))));
    lift_store_f32(cpu->ecx + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 20u, stop_address); return;
    label_0002DF22: cpu->eip = LIFT_CODE_TOKEN_VA(0x42DF22u);
    if ((uint8_t)(((cpu->ecx & 0xFFu)) & (2u)) == 0u) goto label_0002DFC3;
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    cpu->edx = lift_load16(cpu->ecx + 6u);
    cpu->edi = lift_load16(cpu->ecx + 4u);
    cpu->esi = lift_load32(cpu->esp + 0x34u);
    cpu->ebx = lift_load16(cpu->ecx + 8u);
    cpu->edi -= cpu->edx;
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    cpu->edi -= cpu->edx;
    cpu->edi += cpu->esi;
    lift_store32(cpu->esp + 0x3Cu, cpu->edi);
    cpu->edi = lift_load16(cpu->ecx + 0xAu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    lift_x87_push(cpu, 1.5259021893143654e-05);
    cpu->ebx -= cpu->edi;
    cpu->edi = lift_load16(cpu->ecx + 2u);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) * (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->ecx = lift_load16(cpu->ecx);
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx -= cpu->edx;
    cpu->ebx += cpu->esi;
    lift_store32(cpu->esp + 0x3Cu, cpu->ebx);
    cpu->ecx -= cpu->edi;
    cpu->ecx -= cpu->edx;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x3Cu)))));
    cpu->ecx += cpu->esi;
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * ((double)(((int32_t)(lift_load32(cpu->esp + 0x30u))))));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->eax + 0x24u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x18u))));
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x28u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x28u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x1Cu))));
    lift_store_f32(cpu->ecx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x2Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x2Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x20u))));
    lift_store_f32(cpu->ecx + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 20u, stop_address); return;
    label_0002DFC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x42DFC3u);
    cpu->edx = lift_load32(cpu->eax + 0x18u);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 0x1Cu);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 0x20u);
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 20u, stop_address); return;
    label_0002DFE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x42DFE1u);
    lift_x87_push(cpu, 0.0);
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    cpu->edi = lift_pop32(cpu);
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u));
    cpu->esi = lift_pop32(cpu);
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042E000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E000u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002E030;
    cpu->edx = 0x55u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectTrack.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E018u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E020u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->esi + 4u, 0u);
    label_0002E030: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E030u);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->edi) == 0u) goto label_0002E077;
    cpu->edx = 0x5Cu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\EffectTrack.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E047u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->edi;
    cpu->edx = 0x30u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E05Fu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->edi) * 4u));
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x42E06Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E074u);
    cpu->esp += 0x10u;
    label_0002E077: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E077u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042E080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E080u);
    cpu->esp -= 0x174u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x17Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u); lift_push32(cpu, 2u);
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::CreateToolhelp32Snapshot), LIFT_CODE_TOKEN_VA(0x42E0A4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E0A9u);
    cpu->edi = cpu->eax;
    lift_store32(cpu->esp + 0xCu, cpu->edi);
    if ((uint32_t)(cpu->edi) == (uint32_t)(0xFFFFFFFFu)) goto label_0002E0D2;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x1Cu, 0x128u);
    lift_native_call(cpu, native_function_address32(&::Process32First), LIFT_CODE_TOKEN_VA(0x42E0C2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E0C7u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0002E0DA;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_RVA(0x2E0CCu));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x2E0D2u);
    label_0002E0D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E0D2u);
    cpu->eax |= 0xFFFFFFFFu;
    goto label_0002E1A7;
    label_0002E0DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E0DAu);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    cpu->edi = cpu->edi;
    label_0002E0E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E0E0u);
    if (sfera_process_name_is_ignored(cpu->esp + 0x38u)) { goto label_0002E180; }
    label_0002E15E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E15Eu);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFFFu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x42E16Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E172u);
    cpu->esp += 0xCu;
    lift_store8(cpu->esi + cpu->ebp + 0xFFFFFFFFu, 0u);
    cpu->esi += cpu->ebp;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    label_0002E180: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E180u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::Process32Next), LIFT_CODE_TOKEN_VA(0x42E18Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E18Fu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0002E0E0;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_VA(0x42E19Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E1A2u);
    cpu->eax = 1u;
    label_0002E1A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E1A7u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x174u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042E1D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E1D0u);
    cpu->eax = (uint32_t)(uintptr_t)&g_sfera_error_log_runtime.object[0];
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042E210(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E210u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = 0x5Cu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    std::construct_at(reinterpret_cast<IOutputDevice*>(cpu->esi));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E228u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x4000u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E232u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->esp += 4u;
    std::construct_at(reinterpret_cast<COutputLogDevice*>(cpu->esi));
    lift_store32(cpu->esi + 8u, 0u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042E250(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E250u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    std::construct_at(reinterpret_cast<COutputLogDevice*>(cpu->esi));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002E2A7;
    cpu->edx = 0xA0u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E29Bu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E2A4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0002E2A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E2A7u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    std::construct_at(reinterpret_cast<IOutputDevice*>(cpu->esi));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002E2D6;
    cpu->edx = 0x65u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E2CAu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E2D3u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0002E2D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E2D6u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042E2F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E2F0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0002E3DF;
    cpu->eax = cpu->ebx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0002E308: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E308u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0002E308;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002E3DE;
    cpu->edx = 0xAEu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E329u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    ++cpu->esi;
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E330u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->edi + 8u, cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002E3DE;
    cpu->ecx = cpu->ebx;
    cpu->edx = cpu->eax;
    label_0002E342: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E342u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0002E342;
    cpu->eax = lift_load32(cpu->edi + 8u);
    lift_push32(cpu, (uintptr_t)"wt"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x42E355u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E35Bu);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) != 0u) goto label_0002E38B;
    cpu->edx = 0xB6u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E373u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + 8u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E37Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->edi + 8u, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
    label_0002E38B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E38Bu);
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x42E38Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E393u);
    cpu->edi = native_function_address32(&::fprintf);
    lift_push32(cpu, (uintptr_t)"--------------------------------------------------------------------------------\n"); lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x2E3A9u), LIFT_CODE_TOKEN_RVA(0x2E3A7u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E3A9u);
    lift_push32(cpu, (uintptr_t)" Sphere log file\n"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x2E3B1u), LIFT_CODE_TOKEN_RVA(0x2E3AFu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E3B1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x42E3B6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E3BCu);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::asctime), LIFT_CODE_TOKEN_VA(0x42E3BDu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E3C3u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)" Log file created on %s"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x2E3CCu), LIFT_CODE_TOKEN_RVA(0x2E3CAu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E3CCu);
    lift_push32(cpu, (uintptr_t)"--------------------------------------------------------------------------------\n\n"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x2E3D4u), LIFT_CODE_TOKEN_RVA(0x2E3D2u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E3D4u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x42E3D5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E3DBu);
    cpu->esp += 0x34u;
    label_0002E3DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E3DEu);
    cpu->esi = lift_pop32(cpu);
    label_0002E3DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E3DFu);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042E3F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E3F0u);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002E429;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"a+t"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x42E3FEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E404u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0002E428;
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"- %s\n"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x42E418u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E41Eu);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x42E41Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E425u);
    cpu->esp += 0x10u;
    label_0002E428: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E428u);
    cpu->esi = lift_pop32(cpu);
    label_0002E429: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E429u);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042E430(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E430u);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E439u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042E440(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E440u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = 0x5Cu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    std::construct_at(reinterpret_cast<IOutputDevice*>(cpu->esi));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E458u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x4000u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E462u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->esp += 4u;
    std::construct_at(reinterpret_cast<CSphereError*>(cpu->esi));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042E480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E480u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax + 4u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_0002E4B7;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0002E4B7;
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002E4B7;
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::vsprintf), LIFT_CODE_TOKEN_VA(0x42E4A2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E4A8u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<IOutputDevice*>(cpu->ecx)->write(cpu);
    label_0002E4B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E4B7u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042E4C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E4C0u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::vsprintf);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0002E509;
    lift_push32(cpu, (uint32_t)(uintptr_t)"*** ERROR ****************************************************:");
    reinterpret_cast<IOutputDevice*>(cpu->ecx)->write(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E4DFu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->esi = lift_load32(cpu->edi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002E50D;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0002E50D;
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x2E4FAu), LIFT_CODE_TOKEN_RVA(0x2E4F8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E4FAu);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<IOutputDevice*>(cpu->ecx)->write(cpu);
    label_0002E509: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E509u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    label_0002E50D: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E50Du);
    cpu->esi = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->esi) == 0u) goto label_0002E536;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002E536;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0002E536;
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x2E527u), LIFT_CODE_TOKEN_RVA(0x2E525u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E527u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<IOutputDevice*>(cpu->ecx)->write(cpu);
    label_0002E536: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E536u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042E540(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E540u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esi + 8u, 0u);
    lift_store32(cpu->esi + 0xCu, 0u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0002E5B8;
    cpu->edx = 0xE9u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E588u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E58Fu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002E5AB;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E5A9u); lift_push32(cpu, r); sfera_sub_0042E440(cpu,r); if (cpu->eip != r) return; }
    goto label_0002E5AD;
    label_0002E5AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E5ABu);
    cpu->eax = 0u;
    label_0002E5AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E5ADu);
    lift_store32(cpu->esp + 0x10u, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 8u, cpu->eax);
    label_0002E5B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E5B8u);
    lift_store32(cpu->esi, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0002E610;
    cpu->edx = 0xF1u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E5D1u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E5D8u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002E5F4;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E5F2u); lift_push32(cpu, r); sfera_sub_0042E210(cpu,r); if (cpu->eip != r) return; }
    goto label_0002E5F6;
    label_0002E5F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E5F4u);
    cpu->eax = 0u;
    label_0002E5F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E5F6u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"sphere.log");
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0xCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E60Du); lift_push32(cpu, r); sfera_sub_0042E2F0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    label_0002E610: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E610u);
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->eax = cpu->esi;
    lift_store32(cpu->esi + 0x10u, 1u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042E6B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E6B0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->edx;
    lift_push32(cpu, (uintptr_t)"r"); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->ebp + 0xFFFFFFF8u, cpu->ebx);
    cpu->edi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x42E6D0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E6D6u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0002E73C;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E6E7u); lift_push32(cpu, r); sfera_sub_004EEA10(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebp + 0xCu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebx = cpu->esp;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002E701;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, 2u);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fseek), LIFT_CODE_TOKEN_VA(0x42E6F8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E6FEu);
    cpu->esp += 0xCu;
    label_0002E701: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E701u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fread), LIFT_CODE_TOKEN_VA(0x42E709u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E70Fu);
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->ebp + 8u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x42E713u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E719u);
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFF8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"\n%s\n->\n"); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x42E723u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E729u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fwrite), LIFT_CODE_TOKEN_VA(0x42E731u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E737u);
    cpu->esp += 0x30u;
    goto label_0002E74C;
    label_0002E73C: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E73Cu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"\n%s not found!\n"); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x42E743u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E749u);
    cpu->esp += 0xCu;
    label_0002E74C: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E74Cu);
    cpu->esp = (uint32_t)(cpu->ebp + 0xFFFFFFECu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042E770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E770u);
    cpu->eax = (uint32_t)(uintptr_t)"app-is-Run.1";
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::fopen);
    lift_push32(cpu, (uintptr_t)"r"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x2E784u), LIFT_CODE_TOKEN_RVA(0x2E782u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E784u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002E844;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::fclose);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x2E79Au), LIFT_CODE_TOKEN_RVA(0x2E798u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E79Au);
    cpu->ecx = (uint32_t)(uintptr_t)"client-Crash.1";
    lift_push32(cpu, (uintptr_t)"w"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x2E7A8u), LIFT_CODE_TOKEN_RVA(0x2E7A6u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E7A8u);
    cpu->edi = native_function_address32(&::remove);
    cpu->esi = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0002E82E;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x3E8u);
    cpu->edx = (uint32_t)(uintptr_t)"ERRORLOG.TXT";
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E7CAu); lift_push32(cpu, r); sfera_sub_0042E6B0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"ERRORLOG.TXT");
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x2E7D1u), LIFT_CODE_TOKEN_RVA(0x2E7CFu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E7D1u);
    cpu->esp += 4u;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x258u);
    cpu->edx = (uint32_t)(uintptr_t)"Error.log";
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E7E7u); lift_push32(cpu, r); sfera_sub_0042E6B0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"Error.log");
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x2E7EEu), LIFT_CODE_TOKEN_RVA(0x2E7ECu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E7EEu);
    cpu->esp += 4u;
    lift_push32(cpu, 1u); lift_push32(cpu, 0xC8u);
    cpu->edx = (uint32_t)(uintptr_t)"Warnings00.log";
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E804u); lift_push32(cpu, r); sfera_sub_0042E6B0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"Warnings00.log");
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x2E80Bu), LIFT_CODE_TOKEN_RVA(0x2E809u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E80Bu);
    cpu->edx = (uint32_t)(uintptr_t)"error-Cause.1";
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x32u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E81Fu); lift_push32(cpu, r); sfera_sub_0042E6B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(uintptr_t)"error-Cause.1";
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x2E828u), LIFT_CODE_TOKEN_RVA(0x2E826u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E828u);
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x2E82Bu), LIFT_CODE_TOKEN_RVA(0x2E829u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E82Bu);
    cpu->esp += 8u;
    label_0002E82E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E82Eu);
    cpu->eax = (uint32_t)(uintptr_t)"error-Cause.1";
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x2E836u), LIFT_CODE_TOKEN_RVA(0x2E834u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E836u);
    cpu->ecx = (uint32_t)(uintptr_t)"app-is-Run.1";
    lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x2E83Fu), LIFT_CODE_TOKEN_RVA(0x2E83Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E83Fu);
    cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0002E844: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E844u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042E850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E850u);
    cpu->esp -= 0x104u;
    cpu->eax = (uint32_t)(uintptr_t)"app-is-Run.1";
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_access), LIFT_CODE_TOKEN_VA(0x42E86Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E872u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_0002E904;
    cpu->ecx = (uint32_t)(uintptr_t)"app-is-Run.1";
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x42E885u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E88Bu);
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002E904;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_errno), LIFT_CODE_TOKEN_VA(0x42E894u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E89Au);
    cpu->edx = (uint32_t)(uintptr_t)"error-Cause.1";
    cpu->edi = lift_load32(cpu->eax);
    lift_push32(cpu, (uintptr_t)"w"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x42E8A8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E8AEu);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0002E902;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::strerror), LIFT_CODE_TOKEN_VA(0x42E8B8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E8BEu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(uintptr_t)"app-is-Run.1";
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, (uintptr_t)"File %s not deleted (~), error cause: %s\n"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x42E8CFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E8D5u);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->esp += 0x14u;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_0002E8E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E8E0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0002E8E0;
    lift_push32(cpu, cpu->esi);
    cpu->eax -= cpu->edx;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::fwrite), LIFT_CODE_TOKEN_VA(0x42E8F2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E8F8u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x42E8F9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E8FFu);
    cpu->esp += 0x14u;
    label_0002E902: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E902u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_0002E904: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E904u);
    cpu->esp += 0x104u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042E920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E920u);
    cpu->eax = g_sfera_file_runtime.crash_report_instance;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0002E981;
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0x12Cu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\FastCrashReport.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E939u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E940u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->esp += 4u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0002E979;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42E94Eu); lift_push32(cpu, r); sfera_sub_0042E770(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(uintptr_t)"app-is-Run.1";
    lift_push32(cpu, (uintptr_t)"w"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x42E959u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E95Fu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002E970;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x42E967u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E96Du);
    cpu->esp += 4u;
    label_0002E970: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E970u);
    cpu->eax = cpu->esi;
    g_sfera_file_runtime.crash_report_instance = (uint32_t)(cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0002E979: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E979u);
    cpu->eax = 0u;
    g_sfera_file_runtime.crash_report_instance = (uint32_t)(cpu->eax);
    cpu->esi = lift_pop32(cpu);
    label_0002E981: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E981u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042E990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42E990u);
    cpu->esp -= 0x810u;
    cpu->eax = (uint32_t)(uintptr_t)"client-Crash.1";
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"r"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x42E9B0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E9B6u);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0002EA68;
    lift_push32(cpu, 0x800u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x42E9CFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42E9D4u);
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0002E9E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x42E9E0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + ((uint32_t)(uintptr_t)&g_sfera_error_log_runtime.index_table[0]))) & 0xFFu);
    lift_store8(cpu->esp + cpu->eax + 0x11u, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0002E9E0;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x77Bu);
    cpu->edx = (uint32_t)(cpu->esp + 0x9Du);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    lift_store8(cpu->esp + 0x20u, 3u);
    lift_native_call(cpu, native_function_address32(&::fread), LIFT_CODE_TOKEN_VA(0x42EA04u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42EA0Au);
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0xA5u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x42EA12u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42EA18u);
    cpu->esp += 0x14u;
    lift_push32(cpu, 0xB8u);
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0x2BF20u);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    cpu->eax = g_sfera_directplay_runtime.peer;
    lift_push32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x1Cu, 0x800u);
    lift_store32(cpu->esp + 0x18u, 0u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x20u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x2EA58u), LIFT_CODE_TOKEN_RVA(0x2EA56u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42EA58u);
    cpu->ecx = (uint32_t)(uintptr_t)"client-Crash.1";
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x42EA5Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42EA65u);
    cpu->esp += 4u;
    label_0002EA68: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EA68u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x810u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042EB70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42EB70u);
    if ((uint32_t)(g_sfera_file_runtime.crash_report_instance) == (uint32_t)(0u)) goto label_0002EBAE;
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0x136u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\FastCrashReport.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42EB89u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_file_runtime.crash_report_instance;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0002EBA3;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42EB9Au); lift_push32(cpu, r); sfera_sub_0042E850(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42EBA0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0002EBA3: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EBA3u);
    g_sfera_file_runtime.crash_report_instance = (uint32_t)(0u);
    cpu->esi = lift_pop32(cpu);
    label_0002EBAE: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EBAEu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042EBB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42EBB0u);
    g_sfera_file_runtime.callback = (uint32_t)(cpu->ecx);
    g_sfera_file_runtime.callback_enabled = (uint32_t)(1u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042EBD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42EBD0u);
    g_sfera_file_runtime.callback_enabled = (uint32_t)(1u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042EBE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42EBE0u);
    g_sfera_file_runtime.callback_enabled = (uint32_t)(0u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042EBF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42EBF0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edx |= 0x8000u;
    lift_push32(cpu, 0u);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp);
    lift_store32(cpu->esp + 0x1Cu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x42EC05u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42EC0Bu);
    cpu->ebx = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->ebx) == (uint32_t)(0xFFFFFFFFu)) goto label_0002ECBF;
    cpu->eax = cpu->ebp;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->edi = cpu->edi;
    label_0002EC20: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EC20u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0002EC20;
    cpu->ecx = g_sfera_file_runtime.open_file_count;
    cpu->eax -= cpu->edx;
    cpu->edi = cpu->eax;
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_file_runtime.open_files.capacity)) goto label_0002EC45;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.open_files;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2EC45u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002EC45: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EC45u);
    cpu->eax = g_sfera_file_runtime.open_files.data;
    lift_push32(cpu, 0x30u);
    cpu->ecx = (uint32_t)(cpu->edi + 1u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Files.cpp";
    cpu->esi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->esi) * 8u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42EC5Cu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi, cpu->eax);
    cpu->ecx = g_sfera_file_runtime.open_file_count;
    cpu->esi = cpu->ebp;
    cpu->edi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_file_runtime.open_files.capacity)) goto label_0002EC7A;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.open_files;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2EC7Au); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002EC7A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EC7Au);
    cpu->ecx = g_sfera_file_runtime.open_files.data;
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 8u));
    label_0002EC83: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EC83u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    lift_store8(cpu->ecx, cpu->eax & 0xFFu);
    ++cpu->esi;
    ++cpu->ecx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0002EC83;
    cpu->ecx = g_sfera_file_runtime.open_file_count;
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_file_runtime.open_files.capacity)) goto label_0002ECA7;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.open_files;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2ECA7u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002ECA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x42ECA7u);
    cpu->edx = g_sfera_file_runtime.open_files.data;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->edx + ((uint32_t)(cpu->esi) * 8u) + 4u, cpu->ebx);
    ++g_sfera_file_runtime.open_file_count;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0002ECBF: cpu->eip = LIFT_CODE_TOKEN_VA(0x42ECBFu);
    lift_push32(cpu, 0x5Cu); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_strchr_address32(), LIFT_CODE_TOKEN_VA(0x42ECC2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42ECC8u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0002ED9F;
    cpu->ebx = 0u;
    if ((int32_t)(uint32_t)(g_sfera_file_runtime.search_path_count) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0002ED9F;
    label_0002ECE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x42ECE1u);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_file_runtime.search_paths.capacity)) goto label_0002ECF5;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.search_paths;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2ECF5u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002ECF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x42ECF5u);
    cpu->eax = g_sfera_file_runtime.search_paths.data;
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->ebx) * 4u));
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0002ED00: cpu->eip = LIFT_CODE_TOKEN_VA(0x42ED00u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0002ED00;
    cpu->eax -= cpu->edx;
    cpu->edi = cpu->eax;
    cpu->eax = cpu->ebp;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0002ED10: cpu->eip = LIFT_CODE_TOKEN_VA(0x42ED10u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0002ED10;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, 0x3Au);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->edi + 1u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Files.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42ED29u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_file_runtime.search_paths.capacity)) goto label_0002ED3F;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.search_paths;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2ED3Fu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002ED3F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42ED3Fu);
    cpu->ecx = g_sfera_file_runtime.search_paths.data;
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->ebx) * 4u));
    cpu->edx = cpu->esi;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0002ED50: cpu->eip = LIFT_CODE_TOKEN_VA(0x42ED50u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0002ED50;
    cpu->edx = cpu->esi;
    cpu->edx -= cpu->ebp;
    cpu->eax = cpu->ebp;
    cpu->edx += cpu->edi;
    label_0002ED62: cpu->eip = LIFT_CODE_TOKEN_VA(0x42ED62u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0002ED62;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x42ED74u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42ED7Au);
    cpu->edi = cpu->eax;
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->edi) != (uint32_t)(0xFFFFFFFFu)) goto label_0002EDC0;
    lift_push32(cpu, 0x45u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Files.cpp";
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42ED92u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    ++cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_file_runtime.search_path_count)) goto label_0002ECE1;
    label_0002ED9F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42ED9Fu);
    cpu->eax = g_sfera_file_runtime.callback;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002EDB7;
    if ((uint32_t)(g_sfera_file_runtime.callback_enabled) != (uint32_t)(1u)) goto label_0002EDB7;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0u;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x2EDB7u), LIFT_CODE_TOKEN_RVA(0x2EDB5u))) { return; }
    label_0002EDB7: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EDB7u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0002EDC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EDC0u);
    cpu->ecx = g_sfera_file_runtime.open_file_count;
    cpu->ebx = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_file_runtime.open_files.capacity)) goto label_0002EDDA;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.open_files;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2EDDAu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002EDDA: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EDDAu);
    cpu->ecx = g_sfera_file_runtime.open_files.data;
    lift_store32(cpu->ecx + ((uint32_t)(cpu->ebx) * 8u) + 4u, cpu->edi);
    cpu->ecx = g_sfera_file_runtime.open_file_count;
    cpu->ebx = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_file_runtime.open_files.capacity)) goto label_0002EDFE;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.open_files;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2EDFEu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002EDFE: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EDFEu);
    cpu->edx = g_sfera_file_runtime.open_files.data;
    lift_store32(cpu->edx + ((uint32_t)(cpu->ebx) * 8u), cpu->esi);
    ++g_sfera_file_runtime.open_file_count;
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042EE20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42EE20u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x180u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_chmod), LIFT_CODE_TOKEN_VA(0x42EE2Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42EE30u);
    lift_push32(cpu, 0x180u); lift_push32(cpu, 0x8302u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x42EE3Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42EE41u);
    cpu->ebp = cpu->eax;
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(0xFFFFFFFFu)) goto label_0002EEF9;
    cpu->eax = cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_0002EE54: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EE54u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0002EE54;
    cpu->ecx = g_sfera_file_runtime.open_file_count;
    lift_push32(cpu, cpu->ebx);
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->eax;
    cpu->edi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_file_runtime.open_files.capacity)) goto label_0002EE7B;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.open_files;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2EE7Bu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002EE7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EE7Bu);
    cpu->eax = g_sfera_file_runtime.open_files.data;
    lift_push32(cpu, 0x54u);
    cpu->ecx = (uint32_t)(cpu->ebx + 1u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Files.cpp";
    cpu->edi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 8u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42EE92u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi, cpu->eax);
    cpu->ecx = g_sfera_file_runtime.open_file_count;
    cpu->edi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_file_runtime.open_files.capacity)) goto label_0002EEAE;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.open_files;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2EEAEu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002EEAE: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EEAEu);
    cpu->ecx = g_sfera_file_runtime.open_files.data;
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 8u));
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0002EEC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EEC0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    lift_store8(cpu->ecx, cpu->eax & 0xFFu);
    ++cpu->esi;
    ++cpu->ecx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0002EEC0;
    cpu->ecx = g_sfera_file_runtime.open_file_count;
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_file_runtime.open_files.capacity)) goto label_0002EEE4;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.open_files;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2EEE4u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002EEE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EEE4u);
    cpu->edx = g_sfera_file_runtime.open_files.data;
    lift_store32(cpu->edx + ((uint32_t)(cpu->esi) * 8u) + 4u, cpu->ebp);
    ++g_sfera_file_runtime.open_file_count;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0002EEF9: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EEF9u);
    cpu->eax = g_sfera_file_runtime.callback;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002EF14;
    if ((uint32_t)(g_sfera_file_runtime.callback_enabled) != (uint32_t)(1u)) goto label_0002EF14;
    cpu->edx = cpu->esi;
    cpu->ecx = 1u;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x2EF14u), LIFT_CODE_TOKEN_RVA(0x2EF12u))) { return; }
    label_0002EF14: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EF14u);
    cpu->esi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042EF20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42EF20u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->edx;
    cpu->ebx = cpu->ecx;
    if ((int32_t)(uint32_t)(g_sfera_file_runtime.open_file_count) <= (int32_t)(uint32_t)(cpu->esi)) goto label_0002EF5A;
    label_0002EF32: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EF32u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_file_runtime.open_files.capacity)) goto label_0002EF46;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2EF46u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002EF46: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EF46u);
    cpu->eax = g_sfera_file_runtime.open_files.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 8u) + 4u)) == (uint32_t)(cpu->ebx)) goto label_0002EF64;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_file_runtime.open_file_count)) goto label_0002EF32;
    label_0002EF5A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EF5Au);
    cpu->ecx = (uint32_t)(uintptr_t)"Attempt of reading from the file with the wrong handle.";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2EF64u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0002EF64: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EF64u);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x42EF6Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42EF71u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_0002EFBD;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_0002EFF6;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_file_runtime.open_files.capacity)) goto label_0002EF91;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2EF91u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002EF91: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EF91u);
    cpu->eax = g_sfera_file_runtime.callback;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002EFF3;
    if ((uint32_t)(g_sfera_file_runtime.callback_enabled) != (uint32_t)(1u)) goto label_0002EFF3;
    cpu->ecx = g_sfera_file_runtime.open_files.data;
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 8u));
    cpu->ecx = 2u;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x2EFB3u), LIFT_CODE_TOKEN_RVA(0x2EFB1u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42EFB3u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0002EFBD: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EFBDu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_file_runtime.open_files.capacity)) goto label_0002EFD1;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2EFD1u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002EFD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EFD1u);
    cpu->eax = g_sfera_file_runtime.callback;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002EFF3;
    if ((uint32_t)(g_sfera_file_runtime.callback_enabled) != (uint32_t)(1u)) goto label_0002EFF3;
    cpu->edx = g_sfera_file_runtime.open_files.data;
    cpu->edx = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 8u));
    cpu->ecx = 3u;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x2EFF3u), LIFT_CODE_TOKEN_RVA(0x2EFF1u))) { return; }
    label_0002EFF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EFF3u);
    cpu->eax |= 0xFFFFFFFFu;
    label_0002EFF6: cpu->eip = LIFT_CODE_TOKEN_VA(0x42EFF6u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042F000(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42F000u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->edx;
    cpu->ebx = cpu->ecx;
    if ((int32_t)(uint32_t)(g_sfera_file_runtime.open_file_count) <= (int32_t)(uint32_t)(cpu->esi)) goto label_0002F03A;
    label_0002F012: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F012u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_file_runtime.open_files.capacity)) goto label_0002F026;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2F026u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002F026: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F026u);
    cpu->eax = g_sfera_file_runtime.open_files.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 8u) + 4u)) == (uint32_t)(cpu->ebx)) goto label_0002F044;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_file_runtime.open_file_count)) goto label_0002F012;
    label_0002F03A: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F03Au);
    cpu->ecx = (uint32_t)(uintptr_t)"Attempt of writing to the file with the wrong handle.";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2F044u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0002F044: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F044u);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_write), LIFT_CODE_TOKEN_VA(0x42F04Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42F051u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_0002F09D;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_0002F0D6;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_file_runtime.open_files.capacity)) goto label_0002F071;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2F071u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002F071: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F071u);
    cpu->eax = g_sfera_file_runtime.callback;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002F0D3;
    if ((uint32_t)(g_sfera_file_runtime.callback_enabled) != (uint32_t)(1u)) goto label_0002F0D3;
    cpu->ecx = g_sfera_file_runtime.open_files.data;
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 8u));
    cpu->ecx = 4u;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x2F093u), LIFT_CODE_TOKEN_RVA(0x2F091u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42F093u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0002F09D: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F09Du);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_file_runtime.open_files.capacity)) goto label_0002F0B1;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2F0B1u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002F0B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F0B1u);
    cpu->eax = g_sfera_file_runtime.callback;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002F0D3;
    if ((uint32_t)(g_sfera_file_runtime.callback_enabled) != (uint32_t)(1u)) goto label_0002F0D3;
    cpu->edx = g_sfera_file_runtime.open_files.data;
    cpu->edx = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 8u));
    cpu->ecx = 5u;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x2F0D3u), LIFT_CODE_TOKEN_RVA(0x2F0D1u))) { return; }
    label_0002F0D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F0D3u);
    cpu->eax |= 0xFFFFFFFFu;
    label_0002F0D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F0D6u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042F0E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42F0E0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->edx;
    cpu->edi = cpu->ecx;
    if ((int32_t)(uint32_t)(g_sfera_file_runtime.open_file_count) <= (int32_t)(uint32_t)(cpu->esi)) goto label_0002F119;
    label_0002F0F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F0F1u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_file_runtime.open_files.capacity)) goto label_0002F105;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2F105u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002F105: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F105u);
    cpu->eax = g_sfera_file_runtime.open_files.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 8u) + 4u)) == (uint32_t)(cpu->edi)) goto label_0002F123;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_file_runtime.open_file_count)) goto label_0002F0F1;
    label_0002F119: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F119u);
    cpu->ecx = (uint32_t)(uintptr_t)"Attempt of seeking in the file with the wrong handle.";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2F123u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0002F123: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F123u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_lseek), LIFT_CODE_TOKEN_VA(0x42F12Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42F130u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_0002F171;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_file_runtime.open_files.capacity)) goto label_0002F14C;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2F14Cu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002F14C: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F14Cu);
    cpu->eax = g_sfera_file_runtime.callback;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002F16E;
    if ((uint32_t)(g_sfera_file_runtime.callback_enabled) != (uint32_t)(1u)) goto label_0002F16E;
    cpu->edx = g_sfera_file_runtime.open_files.data;
    cpu->edx = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 8u));
    cpu->ecx = 6u;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x2F16Eu), LIFT_CODE_TOKEN_RVA(0x2F16Cu))) { return; }
    label_0002F16E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F16Eu);
    cpu->eax |= 0xFFFFFFFFu;
    label_0002F171: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F171u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042F180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42F180u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)(uint32_t)(g_sfera_file_runtime.open_file_count) <= (int32_t)(uint32_t)(cpu->esi)) goto label_0002F1B8;
    cpu->edi = cpu->edi;
    label_0002F190: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F190u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_file_runtime.open_files.capacity)) goto label_0002F1A4;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2F1A4u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002F1A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F1A4u);
    cpu->eax = g_sfera_file_runtime.open_files.data;
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 8u) + 4u)) == (uint32_t)(cpu->edi)) goto label_0002F1C2;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_file_runtime.open_file_count)) goto label_0002F190;
    label_0002F1B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F1B8u);
    cpu->ecx = (uint32_t)(uintptr_t)"Attempt of closing the file with the wrong handle.";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2F1C2u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0002F1C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F1C2u);
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x42F1C3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42F1C9u);
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0002F262;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_file_runtime.open_files.capacity)) goto label_0002F1E8;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2F1E8u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002F1E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F1E8u);
    cpu->ecx = g_sfera_file_runtime.open_files.data;
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 8u));
    lift_push32(cpu, 0x9Fu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Files.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42F200u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = (uint32_t)(cpu->esi + 1u);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(g_sfera_file_runtime.open_files.capacity)) goto label_0002F217;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2F217u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002F217: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F217u);
    cpu->edx = g_sfera_file_runtime.open_files.data;
    cpu->edi = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edi) * 8u));
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_file_runtime.open_files.capacity)) goto label_0002F234;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2F234u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002F234: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F234u);
    cpu->eax = g_sfera_file_runtime.open_file_count;
    cpu->edx = g_sfera_file_runtime.open_files.data;
    cpu->eax -= cpu->esi;
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFF8u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->esi) * 8u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x42F24Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42F254u);
    --g_sfera_file_runtime.open_file_count;
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0002F262: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F262u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_file_runtime.open_files.capacity)) goto label_0002F276;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2F276u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002F276: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F276u);
    cpu->eax = g_sfera_file_runtime.callback;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0002F298;
    if ((uint32_t)(g_sfera_file_runtime.callback_enabled) != (uint32_t)(1u)) goto label_0002F298;
    cpu->ecx = g_sfera_file_runtime.open_files.data;
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 8u));
    cpu->ecx = 7u;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x2F298u), LIFT_CODE_TOKEN_RVA(0x2F296u))) { return; }
    label_0002F298: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F298u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042F2A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42F2A0u);
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42F2A8u); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_0002F2C8;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_filelength), LIFT_CODE_TOKEN_VA(0x42F2B1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x42F2B7u);
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42F2C3u); lift_push32(cpu, r); sfera_sub_0042F180(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0002F2C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F2C8u);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042F2D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42F2D0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->esi;
    lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0002F2E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F2E0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0002F2E0;
    cpu->ecx = g_sfera_file_runtime.search_path_count;
    cpu->eax -= cpu->edx;
    cpu->ebx = cpu->eax;
    cpu->edi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_file_runtime.search_paths.capacity)) goto label_0002F305;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.search_paths;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2F305u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002F305: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F305u);
    cpu->eax = g_sfera_file_runtime.search_paths.data;
    lift_push32(cpu, 0xCAu);
    cpu->ecx = (uint32_t)(cpu->ebx + 2u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\Files.cpp";
    cpu->edi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42F31Fu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi, cpu->eax);
    cpu->ecx = g_sfera_file_runtime.search_path_count;
    cpu->edi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_file_runtime.search_paths.capacity)) goto label_0002F33B;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.search_paths;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2F33Bu); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002F33B: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F33Bu);
    cpu->ecx = g_sfera_file_runtime.search_paths.data;
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u));
    label_0002F344: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F344u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    lift_store8(cpu->ecx, cpu->eax & 0xFFu);
    ++cpu->esi;
    ++cpu->ecx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0002F344;
    cpu->ecx = g_sfera_file_runtime.search_path_count;
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_file_runtime.search_paths.capacity)) goto label_0002F36E;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.search_paths;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42F368u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_file_runtime.search_path_count;
    label_0002F36E: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F36Eu);
    cpu->edx = g_sfera_file_runtime.search_paths.data;
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    if ((uint8_t)(lift_load8(cpu->eax + cpu->ebx + 0xFFFFFFFFu)) == (uint8_t)(0x5Cu)) goto label_0002F3D0;
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_file_runtime.search_paths.capacity)) goto label_0002F392;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.search_paths;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2F392u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002F392: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F392u);
    cpu->ecx = g_sfera_file_runtime.search_paths.data;
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    lift_store8(cpu->ebx + cpu->edx, 0x5Cu);
    cpu->ecx = g_sfera_file_runtime.search_path_count;
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_file_runtime.search_paths.capacity)) goto label_0002F3B9;
    cpu->edx = (uint32_t)(uintptr_t)&g_sfera_file_runtime.search_paths;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x2F3B9u); lift_push32(cpu, r); sfera_sub_00401030(cpu,r); if (cpu->eip != r) return; }
    label_0002F3B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F3B9u);
    cpu->eax = g_sfera_file_runtime.search_paths.data;
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->ecx + cpu->ebx + 1u, 0u);
    ++g_sfera_file_runtime.search_path_count;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0002F3D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F3D0u);
    cpu->edi = lift_pop32(cpu);
    ++cpu->ecx;
    cpu->esi = lift_pop32(cpu);
    g_sfera_file_runtime.search_path_count = (uint32_t)(cpu->ecx);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042F3E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42F3E0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42F409u); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0002F43D;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->esi + 8u))) / (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0002F43D: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F43Du);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042F450(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42F450u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(4u)) goto label_0002F678;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebx += 0xFFFFFFFCu;
    cpu->ebp = cpu->edi;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebp = v; }
    cpu->ebx = lift_shift_right(cpu, cpu->ebx, (uint32_t)(2u), 32u);
    ++cpu->ebx;
    cpu->eax = (uint32_t)(cpu->ecx + 8u);
    cpu->esi = (uint32_t)(cpu->edi + 0xCu);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->ebx) * 4u));
    label_0002F490: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F490u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFF8u));
    cpu->edi = lift_load32(cpu->edx);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFFCu));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0xCu))));
    lift_store_f32(cpu->esi + 0xFFFFFFF4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_load32(cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x1Cu))));
    lift_store_f32(cpu->esi + 0xFFFFFFF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_load32(cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x24u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 0x20u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x28u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x2Cu))));
    lift_store_f32(cpu->eax + cpu->ebp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_load32(cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xCu));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0xCu))));
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_load32(cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x1Cu))));
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_load32(cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x24u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 0x20u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x28u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x2Cu))));
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_load32(cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x18u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0xCu))));
    lift_store_f32(cpu->esi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_load32(cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x1Cu))));
    lift_store_f32(cpu->esi + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_load32(cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x24u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 0x20u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x28u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x2Cu))));
    lift_store_f32(cpu->esi + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_load32(cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1Cu));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x20u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x24u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0xCu))));
    lift_store_f32(cpu->esi + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_load32(cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    cpu->eax += 0x30u;
    cpu->esi += 0x30u;
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x1Cu))));
    lift_store_f32(cpu->esi + 0xFFFFFFECu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_load32(cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x24u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi + 0x20u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x28u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi + 0x2Cu))));
    lift_store_f32(cpu->esi + 0xFFFFFFF0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002F490;
    cpu->ebx = lift_load32(cpu->esp + 0x28u);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    cpu->ebp = lift_pop32(cpu);
    label_0002F678: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F678u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0002F71F;
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->esi = (uint32_t)(cpu->eax + cpu->edi);
    cpu->eax = (uint32_t)(cpu->eax + cpu->ebx + 8u);
    cpu->edi -= cpu->ebx;
    cpu->ebx = lift_load32(cpu->esp + 0x24u);
    cpu->ebx -= cpu->ecx;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0002F6A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F6A0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFF8u));
    cpu->ecx = lift_load32(cpu->edx);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax += 0xCu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFF0u));
    cpu->esi += 0xCu;
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0xFFFFFFF4u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx))));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx + 0xCu))));
    lift_store_f32(cpu->esi + 0xFFFFFFF4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx + 0x1Cu))));
    lift_store_f32(cpu->esi + 0xFFFFFFF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x24u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx + 0x20u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x28u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx + 0x2Cu))));
    lift_store_f32(cpu->eax + cpu->edi + 0xFFFFFFF4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002F6A0;
    label_0002F71F: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F71Fu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042F730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42F730u);
    cpu->esp -= 8u;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    lift_store32(cpu->ecx, cpu->esi);
    cpu->esi = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->ecx + 4u, cpu->esi);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx));
    cpu->eax = lift_load32(cpu->edx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xCu))));
    cpu->esi = lift_pop32(cpu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0x1Cu))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0x2Cu))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x24u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x18u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edx + 0x28u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ecx + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0042F7D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x42F7D0u);
    cpu->esp -= 0xCu;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x42F7E6u); lift_push32(cpu, r); sfera_sub_0042F730(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x50u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0002F863;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x54u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0002F863;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x64u));
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x98u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x5Cu))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x68u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x98u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x60u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x50u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x54u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x54u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x50u))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x70u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x6Cu))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x6Cu))));
    cpu->esi = lift_pop32(cpu);
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = 1u;
    cpu->esp += 0xCu;
    lift_return(cpu, 8u, stop_address); return;
    label_0002F863: cpu->eip = LIFT_CODE_TOKEN_VA(0x42F863u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 8u, stop_address); return;
}
