#include "lifted_functions.h"
#include <cmath>
namespace lifted {

static uint8_t sfera_ascii_lower(uint8_t value) { return value >= 'A' && value <= 'Z' ? (uint8_t)(value + ('a' - 'A')) : value; }
static uint32_t sfera_ascii_hash_ci(uint32_t address) { uint32_t hash = UINT32_C(2166136261); for (;;) { const uint8_t value = *(uint8_t*)(address++); if (value == 0u) { return hash; } hash = (hash ^ sfera_ascii_lower(value)) * UINT32_C(16777619); } }
static int sfera_ascii_iequals(uint32_t address, const char* literal) { for (;;) { const uint8_t left = sfera_ascii_lower(*(uint8_t*)(address++)); const uint8_t right = sfera_ascii_lower((uint8_t)*literal++); if (left != right) { return 0; } if (left == 0u) { return 1; } } }
static int sfera_process_name_is_ignored(uint32_t address) { switch (sfera_ascii_hash_ci(address)) { case 0xCB320621u: return sfera_ascii_iequals(address, "[System Process]"); case 0xC301CF93u: return sfera_ascii_iequals(address, "idle"); case 0xF84B2A97u: return sfera_ascii_iequals(address, "csrss.exe"); case 0xDE6F2DFEu: return sfera_ascii_iequals(address, "winlogon.exe"); case 0x86049695u: return sfera_ascii_iequals(address, "smss.exe"); case 0x28FDCADBu: return sfera_ascii_iequals(address, "services.exe"); case 0x523B71BAu: return sfera_ascii_iequals(address, "service.exe"); case 0x6105AD4Fu: return sfera_ascii_iequals(address, "lsass.exe"); case 0x82611D84u: return sfera_ascii_iequals(address, "taskmgr.exe"); case 0x491E0A9Cu: return sfera_ascii_iequals(address, "system"); case 0x2453F3B9u: return sfera_ascii_iequals(address, "svchost.exe"); case 0xC979C6AEu: return sfera_ascii_iequals(address, "cdantsrv.exe"); case 0x6369D323u: return sfera_ascii_iequals(address, "spoolsv.exe"); case 0xA162EC55u: return sfera_ascii_iequals(address, "mdm.exe"); case 0x48545BE6u: return sfera_ascii_iequals(address, "nvsvc32.exe"); case 0x708EA5E0u: return sfera_ascii_iequals(address, "far.exe"); case 0x130CD4F6u: return sfera_ascii_iequals(address, "regsvc32.exe"); case 0xA11E0AEu: return sfera_ascii_iequals(address, "mstask.exe"); case 0xABDAFF7Eu: return sfera_ascii_iequals(address, "winmgmt.exe"); case 0x8AE4CC97u: return sfera_ascii_iequals(address, "stisvc.exe"); case 0xDB3A61B5u: return sfera_ascii_iequals(address, "rundll32.exe"); case 0xE566D06Eu: return sfera_ascii_iequals(address, "wcescoomm.exe"); case 0xA062BD36u: return sfera_ascii_iequals(address, "internat.exe"); case 0x5037C1B7u: return sfera_ascii_iequals(address, "winword.exe"); case 0x399460A4u: return sfera_ascii_iequals(address, "explorer.exe"); case 0xB884A32Cu: return sfera_ascii_iequals(address, "notepad.exe"); case 0x82407190u: return sfera_ascii_iequals(address, "ctfmon.exe"); case 0xFFB78D72u: return sfera_ascii_iequals(address, "icq.exe"); case 0x3BC05E55u: return sfera_ascii_iequals(address, "iexplore.exe"); case 0x8C6DE00Au: return sfera_ascii_iequals(address, "srvany.exe"); case 0x47785D4Cu: return sfera_ascii_iequals(address, "spidernt.exe"); case 0xF7D48DE3u: return sfera_ascii_iequals(address, "winamp.exe"); case 0xD391162Bu: return sfera_ascii_iequals(address, "kav.exe"); case 0x83888858u: return sfera_ascii_iequals(address, "winrar.exe"); case 0x4FB24653u: return sfera_ascii_iequals(address, "kavsvc.exe"); case 0x73D09132u: return sfera_ascii_iequals(address, "ati2evxx.exe"); case 0x796F943u: return sfera_ascii_iequals(address, "regsvc.exe"); case 0x51E34A6Eu: return sfera_ascii_iequals(address, "mspmspsv.exe"); case 0x94FF76ADu: return sfera_ascii_iequals(address, "resetservice.exe"); case 0x17B4BBA5u: return sfera_ascii_iequals(address, "directcd.exe"); case 0x5AB899A3u: return sfera_ascii_iequals(address, "qttask.exe"); case 0x91BFD53Cu: return sfera_ascii_iequals(address, "atiptaxx.exe"); case 0x681423EEu: return sfera_ascii_iequals(address, "SOUNDMAN.EXE"); case 0x4DF48812u: return sfera_ascii_iequals(address, "wuauclt.exe"); case 0x5ECB2F2Cu: return sfera_ascii_iequals(address, "miranda32.exe"); case 0xB7110726u: return sfera_ascii_iequals(address, "sphere.exe"); case 0xBB309AE5u: return sfera_ascii_iequals(address, "cmd.exe"); case 0xEDFBE74Au: return sfera_ascii_iequals(address, "calc.exe"); case 0x5D2A3611u: return sfera_ascii_iequals(address, "thebat.exe"); default: return 0; } }
__declspec(noinline) void sfera_sub_004266D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = 0u;
    if (*(uint8_t*)(cpu->ecx + 0xDu) == (cpu->edx & 0xFFu)) goto label_00026700;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xB4u);
    if (cpu->eax == cpu->edx) goto label_000266FD;
    if (*(uint32_t*)(cpu->eax + 0x38u) != cpu->edx) goto label_000266FD;
    if (*(uint32_t*)(cpu->eax + 8u) != cpu->edx) goto label_000266FD;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x68u);
    if (cpu->eax == cpu->edx) goto label_000266F7;
    if (*(uint32_t*)(cpu->eax + 0x6Cu) == cpu->edx) goto label_000266FD;
    label_000266F7:
    *(uint32_t*)(cpu->ecx + 0xA8u) = cpu->edx;
    label_000266FD:
    *(uint8_t*)(cpu->ecx + 0xDu) = cpu->edx & 0xFFu;
    label_00026700:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00426710(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, 0.0);
    cpu->eax = cpu->ecx;
    *(float*)(cpu->esp) = cpu->fpu[0u];
    *(uint32_t*)(cpu->eax + 0xCu) = 0xFFFFFFFFu;
    cpu->ecx = *(uint32_t*)(cpu->esp);
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    lift_x87_push(cpu, (double)255.0f);
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    *(float*)(cpu->eax + 0x28u) = cpu->fpu[0u];
    *(float*)(cpu->eax + 0x24u) = cpu->fpu[0u];
    *(uint32_t*)(cpu->eax + 0x14u) = cpu->edx;
    *(float*)(cpu->eax + 0x20u) = cpu->fpu[0u];
    *(uint32_t*)(cpu->eax + 0x18u) = cpu->ecx;
    *(float*)(cpu->eax + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = 0u;
    lift_x87_push(cpu, 1.0);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(float*)(cpu->eax + 0x50u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x2Cu) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x30u) = cpu->ecx;
    *(float*)(cpu->eax + 0x54u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->eax + 0x34u) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 0x60u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x58u) = 1u;
    *(uint32_t*)(cpu->eax + 0x5Cu) = cpu->ecx;
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00426780(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x44u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x5Cu);
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4267B0u)); sfera_sub_00494900(cpu, LIFT_CODE_TOKEN_VA(0x4267B0u));
    cpu->edx = 0xAA3u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4267BFu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4267BFu));
    lift_push32(cpu, 0x200u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4267C9u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4267C9u));
    cpu->esp += 4u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"light_pos");
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4267DDu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4267DDu));
    cpu->ebx = native_function_address32(&::sscanf);
    if (cpu->eax == 0u) goto label_00026801;
    cpu->edx = cpu->esi + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%f %f %f"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x267FEu), LIFT_CODE_TOKEN_RVA(0x267FCu))) { return; }
    cpu->esp += 0x14u;
    label_00026801:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"light_color");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42680Eu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x42680Eu));
    if (cpu->eax == 0u) goto label_00026850;
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%f %f %f %f"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x26831u), LIFT_CODE_TOKEN_RVA(0x2682Fu))) { return; }
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    *(float*)(cpu->esi + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp += 0x18u;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    *(float*)(cpu->esi + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    *(float*)(cpu->esi + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    *(float*)(cpu->esi + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00026850:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"random_color");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42685Du)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x42685Du));
    if (cpu->eax == 0u) goto label_000268BB;
    cpu->edx = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%d %d %d %d %d %d"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x2688Au), LIFT_CODE_TOKEN_RVA(0x26888u))) { return; }
    cpu->eax = *(uint32_t*)(cpu->esp + 0x58u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x5Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x60u);
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x64u);
    *(uint32_t*)(cpu->esi + 0x3Cu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x68u);
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x6Cu);
    cpu->esp += 0x20u;
    *(uint32_t*)(cpu->esi + 0x44u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x48u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x4Cu) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x34u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x34u)) | (uint64_t)(1u);
    label_000268BB:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"brightness");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4268C8u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4268C8u));
    if (cpu->eax == 0u) goto label_000268E6;
    cpu->eax = cpu->esi + 0x54u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x50u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%f %f"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x268DFu), LIFT_CODE_TOKEN_RVA(0x268DDu))) { return; }
    cpu->esp += 0x10u;
    *(uint32_t*)(cpu->esi + 0x34u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x34u)) | (uint64_t)(2u);
    label_000268E6:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"brightFreq");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4268F3u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4268F3u));
    if (cpu->eax == 0u) goto label_00026903;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x426900u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x426900u));
    *(uint8_t*)(cpu->esi + 0x58u) = cpu->eax & 0xFFu;
    label_00026903:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"attach");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x426910u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x426910u));
    if (cpu->eax == 0u) goto label_00026971;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x426922u)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x426922u));
    if (cpu->eax == 0u) goto label_00026971;
    lift_push32(cpu, (uintptr_t)"ATTACH_LEFTHAND"); lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::_stricmp);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x26934u), LIFT_CODE_TOKEN_RVA(0x26932u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00026941;
    *(uint8_t*)(cpu->esi + 0x60u) = 1u;
    goto label_00026971;
    label_00026941:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"ATTACH_RIGHTHAND"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x2694Du), LIFT_CODE_TOKEN_RVA(0x2694Bu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_0002695A;
    *(uint8_t*)(cpu->esi + 0x60u) = 2u;
    goto label_00026971;
    label_0002695A:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"ATTACH_BETWEENHANDS"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x26966u), LIFT_CODE_TOKEN_RVA(0x26964u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00026971;
    *(uint8_t*)(cpu->esi + 0x60u) = 3u;
    label_00026971:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"color_track");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x426985u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x426985u));
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->eax == 0u) goto label_000269A1;
    lift_push32(cpu, (uintptr_t)"light->color_track"); lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0x20u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42699Eu)); sfera_sub_00482CE0(cpu, LIFT_CODE_TOKEN_VA(0x42699Eu));
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    label_000269A1:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"alpha_track");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4269B5u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4269B5u));
    if (cpu->eax == 0u) goto label_000269CD;
    lift_push32(cpu, (uintptr_t)"light->alpha_track"); lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0x20u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4269CAu)); sfera_sub_00482B00(cpu, LIFT_CODE_TOKEN_VA(0x4269CAu));
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    label_000269CD:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"position_track");
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4269E1u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4269E1u));
    if (cpu->eax == 0u) goto label_000269F8;
    lift_push32(cpu, (uintptr_t)"light->position_track"); lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0x20u;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4269F6u)); sfera_sub_00482CE0(cpu, LIFT_CODE_TOKEN_VA(0x4269F6u));
    *(uint32_t*)(cpu->esi) = cpu->eax;
    label_000269F8:
    cpu->edx = 0xAE6u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    *(uint32_t*)(cpu->esi + 0x30u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x426A0Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x426A0Eu));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x426A18u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x426A18u));
    cpu->esp += 4u;
    cpu->eax = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x426A27u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x426A27u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esp += 0x44u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00426A50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x20u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x28u) = 0u;
    { uint64_t l=cpu->eax, r=7u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_000272B3;
    label_00026A74:
    cpu->edi = cpu->eax;
    cpu->edi = (int32_t)(cpu->edi) >> 1u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    if ((int32_t)cpu->eax <= (int32_t)7u) goto label_00027031;
    cpu->ecx = cpu->eax + 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    if ((int32_t)cpu->eax <= (int32_t)0x28u) goto label_00026F26;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edx &= 7u;
    { uint64_t l=cpu->eax, r=cpu->edx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = *(uint16_t*)(cpu->esi);
    cpu->eax = (int32_t)(cpu->eax) >> 3u;
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x9Cu);
    cpu->ecx = *(uint16_t*)(cpu->esi + (cpu->eax * 2u));
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx = *(uint32_t*)(cpu->ecx + cpu->ebp + 0x98u);
    cpu->edx += cpu->ebp;
    cpu->ecx += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->edx + 0x98u);
    cpu->edx &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=cpu->edx, r=cpu->ebx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026C0C;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->edx + 0x90u);
    cpu->ebx = *(uint32_t*)(cpu->ecx + 0x90u);
    { uint64_t l=cpu->edx, r=cpu->ebx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026AFA;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026C14;
    label_00026AFA:
    cpu->edx = cpu->eax + cpu->eax;
    cpu->edi = *(uint16_t*)(cpu->esi + (cpu->edx * 2u));
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x98u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx = *(uint32_t*)(cpu->edi + cpu->ebp + 0x98u);
    cpu->edi += cpu->ebp;
    cpu->edx &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=cpu->edx, r=cpu->ebx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026CBC;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x90u);
    if (cpu->ecx < *(uint32_t*)(cpu->edi + 0x90u)) goto label_00026CC4;
    label_00026B36:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x98u);
    cpu->ebx = *(uint32_t*)(cpu->edi + 0x98u);
    cpu->ecx &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=cpu->ecx, r=cpu->ebx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026CD1;
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x90u);
    cpu->edi = *(uint32_t*)(cpu->edi + 0x90u);
    { uint64_t l=cpu->ecx, r=cpu->edi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026B6A;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026CD9;
    label_00026B6A:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    label_00026B6E:
    cpu->ecx = cpu->eax + cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    label_00026B75:
    cpu->ecx = *(uint16_t*)(cpu->esi + (cpu->edi * 2u));
    cpu->edx = cpu->edi;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x9Cu);
    cpu->edx -= cpu->eax;
    cpu->ebx = cpu->eax + cpu->edi;
    cpu->eax = *(uint16_t*)(cpu->esi + (cpu->edx * 2u));
    cpu->edi = *(uint32_t*)(cpu->ecx + cpu->ebp + 0x98u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x9Cu);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->ebp + 0x98u);
    cpu->ecx += cpu->ebp;
    cpu->eax += cpu->ebp;
    cpu->edx &= 1u;
    cpu->edi &= 1u;
    { uint64_t l=cpu->edx, r=cpu->edi, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026CEA;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x90u);
    cpu->edi = *(uint32_t*)(cpu->ecx + 0x90u);
    { uint64_t l=cpu->edx, r=cpu->edi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026BCE;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026CF2;
    label_00026BCE:
    cpu->edi = *(uint16_t*)(cpu->esi + (cpu->ebx * 2u));
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x98u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx = *(uint32_t*)(cpu->edi + cpu->ebp + 0x98u);
    cpu->edi += cpu->ebp;
    cpu->edx &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=cpu->edx, r=cpu->ebx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026D69;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x90u);
    if (cpu->ecx < *(uint32_t*)(cpu->edi + 0x90u)) goto label_00026DA5;
    goto label_00026D6D;
    label_00026C0C:
    if ((int32_t)cpu->edx >= 0) goto label_00026AFA;
    label_00026C14:
    cpu->edx = cpu->eax + cpu->eax;
    cpu->ebx = *(uint16_t*)(cpu->esi + (cpu->edx * 2u));
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x98u);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->ebx + 0x98u);
    cpu->edx &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=cpu->edx, r=cpu->ebx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026C55;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x90u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x90u);
    { uint64_t l=cpu->ecx, r=cpu->edx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026C66;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026C59;
    goto label_00026C66;
    label_00026C55:
    if ((int32_t)cpu->edx >= 0) goto label_00026C62;
    label_00026C59:
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    goto label_00026B75;
    label_00026C62:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    label_00026C66:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x98u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x98u);
    cpu->ecx &= 1u;
    cpu->edx &= 1u;
    { uint64_t l=cpu->ecx, r=cpu->edx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026CA7;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x90u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x90u);
    { uint64_t l=cpu->ecx, r=cpu->edx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026CAF;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026B6E;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    goto label_00026B75;
    label_00026CA7:
    if ((int32_t)cpu->ecx < 0) goto label_00026B6E;
    label_00026CAF:
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    goto label_00026B75;
    label_00026CBC:
    if ((int32_t)cpu->edx <= 0) goto label_00026B36;
    label_00026CC4:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    goto label_00026B75;
    label_00026CD1:
    if ((int32_t)cpu->ecx >= 0) goto label_00026B6A;
    label_00026CD9:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    goto label_00026B75;
    label_00026CEA:
    if ((int32_t)cpu->edx >= 0) goto label_00026BCE;
    label_00026CF2:
    cpu->edi = *(uint16_t*)(cpu->esi + (cpu->ebx * 2u));
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x98u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx = *(uint32_t*)(cpu->edi + cpu->ebp + 0x98u);
    cpu->edi += cpu->ebp;
    cpu->edx &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=cpu->edx, r=cpu->ebx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026D29;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x90u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x90u);
    { uint64_t l=cpu->ecx, r=cpu->edx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026D2D;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026DA5;
    goto label_00026D2D;
    label_00026D29:
    if ((int32_t)cpu->edx < 0) goto label_00026DA5;
    label_00026D2D:
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x98u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x98u);
    cpu->ecx &= 1u;
    cpu->edx &= 1u;
    { uint64_t l=cpu->ecx, r=cpu->edx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026D5B;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x90u);
    cpu->edi = *(uint32_t*)(cpu->edi + 0x90u);
    { uint64_t l=cpu->eax, r=cpu->edi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026D55;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026D5F;
    label_00026D55:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    goto label_00026DA1;
    label_00026D5B:
    if ((int32_t)cpu->ecx >= 0) goto label_00026D55;
    label_00026D5F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    goto label_00026DA5;
    label_00026D69:
    if ((int32_t)cpu->edx > 0) goto label_00026DA5;
    label_00026D6D:
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x98u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x98u);
    cpu->ecx &= 1u;
    cpu->edx &= 1u;
    { uint64_t l=cpu->ecx, r=cpu->edx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026E45;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x90u);
    cpu->edi = *(uint32_t*)(cpu->edi + 0x90u);
    { uint64_t l=cpu->eax, r=cpu->edi, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026D9D;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026E4D;
    label_00026D9D:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    label_00026DA1:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    label_00026DA5:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = cpu->eax + cpu->eax;
    cpu->ecx = cpu->edx;
    cpu->ecx -= cpu->edi;
    cpu->edi = *(uint16_t*)(cpu->esi + (cpu->ecx * 2u));
    cpu->edx -= cpu->eax;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x9Cu);
    cpu->eax = *(uint16_t*)(cpu->esi + (cpu->edx * 2u));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx = *(uint32_t*)(cpu->eax + cpu->ebp + 0x98u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + cpu->ebp + 0x98u);
    cpu->eax += cpu->ebp;
    cpu->edi += cpu->ebp;
    cpu->ecx &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=cpu->ecx, r=cpu->ebx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026E5A;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x90u);
    cpu->ebx = *(uint32_t*)(cpu->eax + 0x90u);
    { uint64_t l=cpu->ecx, r=cpu->ebx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026DFC;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026E5E;
    label_00026DFC:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = *(uint16_t*)(cpu->esi + (cpu->ecx * 2u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x98u);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->ebx + 0x98u);
    cpu->ecx &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=cpu->ecx, r=cpu->ebx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026EDE;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x90u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    if (cpu->eax < *(uint32_t*)(cpu->ecx + 0x90u)) goto label_00026EE2;
    goto label_00026EEC;
    label_00026E45:
    if ((int32_t)cpu->ecx >= 0) goto label_00026D9D;
    label_00026E4D:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    goto label_00026DA5;
    label_00026E5A:
    if ((int32_t)cpu->ecx >= 0) goto label_00026DFC;
    label_00026E5E:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = *(uint16_t*)(cpu->esi + (cpu->ecx * 2u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x98u);
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->ebx + 0x98u);
    cpu->ecx &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=cpu->ecx, r=cpu->ebx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026EA0;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x90u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x90u);
    { uint64_t l=cpu->eax, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026EAE;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026EA4;
    goto label_00026EAE;
    label_00026EA0:
    if ((int32_t)cpu->ecx >= 0) goto label_00026EAA;
    label_00026EA4:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    goto label_00026F22;
    label_00026EAA:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    label_00026EAE:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x98u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x98u);
    cpu->eax &= 1u;
    cpu->edx &= 1u;
    { uint64_t l=cpu->eax, r=cpu->edx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026ED8;
    cpu->edi = *(uint32_t*)(cpu->edi + 0x90u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x90u);
    { uint64_t l=cpu->edi, r=cpu->eax, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026F1A;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026F22;
    goto label_00026F1A;
    label_00026ED8:
    if ((int32_t)cpu->eax < 0) goto label_00026F22;
    goto label_00026F1A;
    label_00026EDE:
    if ((int32_t)cpu->ecx <= 0) goto label_00026EE8;
    label_00026EE2:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    goto label_00026F22;
    label_00026EE8:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    label_00026EEC:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x98u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x98u);
    cpu->eax &= 1u;
    cpu->edx &= 1u;
    { uint64_t l=cpu->eax, r=cpu->edx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026F16;
    cpu->edi = *(uint32_t*)(cpu->edi + 0x90u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x90u);
    { uint64_t l=cpu->edi, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026F22;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026F1A;
    goto label_00026F22;
    label_00026F16:
    if ((int32_t)cpu->eax >= 0) goto label_00026F22;
    label_00026F1A:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    label_00026F22:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    label_00026F26:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = *(uint16_t*)(cpu->esi + (cpu->edx * 2u));
    cpu->eax = *(uint16_t*)(cpu->esi + (cpu->edi * 2u));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x9Cu);
    cpu->ecx = *(uint32_t*)(cpu->edx + cpu->ebp + 0x98u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx = *(uint32_t*)(cpu->eax + cpu->ebp + 0x98u);
    cpu->edx += cpu->ebp;
    cpu->eax += cpu->ebp;
    cpu->ecx &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=cpu->ecx, r=cpu->ebx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026FB2;
    cpu->edx = *(uint32_t*)(cpu->edx + 0x90u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x90u);
    { uint64_t l=cpu->edx, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026F70;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00026FB6;
    label_00026F70:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint16_t*)(cpu->esi + (cpu->edx * 2u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x98u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx = *(uint32_t*)(cpu->edx + cpu->ebp + 0x98u);
    cpu->edx += cpu->ebp;
    cpu->ecx &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=cpu->ecx, r=cpu->ebx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000270DA;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x90u);
    if (cpu->eax < *(uint32_t*)(cpu->edx + 0x90u)) goto label_00027031;
    goto label_000270E2;
    label_00026FB2:
    if ((int32_t)cpu->ecx >= 0) goto label_00026F70;
    label_00026FB6:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint16_t*)(cpu->esi + (cpu->edx * 2u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x98u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx = *(uint32_t*)(cpu->edx + cpu->ebp + 0x98u);
    cpu->edx += cpu->ebp;
    cpu->ecx &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=cpu->ecx, r=cpu->ebx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00026FF1;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x90u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x90u);
    { uint64_t l=cpu->eax, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00026FF5;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_00027031;
    goto label_00026FF5;
    label_00026FF1:
    if ((int32_t)cpu->ecx < 0) goto label_00027031;
    label_00026FF5:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x98u);
    cpu->edi = *(uint32_t*)(cpu->edx + 0x98u);
    cpu->eax &= 1u;
    cpu->edi &= 1u;
    { uint64_t l=cpu->eax, r=cpu->edi, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000270C9;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x90u);
    cpu->edx = *(uint32_t*)(cpu->edx + 0x90u);
    { uint64_t l=cpu->eax, r=cpu->edx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_000270D1;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000270D1;
    label_0002702D:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    label_00027031:
    cpu->eax = *(uint16_t*)(cpu->esi);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(cpu->esi + (cpu->edi * 2u)));
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint16_t*)(cpu->esi) = cpu->edx & 0xFFFFu;
    *(uint16_t*)(cpu->esi + (cpu->edi * 2u)) = cpu->eax & 0xFFFFu;
    cpu->edi = 1u;
    --cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    label_00027051:
    if ((int32_t)cpu->edi > (int32_t)cpu->ebx) goto label_0002719E;
    cpu->eax = *(uint16_t*)(cpu->esi);
    cpu->ecx = *(uint16_t*)(cpu->esi + (cpu->edi * 2u));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x9Cu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x9Cu);
    cpu->edx = *(uint32_t*)(cpu->ecx + cpu->ebp + 0x98u);
    cpu->ecx += cpu->ebp;
    cpu->eax += cpu->ebp;
    cpu->ebp = *(uint32_t*)(cpu->eax + 0x98u);
    cpu->edx &= 1u;
    cpu->ebp &= 1u;
    { uint64_t l=cpu->edx, r=cpu->ebp, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00027128;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x90u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x90u);
    { uint64_t l=cpu->ecx, r=cpu->eax, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0002712C;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000270C2;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint16_t*)(cpu->esi + (cpu->edi * 2u));
    cpu->ecx = *(uint16_t*)(cpu->esi + (cpu->edx * 2u));
    *(uint16_t*)(cpu->esi + (cpu->edx * 2u)) = cpu->eax & 0xFFFFu;
    ++cpu->edx;
    *(uint32_t*)(cpu->esp + 0x28u) = 1u;
    *(uint16_t*)(cpu->esi + (cpu->edi * 2u)) = cpu->ecx & 0xFFFFu;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    label_000270C2:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    ++cpu->edi;
    goto label_00027051;
    label_000270C9:
    if ((int32_t)cpu->eax < 0) goto label_0002702D;
    label_000270D1:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    goto label_00027031;
    label_000270DA:
    if ((int32_t)cpu->ecx > 0) goto label_00027031;
    label_000270E2:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x98u);
    cpu->edi = *(uint32_t*)(cpu->edx + 0x98u);
    cpu->eax &= 1u;
    cpu->edi &= 1u;
    { uint64_t l=cpu->eax, r=cpu->edi, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00027117;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x90u);
    cpu->edx = *(uint32_t*)(cpu->edx + 0x90u);
    { uint64_t l=cpu->eax, r=cpu->edx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0002702D;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0002711F;
    goto label_0002702D;
    label_00027117:
    if ((int32_t)cpu->eax >= 0) goto label_0002702D;
    label_0002711F:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    goto label_00027031;
    label_00027128:
    if ((int32_t)cpu->edx <= 0) goto label_000270C2;
    label_0002712C:
    if ((int32_t)cpu->edi > (int32_t)cpu->ebx) goto label_0002719A;
    label_00027130:
    cpu->eax = *(uint16_t*)(cpu->esi);
    cpu->ecx = *(uint16_t*)(cpu->esi + (cpu->ebx * 2u));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x9Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebp = *(uint32_t*)(cpu->eax + cpu->edx + 0x98u);
    cpu->eax += cpu->edx;
    cpu->ecx += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x98u);
    cpu->edx &= 1u;
    cpu->ebp &= 1u;
    { uint64_t l=cpu->edx, r=cpu->ebp, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000271BF;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x90u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x90u);
    { uint64_t l=cpu->ecx, r=cpu->eax, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00027195;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_000271C3;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = *(uint16_t*)(cpu->esi + (cpu->ebx * 2u));
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(cpu->esi + (cpu->ecx * 2u)));
    *(uint16_t*)(cpu->esi + (cpu->ebx * 2u)) = cpu->edx & 0xFFFFu;
    *(uint16_t*)(cpu->esi + (cpu->ecx * 2u)) = cpu->eax & 0xFFFFu;
    --cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x28u) = 1u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    label_00027195:
    --cpu->ebx;
    if ((int32_t)cpu->edi <= (int32_t)cpu->ebx) goto label_00027130;
    label_0002719A:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_0002719E:
    if (*(uint32_t*)(cpu->esp + 0x28u) == 0u) goto label_00027345;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = cpu->edi;
    cpu->edx -= cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    if ((int32_t)cpu->ecx >= (int32_t)cpu->edx) goto label_000271EA;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    goto label_000271F0;
    label_000271BF:
    if ((int32_t)cpu->edx >= 0) goto label_00027195;
    label_000271C3:
    if ((int32_t)cpu->edi > (int32_t)cpu->ebx) goto label_0002719A;
    cpu->eax = *(uint16_t*)(cpu->esi + (cpu->edi * 2u));
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)(cpu->esi + (cpu->ebx * 2u)));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint16_t*)(cpu->esi + (cpu->edi * 2u)) = cpu->ecx & 0xFFFFu;
    *(uint16_t*)(cpu->esi + (cpu->ebx * 2u)) = cpu->eax & 0xFFFFu;
    ++cpu->edi;
    *(uint32_t*)(cpu->esp + 0x28u) = 1u;
    --cpu->ebx;
    goto label_00027051;
    label_000271EA:
    cpu->ecx = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    label_000271F0:
    if ((int32_t)cpu->ecx <= 0) goto label_0002722C;
    cpu->edx = cpu->edi;
    cpu->edx -= cpu->ecx;
    cpu->eax = cpu->esi;
    cpu->ecx = cpu->esi + (cpu->edx * 2u);
    label_00027200:
    cpu->edx = *(uint16_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    cpu->edx = *(uint16_t*)(cpu->ecx);
    *(uint16_t*)(cpu->eax) = cpu->edx & 0xFFFFu;
    cpu->edx = *(uint16_t*)(cpu->esp + 0x2Cu);
    *(uint16_t*)(cpu->ecx) = cpu->edx & 0xFFFFu;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    --cpu->edx;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    if ((int32_t)cpu->edx > 0) goto label_00027200;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    label_0002722C:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->ecx -= *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax -= cpu->ebx;
    --cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    if ((int32_t)cpu->eax >= (int32_t)cpu->ecx) goto label_00027245;
    cpu->ecx = cpu->eax;
    label_00027245:
    if ((int32_t)cpu->ecx <= 0) goto label_00027274;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->eax -= cpu->ecx;
    cpu->edi = cpu->esi + (cpu->edi * 2u);
    cpu->eax = cpu->esi + (cpu->eax * 2u);
    label_00027255:
    cpu->ebx = *(uint16_t*)(cpu->edi);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(cpu->eax));
    *(uint16_t*)(cpu->edi) = cpu->edx & 0xFFFFu;
    *(uint16_t*)(cpu->eax) = cpu->ebx & 0xFFFFu;
    --cpu->ecx;
    cpu->edi += 2u;
    cpu->eax += 2u;
    if ((int32_t)cpu->ecx > 0) goto label_00027255;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    label_00027274:
    if ((int32_t)cpu->edx <= (int32_t)1u) goto label_0002728C;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427288u)); sfera_sub_00426A50(cpu, LIFT_CODE_TOKEN_VA(0x427288u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    label_0002728C:
    if ((int32_t)cpu->eax <= (int32_t)1u) goto label_000273C9;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->ecx -= cpu->eax;
    cpu->esi = cpu->esi + (cpu->ecx * 2u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = 0u;
    { uint64_t l=cpu->eax, r=7u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_00026A74;
    label_000272B3:
    cpu->edx = 1u;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edx;
    if ((int32_t)cpu->eax <= (int32_t)cpu->edx) goto label_000273C9;
    label_000272C4:
    if ((int32_t)cpu->edx <= 0) goto label_0002732E;
    label_000272D0:
    cpu->eax = *(uint16_t*)(cpu->esi + (cpu->edx * 2u));
    cpu->ecx = *(uint16_t*)(cpu->esi + (cpu->edx * 2u) + 0xFFFFFFFEu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx = *(uint32_t*)(cpu->eax + cpu->ebp + 0x98u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x9Cu);
    cpu->edi = *(uint32_t*)(cpu->ecx + cpu->ebp + 0x98u);
    cpu->edi &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=cpu->edi, r=cpu->ebx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002730F;
    cpu->ecx = *(uint32_t*)(cpu->ecx + cpu->ebp + 0x90u);
    if (cpu->ecx >= *(uint32_t*)(cpu->eax + cpu->ebp + 0x90u)) goto label_0002732A;
    goto label_00027313;
    label_0002730F:
    if ((int32_t)cpu->edi <= 0) goto label_0002732A;
    label_00027313:
    cpu->eax = *(uint16_t*)(cpu->esi + (cpu->edx * 2u));
    cpu->ecx = *(uint16_t*)(cpu->esi + (cpu->edx * 2u) + 0xFFFFFFFEu);
    *(uint16_t*)(cpu->esi + (cpu->edx * 2u)) = cpu->ecx & 0xFFFFu;
    *(uint16_t*)(cpu->esi + (cpu->edx * 2u) + 0xFFFFFFFEu) = cpu->eax & 0xFFFFu;
    --cpu->edx;
    if ((int32_t)cpu->edx > 0) goto label_000272D0;
    label_0002732A:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    label_0002732E:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    ++cpu->edx;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edx;
    if ((int32_t)cpu->edx < (int32_t)cpu->eax) goto label_000272C4;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00027345:
    cpu->edx = 1u;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edx;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x34u) <= (int32_t)cpu->edx) goto label_000273C9;
    label_00027358:
    if ((int32_t)cpu->edx <= 0) goto label_000273BE;
    label_00027360:
    cpu->eax = *(uint16_t*)(cpu->esi + (cpu->edx * 2u));
    cpu->ecx = *(uint16_t*)(cpu->esi + (cpu->edx * 2u) + 0xFFFFFFFEu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx = *(uint32_t*)(cpu->eax + cpu->ebp + 0x98u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x9Cu);
    cpu->edi = *(uint32_t*)(cpu->ecx + cpu->ebp + 0x98u);
    cpu->edi &= 1u;
    cpu->ebx &= 1u;
    { uint64_t l=cpu->edi, r=cpu->ebx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002739F;
    cpu->ecx = *(uint32_t*)(cpu->ecx + cpu->ebp + 0x90u);
    if (cpu->ecx >= *(uint32_t*)(cpu->eax + cpu->ebp + 0x90u)) goto label_000273BA;
    goto label_000273A3;
    label_0002739F:
    if ((int32_t)cpu->edi <= 0) goto label_000273BA;
    label_000273A3:
    cpu->eax = *(uint16_t*)(cpu->esi + (cpu->edx * 2u));
    cpu->ecx = *(uint16_t*)(cpu->esi + (cpu->edx * 2u) + 0xFFFFFFFEu);
    *(uint16_t*)(cpu->esi + (cpu->edx * 2u)) = cpu->ecx & 0xFFFFu;
    *(uint16_t*)(cpu->esi + (cpu->edx * 2u) + 0xFFFFFFFEu) = cpu->eax & 0xFFFFu;
    --cpu->edx;
    if ((int32_t)cpu->edx > 0) goto label_00027360;
    label_000273BA:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    label_000273BE:
    ++cpu->edx;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edx;
    if ((int32_t)cpu->edx < (int32_t)*(uint32_t*)(cpu->esp + 0x34u)) goto label_00027358;
    label_000273C9:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004273E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x28u;
    (void)0; /* source SEH registration eliminated */
    cpu->edx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42740Eu)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x42740Eu));
    cpu->ebx = cpu->eax;
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x1Cu;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42741Du)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x42741Du));
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x20u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42742Au)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x42742Au));
    if (*(uint32_t*)(cpu->esp + 0x18u) != 0x314D5353u) goto label_00027526;
    if (*(uint32_t*)(cpu->esp + 0x1Cu) != 1u) goto label_00027526;
    cpu->edi = 0u;
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x18u;
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427456u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x427456u));
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x24u;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427463u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x427463u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if ((int32_t)cpu->eax <= (int32_t)cpu->edi) goto label_00027526;
    cpu->ebp = 0u;
    if ((int32_t)cpu->eax <= (int32_t)cpu->edi) goto label_00027526;
    label_00027480:
    cpu->edx = 0x14Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42748Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42748Fu));
    lift_push32(cpu, 0x58u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427496u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x427496u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    if (cpu->eax == cpu->edi) goto label_000274B0;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4274ACu)); sfera_sub_00483490(cpu, LIFT_CODE_TOKEN_VA(0x4274ACu));
    cpu->esi = cpu->eax;
    goto label_000274B2;
    label_000274B0:
    cpu->esi = 0u;
    label_000274B2:
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x34u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4274C2u)); sfera_sub_004836A0(cpu, LIFT_CODE_TOKEN_VA(0x4274C2u));
    if (cpu->eax == 0u) goto label_000274F8;
    cpu->eax = g_sfera_effect_manager.particle_resource_head;
    if (cpu->eax != cpu->edi) goto label_000274DD;
    g_sfera_effect_manager.particle_resource_head = cpu->esi;
    *(uint32_t*)(cpu->esi + 0x54u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x50u) = cpu->edi;
    goto label_0002751B;
    label_000274DD:
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x54u);
    if (cpu->ecx == cpu->edi) goto label_000274ED;
    label_000274E4:
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x54u);
    if (cpu->ecx != cpu->edi) goto label_000274E4;
    label_000274ED:
    *(uint32_t*)(cpu->eax + 0x54u) = cpu->esi;
    *(uint32_t*)(cpu->esi + 0x50u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x54u) = cpu->edi;
    goto label_0002751B;
    label_000274F8:
    cpu->edx = 0x164u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427507u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x427507u));
    if (cpu->esi == cpu->edi) goto label_0002751B;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427512u)); sfera_sub_004834C0(cpu, LIFT_CODE_TOKEN_VA(0x427512u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427518u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x427518u));
    cpu->esp += 4u;
    label_0002751B:
    ++cpu->ebp;
    if ((int32_t)cpu->ebp < (int32_t)*(uint32_t*)(cpu->esp + 0x14u)) goto label_00027480;
    label_00027526:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42752Du)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x42752Du));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00427550(LiftCpu* cpu, uint32_t stop_address) {
    { uint64_t l=g_sfera_effect_manager.render_slots.capacity, r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00027576;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427568u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x427568u));
    cpu->eax = g_sfera_effect_manager.render_slots.data;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->eax = g_sfera_effect_manager.render_slot_count;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00027576:
    cpu->ecx = g_sfera_effect_manager.render_slots.data;
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    cpu->eax = g_sfera_effect_manager.render_slot_count;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00427590(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=*(uint32_t*)(cpu->esi + 4u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    std::construct_at(reinterpret_cast<IEffectManager*>(cpu->esi));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000275C0;
    if (*(uint8_t*)(cpu->esi + 0xCu) != 0u) goto label_000275C0;
    cpu->edx = 0x67Du;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4275B4u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4275B4u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4275BDu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4275BDu));
    cpu->esp += 4u;
    label_000275C0:
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_000275D0;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4275CDu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4275CDu));
    cpu->esp += 4u;
    label_000275D0:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004275E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x88u;
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x8Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax + 0x48u)));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x4Cu));
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ecx + 4u)));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x50u));
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ecx + 8u)));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx));
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax + 0x3Cu)));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x40u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ecx + 4u)));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x44u));
    cpu->eax = *(uint32_t*)(cpu->esp);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ecx + 8u)));
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->ecx = cpu->esp + 0xCu;
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    cpu->edx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427670u)); sfera_sub_004259C0(cpu, LIFT_CODE_TOKEN_VA(0x427670u));
    cpu->edx = 8u;
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42767Eu)); sfera_sub_0044C370(cpu, LIFT_CODE_TOKEN_VA(0x42767Eu));
    { uint64_t x=cpu->eax, v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->esp += 0x88u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004276A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->edi + 0xA0u);
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    if (cpu->esi == 0u) goto label_00027724;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x9Cu) >= (int32_t)0x10u) goto label_00027724;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xB4u);
    if (cpu->ecx == 0u) goto label_000276CB;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x276CBu)); sfera_sub_00496870(cpu, LIFT_CODE_TOKEN_RVA(0x276CBu));
    label_000276CB:
    if (*(uint32_t*)(cpu->edi + 0xECu) == 0u) goto label_00027710;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = 0u;
    if (*(uint32_t*)(cpu->edi + 0xBCu) <= cpu->ebp) goto label_0002770F;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    label_000276E2:
    cpu->esi = *(uint32_t*)(cpu->edi + 0xECu);
    cpu->ecx = *(uint32_t*)(cpu->esi + cpu->ebx + 0xCu);
    if (cpu->ecx == 0xFFFFFFFFu) goto label_000276F6;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x276F6u)); sfera_sub_004563A0(cpu, LIFT_CODE_TOKEN_RVA(0x276F6u));
    label_000276F6:
    *(uint32_t*)(cpu->esi + cpu->ebx + 0xCu) = 0xFFFFFFFFu;
    ++cpu->ebp;
    cpu->ebx += 0x64u;
    if (cpu->ebp < *(uint32_t*)(cpu->edi + 0xBCu)) goto label_000276E2;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = lift_pop32(cpu);
    label_0002770F:
    cpu->ebp = lift_pop32(cpu);
    label_00027710:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x9Cu);
    *(uint32_t*)(cpu->esi + (cpu->eax * 4u) + 0x5Cu) = cpu->edi;
    ++*(uint32_t*)(cpu->esi + 0x9Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00027724:
    cpu->edx = 0x725u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427733u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x427733u));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    reinterpret_cast<CScriptedEffect*>(cpu->edi)->destroyEffect(cpu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00427750(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (*(uint8_t*)(cpu->edi + 0xDu) != 0u) goto label_000277B9;
    { uint64_t l=*(uint8_t*)(cpu->esp + 8u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000277AF;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    if (*(uint32_t*)(cpu->edi + 0xBCu) <= cpu->ebx) goto label_0002779A;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = 0u;
    (void)cpu;
    label_00027770:
    cpu->esi = *(uint32_t*)(cpu->edi + 0xECu);
    cpu->ecx = *(uint32_t*)(cpu->esi + cpu->ebp + 0xCu);
    if (cpu->ecx == 0xFFFFFFFFu) goto label_00027784;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x27784u)); sfera_sub_004563A0(cpu, LIFT_CODE_TOKEN_RVA(0x27784u));
    label_00027784:
    *(uint32_t*)(cpu->esi + cpu->ebp + 0xCu) = 0xFFFFFFFFu;
    ++cpu->ebx;
    cpu->ebp += 0x64u;
    if (cpu->ebx < *(uint32_t*)(cpu->edi + 0xBCu)) goto label_00027770;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_0002779A:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0xB4u);
    cpu->ebx = lift_pop32(cpu);
    if (cpu->ecx == 0u) goto label_000277AA;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x277AAu)); sfera_sub_00496870(cpu, LIFT_CODE_TOKEN_RVA(0x277AAu));
    label_000277AA:
    { uint64_t l=*(uint8_t*)(cpu->esp + 8u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    label_000277AF:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    *(uint8_t*)(cpu->edi + 0xEu) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->edi + 0xDu) = 1u;
    label_000277B9:
    cpu->edi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004277C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x2Cu), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00027850;
    if (*(uint32_t*)(cpu->esi) == 0u) goto label_000277F8;
    cpu->edx = 0xA3Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4277E2u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4277E2u));
    cpu->edi = *(uint32_t*)(cpu->esi);
    if (cpu->edi == 0u) goto label_000277F8;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4277EFu)); sfera_sub_0042D100(cpu, LIFT_CODE_TOKEN_VA(0x4277EFu));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4277F5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4277F5u));
    cpu->esp += 4u;
    label_000277F8:
    if (*(uint32_t*)(cpu->esi + 4u) == 0u) goto label_00027824;
    cpu->edx = 0xA3Fu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42780Du)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42780Du));
    cpu->edi = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->edi == 0u) goto label_00027824;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42781Bu)); sfera_sub_0042D100(cpu, LIFT_CODE_TOKEN_VA(0x42781Bu));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427821u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x427821u));
    cpu->esp += 4u;
    label_00027824:
    if (*(uint32_t*)(cpu->esi + 8u) == 0u) goto label_00027850;
    cpu->edx = 0xA40u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427839u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x427839u));
    cpu->edi = *(uint32_t*)(cpu->esi + 8u);
    if (cpu->edi == 0u) goto label_00027850;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427847u)); sfera_sub_0042D100(cpu, LIFT_CODE_TOKEN_VA(0x427847u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42784Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42784Du));
    cpu->esp += 4u;
    label_00027850:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->edi |= 0xFFFFFFFFu;
    if (cpu->ecx == cpu->edi) goto label_0002785F;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2785Fu)); sfera_sub_004563A0(cpu, LIFT_CODE_TOKEN_RVA(0x2785Fu));
    label_0002785F:
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00427870(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    if (cpu->ecx == 0xFFFFFFFFu) goto label_00027887;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427880u)); sfera_sub_004563A0(cpu, LIFT_CODE_TOKEN_VA(0x427880u));
    *(uint32_t*)(cpu->esi + 0xCu) = 0xFFFFFFFFu;
    label_00027887:
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_x87_push(cpu, 0.0);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->esp -= 0x14u;
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0xCu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4278CAu)); sfera_sub_004562D0(cpu, LIFT_CODE_TOKEN_VA(0x4278CAu));
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004278E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x24u;
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x9Cu);
    if ((int32_t)cpu->eax <= 0) goto label_0002793B;
    --cpu->eax;
    *(uint32_t*)(cpu->ebp + 0x9Cu) = cpu->eax;
    cpu->ebp = *(uint32_t*)(cpu->ebp + (cpu->eax * 4u) + 0x5Cu);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427925u)); sfera_sub_004261C0(cpu, LIFT_CODE_TOKEN_VA(0x427925u));
    cpu->eax = cpu->ebp;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0002793B:
    cpu->edx = 0x803u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42794Au)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42794Au));
    lift_push32(cpu, 0xFCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427954u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x427954u));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_00027966;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427962u)); sfera_sub_00425FA0(cpu, LIFT_CODE_TOKEN_VA(0x427962u));
    cpu->ebx = cpu->eax;
    goto label_00027968;
    label_00027966:
    cpu->ebx = 0u;
    label_00027968:
    *(uint8_t*)(cpu->ebx + 0xCu) = 1u;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xA4u);
    *(uint32_t*)(cpu->ebx + 0xA4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xC0u);
    *(uint32_t*)(cpu->ebx + 0xC0u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xB8u);
    *(uint32_t*)(cpu->ebx + 0xB8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xC4u);
    *(uint32_t*)(cpu->ebx + 0xC4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xCCu);
    *(uint32_t*)(cpu->ebx + 0xCCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xC8u);
    *(uint32_t*)(cpu->ebx + 0xC8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 4u);
    *(uint32_t*)(cpu->ebx + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->ebx + 8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xBCu);
    *(uint32_t*)(cpu->ebx + 0xBCu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    *(uint32_t*)(cpu->ebx + 0x10u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x14u);
    *(uint32_t*)(cpu->ebx + 0x14u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xACu);
    *(uint32_t*)(cpu->ebx + 0xACu) = cpu->edx;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x1Cu));
    *(float*)(cpu->ebx + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edi |= 0xFFFFFFFFu;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x18u));
    *(float*)(cpu->ebx + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xD4u);
    *(uint32_t*)(cpu->ebx + 0xD4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xD8u);
    *(uint32_t*)(cpu->ebx + 0xD8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xDCu);
    *(uint32_t*)(cpu->ebx + 0xDCu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xE0u);
    *(uint32_t*)(cpu->ebx + 0xE0u) = cpu->eax;
    *(uint32_t*)(cpu->ebx + 0xA0u) = cpu->ebp;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp + 0x54u));
    *(uint8_t*)(cpu->ebx + 0x54u) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x3Cu);
    *(uint32_t*)(cpu->ebx + 0x3Cu) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x40u);
    *(uint32_t*)(cpu->ebx + 0x40u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x44u);
    *(uint32_t*)(cpu->ebx + 0x44u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x48u);
    *(uint32_t*)(cpu->ebx + 0x48u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x4Cu);
    *(uint32_t*)(cpu->ebx + 0x4Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x50u);
    *(uint32_t*)(cpu->ebx + 0x50u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xB0u);
    *(uint32_t*)(cpu->ebx + 0xB0u) = cpu->edx;
    if (*(uint32_t*)(cpu->ebp + 0xD4u) == cpu->edi) goto label_00027AC2;
    cpu->esi = native_function_address32(&::rand);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x27A6Fu), LIFT_CODE_TOKEN_RVA(0x27A6Du))) { return; }
    { uint64_t l=cpu->eax, r=0x80000001u, v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_00027A7B;
    --cpu->eax;
    cpu->eax |= 0xFFFFFFFEu;
    { uint64_t l=cpu->eax, v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    label_00027A7B:
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00027A87;
    *(uint32_t*)(cpu->ebx + 0xE4u) = 1u;
    label_00027A87:
    if (*(uint32_t*)(cpu->ebx + 0xE4u) != 0u) goto label_00027AA5;
    if (*(uint32_t*)(cpu->ebp + 0xD8u) <= 0u) goto label_00027ABA;
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x27A9Bu), LIFT_CODE_TOKEN_RVA(0x27A99u))) { return; }
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, *(uint32_t*)(cpu->ebp + 0xD8u), 32u, 0u);
    goto label_00027ABC;
    label_00027AA5:
    if (*(uint32_t*)(cpu->ebp + 0xE0u) <= 0u) goto label_00027ABA;
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x27AB0u), LIFT_CODE_TOKEN_RVA(0x27AAEu))) { return; }
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, *(uint32_t*)(cpu->ebp + 0xE0u), 32u, 0u);
    goto label_00027ABC;
    label_00027ABA:
    cpu->edx = 0u;
    label_00027ABC:
    *(uint32_t*)(cpu->ebx + 0xD0u) = cpu->edx;
    label_00027AC2:
    if (*(uint32_t*)(cpu->ebp + 0xB4u) == 0u) goto label_00027B1A;
    cpu->edx = 0x829u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427ADAu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x427ADAu));
    lift_push32(cpu, 0xC0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427AE4u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x427AE4u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0u;
    if (cpu->eax == 0u) goto label_00027B00;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427AFEu)); sfera_sub_00495B30(cpu, LIFT_CODE_TOKEN_VA(0x427AFEu));
    goto label_00027B02;
    label_00027B00:
    cpu->eax = 0u;
    label_00027B02:
    *(uint32_t*)(cpu->ebx + 0xB4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xB4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x27B1Au)); sfera_sub_004968C0(cpu, LIFT_CODE_TOKEN_RVA(0x27B1Au));
    label_00027B1A:
    if (*(uint32_t*)(cpu->ebp + 0xBCu) <= 0u) goto label_00027BE4;
    cpu->edx = 0x82Fu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427B36u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x427B36u));
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xBCu);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->esi;
    cpu->edx = 0x64u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    cpu->eax = 0u;
    { uint64_t l=cpu->ecx, r=4u, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->eax |= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427B60u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x427B60u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 1u;
    if (cpu->eax == 0u) goto label_00027B8D;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004277C0)); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00426710)); lift_push32(cpu, cpu->esi);
    cpu->edi = cpu->eax + 4u;
    lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427B8Bu)); sfera_sub_004EEBE9(cpu, LIFT_CODE_TOKEN_VA(0x427B8Bu));
    goto label_00027B8F;
    label_00027B8D:
    cpu->edi = 0u;
    label_00027B8F:
    *(uint32_t*)(cpu->ebx + 0xECu) = cpu->edi;
    { uint64_t l=*(uint32_t*)(cpu->ebp + 0xBCu), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_00027BE4;
    cpu->edx = 0u;
    label_00027BB0:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xECu);
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xECu);
    cpu->eax += cpu->edx;
    cpu->esi += cpu->edx;
    cpu->edi = cpu->eax;
    cpu->ecx = 0x19u;
    lift_movs32(cpu, 1u);
    *(uint32_t*)(cpu->eax + 0x2Cu) = 1u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->eax;
    cpu->edx += 0x64u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->eax < *(uint32_t*)(cpu->ebp + 0xBCu)) goto label_00027BB0;
    label_00027BE4:
    if (*(uint32_t*)(cpu->ebp + 0xB8u) <= 0u) goto label_00027CD4;
    cpu->edx = 0x83Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427C00u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x427C00u));
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xB8u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->esi;
    cpu->edx = 0x9Cu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    cpu->eax = 0u;
    { uint64_t l=cpu->ecx, r=4u, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->eax |= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427C2Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x427C2Au));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 2u;
    if (cpu->eax == 0u) goto label_00027C5A;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00483920)); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00483880)); lift_push32(cpu, cpu->esi);
    cpu->edi = cpu->eax + 4u;
    lift_push32(cpu, 0x9Cu); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427C58u)); sfera_sub_004EEBE9(cpu, LIFT_CODE_TOKEN_VA(0x427C58u));
    goto label_00027C5C;
    label_00027C5A:
    cpu->edi = 0u;
    label_00027C5C:
    *(uint32_t*)(cpu->ebx + 0xE8u) = cpu->edi;
    { uint64_t l=*(uint32_t*)(cpu->ebp + 0xB8u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_00027CD4;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    goto label_00027C94;
    label_00027C90:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    label_00027C94:
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xE8u);
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xE8u);
    cpu->eax += cpu->ecx;
    cpu->esi += cpu->ecx;
    cpu->edi = cpu->eax;
    cpu->ecx = 0x27u;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->eax + 0x34u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427CBBu)); sfera_sub_00483B00(cpu, LIFT_CODE_TOKEN_VA(0x427CBBu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(0x9Cu) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if (cpu->eax < *(uint32_t*)(cpu->ebp + 0xB8u)) goto label_00027C90;
    label_00027CD4:
    if (*(uint32_t*)(cpu->ebp + 0xC4u) <= 0u) goto label_00027E1F;
    cpu->edx = 0x84Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427CF0u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x427CF0u));
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xC4u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->esi;
    cpu->edx = 0x19Cu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    cpu->eax = 0u;
    { uint64_t l=cpu->ecx, r=4u, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->eax |= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427D1Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x427D1Au));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 3u;
    if (cpu->eax == 0u) goto label_00027D4A;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00483F50)); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00486390)); lift_push32(cpu, cpu->esi);
    cpu->edi = cpu->eax + 4u;
    lift_push32(cpu, 0x19Cu); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427D48u)); sfera_sub_004EEBE9(cpu, LIFT_CODE_TOKEN_VA(0x427D48u));
    goto label_00027D4C;
    label_00027D4A:
    cpu->edi = 0u;
    label_00027D4C:
    *(uint32_t*)(cpu->ebx + 0xF0u) = cpu->edi;
    { uint64_t l=*(uint32_t*)(cpu->ebp + 0xC4u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_00027E1F;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    goto label_00027D84;
    label_00027D80:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    label_00027D84:
    cpu->edi = *(uint32_t*)(cpu->ebx + 0xF0u);
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xF0u);
    cpu->edi += cpu->eax;
    cpu->esi += cpu->eax;
    cpu->ecx = 0x67u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    lift_movs32(cpu, 1u);
    cpu->edx = 0x858u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427DB2u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x427DB2u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x5Cu);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 0x50u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427DCFu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x427DCFu));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x5Cu);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = cpu->ecx + (cpu->ecx * 4u);
    cpu->ecx <<= 4u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x427DE9u));
    cpu->esp += 0x10u;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi + 0x198u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427E02u)); sfera_sub_00484440(cpu, LIFT_CODE_TOKEN_VA(0x427E02u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(0x19Cu) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if (cpu->eax < *(uint32_t*)(cpu->ebp + 0xC4u)) goto label_00027D80;
    label_00027E1F:
    if (*(uint32_t*)(cpu->ebp + 0xC8u) <= 0u) goto label_00027EED;
    if (*(uint32_t*)(cpu->ebp + 0xCCu) <= 0u) goto label_00027EED;
    cpu->edx = 0x864u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427E48u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x427E48u));
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xC8u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->esi;
    cpu->edx = 0x19Cu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    cpu->eax = 0u;
    { uint64_t l=cpu->ecx, r=4u, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->eax |= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427E72u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x427E72u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = 4u;
    if (cpu->eax == 0u) goto label_00027EA2;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00483F50)); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00486390)); lift_push32(cpu, cpu->esi);
    cpu->edi = cpu->eax + 4u;
    lift_push32(cpu, 0x19Cu); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427EA0u)); sfera_sub_004EEBE9(cpu, LIFT_CODE_TOKEN_VA(0x427EA0u));
    goto label_00027EA4;
    label_00027EA2:
    cpu->edi = 0u;
    label_00027EA4:
    cpu->edx = 0x865u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ebx + 0xF8u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427EC1u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x427EC1u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCCu);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 0x50u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427EDDu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x427EDDu));
    cpu->esp += 4u;
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->ebx + 0xF4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x27EEDu)); sfera_sub_00426440(cpu, LIFT_CODE_TOKEN_RVA(0x27EEDu));
    label_00027EED:
    cpu->eax = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00427F10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x124u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x138u;
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x148u);
    cpu->esi = cpu->ecx;
    cpu->edx = 0x920u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427F67u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x427F67u));
    lift_push32(cpu, 0x420u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427F71u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x427F71u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x140u) = cpu->ebp;
    if (cpu->eax == cpu->ebp) goto label_00027F8E;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427F8Cu)); sfera_sub_00493BF0(cpu, LIFT_CODE_TOKEN_VA(0x427F8Cu));
    cpu->ebp = cpu->eax;
    label_00027F8E:
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x144u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427FA1u)); sfera_sub_00494940(cpu, LIFT_CODE_TOKEN_VA(0x427FA1u));
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"effectmesh_def");
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x58u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427FB6u)); sfera_sub_00494030(cpu, LIFT_CODE_TOKEN_VA(0x427FB6u));
    cpu->edi = cpu->eax;
    if ((int32_t)cpu->edi <= 0) goto label_000280C5;
    cpu->edx = 0x92Cu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    *(uint32_t*)(cpu->esi + 0xB8u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427FD5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x427FD5u));
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->edi;
    cpu->edx = 0x9Cu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    cpu->eax = 0u;
    { uint64_t l=cpu->ecx, r=4u, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->eax |= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x427FF9u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x427FF9u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x140u) = 1u;
    if (cpu->eax == 0u) goto label_00028032;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00483920)); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00483880)); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->eax + 4u;
    lift_push32(cpu, 0x9Cu); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->eax) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42802Au)); sfera_sub_004EEBE9(cpu, LIFT_CODE_TOKEN_VA(0x42802Au));
    cpu->eax = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x28u);
    goto label_00028034;
    label_00028032:
    cpu->eax = 0u;
    label_00028034:
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x144u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0xE8u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42804Eu)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x42804Eu));
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"effectmesh_def");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42805Fu)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x42805Fu));
    if (cpu->eax == 0u) goto label_000280BE;
    cpu->edi = 0u;
    label_00028065:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xE8u);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    cpu->ecx += cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428079u)); sfera_sub_00485AF0(cpu, LIFT_CODE_TOKEN_VA(0x428079u));
    if (cpu->eax != 0u) goto label_00028093;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"CScriptedEffect::LoadScript(%s) -> Can't load effectmesh_def block");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428088u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x428088u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42808Eu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x42808Eu));
    cpu->esp += 0xCu;
    goto label_000280A3;
    label_00028093:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xE8u);
    cpu->ecx += cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4280A0u)); sfera_sub_00483F40(cpu, LIFT_CODE_TOKEN_VA(0x4280A0u));
    *(uint32_t*)(cpu->esi + 0x58u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x58u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    label_000280A3:
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"effectmesh_def");
    cpu->ecx = cpu->ebp;
    cpu->edi += 0x9Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4280BAu)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x4280BAu));
    if (cpu->eax != 0u) goto label_00028065;
    label_000280BE:
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x280C5u)); sfera_sub_004948B0(cpu, LIFT_CODE_TOKEN_RVA(0x280C5u));
    label_000280C5:
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"psystem_def");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4280D3u)); sfera_sub_00494030(cpu, LIFT_CODE_TOKEN_VA(0x4280D3u));
    cpu->edi = cpu->eax;
    if ((int32_t)cpu->edi <= 0) goto label_00028207;
    cpu->edx = 0x943u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    *(uint32_t*)(cpu->esi + 0xC4u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4280F2u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4280F2u));
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->edi;
    cpu->edx = 0x19Cu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    cpu->eax = 0u;
    { uint64_t l=cpu->ecx, r=4u, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->eax |= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428116u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x428116u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x140u) = 2u;
    if (cpu->eax == 0u) goto label_0002814F;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00483F50)); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00486390)); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->eax + 4u;
    lift_push32(cpu, 0x19Cu); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->eax) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428147u)); sfera_sub_004EEBE9(cpu, LIFT_CODE_TOKEN_VA(0x428147u));
    cpu->eax = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x28u);
    goto label_00028151;
    label_0002814F:
    cpu->eax = 0u;
    label_00028151:
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x144u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0xF0u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42816Bu)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x42816Bu));
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"psystem_def");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42817Cu)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x42817Cu));
    if (cpu->eax == 0u) goto label_00028200;
    cpu->edi = 0u;
    label_00028186:
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428192u)); sfera_sub_00494900(cpu, LIFT_CODE_TOKEN_VA(0x428192u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xF0u);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    cpu->ecx += cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4281A6u)); sfera_sub_00487D50(cpu, LIFT_CODE_TOKEN_VA(0x4281A6u));
    if (cpu->eax != 0u) goto label_000281C0;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"CScriptedEffect::LoadScript(%s) -> Can't load psystem_def block");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4281B5u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4281B5u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4281BBu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4281BBu));
    cpu->esp += 0xCu;
    goto label_000281D9;
    label_000281C0:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xF0u);
    { uint64_t l=*(uint32_t*)(cpu->edi + cpu->ecx + 0x18Cu), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = cpu->edi + cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000281D9;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x5Cu);
    *(uint32_t*)(cpu->esi + 0x58u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x58u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    label_000281D9:
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    cpu->edi += 0x19Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4281EBu)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4281EBu));
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"psystem_def");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4281FCu)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x4281FCu));
    if (cpu->eax != 0u) goto label_00028186;
    label_00028200:
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x28207u)); sfera_sub_004948B0(cpu, LIFT_CODE_TOKEN_RVA(0x28207u));
    label_00028207:
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0xC8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xCCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (*(uint32_t*)(cpu->esi + 0xC4u) <= cpu->eax) goto label_000282D2;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    label_00028230:
    cpu->edi = *(uint32_t*)(cpu->esi + 0xF0u);
    cpu->edi += *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x18Cu);
    if (cpu->eax == 0u) goto label_000282B5;
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    cpu->ebx = 0u;
    label_00028250:
    cpu->edx = *(uint32_t*)(cpu->edi + 0x188u);
    cpu->eax = *(uint32_t*)(cpu->edx + cpu->ebx);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428261u)); sfera_sub_004260F0(cpu, LIFT_CODE_TOKEN_VA(0x428261u));
    if (cpu->eax == 0xFFFFFFFFu) goto label_000282A1;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x188u);
    *(uint32_t*)(cpu->ecx + cpu->ebx + 0x10u) = cpu->eax;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x19Cu);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x188u);
    cpu->ecx = *(uint32_t*)(cpu->edx + cpu->ebx + 4u);
    *(uint32_t*)(cpu->esi + 0xC8u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0xC8u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xF0u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x188u);
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->edx + 0x5Cu);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->ecx + cpu->ebx + 4u));
    *(uint32_t*)(cpu->esi + 0xCCu) = (uint64_t)(*(uint32_t*)(cpu->esi + 0xCCu)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    label_000282A1:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    ++cpu->eax;
    cpu->ebx += 0x14u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    if (cpu->eax < *(uint32_t*)(cpu->edi + 0x18Cu)) goto label_00028250;
    label_000282B5:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x24u)) + (uint64_t)(0x19Cu) + (uint64_t)(0u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->eax < *(uint32_t*)(cpu->esi + 0xC4u)) goto label_00028230;
    label_000282D2:
    if (*(uint32_t*)(cpu->esi + 0xC8u) <= 0u) goto label_000283AF;
    if (*(uint32_t*)(cpu->esi + 0xCCu) <= 0u) goto label_000283AF;
    cpu->edx = 0x973u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4282FBu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4282FBu));
    cpu->edi = *(uint32_t*)(cpu->esi + 0xC8u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->edi;
    cpu->edx = 0x19Cu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    cpu->eax = 0u;
    { uint64_t l=cpu->ecx, r=4u, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->eax |= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428325u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x428325u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x140u) = 3u;
    if (cpu->eax == 0u) goto label_00028358;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00483F50)); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00486390)); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->eax + 4u;
    lift_push32(cpu, 0x19Cu); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->eax) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428356u)); sfera_sub_004EEBE9(cpu, LIFT_CODE_TOKEN_VA(0x428356u));
    goto label_0002835A;
    label_00028358:
    cpu->ebx = 0u;
    label_0002835A:
    cpu->edx = 0x974u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    *(uint32_t*)(cpu->esp + 0x140u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0xF8u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42837Au)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42837Au));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCCu);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 0x50u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428396u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x428396u));
    *(uint32_t*)(cpu->esi + 0xF4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCCu);
    *(uint32_t*)(cpu->esi + 0x58u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x58u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x283AFu)); sfera_sub_00426440(cpu, LIFT_CODE_TOKEN_RVA(0x283AFu));
    label_000283AF:
    lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"effect_def");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4283C4u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4283C4u));
    if (cpu->eax == 0u) goto label_000289BE;
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"effect_name");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4283DDu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4283DDu));
    if (cpu->eax == 0u) goto label_000283FF;
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4283EFu)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4283EFu));
    if (cpu->eax == 0u) goto label_000283FF;
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x283FFu)); sfera_sub_00425EB0(cpu, LIFT_CODE_TOKEN_RVA(0x283FFu));
    label_000283FF:
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"effect_number");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428410u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x428410u));
    if (cpu->eax == 0u) goto label_00028420;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42841Du)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x42841Du));
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    label_00028420:
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"effect_time");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428431u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x428431u));
    if (cpu->eax == 0u) goto label_00028444;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42843Eu)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x42843Eu));
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    label_00028444:
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"effect_timelimit");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428455u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x428455u));
    if (cpu->eax == 0u) goto label_00028465;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428462u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x428462u));
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    label_00028465:
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"updvisible_only");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428476u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x428476u));
    if (cpu->eax == 0u) goto label_000284AA;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428483u)); sfera_sub_00494710(cpu, LIFT_CODE_TOKEN_VA(0x428483u));
    *(uint32_t*)(cpu->esi + 0xACu) = cpu->eax;
    if (cpu->eax != 0u) goto label_000284AA;
    lift_push32(cpu, 0x98Du); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4284A1u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4284A1u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4284A7u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4284A7u));
    cpu->esp += 0x10u;
    label_000284AA:
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"boundbox");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4284BBu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4284BBu));
    if (cpu->eax == 0u) goto label_000284F2;
    cpu->ecx = cpu->esi + 0x44u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esi + 0x40u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x3Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x50u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esi + 0x4Cu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x48u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0x10u;
    lift_push32(cpu, (uintptr_t)"%f %f %f %f %f %f"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4284E0u));
    cpu->esp += 0x20u;
    if (cpu->eax != 6u) goto label_000284F2;
    *(uint8_t*)(cpu->esi + 0x54u) = 1u;
    label_000284F2:
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"daytime_work");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428503u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x428503u));
    if (cpu->eax == 0u) goto label_0002857E;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428510u)); sfera_sub_004942C0(cpu, LIFT_CODE_TOKEN_VA(0x428510u));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42851Du)); sfera_sub_004942C0(cpu, LIFT_CODE_TOKEN_VA(0x42851Du));
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[2u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 24.0);
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x44u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0002853E;
    cpu->fpu[2u] = (cpu->fpu[2u]) / (cpu->fpu[0u]);
    label_0002853E:
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    *(float*)(cpu->esi + 0x18u) = cpu->fpu[0u];
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[3u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    cpu->fpu[2u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x44u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00028562;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[0u] / cpu->fpu[2u]; lift_x87_pop(cpu);
    goto label_00028566;
    label_00028562:
    cpu->fpu[2u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    label_00028566:
    lift_x87_push(cpu, 1.0);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[0u] - cpu->fpu[2u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esi + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esi + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0002857E:
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"worktime");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42858Fu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x42858Fu));
    if (cpu->eax == 0u) goto label_000285B1;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42859Cu)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x42859Cu));
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0xD4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4285ABu)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4285ABu));
    *(uint32_t*)(cpu->esi + 0xD8u) = cpu->eax;
    label_000285B1:
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"sleeptime");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4285C2u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4285C2u));
    if (cpu->eax == 0u) goto label_000285E4;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4285CFu)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4285CFu));
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0xDCu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4285DEu)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4285DEu));
    *(uint32_t*)(cpu->esi + 0xE0u) = cpu->eax;
    label_000285E4:
    lift_push32(cpu, 1u);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"sound_def");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4285FCu)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4285FCu));
    if (cpu->eax == 0u) goto label_00028693;
    cpu->edx = 0x9B6u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428613u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x428613u));
    lift_push32(cpu, 0xC0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42861Du)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42861Du));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x140u) = 4u;
    if (cpu->eax == 0u) goto label_0002863C;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42863Au)); sfera_sub_00495B30(cpu, LIFT_CODE_TOKEN_VA(0x42863Au));
    goto label_0002863E;
    label_0002863C:
    cpu->eax = 0u;
    label_0002863E:
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x148u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0xB4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42865Cu)); sfera_sub_00495F40(cpu, LIFT_CODE_TOKEN_VA(0x42865Cu));
    if (cpu->eax != 0u) goto label_00028693;
    cpu->edx = 0x9BCu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42866Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42866Fu));
    cpu->edi = *(uint32_t*)(cpu->esi + 0xB4u);
    if (cpu->edi == 0u) goto label_00028689;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428680u)); sfera_sub_00496F00(cpu, LIFT_CODE_TOKEN_VA(0x428680u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428686u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x428686u));
    cpu->esp += 4u;
    label_00028689:
    *(uint32_t*)(cpu->esi + 0xB4u) = 0u;
    label_00028693:
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"light_def");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4286A4u)); sfera_sub_00494030(cpu, LIFT_CODE_TOKEN_VA(0x4286A4u));
    cpu->edi = cpu->eax;
    if ((int32_t)cpu->edi <= 0) goto label_0002879C;
    cpu->edx = 0x9C6u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    *(uint32_t*)(cpu->esi + 0xBCu) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4286C3u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4286C3u));
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->edi;
    cpu->edx = 0x64u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    cpu->eax = 0u;
    { uint64_t l=cpu->ecx, r=4u, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->eax |= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4286E7u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4286E7u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x140u) = 5u;
    if (cpu->eax == 0u) goto label_00028717;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004277C0)); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00426710)); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->eax + 4u;
    lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->eax) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428715u)); sfera_sub_004EEBE9(cpu, LIFT_CODE_TOKEN_VA(0x428715u));
    goto label_00028719;
    label_00028717:
    cpu->ebx = 0u;
    label_00028719:
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x144u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0xECu) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428736u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x428736u));
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"light_def");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428747u)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x428747u));
    if (cpu->eax == 0u) goto label_00028795;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edi = 0u;
    label_00028751:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xECu);
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->ecx += cpu->edi;
    lift_push32(cpu, cpu->ebx);
    cpu->edi += 0x64u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428768u)); sfera_sub_00426780(cpu, LIFT_CODE_TOKEN_VA(0x428768u));
    if (cpu->eax != 0u) goto label_00028780;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"CScriptedEffect::LoadScript(%s) -> Can't load light_def block");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428777u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x428777u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42877Du)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x42877Du));
    cpu->esp += 0xCu;
    label_00028780:
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"light_def");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428791u)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x428791u));
    if (cpu->eax != 0u) goto label_00028751;
    label_00028795:
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2879Cu)); sfera_sub_004948B0(cpu, LIFT_CODE_TOKEN_RVA(0x2879Cu));
    label_0002879C:
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"effftype");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4287ADu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4287ADu));
    if (cpu->eax == 0u) goto label_000287C0;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4287BAu)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4287BAu));
    *(uint32_t*)(cpu->esi + 0xB0u) = cpu->eax;
    label_000287C0:
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"subeffects_num");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4287D1u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4287D1u));
    if (cpu->eax == 0u) goto label_000287E4;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4287DEu)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4287DEu));
    *(uint32_t*)(cpu->esi + 0xC0u) = cpu->eax;
    label_000287E4:
    if (*(uint32_t*)(cpu->esi + 0xC0u) <= 0u) goto label_000289BE;
    cpu->edx = 0x9DEu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428800u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x428800u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xC0u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 4u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42881Cu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42881Cu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xC0u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 0xA4u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x428830u));
    cpu->esp += 0x10u;
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428844u)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x428844u));
    lift_push32(cpu, (uintptr_t)"subeffect");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428850u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x428850u));
    if (cpu->eax == 0u) goto label_000289B7;
    cpu->ebx = native_function_address32(&::_stricmp);
    label_00028860:
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428869u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x428869u));
    cpu->edi = cpu->eax;
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428879u)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x428879u));
    if (cpu->eax == 0u) goto label_0002890F;
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, (uintptr_t)"EFF_MESH"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x2888Du), LIFT_CODE_TOKEN_RVA(0x2888Bu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000288C9;
    cpu->edx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 2u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4288A2u)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4288A2u));
    if (cpu->eax == 0u) goto label_0002890F;
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4288B2u)); sfera_sub_00426080(cpu, LIFT_CODE_TOKEN_VA(0x4288B2u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA4u);
    *(uint16_t*)(cpu->ecx + (cpu->edi * 4u)) = cpu->eax & 0xFFFFu;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA4u);
    *(uint8_t*)(cpu->edx + (cpu->edi * 4u) + 2u) = 1u;
    goto label_0002890F;
    label_000288C9:
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, (uintptr_t)"EFF_PSYSTEM"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x288D5u), LIFT_CODE_TOKEN_RVA(0x288D3u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_0002890F;
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 2u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4288EAu)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4288EAu));
    if (cpu->eax == 0u) goto label_0002890F;
    cpu->edx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4288FAu)); sfera_sub_004260F0(cpu, LIFT_CODE_TOKEN_VA(0x4288FAu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA4u);
    *(uint16_t*)(cpu->ecx + (cpu->edi * 4u)) = cpu->eax & 0xFFFFu;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA4u);
    *(uint8_t*)(cpu->edx + (cpu->edi * 4u) + 2u) = 0u;
    label_0002890F:
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 3u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42891Du)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x42891Du));
    if (cpu->eax == 0u) goto label_000289A3;
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, (uintptr_t)"ATTACH_LEFTHAND"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x28931u), LIFT_CODE_TOKEN_RVA(0x2892Fu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00028945;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA4u);
    *(uint8_t*)(cpu->edx + (cpu->edi * 4u) + 3u) = 1u;
    goto label_000289A3;
    label_00028945:
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, (uintptr_t)"ATTACH_RIGHTHAND"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x28951u), LIFT_CODE_TOKEN_RVA(0x2894Fu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00028965;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA4u);
    *(uint8_t*)(cpu->ecx + (cpu->edi * 4u) + 3u) = 2u;
    goto label_000289A3;
    label_00028965:
    cpu->edx = cpu->esp + 0x34u;
    lift_push32(cpu, (uintptr_t)"ATTACH_BETWEENHANDS"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x28971u), LIFT_CODE_TOKEN_RVA(0x2896Fu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00028985;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA4u);
    *(uint8_t*)(cpu->eax + (cpu->edi * 4u) + 3u) = 3u;
    goto label_000289A3;
    label_00028985:
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, (uintptr_t)"ATTACH_SWORD"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x28991u), LIFT_CODE_TOKEN_RVA(0x2898Fu))) { return; }
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000289A3;
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA4u);
    *(uint8_t*)(cpu->edx + (cpu->edi * 4u) + 3u) = 4u;
    label_000289A3:
    lift_push32(cpu, (uintptr_t)"subeffect");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4289AFu)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x4289AFu));
    if (cpu->eax != 0u) goto label_00028860;
    label_000289B7:
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x289BEu)); sfera_sub_004945B0(cpu, LIFT_CODE_TOKEN_RVA(0x289BEu));
    label_000289BE:
    cpu->edx = 0xA10u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4289CDu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4289CDu));
    if (cpu->ebp == 0u) goto label_000289E1;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4289D8u)); sfera_sub_00493C00(cpu, LIFT_CODE_TOKEN_VA(0x4289D8u));
    lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4289DEu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4289DEu));
    cpu->esp += 4u;
    label_000289E1:
    cpu->eax = 1u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x138u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x130u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00428A10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi |= 0xFFFFFFFFu;
    if (*(uint32_t*)(cpu->esi + 0x30u) == 0u) goto label_00028A30;
    if (*(uint32_t*)(cpu->esi + 0xCu) != cpu->edi) goto label_00028A48;
    label_00028A30:
    cpu->eax = cpu->esi + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428A3Fu)); sfera_sub_00427870(cpu, LIFT_CODE_TOKEN_VA(0x428A3Fu));
    if (*(uint32_t*)(cpu->esi + 0xCu) == cpu->edi) goto label_00028BD7;
    label_00028A48:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esi + 0x30u) = 1u;
    if (cpu->ecx == 0u) goto label_00028A66;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    cpu->edx = cpu->esi + 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x28A66u)); sfera_sub_0042D180(cpu, LIFT_CODE_TOKEN_RVA(0x28A66u));
    label_00028A66:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ecx == 0u) goto label_00028A94;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428A7Fu)); sfera_sub_0042D180(cpu, LIFT_CODE_TOKEN_VA(0x428A7Fu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    *(float*)(cpu->esi + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    *(float*)(cpu->esi + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    *(float*)(cpu->esi + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00028A94:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    if (cpu->ecx == 0u) goto label_00028AB7;
    cpu->edx = g_sfera_effect_manager.particle_random_table;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->eax = cpu->esi + 0x28u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x28AB7u)); sfera_sub_0042D290(cpu, LIFT_CODE_TOKEN_RVA(0x28AB7u));
    label_00028AB7:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428AC0u)); sfera_sub_004600C0(cpu, LIFT_CODE_TOKEN_VA(0x428AC0u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x10u));
    cpu->ebp = native_function_address32(&::rand);
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax)));
    *(float*)(cpu->edi) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax + 4u)));
    *(float*)(cpu->edi + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x18u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax + 8u)));
    *(float*)(cpu->edi + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (((*(uint8_t*)(cpu->esi + 0x34u)) & (1u)) == 0u) goto label_00028B4E;
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x28AEDu), LIFT_CODE_TOKEN_RVA(0x28AEBu))) { return; }
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0518509447574615e-05);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x44u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) + ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x38u)))));
    *(float*)(cpu->esi + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x28B0Eu), LIFT_CODE_TOKEN_RVA(0x28B0Cu))) { return; }
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0518509447574615e-05);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x48u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) + ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x3Cu)))));
    *(float*)(cpu->esi + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x28B2Fu), LIFT_CODE_TOKEN_RVA(0x28B2Du))) { return; }
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0518509447574615e-05);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x4Cu)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) + ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x40u)))));
    *(float*)(cpu->esi + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00028B4E:
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x2Cu)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.00390625);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x1Cu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->edi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x20u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->edi + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x24u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->edi + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x28u)));
    *(float*)(cpu->edi + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (((*(uint8_t*)(cpu->esi + 0x34u)) & (2u)) == 0u) goto label_00028BD3;
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x58u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x5Cu);
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    if (cpu->edx != 0u) goto label_00028BD3;
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x28B99u), LIFT_CODE_TOKEN_RVA(0x28B97u))) { return; }
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0518509447574615e-05);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x54u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x50u)));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->edi + 0xCu)));
    *(float*)(cpu->edi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->edi + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->edi + 0x14u)));
    *(float*)(cpu->edi + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00028BD3:
    ++*(uint32_t*)(cpu->esi + 0x5Cu);
    cpu->ebp = lift_pop32(cpu);
    label_00028BD7:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00428BF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x390u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::FindFirstFileA);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Effects\\*.ssm");
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x28C1Au), LIFT_CODE_TOKEN_RVA(0x28C18u))) { return; }
    cpu->ebp = cpu->eax;
    if (cpu->ebp == 0xFFFFFFFFu) goto label_00028C9F;
    label_00028C21:
    if (((*(uint8_t*)(cpu->esp + 0x1Cu)) & (0x10u)) != 0u) goto label_00028C89;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    cpu->edx = 0x5C737463u;
    cpu->ecx = 0x65666645u;
    *(uint8_t*)(cpu->esp + 0x2A4u) = cpu->eax & 0xFFu;
    cpu->eax = cpu->esp + 0x48u;
    *(uint32_t*)(cpu->esp + 0x2A0u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x29Cu) = cpu->ecx;
    cpu->edx = cpu->eax;
    label_00028C54:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00028C54;
    cpu->edi = cpu->esp + 0x29Cu;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_00028C65:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    { uint64_t v= cpu->ecx & 0xFFu; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00028C65;
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 2u;
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->ecx = cpu->esp + 0x29Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x28C89u)); sfera_sub_004273E0(cpu, LIFT_CODE_TOKEN_RVA(0x28C89u));
    label_00028C89:
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_function_address32(&::FindNextFileA), LIFT_CODE_TOKEN_VA(0x428C8Fu));
    if (cpu->eax != 0u) goto label_00028C21;
    cpu->edi = native_function_address32(&::FindFirstFileA);
    label_00028C9F:
    cpu->ebx = native_function_address32(&::FindClose);
    lift_push32(cpu, cpu->ebp);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x28CA8u), LIFT_CODE_TOKEN_RVA(0x28CA6u))) { return; }
    cpu->edx = cpu->esp + 0x15Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"Effects\\*.sef");
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x28CB7u), LIFT_CODE_TOKEN_RVA(0x28CB5u))) { return; }
    cpu->esi = cpu->eax;
    cpu->ebp = 0u;
    if (cpu->esi == 0xFFFFFFFFu) goto label_00028CDE;
    label_00028CC0:
    if (((*(uint8_t*)(cpu->esp + 0x15Cu)) & (0x10u)) != 0u) goto label_00028CCB;
    ++cpu->ebp;
    label_00028CCB:
    cpu->eax = cpu->esp + 0x15Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindNextFileA), LIFT_CODE_TOKEN_VA(0x428CD4u));
    if (cpu->eax != 0u) goto label_00028CC0;
    label_00028CDE:
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x28CE1u), LIFT_CODE_TOKEN_RVA(0x28CDFu))) { return; }
    cpu->ecx = cpu->esp + 0x15Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Players\\*.sef");
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x28CF0u), LIFT_CODE_TOKEN_RVA(0x28CEEu))) { return; }
    cpu->esi = cpu->eax;
    cpu->edi = 0u;
    if (cpu->esi == 0xFFFFFFFFu) goto label_00028D1E;
    label_00028D00:
    if (((*(uint8_t*)(cpu->esp + 0x15Cu)) & (0x10u)) != 0u) goto label_00028D0B;
    ++cpu->edi;
    label_00028D0B:
    cpu->edx = cpu->esp + 0x15Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindNextFileA), LIFT_CODE_TOKEN_VA(0x428D14u));
    if (cpu->eax != 0u) goto label_00028D00;
    label_00028D1E:
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x28D21u), LIFT_CODE_TOKEN_RVA(0x28D1Fu))) { return; }
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Effects\\*.sef");
    lift_native_call(cpu, native_function_address32(&::FindFirstFileA), LIFT_CODE_TOKEN_VA(0x428D2Bu));
    cpu->edi += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u)))));
    cpu->ebx = cpu->eax;
    lift_x87_push(cpu, 1.0);
    cpu->fpu[1u] = cpu->fpu[0u] / cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (cpu->ebx == 0xFFFFFFFFu) goto label_00028E88;
    label_00028D54:
    if (((*(uint8_t*)(cpu->esp + 0x1Cu)) & (0x10u)) != 0u) goto label_00028E74;
    cpu->edx = 0x54Fu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428D6Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x428D6Eu));
    lift_push32(cpu, 0xFCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428D78u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x428D78u));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_00028D8A;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428D86u)); sfera_sub_00425FA0(cpu, LIFT_CODE_TOKEN_VA(0x428D86u));
    cpu->ebp = cpu->eax;
    goto label_00028D8C;
    label_00028D8A:
    cpu->ebp = 0u;
    label_00028D8C:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    cpu->edx = 0x5C737463u;
    cpu->ecx = 0x65666645u;
    *(uint8_t*)(cpu->esp + 0x2A4u) = cpu->eax & 0xFFu;
    cpu->eax = cpu->esp + 0x48u;
    *(uint32_t*)(cpu->esp + 0x2A0u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x29Cu) = cpu->ecx;
    cpu->edx = cpu->eax;
    label_00028DB8:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00028DB8;
    cpu->edi = cpu->esp + 0x29Cu;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_00028DD0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    { uint64_t v= cpu->ecx & 0xFFu; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00028DD0;
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 2u;
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->ecx = cpu->esp + 0x29Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428DF7u)); sfera_sub_00427F10(cpu, LIFT_CODE_TOKEN_VA(0x428DF7u));
    if (cpu->eax != 0u) goto label_00028E1C;
    cpu->edx = 0x558u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428E0Au)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x428E0Au));
    if (cpu->ebp == 0u) goto label_00028E52;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->destroyEffect(cpu);
    goto label_00028E52;
    label_00028E1C:
    cpu->eax = g_sfera_effect_manager.effect_definition_head;
    cpu->edx = 0u;
    if (cpu->eax != cpu->edx) goto label_00028E32;
    g_sfera_effect_manager.effect_definition_head = cpu->ebp;
    *(uint32_t*)(cpu->ebp + 0x24u) = cpu->edx;
    goto label_00028E4F;
    label_00028E32:
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x20u);
    if (cpu->ecx == cpu->edx) goto label_00028E49;
    label_00028E40:
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x20u);
    if (cpu->ecx != cpu->edx) goto label_00028E40;
    label_00028E49:
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ebp;
    *(uint32_t*)(cpu->ebp + 0x24u) = cpu->eax;
    label_00028E4F:
    *(uint32_t*)(cpu->ebp + 0x20u) = cpu->edx;
    label_00028E52:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (30.0);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428E6Du)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x428E6Du));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x28E74u)); sfera_sub_00461700(cpu, LIFT_CODE_TOKEN_RVA(0x28E74u));
    label_00028E74:
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::FindNextFileA), LIFT_CODE_TOKEN_VA(0x428E7Au));
    if (cpu->eax != 0u) goto label_00028D54;
    label_00028E88:
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::FindClose), LIFT_CODE_TOKEN_VA(0x428E89u));
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"Players\\*.sef");
    lift_native_call(cpu, native_function_address32(&::FindFirstFileA), LIFT_CODE_TOKEN_VA(0x428E99u));
    cpu->esi = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    if (cpu->esi == 0xFFFFFFFFu) goto label_00028FDC;
    label_00028EB0:
    if (((*(uint8_t*)(cpu->esp + 0x1Cu)) & (0x10u)) != 0u) goto label_00028FC8;
    cpu->edx = 0x56Fu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428ECAu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x428ECAu));
    lift_push32(cpu, 0xFCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428ED4u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x428ED4u));
    cpu->ebx = 0u;
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_00028EE8;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428EE4u)); sfera_sub_00425FA0(cpu, LIFT_CODE_TOKEN_VA(0x428EE4u));
    cpu->ebp = cpu->eax;
    goto label_00028EEA;
    label_00028EE8:
    cpu->ebp = 0u;
    label_00028EEA:
    cpu->eax = *(uint32_t*)((uintptr_t)"Players\\");
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"Players\\") + 8u));
    cpu->ecx = *(uint32_t*)(((uintptr_t)"Players\\") + 4u);
    *(uint32_t*)(cpu->esp + 0x29Cu) = cpu->eax;
    cpu->eax = cpu->esp + 0x48u;
    *(uint8_t*)(cpu->esp + 0x2A4u) = cpu->edx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x2A0u) = cpu->ecx;
    cpu->edx = cpu->eax;
    label_00028F16:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00028F16;
    cpu->edi = cpu->esp + 0x29Cu;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_00028F27:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    { uint64_t v= cpu->ecx & 0xFFu; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00028F27;
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 2u;
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    cpu->eax = cpu->esp + 0x29Cu;
    lift_movs8(cpu, 1u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428F4Eu)); sfera_sub_00427F10(cpu, LIFT_CODE_TOKEN_VA(0x428F4Eu));
    if (cpu->eax != 0u) goto label_00028F73;
    cpu->edx = 0x578u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428F61u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x428F61u));
    if (cpu->ebp == cpu->ebx) goto label_00028FA2;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->destroyEffect(cpu);
    goto label_00028FA2;
    label_00028F73:
    cpu->eax = g_sfera_effect_manager.effect_definition_head;
    if (cpu->eax != cpu->ebx) goto label_00028F87;
    g_sfera_effect_manager.effect_definition_head = cpu->ebp;
    *(uint32_t*)(cpu->ebp + 0x24u) = cpu->ebx;
    goto label_00028F9F;
    label_00028F87:
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x20u);
    if (cpu->ecx == cpu->ebx) goto label_00028F99;
    label_00028F90:
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x20u);
    if (cpu->ecx != cpu->ebx) goto label_00028F90;
    label_00028F99:
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->ebp;
    *(uint32_t*)(cpu->ebp + 0x24u) = cpu->eax;
    label_00028F9F:
    *(uint32_t*)(cpu->ebp + 0x20u) = cpu->ebx;
    label_00028FA2:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (30.0);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428FBDu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x428FBDu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x428FC4u)); sfera_sub_00461700(cpu, LIFT_CODE_TOKEN_VA(0x428FC4u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    label_00028FC8:
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindNextFileA), LIFT_CODE_TOKEN_VA(0x428FCEu));
    if (cpu->eax != 0u) goto label_00028EB0;
    label_00028FDC:
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindClose), LIFT_CODE_TOKEN_VA(0x428FDDu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x390u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00429000(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x14u;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    std::construct_at(reinterpret_cast<CScriptedEffect*>(cpu->esi));
    { uint64_t l=*(uint32_t*)(cpu->esi + 0xF4u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002905F;
    cpu->edx = 0x6F6u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429050u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x429050u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xF4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42905Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42905Cu));
    cpu->esp += 4u;
    label_0002905F:
    if (*(uint32_t*)(cpu->esi + 0xF8u) == 0u) goto label_000290D6;
    cpu->eax = 0u;
    if (*(uint32_t*)(cpu->esi + 0xC8u) <= cpu->eax) goto label_0002909D;
    cpu->ecx = 0u;
    label_00029080:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xF8u);
    *(uint32_t*)(cpu->ecx + cpu->edx + 4u) = 0u;
    ++cpu->eax;
    cpu->ecx += 0x19Cu;
    if (cpu->eax < *(uint32_t*)(cpu->esi + 0xC8u)) goto label_00029080;
    label_0002909D:
    cpu->edx = 0x6FBu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4290ACu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4290ACu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xF8u);
    if (cpu->eax == 0u) goto label_000290D6;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xFFFFFFFCu);
    cpu->edi = cpu->eax + 0xFFFFFFFCu;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00483F50)); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x19Cu); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4290CDu)); sfera_sub_004EEB86(cpu, LIFT_CODE_TOKEN_VA(0x4290CDu));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4290D3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4290D3u));
    cpu->esp += 4u;
    label_000290D6:
    if (*(uint32_t*)(cpu->esi + 0xE8u) == 0u) goto label_00029118;
    cpu->edx = 0x6FEu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4290EEu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4290EEu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xE8u);
    if (cpu->eax == 0u) goto label_00029118;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xFFFFFFFCu);
    cpu->edi = cpu->eax + 0xFFFFFFFCu;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00483920)); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x9Cu); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42910Fu)); sfera_sub_004EEB86(cpu, LIFT_CODE_TOKEN_VA(0x42910Fu));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429115u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x429115u));
    cpu->esp += 4u;
    label_00029118:
    if (*(uint32_t*)(cpu->esi + 0xF0u) == 0u) goto label_0002915A;
    cpu->edx = 0x6FFu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429130u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x429130u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xF0u);
    if (cpu->eax == 0u) goto label_0002915A;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xFFFFFFFCu);
    cpu->edi = cpu->eax + 0xFFFFFFFCu;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00483F50)); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x19Cu); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429151u)); sfera_sub_004EEB86(cpu, LIFT_CODE_TOKEN_VA(0x429151u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429157u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x429157u));
    cpu->esp += 4u;
    label_0002915A:
    if (*(uint32_t*)(cpu->esi + 0xECu) == 0u) goto label_00029199;
    cpu->edx = 0x700u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429172u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x429172u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xECu);
    if (cpu->eax == 0u) goto label_00029199;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xFFFFFFFCu);
    cpu->edi = cpu->eax + 0xFFFFFFFCu;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_004277C0)); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429190u)); sfera_sub_004EEB86(cpu, LIFT_CODE_TOKEN_VA(0x429190u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429196u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x429196u));
    cpu->esp += 4u;
    label_00029199:
    if (*(uint32_t*)(cpu->esi + 0xB4u) == 0u) goto label_000291CB;
    cpu->edx = 0x701u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4291B1u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4291B1u));
    cpu->edi = *(uint32_t*)(cpu->esi + 0xB4u);
    if (cpu->edi == 0u) goto label_000291CB;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4291C2u)); sfera_sub_00496F00(cpu, LIFT_CODE_TOKEN_VA(0x4291C2u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4291C8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4291C8u));
    cpu->esp += 4u;
    label_000291CB:
    cpu->ebp = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x9Cu) <= (int32_t)cpu->ebp) goto label_0002920A;
    cpu->edi = cpu->esi + 0x5Cu;
    label_000291E0:
    cpu->edx = 0x704u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4291EFu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4291EFu));
    cpu->ecx = *(uint32_t*)(cpu->edi);
    if (cpu->ecx == 0u) goto label_000291FE;
    lift_push32(cpu, 1u);
    reinterpret_cast<IEffectManager*>(cpu->ecx)->destroyEffect(cpu);
    label_000291FE:
    ++cpu->ebp;
    cpu->edi += 4u;
    if ((int32_t)cpu->ebp < (int32_t)*(uint32_t*)(cpu->esi + 0x9Cu)) goto label_000291E0;
    label_0002920A:
    if (*(uint8_t*)(cpu->esi + 0xCu) != 0u) goto label_00029237;
    if (*(uint32_t*)(cpu->esi + 0xA4u) == 0u) goto label_00029237;
    cpu->edx = 0x708u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429228u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x429228u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xA4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429234u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x429234u));
    cpu->esp += 4u;
    label_00029237:
    { uint64_t l=*(uint32_t*)(cpu->esi + 4u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    std::construct_at(reinterpret_cast<IEffectManager*>(cpu->esi));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002926C;
    if (*(uint8_t*)(cpu->esi + 0xCu) != 0u) goto label_0002926C;
    cpu->edx = 0x67Du;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429260u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x429260u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429269u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x429269u));
    cpu->esp += 4u;
    label_0002926C:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00429280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    if (*(uint32_t*)(cpu->ebx + 0xBCu) <= cpu->esi) goto label_000294C9;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    label_000292B0:
    cpu->esi += *(uint32_t*)(cpu->ebx + 0xECu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->eax = *(uint8_t*)(cpu->esi + 0x60u);
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->edi |= 0xFFFFFFFFu;
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x30u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebp = cpu->edx + (cpu->ecx * 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000292D2;
    if (*(uint32_t*)(cpu->esi + 0xCu) != cpu->edi) goto label_00029329;
    label_000292D2:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    if (cpu->ecx == cpu->edi) goto label_000292E1;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4292DEu)); sfera_sub_004563A0(cpu, LIFT_CODE_TOKEN_VA(0x4292DEu));
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->edi;
    label_000292E1:
    lift_x87_push(cpu, 0.0);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->esp -= 0x14u;
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x24u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x14u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42931Eu)); sfera_sub_004562D0(cpu, LIFT_CODE_TOKEN_VA(0x42931Eu));
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->eax;
    if (cpu->eax == cpu->edi) goto label_000294A9;
    label_00029329:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esi + 0x30u) = 1u;
    if (cpu->ecx == 0u) goto label_00029347;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    cpu->edx = cpu->esi + 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x29347u)); sfera_sub_0042D180(cpu, LIFT_CODE_TOKEN_RVA(0x29347u));
    label_00029347:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ecx == 0u) goto label_00029375;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429360u)); sfera_sub_0042D180(cpu, LIFT_CODE_TOKEN_VA(0x429360u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    *(float*)(cpu->esi + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    *(float*)(cpu->esi + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    *(float*)(cpu->esi + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_00029375:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    if (cpu->ecx == 0u) goto label_00029398;
    cpu->edx = g_sfera_effect_manager.particle_random_table;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->eax = cpu->esi + 0x28u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x29398u)); sfera_sub_0042D290(cpu, LIFT_CODE_TOKEN_RVA(0x29398u));
    label_00029398:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4293A0u)); sfera_sub_004600C0(cpu, LIFT_CODE_TOKEN_VA(0x4293A0u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ebp)));
    cpu->edi = cpu->eax;
    *(float*)(cpu->edi) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x14u)));
    *(float*)(cpu->edi + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 8u));
    cpu->ebp = native_function_address32(&::rand);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x18u)));
    *(float*)(cpu->edi + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (((*(uint8_t*)(cpu->esi + 0x34u)) & (1u)) == 0u) goto label_0002942B;
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x293CAu), LIFT_CODE_TOKEN_RVA(0x293C8u))) { return; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0518509447574615e-05);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x44u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) + ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x38u)))));
    *(float*)(cpu->esi + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x293EBu), LIFT_CODE_TOKEN_RVA(0x293E9u))) { return; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0518509447574615e-05);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x48u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) + ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x3Cu)))));
    *(float*)(cpu->esi + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x2940Cu), LIFT_CODE_TOKEN_RVA(0x2940Au))) { return; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0518509447574615e-05);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x4Cu)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) + ((double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x40u)))));
    *(float*)(cpu->esi + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0002942B:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x1Cu));
    lift_x87_push(cpu, 0.99609375);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->edi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x20u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->edi + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x24u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->edi + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x28u)));
    *(float*)(cpu->edi + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (((*(uint8_t*)(cpu->esi + 0x34u)) & (2u)) == 0u) goto label_000294A6;
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x58u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x5Cu);
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    if (cpu->edx != 0u) goto label_000294A6;
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x29468u), LIFT_CODE_TOKEN_RVA(0x29466u))) { return; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0518509447574615e-05);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x54u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x50u)));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0xCu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->edi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->edi + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->edi + 0x14u)));
    *(float*)(cpu->edi + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_000294A6:
    ++*(uint32_t*)(cpu->esi + 0x5Cu);
    label_000294A9:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->eax;
    cpu->esi += 0x64u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    if (cpu->eax < *(uint32_t*)(cpu->ebx + 0xBCu)) goto label_000292B0;
    label_000294C9:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004294E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0xA4u) == 0u) goto label_00029825;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x58u);
    cpu->eax += g_sfera_effect_manager.render_slot_count;
    if (cpu->eax < 0x2710u) goto label_0002950E;
    if (*(uint32_t*)(cpu->esp + 0x1Cu) != 0u) goto label_00029825;
    label_0002950E:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if (*(uint32_t*)(cpu->esi + 0xBCu) <= cpu->edi) goto label_00029553;
    cpu->ebp = 0u;
    label_00029521:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xECu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    cpu->eax = *(uint8_t*)(cpu->ecx + cpu->ebp + 0x60u);
    cpu->ecx += cpu->ebp;
    lift_push32(cpu, 0xFFu); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax + (cpu->eax * 2u);
    cpu->eax = cpu->ebx + (cpu->edx * 4u);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429547u)); sfera_sub_00428A10(cpu, LIFT_CODE_TOKEN_VA(0x429547u));
    ++cpu->edi;
    cpu->ebp += 0x64u;
    if (cpu->edi < *(uint32_t*)(cpu->esi + 0xBCu)) goto label_00029521;
    label_00029553:
    if (*(uint32_t*)(cpu->esi + 0xD4u) == 0xFFFFFFFFu) goto label_000296F3;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xD0u);
    if (cpu->eax != 0u) goto label_000296EC;
    if (*(uint32_t*)(cpu->esi + 0xE4u) != cpu->eax) goto label_00029641;
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x42957Au));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xD8u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0518509447574615e-05);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0xD8u)))));
    if ((int32_t)cpu->ecx >= 0) goto label_000295AC;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_000295AC:
    *(uint16_t*)(cpu->esp + 0x1Cu) = cpu->fpu_control;
    cpu->ebp = 0u;
    cpu->eax = *(uint16_t*)(cpu->esp + 0x1Cu);
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax |= 0xC00u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xE4u) = 1u;
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x10u);
    *(uint64_t*)(cpu->esp + 0x10u) = lift_x87_round(cpu, cpu->fpu[0u], 0u);
    lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx += *(uint32_t*)(cpu->esi + 0xD4u);
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esi + 0xD0u) = cpu->edx;
    if (*(uint32_t*)(cpu->esi + 0xC4u) <= cpu->ebp) goto label_000296F3;
    cpu->edi = 0u;
    label_000295F6:
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xF0u);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, 1u);
    cpu->ecx += cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42960Bu)); sfera_sub_00484420(cpu, LIFT_CODE_TOKEN_VA(0x42960Bu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xF0u);
    *(uint32_t*)(cpu->edi + cpu->eax + 0x190u) = 1u;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xF0u);
    *(uint32_t*)(cpu->edi + cpu->ecx + 0x194u) = 0u;
    ++cpu->ebp;
    cpu->edi += 0x19Cu;
    if (cpu->ebp < *(uint32_t*)(cpu->esi + 0xC4u)) goto label_000295F6;
    goto label_000296F3;
    label_00029641:
    cpu->edi = *(uint32_t*)(cpu->esi + 0xDCu);
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x429647u));
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu)))));
    cpu->edx = cpu->edi;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0518509447574615e-05);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu)))));
    if ((int32_t)cpu->edx >= 0) goto label_00029677;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_00029677:
    *(uint16_t*)(cpu->esp + 0x1Cu) = cpu->fpu_control;
    cpu->ebp = 0u;
    cpu->eax = *(uint16_t*)(cpu->esp + 0x1Cu);
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax |= 0xC00u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xE4u) = cpu->ebp;
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x10u);
    *(uint64_t*)(cpu->esp + 0x10u) = lift_x87_round(cpu, cpu->fpu[0u], 0u);
    lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax += cpu->edi;
    *(uint32_t*)(cpu->esi + 0xD0u) = cpu->eax;
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x1Cu);
    if (*(uint32_t*)(cpu->esi + 0xC4u) <= cpu->ebp) goto label_000296F3;
    cpu->edi = 0u;
    label_000296B5:
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xF0u);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, 0u);
    cpu->ecx += cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4296CAu)); sfera_sub_00484420(cpu, LIFT_CODE_TOKEN_VA(0x4296CAu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xF0u);
    *(uint32_t*)(cpu->edi + cpu->ecx + 0x194u) = 1u;
    ++cpu->ebp;
    cpu->edi += 0x19Cu;
    if (cpu->ebp < *(uint32_t*)(cpu->esi + 0xC4u)) goto label_000296B5;
    goto label_000296F3;
    label_000296EC:
    --cpu->eax;
    *(uint32_t*)(cpu->esi + 0xD0u) = cpu->eax;
    label_000296F3:
    if (*(uint32_t*)(cpu->esp + 0x28u) == 0u) goto label_000297BB;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    if (*(uint32_t*)(cpu->esi + 0xC0u) <= cpu->eax) goto label_00029822;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_00029720:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA4u);
    cpu->edi = (int16_t)(*(uint16_t*)(cpu->edx + (cpu->eax * 4u)));
    cpu->eax = cpu->edx + (cpu->eax * 4u);
    if (cpu->edi == 0xFFFFFFFFu) goto label_0002979C;
    { uint64_t l=*(uint8_t*)(cpu->eax + 2u), r=1u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    cpu->eax = *(uint8_t*)(cpu->eax + 3u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax + (cpu->eax * 2u);
    cpu->ecx = cpu->eax;
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = cpu->ebx + (cpu->edx * 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00029775;
    { int64_t v=(int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x9Cu); cpu->edi= v; uint32_t ov= (int64_t)(int32_t)v != v; cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->ecx <<= 6u;
    cpu->ecx += cpu->ebp;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xE8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx += cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429766u)); sfera_sub_00483C80(cpu, LIFT_CODE_TOKEN_VA(0x429766u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xE8u);
    cpu->ecx += cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429773u)); sfera_sub_004856D0(cpu, LIFT_CODE_TOKEN_VA(0x429773u));
    goto label_0002979C;
    label_00029775:
    { int64_t v=(int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x19Cu); cpu->edi= v; uint32_t ov= (int64_t)(int32_t)v != v; cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->ecx <<= 6u;
    cpu->ecx += cpu->ebp;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xF0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx += cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42978Fu)); sfera_sub_004866A0(cpu, LIFT_CODE_TOKEN_VA(0x42978Fu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xF0u);
    cpu->ecx += cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2979Cu)); sfera_sub_00487410(cpu, LIFT_CODE_TOKEN_RVA(0x2979Cu));
    label_0002979C:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    if (cpu->eax < *(uint32_t*)(cpu->esi + 0xC0u)) goto label_00029720;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
    label_000297BB:
    cpu->edi = 0u;
    if (*(uint32_t*)(cpu->esi + 0xC0u) <= cpu->edi) goto label_00029822;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_000297D0:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xA4u);
    cpu->eax = cpu->ecx + (cpu->edi * 4u);
    cpu->ecx = (int16_t)(*(uint16_t*)(cpu->eax));
    if (cpu->ecx == 0xFFFFFFFFu) goto label_00029819;
    if (*(uint8_t*)(cpu->eax + 2u) != 0u) goto label_00029819;
    cpu->eax = *(uint8_t*)(cpu->eax + 3u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx &= 0xFFFFu;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x19Cu);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    { uint64_t l=cpu->ecx, r=*(uint32_t*)(cpu->esi + 0xF0u), c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = cpu->eax;
    cpu->edx <<= 6u;
    cpu->edx += cpu->ebp;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->edx = cpu->ebx + (cpu->eax * 4u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x29819u)); sfera_sub_004866A0(cpu, LIFT_CODE_TOKEN_RVA(0x29819u));
    label_00029819:
    ++cpu->edi;
    if (cpu->edi < *(uint32_t*)(cpu->esi + 0xC0u)) goto label_000297D0;
    label_00029822:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00029825:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00429830(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->ebp <= 0x3FFFFFFFu) goto label_0002984B;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x429830u), "std::length_error");
    label_0002984B:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    { uint64_t l=cpu->eax, r=*(uint32_t*)(cpu->esi), c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    if (cpu->eax >= cpu->ebp) goto label_000298A5;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429862u)); sfera_sub_0049F1D0(cpu, LIFT_CODE_TOKEN_VA(0x429862u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ebx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi);
    { uint64_t l=cpu->ecx, r=cpu->eax, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = (int32_t)(cpu->ecx) >> 2u;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x429875u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edi = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi -= cpu->eax;
    { uint64_t l=cpu->esp, r=0xCu, v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    cpu->edi = (int32_t)(cpu->edi) >> 2u;
    if (cpu->eax == 0u) goto label_00029895;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429892u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x429892u));
    cpu->esp += 4u;
    label_00029895:
    cpu->eax = cpu->ebx + (cpu->edi * 4u);
    cpu->edx = cpu->ebx + (cpu->ebp * 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    label_000298A5:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004298B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    { uint64_t l=*(uint8_t*)(cpu->eax + 0x15u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (1u & 0xFFu);
    lift_push32(cpu, cpu->edi);
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->ecx & 0xFFu;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000298FD;
    cpu->edx = *(uint32_t*)(cpu->ebx + 0xCu);
    label_000298D1:
    { uint64_t l=*(uint8_t*)(cpu->esp + 0x1Cu), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000298E2;
    { uint64_t l=*(uint32_t*)(cpu->eax + 0xCu), r=cpu->edx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) == 0u)) ? 1u : 0u) & 0xFFu);
    goto label_000298E8;
    label_000298E2:
    { uint64_t l=cpu->edx, r=*(uint32_t*)(cpu->eax + 0xCu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) != 0u)) ? 1u : 0u) & 0xFFu);
    label_000298E8:
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->ecx & 0xFFu;
    if ((cpu->ecx & 0xFFu) == 0u) goto label_000298F4;
    cpu->eax = *(uint32_t*)(cpu->eax);
    goto label_000298F7;
    label_000298F4:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    label_000298F7:
    if (*(uint8_t*)(cpu->eax + 0x15u) == 0u) goto label_000298D1;
    label_000298FD:
    cpu->edi = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    if ((cpu->ecx & 0xFFu) == 0u) goto label_0002993A;
    cpu->eax = *(uint32_t*)(cpu->ebp + 4u);
    cpu->ecx = cpu->esp + 0x1Cu;
    if (cpu->esi != *(uint32_t*)(cpu->eax)) goto label_00029931;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42991Eu)); sfera_sub_004037A0(cpu, LIFT_CODE_TOKEN_VA(0x42991Eu));
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00029931:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429936u)); sfera_sub_004025A0(cpu, LIFT_CODE_TOKEN_VA(0x429936u));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_0002993A:
    cpu->eax = *(uint32_t*)(cpu->edi + 0xCu);
    lift_push32(cpu, cpu->ebx);
    if (cpu->eax >= *(uint32_t*)(cpu->ebx + 0xCu)) goto label_00029968;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429955u)); sfera_sub_004037A0(cpu, LIFT_CODE_TOKEN_VA(0x429955u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = 1u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00029968:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42996Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42996Du));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esp += 4u;
    *(uint32_t*)(cpu->eax) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 4u) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00429990(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_effect_manager.effect_listeners.sentinel;
    cpu->edx = *(uint32_t*)(cpu->esi);
    if (cpu->edx == cpu->esi) goto label_00029A02;
    label_000299A0:
    if (*(uint32_t*)(cpu->edx + 0x10u) == cpu->ecx) goto label_000299EE;
    if (*(uint8_t*)(cpu->edx + 0x15u) != 0u) goto label_000299E7;
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    if (*(uint8_t*)(cpu->eax + 0x15u) != 0u) goto label_000299CC;
    cpu->edx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (*(uint8_t*)(cpu->eax + 0x15u) != 0u) goto label_000299E7;
    label_000299C0:
    cpu->edx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edx);
    if (*(uint8_t*)(cpu->eax + 0x15u) == 0u) goto label_000299C0;
    goto label_000299E7;
    label_000299CC:
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    if (*(uint8_t*)(cpu->eax + 0x15u) != 0u) goto label_000299E5;
    label_000299D5:
    if (cpu->edx != *(uint32_t*)(cpu->eax + 8u)) goto label_000299E5;
    cpu->edx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    if (*(uint8_t*)(cpu->eax + 0x15u) == 0u) goto label_000299D5;
    label_000299E5:
    cpu->edx = cpu->eax;
    label_000299E7:
    if (cpu->edx != cpu->esi) goto label_000299A0;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000299EE:
    if (cpu->edx == cpu->esi) goto label_00029A02;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_effect_manager.effect_listeners;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x29A02u)); sfera_sub_00404510(cpu, LIFT_CODE_TOKEN_RVA(0x29A02u));
    label_00029A02:
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00429A10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429A18u)); sfera_sub_00429000(cpu, LIFT_CODE_TOKEN_VA(0x429A18u));
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_00029A28;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429A25u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x429A25u));
    cpu->esp += 4u;
    label_00029A28:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00429A30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->ebx = *(uint32_t*)(cpu->eax + 4u);
    { uint64_t l=*(uint8_t*)(cpu->ebx + 0x15u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->esi = cpu->ebx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00029A61;
    label_00029A43:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429A4Eu)); sfera_sub_004044D0(cpu, LIFT_CODE_TOKEN_VA(0x429A4Eu));
    cpu->esi = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429A56u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x429A56u));
    cpu->esp += 4u;
    { uint64_t l=*(uint8_t*)(cpu->esi + 0x15u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebx = cpu->esi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00029A43;
    label_00029A61:
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->eax) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 8u) = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00429A80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    { uint64_t l=*(uint8_t*)(cpu->eax + 0x15u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00029AAA;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->edi);
    label_00029A95:
    if (*(uint32_t*)(cpu->eax + 0xCu) >= cpu->esi) goto label_00029A9F;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    goto label_00029AA3;
    label_00029A9F:
    cpu->edx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_00029AA3:
    if (*(uint8_t*)(cpu->eax + 0x15u) == 0u) goto label_00029A95;
    cpu->esi = lift_pop32(cpu);
    label_00029AAA:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    if (cpu->edx == cpu->eax) goto label_00029ACD;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    if (cpu->ecx < *(uint32_t*)(cpu->edx + 0xCu)) goto label_00029ACD;
    cpu->eax = cpu->esp + 0x10u;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00029ACD:
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    cpu->eax = cpu->esp + 4u;
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00429AF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax == 0u) goto label_00029B02;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429AFFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x429AFFu));
    cpu->esp += 4u;
    label_00029B02:
    *(uint32_t*)(cpu->esi) = 0u;
    *(uint32_t*)(cpu->esi + 4u) = 0u;
    *(uint32_t*)(cpu->esi + 8u) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00429B20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->esi == 0u) goto label_00029C05;
    if (cpu->esi == 0xFFFFFFFFu) goto label_00029C05;
    if (g_sfera_effect_manager.active_effect_count == 0u) goto label_00029C05;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esi + 0x28u;
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_effect_manager.effect_listeners;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429B56u)); sfera_sub_00429A80(cpu, LIFT_CODE_TOKEN_VA(0x429B56u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    if (cpu->eax == g_sfera_effect_manager.effect_listeners.sentinel) goto label_00029B79;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    reinterpret_cast<BloodEffListener*>(cpu->ecx)->onEffectDetached(cpu);
    if ((cpu->eax & 0xFFu) == 0u) goto label_00029C04;
    label_00029B79:
    if (*(uint16_t*)(cpu->esi) != 0u) goto label_00029B89;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x29B89u)); sfera_sub_004560A0(cpu, LIFT_CODE_TOKEN_RVA(0x29B89u));
    label_00029B89:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1Cu);
    if (cpu->ecx == 0u) goto label_00029B9E;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->releaseEffect(cpu);
    *(uint32_t*)(cpu->esi + 0x1Cu) = 0u;
    label_00029B9E:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x20u);
    if (cpu->ecx == 0u) goto label_00029BC0;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429BAAu)); sfera_sub_00496FE0(cpu, LIFT_CODE_TOKEN_VA(0x429BAAu));
    *(uint32_t*)(cpu->esi + 0x20u) = 0u;
    if (g_sfera_effect_manager.active_resource_count == 0u) goto label_00029BC0;
    --g_sfera_effect_manager.active_resource_count;
    label_00029BC0:
    *(uint32_t*)(cpu->esi + 8u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x18u) = 0u;
    *(uint32_t*)(cpu->edi) = 0xFFFFFFFFu;
    if (g_sfera_effect_manager.active_effect_count == 0u) goto label_00029BE3;
    --g_sfera_effect_manager.active_effect_count;
    label_00029BE3:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x38u);
    if (cpu->ecx == 0u) goto label_00029BF0;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x29BF0u)); sfera_sub_00425C30(cpu, LIFT_CODE_TOKEN_RVA(0x29BF0u));
    label_00029BF0:
    cpu->eax = g_sfera_effect_items.free_count;
    cpu->ecx = g_sfera_effect_items.free_items;
    *(uint32_t*)(cpu->ecx + (cpu->eax * 4u)) = cpu->esi;
    ++g_sfera_effect_items.free_count;
    label_00029C04:
    cpu->edi = lift_pop32(cpu);
    label_00029C05:
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00429C10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x70u;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uintptr_t)&g_sfera_effect_manager.viewer_position.x;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429C29u)); sfera_sub_00455FD0(cpu, LIFT_CODE_TOKEN_VA(0x429C29u));
    cpu->eax = g_sfera_effect_manager.flare_transition;
    cpu->ebx = 0u;
    if (cpu->eax == cpu->ebx) goto label_00029C71;
    if (cpu->eax != 1u) goto label_00029C42;
    g_sfera_effect_manager.flare_alpha -= 0x23u;
    goto label_00029C49;
    label_00029C42:
    g_sfera_effect_manager.flare_alpha += 0x23u;
    label_00029C49:
    if ((int32_t)g_sfera_effect_manager.flare_alpha >= (int32_t)cpu->ebx) goto label_00029C59;
    g_sfera_effect_manager.flare_alpha = cpu->ebx;
    goto label_00029C6B;
    label_00029C59:
    cpu->eax = 0xFFu;
    if ((int32_t)g_sfera_effect_manager.flare_alpha <= (int32_t)cpu->eax) goto label_00029C71;
    g_sfera_effect_manager.flare_alpha = cpu->eax;
    label_00029C6B:
    g_sfera_effect_manager.flare_transition = cpu->ebx;
    label_00029C71:
    cpu->eax = g_sfera_effect_manager.render_cycle;
    ++cpu->eax;
    g_sfera_effect_manager.render_slot_count = cpu->ebx;
    *(uint8_t*)(cpu->esp + 7u) = cpu->ebx & 0xFFu;
    g_sfera_effect_manager.render_cycle = cpu->eax;
    if (cpu->eax != 0x20u) goto label_00029C9C;
    *(uint8_t*)(cpu->esp + 7u) = 1u;
    g_sfera_effect_manager.render_cycle = cpu->ebx;
    label_00029C9C:
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_view_spatial_runtime.basis[0].z));
    lift_push32(cpu, cpu->esi);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (10.0);
    cpu->esi = g_sfera_effect_manager.active_effects.first;
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (cpu->esi == cpu->ebx) goto label_00029E7C;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->ebp = 2u;
    label_00029CC2:
    cpu->edi = *(uint32_t*)(cpu->esi + 0x30u);
    if (*(uint8_t*)(cpu->esp + 0x13u) != (cpu->ebx & 0xFFu)) goto label_00029CDA;
    cpu->eax = 0xFFFFu;
    if (*(uint16_t*)(cpu->esi + 2u) != (cpu->eax & 0xFFFFu)) goto label_00029DA8;
    label_00029CDA:
    cpu->ecx = 0u;
    *(uint16_t*)(cpu->esi + 2u) = cpu->ecx & 0xFFFFu;
    if (*(uint16_t*)(cpu->esi) != (cpu->ebx & 0xFFFFu)) goto label_00029D29;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = cpu->esp + 0x40u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429CF1u)); sfera_sub_00455E40(cpu, LIFT_CODE_TOKEN_VA(0x429CF1u));
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_effect_manager.viewer_position.x));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x40u)));
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_effect_manager.viewer_position.y));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x44u)));
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_effect_manager.viewer_position.z));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x48u)));
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    goto label_00029D5C;
    label_00029D29:
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_effect_manager.viewer_position.x));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi + 0xCu)));
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_effect_manager.viewer_position.y));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi + 0x10u)));
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)&g_sfera_effect_manager.viewer_position.z));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi + 0x14u)));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_00029D5C:
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429D8Bu)); sfera_sub_004EE9EC(cpu, LIFT_CODE_TOKEN_VA(0x429D8Bu));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    *(float*)(cpu->esi + 0x2Cu) = cpu->fpu[0u];
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00029DA8;
    *(uint16_t*)(cpu->esi + 2u) = (uint64_t)(*(uint16_t*)(cpu->esi + 2u)) | (uint64_t)(1u);
    label_00029DA8:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    if (cpu->eax == cpu->ebx) goto label_00029E5A;
    cpu->edx = g_sfera_effect_manager.last_processed_generation;
    if (cpu->edx == g_sfera_effect_manager.generation) goto label_00029E15;
    if (((*(uint8_t*)(cpu->esi + 2u)) & (1u)) != 0u) goto label_00029E15;
    if (*(uint8_t*)(cpu->eax + 0x54u) == (cpu->ebx & 0xFFu)) goto label_00029E15;
    if (*(uint16_t*)(cpu->esi) != 1u) goto label_00029DE9;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x14u);
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->edx;
    goto label_00029DF5;
    label_00029DE9:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = cpu->esp + 0x4Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x29DF5u)); sfera_sub_00455E40(cpu, LIFT_CODE_TOKEN_RVA(0x29DF5u));
    label_00029DF5:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1Cu);
    cpu->eax = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429E02u)); sfera_sub_004275E0(cpu, LIFT_CODE_TOKEN_VA(0x429E02u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_00029E0C;
    *(uint16_t*)(cpu->esi + 2u) = (uint64_t)(*(uint16_t*)(cpu->esi + 2u)) | (uint64_t)((cpu->ebp & 0xFFFFu));
    goto label_00029E15;
    label_00029E0C:
    cpu->ecx = 0xFFFDu;
    *(uint16_t*)(cpu->esi + 2u) = (uint64_t)(*(uint16_t*)(cpu->esi + 2u)) & (uint64_t)((cpu->ecx & 0xFFFFu));
    label_00029E15:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    if (*(uint8_t*)(cpu->eax + 0xFu) == (cpu->ebx & 0xFFu)) goto label_00029E54;
    cpu->ecx = *(uint16_t*)(cpu->esi + 2u);
    if ((cpu->ecx & 0xFFFFu) == (cpu->ebx & 0xFFFFu)) goto label_00029E51;
    if ((((cpu->ecx & 0xFFu)) & (1u)) == 0u) goto label_00029E46;
    *(uint32_t*)(cpu->esi + 8u) = (uint64_t)(*(uint32_t*)(cpu->esi + 8u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    if (cpu->eax == 0xFFFFFFFFu) goto label_00029E70;
    if ((int32_t)cpu->ecx < (int32_t)cpu->eax) goto label_00029E70;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429E44u)); sfera_sub_00429B20(cpu, LIFT_CODE_TOKEN_VA(0x429E44u));
    goto label_00029E70;
    label_00029E46:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18u);
    if (cpu->eax == cpu->ebx) goto label_00029E70;
    cpu->edx = cpu->ecx;
    goto label_00029E65;
    label_00029E51:
    *(uint8_t*)(cpu->eax + 0xFu) = cpu->ebx & 0xFFu;
    label_00029E54:
    label_00029E5A:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18u);
    if (cpu->eax == cpu->ebx) goto label_00029E70;
    cpu->edx = *(uint16_t*)(cpu->esi + 2u);
    label_00029E65:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x2Cu));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x29E70u), LIFT_CODE_TOKEN_RVA(0x29E6Eu))) { return; }
    label_00029E70:
    cpu->esi = cpu->edi;
    if (cpu->edi != cpu->ebx) goto label_00029CC2;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_00029E7C:
    cpu->ecx = (uintptr_t)&g_sfera_server_wall;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429E86u)); sfera_sub_0048B5E0(cpu, LIFT_CODE_TOKEN_VA(0x429E86u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429E8Bu)); sfera_sub_0041A0B0(cpu, LIFT_CODE_TOKEN_VA(0x429E8Bu));
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x1284Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (0.004999999888241291);
    cpu->esi = lift_pop32(cpu);
    *(float*)(cpu->eax + 0x1284Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = g_sfera_effect_manager.render_slot_count;
    if (cpu->ecx <= cpu->ebx) goto label_00029F14;
    cpu->edx = g_sfera_effect_manager.render_sort_indices;
    cpu->eax = 0u;
    if (cpu->ecx <= cpu->ebx) goto label_00029EC3;
    label_00029EB4:
    *(uint16_t*)(cpu->edx + (cpu->eax * 2u)) = cpu->eax & 0xFFFFu;
    cpu->ecx = g_sfera_effect_manager.render_slot_count;
    ++cpu->eax;
    if (cpu->eax < cpu->ecx) goto label_00029EB4;
    label_00029EC3:
    *(uint8_t*)(cpu->esp + 7u) = cpu->ebx & 0xFFu;
    if ((int32_t)g_sfera_effect_manager.render_slots.capacity > (int32_t)cpu->ebx) goto label_00029EE7;
    cpu->edx = 0u;
    cpu->ecx = (uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429EDBu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x429EDBu));
    cpu->ecx = g_sfera_effect_manager.render_slot_count;
    cpu->edx = g_sfera_effect_manager.render_sort_indices;
    label_00029EE7:
    cpu->eax = cpu->esp + 7u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_effect_manager.render_slots.data;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429EF8u)); sfera_sub_00426A50(cpu, LIFT_CODE_TOKEN_VA(0x429EF8u));
    cpu->ecx = g_sfera_effect_manager.generation;
    g_sfera_effect_manager.last_processed_generation = cpu->ecx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x70u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00029F14:
    cpu->edx = g_sfera_effect_manager.generation;
    cpu->ebx = lift_pop32(cpu);
    g_sfera_effect_manager.last_processed_generation = cpu->edx;
    cpu->esp += 0x70u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00429F30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1A0u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    if (cpu->ebx == 0xFFFFFFFFu) goto label_0002A26B;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->ebx + 0x1Cu);
    if (cpu->ebp == 0u) goto label_00029F8A;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x28u);
    if (cpu->eax == 0x136u) goto label_00029F7A;
    if (cpu->eax == 0x137u) goto label_00029F7A;
    if (cpu->eax == 0x138u) goto label_00029F7A;
    *(uint32_t*)(cpu->ebx + 8u) = (uint64_t)(*(uint32_t*)(cpu->ebx + 8u)) + (uint64_t)(2u) + (uint64_t)(0u);
    goto label_00029F7D;
    label_00029F7A:
    ++*(uint32_t*)(cpu->ebx + 8u);
    label_00029F7D:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x14u);
    if (cpu->eax == 0xFFFFFFFFu) goto label_00029F94;
    if ((int32_t)*(uint32_t*)(cpu->ebx + 8u) < (int32_t)cpu->eax) goto label_00029F94;
    label_00029F8A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429F8Fu)); sfera_sub_00429B20(cpu, LIFT_CODE_TOKEN_VA(0x429F8Fu));
    goto label_0002A26A;
    label_00029F94:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x38u);
    if (cpu->ecx == 0u) goto label_00029FAD;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    if (cpu->eax != *(uint32_t*)(cpu->ecx + 4u)) goto label_00029FAD;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    reinterpret_cast<BloodEffListener*>(cpu->ecx)->onEffectChanged(cpu);
    label_00029FAD:
    if (*(uint32_t*)(cpu->ebx + 0x28u) != 0x136u) goto label_00029FCA;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x38u);
    if (cpu->ecx == 0u) goto label_00029FCA;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    reinterpret_cast<BloodEffListener*>(cpu->ecx)->onEffectChanged(cpu);
    label_00029FCA:
    { uint64_t l=*(uint16_t*)(cpu->ebx), r=1u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,16u); }
    lift_push32(cpu, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002A014;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x14u);
    lift_push32(cpu, 0x40u);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    cpu->eax = cpu->esp + 0x6Cu;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x429FEFu));
    lift_x87_push(cpu, 1.0);
    *(float*)(cpu->esp + 0xB0u) = cpu->fpu[0u];
    cpu->esp += 0xCu;
    *(float*)(cpu->esp + 0x90u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x7Cu) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x68u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_0002A11F;
    label_0002A014:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->esp + 0x30u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A021u)); sfera_sub_00455E40(cpu, LIFT_CODE_TOKEN_VA(0x42A021u));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = cpu->esp + 0x3Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A02Du)); sfera_sub_0045F760(cpu, LIFT_CODE_TOKEN_VA(0x42A02Du));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = cpu->esp + 0x48u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A039u)); sfera_sub_0045F920(cpu, LIFT_CODE_TOKEN_VA(0x42A039u));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = cpu->esp + 0x60u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A045u)); sfera_sub_0045FAE0(cpu, LIFT_CODE_TOKEN_VA(0x42A045u));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = cpu->esp + 0x6Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A051u)); sfera_sub_00455F00(cpu, LIFT_CODE_TOKEN_VA(0x42A051u));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = cpu->esp + 0xACu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A060u)); sfera_sub_0045FCA0(cpu, LIFT_CODE_TOKEN_VA(0x42A060u));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = cpu->esp + 0xECu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A06Fu)); sfera_sub_0045FE00(cpu, LIFT_CODE_TOKEN_VA(0x42A06Fu));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = cpu->esp + 0x16Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A07Eu)); sfera_sub_0045FF60(cpu, LIFT_CODE_TOKEN_VA(0x42A07Eu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x48u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    cpu->esi = cpu->esp + 0x6Cu;
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->edi = cpu->esp + 0x12Cu;
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x4Cu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x50u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_x87_push(cpu, 0.5);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ecx;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x28u)));
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x2Cu)));
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    label_0002A11F:
    lift_native_call(cpu, native_function_address32(&SI_GetInterface), LIFT_CODE_TOKEN_VA(0x42A11Fu));
    if (cpu->eax == 0u) goto label_0002A143;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1B0u));
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 0x30u;
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->updateEffect(cpu);
    label_0002A143:
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x1Cu), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    { uint64_t l=*(uint8_t*)(cpu->ebp + 0xFu), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    *(uint8_t*)(cpu->esp + 0xFu) = cpu->eax & 0xFFu;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002A18B;
    cpu->eax = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->activateEffect(cpu);
    if (cpu->eax != 0u) goto label_0002A18B;
    { uint64_t l=*(uint8_t*)(cpu->ebp + 0xDu), r=(cpu->eax & 0xFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002A182;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax >>= 1u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) & (uint64_t)(1u))) & 0xFFu);
    cpu->eax = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->deactivateEffect(cpu);
    label_0002A182:
    *(uint8_t*)(cpu->ebp + 0xFu) = 1u;
    goto label_0002A269;
    label_0002A18B:
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x18u));
    lift_x87_push(cpu, (double)-1.0f);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x44u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0002A1D3;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x18u));
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x1Cu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    lift_x87_push(cpu, (double)g_sfera_graphics_runtime.environment_factor);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x18u));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0002A1CC;
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0002A212;
    label_0002A1BE:
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x1Cu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0002A1D3;
    goto label_0002A214;
    label_0002A1CC:
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0002A1BE;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0002A1D3:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    if ((int32_t)cpu->eax < (int32_t)cpu->ecx) goto label_0002A1E3;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    *(uint32_t*)(cpu->ebx + 8u) = cpu->edx;
    label_0002A1E3:
    if (((*(uint8_t*)(cpu->esp + 0x1Cu)) & (2u)) == 0u) goto label_0002A228;
    if (*(uint8_t*)(cpu->ebp + 0xEu) == 0u) goto label_0002A1FA;
    cpu->ecx = cpu->ebp;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->renderEffect(cpu);
    label_0002A1FA:
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->ebx + 8u)))));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x30u;
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->queryEffectState(cpu);
    goto label_0002A269;
    label_0002A212:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0002A214:
    if (*(uint8_t*)(cpu->ebp + 0xDu) != 0u) goto label_0002A269;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->deactivateEffect(cpu);
    goto label_0002A269;
    label_0002A228:
    if (*(uint8_t*)(cpu->ebp + 0xDu) == 0u) goto label_0002A238;
    cpu->ecx = cpu->ebp;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->renderEffect(cpu);
    label_0002A238:
    cpu->edx = *(uint8_t*)(cpu->esp + 0xFu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->ebx + 8u)))));
    cpu->ecx = cpu->esp + 0x68u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = 0u;
    { uint64_t l=*(uint16_t*)(cpu->ebx), r=1u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,16u); }
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = cpu->esp + 0x38u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = (cpu->ecx * 4u) + 1u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->initializeEffect(cpu);
    label_0002A269:
    cpu->esi = lift_pop32(cpu);
    label_0002A26A:
    cpu->ebp = lift_pop32(cpu);
    label_0002A26B:
    cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x1A0u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042A290(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    if (*(uint32_t*)(cpu->esi + 0x10u) == cpu->edi) goto label_0002A2B8;
    cpu->edx = cpu->edi + 0x48u;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ItemArray.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A2A9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42A2A9u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A2B2u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42A2B2u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    label_0002A2B8:
    cpu->ebx = *(uint32_t*)(cpu->esi + 4u);
    { uint64_t l=cpu->ebx, r=*(uint32_t*)(cpu->esi), c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebx = v; }
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->edi;
    cpu->ebx = (int32_t)(cpu->ebx) >> 2u;
    if ((int32_t)cpu->ebx <= (int32_t)cpu->edi) goto label_0002A2F2;
    label_0002A2D0:
    cpu->edx = 0x4Fu;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ItemArray.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A2DFu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42A2DFu));
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->edi * 4u));
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A2EAu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42A2EAu));
    ++cpu->edi;
    cpu->esp += 4u;
    if ((int32_t)cpu->edi < (int32_t)cpu->ebx) goto label_0002A2D0;
    label_0002A2F2:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = *(uint32_t*)(cpu->esi);
    if (cpu->edi == cpu->ecx) goto label_0002A31A;
    cpu->eax = cpu->ecx;
    { uint64_t l=cpu->eax, r=cpu->ecx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    cpu->ebx = cpu->eax * 4u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x42A30Cu));
    cpu->esp += 0xCu;
    cpu->ebx += cpu->edi;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebx;
    label_0002A31A:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042A320(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x18u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A32Du)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42A32Du));
    cpu->edx = 0u;
    cpu->esp += 4u;
    if (cpu->eax == cpu->edx) goto label_0002A367;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->eax + 0xCu;
    *(uint16_t*)(cpu->eax + 0x14u) = cpu->edx & 0xFFFFu;
    if (cpu->ecx == cpu->edx) goto label_0002A360;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esi = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    label_0002A360:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0002A367:
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 8u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A391u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x42A391u));
    lift_trap(cpu, 0x42A391u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0042A3A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if ((uint32_t)(g_sfera_effect_manager.initialized) == cpu->edi) goto label_0002A47E;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A3B5u)); sfera_sub_0041AE00(cpu, LIFT_CODE_TOKEN_VA(0x42A3B5u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A3BAu)); sfera_sub_0047FBA0(cpu, LIFT_CODE_TOKEN_VA(0x42A3BAu));
    cpu->esi = g_sfera_effect_manager.active_effects.first;
    if (cpu->esi == cpu->edi) goto label_0002A3EB;
    label_0002A3C4:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1Cu);
    if (cpu->ecx == cpu->edi) goto label_0002A3D5;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->releaseEffect(cpu);
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->edi;
    label_0002A3D5:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x20u);
    if (cpu->ecx == cpu->edi) goto label_0002A3E4;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A3E1u)); sfera_sub_00496FE0(cpu, LIFT_CODE_TOKEN_VA(0x42A3E1u));
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->edi;
    label_0002A3E4:
    cpu->esi = *(uint32_t*)(cpu->esi + 0x30u);
    if (cpu->esi != cpu->edi) goto label_0002A3C4;
    label_0002A3EB:
    cpu->ecx = (uintptr_t)&g_sfera_effect_items;
    g_sfera_effect_manager.active_effects.first = cpu->edi;
    g_sfera_effect_manager.active_effects.last = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A401u)); sfera_sub_0042A290(cpu, LIFT_CODE_TOKEN_VA(0x42A401u));
    g_sfera_effect_manager.active_effect_count = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A40Cu)); sfera_sub_00425D80(cpu, LIFT_CODE_TOKEN_VA(0x42A40Cu));
    g_sfera_effect_manager.initialized = cpu->edi;
    cpu->esi = lift_pop32(cpu);
    if (g_sfera_effect_manager.effect_listeners.size <= cpu->edi) goto label_0002A425;
    cpu->ecx = (uintptr_t)&g_sfera_effect_manager.effect_listeners;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2A425u)); sfera_sub_00429A30(cpu, LIFT_CODE_TOKEN_RVA(0x2A425u));
    label_0002A425:
    cpu->edx = 0x2DFu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A434u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42A434u));
    cpu->eax = g_sfera_effect_manager.render_sort_indices;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A43Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42A43Fu));
    cpu->esp += 4u;
    cpu->edx = 0x2E0u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A451u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42A451u));
    cpu->ecx = g_sfera_effect_manager.render_index_buffer;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A45Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42A45Du));
    cpu->esp += 4u;
    cpu->edx = 0x2E1u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A46Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42A46Fu));
    cpu->edx = g_sfera_effect_manager.render_batch_buffer;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A47Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42A47Bu));
    cpu->esp += 4u;
    label_0002A47E:
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042A480(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edx = 0x60u;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ItemArray.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A496u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42A496u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 0x3Cu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A4AFu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42A4AFu));
    cpu->ebp = cpu->eax;
    cpu->esp += 4u;
    cpu->edx = 0x62u;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ItemArray.h";
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A4C7u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42A4C7u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax -= *(uint32_t*)(cpu->esi);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, 2u, 32u);
    ++cpu->eax;
    { int64_t v=(int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esi + 0x18u)); cpu->eax= v; uint32_t ov= (int64_t)(int32_t)v != v; cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->edx = 4u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A4EAu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42A4EAu));
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_0002A523;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x42A500u));
    cpu->esp += 0xCu;
    cpu->edx = 0x67u;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ItemArray.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A517u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42A517u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A520u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42A520u));
    cpu->esp += 4u;
    label_0002A523:
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    cpu->eax = cpu->ebp;
    cpu->ebx = cpu->ecx + 1u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x18u) <= (int32_t)cpu->ecx) goto label_0002A548;
    label_0002A532:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x14u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x10u);
    *(uint32_t*)(cpu->edi + (cpu->edx * 4u)) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x14u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u);
    cpu->ecx += cpu->ebx;
    cpu->eax += 0x3Cu;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->esi + 0x18u)) goto label_0002A532;
    label_0002A548:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = cpu->esp + 0x10u;
    if (cpu->ecx >= cpu->eax) goto label_0002A5C4;
    cpu->edx = *(uint32_t*)(cpu->esi);
    if (cpu->edx > cpu->ecx) goto label_0002A5C4;
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    { uint64_t l=cpu->edi, r=cpu->edx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->edi = (int32_t)(cpu->edi) >> 2u;
    if (cpu->eax != cpu->ecx) goto label_0002A5AC;
    { uint64_t l=cpu->eax, r=cpu->edx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    if (cpu->eax <= 0x3FFFFFFEu) goto label_0002A57E;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x42A548u), "std::length_error");
    label_0002A57E:
    cpu->ecx -= cpu->edx;
    { uint64_t l=cpu->eax, r=cpu->ebx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = (int32_t)(cpu->ecx) >> 2u;
    { uint64_t l=cpu->eax, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0002A5AC;
    cpu->edx = cpu->ecx;
    cpu->edx >>= 1u;
    cpu->ebx = 0x3FFFFFFFu;
    cpu->ebx -= cpu->edx;
    if (cpu->ebx >= cpu->ecx) goto label_0002A59C;
    cpu->ecx = 0u;
    goto label_0002A59E;
    label_0002A59C:
    cpu->ecx += cpu->edx;
    label_0002A59E:
    if (cpu->ecx >= cpu->eax) goto label_0002A5A4;
    cpu->ecx = cpu->eax;
    label_0002A5A4:
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2A5ACu)); sfera_sub_00429830(cpu, LIFT_CODE_TOKEN_RVA(0x2A5ACu));
    label_0002A5AC:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax == 0u) goto label_0002A61B;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) + (uint64_t)(4u) + (uint64_t)(0u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0002A5C4:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    if (cpu->eax != cpu->ecx) goto label_0002A612;
    cpu->edx = *(uint32_t*)(cpu->esi);
    { uint64_t l=cpu->eax, r=cpu->edx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    if (cpu->eax <= 0x3FFFFFFEu) goto label_0002A5E4;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x42A5C4u), "std::length_error");
    label_0002A5E4:
    cpu->ecx -= cpu->edx;
    { uint64_t l=cpu->eax, r=cpu->ebx, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = (int32_t)(cpu->ecx) >> 2u;
    { uint64_t l=cpu->eax, r=cpu->ecx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0002A612;
    cpu->edx = cpu->ecx;
    cpu->edx >>= 1u;
    cpu->edi = 0x3FFFFFFFu;
    cpu->edi -= cpu->edx;
    if (cpu->edi >= cpu->ecx) goto label_0002A602;
    cpu->ecx = 0u;
    goto label_0002A604;
    label_0002A602:
    cpu->ecx += cpu->edx;
    label_0002A604:
    if (cpu->ecx >= cpu->eax) goto label_0002A60A;
    cpu->ecx = cpu->eax;
    label_0002A60A:
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2A612u)); sfera_sub_00429830(cpu, LIFT_CODE_TOKEN_RVA(0x2A612u));
    label_0002A612:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax == 0u) goto label_0002A61B;
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    label_0002A61B:
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) + (uint64_t)(4u) + (uint64_t)(0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042A630(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = 0u;
    if ((uint32_t)(g_sfera_effect_manager.initialized) != cpu->esi) goto label_0002AA77;
    if (g_sfera_effect_manager.deferred_lifecycle == cpu->esi) goto label_0002A671;
    g_sfera_effect_manager.deferred_lifecycle = cpu->esi;
    goto label_0002A676;
    label_0002A671:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2A676u)); sfera_sub_0042A3A0(cpu, LIFT_CODE_TOKEN_RVA(0x2A676u));
    label_0002A676:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A67Bu)); sfera_sub_00425AA0(cpu, LIFT_CODE_TOKEN_VA(0x42A67Bu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A680u)); sfera_sub_00428BF0(cpu, LIFT_CODE_TOKEN_VA(0x42A680u));
    cpu->edx = 0x278u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A68Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42A68Fu));
    lift_push32(cpu, 0x4E20u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A699u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42A699u));
    cpu->esp += 4u;
    cpu->edx = 0x279u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    g_sfera_effect_manager.render_sort_indices = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A6B0u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42A6B0u));
    lift_push32(cpu, 0xEA60u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A6BAu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42A6BAu));
    cpu->esp += 4u;
    cpu->edx = 0x27Au;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    g_sfera_effect_manager.render_index_buffer = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A6D1u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42A6D1u));
    lift_push32(cpu, 0x7D00u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A6DBu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42A6DBu));
    cpu->esp += 4u;
    g_sfera_effect_manager.render_batch_buffer = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A6E8u)); sfera_sub_0041AD50(cpu, LIFT_CODE_TOKEN_VA(0x42A6E8u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A6EDu)); sfera_sub_0047FB10(cpu, LIFT_CODE_TOKEN_VA(0x42A6EDu));
    cpu->edx = 0x282u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A6FCu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42A6FCu));
    lift_push32(cpu, 0x88u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A706u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42A706u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    if (cpu->eax == cpu->esi) goto label_0002A71E;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A71Cu)); sfera_sub_0044B180(cpu, LIFT_CODE_TOKEN_VA(0x42A71Cu));
    goto label_0002A720;
    label_0002A71E:
    cpu->eax = 0u;
    label_0002A720:
    cpu->ecx = g_sfera_effect_manager.effect_definition_head;
    cpu->edi |= 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    if (cpu->ecx != cpu->esi) goto label_0002A73B;
    g_sfera_effect_manager.effect_definition_head = cpu->eax;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->esi;
    goto label_0002A751;
    label_0002A73B:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    if (cpu->edx == cpu->esi) goto label_0002A74B;
    label_0002A742:
    cpu->ecx = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    if (cpu->edx != cpu->esi) goto label_0002A742;
    label_0002A74B:
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->ecx;
    label_0002A751:
    cpu->edx = 0x283u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A763u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42A763u));
    lift_push32(cpu, 0x60u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A76Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42A76Au));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 1u;
    if (cpu->eax == cpu->esi) goto label_0002A786;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A784u)); sfera_sub_0042AFC0(cpu, LIFT_CODE_TOKEN_VA(0x42A784u));
    goto label_0002A788;
    label_0002A786:
    cpu->eax = 0u;
    label_0002A788:
    cpu->ecx = g_sfera_effect_manager.effect_definition_head;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    if (cpu->ecx != cpu->esi) goto label_0002A7A0;
    g_sfera_effect_manager.effect_definition_head = cpu->eax;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->esi;
    goto label_0002A7B6;
    label_0002A7A0:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    if (cpu->edx == cpu->esi) goto label_0002A7B0;
    label_0002A7A7:
    cpu->ecx = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    if (cpu->edx != cpu->esi) goto label_0002A7A7;
    label_0002A7B0:
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->ecx;
    label_0002A7B6:
    cpu->edx = 0x284u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A7C8u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42A7C8u));
    lift_push32(cpu, 0x7Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A7CFu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42A7CFu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 2u;
    if (cpu->eax == cpu->esi) goto label_0002A7EB;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A7E9u)); sfera_sub_0042B150(cpu, LIFT_CODE_TOKEN_VA(0x42A7E9u));
    goto label_0002A7ED;
    label_0002A7EB:
    cpu->eax = 0u;
    label_0002A7ED:
    cpu->ecx = g_sfera_effect_manager.effect_definition_head;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    if (cpu->ecx != cpu->esi) goto label_0002A805;
    g_sfera_effect_manager.effect_definition_head = cpu->eax;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->esi;
    goto label_0002A81F;
    label_0002A805:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    if (cpu->edx == cpu->esi) goto label_0002A819;
    label_0002A810:
    cpu->ecx = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    if (cpu->edx != cpu->esi) goto label_0002A810;
    label_0002A819:
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->ecx;
    label_0002A81F:
    cpu->edx = 0x285u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A831u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42A831u));
    lift_push32(cpu, 0x74u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A838u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42A838u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 3u;
    if (cpu->eax == cpu->esi) goto label_0002A854;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A852u)); sfera_sub_0042B320(cpu, LIFT_CODE_TOKEN_VA(0x42A852u));
    goto label_0002A856;
    label_0002A854:
    cpu->eax = 0u;
    label_0002A856:
    cpu->ecx = g_sfera_effect_manager.effect_definition_head;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    if (cpu->ecx != cpu->esi) goto label_0002A86E;
    g_sfera_effect_manager.effect_definition_head = cpu->eax;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->esi;
    goto label_0002A884;
    label_0002A86E:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    if (cpu->edx == cpu->esi) goto label_0002A87E;
    label_0002A875:
    cpu->ecx = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    if (cpu->edx != cpu->esi) goto label_0002A875;
    label_0002A87E:
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->ecx;
    label_0002A884:
    cpu->edx = 0x286u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A896u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42A896u));
    lift_push32(cpu, 0x74u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A89Du)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42A89Du));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 4u;
    if (cpu->eax == cpu->esi) goto label_0002A8B9;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A8B7u)); sfera_sub_0042B720(cpu, LIFT_CODE_TOKEN_VA(0x42A8B7u));
    goto label_0002A8BB;
    label_0002A8B9:
    cpu->eax = 0u;
    label_0002A8BB:
    cpu->ecx = g_sfera_effect_manager.effect_definition_head;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    if (cpu->ecx != cpu->esi) goto label_0002A8D3;
    g_sfera_effect_manager.effect_definition_head = cpu->eax;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->esi;
    goto label_0002A8EF;
    label_0002A8D3:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    if (cpu->edx == cpu->esi) goto label_0002A8E9;
    label_0002A8E0:
    cpu->ecx = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    if (cpu->edx != cpu->esi) goto label_0002A8E0;
    label_0002A8E9:
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->ecx;
    label_0002A8EF:
    cpu->edx = 0x288u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A901u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42A901u));
    lift_push32(cpu, 0x1A8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A90Bu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42A90Bu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 5u;
    if (cpu->eax == cpu->esi) goto label_0002A938;
    lift_x87_push(cpu, (double)5.0f);
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, 0x2D0u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A936u)); sfera_sub_0042C570(cpu, LIFT_CODE_TOKEN_VA(0x42A936u));
    goto label_0002A93A;
    label_0002A938:
    cpu->eax = 0u;
    label_0002A93A:
    cpu->ecx = g_sfera_effect_manager.effect_definition_head;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    if (cpu->ecx != cpu->esi) goto label_0002A952;
    g_sfera_effect_manager.effect_definition_head = cpu->eax;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->esi;
    goto label_0002A96F;
    label_0002A952:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    if (cpu->edx == cpu->esi) goto label_0002A969;
    label_0002A960:
    cpu->ecx = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    if (cpu->edx != cpu->esi) goto label_0002A960;
    label_0002A969:
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->ecx;
    label_0002A96F:
    cpu->edx = 0x289u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A981u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42A981u));
    lift_push32(cpu, 0x1A8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A98Bu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42A98Bu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 6u;
    if (cpu->eax == cpu->esi) goto label_0002A9B8;
    lift_x87_push(cpu, (double)10.0f);
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, 0x2D1u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42A9B6u)); sfera_sub_0042C570(cpu, LIFT_CODE_TOKEN_VA(0x42A9B6u));
    goto label_0002A9BA;
    label_0002A9B8:
    cpu->eax = 0u;
    label_0002A9BA:
    cpu->ecx = g_sfera_effect_manager.effect_definition_head;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    if (cpu->ecx != cpu->esi) goto label_0002A9D2;
    g_sfera_effect_manager.effect_definition_head = cpu->eax;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->esi;
    goto label_0002A9EF;
    label_0002A9D2:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    if (cpu->edx == cpu->esi) goto label_0002A9E9;
    label_0002A9E0:
    cpu->ecx = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    if (cpu->edx != cpu->esi) goto label_0002A9E0;
    label_0002A9E9:
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->ecx;
    label_0002A9EF:
    cpu->edx = 0x28Au;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp";
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42AA01u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42AA01u));
    lift_push32(cpu, 0x1A8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42AA0Bu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42AA0Bu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 7u;
    if (cpu->eax == cpu->esi) goto label_0002AA38;
    lift_x87_push(cpu, (double)15.0f);
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, 0x2D2u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42AA36u)); sfera_sub_0042C570(cpu, LIFT_CODE_TOKEN_VA(0x42AA36u));
    goto label_0002AA3A;
    label_0002AA38:
    cpu->eax = 0u;
    label_0002AA3A:
    cpu->ecx = g_sfera_effect_manager.effect_definition_head;
    if (cpu->ecx != cpu->esi) goto label_0002AA4E;
    g_sfera_effect_manager.effect_definition_head = cpu->eax;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->esi;
    goto label_0002AA64;
    label_0002AA4E:
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    if (cpu->edx == cpu->esi) goto label_0002AA5E;
    label_0002AA55:
    cpu->ecx = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    if (cpu->edx != cpu->esi) goto label_0002AA55;
    label_0002AA5E:
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 0x24u) = cpu->ecx;
    label_0002AA64:
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->esi;
    g_sfera_effect_manager.render_slot_count = cpu->esi;
    g_sfera_effect_manager.initialized = 1u;
    label_0002AA77:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042AA90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_effect_manager.effect_listeners;
    cpu->esi = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42AAB1u)); sfera_sub_00429A80(cpu, LIFT_CODE_TOKEN_VA(0x42AAB1u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->edx == g_sfera_effect_manager.effect_listeners.sentinel) goto label_0002AAD6;
    lift_push32(cpu, (uintptr_t)"EM_RegisterEffectListener::Multiple listeners not implemented.");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42AAC7u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x42AAC7u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42AACDu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x42AACDu));
    cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0002AAD6:
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uintptr_t)&g_sfera_effect_manager.effect_listeners;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42AAEFu)); sfera_sub_0042A320(cpu, LIFT_CODE_TOKEN_VA(0x42AAEFu));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_effect_manager.effect_listeners;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42AAFFu)); sfera_sub_004298B0(cpu, LIFT_CODE_TOKEN_VA(0x42AAFFu));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042AB10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->edx;
    cpu->ebp = 0u;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    if (cpu->ebx != cpu->ebp) goto label_0002AB4C;
    lift_push32(cpu, 0x342u); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\EffectManager.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42AB43u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x42AB43u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42AB49u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x42AB49u));
    cpu->esp += 0x10u;
    label_0002AB4C:
    if (g_sfera_effect_manager.active_effect_count < 0x1770u) goto label_0002AB6D;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0002AB6D:
    if (cpu->esi < 0x1388u) goto label_0002AB92;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42AB80u)); sfera_sub_004977E0(cpu, LIFT_CODE_TOKEN_VA(0x42AB80u));
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0002AB92:
    cpu->ecx = g_sfera_effect_manager.effect_definition_head;
    lift_push32(cpu, cpu->edi);
    if (cpu->ecx == cpu->ebp) goto label_0002AD0A;
    label_0002ABA1:
    if (*(uint32_t*)(cpu->ecx + 8u) == cpu->esi) goto label_0002ABC3;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x20u);
    if (cpu->ecx != cpu->ebp) goto label_0002ABA1;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0002ABC3:
    reinterpret_cast<IEffectManager*>(cpu->ecx)->createEffectResources(cpu);
    cpu->edi = cpu->eax;
    if (cpu->edi == cpu->ebp) goto label_0002AD0A;
    if (g_sfera_effect_manager.effects_enabled == cpu->ebp) goto label_0002ABED;
    cpu->ecx = cpu->edi;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->isEffectComplete(cpu);
    if ((int32_t)cpu->eax > 0) goto label_0002AD0A;
    label_0002ABED:
    if (g_sfera_effect_items.free_count != cpu->ebp) goto label_0002ABFF;
    cpu->ecx = (uintptr_t)&g_sfera_effect_items;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2ABFFu)); sfera_sub_0042A480(cpu, LIFT_CODE_TOKEN_RVA(0x2ABFFu));
    label_0002ABFF:
    cpu->eax = g_sfera_effect_items.free_count;
    cpu->ecx = g_sfera_effect_items.free_items;
    --cpu->eax;
    g_sfera_effect_items.free_count = cpu->eax;
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42AC1Cu)); sfera_sub_00456040(cpu, LIFT_CODE_TOKEN_VA(0x42AC1Cu));
    if (cpu->eax != 0u) goto label_0002AC54;
    cpu->ecx = cpu->edi;
    reinterpret_cast<IEffectManager*>(cpu->ecx)->releaseEffect(cpu);
    cpu->ecx = g_sfera_effect_items.free_count;
    cpu->edx = g_sfera_effect_items.free_items;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->edx + (cpu->ecx * 4u)) = cpu->esi;
    ++g_sfera_effect_items.free_count;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0002AC54:
    cpu->eax = 0u;
    cpu->edx = cpu->ebx;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebp;
    *(uint16_t*)(cpu->esi) = cpu->eax & 0xFFFFu;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x18u) = LIFT_CALLBACK(sfera_sub_00429F30);
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42AC78u)); sfera_sub_00425B20(cpu, LIFT_CODE_TOKEN_VA(0x42AC78u));
    *(float*)(cpu->esi + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = 0xFFFFu;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->ecx;
    *(uint16_t*)(cpu->esi + 2u) = cpu->edx & 0xFFFFu;
    cpu->edx = cpu->esp + 0x18u;
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42AC9Fu)); sfera_sub_00455E40(cpu, LIFT_CODE_TOKEN_VA(0x42AC9Fu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->edi + 0x2Cu) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->edi + 0x30u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->edi + 0x34u) = cpu->edx;
    ++g_sfera_effect_manager.active_effect_count;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)&g_sfera_effect_manager.active_effects;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42ACC5u)); sfera_sub_00425C00(cpu, LIFT_CODE_TOKEN_VA(0x42ACC5u));
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uintptr_t)&g_sfera_effect_manager.effect_listeners;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42ACD9u)); sfera_sub_00429A80(cpu, LIFT_CODE_TOKEN_VA(0x42ACD9u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->eax == g_sfera_effect_manager.effect_listeners.sentinel) goto label_0002AD20;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x10u);
    *(uint32_t*)(cpu->edi + 0x38u) = cpu->edx;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x2Cu));
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10u);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, cpu->edi);
    reinterpret_cast<BloodEffListener*>(cpu->ecx)->onEffectAttached(cpu);
    if ((cpu->eax & 0xFFu) != 0u) goto label_0002AD20;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2AD0Au)); sfera_sub_00429B20(cpu, LIFT_CODE_TOKEN_RVA(0x2AD0Au));
    label_0002AD0A:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0002AD20:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042AD40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_effect_manager.effect_definition_head;
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x20u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esi + 0x20u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    cpu->ebx = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002AD79;
    cpu->ebp = native_function_address32(&::_stricmp);
    label_0002AD60:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x2AD67u), LIFT_CODE_TOKEN_RVA(0x2AD65u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0002AD82;
    cpu->esi = *(uint32_t*)(cpu->edi);
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x20u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->esi + 0x20u;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002AD60;
    label_0002AD79:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0002AD82:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    if ((int32_t)cpu->ecx <= 0) goto label_0002AD79;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 4u;
    sfera_sub_0042AB10(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_0042ADA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x3Cu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ebp);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    cpu->ebp = cpu->ecx;
    if (g_sfera_effect_manager.flare_enabled == cpu->eax) goto label_0002ADD4;
    cpu->ecx = 0u;
    { uint64_t v=cpu->eax; lift_flags_logic(cpu,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    g_sfera_effect_manager.flare_enabled = cpu->eax;
    ++cpu->ecx;
    g_sfera_effect_manager.flare_transition = cpu->ecx;
    label_0002ADD4:
    if (cpu->eax != 0u) goto label_0002ADE4;
    if (g_sfera_effect_manager.flare_alpha == cpu->eax) goto label_0002AF9A;
    label_0002ADE4:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uintptr_t)"fx_flare";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42ADF1u)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x42ADF1u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x50u);
    cpu->edx = cpu->esi + (cpu->esi * 4u);
    cpu->edx <<= 7u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) / ((double)(((int32_t)(g_sfera_graphics_runtime.display_width))));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42AE12u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x42AE12u));
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x1E0u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    cpu->edi = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) / ((double)(((int32_t)(g_sfera_graphics_runtime.display_height))));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42AE2Du)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x42AE2Du));
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u];
    cpu->ebx = cpu->eax;
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u];
    cpu->eax = cpu->edi;
    lift_x87_push(cpu, 1.0);
    cpu->eax = (int32_t)(cpu->eax) >> 1u;
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u];
    { uint64_t l=cpu->ebp, r=cpu->eax, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebp = v; }
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u];
    cpu->ecx = cpu->ebx;
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u];
    cpu->ecx = (int32_t)(cpu->ecx) >> 1u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x1Cu)) - (uint64_t)(cpu->ecx) - (uint64_t)(0u);
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebp;
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u];
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.3499999940395355f);
    lift_x87_push(cpu, (double)g_sfera_graphics_runtime.environment_factor);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 2550.0);
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0002AEBD;
    *(uint16_t*)(cpu->esp + 0x10u) = cpu->fpu_control;
    cpu->eax = *(uint16_t*)(cpu->esp + 0x10u);
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[0u] = (0.3499999940395355) - (cpu->fpu[0u]);
    cpu->eax |= 0xC00u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x14u);
    *(uint64_t*)(cpu->esp + 0x14u) = lift_x87_round(cpu, cpu->fpu[0u], 0u);
    lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x10u);
    if (cpu->ecx <= 0xFFu) goto label_0002AEBD;
    cpu->ecx = 0xFFu;
    label_0002AEBD:
    lift_x87_push(cpu, (double)*(float*)((uintptr_t)"333\077..\\ShareClientSeverCode\\CheckFiles.cpp"));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[2u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0002AF07;
    *(uint16_t*)(cpu->esp + 0x10u) = cpu->fpu_control;
    cpu->eax = *(uint16_t*)(cpu->esp + 0x10u);
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (0.699999988079071);
    cpu->eax |= 0xC00u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x14u);
    *(uint64_t*)(cpu->esp + 0x14u) = lift_x87_round(cpu, cpu->fpu[0u], 0u);
    lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x10u);
    if (cpu->ecx <= 0xFFu) goto label_0002AF09;
    cpu->ecx = 0xFFu;
    goto label_0002AF09;
    label_0002AF07:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0002AF09:
    lift_x87_push(cpu, (double)0.1899999976158142f);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0002AF27;
    lift_x87_compare(cpu, cpu->fpu[0u], 0.8299999833106995);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x41u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002AF2B;
    goto label_0002AF29;
    label_0002AF27:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0002AF29:
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    label_0002AF2B:
    cpu->esi = g_sfera_effect_manager.flare_alpha;
    { int64_t v=(int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(cpu->ecx); cpu->esi= v; uint32_t ov= (int64_t)(int32_t)v != v; cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->esi >>= 8u;
    if (cpu->esi == 0u) goto label_0002AF97;
    cpu->ecx = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42AF45u)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_VA(0x42AF45u));
    cpu->ebx += *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, 1u);
    cpu->edx = cpu->esp + 0x2Cu;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u)))));
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->esp -= 0x10u;
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    { uint64_t l=cpu->edi, r=cpu->ebp, c=0u, v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edi;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x2Cu)))));
    cpu->ecx = cpu->esi;
    cpu->ecx <<= 24u;
    cpu->ecx |= 0xFF640Fu;
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x34u)))));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x38u)))));
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42AF90u)); sfera_sub_004CEDA0(cpu, LIFT_CODE_TOKEN_VA(0x42AF90u));
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2AF97u)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_RVA(0x2AF97u));
    label_0002AF97:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0002AF9A:
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x3Cu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042AFB0(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_effect_manager.detail_setting = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042AFC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42AFEFu)); sfera_sub_00425E30(cpu, LIFT_CODE_TOKEN_VA(0x42AFEFu));
    lift_push32(cpu, (uintptr_t)"spiral.effect0");
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x24u) = 0u;
    std::construct_at(reinterpret_cast<CSpiralEffect*>(cpu->esi));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B009u)); sfera_sub_00425EB0(cpu, LIFT_CODE_TOKEN_VA(0x42B009u));
    lift_x87_push(cpu, (double)-0.4000000059604645f);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u];
    cpu->eax = 0x190u;
    lift_x87_push(cpu, (double)-1.0f);
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.4000000059604645f);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u];
    *(uint32_t*)(cpu->esi + 0x3Cu) = cpu->eax;
    lift_x87_push(cpu, (double)0.10000000149011612f);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esi + 0x48u) = cpu->eax;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esi + 0x44u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esi + 0x4Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 8u) = 0u;
    *(uint32_t*)(cpu->esi + 0x5Cu) = 0xFFFFFFFFu;
    *(uint8_t*)(cpu->esi + 0x54u) = 1u;
    *(uint32_t*)(cpu->esi + 0x50u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x58u) = 0x50u;
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042B0A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042B0B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    (void)0; /* source SEH registration eliminated */
    cpu->edx = 0x120u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Effects.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B0E1u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42B0E1u));
    lift_push32(cpu, 0x60u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B0E8u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42B0E8u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    if (cpu->eax == cpu->esi) goto label_0002B102;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B100u)); sfera_sub_0042AFC0(cpu, LIFT_CODE_TOKEN_VA(0x42B100u));
    cpu->esi = cpu->eax;
    label_0002B102:
    cpu->ecx = (uintptr_t)"fx_flare";
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B114u)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x42B114u));
    *(uint32_t*)(cpu->esi + 0x5Cu) = cpu->eax;
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042B130(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x12Eu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Effects.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B144u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x42B144u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B14Au)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x42B14Au));
    cpu->esp += 0x10u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042B150(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x1Cu;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B180u)); sfera_sub_00425E30(cpu, LIFT_CODE_TOKEN_VA(0x42B180u));
    cpu->edi = 0u;
    lift_push32(cpu, (uintptr_t)"molniya.effect110");
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edi;
    std::construct_at(reinterpret_cast<CMolEffect*>(cpu->esi));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B198u)); sfera_sub_00425EB0(cpu, LIFT_CODE_TOKEN_VA(0x42B198u));
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esi + 0x68u) = cpu->fpu[0u];
    cpu->eax |= 0xFFFFFFFFu;
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u];
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esi + 0x5Cu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esi + 0x60u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x70u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x10u) = 1u;
    *(uint32_t*)(cpu->esi + 8u) = 0x6Eu;
    *(uint32_t*)(cpu->esi + 0x64u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x6Cu) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x74u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x78u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x58u) = 4u;
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042B200(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x78u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x74u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002B242;
    if (cpu->ecx == 0u) goto label_0002B237;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0xACu));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0002B22A;
    cpu->eax = 1u;
    goto label_0002B22C;
    label_0002B22A:
    cpu->eax = 0u;
    label_0002B22C:
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2B237u)); sfera_sub_00496650(cpu, LIFT_CODE_TOKEN_RVA(0x2B237u));
    label_0002B237:
    *(uint32_t*)(cpu->esi + 0x78u) = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0002B242:
    if (cpu->ecx == 0u) goto label_0002B257;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    lift_push32(cpu, cpu->ecx);
    cpu->esi += 0x5Cu;
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2B257u)); sfera_sub_00496BD0(cpu, LIFT_CODE_TOKEN_RVA(0x2B257u));
    label_0002B257:
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042B260(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    (void)0; /* source SEH registration eliminated */
    cpu->edx = 0x1D9u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Effects.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B291u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42B291u));
    lift_push32(cpu, 0x7Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B298u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42B298u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    if (cpu->eax == cpu->esi) goto label_0002B2B2;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B2B0u)); sfera_sub_0042B150(cpu, LIFT_CODE_TOKEN_VA(0x42B2B0u));
    cpu->esi = cpu->eax;
    label_0002B2B2:
    cpu->ecx = (uintptr_t)"fx_light";
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B2C4u)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x42B2C4u));
    *(uint32_t*)(cpu->esi + 0x70u) = cpu->eax;
    if (cpu->eax != 0xFFFFFFFFu) goto label_0002B2DF;
    lift_push32(cpu, (uintptr_t)"CMolEffect::Texture not found 'fx_light'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B2D6u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x42B2D6u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B2DCu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x42B2DCu));
    cpu->esp += 8u;
    label_0002B2DF:
    cpu->ecx = 0x6Eu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B2E9u)); sfera_sub_00497910(cpu, LIFT_CODE_TOKEN_VA(0x42B2E9u));
    *(uint32_t*)(cpu->esi + 0x74u) = cpu->eax;
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042B300(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x1EBu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Effects.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B314u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x42B314u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B31Au)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x42B31Au));
    cpu->esp += 0x10u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042B320(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B34Fu)); sfera_sub_00425E30(cpu, LIFT_CODE_TOKEN_VA(0x42B34Fu));
    lift_push32(cpu, (uintptr_t)"blade");
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x24u) = 0u;
    std::construct_at(reinterpret_cast<CBladeEffect*>(cpu->esi));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B369u)); sfera_sub_00425EB0(cpu, LIFT_CODE_TOKEN_VA(0x42B369u));
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esi + 0x68u) = cpu->fpu[0u];
    *(uint32_t*)(cpu->esi + 0x10u) = 0x40u;
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u];
    *(uint32_t*)(cpu->esi + 0x14u) = 0x20u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esi + 0x5Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x60u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 8u) = 0x154u;
    *(uint32_t*)(cpu->esi + 0x64u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x6Cu) = 0u;
    *(uint32_t*)(cpu->esi + 0x70u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x58u) = 4u;
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042B3D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042B3E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    (void)0; /* source SEH registration eliminated */
    cpu->edx = 0x29Cu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Effects.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B411u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42B411u));
    lift_push32(cpu, 0x74u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B418u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42B418u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    if (cpu->eax == cpu->esi) goto label_0002B432;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B430u)); sfera_sub_0042B320(cpu, LIFT_CODE_TOKEN_VA(0x42B430u));
    cpu->esi = cpu->eax;
    label_0002B432:
    cpu->ecx = (uintptr_t)"fx_blade";
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B444u)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x42B444u));
    *(uint32_t*)(cpu->esi + 0x70u) = cpu->eax;
    if (cpu->eax != 0xFFFFFFFFu) goto label_0002B45F;
    lift_push32(cpu, (uintptr_t)"CBladeEffect::Texture not found 'fx_blade'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B456u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x42B456u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B45Cu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x42B45Cu));
    cpu->esp += 8u;
    label_0002B45F:
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042B480(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0x2ACu); lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\Effects.cpp"); lift_push32(cpu, (uintptr_t)"SphereReport::Assertion failed -> File %s, Line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B494u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x42B494u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B49Au)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x42B49Au));
    cpu->esp += 0x10u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042B4A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x14u;
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    std::construct_at(reinterpret_cast<CGazerLakeEffect*>(cpu->ebx));
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    cpu->esi = cpu->ebx + 0x68u;
    cpu->edi = 0x10u;
    label_0002B4E0:
    if (*(uint32_t*)(cpu->esi) == 0u) goto label_0002B503;
    cpu->edx = 0x2DCu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Effects.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B4F4u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42B4F4u));
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if (cpu->ecx == 0u) goto label_0002B503;
    lift_push32(cpu, 1u);
    reinterpret_cast<IEffectManager*>(cpu->ecx)->destroyEffect(cpu);
    label_0002B503:
    cpu->esi += 0x14u;
    { uint64_t l=cpu->edi, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002B4E0;
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B518u)); sfera_sub_00425E70(cpu, LIFT_CODE_TOKEN_VA(0x42B518u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042B530(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx);
    lift_x87_push(cpu, (double)-1.0f);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x5Cu);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_divide_accumulator(cpu, *(uint32_t*)(cpu->esi + 0x60u), 32u, 1u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edi);
    if (cpu->edx != 0u) goto label_0002B63A;
    cpu->edi = 0u;
    cpu->ecx = cpu->esi + 0x6Cu;
    label_0002B562:
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx));
    lift_x87_push(cpu, cpu->fpu[1u]);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x44u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0002B57D;
    ++cpu->edi;
    cpu->ecx += 0x14u;
    if ((int32_t)cpu->edi < (int32_t)0x10u) goto label_0002B562;
    goto label_0002B63A;
    label_0002B57D:
    cpu->ebp = native_function_address32(&::rand);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x2B587u), LIFT_CODE_TOKEN_RVA(0x2B585u))) { return; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0518509447574615e-05);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (6.283185958862305);
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x2B5A9u), LIFT_CODE_TOKEN_RVA(0x2B5A7u))) { return; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0518509447574615e-05);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (0.5);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.1415929794311523);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B5D8u)); sfera_sub_004EE9F2(cpu, LIFT_CODE_TOKEN_VA(0x42B5D8u));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->eax = cpu->edi + (cpu->edi * 4u);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ebp = cpu->esi + (cpu->eax * 4u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B5F3u)); sfera_sub_004EE9F8(cpu, LIFT_CODE_TOKEN_VA(0x42B5F3u));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x64u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x10u)));
    *(float*)(cpu->ebp + 0x70u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B60Eu)); sfera_sub_004EE9F2(cpu, LIFT_CODE_TOKEN_VA(0x42B60Eu));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    cpu->ecx = cpu->edi + (cpu->edi * 4u) + 0x1Eu;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x64u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x10u)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    *(float*)(cpu->esi + (cpu->ecx * 4u)) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->ebp + 0x74u) = cpu->fpu[0u];
    *(float*)(cpu->ebp + 0x6Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)-1.0f);
    label_0002B63A:
    *(uint32_t*)(cpu->esi + 0x5Cu) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x5Cu)) + (uint64_t)(2u) + (uint64_t)(0u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x48u);
    cpu->esi += 0x6Cu;
    cpu->ebp = 0x10u;
    label_0002B64A:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi));
    lift_x87_push(cpu, cpu->fpu[1u]);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x44u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0002B6E8;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xFFFFFFFCu);
    if (cpu->ecx == 0u) goto label_0002B6E8;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (2.0);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    *(float*)(cpu->esi) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)192.0f);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0002B697;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esi) = cpu->fpu[0u];
    goto label_0002B6E8;
    label_0002B697:
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, 0u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 4u));
    lift_push32(cpu, cpu->edi);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ebx)));
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 8u));
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edx;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ebx + 4u)));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebx + 8u));
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0xCu)));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, 1u);
    cpu->edx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->edx);
    reinterpret_cast<IEffectManager*>(static_cast<uintptr_t>(cpu->ecx))->initializeEffect(cpu);
    lift_x87_push(cpu, (double)-1.0f);
    label_0002B6E8:
    cpu->esi += 0x14u;
    { uint64_t l=cpu->ebp, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002B64A;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x28u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042B710(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042B720(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B74Du)); sfera_sub_00425E30(cpu, LIFT_CODE_TOKEN_VA(0x42B74Du));
    lift_x87_push(cpu, (double)4.0f);
    *(float*)(cpu->esi + 0x64u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = 0u;
    lift_x87_push(cpu, (double)0.4000000059604645f);
    lift_push32(cpu, (uintptr_t)"rain");
    *(float*)(cpu->esi + 0x68u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = cpu->esi;
    lift_x87_push(cpu, (double)120.0f);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(float*)(cpu->esi + 0x6Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    std::construct_at(reinterpret_cast<CRainEffect*>(cpu->esi));
    lift_x87_push(cpu, 0.0);
    *(uint32_t*)(cpu->esi + 0x5Cu) = 0xFFFFFFFFu;
    *(float*)(cpu->esi + 0x70u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esi + 0x60u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B78Fu)); sfera_sub_00425EB0(cpu, LIFT_CODE_TOKEN_VA(0x42B78Fu));
    *(uint32_t*)(cpu->esi + 0x10u) = 0x40u;
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 8u) = 0x190u;
    *(uint32_t*)(cpu->esi + 0x28u) = 3u;
    *(uint32_t*)(cpu->esi + 0x58u) = 0xBB8u;
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042B7D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042B7E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B7E8u)); sfera_sub_00425E70(cpu, LIFT_CODE_TOKEN_VA(0x42B7E8u));
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_0002B7F8;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B7F5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42B7F5u));
    cpu->esp += 4u;
    label_0002B7F8:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042B800(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x54u;
    { uint64_t l=*(uint32_t*)(cpu->ebp + 0x14u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002BA3C;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x58u);
    cpu->ecx += g_sfera_effect_manager.render_slot_count;
    if (cpu->ecx >= 0x2710u) goto label_0002BA3C;
    lift_x87_push(cpu, 1.0);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)320.0f);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edx;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x10u));
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0002B885;
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (400.0) - (cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (80.0);
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0002B885:
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.05000000074505806);
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    *(double*)(cpu->esp + 0x48u) = cpu->fpu[0u];
    lift_x87_pop(cpu);
    label_0002B897:
    lift_x87_push(cpu, 0.0);
    *(uint32_t*)(cpu->esp + 0x10u) = 0x28u;
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.1415929794311523);
    *(double*)(cpu->esp + 0x40u) = cpu->fpu[0u];
    lift_x87_pop(cpu);
    label_0002B8B3:
    cpu->eax = g_sfera_effect_manager.render_slot_count;
    cpu->esi = cpu->eax;
    ++cpu->eax;
    g_sfera_effect_manager.render_slot_count = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_0002B8CE;
    cpu->ecx = (uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2B8CEu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x2B8CEu));
    label_0002B8CE:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_effect_manager.render_slots.capacity) goto label_0002B8E2;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2B8E2u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x2B8E2u));
    label_0002B8E2:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x9Cu);
    lift_x87_push(cpu, -204.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    cpu->esi += g_sfera_effect_manager.render_slots.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x5Cu);
    *(uint32_t*)(cpu->esi + 0x90u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x98u) = 1u;
    *(uint32_t*)(cpu->esi + 0x94u) = 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B920u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x42B920u));
    cpu->edi = 0x33u;
    lift_x87_push(cpu, -51.0);
    cpu->edi -= cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B934u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x42B934u));
    lift_x87_push(cpu, 77.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    cpu->ebx = 0x99u;
    cpu->ebx -= cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B948u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x42B948u));
    lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, 1.0);
    cpu->ecx = 0x99u;
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    cpu->ecx -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (255.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x20u)));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B968u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x42B968u));
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    cpu->ecx = cpu->esi + 0x40u;
    cpu->edx = 4u;
    label_0002B974:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->ecx + 0xFFFFFFF0u) = cpu->edi;
    *(uint32_t*)(cpu->ecx) = cpu->ebx;
    *(uint32_t*)(cpu->ecx + 0x20u) = cpu->eax;
    cpu->ecx += 4u;
    { uint64_t l=cpu->edx, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002B974;
    lift_x87_push(cpu, 3.1415929794311523);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (1.2000000476837158);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (*(double*)(cpu->esp + 0x40u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (*(double*)(cpu->esp + 0x48u));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (((double)*(float*)(cpu->esp + 0x38u))) - (cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x54u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    *(double*)(cpu->esp + 0x28u) = cpu->fpu[0u];
    lift_x87_pop(cpu); lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B9C0u)); sfera_sub_004EE9F8(cpu, LIFT_CODE_TOKEN_VA(0x42B9C0u));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.30000001192092896);
    cpu->fpu[0u] = (*(double*)(cpu->esp + 0x28u)) - (cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x50u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    *(double*)(cpu->esp + 0x28u) = cpu->fpu[0u];
    lift_x87_pop(cpu); lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42B9E7u)); sfera_sub_004EE9F2(cpu, LIFT_CODE_TOKEN_VA(0x42B9E7u));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    lift_push32(cpu, cpu->ecx);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.30000001192092896);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->esp + 0x54u;
    cpu->fpu[0u] = (*(double*)(cpu->esp + 0x2Cu)) - (cpu->fpu[0u]);
    *(float*)(cpu->esp + 0x5Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)0.15000000596046448f);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42BA12u)); sfera_sub_00483060(cpu, LIFT_CODE_TOKEN_VA(0x42BA12u));
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x10u), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; *(uint32_t*)(cpu->esp + 0x10u) = v; }
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (0.02500000037252903);
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002B8B3;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)2u) goto label_0002B897;
    label_0002BA3C:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042BA50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    std::construct_at(reinterpret_cast<CMolEffect*>(cpu->esi));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x74u);
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if (cpu->ecx == 0u) goto label_0002BA92;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2BA92u)); sfera_sub_00496FE0(cpu, LIFT_CODE_TOKEN_RVA(0x2BA92u));
    label_0002BA92:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42BAA1u)); sfera_sub_00425E70(cpu, LIFT_CODE_TOKEN_VA(0x42BAA1u));
    if (((*(uint8_t*)(cpu->esp + 0x1Cu)) & (1u)) == 0u) goto label_0002BAB1;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42BAAEu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42BAAEu));
    cpu->esp += 4u;
    label_0002BAB1:
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042BAD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x5Cu;
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x6Cu), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = *(uint32_t*)(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002C006;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x58u);
    cpu->ecx += g_sfera_effect_manager.render_slot_count;
    if (cpu->ecx >= 0x2710u) goto label_0002C006;
    { uint64_t l=*(uint32_t*)(cpu->edi + 0x6Cu), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002BB37;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi + 0x5Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edi + 0x60u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->edi + 0x64u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 0x6Cu) = 1u;
    label_0002BB37:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x5Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42BB43u)); sfera_sub_00455FD0(cpu, LIFT_CODE_TOKEN_VA(0x42BB43u));
    cpu->eax = g_sfera_effect_manager.render_slot_count;
    cpu->esi = cpu->eax;
    ++cpu->eax;
    g_sfera_effect_manager.render_slot_count = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_0002BB5E;
    cpu->ecx = (uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2BB5Eu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x2BB5Eu));
    label_0002BB5E:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_effect_manager.render_slots.capacity) goto label_0002BB72;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2BB72u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x2BB72u));
    label_0002BB72:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x70u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x9Cu);
    cpu->esi += g_sfera_effect_manager.render_slots.data;
    cpu->ebx = native_function_address32(&::rand);
    cpu->eax = 0xFFu;
    *(uint32_t*)(cpu->esi + 0x90u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x98u) = 3u;
    *(uint32_t*)(cpu->esi + 0x94u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x50u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x60u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x44u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x54u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x64u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x48u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x58u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x68u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x4Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x5Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x6Cu) = cpu->eax;
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x2BBD4u), LIFT_CODE_TOKEN_RVA(0x2BBD2u))) { return; }
    cpu->ebp = cpu->eax;
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x2BBD8u), LIFT_CODE_TOKEN_RVA(0x2BBD6u))) { return; }
    cpu->ebp -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0518509447574615e-05);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.20000000298023224);
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x2BBF4u), LIFT_CODE_TOKEN_RVA(0x2BBF2u))) { return; }
    cpu->ebp = cpu->eax;
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x2BBF8u), LIFT_CODE_TOKEN_RVA(0x2BBF6u))) { return; }
    cpu->ebp -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0518509447574615e-05);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.20000000298023224);
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x2BC14u), LIFT_CODE_TOKEN_RVA(0x2BC12u))) { return; }
    cpu->ebp = cpu->eax;
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x2BC18u), LIFT_CODE_TOKEN_RVA(0x2BC16u))) { return; }
    cpu->ebp -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0518509447574615e-05);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.20000000298023224);
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x2BC34u), LIFT_CODE_TOKEN_RVA(0x2BC32u))) { return; }
    cpu->ebp = cpu->eax;
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x2BC38u), LIFT_CODE_TOKEN_RVA(0x2BC36u))) { return; }
    cpu->ebp -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0518509447574615e-05);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.20000000298023224);
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x2BC54u), LIFT_CODE_TOKEN_RVA(0x2BC52u))) { return; }
    cpu->ebp = cpu->eax;
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x2BC58u), LIFT_CODE_TOKEN_RVA(0x2BC56u))) { return; }
    cpu->ebp -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0518509447574615e-05);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.20000000298023224);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x2BC74u), LIFT_CODE_TOKEN_RVA(0x2BC72u))) { return; }
    cpu->ebp = cpu->eax;
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x2BC78u), LIFT_CODE_TOKEN_RVA(0x2BC76u))) { return; }
    cpu->ebp -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0518509447574615e-05);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.20000000298023224);
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x5Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x28u)));
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x60u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x2Cu)));
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x64u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x30u)));
    *(float*)(cpu->esp + 0x48u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x34u)));
    *(float*)(cpu->esp + 0x50u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x38u)));
    *(float*)(cpu->esp + 0x54u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x3Cu)));
    *(float*)(cpu->esp + 0x58u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x50u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x40u)));
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x54u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x44u)));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x58u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x48u)));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x68u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (0.05000000074505806);
    *(float*)(cpu->edi + 0x68u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42BD30u)); sfera_sub_004EE9EC(cpu, LIFT_CODE_TOKEN_VA(0x42BD30u));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.30000001192092896);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x50u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x5Cu)));
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x54u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x60u)));
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x58u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x64u)));
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x38u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[4u] = cpu->fpu[4u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[6u] = cpu->fpu[6u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[5u] = cpu->fpu[0u] - cpu->fpu[5u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42BDD7u)); sfera_sub_004EE9EC(cpu, LIFT_CODE_TOKEN_VA(0x42BDD7u));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_x87_push(cpu, 1.0);
    cpu->fpu[1u] = cpu->fpu[0u] / cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    lift_x87_push(cpu, 0.800000011920929);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x4Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x50u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esi) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x4Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x54u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esi + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x58u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esi + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esi + 0x70u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x68u));
    lift_x87_push(cpu, 0.0);
    cpu->fpu[1u] = (cpu->fpu[1u]) + (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esi + 0x74u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[5u]; cpu->fpu[5u] = temporary; }
    cpu->fpu[6u] = cpu->fpu[0u] - cpu->fpu[6u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[5u]; cpu->fpu[5u] = temporary; }
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[0u] - cpu->fpu[2u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esi + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esi + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    *(float*)(cpu->esi + 0x78u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edi + 0x68u)));
    *(float*)(cpu->esi + 0x7Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x5Cu)));
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x60u)));
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x48u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x64u)));
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x38u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[4u] = cpu->fpu[4u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[6u] = cpu->fpu[6u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[5u] = cpu->fpu[0u] - cpu->fpu[5u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42BF33u)); sfera_sub_004EE9EC(cpu, LIFT_CODE_TOKEN_VA(0x42BF33u));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_x87_push(cpu, 1.0);
    cpu->fpu[1u] = cpu->fpu[0u] / cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    lift_x87_push(cpu, 0.800000011920929);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x4Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esi + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x4Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esi + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x48u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esi + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    *(float*)(cpu->esi + 0x80u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x68u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x10u)));
    *(float*)(cpu->esi + 0x84u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[5u] = cpu->fpu[5u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    *(float*)(cpu->esi + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esi + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esi + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esi + 0x88u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x68u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x10u)));
    *(float*)(cpu->esi + 0x8Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0002C006:
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x5Cu;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042C020(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    std::construct_at(reinterpret_cast<CBladeEffect*>(cpu->esi));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42C02Eu)); sfera_sub_00425E70(cpu, LIFT_CODE_TOKEN_VA(0x42C02Eu));
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_0002C03E;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42C03Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42C03Bu));
    cpu->esp += 4u;
    label_0002C03E:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042C050(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x58u;
    { uint64_t l=*(uint32_t*)(cpu->esp + 0x68u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = *(uint32_t*)(cpu->esp + 0x5Cu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002C555;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x58u);
    cpu->ecx += g_sfera_effect_manager.render_slot_count;
    if (cpu->ecx >= 0x2710u) goto label_0002C555;
    { uint64_t l=*(uint32_t*)(cpu->edi + 0x6Cu), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002C0B7;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi + 0x5Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edi + 0x60u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->edi + 0x64u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 0x6Cu) = 1u;
    label_0002C0B7:
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x50u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42C0C1u)); sfera_sub_00455FD0(cpu, LIFT_CODE_TOKEN_VA(0x42C0C1u));
    cpu->eax = g_sfera_effect_manager.render_slot_count;
    cpu->esi = cpu->eax;
    ++cpu->eax;
    g_sfera_effect_manager.render_slot_count = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_0002C0DC;
    cpu->ecx = (uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2C0DCu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x2C0DCu));
    label_0002C0DC:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_effect_manager.render_slots.capacity) goto label_0002C0F0;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2C0F0u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x2C0F0u));
    label_0002C0F0:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x70u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x9Cu);
    cpu->esi += g_sfera_effect_manager.render_slots.data;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0xFFu;
    *(uint32_t*)(cpu->esi + 0x90u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x98u) = 3u;
    *(uint32_t*)(cpu->esi + 0x94u) = cpu->ebx;
    cpu->ecx = cpu->ebx;
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x68u));
    lift_x87_compare(cpu, cpu->fpu[0u], 0.800000011920929);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0002C147;
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x68u));
    lift_x87_push(cpu, 1.0);
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) / (0.20000000298023224);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (255.0);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42C145u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x42C145u));
    cpu->ecx = cpu->eax;
    label_0002C147:
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x50u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x44u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x54u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x48u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x58u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x3Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x4Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x5Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x60u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x64u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x68u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x6Cu) = cpu->ecx;
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x68u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (0.05000000074505806);
    cpu->ebx = lift_pop32(cpu);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    *(float*)(cpu->edi + 0x68u) = cpu->fpu[0u];
    lift_x87_push(cpu, 1.0);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0002C19E;
    *(float*)(cpu->edi + 0x68u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_0002C1A0;
    label_0002C19E:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0002C1A0:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    cpu->ecx = cpu->esp + 0x18u;
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->edi + 0x5Cu)));
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->edi + 0x60u)));
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->edi + 0x64u)));
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x68u));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x38u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x3Cu)));
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x5Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edi + 0x60u)));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edi + 0x64u)));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x5Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x28u)));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x60u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x2Cu)));
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x64u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x30u)));
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42C237u)); sfera_sub_0042F3E0(cpu, LIFT_CODE_TOKEN_VA(0x42C237u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    lift_x87_push(cpu, 0.5);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0xCu)));
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x10u)));
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[4u] = cpu->fpu[0u] - cpu->fpu[4u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x38u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[3u] = cpu->fpu[0u] - cpu->fpu[3u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[0u] - cpu->fpu[2u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x50u));
    cpu->fpu[3u] = cpu->fpu[3u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x54u)));
    *(float*)(cpu->esp + 0x48u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x58u)));
    *(float*)(cpu->esp + 0x4Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x4Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x48u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[4u] = cpu->fpu[4u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[6u] = cpu->fpu[6u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[5u] = cpu->fpu[0u] - cpu->fpu[5u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42C33Cu)); sfera_sub_004EE9EC(cpu, LIFT_CODE_TOKEN_VA(0x42C33Cu));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_x87_push(cpu, 1.0);
    cpu->fpu[1u] = cpu->fpu[0u] / cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0xCu)));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x10u)));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    lift_x87_push(cpu, 0.800000011920929);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esi) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x38u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esi + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esi + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esi + 0x70u) = cpu->fpu[0u];
    *(float*)(cpu->esi + 0x74u) = cpu->fpu[0u];
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[5u]; cpu->fpu[5u] = temporary; }
    cpu->fpu[6u] = cpu->fpu[0u] - cpu->fpu[6u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[5u]; cpu->fpu[5u] = temporary; }
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[0u] - cpu->fpu[2u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esi + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esi + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    *(float*)(cpu->esi + 0x78u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esi + 0x7Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x50u)));
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x54u)));
    *(float*)(cpu->esp + 0x48u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esp + 0x58u)));
    *(float*)(cpu->esp + 0x4Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x4Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x48u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[4u] = cpu->fpu[4u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[6u] = cpu->fpu[6u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[5u] = cpu->fpu[0u] - cpu->fpu[5u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42C48Cu)); sfera_sub_004EE9EC(cpu, LIFT_CODE_TOKEN_VA(0x42C48Cu));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_x87_push(cpu, 1.0);
    cpu->fpu[1u] = cpu->fpu[0u] / cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u];
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0xCu)));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x10u)));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    lift_x87_push(cpu, 0.800000011920929);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esi + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esi + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esi + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    *(float*)(cpu->esi + 0x80u) = cpu->fpu[0u];
    *(float*)(cpu->esi + 0x84u) = cpu->fpu[0u];
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[5u]; cpu->fpu[5u] = temporary; }
    cpu->fpu[6u] = cpu->fpu[6u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[5u]; cpu->fpu[5u] = temporary; }
    *(float*)(cpu->esi + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esi + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esi + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esi + 0x88u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esi + 0x8Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    label_0002C555:
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x58u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042C570(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42C59Fu)); sfera_sub_00425E30(cpu, LIFT_CODE_TOKEN_VA(0x42C59Fu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    *(float*)(cpu->esi + 0x64u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, (uintptr_t)"gazer.lake");
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x24u) = 0u;
    std::construct_at(reinterpret_cast<CGazerLakeEffect*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x5Cu) = 0u;
    *(uint32_t*)(cpu->esi + 0x60u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42C5CEu)); sfera_sub_00425EB0(cpu, LIFT_CODE_TOKEN_VA(0x42C5CEu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (0.10000000149011612);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x10u) = 0xC0u;
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFFFFFFFFu;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    *(uint8_t*)(cpu->esi + 0x54u) = 1u;
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = -cpu->fpu[0u];
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)-0.4000000059604645f);
    *(uint32_t*)(cpu->esi + 0x3Cu) = cpu->edx;
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esi + 0x44u) = cpu->ecx;
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)0.10000000149011612f);
    *(uint32_t*)(cpu->esi + 0x48u) = cpu->edx;
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esi + 0x4Cu) = cpu->eax;
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esi + 0x50u) = cpu->ecx;
    cpu->eax = cpu->esi + 0x68u;
    cpu->ecx = 0x10u;
    label_0002C660:
    *(uint32_t*)(cpu->eax) = 0u;
    cpu->eax += 0x14u;
    { uint64_t l=cpu->ecx, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002C660;
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042C690(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42C698u)); sfera_sub_0042B4A0(cpu, LIFT_CODE_TOKEN_VA(0x42C698u));
    if (((*(uint8_t*)(cpu->esp + 8u)) & (1u)) == 0u) goto label_0002C6A8;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42C6A5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42C6A5u));
    cpu->esp += 4u;
    label_0002C6A8:
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042C6B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->edx = 0x329u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Effects.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42C6E6u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42C6E6u));
    lift_push32(cpu, 0x1A8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42C6F0u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42C6F0u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    if (cpu->eax == 0u) goto label_0002C71D;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x60u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x64u));
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42C719u)); sfera_sub_0042C570(cpu, LIFT_CODE_TOKEN_VA(0x42C719u));
    cpu->ebp = cpu->eax;
    goto label_0002C71F;
    label_0002C71D:
    cpu->ebp = 0u;
    label_0002C71F:
    cpu->ecx = 0x2D9u;
    *(uint32_t*)(cpu->esp + 0x20u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42C731u)); sfera_sub_00425BD0(cpu, LIFT_CODE_TOKEN_VA(0x42C731u));
    cpu->edi = cpu->eax;
    if (cpu->edi == 0u) goto label_0002C75A;
    cpu->esi = cpu->ebp + 0x6Cu;
    cpu->ebx = 0x10u;
    (void)cpu;
    label_0002C740:
    cpu->ecx = cpu->edi;
    reinterpret_cast<IEffectManager*>(static_cast<uintptr_t>(cpu->edi))->createEffectResources(cpu);
    lift_x87_push(cpu, (double)-1.0f);
    *(float*)(cpu->esi) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esi + 0xFFFFFFFCu) = cpu->eax;
    cpu->esi += 0x14u;
    { uint64_t l=cpu->ebx, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002C740;
    label_0002C75A:
    cpu->eax = cpu->ebp;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042C770(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    std::construct_at(reinterpret_cast<CRainEffect*>(cpu->esi));
    { uint64_t l=*(uint32_t*)(cpu->esi + 0x60u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002C7C7;
    cpu->edx = 0x359u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Effects.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42C7BBu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42C7BBu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x60u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42C7C4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42C7C4u));
    cpu->esp += 4u;
    label_0002C7C7:
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42C7D6u)); sfera_sub_00425E70(cpu, LIFT_CODE_TOKEN_VA(0x42C7D6u));
    if (((*(uint8_t*)(cpu->esp + 0x1Cu)) & (1u)) == 0u) goto label_0002C7E6;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42C7E3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42C7E3u));
    cpu->esp += 4u;
    label_0002C7E6:
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042C800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xC0u;
    { uint64_t l=*(uint32_t*)(cpu->esp + 0xD0u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002CFA7;
    if (*(uint32_t*)(cpu->ebp + 0x5Cu) == 0xFFFFFFFFu) goto label_0002CFA7;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x58u);
    cpu->eax += g_sfera_effect_manager.render_slot_count;
    if (cpu->eax >= 0x2710u) goto label_0002CFA7;
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x6Cu));
    lift_push32(cpu, cpu->ebx);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ebp + 0x70u)));
    lift_push32(cpu, cpu->esi);
    *(uint16_t*)(cpu->esp + 0x1Cu) = cpu->fpu_control;
    cpu->eax = *(uint16_t*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax |= 0xC00u;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u));
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    lift_x87_push(cpu, cpu->fpu[0u]);
    lift_push32(cpu, cpu->edi);
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x24u);
    *(uint64_t*)(cpu->esp + 0x18u) = lift_x87_round(cpu, cpu->fpu[0u], 0u);
    lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u)))));
    if ((int32_t)cpu->ecx >= 0) goto label_0002C882;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)4294967296.0f));
    label_0002C882:
    cpu->fpu[1u] = cpu->fpu[1u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->ebp + 0x70u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (cpu->eax == 0u) goto label_0002CA11;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    label_0002C895:
    if (cpu->eax == 0u) goto label_0002CA11;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0x60u);
    cpu->ebx += cpu->ecx;
    if (((*(uint32_t*)(cpu->ebx + 0x14u)) & (0x80000000u)) == 0u) goto label_0002C9FE;
    cpu->esi = native_function_address32(&::rand);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x2C8B7u), LIFT_CODE_TOKEN_RVA(0x2C8B5u))) { return; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0518509447574615e-05);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (20.0);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (30.0);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    *(float*)(cpu->ebx + 0x18u) = cpu->fpu[0u];
    *(float*)(cpu->ebx + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x2C8E9u), LIFT_CODE_TOKEN_RVA(0x2C8E7u))) { return; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0518509447574615e-05);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_push(cpu, 0.02500000037252903);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->ebx + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x2C90Eu), LIFT_CODE_TOKEN_RVA(0x2C90Cu))) { return; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0518509447574615e-05);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_x87_push(cpu, 0.05999999865889549);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->ebx + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x2C933u), LIFT_CODE_TOKEN_RVA(0x2C931u))) { return; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0518509447574615e-05);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (6.283185958862305);
    *(float*)(cpu->esp + 0xC0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x2C958u), LIFT_CODE_TOKEN_RVA(0x2C956u))) { return; }
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.0518509447574615e-05);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (0.5);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.1415929794311523);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42C987u)); sfera_sub_004EE9F2(cpu, LIFT_CODE_TOKEN_VA(0x42C987u));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u));
    cpu->eax = cpu->esp + 0x40u;
    cpu->ecx = cpu->esp + 0x20u;
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ecx;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xC0u));
    lift_x87_sincos(cpu);
    *(float*)(cpu->esi) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->edi) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x64u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x68u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->ebx) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ebp + 0x64u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ebp + 0x68u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->ebx + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    --*(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    *(float*)(cpu->ebx + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    label_0002C9FE:
    cpu->ecx += 0x20u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)0x17700u) goto label_0002C895;
    label_0002CA11:
    lift_x87_push(cpu, 0.10000000149011612);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    cpu->ebx = 0x9Bu;
    label_0002CA22:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x60u);
    { uint64_t l=*(uint32_t*)(cpu->eax + cpu->edx + 0x14u), r=0x80000000u, v=l & r; lift_flags_logic(cpu,v,32u); }
    cpu->edi = cpu->eax + cpu->edx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002CF90;
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (2.0);
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    *(float*)(cpu->edi + 0x14u) = cpu->fpu[0u];
    cpu->fpu[0u] = (cpu->fpu[0u]) / (((double)*(float*)(cpu->edi + 0x18u)));
    lift_x87_push(cpu, 1.0);
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0xCu));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edi + 4u)));
    *(float*)(cpu->edi + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0002CA78;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->edi + 0x10u) = 0xC8u;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_0002CAA5;
    label_0002CA78:
    cpu->fpu[0u] = (cpu->fpu[0u]) * (200.0);
    *(uint16_t*)(cpu->esp + 0x20u) = cpu->fpu_control;
    cpu->eax = *(uint16_t*)(cpu->esp + 0x20u);
    cpu->fpu[1u] = cpu->fpu[0u] / cpu->fpu[1u]; lift_x87_pop(cpu);
    cpu->eax |= 0xC00u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x18u);
    *(uint64_t*)(cpu->esp + 0x18u) = lift_x87_round(cpu, cpu->fpu[0u], 0u);
    lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->eax;
    cpu->fpu_control = *(uint16_t*)(cpu->esp + 0x20u);
    label_0002CAA5:
    cpu->eax = g_sfera_effect_manager.render_slot_count;
    cpu->esi = cpu->eax;
    ++cpu->eax;
    g_sfera_effect_manager.render_slot_count = cpu->eax;
    if ((int32_t)cpu->esi >= 0) goto label_0002CAC0;
    cpu->ecx = (uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2CAC0u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x2CAC0u));
    label_0002CAC0:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_effect_manager.render_slots.capacity) goto label_0002CAD4;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)g_sfera_effect_manager.render_slots.debug_file;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2CAD4u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x2CAD4u));
    label_0002CAD4:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x5Cu);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x9Cu);
    cpu->esi += g_sfera_effect_manager.render_slots.data;
    *(uint32_t*)(cpu->esi + 0x90u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x98u) = 1u;
    *(uint32_t*)(cpu->esi + 0x94u) = 0u;
    cpu->eax = cpu->esi + 0x40u;
    cpu->ecx = 4u;
    label_0002CB05:
    *(uint32_t*)(cpu->eax + 0xFFFFFFF0u) = cpu->ebx;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ebx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x10u);
    *(uint32_t*)(cpu->eax + 0x20u) = cpu->edx;
    cpu->eax += 4u;
    { uint64_t l=cpu->ecx, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002CB05;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xD4u);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edi)));
    *(float*)(cpu->esp + 0x54u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edi + 4u)));
    *(float*)(cpu->esp + 0x58u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x58u);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 8u));
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->ecx;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax + 8u)));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x54u);
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->eax;
    *(float*)(cpu->esp + 0x5Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x5Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x58u));
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->edx;
    cpu->fpu[0u] = (cpu->fpu[0u]) - (4.0);
    *(float*)(cpu->esp + 0x4Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x1Cu));
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x48u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)g_sfera_effect_manager.viewer_position.x));
    *(float*)(cpu->esp + 0x78u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x4Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)g_sfera_effect_manager.viewer_position.y));
    *(float*)(cpu->esp + 0x7Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x50u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)g_sfera_effect_manager.viewer_position.z));
    *(float*)(cpu->esp + 0x80u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x7Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, 0.0);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x80u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, -1.0);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    lift_x87_push(cpu, cpu->fpu[4u]);
    cpu->fpu[2u] = cpu->fpu[0u] - cpu->fpu[2u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[3u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x78u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[5u] = cpu->fpu[5u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[4u] = cpu->fpu[0u] - cpu->fpu[4u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    cpu->fpu[3u] = cpu->fpu[0u] - cpu->fpu[3u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[4u]);
    lift_x87_push(cpu, cpu->fpu[3u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x38u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[5u] = cpu->fpu[5u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[3u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[3u]);
    cpu->fpu[5u] = cpu->fpu[5u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[3u]);
    cpu->fpu[5u] = cpu->fpu[5u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    cpu->fpu[4u] = cpu->fpu[0u] - cpu->fpu[4u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)9.999999747378752e-06f);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0002CC92;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    *(float*)(cpu->esp + 0xA8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xA8u);
    *(float*)(cpu->esp + 0xACu) = cpu->fpu[0u];
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(float*)(cpu->esp + 0xB0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xACu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xB0u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edx;
    goto label_0002CCF3;
    label_0002CC92:
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    cpu->ecx = 0x5F3759DFu;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.5);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax >>= 1u;
    cpu->ecx -= cpu->eax;
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.5);
    cpu->fpu[2u] = cpu->fpu[0u] - cpu->fpu[2u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x2Cu)));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0002CCF3:
    lift_x87_push(cpu, cpu->fpu[1u]);
    lift_x87_push(cpu, cpu->fpu[3u]);
    lift_x87_push(cpu, cpu->fpu[5u]);
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0002CD60;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[2u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    *(float*)(cpu->esp + 0x90u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esp + 0x90u);
    *(float*)(cpu->esp + 0x94u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x94u);
    *(float*)(cpu->esp + 0x98u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x98u);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    goto label_0002CDB7;
    label_0002CD60:
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u];
    cpu->eax = 0x5F3759DFu;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.5);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx >>= 1u;
    cpu->eax -= cpu->edx;
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.5);
    cpu->fpu[2u] = cpu->fpu[0u] - cpu->fpu[2u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0002CDB7:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u];
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x28u)));
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x2Cu)));
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x30u)));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x34u)));
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x38u)));
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x3Cu)));
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x48u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x28u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x60u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x4Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x64u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x50u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x68u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[5u]; cpu->fpu[5u] = temporary; }
    cpu->fpu[4u] = cpu->fpu[4u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    *(float*)(cpu->esp + 0x9Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xA0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xA4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x60u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x6Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x6Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x64u));
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x38u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x70u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x70u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x68u));
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x74u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x74u);
    lift_x87_push(cpu, cpu->fpu[4u]);
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    cpu->fpu[6u] = cpu->fpu[6u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[5u]; cpu->fpu[5u] = temporary; }
    *(float*)(cpu->esp + 0x84u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x84u);
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ecx;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(float*)(cpu->esp + 0x88u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x88u);
    lift_x87_push(cpu, cpu->fpu[3u]);
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edx;
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x8Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x8Cu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x9Cu));
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->eax;
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[3u]);
    *(float*)(cpu->esp + 0xB4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xB4u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xA0u));
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ecx;
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[3u]);
    *(float*)(cpu->esp + 0xB8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xB8u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xA4u));
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->edx;
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (cpu->fpu[6u]);
    *(float*)(cpu->esp + 0xBCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xBCu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->eax;
    cpu->fpu[4u] = cpu->fpu[0u] - cpu->fpu[4u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    *(float*)(cpu->esp + 0xC4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xC4u);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->ecx;
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xC8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xC8u);
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->edx;
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xCCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCCu);
    lift_x87_push(cpu, 0.10000000149011612);
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    label_0002CF90:
    cpu->eax += 0x20u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)0x17700u) goto label_0002CA22;
    cpu->edi = lift_pop32(cpu);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0002CFA7:
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xC0u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042CFC0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    (void)0; /* source SEH registration eliminated */
    cpu->edx = 0x3C7u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Effects.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42CFF1u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42CFF1u));
    lift_push32(cpu, 0x74u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42CFF8u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42CFF8u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if (cpu->eax == 0u) goto label_0002D016;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D012u)); sfera_sub_0042B720(cpu, LIFT_CODE_TOKEN_VA(0x42D012u));
    cpu->esi = cpu->eax;
    goto label_0002D018;
    label_0002D016:
    cpu->esi = 0u;
    label_0002D018:
    cpu->ecx = (uintptr_t)"fx_rain";
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D02Au)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x42D02Au));
    *(uint32_t*)(cpu->esi + 0x5Cu) = cpu->eax;
    if (cpu->eax != 0xFFFFFFFFu) goto label_0002D045;
    lift_push32(cpu, (uintptr_t)"CRainEffect::Texture not found 'fx_rain'");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D03Cu)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x42D03Cu));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D042u)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x42D042u));
    cpu->esp += 8u;
    label_0002D045:
    cpu->edx = 0x3CEu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\Effects.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D054u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42D054u));
    lift_push32(cpu, 0x17700u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D05Eu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42D05Eu));
    lift_x87_push(cpu, (double)-1.0f);
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x60u) = cpu->eax;
    cpu->eax = 0u;
    label_0002D06C:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x60u);
    *(float*)(cpu->ecx + cpu->eax + 0x14u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x60u);
    *(float*)(cpu->edx + cpu->eax + 0x34u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x60u);
    *(float*)(cpu->ecx + cpu->eax + 0x54u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x60u);
    *(float*)(cpu->edx + cpu->eax + 0x74u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x60u);
    *(float*)(cpu->ecx + cpu->eax + 0x94u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x60u);
    *(float*)(cpu->edx + cpu->eax + 0xB4u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x60u);
    *(float*)(cpu->ecx + cpu->eax + 0xD4u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x60u);
    *(float*)(cpu->edx + cpu->eax + 0xF4u) = cpu->fpu[0u];
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x60u);
    *(float*)(cpu->ecx + cpu->eax + 0x114u) = cpu->fpu[0u];
    cpu->edx = *(uint32_t*)(cpu->esi + 0x60u);
    *(float*)(cpu->edx + cpu->eax + 0x134u) = cpu->fpu[0u];
    cpu->eax += 0x140u;
    if ((int32_t)cpu->eax < (int32_t)0x17700u) goto label_0002D06C;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042D0F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042D100(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi) == 0u) goto label_0002D122;
    cpu->edx = 0x46u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectTrack.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D117u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42D117u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D11Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42D11Fu));
    cpu->esp += 4u;
    label_0002D122:
    *(uint32_t*)(cpu->esi) = 0u;
    *(uint32_t*)(cpu->esi + 4u) = 0u;
    *(uint32_t*)(cpu->esi + 8u) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042D140(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->eax + (cpu->eax * 2u);
    cpu->esi <<= 4u;
    cpu->esi += *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = 0xCu;
    lift_movs32(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042D160(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->eax + (cpu->eax * 2u);
    cpu->edi <<= 4u;
    cpu->edi += *(uint32_t*)(cpu->ecx);
    cpu->ecx = 0xCu;
    lift_movs32(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042D180(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    { uint64_t l=cpu->edx, r=1u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0002D262;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx);
    cpu->eax = cpu->edx + (cpu->edx * 2u);
    cpu->eax += cpu->eax;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + (cpu->eax * 8u) + 0xFFFFFFD0u));
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esi + (cpu->eax * 8u) + 0xFFFFFFD0u;
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x41u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0002D1C6;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x18u);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x1Cu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x20u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0002D1C6:
    { uint64_t l=cpu->edx, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_0002D1E6;
    cpu->edi = cpu->edx + (cpu->edx * 2u);
    cpu->edi <<= 4u;
    cpu->edi += cpu->esi;
    label_0002D1D1:
    lift_x87_push(cpu, (double)*(float*)(cpu->edi));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x41u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0002D1E4;
    cpu->edi -= 0x30u;
    { uint64_t l=cpu->edx, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0002D1D1;
    goto label_0002D1E6;
    label_0002D1E4:
    cpu->esi = cpu->edi;
    label_0002D1E6:
    { uint64_t l=*(uint8_t*)(cpu->ecx + 8u), r=1u, v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi)));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x30u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi)));
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002D226;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.1415929794311523);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D210u)); sfera_sub_004EE9F2(cpu, LIFT_CODE_TOKEN_VA(0x42D210u));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    lift_x87_push(cpu, 1.0);
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.5);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0002D226:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x48u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi + 0x18u)));
    cpu->edi = lift_pop32(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x18u));
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->eax) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x4Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi + 0x1Cu)));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x1Cu)));
    *(float*)(cpu->eax + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x50u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi + 0x20u)));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x20u)));
    cpu->esi = lift_pop32(cpu);
    *(float*)(cpu->eax + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0002D262:
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002D27E;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x1Cu);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x20u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0002D27E:
    lift_x87_push(cpu, 0.0);
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    *(float*)(cpu->eax + 8u) = cpu->fpu[0u];
    *(float*)(cpu->eax + 4u) = cpu->fpu[0u];
    *(float*)(cpu->eax) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042D290(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ebx = 1u;
    { uint64_t l=cpu->esi, r=cpu->ebx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0002D3D5;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    cpu->eax = cpu->esi + (cpu->esi * 2u);
    cpu->eax += cpu->eax;
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + (cpu->eax * 8u) + 0xFFFFFFD0u));
    cpu->ecx = cpu->edx + (cpu->eax * 8u) + 0xFFFFFFD0u;
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x41u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0002D310;
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((uint8_t)((*(uint8_t*)(cpu->ecx + 4u)) & ((cpu->ebx & 0xFFu))) == 0u) goto label_0002D2FF;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = *(uint16_t*)(cpu->edx + (cpu->esi * 2u) + 0xFFFFFFFEu);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (1.5259021893143654e-05);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ecx + 0xCu)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ecx + 8u)));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->ecx) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
    label_0002D2FF:
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 8u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esi = lift_pop32(cpu);
    *(float*)(cpu->edx) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
    label_0002D310:
    cpu->ecx = cpu->esi + 0xFFFFFFFFu;
    { uint64_t v=cpu->ecx; lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_0002D335;
    cpu->esi = cpu->ecx + (cpu->ecx * 2u);
    cpu->esi <<= 4u;
    cpu->esi += cpu->edx;
    label_0002D31F:
    lift_x87_push(cpu, (double)*(float*)(cpu->esi));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x41u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0002D333;
    cpu->esi -= 0x30u;
    { uint64_t l=cpu->ecx, r=cpu->ebx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0002D31F;
    goto label_0002D335;
    label_0002D333:
    cpu->edx = cpu->esi;
    label_0002D335:
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->edx)));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0x30u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->edx)));
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 8u));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0x38u));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.5259021893143654e-05);
    if ((uint8_t)((*(uint8_t*)(cpu->edx + 4u)) & ((cpu->ebx & 0xFFu))) == 0u) goto label_0002D388;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint16_t*)(cpu->eax + (cpu->ecx * 2u));
    cpu->edi += cpu->esi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x24u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->edx + 0xCu)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 8u)));
    *(float*)(cpu->esp + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0002D388:
    if ((uint8_t)((*(uint8_t*)(cpu->edx + 0x34u)) & ((cpu->ebx & 0xFFu))) == 0u) goto label_0002D3B1;
    cpu->eax = *(uint16_t*)(cpu->eax + (cpu->ecx * 2u) + 2u);
    cpu->eax += cpu->esi;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) * ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x24u)))));
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x24u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->edx + 0x3Cu)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_0002D3B3;
    label_0002D3B1:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0002D3B3:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    cpu->esi = lift_pop32(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->ebx = lift_pop32(cpu);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->ecx) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
    label_0002D3D5:
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002D417;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if ((uint8_t)((*(uint8_t*)(cpu->ecx + 4u)) & ((cpu->ebx & 0xFFu))) == 0u) goto label_0002D2FF;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = *(uint16_t*)(cpu->edx);
    cpu->eax += *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x1Cu)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (1.5259021893143654e-05);
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x1Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ecx + 0xCu)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ecx + 8u)));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->ecx) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
    label_0002D417:
    lift_x87_push(cpu, 0.0);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esi = lift_pop32(cpu);
    *(float*)(cpu->eax) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042D430(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint64_t l=cpu->edx, r=1u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0002D8A0;
    cpu->esi = *(uint32_t*)(cpu->ecx);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x34u));
    cpu->eax = cpu->edx + (cpu->edx * 2u);
    cpu->eax += cpu->eax;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + (cpu->eax * 8u) + 0xFFFFFFD0u));
    cpu->edi = cpu->esi + (cpu->eax * 8u) + 0xFFFFFFD0u;
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x41u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0002D5BC;
    { uint64_t l=*(uint8_t*)(cpu->edi + 4u), r=1u, v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002D593;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->esi = cpu->edx;
    cpu->ecx = *(uint16_t*)(cpu->ebp + (cpu->esi * 2u) + 0xFFFFFFFEu);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->edx = *(uint8_t*)(cpu->edi + 0x14u);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x44u)))));
    lift_x87_push(cpu, 1.5259021893143654e-05);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x44u)))));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D4ABu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x42D4ABu));
    cpu->ecx = *(uint16_t*)(cpu->ebp + (cpu->esi * 2u));
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->edx = *(uint8_t*)(cpu->edi + 0x15u);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ecx;
    cpu->ebx = cpu->eax;
    cpu->eax = *(uint8_t*)(cpu->edi + 0x10u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x44u)))));
    cpu->ebx += cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x44u)))));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D4E1u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x42D4E1u));
    cpu->edx = *(uint16_t*)(cpu->ebp + (cpu->esi * 2u) + 2u);
    cpu->edx += *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->ecx = *(uint8_t*)(cpu->edi + 0x11u);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edx;
    cpu->eax += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x44u)))));
    cpu->eax = *(uint8_t*)(cpu->edi + 0x16u);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x44u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x44u));
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x44u)))));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D519u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x42D519u));
    cpu->edx = *(uint16_t*)(cpu->ebp + (cpu->esi * 2u) + 4u);
    cpu->edx += *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->ecx = *(uint8_t*)(cpu->edi + 0x12u);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    cpu->eax += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) * ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    cpu->eax = *(uint8_t*)(cpu->edi + 0x17u);
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D54Fu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x42D54Fu));
    cpu->ecx = *(uint8_t*)(cpu->edi + 0x13u);
    cpu->ebp = 0xFFu;
    cpu->eax += cpu->ecx;
    if ((int32_t)cpu->ebx < (int32_t)cpu->ebp) goto label_0002D560;
    cpu->ebx = cpu->ebp;
    label_0002D560:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint8_t*)(cpu->edx) = cpu->ebx & 0xFFu;
    if ((int32_t)cpu->ecx < (int32_t)cpu->ebp) goto label_0002D570;
    cpu->ecx = cpu->ebp;
    label_0002D570:
    *(uint8_t*)(cpu->edx + 1u) = cpu->ecx & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    label_0002D577:
    if ((int32_t)cpu->ecx < (int32_t)cpu->ebp) goto label_0002D57D;
    cpu->ecx = cpu->ebp;
    label_0002D57D:
    *(uint8_t*)(cpu->edx + 2u) = cpu->ecx & 0xFFu;
    if ((int32_t)cpu->eax < (int32_t)cpu->ebp) goto label_0002D586;
    cpu->eax = cpu->ebp;
    label_0002D586:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->edx + 3u) = cpu->eax & 0xFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
    label_0002D593:
    cpu->edx = *(uint8_t*)(cpu->edi + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint8_t*)(cpu->eax) = cpu->edx & 0xFFu;
    cpu->ecx = *(uint8_t*)(cpu->edi + 0x11u);
    *(uint8_t*)(cpu->eax + 1u) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint8_t*)(cpu->edi + 0x12u);
    *(uint8_t*)(cpu->eax + 2u) = cpu->edx & 0xFFu;
    cpu->ecx = *(uint8_t*)(cpu->edi + 0x13u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 3u) = cpu->ecx & 0xFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
    label_0002D5BC:
    cpu->edi = cpu->edx + 0xFFFFFFFFu;
    cpu->edx = 0u;
    { uint64_t l=cpu->edi, r=cpu->edx, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0002D5E4;
    cpu->ecx = cpu->edi + (cpu->edi * 2u);
    cpu->ecx <<= 4u;
    cpu->ecx += cpu->esi;
    label_0002D5CD:
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x41u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0002D5E2;
    --cpu->edi;
    cpu->ecx -= 0x30u;
    if ((int32_t)cpu->edi >= (int32_t)cpu->edx) goto label_0002D5CD;
    goto label_0002D5E4;
    label_0002D5E2:
    cpu->esi = cpu->ecx;
    label_0002D5E4:
    { uint64_t l=*(uint8_t*)(cpu->esi + 4u), r=1u, v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi)));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x30u));
    cpu->edx = *(uint8_t*)(cpu->esi + 0x10u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi)));
    cpu->eax = *(uint8_t*)(cpu->esi + 0x11u);
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x12u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x44u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    cpu->edx = *(uint8_t*)(cpu->esi + 0x13u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    cpu->eax = *(uint8_t*)(cpu->esi + 0x40u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x41u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    cpu->edx = *(uint8_t*)(cpu->esi + 0x42u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    cpu->eax = *(uint8_t*)(cpu->esi + 0x43u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.5259021893143654e-05);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002D709;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->ecx = *(uint16_t*)(cpu->ebp + (cpu->edi * 2u));
    cpu->edx = *(uint8_t*)(cpu->esi + 0x14u);
    cpu->ecx += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D675u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x42D675u));
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->eax = *(uint16_t*)(cpu->ebp + (cpu->edi * 2u) + 2u);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x15u);
    cpu->eax += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D6A5u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x42D6A5u));
    cpu->edx = *(uint16_t*)(cpu->ebp + (cpu->edi * 2u) + 4u);
    *(uint32_t*)(cpu->esp + 0x18u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x18u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->eax = *(uint8_t*)(cpu->esi + 0x16u);
    cpu->edx += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D6D5u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x42D6D5u));
    cpu->ecx = *(uint16_t*)(cpu->ebp + (cpu->edi * 2u) + 6u);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x17u);
    *(uint32_t*)(cpu->esp + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x20u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->ecx += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D705u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x42D705u));
    *(uint32_t*)(cpu->esp + 0x28u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x28u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    label_0002D709:
    if (((*(uint8_t*)(cpu->esi + 0x34u)) & (1u)) == 0u) goto label_0002D7D7;
    cpu->eax = *(uint16_t*)(cpu->ebp + (cpu->edi * 2u) + 2u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x44u);
    cpu->eax += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D743u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x42D743u));
    cpu->edx = *(uint16_t*)(cpu->ebp + (cpu->edi * 2u) + 4u);
    *(uint32_t*)(cpu->esp + 0x34u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x34u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->eax = *(uint8_t*)(cpu->esi + 0x45u);
    cpu->edx += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D773u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x42D773u));
    cpu->ecx = *(uint16_t*)(cpu->ebp + (cpu->edi * 2u) + 6u);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x46u);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->ecx += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D7A3u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x42D7A3u));
    *(uint32_t*)(cpu->esp + 0x1Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x1Cu)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->eax = *(uint16_t*)(cpu->ebp + (cpu->edi * 2u) + 8u);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x47u);
    cpu->eax += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) * ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D7D1u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x42D7D1u));
    *(uint32_t*)(cpu->esp + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x24u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    goto label_0002D7D9;
    label_0002D7D7:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0002D7D9:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (255.0);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D7E8u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x42D7E8u));
    cpu->ebp = 0xFFu;
    cpu->esi = cpu->eax;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x10u) <= (int32_t)cpu->ebp) goto label_0002D7F9;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebp;
    label_0002D7F9:
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x18u) <= (int32_t)cpu->ebp) goto label_0002D803;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    label_0002D803:
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x20u) <= (int32_t)cpu->ebp) goto label_0002D80D;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebp;
    label_0002D80D:
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x28u) <= (int32_t)cpu->ebp) goto label_0002D817;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebp;
    label_0002D817:
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x34u) <= (int32_t)cpu->ebp) goto label_0002D821;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebp;
    label_0002D821:
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x14u) <= (int32_t)cpu->ebp) goto label_0002D82B;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    label_0002D82B:
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x1Cu) <= (int32_t)cpu->ebp) goto label_0002D835;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    label_0002D835:
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x24u) <= (int32_t)cpu->ebp) goto label_0002D83F;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebp;
    label_0002D83F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    { uint64_t l=cpu->edx, r=cpu->eax, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    { int64_t v=(int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->esi); cpu->edx= v; uint32_t ov= (int64_t)(int32_t)v != v; cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->edx = (int32_t)(cpu->edx) >> 8u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint8_t*)(cpu->ecx) = cpu->edx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    { uint64_t l=cpu->edx, r=cpu->eax, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    { int64_t v=(int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->esi); cpu->edx= v; uint32_t ov= (int64_t)(int32_t)v != v; cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->edx = (int32_t)(cpu->edx) >> 8u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint8_t*)(cpu->ecx + 1u) = cpu->edx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    { uint64_t l=cpu->edx, r=cpu->eax, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    { int64_t v=(int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->esi); cpu->edx= v; uint32_t ov= (int64_t)(int32_t)v != v; cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->edx = (int32_t)(cpu->edx) >> 8u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint8_t*)(cpu->ecx + 2u) = cpu->edx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    { uint64_t l=cpu->edx, r=cpu->eax, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    { int64_t v=(int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(cpu->esi); cpu->edx= v; uint32_t ov= (int64_t)(int32_t)v != v; cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->edx = (int32_t)(cpu->edx) >> 8u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->ecx + 3u) = cpu->edx & 0xFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
    label_0002D8A0:
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002D9DD;
    cpu->esi = *(uint32_t*)(cpu->ecx);
    if (((*(uint8_t*)(cpu->esi + 4u)) & (1u)) == 0u) goto label_0002D9B4;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->eax = *(uint16_t*)(cpu->ebx);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x14u);
    cpu->eax += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    lift_x87_push(cpu, 1.5259021893143654e-05);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D8ECu)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x42D8ECu));
    cpu->edi = *(uint8_t*)(cpu->esi + 0x10u);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x15u);
    cpu->edi += cpu->eax;
    cpu->eax = *(uint16_t*)(cpu->ebx + 2u);
    cpu->eax += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D91Du)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x42D91Du));
    cpu->edx = *(uint8_t*)(cpu->esi + 0x11u);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x16u);
    cpu->eax += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->eax;
    cpu->eax = *(uint16_t*)(cpu->ebx + 4u);
    cpu->eax += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D952u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x42D952u));
    cpu->edx = *(uint8_t*)(cpu->esi + 0x12u);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x17u);
    cpu->eax += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    cpu->eax = *(uint16_t*)(cpu->ebx + 6u);
    cpu->eax += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    cpu->fpu[0u] = (cpu->fpu[0u]) * ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    *(float*)(cpu->esp + 0x3Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x3Cu));
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42D985u)); sfera_sub_004EE940(cpu, LIFT_CODE_TOKEN_VA(0x42D985u));
    cpu->edx = *(uint8_t*)(cpu->esi + 0x13u);
    cpu->ebp = 0xFFu;
    cpu->eax += cpu->edx;
    cpu->ecx = cpu->edi;
    if ((int32_t)cpu->edi < (int32_t)cpu->ebp) goto label_0002D998;
    cpu->ecx = cpu->ebp;
    label_0002D998:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint8_t*)(cpu->edx) = cpu->ecx & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    if ((int32_t)cpu->ecx < (int32_t)cpu->ebp) goto label_0002D9A8;
    cpu->ecx = cpu->ebp;
    label_0002D9A8:
    *(uint8_t*)(cpu->edx + 1u) = cpu->ecx & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    goto label_0002D577;
    label_0002D9B4:
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint8_t*)(cpu->eax) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint8_t*)(cpu->esi + 0x11u);
    *(uint8_t*)(cpu->eax + 1u) = cpu->edx & 0xFFu;
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x12u);
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 2u) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint8_t*)(cpu->esi + 0x13u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + 3u) = cpu->edx & 0xFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
    label_0002D9DD:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->edx = 0u;
    cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042D9F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    { uint64_t l=cpu->edi, r=1u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0002DE96;
    cpu->esi = *(uint32_t*)(cpu->ecx);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x2Cu));
    cpu->eax = cpu->edi + (cpu->edi * 2u);
    cpu->eax += cpu->eax;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + (cpu->eax * 8u) + 0xFFFFFFD0u));
    cpu->edx = cpu->esi + (cpu->eax * 8u) + 0xFFFFFFD0u;
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ebp);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | (((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x41u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0002DB7F;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_0002DAB7;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->ecx = cpu->edi;
    cpu->esi = *(uint16_t*)(cpu->eax + (cpu->ecx * 2u));
    cpu->eax = cpu->eax + (cpu->ecx * 2u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->esi += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->esi;
    cpu->esi = *(uint16_t*)(cpu->eax + 2u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u)))));
    lift_x87_push(cpu, 1.5259021893143654e-05);
    cpu->eax = *(uint16_t*)(cpu->eax + 0xFFFFFFFEu);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    cpu->esi += cpu->ecx;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->esi;
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax += cpu->ecx;
    cpu->ebp = lift_pop32(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edi = lift_pop32(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x30u)))));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->edx + 0x24u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edx + 0x18u)));
    *(float*)(cpu->eax) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0x28u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x28u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edx + 0x1Cu)));
    *(float*)(cpu->eax + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0x2Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x2Cu)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edx + 0x20u)));
    *(float*)(cpu->eax + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
    label_0002DAB7:
    if ((((cpu->eax & 0xFFu)) & (2u)) == 0u) goto label_0002DB60;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->eax = cpu->edi;
    cpu->esi = *(uint16_t*)(cpu->ecx + (cpu->eax * 2u) + 4u);
    cpu->ebx = *(uint16_t*)(cpu->ecx + (cpu->eax * 2u) + 2u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->ebp = *(uint16_t*)(cpu->ecx + (cpu->eax * 2u) + 6u);
    cpu->ebx -= cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->ebx -= cpu->esi;
    cpu->ebx += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ebx;
    cpu->ebx = *(uint16_t*)(cpu->ecx + (cpu->eax * 2u) + 8u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u)))));
    lift_x87_push(cpu, 1.5259021893143654e-05);
    cpu->ebp -= cpu->ebx;
    cpu->ebx = *(uint16_t*)(cpu->ecx + (cpu->eax * 2u) + 0xFFFFFFFEu);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->ecx = *(uint16_t*)(cpu->ecx + (cpu->eax * 2u));
    *(float*)(cpu->esp + 0x38u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ebp -= cpu->esi;
    cpu->ebp += cpu->edi;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ebp;
    cpu->ebx -= cpu->ecx;
    cpu->ebx -= cpu->esi;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u)))));
    cpu->ebx += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ebx;
    cpu->ebp = lift_pop32(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x30u)))));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->edx + 0x24u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edx + 0x18u)));
    *(float*)(cpu->eax) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0x28u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x28u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edx + 0x1Cu)));
    *(float*)(cpu->eax + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0x2Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x2Cu)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edx + 0x20u)));
    *(float*)(cpu->eax + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
    label_0002DB60:
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x1Cu);
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edx + 0x20u);
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
    label_0002DB7F:
    cpu->edx = cpu->edi + 0xFFFFFFFFu;
    { uint64_t v=cpu->edx; lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_0002DBA3;
    cpu->edi = cpu->edx + (cpu->edx * 2u);
    cpu->edi <<= 4u;
    cpu->edi += cpu->esi;
    label_0002DB8E:
    lift_x87_push(cpu, (double)*(float*)(cpu->edi));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x41u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0002DBA1;
    cpu->edi -= 0x30u;
    { uint64_t l=cpu->edx, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0002DB8E;
    goto label_0002DBA3;
    label_0002DBA1:
    cpu->esi = cpu->edi;
    label_0002DBA3:
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi)));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x30u));
    cpu->ebx = *(uint32_t*)(cpu->esi + 4u);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi)));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x48u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x4Cu);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x50u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.5259021893143654e-05);
    if ((((cpu->ebx & 0xFFu)) & (1u)) == 0u) goto label_0002DC5B;
    cpu->edi = *(uint16_t*)(cpu->eax + (cpu->edx * 2u));
    cpu->edi += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->edi;
    cpu->edi = *(uint16_t*)(cpu->eax + (cpu->edx * 2u) + 2u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u)))));
    cpu->edi += cpu->ebp;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->edi;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x24u)));
    cpu->edi = *(uint16_t*)(cpu->eax + (cpu->edx * 2u) + 4u);
    cpu->edi += cpu->ebp;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->edi;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x28u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x24u)));
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x2Cu)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x28u)));
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0002DC5B:
    { uint64_t l=*(uint8_t*)(cpu->esi + 0x34u), r=1u, v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->edi = *(uint32_t*)(cpu->esp + 0x3Cu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002DCD5;
    cpu->ecx = *(uint16_t*)(cpu->eax + (cpu->edx * 2u) + 2u);
    cpu->ecx += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ecx;
    cpu->ecx = *(uint16_t*)(cpu->eax + (cpu->edx * 2u) + 4u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u)))));
    cpu->ecx += cpu->edi;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ecx;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x54u)));
    cpu->ecx = *(uint16_t*)(cpu->eax + (cpu->edx * 2u) + 6u);
    cpu->ecx += cpu->edi;
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ecx;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x58u)));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x5Cu)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0002DCD5:
    if ((((cpu->ebx & 0xFFu)) & (2u)) == 0u) goto label_0002DD68;
    cpu->ecx = *(uint16_t*)(cpu->eax + (cpu->edx * 2u) + 2u);
    cpu->ebx = *(uint16_t*)(cpu->eax + (cpu->edx * 2u));
    cpu->ebx -= cpu->ecx;
    cpu->ecx = *(uint16_t*)(cpu->eax + (cpu->edx * 2u) + 6u);
    cpu->ebx -= cpu->edi;
    cpu->ebx += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ebx;
    cpu->ebx = *(uint16_t*)(cpu->eax + (cpu->edx * 2u) + 4u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u)))));
    cpu->ebx -= cpu->ecx;
    cpu->ecx = *(uint16_t*)(cpu->eax + (cpu->edx * 2u) + 0xAu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    cpu->ebx -= cpu->edi;
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ebx += cpu->ebp;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ebx;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x24u)));
    cpu->ebx = *(uint16_t*)(cpu->eax + (cpu->edx * 2u) + 8u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x20u)));
    cpu->ebx -= cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx -= cpu->edi;
    *(float*)(cpu->esp + 0x20u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ebx += cpu->ebp;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ebx;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x28u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x24u)));
    *(float*)(cpu->esp + 0x24u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u)))));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x2Cu)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x28u)));
    *(float*)(cpu->esp + 0x28u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0002DD68:
    if (((*(uint8_t*)(cpu->esi + 0x34u)) & (2u)) == 0u) goto label_0002DDFD;
    cpu->ebx = *(uint16_t*)(cpu->eax + (cpu->edx * 2u) + 4u);
    cpu->ecx = *(uint16_t*)(cpu->eax + (cpu->edx * 2u) + 0xAu);
    cpu->ecx -= cpu->ebx;
    cpu->ebx = *(uint16_t*)(cpu->eax + (cpu->edx * 2u) + 2u);
    cpu->ecx -= cpu->edi;
    cpu->ecx += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ecx;
    cpu->ecx = *(uint16_t*)(cpu->eax + (cpu->edx * 2u) + 6u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u)))));
    cpu->ecx -= cpu->ebx;
    cpu->ecx -= cpu->edi;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    cpu->ecx += cpu->ebp;
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ecx;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x54u)));
    cpu->ecx = *(uint16_t*)(cpu->eax + (cpu->edx * 2u) + 0xCu);
    cpu->edx = *(uint16_t*)(cpu->eax + (cpu->edx * 2u) + 8u);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x14u)));
    cpu->edx -= cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx -= cpu->edi;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u)))));
    cpu->edx += cpu->ebp;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->edx;
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x58u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u)))));
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x5Cu)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(float*)(cpu->esp + 0x1Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    goto label_0002DDFF;
    label_0002DDFD:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    label_0002DDFF:
    if (((*(uint8_t*)(cpu->ecx + 8u)) & (1u)) == 0u) goto label_0002DE44;
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (3.1415929794311523);
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42DE1Cu)); sfera_sub_004EE9F2(cpu, LIFT_CODE_TOKEN_VA(0x42DE1Cu));
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    lift_x87_push(cpu, 1.0);
    cpu->fpu[1u] = cpu->fpu[0u] - cpu->fpu[1u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (0.5);
    *(float*)(cpu->esp + 0x40u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x40u));
    goto label_0002DE54;
    label_0002DE44:
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x20u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    label_0002DE54:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ebp = lift_pop32(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ebx = lift_pop32(cpu);
    *(float*)(cpu->eax) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->eax + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->eax + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
    label_0002DE96:
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002DFE1;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    if ((((cpu->ecx & 0xFFu)) & (1u)) == 0u) goto label_0002DF22;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->esi = *(uint16_t*)(cpu->ecx + 2u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->esi += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->esi;
    cpu->esi = *(uint16_t*)(cpu->ecx + 4u);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    lift_x87_push(cpu, 1.5259021893143654e-05);
    cpu->ecx = *(uint16_t*)(cpu->ecx);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    cpu->esi += cpu->edx;
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->esi;
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx += cpu->edx;
    cpu->edi = lift_pop32(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x38u)))));
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->esi = lift_pop32(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    cpu->ebx = lift_pop32(cpu);
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x30u)))));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->eax + 0x24u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax + 0x18u)));
    *(float*)(cpu->ecx) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x28u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x28u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax + 0x1Cu)));
    *(float*)(cpu->ecx + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x2Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x2Cu)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax + 0x20u)));
    *(float*)(cpu->ecx + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
    label_0002DF22:
    if ((((cpu->ecx & 0xFFu)) & (2u)) == 0u) goto label_0002DFC3;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->edx = *(uint16_t*)(cpu->ecx + 6u);
    cpu->edi = *(uint16_t*)(cpu->ecx + 4u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->ebx = *(uint16_t*)(cpu->ecx + 8u);
    cpu->edi -= cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->edi -= cpu->edx;
    cpu->edi += cpu->esi;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edi;
    cpu->edi = *(uint16_t*)(cpu->ecx + 0xAu);
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    lift_x87_push(cpu, 1.5259021893143654e-05);
    cpu->ebx -= cpu->edi;
    cpu->edi = *(uint16_t*)(cpu->ecx + 2u);
    cpu->fpu[1u] = (cpu->fpu[1u]) * (cpu->fpu[0u]);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->ecx = *(uint16_t*)(cpu->ecx);
    *(float*)(cpu->esp + 0x34u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ebx -= cpu->edx;
    cpu->ebx += cpu->esi;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ebx;
    cpu->ecx -= cpu->edi;
    cpu->ecx -= cpu->edx;
    lift_x87_push(cpu, (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    cpu->ecx += cpu->esi;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[1u]);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    *(float*)(cpu->esp + 0x2Cu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x30u)))));
    *(float*)(cpu->esp + 0x30u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x30u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->eax + 0x24u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax + 0x18u)));
    *(float*)(cpu->ecx) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x28u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x28u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax + 0x1Cu)));
    *(float*)(cpu->ecx + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x2Cu));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esp + 0x2Cu)));
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->eax + 0x20u)));
    *(float*)(cpu->ecx + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
    label_0002DFC3:
    cpu->edx = *(uint32_t*)(cpu->eax + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x1Cu);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x20u);
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
    label_0002DFE1:
    lift_x87_push(cpu, 0.0);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->eax + 8u) = cpu->fpu[0u];
    cpu->esi = lift_pop32(cpu);
    *(float*)(cpu->eax + 4u) = cpu->fpu[0u];
    *(float*)(cpu->eax) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E000(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=*(uint32_t*)(cpu->esi), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002E030;
    cpu->edx = 0x55u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectTrack.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E018u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42E018u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E020u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42E020u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi) = 0u;
    *(uint32_t*)(cpu->esi + 4u) = 0u;
    label_0002E030:
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->edi == 0u) goto label_0002E077;
    cpu->edx = 0x5Cu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\EffectTrack.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E047u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42E047u));
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->edi;
    cpu->edx = 0x30u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E05Fu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42E05Fu));
    cpu->ecx = cpu->edi * 4u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x42E06Fu));
    cpu->esp += 0x10u;
    label_0002E077:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E080(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x174u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x17Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u); lift_push32(cpu, 2u);
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::CreateToolhelp32Snapshot), LIFT_CODE_TOKEN_VA(0x42E0A4u));
    cpu->edi = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edi;
    if (cpu->edi == 0xFFFFFFFFu) goto label_0002E0D2;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0x128u;
    lift_native_call(cpu, native_function_address32(&::Process32First), LIFT_CODE_TOKEN_VA(0x42E0C2u));
    if (cpu->eax != 0u) goto label_0002E0DA;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_RVA(0x2E0CCu));
    label_0002E0D2:
    cpu->eax |= 0xFFFFFFFFu;
    goto label_0002E1A7;
    label_0002E0DA:
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    label_0002E0E0:
    if (sfera_process_name_is_ignored(cpu->esp + 0x38u)) { goto label_0002E180; }
    label_0002E15E:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->ebp + 0xFFFFFFFFu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::strncpy), LIFT_CODE_TOKEN_VA(0x42E16Cu));
    cpu->esp += 0xCu;
    *(uint8_t*)(cpu->esi + cpu->ebp + 0xFFFFFFFFu) = 0u;
    cpu->esi += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    label_0002E180:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::Process32Next), LIFT_CODE_TOKEN_VA(0x42E18Au));
    if (cpu->eax != 0u) goto label_0002E0E0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::CloseHandle), LIFT_CODE_TOKEN_VA(0x42E19Cu));
    cpu->eax = 1u;
    label_0002E1A7:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x174u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E1D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)&g_sfera_error_log_runtime.object[0];
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E210(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = 0x5Cu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    std::construct_at(reinterpret_cast<IOutputDevice*>(cpu->esi));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E228u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42E228u));
    lift_push32(cpu, 0x4000u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E232u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42E232u));
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->esp += 4u;
    std::construct_at(reinterpret_cast<COutputLogDevice*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 8u) = 0u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E250(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    std::construct_at(reinterpret_cast<COutputLogDevice*>(cpu->esi));
    { uint64_t l=*(uint32_t*)(cpu->esi + 8u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002E2A7;
    cpu->edx = 0xA0u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E29Bu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42E29Bu));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E2A4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42E2A4u));
    cpu->esp += 4u;
    label_0002E2A7:
    { uint64_t l=*(uint32_t*)(cpu->esi + 4u), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    std::construct_at(reinterpret_cast<IOutputDevice*>(cpu->esi));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002E2D6;
    cpu->edx = 0x65u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E2CAu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42E2CAu));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E2D3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42E2D3u));
    cpu->esp += 4u;
    label_0002E2D6:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E2F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (cpu->ebx == 0u) goto label_0002E3DF;
    cpu->eax = cpu->ebx;
    cpu->edx = cpu->eax + 1u;
    label_0002E308:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0002E308;
    { uint64_t l=cpu->eax, r=cpu->edx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002E3DE;
    cpu->edx = 0xAEu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E329u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42E329u));
    ++cpu->esi;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E330u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42E330u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->edi + 8u) = cpu->eax;
    if (cpu->eax == 0u) goto label_0002E3DE;
    cpu->ecx = cpu->ebx;
    cpu->edx = cpu->eax;
    label_0002E342:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0002E342;
    cpu->eax = *(uint32_t*)(cpu->edi + 8u);
    lift_push32(cpu, (uintptr_t)"wt"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x42E355u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi != 0u) goto label_0002E38B;
    cpu->edx = 0xB6u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E373u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42E373u));
    cpu->ecx = *(uint32_t*)(cpu->edi + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E37Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42E37Cu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->edi + 8u) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0002E38B:
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x42E38Du));
    cpu->edi = native_function_address32(&::fprintf);
    lift_push32(cpu, (uintptr_t)"--------------------------------------------------------------------------------\n"); lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x2E3A9u), LIFT_CODE_TOKEN_RVA(0x2E3A7u))) { return; }
    lift_push32(cpu, (uintptr_t)" Sphere log file\n"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x2E3B1u), LIFT_CODE_TOKEN_RVA(0x2E3AFu))) { return; }
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x42E3B6u));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::asctime), LIFT_CODE_TOKEN_VA(0x42E3BDu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)" Log file created on %s"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x2E3CCu), LIFT_CODE_TOKEN_RVA(0x2E3CAu))) { return; }
    lift_push32(cpu, (uintptr_t)"--------------------------------------------------------------------------------\n\n"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x2E3D4u), LIFT_CODE_TOKEN_RVA(0x2E3D2u))) { return; }
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x42E3D5u));
    cpu->esp += 0x34u;
    label_0002E3DE:
    cpu->esi = lift_pop32(cpu);
    label_0002E3DF:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E3F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    if (cpu->eax == 0u) goto label_0002E429;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"a+t"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x42E3FEu));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_0002E428;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"- %s\n"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x42E418u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x42E41Fu));
    cpu->esp += 0x10u;
    label_0002E428:
    cpu->esi = lift_pop32(cpu);
    label_0002E429:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E430(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E439u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x42E439u));
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E440(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->edx = 0x5Cu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    std::construct_at(reinterpret_cast<IOutputDevice*>(cpu->esi));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E458u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42E458u));
    lift_push32(cpu, 0x4000u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E462u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42E462u));
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->esp += 4u;
    std::construct_at(reinterpret_cast<CSphereError*>(cpu->esi));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    if (cpu->esi == 0u) goto label_0002E4B7;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->ecx == 0u) goto label_0002E4B7;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax == 0u) goto label_0002E4B7;
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::vsprintf), LIFT_CODE_TOKEN_VA(0x42E4A2u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<IOutputDevice*>(cpu->ecx)->write(cpu);
    label_0002E4B7:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E4C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::vsprintf);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    if (cpu->ecx == 0u) goto label_0002E509;
    lift_push32(cpu, (uintptr_t)"*** ERROR ****************************************************:");
    reinterpret_cast<IOutputDevice*>(cpu->ecx)->write(cpu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esi = *(uint32_t*)(cpu->edi + 4u);
    if (cpu->eax == 0u) goto label_0002E50D;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ecx == 0u) goto label_0002E50D;
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x2E4FAu), LIFT_CODE_TOKEN_RVA(0x2E4F8u))) { return; }
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<IOutputDevice*>(cpu->ecx)->write(cpu);
    label_0002E509:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    label_0002E50D:
    cpu->esi = *(uint32_t*)(cpu->edi);
    if (cpu->esi == 0u) goto label_0002E536;
    if (cpu->eax == 0u) goto label_0002E536;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->ecx == 0u) goto label_0002E536;
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x2E527u), LIFT_CODE_TOKEN_RVA(0x2E525u))) { return; }
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    reinterpret_cast<IOutputDevice*>(cpu->ecx)->write(cpu);
    label_0002E536:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E540(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 8u;
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esi + 8u) = 0u;
    *(uint32_t*)(cpu->esi + 0xCu) = 0u;
    if (cpu->eax != 0u) goto label_0002E5B8;
    cpu->edx = 0xE9u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E588u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42E588u));
    lift_push32(cpu, 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E58Fu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42E58Fu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if (cpu->eax == 0u) goto label_0002E5AB;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E5A9u)); sfera_sub_0042E440(cpu, LIFT_CODE_TOKEN_VA(0x42E5A9u));
    goto label_0002E5AD;
    label_0002E5AB:
    cpu->eax = 0u;
    label_0002E5AD:
    *(uint32_t*)(cpu->esp + 0x10u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    label_0002E5B8:
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->eax != 0u) goto label_0002E610;
    cpu->edx = 0xF1u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E5D1u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42E5D1u));
    lift_push32(cpu, 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E5D8u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42E5D8u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 1u;
    if (cpu->eax == 0u) goto label_0002E5F4;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E5F2u)); sfera_sub_0042E210(cpu, LIFT_CODE_TOKEN_VA(0x42E5F2u));
    goto label_0002E5F6;
    label_0002E5F4:
    cpu->eax = 0u;
    label_0002E5F6:
    lift_push32(cpu, (uintptr_t)"sphere.log");
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E60Du)); sfera_sub_0042E2F0(cpu, LIFT_CODE_TOKEN_VA(0x42E60Du));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    label_0002E610:
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->eax = cpu->esi;
    *(uint32_t*)(cpu->esi + 0x10u) = 1u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E6B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->edx;
    lift_push32(cpu, (uintptr_t)"r"); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u) = cpu->ebx;
    cpu->edi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x42E6D0u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_0002E73C;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E6E7u)); sfera_sub_004EEA10(cpu, LIFT_CODE_TOKEN_VA(0x42E6E7u));
    { uint64_t l=*(uint8_t*)(cpu->ebp + 0xCu), r=0u, v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebx = cpu->esp;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0002E701;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, 2u);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fseek), LIFT_CODE_TOKEN_VA(0x42E6F8u));
    cpu->esp += 0xCu;
    label_0002E701:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fread), LIFT_CODE_TOKEN_VA(0x42E709u));
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->ebp + 8u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x42E713u));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFF8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"\n%s\n->\n"); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x42E723u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fwrite), LIFT_CODE_TOKEN_VA(0x42E731u));
    cpu->esp += 0x30u;
    goto label_0002E74C;
    label_0002E73C:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"\n%s not found!\n"); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x42E743u));
    cpu->esp += 0xCu;
    label_0002E74C:
    cpu->esp = cpu->ebp + 0xFFFFFFECu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = (uintptr_t)"app-is-Run.1";
    lift_push32(cpu, cpu->esi);
    cpu->esi = native_function_address32(&::fopen);
    lift_push32(cpu, (uintptr_t)"r"); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x2E784u), LIFT_CODE_TOKEN_RVA(0x2E782u))) { return; }
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0002E844;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::fclose);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x2E79Au), LIFT_CODE_TOKEN_RVA(0x2E798u))) { return; }
    cpu->ecx = (uintptr_t)"client-Crash.1";
    lift_push32(cpu, (uintptr_t)"w"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->esi, LIFT_CODE_TOKEN_RVA(0x2E7A8u), LIFT_CODE_TOKEN_RVA(0x2E7A6u))) { return; }
    cpu->edi = native_function_address32(&::remove);
    cpu->esi = cpu->eax;
    cpu->esp += 0xCu;
    if (cpu->esi == 0u) goto label_0002E82E;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x3E8u);
    cpu->edx = (uintptr_t)"ERRORLOG.TXT";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E7CAu)); sfera_sub_0042E6B0(cpu, LIFT_CODE_TOKEN_VA(0x42E7CAu));
    lift_push32(cpu, (uintptr_t)"ERRORLOG.TXT");
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x2E7D1u), LIFT_CODE_TOKEN_RVA(0x2E7CFu))) { return; }
    cpu->esp += 4u;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x258u);
    cpu->edx = (uintptr_t)"Error.log";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E7E7u)); sfera_sub_0042E6B0(cpu, LIFT_CODE_TOKEN_VA(0x42E7E7u));
    lift_push32(cpu, (uintptr_t)"Error.log");
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x2E7EEu), LIFT_CODE_TOKEN_RVA(0x2E7ECu))) { return; }
    cpu->esp += 4u;
    lift_push32(cpu, 1u); lift_push32(cpu, 0xC8u);
    cpu->edx = (uintptr_t)"Warnings00.log";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E804u)); sfera_sub_0042E6B0(cpu, LIFT_CODE_TOKEN_VA(0x42E804u));
    lift_push32(cpu, (uintptr_t)"Warnings00.log");
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x2E80Bu), LIFT_CODE_TOKEN_RVA(0x2E809u))) { return; }
    cpu->edx = (uintptr_t)"error-Cause.1";
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x32u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E81Fu)); sfera_sub_0042E6B0(cpu, LIFT_CODE_TOKEN_VA(0x42E81Fu));
    cpu->edx = (uintptr_t)"error-Cause.1";
    lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x2E828u), LIFT_CODE_TOKEN_RVA(0x2E826u))) { return; }
    lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x2E82Bu), LIFT_CODE_TOKEN_RVA(0x2E829u))) { return; }
    cpu->esp += 8u;
    label_0002E82E:
    cpu->eax = (uintptr_t)"error-Cause.1";
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x2E836u), LIFT_CODE_TOKEN_RVA(0x2E834u))) { return; }
    cpu->ecx = (uintptr_t)"app-is-Run.1";
    lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x2E83Fu), LIFT_CODE_TOKEN_RVA(0x2E83Du))) { return; }
    cpu->esp += 8u;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0002E844:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x104u;
    cpu->eax = (uintptr_t)"app-is-Run.1";
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_access), LIFT_CODE_TOKEN_VA(0x42E86Cu));
    cpu->esp += 8u;
    if (cpu->eax == 0xFFFFFFFFu) goto label_0002E904;
    cpu->ecx = (uintptr_t)"app-is-Run.1";
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x42E885u));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_0002E904;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_errno), LIFT_CODE_TOKEN_VA(0x42E894u));
    cpu->edx = (uintptr_t)"error-Cause.1";
    cpu->edi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, (uintptr_t)"w"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x42E8A8u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_0002E902;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::strerror), LIFT_CODE_TOKEN_VA(0x42E8B8u));
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uintptr_t)"app-is-Run.1";
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, (uintptr_t)"File %s not deleted (~), error cause: %s\n"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sprintf), LIFT_CODE_TOKEN_VA(0x42E8CFu));
    cpu->eax = cpu->esp + 0x1Cu;
    cpu->esp += 0x14u;
    cpu->edx = cpu->eax + 1u;
    (void)cpu;
    label_0002E8E0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0002E8E0;
    lift_push32(cpu, cpu->esi);
    cpu->eax -= cpu->edx;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::fwrite), LIFT_CODE_TOKEN_VA(0x42E8F2u));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x42E8F9u));
    cpu->esp += 0x14u;
    label_0002E902:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_0002E904:
    cpu->esp += 0x104u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_file_runtime.crash_report_instance;
    if (cpu->eax != 0u) goto label_0002E981;
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0x12Cu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\FastCrashReport.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E939u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42E939u));
    lift_push32(cpu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E940u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x42E940u));
    cpu->esi = cpu->eax;
    cpu->esp += 4u;
    if (cpu->esi == 0u) goto label_0002E979;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E94Eu)); sfera_sub_0042E770(cpu, LIFT_CODE_TOKEN_VA(0x42E94Eu));
    cpu->eax = (uintptr_t)"app-is-Run.1";
    lift_push32(cpu, (uintptr_t)"w"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x42E959u));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0002E970;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x42E967u));
    cpu->esp += 4u;
    label_0002E970:
    cpu->eax = cpu->esi;
    g_sfera_file_runtime.crash_report_instance = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0002E979:
    cpu->eax = 0u;
    g_sfera_file_runtime.crash_report_instance = cpu->eax;
    cpu->esi = lift_pop32(cpu);
    label_0002E981:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042E990(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x810u;
    cpu->eax = (uintptr_t)"client-Crash.1";
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"r"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x42E9B0u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_0002EA68;
    lift_push32(cpu, 0x800u);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x42E9CFu));
    cpu->esp += 0xCu;
    cpu->eax = 0u;
    label_0002E9E0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + ((uintptr_t)&g_sfera_error_log_runtime.index_table[0])));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x11u) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0002E9E0;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x77Bu);
    cpu->edx = cpu->esp + 0x9Du;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    *(uint8_t*)(cpu->esp + 0x20u) = 3u;
    lift_native_call(cpu, native_function_address32(&::fread), LIFT_CODE_TOKEN_VA(0x42EA04u));
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0xA5u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x42EA12u));
    cpu->esp += 0x14u;
    lift_push32(cpu, 0xB8u);
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, 0x2BF20u);
    cpu->eax = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    cpu->eax = g_sfera_directplay_runtime.peer;
    lift_push32(cpu, 1u);
    cpu->edx = cpu->esp + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0x800u;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x20u);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x2EA58u), LIFT_CODE_TOKEN_RVA(0x2EA56u))) { return; }
    cpu->ecx = (uintptr_t)"client-Crash.1";
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x42EA5Fu));
    cpu->esp += 4u;
    label_0002EA68:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x810u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042EB70(LiftCpu* cpu, uint32_t stop_address) {
    if (g_sfera_file_runtime.crash_report_instance == 0u) goto label_0002EBAE;
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0x136u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\FastCrashReport.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42EB89u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42EB89u));
    cpu->ecx = g_sfera_file_runtime.crash_report_instance;
    cpu->esi = cpu->ecx;
    if (cpu->ecx == 0u) goto label_0002EBA3;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42EB9Au)); sfera_sub_0042E850(cpu, LIFT_CODE_TOKEN_VA(0x42EB9Au));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42EBA0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42EBA0u));
    cpu->esp += 4u;
    label_0002EBA3:
    g_sfera_file_runtime.crash_report_instance = 0u;
    cpu->esi = lift_pop32(cpu);
    label_0002EBAE:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042EBB0(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_file_runtime.callback = cpu->ecx;
    g_sfera_file_runtime.callback_enabled = 1u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042EBD0(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_file_runtime.callback_enabled = 1u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042EBE0(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_file_runtime.callback_enabled = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042EBF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edx |= 0x8000u;
    lift_push32(cpu, 0u);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebp);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x42EC05u));
    cpu->ebx = cpu->eax;
    cpu->esp += 0xCu;
    if (cpu->ebx == 0xFFFFFFFFu) goto label_0002ECBF;
    cpu->eax = cpu->ebp;
    cpu->edx = cpu->eax + 1u;
    label_0002EC20:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0002EC20;
    cpu->ecx = g_sfera_file_runtime.open_file_count;
    cpu->eax -= cpu->edx;
    cpu->edi = cpu->eax;
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_file_runtime.open_files.capacity) goto label_0002EC45;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.open_files;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2EC45u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2EC45u));
    label_0002EC45:
    cpu->eax = g_sfera_file_runtime.open_files.data;
    lift_push32(cpu, 0x30u);
    cpu->ecx = cpu->edi + 1u;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Files.cpp";
    cpu->esi = cpu->eax + (cpu->esi * 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42EC5Cu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x42EC5Cu));
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->ecx = g_sfera_file_runtime.open_file_count;
    cpu->esi = cpu->ebp;
    cpu->edi = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_file_runtime.open_files.capacity) goto label_0002EC7A;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.open_files;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2EC7Au)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2EC7Au));
    label_0002EC7A:
    cpu->ecx = g_sfera_file_runtime.open_files.data;
    cpu->ecx = *(uint32_t*)(cpu->ecx + (cpu->edi * 8u));
    label_0002EC83:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    *(uint8_t*)(cpu->ecx) = cpu->eax & 0xFFu;
    ++cpu->esi;
    ++cpu->ecx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0002EC83;
    cpu->ecx = g_sfera_file_runtime.open_file_count;
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_file_runtime.open_files.capacity) goto label_0002ECA7;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.open_files;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2ECA7u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2ECA7u));
    label_0002ECA7:
    cpu->edx = g_sfera_file_runtime.open_files.data;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->edx + (cpu->esi * 8u) + 4u) = cpu->ebx;
    ++g_sfera_file_runtime.open_file_count;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0002ECBF:
    lift_push32(cpu, 0x5Cu); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_strchr_address32(), LIFT_CODE_TOKEN_VA(0x42ECC2u));
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_0002ED9F;
    cpu->ebx = 0u;
    if ((int32_t)g_sfera_file_runtime.search_path_count <= (int32_t)cpu->ebx) goto label_0002ED9F;
    label_0002ECE1:
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_file_runtime.search_paths.capacity) goto label_0002ECF5;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.search_paths;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2ECF5u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2ECF5u));
    label_0002ECF5:
    cpu->eax = g_sfera_file_runtime.search_paths.data;
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->ebx * 4u));
    cpu->edx = cpu->eax + 1u;
    label_0002ED00:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0002ED00;
    cpu->eax -= cpu->edx;
    cpu->edi = cpu->eax;
    cpu->eax = cpu->ebp;
    cpu->edx = cpu->eax + 1u;
    label_0002ED10:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0002ED10;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, 0x3Au);
    cpu->ecx = cpu->eax + cpu->edi + 1u;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Files.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42ED29u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x42ED29u));
    cpu->esi = cpu->eax;
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_file_runtime.search_paths.capacity) goto label_0002ED3F;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.search_paths;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2ED3Fu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2ED3Fu));
    label_0002ED3F:
    cpu->ecx = g_sfera_file_runtime.search_paths.data;
    cpu->ecx = *(uint32_t*)(cpu->ecx + (cpu->ebx * 4u));
    cpu->edx = cpu->esi;
    label_0002ED50:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0002ED50;
    cpu->edx = cpu->esi;
    cpu->edx -= cpu->ebp;
    cpu->eax = cpu->ebp;
    cpu->edx += cpu->edi;
    label_0002ED62:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0002ED62;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x42ED74u));
    cpu->edi = cpu->eax;
    cpu->esp += 0xCu;
    if (cpu->edi != 0xFFFFFFFFu) goto label_0002EDC0;
    lift_push32(cpu, 0x45u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Files.cpp";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42ED92u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x42ED92u));
    ++cpu->ebx;
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_file_runtime.search_path_count) goto label_0002ECE1;
    label_0002ED9F:
    cpu->eax = g_sfera_file_runtime.callback;
    if (cpu->eax == 0u) goto label_0002EDB7;
    if (g_sfera_file_runtime.callback_enabled != 1u) goto label_0002EDB7;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0u;
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x2EDB7u), LIFT_CODE_TOKEN_RVA(0x2EDB5u))) { return; }
    label_0002EDB7:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0002EDC0:
    cpu->ecx = g_sfera_file_runtime.open_file_count;
    cpu->ebx = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_file_runtime.open_files.capacity) goto label_0002EDDA;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.open_files;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2EDDAu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2EDDAu));
    label_0002EDDA:
    cpu->ecx = g_sfera_file_runtime.open_files.data;
    *(uint32_t*)(cpu->ecx + (cpu->ebx * 8u) + 4u) = cpu->edi;
    cpu->ecx = g_sfera_file_runtime.open_file_count;
    cpu->ebx = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_file_runtime.open_files.capacity) goto label_0002EDFE;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.open_files;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2EDFEu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2EDFEu));
    label_0002EDFE:
    cpu->edx = g_sfera_file_runtime.open_files.data;
    *(uint32_t*)(cpu->edx + (cpu->ebx * 8u)) = cpu->esi;
    ++g_sfera_file_runtime.open_file_count;
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042EE20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0x180u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_chmod), LIFT_CODE_TOKEN_VA(0x42EE2Au));
    lift_push32(cpu, 0x180u); lift_push32(cpu, 0x8302u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_open), LIFT_CODE_TOKEN_VA(0x42EE3Bu));
    cpu->ebp = cpu->eax;
    cpu->esp += 0x14u;
    if (cpu->ebp == 0xFFFFFFFFu) goto label_0002EEF9;
    cpu->eax = cpu->esi;
    cpu->edx = cpu->eax + 1u;
    label_0002EE54:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0002EE54;
    cpu->ecx = g_sfera_file_runtime.open_file_count;
    lift_push32(cpu, cpu->ebx);
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->eax;
    cpu->edi = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_file_runtime.open_files.capacity) goto label_0002EE7B;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.open_files;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2EE7Bu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2EE7Bu));
    label_0002EE7B:
    cpu->eax = g_sfera_file_runtime.open_files.data;
    lift_push32(cpu, 0x54u);
    cpu->ecx = cpu->ebx + 1u;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Files.cpp";
    cpu->edi = cpu->eax + (cpu->edi * 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42EE92u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x42EE92u));
    *(uint32_t*)(cpu->edi) = cpu->eax;
    cpu->ecx = g_sfera_file_runtime.open_file_count;
    cpu->edi = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_file_runtime.open_files.capacity) goto label_0002EEAE;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.open_files;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2EEAEu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2EEAEu));
    label_0002EEAE:
    cpu->ecx = g_sfera_file_runtime.open_files.data;
    cpu->ecx = *(uint32_t*)(cpu->ecx + (cpu->edi * 8u));
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0002EEC0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    *(uint8_t*)(cpu->ecx) = cpu->eax & 0xFFu;
    ++cpu->esi;
    ++cpu->ecx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0002EEC0;
    cpu->ecx = g_sfera_file_runtime.open_file_count;
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_file_runtime.open_files.capacity) goto label_0002EEE4;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.open_files;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2EEE4u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2EEE4u));
    label_0002EEE4:
    cpu->edx = g_sfera_file_runtime.open_files.data;
    *(uint32_t*)(cpu->edx + (cpu->esi * 8u) + 4u) = cpu->ebp;
    ++g_sfera_file_runtime.open_file_count;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0002EEF9:
    cpu->eax = g_sfera_file_runtime.callback;
    if (cpu->eax == 0u) goto label_0002EF14;
    if (g_sfera_file_runtime.callback_enabled != 1u) goto label_0002EF14;
    cpu->edx = cpu->esi;
    cpu->ecx = 1u;
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x2EF14u), LIFT_CODE_TOKEN_RVA(0x2EF12u))) { return; }
    label_0002EF14:
    cpu->esi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042EF20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->edx;
    cpu->ebx = cpu->ecx;
    if ((int32_t)g_sfera_file_runtime.open_file_count <= (int32_t)cpu->esi) goto label_0002EF5A;
    label_0002EF32:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_file_runtime.open_files.capacity) goto label_0002EF46;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2EF46u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2EF46u));
    label_0002EF46:
    cpu->eax = g_sfera_file_runtime.open_files.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 8u) + 4u) == cpu->ebx) goto label_0002EF64;
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_file_runtime.open_file_count) goto label_0002EF32;
    label_0002EF5A:
    cpu->ecx = (uintptr_t)"Attempt of reading from the file with the wrong handle.";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2EF64u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x2EF64u));
    label_0002EF64:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_read), LIFT_CODE_TOKEN_VA(0x42EF6Bu));
    cpu->esp += 0xCu;
    if (cpu->eax == 0xFFFFFFFFu) goto label_0002EFBD;
    if (cpu->eax == cpu->edi) goto label_0002EFF6;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_file_runtime.open_files.capacity) goto label_0002EF91;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2EF91u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2EF91u));
    label_0002EF91:
    cpu->eax = g_sfera_file_runtime.callback;
    if (cpu->eax == 0u) goto label_0002EFF3;
    if (g_sfera_file_runtime.callback_enabled != 1u) goto label_0002EFF3;
    cpu->ecx = g_sfera_file_runtime.open_files.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 8u));
    cpu->ecx = 2u;
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x2EFB3u), LIFT_CODE_TOKEN_RVA(0x2EFB1u))) { return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0002EFBD:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_file_runtime.open_files.capacity) goto label_0002EFD1;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2EFD1u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2EFD1u));
    label_0002EFD1:
    cpu->eax = g_sfera_file_runtime.callback;
    if (cpu->eax == 0u) goto label_0002EFF3;
    if (g_sfera_file_runtime.callback_enabled != 1u) goto label_0002EFF3;
    cpu->edx = g_sfera_file_runtime.open_files.data;
    cpu->edx = *(uint32_t*)(cpu->edx + (cpu->esi * 8u));
    cpu->ecx = 3u;
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x2EFF3u), LIFT_CODE_TOKEN_RVA(0x2EFF1u))) { return; }
    label_0002EFF3:
    cpu->eax |= 0xFFFFFFFFu;
    label_0002EFF6:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042F000(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->edx;
    cpu->ebx = cpu->ecx;
    if ((int32_t)g_sfera_file_runtime.open_file_count <= (int32_t)cpu->esi) goto label_0002F03A;
    label_0002F012:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_file_runtime.open_files.capacity) goto label_0002F026;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2F026u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2F026u));
    label_0002F026:
    cpu->eax = g_sfera_file_runtime.open_files.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 8u) + 4u) == cpu->ebx) goto label_0002F044;
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_file_runtime.open_file_count) goto label_0002F012;
    label_0002F03A:
    cpu->ecx = (uintptr_t)"Attempt of writing to the file with the wrong handle.";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2F044u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x2F044u));
    label_0002F044:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::_write), LIFT_CODE_TOKEN_VA(0x42F04Bu));
    cpu->esp += 0xCu;
    if (cpu->eax == 0xFFFFFFFFu) goto label_0002F09D;
    if (cpu->eax == cpu->edi) goto label_0002F0D6;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_file_runtime.open_files.capacity) goto label_0002F071;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2F071u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2F071u));
    label_0002F071:
    cpu->eax = g_sfera_file_runtime.callback;
    if (cpu->eax == 0u) goto label_0002F0D3;
    if (g_sfera_file_runtime.callback_enabled != 1u) goto label_0002F0D3;
    cpu->ecx = g_sfera_file_runtime.open_files.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 8u));
    cpu->ecx = 4u;
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x2F093u), LIFT_CODE_TOKEN_RVA(0x2F091u))) { return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0002F09D:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_file_runtime.open_files.capacity) goto label_0002F0B1;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2F0B1u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2F0B1u));
    label_0002F0B1:
    cpu->eax = g_sfera_file_runtime.callback;
    if (cpu->eax == 0u) goto label_0002F0D3;
    if (g_sfera_file_runtime.callback_enabled != 1u) goto label_0002F0D3;
    cpu->edx = g_sfera_file_runtime.open_files.data;
    cpu->edx = *(uint32_t*)(cpu->edx + (cpu->esi * 8u));
    cpu->ecx = 5u;
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x2F0D3u), LIFT_CODE_TOKEN_RVA(0x2F0D1u))) { return; }
    label_0002F0D3:
    cpu->eax |= 0xFFFFFFFFu;
    label_0002F0D6:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042F0E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->edx;
    cpu->edi = cpu->ecx;
    if ((int32_t)g_sfera_file_runtime.open_file_count <= (int32_t)cpu->esi) goto label_0002F119;
    label_0002F0F1:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_file_runtime.open_files.capacity) goto label_0002F105;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2F105u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2F105u));
    label_0002F105:
    cpu->eax = g_sfera_file_runtime.open_files.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 8u) + 4u) == cpu->edi) goto label_0002F123;
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_file_runtime.open_file_count) goto label_0002F0F1;
    label_0002F119:
    cpu->ecx = (uintptr_t)"Attempt of seeking in the file with the wrong handle.";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2F123u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x2F123u));
    label_0002F123:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_lseek), LIFT_CODE_TOKEN_VA(0x42F12Au));
    cpu->esp += 0xCu;
    if (cpu->eax != 0xFFFFFFFFu) goto label_0002F171;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_file_runtime.open_files.capacity) goto label_0002F14C;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2F14Cu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2F14Cu));
    label_0002F14C:
    cpu->eax = g_sfera_file_runtime.callback;
    if (cpu->eax == 0u) goto label_0002F16E;
    if (g_sfera_file_runtime.callback_enabled != 1u) goto label_0002F16E;
    cpu->edx = g_sfera_file_runtime.open_files.data;
    cpu->edx = *(uint32_t*)(cpu->edx + (cpu->esi * 8u));
    cpu->ecx = 6u;
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x2F16Eu), LIFT_CODE_TOKEN_RVA(0x2F16Cu))) { return; }
    label_0002F16E:
    cpu->eax |= 0xFFFFFFFFu;
    label_0002F171:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042F180(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)g_sfera_file_runtime.open_file_count <= (int32_t)cpu->esi) goto label_0002F1B8;
    label_0002F190:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_file_runtime.open_files.capacity) goto label_0002F1A4;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2F1A4u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2F1A4u));
    label_0002F1A4:
    cpu->eax = g_sfera_file_runtime.open_files.data;
    if (*(uint32_t*)(cpu->eax + (cpu->esi * 8u) + 4u) == cpu->edi) goto label_0002F1C2;
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_file_runtime.open_file_count) goto label_0002F190;
    label_0002F1B8:
    cpu->ecx = (uintptr_t)"Attempt of closing the file with the wrong handle.";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2F1C2u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x2F1C2u));
    label_0002F1C2:
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_close), LIFT_CODE_TOKEN_VA(0x42F1C3u));
    cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_0002F262;
    if ((int32_t)cpu->esi < (int32_t)g_sfera_file_runtime.open_files.capacity) goto label_0002F1E8;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2F1E8u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2F1E8u));
    label_0002F1E8:
    cpu->ecx = g_sfera_file_runtime.open_files.data;
    cpu->ecx = *(uint32_t*)(cpu->ecx + (cpu->esi * 8u));
    lift_push32(cpu, 0x9Fu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Files.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42F200u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x42F200u));
    cpu->edi = cpu->esi + 1u;
    if ((int32_t)cpu->edi < (int32_t)g_sfera_file_runtime.open_files.capacity) goto label_0002F217;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2F217u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2F217u));
    label_0002F217:
    cpu->edx = g_sfera_file_runtime.open_files.data;
    cpu->edi = cpu->edx + (cpu->edi * 8u);
    if ((int32_t)cpu->esi < (int32_t)g_sfera_file_runtime.open_files.capacity) goto label_0002F234;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2F234u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2F234u));
    label_0002F234:
    cpu->eax = g_sfera_file_runtime.open_file_count;
    cpu->edx = g_sfera_file_runtime.open_files.data;
    cpu->eax -= cpu->esi;
    cpu->ecx = (cpu->eax * 8u) + 0xFFFFFFF8u;
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->edx + (cpu->esi * 8u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x42F24Eu));
    --g_sfera_file_runtime.open_file_count;
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0002F262:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_file_runtime.open_files.capacity) goto label_0002F276;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2F276u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2F276u));
    label_0002F276:
    cpu->eax = g_sfera_file_runtime.callback;
    if (cpu->eax == 0u) goto label_0002F298;
    if (g_sfera_file_runtime.callback_enabled != 1u) goto label_0002F298;
    cpu->ecx = g_sfera_file_runtime.open_files.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 8u));
    cpu->ecx = 7u;
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x2F298u), LIFT_CODE_TOKEN_RVA(0x2F296u))) { return; }
    label_0002F298:
    cpu->edi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042F2A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42F2A8u)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x42F2A8u));
    cpu->esi = cpu->eax;
    if (cpu->esi == 0xFFFFFFFFu) goto label_0002F2C8;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_filelength), LIFT_CODE_TOKEN_VA(0x42F2B1u));
    cpu->esp += 4u;
    cpu->ecx = cpu->esi;
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42F2C3u)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x42F2C3u));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0002F2C8:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042F2D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->esi;
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->eax + 1u;
    label_0002F2E0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0002F2E0;
    cpu->ecx = g_sfera_file_runtime.search_path_count;
    cpu->eax -= cpu->edx;
    cpu->ebx = cpu->eax;
    cpu->edi = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_file_runtime.search_paths.capacity) goto label_0002F305;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.search_paths;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2F305u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2F305u));
    label_0002F305:
    cpu->eax = g_sfera_file_runtime.search_paths.data;
    lift_push32(cpu, 0xCAu);
    cpu->ecx = cpu->ebx + 2u;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\Files.cpp";
    cpu->edi = cpu->eax + (cpu->edi * 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42F31Fu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x42F31Fu));
    *(uint32_t*)(cpu->edi) = cpu->eax;
    cpu->ecx = g_sfera_file_runtime.search_path_count;
    cpu->edi = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_file_runtime.search_paths.capacity) goto label_0002F33B;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.search_paths;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2F33Bu)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2F33Bu));
    label_0002F33B:
    cpu->ecx = g_sfera_file_runtime.search_paths.data;
    cpu->ecx = *(uint32_t*)(cpu->ecx + (cpu->edi * 4u));
    label_0002F344:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    *(uint8_t*)(cpu->ecx) = cpu->eax & 0xFFu;
    ++cpu->esi;
    ++cpu->ecx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0002F344;
    cpu->ecx = g_sfera_file_runtime.search_path_count;
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_file_runtime.search_paths.capacity) goto label_0002F36E;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.search_paths;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42F368u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_VA(0x42F368u));
    cpu->ecx = g_sfera_file_runtime.search_path_count;
    label_0002F36E:
    cpu->edx = g_sfera_file_runtime.search_paths.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    if (*(uint8_t*)(cpu->eax + cpu->ebx + 0xFFFFFFFFu) == 0x5Cu) goto label_0002F3D0;
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_file_runtime.search_paths.capacity) goto label_0002F392;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.search_paths;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2F392u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2F392u));
    label_0002F392:
    cpu->ecx = g_sfera_file_runtime.search_paths.data;
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    *(uint8_t*)(cpu->ebx + cpu->edx) = 0x5Cu;
    cpu->ecx = g_sfera_file_runtime.search_path_count;
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_file_runtime.search_paths.capacity) goto label_0002F3B9;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.search_paths;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2F3B9u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2F3B9u));
    label_0002F3B9:
    cpu->eax = g_sfera_file_runtime.search_paths.data;
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->ecx + cpu->ebx + 1u) = 0u;
    ++g_sfera_file_runtime.search_path_count;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0002F3D0:
    cpu->edi = lift_pop32(cpu);
    ++cpu->ecx;
    cpu->esi = lift_pop32(cpu);
    g_sfera_file_runtime.search_path_count = cpu->ecx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042F3E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 4u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 8u));
    lift_x87_push(cpu, cpu->fpu[1u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[0u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42F409u)); sfera_sub_004EE9EC(cpu, LIFT_CODE_TOKEN_VA(0x42F409u));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u)); lift_x87_push(cpu, cpu->fpu[0u]);
    lift_x87_push(cpu, 0.0);
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]); lift_x87_pop(cpu); lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=0x44u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0002F43D;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (cpu->fpu[1u]);
    *(float*)(cpu->esi) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) / (cpu->fpu[1u]);
    *(float*)(cpu->esi + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (((double)*(float*)(cpu->esi + 8u))) / (cpu->fpu[0u]);
    *(float*)(cpu->esi + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0002F43D:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042F450(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    if ((int32_t)cpu->ebx < (int32_t)4u) goto label_0002F678;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebx += 0xFFFFFFFCu;
    cpu->ebp = cpu->edi;
    { uint64_t l=cpu->ebp, r=cpu->ecx, c=0u, v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebp = v; }
    cpu->ebx >>= 2u;
    ++cpu->ebx;
    cpu->eax = cpu->ecx + 8u;
    cpu->esi = cpu->edi + 0xCu;
    cpu->ecx = cpu->ebx * 4u;
    label_0002F490:
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xFFFFFFF8u));
    cpu->edi = *(uint32_t*)(cpu->edx);
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xFFFFFFFCu));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 4u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->edi)));
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 8u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edi + 0xCu)));
    *(float*)(cpu->esi + 0xFFFFFFF4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edi = *(uint32_t*)(cpu->edx);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x18u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[4u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edi + 0x1Cu)));
    *(float*)(cpu->esi + 0xFFFFFFF8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edi = *(uint32_t*)(cpu->edx);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x24u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->edi + 0x20u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x28u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edi + 0x2Cu)));
    *(float*)(cpu->eax + cpu->ebp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edi = *(uint32_t*)(cpu->edx);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 4u));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 8u));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xCu));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 4u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->edi)));
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 8u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edi + 0xCu)));
    *(float*)(cpu->esi) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edi = *(uint32_t*)(cpu->edx);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x18u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[4u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edi + 0x1Cu)));
    *(float*)(cpu->esi + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edi = *(uint32_t*)(cpu->edx);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x24u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->edi + 0x20u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x28u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edi + 0x2Cu)));
    *(float*)(cpu->esi + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edi = *(uint32_t*)(cpu->edx);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x10u));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x14u));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x18u));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 4u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->edi)));
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 8u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edi + 0xCu)));
    *(float*)(cpu->esi + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edi = *(uint32_t*)(cpu->edx);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x18u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[4u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edi + 0x1Cu)));
    *(float*)(cpu->esi + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edi = *(uint32_t*)(cpu->edx);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x24u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->edi + 0x20u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x28u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edi + 0x2Cu)));
    *(float*)(cpu->esi + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edi = *(uint32_t*)(cpu->edx);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x1Cu));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x20u));
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x24u));
    *(float*)(cpu->esp + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 4u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->edi)));
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 8u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x18u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edi + 0xCu)));
    *(float*)(cpu->esi + 0x18u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edi = *(uint32_t*)(cpu->edx);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x18u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[4u]);
    cpu->eax += 0x30u;
    cpu->esi += 0x30u;
    { uint64_t l=cpu->ebx, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edi + 0x1Cu)));
    *(float*)(cpu->esi + 0xFFFFFFECu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edi = *(uint32_t*)(cpu->edx);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x24u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->edi + 0x20u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edi + 0x28u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->edi + 0x2Cu)));
    *(float*)(cpu->esi + 0xFFFFFFF0u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002F490;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ebp = lift_pop32(cpu);
    label_0002F678:
    if ((int32_t)cpu->ecx >= (int32_t)cpu->ebx) goto label_0002F71F;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = cpu->ecx + (cpu->ecx * 2u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->esi = cpu->eax + cpu->edi;
    cpu->eax = cpu->eax + cpu->ebx + 8u;
    cpu->edi -= cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ebx -= cpu->ecx;
    label_0002F6A0:
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xFFFFFFF8u));
    cpu->ecx = *(uint32_t*)(cpu->edx);
    *(float*)(cpu->esp + 0x10u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax += 0xCu;
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xFFFFFFF0u));
    cpu->esi += 0xCu;
    { uint64_t l=cpu->ebx, v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0xFFFFFFF4u));
    *(float*)(cpu->esp + 0x14u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 4u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x10u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ecx)));
    cpu->fpu[3u] = cpu->fpu[3u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 8u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0x14u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[4u]; cpu->fpu[4u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ecx + 0xCu)));
    *(float*)(cpu->esi + 0xFFFFFFF4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x10u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x18u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[4u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ecx + 0x1Cu)));
    *(float*)(cpu->esi + 0xFFFFFFF8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x24u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->ecx + 0x20u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 0x28u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->ecx + 0x2Cu)));
    *(float*)(cpu->eax + cpu->edi + 0xFFFFFFF4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0002F6A0;
    label_0002F71F:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042F730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->esi;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx));
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 0xCu)));
    cpu->esi = lift_pop32(cpu);
    *(float*)(cpu->esp) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 0x1Cu)));
    *(float*)(cpu->esp + 0xCu) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->ecx + 8u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->eax + 0x2Cu)));
    *(float*)(cpu->esp + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x10u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[3u]; cpu->fpu[3u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x20u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u)); lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[2u]; cpu->fpu[2u] = temporary; }
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->ecx) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x14u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 4u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[4u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->eax + 0x24u));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (cpu->fpu[2u]);
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->ecx + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->edx = *(uint32_t*)(cpu->edx);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 0x18u));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->edx + 8u));
    cpu->fpu[3u] = cpu->fpu[3u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    { double temporary = cpu->fpu[0u]; cpu->fpu[0u] = cpu->fpu[1u]; cpu->fpu[1u] = temporary; }
    cpu->fpu[2u] = cpu->fpu[2u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->edx + 0x28u)));
    cpu->fpu[1u] = cpu->fpu[1u] + cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->ecx + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042F7D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42F7E6u)); sfera_sub_0042F730(cpu, LIFT_CODE_TOKEN_VA(0x42F7E6u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 4u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x50u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    if (((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0002F863;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x54u));
    lift_x87_compare(cpu, cpu->fpu[0u], cpu->fpu[1u]);
    lift_x87_pop(cpu); (cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u)) & 0xFFFFu));
    { uint64_t l=((cpu->eax >> 8u) & 0xFFu), r=5u, v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0002F863;
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x64u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 8u));
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x98u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x5Cu)));
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->eax) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x68u));
    lift_x87_push(cpu, (double)*(float*)(cpu->esp + 0xCu));
    lift_x87_push(cpu, cpu->fpu[2u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x98u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x60u)));
    cpu->fpu[1u] = cpu->fpu[1u] / cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[1u] - cpu->fpu[0u]; lift_x87_pop(cpu);
    *(float*)(cpu->eax + 4u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, cpu->fpu[0u]);
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi + 0x50u)));
    cpu->fpu[0u] = (cpu->fpu[0u]) * (((double)*(float*)(cpu->esi + 0x54u)));
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x54u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi + 0x50u)));
    cpu->fpu[2u] = cpu->fpu[2u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[1u] = cpu->fpu[0u] / cpu->fpu[1u]; lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)*(float*)(cpu->esi + 0x70u));
    cpu->fpu[0u] = (cpu->fpu[0u]) - (((double)*(float*)(cpu->esi + 0x6Cu)));
    cpu->fpu[1u] = cpu->fpu[1u] * cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->fpu[0u] = (cpu->fpu[0u]) + (((double)*(float*)(cpu->esi + 0x6Cu)));
    cpu->esi = lift_pop32(cpu);
    *(float*)(cpu->eax + 8u) = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = 1u;
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0002F863:
    cpu->fpu[0u] = cpu->fpu[0u]; lift_x87_pop(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

} // namespace lifted
