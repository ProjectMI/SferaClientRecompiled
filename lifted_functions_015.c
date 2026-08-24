#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>

static uint32_t sfera_texture_time_key_digit(uint32_t index) { const char* key = "05185514038799035566164306887187530785282430311941"; return index < 50u ? (uint32_t)(key[index] - '0') : 0u; }
static float sfera_zoning_lower_bound(uint32_t band) { switch (band) { case 0u: return 0.0f; case 1u: return 0.19f; case 2u: return 0.27f; case 3u: return 0.34f; case 4u: return 0.50f; case 5u: return 0.66f; case 6u: return 0.73f; default: return 0.81f; } }
static float sfera_zoning_upper_bound(uint32_t band) { return band == 7u ? 1.0f : sfera_zoning_lower_bound(band + 1u); }

LIFT_ENTRY void LIFT_CDECL sfera_sub_00494A10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x494A10u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x44u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = lift_load32(cpu->esp + 0x54u);
    cpu->ebp = cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x28u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494A55u); lift_push32(cpu, r); sfera_sub_00480380(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store32(cpu->esp + 0x50u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x94A65u); lift_push32(cpu, r); sfera_sub_004803B0(cpu,r); if (cpu->eip != r) return; }
    label_00094A65: cpu->eip = LIFT_CODE_TOKEN_VA(0x494A65u);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(0xBu)) goto label_00094ACA;
    if ((int32_t)(uint32_t)(cpu->ebx) >= (int32_t)(uint32_t)(0xAu)) goto label_00094A7C;
    cpu->eax = (uint32_t)(cpu->ebx + 0x30u);
    lift_store8(cpu->esp + 0x1Bu, cpu->eax & 0xFFu);
    goto label_00094A83;
    label_00094A7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x494A7Cu);
    cpu->eax = (uint32_t)(cpu->ebx + 0x57u);
    lift_store8(cpu->esp + 0x1Bu, cpu->eax & 0xFFu);
    label_00094A83: cpu->eip = LIFT_CODE_TOKEN_VA(0x494A83u);
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x3063)) & 0xFFFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_store16(cpu->esp + 0x2Cu, cpu->ecx & 0xFFFFu);
    lift_push32(cpu, 2u);
    lift_store8(cpu->esp + 0x31u, cpu->eax & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"r");
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_store8(cpu->esp + 0x3Eu, cpu->edx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494AB7u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009500A;
    if ((uint32_t)(cpu->eax) != (uint32_t)(2u)) goto label_00094B52;
    goto label_00094B44;
    label_00094ACA: cpu->eip = LIFT_CODE_TOKEN_VA(0x494ACAu);
    lift_push32(cpu, 2u);
    cpu->edx = (uint32_t)(cpu->ebp + 0x1028u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"n"); lift_push32(cpu, (uintptr_t)"SunsetStateN");
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494AE6u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00094B44;
    lift_push32(cpu, 2u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x102Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"n"); lift_push32(cpu, (uintptr_t)"SunriseStateN");
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494B07u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00094B44;
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x4Cu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494B1Du); lift_push32(cpu, r); sfera_sub_00480390(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->ebp;
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x3Cu;
    lift_return(cpu, 4u, stop_address); return;
    label_00094B40: cpu->eip = LIFT_CODE_TOKEN_VA(0x494B40u);
    cpu->ebp = lift_load32(cpu->esp + 0x28u);
    label_00094B44: cpu->eip = LIFT_CODE_TOKEN_VA(0x494B44u);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    cpu->ecx = (uint32_t)(uintptr_t)"Illegal format of Sky.txt, line: ";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x94B52u); lift_push32(cpu, r); sfera_sub_00459CB0(cpu,r); if (cpu->eip != r) return; }
    label_00094B52: cpu->eip = LIFT_CODE_TOKEN_VA(0x494B52u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x1Bu)) & 0xFFu);
    lift_store32(cpu->esp + 0x2Cu, 0x303061u);
    cpu->ebx = 0u;
    lift_store8(cpu->esp + 0x2Du, cpu->ecx & 0xFFu);
    cpu->edi = 0u;
    label_00094B66: cpu->eip = LIFT_CODE_TOKEN_VA(0x494B66u);
    lift_push32(cpu, 2u);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"r");
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    cpu->edx = (uint32_t)(cpu->ebx + 0x30u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_store8(cpu->esp + 0x3Eu, cpu->edx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494B87u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00094B44;
    cpu->esi = lift_load32(cpu->esp + 0x24u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0x178u);
    lift_push32(cpu, 2u);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"g");
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    cpu->esi += cpu->edi;
    lift_push32(cpu, cpu->ecx);
    cpu->esi += cpu->ebp;
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494BBAu); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00094B44;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_push32(cpu, 2u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"b");
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494BE0u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00094B44;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_push32(cpu, 2u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"a");
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494C0Au); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00094B44;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"p");
    lift_store_f32(cpu->esi + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494C34u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00094B44;
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x5Eu);
    cpu->edx += cpu->ebx;
    cpu->edi += 0x10u;
    ++cpu->ebx;
    lift_store_f32(cpu->ebp + ((uint32_t)(cpu->edx) * 4u) + 0xA0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(0xA0u)) goto label_00094B66;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x1Bu)) & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x2Cu, 0x303062u);
    lift_store8(cpu->esp + 0x2Du, cpu->eax & 0xFFu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ebp = cpu->eax;
    cpu->ebx = 0u;
    cpu->ebp = (int64_t)(int32_t)(cpu->ebp) * (int64_t)(int32_t)(0x5Eu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x178u);
    cpu->edi = (uint32_t)(cpu->eax + cpu->ecx);
    cpu->esi = (uint32_t)(cpu->edi + 0xDCu);
    (void)cpu;
    label_00094C90: cpu->eip = LIFT_CODE_TOKEN_VA(0x494C90u);
    lift_push32(cpu, 2u);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"r");
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    cpu->edx = (uint32_t)(cpu->ebx + 0x30u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_store8(cpu->esp + 0x3Eu, cpu->edx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494CB1u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00094B40;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_push32(cpu, 2u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"g");
    lift_store_f32(cpu->esi + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494CDBu); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00094B40;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_push32(cpu, 2u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"b");
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494D04u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00094B40;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_push32(cpu, 2u);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"a");
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494D2Eu); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00094B40;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"p");
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494D58u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00094B40;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->ecx = (uint32_t)(cpu->ebx + cpu->ebp);
    ++cpu->ebx;
    lift_store_f32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u) + 0x138u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi += 0x10u;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(6u)) goto label_00094C90;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x3063)) & 0xFFFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x1Bu)) & 0xFFu);
    lift_store16(cpu->esp + 0x2Cu, cpu->eax & 0xFFFFu);
    lift_push32(cpu, 2u);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    lift_store8(cpu->esp + 0x36u, cpu->ecx & 0xFFu);
    lift_push32(cpu, (uint32_t)(uintptr_t)"r");
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_store8(cpu->esp + 0x3Du, cpu->edx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494DB7u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00094B40;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_push32(cpu, 2u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"g");
    lift_store_f32(cpu->edi + 0xC8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494DE4u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00094B40;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_push32(cpu, 2u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"b");
    lift_store_f32(cpu->edi + 0xCCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494E11u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00094B40;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_push32(cpu, 2u);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"a");
    lift_store_f32(cpu->edi + 0xD0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494E3Eu); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00094B40;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x1Bu)) & 0xFFu);
    lift_push32(cpu, 0u);
    lift_store_f32(cpu->edi + 0xD4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16((uint32_t)(uintptr_t)"d0")) & 0xFFFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"d0") + 2u)) & 0xFFu);
    lift_store16(cpu->esp + 0x30u, cpu->edx & 0xFFFFu);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    lift_store8(cpu->esp + 0x36u, cpu->eax & 0xFFu);
    lift_push32(cpu, (uint32_t)(uintptr_t)"time");
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    lift_store8(cpu->esp + 0x39u, cpu->ecx & 0xFFu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494E88u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00094B40;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store_f32(cpu->edi + 0x150u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"sun");
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494EB5u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00094B40;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_push32(cpu, 2u);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_store_f32(cpu->edi + 0x154u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"sr");
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494EE2u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00094B40;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_push32(cpu, 2u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"sg");
    lift_store_f32(cpu->edi + 0x158u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494F0Fu); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00094B40;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_push32(cpu, 2u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"sb");
    lift_store_f32(cpu->edi + 0x15Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494F3Cu); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00094B40;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_push32(cpu, 2u);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"ar");
    lift_store_f32(cpu->edi + 0x160u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494F69u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00094B40;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_push32(cpu, 2u);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"ag");
    lift_store_f32(cpu->edi + 0x168u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494F96u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00094B40;
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_push32(cpu, 2u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"ab");
    lift_store_f32(cpu->edi + 0x16Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494FC3u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_00094B40;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x178u);
    cpu->ebx = lift_load32(cpu->esp + 0x24u);
    cpu->ebp = lift_load32(cpu->esp + 0x28u);
    lift_store_f32(cpu->eax + cpu->ecx + 0x170u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16((uint32_t)(uintptr_t)"e0")) & 0xFFFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"e0") + 2u)) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x1Bu)) & 0xFFu);
    lift_store16(cpu->esp + 0x2Cu, cpu->edx & 0xFFFFu);
    lift_store8(cpu->esp + 0x2Eu, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x2Du, cpu->ecx & 0xFFu);
    label_0009500A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49500Au);
    ++cpu->ebx;
    goto label_00094A65;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00495010(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x495010u);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->edx, 1u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x2C8u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00095049;
    label_0009502F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49502Fu);
    lift_store32(cpu->edx, (uint64_t)(lift_load32(cpu->edx)) + 1u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x178u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->ecx + 0x150u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0009502F;
    label_00095049: cpu->eip = LIFT_CODE_TOKEN_VA(0x495049u);
    cpu->eax = lift_load32(cpu->edx);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    --cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->esi, cpu->eax);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x178u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->ecx + 0x150u))));
    cpu->edx = lift_load32(cpu->edx);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x178u);
    cpu->eax = (uint32_t)(cpu->eax + cpu->ecx + 0x150u);
    cpu->esi = lift_pop32(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x150u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax))));
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00495090(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x495090u);
    cpu->esp -= 0x10u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4950B3u); lift_push32(cpu, r); sfera_sub_00495010(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_load32(cpu->esp + 0x28u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->edx = (uint32_t)(cpu->ebx + 0xA0u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x178u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x178u);
    cpu->edx += cpu->ecx;
    cpu->edi += cpu->ecx;
    cpu->eax = (uint32_t)(cpu->edx + 0xA0u);
    cpu->ecx = (uint32_t)(cpu->edi + 0xA0u);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_store32(cpu->esp + 0x24u, cpu->ecx);
    cpu->esi = (uint32_t)(cpu->ebx + 8u);
    cpu->eax = (uint32_t)(cpu->edx + 8u);
    cpu->ecx = (uint32_t)(cpu->edi + 8u);
    lift_store32(cpu->esp + 0x14u, 0xAu);
    label_00095102: cpu->eip = LIFT_CODE_TOKEN_VA(0x495102u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFF8u));
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xFFFFFFF8u))));
    lift_store32(cpu->esp + 0x24u, (uint64_t)(lift_load32(cpu->esp + 0x24u)) + (uint64_t)(4u) + (uint64_t)(0u));
    cpu->ecx += 0x10u;
    cpu->eax += 0x10u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    cpu->esi += 0x10u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0xFFFFFFE8u))));
    lift_store_f32(cpu->esi + 0xFFFFFFE8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFECu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xFFFFFFECu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0xFFFFFFECu))));
    lift_store_f32(cpu->esi + 0xFFFFFFECu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFF0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xFFFFFFF0u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0xFFFFFFF0u))));
    lift_store_f32(cpu->esi + 0xFFFFFFF0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFF4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xFFFFFFF4u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0xFFFFFFF4u))));
    lift_store_f32(cpu->esi + 0xFFFFFFF4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp));
    cpu->ebp = lift_load32(cpu->esp + 0x28u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp))));
    lift_store32(cpu->esp + 0x28u, (uint64_t)(lift_load32(cpu->esp + 0x28u)) + (uint64_t)(4u) + (uint64_t)(0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp))));
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(4u) + (uint64_t)(0u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x14u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x14u, v); }
    lift_store_f32(cpu->ebp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00095102;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xC8u));
    cpu->eax = (uint32_t)(cpu->ebx + 0x138u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + 0xC8u))));
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edx + 0x138u);
    cpu->eax = (uint32_t)(cpu->edi + 0x138u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    cpu->esi = (uint32_t)(cpu->ebx + 0xDCu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + 0xC8u))));
    cpu->eax = (uint32_t)(cpu->edx + 0xDCu);
    cpu->ecx = (uint32_t)(cpu->edi + 0xDCu);
    lift_store32(cpu->esp + 0x14u, 6u);
    lift_store_f32(cpu->ebx + 0xC8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xCCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + 0xCCu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + 0xCCu))));
    lift_store_f32(cpu->ebx + 0xCCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xD0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + 0xD0u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + 0xD0u))));
    lift_store_f32(cpu->ebx + 0xD0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xD4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + 0xD4u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + 0xD4u))));
    lift_store_f32(cpu->ebx + 0xD4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00095212: cpu->eip = LIFT_CODE_TOKEN_VA(0x495212u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFFCu));
    cpu->ebp = lift_load32(cpu->esp + 0x24u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xFFFFFFFCu))));
    lift_store32(cpu->esp + 0x24u, (uint64_t)(lift_load32(cpu->esp + 0x24u)) + (uint64_t)(4u) + (uint64_t)(0u));
    cpu->ecx += 0x10u;
    cpu->eax += 0x10u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    cpu->esi += 0x10u;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0xFFFFFFECu))));
    lift_store_f32(cpu->esi + 0xFFFFFFECu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFF0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xFFFFFFF0u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0xFFFFFFF0u))));
    lift_store_f32(cpu->esi + 0xFFFFFFF0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFF4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xFFFFFFF4u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0xFFFFFFF4u))));
    lift_store_f32(cpu->esi + 0xFFFFFFF4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xFFFFFFF8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xFFFFFFF8u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0xFFFFFFF8u))));
    lift_store_f32(cpu->esi + 0xFFFFFFF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp));
    cpu->ebp = lift_load32(cpu->esp + 0x28u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp))));
    lift_store32(cpu->esp + 0x28u, (uint64_t)(lift_load32(cpu->esp + 0x28u)) + (uint64_t)(4u) + (uint64_t)(0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebp))));
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(4u) + (uint64_t)(0u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x14u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x14u, v); }
    lift_store_f32(cpu->ebp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00095212;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x18u)), r=(uint64_t)(0xBu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x154u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + 0x154u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + 0x154u))));
    lift_store_f32(cpu->ebx + 0x154u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x158u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + 0x158u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + 0x158u))));
    lift_store_f32(cpu->ebx + 0x158u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x15Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + 0x15Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + 0x15Cu))));
    lift_store_f32(cpu->ebx + 0x15Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x160u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + 0x160u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + 0x160u))));
    lift_store_f32(cpu->ebx + 0x160u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x168u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + 0x168u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + 0x168u))));
    lift_store_f32(cpu->ebx + 0x168u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x16Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + 0x16Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + 0x16Cu))));
    lift_store_f32(cpu->ebx + 0x16Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0x170u));
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->edx + 0x170u))));
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edx + 0x170u))));
    lift_store_f32(cpu->ebx + 0x170u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx = lift_pop32(cpu);
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0009534D;
    cpu->ecx = (uint32_t)(uintptr_t)"n2 >= SKY_STATES_NUM";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9534Du); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0009534D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49534Du);
    cpu->esp += 0x10u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00495360(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x495360u);
    cpu->esp -= 0x10u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49537Fu); lift_push32(cpu, r); sfera_sub_00495010(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ecx + 0x102Cu);
    cpu->eax = lift_load32(cpu->ecx + 0x1028u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x178u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x178u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x154u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x178u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->ecx + 0x154u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(cpu->edx + cpu->ecx + 0x154u);
    cpu->edx = lift_load32(cpu->esp);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x178u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x154u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 4u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000953FE;
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000953FE;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00095437;
    label_000953FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4953FEu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00095429;
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_00095429: cpu->eip = LIFT_CODE_TOKEN_VA(0x495429u);
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 3u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00095437: cpu->eip = LIFT_CODE_TOKEN_VA(0x495437u);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.1415929794311523));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x495455u); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49546Eu); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esi + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00495490(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x495490u);
    cpu->esp -= 8u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    cpu->eax = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4954AFu); lift_push32(cpu, r); sfera_sub_00495010(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->eax = lift_load32(cpu->esp);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0x178u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x158u));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x178u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + cpu->ecx + 0x158u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->ecx + 0x158u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx += cpu->ecx;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->eax += cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x15Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0x15Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x15Cu))));
    lift_store_f32(cpu->ecx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x160u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0x160u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x160u))));
    lift_store_f32(cpu->ecx + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x168u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0x168u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x168u))));
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x16Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0x16Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x16Cu))));
    lift_store_f32(cpu->ecx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x170u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0x170u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x170u))));
    lift_store_f32(cpu->ecx + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00495570(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x495570u);
    cpu->esp -= 0x40u;
    lift_x87_push(cpu, 0.0);
    cpu->eax = lift_load32(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    lift_store_f32(cpu->ebp + 0x10A9A8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = native_function_address32(&::rand);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebp);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->esi = (uint32_t)(cpu->ebp + 8u);
    cpu->ebx = 0x1B58u;
    label_000955A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4955A6u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x955A8u), LIFT_CODE_TOKEN_RVA(0x955A6u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4955A8u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (10.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (5.0));
    lift_store_f32(cpu->esi + 0xFFFFFFF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x955C7u), LIFT_CODE_TOKEN_RVA(0x955C5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4955C7u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (10.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (5.0));
    lift_store_f32(cpu->esi + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x955E6u), LIFT_CODE_TOKEN_RVA(0x955E4u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4955E6u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (10.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (32767.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (5.0));
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x95604u), LIFT_CODE_TOKEN_RVA(0x95602u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x495604u);
    cpu->ecx = cpu->eax;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x1B58u);
    cpu->eax = 0x80010003u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(0xEu), 32u);
    cpu->ecx = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(0x1Fu), 32u);
    cpu->ecx += cpu->edx;
    lift_store32(cpu->esi + 4u, cpu->ecx);
    cpu->esi += 0x10u;
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000955A6;
    lift_x87_push(cpu, 0.0);
    cpu->ecx |= 0xFFFFFFFFu;
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    cpu->eax = (uint32_t)(cpu->ebp + 0x1B58Cu);
    lift_x87_push(cpu, 1.0);
    cpu->esi = 0u;
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u));
    goto label_00095661;
    label_0009565F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49565Fu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_00095661: cpu->eip = LIFT_CODE_TOKEN_VA(0x495661u);
    lift_store_f32(cpu->eax + 0xFFFFFFFCu, lift_x87_get(cpu, 0u));
    cpu->edx = (uint32_t)(cpu->ecx + 1u);
    cpu->edx &= 3u;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u));
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + cpu->edx + 0x2Cu));
    cpu->edi = (uint32_t)(cpu->esp + cpu->edx + 0x2Cu);
    lift_store_f32(cpu->eax + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx = (uint32_t)(cpu->esp + cpu->edx + 0x3Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx));
    cpu->edx = (uint32_t)(cpu->ecx + 0xFFFFFFFEu);
    lift_store_f32(cpu->eax + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx &= 3u;
    cpu->edx += cpu->edx;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + 0x1Cu, lift_x87_get(cpu, 0u));
    cpu->edx += cpu->edx;
    cpu->ebp = (uint32_t)(cpu->esp + cpu->edx + 0x2Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + 0x20u, lift_x87_get(cpu, 0u));
    cpu->edx = (uint32_t)(cpu->esp + cpu->edx + 0x3Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp));
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_store_f32(cpu->eax + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    cpu->edx = (uint32_t)(cpu->ecx + 0xFFFFFFFFu);
    lift_store_f32(cpu->eax + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx &= 3u;
    cpu->edx += cpu->edx;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + 0x3Cu, lift_x87_get(cpu, 0u));
    cpu->edx += cpu->edx;
    cpu->ebp = (uint32_t)(cpu->esp + cpu->edx + 0x2Cu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + 0x40u, lift_x87_get(cpu, 0u));
    cpu->edx = (uint32_t)(cpu->esp + cpu->edx + 0x3Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp));
    lift_store32(cpu->esp + 0x28u, cpu->edx);
    lift_store_f32(cpu->eax + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x24u, cpu->ebp);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    cpu->edx = cpu->ecx;
    lift_store_f32(cpu->eax + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx &= 3u;
    cpu->edx += cpu->edx;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + 0x5Cu, lift_x87_get(cpu, 0u));
    cpu->edx += cpu->edx;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    cpu->ebp = (uint32_t)(cpu->esp + cpu->edx + 0x2Cu);
    lift_store_f32(cpu->eax + 0x60u, lift_x87_get(cpu, 0u));
    cpu->edx = (uint32_t)(cpu->esp + cpu->edx + 0x3Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp));
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_store_f32(cpu->eax + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax + 8u, cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store_f32(cpu->eax + 0x70u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax + 0x28u, cpu->esi);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->eax + 0x48u, cpu->esi);
    lift_store_f32(cpu->eax + 0x7Cu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + 0x68u, cpu->esi);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->eax + 0x88u, cpu->esi);
    lift_store_f32(cpu->eax + 0x80u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + 0xA8u, cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_store_f32(cpu->eax + 0x8Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx));
    lift_store_f32(cpu->eax + 0x90u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + 0x9Cu, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + 0xA0u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_store_f32(cpu->eax + 0xACu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_store_f32(cpu->eax + 0xB0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx += 0xAu;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->eax + 0xC8u, cpu->esi);
    lift_store_f32(cpu->eax + 0xBCu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + 0xE8u, cpu->esi);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->eax + 0x108u, cpu->esi);
    lift_store_f32(cpu->eax + 0xC0u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->eax + 0x128u, cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_store_f32(cpu->eax + 0xCCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax += 0x140u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_store_f32(cpu->eax + 0xFFFFFF90u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + 0xFFFFFF9Cu, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + 0xFFFFFFA0u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp));
    lift_store_f32(cpu->eax + 0xFFFFFFACu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store_f32(cpu->eax + 0xFFFFFFB0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + 0xFFFFFFBCu, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + 0xFFFFFFC0u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_store_f32(cpu->eax + 0xFFFFFFCCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx));
    lift_store_f32(cpu->eax + 0xFFFFFFD0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + 0xFFFFFFDCu, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->eax + 0xFFFFFFE0u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store_f32(cpu->eax + 0xFFFFFFECu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    cpu->edx = (uint32_t)(cpu->ecx + 1u);
    lift_store_f32(cpu->eax + 0xFFFFFFF0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(0x6D60u)) goto label_0009565F;
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(cpu->ebx + 0xF6182u);
    cpu->edi = 0x1B58u;
    label_00095820: cpu->eip = LIFT_CODE_TOKEN_VA(0x495820u);
    cpu->ecx = cpu->esi & 0xFFFFu;
    cpu->edx = (uint32_t)(cpu->ecx + 1u);
    lift_store16(cpu->eax, cpu->edx & 0xFFFFu);
    cpu->edx = (uint32_t)(cpu->ecx + 2u);
    lift_store16(cpu->eax + 0xFFFFFFFEu, cpu->ecx & 0xFFFFu);
    lift_store16(cpu->eax + 4u, cpu->ecx & 0xFFFFu);
    cpu->ecx += 3u;
    lift_store16(cpu->eax + 2u, cpu->edx & 0xFFFFu);
    lift_store16(cpu->eax + 6u, cpu->edx & 0xFFFFu);
    lift_store16(cpu->eax + 8u, cpu->ecx & 0xFFFFu);
    cpu->esi += 4u;
    cpu->eax += 0xCu;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00095820;
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x495857u); lift_push32(cpu, r); sfera_sub_0042F2A0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(3u), 32u);
    lift_push32(cpu, 0x59u);
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->eax) * 8u));
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\snow.cpp";
    lift_store32(cpu->ebx + 0x10A9A4u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x495873u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0u;
    cpu->ecx = cpu->esi;
    lift_store32(cpu->ebx + 0x10A9A0u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x495882u); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ebx + 0x10A9A0u);
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->ebx + 0x10A9A4u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49589Eu); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4958A5u); lift_push32(cpu, r); sfera_sub_0042F180(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x40u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004958C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4958C0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_method_address32(&CSound::SetPlayTimepos), LIFT_CODE_TOKEN_VA(0x4958CBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4958D1u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    cpu->eax = static_cast<uint32_t>(reinterpret_cast<CSound*>(static_cast<uintptr_t>(cpu->ecx))->CSound::Play(static_cast<int>(lift_load32(cpu->esp)))); cpu->esp += 4u; cpu->eip = LIFT_CODE_TOKEN_VA(0x4958DEu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000958FB;
    cpu->eax |= 0xFFFFFFFFu;
    lift_store32(cpu->esi + 0x60u, cpu->eax);
    lift_store32(cpu->esi + 0x64u, cpu->eax);
    lift_store32(cpu->esi + 0x6Cu, 0u);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000958FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4958FBu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00495910(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x495910u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->esi) != 0u) goto label_0009591B;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0009591B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49591Bu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = native_function_address32(&::_stricmp);
    lift_push32(cpu, (uintptr_t)"SF_PLAY_RANDOM"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x9592Au), LIFT_CODE_TOKEN_RVA(0x95928u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49592Au);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00095939;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 4u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00095939: cpu->eip = LIFT_CODE_TOKEN_VA(0x495939u);
    lift_push32(cpu, (uintptr_t)"SF_PLAY_RANDOMMIX"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x95941u), LIFT_CODE_TOKEN_RVA(0x9593Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x495941u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00095950;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 8u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00095950: cpu->eip = LIFT_CODE_TOKEN_VA(0x495950u);
    lift_push32(cpu, (uintptr_t)"SF_PLAY_LOOPED"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x95958u), LIFT_CODE_TOKEN_RVA(0x95956u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x495958u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00095967;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0x10u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00095967: cpu->eip = LIFT_CODE_TOKEN_VA(0x495967u);
    lift_push32(cpu, (uintptr_t)"SF_TYPE_ENVIRONMENT"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x9596Fu), LIFT_CODE_TOKEN_RVA(0x9596Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49596Fu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009597E;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0009597E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49597Eu);
    lift_push32(cpu, (uintptr_t)"SF_PLAY_USEREGION"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x95986u), LIFT_CODE_TOKEN_RVA(0x95984u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x495986u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00095995;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0x20u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00095995: cpu->eip = LIFT_CODE_TOKEN_VA(0x495995u);
    lift_push32(cpu, (uintptr_t)"SF_PLAY_TIMEGROUPS"); lift_push32(cpu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x9599Du), LIFT_CODE_TOKEN_RVA(0x9599Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49599Du);
    cpu->esp += 8u;
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->eax &= 0xFFFFFFC0u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax += 0x40u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004959B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4959B0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_000959ED;
    cpu->edx = 0xFFu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4959CBu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->edi;
    cpu->edx = 4u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4959E3u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->edi);
    goto label_000959FA;
    label_000959ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4959EDu);
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->esi + 4u, 0u);
    label_000959FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4959FAu);
    cpu->eax = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_00095A10;
    label_00095A01: cpu->eip = LIFT_CODE_TOKEN_VA(0x495A01u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u), 0u);
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00095A01;
    label_00095A10: cpu->eip = LIFT_CODE_TOKEN_VA(0x495A10u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 8u, 0u);
    lift_store32(cpu->esi + 0xCu, cpu->edx);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00495A30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x495A30u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    cpu->ebp = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00095ABB;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    label_00095A42: cpu->eip = LIFT_CODE_TOKEN_VA(0x495A42u);
    cpu->edx = lift_load32(cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esi + cpu->eax);
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->edi = lift_load32(cpu->ecx);
    (void)cpu;
    label_00095A50: cpu->eip = LIFT_CODE_TOKEN_VA(0x495A50u);
    cpu->ebx = lift_load32(cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->esi) * 4u));
    label_00095A56: cpu->eip = LIFT_CODE_TOKEN_VA(0x495A56u);
    cpu->edx = lift_load32(cpu->ecx);
    ++cpu->esi;
    cpu->ecx += 4u;
    if ((uint32_t)(lift_load32(cpu->edx)) >= (uint32_t)(cpu->edi)) goto label_00095A65;
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(lift_load32(cpu->ebp + 8u))) goto label_00095A56;
    label_00095A65: cpu->eip = LIFT_CODE_TOKEN_VA(0x495A65u);
    --cpu->esi;
    cpu->ecx = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->eax) * 4u));
    cpu->esp = (uint32_t)(cpu->esp);
    label_00095A70: cpu->eip = LIFT_CODE_TOKEN_VA(0x495A70u);
    cpu->edx = lift_load32(cpu->ecx);
    --cpu->eax;
    cpu->ecx -= 4u;
    if ((uint32_t)(lift_load32(cpu->edx)) <= (uint32_t)(cpu->edi)) goto label_00095A7E;
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00095A70;
    label_00095A7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x495A7Eu);
    ++cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) > (int32_t)(uint32_t)(cpu->eax)) goto label_00095A98;
    cpu->edx = lift_load32(cpu->ebx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load32(cpu->ebx + ((uint32_t)(cpu->esi) * 4u));
    lift_store32(cpu->ebx + ((uint32_t)(cpu->esi) * 4u), cpu->edx);
    cpu->edx = lift_load32(cpu->ebp);
    lift_store32(cpu->edx + ((uint32_t)(cpu->eax) * 4u), cpu->ecx);
    ++cpu->esi;
    --cpu->eax;
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(cpu->eax)) goto label_00095A50;
    label_00095A98: cpu->eip = LIFT_CODE_TOKEN_VA(0x495A98u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->eax)) goto label_00095AA9;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x95AA9u); lift_push32(cpu, r); sfera_sub_00495A30(cpu,r); if (cpu->eip != r) return; }
    label_00095AA9: cpu->eip = LIFT_CODE_TOKEN_VA(0x495AA9u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(lift_load32(cpu->esp + 0x18u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_00095AB9;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    goto label_00095A42;
    label_00095AB9: cpu->eip = LIFT_CODE_TOKEN_VA(0x495AB9u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00095ABB: cpu->eip = LIFT_CODE_TOKEN_VA(0x495ABBu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00495AC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x495AC0u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    --cpu->edx;
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_00095AF7;
    cpu->ebp = lift_load32(cpu->ecx);
    label_00095AD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x495AD5u);
    cpu->eax = (uint32_t)(cpu->edx + cpu->esi);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->edi = lift_load32(cpu->ebp + ((uint32_t)(cpu->eax) * 4u));
    cpu->edi = lift_load32(cpu->edi);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_00095AE6;
    cpu->edx = cpu->eax;
    label_00095AE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x495AE6u);
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_00095AEA;
    cpu->esi = cpu->eax;
    label_00095AEA: cpu->eip = LIFT_CODE_TOKEN_VA(0x495AEAu);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->edi)) goto label_00095B19;
    cpu->eax = cpu->edx;
    cpu->eax -= cpu->esi;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00095AD5;
    label_00095AF7: cpu->eip = LIFT_CODE_TOKEN_VA(0x495AF7u);
    cpu->eax = cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) > (int32_t)(uint32_t)(cpu->edx)) goto label_00095B10;
    cpu->edi = lift_load32(cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->esi) * 4u));
    label_00095B02: cpu->eip = LIFT_CODE_TOKEN_VA(0x495B02u);
    cpu->esi = lift_load32(cpu->ecx);
    if ((uint32_t)(lift_load32(cpu->esi)) == (uint32_t)(cpu->ebx)) goto label_00095B24;
    ++cpu->eax;
    cpu->ecx += 4u;
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->edx)) goto label_00095B02;
    label_00095B10: cpu->eip = LIFT_CODE_TOKEN_VA(0x495B10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00095B19: cpu->eip = LIFT_CODE_TOKEN_VA(0x495B19u);
    cpu->eax = lift_load32(cpu->ebp + ((uint32_t)(cpu->eax) * 4u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00095B24: cpu->eip = LIFT_CODE_TOKEN_VA(0x495B24u);
    cpu->eax = lift_load32(cpu->edi + ((uint32_t)(cpu->eax) * 4u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00495B30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x495B30u);
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ebx);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->esi);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    cpu->esi = cpu->ecx;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x3Cu, cpu->eax);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x40u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x44u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_store32(cpu->esi + 0x48u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_store_f32(cpu->esi + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    lift_store32(cpu->esi + 0x4Cu, cpu->ecx);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x50u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esi + 0x54u, cpu->eax);
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->esi + 0x58u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, 0x40u);
    lift_store32(cpu->esi + 0x5Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esi + 0xB4u, cpu->eax);
    cpu->ebx = (uint32_t)(cpu->esi + 0x74u);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esi + 0xB8u, cpu->ecx);
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esi, cpu->edi);
    lift_store32(cpu->esi + 4u, cpu->edi);
    lift_store32(cpu->esi + 0x28u, cpu->edi);
    lift_store32(cpu->esi + 0x30u, cpu->edi);
    lift_store32(cpu->esi + 0x34u, cpu->edi);
    lift_store32(cpu->esi + 0x2Cu, cpu->edi);
    lift_store32(cpu->esi + 0x64u, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x68u, cpu->edi);
    lift_store32(cpu->esi + 0x6Cu, 4u);
    lift_store32(cpu->esi + 0xBCu, cpu->edx);
    lift_store32(cpu->esi + 0x70u, cpu->edi);
    lift_store32(cpu->esi + 8u, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x495C00u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x495C05u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)"(knNcache_lifetime"));
    lift_store_f32(cpu->esi + 0xACu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = 0x168u;
    lift_x87_push(cpu, 1.0);
    lift_store32(cpu->esi + 0x90u, cpu->eax);
    lift_store_f32(cpu->esi + 0xA8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0x94u, cpu->eax);
    lift_x87_push(cpu, 0.0);
    cpu->esp += 0xCu;
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->ebx, 0x40u);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0xA4u, cpu->edi);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, (double)-1.0f);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0x98u, cpu->eax);
    lift_store32(cpu->esi + 0xB0u, cpu->edi);
    lift_store32(cpu->esi + 0x9Cu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esi + 0x38u, cpu->edi);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0xA0u, cpu->edx);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00495C80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x495C80u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(lift_load32(cpu->esi + 0x28u)) == (uint32_t)(cpu->ebx)) goto label_00095CE0;
    cpu->ebp = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x2Cu)) <= (uint32_t)(cpu->ebx)) goto label_00095CC5;
    cpu->edi = 0u;
    label_00095C96: cpu->eip = LIFT_CODE_TOKEN_VA(0x495C96u);
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    if ((uint32_t)(lift_load32(cpu->edi + cpu->eax)) == (uint32_t)(cpu->ebx)) goto label_00095CBC;
    cpu->edx = 0x225u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x495CADu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    cpu->edx = lift_load32(cpu->edi + cpu->ecx);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x495CB9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00095CBC: cpu->eip = LIFT_CODE_TOKEN_VA(0x495CBCu);
    ++cpu->ebp;
    cpu->edi += 0xCu;
    if ((uint32_t)(cpu->ebp) < (uint32_t)(lift_load32(cpu->esi + 0x2Cu))) goto label_00095C96;
    label_00095CC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x495CC5u);
    cpu->edx = 0x227u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x495CD4u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x495CDDu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00095CE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x495CE0u);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esi + 0x28u, cpu->ebx);
    lift_store32(cpu->esi + 0x2Cu, cpu->ebx);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebx)) goto label_00095DBD;
    cpu->edx = 0x22Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x495D01u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->edi;
    cpu->edx = 0xCu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x495D19u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    cpu->esp += 4u;
    cpu->edx = 0u;
    lift_store32(cpu->esi + 0x28u, cpu->eax);
    lift_store32(cpu->esi + 0x2Cu, cpu->edi);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(4u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00095D94;
    cpu->ecx = (uint32_t)(cpu->edi + 0xFFFFFFFCu);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->eax = 0u;
    ++cpu->ecx;
    cpu->edx = (uint32_t)(((uint32_t)(cpu->ecx) * 4u));
    label_00095D3B: cpu->eip = LIFT_CODE_TOKEN_VA(0x495D3Bu);
    cpu->ebp = lift_load32(cpu->esi + 0x28u);
    lift_store32(cpu->eax + cpu->ebp, cpu->ebx);
    cpu->ebp = lift_load32(cpu->esi + 0x28u);
    lift_store8(cpu->eax + cpu->ebp + 4u, cpu->ebx & 0xFFu);
    cpu->ebp = lift_load32(cpu->esi + 0x28u);
    lift_store_f32(cpu->eax + cpu->ebp + 8u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x28u);
    lift_store32(cpu->eax + cpu->ebp + 0xCu, cpu->ebx);
    cpu->ebp = lift_load32(cpu->esi + 0x28u);
    lift_store8(cpu->eax + cpu->ebp + 0x10u, cpu->ebx & 0xFFu);
    cpu->ebp = lift_load32(cpu->esi + 0x28u);
    lift_store_f32(cpu->eax + cpu->ebp + 0x14u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x28u);
    lift_store32(cpu->eax + cpu->ebp + 0x18u, cpu->ebx);
    cpu->ebp = lift_load32(cpu->esi + 0x28u);
    lift_store8(cpu->eax + cpu->ebp + 0x1Cu, cpu->ebx & 0xFFu);
    cpu->ebp = lift_load32(cpu->esi + 0x28u);
    lift_store_f32(cpu->eax + cpu->ebp + 0x20u, lift_x87_get(cpu, 0u));
    cpu->ebp = lift_load32(cpu->esi + 0x28u);
    lift_store32(cpu->eax + cpu->ebp + 0x24u, cpu->ebx);
    cpu->ebp = lift_load32(cpu->esi + 0x28u);
    lift_store8(cpu->eax + cpu->ebp + 0x28u, cpu->ebx & 0xFFu);
    cpu->ebp = lift_load32(cpu->esi + 0x28u);
    lift_store_f32(cpu->eax + cpu->ebp + 0x2Cu, lift_x87_get(cpu, 0u));
    cpu->eax += 0x30u;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00095D3B;
    label_00095D94: cpu->eip = LIFT_CODE_TOKEN_VA(0x495D94u);
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->edi)) goto label_00095DBB;
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->edi -= cpu->edx;
    label_00095DA1: cpu->eip = LIFT_CODE_TOKEN_VA(0x495DA1u);
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    lift_store32(cpu->eax + cpu->ecx, cpu->ebx);
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    lift_store8(cpu->eax + cpu->edx + 4u, cpu->ebx & 0xFFu);
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    lift_store_f32(cpu->eax + cpu->ecx + 8u, lift_x87_get(cpu, 0u));
    cpu->eax += 0xCu;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00095DA1;
    label_00095DBB: cpu->eip = LIFT_CODE_TOKEN_VA(0x495DBBu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00095DBD: cpu->eip = LIFT_CODE_TOKEN_VA(0x495DBDu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00495DD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x495DD0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->edi + 0x30u)) == (uint32_t)(0u)) goto label_00095DF5;
    cpu->edx = 0x23Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x495DE9u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x30u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x495DF2u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00095DF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x495DF5u);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->edi + 0x30u, 0u);
    lift_store32(cpu->edi + 0x34u, 0u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_00095E47;
    cpu->edx = 0x243u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x495E1Au); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->esi;
    cpu->edx = 0x10u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x495E32u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x34u, cpu->esi);
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(4u), 32u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->edi + 0x30u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x495E3Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x495E44u);
    cpu->esp += 0x10u;
    label_00095E47: cpu->eip = LIFT_CODE_TOKEN_VA(0x495E47u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00495E50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x495E50u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(4u), 32u);
    lift_x87_push(cpu, 0.0);
    cpu->edx += lift_load32(cpu->ecx + 0x30u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 24.0);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00095E77;
    lift_x87_set(cpu, 2u, (lift_x87_get(cpu, 2u)) / (lift_x87_get(cpu, 0u)));
    label_00095E77: cpu->eip = LIFT_CODE_TOKEN_VA(0x495E77u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 3u));
    LIFT_X87_POP_STATUS_AX();
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00095E9A;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    goto label_00095E9E;
    label_00095E9A: cpu->eip = LIFT_CODE_TOKEN_VA(0x495E9Au);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_00095E9E: cpu->eip = LIFT_CODE_TOKEN_VA(0x495E9Eu);
    lift_x87_push(cpu, 1.0);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    lift_store32(cpu->edx + 8u, cpu->eax);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->edx + 0xCu, cpu->ecx);
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 4u))));
    lift_store_f32(cpu->edx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->ecx)) goto label_00095ECD;
    lift_store32(cpu->edx + 8u, cpu->ecx);
    lift_store32(cpu->edx + 0xCu, cpu->eax);
    label_00095ECD: cpu->eip = LIFT_CODE_TOKEN_VA(0x495ECDu);
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00495ED0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x495ED0u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(lift_load32(cpu->esi + 0x2Cu))) goto label_00095F33;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_00095F32;
    if ((uint8_t)(lift_load8(cpu->ebx)) == (uint8_t)(0u)) goto label_00095F32;
    cpu->edx = 0x28Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x495EFAu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->ebx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_00095F00: cpu->eip = LIFT_CODE_TOKEN_VA(0x495F00u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00095F00;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x495F10u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x28u);
    cpu->ecx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    cpu->ecx += cpu->ecx;
    cpu->esp += 4u;
    cpu->ecx += cpu->ecx;
    lift_store32(cpu->ecx + cpu->edx, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    cpu->ecx = lift_load32(cpu->ecx + cpu->eax);
    cpu->edx = cpu->ebx;
    label_00095F28: cpu->eip = LIFT_CODE_TOKEN_VA(0x495F28u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    lift_store8(cpu->ecx, cpu->eax & 0xFFu);
    ++cpu->edx;
    ++cpu->ecx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00095F28;
    label_00095F32: cpu->eip = LIFT_CODE_TOKEN_VA(0x495F32u);
    cpu->ebx = lift_pop32(cpu);
    label_00095F33: cpu->eip = LIFT_CODE_TOKEN_VA(0x495F33u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00495F40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x495F40u);
    cpu->esp -= 0x120u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x130u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x130u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, cpu->ebp);
    cpu->ebx = 0u;
    lift_push32(cpu, (uint32_t)(uintptr_t)"eff_number");
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    lift_store32(cpu->edi + 4u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x495F7Eu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00095F8C;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x495F8Au); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi, cpu->eax);
    label_00095F8C: cpu->eip = LIFT_CODE_TOKEN_VA(0x495F8Cu);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"audio_files");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x495FA0u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009609B;
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x495FB4u); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"source");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x495FC0u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000963C9;
    label_00095FC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x495FC8u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"source");
    cpu->ecx = cpu->esi;
    ++cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x495FD5u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00095FC8;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000963C9;
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x495FEDu); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x495FF5u); lift_push32(cpu, r); sfera_sub_00495C80(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"source");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496001u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000960DB;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00096010: cpu->eip = LIFT_CODE_TOKEN_VA(0x496010u);
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496019u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ebp) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_000963C9;
    if ((int32_t)(uint32_t)(cpu->ebp) < 0) goto label_000963C9;
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496039u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00096081;
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49604Au); lift_push32(cpu, r); sfera_sub_00495ED0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, (uintptr_t)"silence"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x496054u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49605Au);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00096081;
    cpu->eax = lift_load32(cpu->edi + 0x28u);
    cpu->ebp = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->ebp) * 2u));
    cpu->ebp += cpu->ebp;
    cpu->ebp += cpu->ebp;
    lift_push32(cpu, 2u);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->eax + cpu->ebp + 4u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49607Au); lift_push32(cpu, r); sfera_sub_004942C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->edi + 0x28u);
    lift_store_f32(cpu->ecx + cpu->ebp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00096081: cpu->eip = LIFT_CODE_TOKEN_VA(0x496081u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"source");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49608Du); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00096010;
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    goto label_000960DB;
    label_0009609B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49609Bu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"audio_file");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4960A8u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000963C9;
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4960BDu); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000963C9;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4960CEu); lift_push32(cpu, r); sfera_sub_00495C80(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x960DBu); lift_push32(cpu, r); sfera_sub_00495ED0(cpu,r); if (cpu->eip != r) return; }
    label_000960DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4960DBu);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"time_groups");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4960EFu); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000961E8;
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496103u); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"time");
    cpu->ecx = cpu->esi;
    cpu->ebx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496111u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000961E8;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00096120: cpu->eip = LIFT_CODE_TOKEN_VA(0x496120u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"time");
    cpu->ecx = cpu->esi;
    ++cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49612Du); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00096120;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000961E8;
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    cpu->ebp = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496147u); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49614Fu); lift_push32(cpu, r); sfera_sub_00495DD0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"time");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49615Bu); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000961E4;
    cpu->ebx = (uint32_t)(cpu->esi + 0x10u);
    label_00096166: cpu->eip = LIFT_CODE_TOKEN_VA(0x496166u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%f %f %d %d"); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x496180u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x496186u);
    cpu->eax = lift_load32(cpu->edi + 0x2Cu);
    cpu->esp += 0x18u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x14u)) >= (uint32_t)(cpu->eax)) goto label_00096198;
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) < (uint32_t)(cpu->eax)) goto label_000961AF;
    label_00096198: cpu->eip = LIFT_CODE_TOKEN_VA(0x496198u);
    cpu->edx = (uint32_t)(cpu->ebp + 1u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"CSoundEffect::LoadScript() -> Invalid audio index in block 'time_groups' line %d");
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4961A6u); lift_push32(cpu, r); sfera_sub_0042E1D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4961ACu); lift_push32(cpu, r); sfera_sub_0042E4C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    label_000961AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4961AFu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->edi;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4961D3u); lift_push32(cpu, r); sfera_sub_00495E50(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"time");
    cpu->ecx = cpu->esi;
    ++cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4961E0u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00096166;
    label_000961E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4961E4u);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    label_000961E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4961E8u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"flags");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4961F5u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00096230;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496200u); lift_push32(cpu, r); sfera_sub_004947E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    cpu->ebx = 0u;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_0009622C;
    label_00096208: cpu->eip = LIFT_CODE_TOKEN_VA(0x496208u);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496215u); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00096225;
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496222u); lift_push32(cpu, r); sfera_sub_00495910(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 4u, (uint64_t)(lift_load32(cpu->edi + 4u)) | (uint64_t)(cpu->eax));
    label_00096225: cpu->eip = LIFT_CODE_TOKEN_VA(0x496225u);
    cpu->ebx += 2u;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->ebp)) goto label_00096208;
    label_0009622C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49622Cu);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    label_00096230: cpu->eip = LIFT_CODE_TOKEN_VA(0x496230u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"region_radius");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49623Du); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009625F;
    cpu->eax = (uint32_t)(cpu->edi + 0x50u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0x4Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%f %f %f"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x496256u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49625Cu);
    cpu->esp += 0x14u;
    label_0009625F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49625Fu);
    lift_x87_push(cpu, (double)0.029999999329447746f);
    lift_push32(cpu, cpu->ebp);
    cpu->ebx = 0u;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, (uint32_t)(uintptr_t)"min_distance");
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49627Cu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00096296;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496288u); lift_push32(cpu, r); sfera_sub_004942C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->edi + 0xA8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x14u, 1u);
    label_00096296: cpu->eip = LIFT_CODE_TOKEN_VA(0x496296u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"max_distance");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4962A3u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000962BB;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4962B0u); lift_push32(cpu, r); sfera_sub_004942C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->edi + 0xACu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx = 1u;
    label_000962BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4962BBu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"mix_duration");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4962C8u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000962D8;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4962D5u); lift_push32(cpu, r); sfera_sub_004942C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->edi + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000962D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4962D8u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"vol_barier");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4962E5u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00096330;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4962F2u); lift_push32(cpu, r); sfera_sub_004942C0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 0.0);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00096311;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.009999999776482582);
    goto label_00096317;
    label_00096311: cpu->eip = LIFT_CODE_TOKEN_VA(0x496311u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (100.0));
    label_00096317: cpu->eip = LIFT_CODE_TOKEN_VA(0x496317u);
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esp + 0x10u)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0009632E;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00096330;
    label_0009632E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49632Eu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00096330: cpu->eip = LIFT_CODE_TOKEN_VA(0x496330u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, (uintptr_t)"offset_vec");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49633Du); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009635F;
    cpu->ecx = (uint32_t)(cpu->edi + 0x44u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 0x40u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->edi + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x10u);
    lift_push32(cpu, (uintptr_t)"%f %f %f"); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x496356u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49635Cu);
    cpu->esp += 0x14u;
    label_0009635F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49635Fu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, ((uint32_t)(uintptr_t)"(knNcache_lifetime") + 4u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49636Cu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00096388;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496379u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x6Cu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0xAu)) goto label_00096388;
    lift_store32(cpu->edi + 0x6Cu, 0xAu);
    label_00096388: cpu->eip = LIFT_CODE_TOKEN_VA(0x496388u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x14u)) == (uint32_t)(0u)) goto label_000963A8;
    if ((uint32_t)(cpu->ebx) != 0u) goto label_000963C2;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xA8u));
    cpu->eax = (uint32_t)(cpu->ebx + 1u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->edi + 0xACu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_000963CB;
    label_000963A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4963A8u);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_000963C2;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xACu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_push(cpu, 1.0);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->edi + 0xA8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000963C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4963C2u);
    cpu->eax = 1u;
    goto label_000963CB;
    label_000963C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4963C9u);
    cpu->eax = 0u;
    label_000963CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4963CBu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x120u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004963F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4963F0u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebp + 4u);
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (0x40u)) == 0u) goto label_0009661D;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_graphics_runtime.environment_factor));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 0x34u);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(4u)) goto label_0009654B;
    cpu->eax = lift_load32(cpu->ebp + 0x30u);
    cpu->edi = 0x10u;
    cpu->edi -= cpu->eax;
    cpu->ecx = 0x20u;
    cpu->edx = 0u;
    cpu->ecx -= cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    goto label_00096441;
    label_0009643D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49643Du);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    label_00096441: cpu->eip = LIFT_CODE_TOKEN_VA(0x496441u);
    cpu->eax = lift_load32(cpu->ebp + 0x30u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->eax));
    cpu->ecx = lift_load32(cpu->ebp + 0x30u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->eax + 4u));
    cpu->esi = (uint32_t)(cpu->edx + cpu->eax + 0x10u);
    LIFT_X87_COMPARE_POP2_AX();
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00096469;
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00096483;
    goto label_00096472;
    label_00096469: cpu->eip = LIFT_CODE_TOKEN_VA(0x496469u);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000965B1;
    label_00096472: cpu->eip = LIFT_CODE_TOKEN_VA(0x496472u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 4u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000965B1;
    label_00096483: cpu->eip = LIFT_CODE_TOKEN_VA(0x496483u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    LIFT_X87_COMPARE_POP2_AX();
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x10u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000964A0;
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000964BA;
    goto label_000964A9;
    label_000964A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4964A0u);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000965B0;
    label_000964A9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4964A9u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x14u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000965B0;
    label_000964BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4964BAu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->eax = (uint32_t)(cpu->ecx + cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->edi));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000964DA;
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_000964F4;
    goto label_000964E3;
    label_000964DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4964DAu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000965F4;
    label_000964E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4964E3u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x24u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000965F4;
    label_000964F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4964F4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x24u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->eax = (uint32_t)(cpu->ecx + cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->esi));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00096518;
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00096532;
    goto label_00096521;
    label_00096518: cpu->eip = LIFT_CODE_TOKEN_VA(0x496518u);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000965F9;
    label_00096521: cpu->eip = LIFT_CODE_TOKEN_VA(0x496521u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x34u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000965F9;
    label_00096532: cpu->eip = LIFT_CODE_TOKEN_VA(0x496532u);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->ebx += 4u;
    cpu->ecx = (uint32_t)(cpu->edi + 0xFFFFFFFDu);
    cpu->eax = 0u;
    cpu->edx += 0x40u;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(cpu->ecx)) goto label_0009643D;
    goto label_0009654F;
    label_0009654B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49654Bu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    label_0009654F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49654Fu);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_000965FE;
    cpu->edx = lift_load32(cpu->ebp + 0x30u);
    cpu->ecx = cpu->ebx;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    cpu->edx = (uint32_t)(cpu->edx + cpu->ecx + 4u);
    label_00096563: cpu->eip = LIFT_CODE_TOKEN_VA(0x496563u);
    cpu->eax = lift_load32(cpu->ebp + 0x30u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + cpu->ecx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->eax = lift_load32(cpu->ebp + 0x30u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + cpu->eax));
    cpu->esi = (uint32_t)(cpu->ecx + cpu->eax);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00096588;
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00096599;
    goto label_0009658D;
    label_00096588: cpu->eip = LIFT_CODE_TOKEN_VA(0x496588u);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_000965B1;
    label_0009658D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49658Du);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_000965B1;
    label_00096599: cpu->eip = LIFT_CODE_TOKEN_VA(0x496599u);
    ++cpu->ebx;
    cpu->ecx += 0x10u;
    cpu->edx += 0x10u;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(cpu->edi)) goto label_00096563;
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000965B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4965B0u);
    ++cpu->ebx;
    label_000965B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4965B1u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000965B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4965B3u);
    if ((uint8_t)((lift_load8(cpu->esp + 0x1Cu)) & (0xCu)) == 0u) goto label_0009660C;
    cpu->ecx = lift_load32(cpu->ebp + 0x30u);
    cpu->edi = cpu->ebx;
    cpu->edi += cpu->edi;
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 8u) + 0xCu);
    cpu->esi -= lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 8u) + 8u);
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edi) * 8u));
    ++cpu->esi;
    if ((uint32_t)(cpu->esi) <= (uint32_t)(1u)) goto label_0009660C;
    cpu->ebx = native_function_address32(&::rand);
    label_000965D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4965D8u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x965DAu), LIFT_CODE_TOKEN_RVA(0x965D8u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4965DAu);
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, cpu->esi, 32u, 0u);
    cpu->eax = cpu->edx;
    cpu->edx = lift_load32(cpu->ebp + 0x30u);
    cpu->eax += lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 8u) + 8u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebp + 0x64u))) goto label_000965D8;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000965F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4965F4u);
    cpu->ebx += 2u;
    goto label_000965B1;
    label_000965F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4965F9u);
    cpu->ebx += 3u;
    goto label_000965B1;
    label_000965FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4965FEu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000965B3;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_0009660C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49660Cu);
    cpu->eax = lift_load32(cpu->ebp + 0x30u);
    cpu->ebx += cpu->ebx;
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->ebx) * 8u) + 8u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_0009661D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49661Du);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (0xCu)) == 0u) goto label_00096644;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x2Cu)) <= (uint32_t)(1u)) goto label_00096644;
    cpu->esi = native_function_address32(&::rand);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00096630: cpu->eip = LIFT_CODE_TOKEN_VA(0x496630u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x96632u), LIFT_CODE_TOKEN_RVA(0x96630u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x496632u);
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, lift_load32(cpu->ebp + 0x2Cu), 32u, 0u);
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebp + 0x64u))) goto label_00096630;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_00096644: cpu->eip = LIFT_CODE_TOKEN_VA(0x496644u);
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00496650(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x496650u);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0x28u)) == (uint32_t)(0u)) goto label_00096860;
    if ((uint32_t)(lift_load32(cpu->esi + 0x2Cu)) == (uint32_t)(0u)) goto label_00096860;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496670u); lift_push32(cpu, r); sfera_sub_00497970(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    lift_store32(cpu->esp + 0xCu, cpu->edi);
    if ((uint32_t)(cpu->edi) != 0u) goto label_00096682;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 8u, stop_address); return;
    label_00096682: cpu->eip = LIFT_CODE_TOKEN_VA(0x496682u);
    cpu->eax = lift_load32(cpu->esi + 0x68u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00096697;
    lift_store32(cpu->eax + 0x68u, 1u);
    lift_store32(cpu->esi + 0x68u, 0u);
    label_00096697: cpu->eip = LIFT_CODE_TOKEN_VA(0x496697u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4966A0u); lift_push32(cpu, r); sfera_sub_004963F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    cpu->ebx = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->esi + 0x64u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    { uint64_t l=(uint64_t)(lift_load8(cpu->ecx + ((uint32_t)(cpu->eax) * 4u) + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebp = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000966D4;
    lift_store32(cpu->esi + 8u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4966C3u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store32(cpu->esi + 0x14u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 8u));
    lift_store_f32(cpu->esi + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00096818;
    label_000966D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4966D4u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_000966EF;
    cpu->edx = lift_load32(cpu->esi + 0x6Cu);
    cpu->eax = lift_load32(cpu->ebp);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4966EAu); lift_push32(cpu, r); sfera_sub_00497B80(cpu,r); if (cpu->eip != r) return; }
    goto label_00096815;
    label_000966EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4966EFu);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (0x20u)) == 0u) goto label_00096755;
    cpu->edi = native_function_address32(&::rand);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x966FBu), LIFT_CODE_TOKEN_RVA(0x966F9u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4966FBu);
    cpu->ebx = cpu->eax;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x966FFu), LIFT_CODE_TOKEN_RVA(0x966FDu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4966FFu);
    cpu->ebx -= cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x48u))));
    lift_store_f32(cpu->esi + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x96717u), LIFT_CODE_TOKEN_RVA(0x96715u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x496717u);
    cpu->ebx = cpu->eax;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x9671Bu), LIFT_CODE_TOKEN_RVA(0x96719u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49671Bu);
    cpu->ebx -= cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x4Cu))));
    lift_store_f32(cpu->esi + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x96733u), LIFT_CODE_TOKEN_RVA(0x96731u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x496733u);
    cpu->ebx = cpu->eax;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x96737u), LIFT_CODE_TOKEN_RVA(0x96735u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x496737u);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->ebx -= cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    cpu->ebx = lift_load32(cpu->esp + 0x2Cu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (3.0518509447574615e-05));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x50u))));
    lift_store_f32(cpu->esi + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00096755: cpu->eip = LIFT_CODE_TOKEN_VA(0x496755u);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000967ED;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 4u)), r=(uint64_t)(0x20u), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x3Cu))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x40u))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x44u))));
    lift_store32(cpu->esi + 0xB4u, cpu->ecx);
    lift_store32(cpu->esi + 0xB8u, cpu->edx);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->esi + 0xBCu, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000967CF;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xB4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x54u))));
    lift_store_f32(cpu->esi + 0xB4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x58u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0xB8u))));
    lift_store_f32(cpu->esi + 0xB8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x5Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0xBCu))));
    lift_store_f32(cpu->esi + 0xBCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_000967CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4967CFu);
    cpu->ecx = lift_load32(cpu->esi + 0xB4u);
    cpu->edx = lift_load32(cpu->esi + 0xB8u);
    cpu->eax = lift_load32(cpu->esi + 0xBCu);
    lift_store32(cpu->esi + 0x78u, cpu->ecx);
    lift_store32(cpu->esi + 0x7Cu, cpu->edx);
    lift_store32(cpu->esi + 0x80u, cpu->eax);
    label_000967ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4967EDu);
    cpu->eax = 0u;
    if ((uint8_t)((lift_load8(cpu->esi + 4u)) & (0x1Cu)) == 0u) goto label_000967FA;
    cpu->eax = 1u;
    label_000967FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4967FAu);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_00096802;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00096818;
    label_00096802: cpu->eip = LIFT_CODE_TOKEN_VA(0x496802u);
    cpu->ecx = lift_load32(cpu->esi + 0x6Cu);
    cpu->eax = lift_load32(cpu->ebp);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esi + 0x74u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x96815u); lift_push32(cpu, r); sfera_sub_00497CB0(cpu,r); if (cpu->eip != r) return; }
    label_00096815: cpu->eip = LIFT_CODE_TOKEN_VA(0x496815u);
    lift_store32(cpu->esi + 0x68u, cpu->eax);
    label_00096818: cpu->eip = LIFT_CODE_TOKEN_VA(0x496818u);
    cpu->ecx = lift_load32(cpu->esi + 0x68u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0009683F;
    if ((uint32_t)(cpu->ebx) != 0u) goto label_00096835;
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx &= 0x10u;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x96835u); lift_push32(cpu, r); sfera_sub_004958C0(cpu,r); if (cpu->eip != r) return; }
    label_00096835: cpu->eip = LIFT_CODE_TOKEN_VA(0x496835u);
    cpu->eax = lift_load32(cpu->esi + 0x68u);
    lift_store32(cpu->eax + 0x68u, 0u);
    label_0009683F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49683Fu);
    cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x38u, cpu->ebx);
    { uint64_t v=(uint64_t)(cpu->ebx); lift_flags_logic(cpu,v,32u); }
    cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00096853;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49684Du); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    lift_store32(cpu->esi + 0x24u, cpu->edx);
    label_00096853: cpu->eip = LIFT_CODE_TOKEN_VA(0x496853u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 8u, stop_address); return;
    label_00096860: cpu->eip = LIFT_CODE_TOKEN_VA(0x496860u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00496870(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x496870u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x68u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000968A5;
    if ((uint32_t)(lift_load32(cpu->ecx + 0x6Cu)) != (uint32_t)(0u)) goto label_00096894;
    lift_native_call(cpu, native_method_address32(&CSound::IsSoundPlaying), LIFT_CODE_TOKEN_VA(0x496880u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x496886u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00096894;
    cpu->ecx = lift_load32(cpu->esi + 0x68u);
    reinterpret_cast<CSoundFX*>(cpu->ecx)->stop(cpu);
    label_00096894: cpu->eip = LIFT_CODE_TOKEN_VA(0x496894u);
    cpu->eax = lift_load32(cpu->esi + 0x68u);
    lift_store32(cpu->eax + 0x68u, 1u);
    lift_store32(cpu->esi + 0x68u, 0u);
    label_000968A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4968A5u);
    lift_store32(cpu->esi + 8u, 0u);
    lift_store32(cpu->esi + 0x38u, 0u);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004968C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4968C0u);
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x28u);
    lift_store32(cpu->eax + 0x28u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x2Cu);
    lift_store32(cpu->eax + 0x2Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x3Cu);
    lift_store32(cpu->eax + 0x3Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x40u);
    lift_store32(cpu->eax + 0x40u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x44u);
    lift_store32(cpu->eax + 0x44u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x60u));
    lift_store_f32(cpu->eax + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->ecx + 0x64u);
    lift_store32(cpu->eax + 0x64u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x6Cu);
    lift_store32(cpu->eax + 0x6Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x48u);
    lift_store32(cpu->eax + 0x48u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x4Cu);
    lift_store32(cpu->eax + 0x4Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x50u);
    lift_store32(cpu->eax + 0x50u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x54u);
    lift_store32(cpu->eax + 0x54u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x58u);
    lift_store32(cpu->eax + 0x58u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x5Cu);
    lift_store32(cpu->eax + 0x5Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x30u);
    lift_store32(cpu->eax + 0x30u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x34u);
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->eax + 0x34u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x38u);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->eax + 0x38u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x1Cu));
    cpu->esi = (uint32_t)(cpu->ecx + 0x74u);
    lift_store_f32(cpu->eax + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = (uint32_t)(cpu->eax + 0x74u);
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax + 0x70u, 1u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00496960(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x496960u);
    cpu->esp -= 0xCu;
    lift_x87_push(cpu, 0.0);
    cpu->eax = cpu->ecx;
    lift_store32(cpu->eax + 0x68u, 0u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u));
    cpu->ecx = lift_load32(cpu->esp);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u));
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax + 0xB4u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->eax + 0xB8u, cpu->edx);
    lift_store32(cpu->eax + 0xBCu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x28u);
    lift_store32(cpu->eax + 0x28u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x2Cu);
    lift_store32(cpu->eax + 0x2Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x3Cu);
    lift_store32(cpu->eax + 0x3Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x40u);
    lift_store32(cpu->eax + 0x40u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x44u);
    lift_store32(cpu->eax + 0x44u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x60u));
    lift_store_f32(cpu->eax + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->ecx + 0x64u);
    lift_store32(cpu->eax + 0x64u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x6Cu);
    lift_store32(cpu->eax + 0x6Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x48u);
    lift_store32(cpu->eax + 0x48u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x4Cu);
    lift_store32(cpu->eax + 0x4Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x50u);
    lift_store32(cpu->eax + 0x50u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x54u);
    lift_store32(cpu->eax + 0x54u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x58u);
    lift_store32(cpu->eax + 0x58u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x5Cu);
    lift_store32(cpu->eax + 0x5Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x30u);
    lift_store32(cpu->eax + 0x30u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x34u);
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->eax + 0x34u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x38u);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->eax + 0x38u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x1Cu));
    cpu->esi = (uint32_t)(cpu->ecx + 0x74u);
    lift_store_f32(cpu->eax + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = (uint32_t)(cpu->eax + 0x74u);
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->eax + 0x70u, 1u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00496A40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x496A40u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->ebx = 1u;
    lift_push32(cpu, cpu->edi);
    if ((uint8_t)(((cpu->ebx & 0xFFu)) & ((cpu->ecx & 0xFFu))) != 0u) goto label_00096BC0;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    cpu->edi = 0u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xACu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x20u))));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00096B30;
    if ((uint32_t)(lift_load32(cpu->esi + 0x38u)) != (uint32_t)(cpu->edi)) goto label_00096ADB;
    cpu->ecx = lift_load32(cpu->esi + 0x68u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_00096A9A;
    if ((uint32_t)(lift_load32(cpu->ecx + 0x6Cu)) != (uint32_t)(cpu->edi)) goto label_00096A9A;
    lift_native_call(cpu, native_method_address32(&CSound::IsSoundPlaying), LIFT_CODE_TOKEN_VA(0x496A86u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x496A8Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00096A9A;
    cpu->ecx = lift_load32(cpu->esi + 0x68u);
    reinterpret_cast<CSoundFX*>(cpu->ecx)->stop(cpu);
    label_00096A9A: cpu->eip = LIFT_CODE_TOKEN_VA(0x496A9Au);
    if ((uint8_t)((lift_load8(cpu->esi + 4u)) & (0x1Cu)) != 0u) goto label_00096AB2;
    cpu->ecx = lift_load32(cpu->esi + 0x68u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_00096ABF;
    lift_x87_push(cpu, reinterpret_cast<CSound*>(static_cast<uintptr_t>(cpu->ecx))->GetPlayTimepos());
    lift_store_f32(cpu->esi + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_00096ABF;
    label_00096AB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x496AB2u);
    cpu->eax = lift_load32(cpu->esi + 0x68u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00096ABF;
    lift_store32(cpu->eax + 0x68u, cpu->ebx);
    lift_store32(cpu->esi + 0x68u, cpu->edi);
    label_00096ABF: cpu->eip = LIFT_CODE_TOKEN_VA(0x496ABFu);
    lift_store32(cpu->esi + 8u, cpu->edi);
    lift_store32(cpu->esi + 0x38u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496ACAu); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x20u, cpu->eax);
    lift_store32(cpu->esi + 0x24u, cpu->edx);
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_00096ADB: cpu->eip = LIFT_CODE_TOKEN_VA(0x496ADBu);
    if ((uint8_t)(((cpu->ecx & 0xFFu)) & (0x1Cu)) != 0u) goto label_00096B25;
    if ((uint32_t)(lift_load32(cpu->esi + 0x68u)) == (uint32_t)(cpu->edi)) goto label_00096B25;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496AEAu); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x20u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = lift_load32(cpu->esi + 0x68u);
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(lift_load32(cpu->esi + 0x24u)) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_x87_push(cpu, (double)(((int64_t)(lift_load64(cpu->esp + 0xCu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (10000.0));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x50u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00096B25;
    lift_store32(cpu->ecx + 0x68u, cpu->ebx);
    lift_store32(cpu->esi + 0x68u, cpu->edi);
    lift_store32(cpu->esi + 0x38u, cpu->edi);
    label_00096B25: cpu->eip = LIFT_CODE_TOKEN_VA(0x496B25u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_00096B30: cpu->eip = LIFT_CODE_TOKEN_VA(0x496B30u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x38u)) == (uint32_t)(cpu->edi)) goto label_00096BC0;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496B3Eu); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x20u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(lift_load32(cpu->esi + 0x24u)) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 4u)), r=(uint64_t)(0x1Cu), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_x87_push(cpu, (double)(((int64_t)(lift_load64(cpu->esp + 0xCu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (10000.0));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00096BB0;
    cpu->ecx = lift_load32(cpu->esi + 0x68u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_00096BBD;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x1Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x50u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00096B90;
    lift_store32(cpu->ecx + 0x68u, cpu->ebx);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0x68u, cpu->edi);
    lift_store32(cpu->esi + 0x38u, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_00096B90: cpu->eip = LIFT_CODE_TOKEN_VA(0x496B90u);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496BA2u); lift_push32(cpu, r); sfera_sub_004958C0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x38u, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
    label_00096BB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x496BB0u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x96BBDu); lift_push32(cpu, r); sfera_sub_00496650(cpu,r); if (cpu->eip != r) return; }
    label_00096BBD: cpu->eip = LIFT_CODE_TOKEN_VA(0x496BBDu);
    lift_store32(cpu->esi + 0x38u, cpu->edi);
    label_00096BC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x496BC0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00496BD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x496BD0u);
    lift_x87_push(cpu, 0.0);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x24u);
    cpu->esp -= 8u;
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = cpu->ecx;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x30u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496BF1u); lift_push32(cpu, r); sfera_sub_00496A40(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00096DED;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) == (uint32_t)(cpu->ebx)) goto label_00096C95;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496C0Au); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x10u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(lift_load32(cpu->esi + 0x14u)) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_x87_push(cpu, (double)(((int64_t)(lift_load64(cpu->esp + 0xCu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (10000.0));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00096C45;
    lift_store32(cpu->esi + 8u, cpu->ebx);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 8u, stop_address); return;
    label_00096C45: cpu->eip = LIFT_CODE_TOKEN_VA(0x496C45u);
    if ((uint8_t)((lift_load8(cpu->esi + 4u)) & (8u)) == 0u) goto label_00096C79;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x60u))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00096C79;
    lift_push32(cpu, cpu->ebx);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esi + 8u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496C70u); lift_push32(cpu, r); sfera_sub_00496650(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 8u, stop_address); return;
    label_00096C79: cpu->eip = LIFT_CODE_TOKEN_VA(0x496C79u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x18u));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00096DEC;
    lift_store32(cpu->esi + 8u, cpu->ebx);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 8u, stop_address); return;
    label_00096C95: cpu->eip = LIFT_CODE_TOKEN_VA(0x496C95u);
    cpu->ecx = lift_load32(cpu->esi + 0x68u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00096DEC;
    if ((uint32_t)(lift_load32(cpu->ecx + 0x6Cu)) == (uint32_t)(cpu->ebx)) goto label_00096CB8;
    lift_store32(cpu->ecx + 0x68u, 1u);
    lift_store32(cpu->esi + 0x68u, cpu->ebx);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 8u, stop_address); return;
    label_00096CB8: cpu->eip = LIFT_CODE_TOKEN_VA(0x496CB8u);
    if ((uint8_t)((lift_load8(cpu->esi + 4u)) & (8u)) == 0u) goto label_00096CF7;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x50u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x60u))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, reinterpret_cast<CSound*>(static_cast<uintptr_t>(cpu->ecx))->GetPlayTimepos());
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00096CF7;
    cpu->eax = lift_load32(cpu->esi + 0x68u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->eax + 0x68u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496CEEu); lift_push32(cpu, r); sfera_sub_00496650(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0x68u)) == (uint32_t)(cpu->ebx)) goto label_00096DEC;
    label_00096CF7: cpu->eip = LIFT_CODE_TOKEN_VA(0x496CF7u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (1u)) != 0u) goto label_00096DEC;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x3Cu))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x40u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0x44u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (0x20u)) == 0u) goto label_00096D44;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x54u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xCu))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x58u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x5Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00096D44: cpu->eip = LIFT_CODE_TOKEN_VA(0x496D44u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0xB4u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0xB8u))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esi + 0xBCu))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) != (uint32_t)(cpu->ebx)) goto label_00096D80;
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) != (uint32_t)(cpu->ebx)) goto label_00096D80;
    if ((uint32_t)(lift_load32(cpu->esp + 0x20u)) == (uint32_t)(cpu->ebx)) goto label_00096DEC;
    label_00096D80: cpu->eip = LIFT_CODE_TOKEN_VA(0x496D80u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u));
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebx);
    cpu->esp -= 0xCu;
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0xB4u, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    cpu->ecx = lift_load32(cpu->esi + 0x68u);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi + 0xB8u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store32(cpu->esi + 0xBCu, cpu->eax);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_native_call(cpu, native_method_address32(&CSound::SetVelocity), LIFT_CODE_TOKEN_VA(0x496DBCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x496DC2u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xBCu));
    cpu->ecx = lift_load32(cpu->esi + 0x68u);
    lift_push32(cpu, cpu->ebx);
    cpu->esp -= 0xCu;
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xB8u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xB4u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_native_call(cpu, native_method_address32(&CSound::SetPosition), LIFT_CODE_TOKEN_RVA(0x96DE6u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x96DECu);
    label_00096DEC: cpu->eip = LIFT_CODE_TOKEN_VA(0x496DECu);
    cpu->ebx = lift_pop32(cpu);
    label_00096DED: cpu->eip = LIFT_CODE_TOKEN_VA(0x496DEDu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00496E00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x496E00u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_00096EE7;
    lift_native_call(cpu, native_function_address32(&SI_GetInterface), LIFT_CODE_TOKEN_VA(0x496E1Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x496E20u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x20u)) == (uint32_t)(0u)) goto label_00096EE0;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00096EE0;
    if ((uint16_t)(lift_load16(cpu->esi)) != (uint16_t)(1u)) goto label_00096E4F;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->edx = lift_load32(cpu->esi + 0x14u);
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 8u, cpu->ecx);
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    goto label_00096E5B;
    label_00096E4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x496E4Fu);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x96E5Bu); lift_push32(cpu, r); sfera_sub_00455E40(cpu,r); if (cpu->eip != r) return; }
    label_00096E5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x496E5Bu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x24u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esi + 0x20u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00096E97;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 0xACu));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_00096E7F;
    cpu->eax = 1u;
    goto label_00096E81;
    label_00096E7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x496E7Fu);
    cpu->eax = 0u;
    label_00096E81: cpu->eip = LIFT_CODE_TOKEN_VA(0x496E81u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496E8Eu); lift_push32(cpu, r); sfera_sub_00496650(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x24u, 1u);
    goto label_00096EAB;
    label_00096E97: cpu->eip = LIFT_CODE_TOKEN_VA(0x496E97u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0xCu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x96EABu); lift_push32(cpu, r); sfera_sub_00496BD0(cpu,r); if (cpu->eip != r) return; }
    label_00096EAB: cpu->eip = LIFT_CODE_TOKEN_VA(0x496EABu);
    if ((uint32_t)(lift_load32(cpu->edi + 0x38u)) != (uint32_t)(0u)) goto label_00096ECB;
    if ((uint32_t)(lift_load32(cpu->edi + 8u)) != (uint32_t)(0u)) goto label_00096ECB;
    cpu->edi = lift_load32(cpu->edi + 0x68u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00096EC4;
    if ((uint32_t)(lift_load32(cpu->edi + 0x6Cu)) == (uint32_t)(0u)) goto label_00096ECB;
    label_00096EC4: cpu->eip = LIFT_CODE_TOKEN_VA(0x496EC4u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x96ECBu); lift_push32(cpu, r); sfera_sub_00429B20(cpu,r); if (cpu->eip != r) return; }
    label_00096ECB: cpu->eip = LIFT_CODE_TOKEN_VA(0x496ECBu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
    label_00096EE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x496EE0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x96EE7u); lift_push32(cpu, r); sfera_sub_00429B20(cpu,r); if (cpu->eip != r) return; }
    label_00096EE7: cpu->eip = LIFT_CODE_TOKEN_VA(0x496EE7u);
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00496F00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x496F00u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebp = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x70u)) != (uint32_t)(cpu->ebp)) goto label_00096F8C;
    if ((uint32_t)(lift_load32(cpu->esi + 0x28u)) == (uint32_t)(cpu->ebp)) goto label_00096F6C;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x2Cu)) <= (uint32_t)(cpu->ebp)) goto label_00096F50;
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    (void)cpu;
    label_00096F20: cpu->eip = LIFT_CODE_TOKEN_VA(0x496F20u);
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    if ((uint32_t)(lift_load32(cpu->edi + cpu->eax)) == (uint32_t)(cpu->ebp)) goto label_00096F46;
    cpu->edx = 0x29Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496F37u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x28u);
    cpu->edx = lift_load32(cpu->edi + cpu->ecx);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496F43u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00096F46: cpu->eip = LIFT_CODE_TOKEN_VA(0x496F46u);
    ++cpu->ebx;
    cpu->edi += 0xCu;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(lift_load32(cpu->esi + 0x2Cu))) goto label_00096F20;
    cpu->edi = lift_pop32(cpu);
    label_00096F50: cpu->eip = LIFT_CODE_TOKEN_VA(0x496F50u);
    cpu->edx = 0x2A0u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496F5Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x28u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496F68u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ebx = lift_pop32(cpu);
    label_00096F6C: cpu->eip = LIFT_CODE_TOKEN_VA(0x496F6Cu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x30u)) == (uint32_t)(cpu->ebp)) goto label_00096F8C;
    cpu->edx = 0x2A3u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496F80u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x496F89u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00096F8C: cpu->eip = LIFT_CODE_TOKEN_VA(0x496F8Cu);
    cpu->ecx = lift_load32(cpu->esi + 0x68u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebp)) goto label_00096FB9;
    if ((uint32_t)(lift_load32(cpu->ecx + 0x6Cu)) != (uint32_t)(cpu->ebp)) goto label_00096FAC;
    lift_native_call(cpu, native_method_address32(&CSound::IsSoundPlaying), LIFT_CODE_TOKEN_VA(0x496F98u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x496F9Eu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00096FAC;
    cpu->ecx = lift_load32(cpu->esi + 0x68u);
    reinterpret_cast<CSoundFX*>(cpu->ecx)->stop(cpu);
    label_00096FAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x496FACu);
    cpu->ecx = lift_load32(cpu->esi + 0x68u);
    lift_store32(cpu->ecx + 0x68u, 1u);
    lift_store32(cpu->esi + 0x68u, cpu->ebp);
    label_00096FB9: cpu->eip = LIFT_CODE_TOKEN_VA(0x496FB9u);
    lift_store32(cpu->esi + 8u, cpu->ebp);
    lift_store32(cpu->esi + 0x38u, cpu->ebp);
    lift_store32(cpu->esi + 0x28u, cpu->ebp);
    lift_store32(cpu->esi + 0x2Cu, cpu->ebp);
    lift_store32(cpu->esi + 0x30u, cpu->ebp);
    lift_store32(cpu->esi + 0x34u, cpu->ebp);
    lift_store32(cpu->esi + 0x70u, cpu->ebp);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00496FE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x496FE0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x68u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00097015;
    if ((uint32_t)(lift_load32(cpu->ecx + 0x6Cu)) != (uint32_t)(0u)) goto label_00097004;
    lift_native_call(cpu, native_method_address32(&CSound::IsSoundPlaying), LIFT_CODE_TOKEN_VA(0x496FF0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x496FF6u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00097004;
    cpu->ecx = lift_load32(cpu->esi + 0x68u);
    reinterpret_cast<CSoundFX*>(cpu->ecx)->stop(cpu);
    label_00097004: cpu->eip = LIFT_CODE_TOKEN_VA(0x497004u);
    cpu->eax = lift_load32(cpu->esi + 0x68u);
    lift_store32(cpu->eax + 0x68u, 1u);
    lift_store32(cpu->esi + 0x68u, 0u);
    label_00097015: cpu->eip = LIFT_CODE_TOKEN_VA(0x497015u);
    lift_store32(cpu->esi + 8u, 0u);
    lift_store32(cpu->esi + 0x38u, 0u);
    cpu->ecx = g_sfera_sound_effect_items.free_count;
    cpu->edx = g_sfera_sound_effect_items.free_items;
    lift_store32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u), cpu->esi);
    ++g_sfera_sound_effect_items.free_count;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00497040(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497040u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 8u)) < (int32_t)(uint32_t)(cpu->eax)) goto label_000970D2;
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    if ((int32_t)(uint32_t)(cpu->ecx) > 0) goto label_0009705C;
    label_00097057: cpu->eip = LIFT_CODE_TOKEN_VA(0x497057u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0009705C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49705Cu);
    cpu->ecx += cpu->eax;
    lift_store32(cpu->esi + 4u, cpu->ecx);
    cpu->edx = 0x17Au;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497070u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = 4u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497089u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->esp += 4u;
    if ((uint32_t)(cpu->edi) == 0u) goto label_000970D2;
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x49709Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4970A2u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->edx = lift_load32(cpu->esi);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x4970AEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4970B3u);
    cpu->esp += 0x18u;
    cpu->edx = 0x17Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4970C5u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4970CDu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, cpu->edi);
    label_000970D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4970D2u);
    if ((uint32_t)(lift_load32(cpu->esi)) == (uint32_t)(0u)) goto label_00097057;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = 0x18Cu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4970E7u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xC0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4970F1u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00097103;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4970FFu); lift_push32(cpu, r); sfera_sub_00495B30(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    goto label_00097105;
    label_00097103: cpu->eip = LIFT_CODE_TOKEN_VA(0x497103u);
    cpu->ebx = 0u;
    label_00097105: cpu->eip = LIFT_CODE_TOKEN_VA(0x497105u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->edx = lift_load32(cpu->esi);
    if ((uint32_t)(lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u))) == (uint32_t)(0u)) goto label_0009713B;
    cpu->edx = 0x18Du;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49711Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edi = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    if ((uint32_t)(cpu->edi) == 0u) goto label_0009713B;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497132u); lift_push32(cpu, r); sfera_sub_00496F00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497138u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009713B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49713Bu);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->eax = lift_load32(cpu->esi);
    lift_store32(cpu->eax + ((uint32_t)(cpu->edx) * 4u), cpu->ebx);
    lift_store32(cpu->esi + 8u, (uint64_t)(lift_load32(cpu->esi + 8u)) + 1u);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00497150(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497150u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x268u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x278u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"Sounds\\*.def");
    cpu->ebx = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::FindFirstFileA), LIFT_CODE_TOKEN_VA(0x49719Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4971A2u);
    cpu->esi = cpu->eax;
    cpu->eax = 0u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009731A;
    label_000971C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4971C0u);
    if ((uint8_t)((lift_load8(cpu->esp + 0x2Cu)) & (0x10u)) != 0u) goto label_00097302;
    cpu->ecx = lift_load32((uintptr_t)"Sounds\\");
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"Sounds\\") + 4u);
    cpu->eax = (uint32_t)(cpu->esp + 0x58u);
    lift_store32(cpu->esp + 0x16Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x170u, cpu->edx);
    cpu->esi = cpu->eax;
    label_000971F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4971F0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000971F0;
    cpu->edi = (uint32_t)(cpu->esp + 0x16Cu);
    cpu->eax -= cpu->esi;
    --cpu->edi;
    label_00097201: cpu->eip = LIFT_CODE_TOKEN_VA(0x497201u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00097201;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->edx = 0x1A8u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497226u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x420u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497230u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_store32(cpu->esp + 0x280u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00097251;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49724Du); lift_push32(cpu, r); sfera_sub_00493BF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    goto label_00097253;
    label_00097251: cpu->eip = LIFT_CODE_TOKEN_VA(0x497251u);
    cpu->esi = 0u;
    label_00097253: cpu->eip = LIFT_CODE_TOKEN_VA(0x497253u);
    cpu->eax = (uint32_t)(cpu->esp + 0x16Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x284u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49726Du); lift_push32(cpu, r); sfera_sub_00494940(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497276u); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"soundeffect");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497287u); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000972DF;
    label_00097290: cpu->eip = LIFT_CODE_TOKEN_VA(0x497290u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497297u); lift_push32(cpu, r); sfera_sub_00497040(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    cpu->edi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4972A5u); lift_push32(cpu, r); sfera_sub_00494900(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4972B2u); lift_push32(cpu, r); sfera_sub_00495F40(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000972BE;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + 8u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->ebx + 8u, v); }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_000972BE;
    lift_store32(cpu->ebx + 8u, cpu->eax);
    label_000972BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4972BEu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4972CAu); lift_push32(cpu, r); sfera_sub_00494850(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"soundeffect");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4972DBu); lift_push32(cpu, r); sfera_sub_004948C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00097290;
    label_000972DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4972DFu);
    cpu->edx = 0x1BBu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4972EEu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) == 0u) goto label_00097302;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4972F9u); lift_push32(cpu, r); sfera_sub_00493C00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4972FFu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00097302: cpu->eip = LIFT_CODE_TOKEN_VA(0x497302u);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindNextFileA), LIFT_CODE_TOKEN_VA(0x49730Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x497312u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000971C0;
    label_0009731A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49731Au);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::FindClose), LIFT_CODE_TOKEN_VA(0x49731Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x497321u);
    if ((uint32_t)(lift_load32(cpu->ebx)) == (uint32_t)(0u)) goto label_00097339;
    cpu->eax = lift_load32(cpu->ebx + 8u);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(1u)) goto label_00097339;
    --cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x97339u); lift_push32(cpu, r); sfera_sub_00495A30(cpu,r); if (cpu->eip != r) return; }
    label_00097339: cpu->eip = LIFT_CODE_TOKEN_VA(0x497339u);
    cpu->eax = 1u;
    cpu->ecx = lift_load32(cpu->esp + 0x278u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00497370(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497370u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    if ((uint32_t)(g_sfera_sound_runtime.effect_manager) != (uint32_t)(0u)) goto label_000973E6;
    cpu->edx = 0x67u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4973A9u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4973B0u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_store32(cpu->esp + 0x10u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000973D0;
    lift_push32(cpu, 0x32u); lift_push32(cpu, 0x64u);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4973CEu); lift_push32(cpu, r); sfera_sub_004959B0(cpu,r); if (cpu->eip != r) return; }
    goto label_000973D2;
    label_000973D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4973D0u);
    cpu->eax = 0u;
    label_000973D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4973D2u);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x10u, 0xFFFFFFFFu);
    g_sfera_sound_runtime.effect_manager = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x973E6u); lift_push32(cpu, r); sfera_sub_00497150(cpu,r); if (cpu->eip != r) return; }
    label_000973E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4973E6u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00497400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497400u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi)) == (uint32_t)(0u)) goto label_00097469;
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 4u)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_00097448;
    lift_push32(cpu, cpu->ebx);
    label_00097411: cpu->eip = LIFT_CODE_TOKEN_VA(0x497411u);
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u))) == (uint32_t)(0u)) goto label_00097441;
    cpu->edx = 0x117u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497428u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi);
    cpu->ebx = lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u));
    if ((uint32_t)(cpu->ebx) == 0u) goto label_00097441;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497438u); lift_push32(cpu, r); sfera_sub_00496F00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49743Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00097441: cpu->eip = LIFT_CODE_TOKEN_VA(0x497441u);
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00097411;
    cpu->ebx = lift_pop32(cpu);
    label_00097448: cpu->eip = LIFT_CODE_TOKEN_VA(0x497448u);
    cpu->edx = 0x119u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497457u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49745Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi, 0u);
    cpu->edi = lift_pop32(cpu);
    label_00097469: cpu->eip = LIFT_CODE_TOKEN_VA(0x497469u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00497470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497470u);
    if ((uint32_t)(g_sfera_sound_runtime.effect_manager) == (uint32_t)(0u)) goto label_000974AE;
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0x77u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundEffect.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497489u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_sound_runtime.effect_manager;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000974A3;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49749Au); lift_push32(cpu, r); sfera_sub_00497400(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4974A0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000974A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4974A3u);
    g_sfera_sound_runtime.effect_manager = (uint32_t)(0u);
    cpu->esi = lift_pop32(cpu);
    label_000974AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4974AEu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004974B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4974B0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(lift_load32(cpu->esi + 0x10u)) == (uint32_t)(cpu->ebx)) goto label_000974D8;
    cpu->edx = (uint32_t)(cpu->ebx + 0x48u);
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ItemArray.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4974C9u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4974D2u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    label_000974D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4974D8u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esi + 4u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(lift_load32(cpu->esi)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ebp = v; }
    lift_store32(cpu->esi + 0x14u, cpu->ebx);
    cpu->ebp = lift_shift_arithmetic(cpu, cpu->ebp, (uint32_t)(2u), 32u);
    if ((int32_t)(uint32_t)(cpu->ebp) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0009752D;
    label_000974F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4974F0u);
    cpu->edx = 0x4Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ItemArray.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4974FFu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->ebx) * 4u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_00097528;
    cpu->edx = lift_load32(cpu->eax + 0xFFFFFFFCu);
    cpu->edi = (uint32_t)(cpu->eax + 0xFFFFFFFCu);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00425940)); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0xC0u); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49751Fu); lift_push32(cpu, r); sfera_sub_004EEB86(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497525u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00097528: cpu->eip = LIFT_CODE_TOKEN_VA(0x497528u);
    ++cpu->ebx;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->ebp)) goto label_000974F0;
    label_0009752D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49752Du);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edi = lift_load32(cpu->esi);
    cpu->ebp = lift_pop32(cpu);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ecx)) goto label_00097556;
    cpu->eax = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ebx = (uint32_t)(((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x497548u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49754Eu);
    cpu->esp += 0xCu;
    cpu->ebx += cpu->edi;
    lift_store32(cpu->esi + 4u, cpu->ebx);
    label_00097556: cpu->eip = LIFT_CODE_TOKEN_VA(0x497556u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00497560(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497560u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    cpu->edx = 0x60u;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ItemArray.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497596u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi + 0x18u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->edi;
    cpu->edx = 0xC0u;
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4975BDu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_000975EB;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00425940)); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00495B30)); lift_push32(cpu, cpu->edi);
    cpu->ebx = (uint32_t)(cpu->eax + 4u);
    lift_push32(cpu, 0xC0u); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->eax, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4975E9u); lift_push32(cpu, r); sfera_sub_004EEBE9(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->ebx;
    label_000975EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4975EBu);
    cpu->edx = 0x62u;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ItemArray.h";
    lift_store32(cpu->esp + 0x20u, 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497606u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497629u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00097662;
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x49763Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x497644u);
    cpu->esp += 0xCu;
    cpu->edx = 0x67u;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ItemArray.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497656u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49765Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00097662: cpu->eip = LIFT_CODE_TOKEN_VA(0x497662u);
    cpu->ecx = 0u;
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    cpu->eax = cpu->ebp;
    cpu->ebx = (uint32_t)(cpu->ecx + 1u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x18u)) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_00097689;
    label_00097671: cpu->eip = LIFT_CODE_TOKEN_VA(0x497671u);
    cpu->edx = lift_load32(cpu->esi + 0x14u);
    cpu->edi = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->edi + ((uint32_t)(cpu->edx) * 4u), cpu->eax);
    lift_store32(cpu->esi + 0x14u, (uint64_t)(lift_load32(cpu->esi + 0x14u)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u));
    cpu->ecx += cpu->ebx;
    cpu->eax += 0xC0u;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x18u))) goto label_00097671;
    label_00097689: cpu->eip = LIFT_CODE_TOKEN_VA(0x497689u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000976FD;
    cpu->edx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->ecx)) goto label_000976FD;
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 8u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000976ED;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(0x3FFFFFFEu)) goto label_000976BF;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x976BFu);
    label_000976BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4976BFu);
    cpu->ecx -= cpu->edx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_000976ED;
    cpu->edx = cpu->ecx;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->ebx = 0x3FFFFFFFu;
    cpu->ebx -= cpu->edx;
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(cpu->ecx)) goto label_000976DD;
    cpu->ecx = 0u;
    goto label_000976DF;
    label_000976DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4976DDu);
    cpu->ecx += cpu->edx;
    label_000976DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4976DFu);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_000976E5;
    cpu->ecx = cpu->eax;
    label_000976E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4976E5u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x976EDu); lift_push32(cpu, r); sfera_sub_00429830(cpu,r); if (cpu->eip != r) return; }
    label_000976ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4976EDu);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00097754;
    cpu->edx = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    lift_store32(cpu->eax, cpu->ecx);
    goto label_00097754;
    label_000976FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4976FDu);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_0009774B;
    cpu->edx = lift_load32(cpu->esi);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(0x3FFFFFFEu)) goto label_0009771D;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x9771Du);
    label_0009771D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49771Du);
    cpu->ecx -= cpu->edx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0009774B;
    cpu->edx = cpu->ecx;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->edi = 0x3FFFFFFFu;
    cpu->edi -= cpu->edx;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->ecx)) goto label_0009773B;
    cpu->ecx = 0u;
    goto label_0009773D;
    label_0009773B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49773Bu);
    cpu->ecx += cpu->edx;
    label_0009773D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49773Du);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_00097743;
    cpu->ecx = cpu->eax;
    label_00097743: cpu->eip = LIFT_CODE_TOKEN_VA(0x497743u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9774Bu); lift_push32(cpu, r); sfera_sub_00429830(cpu,r); if (cpu->eip != r) return; }
    label_0009774B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49774Bu);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00097754;
    lift_store32(cpu->eax, cpu->ebp);
    label_00097754: cpu->eip = LIFT_CODE_TOKEN_VA(0x497754u);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(4u) + (uint64_t)(0u));
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00497770(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497770u);
    if ((uint32_t)(lift_load32(cpu->ecx + 8u)) == (uint32_t)(0u)) goto label_000977D4;
    if ((uint32_t)(lift_load32(cpu->ecx)) == (uint32_t)(0u)) goto label_000977D4;
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497786u); lift_push32(cpu, r); sfera_sub_00495AC0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) == 0u) goto label_000977CE;
    if ((uint32_t)(g_sfera_sound_effect_items.free_count) != (uint32_t)(0u)) goto label_0009779F;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_sound_effect_items;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9779Fu); lift_push32(cpu, r); sfera_sub_00497560(cpu,r); if (cpu->eip != r) return; }
    label_0009779F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49779Fu);
    cpu->eax = g_sfera_sound_effect_items.free_count;
    cpu->ecx = g_sfera_sound_effect_items.free_items;
    --cpu->eax;
    lift_push32(cpu, cpu->esi);
    g_sfera_sound_effect_items.free_count = (uint32_t)(cpu->eax);
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    if ((uint32_t)(cpu->esi) != 0u) goto label_000977BF;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000977BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4977BFu);
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4977C7u); lift_push32(cpu, r); sfera_sub_00496960(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000977CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4977CEu);
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000977D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4977D4u);
    cpu->eax = 0u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004977E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4977E0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = cpu->edx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(0x1388u)) goto label_000977FC;
    cpu->esi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000977FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4977FCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if ((uint32_t)(g_sfera_sound_runtime.effect_manager) == (uint32_t)(cpu->edi)) goto label_00097811;
    lift_native_call(cpu, native_function_address32(&SI_GetInterface), LIFT_CODE_TOKEN_VA(0x497807u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49780Du);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009781B;
    label_00097811: cpu->eip = LIFT_CODE_TOKEN_VA(0x497811u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0009781B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49781Bu);
    cpu->ecx = g_sfera_sound_runtime.effect_manager;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497828u); lift_push32(cpu, r); sfera_sub_00497770(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->edi)) goto label_00097882;
    if ((uint32_t)(g_sfera_effect_items.free_count) != (uint32_t)(cpu->edi)) goto label_00097840;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_effect_items;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x97840u); lift_push32(cpu, r); sfera_sub_0042A480(cpu,r); if (cpu->eip != r) return; }
    label_00097840: cpu->eip = LIFT_CODE_TOKEN_VA(0x497840u);
    cpu->eax = g_sfera_effect_items.free_count;
    cpu->ecx = g_sfera_effect_items.free_items;
    --cpu->eax;
    g_sfera_effect_items.free_count = (uint32_t)(cpu->eax);
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) != (uint32_t)(cpu->edi)) goto label_0009788D;
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497863u); lift_push32(cpu, r); sfera_sub_00456040(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009788D;
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49786Eu); lift_push32(cpu, r); sfera_sub_00496FE0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_effect_items.free_count;
    cpu->eax = g_sfera_effect_items.free_items;
    lift_store32(cpu->eax + ((uint32_t)(cpu->edx) * 4u), cpu->esi);
    ++g_sfera_effect_items.free_count;
    label_00097882: cpu->eip = LIFT_CODE_TOKEN_VA(0x497882u);
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0009788D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49788Du);
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->esp + 0x18u)) & 0xFFFFu);
    lift_store32(cpu->esi + 4u, cpu->ebx);
    cpu->edx = cpu->ebx;
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    lift_store16(cpu->esi, cpu->ecx & 0xFFFFu);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->esi + 8u, cpu->edi);
    lift_store32(cpu->esi + 0x1Cu, cpu->edi);
    lift_store32(cpu->esi + 0x20u, cpu->ebp);
    lift_store32(cpu->esi + 0x24u, cpu->edi);
    lift_store32(cpu->esi + 0x18u, LIFT_CALLBACK(sfera_sub_00496E00));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4978B8u); lift_push32(cpu, r); sfera_sub_00425B20(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esi + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = 0xFFFFu;
    lift_store16(cpu->esi + 2u, cpu->eax & 0xFFFFu);
    cpu->eax = 1u;
    lift_store32(cpu->esi + 0x28u, cpu->edx);
    lift_store32(cpu->esi + 0x30u, cpu->edi);
    lift_store32(cpu->esi + 0x34u, cpu->edi);
    lift_store32(cpu->esi + 0x38u, cpu->edi);
    g_sfera_effect_manager.active_effect_count += cpu->eax;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_effect_manager.active_resource_count, (uint64_t)(g_sfera_effect_manager.active_resource_count) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_effect_manager.active_effects;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4978F0u); lift_push32(cpu, r); sfera_sub_00425C00(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->edi)) goto label_00097905;
    cpu->ecx = lift_load32(cpu->ebx);
    lift_store32(cpu->esi + 0xCu, cpu->ecx);
    cpu->edx = lift_load32(cpu->ebx + 4u);
    lift_store32(cpu->esi + 0x10u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebx + 8u);
    lift_store32(cpu->esi + 0x14u, cpu->eax);
    label_00097905: cpu->eip = LIFT_CODE_TOKEN_VA(0x497905u);
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00497910(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497910u);
    cpu->eax = cpu->ecx;
    cpu->ecx = g_sfera_sound_runtime.effect_manager;
    if ((uint32_t)(cpu->ecx) != 0u) goto label_0009791F;
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
    label_0009791F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49791Fu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497925u); lift_push32(cpu, r); sfera_sub_00497770(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00497930(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497930u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    ::new (reinterpret_cast<void*>(static_cast<uintptr_t>(cpu->ecx))) CSound();
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497939u);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x60u, cpu->ecx);
    lift_store32(cpu->esi + 0x64u, cpu->ecx);
    cpu->ecx = 1u;
    lift_store32(cpu->esi + 0x58u, cpu->eax);
    lift_store32(cpu->esi + 0x70u, cpu->eax);
    lift_store32(cpu->esi + 0x74u, cpu->eax);
    std::construct_at(reinterpret_cast<CSoundFX*>(cpu->esi));
    lift_store32(cpu->esi + 0x68u, cpu->ecx);
    lift_store32(cpu->esi + 0x6Cu, cpu->ecx);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00497970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497970u);
    cpu->eax = g_sfera_sound_runtime.manager;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00497980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497980u);
    cpu->eax = g_sfera_sound_runtime.manager;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00097997;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (100.0));
    sfera_sub_004EE940(cpu, stop_address); return;
    label_00097997: cpu->eip = LIFT_CODE_TOKEN_VA(0x497997u);
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004979A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4979A0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->edx = 0u;
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(cpu->edx)) goto label_000979BD;
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    lift_store32(cpu->eax + 0x70u, cpu->edx);
    cpu->eax = lift_load32(cpu->ecx);
    lift_store32(cpu->eax + 0x74u, cpu->edx);
    lift_store32(cpu->ecx + 0x10u, (uint64_t)(lift_load32(cpu->ecx + 0x10u)) + 1u);
    lift_return(cpu, 4u, stop_address); return;
    label_000979BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4979BDu);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 0x74u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->edx + 0x70u, cpu->eax);
    lift_store32(cpu->ecx + 0x10u, (uint64_t)(lift_load32(cpu->ecx + 0x10u)) + 1u);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004979E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4979E0u);
    cpu->eax = lift_load32(cpu->ecx + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000979EB;
    --cpu->eax;
    lift_store32(cpu->ecx + 0x10u, cpu->eax);
    label_000979EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4979EBu);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->edx = lift_load32(cpu->eax + 0x74u);
    if ((uint32_t)(cpu->edx) != 0u) goto label_00097A03;
    if ((uint32_t)(lift_load32(cpu->eax + 0x70u)) != (uint32_t)(cpu->edx)) goto label_00097A03;
    lift_store32(cpu->ecx, cpu->edx);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_return(cpu, 4u, stop_address); return;
    label_00097A03: cpu->eip = LIFT_CODE_TOKEN_VA(0x497A03u);
    if ((uint32_t)(lift_load32(cpu->ecx + 4u)) != (uint32_t)(cpu->eax)) goto label_00097A15;
    lift_store32(cpu->ecx + 4u, cpu->edx);
    lift_store32(cpu->edx + 0x70u, 0u);
    lift_return(cpu, 4u, stop_address); return;
    label_00097A15: cpu->eip = LIFT_CODE_TOKEN_VA(0x497A15u);
    if ((uint32_t)(lift_load32(cpu->ecx)) != (uint32_t)(cpu->eax)) goto label_00097A28;
    cpu->eax = lift_load32(cpu->eax + 0x70u);
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->eax + 0x74u, 0u);
    lift_return(cpu, 4u, stop_address); return;
    label_00097A28: cpu->eip = LIFT_CODE_TOKEN_VA(0x497A28u);
    cpu->ecx = cpu->edx;
    cpu->edx = lift_load32(cpu->eax + 0x70u);
    lift_store32(cpu->ecx + 0x70u, cpu->edx);
    cpu->ecx = lift_load32(cpu->eax + 0x70u);
    cpu->edx = lift_load32(cpu->eax + 0x74u);
    lift_store32(cpu->ecx + 0x74u, cpu->edx);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00497A40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497A40u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->esi) != 0u) goto label_00097A4D;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00097A4D: cpu->eip = LIFT_CODE_TOKEN_VA(0x497A4Du);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::_stricmp);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_method_address32(&CSound::IsSoundPlaying);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    label_00097A60: cpu->eip = LIFT_CODE_TOKEN_VA(0x497A60u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00097A7A;
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x97A6Bu), LIFT_CODE_TOKEN_RVA(0x97A69u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497A6Bu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00097A7A;
    cpu->ecx = cpu->esi;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x97A76u), LIFT_CODE_TOKEN_RVA(0x97A74u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497A76u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00097A8A;
    label_00097A7A: cpu->eip = LIFT_CODE_TOKEN_VA(0x497A7Au);
    cpu->esi = lift_load32(cpu->esi + 0x70u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_00097A60;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00097A8A: cpu->eip = LIFT_CODE_TOKEN_VA(0x497A8Au);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00497AA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497AA0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00097AB6;
    lift_store32(cpu->esp + 0xCu, 0u);
    goto label_00097AC3;
    label_00097AB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x497AB6u);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(0x64u)) goto label_00097AC3;
    lift_store32(cpu->esp + 0xCu, 0x64u);
    label_00097AC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x497AC3u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    cpu->esi = lift_load32(cpu->edi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (100.0));
    lift_store_f32(cpu->edi + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->esi) == 0u) goto label_00097AF3;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_method_address32(&CSound::SetVolume);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00097AE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x497AE0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 8u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x97AEBu), LIFT_CODE_TOKEN_RVA(0x97AE9u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497AEBu);
    cpu->esi = lift_load32(cpu->esi + 0x70u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_00097AE0;
    cpu->ebx = lift_pop32(cpu);
    label_00097AF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x497AF3u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00497B00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497B00u);
    cpu->eax = g_sfera_sound_runtime.manager;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00097B5E;
    lift_native_call(cpu, native_function_address32(&SI_GetInterface), LIFT_CODE_TOKEN_VA(0x497B09u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x497B0Fu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00097B14;
    lift_return(cpu, 0u, stop_address); return;
    label_00097B14: cpu->eip = LIFT_CODE_TOKEN_VA(0x497B14u);
    cpu->edx = 0x44u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497B23u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497B2Au); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00097B57;
    lift_x87_push(cpu, 1.0);
    lift_store32(cpu->eax, 0u);
    lift_store_f32(cpu->eax + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->eax + 4u, 0u);
    lift_store32(cpu->eax + 0xCu, 0u);
    lift_store32(cpu->eax + 0x10u, 0u);
    g_sfera_sound_runtime.manager = (uint32_t)(cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
    label_00097B57: cpu->eip = LIFT_CODE_TOKEN_VA(0x497B57u);
    cpu->eax = 0u;
    g_sfera_sound_runtime.manager = (uint32_t)(cpu->eax);
    label_00097B5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x497B5Eu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00497B60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497B60u);
    cpu->eax = cpu->ecx;
    cpu->ecx = g_sfera_sound_runtime.manager;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00097B72;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x97B72u); lift_push32(cpu, r); sfera_sub_00497AA0(cpu,r); if (cpu->eip != r) return; }
    label_00097B72: cpu->eip = LIFT_CODE_TOKEN_VA(0x497B72u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00497B80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497B80u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->edi + 0xCu)) == (uint32_t)(0u)) goto label_00097C5F;
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497BB9u); lift_push32(cpu, r); sfera_sub_00497A40(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00097BD1;
    if ((uint32_t)(lift_load32(cpu->esi + 0x68u)) == (uint32_t)(0u)) goto label_00097BD1;
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esi + 0x58u, cpu->eax);
    goto label_00097C85;
    label_00097BD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x497BD1u);
    lift_push32(cpu, (uintptr_t)"rb"); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x497BD7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x497BDDu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00097C5F;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x497BE5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x497BEBu);
    cpu->esp += 4u;
    cpu->edx = 0x16Bu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497BFDu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x78u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497C04u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00097C22;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497C1Eu); lift_push32(cpu, r); sfera_sub_00497930(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    goto label_00097C24;
    label_00097C22: cpu->eip = LIFT_CODE_TOKEN_VA(0x497C22u);
    cpu->esi = 0u;
    label_00097C24: cpu->eip = LIFT_CODE_TOKEN_VA(0x497C24u);
    lift_store32(cpu->esp + 0x18u, 0xFFFFFFFFu);
    if ((uint32_t)(cpu->esi) == 0u) goto label_00097C5F;
    lift_push32(cpu, 8u); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_native_call(cpu, native_method_address32(&CSound::LoadSound), LIFT_CODE_TOKEN_VA(0x497C35u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x497C3Bu);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00097C76;
    cpu->edx = 0x171u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497C4Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    reinterpret_cast<CSound*>(static_cast<uintptr_t>(cpu->ecx))->~CSound();
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497C56u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497C5Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00097C5F: cpu->eip = LIFT_CODE_TOKEN_VA(0x497C5Fu);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 8u, stop_address); return;
    label_00097C76: cpu->eip = LIFT_CODE_TOKEN_VA(0x497C76u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497C7Eu); lift_push32(cpu, r); sfera_sub_004979A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esi + 0x58u, cpu->ecx);
    label_00097C85: cpu->eip = LIFT_CODE_TOKEN_VA(0x497C85u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 8u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_native_call(cpu, native_method_address32(&CSound::SetVolume), LIFT_CODE_TOKEN_VA(0x497C8Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x497C94u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00497CB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497CB0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->edi + 0xCu)) == (uint32_t)(0u)) goto label_00097D96;
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497CE9u); lift_push32(cpu, r); sfera_sub_00497A40(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00097D08;
    if ((uint32_t)(lift_load32(cpu->esi + 0x68u)) == (uint32_t)(0u)) goto label_00097D08;
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, 0u);
    lift_store32(cpu->esi + 0x58u, cpu->eax);
    lift_push32(cpu, cpu->ecx);
    goto label_00097DC3;
    label_00097D08: cpu->eip = LIFT_CODE_TOKEN_VA(0x497D08u);
    lift_push32(cpu, (uintptr_t)"rb"); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x497D0Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x497D14u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00097D96;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x497D1Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x497D22u);
    cpu->esp += 4u;
    cpu->edx = 0x199u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497D34u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x78u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497D3Bu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00097D59;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497D55u); lift_push32(cpu, r); sfera_sub_00497930(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    goto label_00097D5B;
    label_00097D59: cpu->eip = LIFT_CODE_TOKEN_VA(0x497D59u);
    cpu->esi = 0u;
    label_00097D5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x497D5Bu);
    lift_store32(cpu->esp + 0x18u, 0xFFFFFFFFu);
    if ((uint32_t)(cpu->esi) == 0u) goto label_00097D96;
    lift_push32(cpu, 0x29u); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_native_call(cpu, native_method_address32(&CSound::LoadSound), LIFT_CODE_TOKEN_VA(0x497D6Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x497D72u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00097DAD;
    cpu->edx = 0x19Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497D85u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    reinterpret_cast<CSound*>(static_cast<uintptr_t>(cpu->ecx))->~CSound();
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497D8Du);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497D93u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00097D96: cpu->eip = LIFT_CODE_TOKEN_VA(0x497D96u);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
    label_00097DAD: cpu->eip = LIFT_CODE_TOKEN_VA(0x497DADu);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497DB5u); lift_push32(cpu, r); sfera_sub_004979A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, 0u);
    lift_store32(cpu->esi + 0x58u, cpu->edx);
    lift_push32(cpu, cpu->eax);
    label_00097DC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x497DC3u);
    cpu->ecx = cpu->esi;
    lift_native_call(cpu, native_method_address32(&CSound::SetAllParameters), LIFT_CODE_TOKEN_VA(0x497DC5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x497DCBu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi + 8u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_native_call(cpu, native_method_address32(&CSound::SetVolume), LIFT_CODE_TOKEN_VA(0x497DD4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x497DDAu);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00497E00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497E00u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ebp = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_00097EB6;
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, cpu->esi);
    label_00097E16: cpu->eip = LIFT_CODE_TOKEN_VA(0x497E16u);
    cpu->esi = cpu->ebp;
    cpu->ebp = lift_load32(cpu->ebp + 0x70u);
    cpu->ecx = cpu->esi;
    lift_native_call(cpu, native_method_address32(&CSound::IsSoundPlaying), LIFT_CODE_TOKEN_VA(0x497E1Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x497E23u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00097E2E;
    lift_store32(cpu->esi + 0x6Cu, 1u);
    label_00097E2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x497E2Eu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x6Cu)) == (uint32_t)(0u)) goto label_00097EAC;
    if ((uint32_t)(lift_load32(cpu->esi + 0x68u)) == (uint32_t)(0u)) goto label_00097EAC;
    cpu->eax = lift_load32(cpu->esi + 0x58u);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_00097EAC;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00097E52;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497E4Bu); lift_push32(cpu, r); sfera_sub_004979E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0x1D4u;
    goto label_00097E95;
    label_00097E52: cpu->eip = LIFT_CODE_TOKEN_VA(0x497E52u);
    cpu->eax = lift_load32(cpu->esi + 0x60u);
    cpu->eax &= lift_load32(cpu->esi + 0x64u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_00097E6A;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497E62u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x60u, cpu->eax);
    lift_store32(cpu->esi + 0x64u, cpu->edx);
    goto label_00097EAC;
    label_00097E6A: cpu->eip = LIFT_CODE_TOKEN_VA(0x497E6Au);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497E6Fu); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x60u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_push32(cpu, 0u);
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(lift_load32(cpu->esi + 0x64u)) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_push32(cpu, 0x2710u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497E83u); lift_push32(cpu, r); sfera_sub_004EEA40(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x58u))) goto label_00097EAC;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497E90u); lift_push32(cpu, r); sfera_sub_004979E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0x1E3u;
    label_00097E95: cpu->eip = LIFT_CODE_TOKEN_VA(0x497E95u);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497E9Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    reinterpret_cast<CSound*>(static_cast<uintptr_t>(cpu->ecx))->~CSound();
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497EA3u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497EA9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00097EAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x497EACu);
    if ((uint32_t)(cpu->ebp) != 0u) goto label_00097E16;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00097EB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x497EB6u);
    lift_native_call(cpu, native_function_address32(&SI_GetInterface), LIFT_CODE_TOKEN_VA(0x497EB6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x497EBCu);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00097ECA;
    cpu->ecx = cpu->eax;
    lift_native_call_return(cpu, (uint32_t)(native_method_address32(&CSoundInterface::UpdateSettings)), LIFT_CODE_TOKEN_VA(0x497EC4u), stop_address); return;
    label_00097ECA: cpu->eip = LIFT_CODE_TOKEN_VA(0x497ECAu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00497ED0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x497ED0u);
    cpu->esp -= 0x58u;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&SI_GetInterface), LIFT_CODE_TOKEN_VA(0x497EDFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x497EE5u);
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0009804D;
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497EF8u); lift_push32(cpu, r); sfera_sub_00455FD0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x497F05u); lift_push32(cpu, r); sfera_sub_00468050(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    cpu->edx = lift_load32(cpu->ecx + 0xCu);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x10u);
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_method_address32(&CSoundListener::GetOrientation), LIFT_CODE_TOKEN_VA(0x497F5Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x497F63u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x40u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x1Cu))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x44u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x20u))));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x48u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x24u))));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00097FA2;
    if ((uint32_t)(lift_load32(cpu->esp + 8u)) != (uint32_t)(0u)) goto label_00097FA2;
    if ((uint32_t)(lift_load32(cpu->esp + 0xCu)) == (uint32_t)(0u)) goto label_00097FE2;
    label_00097FA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x497FA2u);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, 0u);
    cpu->esp -= 0xCu;
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_native_call(cpu, native_method_address32(&CSoundListener::SetPosition), LIFT_CODE_TOKEN_VA(0x497FB5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x497FBBu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, 0u);
    cpu->esp -= 0xCu;
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_native_call(cpu, native_method_address32(&CSoundListener::SetVelocity), LIFT_CODE_TOKEN_VA(0x497FDAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x497FE0u);
    goto label_00097FE8;
    label_00097FE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x497FE2u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_00097FE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x497FE8u);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esp + 0x28u))) goto label_00098024;
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esp + 0x2Cu))) goto label_00098024;
    cpu->eax = lift_load32(cpu->esp + 0x3Cu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esp + 0x30u))) goto label_00098024;
    cpu->ecx = lift_load32(cpu->esp + 0x4Cu);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(lift_load32(cpu->esp + 0x10u))) goto label_00098024;
    cpu->edx = lift_load32(cpu->esp + 0x50u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_00098024;
    cpu->eax = lift_load32(cpu->esp + 0x54u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esp + 0x18u))) goto label_00098039;
    label_00098024: cpu->eip = LIFT_CODE_TOKEN_VA(0x498024u);
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_method_address32(&CSoundListener::SetOrientation), LIFT_CODE_TOKEN_RVA(0x98033u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x98039u);
    label_00098039: cpu->eip = LIFT_CODE_TOKEN_VA(0x498039u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49803Eu); lift_push32(cpu, r); sfera_sub_00499810(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_sound_runtime.manager;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0009804D;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9804Du); lift_push32(cpu, r); sfera_sub_00497E00(cpu,r); if (cpu->eip != r) return; }
    label_0009804D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49804Du);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x58u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00498060(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x498060u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->edx;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00098094;
    lift_native_call(cpu, native_function_address32(&SI_GetInterface), LIFT_CODE_TOKEN_VA(0x49806Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x498070u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00098094;
    cpu->ecx = g_sfera_sound_runtime.manager;
    lift_push32(cpu, 4u); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498082u); lift_push32(cpu, r); sfera_sub_00497B80(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00098094;
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x98094u); lift_push32(cpu, r); sfera_sub_004958C0(cpu,r); if (cpu->eip != r) return; }
    label_00098094: cpu->eip = LIFT_CODE_TOKEN_VA(0x498094u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004980A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4980A0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebp);
    if ((uint32_t)(cpu->esi) == 0u) goto label_000980DA;
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, cpu->edi);
    label_000980B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4980B3u);
    cpu->edi = cpu->esi;
    cpu->esi = lift_load32(cpu->esi + 0x70u);
    cpu->edx = 0x139u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4980C7u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edi;
    reinterpret_cast<CSound*>(static_cast<uintptr_t>(cpu->ecx))->~CSound();
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4980CBu);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4980D1u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->esi) != 0u) goto label_000980B3;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_000980DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4980DAu);
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebp + 4u, 0u);
    lift_store32(cpu->ebp, 0u);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004980F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4980F0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&SI_SetLogFile), LIFT_CODE_TOKEN_VA(0x4980F5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4980FBu);
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, 0u); lift_push32(cpu, 0xAC44u); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&SI_CreateInterface), LIFT_CODE_TOKEN_VA(0x49810Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x498110u);
    cpu->esp += 0x14u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000981E1;
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498121u); lift_push32(cpu, r); sfera_sub_00497B00(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) == 0u) goto label_00098160;
    lift_native_call(cpu, native_function_address32(&SI_GetInterface), LIFT_CODE_TOKEN_VA(0x498127u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49812Du);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00098159;
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->esi) == 0u) goto label_00098148;
    label_00098138: cpu->eip = LIFT_CODE_TOKEN_VA(0x498138u);
    cpu->ecx = cpu->esi;
    reinterpret_cast<CSoundFX*>(cpu->ecx)->stop(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x498141u);
    cpu->esi = lift_load32(cpu->esi + 0x70u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_00098138;
    label_00098148: cpu->eip = LIFT_CODE_TOKEN_VA(0x498148u);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49814Fu); lift_push32(cpu, r); sfera_sub_004980A0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0xCu, 0u);
    cpu->esi = lift_pop32(cpu);
    goto label_00098160;
    label_00098159: cpu->eip = LIFT_CODE_TOKEN_VA(0x498159u);
    lift_store32(cpu->edi + 0xCu, 1u);
    label_00098160: cpu->eip = LIFT_CODE_TOKEN_VA(0x498160u);
    cpu->eax = 0x64u;
    cpu->ecx = (uint32_t)(uintptr_t)"config.cfg";
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 4u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49817Fu); lift_push32(cpu, r); sfera_sub_004483B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    cpu->ecx = (uint32_t)(uintptr_t)"SNDVOL";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49818Du); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    cpu->ecx = (uint32_t)(uintptr_t)"MUSVOL";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49819Bu); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    cpu->ecx = (uint32_t)(uintptr_t)"HWMIX";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4981A9u); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    cpu->edx = cpu->ecx & 0xFFu;
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&SI_SetHardwareMixing), LIFT_CODE_TOKEN_VA(0x4981B5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4981BBu);
    cpu->esp += 4u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4981C3u); lift_push32(cpu, r); sfera_sub_00497370(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4981CCu); lift_push32(cpu, r); sfera_sub_004982F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_sound_runtime.manager;
    cpu->edi = lift_pop32(cpu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000981E1;
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x981E1u); lift_push32(cpu, r); sfera_sub_00497AA0(cpu,r); if (cpu->eip != r) return; }
    label_000981E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4981E1u);
    cpu->esp += 0xCu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004981F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4981F0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4981F5u); lift_push32(cpu, r); sfera_sub_00497470(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(g_sfera_sound_runtime.manager) == (uint32_t)(0u)) goto label_00098233;
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0x59u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundManager.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49820Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_sound_runtime.manager;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00098228;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49821Fu); lift_push32(cpu, r); sfera_sub_004980A0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498225u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00098228: cpu->eip = LIFT_CODE_TOKEN_VA(0x498228u);
    g_sfera_sound_runtime.manager = (uint32_t)(0u);
    cpu->esi = lift_pop32(cpu);
    label_00098233: cpu->eip = LIFT_CODE_TOKEN_VA(0x498233u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498238u); lift_push32(cpu, r); sfera_sub_004990F0(cpu,r); if (cpu->eip != r) return; }
    lift_native_call_return(cpu, (uint32_t)(native_function_address32(&SI_Close)), LIFT_CODE_TOKEN_VA(0x498238u), stop_address); return;
    lift_trap(cpu, cpu->eip, "function fell through without control transfer");
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00498240(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x498240u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ListStack.h";
    if ((uint32_t)(lift_load32(cpu->esi)) != (uint32_t)(cpu->edi)) goto label_00098295;
    cpu->edx = (uint32_t)(cpu->edi + 0x69u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498257u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49825Eu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00098280;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->edi);
    lift_store32(cpu->eax + 4u, cpu->edi);
    lift_store32(cpu->eax + 8u, cpu->edi);
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 4u, cpu->edx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00098280: cpu->eip = LIFT_CODE_TOKEN_VA(0x498280u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    cpu->eax = 0u;
    lift_store32(cpu->esi, cpu->eax);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->edx = lift_load32(cpu->esi);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 4u, cpu->edx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00098295: cpu->eip = LIFT_CODE_TOKEN_VA(0x498295u);
    cpu->edx = 0x6Fu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49829Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4982A6u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000982B7;
    lift_store32(cpu->eax, cpu->edi);
    lift_store32(cpu->eax + 4u, cpu->edi);
    lift_store32(cpu->eax + 8u, cpu->edi);
    goto label_000982B9;
    label_000982B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4982B7u);
    cpu->eax = 0u;
    label_000982B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4982B9u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->edx + 4u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->edx, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 4u, cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004982F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4982F0u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&SI_SetStreamVolume), LIFT_CODE_TOKEN_VA(0x4982F1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4982F7u);
    cpu->esp += 4u;
    cpu->eax = 1u;
    lift_return(cpu, 0u, stop_address); return;
}


LIFT_ENTRY void LIFT_CDECL sfera_sub_00498310(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x498310u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00098321;
    cpu->eax = lift_load32(cpu->esi + 8u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00098360;
    label_00098321: cpu->eip = LIFT_CODE_TOKEN_VA(0x498321u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    if ((uint32_t)(cpu->edx) != 0u) goto label_0009833E;
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::malloc), LIFT_CODE_TOKEN_VA(0x498333u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x498339u);
    cpu->esp += 4u;
    goto label_00098352;
    label_0009833E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49833Eu);
    cpu->eax += cpu->edx;
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::realloc), LIFT_CODE_TOKEN_VA(0x498349u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49834Fu);
    cpu->esp += 8u;
    label_00098352: cpu->eip = LIFT_CODE_TOKEN_VA(0x498352u);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esi, cpu->eax);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00098399;
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    lift_store32(cpu->esi + 4u, (uint64_t)(lift_load32(cpu->esi + 4u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    label_00098360: cpu->eip = LIFT_CODE_TOKEN_VA(0x498360u);
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->edx) * 4u), cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->edx = lift_load32(cpu->esi);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    lift_store_f32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u) + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    lift_store32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u) + 8u, cpu->edx);
    cpu->eax = 1u;
    lift_store32(cpu->esi + 8u, (uint64_t)(lift_load32(cpu->esi + 8u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_00098399: cpu->eip = LIFT_CODE_TOKEN_VA(0x498399u);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004983A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4983A0u);
    if ((uint32_t)(lift_load32(cpu->ecx + 8u)) == (uint32_t)(0u)) goto label_000983F2;
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000983F2;
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_store32(cpu->edx, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 4u));
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->eax, cpu->edx);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx + 8u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->ecx + 8u, v); }
    cpu->eax = lift_load32(cpu->ecx + 8u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000983EA;
    cpu->ecx = lift_load32(cpu->ecx);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ecx + 0xCu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x4983E1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4983E7u);
    cpu->esp += 0xCu;
    label_000983EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4983EAu);
    cpu->eax = 1u;
    lift_return(cpu, 12u, stop_address); return;
    label_000983F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4983F2u);
    cpu->eax = 0u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00498400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x498400u);
    cpu->eax = cpu->ecx;
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    lift_store32(cpu->eax + 0x10u, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00498420(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x498420u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u))) == (uint32_t)(0u)) goto label_0009844E;
    cpu->edx = 0x1B4u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498440u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u));
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49844Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009844E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49844Eu);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->eax + ((uint32_t)(cpu->edi) * 4u), 0u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u), 0u);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_000984AC;
    cpu->edx = 0x1BAu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498478u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->ebp;
    cpu->edx = 4u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498490u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u), cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->edi) * 4u), cpu->ebp);
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x4984A4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4984A9u);
    cpu->esp += 0x10u;
    label_000984AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4984ACu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004984C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4984C0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    if ((uint32_t)(lift_load32(cpu->esi)) == (uint32_t)(cpu->ebx)) goto label_00098517;
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x10u)) <= (uint32_t)(cpu->ebx)) goto label_000984FC;
    label_000984D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4984D2u);
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u))) == (uint32_t)(cpu->ebx)) goto label_000984F6;
    cpu->edx = 0x1CAu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4984E8u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u));
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4984F3u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000984F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4984F6u);
    ++cpu->edi;
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_000984D2;
    label_000984FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4984FCu);
    cpu->edx = 0x1CCu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49850Bu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498513u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu);
    label_00098517: cpu->eip = LIFT_CODE_TOKEN_VA(0x498517u);
    if ((uint32_t)(lift_load32(cpu->esi + 4u)) == (uint32_t)(cpu->ebx)) goto label_00098537;
    cpu->edx = 0x1CEu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49852Bu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498534u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00098537: cpu->eip = LIFT_CODE_TOKEN_VA(0x498537u);
    lift_store32(cpu->esi, cpu->ebx);
    lift_store32(cpu->esi + 4u, cpu->ebx);
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00498550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x498550u);
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax |= 0xFFFFFFFFu;
    lift_store_f32(cpu->esi + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edi);
    cpu->edx = 0x1ECu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    lift_store32(cpu->esi + 4u, cpu->ebx);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    lift_store32(cpu->esi + 0x24u, cpu->ebx);
    lift_store32(cpu->esi + 0x28u, cpu->ebx);
    lift_store32(cpu->esi + 0x30u, cpu->ebx);
    lift_store32(cpu->esi + 0x2Cu, cpu->ebx);
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store32(cpu->esi + 0x1Cu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49858Cu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498593u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->esp += 4u;
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebx)) goto label_000985BC;
    lift_push32(cpu, 0x168u);
    lift_native_call(cpu, native_function_address32(&::malloc), LIFT_CODE_TOKEN_VA(0x4985A1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4985A7u);
    lift_store32(cpu->edi, cpu->eax);
    cpu->eax = 0x1Eu;
    cpu->esp += 4u;
    lift_store32(cpu->edi + 8u, cpu->ebx);
    lift_store32(cpu->edi + 4u, cpu->eax);
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    goto label_000985BE;
    label_000985BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4985BCu);
    cpu->edi = 0u;
    label_000985BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4985BEu);
    cpu->eax = 1u;
    lift_store32(cpu->esi, cpu->edi);
    lift_store32(cpu->esi + 0x44u, cpu->eax);
    lift_store32(cpu->esi + 0x40u, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x38u, cpu->ebx);
    lift_store32(cpu->esi + 0x34u, cpu->ebx);
    lift_store32(cpu->esi + 0x3Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x4Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x48u, cpu->ebx);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004985E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4985E0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00098605;
    cpu->edx = 0x1FDu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4985F9u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498602u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00098605: cpu->eip = LIFT_CODE_TOKEN_VA(0x498605u);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->esi + 4u, 0u);
    lift_store32(cpu->esi + 8u, 0u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_0009865B;
    cpu->edx = 0x202u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49862Au); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->edi;
    cpu->edx = 8u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498642u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(((uint32_t)(cpu->edi) * 8u));
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->esi + 8u, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x498653u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x498658u);
    cpu->esp += 0x10u;
    label_0009865B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49865Bu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00498660(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x498660u);
    cpu->esp -= 0x20u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x28u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_0009868B;
    lift_x87_push(cpu, 0.0);
    cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 4u, stop_address); return;
    label_0009868B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49868Bu);
    cpu->eax = cpu->edi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00098690: cpu->eip = LIFT_CODE_TOKEN_VA(0x498690u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00098690;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000986CF;
    cpu->ecx = 0u;
    if ((uint8_t)(lift_load8(cpu->edi)) == (uint8_t)(0x3Au)) goto label_000986C6;
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->esp + 0x18u);
    cpu->eax = cpu->edi;
    cpu->esi -= cpu->edi;
    cpu->edi = cpu->edi;
    label_000986B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4986B0u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(0xFu)) goto label_000986C5;
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->ebp)) goto label_000986C5;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->esi + cpu->eax, cpu->edx & 0xFFu);
    ++cpu->eax;
    ++cpu->ecx;
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x3Au)) goto label_000986B0;
    label_000986C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4986C5u);
    cpu->esi = lift_pop32(cpu);
    label_000986C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4986C6u);
    lift_store8(cpu->esp + cpu->ecx + 0x14u, 0u);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->ebp)) goto label_000986E4;
    label_000986CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4986CFu);
    lift_x87_push(cpu, 0.0);
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->esp += 0x20u;
    lift_return(cpu, 4u, stop_address); return;
    label_000986E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4986E4u);
    cpu->eax = (uint32_t)(cpu->edi + cpu->ecx + 1u);
    lift_push32(cpu, cpu->eax);
    lift_x87_push(cpu, std::atof(reinterpret_cast<const char*>(static_cast<std::uintptr_t>(lift_load32(cpu->esp)))));
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4986EFu);
    lift_store_f64(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::atoi), LIFT_CODE_TOKEN_VA(0x4986F8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4986FEu);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    cpu->esp += 8u;
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (60.0));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_load_f64(cpu->esp + 4u)));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    cpu->esp += 0x20u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00498730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x498730u);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0xCu, cpu->ebx);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00098847;
    cpu->eax = cpu->edi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00098760: cpu->eip = LIFT_CODE_TOKEN_VA(0x498760u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00098760;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00098847;
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->edi)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = cpu->edi;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009878E;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00098780: cpu->eip = LIFT_CODE_TOKEN_VA(0x498780u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)(0x2Cu)) goto label_00098789;
    ++cpu->esi;
    label_00098789: cpu->eip = LIFT_CODE_TOKEN_VA(0x498789u);
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0u)) goto label_00098780;
    label_0009878E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49878Eu);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ebp);
    ++cpu->esi;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4987A1u); lift_push32(cpu, r); sfera_sub_00498420(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = 0u;
    if ((int32_t)(uint32_t)(cpu->esi) <= 0) goto label_00098845;
    label_000987B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4987B0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi)) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x2Cu)) goto label_000987CE;
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000987C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4987C0u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000987CE;
    ++cpu->edi;
    lift_store8(cpu->ecx, cpu->eax & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x2Cu)) goto label_000987C0;
    label_000987CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4987CEu);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, (uintptr_t)"STP"); lift_push32(cpu, cpu->eax);
    lift_store8(cpu->ecx, 0u);
    ++cpu->edi;
    cpu->ebx |= 0xFFFFFFFFu;
    cpu->esi = 0u;
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4987E1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4987E7u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000987F5;
    cpu->ebx = 0x40000u;
    goto label_00098828;
    label_000987F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4987F5u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x19u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::atoi), LIFT_CODE_TOKEN_VA(0x4987FAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x498800u);
    cpu->esi = cpu->eax;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x1Cu)) & 0xFFu);
    cpu->esp += 4u;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x6Au)) goto label_00098823;
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)(0x70u)) goto label_0009881C;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x73u)) goto label_00098828;
    cpu->ebx = 0x20000u;
    goto label_00098828;
    label_0009881C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49881Cu);
    cpu->ebx = 0x10000u;
    goto label_00098828;
    label_00098823: cpu->eip = LIFT_CODE_TOKEN_VA(0x498823u);
    cpu->ebx = 0x80000u;
    label_00098828: cpu->eip = LIFT_CODE_TOKEN_VA(0x498828u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    cpu->edx = lift_load32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    cpu->esi |= cpu->ebx;
    lift_store32(cpu->edx + ((uint32_t)(cpu->ebp) * 4u), cpu->esi);
    ++cpu->ebp;
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x10u))) goto label_000987B0;
    label_00098845: cpu->eip = LIFT_CODE_TOKEN_VA(0x498845u);
    cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_00098847: cpu->eip = LIFT_CODE_TOKEN_VA(0x498847u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00498860(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x498860u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->edi + 0x2Cu);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_0009886F;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0009886F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49886Fu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->esi) == 0u) goto label_00098898;
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->ebx = lift_load32(cpu->ecx + 4u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    if ((uint32_t)(cpu->edx) >= (uint32_t)(lift_load32(cpu->eax + cpu->ebx))) goto label_00098898;
    cpu->eax = lift_load32(cpu->eax + cpu->esi);
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    ++cpu->edx;
    lift_store32(cpu->ecx + 8u, cpu->edx);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_0009889F;
    label_00098898: cpu->eip = LIFT_CODE_TOKEN_VA(0x498898u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0009889F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49889Fu);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 0xFFFF0000u;
    lift_push32(cpu, cpu->ebp);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(0x80000u)) goto label_00098925;
    cpu->ebx = native_function_address32(&::rand);
    label_000988B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4988B6u);
    cpu->eax = cpu->eax & 0xFFFFu;
    --cpu->eax;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(lift_load32(cpu->edi + 0x28u))) goto label_0009891B;
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->edi + 0x24u);
    cpu->esi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    lift_store32(cpu->edi + 0x2Cu, cpu->esi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x988CDu), LIFT_CODE_TOKEN_RVA(0x988CBu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4988CDu);
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, lift_load32(cpu->esi + 0x10u), 32u, 0u);
    lift_store32(cpu->esi + 8u, 0u);
    lift_store32(cpu->esi + 0xCu, cpu->edx);
    cpu->ecx = lift_load32(cpu->edi + 0x2Cu);
    cpu->eax = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00098922;
    cpu->edx = lift_load32(cpu->ecx + 0xCu);
    cpu->esi = lift_load32(cpu->ecx + 8u);
    cpu->ebp = lift_load32(cpu->ecx + 4u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(lift_load32(cpu->edx + cpu->ebp))) goto label_00098922;
    cpu->edx = lift_load32(cpu->edx + cpu->eax);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    ++cpu->esi;
    lift_store32(cpu->ecx + 8u, cpu->esi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00098922;
    cpu->ecx = cpu->eax;
    cpu->ecx &= 0xFFFF0000u;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0x80000u)) goto label_000988B6;
    cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0009891B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49891Bu);
    cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00098922: cpu->eip = LIFT_CODE_TOKEN_VA(0x498922u);
    cpu->eax |= 0xFFFFFFFFu;
    label_00098925: cpu->eip = LIFT_CODE_TOKEN_VA(0x498925u);
    cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00498930(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x498930u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    cpu->ebx = cpu->ecx;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00098945;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
    label_00098945: cpu->eip = LIFT_CODE_TOKEN_VA(0x498945u);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49894Du); lift_push32(cpu, r); sfera_sub_00498860(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(0xFFFFFFFFu)) goto label_00098973;
    cpu->ecx = cpu->ebx;
    lift_native_call(cpu, native_method_address32(&CSoundStream::Stop), LIFT_CODE_TOKEN_VA(0x498956u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49895Cu);
    cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x3Cu, 1u);
    lift_store32(cpu->esi + 0xCu, 0u);
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
    label_00098973: cpu->eip = LIFT_CODE_TOKEN_VA(0x498973u);
    cpu->eax &= 0xFFFF0000u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x48u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ebp & 0xFFFFu;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000989C7;
    lift_x87_push(cpu, (double)-1.0f);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498996u); lift_push32(cpu, r); sfera_sub_00498310(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x5Cu, 0xFFFFFFFFu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x20u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (1.0));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_native_call(cpu, native_method_address32(&CSoundStream::SetPlaySignal), LIFT_CODE_TOKEN_VA(0x4989B4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4989BAu);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
    label_000989C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4989C7u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x10000u)) goto label_00098A48;
    cpu->ecx = lift_load32(cpu->ebx);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 0xCu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x989D7u), LIFT_CODE_TOKEN_RVA(0x989D5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4989D7u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->edi) * 8u) + 0xFFFFFFFCu));
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edi) * 8u) + 0xFFFFFFF8u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->eax + 4u)))));
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_000989FB;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_000989FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4989FBu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ecx))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498A02u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_load16(cpu->ecx + 0xCu);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->edx);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498A15u); lift_push32(cpu, r); sfera_sub_00498310(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + ((uint32_t)(cpu->edi) * 8u) + 0xFFFFFFF8u));
    cpu->ecx = cpu->ebx;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_native_call(cpu, native_method_address32(&CSoundStream::SeekToTime), LIFT_CODE_TOKEN_VA(0x498A22u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x498A28u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->edi) * 8u) + 0xFFFFFFFCu));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_native_call(cpu, native_method_address32(&CSoundStream::SetDecodeSignal), LIFT_CODE_TOKEN_VA(0x498A35u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x498A3Bu);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
    label_00098A48: cpu->eip = LIFT_CODE_TOKEN_VA(0x498A48u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x40000u)) goto label_00098A5A;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x20000u)) goto label_00098A75;
    if ((uint32_t)(cpu->edi) == 0u) goto label_00098A75;
    label_00098A5A: cpu->eip = LIFT_CODE_TOKEN_VA(0x498A5Au);
    lift_x87_push(cpu, (double)-1.0f);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498A6Eu); lift_push32(cpu, r); sfera_sub_00498310(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->ebx + 0x5Cu, 0xFFFFFFFFu);
    label_00098A75: cpu->eip = LIFT_CODE_TOKEN_VA(0x498A75u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00498AD0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_00098AD0;
    label_00098A90: cpu->eip = LIFT_CODE_TOKEN_VA(0x498A90u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00098AC3;
    lift_native_call(cpu, native_method_address32(&CSoundStream::IsStreamPlaying), LIFT_CODE_TOKEN_VA(0x498A9Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x498AA0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00098AAD;
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    lift_native_call(cpu, native_method_address32(&CSoundStream::Stop), LIFT_CODE_TOKEN_RVA(0x98AA7u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x98AADu);
    label_00098AAD: cpu->eip = LIFT_CODE_TOKEN_VA(0x498AADu);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_store32(cpu->ecx + 0x5Cu, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 0x34u);
    lift_store32(cpu->edx + 0x68u, cpu->eax);
    lift_store32(cpu->esi + 0x40u, 1u);
    label_00098AC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x498AC3u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00098AD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x498AD0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0xCu)) != (uint32_t)(0u)) goto label_00098BDD;
    cpu->eax = lift_load32(cpu->esi + 0x34u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00098BDD;
    if ((uint32_t)(lift_load32(cpu->eax + 0x40u)) != (uint32_t)(0u)) goto label_00098BDD;
    if ((uint32_t)(lift_load32(cpu->esi + 0x40u)) != (uint32_t)(0u)) goto label_00098BDD;
    if ((uint32_t)(lift_load32(cpu->esi + 0x3Cu)) != (uint32_t)(0u)) goto label_00098B61;
    if ((uint32_t)(lift_load32(cpu->esi + 0x48u)) != (uint32_t)(0u)) goto label_00098B61;
    if ((uint32_t)(lift_load32(cpu->esi + 0x10u)) == (uint32_t)(0u)) goto label_00098B51;
    cpu->eax = lift_load32(cpu->esi + 0x18u);
    cpu->eax &= lift_load32(cpu->esi + 0x1Cu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_00098B26;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498B1Eu); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x18u, cpu->eax);
    lift_store32(cpu->esi + 0x1Cu, cpu->edx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00098B26: cpu->eip = LIFT_CODE_TOKEN_VA(0x498B26u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498B2Bu); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x18u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_push32(cpu, 0u);
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(lift_load32(cpu->esi + 0x1Cu)) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_push32(cpu, 0x2710u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498B3Fu); lift_push32(cpu, r); sfera_sub_004EEA40(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_00098BDD;
    lift_store32(cpu->esi + 0x10u, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00098B51: cpu->eip = LIFT_CODE_TOKEN_VA(0x498B51u);
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498B57u); lift_push32(cpu, r); sfera_sub_00498860(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx |= 0xFFFFFFFFu;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_00098B67;
    cpu->ecx = cpu->esi;
    cpu->ebx = lift_pop32(cpu);
    label_00098B61: cpu->eip = LIFT_CODE_TOKEN_VA(0x498B61u);
    cpu->esi = lift_pop32(cpu);
    goto label_00098A90;
    label_00098B67: cpu->eip = LIFT_CODE_TOKEN_VA(0x498B67u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 0xFFFF0000u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->eax & 0xFFFFu;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(0x10000u)) goto label_00098BDF;
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    lift_native_call(cpu, native_method_address32(&CSoundStream::IsStreamPlaying), LIFT_CODE_TOKEN_VA(0x498B7Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x498B84u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00098B91;
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    lift_native_call(cpu, native_method_address32(&CSoundStream::Stop), LIFT_CODE_TOKEN_RVA(0x98B8Bu));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x98B91u);
    label_00098B91: cpu->eip = LIFT_CODE_TOKEN_VA(0x498B91u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + ((uint32_t)(cpu->edi) * 8u) + 0xFFFFFFFCu));
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->edi) * 8u) + 0xFFFFFFFCu);
    lift_store_f32(cpu->esi + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax));
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_native_call(cpu, native_method_address32(&CSoundStream::SetDecodeSignal), LIFT_CODE_TOKEN_VA(0x498BA8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x498BAEu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x20u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_native_call(cpu, native_method_address32(&CSoundStream::SetPlaySignal), LIFT_CODE_TOKEN_VA(0x498BB8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x498BBEu);
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + ((uint32_t)(cpu->edi) * 8u) + 0xFFFFFFF8u));
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_native_call(cpu, native_method_address32(&CSoundStream::PlayEx), LIFT_CODE_TOKEN_VA(0x498BCEu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x498BD4u);
    lift_store32(cpu->esi + 0xCu, 1u);
    label_00098BDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x498BDBu);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00098BDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x498BDDu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00098BDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x498BDFu);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(0x20000u)) goto label_00098C16;
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    lift_native_call(cpu, native_method_address32(&CSoundStream::IsStreamPlaying), LIFT_CODE_TOKEN_VA(0x498BEAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x498BF0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00098BFD;
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    lift_native_call(cpu, native_method_address32(&CSoundStream::Stop), LIFT_CODE_TOKEN_RVA(0x98BF7u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x98BFDu);
    label_00098BFD: cpu->eip = LIFT_CODE_TOKEN_VA(0x498BFDu);
    cpu->eax = lift_load32(cpu->esi + 0x34u);
    lift_store32(cpu->eax + 0x5Cu, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    lift_store32(cpu->ecx + 0x68u, cpu->ebx);
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x18u, cpu->ebx);
    lift_store32(cpu->esi + 0x1Cu, cpu->ebx);
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00098C16: cpu->eip = LIFT_CODE_TOKEN_VA(0x498C16u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(0x40000u)) goto label_00098BDB;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->ecx = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    goto label_00098A90;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00498C30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x498C30u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->esi) == 0u) goto label_00098CCF;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    label_00098C42: cpu->eip = LIFT_CODE_TOKEN_VA(0x498C42u);
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) == (uint32_t)(cpu->eax)) goto label_00098C53;
    cpu->esi = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_00098C42;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00098C53: cpu->eip = LIFT_CODE_TOKEN_VA(0x498C53u);
    cpu->ecx = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_00098C86;
    if ((uint32_t)(lift_load32(cpu->esi + 4u)) != (uint32_t)(cpu->ecx)) goto label_00098C86;
    cpu->edx = (uint32_t)(cpu->ecx + 0x7Du);
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ListStack.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498C6Bu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498C71u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->edi + 4u, 0u);
    lift_store32(cpu->edi, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00098C86: cpu->eip = LIFT_CODE_TOKEN_VA(0x498C86u);
    cpu->eax = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00098C9C;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    cpu->eax = lift_load32(cpu->esi);
    lift_store32(cpu->edi + 4u, cpu->eax);
    cpu->edx = 0x86u;
    goto label_00098CBC;
    label_00098C9C: cpu->eip = LIFT_CODE_TOKEN_VA(0x498C9Cu);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_00098CAB;
    lift_store32(cpu->edi, cpu->eax);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = 0x8Eu;
    goto label_00098CBC;
    label_00098CAB: cpu->eip = LIFT_CODE_TOKEN_VA(0x498CABu);
    cpu->edx = cpu->eax;
    lift_store32(cpu->ecx + 4u, cpu->edx);
    cpu->eax = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = 0x94u;
    label_00098CBC: cpu->eip = LIFT_CODE_TOKEN_VA(0x498CBCu);
    cpu->ecx = (uint32_t)(uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\shareclientsevercode\\ListStack.h";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498CC6u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498CCCu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00098CCF: cpu->eip = LIFT_CODE_TOKEN_VA(0x498CCFu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00498CE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x498CE0u);
    sfera_sub_004984C0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00498CF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x498CF0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00098CFE;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x98CFEu); lift_push32(cpu, r); sfera_sub_004984C0(cpu,r); if (cpu->eip != r) return; }
    label_00098CFE: cpu->eip = LIFT_CODE_TOKEN_VA(0x498CFEu);
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00098D88;
    cpu->edx = 0x1A0u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498D19u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->edi;
    cpu->edx = 4u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498D31u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->edx = 0x1A1u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    lift_store32(cpu->esi, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498D45u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->edi;
    cpu->edx = 4u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498D5Du); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->esp += 4u;
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00098D88;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00098D70: cpu->eip = LIFT_CODE_TOKEN_VA(0x498D70u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u), 0u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->eax) * 4u), 0u);
    ++cpu->eax;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->edi)) goto label_00098D70;
    label_00098D88: cpu->eip = LIFT_CODE_TOKEN_VA(0x498D88u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00498D90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x498D90u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->edx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->esi) != 0u) goto label_00098DA5;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_00098DA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x498DA5u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498DBCu); lift_push32(cpu, r); sfera_sub_004983A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00098EB4;
    cpu->ecx = lift_load32(cpu->edi);
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx + 0xCu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x98DCDu), LIFT_CODE_TOKEN_RVA(0x98DCBu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x498DCDu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = cpu->eax;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFFFFFFu)) goto label_00098E19;
    cpu->eax = lift_load32(cpu->edx + 4u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->edx + 4u)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_00098DE8;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_00098DE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x498DE8u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x20u))));
    cpu->edx = lift_load16(cpu->edx + 0xCu);
    lift_store16(cpu->esp + 0xEu, cpu->fpu_control);
    cpu->eax = lift_load16(cpu->esp + 0xEu);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x10u));
    lift_store64(cpu->esp + 0x10u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0xEu));
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(cpu->edx);
    cpu->ecx -= cpu->eax;
    lift_store32(cpu->edi + 0x34u, (uint64_t)(lift_load32(cpu->edi + 0x34u)) + (uint64_t)(cpu->ecx) + (uint64_t)(0u));
    label_00098E19: cpu->eip = LIFT_CODE_TOKEN_VA(0x498E19u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)-1.0f);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_00098E3F;
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esi + 0x20u, lift_x87_get(cpu, 0u));
    cpu->ecx = cpu->edi;
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_native_call(cpu, native_method_address32(&CSoundStream::SetPlaySignal), LIFT_CODE_TOKEN_VA(0x498E37u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x498E3Du);
    goto label_00098E48;
    label_00098E3F: cpu->eip = LIFT_CODE_TOKEN_VA(0x498E3Fu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->edi + 0x68u, 0xFFFFFFFFu);
    label_00098E48: cpu->eip = LIFT_CODE_TOKEN_VA(0x498E48u);
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    cpu->eax = cpu->ebx;
    cpu->eax &= 0xFFFF0000u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x40000u)) goto label_00098E96;
    if ((uint32_t)(lift_load32(cpu->esi + 0x48u)) != (uint32_t)(0u)) goto label_00098E96;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0x20000u)) goto label_00098EBB;
    cpu->ecx = cpu->edi;
    lift_native_call(cpu, native_method_address32(&CSoundStream::Stop), LIFT_CODE_TOKEN_VA(0x498E69u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x498E6Fu);
    cpu->eax = cpu->ebx & 0xFFFFu;
    cpu->ebx = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x18u, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0x1Cu, 0xFFFFFFFFu);
    lift_store32(cpu->esi + 0xCu, 0u);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_00098E96: cpu->eip = LIFT_CODE_TOKEN_VA(0x498E96u);
    cpu->ecx = cpu->edi;
    lift_native_call(cpu, native_method_address32(&CSoundStream::Stop), LIFT_CODE_TOKEN_VA(0x498E98u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x498E9Eu);
    cpu->ebx = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x3Cu, cpu->eax);
    lift_store32(cpu->esi + 0xCu, 0u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
    label_00098EB4: cpu->eip = LIFT_CODE_TOKEN_VA(0x498EB4u);
    lift_store32(cpu->edi + 0x68u, 0xFFFFFFFFu);
    label_00098EBB: cpu->eip = LIFT_CODE_TOKEN_VA(0x498EBBu);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00498ED0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x498ED0u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    if ((uint32_t)(lift_load32(cpu->esi + 0x24u)) == (uint32_t)(cpu->ebx)) goto label_00098F61;
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(lift_load32(cpu->esi + 0x28u))) goto label_00098F61;
    cpu->eax = lift_load32(cpu->esi + 0x38u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00098F61;
    lift_store32(cpu->esi + 0x2Cu, cpu->ebx);
    if ((uint32_t)(lift_load32(cpu->esi + 0x34u)) != (uint32_t)(cpu->ebx)) goto label_00098F09;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&SI_StreamCreateFile), LIFT_CODE_TOKEN_VA(0x498EF9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x498EFFu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00098F64;
    lift_store32(cpu->esi + 0x34u, cpu->eax);
    label_00098F09: cpu->eip = LIFT_CODE_TOKEN_VA(0x498F09u);
    cpu->eax = lift_load32(cpu->esi + 0x34u);
    lift_store32(cpu->eax + 0x54u, LIFT_CALLBACK(sfera_sub_00498930));
    lift_store32(cpu->eax + 0x58u, cpu->esi);
    cpu->eax = lift_load32(cpu->esi + 0x34u);
    lift_store32(cpu->eax + 0x60u, LIFT_CALLBACK(sfera_sub_00498D90));
    lift_store32(cpu->eax + 0x64u, cpu->esi);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + 0x44u)))));
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->edi);
    lift_store_f32(cpu->ecx + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esi + 0x30u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    cpu->edi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    lift_store32(cpu->esi + 0x2Cu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::rand), LIFT_CODE_TOKEN_VA(0x498F3Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x498F45u);
    cpu->edx = 0u;
    lift_divide_accumulator(cpu, lift_load32(cpu->edi + 0x10u), 32u, 0u);
    lift_store32(cpu->edi + 8u, cpu->ebx);
    cpu->eax = 1u;
    lift_store32(cpu->edi + 0xCu, cpu->edx);
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->ecx + 8u, cpu->ebx);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x40u, cpu->ebx);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00098F61: cpu->eip = LIFT_CODE_TOKEN_VA(0x498F61u);
    lift_store32(cpu->esi + 0x2Cu, cpu->ebx);
    label_00098F64: cpu->eip = LIFT_CODE_TOKEN_VA(0x498F64u);
    cpu->esi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00498F70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x498F70u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x34u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00098F8B;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&SI_StreamFree), LIFT_CODE_TOKEN_VA(0x498F7Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x498F85u);
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x34u, cpu->ebx);
    label_00098F8B: cpu->eip = LIFT_CODE_TOKEN_VA(0x498F8Bu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x38u)) == (uint32_t)(cpu->ebx)) goto label_00098FAE;
    cpu->edx = 0x453u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498F9Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x38u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498FA8u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 0x38u, cpu->ebx);
    label_00098FAE: cpu->eip = LIFT_CODE_TOKEN_VA(0x498FAEu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x24u)) == (uint32_t)(cpu->ebx)) goto label_00098FE9;
    cpu->edx = 0x459u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498FC2u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x24u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00098FE6;
    cpu->ecx = lift_load32(cpu->eax + 0xFFFFFFFCu);
    cpu->edi = (uint32_t)(cpu->eax + 0xFFFFFFFCu);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00498CE0)); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x14u); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498FDDu); lift_push32(cpu, r); sfera_sub_004EEB86(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498FE3u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00098FE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x498FE6u);
    lift_store32(cpu->esi + 0x24u, cpu->ebx);
    label_00098FE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x498FE9u);
    if ((uint32_t)(lift_load32(cpu->esi + 4u)) == (uint32_t)(cpu->ebx)) goto label_0009900C;
    cpu->edx = 0x45Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x498FFDu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499006u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 4u, cpu->ebx);
    label_0009900C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49900Cu);
    if ((uint32_t)(lift_load32(cpu->esi)) == (uint32_t)(cpu->ebx)) goto label_00099045;
    cpu->edx = 0x465u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49901Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebx)) goto label_00099043;
    cpu->eax = lift_load32(cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_0009903A;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::free), LIFT_CODE_TOKEN_VA(0x49902Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x499032u);
    cpu->esp += 4u;
    lift_store32(cpu->edi, cpu->ebx);
    lift_store32(cpu->edi + 4u, cpu->ebx);
    label_0009903A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49903Au);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499040u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00099043: cpu->eip = LIFT_CODE_TOKEN_VA(0x499043u);
    lift_store32(cpu->esi, cpu->ebx);
    label_00099045: cpu->eip = LIFT_CODE_TOKEN_VA(0x499045u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0x3Cu, cpu->ebx);
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x2Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x28u, cpu->ebx);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    lift_store32(cpu->esi + 0x40u, 1u);
    lift_store32(cpu->esi + 0x30u, 0xFFFFFFFFu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00499070(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x499070u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->esi) != 0u) goto label_0009907B;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0009907B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49907Bu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x40u)) != (uint32_t)(0u)) goto label_000990B1;
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000990B1;
    lift_native_call(cpu, native_method_address32(&CSoundStream::IsStreamPlaying), LIFT_CODE_TOKEN_VA(0x499088u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49908Eu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009909B;
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    lift_native_call(cpu, native_method_address32(&CSoundStream::Stop), LIFT_CODE_TOKEN_RVA(0x99095u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x9909Bu);
    label_0009909B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49909Bu);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    cpu->eax |= 0xFFFFFFFFu;
    lift_store32(cpu->ecx + 0x5Cu, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 0x34u);
    lift_store32(cpu->edx + 0x68u, cpu->eax);
    lift_store32(cpu->esi + 0x40u, 1u);
    label_000990B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4990B1u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_sound_runtime.tracks;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4990BCu); lift_push32(cpu, r); sfera_sub_00498C30(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0x97u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4990CBu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4990D2u); lift_push32(cpu, r); sfera_sub_00498F70(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4990D8u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004990F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4990F0u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = g_sfera_sound_runtime.tracks.first;
    if ((uint32_t)(cpu->edi) == 0u) goto label_00099162;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_method_address32(&CSoundStream::IsStreamPlaying);
    lift_push32(cpu, cpu->esi);
    cpu->ebx |= 0xFFFFFFFFu;
    label_00099107: cpu->eip = LIFT_CODE_TOKEN_VA(0x499107u);
    cpu->esi = lift_load32(cpu->edi + 8u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x40u)) != (uint32_t)(0u)) goto label_00099139;
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00099139;
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x99119u), LIFT_CODE_TOKEN_RVA(0x99117u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x499119u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00099126;
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    lift_native_call(cpu, native_method_address32(&CSoundStream::Stop), LIFT_CODE_TOKEN_RVA(0x99120u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x99126u);
    label_00099126: cpu->eip = LIFT_CODE_TOKEN_VA(0x499126u);
    cpu->eax = lift_load32(cpu->esi + 0x34u);
    lift_store32(cpu->eax + 0x5Cu, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esi + 0x34u);
    lift_store32(cpu->ecx + 0x68u, cpu->ebx);
    lift_store32(cpu->esi + 0x40u, 1u);
    label_00099139: cpu->eip = LIFT_CODE_TOKEN_VA(0x499139u);
    cpu->edx = 0x118u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499148u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49914Fu); lift_push32(cpu, r); sfera_sub_00498F70(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499155u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->edi + 4u);
    cpu->esp += 4u;
    if ((uint32_t)(cpu->edi) != 0u) goto label_00099107;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_00099162: cpu->eip = LIFT_CODE_TOKEN_VA(0x499162u);
    cpu->ecx = 0u;
    cpu->edi = lift_pop32(cpu);
    if ((uint32_t)(g_sfera_sound_runtime.tracks.first) == (uint32_t)(cpu->ecx)) goto label_00099193;
    cpu->eax = g_sfera_sound_runtime.tracks.last;
    label_00099172: cpu->eip = LIFT_CODE_TOKEN_VA(0x499172u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_00099189;
    cpu->edx = lift_load32(cpu->eax + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_sound_runtime.tracks;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499184u); lift_push32(cpu, r); sfera_sub_00498C30(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_sound_runtime.tracks.last;
    label_00099189: cpu->eip = LIFT_CODE_TOKEN_VA(0x499189u);
    cpu->ecx = 0u;
    if ((uint32_t)(g_sfera_sound_runtime.tracks.first) != (uint32_t)(cpu->ecx)) goto label_00099172;
    label_00099193: cpu->eip = LIFT_CODE_TOKEN_VA(0x499193u);
    g_sfera_sound_runtime.tracks.last = (uint32_t)(cpu->ecx);
    g_sfera_sound_runtime.tracks.first = (uint32_t)(cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004991A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4991A0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = cpu->ecx;
    cpu->edi = 0u;
    if ((uint32_t)(lift_load32(cpu->ebp + 0x24u)) == (uint32_t)(cpu->edi)) goto label_000991FF;
    cpu->edx = 0x20Du;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4991DBu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0x24u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000991FF;
    cpu->ecx = lift_load32(cpu->eax + 0xFFFFFFFCu);
    cpu->esi = (uint32_t)(cpu->eax + 0xFFFFFFFCu);
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00498CE0)); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x14u); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4991F6u); lift_push32(cpu, r); sfera_sub_004EEB86(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4991FCu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000991FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4991FFu);
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->ebp + 0x24u, cpu->edi);
    lift_store32(cpu->ebp + 0x28u, cpu->edi);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_0009926D;
    cpu->edx = 0x214u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49921Cu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->esi;
    cpu->edx = 0x14u;
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
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499240u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_00099267;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00498CE0)); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_00498400)); lift_push32(cpu, cpu->esi);
    cpu->edi = (uint32_t)(cpu->eax + 4u);
    lift_push32(cpu, 0x14u); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->eax, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x99267u); lift_push32(cpu, r); sfera_sub_004EEBE9(cpu,r); if (cpu->eip != r) return; }
    label_00099267: cpu->eip = LIFT_CODE_TOKEN_VA(0x499267u);
    lift_store32(cpu->ebp + 0x24u, cpu->edi);
    lift_store32(cpu->ebp + 0x28u, cpu->esi);
    label_0009926D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49926Du);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00499290(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x499290u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x120u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x134u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = lift_load32(cpu->esp + 0x144u);
    cpu->edi = cpu->ecx;
    cpu->edx = 0x344u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4992E3u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x420u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4992EDu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x13Cu, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009930E;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49930Au); lift_push32(cpu, r); sfera_sub_00493BF0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    goto label_00099310;
    label_0009930E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49930Eu);
    cpu->esi = 0u;
    label_00099310: cpu->eip = LIFT_CODE_TOKEN_VA(0x499310u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x140u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499323u); lift_push32(cpu, r); sfera_sub_00494940(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"soundtrack");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499338u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000996D6;
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"audio_file");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499351u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000996CF;
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499367u); lift_push32(cpu, r); sfera_sub_004944A0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000996CF;
    cpu->edx = 0x34Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49937Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00099385: cpu->eip = LIFT_CODE_TOKEN_VA(0x499385u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00099385;
    cpu->eax -= cpu->edx;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499395u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->edi + 0x38u, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    cpu->edx = cpu->eax;
    label_000993A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4993A1u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000993A1;
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"volume");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4993BCu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000993D1;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4993C9u); lift_push32(cpu, r); sfera_sub_004942C0(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4993CEu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x44u, cpu->eax);
    label_000993D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4993D1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"flags");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4993E2u); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00099428;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4993EDu); lift_push32(cpu, r); sfera_sub_004947E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    cpu->ebx = 0u;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00099428;
    label_000993F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4993F5u);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499402u); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00099421;
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, (uintptr_t)"ST_AUTOFREE"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x499410u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x499416u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00099421;
    lift_store32(cpu->edi + 0x4Cu, (uint64_t)(lift_load32(cpu->edi + 0x4Cu)) | (uint64_t)(1u));
    label_00099421: cpu->eip = LIFT_CODE_TOKEN_VA(0x499421u);
    cpu->ebx += 2u;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->ebp)) goto label_000993F5;
    label_00099428: cpu->eip = LIFT_CODE_TOKEN_VA(0x499428u);
    lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"samples");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499440u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000996C8;
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    cpu->ebx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499456u); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"sample");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499462u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009947B;
    label_00099466: cpu->eip = LIFT_CODE_TOKEN_VA(0x499466u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"sample");
    cpu->ecx = cpu->esi;
    ++cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499473u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00099466;
    if ((uint32_t)(cpu->ebx) != 0u) goto label_00099485;
    label_0009947B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49947Bu);
    cpu->edx = 0x376u;
    goto label_000996DB;
    label_00099485: cpu->eip = LIFT_CODE_TOKEN_VA(0x499485u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49948Du); lift_push32(cpu, r); sfera_sub_004985E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499499u); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"sample");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4994A5u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00099526;
    cpu->ebx = (uint32_t)(cpu->esi + 0x10u);
    label_000994B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4994B0u);
    cpu->edx = (uint32_t)(cpu->esp + 0xD0u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d %s %s"); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esp + 0x40u, 0u);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4994D0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4994D6u);
    cpu->ebp = lift_load32(cpu->esp + 0x40u);
    cpu->esp += 0x14u;
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4994E9u); lift_push32(cpu, r); sfera_sub_00498660(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = (uint32_t)(cpu->esp + 0xD0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4994FCu); lift_push32(cpu, r); sfera_sub_00498660(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store_f32(cpu->ecx + ((uint32_t)(cpu->ebp) * 8u) + 0xFFFFFFF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->edi + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_push32(cpu, (uint32_t)(uintptr_t)"sample");
    cpu->ecx = cpu->esi;
    lift_store_f32(cpu->edx + ((uint32_t)(cpu->ebp) * 8u) + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499522u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000994B0;
    label_00099526: cpu->eip = LIFT_CODE_TOKEN_VA(0x499526u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49952Du); lift_push32(cpu, r); sfera_sub_004945B0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"patterns");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499545u); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_000996C1;
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    cpu->ebx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49955Bu); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"pattern");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499567u); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00099585;
    label_00099570: cpu->eip = LIFT_CODE_TOKEN_VA(0x499570u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"pattern");
    cpu->ecx = cpu->esi;
    ++cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49957Du); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_00099570;
    if ((uint32_t)(cpu->ebx) != 0u) goto label_0009958F;
    label_00099585: cpu->eip = LIFT_CODE_TOKEN_VA(0x499585u);
    cpu->edx = 0x3A0u;
    goto label_000996DB;
    label_0009958F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49958Fu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499597u); lift_push32(cpu, r); sfera_sub_004991A0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4995A3u); lift_push32(cpu, r); sfera_sub_00494550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"pattern");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4995AFu); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00099656;
    label_000995B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4995B7u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4995BEu); lift_push32(cpu, r); sfera_sub_004947E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->ebp) <= 0) goto label_00099642;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4995D1u); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->edi + 0x24u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u) + 0xFFFFFFECu);
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    cpu->eax = 1u;
    if ((int32_t)(uint32_t)(cpu->ebp) <= (int32_t)(uint32_t)(2u)) goto label_000995F2;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFFFu);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(1u), 32u);
    ++cpu->eax;
    label_000995F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4995F2u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4995F8u); lift_push32(cpu, r); sfera_sub_00498CF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 1u;
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((int32_t)(uint32_t)(cpu->ebp) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_00099642;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00099610: cpu->eip = LIFT_CODE_TOKEN_VA(0x499610u);
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49961Du); lift_push32(cpu, r); sfera_sub_00494400(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009963B;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499637u); lift_push32(cpu, r); sfera_sub_00498730(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + 1u);
    label_0009963B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49963Bu);
    cpu->ebx += 2u;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(cpu->ebp)) goto label_00099610;
    label_00099642: cpu->eip = LIFT_CODE_TOKEN_VA(0x499642u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"pattern");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49964Eu); lift_push32(cpu, r); sfera_sub_004945C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000995B7;
    label_00099656: cpu->eip = LIFT_CODE_TOKEN_VA(0x499656u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49965Du); lift_push32(cpu, r); sfera_sub_004945B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"start_pattern");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49966Eu); lift_push32(cpu, r); sfera_sub_00494150(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_00099681;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49967Bu); lift_push32(cpu, r); sfera_sub_00494360(cpu,r); if (cpu->eip != r) return; }
    --cpu->eax;
    lift_store32(cpu->edi + 0x30u, cpu->eax);
    goto label_00099688;
    label_00099681: cpu->eip = LIFT_CODE_TOKEN_VA(0x499681u);
    lift_store32(cpu->edi + 0x30u, 0u);
    label_00099688: cpu->eip = LIFT_CODE_TOKEN_VA(0x499688u);
    cpu->edx = lift_load32(cpu->edi + 0x30u);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    if ((uint32_t)(cpu->edx) < (uint32_t)(lift_load32(cpu->edi + 0x28u))) goto label_0009969C;
    cpu->edx = 0x3D0u;
    goto label_000996E0;
    label_0009969C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49969Cu);
    cpu->edx = 0x3E6u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4996A6u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) == 0u) goto label_000996BA;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4996B1u); lift_push32(cpu, r); sfera_sub_00493C00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4996B7u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000996BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4996BAu);
    cpu->eax = 1u;
    goto label_000996FB;
    label_000996C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4996C1u);
    cpu->edx = 0x3D9u;
    goto label_000996DB;
    label_000996C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4996C8u);
    cpu->edx = 0x38Fu;
    goto label_000996DB;
    label_000996CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4996CFu);
    cpu->edx = 0x356u;
    goto label_000996DB;
    label_000996D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4996D6u);
    cpu->edx = 0x3E2u;
    label_000996DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4996DBu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    label_000996E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4996E0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4996E5u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) == 0u) goto label_000996F9;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4996F0u); lift_push32(cpu, r); sfera_sub_00493C00(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4996F6u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000996F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4996F9u);
    cpu->eax = 0u;
    label_000996FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4996FBu);
    cpu->ecx = lift_load32(cpu->esp + 0x134u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x12Cu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00499730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x499730u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&SI_GetInterface), LIFT_CODE_TOKEN_VA(0x49975Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x499764u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000997D3;
    cpu->edx = 0x67u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499777u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49977Eu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009979C;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499798u); lift_push32(cpu, r); sfera_sub_00498550(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    goto label_0009979E;
    label_0009979C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49979Cu);
    cpu->esi = 0u;
    label_0009979E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49979Eu);
    lift_store32(cpu->esp + 0x18u, 0xFFFFFFFFu);
    if ((uint32_t)(cpu->esi) == 0u) goto label_000997D3;
    lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4997B2u); lift_push32(cpu, r); sfera_sub_00499290(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000997E7;
    cpu->edx = (uint32_t)(cpu->eax + 0x6Du);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SoundTrack.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4997C3u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4997CAu); lift_push32(cpu, r); sfera_sub_00498F70(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4997D0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000997D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4997D3u);
    cpu->eax = 0u;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
    label_000997E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4997E7u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_sound_runtime.tracks;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4997F2u); lift_push32(cpu, r); sfera_sub_00498240(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00499810(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x499810u);
    lift_native_call(cpu, native_function_address32(&SI_GetInterface), LIFT_CODE_TOKEN_VA(0x499819u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49981Fu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009988F;
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_sound_runtime.tracks.first;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0009983F;
    cpu->edi = cpu->edi;
    label_00099830: cpu->eip = LIFT_CODE_TOKEN_VA(0x499830u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499838u); lift_push32(cpu, r); sfera_sub_00498AD0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(cpu->esi) != 0u) goto label_00099830;
    label_0009983F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49983Fu);
    cpu->ecx = g_sfera_music_runtime.current_stream;
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00099889;
    if ((uint32_t)(lift_load32(cpu->ecx + 0x40u)) == (uint32_t)(0u)) goto label_00099889;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499855u); lift_push32(cpu, r); sfera_sub_00499070(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(g_sfera_music_runtime.requested_path[0]), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    g_sfera_music_runtime.current_stream = (uint32_t)(0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00099889;
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_music_runtime.requested_path;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499872u); lift_push32(cpu, r); sfera_sub_00499730(cpu,r); if (cpu->eip != r) return; }
    g_sfera_music_runtime.current_stream = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00099882;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x99882u); lift_push32(cpu, r); sfera_sub_00498ED0(cpu,r); if (cpu->eip != r) return; }
    label_00099882: cpu->eip = LIFT_CODE_TOKEN_VA(0x499882u);
    g_sfera_music_runtime.requested_path[0] = (uint8_t)(0u);
    label_00099889: cpu->eip = LIFT_CODE_TOKEN_VA(0x499889u);
    cpu->eax = 1u;
    lift_return(cpu, 0u, stop_address); return;
    label_0009988F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49988Fu);
    cpu->eax = 0u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004998A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4998A0u);
    cpu->eax = cpu->ecx;
    if ((uint32_t)(cpu->eax) != 0u) goto label_000998C2;
    cpu->eax = g_sfera_music_runtime.current_stream;
    g_sfera_music_runtime.requested_path[0] = (uint8_t)((cpu->ecx & 0xFFu));
    if ((uint32_t)(cpu->eax) == 0u) goto label_000998C1;
    if ((uint32_t)(lift_load32(cpu->eax + 0x40u)) != (uint32_t)(cpu->ecx)) goto label_000998C1;
    label_000998BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4998BAu);
    lift_store32(cpu->eax + 0x48u, 1u);
    label_000998C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4998C1u);
    lift_return(cpu, 0u, stop_address); return;
    label_000998C2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4998C2u);
    cpu->ecx = lift_load32((uintptr_t)"Sounds\\Music\\");
    cpu->edx = lift_load32(((uint32_t)(uintptr_t)"Sounds\\Music\\") + 4u);
    lift_store32((uintptr_t)&g_sfera_music_runtime.requested_path[0], cpu->ecx);
    cpu->ecx = lift_load32(((uint32_t)(uintptr_t)"Sounds\\Music\\") + 8u);
    lift_store32((uintptr_t)&g_sfera_music_runtime.requested_path[4], cpu->edx);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(((uint32_t)(uintptr_t)"Sounds\\Music\\") + 0xCu)) & 0xFFFFu);
    lift_store32((uintptr_t)&g_sfera_music_runtime.requested_path[8], cpu->ecx);
    lift_store16((uintptr_t)&g_sfera_music_runtime.requested_path[12], cpu->edx & 0xFFFFu);
    cpu->ecx = cpu->eax;
    label_000998F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4998F6u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000998F6;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(uintptr_t)g_sfera_music_runtime.requested_path;
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00099910: cpu->eip = LIFT_CODE_TOKEN_VA(0x499910u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00099910;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->eax = (uint32_t)(uintptr_t)g_sfera_music_runtime.requested_path;
    cpu->edi = lift_pop32(cpu);
    --cpu->eax;
    cpu->esi = lift_pop32(cpu);
    cpu->edi = cpu->edi;
    label_00099930: cpu->eip = LIFT_CODE_TOKEN_VA(0x499930u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00099930;
    cpu->ecx = lift_load32((uintptr_t)".sst");
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)".sst") + 4u)) & 0xFFu);
    lift_store32(cpu->eax, cpu->ecx);
    lift_store8(cpu->eax + 4u, cpu->edx & 0xFFu);
    cpu->eax = g_sfera_music_runtime.current_stream;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009995C;
    if ((uint32_t)(lift_load32(cpu->eax + 0x40u)) == (uint32_t)(0u)) goto label_000998BA;
    label_0009995C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49995Cu);
    cpu->ecx = (uint32_t)(uintptr_t)g_sfera_music_runtime.requested_path;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499966u); lift_push32(cpu, r); sfera_sub_00499730(cpu,r); if (cpu->eip != r) return; }
    g_sfera_music_runtime.current_stream = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000998C1;
    cpu->ecx = cpu->eax;
    sfera_sub_00498ED0(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00499980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x499980u);
    cpu->ecx = 0u;
    lift_flags_logic(cpu,0u,32u); cpu->edx = 0u;
    label_00099984: cpu->eip = LIFT_CODE_TOKEN_VA(0x499984u);
    cpu->eax = cpu->edx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009999A;
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    label_0009999A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49999Au);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000999AF;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_000999B1;
    label_000999AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4999AFu);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_000999B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4999B1u);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000999C6;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_000999C8;
    label_000999C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4999C6u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_000999C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4999C8u);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000999DD;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_000999DF;
    label_000999DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4999DDu);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_000999DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4999DFu);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000999F4;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_000999F6;
    label_000999F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4999F4u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_000999F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4999F6u);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00099A0B;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_00099A0D;
    label_00099A0B: cpu->eip = LIFT_CODE_TOKEN_VA(0x499A0Bu);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_00099A0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x499A0Du);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00099A22;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0xEDB88320u), v=l ^ r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    goto label_00099A24;
    label_00099A22: cpu->eip = LIFT_CODE_TOKEN_VA(0x499A22u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_00099A24: cpu->eip = LIFT_CODE_TOKEN_VA(0x499A24u);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    if ((uint8_t)(((cpu->eax & 0xFFu)) & (1u)) == 0u) goto label_00099A30;
    cpu->ecx ^= 0xEDB88320u;
    label_00099A30: cpu->eip = LIFT_CODE_TOKEN_VA(0x499A30u);
    cpu->eax = (uint32_t)(cpu->edx + 0xFFFFFF9Fu);
    lift_store16(((uint32_t)(cpu->edx) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_texture_registry_runtime.hash_mix[0]), cpu->ecx & 0xFFFFu);
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x19u)) goto label_00099A50;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)g_sfera_texture_registry_runtime.hash_mix[(uint8_t)(cpu->edx - 0x20u)] & 0xFFFFu);
    lift_store16(((uint32_t)(cpu->edx) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_texture_registry_runtime.hash_mix[0]), cpu->eax & 0xFFFFu);
    label_00099A50: cpu->eip = LIFT_CODE_TOKEN_VA(0x499A50u);
    ++cpu->edx;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00099984;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00499A60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x499A60u);
    cpu->esp -= 0x1B8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = g_sfera_texture_registry_runtime.path_count;
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(0x1F4u)) goto label_00099A9B;
    cpu->ecx = (uint32_t)(uintptr_t)"scan_paths_recursive: MAX_PATH_NUM exceeded";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499A95u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = g_sfera_texture_registry_runtime.path_count;
    label_00099A9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x499A9Bu);
    cpu->ecx = cpu->edi;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x64u);
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(uintptr_t)&g_sfera_texture_registry_runtime.paths[0][0]));
    cpu->edx -= cpu->esi;
    cpu->eax = cpu->esi;
    cpu->ebx = 0u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00099AB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x499AB0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00099AB0;
    ++cpu->edi;
    cpu->edx = (uint32_t)(cpu->esp + 0x15Cu);
    g_sfera_texture_registry_runtime.path_count = (uint32_t)(cpu->edi);
    cpu->eax = cpu->esi;
    cpu->edx -= cpu->esi;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00099AD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x499AD0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00099AD0;
    cpu->eax = (uint32_t)(cpu->esp + 0x15Cu);
    --cpu->eax;
    label_00099AE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x499AE2u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00099AE2;
    cpu->edx = lift_load32((uintptr_t)"*.dds");
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(((uint32_t)(uintptr_t)"*.dds") + 4u)) & 0xFFFFu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_store16(cpu->eax + 4u, cpu->ecx & 0xFFFFu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x160u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_findfirst64i32), LIFT_CODE_TOKEN_VA(0x499B0Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x499B10u);
    cpu->esp += 8u;
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00099C6F;
    lift_push32(cpu, cpu->ebp);
    label_00099B21: cpu->eip = LIFT_CODE_TOKEN_VA(0x499B21u);
    cpu->esi = 0u;
    cpu->ebp = 0u;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x3Cu)), r=(uint64_t)(0x2Eu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00099B65;
    cpu->edi = (uint32_t)(cpu->esp + 0x3Cu);
    label_00099B30: cpu->eip = LIFT_CODE_TOKEN_VA(0x499B30u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0x1Eu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00099B3F;
    cpu->ecx = (uint32_t)(uintptr_t)"too long texture name";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x99B3Fu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00099B3F: cpu->eip = LIFT_CODE_TOKEN_VA(0x499B3Fu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi)) & 0xFFu);
    cpu->ecx = cpu->eax & 0xFFu;
    cpu->ebp = (cpu->ebp & 0xFFFF0000u) | ((uint32_t)(lift_shift_right(cpu, (cpu->ebp & 0xFFFFu), (uint32_t)(1u), 16u)) & 0xFFFFu);
    cpu->ebp = (cpu->ebp & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->ebp & 0xFFFFu)) + (uint64_t)(lift_load16(((uint32_t)(cpu->ecx) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_texture_registry_runtime.hash_mix[0]))) + (uint64_t)(0u))) & 0xFFFFu);
    lift_store8(cpu->esp + cpu->esi + 0x140u, cpu->eax & 0xFFu);
    ++cpu->esi;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + cpu->esi + 0x3Cu)), r=(uint64_t)(0x2Eu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edi = (uint32_t)(cpu->esp + cpu->esi + 0x3Cu);
    cpu->ebp = cpu->ebp & 0xFFFFu;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00099B30;
    label_00099B65: cpu->eip = LIFT_CODE_TOKEN_VA(0x499B65u);
    lift_store8(cpu->esp + cpu->esi + 0x140u, cpu->ebx & 0xFFu);
    cpu->esi = g_sfera_texture_registry_runtime.batch_count;
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(6u), 32u);
    cpu->esi += g_sfera_texture_registry_runtime.batch_records;
    lift_push32(cpu, 0x40u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x499B7Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x499B84u);
    cpu->eax = (uint32_t)(cpu->esp + 0x14Cu);
    cpu->edx = cpu->esi;
    cpu->ecx = cpu->eax;
    cpu->esp += 0xCu;
    cpu->edx -= cpu->ecx;
    label_00099B94: cpu->eip = LIFT_CODE_TOKEN_VA(0x499B94u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00099B94;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esi + 0x24u, cpu->ebx);
    lift_store32(cpu->esi + 0x20u, cpu->edx);
    lift_store32(cpu->esi + 0x38u, cpu->ebx);
    lift_store32(cpu->esi + 0x3Cu, cpu->ebx);
    cpu->edx = g_sfera_texture_registry_runtime.batch_count;
    cpu->edx += g_sfera_texture_registry_runtime.texture_count;
    cpu->eax = cpu->ebp & 0xFFFFu;
    cpu->ecx = lift_load16(((uint32_t)(cpu->eax) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_texture_registry_runtime.hash_heads[0]));
    lift_store16(((uint32_t)(cpu->eax) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_texture_registry_runtime.hash_heads[0]), cpu->edx & 0xFFFFu);
    lift_store16(cpu->esi + 0x28u, cpu->ecx & 0xFFFFu);
    lift_store32(cpu->esi + 0x30u, cpu->ebx);
    lift_store32(cpu->esi + 0x2Cu, cpu->ebx);
    cpu->eax = g_sfera_texture_registry_runtime.batch_count;
    ++cpu->eax;
    g_sfera_texture_registry_runtime.batch_count = (uint32_t)(cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xC8u)) goto label_00099C45;
    cpu->edx = g_sfera_texture_registry_runtime.texture_count;
    cpu->ecx = g_sfera_texture_set_scalar_runtime.mode_01;
    lift_push32(cpu, 0x127u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    lift_push32(cpu, (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\texturesset.cpp");
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(6u), 32u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499C09u); lift_push32(cpu, r); sfera_sub_004EBE80(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_texture_registry_runtime.batch_count;
    cpu->edx = g_sfera_texture_registry_runtime.batch_records;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(6u), 32u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_texture_registry_runtime.texture_count;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(6u), 32u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->ecx);
    g_sfera_texture_set_scalar_runtime.mode_01 = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x499C2Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x499C30u);
    cpu->edx = g_sfera_texture_registry_runtime.batch_count;
    cpu->esp += 0xCu;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_texture_registry_runtime.texture_count, (uint64_t)(g_sfera_texture_registry_runtime.texture_count) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    g_sfera_texture_registry_runtime.batch_count = (uint32_t)(cpu->ebx);
    label_00099C45: cpu->eip = LIFT_CODE_TOKEN_VA(0x499C45u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_findnext64i32), LIFT_CODE_TOKEN_VA(0x499C4Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x499C55u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00099B21;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_findclose), LIFT_CODE_TOKEN_VA(0x499C65u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x499C6Bu);
    cpu->esp += 4u;
    cpu->ebp = lift_pop32(cpu);
    label_00099C6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x499C6Fu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1B8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00499C90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x499C90u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499C95u); lift_push32(cpu, r); sfera_sub_00499980(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x20000u); lift_push32(cpu, 0xFFu); lift_push32(cpu, (uintptr_t)&g_sfera_texture_registry_runtime.hash_heads[0]);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x499CA4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x499CA9u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0x16Fu);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\texturesset.cpp";
    cpu->ecx = 0x3200u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499CC0u); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    g_sfera_texture_registry_runtime.batch_records = (uint32_t)(cpu->eax);
    g_sfera_texture_registry_runtime.initialized = (uint32_t)(1u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00499CD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x499CD0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00099CD8: cpu->eip = LIFT_CODE_TOKEN_VA(0x499CD8u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00099CD8;
    cpu->eax -= cpu->edx;
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x5Au)) goto label_00099CF0;
    cpu->ecx = (uint32_t)(uintptr_t)"add_texture_folder: MAX_TEX_PATH_LEN exceeded";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x99CF0u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_00099CF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x499CF0u);
    cpu->ecx = cpu->esi;
    g_sfera_texture_registry_runtime.batch_count = (uint32_t)(0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499D01u); lift_push32(cpu, r); sfera_sub_00499A60(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_texture_registry_runtime.batch_count;
    cpu->esi = lift_pop32(cpu);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00099D61;
    cpu->edx = g_sfera_texture_registry_runtime.texture_count;
    cpu->ecx = g_sfera_texture_set_scalar_runtime.mode_01;
    lift_push32(cpu, 0x1B4u);
    cpu->edx = (uint32_t)(cpu->edx + cpu->eax);
    lift_push32(cpu, (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\texturesset.cpp");
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(6u), 32u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499D2Cu); lift_push32(cpu, r); sfera_sub_004EBE80(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_texture_registry_runtime.batch_count;
    cpu->ecx = g_sfera_texture_registry_runtime.batch_records;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(6u), 32u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = g_sfera_texture_registry_runtime.texture_count;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(6u), 32u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->eax;
    lift_push32(cpu, cpu->edx);
    g_sfera_texture_set_scalar_runtime.mode_01 = (uint32_t)(cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x499D4Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x499D53u);
    cpu->eax = g_sfera_texture_registry_runtime.batch_count;
    cpu->esp += 0xCu;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_texture_registry_runtime.texture_count, (uint64_t)(g_sfera_texture_registry_runtime.texture_count) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    label_00099D61: cpu->eip = LIFT_CODE_TOKEN_VA(0x499D61u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00499D70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x499D70u);
    { uint64_t l=(uint64_t)(g_sfera_texture_registry_runtime.initialized), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00099E11;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebx)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00099E11;
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->edx = cpu->ebx;
    label_00099D91: cpu->eip = LIFT_CODE_TOKEN_VA(0x499D91u);
    cpu->eax = cpu->eax & 0xFFu;
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_shift_right(cpu, (cpu->ecx & 0xFFFFu), (uint32_t)(1u), 16u)) & 0xFFFFu);
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFFFu)) + (uint64_t)(lift_load16(((uint32_t)(cpu->eax) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_texture_registry_runtime.hash_mix[0]))) + (uint64_t)(0u))) & 0xFFFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx + 1u)) & 0xFFu);
    ++cpu->edx;
    cpu->ecx = cpu->ecx & 0xFFFFu;
    { uint64_t v=(uint64_t)((cpu->eax & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00099D91;
    cpu->edi = lift_load16(((uint32_t)(cpu->ecx) * 2u) + ((uint32_t)(uintptr_t)&g_sfera_texture_registry_runtime.hash_heads[0]));
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0xFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00099E11;
    cpu->edx = g_sfera_texture_set_scalar_runtime.mode_01;
    cpu->ebp = native_function_address32(&::_stricmp);
    cpu->esi = cpu->edi;
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(6u), 32u);
    cpu->eax = (uint32_t)(cpu->esi + cpu->edx);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x99DD2u), LIFT_CODE_TOKEN_RVA(0x99DD0u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x499DD2u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_00099E0A;
    cpu->esp = (uint32_t)(cpu->esp);
    label_00099DE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x499DE0u);
    cpu->ecx = g_sfera_texture_set_scalar_runtime.mode_01;
    cpu->eax = lift_load16(cpu->esi + cpu->ecx + 0x28u);
    cpu->edx = 0xFFFFu;
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFFFu)), r=(uint64_t)((cpu->edx & 0xFFFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,16u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00099E11;
    cpu->edi = cpu->eax;
    cpu->esi = cpu->edi;
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(6u), 32u);
    cpu->eax = (uint32_t)(cpu->esi + cpu->ecx);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x99E03u), LIFT_CODE_TOKEN_RVA(0x99E01u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x499E03u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00099DE0;
    label_00099E0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x499E0Au);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00099E11: cpu->eip = LIFT_CODE_TOKEN_VA(0x499E11u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00499E20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x499E20u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->ecx) < 0) goto label_00099E33;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(g_sfera_texture_registry_runtime.texture_count), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00099E64;
    label_00099E33: cpu->eip = LIFT_CODE_TOKEN_VA(0x499E33u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, (uintptr_t)"preload_texture_from_memory: wrong textureID = %d"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x14u, (uintptr_t)"..\\ShareClientSeverCode\\texturesset.cpp");
    lift_store32(cpu->esp + 0x18u, 0x219u);
    lift_store32(cpu->esp + 0x1Cu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499E5Bu); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_texture_registry_runtime.default_texture_id;
    { uint64_t l=cpu->esp, r=(uint64_t)(0xCu), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    label_00099E64: cpu->eip = LIFT_CODE_TOKEN_VA(0x499E64u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(6u), 32u);
    cpu->ecx += g_sfera_texture_set_scalar_runtime.mode_01;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi)), r=(uint64_t)(0x20534444u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00099ECD;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->edi + 0x2Cu, 1u);
    if ((uint32_t)((lift_load32(cpu->esi + 0x70u)) & (0x200u)) == 0u) goto label_00099EA8;
    cpu->edi += 0x24u;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499EA0u); lift_push32(cpu, r); sfera_sub_004D8F10(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_00099EA8: cpu->eip = LIFT_CODE_TOKEN_VA(0x499EA8u);
    cpu->eax = (uint32_t)(cpu->edi + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499EBDu); lift_push32(cpu, r); sfera_sub_004D8ED0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0x54u)) != (uint32_t)(0x1545844u)) goto label_00099ECD;
    lift_store32(cpu->edi + 0x2Cu, 0u);
    label_00099ECD: cpu->eip = LIFT_CODE_TOKEN_VA(0x499ECDu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00499EE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x499EE0u);
    lift_store32((uint32_t)(uintptr_t)&g_sfera_texture_registry_runtime.preload_request_count, (uint64_t)(g_sfera_texture_registry_runtime.preload_request_count) + 1u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00499EF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x499EF0u);
    cpu->eax = g_sfera_texture_set_scalar_runtime.state_01;
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_texture_set_scalar_runtime.state_03;
    lift_push32(cpu, cpu->edi);
    cpu->esi += cpu->ecx;
    cpu->ecx = g_sfera_texture_set_scalar_runtime.state_02;
    cpu->edx = cpu->eax;
    cpu->edi = cpu->ecx;
    cpu->ecx = lift_double_shift_left(cpu, cpu->ecx, cpu->eax, (uint32_t)(3u), 32u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, 0u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    lift_push32(cpu, 0xAu);
    cpu->edi = (uint64_t)(cpu->edi) + (uint64_t)(cpu->ecx) + (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    g_sfera_texture_set_scalar_runtime.state_03 = (uint32_t)(cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499F28u); lift_push32(cpu, r); sfera_sub_004EEA40(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->ecx = cpu->edx;
    cpu->eax = cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00099F43;
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00099F39;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->edi)) goto label_00099F43;
    label_00099F39: cpu->eip = LIFT_CODE_TOKEN_VA(0x499F39u);
    g_sfera_texture_registry_runtime.stream_direction_flag = (uint32_t)(1u);
    label_00099F43: cpu->eip = LIFT_CODE_TOKEN_VA(0x499F43u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00499F50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x499F50u);
    cpu->eax = g_sfera_texture_set_scalar_runtime.state_01;
    lift_push32(cpu, cpu->esi);
    cpu->esi = g_sfera_texture_set_scalar_runtime.state_03;
    cpu->esi -= cpu->ecx;
    cpu->ecx = g_sfera_texture_set_scalar_runtime.state_02;
    cpu->ecx = lift_double_shift_left(cpu, cpu->ecx, cpu->eax, (uint32_t)(3u), 32u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u);
    cpu->eax += cpu->eax;
    lift_push32(cpu, 0xAu);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    g_sfera_texture_set_scalar_runtime.state_03 = (uint32_t)(cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499F80u); lift_push32(cpu, r); sfera_sub_004EEA40(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->ecx = cpu->edx;
    cpu->eax = cpu->esi;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) == 0u) && ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u)) goto label_00099F9B;
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_00099F91;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edi)) goto label_00099F9B;
    label_00099F91: cpu->eip = LIFT_CODE_TOKEN_VA(0x499F91u);
    g_sfera_texture_registry_runtime.stream_direction_flag = (uint32_t)(0u);
    label_00099F9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x499F9Bu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00499FA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x499FA0u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    cpu->eax = cpu->esi;
    cpu->ebx = cpu->ecx;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    label_00099FB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x499FB0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_00099FB0;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x200u)) goto label_0009A00A;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"SSTR::operator=: buffer overflow! - %s"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\sstr.h");
    lift_store32(cpu->esp + 0x1Cu, 0x6Du);
    lift_store32(cpu->esp + 0x20u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x499FE9u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->ebx;
    cpu->ecx = 0x7Fu;
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    cpu->esp += 0xCu;
    lift_movs8(cpu, 0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store8(cpu->ebx + 0x1FFu, 0u);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_0009A00A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A00Au);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x49A00Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49A013u);
    cpu->esp += 0xCu;
    cpu->esi = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049A020(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49A020u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_0009A062;
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, (uintptr_t)"SSTR::append: wrong count=%d"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x10u, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\sstr.h");
    lift_store32(cpu->esp + 0x14u, 0xC0u);
    lift_store32(cpu->esp + 0x18u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A056u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0xCu;
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 8u, stop_address); return;
    label_0009A062: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A062u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ebp;
    lift_push32(cpu, cpu->edi);
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    cpu->edi = cpu->edi;
    label_0009A070: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A070u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0009A070;
    cpu->eax -= cpu->esi;
    cpu->ecx = cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edx) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_0009A081;
    cpu->ecx = cpu->edx;
    label_0009A081: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A081u);
    cpu->eax = cpu->ebx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_0009A086: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A086u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0009A086;
    cpu->eax -= cpu->esi;
    cpu->edi = cpu->eax;
    cpu->esi = (uint32_t)(cpu->edi + cpu->ecx + 1u);
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(0x200u)) goto label_0009A0D3;
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, (uintptr_t)"SSTR::append: buffer overflow!"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x18u, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\sstr.h");
    lift_store32(cpu->esp + 0x1Cu, 0xCBu);
    lift_store32(cpu->esp + 0x20u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A0C4u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0x1FFu;
    cpu->esp += 8u;
    cpu->ecx -= cpu->edi;
    cpu->esi = 0x200u;
    label_0009A0D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A0D3u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    cpu->edi += cpu->ebx;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x49A0D8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49A0DDu);
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi + cpu->ebx + 0xFFFFFFFFu, 0u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049A100(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49A100u);
    cpu->ecx = g_sfera_texture_registry_runtime.batch_records;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 0x176u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\texturesset.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A116u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"default";
    g_sfera_texture_registry_runtime.default_texture_id = (uint32_t)(0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A12Au); lift_push32(cpu, r); sfera_sub_00499D70(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) != (uint32_t)(0xFFFFFFFFu)) goto label_0009A13B;
    cpu->ecx = (uint32_t)(uintptr_t)"Texture 'default' not found";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9A13Bu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    label_0009A13B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A13Bu);
    cpu->ecx = g_sfera_texture_registry_runtime.texture_count;
    cpu->ecx += cpu->ecx;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, 0x17Fu);
    cpu->ecx += cpu->ecx;
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\texturesset.cpp";
    g_sfera_texture_registry_runtime.default_texture_id = (uint32_t)(cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A15Cu); lift_push32(cpu, r); sfera_sub_004EBE60(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_texture_registry_runtime.texture_count;
    g_sfera_texture_set_scalar_runtime.mode_02 = (uint32_t)(cpu->eax);
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_0009A1B2;
    cpu->edx = 0u;
    cpu->ecx = (uint32_t)(cpu->edx + 1u);
    goto label_0009A177;
    label_0009A172: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A172u);
    cpu->eax = g_sfera_texture_set_scalar_runtime.mode_02;
    label_0009A177: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A177u);
    cpu->esi = (uint32_t)(cpu->ecx + 0xFFFFFFFEu);
    lift_store32(cpu->edx + cpu->eax, cpu->esi);
    cpu->eax = g_sfera_texture_set_scalar_runtime.mode_02;
    lift_store32(cpu->edx + cpu->eax + 4u, cpu->ecx);
    cpu->eax = g_sfera_texture_registry_runtime.texture_count;
    ++cpu->ecx;
    cpu->esi = (uint32_t)(cpu->ecx + 0xFFFFFFFFu);
    cpu->edx += 8u;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->eax)) goto label_0009A172;
    cpu->ecx = g_sfera_texture_set_scalar_runtime.mode_02;
    lift_store32(cpu->ecx + ((uint32_t)(cpu->eax) * 8u) + 0xFFFFFFFCu, 0xF4240u);
    cpu->edx = g_sfera_texture_registry_runtime.texture_count;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0009A1B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A1B2u);
    lift_store32(cpu->eax + ((uint32_t)(cpu->ecx) * 8u) + 0xFFFFFFFCu, 0xF4240u);
    cpu->eax = g_sfera_texture_registry_runtime.texture_count;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049A1D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49A1D0u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    if ((int32_t)(uint32_t)(g_sfera_texture_registry_runtime.texture_count) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0009A20B;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    (void)cpu;
    label_0009A1E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A1E0u);
    cpu->eax = g_sfera_texture_set_scalar_runtime.mode_01;
    cpu->esi = (uint32_t)(cpu->edi + cpu->eax + 0x24u);
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009A1FD;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x9A1F7u), LIFT_CODE_TOKEN_RVA(0x9A1F5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49A1F7u);
    lift_store32(cpu->esi, 0u);
    label_0009A1FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A1FDu);
    ++cpu->ebx;
    cpu->edi += 0x40u;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(g_sfera_texture_registry_runtime.texture_count)) goto label_0009A1E0;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    label_0009A20B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A20Bu);
    cpu->ecx = g_sfera_texture_set_scalar_runtime.mode_01;
    cpu->ebx = lift_pop32(cpu);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0009A22F;
    lift_push32(cpu, 0x192u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\texturesset.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A225u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    g_sfera_texture_set_scalar_runtime.mode_01 = (uint32_t)(0u);
    label_0009A22F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A22Fu);
    cpu->ecx = g_sfera_texture_set_scalar_runtime.mode_02;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0009A252;
    lift_push32(cpu, 0x193u);
    cpu->edx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\texturesset.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A248u); lift_push32(cpu, r); sfera_sub_004EB520(cpu,r); if (cpu->eip != r) return; }
    g_sfera_texture_set_scalar_runtime.mode_02 = (uint32_t)(0u);
    label_0009A252: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A252u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049A260(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49A260u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x244u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x258u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = cpu->ecx;
    cpu->eax = g_sfera_texture_registry_runtime.texture_count;
    cpu->edi = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\texturesset.cpp";
    if ((int32_t)(uint32_t)(cpu->ebp) < 0) goto label_0009A2AF;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0009A2DD;
    label_0009A2AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A2AFu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, (uintptr_t)"preload_texture: wrong textureID = %d, texsNum = %d"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    lift_store32(cpu->esp + 0x34u, 0x24Au);
    lift_store32(cpu->esp + 0x38u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A2D4u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = g_sfera_texture_registry_runtime.default_texture_id;
    { uint64_t l=cpu->esp, r=(uint64_t)(0x10u), v=l + r; lift_flags_add(cpu,l,r,0u,v,32u); cpu->esp= v; }
    label_0009A2DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A2DDu);
    cpu->ecx = g_sfera_texture_set_scalar_runtime.mode_01;
    cpu->edx = lift_load32((uintptr_t)&g_sfera_texture_set_scalar_runtime.record_default_38);
    cpu->eax = cpu->ebp;
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(6u), 32u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + cpu->ecx + 0x24u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = (uint32_t)(cpu->eax + cpu->ecx);
    lift_store32(cpu->ebx + 0x38u, cpu->edx);
    cpu->ecx = lift_load32((uintptr_t)&g_sfera_texture_set_scalar_runtime.record_default_3c);
    lift_store32(cpu->ebx + 0x3Cu, cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009A462;
    cpu->edx = g_sfera_texture_set_scalar_runtime.mode_01;
    cpu->esi = (uint32_t)(cpu->eax + cpu->edx);
    lift_store8(cpu->esp + 0x54u, 0u);
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x64u);
    cpu->eax += ((uint32_t)(uintptr_t)&g_sfera_texture_registry_runtime.paths[0][0]);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x58u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A32Bu); lift_push32(cpu, r); sfera_sub_00499FA0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x5Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A33Au); lift_push32(cpu, r); sfera_sub_0049A020(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7FFFFFFFu); lift_push32(cpu, (uintptr_t)".dds");
    cpu->ecx = (uint32_t)(cpu->esp + 0x5Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A34Du); lift_push32(cpu, r); sfera_sub_0049A020(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A35Bu); lift_push32(cpu, r); sfera_sub_004EDA30(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_texture_set_scalar_runtime.mode_02;
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->ebp) * 8u));
    cpu->edx = lift_load32(cpu->eax + ((uint32_t)(cpu->ebp) * 8u) + 4u);
    lift_store32(cpu->esp + 0x260u, 0u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xFFFFFFFFu)) goto label_0009A382;
    lift_store32(cpu->eax + ((uint32_t)(cpu->ecx) * 8u) + 4u, cpu->edx);
    cpu->eax = g_sfera_texture_set_scalar_runtime.mode_02;
    goto label_0009A388;
    label_0009A382: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A382u);
    lift_store32((uintptr_t)&g_sfera_texture_set_scalar_runtime.last_selector, cpu->edx);
    label_0009A388: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A388u);
    if ((uint32_t)(cpu->edx) == (uint32_t)(0xF4240u)) goto label_0009A398;
    lift_store32(cpu->eax + ((uint32_t)(cpu->edx) * 8u), cpu->ecx);
    cpu->eax = g_sfera_texture_set_scalar_runtime.mode_02;
    label_0009A398: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A398u);
    cpu->ecx = g_sfera_graphics_runtime.texture_runtime_id;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(0xF4240u)) goto label_0009A3B0;
    lift_store32(cpu->eax + ((uint32_t)(cpu->ecx) * 8u), cpu->ebp);
    cpu->eax = g_sfera_texture_set_scalar_runtime.mode_02;
    goto label_0009A3B6;
    label_0009A3B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A3B0u);
    label_0009A3B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A3B6u);
    lift_store32(cpu->eax + ((uint32_t)(cpu->ebp) * 8u), 0xFFFFFFFFu);
    cpu->edx = g_sfera_graphics_runtime.texture_runtime_id;
    cpu->eax = g_sfera_texture_set_scalar_runtime.mode_02;
    lift_store32(cpu->eax + ((uint32_t)(cpu->ebp) * 8u) + 4u, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    g_sfera_graphics_runtime.texture_runtime_id = (uint32_t)(cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A3DBu); lift_push32(cpu, r); sfera_sub_004ED7D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0009A42A;
    cpu->esp -= 0x200u;
    lift_store32(cpu->esp + 0x214u, cpu->edi);
    cpu->edi = cpu->esp;
    cpu->ecx = 0x80u;
    cpu->esi = (uint32_t)(cpu->esp + 0x254u);
    lift_movs32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x214u);
    lift_push32(cpu, (uintptr_t)"File not found %s"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x220u, 0x265u);
    lift_store32(cpu->esp + 0x224u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A424u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 0x208u;
    label_0009A42A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A42Au);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A433u); lift_push32(cpu, r); sfera_sub_004ED7F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A43Du); lift_push32(cpu, r); sfera_sub_004ED860(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A446u); lift_push32(cpu, r); sfera_sub_00499E20(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::UnmapViewOfFile), LIFT_CODE_TOKEN_VA(0x49A448u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49A44Eu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 0x260u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9A462u); lift_push32(cpu, r); sfera_sub_004ED8E0(cpu,r); if (cpu->eip != r) return; }
    label_0009A462: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A462u);
    cpu->eax = cpu->ebx;
    cpu->ecx = lift_load32(cpu->esp + 0x258u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x250u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049A490(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49A490u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A495u); lift_push32(cpu, r); sfera_sub_0049A260(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->eax + 0x24u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049A4A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49A4A0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A4A5u); lift_push32(cpu, r); sfera_sub_00499D70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A4ACu); lift_push32(cpu, r); sfera_sub_0049A260(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->eax + 0x24u);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049A4B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49A4B0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A4B5u); lift_push32(cpu, r); sfera_sub_0049A260(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->eax + 0x2Cu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049A4C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49A4C0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A4C5u); lift_push32(cpu, r); sfera_sub_00499D70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A4CCu); lift_push32(cpu, r); sfera_sub_0049A260(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->eax + 0x2Cu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049A4D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49A4D0u);
    cpu->esp -= 8u;
    cpu->eax = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::QueryPerformanceFrequency), LIFT_CODE_TOKEN_VA(0x49A4D7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49A4DDu);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->esp);
    cpu->edx = 0u;
    g_sfera_high_resolution_clock_runtime.performance_frequency.low = (uint32_t)(cpu->ecx);
    g_sfera_high_resolution_clock_runtime.performance_frequency.high = (uint32_t)(cpu->eax);
    g_sfera_high_resolution_clock_runtime.frequency_shift = (uint32_t)(cpu->edx);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009A503;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x1E8480u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0009A529;
    label_0009A503: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A503u);
    cpu->ecx = lift_double_shift_right(cpu, cpu->ecx, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    ++cpu->edx;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0009A503;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0009A518;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x1E8480u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0009A503;
    label_0009A518: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A518u);
    g_sfera_high_resolution_clock_runtime.performance_frequency.low = (uint32_t)(cpu->ecx);
    g_sfera_high_resolution_clock_runtime.performance_frequency.high = (uint32_t)(cpu->eax);
    g_sfera_high_resolution_clock_runtime.frequency_shift = (uint32_t)(cpu->edx);
    label_0009A529: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A529u);
    cpu->ecx = (uint32_t)(cpu->esp);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::QueryPerformanceCounter), LIFT_CODE_TOKEN_VA(0x49A52Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49A533u);
    cpu->edx = lift_load32(cpu->esp);
    cpu->eax = lift_load32(cpu->esp + 4u);
    g_sfera_high_resolution_clock_runtime.counter_anchor.low = (uint32_t)(cpu->edx);
    g_sfera_high_resolution_clock_runtime.counter_anchor.high = (uint32_t)(cpu->eax);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049A550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49A550u);
    cpu->esp -= 8u;
    if ((uint32_t)(g_sfera_high_resolution_clock_runtime.initialized) != (uint32_t)(0u)) goto label_0009A56B;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A561u); lift_push32(cpu, r); sfera_sub_0049A4D0(cpu,r); if (cpu->eip != r) return; }
    g_sfera_high_resolution_clock_runtime.initialized = (uint32_t)(1u);
    label_0009A56B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A56Bu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::QueryPerformanceCounter), LIFT_CODE_TOKEN_VA(0x49A574u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49A57Au);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = g_sfera_high_resolution_clock_runtime.counter_anchor.low;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->ebp = g_sfera_high_resolution_clock_runtime.counter_anchor.high;
    cpu->ecx = g_sfera_high_resolution_clock_runtime.frequency_shift;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(cpu->ebp) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A59Du); lift_push32(cpu, r); sfera_sub_004EEE10(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = g_sfera_high_resolution_clock_runtime.elapsed_counter.low;
    cpu->esi = g_sfera_high_resolution_clock_runtime.elapsed_counter.high;
    cpu->ecx = g_sfera_high_resolution_clock_runtime.frequency_shift;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->esi = (uint64_t)(cpu->esi) + (uint64_t)(cpu->edx) + (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    g_sfera_high_resolution_clock_runtime.elapsed_counter.low = (uint32_t)(cpu->edi);
    g_sfera_high_resolution_clock_runtime.elapsed_counter.high = (uint32_t)(cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A5C4u); lift_push32(cpu, r); sfera_sub_004EEDF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_high_resolution_clock_runtime.performance_frequency.high;
    lift_push32(cpu, 0u);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ebx = v; }
    lift_push32(cpu, 0x3E8u);
    cpu->ebp = (uint64_t)(cpu->ebp) + (uint64_t)(cpu->edx) + (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->edx = g_sfera_high_resolution_clock_runtime.performance_frequency.low;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    g_sfera_high_resolution_clock_runtime.counter_anchor.low = (uint32_t)(cpu->ebx);
    g_sfera_high_resolution_clock_runtime.counter_anchor.high = (uint32_t)(cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A5EEu); lift_push32(cpu, r); sfera_sub_004EED20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edx;
    cpu->ebx = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0009A662;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0009A5FC;
    if ((uint32_t)(cpu->edi) <= (uint32_t)(cpu->ebx)) goto label_0009A662;
    label_0009A5FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A5FCu);
    cpu->ebx = g_sfera_high_resolution_clock_runtime.epoch_microseconds.high;
    label_0009A602: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A602u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->esi = (uint64_t)(cpu->esi) - (uint64_t)(cpu->edx) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    { uint64_t l=(uint64_t)(g_sfera_high_resolution_clock_runtime.epoch_microseconds.low), r=(uint64_t)(0x3B9ACA00u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); g_sfera_high_resolution_clock_runtime.epoch_microseconds.low = (uint32_t)((v)); }
    cpu->ebx = (uint64_t)(cpu->ebx) + (uint64_t)(0u) + (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0009A602;
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0009A61D;
    if ((uint32_t)(cpu->edi) > (uint32_t)(cpu->eax)) goto label_0009A602;
    label_0009A61D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A61Du);
    g_sfera_high_resolution_clock_runtime.elapsed_counter.low = (uint32_t)(cpu->edi);
    g_sfera_high_resolution_clock_runtime.elapsed_counter.high = (uint32_t)(cpu->esi);
    g_sfera_high_resolution_clock_runtime.epoch_microseconds.high = (uint32_t)(cpu->ebx);
    label_0009A62F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A62Fu);
    lift_push32(cpu, 0u); lift_push32(cpu, 0xF4240u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A63Du); lift_push32(cpu, r); sfera_sub_004EED20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_high_resolution_clock_runtime.performance_frequency.high;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_high_resolution_clock_runtime.performance_frequency.low;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A652u); lift_push32(cpu, r); sfera_sub_004EED80(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(g_sfera_high_resolution_clock_runtime.epoch_microseconds.low), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->edx = (uint64_t)(cpu->edx) + (uint64_t)(cpu->ebx) + (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
    label_0009A662: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A662u);
    cpu->ebx = g_sfera_high_resolution_clock_runtime.epoch_microseconds.high;
    goto label_0009A62F;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049A670(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49A670u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A675u); lift_push32(cpu, r); sfera_sub_0049A550(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0u); lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A680u); lift_push32(cpu, r); sfera_sub_004EEA40(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049A690(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49A690u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx |= 0xFFFFFFFFu;
    if ((uint32_t)(g_sfera_profiler_runtime.call_count[cpu->esi]) == (uint32_t)(cpu->ecx)) goto label_0009A6CB;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    if ((uint8_t)(g_sfera_profiler_runtime.active[cpu->esi]) != (uint8_t)((cpu->eax & 0xFFu))) goto label_0009A6B2;
    g_sfera_profiler_runtime.call_count[cpu->esi] = (uint32_t)(cpu->ecx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0009A6B2: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A6B2u);
    g_sfera_profiler_runtime.active[cpu->esi] = (uint8_t)(cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A6BDu); lift_push32(cpu, r); sfera_sub_0049A550(cpu,r); if (cpu->eip != r) return; }
    g_sfera_profiler_runtime.start_time_us[cpu->esi].low = (uint32_t)(cpu->eax);
    g_sfera_profiler_runtime.start_time_us[cpu->esi].high = (uint32_t)(cpu->edx);
    label_0009A6CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A6CBu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049A6D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49A6D0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax |= 0xFFFFFFFFu;
    if ((uint32_t)(g_sfera_profiler_runtime.call_count[cpu->esi]) == (uint32_t)(cpu->eax)) goto label_0009A722;
    if ((uint8_t)(g_sfera_profiler_runtime.active[cpu->esi]) != (uint8_t)(0u)) goto label_0009A6F1;
    g_sfera_profiler_runtime.call_count[cpu->esi] = (uint32_t)(cpu->eax);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0009A6F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A6F1u);
    g_sfera_profiler_runtime.active[cpu->esi] = UINT8_C(0);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A6FDu); lift_push32(cpu, r); sfera_sub_0049A550(cpu,r); if (cpu->eip != r) return; }
    g_sfera_profiler_runtime.report_clock_snapshot.low = (uint32_t)(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(g_sfera_profiler_runtime.start_time_us[cpu->esi].low), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = (uintptr_t)&g_sfera_profiler_runtime.accumulated_ticks[cpu->esi];
    g_sfera_profiler_runtime.report_clock_snapshot.high = (uint32_t)(cpu->edx);
    cpu->edx = (uint64_t)(cpu->edx) - (uint64_t)(g_sfera_profiler_runtime.start_time_us[cpu->esi].high) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    { uint64_t l=(uint64_t)(lift_load32(cpu->ecx)), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); lift_store32(cpu->ecx, v); }
    lift_store32(cpu->ecx + 4u, (uint64_t)(lift_load32(cpu->ecx + 4u)) + (uint64_t)(cpu->edx) + (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)));
    label_0009A722: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A722u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049A730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49A730u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFC0u;
    cpu->esp -= 0x34u;
    { uint64_t l=(uint64_t)(g_sfera_profiler_runtime.frame_count), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009A883;
    if ((uint32_t)(g_sfera_profiler_runtime.frame_time_total) == (uint32_t)(0u)) goto label_0009A883;
    lift_push32(cpu, (uintptr_t)"a"); lift_push32(cpu, (uintptr_t)"logs\\profile.txt");
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x49A760u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49A766u);
    cpu->ebx = native_function_address32(&::fprintf);
    cpu->edi = cpu->eax;
    lift_push32(cpu, (uintptr_t)"\n\nProfile results:\n"); lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x9A776u), LIFT_CODE_TOKEN_RVA(0x9A774u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49A776u);
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_profiler_runtime.frame_time_total))));
    cpu->eax = g_sfera_profiler_runtime.frame_time_total;
    cpu->esp += 0x10u;
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0009A78E;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0009A78E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A78Eu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / ((double)(((int32_t)(g_sfera_profiler_runtime.frame_count)))));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A79Du); lift_push32(cpu, r); sfera_sub_0049A550(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u));
    g_sfera_profiler_runtime.report_clock_snapshot.low = (uint32_t)(cpu->eax);
    lift_store16(cpu->esp + 0x30u, cpu->fpu_control);
    g_sfera_profiler_runtime.report_clock_snapshot.high = (uint32_t)(cpu->edx);
    cpu->eax = lift_load16(cpu->esp + 0x30u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    cpu->edx = 0u;
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x38u));
    lift_store64(cpu->esp + 0x38u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    cpu->eax = g_sfera_profiler_runtime.report_clock_snapshot.low;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 0u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x30u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"Average frame time = %d  (fps = %d)\n\n"); lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x9A7E1u), LIFT_CODE_TOKEN_RVA(0x9A7DFu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49A7E1u);
    cpu->esp += 0x10u;
    cpu->esi = 0u;
    label_0009A7F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A7F0u);
    cpu->eax = g_sfera_profiler_runtime.call_count[cpu->esi];
    lift_store32(cpu->esp + 0x30u, cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009A86F;
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_0009A812;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"N=%d,  ERROR\n"); lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x9A80Du), LIFT_CODE_TOKEN_RVA(0x9A80Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49A80Du);
    cpu->esp += 0xCu;
    goto label_0009A86F;
    label_0009A812: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A812u);
    lift_x87_push(cpu, (double)(((int32_t)(g_sfera_profiler_runtime.frame_count))));
    cpu->esp -= 0x18u;
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int64_t)(lift_load64((uintptr_t)&g_sfera_profiler_runtime.accumulated_ticks[cpu->esi])))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x50u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x50u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (((double)lift_load_f32(cpu->esp + 0x4Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (100.0));
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x50u));
    lift_store_f64(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    lift_store_f64(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, ((double)(((int32_t)(lift_load32(cpu->esp + 0x48u))))) / (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x50u));
    lift_store_f64(cpu->esp, lift_x87_get(cpu, 0u));
    lift_x87_pop(cpu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"N=%d,  ANoC = %5.2f,  AT = %7.1f,  AP = %5.2f\n"); lift_push32(cpu, cpu->edi);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x9A86Cu), LIFT_CODE_TOKEN_RVA(0x9A86Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49A86Cu);
    cpu->esp += 0x24u;
    label_0009A86F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A86Fu);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(0x64u)) goto label_0009A7F0;
    lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x49A87Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49A880u);
    cpu->esp += 4u;
    label_0009A883: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A883u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049A890(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49A890u);
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    label_0009A892: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A892u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    if ((uint8_t)(((cpu->ecx & 0xFFu)) & (1u)) == 0u) goto label_0009A8A0;
    cpu->eax ^= 0xEDB88320u;
    label_0009A8A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A8A0u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009A8AD;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0009A8AF;
    label_0009A8AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A8ADu);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0009A8AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A8AFu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009A8BC;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0009A8BE;
    label_0009A8BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A8BCu);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0009A8BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A8BEu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009A8CB;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0009A8CD;
    label_0009A8CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A8CBu);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0009A8CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A8CDu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009A8DA;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0009A8DC;
    label_0009A8DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A8DAu);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0009A8DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A8DCu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009A8E9;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0009A8EB;
    label_0009A8E9: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A8E9u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0009A8EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A8EBu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009A8F8;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0009A8FA;
    label_0009A8F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A8F8u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0009A8FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A8FAu);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(1u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009A907;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    cpu->eax ^= 0xEDB88320u;
    goto label_0009A909;
    label_0009A907: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A907u);
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(1u), 32u);
    label_0009A909: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A909u);
    g_sfera_crc32_runtime.table[cpu->ecx] = (uint32_t)(cpu->eax);
    ++cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(0x100u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0009A892;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049A920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49A920u);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0009A94F;
    cpu->eax = g_sfera_crc32_runtime.current;
    lift_push32(cpu, cpu->esi);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0009A930: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A930u);
    cpu->esi = (int8_t)(lift_load8(cpu->ecx));
    cpu->esi ^= cpu->eax;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax ^= g_sfera_crc32_runtime.table[cpu->esi];
    ++cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    g_sfera_crc32_runtime.current = (uint32_t)(cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009A930;
    cpu->esi = lift_pop32(cpu);
    label_0009A94F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A94Fu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049A950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49A950u);
    cpu->eax = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    lift_store8(cpu->eax, cpu->ebx & 0xFFu);
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_store8(cpu->eax + 1u, 1u);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    lift_store32(cpu->eax + 0x124u, 1u);
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->eax + 0x434u, cpu->ebx);
    cpu->esi = (uint32_t)(cpu->eax + 0x10u);
    lift_store32(cpu->eax + 0x638u, cpu->ebx);
    lift_store32(cpu->eax + 0x63Cu, cpu->ebx);
    lift_store32(cpu->eax + 0x640u, cpu->ebx);
    lift_store32(cpu->eax + 0x644u, cpu->ebx);
    cpu->esi -= cpu->ecx;
    label_0009A997: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A997u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->esi + cpu->ecx, cpu->edx & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0009A997;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049A9B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49A9B0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x638u);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_0009A9F5;
    cpu->eax = lift_load32(cpu->esi + 0x63Cu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_push32(cpu, 0x64u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A9D0u); lift_push32(cpu, r); sfera_sub_004EED20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0x638u);
    cpu->edi = cpu->edx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49A9E4u); lift_push32(cpu, r); sfera_sub_004EEA40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x434u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0009A9F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x49A9F5u);
    cpu->edx = lift_load32(cpu->esp + 8u);
    lift_store32(cpu->edx, 0u);
    cpu->eax = lift_load32(cpu->esi + 0x434u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049AA10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49AA10u);
    cpu->eax = 0x18D4u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49AA1Au); lift_push32(cpu, r); sfera_sub_004EEAF0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 0u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::_time64);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x18E0u);
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store32(cpu->esp + 0x28u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->ebp + 0x128u, cpu->eax);
    lift_store32(cpu->ebp + 0x22Cu, cpu->eax);
    lift_store32(cpu->ebp + 0x330u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x9AA64u), LIFT_CODE_TOKEN_RVA(0x9AA62u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49AA64u);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->esp += 4u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49AA74u); lift_push32(cpu, r); sfera_sub_0049A890(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x9AA7Bu), LIFT_CODE_TOKEN_RVA(0x9AA79u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49AA7Bu);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_x87_push(cpu, ::_difftime64(static_cast<__time64_t>(lift_load64(cpu->esp)), static_cast<__time64_t>(lift_load64(cpu->esp + 8u))));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 15.0);
    lift_x87_pop(cpu);
    cpu->esp += 0x14u;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0009B018;
    label_0009AAA1: cpu->eip = LIFT_CODE_TOKEN_VA(0x49AAA1u);
    cpu->eax = lift_load32(cpu->ebp + 0x128u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x128u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(0x40u)) goto label_0009AAC1;
    cpu->edx = lift_load32(cpu->ebp + 0x120u);
    lift_store32(cpu->ebp + ((uint32_t)(cpu->eax) * 4u) + 0x12Cu, cpu->edx);
    lift_store32(cpu->ecx, (uint64_t)(lift_load32(cpu->ecx)) + 1u);
    label_0009AAC1: cpu->eip = LIFT_CODE_TOKEN_VA(0x49AAC1u);
    cpu->eax = lift_load32(cpu->ebp + 0x22Cu);
    cpu->ebx = (uint32_t)(cpu->ebp + 0x22Cu);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(0x40u)) goto label_0009AAE1;
    cpu->edx = lift_load32(cpu->ebp + 0x120u);
    lift_store32(cpu->ebp + ((uint32_t)(cpu->eax) * 4u) + 0x230u, cpu->edx);
    lift_store32(cpu->ebx, (uint64_t)(lift_load32(cpu->ebx)) + 1u);
    label_0009AAE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x49AAE1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->ebp + 0x330u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    lift_native_call(cpu, native_function_address32(&::select), LIFT_CODE_TOKEN_VA(0x49AAF1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49AAF6u);
    cpu->ecx = lift_load32(cpu->ebp + 0x434u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(1u)) goto label_0009AB62;
    cpu->edx = lift_load32(cpu->ebp + 0x120u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::__WSAFDIsSet), LIFT_CODE_TOKEN_VA(0x49AB09u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49AB0Eu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009AB62;
    cpu->edx = (uint32_t)(cpu->ebp + 0x438u);
    cpu->eax = cpu->edx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0009AB20: cpu->eip = LIFT_CODE_TOKEN_VA(0x49AB20u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0009AB20;
    cpu->eax -= cpu->esi;
    lift_push32(cpu, 0u);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0x120u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::send), LIFT_CODE_TOKEN_VA(0x49AB35u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49AB3Au);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009B018;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_0009B018;
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->ebp + 0x434u, 2u);
    goto label_0009AFE7;
    label_0009AB62: cpu->eip = LIFT_CODE_TOKEN_VA(0x49AB62u);
    cpu->ecx = lift_load32(cpu->ebp + 0x434u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(2u)) goto label_0009AD45;
    cpu->edx = lift_load32(cpu->ebp + 0x120u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x128u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::__WSAFDIsSet), LIFT_CODE_TOKEN_VA(0x49AB7Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49AB84u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009AD45;
    cpu->ecx = lift_load32(cpu->ebp + 0x120u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x14u);
    cpu->eax = (uint32_t)(cpu->esp + 0x84u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::recv), LIFT_CODE_TOKEN_VA(0x49AB9Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49ABA4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009B018;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_0009B018;
    cpu->esi = native_function_address32(&::memmove);
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x80u);
    lift_push32(cpu, cpu->edx);
    cpu->ebx = (uint32_t)(cpu->ebp + 0x638u);
    lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x9ABCEu), LIFT_CODE_TOKEN_RVA(0x9ABCCu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49ABCEu);
    lift_push32(cpu, 4u);
    cpu->eax = (uint32_t)(cpu->esp + 0x90u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x9ABDFu), LIFT_CODE_TOKEN_RVA(0x9ABDDu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49ABDFu);
    lift_push32(cpu, 8u);
    cpu->edx = (uint32_t)(cpu->esp + 0xA0u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->esi), LIFT_CODE_TOKEN_RVA(0x9ABF0u), LIFT_CODE_TOKEN_RVA(0x9ABEEu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49ABF0u);
    cpu->esi = (uint32_t)(cpu->ebp + 0x438u);
    lift_push32(cpu, 0x5Cu); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_strrchr_address32(), LIFT_CODE_TOKEN_VA(0x49ABF9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49ABFFu);
    cpu->esp += 0x2Cu;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009AC0A;
    cpu->eax = cpu->esi;
    goto label_0009AC0B;
    label_0009AC0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49AC0Au);
    ++cpu->eax;
    label_0009AC0B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49AC0Bu);
    cpu->ecx = lift_load32((uintptr_t)"inbox\\");
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(((uint32_t)(uintptr_t)"inbox\\") + 4u)) & 0xFFFFu);
    lift_store32(cpu->esp + 0xE0u, cpu->ecx);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"inbox\\") + 6u)) & 0xFFu);
    lift_store16(cpu->esp + 0xE4u, cpu->edx & 0xFFFFu);
    lift_store8(cpu->esp + 0xE6u, cpu->ecx & 0xFFu);
    cpu->edx = cpu->eax;
    label_0009AC36: cpu->eip = LIFT_CODE_TOKEN_VA(0x49AC36u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0009AC36;
    cpu->edi = (uint32_t)(cpu->esp + 0xE0u);
    cpu->eax -= cpu->edx;
    --cpu->edi;
    label_0009AC47: cpu->eip = LIFT_CODE_TOKEN_VA(0x49AC47u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009AC47;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->esi = cpu->edx;
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->eax = 0u;
    label_0009AC61: cpu->eip = LIFT_CODE_TOKEN_VA(0x49AC61u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + cpu->eax + 0xE0u)) & 0xFFu);
    lift_store8(cpu->esp + cpu->eax + 0x4E0u, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0009AC61;
    cpu->eax = (uint32_t)(cpu->esp + 0x4E0u);
    --cpu->eax;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0009AC80: cpu->eip = LIFT_CODE_TOKEN_VA(0x49AC80u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0009AC80;
    cpu->edx = lift_load32((uintptr_t)".crc");
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)".crc") + 4u)) & 0xFFu);
    lift_store32(cpu->eax, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x4E0u);
    lift_push32(cpu, (uintptr_t)"rb"); lift_push32(cpu, cpu->edx);
    lift_store8(cpu->eax + 4u, cpu->ecx & 0xFFu);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x49ACA6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49ACACu);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0009AD24;
    cpu->edi = native_function_address32(&::fread);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, 4u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x9ACC7u), LIFT_CODE_TOKEN_RVA(0x9ACC5u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49ACC7u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, 4u); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x9ACD3u), LIFT_CODE_TOKEN_RVA(0x9ACD1u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49ACD3u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x49ACD4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49ACDAu);
    cpu->edx = lift_load32(cpu->esp + 0x48u);
    cpu->esp += 0x24u;
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_0009AD13;
    cpu->eax = lift_load32(cpu->ebx);
    if ((uint32_t)(lift_load32(cpu->esp + 0x20u)) != (uint32_t)(cpu->eax)) goto label_0009AD13;
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0xE4u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_stat64i32), LIFT_CODE_TOKEN_VA(0x49ACFCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49AD02u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009AD24;
    cpu->eax = lift_load32(cpu->esp + 0x54u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    goto label_0009AD24;
    label_0009AD13: cpu->eip = LIFT_CODE_TOKEN_VA(0x49AD13u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4E0u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x49AD1Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49AD21u);
    cpu->esp += 4u;
    label_0009AD24: cpu->eip = LIFT_CODE_TOKEN_VA(0x49AD24u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->ebp + 0x63Cu, cpu->edx);
    lift_store32(cpu->ebp + 0x434u, 3u);
    goto label_0009AFE7;
    label_0009AD45: cpu->eip = LIFT_CODE_TOKEN_VA(0x49AD45u);
    cpu->eax = lift_load32(cpu->ebp + 0x434u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(3u)) goto label_0009AE55;
    cpu->ecx = lift_load32(cpu->ebp + 0x120u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::__WSAFDIsSet), LIFT_CODE_TOKEN_VA(0x49AD5Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49AD61u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009AE55;
    cpu->eax = 0u;
    lift_push32(cpu, 4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x78u, cpu->eax);
    lift_store16(cpu->esp + 0x7Cu, cpu->eax & 0xFFFFu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x7Bu);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x7Cu, 0x415352u);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x49AD88u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49AD8Eu);
    cpu->edx = lift_load32(cpu->ebp + 0x120u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0u); lift_push32(cpu, 7u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x78u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::send), LIFT_CODE_TOKEN_VA(0x49ADA1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49ADA6u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009B018;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_0009B018;
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) != (uint32_t)(0u)) goto label_0009ADCD;
    lift_push32(cpu, (uint32_t)(uintptr_t)"w+b");
    cpu->eax = (uint32_t)(cpu->esp + 0xE4u);
    lift_push32(cpu, cpu->eax);
    goto label_0009ADDA;
    label_0009ADCD: cpu->eip = LIFT_CODE_TOKEN_VA(0x49ADCDu);
    lift_push32(cpu, (uint32_t)(uintptr_t)"a+b");
    cpu->ecx = (uint32_t)(cpu->esp + 0xE4u);
    lift_push32(cpu, cpu->ecx);
    label_0009ADDA: cpu->eip = LIFT_CODE_TOKEN_VA(0x49ADDAu);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x49ADDAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49ADE0u);
    cpu->esp += 8u;
    lift_store32(cpu->ebp + 0x640u, cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009B018;
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) != (uint32_t)(0u)) goto label_0009AE3E;
    cpu->edx = (uint32_t)(cpu->esp + 0x4E0u);
    lift_push32(cpu, (uintptr_t)"wb"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x49AE05u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49AE0Bu);
    cpu->esi = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0009AE3E;
    cpu->edi = native_function_address32(&::fwrite);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, 4u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x9AE26u), LIFT_CODE_TOKEN_RVA(0x9AE24u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49AE26u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x638u);
    lift_push32(cpu, 4u); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x9AE34u), LIFT_CODE_TOKEN_RVA(0x9AE32u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49AE34u);
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x49AE35u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49AE3Bu);
    cpu->esp += 0x24u;
    label_0009AE3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49AE3Eu);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->ebp + 0x434u, 4u);
    goto label_0009AFE7;
    label_0009AE55: cpu->eip = LIFT_CODE_TOKEN_VA(0x49AE55u);
    cpu->edx = lift_load32(cpu->ebp + 0x434u);
    if ((uint32_t)(cpu->edx) != (uint32_t)(4u)) goto label_0009AFC0;
    cpu->eax = (uint32_t)(cpu->ebp + 0x128u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0x120u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::__WSAFDIsSet), LIFT_CODE_TOKEN_VA(0x49AE72u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49AE77u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009AFC0;
    cpu->edx = lift_load32(cpu->ebp + 0x120u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1000u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x8E8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::recv), LIFT_CODE_TOKEN_VA(0x49AE95u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49AE9Au);
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0009B032;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_0009B032;
    cpu->eax = lift_load32(cpu->ebp + 0x640u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x8E8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::fwrite), LIFT_CODE_TOKEN_VA(0x49AEBFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49AEC5u);
    lift_store32(cpu->ebp + 0x63Cu, (uint64_t)(lift_load32(cpu->ebp + 0x63Cu)) + (uint64_t)(cpu->esi) + (uint64_t)(0u));
    cpu->edx = lift_load32(cpu->ebp + 0x638u);
    cpu->eax = lift_load32(cpu->ebp + 0x63Cu);
    cpu->esp += 0x10u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edx)) goto label_0009AFB6;
    cpu->ecx = (uint32_t)(cpu->esp + 0x4E0u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::remove), LIFT_CODE_TOKEN_VA(0x49AEEAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49AEF0u);
    cpu->edx = lift_load32(cpu->ebp + 0x640u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::fseek), LIFT_CODE_TOKEN_VA(0x49AEFBu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49AF01u);
    cpu->esp += 0x10u;
    cpu->edx = 0x174u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\UpdateClnt.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49AF13u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0x63Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49AF1Fu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0x640u);
    cpu->edx = lift_load32(cpu->ebp + 0x63Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->esi = cpu->eax;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::fread), LIFT_CODE_TOKEN_VA(0x49AF32u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49AF38u);
    g_sfera_crc32_runtime.current = (uint32_t)(0u);
    cpu->edx = lift_load32(cpu->ebp + 0x63Cu);
    cpu->esp += 0x14u;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49AF52u); lift_push32(cpu, r); sfera_sub_0049A920(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0x17Au;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\UpdateClnt.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49AF61u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49AF67u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_crc32_runtime.current;
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_0009B029;
    cpu->ecx = lift_load32(cpu->ebp + 0x640u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x49AF80u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49AF86u);
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    cpu->eax = lift_load32(cpu->esp + 0x40u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x34u, cpu->edx);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0xE8u);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x40u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_utime64), LIFT_CODE_TOKEN_VA(0x49AFA3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49AFA9u);
    cpu->esp += 0xCu;
    lift_store32(cpu->ebp + 0x434u, 6u);
    label_0009AFB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x49AFB6u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    goto label_0009AFE7;
    label_0009AFC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49AFC0u);
    cpu->eax = lift_load32(cpu->ebp + 0x434u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(6u)) goto label_0009AFDC;
    cpu->ecx = lift_load32(cpu->ebp + 0x120u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::__WSAFDIsSet), LIFT_CODE_TOKEN_VA(0x49AFD3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49AFD8u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009B053;
    label_0009AFDC: cpu->eip = LIFT_CODE_TOKEN_VA(0x49AFDCu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebp)) & 0xFFu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0009B07D;
    label_0009AFE7: cpu->eip = LIFT_CODE_TOKEN_VA(0x49AFE7u);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::_time64), LIFT_CODE_TOKEN_VA(0x49AFECu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49AFF2u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_x87_push(cpu, ::_difftime64(static_cast<__time64_t>(lift_load64(cpu->esp)), static_cast<__time64_t>(lift_load64(cpu->esp + 8u))));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), 15.0);
    lift_x87_pop(cpu);
    cpu->esp += 0x14u;
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0009AAA1;
    label_0009B018: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B018u);
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x49B018u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B01Du);
    lift_store32(cpu->ebp + 0x434u, 5u);
    goto label_0009B082;
    label_0009B029: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B029u);
    cpu->eax = lift_load32(cpu->ebp + 0x640u);
    lift_push32(cpu, cpu->eax);
    goto label_0009B039;
    label_0009B032: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B032u);
    cpu->ecx = lift_load32(cpu->ebp + 0x640u);
    lift_push32(cpu, cpu->ecx);
    label_0009B039: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B039u);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x49B039u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B03Fu);
    cpu->esp += 4u;
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x49B042u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B047u);
    lift_store32(cpu->ebp + 0x434u, 5u);
    goto label_0009B082;
    label_0009B053: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B053u);
    cpu->edx = lift_load32(cpu->ebp + 0x120u);
    lift_push32(cpu, 0u); lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"DA"); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::send), LIFT_CODE_TOKEN_VA(0x49B063u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B068u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009B018;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_0009B018;
    lift_store32(cpu->ebp + 0x434u, 0u);
    goto label_0009B082;
    label_0009B07D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B07Du);
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x49B07Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B082u);
    label_0009B082: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B082u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store8(cpu->ebp + 1u, 1u);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esp += 0x18D4u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049B0B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49B0B0u);
    cpu->esp -= 0x198u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + 1u)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0009B0EB;
    cpu->eax = 3u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x198u;
    lift_return(cpu, 4u, stop_address); return;
    label_0009B0EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B0EBu);
    cpu->ecx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x202u);
    lift_native_call(cpu, native_function_address32(&::WSAStartup), LIFT_CODE_TOKEN_VA(0x49B0F5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B0FAu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_0009B11C;
    cpu->eax = 4u;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x198u;
    lift_return(cpu, 4u, stop_address); return;
    label_0009B11C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B11Cu);
    cpu->edx = (int8_t)(lift_load8(cpu->esi + 0x10u));
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::isalpha), LIFT_CODE_TOKEN_VA(0x49B126u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B12Cu);
    cpu->esp += 4u;
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009B13B;
    lift_native_call(cpu, native_function_address32(&::gethostbyname), LIFT_CODE_TOKEN_VA(0x49B134u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B139u);
    goto label_0009B152;
    label_0009B13B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B13Bu);
    lift_native_call(cpu, native_function_address32(&::inet_addr), LIFT_CODE_TOKEN_VA(0x49B13Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B140u);
    lift_push32(cpu, 2u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_push32(cpu, 4u);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::gethostbyaddr), LIFT_CODE_TOKEN_VA(0x49B14Du)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B152u);
    label_0009B152: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B152u);
    cpu->ebp = cpu->eax;
    if ((uint32_t)(cpu->ebp) != 0u) goto label_0009B165;
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x49B158u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B15Du);
    cpu->eax = (uint32_t)(cpu->ebp + 5u);
    goto label_0009B28E;
    label_0009B165: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B165u);
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x110u, cpu->eax);
    cpu->edi = (uint32_t)(cpu->esi + 0x110u);
    lift_store32(cpu->edi + 4u, cpu->eax);
    lift_store32(cpu->edi + 8u, cpu->eax);
    lift_store32(cpu->edi + 0xCu, cpu->eax);
    cpu->ecx = (int16_t)(lift_load16(cpu->ebp + 0xAu));
    cpu->edx = lift_load32(cpu->ebp + 0xCu);
    cpu->eax = lift_load32(cpu->edx);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esi + 0x114u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x49B18Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B193u);
    cpu->eax = lift_load16(cpu->esi + 0xCu);
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->ebp + 8u)) & 0xFFFFu);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->eax);
    lift_store16(cpu->edi, cpu->edx & 0xFFFFu);
    lift_native_call(cpu, native_function_address32(&::htons), LIFT_CODE_TOKEN_VA(0x49B1A2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B1A7u);
    lift_push32(cpu, 0u); lift_push32(cpu, 1u); lift_push32(cpu, 2u);
    lift_store16(cpu->esi + 0x112u, cpu->eax & 0xFFFFu);
    lift_native_call(cpu, native_function_address32(&::socket), LIFT_CODE_TOKEN_VA(0x49B1B4u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B1B9u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x124u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0x8004667Eu); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esi + 0x120u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::ioctlsocket), LIFT_CODE_TOKEN_VA(0x49B1CCu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B1D1u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_0009B1E5;
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x49B1D6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B1DBu);
    cpu->eax = 4u;
    goto label_0009B28E;
    label_0009B1E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B1E5u);
    cpu->edx = lift_load32(cpu->esi + 0x120u);
    lift_push32(cpu, 0x10u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::connect), LIFT_CODE_TOKEN_VA(0x49B1EFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B1F4u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(0xFFFFFFFFu)) goto label_0009B211;
    lift_native_call(cpu, native_function_address32(&::WSAGetLastError), LIFT_CODE_TOKEN_VA(0x49B1F9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B1FEu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0x2733u)) goto label_0009B211;
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x49B205u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B20Au);
    cpu->eax = 6u;
    goto label_0009B28E;
    label_0009B211: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B211u);
    cpu->eax = (uint32_t)(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi); lift_push32(cpu, LIFT_CALLBACK(sfera_sub_0049AA10)); lift_push32(cpu, 0u);
    lift_store8(cpu->esi, 0u);
    lift_push32(cpu, 0u);
    lift_store8(cpu->esi + 1u, 0u);
    lift_native_call(cpu, native_function_address32(&::CreateThread), LIFT_CODE_TOKEN_VA(0x49B228u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B22Eu);
    lift_store32(cpu->esi + 4u, cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009B241;
    lift_native_call(cpu, native_function_address32(&::WSACleanup), LIFT_CODE_TOKEN_VA(0x49B235u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B23Au);
    cpu->eax = 2u;
    goto label_0009B28E;
    label_0009B241: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B241u);
    cpu->eax = lift_load32(cpu->esp + 0x1A8u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax)), r=(uint64_t)(0x5Cu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->edx = (uint32_t)(cpu->esi + 0x438u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009B262;
    ++cpu->eax;
    cpu->edx -= cpu->eax;
    label_0009B256: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B256u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0009B256;
    goto label_0009B26E;
    label_0009B262: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B262u);
    cpu->edx -= cpu->eax;
    label_0009B264: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B264u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0009B264;
    label_0009B26E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B26Eu);
    lift_store32(cpu->esi + 0x434u, 1u);
    lift_store32(cpu->esi + 0x638u, 0u);
    lift_store32(cpu->esi + 0x63Cu, 0u);
    cpu->eax = 0u;
    label_0009B28E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B28Eu);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x198u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049B2B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49B2B0u);
    { uint64_t l=cpu->esp, r=(uint64_t)(0x14u), v=l - r; lift_flags_sub(cpu,l,r,0u,v,32u); cpu->esp= v; }
    cpu->eax = 0x6E726157u;
    cpu->edx = 0x6C2E3030u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 8u, cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x676F)) & 0xFFFFu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->ecx = 0x73676E69u;
    lift_store16(cpu->esp + 0x18u, cpu->eax & 0xFFFFu);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    lift_store8(cpu->esp + 0x1Au, cpu->ecx & 0xFFu);
    cpu->ecx = g_sfera_recovered_static_runtime.server_number;
    cpu->eax = 0x66666667u;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->esi = lift_load32(cpu->esp + 0x24u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->edx = (uint32_t)(cpu->eax + 0x30u);
    lift_store8(cpu->esp + 0x14u, cpu->edx & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((cpu->eax & 0xFFu)) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) - (uint64_t)((cpu->eax & 0xFFu)) - (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    lift_push32(cpu, (uintptr_t)"at"); lift_push32(cpu, cpu->eax);
    lift_store8(cpu->esp + 0x1Du, cpu->ecx & 0xFFu);
    lift_native_call(cpu, native_function_address32(&::fopen), LIFT_CODE_TOKEN_VA(0x49B334u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B33Au);
    cpu->ebx = cpu->eax;
    cpu->esp += 8u;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0009B45C;
    if ((uint32_t)(cpu->esi) < (uint32_t)(0xAu)) goto label_0009B358;
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9B358u); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    label_0009B358: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B358u);
    cpu->ecx = cpu->esi;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x850u);
    cpu->edi += cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->edi + 0x448u)) != (uint32_t)(1u)) goto label_0009B3C4;
    if ((uint32_t)(cpu->esi) < (uint32_t)(0xAu)) goto label_0009B3A0;
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49B37Cu); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49B388u); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49B394u); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9B3A0u); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    label_0009B3A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B3A0u);
    cpu->edx = (uint32_t)(cpu->edi + 0x44Cu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->edi + 0x48u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->edi + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"%s %s\n%s\n%s\n\n"); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x49B3B9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B3BFu);
    cpu->esp += 0x18u;
    goto label_0009B42E;
    label_0009B3C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B3C4u);
    if ((uint32_t)(cpu->esi) < (uint32_t)(0xAu)) goto label_0009B405;
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49B3D5u); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49B3E1u); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49B3EDu); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49B3F9u); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9B405u); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    label_0009B405: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B405u);
    cpu->edx = lift_load32(cpu->edi + 0x448u);
    cpu->eax = (uint32_t)(cpu->edi + 0x44Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0x48u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->edi + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 8u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%s %s\n(%d) %s\n%s\n\n"); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fprintf), LIFT_CODE_TOKEN_VA(0x49B425u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B42Bu);
    cpu->esp += 0x1Cu;
    label_0009B42E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B42Eu);
    if ((uint32_t)(cpu->esi) < (uint32_t)(0xAu)) goto label_0009B43F;
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9B43Fu); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    label_0009B43F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B43Fu);
    if ((uint32_t)(lift_load32(cpu->edi + 0x84Cu)) != (uint32_t)(1u)) goto label_0009B452;
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fflush), LIFT_CODE_TOKEN_VA(0x49B449u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B44Fu);
    cpu->esp += 4u;
    label_0009B452: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B452u);
    lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::fclose), LIFT_CODE_TOKEN_VA(0x49B453u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B459u);
    cpu->esp += 4u;
    label_0009B45C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B45Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049B470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49B470u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xAu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_0009B47C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B47Cu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0009B48A;
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9B48Au); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    label_0009B48A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B48Au);
    cpu->eax = lift_load32(cpu->edi);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->edi + 4u)), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009B4B7;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49B499u); lift_push32(cpu, r); sfera_sub_0049B2B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) < (uint32_t)(0xAu)) goto label_0009B4AA;
    cpu->edx = cpu->esi;
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9B4AAu); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    label_0009B4AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B4AAu);
    lift_store32(cpu->edi, 0u);
    lift_store32(cpu->edi + 4u, 0u);
    label_0009B4B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B4B7u);
    ++cpu->esi;
    cpu->edi += 0x850u;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(0xAu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0009B47C;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049B4D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49B4D0u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = native_function_address32(&::_stricmp);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebp = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(0xAu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_0009B4E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B4E6u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0009B4F4;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9B4F4u); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    label_0009B4F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B4F4u);
    cpu->eax = lift_load32(cpu->edi);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->edi + 4u)), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009B51E;
    if ((uint32_t)(cpu->ebp) < (uint32_t)(0xAu)) goto label_0009B50C;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9B50Cu); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    label_0009B50C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B50Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->eax = (uint32_t)(cpu->edi + 0x48u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x9B517u), LIFT_CODE_TOKEN_RVA(0x9B515u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49B517u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009B52C;
    label_0009B51E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B51Eu);
    ++cpu->ebp;
    cpu->edi += 0x850u;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(0xAu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0009B4E6;
    goto label_0009B572;
    label_0009B52C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B52Cu);
    if ((uint32_t)(cpu->ebp) < (uint32_t)(0xAu)) goto label_0009B53D;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9B53Du); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    label_0009B53D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B53Du);
    cpu->edi = cpu->ebp;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x850u);
    lift_store32(cpu->edi + cpu->esi + 0x448u, (uint64_t)(lift_load32(cpu->edi + cpu->esi + 0x448u)) + 1u);
    cpu->edi += cpu->esi;
    if ((uint32_t)(cpu->ebp) < (uint32_t)(0xAu)) goto label_0009B55F;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9B55Fu); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    label_0009B55F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B55Fu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49B564u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi, cpu->eax);
    lift_store32(cpu->edi + 4u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(0xAu)) goto label_0009B779;
    label_0009B572: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B572u);
    cpu->edi = 0u;
    cpu->ebx = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0xAu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_0009B579: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B579u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0009B587;
    cpu->edx = cpu->edi;
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9B587u); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    label_0009B587: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B587u);
    cpu->eax = lift_load32(cpu->ebx);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->ebx + 4u)), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009B59A;
    ++cpu->edi;
    cpu->ebx += 0x850u;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0xAu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0009B579;
    label_0009B59A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B59Au);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(0xAu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009B5C5;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49B5A8u); lift_push32(cpu, r); sfera_sub_0049B2B0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x4AD0u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x850u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x49B5B5u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B5BBu);
    cpu->esp += 0xCu;
    cpu->ebp = 9u;
    goto label_0009B5D3;
    label_0009B5C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B5C5u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0009B5D3;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9B5D3u); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    label_0009B5D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B5D3u);
    cpu->ebx = cpu->ebp;
    cpu->ebx = (int64_t)(int32_t)(cpu->ebx) * (int64_t)(int32_t)(0x850u);
    cpu->ebx += cpu->esi;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49B5E6u); lift_push32(cpu, r); sfera_sub_0049A670(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 1u;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edx = (uint64_t)(cpu->edx) + (uint64_t)(0u) + (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_store32(cpu->ebx, cpu->eax);
    lift_store32(cpu->ebx + 4u, cpu->edx);
    if ((uint32_t)(cpu->ebp) < (uint32_t)(0xAu)) goto label_0009B604;
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(cpu->edi + 9u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9B604u); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    label_0009B604: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B604u);
    lift_store32(cpu->ebx + 0x448u, cpu->edi);
    if ((uint32_t)(cpu->ebp) < (uint32_t)(0xAu)) goto label_0009B61B;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9B61Bu); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    label_0009B61B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B61Bu);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->ebx + 0x84Cu, cpu->eax);
    if ((uint32_t)(cpu->ebp) < (uint32_t)(0xAu)) goto label_0009B636;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9B636u); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    label_0009B636: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B636u);
    cpu->esi = lift_load32(cpu->esp + 0x24u);
    cpu->eax = cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    (void)cpu;
    label_0009B640: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B640u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0009B640;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x400u)) goto label_0009B68A;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, (uintptr_t)"SSTR::operator=: buffer overflow! - %s"); lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x20u, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\sstr.h");
    lift_store32(cpu->esp + 0x24u, 0x6Du);
    lift_store32(cpu->esp + 0x28u, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49B674u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0xFFu;
    cpu->edi = (uint32_t)(cpu->ebx + 0x48u);
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    lift_movs8(cpu, 0u);
    lift_store8(cpu->ebx + 0x447u, 0u);
    goto label_0009B696;
    label_0009B68A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B68Au);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->ebx + 0x48u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x49B691u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B696u);
    label_0009B696: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B696u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->ebp) < (uint32_t)(0xAu)) goto label_0009B6AA;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9B6AAu); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    label_0009B6AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B6AAu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    cpu->ebx += 0x44Cu;
    lift_store8(cpu->ebx, cpu->edx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49B6BDu); lift_push32(cpu, r); sfera_sub_00434D90(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_0009B739;
    if ((uint32_t)(cpu->ebp) < (uint32_t)(0xAu)) goto label_0009B6D4;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9B6D4u); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    label_0009B6D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B6D4u);
    cpu->eax = cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0009B6E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B6E0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0009B6E0;
    cpu->eax -= cpu->edx;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x400u)) goto label_0009B72D;
    lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, (uintptr_t)"SSTR::operator=: buffer overflow! - %s"); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x20u, (uintptr_t)"h:\\work\\sphere\\sphere1_main_update\\~src\\spheresources\\service\\containers\\sstr.h");
    lift_store32(cpu->esp + 0x24u, 0x6Du);
    lift_store32(cpu->esp + 0x28u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49B718u); lift_push32(cpu, r); sfera_sub_004EC2E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0xFFu;
    cpu->edi = cpu->ebx;
    lift_movs32(cpu, 1u);
    lift_movs16(cpu, 0u);
    lift_movs8(cpu, 0u);
    lift_store8(cpu->ebx + 0x3FFu, 0u);
    goto label_0009B736;
    label_0009B72D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B72Du);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x49B731u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B736u);
    label_0009B736: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B736u);
    cpu->esp += 0xCu;
    label_0009B739: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B739u);
    if ((uint32_t)(cpu->ebp) < (uint32_t)(0xAu)) goto label_0009B74A;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9B74Au); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    label_0009B74A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B74Au);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = (uint32_t)(cpu->esi + 8u);
    cpu->edx = 0x20u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49B75Bu); lift_push32(cpu, r); sfera_sub_0044BFE0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->ebp) < (uint32_t)(0xAu)) goto label_0009B76C;
    cpu->edx = cpu->ebp;
    cpu->ecx = 0xAu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9B76Cu); lift_push32(cpu, r); sfera_sub_004ED5E0(cpu,r); if (cpu->eip != r) return; }
    label_0009B76C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B76Cu);
    cpu->esi += 0x28u;
    lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::_strtime), LIFT_CODE_TOKEN_VA(0x49B770u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B776u);
    cpu->esp += 4u;
    label_0009B779: cpu->eip = LIFT_CODE_TOKEN_VA(0x49B779u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049B790(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49B790u);
    cpu->esp -= 0x404u;
    cpu->ecx = lift_load32(cpu->esp + 0x40Cu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x40Cu);
    cpu->eax = (uint32_t)(cpu->esp + 0x414u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::vsprintf), LIFT_CODE_TOKEN_VA(0x49B7C1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B7C7u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49B7D8u); lift_push32(cpu, r); sfera_sub_0049B4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049B7F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49B7F0u);
    cpu->esp -= 0x404u;
    cpu->ecx = lift_load32(cpu->esp + 0x40Cu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x40Cu);
    cpu->eax = (uint32_t)(cpu->esp + 0x414u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::vsprintf), LIFT_CODE_TOKEN_VA(0x49B821u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49B827u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 1u);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49B838u); lift_push32(cpu, r); sfera_sub_0049B4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49B83Fu); lift_push32(cpu, r); sfera_sub_0049B470(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x404u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049B860(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49B860u);
    cpu->eax = cpu->ecx;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ecx & 0xFFu)) ^ (uint64_t)((cpu->ecx & 0xFFu)))) & 0xFFu);
    lift_store8(cpu->eax + 8u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x28u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x48u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x44Cu, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x858u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x878u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x898u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0xC9Cu, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x10A8u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x10C8u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x10E8u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x14ECu, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x18F8u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x1918u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x1938u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x1D3Cu, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x2148u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x2168u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x2188u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x258Cu, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x2998u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x29B8u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x29D8u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x2DDCu, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x31E8u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x3208u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x3228u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x362Cu, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x3A38u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x3A58u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x3A78u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x3E7Cu, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x4288u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x42A8u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x42C8u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x46CCu, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x4AD8u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x4AF8u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x4B18u, cpu->ecx & 0xFFu);
    lift_store8(cpu->eax + 0x4F1Cu, cpu->ecx & 0xFFu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049BA10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49BA10u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    cpu->ecx = 7u;
    cpu->esi = (uint32_t)(uintptr_t)"wrong format of weather.txt\n";
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_weather_runtime.parse_error[0];
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->ebx;
    lift_movs8(cpu, 0u);
    cpu->eax = cpu->edx;
    cpu->esi = cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0009BA30: cpu->eip = LIFT_CODE_TOKEN_VA(0x49BA30u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != 0u) goto label_0009BA30;
    cpu->ecx -= cpu->esi;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_weather_runtime.parse_error[0];
    cpu->ebx = cpu->ecx;
    --cpu->edi;
    label_0009BA41: cpu->eip = LIFT_CODE_TOKEN_VA(0x49BA41u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009BA41;
    cpu->ecx = cpu->ebx;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->ebx;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_weather_runtime.parse_error[0];
    --cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0009BA60: cpu->eip = LIFT_CODE_TOKEN_VA(0x49BA60u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx + 1u)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != 0u) goto label_0009BA60;
    cpu->edx = (cpu->edx & 0xFFFF0000u) | ((uint32_t)(UINT16_C(0x202C)) & 0xFFFFu);
    lift_store16(cpu->ecx, cpu->edx & 0xFFFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(UINT8_C(0x00)) & 0xFFu);
    lift_store8(cpu->ecx + 2u, cpu->edx & 0xFFu);
    cpu->ecx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0009BA80: cpu->eip = LIFT_CODE_TOKEN_VA(0x49BA80u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0009BA80;
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_weather_runtime.parse_error[0];
    cpu->eax -= cpu->ecx;
    cpu->esi = cpu->ecx;
    --cpu->edi;
    label_0009BA91: cpu->eip = LIFT_CODE_TOKEN_VA(0x49BA91u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edi + 1u)) & 0xFFu);
    ++cpu->edi;
    { uint64_t v=(uint64_t)((cpu->ecx & 0xFFu)); lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009BA91;
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    lift_movs32(cpu, 1u);
    cpu->ecx = cpu->eax;
    cpu->ecx &= 3u;
    lift_movs8(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_weather_runtime.parse_error[0];
    cpu->ebx = lift_pop32(cpu);
    sfera_sub_00459B10(cpu, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049BAC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49BAC0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x3Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = lift_load32(cpu->esp + 0x60u);
    lift_push32(cpu, 0x7E80u);
    cpu->ebx = 0u;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x49BB01u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49BB06u);
    cpu->esp += 0xCu;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49BB12u); lift_push32(cpu, r); sfera_sub_00480380(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x5Cu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49BB20u); lift_push32(cpu, r); sfera_sub_004803B0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32((uintptr_t)"s00_0");
    cpu->ecx = (cpu->ecx & 0xFFFF0000u) | ((uint32_t)(lift_load16(((uint32_t)(uintptr_t)"s00_0") + 4u)) & 0xFFFFu);
    cpu->edx = lift_load32((uintptr_t)"t00c");
    lift_store32(cpu->esp + 0x34u, cpu->eax);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"t00c") + 4u)) & 0xFFu);
    lift_store16(cpu->esp + 0x38u, cpu->ecx & 0xFFFFu);
    cpu->ecx = lift_load32((uintptr_t)"q000");
    lift_push32(cpu, 2u);
    lift_store8(cpu->esp + 0x44u, cpu->eax & 0xFFu);
    cpu->eax = (uint32_t)(cpu->esi + 0x18E0u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x4Cu, cpu->ecx);
    lift_push32(cpu, (uint32_t)(uintptr_t)"stime");
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x48u, cpu->edx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(((uint32_t)(uintptr_t)"q000") + 4u)) & 0xFFu);
    lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x2Cu, 0x303073u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x28u, 0x303074u);
    lift_store32(cpu->esp + 0x3Cu, 0x303072u);
    lift_store32(cpu->esp + 0x38u, 0x303067u);
    lift_store32(cpu->esp + 0x40u, 0x303062u);
    lift_store8(cpu->esp + 0x58u, cpu->edx & 0xFFu);
    lift_store32(cpu->esp + 0x30u, 0x303063u);
    lift_store32(cpu->esi + 0x7CE0u, cpu->ebx);
    lift_store16(cpu->esp + 0x45u, 0x3030u);
    lift_store16(cpu->esp + 0x2Du, 0x3030u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49BBBCu); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0x7CE0u);
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->edi = (uint32_t)(cpu->edx + cpu->esi + 0x18E0u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ebp = 0x32u;
    lift_divide_accumulator(cpu, cpu->ebp, 32u, 1u);
    cpu->eax = sfera_texture_time_key_digit(cpu->edx);
    lift_store32(cpu->edi, (uint64_t)(lift_load32(cpu->edi)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0009BF51;
    label_0009BBE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x49BBE9u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009BBFC;
    cpu->edx = (uint32_t)(uintptr_t)"stime";
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9BBFCu); lift_push32(cpu, r); sfera_sub_0049BA10(cpu,r); if (cpu->eip != r) return; }
    label_0009BBFC: cpu->eip = LIFT_CODE_TOKEN_VA(0x49BBFCu);
    cpu->ecx = lift_load32(cpu->esi + 0x7CE0u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    lift_push32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->esi + 0x18E4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"nsky1");
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49BC22u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009BC35;
    cpu->edx = (uint32_t)(uintptr_t)"nsky1";
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9BC35u); lift_push32(cpu, r); sfera_sub_0049BA10(cpu,r); if (cpu->eip != r) return; }
    label_0009BC35: cpu->eip = LIFT_CODE_TOKEN_VA(0x49BC35u);
    cpu->ecx = lift_load32(cpu->esi + 0x7CE0u);
    cpu->edi = native_function_address32(&::_stricmp);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->esi + 0x18E4u);
    lift_push32(cpu, (uintptr_t)"none"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x9BC53u), LIFT_CODE_TOKEN_RVA(0x9BC51u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49BC53u);
    cpu->esp += 8u;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009BC6B;
    cpu->eax = lift_load32(cpu->esi + 0x7CE0u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    lift_store8(cpu->eax + cpu->esi + 0x18E4u, 0u);
    label_0009BC6B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49BC6Bu);
    cpu->ecx = lift_load32(cpu->esi + 0x7CE0u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    lift_push32(cpu, 1u);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->esi + 0x18F8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"nsky2");
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49BC91u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009BCA4;
    cpu->edx = (uint32_t)(uintptr_t)"nsky2";
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9BCA4u); lift_push32(cpu, r); sfera_sub_0049BA10(cpu,r); if (cpu->eip != r) return; }
    label_0009BCA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x49BCA4u);
    cpu->ecx = lift_load32(cpu->esi + 0x7CE0u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->esi + 0x18F8u);
    lift_push32(cpu, (uintptr_t)"none"); lift_push32(cpu, cpu->edx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x9BCBCu), LIFT_CODE_TOKEN_RVA(0x9BCBAu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49BCBCu);
    cpu->esp += 8u;
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009BCD4;
    cpu->eax = lift_load32(cpu->esi + 0x7CE0u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    lift_store8(cpu->eax + cpu->esi + 0x18F8u, 0u);
    label_0009BCD4: cpu->eip = LIFT_CODE_TOKEN_VA(0x49BCD4u);
    cpu->ecx = lift_load32(cpu->esi + 0x7CE0u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->esi + 0x190Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"tsky1");
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49BCFAu); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009BD0D;
    cpu->edx = (uint32_t)(uintptr_t)"tsky1";
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9BD0Du); lift_push32(cpu, r); sfera_sub_0049BA10(cpu,r); if (cpu->eip != r) return; }
    label_0009BD0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49BD0Du);
    cpu->ecx = lift_load32(cpu->esi + 0x7CE0u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->esi + 0x1910u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"tsky2");
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49BD33u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_0009BD46;
    cpu->edx = (uint32_t)(uintptr_t)"tsky2";
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9BD46u); lift_push32(cpu, r); sfera_sub_0049BA10(cpu,r); if (cpu->eip != r) return; }
    label_0009BD46: cpu->eip = LIFT_CODE_TOKEN_VA(0x49BD46u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"t");
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store8(cpu->esp + 0x48u, 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49BD66u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009BED9;
    cpu->edi = 0u;
    label_0009BD70: cpu->eip = LIFT_CODE_TOKEN_VA(0x49BD70u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009BD83;
    cpu->edx = (uint32_t)(uintptr_t)"t";
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9BD83u); lift_push32(cpu, r); sfera_sub_0049BA10(cpu,r); if (cpu->eip != r) return; }
    label_0009BD83: cpu->eip = LIFT_CODE_TOKEN_VA(0x49BD83u);
    cpu->ebp = lift_load32(cpu->esi + 0x7CE0u);
    cpu->ebp = lift_shift_left(cpu, cpu->ebp, (uint32_t)(8u), 32u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esi + cpu->ebp + 0x18E0u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (0.009999999776482582));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x24u))));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49BDA2u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->edi + cpu->esi);
    lift_store32(cpu->ecx + cpu->ebp + 0x1918u, cpu->eax);
    cpu->edx = lift_load32(cpu->esi + 0x7CE0u);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    lift_push32(cpu, 0u);
    cpu->edx += cpu->edi;
    cpu->eax = (uint32_t)(cpu->edx + cpu->esi + 0x191Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"r");
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49BDD4u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009BDE7;
    cpu->edx = (uint32_t)(uintptr_t)"r";
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9BDE7u); lift_push32(cpu, r); sfera_sub_0049BA10(cpu,r); if (cpu->eip != r) return; }
    label_0009BDE7: cpu->eip = LIFT_CODE_TOKEN_VA(0x49BDE7u);
    cpu->edx = lift_load32(cpu->esi + 0x7CE0u);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    lift_push32(cpu, 0u);
    cpu->edx += cpu->edi;
    cpu->eax = (uint32_t)(cpu->edx + cpu->esi + 0x1920u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"fl1");
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49BE0Fu); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009BE22;
    cpu->edx = (uint32_t)(uintptr_t)"fl1";
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9BE22u); lift_push32(cpu, r); sfera_sub_0049BA10(cpu,r); if (cpu->eip != r) return; }
    label_0009BE22: cpu->eip = LIFT_CODE_TOKEN_VA(0x49BE22u);
    cpu->edx = lift_load32(cpu->esi + 0x7CE0u);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    lift_push32(cpu, 0u);
    cpu->edx += cpu->edi;
    cpu->eax = (uint32_t)(cpu->edx + cpu->esi + 0x1924u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"fl2");
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49BE4Au); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009BE5D;
    cpu->edx = (uint32_t)(uintptr_t)"fl2";
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9BE5Du); lift_push32(cpu, r); sfera_sub_0049BA10(cpu,r); if (cpu->eip != r) return; }
    label_0009BE5D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49BE5Du);
    cpu->edx = lift_load32(cpu->esi + 0x7CE0u);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    lift_push32(cpu, 0u);
    cpu->edx += cpu->edi;
    cpu->eax = (uint32_t)(cpu->edx + cpu->esi + 0x1928u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"cs");
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49BE85u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009BE98;
    cpu->edx = (uint32_t)(uintptr_t)"cs";
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9BE98u); lift_push32(cpu, r); sfera_sub_0049BA10(cpu,r); if (cpu->eip != r) return; }
    label_0009BE98: cpu->eip = LIFT_CODE_TOKEN_VA(0x49BE98u);
    cpu->edx = lift_load32(cpu->esi + 0x7CE0u);
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->ebx + 1u);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->edx + cpu->esi + 0x1914u, cpu->eax);
    cpu->ebx = cpu->eax;
    lift_push32(cpu, (uint32_t)(uintptr_t)"t");
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    cpu->eax = (uint32_t)(cpu->ebx + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    cpu->edi += 0x14u;
    lift_store8(cpu->esp + 0x48u, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49BED1u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009BD70;
    label_0009BED9: cpu->eip = LIFT_CODE_TOKEN_VA(0x49BED9u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x7CE0u)), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esi + 0x7CE0u, v); }
    cpu->ecx = lift_load32(cpu->esi + 0x7CE0u);
    cpu->eax = cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edi = 0xAu;
    lift_divide_accumulator(cpu, cpu->edi, 32u, 1u);
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    lift_push32(cpu, 2u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    lift_store8(cpu->esp + 0x39u, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x21u, cpu->eax & 0xFFu);
    cpu->eax = (uint32_t)(cpu->ecx + cpu->esi + 0x18E0u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"stime");
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store8(cpu->esp + 0x46u, cpu->edx & 0xFFu);
    lift_store8(cpu->esp + 0x2Eu, cpu->edx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49BF24u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->esi + 0x7CE0u);
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->edi = (uint32_t)(cpu->edx + cpu->esi + 0x18E0u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ebx = 0x32u;
    lift_divide_accumulator(cpu, cpu->ebx, 32u, 1u);
    cpu->eax = sfera_texture_time_key_digit(cpu->edx);
    lift_store32(cpu->edi, (uint64_t)(lift_load32(cpu->edi)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    if ((uint32_t)(cpu->ecx) != 0u) goto label_0009BBE9;
    label_0009BF51: cpu->eip = LIFT_CODE_TOKEN_VA(0x49BF51u);
    cpu->ebp = 1u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"ntex");
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esi + 0x1428u, 0u);
    lift_store16(cpu->esp + 0x4Du, 0x3030u);
    lift_store16(cpu->esp + 0x29u, 0x3030u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49BF83u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009C201;
    label_0009BF8B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49BF8Bu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_0009BF9D;
    cpu->edx = (uint32_t)(uintptr_t)"ntex";
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9BF9Du); lift_push32(cpu, r); sfera_sub_0049BA10(cpu,r); if (cpu->eip != r) return; }
    label_0009BF9D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49BF9Du);
    cpu->edx = lift_load32(cpu->esi + 0x1428u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xACu);
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->edx + cpu->esi + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"sc1");
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49BFC3u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_0009BFD5;
    cpu->edx = (uint32_t)(uintptr_t)"sc1";
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9BFD5u); lift_push32(cpu, r); sfera_sub_0049BA10(cpu,r); if (cpu->eip != r) return; }
    label_0009BFD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x49BFD5u);
    cpu->edx = lift_load32(cpu->esi + 0x1428u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xACu);
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->edx + cpu->esi + 0x18u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"sc2");
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49BFFBu); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_0009C00D;
    cpu->edx = (uint32_t)(uintptr_t)"sc2";
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9C00Du); lift_push32(cpu, r); sfera_sub_0049BA10(cpu,r); if (cpu->eip != r) return; }
    label_0009C00D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C00Du);
    cpu->edx = lift_load32(cpu->esi + 0x1428u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xACu);
    lift_push32(cpu, 2u);
    cpu->eax = (uint32_t)(cpu->edx + cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"scrll");
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49C033u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_0009C045;
    cpu->edx = (uint32_t)(uintptr_t)"scrll";
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9C045u); lift_push32(cpu, r); sfera_sub_0049BA10(cpu,r); if (cpu->eip != r) return; }
    label_0009C045: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C045u);
    cpu->edx = lift_load32(cpu->esi + 0x1428u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xACu);
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->edx + cpu->esi + 0x20u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"time1");
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49C06Bu); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_0009C07D;
    cpu->edx = (uint32_t)(uintptr_t)"time1";
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9C07Du); lift_push32(cpu, r); sfera_sub_0049BA10(cpu,r); if (cpu->eip != r) return; }
    label_0009C07D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C07Du);
    cpu->edx = lift_load32(cpu->esi + 0x1428u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xACu);
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->edx + cpu->esi + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"time2");
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49C0A3u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_0009C0B5;
    cpu->edx = (uint32_t)(uintptr_t)"time2";
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9C0B5u); lift_push32(cpu, r); sfera_sub_0049BA10(cpu,r); if (cpu->eip != r) return; }
    label_0009C0B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C0B5u);
    cpu->ebx = 0u;
    lift_flags_logic(cpu,0u,32u); cpu->edi = 0u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0009C0C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C0C0u);
    cpu->ecx = lift_load32(cpu->esi + 0x1428u);
    cpu->eax = 0xCCCCCCCDu;
    { int64_t v=(int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xACu); cpu->ecx= v; uint32_t ov=((int64_t)(int32_t)v != v); cpu->eflags=(cpu->eflags & ~(LIFT_FLAG_CF | LIFT_FLAG_OF)) | (ov ? LIFT_FLAG_CF | LIFT_FLAG_OF : 0u); }
    lift_multiply_accumulator(cpu, cpu->ebx, 32u, 0u);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(3u), 32u);
    cpu->eax = (uint32_t)(cpu->edx + 0x30u);
    lift_store8(cpu->esp + 0x31u, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x29u, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x2Du, cpu->eax & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((cpu->edx & 0xFFu)) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((cpu->ebx & 0xFFu)) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) - (uint64_t)((cpu->edx & 0xFFu)) - (uint64_t)(0u))) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    cpu->ecx += cpu->edi;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->ecx + cpu->esi + 0x28u);
    lift_store8(cpu->esp + 0x36u, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x2Eu, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x32u, cpu->eax & 0xFFu);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49C11Du); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_0009C12E;
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9C12Eu); lift_push32(cpu, r); sfera_sub_0049BA10(cpu,r); if (cpu->eip != r) return; }
    label_0009C12E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C12Eu);
    cpu->edx = lift_load32(cpu->esi + 0x1428u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(0xACu);
    cpu->edx += cpu->edi;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->edx + cpu->esi + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49C156u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_0009C167;
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9C167u); lift_push32(cpu, r); sfera_sub_0049BA10(cpu,r); if (cpu->eip != r) return; }
    label_0009C167: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C167u);
    cpu->eax = lift_load32(cpu->esi + 0x1428u);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0xACu);
    cpu->eax += cpu->edi;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->esi + 0x30u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49C18Fu); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_0009C1A0;
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9C1A0u); lift_push32(cpu, r); sfera_sub_0049BA10(cpu,r); if (cpu->eip != r) return; }
    label_0009C1A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C1A0u);
    cpu->edi += 0xCu;
    cpu->ebx += cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(0x84u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0009C0C0;
    lift_store32(cpu->esi + 0x1428u, (uint64_t)(lift_load32(cpu->esi + 0x1428u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u));
    cpu->ecx = lift_load32(cpu->esi + 0x1428u);
    cpu->eax = cpu->ecx;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0xACu);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edi = 0xAu;
    lift_divide_accumulator(cpu, cpu->edi, 32u, 1u);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx += cpu->esi;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"ntex");
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    lift_store8(cpu->esp + 0x4Du, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x29u, cpu->eax & 0xFFu);
    lift_store8(cpu->esp + 0x4Eu, cpu->edx & 0xFFu);
    lift_store8(cpu->esp + 0x2Au, cpu->edx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49C1F9u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009BF8B;
    label_0009C201: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C201u);
    lift_push32(cpu, 2u);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"s");
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esi + 0x7E74u, cpu->ebx);
    lift_store32(cpu->esi + 0x7E78u, cpu->ebx);
    lift_store16(cpu->esp + 0x55u, 0x3030u);
    lift_store8(cpu->esp + 0x57u, 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49C235u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_0009C2DC;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0009C240: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C240u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009C252;
    cpu->edx = (uint32_t)(uintptr_t)"s";
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9C252u); lift_push32(cpu, r); sfera_sub_0049BA10(cpu,r); if (cpu->eip != r) return; }
    label_0009C252: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C252u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(8u), 32u);
    cpu->edx = lift_load32(cpu->ecx + cpu->esi + 0x18E0u);
    lift_store32(cpu->esi + 0x7E78u, (uint64_t)(lift_load32(cpu->esi + 0x7E78u)) + (uint64_t)(cpu->edx) + (uint64_t)(0u));
    cpu->ecx = lift_load32(cpu->esi + 0x7E74u);
    lift_store16(cpu->esi + ((uint32_t)(cpu->ecx) * 2u) + 0x7CE4u, cpu->eax & 0xFFFFu);
    lift_store32(cpu->esi + 0x7E74u, (uint64_t)(lift_load32(cpu->esi + 0x7E74u)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u));
    cpu->ecx = lift_load32(cpu->esi + 0x7E74u);
    cpu->eax = cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edi = 0x64u;
    lift_divide_accumulator(cpu, cpu->edi, 32u, 1u);
    lift_push32(cpu, 2u);
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)(0x30u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,8u); cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((v)) & 0xFFu); }
    lift_store8(cpu->esp + 0x49u, cpu->eax & 0xFFu);
    cpu->eax = 0x66666667u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    lift_store8(cpu->esp + 0x4Au, cpu->eax & 0xFFu);
    cpu->eax = cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->ecx = 0xAu;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    lift_store8(cpu->esp + 0x4Bu, cpu->edx & 0xFFu);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"s"); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49C2D4u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_0009C240;
    label_0009C2DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C2DCu);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esi + 0x142Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"nsky1");
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->esi + 0x18DCu, cpu->ebx);
    lift_store16(cpu->esp + 0x31u, 0x3030u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49C304u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_0009C403;
    label_0009C30C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C30Cu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_0009C31E;
    cpu->edx = (uint32_t)(uintptr_t)"nsky1";
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9C31Eu); lift_push32(cpu, r); sfera_sub_0049BA10(cpu,r); if (cpu->eip != r) return; }
    label_0009C31E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C31Eu);
    cpu->eax = lift_load32(cpu->esi + 0x18DCu);
    cpu->edi = native_function_address32(&::_stricmp);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->eax) * 8u) + 0x142Cu);
    lift_push32(cpu, (uintptr_t)"none"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x9C33Cu), LIFT_CODE_TOKEN_RVA(0x9C33Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49C33Cu);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009C353;
    cpu->eax = lift_load32(cpu->esi + 0x18DCu);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    lift_store8(cpu->esi + ((uint32_t)(cpu->edx) * 8u) + 0x142Cu, cpu->ebx & 0xFFu);
    label_0009C353: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C353u);
    cpu->eax = lift_load32(cpu->esi + 0x18DCu);
    lift_push32(cpu, cpu->ebp);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->eax) * 8u) + 0x1440u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"nsky2");
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49C378u); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebp)) goto label_0009C38A;
    cpu->edx = (uint32_t)(uintptr_t)"nsky2";
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9C38Au); lift_push32(cpu, r); sfera_sub_0049BA10(cpu,r); if (cpu->eip != r) return; }
    label_0009C38A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C38Au);
    cpu->eax = lift_load32(cpu->esi + 0x18DCu);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->eax) * 8u) + 0x1440u);
    lift_push32(cpu, (uintptr_t)"none"); lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x9C3A2u), LIFT_CODE_TOKEN_RVA(0x9C3A0u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49C3A2u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009C3B9;
    cpu->eax = lift_load32(cpu->esi + 0x18DCu);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    lift_store8(cpu->esi + ((uint32_t)(cpu->edx) * 8u) + 0x1440u, cpu->ebx & 0xFFu);
    label_0009C3B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C3B9u);
    lift_store32(cpu->esi + 0x18DCu, (uint64_t)(lift_load32(cpu->esi + 0x18DCu)) + (uint64_t)(cpu->ebp) + (uint64_t)(0u));
    cpu->ecx = lift_load32(cpu->esi + 0x18DCu);
    cpu->eax = cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    cpu->edi = 0xAu;
    lift_divide_accumulator(cpu, cpu->edi, 32u, 1u);
    lift_push32(cpu, cpu->ebp);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    lift_store8(cpu->esp + 0x25u, cpu->eax & 0xFFu);
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->eax) * 8u) + 0x142Cu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->edx & 0xFFu)) + (uint64_t)(0x30u) + (uint64_t)(0u))) & 0xFFu);
    lift_push32(cpu, cpu->ecx);
    lift_store8(cpu->esp + 0x2Au, cpu->edx & 0xFFu);
    lift_push32(cpu, (uint32_t)(uintptr_t)"nsky1");
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49C3FBu); lift_push32(cpu, r); sfera_sub_00480430(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_0009C30C;
    label_0009C403: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C403u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    g_sfera_weather_runtime.interpolation_offsets[0] = 4u;
    g_sfera_weather_runtime.interpolation_offsets[1] = 8u;
    g_sfera_weather_runtime.interpolation_offsets[2] = 0xCu;
    g_sfera_weather_runtime.interpolation_offsets[3] = 0x10u;
    lift_store32(cpu->esp + 0x58u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49C43Cu); lift_push32(cpu, r); sfera_sub_00480390(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x48u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049C460(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49C460u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->edx);
    cpu->esi = lift_load16(cpu->ecx + ((uint32_t)(cpu->esi) * 2u) + 0x7CE4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->edi);
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(8u), 32u);
    cpu->ebx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->ebx = lift_load32(cpu->esi + ((uint32_t)(cpu->ebx) * 4u) + 0x1918u);
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    lift_store32(cpu->edi, cpu->esi);
    cpu->eax = lift_load32(cpu->edx);
    cpu->eax = lift_load16(cpu->ecx + ((uint32_t)(cpu->eax) * 2u) + 0x7CE4u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(lift_load32(cpu->eax + cpu->ecx + 0x1914u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009C4EF;
    lift_store32(cpu->edi, 0u);
    cpu->esi = lift_load32(cpu->edx);
    cpu->eax = lift_load16(cpu->ecx + ((uint32_t)(cpu->esi) * 2u) + 0x7CE4u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax = lift_load32(cpu->eax + cpu->ecx + 0x18E0u);
    ++cpu->esi;
    cpu->eax -= cpu->ebx;
    lift_store32(cpu->edx, cpu->esi);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(lift_load32(cpu->ecx + 0x7E74u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009C4CE;
    lift_store32(cpu->edx, 0u);
    label_0009C4CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C4CEu);
    cpu->edx = lift_load32(cpu->edx);
    cpu->edx = lift_load16(cpu->ecx + ((uint32_t)(cpu->edx) * 2u) + 0x7CE4u);
    cpu->edi = lift_load32(cpu->edi);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->esi = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 4u));
    cpu->edx += cpu->ecx;
    cpu->eax += lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u) + 0x1918u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0009C4EF: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C4EFu);
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 4u));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    cpu->eax = lift_load32(cpu->eax + cpu->ecx + 0x1918u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax -= cpu->ebx;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049C510(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49C510u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esi, 0u);
    cpu->edx = lift_load16(cpu->ecx + ((uint32_t)(cpu->ebx) * 2u) + 0x7CE4u);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->edx + cpu->ecx + 0x1914u);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edi) <= 0) goto label_0009C568;
    cpu->ebx = (uint32_t)(cpu->edx + cpu->ecx + 0x1918u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0009C550: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C550u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx)) >= (int32_t)(uint32_t)(cpu->ebp)) goto label_0009C620;
    ++cpu->eax;
    cpu->ebx += 0x14u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->edi)) goto label_0009C550;
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    label_0009C568: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C568u);
    cpu->eax = lift_load32(cpu->edx + cpu->ecx + 0x18E0u);
    cpu->eax -= cpu->ebp;
    lift_store32(cpu->esi, cpu->eax);
    ++cpu->ebx;
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(lift_load32(cpu->ecx + 0x7E74u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009C58C;
    lift_flags_logic(cpu,0u,32u); cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    label_0009C58C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C58Cu);
    cpu->edx = lift_load16(cpu->ecx + ((uint32_t)(cpu->ebx) * 2u) + 0x7CE4u);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->edx = lift_load32(cpu->edx + cpu->ecx + 0x1918u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi)), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); lift_store32(cpu->esi, v); }
    label_0009C5A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C5A0u);
    cpu->edx = lift_load16(cpu->ecx + ((uint32_t)(cpu->ebx) * 2u) + 0x7CE4u);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx += cpu->edi;
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x1918u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) == 0u) goto label_0009C617;
    label_0009C5D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C5D1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49C5E2u); lift_push32(cpu, r); sfera_sub_0049C460(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi)), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); lift_store32(cpu->esi, v); }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load16(cpu->ecx + ((uint32_t)(cpu->eax) * 2u) + 0x7CE4u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx += cpu->edi;
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x1918u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_0009C5D1;
    label_0009C617: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C617u);
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_0009C620: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C620u);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    cpu->edi = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    cpu->edx = lift_load32(cpu->edx + cpu->ecx + 0x1918u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esi, cpu->edx);
    goto label_0009C5A0;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049C640(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49C640u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->eax);
    cpu->esi = lift_load16(cpu->ecx + ((uint32_t)(cpu->esi) * 2u) + 0x7CE4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->edi);
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(8u), 32u);
    cpu->ebx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 4u));
    cpu->esi += cpu->ecx;
    cpu->esi = lift_load32(cpu->esi + ((uint32_t)(cpu->ebx) * 4u) + 0x1918u);
    --cpu->edx;
    lift_store32(cpu->edi, cpu->edx);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009C6BD;
    lift_store32(cpu->eax, (uint64_t)(lift_load32(cpu->eax)) - 1u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax)), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009C67D;
    cpu->edx = lift_load32(cpu->ecx + 0x7E74u);
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    lift_store32(cpu->eax, cpu->edx);
    label_0009C67D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C67Du);
    cpu->edx = lift_load32(cpu->eax);
    cpu->edx = lift_load16(cpu->ecx + ((uint32_t)(cpu->edx) * 2u) + 0x7CE4u);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->edx = lift_load32(cpu->edx + cpu->ecx + 0x1914u);
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    lift_store32(cpu->edi, cpu->edx);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load16(cpu->ecx + ((uint32_t)(cpu->eax) * 2u) + 0x7CE4u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 4u));
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    cpu->eax = lift_load32(cpu->eax + cpu->ecx + 0x18E0u);
    cpu->eax -= lift_load32(cpu->edx + cpu->ecx + 0x1918u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax += cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0009C6BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C6BDu);
    cpu->eax = lift_load32(cpu->eax);
    cpu->eax = lift_load16(cpu->ecx + ((uint32_t)(cpu->eax) * 2u) + 0x7CE4u);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax += cpu->ecx;
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 4u));
    cpu->esi -= lift_load32(cpu->eax + ((uint32_t)(cpu->edx) * 4u) + 0x1918u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049C6E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49C6E0u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esi, 0u);
    cpu->edx = lift_load16(cpu->ecx + ((uint32_t)(cpu->ebx) * 2u) + 0x7CE4u);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->eax = lift_load32(cpu->edx + cpu->ecx + 0x1914u);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_SF) != 0u) goto label_0009C733;
    cpu->ebp = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->ebp = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ebp) * 4u));
    cpu->ebp = (uint32_t)(cpu->ecx + cpu->ebp + 0x1918u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0009C720: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C720u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebp)) <= (int32_t)(uint32_t)(cpu->edi)) goto label_0009C7F9;
    cpu->ebp -= 0x14u;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_SF) == 0u) goto label_0009C720;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    label_0009C733: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C733u);
    --cpu->ebx;
    lift_store32(cpu->esi, cpu->edi);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(0xFFFFFFFFu), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009C74A;
    cpu->ebx = lift_load32(cpu->ecx + 0x7E74u);
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    label_0009C74A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C74Au);
    cpu->edx = lift_load16(cpu->ecx + ((uint32_t)(cpu->ebx) * 2u) + 0x7CE4u);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->eax = lift_load32(cpu->edx + cpu->ecx + 0x1914u);
    --cpu->eax;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->ebp = (uint32_t)(cpu->edx + cpu->eax);
    cpu->edx = lift_load32(cpu->edx + cpu->ecx + 0x18E0u);
    cpu->edx -= lift_load32(cpu->ecx + cpu->ebp + 0x1918u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->edx = v; }
    lift_store32(cpu->esi, cpu->edx);
    label_0009C77D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C77Du);
    cpu->edx = lift_load16(cpu->ecx + ((uint32_t)(cpu->ebx) * 2u) + 0x7CE4u);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->edx += cpu->eax;
    cpu->edx += cpu->edi;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x1918u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) == 0u) goto label_0009C7F0;
    label_0009C7AA: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C7AAu);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49C7BBu); lift_push32(cpu, r); sfera_sub_0049C640(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi)), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); lift_store32(cpu->esi, v); }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load16(cpu->ecx + ((uint32_t)(cpu->eax) * 2u) + 0x7CE4u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx += cpu->edi;
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + cpu->ecx + 0x1918u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_0009C7AA;
    label_0009C7F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C7F0u);
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_0009C7F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C7F9u);
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->edx += cpu->eax;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(lift_load32(cpu->edx + cpu->ecx + 0x1918u)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    lift_store32(cpu->esi, cpu->edi);
    goto label_0009C77D;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049C820(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49C820u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = cpu->ecx;
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_divide_accumulator(cpu, lift_load32(cpu->esi + 0x7E78u), 32u, 1u);
    cpu->ebx = 0u;
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esi + 0x7E74u)) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0009C8AD;
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x7CE4u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0009C850: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C850u);
    cpu->eax = lift_load16(cpu->edi);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->esi + 0x7CE0u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0009C86D;
    cpu->ecx = (uint32_t)(uintptr_t)"wScenarioArr[curSN] >= wScenariosNum";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49C865u); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    label_0009C86D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C86Du);
    cpu->eax = lift_load16(cpu->edi);
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax = lift_load32(cpu->eax + cpu->esi + 0x18E0u);
    cpu->ebp += cpu->eax;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->ebp)) goto label_0009C894;
    ++cpu->ebx;
    cpu->edi += 2u;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esi + 0x7E74u))) goto label_0009C850;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_0009C894: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C894u);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax -= cpu->ebp;
    cpu->eax += cpu->edx;
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esi, cpu->ebx);
    lift_store32(cpu->edx, cpu->eax);
    cpu->ecx -= cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edi = lift_pop32(cpu);
    label_0009C8AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C8ADu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049C8C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49C8C0u);
    lift_push32(cpu, cpu->ecx);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009C8F0;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_weather_runtime.direction_sin_component));
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0009C962;
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_weather_runtime.direction_cos_component));
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0009C964;
    label_0009C8F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C8F0u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(7u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ecx = v; }
    lift_store32(cpu->esp + 8u, cpu->ecx);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 8u)))));
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(4u), 32u);
    cpu->eax &= 3u;
    ++cpu->eax;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.7853982448577881));
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.25));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.00019999999494757503));
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49C935u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0xCu))));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_weather_runtime.direction_sin_component, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49C94Eu); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0xCu))));
    lift_store_f32((uint32_t)(uintptr_t)&g_sfera_weather_runtime.direction_cos_component, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0009C964;
    label_0009C962: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C962u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0009C964: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C964u);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_weather_runtime.direction_sin_component));
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store_f32(cpu->edx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32((uint32_t)(uintptr_t)&g_sfera_weather_runtime.direction_cos_component));
    lift_store_f32(cpu->eax, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049C980(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49C980u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009C9A4;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, 0xACu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x49C998u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49C99Du);
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0009C9A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C9A4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(lift_load32(cpu->edi + 0x1428u))) goto label_0009CA00;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = native_function_address32(&::_stricmp);
    cpu->ebx = cpu->edi;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0009C9C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C9C0u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x9C9C8u), LIFT_CODE_TOKEN_RVA(0x9C9C6u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49C9C8u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009C9DE;
    ++cpu->esi;
    cpu->ebx += 0xACu;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->edi + 0x1428u))) goto label_0009C9C0;
    label_0009C9DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x49C9DEu);
    cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(lift_load32(cpu->edi + 0x1428u))) goto label_0009CA00;
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0xACu);
    cpu->esi += cpu->edi;
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = 0x2Bu;
    lift_movs32(cpu, 1u);
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0009CA00: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CA00u);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = (uint32_t)(uintptr_t)"Sky texture name absent in params. ";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49CA0Eu); lift_push32(cpu, r); sfera_sub_00459CB0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049CA20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49CA20u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49CA42u); lift_push32(cpu, r); sfera_sub_0049C820(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0xCu)))));
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_load16(cpu->ebx + ((uint32_t)(cpu->ecx) * 2u) + 0x7CE4u);
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(8u), 32u);
    cpu->esi = (uint32_t)(cpu->edx + cpu->ebx + 0x18E0u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / ((double)(((int32_t)(lift_load32(cpu->esi))))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_0009CA83;
    cpu->ecx = (uint32_t)(uintptr_t)"internal error 98742756";
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49CA7Fu); lift_push32(cpu, r); sfera_sub_00459B10(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    label_0009CA83: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CA83u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ecx = (uint32_t)(cpu->esi + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009CA92;
    if ((uint8_t)(lift_load8(cpu->esi + 0x18u)) == (uint8_t)(0u)) goto label_0009CAD7;
    label_0009CA92: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CA92u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x2Cu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0009CAD7;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x30u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_0009CAD9;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->eax = cpu->ecx;
    cpu->edx -= cpu->ecx;
    label_0009CAB2: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CAB2u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0009CAB2;
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->eax = (uint32_t)(cpu->esi + 0x18u);
    cpu->edx -= cpu->eax;
    label_0009CAC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CAC5u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    lift_store8(cpu->edx + cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0009CAC5;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 16u, stop_address); return;
    label_0009CAD7: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CAD7u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0009CAD9: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CAD9u);
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    lift_store32(cpu->esp + 8u, cpu->ecx);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x18DCu)) <= (int32_t)(uint32_t)(cpu->ecx)) goto label_0009CBDB;
    cpu->eax = (uint32_t)(cpu->ebx + 0x1440u);
    lift_push32(cpu, cpu->ebp);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_push32(cpu, cpu->edi);
    label_0009CB00: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CB00u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax + 0xFFFFFFECu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebp = (uint32_t)(cpu->eax + 0xFFFFFFECu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009CB10;
    { uint64_t l=(uint64_t)(lift_load8(cpu->eax)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->ebp = cpu->eax;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009CB72;
    label_0009CB10: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CB10u);
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x1428u)) <= (int32_t)(uint32_t)(cpu->esi)) goto label_0009CB3E;
    cpu->edi = cpu->ebx;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0009CB20: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CB20u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x49CB22u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49CB28u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009CB4A;
    ++cpu->esi;
    cpu->edi += 0xACu;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x1428u))) goto label_0009CB20;
    label_0009CB3E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CB3Eu);
    cpu->edx = cpu->ebp;
    cpu->ecx = (uint32_t)(uintptr_t)"Sky texture name present in para, but absent in params. ";
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9CB4Au); lift_push32(cpu, r); sfera_sub_00459CB0(cpu,r); if (cpu->eip != r) return; }
    label_0009CB4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CB4Au);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    cpu->esi = (int64_t)(int32_t)(cpu->esi) * (int64_t)(int32_t)(0xACu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + cpu->ebx + 0x20u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0009CBAF;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + cpu->ebx + 0x24u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) != 0u) goto label_0009CBB1;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    label_0009CB72: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CB72u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_0009CB84;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_weather_runtime.sky_texture_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49CB80u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    label_0009CB84: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CB84u);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(g_sfera_weather_runtime.sky_texture_handles.capacity)) goto label_0009CB9C;
    cpu->edx = cpu->ecx;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_weather_runtime.sky_texture_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49CB98u); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    label_0009CB9C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CB9Cu);
    cpu->eax = g_sfera_weather_runtime.sky_texture_handles.data;
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u), cpu->edx);
    ++cpu->ecx;
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    goto label_0009CBB5;
    label_0009CBAF: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CBAFu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0009CBB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CBB1u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    label_0009CBB5: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CBB5u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    ++cpu->edx;
    cpu->eax += 0x28u;
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x18DCu))) goto label_0009CB00;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_0009CBF1;
    label_0009CBDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CBDBu);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->esi = lift_pop32(cpu);
    lift_store8(cpu->eax, 0u);
    lift_store8(cpu->ecx, 0u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 16u, stop_address); return;
    label_0009CBF1: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CBF1u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->esi = cpu->edx;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0009CC08;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_weather_runtime.sky_texture_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9CC08u); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0009CC08: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CC08u);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_weather_runtime.sky_texture_handles.capacity)) goto label_0009CC1C;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_weather_runtime.sky_texture_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9CC1Cu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0009CC1C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CC1Cu);
    cpu->edx = g_sfera_weather_runtime.sky_texture_handles.data;
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->eax) * 8u) + 0x142Cu);
    label_0009CC33: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CC33u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0009CC33;
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0009CC4B;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_weather_runtime.sky_texture_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9CC4Bu); lift_push32(cpu, r); sfera_sub_004010F0(cpu,r); if (cpu->eip != r) return; }
    label_0009CC4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CC4Bu);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(g_sfera_weather_runtime.sky_texture_handles.capacity)) goto label_0009CC5F;
    cpu->edx = cpu->esi;
    cpu->ecx = (uint32_t)(uintptr_t)&g_sfera_weather_runtime.sky_texture_handles.debug_file[0];
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9CC5Fu); lift_push32(cpu, r); sfera_sub_00401120(cpu,r); if (cpu->eip != r) return; }
    label_0009CC5F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CC5Fu);
    cpu->ecx = g_sfera_weather_runtime.sky_texture_handles.data;
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    cpu->edx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->edx) * 8u) + 0x1440u);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    label_0009CC76: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CC76u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->edx, cpu->eax & 0xFFu);
    ++cpu->ecx;
    ++cpu->edx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0009CC76;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049CC90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49CC90u);
    cpu->esp -= 0x74u;
    cpu->eax = lift_load32(cpu->esp + 0x80u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x7Cu);
    lift_store32(cpu->esp + 0xCu, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(lift_load32(cpu->ebx + 0x7E7Cu))) goto label_0009CFF6;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->ebx + 0x7E7Cu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49CCE0u); lift_push32(cpu, r); sfera_sub_0049C820(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->edi = (uint32_t)(uintptr_t)&g_sfera_weather_runtime.interpolation_offsets[0];
    goto label_0009CCF4;
    label_0009CCF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CCF0u);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    label_0009CCF4: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CCF4u);
    cpu->esi = lift_load32(cpu->edi);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49CD09u); lift_push32(cpu, r); sfera_sub_0049C6E0(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ebx) != 0u) goto label_0009CD1B;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    goto label_0009CD58;
    label_0009CD1B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CD1Bu);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49CD30u); lift_push32(cpu, r); sfera_sub_0049C510(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u));
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->eax += cpu->ebx;
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x24u)))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0009CD58: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CD58u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->edi += 4u;
    lift_store_f32(cpu->esi + cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(((uint32_t)(uintptr_t)&g_sfera_weather_runtime.interpolation_offsets[kWeatherInterpolationOffsetCount]))) goto label_0009CCF0;
    lift_x87_push(cpu, 0.0);
    cpu->ebx = lift_load32(cpu->esp + 0x88u);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    cpu->edx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->edx);
    cpu->esi = cpu->ecx;
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_store_f32(cpu->esi + 0x16Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x90u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49CDA8u); lift_push32(cpu, r); sfera_sub_0049CA20(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(lift_load8(cpu->esp + 0x30u)) != (uint8_t)(0u)) goto label_0009CDBA;
    if ((uint8_t)(lift_load8(cpu->esp + 0x44u)) == (uint8_t)(0u)) goto label_0009CF99;
    label_0009CDBA: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CDBAu);
    cpu->edi = (uint32_t)(cpu->ebx + 1u);
    cpu->ebx += 0x51u;
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0009CE78;
    cpu->esi = cpu->edi;
    cpu->esi -= lift_load32(cpu->esp + 0x88u);
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    label_0009CDD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CDD5u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    cpu->ecx = (uint32_t)(cpu->esp + 0x6Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x5Cu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.00017361111531499773));
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x98u))));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49CE04u); lift_push32(cpu, r); sfera_sub_0049CA20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x58u);
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0009CE10: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CE10u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009CE30;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_0009CE2C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009CE30;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0009CE10;
    label_0009CE2C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CE2Cu);
    cpu->eax = 0u;
    goto label_0009CE35;
    label_0009CE30: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CE30u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_0009CE35: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CE35u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009CE78;
    cpu->ecx = (uint32_t)(cpu->esp + 0x6Cu);
    cpu->eax = (uint32_t)(cpu->esp + 0x44u);
    label_0009CE41: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CE41u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009CE61;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_0009CE5D;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009CE61;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0009CE41;
    label_0009CE5D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CE5Du);
    cpu->eax = 0u;
    goto label_0009CE66;
    label_0009CE61: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CE61u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_0009CE66: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CE66u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009CE78;
    ++cpu->edi;
    ++cpu->esi;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->ebx)) goto label_0009CDD5;
    label_0009CE78: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CE78u);
    cpu->edi -= lift_load32(cpu->esp + 0x88u);
    cpu->esi = lift_load32(cpu->esp + 0x88u);
    cpu->ebp = cpu->edi;
    cpu->ebx = (uint32_t)(cpu->esi + 0xFFFFFFFFu);
    cpu->edi = (uint32_t)(cpu->esi + 0xFFFFFFAFu);
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(cpu->edi)) goto label_0009CF4F;
    cpu->esi -= cpu->ebx;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    label_0009CEA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CEA0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x8Cu));
    cpu->eax = (uint32_t)(cpu->esp + 0x6Cu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x5Cu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (0.00017361111531499773));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49CED3u); lift_push32(cpu, r); sfera_sub_0049CA20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x58u);
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    label_0009CEE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CEE0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009CF00;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_0009CEFC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009CF00;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0009CEE0;
    label_0009CEFC: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CEFCu);
    cpu->eax = 0u;
    goto label_0009CF05;
    label_0009CF00: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CF00u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_0009CF05: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CF05u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009CF48;
    cpu->ecx = (uint32_t)(cpu->esp + 0x6Cu);
    cpu->eax = (uint32_t)(cpu->esp + 0x44u);
    label_0009CF11: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CF11u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009CF31;
    if ((uint8_t)((cpu->edx & 0xFFu)) == 0u) goto label_0009CF2D;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + 1u)) & 0xFFu);
    { uint64_t l=(uint64_t)((cpu->edx & 0xFFu)), r=(uint64_t)(lift_load8(cpu->ecx + 1u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009CF31;
    cpu->eax += 2u;
    cpu->ecx += 2u;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0009CF11;
    label_0009CF2D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CF2Du);
    cpu->eax = 0u;
    goto label_0009CF36;
    label_0009CF31: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CF31u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->eax), c=(uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u)), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(0xFFFFFFFFu) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    label_0009CF36: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CF36u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009CF48;
    --cpu->ebx;
    ++cpu->esi;
    lift_store32(cpu->esp + 0x10u, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->ebx) > (int32_t)(uint32_t)(cpu->edi)) goto label_0009CEA0;
    label_0009CF48: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CF48u);
    cpu->esi = lift_load32(cpu->esp + 0x88u);
    label_0009CF4F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CF4Fu);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->edx = (uint32_t)(cpu->edi + 0x2D0u);
    lift_push32(cpu, cpu->edx);
    cpu->esi -= cpu->ebx;
    cpu->eax = (uint32_t)(cpu->edi + 0x2CCu);
    lift_push32(cpu, cpu->eax);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->eax = cpu->edx & 0xFFu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49CF7Bu); lift_push32(cpu, r); sfera_sub_0049C8C0(cpu,r); if (cpu->eip != r) return; }
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->ebp)) goto label_0009CF83;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    label_0009CF83: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CF83u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    cpu->esi = cpu->edi;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (81.0));
    lift_store_f32(cpu->edi + 0x16Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0009CF99: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CF99u);
    cpu->ecx = (uint32_t)(cpu->esi + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49CFA9u); lift_push32(cpu, r); sfera_sub_0049C980(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esi + 0xC0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49CFBCu); lift_push32(cpu, r); sfera_sub_0049C980(cpu,r); if (cpu->eip != r) return; }
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49CFC1u); lift_push32(cpu, r); sfera_sub_00457020(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009CFF3;
    cpu->edx = (uint32_t)(cpu->esi + 0x170u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, (uintptr_t)"clouds8");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49CFD8u); lift_push32(cpu, r); sfera_sub_0049C980(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esi + 0x21Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, (uintptr_t)"clouds8a");
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49CFEBu); lift_push32(cpu, r); sfera_sub_0049C980(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esi + 0x2C8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0009CFF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CFF3u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_0009CFF6: cpu->eip = LIFT_CODE_TOKEN_VA(0x49CFF6u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x74u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049D010(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D010u);
    cpu->esp -= 0x34u;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esp + 0xCu, 0x30u);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    lift_store32(cpu->esp + 0x14u, LIFT_CALLBACK(sfera_sub_00421F10));
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::GetModuleHandleA), LIFT_CODE_TOKEN_VA(0x49D033u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49D039u);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    lift_store32(cpu->esp + 0x34u, (uintptr_t)"Browser Example");
    lift_store32(cpu->esp + 0x38u, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::RegisterClassExA), LIFT_CODE_TOKEN_VA(0x49D05Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49D064u);
    if ((uint16_t)((cpu->eax & 0xFFFFu)) != 0u) goto label_0009D07E;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xBu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, cpu->ecx);
    lift_store8(cpu->esp + 0xFu, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9D07Eu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_0009D07E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D07Eu);
    g_sfera_browser_window_runtime.class_registered = (uint8_t)(1u);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049D090(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D090u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->esi) == (uint32_t)(0x201u)) goto label_0009D0EE;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0x202u)) goto label_0009D0EE;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->esi) == (uint32_t)(0x100u)) goto label_0009D0BF;
    if ((uint32_t)(cpu->esi) != (uint32_t)(0x101u)) goto label_0009D0D3;
    label_0009D0BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D0BFu);
    if ((uint32_t)(cpu->ebx) != (uint32_t)(0x1Bu)) goto label_0009D0D3;
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SendMessageA), LIFT_CODE_TOKEN_RVA(0x9D0CDu));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x9D0D3u);
    label_0009D0D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D0D3u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edx = g_sfera_browser_window_runtime.original_window_proc;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::CallWindowProcA), LIFT_CODE_TOKEN_VA(0x49D0E2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49D0E8u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_0009D0EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D0EEu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049D100(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D100u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    cpu->edi = 0u;
    lift_push32(cpu, 0xFFFFFFEBu); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::GetWindowLongA), LIFT_CODE_TOKEN_VA(0x49D11Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49D125u);
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_0009D19B;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, address32(&__uuidof(IWebBrowser2))); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x9D13Cu), LIFT_CODE_TOKEN_RVA(0x9D13Au))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D13Cu);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0009D19B;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x48u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x9D151u), LIFT_CODE_TOKEN_RVA(0x9D14Fu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D151u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0009D19B;
    cpu->eax = lift_load32(cpu->esp + 8u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_0009D19F;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, address32(&__uuidof(IHTMLDocument2))); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x9D16Eu), LIFT_CODE_TOKEN_RVA(0x9D16Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D16Eu);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0009D19B;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, address32(&__uuidof(IOleWindow))); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x9D187u), LIFT_CODE_TOKEN_RVA(0x9D185u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D187u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0009D19B;
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0xCu);
    cpu->esi += 0x20u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x9D19Bu), LIFT_CODE_TOKEN_RVA(0x9D199u))) { return; }
    label_0009D19B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D19Bu);
    cpu->eax = lift_load32(cpu->esp + 8u);
    label_0009D19F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D19Fu);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0009D1B3;
    cpu->eax = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ecx), LIFT_CODE_TOKEN_RVA(0x9D1AFu), LIFT_CODE_TOKEN_RVA(0x9D1ADu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D1AFu);
    cpu->eax = lift_load32(cpu->esp + 8u);
    label_0009D1B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D1B3u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0009D1C7;
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->edx + 8u);
    lift_push32(cpu, cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x9D1C3u), LIFT_CODE_TOKEN_RVA(0x9D1C1u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D1C3u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    label_0009D1C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D1C7u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_0009D1D3;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x9D1D3u), LIFT_CODE_TOKEN_RVA(0x9D1D1u))) { return; }
    label_0009D1D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D1D3u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009D1E5;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x9D1E5u), LIFT_CODE_TOKEN_RVA(0x9D1E3u))) { return; }
    label_0009D1E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D1E5u);
    cpu->esp += 0x10u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049D1F0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_0009D1F0;
    label_00021B10: cpu->eip = LIFT_CODE_TOKEN_VA(0x421B10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, 0xFFFFFFEBu); lift_push32(cpu, cpu->ecx);
    cpu->esi = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::GetWindowLongA), LIFT_CODE_TOKEN_VA(0x421B17u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x421B1Du);
    cpu->eax = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, address32(&__uuidof(IWebBrowser2))); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x21B30u), LIFT_CODE_TOKEN_RVA(0x21B2Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421B30u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_00021BD8;
    if ((uint32_t)(cpu->esi) > (uint32_t)(5u)) goto label_00021BCC;
    switch ((uint32_t)(cpu->esi)) {
        case 0u: goto label_00021B48;
        case 1u: goto label_00021B63;
        case 2u: goto label_00021B7E;
        case 3u: goto label_00021B99;
        case 4u: goto label_00021BB4;
        case 5u: goto label_00021BC0;
        default: lift_trap(cpu, 0x421B41u, "resolved jump-table index out of range"); return;
    }
label_00021B48: ;
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x21B54u), LIFT_CODE_TOKEN_RVA(0x21B52u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421B54u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x21B60u), LIFT_CODE_TOKEN_RVA(0x21B5Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421B60u);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00021B63: cpu->eip = LIFT_CODE_TOKEN_VA(0x421B63u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x20u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x21B6Fu), LIFT_CODE_TOKEN_RVA(0x21B6Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421B6Fu);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x21B7Bu), LIFT_CODE_TOKEN_RVA(0x21B79u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421B7Bu);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00021B7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x421B7Eu);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x24u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x21B8Au), LIFT_CODE_TOKEN_RVA(0x21B88u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421B8Au);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x21B96u), LIFT_CODE_TOKEN_RVA(0x21B94u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421B96u);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00021B99: cpu->eip = LIFT_CODE_TOKEN_VA(0x421B99u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x28u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x21BA5u), LIFT_CODE_TOKEN_RVA(0x21BA3u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421BA5u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x21BB1u), LIFT_CODE_TOKEN_RVA(0x21BAFu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x421BB1u);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00021BB4: cpu->eip = LIFT_CODE_TOKEN_VA(0x421BB4u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x30u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x21BC0u), LIFT_CODE_TOKEN_RVA(0x21BBEu))) { return; }
    label_00021BC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x421BC0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x38u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x21BCCu), LIFT_CODE_TOKEN_RVA(0x21BCAu))) { return; }
    label_00021BCC: cpu->eip = LIFT_CODE_TOKEN_VA(0x421BCCu);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x21BD8u), LIFT_CODE_TOKEN_RVA(0x21BD6u))) { return; }
    label_00021BD8: cpu->eip = LIFT_CODE_TOKEN_VA(0x421BD8u);
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_0009D1F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D1F0u);
    cpu->ecx = lift_load32(cpu->ecx + 0x1Cu);
    cpu->edx = 4u;
    goto label_00021B10;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049D200(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D200u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->ecx = lift_load32(cpu->ecx + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49D211u); lift_push32(cpu, r); sfera_sub_00421A90(cpu,r); if (cpu->eip != r) return; }
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049D220(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D220u);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x2Cu);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x1Cu);
    lift_push32(cpu, 0xFFFFFFEBu);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::GetWindowLongA), LIFT_CODE_TOKEN_VA(0x49D247u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49D24Du);
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_0009D2B3;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, address32(&__uuidof(IWebBrowser2))); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x9D264u), LIFT_CODE_TOKEN_RVA(0x9D262u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D264u);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0009D2B3;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, address32(&__uuidof(IViewObject2))); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x9D27Du), LIFT_CODE_TOKEN_RVA(0x9D27Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D27Du);
    if ((int32_t)(uint32_t)(cpu->eax) < 0) goto label_0009D2B3;
    cpu->edx = lift_load32(cpu->esi + 0x34u);
    cpu->ecx = lift_load32(cpu->esi + 0x30u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esp + 0x2Cu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x38u, cpu->ebx);
    lift_store32(cpu->esp + 0x3Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x40u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x9D2B3u), LIFT_CODE_TOKEN_RVA(0x9D2B1u))) { return; }
    label_0009D2B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D2B3u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_0009D2C3;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x9D2C3u), LIFT_CODE_TOKEN_RVA(0x9D2C1u))) { return; }
    label_0009D2C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D2C3u);
    cpu->eax = lift_load32(cpu->esp + 0xCu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009D2D6;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x9D2D6u), LIFT_CODE_TOKEN_RVA(0x9D2D4u))) { return; }
    label_0009D2D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D2D6u);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049D2F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D2F0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x38u)), r=(uint64_t)(1u), v=l | r; lift_flags_logic(cpu,v,32u); lift_store32(cpu->esi + 0x38u, v); }
    cpu->ebp = lift_load32(cpu->esi + 0x38u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx & 0xFFFFu;
    cpu->edx = cpu->eax & 0xFFFFu;
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(0x10u), 32u);
    cpu->edi |= cpu->edx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x20u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esi + 0x28u, cpu->eax);
    lift_store32(cpu->esi + 0x2Cu, cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009D322;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9D322u); lift_push32(cpu, r); sfera_sub_0049D100(cpu,r); if (cpu->eip != r) return; }
    label_0009D322: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D322u);
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009D346;
    if ((uint8_t)(lift_load8(cpu->esi + 0x24u)) != (uint8_t)(0u)) goto label_0009D346;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_0049D090)); lift_push32(cpu, 0xFFFFFFFCu); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetWindowLongA), LIFT_CODE_TOKEN_VA(0x49D337u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49D33Du);
    g_sfera_browser_window_runtime.original_window_proc = (uint32_t)(cpu->eax);
    lift_store8(cpu->esi + 0x24u, 1u);
    label_0009D346: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D346u);
    cpu->esi = lift_load32(cpu->esi + 0x20u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_0009D361;
    cpu->eax = g_sfera_browser_window_runtime.original_window_proc;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 0x201u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::CallWindowProcA), LIFT_CODE_TOKEN_RVA(0x9D35Bu));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x9D361u);
    label_0009D361: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D361u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049D370(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D370u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x38u)), r=(uint64_t)(0xFFFFFFFEu), v=l & r; lift_flags_logic(cpu,v,32u); lift_store32(cpu->esi + 0x38u, v); }
    cpu->ebx = lift_load32(cpu->esi + 0x38u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx & 0xFFFFu;
    cpu->edx = cpu->eax & 0xFFFFu;
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(0x10u), 32u);
    cpu->edi |= cpu->edx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x20u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esi + 0x28u, cpu->eax);
    lift_store32(cpu->esi + 0x2Cu, cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009D3A2;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9D3A2u); lift_push32(cpu, r); sfera_sub_0049D100(cpu,r); if (cpu->eip != r) return; }
    label_0009D3A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D3A2u);
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009D3C6;
    if ((uint8_t)(lift_load8(cpu->esi + 0x24u)) != (uint8_t)(0u)) goto label_0009D3C6;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_0049D090)); lift_push32(cpu, 0xFFFFFFFCu); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetWindowLongA), LIFT_CODE_TOKEN_VA(0x49D3B7u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49D3BDu);
    g_sfera_browser_window_runtime.original_window_proc = (uint32_t)(cpu->eax);
    lift_store8(cpu->esi + 0x24u, 1u);
    label_0009D3C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D3C6u);
    cpu->esi = lift_load32(cpu->esi + 0x20u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_0009D3E1;
    cpu->eax = g_sfera_browser_window_runtime.original_window_proc;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x202u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::CallWindowProcA), LIFT_CODE_TOKEN_RVA(0x9D3DBu));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x9D3E1u);
    label_0009D3E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D3E1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049D3F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D3F0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x28u)), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009D405;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x2Cu)), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009D466;
    label_0009D405: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D405u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx & 0xFFFFu;
    lift_store32(cpu->esi + 0x28u, cpu->eax);
    cpu->eax = cpu->eax & 0xFFFFu;
    cpu->edi = lift_shift_left(cpu, cpu->edi, (uint32_t)(0x10u), 32u);
    cpu->edi |= cpu->eax;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x20u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esi + 0x2Cu, cpu->ecx);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009D424;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9D424u); lift_push32(cpu, r); sfera_sub_0049D100(cpu,r); if (cpu->eip != r) return; }
    label_0009D424: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D424u);
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009D448;
    if ((uint8_t)(lift_load8(cpu->esi + 0x24u)) != (uint8_t)(0u)) goto label_0009D448;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_0049D090)); lift_push32(cpu, 0xFFFFFFFCu); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetWindowLongA), LIFT_CODE_TOKEN_VA(0x49D439u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49D43Fu);
    g_sfera_browser_window_runtime.original_window_proc = (uint32_t)(cpu->eax);
    lift_store8(cpu->esi + 0x24u, 1u);
    label_0009D448: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D448u);
    cpu->esi = lift_load32(cpu->esi + 0x20u);
    if ((uint32_t)(cpu->esi) == 0u) goto label_0009D465;
    cpu->ecx = g_sfera_browser_window_runtime.original_window_proc;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, 0u); lift_push32(cpu, 0x200u); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::CallWindowProcA), LIFT_CODE_TOKEN_RVA(0x9D45Fu));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x9D465u);
    label_0009D465: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D465u);
    cpu->edi = lift_pop32(cpu);
    label_0009D466: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D466u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049D470(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D470u);
    cpu->esp -= 8u;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esi + 0x28u, cpu->eax);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_store32(cpu->esi + 0x2Cu, cpu->ecx);
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    cpu->ecx = g_sfera_window_runtime.main_window;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::ClientToScreen), LIFT_CODE_TOKEN_VA(0x49D49Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49D4A0u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x20u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_load32(cpu->esp + 0xCu);
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009D4B5;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9D4B5u); lift_push32(cpu, r); sfera_sub_0049D100(cpu,r); if (cpu->eip != r) return; }
    label_0009D4B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D4B5u);
    cpu->eax = lift_load32(cpu->esi + 0x20u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009D4D9;
    if ((uint8_t)(lift_load8(cpu->esi + 0x24u)) != (uint8_t)(0u)) goto label_0009D4D9;
    lift_push32(cpu, LIFT_CALLBACK(sfera_sub_0049D090)); lift_push32(cpu, 0xFFFFFFFCu); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::SetWindowLongA), LIFT_CODE_TOKEN_VA(0x49D4CAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49D4D0u);
    g_sfera_browser_window_runtime.original_window_proc = (uint32_t)(cpu->eax);
    lift_store8(cpu->esi + 0x24u, 1u);
    label_0009D4D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D4D9u);
    cpu->esi = lift_load32(cpu->esi + 0x20u);
    { uint64_t v=(uint64_t)(cpu->esi); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009D516;
    cpu->edx = cpu->ebx & 0xFFFFu;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(0x10u), 32u);
    cpu->eax = cpu->edi & 0xFFFFu;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->edx = v; }
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_left(cpu, cpu->ecx, (uint32_t)(4u), 32u);
    cpu->ecx -= cpu->eax;
    cpu->eax = g_sfera_browser_window_runtime.original_window_proc;
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->edx = cpu->ecx & 0xFFFFu;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(0x10u), 32u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0x20Au); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::CallWindowProcA), LIFT_CODE_TOKEN_RVA(0x9D510u));
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x9D516u);
    label_0009D516: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D516u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049D520(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D520u);
    cpu->eax = g_sfera_window_runtime.main_window;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_native_call(cpu, native_function_address32(&::SetFocus), LIFT_CODE_TOKEN_VA(0x49D529u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49D52Fu);
    cpu->ecx = lift_load32(cpu->esi + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::DestroyWindow), LIFT_CODE_TOKEN_VA(0x49D533u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49D539u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_0009D54A;
    cpu->edx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49D547u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009D54A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D54Au);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store8(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049D560(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D560u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 8u);
    cpu->eax = cpu->esi;
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_0009D570: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D570u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_0009D570;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49D580u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049D590(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D590u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->edx;
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0009D5A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D5A0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_0009D5A0;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49D5B2u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_0009D5C7;
    cpu->edx = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esi + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49D5C2u); lift_push32(cpu, r); sfera_sub_00421C00(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0009D5C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D5C7u);
    cpu->ecx = lift_load32(cpu->esi + 0x1Cu);
    cpu->edx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49D5D1u); lift_push32(cpu, r); sfera_sub_00421C00(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049D5E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D5E0u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esi + 0x20u, cpu->ebx);
    lift_store8(cpu->esi + 0x24u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esi + 0x28u, cpu->ebx);
    lift_store32(cpu->esi + 0x2Cu, cpu->ebx);
    lift_store32(cpu->esi + 0x30u, cpu->eax);
    lift_store32(cpu->esi + 0x34u, cpu->ecx);
    lift_store32(cpu->esi + 0x38u, cpu->ebx);
    if ((uint8_t)(g_sfera_browser_window_runtime.class_registered) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0009D610;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9D610u); lift_push32(cpu, r); sfera_sub_0049D010(cpu,r); if (cpu->eip != r) return; }
    label_0009D610: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D610u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::GetModuleHandleA), LIFT_CODE_TOKEN_VA(0x49D612u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49D618u);
    cpu->edx = g_sfera_window_runtime.main_window;
    cpu->ecx = lift_load32(cpu->esi + 0x30u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esi + 0x34u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0x40000000u); lift_push32(cpu, (uintptr_t)"");
    lift_push32(cpu, (uintptr_t)"Browser Example"); lift_push32(cpu, cpu->ebx);
    lift_native_call(cpu, native_function_address32(&::CreateWindowExA), LIFT_CODE_TOKEN_VA(0x49D63Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49D641u);
    lift_store32(cpu->esi + 0x1Cu, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_0009D65D;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    lift_push32(cpu, cpu->edx);
    lift_store8(cpu->esp + 0x18u, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9D65Du); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_0009D65D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D65Du);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->eax = cpu->edx;
    lift_push32(cpu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_0009D667: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D667u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0009D667;
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49D679u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0009D68F;
    cpu->edx = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esi + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49D68Au); lift_push32(cpu, r); sfera_sub_00421C00(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0009D68F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D68Fu);
    cpu->ecx = lift_load32(cpu->esi + 0x1Cu);
    cpu->edx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49D699u); lift_push32(cpu, r); sfera_sub_00421C00(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049D6A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D6A0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store8(cpu->esi, cpu->eax & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49D6F0u); lift_push32(cpu, r); sfera_sub_0049D5E0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049D710(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D710u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->esi);
    cpu->eax = 0u;
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    lift_store8(cpu->esi, cpu->eax & 0xFFu);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = lift_load32(cpu->eax + 0x34u);
    cpu->edx = lift_load32(cpu->eax + 0x30u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0009D75C;
    cpu->eax = lift_load32(cpu->eax);
    label_0009D75C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D75Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49D766u); lift_push32(cpu, r); sfera_sub_0049D5E0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049D780(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D780u);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, 0.0);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->edx, 0u);
    lift_store_f32(cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    cpu->ecx = 0u;
    lift_x87_push(cpu, 1.0);
    label_0009D7A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D7A6u);
    lift_x87_push(cpu, (double)sfera_zoning_lower_bound(cpu->ecx));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(7u)) goto label_0009D7BC;
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    goto label_0009D7C7;
    label_0009D7BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D7BCu);
    lift_x87_push(cpu, (double)sfera_zoning_upper_bound(cpu->ecx));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0009D7C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D7C7u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0009D7E3;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 3u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (1u)) == 0u) goto label_0009D7F4;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0009D7E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D7E3u);
    ++cpu->ecx;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(8u)) goto label_0009D7A6;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_0009D7F4: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D7F4u);
    cpu->eax = (uint32_t)(cpu->ecx + 1u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esi, cpu->ecx);
    lift_store32(cpu->edx, cpu->eax);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(7u)) goto label_0009D808;
    lift_store32(cpu->edx, 0u);
    label_0009D808: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D808u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049D820(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D820u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1Cu));
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    lift_store_f32(cpu->ecx, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x20u));
    cpu->esi = lift_load32(cpu->esp + 0xCu);
    lift_store_f32(cpu->ecx + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x24u));
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    lift_store_f32(cpu->ecx + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = (uint32_t)(cpu->esi + ((uint32_t)(cpu->esi) * 2u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x28u));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0x28u))));
    cpu->esi = lift_pop32(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x28u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->ecx + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x2Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0x2Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x2Cu))));
    lift_store_f32(cpu->ecx + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x30u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0x30u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x30u))));
    lift_store_f32(cpu->ecx + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x88u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0x88u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x88u))));
    lift_store_f32(cpu->ecx + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x8Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0x8Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x8Cu))));
    lift_store_f32(cpu->ecx + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x90u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0x90u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0x90u))));
    lift_store_f32(cpu->ecx + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0xE8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xE8u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0xE8u))));
    lift_store_f32(cpu->ecx + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0xECu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xECu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0xECu))));
    lift_store_f32(cpu->ecx + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0xF0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax + 0xF0u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->eax + 0xF0u))));
    lift_store_f32(cpu->ecx + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049D910(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49D910u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0009D957;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x10u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx + 4u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 3u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0009D95E;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0009D957: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D957u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_return(cpu, 12u, stop_address); return;
    label_0009D95E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D95Eu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx))));
    lift_x87_set(cpu, 5u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 5u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 4u)); lift_x87_set(cpu, 4u, temporary); }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 3u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0009D983;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_return(cpu, 12u, stop_address); return;
    label_0009D983: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D983u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ecx + 4u))));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 3u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0009D9A9;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_return(cpu, 12u, stop_address); return;
    label_0009D9A9: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D9A9u);
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 3u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0009D9BA;
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0009D9BC;
    label_0009D9BA: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D9BAu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0009D9BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D9BCu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0009D9F2;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0009D9DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D9DDu);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) == 0u) goto label_0009D9F6;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    goto label_0009D9F8;
    label_0009D9F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D9F2u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0009D9DD;
    label_0009D9F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D9F6u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0009D9F8: cpu->eip = LIFT_CODE_TOKEN_VA(0x49D9F8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x18u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    LIFT_X87_POP_STATUS_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x41u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0009DA0B;
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_return(cpu, 12u, stop_address); return;
    label_0009DA0B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DA0Bu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) / (((double)lift_load_f32(cpu->ecx + 0x18u))));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u));
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049DA20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49DA20u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x63E7063Fu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(7u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    cpu->edx = lift_load32(cpu->ecx);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x148u);
    cpu->eax = (uint32_t)(cpu->eax + cpu->esi + 0xFFFFFEB8u);
    lift_store32(cpu->eax + 0xE8u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 0xECu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax + 0xF0u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0xCu);
    cpu->esi = lift_load32(cpu->edx);
    lift_store32(cpu->eax + 0x88u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 0x8Cu, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 8u);
    lift_store32(cpu->eax + 0x90u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx);
    lift_store32(cpu->eax + 0xF4u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 0xF8u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax + 0xFCu, cpu->esi);
    cpu->esi = lift_load32(cpu->edx);
    lift_store32(cpu->eax + 0x94u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 0x98u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 8u);
    lift_store32(cpu->eax + 0x9Cu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx);
    lift_store32(cpu->eax + 0x100u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 0x104u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax + 0x108u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx);
    lift_store32(cpu->eax + 0xA0u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 0xA4u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 8u);
    lift_store32(cpu->eax + 0xA8u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx);
    lift_store32(cpu->eax + 0x10Cu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 0x110u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax + 0x114u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx);
    lift_store32(cpu->eax + 0xACu, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 0xB0u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 8u);
    lift_store32(cpu->eax + 0xB4u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx);
    lift_store32(cpu->eax + 0x118u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 0x11Cu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax + 0x120u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx);
    lift_store32(cpu->eax + 0xB8u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 0xBCu, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 8u);
    lift_store32(cpu->eax + 0xC0u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx);
    lift_store32(cpu->eax + 0x124u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 0x128u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax + 0x12Cu, cpu->esi);
    cpu->esi = lift_load32(cpu->edx);
    lift_store32(cpu->eax + 0xC4u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 0xC8u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 8u);
    lift_store32(cpu->eax + 0xCCu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx);
    lift_store32(cpu->eax + 0x130u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 0x134u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax + 0x138u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx);
    lift_store32(cpu->eax + 0xD0u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 0xD4u, cpu->esi);
    cpu->esi = lift_load32(cpu->edx + 8u);
    lift_store32(cpu->eax + 0xD8u, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx);
    lift_store32(cpu->eax + 0x13Cu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->eax + 0x140u, cpu->esi);
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->eax + 0x144u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx);
    lift_store32(cpu->eax + 0xDCu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->eax + 0xE0u, cpu->ecx);
    cpu->edx = lift_load32(cpu->edx + 8u);
    lift_store32(cpu->eax + 0xE4u, cpu->edx);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049DC00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49DC00u);
    cpu->ecx = lift_load32(cpu->esp + 4u);
    cpu->esp -= 0xCu;
    cpu->eax = 0u;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0009DC56;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(0xC7CE0Cu)) goto label_0009DC28;
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(0x148u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49DC21u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009DC56;
    label_0009DC28: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DC28u);
    cpu->eax = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_store32(cpu->esp + 0x14u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9DC56u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    label_0009DC56: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DC56u);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049DC60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49DC60u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0009DC91;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebx = cpu->ecx;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0009DC70: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DC70u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009DC7F;
    cpu->ecx = 0x52u;
    cpu->esi = cpu->ebx;
    cpu->edi = cpu->eax;
    lift_movs32(cpu, 1u);
    label_0009DC7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DC7Fu);
    cpu->ebx += 0x148u;
    cpu->eax += 0x148u;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(cpu->edx)) goto label_0009DC70;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0009DC91: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DC91u);
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049DCA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49DCA0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0009DCC9;
    lift_push32(cpu, cpu->esi);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0009DCB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DCB0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009DCBE;
    cpu->esi = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->esi);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 4u));
    lift_store_f32(cpu->eax + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0009DCBE: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DCBEu);
    cpu->ecx += 8u;
    cpu->eax += 8u;
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_0009DCB0;
    cpu->esi = lift_pop32(cpu);
    label_0009DCC9: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DCC9u);
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049DCD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49DCD0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    cpu->esi = cpu->ecx;
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(cpu->ebx) <= (uint32_t)(0xC7CE0Cu)) goto label_0009DD13;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x9DD13u);
    label_0009DD13: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DD13u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x63E7063Fu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(7u), 32u);
    cpu->eax = cpu->edx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(0x1Fu), 32u);
    cpu->eax += cpu->edx;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ebx)) goto label_0009DD97;
    cpu->edi = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49DD38u); lift_push32(cpu, r); sfera_sub_0049DC00(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_load32(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->eax);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49DD54u); lift_push32(cpu, r); sfera_sub_0049DC60(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->eax = 0x63E7063Fu;
    lift_multiply_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(7u), 32u);
    cpu->edi = cpu->edx;
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(0x1Fu), 32u);
    cpu->edi += cpu->edx;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0009DD79;
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49DD76u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009DD79: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DD79u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(0x148u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->eax = (int64_t)(int32_t)(cpu->eax) * (int64_t)(int32_t)(0x148u);
    cpu->eax += cpu->ecx;
    cpu->edi += cpu->ecx;
    lift_store32(cpu->esi + 8u, cpu->eax);
    lift_store32(cpu->esi + 4u, cpu->edi);
    lift_store32(cpu->esi, cpu->ecx);
    label_0009DD97: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DD97u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049DDAB(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49DDABu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49DDB4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49DDC0u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x49DDC0u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049DE83(LiftCpu* cpu, uint32_t stop_address) {
    (void)stop_address;
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49DE83u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49DE8Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49DE98u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x49DE98u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0049DEA0(LiftCpu* cpu, uint32_t stop_address) {
    goto label_0009DEA0;
    label_0009DDD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DDD0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(0x1FFFFFFFu)) goto label_0009DE12;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x9DE12u);
    label_0009DE12: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DE12u);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esi)), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->ecx = v; }
    cpu->ecx = lift_shift_arithmetic(cpu, cpu->ecx, (uint32_t)(3u), 32u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->eax)) goto label_0009DE6F;
    cpu->edi = (uint32_t)(cpu->esi + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49DE29u); lift_push32(cpu, r); sfera_sub_00402BB0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->esi);
    cpu->ebx = cpu->eax;
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->ebx);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49DE47u); lift_push32(cpu, r); sfera_sub_0049DCA0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->edi = lift_load32(cpu->esi + 4u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edi = v; }
    cpu->edi = lift_shift_arithmetic(cpu, cpu->edi, (uint32_t)(3u), 32u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009DE5E;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49DE5Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009DE5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DE5Eu);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->edx = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->ecx) * 8u));
    cpu->eax = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->edi) * 8u));
    lift_store32(cpu->esi + 8u, cpu->edx);
    lift_store32(cpu->esi + 4u, cpu->eax);
    lift_store32(cpu->esi, cpu->ebx);
    label_0009DE6F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DE6Fu);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0009DEA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DEA0u);
    cpu->eax = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->edi);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->edi = 0x1FFFFFFFu;
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(3u), 32u);
    cpu->edi -= cpu->edx;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_0009DEC6;
    lift_push32(cpu, (uint32_t)(uintptr_t)"vector<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x9DEC6u);
    label_0009DEC6: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DEC6u);
    cpu->eax += cpu->edx;
    cpu->edx = lift_load32(cpu->ecx + 8u);
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->edx = v; }
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(3u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0009DEFA;
    cpu->esi = cpu->edx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(1u), 32u);
    cpu->edi = 0x1FFFFFFFu;
    cpu->edi -= cpu->esi;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->edx)) goto label_0009DEE7;
    cpu->edx = 0u;
    goto label_0009DEE9;
    label_0009DEE7: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DEE7u);
    cpu->edx += cpu->esi;
    label_0009DEE9: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DEE9u);
    if ((uint32_t)(cpu->edx) >= (uint32_t)(cpu->eax)) goto label_0009DEEF;
    cpu->edx = cpu->eax;
    label_0009DEEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DEEFu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->esp + 4u, cpu->edx);
    goto label_0009DDD0;
    label_0009DEFA: cpu->eip = LIFT_CODE_TOKEN_VA(0x49DEFAu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}
