#include "lifted_functions.h"
#include <cmath>
#include <cstdio>
namespace lifted {

static inline void sfera_report_file_error(LiftCpu* cpu, uint32_t code, uint32_t path, uint32_t callsite) { if (g_sfera_file_runtime.error_reporting_enabled != 1u) { return; } cpu->ecx = code; cpu->edx = path; lift_push32(cpu, callsite); sfera_sub_00459DC0(cpu, callsite); }

static uint8_t sfera_ascii_lower(uint8_t value) { return value >= 'A' && value <= 'Z' ? (uint8_t)(value + ('a' - 'A')) : value; }
static uint32_t sfera_ascii_hash_ci(uint32_t address) { uint32_t hash = UINT32_C(2166136261); for (;;) { const uint8_t value = *(uint8_t*)(address++); if (value == 0u) { return hash; } hash = (hash ^ sfera_ascii_lower(value)) * UINT32_C(16777619); } }
static int sfera_ascii_iequals(uint32_t address, const char* literal) { for (;;) { const uint8_t left = sfera_ascii_lower(*(uint8_t*)(address++)); const uint8_t right = sfera_ascii_lower((uint8_t)*literal++); if (left != right) { return 0; } if (left == 0u) { return 1; } } }
static int sfera_process_name_is_ignored(uint32_t address) { switch (sfera_ascii_hash_ci(address)) { case 0xCB320621u: return sfera_ascii_iequals(address, "[System Process]"); case 0xC301CF93u: return sfera_ascii_iequals(address, "idle"); case 0xF84B2A97u: return sfera_ascii_iequals(address, "csrss.exe"); case 0xDE6F2DFEu: return sfera_ascii_iequals(address, "winlogon.exe"); case 0x86049695u: return sfera_ascii_iequals(address, "smss.exe"); case 0x28FDCADBu: return sfera_ascii_iequals(address, "services.exe"); case 0x523B71BAu: return sfera_ascii_iequals(address, "service.exe"); case 0x6105AD4Fu: return sfera_ascii_iequals(address, "lsass.exe"); case 0x82611D84u: return sfera_ascii_iequals(address, "taskmgr.exe"); case 0x491E0A9Cu: return sfera_ascii_iequals(address, "system"); case 0x2453F3B9u: return sfera_ascii_iequals(address, "svchost.exe"); case 0xC979C6AEu: return sfera_ascii_iequals(address, "cdantsrv.exe"); case 0x6369D323u: return sfera_ascii_iequals(address, "spoolsv.exe"); case 0xA162EC55u: return sfera_ascii_iequals(address, "mdm.exe"); case 0x48545BE6u: return sfera_ascii_iequals(address, "nvsvc32.exe"); case 0x708EA5E0u: return sfera_ascii_iequals(address, "far.exe"); case 0x130CD4F6u: return sfera_ascii_iequals(address, "regsvc32.exe"); case 0xA11E0AEu: return sfera_ascii_iequals(address, "mstask.exe"); case 0xABDAFF7Eu: return sfera_ascii_iequals(address, "winmgmt.exe"); case 0x8AE4CC97u: return sfera_ascii_iequals(address, "stisvc.exe"); case 0xDB3A61B5u: return sfera_ascii_iequals(address, "rundll32.exe"); case 0xE566D06Eu: return sfera_ascii_iequals(address, "wcescoomm.exe"); case 0xA062BD36u: return sfera_ascii_iequals(address, "internat.exe"); case 0x5037C1B7u: return sfera_ascii_iequals(address, "winword.exe"); case 0x399460A4u: return sfera_ascii_iequals(address, "explorer.exe"); case 0xB884A32Cu: return sfera_ascii_iequals(address, "notepad.exe"); case 0x82407190u: return sfera_ascii_iequals(address, "ctfmon.exe"); case 0xFFB78D72u: return sfera_ascii_iequals(address, "icq.exe"); case 0x3BC05E55u: return sfera_ascii_iequals(address, "iexplore.exe"); case 0x8C6DE00Au: return sfera_ascii_iequals(address, "srvany.exe"); case 0x47785D4Cu: return sfera_ascii_iequals(address, "spidernt.exe"); case 0xF7D48DE3u: return sfera_ascii_iequals(address, "winamp.exe"); case 0xD391162Bu: return sfera_ascii_iequals(address, "kav.exe"); case 0x83888858u: return sfera_ascii_iequals(address, "winrar.exe"); case 0x4FB24653u: return sfera_ascii_iequals(address, "kavsvc.exe"); case 0x73D09132u: return sfera_ascii_iequals(address, "ati2evxx.exe"); case 0x796F943u: return sfera_ascii_iequals(address, "regsvc.exe"); case 0x51E34A6Eu: return sfera_ascii_iequals(address, "mspmspsv.exe"); case 0x94FF76ADu: return sfera_ascii_iequals(address, "resetservice.exe"); case 0x17B4BBA5u: return sfera_ascii_iequals(address, "directcd.exe"); case 0x5AB899A3u: return sfera_ascii_iequals(address, "qttask.exe"); case 0x91BFD53Cu: return sfera_ascii_iequals(address, "atiptaxx.exe"); case 0x681423EEu: return sfera_ascii_iequals(address, "SOUNDMAN.EXE"); case 0x4DF48812u: return sfera_ascii_iequals(address, "wuauclt.exe"); case 0x5ECB2F2Cu: return sfera_ascii_iequals(address, "miranda32.exe"); case 0xB7110726u: return sfera_ascii_iequals(address, "sphere.exe"); case 0xBB309AE5u: return sfera_ascii_iequals(address, "cmd.exe"); case 0xEDFBE74Au: return sfera_ascii_iequals(address, "calc.exe"); case 0x5D2A3611u: return sfera_ascii_iequals(address, "thebat.exe"); default: return 0; } }
__declspec(noinline) void sfera_sub_00426A50(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[18];
    cpu->esp -= 0x20u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x28u) = 0u;
    if ((int32_t)(cpu->eax) < (int32_t)(7u)) goto label_000272B3;
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
    cpu->eax += cpu->edx;
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
    cpu->edx -= cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    if (cpu->edx != 0u) goto label_00026C0C;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = *(uint32_t*)(cpu->edx + 0x90u);
    cpu->ebx = *(uint32_t*)(cpu->ecx + 0x90u);
    sub_pred[1] = cpu->edx <= cpu->ebx;
    if (cpu->edx < cpu->ebx) goto label_00026AFA;
    if (!sub_pred[1]) goto label_00026C14;
    label_00026AFA:
    cpu->edx = cpu->eax + cpu->eax;
    cpu->edi = *(uint16_t*)(cpu->esi + (cpu->edx * 2u));
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x98u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx = *(uint32_t*)(cpu->edi + cpu->ebp + 0x98u);
    cpu->edi += cpu->ebp;
    cpu->edx &= 1u;
    cpu->ebx &= 1u;
    if ((cpu->edx -= cpu->ebx) != 0u) goto label_00026CBC;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x90u);
    if (cpu->ecx < *(uint32_t*)(cpu->edi + 0x90u)) goto label_00026CC4;
    label_00026B36:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x98u);
    cpu->ebx = *(uint32_t*)(cpu->edi + 0x98u);
    cpu->ecx &= 1u;
    cpu->ebx &= 1u;
    if ((cpu->ecx -= cpu->ebx) != 0u) goto label_00026CD1;
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x90u);
    cpu->edi = *(uint32_t*)(cpu->edi + 0x90u);
    sub_pred[4] = cpu->ecx <= cpu->edi;
    if (cpu->ecx < cpu->edi) goto label_00026B6A;
    if (!sub_pred[4]) goto label_00026CD9;
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
    cpu->edx -= cpu->edi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    if (cpu->edx != 0u) goto label_00026CEA;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x90u);
    cpu->edi = *(uint32_t*)(cpu->ecx + 0x90u);
    sub_pred[6] = cpu->edx <= cpu->edi;
    if (cpu->edx < cpu->edi) goto label_00026BCE;
    if (!sub_pred[6]) goto label_00026CF2;
    label_00026BCE:
    cpu->edi = *(uint16_t*)(cpu->esi + (cpu->ebx * 2u));
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x98u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx = *(uint32_t*)(cpu->edi + cpu->ebp + 0x98u);
    cpu->edi += cpu->ebp;
    cpu->edx &= 1u;
    cpu->ebx &= 1u;
    if ((cpu->edx -= cpu->ebx) != 0u) goto label_00026D69;
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
    if ((cpu->edx -= cpu->ebx) != 0u) goto label_00026C55;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x90u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x90u);
    sub_pred[8] = cpu->ecx <= cpu->edx;
    if (cpu->ecx < cpu->edx) goto label_00026C66;
    if (!sub_pred[8]) goto label_00026C59;
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
    if ((cpu->ecx -= cpu->edx) != 0u) goto label_00026CA7;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x90u);
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x90u);
    sub_pred[10] = cpu->ecx <= cpu->edx;
    if (cpu->ecx < cpu->edx) goto label_00026CAF;
    if (!sub_pred[10]) goto label_00026B6E;
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
    if ((cpu->edx -= cpu->ebx) != 0u) goto label_00026D29;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x90u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x90u);
    sub_pred[12] = cpu->ecx <= cpu->edx;
    if (cpu->ecx < cpu->edx) goto label_00026D2D;
    if (!sub_pred[12]) goto label_00026DA5;
    goto label_00026D2D;
    label_00026D29:
    if ((int32_t)cpu->edx < 0) goto label_00026DA5;
    label_00026D2D:
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x98u);
    cpu->edx = *(uint32_t*)(cpu->edi + 0x98u);
    cpu->ecx &= 1u;
    cpu->edx &= 1u;
    if ((cpu->ecx -= cpu->edx) != 0u) goto label_00026D5B;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x90u);
    cpu->edi = *(uint32_t*)(cpu->edi + 0x90u);
    sub_pred[15] = cpu->eax <= cpu->edi;
    if (cpu->eax < cpu->edi) goto label_00026D55;
    if (!sub_pred[15]) goto label_00026D5F;
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
    if ((cpu->ecx -= cpu->edx) != 0u) goto label_00026E45;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x90u);
    cpu->edi = *(uint32_t*)(cpu->edi + 0x90u);
    sub_pred[16] = cpu->eax <= cpu->edi;
    if (cpu->eax < cpu->edi) goto label_00026D9D;
    if (!sub_pred[16]) goto label_00026E4D;
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
    if ((cpu->ecx -= cpu->ebx) != 0u) goto label_00026E5A;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x90u);
    cpu->ebx = *(uint32_t*)(cpu->eax + 0x90u);
    sub_pred[17] = cpu->ecx <= cpu->ebx;
    if (cpu->ecx < cpu->ebx) goto label_00026DFC;
    if (!sub_pred[17]) goto label_00026E5E;
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
    if ((cpu->ecx -= cpu->ebx) != 0u) goto label_00026EDE;
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
    if ((cpu->ecx -= cpu->ebx) != 0u) goto label_00026EA0;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x90u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x90u);
    sub_pred[0] = cpu->eax <= cpu->ecx;
    if (cpu->eax < cpu->ecx) goto label_00026EAE;
    if (!sub_pred[0]) goto label_00026EA4;
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
    if ((cpu->eax -= cpu->edx) != 0u) goto label_00026ED8;
    cpu->edi = *(uint32_t*)(cpu->edi + 0x90u);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x90u);
    sub_pred[2] = cpu->edi <= cpu->eax;
    if (cpu->edi < cpu->eax) goto label_00026F1A;
    if (!sub_pred[2]) goto label_00026F22;
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
    if ((cpu->eax -= cpu->edx) != 0u) goto label_00026F16;
    cpu->edi = *(uint32_t*)(cpu->edi + 0x90u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x90u);
    sub_pred[5] = cpu->edi <= cpu->ecx;
    if (cpu->edi < cpu->ecx) goto label_00026F22;
    if (!sub_pred[5]) goto label_00026F1A;
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
    cpu->ecx -= cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    if (cpu->ecx != 0u) goto label_00026FB2;
    cpu->edx = *(uint32_t*)(cpu->edx + 0x90u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x90u);
    sub_pred[7] = cpu->edx <= cpu->ecx;
    if (cpu->edx < cpu->ecx) goto label_00026F70;
    if (!sub_pred[7]) goto label_00026FB6;
    label_00026F70:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint16_t*)(cpu->esi + (cpu->edx * 2u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x98u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x9Cu);
    cpu->ebx = *(uint32_t*)(cpu->edx + cpu->ebp + 0x98u);
    cpu->edx += cpu->ebp;
    cpu->ecx &= 1u;
    cpu->ebx &= 1u;
    if ((cpu->ecx -= cpu->ebx) != 0u) goto label_000270DA;
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
    if ((cpu->ecx -= cpu->ebx) != 0u) goto label_00026FF1;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x90u);
    cpu->ecx = *(uint32_t*)(cpu->edx + 0x90u);
    sub_pred[9] = cpu->eax <= cpu->ecx;
    if (cpu->eax < cpu->ecx) goto label_00026FF5;
    if (!sub_pred[9]) goto label_00027031;
    goto label_00026FF5;
    label_00026FF1:
    if ((int32_t)cpu->ecx < 0) goto label_00027031;
    label_00026FF5:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x98u);
    cpu->edi = *(uint32_t*)(cpu->edx + 0x98u);
    cpu->eax &= 1u;
    cpu->edi &= 1u;
    if ((cpu->eax -= cpu->edi) != 0u) goto label_000270C9;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x90u);
    cpu->edx = *(uint32_t*)(cpu->edx + 0x90u);
    sub_pred[11] = cpu->eax <= cpu->edx;
    if (cpu->eax < cpu->edx) goto label_000270D1;
    if (sub_pred[11]) goto label_000270D1;
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
    if ((cpu->edx -= cpu->ebp) != 0u) goto label_00027128;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x90u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x90u);
    sub_pred[13] = cpu->ecx <= cpu->eax;
    if (cpu->ecx < cpu->eax) goto label_0002712C;
    if (!sub_pred[13]) goto label_000270C2;
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
    if ((cpu->eax -= cpu->edi) != 0u) goto label_00027117;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x90u);
    cpu->edx = *(uint32_t*)(cpu->edx + 0x90u);
    sub_pred[14] = cpu->eax <= cpu->edx;
    if (cpu->eax < cpu->edx) goto label_0002702D;
    if (!sub_pred[14]) goto label_0002711F;
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
    if ((cpu->edx -= cpu->ebp) != 0u) goto label_000271BF;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x90u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x90u);
    sub_pred[3] = cpu->ecx <= cpu->eax;
    if (cpu->ecx < cpu->eax) goto label_00027195;
    if (!sub_pred[3]) goto label_000271C3;
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
    if ((int32_t)(cpu->eax) >= (int32_t)(7u)) goto label_00026A74;
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
    if ((cpu->edi -= cpu->ebx) != 0u) goto label_0002730F;
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
    if ((cpu->edi -= cpu->ebx) != 0u) goto label_0002739F;
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
__declspec(noinline) void sfera_sub_00427550(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    sub_pred[0] = (uint32_t)(g_sfera_effect_manager.render_slots.capacity) == 0u; sub_pred[1] = (int32_t)((uint32_t)(g_sfera_effect_manager.render_slots.capacity)) < (int32_t)(0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((!sub_pred[0]) && (!sub_pred[1])) goto label_00027576;
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
__declspec(noinline) void sfera_sub_00429830(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->ebp <= 0x3FFFFFFFu) goto label_0002984B;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    cpu->eip = LIFT_CODE_TOKEN_VA(0x429830u); throw std::length_error("std::length_error");
    label_0002984B:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax -= *(uint32_t*)(cpu->esi);
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    if (cpu->eax >= cpu->ebp) goto label_000298A5;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi + 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429862u)); sfera_sub_0049F1D0(cpu, LIFT_CODE_TOKEN_VA(0x429862u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ebx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx -= cpu->eax;
    cpu->ecx = (int32_t)(cpu->ecx) >> 2u;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x429875u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edi = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi -= cpu->eax;
    cpu->esp += 0xCu;
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
__declspec(noinline) void sfera_sub_00429A30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->edi + 4u);
    cpu->ebx = *(uint32_t*)(cpu->eax + 4u);
    cpu->esi = cpu->ebx;
    if (*(uint8_t*)(cpu->ebx + 0x15u) != 0u) goto label_00029A61;
    label_00029A43:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429A4Eu)); sfera_sub_004044D0(cpu, LIFT_CODE_TOKEN_VA(0x429A4Eu));
    cpu->esi = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x429A56u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x429A56u));
    cpu->esp += 4u;
    cpu->ebx = cpu->esi;
    if (*(uint8_t*)(cpu->esi + 0x15u) == 0u) goto label_00029A43;
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
__declspec(noinline) void sfera_sub_00429B20(LiftCpu* cpu, uint32_t stop_address) {
    auto* item = sfera_active_effect(cpu->ecx); if (item != nullptr && cpu->ecx != 0xFFFFFFFFu) g_sfera_effect_manager.removeActiveEffect(*item);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00429C10(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_effect_manager.updateActiveEffects();
    cpu->esp += 4u; cpu->eip = stop_address; return;
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
    cpu->ebx -= *(uint32_t*)(cpu->esi);
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
    cpu->eax -= cpu->ecx;
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
    cpu->eip = 0x42A391u; ::DebugBreak(); return;
}
__declspec(noinline) void sfera_sub_0042A3A0(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_effect_manager.shutdown(); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042A630(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_effect_manager.initialize(); cpu->esp += 4u; cpu->eip = stop_address; return;
}

__declspec(noinline) void sfera_sub_0042AB10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_effect_manager.createActiveEffect(cpu->ecx, cpu->edx); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042AD40(LiftCpu* cpu, uint32_t stop_address) {
    const char* name = reinterpret_cast<const char*>(static_cast<uintptr_t>(cpu->ecx)); cpu->eax = g_sfera_effect_manager.createActiveEffect(name, cpu->edx); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042ADA0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    bool lift_cmp[1];
    cpu->esp -= 0x3Cu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ebp);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    cpu->ebp = cpu->ecx;
    if (g_sfera_effect_manager.flare_enabled == cpu->eax) goto label_0002ADD4;
    cpu->ecx = 0u;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax!=0u) ? 1u : 0u) & 0xFFu);
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
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    x87_v0 = (x87_v0) / ((double)(((int32_t)(g_sfera_graphics_runtime.display_width))));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x1E0u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    cpu->edi = cpu->eax;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    x87_v0 = (x87_v0) / ((double)(((int32_t)(g_sfera_graphics_runtime.display_height))));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    x87_v0 = 0.0;
    *(float*)(cpu->esp + 0x28u) = x87_v0;
    cpu->ebx = cpu->eax;
    *(float*)(cpu->esp + 0x2Cu) = x87_v0;
    cpu->eax = cpu->edi;
    x87_v1 = 1.0;
    cpu->eax = (int32_t)(cpu->eax) >> 1u;
    *(float*)(cpu->esp + 0x30u) = x87_v1;
    cpu->ebp -= cpu->eax;
    *(float*)(cpu->esp + 0x38u) = x87_v1;
    cpu->ecx = cpu->ebx;
    *(float*)(cpu->esp + 0x3Cu) = x87_v1;
    cpu->ecx = (int32_t)(cpu->ecx) >> 1u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x1Cu)) - (uint64_t)(cpu->ecx) - (uint64_t)(0u);
    *(float*)(cpu->esp + 0x44u) = x87_v1; 
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebp;
    *(float*)(cpu->esp + 0x34u) = x87_v0;
    *(float*)(cpu->esp + 0x40u) = x87_v0; 
    x87_v0 = (double)0.3499999940395355f;
    x87_v1 = (double)g_sfera_graphics_runtime.environment_factor;
    lift_cmp[0]=x87_v1<x87_v0;
    x87_v0 = x87_v1; 
    x87_v1 = 2550.0;
    if (!lift_cmp[0]) goto label_0002AEBD;
    cpu->eax = 0xE7Fu;
    x87_v2 = x87_v0;
    x87_v2 = (0.3499999940395355) - (x87_v2);
    x87_v2 = (x87_v2) * (x87_v1);
    *(uint64_t*)(cpu->esp + 0x14u) = static_cast<int64_t>(std::trunc(x87_v2));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->ecx <= 0xFFu) goto label_0002AEBD;
    cpu->ecx = 0xFFu;
    label_0002AEBD:
    { const double lift_left=(double)*(float*)((uintptr_t)"333\077..\\ShareClientSeverCode\\CheckFiles.cpp"); const double lift_right=x87_v0; if (!(lift_left<lift_right)) goto label_0002AF07; }
    cpu->eax = 0xE7Fu;
    x87_v2 = x87_v0;
    x87_v2 = (x87_v2) - (0.699999988079071);
    x87_v1 = x87_v1 * x87_v2; 
    *(uint64_t*)(cpu->esp + 0x14u) = static_cast<int64_t>(std::trunc(x87_v1));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->ecx <= 0xFFu) goto label_0002AF09;
    cpu->ecx = 0xFFu;
    goto label_0002AF09;
    label_0002AF07:
    x87_v1 = x87_v1; 
    label_0002AF09:
    { const double lift_left=(double)0.1899999976158142f; const double lift_right=x87_v0; if (lift_left>lift_right) goto label_0002AF27; }
    { const double lift_left=x87_v0; const double lift_right=0.8299999833106995;  if (!(lift_left>lift_right)) goto label_0002AF2B; }
    goto label_0002AF29;
    label_0002AF27:
    x87_v0 = x87_v0; 
    label_0002AF29:
    cpu->ecx=0u;
    label_0002AF2B:
    cpu->esi = g_sfera_effect_manager.flare_alpha;
    cpu->esi *= cpu->ecx;
    cpu->esi >>= 8u;
    if (cpu->esi == 0u) goto label_0002AF97;
    cpu->ecx = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42AF45u)); sfera_sub_004CE0E0(cpu, LIFT_CODE_TOKEN_VA(0x42AF45u));
    cpu->ebx += *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, 1u);
    cpu->edx = cpu->esp + 0x2Cu;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x18u))));
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->esp -= 0x10u;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    cpu->edi += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edi;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x2Cu))));
    cpu->ecx = cpu->esi;
    cpu->ecx <<= 24u;
    cpu->ecx |= 0xFF640Fu;
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(float*)(cpu->esp + 4u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x34u))));
    *(float*)(cpu->esp) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x38u))));
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
__declspec(noinline) void sfera_sub_0042B0A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042B7D0(LiftCpu* cpu, uint32_t stop_address) {
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
__declspec(noinline) void sfera_sub_0042D180(LiftCpu* cpu, uint32_t stop_address) {
    auto* track = reinterpret_cast<SferaEffectTrack*>(static_cast<uintptr_t>(cpu->ecx));
    auto* output = reinterpret_cast<SferaEffectVec3F*>(static_cast<uintptr_t>(*(uint32_t*)(cpu->esp + 8u)));
    if (track != nullptr && output != nullptr) track->evaluateVector(std::bit_cast<float>(*(uint32_t*)(cpu->esp + 4u)), *output);
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042D290(LiftCpu* cpu, uint32_t stop_address) {
    auto* track = reinterpret_cast<SferaEffectTrack*>(static_cast<uintptr_t>(cpu->ecx));
    auto* output = reinterpret_cast<float*>(static_cast<uintptr_t>(*(uint32_t*)(cpu->esp + 8u)));
    auto* random_values = reinterpret_cast<const std::uint16_t*>(static_cast<uintptr_t>(*(uint32_t*)(cpu->esp + 0x14u)));
    if (track != nullptr && output != nullptr) track->evaluateScalar(std::bit_cast<float>(*(uint32_t*)(cpu->esp + 4u)), *output, random_values, *(uint32_t*)(cpu->esp + 0xCu));
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042D430(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[2]; bool sub_pred[1]; double x87_v0, x87_v1, x87_v2;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    sub_pred[0] = cpu->edx == 1u;
    if (cpu->edx <= 1u) goto label_0002D8A0;
    cpu->esi = *(uint32_t*)(cpu->ecx);
    x87_v0 = (double)*(float*)(cpu->esp + 0x34u);
    cpu->eax = cpu->edx + (cpu->edx * 2u);
    cpu->eax += cpu->eax;
    x87_v1 = (double)*(float*)(cpu->esi + (cpu->eax * 8u) + 0xFFFFFFD0u);
    cpu->edi = cpu->esi + (cpu->eax * 8u) + 0xFFFFFFD0u;
    { const double lift_left=x87_v1; const double lift_right=x87_v0;  if (!(lift_left<=lift_right)) goto label_0002D5BC; }
    lift_test[0]=(*(uint8_t*)(cpu->edi + 4u)&1u)==0u;
    x87_v0 = x87_v0; 
    if (lift_test[0]) goto label_0002D593;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->esi = cpu->edx;
    cpu->ecx = *(uint16_t*)(cpu->ebp + (cpu->esi * 2u) + 0xFFFFFFFEu);
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->edx = *(uint8_t*)(cpu->edi + 0x14u);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ecx;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x44u))));
    x87_v1 = 1.5259021893143654e-05;
    x87_v0 = (x87_v0) * (x87_v1);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x44u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x44u);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edx;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x44u))));
    x87_v1 = x87_v1 * x87_v2; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    cpu->ecx = *(uint16_t*)(cpu->ebp + (cpu->esi * 2u));
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->edx = *(uint8_t*)(cpu->edi + 0x15u);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ecx;
    cpu->ebx = cpu->eax;
    cpu->eax = *(uint8_t*)(cpu->edi + 0x10u);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x44u))));
    cpu->ebx += cpu->eax;
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x44u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x44u);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edx;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x44u))));
    x87_v1 = x87_v1 * x87_v2; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    cpu->edx = *(uint16_t*)(cpu->ebp + (cpu->esi * 2u) + 2u);
    cpu->edx += *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->ecx = *(uint8_t*)(cpu->edi + 0x11u);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edx;
    cpu->eax += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x44u))));
    cpu->eax = *(uint8_t*)(cpu->edi + 0x16u);
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x44u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x44u);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->eax;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x44u))));
    x87_v1 = x87_v1 * x87_v2; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    cpu->edx = *(uint16_t*)(cpu->ebp + (cpu->esi * 2u) + 4u);
    cpu->edx += *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->ecx = *(uint8_t*)(cpu->edi + 0x12u);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    cpu->eax += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->eax;
    x87_v0 = (x87_v0) * ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    cpu->eax = *(uint8_t*)(cpu->edi + 0x17u);
    *(float*)(cpu->esp + 0x3Cu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v0 = x87_v0 * x87_v1; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
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
    if ((int32_t)(cpu->edi) < (int32_t)(cpu->edx)) goto label_0002D5E4;
    cpu->ecx = cpu->edi + (cpu->edi * 2u);
    cpu->ecx <<= 4u;
    cpu->ecx += cpu->esi;
    label_0002D5CD:
    { const double lift_left=(double)*(float*)(cpu->ecx); const double lift_right=x87_v0; if (lift_left<=lift_right) goto label_0002D5E2; }
    --cpu->edi;
    cpu->ecx -= 0x30u;
    if ((int32_t)cpu->edi >= (int32_t)cpu->edx) goto label_0002D5CD;
    goto label_0002D5E4;
    label_0002D5E2:
    cpu->esi = cpu->ecx;
    label_0002D5E4:
    lift_test[1]=(*(uint8_t*)(cpu->esi + 4u)&1u)==0u;
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esi)));
    x87_v1 = (double)*(float*)(cpu->esi + 0x30u);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x10u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->esi)));
    cpu->eax = *(uint8_t*)(cpu->esi + 0x11u);
    x87_v0 = x87_v0 / x87_v1; 
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
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    x87_v0 = 1.5259021893143654e-05;
    if (lift_test[1]) goto label_0002D709;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->ecx = *(uint16_t*)(cpu->ebp + (cpu->edi * 2u));
    cpu->edx = *(uint8_t*)(cpu->esi + 0x14u);
    cpu->ecx += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x3Cu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v1 = x87_v1 * x87_v2; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->eax = *(uint16_t*)(cpu->ebp + (cpu->edi * 2u) + 2u);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x15u);
    cpu->eax += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x3Cu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v1 = x87_v1 * x87_v2; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    cpu->edx = *(uint16_t*)(cpu->ebp + (cpu->edi * 2u) + 4u);
    *(uint32_t*)(cpu->esp + 0x18u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x18u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->eax = *(uint8_t*)(cpu->esi + 0x16u);
    cpu->edx += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x3Cu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v1 = x87_v1 * x87_v2; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    cpu->ecx = *(uint16_t*)(cpu->ebp + (cpu->edi * 2u) + 6u);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x17u);
    *(uint32_t*)(cpu->esp + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x20u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->ecx += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x3Cu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v1 = x87_v1 * x87_v2; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    *(uint32_t*)(cpu->esp + 0x28u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x28u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    label_0002D709:
    if (((*(uint8_t*)(cpu->esi + 0x34u)) & (1u)) == 0u) goto label_0002D7D7;
    cpu->eax = *(uint16_t*)(cpu->ebp + (cpu->edi * 2u) + 2u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x44u);
    cpu->eax += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x3Cu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v1 = x87_v1 * x87_v2; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    cpu->edx = *(uint16_t*)(cpu->ebp + (cpu->edi * 2u) + 4u);
    *(uint32_t*)(cpu->esp + 0x34u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x34u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->eax = *(uint8_t*)(cpu->esi + 0x45u);
    cpu->edx += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x3Cu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v1 = x87_v1 * x87_v2; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    cpu->ecx = *(uint16_t*)(cpu->ebp + (cpu->edi * 2u) + 6u);
    cpu->edx = *(uint8_t*)(cpu->esi + 0x46u);
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->ecx += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x3Cu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edx;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v1 = x87_v1 * x87_v2; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    *(uint32_t*)(cpu->esp + 0x1Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x1Cu)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->eax = *(uint16_t*)(cpu->ebp + (cpu->edi * 2u) + 8u);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x47u);
    cpu->eax += cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    x87_v0 = (x87_v0) * ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    *(float*)(cpu->esp + 0x3Cu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v0 = x87_v0 * x87_v1; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    *(uint32_t*)(cpu->esp + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x24u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    goto label_0002D7D9;
    label_0002D7D7:
    x87_v0 = x87_v0; 
    label_0002D7D9:
    x87_v0 = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_v0 = (x87_v0) * (255.0);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
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
    cpu->edx -= cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->edx *= cpu->esi;
    cpu->edx = (int32_t)(cpu->edx) >> 8u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint8_t*)(cpu->ecx) = cpu->edx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx -= cpu->eax;
    cpu->edx *= cpu->esi;
    cpu->edx = (int32_t)(cpu->edx) >> 8u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint8_t*)(cpu->ecx + 1u) = cpu->edx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx -= cpu->eax;
    cpu->edx *= cpu->esi;
    cpu->edx = (int32_t)(cpu->edx) >> 8u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint8_t*)(cpu->ecx + 2u) = cpu->edx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx -= cpu->eax;
    cpu->edx *= cpu->esi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->edx = (int32_t)(cpu->edx) >> 8u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->ecx + 3u) = cpu->edx & 0xFFu;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x20u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
    label_0002D8A0:
    if (!sub_pred[0]) goto label_0002D9DD;
    cpu->esi = *(uint32_t*)(cpu->ecx);
    if (((*(uint8_t*)(cpu->esi + 4u)) & (1u)) == 0u) goto label_0002D9B4;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x44u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->eax = *(uint16_t*)(cpu->ebx);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x14u);
    cpu->eax += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v1 = 1.5259021893143654e-05;
    x87_v0 = (x87_v0) * (x87_v1);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x3Cu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v1 = x87_v1 * x87_v2; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    cpu->edi = *(uint8_t*)(cpu->esi + 0x10u);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x15u);
    cpu->edi += cpu->eax;
    cpu->eax = *(uint16_t*)(cpu->ebx + 2u);
    cpu->eax += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x3Cu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v1 = x87_v1 * x87_v2; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    cpu->edx = *(uint8_t*)(cpu->esi + 0x11u);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x16u);
    cpu->eax += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->eax;
    cpu->eax = *(uint16_t*)(cpu->ebx + 4u);
    cpu->eax += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x3Cu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    x87_v2 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v1 = x87_v1 * x87_v2; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v1); 
    cpu->edx = *(uint8_t*)(cpu->esi + 0x12u);
    cpu->ecx = *(uint8_t*)(cpu->esi + 0x17u);
    cpu->eax += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    cpu->eax = *(uint16_t*)(cpu->ebx + 6u);
    cpu->eax += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    x87_v0 = (x87_v0) * ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu)))));
    *(float*)(cpu->esp + 0x3Cu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v0 = x87_v0 * x87_v1; 
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
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
__declspec(noinline) void sfera_sub_0042D9F0(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1]; bool sub_pred[1]; double x87_v0, x87_v1, x87_v2, x87_v3;
    bool lift_cmp[1];
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    sub_pred[0] = cpu->edi == 1u;
    if (cpu->edi <= 1u) goto label_0002DE96;
    cpu->esi = *(uint32_t*)(cpu->ecx);
    x87_v0 = (double)*(float*)(cpu->esp + 0x2Cu);
    cpu->eax = cpu->edi + (cpu->edi * 2u);
    cpu->eax += cpu->eax;
    x87_v1 = (double)*(float*)(cpu->esi + (cpu->eax * 8u) + 0xFFFFFFD0u);
    cpu->edx = cpu->esi + (cpu->eax * 8u) + 0xFFFFFFD0u;
    lift_cmp[0]=x87_v1<=x87_v0;
    lift_push32(cpu, cpu->ebp);
    if (!lift_cmp[0]) goto label_0002DB7F;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    x87_v0 = x87_v0; 
    if ((((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_0002DAB7;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->ecx = cpu->edi;
    cpu->esi = *(uint16_t*)(cpu->eax + (cpu->ecx * 2u));
    cpu->eax = cpu->eax + (cpu->ecx * 2u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->esi += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->esi;
    cpu->esi = *(uint16_t*)(cpu->eax + 2u);
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u))));
    x87_v1 = 1.5259021893143654e-05;
    cpu->eax = *(uint16_t*)(cpu->eax + 0xFFFFFFFEu);
    x87_v0 = (x87_v0) * (x87_v1);
    cpu->esi += cpu->ecx;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->esi;
    *(float*)(cpu->esp + 0x38u) = x87_v1; 
    cpu->eax += cpu->ecx;
    cpu->ebp = lift_pop32(cpu);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edi = lift_pop32(cpu);
    x87_v1 = (x87_v1) * (x87_v0);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    *(float*)(cpu->esp + 0x2Cu) = x87_v1; 
    x87_v0 = (x87_v0) * ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x30u)))));
    *(float*)(cpu->esp + 0x30u) = x87_v0; 
    *(float*)(cpu->eax) = (((((((double)*(float*)(cpu->esp + 0x30u))) * (((double)*(float*)(cpu->edx + 0x24u)))))) + (((double)*(float*)(cpu->edx + 0x18u))));
    *(float*)(cpu->eax + 4u) = (((((((double)*(float*)(cpu->edx + 0x28u))) * (((double)*(float*)(cpu->esp + 0x28u)))))) + (((double)*(float*)(cpu->edx + 0x1Cu))));
    *(float*)(cpu->eax + 8u) = (((((((double)*(float*)(cpu->edx + 0x2Cu))) * (((double)*(float*)(cpu->esp + 0x2Cu)))))) + (((double)*(float*)(cpu->edx + 0x20u))));
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
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u))));
    x87_v1 = 1.5259021893143654e-05;
    cpu->ebp -= cpu->ebx;
    cpu->ebx = *(uint16_t*)(cpu->ecx + (cpu->eax * 2u) + 0xFFFFFFFEu);
    x87_v0 = (x87_v0) * (x87_v1);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    cpu->ecx = *(uint16_t*)(cpu->ecx + (cpu->eax * 2u));
    *(float*)(cpu->esp + 0x38u) = x87_v1; 
    cpu->ebp -= cpu->esi;
    cpu->ebp += cpu->edi;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ebp;
    cpu->ebx -= cpu->ecx;
    cpu->ebx -= cpu->esi;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u))));
    cpu->ebx += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ebx;
    cpu->ebp = lift_pop32(cpu);
    x87_v1 = (x87_v1) * (x87_v0);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    *(float*)(cpu->esp + 0x2Cu) = x87_v1; 
    x87_v0 = (x87_v0) * ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x30u)))));
    *(float*)(cpu->esp + 0x30u) = x87_v0; 
    *(float*)(cpu->eax) = (((((((double)*(float*)(cpu->esp + 0x30u))) * (((double)*(float*)(cpu->edx + 0x24u)))))) + (((double)*(float*)(cpu->edx + 0x18u))));
    *(float*)(cpu->eax + 4u) = (((((((double)*(float*)(cpu->edx + 0x28u))) * (((double)*(float*)(cpu->esp + 0x28u)))))) + (((double)*(float*)(cpu->edx + 0x1Cu))));
    *(float*)(cpu->eax + 8u) = (((((((double)*(float*)(cpu->edx + 0x2Cu))) * (((double)*(float*)(cpu->esp + 0x2Cu)))))) + (((double)*(float*)(cpu->edx + 0x20u))));
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
    if (((cpu->edx)&0x80000000u)!=0u) goto label_0002DBA3;
    cpu->edi = cpu->edx + (cpu->edx * 2u);
    cpu->edi <<= 4u;
    cpu->edi += cpu->esi;
    label_0002DB8E:
    { const double lift_left=(double)*(float*)(cpu->edi); const double lift_right=x87_v0; if (lift_left<=lift_right) goto label_0002DBA1; }
    cpu->edi -= 0x30u;
    if ((int32_t)(--cpu->edx) >= 0) goto label_0002DB8E;
    goto label_0002DBA3;
    label_0002DBA1:
    cpu->esi = cpu->edi;
    label_0002DBA3:
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esi)));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18u);
    x87_v1 = (double)*(float*)(cpu->esi + 0x30u);
    cpu->ebx = *(uint32_t*)(cpu->esi + 4u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->esi)));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    x87_v0 = x87_v0 / x87_v1; 
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
    *(float*)(cpu->esp + 0x30u) = x87_v0; 
    x87_v0 = 1.5259021893143654e-05;
    if ((((cpu->ebx & 0xFFu)) & (1u)) == 0u) goto label_0002DC5B;
    cpu->edi = *(uint16_t*)(cpu->eax + (cpu->edx * 2u));
    cpu->edi += cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->edi;
    cpu->edi = *(uint16_t*)(cpu->eax + (cpu->edx * 2u) + 2u);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u))));
    cpu->edi += cpu->ebp;
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x40u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x40u);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->edi;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + 0x24u)));
    cpu->edi = *(uint16_t*)(cpu->eax + (cpu->edx * 2u) + 4u);
    cpu->edi += cpu->ebp;
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 0x20u) = x87_v1; 
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u))));
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x40u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x40u);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->edi;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + 0x28u)));
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esp + 0x24u)));
    *(float*)(cpu->esp + 0x24u) = x87_v1; 
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u))));
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x40u) = x87_v1; 
    *(float*)(cpu->esp + 0x28u) = (((((((double)*(float*)(cpu->esp + 0x40u))) * (((double)*(float*)(cpu->esi + 0x2Cu)))))) + (((double)*(float*)(cpu->esp + 0x28u))));
    label_0002DC5B:
    lift_test[0]=(*(uint8_t*)(cpu->esi + 0x34u)&1u)==0u;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x3Cu);
    if (lift_test[0]) goto label_0002DCD5;
    cpu->ecx = *(uint16_t*)(cpu->eax + (cpu->edx * 2u) + 2u);
    cpu->ecx += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ecx;
    cpu->ecx = *(uint16_t*)(cpu->eax + (cpu->edx * 2u) + 4u);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u))));
    cpu->ecx += cpu->edi;
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x40u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x40u);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ecx;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + 0x54u)));
    cpu->ecx = *(uint16_t*)(cpu->eax + (cpu->edx * 2u) + 6u);
    cpu->ecx += cpu->edi;
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esp + 0x14u) = x87_v1; 
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u))));
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x40u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x40u);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ecx;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + 0x58u)));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0x18u) = x87_v1; 
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u))));
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x40u) = x87_v1; 
    *(float*)(cpu->esp + 0x1Cu) = (((((((double)*(float*)(cpu->esp + 0x40u))) * (((double)*(float*)(cpu->esi + 0x5Cu)))))) + (((double)*(float*)(cpu->esp + 0x1Cu))));
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
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u))));
    cpu->ebx -= cpu->ecx;
    cpu->ecx = *(uint16_t*)(cpu->eax + (cpu->edx * 2u) + 0xAu);
    x87_v1 = (x87_v1) * (x87_v0);
    cpu->ebx -= cpu->edi;
    *(float*)(cpu->esp + 0x40u) = x87_v1; 
    cpu->ebx += cpu->ebp;
    x87_v1 = (double)*(float*)(cpu->esp + 0x40u);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ebx;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + 0x24u)));
    cpu->ebx = *(uint16_t*)(cpu->eax + (cpu->edx * 2u) + 8u);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esp + 0x20u)));
    cpu->ebx -= cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx -= cpu->edi;
    *(float*)(cpu->esp + 0x20u) = x87_v1; 
    cpu->ebx += cpu->ebp;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u))));
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x40u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x40u);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ebx;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + 0x28u)));
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esp + 0x24u)));
    *(float*)(cpu->esp + 0x24u) = x87_v1; 
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u))));
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x40u) = x87_v1; 
    *(float*)(cpu->esp + 0x28u) = (((((((double)*(float*)(cpu->esp + 0x40u))) * (((double)*(float*)(cpu->esi + 0x2Cu)))))) + (((double)*(float*)(cpu->esp + 0x28u))));
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
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u))));
    cpu->ecx -= cpu->ebx;
    cpu->ecx -= cpu->edi;
    x87_v1 = (x87_v1) * (x87_v0);
    cpu->ecx += cpu->ebp;
    *(float*)(cpu->esp + 0x40u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x40u);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ecx;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + 0x54u)));
    cpu->ecx = *(uint16_t*)(cpu->eax + (cpu->edx * 2u) + 0xCu);
    cpu->edx = *(uint16_t*)(cpu->eax + (cpu->edx * 2u) + 8u);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esp + 0x14u)));
    cpu->edx -= cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0x14u) = x87_v1; 
    cpu->edx -= cpu->edi;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u))));
    cpu->edx += cpu->ebp;
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->esp + 0x40u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x40u);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->edx;
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + 0x58u)));
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0x18u) = x87_v1; 
    x87_v0 = (x87_v0) * ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x40u)))));
    *(float*)(cpu->esp + 0x40u) = x87_v0; 
    *(float*)(cpu->esp + 0x1Cu) = (((((((double)*(float*)(cpu->esp + 0x40u))) * (((double)*(float*)(cpu->esi + 0x5Cu)))))) + (((double)*(float*)(cpu->esp + 0x1Cu))));
    goto label_0002DDFF;
    label_0002DDFD:
    x87_v0 = x87_v0; 
    label_0002DDFF:
    if (((*(uint8_t*)(cpu->ecx + 8u)) & (1u)) == 0u) goto label_0002DE44;
    *(float*)(cpu->esp + 0x40u) = ((((double)*(float*)(cpu->esp + 0x30u))) * (3.1415929794311523));
    x87_v0 = (double)*(float*)(cpu->esp + 0x40u);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 0x40u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x40u);
    x87_v1 = 1.0;
    x87_v0 = x87_v1 - x87_v0; 
    x87_v0 = (x87_v0) * (0.5);
    *(float*)(cpu->esp + 0x40u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x20u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 - x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x40u);
    goto label_0002DE54;
    label_0002DE44:
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x20u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 - x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x30u);
    label_0002DE54:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    x87_v3 = x87_v2;
    x87_v0 = x87_v0 * x87_v3; 
    cpu->ebp = lift_pop32(cpu);
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    x87_v1 = x87_v1 + x87_v2; 
    cpu->ebx = lift_pop32(cpu);
    *(float*)(cpu->eax) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 8u);
    x87_v2 = (double)*(float*)(cpu->esp + 0x14u); x87_v3 = x87_v2;
    x87_v1 = x87_v1 - x87_v3; 
    x87_v3 = x87_v0;
    x87_v1 = x87_v1 * x87_v3; 
    x87_v1 = x87_v1 + x87_v2; 
    *(float*)(cpu->eax + 4u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0xCu);
    x87_v2 = (double)*(float*)(cpu->esp + 0x18u); x87_v3 = x87_v2;
    x87_v1 = x87_v1 - x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 * x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->eax + 8u) = x87_v0; 
    cpu->esp += 0x1Cu;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
    label_0002DE96:
    if (!sub_pred[0]) goto label_0002DFE1;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    if ((((cpu->ecx & 0xFFu)) & (1u)) == 0u) goto label_0002DF22;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->esi = *(uint16_t*)(cpu->ecx + 2u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->esi += cpu->edx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->esi;
    cpu->esi = *(uint16_t*)(cpu->ecx + 4u);
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v1 = 1.5259021893143654e-05;
    cpu->ecx = *(uint16_t*)(cpu->ecx);
    x87_v0 = (x87_v0) * (x87_v1);
    cpu->esi += cpu->edx;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->esi;
    *(float*)(cpu->esp + 0x34u) = x87_v1; 
    cpu->ecx += cpu->edx;
    cpu->edi = lift_pop32(cpu);
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x38u))));
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->esi = lift_pop32(cpu);
    x87_v1 = (x87_v1) * (x87_v0);
    cpu->ebx = lift_pop32(cpu);
    *(float*)(cpu->esp + 0x2Cu) = x87_v1; 
    x87_v0 = (x87_v0) * ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x30u)))));
    *(float*)(cpu->esp + 0x30u) = x87_v0; 
    *(float*)(cpu->ecx) = (((((((double)*(float*)(cpu->esp + 0x30u))) * (((double)*(float*)(cpu->eax + 0x24u)))))) + (((double)*(float*)(cpu->eax + 0x18u))));
    *(float*)(cpu->ecx + 4u) = (((((((double)*(float*)(cpu->eax + 0x28u))) * (((double)*(float*)(cpu->esp + 0x28u)))))) + (((double)*(float*)(cpu->eax + 0x1Cu))));
    *(float*)(cpu->ecx + 8u) = (((((((double)*(float*)(cpu->eax + 0x2Cu))) * (((double)*(float*)(cpu->esp + 0x2Cu)))))) + (((double)*(float*)(cpu->eax + 0x20u))));
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
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    x87_v1 = 1.5259021893143654e-05;
    cpu->ebx -= cpu->edi;
    cpu->edi = *(uint16_t*)(cpu->ecx + 2u);
    x87_v0 = (x87_v0) * (x87_v1);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    cpu->ecx = *(uint16_t*)(cpu->ecx);
    *(float*)(cpu->esp + 0x34u) = x87_v1; 
    cpu->ebx -= cpu->edx;
    cpu->ebx += cpu->esi;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ebx;
    cpu->ecx -= cpu->edi;
    cpu->ecx -= cpu->edx;
    x87_v1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x3Cu))));
    cpu->ecx += cpu->esi;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    x87_v1 = (x87_v1) * (x87_v0);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    *(float*)(cpu->esp + 0x2Cu) = x87_v1; 
    x87_v0 = (x87_v0) * ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x30u)))));
    *(float*)(cpu->esp + 0x30u) = x87_v0; 
    *(float*)(cpu->ecx) = (((((((double)*(float*)(cpu->esp + 0x30u))) * (((double)*(float*)(cpu->eax + 0x24u)))))) + (((double)*(float*)(cpu->eax + 0x18u))));
    *(float*)(cpu->ecx + 4u) = (((((((double)*(float*)(cpu->eax + 0x28u))) * (((double)*(float*)(cpu->esp + 0x28u)))))) + (((double)*(float*)(cpu->eax + 0x1Cu))));
    *(float*)(cpu->ecx + 8u) = (((((((double)*(float*)(cpu->eax + 0x2Cu))) * (((double)*(float*)(cpu->esp + 0x2Cu)))))) + (((double)*(float*)(cpu->eax + 0x20u))));
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
    x87_v0 = 0.0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->eax + 8u) = x87_v0;
    cpu->esi = lift_pop32(cpu);
    *(float*)(cpu->eax + 4u) = x87_v0;
    *(float*)(cpu->eax) = x87_v0; 
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
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
__declspec(noinline) void sfera_sub_0042E250(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    std::construct_at(reinterpret_cast<COutputLogDevice*>(cpu->esi));
    sub_pred[0] = *(uint32_t*)(cpu->esi + 8u) == 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if (sub_pred[0]) goto label_0002E2A7;
    cpu->edx = 0xA0u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E29Bu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42E29Bu));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E2A4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42E2A4u));
    cpu->esp += 4u;
    label_0002E2A7:
    sub_pred[1] = *(uint32_t*)(cpu->esi + 4u) == 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    std::construct_at(reinterpret_cast<IOutputDevice*>(cpu->esi));
    if (sub_pred[1]) goto label_0002E2D6;
    cpu->edx = 0x65u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\ErrorLog.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E2CAu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x42E2CAu));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E2D3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x42E2D3u));
    cpu->esp += 4u;
    label_0002E2D6:
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
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->eax;
    if (cpu->eax == 0u) goto label_0002E3DE;
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
    lift_native_call(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x2E3A7u));
    lift_push32(cpu, (uintptr_t)" Sphere log file\n"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x2E3AFu));
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_localtime64), LIFT_CODE_TOKEN_VA(0x42E3B6u));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::asctime), LIFT_CODE_TOKEN_VA(0x42E3BDu));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)" Log file created on %s"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x2E3CAu));
    lift_push32(cpu, (uintptr_t)"--------------------------------------------------------------------------------\n\n"); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x2E3D2u));
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
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::vsprintf)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u), *(uint32_t*)(cpu->esp + 0x8u));
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
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::vsprintf)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u), *(uint32_t*)(cpu->esp + 0x8u));
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
    cpu->ebx = cpu->esp;
    if (*(uint8_t*)(cpu->ebp + 0xCu) == 0u) goto label_0002E701;
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

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fopen)))(cpu->eax, (uintptr_t)"r");

    if (cpu->eax == 0u) goto label_0002E844;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::fclose);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fclose)))(*(uint32_t*)(cpu->esp));
    cpu->ecx = (uintptr_t)"client-Crash.1";
    lift_push32(cpu, (uintptr_t)"w"); lift_push32(cpu, cpu->ecx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fopen)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u));
    cpu->edi = native_function_address32(&::remove);
    cpu->esi = cpu->eax;
    cpu->esp += 0xCu;
    if (cpu->esi == 0u) goto label_0002E82E;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x3E8u);
    cpu->edx = (uintptr_t)"ERRORLOG.TXT";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E7CAu)); sfera_sub_0042E6B0(cpu, LIFT_CODE_TOKEN_VA(0x42E7CAu));

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::remove)))((uintptr_t)"ERRORLOG.TXT");

    lift_push32(cpu, 1u); lift_push32(cpu, 0x258u);
    cpu->edx = (uintptr_t)"Error.log";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E7E7u)); sfera_sub_0042E6B0(cpu, LIFT_CODE_TOKEN_VA(0x42E7E7u));

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::remove)))((uintptr_t)"Error.log");

    lift_push32(cpu, 1u); lift_push32(cpu, 0xC8u);
    cpu->edx = (uintptr_t)"Warnings00.log";
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E804u)); sfera_sub_0042E6B0(cpu, LIFT_CODE_TOKEN_VA(0x42E804u));
    lift_push32(cpu, (uintptr_t)"Warnings00.log");
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::remove)))(*(uint32_t*)(cpu->esp));
    cpu->edx = (uintptr_t)"error-Cause.1";
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x32u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42E81Fu)); sfera_sub_0042E6B0(cpu, LIFT_CODE_TOKEN_VA(0x42E81Fu));
    cpu->edx = (uintptr_t)"error-Cause.1";
    lift_push32(cpu, cpu->edx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::remove)))(*(uint32_t*)(cpu->esp));
    lift_push32(cpu, cpu->esi);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fclose)))(*(uint32_t*)(cpu->esp));
    cpu->esp += 8u;
    label_0002E82E:
    cpu->eax = (uintptr_t)"error-Cause.1";
    lift_push32(cpu, cpu->eax);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::remove)))(*(uint32_t*)(cpu->esp));
    cpu->ecx = (uintptr_t)"app-is-Run.1";
    lift_push32(cpu, cpu->ecx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::remove)))(*(uint32_t*)(cpu->esp));
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
    { auto* client = g_sfera_directplay_runtime.peer; DWORD async_handle = 0u; const SferaDpnBufferDescRuntime buffer{0x800u, reinterpret_cast<void*>(static_cast<uintptr_t>(cpu->esp + 0x10u))}; if (client) cpu->eax = static_cast<uint32_t>(client->Send(&buffer, 1u, 0x2BF20u, nullptr, &async_handle, 0xB8u)); }
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
__declspec(noinline) void sfera_sub_0042EBD0(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_file_runtime.error_reporting_enabled = 1u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042EBE0(LiftCpu* cpu, uint32_t stop_address) {
    g_sfera_file_runtime.error_reporting_enabled = 0u;
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
    sfera_report_file_error(cpu, 0u, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x2EDB5u));
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
    sfera_report_file_error(cpu, 1u, cpu->esi, LIFT_CODE_TOKEN_RVA(0x2EF12u));
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
    sfera_report_file_error(cpu, 2u, *(uint32_t*)(g_sfera_file_runtime.open_files.data + (cpu->esi * 8u)), LIFT_CODE_TOKEN_RVA(0x2EFB1u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0002EFBD:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_file_runtime.open_files.capacity) goto label_0002EFD1;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2EFD1u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2EFD1u));
    label_0002EFD1:
    sfera_report_file_error(cpu, 3u, *(uint32_t*)(g_sfera_file_runtime.open_files.data + (cpu->esi * 8u)), LIFT_CODE_TOKEN_RVA(0x2EFF1u));
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
    sfera_report_file_error(cpu, 4u, *(uint32_t*)(g_sfera_file_runtime.open_files.data + (cpu->esi * 8u)), LIFT_CODE_TOKEN_RVA(0x2F091u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0002F09D:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_file_runtime.open_files.capacity) goto label_0002F0B1;
    cpu->edx = (uintptr_t)&g_sfera_file_runtime.open_files;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x2F0B1u)); sfera_sub_00401030(cpu, LIFT_CODE_TOKEN_RVA(0x2F0B1u));
    label_0002F0B1:
    sfera_report_file_error(cpu, 5u, *(uint32_t*)(g_sfera_file_runtime.open_files.data + (cpu->esi * 8u)), LIFT_CODE_TOKEN_RVA(0x2F0D1u));
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
    sfera_report_file_error(cpu, 6u, *(uint32_t*)(g_sfera_file_runtime.open_files.data + (cpu->esi * 8u)), LIFT_CODE_TOKEN_RVA(0x2F16Cu));
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
    sfera_report_file_error(cpu, 7u, *(uint32_t*)(g_sfera_file_runtime.open_files.data + (cpu->esi * 8u)), LIFT_CODE_TOKEN_RVA(0x2F296u));
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
__declspec(noinline) void sfera_sub_0042F3E0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    x87_v0 = (double)*(float*)(cpu->esi + 4u);
    x87_v1 = (double)*(float*)(cpu->esi);
    x87_v2 = (double)*(float*)(cpu->esi + 8u);
    x87_v3 = x87_v1;
    x87_v1 = x87_v1 * x87_v3; 
    x87_v3 = x87_v0;
    x87_v0 = x87_v0 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 + x87_v2; 
    x87_v1 = (x87_v1) * (x87_v1);
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 4u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 4u);
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 4u);
    x87_v0 = (double)*(float*)(cpu->esp + 4u); x87_v1 = x87_v0;
    x87_v2 = 0.0;
    { const double lift_left=x87_v2; const double lift_right=x87_v1;   if (lift_left==lift_right) goto label_0002F43D; }
    x87_v1 = (double)*(float*)(cpu->esi);
    x87_v1 = (x87_v1) / (x87_v0);
    *(float*)(cpu->esi) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esi + 4u);
    x87_v1 = (x87_v1) / (x87_v0);
    *(float*)(cpu->esi + 4u) = x87_v1; 
    x87_v0 = (((double)*(float*)(cpu->esi + 8u))) / (x87_v0);
    *(float*)(cpu->esi + 8u) = x87_v0; 
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0002F43D:
    x87_v0 = x87_v0; 
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042F450(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5;
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
    cpu->ebp -= cpu->ecx;
    cpu->ebx >>= 2u;
    ++cpu->ebx;
    cpu->eax = cpu->ecx + 8u;
    cpu->esi = cpu->edi + 0xCu;
    cpu->ecx = cpu->ebx * 4u;
    label_0002F490:
    x87_v0 = (double)*(float*)(cpu->eax + 0xFFFFFFF8u);
    cpu->edi = *(uint32_t*)(cpu->edx);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->eax + 0xFFFFFFFCu);
    *(float*)(cpu->esp + 0x18u) = (double)*(float*)(cpu->eax);
    x87_v0 = (double)*(float*)(cpu->edi + 4u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x14u); x87_v3 = x87_v2;
    x87_v3 = (x87_v3) * (((double)*(float*)(cpu->edi)));
    x87_v0 = x87_v0 + x87_v3; 
    x87_v3 = (double)*(float*)(cpu->edi + 8u);
    x87_v4 = (double)*(float*)(cpu->esp + 0x18u); x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v0; x87_v0 = temporary; }
    x87_v3 = x87_v3 + x87_v4; 
    x87_v3 = (x87_v3) + (((double)*(float*)(cpu->edi + 0xCu)));
    *(float*)(cpu->esi + 0xFFFFFFF4u) = x87_v3; 
    cpu->edi = *(uint32_t*)(cpu->edx);
    x87_v3 = (double)*(float*)(cpu->edi + 0x14u);
    x87_v3 = (x87_v3) * (x87_v1);
    x87_v4 = (double)*(float*)(cpu->edi + 0x10u);
    x87_v4 = (x87_v4) * (x87_v2);
    x87_v3 = x87_v3 + x87_v4; 
    x87_v4 = (double)*(float*)(cpu->edi + 0x18u);
    x87_v4 = (x87_v4) * (x87_v0);
    x87_v3 = x87_v3 + x87_v4; 
    x87_v3 = (x87_v3) + (((double)*(float*)(cpu->edi + 0x1Cu)));
    *(float*)(cpu->esi + 0xFFFFFFF8u) = x87_v3; 
    cpu->edi = *(uint32_t*)(cpu->edx);
    x87_v3 = (double)*(float*)(cpu->edi + 0x24u);
    x87_v1 = x87_v1 * x87_v3; 
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->edi + 0x20u)));
    x87_v1 = x87_v1 + x87_v2; 
    x87_v2 = (double)*(float*)(cpu->edi + 0x28u);
    x87_v0 = x87_v0 * x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->edi + 0x2Cu)));
    *(float*)(cpu->eax + cpu->ebp) = x87_v0; 
    cpu->edi = *(uint32_t*)(cpu->edx);
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->eax + 4u);
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->eax + 8u);
    *(float*)(cpu->esp + 0x18u) = (double)*(float*)(cpu->eax + 0xCu);
    x87_v0 = (double)*(float*)(cpu->edi + 4u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x14u); x87_v3 = x87_v2;
    x87_v3 = (x87_v3) * (((double)*(float*)(cpu->edi)));
    x87_v0 = x87_v0 + x87_v3; 
    x87_v3 = (double)*(float*)(cpu->edi + 8u);
    x87_v4 = (double)*(float*)(cpu->esp + 0x18u); x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v0; x87_v0 = temporary; }
    x87_v3 = x87_v3 + x87_v4; 
    x87_v3 = (x87_v3) + (((double)*(float*)(cpu->edi + 0xCu)));
    *(float*)(cpu->esi) = x87_v3; 
    cpu->edi = *(uint32_t*)(cpu->edx);
    x87_v3 = (double)*(float*)(cpu->edi + 0x14u);
    x87_v3 = (x87_v3) * (x87_v1);
    x87_v4 = (double)*(float*)(cpu->edi + 0x10u);
    x87_v4 = (x87_v4) * (x87_v2);
    x87_v3 = x87_v3 + x87_v4; 
    x87_v4 = (double)*(float*)(cpu->edi + 0x18u);
    x87_v4 = (x87_v4) * (x87_v0);
    x87_v3 = x87_v3 + x87_v4; 
    x87_v3 = (x87_v3) + (((double)*(float*)(cpu->edi + 0x1Cu)));
    *(float*)(cpu->esi + 4u) = x87_v3; 
    cpu->edi = *(uint32_t*)(cpu->edx);
    x87_v3 = (double)*(float*)(cpu->edi + 0x24u);
    x87_v1 = x87_v1 * x87_v3; 
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->edi + 0x20u)));
    x87_v1 = x87_v1 + x87_v2; 
    x87_v2 = (double)*(float*)(cpu->edi + 0x28u);
    x87_v0 = x87_v0 * x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->edi + 0x2Cu)));
    *(float*)(cpu->esi + 8u) = x87_v0; 
    cpu->edi = *(uint32_t*)(cpu->edx);
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->eax + 0x10u);
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->eax + 0x14u);
    *(float*)(cpu->esp + 0x18u) = (double)*(float*)(cpu->eax + 0x18u);
    x87_v0 = (double)*(float*)(cpu->edi + 4u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x14u); x87_v3 = x87_v2;
    x87_v3 = (x87_v3) * (((double)*(float*)(cpu->edi)));
    x87_v0 = x87_v0 + x87_v3; 
    x87_v3 = (double)*(float*)(cpu->edi + 8u);
    x87_v4 = (double)*(float*)(cpu->esp + 0x18u); x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v0; x87_v0 = temporary; }
    x87_v3 = x87_v3 + x87_v4; 
    x87_v3 = (x87_v3) + (((double)*(float*)(cpu->edi + 0xCu)));
    *(float*)(cpu->esi + 0xCu) = x87_v3; 
    cpu->edi = *(uint32_t*)(cpu->edx);
    x87_v3 = (double)*(float*)(cpu->edi + 0x14u);
    x87_v3 = (x87_v3) * (x87_v1);
    x87_v4 = (double)*(float*)(cpu->edi + 0x10u);
    x87_v4 = (x87_v4) * (x87_v2);
    x87_v3 = x87_v3 + x87_v4; 
    x87_v4 = (double)*(float*)(cpu->edi + 0x18u);
    x87_v4 = (x87_v4) * (x87_v0);
    x87_v3 = x87_v3 + x87_v4; 
    x87_v3 = (x87_v3) + (((double)*(float*)(cpu->edi + 0x1Cu)));
    *(float*)(cpu->esi + 0x10u) = x87_v3; 
    cpu->edi = *(uint32_t*)(cpu->edx);
    x87_v3 = (double)*(float*)(cpu->edi + 0x24u);
    x87_v1 = x87_v1 * x87_v3; 
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->edi + 0x20u)));
    x87_v1 = x87_v1 + x87_v2; 
    x87_v2 = (double)*(float*)(cpu->edi + 0x28u);
    x87_v0 = x87_v0 * x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->edi + 0x2Cu)));
    *(float*)(cpu->esi + 0x14u) = x87_v0; 
    cpu->edi = *(uint32_t*)(cpu->edx);
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->eax + 0x1Cu);
    *(float*)(cpu->esp + 0x10u) = (double)*(float*)(cpu->eax + 0x20u);
    *(float*)(cpu->esp + 0x18u) = (double)*(float*)(cpu->eax + 0x24u);
    x87_v0 = (double)*(float*)(cpu->edi + 4u);
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x14u); x87_v3 = x87_v2;
    x87_v3 = (x87_v3) * (((double)*(float*)(cpu->edi)));
    x87_v0 = x87_v0 + x87_v3; 
    x87_v3 = (double)*(float*)(cpu->edi + 8u);
    x87_v4 = (double)*(float*)(cpu->esp + 0x18u); x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v0; x87_v0 = temporary; }
    x87_v3 = x87_v3 + x87_v4; 
    x87_v3 = (x87_v3) + (((double)*(float*)(cpu->edi + 0xCu)));
    *(float*)(cpu->esi + 0x18u) = x87_v3; 
    cpu->edi = *(uint32_t*)(cpu->edx);
    x87_v3 = (double)*(float*)(cpu->edi + 0x14u);
    x87_v3 = (x87_v3) * (x87_v1);
    x87_v4 = (double)*(float*)(cpu->edi + 0x10u);
    x87_v4 = (x87_v4) * (x87_v2);
    x87_v3 = x87_v3 + x87_v4; 
    x87_v4 = (double)*(float*)(cpu->edi + 0x18u);
    x87_v4 = (x87_v4) * (x87_v0);
    cpu->eax += 0x30u;
    cpu->esi += 0x30u;
    --cpu->ebx;
    x87_v3 = x87_v3 + x87_v4; 
    x87_v3 = (x87_v3) + (((double)*(float*)(cpu->edi + 0x1Cu)));
    *(float*)(cpu->esi + 0xFFFFFFECu) = x87_v3; 
    cpu->edi = *(uint32_t*)(cpu->edx);
    x87_v3 = (double)*(float*)(cpu->edi + 0x24u);
    x87_v1 = x87_v1 * x87_v3; 
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->edi + 0x20u)));
    x87_v1 = x87_v1 + x87_v2; 
    x87_v2 = (double)*(float*)(cpu->edi + 0x28u);
    x87_v0 = x87_v0 * x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->edi + 0x2Cu)));
    *(float*)(cpu->esi + 0xFFFFFFF0u) = x87_v0; 
    if (cpu->ebx != 0u) goto label_0002F490;
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
    x87_v0 = (double)*(float*)(cpu->eax + 0xFFFFFFF8u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    cpu->eax += 0xCu;
    x87_v0 = (double)*(float*)(cpu->eax + 0xFFFFFFF0u);
    cpu->esi += 0xCu;
    --cpu->ebx;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    *(float*)(cpu->esp + 0x14u) = (double)*(float*)(cpu->eax + 0xFFFFFFF4u);
    x87_v0 = (double)*(float*)(cpu->ecx + 4u);
    x87_v1 = (double)*(float*)(cpu->esp + 0xCu); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x10u); x87_v3 = x87_v2;
    x87_v3 = (x87_v3) * (((double)*(float*)(cpu->ecx)));
    x87_v0 = x87_v0 + x87_v3; 
    x87_v3 = (double)*(float*)(cpu->ecx + 8u);
    x87_v4 = (double)*(float*)(cpu->esp + 0x14u); x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v0; x87_v0 = temporary; }
    x87_v3 = x87_v3 + x87_v4; 
    x87_v3 = (x87_v3) + (((double)*(float*)(cpu->ecx + 0xCu)));
    *(float*)(cpu->esi + 0xFFFFFFF4u) = x87_v3; 
    cpu->ecx = *(uint32_t*)(cpu->edx);
    x87_v3 = (double)*(float*)(cpu->ecx + 0x14u);
    x87_v3 = (x87_v3) * (x87_v1);
    x87_v4 = (double)*(float*)(cpu->ecx + 0x10u);
    x87_v4 = (x87_v4) * (x87_v2);
    x87_v3 = x87_v3 + x87_v4; 
    x87_v4 = (double)*(float*)(cpu->ecx + 0x18u);
    x87_v4 = (x87_v4) * (x87_v0);
    x87_v3 = x87_v3 + x87_v4; 
    x87_v3 = (x87_v3) + (((double)*(float*)(cpu->ecx + 0x1Cu)));
    *(float*)(cpu->esi + 0xFFFFFFF8u) = x87_v3; 
    cpu->ecx = *(uint32_t*)(cpu->edx);
    x87_v3 = (double)*(float*)(cpu->ecx + 0x24u);
    x87_v1 = x87_v1 * x87_v3; 
    x87_v2 = (x87_v2) * (((double)*(float*)(cpu->ecx + 0x20u)));
    x87_v1 = x87_v1 + x87_v2; 
    x87_v2 = (double)*(float*)(cpu->ecx + 0x28u);
    x87_v0 = x87_v0 * x87_v2; 
    x87_v0 = x87_v0 + x87_v1; 
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->ecx + 0x2Cu)));
    *(float*)(cpu->eax + cpu->edi + 0xFFFFFFF4u) = x87_v0; 
    if (cpu->ebx != 0u) goto label_0002F6A0;
    label_0002F71F:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042F730(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5;
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->esi;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    x87_v0 = (double)*(float*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->eax + 0xCu)));
    cpu->esi = lift_pop32(cpu);
    *(float*)(cpu->esp) = x87_v0; 
    *(float*)(cpu->esp + 0xCu) = ((((double)*(float*)(cpu->ecx + 4u))) - (((double)*(float*)(cpu->eax + 0x1Cu))));
    *(float*)(cpu->esp + 4u) = ((((double)*(float*)(cpu->ecx + 8u))) - (((double)*(float*)(cpu->eax + 0x2Cu))));
    x87_v0 = (double)*(float*)(cpu->eax + 0x10u);
    x87_v1 = (double)*(float*)(cpu->esp + 0xCu); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v2 = (double)*(float*)(cpu->eax);
    x87_v3 = (double)*(float*)(cpu->esp); x87_v4 = x87_v3;
    x87_v2 = x87_v2 * x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    x87_v2 = x87_v2 + x87_v3; 
    x87_v3 = (double)*(float*)(cpu->eax + 0x20u);
    x87_v4 = (double)*(float*)(cpu->esp + 4u); x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v2; x87_v2 = temporary; }
    x87_v3 = x87_v3 + x87_v4; 
    *(float*)(cpu->ecx) = x87_v3; 
    cpu->eax = *(uint32_t*)(cpu->edx);
    x87_v3 = (double)*(float*)(cpu->eax + 0x14u);
    x87_v3 = (x87_v3) * (x87_v1);
    x87_v4 = (double)*(float*)(cpu->eax + 4u);
    x87_v4 = (x87_v4) * (x87_v0);
    x87_v3 = x87_v3 + x87_v4; 
    x87_v4 = (double)*(float*)(cpu->eax + 0x24u);
    x87_v4 = (x87_v4) * (x87_v2);
    x87_v3 = x87_v3 + x87_v4; 
    *(float*)(cpu->ecx + 4u) = x87_v3; 
    cpu->edx = *(uint32_t*)(cpu->edx);
    x87_v3 = (double)*(float*)(cpu->edx + 0x18u);
    x87_v1 = x87_v1 * x87_v3; 
    x87_v3 = (double)*(float*)(cpu->edx + 8u);
    x87_v0 = x87_v0 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 + x87_v2; 
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->edx + 0x28u)));
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->ecx + 8u) = x87_v0; 
    cpu->esp += 8u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0042F7D0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3;
    cpu->esp -= 0xCu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x42F7E6u)); sfera_sub_0042F730(cpu, LIFT_CODE_TOKEN_VA(0x42F7E6u));
    x87_v0 = (double)*(float*)(cpu->esp + 4u);
    { const double lift_left=(double)*(float*)(cpu->esi + 0x50u); const double lift_right=x87_v0; if (lift_left>lift_right) goto label_0002F863; }
    { const double lift_left=(double)*(float*)(cpu->esi + 0x54u); const double lift_right=x87_v0; if (lift_left<lift_right) goto label_0002F863; }
    x87_v1 = (double)*(float*)(cpu->esi + 0x64u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    x87_v2 = (double)*(float*)(cpu->esp + 8u);
    x87_v3 = x87_v0;
    x87_v3 = (x87_v3) * (((double)*(float*)(cpu->esi + 0x98u)));
    x87_v3 = (x87_v3) * (((double)*(float*)(cpu->esi + 0x5Cu)));
    x87_v2 = x87_v2 / x87_v3; 
    x87_v1 = x87_v1 - x87_v2; 
    *(float*)(cpu->eax) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esi + 0x68u);
    x87_v2 = (double)*(float*)(cpu->esp + 0xCu);
    x87_v3 = x87_v0;
    x87_v3 = (x87_v3) * (((double)*(float*)(cpu->esi + 0x98u)));
    x87_v3 = (x87_v3) * (((double)*(float*)(cpu->esi + 0x60u)));
    x87_v2 = x87_v2 / x87_v3; 
    x87_v1 = x87_v1 - x87_v2; 
    *(float*)(cpu->eax + 4u) = x87_v1; 
    x87_v1 = x87_v0;
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->esi + 0x50u)));
    x87_v1 = (x87_v1) * (((double)*(float*)(cpu->esi + 0x54u)));
    x87_v2 = (double)*(float*)(cpu->esi + 0x54u);
    x87_v2 = (x87_v2) - (((double)*(float*)(cpu->esi + 0x50u)));
    x87_v0 = x87_v0 * x87_v2; 
    x87_v0 = x87_v1 / x87_v0; 
    x87_v1 = (double)*(float*)(cpu->esi + 0x70u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->esi + 0x6Cu)));
    x87_v0 = x87_v0 * x87_v1; 
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esi + 0x6Cu)));
    cpu->esi = lift_pop32(cpu);
    *(float*)(cpu->eax + 8u) = x87_v0; 
    cpu->eax = 1u;
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0002F863:
    x87_v0 = x87_v0; 
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}

} // namespace lifted
