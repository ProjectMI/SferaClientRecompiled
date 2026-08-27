#include "lifted_functions.h"
#include <cmath>
namespace lifted {

static uint32_t sfera_texture_time_key_digit(uint32_t index) { const char* key = "05185514038799035566164306887187530785282430311941"; return index < 50u ? (uint32_t)(key[index] - '0') : 0u; }
static float sfera_zoning_lower_bound(uint32_t band) { switch (band) { case 0u: return 0.0f; case 1u: return 0.19f; case 2u: return 0.27f; case 3u: return 0.34f; case 4u: return 0.50f; case 5u: return 0.66f; case 6u: return 0.73f; default: return 0.81f; } }
static float sfera_zoning_upper_bound(uint32_t band) { return band == 7u ? 1.0f : sfera_zoning_lower_bound(band + 1u); }
__declspec(noinline) void sfera_sub_00494A10(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x44u;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x54u);
    cpu->ebp = cpu->ecx;
    cpu->ecx = cpu->esp + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494A55u)); sfera_sub_00480380(cpu, LIFT_CODE_TOKEN_VA(0x494A55u));
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x20u;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x94A65u)); sfera_sub_004803B0(cpu, LIFT_CODE_TOKEN_RVA(0x94A65u));
    label_00094A65:
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    if ((int32_t)cpu->ebx >= (int32_t)0xBu) goto label_00094ACA;
    if ((int32_t)cpu->ebx >= (int32_t)0xAu) goto label_00094A7C;
    cpu->eax = cpu->ebx + 0x30u;
    *(uint8_t*)(cpu->esp + 0x1Bu) = cpu->eax & 0xFFu;
    goto label_00094A83;
    label_00094A7C:
    cpu->eax = cpu->ebx + 0x57u;
    *(uint8_t*)(cpu->esp + 0x1Bu) = cpu->eax & 0xFFu;
    label_00094A83:
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x3063)) & 0xFFFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint16_t*)(cpu->esp + 0x2Cu) = cpu->ecx & 0xFFFFu;
    lift_push32(cpu, 2u);
    *(uint8_t*)(cpu->esp + 0x31u) = cpu->eax & 0xFFu;
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"r");
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x2Cu;
    *(uint8_t*)(cpu->esp + 0x3Eu) = cpu->edx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494AB7u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x494AB7u));
    if (cpu->eax == 0u) goto label_0009500A;
    if (cpu->eax != 2u) goto label_00094B52;
    goto label_00094B44;
    label_00094ACA:
    lift_push32(cpu, 2u);
    cpu->edx = cpu->ebp + 0x1028u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"n"); lift_push32(cpu, (uintptr_t)"SunsetStateN");
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494AE6u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x494AE6u));
    if (cpu->eax != 1u) goto label_00094B44;
    lift_push32(cpu, 2u);
    cpu->eax = cpu->ebp + 0x102Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"n"); lift_push32(cpu, (uintptr_t)"SunriseStateN");
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494B07u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x494B07u));
    if (cpu->eax != 1u) goto label_00094B44;
    cpu->ecx = cpu->esp + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x4Cu) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494B1Du)); sfera_sub_00480390(cpu, LIFT_CODE_TOKEN_VA(0x494B1Du));
    cpu->eax = cpu->ebp;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x3Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00094B40:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x28u);
    label_00094B44:
    cpu->edx = cpu->esp + 0x2Cu;
    cpu->ecx = (uintptr_t)"Illegal format of Sky.txt, line: ";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x94B52u)); sfera_sub_00459CB0(cpu, LIFT_CODE_TOKEN_RVA(0x94B52u));
    label_00094B52:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x1Bu));
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0x303061u;
    cpu->ebx = 0u;
    *(uint8_t*)(cpu->esp + 0x2Du) = cpu->ecx & 0xFFu;
    cpu->edi = 0u;
    label_00094B66:
    lift_push32(cpu, 2u);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"r");
    cpu->ecx = cpu->esp + 0x38u;
    cpu->edx = cpu->ebx + 0x30u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x2Cu;
    *(uint8_t*)(cpu->esp + 0x3Eu) = cpu->edx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494B87u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x494B87u));
    if (cpu->eax != 1u) goto label_00094B44;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x24u);
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x178u);
    lift_push32(cpu, 2u);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"g");
    cpu->ecx = cpu->esp + 0x38u;
    cpu->esi += cpu->edi;
    lift_push32(cpu, cpu->ecx);
    cpu->esi += cpu->ebp;
    cpu->ecx = cpu->esp + 0x2Cu;
    *(float*)(cpu->esi) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494BBAu)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x494BBAu));
    if (cpu->eax != 1u) goto label_00094B44;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    lift_push32(cpu, 2u);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"b");
    *(float*)(cpu->esi + 4u) = x87_v0; 
    cpu->eax = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494BE0u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x494BE0u));
    if (cpu->eax != 1u) goto label_00094B44;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    lift_push32(cpu, 2u);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"a");
    *(float*)(cpu->esi + 8u) = x87_v0; 
    cpu->edx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494C0Au)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x494C0Au));
    if (cpu->eax != 1u) goto label_00094B44;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"p");
    *(float*)(cpu->esi + 0xCu) = x87_v0; 
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494C34u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x494C34u));
    if (cpu->eax != 1u) goto label_00094B44;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x5Eu);
    cpu->edx += cpu->ebx;
    cpu->edi += 0x10u;
    ++cpu->ebx;
    *(float*)(cpu->ebp + (cpu->edx * 4u) + 0xA0u) = x87_v0; 
    if ((int32_t)cpu->edi < (int32_t)0xA0u) goto label_00094B66;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x1Bu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0x303062u;
    *(uint8_t*)(cpu->esp + 0x2Du) = cpu->eax & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ebp = cpu->eax;
    cpu->ebx = 0u;
    cpu->ebp = (int64_t)(int32_t)(cpu->ebp) * (int64_t)(int32_t)(0x5Eu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x178u);
    cpu->edi = cpu->eax + cpu->ecx;
    cpu->esi = cpu->edi + 0xDCu;
    (void)cpu;
    label_00094C90:
    lift_push32(cpu, 2u);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"r");
    cpu->ecx = cpu->esp + 0x38u;
    cpu->edx = cpu->ebx + 0x30u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x2Cu;
    *(uint8_t*)(cpu->esp + 0x3Eu) = cpu->edx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494CB1u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x494CB1u));
    if (cpu->eax != 1u) goto label_00094B40;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    lift_push32(cpu, 2u);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"g");
    *(float*)(cpu->esi + 0xFFFFFFFCu) = x87_v0; 
    cpu->eax = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494CDBu)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x494CDBu));
    if (cpu->eax != 1u) goto label_00094B40;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    lift_push32(cpu, 2u);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"b");
    *(float*)(cpu->esi) = x87_v0; 
    cpu->edx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494D04u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x494D04u));
    if (cpu->eax != 1u) goto label_00094B40;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    lift_push32(cpu, 2u);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"a");
    *(float*)(cpu->esi + 4u) = x87_v0; 
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494D2Eu)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x494D2Eu));
    if (cpu->eax != 1u) goto label_00094B40;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"p");
    *(float*)(cpu->esi + 8u) = x87_v0; 
    cpu->eax = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494D58u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x494D58u));
    if (cpu->eax != 1u) goto label_00094B40;
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx = cpu->ebx + cpu->ebp;
    ++cpu->ebx;
    *(float*)(cpu->edx + (cpu->ecx * 4u) + 0x138u) = x87_v0; 
    cpu->esi += 0x10u;
    if ((int32_t)cpu->ebx < (int32_t)6u) goto label_00094C90;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x3063)) & 0xFFFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x1Bu));
    *(uint16_t*)(cpu->esp + 0x2Cu) = cpu->eax & 0xFFFFu;
    lift_push32(cpu, 2u);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->esp + 0x36u) = cpu->ecx & 0xFFu;
    lift_push32(cpu, (uintptr_t)"r");
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x2Cu;
    *(uint8_t*)(cpu->esp + 0x3Du) = cpu->edx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494DB7u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x494DB7u));
    if (cpu->eax != 1u) goto label_00094B40;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    lift_push32(cpu, 2u);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"g");
    *(float*)(cpu->edi + 0xC8u) = x87_v0; 
    cpu->eax = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494DE4u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x494DE4u));
    if (cpu->eax != 1u) goto label_00094B40;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    lift_push32(cpu, 2u);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"b");
    *(float*)(cpu->edi + 0xCCu) = x87_v0; 
    cpu->edx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494E11u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x494E11u));
    if (cpu->eax != 1u) goto label_00094B40;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    lift_push32(cpu, 2u);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"a");
    *(float*)(cpu->edi + 0xD0u) = x87_v0; 
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494E3Eu)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x494E3Eu));
    if (cpu->eax != 1u) goto label_00094B40;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x1Bu));
    lift_push32(cpu, 0u);
    *(float*)(cpu->edi + 0xD4u) = x87_v0; 
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)((uintptr_t)"d0"));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"d0") + 2u));
    *(uint16_t*)(cpu->esp + 0x30u) = cpu->edx & 0xFFFFu;
    cpu->edx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->edx);
    *(uint8_t*)(cpu->esp + 0x36u) = cpu->eax & 0xFFu;
    lift_push32(cpu, (uintptr_t)"time");
    cpu->eax = cpu->esp + 0x38u;
    *(uint8_t*)(cpu->esp + 0x39u) = cpu->ecx & 0xFFu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494E88u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x494E88u));
    if (cpu->eax != 1u) goto label_00094B40;
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x24u;
    *(float*)(cpu->edi + 0x150u) = x87_v0; 
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"sun");
    cpu->edx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494EB5u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x494EB5u));
    if (cpu->eax != 1u) goto label_00094B40;
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    lift_push32(cpu, 2u);
    cpu->eax = cpu->esp + 0x18u;
    *(float*)(cpu->edi + 0x154u) = x87_v0; 
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"sr");
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494EE2u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x494EE2u));
    if (cpu->eax != 1u) goto label_00094B40;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    lift_push32(cpu, 2u);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"sg");
    *(float*)(cpu->edi + 0x158u) = x87_v0; 
    cpu->eax = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494F0Fu)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x494F0Fu));
    if (cpu->eax != 1u) goto label_00094B40;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    lift_push32(cpu, 2u);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"sb");
    *(float*)(cpu->edi + 0x15Cu) = x87_v0; 
    cpu->edx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494F3Cu)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x494F3Cu));
    if (cpu->eax != 1u) goto label_00094B40;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    lift_push32(cpu, 2u);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"ar");
    *(float*)(cpu->edi + 0x160u) = x87_v0; 
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494F69u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x494F69u));
    if (cpu->eax != 1u) goto label_00094B40;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    lift_push32(cpu, 2u);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"ag");
    *(float*)(cpu->edi + 0x168u) = x87_v0; 
    cpu->eax = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494F96u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x494F96u));
    if (cpu->eax != 1u) goto label_00094B40;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    lift_push32(cpu, 2u);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"ab");
    *(float*)(cpu->edi + 0x16Cu) = x87_v0; 
    cpu->edx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494FC3u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x494FC3u));
    if (cpu->eax != 1u) goto label_00094B40;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x178u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x28u);
    *(float*)(cpu->eax + cpu->ecx + 0x170u) = x87_v0; 
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)((uintptr_t)"e0"));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"e0") + 2u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x1Bu));
    *(uint16_t*)(cpu->esp + 0x2Cu) = cpu->edx & 0xFFFFu;
    *(uint8_t*)(cpu->esp + 0x2Eu) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x2Du) = cpu->ecx & 0xFFu;
    label_0009500A:
    ++cpu->ebx;
    goto label_00094A65;
}
__declspec(noinline) void sfera_sub_00495010(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    x87_v0 = (double)*(float*)(cpu->esp + 4u); x87_v1 = x87_v0;
    *(uint32_t*)(cpu->edx) = 1u;
    { const double lift_left=(double)*(float*)(cpu->ecx + 0x2C8u); const double lift_right=x87_v1; if (!(lift_left<lift_right)) goto label_00095049; }
    label_0009502F:
    ++*(uint32_t*)(cpu->edx);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x178u);
    { const double lift_left=(double)*(float*)(cpu->eax + cpu->ecx + 0x150u); const double lift_right=x87_v1; if (lift_left<lift_right) goto label_0009502F; }
    label_00095049:
    cpu->eax = *(uint32_t*)(cpu->edx);
    x87_v1 = x87_v1; 
    --cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x178u);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->eax + cpu->ecx + 0x150u)));
    cpu->edx = *(uint32_t*)(cpu->edx);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x178u);
    cpu->eax = cpu->eax + cpu->ecx + 0x150u;
    cpu->esi = lift_pop32(cpu);
    x87_v1 = (double)*(float*)(cpu->edx + cpu->ecx + 0x150u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax)));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    x87_v0 = x87_v0 / x87_v1; 
    *(float*)(cpu->eax) = x87_v0; 
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00495090(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[3]; double x87_v0, x87_v1;
    cpu->esp -= 0x10u;
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4950B3u)); sfera_sub_00495010(cpu, LIFT_CODE_TOKEN_VA(0x4950B3u));
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x28u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->ebx + 0xA0u;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x178u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x178u);
    cpu->edx += cpu->ecx;
    cpu->edi += cpu->ecx;
    cpu->eax = cpu->edx + 0xA0u;
    cpu->ecx = cpu->edi + 0xA0u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ecx;
    cpu->esi = cpu->ebx + 8u;
    cpu->eax = cpu->edx + 8u;
    cpu->ecx = cpu->edi + 8u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0xAu;
    label_00095102:
    x87_v1 = (double)*(float*)(cpu->ecx + 0xFFFFFFF8u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax + 0xFFFFFFF8u)));
    *(uint32_t*)(cpu->esp + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x24u)) + (uint64_t)(4u) + (uint64_t)(0u);
    cpu->ecx += 0x10u;
    cpu->eax += 0x10u;
    x87_v1 = (x87_v1) * (x87_v0);
    cpu->esi += 0x10u;
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->eax + 0xFFFFFFE8u)));
    *(float*)(cpu->esi + 0xFFFFFFE8u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->ecx + 0xFFFFFFECu);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax + 0xFFFFFFECu)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->eax + 0xFFFFFFECu)));
    *(float*)(cpu->esi + 0xFFFFFFECu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->ecx + 0xFFFFFFF0u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax + 0xFFFFFFF0u)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->eax + 0xFFFFFFF0u)));
    *(float*)(cpu->esi + 0xFFFFFFF0u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->ecx + 0xFFFFFFF4u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax + 0xFFFFFFF4u)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->eax + 0xFFFFFFF4u)));
    *(float*)(cpu->esi + 0xFFFFFFF4u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x28u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->ebp)));
    *(uint32_t*)(cpu->esp + 0x28u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x28u)) + (uint64_t)(4u) + (uint64_t)(0u);
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->ebp)));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(4u) + (uint64_t)(0u);
    --*(uint32_t*)(cpu->esp + 0x14u); sub_pred[0] = *(uint32_t*)(cpu->esp + 0x14u) == 0u;
    *(float*)(cpu->ebp) = x87_v1; 
    if (!sub_pred[0]) goto label_00095102;
    x87_v1 = (double)*(float*)(cpu->edi + 0xC8u);
    cpu->eax = cpu->ebx + 0x138u;
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->edx + 0xC8u)));
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->ecx = cpu->edx + 0x138u;
    cpu->eax = cpu->edi + 0x138u;
    x87_v1 = (x87_v1) * (x87_v0);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    cpu->esi = cpu->ebx + 0xDCu;
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->edx + 0xC8u)));
    cpu->eax = cpu->edx + 0xDCu;
    cpu->ecx = cpu->edi + 0xDCu;
    *(uint32_t*)(cpu->esp + 0x14u) = 6u;
    *(float*)(cpu->ebx + 0xC8u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edi + 0xCCu);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->edx + 0xCCu)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->edx + 0xCCu)));
    *(float*)(cpu->ebx + 0xCCu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edi + 0xD0u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->edx + 0xD0u)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->edx + 0xD0u)));
    *(float*)(cpu->ebx + 0xD0u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edi + 0xD4u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->edx + 0xD4u)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->edx + 0xD4u)));
    *(float*)(cpu->ebx + 0xD4u) = x87_v1; 
    label_00095212:
    x87_v1 = (double)*(float*)(cpu->ecx + 0xFFFFFFFCu);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x24u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax + 0xFFFFFFFCu)));
    *(uint32_t*)(cpu->esp + 0x24u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x24u)) + (uint64_t)(4u) + (uint64_t)(0u);
    cpu->ecx += 0x10u;
    cpu->eax += 0x10u;
    x87_v1 = (x87_v1) * (x87_v0);
    cpu->esi += 0x10u;
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->eax + 0xFFFFFFECu)));
    *(float*)(cpu->esi + 0xFFFFFFECu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->ecx + 0xFFFFFFF0u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax + 0xFFFFFFF0u)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->eax + 0xFFFFFFF0u)));
    *(float*)(cpu->esi + 0xFFFFFFF0u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->ecx + 0xFFFFFFF4u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax + 0xFFFFFFF4u)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->eax + 0xFFFFFFF4u)));
    *(float*)(cpu->esi + 0xFFFFFFF4u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->ecx + 0xFFFFFFF8u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax + 0xFFFFFFF8u)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->eax + 0xFFFFFFF8u)));
    *(float*)(cpu->esi + 0xFFFFFFF8u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x28u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->ebp)));
    *(uint32_t*)(cpu->esp + 0x28u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x28u)) + (uint64_t)(4u) + (uint64_t)(0u);
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->ebp)));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(4u) + (uint64_t)(0u);
    --*(uint32_t*)(cpu->esp + 0x14u); sub_pred[1] = *(uint32_t*)(cpu->esp + 0x14u) == 0u;
    *(float*)(cpu->ebp) = x87_v1; 
    if (!sub_pred[1]) goto label_00095212;
    sub_pred[2] = (int32_t)(*(uint32_t*)(cpu->esp + 0x18u)) < (int32_t)(0xBu);
    x87_v1 = (double)*(float*)(cpu->edi + 0x154u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->edx + 0x154u)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->edx + 0x154u)));
    *(float*)(cpu->ebx + 0x154u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edi + 0x158u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->edx + 0x158u)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->edx + 0x158u)));
    *(float*)(cpu->ebx + 0x158u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edi + 0x15Cu);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->edx + 0x15Cu)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->edx + 0x15Cu)));
    *(float*)(cpu->ebx + 0x15Cu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edi + 0x160u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->edx + 0x160u)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->edx + 0x160u)));
    *(float*)(cpu->ebx + 0x160u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edi + 0x168u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->edx + 0x168u)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->edx + 0x168u)));
    *(float*)(cpu->ebx + 0x168u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edi + 0x16Cu);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->edx + 0x16Cu)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->edx + 0x16Cu)));
    *(float*)(cpu->ebx + 0x16Cu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edi + 0x170u);
    cpu->edi = lift_pop32(cpu);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->edx + 0x170u)));
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    x87_v0 = x87_v0 * x87_v1; 
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->edx + 0x170u)));
    *(float*)(cpu->ebx + 0x170u) = x87_v0; 
    cpu->ebx = lift_pop32(cpu);
    if (sub_pred[2]) goto label_0009534D;
    cpu->ecx = (uintptr_t)"n2 >= SKY_STATES_NUM";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9534Du)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x9534Du));
    label_0009534D:
    cpu->esp += 0x10u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00495360(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4;
    bool lift_cmp[2];
    cpu->esp -= 0x10u;
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->eax = cpu->esp + 4u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49537Fu)); sfera_sub_00495010(cpu, LIFT_CODE_TOKEN_VA(0x49537Fu));
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x102Cu);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x1028u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x178u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x178u);
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->edx + cpu->ecx + 0x154u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x178u);
    *(float*)(cpu->esp + 0xCu) = (double)*(float*)(cpu->eax + cpu->ecx + 0x154u);
    cpu->eax = cpu->edx + cpu->ecx + 0x154u;
    cpu->edx = *(uint32_t*)(cpu->esp);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x178u);
    *(float*)(cpu->esp + 0x14u) = ((((((((((double)*(float*)(cpu->edx + cpu->ecx + 0x154u))) - (((double)*(float*)(cpu->eax)))))) * (((double)*(float*)(cpu->esp + 4u)))))) + (((double)*(float*)(cpu->eax))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v1 = (double)*(float*)(cpu->esp + 8u);
    lift_cmp[0]=x87_v1<x87_v0;
    x87_v2 = (double)*(float*)(cpu->esp + 0xCu);
    if (!lift_cmp[0]) goto label_000953FE;
    { const double lift_left=x87_v2; const double lift_right=x87_v0; if (!(lift_left>lift_right)) goto label_000953FE; }
    x87_v2 = x87_v2; 
    x87_v1 = x87_v1; 
    goto label_00095437;
    label_000953FE:
    x87_v3 = x87_v2;
    x87_v0 = x87_v0 - x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 0x14u) = x87_v2; 
    x87_v2 = 0.0;
    x87_v3 = (double)*(float*)(cpu->esp + 0x14u);
    lift_cmp[1]=x87_v3<x87_v2;
    x87_v2 = x87_v3; 
    x87_v3 = 1.0;
    if (!lift_cmp[1]) goto label_00095429;
    x87_v2 = (x87_v2) + (x87_v3);
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esp + 0x14u) = x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x14u);
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    label_00095429:
    x87_v4 = x87_v0;
    x87_v4 = (x87_v4) - (x87_v1);
    x87_v2 = x87_v2 * x87_v4; 
    x87_v3 = (x87_v3) + (x87_v1);
    x87_v0 = x87_v3 - x87_v0; 
    x87_v0 = x87_v2 / x87_v0; 
    x87_v0 = x87_v0 + x87_v1; 
    label_00095437:
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    lift_push32(cpu, cpu->esi);
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    x87_v0 = (x87_v0) * (3.1415929794311523);
    x87_v0 = (x87_v0) + (x87_v0);
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x10u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    x87_v0 = -x87_v0;
    *(float*)(cpu->esi) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    *(float*)(cpu->esi + 4u) = (double)*(float*)(cpu->esp + 0x18u);
    *(float*)(cpu->esi + 8u) = (double)(0.0);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00495490(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    cpu->esp -= 8u;
    x87_v0 = (double)*(float*)(cpu->esp + 0xCu);
    cpu->eax = cpu->esp + 4u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4954AFu)); sfera_sub_00495010(cpu, LIFT_CODE_TOKEN_VA(0x4954AFu));
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->esp);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x178u);
    x87_v0 = (double)*(float*)(cpu->edx + cpu->ecx + 0x158u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x178u);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->eax + cpu->ecx + 0x158u)));
    x87_v1 = (double)*(float*)(cpu->esp + 4u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v2 = (double)*(float*)(cpu->eax + cpu->ecx + 0x158u);
    x87_v0 = x87_v0 + x87_v2; 
    cpu->edx += cpu->ecx;
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->ecx) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edx + 0x15Cu);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax + 0x15Cu)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->eax + 0x15Cu)));
    *(float*)(cpu->ecx + 4u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edx + 0x160u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax + 0x160u)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->eax + 0x160u)));
    *(float*)(cpu->ecx + 8u) = x87_v1; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v1 = (double)*(float*)(cpu->edx + 0x168u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax + 0x168u)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->eax + 0x168u)));
    *(float*)(cpu->ecx) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edx + 0x16Cu);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax + 0x16Cu)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->eax + 0x16Cu)));
    *(float*)(cpu->ecx + 4u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edx + 0x170u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax + 0x170u)));
    x87_v0 = x87_v0 * x87_v1; 
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->eax + 0x170u)));
    *(float*)(cpu->ecx + 8u) = x87_v0; 
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00495570(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1;
 double x87_v0; double x87_p0, x87_p1;
    cpu->esp -= 0x40u;
    x87_v0 = 0.0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    *(float*)(cpu->ebp + 0x10A9A8u) = x87_v0; 
    cpu->edi = native_function_address32(&::rand);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    cpu->esi = cpu->ebp + 8u;
    cpu->ebx = 0x1B58u;
label_000955A6:
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(float*)(cpu->esi + 0xFFFFFFF8u) = ((((((((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))))) * (10.0)))) / (32767.0)))) - (5.0));
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(float*)(cpu->esi + 0xFFFFFFFCu) = ((((((((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))))) * (10.0)))) / (32767.0)))) - (5.0));
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(float*)(cpu->esi) = ((((((((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))))) * (10.0)))) / (32767.0)))) - (5.0));
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    cpu->ecx = cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x1B58u);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x80010003u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx += cpu->ecx;
    cpu->edx = (int32_t)(cpu->edx) >> 14u;
    cpu->ecx = cpu->edx;
    cpu->ecx >>= 31u;
    cpu->ecx += cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    cpu->esi += 0x10u;
    if ((--cpu->ebx) != 0u) goto label_000955A6;
    x87_p0 = 0.0;
    cpu->ecx |= 0xFFFFFFFFu;
    *(float*)(cpu->esp + 0x2Cu) = x87_p0;
    cpu->eax = cpu->ebp + 0x1B58Cu;
    x87_p1 = 1.0;
    cpu->esi = 0u;
    *(float*)(cpu->esp + 0x30u) = x87_p1;
    *(float*)(cpu->esp + 0x34u) = x87_p1;
    *(float*)(cpu->esp + 0x44u) = x87_p1;
    *(float*)(cpu->esp + 0x48u) = x87_p1;
    std::swap(x87_p1, x87_p0);
    *(float*)(cpu->esp + 0x38u) = x87_p1;
    *(float*)(cpu->esp + 0x3Cu) = x87_p1;
    *(float*)(cpu->esp + 0x40u) = x87_p1;
     value_0 = x87_p1; value_1 = x87_p0; goto label_00095661;
label_0009565F:
label_00095661:
    *(float*)(cpu->eax + 0xFFFFFFFCu) = value_0;
    cpu->edx = cpu->ecx + 1u;
    cpu->edx &= 3u;
    *(float*)(cpu->eax) = value_1;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    x87_p0 = (double)*(float*)(cpu->esp + cpu->edx + 0x2Cu);
    cpu->edi = cpu->esp + cpu->edx + 0x2Cu;
    *(float*)(cpu->eax + 0xCu) = x87_p0; 
    cpu->ebx = cpu->esp + cpu->edx + 0x3Cu;
    x87_p0 = (double)*(float*)(cpu->ebx);
    cpu->edx = cpu->ecx + 0xFFFFFFFEu;
    *(float*)(cpu->eax + 0x10u) = x87_p0; 
    cpu->edx &= 3u;
    cpu->edx += cpu->edx;
    *(float*)(cpu->eax + 0x1Cu) = value_0;
    cpu->edx += cpu->edx;
    cpu->ebp = cpu->esp + cpu->edx + 0x2Cu;
    *(float*)(cpu->eax + 0x20u) = value_1;
    cpu->edx = cpu->esp + cpu->edx + 0x3Cu;
    x87_p0 = (double)*(float*)(cpu->ebp);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    *(float*)(cpu->eax + 0x2Cu) = x87_p0; 
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    x87_p0 = (double)*(float*)(cpu->edx);
    cpu->edx = cpu->ecx + 0xFFFFFFFFu;
    *(float*)(cpu->eax + 0x30u) = x87_p0; 
    cpu->edx &= 3u;
    cpu->edx += cpu->edx;
    *(float*)(cpu->eax + 0x3Cu) = value_0;
    cpu->edx += cpu->edx;
    cpu->ebp = cpu->esp + cpu->edx + 0x2Cu;
    *(float*)(cpu->eax + 0x40u) = value_1;
    cpu->edx = cpu->esp + cpu->edx + 0x3Cu;
    x87_p0 = (double)*(float*)(cpu->ebp);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edx;
    *(float*)(cpu->eax + 0x4Cu) = x87_p0; 
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebp;
    x87_p0 = (double)*(float*)(cpu->edx);
    cpu->edx = cpu->ecx;
    *(float*)(cpu->eax + 0x50u) = x87_p0; 
    cpu->edx &= 3u;
    cpu->edx += cpu->edx;
    *(float*)(cpu->eax + 0x5Cu) = value_0;
    cpu->edx += cpu->edx;
    cpu->ebp = cpu->esp + cpu->edx + 0x2Cu;
    *(float*)(cpu->eax + 0x60u) = value_1;
    cpu->edx = cpu->esp + cpu->edx + 0x3Cu;
    x87_p0 = (double)*(float*)(cpu->ebp);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    *(float*)(cpu->eax + 0x6Cu) = x87_p0; 
    *(uint32_t*)(cpu->eax + 8u) = cpu->esi;
    x87_p0 = (double)*(float*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)(cpu->eax + 0x70u) = x87_p0; 
    *(uint32_t*)(cpu->eax + 0x28u) = cpu->esi;
    *(uint32_t*)(cpu->eax + 0x48u) = cpu->esi;
    *(float*)(cpu->eax + 0x7Cu) = value_0;
    *(uint32_t*)(cpu->eax + 0x68u) = cpu->esi;
    *(uint32_t*)(cpu->eax + 0x88u) = cpu->esi;
    *(float*)(cpu->eax + 0x80u) = value_1;
    *(uint32_t*)(cpu->eax + 0xA8u) = cpu->esi;
    *(float*)(cpu->eax + 0x8Cu) = (double)*(float*)(cpu->edi);
    *(float*)(cpu->eax + 0x90u) = (double)*(float*)(cpu->ebx);
    *(float*)(cpu->eax + 0x9Cu) = value_0;
    *(float*)(cpu->eax + 0xA0u) = value_1;
    *(float*)(cpu->eax + 0xACu) = (double)*(float*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    x87_p0 = (double)*(float*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(float*)(cpu->eax + 0xB0u) = x87_p0; 
    cpu->ecx += 0xAu;
    *(uint32_t*)(cpu->eax + 0xC8u) = cpu->esi;
    *(float*)(cpu->eax + 0xBCu) = value_0;
    *(uint32_t*)(cpu->eax + 0xE8u) = cpu->esi;
    *(uint32_t*)(cpu->eax + 0x108u) = cpu->esi;
    *(float*)(cpu->eax + 0xC0u) = value_1;
    *(uint32_t*)(cpu->eax + 0x128u) = cpu->esi;
    x87_p0 = (double)*(float*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    *(float*)(cpu->eax + 0xCCu) = x87_p0; 
    cpu->eax += 0x140u;
    x87_p0 = (double)*(float*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(float*)(cpu->eax + 0xFFFFFF90u) = x87_p0; 
    *(float*)(cpu->eax + 0xFFFFFF9Cu) = value_0;
    *(float*)(cpu->eax + 0xFFFFFFA0u) = value_1;
    *(float*)(cpu->eax + 0xFFFFFFACu) = (double)*(float*)(cpu->ebp);
    x87_p0 = (double)*(float*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)(cpu->eax + 0xFFFFFFB0u) = x87_p0; 
    *(float*)(cpu->eax + 0xFFFFFFBCu) = value_0;
    *(float*)(cpu->eax + 0xFFFFFFC0u) = value_1;
    *(float*)(cpu->eax + 0xFFFFFFCCu) = (double)*(float*)(cpu->edi);
    *(float*)(cpu->eax + 0xFFFFFFD0u) = (double)*(float*)(cpu->ebx);
    *(float*)(cpu->eax + 0xFFFFFFDCu) = value_0;
    *(float*)(cpu->eax + 0xFFFFFFE0u) = value_1;
    x87_p0 = (double)*(float*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->eax + 0xFFFFFFECu) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->edx);
    cpu->edx = cpu->ecx + 1u;
    *(float*)(cpu->eax + 0xFFFFFFF0u) = x87_p0; 
    if ((int32_t)cpu->edx < (int32_t)0x6D60u) goto label_0009565F;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = cpu->ebx + 0xF6182u;
    cpu->edi = 0x1B58u;
label_00095820:
    cpu->ecx = cpu->esi & 0xFFFFu;
    cpu->edx = cpu->ecx + 1u;
    *(uint16_t*)(cpu->eax) = cpu->edx & 0xFFFFu;
    cpu->edx = cpu->ecx + 2u;
    *(uint16_t*)(cpu->eax + 0xFFFFFFFEu) = cpu->ecx & 0xFFFFu;
    *(uint16_t*)(cpu->eax + 4u) = cpu->ecx & 0xFFFFu;
    cpu->ecx += 3u;
    *(uint16_t*)(cpu->eax + 2u) = cpu->edx & 0xFFFFu;
    *(uint16_t*)(cpu->eax + 6u) = cpu->edx & 0xFFFFu;
    *(uint16_t*)(cpu->eax + 8u) = cpu->ecx & 0xFFFFu;
    cpu->esi += 4u;
    cpu->eax += 0xCu;
    if ((--cpu->edi) != 0u) goto label_00095820;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x495857u)); sfera_sub_0042F2A0(cpu, LIFT_CODE_TOKEN_VA(0x495857u));
    cpu->eax >>= 3u;
    lift_push32(cpu, 0x59u);
    cpu->ecx = cpu->eax * 8u;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\snow.cpp";
    *(uint32_t*)(cpu->ebx + 0x10A9A4u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x495873u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x495873u));
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->ebx + 0x10A9A0u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x495882u)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x495882u));
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x10A9A0u);
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x10A9A4u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49589Eu)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x49589Eu));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4958A5u)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x4958A5u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x40u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004958C0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_method_address32(&CSound::SetPlayTimepos), LIFT_CODE_TOKEN_VA(0x4958CBu));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    cpu->eax = static_cast<uint32_t>(reinterpret_cast<CSound*>(static_cast<uintptr_t>(cpu->ecx))->CSound::Play(static_cast<int>(*(uint32_t*)(cpu->esp)))); cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_000958FB;
    cpu->eax |= 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x60u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x64u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x6Cu) = 0u;
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000958FB:
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00495910(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->esi != 0u) goto label_0009591B;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0009591B:
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_stricmp);

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"SF_PLAY_RANDOM");

    if (cpu->eax != 0u) goto label_00095939;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 4u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00095939:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"SF_PLAY_RANDOMMIX");

    if (cpu->eax != 0u) goto label_00095950;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 8u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00095950:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"SF_PLAY_LOOPED");

    if (cpu->eax != 0u) goto label_00095967;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0x10u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00095967:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"SF_TYPE_ENVIRONMENT");

    if (cpu->eax != 0u) goto label_0009597E;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0009597E:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"SF_PLAY_USEREGION");

    if (cpu->eax != 0u) goto label_00095995;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0x20u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00095995:

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->esi, (uintptr_t)"SF_PLAY_TIMEGROUPS");

    cpu->eax = -cpu->eax;
    cpu->eax = (cpu->eax != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->eax &= 0xFFFFFFC0u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax += 0x40u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004959B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    if ((int32_t)cpu->edi <= 0) goto label_000959ED;
    cpu->edx = 0xFFu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4959CBu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4959CBu));
    cpu->eax = cpu->edi;
    cpu->edx = 4u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4959E3u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4959E3u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    goto label_000959FA;
    label_000959ED:
    *(uint32_t*)(cpu->esi) = 0u;
    *(uint32_t*)(cpu->esi + 4u) = 0u;
    label_000959FA:
    cpu->eax = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->eax) goto label_00095A10;
    label_00095A01:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->ecx + (cpu->eax * 4u)) = 0u;
    ++cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00095A01;
    label_00095A10:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 8u) = 0u;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->edx;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00495A30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ebp = cpu->ecx;
    if (cpu->esi == cpu->eax) goto label_00095ABB;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    label_00095A42:
    cpu->edx = *(uint32_t*)(cpu->ebp);
    cpu->ecx = cpu->esi + cpu->eax;
    cpu->ecx = (int32_t)(cpu->ecx) >> 1u;
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u));
    cpu->edi = *(uint32_t*)(cpu->ecx);
    (void)cpu;
    label_00095A50:
    cpu->ebx = *(uint32_t*)(cpu->ebp);
    cpu->ecx = cpu->ebx + (cpu->esi * 4u);
    label_00095A56:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    ++cpu->esi;
    cpu->ecx += 4u;
    if (*(uint32_t*)(cpu->edx) >= cpu->edi) goto label_00095A65;
    if ((int32_t)cpu->esi <= (int32_t)*(uint32_t*)(cpu->ebp + 8u)) goto label_00095A56;
    label_00095A65:
    --cpu->esi;
    cpu->ecx = cpu->ebx + (cpu->eax * 4u);
    label_00095A70:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    --cpu->eax;
    cpu->ecx -= 4u;
    if (*(uint32_t*)(cpu->edx) <= cpu->edi) goto label_00095A7E;
    if ((int32_t)cpu->eax >= 0) goto label_00095A70;
    label_00095A7E:
    ++cpu->eax;
    if ((int32_t)cpu->esi > (int32_t)cpu->eax) goto label_00095A98;
    cpu->edx = *(uint32_t*)(cpu->ebx + (cpu->eax * 4u));
    cpu->ecx = *(uint32_t*)(cpu->ebx + (cpu->esi * 4u));
    *(uint32_t*)(cpu->ebx + (cpu->esi * 4u)) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp);
    *(uint32_t*)(cpu->edx + (cpu->eax * 4u)) = cpu->ecx;
    ++cpu->esi;
    --cpu->eax;
    if ((int32_t)cpu->esi <= (int32_t)cpu->eax) goto label_00095A50;
    label_00095A98:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    if ((int32_t)cpu->ecx >= (int32_t)cpu->eax) goto label_00095AA9;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x95AA9u)); sfera_sub_00495A30(cpu, LIFT_CODE_TOKEN_RVA(0x95AA9u));
    label_00095AA9:
    if ((int32_t)(cpu->esi) >= (int32_t)(*(uint32_t*)(cpu->esp + 0x18u))) goto label_00095AB9;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    goto label_00095A42;
    label_00095AB9:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00095ABB:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00495AC0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    --cpu->edx;
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    if ((cpu->edx == 2u) || ((int32_t)(cpu->edx) < (int32_t)(2u))) goto label_00095AF7;
    cpu->ebp = *(uint32_t*)(cpu->ecx);
    label_00095AD5:
    cpu->eax = cpu->edx + cpu->esi;
    cpu->eax = (int32_t)(cpu->eax) >> 1u;
    cpu->edi = *(uint32_t*)(cpu->ebp + (cpu->eax * 4u));
    cpu->edi = *(uint32_t*)(cpu->edi);
    sub_pred[0] = cpu->ebx <= cpu->edi;
    if (cpu->ebx >= cpu->edi) goto label_00095AE6;
    cpu->edx = cpu->eax;
    label_00095AE6:
    if (sub_pred[0]) goto label_00095AEA;
    cpu->esi = cpu->eax;
    label_00095AEA:
    if (cpu->ebx == cpu->edi) goto label_00095B19;
    cpu->eax = cpu->edx;
    cpu->eax -= cpu->esi;
    if ((cpu->eax != 2u) && ((int32_t)(cpu->eax) >= (int32_t)(2u))) goto label_00095AD5;
    label_00095AF7:
    cpu->eax = cpu->esi;
    if ((int32_t)cpu->esi > (int32_t)cpu->edx) goto label_00095B10;
    cpu->edi = *(uint32_t*)(cpu->ecx);
    cpu->ecx = cpu->edi + (cpu->esi * 4u);
    label_00095B02:
    cpu->esi = *(uint32_t*)(cpu->ecx);
    if (*(uint32_t*)(cpu->esi) == cpu->ebx) goto label_00095B24;
    ++cpu->eax;
    cpu->ecx += 4u;
    if ((int32_t)cpu->eax <= (int32_t)cpu->edx) goto label_00095B02;
    label_00095B10:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00095B19:
    cpu->eax = *(uint32_t*)(cpu->ebp + (cpu->eax * 4u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00095B24:
    cpu->eax = *(uint32_t*)(cpu->edi + (cpu->eax * 4u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00495B30(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    cpu->esp -= 0xCu;
    x87_v0 = 0.0;
    lift_push32(cpu, cpu->ebx);
    *(float*)(cpu->esp + 4u) = x87_v0;
    lift_push32(cpu, cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    *(float*)(cpu->esp + 0xCu) = x87_v0;
    cpu->esi = cpu->ecx;
    *(float*)(cpu->esp + 0x10u) = x87_v0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    *(float*)(cpu->esp + 8u) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0xCu) = x87_v0;
    *(uint32_t*)(cpu->esi + 0x3Cu) = cpu->eax;
    *(float*)(cpu->esp + 0x10u) = x87_v0;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    *(float*)(cpu->esp + 8u) = x87_v0;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    *(float*)(cpu->esp + 0xCu) = x87_v0;
    *(uint32_t*)(cpu->esi + 0x44u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0x10u) = x87_v0;
    x87_v1 = 1.0;
    *(uint32_t*)(cpu->esi + 0x48u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    *(float*)(cpu->esi + 0x60u) = x87_v1; 
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esi + 0x4Cu) = cpu->ecx;
    *(float*)(cpu->esp + 0xCu) = x87_v0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0x10u) = x87_v0;
    *(uint32_t*)(cpu->esi + 0x50u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    *(uint32_t*)(cpu->esi + 0x54u) = cpu->eax;
    *(float*)(cpu->esi + 0x1Cu) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->esi + 0x58u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, 0x40u);
    *(uint32_t*)(cpu->esi + 0x5Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esi + 0xB4u) = cpu->eax;
    cpu->ebx = cpu->esi + 0x74u;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esi + 0xB8u) = cpu->ecx;
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esi) = cpu->edi;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x64u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x68u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x6Cu) = 4u;
    *(uint32_t*)(cpu->esi + 0xBCu) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x70u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edi;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x495C00u));
    *(float*)(cpu->esi + 0xACu) = (double)*(float*)((uintptr_t)"(knNcache_lifetime");
    cpu->eax = 0x168u;
    x87_v0 = 1.0;
    *(uint32_t*)(cpu->esi + 0x90u) = cpu->eax;
    *(float*)(cpu->esi + 0xA8u) = x87_v0; 
    *(uint32_t*)(cpu->esi + 0x94u) = cpu->eax;
    x87_v0 = 0.0;
    cpu->esp += 0xCu;
    *(float*)(cpu->esp + 0xCu) = x87_v0;
    *(uint32_t*)(cpu->ebx) = 0x40u;
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    *(uint32_t*)(cpu->esi + 0xA4u) = cpu->edi;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    x87_v0 = (double)-1.0f;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    *(uint32_t*)(cpu->esi + 0x98u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xB0u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x9Cu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0xA0u) = cpu->edx;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00495C80(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    if (*(uint32_t*)(cpu->esi + 0x28u) == cpu->ebx) goto label_00095CE0;
    cpu->ebp = 0u;
    if (*(uint32_t*)(cpu->esi + 0x2Cu) <= cpu->ebx) goto label_00095CC5;
    cpu->edi = 0u;
    label_00095C96:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    if (*(uint32_t*)(cpu->edi + cpu->eax) == cpu->ebx) goto label_00095CBC;
    cpu->edx = 0x225u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x495CADu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x495CADu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edx = *(uint32_t*)(cpu->edi + cpu->ecx);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x495CB9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x495CB9u));
    cpu->esp += 4u;
    label_00095CBC:
    ++cpu->ebp;
    cpu->edi += 0xCu;
    if (cpu->ebp < *(uint32_t*)(cpu->esi + 0x2Cu)) goto label_00095C96;
    label_00095CC5:
    cpu->edx = 0x227u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x495CD4u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x495CD4u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x495CDDu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x495CDDu));
    cpu->esp += 4u;
    label_00095CE0:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->ebx;
    if (cpu->edi == cpu->ebx) goto label_00095DBD;
    cpu->edx = 0x22Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x495D01u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x495D01u));
    cpu->eax = cpu->edi;
    cpu->edx = 0xCu;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x495D19u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x495D19u));
    x87_v0 = 0.0;
    cpu->esp += 4u;
    cpu->edx = 0u;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->edi;
    if ((int32_t)(cpu->edi) < (int32_t)(4u)) goto label_00095D94;
    cpu->ecx = cpu->edi + 0xFFFFFFFCu;
    cpu->ecx >>= 2u;
    cpu->eax = 0u;
    ++cpu->ecx;
    cpu->edx = cpu->ecx * 4u;
    label_00095D3B:
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x28u);
    *(uint32_t*)(cpu->eax + cpu->ebp) = cpu->ebx;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x28u);
    *(uint8_t*)(cpu->eax + cpu->ebp + 4u) = cpu->ebx & 0xFFu;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x28u);
    *(float*)(cpu->eax + cpu->ebp + 8u) = x87_v0;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x28u);
    *(uint32_t*)(cpu->eax + cpu->ebp + 0xCu) = cpu->ebx;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x28u);
    *(uint8_t*)(cpu->eax + cpu->ebp + 0x10u) = cpu->ebx & 0xFFu;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x28u);
    *(float*)(cpu->eax + cpu->ebp + 0x14u) = x87_v0;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x28u);
    *(uint32_t*)(cpu->eax + cpu->ebp + 0x18u) = cpu->ebx;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x28u);
    *(uint8_t*)(cpu->eax + cpu->ebp + 0x1Cu) = cpu->ebx & 0xFFu;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x28u);
    *(float*)(cpu->eax + cpu->ebp + 0x20u) = x87_v0;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x28u);
    *(uint32_t*)(cpu->eax + cpu->ebp + 0x24u) = cpu->ebx;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x28u);
    *(uint8_t*)(cpu->eax + cpu->ebp + 0x28u) = cpu->ebx & 0xFFu;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x28u);
    *(float*)(cpu->eax + cpu->ebp + 0x2Cu) = x87_v0;
    cpu->eax += 0x30u;
    if ((--cpu->ecx) != 0u) goto label_00095D3B;
    label_00095D94:
    if (cpu->edx >= cpu->edi) goto label_00095DBB;
    cpu->eax = cpu->edx + (cpu->edx * 2u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->edi -= cpu->edx;
    label_00095DA1:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    *(uint32_t*)(cpu->eax + cpu->ecx) = cpu->ebx;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    *(uint8_t*)(cpu->eax + cpu->edx + 4u) = cpu->ebx & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    *(float*)(cpu->eax + cpu->ecx + 8u) = x87_v0;
    cpu->eax += 0xCu;
    if ((--cpu->edi) != 0u) goto label_00095DA1;
    label_00095DBB:
    x87_v0 = x87_v0; 
    label_00095DBD:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00495DD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (*(uint32_t*)(cpu->edi + 0x30u) == 0u) goto label_00095DF5;
    cpu->edx = 0x23Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x495DE9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x495DE9u));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x30u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x495DF2u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x495DF2u));
    cpu->esp += 4u;
    label_00095DF5:
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->edi + 0x30u) = 0u;
    *(uint32_t*)(cpu->edi + 0x34u) = 0u;
    if (cpu->esi == 0u) goto label_00095E47;
    cpu->edx = 0x243u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x495E1Au)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x495E1Au));
    cpu->eax = cpu->esi;
    cpu->edx = 0x10u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x495E32u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x495E32u));
    *(uint32_t*)(cpu->edi + 0x34u) = cpu->esi;
    cpu->esi <<= 4u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->edi + 0x30u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x495E3Fu));
    cpu->esp += 0x10u;
    label_00095E47:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00495E50(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4;
    bool lift_cmp[1];
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    x87_v1 = x87_v0;
    cpu->edx <<= 4u;
    x87_v2 = 0.0;
    cpu->edx += *(uint32_t*)(cpu->ecx + 0x30u);
    x87_v3 = x87_v2;
    lift_cmp[0]=x87_v3==x87_v1;
    x87_v1 = x87_v2; 
    x87_v2 = 24.0;
    if (lift_cmp[0]) goto label_00095E77;
    x87_v0 = (x87_v0) / (x87_v2);
    label_00095E77:
    { double temporary = x87_v2; x87_v2 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 4u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 4u);
    *(float*)(cpu->edx) = x87_v2;
    x87_v3 = (double)*(float*)(cpu->esp + 0xCu); x87_v4 = x87_v3;
    { const double lift_left=x87_v4; const double lift_right=x87_v1;  x87_v1=x87_v3;  if (lift_left==lift_right) goto label_00095E9A; }
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v2 / x87_v0; 
    goto label_00095E9E;
    label_00095E9A:
    x87_v0 = x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    label_00095E9E:
    x87_v2 = 1.0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v3 = x87_v2;
    x87_v1 = x87_v3 - x87_v1; 
    *(uint32_t*)(cpu->edx + 8u) = cpu->eax;
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    *(uint32_t*)(cpu->edx + 0xCu) = cpu->ecx;
    *(float*)(cpu->edx) = x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->esp + 4u) = x87_v1; 
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esp + 4u)));
    *(float*)(cpu->edx + 4u) = x87_v0; 
    if (cpu->eax <= cpu->ecx) goto label_00095ECD;
    *(uint32_t*)(cpu->edx + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->edx + 0xCu) = cpu->eax;
    label_00095ECD:
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00495ED0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    if (cpu->edi >= *(uint32_t*)(cpu->esi + 0x2Cu)) goto label_00095F33;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->ebx == 0u) goto label_00095F32;
    if (*(uint8_t*)(cpu->ebx) == 0u) goto label_00095F32;
    cpu->edx = 0x28Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x495EFAu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x495EFAu));
    cpu->eax = cpu->ebx;
    cpu->edx = cpu->eax + 1u;
    (void)cpu;
    label_00095F00:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00095F00;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x495F10u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x495F10u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ecx = cpu->edi + (cpu->edi * 2u);
    cpu->ecx += cpu->ecx;
    cpu->esp += 4u;
    cpu->ecx += cpu->ecx;
    *(uint32_t*)(cpu->ecx + cpu->edx) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + cpu->eax);
    cpu->edx = cpu->ebx;
    label_00095F28:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    *(uint8_t*)(cpu->ecx) = cpu->eax & 0xFFu;
    ++cpu->edx;
    ++cpu->ecx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00095F28;
    label_00095F32:
    cpu->ebx = lift_pop32(cpu);
    label_00095F33:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00495F40(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6, value_7, value_8, value_9, value_10, value_11;
 double x87_p0, x87_p1, x87_p2;
    cpu->esp -= 0x120u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x130u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x130u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, cpu->ebp);
    cpu->ebx = 0u;
    lift_push32(cpu, (uintptr_t)"eff_number");
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    *(uint32_t*)(cpu->edi + 4u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x495F7Eu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x495F7Eu));
    if (cpu->eax == 0u) goto label_00095F8C;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x495F8Au)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x495F8Au));
    *(uint32_t*)(cpu->edi) = cpu->eax;
label_00095F8C:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp);
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"audio_files");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x495FA0u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x495FA0u));
    if (cpu->eax == 0u) goto label_0009609B;
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x495FB4u)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x495FB4u));
    lift_push32(cpu, (uintptr_t)"source");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x495FC0u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x495FC0u));
    if (cpu->eax == 0u) goto label_000963C9;
label_00095FC8:
    lift_push32(cpu, (uintptr_t)"source");
    cpu->ecx = cpu->esi;
    ++cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x495FD5u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x495FD5u));
    if (cpu->eax != 0u) goto label_00095FC8;
    if (cpu->ebx == 0u) goto label_000963C9;
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x495FEDu)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x495FEDu));
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x495FF5u)); sfera_sub_00495C80(cpu, LIFT_CODE_TOKEN_VA(0x495FF5u));
    lift_push32(cpu, (uintptr_t)"source");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496001u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x496001u));
    if (cpu->eax == 0u) goto label_000960DB;
label_00096010:
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496019u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x496019u));
    cpu->ebp = cpu->eax;
    if ((int32_t)cpu->ebp >= (int32_t)cpu->ebx) goto label_000963C9;
    if ((int32_t)cpu->ebp < 0) goto label_000963C9;
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496039u)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x496039u));
    if (cpu->eax == 0u) goto label_00096081;
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49604Au)); sfera_sub_00495ED0(cpu, LIFT_CODE_TOKEN_VA(0x49604Au));
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, (uintptr_t)"silence"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x496054u));
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00096081;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x28u);
    cpu->ebp = cpu->ebp + (cpu->ebp * 2u);
    cpu->ebp += cpu->ebp;
    cpu->ebp += cpu->ebp;
    lift_push32(cpu, 2u);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->eax + cpu->ebp + 4u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49607Au)); value_11 = sfera_sub_004942C0(cpu, LIFT_CODE_TOKEN_VA(0x49607Au));
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x28u);
    *(float*)(cpu->ecx + cpu->ebp + 8u) = value_11; 
label_00096081:
    lift_push32(cpu, (uintptr_t)"source");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49608Du)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x49608Du));
    if (cpu->eax != 0u) goto label_00096010;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    goto label_000960DB;
label_0009609B:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"audio_file");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4960A8u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4960A8u));
    if (cpu->eax == 0u) goto label_000963C9;
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4960BDu)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x4960BDu));
    if (cpu->eax == 0u) goto label_000963C9;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4960CEu)); sfera_sub_00495C80(cpu, LIFT_CODE_TOKEN_VA(0x4960CEu));
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x960DBu)); sfera_sub_00495ED0(cpu, LIFT_CODE_TOKEN_RVA(0x960DBu));
label_000960DB:
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"time_groups");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4960EFu)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4960EFu));
    if (cpu->eax == 0u) goto label_000961E8;
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496103u)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x496103u));
    lift_push32(cpu, (uintptr_t)"time");
    cpu->ecx = cpu->esi;
    cpu->ebx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496111u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x496111u));
    if (cpu->eax == 0u) goto label_000961E8;
label_00096120:
    lift_push32(cpu, (uintptr_t)"time");
    cpu->ecx = cpu->esi;
    ++cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49612Du)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x49612Du));
    if (cpu->eax != 0u) goto label_00096120;
    if (cpu->ebx == 0u) goto label_000961E8;
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    cpu->ebp = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496147u)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x496147u));
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49614Fu)); sfera_sub_00495DD0(cpu, LIFT_CODE_TOKEN_VA(0x49614Fu));
    lift_push32(cpu, (uintptr_t)"time");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49615Bu)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x49615Bu));
    if (cpu->eax == 0u) goto label_000961E4;
    cpu->ebx = cpu->esi + 0x10u;
label_00096166:
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%f %f %d %d"); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x496180u));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x2Cu);
    cpu->esp += 0x18u;
    if (*(uint32_t*)(cpu->esp + 0x14u) >= cpu->eax) goto label_00096198;
    if (*(uint32_t*)(cpu->esp + 0x1Cu) < cpu->eax) goto label_000961AF;
label_00096198:
    cpu->edx = cpu->ebp + 1u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"CSoundEffect::LoadScript() -> Invalid audio index in block 'time_groups' line %d");
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4961A6u)); sfera_sub_0042E1D0(cpu, LIFT_CODE_TOKEN_VA(0x4961A6u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4961ACu)); sfera_sub_0042E4C0(cpu, LIFT_CODE_TOKEN_VA(0x4961ACu));
    cpu->esp += 0xCu;
label_000961AF:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    x87_p0 = (double)*(float*)(cpu->esp + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_p0; 
    cpu->ecx = cpu->edi;
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4961D3u)); sfera_sub_00495E50(cpu, LIFT_CODE_TOKEN_VA(0x4961D3u));
    lift_push32(cpu, (uintptr_t)"time");
    cpu->ecx = cpu->esi;
    ++cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4961E0u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x4961E0u));
    if (cpu->eax != 0u) goto label_00096166;
label_000961E4:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
label_000961E8:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"flags");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4961F5u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4961F5u));
    if (cpu->eax == 0u) goto label_00096230;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496200u)); sfera_sub_004947E0(cpu, LIFT_CODE_TOKEN_VA(0x496200u));
    cpu->ebp = cpu->eax;
    cpu->ebx = 0u;
    if ((int32_t)cpu->ebp <= 0) goto label_0009622C;
label_00096208:
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496215u)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x496215u));
    if (cpu->eax == 0u) goto label_00096225;
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496222u)); sfera_sub_00495910(cpu, LIFT_CODE_TOKEN_VA(0x496222u));
    *(uint32_t*)(cpu->edi + 4u) = (uint64_t)(*(uint32_t*)(cpu->edi + 4u)) | (uint64_t)(cpu->eax);
label_00096225:
    cpu->ebx += 2u;
    if ((int32_t)cpu->ebx < (int32_t)cpu->ebp) goto label_00096208;
label_0009622C:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
label_00096230:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"region_radius");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49623Du)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x49623Du));
    if (cpu->eax == 0u) goto label_0009625F;
    cpu->eax = cpu->edi + 0x50u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0x4Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 0x48u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%f %f %f"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x496256u));
    cpu->esp += 0x14u;
label_0009625F:
    x87_p0 = (double)0.029999999329447746f;
    lift_push32(cpu, cpu->ebp);
    cpu->ebx = 0u;
    *(float*)(cpu->esp + 0x14u) = x87_p0; 
    lift_push32(cpu, (uintptr_t)"min_distance");
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49627Cu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x49627Cu));
    if (cpu->eax == 0u) goto label_00096296;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496288u)); value_7 = sfera_sub_004942C0(cpu, LIFT_CODE_TOKEN_VA(0x496288u));
    *(float*)(cpu->edi + 0xA8u) = value_7; 
    *(uint32_t*)(cpu->esp + 0x14u) = 1u;
label_00096296:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"max_distance");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4962A3u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4962A3u));
    if (cpu->eax == 0u) goto label_000962BB;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4962B0u)); value_8 = sfera_sub_004942C0(cpu, LIFT_CODE_TOKEN_VA(0x4962B0u));
    *(float*)(cpu->edi + 0xACu) = value_8; 
    cpu->ebx = 1u;
label_000962BB:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"mix_duration");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4962C8u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4962C8u));
    if (cpu->eax == 0u) goto label_000962D8;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4962D5u)); value_9 = sfera_sub_004942C0(cpu, LIFT_CODE_TOKEN_VA(0x4962D5u));
    *(float*)(cpu->edi + 0x60u) = value_9; 
label_000962D8:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"vol_barier");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4962E5u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4962E5u));
    if (cpu->eax == 0u) goto label_00096330;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4962F2u)); value_10 = sfera_sub_004942C0(cpu, LIFT_CODE_TOKEN_VA(0x4962F2u));
    *(float*)(cpu->esp + 0x18u) = value_10; 
    value_1 = (double)*(float*)(cpu->esp + 0x18u); x87_p0 = value_1;
    x87_p1 = 0.0;
     value_2 = x87_p1; value_3 = x87_p0; if ((value_2)!=(value_3)) goto label_00096311;
    value_4 = 0.009999999776482582;
    value_0 = value_4; goto label_00096317;
label_00096311:
    value_5 = (value_1) / (100.0); value_0 = value_5;
label_00096317:
    *(float*)(cpu->esp + 0x10u) = value_0; 
    value_6 = 1.0;
    if (!((value_6)<(((double)*(float*)(cpu->esp + 0x10u))))) goto label_0009632E;
    *(float*)(cpu->esp + 0x10u) = value_6; 
     goto label_00096330;
label_0009632E:
label_00096330:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"offset_vec");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49633Du)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x49633Du));
    if (cpu->eax == 0u) goto label_0009635F;
    cpu->ecx = cpu->edi + 0x44u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 0x40u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->edi + 0x3Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x10u;
    lift_push32(cpu, (uintptr_t)"%f %f %f"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x496356u));
    cpu->esp += 0x14u;
label_0009635F:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, ((uintptr_t)"(knNcache_lifetime") + 4u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49636Cu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x49636Cu));
    if (cpu->eax == 0u) goto label_00096388;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496379u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x496379u));
    *(uint32_t*)(cpu->edi + 0x6Cu) = cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)0xAu) goto label_00096388;
    *(uint32_t*)(cpu->edi + 0x6Cu) = 0xAu;
label_00096388:
    if (*(uint32_t*)(cpu->esp + 0x14u) == 0u) goto label_000963A8;
    if (cpu->ebx != 0u) goto label_000963C2;
    x87_p0 = (double)*(float*)(cpu->edi + 0xA8u);
    cpu->eax = cpu->ebx + 1u;
    x87_p0 = (x87_p0) / (((double)*(float*)(cpu->esp + 0x10u)));
    *(float*)(cpu->edi + 0xACu) = x87_p0; 
    goto label_000963CB;
label_000963A8:
    if (cpu->ebx == 0u) goto label_000963C2;
    x87_p0 = (double)*(float*)(cpu->edi + 0xACu);
    x87_p1 = (double)*(float*)(cpu->esp + 0x10u);
    x87_p2 = 1.0;
    x87_p1 = x87_p2 / x87_p1; 
    x87_p0 = x87_p0 / x87_p1; 
    *(float*)(cpu->edi + 0xA8u) = x87_p0; 
label_000963C2:
    cpu->eax = 1u;
    goto label_000963CB;
label_000963C9:
    cpu->eax = 0u;
label_000963CB:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x120u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004963F0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    bool lift_cmp[10];
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 4u);
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((((cpu->eax & 0xFFu)) & (0x40u)) == 0u) goto label_0009661D;
    x87_v0 = (double)g_sfera_graphics_runtime.environment_factor;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x34u);
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    if ((int32_t)cpu->edi < (int32_t)4u) goto label_0009654B;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x30u);
    cpu->edi = 0x10u;
    cpu->edi -= cpu->eax;
    cpu->ecx = 0x20u;
    cpu->edx = 0u;
    cpu->ecx -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    goto label_00096441;
    label_0009643D:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    label_00096441:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x30u);
    x87_v1 = (double)*(float*)(cpu->edx + cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x30u);
    x87_v2 = (double)*(float*)(cpu->edx + cpu->eax + 4u);
    cpu->esi = cpu->edx + cpu->eax + 0x10u;
    lift_cmp[0]=x87_v2<x87_v1;  
    x87_v1 = (double)*(float*)(cpu->edx + cpu->ecx);
    lift_cmp[1]=x87_v1<x87_v0;
    if (!lift_cmp[0]) goto label_00096469;
    if (lift_cmp[1]) goto label_00096483;
    goto label_00096472;
    label_00096469:
    if (!lift_cmp[1]) goto label_000965B1;
    label_00096472:
    { const double lift_left=(double)*(float*)(cpu->edx + cpu->ecx + 4u); const double lift_right=x87_v0; if (!(lift_left>lift_right)) goto label_000965B1; }
    label_00096483:
    x87_v1 = (double)*(float*)(cpu->esi);
    x87_v2 = (double)*(float*)(cpu->esi + 4u);
    lift_cmp[2]=x87_v2<x87_v1;  
    x87_v1 = (double)*(float*)(cpu->edx + cpu->ecx + 0x10u);
    lift_cmp[3]=x87_v1<x87_v0;
    if (!lift_cmp[2]) goto label_000964A0;
    if (lift_cmp[3]) goto label_000964BA;
    goto label_000964A9;
    label_000964A0:
    if (!lift_cmp[3]) goto label_000965B0;
    label_000964A9:
    { const double lift_left=(double)*(float*)(cpu->edx + cpu->ecx + 0x14u); const double lift_right=x87_v0; if (!(lift_left>lift_right)) goto label_000965B0; }
    label_000964BA:
    x87_v1 = (double)*(float*)(cpu->esi + 0x10u);
    x87_v2 = (double)*(float*)(cpu->esi + 0x14u);
    lift_cmp[4]=x87_v2<x87_v1;  
    cpu->eax = cpu->ecx + cpu->esi;
    x87_v1 = (double)*(float*)(cpu->eax + cpu->edi);
    lift_cmp[5]=x87_v1<x87_v0;
    if (!lift_cmp[4]) goto label_000964DA;
    if (lift_cmp[5]) goto label_000964F4;
    goto label_000964E3;
    label_000964DA:
    if (!lift_cmp[5]) goto label_000965F4;
    label_000964E3:
    { const double lift_left=(double)*(float*)(cpu->edx + cpu->ecx + 0x24u); const double lift_right=x87_v0; if (!(lift_left>lift_right)) goto label_000965F4; }
    label_000964F4:
    x87_v1 = (double)*(float*)(cpu->esi + 0x20u);
    x87_v2 = (double)*(float*)(cpu->esi + 0x24u);
    lift_cmp[6]=x87_v2<x87_v1;  
    cpu->eax = cpu->ecx + cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    x87_v1 = (double)*(float*)(cpu->eax + cpu->esi);
    lift_cmp[7]=x87_v1<x87_v0;
    if (!lift_cmp[6]) goto label_00096518;
    if (lift_cmp[7]) goto label_00096532;
    goto label_00096521;
    label_00096518:
    if (!lift_cmp[7]) goto label_000965F9;
    label_00096521:
    { const double lift_left=(double)*(float*)(cpu->edx + cpu->ecx + 0x34u); const double lift_right=x87_v0; if (!(lift_left>lift_right)) goto label_000965F9; }
    label_00096532:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ebx += 4u;
    cpu->ecx = cpu->edi + 0xFFFFFFFDu;
    cpu->eax = 0u;
    cpu->edx += 0x40u;
    if (cpu->ebx < cpu->ecx) goto label_0009643D;
    goto label_0009654F;
    label_0009654B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_0009654F:
    if (cpu->ebx >= cpu->edi) goto label_000965FE;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x30u);
    cpu->ecx = cpu->ebx;
    cpu->ecx <<= 4u;
    cpu->edx = cpu->edx + cpu->ecx + 4u;
    label_00096563:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x30u);
    x87_v1 = (double)*(float*)(cpu->eax + cpu->ecx);
    x87_v2 = (double)*(float*)(cpu->edx);
    lift_cmp[8]=x87_v2<x87_v1;  
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x30u);
    x87_v1 = (double)*(float*)(cpu->ecx + cpu->eax);
    cpu->esi = cpu->ecx + cpu->eax;
    lift_cmp[9]=x87_v1<x87_v0;
    if (!lift_cmp[8]) goto label_00096588;
    if (lift_cmp[9]) goto label_00096599;
    goto label_0009658D;
    label_00096588:
    if (!lift_cmp[9]) goto label_000965B1;
    label_0009658D:
    { const double lift_left=(double)*(float*)(cpu->esi + 4u); const double lift_right=x87_v0; if (!(lift_left>lift_right)) goto label_000965B1; }
    label_00096599:
    ++cpu->ebx;
    cpu->ecx += 0x10u;
    cpu->edx += 0x10u;
    if (cpu->ebx < cpu->edi) goto label_00096563;
    cpu->edi = lift_pop32(cpu);
    x87_v0 = x87_v0; 
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000965B0:
    ++cpu->ebx;
    label_000965B1:
    x87_v0 = x87_v0; 
    label_000965B3:
    if (((*(uint8_t*)(cpu->esp + 0x1Cu)) & (0xCu)) == 0u) goto label_0009660C;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x30u);
    cpu->edi = cpu->ebx;
    cpu->edi += cpu->edi;
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->edi * 8u) + 0xCu);
    cpu->esi -= *(uint32_t*)(cpu->ecx + (cpu->edi * 8u) + 8u);
    cpu->eax = cpu->ecx + (cpu->edi * 8u);
    ++cpu->esi;
    if (cpu->esi <= 1u) goto label_0009660C;
    cpu->ebx = native_function_address32(&::rand);
    label_000965D8:
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    { const uint32_t n = cpu->eax, d = (uint32_t)(cpu->esi); cpu->eax = n / d; cpu->edx = n % d; }
    cpu->eax = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x30u);
    cpu->eax += *(uint32_t*)(cpu->edx + (cpu->edi * 8u) + 8u);
    if (cpu->eax == *(uint32_t*)(cpu->ebp + 0x64u)) goto label_000965D8;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000965F4:
    cpu->ebx += 2u;
    goto label_000965B1;
    label_000965F9:
    cpu->ebx += 3u;
    goto label_000965B1;
    label_000965FE:
    x87_v0 = x87_v0; 
    if (cpu->eax != 0u) goto label_000965B3;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0009660C:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x30u);
    cpu->ebx += cpu->ebx;
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->ebx * 8u) + 8u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0009661D:
    if ((((cpu->eax & 0xFFu)) & (0xCu)) == 0u) goto label_00096644;
    if (*(uint32_t*)(cpu->ebp + 0x2Cu) <= 1u) goto label_00096644;
    cpu->esi = native_function_address32(&::rand);
    label_00096630:
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    { const uint32_t n = cpu->eax, d = (uint32_t)(*(uint32_t*)(cpu->ebp + 0x2Cu)); cpu->eax = n / d; cpu->edx = n % d; }
    cpu->eax = cpu->edx;
    if (cpu->eax == *(uint32_t*)(cpu->ebp + 0x64u)) goto label_00096630;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00096644:
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00496650(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[2]; double x87_v0; double x87_p0;
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0x28u) == 0u) goto label_00096860;
    if (*(uint32_t*)(cpu->esi + 0x2Cu) == 0u) goto label_00096860;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496670u)); sfera_sub_00497970(cpu, LIFT_CODE_TOKEN_VA(0x496670u));
    cpu->edi = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edi;
    if (cpu->edi != 0u) goto label_00096682;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00096682:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x68u);
    if (cpu->eax == 0u) goto label_00096697;
    *(uint32_t*)(cpu->eax + 0x68u) = 1u;
    *(uint32_t*)(cpu->esi + 0x68u) = 0u;
    label_00096697:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4966A0u)); sfera_sub_004963F0(cpu, LIFT_CODE_TOKEN_VA(0x4966A0u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esi + 0x64u) = cpu->eax;
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->ebp = cpu->ecx + (cpu->eax * 4u);
    if (*(uint8_t*)(cpu->ecx + (cpu->eax * 4u) + 4u) == 0u) goto label_000966D4;
    *(uint32_t*)(cpu->esi + 8u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4966C3u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x4966C3u));
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->edx;
    *(float*)(cpu->esi + 0x18u) = (double)*(float*)(cpu->ebp + 8u);
    goto label_00096818;
    label_000966D4:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if ((((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_000966EF;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x6Cu);
    cpu->eax = *(uint32_t*)(cpu->ebp);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4966EAu)); sfera_sub_00497B80(cpu, LIFT_CODE_TOKEN_VA(0x4966EAu));
    goto label_00096815;
    label_000966EF:
    if ((((cpu->eax & 0xFFu)) & (0x20u)) == 0u) goto label_00096755;
    cpu->edi = native_function_address32(&::rand);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    cpu->ebx = cpu->eax;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    cpu->ebx -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    *(float*)(cpu->esi + 0x54u) = (((((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))))) * (3.0518509447574615e-05)))) * (((double)*(float*)(cpu->esi + 0x48u))));
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    cpu->ebx = cpu->eax;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    cpu->ebx -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    *(float*)(cpu->esi + 0x58u) = (((((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u)))))) * (3.0518509447574615e-05)))) * (((double)*(float*)(cpu->esi + 0x4Cu))));
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    cpu->ebx = cpu->eax;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x2Cu);
    x87_p0 = (x87_p0) * (3.0518509447574615e-05);
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esi + 0x50u)));
    *(float*)(cpu->esi + 0x5Cu) = x87_p0; 
    label_00096755:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    if (cpu->eax == 0u) goto label_000967ED;
    lift_test[0]=(*(uint8_t*)(cpu->esi + 4u)&0x20u)==0u;
    *(float*)(cpu->esp + 0x18u) = ((((double)*(float*)(cpu->eax))) - (((double)*(float*)(cpu->esi + 0x3Cu))));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(float*)(cpu->esp + 0x1Cu) = ((((double)*(float*)(cpu->eax + 4u))) - (((double)*(float*)(cpu->esi + 0x40u))));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    x87_v0 = (double)*(float*)(cpu->eax + 8u);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->esi + 0x44u)));
    *(uint32_t*)(cpu->esi + 0xB4u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0xB8u) = cpu->edx;
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->esi + 0xBCu) = cpu->eax;
    if (lift_test[0]) goto label_000967CF;
    *(float*)(cpu->esi + 0xB4u) = ((((double)*(float*)(cpu->esi + 0xB4u))) + (((double)*(float*)(cpu->esi + 0x54u))));
    *(float*)(cpu->esi + 0xB8u) = ((((double)*(float*)(cpu->esi + 0x58u))) + (((double)*(float*)(cpu->esi + 0xB8u))));
    *(float*)(cpu->esi + 0xBCu) = ((((double)*(float*)(cpu->esi + 0x5Cu))) + (((double)*(float*)(cpu->esi + 0xBCu))));
    label_000967CF:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xB4u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xB8u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xBCu);
    *(uint32_t*)(cpu->esi + 0x78u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x7Cu) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x80u) = cpu->eax;
    label_000967ED:
    cpu->eax = 0u;
    if (((*(uint8_t*)(cpu->esi + 4u)) & (0x1Cu)) == 0u) goto label_000967FA;
    cpu->eax = 1u;
    label_000967FA:
    if (cpu->ebx == 0u) goto label_00096802;
    if (cpu->eax != 0u) goto label_00096818;
    label_00096802:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x6Cu);
    cpu->eax = *(uint32_t*)(cpu->ebp);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esi + 0x74u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x96815u)); sfera_sub_00497CB0(cpu, LIFT_CODE_TOKEN_RVA(0x96815u));
    label_00096815:
    *(uint32_t*)(cpu->esi + 0x68u) = cpu->eax;
    label_00096818:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x68u);
    if (cpu->ecx == 0u) goto label_0009683F;
    if (cpu->ebx != 0u) goto label_00096835;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    x87_v0 = 0.0;
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    cpu->edx &= 0x10u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x96835u)); sfera_sub_004958C0(cpu, LIFT_CODE_TOKEN_RVA(0x96835u));
    label_00096835:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x68u);
    *(uint32_t*)(cpu->eax + 0x68u) = 0u;
    label_0009683F:
    cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->ebx;
    lift_test[1]=cpu->ebx==0u;
    cpu->ebx = lift_pop32(cpu);
    if (lift_test[1]) goto label_00096853;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49684Du)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x49684Du));
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->edx;
    label_00096853:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00096860:
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00496870(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x68u);
    if (cpu->ecx == 0u) goto label_000968A5;
    if (*(uint32_t*)(cpu->ecx + 0x6Cu) != 0u) goto label_00096894;
    lift_native_call(cpu, native_method_address32(&CSound::IsSoundPlaying), LIFT_CODE_TOKEN_VA(0x496880u));
    if (cpu->eax == 0u) goto label_00096894;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x68u);
    reinterpret_cast<CSoundFX*>(cpu->ecx)->stop(cpu);
    label_00096894:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x68u);
    *(uint32_t*)(cpu->eax + 0x68u) = 1u;
    *(uint32_t*)(cpu->esi + 0x68u) = 0u;
    label_000968A5:
    *(uint32_t*)(cpu->esi + 8u) = 0u;
    *(uint32_t*)(cpu->esi + 0x38u) = 0u;
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004968C0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x28u);
    *(uint32_t*)(cpu->eax + 0x28u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x2Cu);
    *(uint32_t*)(cpu->eax + 0x2Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x3Cu);
    *(uint32_t*)(cpu->eax + 0x3Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x40u);
    *(uint32_t*)(cpu->eax + 0x40u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x44u);
    *(uint32_t*)(cpu->eax + 0x44u) = cpu->edx;
    *(float*)(cpu->eax + 0x60u) = (double)*(float*)(cpu->ecx + 0x60u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x64u);
    *(uint32_t*)(cpu->eax + 0x64u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x6Cu);
    *(uint32_t*)(cpu->eax + 0x6Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x48u);
    *(uint32_t*)(cpu->eax + 0x48u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x4Cu);
    *(uint32_t*)(cpu->eax + 0x4Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x50u);
    *(uint32_t*)(cpu->eax + 0x50u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x54u);
    *(uint32_t*)(cpu->eax + 0x54u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x58u);
    *(uint32_t*)(cpu->eax + 0x58u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x5Cu);
    *(uint32_t*)(cpu->eax + 0x5Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x30u);
    *(uint32_t*)(cpu->eax + 0x30u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x34u);
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->eax + 0x34u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x38u);
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->eax + 0x38u) = cpu->edx;
    x87_v0 = (double)*(float*)(cpu->ecx + 0x1Cu);
    cpu->esi = cpu->ecx + 0x74u;
    *(float*)(cpu->eax + 0x1Cu) = x87_v0; 
    std::memmove((void*)(cpu->eax + 0x74u),(void*)(cpu->esi),64u); cpu->ecx = 0u;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 0x70u) = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00496960(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->esp -= 0xCu;
    x87_v0 = 0.0;
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x68u) = 0u;
    *(float*)(cpu->esp) = x87_v0;
    cpu->ecx = *(uint32_t*)(cpu->esp);
    *(float*)(cpu->esp + 4u) = x87_v0;
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(uint32_t*)(cpu->eax + 0xB4u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->eax + 0xB8u) = cpu->edx;
    *(uint32_t*)(cpu->eax + 0xBCu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x28u);
    *(uint32_t*)(cpu->eax + 0x28u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x2Cu);
    *(uint32_t*)(cpu->eax + 0x2Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x3Cu);
    *(uint32_t*)(cpu->eax + 0x3Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x40u);
    *(uint32_t*)(cpu->eax + 0x40u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x44u);
    *(uint32_t*)(cpu->eax + 0x44u) = cpu->edx;
    *(float*)(cpu->eax + 0x60u) = (double)*(float*)(cpu->ecx + 0x60u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x64u);
    *(uint32_t*)(cpu->eax + 0x64u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x6Cu);
    *(uint32_t*)(cpu->eax + 0x6Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x48u);
    *(uint32_t*)(cpu->eax + 0x48u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x4Cu);
    *(uint32_t*)(cpu->eax + 0x4Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x50u);
    *(uint32_t*)(cpu->eax + 0x50u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x54u);
    *(uint32_t*)(cpu->eax + 0x54u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x58u);
    *(uint32_t*)(cpu->eax + 0x58u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x5Cu);
    *(uint32_t*)(cpu->eax + 0x5Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x30u);
    *(uint32_t*)(cpu->eax + 0x30u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x34u);
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->eax + 0x34u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x38u);
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->eax + 0x38u) = cpu->edx;
    x87_v0 = (double)*(float*)(cpu->ecx + 0x1Cu);
    cpu->esi = cpu->ecx + 0x74u;
    *(float*)(cpu->eax + 0x1Cu) = x87_v0; 
    std::memmove((void*)(cpu->eax + 0x74u),(void*)(cpu->esi),64u); cpu->ecx = 0u;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->eax + 0x70u) = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00496A40(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1]; bool sub_pred[2]; double x87_v0, x87_v1;
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ebx = 1u;
    lift_push32(cpu, cpu->edi);
    if ((uint8_t)(((cpu->ebx & 0xFFu)) & ((cpu->ecx & 0xFFu))) != 0u) goto label_00096BC0;
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    cpu->edi = 0u;
    x87_v1 = (double)*(float*)(cpu->esi + 0xACu);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->esp + 0x20u)));
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (!(lift_left<lift_right)) goto label_00096B30; }
    if (*(uint32_t*)(cpu->esi + 0x38u) != cpu->edi) goto label_00096ADB;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x68u);
    if (cpu->ecx == cpu->edi) goto label_00096A9A;
    if (*(uint32_t*)(cpu->ecx + 0x6Cu) != cpu->edi) goto label_00096A9A;
    lift_native_call(cpu, native_method_address32(&CSound::IsSoundPlaying), LIFT_CODE_TOKEN_VA(0x496A86u));
    if (cpu->eax == 0u) goto label_00096A9A;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x68u);
    reinterpret_cast<CSoundFX*>(cpu->ecx)->stop(cpu);
    label_00096A9A:
    if (((*(uint8_t*)(cpu->esi + 4u)) & (0x1Cu)) != 0u) goto label_00096AB2;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x68u);
    if (cpu->ecx == cpu->edi) goto label_00096ABF;
    *(float*)(cpu->esi + 0x1Cu) = (double)(reinterpret_cast<CSound*>(static_cast<uintptr_t>(cpu->ecx))->GetPlayTimepos());
    goto label_00096ABF;
    label_00096AB2:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x68u);
    if (cpu->eax == cpu->edi) goto label_00096ABF;
    *(uint32_t*)(cpu->eax + 0x68u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x68u) = cpu->edi;
    label_00096ABF:
    *(uint32_t*)(cpu->esi + 8u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496ACAu)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x496ACAu));
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->edx;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00096ADB:
    if ((((cpu->ecx & 0xFFu)) & (0x1Cu)) != 0u) goto label_00096B25;
    if (*(uint32_t*)(cpu->esi + 0x68u) == cpu->edi) goto label_00096B25;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496AEAu)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x496AEAu));
    sub_pred[0] = cpu->eax < *(uint32_t*)(cpu->esi + 0x20u); cpu->eax -= *(uint32_t*)(cpu->esi + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x68u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x24u) + (sub_pred[0]);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    *(float*)(cpu->esp + 0x1Cu) = ((((double)(((int64_t)(*(uint64_t*)(cpu->esp + 0xCu)))))) / (10000.0));
    x87_v0 = (double)*(float*)(cpu->esi + 0x1Cu);
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x1Cu)));
    x87_v1 = (double)*(float*)(cpu->ecx + 0x50u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (!(lift_left<lift_right)) goto label_00096B25; }
    *(uint32_t*)(cpu->ecx + 0x68u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x68u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->edi;
    label_00096B25:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00096B30:
    if (*(uint32_t*)(cpu->esi + 0x38u) == cpu->edi) goto label_00096BC0;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496B3Eu)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x496B3Eu));
    sub_pred[1] = cpu->eax < *(uint32_t*)(cpu->esi + 0x20u); cpu->eax -= *(uint32_t*)(cpu->esi + 0x20u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x24u) + (sub_pred[1]);
    lift_test[0]=(*(uint8_t*)(cpu->esi + 4u)&0x1Cu)==0u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    *(float*)(cpu->esp + 0x1Cu) = ((((double)(((int64_t)(*(uint64_t*)(cpu->esp + 0xCu)))))) / (10000.0));
    if (!lift_test[0]) goto label_00096BB0;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x68u);
    if (cpu->ecx == cpu->edi) goto label_00096BBD;
    x87_v0 = (double)*(float*)(cpu->esi + 0x1Cu);
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x1Cu)));
    { const double lift_left=(double)*(float*)(cpu->ecx + 0x50u); const double lift_right=x87_v0; if (!(lift_left<lift_right)) goto label_00096B90; }
    *(uint32_t*)(cpu->ecx + 0x68u) = cpu->ebx;
    x87_v0 = x87_v0; 
    *(uint32_t*)(cpu->esi + 0x68u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00096B90:
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496BA2u)); sfera_sub_004958C0(cpu, LIFT_CODE_TOKEN_VA(0x496BA2u));
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00096BB0:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x96BBDu)); sfera_sub_00496650(cpu, LIFT_CODE_TOKEN_RVA(0x96BBDu));
    label_00096BBD:
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->edi;
    label_00096BC0:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00496BD0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0, x87_v1;
    x87_v0 = 0.0;
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esp -= 8u;
    *(float*)(cpu->esp + 4u) = x87_v0; 
    cpu->esi = cpu->ecx;
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496BF1u)); sfera_sub_00496A40(cpu, LIFT_CODE_TOKEN_VA(0x496BF1u));
    if (cpu->eax == 0u) goto label_00096DED;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    if (*(uint32_t*)(cpu->esi + 8u) == cpu->ebx) goto label_00096C95;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496C0Au)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x496C0Au));
    sub_pred[0] = cpu->eax < *(uint32_t*)(cpu->esi + 0x10u); cpu->eax -= *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x14u) + (sub_pred[0]);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    *(float*)(cpu->esp + 0xCu) = ((((double)(((int64_t)(*(uint64_t*)(cpu->esp + 0xCu)))))) / (10000.0));
    x87_v0 = 0.0;
    x87_v1 = (double)*(float*)(cpu->esp + 0xCu);
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (!(lift_left<lift_right)) goto label_00096C45; }
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    x87_v0 = x87_v0; 
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00096C45:
    if (((*(uint8_t*)(cpu->esi + 4u)) & (8u)) == 0u) goto label_00096C79;
    *(float*)(cpu->esp + 0xCu) = ((((double)*(float*)(cpu->esi + 0x18u))) - (((double)*(float*)(cpu->esi + 0x60u))));
    { const double lift_left=(double)*(float*)(cpu->esp + 0xCu); const double lift_right=x87_v0; if (!(lift_left<=lift_right)) goto label_00096C79; }
    lift_push32(cpu, cpu->ebx);
    x87_v0 = x87_v0; 
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496C70u)); sfera_sub_00496650(cpu, LIFT_CODE_TOKEN_VA(0x496C70u));
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00096C79:
    x87_v1 = (double)*(float*)(cpu->esi + 0x18u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (!(lift_left<=lift_right)) goto label_00096DEC; }
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00096C95:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x68u);
    if (cpu->ecx == cpu->ebx) goto label_00096DEC;
    if (*(uint32_t*)(cpu->ecx + 0x6Cu) == cpu->ebx) goto label_00096CB8;
    *(uint32_t*)(cpu->ecx + 0x68u) = 1u;
    *(uint32_t*)(cpu->esi + 0x68u) = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00096CB8:
    if (((*(uint8_t*)(cpu->esi + 4u)) & (8u)) == 0u) goto label_00096CF7;
    *(float*)(cpu->esp + 0xCu) = ((((double)*(float*)(cpu->ecx + 0x50u))) - (((double)*(float*)(cpu->esi + 0x60u))));
    x87_v0 = reinterpret_cast<CSound*>(static_cast<uintptr_t>(cpu->ecx))->GetPlayTimepos();
    x87_v1 = (double)*(float*)(cpu->esp + 0xCu);
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (!(lift_left<=lift_right)) goto label_00096CF7; }
    cpu->eax = *(uint32_t*)(cpu->esi + 0x68u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->eax + 0x68u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496CEEu)); sfera_sub_00496650(cpu, LIFT_CODE_TOKEN_VA(0x496CEEu));
    if (*(uint32_t*)(cpu->esi + 0x68u) == cpu->ebx) goto label_00096DEC;
    label_00096CF7:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if ((((cpu->eax & 0xFFu)) & (1u)) != 0u) goto label_00096DEC;
    *(float*)(cpu->esp + 0xCu) = ((((double)*(float*)(cpu->edi))) - (((double)*(float*)(cpu->esi + 0x3Cu))));
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->edi + 4u))) - (((double)*(float*)(cpu->esi + 0x40u))));
    *(float*)(cpu->esp + 0x14u) = ((((double)*(float*)(cpu->edi + 8u))) - (((double)*(float*)(cpu->esi + 0x44u))));
    if ((((cpu->eax & 0xFFu)) & (0x20u)) == 0u) goto label_00096D44;
    *(float*)(cpu->esp + 0xCu) = ((((double)*(float*)(cpu->esi + 0x54u))) + (((double)*(float*)(cpu->esp + 0xCu))));
    *(float*)(cpu->esp + 0x10u) = ((((double)*(float*)(cpu->esi + 0x58u))) + (((double)*(float*)(cpu->esp + 0x10u))));
    *(float*)(cpu->esp + 0x14u) = ((((double)*(float*)(cpu->esi + 0x5Cu))) + (((double)*(float*)(cpu->esp + 0x14u))));
    label_00096D44:
    *(float*)(cpu->esp + 0x18u) = ((((double)*(float*)(cpu->esp + 0xCu))) - (((double)*(float*)(cpu->esi + 0xB4u))));
    *(float*)(cpu->esp + 0x1Cu) = ((((double)*(float*)(cpu->esp + 0x10u))) - (((double)*(float*)(cpu->esi + 0xB8u))));
    *(float*)(cpu->esp + 0x20u) = ((((double)*(float*)(cpu->esp + 0x14u))) - (((double)*(float*)(cpu->esi + 0xBCu))));
    if (*(uint32_t*)(cpu->esp + 0x18u) != cpu->ebx) goto label_00096D80;
    if (*(uint32_t*)(cpu->esp + 0x1Cu) != cpu->ebx) goto label_00096D80;
    if (*(uint32_t*)(cpu->esp + 0x20u) == cpu->ebx) goto label_00096DEC;
    label_00096D80:
    x87_v0 = (double)*(float*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebx);
    cpu->esp -= 0xCu;
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(uint32_t*)(cpu->esi + 0xB4u) = cpu->ecx;
    x87_v0 = (double)*(float*)(cpu->esp + 0x2Cu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x68u);
    *(float*)(cpu->esp + 4u) = x87_v0; 
    *(uint32_t*)(cpu->esi + 0xB8u) = cpu->edx;
    x87_v0 = (double)*(float*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esi + 0xBCu) = cpu->eax;
    *(float*)(cpu->esp) = x87_v0; 
    lift_native_call(cpu, native_method_address32(&CSound::SetVelocity), LIFT_CODE_TOKEN_VA(0x496DBCu));
    x87_v0 = (double)*(float*)(cpu->esi + 0xBCu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x68u);
    lift_push32(cpu, cpu->ebx);
    cpu->esp -= 0xCu;
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esi + 0xB8u);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esi + 0xB4u);
    lift_native_call(cpu, native_method_address32(&CSound::SetPosition), LIFT_CODE_TOKEN_RVA(0x96DE6u));
    label_00096DEC:
    cpu->ebx = lift_pop32(cpu);
    label_00096DED:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00496E00(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0;
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->esi == 0xFFFFFFFFu) goto label_00096EE7;
    lift_native_call(cpu, native_function_address32(&SI_GetInterface), LIFT_CODE_TOKEN_VA(0x496E1Au));
    if (*(uint32_t*)(cpu->esi + 0x20u) == 0u) goto label_00096EE0;
    if (cpu->eax == 0u) goto label_00096EE0;
    if (*(uint16_t*)(cpu->esi) != 1u) goto label_00096E4F;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x14u);
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    goto label_00096E5B;
    label_00096E4F:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x96E5Bu)); sfera_sub_00455E40(cpu, LIFT_CODE_TOKEN_RVA(0x96E5Bu));
    label_00096E5B:
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x24u) == 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x20u);
    if (!sub_pred[0]) goto label_00096E97;
    { const double lift_right=(double)*(float*)(cpu->esp + 0x1Cu); const double lift_left=(double)*(float*)(cpu->edi + 0xACu); if (!(lift_left<lift_right)) goto label_00096E7F; }
    cpu->eax = 1u;
    goto label_00096E81;
    label_00096E7F:
    cpu->eax = 0u;
    label_00096E81:
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496E8Eu)); sfera_sub_00496650(cpu, LIFT_CODE_TOKEN_VA(0x496E8Eu));
    *(uint32_t*)(cpu->esi + 0x24u) = 1u;
    goto label_00096EAB;
    label_00096E97:
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0xCu;
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x96EABu)); sfera_sub_00496BD0(cpu, LIFT_CODE_TOKEN_RVA(0x96EABu));
    label_00096EAB:
    if (*(uint32_t*)(cpu->edi + 0x38u) != 0u) goto label_00096ECB;
    if (*(uint32_t*)(cpu->edi + 8u) != 0u) goto label_00096ECB;
    cpu->edi = *(uint32_t*)(cpu->edi + 0x68u);
    if (cpu->edi == 0u) goto label_00096EC4;
    if (*(uint32_t*)(cpu->edi + 0x6Cu) == 0u) goto label_00096ECB;
    label_00096EC4:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x96ECBu)); sfera_sub_00429B20(cpu, LIFT_CODE_TOKEN_RVA(0x96ECBu));
    label_00096ECB:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00096EE0:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x96EE7u)); sfera_sub_00429B20(cpu, LIFT_CODE_TOKEN_RVA(0x96EE7u));
    label_00096EE7:
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00496F00(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebp = 0u;
    if (*(uint32_t*)(cpu->esi + 0x70u) != cpu->ebp) goto label_00096F8C;
    if (*(uint32_t*)(cpu->esi + 0x28u) == cpu->ebp) goto label_00096F6C;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    if (*(uint32_t*)(cpu->esi + 0x2Cu) <= cpu->ebp) goto label_00096F50;
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    (void)cpu;
    label_00096F20:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    if (*(uint32_t*)(cpu->edi + cpu->eax) == cpu->ebp) goto label_00096F46;
    cpu->edx = 0x29Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496F37u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x496F37u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x28u);
    cpu->edx = *(uint32_t*)(cpu->edi + cpu->ecx);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496F43u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x496F43u));
    cpu->esp += 4u;
    label_00096F46:
    ++cpu->ebx;
    cpu->edi += 0xCu;
    if (cpu->ebx < *(uint32_t*)(cpu->esi + 0x2Cu)) goto label_00096F20;
    cpu->edi = lift_pop32(cpu);
    label_00096F50:
    cpu->edx = 0x2A0u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496F5Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x496F5Fu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496F68u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x496F68u));
    cpu->esp += 4u;
    cpu->ebx = lift_pop32(cpu);
    label_00096F6C:
    if (*(uint32_t*)(cpu->esi + 0x30u) == cpu->ebp) goto label_00096F8C;
    cpu->edx = 0x2A3u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496F80u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x496F80u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x496F89u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x496F89u));
    cpu->esp += 4u;
    label_00096F8C:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x68u);
    if (cpu->ecx == cpu->ebp) goto label_00096FB9;
    if (*(uint32_t*)(cpu->ecx + 0x6Cu) != cpu->ebp) goto label_00096FAC;
    lift_native_call(cpu, native_method_address32(&CSound::IsSoundPlaying), LIFT_CODE_TOKEN_VA(0x496F98u));
    if (cpu->eax == 0u) goto label_00096FAC;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x68u);
    reinterpret_cast<CSoundFX*>(cpu->ecx)->stop(cpu);
    label_00096FAC:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x68u);
    *(uint32_t*)(cpu->ecx + 0x68u) = 1u;
    *(uint32_t*)(cpu->esi + 0x68u) = cpu->ebp;
    label_00096FB9:
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x70u) = cpu->ebp;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00496FE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x68u);
    if (cpu->ecx == 0u) goto label_00097015;
    if (*(uint32_t*)(cpu->ecx + 0x6Cu) != 0u) goto label_00097004;
    lift_native_call(cpu, native_method_address32(&CSound::IsSoundPlaying), LIFT_CODE_TOKEN_VA(0x496FF0u));
    if (cpu->eax == 0u) goto label_00097004;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x68u);
    reinterpret_cast<CSoundFX*>(cpu->ecx)->stop(cpu);
    label_00097004:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x68u);
    *(uint32_t*)(cpu->eax + 0x68u) = 1u;
    *(uint32_t*)(cpu->esi + 0x68u) = 0u;
    label_00097015:
    *(uint32_t*)(cpu->esi + 8u) = 0u;
    *(uint32_t*)(cpu->esi + 0x38u) = 0u;
    cpu->ecx = g_sfera_sound_effect_items.free_count;
    cpu->edx = g_sfera_sound_effect_items.free_items;
    *(uint32_t*)(cpu->edx + (cpu->ecx * 4u)) = cpu->esi;
    ++g_sfera_sound_effect_items.free_count;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00497040(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    if ((int32_t)*(uint32_t*)(cpu->esi + 8u) < (int32_t)cpu->eax) goto label_000970D2;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    if ((int32_t)cpu->ecx > 0) goto label_0009705C;
    label_00097057:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0009705C:
    cpu->ecx += cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    cpu->edx = 0x17Au;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497070u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x497070u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = 4u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497089u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x497089u));
    cpu->edi = cpu->eax;
    cpu->esp += 4u;
    if (cpu->edi == 0u) goto label_000970D2;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x49709Du));
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4970AEu));
    cpu->esp += 0x18u;
    cpu->edx = 0x17Fu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4970C5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4970C5u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4970CDu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4970CDu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi) = cpu->edi;
    label_000970D2:
    if (*(uint32_t*)(cpu->esi) == 0u) goto label_00097057;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = 0x18Cu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4970E7u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4970E7u));
    lift_push32(cpu, 0xC0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4970F1u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4970F1u));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_00097103;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4970FFu)); sfera_sub_00495B30(cpu, LIFT_CODE_TOKEN_VA(0x4970FFu));
    cpu->ebx = cpu->eax;
    goto label_00097105;
    label_00097103:
    cpu->ebx = 0u;
    label_00097105:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    if (*(uint32_t*)(cpu->edx + (cpu->ecx * 4u)) == 0u) goto label_0009713B;
    cpu->edx = 0x18Du;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49711Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x49711Fu));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edi = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    if (cpu->edi == 0u) goto label_0009713B;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497132u)); sfera_sub_00496F00(cpu, LIFT_CODE_TOKEN_VA(0x497132u));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497138u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x497138u));
    cpu->esp += 4u;
    label_0009713B:
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax + (cpu->edx * 4u)) = cpu->ebx;
    ++*(uint32_t*)(cpu->esi + 8u);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00497150(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x268u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Sounds\\*.def");
    cpu->ebx = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::FindFirstFileA), LIFT_CODE_TOKEN_VA(0x49719Cu));
    cpu->esi = cpu->eax;
    cpu->eax = 0u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->esi != 0xFFFFFFFFu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    if (cpu->eax == 0u) goto label_0009731A;
    label_000971C0:
    if (((*(uint8_t*)(cpu->esp + 0x2Cu)) & (0x10u)) != 0u) goto label_00097302;
    cpu->ecx = *(uint32_t*)((uintptr_t)"Sounds\\");
    cpu->edx = *(uint32_t*)(((uintptr_t)"Sounds\\") + 4u);
    cpu->eax = cpu->esp + 0x58u;
    *(uint32_t*)(cpu->esp + 0x16Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x170u) = cpu->edx;
    cpu->esi = cpu->eax;
    label_000971F0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000971F0;
    cpu->edi = cpu->esp + 0x16Cu;
    cpu->eax -= cpu->esi;
    --cpu->edi;
    label_00097201:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00097201;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax;
    cpu->edx = 0x1A8u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497226u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x497226u));
    lift_push32(cpu, 0x420u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497230u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x497230u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x280u) = 0u;
    if (cpu->eax == 0u) goto label_00097251;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49724Du)); sfera_sub_00493BF0(cpu, LIFT_CODE_TOKEN_VA(0x49724Du));
    cpu->esi = cpu->eax;
    goto label_00097253;
    label_00097251:
    cpu->esi = 0u;
    label_00097253:
    cpu->eax = cpu->esp + 0x16Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x284u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49726Du)); sfera_sub_00494940(cpu, LIFT_CODE_TOKEN_VA(0x49726Du));
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497276u)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x497276u));
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"soundeffect");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497287u)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x497287u));
    if (cpu->eax == 0u) goto label_000972DF;
    label_00097290:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497297u)); sfera_sub_00497040(cpu, LIFT_CODE_TOKEN_VA(0x497297u));
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    cpu->edi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4972A5u)); sfera_sub_00494900(cpu, LIFT_CODE_TOKEN_VA(0x4972A5u));
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4972B2u)); sfera_sub_00495F40(cpu, LIFT_CODE_TOKEN_VA(0x4972B2u));
    if (cpu->eax != 0u) goto label_000972BE;
    if ((int32_t)(--*(uint32_t*)(cpu->ebx + 8u)) >= 0) goto label_000972BE;
    *(uint32_t*)(cpu->ebx + 8u) = cpu->eax;
    label_000972BE:
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4972CAu)); sfera_sub_00494850(cpu, LIFT_CODE_TOKEN_VA(0x4972CAu));
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"soundeffect");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4972DBu)); sfera_sub_004948C0(cpu, LIFT_CODE_TOKEN_VA(0x4972DBu));
    if (cpu->eax != 0u) goto label_00097290;
    label_000972DF:
    cpu->edx = 0x1BBu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4972EEu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4972EEu));
    if (cpu->esi == 0u) goto label_00097302;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4972F9u)); sfera_sub_00493C00(cpu, LIFT_CODE_TOKEN_VA(0x4972F9u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4972FFu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4972FFu));
    cpu->esp += 4u;
    label_00097302:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindNextFileA), LIFT_CODE_TOKEN_VA(0x49730Cu));
    if (cpu->eax != 0u) goto label_000971C0;
    label_0009731A:
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindClose), LIFT_CODE_TOKEN_VA(0x49731Bu));
    if (*(uint32_t*)(cpu->ebx) == 0u) goto label_00097339;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    if ((int32_t)cpu->eax <= (int32_t)1u) goto label_00097339;
    --cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x97339u)); sfera_sub_00495A30(cpu, LIFT_CODE_TOKEN_RVA(0x97339u));
    label_00097339:
    cpu->eax = 1u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00497370(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 8u;
    if (g_sfera_sound_runtime.effect_manager != 0u) goto label_000973E6;
    cpu->edx = 0x67u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4973A9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4973A9u));
    lift_push32(cpu, 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4973B0u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4973B0u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    if (cpu->eax == 0u) goto label_000973D0;
    lift_push32(cpu, 0x32u); lift_push32(cpu, 0x64u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4973CEu)); sfera_sub_004959B0(cpu, LIFT_CODE_TOKEN_VA(0x4973CEu));
    goto label_000973D2;
    label_000973D0:
    cpu->eax = 0u;
    label_000973D2:
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = 0xFFFFFFFFu;
    g_sfera_sound_runtime.effect_manager = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x973E6u)); sfera_sub_00497150(cpu, LIFT_CODE_TOKEN_RVA(0x973E6u));
    label_000973E6:
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00497400(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi) == 0u) goto label_00097469;
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 4u) <= (int32_t)cpu->edi) goto label_00097448;
    lift_push32(cpu, cpu->ebx);
    label_00097411:
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (*(uint32_t*)(cpu->eax + (cpu->edi * 4u)) == 0u) goto label_00097441;
    cpu->edx = 0x117u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497428u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x497428u));
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->ebx = *(uint32_t*)(cpu->ecx + (cpu->edi * 4u));
    if (cpu->ebx == 0u) goto label_00097441;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497438u)); sfera_sub_00496F00(cpu, LIFT_CODE_TOKEN_VA(0x497438u));
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49743Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49743Eu));
    cpu->esp += 4u;
    label_00097441:
    ++cpu->edi;
    if ((int32_t)cpu->edi < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00097411;
    cpu->ebx = lift_pop32(cpu);
    label_00097448:
    cpu->edx = 0x119u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497457u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x497457u));
    cpu->edx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49745Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49745Fu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi) = 0u;
    cpu->edi = lift_pop32(cpu);
    label_00097469:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00497470(LiftCpu* cpu, uint32_t stop_address) {
    if (g_sfera_sound_runtime.effect_manager == 0u) goto label_000974AE;
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0x77u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497489u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x497489u));
    cpu->ecx = g_sfera_sound_runtime.effect_manager;
    cpu->esi = cpu->ecx;
    if (cpu->ecx == 0u) goto label_000974A3;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49749Au)); sfera_sub_00497400(cpu, LIFT_CODE_TOKEN_VA(0x49749Au));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4974A0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4974A0u));
    cpu->esp += 4u;
    label_000974A3:
    g_sfera_sound_runtime.effect_manager = 0u;
    cpu->esi = lift_pop32(cpu);
    label_000974AE:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004974B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    if (*(uint32_t*)(cpu->esi + 0x10u) == cpu->ebx) goto label_000974D8;
    cpu->edx = cpu->ebx + 0x48u;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ItemArray.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4974C9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4974C9u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4974D2u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4974D2u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    label_000974D8:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esi + 4u);
    cpu->ebp -= *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ebx;
    cpu->ebp = (int32_t)(cpu->ebp) >> 2u;
    if ((int32_t)cpu->ebp <= (int32_t)cpu->ebx) goto label_0009752D;
    label_000974F0:
    cpu->edx = 0x4Fu;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ItemArray.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4974FFu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4974FFu));
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->ebx * 4u));
    if (cpu->eax == 0u) goto label_00097528;
    cpu->edx = *(uint32_t*)(cpu->eax + 0xFFFFFFFCu);
    cpu->edi = cpu->eax + 0xFFFFFFFCu;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00425940)); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0xC0u); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49751Fu)); sfera_sub_004EEB86(cpu, LIFT_CODE_TOKEN_VA(0x49751Fu));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497525u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x497525u));
    cpu->esp += 4u;
    label_00097528:
    ++cpu->ebx;
    if ((int32_t)cpu->ebx < (int32_t)cpu->ebp) goto label_000974F0;
    label_0009752D:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi = *(uint32_t*)(cpu->esi);
    cpu->ebp = lift_pop32(cpu);
    if (cpu->edi == cpu->ecx) goto label_00097556;
    cpu->eax = cpu->ecx;
    cpu->eax -= cpu->ecx;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    cpu->ebx = cpu->eax * 4u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x497548u));
    cpu->esp += 0xCu;
    cpu->ebx += cpu->edi;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebx;
    label_00097556:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00497560(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    cpu->esi = cpu->ecx;
    cpu->edx = 0x60u;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ItemArray.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497596u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x497596u));
    cpu->edi = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax = cpu->edi;
    cpu->edx = 0xC0u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    cpu->eax = 0u;
    cpu->ecx += 4u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->ecx < 4u);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->eax |= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4975BDu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4975BDu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebp;
    if (cpu->eax == cpu->ebp) goto label_000975EB;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00425940)); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00495B30)); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->eax + 4u;
    lift_push32(cpu, 0xC0u); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->eax) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4975E9u)); sfera_sub_004EEBE9(cpu, LIFT_CODE_TOKEN_VA(0x4975E9u));
    cpu->ebp = cpu->ebx;
    label_000975EB:
    cpu->edx = 0x62u;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ItemArray.h";
    *(uint32_t*)(cpu->esp + 0x20u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497606u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x497606u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax -= *(uint32_t*)(cpu->esi);
    cpu->ecx=0u;
    cpu->eax = (uint32_t)((int32_t)cpu->eax >> 2u);
    ++cpu->eax;
    cpu->eax *= *(uint32_t*)(cpu->esi + 0x18u);
    cpu->edx = 4u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497629u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x497629u));
    cpu->edi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_00097662;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x49763Fu));
    cpu->esp += 0xCu;
    cpu->edx = 0x67u;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ItemArray.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497656u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x497656u));
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49765Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49765Fu));
    cpu->esp += 4u;
    label_00097662:
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    cpu->eax = cpu->ebp;
    cpu->ebx = cpu->ecx + 1u;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x18u) <= (int32_t)cpu->ecx) goto label_00097689;
    label_00097671:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x14u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x10u);
    *(uint32_t*)(cpu->edi + (cpu->edx * 4u)) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x14u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u);
    cpu->ecx += cpu->ebx;
    cpu->eax += 0xC0u;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->esi + 0x18u)) goto label_00097671;
    label_00097689:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = cpu->esp + 0x14u;
    if (cpu->ecx >= cpu->eax) goto label_000976FD;
    cpu->edx = *(uint32_t*)(cpu->esi);
    if (cpu->edx > cpu->ecx) goto label_000976FD;
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->edi -= cpu->edx;
    cpu->edi = (int32_t)(cpu->edi) >> 2u;
    if (cpu->eax != cpu->ecx) goto label_000976ED;
    cpu->eax -= cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    if (cpu->eax <= 0x3FFFFFFEu) goto label_000976BF;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x497689u), "std::length_error");
    label_000976BF:
    cpu->ecx -= cpu->edx;
    cpu->eax += cpu->ebx;
    cpu->ecx = (int32_t)(cpu->ecx) >> 2u;
    if (cpu->eax <= cpu->ecx) goto label_000976ED;
    cpu->edx = cpu->ecx;
    cpu->edx >>= 1u;
    cpu->ebx = 0x3FFFFFFFu;
    cpu->ebx -= cpu->edx;
    if (cpu->ebx >= cpu->ecx) goto label_000976DD;
    cpu->ecx = 0u;
    goto label_000976DF;
    label_000976DD:
    cpu->ecx += cpu->edx;
    label_000976DF:
    if (cpu->ecx >= cpu->eax) goto label_000976E5;
    cpu->ecx = cpu->eax;
    label_000976E5:
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x976EDu)); sfera_sub_00429830(cpu, LIFT_CODE_TOKEN_RVA(0x976EDu));
    label_000976ED:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax == 0u) goto label_00097754;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    goto label_00097754;
    label_000976FD:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    if (cpu->eax != cpu->ecx) goto label_0009774B;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->eax -= cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    if (cpu->eax <= 0x3FFFFFFEu) goto label_0009771D;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x4976FDu), "std::length_error");
    label_0009771D:
    cpu->ecx -= cpu->edx;
    cpu->eax += cpu->ebx;
    cpu->ecx = (int32_t)(cpu->ecx) >> 2u;
    if (cpu->eax <= cpu->ecx) goto label_0009774B;
    cpu->edx = cpu->ecx;
    cpu->edx >>= 1u;
    cpu->edi = 0x3FFFFFFFu;
    cpu->edi -= cpu->edx;
    if (cpu->edi >= cpu->ecx) goto label_0009773B;
    cpu->ecx = 0u;
    goto label_0009773D;
    label_0009773B:
    cpu->ecx += cpu->edx;
    label_0009773D:
    if (cpu->ecx >= cpu->eax) goto label_00097743;
    cpu->ecx = cpu->eax;
    label_00097743:
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9774Bu)); sfera_sub_00429830(cpu, LIFT_CODE_TOKEN_RVA(0x9774Bu));
    label_0009774B:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax == 0u) goto label_00097754;
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    label_00097754:
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) + (uint64_t)(4u) + (uint64_t)(0u);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00497770(LiftCpu* cpu, uint32_t stop_address) {
    if (*(uint32_t*)(cpu->ecx + 8u) == 0u) goto label_000977D4;
    if (*(uint32_t*)(cpu->ecx) == 0u) goto label_000977D4;
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497786u)); sfera_sub_00495AC0(cpu, LIFT_CODE_TOKEN_VA(0x497786u));
    cpu->edi = cpu->eax;
    if (cpu->edi == 0u) goto label_000977CE;
    if (g_sfera_sound_effect_items.free_count != 0u) goto label_0009779F;
    cpu->ecx = (uintptr_t)&g_sfera_sound_effect_items;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9779Fu)); sfera_sub_00497560(cpu, LIFT_CODE_TOKEN_RVA(0x9779Fu));
    label_0009779F:
    cpu->eax = g_sfera_sound_effect_items.free_count;
    cpu->ecx = g_sfera_sound_effect_items.free_items;
    --cpu->eax;
    lift_push32(cpu, cpu->esi);
    g_sfera_sound_effect_items.free_count = cpu->eax;
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    if (cpu->esi != 0u) goto label_000977BF;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000977BF:
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4977C7u)); sfera_sub_00496960(cpu, LIFT_CODE_TOKEN_VA(0x4977C7u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000977CE:
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000977D4:
    cpu->eax = 0u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004977E0(LiftCpu* cpu, uint32_t stop_address) { double value_0;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = cpu->edx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    if ((int32_t)cpu->esi >= (int32_t)0x1388u) goto label_000977FC;
    cpu->esi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
label_000977FC:
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if (g_sfera_sound_runtime.effect_manager == cpu->edi) goto label_00097811;
    lift_native_call(cpu, native_function_address32(&SI_GetInterface), LIFT_CODE_TOKEN_VA(0x497807u));
    if (cpu->eax != 0u) goto label_0009781B;
label_00097811:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
label_0009781B:
    cpu->ecx = g_sfera_sound_runtime.effect_manager;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497828u)); sfera_sub_00497770(cpu, LIFT_CODE_TOKEN_VA(0x497828u));
    cpu->ebp = cpu->eax;
    if (cpu->ebp == cpu->edi) goto label_00097882;
    if (g_sfera_effect_items.free_count != cpu->edi) goto label_00097840;
    cpu->ecx = (uintptr_t)&g_sfera_effect_items;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x97840u)); sfera_sub_0042A480(cpu, LIFT_CODE_TOKEN_RVA(0x97840u));
label_00097840:
    cpu->eax = g_sfera_effect_items.free_count;
    cpu->ecx = g_sfera_effect_items.free_items;
    --cpu->eax;
    g_sfera_effect_items.free_count = cpu->eax;
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    if (*(uint32_t*)(cpu->esp + 0x18u) != cpu->edi) goto label_0009788D;
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497863u)); sfera_sub_00456040(cpu, LIFT_CODE_TOKEN_VA(0x497863u));
    if (cpu->eax != 0u) goto label_0009788D;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49786Eu)); sfera_sub_00496FE0(cpu, LIFT_CODE_TOKEN_VA(0x49786Eu));
    cpu->edx = g_sfera_effect_items.free_count;
    cpu->eax = g_sfera_effect_items.free_items;
    *(uint32_t*)(cpu->eax + (cpu->edx * 4u)) = cpu->esi;
    ++g_sfera_effect_items.free_count;
label_00097882:
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
label_0009788D:
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)(cpu->esp + 0x18u));
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebx;
    cpu->edx = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint16_t*)(cpu->esi) = cpu->ecx & 0xFFFFu;
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->ebp;
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x18u) = LIFT_CALLBACK(sfera_sub_00496E00);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4978B8u)); value_0 = sfera_sub_00425B20(cpu, LIFT_CODE_TOKEN_VA(0x4978B8u));
    *(float*)(cpu->esi + 0x2Cu) = value_0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = 0xFFFFu;
    *(uint16_t*)(cpu->esi + 2u) = cpu->eax & 0xFFFFu;
    cpu->eax = 1u;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->edi;
    g_sfera_effect_manager.active_effect_count += cpu->eax;
    g_sfera_effect_manager.active_resource_count = (uint64_t)(g_sfera_effect_manager.active_resource_count) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)&g_sfera_effect_manager.active_effects;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4978F0u)); sfera_sub_00425C00(cpu, LIFT_CODE_TOKEN_VA(0x4978F0u));
     if (cpu->ebx == cpu->edi) goto label_00097905;
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->ebx + 4u);
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->eax;
label_00097905:
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00497910(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = g_sfera_sound_runtime.effect_manager;
    if (cpu->ecx != 0u) goto label_0009791F;
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0009791F:
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497925u)); sfera_sub_00497770(cpu, LIFT_CODE_TOKEN_VA(0x497925u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00497930(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    ::new (reinterpret_cast<void*>(static_cast<uintptr_t>(cpu->ecx))) CSound();
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x60u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x64u) = cpu->ecx;
    cpu->ecx = 1u;
    *(uint32_t*)(cpu->esi + 0x58u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x70u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x74u) = cpu->eax;
    std::construct_at(reinterpret_cast<CSoundFX*>(cpu->esi));
    *(uint32_t*)(cpu->esi + 0x68u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x6Cu) = cpu->ecx;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00497970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_sound_runtime.manager;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00497980(LiftCpu* cpu, uint32_t stop_address) { double value_0;
 double x87_p0;
    cpu->eax = g_sfera_sound_runtime.manager;
    if (cpu->eax == 0u) goto label_00097997;
    x87_p0 = (double)*(float*)(cpu->eax + 8u);
    x87_p0 = (x87_p0) * (100.0);
     value_0 = x87_p0; sfera_sub_004EE940(cpu, stop_address, value_0); return;
label_00097997:
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004979A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = 0u;
    if (*(uint32_t*)(cpu->ecx) != cpu->edx) goto label_000979BD;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    *(uint32_t*)(cpu->eax + 0x70u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 0x74u) = cpu->edx;
    ++*(uint32_t*)(cpu->ecx + 0x10u);
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000979BD:
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 0x74u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->edx + 0x70u) = cpu->eax;
    ++*(uint32_t*)(cpu->ecx + 0x10u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004979E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    if (cpu->eax == 0u) goto label_000979EB;
    --cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->eax;
    label_000979EB:
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x74u);
    if (cpu->edx != 0u) goto label_00097A03;
    if (*(uint32_t*)(cpu->eax + 0x70u) != cpu->edx) goto label_00097A03;
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00097A03:
    if (*(uint32_t*)(cpu->ecx + 4u) != cpu->eax) goto label_00097A15;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    *(uint32_t*)(cpu->edx + 0x70u) = 0u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00097A15:
    if (*(uint32_t*)(cpu->ecx) != cpu->eax) goto label_00097A28;
    cpu->eax = *(uint32_t*)(cpu->eax + 0x70u);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->eax + 0x74u) = 0u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00097A28:
    cpu->ecx = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x70u);
    *(uint32_t*)(cpu->ecx + 0x70u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x70u);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x74u);
    *(uint32_t*)(cpu->ecx + 0x74u) = cpu->edx;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00497A40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx);
    if (cpu->esi != 0u) goto label_00097A4D;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00097A4D:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::_stricmp);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_method_address32(&CSound::IsSoundPlaying);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    label_00097A60:
    if (cpu->edi == 0u) goto label_00097A7A;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->edi, cpu->eax);

    if (cpu->eax != 0u) goto label_00097A7A;
    cpu->ecx = cpu->esi;
    cpu->eax = reinterpret_cast<uint32_t (__fastcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_method_address32(&CSound::IsSoundPlaying)))(cpu->ecx, cpu->edx);
    if (cpu->eax == 0u) goto label_00097A8A;
    label_00097A7A:
    cpu->esi = *(uint32_t*)(cpu->esi + 0x70u);
    if (cpu->esi != 0u) goto label_00097A60;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00097A8A:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00497AA0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)cpu->eax >= 0) goto label_00097AB6;
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    goto label_00097AC3;
    label_00097AB6:
    if ((int32_t)cpu->eax <= (int32_t)0x64u) goto label_00097AC3;
    *(uint32_t*)(cpu->esp + 0xCu) = 0x64u;
    label_00097AC3:
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu))));
    cpu->esi = *(uint32_t*)(cpu->edi);
    x87_v0 = (x87_v0) / (100.0);
    *(float*)(cpu->edi + 8u) = x87_v0; 
    if (cpu->esi == 0u) goto label_00097AF3;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_method_address32(&CSound::SetVolume);
    label_00097AE0:
    x87_v0 = (double)*(float*)(cpu->edi + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp) = x87_v0; 
    cpu->eax = reinterpret_cast<uint32_t (__fastcall*)(uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_method_address32(&CSound::SetVolume)))(cpu->ecx, cpu->edx, *(uint32_t*)(cpu->esp)); cpu->esp += 0x4u;
    cpu->esi = *(uint32_t*)(cpu->esi + 0x70u);
    if (cpu->esi != 0u) goto label_00097AE0;
    cpu->ebx = lift_pop32(cpu);
    label_00097AF3:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00497B00(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->eax = g_sfera_sound_runtime.manager;
    if (cpu->eax != 0u) goto label_00097B5E;
    lift_native_call(cpu, native_function_address32(&SI_GetInterface), LIFT_CODE_TOKEN_VA(0x497B09u));
    if (cpu->eax != 0u) goto label_00097B14;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00097B14:
    cpu->edx = 0x44u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497B23u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x497B23u));
    lift_push32(cpu, 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497B2Au)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x497B2Au));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_00097B57;
    x87_v0 = 1.0;
    *(uint32_t*)(cpu->eax) = 0u;
    *(float*)(cpu->eax + 8u) = x87_v0; 
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    *(uint32_t*)(cpu->eax + 0xCu) = 0u;
    *(uint32_t*)(cpu->eax + 0x10u) = 0u;
    g_sfera_sound_runtime.manager = cpu->eax;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00097B57:
    cpu->eax = 0u;
    g_sfera_sound_runtime.manager = cpu->eax;
    label_00097B5E:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00497B60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = g_sfera_sound_runtime.manager;
    if (cpu->ecx == 0u) goto label_00097B72;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x97B72u)); sfera_sub_00497AA0(cpu, LIFT_CODE_TOKEN_RVA(0x97B72u));
    label_00097B72:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00497B80(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    cpu->edi = cpu->ecx;
    if (*(uint32_t*)(cpu->edi + 0xCu) == 0u) goto label_00097C5F;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497BB9u)); sfera_sub_00497A40(cpu, LIFT_CODE_TOKEN_VA(0x497BB9u));
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_00097BD1;
    if (*(uint32_t*)(cpu->esi + 0x68u) == 0u) goto label_00097BD1;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esi + 0x58u) = cpu->eax;
    goto label_00097C85;
    label_00097BD1:
    lift_push32(cpu, (uintptr_t)"rb"); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x497BD7u));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_00097C5F;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x497BE5u));
    cpu->esp += 4u;
    cpu->edx = 0x16Bu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497BFDu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x497BFDu));
    lift_push32(cpu, 0x78u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497C04u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x497C04u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (cpu->eax == 0u) goto label_00097C22;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497C1Eu)); sfera_sub_00497930(cpu, LIFT_CODE_TOKEN_VA(0x497C1Eu));
    cpu->esi = cpu->eax;
    goto label_00097C24;
    label_00097C22:
    cpu->esi = 0u;
    label_00097C24:
    *(uint32_t*)(cpu->esp + 0x18u) = 0xFFFFFFFFu;
    if (cpu->esi == 0u) goto label_00097C5F;
    lift_push32(cpu, 8u); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_native_call(cpu, native_method_address32(&CSound::LoadSound), LIFT_CODE_TOKEN_VA(0x497C35u));
    if (cpu->eax != 0u) goto label_00097C76;
    cpu->edx = 0x171u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497C4Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x497C4Eu));
    cpu->ecx = cpu->esi;
    reinterpret_cast<CSound*>(static_cast<uintptr_t>(cpu->ecx))->~CSound();
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497C5Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x497C5Cu));
    cpu->esp += 4u;
    label_00097C5F:
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00097C76:
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497C7Eu)); sfera_sub_004979A0(cpu, LIFT_CODE_TOKEN_VA(0x497C7Eu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esi + 0x58u) = cpu->ecx;
    label_00097C85:
    x87_v0 = (double)*(float*)(cpu->edi + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp) = x87_v0; 
    lift_native_call(cpu, native_method_address32(&CSound::SetVolume), LIFT_CODE_TOKEN_VA(0x497C8Eu));
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00497CB0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    cpu->edi = cpu->ecx;
    if (*(uint32_t*)(cpu->edi + 0xCu) == 0u) goto label_00097D96;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497CE9u)); sfera_sub_00497A40(cpu, LIFT_CODE_TOKEN_VA(0x497CE9u));
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_00097D08;
    if (*(uint32_t*)(cpu->esi + 0x68u) == 0u) goto label_00097D08;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->esi + 0x58u) = cpu->eax;
    lift_push32(cpu, cpu->ecx);
    goto label_00097DC3;
    label_00097D08:
    lift_push32(cpu, (uintptr_t)"rb"); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x497D0Eu));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_00097D96;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x497D1Cu));
    cpu->esp += 4u;
    cpu->edx = 0x199u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497D34u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x497D34u));
    lift_push32(cpu, 0x78u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497D3Bu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x497D3Bu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (cpu->eax == 0u) goto label_00097D59;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497D55u)); sfera_sub_00497930(cpu, LIFT_CODE_TOKEN_VA(0x497D55u));
    cpu->esi = cpu->eax;
    goto label_00097D5B;
    label_00097D59:
    cpu->esi = 0u;
    label_00097D5B:
    *(uint32_t*)(cpu->esp + 0x18u) = 0xFFFFFFFFu;
    if (cpu->esi == 0u) goto label_00097D96;
    lift_push32(cpu, 0x29u); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_native_call(cpu, native_method_address32(&CSound::LoadSound), LIFT_CODE_TOKEN_VA(0x497D6Cu));
    if (cpu->eax != 0u) goto label_00097DAD;
    cpu->edx = 0x19Fu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497D85u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x497D85u));
    cpu->ecx = cpu->esi;
    reinterpret_cast<CSound*>(static_cast<uintptr_t>(cpu->ecx))->~CSound();
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497D93u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x497D93u));
    cpu->esp += 4u;
    label_00097D96:
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00097DAD:
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497DB5u)); sfera_sub_004979A0(cpu, LIFT_CODE_TOKEN_VA(0x497DB5u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->esi + 0x58u) = cpu->edx;
    lift_push32(cpu, cpu->eax);
    label_00097DC3:
    cpu->ecx = cpu->esi;
    lift_native_call(cpu, native_method_address32(&CSound::SetAllParameters), LIFT_CODE_TOKEN_VA(0x497DC5u));
    x87_v0 = (double)*(float*)(cpu->edi + 8u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(float*)(cpu->esp) = x87_v0; 
    lift_native_call(cpu, native_method_address32(&CSound::SetVolume), LIFT_CODE_TOKEN_VA(0x497DD4u));
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00497E00(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1]; bool sub_pred[1];
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ebp = *(uint32_t*)(cpu->edi);
    if (cpu->ebp == 0u) goto label_00097EB6;
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, cpu->esi);
    label_00097E16:
    cpu->esi = cpu->ebp;
    cpu->ebp = *(uint32_t*)(cpu->ebp + 0x70u);
    cpu->ecx = cpu->esi;
    lift_native_call(cpu, native_method_address32(&CSound::IsSoundPlaying), LIFT_CODE_TOKEN_VA(0x497E1Du));
    if (cpu->eax != 0u) goto label_00097E2E;
    *(uint32_t*)(cpu->esi + 0x6Cu) = 1u;
    label_00097E2E:
    if (*(uint32_t*)(cpu->esi + 0x6Cu) == 0u) goto label_00097EAC;
    if (*(uint32_t*)(cpu->esi + 0x68u) == 0u) goto label_00097EAC;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x58u);
    lift_test[0]=cpu->eax==0u;
    if (((cpu->eax)&0x80000000u)!=0u) goto label_00097EAC;
    if (!lift_test[0]) goto label_00097E52;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497E4Bu)); sfera_sub_004979E0(cpu, LIFT_CODE_TOKEN_VA(0x497E4Bu));
    cpu->edx = 0x1D4u;
    goto label_00097E95;
    label_00097E52:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x60u);
    cpu->eax &= *(uint32_t*)(cpu->esi + 0x64u);
    if (cpu->eax != 0xFFFFFFFFu) goto label_00097E6A;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497E62u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x497E62u));
    *(uint32_t*)(cpu->esi + 0x60u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x64u) = cpu->edx;
    goto label_00097EAC;
    label_00097E6A:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497E6Fu)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x497E6Fu));
    sub_pred[0] = cpu->eax < *(uint32_t*)(cpu->esi + 0x60u); cpu->eax -= *(uint32_t*)(cpu->esi + 0x60u);
    lift_push32(cpu, 0u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x64u) + (sub_pred[0]);
    lift_push32(cpu, 0x2710u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497E83u)); sfera_sub_004EEA40(cpu, LIFT_CODE_TOKEN_VA(0x497E83u));
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 0x58u)) goto label_00097EAC;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497E90u)); sfera_sub_004979E0(cpu, LIFT_CODE_TOKEN_VA(0x497E90u));
    cpu->edx = 0x1E3u;
    label_00097E95:
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497E9Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x497E9Fu));
    cpu->ecx = cpu->esi;
    reinterpret_cast<CSound*>(static_cast<uintptr_t>(cpu->ecx))->~CSound();
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497EA9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x497EA9u));
    cpu->esp += 4u;
    label_00097EAC:
    if (cpu->ebp != 0u) goto label_00097E16;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00097EB6:
    lift_native_call(cpu, native_function_address32(&SI_GetInterface), LIFT_CODE_TOKEN_VA(0x497EB6u));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if (cpu->eax == 0u) goto label_00097ECA;
    cpu->ecx = cpu->eax;
    cpu->esp += 4u; lift_native_call(cpu, (uint32_t)(native_method_address32(&CSoundInterface::UpdateSettings)), LIFT_CODE_TOKEN_VA(0x497EC4u)); cpu->eip = stop_address; return;
    label_00097ECA:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00497ED0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0, x87_v1, x87_v2, x87_v3;
    cpu->esp -= 0x58u;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&SI_GetInterface), LIFT_CODE_TOKEN_VA(0x497EDFu));
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_0009804D;
    cpu->ecx = cpu->esp + 0x40u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497EF8u)); sfera_sub_00455FD0(cpu, LIFT_CODE_TOKEN_VA(0x497EF8u));
    cpu->edx = cpu->esp + 0x10u;
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x497F05u)); sfera_sub_00468050(cpu, LIFT_CODE_TOKEN_VA(0x497F05u));
    *(float*)(cpu->esp + 4u) = (-((double)*(float*)(cpu->esp + 0x10u)));
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    x87_v0 = -x87_v0;
    *(float*)(cpu->esp + 8u) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    x87_v0 = -x87_v0;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xCu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    cpu->edx = cpu->esp + 0x4Cu;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_method_address32(&CSoundListener::GetOrientation), LIFT_CODE_TOKEN_VA(0x497F5Du));
    x87_v0 = (double)*(float*)(cpu->esp + 0x40u); x87_v1 = x87_v0;
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->esp + 0x1Cu)));
    *(float*)(cpu->esp + 4u) = x87_v1; 
    sub_pred[0] = *(uint32_t*)(cpu->esp + 4u) == 0u;
    x87_v1 = (double)*(float*)(cpu->esp + 0x44u); x87_v2 = x87_v1;
    x87_v2 = (x87_v2) - (((double)*(float*)(cpu->esp + 0x20u)));
    *(float*)(cpu->esp + 8u) = x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x48u); x87_v3 = x87_v2;
    x87_v3 = (x87_v3) - (((double)*(float*)(cpu->esp + 0x24u)));
    *(float*)(cpu->esp + 0xCu) = x87_v3; 
    if (!sub_pred[0]) goto label_00097FA2;
    if (*(uint32_t*)(cpu->esp + 8u) != 0u) goto label_00097FA2;
    if (*(uint32_t*)(cpu->esp + 0xCu) == 0u) goto label_00097FE2;
    label_00097FA2:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, 0u);
    cpu->esp -= 0xCu;
    *(float*)(cpu->esp + 8u) = x87_v2; 
    *(float*)(cpu->esp + 4u) = x87_v1; 
    *(float*)(cpu->esp) = x87_v0; 
    lift_native_call(cpu, native_method_address32(&CSoundListener::SetPosition), LIFT_CODE_TOKEN_VA(0x497FB5u));
    x87_v0 = (double)*(float*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, 0u);
    cpu->esp -= 0xCu;
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->esp + 0x18u);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x14u);
    lift_native_call(cpu, native_method_address32(&CSoundListener::SetVelocity), LIFT_CODE_TOKEN_VA(0x497FDAu));
    goto label_00097FE8;
    label_00097FE2:
    x87_v0 = x87_v2; 
    x87_v1 = x87_v1; 
    x87_v0 = x87_v0; 
    label_00097FE8:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x28u)) goto label_00098024;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    if (cpu->edx != *(uint32_t*)(cpu->esp + 0x2Cu)) goto label_00098024;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x3Cu);
    if (cpu->eax != *(uint32_t*)(cpu->esp + 0x30u)) goto label_00098024;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x4Cu);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x10u)) goto label_00098024;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x50u);
    if (cpu->edx != *(uint32_t*)(cpu->esp + 0x14u)) goto label_00098024;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x54u);
    if (cpu->eax == *(uint32_t*)(cpu->esp + 0x18u)) goto label_00098039;
    label_00098024:
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_method_address32(&CSoundListener::SetOrientation), LIFT_CODE_TOKEN_RVA(0x98033u));
    label_00098039:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49803Eu)); sfera_sub_00499810(cpu, LIFT_CODE_TOKEN_VA(0x49803Eu));
    cpu->ecx = g_sfera_sound_runtime.manager;
    if (cpu->ecx == 0u) goto label_0009804D;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9804Du)); sfera_sub_00497E00(cpu, LIFT_CODE_TOKEN_RVA(0x9804Du));
    label_0009804D:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x58u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00498060(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if (cpu->esi == 0u) goto label_00098094;
    lift_native_call(cpu, native_function_address32(&SI_GetInterface), LIFT_CODE_TOKEN_VA(0x49806Au));
    if (cpu->eax == 0u) goto label_00098094;
    cpu->ecx = g_sfera_sound_runtime.manager;
    lift_push32(cpu, 4u); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498082u)); sfera_sub_00497B80(cpu, LIFT_CODE_TOKEN_VA(0x498082u));
    if (cpu->eax == 0u) goto label_00098094;
    x87_v0 = 0.0;
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_v0; 
    cpu->ecx = cpu->eax;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x98094u)); sfera_sub_004958C0(cpu, LIFT_CODE_TOKEN_RVA(0x98094u));
    label_00098094:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004980A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebp);
    if (cpu->esi == 0u) goto label_000980DA;
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, cpu->edi);
    label_000980B3:
    cpu->edi = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->esi + 0x70u);
    cpu->edx = 0x139u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4980C7u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4980C7u));
    cpu->ecx = cpu->edi;
    reinterpret_cast<CSound*>(static_cast<uintptr_t>(cpu->ecx))->~CSound();
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4980D1u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4980D1u));
    cpu->esp += 4u;
    if (cpu->esi != 0u) goto label_000980B3;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000980DA:
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebp + 4u) = 0u;
    *(uint32_t*)(cpu->ebp) = 0u;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004980F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&SI_SetLogFile), LIFT_CODE_TOKEN_VA(0x4980F5u));
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, 0u); lift_push32(cpu, 0xAC44u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&SI_CreateInterface), LIFT_CODE_TOKEN_VA(0x49810Au));
    cpu->esp += 0x14u;
    if (cpu->eax == 0u) goto label_000981E1;
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498121u)); sfera_sub_00497B00(cpu, LIFT_CODE_TOKEN_VA(0x498121u));
    cpu->edi = cpu->eax;
    if (cpu->edi == 0u) goto label_00098160;
    lift_native_call(cpu, native_function_address32(&SI_GetInterface), LIFT_CODE_TOKEN_VA(0x498127u));
    if (cpu->eax != 0u) goto label_00098159;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->edi);
    if (cpu->esi == 0u) goto label_00098148;
    label_00098138:
    cpu->ecx = cpu->esi;
    reinterpret_cast<CSoundFX*>(cpu->ecx)->stop(cpu);
    cpu->esi = *(uint32_t*)(cpu->esi + 0x70u);
    if (cpu->esi != 0u) goto label_00098138;
    label_00098148:
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49814Fu)); sfera_sub_004980A0(cpu, LIFT_CODE_TOKEN_VA(0x49814Fu));
    *(uint32_t*)(cpu->edi + 0xCu) = 0u;
    cpu->esi = lift_pop32(cpu);
    goto label_00098160;
    label_00098159:
    *(uint32_t*)(cpu->edi + 0xCu) = 1u;
    label_00098160:
    cpu->eax = 0x64u;
    cpu->ecx = (uintptr_t)"config.cfg";
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 4u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49817Fu)); sfera_sub_004483B0(cpu, LIFT_CODE_TOKEN_VA(0x49817Fu));
    cpu->edx = cpu->esp + 0xCu;
    cpu->ecx = (uintptr_t)"SNDVOL";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49818Du)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x49818Du));
    cpu->edx = cpu->esp + 8u;
    cpu->ecx = (uintptr_t)"MUSVOL";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49819Bu)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x49819Bu));
    cpu->edx = cpu->esp + 4u;
    cpu->ecx = (uintptr_t)"HWMIX";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4981A9u)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x4981A9u));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint32_t*)(cpu->esp + 4u) != 0u);
    cpu->edx = cpu->ecx & 0xFFu;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&SI_SetHardwareMixing), LIFT_CODE_TOKEN_VA(0x4981B5u));
    cpu->esp += 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4981C3u)); sfera_sub_00497370(cpu, LIFT_CODE_TOKEN_VA(0x4981C3u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4981CCu)); sfera_sub_004982F0(cpu, LIFT_CODE_TOKEN_VA(0x4981CCu));
    cpu->ecx = g_sfera_sound_runtime.manager;
    cpu->edi = lift_pop32(cpu);
    if (cpu->ecx == 0u) goto label_000981E1;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x981E1u)); sfera_sub_00497AA0(cpu, LIFT_CODE_TOKEN_RVA(0x981E1u));
    label_000981E1:
    cpu->esp += 0xCu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004981F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4981F5u)); sfera_sub_00497470(cpu, LIFT_CODE_TOKEN_VA(0x4981F5u));
    if (g_sfera_sound_runtime.manager == 0u) goto label_00098233;
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0x59u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundManager.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49820Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x49820Eu));
    cpu->ecx = g_sfera_sound_runtime.manager;
    cpu->esi = cpu->ecx;
    if (cpu->ecx == 0u) goto label_00098228;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49821Fu)); sfera_sub_004980A0(cpu, LIFT_CODE_TOKEN_VA(0x49821Fu));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498225u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x498225u));
    cpu->esp += 4u;
    label_00098228:
    g_sfera_sound_runtime.manager = 0u;
    cpu->esi = lift_pop32(cpu);
    label_00098233:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498238u)); sfera_sub_004990F0(cpu, LIFT_CODE_TOKEN_VA(0x498238u));
    cpu->esp += 4u; lift_native_call(cpu, native_function_address32(&SI_Close), LIFT_CODE_TOKEN_VA(0x498238u)); cpu->eip = stop_address; return;
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x498233u), "function fell through without control transfer");
}
__declspec(noinline) void sfera_sub_00498240(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ListStack.h";
    if (*(uint32_t*)(cpu->esi) != cpu->edi) goto label_00098295;
    cpu->edx = cpu->edi + 0x69u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498257u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x498257u));
    lift_push32(cpu, 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49825Eu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x49825Eu));
    cpu->esp += 4u;
    if (cpu->eax == cpu->edi) goto label_00098280;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->edi;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edi;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00098280:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 4u) = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00098295:
    cpu->edx = 0x6Fu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49829Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x49829Fu));
    lift_push32(cpu, 0xCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4982A6u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4982A6u));
    cpu->esp += 4u;
    if (cpu->eax == cpu->edi) goto label_000982B7;
    *(uint32_t*)(cpu->eax) = cpu->edi;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edi;
    goto label_000982B9;
    label_000982B7:
    cpu->eax = 0u;
    label_000982B9:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 4u) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004982F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&SI_SetStreamVolume), LIFT_CODE_TOKEN_VA(0x4982F1u));
    cpu->esp += 4u;
    cpu->eax = 1u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00498310(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if (cpu->ecx == 0u) goto label_00098321;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 4u)) goto label_00098360;
    label_00098321:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    if (cpu->edx != 0u) goto label_0009833E;
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::malloc), LIFT_CODE_TOKEN_VA(0x498333u));
    cpu->esp += 4u;
    goto label_00098352;
    label_0009833E:
    cpu->eax += cpu->edx;
    cpu->edx = cpu->eax + (cpu->eax * 2u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::realloc), LIFT_CODE_TOKEN_VA(0x498349u));
    cpu->esp += 8u;
    label_00098352:
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    if (cpu->ecx == 0u) goto label_00098399;
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    *(uint32_t*)(cpu->esi + 4u) = (uint64_t)(*(uint32_t*)(cpu->esi + 4u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    label_00098360:
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    x87_v0 = (double)*(float*)(cpu->esp + 0xCu);
    cpu->edx = cpu->eax + (cpu->eax * 2u);
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->ecx + (cpu->edx * 4u)) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->ecx = cpu->eax + (cpu->eax * 2u);
    *(float*)(cpu->edx + (cpu->ecx * 4u) + 4u) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    *(uint32_t*)(cpu->ecx + (cpu->eax * 4u) + 8u) = cpu->edx;
    cpu->eax = 1u;
    *(uint32_t*)(cpu->esi + 8u) = (uint64_t)(*(uint32_t*)(cpu->esi + 8u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_00098399:
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004983A0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    if (*(uint32_t*)(cpu->ecx + 8u) == 0u) goto label_000983F2;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (cpu->eax == 0u) goto label_000983F2;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    x87_v0 = (double)*(float*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(float*)(cpu->edx) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    --*(uint32_t*)(cpu->ecx + 8u);
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    if (*(uint32_t*)(cpu->ecx + 8u) == 0u) goto label_000983EA;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    cpu->edx = cpu->eax + (cpu->eax * 2u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ecx + 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4983E1u));
    cpu->esp += 0xCu;
    label_000983EA:
    cpu->eax = 1u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_000983F2:
    cpu->eax = 0u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00498400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0x10u) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00498420(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint32_t*)(cpu->eax + (cpu->edi * 4u)) == 0u) goto label_0009844E;
    cpu->edx = 0x1B4u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498440u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x498440u));
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->edi * 4u));
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49844Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49844Bu));
    cpu->esp += 4u;
    label_0009844E:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->eax + (cpu->edi * 4u)) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->ecx + (cpu->edi * 4u)) = 0u;
    if (cpu->ebp == 0u) goto label_000984AC;
    cpu->edx = 0x1BAu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498478u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x498478u));
    cpu->eax = cpu->ebp;
    cpu->edx = 4u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498490u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x498490u));
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->ecx + (cpu->edi * 4u)) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx + (cpu->edi * 4u)) = cpu->ebp;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4984A4u));
    cpu->esp += 0x10u;
    label_000984AC:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004984C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    if (*(uint32_t*)(cpu->esi) == cpu->ebx) goto label_00098517;
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if (*(uint32_t*)(cpu->esi + 0x10u) <= cpu->ebx) goto label_000984FC;
    label_000984D2:
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (*(uint32_t*)(cpu->eax + (cpu->edi * 4u)) == cpu->ebx) goto label_000984F6;
    cpu->edx = 0x1CAu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4984E8u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4984E8u));
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->edi * 4u));
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4984F3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4984F3u));
    cpu->esp += 4u;
    label_000984F6:
    ++cpu->edi;
    if (cpu->edi < *(uint32_t*)(cpu->esi + 0x10u)) goto label_000984D2;
    label_000984FC:
    cpu->edx = 0x1CCu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49850Bu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x49850Bu));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498513u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x498513u));
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu);
    label_00098517:
    if (*(uint32_t*)(cpu->esi + 4u) == cpu->ebx) goto label_00098537;
    cpu->edx = 0x1CEu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49852Bu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x49852Bu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498534u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x498534u));
    cpu->esp += 4u;
    label_00098537:
    *(uint32_t*)(cpu->esi) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00498550(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    x87_v0 = 0.0;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax |= 0xFFFFFFFFu;
    *(float*)(cpu->esi + 0x20u) = x87_v0; 
    lift_push32(cpu, cpu->edi);
    cpu->edx = 0x1ECu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49858Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x49858Cu));
    lift_push32(cpu, 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498593u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x498593u));
    cpu->edi = cpu->eax;
    cpu->esp += 4u;
    if (cpu->edi == cpu->ebx) goto label_000985BC;
    lift_push32(cpu, 0x168u);
    lift_native_call(cpu, native_function_address32(&::malloc), LIFT_CODE_TOKEN_VA(0x4985A1u));
    *(uint32_t*)(cpu->edi) = cpu->eax;
    cpu->eax = 0x1Eu;
    cpu->esp += 4u;
    *(uint32_t*)(cpu->edi + 8u) = cpu->ebx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->eax;
    goto label_000985BE;
    label_000985BC:
    cpu->edi = 0u;
    label_000985BE:
    cpu->eax = 1u;
    *(uint32_t*)(cpu->esi) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0x44u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x3Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x4Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x48u) = cpu->ebx;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004985E0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 4u) == 0u;
    lift_push32(cpu, cpu->edi);
    if (sub_pred[0]) goto label_00098605;
    cpu->edx = 0x1FDu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4985F9u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4985F9u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498602u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x498602u));
    cpu->esp += 4u;
    label_00098605:
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->esi + 4u) = 0u;
    *(uint32_t*)(cpu->esi + 8u) = 0u;
    if (cpu->edi == 0u) goto label_0009865B;
    cpu->edx = 0x202u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49862Au)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x49862Au));
    cpu->eax = cpu->edi;
    cpu->edx = 8u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498642u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x498642u));
    cpu->ecx = cpu->edi * 8u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edi;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x498653u));
    cpu->esp += 0x10u;
    label_0009865B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) double sfera_sub_00498660(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2;
 double x87_p0;
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x28u);
    if (cpu->edi != 0u) goto label_0009868B;
    x87_p0 = 0.0;
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x20u;
     value_2 = x87_p0; cpu->esp += 8u; cpu->eip = stop_address; return value_2;
label_0009868B:
    cpu->eax = cpu->edi;
    cpu->edx = cpu->eax + 1u;
label_00098690:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00098690;
    cpu->eax -= cpu->edx;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->eax;
    if (cpu->eax == 0u) goto label_000986CF;
    cpu->ecx = 0u;
    if (*(uint8_t*)(cpu->edi) == 0x3Au) goto label_000986C6;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->esp + 0x18u;
    cpu->eax = cpu->edi;
    cpu->esi -= cpu->edi;
label_000986B0:
    if ((int32_t)cpu->ecx >= (int32_t)0xFu) goto label_000986C5;
    if ((int32_t)cpu->ecx >= (int32_t)cpu->ebp) goto label_000986C5;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->esi + cpu->eax) = cpu->edx & 0xFFu;
    ++cpu->eax;
    ++cpu->ecx;
    if (*(uint8_t*)(cpu->eax) != 0x3Au) goto label_000986B0;
label_000986C5:
    cpu->esi = lift_pop32(cpu);
label_000986C6:
    *(uint8_t*)(cpu->esp + cpu->ecx + 0x14u) = 0u;
    if ((int32_t)cpu->ecx < (int32_t)cpu->ebp) goto label_000986E4;
label_000986CF:
    x87_p0 = 0.0;
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x20u;
     value_0 = x87_p0; cpu->esp += 8u; cpu->eip = stop_address; return value_0;
label_000986E4:
    cpu->eax = cpu->edi + cpu->ecx + 1u;
    lift_push32(cpu, cpu->eax);
    x87_p0 = std::atof(reinterpret_cast<const char*>(static_cast<std::uintptr_t>(*(uint32_t*)(cpu->esp))));
    *(double*)(cpu->esp + 0x10u) = x87_p0;
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::atoi), LIFT_CODE_TOKEN_VA(0x4986F8u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    cpu->esp += 8u;
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    x87_p0 = (x87_p0) * (60.0);
    x87_p0 = (x87_p0) + (*(double*)(cpu->esp + 4u));
    *(float*)(cpu->esp) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp);
    cpu->esp += 0x20u;
     value_1 = x87_p0; cpu->esp += 8u; cpu->eip = stop_address; return value_1;
}
__declspec(noinline) void sfera_sub_00498730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ebx;
    if (cpu->edi == 0u) goto label_00098847;
    cpu->eax = cpu->edi;
    cpu->edx = cpu->eax + 1u;
    label_00098760:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00098760;
    if ((cpu->eax -= cpu->edx) == 0u) goto label_00098847;
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    cpu->eax = cpu->edi;
    if (*(uint8_t*)(cpu->edi) == 0u) goto label_0009878E;
    label_00098780:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0x2Cu) goto label_00098789;
    ++cpu->esi;
    label_00098789:
    if (*(uint8_t*)(cpu->eax) != 0u) goto label_00098780;
    label_0009878E:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ebp);
    ++cpu->esi;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4987A1u)); sfera_sub_00498420(cpu, LIFT_CODE_TOKEN_VA(0x4987A1u));
    cpu->ebp = 0u;
    if ((int32_t)cpu->esi <= 0) goto label_00098845;
    label_000987B0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    cpu->ecx = cpu->esp + 0x18u;
    if ((cpu->eax & 0xFFu) == 0x2Cu) goto label_000987CE;
    label_000987C0:
    if ((cpu->eax & 0xFFu) == 0u) goto label_000987CE;
    ++cpu->edi;
    *(uint8_t*)(cpu->ecx) = cpu->eax & 0xFFu;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    ++cpu->ecx;
    if ((cpu->eax & 0xFFu) != 0x2Cu) goto label_000987C0;
    label_000987CE:
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, (uintptr_t)"STP"); lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->ecx) = 0u;
    ++cpu->edi;
    cpu->ebx |= 0xFFFFFFFFu;
    cpu->esi = 0u;
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4987E1u));
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_000987F5;
    cpu->ebx = 0x40000u;
    goto label_00098828;
    label_000987F5:
    cpu->ecx = cpu->esp + 0x19u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::atoi), LIFT_CODE_TOKEN_VA(0x4987FAu));
    cpu->esi = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x1Cu));
    cpu->esp += 4u;
    if ((cpu->eax & 0xFFu) == 0x6Au) goto label_00098823;
    if ((cpu->eax & 0xFFu) == 0x70u) goto label_0009881C;
    if ((cpu->eax & 0xFFu) != 0x73u) goto label_00098828;
    cpu->ebx = 0x20000u;
    goto label_00098828;
    label_0009881C:
    cpu->ebx = 0x10000u;
    goto label_00098828;
    label_00098823:
    cpu->ebx = 0x80000u;
    label_00098828:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->edx = *(uint32_t*)(cpu->eax + (cpu->ecx * 4u));
    cpu->esi |= cpu->ebx;
    *(uint32_t*)(cpu->edx + (cpu->ebp * 4u)) = cpu->esi;
    ++cpu->ebp;
    if ((int32_t)cpu->ebp < (int32_t)*(uint32_t*)(cpu->esp + 0x10u)) goto label_000987B0;
    label_00098845:
    cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_00098847:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00498860(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x2Cu);
    if (cpu->ecx != 0u) goto label_0009886F;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0009886F:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx);
    if (cpu->esi == 0u) goto label_00098898;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->ebx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    if (cpu->edx >= *(uint32_t*)(cpu->eax + cpu->ebx)) goto label_00098898;
    cpu->eax = *(uint32_t*)(cpu->eax + cpu->esi);
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->edx * 4u));
    ++cpu->edx;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->edx;
    if (cpu->eax != 0xFFFFFFFFu) goto label_0009889F;
    label_00098898:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0009889F:
    cpu->ecx = cpu->eax;
    cpu->ecx &= 0xFFFF0000u;
    lift_push32(cpu, cpu->ebp);
    if (cpu->ecx != 0x80000u) goto label_00098925;
    cpu->ebx = native_function_address32(&::rand);
    label_000988B6:
    cpu->eax = cpu->eax & 0xFFFFu;
    --cpu->eax;
    if (cpu->eax >= *(uint32_t*)(cpu->edi + 0x28u)) goto label_0009891B;
    cpu->edx = cpu->eax + (cpu->eax * 4u);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x24u);
    cpu->esi = cpu->eax + (cpu->edx * 4u);
    *(uint32_t*)(cpu->edi + 0x2Cu) = cpu->esi;
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)()>(static_cast<uintptr_t>(native_function_address32(&::rand)))();
    { const uint32_t n = cpu->eax, d = (uint32_t)(*(uint32_t*)(cpu->esi + 0x10u)); cpu->eax = n / d; cpu->edx = n % d; }
    *(uint32_t*)(cpu->esi + 8u) = 0u;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x2Cu);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    if (cpu->eax == 0u) goto label_00098922;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xCu);
    cpu->esi = *(uint32_t*)(cpu->ecx + 8u);
    cpu->ebp = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    if (cpu->esi >= *(uint32_t*)(cpu->edx + cpu->ebp)) goto label_00098922;
    cpu->edx = *(uint32_t*)(cpu->edx + cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    ++cpu->esi;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->esi;
    if (cpu->eax == 0xFFFFFFFFu) goto label_00098922;
    cpu->ecx = cpu->eax;
    cpu->ecx &= 0xFFFF0000u;
    if (cpu->ecx == 0x80000u) goto label_000988B6;
    cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0009891B:
    cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00098922:
    cpu->eax |= 0xFFFFFFFFu;
    label_00098925:
    cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00498930(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4;
 bool sub_pred[1]; double x87_v0; double x87_p0;
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    cpu->ebx = cpu->ecx;
    if (cpu->esi != 0u) goto label_00098945;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
label_00098945:
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49894Du)); sfera_sub_00498860(cpu, LIFT_CODE_TOKEN_VA(0x49894Du));
    cpu->ebp = cpu->eax;
    if (cpu->ebp != 0xFFFFFFFFu) goto label_00098973;
    cpu->ecx = cpu->ebx;
    lift_native_call(cpu, native_method_address32(&CSoundStream::Stop), LIFT_CODE_TOKEN_VA(0x498956u));
    cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x3Cu) = 1u;
    *(uint32_t*)(cpu->esi + 0xCu) = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
label_00098973:
    cpu->eax &= 0xFFFF0000u;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x48u) == 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ebp & 0xFFFFu;
    if (sub_pred[0]) goto label_000989C7;
    x87_v0 = (double)-1.0f;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498996u)); sfera_sub_00498310(cpu, LIFT_CODE_TOKEN_VA(0x498996u));
    *(uint32_t*)(cpu->ebx + 0x5Cu) = 0xFFFFFFFFu;
    x87_v0 = (double)*(float*)(cpu->esi + 0x20u);
    x87_v0 = (x87_v0) - (1.0);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x14u);
    lift_native_call(cpu, native_method_address32(&CSoundStream::SetPlaySignal), LIFT_CODE_TOKEN_VA(0x4989B4u));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
label_000989C7:
    if (cpu->eax != 0x10000u) goto label_00098A48;
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->eax + 0xCu);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x989D5u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    x87_p0 = (double)*(float*)(cpu->ecx + (cpu->edi * 8u) + 0xFFFFFFFCu);
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = cpu->ecx + (cpu->edi * 8u) + 0xFFFFFFF8u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_p0; 
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->eax + 4u))));
     value_1 = x87_p0; if ((int32_t)cpu->edx >= 0) { value_0 = value_1; goto label_000989FB; }
    value_2 = (value_1) + (((double)4294967296.0f)); value_0 = value_2;
label_000989FB:
    value_3 = (value_0) * (((double)*(float*)(cpu->ecx)));
    cpu->eax = (uint32_t)(int32_t)std::trunc(value_3); 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = *(uint16_t*)(cpu->ecx + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498A15u)); sfera_sub_00498310(cpu, LIFT_CODE_TOKEN_VA(0x498A15u));
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    value_4 = (double)*(float*)(cpu->eax + (cpu->edi * 8u) + 0xFFFFFFF8u);
    cpu->ecx = cpu->ebx;
    *(float*)(cpu->esp) = value_4; 
     lift_native_call(cpu, native_method_address32(&CSoundStream::SeekToTime), LIFT_CODE_TOKEN_VA(0x498A22u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    x87_p0 = (double)*(float*)(cpu->ecx + (cpu->edi * 8u) + 0xFFFFFFFCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    *(float*)(cpu->esp) = x87_p0; 
    lift_native_call(cpu, native_method_address32(&CSoundStream::SetDecodeSignal), LIFT_CODE_TOKEN_VA(0x498A35u));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
label_00098A48:
    if (cpu->eax == 0x40000u) goto label_00098A5A;
    if (cpu->eax != 0x20000u) goto label_00098A75;
    if (cpu->edi == 0u) goto label_00098A75;
label_00098A5A:
    x87_v0 = (double)-1.0f;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(float*)(cpu->esp) = x87_v0; 
    lift_push32(cpu, 0xFFFFFFFFu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498A6Eu)); sfera_sub_00498310(cpu, LIFT_CODE_TOKEN_VA(0x498A6Eu));
    *(uint32_t*)(cpu->ebx + 0x5Cu) = 0xFFFFFFFFu;
label_00098A75:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00498AD0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0;
    goto label_00098AD0;
    label_00098A90:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    if (cpu->ecx == 0u) goto label_00098AC3;
    lift_native_call(cpu, native_method_address32(&CSoundStream::IsStreamPlaying), LIFT_CODE_TOKEN_VA(0x498A9Au));
    if (cpu->eax == 0u) goto label_00098AAD;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    lift_native_call(cpu, native_method_address32(&CSoundStream::Stop), LIFT_CODE_TOKEN_RVA(0x98AA7u));
    label_00098AAD:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->eax |= 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ecx + 0x5Cu) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x34u);
    *(uint32_t*)(cpu->edx + 0x68u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x40u) = 1u;
    label_00098AC3:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00098AD0:
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0xCu) != 0u) goto label_00098BDD;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x34u);
    if (cpu->eax == 0u) goto label_00098BDD;
    if (*(uint32_t*)(cpu->eax + 0x40u) != 0u) goto label_00098BDD;
    if (*(uint32_t*)(cpu->esi + 0x40u) != 0u) goto label_00098BDD;
    if (*(uint32_t*)(cpu->esi + 0x3Cu) != 0u) goto label_00098B61;
    if (*(uint32_t*)(cpu->esi + 0x48u) != 0u) goto label_00098B61;
    if (*(uint32_t*)(cpu->esi + 0x10u) == 0u) goto label_00098B51;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->eax &= *(uint32_t*)(cpu->esi + 0x1Cu);
    if (cpu->eax != 0xFFFFFFFFu) goto label_00098B26;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498B1Eu)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x498B1Eu));
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00098B26:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498B2Bu)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x498B2Bu));
    sub_pred[0] = cpu->eax < *(uint32_t*)(cpu->esi + 0x18u); cpu->eax -= *(uint32_t*)(cpu->esi + 0x18u);
    lift_push32(cpu, 0u);
    cpu->edx -= *(uint32_t*)(cpu->esi + 0x1Cu) + (sub_pred[0]);
    lift_push32(cpu, 0x2710u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498B3Fu)); sfera_sub_004EEA40(cpu, LIFT_CODE_TOKEN_VA(0x498B3Fu));
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esi + 0x10u)) goto label_00098BDD;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00098B51:
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498B57u)); sfera_sub_00498860(cpu, LIFT_CODE_TOKEN_VA(0x498B57u));
    cpu->ebx |= 0xFFFFFFFFu;
    if (cpu->eax != cpu->ebx) goto label_00098B67;
    cpu->ecx = cpu->esi;
    cpu->ebx = lift_pop32(cpu);
    label_00098B61:
    cpu->esi = lift_pop32(cpu);
    goto label_00098A90;
    label_00098B67:
    cpu->ecx = cpu->eax;
    cpu->ecx &= 0xFFFF0000u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->eax & 0xFFFFu;
    if (cpu->ecx != 0x10000u) goto label_00098BDF;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    lift_native_call(cpu, native_method_address32(&CSoundStream::IsStreamPlaying), LIFT_CODE_TOKEN_VA(0x498B7Eu));
    if (cpu->eax == 0u) goto label_00098B91;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    lift_native_call(cpu, native_method_address32(&CSoundStream::Stop), LIFT_CODE_TOKEN_RVA(0x98B8Bu));
    label_00098B91:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    x87_v0 = (double)*(float*)(cpu->ecx + (cpu->edi * 8u) + 0xFFFFFFFCu);
    cpu->eax = cpu->ecx + (cpu->edi * 8u) + 0xFFFFFFFCu;
    *(float*)(cpu->esi + 0x20u) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)*(float*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    *(float*)(cpu->esp) = x87_v0; 
    lift_native_call(cpu, native_method_address32(&CSoundStream::SetDecodeSignal), LIFT_CODE_TOKEN_VA(0x498BA8u));
    x87_v0 = (double)*(float*)(cpu->esi + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    *(float*)(cpu->esp) = x87_v0; 
    lift_native_call(cpu, native_method_address32(&CSoundStream::SetPlaySignal), LIFT_CODE_TOKEN_VA(0x498BB8u));
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    x87_v0 = (double)*(float*)(cpu->edx + (cpu->edi * 8u) + 0xFFFFFFF8u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    *(float*)(cpu->esp) = x87_v0; 
    lift_native_call(cpu, native_method_address32(&CSoundStream::PlayEx), LIFT_CODE_TOKEN_VA(0x498BCEu));
    *(uint32_t*)(cpu->esi + 0xCu) = 1u;
    label_00098BDB:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00098BDD:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00098BDF:
    if (cpu->ecx != 0x20000u) goto label_00098C16;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    lift_native_call(cpu, native_method_address32(&CSoundStream::IsStreamPlaying), LIFT_CODE_TOKEN_VA(0x498BEAu));
    if (cpu->eax == 0u) goto label_00098BFD;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    lift_native_call(cpu, native_method_address32(&CSoundStream::Stop), LIFT_CODE_TOKEN_RVA(0x98BF7u));
    label_00098BFD:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x34u);
    *(uint32_t*)(cpu->eax + 0x5Cu) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    *(uint32_t*)(cpu->ecx + 0x68u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x18u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00098C16:
    if (cpu->ecx != 0x40000u) goto label_00098BDB;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    goto label_00098A90;
}
__declspec(noinline) void sfera_sub_00498C30(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->edi);
    if (cpu->esi == 0u) goto label_00098CCF;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    label_00098C42:
    if (*(uint32_t*)(cpu->esi + 8u) == cpu->eax) goto label_00098C53;
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->esi != 0u) goto label_00098C42;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00098C53:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    if (cpu->ecx != 0u) goto label_00098C86;
    if (*(uint32_t*)(cpu->esi + 4u) != cpu->ecx) goto label_00098C86;
    cpu->edx = cpu->ecx + 0x7Du;
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ListStack.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498C6Bu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x498C6Bu));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498C71u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x498C71u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->edi + 4u) = 0u;
    *(uint32_t*)(cpu->edi) = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00098C86:
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->eax != 0u) goto label_00098C9C;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    cpu->edx = 0x86u;
    goto label_00098CBC;
    label_00098C9C:
    if (cpu->ecx != 0u) goto label_00098CAB;
    *(uint32_t*)(cpu->edi) = cpu->eax;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = 0x8Eu;
    goto label_00098CBC;
    label_00098CAB:
    cpu->edx = cpu->eax;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = 0x94u;
    label_00098CBC:
    cpu->ecx = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ListStack.h";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498CC6u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x498CC6u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498CCCu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x498CCCu));
    cpu->esp += 4u;
    label_00098CCF:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00498CE0(LiftCpu* cpu, uint32_t stop_address) {
    sfera_sub_004984C0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_00498CF0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    sub_pred[0] = *(uint32_t*)(cpu->esi) == 0u;
    lift_push32(cpu, cpu->edi);
    if (sub_pred[0]) goto label_00098CFE;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x98CFEu)); sfera_sub_004984C0(cpu, LIFT_CODE_TOKEN_RVA(0x98CFEu));
    label_00098CFE:
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->edi == 0u) goto label_00098D88;
    cpu->edx = 0x1A0u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498D19u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x498D19u));
    cpu->eax = cpu->edi;
    cpu->edx = 4u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498D31u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x498D31u));
    cpu->esp += 4u;
    cpu->edx = 0x1A1u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    *(uint32_t*)(cpu->esi) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498D45u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x498D45u));
    cpu->eax = cpu->edi;
    cpu->edx = 4u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498D5Du)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x498D5Du));
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->esp += 4u;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (cpu->edi == 0u) goto label_00098D88;
    label_00098D70:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->ecx + (cpu->eax * 4u)) = 0u;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx + (cpu->eax * 4u)) = 0u;
    ++cpu->eax;
    if (cpu->eax < cpu->edi) goto label_00098D70;
    label_00098D88:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00498D90(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6;
 double x87_p0, x87_p1, x87_p2;
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (cpu->esi != 0u) goto label_00098DA5;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
label_00098DA5:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498DBCu)); sfera_sub_004983A0(cpu, LIFT_CODE_TOKEN_VA(0x498DBCu));
    if (cpu->eax == 0u) goto label_00098EB4;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx + 0xCu);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x98DCBu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->eax;
    if (cpu->ecx == 0xFFFFFFFFu) goto label_00098E19;
    cpu->eax = *(uint32_t*)(cpu->edx + 4u);
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->edx + 4u))));
     value_1 = x87_p0; if ((int32_t)cpu->eax >= 0) { value_0 = value_1; goto label_00098DE8; }
    value_2 = (value_1) + (((double)4294967296.0f)); value_0 = value_2;
label_00098DE8:
    value_3 = (value_0) * (((double)*(float*)(cpu->esi + 0x20u)));
    cpu->edx = *(uint16_t*)(cpu->edx + 0xCu);
    *(uint64_t*)(cpu->esp + 0x10u) = static_cast<int64_t>(std::trunc(value_3));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->edx);
    cpu->ecx -= cpu->eax;
    *(uint32_t*)(cpu->edi + 0x34u) = (uint64_t)(*(uint32_t*)(cpu->edi + 0x34u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u);
label_00098E19:
    x87_p0 = (double)*(float*)(cpu->esp + 0x1Cu); x87_p1 = x87_p0;
    x87_p2 = (double)-1.0f;
     value_4 = x87_p2; value_5 = x87_p1; value_6 = x87_p0; if ((value_4)==(value_5)) goto label_00098E3F;
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esi + 0x20u) = value_6;
    cpu->ecx = cpu->edi;
    *(float*)(cpu->esp) = value_6; 
     lift_native_call(cpu, native_method_address32(&CSoundStream::SetPlaySignal), LIFT_CODE_TOKEN_VA(0x498E37u));
    goto label_00098E48;
label_00098E3F:
    *(uint32_t*)(cpu->edi + 0x68u) = 0xFFFFFFFFu;
label_00098E48:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = cpu->ebx;
    cpu->eax &= 0xFFFF0000u;
    if (cpu->eax == 0x40000u) goto label_00098E96;
    if (*(uint32_t*)(cpu->esi + 0x48u) != 0u) goto label_00098E96;
    if (cpu->eax != 0x20000u) goto label_00098EBB;
    cpu->ecx = cpu->edi;
    lift_native_call(cpu, native_method_address32(&CSoundStream::Stop), LIFT_CODE_TOKEN_VA(0x498E69u));
    cpu->eax = cpu->ebx & 0xFFFFu;
    cpu->ebx = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x18u) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0x1Cu) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi + 0xCu) = 0u;
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
label_00098E96:
    cpu->ecx = cpu->edi;
    lift_native_call(cpu, native_method_address32(&CSoundStream::Stop), LIFT_CODE_TOKEN_VA(0x498E98u));
    cpu->ebx = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x3Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0xCu) = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
label_00098EB4:
    *(uint32_t*)(cpu->edi + 0x68u) = 0xFFFFFFFFu;
label_00098EBB:
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00498ED0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    if (*(uint32_t*)(cpu->esi + 0x24u) == cpu->ebx) goto label_00098F61;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    if (cpu->eax >= *(uint32_t*)(cpu->esi + 0x28u)) goto label_00098F61;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x38u);
    if (cpu->eax == cpu->ebx) goto label_00098F61;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->ebx;
    if (*(uint32_t*)(cpu->esi + 0x34u) != cpu->ebx) goto label_00098F09;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&SI_StreamCreateFile), LIFT_CODE_TOKEN_VA(0x498EF9u));
    cpu->esp += 8u;
    if (cpu->eax == cpu->ebx) goto label_00098F64;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->eax;
    label_00098F09:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x34u);
    *(uint32_t*)(cpu->eax + 0x54u) = LIFT_CALLBACK(sfera_sub_00498930);
    *(uint32_t*)(cpu->eax + 0x58u) = cpu->esi;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x34u);
    *(uint32_t*)(cpu->eax + 0x60u) = LIFT_CALLBACK(sfera_sub_00498D90);
    *(uint32_t*)(cpu->eax + 0x64u) = cpu->esi;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esi + 0x44u))));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->edi);
    *(float*)(cpu->ecx + 0x6Cu) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->edx = cpu->eax + (cpu->eax * 4u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->edi = cpu->eax + (cpu->edx * 4u);
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->edi;
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x498F3Fu));
    { const uint32_t n = cpu->eax, d = (uint32_t)(*(uint32_t*)(cpu->edi + 0x10u)); cpu->eax = n / d; cpu->edx = n % d; }
    *(uint32_t*)(cpu->edi + 8u) = cpu->ebx;
    cpu->eax = 1u;
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->ebx;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x40u) = cpu->ebx;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00098F61:
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->ebx;
    label_00098F64:
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00498F70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    if (cpu->eax == cpu->ebx) goto label_00098F8B;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&SI_StreamFree), LIFT_CODE_TOKEN_VA(0x498F7Fu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->ebx;
    label_00098F8B:
    if (*(uint32_t*)(cpu->esi + 0x38u) == cpu->ebx) goto label_00098FAE;
    cpu->edx = 0x453u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498F9Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x498F9Fu));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x38u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498FA8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x498FA8u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->ebx;
    label_00098FAE:
    if (*(uint32_t*)(cpu->esi + 0x24u) == cpu->ebx) goto label_00098FE9;
    cpu->edx = 0x459u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498FC2u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x498FC2u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x24u);
    if (cpu->eax == cpu->ebx) goto label_00098FE6;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xFFFFFFFCu);
    cpu->edi = cpu->eax + 0xFFFFFFFCu;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00498CE0)); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x14u); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498FDDu)); sfera_sub_004EEB86(cpu, LIFT_CODE_TOKEN_VA(0x498FDDu));
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498FE3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x498FE3u));
    cpu->esp += 4u;
    label_00098FE6:
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->ebx;
    label_00098FE9:
    if (*(uint32_t*)(cpu->esi + 4u) == cpu->ebx) goto label_0009900C;
    cpu->edx = 0x45Fu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x498FFDu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x498FFDu));
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499006u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x499006u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebx;
    label_0009900C:
    if (*(uint32_t*)(cpu->esi) == cpu->ebx) goto label_00099045;
    cpu->edx = 0x465u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49901Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x49901Fu));
    cpu->edi = *(uint32_t*)(cpu->esi);
    if (cpu->edi == cpu->ebx) goto label_00099043;
    cpu->eax = *(uint32_t*)(cpu->edi);
    if (cpu->eax == cpu->ebx) goto label_0009903A;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::free), LIFT_CODE_TOKEN_VA(0x49902Cu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->edi) = cpu->ebx;
    *(uint32_t*)(cpu->edi + 4u) = cpu->ebx;
    label_0009903A:
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499040u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x499040u));
    cpu->esp += 4u;
    label_00099043:
    *(uint32_t*)(cpu->esi) = cpu->ebx;
    label_00099045:
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0x3Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x40u) = 1u;
    *(uint32_t*)(cpu->esi + 0x30u) = 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00499070(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->esi != 0u) goto label_0009907B;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0009907B:
    if (*(uint32_t*)(cpu->esi + 0x40u) != 0u) goto label_000990B1;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    if (cpu->ecx == 0u) goto label_000990B1;
    lift_native_call(cpu, native_method_address32(&CSoundStream::IsStreamPlaying), LIFT_CODE_TOKEN_VA(0x499088u));
    if (cpu->eax == 0u) goto label_0009909B;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    lift_native_call(cpu, native_method_address32(&CSoundStream::Stop), LIFT_CODE_TOKEN_RVA(0x99095u));
    label_0009909B:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->eax |= 0xFFFFFFFFu;
    *(uint32_t*)(cpu->ecx + 0x5Cu) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x34u);
    *(uint32_t*)(cpu->edx + 0x68u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x40u) = 1u;
    label_000990B1:
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)&g_sfera_sound_runtime.tracks;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4990BCu)); sfera_sub_00498C30(cpu, LIFT_CODE_TOKEN_VA(0x4990BCu));
    cpu->edx = 0x97u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4990CBu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4990CBu));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4990D2u)); sfera_sub_00498F70(cpu, LIFT_CODE_TOKEN_VA(0x4990D2u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4990D8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4990D8u));
    cpu->esp += 4u;
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004990F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->edi);
    cpu->edi = g_sfera_sound_runtime.tracks.first;
    if (cpu->edi == 0u) goto label_00099162;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_method_address32(&CSoundStream::IsStreamPlaying);
    lift_push32(cpu, cpu->esi);
    cpu->ebx |= 0xFFFFFFFFu;
    label_00099107:
    cpu->esi = *(uint32_t*)(cpu->edi + 8u);
    if (*(uint32_t*)(cpu->esi + 0x40u) != 0u) goto label_00099139;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    if (cpu->ecx == 0u) goto label_00099139;
    cpu->eax = reinterpret_cast<uint32_t (__fastcall*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_method_address32(&CSoundStream::IsStreamPlaying)))(cpu->ecx, cpu->edx);
    if (cpu->eax == 0u) goto label_00099126;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    lift_native_call(cpu, native_method_address32(&CSoundStream::Stop), LIFT_CODE_TOKEN_RVA(0x99120u));
    label_00099126:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x34u);
    *(uint32_t*)(cpu->eax + 0x5Cu) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x34u);
    *(uint32_t*)(cpu->ecx + 0x68u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x40u) = 1u;
    label_00099139:
    cpu->edx = 0x118u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499148u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x499148u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49914Fu)); sfera_sub_00498F70(cpu, LIFT_CODE_TOKEN_VA(0x49914Fu));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499155u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x499155u));
    cpu->edi = *(uint32_t*)(cpu->edi + 4u);
    cpu->esp += 4u;
    if (cpu->edi != 0u) goto label_00099107;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00099162:
    cpu->ecx = 0u;
    cpu->edi = lift_pop32(cpu);
    if (g_sfera_sound_runtime.tracks.first == cpu->ecx) goto label_00099193;
    cpu->eax = g_sfera_sound_runtime.tracks.last;
    label_00099172:
    if (cpu->eax == cpu->ecx) goto label_00099189;
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uintptr_t)&g_sfera_sound_runtime.tracks;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499184u)); sfera_sub_00498C30(cpu, LIFT_CODE_TOKEN_VA(0x499184u));
    cpu->eax = g_sfera_sound_runtime.tracks.last;
    label_00099189:
    cpu->ecx = 0u;
    if (g_sfera_sound_runtime.tracks.first != cpu->ecx) goto label_00099172;
    label_00099193:
    g_sfera_sound_runtime.tracks.last = cpu->ecx;
    g_sfera_sound_runtime.tracks.first = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004991A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    cpu->ebp = cpu->ecx;
    cpu->edi = 0u;
    if (*(uint32_t*)(cpu->ebp + 0x24u) == cpu->edi) goto label_000991FF;
    cpu->edx = 0x20Du;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4991DBu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4991DBu));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x24u);
    if (cpu->eax == cpu->edi) goto label_000991FF;
    cpu->ecx = *(uint32_t*)(cpu->eax + 0xFFFFFFFCu);
    cpu->esi = cpu->eax + 0xFFFFFFFCu;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00498CE0)); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x14u); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4991F6u)); sfera_sub_004EEB86(cpu, LIFT_CODE_TOKEN_VA(0x4991F6u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4991FCu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4991FCu));
    cpu->esp += 4u;
    label_000991FF:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->ebp + 0x24u) = cpu->edi;
    *(uint32_t*)(cpu->ebp + 0x28u) = cpu->edi;
    if (cpu->esi == cpu->edi) goto label_0009926D;
    cpu->edx = 0x214u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49921Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x49921Cu));
    cpu->eax = cpu->esi;
    cpu->edx = 0x14u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    cpu->eax = 0u;
    cpu->ecx += 4u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->ecx < 4u);
    cpu->eax = 0u - (uint64_t)(cpu->eax);
    cpu->eax |= cpu->ecx;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499240u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x499240u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    if (cpu->eax == cpu->edi) goto label_00099267;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00498CE0)); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00498400)); lift_push32(cpu, cpu->esi);
    cpu->edi = cpu->eax + 4u;
    lift_push32(cpu, 0x14u); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x99267u)); sfera_sub_004EEBE9(cpu, LIFT_CODE_TOKEN_RVA(0x99267u));
    label_00099267:
    *(uint32_t*)(cpu->ebp + 0x24u) = cpu->edi;
    *(uint32_t*)(cpu->ebp + 0x28u) = cpu->esi;
    label_0009926D:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00499290(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x120u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x134u;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x144u);
    cpu->edi = cpu->ecx;
    cpu->edx = 0x344u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4992E3u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4992E3u));
    lift_push32(cpu, 0x420u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4992EDu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4992EDu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x13Cu) = 0u;
    if (cpu->eax == 0u) goto label_0009930E;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49930Au)); sfera_sub_00493BF0(cpu, LIFT_CODE_TOKEN_VA(0x49930Au));
    cpu->esi = cpu->eax;
    goto label_00099310;
label_0009930E:
    cpu->esi = 0u;
label_00099310:
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x140u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499323u)); sfera_sub_00494940(cpu, LIFT_CODE_TOKEN_VA(0x499323u));
    lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"soundtrack");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499338u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x499338u));
    if (cpu->eax == 0u) goto label_000996D6;
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"audio_file");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499351u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x499351u));
    if (cpu->eax == 0u) goto label_000996CF;
    cpu->edx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499367u)); sfera_sub_004944A0(cpu, LIFT_CODE_TOKEN_VA(0x499367u));
    if (cpu->eax == 0u) goto label_000996CF;
    cpu->edx = 0x34Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49937Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x49937Eu));
    cpu->eax = cpu->esp + 0x30u;
    cpu->edx = cpu->eax + 1u;
label_00099385:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00099385;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499395u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x499395u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->edi + 0x38u) = cpu->eax;
    cpu->ecx = cpu->esp + 0x30u;
    cpu->edx = cpu->eax;
label_000993A1:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_000993A1;
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"volume");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4993BCu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4993BCu));
    if (cpu->eax == 0u) goto label_000993D1;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4993C9u)); value_3 = sfera_sub_004942C0(cpu, LIFT_CODE_TOKEN_VA(0x4993C9u));
    cpu->eax = (uint32_t)(int32_t)std::trunc(value_3); 
    *(uint32_t*)(cpu->edi + 0x44u) = cpu->eax;
label_000993D1:
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"flags");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4993E2u)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x4993E2u));
    if (cpu->eax == 0u) goto label_00099428;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4993EDu)); sfera_sub_004947E0(cpu, LIFT_CODE_TOKEN_VA(0x4993EDu));
    cpu->ebp = cpu->eax;
    cpu->ebx = 0u;
    if ((int32_t)cpu->ebp <= 0) goto label_00099428;
label_000993F5:
    cpu->edx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499402u)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x499402u));
    if (cpu->eax == 0u) goto label_00099421;
    cpu->eax = cpu->esp + 0x30u;
    lift_push32(cpu, (uintptr_t)"ST_AUTOFREE"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x499410u));
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00099421;
    *(uint32_t*)(cpu->edi + 0x4Cu) = (uint64_t)(*(uint32_t*)(cpu->edi + 0x4Cu)) | (uint64_t)(1u);
label_00099421:
    cpu->ebx += 2u;
    if ((int32_t)cpu->ebx < (int32_t)cpu->ebp) goto label_000993F5;
label_00099428:
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"samples");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499440u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x499440u));
    if (cpu->eax == 0u) goto label_000996C8;
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    cpu->ebx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499456u)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x499456u));
    lift_push32(cpu, (uintptr_t)"sample");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499462u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x499462u));
    if (cpu->eax == 0u) goto label_0009947B;
label_00099466:
    lift_push32(cpu, (uintptr_t)"sample");
    cpu->ecx = cpu->esi;
    ++cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499473u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x499473u));
    if (cpu->eax != 0u) goto label_00099466;
    if (cpu->ebx != 0u) goto label_00099485;
label_0009947B:
    cpu->edx = 0x376u;
    goto label_000996DB;
label_00099485:
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49948Du)); sfera_sub_004985E0(cpu, LIFT_CODE_TOKEN_VA(0x49948Du));
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499499u)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x499499u));
    lift_push32(cpu, (uintptr_t)"sample");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4994A5u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x4994A5u));
    if (cpu->eax == 0u) goto label_00099526;
    cpu->ebx = cpu->esi + 0x10u;
label_000994B0:
    cpu->edx = cpu->esp + 0xD0u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d %s %s"); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esp + 0x40u) = 0u;
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4994D0u));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->esp += 0x14u;
    cpu->edx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4994E9u)); value_1 = sfera_sub_00498660(cpu, LIFT_CODE_TOKEN_VA(0x4994E9u));
    *(float*)(cpu->esp + 0x14u) = value_1; 
    cpu->eax = cpu->esp + 0xD0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
     lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4994FCu)); value_2 = sfera_sub_00498660(cpu, LIFT_CODE_TOKEN_VA(0x4994FCu));
    *(float*)(cpu->esp + 0x18u) = value_2; 
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    *(float*)(cpu->ecx + (cpu->ebp * 8u) + 0xFFFFFFF8u) = (double)*(float*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    value_0 = (double)*(float*)(cpu->esp + 0x18u);
    lift_push32(cpu, (uintptr_t)"sample");
    cpu->ecx = cpu->esi;
    *(float*)(cpu->edx + (cpu->ebp * 8u) + 0xFFFFFFFCu) = value_0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499522u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x499522u));
     if (cpu->eax != 0u) goto label_000994B0;
label_00099526:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49952Du)); sfera_sub_004945B0(cpu, LIFT_CODE_TOKEN_VA(0x49952Du));
    lift_push32(cpu, 1u);
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"patterns");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499545u)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x499545u));
    if (cpu->eax == 0u) goto label_000996C1;
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    cpu->ebx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49955Bu)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x49955Bu));
    lift_push32(cpu, (uintptr_t)"pattern");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499567u)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x499567u));
    if (cpu->eax == 0u) goto label_00099585;
label_00099570:
    lift_push32(cpu, (uintptr_t)"pattern");
    cpu->ecx = cpu->esi;
    ++cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49957Du)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x49957Du));
    if (cpu->eax != 0u) goto label_00099570;
    if (cpu->ebx != 0u) goto label_0009958F;
label_00099585:
    cpu->edx = 0x3A0u;
    goto label_000996DB;
label_0009958F:
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499597u)); sfera_sub_004991A0(cpu, LIFT_CODE_TOKEN_VA(0x499597u));
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4995A3u)); sfera_sub_00494550(cpu, LIFT_CODE_TOKEN_VA(0x4995A3u));
    lift_push32(cpu, (uintptr_t)"pattern");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4995AFu)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x4995AFu));
    if (cpu->eax == 0u) goto label_00099656;
label_000995B7:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4995BEu)); sfera_sub_004947E0(cpu, LIFT_CODE_TOKEN_VA(0x4995BEu));
    cpu->ebp = cpu->eax;
    if ((int32_t)cpu->ebp <= 0) goto label_00099642;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4995D1u)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x4995D1u));
    cpu->edx = *(uint32_t*)(cpu->edi + 0x24u);
    cpu->ecx = cpu->eax + (cpu->eax * 4u);
    cpu->ecx = cpu->edx + (cpu->ecx * 4u) + 0xFFFFFFECu;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    cpu->eax = 1u;
    if ((int32_t)cpu->ebp <= (int32_t)2u) goto label_000995F2;
    cpu->eax = cpu->ebp + 0xFFFFFFFFu;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->eax -= cpu->edx;
    cpu->eax = (int32_t)(cpu->eax) >> 1u;
    ++cpu->eax;
label_000995F2:
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4995F8u)); sfera_sub_00498CF0(cpu, LIFT_CODE_TOKEN_VA(0x4995F8u));
    cpu->ebx = 1u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if ((int32_t)cpu->ebp <= (int32_t)cpu->ebx) goto label_00099642;
label_00099610:
    cpu->eax = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49961Du)); sfera_sub_00494400(cpu, LIFT_CODE_TOKEN_VA(0x49961Du));
    if (cpu->eax == 0u) goto label_0009963B;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499637u)); sfera_sub_00498730(cpu, LIFT_CODE_TOKEN_VA(0x499637u));
    ++*(uint32_t*)(cpu->esp + 0x14u);
label_0009963B:
    cpu->ebx += 2u;
    if ((int32_t)cpu->ebx < (int32_t)cpu->ebp) goto label_00099610;
label_00099642:
    lift_push32(cpu, (uintptr_t)"pattern");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49964Eu)); sfera_sub_004945C0(cpu, LIFT_CODE_TOKEN_VA(0x49964Eu));
    if (cpu->eax != 0u) goto label_000995B7;
label_00099656:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49965Du)); sfera_sub_004945B0(cpu, LIFT_CODE_TOKEN_VA(0x49965Du));
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"start_pattern");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49966Eu)); sfera_sub_00494150(cpu, LIFT_CODE_TOKEN_VA(0x49966Eu));
    if (cpu->eax == 0u) goto label_00099681;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49967Bu)); sfera_sub_00494360(cpu, LIFT_CODE_TOKEN_VA(0x49967Bu));
    --cpu->eax;
    *(uint32_t*)(cpu->edi + 0x30u) = cpu->eax;
    goto label_00099688;
label_00099681:
    *(uint32_t*)(cpu->edi + 0x30u) = 0u;
label_00099688:
    cpu->edx = *(uint32_t*)(cpu->edi + 0x30u);
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    if (cpu->edx < *(uint32_t*)(cpu->edi + 0x28u)) goto label_0009969C;
    cpu->edx = 0x3D0u;
    goto label_000996E0;
label_0009969C:
    cpu->edx = 0x3E6u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4996A6u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4996A6u));
    if (cpu->esi == 0u) goto label_000996BA;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4996B1u)); sfera_sub_00493C00(cpu, LIFT_CODE_TOKEN_VA(0x4996B1u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4996B7u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4996B7u));
    cpu->esp += 4u;
label_000996BA:
    cpu->eax = 1u;
    goto label_000996FB;
label_000996C1:
    cpu->edx = 0x3D9u;
    goto label_000996DB;
label_000996C8:
    cpu->edx = 0x38Fu;
    goto label_000996DB;
label_000996CF:
    cpu->edx = 0x356u;
    goto label_000996DB;
label_000996D6:
    cpu->edx = 0x3E2u;
label_000996DB:
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
label_000996E0:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4996E5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4996E5u));
    if (cpu->esi == 0u) goto label_000996F9;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4996F0u)); sfera_sub_00493C00(cpu, LIFT_CODE_TOKEN_VA(0x4996F0u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4996F6u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4996F6u));
    cpu->esp += 4u;
label_000996F9:
    cpu->eax = 0u;
label_000996FB:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x12Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00499730(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x10u;
    cpu->edi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&SI_GetInterface), LIFT_CODE_TOKEN_VA(0x49975Eu));
    if (cpu->eax == 0u) goto label_000997D3;
    cpu->edx = 0x67u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499777u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x499777u));
    lift_push32(cpu, 0x50u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49977Eu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x49977Eu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    if (cpu->eax == 0u) goto label_0009979C;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499798u)); sfera_sub_00498550(cpu, LIFT_CODE_TOKEN_VA(0x499798u));
    cpu->esi = cpu->eax;
    goto label_0009979E;
    label_0009979C:
    cpu->esi = 0u;
    label_0009979E:
    *(uint32_t*)(cpu->esp + 0x18u) = 0xFFFFFFFFu;
    if (cpu->esi == 0u) goto label_000997D3;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4997B2u)); sfera_sub_00499290(cpu, LIFT_CODE_TOKEN_VA(0x4997B2u));
    if (cpu->eax != 0u) goto label_000997E7;
    cpu->edx = cpu->eax + 0x6Du;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4997C3u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4997C3u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4997CAu)); sfera_sub_00498F70(cpu, LIFT_CODE_TOKEN_VA(0x4997CAu));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4997D0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4997D0u));
    cpu->esp += 4u;
    label_000997D3:
    cpu->eax = 0u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000997E7:
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uintptr_t)&g_sfera_sound_runtime.tracks;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4997F2u)); sfera_sub_00498240(cpu, LIFT_CODE_TOKEN_VA(0x4997F2u));
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00499810(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_native_call(cpu, native_function_address32(&SI_GetInterface), LIFT_CODE_TOKEN_VA(0x499819u));
    if (cpu->eax == 0u) goto label_0009988F;
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_sound_runtime.tracks.first;
    if (cpu->esi == 0u) goto label_0009983F;
    label_00099830:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499838u)); sfera_sub_00498AD0(cpu, LIFT_CODE_TOKEN_VA(0x499838u));
    cpu->esi = *(uint32_t*)(cpu->esi + 4u);
    if (cpu->esi != 0u) goto label_00099830;
    label_0009983F:
    cpu->ecx = g_sfera_music_runtime.current_stream;
    cpu->esi = lift_pop32(cpu);
    if (cpu->ecx == 0u) goto label_00099889;
    if (*(uint32_t*)(cpu->ecx + 0x40u) == 0u) goto label_00099889;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499855u)); sfera_sub_00499070(cpu, LIFT_CODE_TOKEN_VA(0x499855u));
    sub_pred[0] = (uint8_t)(g_sfera_music_runtime.requested_path[0]) == 0u;
    g_sfera_music_runtime.current_stream = 0u;
    if (sub_pred[0]) goto label_00099889;
    cpu->ecx = (uintptr_t)g_sfera_music_runtime.requested_path;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499872u)); sfera_sub_00499730(cpu, LIFT_CODE_TOKEN_VA(0x499872u));
    g_sfera_music_runtime.current_stream = cpu->eax;
    if (cpu->eax == 0u) goto label_00099882;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x99882u)); sfera_sub_00498ED0(cpu, LIFT_CODE_TOKEN_RVA(0x99882u));
    label_00099882:
    g_sfera_music_runtime.requested_path[0] = 0u;
    label_00099889:
    cpu->eax = 1u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0009988F:
    cpu->eax = 0u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004998A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    if (cpu->eax != 0u) goto label_000998C2;
    cpu->eax = g_sfera_music_runtime.current_stream;
    g_sfera_music_runtime.requested_path[0] = cpu->ecx & 0xFFu;
    if (cpu->eax == 0u) goto label_000998C1;
    if (*(uint32_t*)(cpu->eax + 0x40u) != cpu->ecx) goto label_000998C1;
    label_000998BA:
    *(uint32_t*)(cpu->eax + 0x48u) = 1u;
    label_000998C1:
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_000998C2:
    cpu->ecx = *(uint32_t*)((uintptr_t)"Sounds\\Music\\");
    cpu->edx = *(uint32_t*)(((uintptr_t)"Sounds\\Music\\") + 4u);
    *(uint32_t*)((uintptr_t)&g_sfera_music_runtime.requested_path[0]) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(((uintptr_t)"Sounds\\Music\\") + 8u);
    *(uint32_t*)((uintptr_t)&g_sfera_music_runtime.requested_path[4]) = cpu->edx;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(((uintptr_t)"Sounds\\Music\\") + 0xCu));
    *(uint32_t*)((uintptr_t)&g_sfera_music_runtime.requested_path[8]) = cpu->ecx;
    *(uint16_t*)((uintptr_t)&g_sfera_music_runtime.requested_path[12]) = cpu->edx & 0xFFFFu;
    cpu->ecx = cpu->eax;
    label_000998F6:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000998F6;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = (uintptr_t)g_sfera_music_runtime.requested_path;
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_00099910:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_00099910;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->ecx = 0u;
    cpu->eax = (uintptr_t)g_sfera_music_runtime.requested_path;
    cpu->edi = lift_pop32(cpu);
    --cpu->eax;
    cpu->esi = lift_pop32(cpu);
    label_00099930:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00099930;
    cpu->ecx = *(uint32_t*)((uintptr_t)".sst");
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)".sst") + 4u));
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint8_t*)(cpu->eax + 4u) = cpu->edx & 0xFFu;
    cpu->eax = g_sfera_music_runtime.current_stream;
    if (cpu->eax == 0u) goto label_0009995C;
    if (*(uint32_t*)(cpu->eax + 0x40u) == 0u) goto label_000998BA;
    label_0009995C:
    cpu->ecx = (uintptr_t)g_sfera_music_runtime.requested_path;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499966u)); sfera_sub_00499730(cpu, LIFT_CODE_TOKEN_VA(0x499966u));
    g_sfera_music_runtime.current_stream = cpu->eax;
    if (cpu->eax == 0u) goto label_000998C1;
    cpu->ecx = cpu->eax;
    sfera_sub_00498ED0(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_00499980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = 0u;
    cpu->edx=0u;
    label_00099984:
    cpu->eax = cpu->edx;
    cpu->ecx >>= 1u;
    cpu->eax >>= 1u;
    if (((cpu->edx & 0xFFu)&1u)==0u) goto label_0009999A;
    cpu->eax ^= 0xEDB88320u;
    cpu->ecx^=0xEDB88320u;
    label_0009999A:
    cpu->ecx >>= 1u;
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_000999AF;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    cpu->ecx^=0xEDB88320u;
    goto label_000999B1;
    label_000999AF:
    cpu->eax >>= 1u;
    label_000999B1:
    cpu->ecx >>= 1u;
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_000999C6;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    cpu->ecx^=0xEDB88320u;
    goto label_000999C8;
    label_000999C6:
    cpu->eax >>= 1u;
    label_000999C8:
    cpu->ecx >>= 1u;
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_000999DD;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    cpu->ecx^=0xEDB88320u;
    goto label_000999DF;
    label_000999DD:
    cpu->eax >>= 1u;
    label_000999DF:
    cpu->ecx >>= 1u;
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_000999F4;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    cpu->ecx^=0xEDB88320u;
    goto label_000999F6;
    label_000999F4:
    cpu->eax >>= 1u;
    label_000999F6:
    cpu->ecx >>= 1u;
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_00099A0B;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    cpu->ecx^=0xEDB88320u;
    goto label_00099A0D;
    label_00099A0B:
    cpu->eax >>= 1u;
    label_00099A0D:
    cpu->ecx >>= 1u;
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_00099A22;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    cpu->ecx^=0xEDB88320u;
    goto label_00099A24;
    label_00099A22:
    cpu->eax >>= 1u;
    label_00099A24:
    cpu->ecx >>= 1u;
    if ((((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_00099A30;
    cpu->ecx ^= 0xEDB88320u;
    label_00099A30:
    cpu->eax = cpu->edx + 0xFFFFFF9Fu;
    *(uint16_t*)((cpu->edx * 2u) + ((uintptr_t)&g_sfera_texture_registry_runtime.hash_mix[0])) = cpu->ecx & 0xFFFFu;
    if (cpu->eax > 0x19u) goto label_00099A50;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)g_sfera_texture_registry_runtime.hash_mix[(uint8_t)(cpu->edx - 0x20u)] & 0xFFFFu);
    *(uint16_t*)((cpu->edx * 2u) + ((uintptr_t)&g_sfera_texture_registry_runtime.hash_mix[0])) = cpu->eax & 0xFFFFu;
    label_00099A50:
    ++cpu->edx;
    if ((int32_t)(cpu->edx) < (int32_t)(0x100u)) goto label_00099984;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00499A60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x1B8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = g_sfera_texture_registry_runtime.path_count;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    if ((int32_t)cpu->edi < (int32_t)0x1F4u) goto label_00099A9B;
    cpu->ecx = (uintptr_t)"scan_paths_recursive: MAX_PATH_NUM exceeded";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499A95u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x499A95u));
    cpu->edi = g_sfera_texture_registry_runtime.path_count;
    label_00099A9B:
    cpu->ecx = cpu->edi;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x64u);
    cpu->edx = cpu->ecx + ((uintptr_t)&g_sfera_texture_registry_runtime.paths[0][0]);
    cpu->edx -= cpu->esi;
    cpu->eax = cpu->esi;
    cpu->ebx = 0u;
    label_00099AB0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_00099AB0;
    ++cpu->edi;
    cpu->edx = cpu->esp + 0x15Cu;
    g_sfera_texture_registry_runtime.path_count = cpu->edi;
    cpu->eax = cpu->esi;
    cpu->edx -= cpu->esi;
    label_00099AD0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_00099AD0;
    cpu->eax = cpu->esp + 0x15Cu;
    --cpu->eax;
    label_00099AE2:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_00099AE2;
    cpu->edx = *(uint32_t*)((uintptr_t)"*.dds");
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)(((uintptr_t)"*.dds") + 4u));
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = cpu->esp + 0x14u;
    *(uint16_t*)(cpu->eax + 4u) = cpu->ecx & 0xFFFFu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x160u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_findfirst64i32), LIFT_CODE_TOKEN_VA(0x499B0Au));
    cpu->esp += 8u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    if (cpu->eax == 0xFFFFFFFFu) goto label_00099C6F;
    lift_push32(cpu, cpu->ebp);
    label_00099B21:
    cpu->esi = 0u;
    cpu->ebp = 0u;
    if (*(uint8_t*)(cpu->esp + 0x3Cu) == 0x2Eu) goto label_00099B65;
    cpu->edi = cpu->esp + 0x3Cu;
    label_00099B30:
    if (cpu->esi != 0x1Eu) goto label_00099B3F;
    cpu->ecx = (uintptr_t)"too long texture name";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x99B3Fu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x99B3Fu));
    label_00099B3F:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi));
    cpu->ecx = cpu->eax & 0xFFu;
    cpu->ebp = (cpu->ebp & 0xFFFF0000u) | (((uint16_t)((cpu->ebp & 0xFFFFu)) >> 1u));
    cpu->ebp = (cpu->ebp & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->ebp & 0xFFFFu)) + (uint64_t)(*(uint16_t*)((cpu->ecx * 2u) + ((uintptr_t)&g_sfera_texture_registry_runtime.hash_mix[0]))) + (uint64_t)(0u))) & 0xFFFFu);
    *(uint8_t*)(cpu->esp + cpu->esi + 0x140u) = cpu->eax & 0xFFu;
    ++cpu->esi;
    cpu->edi = cpu->esp + cpu->esi + 0x3Cu;
    cpu->ebp = cpu->ebp & 0xFFFFu;
    if (*(uint8_t*)(cpu->esp + cpu->esi + 0x3Cu) != 0x2Eu) goto label_00099B30;
    label_00099B65:
    *(uint8_t*)(cpu->esp + cpu->esi + 0x140u) = cpu->ebx & 0xFFu;
    cpu->esi = g_sfera_texture_registry_runtime.batch_count;
    cpu->esi <<= 6u;
    cpu->esi += g_sfera_texture_registry_runtime.batch_records;
    lift_push32(cpu, 0x40u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x499B7Fu));
    cpu->eax = cpu->esp + 0x14Cu;
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    cpu->esp += 0xCu;
    cpu->edx -= cpu->ecx;
    label_00099B94:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_00099B94;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esi + 0x24u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x3Cu) = cpu->ebx;
    cpu->edx = g_sfera_texture_registry_runtime.batch_count;
    cpu->edx += g_sfera_texture_registry_runtime.texture_count;
    cpu->eax = cpu->ebp & 0xFFFFu;
    cpu->ecx = *(uint16_t*)((cpu->eax * 2u) + ((uintptr_t)&g_sfera_texture_registry_runtime.hash_heads[0]));
    *(uint16_t*)((cpu->eax * 2u) + ((uintptr_t)&g_sfera_texture_registry_runtime.hash_heads[0])) = cpu->edx & 0xFFFFu;
    *(uint16_t*)(cpu->esi + 0x28u) = cpu->ecx & 0xFFFFu;
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->ebx;
    cpu->eax = g_sfera_texture_registry_runtime.batch_count;
    ++cpu->eax;
    g_sfera_texture_registry_runtime.batch_count = cpu->eax;
    if (cpu->eax != 0xC8u) goto label_00099C45;
    cpu->edx = g_sfera_texture_registry_runtime.texture_count;
    cpu->ecx = g_sfera_texture_set_scalar_runtime.mode_01;
    lift_push32(cpu, 0x127u);
    cpu->edx += cpu->eax;
    lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\texturesset.cpp");
    cpu->edx <<= 6u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499C09u)); sfera_sub_004EBE80(cpu, LIFT_CODE_TOKEN_VA(0x499C09u));
    cpu->ecx = g_sfera_texture_registry_runtime.batch_count;
    cpu->edx = g_sfera_texture_registry_runtime.batch_records;
    cpu->ecx <<= 6u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_texture_registry_runtime.texture_count;
    cpu->ecx <<= 6u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->ecx);
    g_sfera_texture_set_scalar_runtime.mode_01 = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x499C2Bu));
    cpu->edx = g_sfera_texture_registry_runtime.batch_count;
    cpu->esp += 0xCu;
    g_sfera_texture_registry_runtime.texture_count = (uint64_t)(g_sfera_texture_registry_runtime.texture_count) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    g_sfera_texture_registry_runtime.batch_count = cpu->ebx;
    label_00099C45:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_findnext64i32), LIFT_CODE_TOKEN_VA(0x499C4Fu));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_00099B21;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x499C65u));
    cpu->esp += 4u;
    cpu->ebp = lift_pop32(cpu);
    label_00099C6F:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1B8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00499C90(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499C95u)); sfera_sub_00499980(cpu, LIFT_CODE_TOKEN_VA(0x499C95u));
    lift_push32(cpu, 0x20000u); lift_push32(cpu, 0xFFu); lift_push32(cpu, (uintptr_t)&g_sfera_texture_registry_runtime.hash_heads[0]);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x499CA4u));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0x16Fu);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\texturesset.cpp";
    cpu->ecx = 0x3200u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499CC0u)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x499CC0u));
    g_sfera_texture_registry_runtime.batch_records = cpu->eax;
    g_sfera_texture_registry_runtime.initialized = 1u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00499CD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->esi;
    cpu->edx = cpu->eax + 1u;
    label_00099CD8:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00099CD8;
    cpu->eax -= cpu->edx;
    if (cpu->eax < 0x5Au) goto label_00099CF0;
    cpu->ecx = (uintptr_t)"add_texture_folder: MAX_TEX_PATH_LEN exceeded";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x99CF0u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x99CF0u));
    label_00099CF0:
    cpu->ecx = cpu->esi;
    g_sfera_texture_registry_runtime.batch_count = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499D01u)); sfera_sub_00499A60(cpu, LIFT_CODE_TOKEN_VA(0x499D01u));
    cpu->eax = g_sfera_texture_registry_runtime.batch_count;
    cpu->esi = lift_pop32(cpu);
    if (cpu->eax==0u) goto label_00099D61;
    cpu->edx = g_sfera_texture_registry_runtime.texture_count;
    cpu->ecx = g_sfera_texture_set_scalar_runtime.mode_01;
    lift_push32(cpu, 0x1B4u);
    cpu->edx = cpu->edx + cpu->eax;
    lift_push32(cpu, (uintptr_t)"..\\ShareClientSeverCode\\texturesset.cpp");
    cpu->edx <<= 6u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499D2Cu)); sfera_sub_004EBE80(cpu, LIFT_CODE_TOKEN_VA(0x499D2Cu));
    cpu->edx = g_sfera_texture_registry_runtime.batch_count;
    cpu->ecx = g_sfera_texture_registry_runtime.batch_records;
    cpu->edx <<= 6u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_texture_registry_runtime.texture_count;
    cpu->edx <<= 6u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx);
    g_sfera_texture_set_scalar_runtime.mode_01 = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x499D4Eu));
    cpu->eax = g_sfera_texture_registry_runtime.batch_count;
    cpu->esp += 0xCu;
    g_sfera_texture_registry_runtime.texture_count = (uint64_t)(g_sfera_texture_registry_runtime.texture_count) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    label_00099D61:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00499D70(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    sub_pred[0] = (uint32_t)((uint64_t)(g_sfera_texture_registry_runtime.initialized)) == 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    if (sub_pred[0]) goto label_00099E11;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebx));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00099E11;
    cpu->ecx=0u;
    cpu->edx = cpu->ebx;
    label_00099D91:
    cpu->eax = cpu->eax & 0xFFu;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (((uint16_t)((cpu->ecx & 0xFFFFu)) >> 1u));
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFFFu)) + (uint64_t)(*(uint16_t*)((cpu->eax * 2u) + ((uintptr_t)&g_sfera_texture_registry_runtime.hash_mix[0]))) + (uint64_t)(0u))) & 0xFFFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx + 1u));
    ++cpu->edx;
    cpu->ecx = cpu->ecx & 0xFFFFu;
    if ((cpu->eax & 0xFFu)!=0u) goto label_00099D91;
    cpu->edi = *(uint16_t*)((cpu->ecx * 2u) + ((uintptr_t)&g_sfera_texture_registry_runtime.hash_heads[0]));
    if (cpu->edi == 0xFFFFu) goto label_00099E11;
    cpu->edx = g_sfera_texture_set_scalar_runtime.mode_01;
    cpu->ebp = native_function_address32(&::_stricmp);
    cpu->esi = cpu->edi;
    cpu->esi <<= 6u;
    cpu->eax = cpu->esi + cpu->edx;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->eax, cpu->ebx);

    if (cpu->eax == 0u) goto label_00099E0A;
    label_00099DE0:
    cpu->ecx = g_sfera_texture_set_scalar_runtime.mode_01;
    cpu->eax = *(uint16_t*)(cpu->esi + cpu->ecx + 0x28u);
    cpu->edx = 0xFFFFu;
    if ((uint16_t)(cpu->eax) == (uint16_t)(cpu->edx)) goto label_00099E11;
    cpu->edi = cpu->eax;
    cpu->esi = cpu->edi;
    cpu->esi <<= 6u;
    cpu->eax = cpu->esi + cpu->ecx;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->eax, cpu->ebx);

    if (cpu->eax != 0u) goto label_00099DE0;
    label_00099E0A:
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00099E11:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00499E20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    if ((int32_t)cpu->ecx < 0) goto label_00099E33;
    if ((int32_t)(cpu->ecx) < (int32_t)((uint32_t)(g_sfera_texture_registry_runtime.texture_count))) goto label_00099E64;
    label_00099E33:
    lift_push32(cpu, cpu->ecx);
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, (uintptr_t)"preload_texture_from_memory: wrong textureID = %d"); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x14u) = (uintptr_t)"..\\ShareClientSeverCode\\texturesset.cpp";
    *(uint32_t*)(cpu->esp + 0x18u) = 0x219u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499E5Bu)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x499E5Bu));
    cpu->ecx = g_sfera_texture_registry_runtime.default_texture_id;
    cpu->esp += 0xCu;
    label_00099E64:
    cpu->ecx <<= 6u;
    cpu->ecx += g_sfera_texture_set_scalar_runtime.mode_01;
    cpu->edi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi) != 0x20534444u) goto label_00099ECD;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->edi + 0x2Cu) = 1u;
    if (((*(uint32_t*)(cpu->esi + 0x70u)) & (0x200u)) == 0u) goto label_00099EA8;
    cpu->edi += 0x24u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499EA0u)); sfera_sub_004D8F10(cpu, LIFT_CODE_TOKEN_VA(0x499EA0u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00099EA8:
    cpu->eax = cpu->edi + 0x24u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499EBDu)); sfera_sub_004D8ED0(cpu, LIFT_CODE_TOKEN_VA(0x499EBDu));
    if (*(uint32_t*)(cpu->esi + 0x54u) != 0x1545844u) goto label_00099ECD;
    *(uint32_t*)(cpu->edi + 0x2Cu) = 0u;
    label_00099ECD:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00499EE0(LiftCpu* cpu, uint32_t stop_address) {
    ++g_sfera_texture_registry_runtime.preload_request_count;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00499EF0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    cpu->eax = g_sfera_texture_set_scalar_runtime.state_01;
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_texture_set_scalar_runtime.state_03;
    lift_push32(cpu, cpu->edi);
    cpu->esi += cpu->ecx;
    cpu->ecx = g_sfera_texture_set_scalar_runtime.state_02;
    cpu->edx = cpu->eax;
    cpu->edi = cpu->ecx;
    cpu->ecx = (cpu->ecx << 3u) | (cpu->eax >> 29u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, 0u);
    cpu->edx += cpu->eax;
    lift_push32(cpu, 0xAu);
    cpu->edi += cpu->ecx + (cpu->edx < cpu->eax);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    g_sfera_texture_set_scalar_runtime.state_03 = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499F28u)); sfera_sub_004EEA40(cpu, LIFT_CODE_TOKEN_VA(0x499F28u));
    cpu->edi = cpu->eax;
    cpu->ecx = cpu->edx;
    cpu->eax = cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    sub_pred[0] = cpu->edx == cpu->ecx; sub_pred[1] = (int32_t)(cpu->edx) < (int32_t)(cpu->ecx);
    if ((int32_t)(cpu->edx) < (int32_t)(cpu->ecx)) goto label_00099F43;
    if ((!sub_pred[0]) && (!sub_pred[1])) goto label_00099F39;
    if (cpu->eax <= cpu->edi) goto label_00099F43;
    label_00099F39:
    g_sfera_texture_registry_runtime.stream_direction_flag = 1u;
    label_00099F43:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00499F50(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = g_sfera_texture_set_scalar_runtime.state_01;
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_texture_set_scalar_runtime.state_03;
    cpu->esi -= cpu->ecx;
    cpu->ecx = g_sfera_texture_set_scalar_runtime.state_02;
    cpu->ecx = (cpu->ecx << 3u) | (cpu->eax >> 29u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u);
    cpu->eax += cpu->eax;
    lift_push32(cpu, 0xAu);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    g_sfera_texture_set_scalar_runtime.state_03 = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499F80u)); sfera_sub_004EEA40(cpu, LIFT_CODE_TOKEN_VA(0x499F80u));
    cpu->edi = cpu->eax;
    cpu->ecx = cpu->edx;
    cpu->eax = cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    sub_pred[0] = (int32_t)(cpu->edx) < (int32_t)(cpu->ecx);
    if ((cpu->edx != cpu->ecx) && ((int32_t)(cpu->edx) >= (int32_t)(cpu->ecx))) goto label_00099F9B;
    if (sub_pred[0]) goto label_00099F91;
    if (cpu->eax >= cpu->edi) goto label_00099F9B;
    label_00099F91:
    g_sfera_texture_registry_runtime.stream_direction_flag = 0u;
    label_00099F9B:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00499FA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = cpu->esi;
    cpu->ebx = cpu->ecx;
    cpu->edx = cpu->eax + 1u;
    label_00099FB0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_00099FB0;
    cpu->eax -= cpu->edx;
    if ((int32_t)cpu->eax < (int32_t)0x200u) goto label_0009A00A;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, (uintptr_t)"SSTR::operator=: buffer overflow! - %s"); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x18u) = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\sstr.h";
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0x6Du;
    *(uint32_t*)(cpu->esp + 0x20u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x499FE9u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x499FE9u));
    std::memmove((void*)(cpu->ebx),(void*)(cpu->esi),511u); cpu->ecx = 0u;
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint8_t*)(cpu->ebx + 0x1FFu) = 0u;
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0009A00A:
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x49A00Eu));
    cpu->esp += 0xCu;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049A020(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    if ((int32_t)cpu->edx >= 0) goto label_0009A062;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, (uintptr_t)"SSTR::append: wrong count=%d"); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x10u) = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\sstr.h";
    *(uint32_t*)(cpu->esp + 0x14u) = 0xC0u;
    *(uint32_t*)(cpu->esp + 0x18u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A056u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x49A056u));
    cpu->esp += 0xCu;
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0009A062:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ebp;
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->eax + 1u;
    label_0009A070:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0009A070;
    cpu->eax -= cpu->esi;
    cpu->ecx = cpu->eax;
    if ((int32_t)cpu->edx >= (int32_t)cpu->ecx) goto label_0009A081;
    cpu->ecx = cpu->edx;
    label_0009A081:
    cpu->eax = cpu->ebx;
    cpu->esi = cpu->eax + 1u;
    label_0009A086:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0009A086;
    cpu->eax -= cpu->esi;
    cpu->edi = cpu->eax;
    cpu->esi = cpu->edi + cpu->ecx + 1u;
    if ((int32_t)cpu->esi <= (int32_t)0x200u) goto label_0009A0D3;
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, (uintptr_t)"SSTR::append: buffer overflow!"); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x18u) = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\sstr.h";
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0xCBu;
    *(uint32_t*)(cpu->esp + 0x20u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A0C4u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x49A0C4u));
    cpu->ecx = 0x1FFu;
    cpu->esp += 8u;
    cpu->ecx -= cpu->edi;
    cpu->esi = 0x200u;
    label_0009A0D3:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    cpu->edi += cpu->ebx;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x49A0D8u));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi + cpu->ebx + 0xFFFFFFFFu) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049A100(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = g_sfera_texture_registry_runtime.batch_records;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x176u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\texturesset.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A116u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x49A116u));
    cpu->ecx = (uintptr_t)"default";
    g_sfera_texture_registry_runtime.default_texture_id = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A12Au)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x49A12Au));
    cpu->esi = cpu->eax;
    if (cpu->esi != 0xFFFFFFFFu) goto label_0009A13B;
    cpu->ecx = (uintptr_t)"Texture 'default' not found";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9A13Bu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_RVA(0x9A13Bu));
    label_0009A13B:
    cpu->ecx = g_sfera_texture_registry_runtime.texture_count;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x17Fu);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\texturesset.cpp";
    g_sfera_texture_registry_runtime.default_texture_id = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A15Cu)); sfera_sub_004EBE60(cpu, LIFT_CODE_TOKEN_VA(0x49A15Cu));
    cpu->ecx = g_sfera_texture_registry_runtime.texture_count;
    g_sfera_texture_set_scalar_runtime.mode_02 = cpu->eax;
    if ((int32_t)cpu->ecx <= 0) goto label_0009A1B2;
    cpu->edx = 0u;
    cpu->ecx = cpu->edx + 1u;
    goto label_0009A177;
    label_0009A172:
    cpu->eax = g_sfera_texture_set_scalar_runtime.mode_02;
    label_0009A177:
    cpu->esi = cpu->ecx + 0xFFFFFFFEu;
    *(uint32_t*)(cpu->edx + cpu->eax) = cpu->esi;
    cpu->eax = g_sfera_texture_set_scalar_runtime.mode_02;
    *(uint32_t*)(cpu->edx + cpu->eax + 4u) = cpu->ecx;
    cpu->eax = g_sfera_texture_registry_runtime.texture_count;
    ++cpu->ecx;
    cpu->esi = cpu->ecx + 0xFFFFFFFFu;
    cpu->edx += 8u;
    if ((int32_t)cpu->esi < (int32_t)cpu->eax) goto label_0009A172;
    cpu->ecx = g_sfera_texture_set_scalar_runtime.mode_02;
    *(uint32_t*)(cpu->ecx + (cpu->eax * 8u) + 0xFFFFFFFCu) = 0xF4240u;
    cpu->edx = g_sfera_texture_registry_runtime.texture_count;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0009A1B2:
    *(uint32_t*)(cpu->eax + (cpu->ecx * 8u) + 0xFFFFFFFCu) = 0xF4240u;
    cpu->eax = g_sfera_texture_registry_runtime.texture_count;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049A1D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    if ((int32_t)g_sfera_texture_registry_runtime.texture_count <= (int32_t)cpu->ebx) goto label_0009A20B;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    (void)cpu;
    label_0009A1E0:
    cpu->eax = g_sfera_texture_set_scalar_runtime.mode_01;
    cpu->esi = cpu->edi + cpu->eax + 0x24u;
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax == 0u) goto label_0009A1FD;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x9A1F5u));
    *(uint32_t*)(cpu->esi) = 0u;
    label_0009A1FD:
    ++cpu->ebx;
    cpu->edi += 0x40u;
    if ((int32_t)cpu->ebx < (int32_t)g_sfera_texture_registry_runtime.texture_count) goto label_0009A1E0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_0009A20B:
    cpu->ecx = g_sfera_texture_set_scalar_runtime.mode_01;
    cpu->ebx = lift_pop32(cpu);
    if (cpu->ecx == 0u) goto label_0009A22F;
    lift_push32(cpu, 0x192u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\texturesset.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A225u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x49A225u));
    g_sfera_texture_set_scalar_runtime.mode_01 = 0u;
    label_0009A22F:
    cpu->ecx = g_sfera_texture_set_scalar_runtime.mode_02;
    if (cpu->ecx == 0u) goto label_0009A252;
    lift_push32(cpu, 0x193u);
    cpu->edx = (uintptr_t)"..\\ShareClientSeverCode\\texturesset.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A248u)); sfera_sub_004EB520(cpu, LIFT_CODE_TOKEN_VA(0x49A248u));
    g_sfera_texture_set_scalar_runtime.mode_02 = 0u;
    label_0009A252:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049A260(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x244u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x258u;
    cpu->ebp = cpu->ecx;
    cpu->eax = g_sfera_texture_registry_runtime.texture_count;
    cpu->edi = (uintptr_t)"..\\ShareClientSeverCode\\texturesset.cpp";
    if ((int32_t)cpu->ebp < 0) goto label_0009A2AF;
    if ((int32_t)(cpu->ebp) < (int32_t)(cpu->eax)) goto label_0009A2DD;
    label_0009A2AF:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, (uintptr_t)"preload_texture: wrong textureID = %d, texsNum = %d"); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x34u) = 0x24Au;
    *(uint32_t*)(cpu->esp + 0x38u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A2D4u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x49A2D4u));
    cpu->ebp = g_sfera_texture_registry_runtime.default_texture_id;
    cpu->esp += 0x10u;
    label_0009A2DD:
    cpu->ecx = g_sfera_texture_set_scalar_runtime.mode_01;
    cpu->edx = g_sfera_texture_set_scalar_runtime.record_default_38;
    cpu->eax = cpu->ebp;
    cpu->eax <<= 6u;
    sub_pred[0] = *(uint32_t*)(cpu->eax + cpu->ecx + 0x24u) == 0u;
    cpu->ebx = cpu->eax + cpu->ecx;
    *(uint32_t*)(cpu->ebx + 0x38u) = cpu->edx;
    cpu->ecx = g_sfera_texture_set_scalar_runtime.record_default_3c;
    *(uint32_t*)(cpu->ebx + 0x3Cu) = cpu->ecx;
    if (!sub_pred[0]) goto label_0009A462;
    cpu->edx = g_sfera_texture_set_scalar_runtime.mode_01;
    cpu->esi = cpu->eax + cpu->edx;
    *(uint8_t*)(cpu->esp + 0x54u) = 0u;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x64u);
    cpu->eax += ((uintptr_t)&g_sfera_texture_registry_runtime.paths[0][0]);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x58u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A32Bu)); sfera_sub_00499FA0(cpu, LIFT_CODE_TOKEN_VA(0x49A32Bu));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x5Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A33Au)); sfera_sub_0049A020(cpu, LIFT_CODE_TOKEN_VA(0x49A33Au));
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".dds");
    cpu->ecx = cpu->esp + 0x5Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A34Du)); sfera_sub_0049A020(cpu, LIFT_CODE_TOKEN_VA(0x49A34Du));
    cpu->ecx = cpu->esp + 0x54u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A35Bu)); sfera_sub_004EDA30(cpu, LIFT_CODE_TOKEN_VA(0x49A35Bu));
    cpu->eax = g_sfera_texture_set_scalar_runtime.mode_02;
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->ebp * 8u));
    cpu->edx = *(uint32_t*)(cpu->eax + (cpu->ebp * 8u) + 4u);
    *(uint32_t*)(cpu->esp + 0x260u) = 0u;
    if (cpu->ecx == 0xFFFFFFFFu) goto label_0009A382;
    *(uint32_t*)(cpu->eax + (cpu->ecx * 8u) + 4u) = cpu->edx;
    cpu->eax = g_sfera_texture_set_scalar_runtime.mode_02;
    goto label_0009A388;
    label_0009A382:
    g_sfera_texture_set_scalar_runtime.last_selector = cpu->edx;
    label_0009A388:
    if (cpu->edx == 0xF4240u) goto label_0009A398;
    *(uint32_t*)(cpu->eax + (cpu->edx * 8u)) = cpu->ecx;
    cpu->eax = g_sfera_texture_set_scalar_runtime.mode_02;
    label_0009A398:
    cpu->ecx = g_sfera_graphics_runtime.texture_runtime_id;
    if (cpu->ecx == 0xF4240u) goto label_0009A3B0;
    *(uint32_t*)(cpu->eax + (cpu->ecx * 8u)) = cpu->ebp;
    cpu->eax = g_sfera_texture_set_scalar_runtime.mode_02;
    goto label_0009A3B6;
    label_0009A3B0:
    label_0009A3B6:
    *(uint32_t*)(cpu->eax + (cpu->ebp * 8u)) = 0xFFFFFFFFu;
    cpu->edx = g_sfera_graphics_runtime.texture_runtime_id;
    cpu->eax = g_sfera_texture_set_scalar_runtime.mode_02;
    *(uint32_t*)(cpu->eax + (cpu->ebp * 8u) + 4u) = cpu->edx;
    cpu->ecx = cpu->esp + 0x2Cu;
    g_sfera_graphics_runtime.texture_runtime_id = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A3DBu)); sfera_sub_004ED7D0(cpu, LIFT_CODE_TOKEN_VA(0x49A3DBu));
    if ((cpu->eax & 0xFFu) != 0u) goto label_0009A42A;
    cpu->esp -= 0x200u;
    *(uint32_t*)(cpu->esp + 0x214u) = cpu->edi;
    std::memmove((void*)(cpu->esp),(void*)(cpu->esp + 0x254u),512u);
    cpu->ecx = cpu->esp + 0x214u;
    lift_push32(cpu, (uintptr_t)"File not found %s"); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x220u) = 0x265u;
    *(uint32_t*)(cpu->esp + 0x224u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A424u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x49A424u));
    cpu->esp += 0x208u;
    label_0009A42A:
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A433u)); sfera_sub_004ED7F0(cpu, LIFT_CODE_TOKEN_VA(0x49A433u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A43Du)); sfera_sub_004ED860(cpu, LIFT_CODE_TOKEN_VA(0x49A43Du));
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A446u)); sfera_sub_00499E20(cpu, LIFT_CODE_TOKEN_VA(0x49A446u));
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::UnmapViewOfFile), LIFT_CODE_TOKEN_VA(0x49A448u));
    cpu->ecx = cpu->esp + 0x2Cu;
    *(uint32_t*)(cpu->esp + 0x260u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9A462u)); sfera_sub_004ED8E0(cpu, LIFT_CODE_TOKEN_RVA(0x9A462u));
    label_0009A462:
    cpu->eax = cpu->ebx;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x250u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049A490(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A495u)); sfera_sub_0049A260(cpu, LIFT_CODE_TOKEN_VA(0x49A495u));
    cpu->eax = *(uint32_t*)(cpu->eax + 0x24u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049A4A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A4A5u)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x49A4A5u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A4ACu)); sfera_sub_0049A260(cpu, LIFT_CODE_TOKEN_VA(0x49A4ACu));
    cpu->eax = *(uint32_t*)(cpu->eax + 0x24u);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049A4B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A4B5u)); sfera_sub_0049A260(cpu, LIFT_CODE_TOKEN_VA(0x49A4B5u));
    cpu->eax = *(uint32_t*)(cpu->eax + 0x2Cu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049A4C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A4C5u)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x49A4C5u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A4CCu)); sfera_sub_0049A260(cpu, LIFT_CODE_TOKEN_VA(0x49A4CCu));
    cpu->eax = *(uint32_t*)(cpu->eax + 0x2Cu);
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049A4D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = cpu->esp;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::QueryPerformanceFrequency), LIFT_CODE_TOKEN_VA(0x49A4D7u));
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp);
    cpu->edx = 0u;
    g_sfera_high_resolution_clock_runtime.performance_frequency.low = cpu->ecx;
    g_sfera_high_resolution_clock_runtime.performance_frequency.high = cpu->eax;
    g_sfera_high_resolution_clock_runtime.frequency_shift = cpu->edx;
    if (cpu->eax!=0u) goto label_0009A503;
    if (cpu->ecx <= 0x1E8480u) goto label_0009A529;
    label_0009A503:
    cpu->ecx = (cpu->ecx >> 1u) | (cpu->eax << 31u);
    cpu->eax >>= 1u;
    ++cpu->edx;
    if (cpu->eax!=0u) goto label_0009A503;
    if (false) goto label_0009A518;
    if (cpu->ecx > 0x1E8480u) goto label_0009A503;
    label_0009A518:
    g_sfera_high_resolution_clock_runtime.performance_frequency.low = cpu->ecx;
    g_sfera_high_resolution_clock_runtime.performance_frequency.high = cpu->eax;
    g_sfera_high_resolution_clock_runtime.frequency_shift = cpu->edx;
    label_0009A529:
    cpu->ecx = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::QueryPerformanceCounter), LIFT_CODE_TOKEN_VA(0x49A52Du));
    cpu->edx = *(uint32_t*)(cpu->esp);
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    g_sfera_high_resolution_clock_runtime.counter_anchor.low = cpu->edx;
    g_sfera_high_resolution_clock_runtime.counter_anchor.high = cpu->eax;
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049A550(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[4];
    cpu->esp -= 8u;
    if ((uint32_t)(g_sfera_high_resolution_clock_runtime.initialized) != 0u) goto label_0009A56B;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A561u)); sfera_sub_0049A4D0(cpu, LIFT_CODE_TOKEN_VA(0x49A561u));
    g_sfera_high_resolution_clock_runtime.initialized = 1u;
    label_0009A56B:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::QueryPerformanceCounter), LIFT_CODE_TOKEN_VA(0x49A574u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = g_sfera_high_resolution_clock_runtime.counter_anchor.low;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebp = g_sfera_high_resolution_clock_runtime.counter_anchor.high;
    cpu->ecx = g_sfera_high_resolution_clock_runtime.frequency_shift;
    sub_pred[0] = cpu->eax < cpu->ebx; cpu->eax -= cpu->ebx;
    cpu->edx -= cpu->ebp + (sub_pred[0]);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A59Du)); sfera_sub_004EEE10(cpu, LIFT_CODE_TOKEN_VA(0x49A59Du));
    cpu->edi = g_sfera_high_resolution_clock_runtime.elapsed_counter.low;
    cpu->esi = g_sfera_high_resolution_clock_runtime.elapsed_counter.high;
    cpu->ecx = g_sfera_high_resolution_clock_runtime.frequency_shift;
    cpu->edi += cpu->eax;
    cpu->esi += cpu->edx + (cpu->edi < cpu->eax);
    g_sfera_high_resolution_clock_runtime.elapsed_counter.low = cpu->edi;
    g_sfera_high_resolution_clock_runtime.elapsed_counter.high = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A5C4u)); sfera_sub_004EEDF0(cpu, LIFT_CODE_TOKEN_VA(0x49A5C4u));
    cpu->ecx = g_sfera_high_resolution_clock_runtime.performance_frequency.high;
    lift_push32(cpu, 0u);
    cpu->ebx += cpu->eax;
    lift_push32(cpu, 0x3E8u);
    cpu->ebp += cpu->edx + (cpu->ebx < cpu->eax);
    cpu->edx = g_sfera_high_resolution_clock_runtime.performance_frequency.low;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    g_sfera_high_resolution_clock_runtime.counter_anchor.low = cpu->ebx;
    g_sfera_high_resolution_clock_runtime.counter_anchor.high = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A5EEu)); sfera_sub_004EED20(cpu, LIFT_CODE_TOKEN_VA(0x49A5EEu));
    cpu->ecx = cpu->edx;
    cpu->ebx = cpu->eax;
    sub_pred[3] = cpu->esi <= cpu->ecx;
    if (cpu->esi < cpu->ecx) goto label_0009A662;
    if (!sub_pred[3]) goto label_0009A5FC;
    if (cpu->edi <= cpu->ebx) goto label_0009A662;
    label_0009A5FC:
    cpu->ebx = g_sfera_high_resolution_clock_runtime.epoch_microseconds.high;
    label_0009A602:
    sub_pred[1] = cpu->edi < cpu->eax; cpu->edi -= cpu->eax;
    cpu->esi -= cpu->edx + (sub_pred[1]);
    g_sfera_high_resolution_clock_runtime.epoch_microseconds.low += 0x3B9ACA00u;
    cpu->ebx += (g_sfera_high_resolution_clock_runtime.epoch_microseconds.low < 0x3B9ACA00u);
    sub_pred[2] = cpu->esi < cpu->ecx;
    if (cpu->esi > cpu->ecx) goto label_0009A602;
    if (sub_pred[2]) goto label_0009A61D;
    if (cpu->edi > cpu->eax) goto label_0009A602;
    label_0009A61D:
    g_sfera_high_resolution_clock_runtime.elapsed_counter.low = cpu->edi;
    g_sfera_high_resolution_clock_runtime.elapsed_counter.high = cpu->esi;
    g_sfera_high_resolution_clock_runtime.epoch_microseconds.high = cpu->ebx;
    label_0009A62F:
    lift_push32(cpu, 0u); lift_push32(cpu, 0xF4240u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A63Du)); sfera_sub_004EED20(cpu, LIFT_CODE_TOKEN_VA(0x49A63Du));
    cpu->ecx = g_sfera_high_resolution_clock_runtime.performance_frequency.high;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_high_resolution_clock_runtime.performance_frequency.low;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A652u)); sfera_sub_004EED80(cpu, LIFT_CODE_TOKEN_VA(0x49A652u));
    cpu->eax += g_sfera_high_resolution_clock_runtime.epoch_microseconds.low;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->edx += cpu->ebx + (cpu->eax < (uint32_t)(g_sfera_high_resolution_clock_runtime.epoch_microseconds.low));
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0009A662:
    cpu->ebx = g_sfera_high_resolution_clock_runtime.epoch_microseconds.high;
    goto label_0009A62F;
}
__declspec(noinline) void sfera_sub_0049A670(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A675u)); sfera_sub_0049A550(cpu, LIFT_CODE_TOKEN_VA(0x49A675u));
    lift_push32(cpu, 0u); lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A680u)); sfera_sub_004EEA40(cpu, LIFT_CODE_TOKEN_VA(0x49A680u));
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049A690(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx |= 0xFFFFFFFFu;
    if (g_sfera_profiler_runtime.call_count[cpu->esi] == cpu->ecx) goto label_0009A6CB;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    if (g_sfera_profiler_runtime.active[cpu->esi] != (cpu->eax & 0xFFu)) goto label_0009A6B2;
    g_sfera_profiler_runtime.call_count[cpu->esi] = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0009A6B2:
    g_sfera_profiler_runtime.active[cpu->esi] = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A6BDu)); sfera_sub_0049A550(cpu, LIFT_CODE_TOKEN_VA(0x49A6BDu));
    g_sfera_profiler_runtime.start_time_us[cpu->esi].low = cpu->eax;
    g_sfera_profiler_runtime.start_time_us[cpu->esi].high = cpu->edx;
    label_0009A6CB:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049A6D0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax |= 0xFFFFFFFFu;
    if (g_sfera_profiler_runtime.call_count[cpu->esi] == cpu->eax) goto label_0009A722;
    if (g_sfera_profiler_runtime.active[cpu->esi] != 0u) goto label_0009A6F1;
    g_sfera_profiler_runtime.call_count[cpu->esi] = cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0009A6F1:
    g_sfera_profiler_runtime.active[cpu->esi] = UINT8_C(0);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A6FDu)); sfera_sub_0049A550(cpu, LIFT_CODE_TOKEN_VA(0x49A6FDu));
    g_sfera_profiler_runtime.report_clock_snapshot.low = cpu->eax;
    sub_pred[0] = cpu->eax < (uint32_t)((uint64_t)(g_sfera_profiler_runtime.start_time_us[cpu->esi].low)); cpu->eax -= (uint64_t)(g_sfera_profiler_runtime.start_time_us[cpu->esi].low);
    cpu->ecx = (uintptr_t)&g_sfera_profiler_runtime.accumulated_ticks[cpu->esi];
    g_sfera_profiler_runtime.report_clock_snapshot.high = cpu->edx;
    cpu->edx -= g_sfera_profiler_runtime.start_time_us[cpu->esi].high + (sub_pred[0]);
    *(uint32_t*)(cpu->ecx) += cpu->eax;
    *(uint32_t*)(cpu->ecx + 4u) += cpu->edx + (*(uint32_t*)(cpu->ecx) < cpu->eax);
    label_0009A722:
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049A730(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4;
 bool sub_pred[1]; double x87_p0, x87_p1, x87_p2;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFC0u;
    cpu->esp -= 0x34u;
    sub_pred[0] = (uint32_t)(g_sfera_profiler_runtime.frame_count) == 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if (sub_pred[0]) goto label_0009A883;
    if (g_sfera_profiler_runtime.frame_time_total == 0u) goto label_0009A883;
    lift_push32(cpu, (uintptr_t)"a"); lift_push32(cpu, (uintptr_t)"logs\\profile.txt");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x49A760u));
    cpu->ebx = native_function_address32(&::fprintf);
    cpu->edi = cpu->eax;
    lift_push32(cpu, (uintptr_t)"\n\nProfile results:\n"); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x9A774u));
    x87_p0 = (double)(((int32_t)(g_sfera_profiler_runtime.frame_time_total)));
    cpu->eax = g_sfera_profiler_runtime.frame_time_total;
    cpu->esp += 0x10u;
     value_1 = x87_p0; if ((int32_t)cpu->eax >= 0) { value_0 = value_1; goto label_0009A78E; }
    value_2 = (value_1) + (((double)4294967296.0f)); value_0 = value_2;
label_0009A78E:
    value_3 = (value_0) / ((double)(((int32_t)(g_sfera_profiler_runtime.frame_count))));
    *(float*)(cpu->esp + 0x34u) = value_3; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A79Du)); sfera_sub_0049A550(cpu, LIFT_CODE_TOKEN_VA(0x49A79Du));
    value_4 = (double)*(float*)(cpu->esp + 0x34u);
    g_sfera_profiler_runtime.report_clock_snapshot.low = cpu->eax;
    g_sfera_profiler_runtime.report_clock_snapshot.high = cpu->edx;
    *(uint64_t*)(cpu->esp + 0x38u) = static_cast<int64_t>(std::trunc(value_4));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    cpu->eax = g_sfera_profiler_runtime.report_clock_snapshot.low;
    { const uint32_t n = cpu->eax, d = (uint32_t)(cpu->ecx); cpu->eax = n / d; cpu->edx = n % d; }
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Average frame time = %d  (fps = %d)\n\n"); lift_push32(cpu, cpu->edi);
     lift_native_call(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x9A7DFu));
    cpu->esp += 0x10u;
    cpu->esi = 0u;
label_0009A7F0:
    cpu->eax = g_sfera_profiler_runtime.call_count[cpu->esi];
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->eax;
    if (cpu->eax == 0u) goto label_0009A86F;
    if (cpu->eax != 0xFFFFFFFFu) goto label_0009A812;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"N=%d,  ERROR\n"); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x9A80Bu));
    cpu->esp += 0xCu;
    goto label_0009A86F;
label_0009A812:
    x87_p0 = (double)(((int32_t)(g_sfera_profiler_runtime.frame_count)));
    cpu->esp -= 0x18u;
    *(float*)(cpu->esp + 0x50u) = x87_p0; 
    x87_p0 = (double)(((int64_t)(*(uint64_t*)((uintptr_t)&g_sfera_profiler_runtime.accumulated_ticks[cpu->esi]))));
    x87_p1 = (double)*(float*)(cpu->esp + 0x50u); x87_p2 = x87_p1;
    x87_p0 = x87_p0 / x87_p2; 
    std::swap(x87_p1, x87_p0);
    *(float*)(cpu->esp + 0x50u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 0x50u); x87_p2 = x87_p1;
    x87_p2 = (x87_p2) / (((double)*(float*)(cpu->esp + 0x4Cu)));
    x87_p2 = (x87_p2) * (100.0);
    *(float*)(cpu->esp + 0x50u) = x87_p2; 
    x87_p2 = (double)*(float*)(cpu->esp + 0x50u);
    *(double*)(cpu->esp + 0x10u) = x87_p2;
    *(double*)(cpu->esp + 8u) = x87_p1;
    x87_p0 = ((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x48u))))) / (x87_p0);
    *(float*)(cpu->esp + 0x50u) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x50u);
    *(double*)(cpu->esp) = x87_p0;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"N=%d,  ANoC = %5.2f,  AT = %7.1f,  AP = %5.2f\n"); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x9A86Au));
    cpu->esp += 0x24u;
label_0009A86F:
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)0x64u) goto label_0009A7F0;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x49A87Au));
    cpu->esp += 4u;
label_0009A883:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049A890(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx=0u;
    label_0009A892:
    cpu->eax = cpu->ecx;
    cpu->eax >>= 1u;
    if ((((cpu->ecx & 0xFFu)) & (1u)) == 0u) goto label_0009A8A0;
    cpu->eax ^= 0xEDB88320u;
    label_0009A8A0:
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_0009A8AD;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0009A8AF;
    label_0009A8AD:
    cpu->eax >>= 1u;
    label_0009A8AF:
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_0009A8BC;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0009A8BE;
    label_0009A8BC:
    cpu->eax >>= 1u;
    label_0009A8BE:
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_0009A8CB;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0009A8CD;
    label_0009A8CB:
    cpu->eax >>= 1u;
    label_0009A8CD:
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_0009A8DA;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0009A8DC;
    label_0009A8DA:
    cpu->eax >>= 1u;
    label_0009A8DC:
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_0009A8E9;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0009A8EB;
    label_0009A8E9:
    cpu->eax >>= 1u;
    label_0009A8EB:
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_0009A8F8;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0009A8FA;
    label_0009A8F8:
    cpu->eax >>= 1u;
    label_0009A8FA:
    if (((cpu->eax & 0xFFu)&1u)==0u) goto label_0009A907;
    cpu->eax >>= 1u;
    cpu->eax ^= 0xEDB88320u;
    goto label_0009A909;
    label_0009A907:
    cpu->eax >>= 1u;
    label_0009A909:
    g_sfera_crc32_runtime.table[cpu->ecx] = cpu->eax;
    ++cpu->ecx;
    if ((int32_t)(cpu->ecx) < (int32_t)(0x100u)) goto label_0009A892;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049A920(LiftCpu* cpu, uint32_t stop_address) {
    if (cpu->edx == 0u) goto label_0009A94F;
    cpu->eax = g_sfera_crc32_runtime.current;
    lift_push32(cpu, cpu->esi);
    label_0009A930:
    cpu->esi = (int8_t)(*(uint8_t*)(cpu->ecx));
    cpu->esi ^= cpu->eax;
    cpu->esi&=0xFFu;
    cpu->eax >>= 8u;
    cpu->eax ^= g_sfera_crc32_runtime.table[cpu->esi];
    ++cpu->ecx;
    --cpu->edx;
    g_sfera_crc32_runtime.current = cpu->eax;
    if (cpu->edx != 0u) goto label_0009A930;
    cpu->esi = lift_pop32(cpu);
    label_0009A94F:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049A950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    *(uint8_t*)(cpu->eax) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint8_t*)(cpu->eax + 1u) = 1u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 0x124u) = 1u;
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->eax + 0x434u) = cpu->ebx;
    cpu->esi = cpu->eax + 0x10u;
    *(uint32_t*)(cpu->eax + 0x638u) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 0x63Cu) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 0x640u) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 0x644u) = cpu->ebx;
    cpu->esi -= cpu->ecx;
    label_0009A997:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->esi + cpu->ecx) = cpu->edx & 0xFFu;
    ++cpu->ecx;
    if ((cpu->edx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0009A997;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049A9B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x638u);
    if ((int32_t)cpu->eax <= 0) goto label_0009A9F5;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x63Cu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A9D0u)); sfera_sub_004EED20(cpu, LIFT_CODE_TOKEN_VA(0x49A9D0u));
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x638u);
    cpu->edi = cpu->edx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49A9E4u)); sfera_sub_004EEA40(cpu, LIFT_CODE_TOKEN_VA(0x49A9E4u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x434u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0009A9F5:
    cpu->edx = *(uint32_t*)(cpu->esp + 8u);
    *(uint32_t*)(cpu->edx) = 0u;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x434u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049AA10(LiftCpu* cpu, uint32_t stop_address) { double x87_p0;
    bool lift_cmp[2];
    cpu->eax = 0x18D4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49AA1Au)); sfera_sub_004EEAF0(cpu, LIFT_CODE_TOKEN_VA(0x49AA1Au));
    cpu->eax = 0u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::_time64);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18E0u);
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0x128u) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0x22Cu) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0x330u) = cpu->eax;
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    { const int64_t lift_result = reinterpret_cast<int64_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_time64)))(*(uint32_t*)(cpu->esp)); cpu->eax = (uint32_t)lift_result; cpu->edx = (uint32_t)((uint64_t)lift_result >> 32u); }
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esp += 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49AA74u)); sfera_sub_0049A890(cpu, LIFT_CODE_TOKEN_VA(0x49AA74u));
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    { const int64_t lift_result = reinterpret_cast<int64_t (__cdecl*)(uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_time64)))(*(uint32_t*)(cpu->esp)); cpu->eax = (uint32_t)lift_result; cpu->edx = (uint32_t)((uint64_t)lift_result >> 32u); }
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    x87_p0 = ::_difftime64(static_cast<__time64_t>(*(uint64_t*)(cpu->esp)), static_cast<__time64_t>(*(uint64_t*)(cpu->esp + 8u)));
    lift_cmp[0]=x87_p0>(15.0);
    cpu->esp += 0x14u;
    if (lift_cmp[0]) goto label_0009B018;
    label_0009AAA1:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x128u);
    cpu->ecx = cpu->ebp + 0x128u;
    if (cpu->eax >= 0x40u) goto label_0009AAC1;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x120u);
    *(uint32_t*)(cpu->ebp + (cpu->eax * 4u) + 0x12Cu) = cpu->edx;
    ++*(uint32_t*)(cpu->ecx);
    label_0009AAC1:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x22Cu);
    cpu->ebx = cpu->ebp + 0x22Cu;
    if (cpu->eax >= 0x40u) goto label_0009AAE1;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x120u);
    *(uint32_t*)(cpu->ebp + (cpu->eax * 4u) + 0x230u) = cpu->edx;
    ++*(uint32_t*)(cpu->ebx);
    label_0009AAE1:
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->ebp + 0x330u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::select), LIFT_CODE_TOKEN_VA(0x49AAF1u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x434u);
    if (cpu->ecx != 1u) goto label_0009AB62;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x120u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::__WSAFDIsSet), LIFT_CODE_TOKEN_VA(0x49AB09u));
    if (cpu->eax == 0u) goto label_0009AB62;
    cpu->edx = cpu->ebp + 0x438u;
    cpu->eax = cpu->edx;
    cpu->esi = cpu->eax + 1u;
    label_0009AB20:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0009AB20;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, 0u);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x120u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::send), LIFT_CODE_TOKEN_VA(0x49AB35u));
    if (cpu->eax == 0u) goto label_0009B018;
    if (cpu->eax == 0xFFFFFFFFu) goto label_0009B018;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ebp + 0x434u) = 2u;
    goto label_0009AFE7;
    label_0009AB62:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x434u);
    if (cpu->ecx != 2u) goto label_0009AD45;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x120u);
    cpu->eax = cpu->ebp + 0x128u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::__WSAFDIsSet), LIFT_CODE_TOKEN_VA(0x49AB7Fu));
    if (cpu->eax == 0u) goto label_0009AD45;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x120u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x14u);
    cpu->eax = cpu->esp + 0x84u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::recv), LIFT_CODE_TOKEN_VA(0x49AB9Fu));
    if (cpu->eax == 0u) goto label_0009B018;
    if (cpu->eax == 0xFFFFFFFFu) goto label_0009B018;
    cpu->esi = native_function_address32(&::memmove);
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x80u;
    lift_push32(cpu, cpu->edx);
    cpu->ebx = cpu->ebp + 0x638u;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::memmove)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u), *(uint32_t*)(cpu->esp + 0x8u));
    lift_push32(cpu, 4u);
    cpu->eax = cpu->esp + 0x90u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->ecx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::memmove)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u), *(uint32_t*)(cpu->esp + 0x8u));
    lift_push32(cpu, 8u);
    cpu->edx = cpu->esp + 0xA0u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x58u;
    lift_push32(cpu, cpu->eax);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::memmove)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u), *(uint32_t*)(cpu->esp + 0x8u));
    cpu->esi = cpu->ebp + 0x438u;
    lift_push32(cpu, 0x5Cu); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_strrchr_address32(), LIFT_CODE_TOKEN_VA(0x49ABF9u));
    cpu->esp += 0x2Cu;
    if (cpu->eax != 0u) goto label_0009AC0A;
    cpu->eax = cpu->esi;
    goto label_0009AC0B;
    label_0009AC0A:
    ++cpu->eax;
    label_0009AC0B:
    cpu->ecx = *(uint32_t*)((uintptr_t)"inbox\\");
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(((uintptr_t)"inbox\\") + 4u));
    *(uint32_t*)(cpu->esp + 0xE0u) = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"inbox\\") + 6u));
    *(uint16_t*)(cpu->esp + 0xE4u) = cpu->edx & 0xFFFFu;
    *(uint8_t*)(cpu->esp + 0xE6u) = cpu->ecx & 0xFFu;
    cpu->edx = cpu->eax;
    label_0009AC36:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0009AC36;
    cpu->edi = cpu->esp + 0xE0u;
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_0009AC47:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_0009AC47;
    cpu->esi = cpu->edx;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax); cpu->esi += cpu->eax; cpu->edi += cpu->eax; cpu->ecx = 0u;
    cpu->eax = 0u;
    label_0009AC61:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + cpu->eax + 0xE0u));
    *(uint8_t*)(cpu->esp + cpu->eax + 0x4E0u) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0009AC61;
    cpu->eax = cpu->esp + 0x4E0u;
    --cpu->eax;
    label_0009AC80:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0009AC80;
    cpu->edx = *(uint32_t*)((uintptr_t)".crc");
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)".crc") + 4u));
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->edx = cpu->esp + 0x4E0u;
    lift_push32(cpu, (uintptr_t)"rb"); lift_push32(cpu, cpu->edx);
    *(uint8_t*)(cpu->eax + 4u) = cpu->ecx & 0xFFu;
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x49ACA6u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_0009AD24;
    cpu->edi = native_function_address32(&::fread);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u);
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, 4u); lift_push32(cpu, cpu->eax);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fread)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u), *(uint32_t*)(cpu->esp + 0x8u), *(uint32_t*)(cpu->esp + 0xCu));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u);
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, 4u); lift_push32(cpu, cpu->ecx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fread)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u), *(uint32_t*)(cpu->esp + 0x8u), *(uint32_t*)(cpu->esp + 0xCu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x49ACD4u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x48u);
    cpu->esp += 0x24u;
    if (cpu->edx != *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_0009AD13;
    cpu->eax = *(uint32_t*)(cpu->ebx);
    if (*(uint32_t*)(cpu->esp + 0x20u) != cpu->eax) goto label_0009AD13;
    cpu->ecx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0xE4u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_stat64i32), LIFT_CODE_TOKEN_VA(0x49ACFCu));
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_0009AD24;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x54u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    goto label_0009AD24;
    label_0009AD13:
    cpu->ecx = cpu->esp + 0x4E0u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x49AD1Bu));
    cpu->esp += 4u;
    label_0009AD24:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ebp + 0x63Cu) = cpu->edx;
    *(uint32_t*)(cpu->ebp + 0x434u) = 3u;
    goto label_0009AFE7;
    label_0009AD45:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x434u);
    if (cpu->eax != 3u) goto label_0009AE55;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x120u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::__WSAFDIsSet), LIFT_CODE_TOKEN_VA(0x49AD5Cu));
    if (cpu->eax == 0u) goto label_0009AE55;
    cpu->eax = 0u;
    lift_push32(cpu, 4u);
    cpu->edx = cpu->esp + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x78u) = cpu->eax;
    *(uint16_t*)(cpu->esp + 0x7Cu) = cpu->eax & 0xFFFFu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x7Bu;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x7Cu) = 0x415352u;
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x49AD88u));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x120u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0u); lift_push32(cpu, 7u);
    cpu->ecx = cpu->esp + 0x78u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::send), LIFT_CODE_TOKEN_VA(0x49ADA1u));
    if (cpu->eax == 0u) goto label_0009B018;
    if (cpu->eax == 0xFFFFFFFFu) goto label_0009B018;
    if (*(uint32_t*)(cpu->esp + 0x18u) != 0u) goto label_0009ADCD;
    lift_push32(cpu, (uintptr_t)"w+b");
    cpu->eax = cpu->esp + 0xE4u;
    lift_push32(cpu, cpu->eax);
    goto label_0009ADDA;
    label_0009ADCD:
    lift_push32(cpu, (uintptr_t)"a+b");
    cpu->ecx = cpu->esp + 0xE4u;
    lift_push32(cpu, cpu->ecx);
    label_0009ADDA:
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x49ADDAu));
    cpu->esp += 8u;
    *(uint32_t*)(cpu->ebp + 0x640u) = cpu->eax;
    if (cpu->eax == 0u) goto label_0009B018;
    if (*(uint32_t*)(cpu->esp + 0x18u) != 0u) goto label_0009AE3E;
    cpu->edx = cpu->esp + 0x4E0u;
    lift_push32(cpu, (uintptr_t)"wb"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x49AE05u));
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if (cpu->esi == 0u) goto label_0009AE3E;
    cpu->edi = native_function_address32(&::fwrite);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u);
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, 4u); lift_push32(cpu, cpu->eax);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fwrite)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u), *(uint32_t*)(cpu->esp + 0x8u), *(uint32_t*)(cpu->esp + 0xCu));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp + 0x638u;
    lift_push32(cpu, 4u); lift_push32(cpu, cpu->ecx);
    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t, uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::fwrite)))(*(uint32_t*)(cpu->esp), *(uint32_t*)(cpu->esp + 0x4u), *(uint32_t*)(cpu->esp + 0x8u), *(uint32_t*)(cpu->esp + 0xCu));
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x49AE35u));
    cpu->esp += 0x24u;
    label_0009AE3E:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->ebp + 0x434u) = 4u;
    goto label_0009AFE7;
    label_0009AE55:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x434u);
    if (cpu->edx != 4u) goto label_0009AFC0;
    cpu->eax = cpu->ebp + 0x128u;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x120u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::__WSAFDIsSet), LIFT_CODE_TOKEN_VA(0x49AE72u));
    if (cpu->eax == 0u) goto label_0009AFC0;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x120u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1000u);
    cpu->ecx = cpu->esp + 0x8E8u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::recv), LIFT_CODE_TOKEN_VA(0x49AE95u));
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_0009B032;
    if (cpu->esi == 0xFFFFFFFFu) goto label_0009B032;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x640u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u);
    cpu->ecx = cpu->esp + 0x8E8u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::fwrite), LIFT_CODE_TOKEN_VA(0x49AEBFu));
    *(uint32_t*)(cpu->ebp + 0x63Cu) = (uint64_t)(*(uint32_t*)(cpu->ebp + 0x63Cu)) + (uint64_t)(cpu->esi) + (uint64_t)(0u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x638u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x63Cu);
    cpu->esp += 0x10u;
    if ((int32_t)cpu->eax < (int32_t)cpu->edx) goto label_0009AFB6;
    cpu->ecx = cpu->esp + 0x4E0u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x49AEEAu));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x640u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::fseek), LIFT_CODE_TOKEN_VA(0x49AEFBu));
    cpu->esp += 0x10u;
    cpu->edx = 0x174u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\UpdateClnt.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49AF13u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x49AF13u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x63Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49AF1Fu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x49AF1Fu));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x640u);
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x63Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->esi = cpu->eax;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fread), LIFT_CODE_TOKEN_VA(0x49AF32u));
    g_sfera_crc32_runtime.current = 0u;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x63Cu);
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49AF52u)); sfera_sub_0049A920(cpu, LIFT_CODE_TOKEN_VA(0x49AF52u));
    cpu->edx = 0x17Au;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\UpdateClnt.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49AF61u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x49AF61u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49AF67u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49AF67u));
    cpu->eax = g_sfera_crc32_runtime.current;
    cpu->esp += 4u;
    if (cpu->eax != *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_0009B029;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x640u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x49AF80u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->ecx = cpu->esp + 0x34u;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edx;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0xE8u;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::_utime64), LIFT_CODE_TOKEN_VA(0x49AFA3u));
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->ebp + 0x434u) = 6u;
    label_0009AFB6:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    goto label_0009AFE7;
    label_0009AFC0:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x434u);
    if (cpu->eax != 6u) goto label_0009AFDC;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x120u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::__WSAFDIsSet), LIFT_CODE_TOKEN_VA(0x49AFD3u));
    if (cpu->eax != 0u) goto label_0009B053;
    label_0009AFDC:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebp));
    if ((cpu->edx & 0xFFu) != 0u) goto label_0009B07D;
    label_0009AFE7:
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x49AFECu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    x87_p0 = ::_difftime64(static_cast<__time64_t>(*(uint64_t*)(cpu->esp)), static_cast<__time64_t>(*(uint64_t*)(cpu->esp + 8u)));
    lift_cmp[1]=x87_p0>(15.0);
    cpu->esp += 0x14u;
    if (!lift_cmp[1]) goto label_0009AAA1;
    label_0009B018:
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x49B018u));
    *(uint32_t*)(cpu->ebp + 0x434u) = 5u;
    goto label_0009B082;
    label_0009B029:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x640u);
    lift_push32(cpu, cpu->eax);
    goto label_0009B039;
    label_0009B032:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x640u);
    lift_push32(cpu, cpu->ecx);
    label_0009B039:
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x49B039u));
    cpu->esp += 4u;
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x49B042u));
    *(uint32_t*)(cpu->ebp + 0x434u) = 5u;
    goto label_0009B082;
    label_0009B053:
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x120u);
    lift_push32(cpu, 0u); lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"DA"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::send), LIFT_CODE_TOKEN_VA(0x49B063u));
    if (cpu->eax == 0u) goto label_0009B018;
    if (cpu->eax == 0xFFFFFFFFu) goto label_0009B018;
    *(uint32_t*)(cpu->ebp + 0x434u) = 0u;
    goto label_0009B082;
    label_0009B07D:
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x49B07Du));
    label_0009B082:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint8_t*)(cpu->ebp + 1u) = 1u;
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x18D4u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049B0B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x198u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + 1u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_0009B0EB;
    cpu->eax = 3u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x198u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0009B0EB:
    cpu->ecx = cpu->esp + 8u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x202u);
    lift_native_call(cpu, native_function_address32(&::WSAStartup), LIFT_CODE_TOKEN_VA(0x49B0F5u));
    if (cpu->eax != 0xFFFFFFFFu) goto label_0009B11C;
    cpu->eax = 4u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x198u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0009B11C:
    cpu->edx = (int8_t)(*(uint8_t*)(cpu->esi + 0x10u));
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esi + 0x10u;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::isalpha), LIFT_CODE_TOKEN_VA(0x49B126u));
    cpu->esp += 4u;
    lift_push32(cpu, cpu->edi);
    if (cpu->eax == 0u) goto label_0009B13B;
    lift_native_call(cpu, native_function_address32(&::gethostbyname), LIFT_CODE_TOKEN_VA(0x49B134u));
    goto label_0009B152;
    label_0009B13B:
    lift_native_call(cpu, native_function_address32(&::inet_addr), LIFT_CODE_TOKEN_VA(0x49B13Bu));
    lift_push32(cpu, 2u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, 4u);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::gethostbyaddr), LIFT_CODE_TOKEN_VA(0x49B14Du));
    label_0009B152:
    cpu->ebp = cpu->eax;
    if (cpu->ebp != 0u) goto label_0009B165;
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x49B158u));
    cpu->eax = cpu->ebp + 5u;
    goto label_0009B28E;
    label_0009B165:
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x110u) = cpu->eax;
    cpu->edi = cpu->esi + 0x110u;
    *(uint32_t*)(cpu->edi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 8u) = cpu->eax;
    *(uint32_t*)(cpu->edi + 0xCu) = cpu->eax;
    cpu->ecx = (int16_t)(*(uint16_t*)(cpu->ebp + 0xAu));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->eax = *(uint32_t*)(cpu->edx);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi + 0x114u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x49B18Eu));
    cpu->eax = *(uint16_t*)(cpu->esi + 0xCu);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | (*(uint16_t*)(cpu->ebp + 8u));
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->eax);
    *(uint16_t*)(cpu->edi) = cpu->edx & 0xFFFFu;
    lift_native_call(cpu, native_function_address32(&::htons), LIFT_CODE_TOKEN_VA(0x49B1A2u));
    lift_push32(cpu, 0u); lift_push32(cpu, 1u); lift_push32(cpu, 2u);
    *(uint16_t*)(cpu->esi + 0x112u) = cpu->eax & 0xFFFFu;
    lift_native_call(cpu, native_function_address32(&::socket), LIFT_CODE_TOKEN_VA(0x49B1B4u));
    cpu->ecx = cpu->esi + 0x124u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x8004667Eu); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esi + 0x120u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::ioctlsocket), LIFT_CODE_TOKEN_VA(0x49B1CCu));
    if (cpu->eax != 0xFFFFFFFFu) goto label_0009B1E5;
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x49B1D6u));
    cpu->eax = 4u;
    goto label_0009B28E;
    label_0009B1E5:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x120u);
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::connect), LIFT_CODE_TOKEN_VA(0x49B1EFu));
    if (cpu->eax != 0xFFFFFFFFu) goto label_0009B211;
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x49B1F9u));
    if (cpu->eax == 0x2733u) goto label_0009B211;
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x49B205u));
    cpu->eax = 6u;
    goto label_0009B28E;
    label_0009B211:
    cpu->eax = cpu->esi + 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_0049AA10)); lift_push32(cpu, 0u);
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, 0u);
    *(uint8_t*)(cpu->esi + 1u) = 0u;
    lift_native_call(cpu, native_function_address32(&::CreateThread), LIFT_CODE_TOKEN_VA(0x49B228u));
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    if (cpu->eax != 0u) goto label_0009B241;
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x49B235u));
    cpu->eax = 2u;
    goto label_0009B28E;
    label_0009B241:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1A8u);
    cpu->edx = cpu->esi + 0x438u;
    if (*(uint8_t*)(cpu->eax) != 0x5Cu) goto label_0009B262;
    ++cpu->eax;
    cpu->edx -= cpu->eax;
    label_0009B256:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0009B256;
    goto label_0009B26E;
    label_0009B262:
    cpu->edx -= cpu->eax;
    label_0009B264:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0009B264;
    label_0009B26E:
    *(uint32_t*)(cpu->esi + 0x434u) = 1u;
    *(uint32_t*)(cpu->esi + 0x638u) = 0u;
    *(uint32_t*)(cpu->esi + 0x63Cu) = 0u;
    cpu->eax = 0u;
    label_0009B28E:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x198u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049B2B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x14u;
    cpu->eax = 0x6E726157u;
    cpu->edx = 0x6C2E3030u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x676F)) & 0xFFFFu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = 0x73676E69u;
    *(uint16_t*)(cpu->esp + 0x18u) = cpu->eax & 0xFFFFu;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    *(uint8_t*)(cpu->esp + 0x1Au) = cpu->ecx & 0xFFu;
    cpu->ecx = g_sfera_recovered_static_runtime.server_number;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x66666667u * (int32_t)(cpu->ecx))) >> 32u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->edx = cpu->eax + 0x30u;
    *(uint8_t*)(cpu->esp + 0x14u) = cpu->edx & 0xFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((cpu->eax & 0xFFu) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) - (uint64_t)((cpu->eax & 0xFFu)) - (uint64_t)(0u))) & 0xFFu);
    cpu->eax = cpu->esp + 0xCu;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->eax);
    *(uint8_t*)(cpu->esp + 0x1Du) = cpu->ecx & 0xFFu;
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x49B334u));
    cpu->ebx = cpu->eax;
    cpu->esp += 8u;
    if (cpu->ebx == 0u) goto label_0009B45C;
    if (cpu->esi < 0xAu) goto label_0009B358;
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B358u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B358u));
    label_0009B358:
    cpu->ecx = cpu->esi;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x850u);
    cpu->edi += cpu->ecx;
    if (*(uint32_t*)(cpu->edi + 0x448u) != 1u) goto label_0009B3C4;
    if (cpu->esi < 0xAu) goto label_0009B3A0;
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B37Cu)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_VA(0x49B37Cu));
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B388u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_VA(0x49B388u));
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B394u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_VA(0x49B394u));
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B3A0u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B3A0u));
    label_0009B3A0:
    cpu->edx = cpu->edi + 0x44Cu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->edi + 0x48u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0x28u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->edi + 8u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"%s %s\n%s\n%s\n\n"); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x49B3B9u));
    cpu->esp += 0x18u;
    goto label_0009B42E;
    label_0009B3C4:
    if (cpu->esi < 0xAu) goto label_0009B405;
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B3D5u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_VA(0x49B3D5u));
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B3E1u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_VA(0x49B3E1u));
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B3EDu)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_VA(0x49B3EDu));
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B3F9u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_VA(0x49B3F9u));
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B405u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B405u));
    label_0009B405:
    cpu->edx = *(uint32_t*)(cpu->edi + 0x448u);
    cpu->eax = cpu->edi + 0x44Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0x48u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->edi + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 8u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%s %s\n(%d) %s\n%s\n\n"); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x49B425u));
    cpu->esp += 0x1Cu;
    label_0009B42E:
    if (cpu->esi < 0xAu) goto label_0009B43F;
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B43Fu)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B43Fu));
    label_0009B43F:
    if (*(uint32_t*)(cpu->edi + 0x84Cu) != 1u) goto label_0009B452;
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x49B449u));
    cpu->esp += 4u;
    label_0009B452:
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x49B453u));
    cpu->esp += 4u;
    label_0009B45C:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049B470(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ebx;
    sub_pred[0] = cpu->esi < 0xAu;
    label_0009B47C:
    if (sub_pred[0]) goto label_0009B48A;
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B48Au)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B48Au));
    label_0009B48A:
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->eax|=*(uint32_t*)(cpu->edi + 4u);
    if (cpu->eax==0u) goto label_0009B4B7;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B499u)); sfera_sub_0049B2B0(cpu, LIFT_CODE_TOKEN_VA(0x49B499u));
    if (cpu->esi < 0xAu) goto label_0009B4AA;
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B4AAu)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B4AAu));
    label_0009B4AA:
    *(uint32_t*)(cpu->edi) = 0u;
    *(uint32_t*)(cpu->edi + 4u) = 0u;
    label_0009B4B7:
    ++cpu->esi;
    cpu->edi += 0x850u;
    sub_pred[0] = cpu->esi < 0xAu;
    if ((int32_t)(cpu->esi) < (int32_t)(0xAu)) goto label_0009B47C;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049B4D0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[3];
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::_stricmp);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebp = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esi;
    sub_pred[0] = cpu->ebp < 0xAu;
    label_0009B4E6:
    if (sub_pred[0]) goto label_0009B4F4;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B4F4u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B4F4u));
    label_0009B4F4:
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->eax|=*(uint32_t*)(cpu->edi + 4u);
    if (cpu->eax==0u) goto label_0009B51E;
    if (cpu->ebp < 0xAu) goto label_0009B50C;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B50Cu)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B50Cu));
    label_0009B50C:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = cpu->edi + 0x48u;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->ecx, cpu->eax);

    if (cpu->eax == 0u) goto label_0009B52C;
    label_0009B51E:
    ++cpu->ebp;
    cpu->edi += 0x850u;
    sub_pred[0] = cpu->ebp < 0xAu;
    if ((int32_t)(cpu->ebp) < (int32_t)(0xAu)) goto label_0009B4E6;
    goto label_0009B572;
    label_0009B52C:
    if (cpu->ebp < 0xAu) goto label_0009B53D;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B53Du)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B53Du));
    label_0009B53D:
    cpu->edi = cpu->ebp;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x850u);
    ++*(uint32_t*)(cpu->edi + cpu->esi + 0x448u);
    cpu->edi += cpu->esi;
    if (cpu->ebp < 0xAu) goto label_0009B55F;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B55Fu)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B55Fu));
    label_0009B55F:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B564u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x49B564u));
    *(uint32_t*)(cpu->edi) = cpu->eax;
    *(uint32_t*)(cpu->edi + 4u) = cpu->edx;
    if ((int32_t)cpu->ebp < (int32_t)0xAu) goto label_0009B779;
    label_0009B572:
    cpu->edi = 0u;
    cpu->ebx = cpu->esi;
    sub_pred[1] = cpu->edi < 0xAu;
    label_0009B579:
    if (sub_pred[1]) goto label_0009B587;
    cpu->edx = cpu->edi;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B587u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B587u));
    label_0009B587:
    cpu->eax = *(uint32_t*)(cpu->ebx);
    cpu->eax|=*(uint32_t*)(cpu->ebx + 4u);
    if (cpu->eax==0u) goto label_0009B59A;
    ++cpu->edi;
    cpu->ebx += 0x850u;
    sub_pred[1] = cpu->edi < 0xAu;
    if ((int32_t)(cpu->edi) < (int32_t)(0xAu)) goto label_0009B579;
    label_0009B59A:
    sub_pred[2] = cpu->ebp < 0xAu;
    if (cpu->ebp != 0xAu) goto label_0009B5C5;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B5A8u)); sfera_sub_0049B2B0(cpu, LIFT_CODE_TOKEN_VA(0x49B5A8u));
    lift_push32(cpu, 0x4AD0u);
    cpu->ecx = cpu->esi + 0x850u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x49B5B5u));
    cpu->esp += 0xCu;
    cpu->ebp = 9u;
    goto label_0009B5D3;
    label_0009B5C5:
    if (sub_pred[2]) goto label_0009B5D3;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B5D3u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B5D3u));
    label_0009B5D3:
    cpu->ebx = cpu->ebp;
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x850u);
    cpu->ebx += cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B5E6u)); sfera_sub_0049A670(cpu, LIFT_CODE_TOKEN_VA(0x49B5E6u));
    cpu->edi = 1u;
    cpu->eax += cpu->edi;
    cpu->edx += (cpu->eax < cpu->edi);
    *(uint32_t*)(cpu->ebx) = cpu->eax;
    *(uint32_t*)(cpu->ebx + 4u) = cpu->edx;
    if (cpu->ebp < 0xAu) goto label_0009B604;
    cpu->edx = cpu->ebp;
    cpu->ecx = cpu->edi + 9u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B604u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B604u));
    label_0009B604:
    *(uint32_t*)(cpu->ebx + 0x448u) = cpu->edi;
    if (cpu->ebp < 0xAu) goto label_0009B61B;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B61Bu)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B61Bu));
    label_0009B61B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->ebx + 0x84Cu) = cpu->eax;
    if (cpu->ebp < 0xAu) goto label_0009B636;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B636u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B636u));
    label_0009B636:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = cpu->esi;
    cpu->edx = cpu->eax + 1u;
    (void)cpu;
    label_0009B640:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0009B640;
    cpu->eax -= cpu->edx;
    if ((int32_t)cpu->eax < (int32_t)0x400u) goto label_0009B68A;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, (uintptr_t)"SSTR::operator=: buffer overflow! - %s"); lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x20u) = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\sstr.h";
    *(uint32_t*)(cpu->esp + 0x24u) = 0x6Du;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B674u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x49B674u));
    cpu->edi = cpu->ebx + 0x48u;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),1023u); cpu->esi += 1023u; cpu->edi += 1023u; cpu->ecx = 0u;
    *(uint8_t*)(cpu->ebx + 0x447u) = 0u;
    goto label_0009B696;
    label_0009B68A:
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->ebx + 0x48u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x49B691u));
    label_0009B696:
    cpu->esp += 0xCu;
    if (cpu->ebp < 0xAu) goto label_0009B6AA;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B6AAu)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B6AAu));
    label_0009B6AA:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    cpu->ebx += 0x44Cu;
    *(uint8_t*)(cpu->ebx) = cpu->edx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B6BDu)); sfera_sub_00434D90(cpu, LIFT_CODE_TOKEN_VA(0x49B6BDu));
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_0009B739;
    if (cpu->ebp < 0xAu) goto label_0009B6D4;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B6D4u)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B6D4u));
    label_0009B6D4:
    cpu->eax = cpu->esi;
    cpu->edx = cpu->eax + 1u;
    label_0009B6E0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0009B6E0;
    cpu->eax -= cpu->edx;
    if ((int32_t)cpu->eax < (int32_t)0x400u) goto label_0009B72D;
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, (uintptr_t)"SSTR::operator=: buffer overflow! - %s"); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x20u) = (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\sstr.h";
    *(uint32_t*)(cpu->esp + 0x24u) = 0x6Du;
    *(uint32_t*)(cpu->esp + 0x28u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B718u)); sfera_sub_004EC2E0(cpu, LIFT_CODE_TOKEN_VA(0x49B718u));
    cpu->edi = cpu->ebx;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),1023u); cpu->esi += 1023u; cpu->edi += 1023u; cpu->ecx = 0u;
    *(uint8_t*)(cpu->ebx + 0x3FFu) = 0u;
    goto label_0009B736;
    label_0009B72D:
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x49B731u));
    label_0009B736:
    cpu->esp += 0xCu;
    label_0009B739:
    if (cpu->ebp < 0xAu) goto label_0009B74A;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B74Au)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B74Au));
    label_0009B74A:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = cpu->esi + 8u;
    cpu->edx = 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B75Bu)); sfera_sub_0044BFE0(cpu, LIFT_CODE_TOKEN_VA(0x49B75Bu));
    if (cpu->ebp < 0xAu) goto label_0009B76C;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9B76Cu)); sfera_sub_004ED5E0(cpu, LIFT_CODE_TOKEN_RVA(0x9B76Cu));
    label_0009B76C:
    cpu->esi += 0x28u;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x49B770u));
    cpu->esp += 4u;
    label_0009B779:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049B790(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x404u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40Cu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x40Cu);
    cpu->eax = cpu->esp + 0x414u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::vsprintf), LIFT_CODE_TOKEN_VA(0x49B7C1u));
    cpu->esp += 0xCu;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B7D8u)); sfera_sub_0049B4D0(cpu, LIFT_CODE_TOKEN_VA(0x49B7D8u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049B7F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x404u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x40Cu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x40Cu);
    cpu->eax = cpu->esp + 0x414u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::vsprintf), LIFT_CODE_TOKEN_VA(0x49B821u));
    cpu->esp += 0xCu;
    lift_push32(cpu, 1u);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B838u)); sfera_sub_0049B4D0(cpu, LIFT_CODE_TOKEN_VA(0x49B838u));
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49B83Fu)); sfera_sub_0049B470(cpu, LIFT_CODE_TOKEN_VA(0x49B83Fu));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049B860(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    *(uint8_t*)(cpu->eax + 8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x28u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x48u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x44Cu) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x858u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x878u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x898u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0xC9Cu) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x10A8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x10C8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x10E8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x14ECu) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x18F8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x1918u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x1938u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x1D3Cu) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x2148u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x2168u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x2188u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x258Cu) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x2998u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x29B8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x29D8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x2DDCu) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x31E8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x3208u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x3228u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x362Cu) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x3A38u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x3A58u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x3A78u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x3E7Cu) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x4288u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x42A8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x42C8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x46CCu) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x4AD8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x4AF8u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x4B18u) = cpu->ecx & 0xFFu;
    *(uint8_t*)(cpu->eax + 0x4F1Cu) = cpu->ecx & 0xFFu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049BA10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    cpu->edi = (uintptr_t)&g_sfera_weather_runtime.parse_error[0];
    std::memmove((void*)(cpu->edi),(void*)((uintptr_t)"wrong format of weather.txt\n"),29u); cpu->edi += 29u; cpu->ecx = 0u;
    cpu->ecx = cpu->ebx;
    cpu->eax = cpu->edx;
    cpu->esi = cpu->ecx;
    label_0009BA30:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    ++cpu->ecx;
    if ((cpu->ebx & 0xFFu) != 0u) goto label_0009BA30;
    cpu->ecx -= cpu->esi;
    cpu->edi = (uintptr_t)&g_sfera_weather_runtime.parse_error[0];
    cpu->ebx = cpu->ecx;
    --cpu->edi;
    label_0009BA41:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_0009BA41;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->ebx); cpu->esi += cpu->ebx; cpu->edi += cpu->ebx;
    cpu->ecx = (uintptr_t)&g_sfera_weather_runtime.parse_error[0];
    --cpu->ecx;
    label_0009BA60:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx + 1u));
    ++cpu->ecx;
    if ((cpu->ebx & 0xFFu) != 0u) goto label_0009BA60;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x202C)) & 0xFFFFu);
    *(uint16_t*)(cpu->ecx) = cpu->edx & 0xFFFFu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    *(uint8_t*)(cpu->ecx + 2u) = cpu->edx & 0xFFu;
    cpu->ecx = cpu->eax;
    label_0009BA80:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0009BA80;
    cpu->edi = (uintptr_t)&g_sfera_weather_runtime.parse_error[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_0009BA91:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edi + 1u));
    ++cpu->edi;
    if ((cpu->ecx & 0xFFu)!=0u) goto label_0009BA91;
    std::memmove((void*)cpu->edi,(void*)cpu->esi,cpu->eax);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->ecx = (uintptr_t)&g_sfera_weather_runtime.parse_error[0];
    cpu->ebx = lift_pop32(cpu);
    sfera_sub_00459B10(cpu, stop_address); return;
}
__declspec(noinline) void sfera_sub_0049BAC0(LiftCpu* cpu, uint32_t stop_address) { double x87_p0;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x3Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x50u;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x60u);
    lift_push32(cpu, 0x7E80u);
    cpu->ebx = 0u;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x49BB01u));
    cpu->esp += 0xCu;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49BB12u)); sfera_sub_00480380(cpu, LIFT_CODE_TOKEN_VA(0x49BB12u));
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x18u;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49BB20u)); sfera_sub_004803B0(cpu, LIFT_CODE_TOKEN_VA(0x49BB20u));
    cpu->eax = *(uint32_t*)((uintptr_t)"s00_0");
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | (*(uint16_t*)(((uintptr_t)"s00_0") + 4u));
    cpu->edx = *(uint32_t*)((uintptr_t)"t00c");
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"t00c") + 4u));
    *(uint16_t*)(cpu->esp + 0x38u) = cpu->ecx & 0xFFFFu;
    cpu->ecx = *(uint32_t*)((uintptr_t)"q000");
    lift_push32(cpu, 2u);
    *(uint8_t*)(cpu->esp + 0x44u) = cpu->eax & 0xFFu;
    cpu->eax = cpu->esi + 0x18E0u;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->ecx;
    lift_push32(cpu, (uintptr_t)"stime");
    cpu->ecx = cpu->esp + 0x28u;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->edx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(((uintptr_t)"q000") + 4u));
    lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0x303073u;
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esp + 0x28u) = 0x303074u;
    *(uint32_t*)(cpu->esp + 0x3Cu) = 0x303072u;
    *(uint32_t*)(cpu->esp + 0x38u) = 0x303067u;
    *(uint32_t*)(cpu->esp + 0x40u) = 0x303062u;
    *(uint8_t*)(cpu->esp + 0x58u) = cpu->edx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x30u) = 0x303063u;
    *(uint32_t*)(cpu->esi + 0x7CE0u) = cpu->ebx;
    *(uint16_t*)(cpu->esp + 0x45u) = 0x3030u;
    *(uint16_t*)(cpu->esp + 0x2Du) = 0x3030u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49BBBCu)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49BBBCu));
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x7CE0u);
    cpu->edx = cpu->eax;
    cpu->edx <<= 8u;
    cpu->edi = cpu->edx + cpu->esi + 0x18E0u;
    cpu->ebp = 0x32u;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ebp); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    cpu->eax = sfera_texture_time_key_digit(cpu->edx);
    *(uint32_t*)(cpu->edi) = (uint64_t)(*(uint32_t*)(cpu->edi)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    if (cpu->ecx == cpu->ebx) goto label_0009BF51;
    label_0009BBE9:
    if (cpu->ecx == 1u) goto label_0009BBFC;
    cpu->edx = (uintptr_t)"stime";
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9BBFCu)); sfera_sub_0049BA10(cpu, LIFT_CODE_TOKEN_RVA(0x9BBFCu));
    label_0009BBFC:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x7CE0u);
    cpu->ecx <<= 8u;
    lift_push32(cpu, 1u);
    cpu->edx = cpu->ecx + cpu->esi + 0x18E4u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"nsky1");
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49BC22u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49BC22u));
    if (cpu->eax == 1u) goto label_0009BC35;
    cpu->edx = (uintptr_t)"nsky1";
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9BC35u)); sfera_sub_0049BA10(cpu, LIFT_CODE_TOKEN_RVA(0x9BC35u));
    label_0009BC35:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x7CE0u);
    cpu->edi = native_function_address32(&::_stricmp);
    cpu->ecx <<= 8u;
    cpu->edx = cpu->ecx + cpu->esi + 0x18E4u;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->edx, (uintptr_t)"none");

    if (cpu->eax!=0u) goto label_0009BC6B;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x7CE0u);
    cpu->eax <<= 8u;
    *(uint8_t*)(cpu->eax + cpu->esi + 0x18E4u) = 0u;
    label_0009BC6B:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x7CE0u);
    cpu->ecx <<= 8u;
    lift_push32(cpu, 1u);
    cpu->edx = cpu->ecx + cpu->esi + 0x18F8u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"nsky2");
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49BC91u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49BC91u));
    if (cpu->eax == 1u) goto label_0009BCA4;
    cpu->edx = (uintptr_t)"nsky2";
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9BCA4u)); sfera_sub_0049BA10(cpu, LIFT_CODE_TOKEN_RVA(0x9BCA4u));
    label_0009BCA4:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x7CE0u);
    cpu->ecx <<= 8u;
    cpu->edx = cpu->ecx + cpu->esi + 0x18F8u;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->edx, (uintptr_t)"none");

    if (cpu->eax!=0u) goto label_0009BCD4;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x7CE0u);
    cpu->eax <<= 8u;
    *(uint8_t*)(cpu->eax + cpu->esi + 0x18F8u) = 0u;
    label_0009BCD4:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x7CE0u);
    cpu->ecx <<= 8u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->ecx + cpu->esi + 0x190Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"tsky1");
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49BCFAu)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49BCFAu));
    if (cpu->eax == 1u) goto label_0009BD0D;
    cpu->edx = (uintptr_t)"tsky1";
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9BD0Du)); sfera_sub_0049BA10(cpu, LIFT_CODE_TOKEN_RVA(0x9BD0Du));
    label_0009BD0D:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x7CE0u);
    cpu->ecx <<= 8u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->ecx + cpu->esi + 0x1910u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"tsky2");
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49BD33u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49BD33u));
    if (cpu->eax == 1u) goto label_0009BD46;
    cpu->edx = (uintptr_t)"tsky2";
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9BD46u)); sfera_sub_0049BA10(cpu, LIFT_CODE_TOKEN_RVA(0x9BD46u));
    label_0009BD46:
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"t");
    cpu->edx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x24u;
    *(uint8_t*)(cpu->esp + 0x48u) = 0x30u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49BD66u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49BD66u));
    if (cpu->eax==0u) goto label_0009BED9;
    cpu->edi = 0u;
    label_0009BD70:
    if (cpu->eax == 1u) goto label_0009BD83;
    cpu->edx = (uintptr_t)"t";
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9BD83u)); sfera_sub_0049BA10(cpu, LIFT_CODE_TOKEN_RVA(0x9BD83u));
    label_0009BD83:
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x7CE0u);
    cpu->ebp = cpu->ebp << 8u;
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esi + cpu->ebp + 0x18E0u))));
    x87_p0 = (x87_p0) - (0.009999999776482582);
    x87_p0 = (x87_p0) * (((double)*(float*)(cpu->esp + 0x24u)));
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_p0); 
    cpu->ecx = cpu->edi + cpu->esi;
    *(uint32_t*)(cpu->ecx + cpu->ebp + 0x1918u) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x7CE0u);
    cpu->edx <<= 8u;
    lift_push32(cpu, 0u);
    cpu->edx += cpu->edi;
    cpu->eax = cpu->edx + cpu->esi + 0x191Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"r");
    cpu->ecx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49BDD4u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49BDD4u));
    if (cpu->eax == 1u) goto label_0009BDE7;
    cpu->edx = (uintptr_t)"r";
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9BDE7u)); sfera_sub_0049BA10(cpu, LIFT_CODE_TOKEN_RVA(0x9BDE7u));
    label_0009BDE7:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x7CE0u);
    cpu->edx <<= 8u;
    lift_push32(cpu, 0u);
    cpu->edx += cpu->edi;
    cpu->eax = cpu->edx + cpu->esi + 0x1920u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"fl1");
    cpu->ecx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49BE0Fu)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49BE0Fu));
    if (cpu->eax == 1u) goto label_0009BE22;
    cpu->edx = (uintptr_t)"fl1";
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9BE22u)); sfera_sub_0049BA10(cpu, LIFT_CODE_TOKEN_RVA(0x9BE22u));
    label_0009BE22:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x7CE0u);
    cpu->edx <<= 8u;
    lift_push32(cpu, 0u);
    cpu->edx += cpu->edi;
    cpu->eax = cpu->edx + cpu->esi + 0x1924u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"fl2");
    cpu->ecx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49BE4Au)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49BE4Au));
    if (cpu->eax == 1u) goto label_0009BE5D;
    cpu->edx = (uintptr_t)"fl2";
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9BE5Du)); sfera_sub_0049BA10(cpu, LIFT_CODE_TOKEN_RVA(0x9BE5Du));
    label_0009BE5D:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x7CE0u);
    cpu->edx <<= 8u;
    lift_push32(cpu, 0u);
    cpu->edx += cpu->edi;
    cpu->eax = cpu->edx + cpu->esi + 0x1928u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"cs");
    cpu->ecx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49BE85u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49BE85u));
    if (cpu->eax == 1u) goto label_0009BE98;
    cpu->edx = (uintptr_t)"cs";
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9BE98u)); sfera_sub_0049BA10(cpu, LIFT_CODE_TOKEN_RVA(0x9BE98u));
    label_0009BE98:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x7CE0u);
    lift_push32(cpu, 0u);
    cpu->eax = cpu->ebx + 1u;
    cpu->edx <<= 8u;
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->edx + cpu->esi + 0x1914u) = cpu->eax;
    cpu->ebx = cpu->eax;
    lift_push32(cpu, (uintptr_t)"t");
    cpu->edx = cpu->esp + 0x40u;
    cpu->eax = cpu->ebx + 0x30u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x24u;
    cpu->edi += 0x14u;
    *(uint8_t*)(cpu->esp + 0x48u) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49BED1u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49BED1u));
    if (cpu->eax!=0u) goto label_0009BD70;
    label_0009BED9:
    ++*(uint32_t*)(cpu->esi + 0x7CE0u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x7CE0u);
    cpu->eax = cpu->ecx;
    cpu->edi = 0xAu;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->edi); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    cpu->ecx <<= 8u;
    lift_push32(cpu, 2u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    *(uint8_t*)(cpu->esp + 0x39u) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x21u) = cpu->eax & 0xFFu;
    cpu->eax = cpu->ecx + cpu->esi + 0x18E0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"stime");
    cpu->ecx = cpu->esp + 0x28u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x24u;
    *(uint8_t*)(cpu->esp + 0x46u) = cpu->edx & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x2Eu) = cpu->edx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49BF24u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49BF24u));
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x7CE0u);
    cpu->edx = cpu->eax;
    cpu->edx <<= 8u;
    cpu->edi = cpu->edx + cpu->esi + 0x18E0u;
    cpu->ebx = 0x32u;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ebx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    cpu->eax = sfera_texture_time_key_digit(cpu->edx);
    *(uint32_t*)(cpu->edi) = (uint64_t)(*(uint32_t*)(cpu->edi)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    if (cpu->ecx != 0u) goto label_0009BBE9;
    label_0009BF51:
    cpu->ebp = 1u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"ntex");
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esi + 0x1428u) = 0u;
    *(uint16_t*)(cpu->esp + 0x4Du) = 0x3030u;
    *(uint16_t*)(cpu->esp + 0x29u) = 0x3030u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49BF83u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49BF83u));
    if (cpu->eax == 0u) goto label_0009C201;
    label_0009BF8B:
    if (cpu->eax == cpu->ebp) goto label_0009BF9D;
    cpu->edx = (uintptr_t)"ntex";
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9BF9Du)); sfera_sub_0049BA10(cpu, LIFT_CODE_TOKEN_RVA(0x9BF9Du));
    label_0009BF9D:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1428u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xACu);
    lift_push32(cpu, 0u);
    cpu->eax = cpu->edx + cpu->esi + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"sc1");
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49BFC3u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49BFC3u));
    if (cpu->eax == cpu->ebp) goto label_0009BFD5;
    cpu->edx = (uintptr_t)"sc1";
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9BFD5u)); sfera_sub_0049BA10(cpu, LIFT_CODE_TOKEN_RVA(0x9BFD5u));
    label_0009BFD5:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1428u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xACu);
    lift_push32(cpu, 0u);
    cpu->eax = cpu->edx + cpu->esi + 0x18u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"sc2");
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49BFFBu)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49BFFBu));
    if (cpu->eax == cpu->ebp) goto label_0009C00D;
    cpu->edx = (uintptr_t)"sc2";
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9C00Du)); sfera_sub_0049BA10(cpu, LIFT_CODE_TOKEN_RVA(0x9C00Du));
    label_0009C00D:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1428u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xACu);
    lift_push32(cpu, 2u);
    cpu->eax = cpu->edx + cpu->esi + 0x1Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"scrll");
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49C033u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49C033u));
    if (cpu->eax == cpu->ebp) goto label_0009C045;
    cpu->edx = (uintptr_t)"scrll";
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9C045u)); sfera_sub_0049BA10(cpu, LIFT_CODE_TOKEN_RVA(0x9C045u));
    label_0009C045:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1428u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xACu);
    lift_push32(cpu, 0u);
    cpu->eax = cpu->edx + cpu->esi + 0x20u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"time1");
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49C06Bu)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49C06Bu));
    if (cpu->eax == cpu->ebp) goto label_0009C07D;
    cpu->edx = (uintptr_t)"time1";
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9C07Du)); sfera_sub_0049BA10(cpu, LIFT_CODE_TOKEN_RVA(0x9C07Du));
    label_0009C07D:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1428u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xACu);
    lift_push32(cpu, 0u);
    cpu->eax = cpu->edx + cpu->esi + 0x24u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"time2");
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49C0A3u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49C0A3u));
    if (cpu->eax == cpu->ebp) goto label_0009C0B5;
    cpu->edx = (uintptr_t)"time2";
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9C0B5u)); sfera_sub_0049BA10(cpu, LIFT_CODE_TOKEN_RVA(0x9C0B5u));
    label_0009C0B5:
    cpu->ebx = 0u;
    cpu->edi=0u;
    label_0009C0C0:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1428u);
    cpu->eax = 0xCCCCCCCDu;
    cpu->ecx *= 0xACu;
    cpu->edx = (uint32_t)(((uint64_t)cpu->eax * (uint32_t)(cpu->ebx)) >> 32u);
    cpu->edx >>= 3u;
    cpu->eax = cpu->edx + 0x30u;
    *(uint8_t*)(cpu->esp + 0x31u) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x29u) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x2Du) = cpu->eax & 0xFFu;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((cpu->edx & 0xFFu) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((cpu->ebx & 0xFFu) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) - (uint64_t)((cpu->edx & 0xFFu)) - (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    cpu->ecx += cpu->edi;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->ecx + cpu->esi + 0x28u;
    *(uint8_t*)(cpu->esp + 0x36u) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x2Eu) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x32u) = cpu->eax & 0xFFu;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49C11Du)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49C11Du));
    if (cpu->eax == cpu->ebp) goto label_0009C12E;
    cpu->edx = cpu->esp + 0x2Cu;
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9C12Eu)); sfera_sub_0049BA10(cpu, LIFT_CODE_TOKEN_RVA(0x9C12Eu));
    label_0009C12E:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x1428u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xACu);
    cpu->edx += cpu->edi;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->edx + cpu->esi + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49C156u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49C156u));
    if (cpu->eax == cpu->ebp) goto label_0009C167;
    cpu->edx = cpu->esp + 0x28u;
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9C167u)); sfera_sub_0049BA10(cpu, LIFT_CODE_TOKEN_RVA(0x9C167u));
    label_0009C167:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1428u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xACu);
    cpu->eax += cpu->edi;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->eax + cpu->esi + 0x30u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49C18Fu)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49C18Fu));
    if (cpu->eax == cpu->ebp) goto label_0009C1A0;
    cpu->edx = cpu->esp + 0x30u;
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9C1A0u)); sfera_sub_0049BA10(cpu, LIFT_CODE_TOKEN_RVA(0x9C1A0u));
    label_0009C1A0:
    cpu->edi += 0xCu;
    cpu->ebx += cpu->ebp;
    if ((int32_t)(cpu->edi) < (int32_t)(0x84u)) goto label_0009C0C0;
    *(uint32_t*)(cpu->esi + 0x1428u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x1428u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1428u);
    cpu->eax = cpu->ecx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xACu);
    cpu->edi = 0xAu;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->edi); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    lift_push32(cpu, cpu->ebp);
    cpu->ecx += cpu->esi;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"ntex");
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x24u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    *(uint8_t*)(cpu->esp + 0x4Du) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x29u) = cpu->eax & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x4Eu) = cpu->edx & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x2Au) = cpu->edx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49C1F9u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49C1F9u));
    if (cpu->eax != 0u) goto label_0009BF8B;
    label_0009C201:
    lift_push32(cpu, 2u);
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"s");
    cpu->eax = cpu->esp + 0x50u;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esi + 0x7E74u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x7E78u) = cpu->ebx;
    *(uint16_t*)(cpu->esp + 0x55u) = 0x3030u;
    *(uint8_t*)(cpu->esp + 0x57u) = 0x30u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49C235u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49C235u));
    if (cpu->eax == cpu->ebx) goto label_0009C2DC;
    label_0009C240:
    if (cpu->eax == cpu->ebp) goto label_0009C252;
    cpu->edx = (uintptr_t)"s";
    cpu->ecx = cpu->esp + 0x44u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9C252u)); sfera_sub_0049BA10(cpu, LIFT_CODE_TOKEN_RVA(0x9C252u));
    label_0009C252:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = cpu->eax;
    cpu->ecx <<= 8u;
    cpu->edx = *(uint32_t*)(cpu->ecx + cpu->esi + 0x18E0u);
    *(uint32_t*)(cpu->esi + 0x7E78u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x7E78u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x7E74u);
    *(uint16_t*)(cpu->esi + (cpu->ecx * 2u) + 0x7CE4u) = cpu->eax & 0xFFFFu;
    *(uint32_t*)(cpu->esi + 0x7E74u) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x7E74u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x7E74u);
    cpu->eax = cpu->ecx;
    cpu->edi = 0x64u;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->edi); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    lift_push32(cpu, 2u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((cpu->eax + 0x30u) & 0xFFu);
    *(uint8_t*)(cpu->esp + 0x49u) = cpu->eax & 0xFFu;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x66666667u * (int32_t)(cpu->edx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    *(uint8_t*)(cpu->esp + 0x4Au) = cpu->eax & 0xFFu;
    cpu->eax = cpu->ecx;
    cpu->ecx = 0xAu;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ecx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    cpu->eax = cpu->esp + 0x48u;
    cpu->ecx = cpu->esp + 0x18u;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    *(uint8_t*)(cpu->esp + 0x4Bu) = cpu->edx & 0xFFu;
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"s"); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49C2D4u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49C2D4u));
    if (cpu->eax != cpu->ebx) goto label_0009C240;
    label_0009C2DC:
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi + 0x142Cu;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"nsky1");
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->esi + 0x18DCu) = cpu->ebx;
    *(uint16_t*)(cpu->esp + 0x31u) = 0x3030u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49C304u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49C304u));
    if (cpu->eax == cpu->ebx) goto label_0009C403;
    label_0009C30C:
    if (cpu->eax == cpu->ebp) goto label_0009C31E;
    cpu->edx = (uintptr_t)"nsky1";
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9C31Eu)); sfera_sub_0049BA10(cpu, LIFT_CODE_TOKEN_RVA(0x9C31Eu));
    label_0009C31E:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18DCu);
    cpu->edi = native_function_address32(&::_stricmp);
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->ecx = cpu->esi + (cpu->eax * 8u) + 0x142Cu;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->ecx, (uintptr_t)"none");

    if (cpu->eax != 0u) goto label_0009C353;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18DCu);
    cpu->edx = cpu->eax + (cpu->eax * 4u);
    *(uint8_t*)(cpu->esi + (cpu->edx * 8u) + 0x142Cu) = cpu->ebx & 0xFFu;
    label_0009C353:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18DCu);
    lift_push32(cpu, cpu->ebp);
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->ecx = cpu->esi + (cpu->eax * 8u) + 0x1440u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"nsky2");
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49C378u)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49C378u));
    if (cpu->eax == cpu->ebp) goto label_0009C38A;
    cpu->edx = (uintptr_t)"nsky2";
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9C38Au)); sfera_sub_0049BA10(cpu, LIFT_CODE_TOKEN_RVA(0x9C38Au));
    label_0009C38A:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18DCu);
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->ecx = cpu->esi + (cpu->eax * 8u) + 0x1440u;

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->ecx, (uintptr_t)"none");

    if (cpu->eax != 0u) goto label_0009C3B9;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x18DCu);
    cpu->edx = cpu->eax + (cpu->eax * 4u);
    *(uint8_t*)(cpu->esi + (cpu->edx * 8u) + 0x1440u) = cpu->ebx & 0xFFu;
    label_0009C3B9:
    *(uint32_t*)(cpu->esi + 0x18DCu) = (uint64_t)(*(uint32_t*)(cpu->esi + 0x18DCu)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18DCu);
    cpu->eax = cpu->ecx;
    cpu->edi = 0xAu;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->edi); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    lift_push32(cpu, cpu->ebp);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    *(uint8_t*)(cpu->esp + 0x25u) = cpu->eax & 0xFFu;
    cpu->eax = cpu->ecx + (cpu->ecx * 4u);
    cpu->ecx = cpu->esi + (cpu->eax * 8u) + 0x142Cu;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    lift_push32(cpu, cpu->ecx);
    *(uint8_t*)(cpu->esp + 0x2Au) = cpu->edx & 0xFFu;
    lift_push32(cpu, (uintptr_t)"nsky1");
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49C3FBu)); sfera_sub_00480430(cpu, LIFT_CODE_TOKEN_VA(0x49C3FBu));
    if (cpu->eax != cpu->ebx) goto label_0009C30C;
    label_0009C403:
    cpu->ecx = cpu->esp + 0x14u;
    g_sfera_weather_runtime.interpolation_offsets[0] = 4u;
    g_sfera_weather_runtime.interpolation_offsets[1] = 8u;
    g_sfera_weather_runtime.interpolation_offsets[2] = 0xCu;
    g_sfera_weather_runtime.interpolation_offsets[3] = 0x10u;
    *(uint32_t*)(cpu->esp + 0x58u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49C43Cu)); sfera_sub_00480390(cpu, LIFT_CODE_TOKEN_VA(0x49C43Cu));
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x48u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049C460(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->edx);
    cpu->esi = *(uint16_t*)(cpu->ecx + (cpu->esi * 2u) + 0x7CE4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->esi <<= 8u;
    cpu->ebx = cpu->eax + (cpu->eax * 4u);
    cpu->esi += cpu->ecx;
    cpu->ebx = *(uint32_t*)(cpu->esi + (cpu->ebx * 4u) + 0x1918u);
    cpu->esi = cpu->eax + 1u;
    *(uint32_t*)(cpu->edi) = cpu->esi;
    cpu->eax = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint16_t*)(cpu->ecx + (cpu->eax * 2u) + 0x7CE4u);
    cpu->eax <<= 8u;
    if (cpu->esi != *(uint32_t*)(cpu->eax + cpu->ecx + 0x1914u)) goto label_0009C4EF;
    *(uint32_t*)(cpu->edi) = 0u;
    cpu->esi = *(uint32_t*)(cpu->edx);
    cpu->eax = *(uint16_t*)(cpu->ecx + (cpu->esi * 2u) + 0x7CE4u);
    cpu->eax <<= 8u;
    cpu->eax = *(uint32_t*)(cpu->eax + cpu->ecx + 0x18E0u);
    ++cpu->esi;
    cpu->eax -= cpu->ebx;
    *(uint32_t*)(cpu->edx) = cpu->esi;
    if (cpu->esi != *(uint32_t*)(cpu->ecx + 0x7E74u)) goto label_0009C4CE;
    *(uint32_t*)(cpu->edx) = 0u;
    label_0009C4CE:
    cpu->edx = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint16_t*)(cpu->ecx + (cpu->edx * 2u) + 0x7CE4u);
    cpu->edi = *(uint32_t*)(cpu->edi);
    cpu->edx <<= 8u;
    cpu->esi = cpu->edi + (cpu->edi * 4u);
    cpu->edx += cpu->ecx;
    cpu->eax += *(uint32_t*)(cpu->edx + (cpu->esi * 4u) + 0x1918u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0009C4EF:
    cpu->edx = cpu->esi + (cpu->esi * 4u);
    cpu->eax = cpu->eax + (cpu->edx * 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + cpu->ecx + 0x1918u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax -= cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) double sfera_sub_0049C510(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3;
 double x87_p0, x87_p1;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esi) = 0u;
    cpu->edx = *(uint16_t*)(cpu->ecx + (cpu->ebx * 2u) + 0x7CE4u);
    cpu->edx <<= 8u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->edx + cpu->ecx + 0x1914u);
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    if ((int32_t)cpu->edi <= 0) goto label_0009C568;
    cpu->ebx = cpu->edx + cpu->ecx + 0x1918u;
label_0009C550:
    if ((int32_t)*(uint32_t*)(cpu->ebx) >= (int32_t)cpu->ebp) goto label_0009C620;
    ++cpu->eax;
    cpu->ebx += 0x14u;
    if ((int32_t)cpu->eax < (int32_t)cpu->edi) goto label_0009C550;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
label_0009C568:
    cpu->eax = *(uint32_t*)(cpu->edx + cpu->ecx + 0x18E0u);
    cpu->eax -= cpu->ebp;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    ++cpu->ebx;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if (cpu->ebx != *(uint32_t*)(cpu->ecx + 0x7E74u)) goto label_0009C58C;
    cpu->ebx=0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
label_0009C58C:
    cpu->edx = *(uint16_t*)(cpu->ecx + (cpu->ebx * 2u) + 0x7CE4u);
    cpu->edx <<= 8u;
    cpu->edx = *(uint32_t*)(cpu->edx + cpu->ecx + 0x1918u);
    *(uint32_t*)(cpu->esi) += cpu->edx;
label_0009C5A0:
    cpu->edx = *(uint16_t*)(cpu->ecx + (cpu->ebx * 2u) + 0x7CE4u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx <<= 8u;
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->edx += cpu->edi;
    cpu->edx = cpu->edx + (cpu->eax * 4u);
    *(float*)(cpu->esp + 0x18u) = (double)*(float*)(cpu->edx + cpu->ecx + 0x1918u);
    x87_p0 = 0.0;
    x87_p1 = (double)*(float*)(cpu->esp + 0x18u);
     value_1 = x87_p1; value_2 = x87_p0; { const double lift_left=value_1; const double lift_right=value_2; if (lift_left>=lift_right) { value_0 = value_1; goto label_0009C617; } }
label_0009C5D1:
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49C5E2u)); sfera_sub_0049C460(cpu, LIFT_CODE_TOKEN_VA(0x49C5E2u));
    *(uint32_t*)(cpu->esi) += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint16_t*)(cpu->ecx + (cpu->eax * 2u) + 0x7CE4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx <<= 8u;
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->edx += cpu->edi;
    cpu->edx = cpu->edx + (cpu->eax * 4u);
    *(float*)(cpu->esp + 0x18u) = (double)*(float*)(cpu->edx + cpu->ecx + 0x1918u);
    value_3 = (double)*(float*)(cpu->esp + 0x18u);
    if (!((value_3)>=(value_2))) goto label_0009C5D1; value_0 = value_3;
label_0009C617:
    cpu->edi = lift_pop32(cpu);
     cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return value_0;
label_0009C620:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edi = cpu->eax + (cpu->eax * 4u);
    cpu->edx = cpu->edx + (cpu->edi * 4u);
    cpu->edx = *(uint32_t*)(cpu->edx + cpu->ecx + 0x1918u);
    cpu->edx -= cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esi) = cpu->edx;
    goto label_0009C5A0;
}
__declspec(noinline) void sfera_sub_0049C640(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->esi = *(uint16_t*)(cpu->ecx + (cpu->esi * 2u) + 0x7CE4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->edi);
    cpu->esi <<= 8u;
    cpu->ebx = cpu->edx + (cpu->edx * 4u);
    cpu->esi += cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->esi + (cpu->ebx * 4u) + 0x1918u);
    --cpu->edx;
    *(uint32_t*)(cpu->edi) = cpu->edx;
    if (cpu->edx != 0xFFFFFFFFu) goto label_0009C6BD;
    --*(uint32_t*)(cpu->eax);
    if (*(uint32_t*)(cpu->eax) != cpu->edx) goto label_0009C67D;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x7E74u);
    --cpu->edx;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0009C67D:
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint16_t*)(cpu->ecx + (cpu->edx * 2u) + 0x7CE4u);
    cpu->edx <<= 8u;
    cpu->edx = *(uint32_t*)(cpu->edx + cpu->ecx + 0x1914u);
    --cpu->edx;
    *(uint32_t*)(cpu->edi) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint16_t*)(cpu->ecx + (cpu->eax * 2u) + 0x7CE4u);
    cpu->eax <<= 8u;
    cpu->edx = cpu->edx + (cpu->edx * 4u);
    cpu->edx = cpu->eax + (cpu->edx * 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + cpu->ecx + 0x18E0u);
    cpu->eax -= *(uint32_t*)(cpu->edx + cpu->ecx + 0x1918u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax += cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0009C6BD:
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint16_t*)(cpu->ecx + (cpu->eax * 2u) + 0x7CE4u);
    cpu->eax <<= 8u;
    cpu->eax += cpu->ecx;
    cpu->edx = cpu->edx + (cpu->edx * 4u);
    cpu->esi -= *(uint32_t*)(cpu->eax + (cpu->edx * 4u) + 0x1918u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) double sfera_sub_0049C6E0(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3;
 double x87_p0, x87_p1;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esi) = 0u;
    cpu->edx = *(uint16_t*)(cpu->ecx + (cpu->ebx * 2u) + 0x7CE4u);
    cpu->edx <<= 8u;
    cpu->eax = *(uint32_t*)(cpu->edx + cpu->ecx + 0x1914u);
    --cpu->eax;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    if ((int32_t)(cpu->eax) < 0) goto label_0009C733;
    cpu->ebp = cpu->eax + (cpu->eax * 4u);
    cpu->ebp = cpu->edx + (cpu->ebp * 4u);
    cpu->ebp = cpu->ecx + cpu->ebp + 0x1918u;
label_0009C720:
    if ((int32_t)*(uint32_t*)(cpu->ebp) <= (int32_t)cpu->edi) goto label_0009C7F9;
    cpu->ebp -= 0x14u;
    if ((int32_t)(--cpu->eax) >= 0) goto label_0009C720;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
label_0009C733:
    --cpu->ebx;
    *(uint32_t*)(cpu->esi) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if (cpu->ebx != 0xFFFFFFFFu) goto label_0009C74A;
    cpu->ebx = *(uint32_t*)(cpu->ecx + 0x7E74u);
    --cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
label_0009C74A:
    cpu->edx = *(uint16_t*)(cpu->ecx + (cpu->ebx * 2u) + 0x7CE4u);
    cpu->edx <<= 8u;
    cpu->eax = *(uint32_t*)(cpu->edx + cpu->ecx + 0x1914u);
    --cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->ebp = cpu->edx + cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->edx + cpu->ecx + 0x18E0u);
    cpu->edx -= *(uint32_t*)(cpu->ecx + cpu->ebp + 0x1918u);
    cpu->edx += cpu->edi;
    *(uint32_t*)(cpu->esi) = cpu->edx;
label_0009C77D:
    cpu->edx = *(uint16_t*)(cpu->ecx + (cpu->ebx * 2u) + 0x7CE4u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx <<= 8u;
    cpu->edx += cpu->eax;
    cpu->edx += cpu->edi;
    *(float*)(cpu->esp + 0x18u) = (double)*(float*)(cpu->edx + cpu->ecx + 0x1918u);
    x87_p0 = 0.0;
    x87_p1 = (double)*(float*)(cpu->esp + 0x18u);
     value_1 = x87_p1; value_2 = x87_p0; { const double lift_left=value_1; const double lift_right=value_2; if (lift_left>=lift_right) { value_0 = value_1; goto label_0009C7F0; } }
label_0009C7AA:
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49C7BBu)); sfera_sub_0049C640(cpu, LIFT_CODE_TOKEN_VA(0x49C7BBu));
    *(uint32_t*)(cpu->esi) += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint16_t*)(cpu->ecx + (cpu->eax * 2u) + 0x7CE4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx <<= 8u;
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->edx += cpu->edi;
    cpu->edx = cpu->edx + (cpu->eax * 4u);
    *(float*)(cpu->esp + 0x18u) = (double)*(float*)(cpu->edx + cpu->ecx + 0x1918u);
    value_3 = (double)*(float*)(cpu->esp + 0x18u);
    if (!((value_3)>=(value_2))) goto label_0009C7AA; value_0 = value_3;
label_0009C7F0:
    cpu->edi = lift_pop32(cpu);
     cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return value_0;
label_0009C7F9:
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->edx += cpu->eax;
    cpu->edi -= *(uint32_t*)(cpu->edx + cpu->ecx + 0x1918u);
    *(uint32_t*)(cpu->esi) = cpu->edi;
    goto label_0009C77D;
}
__declspec(noinline) void sfera_sub_0049C820(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = cpu->ecx;
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(*(uint32_t*)(cpu->esi + 0x7E78u)); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    cpu->ebx = 0u;
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    if ((int32_t)*(uint32_t*)(cpu->esi + 0x7E74u) <= (int32_t)cpu->ebx) goto label_0009C8AD;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esi + 0x7CE4u;
    label_0009C850:
    cpu->eax = *(uint16_t*)(cpu->edi);
    if ((int32_t)(cpu->eax) < (int32_t)(*(uint32_t*)(cpu->esi + 0x7CE0u))) goto label_0009C86D;
    cpu->ecx = (uintptr_t)"wScenarioArr[curSN] >= wScenariosNum";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49C865u)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x49C865u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    label_0009C86D:
    cpu->eax = *(uint16_t*)(cpu->edi);
    cpu->eax <<= 8u;
    cpu->eax = *(uint32_t*)(cpu->eax + cpu->esi + 0x18E0u);
    cpu->ebp += cpu->eax;
    if ((int32_t)cpu->edx < (int32_t)cpu->ebp) goto label_0009C894;
    ++cpu->ebx;
    cpu->edi += 2u;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->esi + 0x7E74u)) goto label_0009C850;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_0009C894:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax -= cpu->ebp;
    cpu->eax += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esi) = cpu->ebx;
    *(uint32_t*)(cpu->edx) = cpu->eax;
    cpu->ecx -= cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edi = lift_pop32(cpu);
    label_0009C8AD:
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049C8C0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    lift_push32(cpu, cpu->ecx);
    if (*(uint8_t*)(cpu->esp + 8u) != 0u) goto label_0009C8F0;
    x87_v0 = (double)g_sfera_weather_runtime.direction_sin_component;
    x87_v1 = 0.0;
    x87_v2 = x87_v1;
    { const double lift_left=x87_v2; const double lift_right=x87_v0;  x87_v0=x87_v1;  if (lift_left!=lift_right) goto label_0009C962; }
    x87_v1 = (double)g_sfera_weather_runtime.direction_cos_component;
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (lift_left!=lift_right) goto label_0009C964; }
    label_0009C8F0:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = cpu->eax;
    cpu->ecx = (int32_t)(cpu->ecx) >> 1u;
    cpu->ecx&=7u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 8u))));
    cpu->eax = (int32_t)(cpu->eax) >> 4u;
    cpu->eax &= 3u;
    ++cpu->eax;
    x87_v0 = (x87_v0) * (0.7853982448577881);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    *(float*)(cpu->esp + 8u) = x87_v0; 
    *(float*)(cpu->esp + 0xCu) = (((((((double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu)))))) * (0.25)))) * (0.00019999999494757503));
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp) = x87_v0; 
    g_sfera_weather_runtime.direction_sin_component = ((((double)*(float*)(cpu->esp))) * (((double)*(float*)(cpu->esp + 0xCu))));
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    g_sfera_weather_runtime.direction_cos_component = ((((double)*(float*)(cpu->esp + 8u))) * (((double)*(float*)(cpu->esp + 0xCu))));
    goto label_0009C964;
    label_0009C962:
    x87_v0 = x87_v0; 
    label_0009C964:
    x87_v0 = (double)g_sfera_weather_runtime.direction_sin_component;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)(cpu->edx) = x87_v0; 
    *(float*)(cpu->eax) = (double)g_sfera_weather_runtime.direction_cos_component;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049C980(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    sub_pred[0] = *(uint8_t*)(cpu->eax) == 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (!sub_pred[0]) goto label_0009C9A4;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, 0xACu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x49C998u));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0009C9A4:
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if ((int32_t)cpu->esi >= (int32_t)*(uint32_t*)(cpu->edi + 0x1428u)) goto label_0009CA00;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::_stricmp);
    cpu->ebx = cpu->edi;
    label_0009C9C0:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);

    cpu->eax = reinterpret_cast<uint32_t (__cdecl*)(uint32_t, uint32_t)>(static_cast<uintptr_t>(native_function_address32(&::_stricmp)))(cpu->ebx, cpu->edx);

    if (cpu->eax == 0u) goto label_0009C9DE;
    ++cpu->esi;
    cpu->ebx += 0xACu;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->edi + 0x1428u)) goto label_0009C9C0;
    label_0009C9DE:
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((int32_t)cpu->esi >= (int32_t)*(uint32_t*)(cpu->edi + 0x1428u)) goto label_0009CA00;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0xACu);
    cpu->esi += cpu->edi;
    std::memmove((void*)(*(uint32_t*)(cpu->esp + 0x10u)),(void*)(cpu->esi),172u);
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0009CA00:
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = (uintptr_t)"Sky texture name absent in params. ";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49CA0Eu)); sfera_sub_00459CB0(cpu, LIFT_CODE_TOKEN_VA(0x49CA0Eu));
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049CA20(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1;
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49CA42u)); sfera_sub_0049C820(cpu, LIFT_CODE_TOKEN_VA(0x49CA42u));
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0xCu))));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = *(uint16_t*)(cpu->ebx + (cpu->ecx * 2u) + 0x7CE4u);
    cpu->edx <<= 8u;
    cpu->esi = cpu->edx + cpu->ebx + 0x18E0u;
    x87_v0 = (x87_v0) / ((double)(((int32_t)(*(uint32_t*)(cpu->esi)))));
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    x87_v0 = 1.0;
    x87_v1 = (double)*(float*)(cpu->esp + 0x18u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (!(lift_left>=lift_right)) goto label_0009CA83; }
    cpu->ecx = (uintptr_t)"internal error 98742756";
    x87_v0 = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49CA7Fu)); sfera_sub_00459B10(cpu, LIFT_CODE_TOKEN_VA(0x49CA7Fu));
    x87_v0 = (double)*(float*)(cpu->esp + 0x18u);
    label_0009CA83:
    cpu->ecx = cpu->esi + 4u;
    if (*(uint8_t*)(cpu->esi + 4u) != 0u) goto label_0009CA92;
    if (*(uint8_t*)(cpu->esi + 0x18u) == 0u) goto label_0009CAD7;
    label_0009CA92:
    { const double lift_left=(double)*(float*)(cpu->esi + 0x2Cu); const double lift_right=x87_v0; if (!(lift_left<=lift_right)) goto label_0009CAD7; }
    x87_v1 = (double)*(float*)(cpu->esi + 0x30u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (!(lift_left>=lift_right)) goto label_0009CAD9; }
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = cpu->ecx;
    cpu->edx -= cpu->ecx;
    label_0009CAB2:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0009CAB2;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = cpu->esi + 0x18u;
    cpu->edx -= cpu->eax;
    label_0009CAC5:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    *(uint8_t*)(cpu->edx + cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0009CAC5;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_0009CAD7:
    x87_v0 = x87_v0; 
    label_0009CAD9:
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ecx;
    if ((int32_t)*(uint32_t*)(cpu->ebx + 0x18DCu) <= (int32_t)cpu->ecx) goto label_0009CBDB;
    cpu->eax = cpu->ebx + 0x1440u;
    lift_push32(cpu, cpu->ebp);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    lift_push32(cpu, cpu->edi);
    label_0009CB00:
    cpu->ebp = cpu->eax + 0xFFFFFFECu;
    if (*(uint8_t*)(cpu->eax + 0xFFFFFFECu) != 0u) goto label_0009CB10;
    cpu->ebp = cpu->eax;
    if (*(uint8_t*)(cpu->eax) == 0u) goto label_0009CB72;
    label_0009CB10:
    cpu->esi = 0u;
    if ((int32_t)*(uint32_t*)(cpu->ebx + 0x1428u) <= (int32_t)cpu->esi) goto label_0009CB3E;
    cpu->edi = cpu->ebx;
    label_0009CB20:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x49CB22u));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0009CB4A;
    ++cpu->esi;
    cpu->edi += 0xACu;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->ebx + 0x1428u)) goto label_0009CB20;
    label_0009CB3E:
    cpu->edx = cpu->ebp;
    cpu->ecx = (uintptr_t)"Sky texture name present in para, but absent in params. ";
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9CB4Au)); sfera_sub_00459CB0(cpu, LIFT_CODE_TOKEN_RVA(0x9CB4Au));
    label_0009CB4A:
    x87_v0 = (double)*(float*)(cpu->esp + 0x24u);
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0xACu);
    { const double lift_left=(double)*(float*)(cpu->esi + cpu->ebx + 0x20u); const double lift_right=x87_v0; if (!(lift_left<=lift_right)) goto label_0009CBAF; }
    x87_v1 = (double)*(float*)(cpu->esi + cpu->ebx + 0x24u);
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (!(lift_left>=lift_right)) goto label_0009CBB1; }
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    label_0009CB72:
    if ((int32_t)cpu->ecx >= 0) goto label_0009CB84;
    cpu->ecx = (uintptr_t)&g_sfera_weather_runtime.sky_texture_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49CB80u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_VA(0x49CB80u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    label_0009CB84:
    if ((int32_t)cpu->ecx < (int32_t)g_sfera_weather_runtime.sky_texture_handles.capacity) goto label_0009CB9C;
    cpu->edx = cpu->ecx;
    cpu->ecx = (uintptr_t)&g_sfera_weather_runtime.sky_texture_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49CB98u)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_VA(0x49CB98u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    label_0009CB9C:
    cpu->eax = g_sfera_weather_runtime.sky_texture_handles.data;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->eax + (cpu->ecx * 4u)) = cpu->edx;
    ++cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    goto label_0009CBB5;
    label_0009CBAF:
    x87_v0 = x87_v0; 
    label_0009CBB1:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    label_0009CBB5:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->edx;
    cpu->eax += 0x28u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->edx < (int32_t)*(uint32_t*)(cpu->ebx + 0x18DCu)) goto label_0009CB00;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if (cpu->ecx != 0u) goto label_0009CBF1;
    label_0009CBDB:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    *(uint8_t*)(cpu->ecx) = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_0009CBF1:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ecx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    cpu->esi = cpu->edx;
    if ((int32_t)cpu->esi >= 0) goto label_0009CC08;
    cpu->ecx = (uintptr_t)&g_sfera_weather_runtime.sky_texture_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9CC08u)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x9CC08u));
    label_0009CC08:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_weather_runtime.sky_texture_handles.capacity) goto label_0009CC1C;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_weather_runtime.sky_texture_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9CC1Cu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x9CC1Cu));
    label_0009CC1C:
    cpu->edx = g_sfera_weather_runtime.sky_texture_handles.data;
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->esi * 4u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = cpu->eax + (cpu->eax * 4u);
    cpu->ecx = cpu->ebx + (cpu->eax * 8u) + 0x142Cu;
    label_0009CC33:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0009CC33;
    if ((int32_t)cpu->esi >= 0) goto label_0009CC4B;
    cpu->ecx = (uintptr_t)&g_sfera_weather_runtime.sky_texture_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9CC4Bu)); sfera_sub_004010F0(cpu, LIFT_CODE_TOKEN_RVA(0x9CC4Bu));
    label_0009CC4B:
    if ((int32_t)cpu->esi < (int32_t)g_sfera_weather_runtime.sky_texture_handles.capacity) goto label_0009CC5F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uintptr_t)&g_sfera_weather_runtime.sky_texture_handles.debug_file[0];
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9CC5Fu)); sfera_sub_00401120(cpu, LIFT_CODE_TOKEN_RVA(0x9CC5Fu));
    label_0009CC5F:
    cpu->ecx = g_sfera_weather_runtime.sky_texture_handles.data;
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    cpu->edx = cpu->esi + (cpu->esi * 4u);
    cpu->ecx = cpu->ebx + (cpu->edx * 8u) + 0x1440u;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    label_0009CC76:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->edx) = cpu->eax & 0xFFu;
    ++cpu->ecx;
    ++cpu->edx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_0009CC76;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049CC90(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6, value_7, value_8, value_9;
 bool sub_pred[4]; double x87_p0, x87_p1;
    cpu->esp -= 0x74u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x80u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x7Cu);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ebx;
    if ((int32_t)cpu->eax <= (int32_t)*(uint32_t*)(cpu->ebx + 0x7E7Cu)) goto label_0009CFF6;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->ebx + 0x7E7Cu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49CCE0u)); sfera_sub_0049C820(cpu, LIFT_CODE_TOKEN_VA(0x49CCE0u));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = (uintptr_t)&g_sfera_weather_runtime.interpolation_offsets[0];
    goto label_0009CCF4;
label_0009CCF0:
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
label_0009CCF4:
    cpu->esi = *(uint32_t*)(cpu->edi);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49CD09u)); value_8 = sfera_sub_0049C6E0(cpu, LIFT_CODE_TOKEN_VA(0x49CD09u));
    *(float*)(cpu->esp + 0x14u) = value_8; 
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
     if (cpu->ebx != 0u) goto label_0009CD1B;
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
     value_1 = x87_p0; value_0 = value_1; goto label_0009CD58;
label_0009CD1B:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49CD30u)); value_9 = sfera_sub_0049C510(cpu, LIFT_CODE_TOKEN_VA(0x49CD30u));
    *(float*)(cpu->esp + 0x24u) = value_9; 
    value_2 = (double)*(float*)(cpu->esp + 0x24u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    x87_p0 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->eax += cpu->ebx;
    x87_p1 = x87_p0;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    value_3 = value_2 - x87_p1; 
    x87_p1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    value_4 = value_3 * x87_p1; 
    x87_p1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x24u))));
    value_5 = value_4 / x87_p1; 
    value_6 = value_5 + x87_p0;  value_0 = value_6;
label_0009CD58:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    *(float*)(cpu->esp + 0x14u) = value_0; 
    value_7 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->edi += 4u;
    *(float*)(cpu->esi + cpu->ecx) = value_7; 
     if ((int32_t)cpu->edi < (int32_t)((uintptr_t)&g_sfera_weather_runtime.interpolation_offsets[kWeatherInterpolationOffsetCount])) goto label_0009CCF0;
    x87_p0 = 0.0;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x88u);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->edx);
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->esp + 0x34u;
    *(float*)(cpu->esi + 0x16Cu) = x87_p0; 
    x87_p0 = (double)*(float*)(cpu->esp + 0x90u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp) = x87_p0; 
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49CDA8u)); sfera_sub_0049CA20(cpu, LIFT_CODE_TOKEN_VA(0x49CDA8u));
    if (*(uint8_t*)(cpu->esp + 0x30u) != 0u) goto label_0009CDBA;
    if (*(uint8_t*)(cpu->esp + 0x44u) == 0u) goto label_0009CF99;
label_0009CDBA:
    cpu->edi = cpu->ebx + 1u;
    cpu->ebx += 0x51u;
    if ((int32_t)cpu->edi >= (int32_t)cpu->ebx) goto label_0009CE78;
    cpu->esi = cpu->edi;
    cpu->esi -= *(uint32_t*)(cpu->esp + 0x88u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
label_0009CDD5:
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    cpu->ecx = cpu->esp + 0x6Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x5Cu;
    x87_p0 = (x87_p0) * (0.00017361111531499773);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->esp + 0x98u)));
    *(float*)(cpu->esp + 0x28u) = x87_p0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49CE04u)); sfera_sub_0049CA20(cpu, LIFT_CODE_TOKEN_VA(0x49CE04u));
    cpu->ecx = cpu->esp + 0x58u;
    cpu->eax = cpu->esp + 0x30u;
label_0009CE10:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_0009CE30;
    if ((cpu->edx & 0xFFu) == 0u) goto label_0009CE2C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[0] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_0009CE30;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0009CE10;
label_0009CE2C:
    cpu->eax = 0u;
    goto label_0009CE35;
label_0009CE30:
    cpu->eax = (sub_pred[0]) ? 0xFFFFFFFFu : 1u;
label_0009CE35:
    if (cpu->eax != 0u) goto label_0009CE78;
    cpu->ecx = cpu->esp + 0x6Cu;
    cpu->eax = cpu->esp + 0x44u;
label_0009CE41:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[2] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_0009CE61;
    if ((cpu->edx & 0xFFu) == 0u) goto label_0009CE5D;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[2] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_0009CE61;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0009CE41;
label_0009CE5D:
    cpu->eax = 0u;
    goto label_0009CE66;
label_0009CE61:
    cpu->eax = (sub_pred[2]) ? 0xFFFFFFFFu : 1u;
label_0009CE66:
    if (cpu->eax != 0u) goto label_0009CE78;
    ++cpu->edi;
    ++cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((int32_t)cpu->edi < (int32_t)cpu->ebx) goto label_0009CDD5;
label_0009CE78:
    cpu->edi -= *(uint32_t*)(cpu->esp + 0x88u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x88u);
    cpu->ebp = cpu->edi;
    cpu->ebx = cpu->esi + 0xFFFFFFFFu;
    cpu->edi = cpu->esi + 0xFFFFFFAFu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    if ((int32_t)cpu->ebx <= (int32_t)cpu->edi) goto label_0009CF4F;
    cpu->esi -= cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
label_0009CEA0:
    x87_p0 = (double)*(float*)(cpu->esp + 0x8Cu);
    cpu->eax = cpu->esp + 0x6Cu;
    x87_p1 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x5Cu;
    lift_push32(cpu, cpu->ecx);
    x87_p1 = (x87_p1) * (0.00017361111531499773);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    x87_p0 = x87_p0 - x87_p1; 
    *(float*)(cpu->esp + 0x28u) = x87_p0; 
    *(float*)(cpu->esp) = (double)*(float*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49CED3u)); sfera_sub_0049CA20(cpu, LIFT_CODE_TOKEN_VA(0x49CED3u));
    cpu->ecx = cpu->esp + 0x58u;
    cpu->eax = cpu->esp + 0x30u;
label_0009CEE0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[1] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_0009CF00;
    if ((cpu->edx & 0xFFu) == 0u) goto label_0009CEFC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[1] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_0009CF00;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0009CEE0;
label_0009CEFC:
    cpu->eax = 0u;
    goto label_0009CF05;
label_0009CF00:
    cpu->eax = (sub_pred[1]) ? 0xFFFFFFFFu : 1u;
label_0009CF05:
    if (cpu->eax != 0u) goto label_0009CF48;
    cpu->ecx = cpu->esp + 0x6Cu;
    cpu->eax = cpu->esp + 0x44u;
label_0009CF11:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    sub_pred[3] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx)) goto label_0009CF31;
    if ((cpu->edx & 0xFFu) == 0u) goto label_0009CF2D;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + 1u));
    sub_pred[3] = (uint8_t)(cpu->edx) < *(uint8_t*)(cpu->ecx + 1u);
    if ((uint8_t)(cpu->edx) != *(uint8_t*)(cpu->ecx + 1u)) goto label_0009CF31;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0009CF11;
label_0009CF2D:
    cpu->eax = 0u;
    goto label_0009CF36;
label_0009CF31:
    cpu->eax = (sub_pred[3]) ? 0xFFFFFFFFu : 1u;
label_0009CF36:
    if (cpu->eax != 0u) goto label_0009CF48;
    --cpu->ebx;
    ++cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esi;
    if ((int32_t)cpu->ebx > (int32_t)cpu->edi) goto label_0009CEA0;
label_0009CF48:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x88u);
label_0009CF4F:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edx = cpu->edi + 0x2D0u;
    lift_push32(cpu, cpu->edx);
    cpu->esi -= cpu->ebx;
    cpu->eax = cpu->edi + 0x2CCu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (cpu->esi == 1u);
    cpu->eax = cpu->edx & 0xFFu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49CF7Bu)); sfera_sub_0049C8C0(cpu, LIFT_CODE_TOKEN_VA(0x49CF7Bu));
    if ((int32_t)cpu->esi >= (int32_t)cpu->ebp) goto label_0009CF83;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
label_0009CF83:
    x87_p0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->esi = cpu->edi;
    x87_p0 = (x87_p0) / (81.0);
    *(float*)(cpu->edi + 0x16Cu) = x87_p0; 
label_0009CF99:
    cpu->ecx = cpu->esi + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49CFA9u)); sfera_sub_0049C980(cpu, LIFT_CODE_TOKEN_VA(0x49CFA9u));
    cpu->eax = cpu->esi + 0xC0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49CFBCu)); sfera_sub_0049C980(cpu, LIFT_CODE_TOKEN_VA(0x49CFBCu));
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49CFC1u)); sfera_sub_00457020(cpu, LIFT_CODE_TOKEN_VA(0x49CFC1u));
    if (cpu->eax == 0u) goto label_0009CFF3;
    cpu->edx = cpu->esi + 0x170u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"clouds8");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49CFD8u)); sfera_sub_0049C980(cpu, LIFT_CODE_TOKEN_VA(0x49CFD8u));
    cpu->eax = cpu->esi + 0x21Cu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"clouds8a");
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49CFEBu)); sfera_sub_0049C980(cpu, LIFT_CODE_TOKEN_VA(0x49CFEBu));
    *(float*)(cpu->esi + 0x2C8u) = (double)(1.0);
label_0009CFF3:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
label_0009CFF6:
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x74u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049D010(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x34u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esp + 0xCu) = 0x30u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = LIFT_CALLBACK(sfera_sub_00421F10);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    lift_native_call(cpu, native_function_address32(&::GetModuleHandleA), LIFT_CODE_TOKEN_VA(0x49D033u));
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x34u) = (uintptr_t)"Browser Example";
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ebx;
    lift_native_call(cpu, native_function_address32(&::RegisterClassExA), LIFT_CODE_TOKEN_VA(0x49D05Eu));
    if ((cpu->eax & 0xFFFFu) != 0u) goto label_0009D07E;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0xBu;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, cpu->ecx);
    *(uint8_t*)(cpu->esp + 0xFu) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9D07Eu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0x9D07Eu));
    label_0009D07E:
    g_sfera_browser_window_runtime.class_registered = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049D090(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->esi == 0x201u) goto label_0009D0EE;
    if (cpu->esi == 0x202u) goto label_0009D0EE;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->esi == 0x100u) goto label_0009D0BF;
    if (cpu->esi != 0x101u) goto label_0009D0D3;
    label_0009D0BF:
    if (cpu->ebx != 0x1Bu) goto label_0009D0D3;
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SendMessageA), LIFT_CODE_TOKEN_RVA(0x9D0CDu));
    label_0009D0D3:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = g_sfera_browser_window_runtime.original_window_proc;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::CallWindowProcA), LIFT_CODE_TOKEN_VA(0x49D0E2u));
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_0009D0EE:
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049D100(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    cpu->edi = 0u;
    lift_push32(cpu, 0xFFFFFFEBu); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    lift_native_call(cpu, native_function_address32(&::GetWindowLongA), LIFT_CODE_TOKEN_VA(0x49D11Fu));
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == cpu->edi) goto label_0009D19B;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, address32(&__uuidof(IWebBrowser2))); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x9D13Au));
    if ((int32_t)cpu->eax < 0) goto label_0009D19B;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x48u);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x9D14Fu));
    if ((int32_t)cpu->eax < 0) goto label_0009D19B;
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    if (cpu->eax == cpu->edi) goto label_0009D19F;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, address32(&__uuidof(IHTMLDocument2))); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x9D16Cu));
    if ((int32_t)cpu->eax < 0) goto label_0009D19B;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, address32(&__uuidof(IOleWindow))); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x9D185u));
    if ((int32_t)cpu->eax < 0) goto label_0009D19B;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xCu);
    cpu->esi += 0x20u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x9D199u));
    label_0009D19B:
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    label_0009D19F:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->ecx == cpu->edi) goto label_0009D1B3;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    lift_native_call(cpu, cpu->ecx, LIFT_CODE_TOKEN_RVA(0x9D1ADu));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    label_0009D1B3:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx == cpu->edi) goto label_0009D1C7;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x9D1C1u));
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    label_0009D1C7:
    if (cpu->eax == cpu->edi) goto label_0009D1D3;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x9D1D1u));
    label_0009D1D3:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    sub_pred[0] = cpu->eax == cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_0009D1E5;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x9D1E3u));
    label_0009D1E5:
    cpu->esp += 0x10u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049D1F0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_0009D1F0;
    label_00021B10:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0xFFFFFFEBu); lift_push32(cpu, cpu->ecx);
    cpu->esi = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::GetWindowLongA), LIFT_CODE_TOKEN_VA(0x421B17u));
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 4u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, address32(&__uuidof(IWebBrowser2))); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x21B2Eu));
    if (cpu->eax != 0u) goto label_00021BD8;
    if (cpu->esi > 5u) goto label_00021BCC;
    switch (cpu->esi) {
        case 0u: goto label_00021B48;
        case 1u: goto label_00021B63;
        case 2u: goto label_00021B7E;
        case 3u: goto label_00021B99;
        case 4u: goto label_00021BB4;
        case 5u: goto label_00021BC0;
        default: lift_trap(cpu, 0x421B41u, "resolved jump-table index out of range"); return;
    }
label_00021B48: ;
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x21B52u));
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x21B5Eu));
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00021B63:
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x20u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x21B6Du));
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x21B79u));
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00021B7E:
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x24u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x21B88u));
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x21B94u));
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00021B99:
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x28u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x21BA3u));
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x21BAFu));
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00021BB4:
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x30u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x21BBEu));
    label_00021BC0:
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x38u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x21BCAu));
    label_00021BCC:
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x21BD6u));
    label_00021BD8:
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0009D1F0:
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    cpu->edx = 4u;
    goto label_00021B10;
}
__declspec(noinline) void sfera_sub_0049D200(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49D211u)); sfera_sub_00421A90(cpu, LIFT_CODE_TOKEN_VA(0x49D211u));
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049D220(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x1Cu);
    lift_push32(cpu, 0xFFFFFFEBu);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    lift_native_call(cpu, native_function_address32(&::GetWindowLongA), LIFT_CODE_TOKEN_VA(0x49D247u));
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == cpu->ebx) goto label_0009D2B3;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, address32(&__uuidof(IWebBrowser2))); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x9D262u));
    if ((int32_t)cpu->eax < 0) goto label_0009D2B3;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, address32(&__uuidof(IViewObject2))); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x9D27Bu));
    if ((int32_t)cpu->eax < 0) goto label_0009D2B3;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x30u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edx;
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0xFFFFFFFFu);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xCu);
    lift_native_call(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x9D2B1u));
    label_0009D2B3:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->eax == cpu->ebx) goto label_0009D2C3;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x9D2C1u));
    label_0009D2C3:
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    sub_pred[0] = cpu->eax == cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    if (sub_pred[0]) goto label_0009D2D6;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x9D2D4u));
    label_0009D2D6:
    cpu->esp += 0x1Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049D2F0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esi + 0x38u)|=1u;
    cpu->ebp = *(uint32_t*)(cpu->esi + 0x38u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx & 0xFFFFu;
    cpu->edx = cpu->eax & 0xFFFFu;
    cpu->edi <<= 16u;
    cpu->edi |= cpu->edx;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x20u) == 0u;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->ecx;
    if (!sub_pred[0]) goto label_0009D322;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9D322u)); sfera_sub_0049D100(cpu, LIFT_CODE_TOKEN_RVA(0x9D322u));
    label_0009D322:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    if (cpu->eax == 0u) goto label_0009D346;
    if (*(uint8_t*)(cpu->esi + 0x24u) != 0u) goto label_0009D346;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_0049D090)); lift_push32(cpu, 0xFFFFFFFCu); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetWindowLongA), LIFT_CODE_TOKEN_VA(0x49D337u));
    g_sfera_browser_window_runtime.original_window_proc = cpu->eax;
    *(uint8_t*)(cpu->esi + 0x24u) = 1u;
    label_0009D346:
    cpu->esi = *(uint32_t*)(cpu->esi + 0x20u);
    if (cpu->esi == 0u) goto label_0009D361;
    cpu->eax = g_sfera_browser_window_runtime.original_window_proc;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0x201u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::CallWindowProcA), LIFT_CODE_TOKEN_RVA(0x9D35Bu));
    label_0009D361:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049D370(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esi + 0x38u)&=0xFFFFFFFEu;
    cpu->ebx = *(uint32_t*)(cpu->esi + 0x38u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx & 0xFFFFu;
    cpu->edx = cpu->eax & 0xFFFFu;
    cpu->edi <<= 16u;
    cpu->edi |= cpu->edx;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x20u) == 0u;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->ecx;
    if (!sub_pred[0]) goto label_0009D3A2;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9D3A2u)); sfera_sub_0049D100(cpu, LIFT_CODE_TOKEN_RVA(0x9D3A2u));
    label_0009D3A2:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    if (cpu->eax == 0u) goto label_0009D3C6;
    if (*(uint8_t*)(cpu->esi + 0x24u) != 0u) goto label_0009D3C6;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_0049D090)); lift_push32(cpu, 0xFFFFFFFCu); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetWindowLongA), LIFT_CODE_TOKEN_VA(0x49D3B7u));
    g_sfera_browser_window_runtime.original_window_proc = cpu->eax;
    *(uint8_t*)(cpu->esi + 0x24u) = 1u;
    label_0009D3C6:
    cpu->esi = *(uint32_t*)(cpu->esi + 0x20u);
    if (cpu->esi == 0u) goto label_0009D3E1;
    cpu->eax = g_sfera_browser_window_runtime.original_window_proc;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x202u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::CallWindowProcA), LIFT_CODE_TOKEN_RVA(0x9D3DBu));
    label_0009D3E1:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049D3F0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    if (*(uint32_t*)(cpu->esi + 0x28u) != cpu->eax) goto label_0009D405;
    if (*(uint32_t*)(cpu->esi + 0x2Cu) == cpu->ecx) goto label_0009D466;
    label_0009D405:
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx & 0xFFFFu;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->eax;
    cpu->eax = cpu->eax & 0xFFFFu;
    cpu->edi <<= 16u;
    cpu->edi |= cpu->eax;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x20u) == 0u;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->ecx;
    if (!sub_pred[0]) goto label_0009D424;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9D424u)); sfera_sub_0049D100(cpu, LIFT_CODE_TOKEN_RVA(0x9D424u));
    label_0009D424:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    if (cpu->eax == 0u) goto label_0009D448;
    if (*(uint8_t*)(cpu->esi + 0x24u) != 0u) goto label_0009D448;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_0049D090)); lift_push32(cpu, 0xFFFFFFFCu); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetWindowLongA), LIFT_CODE_TOKEN_VA(0x49D439u));
    g_sfera_browser_window_runtime.original_window_proc = cpu->eax;
    *(uint8_t*)(cpu->esi + 0x24u) = 1u;
    label_0009D448:
    cpu->esi = *(uint32_t*)(cpu->esi + 0x20u);
    if (cpu->esi == 0u) goto label_0009D465;
    cpu->ecx = g_sfera_browser_window_runtime.original_window_proc;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u); lift_push32(cpu, 0x200u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::CallWindowProcA), LIFT_CODE_TOKEN_RVA(0x9D45Fu));
    label_0009D465:
    cpu->edi = lift_pop32(cpu);
    label_0009D466:
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049D470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->eax;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    cpu->eax = cpu->esp + 0xCu;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    cpu->ecx = g_sfera_window_runtime.main_window;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ClientToScreen), LIFT_CODE_TOKEN_VA(0x49D49Au));
    cpu->edi = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint32_t*)(cpu->esi + 0x20u) != 0u) goto label_0009D4B5;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9D4B5u)); sfera_sub_0049D100(cpu, LIFT_CODE_TOKEN_RVA(0x9D4B5u));
    label_0009D4B5:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x20u);
    if (cpu->eax == 0u) goto label_0009D4D9;
    if (*(uint8_t*)(cpu->esi + 0x24u) != 0u) goto label_0009D4D9;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_0049D090)); lift_push32(cpu, 0xFFFFFFFCu); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetWindowLongA), LIFT_CODE_TOKEN_VA(0x49D4CAu));
    g_sfera_browser_window_runtime.original_window_proc = cpu->eax;
    *(uint8_t*)(cpu->esi + 0x24u) = 1u;
    label_0009D4D9:
    cpu->esi = *(uint32_t*)(cpu->esi + 0x20u);
    if (cpu->esi==0u) goto label_0009D516;
    cpu->edx = cpu->ebx & 0xFFFFu;
    cpu->edx <<= 16u;
    cpu->eax = cpu->edi & 0xFFFFu;
    cpu->edx|=cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = cpu->eax;
    cpu->ecx <<= 4u;
    cpu->ecx -= cpu->eax;
    cpu->eax = g_sfera_browser_window_runtime.original_window_proc;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    cpu->edx = cpu->ecx & 0xFFFFu;
    cpu->edx <<= 16u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x20Au); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::CallWindowProcA), LIFT_CODE_TOKEN_RVA(0x9D510u));
    label_0009D516:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049D520(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::SetFocus), LIFT_CODE_TOKEN_VA(0x49D529u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::DestroyWindow), LIFT_CODE_TOKEN_VA(0x49D533u));
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_0009D54A;
    cpu->edx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49D547u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49D547u));
    cpu->esp += 4u;
    label_0009D54A:
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    *(uint8_t*)(cpu->esi) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049D560(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = cpu->esi;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->eax + 1u;
    label_0009D570:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_0009D570;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49D580u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x49D580u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049D590(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->edx;
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = cpu->eax + 1u;
    label_0009D5A0:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_0009D5A0;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49D5B2u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x49D5B2u));
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_0009D5C7;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49D5C2u)); sfera_sub_00421C00(cpu, LIFT_CODE_TOKEN_VA(0x49D5C2u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0009D5C7:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1Cu);
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49D5D1u)); sfera_sub_00421C00(cpu, LIFT_CODE_TOKEN_VA(0x49D5D1u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049D5E0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esi + 0x20u) = cpu->ebx;
    *(uint8_t*)(cpu->esi + 0x24u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esi + 0x28u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x2Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x30u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x34u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x38u) = cpu->ebx;
    if (g_sfera_browser_window_runtime.class_registered != (cpu->ebx & 0xFFu)) goto label_0009D610;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9D610u)); sfera_sub_0049D010(cpu, LIFT_CODE_TOKEN_RVA(0x9D610u));
    label_0009D610:
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::GetModuleHandleA), LIFT_CODE_TOKEN_VA(0x49D612u));
    cpu->edx = g_sfera_window_runtime.main_window;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x40000000u); lift_push32(cpu, (uintptr_t)"");
    lift_push32(cpu, (uintptr_t)"Browser Example"); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::CreateWindowExA), LIFT_CODE_TOKEN_VA(0x49D63Bu));
    *(uint32_t*)(cpu->esi + 0x1Cu) = cpu->eax;
    if (cpu->eax != cpu->ebx) goto label_0009D65D;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x14u;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, cpu->edx);
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9D65Du)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0x9D65Du));
    label_0009D65D:
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->eax = cpu->edx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->eax + 1u;
    label_0009D667:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0009D667;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49D679u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x49D679u));
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x14u) < 0x10u;
    cpu->edi = lift_pop32(cpu);
    if (sub_pred[0]) goto label_0009D68F;
    cpu->edx = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49D68Au)); sfera_sub_00421C00(cpu, LIFT_CODE_TOKEN_VA(0x49D68Au));
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0009D68F:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x1Cu);
    cpu->edx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49D699u)); sfera_sub_00421C00(cpu, LIFT_CODE_TOKEN_VA(0x49D699u));
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049D6A0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49D6F0u)); sfera_sub_0049D5E0(cpu, LIFT_CODE_TOKEN_VA(0x49D6F0u));
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049D710(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->esi;
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    *(uint8_t*)(cpu->esi) = cpu->eax & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->eax + 0x34u);
    cpu->edx = *(uint32_t*)(cpu->eax + 0x30u);
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_0009D75C;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0009D75C:
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49D766u)); sfera_sub_0049D5E0(cpu, LIFT_CODE_TOKEN_VA(0x49D766u));
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049D780(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    x87_v0 = 0.0;
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esi) = 0u;
    *(uint32_t*)(cpu->edx) = 0u;
    *(float*)(cpu->edi) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0xCu);
    cpu->ecx = 0u;
    x87_v1 = 1.0;
    label_0009D7A6:
    *(float*)(cpu->esp + 0x14u) = (double)sfera_zoning_lower_bound(cpu->ecx);
    if (cpu->ecx != 7u) goto label_0009D7BC;
    *(float*)(cpu->esp + 0x10u) = x87_v1;
    goto label_0009D7C7;
    label_0009D7BC:
    *(float*)(cpu->esp + 0x10u) = (double)sfera_zoning_upper_bound(cpu->ecx);
    label_0009D7C7:
    x87_v2 = (double)*(float*)(cpu->esp + 0x14u);
    { const double lift_left=x87_v2; const double lift_right=x87_v0; if (!(lift_left<=lift_right)) goto label_0009D7E3; }
    x87_v3 = (double)*(float*)(cpu->esp + 0x10u);
    { const double lift_left=x87_v3; const double lift_right=x87_v0; if (lift_left>=lift_right) goto label_0009D7F4; }
    x87_v2 = x87_v3; 
    label_0009D7E3:
    ++cpu->ecx;
    x87_v2 = x87_v2; 
    if ((int32_t)cpu->ecx < (int32_t)8u) goto label_0009D7A6;
    x87_v0 = x87_v1; 
    cpu->edi = lift_pop32(cpu);
    x87_v0 = x87_v0; 
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_0009D7F4:
    cpu->eax = cpu->ecx + 1u;
    x87_v1 = x87_v3; 
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    *(uint32_t*)(cpu->edx) = cpu->eax;
    if (cpu->ecx != 7u) goto label_0009D808;
    *(uint32_t*)(cpu->edx) = 0u;
    label_0009D808:
    x87_v3 = x87_v2;
    x87_v0 = x87_v0 - x87_v3; 
    x87_v1 = x87_v1 - x87_v2; 
    x87_v0 = x87_v0 / x87_v1; 
    *(float*)(cpu->edi) = x87_v0; 
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049D820(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    x87_v0 = (double)*(float*)(cpu->eax + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    *(float*)(cpu->ecx) = x87_v0; 
    lift_push32(cpu, cpu->esi);
    x87_v0 = (double)*(float*)(cpu->eax + 0x20u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0xCu);
    *(float*)(cpu->ecx + 4u) = x87_v0; 
    cpu->edx = cpu->edx + (cpu->edx * 2u);
    x87_v0 = (double)*(float*)(cpu->eax + 0x24u);
    cpu->edx = cpu->eax + (cpu->edx * 4u);
    *(float*)(cpu->ecx + 8u) = x87_v0; 
    cpu->esi = cpu->esi + (cpu->esi * 2u);
    x87_v0 = (double)*(float*)(cpu->edx + 0x28u);
    cpu->eax = cpu->eax + (cpu->esi * 4u);
    x87_v0 = (x87_v0) - (((double)*(float*)(cpu->eax + 0x28u)));
    cpu->esi = lift_pop32(cpu);
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u); x87_v2 = x87_v1;
    x87_v0 = x87_v0 * x87_v2; 
    x87_v2 = (double)*(float*)(cpu->eax + 0x28u);
    x87_v0 = x87_v0 + x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->ecx + 0xCu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edx + 0x2Cu);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax + 0x2Cu)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->eax + 0x2Cu)));
    *(float*)(cpu->ecx + 0x10u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edx + 0x30u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax + 0x30u)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->eax + 0x30u)));
    *(float*)(cpu->ecx + 0x14u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edx + 0x88u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax + 0x88u)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->eax + 0x88u)));
    *(float*)(cpu->ecx + 0x18u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edx + 0x8Cu);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax + 0x8Cu)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->eax + 0x8Cu)));
    *(float*)(cpu->ecx + 0x1Cu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edx + 0x90u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax + 0x90u)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->eax + 0x90u)));
    *(float*)(cpu->ecx + 0x20u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edx + 0xE8u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax + 0xE8u)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->eax + 0xE8u)));
    *(float*)(cpu->ecx + 0x24u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edx + 0xECu);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax + 0xECu)));
    x87_v1 = (x87_v1) * (x87_v0);
    x87_v1 = (x87_v1) + (((double)*(float*)(cpu->eax + 0xECu)));
    *(float*)(cpu->ecx + 0x28u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->edx + 0xF0u);
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->eax + 0xF0u)));
    x87_v0 = x87_v0 * x87_v1; 
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->eax + 0xF0u)));
    *(float*)(cpu->ecx + 0x2Cu) = x87_v0; 
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) double sfera_sub_0049D910(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2, value_3, value_4, value_5, value_6, value_7, value_8, value_9, value_10, value_11, value_12, value_13, value_14, value_15, value_16, value_17;
 double x87_p0, x87_p1, x87_p2;
    x87_p0 = (double)*(float*)(cpu->esp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    x87_p1 = x87_p0;
    x87_p2 = (double)*(float*)(cpu->ecx + 8u);
    x87_p2 = (x87_p2) + (((double)*(float*)(cpu->ecx)));
    x87_p1 = x87_p1 - x87_p2; 
    *(float*)(cpu->esp + 4u) = x87_p1; 
    x87_p1 = 0.0;
    x87_p2 = (double)*(float*)(cpu->esp + 4u);
     value_3 = x87_p2; value_4 = x87_p1; value_5 = x87_p0; if ((value_3)<(value_4)) goto label_0009D957;
    x87_p0 = (double)*(float*)(cpu->esp + 8u); x87_p1 = x87_p0;
    x87_p2 = (double)*(float*)(cpu->ecx + 0x10u);
    x87_p2 = (x87_p2) + (((double)*(float*)(cpu->ecx + 4u)));
    x87_p1 = x87_p1 - x87_p2; 
    *(float*)(cpu->esp + 4u) = x87_p1; 
    x87_p1 = (double)*(float*)(cpu->esp + 4u);
     value_6 = x87_p1; value_7 = x87_p0; if (!((value_6)<(value_4))) goto label_0009D95E;
label_0009D957:
     cpu->esp += 0x10u; cpu->eip = stop_address; return value_4;
label_0009D95E:
    x87_p0 = (double)*(float*)(cpu->ecx + 0xCu);
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->ecx)));
    value_8 = x87_p0 - value_5; 
    *(float*)(cpu->esp + 4u) = value_8; 
    value_9 = (double)*(float*)(cpu->esp + 4u);
    if (!((value_9)<(value_4))) goto label_0009D983;
     cpu->esp += 0x10u; cpu->eip = stop_address; return value_4;
label_0009D983:
    x87_p0 = (double)*(float*)(cpu->ecx + 0x14u);
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->ecx + 4u)));
    value_10 = x87_p0 - value_7; 
    *(float*)(cpu->esp + 4u) = value_10; 
    value_11 = (double)*(float*)(cpu->esp + 4u);
    if (!((value_11)<(value_4))) goto label_0009D9A9;
     cpu->esp += 0x10u; cpu->eip = stop_address; return value_4;
label_0009D9A9:
     if (!((value_3)<(value_6))) goto label_0009D9BA;
     value_0 = value_3; goto label_0009D9BC;
label_0009D9BA:
      value_0 = value_6;
label_0009D9BC:
    *(float*)(cpu->esp + 4u) = value_0; 
    value_12 = (double)*(float*)(cpu->esp + 4u);
    if ((value_12)<(value_9)) goto label_0009D9F2;
    *(float*)(cpu->esp + 4u) = value_9; 
    value_13 = (double)*(float*)(cpu->esp + 4u);
      value_1 = value_13;
label_0009D9DD:
    if ((value_11)>(value_1)) goto label_0009D9F6;
    *(float*)(cpu->esp + 4u) = value_11; 
    value_14 = (double)*(float*)(cpu->esp + 4u);
     value_2 = value_14; goto label_0009D9F8;
label_0009D9F2:
     value_1 = value_12; goto label_0009D9DD;
label_0009D9F6:
      value_2 = value_1;
label_0009D9F8:
    if (!(((double)*(float*)(cpu->ecx + 0x18u))<=(value_2))) goto label_0009DA0B;
    value_15 = 1.0;
    cpu->esp += 0x10u; cpu->eip = stop_address; return value_15;
label_0009DA0B:
    value_16 = (value_2) / (((double)*(float*)(cpu->ecx + 0x18u)));
    *(float*)(cpu->esp + 4u) = value_16; 
    value_17 = (double)*(float*)(cpu->esp + 4u);
    cpu->esp += 0x10u; cpu->eip = stop_address; return value_17;
}
__declspec(noinline) void sfera_sub_0049DA20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx -= cpu->esi;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x63E7063Fu * (int32_t)(cpu->ecx))) >> 32u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edx = (int32_t)(cpu->edx) >> 7u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x148u);
    cpu->eax = cpu->eax + cpu->esi + 0xFFFFFEB8u;
    *(uint32_t*)(cpu->eax + 0xE8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 0xECu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax + 0xF0u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xCu);
    cpu->esi = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 0x88u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 0x8Cu) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->eax + 0x90u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 0xF4u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 0xF8u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax + 0xFCu) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 0x94u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 0x98u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->eax + 0x9Cu) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 0x100u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 0x104u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax + 0x108u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 0xA0u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 0xA4u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->eax + 0xA8u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 0x10Cu) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 0x110u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax + 0x114u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 0xACu) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 0xB0u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->eax + 0xB4u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 0x118u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 0x11Cu) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax + 0x120u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 0xB8u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 0xBCu) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->eax + 0xC0u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 0x124u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 0x128u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax + 0x12Cu) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 0xC4u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 0xC8u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->eax + 0xCCu) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 0x130u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 0x134u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax + 0x138u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 0xD0u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 0xD4u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->eax + 0xD8u) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax + 0x13Cu) = cpu->esi;
    cpu->esi = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->eax + 0x140u) = cpu->esi;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->eax + 0x144u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax + 0xDCu) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->eax + 0xE0u) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->eax + 0xE4u) = cpu->edx;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049DC00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = 0u;
    if (cpu->ecx == 0u) goto label_0009DC56;
    if (cpu->ecx > 0xC7CE0Cu) goto label_0009DC28;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x148u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DC21u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x49DC21u));
    cpu->esp += 4u;
    if (cpu->eax != 0u) goto label_0009DC56;
    label_0009DC28:
    cpu->eax = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 4u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9DC56u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_RVA(0x9DC56u));
    label_0009DC56:
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049DC60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if (cpu->ecx == cpu->edx) goto label_0009DC91;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    label_0009DC70:
    if (cpu->eax == 0u) goto label_0009DC7F;
    cpu->esi = cpu->ebx;
    cpu->edi = cpu->eax;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),328u); cpu->esi += 328u; cpu->edi += 328u; cpu->ecx = 0u;
    label_0009DC7F:
    cpu->ebx += 0x148u;
    cpu->eax += 0x148u;
    if (cpu->ebx != cpu->edx) goto label_0009DC70;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0009DC91:
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049DCA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if (cpu->ecx == cpu->edx) goto label_0009DCC9;
    lift_push32(cpu, cpu->esi);
    label_0009DCB0:
    if (cpu->eax == 0u) goto label_0009DCBE;
    cpu->esi = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    *(float*)(cpu->eax + 4u) = (double)*(float*)(cpu->ecx + 4u);
    label_0009DCBE:
    cpu->ecx += 8u;
    cpu->eax += 8u;
    if (cpu->ecx != cpu->edx) goto label_0009DCB0;
    cpu->esi = lift_pop32(cpu);
    label_0009DCC9:
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049DCD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    cpu->esi = cpu->ecx;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    if (cpu->ebx <= 0xC7CE0Cu) goto label_0009DD13;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x49DCD0u), "std::length_error");
    label_0009DD13:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx -= *(uint32_t*)(cpu->esi);
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x63E7063Fu * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 7u;
    cpu->eax = cpu->edx;
    cpu->eax >>= 31u;
    cpu->eax += cpu->edx;
    if (cpu->eax >= cpu->ebx) goto label_0009DD97;
    cpu->edi = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DD38u)); sfera_sub_0049DC00(cpu, LIFT_CODE_TOKEN_VA(0x49DD38u));
    cpu->ebx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DD54u)); sfera_sub_0049DC60(cpu, LIFT_CODE_TOKEN_VA(0x49DD54u));
    cpu->ebx = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx -= cpu->ebx;
    cpu->edx = (uint32_t)(((uint64_t)((int64_t)(int32_t)0x63E7063Fu * (int32_t)(cpu->ecx))) >> 32u);
    cpu->edx = (int32_t)(cpu->edx) >> 7u;
    cpu->edi = cpu->edx;
    cpu->edi >>= 31u;
    cpu->edi += cpu->edx;
    if (cpu->ebx == 0u) goto label_0009DD79;
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DD76u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49DD76u));
    cpu->esp += 4u;
    label_0009DD79:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x148u);
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x148u);
    cpu->eax += cpu->ecx;
    cpu->edi += cpu->ecx;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    label_0009DD97:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0049DDAB(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DDB4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49DDB4u));
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DDC0u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x49DDC0u));
    lift_trap(cpu, 0x49DDC0u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0049DE83(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DE8Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49DE8Cu));
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DE98u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x49DE98u));
    lift_trap(cpu, 0x49DE98u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0049DEA0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_0009DEA0;
    label_0009DDD0:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    if (cpu->eax <= 0x1FFFFFFFu) goto label_0009DE12;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x49DDD0u), "std::length_error");
    label_0009DE12:
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx -= *(uint32_t*)(cpu->esi);
    cpu->ecx = (int32_t)(cpu->ecx) >> 3u;
    if (cpu->ecx >= cpu->eax) goto label_0009DE6F;
    cpu->edi = cpu->esi + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DE29u)); sfera_sub_00402BB0(cpu, LIFT_CODE_TOKEN_VA(0x49DE29u));
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->esi);
    cpu->ebx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->ebx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DE47u)); sfera_sub_0049DCA0(cpu, LIFT_CODE_TOKEN_VA(0x49DE47u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edi = *(uint32_t*)(cpu->esi + 4u);
    cpu->edi -= cpu->eax;
    cpu->edi = (int32_t)(cpu->edi) >> 3u;
    if (cpu->eax == 0u) goto label_0009DE5E;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49DE5Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49DE5Bu));
    cpu->esp += 4u;
    label_0009DE5E:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->edx = cpu->ebx + (cpu->ecx * 8u);
    cpu->eax = cpu->ebx + (cpu->edi * 8u);
    *(uint32_t*)(cpu->esi + 8u) = cpu->edx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    *(uint32_t*)(cpu->esi) = cpu->ebx;
    label_0009DE6F:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0009DEA0:
    cpu->eax = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->edi);
    cpu->eax -= cpu->esi;
    cpu->edi = 0x1FFFFFFFu;
    cpu->eax = (int32_t)(cpu->eax) >> 3u;
    cpu->edi -= cpu->edx;
    if (cpu->edi >= cpu->eax) goto label_0009DEC6;
    lift_push32(cpu, (uintptr_t)"vector<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x49DEA0u), "std::length_error");
    label_0009DEC6:
    cpu->eax += cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx -= cpu->esi;
    cpu->edx = (int32_t)(cpu->edx) >> 3u;
    if (cpu->eax <= cpu->edx) goto label_0009DEFA;
    cpu->esi = cpu->edx;
    cpu->esi >>= 1u;
    cpu->edi = 0x1FFFFFFFu;
    cpu->edi -= cpu->esi;
    if (cpu->edi >= cpu->edx) goto label_0009DEE7;
    cpu->edx = 0u;
    goto label_0009DEE9;
    label_0009DEE7:
    cpu->edx += cpu->esi;
    label_0009DEE9:
    if (cpu->edx >= cpu->eax) goto label_0009DEEF;
    cpu->edx = cpu->eax;
    label_0009DEEF:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esp + 4u) = cpu->edx;
    goto label_0009DDD0;
    label_0009DEFA:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

} // namespace lifted
