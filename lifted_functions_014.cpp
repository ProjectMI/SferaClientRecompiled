#include "lifted_functions.h"
#include <cmath>
namespace lifted {

__declspec(noinline) void sfera_sub_0048B970(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[6]; double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5, x87_v6;
    cpu->esp -= 0x30u;
    x87_v0 = (double)3.4028234663852886e+38f;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->ebx = cpu->ecx;
    cpu->ecx = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ebp = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ebx;
    if ((int32_t)cpu->esi < (int32_t)4u) goto label_0008BA17;
    cpu->esi += 0xFFFFFFFDu;
    cpu->edx = cpu->ebp + 0xCu;
    label_0008B9A0:
    { const double lift_right=(double)*(float*)(cpu->edx + 0xFFFFFFF8u); const double lift_left=(double)*(float*)(cpu->esp + 0x14u); if (!(lift_left>lift_right)) goto label_0008B9B9; }
    x87_v0 = (double)*(float*)(cpu->edx + 0xFFFFFFF8u);
    cpu->edi = cpu->ecx;
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    label_0008B9B9:
    { const double lift_right=(double)*(float*)(cpu->edx); const double lift_left=(double)*(float*)(cpu->esp + 0x14u); if (!(lift_left>lift_right)) goto label_0008B9D1; }
    x87_v0 = (double)*(float*)(cpu->edx);
    cpu->edi = cpu->ecx + 1u;
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    label_0008B9D1:
    { const double lift_right=(double)*(float*)(cpu->edx + 8u); const double lift_left=(double)*(float*)(cpu->esp + 0x14u); if (!(lift_left>lift_right)) goto label_0008B9EB; }
    x87_v0 = (double)*(float*)(cpu->edx + 8u);
    cpu->edi = cpu->ecx + 2u;
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    label_0008B9EB:
    { const double lift_right=(double)*(float*)(cpu->edx + 0x10u); const double lift_left=(double)*(float*)(cpu->esp + 0x14u); if (!(lift_left>lift_right)) goto label_0008BA05; }
    x87_v0 = (double)*(float*)(cpu->edx + 0x10u);
    cpu->edi = cpu->ecx + 3u;
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    label_0008BA05:
    cpu->ecx += 4u;
    cpu->edx += 0x20u;
    if ((int32_t)cpu->ecx < (int32_t)cpu->esi) goto label_0008B9A0;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x44u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    label_0008BA17:
    if ((int32_t)cpu->ecx >= (int32_t)cpu->esi) goto label_0008BA49;
    cpu->edx = cpu->ebp + (cpu->ecx * 8u) + 4u;
    (void)cpu;
    label_0008BA20:
    { const double lift_right=(double)*(float*)(cpu->edx); const double lift_left=(double)*(float*)(cpu->esp + 0x14u); if (!(lift_left>lift_right)) goto label_0008BA37; }
    x87_v0 = (double)*(float*)(cpu->edx);
    cpu->edi = cpu->ecx;
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    label_0008BA37:
    ++cpu->ecx;
    cpu->edx += 8u;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->esp + 0x44u)) goto label_0008BA20;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x44u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    label_0008BA49:
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->eax >= 0) goto label_0008BA6A;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    label_0008BA6A:
    x87_v0 = 0.0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(float*)(cpu->esp + 0x28u) = x87_v0;
    --cpu->eax;
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0x44u) == 0u; sub_pred[4] = (int32_t)(*(uint32_t*)(cpu->esp + 0x44u)) < (int32_t)(0u);
    *(float*)(cpu->esp + 0x2Cu) = x87_v0;
    *(float*)(cpu->esp + 0x34u) = x87_v0;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(float*)(cpu->esp + 0x38u) = x87_v0; 
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint8_t*)(cpu->esp + 0x13u) = 0u;
    if ((sub_pred[0]) || (sub_pred[4])) goto label_0008BDA0;
    x87_v0 = 6.018531076210112e-36;
    x87_v1 = 0.5;
    x87_v2 = (double)*(float*)(cpu->esp + 0x28u);
    x87_v3 = (double)*(float*)(cpu->esp + 0x2Cu);
    goto label_0008BAB3;
    label_0008BAAF:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    label_0008BAB3:
    if ((int32_t)cpu->eax > (int32_t)*(uint32_t*)(cpu->esp + 0x14u)) goto label_0008BB3F;
    goto label_0008BAC1;
    label_0008BABF:
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    label_0008BAC1:
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x1Cu) <= (int32_t)0u) goto label_0008BC68;
    cpu->esi = cpu->edi + 0xFFFFFFFFu;
    x87_v2 = x87_v3; 
    if ((int32_t)cpu->esi >= 0) goto label_0008BADA;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x44u);
    --cpu->esi;
    label_0008BADA:
    x87_v3 = (double)*(float*)(cpu->ebp + (cpu->esi * 8u) + 4u);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v3); 
    cpu->ecx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x4Cu);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    if ((int32_t)cpu->ecx <= (int32_t)cpu->eax) goto label_0008BAF7;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    cpu->ecx = cpu->eax;
    label_0008BAF7:
    x87_v3 = (double)*(float*)(cpu->ebp + (cpu->esi * 8u));
    --*(uint32_t*)(cpu->esp + 0x1Cu);
    x87_v3 = (x87_v3) - (((double)*(float*)(cpu->ebp + (cpu->edi * 8u))));
    x87_v4 = (double)*(float*)(cpu->ebp + (cpu->esi * 8u) + 4u);
    x87_v4 = (x87_v4) - (((double)*(float*)(cpu->ebp + (cpu->edi * 8u) + 4u)));
    x87_v4 = (x87_v4) + (x87_v0);
    x87_v3 = x87_v3 / x87_v4; 
    *(float*)(cpu->esp + 0x28u) = x87_v3; 
    x87_v3 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    x87_v3 = (x87_v3) + (x87_v1);
    x87_v3 = (x87_v3) - (((double)*(float*)(cpu->ebp + (cpu->edi * 8u) + 4u)));
    x87_v4 = (double)*(float*)(cpu->esp + 0x28u); x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    x87_v5 = (double)*(float*)(cpu->ebp + (cpu->edi * 8u));
    cpu->edi = cpu->esi;
    x87_v3 = x87_v3 + x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v3; x87_v3 = temporary; }
    *(float*)(cpu->esp + 0x34u) = x87_v4; 
    if ((int32_t)cpu->ecx <= (int32_t)*(uint32_t*)(cpu->esp + 0x14u)) goto label_0008BABF;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    label_0008BB3F:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x24u) > (int32_t)cpu->eax) goto label_0008BBC4;
    label_0008BB49:
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x1Cu) <= (int32_t)0u) goto label_0008BBC4;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x30u);
    x87_v3 = x87_v3; 
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)*(uint32_t*)(cpu->esp + 0x44u)) goto label_0008BB5F;
    cpu->esi = 0u;
    label_0008BB5F:
    x87_v3 = (double)*(float*)(cpu->ebp + (cpu->esi * 8u) + 4u);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v3); 
    cpu->edx = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x4Cu);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    if ((int32_t)cpu->edx <= (int32_t)cpu->eax) goto label_0008BB7C;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    cpu->edx = cpu->eax;
    label_0008BB7C:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    x87_v3 = (double)*(float*)(cpu->ebp + (cpu->esi * 8u));
    x87_v3 = (x87_v3) - (((double)*(float*)(cpu->ebp + (cpu->ecx * 8u))));
    cpu->eax = cpu->ebp + (cpu->ecx * 8u) + 4u;
    x87_v4 = (double)*(float*)(cpu->ebp + (cpu->esi * 8u) + 4u);
    --*(uint32_t*)(cpu->esp + 0x1Cu);
    x87_v4 = (x87_v4) - (((double)*(float*)(cpu->eax)));
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->esi;
    x87_v4 = (x87_v4) + (x87_v0);
    x87_v3 = x87_v3 / x87_v4; 
    *(float*)(cpu->esp + 0x2Cu) = x87_v3; 
    x87_v3 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x14u))));
    x87_v3 = (x87_v3) + (x87_v1);
    x87_v3 = (x87_v3) - (((double)*(float*)(cpu->eax)));
    x87_v4 = (double)*(float*)(cpu->esp + 0x2Cu); x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    x87_v5 = (double)*(float*)(cpu->ebp + (cpu->ecx * 8u));
    x87_v3 = x87_v3 + x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v3; x87_v3 = temporary; }
    *(float*)(cpu->esp + 0x38u) = x87_v4; 
    if ((int32_t)cpu->edx <= (int32_t)*(uint32_t*)(cpu->esp + 0x14u)) goto label_0008BB49;
    label_0008BBC4:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->esp + 0x20u)) goto label_0008BCF8;
    cpu->eax = cpu->eax + (cpu->eax * 2u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    label_0008BBDF:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x14u) >= (int32_t)cpu->ecx) goto label_0008BCF8;
    x87_v4 = (double)*(float*)(cpu->esp + 0x34u); x87_v5 = x87_v4;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v5); 
    x87_v5 = (double)*(float*)(cpu->esp + 0x38u); x87_v6 = x87_v5;
    cpu->esi = cpu->eax;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v6); 
    x87_v6 = x87_v2;
    x87_v4 = x87_v4 + x87_v6; 
    { double temporary = x87_v5; x87_v5 = x87_v4; x87_v4 = temporary; }
    *(float*)(cpu->esp + 0x34u) = x87_v5; 
    x87_v4 = (x87_v4) + (x87_v3);
    *(float*)(cpu->esp + 0x38u) = x87_v4; 
    if ((int32_t)cpu->esi >= 0) goto label_0008BC1B;
    cpu->esi = 0u;
    label_0008BC1B:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x48u);
    if ((int32_t)cpu->eax < (int32_t)cpu->ecx) goto label_0008BC26;
    cpu->eax = cpu->ecx + 0xFFFFFFFFu;
    label_0008BC26:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ecx += g_sfera_shadow_runtime.span_records;
    ++*(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x2Cu)) + (uint64_t)(0x18u) + (uint64_t)(0u);
    if ((int32_t)cpu->esi > (int32_t)cpu->eax) goto label_0008BCEA;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    if (cpu->edx != 0x7FFFFFFFu) goto label_0008BC71;
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->ebx;
    cpu->eax = g_sfera_shadow_runtime.manager;
    if (cpu->eax == 0u) goto label_0008BCEA;
    *(uint8_t*)(cpu->eax) = 1u;
    goto label_0008BCEA;
    label_0008BC68:
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    goto label_0008BB3F;
    label_0008BC71:
    cpu->edi = *(uint32_t*)(cpu->ecx + 8u);
    if (cpu->edi == cpu->ebx) goto label_0008BC90;
    *(uint32_t*)(cpu->ecx + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 0x14u) = cpu->edi;
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x13u) = 1u;
    goto label_0008BCE3;
    label_0008BC90:
    if ((int32_t)cpu->esi >= (int32_t)cpu->edx) goto label_0008BCBB;
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    if ((int32_t)cpu->eax >= (int32_t)cpu->edx) goto label_0008BCAD;
    *(uint32_t*)(cpu->ecx + 0xCu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 0x14u) = cpu->edi;
    *(uint8_t*)(cpu->esp + 0x13u) = 1u;
    goto label_0008BCE3;
    label_0008BCAD:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    if ((int32_t)cpu->eax <= (int32_t)*(uint32_t*)(cpu->ecx + 4u)) goto label_0008BCEA;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    goto label_0008BCEA;
    label_0008BCBB:
    cpu->ebx = *(uint32_t*)(cpu->ecx + 4u);
    if ((int32_t)cpu->esi <= (int32_t)cpu->ebx) goto label_0008BCDB;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->ecx + 0xCu) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 0x14u) = cpu->edi;
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    *(uint32_t*)(cpu->ecx + 8u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x13u) = 1u;
    goto label_0008BCE3;
    label_0008BCDB:
    sub_pred[1] = cpu->eax == cpu->ebx; sub_pred[5] = (int32_t)(cpu->eax) < (int32_t)(cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x3Cu);
    if ((sub_pred[1]) || (sub_pred[5])) goto label_0008BCE6;
    label_0008BCE3:
    *(uint32_t*)(cpu->ecx + 4u) = cpu->eax;
    label_0008BCE6:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    label_0008BCEA:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x14u) < (int32_t)cpu->eax) goto label_0008BBDF;
    label_0008BCF8:
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x1Cu) > (int32_t)0u) goto label_0008BAAF;
    sub_pred[2] = *(uint8_t*)(cpu->esp + 0x13u) == 0u;
    x87_v3 = x87_v3; 
    x87_v2 = x87_v2; 
    x87_v0 = x87_v1; 
    x87_v0 = x87_v0; 
    if (sub_pred[2]) goto label_0008BDA0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x50u);
    cpu->ebx = *(uint32_t*)(cpu->ecx + 4u);
    if ((int32_t)cpu->eax <= 0) goto label_0008BDA0;
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->eax;
    label_0008BD33:
    cpu->eax = g_sfera_shadow_runtime.span_records;
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->ebp + 0x10u);
    cpu->edi = *(uint32_t*)(cpu->eax + cpu->ebp + 0xCu);
    cpu->esi = cpu->eax + cpu->ebp + 0x10u;
    cpu->ecx = cpu->eax + cpu->ebp + 0xCu;
    if ((int32_t)(cpu->edi) >= (int32_t)(cpu->edx)) goto label_0008BD85;
    cpu->edx -= cpu->edi;
    ++cpu->edx;
    cpu->eax = 0u;
    if ((cpu->edx==0u) || (((cpu->edx)&0x80000000u)!=0u)) goto label_0008BD79;
    cpu->edx = g_sfera_shadow_runtime.span_records;
    cpu->edx = cpu->edx + cpu->ebp + 0x14u;
    (void)cpu;
    label_0008BD60:
    cpu->edi = *(uint32_t*)(cpu->ecx);
    cpu->ebp = (cpu->ebp & 0xFFFF0000u) | (*(uint16_t*)(cpu->edx));
    cpu->edi += cpu->eax;
    *(uint16_t*)(cpu->ebx + (cpu->edi * 2u)) = cpu->ebp & 0xFFFFu;
    cpu->edi = *(uint32_t*)(cpu->esi);
    cpu->edi -= *(uint32_t*)(cpu->ecx);
    ++cpu->eax;
    ++cpu->edi;
    if ((int32_t)(cpu->eax) < (int32_t)(cpu->edi)) goto label_0008BD60;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x44u);
    label_0008BD79:
    *(uint32_t*)(cpu->ecx) = 0x7FFFFFFFu;
    *(uint32_t*)(cpu->esi) = 0x80000000u;
    label_0008BD85:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x50u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->ecx >>= 1u;
    cpu->edx = cpu->ecx & 0xFFFFu;
    cpu->ebp += 0x18u;
    --*(uint32_t*)(cpu->esp + 0x4Cu); sub_pred[3] = *(uint32_t*)(cpu->esp + 0x4Cu) == 0u;
    cpu->ebx = cpu->ebx + (cpu->edx * 2u);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ebp;
    if (!sub_pred[3]) goto label_0008BD33;
    label_0008BDA0:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048BDB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 4u) = cpu->ecx;
    if ((int32_t)cpu->eax <= 0) goto label_0008BE2F;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = 0u;
    cpu->ecx = cpu->eax;
    label_0008BDD0:
    cpu->eax = g_sfera_shadow_runtime.span_records;
    cpu->edi = *(uint32_t*)(cpu->eax + cpu->ebp);
    cpu->edx = *(uint32_t*)(cpu->eax + cpu->ebp + 4u);
    cpu->eax += cpu->ebp;
    if ((int32_t)(cpu->edi) >= (int32_t)(cpu->edx)) goto label_0008BE14;
    cpu->edx -= cpu->edi;
    ++cpu->edx;
    cpu->esi = 0u;
    if ((cpu->edx==0u) || (((cpu->edx)&0x80000000u)!=0u)) goto label_0008BE07;
    label_0008BDF0:
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->edi = (cpu->edi & 0xFFFF0000u) | (*(uint16_t*)(cpu->eax + 8u));
    cpu->edx += cpu->esi;
    *(uint16_t*)(cpu->ebx + (cpu->edx * 2u)) = cpu->edi & 0xFFFFu;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx -= *(uint32_t*)(cpu->eax);
    ++cpu->esi;
    ++cpu->edx;
    if ((int32_t)(cpu->esi) < (int32_t)(cpu->edx)) goto label_0008BDF0;
    label_0008BE07:
    *(uint32_t*)(cpu->eax) = 0x7FFFFFFFu;
    *(uint32_t*)(cpu->eax + 4u) = 0x80000000u;
    label_0008BE14:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->edx >>= 1u;
    cpu->eax = cpu->edx & 0xFFFFu;
    cpu->ebp += 0x18u;
    --cpu->ecx;
    cpu->ebx = cpu->ebx + (cpu->eax * 2u);
    if (cpu->ecx != 0u) goto label_0008BDD0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_0008BE2F:
    *(uint8_t*)(cpu->ecx) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048BE40(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5, x87_v6, x87_v7;
    cpu->esp -= 0x114u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x120u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x124u);
    cpu->ebx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x138u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ecx;
    if (g_sfera_shadow_runtime.projected_point_capacity >= cpu->ebp) goto label_0008BEDC;
    cpu->edx = 0x18Bu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\shadow.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48BE98u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48BE98u));
    cpu->edx = g_sfera_shadow_runtime.projected_points;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48BEA4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48BEA4u));
    cpu->esp += 4u;
    cpu->edx = 0x18Cu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\shadow.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48BEB6u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48BEB6u));
    cpu->eax = cpu->ebp;
    cpu->edx = 8u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48BECEu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x48BECEu));
    cpu->esp += 4u;
    g_sfera_shadow_runtime.projected_points = cpu->eax;
    g_sfera_shadow_runtime.projected_point_capacity = cpu->ebp;
    label_0008BEDC:
    x87_v0 = (double)*(float*)(cpu->esp + 0x148u);
    std::memmove((void*)(cpu->esp + 0x38u),(void*)(cpu->esi),64u);
    cpu->edi = cpu->esp + 0x78u;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esp + 0x144u),64u); cpu->edi += 64u;
    *(float*)(cpu->esp + 0x154u) = x87_v0; 
    *(float*)(cpu->esp + 0x164u) = (double)*(float*)(cpu->esp + 0x80u);
    *(float*)(cpu->esp + 0x174u) = (double)*(float*)(cpu->esp + 0x84u);
    *(float*)(cpu->esp + 0x148u) = (double)*(float*)(cpu->esp + 0x88u);
    *(float*)(cpu->esp + 0x158u) = (double)*(float*)(cpu->esp + 0x8Cu);
    *(float*)(cpu->esp + 0x168u) = (double)*(float*)(cpu->esp + 0x90u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x94u);
    cpu->eax = cpu->esp + 0xC8u;
    *(float*)(cpu->esp + 0x178u) = x87_v0; 
    cpu->eax &= 0xFFFFFFF0u;
    x87_v0 = (double)*(float*)(cpu->esp + 0x98u);
    cpu->ecx = cpu->esp + 0x144u;
    *(float*)(cpu->esp + 0x14Cu) = x87_v0; 
    lift_push32(cpu, cpu->ecx);
    x87_v0 = (double)*(float*)(cpu->esp + 0xA0u);
    cpu->edx = cpu->esp + 0x3Cu;
    *(float*)(cpu->esp + 0x160u) = x87_v0; 
    cpu->ecx = cpu->eax;
    x87_v0 = (double)*(float*)(cpu->esp + 0xA4u);
    *(uint32_t*)(cpu->esp + 0xBCu) = cpu->eax;
    *(float*)(cpu->esp + 0x170u) = x87_v0; 
    *(float*)(cpu->esp + 0x180u) = (double)*(float*)(cpu->esp + 0xA8u);
    *(float*)(cpu->esp + 0x154u) = (double)*(float*)(cpu->esp + 0xACu);
    *(float*)(cpu->esp + 0x164u) = (double)*(float*)(cpu->esp + 0xB0u);
    *(float*)(cpu->esp + 0x174u) = (double)*(float*)(cpu->esp + 0xB4u);
    *(float*)(cpu->esp + 0x184u) = (double)*(float*)(cpu->esp + 0xB8u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48BFEFu)); sfera_sub_004822F0(cpu, LIFT_CODE_TOKEN_VA(0x48BFEFu));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x138u);
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x138u))));
    cpu->esi = *(uint32_t*)(cpu->esp + 0xB8u);
    if ((int32_t)cpu->edx >= 0) goto label_0008C00E;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_0008C00E:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x13Cu);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x13Cu))));
    if ((int32_t)cpu->eax >= 0) goto label_0008C02A;
    x87_v0 = (x87_v0) + (((double)4294967296.0f));
    label_0008C02A:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x128u);
    *(float*)(cpu->esp + 0x18u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->ecx = 0u;
    x87_v1 = (double)*(float*)(cpu->esp + 0x18u);
    cpu->eax = 0u;
    x87_v2 = 0.5;
    if ((int32_t)cpu->ebp < (int32_t)4u) goto label_0008C2F3;
    cpu->edi = cpu->esi + 8u;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edi;
    cpu->edi = cpu->esi + 0xCu;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    cpu->edi = cpu->esi + 0x14u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    cpu->edi = cpu->esi + 0x10u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edi;
    cpu->edi = cpu->esi + 0x18u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edi;
    cpu->edi = cpu->esi + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    label_0008C07A:
    cpu->edi = *(uint32_t*)(cpu->edx);
    x87_v3 = (double)*(float*)(cpu->esi);
    cpu->ebp = *(uint32_t*)(cpu->edi + cpu->eax);
    *(uint32_t*)(cpu->esp + 0x108u) = cpu->ebp;
    x87_v4 = (double)*(float*)(cpu->esp + 0x108u);
    cpu->ebp = *(uint32_t*)(cpu->edi + cpu->eax + 4u);
    x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    cpu->edi = *(uint32_t*)(cpu->edi + cpu->eax + 8u);
    x87_v5 = (double)*(float*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->esp + 0x110u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esp + 0x10Cu) = cpu->ebp;
    x87_v6 = (double)*(float*)(cpu->esp + 0x10Cu); x87_v7 = x87_v6;
    x87_v5 = x87_v5 * x87_v7; 
    { double temporary = x87_v6; x87_v6 = x87_v3; x87_v3 = temporary; }
    x87_v5 = x87_v5 + x87_v6; 
    x87_v6 = (double)*(float*)(cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    x87_v6 = (x87_v6) * (((double)*(float*)(cpu->esp + 0x110u)));
    x87_v5 = x87_v5 + x87_v6; 
    x87_v5 = (x87_v5) + (((double)*(float*)(cpu->edi)));
    cpu->edi = g_sfera_shadow_runtime.projected_points;
    x87_v5 = (x87_v5) + (x87_v2);
    x87_v5 = (x87_v5) * (x87_v0);
    *(float*)(cpu->edi + (cpu->ecx * 8u)) = x87_v5; 
    cpu->edi = *(uint32_t*)(cpu->esp + 0x24u);
    x87_v4 = (x87_v4) * (((double)*(float*)(cpu->edi)));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    x87_v5 = (double)*(float*)(cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    x87_v3 = x87_v3 * x87_v5; 
    x87_v3 = x87_v3 + x87_v4; 
    x87_v4 = (double)*(float*)(cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v4 = (x87_v4) * (((double)*(float*)(cpu->esp + 0x110u)));
    x87_v3 = x87_v3 + x87_v4; 
    x87_v3 = (x87_v3) + (((double)*(float*)(cpu->edi)));
    cpu->edi = g_sfera_shadow_runtime.projected_points;
    x87_v3 = (x87_v3) + (x87_v2);
    x87_v3 = (x87_v3) * (x87_v1);
    *(float*)(cpu->edi + (cpu->ecx * 8u) + 4u) = x87_v3; 
    cpu->eax += *(uint32_t*)(cpu->edx + 4u);
    cpu->edi = *(uint32_t*)(cpu->edx);
    x87_v3 = (double)*(float*)(cpu->esi);
    cpu->ebp = *(uint32_t*)(cpu->edi + cpu->eax);
    *(uint32_t*)(cpu->esp + 0x108u) = cpu->ebp;
    x87_v4 = (double)*(float*)(cpu->esp + 0x108u);
    cpu->ebp = *(uint32_t*)(cpu->edi + cpu->eax + 4u);
    x87_v5 = x87_v4;
    cpu->edi = *(uint32_t*)(cpu->edi + cpu->eax + 8u);
    x87_v3 = x87_v3 * x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->esp + 0x10Cu) = cpu->ebp;
    x87_v6 = (double)*(float*)(cpu->esp + 0x10Cu);
    *(uint32_t*)(cpu->esp + 0x110u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x28u);
    x87_v7 = x87_v6;
    x87_v5 = x87_v5 * x87_v7; 
    { double temporary = x87_v6; x87_v6 = x87_v3; x87_v3 = temporary; }
    x87_v5 = x87_v5 + x87_v6; 
    x87_v6 = (double)*(float*)(cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    x87_v6 = (x87_v6) * (((double)*(float*)(cpu->esp + 0x110u)));
    x87_v5 = x87_v5 + x87_v6; 
    x87_v5 = (x87_v5) + (((double)*(float*)(cpu->edi)));
    cpu->edi = g_sfera_shadow_runtime.projected_points;
    x87_v5 = (x87_v5) + (x87_v2);
    x87_v5 = (x87_v5) * (x87_v0);
    *(float*)(cpu->edi + (cpu->ecx * 8u) + 8u) = x87_v5; 
    cpu->edi = *(uint32_t*)(cpu->esp + 0x24u);
    x87_v4 = (x87_v4) * (((double)*(float*)(cpu->edi)));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    x87_v5 = (double)*(float*)(cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    x87_v3 = x87_v3 * x87_v5; 
    x87_v3 = x87_v3 + x87_v4; 
    x87_v4 = (double)*(float*)(cpu->edi);
    x87_v4 = (x87_v4) * (((double)*(float*)(cpu->esp + 0x110u)));
    x87_v3 = x87_v3 + x87_v4; 
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v3 = (x87_v3) + (((double)*(float*)(cpu->edi)));
    cpu->edi = g_sfera_shadow_runtime.projected_points;
    x87_v3 = (x87_v3) + (x87_v2);
    x87_v3 = (x87_v3) * (x87_v1);
    *(float*)(cpu->edi + (cpu->ecx * 8u) + 0xCu) = x87_v3; 
    cpu->eax += *(uint32_t*)(cpu->edx + 4u);
    cpu->edi = *(uint32_t*)(cpu->edx);
    x87_v3 = (double)*(float*)(cpu->esi);
    cpu->ebp = *(uint32_t*)(cpu->edi + cpu->eax);
    *(uint32_t*)(cpu->esp + 0x108u) = cpu->ebp;
    x87_v4 = (double)*(float*)(cpu->esp + 0x108u);
    cpu->ebp = *(uint32_t*)(cpu->edi + cpu->eax + 4u);
    x87_v5 = x87_v4;
    cpu->edi = *(uint32_t*)(cpu->edi + cpu->eax + 8u);
    x87_v3 = x87_v3 * x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->esp + 0x110u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x28u);
    *(uint32_t*)(cpu->esp + 0x10Cu) = cpu->ebp;
    x87_v6 = (double)*(float*)(cpu->esp + 0x10Cu); x87_v7 = x87_v6;
    x87_v5 = x87_v5 * x87_v7; 
    { double temporary = x87_v6; x87_v6 = x87_v3; x87_v3 = temporary; }
    x87_v5 = x87_v5 + x87_v6; 
    x87_v6 = (double)*(float*)(cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    x87_v6 = (x87_v6) * (((double)*(float*)(cpu->esp + 0x110u)));
    x87_v5 = x87_v5 + x87_v6; 
    x87_v5 = (x87_v5) + (((double)*(float*)(cpu->edi)));
    cpu->edi = g_sfera_shadow_runtime.projected_points;
    x87_v5 = (x87_v5) + (x87_v2);
    x87_v5 = (x87_v5) * (x87_v0);
    *(float*)(cpu->edi + (cpu->ecx * 8u) + 0x10u) = x87_v5; 
    cpu->edi = *(uint32_t*)(cpu->esp + 0x24u);
    x87_v4 = (x87_v4) * (((double)*(float*)(cpu->edi)));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    x87_v5 = (double)*(float*)(cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    x87_v3 = x87_v3 * x87_v5; 
    x87_v3 = x87_v3 + x87_v4; 
    x87_v4 = (double)*(float*)(cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v4 = (x87_v4) * (((double)*(float*)(cpu->esp + 0x110u)));
    x87_v3 = x87_v3 + x87_v4; 
    x87_v3 = (x87_v3) + (((double)*(float*)(cpu->edi)));
    cpu->edi = g_sfera_shadow_runtime.projected_points;
    x87_v3 = (x87_v3) + (x87_v2);
    x87_v3 = (x87_v3) * (x87_v1);
    *(float*)(cpu->edi + (cpu->ecx * 8u) + 0x14u) = x87_v3; 
    cpu->eax += *(uint32_t*)(cpu->edx + 4u);
    cpu->edi = *(uint32_t*)(cpu->edx);
    x87_v3 = (double)*(float*)(cpu->esi);
    cpu->ebp = *(uint32_t*)(cpu->edi + cpu->eax);
    *(uint32_t*)(cpu->esp + 0x108u) = cpu->ebp;
    x87_v4 = (double)*(float*)(cpu->esp + 0x108u);
    cpu->ebp = *(uint32_t*)(cpu->edi + cpu->eax + 4u);
    x87_v5 = x87_v4;
    cpu->edi = *(uint32_t*)(cpu->edi + cpu->eax + 8u);
    x87_v3 = x87_v3 * x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->esp + 0x10Cu) = cpu->ebp;
    x87_v6 = (double)*(float*)(cpu->esp + 0x10Cu);
    *(uint32_t*)(cpu->esp + 0x110u) = cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x28u);
    x87_v7 = x87_v6;
    x87_v5 = x87_v5 * x87_v7; 
    { double temporary = x87_v6; x87_v6 = x87_v3; x87_v3 = temporary; }
    x87_v5 = x87_v5 + x87_v6; 
    x87_v6 = (double)*(float*)(cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    x87_v6 = (x87_v6) * (((double)*(float*)(cpu->esp + 0x110u)));
    x87_v5 = x87_v5 + x87_v6; 
    x87_v5 = (x87_v5) + (((double)*(float*)(cpu->edi)));
    cpu->edi = g_sfera_shadow_runtime.projected_points;
    x87_v5 = (x87_v5) + (x87_v2);
    x87_v5 = (x87_v5) * (x87_v0);
    *(float*)(cpu->edi + (cpu->ecx * 8u) + 0x18u) = x87_v5; 
    cpu->edi = *(uint32_t*)(cpu->esp + 0x24u);
    x87_v4 = (x87_v4) * (((double)*(float*)(cpu->edi)));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    x87_v5 = (double)*(float*)(cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    x87_v3 = x87_v3 * x87_v5; 
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx += 4u;
    x87_v3 = x87_v3 + x87_v4; 
    x87_v4 = (double)*(float*)(cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    x87_v4 = (x87_v4) * (((double)*(float*)(cpu->esp + 0x110u)));
    x87_v3 = x87_v3 + x87_v4; 
    x87_v3 = (x87_v3) + (((double)*(float*)(cpu->edi)));
    cpu->edi = g_sfera_shadow_runtime.projected_points;
    x87_v3 = (x87_v3) + (x87_v2);
    x87_v3 = (x87_v3) * (x87_v1);
    *(float*)(cpu->edi + (cpu->ecx * 8u) + 0xFFFFFFFCu) = x87_v3; 
    cpu->eax += *(uint32_t*)(cpu->edx + 4u);
    cpu->edi = cpu->ebp + 0xFFFFFFFDu;
    if (cpu->ecx < cpu->edi) goto label_0008C07A;
    label_0008C2F3:
    if (cpu->ecx >= cpu->ebp) goto label_0008C390;
    label_0008C2FB:
    cpu->edi = *(uint32_t*)(cpu->edx);
    x87_v3 = (double)*(float*)(cpu->esi);
    cpu->ebx = *(uint32_t*)(cpu->edi + cpu->eax);
    *(uint32_t*)(cpu->esp + 0x108u) = cpu->ebx;
    x87_v4 = (double)*(float*)(cpu->esp + 0x108u);
    cpu->ebx = *(uint32_t*)(cpu->edi + cpu->eax + 4u);
    x87_v5 = x87_v4;
    cpu->edi = *(uint32_t*)(cpu->edi + cpu->eax + 8u);
    x87_v3 = x87_v3 * x87_v5; 
    x87_v5 = (double)*(float*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->esp + 0x10Cu) = cpu->ebx;
    x87_v6 = (double)*(float*)(cpu->esp + 0x10Cu);
    *(uint32_t*)(cpu->esp + 0x110u) = cpu->edi;
    x87_v7 = x87_v6;
    cpu->edi = g_sfera_shadow_runtime.projected_points;
    x87_v5 = x87_v5 * x87_v7; 
    ++cpu->ecx;
    { double temporary = x87_v6; x87_v6 = x87_v3; x87_v3 = temporary; }
    x87_v5 = x87_v5 + x87_v6; 
    x87_v6 = (double)*(float*)(cpu->esi + 8u);
    x87_v6 = (x87_v6) * (((double)*(float*)(cpu->esp + 0x110u)));
    x87_v5 = x87_v5 + x87_v6; 
    x87_v5 = (x87_v5) + (((double)*(float*)(cpu->esi + 0xCu)));
    x87_v5 = (x87_v5) + (x87_v2);
    x87_v5 = (x87_v5) * (x87_v0);
    *(float*)(cpu->edi + (cpu->ecx * 8u) + 0xFFFFFFF8u) = x87_v5; 
    cpu->edi = g_sfera_shadow_runtime.projected_points;
    x87_v4 = (x87_v4) * (((double)*(float*)(cpu->esi + 0x10u)));
    x87_v5 = (double)*(float*)(cpu->esi + 0x14u);
    x87_v3 = x87_v3 * x87_v5; 
    x87_v3 = x87_v3 + x87_v4; 
    x87_v4 = (double)*(float*)(cpu->esi + 0x18u);
    x87_v4 = (x87_v4) * (((double)*(float*)(cpu->esp + 0x110u)));
    x87_v3 = x87_v3 + x87_v4; 
    x87_v3 = (x87_v3) + (((double)*(float*)(cpu->esi + 0x1Cu)));
    x87_v3 = (x87_v3) + (x87_v2);
    x87_v3 = (x87_v3) * (x87_v1);
    *(float*)(cpu->edi + (cpu->ecx * 8u) + 0xFFFFFFFCu) = x87_v3; 
    cpu->eax += *(uint32_t*)(cpu->edx + 4u);
    if (cpu->ecx < cpu->ebp) goto label_0008C2FB;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x2Cu);
    label_0008C390:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x134u);
    x87_v2 = x87_v2; 
    cpu->ebp = cpu->ebx;
    x87_v0 = x87_v1; 
    cpu->ebp = cpu->ebp >> 3u;
    x87_v0 = x87_v0; 
    cpu->ebp &= 0x1F0000u;
    cpu->ecx = cpu->ebx;
    cpu->ecx &= 0xFC00u;
    cpu->ebp|=cpu->ecx;
    cpu->ebp = cpu->ebp >> 2u;
    cpu->ebx &= 0xF8u;
    cpu->ebp|=cpu->ebx;
    cpu->ebp = cpu->ebp >> 3u;
    if (cpu->eax==0u) goto label_0008C54C;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi = g_sfera_shadow_runtime.projected_points;
    cpu->edx = cpu->eax + 0xFFFFFFFFu;
    cpu->edx = (uint32_t)(((uint64_t)0xAAAAAAABu * (uint32_t)(cpu->edx)) >> 32u);
    cpu->ebx = cpu->edx;
    cpu->ebx >>= 1u;
    cpu->edi += 4u;
    ++cpu->ebx;
    label_0008C3E4:
    cpu->eax = *(uint16_t*)(cpu->edi + 0xFFFFFFFCu);
    cpu->ecx = *(uint32_t*)(cpu->esi + (cpu->eax * 8u));
    cpu->edx = *(uint32_t*)(cpu->esi + (cpu->eax * 8u) + 4u);
    cpu->eax = *(uint16_t*)(cpu->edi + 0xFFFFFFFEu);
    *(uint32_t*)(cpu->esp + 0x108u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + (cpu->eax * 8u));
    x87_v0 = (double)*(float*)(cpu->esp + 0x108u);
    *(uint32_t*)(cpu->esp + 0x10Cu) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + (cpu->eax * 8u) + 4u);
    cpu->eax = *(uint16_t*)(cpu->edi);
    *(uint32_t*)(cpu->esp + 0x110u) = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + (cpu->eax * 8u));
    *(uint32_t*)(cpu->esp + 0x114u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esi + (cpu->eax * 8u) + 4u);
    *(uint32_t*)(cpu->esp + 0x118u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x11Cu) = cpu->edx;
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(float*)(cpu->esp + 0x108u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x10Cu);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(float*)(cpu->esp + 0x10Cu) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x110u);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(float*)(cpu->esp + 0x110u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x114u);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(float*)(cpu->esp + 0x114u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x118u);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(float*)(cpu->esp + 0x118u) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x11Cu);
    cpu->eax = (uint32_t)(int32_t)std::trunc(x87_v0); 
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(float*)(cpu->esp + 0x11Cu) = (double)(((int32_t)(*(uint32_t*)(cpu->esp + 0x10u))));
    x87_v0 = (double)*(float*)(cpu->esp + 0x11Cu);
    x87_v1 = (double)*(float*)(cpu->esp + 0x10Cu); x87_v2 = x87_v1;
    x87_v0 = x87_v0 - x87_v2; 
    x87_v2 = (double)*(float*)(cpu->esp + 0x110u);
    x87_v3 = (double)*(float*)(cpu->esp + 0x108u); x87_v4 = x87_v3;
    x87_v2 = x87_v2 - x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v0; x87_v0 = temporary; }
    x87_v2 = x87_v2 * x87_v3; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x114u);
    x87_v1 = x87_v3 - x87_v1; 
    x87_v3 = (double)*(float*)(cpu->esp + 0x118u);
    x87_v0 = x87_v3 - x87_v0; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 * x87_v2; 
    { const double lift_left=x87_v1; const double lift_right=x87_v0;   if (lift_left<lift_right) goto label_0008C542; }
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x13Cu);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x138u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx); lift_push32(cpu, 3u);
    cpu->edx = cpu->esp + 0x118u;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48C53Cu)); sfera_sub_0048B970(cpu, LIFT_CODE_TOKEN_VA(0x48C53Cu));
    cpu->esi = g_sfera_shadow_runtime.projected_points;
    label_0008C542:
    cpu->edi += 6u;
    if ((--cpu->ebx) != 0u) goto label_0008C3E4;
    label_0008C54C:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x114u;
    cpu->esp += 0x60u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048C570(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    x87_v0 = 1.0;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    *(float*)(cpu->esi + 0x9Cu) = x87_v0; 
    cpu->edi |= 0xFFFFFFFFu;
    cpu->edx = 0x231u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\shadow.cpp";
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ebx;
    *(uint16_t*)(cpu->esi + 0xA0u) = cpu->ebx & 0xFFFFu;
    *(uint32_t*)(cpu->esi + 0xA4u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xA8u) = cpu->edi;
    *(uint32_t*)(cpu->esi + 0xC4u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48C5BAu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48C5BAu));
    lift_push32(cpu, 0x7D4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48C5C4u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x48C5C4u));
    cpu->esp += 4u;
    cpu->edx = 0x232u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\shadow.cpp";
    *(uint32_t*)(cpu->esi + 0xCCu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48C5DCu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48C5DCu));
    lift_push32(cpu, 0x36CCu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48C5E6u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x48C5E6u));
    cpu->esp += 4u;
    cpu->edx = 0x235u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\shadow.cpp";
    *(uint32_t*)(cpu->esi + 0xC8u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48C5FEu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48C5FEu));
    lift_push32(cpu, 0x1800u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48C608u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x48C608u));
    cpu->esp += 4u;
    g_sfera_shadow_runtime.span_records = cpu->eax;
    cpu->eax = 0u;
    cpu->edx = 0x7FFFFFFFu;
    cpu->ecx = 0x80000000u;
    label_0008C620:
    cpu->ebp = g_sfera_shadow_runtime.span_records;
    *(uint32_t*)(cpu->eax + cpu->ebp + 0xCu) = cpu->edx;
    cpu->ebp = g_sfera_shadow_runtime.span_records;
    *(uint32_t*)(cpu->eax + cpu->ebp) = cpu->edx;
    cpu->ebp = g_sfera_shadow_runtime.span_records;
    *(uint32_t*)(cpu->eax + cpu->ebp + 0x10u) = cpu->ecx;
    cpu->ebp = g_sfera_shadow_runtime.span_records;
    *(uint32_t*)(cpu->eax + cpu->ebp + 4u) = cpu->ecx;
    cpu->ebp = g_sfera_shadow_runtime.span_records;
    *(uint32_t*)(cpu->eax + cpu->ebp + 8u) = cpu->edi;
    cpu->ebp = g_sfera_shadow_runtime.span_records;
    *(uint32_t*)(cpu->eax + cpu->ebp + 0x14u) = cpu->edi;
    cpu->eax += 0x18u;
    if ((int32_t)cpu->eax < (int32_t)0x1800u) goto label_0008C620;
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048C670(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->ebx = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ebx + 4u;
    cpu->edi = 3u;
    label_0008C680:
    cpu->eax = *(uint32_t*)(cpu->esi);
    if (cpu->eax == 0u) goto label_0008C694;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x8C68Eu), LIFT_CODE_TOKEN_RVA(0x8C68Cu))) { return; }
    *(uint32_t*)(cpu->esi) = 0u;
    label_0008C694:
    cpu->esi += 4u;
    if ((--cpu->edi) != 0u) goto label_0008C680;
    cpu->ecx = 0x2A000u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48C6A4u)); sfera_sub_00499F50(cpu, LIFT_CODE_TOKEN_VA(0x48C6A4u));
    if (*(uint32_t*)(cpu->ebx + 0xCCu) == cpu->edi) goto label_0008C6CA;
    cpu->edx = 0x259u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\shadow.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48C6BBu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48C6BBu));
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xCCu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48C6C7u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48C6C7u));
    cpu->esp += 4u;
    label_0008C6CA:
    if (*(uint32_t*)(cpu->ebx + 0xC8u) == 0u) goto label_0008C6F1;
    cpu->edx = 0x25Bu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\shadow.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48C6E2u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48C6E2u));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xC8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48C6EEu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48C6EEu));
    cpu->esp += 4u;
    label_0008C6F1:
    cpu->edx = 0x25Du;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\shadow.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48C700u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48C700u));
    cpu->edx = g_sfera_shadow_runtime.span_records;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48C70Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48C70Cu));
    cpu->esp += 4u;
    cpu->edx = 0x25Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\shadow.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48C71Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48C71Eu));
    cpu->eax = g_sfera_shadow_runtime.projected_points;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48C729u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48C729u));
    cpu->esp += 4u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048C730(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x2Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->esi = cpu->edi + 4u;
    cpu->ebx = cpu->esi;
    cpu->ebp = 3u;
    label_0008C750:
    cpu->eax = *(uint32_t*)(cpu->ebx);
    if (cpu->eax == 0u) goto label_0008C764;
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x8C75Eu), LIFT_CODE_TOKEN_RVA(0x8C75Cu))) { return; }
    *(uint32_t*)(cpu->ebx) = 0u;
    label_0008C764:
    cpu->ebx += 4u;
    if ((--cpu->ebp) != 0u) goto label_0008C750;
    cpu->ecx = 0x2A000u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48C774u)); sfera_sub_00499EF0(cpu, LIFT_CODE_TOKEN_VA(0x48C774u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u); lift_push32(cpu, 0x17u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 1u); lift_push32(cpu, 0x100u); lift_push32(cpu, 0x100u); lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48C792u)); sfera_sub_004D8E70(cpu, LIFT_CODE_TOKEN_VA(0x48C792u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->eax = cpu->edi + 8u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u); lift_push32(cpu, 0x17u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 1u); lift_push32(cpu, 0x80u); lift_push32(cpu, 0x80u); lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48C7B3u)); sfera_sub_004D8E70(cpu, LIFT_CODE_TOKEN_VA(0x48C7B3u));
    cpu->ecx = cpu->edi + 0xCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x17u); lift_push32(cpu, cpu->ebp); lift_push32(cpu, 1u); lift_push32(cpu, 0x40u); lift_push32(cpu, 0x40u); lift_push32(cpu, cpu->ebp);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48C7CEu)); sfera_sub_004D8E70(cpu, LIFT_CODE_TOKEN_VA(0x48C7CEu));
    cpu->ecx = (uintptr_t)"shadspot";
    *(uint32_t*)(cpu->edi + 0x10u) = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48C7DBu)); sfera_sub_00499D70(cpu, LIFT_CODE_TOKEN_VA(0x48C7DBu));
    *(uint32_t*)(cpu->edi + 0x18u) = cpu->eax;
    cpu->edi = cpu->ebp + 4u;
    label_0008C7E1:
    if (*(uint32_t*)(cpu->esi) == 0u) goto label_0008C839;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edx + 0x4Cu);
    lift_push32(cpu, 0x800u); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x8C7FEu), LIFT_CODE_TOKEN_RVA(0x8C7FCu))) { return; }
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x44u);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x8C80Fu), LIFT_CODE_TOKEN_RVA(0x8C80Du))) { return; }
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    cpu->ecx = (int64_t)(int32_t)(cpu->ecx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esp + 0x34u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx += cpu->ecx;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0xFFFFu); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x48C825u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x50u);
    cpu->esp += 0xCu;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x8C839u), LIFT_CODE_TOKEN_RVA(0x8C837u))) { return; }
    label_0008C839:
    cpu->esi += 4u;
    if ((--cpu->edi) != 0u) goto label_0008C7E1;
    cpu->eax = cpu->edi + 1u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x2Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048C860(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2, x87_v3, x87_v4, x87_v5;
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    *(float*)(cpu->esi + 0x9Cu) = x87_v0;
    lift_push32(cpu, cpu->edi);
    x87_v1 = 1.0;
    { const double lift_left=x87_v1; const double lift_right=x87_v0; x87_v0=x87_v1;  if (!(lift_left<lift_right)) goto label_0008C886; }
    *(float*)(cpu->esi + 0x9Cu) = x87_v0; 
    goto label_0008C888;
    label_0008C886:
    x87_v0 = x87_v0; 
    label_0008C888:
    x87_v0 = 0.0;
    { const double lift_left=x87_v0; const double lift_right=((double)*(float*)(cpu->esi + 0x9Cu)); if (!(lift_left>lift_right)) goto label_0008C89F; }
    *(float*)(cpu->esi + 0x9Cu) = x87_v0; 
    goto label_0008C8A1;
    label_0008C89F:
    x87_v0 = x87_v0; 
    label_0008C8A1:
    lift_push32(cpu, 0x40u);
    cpu->edi = cpu->esi + 0x5Cu;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x48C8A9u));
    x87_v0 = 1.0;
    *(float*)(cpu->edi + 0x3Cu) = x87_v0;
    cpu->esp += 0xCu;
    *(float*)(cpu->edi + 0x28u) = x87_v0;
    *(float*)(cpu->edi + 0x14u) = x87_v0;
    *(float*)(cpu->edi) = x87_v0; 
    if (*(uint8_t*)(cpu->esi + 0xA0u) != 3u) goto label_0008C913;
    x87_v0 = 0.0;
    cpu->edi = lift_pop32(cpu);
    *(float*)(cpu->esi + 0x70u) = x87_v0;
    x87_v1 = (double)-1.0f;
    *(float*)(cpu->esi + 0x80u) = x87_v1;
    *(float*)(cpu->esi + 0x74u) = x87_v1;
    *(float*)(cpu->esp + 0x18u) = x87_v1; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    *(float*)(cpu->esi + 0x84u) = x87_v0;
    *(float*)(cpu->esp + 0x14u) = x87_v0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esi + 0xACu) = cpu->eax;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esi + 0xB0u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0xB4u) = cpu->edx;
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0008C913:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esi + 0xACu) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esi + 0xB0u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esi + 0xB4u) = cpu->eax;
    { const double lift_left=(double)*(float*)(cpu->esi + 0xB0u); const double lift_right=-0.10000000149011612; if (!(lift_left>lift_right)) goto label_0008C950; }
    *(float*)(cpu->esi + 0xB0u) = (double)-0.10000000149011612f;
    label_0008C950:
    x87_v0 = (double)*(float*)(cpu->esi + 0xB0u);
    x87_v1 = (double)*(float*)(cpu->esi + 0xACu);
    x87_v2 = (double)*(float*)(cpu->esi + 0xB4u);
    x87_v3 = x87_v1;
    x87_v1 = x87_v1 * x87_v3; 
    x87_v3 = x87_v0;
    x87_v0 = x87_v0 * x87_v3; 
    { double temporary = x87_v2; x87_v2 = x87_v1; x87_v1 = temporary; }
    x87_v0 = x87_v0 + x87_v2; 
    x87_v1 = (x87_v1) * (x87_v1);
    x87_v0 = x87_v0 + x87_v1; 
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_v0 = std::sqrt(x87_v0);
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    *(float*)(cpu->esp + 0x28u) = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_v0 = (double)*(float*)(cpu->esi + 0xACu);
    x87_v1 = (double)*(float*)(cpu->esi + 0xB4u);
    x87_v0 = std::atan2(x87_v0, x87_v1); 
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    *(float*)(cpu->esp + 8u) = (-((double)*(float*)(cpu->esp + 0x2Cu)));
    x87_v0 = 0.0;
    *(float*)(cpu->esp + 0x2Cu) = x87_v0;
    x87_v1 = (double)*(float*)(cpu->esp + 0x28u); x87_v2 = x87_v1;
    { const double lift_left=x87_v2; const double lift_right=x87_v0;  x87_v0=x87_v1;  if (lift_left==lift_right) goto label_0008C9E2; }
    x87_v0 = (((double)*(float*)(cpu->esi + 0xB0u))) / (x87_v0);
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x2Cu);
    x87_v0 = std::asin(x87_v0);
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    *(float*)(cpu->esp + 0x2Cu) = (double)*(float*)(cpu->esp + 0x2Cu);
    goto label_0008C9E4;
    label_0008C9E2:
    x87_v0 = x87_v0; 
    label_0008C9E4:
    { const double lift_left=(double)*(float*)(cpu->esp + 0x2Cu); const double lift_right=-0.7853982448577881; if (!(lift_left>lift_right)) goto label_0008C9FF; }
    *(float*)(cpu->esp + 0x2Cu) = (double)-0.7853982448577881f;
    label_0008C9FF:
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    *(double*)(cpu->esp + 0x10u) = x87_v0;
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 8u) = x87_v0; 
    x87_v0 = *(double*)(cpu->esp + 0x10u);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x2Cu);
    *(double*)(cpu->esp + 0x18u) = x87_v0;
    x87_v0 = std::sin(x87_v0);
    *(float*)(cpu->esp + 0x10u) = x87_v0; 
    x87_v0 = *(double*)(cpu->esp + 0x18u);
    x87_v0 = std::cos(x87_v0);
    *(float*)(cpu->esp + 0x14u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0xCu);
    *(float*)(cpu->edi) = x87_v0;
    cpu->edi = lift_pop32(cpu);
    x87_v1 = (double)*(float*)(cpu->esp + 0xCu); x87_v2 = x87_v1;
    x87_v3 = (double)*(float*)(cpu->esp + 4u); x87_v4 = x87_v3;
    x87_v2 = x87_v2 * x87_v4; 
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esi + 0x6Cu) = x87_v3; 
    x87_v3 = x87_v2;
    x87_v3 = -x87_v3;
    x87_v4 = (double)*(float*)(cpu->esp + 0x10u); x87_v5 = x87_v4;
    x87_v3 = x87_v3 * x87_v5; 
    { double temporary = x87_v4; x87_v4 = x87_v3; x87_v3 = temporary; }
    *(float*)(cpu->esi + 0x7Cu) = x87_v4; 
    *(float*)(cpu->esi + 0x70u) = x87_v3;
    { double temporary = x87_v3; x87_v3 = x87_v1; x87_v1 = temporary; }
    *(float*)(cpu->esi + 0x80u) = x87_v3;
    { double temporary = x87_v3; x87_v3 = x87_v2; x87_v2 = temporary; }
    *(float*)(cpu->esi + 0x64u) = x87_v3; 
    x87_v2 = -x87_v2;
    x87_v2 = (x87_v2) * (x87_v0);
    *(float*)(cpu->esi + 0x74u) = x87_v2; 
    x87_v0 = x87_v0 * x87_v1; 
    *(float*)(cpu->esi + 0x84u) = x87_v0; 
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048CA90(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2; double x87_p0, x87_p1, x87_p2, x87_p3, x87_p4, x87_p5;
    cpu->esp -= 0x4Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x5Cu);
    cpu->eax = *(uint32_t*)(cpu->esi + 4u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x64u);
    cpu->ebx = cpu->ecx;
    cpu->ecx = g_sfera_model_runtime.repository;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48CABBu)); sfera_sub_0047F4D0(cpu, LIFT_CODE_TOKEN_VA(0x48CABBu));
    cpu->ebp = cpu->eax;
    if (cpu->edi == 0u) goto label_0008CACF;
    cpu->edx = *(uint32_t*)(cpu->edi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edi);
    cpu->eax = *(uint32_t*)(cpu->edi + 8u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    goto label_0008CAEA;
    label_0008CACF:
    cpu->edx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edx;
    *(float*)(cpu->esp + 0x14u) = ((((double)*(float*)(cpu->esp + 0x14u))) - (0.800000011920929));
    label_0008CAEA:
    *(uint32_t*)(cpu->ebx + 0xC4u) = 0u;
    x87_v0 = (double)*(float*)(cpu->ebx + 0xACu);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ecx;
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x10u)));
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esp + 0x20u) = ((((double)*(float*)(cpu->ebx + 0xB0u))) + (((double)*(float*)(cpu->esp + 0x14u))));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    x87_v0 = (double)*(float*)(cpu->ebx + 0xB4u);
    *(uint32_t*)(cpu->ebx + 0xB8u) = cpu->ecx;
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x18u)));
    *(uint32_t*)(cpu->ebx + 0xBCu) = cpu->edx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebx + 0xA0u));
    *(uint32_t*)(cpu->ebx + 0x14u) = cpu->esi;
    *(float*)(cpu->esp + 0x24u) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->ebx + 0xC0u) = cpu->eax;
    if ((cpu->edx & 0xFFu) != 4u) goto label_0008CB6C;
    label_0008CB52:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x4Cu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_0008CB6C:
    x87_v0 = (double)*(float*)(cpu->ebx + 0x9Cu);
    x87_v1 = 1.0;
    x87_v2 = x87_v1;
    x87_v0 = x87_v2 - x87_v0; 
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->esp + 0x68u)));
    cpu->eax = 0xE7Fu;
    x87_v0 = x87_v0 * x87_v1; 
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->ebx + 0x9Cu)));
    x87_v0 = (x87_v0) * (255.0);
    *(uint64_t*)(cpu->esp + 0x1Cu) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->ecx >= 0xFFu) goto label_0008CB52;
    cpu->esi = cpu->ecx;
    cpu->esi |= 0xFFFFFF00u;
    cpu->eax = cpu->ecx;
    cpu->eax&=0xFFu;
    cpu->esi <<= 8u;
    cpu->esi|=cpu->eax;
    cpu->esi <<= 8u;
    cpu->esi |= cpu->eax;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->eax -= cpu->ecx;
    cpu->ecx = cpu->eax;
    cpu->eax|=0xFFFFFF00u;
    cpu->eax <<= 8u;
    cpu->ecx &= 0xFFu;
    cpu->eax|=cpu->ecx;
    cpu->eax <<= 8u;
    cpu->eax |= cpu->ecx;
    *(uint32_t*)(cpu->ebx + 0xA4u) = cpu->esi;
    *(uint32_t*)(cpu->ebx + 0xA8u) = cpu->eax;
    if ((cpu->edx & 0xFFu) != 3u) goto label_0008CC7E;
    if (*(uint32_t*)(cpu->ebx + 0x18u) != 0xFFFFFFFFu) goto label_0008CC1B;
    label_0008CC04:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x4Cu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_0008CC1B:
    lift_push32(cpu, 0x40u);
    cpu->esi = cpu->ebx + 0x1Cu;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x48CC23u));
    x87_v0 = (double)*(float*)(cpu->ebp + 0x1B8u);
    x87_v1 = 1.0;
    cpu->esp += 0xCu;
    x87_v0 = x87_v1 / x87_v0; 
    *(float*)(cpu->esp + 0x1Cu) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->esi) = x87_v0;
    x87_v1 = x87_v0;
    x87_v1 = -x87_v1;
    *(float*)(cpu->esp + 0x1Cu) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x1Cu);
    *(float*)(cpu->ebx + 0x40u) = x87_v1;
    *(float*)(cpu->ebx + 0x34u) = x87_v1;
    *(float*)(cpu->ebx + 0x58u) = (double)(1.0);
    x87_v2 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v2 = -x87_v2;
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->ebx + 0x28u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x18u);
    x87_v1 = -x87_v1;
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->ebx + 0x38u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v1 = -x87_v1;
    x87_v0 = x87_v0 * x87_v1; 
    *(float*)(cpu->ebx + 0x48u) = x87_v0; 
    goto label_0008CDED;
    label_0008CC7E:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((cpu->edx & 0xFFu) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(*(uint8_t*)(cpu->esp + 0x6Cu)) + (uint64_t)(0u))) & 0xFFu);
    *(uint8_t*)(cpu->ebx + 0xA1u) = cpu->eax & 0xFFu;
    if ((cpu->eax & 0xFFu) <= 2u) goto label_0008CC95;
    *(uint8_t*)(cpu->ebx + 0xA1u) = 2u;
    label_0008CC95:
    cpu->ecx = *(uint8_t*)(cpu->ebx + 0xA1u);
    cpu->eax = cpu->ebx + (cpu->ecx * 4u) + 4u;
    if (*(uint32_t*)(cpu->ebx + (cpu->ecx * 4u) + 4u) == 0u) goto label_0008CC04;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edx + 0x4Cu);
    lift_push32(cpu, 0x800u); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x8CCC3u), LIFT_CODE_TOKEN_RVA(0x8CCC1u))) { return; }
    cpu->eax = *(uint8_t*)(cpu->ebx + 0xA1u);
    cpu->eax = *(uint32_t*)(cpu->ebx + (cpu->eax * 4u) + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x44u);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x8CCDDu), LIFT_CODE_TOKEN_RVA(0x8CCDBu))) { return; }
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    if (cpu->eax == 0u) goto label_0008CC04;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x50u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esp + 0x54u));
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx);
    std::memmove((void*)(cpu->ebx + 0x120u),(void*)(cpu->esp + 0x3Cu),32u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    lift_push32(cpu, 0xFFFFu); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebx + 0x140u) = cpu->ecx;
    *(uint32_t*)(cpu->ebx + 0x144u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x48CD1Cu));
    cpu->eax = cpu->ebp;
    std::memmove((void*)(cpu->ebx + 0x1Cu),(void*)(cpu->ebx + 0x5Cu),64u);
    *(float*)(cpu->esp + 8u) = (double)*(float*)(cpu->eax + 0x1B4u);
    *(float*)(cpu->esp + 4u) = (double)*(float*)(cpu->eax + 0x1B4u);
    *(float*)(cpu->esp) = (double)*(float*)(cpu->eax + 0x1B4u);
    cpu->ecx = cpu->ebx + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48CD55u)); sfera_sub_0041A010(cpu, LIFT_CODE_TOKEN_VA(0x48CD55u));
    *(float*)(cpu->esp + 0x1Cu) = (-((double)*(float*)(cpu->esp + 0x10u)));
    *(float*)(cpu->esp + 0x2Cu) = (-((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esp + 0x28u) = (-((double)*(float*)(cpu->esp + 0x18u)));
    x87_p0 = (double)*(float*)(cpu->ebx + 0x20u);
    x87_p1 = (double)*(float*)(cpu->esp + 0x2Cu); x87_p2 = x87_p1;
    x87_p0 = x87_p0 * x87_p2; 
    x87_p2 = (double)*(float*)(cpu->ebx + 0x1Cu);
    x87_p3 = (double)*(float*)(cpu->esp + 0x1Cu); x87_p4 = x87_p3;
    x87_p2 = x87_p2 * x87_p4; 
    { double temporary = x87_p3; x87_p3 = x87_p0; x87_p0 = temporary; }
    x87_p2 = x87_p2 + x87_p3; 
    x87_p3 = (double)*(float*)(cpu->ebx + 0x24u);
    x87_p4 = (double)*(float*)(cpu->esp + 0x28u); x87_p5 = x87_p4;
    x87_p3 = x87_p3 * x87_p5; 
    { double temporary = x87_p4; x87_p4 = x87_p2; x87_p2 = temporary; }
    x87_p3 = x87_p3 + x87_p4; 
    x87_p3 = (x87_p3) + (((double)*(float*)(cpu->ebx + 0x28u)));
    *(float*)(cpu->ebx + 0x28u) = x87_p3; 
    x87_p3 = (double)*(float*)(cpu->ebx + 0x30u);
    x87_p3 = (x87_p3) * (x87_p1);
    x87_p4 = (double)*(float*)(cpu->ebx + 0x2Cu);
    x87_p4 = (x87_p4) * (x87_p0);
    x87_p3 = x87_p3 + x87_p4; 
    x87_p4 = (double)*(float*)(cpu->ebx + 0x34u);
    x87_p4 = (x87_p4) * (x87_p2);
    x87_p3 = x87_p3 + x87_p4; 
    x87_p3 = (x87_p3) + (((double)*(float*)(cpu->ebx + 0x38u)));
    *(float*)(cpu->ebx + 0x38u) = x87_p3; 
    x87_p3 = (double)*(float*)(cpu->ebx + 0x40u);
    x87_p3 = (x87_p3) * (x87_p1);
    x87_p4 = (double)*(float*)(cpu->ebx + 0x3Cu);
    x87_p4 = (x87_p4) * (x87_p0);
    x87_p3 = x87_p3 + x87_p4; 
    x87_p4 = (double)*(float*)(cpu->ebx + 0x44u);
    x87_p4 = (x87_p4) * (x87_p2);
    x87_p3 = x87_p3 + x87_p4; 
    x87_p3 = (x87_p3) + (((double)*(float*)(cpu->ebx + 0x48u)));
    *(float*)(cpu->ebx + 0x48u) = x87_p3; 
    x87_p3 = (double)*(float*)(cpu->ebx + 0x50u);
    x87_p1 = x87_p1 * x87_p3; 
    x87_p3 = (double)*(float*)(cpu->ebx + 0x4Cu);
    x87_p0 = x87_p0 * x87_p3; 
    { double temporary = x87_p2; x87_p2 = x87_p1; x87_p1 = temporary; }
    x87_p0 = x87_p0 + x87_p2; 
    x87_p1 = (x87_p1) * (((double)*(float*)(cpu->ebx + 0x54u)));
    x87_p0 = x87_p0 + x87_p1; 
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->ebx + 0x58u)));
    *(float*)(cpu->ebx + 0x58u) = x87_p0; 
    label_0008CDED:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x58u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 0xC4u) = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x4Cu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048CE10(LiftCpu* cpu, uint32_t stop_address) { double x87_v0, x87_v1, x87_v2; double x87_p0, x87_p1, x87_p2, x87_p3, x87_p4, x87_p5;
    cpu->esp -= 0x44u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x4Cu);
    if (cpu->eax == 0u) goto label_0008CE43;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->eax + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    goto label_0008CE66;
    label_0008CE43:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xCu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    x87_v0 = (double)*(float*)(cpu->esp + 0xCu);
    x87_v0 = (x87_v0) - (0.800000011920929);
    *(uint32_t*)(cpu->esp + 8u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x10u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    *(float*)(cpu->esp + 0xCu) = x87_v0; 
    label_0008CE66:
    *(uint32_t*)(cpu->ebx + 0xC4u) = 0u;
    *(float*)(cpu->esp + 0x18u) = ((((double)*(float*)(cpu->ebx + 0xACu))) + (((double)*(float*)(cpu->esp + 8u))));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    *(float*)(cpu->esp + 0x1Cu) = ((((double)*(float*)(cpu->ebx + 0xB0u))) + (((double)*(float*)(cpu->esp + 0xCu))));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    x87_v0 = (double)*(float*)(cpu->ebx + 0xB4u);
    *(uint32_t*)(cpu->ebx + 0xB8u) = cpu->eax;
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x10u)));
    *(uint32_t*)(cpu->ebx + 0xBCu) = cpu->edx;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ebx + 0xA0u));
    *(uint32_t*)(cpu->ebx + 0x14u) = cpu->ecx;
    *(float*)(cpu->esp + 0x20u) = x87_v0; 
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->ebx + 0xC0u) = cpu->eax;
    if ((cpu->edx & 0xFFu) != 4u) goto label_0008CEDA;
    label_0008CEC6:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x44u;
    cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
    label_0008CEDA:
    x87_v0 = (double)*(float*)(cpu->esp + 0x54u);
    x87_v1 = 1.0;
    x87_v2 = x87_v1;
    x87_v0 = x87_v2 - x87_v0; 
    x87_v1 = (x87_v1) - (((double)*(float*)(cpu->ebx + 0x9Cu)));
    cpu->eax = 0xE7Fu;
    x87_v0 = x87_v0 * x87_v1; 
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->ebx + 0x9Cu)));
    x87_v0 = (x87_v0) * (255.0);
    *(uint64_t*)(cpu->esp + 0x18u) = static_cast<int64_t>(std::trunc(x87_v0));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    if (cpu->ecx >= 0xFFu) goto label_0008CEC6;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->esi |= 0xFFFFFF00u;
    cpu->eax = cpu->ecx;
    cpu->eax&=0xFFu;
    cpu->esi <<= 8u;
    cpu->esi|=cpu->eax;
    cpu->esi <<= 8u;
    cpu->esi |= cpu->eax;
    cpu->eax |= 0xFFFFFFFFu;
    cpu->eax -= cpu->ecx;
    cpu->ecx = cpu->eax;
    cpu->eax|=0xFFFFFF00u;
    cpu->eax <<= 8u;
    cpu->ecx &= 0xFFu;
    cpu->eax|=cpu->ecx;
    cpu->eax <<= 8u;
    cpu->eax |= cpu->ecx;
    *(uint32_t*)(cpu->ebx + 0xA4u) = cpu->esi;
    *(uint32_t*)(cpu->ebx + 0xA8u) = cpu->eax;
    if ((cpu->edx & 0xFFu) != 3u) goto label_0008CFD4;
    if (*(uint32_t*)(cpu->ebx + 0x18u) == 0xFFFFFFFFu) goto label_0008D037;
    lift_push32(cpu, 0x40u);
    cpu->esi = cpu->ebx + 0x1Cu;
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->esi);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x48CF7Bu));
    x87_v0 = (double)*(float*)(cpu->esp + 0x70u);
    x87_v1 = 1.0;
    cpu->esp += 0xCu;
    x87_v0 = x87_v1 / x87_v0; 
    *(float*)(cpu->esp + 8u) = x87_v0; 
    x87_v0 = (double)*(float*)(cpu->esp + 8u);
    *(float*)(cpu->esi) = x87_v0;
    x87_v1 = x87_v0;
    x87_v1 = -x87_v1;
    *(float*)(cpu->esp + 8u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 8u);
    *(float*)(cpu->ebx + 0x40u) = x87_v1;
    *(float*)(cpu->ebx + 0x34u) = x87_v1;
    *(float*)(cpu->ebx + 0x58u) = (double)(1.0);
    x87_v2 = (double)*(float*)(cpu->esp + 0xCu);
    x87_v2 = -x87_v2;
    x87_v0 = x87_v0 * x87_v2; 
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->ebx + 0x28u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x14u);
    x87_v1 = -x87_v1;
    x87_v1 = (x87_v1) * (x87_v0);
    *(float*)(cpu->ebx + 0x38u) = x87_v1; 
    x87_v1 = (double)*(float*)(cpu->esp + 0x10u);
    x87_v1 = -x87_v1;
    x87_v0 = x87_v0 * x87_v1; 
    *(float*)(cpu->ebx + 0x48u) = x87_v0; 
    goto label_0008D144;
    label_0008CFD4:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((cpu->edx & 0xFFu) & 0xFFu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) + (uint64_t)(*(uint8_t*)(cpu->esp + 0x5Cu)) + (uint64_t)(0u))) & 0xFFu);
    *(uint8_t*)(cpu->ebx + 0xA1u) = cpu->eax & 0xFFu;
    if ((cpu->eax & 0xFFu) <= 2u) goto label_0008CFEB;
    *(uint8_t*)(cpu->ebx + 0xA1u) = 2u;
    label_0008CFEB:
    cpu->ecx = *(uint8_t*)(cpu->ebx + 0xA1u);
    cpu->eax = cpu->ebx + (cpu->ecx * 4u) + 4u;
    if (*(uint32_t*)(cpu->ebx + (cpu->ecx * 4u) + 4u) == 0u) goto label_0008D037;
    cpu->eax = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->eax);
    cpu->edx = *(uint32_t*)(cpu->edx + 0x4Cu);
    lift_push32(cpu, 0x800u); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edx, LIFT_CODE_TOKEN_RVA(0x8D015u), LIFT_CODE_TOKEN_RVA(0x8D013u))) { return; }
    cpu->eax = *(uint8_t*)(cpu->ebx + 0xA1u);
    cpu->eax = *(uint32_t*)(cpu->ebx + (cpu->eax * 4u) + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x44u);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x8D02Fu), LIFT_CODE_TOKEN_RVA(0x8D02Du))) { return; }
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    if (cpu->eax != 0u) goto label_0008D04C;
    label_0008D037:
    cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x44u;
    cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
    label_0008D04C:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x40u);
    cpu->edx = (int64_t)(int32_t)(cpu->edx) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esp + 0x44u));
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx);
    std::memmove((void*)(cpu->ebx + 0x120u),(void*)(cpu->esp + 0x34u),32u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, 0xFFFFu); lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->ebx + 0x140u) = cpu->ecx;
    *(uint32_t*)(cpu->ebx + 0x144u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x48D081u));
    x87_p0 = (double)*(float*)(cpu->esp + 0x74u);
    *(float*)(cpu->esp + 8u) = x87_p0;
    std::memmove((void*)(cpu->ebx + 0x1Cu),(void*)(cpu->ebx + 0x5Cu),64u);
    *(float*)(cpu->esp + 4u) = x87_p0;
    *(float*)(cpu->esp) = x87_p0; 
    cpu->ecx = cpu->ebx + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D0AAu)); sfera_sub_0041A010(cpu, LIFT_CODE_TOKEN_VA(0x48D0AAu));
    *(float*)(cpu->esp + 0x20u) = (-((double)*(float*)(cpu->esp + 0x14u)));
    *(float*)(cpu->esp + 0x10u) = (-((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->esp + 0x24u) = (-((double)*(float*)(cpu->esp + 0x1Cu)));
    x87_p0 = (double)*(float*)(cpu->ebx + 0x20u);
    x87_p1 = (double)*(float*)(cpu->esp + 0x10u); x87_p2 = x87_p1;
    x87_p0 = x87_p0 * x87_p2; 
    x87_p2 = (double)*(float*)(cpu->ebx + 0x1Cu);
    x87_p3 = (double)*(float*)(cpu->esp + 0x20u); x87_p4 = x87_p3;
    x87_p2 = x87_p2 * x87_p4; 
    { double temporary = x87_p3; x87_p3 = x87_p0; x87_p0 = temporary; }
    x87_p2 = x87_p2 + x87_p3; 
    x87_p3 = (double)*(float*)(cpu->ebx + 0x24u);
    x87_p4 = (double)*(float*)(cpu->esp + 0x24u); x87_p5 = x87_p4;
    x87_p3 = x87_p3 * x87_p5; 
    { double temporary = x87_p4; x87_p4 = x87_p2; x87_p2 = temporary; }
    x87_p3 = x87_p3 + x87_p4; 
    x87_p3 = (x87_p3) + (((double)*(float*)(cpu->ebx + 0x28u)));
    *(float*)(cpu->ebx + 0x28u) = x87_p3; 
    x87_p3 = (double)*(float*)(cpu->ebx + 0x30u);
    x87_p3 = (x87_p3) * (x87_p1);
    x87_p4 = (double)*(float*)(cpu->ebx + 0x2Cu);
    x87_p4 = (x87_p4) * (x87_p0);
    x87_p3 = x87_p3 + x87_p4; 
    x87_p4 = (double)*(float*)(cpu->ebx + 0x34u);
    x87_p4 = (x87_p4) * (x87_p2);
    x87_p3 = x87_p3 + x87_p4; 
    x87_p3 = (x87_p3) + (((double)*(float*)(cpu->ebx + 0x38u)));
    *(float*)(cpu->ebx + 0x38u) = x87_p3; 
    x87_p3 = (double)*(float*)(cpu->ebx + 0x40u);
    x87_p3 = (x87_p3) * (x87_p1);
    x87_p4 = (double)*(float*)(cpu->ebx + 0x3Cu);
    x87_p4 = (x87_p4) * (x87_p0);
    x87_p3 = x87_p3 + x87_p4; 
    x87_p4 = (double)*(float*)(cpu->ebx + 0x44u);
    x87_p4 = (x87_p4) * (x87_p2);
    x87_p3 = x87_p3 + x87_p4; 
    x87_p3 = (x87_p3) + (((double)*(float*)(cpu->ebx + 0x48u)));
    *(float*)(cpu->ebx + 0x48u) = x87_p3; 
    x87_p3 = (double)*(float*)(cpu->ebx + 0x50u);
    x87_p1 = x87_p1 * x87_p3; 
    x87_p3 = (double)*(float*)(cpu->ebx + 0x4Cu);
    x87_p0 = x87_p0 * x87_p3; 
    { double temporary = x87_p2; x87_p2 = x87_p1; x87_p1 = temporary; }
    x87_p0 = x87_p0 + x87_p2; 
    x87_p1 = (x87_p1) * (((double)*(float*)(cpu->ebx + 0x54u)));
    x87_p0 = x87_p0 + x87_p1; 
    x87_p0 = (x87_p0) + (((double)*(float*)(cpu->ebx + 0x58u)));
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(float*)(cpu->ebx + 0x58u) = x87_p0; 
    label_0008D144:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x48u);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 0xC4u) = cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x44u;
    cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048D170(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0;
    cpu->esp -= 0x90u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x98u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xA4u);
    cpu->ebx = cpu->ecx;
    sub_pred[0] = *(uint8_t*)(cpu->ebx + 0xA0u) < 3u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edi;
    if (!sub_pred[0]) goto label_0008D366;
    if (*(uint32_t*)(cpu->ebx + 0xC4u) == 0u) goto label_0008D366;
    cpu->ecx = *(uint8_t*)(cpu->ebx + 0xA1u);
    if (*(uint32_t*)(cpu->ebx + (cpu->ecx * 4u) + 4u) == 0u) goto label_0008D366;
    cpu->esi = *(uint32_t*)(cpu->esp + 0xACu);
    cpu->edx = cpu->eax + (cpu->eax * 8u);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x34u);
    cpu->ebp = cpu->eax + (cpu->edx * 2u);
    if (cpu->esi == 0u) goto label_0008D29C;
    std::memmove((void*)(cpu->esp + 0x5Cu),(void*)(cpu->esi),64u); cpu->esi += 64u;
    *(float*)(cpu->esp + 0x1Cu) = (double)*(float*)(cpu->esp + 0x5Cu);
    *(float*)(cpu->esp + 0x20u) = (double)*(float*)(cpu->esp + 0x6Cu);
    *(float*)(cpu->esp + 0x24u) = (double)*(float*)(cpu->esp + 0x7Cu);
    *(float*)(cpu->esp + 0x28u) = (double)*(float*)(cpu->esp + 0x8Cu);
    *(float*)(cpu->esp + 0x2Cu) = (double)*(float*)(cpu->esp + 0x60u);
    *(float*)(cpu->esp + 0x30u) = (double)*(float*)(cpu->esp + 0x70u);
    cpu->ecx = cpu->esp + 0x1Cu;
    x87_v0 = (double)*(float*)(cpu->esp + 0x80u);
    lift_push32(cpu, cpu->ecx);
    *(float*)(cpu->esp + 0x38u) = x87_v0; 
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    x87_v0 = (double)*(float*)(cpu->esp + 0x94u);
    lift_push32(cpu, 0x100u);
    *(float*)(cpu->esp + 0x40u) = x87_v0; 
    *(float*)(cpu->esp + 0x44u) = (double)*(float*)(cpu->esp + 0x6Cu);
    *(float*)(cpu->esp + 0x48u) = (double)*(float*)(cpu->esp + 0x7Cu);
    *(float*)(cpu->esp + 0x4Cu) = (double)*(float*)(cpu->esp + 0x8Cu);
    *(float*)(cpu->esp + 0x50u) = (double)*(float*)(cpu->esp + 0x9Cu);
    *(float*)(cpu->esp + 0x54u) = (double)*(float*)(cpu->esp + 0x70u);
    *(float*)(cpu->esp + 0x58u) = (double)*(float*)(cpu->esp + 0x80u);
    *(float*)(cpu->esp + 0x5Cu) = (double)*(float*)(cpu->esp + 0x90u);
    *(float*)(cpu->esp + 0x60u) = (double)*(float*)(cpu->esp + 0xA0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D298u)); sfera_sub_004D88E0(cpu, LIFT_CODE_TOKEN_VA(0x48D298u));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    label_0008D29C:
    cpu->eax = *(uint16_t*)(cpu->ebp + 8u);
    cpu->edx = cpu->eax + (cpu->eax * 8u);
    cpu->eax = *(uint32_t*)(cpu->edi + 0x24u);
    cpu->ecx = cpu->eax + (cpu->edx * 4u);
    cpu->edx = *(uint16_t*)(cpu->ebp + 6u);
    cpu->eax = cpu->edx + (cpu->edx * 2u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = 0x24u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)0x3EAu) goto label_0008D2D4;
    cpu->edx = 0x14Eu;
    *(uint32_t*)(cpu->esp + 0x10u) = 0x3EAu;
    label_0008D2D4:
    cpu->ecx = *(uint16_t*)(cpu->ebp + 4u);
    cpu->esi = *(uint32_t*)(cpu->edi + 0x2Cu);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xCCu);
    cpu->ecx = cpu->ecx + (cpu->ecx * 2u);
    cpu->ecx = cpu->esi + (cpu->ecx * 4u);
    if ((int32_t)cpu->edx <= 0) goto label_0008D30F;
    label_0008D2F0:
    cpu->esi = *(uint16_t*)(cpu->ecx);
    *(uint16_t*)(cpu->eax) = cpu->esi & 0xFFFFu;
    cpu->esi = *(uint16_t*)(cpu->ecx + 4u);
    *(uint16_t*)(cpu->eax + 2u) = cpu->esi & 0xFFFFu;
    cpu->esi = *(uint16_t*)(cpu->ecx + 2u);
    *(uint16_t*)(cpu->eax + 4u) = cpu->esi & 0xFFFFu;
    cpu->eax += 6u;
    cpu->ecx += 0xCu;
    if ((--cpu->edx) != 0u) goto label_0008D2F0;
    label_0008D30F:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D31Fu)); sfera_sub_004D8950(cpu, LIFT_CODE_TOKEN_VA(0x48D31Fu));
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x138u);
    cpu->esp -= 0x40u;
    std::memmove((void*)(cpu->esp),(void*)(cpu->eax),64u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x13Cu);
    cpu->eax = cpu->ebx + 0x140u;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xCCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint16_t*)(cpu->ebp + 0xAu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xA4u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x6Cu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8D366u)); sfera_sub_0048BE40(cpu, LIFT_CODE_TOKEN_RVA(0x8D366u));
    label_0008D366:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x90u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048D390(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x4Cu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x60u);
    cpu->ebx = cpu->ecx;
    sub_pred[0] = *(uint8_t*)(cpu->ebx + 0xA0u) < 3u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if (!sub_pred[0]) goto label_0008D42F;
    if (*(uint32_t*)(cpu->ebx + 0xC4u) == 0u) goto label_0008D42F;
    cpu->ecx = *(uint8_t*)(cpu->ebx + 0xA1u);
    if (*(uint32_t*)(cpu->ebx + (cpu->ecx * 4u) + 4u) == 0u) goto label_0008D42F;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D3E8u)); sfera_sub_004D8950(cpu, LIFT_CODE_TOKEN_VA(0x48D3E8u));
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x138u);
    cpu->esp -= 0x40u;
    std::memmove((void*)(cpu->esp),(void*)(cpu->eax),64u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x13Cu);
    cpu->eax = cpu->ebx + 0x140u;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0xB0u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xACu);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xA4u);
    cpu->edx = cpu->esp + 0x68u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->ebx + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8D42Fu)); sfera_sub_0048BE40(cpu, LIFT_CODE_TOKEN_RVA(0x8D42Fu));
    label_0008D42F:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x4Cu;
    cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048D450(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x50u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x60u);
    cpu->ebx = cpu->ecx;
    sub_pred[0] = *(uint8_t*)(cpu->ebx + 0xA0u) < 3u;
    lift_push32(cpu, cpu->edi);
    if (!sub_pred[0]) goto label_0008D566;
    if (*(uint32_t*)(cpu->ebx + 0xC4u) == 0u) goto label_0008D566;
    cpu->ecx = *(uint8_t*)(cpu->ebx + 0xA1u);
    if (*(uint32_t*)(cpu->ebx + (cpu->ecx * 4u) + 4u) == 0u) goto label_0008D566;
    cpu->edx = cpu->eax + (cpu->eax * 8u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x34u);
    cpu->ebp = cpu->eax + (cpu->edx * 2u);
    cpu->eax = *(uint16_t*)(cpu->ebp + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x24u);
    cpu->ecx = cpu->eax + (cpu->eax * 8u);
    cpu->eax = cpu->edx + (cpu->ecx * 4u);
    cpu->edx = *(uint16_t*)(cpu->ebp + 6u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = cpu->edx + (cpu->edx * 2u);
    *(uint32_t*)(cpu->esp + 0x18u) = 0x24u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)0x3EAu) goto label_0008D4D9;
    cpu->edx = 0x14Eu;
    *(uint32_t*)(cpu->esp + 0x10u) = 0x3EAu;
    label_0008D4D9:
    cpu->ecx = *(uint16_t*)(cpu->ebp + 4u);
    cpu->esi = *(uint32_t*)(cpu->esi + 0x2Cu);
    cpu->eax = *(uint32_t*)(cpu->ebx + 0xCCu);
    cpu->ecx = cpu->ecx + (cpu->ecx * 2u);
    cpu->ecx = cpu->esi + (cpu->ecx * 4u);
    if ((int32_t)cpu->edx <= 0) goto label_0008D50F;
    label_0008D4F0:
    cpu->esi = *(uint16_t*)(cpu->ecx);
    *(uint16_t*)(cpu->eax) = cpu->esi & 0xFFFFu;
    cpu->esi = *(uint16_t*)(cpu->ecx + 4u);
    *(uint16_t*)(cpu->eax + 2u) = cpu->esi & 0xFFFFu;
    cpu->esi = *(uint16_t*)(cpu->ecx + 2u);
    *(uint16_t*)(cpu->eax + 4u) = cpu->esi & 0xFFFFu;
    cpu->eax += 6u;
    cpu->ecx += 0xCu;
    if ((--cpu->edx) != 0u) goto label_0008D4F0;
    label_0008D50F:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D51Fu)); sfera_sub_004D8950(cpu, LIFT_CODE_TOKEN_VA(0x48D51Fu));
    cpu->edx = *(uint32_t*)(cpu->ebx + 0x138u);
    cpu->esp -= 0x40u;
    std::memmove((void*)(cpu->esp),(void*)(cpu->eax),64u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0x13Cu);
    cpu->eax = cpu->ebx + 0x140u;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x54u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xCCu);
    lift_push32(cpu, cpu->edx);
    cpu->edx = *(uint16_t*)(cpu->ebp + 0xAu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 0xA4u);
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x6Cu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8D566u)); sfera_sub_0048BE40(cpu, LIFT_CODE_TOKEN_RVA(0x8D566u));
    label_0008D566:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x50u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048D580(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1]; double x87_v0, x87_v1;
    cpu->esp -= 0x54u;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0xC4u) == 0u) goto label_0008D9BB;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = 3u;
    lift_push32(cpu, cpu->edi);
    if (*(uint8_t*)(cpu->esi + 0xA0u) >= (cpu->ebx & 0xFFu)) goto label_0008D6A7;
    cpu->eax = *(uint8_t*)(cpu->esi + 0xA1u);
    if (*(uint32_t*)(cpu->esi + (cpu->eax * 4u) + 4u) == 0u) goto label_0008D9B9;
    if (*(uint8_t*)(cpu->esi) == 0u) goto label_0008D5E4;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x13Cu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x138u);
    cpu->eax = cpu->esi + 0x140u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8D5E4u)); sfera_sub_0048BDB0(cpu, LIFT_CODE_TOKEN_RVA(0x8D5E4u));
    label_0008D5E4:
    std::fill_n((uint16_t*)(*(uint32_t*)(cpu->esi + 0x144u)),(*(uint32_t*)(cpu->esi + 0x138u)),(uint16_t)0xFFFFu);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x13Cu);
    --cpu->edi;
    cpu->edi = (int64_t)(int32_t)(cpu->edi) * (int64_t)(int32_t)(*(uint32_t*)(cpu->esi + 0x140u));
    cpu->edi += *(uint32_t*)(cpu->esi + 0x144u);
    std::fill_n((uint16_t*)(cpu->edi),(*(uint32_t*)(cpu->esi + 0x138u)),(uint16_t)0xFFFFu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0x13Cu);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x138u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x144u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x140u);
    cpu->eax = cpu->edi + (cpu->eax * 2u) + 0xFFFFFFFEu;
    if (cpu->edx == 0u) goto label_0008D66F;
    label_0008D662:
    cpu->edi = 0xFFFFu;
    *(uint16_t*)(cpu->eax) = cpu->edi & 0xFFFFu;
    cpu->eax += cpu->ecx;
    if ((--cpu->edx) != 0u) goto label_0008D662;
    label_0008D66F:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x13Cu);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x140u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x144u);
    if (cpu->edx == 0u) goto label_0008D692;
    label_0008D685:
    cpu->edi = 0xFFFFu;
    *(uint16_t*)(cpu->eax) = cpu->edi & 0xFFFFu;
    cpu->eax += cpu->ecx;
    if ((--cpu->edx) != 0u) goto label_0008D685;
    label_0008D692:
    cpu->ecx = *(uint8_t*)(cpu->esi + 0xA1u);
    cpu->eax = *(uint32_t*)(cpu->esi + (cpu->ecx * 4u) + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x50u);
    if (!lift_call_indirect(cpu, cpu->eax, LIFT_CODE_TOKEN_RVA(0x8D6A7u), LIFT_CODE_TOKEN_RVA(0x8D6A5u))) { return; }
    label_0008D6A7:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x68u);
    if (cpu->edi == 0u) goto label_0008D9B9;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u);
    *(uint32_t*)(cpu->esi + 0xC4u) = 0u;
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D6CEu)); sfera_sub_004D8790(cpu, LIFT_CODE_TOKEN_VA(0x48D6CEu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 2u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D6DEu)); sfera_sub_004D8790(cpu, LIFT_CODE_TOKEN_VA(0x48D6DEu));
    x87_v0 = 0.0;
    *(float*)(cpu->esp + 0x58u) = x87_v0;
    cpu->ecx = cpu->esp + 0x20u;
    *(float*)(cpu->esp + 0x54u) = x87_v0;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    *(float*)(cpu->esp + 0x54u) = x87_v0;
    *(float*)(cpu->esp + 0x50u) = x87_v0;
    lift_push32(cpu, 0x100u);
    *(float*)(cpu->esp + 0x4Cu) = x87_v0;
    *(float*)(cpu->esp + 0x48u) = x87_v0;
    *(float*)(cpu->esp + 0x44u) = x87_v0;
    *(float*)(cpu->esp + 0x40u) = x87_v0;
    *(float*)(cpu->esp + 0x38u) = x87_v0;
    *(float*)(cpu->esp + 0x34u) = x87_v0;
    *(float*)(cpu->esp + 0x30u) = x87_v0;
    *(float*)(cpu->esp + 0x2Cu) = x87_v0; 
    x87_v0 = 1.0;
    *(float*)(cpu->esp + 0x64u) = x87_v0;
    *(float*)(cpu->esp + 0x50u) = x87_v0;
    *(float*)(cpu->esp + 0x3Cu) = x87_v0;
    *(float*)(cpu->esp + 0x28u) = x87_v0; 
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D737u)); sfera_sub_004D88E0(cpu, LIFT_CODE_TOKEN_VA(0x48D737u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D745u)); sfera_sub_004D9190(cpu, LIFT_CODE_TOKEN_VA(0x48D745u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D754u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x48D754u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 0xEu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D763u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x48D763u));
    if (*(uint8_t*)(cpu->esi + 0xA0u) != (cpu->ebx & 0xFFu)) goto label_0008D8A0;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x18u);
    cpu->edx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D779u)); sfera_sub_0044FCB0(cpu, LIFT_CODE_TOKEN_VA(0x48D779u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 4u); lift_push32(cpu, 0x14u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D788u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x48D788u));
    cpu->ebx = cpu->edi + (cpu->edi * 2u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    if (cpu->ebx <= 0x1F5u) goto label_0008D7A3;
    *(uint32_t*)(cpu->esp + 0x10u) = 0x1F5u;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x10u);
    label_0008D7A3:
    cpu->edi = *(uint32_t*)(cpu->esi + 0xC8u);
    if (cpu->ebx == 0u) goto label_0008D800;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x68u);
    label_0008D7B1:
    lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->esi + 0x1Cu;
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D7BEu)); sfera_sub_00419F70(cpu, LIFT_CODE_TOKEN_VA(0x48D7BEu));
    *(float*)(cpu->edi) = (double)*(float*)(cpu->ebp);
    cpu->edi += 0x1Cu;
    x87_v0 = (double)*(float*)(cpu->ebp + 4u);
    cpu->ebp += 0xCu;
    --cpu->ebx;
    *(float*)(cpu->edi + 0xFFFFFFE8u) = x87_v0; 
    *(float*)(cpu->edi + 0xFFFFFFECu) = (double)*(float*)(cpu->ebp + 0xFFFFFFFCu);
    cpu->edx = *(uint32_t*)(cpu->esi + 0xA8u);
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->edi + 0xFFFFFFF0u) = cpu->edx;
    x87_v1 = 0.5;
    *(uint32_t*)(cpu->edi + 0xFFFFFFF4u) = 0u;
    x87_v0 = (x87_v0) + (x87_v1);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(float*)(cpu->edi + 0xFFFFFFF8u) = x87_v1; 
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x18u)));
    *(float*)(cpu->edi + 0xFFFFFFFCu) = x87_v0; 
    if (cpu->ebx != 0u) goto label_0008D7B1;
    label_0008D800:
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x16u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D80Fu)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x48D80Fu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x1C2u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D81Fu)); sfera_sub_004D8B70(cpu, LIFT_CODE_TOKEN_VA(0x48D81Fu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xC8u);
    lift_push32(cpu, 0x1Cu); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0u); lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D840u)); sfera_sub_004D9580(cpu, LIFT_CODE_TOKEN_VA(0x48D840u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D851u)); sfera_sub_004D8790(cpu, LIFT_CODE_TOKEN_VA(0x48D851u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 2u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D862u)); sfera_sub_004D8790(cpu, LIFT_CODE_TOKEN_VA(0x48D862u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D86Du)); sfera_sub_004D91E0(cpu, LIFT_CODE_TOKEN_VA(0x48D86Du));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D87Cu)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x48D87Cu));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0xEu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D88Bu)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x48D88Bu));
    cpu->ebp = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x54u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0008D8A0:
    cpu->edx = *(uint8_t*)(cpu->esi + 0xA1u);
    cpu->eax = *(uint32_t*)(cpu->esi + (cpu->edx * 4u) + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D8B9u)); sfera_sub_004D8F40(cpu, LIFT_CODE_TOKEN_VA(0x48D8B9u));
    cpu->ebx = cpu->edi + (cpu->edi * 2u);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D8C3u)); sfera_sub_0044EFE0(cpu, LIFT_CODE_TOKEN_VA(0x48D8C3u));
    if (cpu->eax == 0u) goto label_0008D9B8;
    if (cpu->ebx == 0u) goto label_0008D923;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x68u);
    cpu->edi = cpu->eax + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    label_0008D8E0:
    lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->esi + 0x1Cu;
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D8EDu)); sfera_sub_00419F70(cpu, LIFT_CODE_TOKEN_VA(0x48D8EDu));
    x87_v0 = (double)*(float*)(cpu->esp + 0x14u);
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    x87_v1 = 0.5;
    *(uint32_t*)(cpu->edi + 0xFFFFFFE4u) = cpu->ecx;
    x87_v0 = (x87_v0) + (x87_v1);
    cpu->edx = *(uint32_t*)(cpu->ebp + 4u);
    { double temporary = x87_v1; x87_v1 = x87_v0; x87_v0 = temporary; }
    *(uint32_t*)(cpu->edi + 0xFFFFFFE8u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    *(float*)(cpu->edi + 0xFFFFFFFCu) = x87_v1; 
    *(uint32_t*)(cpu->edi + 0xFFFFFFECu) = cpu->eax;
    x87_v0 = (x87_v0) + (((double)*(float*)(cpu->esp + 0x18u)));
    cpu->edi += 0x20u;
    cpu->ebp += 0xCu;
    --*(uint32_t*)(cpu->esp + 0x10u); sub_pred[0] = *(uint32_t*)(cpu->esp + 0x10u) == 0u;
    *(float*)(cpu->edi + 0xFFFFFFE0u) = x87_v0; 
    if (!sub_pred[0]) goto label_0008D8E0;
    label_0008D923:
    cpu->ecx = g_sfera_sky_runtime.draw_resource;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D938u)); sfera_sub_004D8AA0(cpu, LIFT_CODE_TOKEN_VA(0x48D938u));
    cpu->eax = *(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator;
    cpu->ecx = g_sfera_sky_runtime.draw_resource;
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 0x20u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    lift_push32(cpu, 4u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D960u)); sfera_sub_004D92A0(cpu, LIFT_CODE_TOKEN_VA(0x48D960u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    g_sfera_main_input_state_runtime.timing_accumulator = (uint64_t)((*(uint32_t*)(void*)&g_sfera_main_input_state_runtime.timing_accumulator)) + (uint64_t)(cpu->ebx) + (uint64_t)(0u);
    lift_push32(cpu, 1u); lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D977u)); sfera_sub_004D8790(cpu, LIFT_CODE_TOKEN_VA(0x48D977u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 2u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D988u)); sfera_sub_004D8790(cpu, LIFT_CODE_TOKEN_VA(0x48D988u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D993u)); sfera_sub_004D91E0(cpu, LIFT_CODE_TOKEN_VA(0x48D993u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0x1Cu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D9A2u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x48D9A2u));
    cpu->ecx = g_sfera_graphics_runtime.d3d9_device;
    lift_push32(cpu, 1u); lift_push32(cpu, 0xEu);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48D9B1u)); sfera_sub_004D8740(cpu, LIFT_CODE_TOKEN_VA(0x48D9B1u));
    *(uint32_t*)(cpu->esi + 0x14u) = 0u;
    label_0008D9B8:
    cpu->ebp = lift_pop32(cpu);
    label_0008D9B9:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0008D9BB:
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x54u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048D9D0(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xACu);
    x87_v0 = (double)*(float*)(cpu->ecx + 0x9Cu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xB0u);
    *(float*)(cpu->ecx + 0xD0u) = x87_v0; 
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->ecx + 0xD4u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xB4u);
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->ecx + 0xD8u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 0xDCu) = cpu->eax;
    cpu->esi = cpu->ecx + 0x5Cu;
    cpu->edi = cpu->ecx + 0xE0u;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),64u); cpu->ecx = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048DA20(LiftCpu* cpu, uint32_t stop_address) { double x87_v0;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xD4u);
    x87_v0 = (double)*(float*)(cpu->ecx + 0xD0u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xD8u);
    *(float*)(cpu->ecx + 0x9Cu) = x87_v0; 
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->ecx + 0xACu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xDCu);
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->ecx + 0xB0u) = cpu->edx;
    *(uint32_t*)(cpu->ecx + 0xB4u) = cpu->eax;
    cpu->esi = cpu->ecx + 0xE0u;
    cpu->edi = cpu->ecx + 0x5Cu;
    std::memmove((void*)(cpu->edi),(void*)(cpu->esi),64u); cpu->ecx = 0u;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048DA70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xCu;
    *(uint32_t*)(cpu->esp + 4u) = cpu->ecx;
    cpu->ecx = (uintptr_t)"config.cfg";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48DAA1u)); sfera_sub_004483B0(cpu, LIFT_CODE_TOKEN_VA(0x48DAA1u));
    cpu->edx = cpu->esp + 4u;
    cpu->ecx = (uintptr_t)"SHAD";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48DAAFu)); sfera_sub_00448540(cpu, LIFT_CODE_TOKEN_VA(0x48DAAFu));
    cpu->eax = g_sfera_shadow_runtime.manager;
    if (cpu->eax != 0u) goto label_0008DB17;
    cpu->edx = 0x206u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\shadow.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48DAC7u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48DAC7u));
    lift_push32(cpu, 0x148u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48DAD1u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x48DAD1u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if (cpu->eax == 0u) goto label_0008DAED;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48DAEBu)); sfera_sub_0048C570(cpu, LIFT_CODE_TOKEN_VA(0x48DAEBu));
    goto label_0008DAEF;
    label_0008DAED:
    cpu->eax = 0u;
    label_0008DAEF:
    cpu->ecx = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = 0xFFFFFFFFu;
    g_sfera_shadow_runtime.manager = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48DB03u)); sfera_sub_0048C730(cpu, LIFT_CODE_TOKEN_VA(0x48DB03u));
    cpu->eax = g_sfera_shadow_runtime.manager;
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 4u));
    *(uint8_t*)(cpu->eax + 0xA0u) = cpu->ecx & 0xFFu;
    cpu->eax = g_sfera_shadow_runtime.manager;
    label_0008DB17:
    cpu->ecx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048DB30(LiftCpu* cpu, uint32_t stop_address) {
    if (g_sfera_shadow_runtime.manager == 0u) goto label_0008DB6E;
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0x215u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\shadow.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48DB49u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48DB49u));
    cpu->ecx = g_sfera_shadow_runtime.manager;
    cpu->esi = cpu->ecx;
    if (cpu->ecx == 0u) goto label_0008DB63;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48DB5Au)); sfera_sub_0048C670(cpu, LIFT_CODE_TOKEN_VA(0x48DB5Au));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48DB60u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48DB60u));
    cpu->esp += 4u;
    label_0008DB63:
    g_sfera_shadow_runtime.manager = 0u;
    cpu->esi = lift_pop32(cpu);
    label_0008DB6E:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048DB70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx);
    lift_push32(cpu, cpu->esi);
    if (cpu->eax!=0u) goto label_0008DB7B;
    cpu->esi=0u;
    goto label_0008DB7D;
    label_0008DB7B:
    cpu->esi = *(uint32_t*)(cpu->eax);
    label_0008DB7D:
    cpu->eax = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 2u;
    cpu->eax &= 3u;
    if (cpu->edx > cpu->ecx) goto label_0008DB91;
    cpu->ecx -= cpu->edx;
    label_0008DB91:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u));
    cpu->eax = cpu->ecx + (cpu->eax * 4u);
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048DBA0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    if (cpu->eax != 1u) goto label_0008DBBF;
    if (*(uint32_t*)(cpu->ecx + 0x14u) < 0x10u) goto label_0008DBB1;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_0008DBB1:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0xCu));
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    *(uint8_t*)(cpu->ecx + cpu->edx) = cpu->eax & 0xFFu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0008DBBF:
    if (*(uint32_t*)(cpu->ecx + 0x14u) < 0x10u) goto label_0008DBC7;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_0008DBC7:
    cpu->ecx += *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->esp + 0x10u));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memset), LIFT_CODE_TOKEN_VA(0x48DBD3u));
    cpu->esp += 0xCu;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048DBE0(LiftCpu* cpu, uint32_t stop_address) {
    if (*(uint32_t*)(cpu->ecx + 0x14u) < 0x10u) goto label_0008DBF1;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax += cpu->ecx;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0008DBF1:
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = cpu->ecx + cpu->edx;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048DC00(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0xCu) <= 0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (sub_pred[0]) goto label_0008DC5C;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    if (cpu->esi >= cpu->edx) goto label_0008DC5C;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x14u);
    if (cpu->ecx < 0x10u) goto label_0008DC24;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_0008DC26;
    label_0008DC24:
    cpu->eax = cpu->edi;
    label_0008DC26:
    cpu->ebx = cpu->edx + cpu->eax;
    if (cpu->ecx < 0x10u) goto label_0008DC32;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_0008DC34;
    label_0008DC32:
    cpu->eax = cpu->edi;
    label_0008DC34:
    cpu->esi += cpu->eax;
    if (cpu->esi >= cpu->ebx) goto label_0008DC5C;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    label_0008DC40:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = (int8_t)(*(uint8_t*)(cpu->esi));
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp);
    lift_native_call(cpu, native_memchr_address32(), LIFT_CODE_TOKEN_VA(0x48DC4Au));
    cpu->esp += 0xCu;
    if (cpu->eax != 0u) goto label_0008DC66;
    ++cpu->esi;
    if (cpu->esi < cpu->ebx) goto label_0008DC40;
    label_0008DC5C:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0008DC66:
    if (*(uint32_t*)(cpu->edi + 0x14u) < 0x10u) goto label_0008DC6E;
    cpu->edi = *(uint32_t*)(cpu->edi);
    label_0008DC6E:
    cpu->eax = cpu->esi;
    cpu->eax -= cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048DC80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->edi + 0x10u);
    if (cpu->esi >= cpu->edx) goto label_0008DCD3;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x14u);
    if (cpu->ecx < 0x10u) goto label_0008DC9D;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_0008DC9F;
    label_0008DC9D:
    cpu->eax = cpu->edi;
    label_0008DC9F:
    cpu->ebx = cpu->edx + cpu->eax;
    if (cpu->ecx < 0x10u) goto label_0008DCAB;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_0008DCAD;
    label_0008DCAB:
    cpu->eax = cpu->edi;
    label_0008DCAD:
    cpu->esi += cpu->eax;
    if (cpu->esi >= cpu->ebx) goto label_0008DCD3;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_0008DCB7:
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->esi));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_memchr_address32(), LIFT_CODE_TOKEN_VA(0x48DCC1u));
    cpu->esp += 0xCu;
    if (cpu->eax == 0u) goto label_0008DCDD;
    ++cpu->esi;
    if (cpu->esi < cpu->ebx) goto label_0008DCB7;
    label_0008DCD3:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0008DCDD:
    if (*(uint32_t*)(cpu->edi + 0x14u) < 0x10u) goto label_0008DCE5;
    cpu->edi = *(uint32_t*)(cpu->edi);
    label_0008DCE5:
    cpu->eax = cpu->esi;
    cpu->eax -= cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048DCF0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->eax + 0x10u);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (cpu->edx == 0u) goto label_0008DD6D;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->ecx >= cpu->edx) goto label_0008DD0E;
    cpu->edx = cpu->ecx;
    goto label_0008DD0F;
    label_0008DD0E:
    --cpu->edx;
    label_0008DD0F:
    if (*(uint32_t*)(cpu->eax + 0x14u) < 0x10u) goto label_0008DD17;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0008DD17:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ebp = native_memchr_address32();
    cpu->esi = cpu->eax + cpu->edx;
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->esi));
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x8DD30u), LIFT_CODE_TOKEN_RVA(0x8DD2Eu))) { return; }
    cpu->esp += 0xCu;
    if (cpu->eax == 0u) goto label_0008DD55;
    label_0008DD37:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48DD40u)); sfera_sub_004020B0(cpu, LIFT_CODE_TOKEN_VA(0x48DD40u));
    if (cpu->esi == cpu->eax) goto label_0008DD6D;
    cpu->ecx = (int8_t)(*(uint8_t*)(cpu->esi + 0xFFFFFFFFu));
    --cpu->esi;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x8DD4Eu), LIFT_CODE_TOKEN_RVA(0x8DD4Cu))) { return; }
    cpu->esp += 0xCu;
    if (cpu->eax != 0u) goto label_0008DD37;
    label_0008DD55:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint32_t*)(cpu->ecx + 0x14u) < 0x10u) goto label_0008DD61;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_0008DD61:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax -= cpu->ecx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0008DD6D:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048DD80(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = cpu->ecx;
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->edx);
    if (cpu->ecx == 0u) goto label_0008DDA3;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == 0u) goto label_0008DDA3;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008DDA3:
    cpu->edx = *(uint32_t*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048DDB0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = cpu->ecx;
    if (*(uint32_t*)(cpu->esp + 0x10u) == cpu->esi) goto label_0008DE2E;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    label_0008DDC0:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    --cpu->esi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    if (cpu->edx!=0u) goto label_0008DDD1;
    cpu->edi=0u;
    goto label_0008DDD3;
    label_0008DDD1:
    cpu->edi = *(uint32_t*)(cpu->edx);
    label_0008DDD3:
    cpu->ebx = *(uint32_t*)(cpu->edi + 8u);
    cpu->edx = cpu->esi;
    cpu->edx >>= 2u;
    cpu->esi &= 3u;
    if (cpu->ebx > cpu->edx) goto label_0008DDE4;
    cpu->edx -= cpu->ebx;
    label_0008DDE4:
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->edx * 4u));
    cpu->ebp = cpu->edx + (cpu->esi * 4u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    --cpu->esi;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->esi;
    if (cpu->edx!=0u) goto label_0008DE02;
    cpu->ebx=0u;
    goto label_0008DE04;
    label_0008DE02:
    cpu->ebx = *(uint32_t*)(cpu->edx);
    label_0008DE04:
    cpu->edi = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx = cpu->esi;
    cpu->edx >>= 2u;
    cpu->esi &= 3u;
    if (cpu->edi > cpu->edx) goto label_0008DE15;
    cpu->edx -= cpu->edi;
    label_0008DE15:
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->edx * 4u));
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    *(uint32_t*)(cpu->edx + (cpu->esi * 4u)) = cpu->ecx;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x28u);
    if (*(uint32_t*)(cpu->esp + 0x1Cu) != cpu->esi) goto label_0008DDC0;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0008DE2E:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    cpu->esi = lift_pop32(cpu);
    if (cpu->edx == 0u) goto label_0008DE4E;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == 0u) goto label_0008DE58;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0008DE4E:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
    label_0008DE58:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048DE70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->ecx;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    if (cpu->edx == *(uint32_t*)(cpu->esp + 0x20u)) goto label_0008DEFB;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_0008DE90:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    if (cpu->eax==0u) goto label_0008DE9A;
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0008DE9A:
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edi = cpu->edx;
    cpu->edi >>= 2u;
    cpu->edx &= 3u;
    if (cpu->ecx > cpu->edi) goto label_0008DEAB;
    cpu->edi -= cpu->ecx;
    label_0008DEAB:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    if (cpu->ecx!=0u) goto label_0008DEB7;
    cpu->ebp=0u;
    goto label_0008DEB9;
    label_0008DEB7:
    cpu->ebp = *(uint32_t*)(cpu->ecx);
    label_0008DEB9:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->esi = cpu->ebx;
    cpu->esi >>= 2u;
    cpu->ebx &= 3u;
    if (cpu->ecx > cpu->esi) goto label_0008DECA;
    cpu->esi -= cpu->ecx;
    label_0008DECA:
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->edi * 4u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 4u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + (cpu->edx * 4u));
    cpu->eax = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    *(uint32_t*)(cpu->eax + (cpu->ebx * 4u)) = cpu->ecx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x38u);
    ++cpu->edx;
    ++cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    if (cpu->edx != *(uint32_t*)(cpu->esp + 0x2Cu)) goto label_0008DE90;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    label_0008DEFB:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ebx;
    if (cpu->ecx == 0u) goto label_0008DF1D;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == 0u) goto label_0008DF1D;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0008DF1D:
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048DF30(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->eax == cpu->ecx) goto label_0008DFA2;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    label_0008DF40:
    --cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    if (cpu->eax == cpu->ecx) goto label_0008DF9E;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->esi = cpu->ecx;
    cpu->esi >>= 2u;
    cpu->ecx &= 3u;
    if (cpu->edx > cpu->esi) goto label_0008DF5E;
    cpu->esi -= cpu->edx;
    label_0008DF5E:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebx = *(uint32_t*)(cpu->edi + 8u);
    cpu->edx = cpu->eax;
    cpu->edx >>= 2u;
    cpu->eax &= 3u;
    if (cpu->ebx > cpu->edx) goto label_0008DF73;
    cpu->edx -= cpu->ebx;
    label_0008DF73:
    cpu->ebx = *(uint32_t*)(cpu->ebp + 4u);
    cpu->esi = *(uint32_t*)(cpu->ebx + (cpu->esi * 4u));
    cpu->ecx = cpu->esi + (cpu->ecx * 4u);
    cpu->esi = *(uint32_t*)(cpu->edi + 4u);
    cpu->edx = *(uint32_t*)(cpu->esi + (cpu->edx * 4u));
    cpu->esi = *(uint32_t*)(cpu->ecx);
    cpu->eax = cpu->edx + (cpu->eax * 4u);
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->eax) = cpu->esi;
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if (cpu->eax != cpu->ecx) goto label_0008DF40;
    label_0008DF9E:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    label_0008DFA2:
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048DFB0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 0x10u);
    if (cpu->edi != *(uint32_t*)(cpu->edx + 0x10u)) goto label_0008E021;
    if (*(uint32_t*)(cpu->edx + 0x14u) < 0x10u) goto label_0008DFC7;
    cpu->edx = *(uint32_t*)(cpu->edx);
    label_0008DFC7:
    cpu->esi = *(uint32_t*)(cpu->ecx + 0x14u);
    if (cpu->esi < 0x10u) goto label_0008DFD3;
    cpu->eax = *(uint32_t*)(cpu->ecx);
    goto label_0008DFD5;
    label_0008DFD3:
    cpu->eax = cpu->ecx;
    label_0008DFD5:
    cpu->eax += cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->esi < 0x10u) goto label_0008DFE4;
    cpu->esi = *(uint32_t*)(cpu->ecx);
    goto label_0008DFE6;
    label_0008DFE4:
    cpu->esi = cpu->ecx;
    label_0008DFE6:
    if (cpu->esi == cpu->eax) goto label_0008E017;
    cpu->edi = native_function_address32(&::toupper);
    cpu->ebp = cpu->edx;
    cpu->ebp -= cpu->esi;
    label_0008DFF4:
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->esi));
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + cpu->ebp));
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x8DFFDu), LIFT_CODE_TOKEN_RVA(0x8DFFBu))) { return; }
    cpu->ecx = (int8_t)((cpu->ebx & 0xFFu));
    lift_push32(cpu, cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if (!lift_call_indirect(cpu, cpu->edi, LIFT_CODE_TOKEN_RVA(0x8E007u), LIFT_CODE_TOKEN_RVA(0x8E005u))) { return; }
    cpu->esp += 8u;
    if (*(uint32_t*)(cpu->esp + 0x10u) != cpu->eax) goto label_0008E021;
    ++cpu->esi;
    if (cpu->esi != *(uint32_t*)(cpu->esp + 0x14u)) goto label_0008DFF4;
    label_0008E017:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
    label_0008E021:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048E030(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = cpu->edx;
    cpu->esi = cpu->ecx;
    if (cpu->edi == 0xFFFFFFFFu) goto label_0008E089;
    if (cpu->edi >= *(uint32_t*)(cpu->esi + 0x10u)) goto label_0008E089;
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_0008E04F;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_0008E051;
    label_0008E04F:
    cpu->eax = cpu->esi;
    label_0008E051:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + cpu->edi));
    cpu->eax = (((cpu->eax & 0xFFu) == 0x5Cu) || ((cpu->eax & 0xFFu) == 0x2Fu)) ? 0u : 0xFFFFFFFFu;
    if (cpu->eax == 0xFFFFFFFFu) goto label_0008E089;
    if (cpu->ebx == 0u) goto label_0008E081;
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_0008E07C;
    cpu->esi = *(uint32_t*)(cpu->esi);
    label_0008E07C:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi + cpu->edi));
    *(uint8_t*)(cpu->ebx) = cpu->edx & 0xFFu;
    label_0008E081:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0008E089:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048E0A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->ecx);
    cpu->edx = 0u;
    if (cpu->eax == 0u) goto label_0008E0B0;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_0008E0B0;
    cpu->edx = *(uint32_t*)(cpu->eax);
    label_0008E0B0:
    cpu->ecx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->ecx -= *(uint32_t*)(cpu->esp + 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    if (cpu->edx == 0u) goto label_0008E0D9;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == 0u) goto label_0008E0D9;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0008E0D9:
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048E0E0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->ecx + 0x10u);
    if (cpu->eax == 0u) goto label_0008E10C;
    ++*(uint32_t*)(cpu->ecx + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 8u);
    cpu->edi += cpu->edi;
    cpu->edi += cpu->edi;
    sub_pred[0] = cpu->edi <= *(uint32_t*)(cpu->ecx + 0xCu);
    cpu->edi = lift_pop32(cpu);
    if (!sub_pred[0]) goto label_0008E0FF;
    *(uint32_t*)(cpu->ecx + 0xCu) = 0u;
    label_0008E0FF:
    --cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x10u) = cpu->eax;
    if (cpu->eax != 0u) goto label_0008E10C;
    *(uint32_t*)(cpu->ecx + 0xCu) = 0u;
    label_0008E10C:
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048E110(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    cpu->ecx = 0xFFFFFFFu;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx -= cpu->eax;
    if (cpu->ecx >= cpu->edi) goto label_0008E134;
    lift_push32(cpu, (uintptr_t)"deque<T> too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x48E110u), "std::length_error");
    label_0008E134:
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 1u;
    if (cpu->ecx >= 8u) goto label_0008E142;
    cpu->ecx = 8u;
    label_0008E142:
    if (cpu->edi >= cpu->ecx) goto label_0008E157;
    cpu->edx = 0xFFFFFFFu;
    cpu->edx -= cpu->ecx;
    if (cpu->eax > cpu->edx) goto label_0008E157;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    cpu->edi = cpu->ecx;
    label_0008E157:
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->ebx + 0xCu);
    lift_push32(cpu, cpu->esi);
    cpu->eax += cpu->edi;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx + 0x15u;
    cpu->ebp = cpu->ebp >> 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E16Au)); sfera_sub_0049F1D0(cpu, LIFT_CODE_TOKEN_VA(0x48E16Au));
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->edx = cpu->eax;
    cpu->esi = cpu->ebp * 4u;
    cpu->eax = cpu->esi + cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebx + 8u);
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    cpu->eax -= *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    cpu->eax += cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = (int32_t)(cpu->eax) >> 2u;
    cpu->eax += cpu->eax;
    cpu->eax += cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->edx += cpu->esi;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x48E1A2u));
    cpu->eax += *(uint32_t*)(cpu->esp + 0x24u);
    cpu->ecx = *(uint32_t*)(cpu->ebx + 4u);
    cpu->esp += 0xCu;
    if (cpu->ebp > cpu->edi) goto label_0008E1F3;
    cpu->esi = (int32_t)(cpu->esi) >> 2u;
    cpu->edx = cpu->esi;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edx;
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x48E1C8u));
    cpu->edx = cpu->eax;
    cpu->edx += *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esp += 0xCu;
    if ((cpu->esi -= cpu->ebp) == 0u) goto label_0008E1E7;
    cpu->eax = 0u;
    std::memset((void*)(cpu->edx),0x00,(cpu->esi)*4u); cpu->ecx = 0u;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    label_0008E1E7:
    if (cpu->ebp == 0u) goto label_0008E240;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = cpu->ebp;
    goto label_0008E238;
    label_0008E1F3:
    cpu->ebp = cpu->edi * 4u;
    cpu->edx = cpu->ebp;
    cpu->edx = (int32_t)(cpu->edx) >> 2u;
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x48E206u));
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->ecx = cpu->eax + cpu->ebp;
    cpu->esi -= cpu->ecx;
    cpu->esi += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esi = (int32_t)(cpu->esi) >> 2u;
    cpu->esi += cpu->esi;
    cpu->esi += cpu->esi;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x48E224u));
    cpu->esp += 0x18u;
    cpu->edx = cpu->esi + cpu->eax;
    if (cpu->edi == 0u) goto label_0008E240;
    cpu->ecx = cpu->edi;
    cpu->edi = cpu->edx;
    label_0008E238:
    std::memset((void*)cpu->edi,0,cpu->ecx*4u);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    label_0008E240:
    cpu->eax = *(uint32_t*)(cpu->ebx + 4u);
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    if (cpu->eax == 0u) goto label_0008E252;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E24Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48E24Fu));
    cpu->esp += 4u;
    label_0008E252:
    *(uint32_t*)(cpu->ebx + 8u) = (uint64_t)(*(uint32_t*)(cpu->ebx + 8u)) + (uint64_t)(cpu->edi) + (uint64_t)(0u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 8u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->ebx + 4u) = cpu->ecx;
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048E270(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xCu);
    if (cpu->eax >= cpu->ecx) goto label_0008E28D;
    lift_push32(cpu, (uintptr_t)"invalid string position");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x48E270u), "std::out_of_range");
    label_0008E28D:
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax -= cpu->ecx;
    if (cpu->eax >= cpu->ebx) goto label_0008E29A;
    cpu->ebx = cpu->eax;
    label_0008E29A:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->eax;
    if (cpu->ecx > cpu->ebx) goto label_0008E2B1;
    lift_push32(cpu, (uintptr_t)"string too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x48E29Au), "std::length_error");
    label_0008E2B1:
    lift_push32(cpu, cpu->edi);
    if (cpu->ebx == 0u) goto label_0008E34E;
    cpu->edi = cpu->eax + cpu->ebx;
    if (cpu->edi <= 0xFFFFFFFEu) goto label_0008E2CD;
    lift_push32(cpu, (uintptr_t)"string too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x48E2B1u), "std::length_error");
    label_0008E2CD:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->ecx >= cpu->edi) goto label_0008E2F7;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E2DDu)); sfera_sub_00403230(cpu, LIFT_CODE_TOKEN_VA(0x48E2DDu));
    if (cpu->edi == 0u) goto label_0008E34E;
    label_0008E2E1:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (*(uint32_t*)(cpu->ecx + 0x14u) < 0x10u) goto label_0008E2ED;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_0008E2ED:
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_0008E31B;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_0008E31D;
    label_0008E2F7:
    if (cpu->edi != 0u) goto label_0008E2E1;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (cpu->ecx < 0x10u) goto label_0008E310;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0008E310:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->ebx = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0008E31B:
    cpu->eax = cpu->esi;
    label_0008E31D:
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x48E329u));
    cpu->esp += 0xCu;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x14u) < 0x10u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (sub_pred[0]) goto label_0008E348;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0008E348:
    cpu->eax = cpu->esi;
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    label_0008E34E:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048E360(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    if (cpu->ebp == 0u) goto label_0008E3C5;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->ecx < 0x10u) goto label_0008E378;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_0008E37A;
    label_0008E378:
    cpu->eax = cpu->esi;
    label_0008E37A:
    if (cpu->ebp < cpu->eax) goto label_0008E3C5;
    if (cpu->ecx < 0x10u) goto label_0008E387;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_0008E389;
    label_0008E387:
    cpu->eax = cpu->esi;
    label_0008E389:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx += cpu->eax;
    if (cpu->edx <= cpu->ebp) goto label_0008E3C5;
    if (cpu->ecx < 0x10u) goto label_0008E3AE;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->ecx);
    cpu->ebp -= cpu->eax;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E3A9u)); sfera_sub_0048E270(cpu, LIFT_CODE_TOKEN_VA(0x48E3A9u));
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0008E3AE:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = cpu->esi;
    lift_push32(cpu, cpu->ecx);
    cpu->ebp -= cpu->eax;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E3C0u)); sfera_sub_0048E270(cpu, LIFT_CODE_TOKEN_VA(0x48E3C0u));
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0008E3C5:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx |= 0xFFFFFFFFu;
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx -= cpu->eax;
    if (cpu->edx > cpu->ebx) goto label_0008E3E1;
    lift_push32(cpu, (uintptr_t)"string too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x48E3C5u), "std::length_error");
    label_0008E3E1:
    lift_push32(cpu, cpu->edi);
    if (cpu->ebx == 0u) goto label_0008E471;
    cpu->edi = cpu->eax + cpu->ebx;
    if (cpu->edi <= 0xFFFFFFFEu) goto label_0008E3FD;
    lift_push32(cpu, (uintptr_t)"string too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x48E3E1u), "std::length_error");
    label_0008E3FD:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->ecx >= cpu->edi) goto label_0008E41B;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E40Du)); sfera_sub_00403230(cpu, LIFT_CODE_TOKEN_VA(0x48E40Du));
    if (cpu->edi == 0u) goto label_0008E471;
    label_0008E411:
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_0008E441;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_0008E443;
    label_0008E41B:
    if (cpu->edi != 0u) goto label_0008E411;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (cpu->ecx < 0x10u) goto label_0008E435;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0008E435:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0008E441:
    cpu->eax = cpu->esi;
    label_0008E443:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->ebx);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x48E44Bu));
    cpu->esp += 0xCu;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x14u) < 0x10u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (sub_pred[0]) goto label_0008E46B;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0008E46B:
    cpu->eax = cpu->esi;
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    label_0008E471:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048E480(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    if (cpu->eax >= cpu->ebx) goto label_0008E49A;
    lift_push32(cpu, (uintptr_t)"invalid string position");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x48E480u), "std::out_of_range");
    label_0008E49A:
    cpu->ecx |= 0xFFFFFFFFu;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx -= cpu->eax;
    if (cpu->ecx > cpu->ebp) goto label_0008E4B3;
    lift_push32(cpu, (uintptr_t)"string too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x48E49Au), "std::length_error");
    label_0008E4B3:
    lift_push32(cpu, cpu->edi);
    if (cpu->ebp == 0u) goto label_0008E569;
    cpu->edi = cpu->eax + cpu->ebp;
    if (cpu->edi <= 0xFFFFFFFEu) goto label_0008E4CF;
    lift_push32(cpu, (uintptr_t)"string too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x48E4B3u), "std::length_error");
    label_0008E4CF:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->ecx >= cpu->edi) goto label_0008E4F3;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E4DFu)); sfera_sub_00403230(cpu, LIFT_CODE_TOKEN_VA(0x48E4DFu));
    if (cpu->edi == 0u) goto label_0008E569;
    label_0008E4E7:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->eax < 0x10u) goto label_0008E519;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    goto label_0008E51B;
    label_0008E4F3:
    if (cpu->edi != 0u) goto label_0008E4E7;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (cpu->ecx < 0x10u) goto label_0008E50D;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0008E50D:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0008E519:
    cpu->ecx = cpu->esi;
    label_0008E51B:
    if (cpu->eax < 0x10u) goto label_0008E524;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_0008E526;
    label_0008E524:
    cpu->eax = cpu->esi;
    label_0008E526:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx -= cpu->ebx;
    lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->ebx;
    cpu->eax += cpu->ebx;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x48E534u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esp += 0xCu;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E54Bu)); sfera_sub_0048DBA0(cpu, LIFT_CODE_TOKEN_VA(0x48E54Bu));
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x14u) < 0x10u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (sub_pred[0]) goto label_0008E563;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0008E563:
    cpu->eax = cpu->esi;
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    label_0008E569:
    cpu->edi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048E580(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->edx = 0u;
    cpu->eax = cpu->esp;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esp;
    if (cpu->ecx == cpu->edx) goto label_0008E5AB;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->edx) goto label_0008E5AB;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008E5AB:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esp;
    if (cpu->ecx == cpu->edx) goto label_0008E5D2;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->edx) goto label_0008E5D2;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008E5D2:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->esp;
    if (cpu->ecx == cpu->edx) goto label_0008E5F9;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->edx) goto label_0008E5F9;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0008E5F9:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E607u)); sfera_sub_0048DDB0(cpu, LIFT_CODE_TOKEN_VA(0x48E607u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x28u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048E610(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->edx = 0u;
    cpu->eax = cpu->esp;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esp;
    if (cpu->ecx == cpu->edx) goto label_0008E63B;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->edx) goto label_0008E63B;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008E63B:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esp;
    if (cpu->ecx == cpu->edx) goto label_0008E662;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->edx) goto label_0008E662;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008E662:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->esp;
    if (cpu->ecx == cpu->edx) goto label_0008E689;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->edx) goto label_0008E689;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0008E689:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E697u)); sfera_sub_0048DE70(cpu, LIFT_CODE_TOKEN_VA(0x48E697u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x28u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048E6A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->ecx += cpu->eax;
    lift_push32(cpu, cpu->edi);
    if ((((cpu->ecx & 0xFFu)) & (3u)) != 0u) goto label_0008E6C9;
    cpu->eax += 4u;
    cpu->eax >>= 2u;
    if (*(uint32_t*)(cpu->esi + 8u) > cpu->eax) goto label_0008E6C9;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8E6C9u)); sfera_sub_0048E110(cpu, LIFT_CODE_TOKEN_RVA(0x8E6C9u));
    label_0008E6C9:
    cpu->ebx = *(uint32_t*)(cpu->esi + 0xCu);
    cpu->ebx += *(uint32_t*)(cpu->esi + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    cpu->edi = cpu->ebx;
    cpu->edi >>= 2u;
    if (cpu->eax > cpu->edi) goto label_0008E6DD;
    cpu->edi -= cpu->eax;
    label_0008E6DD:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    if (*(uint32_t*)(cpu->edx + (cpu->edi * 4u)) != 0u) goto label_0008E6FA;
    lift_push32(cpu, 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E6EDu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x48E6EDu));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_0008E71E;
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->ecx + (cpu->edi * 4u)) = cpu->eax;
    label_0008E6FA:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->edi * 4u));
    cpu->ebx &= 3u;
    cpu->eax = cpu->edx + (cpu->ebx * 4u);
    if (cpu->eax == 0u) goto label_0008E712;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0008E712:
    ++*(uint32_t*)(cpu->esi + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0008E71E:
    cpu->edx = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x14u;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E74Cu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x48E74Cu));
    lift_trap(cpu, 0x48E74Cu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0048E750(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1];
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    lift_test[0]=(*(uint8_t*)(cpu->esi + 0xCu)&3u)==0u;
    lift_push32(cpu, cpu->edi);
    if (!lift_test[0]) goto label_0008E773;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->eax += 4u;
    cpu->eax >>= 2u;
    if (*(uint32_t*)(cpu->esi + 8u) > cpu->eax) goto label_0008E773;
    lift_push32(cpu, 1u);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8E773u)); sfera_sub_0048E110(cpu, LIFT_CODE_TOKEN_RVA(0x8E773u));
    label_0008E773:
    cpu->ebx = *(uint32_t*)(cpu->esi + 0xCu);
    if (cpu->ebx!=0u) goto label_0008E781;
    cpu->ebx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ebx += cpu->ebx;
    cpu->ebx += cpu->ebx;
    label_0008E781:
    cpu->ecx = *(uint32_t*)(cpu->esi + 4u);
    --cpu->ebx;
    cpu->edi = cpu->ebx;
    cpu->edi >>= 2u;
    if (*(uint32_t*)(cpu->ecx + (cpu->edi * 4u)) != 0u) goto label_0008E7A4;
    lift_push32(cpu, 0x10u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E797u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x48E797u));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_0008E7CD;
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    *(uint32_t*)(cpu->edx + (cpu->edi * 4u)) = cpu->eax;
    label_0008E7A4:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    cpu->eax = cpu->ebx;
    cpu->eax &= 3u;
    cpu->eax = cpu->ecx + (cpu->eax * 4u);
    if (cpu->eax == 0u) goto label_0008E7BE;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ecx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008E7BE:
    ++*(uint32_t*)(cpu->esi + 0x10u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x10u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0008E7CD:
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x14u;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E7FBu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x48E7FBu));
    lift_trap(cpu, 0x48E7FBu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0048E800(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    cpu->esp &= 0xFFFFFFF8u;
    cpu->esp -= 0x3Cu;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x14u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->eax -= cpu->esi;
    cpu->ebx = cpu->edi;
    cpu->ebx -= cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    cpu->eax = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->esi <= cpu->edi) goto label_0008E82D;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    label_0008E82D:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    if (cpu->ecx == 0u) goto label_0008E844;
    label_0008E835:
    { const int32_t n = (int32_t)cpu->eax, d = (int32_t)(cpu->ecx); cpu->eax = (uint32_t)(n / d); cpu->edx = (uint32_t)(n % d); }
    cpu->eax = cpu->ecx;
    cpu->ecx = cpu->edx;
    if (cpu->edx != 0u) goto label_0008E835;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    label_0008E844:
    if ((int32_t)cpu->eax >= (int32_t)cpu->ebx) goto label_0008E944;
    if ((int32_t)cpu->eax <= 0) goto label_0008E944;
    goto label_0008E859;
    label_0008E856:
    cpu->edi = *(uint32_t*)(cpu->ebp + 0x1Cu);
    label_0008E859:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->esi;
    cpu->esi += cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax += cpu->esi;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    cpu->ebx = cpu->esi;
    if (cpu->eax != cpu->edi) goto label_0008E87B;
    cpu->eax = cpu->ebp + 8u;
    goto label_0008E88B;
    label_0008E87B:
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    cpu->eax = cpu->esp + 0x28u;
    label_0008E88B:
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    label_0008E890:
    cpu->edx = *(uint32_t*)(cpu->edi + 8u);
    cpu->esi = cpu->ecx;
    cpu->eax = cpu->ecx;
    cpu->esi >>= 2u;
    cpu->eax &= 3u;
    if (cpu->edx > cpu->esi) goto label_0008E8A3;
    cpu->esi -= cpu->edx;
    label_0008E8A3:
    cpu->edx = cpu->ebx;
    cpu->ebx&=3u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->ebx = *(uint32_t*)(cpu->ebx + 8u);
    cpu->edx >>= 2u;
    if (cpu->ebx > cpu->edx) goto label_0008E8BC;
    cpu->edx -= cpu->ebx;
    label_0008E8BC:
    cpu->ebx = *(uint32_t*)(cpu->edi + 4u);
    cpu->esi = *(uint32_t*)(cpu->ebx + (cpu->esi * 4u));
    cpu->ebx = *(uint32_t*)(cpu->esi + (cpu->eax * 4u));
    cpu->esi = cpu->esi + (cpu->eax * 4u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->eax + (cpu->edx * 4u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->edx + (cpu->eax * 4u);
    cpu->eax = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->edx) = cpu->ebx;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    cpu->edx = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->edx -= cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    cpu->ebx = cpu->ecx;
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x10u) >= (int32_t)cpu->edx) goto label_0008E909;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ecx;
    cpu->eax = cpu->esp + 0x30u;
    goto label_0008E924;
    label_0008E909:
    cpu->eax = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = cpu->esi;
    cpu->ecx -= cpu->edx;
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x10u);
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ecx;
    cpu->eax = cpu->esp + 0x38u;
    label_0008E924:
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edi = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != *(uint32_t*)(cpu->esp + 0x44u)) goto label_0008E890;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    --cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if ((int32_t)cpu->eax > 0) goto label_0008E856;
    label_0008E944:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048E950(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x44u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebx = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x58u);
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->esi;
    if (cpu->eax != 0u) goto label_0008E996;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x44u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0008E996:
    if (cpu->ecx != 0xFFFFFFFFu) goto label_0008E9B5;
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x44u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0008E9B5:
    lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    if (cpu->eax == 0u) goto label_0008EA58;
    label_0008E9C0:
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E9D2u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48E9D2u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48E9D9u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48E9D9u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx!=0u) goto label_0008E9E3;
    cpu->esi=0u;
    goto label_0008E9E5;
    label_0008E9E3:
    cpu->esi = *(uint32_t*)(cpu->ecx);
    label_0008E9E5:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 2u;
    cpu->eax &= 3u;
    if (cpu->edx > cpu->ecx) goto label_0008E9F9;
    cpu->ecx -= cpu->edx;
    label_0008E9F9:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u));
    cpu->esi = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    cpu->ecx = cpu->esi;
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EA11u)); sfera_sub_004312C0(cpu, LIFT_CODE_TOKEN_VA(0x48EA11u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0008EA42;
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EA21u)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x48EA21u));
    cpu->esi = *(uint32_t*)(cpu->eax + 0x10u);
    if (*(uint32_t*)(cpu->esp + 0x48u) < 0x10u) goto label_0008EA38;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EA35u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48EA35u));
    cpu->esp += 4u;
    label_0008EA38:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ebp += cpu->esi;
    if (cpu->ebp > cpu->eax) goto label_0008EA7F;
    label_0008EA42:
    ++cpu->edi;
    if (cpu->edi < *(uint32_t*)(cpu->ebx + 0x10u)) goto label_0008E9C0;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x10u);
    label_0008EA58:
    if (cpu->ecx != cpu->ebp) goto label_0008EAA6;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->edx) = 0xFFFFFFFFu;
    *(uint32_t*)(cpu->esi) = 0xFFFFFFFFu;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x44u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0008EA7F:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->esi -= cpu->ebp;
    cpu->esi += cpu->eax;
    *(uint32_t*)(cpu->ecx) = cpu->edi;
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->edx) = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x44u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0008EAA6:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->esp += 0x44u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048EAC0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 0x18u;
    if (*(uint32_t*)(cpu->ecx + 0x10u) > cpu->eax) goto label_0008EAD7;
    lift_push32(cpu, (uintptr_t)"invalid deque<T> subscript");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x48EAC0u), "std::out_of_range");
    label_0008EAD7:
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EAE8u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48EAE8u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EAEFu)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48EAEFu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx!=0u) goto label_0008EAF9;
    cpu->esi=0u;
    goto label_0008EAFB;
    label_0008EAF9:
    cpu->esi = *(uint32_t*)(cpu->ecx);
    label_0008EAFB:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 2u;
    cpu->eax &= 3u;
    if (cpu->edx > cpu->ecx) goto label_0008EB0F;
    cpu->ecx -= cpu->edx;
    label_0008EB0F:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u));
    cpu->eax = cpu->ecx + (cpu->eax * 4u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048EB20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 8u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EB38u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48EB38u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EB3Fu)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48EB3Fu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx!=0u) goto label_0008EB49;
    cpu->esi=0u;
    goto label_0008EB4B;
    label_0008EB49:
    cpu->esi = *(uint32_t*)(cpu->ecx);
    label_0008EB4B:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 2u;
    cpu->eax &= 3u;
    if (cpu->edx > cpu->ecx) goto label_0008EB5F;
    cpu->ecx -= cpu->edx;
    label_0008EB5F:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u));
    cpu->eax = cpu->ecx + (cpu->eax * 4u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048EB70(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x18u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, 1u);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EB85u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x48EB85u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EB8Cu)); sfera_sub_0048E0A0(cpu, LIFT_CODE_TOKEN_VA(0x48EB8Cu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx!=0u) goto label_0008EB96;
    cpu->esi=0u;
    goto label_0008EB98;
    label_0008EB96:
    cpu->esi = *(uint32_t*)(cpu->ecx);
    label_0008EB98:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 2u;
    cpu->eax &= 3u;
    if (cpu->edx > cpu->ecx) goto label_0008EBAC;
    cpu->ecx -= cpu->edx;
    label_0008EBAC:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u));
    cpu->eax = cpu->ecx + (cpu->eax * 4u);
    cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048EBC0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 0xCu;
    cpu->ebx = 0u;
    cpu->eax = cpu->esp;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x4Cu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esp;
    if (cpu->ecx == cpu->ebx) goto label_0008EBEB;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebx) goto label_0008EBEB;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008EBEB:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x54u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EBFEu)); sfera_sub_0049F9C0(cpu, LIFT_CODE_TOKEN_VA(0x48EBFEu));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x58u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esp;
    if (cpu->ecx == cpu->ebx) goto label_0008EC1E;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebx) goto label_0008EC1E;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008EC1E:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x60u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EC31u)); sfera_sub_0049F9C0(cpu, LIFT_CODE_TOKEN_VA(0x48EC31u));
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EC3Du)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48EC3Du));
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = cpu->eax;
    cpu->edx -= cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->edx;
    cpu->edx = cpu->esp + 0x2Cu;
    cpu->ebp = cpu->edi;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    cpu->ebp -= cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EC60u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x48EC60u));
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax -= cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->edi < cpu->eax);
    cpu->esp -= 0xCu;
    sub_pred[0] = (uint8_t)(cpu->eax) == (uint8_t)(cpu->ebx);
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    if (sub_pred[0]) goto label_0008ED14;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    if (cpu->ecx == cpu->ebx) goto label_0008EC96;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebx) goto label_0008EC96;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008EC96:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esp;
    if (cpu->ecx == cpu->ebx) goto label_0008ECBD;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebx) goto label_0008ECBD;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008ECBD:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->esp -= 0xCu;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48ECD5u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48ECD5u));
    cpu->ecx = cpu->esp + 0x50u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48ECDEu)); sfera_sub_0048E580(cpu, LIFT_CODE_TOKEN_VA(0x48ECDEu));
    if (cpu->ebp <= cpu->ebx) goto label_0008ED85;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    label_0008ECF0:
    if (cpu->ecx == cpu->ebx) goto label_0008ED0C;
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    ++*(uint32_t*)(cpu->esi + 0xCu);
    cpu->edx += cpu->edx;
    cpu->edx += cpu->edx;
    if (cpu->edx > *(uint32_t*)(cpu->esi + 0xCu)) goto label_0008ED06;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    label_0008ED06:
    if ((--cpu->ecx) != 0u) goto label_0008ED0C;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    label_0008ED0C:
    if ((--cpu->ebp) != 0u) goto label_0008ECF0;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ecx;
    goto label_0008ED85;
    label_0008ED14:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    if (cpu->ecx == cpu->ebx) goto label_0008ED26;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebx) goto label_0008ED26;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008ED26:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->esp -= 0xCu;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48ED3Eu)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x48ED3Eu));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->ebx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ebx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->esp;
    if (cpu->ecx == cpu->ebx) goto label_0008ED5E;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->ebx) goto label_0008ED5E;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008ED5E:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->ecx = cpu->esp + 0x50u;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48ED6Eu)); sfera_sub_0048E610(cpu, LIFT_CODE_TOKEN_VA(0x48ED6Eu));
    if (cpu->ebp <= cpu->ebx) goto label_0008ED85;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    label_0008ED75:
    if (cpu->eax == cpu->ebx) goto label_0008ED7F;
    if ((--cpu->eax) != 0u) goto label_0008ED7F;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    label_0008ED7F:
    if ((--cpu->ebp) != 0u) goto label_0008ED75;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->eax;
    label_0008ED85:
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48ED97u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48ED97u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48ED9Eu)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48ED9Eu));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x28u;
    cpu->esp += 0x20u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048EDB0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ecx |= 0xFFFFFFFFu;
    cpu->ecx -= cpu->eax;
    if (cpu->ecx > cpu->ebx) goto label_0008EDCF;
    lift_push32(cpu, (uintptr_t)"string too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x48EDB0u), "std::length_error");
    label_0008EDCF:
    lift_push32(cpu, cpu->edi);
    if (cpu->ebx == 0u) goto label_0008EE4D;
    cpu->edi = cpu->eax + cpu->ebx;
    if (cpu->edi <= 0xFFFFFFFEu) goto label_0008EDE7;
    lift_push32(cpu, (uintptr_t)"string too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x48EDCFu), "std::length_error");
    label_0008EDE7:
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->ecx >= cpu->edi) goto label_0008EE23;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EDF7u)); sfera_sub_00403230(cpu, LIFT_CODE_TOKEN_VA(0x48EDF7u));
    if (cpu->edi == 0u) goto label_0008EE4D;
    label_0008EDFB:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EE0Cu)); sfera_sub_0048DBA0(cpu, LIFT_CODE_TOKEN_VA(0x48EE0Cu));
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x14u) < 0x10u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (sub_pred[0]) goto label_0008EE47;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0008EE23:
    if (cpu->edi != 0u) goto label_0008EDFB;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (cpu->ecx < 0x10u) goto label_0008EE3C;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0008EE3C:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0008EE47:
    cpu->eax = cpu->esi;
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    label_0008EE4D:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048EE60(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    if (cpu->ecx < cpu->ebp) goto label_0008EFD1;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->eax = *(uint32_t*)(cpu->eax + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->eax < cpu->edx) goto label_0008EFD1;
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax -= cpu->edx;
    if (cpu->eax >= cpu->edi) goto label_0008EE93;
    cpu->edi = cpu->eax;
    label_0008EE93:
    cpu->edx |= 0xFFFFFFFFu;
    cpu->edx -= cpu->ecx;
    if (cpu->edx > cpu->edi) goto label_0008EEA7;
    lift_push32(cpu, (uintptr_t)"string too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x48EE93u), "std::length_error");
    label_0008EEA7:
    lift_push32(cpu, cpu->ebx);
    if (cpu->edi == 0u) goto label_0008EFC8;
    cpu->ebx = cpu->ecx + cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if (cpu->ebx <= 0xFFFFFFFEu) goto label_0008EEC7;
    lift_push32(cpu, (uintptr_t)"string too long");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x48EEA7u), "std::length_error");
    label_0008EEC7:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->eax >= cpu->ebx) goto label_0008EEEB;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48EED7u)); sfera_sub_00403230(cpu, LIFT_CODE_TOKEN_VA(0x48EED7u));
    if (cpu->ebx == 0u) goto label_0008EFC8;
    label_0008EEDF:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->eax < 0x10u) goto label_0008EF10;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    goto label_0008EF12;
    label_0008EEEB:
    if (cpu->ebx != 0u) goto label_0008EEDF;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    if (cpu->eax < 0x10u) goto label_0008EF04;
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint8_t*)(cpu->eax) = cpu->ebx & 0xFFu;
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_0008EF04:
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_0008EF10:
    cpu->ecx = cpu->esi;
    label_0008EF12:
    if (cpu->eax < 0x10u) goto label_0008EF1B;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_0008EF1D;
    label_0008EF1B:
    cpu->eax = cpu->esi;
    label_0008EF1D:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ebx = native_function_address32(&::memmove);
    cpu->edx -= cpu->ebp;
    lift_push32(cpu, cpu->edx);
    cpu->ecx += cpu->ebp;
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->edi;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x8EF33u), LIFT_CODE_TOKEN_RVA(0x8EF31u))) { return; }
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esp += 0xCu;
    if (cpu->esi != cpu->ecx) goto label_0008EF7F;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->ebp >= cpu->edx) goto label_0008EF48;
    cpu->edx += cpu->edi;
    label_0008EF48:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    if (cpu->eax < 0x10u) goto label_0008EF54;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    goto label_0008EF56;
    label_0008EF54:
    cpu->ecx = cpu->esi;
    label_0008EF56:
    if (cpu->eax < 0x10u) goto label_0008EF6D;
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->edi);
    cpu->ecx += cpu->edx;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x8EF66u), LIFT_CODE_TOKEN_RVA(0x8EF64u))) { return; }
    cpu->ebx = 0x10u;
    goto label_0008EFA4;
    label_0008EF6D:
    lift_push32(cpu, cpu->edi);
    cpu->ecx += cpu->edx;
    cpu->eax = cpu->esi;
    lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->ebx, LIFT_CODE_TOKEN_RVA(0x8EF78u), LIFT_CODE_TOKEN_RVA(0x8EF76u))) { return; }
    cpu->ebx = 0x10u;
    goto label_0008EFA4;
    label_0008EF7F:
    cpu->ebx = 0x10u;
    if (*(uint32_t*)(cpu->ecx + 0x14u) < cpu->ebx) goto label_0008EF8B;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    label_0008EF8B:
    if (*(uint32_t*)(cpu->esi + 0x14u) < cpu->ebx) goto label_0008EF94;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_0008EF96;
    label_0008EF94:
    cpu->eax = cpu->esi;
    label_0008EF96:
    cpu->ecx += *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->eax += cpu->ebp;
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memcpy), LIFT_CODE_TOKEN_VA(0x48EF9Fu));
    label_0008EFA4:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->esp += 0xCu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ecx;
    if (*(uint32_t*)(cpu->esi + 0x14u) < cpu->ebx) goto label_0008EFC2;
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax + cpu->ecx) = 0u;
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_0008EFC2:
    cpu->eax = cpu->esi;
    *(uint8_t*)(cpu->eax + cpu->ecx) = 0u;
    label_0008EFC8:
    cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_0008EFD1:
    lift_push32(cpu, (uintptr_t)"invalid string position");
    lift_trap(cpu, LIFT_CODE_TOKEN_VA(0x48EFD1u), "std::out_of_range");
    lift_trap(cpu, 0x48EFDCu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_0048EFE0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, 1u);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    cpu->ebx = cpu->edx;
    *(uint8_t*)(cpu->esp + 0x1Cu) = 0x3Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F001u)); sfera_sub_004312E0(cpu, LIFT_CODE_TOKEN_VA(0x48F001u));
    lift_push32(cpu, 1u);
    cpu->esi = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    *(uint8_t*)(cpu->esp + 0x24u) = 0x3Eu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F017u)); sfera_sub_004312E0(cpu, LIFT_CODE_TOKEN_VA(0x48F017u));
    cpu->ebp = cpu->eax;
    if (cpu->esi == 0xFFFFFFFFu) goto label_0008F063;
    if (cpu->ebp == 0xFFFFFFFFu) goto label_0008F063;
    cpu->eax -= cpu->esi;
    if (cpu->eax <= 1u) goto label_0008F063;
    if (cpu->ebx == 0u) goto label_0008F03C;
    --cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esi + 1u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8F03Cu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0x8F03Cu));
    label_0008F03C:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->eax == 0u) goto label_0008F046;
    *(uint32_t*)(cpu->eax) = cpu->esi;
    label_0008F046:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    if (cpu->eax == 0u) goto label_0008F059;
    ++cpu->ebp;
    if (cpu->ebp < *(uint32_t*)(cpu->edi + 0x10u)) goto label_0008F057;
    cpu->ebp |= 0xFFFFFFFFu;
    label_0008F057:
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    label_0008F059:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
    label_0008F063:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->eax == 0u) goto label_0008F071;
    *(uint32_t*)(cpu->eax) = 0xFFFFFFFFu;
    label_0008F071:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    if (cpu->eax == 0u) goto label_0008F07F;
    *(uint32_t*)(cpu->eax) = 0xFFFFFFFFu;
    label_0008F07F:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048F090(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esp;
    lift_push32(cpu, 1u);
    cpu->edi = cpu->ecx;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F0AAu)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F0AAu));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esp;
    if (cpu->ecx == 0u) goto label_0008F0D2;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == 0u) goto label_0008F0D2;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_0008F0D2:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F0E5u)); sfera_sub_0048EBC0(cpu, LIFT_CODE_TOKEN_VA(0x48F0E5u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048F0F0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (cpu->esi == cpu->ebx) goto label_0008F17B;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x34u);
    if (cpu->ebx == cpu->ebp) goto label_0008F17B;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    if (cpu->eax == 0u) goto label_0008F11E;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_0008F11E;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_0008F122;
    label_0008F11E:
    cpu->edx = 0u;
    goto label_0008F124;
    label_0008F122:
    cpu->edx = *(uint32_t*)(cpu->eax);
    label_0008F124:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    if (cpu->eax == 0u) goto label_0008F138;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_0008F138;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_0008F13C;
    label_0008F138:
    cpu->ecx = 0u;
    goto label_0008F13E;
    label_0008F13C:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_0008F13E:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->eax == 0u) goto label_0008F152;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_0008F152;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_0008F156;
    label_0008F152:
    cpu->eax = 0u;
    goto label_0008F158;
    label_0008F156:
    cpu->eax = *(uint32_t*)(cpu->eax);
    label_0008F158:
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->edx = 0u;
    cpu->ecx = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F167u)); sfera_sub_0048E800(cpu, LIFT_CODE_TOKEN_VA(0x48F167u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax -= cpu->ecx;
    cpu->esi += cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esi;
    label_0008F17B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->edi) = 0u;
    *(uint32_t*)(cpu->edi + 4u) = 0u;
    *(uint32_t*)(cpu->edi + 8u) = cpu->esi;
    if (cpu->eax == 0u) goto label_0008F19D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_0008F19D;
    cpu->eax = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->edi) = cpu->eax;
    label_0008F19D:
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 0x28u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048F1B0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->esp;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x4Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->ebp + 0xFFFFFFF4u;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFF0u) = cpu->esp;
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u) = cpu->edi;
    cpu->eax = cpu->ebp + 0xFFFFFFCCu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F1E9u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F1E9u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->eax -= cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x10u);
    *(uint32_t*)(cpu->ebp + 0xFFFFFFECu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1Cu);
    cpu->ebx = cpu->ecx;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->ebx;
    if (cpu->eax == *(uint32_t*)(cpu->ebp + 0x28u)) goto label_0008F400;
    cpu->ecx >>= 1u;
    if (*(uint32_t*)(cpu->ebp + 0xFFFFFFECu) > cpu->ecx) goto label_0008F348;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 0u;
    label_0008F220:
    if (cpu->eax == *(uint32_t*)(cpu->ebp + 0x28u)) goto label_0008F27D;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x14u);
    if (cpu->ecx!=0u) goto label_0008F230;
    cpu->esi=0u;
    goto label_0008F232;
    label_0008F230:
    cpu->esi = *(uint32_t*)(cpu->ecx);
    label_0008F232:
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 2u;
    cpu->eax &= 3u;
    if (cpu->edx > cpu->ecx) goto label_0008F243;
    cpu->ecx -= cpu->edx;
    label_0008F243:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u));
    cpu->edx = cpu->ecx + (cpu->eax * 4u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F254u)); sfera_sub_0048E750(cpu, LIFT_CODE_TOKEN_VA(0x48F254u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1Cu);
    ++cpu->eax;
    *(uint32_t*)(cpu->ebp + 0x1Cu) = cpu->eax;
    goto label_0008F220;
    label_0008F27D:
    cpu->esi = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->esi -= cpu->ebx;
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFC0u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F292u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F292u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F299u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F299u));
    cpu->edx = cpu->ebp + 0xFFFFFFCCu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F2A4u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F2A4u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    if (cpu->eax == 0u) goto label_0008F2BB;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_0008F2BB;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_0008F2BF;
    label_0008F2BB:
    cpu->ecx = 0u;
    goto label_0008F2C1;
    label_0008F2BF:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_0008F2C1:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->ecx);
    if (cpu->eax == 0u) goto label_0008F2D9;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_0008F2D9;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_0008F2DD;
    label_0008F2D9:
    cpu->ecx = 0u;
    goto label_0008F2DF;
    label_0008F2DD:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_0008F2DF:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F2E9u)); sfera_sub_0048DF30(cpu, LIFT_CODE_TOKEN_VA(0x48F2E9u));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ebp + 0xFFFFFFC0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFCCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F306u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F306u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F30Du)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F30Du));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F314u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F314u));
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0xFFFFFFB4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F329u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F329u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F330u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F330u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F340u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F340u));
    cpu->ecx = cpu->ebp + 0xFFFFFFA8u;
    goto label_0008F3FB;
    label_0008F348:
    *(uint32_t*)(cpu->ebp + 0xFFFFFFFCu) = 2u;
    (void)cpu;
    label_0008F350:
    if (cpu->eax == *(uint32_t*)(cpu->ebp + 0x28u)) goto label_0008F3AD;
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x14u);
    if (cpu->ecx!=0u) goto label_0008F360;
    cpu->esi=0u;
    goto label_0008F362;
    label_0008F360:
    cpu->esi = *(uint32_t*)(cpu->ecx);
    label_0008F362:
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->ecx = cpu->eax;
    cpu->ecx >>= 2u;
    cpu->eax &= 3u;
    if (cpu->edx > cpu->ecx) goto label_0008F373;
    cpu->ecx -= cpu->edx;
    label_0008F373:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u));
    cpu->edx = cpu->ecx + (cpu->eax * 4u);
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F384u)); sfera_sub_0048E6A0(cpu, LIFT_CODE_TOKEN_VA(0x48F384u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1Cu);
    ++cpu->eax;
    *(uint32_t*)(cpu->ebp + 0x1Cu) = cpu->eax;
    goto label_0008F350;
    label_0008F3AD:
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F3BDu)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x48F3BDu));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp + 0xFFFFFFA8u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F3D2u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F3D2u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F3D9u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F3D9u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebp + 0xFFFFFFB4u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F3F1u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F3F1u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F3F8u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F3F8u));
    cpu->ecx = cpu->ebp + 0xFFFFFFC0u;
    label_0008F3FB:
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8F400u)); sfera_sub_0048F0F0(cpu, LIFT_CODE_TOKEN_RVA(0x8F400u));
    label_0008F400:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048F25D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    if (cpu->edi >= *(uint32_t*)(cpu->esi + 0x10u)) goto label_0008F274;
    label_0008F268:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F26Fu)); sfera_sub_0048E0E0(cpu, LIFT_CODE_TOKEN_VA(0x48F26Fu));
    if (cpu->edi < *(uint32_t*)(cpu->esi + 0x10u)) goto label_0008F268;
    label_0008F274:
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F27Du)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x48F27Du));
    cpu->esi = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->esi -= cpu->ebx;
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ebp + 0xFFFFFFD8u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFC0u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F292u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F292u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F299u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F299u));
    cpu->edx = cpu->ebp + 0xFFFFFFCCu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F2A4u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F2A4u));
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x1Cu);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD8u);
    if (cpu->eax == 0u) goto label_0008F2BB;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_0008F2BB;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_0008F2BF;
    label_0008F2BB:
    cpu->ecx = 0u;
    goto label_0008F2C1;
    label_0008F2BF:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_0008F2C1:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFE0u);
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFCCu);
    lift_push32(cpu, cpu->ecx);
    if (cpu->eax == 0u) goto label_0008F2D9;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax == 0u) goto label_0008F2D9;
    cpu->eax = *(uint32_t*)(cpu->eax);
    if (cpu->eax != 0u) goto label_0008F2DD;
    label_0008F2D9:
    cpu->ecx = 0u;
    goto label_0008F2DF;
    label_0008F2DD:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_0008F2DF:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xFFFFFFD4u);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F2E9u)); sfera_sub_0048DF30(cpu, LIFT_CODE_TOKEN_VA(0x48F2E9u));
    cpu->edx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->ebp + 0xFFFFFFC0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0xFFFFFFCCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F306u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F306u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F30Du)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F30Du));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F314u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F314u));
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->ebp + 0xFFFFFFB4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F329u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F329u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F330u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F330u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F340u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F340u));
    cpu->ecx = cpu->ebp + 0xFFFFFFA8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F400u)); sfera_sub_0048F0F0(cpu, LIFT_CODE_TOKEN_VA(0x48F400u));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048F38D(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE8u);
    cpu->edi = *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u);
    if (cpu->edi >= *(uint32_t*)(cpu->esi + 0x10u)) goto label_0008F3A4;
    label_0008F398:
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F39Fu)); sfera_sub_0049FA20(cpu, LIFT_CODE_TOKEN_VA(0x48F39Fu));
    if (cpu->edi < *(uint32_t*)(cpu->esi + 0x10u)) goto label_0008F398;
    label_0008F3A4:
    lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F3ADu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x48F3ADu));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F3BDu)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x48F3BDu));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ebp + 0xFFFFFFA8u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F3D2u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F3D2u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F3D9u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F3D9u));
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0xFFFFFFECu);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->ebp + 0xFFFFFFE4u) = cpu->esp;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebp + 0xFFFFFFB4u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F3F1u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F3F1u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F3F8u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F3F8u));
    cpu->ecx = cpu->ebp + 0xFFFFFFC0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F400u)); sfera_sub_0048F0F0(cpu, LIFT_CODE_TOKEN_VA(0x48F400u));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp = cpu->ebp;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x2Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048F420(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x48u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x5Cu;
    cpu->edi = cpu->ecx;
    cpu->ebx = cpu->edx;
    if (*(uint32_t*)(cpu->edi + 0x10u) <= cpu->ebx) goto label_0008F5B4;
    if (*(uint32_t*)(cpu->esp + 0x6Cu) == 0xFFFFFFFFu) goto label_0008F5B4;
    lift_push32(cpu, cpu->ebx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F470u)); sfera_sub_0048EAC0(cpu, LIFT_CODE_TOKEN_VA(0x48F470u));
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->ecx = cpu->esi;
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    cpu->ebp = cpu->eax;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F483u)); sfera_sub_004312C0(cpu, LIFT_CODE_TOKEN_VA(0x48F483u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0008F5B4;
    cpu->eax = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F497u)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x48F497u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x6Cu);
    *(uint32_t*)(cpu->esp + 0x64u) = 0u;
    if (cpu->eax <= cpu->ecx) goto label_0008F4B0;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->ecx);
    goto label_0008F4B4;
    label_0008F4B0:
    lift_push32(cpu, 0xFFFFFFFFu);
    --cpu->eax;
    lift_push32(cpu, cpu->eax);
    label_0008F4B4:
    cpu->ecx = cpu->esp + 0x44u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F4BDu)); sfera_sub_00402810(cpu, LIFT_CODE_TOKEN_VA(0x48F4BDu));
    if (*(uint32_t*)(cpu->esp + 0x4Cu) == 0u) goto label_0008F550;
    cpu->eax = cpu->ebp;
    if ((cpu->eax -= 4u) == 0u) goto label_0008F542;
    if ((--cpu->eax) != 0u) goto label_0008F59C;
    cpu->edx = 0x220u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F4E5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48F4E5u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F4EBu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48F4EBu));
    cpu->esp += 4u;
    cpu->edx = 0x221u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F4FDu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48F4FDu));
    lift_push32(cpu, 0x34u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F504u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x48F504u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint8_t*)(cpu->esp + 0x64u) = 1u;
    if (cpu->eax == 0u) goto label_0008F534;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F526u)); sfera_sub_004315D0(cpu, LIFT_CODE_TOKEN_VA(0x48F526u));
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    cpu->esi = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F530u)); sfera_sub_0048EB20(cpu, LIFT_CODE_TOKEN_VA(0x48F530u));
    *(uint32_t*)(cpu->eax) = cpu->esi;
    goto label_0008F59C;
    label_0008F534:
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->edi;
    cpu->esi = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F53Eu)); sfera_sub_0048EB20(cpu, LIFT_CODE_TOKEN_VA(0x48F53Eu));
    *(uint32_t*)(cpu->eax) = cpu->esi;
    goto label_0008F59C;
    label_0008F542:
    cpu->edx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F54Eu)); sfera_sub_004317E0(cpu, LIFT_CODE_TOKEN_VA(0x48F54Eu));
    goto label_0008F59C;
    label_0008F550:
    cpu->edx = 0x227u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F55Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48F55Fu));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F565u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48F565u));
    cpu->esp += 4u;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F57Au)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F57Au));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F581u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F581u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F590u)); sfera_sub_0048DD80(cpu, LIFT_CODE_TOKEN_VA(0x48F590u));
    cpu->edx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8F59Cu)); sfera_sub_0048F090(cpu, LIFT_CODE_TOKEN_RVA(0x8F59Cu));
    label_0008F59C:
    if (*(uint32_t*)(cpu->esp + 0x50u) < 0x10u) goto label_0008F5B0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F5ADu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48F5ADu));
    cpu->esp += 4u;
    label_0008F5B0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    goto label_0008F5B6;
    label_0008F5B4:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    label_0008F5B6:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x54u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048F5E0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x1Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    sub_pred[0] = *(uint32_t*)(cpu->ebp + 0x10u) == 0u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    if (sub_pred[0]) goto label_0008F6B4;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F5FDu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F5FDu));
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F609u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x48F609u));
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->esi == *(uint32_t*)(cpu->eax + 8u)) goto label_0008F6B4;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    label_0008F620:
    cpu->edx = 0x356u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F62Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x48F62Fu));
    if (cpu->ebx!=0u) goto label_0008F637;
    cpu->edx=0u;
    goto label_0008F639;
    label_0008F637:
    cpu->edx = *(uint32_t*)(cpu->ebx);
    label_0008F639:
    cpu->edi = *(uint32_t*)(cpu->edx + 8u);
    cpu->eax = cpu->esi;
    cpu->ecx = cpu->esi;
    cpu->eax >>= 2u;
    cpu->ecx &= 3u;
    if (cpu->edi > cpu->eax) goto label_0008F64C;
    cpu->eax -= cpu->edi;
    label_0008F64C:
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->eax * 4u));
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->ecx * 4u));
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F65Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48F65Bu));
    cpu->esp -= 8u;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esp;
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    if (cpu->ebx == 0u) goto label_0008F67F;
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    if (cpu->ecx == 0u) goto label_0008F67F;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0008F67F:
    *(uint32_t*)(cpu->eax + 8u) = cpu->esi;
    cpu->eax = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F68Eu)); sfera_sub_0048F090(cpu, LIFT_CODE_TOKEN_VA(0x48F68Eu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ebx == cpu->ecx) goto label_0008F69C;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == 0u) goto label_0008F69C;
    cpu->ebx = *(uint32_t*)(cpu->ecx);
    label_0008F69C:
    cpu->esi = *(uint32_t*)(cpu->eax + 8u);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F6ABu)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x48F6ABu));
    if (cpu->esi != *(uint32_t*)(cpu->eax + 8u)) goto label_0008F620;
    label_0008F6B4:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048F6C0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0x30u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 8u;
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F6D1u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F6D1u));
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x48u);
    cpu->eax -= cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->ecx >>= 1u;
    cpu->edi = cpu->eax;
    sub_pred[0] = cpu->edi <= cpu->ecx;
    cpu->ecx = cpu->esi;
    if (!sub_pred[0]) goto label_0008F753;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F6F1u)); sfera_sub_0048E750(cpu, LIFT_CODE_TOKEN_VA(0x48F6F1u));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->esp;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F70Fu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F70Fu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F716u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F716u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F71Du)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F71Du));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->esp;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F735u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F735u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F73Cu)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F73Cu));
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->esp;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F74Du)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F74Du));
    cpu->ecx = cpu->esp + 0x50u;
    goto label_0008F7AF;
    label_0008F753:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x4Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F75Du)); sfera_sub_0048E6A0(cpu, LIFT_CODE_TOKEN_VA(0x48F75Du));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F76Eu)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x48F76Eu));
    cpu->esp -= 0xCu;
    cpu->edx = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->esp;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F786u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x48F786u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F78Du)); sfera_sub_0048E0A0(cpu, LIFT_CODE_TOKEN_VA(0x48F78Du));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->esp;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F7A4u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F7A4u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F7ABu)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F7ABu));
    cpu->ecx = cpu->esp + 0x38u;
    label_0008F7AF:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F7B4u)); sfera_sub_0048F0F0(cpu, LIFT_CODE_TOKEN_VA(0x48F7B4u));
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F7C6u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48F7C6u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F7CDu)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x48F7CDu));
    cpu->eax = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x30u;
    cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048F7E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esp;
    if (cpu->edx == 0u) goto label_0008F80E;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == 0u) goto label_0008F80E;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0008F80E:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esp;
    if (cpu->edx == 0u) goto label_0008F83D;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == 0u) goto label_0008F83D;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0008F83D:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esp;
    if (cpu->edx == 0u) goto label_0008F86C;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == 0u) goto label_0008F86C;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0008F86C:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x38u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F878u)); sfera_sub_0048F1B0(cpu, LIFT_CODE_TOKEN_VA(0x48F878u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 0x28u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048F880(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x3Cu;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x50u);
    cpu->edi = 0u;
    lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = cpu->esp + 0x24u;
    cpu->ebx = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x38u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edi;
    *(uint8_t*)(cpu->esp + 0x24u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F8E0u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x48F8E0u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edi;
    sub_pred[0] = cpu->eax == cpu->edi;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x4Cu);
    if (sub_pred[0]) goto label_0008F9DC;
    if (cpu->edi == 0xFFFFFFFFu) goto label_0008F9DC;
    if (cpu->edi >= cpu->eax) goto label_0008F9DC;
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_0008F90E;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_0008F910;
    label_0008F90E:
    cpu->eax = cpu->esi;
    label_0008F910:
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->eax + cpu->edi));
    lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::isalpha), LIFT_CODE_TOKEN_VA(0x48F915u));
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_0008F9DC;
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_0008F930;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_0008F932;
    label_0008F930:
    cpu->eax = cpu->esi;
    label_0008F932:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + cpu->edi));
    *(uint8_t*)(cpu->esp + 0x14u) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F949u)); sfera_sub_0048EDB0(cpu, LIFT_CODE_TOKEN_VA(0x48F949u));
    ++cpu->edi;
    if (cpu->edi >= *(uint32_t*)(cpu->esi + 0x10u)) goto label_0008F9A1;
    cpu->ebp = native_function_address32(&::isalnum);
    label_0008F955:
    if (cpu->edi == 0xFFFFFFFFu) goto label_0008F99D;
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_0008F964;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_0008F966;
    label_0008F964:
    cpu->eax = cpu->esi;
    label_0008F966:
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->eax + cpu->edi));
    lift_push32(cpu, cpu->eax);
    if (!lift_call_indirect(cpu, cpu->ebp, LIFT_CODE_TOKEN_RVA(0x8F96Du), LIFT_CODE_TOKEN_RVA(0x8F96Bu))) { return; }
    cpu->esp += 4u;
    if (cpu->eax == 0u) goto label_0008F99D;
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_0008F97E;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_0008F980;
    label_0008F97E:
    cpu->eax = cpu->esi;
    label_0008F980:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + cpu->edi));
    *(uint8_t*)(cpu->esp + 0x14u) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F997u)); sfera_sub_0048EDB0(cpu, LIFT_CODE_TOKEN_VA(0x48F997u));
    ++cpu->edi;
    if (cpu->edi < *(uint32_t*)(cpu->esi + 0x10u)) goto label_0008F955;
    label_0008F99D:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    label_0008F9A1:
    if (cpu->ebx == 0u) goto label_0008F9B5;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8F9B5u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0x8F9B5u));
    label_0008F9B5:
    if (cpu->ebp == 0u) goto label_0008F9C4;
    if (cpu->edi != *(uint32_t*)(cpu->esi + 0x10u)) goto label_0008F9C1;
    cpu->edi |= 0xFFFFFFFFu;
    label_0008F9C1:
    *(uint32_t*)(cpu->ebp) = cpu->edi;
    label_0008F9C4:
    if (*(uint32_t*)(cpu->esp + 0x30u) < 0x10u) goto label_0008F9D8;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F9D5u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48F9D5u));
    cpu->esp += 4u;
    label_0008F9D8:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    goto label_0008F9F9;
    label_0008F9DC:
    if (cpu->ebp == 0u) goto label_0008F9E3;
    *(uint32_t*)(cpu->ebp) = cpu->edi;
    label_0008F9E3:
    if (*(uint32_t*)(cpu->esp + 0x30u) < 0x10u) goto label_0008F9F7;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48F9F4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48F9F4u));
    cpu->esp += 4u;
    label_0008F9F7:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    label_0008F9F9:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048FA20(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x48u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x70u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx);
    cpu->esi = cpu->ecx;
    cpu->edi = 0xFu;
    lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = cpu->esp + 0x44u;
    cpu->ebp = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x44u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FA80u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x48FA80u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = cpu->esp + 0x28u;
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x28u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FA9Fu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x48FA9Fu));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x6Cu);
    *(uint8_t*)(cpu->esp + 0x64u) = 1u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    if (*(uint32_t*)(cpu->esi + 0x10u) == cpu->ebx) goto label_0008FB64;
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->esp + 0x20u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FAC1u)); sfera_sub_0048E030(cpu, LIFT_CODE_TOKEN_VA(0x48FAC1u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_0008FADA;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FAD5u)); sfera_sub_0048EDB0(cpu, LIFT_CODE_TOKEN_VA(0x48FAD5u));
    ++cpu->edi;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->edi;
    label_0008FADA:
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->esp + 0x44u;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FAEBu)); sfera_sub_0048F880(cpu, LIFT_CODE_TOKEN_VA(0x48FAEBu));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FAFCu)); sfera_sub_0048E270(cpu, LIFT_CODE_TOKEN_VA(0x48FAFCu));
    if (cpu->ebp == cpu->ebx) goto label_0008FB0F;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x8FB0Fu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0x8FB0Fu));
    label_0008FB0F:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    if (cpu->ecx == cpu->ebx) goto label_0008FB25;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 0x10u)) goto label_0008FB23;
    cpu->eax |= 0xFFFFFFFFu;
    label_0008FB23:
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    label_0008FB25:
    cpu->esi = 0x10u;
    if (*(uint32_t*)(cpu->esp + 0x34u) < cpu->esi) goto label_0008FB3D;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FB3Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48FB3Au));
    cpu->esp += 4u;
    label_0008FB3D:
    *(uint32_t*)(cpu->esp + 0x34u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x20u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x50u) < cpu->esi) goto label_0008FB60;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FB5Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48FB5Du));
    cpu->esp += 4u;
    label_0008FB60:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    goto label_0008FBA1;
    label_0008FB64:
    cpu->esi = 0x10u;
    if (*(uint32_t*)(cpu->esp + 0x34u) < cpu->esi) goto label_0008FB7C;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FB79u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48FB79u));
    cpu->esp += 4u;
    label_0008FB7C:
    *(uint32_t*)(cpu->esp + 0x34u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x20u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x50u) < cpu->esi) goto label_0008FB9F;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FB9Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48FB9Cu));
    cpu->esp += 4u;
    label_0008FB9F:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    label_0008FBA1:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x54u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048FBD0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x40u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x50u;
    cpu->ebx = 0u;
    cpu->esi = 0xFu;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x30u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0x38u;
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FC23u)); sfera_sub_0048F880(cpu, LIFT_CODE_TOKEN_VA(0x48FC23u));
    cpu->edi = cpu->esi + 1u;
    if ((cpu->eax & 0xFFu) == 0u) goto label_0008FD85;
    lift_push32(cpu, 3u); lift_push32(cpu, (uintptr_t)"hts");
    cpu->ecx = cpu->esp + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x1Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FC4Au)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x48FC4Au));
    cpu->edx = cpu->esp + 0x14u;
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FC57u)); sfera_sub_0048DFB0(cpu, LIFT_CODE_TOKEN_VA(0x48FC57u));
    *(uint8_t*)(cpu->esp + 0x13u) = cpu->eax & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x28u) < cpu->edi) goto label_0008FC6E;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FC6Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48FC6Bu));
    cpu->esp += 4u;
    label_0008FC6E:
    if (*(uint8_t*)(cpu->esp + 0x13u) == (cpu->ebx & 0xFFu)) goto label_0008FC8E;
    if (*(uint32_t*)(cpu->esp + 0x44u) < cpu->edi) goto label_0008FC87;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FC84u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48FC84u));
    cpu->esp += 4u;
    label_0008FC87:
    cpu->eax = 0u;
    goto label_0008FD9D;
    label_0008FC8E:
    lift_push32(cpu, 6u); lift_push32(cpu, (uintptr_t)"mailto");
    cpu->ecx = cpu->esp + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x1Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FCAAu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x48FCAAu));
    cpu->edx = cpu->esp + 0x14u;
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FCB7u)); sfera_sub_0048DFB0(cpu, LIFT_CODE_TOKEN_VA(0x48FCB7u));
    *(uint8_t*)(cpu->esp + 0x13u) = cpu->eax & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x28u) < cpu->edi) goto label_0008FCCE;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FCCBu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48FCCBu));
    cpu->esp += 4u;
    label_0008FCCE:
    if (*(uint8_t*)(cpu->esp + 0x13u) == (cpu->ebx & 0xFFu)) goto label_0008FCF1;
    if (*(uint32_t*)(cpu->esp + 0x44u) < cpu->edi) goto label_0008FCE7;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FCE4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48FCE4u));
    cpu->esp += 4u;
    label_0008FCE7:
    cpu->eax = 3u;
    goto label_0008FD9D;
    label_0008FCF1:
    lift_push32(cpu, 4u); lift_push32(cpu, (uintptr_t)"item");
    cpu->ecx = cpu->esp + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x1Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FD0Du)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x48FD0Du));
    cpu->edx = cpu->esp + 0x14u;
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FD1Au)); sfera_sub_0048DFB0(cpu, LIFT_CODE_TOKEN_VA(0x48FD1Au));
    *(uint8_t*)(cpu->esp + 0x13u) = cpu->eax & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x28u) < cpu->edi) goto label_0008FD31;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FD2Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48FD2Eu));
    cpu->esp += 4u;
    label_0008FD31:
    if (*(uint8_t*)(cpu->esp + 0x13u) == (cpu->ebx & 0xFFu)) goto label_0008FD47;
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FD40u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x48FD40u));
    cpu->eax = 1u;
    goto label_0008FD9D;
    label_0008FD47:
    lift_push32(cpu, (uintptr_t)"player");
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FD55u)); sfera_sub_004090F0(cpu, LIFT_CODE_TOKEN_VA(0x48FD55u));
    cpu->edx = cpu->esp + 0x14u;
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FD62u)); sfera_sub_0048DFB0(cpu, LIFT_CODE_TOKEN_VA(0x48FD62u));
    cpu->ecx = cpu->esp + 0x14u;
    *(uint8_t*)(cpu->esp + 0x13u) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FD6Fu)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x48FD6Fu));
    if (*(uint8_t*)(cpu->esp + 0x13u) == (cpu->ebx & 0xFFu)) goto label_0008FD85;
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FD7Eu)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x48FD7Eu));
    cpu->eax = 2u;
    goto label_0008FD9D;
    label_0008FD85:
    if (*(uint32_t*)(cpu->esp + 0x44u) < cpu->edi) goto label_0008FD98;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FD95u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48FD95u));
    cpu->esp += 4u;
    label_0008FD98:
    cpu->eax = 4u;
    label_0008FD9D:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x4Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048FDC0(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x44u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x50u;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    lift_push32(cpu, 2u);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, (uintptr_t)"\\l");
    cpu->ecx = cpu->esp + 0x38u;
    *(uint32_t*)(cpu->esp + 0x4Cu) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x38u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FE18u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x48FE18u));
    cpu->edx = cpu->esp + 0x30u;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FE2Fu)); sfera_sub_0048DFB0(cpu, LIFT_CODE_TOKEN_VA(0x48FE2Fu));
    if ((cpu->eax & 0xFFu) != 0u) goto label_0008FE6E;
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"/l");
    cpu->ecx = cpu->esp + 0x1Cu;
    *(uint32_t*)(cpu->esp + 0x30u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x1Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FE53u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x48FE53u));
    cpu->edx = cpu->esp + 0x14u;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = 3u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FE66u)); sfera_sub_0048DFB0(cpu, LIFT_CODE_TOKEN_VA(0x48FE66u));
    *(uint8_t*)(cpu->esp + 0xFu) = cpu->ebx & 0xFFu;
    if ((cpu->eax & 0xFFu) == 0u) goto label_0008FE73;
    label_0008FE6E:
    *(uint8_t*)(cpu->esp + 0xFu) = 1u;
    label_0008FE73:
    lift_test[0]=(*(uint8_t*)(cpu->esp + 0x10u)&2u)==0u;
    cpu->esi = 0x10u;
    if (lift_test[0]) goto label_0008FEA7;
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) & (uint64_t)(0xFFFFFFFDu);
    if (*(uint32_t*)(cpu->esp + 0x28u) < cpu->esi) goto label_0008FE97;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FE94u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48FE94u));
    cpu->esp += 4u;
    label_0008FE97:
    *(uint32_t*)(cpu->esp + 0x28u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x14u) = cpu->ebx & 0xFFu;
    label_0008FEA7:
    if (((*(uint8_t*)(cpu->esp + 0x10u)) & (1u)) == 0u) goto label_0008FEC1;
    if (*(uint32_t*)(cpu->esp + 0x44u) < cpu->esi) goto label_0008FEC1;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FEBEu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x48FEBEu));
    cpu->esp += 4u;
    label_0008FEC1:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0xFu));
    cpu->ecx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x50u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048FEF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esp;
    if (cpu->edx == 0u) goto label_0008FF1E;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == 0u) goto label_0008FF1E;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0008FF1E:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FF2Fu)); sfera_sub_0048F6C0(cpu, LIFT_CODE_TOKEN_VA(0x48FF2Fu));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0x18u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_0048FF40(LiftCpu* cpu, uint32_t stop_address) {
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0xCu;
    lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FF51u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x48FF51u));
    cpu->esp -= 0xCu;
    cpu->edi = 0u;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ecx) = cpu->edi;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esp;
    if (cpu->edx == cpu->edi) goto label_0008FF71;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == cpu->edi) goto label_0008FF71;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    label_0008FF71:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FF83u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x48FF83u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ecx) = cpu->edi;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esp;
    if (cpu->edx == cpu->edi) goto label_0008FFA1;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == cpu->edi) goto label_0008FFA1;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    label_0008FFA1:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x48FFB3u)); sfera_sub_0048EBC0(cpu, LIFT_CODE_TOKEN_VA(0x48FFB3u));
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edi;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x4Cu);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esp;
    if (cpu->ecx == cpu->edi) goto label_0008FFD3;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->edi) goto label_0008FFD3;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0008FFD3:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x54u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->edi;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edi;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x4Cu);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esp;
    if (cpu->ecx == cpu->edi) goto label_0008FFFA;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->edi) goto label_0008FFFA;
    cpu->edx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0008FFFA:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x54u);
    cpu->edx = cpu->esp + 0x3Cu;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49000Du)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x49000Du));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->ecx) = cpu->edi;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edi;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->esp;
    if (cpu->edx == cpu->edi) goto label_0009002B;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == cpu->edi) goto label_0009002B;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->ecx) = cpu->edx;
    label_0009002B:
    cpu->eax = *(uint32_t*)(cpu->eax + 8u);
    *(uint32_t*)(cpu->ecx + 8u) = cpu->eax;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490038u)); sfera_sub_0048F7E0(cpu, LIFT_CODE_TOKEN_VA(0x490038u));
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->esp += 0x28u;
    cpu->esp += 0x20u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00490040(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x3Cu;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x4Cu);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x50u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x54u);
    cpu->edi = cpu->ecx;
    cpu->ebx = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->esi == 0xFFFFFFFFu) goto label_0009014A;
    if (cpu->esi >= *(uint32_t*)(cpu->edi + 0x10u)) goto label_000900C1;
    cpu->eax = (uintptr_t)g_sfera_server_parser_whitespace;
    cpu->ecx = sizeof(g_sfera_server_parser_whitespace) - 1u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4900BBu)); sfera_sub_0048DC80(cpu, LIFT_CODE_TOKEN_VA(0x4900BBu));
    cpu->esi = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    label_000900C1:
    if (cpu->esi == 0xFFFFFFFFu) goto label_0009014A;
    cpu->eax = (uintptr_t)g_sfera_server_parser_whitespace;
    cpu->edx = sizeof(g_sfera_server_parser_whitespace) - 1u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4900EDu)); sfera_sub_0048DC00(cpu, LIFT_CODE_TOKEN_VA(0x4900EDu));
    cpu->ebp = cpu->eax;
    if (cpu->ebx == 0u) goto label_00090132;
    if (cpu->ebp != 0xFFFFFFFFu) goto label_000900FC;
    cpu->eax |= cpu->eax;
    goto label_00090100;
    label_000900FC:
    cpu->eax = cpu->ebp;
    cpu->eax -= cpu->esi;
    label_00090100:
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49010Eu)); sfera_sub_00431640(cpu, LIFT_CODE_TOKEN_VA(0x49010Eu));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x48u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49011Eu)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x49011Eu));
    if (*(uint32_t*)(cpu->esp + 0x30u) < 0x10u) goto label_00090132;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49012Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49012Fu));
    cpu->esp += 4u;
    label_00090132:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    if (cpu->eax == 0u) goto label_0009013C;
    *(uint32_t*)(cpu->eax) = cpu->esi;
    label_0009013C:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->eax == 0u) goto label_00090146;
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    label_00090146:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    goto label_00090161;
    label_0009014A:
    if (cpu->ebp == 0u) goto label_00090155;
    *(uint32_t*)(cpu->ebp) = 0xFFFFFFFFu;
    label_00090155:
    if (cpu->eax == 0u) goto label_0009015F;
    *(uint32_t*)(cpu->eax) = 0xFFFFFFFFu;
    label_0009015F:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    label_00090161:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00490190(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, 0u);
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4901AAu)); sfera_sub_0048E480(cpu, LIFT_CODE_TOKEN_VA(0x4901AAu));
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4901C3u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x4901C3u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004901D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->edx + 0x10u);
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->edx + 0x14u);
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->ebp -= cpu->eax;
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    if (cpu->edi <= cpu->ebp) goto label_00090208;
    cpu->ebp = *(uint32_t*)(cpu->ecx + 0x14u);
    cpu->ebp -= cpu->edi;
    if (cpu->ebp < cpu->eax) goto label_00090208;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490206u)); sfera_sub_0048EE60(cpu, LIFT_CODE_TOKEN_VA(0x490206u));
    goto label_00090214;
    label_00090208:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x90214u)); sfera_sub_0048E270(cpu, LIFT_CODE_TOKEN_RVA(0x90214u));
    label_00090214:
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49022Du)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x49022Du));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00490240(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->edx;
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49025Au)); sfera_sub_0048EDB0(cpu, LIFT_CODE_TOKEN_VA(0x49025Au));
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490273u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x490273u));
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00490280(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    cpu->ebp = cpu->edx;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    *(uint8_t*)(cpu->esi) = 0u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x10u);
    cpu->edi = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->eax += cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = 1u;
    if (cpu->edi > cpu->eax) goto label_00090310;
    if (*(uint32_t*)(cpu->esi + 0x14u) == cpu->eax) goto label_00090310;
    lift_push32(cpu, 1u); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4902F9u)); sfera_sub_00403CA0(cpu, LIFT_CODE_TOKEN_VA(0x4902F9u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00090310;
    sub_pred[0] = *(uint32_t*)(cpu->esi + 0x14u) < 0x10u;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    if (sub_pred[0]) goto label_0009030A;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_0009030C;
    label_0009030A:
    cpu->eax = cpu->esi;
    label_0009030C:
    *(uint8_t*)(cpu->eax + cpu->edi) = 0u;
    label_00090310:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49031Cu)); sfera_sub_0048E270(cpu, LIFT_CODE_TOKEN_VA(0x49031Cu));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49032Cu)); sfera_sub_0048E270(cpu, LIFT_CODE_TOKEN_VA(0x49032Cu));
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00490350(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->esp;
    if (cpu->edx == 0u) goto label_0009037E;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == 0u) goto label_0009037E;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_0009037E:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->eax) = 0u;
    *(uint32_t*)(cpu->eax + 4u) = 0u;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->esp;
    if (cpu->edx == 0u) goto label_000903AD;
    cpu->edx = *(uint32_t*)(cpu->edx);
    if (cpu->edx == 0u) goto label_000903AD;
    cpu->edx = *(uint32_t*)(cpu->edx);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    label_000903AD:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4903B9u)); sfera_sub_0048FF40(cpu, LIFT_CODE_TOKEN_VA(0x4903B9u));
    cpu->ecx = lift_pop32(cpu); cpu->esp += 0x1Cu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004903C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = cpu->edi;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0xCu) = 0u;
    cpu->ebp = cpu->eax + 1u;
    label_000903D7:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ecx & 0xFFu) != 0u) goto label_000903D7;
    cpu->eax -= cpu->ebp;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4903E9u)); sfera_sub_0048E360(cpu, LIFT_CODE_TOKEN_VA(0x4903E9u));
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490402u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x490402u));
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00490410(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x28u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x3Cu;
    cpu->ebx = 0u;
    cpu->esi = cpu->ecx;
    lift_push32(cpu, 0xFFFFFFFFu);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esi;
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490467u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x490467u));
    cpu->eax = (uintptr_t)g_sfera_server_parser_whitespace;
    cpu->ebp = 0x10u;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = 1u;
    cpu->ecx = sizeof(g_sfera_server_parser_whitespace) - 1u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49049Au)); sfera_sub_0048DC80(cpu, LIFT_CODE_TOKEN_VA(0x49049Au));
    cpu->edi = cpu->eax;
    cpu->eax = (uintptr_t)g_sfera_server_parser_whitespace;
    cpu->edx = sizeof(g_sfera_server_parser_whitespace) - 1u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4904BFu)); sfera_sub_0048DCF0(cpu, LIFT_CODE_TOKEN_VA(0x4904BFu));
    if (cpu->edi == 0xFFFFFFFFu) goto label_000904FF;
    if (cpu->eax == 0xFFFFFFFFu) goto label_000904FF;
    cpu->eax -= cpu->edi;
    ++cpu->eax;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4904DAu)); sfera_sub_00431640(cpu, LIFT_CODE_TOKEN_VA(0x4904DAu));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x48u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4904EAu)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x4904EAu));
    if (*(uint32_t*)(cpu->esp + 0x30u) < cpu->ebp) goto label_0009050F;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4904FAu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4904FAu));
    cpu->esp += 4u;
    goto label_0009050F;
    label_000904FF:
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    if (*(uint32_t*)(cpu->esi + 0x14u) < cpu->ebp) goto label_0009050B;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_0009050D;
    label_0009050B:
    cpu->eax = cpu->esi;
    label_0009050D:
    *(uint8_t*)(cpu->eax) = cpu->ebx & 0xFFu;
    label_0009050F:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x34u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00490530(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 0u;
    lift_push32(cpu, 0xFFFFFFFFu);
    cpu->esi = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->edi;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    *(uint8_t*)(cpu->esi) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490553u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x490553u));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0x10u);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->eax != *(uint32_t*)(cpu->ebx + 0x10u)) goto label_000905BF;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    if (cpu->eax == cpu->edi) goto label_000905BF;
    if (cpu->eax == 0u) goto label_000905BF;
    label_00090570:
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_0009057A;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_0009057C;
    label_0009057A:
    cpu->eax = cpu->esi;
    label_0009057C:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + cpu->edi));
    lift_push32(cpu, 1u); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->esp + 0x24u) = cpu->eax & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490593u)); sfera_sub_004312E0(cpu, LIFT_CODE_TOKEN_VA(0x490593u));
    if (cpu->eax == 0xFFFFFFFFu) goto label_000905B9;
    cpu->ecx = 0x10u;
    if (*(uint32_t*)(cpu->ebx + 0x14u) < cpu->ecx) goto label_000905A6;
    cpu->edx = *(uint32_t*)(cpu->ebx);
    goto label_000905A8;
    label_000905A6:
    cpu->edx = cpu->ebx;
    label_000905A8:
    if (*(uint32_t*)(cpu->esi + 0x14u) < cpu->ecx) goto label_000905B1;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    goto label_000905B3;
    label_000905B1:
    cpu->ecx = cpu->esi;
    label_000905B3:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx + cpu->eax));
    *(uint8_t*)(cpu->ecx + cpu->edi) = cpu->edx & 0xFFu;
    label_000905B9:
    ++cpu->edi;
    if (cpu->edi < *(uint32_t*)(cpu->esi + 0x10u)) goto label_00090570;
    label_000905BF:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004905D0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xCu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x1Cu;
    cpu->edi = cpu->edx;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    lift_push32(cpu, (uintptr_t)"");
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49061Fu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x49061Fu));
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x10u) = 1u;
    if (*(uint32_t*)(cpu->edi + 0x10u) <= cpu->ebx) goto label_000906C6;
    label_00090634:
    cpu->ecx = *(uint32_t*)(cpu->edi + 0x14u);
    if (cpu->ecx < 0x10u) goto label_00090640;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_00090642;
    label_00090640:
    cpu->eax = cpu->edi;
    label_00090642:
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->eax + cpu->ebx));
    cpu->eax += 0xFFFFFFDEu;
    if (cpu->eax > 0x3Au) goto label_0009069C;
    switch (cpu->eax) {
        case 0u: goto label_0009067C;
        case 26u: goto label_0009065C;
        case 28u: goto label_0009066C;
        case 58u: goto label_0009068C;
        default: goto label_0009069C;
    }
label_0009065C: ;
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"\\[");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49066Au)); sfera_sub_0048E360(cpu, LIFT_CODE_TOKEN_VA(0x49066Au));
    goto label_000906BC;
    label_0009066C:
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"\\]");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49067Au)); sfera_sub_0048E360(cpu, LIFT_CODE_TOKEN_VA(0x49067Au));
    goto label_000906BC;
    label_0009067C:
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"\\\"");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49068Au)); sfera_sub_0048E360(cpu, LIFT_CODE_TOKEN_VA(0x49068Au));
    goto label_000906BC;
    label_0009068C:
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"\\\\");
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49069Au)); sfera_sub_0048E360(cpu, LIFT_CODE_TOKEN_VA(0x49069Au));
    goto label_000906BC;
    label_0009069C:
    if (cpu->ecx < 0x10u) goto label_000906A5;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_000906A7;
    label_000906A5:
    cpu->eax = cpu->edi;
    label_000906A7:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + cpu->ebx));
    *(uint8_t*)(cpu->esp + 0x14u) = cpu->ecx & 0xFFu;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x906BCu)); sfera_sub_0048EDB0(cpu, LIFT_CODE_TOKEN_RVA(0x906BCu));
    label_000906BC:
    ++cpu->ebx;
    if (cpu->ebx < *(uint32_t*)(cpu->edi + 0x10u)) goto label_00090634;
    label_000906C6:
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x18u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00490730(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x10u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x24u;
    cpu->edi = cpu->edx;
    cpu->ebp = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebp;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->ebp + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->ebp + 0x10u) = cpu->ebx;
    lift_push32(cpu, (uintptr_t)"");
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint8_t*)(cpu->ebp) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490781u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x490781u));
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    cpu->esi = 0u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = 1u;
    if (cpu->eax <= cpu->ebx) goto label_0009085A;
    cpu->ebx = cpu->esi + 1u;
    label_000907A0:
    cpu->edx = *(uint32_t*)(cpu->edi + 0x14u);
    if (cpu->edx < 0x10u) goto label_000907AC;
    cpu->ecx = *(uint32_t*)(cpu->edi);
    goto label_000907AE;
    label_000907AC:
    cpu->ecx = cpu->edi;
    label_000907AE:
    if (*(uint8_t*)(cpu->ecx + cpu->esi) != 0x5Cu) goto label_0009082D;
    if (cpu->ebx >= cpu->eax) goto label_00090829;
    if (cpu->edx < 0x10u) goto label_000907C1;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_000907C3;
    label_000907C1:
    cpu->eax = cpu->edi;
    label_000907C3:
    cpu->eax = (int8_t)(*(uint8_t*)(cpu->eax + cpu->esi + 1u));
    if ((cpu->eax -= 0x5Bu) == 0u) goto label_0009081E;
    if ((cpu->eax -= 2u) == 0u) goto label_0009080F;
    if (cpu->edx < 0x10u) goto label_000907F3;
    cpu->eax = *(uint32_t*)(cpu->edi);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + cpu->esi + 1u));
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->eax & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4907EFu)); sfera_sub_0048EDB0(cpu, LIFT_CODE_TOKEN_VA(0x4907EFu));
    ++cpu->esi;
    ++cpu->ebx;
    goto label_0009084D;
    label_000907F3:
    cpu->eax = cpu->edi;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + cpu->esi + 1u));
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->eax & 0xFFu;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49080Bu)); sfera_sub_0048EDB0(cpu, LIFT_CODE_TOKEN_VA(0x49080Bu));
    ++cpu->esi;
    ++cpu->ebx;
    goto label_0009084D;
    label_0009080F:
    lift_push32(cpu, 0x3Eu); lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49081Au)); sfera_sub_0048EDB0(cpu, LIFT_CODE_TOKEN_VA(0x49081Au));
    ++cpu->esi;
    ++cpu->ebx;
    goto label_0009084D;
    label_0009081E:
    lift_push32(cpu, 0x3Cu); lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x90829u)); sfera_sub_0048EDB0(cpu, LIFT_CODE_TOKEN_RVA(0x90829u));
    label_00090829:
    ++cpu->esi;
    ++cpu->ebx;
    goto label_0009084D;
    label_0009082D:
    if (cpu->edx < 0x10u) goto label_00090836;
    cpu->eax = *(uint32_t*)(cpu->edi);
    goto label_00090838;
    label_00090836:
    cpu->eax = cpu->edi;
    label_00090838:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax + cpu->esi));
    *(uint8_t*)(cpu->esp + 0x1Cu) = cpu->edx & 0xFFu;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, 1u);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9084Du)); sfera_sub_0048EDB0(cpu, LIFT_CODE_TOKEN_RVA(0x9084Du));
    label_0009084D:
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    ++cpu->esi;
    ++cpu->ebx;
    if (cpu->esi < cpu->eax) goto label_000907A0;
    label_0009085A:
    cpu->eax = cpu->ebp;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1Cu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00490870(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x6Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x80u;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x90u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x94u);
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = 0u;
    if (cpu->ebx == 0xFFFFFFFFu) goto label_00090995;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x10u);
    cpu->edx = cpu->ecx + 0xFFFFFFFFu;
    if (cpu->ebx >= cpu->edx) goto label_00090995;
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_000908E6;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_000908E8;
    label_000908E6:
    cpu->eax = cpu->esi;
    label_000908E8:
    if (*(uint8_t*)(cpu->eax + cpu->ebx) != 0x22u) goto label_00090995;
    cpu->edx = cpu->ebx + 1u;
    cpu->ebp = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edx;
    if (cpu->ebp >= cpu->ecx) goto label_00090995;
    cpu->edi = cpu->ebp;
    cpu->edi -= cpu->ebx;
    --cpu->edi;
    goto label_00090914;
    label_00090910:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    label_00090914:
    if (*(uint32_t*)(cpu->esi + 0x14u) < 0x10u) goto label_0009091E;
    cpu->eax = *(uint32_t*)(cpu->esi);
    goto label_00090920;
    label_0009091E:
    cpu->eax = cpu->esi;
    label_00090920:
    if (*(uint8_t*)(cpu->eax + cpu->ebp) != 0x22u) goto label_0009098A;
    lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490934u)); sfera_sub_00431640(cpu, LIFT_CODE_TOKEN_VA(0x490934u));
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->ecx;
    if (*(uint32_t*)(cpu->esp + 0x38u) == cpu->ecx) goto label_00090966;
    lift_push32(cpu, 1u); lift_push32(cpu, 0xFFFFFFFFu);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x34u;
    *(uint8_t*)(cpu->esp + 0x20u) = 0x5Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49095Au)); sfera_sub_0048DCF0(cpu, LIFT_CODE_TOKEN_VA(0x49095Au));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    if (cpu->eax == 0xFFFFFFFFu) goto label_00090966;
    cpu->ecx -= cpu->eax;
    --cpu->ecx;
    label_00090966:
    if ((((cpu->ecx & 0xFFu)) & (1u)) == 0u) goto label_000909BB;
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0x3Cu) < 0x10u;
    *(uint32_t*)(cpu->esp + 0x88u) = 0xFFFFFFFFu;
    if (sub_pred[0]) goto label_0009098A;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490987u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x490987u));
    cpu->esp += 4u;
    label_0009098A:
    ++cpu->ebp;
    ++cpu->edi;
    if (cpu->ebp < *(uint32_t*)(cpu->esi + 0x10u)) goto label_00090910;
    label_00090995:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    label_00090997:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x78u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000909BB:
    if (*(uint32_t*)(cpu->esp + 0x18u) == 0u) goto label_00090A34;
    cpu->eax = cpu->ebp;
    cpu->eax -= cpu->ebx;
    if (cpu->eax <= 1u) goto label_000909ED;
    --cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x68u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4909DEu)); sfera_sub_00431640(cpu, LIFT_CODE_TOKEN_VA(0x4909DEu));
    *(uint8_t*)(cpu->esp + 0x88u) = 1u;
    cpu->ebx = 1u;
    goto label_00090A07;
    label_000909ED:
    lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = cpu->esp + 0x48u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4909FBu)); sfera_sub_004090F0(cpu, LIFT_CODE_TOKEN_VA(0x4909FBu));
    cpu->ebx = 2u;
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->ebx;
    label_00090A07:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490A15u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x490A15u));
    if ((((cpu->ebx & 0xFFu)) & (2u)) == 0u) goto label_00090A26;
    cpu->ecx = cpu->esp + 0x44u;
    cpu->ebx &= 0xFFFFFFFDu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x90A26u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_RVA(0x90A26u));
    label_00090A26:
    if ((((cpu->ebx & 0xFFu)) & (1u)) == 0u) goto label_00090A34;
    cpu->ecx = cpu->esp + 0x60u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x90A34u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_RVA(0x90A34u));
    label_00090A34:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x24u);
    if (cpu->eax == 0u) goto label_00090A47;
    ++cpu->ebp;
    if (cpu->ebp < *(uint32_t*)(cpu->esi + 0x10u)) goto label_00090A45;
    cpu->ebp |= 0xFFFFFFFFu;
    label_00090A45:
    *(uint32_t*)(cpu->eax) = cpu->ebp;
    label_00090A47:
    if (*(uint32_t*)(cpu->esp + 0x3Cu) < 0x10u) goto label_00090A5B;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490A58u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x490A58u));
    cpu->esp += 4u;
    label_00090A5B:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    goto label_00090997;
}
__declspec(noinline) void sfera_sub_00490A70(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x48u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x6Cu);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x70u);
    cpu->esi = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x74u);
    cpu->ebp = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ecx;
    if (cpu->eax == 0xFFFFFFFFu) goto label_00090AEE;
    if (cpu->eax >= *(uint32_t*)(cpu->esi + 0x10u)) goto label_00090AEE;
    cpu->ecx = (uintptr_t)g_sfera_server_parser_whitespace;
    cpu->edi = 0x10u;
    cpu->edx = sizeof(g_sfera_server_parser_whitespace) - 1u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490AECu)); sfera_sub_0048DC80(cpu, LIFT_CODE_TOKEN_VA(0x490AECu));
    goto label_00090AF3;
    label_00090AEE:
    cpu->edi = 0x10u;
    label_00090AF3:
    if (cpu->eax == 0xFFFFFFFFu) goto label_00090C2C;
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    if (cpu->eax >= cpu->edx) goto label_00090C2C;
    if (*(uint32_t*)(cpu->esi + 0x14u) < cpu->edi) goto label_00090B10;
    cpu->ecx = *(uint32_t*)(cpu->esi);
    goto label_00090B12;
    label_00090B10:
    cpu->ecx = cpu->esi;
    label_00090B12:
    if (*(uint8_t*)(cpu->ecx + cpu->eax) != 0x3Du) goto label_00090C2C;
    ++cpu->eax;
    if (cpu->eax == 0xFFFFFFFFu) goto label_00090B49;
    if (cpu->eax >= cpu->edx) goto label_00090B49;
    cpu->ecx = (uintptr_t)g_sfera_server_parser_whitespace;
    cpu->edx = sizeof(g_sfera_server_parser_whitespace) - 1u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x90B49u)); sfera_sub_0048DC80(cpu, LIFT_CODE_TOKEN_RVA(0x90B49u));
    label_00090B49:
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    if (cpu->eax == 0xFFFFFFFFu) goto label_00090C2C;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x34u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x20u) = cpu->ebx & 0xFFu;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x28u;
    cpu->ecx = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490B7Du)); sfera_sub_00490870(cpu, LIFT_CODE_TOKEN_VA(0x490B7Du));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00090C19;
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490B8Eu)); sfera_sub_0048FBD0(cpu, LIFT_CODE_TOKEN_VA(0x490B8Eu));
    cpu->edi = cpu->eax;
    if (cpu->edi == 2u) goto label_00090B9A;
    if (cpu->edi != 1u) goto label_00090BCE;
    label_00090B9A:
    cpu->edx = cpu->esp + 0x20u;
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490BA7u)); sfera_sub_00490730(cpu, LIFT_CODE_TOKEN_VA(0x490BA7u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x24u;
    *(uint8_t*)(cpu->esp + 0x68u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490BB6u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x490BB6u));
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0x50u) < 0x10u;
    *(uint8_t*)(cpu->esp + 0x64u) = cpu->ebx & 0xFFu;
    if (sub_pred[0]) goto label_00090BCE;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490BCBu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x490BCBu));
    cpu->esp += 4u;
    label_00090BCE:
    if (cpu->ebp == cpu->ebx) goto label_00090BE1;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x90BE1u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0x90BE1u));
    label_00090BE1:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    if (cpu->eax == cpu->ebx) goto label_00090BEB;
    *(uint32_t*)(cpu->eax) = cpu->edi;
    label_00090BEB:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    if (cpu->ecx == cpu->ebx) goto label_00090C01;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->eax != *(uint32_t*)(cpu->esi + 0x10u)) goto label_00090BFF;
    cpu->eax |= 0xFFFFFFFFu;
    label_00090BFF:
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    label_00090C01:
    if (*(uint32_t*)(cpu->esp + 0x34u) < 0x10u) goto label_00090C15;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490C12u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x490C12u));
    cpu->esp += 4u;
    label_00090C15:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    goto label_00090C2E;
    label_00090C19:
    if (*(uint32_t*)(cpu->esp + 0x34u) < cpu->edi) goto label_00090C2C;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490C29u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x490C29u));
    cpu->esp += 4u;
    label_00090C2C:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    label_00090C2E:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x54u;
    cpu->esp += 0x10u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00490C50(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[4];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x130u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x154u);
    cpu->ebx = 0u;
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ecx;
    cpu->edi = 0u;
    cpu->esi = 0xFu;
    lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = cpu->esp + 0x110u;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x124u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x120u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x110u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490CD6u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x490CD6u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = cpu->esp + 0x12Cu;
    *(uint32_t*)(cpu->esp + 0x154u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x140u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x13Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x12Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490D04u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x490D04u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = cpu->esp + 0x68u;
    *(uint8_t*)(cpu->esp + 0x154u) = 1u;
    *(uint32_t*)(cpu->esp + 0x7Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x78u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x68u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490D27u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x490D27u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = cpu->esp + 0xD8u;
    *(uint8_t*)(cpu->esp + 0x154u) = 2u;
    *(uint32_t*)(cpu->esp + 0xECu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xE8u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0xD8u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490D56u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x490D56u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = cpu->esp + 0x4Cu;
    *(uint8_t*)(cpu->esp + 0x154u) = 3u;
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x5Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x4Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490D79u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x490D79u));
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0x114u;
    *(uint8_t*)(cpu->esp + 0x158u) = 4u;
    *(uint32_t*)(cpu->esp + 0x44u) = 4u;
    cpu->ebp = 0u;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x23u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490DAEu)); sfera_sub_0048EFE0(cpu, LIFT_CODE_TOKEN_VA(0x490DAEu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000912DA;
    label_00090DB6:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x34u);
    cpu->eax -= cpu->edi;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0xBCu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490DCFu)); sfera_sub_00431640(cpu, LIFT_CODE_TOKEN_VA(0x490DCFu));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = cpu->esp + 0x84u;
    *(uint8_t*)(cpu->esp + 0x154u) = 5u;
    *(uint32_t*)(cpu->esp + 0x98u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x94u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x84u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490DFEu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x490DFEu));
    cpu->edx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0x84u;
    cpu->ecx = cpu->esp + 0x110u;
    *(uint8_t*)(cpu->esp + 0x154u) = 6u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490E1Fu)); sfera_sub_0048FA20(cpu, LIFT_CODE_TOKEN_VA(0x490E1Fu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000910C5;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x40u);
    if (cpu->edi == 0xFFFFFFFFu) goto label_00090F21;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->edi);
    cpu->eax = cpu->esp + 0xF4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x114u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490E4Bu)); sfera_sub_00431640(cpu, LIFT_CODE_TOKEN_VA(0x490E4Bu));
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esp + 0x98u;
    *(uint8_t*)(cpu->esp + 0x14Cu) = 7u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490E61u)); sfera_sub_00490410(cpu, LIFT_CODE_TOKEN_VA(0x490E61u));
    cpu->esi = cpu->eax;
    cpu->ecx = cpu->esp + 0x60u;
    if (cpu->ecx == cpu->esi) goto label_00090EC7;
    if (*(uint32_t*)(cpu->esp + 0x74u) < 0x10u) goto label_00090E7F;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490E7Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x490E7Cu));
    cpu->esp += 4u;
    label_00090E7F:
    *(uint32_t*)(cpu->esp + 0x74u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x60u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esi + 0x14u) >= 0x10u) goto label_00090EAB;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->eax = cpu->esp + 0x64u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x490EA0u));
    cpu->esp += 0xCu;
    goto label_00090EB3;
    label_00090EAB:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->ecx;
    *(uint32_t*)(cpu->esi) = cpu->ebx;
    label_00090EB3:
    cpu->edx = *(uint32_t*)(cpu->esi + 0x10u);
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x14u);
    *(uint32_t*)(cpu->esp + 0x74u) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ebx;
    label_00090EC7:
    if (*(uint32_t*)(cpu->esp + 0xACu) < 0x10u) goto label_00090EE1;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x98u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490EDEu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x490EDEu));
    cpu->esp += 4u;
    label_00090EE1:
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0x100u) < 0x10u;
    *(uint32_t*)(cpu->esp + 0xACu) = 0xFu;
    *(uint32_t*)(cpu->esp + 0xA8u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x98u) = cpu->ebx & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x14Cu) = 6u;
    if (sub_pred[0]) goto label_00090F1C;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xECu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490F19u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x490F19u));
    cpu->esp += 4u;
    label_00090F1C:
    cpu->esi = 0xFu;
    label_00090F21:
    lift_push32(cpu, 1u); lift_push32(cpu, (uintptr_t)"l");
    cpu->ecx = cpu->esp + 0xA0u;
    *(uint32_t*)(cpu->esp + 0xB4u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xB0u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0xA0u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490F49u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x490F49u));
    cpu->edx = cpu->esp + 0x98u;
    cpu->ecx = cpu->esp + 0x7Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490F59u)); sfera_sub_0048DFB0(cpu, LIFT_CODE_TOKEN_VA(0x490F59u));
    sub_pred[1] = *(uint32_t*)(cpu->esp + 0xACu) < 0x10u;
    *(uint8_t*)(cpu->esp + 0x1Fu) = cpu->eax & 0xFFu;
    if (sub_pred[1]) goto label_00090F77;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x98u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490F74u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x490F74u));
    cpu->esp += 4u;
    label_00090F77:
    *(uint32_t*)(cpu->esp + 0xACu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xA8u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x98u) = cpu->ebx & 0xFFu;
    if (*(uint8_t*)(cpu->esp + 0x1Fu) == (cpu->ebx & 0xFFu)) goto label_00090FC3;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x130u;
    cpu->ecx = cpu->esp + 0x114u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490FACu)); sfera_sub_00490A70(cpu, LIFT_CODE_TOKEN_VA(0x490FACu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00090FC3;
    if (cpu->ebp == 3u) goto label_000910CD;
    cpu->ebp = 3u;
    goto label_000910CD;
    label_00090FC3:
    cpu->ecx = cpu->esp + 0x7Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490FCCu)); sfera_sub_0048FDC0(cpu, LIFT_CODE_TOKEN_VA(0x490FCCu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000910BB;
    if (cpu->ebp != 3u) goto label_000910B3;
    if (*(uint32_t*)(cpu->esp + 0xC4u) == cpu->ebx) goto label_000910B3;
    cpu->edx = cpu->esp + 0xB4u;
    cpu->ecx = cpu->esp + 0xECu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x490FFDu)); sfera_sub_00490730(cpu, LIFT_CODE_TOKEN_VA(0x490FFDu));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x48u;
    *(uint8_t*)(cpu->esp + 0x150u) = 9u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49100Fu)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x49100Fu));
    sub_pred[2] = *(uint32_t*)(cpu->esp + 0x100u) < 0x10u;
    *(uint8_t*)(cpu->esp + 0x14Cu) = 6u;
    if (sub_pred[2]) goto label_00091031;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xECu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49102Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49102Eu));
    cpu->esp += 4u;
    label_00091031:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x28u);
    if (cpu->esi == cpu->ebx) goto label_0009109F;
    cpu->edx = 0x1B6u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491048u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x491048u));
    lift_push32(cpu, 0x70u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49104Fu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x49104Fu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint8_t*)(cpu->esp + 0x14Cu) = 0xAu;
    if (cpu->eax == cpu->ebx) goto label_00091085;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x134u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x74u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x5Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491083u)); sfera_sub_00431730(cpu, LIFT_CODE_TOKEN_VA(0x491083u));
    goto label_00091087;
    label_00091085:
    cpu->eax = 0u;
    label_00091087:
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x150u) = 6u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9109Fu)); sfera_sub_0048E6A0(cpu, LIFT_CODE_TOKEN_RVA(0x9109Fu));
    label_0009109F:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0xDCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x910B3u)); sfera_sub_0048E270(cpu, LIFT_CODE_TOKEN_RVA(0x910B3u));
    label_000910B3:
    cpu->ebp = 0u;
    sub_pred[3] = *(uint32_t*)(cpu->esp + 0x30u) == cpu->ebx;
    goto label_000910C7;
    label_000910BB:
    if (cpu->ebp != cpu->ebx) goto label_000910CD;
    sub_pred[3] = *(uint32_t*)(cpu->esp + 0x30u) == cpu->ebx;
    goto label_000910C7;
    label_000910C5:
    sub_pred[3] = cpu->ebp == cpu->ebx;
    label_000910C7:
    if (!sub_pred[3]) goto label_000911E7;
    label_000910CD:
    if (*(uint32_t*)(cpu->esp + 0xC4u) == cpu->ebx) goto label_000911E7;
    cpu->edx = cpu->esp + 0xB4u;
    cpu->ecx = cpu->esp + 0xECu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4910EDu)); sfera_sub_00490730(cpu, LIFT_CODE_TOKEN_VA(0x4910EDu));
    cpu->esi = cpu->eax;
    cpu->edx = cpu->esp + 0x44u;
    cpu->edi = 0x10u;
    if (cpu->edx == cpu->esi) goto label_00091156;
    if (*(uint32_t*)(cpu->esp + 0x58u) < cpu->edi) goto label_0009110F;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49110Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49110Cu));
    cpu->esp += 4u;
    label_0009110F:
    *(uint32_t*)(cpu->esp + 0x58u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x44u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esi + 0x14u) >= cpu->edi) goto label_0009113A;
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    ++cpu->eax;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::memmove), LIFT_CODE_TOKEN_VA(0x49112Fu));
    cpu->esp += 0xCu;
    goto label_00091142;
    label_0009113A:
    cpu->edx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->edx;
    *(uint32_t*)(cpu->esi) = cpu->ebx;
    label_00091142:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->eax;
    cpu->ecx = *(uint32_t*)(cpu->esi + 0x14u);
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->ecx;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x14u) = cpu->ebx;
    label_00091156:
    *(uint8_t*)(cpu->esp + 0x14Cu) = 6u;
    if (*(uint32_t*)(cpu->esp + 0x100u) < cpu->edi) goto label_00091177;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xECu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491174u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x491174u));
    cpu->esp += 4u;
    label_00091177:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x28u);
    if (cpu->esi == cpu->ebx) goto label_000911D3;
    cpu->edx = 0x1C8u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49118Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x49118Eu));
    lift_push32(cpu, 0x34u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491195u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x491195u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint8_t*)(cpu->esp + 0x14Cu) = 0xCu;
    if (cpu->eax == cpu->ebx) goto label_000911B9;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4911B7u)); sfera_sub_004315D0(cpu, LIFT_CODE_TOKEN_VA(0x4911B7u));
    goto label_000911BB;
    label_000911B9:
    cpu->eax = 0u;
    label_000911BB:
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x150u) = 6u;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x911D3u)); sfera_sub_0048E6A0(cpu, LIFT_CODE_TOKEN_RVA(0x911D3u));
    label_000911D3:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0xDCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x911E7u)); sfera_sub_0048E270(cpu, LIFT_CODE_TOKEN_RVA(0x911E7u));
    label_000911E7:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x2Cu);
    if (cpu->esi == 0xFFFFFFFFu) goto label_0009127A;
    cpu->edi = 0x10u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebp;
    if (*(uint32_t*)(cpu->esp + 0x90u) < cpu->edi) goto label_00091217;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x7Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491214u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x491214u));
    cpu->esp += 4u;
    label_00091217:
    *(uint32_t*)(cpu->esp + 0x90u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x8Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x7Cu) = cpu->ebx & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x14Cu) = 4u;
    if (*(uint32_t*)(cpu->esp + 0xC8u) < cpu->edi) goto label_0009124E;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xB4u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49124Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49124Bu));
    cpu->esp += 4u;
    label_0009124E:
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->esp + 0x114u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491269u)); sfera_sub_0048EFE0(cpu, LIFT_CODE_TOKEN_VA(0x491269u));
    cpu->edi = cpu->esi;
    cpu->esi = 0xFu;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00090DB6;
    goto label_000912DA;
    label_0009127A:
    cpu->esi = 0x10u;
    *(uint8_t*)(cpu->esp + 0x17u) = 1u;
    if (*(uint32_t*)(cpu->esp + 0x90u) < cpu->esi) goto label_0009129A;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x7Cu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491297u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x491297u));
    cpu->esp += 4u;
    label_0009129A:
    *(uint32_t*)(cpu->esp + 0x90u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x8Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x7Cu) = cpu->ebx & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x14Cu) = 4u;
    if (*(uint32_t*)(cpu->esp + 0xC8u) < cpu->esi) goto label_000912D1;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xB4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4912CEu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4912CEu));
    cpu->esp += 4u;
    label_000912D1:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->esi = 0xFu;
    label_000912DA:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    if (cpu->edi >= *(uint32_t*)(cpu->ecx + 0x10u)) goto label_000913F7;
    if (cpu->ebp != cpu->ebx) goto label_000913F7;
    if (*(uint8_t*)(cpu->esp + 0x17u) != (cpu->ebx & 0xFFu)) goto label_000913F7;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->esp + 0xF4u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491309u)); sfera_sub_00431640(cpu, LIFT_CODE_TOKEN_VA(0x491309u));
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esp + 0xB4u;
    *(uint8_t*)(cpu->esp + 0x14Cu) = 0xDu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49131Fu)); sfera_sub_00490730(cpu, LIFT_CODE_TOKEN_VA(0x49131Fu));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x48u;
    *(uint8_t*)(cpu->esp + 0x150u) = 0xEu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491331u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x491331u));
    cpu->edi = 0x10u;
    if (*(uint32_t*)(cpu->esp + 0xC8u) < cpu->edi) goto label_0009134F;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xB4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49134Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49134Cu));
    cpu->esp += 4u;
    label_0009134F:
    *(uint32_t*)(cpu->esp + 0xC8u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xC4u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0xB4u) = cpu->ebx & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x14Cu) = 4u;
    if (*(uint32_t*)(cpu->esp + 0x100u) < cpu->edi) goto label_00091385;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xECu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491382u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x491382u));
    cpu->esp += 4u;
    label_00091385:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x28u);
    if (cpu->ebp == cpu->ebx) goto label_000913E1;
    cpu->edx = 0x1D7u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49139Cu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x49139Cu));
    lift_push32(cpu, 0x34u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4913A3u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4913A3u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    *(uint8_t*)(cpu->esp + 0x14Cu) = 0xFu;
    if (cpu->eax == cpu->ebx) goto label_000913C7;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4913C5u)); sfera_sub_004315D0(cpu, LIFT_CODE_TOKEN_VA(0x4913C5u));
    goto label_000913C9;
    label_000913C7:
    cpu->eax = 0u;
    label_000913C9:
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->esp + 0x150u) = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x913E1u)); sfera_sub_0048E6A0(cpu, LIFT_CODE_TOKEN_RVA(0x913E1u));
    label_000913E1:
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0xDCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4913F5u)); sfera_sub_0048E270(cpu, LIFT_CODE_TOKEN_VA(0x4913F5u));
    goto label_000913FC;
    label_000913F7:
    cpu->edi = 0x10u;
    label_000913FC:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x3Cu);
    if (cpu->ecx == cpu->ebx) goto label_00091414;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0xD8u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x91414u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0x91414u));
    label_00091414:
    if (*(uint32_t*)(cpu->esp + 0x58u) < cpu->edi) goto label_00091427;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491424u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x491424u));
    cpu->esp += 4u;
    label_00091427:
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x44u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0xE4u) < cpu->edi) goto label_0009144C;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xD0u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491449u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x491449u));
    cpu->esp += 4u;
    label_0009144C:
    *(uint32_t*)(cpu->esp + 0xE4u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xE0u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0xD0u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x74u) < cpu->edi) goto label_00091474;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491471u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x491471u));
    cpu->esp += 4u;
    label_00091474:
    *(uint32_t*)(cpu->esp + 0x74u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x60u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x138u) < cpu->edi) goto label_00091499;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x124u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491496u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x491496u));
    cpu->esp += 4u;
    label_00091499:
    *(uint32_t*)(cpu->esp + 0x138u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x134u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x124u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x11Cu) < cpu->edi) goto label_000914C7;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x108u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4914C4u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4914C4u));
    cpu->esp += 4u;
    label_000914C7:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x13Cu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00491500(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x224u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x248u);
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    cpu->ebx = 0u;
    cpu->esi = cpu->ecx;
    cpu->ebp = cpu->edx;
    cpu->eax = 0xFu;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0xA4u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0xA0u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x90u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x240u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x74u) = cpu->ebx & 0xFFu;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x244u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49159Bu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x49159Bu));
    cpu->edx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4915A7u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4915A7u));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->edi != *(uint32_t*)(cpu->eax + 8u));
    if ((cpu->eax & 0xFFu) == (cpu->ebx & 0xFFu)) goto label_00091BE8;
    goto label_000915C4;
    label_000915C0:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x1Cu);
    label_000915C4:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    if (cpu->ebp != cpu->ebx) goto label_000915D0;
    cpu->edx=0u;
    goto label_000915D3;
    label_000915D0:
    cpu->edx = *(uint32_t*)(cpu->ebp);
    label_000915D3:
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    cpu->esi = cpu->edi;
    cpu->esi >>= 2u;
    cpu->eax = cpu->esi;
    cpu->edi &= 3u;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->esi;
    if (cpu->ecx > cpu->eax) goto label_000915EA;
    cpu->eax -= cpu->ecx;
    label_000915EA:
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    if ((cpu->eax -= 3u) == 0u) goto label_00091AD4;
    if ((--cpu->eax) == 0u) goto label_000919EA;
    if ((--cpu->eax) != 0u) goto label_00091BC4;
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"/l");
    cpu->ecx = cpu->esp + 0x44u;
    *(uint32_t*)(cpu->esp + 0x58u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x44u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491630u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x491630u));
    *(uint8_t*)(cpu->esp + 0x240u) = 4u;
    if (cpu->ebp != cpu->ebx) goto label_00091640;
    cpu->ecx = 0u;
    goto label_00091643;
    label_00091640:
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    label_00091643:
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->eax = cpu->esi;
    if (cpu->edx > cpu->eax) goto label_0009164E;
    cpu->eax -= cpu->edx;
    label_0009164E:
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    cpu->ecx = cpu->esp + 0x100u;
    cpu->eax = cpu->edx + (cpu->edi * 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491666u)); sfera_sub_004313F0(cpu, LIFT_CODE_TOKEN_VA(0x491666u));
    cpu->ebp = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint8_t*)(cpu->esp + 0x240u) = 5u;
    if (cpu->eax != cpu->ebx) goto label_0009167C;
    cpu->ecx = 0u;
    goto label_0009167E;
    label_0009167C:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_0009167E:
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->eax = cpu->esi;
    if (cpu->edx > cpu->eax) goto label_00091689;
    cpu->eax -= cpu->edx;
    label_00091689:
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->eax * 4u));
    cpu->ecx = cpu->esp + 0xC8u;
    cpu->eax = cpu->eax + (cpu->edi * 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4916A1u)); sfera_sub_004315A0(cpu, LIFT_CODE_TOKEN_VA(0x4916A1u));
    cpu->esi = cpu->eax;
    lift_push32(cpu, 2u); lift_push32(cpu, (uintptr_t)"l ");
    cpu->ecx = cpu->esp + 0x60u;
    *(uint8_t*)(cpu->esp + 0x248u) = 6u;
    *(uint32_t*)(cpu->esp + 0x74u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x60u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4916CBu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x4916CBu));
    cpu->edx = cpu->esp + 0x58u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (0x3Cu & 0xFFu);
    cpu->ecx = cpu->esp + 0x1ACu;
    *(uint8_t*)(cpu->esp + 0x244u) = 7u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4916E6u)); sfera_sub_00490190(cpu, LIFT_CODE_TOKEN_VA(0x4916E6u));
    lift_push32(cpu, cpu->esi);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esp + 0x158u;
    *(uint8_t*)(cpu->esp + 0x244u) = 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4916FDu)); sfera_sub_004901D0(cpu, LIFT_CODE_TOKEN_VA(0x4916FDu));
    lift_push32(cpu, 0x3Eu);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esp + 0x1C8u;
    *(uint8_t*)(cpu->esp + 0x244u) = 9u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491715u)); sfera_sub_00490240(cpu, LIFT_CODE_TOKEN_VA(0x491715u));
    lift_push32(cpu, cpu->ebp);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esp + 0x120u;
    *(uint8_t*)(cpu->esp + 0x244u) = 0xAu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49172Cu)); sfera_sub_004901D0(cpu, LIFT_CODE_TOKEN_VA(0x49172Cu));
    lift_push32(cpu, 0x3Cu);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esp + 0x190u;
    *(uint8_t*)(cpu->esp + 0x244u) = 0xBu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491744u)); sfera_sub_00490240(cpu, LIFT_CODE_TOKEN_VA(0x491744u));
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esp + 0xB0u;
    *(uint8_t*)(cpu->esp + 0x244u) = 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49175Fu)); sfera_sub_004901D0(cpu, LIFT_CODE_TOKEN_VA(0x49175Fu));
    lift_push32(cpu, 0x3Eu);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esp + 0xE8u;
    *(uint8_t*)(cpu->esp + 0x244u) = 0xDu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491777u)); sfera_sub_00490240(cpu, LIFT_CODE_TOKEN_VA(0x491777u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x9Cu;
    *(uint8_t*)(cpu->esp + 0x24Cu) = 0xEu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49178Fu)); sfera_sub_0048E270(cpu, LIFT_CODE_TOKEN_VA(0x49178Fu));
    cpu->esi = 0x10u;
    if (*(uint32_t*)(cpu->esp + 0xF8u) < cpu->esi) goto label_000917AD;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xE4u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4917AAu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4917AAu));
    cpu->esp += 4u;
    label_000917AD:
    cpu->ebp = 0xFu;
    *(uint32_t*)(cpu->esp + 0xF8u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0xF4u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0xE4u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0xC0u) < cpu->esi) goto label_000917E0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xACu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4917DDu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4917DDu));
    cpu->esp += 4u;
    label_000917E0:
    *(uint32_t*)(cpu->esp + 0xC0u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0xBCu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0xACu) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x1A0u) < cpu->esi) goto label_0009180E;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49180Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49180Bu));
    cpu->esp += 4u;
    label_0009180E:
    *(uint32_t*)(cpu->esp + 0x1A0u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x19Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x18Cu) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x130u) < cpu->esi) goto label_0009183C;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x11Cu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491839u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x491839u));
    cpu->esp += 4u;
    label_0009183C:
    *(uint32_t*)(cpu->esp + 0x130u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x12Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x11Cu) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x1D8u) < cpu->esi) goto label_0009186A;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1C4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491867u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x491867u));
    cpu->esp += 4u;
    label_0009186A:
    *(uint32_t*)(cpu->esp + 0x1D8u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x1D4u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x1C4u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x168u) < cpu->esi) goto label_00091898;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x154u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491895u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x491895u));
    cpu->esp += 4u;
    label_00091898:
    *(uint32_t*)(cpu->esp + 0x168u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x164u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x154u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x1BCu) < cpu->esi) goto label_000918C6;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1A8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4918C3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4918C3u));
    cpu->esp += 4u;
    label_000918C6:
    *(uint32_t*)(cpu->esp + 0x1BCu) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x1B8u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x1A8u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x6Cu) < cpu->esi) goto label_000918EE;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x58u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4918EBu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4918EBu));
    cpu->esp += 4u;
    label_000918EE:
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x68u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x58u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0xDCu) < cpu->esi) goto label_00091913;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xC8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491910u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x491910u));
    cpu->esp += 4u;
    label_00091913:
    *(uint32_t*)(cpu->esp + 0xDCu) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0xD8u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0xC8u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x114u) < cpu->esi) goto label_00091941;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x100u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49193Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49193Eu));
    cpu->esp += 4u;
    label_00091941:
    *(uint32_t*)(cpu->esp + 0x114u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x110u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x100u) = cpu->ebx & 0xFFu;
    *(uint8_t*)(cpu->esp + 0x240u) = 1u;
    if (*(uint32_t*)(cpu->esp + 0x50u) < cpu->esi) goto label_00091971;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x3Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49196Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49196Eu));
    cpu->esp += 4u;
    label_00091971:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x4Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x3Cu) = cpu->ebx & 0xFFu;
    if (cpu->eax != cpu->ebx) goto label_00091989;
    cpu->ecx = 0u;
    goto label_0009198B;
    label_00091989:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_0009198B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    if (cpu->edx > cpu->eax) goto label_00091998;
    cpu->eax -= cpu->edx;
    label_00091998:
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    cpu->edi = cpu->edx + (cpu->edi * 4u);
    cpu->eax = cpu->esp + 0x1E0u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4919B1u)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x4919B1u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x80u;
    *(uint8_t*)(cpu->esp + 0x24Cu) = 0xFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4919C9u)); sfera_sub_0048E270(cpu, LIFT_CODE_TOKEN_VA(0x4919C9u));
    *(uint8_t*)(cpu->esp + 0x240u) = 1u;
    if (*(uint32_t*)(cpu->esp + 0x1F4u) < cpu->esi) goto label_00091BC4;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1E0u);
    goto label_00091BBB;
    label_000919EA:
    if (cpu->ebp != cpu->ebx) goto label_000919F2;
    cpu->ecx = 0u;
    goto label_000919F5;
    label_000919F2:
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    label_000919F5:
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->eax = cpu->esi;
    if (cpu->edx > cpu->eax) goto label_00091A00;
    cpu->eax -= cpu->edx;
    label_00091A00:
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->eax * 4u));
    cpu->ecx = cpu->esp + 0x138u;
    cpu->eax = cpu->eax + (cpu->edi * 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491A18u)); sfera_sub_004313F0(cpu, LIFT_CODE_TOKEN_VA(0x491A18u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x9Cu;
    *(uint8_t*)(cpu->esp + 0x24Cu) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491A30u)); sfera_sub_0048E270(cpu, LIFT_CODE_TOKEN_VA(0x491A30u));
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0x14Cu) < 0x10u;
    *(uint8_t*)(cpu->esp + 0x240u) = 1u;
    if (sub_pred[0]) goto label_00091A52;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x138u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491A4Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x491A4Fu));
    cpu->esp += 4u;
    label_00091A52:
    *(uint32_t*)(cpu->esp + 0x14Cu) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x148u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x138u) = cpu->ebx & 0xFFu;
    if (cpu->ebp != cpu->ebx) goto label_00091A73;
    cpu->ecx = 0u;
    goto label_00091A76;
    label_00091A73:
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    label_00091A76:
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->eax = cpu->esi;
    if (cpu->edx > cpu->eax) goto label_00091A81;
    cpu->eax -= cpu->edx;
    label_00091A81:
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    cpu->edi = cpu->edx + (cpu->edi * 4u);
    cpu->eax = cpu->esp + 0x1FCu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491A9Au)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x491A9Au));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x80u;
    *(uint8_t*)(cpu->esp + 0x24Cu) = 3u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491AB2u)); sfera_sub_0048E270(cpu, LIFT_CODE_TOKEN_VA(0x491AB2u));
    sub_pred[1] = *(uint32_t*)(cpu->esp + 0x210u) < 0x10u;
    *(uint8_t*)(cpu->esp + 0x240u) = 1u;
    if (sub_pred[1]) goto label_00091BC4;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1FCu);
    goto label_00091BBB;
    label_00091AD4:
    if (cpu->ebp != cpu->ebx) goto label_00091ADC;
    cpu->ecx = 0u;
    goto label_00091ADF;
    label_00091ADC:
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    label_00091ADF:
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->eax = cpu->esi;
    if (cpu->edx > cpu->eax) goto label_00091AEA;
    cpu->eax -= cpu->edx;
    label_00091AEA:
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->eax * 4u));
    cpu->ecx = cpu->esp + 0x170u;
    cpu->eax = cpu->eax + (cpu->edi * 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491B02u)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x491B02u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x9Cu;
    *(uint8_t*)(cpu->esp + 0x24Cu) = 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491B1Au)); sfera_sub_0048E270(cpu, LIFT_CODE_TOKEN_VA(0x491B1Au));
    cpu->ebp = 0x10u;
    *(uint8_t*)(cpu->esp + 0x240u) = 1u;
    if (*(uint32_t*)(cpu->esp + 0x184u) < cpu->ebp) goto label_00091B40;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x170u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491B3Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x491B3Du));
    cpu->esp += 4u;
    label_00091B40:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint32_t*)(cpu->esp + 0x184u) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x180u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x170u) = cpu->ebx & 0xFFu;
    if (cpu->eax != cpu->ebx) goto label_00091B65;
    cpu->ecx = 0u;
    goto label_00091B67;
    label_00091B65:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    label_00091B67:
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->eax = cpu->esi;
    if (cpu->edx > cpu->eax) goto label_00091B72;
    cpu->eax -= cpu->edx;
    label_00091B72:
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    cpu->edi = cpu->edx + (cpu->edi * 4u);
    cpu->eax = cpu->esp + 0x218u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491B8Bu)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x491B8Bu));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x80u;
    *(uint8_t*)(cpu->esp + 0x24Cu) = 0x11u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491BA3u)); sfera_sub_0048E270(cpu, LIFT_CODE_TOKEN_VA(0x491BA3u));
    *(uint8_t*)(cpu->esp + 0x240u) = 1u;
    if (*(uint32_t*)(cpu->esp + 0x22Cu) < cpu->ebp) goto label_00091BC4;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x218u);
    label_00091BBB:
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491BC1u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x491BC1u));
    cpu->esp += 4u;
    label_00091BC4:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    cpu->edx = cpu->esp + 0x30u;
    ++cpu->esi;
    lift_push32(cpu, cpu->edx);
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491BDBu)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x491BDBu));
    if (cpu->esi != *(uint32_t*)(cpu->eax + 8u)) goto label_000915C0;
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x20u);
    label_00091BE8:
    if (cpu->ebp == cpu->ebx) goto label_00091BFE;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->esp + 0x98u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x91BFEu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0x91BFEu));
    label_00091BFE:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    if (cpu->ecx == cpu->ebx) goto label_00091C13;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0x7Cu;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x91C13u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0x91C13u));
    label_00091C13:
    cpu->esi = 0x10u;
    if (*(uint32_t*)(cpu->esp + 0x88u) < cpu->esi) goto label_00091C2E;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x74u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491C2Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x491C2Bu));
    cpu->esp += 4u;
    label_00091C2E:
    if (*(uint32_t*)(cpu->esp + 0xA4u) < cpu->esi) goto label_00091C47;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x90u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491C44u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x491C44u));
    cpu->esp += 4u;
    label_00091C47:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x230u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00491C80(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 8u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x18u;
    cpu->edi = cpu->edx;
    cpu->esi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->esi;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->ebx;
    lift_push32(cpu, cpu->ebx);
    *(uint32_t*)(cpu->esi + 0x14u) = 0xFu;
    *(uint32_t*)(cpu->esi + 0x10u) = cpu->ebx;
    lift_push32(cpu, (uintptr_t)"");
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491CCFu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x491CCFu));
    lift_push32(cpu, cpu->esi);
    cpu->edx = 0u;
    cpu->ecx = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491CE5u)); sfera_sub_00490C50(cpu, LIFT_CODE_TOKEN_VA(0x491CE5u));
    cpu->eax = cpu->esi;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00491D00(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xA0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xB4u;
    cpu->esi = cpu->ecx;
    sub_pred[1] = *(uint32_t*)(cpu->esi + 0x10u) <= 1u;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x14u) = 0u;
    if (sub_pred[1]) goto label_00091FE4;
    lift_push32(cpu, 1u);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491D66u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x491D66u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491D6Du)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x491D6Du));
    cpu->edx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491D79u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x491D79u));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (cpu->edi != *(uint32_t*)(cpu->eax + 8u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00091FE4;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    label_00091D8F:
    if (cpu->ebx!=0u) goto label_00091D97;
    cpu->edx=0u;
    goto label_00091D99;
    label_00091D97:
    cpu->edx = *(uint32_t*)(cpu->ebx);
    label_00091D99:
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    cpu->ebp = cpu->edi;
    cpu->ebp = cpu->ebp >> 2u;
    cpu->eax = cpu->ebp;
    cpu->edi &= 3u;
    if (cpu->ecx > cpu->eax) goto label_00091DAC;
    cpu->eax -= cpu->ecx;
    label_00091DAC:
    cpu->ecx = *(uint32_t*)(cpu->edx + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    if (cpu->eax != 4u) goto label_00091E0D;
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) | (uint64_t)(1u);
    lift_push32(cpu, 1u);
    cpu->eax = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491DD5u)); sfera_sub_0048E0A0(cpu, LIFT_CODE_TOKEN_VA(0x491DD5u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx!=0u) goto label_00091DDF;
    cpu->esi=0u;
    goto label_00091DE1;
    label_00091DDF:
    cpu->esi = *(uint32_t*)(cpu->ecx);
    label_00091DE1:
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax = cpu->ecx;
    cpu->eax >>= 2u;
    cpu->ecx &= 3u;
    if (cpu->edx > cpu->eax) goto label_00091DF5;
    cpu->eax -= cpu->edx;
    label_00091DF5:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->eax * 4u));
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->ecx * 4u));
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    if (cpu->eax != 4u) goto label_00091E0D;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    goto label_00091E0F;
    label_00091E0D:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    label_00091E0F:
    if (((*(uint8_t*)(cpu->esp + 0x14u)) & (1u)) == 0u) goto label_00091E1B;
    *(uint32_t*)(cpu->esp + 0x14u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x14u)) & (uint64_t)(0xFFFFFFFEu);
    label_00091E1B:
    if ((cpu->eax & 0xFFu) == 0u) goto label_00091FC5;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491E33u)); sfera_sub_0048E0A0(cpu, LIFT_CODE_TOKEN_VA(0x491E33u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx!=0u) goto label_00091E3D;
    cpu->esi=0u;
    goto label_00091E3F;
    label_00091E3D:
    cpu->esi = *(uint32_t*)(cpu->ecx);
    label_00091E3F:
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax = cpu->ecx;
    cpu->eax >>= 2u;
    cpu->ecx &= 3u;
    if (cpu->edx > cpu->eax) goto label_00091E53;
    cpu->eax -= cpu->edx;
    label_00091E53:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->eax * 4u));
    cpu->esi = *(uint32_t*)(cpu->eax + (cpu->ecx * 4u));
    cpu->ecx = cpu->esp + 0x78u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491E68u)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x491E68u));
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0xBCu) = cpu->ecx;
    if (cpu->ebx == cpu->ecx) goto label_00091E77;
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    label_00091E77:
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->eax = cpu->ebp;
    if (cpu->edx > cpu->eax) goto label_00091E82;
    cpu->eax -= cpu->edx;
    label_00091E82:
    cpu->edx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->eax * 4u));
    cpu->ecx = cpu->esp + 0x5Cu;
    cpu->eax = cpu->eax + (cpu->edi * 4u);
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491E97u)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x491E97u));
    cpu->edx = cpu->esp + 0x5Cu;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x7Cu;
    cpu->ecx = cpu->esp + 0x98u;
    *(uint8_t*)(cpu->esp + 0xC0u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491EB4u)); sfera_sub_00490280(cpu, LIFT_CODE_TOKEN_VA(0x491EB4u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0xC0u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491EC4u)); sfera_sub_004317E0(cpu, LIFT_CODE_TOKEN_VA(0x491EC4u));
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0xA8u) < 0x10u;
    *(uint8_t*)(cpu->esp + 0xBCu) = 1u;
    if (sub_pred[0]) goto label_00091EE6;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x94u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491EE3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x491EE3u));
    cpu->esp += 4u;
    label_00091EE6:
    cpu->edx = 0x251u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491EF5u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x491EF5u));
    cpu->esi = 0u;
    if (cpu->ebx != cpu->esi) goto label_00091EFF;
    cpu->ecx = 0u;
    goto label_00091F01;
    label_00091EFF:
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    label_00091F01:
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->eax = cpu->ebp;
    if (cpu->edx > cpu->eax) goto label_00091F0C;
    cpu->eax -= cpu->edx;
    label_00091F0C:
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491F1Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x491F1Bu));
    cpu->esp -= 8u;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->esp;
    *(uint32_t*)(cpu->eax) = cpu->esi;
    *(uint32_t*)(cpu->eax + 4u) = cpu->esi;
    if (cpu->ebx == cpu->esi) goto label_00091F37;
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    if (cpu->ecx == cpu->esi) goto label_00091F37;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    label_00091F37:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x30u);
    *(uint32_t*)(cpu->eax + 8u) = cpu->edx;
    cpu->eax = cpu->esp + 0x5Cu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491F4Cu)); sfera_sub_0048F090(cpu, LIFT_CODE_TOKEN_VA(0x491F4Cu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ebx == cpu->ecx) goto label_00091F5E;
    cpu->ecx = *(uint32_t*)(cpu->ecx);
    if (cpu->ecx == cpu->esi) goto label_00091F5E;
    cpu->ebx = *(uint32_t*)(cpu->ecx);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    label_00091F5E:
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ebp = 0x10u;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    if (*(uint32_t*)(cpu->esp + 0x70u) < cpu->ebp) goto label_00091F7D;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x5Cu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491F7Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x491F7Au));
    cpu->esp += 4u;
    label_00091F7D:
    cpu->edi = 0xFu;
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x5Cu) = 0u;
    *(uint32_t*)(cpu->esp + 0xBCu) = 0xFFFFFFFFu;
    if (*(uint32_t*)(cpu->esp + 0x8Cu) < cpu->ebp) goto label_00091FB0;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x78u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491FADu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x491FADu));
    cpu->esp += 4u;
    label_00091FB0:
    *(uint32_t*)(cpu->esp + 0x8Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x78u) = 0u;
    goto label_00091FC9;
    label_00091FC5:
    ++*(uint32_t*)(cpu->esp + 0x20u);
    label_00091FC9:
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x491FD7u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x491FD7u));
    cpu->edi = *(uint32_t*)(cpu->esp + 0x20u);
    if (cpu->edi != *(uint32_t*)(cpu->eax + 8u)) goto label_00091D8F;
    label_00091FE4:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xACu;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00492010(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x68u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x7Cu;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x8Cu);
    cpu->edi = cpu->ecx;
    sub_pred[0] = *(uint32_t*)(cpu->edi + 0x10u) == 0u;
    cpu->esi = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->esi;
    if (!sub_pred[0]) goto label_0009205E;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    goto label_000923BE;
    label_0009205E:
    cpu->eax = *(uint32_t*)(cpu->esi + 0x10u);
    if (cpu->eax != 0u) goto label_000920C1;
    cpu->edx = 0x25Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492074u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x492074u));
    lift_push32(cpu, 0x34u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49207Bu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x49207Bu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x84u) = 0u;
    if (cpu->eax == 0u) goto label_000920AF;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49209Fu)); sfera_sub_004315D0(cpu, LIFT_CODE_TOKEN_VA(0x49209Fu));
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    goto label_000923AC;
    label_000920AF:
    cpu->eax = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    cpu->eax = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    goto label_000923AC;
    label_000920C1:
    if (cpu->ebx < cpu->eax) goto label_000920C8;
    cpu->ebx = cpu->eax + 0xFFFFFFFFu;
    label_000920C8:
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4920D0u)); sfera_sub_0048EAC0(cpu, LIFT_CODE_TOKEN_VA(0x4920D0u));
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->ecx = cpu->esi;
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    cpu->ebp = cpu->eax;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4920E3u)); sfera_sub_004312C0(cpu, LIFT_CODE_TOKEN_VA(0x4920E3u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00092361;
    lift_push32(cpu, 0u); lift_push32(cpu, (uintptr_t)"");
    cpu->ecx = cpu->esp + 0x48u;
    *(uint32_t*)(cpu->esp + 0x5Cu) = 0xFu;
    *(uint32_t*)(cpu->esp + 0x58u) = 0u;
    *(uint8_t*)(cpu->esp + 0x48u) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492110u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x492110u));
    *(uint32_t*)(cpu->esp + 0x84u) = 1u;
    if (cpu->ebp != 4u) goto label_00092192;
    cpu->ecx = cpu->esp + 0x5Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49212Cu)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x49212Cu));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x44u;
    *(uint8_t*)(cpu->esp + 0x88u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49213Eu)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x49213Eu));
    cpu->ecx = cpu->esp + 0x5Cu;
    *(uint8_t*)(cpu->esp + 0x84u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49214Fu)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x49214Fu));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x90u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->edi);
    if (cpu->eax >= *(uint32_t*)(cpu->esp + 0x5Cu)) goto label_0009217C;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49216Bu)); sfera_sub_0048EE60(cpu, LIFT_CODE_TOKEN_VA(0x49216Bu));
    cpu->edx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492177u)); sfera_sub_004317E0(cpu, LIFT_CODE_TOKEN_VA(0x492177u));
    goto label_0009234B;
    label_0009217C:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492181u)); sfera_sub_0048E270(cpu, LIFT_CODE_TOKEN_VA(0x492181u));
    cpu->edx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49218Du)); sfera_sub_004317E0(cpu, LIFT_CODE_TOKEN_VA(0x49218Du));
    goto label_0009234B;
    label_00092192:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x90u);
    if (cpu->ebp != 0u) goto label_00092227;
    cpu->edx = 0x277u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4921B0u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4921B0u));
    lift_push32(cpu, 0x34u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4921B7u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4921B7u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint8_t*)(cpu->esp + 0x84u) = 3u;
    if (cpu->eax == 0u) goto label_000921D7;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4921D5u)); sfera_sub_004315D0(cpu, LIFT_CODE_TOKEN_VA(0x4921D5u));
    goto label_000921D9;
    label_000921D7:
    cpu->eax = 0u;
    label_000921D9:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x18u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->eax = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x28u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0x94u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492200u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x492200u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492207u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x492207u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492216u)); sfera_sub_0048DD80(cpu, LIFT_CODE_TOKEN_VA(0x492216u));
    cpu->eax = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492222u)); sfera_sub_0048FEF0(cpu, LIFT_CODE_TOKEN_VA(0x492222u));
    goto label_0009234B;
    label_00092227:
    cpu->ecx = cpu->esp + 0x5Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492233u)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x492233u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x44u;
    *(uint8_t*)(cpu->esp + 0x88u) = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492245u)); sfera_sub_00409130(cpu, LIFT_CODE_TOKEN_VA(0x492245u));
    cpu->ecx = cpu->esp + 0x5Cu;
    *(uint8_t*)(cpu->esp + 0x84u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492256u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x492256u));
    if (cpu->ebp == 0u) goto label_000922F6;
    if (cpu->ebp >= *(uint32_t*)(cpu->esp + 0x50u)) goto label_000922F6;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esp + 0x50u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492277u)); sfera_sub_0048EE60(cpu, LIFT_CODE_TOKEN_VA(0x492277u));
    cpu->edx = 0x27Eu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492286u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x492286u));
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49228Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49228Cu));
    cpu->esp += 4u;
    cpu->edx = 0x27Fu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49229Eu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x49229Eu));
    lift_push32(cpu, 0x34u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4922A5u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4922A5u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint8_t*)(cpu->esp + 0x84u) = 5u;
    if (cpu->eax == 0u) goto label_000922CE;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4922CAu)); sfera_sub_004315D0(cpu, LIFT_CODE_TOKEN_VA(0x4922CAu));
    cpu->esi = cpu->eax;
    goto label_000922D0;
    label_000922CE:
    cpu->esi = 0u;
    label_000922D0:
    lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->esp + 0x2Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4922E4u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4922E4u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4922EBu)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4922EBu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4922F2u)); sfera_sub_0048DB70(cpu, LIFT_CODE_TOKEN_VA(0x4922F2u));
    *(uint32_t*)(cpu->eax) = cpu->esi;
    goto label_0009234B;
    label_000922F6:
    cpu->edx = 0x282u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492305u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x492305u));
    lift_push32(cpu, 0x34u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49230Cu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x49230Cu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint8_t*)(cpu->esp + 0x84u) = 6u;
    if (cpu->eax == 0u) goto label_0009232F;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49232Du)); sfera_sub_004315D0(cpu, LIFT_CODE_TOKEN_VA(0x49232Du));
    goto label_00092331;
    label_0009232F:
    cpu->eax = 0u;
    label_00092331:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->edx);
    *(uint8_t*)(cpu->esp + 0x88u) = 1u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9234Bu)); sfera_sub_0048E6A0(cpu, LIFT_CODE_TOKEN_RVA(0x9234Bu));
    label_0009234B:
    if (*(uint32_t*)(cpu->esp + 0x54u) < 0x10u) goto label_000923BC;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x40u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49235Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49235Cu));
    cpu->esp += 4u;
    goto label_000923BC;
    label_00092361:
    cpu->edx = 0x287u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492370u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x492370u));
    lift_push32(cpu, 0x34u);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492377u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x492377u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x84u) = 7u;
    if (cpu->eax == 0u) goto label_0009239D;
    lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, 0u); lift_push32(cpu, cpu->edi);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49239Bu)); sfera_sub_004315D0(cpu, LIFT_CODE_TOKEN_VA(0x49239Bu));
    goto label_0009239F;
    label_0009239D:
    cpu->eax = 0u;
    label_0009239F:
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    label_000923AC:
    *(uint32_t*)(cpu->esp + 0x88u) = 0xFFFFFFFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x923BCu)); sfera_sub_0048E6A0(cpu, LIFT_CODE_TOKEN_RVA(0x923BCu));
    label_000923BC:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    label_000923BE:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x74u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004923E0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x8Cu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xA0u;
    cpu->esi = cpu->edx;
    cpu->ebx = cpu->ecx;
    cpu->edi = 0u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->edi;
    lift_push32(cpu, 8u);
    *(uint32_t*)(cpu->esp + 0xACu) = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492437u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x492437u));
    cpu->esp += 4u;
    if (cpu->eax == cpu->edi) goto label_0009278D;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = 0u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->eax = cpu->esp + 0x1Cu;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0xA8u) = 1u;
    if (*(uint32_t*)(cpu->ebx + 0x10u) == cpu->edi) goto label_0009277A;
    cpu->edi = *(uint32_t*)(cpu->esp + 0xB0u);
    if (cpu->esi > cpu->edi) goto label_000926AD;
    cpu->edx = cpu->esp + 0x34u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49249Fu)); sfera_sub_0048E950(cpu, LIFT_CODE_TOKEN_VA(0x49249Fu));
    if ((cpu->eax & 0xFFu) == 0u) goto label_000926AD;
    cpu->ebp |= 0xFFFFFFFFu;
    if (*(uint32_t*)(cpu->esp + 0x34u) == cpu->ebp) goto label_000926AD;
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->ebx;
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4924C7u)); sfera_sub_0048E950(cpu, LIFT_CODE_TOKEN_VA(0x4924C7u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_000924D4;
    cpu->eax = *(uint32_t*)(cpu->ebx + 0x10u);
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    goto label_000924D8;
    label_000924D4:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x38u);
    label_000924D8:
    cpu->esi = 0u;
    if (*(uint32_t*)(cpu->ebx + 0x10u) <= cpu->esi) goto label_00092640;
    label_000924E3:
    cpu->edi = *(uint32_t*)(cpu->esp + 0x18u);
    if (cpu->esi < cpu->edi) goto label_00092614;
    if (cpu->esi > *(uint32_t*)(cpu->esp + 0x14u)) goto label_00092614;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492501u)); sfera_sub_0048EAC0(cpu, LIFT_CODE_TOKEN_VA(0x492501u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x20u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49250Bu)); sfera_sub_0048E6A0(cpu, LIFT_CODE_TOKEN_VA(0x49250Bu));
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492513u)); sfera_sub_0048EAC0(cpu, LIFT_CODE_TOKEN_VA(0x492513u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492522u)); sfera_sub_004312C0(cpu, LIFT_CODE_TOKEN_VA(0x492522u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00092636;
    if (cpu->esi != cpu->edi) goto label_0009259E;
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492537u)); sfera_sub_0048EB70(cpu, LIFT_CODE_TOKEN_VA(0x492537u));
    cpu->ecx = cpu->esp + 0x80u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492546u)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x492546u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x6Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    *(uint8_t*)(cpu->esp + 0xB4u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492561u)); sfera_sub_00431640(cpu, LIFT_CODE_TOKEN_VA(0x492561u));
    cpu->edi = cpu->eax;
    cpu->ecx = cpu->esp + 0x1Cu;
    *(uint8_t*)(cpu->esp + 0xA8u) = 3u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492574u)); sfera_sub_0048EB70(cpu, LIFT_CODE_TOKEN_VA(0x492574u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49257Cu)); sfera_sub_004317E0(cpu, LIFT_CODE_TOKEN_VA(0x49257Cu));
    cpu->ecx = cpu->esp + 0x64u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492585u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x492585u));
    cpu->ecx = cpu->esp + 0x80u;
    *(uint8_t*)(cpu->esp + 0xA8u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492599u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x492599u));
    goto label_00092636;
    label_0009259E:
    if (cpu->esi != *(uint32_t*)(cpu->esp + 0x14u)) goto label_00092636;
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4925B1u)); sfera_sub_0048EB70(cpu, LIFT_CODE_TOKEN_VA(0x4925B1u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->edx = cpu->esp + 0x64u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4925BDu)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x4925BDu));
    cpu->ecx = cpu->ebp + 1u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x88u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->eax;
    *(uint8_t*)(cpu->esp + 0xB4u) = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4925DAu)); sfera_sub_00431640(cpu, LIFT_CODE_TOKEN_VA(0x4925DAu));
    cpu->edi = cpu->eax;
    cpu->ecx = cpu->esp + 0x1Cu;
    *(uint8_t*)(cpu->esp + 0xA8u) = 5u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4925EDu)); sfera_sub_0048EB70(cpu, LIFT_CODE_TOKEN_VA(0x4925EDu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4925F5u)); sfera_sub_004317E0(cpu, LIFT_CODE_TOKEN_VA(0x4925F5u));
    cpu->ecx = cpu->esp + 0x80u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492601u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x492601u));
    cpu->ecx = cpu->esp + 0x64u;
    *(uint8_t*)(cpu->esp + 0xA8u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492612u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x492612u));
    goto label_00092636;
    label_00092614:
    cpu->edx = 0x2D6u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492623u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x492623u));
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49262Bu)); sfera_sub_0048EAC0(cpu, LIFT_CODE_TOKEN_VA(0x49262Bu));
    cpu->eax = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492633u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x492633u));
    cpu->esp += 4u;
    label_00092636:
    ++cpu->esi;
    if (cpu->esi < *(uint32_t*)(cpu->ebx + 0x10u)) goto label_000924E3;
    label_00092640:
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x2Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492653u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x492653u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x38u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492666u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x492666u));
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49266Du)); sfera_sub_00490350(cpu, LIFT_CODE_TOKEN_VA(0x49266Du));
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492676u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x492676u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->edx);
    label_0009267B:
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492680u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x492680u));
    cpu->esp += 4u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x98u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000926AD:
    cpu->eax = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4926B9u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4926B9u));
    cpu->ecx = cpu->esp + 0x58u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4926C5u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4926C5u));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x48u);
    if (cpu->ebp == *(uint32_t*)(cpu->eax + 8u)) goto label_00092773;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x40u);
    label_000926D6:
    if (cpu->ebx!=0u) goto label_000926DE;
    cpu->edx=0u;
    goto label_000926E0;
    label_000926DE:
    cpu->edx = *(uint32_t*)(cpu->ebx);
    label_000926E0:
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    cpu->esi = cpu->ebp;
    cpu->esi >>= 2u;
    cpu->edi = cpu->ebp;
    cpu->eax = cpu->esi;
    cpu->edi &= 3u;
    if (cpu->ecx > cpu->eax) goto label_000926F5;
    cpu->eax -= cpu->ecx;
    label_000926F5:
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->eax * 4u));
    if (*(uint32_t*)(cpu->eax + (cpu->edi * 4u)) == 0u) goto label_00092757;
    cpu->edx = 0x2E0u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492710u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x492710u));
    if (cpu->ebx != 0u) goto label_00092718;
    cpu->ecx = 0u;
    goto label_0009271A;
    label_00092718:
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    label_0009271A:
    cpu->edx = *(uint32_t*)(cpu->ecx + 8u);
    cpu->eax = cpu->esi;
    if (cpu->edx > cpu->eax) goto label_00092725;
    cpu->eax -= cpu->edx;
    label_00092725:
    cpu->ecx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->edi * 4u));
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492734u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x492734u));
    cpu->esp += 4u;
    if (cpu->ebx != 0u) goto label_0009273F;
    cpu->eax = 0u;
    goto label_00092741;
    label_0009273F:
    cpu->eax = *(uint32_t*)(cpu->ebx);
    label_00092741:
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    if (cpu->ecx > cpu->esi) goto label_0009274A;
    cpu->esi -= cpu->ecx;
    label_0009274A:
    cpu->ecx = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + (cpu->esi * 4u));
    *(uint32_t*)(cpu->edx + (cpu->edi * 4u)) = 0u;
    label_00092757:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = cpu->esp + 0x58u;
    lift_push32(cpu, cpu->eax);
    ++cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492766u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x492766u));
    if (cpu->ebp != *(uint32_t*)(cpu->eax + 8u)) goto label_000926D6;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x14u);
    label_00092773:
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9277Au)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_RVA(0x9277Au));
    label_0009277A:
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492783u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x492783u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->ecx);
    goto label_0009267B;
    label_0009278D:
    cpu->edx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x50u;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->edi;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4927B7u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x4927B7u));
    lift_trap(cpu, 0x4927B7u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_004927C0(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x58u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x6Cu;
    cpu->esi = cpu->edx;
    cpu->ebx = 0u;
    cpu->edi = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    lift_push32(cpu, 8u);
    *(uint32_t*)(cpu->esp + 0x78u) = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492807u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x492807u));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_00092B0A;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->eax;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = 0u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    cpu->eax = cpu->esp + 0x24u;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x30u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x74u) = 1u;
    if (*(uint32_t*)(cpu->edi + 0x10u) == cpu->ebx) goto label_00092AD3;
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x7Cu);
    if (cpu->esi > cpu->ebx) goto label_00092AD3;
    cpu->edx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x24u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492869u)); sfera_sub_0048E950(cpu, LIFT_CODE_TOKEN_VA(0x492869u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00092AD3;
    cpu->ebp |= 0xFFFFFFFFu;
    if (*(uint32_t*)(cpu->esp + 0x18u) == cpu->ebp) goto label_00092AD3;
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->esp + 0x20u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->edi;
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492891u)); sfera_sub_0048E950(cpu, LIFT_CODE_TOKEN_VA(0x492891u));
    if ((cpu->eax & 0xFFu) != 0u) goto label_000928A2;
    cpu->eax = *(uint32_t*)(cpu->edi + 0x10u);
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebp;
    goto label_000928A6;
    label_000928A2:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    label_000928A6:
    cpu->esi = 0u;
    if (*(uint32_t*)(cpu->edi + 0x10u) <= cpu->esi) goto label_00092AA6;
    label_000928B1:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x20u);
    if (cpu->esi < cpu->eax) goto label_00092A8A;
    if (cpu->esi > *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_00092A8A;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->ebx & 0xFFu)) ^ (uint64_t)((cpu->ebx & 0xFFu)))) & 0xFFu);
    if (cpu->esi != cpu->eax) goto label_000929D5;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4928D9u)); sfera_sub_0048EAC0(cpu, LIFT_CODE_TOKEN_VA(0x4928D9u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->esi != *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_00092967;
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4928F2u)); sfera_sub_004312C0(cpu, LIFT_CODE_TOKEN_VA(0x4928F2u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00092A66;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492902u)); sfera_sub_0048EAC0(cpu, LIFT_CODE_TOKEN_VA(0x492902u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49290Cu)); sfera_sub_0048E6A0(cpu, LIFT_CODE_TOKEN_VA(0x49290Cu));
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492915u)); sfera_sub_0048EB70(cpu, LIFT_CODE_TOKEN_VA(0x492915u));
    cpu->ecx = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492921u)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x492921u));
    cpu->ebx = cpu->eax;
    cpu->ecx = cpu->esp + 0x24u;
    *(uint8_t*)(cpu->esp + 0x74u) = 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492931u)); sfera_sub_0048EB70(cpu, LIFT_CODE_TOKEN_VA(0x492931u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ebp = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->edx -= cpu->eax;
    ++cpu->edx;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492947u)); sfera_sub_00402810(cpu, LIFT_CODE_TOKEN_VA(0x492947u));
    cpu->ecx = *(uint32_t*)(cpu->ebp);
    label_0009294A:
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492950u)); sfera_sub_004317E0(cpu, LIFT_CODE_TOKEN_VA(0x492950u));
    cpu->ecx = cpu->esp + 0x4Cu;
    *(uint8_t*)(cpu->esp + 0x74u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49295Eu)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x49295Eu));
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x14u);
    goto label_00092A9C;
    label_00092967:
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492974u)); sfera_sub_004312C0(cpu, LIFT_CODE_TOKEN_VA(0x492974u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00092A66;
    if (*(uint32_t*)(cpu->esp + 0x18u) <= 0u) goto label_00092A66;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49298Fu)); sfera_sub_0048EAC0(cpu, LIFT_CODE_TOKEN_VA(0x49298Fu));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492999u)); sfera_sub_0048E6A0(cpu, LIFT_CODE_TOKEN_VA(0x492999u));
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4929A2u)); sfera_sub_0048EB70(cpu, LIFT_CODE_TOKEN_VA(0x4929A2u));
    cpu->ecx = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4929AEu)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x4929AEu));
    cpu->ebp = cpu->eax;
    cpu->ecx = cpu->esp + 0x24u;
    *(uint8_t*)(cpu->esp + 0x74u) = 3u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4929BEu)); sfera_sub_0048EB70(cpu, LIFT_CODE_TOKEN_VA(0x4929BEu));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->ebp;
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4929CEu)); sfera_sub_00402810(cpu, LIFT_CODE_TOKEN_VA(0x4929CEu));
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    goto label_0009294A;
    label_000929D5:
    if (cpu->esi != *(uint32_t*)(cpu->esp + 0x1Cu)) goto label_00092A66;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4929E7u)); sfera_sub_0048EAC0(cpu, LIFT_CODE_TOKEN_VA(0x4929E7u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4929F6u)); sfera_sub_004312C0(cpu, LIFT_CODE_TOKEN_VA(0x4929F6u));
    if ((cpu->eax & 0xFFu) == 0u) goto label_00092A66;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492A02u)); sfera_sub_0048EAC0(cpu, LIFT_CODE_TOKEN_VA(0x492A02u));
    cpu->ecx = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492A0Eu)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x492A0Eu));
    *(uint8_t*)(cpu->esp + 0x74u) = 4u;
    if (cpu->ebp >= *(uint32_t*)(cpu->esp + 0x5Cu)) goto label_00092A54;
    if (cpu->ebp == 0xFFFFFFFFu) goto label_00092A54;
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492A26u)); sfera_sub_0048EAC0(cpu, LIFT_CODE_TOKEN_VA(0x492A26u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492A30u)); sfera_sub_0048E6A0(cpu, LIFT_CODE_TOKEN_VA(0x492A30u));
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492A39u)); sfera_sub_0048EB70(cpu, LIFT_CODE_TOKEN_VA(0x492A39u));
    cpu->edx = cpu->ebp + 1u;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x54u;
    cpu->ebx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492A4Au)); sfera_sub_00402810(cpu, LIFT_CODE_TOKEN_VA(0x492A4Au));
    cpu->ecx = *(uint32_t*)(cpu->ebx);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492A52u)); sfera_sub_004317E0(cpu, LIFT_CODE_TOKEN_VA(0x492A52u));
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (1u & 0xFFu);
    label_00092A54:
    cpu->ecx = cpu->esp + 0x4Cu;
    *(uint8_t*)(cpu->esp + 0x74u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492A62u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x492A62u));
    if ((cpu->ebx & 0xFFu) != 0u) goto label_00092A9C;
    label_00092A66:
    cpu->edx = 0x324u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492A75u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x492A75u));
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492A7Du)); sfera_sub_0048EAC0(cpu, LIFT_CODE_TOKEN_VA(0x492A7Du));
    cpu->eax = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492A85u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x492A85u));
    cpu->esp += 4u;
    goto label_00092A9C;
    label_00092A8A:
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492A92u)); sfera_sub_0048EAC0(cpu, LIFT_CODE_TOKEN_VA(0x492A92u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x92A9Cu)); sfera_sub_0048E6A0(cpu, LIFT_CODE_TOKEN_RVA(0x92A9Cu));
    label_00092A9C:
    ++cpu->esi;
    if (cpu->esi < *(uint32_t*)(cpu->edi + 0x10u)) goto label_000928B1;
    label_00092AA6:
    cpu->esp -= 0xCu;
    cpu->eax = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492AB9u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x492AB9u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->esp;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x40u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492ACCu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x492ACCu));
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x92AD3u)); sfera_sub_00490350(cpu, LIFT_CODE_TOKEN_RVA(0x92AD3u));
    label_00092AD3:
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492ADCu)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x492ADCu));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x24u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492AE6u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x492AE6u));
    cpu->esp += 4u;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x64u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00092B0A:
    cpu->eax = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x44u;
    *(uint32_t*)(cpu->esp + 0x40u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492B34u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x492B34u));
    lift_trap(cpu, 0x492B34u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00492B40(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x1ACu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x1C0u;
    cpu->ebx = 0u;
    cpu->ebp = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    lift_push32(cpu, 2u);
    cpu->esi = 0xFu;
    lift_push32(cpu, (uintptr_t)"/l");
    cpu->ecx = cpu->esp + 0x90u;
    *(uint32_t*)(cpu->esp + 0x1D0u) = 2u;
    *(uint32_t*)(cpu->esp + 0xA4u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xA0u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x90u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492BBBu)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x492BBBu));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->esp + 0x210u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x5Cu;
    *(uint8_t*)(cpu->esp + 0x1D4u) = 3u;
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x6Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x5Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492BE3u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x492BE3u));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esp + 0x1F4u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x40u;
    *(uint8_t*)(cpu->esp + 0x1D4u) = 4u;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x50u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x40u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492C0Bu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x492C0Bu));
    cpu->edx = cpu->esp + 0x34u;
    cpu->ecx = cpu->esp + 0x1A0u;
    *(uint8_t*)(cpu->esp + 0x1C8u) = 5u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492C23u)); sfera_sub_004905D0(cpu, LIFT_CODE_TOKEN_VA(0x492C23u));
    cpu->edi = cpu->eax;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0x1D8u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x24u;
    *(uint8_t*)(cpu->esp + 0x1D4u) = 6u;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x24u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492C4Du)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x492C4Du));
    lift_push32(cpu, 3u); lift_push32(cpu, (uintptr_t)"l=\"");
    cpu->ecx = cpu->esp + 0x74u;
    *(uint8_t*)(cpu->esp + 0x1D0u) = 7u;
    *(uint32_t*)(cpu->esp + 0x88u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x84u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x74u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492C77u)); sfera_sub_00406820(cpu, LIFT_CODE_TOKEN_VA(0x492C77u));
    cpu->eax = cpu->esp + 0x6Cu;
    lift_push32(cpu, cpu->eax);
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (0x3Cu & 0xFFu);
    cpu->ecx = cpu->esp + 0x16Cu;
    *(uint8_t*)(cpu->esp + 0x1CCu) = 8u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492C92u)); sfera_sub_00490190(cpu, LIFT_CODE_TOKEN_VA(0x492C92u));
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esp + 0x134u;
    *(uint8_t*)(cpu->esp + 0x1CCu) = 9u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492CADu)); sfera_sub_004901D0(cpu, LIFT_CODE_TOKEN_VA(0x492CADu));
    *(uint8_t*)(cpu->esp + 0x1C8u) = 0xAu;
    lift_push32(cpu, (uintptr_t)"://");
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esp + 0xFCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492CC8u)); sfera_sub_004903C0(cpu, LIFT_CODE_TOKEN_VA(0x492CC8u));
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esp + 0xC4u;
    *(uint8_t*)(cpu->esp + 0x1CCu) = 0xBu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492CDFu)); sfera_sub_004901D0(cpu, LIFT_CODE_TOKEN_VA(0x492CDFu));
    lift_push32(cpu, 0x22u);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esp + 0x188u;
    *(uint8_t*)(cpu->esp + 0x1CCu) = 0xCu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492CF7u)); sfera_sub_00490240(cpu, LIFT_CODE_TOKEN_VA(0x492CF7u));
    lift_push32(cpu, 0x3Eu);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esp + 0x118u;
    *(uint8_t*)(cpu->esp + 0x1CCu) = 0xDu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492D0Fu)); sfera_sub_00490240(cpu, LIFT_CODE_TOKEN_VA(0x492D0Fu));
    cpu->edx = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esp + 0x150u;
    *(uint8_t*)(cpu->esp + 0x1CCu) = 0xEu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492D2Au)); sfera_sub_004901D0(cpu, LIFT_CODE_TOKEN_VA(0x492D2Au));
    lift_push32(cpu, 0x3Cu);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esp + 0xA8u;
    *(uint8_t*)(cpu->esp + 0x1CCu) = 0xFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492D42u)); sfera_sub_00490240(cpu, LIFT_CODE_TOKEN_VA(0x492D42u));
    cpu->ecx = cpu->esp + 0x88u;
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esp + 0xE0u;
    *(uint8_t*)(cpu->esp + 0x1CCu) = 0x10u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492D60u)); sfera_sub_004901D0(cpu, LIFT_CODE_TOKEN_VA(0x492D60u));
    lift_push32(cpu, 0x3Eu);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->ebp;
    *(uint8_t*)(cpu->esp + 0x1CCu) = 0x11u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492D73u)); sfera_sub_00490240(cpu, LIFT_CODE_TOKEN_VA(0x492D73u));
    cpu->edi = 0x10u;
    if (*(uint32_t*)(cpu->esp + 0xF0u) < cpu->edi) goto label_00092D91;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xDCu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492D8Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x492D8Eu));
    cpu->esp += 4u;
    label_00092D91:
    *(uint32_t*)(cpu->esp + 0xF0u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xECu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0xDCu) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0xB8u) < cpu->edi) goto label_00092DBF;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xA4u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492DBCu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x492DBCu));
    cpu->esp += 4u;
    label_00092DBF:
    *(uint32_t*)(cpu->esp + 0xB8u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xB4u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0xA4u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x160u) < cpu->edi) goto label_00092DED;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492DEAu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x492DEAu));
    cpu->esp += 4u;
    label_00092DED:
    *(uint32_t*)(cpu->esp + 0x160u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x15Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x14Cu) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x128u) < cpu->edi) goto label_00092E1B;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x114u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492E18u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x492E18u));
    cpu->esp += 4u;
    label_00092E1B:
    *(uint32_t*)(cpu->esp + 0x128u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x124u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x114u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x198u) < cpu->edi) goto label_00092E49;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x184u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492E46u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x492E46u));
    cpu->esp += 4u;
    label_00092E49:
    *(uint32_t*)(cpu->esp + 0x198u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x194u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x184u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0xD4u) < cpu->edi) goto label_00092E77;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xC0u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492E74u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x492E74u));
    cpu->esp += 4u;
    label_00092E77:
    *(uint32_t*)(cpu->esp + 0xD4u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0xD0u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0xC0u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x10Cu) < cpu->edi) goto label_00092EA5;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xF8u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492EA2u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x492EA2u));
    cpu->esp += 4u;
    label_00092EA5:
    *(uint32_t*)(cpu->esp + 0x10Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x108u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0xF8u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x144u) < cpu->edi) goto label_00092ED3;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x130u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492ED0u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x492ED0u));
    cpu->esp += 4u;
    label_00092ED3:
    *(uint32_t*)(cpu->esp + 0x144u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x140u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x130u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x17Cu) < cpu->edi) goto label_00092F01;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x168u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492EFEu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x492EFEu));
    cpu->esp += 4u;
    label_00092F01:
    *(uint32_t*)(cpu->esp + 0x17Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x178u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x168u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x80u) < cpu->edi) goto label_00092F2C;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x6Cu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492F29u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x492F29u));
    cpu->esp += 4u;
    label_00092F2C:
    *(uint32_t*)(cpu->esp + 0x80u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x7Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x6Cu) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x2Cu) < cpu->edi) goto label_00092F4E;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492F4Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x492F4Bu));
    cpu->esp += 4u;
    label_00092F4E:
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x18u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x1B4u) < cpu->edi) goto label_00092F73;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x1A0u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492F70u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x492F70u));
    cpu->esp += 4u;
    label_00092F73:
    *(uint32_t*)(cpu->esp + 0x1B4u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1B0u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x1A0u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x48u) < cpu->edi) goto label_00092F9B;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492F98u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x492F98u));
    cpu->esp += 4u;
    label_00092F9B:
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x44u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x34u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x64u) < cpu->edi) goto label_00092FBA;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x50u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492FB7u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x492FB7u));
    cpu->esp += 4u;
    label_00092FBA:
    *(uint32_t*)(cpu->esp + 0x64u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x60u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x50u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x9Cu) < cpu->edi) goto label_00092FDF;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x88u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x492FDCu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x492FDCu));
    cpu->esp += 4u;
    label_00092FDF:
    *(uint32_t*)(cpu->esp + 0x9Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x98u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x88u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x1E4u) < cpu->edi) goto label_0009300D;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x1D0u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49300Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49300Au));
    cpu->esp += 4u;
    label_0009300D:
    *(uint32_t*)(cpu->esp + 0x1E4u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1E0u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x1D0u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x200u) < cpu->edi) goto label_0009303B;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1ECu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493038u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x493038u));
    cpu->esp += 4u;
    label_0009303B:
    *(uint32_t*)(cpu->esp + 0x200u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x1FCu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x1ECu) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x21Cu) < cpu->edi) goto label_00093069;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x208u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493066u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x493066u));
    cpu->esp += 4u;
    label_00093069:
    cpu->eax = cpu->ebp;
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x1B8u;
    cpu->esp += 0x58u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004930A0(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xACu;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xC0u;
    cpu->ebp = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->edx;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0xC8u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    lift_push32(cpu, 8u);
    *(uint8_t*)(cpu->esp + 0xCCu) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4930FDu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4930FDu));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_000933F7;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = 0u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = cpu->esp + 0x18u;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    cpu->edi = 0xFu;
    *(uint32_t*)(cpu->esp + 0x7Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x78u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x68u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x98u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x94u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x84u) = cpu->ebx & 0xFFu;
    cpu->edx = cpu->esp + 0x68u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->esp + 0xD4u;
    *(uint8_t*)(cpu->esp + 0xCCu) = 4u;
    *(uint8_t*)(cpu->esp + 0x1Au) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493174u)); sfera_sub_00490C50(cpu, LIFT_CODE_TOKEN_VA(0x493174u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    if (cpu->eax == cpu->ebx) goto label_00093344;
    if (cpu->eax <= 1u) goto label_0009333B;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49319Du)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x49319Du));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4931A4u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4931A4u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != cpu->ebx) goto label_000931AE;
    cpu->esi=0u;
    goto label_000931B0;
    label_000931AE:
    cpu->esi = *(uint32_t*)(cpu->ecx);
    label_000931B0:
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->edx = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax = cpu->ecx;
    cpu->eax >>= 2u;
    cpu->ecx &= 3u;
    if (cpu->edx > cpu->eax) goto label_000931C4;
    cpu->eax -= cpu->edx;
    label_000931C4:
    cpu->edx = *(uint32_t*)(cpu->esi + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->eax * 4u));
    cpu->eax = cpu->eax + (cpu->ecx * 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    if (cpu->eax != 5u) goto label_0009333B;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4931E9u)); sfera_sub_0048EB20(cpu, LIFT_CODE_TOKEN_VA(0x4931E9u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    if (cpu->eax != 4u) goto label_0009333B;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493204u)); sfera_sub_0048EB20(cpu, LIFT_CODE_TOKEN_VA(0x493204u));
    cpu->esi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493211u)); sfera_sub_0048EB20(cpu, LIFT_CODE_TOKEN_VA(0x493211u));
    cpu->edi = *(uint32_t*)(cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49321Au)); sfera_sub_00431210(cpu, LIFT_CODE_TOKEN_VA(0x49321Au));
    if (cpu->eax != 2u) goto label_00093336;
    cpu->ecx = cpu->esp + 0xA0u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493232u)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x493232u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)": ");
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49323Fu)); sfera_sub_00431390(cpu, LIFT_CODE_TOKEN_VA(0x49323Fu));
    lift_test[0]=cpu->eax==0u;
    cpu->ecx = cpu->esp + 0xA0u;
    *(uint8_t*)(cpu->esp + 0x17u) = (lift_test[0]) ? 1u : 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493252u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x493252u));
    if (*(uint8_t*)(cpu->esp + 0x17u) == (cpu->ebx & 0xFFu)) goto label_00093336;
    cpu->esi = 1u;
    if (*(uint32_t*)(cpu->esp + 0x28u) <= cpu->esi) goto label_0009329B;
    label_00093270:
    cpu->edx = 0x377u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49327Fu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x49327Fu));
    lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493289u)); sfera_sub_0048EB20(cpu, LIFT_CODE_TOKEN_VA(0x493289u));
    cpu->eax = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493291u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x493291u));
    ++cpu->esi;
    cpu->esp += 4u;
    if (cpu->esi < *(uint32_t*)(cpu->esp + 0x28u)) goto label_00093270;
    label_0009329B:
    cpu->edx = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4932A9u)); sfera_sub_0049F5D0(cpu, LIFT_CODE_TOKEN_VA(0x4932A9u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4932B8u)); sfera_sub_0048DD80(cpu, LIFT_CODE_TOKEN_VA(0x4932B8u));
    lift_push32(cpu, 1u);
    cpu->eax = cpu->esp + 0x48u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x70u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4932CDu)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x4932CDu));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4932D4u)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x4932D4u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x48u) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4932E3u)); sfera_sub_0048DD80(cpu, LIFT_CODE_TOKEN_VA(0x4932E3u));
    cpu->edx = cpu->esp + 0x68u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x34u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4932F1u)); sfera_sub_0048EBC0(cpu, LIFT_CODE_TOKEN_VA(0x4932F1u));
    cpu->eax = cpu->esp + 0x68u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x88u;
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493306u)); sfera_sub_00491500(cpu, LIFT_CODE_TOKEN_VA(0x493306u));
    if (cpu->ebp == cpu->ebx) goto label_0009331C;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esp + 0x8Cu;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x9331Cu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0x9331Cu));
    label_0009331C:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    if (cpu->ecx == cpu->ebx) goto label_00093331;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0x70u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x93331u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0x93331u));
    label_00093331:
    *(uint8_t*)(cpu->esp + 0x16u) = 1u;
    label_00093336:
    cpu->edi = 0xFu;
    label_0009333B:
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x93344u)); sfera_sub_0048F5E0(cpu, LIFT_CODE_TOKEN_RVA(0x93344u));
    label_00093344:
    cpu->esi = 0x10u;
    if (*(uint32_t*)(cpu->esp + 0x98u) < cpu->esi) goto label_00093362;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x84u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49335Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49335Fu));
    cpu->esp += 4u;
    label_00093362:
    *(uint32_t*)(cpu->esp + 0x98u) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x94u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x84u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x7Cu) < cpu->esi) goto label_0009338A;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x68u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493387u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x493387u));
    cpu->esp += 4u;
    label_0009338A:
    cpu->ecx = cpu->esp + 0x18u;
    *(uint32_t*)(cpu->esp + 0x7Cu) = cpu->edi;
    *(uint32_t*)(cpu->esp + 0x78u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x68u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49339Fu)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x49339Fu));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4933A9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4933A9u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    if (*(uint32_t*)(cpu->esp + 0xE4u) < cpu->esi) goto label_000933C9;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xD0u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4933C6u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4933C6u));
    cpu->esp += 4u;
    label_000933C9:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esp + 0x16u));
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xB8u;
    cpu->esp += 0x20u; cpu->eip = stop_address; return;
    label_000933F7:
    cpu->ecx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x3Cu;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->edx = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493421u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x493421u));
    lift_trap(cpu, 0x493421u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00493430(LiftCpu* cpu, uint32_t stop_address) { bool lift_test[1];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0xC0u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0xD4u;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x38u) = cpu->edx;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0xDCu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    lift_push32(cpu, 8u);
    *(uint8_t*)(cpu->esp + 0xE0u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49348Fu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x49348Fu));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_000938ED;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = 0u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = cpu->esp + 0x18u;
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x28u) = cpu->ebx;
    cpu->ebp = 0xFu;
    *(uint32_t*)(cpu->esp + 0x90u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x8Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x7Cu) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x74u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x60u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0xECu;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0xA4u;
    *(uint8_t*)(cpu->esp + 0xE8u) = 4u;
    *(uint32_t*)(cpu->esp + 0xB8u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0xB4u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0xA4u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493518u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x493518u));
    cpu->eax = cpu->esp + 0x60u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x1Cu;
    cpu->ecx = cpu->esp + 0x9Cu;
    *(uint8_t*)(cpu->esp + 0xE0u) = 5u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493535u)); sfera_sub_00490C50(cpu, LIFT_CODE_TOKEN_VA(0x493535u));
    cpu->edi = 0x10u;
    *(uint8_t*)(cpu->esp + 0xDCu) = 4u;
    if (*(uint32_t*)(cpu->esp + 0xACu) < cpu->edi) goto label_0009355B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x98u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493558u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x493558u));
    cpu->esp += 4u;
    label_0009355B:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    if (cpu->eax == cpu->ebx) goto label_0009386C;
    if (cpu->eax <= 1u) goto label_0009377B;
    lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->edx);
    cpu->eax = cpu->esp + 0x50u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493584u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x493584u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49358Bu)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x49358Bu));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    if (cpu->ecx != cpu->ebx) goto label_00093595;
    cpu->edx=0u;
    goto label_00093597;
    label_00093595:
    cpu->edx = *(uint32_t*)(cpu->ecx);
    label_00093597:
    cpu->ecx = *(uint32_t*)(cpu->eax + 8u);
    cpu->esi = *(uint32_t*)(cpu->edx + 8u);
    cpu->eax = cpu->ecx;
    cpu->eax >>= 2u;
    cpu->ecx &= 3u;
    if (cpu->esi > cpu->eax) goto label_000935AB;
    cpu->eax -= cpu->esi;
    label_000935AB:
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    cpu->eax = *(uint32_t*)(cpu->edx + (cpu->eax * 4u));
    cpu->eax = cpu->eax + (cpu->ecx * 4u);
    cpu->ecx = *(uint32_t*)(cpu->eax);
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    if (cpu->eax != 5u) goto label_0009377B;
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4935D0u)); sfera_sub_0048EB20(cpu, LIFT_CODE_TOKEN_VA(0x4935D0u));
    cpu->ecx = *(uint32_t*)(cpu->eax);
    reinterpret_cast<HyperTextElement*>(cpu->ecx)->elementType(cpu);
    if (cpu->eax != 4u) goto label_0009377B;
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4935EBu)); sfera_sub_0048EB20(cpu, LIFT_CODE_TOKEN_VA(0x4935EBu));
    cpu->edi = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4935F8u)); sfera_sub_0048EB20(cpu, LIFT_CODE_TOKEN_VA(0x4935F8u));
    cpu->esi = *(uint32_t*)(cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493601u)); sfera_sub_00431210(cpu, LIFT_CODE_TOKEN_VA(0x493601u));
    if (cpu->eax != 2u) goto label_00093776;
    cpu->ecx = cpu->esp + 0x98u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493619u)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x493619u));
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, (uintptr_t)": ");
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493626u)); sfera_sub_00431390(cpu, LIFT_CODE_TOKEN_VA(0x493626u));
    lift_test[0]=cpu->eax==0u;
    cpu->ecx = cpu->esp + 0x98u;
    *(uint8_t*)(cpu->esp + 0x17u) = (lift_test[0]) ? 1u : 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493639u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x493639u));
    if (*(uint8_t*)(cpu->esp + 0x17u) == (cpu->ebx & 0xFFu)) goto label_00093776;
    cpu->edx = cpu->esp + 0x98u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493652u)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x493652u));
    cpu->ecx = cpu->esp + 0x98u;
    *(uint8_t*)(cpu->esp + 0x17u) = *(uint32_t*)(cpu->eax + 0x10u) > 2u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493667u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x493667u));
    if (*(uint8_t*)(cpu->esp + 0x17u) == (cpu->ebx & 0xFFu)) goto label_000936C9;
    cpu->eax = cpu->esp + 0xB4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49367Cu)); sfera_sub_004314D0(cpu, LIFT_CODE_TOKEN_VA(0x49367Cu));
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 2u);
    cpu->ecx = cpu->esp + 0xA0u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->eax;
    *(uint8_t*)(cpu->esp + 0xE8u) = 6u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493697u)); sfera_sub_00431640(cpu, LIFT_CODE_TOKEN_VA(0x493697u));
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->esp + 0xE0u) = 7u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4936A7u)); sfera_sub_004317E0(cpu, LIFT_CODE_TOKEN_VA(0x4936A7u));
    cpu->ecx = cpu->esp + 0x98u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4936B3u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4936B3u));
    cpu->ecx = cpu->esp + 0xB4u;
    *(uint8_t*)(cpu->esp + 0xDCu) = 4u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4936C7u)); sfera_sub_004061B0(cpu, LIFT_CODE_TOKEN_VA(0x4936C7u));
    goto label_00093727;
    label_000936C9:
    cpu->edx = 0x39Fu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4936D8u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4936D8u));
    lift_push32(cpu, 1u);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4936E3u)); sfera_sub_0048EB20(cpu, LIFT_CODE_TOKEN_VA(0x4936E3u));
    cpu->edx = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4936EBu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4936EBu));
    cpu->esp += 4u;
    lift_push32(cpu, 1u);
    cpu->eax = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x44u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x24u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493703u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x493703u));
    cpu->ecx = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49370Au)); sfera_sub_004A8C50(cpu, LIFT_CODE_TOKEN_VA(0x49370Au));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493719u)); sfera_sub_0048DD80(cpu, LIFT_CODE_TOKEN_VA(0x493719u));
    cpu->edx = cpu->esp + 0x60u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x93727u)); sfera_sub_0048F090(cpu, LIFT_CODE_TOKEN_RVA(0x93727u));
    label_00093727:
    cpu->edx = 0x3A2u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\simpleHTMLParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493736u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x493736u));
    lift_push32(cpu, cpu->ebx);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493740u)); sfera_sub_0048EB20(cpu, LIFT_CODE_TOKEN_VA(0x493740u));
    cpu->eax = *(uint32_t*)(cpu->eax);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493748u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x493748u));
    cpu->esp += 4u;
    cpu->ecx = cpu->esp + 0x54u;
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493759u)); sfera_sub_004A8E20(cpu, LIFT_CODE_TOKEN_VA(0x493759u));
    cpu->esp -= 0xCu;
    cpu->ecx = cpu->esp;
    *(uint32_t*)(cpu->esp + 0x3Cu) = cpu->esp;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493768u)); sfera_sub_0048DD80(cpu, LIFT_CODE_TOKEN_VA(0x493768u));
    cpu->edx = cpu->esp + 0x54u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x28u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x93776u)); sfera_sub_0048F090(cpu, LIFT_CODE_TOKEN_RVA(0x93776u));
    label_00093776:
    cpu->edi = 0x10u;
    label_0009377B:
    cpu->eax = cpu->esp + 0x60u;
    lift_push32(cpu, cpu->eax);
    cpu->edx = cpu->esp + 0x80u;
    cpu->ecx = cpu->esp + 0x1Cu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493790u)); sfera_sub_00491500(cpu, LIFT_CODE_TOKEN_VA(0x493790u));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x38u);
    if (cpu->ecx == cpu->ebx) goto label_000937A5;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0x68u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x937A5u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0x937A5u));
    label_000937A5:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x34u);
    if (cpu->ecx == cpu->ebx) goto label_000937BD;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->esp + 0x84u;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x937BDu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0x937BDu));
    label_000937BD:
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4937C6u)); sfera_sub_0048F5E0(cpu, LIFT_CODE_TOKEN_VA(0x4937C6u));
    if (*(uint32_t*)(cpu->esp + 0x74u) < cpu->edi) goto label_000937D9;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4937D6u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4937D6u));
    cpu->esp += 4u;
    label_000937D9:
    *(uint32_t*)(cpu->esp + 0x74u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x60u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x90u) < cpu->edi) goto label_000937FB;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x7Cu);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4937F8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4937F8u));
    cpu->esp += 4u;
    label_000937FB:
    cpu->ecx = cpu->esp + 0x18u;
    *(uint32_t*)(cpu->esp + 0x90u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x8Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x7Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493816u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x493816u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493820u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x493820u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    if (*(uint32_t*)(cpu->esp + 0xF8u) < cpu->edi) goto label_00093840;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xE4u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49383Du)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49383Du));
    cpu->esp += 4u;
    label_00093840:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    label_00093842:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0xCCu;
    cpu->esp += 0x20u; cpu->eip = stop_address; return;
    label_0009386C:
    if (*(uint32_t*)(cpu->esp + 0x74u) < cpu->edi) goto label_0009387F;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49387Cu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49387Cu));
    cpu->esp += 4u;
    label_0009387F:
    *(uint32_t*)(cpu->esp + 0x74u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x60u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x90u) < cpu->edi) goto label_000938A1;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x7Cu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49389Eu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49389Eu));
    cpu->esp += 4u;
    label_000938A1:
    cpu->ecx = cpu->esp + 0x18u;
    *(uint32_t*)(cpu->esp + 0x90u) = cpu->ebp;
    *(uint32_t*)(cpu->esp + 0x8Cu) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x7Cu) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4938BCu)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x4938BCu));
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x18u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4938C6u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4938C6u));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    if (*(uint32_t*)(cpu->esp + 0xF8u) < cpu->edi) goto label_000938E6;
    cpu->edx = *(uint32_t*)(cpu->esp + 0xE4u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4938E3u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x4938E3u));
    cpu->esp += 4u;
    label_000938E6:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    goto label_00093842;
    label_000938ED:
    cpu->eax = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x40u;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->ecx = cpu->esp + 0x40u;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493917u)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x493917u));
    lift_trap(cpu, 0x493917u, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00493920(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[3];
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, 0u);
    cpu->eax = 0u;
    lift_push32(cpu, cpu->eax);
    cpu->esp -= 0x88u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esp -= 4u;
    cpu->eax = cpu->esp + 0x9Cu;
    cpu->ebp = cpu->edx;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ecx;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xCCu);
    cpu->edi = *(uint32_t*)(cpu->esp + 0xC8u);
    *(uint32_t*)(cpu->esp + 0x2Cu) = cpu->eax;
    cpu->ebx = 0u;
    *(uint32_t*)(cpu->esp + 0xA4u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    lift_push32(cpu, 8u);
    *(uint8_t*)(cpu->esp + 0xA8u) = 1u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49398Fu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x49398Fu));
    cpu->esp += 4u;
    if (cpu->eax == cpu->ebx) goto label_00093BC2;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->eax;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    cpu->edx = 0u;
    *(uint32_t*)(cpu->eax + 4u) = cpu->edx;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->ecx = cpu->esp + 0x14u;
    *(uint32_t*)(cpu->edx) = cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ebx;
    *(uint32_t*)(cpu->esp + 0x24u) = cpu->ebx;
    cpu->esi = 0xFu;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x44u) = cpu->ebx & 0xFFu;
    *(uint32_t*)(cpu->esp + 0x74u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x60u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->esp + 0xB4u;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->esp + 0x88u;
    *(uint8_t*)(cpu->esp + 0xB0u) = 4u;
    *(uint32_t*)(cpu->esp + 0x9Cu) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x98u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x88u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493A12u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_VA(0x493A12u));
    lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0x18u;
    cpu->ecx = cpu->esp + 0x80u;
    *(uint8_t*)(cpu->esp + 0xA8u) = 5u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493A2Bu)); sfera_sub_00490C50(cpu, LIFT_CODE_TOKEN_VA(0x493A2Bu));
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0x90u) < 0x10u;
    *(uint8_t*)(cpu->esp + 0xA4u) = 4u;
    if (sub_pred[0]) goto label_00093A4A;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x7Cu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493A47u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x493A47u));
    cpu->esp += 4u;
    label_00093A4A:
    if (*(uint32_t*)(cpu->esp + 0x24u) == cpu->ebx) goto label_00093B47;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x34u);
    lift_push32(cpu, cpu->ebp);
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493A62u)); sfera_sub_004927C0(cpu, LIFT_CODE_TOKEN_VA(0x493A62u));
    cpu->edx = cpu->esp + 0x60u;
    lift_push32(cpu, cpu->edx);
    cpu->edx = cpu->esp + 0x48u;
    cpu->ecx = cpu->esp + 0x18u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493A74u)); sfera_sub_00491500(cpu, LIFT_CODE_TOKEN_VA(0x493A74u));
    if (cpu->edi == cpu->ebx) goto label_00093A87;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->esp + 0x4Cu;
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x93A87u)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0x93A87u));
    label_00093A87:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x2Cu);
    if (cpu->ecx == cpu->ebx) goto label_00093A9C;
    lift_push32(cpu, 0xFFFFFFFFu); lift_push32(cpu, cpu->ebx);
    cpu->edx = cpu->esp + 0x68u;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x93A9Cu)); sfera_sub_00405210(cpu, LIFT_CODE_TOKEN_RVA(0x93A9Cu));
    label_00093A9C:
    cpu->ecx = cpu->esp + 0x14u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493AA5u)); sfera_sub_0048F5E0(cpu, LIFT_CODE_TOKEN_VA(0x493AA5u));
    cpu->edi = 0x10u;
    if (*(uint32_t*)(cpu->esp + 0x74u) < cpu->edi) goto label_00093ABD;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493ABAu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x493ABAu));
    cpu->esp += 4u;
    label_00093ABD:
    *(uint32_t*)(cpu->esp + 0x74u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x60u) = cpu->ebx & 0xFFu;
    if (*(uint32_t*)(cpu->esp + 0x58u) < cpu->edi) goto label_00093ADC;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493AD9u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x493AD9u));
    cpu->esp += 4u;
    label_00093ADC:
    cpu->ecx = cpu->esp + 0x14u;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x44u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493AF1u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x493AF1u));
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493AFBu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x493AFBu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if (*(uint32_t*)(cpu->esp + 0xC0u) < cpu->edi) goto label_00093B1B;
    cpu->eax = *(uint32_t*)(cpu->esp + 0xACu);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493B18u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x493B18u));
    cpu->esp += 4u;
    label_00093B1B:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (1u & 0xFFu);
    label_00093B1D:
    cpu->ecx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x94u;
    cpu->esp += 0x28u; cpu->eip = stop_address; return;
    label_00093B47:
    if (*(uint32_t*)(cpu->esp + 0x74u) < 0x10u) goto label_00093B5B;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x60u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493B58u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x493B58u));
    cpu->esp += 4u;
    label_00093B5B:
    sub_pred[1] = *(uint32_t*)(cpu->esp + 0x58u) < 0x10u;
    *(uint32_t*)(cpu->esp + 0x74u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x70u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x60u) = cpu->ebx & 0xFFu;
    if (sub_pred[1]) goto label_00093B7B;
    cpu->edx = *(uint32_t*)(cpu->esp + 0x44u);
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493B78u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x493B78u));
    cpu->esp += 4u;
    label_00093B7B:
    cpu->ecx = cpu->esp + 0x14u;
    *(uint32_t*)(cpu->esp + 0x58u) = cpu->esi;
    *(uint32_t*)(cpu->esp + 0x54u) = cpu->ebx;
    *(uint8_t*)(cpu->esp + 0x44u) = cpu->ebx & 0xFFu;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493B90u)); sfera_sub_0049FA40(cpu, LIFT_CODE_TOKEN_VA(0x493B90u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493B9Au)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x493B9Au));
    cpu->esp += 4u;
    sub_pred[2] = *(uint32_t*)(cpu->esp + 0xC0u) < 0x10u;
    *(uint32_t*)(cpu->esp + 0x14u) = cpu->ebx;
    if (sub_pred[2]) goto label_00093BBB;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0xACu);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493BB8u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x493BB8u));
    cpu->esp += 4u;
    label_00093BBB:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | ((uint32_t)(((uint64_t)((cpu->eax & 0xFFu)) ^ (uint64_t)((cpu->eax & 0xFFu)))) & 0xFFu);
    goto label_00093B1D;
    label_00093BC2:
    cpu->edx = cpu->esp + 0x30u;
    lift_push32(cpu, cpu->edx);
    cpu->ecx = cpu->esp + 0x3Cu;
    *(uint32_t*)(cpu->esp + 0x34u) = cpu->ebx;
    cpu->esp += 4u;
    lift_push32(cpu, 0u);
    cpu->eax = cpu->esp + 0x3Cu;
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493BECu)); sfera_sub_004EE92A(cpu, LIFT_CODE_TOKEN_VA(0x493BECu));
    lift_trap(cpu, 0x493BECu, "INT3"); return;
}
__declspec(noinline) void sfera_sub_00493BF0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx;
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 8u) = cpu->ecx;
    *(uint32_t*)(cpu->eax + 0xCu) = cpu->ecx;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00493C00(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->esi = cpu->ecx;
    cpu->edi = 0u;
    if (*(uint32_t*)(cpu->esi) == cpu->edi) goto label_00093C22;
    cpu->edx = cpu->edi + 0x4Cu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SimpleParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493C17u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x493C17u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493C1Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x493C1Fu));
    cpu->esp += 4u;
    label_00093C22:
    *(uint32_t*)(cpu->esi) = cpu->edi;
    *(uint32_t*)(cpu->esi + 4u) = cpu->edi;
    if (*(uint32_t*)(cpu->esi + 8u) == cpu->edi) goto label_00093C47;
    cpu->edx = 0x51u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SimpleParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493C3Bu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x493C3Bu));
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493C44u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x493C44u));
    cpu->esp += 4u;
    label_00093C47:
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->edi;
    *(uint32_t*)(cpu->esi + 8u) = cpu->edi;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00493C50(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    cpu->ebx = 0u;
    if (*(uint32_t*)(cpu->esi) == cpu->ebx) goto label_00093D1B;
    if (*(uint32_t*)(cpu->esi + 8u) == cpu->ebx) goto label_00093C7E;
    cpu->edx = 0x88u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SimpleParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493C72u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x493C72u));
    cpu->eax = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493C7Bu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x493C7Bu));
    cpu->esp += 4u;
    label_00093C7E:
    cpu->eax = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->esi + 8u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    if (cpu->eax >= *(uint32_t*)(cpu->esi + 4u)) goto label_00093C9E;
    label_00093C90:
    if (*(uint8_t*)(cpu->eax) != 0xDu) goto label_00093C98;
    ++*(uint32_t*)(cpu->esi + 0xCu);
    label_00093C98:
    ++cpu->eax;
    if (cpu->eax < *(uint32_t*)(cpu->esi + 4u)) goto label_00093C90;
    label_00093C9E:
    ++*(uint32_t*)(cpu->esi + 0xCu);
    cpu->edx = 0x93u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SimpleParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493CB0u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x493CB0u));
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    ++cpu->eax;
    cpu->edx = 4u;
    cpu->ecx = (uint64_t)cpu->eax * cpu->edx > 0xFFFFFFFFu ? 0xFFFFFFFFu : cpu->eax * cpu->edx;
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493CCAu)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x493CCAu));
    cpu->esp += 4u;
    *(uint32_t*)(cpu->esi + 8u) = cpu->eax;
    if (cpu->eax != cpu->ebx) goto label_00093CDA;
    *(uint32_t*)(cpu->esi + 0xCu) = cpu->ebx;
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00093CDA:
    cpu->ecx = *(uint32_t*)(cpu->esi);
    *(uint32_t*)(cpu->eax) = cpu->ecx;
    if (cpu->ecx >= *(uint32_t*)(cpu->esi + 4u)) goto label_00093D00;
    cpu->eax = 0u;
    lift_push32(cpu, cpu->ebp);
    label_00093CE6:
    if (*(uint8_t*)(cpu->ecx) != 0xDu) goto label_00093CF9;
    cpu->ebp = *(uint32_t*)(cpu->esi + 8u);
    cpu->eax += 4u;
    cpu->edx = cpu->ecx + 2u;
    *(uint32_t*)(cpu->eax + cpu->ebp) = cpu->edx;
    *(uint8_t*)(cpu->ecx) = cpu->ebx & 0xFFu;
    label_00093CF9:
    ++cpu->ecx;
    if (cpu->ecx < *(uint32_t*)(cpu->esi + 4u)) goto label_00093CE6;
    cpu->ebp = lift_pop32(cpu);
    label_00093D00:
    cpu->eax = *(uint32_t*)(cpu->esi + 0xCu);
    *(uint32_t*)(cpu->esi + 0x418u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x41Cu) = cpu->eax;
    *(uint32_t*)(cpu->esi + 0x410u) = cpu->ebx;
    *(uint32_t*)(cpu->esi + 0x414u) = cpu->eax;
    label_00093D1B:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00493D20(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if (cpu->eax == 0u) goto label_00093D66;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx + 1u;
    label_00093D30:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    ++cpu->ecx;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00093D30;
    cpu->ecx -= cpu->esi;
    cpu->ecx += cpu->eax;
    cpu->esi = lift_pop32(cpu);
    if (cpu->eax == cpu->ecx) goto label_00093D66;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    if ((cpu->edx & 0xFFu) != 0x2Fu) goto label_00093D4C;
    if (*(uint8_t*)(cpu->eax + 1u) == (cpu->edx & 0xFFu)) goto label_00093D66;
    label_00093D4C:
    if ((int8_t)(cpu->edx & 0xFFu) > (int8_t)0x20u) goto label_00093D5B;
    label_00093D51:
    ++cpu->eax;
    if (cpu->eax >= cpu->ecx) goto label_00093D66;
    if ((int8_t)*(uint8_t*)(cpu->eax) <= (int8_t)0x20u) goto label_00093D51;
    label_00093D5B:
    if (*(uint8_t*)(cpu->eax) != 0x2Fu) goto label_00093D68;
    if (*(uint8_t*)(cpu->eax + 1u) != 0x2Fu) goto label_00093D68;
    label_00093D66:
    cpu->eax = 0u;
    label_00093D68:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00493D70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx);
    cpu->edx = cpu->ecx;
    cpu->ecx = *(uint32_t*)(cpu->edx + 8u);
    *(uint32_t*)(cpu->esp) = cpu->edx;
    if (cpu->ecx != 0u) goto label_00093D84;
    label_00093D7D:
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00093D84:
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->esp + 0xCu)) goto label_00093D7D;
    if ((int32_t)cpu->eax >= (int32_t)*(uint32_t*)(cpu->edx + 0xCu)) goto label_00093D7D;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = 1u;
    cpu->ebx = cpu->eax;
    cpu->ebp = cpu->ecx + (cpu->eax * 4u);
    goto label_00093DA7;
    label_00093DA3:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x10u);
    label_00093DA7:
    cpu->eax = *(uint32_t*)(cpu->ebp);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edx;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493DB2u)); sfera_sub_00493D20(cpu, LIFT_CODE_TOKEN_VA(0x493DB2u));
    cpu->esi = cpu->eax;
    if (cpu->esi == 0u) goto label_00093DF0;
    cpu->ecx = cpu->esi;
    cpu->edx = cpu->ecx + 1u;
    label_00093DC0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    ++cpu->ecx;
    if ((cpu->eax & 0xFFu) != 0u) goto label_00093DC0;
    cpu->ecx -= cpu->edx;
    cpu->edx = 0u;
    if ((int32_t)cpu->ecx <= 0) goto label_00093DF0;
    (void)cpu;
    label_00093DD0:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx + cpu->esi));
    if ((cpu->eax & 0xFFu) != 0x2Fu) goto label_00093DDD;
    if (*(uint8_t*)(cpu->edx + cpu->esi + 1u) == (cpu->eax & 0xFFu)) goto label_00093DF0;
    label_00093DDD:
    if ((cpu->eax & 0xFFu) != 0x7Bu) goto label_00093DE2;
    ++cpu->edi;
    label_00093DE2:
    if ((cpu->eax & 0xFFu) != 0x7Du) goto label_00093DE7;
    --cpu->edi;
    label_00093DE7:
    if (cpu->edi == 0u) goto label_00093E05;
    ++cpu->edx;
    if ((int32_t)cpu->edx < (int32_t)cpu->ecx) goto label_00093DD0;
    label_00093DF0:
    ++cpu->ebx;
    cpu->ebp += 4u;
    if ((int32_t)cpu->ebx < (int32_t)*(uint32_t*)(cpu->esp + 0x1Cu)) goto label_00093DA3;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00093E05:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu);
    cpu->eax = cpu->ebx;
    cpu->ebx = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00493E10(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebp = cpu->ecx;
    *(uint32_t*)(cpu->esp + 8u) = cpu->ebp;
    if (cpu->edi != 0u) goto label_00093E2A;
    label_00093E21:
    cpu->edi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_00093E2A:
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    if ((int32_t)*(uint32_t*)(cpu->esp + 0x18u) <= (int32_t)cpu->eax) goto label_00093E37;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    label_00093E37:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    if ((int32_t)cpu->ecx >= (int32_t)*(uint32_t*)(cpu->esp + 0x18u)) goto label_00093E21;
    lift_push32(cpu, cpu->esi);
    cpu->eax = cpu->edi;
    cpu->edx = cpu->edi;
    cpu->esi = cpu->eax + 1u;
    lift_push32(cpu, cpu->ebx);
    label_00093E50:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ebx & 0xFFu) != 0u) goto label_00093E50;
    cpu->eax -= cpu->esi;
    cpu->esi = cpu->eax + cpu->edi;
    if (cpu->edi == cpu->esi) goto label_00093F2D;
    cpu->eax = cpu->ebp + 0x10u;
    cpu->ebp += 0x410u;
    if (cpu->edi >= cpu->esi) goto label_00093E88;
    label_00093E71:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    if ((int8_t)(cpu->ebx & 0xFFu) <= (int8_t)0x20u) goto label_00093E88;
    if (cpu->eax >= cpu->ebp) goto label_00093F2D;
    *(uint8_t*)(cpu->eax) = cpu->ebx & 0xFFu;
    ++cpu->edx;
    ++cpu->eax;
    if (cpu->edx < cpu->esi) goto label_00093E71;
    label_00093E88:
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->eax = cpu->edx;
    cpu->edi = cpu->ecx;
    cpu->esi = cpu->eax + 1u;
    label_00093E92:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->ebx & 0xFFu) != 0u) goto label_00093E92;
    cpu->eax -= cpu->esi;
    if ((int32_t)cpu->eax <= 0) goto label_00093EB4;
    cpu->esi = 0u;
    if ((int32_t)cpu->eax <= 0) goto label_00093EB4;
    label_00093EA5:
    if (*(uint8_t*)(cpu->esi + cpu->edx) == 0x7Bu) goto label_00093F38;
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)cpu->eax) goto label_00093EA5;
    label_00093EB4:
    cpu->edi = cpu->ecx + 1u;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    if ((int32_t)cpu->edi >= (int32_t)cpu->ecx) goto label_00093F2D;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edx = *(uint32_t*)(cpu->eax + 8u);
    cpu->ebp = cpu->edx + (cpu->edi * 4u);
    label_00093ED0:
    cpu->eax = *(uint32_t*)(cpu->ebp);
    if (cpu->eax == 0u) goto label_00093F15;
    cpu->edx = cpu->eax;
    cpu->esi = cpu->edx + 1u;
    label_00093EE0:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->edx));
    ++cpu->edx;
    if ((cpu->ebx & 0xFFu) != 0u) goto label_00093EE0;
    cpu->edx -= cpu->esi;
    cpu->edx += cpu->eax;
    if (cpu->eax == cpu->edx) goto label_00093F15;
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    if ((cpu->ebx & 0xFFu) != 0x2Fu) goto label_00093EFB;
    if (*(uint8_t*)(cpu->eax + 1u) == (cpu->ebx & 0xFFu)) goto label_00093F15;
    label_00093EFB:
    if ((int8_t)(cpu->ebx & 0xFFu) > (int8_t)0x20u) goto label_00093F0A;
    label_00093F00:
    ++cpu->eax;
    if (cpu->eax >= cpu->edx) goto label_00093F15;
    if ((int8_t)*(uint8_t*)(cpu->eax) <= (int8_t)0x20u) goto label_00093F00;
    label_00093F0A:
    if (*(uint8_t*)(cpu->eax) != 0x2Fu) goto label_00093F28;
    if (*(uint8_t*)(cpu->eax + 1u) != 0x2Fu) goto label_00093F28;
    label_00093F15:
    ++cpu->edi;
    cpu->ebp += 4u;
    if ((int32_t)cpu->edi < (int32_t)cpu->ecx) goto label_00093ED0;
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_00093F28:
    if (*(uint8_t*)(cpu->eax) == 0x7Bu) goto label_00093F3C;
    label_00093F2D:
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax |= 0xFFFFFFFFu;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_00093F38:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    label_00093F3C:
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->esi = cpu->edi + 1u;
    lift_push32(cpu, cpu->esi);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493F4Au)); sfera_sub_00493D70(cpu, LIFT_CODE_TOKEN_VA(0x493F4Au));
    if (cpu->eax == 0xFFFFFFFFu) goto label_00093F2D;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x24u);
    if (cpu->ecx == 0u) goto label_00093F5F;
    cpu->edx = cpu->eax + 1u;
    *(uint32_t*)(cpu->ecx) = cpu->esi;
    *(uint32_t*)(cpu->ecx + 4u) = cpu->edx;
    label_00093F5F:
    cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    cpu->eax -= cpu->edi;
    cpu->edi = lift_pop32(cpu);
    ++cpu->eax;
    cpu->ebp = lift_pop32(cpu); cpu->ecx = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00493F70(LiftCpu* cpu, uint32_t stop_address) {
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = *(uint32_t*)(cpu->esp + 0xCu);
    lift_push32(cpu, cpu->edi);
    cpu->edi = cpu->ecx;
    if (cpu->ebp != 0u) goto label_00093F83;
    label_00093F7C:
    cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_00093F83:
    if (*(uint32_t*)(cpu->edi + 8u) == 0u) goto label_00093F7C;
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->edi + 0xCu);
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    cpu->esi = 0u;
    cpu->ebx = cpu->eax;
    if (cpu->ecx == 0u) goto label_00093FAB;
    cpu->ebx = *(uint32_t*)(cpu->ecx + 4u);
    cpu->esi = *(uint32_t*)(cpu->ecx);
    if ((int32_t)cpu->ebx <= (int32_t)cpu->eax) goto label_00093FA5;
    cpu->ebx = cpu->eax;
    label_00093FA5:
    if ((int32_t)cpu->esi >= 0) goto label_00093FAB;
    cpu->esi = 0u;
    label_00093FAB:
    if ((int32_t)cpu->esi >= (int32_t)cpu->ebx) goto label_0009400F;
    *(uint32_t*)(cpu->esp + 0x18u) = 0u;
    label_00093FB7:
    cpu->eax = *(uint32_t*)(cpu->edi + 8u);
    cpu->ecx = *(uint32_t*)(cpu->eax + (cpu->esi * 4u));
    lift_push32(cpu, cpu->ecx);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493FC5u)); sfera_sub_00493D20(cpu, LIFT_CODE_TOKEN_VA(0x493FC5u));
    if (cpu->eax == 0u) goto label_0009400A;
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x493FD4u)); sfera_sub_00493E10(cpu, LIFT_CODE_TOKEN_VA(0x493FD4u));
    if (cpu->eax == 0xFFFFFFFFu) goto label_0009400A;
    cpu->edx = *(uint32_t*)(cpu->ebp);
    if (cpu->edx == *(uint32_t*)(cpu->ebp + 4u)) goto label_0009400A;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->edi + 0x10u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x493FEAu));
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_00094006;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x18u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    if (cpu->eax == *(uint32_t*)(cpu->esp + 0x20u)) goto label_00094018;
    label_00094006:
    cpu->esi = *(uint32_t*)(cpu->ebp + 4u);
    --cpu->esi;
    label_0009400A:
    ++cpu->esi;
    if ((int32_t)cpu->esi < (int32_t)cpu->ebx) goto label_00093FB7;
    label_0009400F:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
    label_00094018:
    cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->edi = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu); cpu->esp += 0x14u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00494030(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 8u);
    cpu->esp -= 0x14u;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->ebp = cpu->ecx;
    if (cpu->eax != 0u) goto label_0009404C;
    cpu->ebx = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->ebx;
    goto label_00094057;
    label_0009404C:
    cpu->ecx = *(uint32_t*)(cpu->eax);
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    *(uint32_t*)(cpu->esp + 0x18u) = cpu->eax;
    cpu->ebx = cpu->eax;
    label_00094057:
    *(uint32_t*)(cpu->esp + 0x2Cu) = 0u;
    (void)cpu;
    label_00094060:
    if (*(uint32_t*)(cpu->ebp + 8u) == 0u) goto label_00094126;
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    if ((int32_t)cpu->ebx <= (int32_t)cpu->eax) goto label_00094073;
    cpu->ebx = cpu->eax;
    label_00094073:
    if ((int32_t)cpu->ecx >= 0) goto label_00094079;
    cpu->ecx = 0u;
    label_00094079:
    if ((int32_t)cpu->ecx >= (int32_t)cpu->ebx) goto label_00094126;
    *(uint32_t*)(cpu->esp + 0x10u) = 0u;
    cpu->edi = cpu->ecx;
    label_00094090:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->eax = *(uint32_t*)(cpu->ecx + (cpu->edi * 4u));
    if (cpu->eax == 0u) goto label_0009411D;
    cpu->ecx = cpu->eax;
    cpu->esi = cpu->ecx + 1u;
    label_000940A3:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    ++cpu->ecx;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000940A3;
    cpu->ecx -= cpu->esi;
    cpu->ecx += cpu->eax;
    if (cpu->eax == cpu->ecx) goto label_0009411D;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    if ((cpu->edx & 0xFFu) != 0x2Fu) goto label_000940BE;
    if (*(uint8_t*)(cpu->eax + 1u) == (cpu->edx & 0xFFu)) goto label_0009411D;
    label_000940BE:
    if ((int8_t)(cpu->edx & 0xFFu) > (int8_t)0x20u) goto label_000940CD;
    label_000940C3:
    ++cpu->eax;
    if (cpu->eax >= cpu->ecx) goto label_0009411D;
    if ((int8_t)*(uint8_t*)(cpu->eax) <= (int8_t)0x20u) goto label_000940C3;
    label_000940CD:
    if (*(uint8_t*)(cpu->eax) != 0x2Fu) goto label_000940D8;
    if (*(uint8_t*)(cpu->eax + 1u) == 0x2Fu) goto label_0009411D;
    label_000940D8:
    cpu->edx = cpu->esp + 0x1Cu;
    lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4940E7u)); sfera_sub_00493E10(cpu, LIFT_CODE_TOKEN_VA(0x4940E7u));
    if (cpu->eax == 0xFFFFFFFFu) goto label_0009411D;
    cpu->esi = *(uint32_t*)(cpu->esp + 0x20u);
    if (*(uint32_t*)(cpu->esp + 0x1Cu) == cpu->esi) goto label_0009411D;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x28u);
    lift_push32(cpu, cpu->eax);
    cpu->ecx = cpu->ebp + 0x10u;
    lift_push32(cpu, cpu->ecx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4940FFu));
    cpu->esp += 8u;
    if (cpu->eax != 0u) goto label_0009411A;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if (cpu->eax == 1u) goto label_00094134;
    label_0009411A:
    cpu->edi = cpu->esi + 0xFFFFFFFFu;
    label_0009411D:
    ++cpu->edi;
    if ((int32_t)cpu->edi < (int32_t)cpu->ebx) goto label_00094090;
    label_00094126:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->esp += 0x14u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00094134:
    ++*(uint32_t*)(cpu->esp + 0x2Cu);
    cpu->ebx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->ecx = cpu->esi;
    goto label_00094060;
}
__declspec(noinline) void sfera_sub_00494150(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 8u;
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0xCu) == 0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    if (!sub_pred[0]) goto label_00094166;
    label_0009415D:
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00094166:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x14u);
    cpu->eax = *(uint32_t*)(cpu->ebp + 0xCu);
    cpu->ecx = 0u;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    if (cpu->edx == 0u) goto label_00094180;
    cpu->ecx = *(uint32_t*)(cpu->edx);
    cpu->edx = *(uint32_t*)(cpu->edx + 4u);
    *(uint32_t*)(cpu->esp + 4u) = cpu->edx;
    label_00094180:
    if ((int32_t)*(uint32_t*)(cpu->esp + 4u) <= (int32_t)cpu->eax) goto label_0009418A;
    *(uint32_t*)(cpu->esp + 4u) = cpu->eax;
    label_0009418A:
    if ((int32_t)cpu->ecx >= (int32_t)*(uint32_t*)(cpu->esp + 4u)) goto label_0009415D;
    lift_push32(cpu, cpu->ebx);
    cpu->eax = cpu->ebp + 0x410u;
    lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    *(uint32_t*)(cpu->esp + 0x1Cu) = cpu->ecx;
    lift_push32(cpu, cpu->edi);
    label_000941A1:
    cpu->edx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->edx + (cpu->ecx * 4u));
    cpu->eax = cpu->ecx;
    cpu->esi = cpu->eax + 1u;
    label_000941B0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000941B0;
    cpu->eax -= cpu->esi;
    cpu->ebx = cpu->eax + cpu->ecx;
    cpu->esi = cpu->ecx;
    if (cpu->ecx == 0u) goto label_0009425B;
    cpu->eax = cpu->ecx;
    cpu->edi = cpu->eax + 1u;
    label_000941D0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000941D0;
    cpu->eax -= cpu->edi;
    cpu->eax += cpu->ecx;
    if (cpu->ecx == cpu->eax) goto label_0009425B;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    if ((cpu->edx & 0xFFu) != 0x2Fu) goto label_000941EB;
    if (*(uint8_t*)(cpu->ecx + 1u) == (cpu->edx & 0xFFu)) goto label_0009425B;
    label_000941EB:
    if ((int8_t)(cpu->edx & 0xFFu) > (int8_t)0x20u) goto label_000941FA;
    label_000941F0:
    ++cpu->esi;
    if (cpu->esi >= cpu->eax) goto label_0009425B;
    if ((int8_t)*(uint8_t*)(cpu->esi) <= (int8_t)0x20u) goto label_000941F0;
    label_000941FA:
    if (*(uint8_t*)(cpu->esi) != 0x2Fu) goto label_00094205;
    if (*(uint8_t*)(cpu->esi + 1u) == 0x2Fu) goto label_0009425B;
    label_00094205:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494219u)); sfera_sub_00493E10(cpu, LIFT_CODE_TOKEN_VA(0x494219u));
    if (cpu->eax == 0xFFFFFFFFu) goto label_00094224;
    *(uint32_t*)(cpu->esp + 0x20u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x20u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    goto label_0009425B;
    label_00094224:
    cpu->edx = cpu->ebp + 0x10u;
    cpu->eax = cpu->edx;
    if (cpu->esi >= cpu->ebx) goto label_00094245;
    label_00094230:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    if ((int8_t)(cpu->ecx & 0xFFu) <= (int8_t)0x20u) goto label_00094245;
    if (cpu->eax >= *(uint32_t*)(cpu->esp + 0x14u)) goto label_00094241;
    *(uint8_t*)(cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    ++cpu->esi;
    label_00094241:
    if (cpu->esi < cpu->ebx) goto label_00094230;
    label_00094245:
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->edx);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x49424Eu));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_0009427A;
    label_0009425B:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    ++cpu->ecx;
    *(uint32_t*)(cpu->esp + 0x20u) = cpu->ecx;
    if ((int32_t)cpu->ecx < (int32_t)*(uint32_t*)(cpu->esp + 0x10u)) goto label_000941A1;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0009427A:
    cpu->eax = cpu->ebp + 0x10u;
    if (cpu->esi >= cpu->ebx) goto label_000942A0;
    cpu->ecx = cpu->eax;
    cpu->ecx -= cpu->ebp;
    cpu->ecx = cpu->ecx + cpu->esi + 0xFFFFFFF0u;
    label_00094290:
    if (cpu->eax >= *(uint32_t*)(cpu->esp + 0x14u)) goto label_0009429C;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->eax) = cpu->edx & 0xFFu;
    ++cpu->eax;
    ++cpu->ecx;
    label_0009429C:
    if (cpu->ecx < cpu->ebx) goto label_00094290;
    label_000942A0:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 8u;
    cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) double sfera_sub_004942C0(LiftCpu* cpu, uint32_t stop_address) { double value_0, value_1, value_2;
 double x87_p0;
    cpu->eax = cpu->ecx + 0x10u;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx + 1u;
label_000942D0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    ++cpu->ecx;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000942D0;
    cpu->ecx -= cpu->esi;
    cpu->ecx += cpu->eax;
    if (cpu->eax != cpu->ecx) goto label_000942E5;
    x87_p0 = 0.0;
     value_0 = x87_p0; cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return value_0;
label_000942E5:
    lift_push32(cpu, cpu->ebx);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    if (cpu->eax >= cpu->ecx) goto label_00094333;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (0x2Fu & 0xFFu);
label_000942F3:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    if ((cpu->edx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000942FE;
    if (*(uint8_t*)(cpu->eax + 1u) == (cpu->ebx & 0xFFu)) goto label_00094333;
label_000942FE:
    if ((int8_t)(cpu->edx & 0xFFu) > (int8_t)0x20u) goto label_0009430D;
label_00094303:
    ++cpu->eax;
    if (cpu->eax >= cpu->ecx) goto label_00094333;
    if ((int8_t)*(uint8_t*)(cpu->eax) <= (int8_t)0x20u) goto label_00094303;
label_0009430D:
    if (*(uint8_t*)(cpu->eax) != (cpu->ebx & 0xFFu)) goto label_00094316;
    if (*(uint8_t*)(cpu->eax + 1u) == (cpu->ebx & 0xFFu)) goto label_00094333;
label_00094316:
    if (cpu->esi == cpu->edi) goto label_0009433B;
    if (cpu->eax >= cpu->ecx) goto label_0009432E;
label_00094320:
    if ((int8_t)*(uint8_t*)(cpu->eax) <= (int8_t)0x20u) goto label_0009432E;
    if (cpu->eax >= cpu->ecx) goto label_00094333;
    ++cpu->eax;
    if (cpu->eax < cpu->ecx) goto label_00094320;
label_0009432E:
    ++cpu->esi;
    if (cpu->eax < cpu->ecx) goto label_000942F3;
label_00094333:
    x87_p0 = 0.0;
     value_1 = x87_p0; cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return value_1;
label_0009433B:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%f"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x494346u));
    x87_p0 = (double)*(float*)(cpu->esp + 0x1Cu);
    cpu->esp += 0xCu;
     value_2 = x87_p0; cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return value_2;
}
__declspec(noinline) void sfera_sub_00494360(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx + 0x10u;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx + 1u;
    label_00094370:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    ++cpu->ecx;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00094370;
    cpu->ecx -= cpu->esi;
    cpu->ecx += cpu->eax;
    if (cpu->eax != cpu->ecx) goto label_00094385;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00094385:
    lift_push32(cpu, cpu->ebx);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    if (cpu->eax >= cpu->ecx) goto label_000943D3;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (0x2Fu & 0xFFu);
    label_00094393:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    if ((cpu->edx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0009439E;
    if (*(uint8_t*)(cpu->eax + 1u) == (cpu->ebx & 0xFFu)) goto label_000943D3;
    label_0009439E:
    if ((int8_t)(cpu->edx & 0xFFu) > (int8_t)0x20u) goto label_000943AD;
    label_000943A3:
    ++cpu->eax;
    if (cpu->eax >= cpu->ecx) goto label_000943D3;
    if ((int8_t)*(uint8_t*)(cpu->eax) <= (int8_t)0x20u) goto label_000943A3;
    label_000943AD:
    if (*(uint8_t*)(cpu->eax) != (cpu->ebx & 0xFFu)) goto label_000943B6;
    if (*(uint8_t*)(cpu->eax + 1u) == (cpu->ebx & 0xFFu)) goto label_000943D3;
    label_000943B6:
    if (cpu->esi == cpu->edi) goto label_000943DB;
    if (cpu->eax >= cpu->ecx) goto label_000943CE;
    label_000943C0:
    if ((int8_t)*(uint8_t*)(cpu->eax) <= (int8_t)0x20u) goto label_000943CE;
    if (cpu->eax >= cpu->ecx) goto label_000943D3;
    ++cpu->eax;
    if (cpu->eax < cpu->ecx) goto label_000943C0;
    label_000943CE:
    ++cpu->esi;
    if (cpu->eax < cpu->ecx) goto label_00094393;
    label_000943D3:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000943DB:
    cpu->ecx = cpu->esp + 0x10u;
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, (uintptr_t)"%d"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x4943E6u));
    cpu->eax = *(uint32_t*)(cpu->esp + 0x1Cu);
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00494400(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx + 0x10u;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx + 1u;
    label_00094410:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    ++cpu->ecx;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00094410;
    cpu->ecx -= cpu->esi;
    cpu->ecx += cpu->eax;
    if (cpu->eax != cpu->ecx) goto label_00094425;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_00094425:
    lift_push32(cpu, cpu->ebx);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    if (cpu->eax >= cpu->ecx) goto label_00094473;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (0x2Fu & 0xFFu);
    label_00094433:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    if ((cpu->edx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0009443E;
    if (*(uint8_t*)(cpu->eax + 1u) == (cpu->ebx & 0xFFu)) goto label_00094473;
    label_0009443E:
    if ((int8_t)(cpu->edx & 0xFFu) > (int8_t)0x20u) goto label_0009444D;
    label_00094443:
    ++cpu->eax;
    if (cpu->eax >= cpu->ecx) goto label_00094473;
    if ((int8_t)*(uint8_t*)(cpu->eax) <= (int8_t)0x20u) goto label_00094443;
    label_0009444D:
    if (*(uint8_t*)(cpu->eax) != (cpu->ebx & 0xFFu)) goto label_00094456;
    if (*(uint8_t*)(cpu->eax + 1u) == (cpu->ebx & 0xFFu)) goto label_00094473;
    label_00094456:
    if (cpu->esi == cpu->edi) goto label_0009447B;
    if (cpu->eax >= cpu->ecx) goto label_0009446E;
    label_00094460:
    if ((int8_t)*(uint8_t*)(cpu->eax) <= (int8_t)0x20u) goto label_0009446E;
    if (cpu->eax >= cpu->ecx) goto label_00094473;
    ++cpu->eax;
    if (cpu->eax < cpu->ecx) goto label_00094460;
    label_0009446E:
    ++cpu->esi;
    if (cpu->eax < cpu->ecx) goto label_00094433;
    label_00094473:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0009447B:
    cpu->esi = *(uint32_t*)(cpu->esp + 0x14u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, (uintptr_t)"%s"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x494486u));
    cpu->esp += 0xCu;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004944A0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx += 0x10u;
    cpu->eax = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->eax + 1u;
    label_000944B0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000944B0;
    cpu->eax -= cpu->esi;
    cpu->edx = cpu->eax + cpu->ecx;
    if (cpu->ecx != cpu->edx) goto label_000944C6;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000944C6:
    lift_push32(cpu, cpu->ebx);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    if (cpu->ecx >= cpu->edx) goto label_00094513;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (0x2Fu & 0xFFu);
    label_000944D4:
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    if ((cpu->eax & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_000944DF;
    if (*(uint8_t*)(cpu->ecx + 1u) == (cpu->ebx & 0xFFu)) goto label_00094513;
    label_000944DF:
    if ((int8_t)(cpu->eax & 0xFFu) > (int8_t)0x20u) goto label_000944ED;
    label_000944E3:
    ++cpu->ecx;
    if (cpu->ecx >= cpu->edx) goto label_00094513;
    if ((int8_t)*(uint8_t*)(cpu->ecx) <= (int8_t)0x20u) goto label_000944E3;
    label_000944ED:
    if (*(uint8_t*)(cpu->ecx) != (cpu->ebx & 0xFFu)) goto label_000944F6;
    if (*(uint8_t*)(cpu->ecx + 1u) == (cpu->ebx & 0xFFu)) goto label_00094513;
    label_000944F6:
    if (cpu->esi == cpu->edi) goto label_0009451B;
    if (cpu->ecx >= cpu->edx) goto label_0009450E;
    label_00094500:
    if ((int8_t)*(uint8_t*)(cpu->ecx) <= (int8_t)0x20u) goto label_0009450E;
    if (cpu->ecx >= cpu->edx) goto label_00094513;
    ++cpu->ecx;
    if (cpu->ecx < cpu->edx) goto label_00094500;
    label_0009450E:
    ++cpu->esi;
    if (cpu->ecx < cpu->edx) goto label_000944D4;
    label_00094513:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_0009451B:
    if (*(uint8_t*)(cpu->ecx) != 0x22u) goto label_00094513;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x14u);
    ++cpu->ecx;
    cpu->esi = cpu->eax;
    if (cpu->ecx >= cpu->edx) goto label_00094543;
    label_00094530:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    if ((cpu->ebx & 0xFFu) == 0x22u) goto label_00094543;
    if (cpu->ecx >= cpu->edx) goto label_00094513;
    *(uint8_t*)(cpu->esi) = cpu->ebx & 0xFFu;
    ++cpu->ecx;
    ++cpu->esi;
    if (cpu->ecx < cpu->edx) goto label_00094530;
    label_00094543:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    *(uint8_t*)(cpu->esi) = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00494550(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if (cpu->eax == 0u) goto label_0009458C;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ecx + 0x410u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xCu);
    *(uint32_t*)(cpu->ecx + 0x414u) = cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)cpu->edx) goto label_00094576;
    *(uint32_t*)(cpu->ecx + 0x414u) = cpu->edx;
    label_00094576:
    if ((int32_t)*(uint32_t*)(cpu->ecx + 0x410u) >= (int32_t)0u) goto label_0009459F;
    *(uint32_t*)(cpu->ecx + 0x410u) = 0u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0009458C:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xCu);
    *(uint32_t*)(cpu->ecx + 0x414u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x410u) = 0u;
    label_0009459F:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004945B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0u;
    *(uint32_t*)(cpu->ecx + 0x410u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x414u) = cpu->eax;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004945C0(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[1];
    cpu->esp -= 0xCu;
    sub_pred[0] = *(uint32_t*)(cpu->esp + 0x10u) == 0u;
    lift_push32(cpu, cpu->ebp);
    cpu->ebp = cpu->ecx;
    if (!sub_pred[0]) goto label_000945D6;
    label_000945CD:
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000945D6:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 0x414u);
    cpu->eax = cpu->ebp + 0x410u;
    *(uint32_t*)(cpu->esp + 8u) = cpu->eax;
    cpu->eax = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->ecx;
    if ((int32_t)cpu->eax >= (int32_t)cpu->ecx) goto label_000945CD;
    lift_push32(cpu, cpu->ebx); lift_push32(cpu, cpu->esi);
    *(uint32_t*)(cpu->esp + 0xCu) = cpu->eax;
    lift_push32(cpu, cpu->edi);
    label_000945F7:
    cpu->ecx = *(uint32_t*)(cpu->ebp + 8u);
    cpu->ecx = *(uint32_t*)(cpu->ecx + (cpu->eax * 4u));
    cpu->eax = cpu->ecx;
    cpu->esi = cpu->eax + 1u;
    label_00094602:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00094602;
    cpu->eax -= cpu->esi;
    cpu->ebx = cpu->eax + cpu->ecx;
    cpu->esi = cpu->ecx;
    if (cpu->ecx == 0u) goto label_000946AC;
    cpu->eax = cpu->ecx;
    cpu->edi = cpu->eax + 1u;
    label_00094620:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00094620;
    cpu->eax -= cpu->edi;
    cpu->eax += cpu->ecx;
    if (cpu->ecx == cpu->eax) goto label_000946AC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    if ((cpu->edx & 0xFFu) != 0x2Fu) goto label_0009463F;
    if (*(uint8_t*)(cpu->ecx + 1u) == (cpu->edx & 0xFFu)) goto label_000946AC;
    label_0009463F:
    if ((int8_t)(cpu->edx & 0xFFu) > (int8_t)0x20u) goto label_0009464E;
    label_00094644:
    ++cpu->esi;
    if (cpu->esi >= cpu->eax) goto label_000946AC;
    if ((int8_t)*(uint8_t*)(cpu->esi) <= (int8_t)0x20u) goto label_00094644;
    label_0009464E:
    if (*(uint8_t*)(cpu->esi) != 0x2Fu) goto label_00094659;
    if (*(uint8_t*)(cpu->esi + 1u) == 0x2Fu) goto label_000946AC;
    label_00094659:
    cpu->edx = *(uint32_t*)(cpu->esp + 0x18u);
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, 0u); lift_push32(cpu, cpu->edx); lift_push32(cpu, cpu->eax); lift_push32(cpu, cpu->esi);
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49466Du)); sfera_sub_00493E10(cpu, LIFT_CODE_TOKEN_VA(0x49466Du));
    if (cpu->eax == 0xFFFFFFFFu) goto label_00094678;
    *(uint32_t*)(cpu->esp + 0x10u) = (uint64_t)(*(uint32_t*)(cpu->esp + 0x10u)) + (uint64_t)(cpu->eax) + (uint64_t)(0u);
    goto label_000946AC;
    label_00094678:
    cpu->edx = cpu->ebp + 0x10u;
    cpu->eax = cpu->edx;
    if (cpu->esi >= cpu->ebx) goto label_00094696;
    label_00094681:
    cpu->ecx = (cpu->ecx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->esi));
    if ((int8_t)(cpu->ecx & 0xFFu) <= (int8_t)0x20u) goto label_00094696;
    if (cpu->eax >= *(uint32_t*)(cpu->esp + 0x14u)) goto label_00094692;
    *(uint8_t*)(cpu->eax) = cpu->ecx & 0xFFu;
    ++cpu->eax;
    ++cpu->esi;
    label_00094692:
    if (cpu->esi < cpu->ebx) goto label_00094681;
    label_00094696:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x20u);
    lift_push32(cpu, cpu->ecx); lift_push32(cpu, cpu->edx);
    *(uint8_t*)(cpu->eax) = 0u;
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x49469Fu));
    cpu->esp += 8u;
    if (cpu->eax == 0u) goto label_000946CB;
    label_000946AC:
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    ++cpu->eax;
    *(uint32_t*)(cpu->esp + 0x10u) = cpu->eax;
    if ((int32_t)cpu->eax < (int32_t)*(uint32_t*)(cpu->esp + 0x18u)) goto label_000945F7;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000946CB:
    cpu->eax = cpu->ebp + 0x10u;
    if (cpu->esi >= cpu->ebx) goto label_000946F0;
    cpu->edx = cpu->eax;
    cpu->edx -= cpu->ebp;
    cpu->ecx = cpu->edx + cpu->esi + 0xFFFFFFF0u;
    label_000946E0:
    if (cpu->eax >= *(uint32_t*)(cpu->esp + 0x14u)) goto label_000946EC;
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    *(uint8_t*)(cpu->eax) = cpu->edx & 0xFFu;
    ++cpu->eax;
    ++cpu->ecx;
    label_000946EC:
    if (cpu->ecx < cpu->ebx) goto label_000946E0;
    label_000946F0:
    cpu->ecx = *(uint32_t*)(cpu->esp + 0x14u);
    *(uint8_t*)(cpu->eax) = 0u;
    cpu->eax = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu);
    ++cpu->eax;
    cpu->ebx = lift_pop32(cpu);
    *(uint32_t*)(cpu->ecx) = cpu->eax;
    cpu->eax = 1u;
    cpu->ebp = lift_pop32(cpu);
    cpu->esp += 0xCu;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00494710(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = cpu->ecx + 0x10u;
    cpu->ecx = cpu->eax;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx + 1u;
    label_00094720:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    ++cpu->ecx;
    if ((cpu->edx & 0xFFu) != 0u) goto label_00094720;
    cpu->ecx -= cpu->esi;
    cpu->ecx += cpu->eax;
    if (cpu->eax != cpu->ecx) goto label_00094735;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_00094735:
    lift_push32(cpu, cpu->ebx);
    cpu->esi = 0u;
    lift_push32(cpu, cpu->edi);
    if (cpu->eax >= cpu->ecx) goto label_00094783;
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (0x2Fu & 0xFFu);
    label_00094743:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    if ((cpu->edx & 0xFFu) != (cpu->ebx & 0xFFu)) goto label_0009474E;
    if (*(uint8_t*)(cpu->eax + 1u) == (cpu->ebx & 0xFFu)) goto label_00094783;
    label_0009474E:
    if ((int8_t)(cpu->edx & 0xFFu) > (int8_t)0x20u) goto label_0009475D;
    label_00094753:
    ++cpu->eax;
    if (cpu->eax >= cpu->ecx) goto label_00094783;
    if ((int8_t)*(uint8_t*)(cpu->eax) <= (int8_t)0x20u) goto label_00094753;
    label_0009475D:
    if (*(uint8_t*)(cpu->eax) != (cpu->ebx & 0xFFu)) goto label_00094766;
    if (*(uint8_t*)(cpu->eax + 1u) == (cpu->ebx & 0xFFu)) goto label_00094783;
    label_00094766:
    if (cpu->esi == cpu->edi) goto label_0009478B;
    if (cpu->eax >= cpu->ecx) goto label_0009477E;
    label_00094770:
    if ((int8_t)*(uint8_t*)(cpu->eax) <= (int8_t)0x20u) goto label_0009477E;
    if (cpu->eax >= cpu->ecx) goto label_00094783;
    ++cpu->eax;
    if (cpu->eax < cpu->ecx) goto label_00094770;
    label_0009477E:
    ++cpu->esi;
    if (cpu->eax < cpu->ecx) goto label_00094743;
    label_00094783:
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0009478B:
    lift_push32(cpu, (uintptr_t)g_sfera_config_parse_scratch_runtime.token); lift_push32(cpu, (uintptr_t)"%s"); lift_push32(cpu, cpu->eax);
    lift_native_call(cpu, native_function_address32(&::sscanf), LIFT_CODE_TOKEN_VA(0x494796u));
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (g_sfera_config_parse_scratch_runtime.token[0]);
    cpu->esp += 0xCu;
    if ((cpu->eax & 0xFFu) == 0u) goto label_00094783;
    if ((cpu->eax & 0xFFu) != 0x31u) goto label_000947B7;
    cpu->edi = lift_pop32(cpu); cpu->ebx = lift_pop32(cpu);
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
    label_000947B7:
    lift_push32(cpu, (uintptr_t)"true"); lift_push32(cpu, (uintptr_t)g_sfera_config_parse_scratch_runtime.token);
    lift_native_call(cpu, native_function_address32(&::_stricmp), LIFT_CODE_TOKEN_VA(0x4947C1u));
    cpu->esp += 8u;
    cpu->eax = -cpu->eax;
    cpu->edi = lift_pop32(cpu);
    cpu->eax = (cpu->eax != 0u) ? 0xFFFFFFFFu : 0u;
    cpu->ebx = lift_pop32(cpu);
    ++cpu->eax;
    cpu->esi = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004947E0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->ecx += 0x10u;
    cpu->eax = cpu->ecx;
    lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->eax + 1u;
    label_000947F0:
    cpu->edx = (cpu->edx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->eax));
    ++cpu->eax;
    if ((cpu->edx & 0xFFu) != 0u) goto label_000947F0;
    cpu->eax -= cpu->esi;
    cpu->edx = cpu->eax + cpu->ecx;
    if (cpu->ecx != cpu->edx) goto label_00094804;
    cpu->eax = 0u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
    label_00094804:
    cpu->esi = 0u;
    lift_push32(cpu, cpu->ebx);
    if (cpu->ecx >= cpu->edx) goto label_0009484A;
    cpu->eax = (cpu->eax & 0xFFFFFF00u) | (0x2Fu & 0xFFu);
    label_00094810:
    cpu->ebx = (cpu->ebx & 0xFFFFFF00u) | (*(uint8_t*)(cpu->ecx));
    if ((cpu->ebx & 0xFFu) != (cpu->eax & 0xFFu)) goto label_0009481B;
    if (*(uint8_t*)(cpu->ecx + 1u) == (cpu->eax & 0xFFu)) goto label_0009484A;
    label_0009481B:
    if ((int8_t)(cpu->ebx & 0xFFu) > (int8_t)0x20u) goto label_0009482A;
    label_00094820:
    ++cpu->ecx;
    if (cpu->ecx >= cpu->edx) goto label_0009484A;
    if ((int8_t)*(uint8_t*)(cpu->ecx) <= (int8_t)0x20u) goto label_00094820;
    label_0009482A:
    if (*(uint8_t*)(cpu->ecx) != (cpu->eax & 0xFFu)) goto label_00094833;
    if (*(uint8_t*)(cpu->ecx + 1u) == (cpu->eax & 0xFFu)) goto label_0009484A;
    label_00094833:
    if (cpu->ecx >= cpu->edx) goto label_00094845;
    label_00094837:
    if ((int8_t)*(uint8_t*)(cpu->ecx) <= (int8_t)0x20u) goto label_00094845;
    if (cpu->ecx >= cpu->edx) goto label_0009484A;
    ++cpu->ecx;
    if (cpu->ecx < cpu->edx) goto label_00094837;
    label_00094845:
    ++cpu->esi;
    if (cpu->ecx < cpu->edx) goto label_00094810;
    label_0009484A:
    cpu->ebx = lift_pop32(cpu);
    cpu->eax = cpu->esi;
    cpu->esi = lift_pop32(cpu); cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00494850(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    if (cpu->eax == 0u) goto label_0009488C;
    cpu->edx = *(uint32_t*)(cpu->eax);
    *(uint32_t*)(cpu->ecx + 0x418u) = cpu->edx;
    cpu->eax = *(uint32_t*)(cpu->eax + 4u);
    cpu->edx = *(uint32_t*)(cpu->ecx + 0xCu);
    *(uint32_t*)(cpu->ecx + 0x41Cu) = cpu->eax;
    if ((int32_t)cpu->eax <= (int32_t)cpu->edx) goto label_00094876;
    *(uint32_t*)(cpu->ecx + 0x41Cu) = cpu->edx;
    label_00094876:
    if ((int32_t)*(uint32_t*)(cpu->ecx + 0x418u) >= (int32_t)0u) goto label_0009489F;
    *(uint32_t*)(cpu->ecx + 0x418u) = 0u;
    cpu->esp += 8u; cpu->eip = stop_address; return;
    label_0009488C:
    cpu->eax = *(uint32_t*)(cpu->ecx + 0xCu);
    *(uint32_t*)(cpu->ecx + 0x41Cu) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x418u) = 0u;
    label_0009489F:
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004948B0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = 0u;
    *(uint32_t*)(cpu->ecx + 0x418u) = cpu->eax;
    *(uint32_t*)(cpu->ecx + 0x41Cu) = cpu->eax;
    cpu->esp += 4u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_004948C0(LiftCpu* cpu, uint32_t stop_address) {
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi);
    cpu->edi = *(uint32_t*)(cpu->esp + 0x10u);
    lift_push32(cpu, 1u);
    cpu->esi = cpu->ecx + 0x418u;
    lift_push32(cpu, cpu->esi); lift_push32(cpu, cpu->edi); lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4948DAu)); sfera_sub_00493F70(cpu, LIFT_CODE_TOKEN_VA(0x4948DAu));
    if (cpu->eax != 0u) goto label_000948E3;
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
    label_000948E3:
    cpu->ecx = *(uint32_t*)(cpu->edi + 4u);
    cpu->edi = lift_pop32(cpu);
    *(uint32_t*)(cpu->esi) = cpu->ecx;
    cpu->eax = 1u;
    cpu->esi = lift_pop32(cpu); cpu->esp += 0xCu; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00494900(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x418u);
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x41Cu);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00494920(LiftCpu* cpu, uint32_t stop_address) {
    cpu->edx = *(uint32_t*)(cpu->ecx + 0x410u);
    cpu->eax = *(uint32_t*)(cpu->esp + 4u);
    *(uint32_t*)(cpu->eax) = cpu->edx;
    cpu->ecx = *(uint32_t*)(cpu->ecx + 0x414u);
    *(uint32_t*)(cpu->eax + 4u) = cpu->ecx;
    cpu->esp += 8u; cpu->eip = stop_address; return;
}
__declspec(noinline) void sfera_sub_00494940(LiftCpu* cpu, uint32_t stop_address) { bool sub_pred[2];
    lift_push32(cpu, cpu->ebp); lift_push32(cpu, cpu->esi);
    cpu->esi = cpu->ecx;
    sub_pred[0] = *(uint32_t*)(cpu->esi) == 0u;
    lift_push32(cpu, cpu->edi);
    if (sub_pred[0]) goto label_00094964;
    cpu->edx = 0x4Cu;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SimpleParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494959u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x494959u));
    cpu->eax = *(uint32_t*)(cpu->esi);
    lift_push32(cpu, cpu->eax);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494961u)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x494961u));
    cpu->esp += 4u;
    label_00094964:
    sub_pred[1] = *(uint32_t*)(cpu->esi + 8u) == 0u;
    *(uint32_t*)(cpu->esi) = 0u;
    *(uint32_t*)(cpu->esi + 4u) = 0u;
    if (sub_pred[1]) goto label_00094992;
    cpu->edx = 0x51u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SimpleParser.cpp";
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x494986u)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x494986u));
    cpu->ecx = *(uint32_t*)(cpu->esi + 8u);
    lift_push32(cpu, cpu->ecx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x49498Fu)); sfera_sub_004EBE20(cpu, LIFT_CODE_TOKEN_VA(0x49498Fu));
    cpu->esp += 4u;
    label_00094992:
    cpu->ebp = *(uint32_t*)(cpu->esp + 0x10u);
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esi + 8u) = 0u;
    *(uint32_t*)(cpu->esi + 0xCu) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4949ABu)); sfera_sub_0042F2A0(cpu, LIFT_CODE_TOKEN_VA(0x4949ABu));
    cpu->edi = cpu->eax;
    if (cpu->edi == 0u) goto label_000949FB;
    cpu->edx = 0u;
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4949BAu)); sfera_sub_0042EBF0(cpu, LIFT_CODE_TOKEN_VA(0x4949BAu));
    cpu->edx = 0x76u;
    cpu->ecx = (uintptr_t)"..\\ShareClientSeverCode\\SimpleParser.cpp";
    cpu->ebp = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4949CBu)); sfera_sub_004EB1C0(cpu, LIFT_CODE_TOKEN_VA(0x4949CBu));
    cpu->edx = cpu->edi + 0xAu;
    lift_push32(cpu, cpu->edx);
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4949D4u)); sfera_sub_004EBEA0(cpu, LIFT_CODE_TOKEN_VA(0x4949D4u));
    cpu->esp += 4u;
    lift_push32(cpu, cpu->edi);
    cpu->edx = cpu->eax;
    cpu->ecx = cpu->ebp;
    *(uint32_t*)(cpu->esi) = cpu->eax;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4949E3u)); sfera_sub_0042EF20(cpu, LIFT_CODE_TOKEN_VA(0x4949E3u));
    cpu->ecx = cpu->ebp;
    lift_push32(cpu, LIFT_CODE_TOKEN_VA(0x4949EAu)); sfera_sub_0042F180(cpu, LIFT_CODE_TOKEN_VA(0x4949EAu));
    cpu->eax = *(uint32_t*)(cpu->esi);
    cpu->eax += cpu->edi;
    *(uint32_t*)(cpu->esi + 4u) = cpu->eax;
    cpu->ecx = cpu->esi;
    *(uint8_t*)(cpu->eax) = 0u;
    lift_push32(cpu, LIFT_CODE_TOKEN_RVA(0x949FBu)); sfera_sub_00493C50(cpu, LIFT_CODE_TOKEN_RVA(0x949FBu));
    label_000949FB:
    cpu->edi = lift_pop32(cpu); cpu->esi = lift_pop32(cpu); cpu->ebp = lift_pop32(cpu); cpu->esp += 8u; cpu->eip = stop_address; return;
}

} // namespace lifted
