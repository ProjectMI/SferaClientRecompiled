#include "lifted_functions.h"
#include "lifted_normalized_ops.h"

#include <math.h>

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048B970(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48B970u);
    cpu->esp -= 0x30u;
    lift_x87_push(cpu, (double)3.4028234663852886e+38f);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x40u);
    cpu->ebx = cpu->ecx;
    cpu->ecx = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->ebp = cpu->edx;
    lift_store32(cpu->esp + 0x3Cu, cpu->ebx);
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(4u)) goto label_0008BA17;
    cpu->esi += 0xFFFFFFFDu;
    cpu->edx = (uint32_t)(cpu->ebp + 0xCu);
    cpu->edi = cpu->edi;
    label_0008B9A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B9A0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0xFFFFFFF8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0008B9B9;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0xFFFFFFF8u));
    cpu->edi = cpu->ecx;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008B9B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B9B9u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0008B9D1;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    cpu->edi = (uint32_t)(cpu->ecx + 1u);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008B9D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B9D1u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0008B9EB;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 8u));
    cpu->edi = (uint32_t)(cpu->ecx + 2u);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008B9EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x48B9EBu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x10u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0008BA05;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx + 0x10u));
    cpu->edi = (uint32_t)(cpu->ecx + 3u);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008BA05: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BA05u);
    cpu->ecx += 4u;
    cpu->edx += 0x20u;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(cpu->esi)) goto label_0008B9A0;
    cpu->esi = lift_load32(cpu->esp + 0x44u);
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    label_0008BA17: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BA17u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->esi)) goto label_0008BA49;
    cpu->edx = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->ecx) * 8u) + 4u);
    (void)cpu;
    label_0008BA20: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BA20u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    LIFT_X87_COMPARE_POP2_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0008BA37;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edx));
    cpu->edi = cpu->ecx;
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008BA37: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BA37u);
    ++cpu->ecx;
    cpu->edx += 8u;
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x44u))) goto label_0008BA20;
    cpu->esi = lift_load32(cpu->esp + 0x44u);
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    label_0008BA49: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BA49u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48BA5Au); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0008BA6A;
    lift_store32(cpu->esp + 0x14u, 0u);
    label_0008BA6A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BA6Au);
    lift_x87_push(cpu, 0.0);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u));
    --cpu->eax;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x44u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u));
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store8(cpu->esp + 0x13u, 0u);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0008BDA0;
    lift_x87_push(cpu, 6.018531076210112e-36);
    lift_x87_push(cpu, 0.5);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    goto label_0008BAB3;
    label_0008BAAF: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BAAFu);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    label_0008BAB3: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BAB3u);
    if ((int32_t)(uint32_t)(cpu->eax) > (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_0008BB3F;
    goto label_0008BAC1;
    label_0008BABF: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BABFu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0008BAC1: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BAC1u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x1Cu)) <= (int32_t)(uint32_t)(0u)) goto label_0008BC68;
    cpu->esi = (uint32_t)(cpu->edi + 0xFFFFFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0008BADA;
    cpu->esi = lift_load32(cpu->esp + 0x44u);
    --cpu->esi;
    label_0008BADA: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BADAu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + ((uint32_t)(cpu->esi) * 8u) + 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48BAE3u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x4Cu);
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ecx) <= (int32_t)(uint32_t)(cpu->eax)) goto label_0008BAF7;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    cpu->ecx = cpu->eax;
    label_0008BAF7: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BAF7u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + ((uint32_t)(cpu->esi) * 8u)));
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) - 1u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + ((uint32_t)(cpu->edi) * 8u)))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + ((uint32_t)(cpu->esi) * 8u) + 4u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + ((uint32_t)(cpu->edi) * 8u) + 4u))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + ((uint32_t)(cpu->edi) * 8u) + 4u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + ((uint32_t)(cpu->edi) * 8u)));
    cpu->edi = cpu->esi;
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->ecx) <= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_0008BABF;
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    label_0008BB3F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BB3Fu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x24u)) > (int32_t)(uint32_t)(cpu->eax)) goto label_0008BBC4;
    label_0008BB49: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BB49u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x1Cu)) <= (int32_t)(uint32_t)(0u)) goto label_0008BBC4;
    cpu->esi = lift_load32(cpu->esp + 0x30u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x44u))) goto label_0008BB5F;
    cpu->esi = 0u;
    label_0008BB5F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BB5Fu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + ((uint32_t)(cpu->esi) * 8u) + 4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48BB68u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x4Cu);
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(cpu->eax)) goto label_0008BB7C;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    cpu->edx = cpu->eax;
    label_0008BB7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BB7Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + ((uint32_t)(cpu->esi) * 8u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebp + ((uint32_t)(cpu->ecx) * 8u)))));
    cpu->eax = (uint32_t)(cpu->ebp + ((uint32_t)(cpu->ecx) * 8u) + 4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + ((uint32_t)(cpu->esi) * 8u) + 4u));
    lift_store32(cpu->esp + 0x1Cu, (uint64_t)(lift_load32(cpu->esp + 0x1Cu)) - 1u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax))));
    lift_store32(cpu->esp + 0x30u, cpu->esi);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) / lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x14u)))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->eax))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + ((uint32_t)(cpu->ecx) * 8u)));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->edx) <= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_0008BB49;
    label_0008BBC4: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BBC4u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x20u))) goto label_0008BCF8;
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 2u));
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    label_0008BBDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BBDFu);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x14u)) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_0008BCF8;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x34u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48BBF8u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x38u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48BC05u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, lift_x87_get(cpu, 3u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_0008BC1B;
    cpu->esi = 0u;
    label_0008BC1B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BC1Bu);
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(cpu->ecx)) goto label_0008BC26;
    cpu->eax = (uint32_t)(cpu->ecx + 0xFFFFFFFFu);
    label_0008BC26: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BC26u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx += g_sfera_shadow_runtime.span_records;
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) + 1u);
    lift_store32(cpu->esp + 0x2Cu, (uint64_t)(lift_load32(cpu->esp + 0x2Cu)) + (uint64_t)(0x18u) + (uint64_t)(0u));
    if ((int32_t)(uint32_t)(cpu->esi) > (int32_t)(uint32_t)(cpu->eax)) goto label_0008BCEA;
    cpu->edx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->edx) != (uint32_t)(0x7FFFFFFFu)) goto label_0008BC71;
    lift_store32(cpu->ecx, cpu->esi);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    lift_store32(cpu->ecx + 8u, cpu->ebx);
    cpu->eax = g_sfera_shadow_runtime.manager;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008BCEA;
    lift_store8(cpu->eax, 1u);
    goto label_0008BCEA;
    label_0008BC68: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BC68u);
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    goto label_0008BB3F;
    label_0008BC71: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BC71u);
    cpu->edi = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebx)) goto label_0008BC90;
    lift_store32(cpu->ecx + 0xCu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->ecx + 0x10u, cpu->edx);
    lift_store32(cpu->ecx + 0x14u, cpu->edi);
    lift_store32(cpu->ecx, cpu->esi);
    lift_store32(cpu->ecx + 8u, cpu->ebx);
    lift_store8(cpu->esp + 0x13u, 1u);
    goto label_0008BCE3;
    label_0008BC90: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BC90u);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->edx)) goto label_0008BCBB;
    lift_store32(cpu->ecx, cpu->esi);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->edx)) goto label_0008BCAD;
    lift_store32(cpu->ecx + 0xCu, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    lift_store32(cpu->ecx + 0x10u, cpu->edx);
    lift_store32(cpu->ecx + 0x14u, cpu->edi);
    lift_store8(cpu->esp + 0x13u, 1u);
    goto label_0008BCE3;
    label_0008BCAD: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BCADu);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(lift_load32(cpu->ecx + 4u))) goto label_0008BCEA;
    lift_store32(cpu->ecx + 4u, cpu->eax);
    goto label_0008BCEA;
    label_0008BCBB: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BCBBu);
    cpu->ebx = lift_load32(cpu->ecx + 4u);
    if ((int32_t)(uint32_t)(cpu->esi) <= (int32_t)(uint32_t)(cpu->ebx)) goto label_0008BCDB;
    lift_store32(cpu->ecx + 0x10u, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->ecx + 0xCu, cpu->edx);
    lift_store32(cpu->ecx + 0x14u, cpu->edi);
    lift_store32(cpu->ecx, cpu->esi);
    lift_store32(cpu->ecx + 8u, cpu->ebx);
    lift_store8(cpu->esp + 0x13u, 1u);
    goto label_0008BCE3;
    label_0008BCDB: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BCDBu);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ebx = lift_load32(cpu->esp + 0x3Cu);
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0008BCE6;
    label_0008BCE3: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BCE3u);
    lift_store32(cpu->ecx + 4u, cpu->eax);
    label_0008BCE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BCE6u);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    label_0008BCEA: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BCEAu);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x14u)) < (int32_t)(uint32_t)(cpu->eax)) goto label_0008BBDF;
    label_0008BCF8: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BCF8u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x1Cu)) > (int32_t)(uint32_t)(0u)) goto label_0008BAAF;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x13u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0008BDA0;
    cpu->eax = lift_load32(cpu->esp + 0x4Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    cpu->ebx = lift_load32(cpu->ecx + 4u);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_0008BDA0;
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x44u, cpu->ebp);
    lift_store32(cpu->esp + 0x4Cu, cpu->eax);
    label_0008BD33: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BD33u);
    cpu->eax = g_sfera_shadow_runtime.span_records;
    cpu->edx = lift_load32(cpu->eax + cpu->ebp + 0x10u);
    cpu->edi = lift_load32(cpu->eax + cpu->ebp + 0xCu);
    cpu->esi = (uint32_t)(cpu->eax + cpu->ebp + 0x10u);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->ebp + 0xCu);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0008BD85;
    cpu->edx -= cpu->edi;
    ++cpu->edx;
    cpu->eax = 0u;
    { uint64_t v=(uint64_t)(cpu->edx); lift_flags_logic(cpu,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0008BD79;
    cpu->edx = g_sfera_shadow_runtime.span_records;
    cpu->edx = (uint32_t)(cpu->edx + cpu->ebp + 0x14u);
    (void)cpu;
    label_0008BD60: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BD60u);
    cpu->edi = lift_load32(cpu->ecx);
    cpu->ebp = (cpu->ebp & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->edx)) & 0xFFFFu);
    cpu->edi += cpu->eax;
    lift_store16(cpu->ebx + ((uint32_t)(cpu->edi) * 2u), cpu->ebp & 0xFFFFu);
    cpu->edi = lift_load32(cpu->esi);
    cpu->edi -= lift_load32(cpu->ecx);
    ++cpu->eax;
    ++cpu->edi;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0008BD60;
    cpu->ebp = lift_load32(cpu->esp + 0x44u);
    label_0008BD79: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BD79u);
    lift_store32(cpu->ecx, 0x7FFFFFFFu);
    lift_store32(cpu->esi, 0x80000000u);
    label_0008BD85: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BD85u);
    cpu->eax = lift_load32(cpu->esp + 0x50u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    cpu->edx = cpu->ecx & 0xFFFFu;
    cpu->ebp += 0x18u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x4Cu)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x4Cu, v); }
    cpu->ebx = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->edx) * 2u));
    lift_store32(cpu->esp + 0x44u, cpu->ebp);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008BD33;
    label_0008BDA0: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BDA0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048BDB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48BDB0u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 4u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_0008BE2F;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = 0u;
    cpu->ecx = cpu->eax;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0008BDD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BDD0u);
    cpu->eax = g_sfera_shadow_runtime.span_records;
    cpu->edi = lift_load32(cpu->eax + cpu->ebp);
    cpu->edx = lift_load32(cpu->eax + cpu->ebp + 4u);
    cpu->eax += cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) == 0u) goto label_0008BE14;
    cpu->edx -= cpu->edi;
    ++cpu->edx;
    cpu->esi = 0u;
    { uint64_t v=(uint64_t)(cpu->edx); lift_flags_logic(cpu,v,32u); }
    if (((cpu->eflags & LIFT_FLAG_ZF) != 0u) || ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u)) goto label_0008BE07;
    label_0008BDF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BDF0u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->edi = (cpu->edi & 0xFFFF0000u) | ((uint32_t)(lift_load16(cpu->eax + 8u)) & 0xFFFFu);
    cpu->edx += cpu->esi;
    lift_store16(cpu->ebx + ((uint32_t)(cpu->edx) * 2u), cpu->edi & 0xFFFFu);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->edx -= lift_load32(cpu->eax);
    ++cpu->esi;
    ++cpu->edx;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((((cpu->eflags >> 7u) ^ (cpu->eflags >> 11u)) & 1u) != 0u) goto label_0008BDF0;
    label_0008BE07: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BE07u);
    lift_store32(cpu->eax, 0x7FFFFFFFu);
    lift_store32(cpu->eax + 4u, 0x80000000u);
    label_0008BE14: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BE14u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->edx = lift_load32(cpu->eax);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(1u), 32u);
    cpu->eax = cpu->edx & 0xFFFFu;
    cpu->ebp += 0x18u;
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    cpu->ebx = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->eax) * 2u));
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008BDD0;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_0008BE2F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BE2Fu);
    lift_store8(cpu->ecx, 0u);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048BE40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48BE40u);
    cpu->esp -= 0x114u;
    cpu->eax = lift_load32(cpu->esp + 0x120u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x124u);
    cpu->ebx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x138u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x30u, cpu->ebp);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x34u, cpu->ecx);
    if ((uint32_t)(g_sfera_shadow_runtime.projected_point_capacity) >= (uint32_t)(cpu->ebp)) goto label_0008BEDC;
    cpu->edx = 0x18Bu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\shadow.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48BE98u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_shadow_runtime.projected_points;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48BEA4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->edx = 0x18Cu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\shadow.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48BEB6u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_flags_logic(cpu,0u,32u); cpu->ecx = 0u;
    cpu->eax = cpu->ebp;
    cpu->edx = 8u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48BECEu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    g_sfera_shadow_runtime.projected_points = (uint32_t)(cpu->eax);
    g_sfera_shadow_runtime.projected_point_capacity = (uint32_t)(cpu->ebp);
    label_0008BEDC: cpu->eip = LIFT_CODE_TOKEN_VA(0x48BEDCu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x148u));
    cpu->ecx = 0x10u;
    cpu->edi = (uint32_t)(cpu->esp + 0x38u);
    lift_movs32(cpu, 1u);
    cpu->ecx = 0x10u;
    cpu->esi = (uint32_t)(cpu->esp + 0x144u);
    cpu->edi = (uint32_t)(cpu->esp + 0x78u);
    lift_movs32(cpu, 1u);
    lift_store_f32(cpu->esp + 0x154u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x80u));
    lift_store_f32(cpu->esp + 0x164u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x84u));
    lift_store_f32(cpu->esp + 0x174u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x88u));
    lift_store_f32(cpu->esp + 0x148u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x8Cu));
    lift_store_f32(cpu->esp + 0x158u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x90u));
    lift_store_f32(cpu->esp + 0x168u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x94u));
    cpu->eax = (uint32_t)(cpu->esp + 0xC8u);
    lift_store_f32(cpu->esp + 0x178u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax &= 0xFFFFFFF0u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x98u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x144u);
    lift_store_f32(cpu->esp + 0x14Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->ecx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xA0u));
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_store_f32(cpu->esp + 0x160u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = cpu->eax;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xA4u));
    lift_store32(cpu->esp + 0xBCu, cpu->eax);
    lift_store_f32(cpu->esp + 0x170u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xA8u));
    lift_store_f32(cpu->esp + 0x180u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xACu));
    lift_store_f32(cpu->esp + 0x154u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB0u));
    lift_store_f32(cpu->esp + 0x164u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB4u));
    lift_store_f32(cpu->esp + 0x174u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xB8u));
    lift_store_f32(cpu->esp + 0x184u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48BFEFu); lift_push32(cpu, r); sfera_sub_004822F0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x138u);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x138u)))));
    cpu->esi = lift_load32(cpu->esp + 0xB8u);
    if ((int32_t)(uint32_t)(cpu->edx) >= 0) goto label_0008C00E;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0008C00E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C00Eu);
    cpu->eax = lift_load32(cpu->esp + 0x13Cu);
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x13Cu)))));
    if ((int32_t)(uint32_t)(cpu->eax) >= 0) goto label_0008C02A;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)4294967296.0f)));
    label_0008C02A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C02Au);
    cpu->edx = lift_load32(cpu->esp + 0x128u);
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->ecx = 0u;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    cpu->eax = 0u;
    lift_x87_push(cpu, 0.5);
    if ((int32_t)(uint32_t)(cpu->ebp) < (int32_t)(uint32_t)(4u)) goto label_0008C2F3;
    cpu->edi = (uint32_t)(cpu->esi + 8u);
    lift_store32(cpu->esp + 0x28u, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0xCu);
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x14u);
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x10u);
    lift_store32(cpu->esp + 0x24u, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x18u);
    lift_store32(cpu->esp + 0x18u, cpu->edi);
    cpu->edi = (uint32_t)(cpu->esi + 0x1Cu);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    label_0008C07A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C07Au);
    cpu->edi = lift_load32(cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    cpu->ebp = lift_load32(cpu->edi + cpu->eax);
    lift_store32(cpu->esp + 0x108u, cpu->ebp);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x108u));
    cpu->ebp = lift_load32(cpu->edi + cpu->eax + 4u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_load32(cpu->edi + cpu->eax + 8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_store32(cpu->esp + 0x110u, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x10Cu, cpu->ebp);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x110u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi))));
    cpu->edi = g_sfera_shadow_runtime.projected_points;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_store_f32(cpu->edi + ((uint32_t)(cpu->ecx) * 8u), lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_load32(cpu->esp + 0x24u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi))));
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x110u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi))));
    cpu->edi = g_sfera_shadow_runtime.projected_points;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->edi + ((uint32_t)(cpu->ecx) * 8u) + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax += lift_load32(cpu->edx + 4u);
    cpu->edi = lift_load32(cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    cpu->ebp = lift_load32(cpu->edi + cpu->eax);
    lift_store32(cpu->esp + 0x108u, cpu->ebp);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x108u));
    cpu->ebp = lift_load32(cpu->edi + cpu->eax + 4u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->edi = lift_load32(cpu->edi + cpu->eax + 8u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_store32(cpu->esp + 0x10Cu, cpu->ebp);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10Cu));
    lift_store32(cpu->esp + 0x110u, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x28u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x110u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi))));
    cpu->edi = g_sfera_shadow_runtime.projected_points;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_store_f32(cpu->edi + ((uint32_t)(cpu->ecx) * 8u) + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_load32(cpu->esp + 0x24u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi))));
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x110u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi))));
    cpu->edi = g_sfera_shadow_runtime.projected_points;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->edi + ((uint32_t)(cpu->ecx) * 8u) + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax += lift_load32(cpu->edx + 4u);
    cpu->edi = lift_load32(cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    cpu->ebp = lift_load32(cpu->edi + cpu->eax);
    lift_store32(cpu->esp + 0x108u, cpu->ebp);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x108u));
    cpu->ebp = lift_load32(cpu->edi + cpu->eax + 4u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->edi = lift_load32(cpu->edi + cpu->eax + 8u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_store32(cpu->esp + 0x110u, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x10Cu, cpu->ebp);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x110u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi))));
    cpu->edi = g_sfera_shadow_runtime.projected_points;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_store_f32(cpu->edi + ((uint32_t)(cpu->ecx) * 8u) + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_load32(cpu->esp + 0x24u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi))));
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x110u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi))));
    cpu->edi = g_sfera_shadow_runtime.projected_points;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->edi + ((uint32_t)(cpu->ecx) * 8u) + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax += lift_load32(cpu->edx + 4u);
    cpu->edi = lift_load32(cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    cpu->ebp = lift_load32(cpu->edi + cpu->eax);
    lift_store32(cpu->esp + 0x108u, cpu->ebp);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x108u));
    cpu->ebp = lift_load32(cpu->edi + cpu->eax + 4u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->edi = lift_load32(cpu->edi + cpu->eax + 8u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_store32(cpu->esp + 0x10Cu, cpu->ebp);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10Cu));
    lift_store32(cpu->esp + 0x110u, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x28u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x110u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi))));
    cpu->edi = g_sfera_shadow_runtime.projected_points;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_store_f32(cpu->edi + ((uint32_t)(cpu->ecx) * 8u) + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = lift_load32(cpu->esp + 0x24u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->edi))));
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_load32(cpu->esp + 0x30u);
    cpu->ecx += 4u;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->edi));
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x110u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->edi))));
    cpu->edi = g_sfera_shadow_runtime.projected_points;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->edi + ((uint32_t)(cpu->ecx) * 8u) + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax += lift_load32(cpu->edx + 4u);
    cpu->edi = (uint32_t)(cpu->ebp + 0xFFFFFFFDu);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->edi)) goto label_0008C07A;
    label_0008C2F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C2F3u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_0008C390;
    label_0008C2FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C2FBu);
    cpu->edi = lift_load32(cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi));
    cpu->ebx = lift_load32(cpu->edi + cpu->eax);
    lift_store32(cpu->esp + 0x108u, cpu->ebx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x108u));
    cpu->ebx = lift_load32(cpu->edi + cpu->eax + 4u);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->edi = lift_load32(cpu->edi + cpu->eax + 8u);
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 4u));
    lift_store32(cpu->esp + 0x10Cu, cpu->ebx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10Cu));
    lift_store32(cpu->esp + 0x110u, cpu->edi);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    cpu->edi = g_sfera_shadow_runtime.projected_points;
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    ++cpu->ecx;
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 8u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x110u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0xCu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 3u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 5u)));
    lift_store_f32(cpu->edi + ((uint32_t)(cpu->ecx) * 8u) + 0xFFFFFFF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi = g_sfera_shadow_runtime.projected_points;
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esi + 0x10u))));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x14u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0x18u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->esp + 0x110u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esi + 0x1Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (lift_x87_get(cpu, 1u)));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->edi + ((uint32_t)(cpu->ecx) * 8u) + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax += lift_load32(cpu->edx + 4u);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebp), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0008C2FB;
    cpu->ebx = lift_load32(cpu->esp + 0x2Cu);
    label_0008C390: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C390u);
    cpu->eax = lift_load32(cpu->esp + 0x134u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = cpu->ebx;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp = lift_shift_right(cpu, cpu->ebp, (uint32_t)(3u), 32u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ebp &= 0x1F0000u;
    cpu->ecx = cpu->ebx;
    cpu->ecx &= 0xFC00u;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->ecx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    cpu->ebp = lift_shift_right(cpu, cpu->ebp, (uint32_t)(2u), 32u);
    cpu->ebx &= 0xF8u;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->ebx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->ebp = v; }
    cpu->ebp = lift_shift_right(cpu, cpu->ebp, (uint32_t)(3u), 32u);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0008C54C;
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->esi = g_sfera_shadow_runtime.projected_points;
    cpu->edx = (uint32_t)(cpu->eax + 0xFFFFFFFFu);
    cpu->eax = 0xAAAAAAABu;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ebx = cpu->edx;
    cpu->ebx = lift_shift_right(cpu, cpu->ebx, (uint32_t)(1u), 32u);
    cpu->edi += 4u;
    ++cpu->ebx;
    label_0008C3E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C3E4u);
    cpu->eax = lift_load16(cpu->edi + 0xFFFFFFFCu);
    cpu->ecx = lift_load32(cpu->esi + ((uint32_t)(cpu->eax) * 8u));
    cpu->edx = lift_load32(cpu->esi + ((uint32_t)(cpu->eax) * 8u) + 4u);
    cpu->eax = lift_load16(cpu->edi + 0xFFFFFFFEu);
    lift_store32(cpu->esp + 0x108u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + ((uint32_t)(cpu->eax) * 8u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x108u));
    lift_store32(cpu->esp + 0x10Cu, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + ((uint32_t)(cpu->eax) * 8u) + 4u);
    cpu->eax = lift_load16(cpu->edi);
    lift_store32(cpu->esp + 0x110u, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + ((uint32_t)(cpu->eax) * 8u));
    lift_store32(cpu->esp + 0x114u, cpu->edx);
    cpu->edx = lift_load32(cpu->esi + ((uint32_t)(cpu->eax) * 8u) + 4u);
    lift_store32(cpu->esp + 0x118u, cpu->ecx);
    lift_store32(cpu->esp + 0x11Cu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C43Au); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_store_f32(cpu->esp + 0x108u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10Cu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C455u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_store_f32(cpu->esp + 0x10Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x110u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C470u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_store_f32(cpu->esp + 0x110u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x114u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C48Bu); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_store_f32(cpu->esp + 0x114u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x118u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C4A6u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_store_f32(cpu->esp + 0x118u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x11Cu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C4C1u); lift_push32(cpu, r); sfera_sub_004EE940(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_x87_push(cpu, (double)(((int32_t)(lift_load32(cpu->esp + 0x10u)))));
    lift_store_f32(cpu->esp + 0x11Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x11Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x110u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x108u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) - lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x114u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x118u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 3u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    LIFT_X87_COMPARE_POP2_AX();
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0008C542;
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    cpu->ecx = lift_load32(cpu->esp + 0x13Cu);
    cpu->edx = lift_load32(cpu->esp + 0x138u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, 3u);
    cpu->edx = (uint32_t)(cpu->esp + 0x118u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C53Cu); lift_push32(cpu, r); sfera_sub_0048B970(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = g_sfera_shadow_runtime.projected_points;
    label_0008C542: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C542u);
    cpu->edi += 6u;
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008C3E4;
    label_0008C54C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C54Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x114u;
    lift_return(cpu, 92u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048C570(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48C570u);
    lift_x87_push(cpu, 1.0);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    lift_store_f32(cpu->esi + 0x9Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi |= 0xFFFFFFFFu;
    cpu->edx = 0x231u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\shadow.cpp";
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    lift_store32(cpu->esi + 4u, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, cpu->ebx);
    lift_store16(cpu->esi + 0xA0u, cpu->ebx & 0xFFFFu);
    lift_store32(cpu->esi + 0xA4u, cpu->ebx);
    lift_store32(cpu->esi + 0xA8u, cpu->edi);
    lift_store32(cpu->esi + 0xC4u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C5BAu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x7D4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C5C4u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->edx = 0x232u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\shadow.cpp";
    lift_store32(cpu->esi + 0xCCu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C5DCu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x36CCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C5E6u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->edx = 0x235u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\shadow.cpp";
    lift_store32(cpu->esi + 0xC8u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C5FEu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x1800u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C608u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    g_sfera_shadow_runtime.span_records = (uint32_t)(cpu->eax);
    cpu->eax = 0u;
    cpu->edx = 0x7FFFFFFFu;
    cpu->ecx = 0x80000000u;
    cpu->esp = (uint32_t)(cpu->esp);
    label_0008C620: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C620u);
    cpu->ebp = g_sfera_shadow_runtime.span_records;
    lift_store32(cpu->eax + cpu->ebp + 0xCu, cpu->edx);
    cpu->ebp = g_sfera_shadow_runtime.span_records;
    lift_store32(cpu->eax + cpu->ebp, cpu->edx);
    cpu->ebp = g_sfera_shadow_runtime.span_records;
    lift_store32(cpu->eax + cpu->ebp + 0x10u, cpu->ecx);
    cpu->ebp = g_sfera_shadow_runtime.span_records;
    lift_store32(cpu->eax + cpu->ebp + 4u, cpu->ecx);
    cpu->ebp = g_sfera_shadow_runtime.span_records;
    lift_store32(cpu->eax + cpu->ebp + 8u, cpu->edi);
    cpu->ebp = g_sfera_shadow_runtime.span_records;
    lift_store32(cpu->eax + cpu->ebp + 0x14u, cpu->edi);
    cpu->eax += 0x18u;
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x1800u)) goto label_0008C620;
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048C670(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48C670u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->esi = (uint32_t)(cpu->ebx + 4u);
    cpu->edi = 3u;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_0008C680: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C680u);
    cpu->eax = lift_load32(cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008C694;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x8C68Eu), LIFT_CODE_TOKEN_RVA(0x8C68Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48C68Eu);
    lift_store32(cpu->esi, 0u);
    label_0008C694: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C694u);
    cpu->esi += 4u;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008C680;
    cpu->ecx = 0x2A000u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C6A4u); lift_push32(cpu, r); sfera_sub_00499F50(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->ebx + 0xCCu)) == (uint32_t)(cpu->edi)) goto label_0008C6CA;
    cpu->edx = 0x259u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\shadow.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C6BBu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebx + 0xCCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C6C7u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008C6CA: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C6CAu);
    if ((uint32_t)(lift_load32(cpu->ebx + 0xC8u)) == (uint32_t)(0u)) goto label_0008C6F1;
    cpu->edx = 0x25Bu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\shadow.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C6E2u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 0xC8u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C6EEu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008C6F1: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C6F1u);
    cpu->edx = 0x25Du;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\shadow.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C700u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = g_sfera_shadow_runtime.span_records;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C70Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->edx = 0x25Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\shadow.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C71Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_shadow_runtime.projected_points;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C729u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048C730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48C730u);
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = (uint32_t)(cpu->edi + 4u);
    cpu->ebx = cpu->esi;
    cpu->ebp = 3u;
    cpu->edi = cpu->edi;
    label_0008C750: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C750u);
    cpu->eax = lift_load32(cpu->ebx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008C764;
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x8C75Eu), LIFT_CODE_TOKEN_RVA(0x8C75Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48C75Eu);
    lift_store32(cpu->ebx, 0u);
    label_0008C764: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C764u);
    cpu->ebx += 4u;
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008C750;
    cpu->ecx = 0x2A000u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C774u); lift_push32(cpu, r); sfera_sub_00499EF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u); lift_push32(cpu, 0x17u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 1u); lift_push32(cpu, 0x100u); lift_push32(cpu, 0x100u); lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C792u); lift_push32(cpu, r); sfera_sub_004D8E70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = (uint32_t)(cpu->edi + 8u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, 0x17u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 1u); lift_push32(cpu, 0x80u); lift_push32(cpu, 0x80u); lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C7B3u); lift_push32(cpu, r); sfera_sub_004D8E70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->edi + 0xCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x17u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 1u); lift_push32(cpu, 0x40u); lift_push32(cpu, 0x40u); lift_push32(cpu, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C7CEu); lift_push32(cpu, r); sfera_sub_004D8E70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(uintptr_t)"shadspot";
    lift_store32(cpu->edi + 0x10u, cpu->ebp);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C7DBu); lift_push32(cpu, r); sfera_sub_00499D70(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->edi + 0x18u, cpu->eax);
    cpu->edi = (uint32_t)(cpu->ebp + 4u);
    label_0008C7E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C7E1u);
    if ((uint32_t)(lift_load32(cpu->esi)) == (uint32_t)(0u)) goto label_0008C839;
    cpu->eax = lift_load32(cpu->esi);
    cpu->edx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edx + 0x4Cu);
    lift_push32(cpu, 0x800u); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x8C7FEu), LIFT_CODE_TOKEN_RVA(0x8C7FCu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48C7FEu);
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x44u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x8C80Fu), LIFT_CODE_TOKEN_RVA(0x8C80Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48C80Fu);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(lift_load32(cpu->esp + 0x34u));
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0xFFFFu); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x48C825u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48C82Au);
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->ecx + 0x50u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x8C839u), LIFT_CODE_TOKEN_RVA(0x8C837u))) { return; }
    label_0008C839: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C839u);
    cpu->esi += 4u;
    { uint64_t l=(uint64_t)(cpu->edi), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008C7E1;
    cpu->eax = (uint32_t)(cpu->edi + 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048C860(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48C860u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_store_f32(cpu->esi + 0x9Cu, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->edi);
    lift_x87_push(cpu, 1.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 1u));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(5u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) != 0u) goto label_0008C886;
    lift_store_f32(cpu->esi + 0x9Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0008C888;
    label_0008C886: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C886u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008C888: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C888u);
    lift_x87_push(cpu, 0.0);
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), ((double)lift_load_f32(cpu->esi + 0x9Cu)));
    cpu->eax = (cpu->eax & 0xFFFF0000u) | ((uint32_t)((uint16_t)(cpu->fpu_status | ((cpu->fpu_top & 7u) << 11u))) & 0xFFFFu);
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0008C89F;
    lift_store_f32(cpu->esi + 0x9Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0008C8A1;
    label_0008C89F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C89Fu);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008C8A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C8A1u);
    lift_push32(cpu, 0x40u);
    cpu->edi = (uint32_t)(cpu->esi + 0x5Cu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x48C8A9u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48C8AEu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->edi + 0x3Cu, lift_x87_get(cpu, 0u));
    cpu->esp += 0xCu;
    lift_store_f32(cpu->edi + 0x28u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edi + 0x14u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((uint8_t)(lift_load8(cpu->esi + 0xA0u)) != (uint8_t)(3u)) goto label_0008C913;
    lift_x87_push(cpu, 0.0);
    cpu->edi = lift_pop32(cpu);
    lift_store_f32(cpu->esi + 0x70u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)-1.0f);
    lift_store_f32(cpu->esi + 0x80u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esi + 0x74u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_store_f32(cpu->esi + 0x84u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u));
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esi + 0xACu, cpu->eax);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esi + 0xB0u, cpu->ecx);
    lift_store32(cpu->esi + 0xB4u, cpu->edx);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 8u, stop_address); return;
    label_0008C913: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C913u);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->ecx = lift_load32(cpu->eax);
    lift_store32(cpu->esi + 0xACu, cpu->ecx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esi + 0xB0u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esi + 0xB4u, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xB0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), -0.10000000149011612);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0008C950;
    lift_x87_push(cpu, (double)-0.10000000149011612f);
    lift_store_f32(cpu->esi + 0xB0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008C950: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C950u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xB0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xACu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xB4u));
    lift_x87_push(cpu, lift_x87_get(cpu, 1u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 2u));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 0u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C97Fu); lift_push32(cpu, r); sfera_sub_004EE9EC(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xACu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esi + 0xB4u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C99Cu); lift_push32(cpu, r); sfera_sub_004EEC4E(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), lift_x87_get(cpu, 2u));
    LIFT_X87_POP_STATUS_AX();
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint64_t l=(uint64_t)(((cpu->eax >> 8u) & 0xFFu)), r=(uint64_t)(0x44u), v=l & r; lift_flags_logic(cpu,v,8u); }
    if ((cpu->eflags & LIFT_FLAG_PF) == 0u) goto label_0008C9E2;
    lift_x87_set(cpu, 0u, (((double)lift_load_f32(cpu->esi + 0xB0u))) / (lift_x87_get(cpu, 0u)));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48C9D4u); lift_push32(cpu, r); sfera_sub_004EED6C(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0008C9E4;
    label_0008C9E2: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C9E2u);
    lift_x87_set(cpu, 0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008C9E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C9E4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_x87_compare(cpu, lift_x87_get(cpu, 0u), -0.7853982448577881);
    LIFT_X87_POP_STATUS_AX();
    if ((uint8_t)((((cpu->eax >> 8u) & 0xFFu)) & (0x41u)) != 0u) goto label_0008C9FF;
    lift_x87_push(cpu, (double)-0.7853982448577881f);
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008C9FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x48C9FFu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f64(cpu->esp + 0x10u, lift_x87_get(cpu, 0u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48CA0Cu); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0x10u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48CA19u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu));
    lift_store_f64(cpu->esp + 0x18u, lift_x87_get(cpu, 0u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48CA2Au); lift_push32(cpu, r); sfera_sub_004EE9F8(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_load_f64(cpu->esp + 0x18u));
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48CA37u); lift_push32(cpu, r); sfera_sub_004EE9F2(cpu,r); if (cpu->eip != r) return; }
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_store_f32(cpu->edi, lift_x87_get(cpu, 0u));
    cpu->edi = lift_pop32(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 4u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x6Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x7Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x70u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_store_f32(cpu->esi + 0x80u, lift_x87_get(cpu, 0u));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->esi + 0x64u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_store_f32(cpu->esi + 0x74u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esi + 0x84u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048CA90(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48CA90u);
    cpu->esp -= 0x4Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x5Cu);
    cpu->eax = lift_load32(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x64u);
    cpu->ebx = cpu->ecx;
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48CABBu); lift_push32(cpu, r); sfera_sub_0047F4D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    if ((uint32_t)(cpu->edi) == 0u) goto label_0008CACF;
    cpu->edx = lift_load32(cpu->edi + 4u);
    cpu->ecx = lift_load32(cpu->edi);
    cpu->eax = lift_load32(cpu->edi + 8u);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    goto label_0008CAEA;
    label_0008CACF: cpu->eip = LIFT_CODE_TOKEN_VA(0x48CACFu);
    cpu->edx = lift_load32(cpu->esi + 0xCu);
    cpu->ecx = lift_load32(cpu->esi + 8u);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->esp + 0x14u, cpu->edx);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (0.800000011920929));
    lift_store_f32(cpu->esp + 0x14u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008CAEA: cpu->eip = LIFT_CODE_TOKEN_VA(0x48CAEAu);
    lift_store32(cpu->ebx + 0xC4u, 0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0xACu));
    lift_store32(cpu->esp + 0x10u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0xB0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x14u))));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0xB4u));
    lift_store32(cpu->ebx + 0xB8u, cpu->ecx);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store32(cpu->ebx + 0xBCu, cpu->edx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebx + 0xA0u)) & 0xFFu);
    lift_store32(cpu->ebx + 0x14u, cpu->esi);
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->ebx + 0xC0u, cpu->eax);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(4u)) goto label_0008CB6C;
    label_0008CB52: cpu->eip = LIFT_CODE_TOKEN_VA(0x48CB52u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x4Cu;
    lift_return(cpu, 16u, stop_address); return;
    label_0008CB6C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48CB6Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x9Cu));
    lift_x87_push(cpu, 1.0);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    lift_store16(cpu->esp + 0x28u, cpu->fpu_control);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->esp + 0x68u))));
    cpu->eax = lift_load16(cpu->esp + 0x28u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebx + 0x9Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (255.0));
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x1Cu));
    lift_store64(cpu->esp + 0x1Cu, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x28u));
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(0xFFu)) goto label_0008CB52;
    cpu->esi = cpu->ecx;
    cpu->esi |= 0xFFFFFF00u;
    cpu->eax = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(8u), 32u);
    cpu->esi |= cpu->eax;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->eax -= cpu->ecx;
    cpu->ecx = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->ecx &= 0xFFu;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax |= cpu->ecx;
    lift_store32(cpu->ebx + 0xA4u, cpu->esi);
    lift_store32(cpu->ebx + 0xA8u, cpu->eax);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(3u)) goto label_0008CC7E;
    if ((uint32_t)(lift_load32(cpu->ebx + 0x18u)) != (uint32_t)(0xFFFFFFFFu)) goto label_0008CC1B;
    label_0008CC04: cpu->eip = LIFT_CODE_TOKEN_VA(0x48CC04u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x4Cu;
    lift_return(cpu, 16u, stop_address); return;
    label_0008CC1B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48CC1Bu);
    lift_push32(cpu, 0x40u);
    cpu->esi = (uint32_t)(cpu->ebx + 0x1Cu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x48CC23u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48CC28u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0x1B8u));
    lift_x87_push(cpu, 1.0);
    cpu->esp += 0xCu;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_store_f32(cpu->ebx + 0x40u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ebx + 0x34u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->ebx + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->ebx + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->ebx + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ebx + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0008CDED;
    label_0008CC7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48CC7Eu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((cpu->edx & 0xFFu)) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(lift_load8(cpu->esp + 0x6Cu)) + (uint64_t)(0u))) & 0xFFu);
    lift_store8(cpu->ebx + 0xA1u, cpu->eax & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) <= (uint8_t)(2u)) goto label_0008CC95;
    lift_store8(cpu->ebx + 0xA1u, 2u);
    label_0008CC95: cpu->eip = LIFT_CODE_TOKEN_VA(0x48CC95u);
    cpu->ecx = lift_load8(cpu->ebx + 0xA1u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + ((uint32_t)(cpu->ecx) * 4u) + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->ecx) * 4u) + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0008CC04;
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edx + 0x4Cu);
    lift_push32(cpu, 0x800u); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x8CCC3u), LIFT_CODE_TOKEN_RVA(0x8CCC1u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48CCC3u);
    cpu->eax = lift_load8(cpu->ebx + 0xA1u);
    cpu->eax = lift_load32(cpu->ebx + ((uint32_t)(cpu->eax) * 4u) + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x44u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x8CCDDu), LIFT_CODE_TOKEN_RVA(0x8CCDBu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48CCDDu);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008CC04;
    cpu->edx = lift_load32(cpu->esp + 0x50u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(lift_load32(cpu->esp + 0x54u));
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx);
    cpu->edi = (uint32_t)(cpu->ebx + 0x120u);
    cpu->ecx = 8u;
    cpu->esi = (uint32_t)(cpu->esp + 0x3Cu);
    lift_movs32(cpu, 1u);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, 0xFFFFu); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebx + 0x140u, cpu->ecx);
    lift_store32(cpu->ebx + 0x144u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x48CD1Cu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48CD21u);
    cpu->eax = cpu->ebp;
    cpu->esi = (uint32_t)(cpu->ebx + 0x5Cu);
    cpu->ecx = 0x10u;
    cpu->edi = (uint32_t)(cpu->ebx + 0x1Cu);
    lift_movs32(cpu, 1u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1B4u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1B4u));
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->eax + 0x1B4u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48CD55u); lift_push32(cpu, r); sfera_sub_0041A010(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x2Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x24u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x28u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebx + 0x28u))));
    lift_store_f32(cpu->ebx + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x30u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x2Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x34u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebx + 0x38u))));
    lift_store_f32(cpu->ebx + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x40u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x3Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x44u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebx + 0x48u))));
    lift_store_f32(cpu->ebx + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x50u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x4Cu));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ebx + 0x54u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebx + 0x58u))));
    lift_store_f32(cpu->ebx + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008CDED: cpu->eip = LIFT_CODE_TOKEN_VA(0x48CDEDu);
    cpu->ecx = lift_load32(cpu->esp + 0x58u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    lift_store32(cpu->ebx + 0xC4u, cpu->eax);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x4Cu;
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048CE10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48CE10u);
    cpu->esp -= 0x44u;
    cpu->eax = lift_load32(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x4Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008CE43;
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->eax + 4u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->esp + 0xCu, cpu->edx);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    goto label_0008CE66;
    label_0008CE43: cpu->eip = LIFT_CODE_TOKEN_VA(0x48CE43u);
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (0.800000011920929));
    lift_store32(cpu->esp + 8u, cpu->edx);
    cpu->edx = lift_load32(cpu->ecx + 0x10u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_store_f32(cpu->esp + 0xCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008CE66: cpu->eip = LIFT_CODE_TOKEN_VA(0x48CE66u);
    lift_store32(cpu->ebx + 0xC4u, 0u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0xACu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 8u))));
    lift_store_f32(cpu->esp + 0x18u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0xB0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0xCu))));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0xB4u));
    lift_store32(cpu->ebx + 0xB8u, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x10u))));
    lift_store32(cpu->ebx + 0xBCu, cpu->edx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ebx + 0xA0u)) & 0xFFu);
    lift_store32(cpu->ebx + 0x14u, cpu->ecx);
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->ebx + 0xC0u, cpu->eax);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(4u)) goto label_0008CEDA;
    label_0008CEC6: cpu->eip = LIFT_CODE_TOKEN_VA(0x48CEC6u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x44u;
    lift_return(cpu, 24u, stop_address); return;
    label_0008CEDA: cpu->eip = LIFT_CODE_TOKEN_VA(0x48CEDAu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x54u));
    lift_x87_push(cpu, 1.0);
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 0u) - lift_x87_get(cpu, 2u)); lift_x87_pop(cpu);
    lift_store16(cpu->esp + 0x14u, cpu->fpu_control);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) - (((double)lift_load_f32(cpu->ebx + 0x9Cu))));
    cpu->eax = lift_load16(cpu->esp + 0x14u);
    cpu->eax |= 0xC00u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebx + 0x9Cu))));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (255.0));
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 4u));
    lift_store64(cpu->esp + 0x18u, lift_x87_round(cpu, lift_x87_get(cpu, 0u), 0u));
    lift_x87_pop(cpu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->fpu_control = (uint16_t)(lift_load16(cpu->esp + 0x14u));
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(0xFFu)) goto label_0008CEC6;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->esi |= 0xFFFFFF00u;
    cpu->eax = cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFu), v=l & r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(8u), 32u);
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), v=l | r; lift_flags_logic(cpu,v,32u); cpu->esi = v; }
    cpu->esi = lift_shift_left(cpu, cpu->esi, (uint32_t)(8u), 32u);
    cpu->esi |= cpu->eax;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->eax -= cpu->ecx;
    cpu->ecx = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0xFFFFFF00u), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->ecx &= 0xFFu;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_left(cpu, cpu->eax, (uint32_t)(8u), 32u);
    cpu->eax |= cpu->ecx;
    lift_store32(cpu->ebx + 0xA4u, cpu->esi);
    lift_store32(cpu->ebx + 0xA8u, cpu->eax);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(3u)) goto label_0008CFD4;
    if ((uint32_t)(lift_load32(cpu->ebx + 0x18u)) == (uint32_t)(0xFFFFFFFFu)) goto label_0008D037;
    lift_push32(cpu, 0x40u);
    cpu->esi = (uint32_t)(cpu->ebx + 0x1Cu);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x48CF7Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48CF80u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x70u));
    lift_x87_push(cpu, 1.0);
    cpu->esp += 0xCu;
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 0u) / lift_x87_get(cpu, 1u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->esi, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 8u));
    lift_store_f32(cpu->ebx + 0x40u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->ebx + 0x34u, lift_x87_get(cpu, 0u));
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->ebx + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xCu));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->ebx + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 1u)));
    lift_store_f32(cpu->ebx + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store_f32(cpu->ebx + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    goto label_0008D144;
    label_0008CFD4: cpu->eip = LIFT_CODE_TOKEN_VA(0x48CFD4u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((cpu->edx & 0xFFu)) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(lift_load8(cpu->esp + 0x5Cu)) + (uint64_t)(0u))) & 0xFFu);
    lift_store8(cpu->ebx + 0xA1u, cpu->eax & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) <= (uint8_t)(2u)) goto label_0008CFEB;
    lift_store8(cpu->ebx + 0xA1u, 2u);
    label_0008CFEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x48CFEBu);
    cpu->ecx = lift_load8(cpu->ebx + 0xA1u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebx + ((uint32_t)(cpu->ecx) * 4u) + 4u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (uint32_t)(cpu->ebx + ((uint32_t)(cpu->ecx) * 4u) + 4u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0008D037;
    cpu->eax = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->eax);
    cpu->edx = lift_load32(cpu->edx + 0x4Cu);
    lift_push32(cpu, 0x800u); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edx), LIFT_CODE_TOKEN_RVA(0x8D015u), LIFT_CODE_TOKEN_RVA(0x8D013u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48D015u);
    cpu->eax = lift_load8(cpu->ebx + 0xA1u);
    cpu->eax = lift_load32(cpu->ebx + ((uint32_t)(cpu->eax) * 4u) + 4u);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0x44u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x8D02Fu), LIFT_CODE_TOKEN_RVA(0x8D02Du))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48D02Fu);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008D04C;
    label_0008D037: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D037u);
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x44u;
    lift_return(cpu, 24u, stop_address); return;
    label_0008D04C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D04Cu);
    cpu->edx = lift_load32(cpu->esp + 0x40u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(lift_load32(cpu->esp + 0x44u));
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx);
    cpu->edi = (uint32_t)(cpu->ebx + 0x120u);
    cpu->ecx = 8u;
    cpu->esi = (uint32_t)(cpu->esp + 0x34u);
    lift_movs32(cpu, 1u);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, 0xFFFFu); lift_push32(cpu, cpu->eax);
    lift_store32(cpu->ebx + 0x140u, cpu->ecx);
    lift_store32(cpu->ebx + 0x144u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x48D081u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48D086u);
    cpu->esi = (uint32_t)(cpu->ebx + 0x5Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x74u));
    cpu->ecx = 0x10u;
    lift_store_f32(cpu->esp + 8u, lift_x87_get(cpu, 0u));
    cpu->edi = (uint32_t)(cpu->ebx + 0x1Cu);
    lift_movs32(cpu, 1u);
    lift_store_f32(cpu->esp + 4u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D0AAu); lift_push32(cpu, r); sfera_sub_0041A010(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x18u));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x10u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    lift_x87_set(cpu, 0u, -lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x20u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x10u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x1Cu));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x20u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 3u)); lift_x87_set(cpu, 3u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x24u));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x24u)); lift_x87_push(cpu, lift_x87_get(cpu, 0u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 2u)); lift_x87_set(cpu, 2u, temporary); }
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebx + 0x28u))));
    lift_store_f32(cpu->ebx + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x30u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x2Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x34u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebx + 0x38u))));
    lift_store_f32(cpu->ebx + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x40u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x3Cu));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 4u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x44u));
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (lift_x87_get(cpu, 2u)));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebx + 0x48u))));
    lift_store_f32(cpu->ebx + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x50u));
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebx + 0x4Cu));
    lift_x87_set(cpu, 3u, lift_x87_get(cpu, 3u) * lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_x87_set(cpu, 2u, lift_x87_get(cpu, 2u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) * (((double)lift_load_f32(cpu->ebx + 0x54u))));
    lift_x87_set(cpu, 1u, lift_x87_get(cpu, 1u) + lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->ebx + 0x58u))));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store_f32(cpu->ebx + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    label_0008D144: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D144u);
    cpu->ecx = lift_load32(cpu->esp + 0x48u);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    lift_store32(cpu->ebx + 0xC4u, cpu->eax);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x44u;
    lift_return(cpu, 24u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048D170(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48D170u);
    cpu->esp -= 0x90u;
    cpu->eax = lift_load32(cpu->esp + 0x98u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0xA4u);
    cpu->ebx = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + 0xA0u)), r=(uint64_t)(3u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_store32(cpu->esp + 0x10u, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_0008D366;
    if ((uint32_t)(lift_load32(cpu->ebx + 0xC4u)) == (uint32_t)(0u)) goto label_0008D366;
    cpu->ecx = lift_load8(cpu->ebx + 0xA1u);
    if ((uint32_t)(lift_load32(cpu->ebx + ((uint32_t)(cpu->ecx) * 4u) + 4u)) == (uint32_t)(0u)) goto label_0008D366;
    cpu->esi = lift_load32(cpu->esp + 0xACu);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax = lift_load32(cpu->edi + 0x34u);
    cpu->ebp = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 2u));
    if ((uint32_t)(cpu->esi) == 0u) goto label_0008D29C;
    cpu->ecx = 0x10u;
    cpu->edi = (uint32_t)(cpu->esp + 0x5Cu);
    lift_movs32(cpu, 1u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x5Cu));
    lift_store_f32(cpu->esp + 0x1Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x6Cu));
    lift_store_f32(cpu->esp + 0x20u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x7Cu));
    lift_store_f32(cpu->esp + 0x24u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x8Cu));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x60u));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x70u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x80u));
    lift_push32(cpu, cpu->ecx);
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x94u));
    lift_push32(cpu, 0x100u);
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x6Cu));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x7Cu));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x8Cu));
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x9Cu));
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x70u));
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x80u));
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x90u));
    lift_store_f32(cpu->esp + 0x5Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0xA0u));
    lift_store_f32(cpu->esp + 0x60u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D298u); lift_push32(cpu, r); sfera_sub_004D88E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    label_0008D29C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D29Cu);
    cpu->eax = lift_load16(cpu->ebp + 8u);
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax = lift_load32(cpu->edi + 0x24u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    cpu->edx = lift_load16(cpu->ebp + 6u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u));
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_store32(cpu->esp + 0x18u, 0x24u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x3EAu)) goto label_0008D2D4;
    cpu->edx = 0x14Eu;
    lift_store32(cpu->esp + 0x10u, 0x3EAu);
    label_0008D2D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D2D4u);
    cpu->ecx = lift_load16(cpu->ebp + 4u);
    cpu->esi = lift_load32(cpu->edi + 0x2Cu);
    cpu->eax = lift_load32(cpu->ebx + 0xCCu);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->ecx) * 4u));
    if ((int32_t)(uint32_t)(cpu->edx) <= 0) goto label_0008D30F;
    label_0008D2F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D2F0u);
    cpu->esi = lift_load16(cpu->ecx);
    lift_store16(cpu->eax, cpu->esi & 0xFFFFu);
    cpu->esi = lift_load16(cpu->ecx + 4u);
    lift_store16(cpu->eax + 2u, cpu->esi & 0xFFFFu);
    cpu->esi = lift_load16(cpu->ecx + 2u);
    lift_store16(cpu->eax + 4u, cpu->esi & 0xFFFFu);
    cpu->eax += 6u;
    cpu->ecx += 0xCu;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008D2F0;
    label_0008D30F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D30Fu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D31Fu); lift_push32(cpu, r); sfera_sub_004D8950(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ebx + 0x138u);
    cpu->esp -= 0x40u;
    cpu->edi = cpu->esp;
    cpu->esi = cpu->eax;
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    cpu->ecx = lift_load32(cpu->ebx + 0x13Cu);
    cpu->eax = (uint32_t)(cpu->ebx + 0x140u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebx + 0xCCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load16(cpu->ebp + 0xAu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebx + 0xA4u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x6Cu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->ebx + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8D366u); lift_push32(cpu, r); sfera_sub_0048BE40(cpu,r); if (cpu->eip != r) return; }
    label_0008D366: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D366u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x90u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048D390(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48D390u);
    cpu->esp -= 0x4Cu;
    cpu->eax = lift_load32(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x60u);
    cpu->ebx = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + 0xA0u)), r=(uint64_t)(3u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_0008D42F;
    if ((uint32_t)(lift_load32(cpu->ebx + 0xC4u)) == (uint32_t)(0u)) goto label_0008D42F;
    cpu->ecx = lift_load8(cpu->ebx + 0xA1u);
    if ((uint32_t)(lift_load32(cpu->ebx + ((uint32_t)(cpu->ecx) * 4u) + 4u)) == (uint32_t)(0u)) goto label_0008D42F;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x18u, 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D3E8u); lift_push32(cpu, r); sfera_sub_004D8950(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ebx + 0x138u);
    cpu->esp -= 0x40u;
    cpu->edi = cpu->esp;
    cpu->esi = cpu->eax;
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    cpu->ecx = lift_load32(cpu->ebx + 0x13Cu);
    cpu->eax = (uint32_t)(cpu->ebx + 0x140u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0xB0u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0xACu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebx + 0xA4u);
    cpu->edx = (uint32_t)(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->ebx + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8D42Fu); lift_push32(cpu, r); sfera_sub_0048BE40(cpu,r); if (cpu->eip != r) return; }
    label_0008D42F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D42Fu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x4Cu;
    lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048D450(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48D450u);
    cpu->esp -= 0x50u;
    cpu->eax = lift_load32(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x60u);
    cpu->ebx = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->ebx + 0xA0u)), r=(uint64_t)(3u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_0008D566;
    if ((uint32_t)(lift_load32(cpu->ebx + 0xC4u)) == (uint32_t)(0u)) goto label_0008D566;
    cpu->ecx = lift_load8(cpu->ebx + 0xA1u);
    if ((uint32_t)(lift_load32(cpu->ebx + ((uint32_t)(cpu->ecx) * 4u) + 4u)) == (uint32_t)(0u)) goto label_0008D566;
    cpu->edx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax = lift_load32(cpu->esi + 0x34u);
    cpu->ebp = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edx) * 2u));
    cpu->eax = lift_load16(cpu->ebp + 8u);
    cpu->edx = lift_load32(cpu->esi + 0x24u);
    cpu->ecx = (uint32_t)(cpu->eax + ((uint32_t)(cpu->eax) * 8u));
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->edx = lift_load16(cpu->ebp + 6u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edx) * 2u));
    lift_store32(cpu->esp + 0x18u, 0x24u);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(0x3EAu)) goto label_0008D4D9;
    cpu->edx = 0x14Eu;
    lift_store32(cpu->esp + 0x10u, 0x3EAu);
    label_0008D4D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D4D9u);
    cpu->ecx = lift_load16(cpu->ebp + 4u);
    cpu->esi = lift_load32(cpu->esi + 0x2Cu);
    cpu->eax = lift_load32(cpu->ebx + 0xCCu);
    cpu->ecx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->ecx) * 2u));
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->ecx) * 4u));
    if ((int32_t)(uint32_t)(cpu->edx) <= 0) goto label_0008D50F;
    label_0008D4F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D4F0u);
    cpu->esi = lift_load16(cpu->ecx);
    lift_store16(cpu->eax, cpu->esi & 0xFFFFu);
    cpu->esi = lift_load16(cpu->ecx + 4u);
    lift_store16(cpu->eax + 2u, cpu->esi & 0xFFFFu);
    cpu->esi = lift_load16(cpu->ecx + 2u);
    lift_store16(cpu->eax + 4u, cpu->esi & 0xFFFFu);
    cpu->eax += 6u;
    cpu->ecx += 0xCu;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008D4F0;
    label_0008D50F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D50Fu);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D51Fu); lift_push32(cpu, r); sfera_sub_004D8950(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ebx + 0x138u);
    cpu->esp -= 0x40u;
    cpu->edi = cpu->esp;
    cpu->esi = cpu->eax;
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    cpu->ecx = lift_load32(cpu->ebx + 0x13Cu);
    cpu->eax = (uint32_t)(cpu->ebx + 0x140u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebx + 0xCCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = lift_load16(cpu->ebp + 0xAu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->ebx + 0xA4u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x6Cu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->ebx + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8D566u); lift_push32(cpu, r); sfera_sub_0048BE40(cpu,r); if (cpu->eip != r) return; }
    label_0008D566: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D566u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x50u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048D580(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48D580u);
    cpu->esp -= 0x54u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esi + 0xC4u)) == (uint32_t)(0u)) goto label_0008D9BB;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 3u;
    lift_push32(cpu, cpu->edi);
    if ((uint8_t)(lift_load8(cpu->esi + 0xA0u)) >= (uint8_t)((cpu->ebx & 0xFFu))) goto label_0008D6A7;
    cpu->eax = lift_load8(cpu->esi + 0xA1u);
    if ((uint32_t)(lift_load32(cpu->esi + ((uint32_t)(cpu->eax) * 4u) + 4u)) == (uint32_t)(0u)) goto label_0008D9B9;
    if ((uint8_t)(lift_load8(cpu->esi)) == (uint8_t)(0u)) goto label_0008D5E4;
    cpu->ecx = lift_load32(cpu->esi + 0x13Cu);
    cpu->edx = lift_load32(cpu->esi + 0x138u);
    cpu->eax = (uint32_t)(cpu->esi + 0x140u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8D5E4u); lift_push32(cpu, r); sfera_sub_0048BDB0(cpu,r); if (cpu->eip != r) return; }
    label_0008D5E4: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D5E4u);
    cpu->ecx = lift_load32(cpu->esi + 0x138u);
    cpu->edi = lift_load32(cpu->esi + 0x144u);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0008D60C;
    cpu->eax = 0xFFFFu;
    cpu->edx = cpu->eax & 0xFFFFu;
    cpu->eax = cpu->edx;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(0x10u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    lift_stos32(cpu, 1u);
    cpu->ecx = (uint64_t)(cpu->ecx) + (uint64_t)(cpu->ecx) + (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_stos16(cpu, 1u);
    label_0008D60C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D60Cu);
    cpu->edi = lift_load32(cpu->esi + 0x13Cu);
    cpu->ecx = lift_load32(cpu->esi + 0x138u);
    --cpu->edi;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(lift_load32(cpu->esi + 0x140u));
    cpu->edi += lift_load32(cpu->esi + 0x144u);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0008D642;
    cpu->eax = 0xFFFFu;
    cpu->edx = cpu->eax & 0xFFFFu;
    cpu->eax = cpu->edx;
    cpu->edx = lift_shift_left(cpu, cpu->edx, (uint32_t)(0x10u), 32u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edx), v=l | r; lift_flags_logic(cpu,v,32u); cpu->eax = v; }
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    lift_stos32(cpu, 1u);
    cpu->ecx = (uint64_t)(cpu->ecx) + (uint64_t)(cpu->ecx) + (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    lift_stos16(cpu, 1u);
    label_0008D642: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D642u);
    cpu->edx = lift_load32(cpu->esi + 0x13Cu);
    cpu->eax = lift_load32(cpu->esi + 0x138u);
    cpu->edi = lift_load32(cpu->esi + 0x144u);
    cpu->ecx = lift_load32(cpu->esi + 0x140u);
    cpu->eax = (uint32_t)(cpu->edi + ((uint32_t)(cpu->eax) * 2u) + 0xFFFFFFFEu);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0008D66F;
    label_0008D662: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D662u);
    cpu->edi = 0xFFFFu;
    lift_store16(cpu->eax, cpu->edi & 0xFFFFu);
    cpu->eax += cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008D662;
    label_0008D66F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D66Fu);
    cpu->edx = lift_load32(cpu->esi + 0x13Cu);
    cpu->ecx = lift_load32(cpu->esi + 0x140u);
    cpu->eax = lift_load32(cpu->esi + 0x144u);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0008D692;
    label_0008D685: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D685u);
    cpu->edi = 0xFFFFu;
    lift_store16(cpu->eax, cpu->edi & 0xFFFFu);
    cpu->eax += cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->edx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->edx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008D685;
    label_0008D692: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D692u);
    cpu->ecx = lift_load8(cpu->esi + 0xA1u);
    cpu->eax = lift_load32(cpu->esi + ((uint32_t)(cpu->ecx) * 4u) + 4u);
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->edx + 0x50u);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->eax), LIFT_CODE_TOKEN_RVA(0x8D6A7u), LIFT_CODE_TOKEN_RVA(0x8D6A5u))) { return; }
    label_0008D6A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D6A7u);
    cpu->edi = lift_load32(cpu->esp + 0x68u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_0008D9B9;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u);
    lift_store32(cpu->esi + 0xC4u, 0u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D6CEu); lift_push32(cpu, r); sfera_sub_004D8790(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 2u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D6DEu); lift_push32(cpu, r); sfera_sub_004D8790(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, 0.0);
    lift_store_f32(cpu->esp + 0x58u, lift_x87_get(cpu, 0u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store_f32(cpu->esp + 0x54u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u));
    lift_push32(cpu, 0x100u);
    lift_store_f32(cpu->esp + 0x4Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x48u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x44u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x40u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x38u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x34u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x30u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x2Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, 1.0);
    lift_store_f32(cpu->esp + 0x64u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x50u, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x3Cu, lift_x87_get(cpu, 0u));
    lift_store_f32(cpu->esp + 0x28u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D737u); lift_push32(cpu, r); sfera_sub_004D88E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D745u); lift_push32(cpu, r); sfera_sub_004D9190(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D754u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0xEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D763u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(lift_load8(cpu->esi + 0xA0u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0008D8A0;
    cpu->ecx = lift_load32(cpu->esi + 0x18u);
    cpu->edx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D779u); lift_push32(cpu, r); sfera_sub_0044FCB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 4u); lift_push32(cpu, 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D788u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    if ((uint32_t)(cpu->ebx) <= (uint32_t)(0x1F5u)) goto label_0008D7A3;
    lift_store32(cpu->esp + 0x10u, 0x1F5u);
    cpu->ebx = lift_load32(cpu->esp + 0x10u);
    label_0008D7A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D7A3u);
    cpu->edi = lift_load32(cpu->esi + 0xC8u);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0008D800;
    cpu->ebp = lift_load32(cpu->esp + 0x68u);
    label_0008D7B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D7B1u);
    lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->esi + 0x1Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D7BEu); lift_push32(cpu, r); sfera_sub_00419F70(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp));
    lift_store_f32(cpu->edi, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edi += 0x1Cu;
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 4u));
    cpu->ebp += 0xCu;
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    lift_store_f32(cpu->edi + 0xFFFFFFE8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ebp + 0xFFFFFFFCu));
    lift_store_f32(cpu->edi + 0xFFFFFFECu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    cpu->edx = lift_load32(cpu->esi + 0xA8u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    lift_store32(cpu->edi + 0xFFFFFFF0u, cpu->edx);
    lift_x87_push(cpu, 0.5);
    lift_store32(cpu->edi + 0xFFFFFFF4u, 0u);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store_f32(cpu->edi + 0xFFFFFFF8u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x18u))));
    lift_store_f32(cpu->edi + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008D7B1;
    label_0008D800: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D800u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x16u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D80Fu); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x1C2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D81Fu); lift_push32(cpu, r); sfera_sub_004D8B70(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esi + 0xC8u);
    lift_push32(cpu, 0x1Cu); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D840u); lift_push32(cpu, r); sfera_sub_004D9580(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D851u); lift_push32(cpu, r); sfera_sub_004D8790(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 2u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D862u); lift_push32(cpu, r); sfera_sub_004D8790(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D86Du); lift_push32(cpu, r); sfera_sub_004D91E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D87Cu); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0xEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D88Bu); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x54u;
    lift_return(cpu, 8u, stop_address); return;
    label_0008D8A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D8A0u);
    cpu->edx = lift_load8(cpu->esi + 0xA1u);
    cpu->eax = lift_load32(cpu->esi + ((uint32_t)(cpu->edx) * 4u) + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D8B9u); lift_push32(cpu, r); sfera_sub_004D8F40(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = (uint32_t)(cpu->edi + ((uint32_t)(cpu->edi) * 2u));
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D8C3u); lift_push32(cpu, r); sfera_sub_0044EFE0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008D9B8;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0008D923;
    cpu->ebp = lift_load32(cpu->esp + 0x68u);
    cpu->edi = (uint32_t)(cpu->eax + 0x1Cu);
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0008D8E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D8E0u);
    lift_push32(cpu, cpu->ebp);
    cpu->edx = (uint32_t)(cpu->esi + 0x1Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D8EDu); lift_push32(cpu, r); sfera_sub_00419F70(cpu,r); if (cpu->eip != r) return; }
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x14u));
    cpu->ecx = lift_load32(cpu->ebp);
    lift_x87_push(cpu, 0.5);
    lift_store32(cpu->edi + 0xFFFFFFE4u, cpu->ecx);
    lift_x87_set(cpu, 1u, (lift_x87_get(cpu, 1u)) + (lift_x87_get(cpu, 0u)));
    cpu->edx = lift_load32(cpu->ebp + 4u);
    { double temporary = lift_x87_get(cpu, 0u); lift_x87_set(cpu, 0u, lift_x87_get(cpu, 1u)); lift_x87_set(cpu, 1u, temporary); }
    lift_store32(cpu->edi + 0xFFFFFFE8u, cpu->edx);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    lift_store_f32(cpu->edi + 0xFFFFFFFCu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_store32(cpu->edi + 0xFFFFFFECu, cpu->eax);
    lift_x87_set(cpu, 0u, (lift_x87_get(cpu, 0u)) + (((double)lift_load_f32(cpu->esp + 0x18u))));
    cpu->edi += 0x20u;
    cpu->ebp += 0xCu;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; lift_store32(cpu->esp + 0x10u, v); }
    lift_store_f32(cpu->edi + 0xFFFFFFE0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008D8E0;
    label_0008D923: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D923u);
    cpu->ecx = g_sfera_sky_runtime.draw_resource;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D938u); lift_push32(cpu, r); sfera_sub_004D8AA0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator;
    cpu->ecx = g_sfera_sky_runtime.draw_resource;
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x20u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_push32(cpu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D960u); lift_push32(cpu, r); sfera_sub_004D92A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_store32((uint32_t)(uintptr_t)&g_sfera_main_input_state_runtime.timing_accumulator, (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u));
    lift_push32(cpu, 1u); lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D977u); lift_push32(cpu, r); sfera_sub_004D8790(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 2u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D988u); lift_push32(cpu, r); sfera_sub_004D8790(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D993u); lift_push32(cpu, r); sfera_sub_004D91E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D9A2u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0xEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48D9B1u); lift_push32(cpu, r); sfera_sub_004D8740(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x14u, 0u);
    label_0008D9B8: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D9B8u);
    cpu->ebp = lift_pop32(cpu);
    label_0008D9B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D9B9u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0008D9BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x48D9BBu);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x54u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048D9D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48D9D0u);
    cpu->eax = lift_load32(cpu->ecx + 0xACu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0x9Cu));
    cpu->edx = lift_load32(cpu->ecx + 0xB0u);
    lift_store_f32(cpu->ecx + 0xD0u, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->ecx + 0xD4u, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xB4u);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->ecx + 0xD8u, cpu->edx);
    lift_store32(cpu->ecx + 0xDCu, cpu->eax);
    cpu->esi = (uint32_t)(cpu->ecx + 0x5Cu);
    cpu->edi = (uint32_t)(cpu->ecx + 0xE0u);
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048DA20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48DA20u);
    cpu->eax = lift_load32(cpu->ecx + 0xD4u);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->ecx + 0xD0u));
    cpu->edx = lift_load32(cpu->ecx + 0xD8u);
    lift_store_f32(cpu->ecx + 0x9Cu, lift_x87_get(cpu, 0u)); lift_x87_pop(cpu);
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->ecx + 0xACu, cpu->eax);
    cpu->eax = lift_load32(cpu->ecx + 0xDCu);
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->ecx + 0xB0u, cpu->edx);
    lift_store32(cpu->ecx + 0xB4u, cpu->eax);
    cpu->esi = (uint32_t)(cpu->ecx + 0xE0u);
    cpu->edi = (uint32_t)(cpu->ecx + 0x5Cu);
    cpu->ecx = 0x10u;
    lift_movs32(cpu, 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048DA70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48DA70u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->esp + 4u, cpu->ecx);
    cpu->ecx = (uint32_t)(uintptr_t)"config.cfg";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48DAA1u); lift_push32(cpu, r); sfera_sub_004483B0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 4u);
    cpu->ecx = (uint32_t)(uintptr_t)"SHAD";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48DAAFu); lift_push32(cpu, r); sfera_sub_00448540(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_shadow_runtime.manager;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008DB17;
    cpu->edx = 0x206u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\shadow.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48DAC7u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x148u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48DAD1u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 8u, cpu->eax);
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008DAED;
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48DAEBu); lift_push32(cpu, r); sfera_sub_0048C570(cpu,r); if (cpu->eip != r) return; }
    goto label_0008DAEF;
    label_0008DAED: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DAEDu);
    cpu->eax = 0u;
    label_0008DAEF: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DAEFu);
    cpu->ecx = cpu->eax;
    lift_store32(cpu->esp + 0x14u, 0xFFFFFFFFu);
    g_sfera_shadow_runtime.manager = (uint32_t)(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48DB03u); lift_push32(cpu, r); sfera_sub_0048C730(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = g_sfera_shadow_runtime.manager;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 4u)) & 0xFFu);
    lift_store8(cpu->eax + 0xA0u, cpu->ecx & 0xFFu);
    cpu->eax = g_sfera_shadow_runtime.manager;
    label_0008DB17: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DB17u);
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048DB30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48DB30u);
    if ((uint32_t)(g_sfera_shadow_runtime.manager) == (uint32_t)(0u)) goto label_0008DB6E;
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0x215u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\shadow.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48DB49u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = g_sfera_shadow_runtime.manager;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0008DB63;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48DB5Au); lift_push32(cpu, r); sfera_sub_0048C670(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48DB60u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008DB63: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DB63u);
    g_sfera_shadow_runtime.manager = (uint32_t)(0u);
    cpu->esi = lift_pop32(cpu);
    label_0008DB6E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DB6Eu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048DB70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48DB70u);
    cpu->eax = lift_load32(cpu->ecx);
    lift_push32(cpu, cpu->esi);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008DB7B;
    lift_flags_logic(cpu,0u,32u); cpu->esi = 0u;
    goto label_0008DB7D;
    label_0008DB7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DB7Bu);
    cpu->esi = lift_load32(cpu->eax);
    label_0008DB7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DB7Du);
    cpu->eax = lift_load32(cpu->ecx + 8u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->eax &= 3u;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->ecx)) goto label_0008DB91;
    cpu->ecx -= cpu->edx;
    label_0008DB91: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DB91u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048DBA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48DBA0u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(1u)) goto label_0008DBBF;
    if ((uint32_t)(lift_load32(cpu->ecx + 0x14u)) < (uint32_t)(0x10u)) goto label_0008DBB1;
    cpu->ecx = lift_load32(cpu->ecx);
    label_0008DBB1: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DBB1u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0xCu)) & 0xFFu);
    cpu->edx = lift_load32(cpu->esp + 4u);
    lift_store8(cpu->ecx + cpu->edx, cpu->eax & 0xFFu);
    lift_return(cpu, 12u, stop_address); return;
    label_0008DBBF: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DBBFu);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x14u)) < (uint32_t)(0x10u)) goto label_0008DBC7;
    cpu->ecx = lift_load32(cpu->ecx);
    label_0008DBC7: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DBC7u);
    cpu->ecx += lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (int8_t)(lift_load8(cpu->esp + 0x10u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x48DBD3u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48DBD8u);
    cpu->esp += 0xCu;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048DBE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48DBE0u);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x14u)) < (uint32_t)(0x10u)) goto label_0008DBF1;
    cpu->ecx = lift_load32(cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->eax += cpu->ecx;
    lift_return(cpu, 4u, stop_address); return;
    label_0008DBF1: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DBF1u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = (uint32_t)(cpu->ecx + cpu->edx);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048DC00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48DC00u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0xCu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_0008DC5C;
    cpu->edx = lift_load32(cpu->edi + 0x10u);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->edx)) goto label_0008DC5C;
    cpu->ecx = lift_load32(cpu->edi + 0x14u);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(0x10u)) goto label_0008DC24;
    cpu->eax = lift_load32(cpu->edi);
    goto label_0008DC26;
    label_0008DC24: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DC24u);
    cpu->eax = cpu->edi;
    label_0008DC26: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DC26u);
    cpu->ebx = (uint32_t)(cpu->edx + cpu->eax);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(0x10u)) goto label_0008DC32;
    cpu->eax = lift_load32(cpu->edi);
    goto label_0008DC34;
    label_0008DC32: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DC32u);
    cpu->eax = cpu->edi;
    label_0008DC34: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DC34u);
    cpu->esi += cpu->eax;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->ebx)) goto label_0008DC5C;
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    cpu->edi = cpu->edi;
    label_0008DC40: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DC40u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = (int8_t)(lift_load8(cpu->esi));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_memchr_address32(), LIFT_CODE_TOKEN_VA(0x48DC4Au)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48DC50u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008DC66;
    ++cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebx)) goto label_0008DC40;
    label_0008DC5C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DC5Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0008DC66: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DC66u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) < (uint32_t)(0x10u)) goto label_0008DC6E;
    cpu->edi = lift_load32(cpu->edi);
    label_0008DC6E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DC6Eu);
    cpu->eax = cpu->esi;
    cpu->eax -= cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048DC80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48DC80u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->edx = lift_load32(cpu->edi + 0x10u);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->edx)) goto label_0008DCD3;
    cpu->ecx = lift_load32(cpu->edi + 0x14u);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(0x10u)) goto label_0008DC9D;
    cpu->eax = lift_load32(cpu->edi);
    goto label_0008DC9F;
    label_0008DC9D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DC9Du);
    cpu->eax = cpu->edi;
    label_0008DC9F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DC9Fu);
    cpu->ebx = (uint32_t)(cpu->edx + cpu->eax);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(0x10u)) goto label_0008DCAB;
    cpu->eax = lift_load32(cpu->edi);
    goto label_0008DCAD;
    label_0008DCAB: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DCABu);
    cpu->eax = cpu->edi;
    label_0008DCAD: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DCADu);
    cpu->esi += cpu->eax;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->ebx)) goto label_0008DCD3;
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    label_0008DCB7: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DCB7u);
    cpu->eax = (int8_t)(lift_load8(cpu->esi));
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_memchr_address32(), LIFT_CODE_TOKEN_VA(0x48DCC1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48DCC7u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008DCDD;
    ++cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebx)) goto label_0008DCB7;
    label_0008DCD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DCD3u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0008DCDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DCDDu);
    if ((uint32_t)(lift_load32(cpu->edi + 0x14u)) < (uint32_t)(0x10u)) goto label_0008DCE5;
    cpu->edi = lift_load32(cpu->edi);
    label_0008DCE5: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DCE5u);
    cpu->eax = cpu->esi;
    cpu->eax -= cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048DCF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48DCF0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->ecx;
    cpu->edx = lift_load32(cpu->eax + 0x10u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0008DD6D;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->edx)) goto label_0008DD0E;
    cpu->edx = cpu->ecx;
    goto label_0008DD0F;
    label_0008DD0E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DD0Eu);
    --cpu->edx;
    label_0008DD0F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DD0Fu);
    if ((uint32_t)(lift_load32(cpu->eax + 0x14u)) < (uint32_t)(0x10u)) goto label_0008DD17;
    cpu->eax = lift_load32(cpu->eax);
    label_0008DD17: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DD17u);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    cpu->ebp = native_memchr_address32();
    cpu->esi = (uint32_t)(cpu->eax + cpu->edx);
    cpu->eax = (int8_t)(lift_load8(cpu->esi));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x8DD30u), LIFT_CODE_TOKEN_RVA(0x8DD2Eu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48DD30u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008DD55;
    label_0008DD37: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DD37u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48DD40u); lift_push32(cpu, r); sfera_sub_004020B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_0008DD6D;
    cpu->ecx = (int8_t)(lift_load8(cpu->esi + 0xFFFFFFFFu));
    --cpu->esi;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x8DD4Eu), LIFT_CODE_TOKEN_RVA(0x8DD4Cu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48DD4Eu);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008DD37;
    label_0008DD55: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DD55u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x14u)) < (uint32_t)(0x10u)) goto label_0008DD61;
    cpu->ecx = lift_load32(cpu->ecx);
    label_0008DD61: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DD61u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax -= cpu->ecx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0008DD6D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DD6Du);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048DD80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48DD80u);
    cpu->edx = lift_load32(cpu->esp + 4u);
    cpu->eax = cpu->ecx;
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    cpu->ecx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0008DDA3;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0008DDA3;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_0008DDA3: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DDA3u);
    cpu->edx = lift_load32(cpu->edx + 8u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048DDB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48DDB0u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax = cpu->ecx;
    if ((uint32_t)(lift_load32(cpu->esp + 0x10u)) == (uint32_t)(cpu->esi)) goto label_0008DE2E;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    label_0008DDC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DDC0u);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    --cpu->esi;
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    { uint64_t v=(uint64_t)(cpu->edx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008DDD1;
    lift_flags_logic(cpu,0u,32u); cpu->edi = 0u;
    goto label_0008DDD3;
    label_0008DDD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DDD1u);
    cpu->edi = lift_load32(cpu->edx);
    label_0008DDD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DDD3u);
    cpu->ebx = lift_load32(cpu->edi + 8u);
    cpu->edx = cpu->esi;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->esi &= 3u;
    if ((uint32_t)(cpu->ebx) > (uint32_t)(cpu->edx)) goto label_0008DDE4;
    cpu->edx -= cpu->ebx;
    label_0008DDE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DDE4u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->edx) * 4u));
    cpu->ebp = (uint32_t)(cpu->edx + ((uint32_t)(cpu->esi) * 4u));
    cpu->esi = lift_load32(cpu->esp + 0x34u);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    --cpu->esi;
    lift_store32(cpu->esp + 0x34u, cpu->esi);
    { uint64_t v=(uint64_t)(cpu->edx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008DE02;
    lift_flags_logic(cpu,0u,32u); cpu->ebx = 0u;
    goto label_0008DE04;
    label_0008DE02: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DE02u);
    cpu->ebx = lift_load32(cpu->edx);
    label_0008DE04: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DE04u);
    cpu->edi = lift_load32(cpu->ebx + 8u);
    cpu->edx = cpu->esi;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->esi &= 3u;
    if ((uint32_t)(cpu->edi) > (uint32_t)(cpu->edx)) goto label_0008DE15;
    cpu->edx -= cpu->edi;
    label_0008DE15: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DE15u);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->edx) * 4u));
    cpu->ecx = lift_load32(cpu->ebp);
    lift_store32(cpu->edx + ((uint32_t)(cpu->esi) * 4u), cpu->ecx);
    cpu->esi = lift_load32(cpu->esp + 0x28u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) != (uint32_t)(cpu->esi)) goto label_0008DDC0;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0008DE2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DE2Eu);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0008DE4E;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0008DE58;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->eax, cpu->edx);
    label_0008DE4E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DE4Eu);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    lift_return(cpu, 40u, stop_address); return;
    label_0008DE58: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DE58u);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    lift_return(cpu, 40u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048DE70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48DE70u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = cpu->ecx;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 4u, cpu->eax);
    if ((uint32_t)(cpu->edx) == (uint32_t)(lift_load32(cpu->esp + 0x20u))) goto label_0008DEFB;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0008DE90: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DE90u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0008DE9A;
    cpu->eax = lift_load32(cpu->eax);
    label_0008DE9A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DE9Au);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edi = cpu->edx;
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(2u), 32u);
    cpu->edx &= 3u;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->edi)) goto label_0008DEAB;
    cpu->edi -= cpu->ecx;
    label_0008DEAB: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DEABu);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008DEB7;
    lift_flags_logic(cpu,0u,32u); cpu->ebp = 0u;
    goto label_0008DEB9;
    label_0008DEB7: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DEB7u);
    cpu->ebp = lift_load32(cpu->ecx);
    label_0008DEB9: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DEB9u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->esi = cpu->ebx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(2u), 32u);
    cpu->ebx &= 3u;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->esi)) goto label_0008DECA;
    cpu->esi -= cpu->ecx;
    label_0008DECA: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DECAu);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    cpu->eax = lift_load32(cpu->ebp + 4u);
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->edx) * 4u));
    cpu->eax = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    lift_store32(cpu->eax + ((uint32_t)(cpu->ebx) * 4u), cpu->ecx);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->ebx = lift_load32(cpu->esp + 0x38u);
    ++cpu->edx;
    ++cpu->ebx;
    lift_store32(cpu->esp + 0x38u, cpu->ebx);
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    if ((uint32_t)(cpu->edx) != (uint32_t)(lift_load32(cpu->esp + 0x2Cu))) goto label_0008DE90;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_0008DEFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DEFBu);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    lift_store32(cpu->eax + 8u, cpu->ebx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0008DF1D;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0008DF1D;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    label_0008DF1D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DF1Du);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 40u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048DF30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48DF30u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_0008DFA2;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_0008DF40: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DF40u);
    --cpu->ecx;
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0008DF9E;
    cpu->ebp = lift_load32(cpu->esp + 0x1Cu);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->esi = cpu->ecx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(2u), 32u);
    cpu->ecx &= 3u;
    { uint64_t l=(uint64_t)(cpu->edx), r=(uint64_t)(cpu->esi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0008DF5E;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->edx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    label_0008DF5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DF5Eu);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = lift_load32(cpu->edi + 8u);
    cpu->edx = cpu->eax;
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->eax &= 3u;
    if ((uint32_t)(cpu->ebx) > (uint32_t)(cpu->edx)) goto label_0008DF73;
    cpu->edx -= cpu->ebx;
    label_0008DF73: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DF73u);
    cpu->ebx = lift_load32(cpu->ebp + 4u);
    cpu->esi = lift_load32(cpu->ebx + ((uint32_t)(cpu->esi) * 4u));
    cpu->ecx = (uint32_t)(cpu->esi + ((uint32_t)(cpu->ecx) * 4u));
    cpu->esi = lift_load32(cpu->edi + 4u);
    cpu->edx = lift_load32(cpu->esi + ((uint32_t)(cpu->edx) * 4u));
    cpu->esi = lift_load32(cpu->ecx);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->eax, cpu->esi);
    lift_store32(cpu->ecx, cpu->edx);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_0008DF40;
    label_0008DF9E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DF9Eu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0008DFA2: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DFA2u);
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048DFB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48DFB0u);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 0x10u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->edx + 0x10u))) goto label_0008E021;
    if ((uint32_t)(lift_load32(cpu->edx + 0x14u)) < (uint32_t)(0x10u)) goto label_0008DFC7;
    cpu->edx = lift_load32(cpu->edx);
    label_0008DFC7: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DFC7u);
    cpu->esi = lift_load32(cpu->ecx + 0x14u);
    if ((uint32_t)(cpu->esi) < (uint32_t)(0x10u)) goto label_0008DFD3;
    cpu->eax = lift_load32(cpu->ecx);
    goto label_0008DFD5;
    label_0008DFD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DFD3u);
    cpu->eax = cpu->ecx;
    label_0008DFD5: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DFD5u);
    cpu->eax += cpu->edi;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->esi) < (uint32_t)(0x10u)) goto label_0008DFE4;
    cpu->esi = lift_load32(cpu->ecx);
    goto label_0008DFE6;
    label_0008DFE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DFE4u);
    cpu->esi = cpu->ecx;
    label_0008DFE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DFE6u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->eax)) goto label_0008E017;
    cpu->edi = native_function_address32(&::toupper);
    cpu->ebp = cpu->edx;
    cpu->ebp -= cpu->esi;
    label_0008DFF4: cpu->eip = LIFT_CODE_TOKEN_VA(0x48DFF4u);
    cpu->eax = (int8_t)(lift_load8(cpu->esi));
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + cpu->ebp)) & 0xFFu);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x8DFFDu), LIFT_CODE_TOKEN_RVA(0x8DFFBu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48DFFDu);
    cpu->ecx = (int8_t)((cpu->ebx & 0xFFu));
    lift_push32(cpu, cpu->ecx);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->edi), LIFT_CODE_TOKEN_RVA(0x8E007u), LIFT_CODE_TOKEN_RVA(0x8E005u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48E007u);
    cpu->esp += 8u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x10u)) != (uint32_t)(cpu->eax)) goto label_0008E021;
    ++cpu->esi;
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_0008DFF4;
    label_0008E017: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E017u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
    label_0008E021: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E021u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048E030(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48E030u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = cpu->edx;
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->edi) == (uint32_t)(0xFFFFFFFFu)) goto label_0008E089;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_0008E089;
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_0008E04F;
    cpu->eax = lift_load32(cpu->esi);
    goto label_0008E051;
    label_0008E04F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E04Fu);
    cpu->eax = cpu->esi;
    label_0008E051: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E051u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + cpu->edi)) & 0xFFu);
    cpu->eax = (((cpu->eax & 0xFFu) == 0x5Cu) || ((cpu->eax & 0xFFu) == 0x2Fu)) ? 0u : 0xFFFFFFFFu;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_0008E089;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0008E081;
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_0008E07C;
    cpu->esi = lift_load32(cpu->esi);
    label_0008E07C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E07Cu);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi + cpu->edi)) & 0xFFu);
    lift_store8(cpu->ebx, cpu->edx & 0xFFu);
    label_0008E081: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E081u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0008E089: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E089u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048E0A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48E0A0u);
    cpu->eax = lift_load32(cpu->ecx);
    cpu->edx = 0u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008E0B0;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008E0B0;
    cpu->edx = lift_load32(cpu->eax);
    label_0008E0B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E0B0u);
    cpu->ecx = lift_load32(cpu->ecx + 8u);
    cpu->ecx -= lift_load32(cpu->esp + 8u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0008E0D9;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0008E0D9;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->eax, cpu->edx);
    label_0008E0D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E0D9u);
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048E0E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48E0E0u);
    cpu->eax = lift_load32(cpu->ecx + 0x10u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008E10C;
    lift_store32(cpu->ecx + 0xCu, (uint64_t)(lift_load32(cpu->ecx + 0xCu)) + 1u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 8u);
    cpu->edi += cpu->edi;
    cpu->edi += cpu->edi;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(lift_load32(cpu->ecx + 0xCu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_pop32(cpu);
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0008E0FF;
    lift_store32(cpu->ecx + 0xCu, 0u);
    label_0008E0FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E0FFu);
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    lift_store32(cpu->ecx + 0x10u, cpu->eax);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008E10C;
    lift_store32(cpu->ecx + 0xCu, 0u);
    label_0008E10C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E10Cu);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048E110(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48E110u);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = lift_load32(cpu->ebx + 8u);
    cpu->ecx = 0xFFFFFFFu;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    cpu->ecx -= cpu->eax;
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_CF) == 0u) goto label_0008E134;
    lift_push32(cpu, (uint32_t)(uintptr_t)"deque<T> too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x8E134u);
    label_0008E134: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E134u);
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(8u)) goto label_0008E142;
    cpu->ecx = 8u;
    label_0008E142: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E142u);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->ecx)) goto label_0008E157;
    cpu->edx = 0xFFFFFFFu;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->eax) > (uint32_t)(cpu->edx)) goto label_0008E157;
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    cpu->edi = cpu->ecx;
    label_0008E157: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E157u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->ebx + 0xCu);
    lift_push32(cpu, cpu->esi);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebx + 0x15u);
    cpu->ebp = lift_shift_right(cpu, cpu->ebp, (uint32_t)(2u), 32u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48E16Au); lift_push32(cpu, r); sfera_sub_0049F1D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->edx = cpu->eax;
    cpu->esi = (uint32_t)(((uint32_t)(cpu->ebp) * 4u));
    cpu->eax = (uint32_t)(cpu->esi + cpu->ecx);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->eax = lift_load32(cpu->ebx + 8u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax -= lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_shift_arithmetic(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->esi;
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x48E1A2u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48E1A8u);
    cpu->eax += lift_load32(cpu->esp + 0x24u);
    cpu->ecx = lift_load32(cpu->ebx + 4u);
    cpu->esp += 0xCu;
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0008E1F3;
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(2u), 32u);
    cpu->edx = cpu->esi;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->edi;
    lift_store32(cpu->esp + 0x24u, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x48E1C8u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48E1CEu);
    cpu->edx = cpu->eax;
    cpu->edx += lift_load32(cpu->esp + 0x24u);
    cpu->esp += 0xCu;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->ebp), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->esi = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0008E1E7;
    cpu->ecx = cpu->esi;
    cpu->eax = 0u;
    cpu->edi = cpu->edx;
    lift_stos32(cpu, 1u);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    label_0008E1E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E1E7u);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_0008E240;
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = cpu->ebp;
    goto label_0008E238;
    label_0008E1F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E1F3u);
    cpu->ebp = (uint32_t)(((uint32_t)(cpu->edi) * 4u));
    cpu->edx = cpu->ebp;
    cpu->edx = lift_shift_arithmetic(cpu, cpu->edx, (uint32_t)(2u), 32u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x48E206u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48E20Cu);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->ecx = (uint32_t)(cpu->eax + cpu->ebp);
    cpu->esi -= cpu->ecx;
    { uint64_t l=(uint64_t)(cpu->esi), r=(uint64_t)(cpu->eax), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->esi = v; }
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->esi = lift_shift_arithmetic(cpu, cpu->esi, (uint32_t)(2u), 32u);
    cpu->esi += cpu->esi;
    cpu->esi += cpu->esi;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x48E224u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48E22Au);
    cpu->esp += 0x18u;
    cpu->edx = (uint32_t)(cpu->esi + cpu->eax);
    if ((uint32_t)(cpu->edi) == 0u) goto label_0008E240;
    cpu->ecx = cpu->edi;
    cpu->edi = cpu->edx;
    label_0008E238: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E238u);
    cpu->eax = 0u;
    lift_stos32(cpu, 1u);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    label_0008E240: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E240u);
    cpu->eax = lift_load32(cpu->ebx + 4u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008E252;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48E24Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008E252: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E252u);
    lift_store32(cpu->ebx + 8u, (uint64_t)(lift_load32(cpu->ebx + 8u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u));
    cpu->ecx = lift_load32(cpu->esp + 8u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->ebx + 4u, cpu->ecx);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048E270(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48E270u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->eax = lift_load32(cpu->eax + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0xCu);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_0008E28D;
    lift_push32(cpu, (uint32_t)(uintptr_t)"invalid string position");
    lift_trap(cpu, cpu->eip, "std::out_of_range");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x8E28Du);
    label_0008E28D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E28Du);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    cpu->eax -= cpu->ecx;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ebx)) goto label_0008E29A;
    cpu->ebx = cpu->eax;
    label_0008E29A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E29Au);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->eax;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->ebx)) goto label_0008E2B1;
    lift_push32(cpu, (uint32_t)(uintptr_t)"string too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x8E2B1u);
    label_0008E2B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E2B1u);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0008E34E;
    cpu->edi = (uint32_t)(cpu->eax + cpu->ebx);
    if ((uint32_t)(cpu->edi) <= (uint32_t)(0xFFFFFFFEu)) goto label_0008E2CD;
    lift_push32(cpu, (uint32_t)(uintptr_t)"string too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x8E2CDu);
    label_0008E2CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E2CDu);
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->edi)) goto label_0008E2F7;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48E2DDu); lift_push32(cpu, r); sfera_sub_00403230(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) == 0u) goto label_0008E34E;
    label_0008E2E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E2E1u);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(lift_load32(cpu->ecx + 0x14u)) < (uint32_t)(0x10u)) goto label_0008E2ED;
    cpu->ecx = lift_load32(cpu->ecx);
    label_0008E2ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E2EDu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_0008E31B;
    cpu->eax = lift_load32(cpu->esi);
    goto label_0008E31D;
    label_0008E2F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E2F7u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_0008E2E1;
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(0x10u)) goto label_0008E310;
    cpu->eax = lift_load32(cpu->esi);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->eax, 0u);
    cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0008E310: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E310u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->ebx = lift_pop32(cpu);
    lift_store8(cpu->eax, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0008E31B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E31Bu);
    cpu->eax = cpu->esi;
    label_0008E31D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E31Du);
    cpu->ecx += lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x48E329u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48E32Eu);
    cpu->esp += 0xCu;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0008E348;
    cpu->eax = lift_load32(cpu->esi);
    lift_store8(cpu->eax + cpu->edi, 0u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0008E348: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E348u);
    cpu->eax = cpu->esi;
    lift_store8(cpu->eax + cpu->edi, 0u);
    label_0008E34E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E34Eu);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048E360(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48E360u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ebp) == 0u) goto label_0008E3C5;
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(0x10u)) goto label_0008E378;
    cpu->eax = lift_load32(cpu->esi);
    goto label_0008E37A;
    label_0008E378: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E378u);
    cpu->eax = cpu->esi;
    label_0008E37A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E37Au);
    if ((uint32_t)(cpu->ebp) < (uint32_t)(cpu->eax)) goto label_0008E3C5;
    if ((uint32_t)(cpu->ecx) < (uint32_t)(0x10u)) goto label_0008E387;
    cpu->eax = lift_load32(cpu->esi);
    goto label_0008E389;
    label_0008E387: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E387u);
    cpu->eax = cpu->esi;
    label_0008E389: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E389u);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    cpu->edx += cpu->eax;
    if ((uint32_t)(cpu->edx) <= (uint32_t)(cpu->ebp)) goto label_0008E3C5;
    if ((uint32_t)(cpu->ecx) < (uint32_t)(0x10u)) goto label_0008E3AE;
    cpu->eax = lift_load32(cpu->esi);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ebp -= cpu->eax;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48E3A9u); lift_push32(cpu, r); sfera_sub_0048E270(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0008E3AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E3AEu);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    cpu->eax = cpu->esi;
    lift_push32(cpu, cpu->ecx);
    cpu->ebp -= cpu->eax;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48E3C0u); lift_push32(cpu, r); sfera_sub_0048E270(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0008E3C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E3C5u);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->edx |= 0xFFFFFFFFu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    cpu->edx -= cpu->eax;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->ebx)) goto label_0008E3E1;
    lift_push32(cpu, (uint32_t)(uintptr_t)"string too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x8E3E1u);
    label_0008E3E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E3E1u);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0008E471;
    cpu->edi = (uint32_t)(cpu->eax + cpu->ebx);
    if ((uint32_t)(cpu->edi) <= (uint32_t)(0xFFFFFFFEu)) goto label_0008E3FD;
    lift_push32(cpu, (uint32_t)(uintptr_t)"string too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x8E3FDu);
    label_0008E3FD: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E3FDu);
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->edi)) goto label_0008E41B;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48E40Du); lift_push32(cpu, r); sfera_sub_00403230(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) == 0u) goto label_0008E471;
    label_0008E411: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E411u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_0008E441;
    cpu->eax = lift_load32(cpu->esi);
    goto label_0008E443;
    label_0008E41B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E41Bu);
    if ((uint32_t)(cpu->edi) != 0u) goto label_0008E411;
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(0x10u)) goto label_0008E435;
    cpu->eax = lift_load32(cpu->esi);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    lift_store8(cpu->eax, 0u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0008E435: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E435u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    lift_store8(cpu->eax, 0u);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0008E441: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E441u);
    cpu->eax = cpu->esi;
    label_0008E443: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E443u);
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x48E44Bu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48E450u);
    cpu->esp += 0xCu;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0008E46B;
    cpu->eax = lift_load32(cpu->esi);
    lift_store8(cpu->eax + cpu->edi, 0u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0008E46B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E46Bu);
    cpu->eax = cpu->esi;
    lift_store8(cpu->eax + cpu->edi, 0u);
    label_0008E471: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E471u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048E480(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48E480u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ebx)) goto label_0008E49A;
    lift_push32(cpu, (uint32_t)(uintptr_t)"invalid string position");
    lift_trap(cpu, cpu->eip, "std::out_of_range");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x8E49Au);
    label_0008E49A: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E49Au);
    cpu->ecx |= 0xFFFFFFFFu;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    cpu->ecx -= cpu->eax;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->ebp)) goto label_0008E4B3;
    lift_push32(cpu, (uint32_t)(uintptr_t)"string too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x8E4B3u);
    label_0008E4B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E4B3u);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_0008E569;
    cpu->edi = (uint32_t)(cpu->eax + cpu->ebp);
    if ((uint32_t)(cpu->edi) <= (uint32_t)(0xFFFFFFFEu)) goto label_0008E4CF;
    lift_push32(cpu, (uint32_t)(uintptr_t)"string too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x8E4CFu);
    label_0008E4CF: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E4CFu);
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->edi)) goto label_0008E4F3;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48E4DFu); lift_push32(cpu, r); sfera_sub_00403230(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) == 0u) goto label_0008E569;
    label_0008E4E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E4E7u);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x10u)) goto label_0008E519;
    cpu->ecx = lift_load32(cpu->esi);
    goto label_0008E51B;
    label_0008E4F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E4F3u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_0008E4E7;
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(0x10u)) goto label_0008E50D;
    cpu->eax = lift_load32(cpu->esi);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    lift_store8(cpu->eax, 0u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0008E50D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E50Du);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    lift_store8(cpu->eax, 0u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0008E519: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E519u);
    cpu->ecx = cpu->esi;
    label_0008E51B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E51Bu);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x10u)) goto label_0008E524;
    cpu->eax = lift_load32(cpu->esi);
    goto label_0008E526;
    label_0008E524: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E524u);
    cpu->eax = cpu->esi;
    label_0008E526: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E526u);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    cpu->edx -= cpu->ebx;
    lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->ebx;
    cpu->eax += cpu->ebx;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x48E534u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48E53Au);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48E54Bu); lift_push32(cpu, r); sfera_sub_0048DBA0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0008E563;
    cpu->eax = lift_load32(cpu->esi);
    lift_store8(cpu->eax + cpu->edi, 0u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0008E563: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E563u);
    cpu->eax = cpu->esi;
    lift_store8(cpu->eax + cpu->edi, 0u);
    label_0008E569: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E569u);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048E580(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48E580u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->edx = 0u;
    cpu->eax = cpu->esp;
    cpu->esi = cpu->ecx;
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x14u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0008E5AB;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0008E5AB;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_0008E5AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E5ABu);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x20u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0008E5D2;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0008E5D2;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_0008E5D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E5D2u);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x2Cu, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0008E5F9;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0008E5F9;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    label_0008E5F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E5F9u);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48E607u); lift_push32(cpu, r); sfera_sub_0048DDB0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 36u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048E610(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48E610u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->edx = 0u;
    cpu->eax = cpu->esp;
    cpu->esi = cpu->ecx;
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x14u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0008E63B;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0008E63B;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_0008E63B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E63Bu);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x20u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0008E662;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0008E662;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_0008E662: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E662u);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edx);
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->esp + 0x2Cu, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0008E689;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edx)) goto label_0008E689;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    label_0008E689: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E689u);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48E697u); lift_push32(cpu, r); sfera_sub_0048DE70(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 36u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048E6A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48E6A0u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->ecx = lift_load32(cpu->esi + 0xCu);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->edi);
    if ((uint8_t)(((cpu->ecx & 0xFFu)) & (3u)) != 0u) goto label_0008E6C9;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(2u), 32u);
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) > (uint32_t)(cpu->eax)) goto label_0008E6C9;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8E6C9u); lift_push32(cpu, r); sfera_sub_0048E110(cpu,r); if (cpu->eip != r) return; }
    label_0008E6C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E6C9u);
    cpu->ebx = lift_load32(cpu->esi + 0xCu);
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(lift_load32(cpu->esi + 0x10u)), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ebx = v; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    cpu->edi = cpu->ebx;
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->eax) > (uint32_t)(cpu->edi)) goto label_0008E6DD;
    cpu->edi -= cpu->eax;
    label_0008E6DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E6DDu);
    cpu->edx = lift_load32(cpu->esi + 4u);
    if ((uint32_t)(lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u))) != (uint32_t)(0u)) goto label_0008E6FA;
    lift_push32(cpu, 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48E6EDu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008E71E;
    cpu->ecx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u), cpu->eax);
    label_0008E6FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E6FAu);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u));
    cpu->ebx &= 3u;
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->ebx) * 4u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008E712;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    label_0008E712: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E712u);
    lift_store32(cpu->esi + 0x10u, (uint64_t)(lift_load32(cpu->esi + 0x10u)) + 1u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
    label_0008E71E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E71Eu);
    cpu->edx = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x10u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48E74Cu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x48E74Cu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048E750(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48E750u);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load8(cpu->esi + 0xCu)), r=(uint64_t)(3u), v=l & r; lift_flags_logic(cpu,v,8u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008E773;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(2u), 32u);
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) > (uint32_t)(cpu->eax)) goto label_0008E773;
    lift_push32(cpu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8E773u); lift_push32(cpu, r); sfera_sub_0048E110(cpu,r); if (cpu->eip != r) return; }
    label_0008E773: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E773u);
    cpu->ebx = lift_load32(cpu->esi + 0xCu);
    { uint64_t v=(uint64_t)(cpu->ebx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008E781;
    cpu->ebx = lift_load32(cpu->esi + 8u);
    cpu->ebx += cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(cpu->ebx), c=(uint64_t)(0u), v=l + r + c; lift_flags_add(cpu,l,r,c,v,32u); cpu->ebx = v; }
    label_0008E781: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E781u);
    cpu->ecx = lift_load32(cpu->esi + 4u);
    { uint64_t l=(uint64_t)(cpu->ebx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebx = v; }
    cpu->edi = cpu->ebx;
    cpu->edi = lift_shift_right(cpu, cpu->edi, (uint32_t)(2u), 32u);
    if ((uint32_t)(lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u))) != (uint32_t)(0u)) goto label_0008E7A4;
    lift_push32(cpu, 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48E797u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008E7CD;
    cpu->edx = lift_load32(cpu->esi + 4u);
    lift_store32(cpu->edx + ((uint32_t)(cpu->edi) * 4u), cpu->eax);
    label_0008E7A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E7A4u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    cpu->eax = cpu->ebx;
    cpu->eax &= 3u;
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008E7BE;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    cpu->ecx = lift_load32(cpu->edx);
    lift_store32(cpu->eax, cpu->ecx);
    label_0008E7BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E7BEu);
    lift_store32(cpu->esi + 0x10u, (uint64_t)(lift_load32(cpu->esi + 0x10u)) + 1u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    lift_return(cpu, 4u, stop_address); return;
    label_0008E7CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E7CDu);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x10u, 0u);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48E7FBu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x48E7FBu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048E800(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48E800u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x3Cu;
    cpu->eax = lift_load32(cpu->ebp + 0x14u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ebp + 0x1Cu);
    cpu->eax -= cpu->esi;
    cpu->ebx = cpu->edi;
    cpu->ebx -= cpu->esi;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    cpu->eax = cpu->ebx;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->esi) <= (uint32_t)(cpu->edi)) goto label_0008E82D;
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    label_0008E82D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E82Du);
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0008E844;
    label_0008E835: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E835u);
    cpu->edx = ((int32_t)cpu->eax < 0) ? 0xFFFFFFFFu : 0u;
    lift_divide_accumulator(cpu, cpu->ecx, 32u, 1u);
    cpu->eax = cpu->ecx;
    cpu->ecx = cpu->edx;
    if ((uint32_t)(cpu->edx) != 0u) goto label_0008E835;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    label_0008E844: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E844u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0008E944;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_0008E944;
    goto label_0008E859;
    label_0008E856: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E856u);
    cpu->edi = lift_load32(cpu->ebp + 0x1Cu);
    label_0008E859: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E859u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    lift_store32(cpu->esp + 0x44u, cpu->esi);
    cpu->esi += cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->eax += cpu->esi;
    lift_store32(cpu->esp + 0x44u, cpu->esi);
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    cpu->ebx = cpu->esi;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008E87B;
    cpu->eax = (uint32_t)(cpu->ebp + 8u);
    goto label_0008E88B;
    label_0008E87B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E87Bu);
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    label_0008E88B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E88Bu);
    cpu->edi = lift_load32(cpu->eax);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    label_0008E890: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E890u);
    cpu->edx = lift_load32(cpu->edi + 8u);
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->ecx;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(2u), 32u);
    cpu->eax &= 3u;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->esi)) goto label_0008E8A3;
    cpu->esi -= cpu->edx;
    label_0008E8A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E8A3u);
    cpu->edx = cpu->ebx;
    { uint64_t l=(uint64_t)(cpu->ebx), r=(uint64_t)(3u), v=l & r; lift_flags_logic(cpu,v,32u); cpu->ebx = v; }
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x20u);
    cpu->ebx = lift_load32(cpu->ebx + 8u);
    cpu->edx = lift_shift_right(cpu, cpu->edx, (uint32_t)(2u), 32u);
    if ((uint32_t)(cpu->ebx) > (uint32_t)(cpu->edx)) goto label_0008E8BC;
    cpu->edx -= cpu->ebx;
    label_0008E8BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E8BCu);
    cpu->ebx = lift_load32(cpu->edi + 4u);
    cpu->esi = lift_load32(cpu->ebx + ((uint32_t)(cpu->esi) * 4u));
    cpu->ebx = lift_load32(cpu->esi + ((uint32_t)(cpu->eax) * 4u));
    cpu->esi = (uint32_t)(cpu->esi + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->eax + ((uint32_t)(cpu->edx) * 4u));
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->edx = (uint32_t)(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->edx);
    lift_store32(cpu->edx, cpu->ebx);
    lift_store32(cpu->esi, cpu->eax);
    cpu->edx = lift_load32(cpu->ebp + 0x1Cu);
    cpu->esi = lift_load32(cpu->ebp + 0xCu);
    cpu->edx -= cpu->ecx;
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    cpu->ebx = cpu->ecx;
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x10u)) >= (int32_t)(uint32_t)(cpu->edx)) goto label_0008E909;
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    cpu->ecx += lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x30u, cpu->edi);
    lift_store32(cpu->esp + 0x34u, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    goto label_0008E924;
    label_0008E909: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E909u);
    cpu->eax = lift_load32(cpu->ebp + 8u);
    cpu->ecx = cpu->esi;
    cpu->ecx -= cpu->edx;
    cpu->ecx += lift_load32(cpu->esp + 0x10u);
    lift_store32(cpu->esp + 0x38u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    lift_store32(cpu->esp + 0x3Cu, cpu->ecx);
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    label_0008E924: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E924u);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edi = lift_load32(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(lift_load32(cpu->esp + 0x44u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008E890;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    --cpu->eax;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) > 0) goto label_0008E856;
    label_0008E944: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E944u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 24u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048E950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48E950u);
    cpu->esp -= 0x44u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebx = cpu->edx;
    cpu->eax = lift_load32(cpu->ebx + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x58u);
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->ecx);
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    lift_store32(cpu->esp + 0xCu, cpu->esi);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008E996;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x44u;
    lift_return(cpu, 8u, stop_address); return;
    label_0008E996: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E996u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(0xFFFFFFFFu)) goto label_0008E9B5;
    lift_store32(cpu->edx, cpu->ecx);
    lift_store32(cpu->esi, cpu->ecx);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x44u;
    lift_return(cpu, 8u, stop_address); return;
    label_0008E9B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E9B5u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008EA58;
    label_0008E9C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E9C0u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48E9D2u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48E9D9u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008E9E3;
    lift_flags_logic(cpu,0u,32u); cpu->esi = 0u;
    goto label_0008E9E5;
    label_0008E9E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E9E3u);
    cpu->esi = lift_load32(cpu->ecx);
    label_0008E9E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E9E5u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->eax &= 3u;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->ecx)) goto label_0008E9F9;
    cpu->ecx -= cpu->edx;
    label_0008E9F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x48E9F9u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->esi = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = cpu->esi;
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48EA0Au);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48EA11u); lift_push32(cpu, r); sfera_sub_004312C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0008EA42;
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48EA21u); lift_push32(cpu, r); sfera_sub_004314D0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x48u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = lift_load32(cpu->eax + 0x10u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0008EA38;
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48EA35u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008EA38: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EA38u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->ebp += cpu->esi;
    if ((uint32_t)(cpu->ebp) > (uint32_t)(cpu->eax)) goto label_0008EA7F;
    label_0008EA42: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EA42u);
    ++cpu->edi;
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->ebx + 0x10u))) goto label_0008E9C0;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->esi = lift_load32(cpu->esp + 0x10u);
    label_0008EA58: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EA58u);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->ebp)) goto label_0008EAA6;
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->edx, 0xFFFFFFFFu);
    lift_store32(cpu->esi, 0xFFFFFFFFu);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x44u;
    lift_return(cpu, 8u, stop_address); return;
    label_0008EA7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EA7Fu);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    cpu->esi -= cpu->ebp;
    cpu->esi += cpu->eax;
    lift_store32(cpu->ecx, cpu->edi);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->edx, cpu->esi);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x44u;
    lift_return(cpu, 8u, stop_address); return;
    label_0008EAA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EAA6u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esp += 0x44u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048EAC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48EAC0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->esp -= 0x18u;
    if ((uint32_t)(lift_load32(cpu->ecx + 0x10u)) > (uint32_t)(cpu->eax)) goto label_0008EAD7;
    lift_push32(cpu, (uint32_t)(uintptr_t)"invalid deque<T> subscript");
    lift_trap(cpu, cpu->eip, "std::out_of_range");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x8EAD7u);
    label_0008EAD7: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EAD7u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48EAE8u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48EAEFu); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008EAF9;
    lift_flags_logic(cpu,0u,32u); cpu->esi = 0u;
    goto label_0008EAFB;
    label_0008EAF9: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EAF9u);
    cpu->esi = lift_load32(cpu->ecx);
    label_0008EAFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EAFBu);
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->eax &= 3u;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->ecx)) goto label_0008EB0F;
    cpu->ecx -= cpu->edx;
    label_0008EB0F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EB0Fu);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048EB20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48EB20u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48EB38u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48EB3Fu); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008EB49;
    lift_flags_logic(cpu,0u,32u); cpu->esi = 0u;
    goto label_0008EB4B;
    label_0008EB49: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EB49u);
    cpu->esi = lift_load32(cpu->ecx);
    label_0008EB4B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EB4Bu);
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->eax &= 3u;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->ecx)) goto label_0008EB5F;
    cpu->ecx -= cpu->edx;
    label_0008EB5F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EB5Fu);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048EB70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48EB70u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48EB85u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48EB8Cu); lift_push32(cpu, r); sfera_sub_0048E0A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008EB96;
    lift_flags_logic(cpu,0u,32u); cpu->esi = 0u;
    goto label_0008EB98;
    label_0008EB96: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EB96u);
    cpu->esi = lift_load32(cpu->ecx);
    label_0008EB98: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EB98u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->eax &= 3u;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->ecx)) goto label_0008EBAC;
    cpu->ecx -= cpu->edx;
    label_0008EBAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EBACu);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->eax = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048EBC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48EBC0u);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 0xCu;
    cpu->ebx = 0u;
    cpu->eax = cpu->esp;
    cpu->esi = cpu->ecx;
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x4Cu);
    lift_store32(cpu->esp + 0x1Cu, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0008EBEB;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0008EBEB;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_0008EBEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EBEBu);
    cpu->edx = lift_load32(cpu->esp + 0x54u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48EBFEu); lift_push32(cpu, r); sfera_sub_0049F9C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x58u);
    lift_store32(cpu->esp + 0x1Cu, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0008EC1E;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0008EC1E;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_0008EC1E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EC1Eu);
    cpu->edx = lift_load32(cpu->esp + 0x60u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48EC31u); lift_push32(cpu, r); sfera_sub_0049F9C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48EC3Du); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->edi = lift_load32(cpu->esp + 0x28u);
    cpu->edx = cpu->eax;
    cpu->edx -= cpu->ecx;
    lift_store32(cpu->esp + 0x10u, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    cpu->ebp = cpu->edi;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    cpu->ebp -= cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48EC60u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->eax + 8u);
    cpu->eax -= cpu->edi;
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->eax), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_CF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->esp -= 0xCu;
    { uint64_t l=(uint64_t)((cpu->eax & 0xFFu)), r=(uint64_t)((cpu->ebx & 0xFFu)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,8u); }
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x1Cu, cpu->esp);
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0008ED14;
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0008EC96;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0008EC96;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_0008EC96: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EC96u);
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 0x28u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0008ECBD;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0008ECBD;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_0008ECBD: cpu->eip = LIFT_CODE_TOKEN_VA(0x48ECBDu);
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    cpu->esp -= 0xCu;
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x34u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48ECD5u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48ECDEu); lift_push32(cpu, r); sfera_sub_0048E580(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->ebp) <= (uint32_t)(cpu->ebx)) goto label_0008ED85;
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_0008ECF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x48ECF0u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0008ED0C;
    cpu->edx = lift_load32(cpu->esi + 8u);
    lift_store32(cpu->esi + 0xCu, (uint64_t)(lift_load32(cpu->esi + 0xCu)) + 1u);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    if ((uint32_t)(cpu->edx) > (uint32_t)(lift_load32(cpu->esi + 0xCu))) goto label_0008ED06;
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    label_0008ED06: cpu->eip = LIFT_CODE_TOKEN_VA(0x48ED06u);
    { uint64_t l=(uint64_t)(cpu->ecx), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ecx = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008ED0C;
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    label_0008ED0C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48ED0Cu);
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008ECF0;
    lift_store32(cpu->esi + 0x10u, cpu->ecx);
    goto label_0008ED85;
    label_0008ED14: cpu->eip = LIFT_CODE_TOKEN_VA(0x48ED14u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0008ED26;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0008ED26;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_0008ED26: cpu->eip = LIFT_CODE_TOKEN_VA(0x48ED26u);
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    cpu->esp -= 0xCu;
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x28u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48ED3Eu); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->ebx);
    lift_store32(cpu->eax + 4u, cpu->ebx);
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    lift_store32(cpu->esp + 0x34u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0008ED5E;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0008ED5E;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_0008ED5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48ED5Eu);
    cpu->edx = lift_load32(cpu->esp + 0x4Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48ED6Eu); lift_push32(cpu, r); sfera_sub_0048E610(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->ebp) <= (uint32_t)(cpu->ebx)) goto label_0008ED85;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    label_0008ED75: cpu->eip = LIFT_CODE_TOKEN_VA(0x48ED75u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_0008ED7F;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008ED7F;
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    label_0008ED7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48ED7Fu);
    { uint64_t l=(uint64_t)(cpu->ebp), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->ebp = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008ED75;
    lift_store32(cpu->esi + 0x10u, cpu->eax);
    label_0008ED85: cpu->eip = LIFT_CODE_TOKEN_VA(0x48ED85u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48ED97u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48ED9Eu); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x28u;
    lift_return(cpu, 28u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048EDB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48EDB0u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->eax;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->ebx)) goto label_0008EDCF;
    lift_push32(cpu, (uint32_t)(uintptr_t)"string too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x8EDCFu);
    label_0008EDCF: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EDCFu);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0008EE4D;
    cpu->edi = (uint32_t)(cpu->eax + cpu->ebx);
    if ((uint32_t)(cpu->edi) <= (uint32_t)(0xFFFFFFFEu)) goto label_0008EDE7;
    lift_push32(cpu, (uint32_t)(uintptr_t)"string too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x8EDE7u);
    label_0008EDE7: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EDE7u);
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->edi)) goto label_0008EE23;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48EDF7u); lift_push32(cpu, r); sfera_sub_00403230(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) == 0u) goto label_0008EE4D;
    label_0008EDFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EDFBu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48EE0Cu); lift_push32(cpu, r); sfera_sub_0048DBA0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0008EE47;
    cpu->eax = lift_load32(cpu->esi);
    lift_store8(cpu->eax + cpu->edi, 0u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0008EE23: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EE23u);
    if ((uint32_t)(cpu->edi) != 0u) goto label_0008EDFB;
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(0x10u)) goto label_0008EE3C;
    cpu->eax = lift_load32(cpu->esi);
    cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->eax, 0u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0008EE3C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EE3Cu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    lift_store8(cpu->eax, 0u);
    cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0008EE47: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EE47u);
    cpu->eax = cpu->esi;
    lift_store8(cpu->eax + cpu->edi, 0u);
    label_0008EE4D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EE4Du);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048EE60(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48EE60u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->ebp)) goto label_0008EFD1;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->eax = lift_load32(cpu->eax + 0x10u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->edx)) goto label_0008EFD1;
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax -= cpu->edx;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edi)) goto label_0008EE93;
    cpu->edi = cpu->eax;
    label_0008EE93: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EE93u);
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->ecx;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->edi)) goto label_0008EEA7;
    lift_push32(cpu, (uint32_t)(uintptr_t)"string too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x8EEA7u);
    label_0008EEA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EEA7u);
    lift_push32(cpu, cpu->ebx);
    if ((uint32_t)(cpu->edi) == 0u) goto label_0008EFC8;
    cpu->ebx = (uint32_t)(cpu->ecx + cpu->edi);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((uint32_t)(cpu->ebx) <= (uint32_t)(0xFFFFFFFEu)) goto label_0008EEC7;
    lift_push32(cpu, (uint32_t)(uintptr_t)"string too long");
    lift_trap(cpu, cpu->eip, "std::length_error");
    cpu->eip = LIFT_CODE_TOKEN_RVA(0x8EEC7u);
    label_0008EEC7: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EEC7u);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ebx)) goto label_0008EEEB;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48EED7u); lift_push32(cpu, r); sfera_sub_00403230(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0008EFC8;
    label_0008EEDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EEDFu);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x10u)) goto label_0008EF10;
    cpu->ecx = lift_load32(cpu->esi);
    goto label_0008EF12;
    label_0008EEEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EEEBu);
    if ((uint32_t)(cpu->ebx) != 0u) goto label_0008EEDF;
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x10u)) goto label_0008EF04;
    cpu->eax = lift_load32(cpu->esi);
    lift_store8(cpu->eax, cpu->ebx & 0xFFu);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_0008EF04: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EF04u);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    lift_store8(cpu->eax, 0u);
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_0008EF10: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EF10u);
    cpu->ecx = cpu->esi;
    label_0008EF12: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EF12u);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x10u)) goto label_0008EF1B;
    cpu->eax = lift_load32(cpu->esi);
    goto label_0008EF1D;
    label_0008EF1B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EF1Bu);
    cpu->eax = cpu->esi;
    label_0008EF1D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EF1Du);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    cpu->ebx = native_function_address32(&::memmove);
    cpu->edx -= cpu->ebp;
    lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->ebp;
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->edi;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x8EF33u), LIFT_CODE_TOKEN_RVA(0x8EF31u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48EF33u);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->esp += 0xCu;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->ecx)) goto label_0008EF7F;
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->ebp) >= (uint32_t)(cpu->edx)) goto label_0008EF48;
    cpu->edx += cpu->edi;
    label_0008EF48: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EF48u);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x10u)) goto label_0008EF54;
    cpu->ecx = lift_load32(cpu->esi);
    goto label_0008EF56;
    label_0008EF54: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EF54u);
    cpu->ecx = cpu->esi;
    label_0008EF56: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EF56u);
    if ((uint32_t)(cpu->eax) < (uint32_t)(0x10u)) goto label_0008EF6D;
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->edi);
    cpu->ecx += cpu->edx;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x8EF66u), LIFT_CODE_TOKEN_RVA(0x8EF64u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48EF66u);
    cpu->ebx = 0x10u;
    goto label_0008EFA4;
    label_0008EF6D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EF6Du);
    lift_push32(cpu, cpu->edi);
    cpu->ecx += cpu->edx;
    cpu->eax = cpu->esi;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebx), LIFT_CODE_TOKEN_RVA(0x8EF78u), LIFT_CODE_TOKEN_RVA(0x8EF76u))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48EF78u);
    cpu->ebx = 0x10u;
    goto label_0008EFA4;
    label_0008EF7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EF7Fu);
    cpu->ebx = 0x10u;
    if ((uint32_t)(lift_load32(cpu->ecx + 0x14u)) < (uint32_t)(cpu->ebx)) goto label_0008EF8B;
    cpu->ecx = lift_load32(cpu->ecx);
    label_0008EF8B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EF8Bu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(cpu->ebx)) goto label_0008EF94;
    cpu->eax = lift_load32(cpu->esi);
    goto label_0008EF96;
    label_0008EF94: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EF94u);
    cpu->eax = cpu->esi;
    label_0008EF96: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EF96u);
    cpu->ecx += lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x48EF9Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48EFA4u);
    label_0008EFA4: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EFA4u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    cpu->esp += 0xCu;
    lift_store32(cpu->esi + 0x10u, cpu->ecx);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(cpu->ebx)) goto label_0008EFC2;
    cpu->eax = lift_load32(cpu->esi);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    lift_store8(cpu->eax + cpu->ecx, 0u);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_0008EFC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EFC2u);
    cpu->eax = cpu->esi;
    lift_store8(cpu->eax + cpu->ecx, 0u);
    label_0008EFC8: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EFC8u);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_0008EFD1: cpu->eip = LIFT_CODE_TOKEN_VA(0x48EFD1u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"invalid string position");
    lift_trap(cpu, cpu->eip, "std::out_of_range");
    lift_trap(cpu, 0x48EFDCu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048EFE0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48EFE0u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    cpu->ebx = cpu->edx;
    lift_store8(cpu->esp + 0x1Cu, 0x3Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F001u); lift_push32(cpu, r); sfera_sub_004312E0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->esi = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_store8(cpu->esp + 0x24u, 0x3Eu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F017u); lift_push32(cpu, r); sfera_sub_004312E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_0008F063;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(0xFFFFFFFFu)) goto label_0008F063;
    cpu->eax -= cpu->esi;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(1u)) goto label_0008F063;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0008F03C;
    --cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esi + 1u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8F03Cu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    label_0008F03C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F03Cu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008F046;
    lift_store32(cpu->eax, cpu->esi);
    label_0008F046: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F046u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008F059;
    ++cpu->ebp;
    if ((uint32_t)(cpu->ebp) < (uint32_t)(lift_load32(cpu->edi + 0x10u))) goto label_0008F057;
    cpu->ebp |= 0xFFFFFFFFu;
    label_0008F057: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F057u);
    lift_store32(cpu->eax, cpu->ebp);
    label_0008F059: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F059u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
    label_0008F063: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F063u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008F071;
    lift_store32(cpu->eax, 0xFFFFFFFFu);
    label_0008F071: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F071u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008F07F;
    lift_store32(cpu->eax, 0xFFFFFFFFu);
    label_0008F07F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F07Fu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048F090(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48F090u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x14u, cpu->esp);
    lift_push32(cpu, 1u);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F0AAu); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->esp + 0x20u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0008F0D2;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0008F0D2;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_0008F0D2: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F0D2u);
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    cpu->esi = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_store32(cpu->eax + 8u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F0E5u); lift_push32(cpu, r); sfera_sub_0048EBC0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048F0F0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48F0F0u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_0008F17B;
    cpu->ebp = lift_load32(cpu->esp + 0x34u);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->ebp)) goto label_0008F17B;
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008F11E;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008F11E;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008F122;
    label_0008F11E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F11Eu);
    cpu->edx = 0u;
    goto label_0008F124;
    label_0008F122: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F122u);
    cpu->edx = lift_load32(cpu->eax);
    label_0008F124: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F124u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008F138;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008F138;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008F13C;
    label_0008F138: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F138u);
    cpu->ecx = 0u;
    goto label_0008F13E;
    label_0008F13C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F13Cu);
    cpu->ecx = lift_load32(cpu->eax);
    label_0008F13E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F13Eu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008F152;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008F152;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008F156;
    label_0008F152: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F152u);
    cpu->eax = 0u;
    goto label_0008F158;
    label_0008F156: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F156u);
    cpu->eax = lift_load32(cpu->eax);
    label_0008F158: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F158u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F167u); lift_push32(cpu, r); sfera_sub_0048E800(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax -= cpu->ecx;
    cpu->esi += cpu->eax;
    lift_store32(cpu->esp + 0x1Cu, cpu->esi);
    label_0008F17B: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F17Bu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->edi, 0u);
    lift_store32(cpu->edi + 4u, 0u);
    lift_store32(cpu->edi + 8u, cpu->esi);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008F19D;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008F19D;
    cpu->eax = lift_load32(cpu->eax);
    lift_store32(cpu->edi, cpu->eax);
    label_0008F19D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F19Du);
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 36u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048F1B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48F1B0u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x4Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->ebp + 0xFFFFFFF0u, cpu->esp);
    cpu->edi = cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFE8u, cpu->edi);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F1E9u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->eax -= cpu->ecx;
    cpu->ecx = lift_load32(cpu->edi + 0x10u);
    lift_store32(cpu->ebp + 0xFFFFFFECu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0x1Cu);
    cpu->ebx = cpu->ecx;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->ebx);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(lift_load32(cpu->ebp + 0x28u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0008F400;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    if ((uint32_t)(lift_load32(cpu->ebp + 0xFFFFFFECu)) > (uint32_t)(cpu->ecx)) goto label_0008F348;
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 0u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0008F220: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F220u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebp + 0x28u))) goto label_0008F27D;
    cpu->ecx = lift_load32(cpu->ebp + 0x14u);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008F230;
    lift_flags_logic(cpu,0u,32u); cpu->esi = 0u;
    goto label_0008F232;
    label_0008F230: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F230u);
    cpu->esi = lift_load32(cpu->ecx);
    label_0008F232: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F232u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->eax &= 3u;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->ecx)) goto label_0008F243;
    cpu->ecx -= cpu->edx;
    label_0008F243: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F243u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F254u); lift_push32(cpu, r); sfera_sub_0048E750(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0x1Cu);
    ++cpu->eax;
    lift_store32(cpu->ebp + 0x1Cu, cpu->eax);
    goto label_0008F220;
    label_0008F27D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F27Du);
    cpu->esi = lift_load32(cpu->edi + 0x10u);
    cpu->esi -= cpu->ebx;
    lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFC0u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F292u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F299u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F2A4u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008F2BB;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008F2BB;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008F2BF;
    label_0008F2BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F2BBu);
    cpu->ecx = 0u;
    goto label_0008F2C1;
    label_0008F2BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F2BFu);
    cpu->ecx = lift_load32(cpu->eax);
    label_0008F2C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F2C1u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->ecx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008F2D9;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008F2D9;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008F2DD;
    label_0008F2D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F2D9u);
    cpu->ecx = 0u;
    goto label_0008F2DF;
    label_0008F2DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F2DDu);
    cpu->ecx = lift_load32(cpu->eax);
    label_0008F2DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F2DFu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F2E9u); lift_push32(cpu, r); sfera_sub_0048DF30(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFC0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F306u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F30Du); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F314u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFB4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F329u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F330u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F340u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFA8u);
    goto label_0008F3FB;
    label_0008F348: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F348u);
    lift_store32(cpu->ebp + 0xFFFFFFFCu, 2u);
    (void)cpu;
    label_0008F350: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F350u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->ebp + 0x28u))) goto label_0008F3AD;
    cpu->ecx = lift_load32(cpu->ebp + 0x14u);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008F360;
    lift_flags_logic(cpu,0u,32u); cpu->esi = 0u;
    goto label_0008F362;
    label_0008F360: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F360u);
    cpu->esi = lift_load32(cpu->ecx);
    label_0008F362: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F362u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->ecx = cpu->eax;
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(2u), 32u);
    cpu->eax &= 3u;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->ecx)) goto label_0008F373;
    cpu->ecx -= cpu->edx;
    label_0008F373: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F373u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->edx = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F384u); lift_push32(cpu, r); sfera_sub_0048E6A0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0x1Cu);
    ++cpu->eax;
    lift_store32(cpu->ebp + 0x1Cu, cpu->eax);
    goto label_0008F350;
    label_0008F3AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F3ADu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F3BDu); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFA8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F3D2u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F3D9u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFB4u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F3F1u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F3F8u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFC0u);
    label_0008F3FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F3FBu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8F400u); lift_push32(cpu, r); sfera_sub_0048F0F0(cpu,r); if (cpu->eip != r) return; }
    label_0008F400: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F400u);
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 40u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048F25D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48F25Du);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_0008F274;
    label_0008F268: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F268u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F26Fu); lift_push32(cpu, r); sfera_sub_0048E0E0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_0008F268;
    label_0008F274: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F274u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F27Du); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->edi + 0x10u);
    cpu->esi -= cpu->ebx;
    lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFD8u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFC0u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F292u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F299u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F2A4u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->ebp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFD8u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008F2BB;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008F2BB;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008F2BF;
    label_0008F2BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F2BBu);
    cpu->ecx = 0u;
    goto label_0008F2C1;
    label_0008F2BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F2BFu);
    cpu->ecx = lift_load32(cpu->eax);
    label_0008F2C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F2C1u);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->ecx);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008F2D9;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008F2D9;
    cpu->eax = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->eax) != 0u) goto label_0008F2DD;
    label_0008F2D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F2D9u);
    cpu->ecx = 0u;
    goto label_0008F2DF;
    label_0008F2DD: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F2DDu);
    cpu->ecx = lift_load32(cpu->eax);
    label_0008F2DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F2DFu);
    cpu->eax = lift_load32(cpu->ebp + 0xFFFFFFD4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F2E9u); lift_push32(cpu, r); sfera_sub_0048DF30(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFC0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F306u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F30Du); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F314u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->ebp + 0xFFFFFFB4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F329u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F330u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F340u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFA8u);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48F3FBu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F400u); lift_push32(cpu, r); sfera_sub_0048F0F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 40u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048F38D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48F38Du);
    cpu->esi = lift_load32(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = lift_load32(cpu->ebp + 0xFFFFFFE4u);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_0008F3A4;
    label_0008F398: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F398u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F39Fu); lift_push32(cpu, r); sfera_sub_0049FA20(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_0008F398;
    label_0008F3A4: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F3A4u);
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F3ADu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F3BDu); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFA8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F3D2u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F3D9u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFECu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->ebp + 0xFFFFFFE4u, cpu->esp);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->ebp + 0xFFFFFFB4u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F3F1u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F3F8u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->ebp + 0xFFFFFFC0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F400u); lift_push32(cpu, r); sfera_sub_0048F0F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp + 0xFFFFFFF4u);
    lift_fs_store32(cpu, 0u, cpu->ecx);
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 40u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048F420(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48F420u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x48u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x5Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->ecx;
    cpu->ebx = cpu->edx;
    if ((uint32_t)(lift_load32(cpu->edi + 0x10u)) <= (uint32_t)(cpu->ebx)) goto label_0008F5B4;
    if ((uint32_t)(lift_load32(cpu->esp + 0x6Cu)) == (uint32_t)(0xFFFFFFFFu)) goto label_0008F5B4;
    lift_push32(cpu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F470u); lift_push32(cpu, r); sfera_sub_0048EAC0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->eax);
    cpu->ecx = cpu->esi;
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48F47Au);
    cpu->ebp = cpu->eax;
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F483u); lift_push32(cpu, r); sfera_sub_004312C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0008F5B4;
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F497u); lift_push32(cpu, r); sfera_sub_004314D0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x4Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x6Cu);
    lift_store32(cpu->esp + 0x64u, 0u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->ecx)) goto label_0008F4B0;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    goto label_0008F4B4;
    label_0008F4B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F4B0u);
    lift_push32(cpu, 0xFFFFFFFFu);
    --cpu->eax;
    lift_push32(cpu, cpu->eax);
    label_0008F4B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F4B4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F4BDu); lift_push32(cpu, r); sfera_sub_00402810(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esp + 0x4Cu)) == (uint32_t)(0u)) goto label_0008F550;
    cpu->eax = cpu->ebp;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(4u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0008F542;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008F59C;
    cpu->edx = 0x220u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F4E5u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F4EBu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->edx = 0x221u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F4FDu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F504u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store8(cpu->esp + 0x64u, 1u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008F534;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F526u); lift_push32(cpu, r); sfera_sub_004315D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    cpu->esi = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F530u); lift_push32(cpu, r); sfera_sub_0048EB20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->eax, cpu->esi);
    goto label_0008F59C;
    label_0008F534: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F534u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    cpu->esi = 0u;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F53Eu); lift_push32(cpu, r); sfera_sub_0048EB20(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->eax, cpu->esi);
    goto label_0008F59C;
    label_0008F542: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F542u);
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F54Eu); lift_push32(cpu, r); sfera_sub_004317E0(cpu,r); if (cpu->eip != r) return; }
    goto label_0008F59C;
    label_0008F550: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F550u);
    cpu->edx = 0x227u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F55Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F565u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F57Au); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F581u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->esp + 0x20u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F590u); lift_push32(cpu, r); sfera_sub_0048DD80(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8F59Cu); lift_push32(cpu, r); sfera_sub_0048F090(cpu,r); if (cpu->eip != r) return; }
    label_0008F59C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F59Cu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x50u)) < (uint32_t)(0x10u)) goto label_0008F5B0;
    cpu->eax = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F5ADu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008F5B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F5B0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    goto label_0008F5B6;
    label_0008F5B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F5B4u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    label_0008F5B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F5B6u);
    cpu->ecx = lift_load32(cpu->esp + 0x5Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x54u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048F5E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48F5E0u);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->ebp + 0x10u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0008F6B4;
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F5FDu); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F609u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->esi) == (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_0008F6B4;
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_0008F620: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F620u);
    cpu->edx = 0x356u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F62Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->ebx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0008F637;
    lift_flags_logic(cpu,0u,32u); cpu->edx = 0u;
    goto label_0008F639;
    label_0008F637: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F637u);
    cpu->edx = lift_load32(cpu->ebx);
    label_0008F639: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F639u);
    cpu->edi = lift_load32(cpu->edx + 8u);
    cpu->eax = cpu->esi;
    cpu->ecx = cpu->esi;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ecx &= 3u;
    if ((uint32_t)(cpu->edi) > (uint32_t)(cpu->eax)) goto label_0008F64C;
    cpu->eax -= cpu->edi;
    label_0008F64C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F64Cu);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F65Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 8u;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x1Cu, cpu->esp);
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0008F67F;
    cpu->ecx = lift_load32(cpu->ebx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0008F67F;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    label_0008F67F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F67Fu);
    lift_store32(cpu->eax + 8u, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F68Eu); lift_push32(cpu, r); sfera_sub_0048F090(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->ecx)) goto label_0008F69C;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0008F69C;
    cpu->ebx = lift_load32(cpu->ecx);
    label_0008F69C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F69Cu);
    cpu->esi = lift_load32(cpu->eax + 8u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F6ABu); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_0008F620;
    label_0008F6B4: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F6B4u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048F6C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48F6C0u);
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 8u);
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F6D1u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->eax = lift_load32(cpu->esp + 0x48u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->ecx), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->ecx = lift_shift_right(cpu, cpu->ecx, (uint32_t)(1u), 32u);
    cpu->edi = cpu->eax;
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(cpu->ecx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = cpu->esi;
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u) goto label_0008F753;
    cpu->edx = lift_load32(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F6F1u); lift_push32(cpu, r); sfera_sub_0048E750(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x58u, cpu->esp);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F70Fu); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F716u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F71Du); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x64u, cpu->esp);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F735u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F73Cu); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->esp + 0x70u, cpu->esp);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F74Du); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    goto label_0008F7AF;
    label_0008F753: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F753u);
    cpu->eax = lift_load32(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F75Du); lift_push32(cpu, r); sfera_sub_0048E6A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->esp + 0x58u, cpu->esp);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F76Eu); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    lift_store32(cpu->esp + 0x64u, cpu->esp);
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F786u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F78Du); lift_push32(cpu, r); sfera_sub_0048E0A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->esp + 0x70u, cpu->esp);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F7A4u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F7ABu); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    label_0008F7AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F7AFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F7B4u); lift_push32(cpu, r); sfera_sub_0048F0F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F7C6u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F7CDu); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048F7E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48F7E0u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x10u, cpu->esp);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0008F80E;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0008F80E;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->eax, cpu->edx);
    label_0008F80E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F80Eu);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x1Cu, cpu->esp);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0008F83D;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0008F83D;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->eax, cpu->edx);
    label_0008F83D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F83Du);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->esp + 0x28u, cpu->esp);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0008F86C;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0008F86C;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->eax, cpu->edx);
    label_0008F86C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F86Cu);
    cpu->edx = lift_load32(cpu->esp + 0x38u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F878u); lift_push32(cpu, r); sfera_sub_0048F1B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 36u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048F880(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48F880u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = lift_load32(cpu->esp + 0x50u);
    cpu->edi = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, (uint32_t)(uintptr_t)"");
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    cpu->ebx = cpu->edx;
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    lift_store32(cpu->esp + 0x38u, 0xFu);
    lift_store32(cpu->esp + 0x34u, cpu->edi);
    lift_store8(cpu->esp + 0x24u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F8E0u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->esp + 0x44u, cpu->edi);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(cpu->edi), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->edi = lift_load32(cpu->esp + 0x4Cu);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0008F9DC;
    if ((uint32_t)(cpu->edi) == (uint32_t)(0xFFFFFFFFu)) goto label_0008F9DC;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->eax)) goto label_0008F9DC;
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_0008F90E;
    cpu->eax = lift_load32(cpu->esi);
    goto label_0008F910;
    label_0008F90E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F90Eu);
    cpu->eax = cpu->esi;
    label_0008F910: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F910u);
    cpu->eax = (int8_t)(lift_load8(cpu->eax + cpu->edi));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::isalpha), LIFT_CODE_TOKEN_VA(0x48F915u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x48F91Bu);
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008F9DC;
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_0008F930;
    cpu->eax = lift_load32(cpu->esi);
    goto label_0008F932;
    label_0008F930: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F930u);
    cpu->eax = cpu->esi;
    label_0008F932: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F932u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + cpu->edi)) & 0xFFu);
    lift_store8(cpu->esp + 0x14u, cpu->ecx & 0xFFu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F949u); lift_push32(cpu, r); sfera_sub_0048EDB0(cpu,r); if (cpu->eip != r) return; }
    ++cpu->edi;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_0008F9A1;
    cpu->ebp = native_function_address32(&::isalnum);
    label_0008F955: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F955u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(0xFFFFFFFFu)) goto label_0008F99D;
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_0008F964;
    cpu->eax = lift_load32(cpu->esi);
    goto label_0008F966;
    label_0008F964: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F964u);
    cpu->eax = cpu->esi;
    label_0008F966: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F966u);
    cpu->eax = (int8_t)(lift_load8(cpu->eax + cpu->edi));
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, (uint32_t)(cpu->ebp), LIFT_CODE_TOKEN_RVA(0x8F96Du), LIFT_CODE_TOKEN_RVA(0x8F96Bu))) { return; }
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48F96Du);
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0008F99D;
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_0008F97E;
    cpu->eax = lift_load32(cpu->esi);
    goto label_0008F980;
    label_0008F97E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F97Eu);
    cpu->eax = cpu->esi;
    label_0008F980: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F980u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + cpu->edi)) & 0xFFu);
    lift_store8(cpu->esp + 0x14u, cpu->ecx & 0xFFu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F997u); lift_push32(cpu, r); sfera_sub_0048EDB0(cpu,r); if (cpu->eip != r) return; }
    ++cpu->edi;
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_0008F955;
    label_0008F99D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F99Du);
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    label_0008F9A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F9A1u);
    if ((uint32_t)(cpu->ebx) == 0u) goto label_0008F9B5;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8F9B5u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    label_0008F9B5: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F9B5u);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_0008F9C4;
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_0008F9C1;
    cpu->edi |= 0xFFFFFFFFu;
    label_0008F9C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F9C1u);
    lift_store32(cpu->ebp, cpu->edi);
    label_0008F9C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F9C4u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x30u)) < (uint32_t)(0x10u)) goto label_0008F9D8;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F9D5u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008F9D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F9D8u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    goto label_0008F9F9;
    label_0008F9DC: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F9DCu);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_0008F9E3;
    lift_store32(cpu->ebp, cpu->edi);
    label_0008F9E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F9E3u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x30u)) < (uint32_t)(0x10u)) goto label_0008F9F7;
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48F9F4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008F9F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F9F7u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    label_0008F9F9: cpu->eip = LIFT_CODE_TOKEN_VA(0x48F9F9u);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048FA20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48FA20u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x48u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x5Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = lift_load32(cpu->esp + 0x70u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx);
    cpu->esi = cpu->ecx;
    cpu->edi = 0xFu;
    lift_push32(cpu, (uint32_t)(uintptr_t)"");
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    cpu->ebp = cpu->edx;
    lift_store32(cpu->esp + 0x20u, cpu->eax);
    lift_store32(cpu->esp + 0x58u, cpu->edi);
    lift_store32(cpu->esp + 0x54u, cpu->ebx);
    lift_store8(cpu->esp + 0x44u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FA80u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_store32(cpu->esp + 0x6Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x3Cu, cpu->edi);
    lift_store32(cpu->esp + 0x38u, cpu->ebx);
    lift_store8(cpu->esp + 0x28u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FA9Fu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x6Cu);
    lift_store8(cpu->esp + 0x64u, 1u);
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    if ((uint32_t)(lift_load32(cpu->esi + 0x10u)) == (uint32_t)(cpu->ebx)) goto label_0008FB64;
    lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FAC1u); lift_push32(cpu, r); sfera_sub_0048E030(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0008FADA;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FAD5u); lift_push32(cpu, r); sfera_sub_0048EDB0(cpu,r); if (cpu->eip != r) return; }
    ++cpu->edi;
    lift_store32(cpu->esp + 0x14u, cpu->edi);
    label_0008FADA: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FADAu);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->esp + 0x44u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FAEBu); lift_push32(cpu, r); sfera_sub_0048F880(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FAFCu); lift_push32(cpu, r); sfera_sub_0048E270(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->ebx)) goto label_0008FB0F;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x8FB0Fu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    label_0008FB0F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FB0Fu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_0008FB25;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_0008FB23;
    cpu->eax |= 0xFFFFFFFFu;
    label_0008FB23: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FB23u);
    lift_store32(cpu->ecx, cpu->eax);
    label_0008FB25: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FB25u);
    cpu->esi = 0x10u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x34u)) < (uint32_t)(cpu->esi)) goto label_0008FB3D;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FB3Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008FB3D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FB3Du);
    lift_store32(cpu->esp + 0x34u, 0xFu);
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    lift_store8(cpu->esp + 0x20u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x50u)) < (uint32_t)(cpu->esi)) goto label_0008FB60;
    cpu->eax = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FB5Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008FB60: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FB60u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    goto label_0008FBA1;
    label_0008FB64: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FB64u);
    cpu->esi = 0x10u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x34u)) < (uint32_t)(cpu->esi)) goto label_0008FB7C;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FB79u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008FB7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FB7Cu);
    lift_store32(cpu->esp + 0x34u, 0xFu);
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    lift_store8(cpu->esp + 0x20u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x50u)) < (uint32_t)(cpu->esi)) goto label_0008FB9F;
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FB9Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008FB9F: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FB9Fu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    label_0008FBA1: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FBA1u);
    cpu->ecx = lift_load32(cpu->esp + 0x5Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x54u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048FBD0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48FBD0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x40u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = 0u;
    cpu->esi = 0xFu;
    lift_store32(cpu->esp + 0x44u, cpu->esi);
    lift_store32(cpu->esp + 0x40u, cpu->ebx);
    lift_store8(cpu->esp + 0x30u, cpu->ebx & 0xFFu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_store32(cpu->esp + 0x60u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FC23u); lift_push32(cpu, r); sfera_sub_0048F880(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = (uint32_t)(cpu->esi + 1u);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0008FD85;
    lift_push32(cpu, 3u); lift_push32(cpu, (uintptr_t)"hts");
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x30u, cpu->esi);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x1Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FC4Au); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FC57u); lift_push32(cpu, r); sfera_sub_0048DFB0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x13u, cpu->eax & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x28u)) < (uint32_t)(cpu->edi)) goto label_0008FC6E;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FC6Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008FC6E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FC6Eu);
    if ((uint8_t)(lift_load8(cpu->esp + 0x13u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0008FC8E;
    if ((uint32_t)(lift_load32(cpu->esp + 0x44u)) < (uint32_t)(cpu->edi)) goto label_0008FC87;
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FC84u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008FC87: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FC87u);
    cpu->eax = 0u;
    goto label_0008FD9D;
    label_0008FC8E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FC8Eu);
    lift_push32(cpu, 6u); lift_push32(cpu, (uintptr_t)"mailto");
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x30u, cpu->esi);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x1Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FCAAu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FCB7u); lift_push32(cpu, r); sfera_sub_0048DFB0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x13u, cpu->eax & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x28u)) < (uint32_t)(cpu->edi)) goto label_0008FCCE;
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FCCBu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008FCCE: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FCCEu);
    if ((uint8_t)(lift_load8(cpu->esp + 0x13u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0008FCF1;
    if ((uint32_t)(lift_load32(cpu->esp + 0x44u)) < (uint32_t)(cpu->edi)) goto label_0008FCE7;
    cpu->eax = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FCE4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008FCE7: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FCE7u);
    cpu->eax = 3u;
    goto label_0008FD9D;
    label_0008FCF1: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FCF1u);
    lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)"item");
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x30u, cpu->esi);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x1Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FD0Du); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FD1Au); lift_push32(cpu, r); sfera_sub_0048DFB0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x13u, cpu->eax & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x28u)) < (uint32_t)(cpu->edi)) goto label_0008FD31;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FD2Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008FD31: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FD31u);
    if ((uint8_t)(lift_load8(cpu->esp + 0x13u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0008FD47;
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FD40u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 1u;
    goto label_0008FD9D;
    label_0008FD47: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FD47u);
    lift_push32(cpu, (uint32_t)(uintptr_t)"player");
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FD55u); lift_push32(cpu, r); sfera_sub_004090F0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FD62u); lift_push32(cpu, r); sfera_sub_0048DFB0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store8(cpu->esp + 0x13u, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FD6Fu); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(lift_load8(cpu->esp + 0x13u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_0008FD85;
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FD7Eu); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = 2u;
    goto label_0008FD9D;
    label_0008FD85: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FD85u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x44u)) < (uint32_t)(cpu->edi)) goto label_0008FD98;
    cpu->edx = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FD95u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008FD98: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FD98u);
    cpu->eax = 4u;
    label_0008FD9D: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FD9Du);
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x4Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048FDC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48FDC0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x44u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    lift_push32(cpu, 2u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, (uint32_t)(uintptr_t)"\\l");
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_store32(cpu->esp + 0x4Cu, 0xFu);
    lift_store32(cpu->esp + 0x48u, cpu->ebx);
    lift_store8(cpu->esp + 0x38u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FE18u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x58u, cpu->ebx);
    lift_store32(cpu->esp + 0x10u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FE2Fu); lift_push32(cpu, r); sfera_sub_0048DFB0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_0008FE6E;
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"/l");
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x30u, 0xFu);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x1Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FE53u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x10u, 3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FE66u); lift_push32(cpu, r); sfera_sub_0048DFB0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0xFu, cpu->ebx & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_0008FE73;
    label_0008FE6E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FE6Eu);
    lift_store8(cpu->esp + 0xFu, 1u);
    label_0008FE73: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FE73u);
    { uint64_t l=(uint64_t)(lift_load8(cpu->esp + 0x10u)), r=(uint64_t)(2u), v=l & r; lift_flags_logic(cpu,v,8u); }
    cpu->esi = 0x10u;
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0008FEA7;
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) & (uint64_t)(0xFFFFFFFDu));
    if ((uint32_t)(lift_load32(cpu->esp + 0x28u)) < (uint32_t)(cpu->esi)) goto label_0008FE97;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FE94u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008FE97: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FE97u);
    lift_store32(cpu->esp + 0x28u, 0xFu);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    lift_store8(cpu->esp + 0x14u, cpu->ebx & 0xFFu);
    label_0008FEA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FEA7u);
    if ((uint8_t)((lift_load8(cpu->esp + 0x10u)) & (1u)) == 0u) goto label_0008FEC1;
    if ((uint32_t)(lift_load32(cpu->esp + 0x44u)) < (uint32_t)(cpu->esi)) goto label_0008FEC1;
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FEBEu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0008FEC1: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FEC1u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0xFu)) & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x50u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x50u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048FEF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48FEF0u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x28u, cpu->esp);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0008FF1E;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0008FF1E;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->eax, cpu->edx);
    label_0008FF1E: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FF1Eu);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->eax + 8u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FF2Fu); lift_push32(cpu, r); sfera_sub_0048F6C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 20u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_0048FF40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x48FF40u);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FF51u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->edi = 0u;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->edi);
    lift_store32(cpu->ecx + 4u, cpu->edi);
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->esp);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->edi)) goto label_0008FF71;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->edi)) goto label_0008FF71;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->ecx, cpu->edx);
    label_0008FF71: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FF71u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FF83u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->edi);
    lift_store32(cpu->ecx + 4u, cpu->edi);
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->esp);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->edi)) goto label_0008FFA1;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->edi)) goto label_0008FFA1;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->ecx, cpu->edx);
    label_0008FFA1: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FFA1u);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x48FFB3u); lift_push32(cpu, r); sfera_sub_0048EBC0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edi);
    lift_store32(cpu->eax + 4u, cpu->edi);
    cpu->ecx = lift_load32(cpu->esp + 0x4Cu);
    lift_store32(cpu->esp + 0x14u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0008FFD3;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0008FFD3;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    label_0008FFD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FFD3u);
    cpu->ecx = lift_load32(cpu->esp + 0x54u);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, cpu->edi);
    lift_store32(cpu->eax + 4u, cpu->edi);
    cpu->ecx = lift_load32(cpu->esp + 0x4Cu);
    lift_store32(cpu->esp + 0x20u, cpu->esp);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0008FFFA;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->edi)) goto label_0008FFFA;
    cpu->edx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->edx);
    label_0008FFFA: cpu->eip = LIFT_CODE_TOKEN_VA(0x48FFFAu);
    cpu->ecx = lift_load32(cpu->esp + 0x54u);
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49000Du); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->ecx, cpu->edi);
    lift_store32(cpu->ecx + 4u, cpu->edi);
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0x2Cu, cpu->esp);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->edi)) goto label_0009002B;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->edi)) goto label_0009002B;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->ecx, cpu->edx);
    label_0009002B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49002Bu);
    cpu->eax = lift_load32(cpu->eax + 8u);
    lift_store32(cpu->ecx + 8u, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490038u); lift_push32(cpu, r); sfera_sub_0048F7E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x28u;
    lift_return(cpu, 28u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00490040(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x490040u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = lift_load32(cpu->esp + 0x4Cu);
    cpu->ebp = lift_load32(cpu->esp + 0x50u);
    cpu->eax = lift_load32(cpu->esp + 0x54u);
    cpu->edi = cpu->ecx;
    cpu->ebx = cpu->edx;
    lift_store32(cpu->esp + 0x18u, cpu->ebp);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_0009014A;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(lift_load32(cpu->edi + 0x10u))) goto label_000900C1;
    cpu->eax = (uintptr_t)g_sfera_server_parser_whitespace;
    cpu->ecx = sizeof(g_sfera_server_parser_whitespace) - 1u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4900BBu); lift_push32(cpu, r); sfera_sub_0048DC80(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    label_000900C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4900C1u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_0009014A;
    cpu->eax = (uintptr_t)g_sfera_server_parser_whitespace;
    cpu->edx = sizeof(g_sfera_server_parser_whitespace) - 1u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4900EDu); lift_push32(cpu, r); sfera_sub_0048DC00(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    if ((uint32_t)(cpu->ebx) == 0u) goto label_00090132;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(0xFFFFFFFFu)) goto label_000900FC;
    cpu->eax |= cpu->eax;
    goto label_00090100;
    label_000900FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4900FCu);
    cpu->eax = cpu->ebp;
    cpu->eax -= cpu->esi;
    label_00090100: cpu->eip = LIFT_CODE_TOKEN_VA(0x490100u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49010Eu); lift_push32(cpu, r); sfera_sub_00431640(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_store32(cpu->esp + 0x48u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49011Eu); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esp + 0x30u)) < (uint32_t)(0x10u)) goto label_00090132;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49012Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00090132: cpu->eip = LIFT_CODE_TOKEN_VA(0x490132u);
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009013C;
    lift_store32(cpu->eax, cpu->esi);
    label_0009013C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49013Cu);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00090146;
    lift_store32(cpu->eax, cpu->ebp);
    label_00090146: cpu->eip = LIFT_CODE_TOKEN_VA(0x490146u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    goto label_00090161;
    label_0009014A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49014Au);
    if ((uint32_t)(cpu->ebp) == 0u) goto label_00090155;
    lift_store32(cpu->ebp, 0xFFFFFFFFu);
    label_00090155: cpu->eip = LIFT_CODE_TOKEN_VA(0x490155u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009015F;
    lift_store32(cpu->eax, 0xFFFFFFFFu);
    label_0009015F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49015Fu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    label_00090161: cpu->eip = LIFT_CODE_TOKEN_VA(0x490161u);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00490190(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x490190u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, 0u);
    lift_store32(cpu->esp + 0x10u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4901AAu); lift_push32(cpu, r); sfera_sub_0048E480(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4901C3u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004901D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4901D0u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->edx + 0x10u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->edx + 0x14u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->ecx + 0x10u);
    cpu->ebp -= cpu->eax;
    lift_store32(cpu->esp + 0xCu, 0u);
    if ((uint32_t)(cpu->edi) <= (uint32_t)(cpu->ebp)) goto label_00090208;
    cpu->ebp = lift_load32(cpu->ecx + 0x14u);
    cpu->ebp -= cpu->edi;
    if ((uint32_t)(cpu->ebp) < (uint32_t)(cpu->eax)) goto label_00090208;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490206u); lift_push32(cpu, r); sfera_sub_0048EE60(cpu,r); if (cpu->eip != r) return; }
    goto label_00090214;
    label_00090208: cpu->eip = LIFT_CODE_TOKEN_VA(0x490208u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x90214u); lift_push32(cpu, r); sfera_sub_0048E270(cpu,r); if (cpu->eip != r) return; }
    label_00090214: cpu->eip = LIFT_CODE_TOKEN_VA(0x490214u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49022Du); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00490240(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x490240u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edx;
    lift_store32(cpu->esp + 0xCu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49025Au); lift_push32(cpu, r); sfera_sub_0048EDB0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490273u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00490280(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x490280u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = cpu->edx;
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    lift_store32(cpu->esp + 0x10u, 0u);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_store8(cpu->esi, 0u);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->ecx = lift_load32(cpu->ecx + 0x10u);
    cpu->edi = lift_load32(cpu->esi + 0x10u);
    cpu->eax += cpu->ecx;
    lift_store32(cpu->esp + 0x20u, 0u);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(cpu->edi) > (uint32_t)(cpu->eax)) goto label_00090310;
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) == (uint32_t)(cpu->eax)) goto label_00090310;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4902F9u); lift_push32(cpu, r); sfera_sub_00403CA0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00090310;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x14u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0009030A;
    cpu->eax = lift_load32(cpu->esi);
    goto label_0009030C;
    label_0009030A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49030Au);
    cpu->eax = cpu->esi;
    label_0009030C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49030Cu);
    lift_store8(cpu->eax + cpu->edi, 0u);
    label_00090310: cpu->eip = LIFT_CODE_TOKEN_VA(0x490310u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49031Cu); lift_push32(cpu, r); sfera_sub_0048E270(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49032Cu); lift_push32(cpu, r); sfera_sub_0048E270(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00490350(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x490350u);
    lift_push32(cpu, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x10u, cpu->esp);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0009037E;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_0009037E;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->eax, cpu->edx);
    label_0009037E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49037Eu);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->eax, 0u);
    lift_store32(cpu->eax + 4u, 0u);
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_store32(cpu->esp + 0x1Cu, cpu->esp);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000903AD;
    cpu->edx = lift_load32(cpu->edx);
    if ((uint32_t)(cpu->edx) == 0u) goto label_000903AD;
    cpu->edx = lift_load32(cpu->edx);
    lift_store32(cpu->eax, cpu->edx);
    label_000903AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4903ADu);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    lift_store32(cpu->eax + 8u, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4903B9u); lift_push32(cpu, r); sfera_sub_0048FF40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 24u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004903C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4903C0u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x14u);
    cpu->eax = cpu->edi;
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0xCu, 0u);
    cpu->ebp = (uint32_t)(cpu->eax + 1u);
    label_000903D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4903D7u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ecx & 0xFFu)) != 0u) goto label_000903D7;
    cpu->eax -= cpu->ebp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->edx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4903E9u); lift_push32(cpu, r); sfera_sub_0048E360(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, 0u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490402u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00490410(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x490410u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = 0u;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0xFFFFFFFFu);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x50u, cpu->ebx);
    lift_store32(cpu->esp + 0x24u, cpu->esi);
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490467u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uintptr_t)g_sfera_server_parser_whitespace;
    cpu->ebp = 0x10u;
    lift_store32(cpu->esp + 0x44u, cpu->ebx);
    lift_store32(cpu->esp + 0x14u, 1u);
    cpu->ecx = sizeof(g_sfera_server_parser_whitespace) - 1u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49049Au); lift_push32(cpu, r); sfera_sub_0048DC80(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->eax = (uintptr_t)g_sfera_server_parser_whitespace;
    cpu->edx = sizeof(g_sfera_server_parser_whitespace) - 1u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4904BFu); lift_push32(cpu, r); sfera_sub_0048DCF0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) == (uint32_t)(0xFFFFFFFFu)) goto label_000904FF;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000904FF;
    cpu->eax -= cpu->edi;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4904DAu); lift_push32(cpu, r); sfera_sub_00431640(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x48u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4904EAu); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esp + 0x30u)) < (uint32_t)(cpu->ebp)) goto label_0009050F;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4904FAu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    goto label_0009050F;
    label_000904FF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4904FFu);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(cpu->ebp)) goto label_0009050B;
    cpu->eax = lift_load32(cpu->esi);
    goto label_0009050D;
    label_0009050B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49050Bu);
    cpu->eax = cpu->esi;
    label_0009050D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49050Du);
    lift_store8(cpu->eax, cpu->ebx & 0xFFu);
    label_0009050F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49050Fu);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00490530(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x490530u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->edi);
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    lift_store8(cpu->esi, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490553u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->ebp + 0x10u);
    cpu->ebx = lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->ebx + 0x10u))) goto label_000905BF;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_000905BF;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000905BF;
    cpu->edi = cpu->edi;
    label_00090570: cpu->eip = LIFT_CODE_TOKEN_VA(0x490570u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_0009057A;
    cpu->eax = lift_load32(cpu->esi);
    goto label_0009057C;
    label_0009057A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49057Au);
    cpu->eax = cpu->esi;
    label_0009057C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49057Cu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + cpu->edi)) & 0xFFu);
    lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->esp + 0x24u, cpu->eax & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490593u); lift_push32(cpu, r); sfera_sub_004312E0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_000905B9;
    cpu->ecx = 0x10u;
    if ((uint32_t)(lift_load32(cpu->ebx + 0x14u)) < (uint32_t)(cpu->ecx)) goto label_000905A6;
    cpu->edx = lift_load32(cpu->ebx);
    goto label_000905A8;
    label_000905A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4905A6u);
    cpu->edx = cpu->ebx;
    label_000905A8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4905A8u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(cpu->ecx)) goto label_000905B1;
    cpu->ecx = lift_load32(cpu->esi);
    goto label_000905B3;
    label_000905B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4905B1u);
    cpu->ecx = cpu->esi;
    label_000905B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4905B3u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx + cpu->eax)) & 0xFFu);
    lift_store8(cpu->ecx + cpu->edi, cpu->edx & 0xFFu);
    label_000905B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4905B9u);
    ++cpu->edi;
    if ((uint32_t)(cpu->edi) < (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_00090570;
    label_000905BF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4905BFu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004905D0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4905D0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->edx;
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_push32(cpu, (uint32_t)(uintptr_t)"");
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49061Fu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    lift_store32(cpu->esp + 0x10u, 1u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x10u)) <= (uint32_t)(cpu->ebx)) goto label_000906C6;
    label_00090634: cpu->eip = LIFT_CODE_TOKEN_VA(0x490634u);
    cpu->ecx = lift_load32(cpu->edi + 0x14u);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(0x10u)) goto label_00090640;
    cpu->eax = lift_load32(cpu->edi);
    goto label_00090642;
    label_00090640: cpu->eip = LIFT_CODE_TOKEN_VA(0x490640u);
    cpu->eax = cpu->edi;
    label_00090642: cpu->eip = LIFT_CODE_TOKEN_VA(0x490642u);
    cpu->eax = (int8_t)(lift_load8(cpu->eax + cpu->ebx));
    cpu->eax += 0xFFFFFFDEu;
    if ((uint32_t)(cpu->eax) > (uint32_t)(0x3Au)) goto label_0009069C;
    switch ((uint32_t)(cpu->eax)) {
        case 0u: goto label_0009067C;
        case 26u: goto label_0009065C;
        case 28u: goto label_0009066C;
        case 58u: goto label_0009068C;
        default: goto label_0009069C;
    }
label_0009065C: ;
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"\\[");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49066Au); lift_push32(cpu, r); sfera_sub_0048E360(cpu,r); if (cpu->eip != r) return; }
    goto label_000906BC;
    label_0009066C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49066Cu);
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"\\]");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49067Au); lift_push32(cpu, r); sfera_sub_0048E360(cpu,r); if (cpu->eip != r) return; }
    goto label_000906BC;
    label_0009067C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49067Cu);
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"\\\"");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49068Au); lift_push32(cpu, r); sfera_sub_0048E360(cpu,r); if (cpu->eip != r) return; }
    goto label_000906BC;
    label_0009068C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49068Cu);
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"\\\\");
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49069Au); lift_push32(cpu, r); sfera_sub_0048E360(cpu,r); if (cpu->eip != r) return; }
    goto label_000906BC;
    label_0009069C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49069Cu);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(0x10u)) goto label_000906A5;
    cpu->eax = lift_load32(cpu->edi);
    goto label_000906A7;
    label_000906A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4906A5u);
    cpu->eax = cpu->edi;
    label_000906A7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4906A7u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + cpu->ebx)) & 0xFFu);
    lift_store8(cpu->esp + 0x14u, cpu->ecx & 0xFFu);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x906BCu); lift_push32(cpu, r); sfera_sub_0048EDB0(cpu,r); if (cpu->eip != r) return; }
    label_000906BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4906BCu);
    ++cpu->ebx;
    if ((uint32_t)(cpu->ebx) < (uint32_t)(lift_load32(cpu->edi + 0x10u))) goto label_00090634;
    label_000906C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4906C6u);
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00490730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x490730u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->edx;
    cpu->ebp = cpu->ecx;
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->ebp + 0x14u, 0xFu);
    lift_store32(cpu->ebp + 0x10u, cpu->ebx);
    lift_push32(cpu, (uint32_t)(uintptr_t)"");
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store8(cpu->ebp, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490781u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    cpu->esi = 0u;
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x14u, 1u);
    if ((uint32_t)(cpu->eax) <= (uint32_t)(cpu->ebx)) goto label_0009085A;
    cpu->ebx = (uint32_t)(cpu->esi + 1u);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_000907A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4907A0u);
    cpu->edx = lift_load32(cpu->edi + 0x14u);
    if ((uint32_t)(cpu->edx) < (uint32_t)(0x10u)) goto label_000907AC;
    cpu->ecx = lift_load32(cpu->edi);
    goto label_000907AE;
    label_000907AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4907ACu);
    cpu->ecx = cpu->edi;
    label_000907AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4907AEu);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->esi)) != (uint8_t)(0x5Cu)) goto label_0009082D;
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(cpu->eax)) goto label_00090829;
    if ((uint32_t)(cpu->edx) < (uint32_t)(0x10u)) goto label_000907C1;
    cpu->eax = lift_load32(cpu->edi);
    goto label_000907C3;
    label_000907C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4907C1u);
    cpu->eax = cpu->edi;
    label_000907C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4907C3u);
    cpu->eax = (int8_t)(lift_load8(cpu->eax + cpu->esi + 1u));
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(0x5Bu), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009081E;
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(2u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_0009080F;
    if ((uint32_t)(cpu->edx) < (uint32_t)(0x10u)) goto label_000907F3;
    cpu->eax = lift_load32(cpu->edi);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + cpu->esi + 1u)) & 0xFFu);
    lift_store8(cpu->esp + 0x18u, cpu->eax & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4907EFu); lift_push32(cpu, r); sfera_sub_0048EDB0(cpu,r); if (cpu->eip != r) return; }
    ++cpu->esi;
    ++cpu->ebx;
    goto label_0009084D;
    label_000907F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4907F3u);
    cpu->eax = cpu->edi;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + cpu->esi + 1u)) & 0xFFu);
    lift_store8(cpu->esp + 0x18u, cpu->eax & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49080Bu); lift_push32(cpu, r); sfera_sub_0048EDB0(cpu,r); if (cpu->eip != r) return; }
    ++cpu->esi;
    ++cpu->ebx;
    goto label_0009084D;
    label_0009080F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49080Fu);
    lift_push32(cpu, 0x3Eu); lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49081Au); lift_push32(cpu, r); sfera_sub_0048EDB0(cpu,r); if (cpu->eip != r) return; }
    ++cpu->esi;
    ++cpu->ebx;
    goto label_0009084D;
    label_0009081E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49081Eu);
    lift_push32(cpu, 0x3Cu); lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x90829u); lift_push32(cpu, r); sfera_sub_0048EDB0(cpu,r); if (cpu->eip != r) return; }
    label_00090829: cpu->eip = LIFT_CODE_TOKEN_VA(0x490829u);
    ++cpu->esi;
    ++cpu->ebx;
    goto label_0009084D;
    label_0009082D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49082Du);
    if ((uint32_t)(cpu->edx) < (uint32_t)(0x10u)) goto label_00090836;
    cpu->eax = lift_load32(cpu->edi);
    goto label_00090838;
    label_00090836: cpu->eip = LIFT_CODE_TOKEN_VA(0x490836u);
    cpu->eax = cpu->edi;
    label_00090838: cpu->eip = LIFT_CODE_TOKEN_VA(0x490838u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax + cpu->esi)) & 0xFFu);
    lift_store8(cpu->esp + 0x1Cu, cpu->edx & 0xFFu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9084Du); lift_push32(cpu, r); sfera_sub_0048EDB0(cpu,r); if (cpu->eip != r) return; }
    label_0009084D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49084Du);
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    ++cpu->esi;
    ++cpu->ebx;
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->eax)) goto label_000907A0;
    label_0009085A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49085Au);
    cpu->eax = cpu->ebp;
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00490870(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x490870u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x6Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x80u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = lift_load32(cpu->esp + 0x90u);
    cpu->eax = lift_load32(cpu->esp + 0x94u);
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x18u, cpu->edx);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, 0u);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(0xFFFFFFFFu)) goto label_00090995;
    cpu->ecx = lift_load32(cpu->esi + 0x10u);
    cpu->edx = (uint32_t)(cpu->ecx + 0xFFFFFFFFu);
    if ((uint32_t)(cpu->ebx) >= (uint32_t)(cpu->edx)) goto label_00090995;
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_000908E6;
    cpu->eax = lift_load32(cpu->esi);
    goto label_000908E8;
    label_000908E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4908E6u);
    cpu->eax = cpu->esi;
    label_000908E8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4908E8u);
    if ((uint8_t)(lift_load8(cpu->eax + cpu->ebx)) != (uint8_t)(0x22u)) goto label_00090995;
    cpu->edx = (uint32_t)(cpu->ebx + 1u);
    cpu->ebp = cpu->edx;
    lift_store32(cpu->esp + 0x20u, cpu->edx);
    if ((uint32_t)(cpu->ebp) >= (uint32_t)(cpu->ecx)) goto label_00090995;
    cpu->edi = cpu->ebp;
    cpu->edi -= cpu->ebx;
    --cpu->edi;
    goto label_00090914;
    label_00090910: cpu->eip = LIFT_CODE_TOKEN_VA(0x490910u);
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    label_00090914: cpu->eip = LIFT_CODE_TOKEN_VA(0x490914u);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(0x10u)) goto label_0009091E;
    cpu->eax = lift_load32(cpu->esi);
    goto label_00090920;
    label_0009091E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49091Eu);
    cpu->eax = cpu->esi;
    label_00090920: cpu->eip = LIFT_CODE_TOKEN_VA(0x490920u);
    if ((uint8_t)(lift_load8(cpu->eax + cpu->ebp)) != (uint8_t)(0x22u)) goto label_0009098A;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490934u); lift_push32(cpu, r); sfera_sub_00431640(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x88u, cpu->ecx);
    if ((uint32_t)(lift_load32(cpu->esp + 0x38u)) == (uint32_t)(cpu->ecx)) goto label_00090966;
    lift_push32(cpu, 1u); lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_store8(cpu->esp + 0x20u, 0x5Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49095Au); lift_push32(cpu, r); sfera_sub_0048DCF0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00090966;
    cpu->ecx -= cpu->eax;
    --cpu->ecx;
    label_00090966: cpu->eip = LIFT_CODE_TOKEN_VA(0x490966u);
    if ((uint8_t)(((cpu->ecx & 0xFFu)) & (1u)) == 0u) goto label_000909BB;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x3Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x88u, 0xFFFFFFFFu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_0009098A;
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490987u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009098A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49098Au);
    ++cpu->ebp;
    ++cpu->edi;
    if ((uint32_t)(cpu->ebp) < (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_00090910;
    label_00090995: cpu->eip = LIFT_CODE_TOKEN_VA(0x490995u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    label_00090997: cpu->eip = LIFT_CODE_TOKEN_VA(0x490997u);
    cpu->ecx = lift_load32(cpu->esp + 0x80u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x78u;
    lift_return(cpu, 8u, stop_address); return;
    label_000909BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4909BBu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) == (uint32_t)(0u)) goto label_00090A34;
    cpu->eax = cpu->ebp;
    cpu->eax -= cpu->ebx;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(1u)) goto label_000909ED;
    --cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4909DEu); lift_push32(cpu, r); sfera_sub_00431640(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x88u, 1u);
    cpu->ebx = 1u;
    goto label_00090A07;
    label_000909ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4909EDu);
    lift_push32(cpu, (uint32_t)(uintptr_t)"");
    cpu->ecx = (uint32_t)(cpu->esp + 0x48u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4909FBu); lift_push32(cpu, r); sfera_sub_004090F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = 2u;
    lift_store32(cpu->esp + 0x88u, cpu->ebx);
    label_00090A07: cpu->eip = LIFT_CODE_TOKEN_VA(0x490A07u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490A15u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(((cpu->ebx & 0xFFu)) & (2u)) == 0u) goto label_00090A26;
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    cpu->ebx &= 0xFFFFFFFDu;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x90A26u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    label_00090A26: cpu->eip = LIFT_CODE_TOKEN_VA(0x490A26u);
    if ((uint8_t)(((cpu->ebx & 0xFFu)) & (1u)) == 0u) goto label_00090A34;
    cpu->ecx = (uint32_t)(cpu->esp + 0x60u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x90A34u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    label_00090A34: cpu->eip = LIFT_CODE_TOKEN_VA(0x490A34u);
    cpu->eax = lift_load32(cpu->esp + 0x24u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00090A47;
    ++cpu->ebp;
    if ((uint32_t)(cpu->ebp) < (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_00090A45;
    cpu->ebp |= 0xFFFFFFFFu;
    label_00090A45: cpu->eip = LIFT_CODE_TOKEN_VA(0x490A45u);
    lift_store32(cpu->eax, cpu->ebp);
    label_00090A47: cpu->eip = LIFT_CODE_TOKEN_VA(0x490A47u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x3Cu)) < (uint32_t)(0x10u)) goto label_00090A5B;
    cpu->edx = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490A58u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00090A5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x490A5Bu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    goto label_00090997;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00490A70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x490A70u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x48u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x5Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = lift_load32(cpu->esp + 0x6Cu);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    cpu->eax = lift_load32(cpu->esp + 0x70u);
    cpu->esi = cpu->ecx;
    cpu->ecx = lift_load32(cpu->esp + 0x74u);
    cpu->ebp = cpu->edx;
    lift_store32(cpu->esp + 0x18u, cpu->ecx);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00090AEE;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_00090AEE;
    cpu->ecx = (uintptr_t)g_sfera_server_parser_whitespace;
    cpu->edi = 0x10u;
    cpu->edx = sizeof(g_sfera_server_parser_whitespace) - 1u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490AECu); lift_push32(cpu, r); sfera_sub_0048DC80(cpu,r); if (cpu->eip != r) return; }
    goto label_00090AF3;
    label_00090AEE: cpu->eip = LIFT_CODE_TOKEN_VA(0x490AEEu);
    cpu->edi = 0x10u;
    label_00090AF3: cpu->eip = LIFT_CODE_TOKEN_VA(0x490AF3u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00090C2C;
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edx)) goto label_00090C2C;
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) < (uint32_t)(cpu->edi)) goto label_00090B10;
    cpu->ecx = lift_load32(cpu->esi);
    goto label_00090B12;
    label_00090B10: cpu->eip = LIFT_CODE_TOKEN_VA(0x490B10u);
    cpu->ecx = cpu->esi;
    label_00090B12: cpu->eip = LIFT_CODE_TOKEN_VA(0x490B12u);
    if ((uint8_t)(lift_load8(cpu->ecx + cpu->eax)) != (uint8_t)(0x3Du)) goto label_00090C2C;
    ++cpu->eax;
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00090B49;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edx)) goto label_00090B49;
    cpu->ecx = (uintptr_t)g_sfera_server_parser_whitespace;
    cpu->edx = sizeof(g_sfera_server_parser_whitespace) - 1u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x90B49u); lift_push32(cpu, r); sfera_sub_0048DC80(cpu,r); if (cpu->eip != r) return; }
    label_00090B49: cpu->eip = LIFT_CODE_TOKEN_VA(0x490B49u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00090C2C;
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x34u, 0xFu);
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    lift_store8(cpu->esp + 0x20u, cpu->ebx & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    cpu->ecx = cpu->esi;
    lift_store32(cpu->esp + 0x6Cu, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490B7Du); lift_push32(cpu, r); sfera_sub_00490870(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00090C19;
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490B8Eu); lift_push32(cpu, r); sfera_sub_0048FBD0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) == (uint32_t)(2u)) goto label_00090B9A;
    if ((uint32_t)(cpu->edi) != (uint32_t)(1u)) goto label_00090BCE;
    label_00090B9A: cpu->eip = LIFT_CODE_TOKEN_VA(0x490B9Au);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490BA7u); lift_push32(cpu, r); sfera_sub_00490730(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store8(cpu->esp + 0x68u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490BB6u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x50u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x64u, cpu->ebx & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00090BCE;
    cpu->edx = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490BCBu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00090BCE: cpu->eip = LIFT_CODE_TOKEN_VA(0x490BCEu);
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->ebx)) goto label_00090BE1;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x90BE1u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    label_00090BE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x490BE1u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00090BEB;
    lift_store32(cpu->eax, cpu->edi);
    label_00090BEB: cpu->eip = LIFT_CODE_TOKEN_VA(0x490BEBu);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00090C01;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(lift_load32(cpu->esi + 0x10u))) goto label_00090BFF;
    cpu->eax |= 0xFFFFFFFFu;
    label_00090BFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x490BFFu);
    lift_store32(cpu->ecx, cpu->eax);
    label_00090C01: cpu->eip = LIFT_CODE_TOKEN_VA(0x490C01u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x34u)) < (uint32_t)(0x10u)) goto label_00090C15;
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490C12u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00090C15: cpu->eip = LIFT_CODE_TOKEN_VA(0x490C15u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    goto label_00090C2E;
    label_00090C19: cpu->eip = LIFT_CODE_TOKEN_VA(0x490C19u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x34u)) < (uint32_t)(cpu->edi)) goto label_00090C2C;
    cpu->edx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490C29u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00090C2C: cpu->eip = LIFT_CODE_TOKEN_VA(0x490C2Cu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    label_00090C2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x490C2Eu);
    cpu->ecx = lift_load32(cpu->esp + 0x5Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x54u;
    lift_return(cpu, 12u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00490C50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x490C50u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x130u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x144u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = lift_load32(cpu->esp + 0x154u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esp + 0x28u, cpu->ecx);
    cpu->edi = 0u;
    cpu->esi = 0xFu;
    lift_push32(cpu, (uint32_t)(uintptr_t)"");
    cpu->ecx = (uint32_t)(cpu->esp + 0x110u);
    lift_store32(cpu->esp + 0x30u, cpu->edx);
    lift_store32(cpu->esp + 0x44u, cpu->eax);
    lift_store32(cpu->esp + 0x28u, cpu->edi);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x124u, cpu->esi);
    lift_store32(cpu->esp + 0x120u, cpu->ebx);
    lift_store8(cpu->esp + 0x110u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490CD6u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = (uint32_t)(cpu->esp + 0x12Cu);
    lift_store32(cpu->esp + 0x154u, cpu->ebx);
    lift_store32(cpu->esp + 0x140u, cpu->esi);
    lift_store32(cpu->esp + 0x13Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x12Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490D04u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = (uint32_t)(cpu->esp + 0x68u);
    lift_store8(cpu->esp + 0x154u, 1u);
    lift_store32(cpu->esp + 0x7Cu, cpu->esi);
    lift_store32(cpu->esp + 0x78u, cpu->ebx);
    lift_store8(cpu->esp + 0x68u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490D27u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = (uint32_t)(cpu->esp + 0xD8u);
    lift_store8(cpu->esp + 0x154u, 2u);
    lift_store32(cpu->esp + 0xECu, cpu->esi);
    lift_store32(cpu->esp + 0xE8u, cpu->ebx);
    lift_store8(cpu->esp + 0xD8u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490D56u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_store8(cpu->esp + 0x154u, 3u);
    lift_store32(cpu->esp + 0x60u, cpu->esi);
    lift_store32(cpu->esp + 0x5Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x4Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490D79u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->edx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x114u);
    lift_store8(cpu->esp + 0x158u, 4u);
    lift_store32(cpu->esp + 0x44u, 4u);
    cpu->ebp = 0u;
    lift_store32(cpu->esp + 0x3Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x23u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490DAEu); lift_push32(cpu, r); sfera_sub_0048EFE0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000912DA;
    label_00090DB6: cpu->eip = LIFT_CODE_TOKEN_VA(0x490DB6u);
    cpu->eax = lift_load32(cpu->esp + 0x34u);
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0xBCu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490DCFu); lift_push32(cpu, r); sfera_sub_00431640(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = (uint32_t)(cpu->esp + 0x84u);
    lift_store8(cpu->esp + 0x154u, 5u);
    lift_store32(cpu->esp + 0x98u, cpu->esi);
    lift_store32(cpu->esp + 0x94u, cpu->ebx);
    lift_store8(cpu->esp + 0x84u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490DFEu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x84u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x110u);
    lift_store8(cpu->esp + 0x154u, 6u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490E1Fu); lift_push32(cpu, r); sfera_sub_0048FA20(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000910C5;
    cpu->edi = lift_load32(cpu->esp + 0x40u);
    if ((uint32_t)(cpu->edi) == (uint32_t)(0xFFFFFFFFu)) goto label_00090F21;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->edi);
    cpu->eax = (uint32_t)(cpu->esp + 0xF4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x114u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490E4Bu); lift_push32(cpu, r); sfera_sub_00431640(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x98u);
    lift_store8(cpu->esp + 0x14Cu, 7u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490E61u); lift_push32(cpu, r); sfera_sub_00490410(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x60u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->esi)) goto label_00090EC7;
    if ((uint32_t)(lift_load32(cpu->esp + 0x74u)) < (uint32_t)(0x10u)) goto label_00090E7F;
    cpu->edx = lift_load32(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490E7Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00090E7F: cpu->eip = LIFT_CODE_TOKEN_VA(0x490E7Fu);
    lift_store32(cpu->esp + 0x74u, 0xFu);
    lift_store32(cpu->esp + 0x70u, cpu->ebx);
    lift_store8(cpu->esp + 0x60u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) >= (uint32_t)(0x10u)) goto label_00090EAB;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x64u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x490EA0u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x490EA6u);
    cpu->esp += 0xCu;
    goto label_00090EB3;
    label_00090EAB: cpu->eip = LIFT_CODE_TOKEN_VA(0x490EABu);
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->esp + 0x60u, cpu->ecx);
    lift_store32(cpu->esi, cpu->ebx);
    label_00090EB3: cpu->eip = LIFT_CODE_TOKEN_VA(0x490EB3u);
    cpu->edx = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->esp + 0x70u, cpu->edx);
    cpu->eax = lift_load32(cpu->esi + 0x14u);
    lift_store32(cpu->esp + 0x74u, cpu->eax);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, cpu->ebx);
    label_00090EC7: cpu->eip = LIFT_CODE_TOKEN_VA(0x490EC7u);
    if ((uint32_t)(lift_load32(cpu->esp + 0xACu)) < (uint32_t)(0x10u)) goto label_00090EE1;
    cpu->ecx = lift_load32(cpu->esp + 0x98u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490EDEu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00090EE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x490EE1u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x100u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0xACu, 0xFu);
    lift_store32(cpu->esp + 0xA8u, cpu->ebx);
    lift_store8(cpu->esp + 0x98u, cpu->ebx & 0xFFu);
    lift_store8(cpu->esp + 0x14Cu, 6u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00090F1C;
    cpu->edx = lift_load32(cpu->esp + 0xECu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490F19u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00090F1C: cpu->eip = LIFT_CODE_TOKEN_VA(0x490F1Cu);
    cpu->esi = 0xFu;
    label_00090F21: cpu->eip = LIFT_CODE_TOKEN_VA(0x490F21u);
    lift_push32(cpu, 1u); lift_push32(cpu, (uintptr_t)"l");
    cpu->ecx = (uint32_t)(cpu->esp + 0xA0u);
    lift_store32(cpu->esp + 0xB4u, cpu->esi);
    lift_store32(cpu->esp + 0xB0u, cpu->ebx);
    lift_store8(cpu->esp + 0xA0u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490F49u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x98u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x7Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490F59u); lift_push32(cpu, r); sfera_sub_0048DFB0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0xACu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x1Fu, cpu->eax & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00090F77;
    cpu->eax = lift_load32(cpu->esp + 0x98u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490F74u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00090F77: cpu->eip = LIFT_CODE_TOKEN_VA(0x490F77u);
    lift_store32(cpu->esp + 0xACu, cpu->esi);
    lift_store32(cpu->esp + 0xA8u, cpu->ebx);
    lift_store8(cpu->esp + 0x98u, cpu->ebx & 0xFFu);
    if ((uint8_t)(lift_load8(cpu->esp + 0x1Fu)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00090FC3;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x130u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x114u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490FACu); lift_push32(cpu, r); sfera_sub_00490A70(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00090FC3;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(3u)) goto label_000910CD;
    cpu->ebp = 3u;
    goto label_000910CD;
    label_00090FC3: cpu->eip = LIFT_CODE_TOKEN_VA(0x490FC3u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x7Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490FCCu); lift_push32(cpu, r); sfera_sub_0048FDC0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000910BB;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(3u)) goto label_000910B3;
    if ((uint32_t)(lift_load32(cpu->esp + 0xC4u)) == (uint32_t)(cpu->ebx)) goto label_000910B3;
    cpu->edx = (uint32_t)(cpu->esp + 0xB4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xECu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x490FFDu); lift_push32(cpu, r); sfera_sub_00490730(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x48u);
    lift_store8(cpu->esp + 0x150u, 9u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49100Fu); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x100u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x14Cu, 6u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00091031;
    cpu->edx = lift_load32(cpu->esp + 0xECu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49102Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00091031: cpu->eip = LIFT_CODE_TOKEN_VA(0x491031u);
    cpu->esi = lift_load32(cpu->esp + 0x28u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_0009109F;
    cpu->edx = 0x1B6u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491048u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x70u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49104Fu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store8(cpu->esp + 0x14Cu, 0xAu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00091085;
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x134u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x74u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x5Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491083u); lift_push32(cpu, r); sfera_sub_00431730(cpu,r); if (cpu->eip != r) return; }
    goto label_00091087;
    label_00091085: cpu->eip = LIFT_CODE_TOKEN_VA(0x491085u);
    cpu->eax = 0u;
    label_00091087: cpu->eip = LIFT_CODE_TOKEN_VA(0x491087u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x150u, 6u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9109Fu); lift_push32(cpu, r); sfera_sub_0048E6A0(cpu,r); if (cpu->eip != r) return; }
    label_0009109F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49109Fu);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0xDCu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x910B3u); lift_push32(cpu, r); sfera_sub_0048E270(cpu,r); if (cpu->eip != r) return; }
    label_000910B3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4910B3u);
    cpu->ebp = 0u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x30u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    goto label_000910C7;
    label_000910BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4910BBu);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(cpu->ebx)) goto label_000910CD;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x30u)), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    goto label_000910C7;
    label_000910C5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4910C5u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    label_000910C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4910C7u);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000911E7;
    label_000910CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4910CDu);
    if ((uint32_t)(lift_load32(cpu->esp + 0xC4u)) == (uint32_t)(cpu->ebx)) goto label_000911E7;
    cpu->edx = (uint32_t)(cpu->esp + 0xB4u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xECu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4910EDu); lift_push32(cpu, r); sfera_sub_00490730(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    cpu->edx = (uint32_t)(cpu->esp + 0x44u);
    cpu->edi = 0x10u;
    if ((uint32_t)(cpu->edx) == (uint32_t)(cpu->esi)) goto label_00091156;
    if ((uint32_t)(lift_load32(cpu->esp + 0x58u)) < (uint32_t)(cpu->edi)) goto label_0009110F;
    cpu->eax = lift_load32(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49110Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009110F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49110Fu);
    lift_store32(cpu->esp + 0x58u, 0xFu);
    lift_store32(cpu->esp + 0x54u, cpu->ebx);
    lift_store8(cpu->esp + 0x44u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esi + 0x14u)) >= (uint32_t)(cpu->edi)) goto label_0009113A;
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x49112Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x491135u);
    cpu->esp += 0xCu;
    goto label_00091142;
    label_0009113A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49113Au);
    cpu->edx = lift_load32(cpu->esi);
    lift_store32(cpu->esp + 0x44u, cpu->edx);
    lift_store32(cpu->esi, cpu->ebx);
    label_00091142: cpu->eip = LIFT_CODE_TOKEN_VA(0x491142u);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    lift_store32(cpu->esp + 0x54u, cpu->eax);
    cpu->ecx = lift_load32(cpu->esi + 0x14u);
    lift_store32(cpu->esp + 0x58u, cpu->ecx);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, cpu->ebx);
    label_00091156: cpu->eip = LIFT_CODE_TOKEN_VA(0x491156u);
    lift_store8(cpu->esp + 0x14Cu, 6u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x100u)) < (uint32_t)(cpu->edi)) goto label_00091177;
    cpu->edx = lift_load32(cpu->esp + 0xECu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491174u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00091177: cpu->eip = LIFT_CODE_TOKEN_VA(0x491177u);
    cpu->esi = lift_load32(cpu->esp + 0x28u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->ebx)) goto label_000911D3;
    cpu->edx = 0x1C8u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49118Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491195u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store8(cpu->esp + 0x14Cu, 0xCu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000911B9;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4911B7u); lift_push32(cpu, r); sfera_sub_004315D0(cpu,r); if (cpu->eip != r) return; }
    goto label_000911BB;
    label_000911B9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4911B9u);
    cpu->eax = 0u;
    label_000911BB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4911BBu);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x150u, 6u);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x911D3u); lift_push32(cpu, r); sfera_sub_0048E6A0(cpu,r); if (cpu->eip != r) return; }
    label_000911D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4911D3u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0xDCu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x911E7u); lift_push32(cpu, r); sfera_sub_0048E270(cpu,r); if (cpu->eip != r) return; }
    label_000911E7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4911E7u);
    cpu->esi = lift_load32(cpu->esp + 0x2Cu);
    if ((uint32_t)(cpu->esi) == (uint32_t)(0xFFFFFFFFu)) goto label_0009127A;
    cpu->edi = 0x10u;
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    lift_store32(cpu->esp + 0x30u, cpu->ebp);
    if ((uint32_t)(lift_load32(cpu->esp + 0x90u)) < (uint32_t)(cpu->edi)) goto label_00091217;
    cpu->ecx = lift_load32(cpu->esp + 0x7Cu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491214u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00091217: cpu->eip = LIFT_CODE_TOKEN_VA(0x491217u);
    lift_store32(cpu->esp + 0x90u, 0xFu);
    lift_store32(cpu->esp + 0x8Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x7Cu, cpu->ebx & 0xFFu);
    lift_store8(cpu->esp + 0x14Cu, 4u);
    if ((uint32_t)(lift_load32(cpu->esp + 0xC8u)) < (uint32_t)(cpu->edi)) goto label_0009124E;
    cpu->edx = lift_load32(cpu->esp + 0xB4u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49124Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009124E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49124Eu);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->esi);
    cpu->edx = (uint32_t)(cpu->esp + 0x114u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491269u); lift_push32(cpu, r); sfera_sub_0048EFE0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->esi;
    cpu->esi = 0xFu;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00090DB6;
    goto label_000912DA;
    label_0009127A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49127Au);
    cpu->esi = 0x10u;
    lift_store8(cpu->esp + 0x17u, 1u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x90u)) < (uint32_t)(cpu->esi)) goto label_0009129A;
    cpu->edx = lift_load32(cpu->esp + 0x7Cu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491297u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009129A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49129Au);
    lift_store32(cpu->esp + 0x90u, 0xFu);
    lift_store32(cpu->esp + 0x8Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x7Cu, cpu->ebx & 0xFFu);
    lift_store8(cpu->esp + 0x14Cu, 4u);
    if ((uint32_t)(lift_load32(cpu->esp + 0xC8u)) < (uint32_t)(cpu->esi)) goto label_000912D1;
    cpu->eax = lift_load32(cpu->esp + 0xB4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4912CEu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000912D1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4912D1u);
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    cpu->esi = 0xFu;
    label_000912DA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4912DAu);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    if ((uint32_t)(cpu->edi) >= (uint32_t)(lift_load32(cpu->ecx + 0x10u))) goto label_000913F7;
    if ((uint32_t)(cpu->ebp) != (uint32_t)(cpu->ebx)) goto label_000913F7;
    if ((uint8_t)(lift_load8(cpu->esp + 0x17u)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000913F7;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->edi);
    cpu->edx = (uint32_t)(cpu->esp + 0xF4u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491309u); lift_push32(cpu, r); sfera_sub_00431640(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0xB4u);
    lift_store8(cpu->esp + 0x14Cu, 0xDu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49131Fu); lift_push32(cpu, r); sfera_sub_00490730(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x48u);
    lift_store8(cpu->esp + 0x150u, 0xEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491331u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0x10u;
    if ((uint32_t)(lift_load32(cpu->esp + 0xC8u)) < (uint32_t)(cpu->edi)) goto label_0009134F;
    cpu->eax = lift_load32(cpu->esp + 0xB4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49134Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009134F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49134Fu);
    lift_store32(cpu->esp + 0xC8u, cpu->esi);
    lift_store32(cpu->esp + 0xC4u, cpu->ebx);
    lift_store8(cpu->esp + 0xB4u, cpu->ebx & 0xFFu);
    lift_store8(cpu->esp + 0x14Cu, 4u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x100u)) < (uint32_t)(cpu->edi)) goto label_00091385;
    cpu->ecx = lift_load32(cpu->esp + 0xECu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491382u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00091385: cpu->eip = LIFT_CODE_TOKEN_VA(0x491385u);
    cpu->ebp = lift_load32(cpu->esp + 0x28u);
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->ebx)) goto label_000913E1;
    cpu->edx = 0x1D7u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49139Cu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4913A3u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    lift_store8(cpu->esp + 0x14Cu, 0xFu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000913C7;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4913C5u); lift_push32(cpu, r); sfera_sub_004315D0(cpu,r); if (cpu->eip != r) return; }
    goto label_000913C9;
    label_000913C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4913C7u);
    cpu->eax = 0u;
    label_000913C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4913C9u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->esp + 0x150u, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x913E1u); lift_push32(cpu, r); sfera_sub_0048E6A0(cpu,r); if (cpu->eip != r) return; }
    label_000913E1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4913E1u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0xDCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4913F5u); lift_push32(cpu, r); sfera_sub_0048E270(cpu,r); if (cpu->eip != r) return; }
    goto label_000913FC;
    label_000913F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4913F7u);
    cpu->edi = 0x10u;
    label_000913FC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4913FCu);
    cpu->ecx = lift_load32(cpu->esp + 0x3Cu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00091414;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0xD8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x91414u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    label_00091414: cpu->eip = LIFT_CODE_TOKEN_VA(0x491414u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x58u)) < (uint32_t)(cpu->edi)) goto label_00091427;
    cpu->eax = lift_load32(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491424u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00091427: cpu->eip = LIFT_CODE_TOKEN_VA(0x491427u);
    lift_store32(cpu->esp + 0x58u, cpu->esi);
    lift_store32(cpu->esp + 0x54u, cpu->ebx);
    lift_store8(cpu->esp + 0x44u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0xE4u)) < (uint32_t)(cpu->edi)) goto label_0009144C;
    cpu->ecx = lift_load32(cpu->esp + 0xD0u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491449u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009144C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49144Cu);
    lift_store32(cpu->esp + 0xE4u, cpu->esi);
    lift_store32(cpu->esp + 0xE0u, cpu->ebx);
    lift_store8(cpu->esp + 0xD0u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x74u)) < (uint32_t)(cpu->edi)) goto label_00091474;
    cpu->edx = lift_load32(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491471u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00091474: cpu->eip = LIFT_CODE_TOKEN_VA(0x491474u);
    lift_store32(cpu->esp + 0x74u, cpu->esi);
    lift_store32(cpu->esp + 0x70u, cpu->ebx);
    lift_store8(cpu->esp + 0x60u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x138u)) < (uint32_t)(cpu->edi)) goto label_00091499;
    cpu->eax = lift_load32(cpu->esp + 0x124u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491496u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00091499: cpu->eip = LIFT_CODE_TOKEN_VA(0x491499u);
    lift_store32(cpu->esp + 0x138u, cpu->esi);
    lift_store32(cpu->esp + 0x134u, cpu->ebx);
    lift_store8(cpu->esp + 0x124u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x11Cu)) < (uint32_t)(cpu->edi)) goto label_000914C7;
    cpu->ecx = lift_load32(cpu->esp + 0x108u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4914C4u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000914C7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4914C7u);
    cpu->ecx = lift_load32(cpu->esp + 0x144u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x13Cu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00491500(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x491500u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x224u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x238u);
    (void)0; /* source SEH registration eliminated */
    cpu->eax = lift_load32(cpu->esp + 0x248u);
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    cpu->ebx = 0u;
    cpu->esi = cpu->ecx;
    cpu->ebp = cpu->edx;
    cpu->eax = 0xFu;
    lift_store32(cpu->esp + 0x28u, cpu->esi);
    lift_store32(cpu->esp + 0x20u, cpu->ebp);
    lift_store32(cpu->esp + 0xA4u, cpu->eax);
    lift_store32(cpu->esp + 0xA0u, cpu->ebx);
    lift_store8(cpu->esp + 0x90u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esp + 0x240u, cpu->ebx);
    lift_store32(cpu->esp + 0x88u, cpu->eax);
    lift_store32(cpu->esp + 0x84u, cpu->ebx);
    lift_store8(cpu->esp + 0x74u, cpu->ebx & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x244u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49159Bu); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4915A7u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(lift_load32(cpu->eax + 8u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00091BE8;
    goto label_000915C4;
    label_000915C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4915C0u);
    cpu->edi = lift_load32(cpu->esp + 0x1Cu);
    label_000915C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4915C4u);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    { uint64_t l=(uint64_t)(cpu->ebp), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000915D0;
    lift_flags_logic(cpu,0u,32u); cpu->edx = 0u;
    goto label_000915D3;
    label_000915D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4915D0u);
    cpu->edx = lift_load32(cpu->ebp);
    label_000915D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4915D3u);
    cpu->ecx = lift_load32(cpu->edx + 8u);
    cpu->esi = cpu->edi;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(2u), 32u);
    cpu->eax = cpu->esi;
    cpu->edi &= 3u;
    lift_store32(cpu->esp + 0x2Cu, cpu->esi);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000915EA;
    cpu->eax -= cpu->ecx;
    label_000915EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4915EAu);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4915F9u);
    { uint64_t l=(uint64_t)(cpu->eax), r=(uint64_t)(3u), c=(uint64_t)(0u), v=l - r - c; lift_flags_sub(cpu,l,r,c,v,32u); cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00091AD4;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_000919EA;
    { uint64_t l=(uint64_t)(cpu->eax), v=l - 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_sub(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00091BC4;
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"/l");
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_store32(cpu->esp + 0x58u, 0xFu);
    lift_store32(cpu->esp + 0x54u, cpu->ebx);
    lift_store8(cpu->esp + 0x44u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491630u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x240u, 4u);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(cpu->ebx)) goto label_00091640;
    cpu->ecx = 0u;
    goto label_00091643;
    label_00091640: cpu->eip = LIFT_CODE_TOKEN_VA(0x491640u);
    cpu->ecx = lift_load32(cpu->ebp);
    label_00091643: cpu->eip = LIFT_CODE_TOKEN_VA(0x491643u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_0009164E;
    cpu->eax -= cpu->edx;
    label_0009164E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49164Eu);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x100u);
    cpu->eax = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491666u); lift_push32(cpu, r); sfera_sub_004313F0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store8(cpu->esp + 0x240u, 5u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_0009167C;
    cpu->ecx = 0u;
    goto label_0009167E;
    label_0009167C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49167Cu);
    cpu->ecx = lift_load32(cpu->eax);
    label_0009167E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49167Eu);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_00091689;
    cpu->eax -= cpu->edx;
    label_00091689: cpu->eip = LIFT_CODE_TOKEN_VA(0x491689u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = (uint32_t)(cpu->esp + 0xC8u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4916A1u); lift_push32(cpu, r); sfera_sub_004315A0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"l ");
    cpu->ecx = (uint32_t)(cpu->esp + 0x60u);
    lift_store8(cpu->esp + 0x248u, 6u);
    lift_store32(cpu->esp + 0x74u, 0xFu);
    lift_store32(cpu->esp + 0x70u, cpu->ebx);
    lift_store8(cpu->esp + 0x60u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4916CBu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(0x3Cu) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1ACu);
    lift_store8(cpu->esp + 0x244u, 7u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4916E6u); lift_push32(cpu, r); sfera_sub_00490190(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x158u);
    lift_store8(cpu->esp + 0x244u, 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4916FDu); lift_push32(cpu, r); sfera_sub_004901D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x3Eu);
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x1C8u);
    lift_store8(cpu->esp + 0x244u, 9u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491715u); lift_push32(cpu, r); sfera_sub_00490240(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x120u);
    lift_store8(cpu->esp + 0x244u, 0xAu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49172Cu); lift_push32(cpu, r); sfera_sub_004901D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x3Cu);
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x190u);
    lift_store8(cpu->esp + 0x244u, 0xBu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491744u); lift_push32(cpu, r); sfera_sub_00490240(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0xB0u);
    lift_store8(cpu->esp + 0x244u, 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49175Fu); lift_push32(cpu, r); sfera_sub_004901D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x3Eu);
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0xE8u);
    lift_store8(cpu->esp + 0x244u, 0xDu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491777u); lift_push32(cpu, r); sfera_sub_00490240(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x9Cu);
    lift_store8(cpu->esp + 0x24Cu, 0xEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49178Fu); lift_push32(cpu, r); sfera_sub_0048E270(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0x10u;
    if ((uint32_t)(lift_load32(cpu->esp + 0xF8u)) < (uint32_t)(cpu->esi)) goto label_000917AD;
    cpu->edx = lift_load32(cpu->esp + 0xE4u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4917AAu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000917AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4917ADu);
    cpu->ebp = 0xFu;
    lift_store32(cpu->esp + 0xF8u, cpu->ebp);
    lift_store32(cpu->esp + 0xF4u, cpu->ebx);
    lift_store8(cpu->esp + 0xE4u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0xC0u)) < (uint32_t)(cpu->esi)) goto label_000917E0;
    cpu->eax = lift_load32(cpu->esp + 0xACu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4917DDu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000917E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4917E0u);
    lift_store32(cpu->esp + 0xC0u, cpu->ebp);
    lift_store32(cpu->esp + 0xBCu, cpu->ebx);
    lift_store8(cpu->esp + 0xACu, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x1A0u)) < (uint32_t)(cpu->esi)) goto label_0009180E;
    cpu->ecx = lift_load32(cpu->esp + 0x18Cu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49180Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009180E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49180Eu);
    lift_store32(cpu->esp + 0x1A0u, cpu->ebp);
    lift_store32(cpu->esp + 0x19Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x18Cu, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x130u)) < (uint32_t)(cpu->esi)) goto label_0009183C;
    cpu->edx = lift_load32(cpu->esp + 0x11Cu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491839u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009183C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49183Cu);
    lift_store32(cpu->esp + 0x130u, cpu->ebp);
    lift_store32(cpu->esp + 0x12Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x11Cu, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x1D8u)) < (uint32_t)(cpu->esi)) goto label_0009186A;
    cpu->eax = lift_load32(cpu->esp + 0x1C4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491867u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009186A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49186Au);
    lift_store32(cpu->esp + 0x1D8u, cpu->ebp);
    lift_store32(cpu->esp + 0x1D4u, cpu->ebx);
    lift_store8(cpu->esp + 0x1C4u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x168u)) < (uint32_t)(cpu->esi)) goto label_00091898;
    cpu->ecx = lift_load32(cpu->esp + 0x154u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491895u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00091898: cpu->eip = LIFT_CODE_TOKEN_VA(0x491898u);
    lift_store32(cpu->esp + 0x168u, cpu->ebp);
    lift_store32(cpu->esp + 0x164u, cpu->ebx);
    lift_store8(cpu->esp + 0x154u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x1BCu)) < (uint32_t)(cpu->esi)) goto label_000918C6;
    cpu->edx = lift_load32(cpu->esp + 0x1A8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4918C3u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000918C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4918C6u);
    lift_store32(cpu->esp + 0x1BCu, cpu->ebp);
    lift_store32(cpu->esp + 0x1B8u, cpu->ebx);
    lift_store8(cpu->esp + 0x1A8u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x6Cu)) < (uint32_t)(cpu->esi)) goto label_000918EE;
    cpu->eax = lift_load32(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4918EBu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000918EE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4918EEu);
    lift_store32(cpu->esp + 0x6Cu, cpu->ebp);
    lift_store32(cpu->esp + 0x68u, cpu->ebx);
    lift_store8(cpu->esp + 0x58u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0xDCu)) < (uint32_t)(cpu->esi)) goto label_00091913;
    cpu->ecx = lift_load32(cpu->esp + 0xC8u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491910u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00091913: cpu->eip = LIFT_CODE_TOKEN_VA(0x491913u);
    lift_store32(cpu->esp + 0xDCu, cpu->ebp);
    lift_store32(cpu->esp + 0xD8u, cpu->ebx);
    lift_store8(cpu->esp + 0xC8u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x114u)) < (uint32_t)(cpu->esi)) goto label_00091941;
    cpu->edx = lift_load32(cpu->esp + 0x100u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49193Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00091941: cpu->eip = LIFT_CODE_TOKEN_VA(0x491941u);
    lift_store32(cpu->esp + 0x114u, cpu->ebp);
    lift_store32(cpu->esp + 0x110u, cpu->ebx);
    lift_store8(cpu->esp + 0x100u, cpu->ebx & 0xFFu);
    lift_store8(cpu->esp + 0x240u, 1u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x50u)) < (uint32_t)(cpu->esi)) goto label_00091971;
    cpu->eax = lift_load32(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49196Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00091971: cpu->eip = LIFT_CODE_TOKEN_VA(0x491971u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x50u, cpu->ebp);
    lift_store32(cpu->esp + 0x4Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x3Cu, cpu->ebx & 0xFFu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_00091989;
    cpu->ecx = 0u;
    goto label_0009198B;
    label_00091989: cpu->eip = LIFT_CODE_TOKEN_VA(0x491989u);
    cpu->ecx = lift_load32(cpu->eax);
    label_0009198B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49198Bu);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_00091998;
    cpu->eax -= cpu->edx;
    label_00091998: cpu->eip = LIFT_CODE_TOKEN_VA(0x491998u);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    cpu->edi = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    cpu->eax = (uint32_t)(cpu->esp + 0x1E0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4919B1u); lift_push32(cpu, r); sfera_sub_004314D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x80u);
    lift_store8(cpu->esp + 0x24Cu, 0xFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4919C9u); lift_push32(cpu, r); sfera_sub_0048E270(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x240u, 1u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x1F4u)) < (uint32_t)(cpu->esi)) goto label_00091BC4;
    cpu->ecx = lift_load32(cpu->esp + 0x1E0u);
    goto label_00091BBB;
    label_000919EA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4919EAu);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(cpu->ebx)) goto label_000919F2;
    cpu->ecx = 0u;
    goto label_000919F5;
    label_000919F2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4919F2u);
    cpu->ecx = lift_load32(cpu->ebp);
    label_000919F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4919F5u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_00091A00;
    cpu->eax -= cpu->edx;
    label_00091A00: cpu->eip = LIFT_CODE_TOKEN_VA(0x491A00u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x138u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491A18u); lift_push32(cpu, r); sfera_sub_004313F0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x9Cu);
    lift_store8(cpu->esp + 0x24Cu, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491A30u); lift_push32(cpu, r); sfera_sub_0048E270(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x14Cu)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x240u, 1u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00091A52;
    cpu->edx = lift_load32(cpu->esp + 0x138u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491A4Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00091A52: cpu->eip = LIFT_CODE_TOKEN_VA(0x491A52u);
    lift_store32(cpu->esp + 0x14Cu, 0xFu);
    lift_store32(cpu->esp + 0x148u, cpu->ebx);
    lift_store8(cpu->esp + 0x138u, cpu->ebx & 0xFFu);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(cpu->ebx)) goto label_00091A73;
    cpu->ecx = 0u;
    goto label_00091A76;
    label_00091A73: cpu->eip = LIFT_CODE_TOKEN_VA(0x491A73u);
    cpu->ecx = lift_load32(cpu->ebp);
    label_00091A76: cpu->eip = LIFT_CODE_TOKEN_VA(0x491A76u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_00091A81;
    cpu->eax -= cpu->edx;
    label_00091A81: cpu->eip = LIFT_CODE_TOKEN_VA(0x491A81u);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    cpu->edi = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    cpu->eax = (uint32_t)(cpu->esp + 0x1FCu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491A9Au); lift_push32(cpu, r); sfera_sub_004314D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x80u);
    lift_store8(cpu->esp + 0x24Cu, 3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491AB2u); lift_push32(cpu, r); sfera_sub_0048E270(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x210u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0x240u, 1u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00091BC4;
    cpu->ecx = lift_load32(cpu->esp + 0x1FCu);
    goto label_00091BBB;
    label_00091AD4: cpu->eip = LIFT_CODE_TOKEN_VA(0x491AD4u);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(cpu->ebx)) goto label_00091ADC;
    cpu->ecx = 0u;
    goto label_00091ADF;
    label_00091ADC: cpu->eip = LIFT_CODE_TOKEN_VA(0x491ADCu);
    cpu->ecx = lift_load32(cpu->ebp);
    label_00091ADF: cpu->eip = LIFT_CODE_TOKEN_VA(0x491ADFu);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_00091AEA;
    cpu->eax -= cpu->edx;
    label_00091AEA: cpu->eip = LIFT_CODE_TOKEN_VA(0x491AEAu);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x170u);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491B02u); lift_push32(cpu, r); sfera_sub_004314D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x9Cu);
    lift_store8(cpu->esp + 0x24Cu, 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491B1Au); lift_push32(cpu, r); sfera_sub_0048E270(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = 0x10u;
    lift_store8(cpu->esp + 0x240u, 1u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x184u)) < (uint32_t)(cpu->ebp)) goto label_00091B40;
    cpu->edx = lift_load32(cpu->esp + 0x170u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491B3Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00091B40: cpu->eip = LIFT_CODE_TOKEN_VA(0x491B40u);
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x184u, 0xFu);
    lift_store32(cpu->esp + 0x180u, cpu->ebx);
    lift_store8(cpu->esp + 0x170u, cpu->ebx & 0xFFu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_00091B65;
    cpu->ecx = 0u;
    goto label_00091B67;
    label_00091B65: cpu->eip = LIFT_CODE_TOKEN_VA(0x491B65u);
    cpu->ecx = lift_load32(cpu->eax);
    label_00091B67: cpu->eip = LIFT_CODE_TOKEN_VA(0x491B67u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_00091B72;
    cpu->eax -= cpu->edx;
    label_00091B72: cpu->eip = LIFT_CODE_TOKEN_VA(0x491B72u);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    cpu->edi = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    cpu->eax = (uint32_t)(cpu->esp + 0x218u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491B8Bu); lift_push32(cpu, r); sfera_sub_004314D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x80u);
    lift_store8(cpu->esp + 0x24Cu, 0x11u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491BA3u); lift_push32(cpu, r); sfera_sub_0048E270(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x240u, 1u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x22Cu)) < (uint32_t)(cpu->ebp)) goto label_00091BC4;
    cpu->ecx = lift_load32(cpu->esp + 0x218u);
    label_00091BBB: cpu->eip = LIFT_CODE_TOKEN_VA(0x491BBBu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491BC1u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00091BC4: cpu->eip = LIFT_CODE_TOKEN_VA(0x491BC4u);
    cpu->esi = lift_load32(cpu->esp + 0x1Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    ++cpu->esi;
    lift_push32(cpu, cpu->edx);
    lift_store32(cpu->esp + 0x20u, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491BDBu); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_000915C0;
    cpu->ebp = lift_load32(cpu->esp + 0x20u);
    label_00091BE8: cpu->eip = LIFT_CODE_TOKEN_VA(0x491BE8u);
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->ebx)) goto label_00091BFE;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0x98u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x91BFEu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    label_00091BFE: cpu->eip = LIFT_CODE_TOKEN_VA(0x491BFEu);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00091C13;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x7Cu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x91C13u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    label_00091C13: cpu->eip = LIFT_CODE_TOKEN_VA(0x491C13u);
    cpu->esi = 0x10u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x88u)) < (uint32_t)(cpu->esi)) goto label_00091C2E;
    cpu->eax = lift_load32(cpu->esp + 0x74u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491C2Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00091C2E: cpu->eip = LIFT_CODE_TOKEN_VA(0x491C2Eu);
    if ((uint32_t)(lift_load32(cpu->esp + 0xA4u)) < (uint32_t)(cpu->esi)) goto label_00091C47;
    cpu->ecx = lift_load32(cpu->esp + 0x90u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491C44u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00091C47: cpu->eip = LIFT_CODE_TOKEN_VA(0x491C47u);
    cpu->ecx = lift_load32(cpu->esp + 0x238u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x230u;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00491C80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x491C80u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->edi = cpu->edx;
    cpu->esi = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->esi);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0x10u, cpu->ebx);
    lift_push32(cpu, cpu->ebx);
    lift_store32(cpu->esi + 0x14u, 0xFu);
    lift_store32(cpu->esi + 0x10u, cpu->ebx);
    lift_push32(cpu, (uint32_t)(uintptr_t)"");
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491CCFu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0u;
    cpu->ecx = cpu->edi;
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    lift_store32(cpu->esp + 0x14u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491CE5u); lift_push32(cpu, r); sfera_sub_00490C50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = cpu->esi;
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00491D00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x491D00u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xA0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xB4u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 0x10u)), r=(uint64_t)(1u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x24u, cpu->esi);
    lift_store32(cpu->esp + 0x14u, 0u);
    if ((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) != 0u) goto label_00091FE4;
    lift_push32(cpu, 1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491D66u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491D6Du); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491D79u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    { uint64_t l=(uint64_t)(cpu->edi), r=(uint64_t)(lift_load32(cpu->eax + 8u)), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_ZF) == 0u)) ? 1u : 0u) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00091FE4;
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    label_00091D8F: cpu->eip = LIFT_CODE_TOKEN_VA(0x491D8Fu);
    { uint64_t v=(uint64_t)(cpu->ebx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00091D97;
    lift_flags_logic(cpu,0u,32u); cpu->edx = 0u;
    goto label_00091D99;
    label_00091D97: cpu->eip = LIFT_CODE_TOKEN_VA(0x491D97u);
    cpu->edx = lift_load32(cpu->ebx);
    label_00091D99: cpu->eip = LIFT_CODE_TOKEN_VA(0x491D99u);
    cpu->ecx = lift_load32(cpu->edx + 8u);
    cpu->ebp = cpu->edi;
    cpu->ebp = lift_shift_right(cpu, cpu->ebp, (uint32_t)(2u), 32u);
    cpu->eax = cpu->ebp;
    cpu->edi &= 3u;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_00091DAC;
    cpu->eax -= cpu->ecx;
    label_00091DAC: cpu->eip = LIFT_CODE_TOKEN_VA(0x491DACu);
    cpu->ecx = lift_load32(cpu->edx + 4u);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x491DBBu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(4u)) goto label_00091E0D;
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) | (uint64_t)(1u));
    lift_push32(cpu, 1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491DD5u); lift_push32(cpu, r); sfera_sub_0048E0A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00091DDF;
    lift_flags_logic(cpu,0u,32u); cpu->esi = 0u;
    goto label_00091DE1;
    label_00091DDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x491DDFu);
    cpu->esi = lift_load32(cpu->ecx);
    label_00091DE1: cpu->eip = LIFT_CODE_TOKEN_VA(0x491DE1u);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ecx &= 3u;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_00091DF5;
    cpu->eax -= cpu->edx;
    label_00091DF5: cpu->eip = LIFT_CODE_TOKEN_VA(0x491DF5u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x491E04u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(4u)) goto label_00091E0D;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    goto label_00091E0F;
    label_00091E0D: cpu->eip = LIFT_CODE_TOKEN_VA(0x491E0Du);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    label_00091E0F: cpu->eip = LIFT_CODE_TOKEN_VA(0x491E0Fu);
    if ((uint8_t)((lift_load8(cpu->esp + 0x14u)) & (1u)) == 0u) goto label_00091E1B;
    lift_store32(cpu->esp + 0x14u, (uint64_t)(lift_load32(cpu->esp + 0x14u)) & (uint64_t)(0xFFFFFFFEu));
    label_00091E1B: cpu->eip = LIFT_CODE_TOKEN_VA(0x491E1Bu);
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00091FC5;
    lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491E33u); lift_push32(cpu, r); sfera_sub_0048E0A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    { uint64_t v=(uint64_t)(cpu->ecx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00091E3D;
    lift_flags_logic(cpu,0u,32u); cpu->esi = 0u;
    goto label_00091E3F;
    label_00091E3D: cpu->eip = LIFT_CODE_TOKEN_VA(0x491E3Du);
    cpu->esi = lift_load32(cpu->ecx);
    label_00091E3F: cpu->eip = LIFT_CODE_TOKEN_VA(0x491E3Fu);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ecx &= 3u;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_00091E53;
    cpu->eax -= cpu->edx;
    label_00091E53: cpu->eip = LIFT_CODE_TOKEN_VA(0x491E53u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->esi = lift_load32(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x78u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491E68u); lift_push32(cpu, r); sfera_sub_004314D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0xBCu, cpu->ecx);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->ecx)) goto label_00091E77;
    cpu->ecx = lift_load32(cpu->ebx);
    label_00091E77: cpu->eip = LIFT_CODE_TOKEN_VA(0x491E77u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->eax = cpu->ebp;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_00091E82;
    cpu->eax -= cpu->edx;
    label_00091E82: cpu->eip = LIFT_CODE_TOKEN_VA(0x491E82u);
    cpu->edx = lift_load32(cpu->ecx + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->ecx = (uint32_t)(cpu->esp + 0x5Cu);
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->edi) * 4u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491E97u); lift_push32(cpu, r); sfera_sub_004314D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x5Cu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x7Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x98u);
    lift_store8(cpu->esp + 0xC0u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491EB4u); lift_push32(cpu, r); sfera_sub_00490280(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0xC0u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491EC4u); lift_push32(cpu, r); sfera_sub_004317E0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0xA8u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0xBCu, 1u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00091EE6;
    cpu->eax = lift_load32(cpu->esp + 0x94u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491EE3u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00091EE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x491EE6u);
    cpu->edx = 0x251u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491EF5u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = 0u;
    if ((uint32_t)(cpu->ebx) != (uint32_t)(cpu->esi)) goto label_00091EFF;
    cpu->ecx = 0u;
    goto label_00091F01;
    label_00091EFF: cpu->eip = LIFT_CODE_TOKEN_VA(0x491EFFu);
    cpu->ecx = lift_load32(cpu->ebx);
    label_00091F01: cpu->eip = LIFT_CODE_TOKEN_VA(0x491F01u);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->eax = cpu->ebp;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_00091F0C;
    cpu->eax -= cpu->edx;
    label_00091F0C: cpu->eip = LIFT_CODE_TOKEN_VA(0x491F0Cu);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491F1Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 8u;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x34u, cpu->esp);
    lift_store32(cpu->eax, cpu->esi);
    lift_store32(cpu->eax + 4u, cpu->esi);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->esi)) goto label_00091F37;
    cpu->ecx = lift_load32(cpu->ebx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->esi)) goto label_00091F37;
    cpu->ecx = lift_load32(cpu->ecx);
    lift_store32(cpu->eax, cpu->ecx);
    label_00091F37: cpu->eip = LIFT_CODE_TOKEN_VA(0x491F37u);
    cpu->edx = lift_load32(cpu->esp + 0x2Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x30u);
    lift_store32(cpu->eax + 8u, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x5Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491F4Cu); lift_push32(cpu, r); sfera_sub_0048F090(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->ebx) == (uint32_t)(cpu->ecx)) goto label_00091F5E;
    cpu->ecx = lift_load32(cpu->ecx);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->esi)) goto label_00091F5E;
    cpu->ebx = lift_load32(cpu->ecx);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    label_00091F5E: cpu->eip = LIFT_CODE_TOKEN_VA(0x491F5Eu);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->ebp = 0x10u;
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    if ((uint32_t)(lift_load32(cpu->esp + 0x70u)) < (uint32_t)(cpu->ebp)) goto label_00091F7D;
    cpu->edx = lift_load32(cpu->esp + 0x5Cu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491F7Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00091F7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x491F7Du);
    cpu->edi = 0xFu;
    lift_store32(cpu->esp + 0x70u, cpu->edi);
    lift_store32(cpu->esp + 0x6Cu, cpu->esi);
    lift_store8(cpu->esp + 0x5Cu, 0u);
    lift_store32(cpu->esp + 0xBCu, 0xFFFFFFFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x8Cu)) < (uint32_t)(cpu->ebp)) goto label_00091FB0;
    cpu->eax = lift_load32(cpu->esp + 0x78u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491FADu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00091FB0: cpu->eip = LIFT_CODE_TOKEN_VA(0x491FB0u);
    lift_store32(cpu->esp + 0x8Cu, cpu->edi);
    lift_store32(cpu->esp + 0x88u, cpu->esi);
    lift_store8(cpu->esp + 0x78u, 0u);
    goto label_00091FC9;
    label_00091FC5: cpu->eip = LIFT_CODE_TOKEN_VA(0x491FC5u);
    lift_store32(cpu->esp + 0x20u, (uint64_t)(lift_load32(cpu->esp + 0x20u)) + 1u);
    label_00091FC9: cpu->eip = LIFT_CODE_TOKEN_VA(0x491FC9u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x491FD7u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->edi) != (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_00091D8F;
    label_00091FE4: cpu->eip = LIFT_CODE_TOKEN_VA(0x491FE4u);
    cpu->ecx = lift_load32(cpu->esp + 0xB4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xACu;
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00492010(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x492010u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x68u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x7Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = lift_load32(cpu->esp + 0x8Cu);
    cpu->edi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->edi + 0x10u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->esi = cpu->edx;
    lift_store32(cpu->esp + 0x18u, cpu->esi);
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_0009205E;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    goto label_000923BE;
    label_0009205E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49205Eu);
    cpu->eax = lift_load32(cpu->esi + 0x10u);
    if ((uint32_t)(cpu->eax) != 0u) goto label_000920C1;
    cpu->edx = 0x25Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492074u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49207Bu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x84u, 0u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000920AF;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49209Fu); lift_push32(cpu, r); sfera_sub_004315D0(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    goto label_000923AC;
    label_000920AF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4920AFu);
    cpu->eax = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    goto label_000923AC;
    label_000920C1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4920C1u);
    if ((uint32_t)(cpu->ebx) < (uint32_t)(cpu->eax)) goto label_000920C8;
    cpu->ebx = (uint32_t)(cpu->eax + 0xFFFFFFFFu);
    label_000920C8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4920C8u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4920D0u); lift_push32(cpu, r); sfera_sub_0048EAC0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->eax);
    cpu->ecx = cpu->esi;
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4920DAu);
    cpu->ebp = cpu->eax;
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4920E3u); lift_push32(cpu, r); sfera_sub_004312C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00092361;
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = (uint32_t)(cpu->esp + 0x48u);
    lift_store32(cpu->esp + 0x5Cu, 0xFu);
    lift_store32(cpu->esp + 0x58u, 0u);
    lift_store8(cpu->esp + 0x48u, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492110u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->esp + 0x84u, 1u);
    if ((uint32_t)(cpu->ebp) != (uint32_t)(4u)) goto label_00092192;
    cpu->ecx = (uint32_t)(cpu->esp + 0x5Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49212Cu); lift_push32(cpu, r); sfera_sub_004314D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_store8(cpu->esp + 0x88u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49213Eu); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x5Cu);
    lift_store8(cpu->esp + 0x84u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49214Fu); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x90u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(lift_load32(cpu->esp + 0x5Cu))) goto label_0009217C;
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49216Bu); lift_push32(cpu, r); sfera_sub_0048EE60(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492177u); lift_push32(cpu, r); sfera_sub_004317E0(cpu,r); if (cpu->eip != r) return; }
    goto label_0009234B;
    label_0009217C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49217Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492181u); lift_push32(cpu, r); sfera_sub_0048E270(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49218Du); lift_push32(cpu, r); sfera_sub_004317E0(cpu,r); if (cpu->eip != r) return; }
    goto label_0009234B;
    label_00092192: cpu->eip = LIFT_CODE_TOKEN_VA(0x492192u);
    cpu->ebp = lift_load32(cpu->esp + 0x90u);
    if ((uint32_t)(cpu->ebp) != 0u) goto label_00092227;
    cpu->edx = 0x277u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4921B0u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4921B7u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store8(cpu->esp + 0x84u, 3u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000921D7;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4921D5u); lift_push32(cpu, r); sfera_sub_004315D0(cpu,r); if (cpu->eip != r) return; }
    goto label_000921D9;
    label_000921D7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4921D7u);
    cpu->eax = 0u;
    label_000921D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4921D9u);
    cpu->esi = lift_load32(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->eax = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0x94u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492200u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492207u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->esp + 0x28u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492216u); lift_push32(cpu, r); sfera_sub_0048DD80(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492222u); lift_push32(cpu, r); sfera_sub_0048FEF0(cpu,r); if (cpu->eip != r) return; }
    goto label_0009234B;
    label_00092227: cpu->eip = LIFT_CODE_TOKEN_VA(0x492227u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x5Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492233u); lift_push32(cpu, r); sfera_sub_004314D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_store8(cpu->esp + 0x88u, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492245u); lift_push32(cpu, r); sfera_sub_00409130(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x5Cu);
    lift_store8(cpu->esp + 0x84u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492256u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->ebp) == 0u) goto label_000922F6;
    if ((uint32_t)(cpu->ebp) >= (uint32_t)(lift_load32(cpu->esp + 0x50u))) goto label_000922F6;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492277u); lift_push32(cpu, r); sfera_sub_0048EE60(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0x27Eu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492286u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49228Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->edx = 0x27Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49229Eu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4922A5u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store8(cpu->esp + 0x84u, 5u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_000922CE;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4922CAu); lift_push32(cpu, r); sfera_sub_004315D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    goto label_000922D0;
    label_000922CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4922CEu);
    cpu->esi = 0u;
    label_000922D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4922D0u);
    lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4922E4u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4922EBu); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4922F2u); lift_push32(cpu, r); sfera_sub_0048DB70(cpu,r); if (cpu->eip != r) return; }
    lift_store32(cpu->eax, cpu->esi);
    goto label_0009234B;
    label_000922F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4922F6u);
    cpu->edx = 0x282u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492305u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49230Cu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store8(cpu->esp + 0x84u, 6u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009232F;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49232Du); lift_push32(cpu, r); sfera_sub_004315D0(cpu,r); if (cpu->eip != r) return; }
    goto label_00092331;
    label_0009232F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49232Fu);
    cpu->eax = 0u;
    label_00092331: cpu->eip = LIFT_CODE_TOKEN_VA(0x492331u);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->edx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    lift_store8(cpu->esp + 0x88u, 1u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9234Bu); lift_push32(cpu, r); sfera_sub_0048E6A0(cpu,r); if (cpu->eip != r) return; }
    label_0009234B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49234Bu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x54u)) < (uint32_t)(0x10u)) goto label_000923BC;
    cpu->eax = lift_load32(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49235Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    goto label_000923BC;
    label_00092361: cpu->eip = LIFT_CODE_TOKEN_VA(0x492361u);
    cpu->edx = 0x287u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492370u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492377u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    lift_store32(cpu->esp + 0x84u, 7u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009239D;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49239Bu); lift_push32(cpu, r); sfera_sub_004315D0(cpu,r); if (cpu->eip != r) return; }
    goto label_0009239F;
    label_0009239D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49239Du);
    cpu->eax = 0u;
    label_0009239F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49239Fu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    label_000923AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4923ACu);
    lift_store32(cpu->esp + 0x88u, 0xFFFFFFFFu);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x923BCu); lift_push32(cpu, r); sfera_sub_0048E6A0(cpu,r); if (cpu->eip != r) return; }
    label_000923BC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4923BCu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    label_000923BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4923BEu);
    cpu->ecx = lift_load32(cpu->esp + 0x7Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x74u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004923E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4923E0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x8Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xA0u);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->edx;
    cpu->ebx = cpu->ecx;
    cpu->edi = 0u;
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->edi);
    lift_push32(cpu, 8u);
    lift_store32(cpu->esp + 0xACu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492437u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edi)) goto label_0009278D;
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = 0u;
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->esp + 0x20u, cpu->edi);
    lift_store32(cpu->esp + 0x24u, cpu->edi);
    lift_store32(cpu->esp + 0x28u, cpu->edi);
    lift_store32(cpu->esp + 0x2Cu, cpu->edi);
    lift_store32(cpu->esp + 0xA8u, 1u);
    if ((uint32_t)(lift_load32(cpu->ebx + 0x10u)) == (uint32_t)(cpu->edi)) goto label_0009277A;
    cpu->edi = lift_load32(cpu->esp + 0xB0u);
    if ((uint32_t)(cpu->esi) > (uint32_t)(cpu->edi)) goto label_000926AD;
    cpu->edx = (uint32_t)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49249Fu); lift_push32(cpu, r); sfera_sub_0048E950(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_000926AD;
    cpu->ebp |= 0xFFFFFFFFu;
    if ((uint32_t)(lift_load32(cpu->esp + 0x34u)) == (uint32_t)(cpu->ebp)) goto label_000926AD;
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4924C7u); lift_push32(cpu, r); sfera_sub_0048E950(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000924D4;
    cpu->eax = lift_load32(cpu->ebx + 0x10u);
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    goto label_000924D8;
    label_000924D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4924D4u);
    cpu->ebp = lift_load32(cpu->esp + 0x38u);
    label_000924D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4924D8u);
    cpu->esi = 0u;
    if ((uint32_t)(lift_load32(cpu->ebx + 0x10u)) <= (uint32_t)(cpu->esi)) goto label_00092640;
    label_000924E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4924E3u);
    cpu->edi = lift_load32(cpu->esp + 0x18u);
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->edi)) goto label_00092614;
    if ((uint32_t)(cpu->esi) > (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_00092614;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492501u); lift_push32(cpu, r); sfera_sub_0048EAC0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x20u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49250Bu); lift_push32(cpu, r); sfera_sub_0048E6A0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492513u); lift_push32(cpu, r); sfera_sub_0048EAC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49251Bu);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492522u); lift_push32(cpu, r); sfera_sub_004312C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00092636;
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->edi)) goto label_0009259E;
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492537u); lift_push32(cpu, r); sfera_sub_0048EB70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x80u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492546u); lift_push32(cpu, r); sfera_sub_004314D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x6Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_store8(cpu->esp + 0xB4u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492561u); lift_push32(cpu, r); sfera_sub_00431640(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store8(cpu->esp + 0xA8u, 3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492574u); lift_push32(cpu, r); sfera_sub_0048EB70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49257Cu); lift_push32(cpu, r); sfera_sub_004317E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x64u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492585u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x80u);
    lift_store8(cpu->esp + 0xA8u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492599u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_00092636;
    label_0009259E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49259Eu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_00092636;
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4925B1u); lift_push32(cpu, r); sfera_sub_0048EB70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x64u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4925BDu); lift_push32(cpu, r); sfera_sub_004314D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->ebp + 1u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x88u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    lift_store8(cpu->esp + 0xB4u, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4925DAu); lift_push32(cpu, r); sfera_sub_00431640(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_store8(cpu->esp + 0xA8u, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4925EDu); lift_push32(cpu, r); sfera_sub_0048EB70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4925F5u); lift_push32(cpu, r); sfera_sub_004317E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x80u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492601u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x64u);
    lift_store8(cpu->esp + 0xA8u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492612u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_00092636;
    label_00092614: cpu->eip = LIFT_CODE_TOKEN_VA(0x492614u);
    cpu->edx = 0x2D6u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492623u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49262Bu); lift_push32(cpu, r); sfera_sub_0048EAC0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492633u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00092636: cpu->eip = LIFT_CODE_TOKEN_VA(0x492636u);
    ++cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(lift_load32(cpu->ebx + 0x10u))) goto label_000924E3;
    label_00092640: cpu->eip = LIFT_CODE_TOKEN_VA(0x492640u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x24u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x2Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492653u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->esp + 0x30u, cpu->esp);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x38u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492666u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49266Du); lift_push32(cpu, r); sfera_sub_00490350(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492676u); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    label_0009267B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49267Bu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492680u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0xA0u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x98u;
    lift_return(cpu, 4u, stop_address); return;
    label_000926AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4926ADu);
    cpu->eax = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4926B9u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4926C5u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esp + 0x48u);
    if ((uint32_t)(cpu->ebp) == (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_00092773;
    cpu->ebx = lift_load32(cpu->esp + 0x40u);
    label_000926D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4926D6u);
    { uint64_t v=(uint64_t)(cpu->ebx); lift_flags_logic(cpu,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000926DE;
    lift_flags_logic(cpu,0u,32u); cpu->edx = 0u;
    goto label_000926E0;
    label_000926DE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4926DEu);
    cpu->edx = lift_load32(cpu->ebx);
    label_000926E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4926E0u);
    cpu->ecx = lift_load32(cpu->edx + 8u);
    cpu->esi = cpu->ebp;
    cpu->esi = lift_shift_right(cpu, cpu->esi, (uint32_t)(2u), 32u);
    cpu->edi = cpu->ebp;
    cpu->eax = cpu->esi;
    cpu->edi &= 3u;
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->eax)) goto label_000926F5;
    cpu->eax -= cpu->ecx;
    label_000926F5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4926F5u);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    if ((uint32_t)(lift_load32(cpu->eax + ((uint32_t)(cpu->edi) * 4u))) == (uint32_t)(0u)) goto label_00092757;
    cpu->edx = 0x2E0u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492710u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->ebx) != 0u) goto label_00092718;
    cpu->ecx = 0u;
    goto label_0009271A;
    label_00092718: cpu->eip = LIFT_CODE_TOKEN_VA(0x492718u);
    cpu->ecx = lift_load32(cpu->ebx);
    label_0009271A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49271Au);
    cpu->edx = lift_load32(cpu->ecx + 8u);
    cpu->eax = cpu->esi;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_00092725;
    cpu->eax -= cpu->edx;
    label_00092725: cpu->eip = LIFT_CODE_TOKEN_VA(0x492725u);
    cpu->ecx = lift_load32(cpu->ecx + 4u);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492734u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->ebx) != 0u) goto label_0009273F;
    cpu->eax = 0u;
    goto label_00092741;
    label_0009273F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49273Fu);
    cpu->eax = lift_load32(cpu->ebx);
    label_00092741: cpu->eip = LIFT_CODE_TOKEN_VA(0x492741u);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    if ((uint32_t)(cpu->ecx) > (uint32_t)(cpu->esi)) goto label_0009274A;
    cpu->esi -= cpu->ecx;
    label_0009274A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49274Au);
    cpu->ecx = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->ecx + ((uint32_t)(cpu->esi) * 4u));
    lift_store32(cpu->edx + ((uint32_t)(cpu->edi) * 4u), 0u);
    label_00092757: cpu->eip = LIFT_CODE_TOKEN_VA(0x492757u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = (uint32_t)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->eax);
    ++cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492766u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->ebp) != (uint32_t)(lift_load32(cpu->eax + 8u))) goto label_000926D6;
    cpu->ebx = lift_load32(cpu->esp + 0x14u);
    label_00092773: cpu->eip = LIFT_CODE_TOKEN_VA(0x492773u);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9277Au); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    label_0009277A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49277Au);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492783u); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    goto label_0009267B;
    label_0009278D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49278Du);
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x50u);
    lift_store32(cpu->esp + 0x40u, cpu->edi);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4927B7u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x4927B7u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004927C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4927C0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x58u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x6Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->esi = cpu->edx;
    cpu->ebx = 0u;
    cpu->edi = cpu->ecx;
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    lift_push32(cpu, 8u);
    lift_store32(cpu->esp + 0x78u, cpu->ebx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492807u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00092B0A;
    lift_store32(cpu->esp + 0x24u, cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = 0u;
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    lift_store32(cpu->esp + 0x2Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x30u, cpu->ebx);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store32(cpu->esp + 0x74u, 1u);
    if ((uint32_t)(lift_load32(cpu->edi + 0x10u)) == (uint32_t)(cpu->ebx)) goto label_00092AD3;
    cpu->ebx = lift_load32(cpu->esp + 0x7Cu);
    if ((uint32_t)(cpu->esi) > (uint32_t)(cpu->ebx)) goto label_00092AD3;
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492869u); lift_push32(cpu, r); sfera_sub_0048E950(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00092AD3;
    cpu->ebp |= 0xFFFFFFFFu;
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) == (uint32_t)(cpu->ebp)) goto label_00092AD3;
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = (uint32_t)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492891u); lift_push32(cpu, r); sfera_sub_0048E950(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_000928A2;
    cpu->eax = lift_load32(cpu->edi + 0x10u);
    lift_store32(cpu->esp + 0x1Cu, cpu->eax);
    lift_store32(cpu->esp + 0x14u, cpu->ebp);
    goto label_000928A6;
    label_000928A2: cpu->eip = LIFT_CODE_TOKEN_VA(0x4928A2u);
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    label_000928A6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4928A6u);
    cpu->esi = 0u;
    if ((uint32_t)(lift_load32(cpu->edi + 0x10u)) <= (uint32_t)(cpu->esi)) goto label_00092AA6;
    label_000928B1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4928B1u);
    cpu->eax = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->eax)) goto label_00092A8A;
    if ((uint32_t)(cpu->esi) > (uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_00092A8A;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    if ((uint32_t)(cpu->esi) != (uint32_t)(cpu->eax)) goto label_000929D5;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4928D9u); lift_push32(cpu, r); sfera_sub_0048EAC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_00092967;
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4928EBu);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4928F2u); lift_push32(cpu, r); sfera_sub_004312C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00092A66;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492902u); lift_push32(cpu, r); sfera_sub_0048EAC0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49290Cu); lift_push32(cpu, r); sfera_sub_0048E6A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492915u); lift_push32(cpu, r); sfera_sub_0048EB70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492921u); lift_push32(cpu, r); sfera_sub_004314D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store8(cpu->esp + 0x74u, 2u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492931u); lift_push32(cpu, r); sfera_sub_0048EB70(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->ebp = cpu->eax;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    cpu->edx -= cpu->eax;
    ++cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492947u); lift_push32(cpu, r); sfera_sub_00402810(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebp);
    label_0009294A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49294Au);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492950u); lift_push32(cpu, r); sfera_sub_004317E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_store8(cpu->esp + 0x74u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49295Eu); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = lift_load32(cpu->esp + 0x14u);
    goto label_00092A9C;
    label_00092967: cpu->eip = LIFT_CODE_TOKEN_VA(0x492967u);
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x49296Du);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492974u); lift_push32(cpu, r); sfera_sub_004312C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00092A66;
    if ((uint32_t)(lift_load32(cpu->esp + 0x18u)) <= (uint32_t)(0u)) goto label_00092A66;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49298Fu); lift_push32(cpu, r); sfera_sub_0048EAC0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492999u); lift_push32(cpu, r); sfera_sub_0048E6A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4929A2u); lift_push32(cpu, r); sfera_sub_0048EB70(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4929AEu); lift_push32(cpu, r); sfera_sub_004314D0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebp = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store8(cpu->esp + 0x74u, 3u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4929BEu); lift_push32(cpu, r); sfera_sub_0048EB70(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    cpu->ebx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4929CEu); lift_push32(cpu, r); sfera_sub_00402810(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx);
    goto label_0009294A;
    label_000929D5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4929D5u);
    if ((uint32_t)(cpu->esi) != (uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_00092A66;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4929E7u); lift_push32(cpu, r); sfera_sub_0048EAC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4929EFu);
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4929F6u); lift_push32(cpu, r); sfera_sub_004312C0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00092A66;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492A02u); lift_push32(cpu, r); sfera_sub_0048EAC0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492A0Eu); lift_push32(cpu, r); sfera_sub_004314D0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x74u, 4u);
    if ((uint32_t)(cpu->ebp) >= (uint32_t)(lift_load32(cpu->esp + 0x5Cu))) goto label_00092A54;
    if ((uint32_t)(cpu->ebp) == (uint32_t)(0xFFFFFFFFu)) goto label_00092A54;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492A26u); lift_push32(cpu, r); sfera_sub_0048EAC0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492A30u); lift_push32(cpu, r); sfera_sub_0048E6A0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492A39u); lift_push32(cpu, r); sfera_sub_0048EB70(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->ebp + 1u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    cpu->ebx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492A4Au); lift_push32(cpu, r); sfera_sub_00402810(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->ebx);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492A52u); lift_push32(cpu, r); sfera_sub_004317E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    label_00092A54: cpu->eip = LIFT_CODE_TOKEN_VA(0x492A54u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_store8(cpu->esp + 0x74u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492A62u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)((cpu->ebx & 0xFFu)) != 0u) goto label_00092A9C;
    label_00092A66: cpu->eip = LIFT_CODE_TOKEN_VA(0x492A66u);
    cpu->edx = 0x324u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492A75u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492A7Du); lift_push32(cpu, r); sfera_sub_0048EAC0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492A85u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    goto label_00092A9C;
    label_00092A8A: cpu->eip = LIFT_CODE_TOKEN_VA(0x492A8Au);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492A92u); lift_push32(cpu, r); sfera_sub_0048EAC0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x92A9Cu); lift_push32(cpu, r); sfera_sub_0048E6A0(cpu,r); if (cpu->eip != r) return; }
    label_00092A9C: cpu->eip = LIFT_CODE_TOKEN_VA(0x492A9Cu);
    ++cpu->esi;
    if ((uint32_t)(cpu->esi) < (uint32_t)(lift_load32(cpu->edi + 0x10u))) goto label_000928B1;
    label_00092AA6: cpu->eip = LIFT_CODE_TOKEN_VA(0x492AA6u);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    lift_store32(cpu->esp + 0x2Cu, cpu->esp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492AB9u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->esp + 0x38u, cpu->esp);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492ACCu); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x92AD3u); lift_push32(cpu, r); sfera_sub_00490350(cpu,r); if (cpu->eip != r) return; }
    label_00092AD3: cpu->eip = LIFT_CODE_TOKEN_VA(0x492AD3u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492ADCu); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492AE6u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = lift_load32(cpu->esp + 0x6Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x64u;
    lift_return(cpu, 4u, stop_address); return;
    label_00092B0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x492B0Au);
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_store32(cpu->esp + 0x40u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492B34u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x492B34u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00492B40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x492B40u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1ACu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x1C0u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebx = 0u;
    cpu->ebp = cpu->ecx;
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_push32(cpu, 2u);
    cpu->esi = 0xFu;
    lift_push32(cpu, (uint32_t)(uintptr_t)"/l");
    cpu->ecx = (uint32_t)(cpu->esp + 0x90u);
    lift_store32(cpu->esp + 0x1D0u, 2u);
    lift_store32(cpu->esp + 0xA4u, cpu->esi);
    lift_store32(cpu->esp + 0xA0u, cpu->ebx);
    lift_store8(cpu->esp + 0x90u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492BBBu); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0x210u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x5Cu);
    lift_store8(cpu->esp + 0x1D4u, 3u);
    lift_store32(cpu->esp + 0x70u, cpu->esi);
    lift_store32(cpu->esp + 0x6Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x5Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492BE3u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1F4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_store8(cpu->esp + 0x1D4u, 4u);
    lift_store32(cpu->esp + 0x54u, cpu->esi);
    lift_store32(cpu->esp + 0x50u, cpu->ebx);
    lift_store8(cpu->esp + 0x40u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492C0Bu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x34u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1A0u);
    lift_store8(cpu->esp + 0x1C8u, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492C23u); lift_push32(cpu, r); sfera_sub_004905D0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x1D8u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    lift_store8(cpu->esp + 0x1D4u, 6u);
    lift_store32(cpu->esp + 0x38u, cpu->esi);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    lift_store8(cpu->esp + 0x24u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492C4Du); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 3u); lift_push32(cpu, (uintptr_t)"l=\"");
    cpu->ecx = (uint32_t)(cpu->esp + 0x74u);
    lift_store8(cpu->esp + 0x1D0u, 7u);
    lift_store32(cpu->esp + 0x88u, cpu->esi);
    lift_store32(cpu->esp + 0x84u, cpu->ebx);
    lift_store8(cpu->esp + 0x74u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492C77u); lift_push32(cpu, r); sfera_sub_00406820(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x6Cu);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(0x3Cu) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x16Cu);
    lift_store8(cpu->esp + 0x1CCu, 8u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492C92u); lift_push32(cpu, r); sfera_sub_00490190(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x134u);
    lift_store8(cpu->esp + 0x1CCu, 9u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492CADu); lift_push32(cpu, r); sfera_sub_004901D0(cpu,r); if (cpu->eip != r) return; }
    lift_store8(cpu->esp + 0x1C8u, 0xAu);
    lift_push32(cpu, (uint32_t)(uintptr_t)"://");
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0xFCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492CC8u); lift_push32(cpu, r); sfera_sub_004903C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0xC4u);
    lift_store8(cpu->esp + 0x1CCu, 0xBu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492CDFu); lift_push32(cpu, r); sfera_sub_004901D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x22u);
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x188u);
    lift_store8(cpu->esp + 0x1CCu, 0xCu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492CF7u); lift_push32(cpu, r); sfera_sub_00490240(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x3Eu);
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x118u);
    lift_store8(cpu->esp + 0x1CCu, 0xDu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492D0Fu); lift_push32(cpu, r); sfera_sub_00490240(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0x150u);
    lift_store8(cpu->esp + 0x1CCu, 0xEu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492D2Au); lift_push32(cpu, r); sfera_sub_004901D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x3Cu);
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0xA8u);
    lift_store8(cpu->esp + 0x1CCu, 0xFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492D42u); lift_push32(cpu, r); sfera_sub_00490240(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x88u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0xE0u);
    lift_store8(cpu->esp + 0x1CCu, 0x10u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492D60u); lift_push32(cpu, r); sfera_sub_004901D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0x3Eu);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->ebp;
    lift_store8(cpu->esp + 0x1CCu, 0x11u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492D73u); lift_push32(cpu, r); sfera_sub_00490240(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0x10u;
    if ((uint32_t)(lift_load32(cpu->esp + 0xF0u)) < (uint32_t)(cpu->edi)) goto label_00092D91;
    cpu->edx = lift_load32(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492D8Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00092D91: cpu->eip = LIFT_CODE_TOKEN_VA(0x492D91u);
    lift_store32(cpu->esp + 0xF0u, cpu->esi);
    lift_store32(cpu->esp + 0xECu, cpu->ebx);
    lift_store8(cpu->esp + 0xDCu, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0xB8u)) < (uint32_t)(cpu->edi)) goto label_00092DBF;
    cpu->eax = lift_load32(cpu->esp + 0xA4u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492DBCu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00092DBF: cpu->eip = LIFT_CODE_TOKEN_VA(0x492DBFu);
    lift_store32(cpu->esp + 0xB8u, cpu->esi);
    lift_store32(cpu->esp + 0xB4u, cpu->ebx);
    lift_store8(cpu->esp + 0xA4u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x160u)) < (uint32_t)(cpu->edi)) goto label_00092DED;
    cpu->ecx = lift_load32(cpu->esp + 0x14Cu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492DEAu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00092DED: cpu->eip = LIFT_CODE_TOKEN_VA(0x492DEDu);
    lift_store32(cpu->esp + 0x160u, cpu->esi);
    lift_store32(cpu->esp + 0x15Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x14Cu, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x128u)) < (uint32_t)(cpu->edi)) goto label_00092E1B;
    cpu->edx = lift_load32(cpu->esp + 0x114u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492E18u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00092E1B: cpu->eip = LIFT_CODE_TOKEN_VA(0x492E1Bu);
    lift_store32(cpu->esp + 0x128u, cpu->esi);
    lift_store32(cpu->esp + 0x124u, cpu->ebx);
    lift_store8(cpu->esp + 0x114u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x198u)) < (uint32_t)(cpu->edi)) goto label_00092E49;
    cpu->eax = lift_load32(cpu->esp + 0x184u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492E46u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00092E49: cpu->eip = LIFT_CODE_TOKEN_VA(0x492E49u);
    lift_store32(cpu->esp + 0x198u, cpu->esi);
    lift_store32(cpu->esp + 0x194u, cpu->ebx);
    lift_store8(cpu->esp + 0x184u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0xD4u)) < (uint32_t)(cpu->edi)) goto label_00092E77;
    cpu->ecx = lift_load32(cpu->esp + 0xC0u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492E74u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00092E77: cpu->eip = LIFT_CODE_TOKEN_VA(0x492E77u);
    lift_store32(cpu->esp + 0xD4u, cpu->esi);
    lift_store32(cpu->esp + 0xD0u, cpu->ebx);
    lift_store8(cpu->esp + 0xC0u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x10Cu)) < (uint32_t)(cpu->edi)) goto label_00092EA5;
    cpu->edx = lift_load32(cpu->esp + 0xF8u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492EA2u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00092EA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x492EA5u);
    lift_store32(cpu->esp + 0x10Cu, cpu->esi);
    lift_store32(cpu->esp + 0x108u, cpu->ebx);
    lift_store8(cpu->esp + 0xF8u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x144u)) < (uint32_t)(cpu->edi)) goto label_00092ED3;
    cpu->eax = lift_load32(cpu->esp + 0x130u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492ED0u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00092ED3: cpu->eip = LIFT_CODE_TOKEN_VA(0x492ED3u);
    lift_store32(cpu->esp + 0x144u, cpu->esi);
    lift_store32(cpu->esp + 0x140u, cpu->ebx);
    lift_store8(cpu->esp + 0x130u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x17Cu)) < (uint32_t)(cpu->edi)) goto label_00092F01;
    cpu->ecx = lift_load32(cpu->esp + 0x168u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492EFEu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00092F01: cpu->eip = LIFT_CODE_TOKEN_VA(0x492F01u);
    lift_store32(cpu->esp + 0x17Cu, cpu->esi);
    lift_store32(cpu->esp + 0x178u, cpu->ebx);
    lift_store8(cpu->esp + 0x168u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x80u)) < (uint32_t)(cpu->edi)) goto label_00092F2C;
    cpu->edx = lift_load32(cpu->esp + 0x6Cu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492F29u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00092F2C: cpu->eip = LIFT_CODE_TOKEN_VA(0x492F2Cu);
    lift_store32(cpu->esp + 0x80u, cpu->esi);
    lift_store32(cpu->esp + 0x7Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x6Cu, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x2Cu)) < (uint32_t)(cpu->edi)) goto label_00092F4E;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492F4Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00092F4E: cpu->eip = LIFT_CODE_TOKEN_VA(0x492F4Eu);
    lift_store32(cpu->esp + 0x2Cu, cpu->esi);
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    lift_store8(cpu->esp + 0x18u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x1B4u)) < (uint32_t)(cpu->edi)) goto label_00092F73;
    cpu->ecx = lift_load32(cpu->esp + 0x1A0u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492F70u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00092F73: cpu->eip = LIFT_CODE_TOKEN_VA(0x492F73u);
    lift_store32(cpu->esp + 0x1B4u, cpu->esi);
    lift_store32(cpu->esp + 0x1B0u, cpu->ebx);
    lift_store8(cpu->esp + 0x1A0u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x48u)) < (uint32_t)(cpu->edi)) goto label_00092F9B;
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492F98u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00092F9B: cpu->eip = LIFT_CODE_TOKEN_VA(0x492F9Bu);
    lift_store32(cpu->esp + 0x48u, cpu->esi);
    lift_store32(cpu->esp + 0x44u, cpu->ebx);
    lift_store8(cpu->esp + 0x34u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x64u)) < (uint32_t)(cpu->edi)) goto label_00092FBA;
    cpu->eax = lift_load32(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492FB7u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00092FBA: cpu->eip = LIFT_CODE_TOKEN_VA(0x492FBAu);
    lift_store32(cpu->esp + 0x64u, cpu->esi);
    lift_store32(cpu->esp + 0x60u, cpu->ebx);
    lift_store8(cpu->esp + 0x50u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x9Cu)) < (uint32_t)(cpu->edi)) goto label_00092FDF;
    cpu->ecx = lift_load32(cpu->esp + 0x88u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x492FDCu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00092FDF: cpu->eip = LIFT_CODE_TOKEN_VA(0x492FDFu);
    lift_store32(cpu->esp + 0x9Cu, cpu->esi);
    lift_store32(cpu->esp + 0x98u, cpu->ebx);
    lift_store8(cpu->esp + 0x88u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x1E4u)) < (uint32_t)(cpu->edi)) goto label_0009300D;
    cpu->edx = lift_load32(cpu->esp + 0x1D0u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49300Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009300D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49300Du);
    lift_store32(cpu->esp + 0x1E4u, cpu->esi);
    lift_store32(cpu->esp + 0x1E0u, cpu->ebx);
    lift_store8(cpu->esp + 0x1D0u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x200u)) < (uint32_t)(cpu->edi)) goto label_0009303B;
    cpu->eax = lift_load32(cpu->esp + 0x1ECu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493038u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009303B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49303Bu);
    lift_store32(cpu->esp + 0x200u, cpu->esi);
    lift_store32(cpu->esp + 0x1FCu, cpu->ebx);
    lift_store8(cpu->esp + 0x1ECu, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x21Cu)) < (uint32_t)(cpu->edi)) goto label_00093069;
    cpu->ecx = lift_load32(cpu->esp + 0x208u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493066u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00093069: cpu->eip = LIFT_CODE_TOKEN_VA(0x493069u);
    cpu->eax = cpu->ebp;
    cpu->ecx = lift_load32(cpu->esp + 0x1C0u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1B8u;
    lift_return(cpu, 84u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004930A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4930A0u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xACu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xC0u);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = cpu->ecx;
    lift_store32(cpu->esp + 0x34u, cpu->edx);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0xC8u, cpu->ebx);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_push32(cpu, 8u);
    lift_store8(cpu->esp + 0xCCu, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4930FDu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000933F7;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = 0u;
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    cpu->edi = 0xFu;
    lift_store32(cpu->esp + 0x7Cu, cpu->edi);
    lift_store32(cpu->esp + 0x78u, cpu->ebx);
    lift_store8(cpu->esp + 0x68u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esp + 0x98u, cpu->edi);
    lift_store32(cpu->esp + 0x94u, cpu->ebx);
    lift_store8(cpu->esp + 0x84u, cpu->ebx & 0xFFu);
    cpu->edx = (uint32_t)(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax;
    cpu->ecx = (uint32_t)(cpu->esp + 0xD4u);
    lift_store8(cpu->esp + 0xCCu, 4u);
    lift_store8(cpu->esp + 0x1Au, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493174u); lift_push32(cpu, r); sfera_sub_00490C50(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00093344;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(1u)) goto label_0009333B;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49319Du); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4931A4u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000931AE;
    lift_flags_logic(cpu,0u,32u); cpu->esi = 0u;
    goto label_000931B0;
    label_000931AE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4931AEu);
    cpu->esi = lift_load32(cpu->ecx);
    label_000931B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4931B0u);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->edx = lift_load32(cpu->esi + 8u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ecx &= 3u;
    if ((uint32_t)(cpu->edx) > (uint32_t)(cpu->eax)) goto label_000931C4;
    cpu->eax -= cpu->edx;
    label_000931C4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4931C4u);
    cpu->edx = lift_load32(cpu->esi + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = lift_load32(cpu->eax);
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4931D5u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(5u)) goto label_0009333B;
    lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4931E9u); lift_push32(cpu, r); sfera_sub_0048EB20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4931F1u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(4u)) goto label_0009333B;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493204u); lift_push32(cpu, r); sfera_sub_0048EB20(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->eax);
    lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493211u); lift_push32(cpu, r); sfera_sub_0048EB20(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49321Au); lift_push32(cpu, r); sfera_sub_00431210(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(2u)) goto label_00093336;
    cpu->ecx = (uint32_t)(cpu->esp + 0xA0u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493232u); lift_push32(cpu, r); sfera_sub_004314D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)": ");
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49323Fu); lift_push32(cpu, r); sfera_sub_00431390(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->ecx = (uint32_t)(cpu->esp + 0xA0u);
    lift_store8(cpu->esp + 0x17u, (((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493252u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(lift_load8(cpu->esp + 0x17u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00093336;
    cpu->esi = 1u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x28u)) <= (uint32_t)(cpu->esi)) goto label_0009329B;
    label_00093270: cpu->eip = LIFT_CODE_TOKEN_VA(0x493270u);
    cpu->edx = 0x377u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49327Fu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->esi);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493289u); lift_push32(cpu, r); sfera_sub_0048EB20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493291u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    ++cpu->esi;
    cpu->esp += 4u;
    if ((uint32_t)(cpu->esi) < (uint32_t)(lift_load32(cpu->esp + 0x28u))) goto label_00093270;
    label_0009329B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49329Bu);
    cpu->edx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4932A9u); lift_push32(cpu, r); sfera_sub_0049F5D0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->esp + 0x3Cu, cpu->esp);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4932B8u); lift_push32(cpu, r); sfera_sub_0048DD80(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x48u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x70u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4932CDu); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4932D4u); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->esp + 0x48u, cpu->esp);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4932E3u); lift_push32(cpu, r); sfera_sub_0048DD80(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x34u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4932F1u); lift_push32(cpu, r); sfera_sub_0048EBC0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x88u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493306u); lift_push32(cpu, r); sfera_sub_00491500(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->ebp) == (uint32_t)(cpu->ebx)) goto label_0009331C;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x8Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x9331Cu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    label_0009331C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49331Cu);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00093331;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x70u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x93331u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    label_00093331: cpu->eip = LIFT_CODE_TOKEN_VA(0x493331u);
    lift_store8(cpu->esp + 0x16u, 1u);
    label_00093336: cpu->eip = LIFT_CODE_TOKEN_VA(0x493336u);
    cpu->edi = 0xFu;
    label_0009333B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49333Bu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x93344u); lift_push32(cpu, r); sfera_sub_0048F5E0(cpu,r); if (cpu->eip != r) return; }
    label_00093344: cpu->eip = LIFT_CODE_TOKEN_VA(0x493344u);
    cpu->esi = 0x10u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x98u)) < (uint32_t)(cpu->esi)) goto label_00093362;
    cpu->eax = lift_load32(cpu->esp + 0x84u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49335Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00093362: cpu->eip = LIFT_CODE_TOKEN_VA(0x493362u);
    lift_store32(cpu->esp + 0x98u, cpu->edi);
    lift_store32(cpu->esp + 0x94u, cpu->ebx);
    lift_store8(cpu->esp + 0x84u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x7Cu)) < (uint32_t)(cpu->esi)) goto label_0009338A;
    cpu->ecx = lift_load32(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493387u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009338A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49338Au);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x7Cu, cpu->edi);
    lift_store32(cpu->esp + 0x78u, cpu->ebx);
    lift_store8(cpu->esp + 0x68u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49339Fu); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4933A9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    if ((uint32_t)(lift_load32(cpu->esp + 0xE4u)) < (uint32_t)(cpu->esi)) goto label_000933C9;
    cpu->eax = lift_load32(cpu->esp + 0xD0u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4933C6u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000933C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4933C9u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esp + 0x16u)) & 0xFFu);
    cpu->ecx = lift_load32(cpu->esp + 0xC0u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xB8u;
    lift_return(cpu, 28u, stop_address); return;
    label_000933F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4933F7u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493421u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x493421u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00493430(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x493430u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xC0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0xD4u);
    (void)0; /* source SEH registration eliminated */
    lift_store32(cpu->esp + 0x34u, cpu->ecx);
    lift_store32(cpu->esp + 0x38u, cpu->edx);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0xDCu, cpu->ebx);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_push32(cpu, 8u);
    lift_store8(cpu->esp + 0xE0u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49348Fu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_000938ED;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = 0u;
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->ecx, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    lift_store32(cpu->esp + 0x28u, cpu->ebx);
    cpu->ebp = 0xFu;
    lift_store32(cpu->esp + 0x90u, cpu->ebp);
    lift_store32(cpu->esp + 0x8Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x7Cu, cpu->ebx & 0xFFu);
    lift_store32(cpu->esp + 0x74u, cpu->ebp);
    lift_store32(cpu->esp + 0x70u, cpu->ebx);
    lift_store8(cpu->esp + 0x60u, cpu->ebx & 0xFFu);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0xECu);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0xA4u);
    lift_store8(cpu->esp + 0xE8u, 4u);
    lift_store32(cpu->esp + 0xB8u, cpu->ebp);
    lift_store32(cpu->esp + 0xB4u, cpu->ebx);
    lift_store8(cpu->esp + 0xA4u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493518u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = (uint32_t)(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x9Cu);
    lift_store8(cpu->esp + 0xE0u, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493535u); lift_push32(cpu, r); sfera_sub_00490C50(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0x10u;
    lift_store8(cpu->esp + 0xDCu, 4u);
    if ((uint32_t)(lift_load32(cpu->esp + 0xACu)) < (uint32_t)(cpu->edi)) goto label_0009355B;
    cpu->ecx = lift_load32(cpu->esp + 0x98u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493558u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009355B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49355Bu);
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_0009386C;
    if ((uint32_t)(cpu->eax) <= (uint32_t)(1u)) goto label_0009377B;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = (uint32_t)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493584u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49358Bu); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    { uint64_t l=(uint64_t)(cpu->ecx), r=(uint64_t)(cpu->ebx), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00093595;
    lift_flags_logic(cpu,0u,32u); cpu->edx = 0u;
    goto label_00093597;
    label_00093595: cpu->eip = LIFT_CODE_TOKEN_VA(0x493595u);
    cpu->edx = lift_load32(cpu->ecx);
    label_00093597: cpu->eip = LIFT_CODE_TOKEN_VA(0x493597u);
    cpu->ecx = lift_load32(cpu->eax + 8u);
    cpu->esi = lift_load32(cpu->edx + 8u);
    cpu->eax = cpu->ecx;
    cpu->eax = lift_shift_right(cpu, cpu->eax, (uint32_t)(2u), 32u);
    cpu->ecx &= 3u;
    if ((uint32_t)(cpu->esi) > (uint32_t)(cpu->eax)) goto label_000935AB;
    cpu->eax -= cpu->esi;
    label_000935AB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4935ABu);
    cpu->edx = lift_load32(cpu->edx + 4u);
    cpu->eax = lift_load32(cpu->edx + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = (uint32_t)(cpu->eax + ((uint32_t)(cpu->ecx) * 4u));
    cpu->ecx = lift_load32(cpu->eax);
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4935BCu);
    if ((uint32_t)(cpu->eax) != (uint32_t)(5u)) goto label_0009377B;
    lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4935D0u); lift_push32(cpu, r); sfera_sub_0048EB20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->eax);
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4935D8u);
    if ((uint32_t)(cpu->eax) != (uint32_t)(4u)) goto label_0009377B;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4935EBu); lift_push32(cpu, r); sfera_sub_0048EB20(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = lift_load32(cpu->eax);
    lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4935F8u); lift_push32(cpu, r); sfera_sub_0048EB20(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = lift_load32(cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493601u); lift_push32(cpu, r); sfera_sub_00431210(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != (uint32_t)(2u)) goto label_00093776;
    cpu->ecx = (uint32_t)(cpu->esp + 0x98u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493619u); lift_push32(cpu, r); sfera_sub_004314D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)": ");
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493626u); lift_push32(cpu, r); sfera_sub_00431390(cpu,r); if (cpu->eip != r) return; }
    { uint64_t v=(uint64_t)(cpu->eax); lift_flags_logic(cpu,v,32u); }
    cpu->ecx = (uint32_t)(cpu->esp + 0x98u);
    lift_store8(cpu->esp + 0x17u, (((cpu->eflags & LIFT_FLAG_ZF) != 0u)) ? 1u : 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493639u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(lift_load8(cpu->esp + 0x17u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00093776;
    cpu->edx = (uint32_t)(cpu->esp + 0x98u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493652u); lift_push32(cpu, r); sfera_sub_004314D0(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->eax + 0x10u)), r=(uint64_t)(2u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    cpu->ecx = (uint32_t)(cpu->esp + 0x98u);
    lift_store8(cpu->esp + 0x17u, (((cpu->eflags & (LIFT_FLAG_CF | LIFT_FLAG_ZF)) == 0u)) ? 1u : 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493667u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    if ((uint8_t)(lift_load8(cpu->esp + 0x17u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000936C9;
    cpu->eax = (uint32_t)(cpu->esp + 0xB4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49367Cu); lift_push32(cpu, r); sfera_sub_004314D0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 2u);
    cpu->ecx = (uint32_t)(cpu->esp + 0xA0u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_store8(cpu->esp + 0xE8u, 6u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493697u); lift_push32(cpu, r); sfera_sub_00431640(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->esp + 0xE0u, 7u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4936A7u); lift_push32(cpu, r); sfera_sub_004317E0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0x98u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4936B3u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = (uint32_t)(cpu->esp + 0xB4u);
    lift_store8(cpu->esp + 0xDCu, 4u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4936C7u); lift_push32(cpu, r); sfera_sub_004061B0(cpu,r); if (cpu->eip != r) return; }
    goto label_00093727;
    label_000936C9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4936C9u);
    cpu->edx = 0x39Fu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4936D8u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, 1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4936E3u); lift_push32(cpu, r); sfera_sub_0048EB20(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4936EBu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, 1u);
    cpu->eax = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x24u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493703u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49370Au); lift_push32(cpu, r); sfera_sub_004A8C50(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->esp + 0x3Cu, cpu->esp);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493719u); lift_push32(cpu, r); sfera_sub_0048DD80(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x93727u); lift_push32(cpu, r); sfera_sub_0048F090(cpu,r); if (cpu->eip != r) return; }
    label_00093727: cpu->eip = LIFT_CODE_TOKEN_VA(0x493727u);
    cpu->edx = 0x3A2u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493736u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493740u); lift_push32(cpu, r); sfera_sub_0048EB20(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->eax);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493748u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    cpu->ecx = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493759u); lift_push32(cpu, r); sfera_sub_004A8E20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    lift_store32(cpu->esp + 0x3Cu, cpu->esp);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493768u); lift_push32(cpu, r); sfera_sub_0048DD80(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x28u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x93776u); lift_push32(cpu, r); sfera_sub_0048F090(cpu,r); if (cpu->eip != r) return; }
    label_00093776: cpu->eip = LIFT_CODE_TOKEN_VA(0x493776u);
    cpu->edi = 0x10u;
    label_0009377B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49377Bu);
    cpu->eax = (uint32_t)(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->eax);
    cpu->edx = (uint32_t)(cpu->esp + 0x80u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x1Cu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493790u); lift_push32(cpu, r); sfera_sub_00491500(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x38u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000937A5;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x937A5u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    label_000937A5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4937A5u);
    cpu->ecx = lift_load32(cpu->esp + 0x34u);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_000937BD;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0x84u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x937BDu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    label_000937BD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4937BDu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4937C6u); lift_push32(cpu, r); sfera_sub_0048F5E0(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(lift_load32(cpu->esp + 0x74u)) < (uint32_t)(cpu->edi)) goto label_000937D9;
    cpu->ecx = lift_load32(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4937D6u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000937D9: cpu->eip = LIFT_CODE_TOKEN_VA(0x4937D9u);
    lift_store32(cpu->esp + 0x74u, cpu->ebp);
    lift_store32(cpu->esp + 0x70u, cpu->ebx);
    lift_store8(cpu->esp + 0x60u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x90u)) < (uint32_t)(cpu->edi)) goto label_000937FB;
    cpu->edx = lift_load32(cpu->esp + 0x7Cu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4937F8u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000937FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4937FBu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x90u, cpu->ebp);
    lift_store32(cpu->esp + 0x8Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x7Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493816u); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493820u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    if ((uint32_t)(lift_load32(cpu->esp + 0xF8u)) < (uint32_t)(cpu->edi)) goto label_00093840;
    cpu->ecx = lift_load32(cpu->esp + 0xE4u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49383Du); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00093840: cpu->eip = LIFT_CODE_TOKEN_VA(0x493840u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    label_00093842: cpu->eip = LIFT_CODE_TOKEN_VA(0x493842u);
    cpu->ecx = lift_load32(cpu->esp + 0xD4u);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCCu;
    lift_return(cpu, 28u, stop_address); return;
    label_0009386C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49386Cu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x74u)) < (uint32_t)(cpu->edi)) goto label_0009387F;
    cpu->edx = lift_load32(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49387Cu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_0009387F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49387Fu);
    lift_store32(cpu->esp + 0x74u, cpu->ebp);
    lift_store32(cpu->esp + 0x70u, cpu->ebx);
    lift_store8(cpu->esp + 0x60u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x90u)) < (uint32_t)(cpu->edi)) goto label_000938A1;
    cpu->eax = lift_load32(cpu->esp + 0x7Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49389Eu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000938A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4938A1u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    lift_store32(cpu->esp + 0x90u, cpu->ebp);
    lift_store32(cpu->esp + 0x8Cu, cpu->ebx);
    lift_store8(cpu->esp + 0x7Cu, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4938BCu); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4938C6u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    if ((uint32_t)(lift_load32(cpu->esp + 0xF8u)) < (uint32_t)(cpu->edi)) goto label_000938E6;
    cpu->edx = lift_load32(cpu->esp + 0xE4u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4938E3u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_000938E6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4938E6u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    goto label_00093842;
    label_000938ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4938EDu);
    cpu->eax = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493917u); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x493917u, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00493920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x493920u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x88u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = (uint32_t)(cpu->esp + 0x9Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ebp = cpu->edx;
    lift_store32(cpu->esp + 0x34u, cpu->ecx);
    cpu->eax = lift_load32(cpu->esp + 0xCCu);
    cpu->edi = lift_load32(cpu->esp + 0xC8u);
    lift_store32(cpu->esp + 0x2Cu, cpu->eax);
    cpu->ebx = 0u;
    lift_store32(cpu->esp + 0xA4u, cpu->ebx);
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    lift_push32(cpu, 8u);
    lift_store8(cpu->esp + 0xA8u, 1u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49398Fu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ebx)) goto label_00093BC2;
    lift_store32(cpu->esp + 0x14u, cpu->eax);
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    cpu->edx = 0u;
    lift_store32(cpu->eax + 4u, cpu->edx);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->edx, cpu->ecx);
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    lift_store32(cpu->esp + 0x1Cu, cpu->ebx);
    lift_store32(cpu->esp + 0x20u, cpu->ebx);
    lift_store32(cpu->esp + 0x24u, cpu->ebx);
    cpu->esi = 0xFu;
    lift_store32(cpu->esp + 0x58u, cpu->esi);
    lift_store32(cpu->esp + 0x54u, cpu->ebx);
    lift_store8(cpu->esp + 0x44u, cpu->ebx & 0xFFu);
    lift_store32(cpu->esp + 0x74u, cpu->esi);
    lift_store32(cpu->esp + 0x70u, cpu->ebx);
    lift_store8(cpu->esp + 0x60u, cpu->ebx & 0xFFu);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0xB4u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->esp + 0x88u);
    lift_store8(cpu->esp + 0xB0u, 4u);
    lift_store32(cpu->esp + 0x9Cu, cpu->esi);
    lift_store32(cpu->esp + 0x98u, cpu->ebx);
    lift_store8(cpu->esp + 0x88u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493A12u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x18u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x80u);
    lift_store8(cpu->esp + 0xA8u, 5u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493A2Bu); lift_push32(cpu, r); sfera_sub_00490C50(cpu,r); if (cpu->eip != r) return; }
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x90u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store8(cpu->esp + 0xA4u, 4u);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00093A4A;
    cpu->ecx = lift_load32(cpu->esp + 0x7Cu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493A47u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00093A4A: cpu->eip = LIFT_CODE_TOKEN_VA(0x493A4Au);
    if ((uint32_t)(lift_load32(cpu->esp + 0x24u)) == (uint32_t)(cpu->ebx)) goto label_00093B47;
    cpu->edx = lift_load32(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493A62u); lift_push32(cpu, r); sfera_sub_004927C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->edx);
    cpu->edx = (uint32_t)(cpu->esp + 0x48u);
    cpu->ecx = (uint32_t)(cpu->esp + 0x18u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493A74u); lift_push32(cpu, r); sfera_sub_00491500(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->ebx)) goto label_00093A87;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x93A87u); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    label_00093A87: cpu->eip = LIFT_CODE_TOKEN_VA(0x493A87u);
    cpu->ecx = lift_load32(cpu->esp + 0x2Cu);
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->ebx)) goto label_00093A9C;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->edx = (uint32_t)(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x93A9Cu); lift_push32(cpu, r); sfera_sub_00405210(cpu,r); if (cpu->eip != r) return; }
    label_00093A9C: cpu->eip = LIFT_CODE_TOKEN_VA(0x493A9Cu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493AA5u); lift_push32(cpu, r); sfera_sub_0048F5E0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = 0x10u;
    if ((uint32_t)(lift_load32(cpu->esp + 0x74u)) < (uint32_t)(cpu->edi)) goto label_00093ABD;
    cpu->eax = lift_load32(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493ABAu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00093ABD: cpu->eip = LIFT_CODE_TOKEN_VA(0x493ABDu);
    lift_store32(cpu->esp + 0x74u, cpu->esi);
    lift_store32(cpu->esp + 0x70u, cpu->ebx);
    lift_store8(cpu->esp + 0x60u, cpu->ebx & 0xFFu);
    if ((uint32_t)(lift_load32(cpu->esp + 0x58u)) < (uint32_t)(cpu->edi)) goto label_00093ADC;
    cpu->ecx = lift_load32(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493AD9u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00093ADC: cpu->eip = LIFT_CODE_TOKEN_VA(0x493ADCu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x58u, cpu->esi);
    lift_store32(cpu->esp + 0x54u, cpu->ebx);
    lift_store8(cpu->esp + 0x44u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493AF1u); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493AFBu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((uint32_t)(lift_load32(cpu->esp + 0xC0u)) < (uint32_t)(cpu->edi)) goto label_00093B1B;
    cpu->eax = lift_load32(cpu->esp + 0xACu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493B18u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00093B1B: cpu->eip = LIFT_CODE_TOKEN_VA(0x493B1Bu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(1u) & 0xFFu);
    label_00093B1D: cpu->eip = LIFT_CODE_TOKEN_VA(0x493B1Du);
    cpu->ecx = lift_load32(cpu->esp + 0x9Cu);
    (void)0; /* source SEH registration eliminated */
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x94u;
    lift_return(cpu, 36u, stop_address); return;
    label_00093B47: cpu->eip = LIFT_CODE_TOKEN_VA(0x493B47u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x74u)) < (uint32_t)(0x10u)) goto label_00093B5B;
    cpu->ecx = lift_load32(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493B58u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00093B5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x493B5Bu);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x58u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x74u, cpu->esi);
    lift_store32(cpu->esp + 0x70u, cpu->ebx);
    lift_store8(cpu->esp + 0x60u, cpu->ebx & 0xFFu);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00093B7B;
    cpu->edx = lift_load32(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493B78u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00093B7B: cpu->eip = LIFT_CODE_TOKEN_VA(0x493B7Bu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x14u);
    lift_store32(cpu->esp + 0x58u, cpu->esi);
    lift_store32(cpu->esp + 0x54u, cpu->ebx);
    lift_store8(cpu->esp + 0x44u, cpu->ebx & 0xFFu);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493B90u); lift_push32(cpu, r); sfera_sub_0049FA40(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493B9Au); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0xC0u)), r=(uint64_t)(0x10u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esp + 0x14u, cpu->ebx);
    if ((cpu->eflags & LIFT_FLAG_CF) != 0u) goto label_00093BBB;
    cpu->ecx = lift_load32(cpu->esp + 0xACu);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493BB8u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00093BBB: cpu->eip = LIFT_CODE_TOKEN_VA(0x493BBBu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    goto label_00093B1D;
    label_00093BC2: cpu->eip = LIFT_CODE_TOKEN_VA(0x493BC2u);
    cpu->edx = (uint32_t)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = (uint32_t)(cpu->esp + 0x3Cu);
    lift_store32(cpu->esp + 0x34u, cpu->ebx);
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = (uint32_t)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493BECu); lift_push32(cpu, r); sfera_sub_004EE92A(cpu,r); if (cpu->eip != r) return; }
    lift_trap(cpu, 0x493BECu, "INT3"); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00493BF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x493BF0u);
    cpu->eax = cpu->ecx;
    cpu->ecx = 0u;
    lift_store32(cpu->eax, cpu->ecx);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_store32(cpu->eax + 8u, cpu->ecx);
    lift_store32(cpu->eax + 0xCu, cpu->ecx);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00493C00(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x493C00u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    if ((uint32_t)(lift_load32(cpu->esi)) == (uint32_t)(cpu->edi)) goto label_00093C22;
    cpu->edx = (uint32_t)(cpu->edi + 0x4Cu);
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SimpleParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493C17u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493C1Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00093C22: cpu->eip = LIFT_CODE_TOKEN_VA(0x493C22u);
    lift_store32(cpu->esi, cpu->edi);
    lift_store32(cpu->esi + 4u, cpu->edi);
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) == (uint32_t)(cpu->edi)) goto label_00093C47;
    cpu->edx = 0x51u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SimpleParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493C3Bu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493C44u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00093C47: cpu->eip = LIFT_CODE_TOKEN_VA(0x493C47u);
    lift_store32(cpu->esi + 0xCu, cpu->edi);
    lift_store32(cpu->esi + 8u, cpu->edi);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00493C50(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x493C50u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    if ((uint32_t)(lift_load32(cpu->esi)) == (uint32_t)(cpu->ebx)) goto label_00093D1B;
    if ((uint32_t)(lift_load32(cpu->esi + 8u)) == (uint32_t)(cpu->ebx)) goto label_00093C7E;
    cpu->edx = 0x88u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SimpleParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493C72u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493C7Bu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00093C7E: cpu->eip = LIFT_CODE_TOKEN_VA(0x493C7Eu);
    cpu->eax = lift_load32(cpu->esi);
    lift_store32(cpu->esi + 8u, cpu->ebx);
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00093C9E;
    label_00093C90: cpu->eip = LIFT_CODE_TOKEN_VA(0x493C90u);
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0xDu)) goto label_00093C98;
    lift_store32(cpu->esi + 0xCu, (uint64_t)(lift_load32(cpu->esi + 0xCu)) + 1u);
    label_00093C98: cpu->eip = LIFT_CODE_TOKEN_VA(0x493C98u);
    ++cpu->eax;
    if ((uint32_t)(cpu->eax) < (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00093C90;
    label_00093C9E: cpu->eip = LIFT_CODE_TOKEN_VA(0x493C9Eu);
    lift_store32(cpu->esi + 0xCu, (uint64_t)(lift_load32(cpu->esi + 0xCu)) + 1u);
    cpu->edx = 0x93u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SimpleParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493CB0u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    cpu->ecx = 0u;
    { uint64_t l=(uint64_t)(cpu->eax), v=l + 1u; uint32_t cf=cpu->eflags & LIFT_FLAG_CF; lift_flags_add(cpu,l,1u,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | cf; cpu->eax = v; }
    cpu->edx = 4u;
    lift_multiply_accumulator(cpu, cpu->edx, 32u, 0u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)((((cpu->eflags & LIFT_FLAG_OF) != 0u)) ? 1u : 0u) & 0xFFu);
    cpu->ecx = 0u - (uint64_t)(cpu->ecx);
    cpu->ecx |= cpu->eax;
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493CCAu); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_store32(cpu->esi + 8u, cpu->eax);
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ebx)) goto label_00093CDA;
    lift_store32(cpu->esi + 0xCu, cpu->ebx);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00093CDA: cpu->eip = LIFT_CODE_TOKEN_VA(0x493CDAu);
    cpu->ecx = lift_load32(cpu->esi);
    lift_store32(cpu->eax, cpu->ecx);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00093D00;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->ebp);
    label_00093CE6: cpu->eip = LIFT_CODE_TOKEN_VA(0x493CE6u);
    if ((uint8_t)(lift_load8(cpu->ecx)) != (uint8_t)(0xDu)) goto label_00093CF9;
    cpu->ebp = lift_load32(cpu->esi + 8u);
    cpu->eax += 4u;
    cpu->edx = (uint32_t)(cpu->ecx + 2u);
    lift_store32(cpu->eax + cpu->ebp, cpu->edx);
    lift_store8(cpu->ecx, cpu->ebx & 0xFFu);
    label_00093CF9: cpu->eip = LIFT_CODE_TOKEN_VA(0x493CF9u);
    ++cpu->ecx;
    if ((uint32_t)(cpu->ecx) < (uint32_t)(lift_load32(cpu->esi + 4u))) goto label_00093CE6;
    cpu->ebp = lift_pop32(cpu);
    label_00093D00: cpu->eip = LIFT_CODE_TOKEN_VA(0x493D00u);
    cpu->eax = lift_load32(cpu->esi + 0xCu);
    lift_store32(cpu->esi + 0x418u, cpu->ebx);
    lift_store32(cpu->esi + 0x41Cu, cpu->eax);
    lift_store32(cpu->esi + 0x410u, cpu->ebx);
    lift_store32(cpu->esi + 0x414u, cpu->eax);
    label_00093D1B: cpu->eip = LIFT_CODE_TOKEN_VA(0x493D1Bu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00493D20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x493D20u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00093D66;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx + 1u);
    cpu->edi = cpu->edi;
    label_00093D30: cpu->eip = LIFT_CODE_TOKEN_VA(0x493D30u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00093D30;
    cpu->ecx -= cpu->esi;
    cpu->ecx += cpu->eax;
    cpu->esi = lift_pop32(cpu);
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_00093D66;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(0x2Fu)) goto label_00093D4C;
    if ((uint8_t)(lift_load8(cpu->eax + 1u)) == (uint8_t)((cpu->edx & 0xFFu))) goto label_00093D66;
    label_00093D4C: cpu->eip = LIFT_CODE_TOKEN_VA(0x493D4Cu);
    if ((int8_t)(uint8_t)((cpu->edx & 0xFFu)) > (int8_t)(uint8_t)(0x20u)) goto label_00093D5B;
    label_00093D51: cpu->eip = LIFT_CODE_TOKEN_VA(0x493D51u);
    ++cpu->eax;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_00093D66;
    if ((int8_t)(uint8_t)(lift_load8(cpu->eax)) <= (int8_t)(uint8_t)(0x20u)) goto label_00093D51;
    label_00093D5B: cpu->eip = LIFT_CODE_TOKEN_VA(0x493D5Bu);
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x2Fu)) goto label_00093D68;
    if ((uint8_t)(lift_load8(cpu->eax + 1u)) != (uint8_t)(0x2Fu)) goto label_00093D68;
    label_00093D66: cpu->eip = LIFT_CODE_TOKEN_VA(0x493D66u);
    cpu->eax = 0u;
    label_00093D68: cpu->eip = LIFT_CODE_TOKEN_VA(0x493D68u);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00493D70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x493D70u);
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ecx;
    cpu->ecx = lift_load32(cpu->edx + 8u);
    lift_store32(cpu->esp, cpu->edx);
    if ((uint32_t)(cpu->ecx) != 0u) goto label_00093D84;
    label_00093D7D: cpu->eip = LIFT_CODE_TOKEN_VA(0x493D7Du);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00093D84: cpu->eip = LIFT_CODE_TOKEN_VA(0x493D84u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0xCu))) goto label_00093D7D;
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(lift_load32(cpu->edx + 0xCu))) goto label_00093D7D;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 1u;
    cpu->ebx = cpu->eax;
    cpu->ebp = (uint32_t)(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    goto label_00093DA7;
    label_00093DA3: cpu->eip = LIFT_CODE_TOKEN_VA(0x493DA3u);
    cpu->edx = lift_load32(cpu->esp + 0x10u);
    label_00093DA7: cpu->eip = LIFT_CODE_TOKEN_VA(0x493DA7u);
    cpu->eax = lift_load32(cpu->ebp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edx;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493DB2u); lift_push32(cpu, r); sfera_sub_00493D20(cpu,r); if (cpu->eip != r) return; }
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->esi) == 0u) goto label_00093DF0;
    cpu->ecx = cpu->esi;
    cpu->edx = (uint32_t)(cpu->ecx + 1u);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00093DC0: cpu->eip = LIFT_CODE_TOKEN_VA(0x493DC0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->eax & 0xFFu)) != 0u) goto label_00093DC0;
    cpu->ecx -= cpu->edx;
    cpu->edx = 0u;
    if ((int32_t)(uint32_t)(cpu->ecx) <= 0) goto label_00093DF0;
    (void)cpu;
    label_00093DD0: cpu->eip = LIFT_CODE_TOKEN_VA(0x493DD0u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx + cpu->esi)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x2Fu)) goto label_00093DDD;
    if ((uint8_t)(lift_load8(cpu->edx + cpu->esi + 1u)) == (uint8_t)((cpu->eax & 0xFFu))) goto label_00093DF0;
    label_00093DDD: cpu->eip = LIFT_CODE_TOKEN_VA(0x493DDDu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x7Bu)) goto label_00093DE2;
    ++cpu->edi;
    label_00093DE2: cpu->eip = LIFT_CODE_TOKEN_VA(0x493DE2u);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x7Du)) goto label_00093DE7;
    --cpu->edi;
    label_00093DE7: cpu->eip = LIFT_CODE_TOKEN_VA(0x493DE7u);
    if ((uint32_t)(cpu->edi) == 0u) goto label_00093E05;
    ++cpu->edx;
    if ((int32_t)(uint32_t)(cpu->edx) < (int32_t)(uint32_t)(cpu->ecx)) goto label_00093DD0;
    label_00093DF0: cpu->eip = LIFT_CODE_TOKEN_VA(0x493DF0u);
    ++cpu->ebx;
    cpu->ebp += 4u;
    if ((int32_t)(uint32_t)(cpu->ebx) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x1Cu))) goto label_00093DA3;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00093E05: cpu->eip = LIFT_CODE_TOKEN_VA(0x493E05u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00493E10(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x493E10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->ebp = cpu->ecx;
    lift_store32(cpu->esp + 8u, cpu->ebp);
    if ((uint32_t)(cpu->edi) != 0u) goto label_00093E2A;
    label_00093E21: cpu->eip = LIFT_CODE_TOKEN_VA(0x493E21u);
    cpu->edi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_00093E2A: cpu->eip = LIFT_CODE_TOKEN_VA(0x493E2Au);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 0x18u)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_00093E37;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    label_00093E37: cpu->eip = LIFT_CODE_TOKEN_VA(0x493E37u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x18u))) goto label_00093E21;
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->edi;
    cpu->edx = cpu->edi;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_00093E50: cpu->eip = LIFT_CODE_TOKEN_VA(0x493E50u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != 0u) goto label_00093E50;
    cpu->eax -= cpu->esi;
    cpu->esi = (uint32_t)(cpu->eax + cpu->edi);
    if ((uint32_t)(cpu->edi) == (uint32_t)(cpu->esi)) goto label_00093F2D;
    cpu->eax = (uint32_t)(cpu->ebp + 0x10u);
    cpu->ebp += 0x410u;
    if ((uint32_t)(cpu->edi) >= (uint32_t)(cpu->esi)) goto label_00093E88;
    label_00093E71: cpu->eip = LIFT_CODE_TOKEN_VA(0x493E71u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    if ((int8_t)(uint8_t)((cpu->ebx & 0xFFu)) <= (int8_t)(uint8_t)(0x20u)) goto label_00093E88;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ebp)) goto label_00093F2D;
    lift_store8(cpu->eax, cpu->ebx & 0xFFu);
    ++cpu->edx;
    ++cpu->eax;
    if ((uint32_t)(cpu->edx) < (uint32_t)(cpu->esi)) goto label_00093E71;
    label_00093E88: cpu->eip = LIFT_CODE_TOKEN_VA(0x493E88u);
    lift_store8(cpu->eax, 0u);
    cpu->eax = cpu->edx;
    cpu->edi = cpu->ecx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_00093E92: cpu->eip = LIFT_CODE_TOKEN_VA(0x493E92u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != 0u) goto label_00093E92;
    cpu->eax -= cpu->esi;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00093EB4;
    cpu->esi = 0u;
    if ((int32_t)(uint32_t)(cpu->eax) <= 0) goto label_00093EB4;
    label_00093EA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x493EA5u);
    if ((uint8_t)(lift_load8(cpu->esi + cpu->edx)) == (uint8_t)(0x7Bu)) goto label_00093F38;
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->eax)) goto label_00093EA5;
    label_00093EB4: cpu->eip = LIFT_CODE_TOKEN_VA(0x493EB4u);
    cpu->edi = (uint32_t)(cpu->ecx + 1u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    if ((int32_t)(uint32_t)(cpu->edi) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_00093F2D;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edx = lift_load32(cpu->eax + 8u);
    cpu->ebp = (uint32_t)(cpu->edx + ((uint32_t)(cpu->edi) * 4u));
    cpu->esp = (uint32_t)(cpu->esp);
    label_00093ED0: cpu->eip = LIFT_CODE_TOKEN_VA(0x493ED0u);
    cpu->eax = lift_load32(cpu->ebp);
    if ((uint32_t)(cpu->eax) == 0u) goto label_00093F15;
    cpu->edx = cpu->eax;
    cpu->esi = (uint32_t)(cpu->edx + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00093EE0: cpu->eip = LIFT_CODE_TOKEN_VA(0x493EE0u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->edx)) & 0xFFu);
    ++cpu->edx;
    if ((uint8_t)((cpu->ebx & 0xFFu)) != 0u) goto label_00093EE0;
    cpu->edx -= cpu->esi;
    cpu->edx += cpu->eax;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->edx)) goto label_00093F15;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    if ((uint8_t)((cpu->ebx & 0xFFu)) != (uint8_t)(0x2Fu)) goto label_00093EFB;
    if ((uint8_t)(lift_load8(cpu->eax + 1u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00093F15;
    label_00093EFB: cpu->eip = LIFT_CODE_TOKEN_VA(0x493EFBu);
    if ((int8_t)(uint8_t)((cpu->ebx & 0xFFu)) > (int8_t)(uint8_t)(0x20u)) goto label_00093F0A;
    label_00093F00: cpu->eip = LIFT_CODE_TOKEN_VA(0x493F00u);
    ++cpu->eax;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->edx)) goto label_00093F15;
    if ((int8_t)(uint8_t)(lift_load8(cpu->eax)) <= (int8_t)(uint8_t)(0x20u)) goto label_00093F00;
    label_00093F0A: cpu->eip = LIFT_CODE_TOKEN_VA(0x493F0Au);
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x2Fu)) goto label_00093F28;
    if ((uint8_t)(lift_load8(cpu->eax + 1u)) != (uint8_t)(0x2Fu)) goto label_00093F28;
    label_00093F15: cpu->eip = LIFT_CODE_TOKEN_VA(0x493F15u);
    ++cpu->edi;
    cpu->ebp += 4u;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->ecx)) goto label_00093ED0;
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_00093F28: cpu->eip = LIFT_CODE_TOKEN_VA(0x493F28u);
    if ((uint8_t)(lift_load8(cpu->eax)) == (uint8_t)(0x7Bu)) goto label_00093F3C;
    label_00093F2D: cpu->eip = LIFT_CODE_TOKEN_VA(0x493F2Du);
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_00093F38: cpu->eip = LIFT_CODE_TOKEN_VA(0x493F38u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    label_00093F3C: cpu->eip = LIFT_CODE_TOKEN_VA(0x493F3Cu);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->esi = (uint32_t)(cpu->edi + 1u);
    lift_push32(cpu, cpu->esi);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493F4Au); lift_push32(cpu, r); sfera_sub_00493D70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00093F2D;
    cpu->ecx = lift_load32(cpu->esp + 0x24u);
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00093F5F;
    cpu->edx = (uint32_t)(cpu->eax + 1u);
    lift_store32(cpu->ecx, cpu->esi);
    lift_store32(cpu->ecx + 4u, cpu->edx);
    label_00093F5F: cpu->eip = LIFT_CODE_TOKEN_VA(0x493F5Fu);
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax -= cpu->edi;
    cpu->edi = lift_pop32(cpu);
    ++cpu->eax;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00493F70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x493F70u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = lift_load32(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if ((uint32_t)(cpu->ebp) != 0u) goto label_00093F83;
    label_00093F7C: cpu->eip = LIFT_CODE_TOKEN_VA(0x493F7Cu);
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_00093F83: cpu->eip = LIFT_CODE_TOKEN_VA(0x493F83u);
    if ((uint32_t)(lift_load32(cpu->edi + 8u)) == (uint32_t)(0u)) goto label_00093F7C;
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->edi + 0xCu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    cpu->ebx = cpu->eax;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_00093FAB;
    cpu->ebx = lift_load32(cpu->ecx + 4u);
    cpu->esi = lift_load32(cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(cpu->eax)) goto label_00093FA5;
    cpu->ebx = cpu->eax;
    label_00093FA5: cpu->eip = LIFT_CODE_TOKEN_VA(0x493FA5u);
    if ((int32_t)(uint32_t)(cpu->esi) >= 0) goto label_00093FAB;
    cpu->esi = 0u;
    label_00093FAB: cpu->eip = LIFT_CODE_TOKEN_VA(0x493FABu);
    if ((int32_t)(uint32_t)(cpu->esi) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_0009400F;
    lift_store32(cpu->esp + 0x18u, 0u);
    label_00093FB7: cpu->eip = LIFT_CODE_TOKEN_VA(0x493FB7u);
    cpu->eax = lift_load32(cpu->edi + 8u);
    cpu->ecx = lift_load32(cpu->eax + ((uint32_t)(cpu->esi) * 4u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493FC5u); lift_push32(cpu, r); sfera_sub_00493D20(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009400A;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x493FD4u); lift_push32(cpu, r); sfera_sub_00493E10(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_0009400A;
    cpu->edx = lift_load32(cpu->ebp);
    if ((uint32_t)(cpu->edx) == (uint32_t)(lift_load32(cpu->ebp + 4u))) goto label_0009400A;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->edi + 0x10u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x493FEAu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x493FF0u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_00094006;
    cpu->eax = lift_load32(cpu->esp + 0x18u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(lift_load32(cpu->esp + 0x20u))) goto label_00094018;
    label_00094006: cpu->eip = LIFT_CODE_TOKEN_VA(0x494006u);
    cpu->esi = lift_load32(cpu->ebp + 4u);
    --cpu->esi;
    label_0009400A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49400Au);
    ++cpu->esi;
    if ((int32_t)(uint32_t)(cpu->esi) < (int32_t)(uint32_t)(cpu->ebx)) goto label_00093FB7;
    label_0009400F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49400Fu);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
    label_00094018: cpu->eip = LIFT_CODE_TOKEN_VA(0x494018u);
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu); lift_return(cpu, 16u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00494030(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x494030u);
    cpu->eax = lift_load32(cpu->esp + 8u);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009404C;
    cpu->ebx = lift_load32(cpu->ebp + 0xCu);
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 0x18u, cpu->ebx);
    goto label_00094057;
    label_0009404C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49404Cu);
    cpu->ecx = lift_load32(cpu->eax);
    cpu->eax = lift_load32(cpu->eax + 4u);
    lift_store32(cpu->esp + 0x18u, cpu->eax);
    cpu->ebx = cpu->eax;
    label_00094057: cpu->eip = LIFT_CODE_TOKEN_VA(0x494057u);
    lift_store32(cpu->esp + 0x2Cu, 0u);
    (void)cpu;
    label_00094060: cpu->eip = LIFT_CODE_TOKEN_VA(0x494060u);
    if ((uint32_t)(lift_load32(cpu->ebp + 8u)) == (uint32_t)(0u)) goto label_00094126;
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    if ((int32_t)(uint32_t)(cpu->ebx) <= (int32_t)(uint32_t)(cpu->eax)) goto label_00094073;
    cpu->ebx = cpu->eax;
    label_00094073: cpu->eip = LIFT_CODE_TOKEN_VA(0x494073u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= 0) goto label_00094079;
    cpu->ecx = 0u;
    label_00094079: cpu->eip = LIFT_CODE_TOKEN_VA(0x494079u);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(cpu->ebx)) goto label_00094126;
    lift_store32(cpu->esp + 0x10u, 0u);
    cpu->edi = cpu->ecx;
    label_00094090: cpu->eip = LIFT_CODE_TOKEN_VA(0x494090u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->eax = lift_load32(cpu->ecx + ((uint32_t)(cpu->edi) * 4u));
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009411D;
    cpu->ecx = cpu->eax;
    cpu->esi = (uint32_t)(cpu->ecx + 1u);
    label_000940A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4940A3u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000940A3;
    cpu->ecx -= cpu->esi;
    cpu->ecx += cpu->eax;
    if ((uint32_t)(cpu->eax) == (uint32_t)(cpu->ecx)) goto label_0009411D;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(0x2Fu)) goto label_000940BE;
    if ((uint8_t)(lift_load8(cpu->eax + 1u)) == (uint8_t)((cpu->edx & 0xFFu))) goto label_0009411D;
    label_000940BE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4940BEu);
    if ((int8_t)(uint8_t)((cpu->edx & 0xFFu)) > (int8_t)(uint8_t)(0x20u)) goto label_000940CD;
    label_000940C3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4940C3u);
    ++cpu->eax;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_0009411D;
    if ((int8_t)(uint8_t)(lift_load8(cpu->eax)) <= (int8_t)(uint8_t)(0x20u)) goto label_000940C3;
    label_000940CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4940CDu);
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)(0x2Fu)) goto label_000940D8;
    if ((uint8_t)(lift_load8(cpu->eax + 1u)) == (uint8_t)(0x2Fu)) goto label_0009411D;
    label_000940D8: cpu->eip = LIFT_CODE_TOKEN_VA(0x4940D8u);
    cpu->edx = (uint32_t)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4940E7u); lift_push32(cpu, r); sfera_sub_00493E10(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_0009411D;
    cpu->esi = lift_load32(cpu->esp + 0x20u);
    if ((uint32_t)(lift_load32(cpu->esp + 0x1Cu)) == (uint32_t)(cpu->esi)) goto label_0009411D;
    cpu->eax = lift_load32(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = (uint32_t)(cpu->ebp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4940FFu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x494105u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) != 0u) goto label_0009411A;
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((uint32_t)(cpu->eax) == (uint32_t)(1u)) goto label_00094134;
    label_0009411A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49411Au);
    cpu->edi = (uint32_t)(cpu->esi + 0xFFFFFFFFu);
    label_0009411D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49411Du);
    ++cpu->edi;
    if ((int32_t)(uint32_t)(cpu->edi) < (int32_t)(uint32_t)(cpu->ebx)) goto label_00094090;
    label_00094126: cpu->eip = LIFT_CODE_TOKEN_VA(0x494126u);
    cpu->eax = lift_load32(cpu->esp + 0x2Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    lift_return(cpu, 8u, stop_address); return;
    label_00094134: cpu->eip = LIFT_CODE_TOKEN_VA(0x494134u);
    lift_store32(cpu->esp + 0x2Cu, (uint64_t)(lift_load32(cpu->esp + 0x2Cu)) + 1u);
    cpu->ebx = lift_load32(cpu->esp + 0x18u);
    cpu->ecx = cpu->esi;
    goto label_00094060;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00494150(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x494150u);
    cpu->esp -= 8u;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0xCu)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_00094166;
    label_0009415D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49415Du);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 8u, stop_address); return;
    label_00094166: cpu->eip = LIFT_CODE_TOKEN_VA(0x494166u);
    cpu->edx = lift_load32(cpu->esp + 0x14u);
    cpu->eax = lift_load32(cpu->ebp + 0xCu);
    cpu->ecx = 0u;
    lift_store32(cpu->esp + 4u, cpu->eax);
    if ((uint32_t)(cpu->edx) == 0u) goto label_00094180;
    cpu->ecx = lift_load32(cpu->edx);
    cpu->edx = lift_load32(cpu->edx + 4u);
    lift_store32(cpu->esp + 4u, cpu->edx);
    label_00094180: cpu->eip = LIFT_CODE_TOKEN_VA(0x494180u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->esp + 4u)) <= (int32_t)(uint32_t)(cpu->eax)) goto label_0009418A;
    lift_store32(cpu->esp + 4u, cpu->eax);
    label_0009418A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49418Au);
    if ((int32_t)(uint32_t)(cpu->ecx) >= (int32_t)(uint32_t)(lift_load32(cpu->esp + 4u))) goto label_0009415D;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = (uint32_t)(cpu->ebp + 0x410u);
    lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    lift_store32(cpu->esp + 0x1Cu, cpu->ecx);
    lift_push32(cpu, cpu->edi);
    label_000941A1: cpu->eip = LIFT_CODE_TOKEN_VA(0x4941A1u);
    cpu->edx = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->edx + ((uint32_t)(cpu->ecx) * 4u));
    cpu->eax = cpu->ecx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000941B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4941B0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000941B0;
    cpu->eax -= cpu->esi;
    cpu->ebx = (uint32_t)(cpu->eax + cpu->ecx);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_0009425B;
    cpu->eax = cpu->ecx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    label_000941D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4941D0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000941D0;
    cpu->eax -= cpu->edi;
    cpu->eax += cpu->ecx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_0009425B;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(0x2Fu)) goto label_000941EB;
    if ((uint8_t)(lift_load8(cpu->ecx + 1u)) == (uint8_t)((cpu->edx & 0xFFu))) goto label_0009425B;
    label_000941EB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4941EBu);
    if ((int8_t)(uint8_t)((cpu->edx & 0xFFu)) > (int8_t)(uint8_t)(0x20u)) goto label_000941FA;
    label_000941F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4941F0u);
    ++cpu->esi;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->eax)) goto label_0009425B;
    if ((int8_t)(uint8_t)(lift_load8(cpu->esi)) <= (int8_t)(uint8_t)(0x20u)) goto label_000941F0;
    label_000941FA: cpu->eip = LIFT_CODE_TOKEN_VA(0x4941FAu);
    if ((uint8_t)(lift_load8(cpu->esi)) != (uint8_t)(0x2Fu)) goto label_00094205;
    if ((uint8_t)(lift_load8(cpu->esi + 1u)) == (uint8_t)(0x2Fu)) goto label_0009425B;
    label_00094205: cpu->eip = LIFT_CODE_TOKEN_VA(0x494205u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494219u); lift_push32(cpu, r); sfera_sub_00493E10(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00094224;
    lift_store32(cpu->esp + 0x20u, (uint64_t)(lift_load32(cpu->esp + 0x20u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    goto label_0009425B;
    label_00094224: cpu->eip = LIFT_CODE_TOKEN_VA(0x494224u);
    cpu->edx = (uint32_t)(cpu->ebp + 0x10u);
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->ebx)) goto label_00094245;
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00094230: cpu->eip = LIFT_CODE_TOKEN_VA(0x494230u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((int8_t)(uint8_t)((cpu->ecx & 0xFFu)) <= (int8_t)(uint8_t)(0x20u)) goto label_00094245;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_00094241;
    lift_store8(cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    ++cpu->esi;
    label_00094241: cpu->eip = LIFT_CODE_TOKEN_VA(0x494241u);
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebx)) goto label_00094230;
    label_00094245: cpu->eip = LIFT_CODE_TOKEN_VA(0x494245u);
    lift_store8(cpu->eax, 0u);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x49424Eu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x494254u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009427A;
    label_0009425B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49425Bu);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    ++cpu->ecx;
    lift_store32(cpu->esp + 0x20u, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->ecx) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x10u))) goto label_000941A1;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 8u, stop_address); return;
    label_0009427A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49427Au);
    cpu->eax = (uint32_t)(cpu->ebp + 0x10u);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->ebx)) goto label_000942A0;
    cpu->ecx = cpu->eax;
    cpu->ecx -= cpu->ebp;
    cpu->ecx = (uint32_t)(cpu->ecx + cpu->esi + 0xFFFFFFF0u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00094290: cpu->eip = LIFT_CODE_TOKEN_VA(0x494290u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_0009429C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->eax, cpu->edx & 0xFFu);
    ++cpu->eax;
    ++cpu->ecx;
    label_0009429C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49429Cu);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->ebx)) goto label_00094290;
    label_000942A0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4942A0u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    lift_store8(cpu->eax, 0u);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 8u;
    lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004942C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4942C0u);
    cpu->eax = (uint32_t)(cpu->ecx + 0x10u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000942D0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4942D0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000942D0;
    cpu->ecx -= cpu->esi;
    cpu->ecx += cpu->eax;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_000942E5;
    lift_x87_push(cpu, 0.0);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000942E5: cpu->eip = LIFT_CODE_TOKEN_VA(0x4942E5u);
    lift_push32(cpu, cpu->ebx);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_00094333;
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(0x2Fu) & 0xFFu);
    label_000942F3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4942F3u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000942FE;
    if ((uint8_t)(lift_load8(cpu->eax + 1u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00094333;
    label_000942FE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4942FEu);
    if ((int8_t)(uint8_t)((cpu->edx & 0xFFu)) > (int8_t)(uint8_t)(0x20u)) goto label_0009430D;
    label_00094303: cpu->eip = LIFT_CODE_TOKEN_VA(0x494303u);
    ++cpu->eax;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_00094333;
    if ((int8_t)(uint8_t)(lift_load8(cpu->eax)) <= (int8_t)(uint8_t)(0x20u)) goto label_00094303;
    label_0009430D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49430Du);
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00094316;
    if ((uint8_t)(lift_load8(cpu->eax + 1u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00094333;
    label_00094316: cpu->eip = LIFT_CODE_TOKEN_VA(0x494316u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_0009433B;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_0009432E;
    cpu->edi = cpu->edi;
    label_00094320: cpu->eip = LIFT_CODE_TOKEN_VA(0x494320u);
    if ((int8_t)(uint8_t)(lift_load8(cpu->eax)) <= (int8_t)(uint8_t)(0x20u)) goto label_0009432E;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_00094333;
    ++cpu->eax;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_00094320;
    label_0009432E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49432Eu);
    ++cpu->esi;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_000942F3;
    label_00094333: cpu->eip = LIFT_CODE_TOKEN_VA(0x494333u);
    lift_x87_push(cpu, 0.0);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0009433B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49433Bu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%f"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x494346u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49434Cu);
    lift_x87_push(cpu, (double)lift_load_f32(cpu->esp + 0x1Cu));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00494360(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x494360u);
    cpu->eax = (uint32_t)(cpu->ecx + 0x10u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00094370: cpu->eip = LIFT_CODE_TOKEN_VA(0x494370u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00094370;
    cpu->ecx -= cpu->esi;
    cpu->ecx += cpu->eax;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_00094385;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00094385: cpu->eip = LIFT_CODE_TOKEN_VA(0x494385u);
    lift_push32(cpu, cpu->ebx);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_000943D3;
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(0x2Fu) & 0xFFu);
    label_00094393: cpu->eip = LIFT_CODE_TOKEN_VA(0x494393u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0009439E;
    if ((uint8_t)(lift_load8(cpu->eax + 1u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000943D3;
    label_0009439E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49439Eu);
    if ((int8_t)(uint8_t)((cpu->edx & 0xFFu)) > (int8_t)(uint8_t)(0x20u)) goto label_000943AD;
    label_000943A3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4943A3u);
    ++cpu->eax;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_000943D3;
    if ((int8_t)(uint8_t)(lift_load8(cpu->eax)) <= (int8_t)(uint8_t)(0x20u)) goto label_000943A3;
    label_000943AD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4943ADu);
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000943B6;
    if ((uint8_t)(lift_load8(cpu->eax + 1u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_000943D3;
    label_000943B6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4943B6u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_000943DB;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_000943CE;
    cpu->edi = cpu->edi;
    label_000943C0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4943C0u);
    if ((int8_t)(uint8_t)(lift_load8(cpu->eax)) <= (int8_t)(uint8_t)(0x20u)) goto label_000943CE;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_000943D3;
    ++cpu->eax;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_000943C0;
    label_000943CE: cpu->eip = LIFT_CODE_TOKEN_VA(0x4943CEu);
    ++cpu->esi;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_00094393;
    label_000943D3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4943D3u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000943DB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4943DBu);
    cpu->ecx = (uint32_t)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4943E6u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4943ECu);
    cpu->eax = lift_load32(cpu->esp + 0x1Cu);
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00494400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x494400u);
    cpu->eax = (uint32_t)(cpu->ecx + 0x10u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00094410: cpu->eip = LIFT_CODE_TOKEN_VA(0x494410u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00094410;
    cpu->ecx -= cpu->esi;
    cpu->ecx += cpu->eax;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_00094425;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_00094425: cpu->eip = LIFT_CODE_TOKEN_VA(0x494425u);
    lift_push32(cpu, cpu->ebx);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_00094473;
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(0x2Fu) & 0xFFu);
    label_00094433: cpu->eip = LIFT_CODE_TOKEN_VA(0x494433u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0009443E;
    if ((uint8_t)(lift_load8(cpu->eax + 1u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00094473;
    label_0009443E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49443Eu);
    if ((int8_t)(uint8_t)((cpu->edx & 0xFFu)) > (int8_t)(uint8_t)(0x20u)) goto label_0009444D;
    label_00094443: cpu->eip = LIFT_CODE_TOKEN_VA(0x494443u);
    ++cpu->eax;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_00094473;
    if ((int8_t)(uint8_t)(lift_load8(cpu->eax)) <= (int8_t)(uint8_t)(0x20u)) goto label_00094443;
    label_0009444D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49444Du);
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00094456;
    if ((uint8_t)(lift_load8(cpu->eax + 1u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00094473;
    label_00094456: cpu->eip = LIFT_CODE_TOKEN_VA(0x494456u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_0009447B;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_0009446E;
    cpu->edi = cpu->edi;
    label_00094460: cpu->eip = LIFT_CODE_TOKEN_VA(0x494460u);
    if ((int8_t)(uint8_t)(lift_load8(cpu->eax)) <= (int8_t)(uint8_t)(0x20u)) goto label_0009446E;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_00094473;
    ++cpu->eax;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_00094460;
    label_0009446E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49446Eu);
    ++cpu->esi;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_00094433;
    label_00094473: cpu->eip = LIFT_CODE_TOKEN_VA(0x494473u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0009447B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49447Bu);
    cpu->esi = lift_load32(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"%s"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x494486u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49448Cu);
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004944A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4944A0u);
    cpu->ecx += 0x10u;
    cpu->eax = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000944B0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4944B0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000944B0;
    cpu->eax -= cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + cpu->ecx);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_000944C6;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000944C6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4944C6u);
    lift_push32(cpu, cpu->ebx);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->edx)) goto label_00094513;
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(0x2Fu) & 0xFFu);
    label_000944D4: cpu->eip = LIFT_CODE_TOKEN_VA(0x4944D4u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000944DF;
    if ((uint8_t)(lift_load8(cpu->ecx + 1u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00094513;
    label_000944DF: cpu->eip = LIFT_CODE_TOKEN_VA(0x4944DFu);
    if ((int8_t)(uint8_t)((cpu->eax & 0xFFu)) > (int8_t)(uint8_t)(0x20u)) goto label_000944ED;
    label_000944E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4944E3u);
    ++cpu->ecx;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->edx)) goto label_00094513;
    if ((int8_t)(uint8_t)(lift_load8(cpu->ecx)) <= (int8_t)(uint8_t)(0x20u)) goto label_000944E3;
    label_000944ED: cpu->eip = LIFT_CODE_TOKEN_VA(0x4944EDu);
    if ((uint8_t)(lift_load8(cpu->ecx)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_000944F6;
    if ((uint8_t)(lift_load8(cpu->ecx + 1u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00094513;
    label_000944F6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4944F6u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_0009451B;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->edx)) goto label_0009450E;
    cpu->edi = cpu->edi;
    label_00094500: cpu->eip = LIFT_CODE_TOKEN_VA(0x494500u);
    if ((int8_t)(uint8_t)(lift_load8(cpu->ecx)) <= (int8_t)(uint8_t)(0x20u)) goto label_0009450E;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->edx)) goto label_00094513;
    ++cpu->ecx;
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->edx)) goto label_00094500;
    label_0009450E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49450Eu);
    ++cpu->esi;
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->edx)) goto label_000944D4;
    label_00094513: cpu->eip = LIFT_CODE_TOKEN_VA(0x494513u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_0009451B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49451Bu);
    if ((uint8_t)(lift_load8(cpu->ecx)) != (uint8_t)(0x22u)) goto label_00094513;
    cpu->eax = lift_load32(cpu->esp + 0x14u);
    ++cpu->ecx;
    cpu->esi = cpu->eax;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->edx)) goto label_00094543;
    label_00094530: cpu->eip = LIFT_CODE_TOKEN_VA(0x494530u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    if ((uint8_t)((cpu->ebx & 0xFFu)) == (uint8_t)(0x22u)) goto label_00094543;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->edx)) goto label_00094513;
    lift_store8(cpu->esi, cpu->ebx & 0xFFu);
    ++cpu->ecx;
    ++cpu->esi;
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->edx)) goto label_00094530;
    label_00094543: cpu->eip = LIFT_CODE_TOKEN_VA(0x494543u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    lift_store8(cpu->esi, 0u);
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00494550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x494550u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009458C;
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->ecx + 0x410u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->ecx + 0xCu);
    lift_store32(cpu->ecx + 0x414u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->edx)) goto label_00094576;
    lift_store32(cpu->ecx + 0x414u, cpu->edx);
    label_00094576: cpu->eip = LIFT_CODE_TOKEN_VA(0x494576u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ecx + 0x410u)) >= (int32_t)(uint32_t)(0u)) goto label_0009459F;
    lift_store32(cpu->ecx + 0x410u, 0u);
    lift_return(cpu, 4u, stop_address); return;
    label_0009458C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49458Cu);
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    lift_store32(cpu->ecx + 0x414u, cpu->eax);
    lift_store32(cpu->ecx + 0x410u, 0u);
    label_0009459F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49459Fu);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004945B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4945B0u);
    cpu->eax = 0u;
    lift_store32(cpu->ecx + 0x410u, cpu->eax);
    lift_store32(cpu->ecx + 0x414u, cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004945C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4945C0u);
    cpu->esp -= 0xCu;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esp + 0x10u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    if ((cpu->eflags & LIFT_FLAG_ZF) == 0u) goto label_000945D6;
    label_000945CD: cpu->eip = LIFT_CODE_TOKEN_VA(0x4945CDu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_000945D6: cpu->eip = LIFT_CODE_TOKEN_VA(0x4945D6u);
    cpu->ecx = lift_load32(cpu->ebp + 0x414u);
    cpu->eax = (uint32_t)(cpu->ebp + 0x410u);
    lift_store32(cpu->esp + 8u, cpu->eax);
    cpu->eax = lift_load32(cpu->eax);
    lift_store32(cpu->esp + 0xCu, cpu->ecx);
    if ((int32_t)(uint32_t)(cpu->eax) >= (int32_t)(uint32_t)(cpu->ecx)) goto label_000945CD;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    lift_store32(cpu->esp + 0xCu, cpu->eax);
    lift_push32(cpu, cpu->edi);
    label_000945F7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4945F7u);
    cpu->ecx = lift_load32(cpu->ebp + 8u);
    cpu->ecx = lift_load32(cpu->ecx + ((uint32_t)(cpu->eax) * 4u));
    cpu->eax = cpu->ecx;
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    label_00094602: cpu->eip = LIFT_CODE_TOKEN_VA(0x494602u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00094602;
    cpu->eax -= cpu->esi;
    cpu->ebx = (uint32_t)(cpu->eax + cpu->ecx);
    cpu->esi = cpu->ecx;
    if ((uint32_t)(cpu->ecx) == 0u) goto label_000946AC;
    cpu->eax = cpu->ecx;
    cpu->edi = (uint32_t)(cpu->eax + 1u);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00094620: cpu->eip = LIFT_CODE_TOKEN_VA(0x494620u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00094620;
    cpu->eax -= cpu->edi;
    cpu->eax += cpu->ecx;
    if ((uint32_t)(cpu->ecx) == (uint32_t)(cpu->eax)) goto label_000946AC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)(0x2Fu)) goto label_0009463F;
    if ((uint8_t)(lift_load8(cpu->ecx + 1u)) == (uint8_t)((cpu->edx & 0xFFu))) goto label_000946AC;
    label_0009463F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49463Fu);
    if ((int8_t)(uint8_t)((cpu->edx & 0xFFu)) > (int8_t)(uint8_t)(0x20u)) goto label_0009464E;
    label_00094644: cpu->eip = LIFT_CODE_TOKEN_VA(0x494644u);
    ++cpu->esi;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->eax)) goto label_000946AC;
    if ((int8_t)(uint8_t)(lift_load8(cpu->esi)) <= (int8_t)(uint8_t)(0x20u)) goto label_00094644;
    label_0009464E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49464Eu);
    if ((uint8_t)(lift_load8(cpu->esi)) != (uint8_t)(0x2Fu)) goto label_00094659;
    if ((uint8_t)(lift_load8(cpu->esi + 1u)) == (uint8_t)(0x2Fu)) goto label_000946AC;
    label_00094659: cpu->eip = LIFT_CODE_TOKEN_VA(0x494659u);
    cpu->edx = lift_load32(cpu->esp + 0x18u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49466Du); lift_push32(cpu, r); sfera_sub_00493E10(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) == (uint32_t)(0xFFFFFFFFu)) goto label_00094678;
    lift_store32(cpu->esp + 0x10u, (uint64_t)(lift_load32(cpu->esp + 0x10u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u));
    goto label_000946AC;
    label_00094678: cpu->eip = LIFT_CODE_TOKEN_VA(0x494678u);
    cpu->edx = (uint32_t)(cpu->ebp + 0x10u);
    cpu->eax = cpu->edx;
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->ebx)) goto label_00094696;
    label_00094681: cpu->eip = LIFT_CODE_TOKEN_VA(0x494681u);
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->esi)) & 0xFFu);
    if ((int8_t)(uint8_t)((cpu->ecx & 0xFFu)) <= (int8_t)(uint8_t)(0x20u)) goto label_00094696;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_00094692;
    lift_store8(cpu->eax, cpu->ecx & 0xFFu);
    ++cpu->eax;
    ++cpu->esi;
    label_00094692: cpu->eip = LIFT_CODE_TOKEN_VA(0x494692u);
    if ((uint32_t)(cpu->esi) < (uint32_t)(cpu->ebx)) goto label_00094681;
    label_00094696: cpu->eip = LIFT_CODE_TOKEN_VA(0x494696u);
    cpu->ecx = lift_load32(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    lift_store8(cpu->eax, 0u);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x49469Fu)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4946A5u);
    cpu->esp += 8u;
    if ((uint32_t)(cpu->eax) == 0u) goto label_000946CB;
    label_000946AC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4946ACu);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    ++cpu->eax;
    lift_store32(cpu->esp + 0x10u, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) < (int32_t)(uint32_t)(lift_load32(cpu->esp + 0x18u))) goto label_000945F7;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
    label_000946CB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4946CBu);
    cpu->eax = (uint32_t)(cpu->ebp + 0x10u);
    if ((uint32_t)(cpu->esi) >= (uint32_t)(cpu->ebx)) goto label_000946F0;
    cpu->edx = cpu->eax;
    cpu->edx -= cpu->ebp;
    cpu->ecx = (uint32_t)(cpu->edx + cpu->esi + 0xFFFFFFF0u);
    cpu->ebx = (uint32_t)(cpu->ebx);
    label_000946E0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4946E0u);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(lift_load32(cpu->esp + 0x14u))) goto label_000946EC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    lift_store8(cpu->eax, cpu->edx & 0xFFu);
    ++cpu->eax;
    ++cpu->ecx;
    label_000946EC: cpu->eip = LIFT_CODE_TOKEN_VA(0x4946ECu);
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->ebx)) goto label_000946E0;
    label_000946F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4946F0u);
    cpu->ecx = lift_load32(cpu->esp + 0x14u);
    lift_store8(cpu->eax, 0u);
    cpu->eax = lift_load32(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    ++cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    lift_store32(cpu->ecx, cpu->eax);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00494710(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x494710u);
    cpu->eax = (uint32_t)(cpu->ecx + 0x10u);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->ecx + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_00094720: cpu->eip = LIFT_CODE_TOKEN_VA(0x494720u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    ++cpu->ecx;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_00094720;
    cpu->ecx -= cpu->esi;
    cpu->ecx += cpu->eax;
    if ((uint32_t)(cpu->eax) != (uint32_t)(cpu->ecx)) goto label_00094735;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_00094735: cpu->eip = LIFT_CODE_TOKEN_VA(0x494735u);
    lift_push32(cpu, cpu->ebx);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_00094783;
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(0x2Fu) & 0xFFu);
    label_00094743: cpu->eip = LIFT_CODE_TOKEN_VA(0x494743u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    if ((uint8_t)((cpu->edx & 0xFFu)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_0009474E;
    if ((uint8_t)(lift_load8(cpu->eax + 1u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00094783;
    label_0009474E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49474Eu);
    if ((int8_t)(uint8_t)((cpu->edx & 0xFFu)) > (int8_t)(uint8_t)(0x20u)) goto label_0009475D;
    label_00094753: cpu->eip = LIFT_CODE_TOKEN_VA(0x494753u);
    ++cpu->eax;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_00094783;
    if ((int8_t)(uint8_t)(lift_load8(cpu->eax)) <= (int8_t)(uint8_t)(0x20u)) goto label_00094753;
    label_0009475D: cpu->eip = LIFT_CODE_TOKEN_VA(0x49475Du);
    if ((uint8_t)(lift_load8(cpu->eax)) != (uint8_t)((cpu->ebx & 0xFFu))) goto label_00094766;
    if ((uint8_t)(lift_load8(cpu->eax + 1u)) == (uint8_t)((cpu->ebx & 0xFFu))) goto label_00094783;
    label_00094766: cpu->eip = LIFT_CODE_TOKEN_VA(0x494766u);
    if ((uint32_t)(cpu->esi) == (uint32_t)(cpu->edi)) goto label_0009478B;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_0009477E;
    cpu->edi = cpu->edi;
    label_00094770: cpu->eip = LIFT_CODE_TOKEN_VA(0x494770u);
    if ((int8_t)(uint8_t)(lift_load8(cpu->eax)) <= (int8_t)(uint8_t)(0x20u)) goto label_0009477E;
    if ((uint32_t)(cpu->eax) >= (uint32_t)(cpu->ecx)) goto label_00094783;
    ++cpu->eax;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_00094770;
    label_0009477E: cpu->eip = LIFT_CODE_TOKEN_VA(0x49477Eu);
    ++cpu->esi;
    if ((uint32_t)(cpu->eax) < (uint32_t)(cpu->ecx)) goto label_00094743;
    label_00094783: cpu->eip = LIFT_CODE_TOKEN_VA(0x494783u);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_0009478B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49478Bu);
    lift_push32(cpu, (uintptr_t)g_sfera_config_parse_scratch_runtime.token); lift_push32(cpu, (uintptr_t)"%s"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x494796u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x49479Cu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(g_sfera_config_parse_scratch_runtime.token[0]) & 0xFFu);
    cpu->esp += 0xCu;
    if ((uint8_t)((cpu->eax & 0xFFu)) == 0u) goto label_00094783;
    if ((uint8_t)((cpu->eax & 0xFFu)) != (uint8_t)(0x31u)) goto label_000947B7;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
    label_000947B7: cpu->eip = LIFT_CODE_TOKEN_VA(0x4947B7u);
    lift_push32(cpu, (uintptr_t)"true"); lift_push32(cpu, (uintptr_t)g_sfera_config_parse_scratch_runtime.token);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4947C1u)); cpu->eip = LIFT_CODE_TOKEN_VA(0x4947C7u);
    cpu->esp += 8u;
    { uint64_t x=(uint64_t)(cpu->eax), v=0u-x; lift_flags_sub(cpu,0u,x,0u,v,32u); cpu->eflags=(cpu->eflags & ~LIFT_FLAG_CF) | (x != 0u ? LIFT_FLAG_CF : 0u); cpu->eax = v; }
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (uint64_t)(cpu->eax) - (uint64_t)(cpu->eax) - (uint64_t)(((cpu->eflags & LIFT_FLAG_CF) != 0u ? 1u : 0u));
    cpu->ebx = lift_pop32(cpu);
    ++cpu->eax;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004947E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4947E0u);
    cpu->ecx += 0x10u;
    cpu->eax = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = (uint32_t)(cpu->eax + 1u);
    cpu->esp = (uint32_t)(cpu->esp);
    label_000947F0: cpu->eip = LIFT_CODE_TOKEN_VA(0x4947F0u);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->eax)) & 0xFFu);
    ++cpu->eax;
    if ((uint8_t)((cpu->edx & 0xFFu)) != 0u) goto label_000947F0;
    cpu->eax -= cpu->esi;
    cpu->edx = (uint32_t)(cpu->eax + cpu->ecx);
    if ((uint32_t)(cpu->ecx) != (uint32_t)(cpu->edx)) goto label_00094804;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
    label_00094804: cpu->eip = LIFT_CODE_TOKEN_VA(0x494804u);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->ebx);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->edx)) goto label_0009484A;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(0x2Fu) & 0xFFu);
    cpu->ecx = (uint32_t)(cpu->ecx);
    label_00094810: cpu->eip = LIFT_CODE_TOKEN_VA(0x494810u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(lift_load8(cpu->ecx)) & 0xFFu);
    if ((uint8_t)((cpu->ebx & 0xFFu)) != (uint8_t)((cpu->eax & 0xFFu))) goto label_0009481B;
    if ((uint8_t)(lift_load8(cpu->ecx + 1u)) == (uint8_t)((cpu->eax & 0xFFu))) goto label_0009484A;
    label_0009481B: cpu->eip = LIFT_CODE_TOKEN_VA(0x49481Bu);
    if ((int8_t)(uint8_t)((cpu->ebx & 0xFFu)) > (int8_t)(uint8_t)(0x20u)) goto label_0009482A;
    label_00094820: cpu->eip = LIFT_CODE_TOKEN_VA(0x494820u);
    ++cpu->ecx;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->edx)) goto label_0009484A;
    if ((int8_t)(uint8_t)(lift_load8(cpu->ecx)) <= (int8_t)(uint8_t)(0x20u)) goto label_00094820;
    label_0009482A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49482Au);
    if ((uint8_t)(lift_load8(cpu->ecx)) != (uint8_t)((cpu->eax & 0xFFu))) goto label_00094833;
    if ((uint8_t)(lift_load8(cpu->ecx + 1u)) == (uint8_t)((cpu->eax & 0xFFu))) goto label_0009484A;
    label_00094833: cpu->eip = LIFT_CODE_TOKEN_VA(0x494833u);
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->edx)) goto label_00094845;
    label_00094837: cpu->eip = LIFT_CODE_TOKEN_VA(0x494837u);
    if ((int8_t)(uint8_t)(lift_load8(cpu->ecx)) <= (int8_t)(uint8_t)(0x20u)) goto label_00094845;
    if ((uint32_t)(cpu->ecx) >= (uint32_t)(cpu->edx)) goto label_0009484A;
    ++cpu->ecx;
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->edx)) goto label_00094837;
    label_00094845: cpu->eip = LIFT_CODE_TOKEN_VA(0x494845u);
    ++cpu->esi;
    if ((uint32_t)(cpu->ecx) < (uint32_t)(cpu->edx)) goto label_00094810;
    label_0009484A: cpu->eip = LIFT_CODE_TOKEN_VA(0x49484Au);
    cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00494850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x494850u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    if ((uint32_t)(cpu->eax) == 0u) goto label_0009488C;
    cpu->edx = lift_load32(cpu->eax);
    lift_store32(cpu->ecx + 0x418u, cpu->edx);
    cpu->eax = lift_load32(cpu->eax + 4u);
    cpu->edx = lift_load32(cpu->ecx + 0xCu);
    lift_store32(cpu->ecx + 0x41Cu, cpu->eax);
    if ((int32_t)(uint32_t)(cpu->eax) <= (int32_t)(uint32_t)(cpu->edx)) goto label_00094876;
    lift_store32(cpu->ecx + 0x41Cu, cpu->edx);
    label_00094876: cpu->eip = LIFT_CODE_TOKEN_VA(0x494876u);
    if ((int32_t)(uint32_t)(lift_load32(cpu->ecx + 0x418u)) >= (int32_t)(uint32_t)(0u)) goto label_0009489F;
    lift_store32(cpu->ecx + 0x418u, 0u);
    lift_return(cpu, 4u, stop_address); return;
    label_0009488C: cpu->eip = LIFT_CODE_TOKEN_VA(0x49488Cu);
    cpu->eax = lift_load32(cpu->ecx + 0xCu);
    lift_store32(cpu->ecx + 0x41Cu, cpu->eax);
    lift_store32(cpu->ecx + 0x418u, 0u);
    label_0009489F: cpu->eip = LIFT_CODE_TOKEN_VA(0x49489Fu);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004948B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4948B0u);
    cpu->eax = 0u;
    lift_store32(cpu->ecx + 0x418u, cpu->eax);
    lift_store32(cpu->ecx + 0x41Cu, cpu->eax);
    lift_return(cpu, 0u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_004948C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x4948C0u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = lift_load32(cpu->esp + 0x10u);
    lift_push32(cpu, 1u);
    cpu->esi = (uint32_t)(cpu->ecx + 0x418u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4948DAu); lift_push32(cpu, r); sfera_sub_00493F70(cpu,r); if (cpu->eip != r) return; }
    if ((uint32_t)(cpu->eax) != 0u) goto label_000948E3;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
    label_000948E3: cpu->eip = LIFT_CODE_TOKEN_VA(0x4948E3u);
    cpu->ecx = lift_load32(cpu->edi + 4u);
    cpu->edi = lift_pop32(cpu);
    lift_store32(cpu->esi, cpu->ecx);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); lift_return(cpu, 8u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00494900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x494900u);
    cpu->edx = lift_load32(cpu->ecx + 0x418u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->ecx = lift_load32(cpu->ecx + 0x41Cu);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00494920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x494920u);
    cpu->edx = lift_load32(cpu->ecx + 0x410u);
    cpu->eax = lift_load32(cpu->esp + 4u);
    lift_store32(cpu->eax, cpu->edx);
    cpu->ecx = lift_load32(cpu->ecx + 0x414u);
    lift_store32(cpu->eax + 4u, cpu->ecx);
    lift_return(cpu, 4u, stop_address); return;
}

LIFT_ENTRY void LIFT_CDECL sfera_sub_00494940(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eip = LIFT_CODE_TOKEN_VA(0x494940u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_push32(cpu, cpu->edi);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00094964;
    cpu->edx = 0x4Cu;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SimpleParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494959u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    lift_push32(cpu, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494961u); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00094964: cpu->eip = LIFT_CODE_TOKEN_VA(0x494964u);
    { uint64_t l=(uint64_t)(lift_load32(cpu->esi + 8u)), r=(uint64_t)(0u), v=l-r; lift_flags_sub(cpu,l,r,0u,v,32u); }
    lift_store32(cpu->esi, 0u);
    lift_store32(cpu->esi + 4u, 0u);
    if ((cpu->eflags & LIFT_FLAG_ZF) != 0u) goto label_00094992;
    cpu->edx = 0x51u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SimpleParser.cpp";
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x494986u); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = lift_load32(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x49498Fu); lift_push32(cpu, r); sfera_sub_004EBE20(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    label_00094992: cpu->eip = LIFT_CODE_TOKEN_VA(0x494992u);
    cpu->ebp = lift_load32(cpu->esp + 0x10u);
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esi + 8u, 0u);
    lift_store32(cpu->esi + 0xCu, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4949ABu); lift_push32(cpu, r); sfera_sub_0042F2A0(cpu,r); if (cpu->eip != r) return; }
    cpu->edi = cpu->eax;
    if ((uint32_t)(cpu->edi) == 0u) goto label_000949FB;
    cpu->edx = 0u;
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4949BAu); lift_push32(cpu, r); sfera_sub_0042EBF0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = 0x76u;
    cpu->ecx = (uint32_t)(uintptr_t)"..\\ShareClientSeverCode\\SimpleParser.cpp";
    cpu->ebp = cpu->eax;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4949CBu); lift_push32(cpu, r); sfera_sub_004EB1C0(cpu,r); if (cpu->eip != r) return; }
    cpu->edx = (uint32_t)(cpu->edi + 0xAu);
    lift_push32(cpu, cpu->edx);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4949D4u); lift_push32(cpu, r); sfera_sub_004EBEA0(cpu,r); if (cpu->eip != r) return; }
    cpu->esp += 4u;
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->ebp;
    lift_store32(cpu->esi, cpu->eax);
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4949E3u); lift_push32(cpu, r); sfera_sub_0042EF20(cpu,r); if (cpu->eip != r) return; }
    cpu->ecx = cpu->ebp;
    { uint32_t r=LIFT_CODE_TOKEN_VA(0x4949EAu); lift_push32(cpu, r); sfera_sub_0042F180(cpu,r); if (cpu->eip != r) return; }
    cpu->eax = lift_load32(cpu->esi);
    cpu->eax += cpu->edi;
    lift_store32(cpu->esi + 4u, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_store8(cpu->eax, 0u);
    { uint32_t r=LIFT_CODE_TOKEN_RVA(0x949FBu); lift_push32(cpu, r); sfera_sub_00493C50(cpu,r); if (cpu->eip != r) return; }
    label_000949FB: cpu->eip = LIFT_CODE_TOKEN_VA(0x4949FBu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); lift_return(cpu, 4u, stop_address); return;
}
